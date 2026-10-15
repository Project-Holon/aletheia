/*
 * function: BR_BTN_AnimMove
 * address: 0x021FAFD0
 * packet: pkt_ov186_021FAFD0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021FB056..021FB058 is two zero alignment bytes.
 * symbols:
 *   BR_BTN_GetPos 0x021FAEE4 thumb ov186
 *   BR_BTN_GetObjectPos 0x021FB548 thumb ov186
 *   BR_BTN_SetObjectPos 0x021FB514 thumb ov186
 */
#include "../include/Obj01280.h"
extern void BR_BTN_GetPos(char *, int *);
extern void BR_BTN_GetObjectPos(char *p, short *x, short *y);
extern void BR_BTN_SetObjectPos(char *p, short x, int y);
int BR_BTN_AnimMove(char *ctx)
{
    int position[2];
    short x;
    short value;
    switch (((struct Obj01280 *)ctx)->f1C) {
    case 0:
        BR_BTN_GetPos(ctx, position);
        ((struct Obj01280 *)ctx)->f20 = position[1];
        ((struct Obj01280 *)ctx)->f22 = ((struct Obj01280 *)ctx)->f18;
        ((struct Obj01280 *)ctx)->f24 = 0;
        ((struct Obj01280 *)ctx)->f26 = 10;
        ((struct Obj01280 *)ctx)->f1C = 1;
        break;
    case 1:
        value = ((struct Obj01280 *)ctx)->f20 + ((((struct Obj01280 *)ctx)->f22 - ((struct Obj01280 *)ctx)->f20) * ((struct Obj01280 *)ctx)->f24) / ((struct Obj01280 *)ctx)->f26;
        BR_BTN_GetObjectPos(((struct Obj01280 *)ctx)->f8, &x, 0);
        BR_BTN_SetObjectPos(((struct Obj01280 *)ctx)->f8, x, value);
        if ((((struct Obj01280 *)ctx)->f24)++ >= ((struct Obj01280 *)ctx)->f26) ((struct Obj01280 *)ctx)->f1C = 2;
        break;
    case 2: return 1;
    }
    return 0;
}
