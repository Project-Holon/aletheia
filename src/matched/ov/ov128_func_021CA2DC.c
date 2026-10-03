/*
 * function: func_021CA2DC
 * address: 0x021CA2DC
 * packet: pkt_ov128_021CA2DC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   func_021CA25C 0x021CA25C thumb ov128
 * Extent ends with two bytes of zero alignment padding.
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 func_020355C4(void);
extern void func_021CA25C(u32 a, u32 b);
void func_021CA2DC(char *p)  {
    unsigned i;
    if(func_020355C4()==1)  {
        for(i=0;i<8;i++) func_021CA25C(i,1);
    }
    else  {
        for(i=0;i<8;i++)  {
            if(i==*(short *)(p+4)) func_021CA25C(i,3);
            else func_021CA25C(i,1);
        }
    }
}
