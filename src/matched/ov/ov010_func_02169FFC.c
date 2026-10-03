/*
 * function: func_02169FFC
 * address:  0x02169FFC
 * packet:   pkt_ov010_02169FFC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Res {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u8 pad0C[0x10 - 0x0C];
    void *f10;          /* 0x10 */
    void *f14;          /* 0x14 */
    void *f18;          /* 0x18 */
    void *f1C;          /* 0x1C */
    u32 f20;            /* 0x20 */
    void *f24;          /* 0x24 */
    u16 f28;            /* 0x28 */
    u32 f2C;            /* 0x2C */
    void *f30;          /* 0x30 */
    u16 f34;            /* 0x34 */
    u32 f38;            /* 0x38 */
    void *f3C;          /* 0x3C */
    void *f40;          /* 0x40 */
} Res;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 *f08;            /* 0x08 */
    void *f0C;          /* 0x0C */
    u16 f10;            /* 0x10 */
    u8 pad12[0x18 - 0x12];
    Res *f18;           /* 0x18 */
} Work;

typedef struct Slot {
    void *f00;
    u8 f04;
} Slot;

struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_021904AC(u8 *p);
extern void func_0201C6FC(void *a0, void *a1, u32 a2, u32 a3, void *a4, u32 a5);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);

void func_02169FFC(Work *w, u32 msg)
{
    void *str;
    u32 a;
    Slot *s;
    void *t;
    void *p;

    func_02043B5C(func_02045770(w->f18->f08), 15);
    func_0201F73C(w->f18->f08, 2, 1, 13);
    str = func_02045EC0(w->f18->f04, msg);
    a = func_021904AC(w->f0C);
    s = (Slot *)&w->f18->f08;
    t = w->f18->f14;
    func_0201C6FC(t, func_02045770(s->f00), 0, 0, str, a);
    s->f04 = 1;
    func_02045808(str);
    p = w->f18->f08;
    func_02045334(p);
    func_02045374(p);
    func_02041B6C(func_02045730(p));
}
