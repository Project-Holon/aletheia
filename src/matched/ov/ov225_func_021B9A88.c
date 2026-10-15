/*
 * function: MANUAL_GRAPHIC_DeleteBg
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
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 *   BG_SYS_Delete  0x0203F9B4  arm  arm9
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern const u8 d_021BBE4C[];
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void MI_CpuFill8(void *, u32, u32);
void MANUAL_GRAPHIC_DeleteBg(void *p) {
    u32 i;
    for (i=0; i<4; i++) func_020403F4((u8)(*(const u32 *)(d_021BBE4C+i*44)));
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(p,0,4);
}
