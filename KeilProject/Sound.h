// Sound.h
// Runs on TM4C123 or LM4F120
// Prototypes for basic functions to play sounds from the
// original Space Invaders.
// Jonathan Valvano
// November 17, 2014


void Sound_Init(void);
void Sound_Play(const uint8_t *pt, uint32_t count);
void Sound_Intro(void);
void Sound_Die(void);
void Sound_Siren(void);
void Sound_Chomp(void);

void Play(void);
void Stop(void);

