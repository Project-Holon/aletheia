/*
 * function: WIFIBATTLEMATCH_GRAPHIC_Create
 * address: 0x021E5440
 * packet: pkt_ov177_021E5440
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021E5466,021E5468 hardware stores; 021E546C,021E5474 and 021E5476,021E547A hardware read-modify-write
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   WIFIBATTLEMATCH_GRAPHIC_InitBg 0x021E5568 thumb ov177
 *   WIFIBATTLEMATCH_GRAPHIC_InitClact 0x021E560C thumb ov177
 *   WIFIBATTLEMATCH_GRAPHIC_VBlank 0x021E5554 thumb ov177
 *   func_020056A0 0x020056A0 thumb
 *   d_021E8DA0 0x021E8DA0 data a1
 *   d_021E8B2C 0x021E8B2C data a4
 */
extern const char d_021E8DA0[];
extern const unsigned d_021E8B2C[];
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *, unsigned, unsigned);
extern void BG_SYS_ClearGraphicsMemory(unsigned);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BMP_SetDisplaySwap(unsigned);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern void WIFIBATTLEMATCH_GRAPHIC_InitBg(void *, int);
extern void WIFIBATTLEMATCH_GRAPHIC_InitClact(int *, int, int);
extern void WIFIBATTLEMATCH_GRAPHIC_VBlank(int, int *);
extern int func_020056A0(void (*)(int, int *), int *, int);
int *WIFIBATTLEMATCH_GRAPHIC_Create(unsigned swap, int heap)
{
    int *p = func_02030734(heap, 16, 0, d_021E8DA0, 0x1BB);
    MI_CpuFill8(p, 0, 16);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021E8B2C);
    BMP_SetDisplaySwap(swap);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    WIFIBATTLEMATCH_GRAPHIC_InitBg(p, heap);
    WIFIBATTLEMATCH_GRAPHIC_InitClact(p + 1, (int)d_021E8B2C, heap);
    p[3] = func_020056A0(WIFIBATTLEMATCH_GRAPHIC_VBlank, p, 0);
    return p;
}
