/*
 * file:     unit_021EE740_p07.c
 * unit:     yes
 * function: func_021EF920, func_021EF93C, func_021EF950
 * address:  0x021EF920
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A25DC 0x021A25DC thumb ov021
 *   func_020056EC 0x020056EC thumb
 *   func_02006148  0x02006148  thumb
 *   func_02006224  0x02006224  thumb
 *   func_021A2604  0x021A2604  thumb  ov021
 */
typedef unsigned char u8;

typedef short s16_021EF920;

typedef unsigned int u32;

typedef short s16_021EF93C;

typedef unsigned short u16;

typedef signed short   s16_021EF950;

extern void func_021A25DC(u8 *, int);
extern u32 func_020056EC(u32);
extern int func_02006148(u32 a0);
extern int func_02006224(u32 a0);
extern void func_021A2604(u8 *p, int a, int b);
void func_021EF920(u8 *a, s16_021EF920 *p, int b, int c);
void func_021EF93C(s16_021EF93C *p);
void func_021EF950(int a, s16_021EF950 *p, int c);

void func_021EF920(u8 *a, s16_021EF920 *p, int b, int c)
{
    if (b != 0 && p[6] == p[7] - 24)
        func_021A25DC(a, c);
}

void func_021EF93C(s16_021EF93C *p)
{
    p[9] = 0;
    p[10] = func_020056EC(16) + 50;
}


void func_021EF950(int a, s16_021EF950 *p, int c)
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
    if (func_02006224(func_02006148(0x71F)) == 0) {
        int t = func_020056EC(0x1B) + 0x64;
        func_021A2604((u8 *)a, 0x71E, t);
        func_021EF93C(p);
        return;
    }
    p[9] = p[10] - 10;
}
