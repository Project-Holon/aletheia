/*
 * function: INTRO_GRAPHIC_CreateDisplay
 * address: 0x021BDC18
 * packet: pkt_ov204_021BDC18
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0204363C is in src/matched/arm9/unit_0204361C.c but omitted
 *   from function:. Owner must list BG_SYS_ResetSubDisplay,BMP_SetDisplaySwap,BMP_GetVisiblePlane
 *   and regenerate its shard. Prior verified EXACT 28-byte ARM C copied
 *   from ov170_func_021E1E80.c (wave62 B4 blocker-1.log):
 *   typedef unsigned short u16; typedef unsigned int u32;
 *   void BMP_SetDisplaySwap(u32 swap) {
 *     *(volatile u16 *)0x04000304 =
 *       (*(volatile u16 *)0x04000304 & ~0x8000) | (swap << 15);
 *   }
 * blocker: ARM9 020434CC is in src/matched/arm9/unit_0204349C.c but omitted
 *   from function: together with its nested 020434B4. Prior verified MATCH
 *   16-byte ARM C copied from ov133_func_021B69AC.c:
 *   extern void BG_SYS_ClearMainBgPlanes(void),BG_SYS_ClearMainObjPlane(void);
 *   void BG_SYS_ClearMainPlanes(void) { BG_SYS_ClearMainBgPlanes(); BG_SYS_ClearMainObjPlane(); }
 * blocker: ARM9 02043588 is in src/matched/arm9/unit_02043570.c but omitted
 *   from function:. Prior verified EXACT 16-byte ARM C copied from
 *   ov133_func_021B69AC.c:
 *   extern void BG_SYS_ClearSubBgPlanes(void),BG_SYS_ClearSubObjPlane(void);
 *   void BG_SYS_ClearSubPlanes(void) { BG_SYS_ClearSubBgPlanes(); BG_SYS_ClearSubObjPlane(); }
 * tu: --suggest-split MATCH216, sole function OUT, no viable partition.
 * volatile: hardware 0x04000050/0x04001050 writes; 0x04000000 at 021BDC48 and 0x04001000 at 021BDC52 are read-modify-written.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   INTRO_GRAPHIC_InitBg7 0x021BDE30 thumb ov204
 *   INTRO_GRAPHIC_InitBg 0x021BDD98 thumb ov204
 *   INTRO_GRAPHIC_InitClact 0x021BDF34 thumb ov204
 *   INTRO_GRAPHIC_InitCamera7 0x021BE03C thumb ov204
 *   INTRO_GRAPHIC_InitCamera 0x021BDFA4 thumb ov204
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   INTRO_GRAPHIC_VBlank 0x021BDD84 thumb ov204
 *   gIntroGraphicSite 0x021C09C0 data a4
 *   d_021BFE4C 0x021BFE4C data a4
 *   d_021BFE1C 0x021BFE1C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct DispVram;
extern const struct DispVram d_021BFE4C,d_021BFE1C;
extern const char gIntroGraphicSite[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void MI_CpuFill8(void *,u8,u32);
extern void BG_SYS_ClearGraphicsMemory(u32);
extern void BMP_SetDisplaySwap(u32);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
extern void INTRO_GRAPHIC_InitBg7(void *,u16);
extern void INTRO_GRAPHIC_InitBg(void *,u32);
extern void INTRO_GRAPHIC_InitClact(u8 *,int,int);
extern void INTRO_GRAPHIC_InitCamera7(void *,u32);
extern void INTRO_GRAPHIC_InitCamera(void *,u32);
extern void GF_FONT_InitTextColor(void);
extern void *func_020056A0(u32,u32,u32);
extern void INTRO_GRAPHIC_VBlank(u32,u8 *);
void *INTRO_GRAPHIC_CreateDisplay(int swap, int mode, u16 heap)
{
    u8 *p;
    p=func_02030734(heap,20,0,gIntroGraphicSite,406);
    MI_CpuFill8(p,0,20);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &=0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &=0xFFFF1FFF;
    BG_SYS_ClearGraphicsMemory(0);
    BMP_SetDisplaySwap(swap);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    if (mode==7) {
        BG_SYS_SetVramBanks(&d_021BFE4C);
        INTRO_GRAPHIC_InitBg7(p,heap);
        INTRO_GRAPHIC_InitClact(p+4,(u32)&d_021BFE1C,heap);
        INTRO_GRAPHIC_InitCamera7(p+8,heap);
    } else {
        BG_SYS_SetVramBanks(&d_021BFE1C);
        INTRO_GRAPHIC_InitBg(p,heap);
        INTRO_GRAPHIC_InitClact(p+4,(u32)&d_021BFE1C,heap);
        INTRO_GRAPHIC_InitCamera(p+8,heap);
    }
    GF_FONT_InitTextColor();
    *(void **)(p+16)=func_020056A0((u32)INTRO_GRAPHIC_VBlank,(u32)p,0);
    return p;
}
