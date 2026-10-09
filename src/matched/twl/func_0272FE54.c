/*
 * function: func_0272FE54
 * address:  0x0272FE54
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0272FDC0 0x0272FDC0 arm twl
 *   func_0272F9C4 0x0272F9C4 arm twl
 */
typedef unsigned int u32;
extern void func_0272FDC0(u32, void *);
extern void func_0272F9C4(u32, u32, u32, u32, u32, u32, u32, u32, void *, u32, u32);

void func_0272FE54(u32 a0, u32 a1, u32 a2, u32 a3, int s0, u32 s1, u32 s2)
{
    u32 buf[4];
    u32 n = 10;
    if (s0 == 0) {
        n = 3;
    }
    func_0272FDC0(a0, buf);
    buf[0] = 2;
    buf[1] = 0;
    buf[2] = 0x40000;
    buf[3] = a2;
    func_0272F9C4(n, a0, 0x04004204, a1, 0, a3, s1, s2, buf, 0x0b000000, 0x80000000);
}


