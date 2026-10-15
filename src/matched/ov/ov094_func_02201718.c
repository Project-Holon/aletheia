/*
 * function: BTLV_MCSS_IdleAnimCallback
 * address: 0x02201718
 * packet: pkt_ov094_02201718
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker (cleared 2026-10-01, arm9 leaf filed): ARM9 sole-ref/code 02015EF4 and 02015EEC are integrator-owned.
 * Verified C for 02015EF4 reused from ov094_func_02201810.c:
 *   typedef unsigned char u8;
 *   u8 MCSS_GetStopCellNum(char *p) { return **(u8 **)(p + 0x30); }
 * Verified C for 02015EEC: one, Thumb dsi/1.1p1 -O4,p EXACT 6 bytes;
 * proof: scratchpad/overlay-goal-20260930-w29/B6/eec-proof.log
 *   typedef unsigned short u16;
 *   u16 MCSS_GetAnimSeqNum(char *p) { return **(u16 **)(p + 0x28); }
 * lever: Bind the random draw before the variable 64-bit product.
 * split: Caller-only tu --suggest-split MATCH, zero viable pieces;
 * 02015EEC has only this caller. No overlay leaves filed.
 * symbols:
 *   BTLV_EFFECT_GetMcss 0x021F8694 thumb ov094
 *   BTLV_EFFECT_GetEffvm 0x021F86C4 thumb ov094
 *   BTLV_EFFVM_GetFallbackScriptFlag 0x021F9824 thumb ov094
 *   MCSS_GetStopCellNum 0x02015EF4 thumb
 *   GF_STANDARD_Rand 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   func_02030734 0x02030734 arm
 *   MCSS_GetAnimSeqNum 0x02015EEC thumb
 *   MCSS_SetAnimeIndex 0x02016028 thumb
 *   func_02030DA8 0x02030DA8 arm
 *   BTLV_MCSS_AnimWatchTaskMain 0x02201304 thumb ov094
 *   gBtlvMcssSourceFileName 0x0220AE7C data a4
 */
#include "../include/Obj13608.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct Flags { unsigned low:3; unsigned count:2; unsigned high:27; } Flags;
typedef struct GlobalFlags { unsigned low:2; unsigned disabled:1; unsigned high:29; } GlobalFlags;
extern int BTLV_EFFECT_GetMcss(void);
extern int BTLV_EFFECT_GetEffvm(void);
extern int BTLV_EFFVM_GetFallbackScriptFlag(void *);
extern u8 MCSS_GetStopCellNum(char *p);
extern u32 GF_STANDARD_Rand(void);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u16 MCSS_GetAnimSeqNum(char *p);
extern void MCSS_SetAnimeIndex(void *, u32);
extern void *func_02030DA8(void *, void (*)(void *, int *), void *, u32);
extern void BTLV_MCSS_AnimWatchTaskMain(void *, int *);
extern const char gBtlvMcssSourceFileName[];
void BTLV_MCSS_IdleAnimCallback(int i)
{
    char *p = (char *)BTLV_EFFECT_GetMcss();
    char *e;
    int off;
    unsigned n;
    u32 draw;
    int *q;
    if (i == -1) return;
    e = p + 8;
    off = i * 0x5c;
    if (*(void **)(e + off) == 0) return;
    if (BTLV_EFFVM_GetFallbackScriptFlag((void *)BTLV_EFFECT_GetEffvm()) == 0) return;
    if (((GlobalFlags *)(p + 0x510))->disabled) return;
    if (MCSS_GetStopCellNum(*(void **)(e + off)) == 0xff) {
        *(u32 *)(p + 0x54 + off) |= 0x800;
        return;
    }
    n = ((Flags *)(p + 0x54 + off))->count;
    ((Flags *)(p + 0x54 + off))->count = n - 1;
    draw = GF_STANDARD_Rand();
    if ((u32)(((u64)draw * n) >> 32) != 0) return;
    ((Flags *)(p + 0x54 + off))->count = 3;
    q = func_02030734((u16)((((struct Obj13608 *)p)->f540 & 0x7fff) | 0x8000), 12, 1, gBtlvMcssSourceFileName, 0xd5e);
    q[1] = i;
    if (MCSS_GetAnimSeqNum(*(void **)(e + off)) > 1) MCSS_SetAnimeIndex(*(void **)(e + off), 1);
    *(void **)(p + off + 0x30) = func_02030DA8(((struct Obj13608 *)p)->f0, BTLV_MCSS_AnimWatchTaskMain, q, 0);
}
