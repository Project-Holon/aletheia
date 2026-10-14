/*
 * function: WORLDTRADE_ENTER_ShowErrorMessage
 * address: 0x021F8F84
 * packet: pkt_ov135_021F8F84
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5B5C 0x021D5B5C thumb ov115
 */
#include "../include/Obj10580.h"
typedef unsigned char u8;
typedef signed short s16;
struct MsgBank;
extern void func_021D5B5C(char *p, struct MsgBank *a, int b);
int WORLDTRADE_ENTER_ShowErrorMessage(u8 *p, void *dialog)
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
