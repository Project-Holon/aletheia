/*
 * function: func_021B9F84
 * address: 0x021B9F84
 * packet: pkt_ov093_021B9F84
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9F70 0x021B9F70 thumb ov093
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B9F70(char *,int);
u16 func_021B9F84(char *p,int i,unsigned int j) {
    char *q;
    if(func_021B9F70(p,i)) {
        q=(char *)((u32)p+32+(u32)i*40);
        if(j<4) return *(u16 *)((u32)q+16+j*2);
    }
    return 0;
}
