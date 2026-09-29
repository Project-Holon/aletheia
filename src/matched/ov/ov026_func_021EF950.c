/*
 * function: func_021EF950
 * address:  0x021EF950
 * packet:   pkt_ov026_021EF950
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   func_02006148  0x02006148  thumb
 *   func_02006224  0x02006224  thumb
 *   func_021A2604  0x021A2604  thumb  ov021
 *   func_021EF93C  0x021EF93C  thumb  ov026
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 func_020056EC(u32 v);
extern int func_02006148(u32 a0);
extern int func_02006224(void);
extern void func_021A2604(int, int, int);
extern void func_021EF93C(s16 *p);

void func_021EF950(int a, s16 *p, int c)
{
    if (c == 0) {
        return;
    }
    if (p[6] > p[7] - 0x4A) {
        return;
    }
    p[9]++;
    if (p[9] < p[10]) {
        return;
    }
    func_02006148(0x71F);
    if (func_02006224() == 0) {
        int t = func_020056EC(0x1B) + 0x64;
        func_021A2604(a, 0x71E, t);
        func_021EF93C(p);
        return;
    }
    p[9] = p[10] - 10;
}
