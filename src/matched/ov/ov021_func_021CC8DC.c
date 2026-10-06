/*
 * function: func_021CC8DC
 * address:  0x021CC8DC
 * packet:   pkt_ov021_021CC8DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC40  0x0201BC40  thumb
 *   func_0201BCB4  0x0201BCB4  thumb
 *   func_0204AF28  0x0204AF28  arm
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_020185F0  0x020185F0  thumb
 *   func_0201BA68  0x0201BA68  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_02049238  0x02049238  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    void *f4;
    void *f8;
    u16 heap;
    u16 padE[(0x7C - 0xE) / 2];
    u16 f7C;
    u16 f7E;
    u16 f80[6];
    u16 f8C[6];
} Obj;

extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *h, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_020185F0(void *p);
extern u32 func_0201BA68(void *mon);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void func_02049238(void *h);

void func_021CC8DC(Obj *p)
{
    void *arc;
    int i;
    int n;

    arc = func_020490F4(7, p->heap);
    p->f7C = func_0204ACEC(arc, func_0201BC3C(), 0, 0x60, p->heap);
    p->f7E = func_0204AF28(arc, func_0201BC40(), func_0201BCB4(), p->heap);
    n = func_0201AA18(p->f4);
    for (i = 0; i < n; i++) {
        p->f80[i] = func_0204A6C8(arc, func_0201BA68((void *)func_020185F0(func_0201AB28(p->f4, i))), 0, 0, p->heap);
    }
    if (p->f8 != 0) {
        n = func_0201AA18(p->f8);
        for (i = 0; i < n; i++) {
            p->f8C[i] = func_0204A6C8(arc, func_0201BA68((void *)func_020185F0(func_0201AB28(p->f8, i))), 0, 0, p->heap);
        }
    }
    func_02049238(arc);
}
