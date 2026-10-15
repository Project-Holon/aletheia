/*
 * function: MCSS_LoadResource
 * address:  0x020163C4
 * packet:   pkt_020163C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The mcss.c bind-slot routine (line 0x840).  Closed in wave 15 from 16
 * bytes out by one declaration: the descriptor parameter is
 * const struct Src *.  Without const, the four constructor call sites
 * load a2 for the first argument before the second; with it the image's
 * order (second-argument base first, then the first, then the out
 * pointer copy) comes out.  History: docs/notes/MCSS_LoadResource.c.txt.
 *
 * symbols:
 *   MIi_CpuCopy16  0x02082A60  arm
 *   data_020A72CC  0x020A72CC  data
 *   MCSS_TransTextureTask  0x02016880  thumb
 *   MCSS_LoadResourceShared  0x02016630  thumb
 *   MCSS_ApplyMosaic  0x02016C60  thumb
 *   ARC_UTIL_LoadCellBankFromArchive  0x02049FBC  arm
 *   ARC_UTIL_LoadMultiCellBankFromArchive  0x0204A03C  arm
 *   ARC_UTIL_LoadAnimBankFromArchive  0x0204A0BC  arm
 *   ARC_UTIL_LoadMultiAnimBankFromArchive  0x0204A13C  arm
 *   MCSS_SetAnimeIndex  0x02016028  thumb
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   ARC_UTIL_LoadBgCharDataFromArchive  0x02049DB4  arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive  0x02049F34  arm
 *   NNSi_G2dInitVramHandle  0x02063790  arm
 *   NNSi_G2dInitVramHandleEx  0x020637D4  arm
 */
#include "../include/Obj01018.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj_02016880;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MIi_CpuCopy16(const void *src, void *dest, u32 size);
extern void *ARC_UTIL_LoadCellBankFromArchive(void *a0, void *a1, u32 a2, void *a3, u32 a4);
extern void *ARC_UTIL_LoadMultiCellBankFromArchive(void *a0, void *a1, u32 a2, void *a3, u32 a4);
extern void *ARC_UTIL_LoadAnimBankFromArchive(void *a0, void *a1, u32 a2, void *a3, u32 a4);
extern void *ARC_UTIL_LoadMultiAnimBankFromArchive(void *a0, void *a1, u32 a2, void *a3, u32 a4);
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern void *ARC_UTIL_LoadBgCharDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 a0, u32 a1, u32 a2, u32 a3);
struct Task;
struct Work;
extern void NNSi_G2dInitVramHandle(u32 *p);
extern void NNSi_G2dInitVramHandleEx(u32 *p);
extern void MCSS_SetAnimeIndex(void *p, u32 flag);
extern void MCSS_ApplyMosaic(struct Work *a0, struct Task *a1);
extern void *func_02030DA8(void *a0, void *callback, void *ctx, int a3);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void MCSS_TransTextureTask(void *a0, struct Obj_02016880 *a1);

extern char data_020A72CC[];

struct Obj {
    void *f00;
    void *f04;
    void *f08;
    void *f0c;
    void *f10;
    void *f14;
    u32 f18;
    u32 f1c;
    void *f20;
    void *f24;
    u32 f28;
};

struct Ctx {
    void *f00;
    void *f04;
    void *f08;
    u8 pad0c[8];
    void **f14;
    u8 pad18[0x18];
    u32 f30;
    u32 f34;
    u32 (*f38)(void *, void *, u32);
    u32 f3c;
};

struct Ctx;
struct Src {
    void *f00;
    void *f04;
    void *f08;
    void *f0c;
    void *f10;
    void *f14;
    void *f18;
    void *f1c;
    u32 f20;
};

extern void MCSS_LoadResourceShared(struct Ctx *a0, u32 idx, const struct Src *a2);

