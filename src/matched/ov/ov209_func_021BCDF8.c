/*
 * function: func_021BCDF8
 * address: 0x021BCDF8
 * packet: pkt_ov209_021BCDF8
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: int step schedules the p copy before movs r6,16; enum step swaps those instructions (DIFF4).
 * symbols:
 *   func_021B7A64 0x021B7A64 thumb ov067
 *   func_021BE5D4 0x021BE5D4 thumb ov209
 *   func_021BE588 0x021BE588 thumb ov209
 *   func_021BE43C 0x021BE43C thumb ov209
 *   func_021BD280 0x021BD280 thumb ov209
 *   func_02021ED8 0x02021ED8 thumb
 *   func_0207D534 0x0207D534 arm
 *   func_021BC730 0x021BC730 thumb ov209
 *   func_021BC90C 0x021BC90C thumb ov209
 *   func_021BC91C 0x021BC91C thumb ov209
 */
typedef struct S S;
typedef unsigned short u16;
typedef unsigned char  u8;
extern int func_021B7A64(struct S *p);
extern void func_021BE5D4(char *, int);
extern void func_021BE588(char *);
extern void func_021BE43C(char *);
extern void func_021BD280(char *);
extern unsigned func_02021ED8(const char *);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_021BC730(char *p, u8 a, u8 b);
extern void func_021BC90C(char *, int);
extern int func_021BC91C(char *);
enum Value { V0 };
int func_021BCDF8(char *p)
{
    int step;
    switch (*(int *)(p + 0xc30)) {
    case 0:
        if (func_021B7A64(*(S **)(p + 0xc2c)) == 0) {
            func_021BE5D4(p, 0);
            func_021BE588(p);
            func_021BE43C(p);
            func_021BD280(p);
            (*(int *)(p + 0xc30))++;
        }
        break;
    case 1:
        if (func_02021ED8(*(char **)(p + 12)) == 0) {
            func_0207D534((unsigned short *)0x0400006c, 0);
            func_0207D534((unsigned short *)0x0400106c, 0);
            func_021BC730(p, step = 16, 0);
            step -= 24;
            func_021BC90C(p, step);
            (*(int *)(p + 0xc30))++;
        }
        break;
    case 2:
        if (func_021BC91C(p) == 0 && func_02021ED8(*(char **)(p + 12)) == 0) {
            *(int *)(p + 0xc30) = 0;
            return 4;
        }
        break;
    }
    return 3;
}
