/*
 * function: func_021B6434
 * address:  0x021B6434
 * packet:   pkt_ov093_021B6434
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9114  0x021B9114  thumb  ov093
 *   func_021BA54C  0x021BA54C  thumb  ov093
 *   func_021BA6C0  0x021BA6C0  thumb  ov093
 *   func_021BA878  0x021BA878  thumb  ov093
 *   func_021BA2E4  0x021BA2E4  thumb  ov093
 *   func_021B64CC  0x021B64CC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct P {
    u8 pad00[0x88];
    int f88;
    u8 pad8c[0x35];
    u8 fc1_0 : 1;
    u8 fc1_1 : 1;
};

struct S {
    struct P *f00;
    u8 pad04[0x42c];
    int f430;
    int f434;
    int f438;
    u8 pad43c[0x28];
    int (*f464)(struct S *);
};

extern u8 func_021B9114(u8 **p);
extern int func_021BA54C(struct S *s);
extern void func_021BA6C0(struct S *s);
extern void func_021BA878(struct S *s);
extern void func_021BA2E4(struct S *s);
extern int func_021B64CC(struct S *s);

int func_021B6434(int a0, int a1, int a2, struct S *s)
{
    u32 t;
    u32 r;

    if (s->f464 == 0) {
        return 1;
    }
    if (s->f464(s) != 0) {
        if (func_021B9114((u8 **)s) == 0) {
            t = func_021BA54C(s);
            func_021BA6C0(s);
            func_021BA878(s);
            func_021BA2E4(s);
            switch (t) {
            case 1:
                s->f00->f88 = s->f430 + s->f434;
                break;
            case 0:
            case 2:
                s->f00->f88 = -s->f438;
                break;
            }
        } else {
            r = func_021B64CC(s);
            s->f00->fc1_1 = r;
        }
        return 1;
    }
    return 0;
}
