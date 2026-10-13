/*
 * function: IRCBATTLEMATCH_ProcInit
 * address:  0x021BB414
 * packet:   pkt_ov100_021BB414
 * region:   ov100
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   GFL_NET_IRC_WIRELESS_Exit  0x0203D0D0  arm
 *   func_0207D63C  0x0207D63C  arm
 *   IRCBATTLEMATCH_InitScreen  0x021BA780  thumb  ov100
 */
#include "../include/Obj00178.h"

typedef unsigned short u16;

extern void GFL_HEAP_CreateChildHeap(unsigned int, unsigned int, unsigned int);
typedef unsigned int   u32;
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(int, int, int);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void GFL_NET_IRC_WIRELESS_Exit(void);
extern void func_0207D63C(int, int, int, int, int);
extern void IRCBATTLEMATCH_InitScreen(char *p);

int IRCBATTLEMATCH_ProcInit(struct Obj0203159C *a, int b, int c)
{
    int r5;

    GFL_HEAP_CreateChildHeap(1, 0x1f, 0x20000);
    r5 = 0xcf0;
    a = (struct Obj0203159C *)PROCSYS_AllocProcWork(a, r5, 0x1f);
    MI_CpuFill8((int)a, 0, r5);
    ((struct Obj00178 *)a)->f244 = c;
    ((struct Obj00178 *)a)->f278 = 0x1f;
    ((struct Obj00178 *)a)->f24C = *(int *)(((struct Obj00178 *)a)->f244 + 0x1c);
    ((struct Obj00178 *)a)->fCB4 =
        (int)func_02030734(((struct Obj00178 *)a)->f278, 0x200, 0, (const char *)0x021BB8AC, 0xb07);
    IRCBATTLEMATCH_InitScreen((char *)a);
    GFL_NET_IRC_WIRELESS_Exit();
    func_0207D63C(0x04000050, 0x10, 3, 9, 0xe);
    return 1;
}
