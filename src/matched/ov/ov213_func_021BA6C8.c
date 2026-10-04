/*
 * function: func_021BA6C8
 * address: 0x021BA6C8
 * packet: pkt_ov213_021BA6C8
 * region: ov213
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: writing zero fields first restores r0/r2 colours while stores
 * remain scheduled after the nonzero fields (C4 diagnostic).
 * symbols:
 *   func_021BAC94 0x021BAC94 thumb ov213
 *   func_021B6208 0x021B6208 thumb ov067
 * evidence: ov213 021B95BC loads ov067 (pool 021B96B0=0x43).
 * width: 6208 heap widened: original forwards full r2 at 021BA706.
 */
#include "../include/Obj14695.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { int f0, f4, f8, fC; } Out;
typedef struct { int f0; u32 f4; int f8, fC, f10, f14, f18; u8 b1c,b1d,b1e; } In;
extern u32 func_021BAC94(char *p);
extern void func_021B6208(Out *out, In *in, int unused, unsigned heap);
void func_021BA6C8(char *p, void *state, short heap)
{
    int resource;
    In config;
    ((struct Obj14695 *)p)->f0 = state;
    ((struct Obj14695 *)p)->f4 = heap;
    config.f0=0;
    config.f4=0;
    config.f8=0xB5;
    config.fC=9;
    config.f10=8;
    config.f14=7;
    config.f18=6;
    config.b1c=0;
    config.b1d=0;
    config.b1e=4;
    resource=func_021BAC94(state);
    func_021B6208((Out *)(p+8), &config, resource, heap);
}
