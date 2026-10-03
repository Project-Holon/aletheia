/*
 * function: func_021BB65C
 * address:  0x021BB65C
 * packet:   pkt_ov172_021BB65C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE034  0x021BE034  thumb  ov172
 *   func_021BE03C  0x021BE03C  thumb  ov172
 *   func_021BE044  0x021BE044  thumb  ov172
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_020452E8  0x020452E8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern u32 func_021BE034(void *p);
extern u32 func_021BE03C(void *p);
extern u32 func_021BE044(void *p);
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct PrintSys;
struct U16Vec;
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020456F8(struct Descriptor *d);
extern void *func_020450F0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(void *a, void *b, u32 c, u32 d, void *e, u32 f, u16 g);
extern void func_02045808(struct U16Vec *vec);
extern void func_020452E8(struct Descriptor *d);

void func_021BB65C(void *ctx, u8 *p, int k)
{
    void *last;
    void *w8;
    void *w7;
    void *w6;
    void *w5;
    void *w4;
    void *w3;
    void *w2;
    void *w1;
    void *w0;
    void *old;
    void *h3c;
    void *h44;
    u32 h34;

    h34 = func_021BE034(ctx);
    h3c = (void *)func_021BE03C(ctx);
    h44 = (void *)func_021BE044(ctx);
    old = *(void **)(p + 0x48);
    if (old != 0) {
        func_0201C6EC(h44);
        func_0201F7A8(*(void **)(p + 0x48), 2);
        func_020456F8(*(void **)(p + 0x48));
    }
    *(int *)(p + 0x3c) = k;
    if (k == 1) {
        *(void **)(p + 0x48) = func_020450F0(4, 2, 8, 0x1c, 0xd, 0xa, 1);
        func_02043B5C(func_02045770(*(void **)(p + 0x48)), 0xf);
        func_02045334(*(void **)(p + 0x48));
        w0 = func_02045EC0(h3c, 6);
        func_0201C724(h44, func_02045770(*(void **)(p + 0x48)), 0x40, 0x4, w0, h34, 0x440);
        func_02045808(w0);
        w1 = func_02045EC0(h3c, 7);
        func_0201C724(h44, func_02045770(*(void **)(p + 0x48)), 0x40, 0x18, w1, h34, 0x440);
        func_02045808(w1);
        w2 = func_02045EC0(h3c, 8);
        func_0201C724(h44, func_02045770(*(void **)(p + 0x48)), 0x40, 0x2c, w2, h34, 0x440);
        func_02045808(w2);
        w3 = func_02045EC0(h3c, 10);
        func_0201C724(h44, func_02045770(*(void **)(p + 0x48)), 0x40, 0x40, w3, h34, 0x440);
        func_02045808(w3);
        last = func_02045EC0(h3c, 9);
        func_0201C724(h44, func_02045770(*(void **)(p + 0x48)), 0x40, 0x54, last, h34, 0x440);
        func_02045808(last);
    } else {
        *(void **)(p + 0x48) = func_020450F0(4, 2, 0x10, 0x1c, 6, 0xa, 1);
        func_02043B5C(func_02045770(*(void **)(p + 0x48)), 0xf);
        func_02045334(*(void **)(p + 0x48));
        w4 = func_02045EC0(h3c, 0);
        func_0201C724(h44, func_02045770(*(void **)(p + 0x48)), 0x8, 0x0, w4, h34, 0x440);
        func_02045808(w4);
        w5 = func_02045EC0(h3c, 1);
        func_0201C724(h44, func_02045770(*(void **)(p + 0x48)), 0x8, 0x10, w5, h34, 0x440);
        func_02045808(w5);
        w6 = func_02045EC0(h3c, 2);
        func_0201C724(h44, func_02045770(*(void **)(p + 0x48)), 0x8, 0x20, w6, h34, 0x440);
        func_02045808(w6);
        w7 = func_02045EC0(h3c, 3);
        func_0201C724(h44, func_02045770(*(void **)(p + 0x48)), 0x50, 0x0, w7, h34, 0x440);
        func_02045808(w7);
        w8 = func_02045EC0(h3c, 4);
        func_0201C724(h44, func_02045770(*(void **)(p + 0x48)), 0x50, 0x10, w8, h34, 0x440);
        func_02045808(w8);
        last = func_02045EC0(h3c, 5);
        func_0201C724(h44, func_02045770(*(void **)(p + 0x48)), 0x50, 0x20, last, h34, 0x440);
        func_02045808(last);
    }
    *(int *)(p + 0x38) = 1;
    if (old != 0) {
        func_020452E8(old);
    }
}
