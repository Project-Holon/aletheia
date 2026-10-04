/*
 * function: func_021BA8CC
 * address:  0x021BA8CC
 * packet:   pkt_ov091_021BA8CC
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02017F90  0x02017F90  thumb
 *   func_021BB56C  0x021BB56C  thumb  ov091
 *   func_0204B8F4  0x0204B8F4  arm
 *   func_0204B404  0x0204B404  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    int w0;
    u16 pad4;
    u16 h6;
    int pad8[2];
    int w10;
    int w14;
    int w18;
    int pad1c;
    u32 w20;
    int pad24[3];
    int w30;
} S;

struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct Cfg;
struct Obj;
struct PrintSys;
struct Vec2;
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern u32 func_02017F90(void *p);
extern void func_021BB56C(S *s, int a, int b, s16 *out);
extern u32 func_0204B8F4(struct Obj *p);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);

void func_021BA8CC(u32 a, S *s)
{
    s16 buf[2];

    if (s->w14 != 0)
        return;
    if (s->w18 == 1) {
        u32 t = (u32)func_02045770((struct Descriptor *)s->w20);

        if (func_0201C6C4((struct PrintSys *)(*(int *)(a + 0x140)), (void *)t) == 0) {
            a = s->w20;
            s->w18 = 0;
            func_02045334((struct Descriptor *)a);
            func_02045374((struct Cfg *)a);
            func_02041B6C(func_02045730((struct Descriptor *)a));
        }
    }
    if (s->w10 == 1 && func_02017F90((void *)s->w0) == 0 && s->h6 != 0) {
        func_021BB56C(s, 0x1a, 0x13, buf);
        if (func_0204B8F4((struct Obj *)s->w30) == 1)
            buf[1] = buf[1] - 6;
        func_0204B404((struct Obj *)s->w30, (const struct Vec2 *)buf, 0);
    }
}
