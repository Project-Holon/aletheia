/*
 * function: func_021B9ACC
 * address: 0x021B9ACC
 * packet: pkt_ov224_021B9ACC
 * region: ov224
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: u8 callee parameter follows original explicit low-byte truncation.
 * symbols:
 *   d_021B9CD0 0x021B9CD0 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern const u8 d_021B9CD0[];
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02082BCC(void *, u32, u32);
void func_021B9ACC(void *p) {
    u32 i;
    for (i=0; i<2; i++) func_020403F4((u8)(*(const u32 *)(d_021B9CD0+i*44)));
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(p,0,4);
}
