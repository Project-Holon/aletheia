/*
 * function: func_02178F1C
 * address:  0x02178F1C
 * packet:   pkt_ov014_02178F1C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02178138  0x02178138  thumb  ov014
 *   func_0217814C  0x0217814C  thumb  ov014
 *   func_02178F8C  0x02178F8C  thumb  ov014
 *   func_02179010  0x02179010  thumb  ov014
 *   func_0208EE60  0x0208EE60  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

void func_02178138(int a);
void func_0217814C(int a);
void func_02178F8C(u8 *m);
int func_02179010(void *cb, int n);
u32 func_0208EE60(void);

int func_02178F1C(u16 n)
{
    u32 m = func_0208EE60();

    if (m == 0x8000) {
        func_0217814C(3);
        func_02178138(9);
        return 3;
    }
    if (m == 0) {
        func_0217814C(0x16);
        func_02178138(9);
        return 0x18;
    }
    if (!((1 << (n - 1)) & m)) {
        do {
            n = n + 1;
            if (n > 0x10)
                return 0x18;
        } while (!((1 << (n - 1)) & m));
    }
    return (u16)func_02179010((void *)func_02178F8C, n);
}
