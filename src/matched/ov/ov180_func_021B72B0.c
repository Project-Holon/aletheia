/*
 * function: func_021B72B0
 * address: 0x021B72B0
 * packet: pkt_ov180_021B72B0
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B73E4 0x021B73E4 thumb ov180
 */
extern void func_021B73E4(char *,int,short,short);
int func_021B72B0(char *p,int i) {
    if(*(unsigned char *)(p+0x915f)==8) {
        func_021B73E4(p,i,*(short *)(p+0x9160),*(short *)(p+0x9162));
        return 0;
    }
    func_021B73E4(p,i,*(short *)(p+0x9160)+*(short *)(p+0x9164+*(unsigned char *)(p+0x915f)*2),*(short *)(p+0x9162)+*(short *)(p+0x9174+*(unsigned char *)(p+0x915f)*2));
    (*(unsigned char *)(p+0x915f))++;
    return 1;
}
