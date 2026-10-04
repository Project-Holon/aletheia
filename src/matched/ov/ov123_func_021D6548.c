/*
 * function: func_021D6548
 * address: 0x021D6548
 * packet: pkt_ov123_021D6548
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207E3D0 0x0207E3D0 arm
 *   d_021DAA88 0x021DAA88 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern void func_0207E3D0(const void *, int, int);
extern const u16 d_021DAA88[10];
void func_021D6548(void *unused, u8 *p)
{
    int line;
    int idx;
    int d;
    int v;
    idx = *(s16 *)(p + 0x43C6) + 1;
    line = *(volatile u16 *)0x04000006;
    idx = (line + idx) % 0xC0;
    if (*(volatile u16 *)0x04000004 & 2) {
        *(volatile u32 *)0x0400001C = *(s16 *)(p + 0x43C8 + idx * 2) & 0x1FF;
        v = *(int *)(p + 0x455C);
        if (v >= 0xC0) {
            func_0207E3D0(d_021DAA88, 0x142, 2);
            return;
        }
        if (v == 0) {
            func_0207E3D0(&d_021DAA88[9], 0x142, 2);
            return;
        }
        if (line > 200) {
            func_0207E3D0(d_021DAA88, 0x142, 2);
            return;
        }
        if (v > line) {
            func_0207E3D0(d_021DAA88, 0x142, 2);
            return;
        }
        d = line - v;
        if ((u32)d < 10 && d >= 0) {
            func_0207E3D0(&d_021DAA88[d], 0x142, 2);
            return;
        }
        func_0207E3D0(&d_021DAA88[9], 0x142, 2);
    }
}
