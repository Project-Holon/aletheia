/*
 * function: func_0216117C
 * address:  0x0216117C
 * packet:   pkt_ov010_0216117C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02012134  0x02012134  thumb
 *   func_02029DBC  0x02029DBC  thumb
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   func_0216F7BC  0x0216F7BC  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_020120F4();
extern u16 *func_020127A4();
extern int func_02012A30();
extern int func_02012134();
extern void func_02029DBC();
extern int func_02013CC8();
extern int func_02013CE0(u16);
extern int *func_0216F7BC();

void func_0216117C(int *a0, int a1)
{
    int h = func_020120F4(*(int *)a0[6]);
    u32 v = *func_020127A4();
    int f = 1;
    int s;
    int *r;

    s = func_02012A30(h);
    func_02029DBC(s, func_02012134(*(int *)a0[6]));
    if (func_02013CC8(v) != 0 || func_02013CE0(v) != 0) {
        f = 0;
    }
    r = func_0216F7BC(h, 4, f);
    if (a1 != -1) {
        r[5] = a1;
    }
}
