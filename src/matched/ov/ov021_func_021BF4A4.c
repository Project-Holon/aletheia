/*
 * function: func_021BF4A4
 * address:  0x021BF4A4
 * packet:   pkt_ov021_021BF4A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BF564 0x021BF564 thumb ov021
 *   func_021BF584 0x021BF584 thumb ov021
 *   func_0204E720 0x0204E720 arm
 *   func_02188C84 0x02188C84 thumb ov021
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 */

extern void func_021BF564(int);
extern void func_021BF584(int);
typedef signed int     s32;
typedef unsigned int   u32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 func_02188C84(u8 *p);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);

int func_021BF4A4(int a, int *s, int *q)
{
    int k = s[0];
    int v = q[1];

    switch (k) {
    case 0:
        func_021BF564(v);
        func_021BF584(q[1]);
        func_0204E720(q[3], 16, 0, -1);
        s[0] = s[0] + 1;
        break;
    case 1:
        func_0202208C((void *)3, 11, 11, 0, 6, 1, func_02188C84((u8 *)v));
        s[0] = s[0] + 1;
        break;
    case 2:
        if (func_020221A4() != 0) {
            s[0] = s[0] + 1;
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}
