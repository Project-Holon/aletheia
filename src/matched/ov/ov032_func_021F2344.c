/*
 * function: BEACON_VIEW_Update
 * address:  0x021F2344
 * packet:   pkt_ov032_021F2344
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BEACON_VIEW_Update 0x021F2344 thumb
 *   BEACON_VIEW_SetFadeState 0x021F0208 thumb ov032
 *   func_021F2544 0x021F2544 thumb ov032
 *   TCBL_Main 0x020310C4 arm
 *   func_021F2674 0x021F2674 thumb ov032
 *   func_021F26D8 0x021F26D8 thumb ov032
 *   func_021F26F0 0x021F26F0 thumb ov032
 *   func_021F2714 0x021F2714 thumb ov032
 *   func_021F27B4 0x021F27B4 thumb ov032
 *   func_021F27CC 0x021F27CC thumb ov032
 *   GAME_BEACON_ACCESSOR_TableAddNewLogs 0x02165888 thumb ov010
 */
#include "../include/Obj00007.h"

typedef unsigned char  u8;
extern void BEACON_VIEW_SetFadeState(u8 *p, int flag);
extern void func_021F2544(char *);
struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
extern int func_021F2674(char *);
extern int func_021F26D8(u8 *p);
extern int func_021F26F0(u8 *p);
extern int func_021F2714(char *);
extern int func_021F27B4(u8 *p);
extern int func_021F27CC(char *);
extern int GAME_BEACON_ACCESSOR_TableAddNewLogs(int a0);

void BEACON_VIEW_Update(char *p, int a1)
{
    int f;

    if (((struct Obj00007 *)p)->f60 != a1) {
        int c;

        if (((struct Obj00007 *)p)->f72 != 0 && a1 == 0) {
            c = 1;
        } else {
            c = 0;
        }
        if (c == 0) {
            f = 1;
            ((struct Obj00007 *)p)->f60 = a1;
            if (a1 != 0) {
                f = 0;
            }
            BEACON_VIEW_SetFadeState((u8 *)p, f);
        }
    }
    if (((struct Obj00007 *)p)->f70 != 0) {
        if (a1 == 0) {
            func_021F2544(p);
            return;
        }
        return;
    }
    if (a1 != 0) {
        TCBL_Main((struct Tcbl *)(*(int *)&((struct Obj00007 *)p)->fA0));
        switch (((struct Obj00007 *)p)->f68) {
        case 0:
            ((struct Obj00007 *)p)->f68 = func_021F2674(p);
            break;
        case 1:
            ((struct Obj00007 *)p)->f68 = func_021F26D8((u8 *)p);
            break;
        case 2:
            ((struct Obj00007 *)p)->f68 = func_021F26F0((u8 *)p);
            break;
        case 3:
            ((struct Obj00007 *)p)->f68 = func_021F2714(p);
            break;
        case 4:
            ((struct Obj00007 *)p)->f68 = func_021F27B4((u8 *)p);
            break;
        case 5:
            ((struct Obj00007 *)p)->f68 = func_021F27CC(p);
            break;
        case 6:
        case 7:
            break;
        }
        GAME_BEACON_ACCESSOR_TableAddNewLogs(((struct Obj00007 *)p)->f38);
    }
}
