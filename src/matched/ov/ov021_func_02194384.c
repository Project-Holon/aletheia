/*
 * function: FIELD_COMM_ACTOR_CTRL_SearchGridPos
 * address:  0x02194384
 * packet:   pkt_ov021_02194384
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb  ov010
 *   FLDMMDL_MOVE_IsGridInObjectRect  0x02163C04  thumb  ov010
 */
#include "../include/Obj07448.h"
#include "../include/Obj12622.h"

typedef unsigned short u16;
typedef short s16;

extern int FLDMMDL_GetGridNowY(void *p);
extern int FLDMMDL_MOVE_IsGridInObjectRect(int a, int x, int y, int flag);

int FIELD_COMM_ACTOR_CTRL_SearchGridPos(u16 *a, s16 b, int c, s16 d, int *e, unsigned *f)
{
    unsigned n = *a;
    unsigned char *q;
    short dlt;

    if (*f < n) {
        q = *(unsigned char * *)&((struct Obj12622 *)a)->f8 + *f * 0xc;
        do {
            (*f)++;
            if (((struct Obj07448 *)q)->f8 != 0) {
                dlt = FLDMMDL_GetGridNowY(((struct Obj07448 *)q)->f8) - c;
                if (dlt < 0)
                    dlt = -dlt;
                if (dlt < 1) {
                    if (FLDMMDL_MOVE_IsGridInObjectRect((int)(((struct Obj07448 *)q)->f8), b, d, 1)) {
                        *e = ((struct Obj07448 *)q)->f0;
                        return 1;
                    }
                }
                q += 0xc;
            }
        } while (*f < n);
    }
    return 0;
}
