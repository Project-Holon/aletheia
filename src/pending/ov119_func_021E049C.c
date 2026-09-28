/*
 * function: func_021E049C
 * address:  0x021E049C
 * packet:   pkt_ov119_021E049C
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  0x02009020 and 0x02012F14 are unlabelled ARM9 Thumb tail-call thunks (.word runs in asm/arm9/main.s; witnesses here at 0x021E062E, 0x021E06D0, 0x021E080C); seed both and this closes EXACT
 *
 * pokemontrade_save.c.  The first two buffer copies are inlined statics
 * (their arguments are spilled before the body, and each carries its own
 * copy of the __FILE__ string); the rest call the out-of-line copies.
 * Every copy goes through the GFL_STD_MemCopy inline wrapper, whose
 * arguments are evaluated last to first: the size call, then the
 * destination load, then the source call.
 *
 * symbols:
 *   func_021D8AA8  0x021D8AA8  thumb
 *   func_021E0138  0x021E0138  thumb
 *   func_021E01A0  0x021E01A0  thumb
 *   func_021E0200  0x021E0200  thumb
 *   func_021E0410  0x021E0410  thumb
 *   sub_02030734   0x02030734  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 *   sub_02008FFC   0x02008FFC  thumb
 *   sub_02008FEC   0x02008FEC  thumb
 *   sub_02008C20   0x02008C20  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02012FCC  0x02012FCC  thumb
 *   sub_020086F0   0x020086F0  thumb
 *   sub_020076A4   0x020076A4  thumb
 *   func_0201A920  0x0201A920  thumb
 *   func_0201AC2C  0x0201AC2C  thumb
 *   sub_02007A9C   0x02007A9C  thumb
 *   sub_02007AF4   0x02007AF4  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_0202136C  0x0202136C  thumb
 *   func_02009020  0x02009020  thumb
 *   func_02008F08  0x02008F08  thumb
 *   sub_0200903C   0x0200903C  thumb
 *   func_02008EAC  0x02008EAC  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_02008570  0x02008570  thumb
 *   func_02008564  0x02008564  thumb
 *   func_02025C1C  0x02025C1C  thumb
 *   func_02025C30  0x02025C30  thumb
 *   func_02008574  0x02008574  thumb
 *   func_02012F14  0x02012F14  thumb
 *   sub_02009DE8   0x02009DE8  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   sub_0200949C   0x0200949C  thumb
 *   sub_020094D8   0x020094D8  thumb
 *   func_0201B9F0  0x0201B9F0  thumb
 *   func_0202F190  0x0202F190  thumb
 *   sub_02008DF0   0x02008DF0  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   sub_02009EB0   0x02009EB0  thumb
 *   func_02017988  0x02017988  thumb
 *   sub_0201AB48   0x0201AB48  thumb
 *   sub_020185F4   0x020185F4  thumb
 *   func_020075B0  0x020075B0  thumb
 *   sub_0201283C   0x0201283C  thumb
 *   sub_02009BB8   0x02009BB8  thumb
 *   sub_02009D1C   0x02009D1C  thumb
 *   d_021E8108     0x021E8108  data  ov119
 *   d_021E811C     0x021E811C  data  ov119
 *   d_021E8130     0x021E8130  data  ov119
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021D8AA8(char *p);
extern void *func_021E0138(void *sys, u16 heapId);
extern void *func_021E01A0(void *src, u16 heapId);
extern void *func_021E0200(void *sys, u16 heapId);
extern int func_021E0410(char *p, void *party, int idx);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *file, u32 line);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void func_020307B0(void *p);
extern u32 sub_02008FFC(void);
extern void *sub_02008FEC(void *sys);
extern u32 sub_02008C20(void);
extern void *func_02012F2C(void *sys);
extern void *func_02012FCC(void *sys);
extern void sub_020086F0(void *src, void *out);
extern u8 sub_020076A4(void *save);
extern void *func_0201A920(u32 heapId);
extern void func_0201AC2C(void *src, void *dst);
extern u32 sub_02007A9C(void);
extern void *sub_02007AF4(void *save, u32 box);
extern void *func_0201AB28(void *party, int idx);
extern u32 func_02017E1C(void *mon, u32 id, void *v);
extern void func_02017E40(void *mon, u32 id, void *v);
extern u32 func_0202136C(u16 v);
extern int func_02009020(void *obj, int v);
extern void *func_02008F08(u32 heapId);
extern void sub_0200903C(void *obj, u32 unused, int i, void *buf);
extern void func_02008EAC(void *buf);
extern u8 func_0200856C(void *p);
extern u8 func_02008570(void *p);
extern u8 func_02008564(void *p);
extern u32 func_02025C1C(u32 a, u32 b, u32 c);
extern u32 func_02025C30(u32 a, u32 b, u32 c);
extern void func_02008574(void *p, u8 a, u8 b);
extern void *func_02012F14(void *sys);
extern void sub_02009DE8(void *obj, void *p);
extern void *func_02012EBC(void *sys);
extern void *func_02009470(void *p);
extern u32 sub_0200949C(void *obj, int row, int col);
extern void sub_020094D8(void *obj, int row, int col, int value);
extern void func_0201B9F0(void *mon);
extern void func_0202F190(void *mon, u32 a1, void *a2, u32 a3, u16 a4);
extern void sub_02008DF0(void *obj, int i);
extern void *func_0200CA1C(void *sys);
extern void func_0200CDE0(void *p, void *mon);
extern void sub_02009EB0(void *obj);
extern void func_02017988(void *mon, u32 a);
extern void sub_0201AB48(void *party, u32 idx, void *mon);
extern void *sub_020185F4(void *mon);
extern void func_020075B0(void *save, u32 a, u32 b, void *c);
extern void *sub_0201283C(void *sys);
extern void sub_02009BB8(void *obj, int i, int a, int b, int c);
extern int sub_02009D1C(void *obj, void *p, int *out);
extern const char d_021E8108[];
extern const char d_021E811C[];
extern const char d_021E8130[];

typedef struct {
    u8   pad0[0x1C];
    void *party;
    u8   pad20[8];
    u16  box;
    u16  slot;
    u16  count;
} Trade;

#define I(p, o) (*(void **)((p) + (o)))
#define W(p, o) (*(int *)((p) + (o)))
#define H(p, o) (*(u16 *)((p) + (o)))
#define T(p)    (*(Trade **)((p) + 8))

static inline void GFL_STD_MemCopy(const void *src, void *dst, u32 size)
{
    MI_CpuCopy8(src, dst, size);
}

static inline void *copy_a(void *sys, u16 heapId)
{
    void *buf = sub_02030734(heapId, sub_02008FFC(), 0, d_021E811C, 0x163);

    GFL_STD_MemCopy(sub_02008FEC(sys), buf, sub_02008FFC());
    return buf;
}

static inline void *copy_b(void *sys, u16 heapId)
{
    void *buf = sub_02030734(heapId, sub_02008C20(), 0, d_021E8108, 0x182);

    GFL_STD_MemCopy(func_02012F2C(sys), buf, sub_02008C20());
    return buf;
}

void func_021E049C(char *p)
{
    void *mon;
    void *obj;
    void *list[2];
    int i;
    int out;

    if (func_021D8AA8(p) == 0) {
        I(p, 0x60C) = copy_a(I(p, 0x82C), H(p, 0x5F4));
        I(p, 0x610) = copy_b(I(p, 0x82C), H(p, 0x5F4));
        I(p, 0x614) = func_021E0138(I(p, 0x82C), H(p, 0x5F4));
        I(p, 0x618) = func_021E01A0(I(p, 0x82C), H(p, 0x5F4));
        I(p, 0x61C) = func_021E0200(I(p, 0x82C), H(p, 0x5F4));
        sub_020086F0(func_02012FCC(I(p, 0x82C)), p + 0x628);
        if (T(p)->box == sub_020076A4(I(p, 0x828))) {
            I(p, 0x620) = func_0201A920(H(p, 0x5F4));
            func_0201AC2C(I(p, 0x838), I(p, 0x620));
            W(p, 0x62C) = func_021E0410(p, I(p, 0x838), T(p)->slot);
        } else {
            I(p, 0x624) = sub_02030734(H(p, 0x5F4), sub_02007A9C(), 0, d_021E8130, 0x271);
            GFL_STD_MemCopy(sub_02007AF4(I(p, 0x828), T(p)->box), I(p, 0x624), sub_02007A9C());
        }
    } else {
        Trade *t = T(p);
        if (t->box == sub_020076A4(I(p, 0x828)))
            func_021E0410(p, I(p, 0x838), t->slot);
        p[0x11F7] = 1;
    }

    {
        Trade *t = T(p);
        if (t->box != sub_020076A4(I(p, 0x828))) {
            mon = func_0201AB28(t->party, 0);
            if (func_0202136C(func_02017E1C(mon, 6, 0))) {
                void *o = sub_02008FEC(I(p, 0x82C));
                int idx = func_02009020(o, 0);
                if (idx != -1) {
                    void *buf = func_02008F08(H(p, 0x5F4));
                    func_02017E1C(mon, 0xA7, buf);
                    sub_0200903C(o, 0, idx, buf);
                    func_02008EAC(buf);
                    func_02017E40(mon, 0xA7, buf);
                    func_02017E40(mon, 6, 0);
                    func_020307B0(buf);
                }
            }
        }
    }

    {
        u8 a = func_0200856C(I(p, 0x834));
        u8 b = func_02008570(I(p, 0x834));
        u32 ra = func_02025C1C(a, b, func_02008564(I(p, 0x834)));
        u32 rb = func_02025C30(a, b, func_02008564(I(p, 0x834)));
        if (a != ra || b != rb)
            func_02008574(I(p, 0x834), 0, 0);
    }

    sub_02009DE8(func_02012F14(I(p, 0x82C)), I(p, 0x834));
    obj = func_02009470(func_02012EBC(I(p, 0x82C)));
    list[0] = I(p, 0x830);
    list[1] = I(p, 0x834);
    for (i = 0; i < 2; i++) {
        void *q = list[i];
        if (q) {
            u8 row = func_0200856C(q);
            u8 col = func_02008570(q);
            func_02008564(q);
            if (!sub_0200949C(obj, row, col))
                sub_020094D8(obj, row, col, 1);
        }
    }

    mon = func_0201AB28(T(p)->party, 0);
    obj = func_02012F2C(I(p, 0x82C));
    func_0201B9F0(mon);
    if (func_02017E1C(mon, 0x4C, 0) == 0)
        func_02017E40(mon, 9, (void *)0x46);
    if (func_02017E1C(mon, 0x4C, 0))
        func_0202F190(mon, 6, I(p, 0x830), 0x7533, H(p, 0x5F4));
    switch (W(p, 0x118C)) {
    case 2:
    case 3:
        sub_02008DF0(obj, 0x10);
        break;
    case 1:
        sub_02008DF0(obj, 0xC);
        break;
    case 0:
        sub_02008DF0(obj, 0x24);
        break;
    }
    func_0200CDE0(func_0200CA1C(I(p, 0x82C)), mon);
    if (W(p, 0x118C) == 3)
        sub_02009EB0(func_02012F14(I(p, 0x82C)));
    if (func_02017E1C(mon, 5, 0) == 0x1EC && func_02017E1C(mon, 0x6F, 0) == 1) {
        func_02017988(mon, 0);
        func_0200CDE0(func_0200CA1C(I(p, 0x82C)), mon);
    }
    {
        Trade *t = T(p);
        if (t->box == sub_020076A4(I(p, 0x828))) {
            sub_0201AB48(I(p, 0x838), t->slot, mon);
        } else {
            t = T(p);
            func_020075B0(I(p, 0x828), t->box, t->slot, sub_020185F4(mon));
        }
    }
    switch (W(p, 0x118C)) {
    case 2:
        sub_02009BB8(sub_0201283C(I(p, 0x82C)), T(p)->count - 1, 0, 0, 1);
        break;
    case 0:
    case 1:
        if (sub_02009D1C(sub_0201283C(I(p, 0x82C)), I(p, 0x834), &out))
            sub_02009BB8(sub_0201283C(I(p, 0x82C)), out, 0, 0, 1);
        break;
    }
}
