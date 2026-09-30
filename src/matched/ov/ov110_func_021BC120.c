/*
 * function: func_021BC120
 * address: 0x021BC120
 * packet: pkt_ov110_021BC120
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF6D8 0x021BF6D8 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned func_021BF6D8(u8 *);
void func_021BC120(u8 *p)
{
    switch (func_021BF6D8(*(u8 **)(p+4))) {
    case 0: *(u16 *)(p+0x38)=104; *(u16 *)(p+0x3a)=16; *(int *)(p+0x44)=1; break;
    case 1: *(u16 *)(p+0x38)=48; *(u16 *)(p+0x3a)=16; *(u16 *)(p+0x3c)=160; *(u16 *)(p+0x3e)=16; *(int *)(p+0x44)=2; break;
    case 2: *(int *)(p+0x44)=0; break;
    }
}
