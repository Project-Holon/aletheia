/*
 * function: BTLV_EFFVM_CmdStartFadeTask
 * address:  0x021FB648
 * packet:   pkt_ov094_021FB648
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_02030734  0x02030734  arm
 *   func_02040588  0x02040588  arm
 *   func_02030DA8  0x02030DA8  arm
 *   BTLV_EFFECT_RegisterTask  0x021F896C  thumb  ov094
 *   BTLV_EFFVM_BlendRegisterTaskMain  0x021FE79C  thumb  ov094
 *   BTLV_EFFVM_BlendRegisterTaskEnd  0x021FE8AC  thumb  ov094
 *   d_0220AE68     0x0220AE68  data   ov094  a1
 */
#include "../include/Obj07879.h"
typedef unsigned short u16;

extern char d_0220AE68[];

struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *p);
extern void *func_02030734(unsigned int heap, unsigned int size, int clear, const char *file, u16 line);
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern int func_02030DA8(int a, void (*fn)(void), int *p, int d);
extern void BTLV_EFFECT_RegisterTask(void *h, void (*cb)(void *), int arg);
extern void BTLV_EFFVM_BlendRegisterTaskMain(void *h, int *s);
extern void BTLV_EFFVM_BlendRegisterTaskEnd(void *h);

int BTLV_EFFVM_CmdStartFadeTask(struct Cursor *a, char *b)
{
    int *p;

    p = func_02030734((u16)((((struct Obj07879 *)b)->f238 & 0x7fff) | 0x8000), 0x28, 1, d_0220AE68, 0xd88);
    p[0] = (int)b;
    p[2] = VM_GetU32(a);
    p[3] = VM_GetU32(a);
    p[4] = VM_GetU32(a);
    p[5] = VM_GetU32(a);
    p[6] = VM_GetU32(a);
    p[8] = VM_GetU32(a);
    p[9] = VM_GetU32(a);
    func_02040588(1, 0);
    func_02040588(2, 0);
    BTLV_EFFECT_RegisterTask((void *)func_02030DA8(((struct Obj07879 *)b)->f8, (void (*)(void))BTLV_EFFVM_BlendRegisterTaskMain, p, 0), BTLV_EFFVM_BlendRegisterTaskEnd, 1);
    ((struct Obj07879 *)b)->f0 |= 0x100;
    return ((struct Obj07879 *)b)->f23C;
}
