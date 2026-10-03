/*
 * volatile: 021FF12E reads hardware register 04000304.
 * function: func_021FF118
 * address: 0x021FF118
 * packet: pkt_ov135_021FF118
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_020221A4(void);
extern void func_021F4EC0(void *, unsigned, unsigned);
extern void func_0204B3DC(unsigned, int);
int func_021FF118(char *p)
{
    ++*(int *)(p + 0xd3c);
    if (func_020221A4()) {
        *(volatile u16 *)0x04000304 |= 0x8000;
        *(int *)(p + 0xd3c) = -16;
        if (*(u16 *)(p + 0xe1a)) {
            *(int *)(p + 0x28) = 2;
            func_021F4EC0(p, 3, 16);
            *(int *)(p + 0xd4) = 0;
        }
        func_0204B3DC(*(unsigned *)(p + 0xd38), 0);
    }
    return 2;
}
