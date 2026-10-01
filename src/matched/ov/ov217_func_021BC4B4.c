/*
 * function: func_021BC4B4
 * address: 0x021BC4B4
 * packet: pkt_ov217_021BC4B4
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct PalAnmObj PalAnmObj;
extern int func_0202173C(PalAnmObj *, u16, u16, s16, u8, u8, u16, void *);
void func_021BC4B4(char *p)
{
    func_0202173C(*(PalAnmObj **)(p + 0x98), 1, 0xBBFF, 2, 0, 10, 0, *(void **)(p + 0x150));
    func_0202173C(*(PalAnmObj **)(p + 0x98), 4, 0xCF, 2, 0, 10, 0, *(void **)(p + 0x150));
    *(u32 *)(p + 0x15C) = 1;
}
