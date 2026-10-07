/*
 * file:     worldtrade_enter_p05.c
 * unit:     yes
 * function: func_021F8E58, func_021F8E88, func_021F8F5C, func_021F8F68, func_021F8F84
 * address:  0x021F8E58
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F4EC0  0x021F4EC0  thumb  ov135
 *   func_021F8A74 0x021F8A74 thumb ov135
 *   func_021F8A80 0x021F8A80 thumb ov135
 *   func_021F8AB0 0x021F8AB0 thumb ov135
 *   func_021F8AF4 0x021F8AF4 thumb ov135
 *   func_021F8B0C 0x021F8B0C thumb ov135
 *   func_021F8BBC 0x021F8BBC thumb ov135
 *   func_021F8BE8 0x021F8BE8 thumb ov135
 *   func_021F9024 0x021F9024 thumb ov135
 *   func_021F4FC4  0x021F4FC4  thumb  ov135
 *   func_021D5B5C 0x021D5B5C thumb ov115
 */
#include "../../matched/include/Obj09233.h"
#include "../../matched/include/Obj01743.h"
#include "../../matched/include/Obj12205.h"
#include "../../matched/include/Obj10580.h"

struct MsgBank;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef signed short s16;

extern u32 func_020307B0(void *p);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern int func_021F8A74(void *a0);
extern int func_021F8A80(u8 *);
extern int func_021F8AB0(u8 **);
extern int func_021F8AF4(u8 *);
extern int func_021F8B0C(u8 *);
extern int func_021F8BBC(u8 *);
extern int func_021F8BE8(u8 *);
extern int func_021F9024(u8 *, void *);
extern void func_021C8658(u8 *p);
extern void func_021F4FC4(u8 *p);
extern void func_021D5B5C(char *p, struct MsgBank *a, int b);
int func_021F8E58(u8 *p);
int func_021F8E88(void *dialog, u8 *p);
u32 func_021F8F5C(u8 *p);
int func_021F8F68(u8 *p);
int func_021F8F84(u8 *p, void *dialog);


int func_021F8E58(u8 *p)
{
    if (((struct Obj09233 *)p)->f12F4 == 0) {
        func_020307B0((void *)(((struct Obj09233 *)p)->f10DC));
        func_021F4EC0(p, 0, 0);
        ((struct Obj09233 *)p)->f28 = 1;
    }
    return 2;
}

int func_021F8E88(void *dialog, u8 *p)
{
    int result;
    switch (((struct Obj01743 *)p)->f12EC) {
    case 0:
        if (func_021F8A74(p))
            (((struct Obj01743 *)p)->f12EC)++;
        break;
    case 1:
        result = func_021F8A80(p);
        switch (result) {
        case 1: (((struct Obj01743 *)p)->f12EC)++; break;
        case 2: ((struct Obj01743 *)p)->f12EC = 9; break;
        }
        break;
    case 2:
        if (func_021F8AB0((u8 **)p)) (((struct Obj01743 *)p)->f12EC)++;
        break;
    case 3:
        if (func_021F8AF4(p)) (((struct Obj01743 *)p)->f12EC)++;
        break;
    case 4:
        result = func_021F8B0C(p);
        switch (result) {
        case 1: (((struct Obj01743 *)p)->f12EC)++; break;
        case 2: ((struct Obj01743 *)p)->f12EC = 7; break;
        }
        break;
    case 5:
        if (func_021F8BBC(p)) (((struct Obj01743 *)p)->f12EC)++;
        break;
    case 6:
        result = func_021F8BE8(p);
        switch (result) {
        case 1: ((struct Obj01743 *)p)->f12EC = 0; return 0;
        case 2: ((struct Obj01743 *)p)->f12EC = 7; break;
        }
        break;
    case 7:
        if (func_021F8F84(p, dialog)) (((struct Obj01743 *)p)->f12EC)++;
        break;
    case 8:
        if (func_021F9024(p, dialog)) (((struct Obj01743 *)p)->f12EC)++;
        break;
    case 9:
        ((struct Obj01743 *)p)->f12EC = 0;
        return 1;
    }
    return 2;
}


/*
 * Every concrete byte is reproduced.  The one wildcard is the BLX at +0002 to
 * func_021C8658, which has no independent witness outside 021F8F5C..021F8F66;
 * the resolver reports "(arm, from name) ... 8 overlays overlap this address
 * (ov016, ov021, ov093, ov111, ov114, ov128, ov172, ov208), none resolvable
 * without a region hint on the symbols: line".  Same blocker as func_02201FDC
 * and func_021FEB84/func_02201C88: naming one of those eight regions would be
 * a guess, so the site stays parked until the region that owns 0x021C8658 is
 * established.
 */
u32 func_021F8F5C(u8 *p)
{
    func_021C8658(p);
    return 0;
}


/*
 * Reset the object, latch state 0 and set the +0xeb4 slot to 1.
 */
int func_021F8F68(u8 *p)
{
    func_021F4FC4(p);
    ((struct Obj12205 *)p)->f28 = 0;
    ((struct Obj12205 *)p)->fEB4 = 1;
    return 3;
}

int func_021F8F84(u8 *p, void *dialog)
{
    int text;
    switch (((struct Obj10580 *)p)->f38) {
    case 1: text = 166; break;
    case 2: text = 167; break;
    case -1: text = 157; break;
    case -2: text = 169; break;
    case -3: text = 162; break;
    case -4: text = 164; break;
    case -5: text = 163; break;
    case -6: text = 27; break;
    case -7: text = 28; break;
    case -8: text = 29; break;
    case -9: text = 30; break;
    case -10: text = 31; break;
    case -11: text = 32; break;
    case -12: text = 160; break;
    case -13: text = 165; break;
    case -14: text = 170; break;
    case -15: text = 161; break;
    default: text = 159; break;
    }
    func_021D5B5C(dialog, ((struct Obj10580 *)p)->fB6C, text);
    ((struct Obj10580 *)p)->fF88 = 0;
    return 1;
}
