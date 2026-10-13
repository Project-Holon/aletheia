/*
 * function: MCSS_CreatePaletteCopyTask
 * address:  0x0201624C
 * packet:   pkt_020160D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MIi_CpuCopy16  0x02082A60  arm
 *   data_020A72CC  0x020A72CC  data
 *   MCSS_TransPaletteTask  0x0201691C  thumb
 *   MCSS_DeletePaletteTask  0x02016C38  thumb
 */
#include "../include/Obj01613.h"
#include "../include/Obj06865.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj_0201691C;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MIi_CpuCopy16(const void *src, void *dest, u32 size);
extern int MCSS_DeletePaletteTask(int a0);
extern void *func_02030DA8(void *a0, void *callback, void *ctx, int a3);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void MCSS_TransPaletteTask(void *a0, struct Obj_0201691C *a1);

extern char data_020A72CC[];

struct Inner {
    u32 f00;
    u32 f04;
    u32 f08;
    void *f0c;
};

struct Obj {
    u8 pad00[4];
    struct Inner *f04;
    u8 pad08[4];
    void *f0c;
    u8 pad10[0xc];
    u32 f1c;
    void *f20;
    void *f24;
    u32 f28;
};

void MCSS_CreatePaletteCopyTask(u8 *a0, u8 *a1)
{
    struct Obj *p;
    u32 flag;
    void *ret;

    flag = 1;
    p = (struct Obj *)func_02030734((u16)(((u16)((struct Obj01613 *)a1)->f14C & 0x7FFF) | 0x8000), 0x2C, 1, data_020A72CC, 1942);
    p->f20 = a0;
    if (((struct Obj06865 *)a0)->f8 == 0) {
        flag = 0;
    }
    p->f28 = flag;
    p->f24 = a1;
    p->f0c = a1 + 0xC0;
    p->f1c = ((struct Obj06865 *)a0)->f34 + (((struct Obj01613 *)a1)->f148 << 5);

    flag = 0;
    p->f04 = (struct Inner *)func_02030734((u16)(((u16)*((u32 *)(a1 + 0x148) + 1) & 0x7FFF) | 0x8000), 0x10, 0, data_020A72CC, 1950);
    p->f04->f00 = ((struct Obj01613 *)a1)->fC0;
    p->f04->f04 = flag;
    p->f04->f08 = ((struct Obj01613 *)a1)->fDC;

    p->f04->f0c = func_02030734((u16)(((u16)*((u32 *)(a1 + 0x148) + 1) & 0x7FFF) | 0x8000), ((struct Obj01613 *)a1)->fDC, 0, data_020A72CC, 1950 + 5);
    MIi_CpuCopy16(((struct Obj01613 *)a1)->fD4, p->f04->f0c, ((struct Obj01613 *)a1)->fDC);

    if (((struct Obj01613 *)a1)->f8 != 0) {
        MCSS_DeletePaletteTask((int)(((struct Obj01613 *)a1)->f8));
        ((struct Obj01613 *)a1)->f8 = (void *)flag;
    }

    if (((struct Obj06865 *)a0)->f8 != 0) {
        ret = func_02030DA8(((struct Obj06865 *)a0)->f8, MCSS_TransPaletteTask, p, 0);
    } else {
        ret = func_020056A0(MCSS_TransPaletteTask, p, 0);
    }
    ((struct Obj01613 *)a1)->f8 = ret;

    *(u32 *)(a1 + (5 << 6)) &= 0xEFFFFFFF;
}
