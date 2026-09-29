/*
 * function: func_021B6848
 * address:  0x021B6848
 * packet:   pkt_ov093_021B6848
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8BEC  0x021B8BEC  thumb  ov093
 *   func_021B68D8  0x021B68D8  thumb  ov093
 *   func_021B9114  0x021B9114  thumb  ov093
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02007B44  0x02007B44  thumb
 *   func_02007B20  0x02007B20  thumb
 *   func_02007C20  0x02007C20  thumb
 *   func_021B997C  0x021B997C  thumb  ov093
 *   func_021BA710  0x021BA710  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct P {
    u8 pad00[0x44];
    u8 f44[4];
};

struct T {
    u8 pad00[0x21];
    u8 f21;
    u8 pad22[0x36];
    u32 f58;
};

extern u8 func_021B8BEC(u8 *s, u32 k, u8 n);
extern void func_021B68D8(u8 *s, struct T *t);
extern int func_021B9114(u8 *s);
extern u32 func_02012EBC(u32 a);
extern u32 func_02007B44(void);
extern u32 func_02007B20(u16 a);
extern void func_02007C20(u32 a, u32 b);
extern u8 func_021B997C(u8 *s, int k);
extern int func_021BA710(int, u8);

void func_021B6848(u8 *s, struct T *t)
{
    u32 i;
    u32 v;
    u8 tmp[4];
    u8 k = t->f21;

    i = 0;
    s[0x46c] = k;
    s[0x46d] = func_021B8BEC(s, k, 0);
    func_021B68D8(s, t);
    if (func_021B9114(s) == 0) {
        func_02012EBC(t->f58);
        v = func_02007B44();
        *(u32 *)(s + 0x3e0) = func_02007B20(*(u16 *)(s + 0x468));
        func_02007C20(*(u32 *)(s + 0x3e0), v);
        (*(struct P **)s)->f44[0] = func_021B997C(s, i);
    } else {
        for (i = 0; i < 4; i++) {
            tmp[func_021BA710(s[0x46c], i)] = (*(struct P **)s)->f44[i];
        }
        for (i = 0; i < 4; i++) {
            (*(struct P **)s)->f44[i] = tmp[i];
        }
    }
}
