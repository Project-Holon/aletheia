/*
 * function: func_021B9840
 * address: 0x021B9840
 * packet: pkt_ov182_021B9840
 * region: ov182
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware 04000008/04000060 read/write 021B984E-021B988C, 04000580 write 021B98AA.
 * symbols:
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021B9C28 0x021B9C28 data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;
extern void func_020434DC(int, int);
extern void func_0207DC44(int, int, int, int);
extern void func_0207DD24(int, int, int, int, int);
extern void func_02046A94(u8, const void *);
extern void func_02046BE0(int, int);
extern const u32 d_021B9C28[][2];
void func_021B9840(void)
{
    unsigned i;
    func_020434DC(1, 1);
    *(volatile u16 *)0x04000008 = *(volatile u16 *)0x04000008 & ~3;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3002) | 2;
    *(volatile u16 *)0x04000060 &= (u16)~0x3010;
    *(volatile u16 *)0x04000060 &= (u16)~0x3004;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 8;
    *(volatile u16 *)0x04000060 &= (u16)~0x3020;
    func_0207DC44(0, 0, 0, 0);
    func_0207DD24(0, 0, 0x7fff, 0x3f, 0);
    *(volatile u32 *)0x04000580 = 0xbfff0000;
    for (i = 0; i < 4; i++)
        func_02046A94(i, d_021B9C28[i]);
    func_02046BE0(0, 0);
}
