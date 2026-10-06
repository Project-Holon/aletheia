/*
 * function: func_021BF518
 * address:  0x021BF518
 * packet:   pkt_ov021_021BF518
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
 *   func_0204E804 0x0204E804 arm
 */

extern void func_021BF564(int);
typedef unsigned char  u8;
extern void func_021BF584(u8 *a0);
typedef signed int     s32;
typedef unsigned int   u32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);

int func_021BF518(int a, int *s, int *q)
{
    switch (s[0]) {
    case 0:
        func_0204E720(q[3], 16, 0, q[4]);
        func_021BF564(q[1]);
        func_021BF584((u8 *)q[1]);
        s[0] = s[0] + 1;
        break;
    case 1:
        if (q[5] == 1) {
            return 1;
        }
        if (func_0204E804() == 0) {
            return 1;
        }
        break;
    }
    return 0;
}
