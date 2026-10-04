/*
 * function: func_021FB058
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
 *   func_021FAEE4 0x021FAEE4 thumb ov186
 *   func_021FB548 0x021FB548 thumb ov186
 *   func_021FB514 0x021FB514 thumb ov186
 *   func_021FB7B0 0x021FB7B0 thumb ov186
 */
#include "../include/Obj01281.h"
extern void func_021FAEE4(char *, int *);
extern void func_021FB548(char *p, short *x, short *y);
extern void func_021FB514(char *p, short x, short y);
extern int func_021FB7B0(void *, int);
int func_021FB058(char *ctx)
{
    int position[2];
    short x;
    short value;
    int target;
    int start;
    switch (((struct Obj01281 *)ctx)->f1C) {
    case 0:
        func_021FAEE4(ctx, position);
        target = func_021FB7B0(((struct Obj01281 *)ctx)->fC, 1);
        start = position[1];
        ((struct Obj01281 *)ctx)->f22 = target;
        ((struct Obj01281 *)ctx)->f24 = 0;
        ((struct Obj01281 *)ctx)->f20 = start;
        ((struct Obj01281 *)ctx)->f26 = 16;
        ((struct Obj01281 *)ctx)->f1C = 1;
        break;
    case 1:
        value = ((struct Obj01281 *)ctx)->f20 + ((((struct Obj01281 *)ctx)->f22 - ((struct Obj01281 *)ctx)->f20) * ((struct Obj01281 *)ctx)->f24) / ((struct Obj01281 *)ctx)->f26;
        func_021FB548(((struct Obj01281 *)ctx)->f8, &x, 0);
        func_021FB514(((struct Obj01281 *)ctx)->f8, x, value);
        if ((((struct Obj01281 *)ctx)->f24)++ >= ((struct Obj01281 *)ctx)->f26) ((struct Obj01281 *)ctx)->f1C = 2;
        break;
    case 2: return 1;
    }
    return 0;
}
