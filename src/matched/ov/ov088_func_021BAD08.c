/*
 * function: func_021BAD08
 * address:  0x021BAD08
 * packet:   pkt_ov088_021BAD08
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Title menu graphics setup: creates the fourteen handles at +0x80 from
 * the 6-byte table d_021BD7C4 (released by func_021BB164), then draws each
 * menu text window into them.  The real extent is 1116 bytes (a literal
 * pool sits mid-body at 0x021BAEF8).
 *
 * Match levers: the bg = p->f68 load is hoisted into a local ahead of each
 * func_0201C724 call; slot[1].on = 1 sits inside both arms of the if so the
 * constant 1 stays in r7; the last seven blocks declare bg in block scope,
 * which hands out their spill slots high to low (function-scope bg gives
 * them low to high; see docs/idioms/function-scope-versus-block-scope-
 * decides-spill-slot-order.md).
 *
 * symbols:
 *   func_02045088  0x02045088  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_02045808  0x02045808  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201F158  0x0201F158  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_020139B0  0x020139B0  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_02008854  0x02008854  thumb
 *   func_02008848  0x02008848  thumb
 *   func_0200890C  0x0200890C  thumb
 *   func_02013E4C  0x02013E4C  thumb
 *   func_02013A48  0x02013A48  thumb
 *   func_02008748  0x02008748  thumb
 *   func_0200864C  0x0200864C  thumb
 *   func_02008650  0x02008650  thumb
 *   func_0200CA10  0x0200CA10  thumb
 *   func_0200D0AC  0x0200D0AC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200C258  0x0200C258  thumb
 *   d_021BD7C4     0x021BD7C4  data  a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ent6 {
    u8 a0, a1, a2, a3, a4, a5;
};

struct Slot {
    void *obj;
    u8 on;
};

struct Menu {
    void *f00;
    void *f04;
    u8 pad08[8];
    void *f10;
    u8 pad14[0x58 - 0x14];
    void *f58;
    void *f5c;
    void *f60;
    void *f64;
    void *f68;
    u8 pad6c[0x80 - 0x6c];
    struct Slot slot[14];
};

extern const struct Ent6 d_021BD7C4[];

extern void func_02045088(int);
extern void *func_020450F0(int, int, int, int, int, int, int);
extern void *func_02045EC0(void *, int);
extern void *func_02045770(void *);
extern void func_02045808(void *);
extern void func_0201C724(void *, void *, int, int, void *, void *, int);
extern void func_0201F02C(void *, int, void *);
extern void func_0201F250(void *, void *, void *);
extern void func_0201F158(void *, int, void *);
extern void func_0201EFA4(void *, int, void *, int, int, int);
extern int func_02008550(void *);
extern void func_020139B0(int);
extern int func_020142E8(void *, int);
extern void *func_02008854(void *);
extern u16 *func_02008848(void *);
extern void func_0200890C(void *, void *);
extern void *func_02013E4C(u16);
extern void func_02013A48(void);
extern void *func_02008748(void *);
extern void *func_0200864C(void *);
extern void *func_02008650(void *);
extern void *func_0200CA10(void *);
extern void *func_0200D0AC(void *, int);
extern void *func_0200C0F0(void *);
extern void *func_0200C258(void *);

void func_021BAD08(struct Menu *p)
{
    u32 i;
    void *a;
    void *s;
    void *b;
    void *bg;
    u16 buf[14];

    func_02045088(11);
    for (i = 0; i < 14; i++) {
        p->slot[i].obj = func_020450F0(d_021BD7C4[i].a0, d_021BD7C4[i].a1, d_021BD7C4[i].a2,
                                       d_021BD7C4[i].a3, d_021BD7C4[i].a4, d_021BD7C4[i].a5, 1);
    }

    a = func_02045EC0(p->f5c, 0);
    bg = p->f68;
    func_0201C724(bg, func_02045770(p->slot[0].obj), 0, 4, a, p->f58, 0x440);
    p->slot[0].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 12);
    func_0201F02C(p->f60, 0, p->f04);
    func_0201F250(p->f60, p->f64, a);
    if (func_02008550(p->f04) == 0) {
        bg = p->f68;
        func_0201C724(bg, func_02045770(p->slot[1].obj), 0, 0, p->f64, p->f58, 0xC80);
        p->slot[1].on = 1;
    } else {
        bg = p->f68;
        func_0201C724(bg, func_02045770(p->slot[1].obj), 0, 0, p->f64, p->f58, 0x14C0);
        p->slot[1].on = 1;
    }
    func_02045808(a);

    a = func_02045EC0(p->f5c, 16);
    func_020139B0(0x800B);
    if (func_020142E8(p->f10, 0x966) == 1) {
        s = func_02013E4C(func_02008848(func_02008854(p->f00))[2]);
    } else {
        func_0200890C(p->f00, buf);
        s = func_02013E4C(buf[0]);
    }
    func_02013A48();
    func_0201F158(p->f60, 0, s);
    func_0201F250(p->f60, p->f64, a);
    bg = p->f68;
    func_0201C724(bg, func_02045770(p->slot[2].obj), 0, 0, p->f64, p->f58, 0x440);
    p->slot[2].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 9);
    b = func_02008748(p->f00);
    func_0201EFA4(p->f60, 0, func_0200864C(b), 3, 0, 1);
    func_0201EFA4(p->f60, 1, func_02008650(b), 2, 2, 1);
    func_0201F250(p->f60, p->f64, a);
    bg = p->f68;
    func_0201C724(bg, func_02045770(p->slot[3].obj), 0, 0, p->f64, p->f58, 0x440);
    p->slot[3].on = 1;
    func_02045808(a);

    if (func_020142E8(p->f10, 0x962) == 1) {
        a = func_02045EC0(p->f5c, 10);
        func_0201EFA4(p->f60, 0, func_0200D0AC(func_0200CA10(p->f00), 11), 3, 0, 1);
        func_0201F250(p->f60, p->f64, a);
        bg = p->f68;
        func_0201C724(bg, func_02045770(p->slot[4].obj), 0, 0, p->f64, p->f58, 0x440);
        p->slot[4].on = 1;
        func_02045808(a);
    }

    a = func_02045EC0(p->f5c, 11);
    func_0201EFA4(p->f60, 0, func_0200C258(func_0200C0F0(p->f00)), 2, 0, 1);
    func_0201F250(p->f60, p->f64, a);
    bg = p->f68;
    func_0201C724(bg, func_02045770(p->slot[5].obj), 0, 0, p->f64, p->f58, 0x440);
    p->slot[5].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 1);
    {
        void *bg = p->f68;
        func_0201C724(bg, func_02045770(p->slot[6].obj), 0, 4, a, p->f58, 0x440);
    }
    p->slot[6].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 2);
    {
        void *bg = p->f68;
        func_0201C724(bg, func_02045770(p->slot[7].obj), 0, 4, a, p->f58, 0x440);
    }
    p->slot[7].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 4);
    {
        void *bg = p->f68;
        func_0201C724(bg, func_02045770(p->slot[8].obj), 0, 4, a, p->f58, 0x440);
    }
    p->slot[8].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 5);
    {
        void *bg = p->f68;
        func_0201C724(bg, func_02045770(p->slot[9].obj), 0, 4, a, p->f58, 0x440);
    }
    p->slot[9].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 3);
    {
        void *bg = p->f68;
        func_0201C724(bg, func_02045770(p->slot[10].obj), 0, 4, a, p->f58, 0x440);
    }
    p->slot[10].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 7);
    {
        void *bg = p->f68;
        func_0201C724(bg, func_02045770(p->slot[11].obj), 0, 4, a, p->f58, 0x440);
    }
    p->slot[11].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 6);
    {
        void *bg = p->f68;
        func_0201C724(bg, func_02045770(p->slot[12].obj), 0, 4, a, p->f58, 0x440);
    }
    p->slot[12].on = 1;
    func_02045808(a);
}
