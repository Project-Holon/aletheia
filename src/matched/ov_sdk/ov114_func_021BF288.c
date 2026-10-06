/*
 * function: func_021BF288
 * address:  0x021BF288
 * packet:   pkt_ov114_021BF288
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BEF08 0x021BEF08  arm
 *   func_021BEF50 0x021BEF50  arm
 *   func_021BEF58 0x021BEF58  arm
 *   func_021BEC00 0x021BEC00  arm
 *   func_021BF3BC 0x021BF3BC  arm
 *   func_021B9C1C 0x021B9C1C  arm
 *   func_021BF488 0x021BF488  arm
 *   func_021BEA64 0x021BEA64  arm
 */

typedef unsigned char  u8;
extern u8 *func_021BEF08(void);
extern int func_021BEF50(void);
extern void *func_021BEF58(int p);
struct Conn;
extern struct Conn *func_021BEC00(int a, int b);
extern int func_021BF3BC(int);
extern void func_021B9C1C(int, int);
extern int func_021BF488(int);
extern void func_021BEA64(u8 *p);

int func_021BF288(int x)
{
    int a = (int)func_021BEF08();
    int b = func_021BEF50();
    int c;
    int d;

    c = (int)func_021BEC00((int)func_021BEF58(a), x);
    if (c == 0)
        return -1;
    d = func_021BF3BC(x);
    func_021B9C1C(b, 1);
    if (d != -1 && d != 0) {
        if (func_021BF488(x) == 0xf)
            func_021BEA64((u8 *)c);
    }
    return 0;
}
