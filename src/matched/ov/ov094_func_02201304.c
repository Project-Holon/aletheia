/*
 * function: func_02201304
 * address: 0x02201304
 * packet: pkt_ov094_02201304
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker (cleared 2026-10-01, arm9 leaf filed): ARM9 sole-ref/code 02015F40 belongs to the integrator.
 * Verified C: one, Thumb dsi/1.1p1 -O4,p EXACT 16 bytes;
 * proof: scratchpad/overlay-goal-20260930-w29/B6/f40-proof.log
 * symbols for blocker: NNSi_G2dMCEnumAnimBank 0x02064D70 arm
 *   extern void NNSi_G2dMCEnumAnimBank(void *, void *, unsigned);
 *   void MCSS_SetCellCallback(char *p, unsigned flags, void *callback)
 *   { NNSi_G2dMCEnumAnimBank(p + 0x68, callback, flags); }
 * lever: Offset local precedes the entry pointer, and is initialized first.
 * split: Caller-only tu --suggest-split MATCH, zero viable pieces; both
 * 02015F40 witnesses are inside this callback. No overlay leaves filed.
 * symbols:
 *   func_021F8694 0x021F8694 thumb ov094
 *   func_020307B0 0x020307B0 arm
 *   func_02030EAC 0x02030EAC arm
 *   MCSS_GetAnimCtrl 0x02015EE8 thumb
 *   MCSS_SetCellCallback 0x02015F40 thumb
 *   func_02201810 0x02201810 thumb ov094
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   d_0220AE78 0x0220AE78 data a4
 *   func_021F86C4 0x021F86C4 thumb ov094
 *   func_021F9824 0x021F9824 thumb ov094
 *   MCSS_SetAnimeIndex 0x02016028 thumb
 *   MCSS_SetAnimCallback 0x02015F2C thumb
 *   func_02201718 0x02201718 thumb ov094
 */
#include "../include/Obj21725.h"
#include "../include/Obj21726.h"
#include "../include/Obj21727.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
extern int func_021F8694(void);
extern u32 func_020307B0(void *p);
struct Node;
extern void func_02030EAC(struct Node *n);
extern void *MCSS_GetAnimCtrl(void *);
extern void MCSS_SetCellCallback(char *p, unsigned flags, void *callback);
extern int func_02201810(u32 flags, int a, int *out, int key);
extern u32 func_0203F0A8(void);
extern const u8 d_0220AE78[];
extern int func_021F86C4(void);
extern int func_021F9824(void *);
extern void MCSS_SetAnimeIndex(void *, u32);
extern void MCSS_SetAnimCallback(void *, u32, void (*)(int), int);
extern void func_02201718(int);
void func_02201304(void *task, int *q)
{
    char *p = (char *)func_021F8694();
    int i = q[1];
    int off;
    char *e;
    if (i == -1) {
        func_020307B0(q);
        func_02030EAC(task);
        return;
    }
    off = i * 0x5c;
    e = p + 8;
    if (*(void **)(e + off) == 0) {
        func_020307B0(q);
        func_02030EAC(task);
        return;
    }
    switch (q[0]) {
    case 0:
        ((struct Obj21726 *)((char *)MCSS_GetAnimCtrl(*(void **)(e + off))))->fC = 0;
        MCSS_SetCellCallback(*(void **)(e + off), i | 0x80000000, func_02201810);
        q[0]++;
        q[2] = d_0220AE78[(u32)(((u64)func_0203F0A8() * 3) >> 32)];
        return;
    case 1:
        q[2]--;
        if (q[2] != 0 && ((struct Obj21725 *)p)->f51C == 0 && func_021F9824((void *)func_021F86C4()) != 0) break;
        MCSS_SetAnimeIndex(*(void **)(e + off), 0);
        ((struct Obj21727 *)((char *)MCSS_GetAnimCtrl(*(void **)(e + off))))->fC = 1;
        MCSS_SetCellCallback(*(void **)(e + off), i, func_02201810);
        q[0]++;
        return;
    case 2:
        MCSS_SetAnimCallback(*(void **)(e + off), i, func_02201718, 1);
        func_020307B0(q);
        func_02030EAC(task);
        *(int *)(p + off + 0x30) = 0;
        break;
    }
}
