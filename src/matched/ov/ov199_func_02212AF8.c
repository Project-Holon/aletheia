/*
 * function: func_02212AF8
 * address: 0x02212AF8
 * packet: pkt_ov199_02212AF8
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * matching: a switch default written as its own copy of case 0 leaves the b stub the
 *   original has; explicit copies per index (0 and 1) instead of a helper; y*2+0x21+x add order.
 * symbols:
 *   ov093_id 0x0000005D data
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_0200B480 0x0200B480 thumb
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02012F2C 0x02012F2C thumb
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_020399A8 0x020399A8 arm
 *   func_02013790 0x02013790 thumb
 *   func_020137C0 0x020137C0 thumb
 *   func_02013864 0x02013864 thumb
 *   func_02013894 0x02013894 thumb
 *   func_0201A354 0x0201A354 thumb
 *   func_0200AE14 0x0200AE14 thumb
 *   func_0200AE54 0x0200AE54 thumb
 *   func_0200B1D4 0x0200B1D4 thumb
 *   func_0200B078 0x0200B078 thumb
 *   func_02013128 0x02013128 thumb
 *   func_02013160 0x02013160 thumb
 *   func_02013980 0x02013980 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02034714 0x02034714 arm
 *   d_02213D04 0x02213D04 data a1 ov199
 *   d_02213D00 0x02213D00 data a1 ov199
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
struct Big;
struct Rec160;
extern const char ov093_id[];
extern void *func_02012EBC(struct Big *p);
extern void *func_0200B358(void *);
extern void func_0200B480(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, unsigned);
struct Entry;
struct Reg;
struct Reg2;
struct ZoneData;
extern void *func_02012F2C(int *p);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(int);
extern struct Entry *func_020399A8(void);
extern void func_02013790(void *, void *, int, int, u32);
extern void func_020137C0(void *, void *, int, int, u32);
extern void func_02013864(void *, void *, int, int, u32);
extern void func_02013894(void *, void *, int, int, u32);
extern void *func_0201A354(int, int);
extern void *func_0200AE14(void *);
extern u32 func_0200AE54(struct Reg *p, u32 id);
extern struct Rec160 *func_0200B1D4(struct Rec160 *arr, u32 index);
extern s32 func_0200B078(struct Reg2 *p, u32 id);
extern void func_02013128(void *, void *, int);
extern void func_02013160(u8 *o, void *a1, u32 a2);
extern void func_02013980(struct ZoneData *o, u32 heap);
extern u32 func_020307B0(void *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_02213D04[], d_02213D00[];
struct Sub { u32 a0; u32 a4; u8 pad[1]; };
struct Row { u8 pad[0x44]; u32 f44; };
struct In {
    u32 f0; void *f4; s32 f8; u8 padc[0x1c - 0xc]; s32 f1c; u8 pad20[0x28 - 0x20];
    struct Row *f28; struct Row *f2c; void *f30; void *f34; u8 pad38[0x8ac - 0x38]; s32 f8ac;
};
struct Pair { u32 f0; struct Row *f4; u8 f8; u8 f9; u8 pada[6]; };
struct R8 {
    struct Pair a; struct Pair b; u8 pad_b[0x48 - 0x20];
    s32 f48; u8 pad4c[4]; s32 f50; void *f54;
};
struct W4 {
    u8 pad0[8]; s32 f8; s32 fc; u8 pad10[8]; u16 f18; u16 f1a;
    u8 pad1c[0xc1 - 0x1c]; u8 fc1;
};
struct Out { void *f0; struct W4 *f4; struct R8 *f8; };
struct Out *func_02212AF8(int unused, u32 heap, struct In *p)
{
    struct Out *out;
    void *v;
    void *sys;
    int id;
    int a;
    int flag = 0;
    sys = func_0200B358(func_02012EBC(p->f4));
    out = func_02030734(heap, 0x10, 0, d_02213D04, 0x3e0);
    func_02082BCC(out, 0, 0x10);
    out->f0 = p->f4;
    func_0200B480();
    func_02082BCC((u8 *)p + 0x1b4, 0, 0x18);
    out->f8 = func_02030734(heap, 0x58, 0, d_02213D04, 0x3eb);
    func_02082BCC(out->f8, 0, 0x58);
    out->f8->f54 = func_02012F2C(p->f4);
    out->f8->f50 = 0;
    {
        struct R8 *r = out->f8;
        r->a.f4 = p->f28;
        r->a.f0 = (u32)p->f30;
        r->a.f9 = p->f28->f44;
    }
    {
        struct R8 *r = out->f8;
        struct Pair *b = &r->b;
        b->f4 = p->f2c;
        r->b.f0 = (u32)p->f34;
        b->f9 = p->f2c->f44;
    }
    out->f4 = func_02030734(heap, 0xf0, 0, d_02213D04, 0x403);
    func_02082BCC(out->f4, 0, 0xf0);
    func_02034AC4((int)ov093_id);
    if (p->f1c == 2 || p->f1c == 3) {
        id = 16;
        switch (p->f8) {
        case 0: default: id = 15; func_02013790(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        case 1: func_020137C0(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        case 2: id = 17; func_02013864(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        case 3: id = 18; func_02013894(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        case 4: id = 19; func_02013864(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        }
        v = func_0201A354(id, heap);
        flag = 1;
    } else if (p->f1c == 0) {
        v = func_0200AE14(func_0200B1D4(sys, 0));
        switch (func_0200AE54(v, 0x15)) {
        case 0: func_02013790(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        case 1: func_020137C0(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        case 2: func_02013864(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        case 3: func_02013894(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        default: func_02013790(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        }
    } else if (p->f1c == 1) {
        v = func_0200AE14(func_0200B1D4(sys, 1));
        switch (func_0200AE54(v, 0x15)) {
        case 0: func_02013790(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        case 1: func_020137C0(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        case 2: func_02013864(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        case 3: func_02013894(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        default: func_02013790(out->f4, p->f4, (int)func_020399A8(), 2, heap); break;
        }
    } else {
        func_02034714(d_02213D00, flag, d_02213D00);
    }
    if (p->f1c == 3) a = p->f8 + 0x17;
    else if (p->f1c == 2) a = p->f8 + 0x1c;
    else {
        int x = func_0200AE54(v, 0xd);
        int y = func_0200AE54(v, 0x15);
        if (x >= 2) x = 1;
        a = y * 2 + 0x21 + x;
    }
    out->f8->f48 = a;
    if (p->f1c == 2 || p->f1c == 3) {
        out->f4->f18 = 0x490;
        out->f4->f1a = 0x47d;
    } else if (p->f1c == 0) {
        void *e = func_0200B1D4(sys, 0);
        int m = func_0200B078(e, 0xb);
        int r = func_0200AE54(func_0200AE14(e), 0x12);
        if (m == 1) { out->f4->f18 = 0x48d; out->f4->f1a = 0x480; }
        else { out->f4->f18 = 0x46b; out->f4->f1a = 0x47d; }
        if ((u32)(r - 2) <= 1) {
            out->f4->fc = 0xe;
            out->f4->f8 = 0x12;
            out->f8->f50 = 1;
        }
    } else if (p->f1c == 1) {
        void *e = func_0200B1D4(sys, 1);
        int m = func_0200B078(e, 0xb);
        int r = func_0200AE54(func_0200AE14(e), 0x12);
        if (m == 1) { out->f4->f18 = 0x48d; out->f4->f1a = 0x480; }
        else { out->f4->f18 = 0x46b; out->f4->f1a = 0x47d; }
        if ((u32)(r - 2) <= 1) {
            out->f4->fc = 0xe;
            out->f4->f8 = 0x12;
            out->f8->f50 = 1;
        }
    }
    func_02013128(out->f4, p->f30, 0);
    func_02013160((u8 *)out->f4, v, (u16)((heap & 0x7fff) | 0x8000));
    if (p->f8ac) out->f4->fc1 |= 4;
    func_02013980((struct ZoneData *)out->f4, heap);
    func_02034A5C((int)ov093_id);
    if (flag) func_020307B0(v);
    return out;
}
