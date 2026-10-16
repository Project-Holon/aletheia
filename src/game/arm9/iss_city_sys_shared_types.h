#ifndef ISS_CITY_SYS_SHARED_TYPES_H
#define ISS_CITY_SYS_SHARED_TYPES_H

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed int     s32;

/*
 * One 0x28-byte city sound unit, filled from archive 0x84 (one member per
 * unit).  The unit covers one zone.  It stores a center on a 3D grid and, per
 * axis, six distance thresholds (radius >> 4) with a volume step for each:
 * the closer the player is, the higher the step.
 */
struct IssCityUnit {
    u16 zoneId;
    u16 pad02;
    u32 centerGridX;        /* center = 8.0 * (centerGridX << 4) */
    u32 centerGridY;
    u32 centerGridZ;
    u8 volumeSteps[6];      /* volume (0..127) of each distance step */
    u8 radiusX[6];          /* distance thresholds, radius >> 4 */
    u8 radiusY[6];
    u8 radiusZ[6];
};

#endif
