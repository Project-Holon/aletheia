/*
 * function: func_021B0DF0
 * address:  0x021B0DF0
 * packet:   pkt_ov021_021B0DF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B0DF0  0x021B0DF0  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_020127A4  0x020127A4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_021B0BAC  0x021B0BAC  thumb
 *   func_020113D0  0x020113D0  thumb
 *   func_021B0CEC  0x021B0CEC  thumb
 */

typedef unsigned short u16;
extern u16 func_02159B10(int, int);
extern void *func_0215A5E4(void *a0);
extern char *func_020127A4(void *);
typedef unsigned char  u8;
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
typedef unsigned int   u32;
extern int func_021B0BAC(u32 b, u16 id, u16 c, u16 d, u16 e, int f);
extern void func_020113D0(char *p, int val);
extern int func_021B0CEC(int, int);

int func_021B0DF0(int a, int b)
{
    u16 v0, v1, v2, v3, v4, v5;
    v0 = func_02159B10(a, b);
    v1 = func_02159B10(a, b);
    v2 = func_02159B10(a, b);
    v3 = func_02159B10(a, b);
    v4 = func_02159B10(a, b);
    v5 = func_02159B10(a, b);
    if (func_02008550((const struct Sub0200852CObj *)(func_020127A4(func_0215A5E4((void *)b)) + 0x20))) {
        v1 = v2;
    }
    if (func_021B0BAC(b, v3, v0, v1, v4, v5) == 1) {
        func_020113D0((char *)a, (int)func_021B0CEC);
        return 1;
    }
    return 0;
}
