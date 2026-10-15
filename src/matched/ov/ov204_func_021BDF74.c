/*
 * function: INTRO_GRAPHIC_DeleteClact
 * address:  0x021BDF74
 * packet:   pkt_021BDF74
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_ExitSystem  0x0204A5AC  arm  arm9
 *   CLACT_DeleteUnit  0x0204B1CC  arm  arm9
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25335.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void MI_CpuFill8(u8 *, u32, u32);

void INTRO_GRAPHIC_DeleteClact(u8 *p)
{
    CLACT_DeleteUnit((struct Bank *)(((struct Obj25335 *)p)->f0));
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 4);
}

