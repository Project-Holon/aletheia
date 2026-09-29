/*
 * function: func_021F3FB8
 * address:  0x021F3FB8
 * packet:   pkt_ov056_021F3FB8
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_020143CC  0x020143CC  thumb
 *   func_02028A7C  0x02028A7C  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 *f0;
    u16 f4;
    u32 f8;
    int fc;
} S3F30;

extern int func_02188C80(int a);
extern int func_020120F4(int a);
extern int func_0201296C(int a);
extern int func_02012A30(int a);
extern u16 *func_020143CC(u32 a, int b);
extern void func_02028A7C(int a, int b);

void func_021F3FB8(int a, int b, S3F30 *c)
{
    int r5;

    r5 = func_020120F4(func_02188C80(b));
    c->f8 = func_0201296C(r5);
    c->fc = func_02012A30(r5);
    c->f0 = func_020143CC(c->f8, 0x4001);
    if (*c->f0 == 0) {
        func_02028A7C(c->fc, 0x7ef);
        c->f4 = 0;
        return;
    }
    c->f4 = 1;
}
