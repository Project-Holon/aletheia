/*
 * function: UN_SELECT_GRAPHIC_Create
 * address: 0x021BA848
 * packet: pkt_ov218_021BA848
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: BLDCNT04000050/04001050 writes A870-A872; DISPCNT04000000/04001000 reread and masked A876-A884.
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
 *   UN_SELECT_GRAPHIC_SetupBg 0x021BA980 thumb ov218
 *   UN_SELECT_GRAPHIC_SetupClact 0x021BAA24 thumb ov218
 *   UN_SELECT_GRAPHIC_SetupCamera 0x021BAA94 thumb ov218
 *   UN_SELECT_GRAPHIC_Task 0x021BA96C thumb ov218
 *   func_020056A0 0x020056A0 thumb
 *   d_021BB094 0x021BB094 data a1
 *   d_021BAEF8 0x021BAEF8 data a4
 */
#include "../include/Obj26049.h"
struct DispVram;
extern const struct DispVram d_021BAEF8;
extern const char d_021BB094[];
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern void MI_CpuFill8(void *, int, int);
extern void BG_SYS_ClearGraphicsMemory(unsigned);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
extern void BMP_SetDisplaySwap(unsigned);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern void UN_SELECT_GRAPHIC_SetupBg(char *, unsigned);
extern void UN_SELECT_GRAPHIC_SetupClact(unsigned char *, int, int);
extern void UN_SELECT_GRAPHIC_SetupCamera(unsigned **, unsigned);
extern void UN_SELECT_GRAPHIC_Task(void *, char *);
extern void *func_020056A0(unsigned, unsigned, unsigned);
char *UN_SELECT_GRAPHIC_Create(unsigned swap, unsigned heap)
{
    char *p;
    p = func_02030734(heap, 16, 0, d_021BB094, 436);
    MI_CpuFill8(p, 0, 16);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000u;
    *(volatile unsigned *)0x04001000 &= ~0xe000u;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks(&d_021BAEF8);
    BMP_SetDisplaySwap(swap);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    UN_SELECT_GRAPHIC_SetupBg(p, heap);
    UN_SELECT_GRAPHIC_SetupClact((unsigned char *)(p + 4), (int)&d_021BAEF8, heap);
    UN_SELECT_GRAPHIC_SetupCamera((unsigned **)(p + 8), heap);
    ((struct Obj26049 *)p)->fC = func_020056A0((unsigned)UN_SELECT_GRAPHIC_Task, (unsigned)p, 0);
    return p;
}
