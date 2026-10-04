/*
 * function: func_0215FF54
 * address:  0x0215FF54
 * packet:   pkt_ov010_0215FF54
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C404  0x0200C404  thumb
 *   func_0200C468  0x0200C468  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_020355D8  0x020355D8  arm
 *   func_0216025C  0x0216025C  thumb  ov010
 *   func_02160018  0x02160018  thumb  ov010
 *   d_02172960     0x02172960  data  a4
 *   func_02160668  0x02160668  thumb  ov010
 *   func_021606D0  0x021606D0  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
struct Big;
struct Desc;

extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C404(void *sys);
struct Work;
extern u16 func_0200C468(const u8 *a);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC();
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_02188C7C(unsigned char *p);
extern void func_0216D9A0(void *map);
extern void func_020355D8(u8 v);
extern int func_0216025C(void *evt, u32 *state, struct Ctx *c);
extern int func_02160018(void *evt, u32 *state, struct Work *w);
extern u8 d_02172960[];
extern int func_02160668(int *a0, int *a1);
extern void func_021606D0(int a, int b);

/* the 0x40-byte block hung off the record */
struct Sub {
    int          owner;  /* 0x00 */
    int          field;  /* 0x04 */
    struct Desc *desc;   /* 0x08 */
    u32          f0C;
    u32          f10;
    void        *fn14;
    void        *fn18;
    u32          f1C;
    void        *rec;    /* 0x20 */
    u8           pad24[0x40 - 0x24];
};

/* the 0x20-byte record behind the descriptor */
struct Rec {
    struct Desc *desc;   /* 0x00 */
    int          owner;  /* 0x04 */
    int          field;  /* 0x08 */
    u32          f0C;
    struct Sub  *sub;    /* 0x10 */
    u16          id;     /* 0x14 */
    u16          f16;
    u32          f18;
    u32          f1C;
};

struct Desc *func_0215FF54(int a0, int a1, u16 a2)
{
    void *sp8;
    struct Desc *r5;
    struct Rec *p;

    sp8 = func_0200C404(func_02012EBC((struct Big *)func_020120F4((const struct Ctx *)a0)));
    if (func_0200C468(sp8) == 1) {
        r5 = func_020122C0((void *)a0, 0, (void *)func_0216025C, 0x20);
    } else {
        r5 = func_020122C0((void *)a0, 0, (void *)func_02160018, 0x20);
    }
    p = (struct Rec *)func_020124E8((struct Obj *)r5);
    func_02082BCC(p, 0, 0x20);
    p->owner = a0;
    p->desc = r5;
    p->field = a1;
    p->id = a2;
    p->f18 = 0;
    p->sub = (struct Sub *)func_02030734(4, 0x40, 0, (const char *)d_02172960, 0xc2);
    func_02082BCC(p->sub, 0, 0x40);
    p->sub->owner = p->owner;
    p->sub->field = p->field;
    p->sub->desc = r5;
    if (func_0200C468(sp8) != 1) {
        p->sub->fn14 = (void *)func_02160668;
        p->sub->fn18 = (void *)func_021606D0;
        p->sub->rec = p;
    }
    func_0216D9A0(func_02188C7C((unsigned char *)p->field));
    func_020355D8(0);
    return r5;
}
