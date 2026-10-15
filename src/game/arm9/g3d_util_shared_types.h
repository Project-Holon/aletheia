#ifndef G3D_UTIL_SHARED_TYPES_H
#define G3D_UTIL_SHARED_TYPES_H

struct ArcHandle;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct ArcHandle {
    u8  file[0x48];
    u32 imageBase;
    u16 fatOffset;
    u16 count;
};

#endif