void MCSS_LoadResource(struct Ctx *a0, u32 idx, const struct Src *a2)
{
    u8 *a1 = (u8 *)a0->f14[idx];
    struct Obj *p;
    u32 h;
    u32 flag;
    u32 *q;

    {
        u32 t;
        if (a2->f20 == 1) {
            t = (u16)(((u16)((struct Obj01018 *)a1)->f14C & 0x7FFF) | 0x8000);
        } else {
            t = ((struct Obj01018 *)a1)->f14C;
        }
        h = (u16)t;
    }

    if (a0->f00 != 0 && a0->f04 == a2->f00) {
        MCSS_LoadResourceShared(a0, idx, a2);
        return;
    }

    *(u32 *)(a1 + (5 << 6)) &= 0xFFFFDFFF;
    NNSi_G2dInitVramHandle((u32 *)(a1 + 0x9C));
    NNSi_G2dInitVramHandleEx((u32 *)(a1 + 0xC0));

    ((struct Obj01018 *)a1)->fC = ARC_UTIL_LoadCellBankFromArchive(a2->f00, a2->f0c, 0, a1 + 0x10, h);
    ((struct Obj01018 *)a1)->f1C = ARC_UTIL_LoadMultiCellBankFromArchive(a2->f00, a2->f10, 1, a1 + 0x20, h);
    flag = 1;
    ((struct Obj01018 *)a1)->f14 = ARC_UTIL_LoadAnimBankFromArchive(a2->f00, a2->f14, 0, a1 + 0x18, h);
    ((struct Obj01018 *)a1)->f24 = ARC_UTIL_LoadMultiAnimBankFromArchive(a2->f00, a2->f18, 0, a1 + 0x28, h);
    MCSS_SetAnimeIndex(a1, 0);

    q = ARC_TOOL_LoadMember((u32)a2->f00, (u32)a2->f1c, h);
    *(u32 * *)&((struct Obj01018 *)a1)->f2C = q;
    *(u32 * *)&((struct Obj01018 *)a1)->f30 = (u32 *)((u8 *)q + ((0x30 * q[0] + 0xC) & ~3u));

    p = (struct Obj *)func_02030734((u16)(((u16)*(u32 *)(a1 + (5 << 6) + 0xC) & (0xFFFFDFFFu >> 0x11)) | (flag << 0xF)),
                                    0x2C, 1, data_020A72CC, 0x840);
    p->f20 = a0;
    if (a0->f08 == 0) {
        flag = 0;
    }
    p->f28 = flag;
    p->f08 = a1 + 0x9C;
    p->f0c = a1 + 0xC0;
    p->f18 = a0->f30 + (idx << 0xE);
    p->f1c = a0->f34 + (idx << 5);
    p->f24 = a1;

    p->f10 = ARC_UTIL_LoadBgCharDataFromArchive((u32)a2->f00, (u32)a2->f04, 1, (u32)p,
                           (u16)(((u16)((struct Obj01018 *)a1)->f14C & 0x7FFF) | 0x8000));
    p->f14 = ARC_UTIL_LoadPaletteBlockFromArchive((u32)a2->f00, (u32)a2->f08, (u32)(&p->f04),
                           (u16)(((u16)((struct Obj01018 *)a1)->f14C & 0x7FFF) | 0x8000));

    ((struct Obj01018 *)a1)->fD4 = func_02030734(h,
                                          (u32)((struct Src *)p->f04)->f08, 0,
                                          data_020A72CC, 0x858);
    ((struct Obj01018 *)a1)->fD8 = func_02030734(h,
                                          (u32)((struct Src *)p->f04)->f08, 0,
                                          data_020A72CC, 0x858 + 1);
    ((struct Obj01018 *)a1)->fDC = ((struct Src *)p->f04)->f08;
    MIi_CpuCopy16(((struct Src *)p->f04)->f0c, ((struct Obj01018 *)a1)->fD4,
                  (u32)((struct Src *)p->f04)->f08);

    if (a0->f38 != 0) {
        if (a0->f38((void*)a2, p, a0->f3c) == 1) {
            a0->f38 = 0;
            a0->f3c = 0;
        }
    }
    if (((*(u32 *)(a1 + (5 << 6)) << 4) >> 0x1C) != 0) {
        MCSS_ApplyMosaic((struct Work *)a1, (struct Task *)p);
    }
    if (a0->f08 != 0) {
        ((struct Obj01018 *)a1)->f0 = func_02030DA8(a0->f08, MCSS_TransTextureTask, p, 0);
    } else {
        ((struct Obj01018 *)a1)->f0 = func_020056A0(MCSS_TransTextureTask, p, 0);
    }
}
