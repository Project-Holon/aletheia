/*
 * function: func_021B14F4
 * address:  0x021B14F4
 * packet:   pkt_ov021_021B14F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159190  0x02159190  thumb  ov010
 *   func_021B0480  0x021B0480  thumb  ov021
 *   func_021B10A4  0x021B10A4  thumb  ov021
 *   func_021B1268  0x021B1268  thumb  ov021
 *   func_021B13F8  0x021B13F8  thumb  ov021
 *   func_021B0A88  0x021B0A88  thumb  ov021
 */

int func_02159190(int a);
typedef unsigned int   u32;
void func_021B0480(u32 a);
void func_021B10A4(void *p);
void func_021B1268(void *p);
void func_021B13F8(u32 a);
void func_021B0A88(u32 a, u32 b);

int func_021B14F4(int a, int b)
{
    if (func_02159190(1)) {
        func_021B0480(b);
    }
    if (func_02159190(3)) {
        func_021B10A4((void *)b);
    }
    if (func_02159190(4)) {
        func_021B1268((void *)b);
    }
    if (func_02159190(6)) {
        func_021B13F8(b);
    }
    if (func_02159190(2)) {
        func_021B0A88(a, b);
    }
    return 1;
}
