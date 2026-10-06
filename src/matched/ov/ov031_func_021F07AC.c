/*
 * function: func_021F07AC
 * address:  0x021F07AC
 * packet:   pkt_ov031_021F07AC
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note: 2026-10-05 (wave P6 U7b) closed from 28 B. The palette row offset is a byte
 * offset written (k * 0xE0) << 1 (the 0x1C0 byte length is the same row size), and the
 * flag helper tests e[0x20] == 0 first. The offset form fixed the k/c register swap
 * and the early shift; the helper polarity fixed bne vs beq.
 * symbols:
 *   func_0204162C  0x0204162C  arm
 *   func_02082D44  0x02082D44  arm
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0202DCC4  0x0202DCC4  thumb
 *   func_0202DC9C  0x0202DC9C  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_0202DC60  0x0202DC60  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045924  0x02045924  arm
 *   d_021F1040     0x021F1040  data  ov031  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct { int a, b; } Pair;

struct Slot {
    u32 h;
    u8  f;
    u8  pad[3];
};

struct Obj {
    u32 w0;
    char pad0[0x40 - 4];
    u32 w40;
    u32 w44;
    u32 w48;
    u32 a[3];
    u32 b[3];
    struct Slot s[3];
    u32 w7c;
};

struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Obj0202DC98;
struct Obj0202DCC4;
struct Strbuf;
struct U16Vec;
extern u32 func_0204162C(int channel);
extern void func_02082D44(void *src, void *dst, int n);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 bit);
extern u32 func_0202DCC4(const struct Obj0202DCC4 *p, u32 i);
extern void func_0202DC9C(struct Obj0202DC98 *o, int i, u32 a1);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_0202DC60(struct Obj *p, u32 a, void *w, u32 i, u32 e);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern const Pair d_021F1040;
static inline int paletteFlag(const u8 *e)
{
    if (e[0x20] == 0) return 0;
    return 2;
}

void func_021F07AC(struct Obj *p, const u8 *e, u8 k)
{
    u16 *pal;
    int c;
    Pair t;
    void *x;
    void *buf;
    u32 q;
    int off;

    pal = (u16 *)func_0204162C(6);
    off = (k * 0xE0) << 1;
    c = paletteFlag(e);
    func_02082D44(pal, (u8 *)pal + off, 0x1C0);
    func_020413B0(6, 0, k * 7, 0x20, 7, c);
    func_02041B6C(6);
    t = d_021F1040;
    if (p->b[k] == 0) {
        if (func_0202DCC4((const struct Obj0202DCC4 *)p->w7c, k) == 1)
            func_0202DC9C((struct Obj0202DC98 *)p->w7c, k, 1);
    } else if (p->b[k] == 1) {
        func_02043B5C(func_02045770((struct Descriptor *)p->a[k]), 0);
        func_02045334((struct Descriptor *)p->a[k]);
    }
    if (e[0x21] == 0) {
        func_0202DC60((struct Obj *)p->w7c, p->a[k], (void *)(e + 0x10), k, (u32)(&t));
        p->b[k] = 0;
    } else {
        switch (e[0x21]) {
        case 1:
            x = func_02045EC0((struct MsgBank *)p->w48, 6);
            break;
        case 2:
            x = func_02045EC0((struct MsgBank *)p->w48, 0);
            break;
        case 3:
            x = func_02045EC0((struct MsgBank *)p->w48, 1);
            break;
        case 4:
            x = func_02045EC0((struct MsgBank *)p->w48, 2);
            break;
        case 5:
            x = func_02045EC0((struct MsgBank *)p->w48, 3);
            break;
        case 0:
            return;
        default:
            return;
        }
        func_02045374((struct Cfg *)p->a[k]);
        func_02041B6C(func_02045730((struct Descriptor *)p->a[k]));
        q = p->w40;
        func_0201C724((void *)q, (u32)func_02045770((struct Descriptor *)p->s[k].h), (s16)0, (s16)t.b, (u32)x, p->w44, (u32)0x440);
        p->s[k].f = 1;
        func_02045808(x);
        p->b[k] = 1;
    }
    buf = func_020457B0(8, 0x15);
    func_02045924(buf, (const u16 *)e);
    func_0201C724((void *)p->w40, (u32)func_02045770((struct Descriptor *)p->a[k]), (s16)0, (s16)0, (u32)buf, p->w44, (u32)0x440);
    func_02045808(buf);
    if (e[0x22] != 0) {
        buf = func_02045EC0((struct MsgBank *)p->w48, (e[0x22] == 1) ? 4 : 5);
        func_0201C724((void *)p->w40, (u32)func_02045770((struct Descriptor *)p->a[k]), (s16)0x74, (s16)0, (u32)buf, p->w44, (u32)0x440);
        func_02045808(buf);
    }
}
