/*
 * function: func_021D8490
 * address: 0x021D8490
 * packet: pkt_ov123_021D8490
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_021B99DC 0x021B99DC thumb ov114
 *   func_021B9790 0x021B9790 thumb ov114
 *   func_021B97F4 0x021B97F4 thumb ov114
 *   func_021D6E08 0x021D6E08 thumb ov123
 *   func_021D584C 0x021D584C thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8958 0x021D8958 thumb ov123
 *   func_021D8448 0x021D8448 thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 */
extern int func_0203CD98(void);
typedef unsigned char  u8;
extern int func_021B99DC(u8 *p);
extern int func_021B9790(u8 *p);
extern char *func_021B97F4(void *);
extern int func_021D6E08(char *, int);
extern void func_021D584C(char *);
extern void func_021D6EE0(char *, int, int);
extern void func_021D8958(char *p);
extern void func_021D8448(char *p);
extern void func_021D6FF0(char *p);
void func_021D8490(char *p)
{
    char *q;
    if (func_0203CD98()) {
        if (func_021D6E08(p, func_021B99DC(*(void **)(p + 0x10)))) return;
        if (func_021B9790(*(void **)(p + 0x10))) return;
        q = func_021B97F4(*(void **)(p + 0x10));
        if (*(int *)q == 2) {
            func_021D6EE0(p, (int)func_021D8958, 0x6d4);
            return;
        }
        if (*(int *)q == 0) {
            func_021D584C(*(char **)(p + 0x18));
            func_021D6EE0(p, (int)func_021D8448, 0x6d8);
            return;
        }
        *(int *)(p + 0x80) = *(int *)q;
        func_021D6EE0(p, (int)func_021D6FF0, 0x6dc);
        return;
    } else {
        func_021D6EE0(p, (int)func_021D8958, 0x6e2);
    }
}
