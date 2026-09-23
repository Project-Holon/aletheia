/*
 * docs/families/cluster_02075DA0.h -- declarations for the pseudo-family at
 * 0x02075DA0..0x0207608C in the ARM9 image.  REFERENCE ONLY; nothing includes
 * this file.
 *
 * A small TWL-environment query layer: func_02075DA0 returns a module pointer
 * (s_data_0215019C), func_02075E04 returns the TWL ROM header buffer
 * (pool word 0x02FFE000), func_02075FCC turns the header's access-control
 * word at +0x1B4 into a 3-bit permission mask, and the two unlabelled leaves
 * func_02076050 / func_02076070 are a tail call and a flag predicate on
 * g_02150200.
 *
 * COMPILER: dsi/1.1p1 (func_02075FCC is byte-exact under both 1.1p1 and
 * ../2.0/sp2).  ISA: ARM throughout; pass --arm.
 */
#ifndef CLUSTER_02075DA0_H
#define CLUSTER_02075DA0_H

typedef unsigned char u8;
typedef unsigned int  u32;

/* The access-control word, read as u32 bitfields (lsl/lsr #0x1f pairs). */
typedef struct {
    u32 b0_4  : 5;
    u32 b5    : 1;      /* enables the photo checks without granting 4   */
    u32 b6_7  : 2;
    u32 b8    : 1;      /* grants 4 and enables the checks               */
    u32 b9_14 : 6;
    u32 b15   : 1;      /* grants 1                                      */
    u32 b16   : 1;      /* grants 2                                      */
    u32 rest  : 15;
} Access;
typedef struct { u8 pad[0x1b4]; Access access; } Hdr;

extern int   OS_GetBootType(void);          /* 0x02087B04 arm */
extern int   OS_IsRunOnTwl(void);           /* 0x02085D3C arm */
extern Hdr  *func_02075E04(void);           /* 0x02075E04 arm */
extern u32   func_02075FCC(void);           /* EXACT*          */

#endif /* CLUSTER_02075DA0_H */
