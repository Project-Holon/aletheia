/*
 * function: OPTION_MENU_InitButtons
 * address:  0x021BA37C
 * packet:   pkt_ov068_021BA37C
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The u16 stack parameter is re-read per call because both callees take it
 * as u16 (docs/idioms/a-u16-stack-parameter-reloaded-per-call-means-u16-callee-parameters.md).
 * Locals: the 64-byte table copy is declared before the 32-byte request so the
 * request sits at the lower address.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   TOUCHBAR_Create  0x021B62E0  thumb  ov067
 *   OPTION_MENU_CreateButtonWindows  0x021BA6B8  thumb  ov068
 *   GAME_DATA_ContainsRecentId  0x02012BF8  thumb
 *   TOUCHBAR_SetButtonToggled  0x021B6598  thumb  ov067
 *   gOptionMenuReturnButtonCells     0x021BB5D4  data  a4
 */
#include "../include/Obj02762.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 w[16]; } Tbl;
typedef struct { u32 w[8]; } Req;

extern void MI_CpuFill8(void *p, u32 a, u32 b);
extern u32  TOUCHBAR_Create(Req *r, u16 a);
extern void OPTION_MENU_CreateButtonWindows(u8 *p, u32 arg);
extern int GAME_DATA_ContainsRecentId(int a0, int a1);
extern void TOUCHBAR_SetButtonToggled(unsigned char *p, unsigned int id, unsigned int v);
extern Tbl  gOptionMenuReturnButtonCells;

void OPTION_MENU_InitButtons(u8 *p, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, u16 s3)
{
    Tbl t;
    Req r;

    MI_CpuFill8(p, 0, 0x44);
    ((struct Obj02762 *)p)->fC = 3;
    ((struct Obj02762 *)p)->f0 = a2;
    ((struct Obj02762 *)p)->f14 = s1;
    ((struct Obj02762 *)p)->f18 = s0;
    ((struct Obj02762 *)p)->f4 = a3;
    ((struct Obj02762 *)p)->f3C = s2;
    t = gOptionMenuReturnButtonCells;
    MI_CpuFill8(&r, 0, 0x20);
    r.w[0] = (u32)&t;
    r.w[1] = 2;
    r.w[2] = a1;
    r.w[5] = 8;
    r.w[7] = 1;
    r.w[6] = 2;
    ((struct Obj02762 *)p)->f8 = TOUCHBAR_Create(&r, s3);
    OPTION_MENU_CreateButtonWindows(p, s3);
    if (GAME_DATA_ContainsRecentId(((struct Obj02762 *)p)->f3C, 0x18) != 0) {
        TOUCHBAR_SetButtonToggled((unsigned char *)(((struct Obj02762 *)p)->f8), 6, 1);
    } else {
        TOUCHBAR_SetButtonToggled((unsigned char *)(((struct Obj02762 *)p)->f8), 6, 0);
    }
}
