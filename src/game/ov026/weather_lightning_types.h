#ifndef OV026_WEATHER_LIGHTNING_TYPES_H
#define OV026_WEATHER_LIGHTNING_TYPES_H

/* Lightning sequencer of the weather kinds of overlay 26. It has no
 * dependencies, so the unplaced leaf of the sequencer can include it alone. */

struct WeatherTaskSys;

/* One flash of a lightning sequence. */
typedef struct WeatherLightningFlash {
    unsigned short fadeInFrames;   /* 0x00 frames the screen takes to flash */
    unsigned short returnFrames;   /* 0x02 frames the screen takes to return to normal */
    unsigned short brightness;     /* 0x04 flash colour component, 0x12 to 0x1E */
    short holdFrames;              /* 0x06 frames before the next flash starts */
    short soundDelay;              /* 0x08 frames until the thunder starts */
    unsigned short soundId;        /* 0x0A thunder sound effect */
} WeatherLightningFlash;

#define WEATHER_LIGHTNING_FLASH_MAX 4

/* States of WeatherLightning.state. */
enum {
    WEATHER_LIGHTNING_WAIT = 0,
    WEATHER_LIGHTNING_PICK_SEQUENCE = 1,
    WEATHER_LIGHTNING_SKY_FLASH = 2,
    WEATHER_LIGHTNING_SKY_FLASH_WAIT = 3,
    WEATHER_LIGHTNING_START_FLASH = 4,
    WEATHER_LIGHTNING_FLASH_FADE = 5,
    WEATHER_LIGHTNING_FLASH_HOLD = 6
};

/* Lightning sequencer (0x40 bytes). Picks a sequence of up to four flashes,
 * flashes the screen light for each and plays the thunder late. */
typedef struct WeatherLightning {
    unsigned char state;                                        /* 0x00 */
    unsigned char mode;                                         /* 0x01 0: thunder only, no screen flash; 1: flashes; 2: flashes with a sky pre-flash and long sequences */
    unsigned short pattern;                                     /* 0x02 0: short flashes, 1: one flash, 2: long sequence */
    unsigned short flashCount;                                  /* 0x04 */
    unsigned short flashIndex;                                  /* 0x06 */
    WeatherLightningFlash flashes[WEATHER_LIGHTNING_FLASH_MAX]; /* 0x08 */
    int timer;                                                  /* 0x38 frames until the next sequence */
    short pendingSoundDelay;                                    /* 0x3C */
    short pendingSoundId;                                       /* 0x3E */
} WeatherLightning;

/* Lightning sequencer (weather_rain_thunderstorm_storm.c). */
extern void WEATHER_LIGHTNING_Init(WeatherLightning *lightning, int mode);
extern void WEATHER_LIGHTNING_Clear(WeatherLightning *lightning);
extern void WEATHER_LIGHTNING_Update(WeatherLightning *lightning, struct WeatherTaskSys *task);
extern void WEATHER_LIGHTNING_PickShortFlashes(WeatherLightning *lightning);
extern void WEATHER_LIGHTNING_PickSingleFlash(WeatherLightning *lightning);
extern void WEATHER_LIGHTNING_PickLongSequence(WeatherLightning *lightning);
extern unsigned short WEATHER_LIGHTNING_GetFlashColor(WeatherLightning *lightning);

#endif
