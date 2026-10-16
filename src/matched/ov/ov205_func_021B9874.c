/*
 * function: SAVE_SCREEN_Setup
 * address: 0x021B9874
 * packet: pkt_ov205_021B9874
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0204363C is inside src/matched/arm9/unit_0204361C.c but omitted from function:. Owner must list BG_SYS_ResetSubDisplay,BG_SYS_SetLcdSwap,BG_SYS_GetMainVisiblePlanes and regenerate its shard. tu --suggest-split leaves this caller out.
 * blocker: verified EXACT 28-byte ARM C copied from ov204_func_021BDC18.c, which cites wave62 B4 blocker-1.log:
 *   typedef unsigned short u16; typedef unsigned int u32;
 *   void BG_SYS_SetLcdSwap(u32 swap) {
 *     *(volatile u16 *)0x04000304 =
 *       (*(volatile u16 *)0x04000304 & ~0x8000) | (swap << 15);
 *   }
 * symbols:
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   func_0208068C 0x0208068C arm
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   GX_DisableBankForLCDC 0x02080B98 arm
 *   SAVE_SCREEN_SetupBackground 0x021B9970 thumb ov205
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02049B40 0x02049B40 arm
 *   func_02045B38 0x02045B38 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   TCBL_Create 0x0203101C arm
 *   STRBUF_Create 0x020457B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct GfFont;struct MsgBank;struct WordSet;struct Tcbl;struct U16Vec;
extern void BG_SYS_SetLcdSwap(u32);extern void func_0208068C(u32);extern void MIi_CpuClearFast(u32,u32,u32);extern void GX_DisableBankForLCDC(void);extern void SAVE_SCREEN_SetupBackground(u16);
extern struct GfFont *GF_FONT_Create(int,int,int,int,u32);extern void func_02049B40(u32,u32,u32,u32,u32,u16);extern struct MsgBank *func_02045B38(u32,u32,u32,u32);extern struct WordSet *WORDSET_CreateDefault(u32);extern void BMP_MENUWORK_LoadCharAndPltt(u32,u32,u32,u32,u16);extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);extern struct Tcbl *TCBL_Create(u32,u16,u32,u32);extern struct U16Vec *STRBUF_Create(u32,u32);
void SAVE_SCREEN_Setup(char *p, const char *a1) { BG_SYS_SetLcdSwap(1);func_0208068C(511);MIi_CpuClearFast(0,0x6800000,0xa4000);GX_DisableBankForLCDC();SAVE_SCREEN_SetupBackground(*(u16 *)p);*(struct GfFont **)(p+0x10)=GF_FONT_Create(23,0,0,0,*(u16 *)p);func_02049B40(23,5,0,416,32,*(u16 *)p);*(struct MsgBank **)(p+0x14)=func_02045B38(0,2,*(u16 *)(p+2),*(u16 *)p);*(struct WordSet **)(p+0x18)=WORDSET_CreateDefault(*(u16 *)p);BMP_MENUWORK_LoadCharAndPltt(0,1,12,0,*(u16 *)p);*(u32 *)(p+0x1c)=BMP_WIN_Create(0,2,18,27,4,13,1);*(struct Tcbl **)(p+0x24)=TCBL_Create(*(u16 *)p,*(u16 *)p,10,32);*(struct U16Vec **)(p+12)=STRBUF_Create(1024,*(u16 *)p); }
