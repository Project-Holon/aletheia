/*
 * function: func_021B9B60
 * address: 0x021B9B60
 * packet: pkt_ov093_021B9B60
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT* (2 bytes alignment padding)
 * symbols:
 *   func_021D5B7C 0x021D5B7C thumb ov093
 *   func_021B9C24 0x021B9C24 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021D5B7C(void *);
extern void func_021B9C24(void *,u8);
void func_021B9B60(u8 *p) {
    unsigned int j;
    int i;
    j=0;
    i=0;
    for(;j<p[24];j++) {
        if(func_021D5B7C(*(void **)((u32)p+(u32)i*4))) i++;
        else func_021B9C24(p,i);
    }
}
