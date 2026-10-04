/*
 * function: ov208_func_021BD634
 * address:  0x021BD634
 * packet:   pkt_ov208_021BD634
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-04 (D1-08): also tried `struct Ov208Pos pos = {0}` in a nested block (compiler zeroes with strh, not a memset call; 203 bytes out).
 *
 * 2026-10-02 (lane C2-01): also tried a local `one = 1` shared by all three uses of 1, f4 store after
 * the pos memset, f4/f34 stores swapped: 8/16/12 bytes out, no better.
 * 8 bytes out: the store p->f4 = 1 (str r7, [r5, #4]) is scheduled after the
 * memset argument setup in the image, before it in every spelling tried.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_020416D4  0x020416D4  arm
 *   func_021BD56C  0x021BD56C  thumb
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_021BD880  0x021BD880  thumb
 *   func_021BD89C  0x021BD89C  thumb
 *   data_021C8314  0x021C8314  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Ov208ActDesc {
    int f0;
    s16 x;
    s16 y;
    u16 h8;
    u16 ha;
    u16 hc;
    u16 he;
    u16 h10;
    u16 h12;
    u16 h14;
    u16 h16;
    u32 f18;
    u32 f1c;
};

struct Ov208ActKind {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u32 e;
    u32 f;
};

struct Ov208Pos {
    s16 x;
    s16 y;
    u16 h4;
    u8  b6;
    u8  b7;
};

struct Ov208ActObj {
    u32 f0;
    u32 f4;
    u32 f8;
    void (*fc)(void);
    u32 f10;
    struct Ov208ActDesc desc;
    u32 f34;
};

extern void func_02082BCC(void *p, u32 v, u32 n);
extern u8   func_020416D4(u32 layer);
extern int  func_021BD56C(int *p, int i);
extern u32  func_0204B294(u32 owner, u32 i, u32 j, u32 k, struct Ov208Pos *e, u16 f, u16 g);
extern void func_0204B92C(u32 obj, int v);
extern void func_021BD880(void);
extern void func_021BD89C(void);
extern const struct Ov208ActKind data_021C8314[];

void ov208_func_021BD634(struct Ov208ActObj *p, u32 owner, int *res, struct Ov208ActDesc *desc,
                         u32 prio, u16 mode)
{
    struct Ov208Pos pos;
    u32 i;
    u32 j;
    u32 k;
    int n;

    func_02082BCC(p, 0, 0x38);
    p->desc = *desc;
    p->f34 = 0;
    p->f4 = 1;
    func_02082BCC(&pos, 0, 8);
    pos.b7 = func_020416D4((u8)res[3]);
    pos.x = desc->x;
    pos.y = desc->y;
    if (desc->f0 >= 7) {
        i = desc->ha;
        j = desc->hc;
        k = desc->he;
        p->f10 = 0;
    } else {
        i = func_021BD56C(res, 1);
        j = func_021BD56C(res, 0);
        k = func_021BD56C(res, 2);
        n = desc->f0;
        p->desc.h10 = data_021C8314[n].a;
        p->desc.h12 = data_021C8314[n].b;
        p->desc.h14 = data_021C8314[n].c;
        p->desc.f18 = data_021C8314[n].e;
        p->desc.f1c = data_021C8314[n].d;
        p->f10 = data_021C8314[n].f;
    }
    p->f8 = p->desc.h10;
    pos.h4 = p->desc.h10;
    p->f0 = func_0204B294(owner, i, j, k, &pos, prio, mode);
    func_0204B92C(p->f0, 1);
    switch (p->f10) {
    case 0:
        p->fc = func_021BD880;
        break;
    case 1:
        p->fc = func_021BD89C;
        break;
    }
}
