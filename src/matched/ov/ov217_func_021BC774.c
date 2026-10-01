/*
 * function: func_021BC774
 * address: 0x021BC774
 * packet: pkt_ov217_021BC774
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent ends in two zero alignment bytes at 021BC816.
 * symbols:
 *   func_021BC94C 0x021BC94C thumb ov217
 *   func_021BC910 0x021BC910 thumb ov217
 *   func_021BC8D0 0x021BC8D0 thumb ov217
 *   func_021BCD6C 0x021BCD6C thumb ov217
 *   func_021BCF4C 0x021BCF4C thumb ov217
 *   func_021BCFB4 0x021BCFB4 thumb ov217
 *   func_021BCDDC 0x021BCDDC thumb ov217
 *   func_021BD474 0x021BD474 thumb ov217
 *   func_021BD078 0x021BD078 thumb ov217
 *   func_021BD50C 0x021BD50C thumb ov217
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_020056BC(void);
extern void func_021BC94C(void *);
extern void func_021BC910(void *);
extern void func_021BC8D0(void *);
extern void func_021BCD6C(void *);
extern void func_021BCF4C(void *);
extern void func_021BCFB4(void *);
extern void func_021BCDDC(void *);
extern void func_021BD474(void *);
extern void func_021BD078(void *);
extern void func_021BD50C(void *);
void func_021BC774(u8 *p)
{
    *(u32 *)(p + 4) = 0;
    *(u32 *)(p + 0x1C) = 0;
    *(u32 *)(p + 0x24) = 0;
    *(u32 *)(p + 0x158) = 0;
    *(u32 *)(p + 0x28) = 15;
    p[0x32] = 0;
    p[0x33] = 0;
    p[0x30] = 0;
    *(u32 *)(p + 0x2C) = 0;
    p[0x31] = 255;
    *(u32 *)(p + 0x150) = func_020056BC();
    *(u32 *)(p + 0x34) = 0;
    *(u32 *)(p + 0x38) = 0;
    *(u32 *)(p + 0x3C) = 0;
    *(u32 *)(p + 0x40) = 0;
    *(u32 *)(p + 0x44) = 0;
    *(u32 *)(p + 0x48) = 0;
    *(u32 *)(p + 0x15C) = 0;
    *(u32 *)(p + 0x160) = 0;
    *(u32 *)(p + 0x168) = 0;
    *(u32 *)(p + 0x164) = 0;
    *(u32 *)(p + 0x154) = 0;
    func_021BC94C(p);
    func_021BC910(p);
    func_021BC8D0(p);
    func_021BCD6C(p);
    func_021BCF4C(p);
    func_021BCFB4(p);
    func_021BCDDC(p);
    func_021BD474(p);
    func_021BD078(p);
    func_021BD50C(p);
}
