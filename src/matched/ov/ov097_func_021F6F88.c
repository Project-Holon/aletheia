/*
 * function: func_021F6F88
 * address: 0x021F6F88
 * packet: pkt_ov097_021F6F88
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: integer object base; the icon array address comes from a static
 * inline accessor of field fB4 (the inlined parameter and the result share
 * one spill slot: str p; adds #0xb4; str); merged icon is u16.
 * note 2026-10-05: replaced the stand-in `icons = p; icons = p + 0xb4;`
 * with the accessor IconBase(p). EXACT in --lang c99 and --lang c. An
 * accessor returning u32 * with icons[i] stores gives DIFF; one that copies
 * into a local and adds (r = obj; r += 0xb4) gives DIFF.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_020185F4 0x020185F4 thumb
 *   func_0201BA68 0x0201BA68 thumb
 *   func_0201BABC 0x0201BABC thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCEC 0x0201BCEC thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0202775C 0x0202775C thumb
 *   func_02027758 0x02027758 thumb
 *   func_02027760 0x02027760 thumb
 *   func_02027764 0x02027764 thumb
 */
#include "../include/Obj00410.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(unsigned int id, u16 heap);
extern void *func_020185F4(void *);
extern u32 func_0201BA68(void *);
extern u32 func_0201BABC(u32, u32, u32, u32);
extern int func_0204A6C8(void *, u32, u32, u32, u16);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *, u32, u32, u32, u16);
extern int func_0201BC78(void);
extern int func_0201BCEC(void);
extern int func_0204AF28(void *, u32, u32, u32);
extern void func_02049238(void *);
extern u32 func_020275E4(void);
extern int func_0204ABF0(void *, u32, u32, u32, u16);
extern int func_0202775C(int);
extern int func_02027758(void);
extern int func_02027760(int);
extern int func_02027764(int);
static inline u32 IconBase(int obj)
{
    return (u32)&((struct Obj00410 *)obj)->fB4;
}
void func_021F6F88(int p)
{
    u32 a, b;
    void *h;
    void *h2;
    u16 i, icon;
    u32 icons;
    h = func_020490F4(7, 0x8071);
    icons = IconBase(p);
    for (i = 0; i < 6; i++) {
        if (*(void **)(p + i * 4 + 0xf8) != 0)
            icon = func_0201BA68(func_020185F4(*(void **)(p + i * 4 + 0xf8)));
        else
            icon = func_0201BABC(0, 0, 0, 0);
        *(int *)(icons + i * 4) = func_0204A6C8(h, icon, 0, 0, 0x71);
    }
    *(int *)&((struct Obj00410 *)p)->fD8 = func_0204ACEC(h, func_0201BC3C(), 0, 0, 0x71);
    a = func_0201BC78();
    b = func_0201BCEC();
    *(int *)&((struct Obj00410 *)p)->fE8 = func_0204AF28(h, a, b, 0x71);
    func_02049238(h);
    h2 = func_020490F4(func_020275E4(), 0x8071);
    ((struct Obj00410 *)p)->fD0 = func_0204A6C8(h2, 0xc, 0, 0, 0x71);
    ((struct Obj00410 *)p)->fE0 = func_0204ABF0(h2, 0xb, 0, 0x60, 0x71);
    ((struct Obj00410 *)p)->fF0 = func_0204AF28(h2, 0xf, 0x12, 0x71);
    ((struct Obj00410 *)p)->fCC = func_0204A6C8(h2, 0x41, 0, 0, 0x71);
    ((struct Obj00410 *)p)->fDC = func_0204ABF0(h2, 0x42, 0, 0x80, 0x71);
    ((struct Obj00410 *)p)->fEC = func_0204AF28(h2, 0x45, 0x48, 0x71);
    ((struct Obj00410 *)p)->fD4 = func_0204A6C8(h2, func_0202775C(2), 0, 0, 0x71);
    ((struct Obj00410 *)p)->fE4 = func_0204ABF0(h2, func_02027758(), 0, 0xa0, 0x71);
    a = func_02027760(2);
    b = func_02027764(2);
    ((struct Obj00410 *)p)->fF4 = func_0204AF28(h2, a, b, 0x71);
    func_02049238(h2);
}
