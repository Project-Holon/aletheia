/*
 * function: CircleGraph_AddSlice
 * address:  0x021C1720
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   CircleGraph_AddSlice  0x021C1720  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00554.h"
#include "../include/Obj03955.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;


void CircleGraph_AddSlice(u8 *a0, u8 *a1)
{
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC) + 28) = ((struct Obj03955 *)((u8*)a1))->f0;
    *(u32*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC) + 32) = (u32)(((struct Obj03955 *)(((u8*)a1)))->f4);
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 36)) = 0;
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 37)) = 0;
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 38)) = 0;
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 39)) = ((struct Obj03955 *)(((u8*)a1)))->f8;
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 40)) = ((struct Obj03955 *)(((u8*)a1)))->f9;
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 41)) = ((struct Obj03955 *)(((u8*)a1)))->fA;
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 42)) = ((struct Obj03955 *)(((u8*)a1)))->fB;
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 43)) = ((struct Obj03955 *)(((u8*)a1)))->fC;
    *(u8*)(((u8*)a0 + ((struct Obj00554 *)(((u8*)a0)))->f1AC * 20 + 44)) = ((struct Obj03955 *)(((u8*)a1)))->fD;
    ((struct Obj00554 *)(((u8*)a0)))->f1AC = ((struct Obj00554 *)(((u8*)a0)))->f1AC + 1;
}

