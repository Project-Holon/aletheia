/*
 * packet: pkt_ov187_0220AF40
 * function: BR_MAIN_Init
 * address: 0x0220AF40
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * region: ov187
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BATTLE_REC_AllocWork 0x0200B400 thumb
 *   BR_MAIN_InitSceneManager 0x0220B008 thumb ov187
 *   BR_MAIN_SetDesiredScene 0x0220B0F8 thumb ov187
 *   d_0220B2A0 0x0220B2A0 data a4
 */
#include "../include/Obj24881.h"
extern void GFL_HEAP_CreateChildHeap(unsigned, unsigned, unsigned);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, unsigned int size, unsigned int heap);
extern void *MI_CpuFill8(void *, int, unsigned);
extern void BATTLE_REC_AllocWork(unsigned);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct S;
extern void BR_MAIN_InitSceneManager(struct S *p, u32 a, u32 b, u32 c);
extern void BR_MAIN_SetDesiredScene(u8 *p, u32 v);
extern const char d_0220B2A0[];
int BR_MAIN_Init(struct Proc *a, unsigned unused, unsigned mode)
{
    char *p;
    GFL_HEAP_CreateChildHeap(1, 0x59, 0x12000);
    p = PROCSYS_AllocProcWork(a, 0x17f4, 0x59);
    MI_CpuFill8(p, 0, 0x17f4);
    ((struct Obj24881 *)p)->f17F0 = mode;
    BATTLE_REC_AllocWork(0x59);
    BR_MAIN_InitSceneManager((struct S *)p, (unsigned)d_0220B2A0, (unsigned)p, 0x59);
    BR_MAIN_SetDesiredScene((u8 *)p, 0);
    return 1;
}
