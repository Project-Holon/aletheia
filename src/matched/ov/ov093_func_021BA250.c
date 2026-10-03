/*
 * function: func_021BA250
 * address:  0x021BA250
 * packet:   pkt_ov093_021BA250
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B9940  0x021B9940  thumb  ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_021B8714  0x021B8714  thumb  ov093
 *   func_0201B7B4  0x0201B7B4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 func_021D5440(u8 *p);
extern u8 *func_021B9940(char *, u8);
extern void *func_021D5844(void *);
extern char *func_021B8714(char **);
extern void func_0201B7B4(void *, int, u16, u16);

void func_021BA250(char *p, u8 *a, int b)
{
    u8 i;
    void *x;
    void *y;
    void *xv;
    void *yv;
    char *q;

    i = func_021D5440(a);
    x = func_021B9940(p + 0x1b0, i);
    y = func_021B9940(p + 0xc8, i);
    xv = func_021D5844(x);
    yv = func_021D5844(y);
    q = func_021B8714((char **)p);
    func_0201B7B4(xv, b, *(u16 *)(q + 0xa), (*(u16 *)(p + 0x468) & 0x7fff) | 0x8000);
    func_0201B7B4(yv, b, *(u16 *)(q + 0xa), (*(u16 *)(p + 0x468) & 0x7fff) | 0x8000);
}
