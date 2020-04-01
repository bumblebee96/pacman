; Print.s
; Student names: change this to your names or look very silly
; Last modification date: change this to the last modification date or look very silly
; Runs on LM4F120 or TM4C123
; EE319K lab 7 device driver for any LCD
;
; As part of Lab 7, students need to implement these LCD_OutDec and LCD_OutFix
; This driver assumes two low-level LCD functions
; ST7735_OutChar   outputs a single 8-bit ASCII character
; ST7735_OutString outputs a null-terminated string

    IMPORT   ST7735_OutChar
    IMPORT   ST7735_OutString
    EXPORT   LCD_OutDec
    EXPORT   LCD_OutFix

dec1  EQU 0
dec2  EQU 2
dec3  EQU 3
dec4  EQU 4


    AREA    |.text|, CODE, READONLY, ALIGN=2
    THUMB



;-----------------------LCD_OutDec-----------------------
; Output a 32-bit number in unsigned decimal format
; Input: R0 (call by value) 32-bit unsigned number
; Output: none
; Invariables: This function must not permanently modify registers R4 to R11
LCD_OutDec

  PUSH {R4,R5,R6,R7,R11,LR}

  CMP R0,#10    ;if R0<10 print out ascii code
  BHS rec
          ;convert R0 to ascii value
  MOV R1,#0x30  ;ascii code for 0 character
  ADD R0,R0,R1

  BL ST7735_OutChar

  B done

rec         ;recursively call this function

  PUSH{R0,R1}
  MOV R1,#10
  UDIV R0,R1
  BL LCD_OutDec ;call LCD_OutDec(R0/10)
  POP{R0,R1}

  PUSH{R0,R1}
  ;MOD  DIVISION
  MOV R1,#10
  UDIV R2,R0,R1
  MUL R2,R2,R1
  SUB R0,R0,R2
  BL LCD_OutDec ;call LCD_OutDec(R0%10)
  POP{R0,R1}

done
  POP {R4,R5,R6,R7,R11,LR}

  BX  LR
;* * * * * * * * End of LCD_OutDec * * * * * * * *

; -----------------------LCD _OutFix----------------------
; Output characters to LCD display in fixed-point format
; unsigned decimal, resolution 0.001, range 0.000 to 9.999
; Inputs:  R0 is an unsigned 32-bit number
; Outputs: none
; E.g., R0=0,    then output "0.000 "
;       R0=3,    then output "0.003 "
;       R0=89,   then output "0.089 "
;       R0=123,  then output "0.123 "
;       R0=9999, then output "9.999 "
;       R0>9999, then output "*.*** "
; Invariables: This function must not permanently modify registers R4 to R11
LCD_OutFix

  PUSH {R4,R5,R6,R7,R11,LR}

  SUB SP,SP,#8  ;allocate memory for  the char  string
  MOV R11,SP    ;set stack frame pointer

  MOV R1,#0x2A  ;initialize memory
  STRB R1,[R11]
  MOV R1,#0x2E
  STRB R1,[SP,#1]
  MOV R1,#0x2A
  STRB R1,[R11,#2]
  STRB R1,[R11,#3]
  STRB R1,[R11,#4]
  MOV R1,#0x20
  STRB R1,[R11,#5]
  MOV R1,#0x00
  STRB R1,[R11,#6]

  MOV R1,#9999  ;test if our input is valid
  CMP R0,R1
  BLS valid

  MOV R0,R11    ;if input is greater than 9999 output "*.*** "
  BL ST7735_OutString
  B done2

valid
  MOV R1,#0x30  ;ascii for '0'
  MOV R2,#1000
  UDIV R3,R0,R2
  ADD R3,R3,R1
  STRB R3,[R11,#dec1] ;store the first digit

  UDIV R3,R0,R2
  MUL R3,R3,R2
  SUB R7,R0,R3  ;R7 = R0%1000
  MOV R2,#100
  UDIV R3,R7,R2
  ADD R3,R3,R1
  STRB R3,[R11,#dec2] ;store second digit

  MOV R2,#100
  UDIV R3,R7,R2
  MUL R3,R3,R2
  SUB R6,R7,R3  ;R6 = R7%100
  MOV R2,#10
  UDIV R3,R6,R2
  ADD R3,R3,R1
  STRB R3,[R11,#dec3]

  MOV R2,#10
  UDIV R3,R6,R2
  MUL R3,R3,R2
  SUB R5,R6,R3  ;R5 = R6%10
  ADD R3,R5,R1
  STRB R3,[R11,#dec4]

  MOV R0,R11
  BL ST7735_OutString

done2
  ADD SP,SP,#8  ;dealocate locals
  POP {R4,R5,R6,R7,R11,LR}

  BX   LR

     ALIGN
;* * * * * * * * End of LCD_OutFix * * * * * * * *

     ALIGN                           ; make sure the end of this section is aligned
     END                             ; end of file
