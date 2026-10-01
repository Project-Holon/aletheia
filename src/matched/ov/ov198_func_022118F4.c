/*
 * function: func_022118F4
 * address: 0x022118F4
 * packet: pkt_ov198_022118F4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: associate the index with the destination pointer before adding 0x48.
 * symbols:
 *   func_02210EFC 0x02210EFC thumb ov198
 *   func_022110D4 0x022110D4 thumb ov198
 */
typedef unsigned char u8;
extern unsigned func_02210EFC(unsigned);
extern int func_022110D4(u8 *,int);
void func_022118F4(u8 *p)
{
    unsigned i;
    if(func_02210EFC((unsigned)p)==1) {
        (*(u8 **)p)[0x48]=func_022110D4(p,(*(u8 **)p)[0x20]);
    } else {
        for(i=0;i<3;i++) {
            if(*(unsigned short *)(p+func_022110D4(p,i)*0x4c+0x14)==0) {
                ((*(u8 **)p)+i)[0x48]=(*(u8 **)p)[0x20];
                break;
            }
        }
    }
}
