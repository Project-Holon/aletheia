/*
 * function: func_021BAFA0
 * address: 0x021BAFA0
 * packet: pkt_ov100_021BAFA0
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA5F4 0x021BA5F4 thumb ov100
 *   func_021B95C0 0x021B95C0 thumb ov100
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B96B8 0x021B96B8 thumb ov100
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BA5F4(int),func_021B95C0(int),func_021B95B8(u8 *,u32),func_021B96B8(int);
void func_021BAFA0(int p) {
    if(--*(int *)(p+0xcac)==0) {
        func_021BA5F4(p);
        func_021B95C0(p);
        func_021B95B8((u8 *)p,(u32)func_021B96B8);
    }
}
