/*
 * function: func_021F7268
 * address: 0x021F7268
 * packet: pkt_ov135_021F7268
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 0x021F72AC writes hardware halfword 0x04000050.
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_021F5074 0x021F5074 thumb ov135
 *   func_021F4EC8 0x021F4EC8 thumb ov135
 */
typedef unsigned char u8;
extern void func_020307B0(void *p);
extern void func_021F5074(void *p);
extern void func_021F4EC8(void *p);
int func_021F7268(u8 *p)
{
    if (*(void **)(p + 0xD8)) {
        func_020307B0(*(void **)(p + 0xD8));
        *(void **)(p + 0xD8) = 0;
    }
    func_020307B0(*(void **)(p + 0xEA4));
    if (*(void **)(p + 0x10DC)) {
        func_020307B0(*(void **)(p + 0x10DC));
        *(void **)(p + 0x10DC) = 0;
    }
    *(unsigned *)(p + 0x12F8) = 0;
    func_021F5074(p);
    func_021F4EC8(p);
    *(volatile unsigned short *)0x04000050 = 0;
    return 0;
}
