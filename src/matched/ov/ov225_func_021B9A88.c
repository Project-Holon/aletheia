/*
 * function: func_021B9A88
 * address: 0x021B9A88
 * packet: pkt_ov225_021B9A88
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: u8 callee parameter follows original explicit low-byte truncation.
 * symbols:
 *   d_021BBE4C 0x021BBE4C data a4
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern const u8 d_021BBE4C[];
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern void func_02082BCC(void *, u32, u32);
void func_021B9A88(void *p) {
    u32 i;
    for (i=0; i<4; i++) func_020403F4((u8)(*(const u32 *)(d_021BBE4C+i*44)));
    BMP_WIN_Exit();
    func_0203F9B4();
    func_02082BCC(p,0,4);
}
