/*
 * function: FIELD_CAMERA_CreateDelay
 * address:  0x0218EEFC
 * packet:   pkt_ov021_0218EEFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gFieldCameraFileName  0x021DDA28  data  a4
 *
 * The fifth (stack) parameter is a void pointer reassigned to the address of
 * its +0xec slot before the store: the cast keeps it a live variable homed in
 * its own parameter slot (entry write-back, end adds/str).
 */
#include "../include/Obj12593.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { int x, y, z; } Vec3;

typedef struct {
    int count;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 flag1;
    u32 flag2;
    u32 flag4;
    Vec3 *bufA;
    Vec3 *bufB;
    u32 unk28;
    u32 unk2C;
} Track;

extern void *func_02030734(u16 heap, u32 size, u32 flag, const void *file, u32 line);
extern const char gFieldCameraFileName[];

void FIELD_CAMERA_CreateDelay(int n, u32 x, u32 flags, u32 heap, void *a)
{
    if (((struct Obj12593 *)a)->f1C != 0) {
        int i = 0;
        Track *t = func_02030734(heap, sizeof(Track), 0, gFieldCameraFileName, 0x6aa);
        t->bufA = func_02030734(heap, n * sizeof(Vec3), 0, gFieldCameraFileName, 0x6ab);
        t->bufB = func_02030734(heap, n * sizeof(Vec3), 0, gFieldCameraFileName, 0x6ac);
        for (; i < n; i++) {
            Vec3 *v = &t->bufA[i];
            v->x = 0;
            v->y = 0;
            v->z = 0;
            v = &t->bufB[i];
            v->x = 0;
            v->y = 0;
            v->z = 0;
        }
        t->count = n;
        t->unk0C = x;
        t->unk10 = 0;
        t->unk04 = 0;
        t->unk08 = x;
        t->flag1 = 0;
        t->flag2 = 0;
        t->flag4 = 0;
        if (flags & 1)
            t->flag1 = 1;
        if (flags & 2)
            t->flag2 = 1;
        if (flags & 4)
            t->flag4 = 1;
        t->unk28 = 1;
        t->unk2C = 0;
        a = (u8 *)a + 0xec;
        *(Track * *)&((struct Obj12593 *)a)->f0 = t;
    }
}
