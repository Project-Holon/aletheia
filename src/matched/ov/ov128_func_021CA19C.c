/*
 * function: func_021CA19C
 * address: 0x021CA19C
 * packet: pkt_ov128_021CA19C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero padding at 021CA1DE; next labelled function 021CA1E0.
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   func_021CA124 0x021CA124 thumb ov128
 */
typedef unsigned char u8;
extern u8 func_020355C4(void);
extern void func_021CA124(int,int);
void func_021CA19C(unsigned *p)
{
    unsigned i;
    if(func_020355C4()==1) {
        for(i=0;i<3;i++) func_021CA124(i,1);
        return;
    }
    for(i=0;i<3;i++) {
        if(i==*p) func_021CA124(i,3);
        else func_021CA124(i,1);
    }
}
