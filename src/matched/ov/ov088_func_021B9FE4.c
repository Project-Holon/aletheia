/*
 * function: STARTMENU_MenuMain
 * address:  0x021B9FE4
 * packet:   pkt_ov088_021B9FE4
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TCBL_Main  0x020310C4  arm
 *   CLACT_DrawSystem  0x0204A600  arm
 *   gStartMenuStateTable     0x021BD63C  data  ov088  a4
 */
#include "../include/Obj13230.h"

typedef int (*StateFn)(char *);

struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
extern void CLACT_DrawSystem(void);
extern StateFn gStartMenuStateTable[];

int STARTMENU_MenuMain(int a0, int a1, int a2, char *p)
{
    int s = gStartMenuStateTable[*(int *)(p + 0x13c)](p);
    ((struct Obj13230 *)p)->f13C = s;
    if (s == 12) {
        return 1;
    }
    TCBL_Main((struct Tcbl *)(((struct Obj13230 *)p)->f70));
    CLACT_DrawSystem();
    return 0;
}
