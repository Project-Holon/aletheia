/*
 * function: func_021FD698
 * address: 0x021FD698
 * packet: pkt_ov135_021FD698
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021FD6B0 reads hardware register 04000304.
 * symbols:
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char  u8;
extern u32 func_020221A4(void);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
int func_021FD698(unsigned char *p)
{
    --*(int *)(p + 0xd3c);
    if (func_020221A4()) {
        *(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000);
        *(int *)(p + 0x28) = 2;
        func_021F4EC0(p, 4, 15);
        *(int *)(p + 0xd3c) = 16;
    }
    return 2;
}
