/*
 * function: func_022020F8
 * address: 0x022020F8
 * packet: pkt_ov135_022020F8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021F4FC4 0x021F4FC4 thumb ov135
 *   func_021F90A0 0x021F90A0 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_020120F4(void *);
extern int func_02012DD0(void *);
extern void func_021F4EC0(void *, unsigned, unsigned);
extern void func_021F4FC4(void *);
extern void func_021F90A0(void *, void *, unsigned, unsigned, u16);
extern void func_021F4E98(void *, unsigned, unsigned);
int func_022020F8(u8 *p)
{
    if (func_02012DD0(func_020120F4(*(void **)(*(u8 **)p + 0x40))) == 2) {
        func_021F4EC0(p, 1, 0);
        func_021F4FC4(p);
        func_021F90A0(p, *(void **)(p + 0xB6C), *(unsigned *)(p + 0x24), 1, 0xF0F);
        func_021F4E98(p, 0x2A, 0x20);
    }
    return 2;
}
