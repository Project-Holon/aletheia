/*
 * function: func_021A6DC4
 * address:  0x021A6DC4
 * packet:   pkt_ov021_021A6DC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D5F8  0x0216D5F8  thumb
 *   func_021A71E4  0x021A71E4  thumb
 *   func_021A70D0  0x021A70D0  thumb
 *   func_021A7198  0x021A7198  thumb
 *   func_021A712C  0x021A712C  thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_021A3074(unsigned char *p);
extern u32 func_0216D5F8(void *a);
extern u32 func_021A71E4(void *a, u32 *b, u16 *c, u32 d);
extern void func_021A70D0(void *a, u32 *b, u32 c, u32 d, u16 *e, u32 f, u32 g);
extern u32 func_021A7198(void *a, u32 *b, u16 *c, u32 d);
extern void func_021A712C(void *a, u32 *b, u32 c, u32 d, u16 *e, u32 f, u32 g);

void func_021A6DC4(u32 *b, void *a)
{
    u16 out2[6];
    u16 out1[4];
    u32 k = func_0216D5F8(func_021A3074(((unsigned char **)b)[1]));
    if (b[0] == 0) {
        if (func_021A71E4(a, b, out1, k) != 0) {
            func_021A70D0(a, b, k, 0, out1, 0, 0);
        }
    } else {
        if (func_021A7198(a, b, out2, k) != 0) {
            func_021A712C(a, b, k, 0, out2, 0, 0);
        }
    }
    b[2] = 0;
}
