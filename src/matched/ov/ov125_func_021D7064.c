/*
 * unit: yes
 * function: func_021D7064, func_021D7120
 * address: 0x021D7064
 * packet: pkt_ov125_021D7064
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7700 0x021D7700 thumb ov125
 *   func_021D7154 0x021D7154 thumb ov125
 *   func_021D71CC 0x021D71CC thumb ov125
 *   func_021D75E8 0x021D75E8 thumb ov125
 *   func_021D85E8 0x021D85E8 arm ov125
 *   func_0200B490 0x0200B490 thumb
 *   func_0200B91C 0x0200B91C thumb
 *   func_0200B4B8 0x0200B4B8 thumb
 */
typedef unsigned short u16;
extern char *func_021D7700(void);
extern void func_0200B784(u16, int *, int *);
extern int func_021D7154(int, int, int *, int *);
extern void func_021D71CC(void *, void *, int);
extern void func_0200B490(void *);
extern void *func_0200B91C(void);
extern void func_0200BA44(void *);
extern void func_0200B4B8(void);
extern int *func_021D85E8(void);
extern int func_021D75E8(int, int, int, u16 *, int, u16);
int func_021D7064(char *p, const u16 *s)
{
    char *base;
    char *out;
    char *r;
    int outer, inner;
    int n, m;
    int i;
    int *obj;
    int result;
    if (s[2] == 0 && *(int *)(p + 0x5a0) != 0) {
        r = func_021D7700();
        func_0200B490(r);
        func_0200B784(*(u16 *)(r + 0xa6), &n, &m);
        i = 0;
        out = p + 0x498;
        base = r + 0xd00;
        for (; i < 12; i++) {
            if (!func_021D7154((int)p, i, &outer, &inner)) break;
            func_021D71CC(out + i * 22, base + outer * 676 + inner * 112 + 50, 11);
        }
        func_0200BA44(func_0200B91C());
        func_0200B4B8();
    }
    obj = func_021D85E8();
    result = func_021D75E8(*(int *)p, obj[1], obj[2], (u16 *)(s + 2), (int)(s + 3), (u16)*(int *)(p + 0x13c));
    if (result == 2 || result == 3) return 1;
    return 0;
}
int func_021D7120(void) { return 1; }
