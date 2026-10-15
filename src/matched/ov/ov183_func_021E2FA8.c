/*
 * function: BR_CODEIN_ShowMenuText
 * address: 0x021E2FA8
 * packet: pkt_ov183_021E2FA8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb ov186
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 */
#include "../include/Obj03885.h"
#include "../include/Obj24693.h"
#include "../include/Obj24694.h"
typedef unsigned short u16;
extern void *BR_UTIL_CreateTextWin(int a, void *owner, u16 heap);
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
extern void BR_UTIL_StartEffect(int, int, int *);
void BR_CODEIN_ShowMenuText(char *p)
{
    int args[2];
    if (((struct Obj03885 *)p)->f8 == 0)
        ((struct Obj03885 *)p)->f8 = BR_UTIL_CreateTextWin(((struct Obj24693 *)(*(char * *)&((struct Obj03885 *)p)->f3C))->f8, (void *)(((struct Obj03885 *)p)->f4), ((struct Obj03885 *)p)->f38);
    BR_UTIL_SetWindowText(((struct Obj03885 *)p)->f8, (char *)(((struct Obj24694 *)(*(char * *)&((struct Obj03885 *)p)->f3C))->f8), (void *)0x14b);
    args[0] = 0x80;
    args[1] = 0x60;
    BR_UTIL_StartEffect(((struct Obj03885 *)p)->f30, 4, args);
}
