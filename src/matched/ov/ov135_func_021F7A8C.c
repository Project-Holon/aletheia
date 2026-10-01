/*
 * function: func_021F7A8C
 * address: 0x021F7A8C
 * packet: pkt_ov135_021F7A8C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F8950 0x021F8950 thumb ov135
 *   func_02202644 0x02202644 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_020452E8 0x020452E8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021F8950(void *p, u16 *old);
extern void func_0202020C(void *p, u16 *a, u16 *b);
extern void func_0201F868(void *p);
extern void func_02202644(void *p, int on);
extern void func_0201F7A8(void *p, unsigned kind);
extern void func_020452E8(void *p);
extern void func_021F4EC0(void *p, unsigned a, unsigned b);
extern void func_020061E4(unsigned se);
int func_021F7A8C(u8 *p)
{
    switch ((unsigned)func_021F8950(*(void **)(p + 0xDF4), (u16 *)(p + 0xBC))) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
        func_0202020C(*(void **)(p + 0xDF4), (u16 *)(*(u8 **)(p + 0xE00) + 6), (u16 *)(*(u8 **)(p + 0xE00) + 4));
        func_0201F868(*(void **)(p + 0xDE8));
        *(unsigned *)(p + 0x28) = 5;
        func_020061E4(0x54C);
        break;
    case (unsigned)-2:
        func_0202020C(*(void **)(p + 0xDF4), (u16 *)(*(u8 **)(p + 0xE00) + 6), (u16 *)(*(u8 **)(p + 0xE00) + 4));
        func_0201F868(*(void **)(p + 0xDE8));
        func_02202644(*(void **)(p + 0xD50), 0);
        func_0201F7A8(*(void **)(p + 0xD40), 0);
        func_020452E8(*(void **)(p + 0xD50));
        func_020452E8(*(void **)(p + 0xD54));
        func_021F4EC0(p, 5, 5);
        *(unsigned *)(p + 0x28) = 2;
        func_020061E4(0x54C);
        break;
    case 0:
        break;
    }
    return 2;
}
