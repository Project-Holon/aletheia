/*
 * function: SUBWAY_MAP_GRAPHIC_DeleteBg
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
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 *   BG_SYS_Delete  0x0203F9B4  arm  arm9
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern const u8 d_021B9CD0[];
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void MI_CpuFill8(void *, u32, u32);
void SUBWAY_MAP_GRAPHIC_DeleteBg(void *p) {
    u32 i;
    for (i=0; i<2; i++) func_020403F4((u8)(*(const u32 *)(d_021B9CD0+i*44)));
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(p,0,4);
}
