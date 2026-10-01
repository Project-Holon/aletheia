/*
 * function: func_02200AB4
 * address: 0x02200AB4
 * packet: pkt_ov135_02200AB4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049658 0x02049658 arm
 *   func_020499D4 0x020499D4 arm
 *   func_02049238 0x02049238 arm
 *   func_02049B40 0x02049B40 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32, u32);
extern void func_02049BDC(void *, u32, u32, u32, u32, u32, u32);
extern void func_02049658(void *, u32, u32, u32, u32, u32, u32);
extern u32 func_020499D4(void *, u32, u32, u32, u32, u32, u32, u16);
extern void func_02049238(void *);
extern void func_02049B40(u32, u32, u32, u32, u32, u32);
void func_02200AB4(u8 *p)
{
    void *h;
    if (*(u32 *)(p + 0x12e0) == 1 && *(u32 *)(p + 0x12e4) == 0) {
        h = func_020490F4(0x60, 0x48);
        func_02049BDC(h, 4, 4, 0x160, 0x160, 0xa0, 0x48);
        func_02049658(h, 0xe, 5, 0, 0x1c00, 0, 0x48);
        func_020499D4(h, 0x21, 5, 0, 0, 0, 0, 0x48);
        func_02049238(h);
        func_02049B40(0x17, 5, 4, 0x20, 0x20, 0x48);
    }
}
