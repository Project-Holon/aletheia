/*
 * function: func_0220BD34
 * address: 0x0220BD34
 * packet: pkt_ov198_0220BD34
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020450F0 0x020450F0 arm
 */
typedef unsigned char u8;
typedef struct Bits { unsigned char low:5; unsigned char high:3; } Bits;
extern void *func_020450F0(int,int,int,int,u8,u8,u8);
void func_0220BD34(u8 *p)
{
    if (((Bits *)(p+0x2175))->low == 1)
        *(void **)(p+0x2170)=func_020450F0(5,0,0,32,16,0,1);
    ((Bits *)(p+0x2175))->low ^= 1;
}
