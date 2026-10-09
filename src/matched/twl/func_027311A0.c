/*
 * function: func_027311A0
 * address:  0x027311A0
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 */
typedef unsigned short u16;
typedef unsigned int u32;

void func_027311A0(u32 data, u32 *cmd, u32 *p2, u32 *p3, u32 *p4)
{
    if (cmd != 0) {
        *cmd = (data >> 20) & 0xF;
    }
    if (p2 != 0) {
        *p2 = (data >> 18) & 3;
    }
    if (p3 != 0) {
        *p3 = (data >> 16) & 3;
    }
    if (p4 != 0) {
        *p4 = (u16)data;
    }
}
