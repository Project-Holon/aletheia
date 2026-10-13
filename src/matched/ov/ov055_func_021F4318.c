/*
 * function: CROWD_IsMmdlInFront
 * address:  0x021F4318
 * packet:   pkt_ov055_021F4318
 * region:   ov055
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_GetGridOldX  0x0216D804  thumb  ov010
 *   FLDMMDL_GetGridOldZ  0x0216D81C  thumb  ov010
 *   CROWD_IsTileInFront  0x021F4388  thumb  ov055
 */
#include "../include/Obj00204.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);
extern int FLDMMDL_GetGridOldX(void *p);
extern int FLDMMDL_GetGridOldZ(void *p);
extern int CROWD_IsTileInFront(int a, int b, int c, int d, u16 hi, u16 lo, u16 dir);

int CROWD_IsMmdlInFront(const u8 *a, void *b, u16 c, u16 d)
{
    int x0 = FLDMMDL_GetGridNowX(b);
    int y0 = FLDMMDL_GetGridNowZ(b);
    int x1 = FLDMMDL_GetGridNowX(*(void * const *)&((struct Obj00204 *)a)->fC);
    int y1 = FLDMMDL_GetGridNowZ(*(void * const *)&((struct Obj00204 *)a)->fC);
    int x2;
    int y2;

    if (CROWD_IsTileInFront(x1, y1, x0, y0, c, d, a[3])) {
        return 1;
    }
    x2 = FLDMMDL_GetGridOldX(b);
    y2 = FLDMMDL_GetGridOldZ(b);
    return CROWD_IsTileInFront(x1, y1, x2, y2, c, d, a[3]);
}
