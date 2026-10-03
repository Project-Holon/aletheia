/*
 * function: func_021B937C
 * address:  0x021B937C
 * packet:   pkt_ov093_021B937C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D6C24  0x021D6C24  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021D5864  0x021D5864  thumb  ov093
 *   func_021B9AF8  0x021B9AF8  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D6C24(void *m);
extern u8 func_021D5440(u8 *p);
extern int func_021B8DDC(int m);
extern void *func_021D5864(void *m);
extern char *func_021B9AF8(char *p, int i);
extern u32 func_021B9B94(void *p);
extern u8 *func_021B9C00(void *p, u32 i);
extern void *func_021D5844(void *m);

u8 *func_021B937C(int a, char *b, u8 *c)
{
    u8 *t;
    void *v;
    void *k;
    int e;
    char *g;
    u32 n;
    u32 i;

    if (func_021D6C24(c)) {
        e = func_021B8DDC(func_021D5440(c));
        k = func_021D5864(c);
        g = func_021B9AF8(b, e);
        n = func_021B9B94(g);
        for (i = 0; i < n; i++) {
            t = func_021B9C00(g, (u8)i);
            v = func_021D5844(t);
            if (v == k)
                return t;
        }
    }
    return c;
}
