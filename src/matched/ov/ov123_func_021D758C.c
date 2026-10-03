/*
 * function: func_021D758C
 * address: 0x021D758C
 * packet: pkt_ov123_021D758C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020090F8 0x020090F8 thumb
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D7560 0x021D7560 thumb ov123
 */
extern int func_02012EBC(int);
extern int func_02012E7C(int,int);
struct Sub02007324Ctrl;
extern void func_0200734C(struct Sub02007324Ctrl *,unsigned int);
extern int func_02009210(int);
extern void func_020090F8(int,unsigned char);
typedef unsigned char  u8;
extern void func_021D7560(u8 *p);
extern void func_021D6EE0(int,int,int);
void func_021D758C(int a)
{
    int b = func_02012EBC(*(int *)(a+0x2c));
    if(func_02012E7C(*(int *)(a+0x2c),4)==2) {
        func_0200734C((struct Sub02007324Ctrl *)b,4);
        func_020090F8(func_02009210(b),1);
        func_021D6EE0(a,(int)func_021D7560,0x333);
    }
}
