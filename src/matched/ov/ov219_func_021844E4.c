/*
 * function: func_021844E4
 * address: 0x021844E4
 * packet: pkt_ov219_021844E4
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 82AC0 SDK asm source reads r0 fill/r1 destination/r2 size;
 * preserve all three observed inputs despite legacy asm void(void).
 * symbols:
 *   func_0208068C 0x0208068C arm
 *   func_02082AC0 0x02082AC0 arm
 *   func_02080B98 0x02080B98 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   d_02185F4C 0x02185F4C data ov219 a4
 */
typedef enum {GX_VRAM_NONE=0} GXVRam;
typedef enum {GX_OBJVRAMMODE_CHAR_2D=0,GX_OBJVRAMMODE_CHAR_1D_32K=0x10,GX_OBJVRAMMODE_CHAR_1D_64K=0x100010,GX_OBJVRAMMODE_CHAR_1D_128K=0x200010,GX_OBJVRAMMODE_CHAR_1D_256K=0x300010} GXOBJVRamModeChar;
struct DispVram {GXVRam main_bg,main_bg_expltt,sub_bg,sub_bg_expltt,main_obj,main_obj_expltt,sub_obj,sub_obj_expltt,teximage,texpltt;GXOBJVRamModeChar main_mapping,sub_mapping;};
extern const struct DispVram d_02185F4C;
extern void func_0208068C(unsigned),func_02082AC0(unsigned,void *,unsigned),func_02080B98(void);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
void func_021844E4(void)
{
    struct DispVram cfg=d_02185F4C;
    func_0208068C(0x1ff);
    func_02082AC0(0,(void *)0x06800000,0xa4000);func_02080B98();
    func_02082AC0(0xc0,(void *)0x07000000,0x400);
    func_02082AC0(0,(void *)0x05000000,0x400);
    func_02082AC0(0xc0,(void *)0x07000400,0x400);
    func_02082AC0(0,(void *)0x05000400,0x400);
    BG_SYS_SetVramBanks(&cfg);
}
