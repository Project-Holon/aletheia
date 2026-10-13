#ifndef OV027_WEATHER_SANDSTORM_TYPES_H
#define OV027_WEATHER_SANDSTORM_TYPES_H

struct WeatherTaskSys;

/* Sandstorm weather kind (overlay 27, weather ids 3 and 12): fog and sprite grains that gusts blow
 * to the right. The gust strength changes every GUST_STEP_FRAMES spawn calls and
 * the pattern repeats every GUST_CYCLE_FRAMES. */
#define GUST_STEP_FRAMES 40
#define GUST_CYCLE_FRAMES 320
#define GUST_SCROLL_STEP 6
#define GUST_SCROLL_PERIOD 256

/* Kind work buffer (WeatherKindDef.workBufferSize is 0x28; only 4 words are used). */
typedef struct WeatherSandstormWork {
    int startDelay;     /* frames left before the fog and light change starts (1 at begin, 31 at end) */
    int gustCounter;    /* counts spawn calls, wraps at GUST_CYCLE_FRAMES; counter / 40 picks the gust step */
    int scrollPhase;    /* phase of the billboard scroll, +6 per frame, wraps at 256 */
    int gustSpeed;      /* horizontal speed of the current gust step */
} WeatherSandstormWork;

/* Per-particle data in WeatherParticle.kindWork. */
typedef struct WeatherSandstormGrain {
    int age;            /* frames lived */
    int lifetime;       /* frames until the particle expires */
    int speedY;         /* vertical speed, pixels per frame */
    int expired;        /* set when age passes lifetime; the particle is released next frame */
    int speedX;         /* horizontal speed, grows by speedXStep every 5 frames */
    int speedXStep;
} WeatherSandstormGrain;

void WEATHER_SANDSTORM_ScrollBillboards(struct WeatherTaskSys *task, WeatherSandstormWork *work);

#endif
