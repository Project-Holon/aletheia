/*
 * function: func_02175110
 * address: 0x02175110
 * packet: pkt_ov012_02175110
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203D378 0x0203D378 arm
 *   func_02174D2C 0x02174D2C thumb ov012
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_0203D378(void);
extern int func_02174D2C(u8 *,int,int);
void func_02175110(u8 *p)
{
    int i;
    if (func_0203D378()) {
        for (i=0;i<4;i++) {
            if ((p+i)[0xd0] != 255 && func_02174D2C(p,i,(p+i)[0xd0]) == 1)
                (p+i)[0xd0] = 255;
        }
    }
}
