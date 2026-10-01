/*
 * function: func_0220B760
 * address: 0x0220B760
 * packet: pkt_ov198_0220B760
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02210B00 0x02210B00 thumb ov198
 */
typedef unsigned char u8;
typedef struct Bits { unsigned char low:4; unsigned char mode:3; unsigned char active:1; } Bits;
extern int func_02210B00(u8 *,unsigned int);
void func_0220B760(u8 *p,unsigned int state)
{
    ((Bits *)(p+0x1E9B))->mode=0;
    if (state<=5 && func_02210B00(p,state)==2) ((Bits *)(p+0x1E9B))->mode=1;
    p[0x1E98]=0;
    p[0x1E99]=0;
    p[0x1E9A]=state;
    ((Bits *)(p+0x1E9B))->active=1;
}
