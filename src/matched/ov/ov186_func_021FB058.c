/*
 * function: BR_BTN_AnimMoveRow
 * address: 0x021FB058
 * packet: pkt_ov186_021FB058
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021FB0E6..021FB0E8 is two zero alignment bytes.
 * lever: load position[1] to a local before the target and step stores.
 * symbols:
 *   BR_BTN_GetPos 0x021FAEE4 thumb ov186
 *   BR_BTN_GetObjectPos 0x021FB548 thumb ov186
 *   BR_BTN_SetObjectPos 0x021FB514 thumb ov186
 *   BR_BTN_DATA_GetRowField 0x021FB7B0 thumb ov186
 */
#include "../include/Obj01281.h"
extern void BR_BTN_GetPos(char *, int *);
extern void BR_BTN_GetObjectPos(char *p, short *x, short *y);
extern void BR_BTN_SetObjectPos(char *p, short x, int y);
extern int BR_BTN_DATA_GetRowField(void *, int);
int BR_BTN_AnimMoveRow(char *ctx)
{
    int position[2];
    short x;
    short value;
    int target;
    int start;
    switch (((struct Obj01281 *)ctx)->f1C) {
    case 0:
        BR_BTN_GetPos(ctx, position);
        target = BR_BTN_DATA_GetRowField(((struct Obj01281 *)ctx)->fC, 1);
        start = position[1];
        ((struct Obj01281 *)ctx)->f22 = target;
        ((struct Obj01281 *)ctx)->f24 = 0;
        ((struct Obj01281 *)ctx)->f20 = start;
        ((struct Obj01281 *)ctx)->f26 = 16;
        ((struct Obj01281 *)ctx)->f1C = 1;
        break;
    case 1:
        value = ((struct Obj01281 *)ctx)->f20 + ((((struct Obj01281 *)ctx)->f22 - ((struct Obj01281 *)ctx)->f20) * ((struct Obj01281 *)ctx)->f24) / ((struct Obj01281 *)ctx)->f26;
        BR_BTN_GetObjectPos(((struct Obj01281 *)ctx)->f8, &x, 0);
        BR_BTN_SetObjectPos(((struct Obj01281 *)ctx)->f8, x, value);
        if ((((struct Obj01281 *)ctx)->f24)++ >= ((struct Obj01281 *)ctx)->f26) ((struct Obj01281 *)ctx)->f1C = 2;
        break;
    case 2: return 1;
    }
    return 0;
}
