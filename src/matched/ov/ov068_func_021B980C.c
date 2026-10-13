/*
 * function: OPTION_MENU_Main
 * address:  0x021B980C
 * packet:   pkt_ov068_021B980C
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   OPTION_MENU_UpdateRunner  0x021BB120  thumb
 *   OPTION_MENU_UpdateScreen  0x021B9930  thumb
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   TCBL_Main  0x020310C4  arm
 *   OPTION_MENU_UpdateButtonWindows  0x021BA644  thumb
 *   OPTION_MENU_IsRunnerFinished  0x021BB134  thumb
 */
#include "../include/Obj13137.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct PrintSys;
struct Tcbl;
extern void OPTION_MENU_UpdateRunner(u8 *p);
extern void OPTION_MENU_UpdateScreen(u8 *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void TCBL_Main(struct Tcbl *p);
extern void OPTION_MENU_UpdateButtonWindows(u8 *p);
extern int OPTION_MENU_IsRunnerFinished(void *p);

int OPTION_MENU_Main(u32 a, u32 b, u32 c, u8 *w)
{
    OPTION_MENU_UpdateRunner(w + 0xd4);
    OPTION_MENU_UpdateScreen(w);
    PRINTSYS_QUE_Main(((struct Obj13137 *)w)->f258);
    TCBL_Main(((struct Obj13137 *)w)->f268);
    OPTION_MENU_UpdateButtonWindows(w + 0x104);
    if (OPTION_MENU_IsRunnerFinished(w + 0xd4) != 0)
        return 1;
    return 0;
}
