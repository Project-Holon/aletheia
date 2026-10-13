#ifndef OV028_WEATHER_FOG_TYPES_H
#define OV028_WEATHER_FOG_TYPES_H

/* Fog weather kinds (overlay 28, weather ids 9, 10, 11, 13 and 14): only fog and
 * light, no particles. Id 9 uses a fixed fog; the others choose the fog from the
 * camera state. All kinds use a work buffer of 0x38 bytes. */

#define FOG_LIGHT_ARC_ID 0x3e
#define FOG_CHANGE_FRAMES 0x5a
#define FOG_END_FRAMES 0x3c
#define FOG_END_OFFSET 0x7fdf

/* Work buffer of weather id 9. */
typedef struct FogFixedWork {
    int fogChangeStarted;   /* 0 until the fog change is started, then -1 */
    int reserved[9];        /* not read */
    int fogSlope;           /* target fog slope */
    int fogOffset;          /* target fog offset */
} FogFixedWork;

/* Work buffer of weather ids 10, 11, 13 and 14. */
typedef struct FogCameraWork {
    int weatherId;          /* selects the light of the weather */
    int fogChangeStarted;   /* 0 until the fog change is started, then -1 */
    int reserved[9];        /* not read */
    int fogSlope;           /* from gFogSlopeByCameraState */
    int fogOffset;          /* from gFogOffsetByCameraState */
} FogCameraWork;

#endif
