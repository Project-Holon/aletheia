/*
 * function: NNSi_G3dTexPatAnmGetFrameValue
 * address:  0x0206EA58
 * packet:   pkt_0206E9A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_G3dTexPatAnmGetTrackByIdx    0x0206EACC  arm
 *
 * Bucket search in a BTX0-style table: the signed halfword at +4 of the block
 * NNSi_G3dTexPatAnmGetTrackByIdx returns scales the key, the result is a fixed-point index, and
 * the two walks that follow step it down over entries >= v and then up over
 * entries <= v, returning the entry address.
 *
 * The entry stride is four *bytes* and is spelled through a byte pointer, and
 * the two walks are one `while` each: the emitted shape is the rotated form
 * the compiler produces for a conjunction whose second term loads.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G3dTexPatAnmGetFrameValue.c \
 *       --func NNSi_G3dTexPatAnmGetFrameValue --addr 0x0206EA58 --cc 1.1p1 --arm
 */
#include "../include/Obj08931.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u8 *NNSi_G3dTexPatAnmGetTrackByIdx(void *p, u32 idx);

u16 *NNSi_G3dTexPatAnmGetFrameValue(u16 *p, u32 arg, u32 v)
{
    u8 *h = NNSi_G3dTexPatAnmGetTrackByIdx(p, arg);
    s16 n = ((struct Obj08931 *)h)->f4;
    u8 *t = (u8 *)p + ((struct Obj08931 *)h)->f6;
    u32 i = (u32)(n * v) >> 12;

    while (i != 0 && *(u16 *)(t + i * 4) >= v)
        i--;
    while (i + 1 < ((struct Obj08931 *)h)->f0 && *(u16 *)(t + 4 + i * 4) <= v)
        i++;
    return (u16 *)(t + i * 4);
}
