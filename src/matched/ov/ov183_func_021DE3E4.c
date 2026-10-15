/*
 * function: BR_CODEIN_ResultSetupTextWin
 * address: 0x021DE3E4
 * packet: pkt_ov183_021DE3E4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb ov186
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 */
#include "../include/Obj02519.h"
#include "../include/Obj14429.h"
typedef unsigned short u16;
extern void *BR_UTIL_CreateTextWin(int a, void *owner, u16 heap);
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
void BR_CODEIN_ResultSetupTextWin(char *p, char *q)
{
    ((struct Obj02519 *)p)->f8 = BR_UTIL_CreateTextWin(((struct Obj14429 *)q)->f8, (void *)(*(int *)&((struct Obj02519 *)p)->f4), ((struct Obj02519 *)p)->f6C);
    BR_UTIL_SetWindowText(((struct Obj02519 *)p)->f8, (char *)(((struct Obj14429 *)q)->f8), (void *)0x86);
}
