/*
 * function: func_021DC860
 * address: 0x021DC860
 * packet: pkt_ov170_021DC860
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * domain: initialized storage count is 8/16/24: ARM9 02007464 writes 8 at
 *   020074C0-020074C2; 020074D8/020076B4/020076D0 add 8 only while count
 *   != 24. The D0 guard at 0200774C-0200774E dominates store 02007764.
 *   020076A4 reads byte +0x3DD. All seven offset pools audited; 0200752C
 *   and 020075B0 only read this field. Full contexts saved in lane scratch.
 *   Thus non-24 count always assigns max in the 8/16 arms before any use.
 * extent: 158 bytes code; +0x9E 00 00 alignment padding, next labelled
 *   function 021DC900 starts at +0xA0. No follower or unit.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02007698 0x02007698 thumb
 *   func_020076A4 0x020076A4 thumb
 *   func_020078C4 0x020078C4 thumb
 *   func_020076B4 0x020076B4 thumb
 *   PROCSYS_Create 0x02031324 arm
 */
#include "../include/Obj01948.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef enum { B0=0, B8=8, B16=16 } Bound;
extern void GFL_HEAP_CreateChildHeap(unsigned int,unsigned int,unsigned int);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void MI_CpuFill8(void *,int,unsigned);
extern unsigned func_02007698(void *);
extern u8 func_020076A4(void *);
typedef unsigned int   u32;
extern int func_020078C4(void *save, u32 box);
extern u8 func_020076B4(void *);
extern void *PROCSYS_Create(int a0);
int func_021DC860(void *manager, int unused, void **context)
{
    u8 *p;
    u16 max;
    u16 i;
    GFL_HEAP_CreateChildHeap(1,75,0x10000);
    p = PROCSYS_AllocProcWork(manager,0x30,75);
    MI_CpuFill8(p,0,0x30);
    *(void ** *)&((struct Obj01948 *)p)->f0 = context;
    p[0x14] = func_02007698(context[1]);
    p[0x15] = func_020076A4((*(void ***)p)[1]);
    p[0x17] = 255;
    ((struct Obj01948 *)p)->f28 = 11;
    if ((u8)p[0x15] != 24) {
        if ((u8)p[0x15] == 8) max = B8;
        else if ((u8)p[0x15] == 16) max = B16;
        for (i=0;i<max;i++) {
            if (func_020078C4((*(void ***)p)[1],i) == 0) break;
        }
        if (i == max) p[0x15] = func_020076B4((*(void ***)p)[1]);
    }
    p[0x20] = 0;
    p[0x1f] = 0;
    p[0x21] = 1;
    ((struct Obj01948 *)p)->f4 = PROCSYS_Create(75);
    return 1;
}
