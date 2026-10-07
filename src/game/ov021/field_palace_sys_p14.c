/*
 * file:     field_palace_sys_p14.c
 * unit:     yes
 * function: func_021D32C4, func_021D32F8, func_021D331C
 * address:  0x021D32C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207D63C  0x0207D63C  arm
 *   func_0207D658  0x0207D658  arm
 *   func_0207D67C  0x0207D67C  arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_0207D63C(int, int, int, int, int);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_0207D67C(u32 reg, int a, int b, int c, int d, int e);
void func_021D32C4(int *p, int main);
void func_021D32F8(u32 *p, int main);
void func_021D331C(const int *p, int sub);
void func_021D335C(u32 *p, int sub);


void func_021D32C4(int *p, int main)
{
    if (main) {
        func_0207D63C(0x04000050, p[0], p[1], p[2], p[3]);
    } else {
        func_0207D63C(0x04001050, p[0], p[1], p[2], p[3]);
    }
}


void func_021D32F8(u32 *p, int main)
{
    if (main) {
        func_0207D658(0x04000050, p[0], p[1]);
    } else {
        func_0207D658(0x04001050, p[0], p[1]);
    }
}


/*
 * Addresses are Black-image addresses.
 * func_021D335C is an unlabelled leaf after the first function's pool.
 */
void func_021D331C(const int *p, int sub)
{
    if (sub) {
        func_0207D67C(0x04000050, p[0], p[1], p[2], p[3], p[4]);
    } else {
        func_0207D67C(0x04001050, p[0], p[1], p[2], p[3], p[4]);
    }
}


void func_021D335C(u32 *p, int sub)
{
    if (sub) {
        *(volatile u16 *)0x04000052 = p[0] | (p[1] << 8);
    } else {
        *(volatile u16 *)0x04001052 = p[0] | (p[1] << 8);
    }
}
