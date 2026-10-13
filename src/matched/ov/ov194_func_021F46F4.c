/*
 * function: func_021F46F4
 * address: 0x021F46F4
 * packet: pkt_ov194_021F46F4
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Padding: two zero bytes at 0x021F47B2, then a function prologue.
 * symbols:
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   KEY_GetCont 0x0203630C arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   UI_SetInputMode 0x020355D8 arm
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   func_021F462C 0x021F462C thumb ov194
 */
#include "../include/Obj03901.h"
struct Tcbl;
struct Rec;
extern void TCBL_Main(struct Tcbl *);
extern unsigned PRINTSYS_PrintStreamGetState(void *);
extern unsigned int KEY_GetCont(void);
extern int TOUCHPANEL_GetCont(void);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *, int);
extern void UI_SetInputMode(unsigned char);
typedef unsigned int   u32;
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern void func_021F462C(unsigned char *, unsigned);
void func_021F46F4(unsigned char *a, int *state, char *p)
{
    char *q = p + 0x254;
    switch (*state) {
    case 0:
        TCBL_Main(*(struct Tcbl * *)&((struct Obj03901 *)q)->f4);
        switch (PRINTSYS_PrintStreamGetState(((struct Obj03901 *)q)->f0)) {
        case 0:
            if (((unsigned)KEY_GetCont() & 3) != 0 || TOUCHPANEL_GetCont() != 0) {
                PRINTSYS_PrintStreamShortWait(*(struct Rec * *)&((struct Obj03901 *)q)->f0, 0);
                if (((unsigned)KEY_GetCont() & 3) != 0) UI_SetInputMode(0);
                else UI_SetInputMode(1);
            }
            break;
        case 2:
            *state = 1;
            break;
        case 1:
            if (((unsigned)KEY_GetTrg() & 3) != 0 || TOUCHPANEL_GetTrg() != 0) {
                PRINTSYS_PrintStreamReleasePause(((struct Obj03901 *)q)->f0);
                if (((unsigned)KEY_GetTrg() & 3) != 0) UI_SetInputMode(0);
                else UI_SetInputMode(1);
            }
            break;
        }
        break;
    case 1:
        if (((struct Obj03901 *)q)->fE >= ((struct Obj03901 *)q)->fC) *state = 2;
        else (((struct Obj03901 *)q)->fE)++;
        break;
    case 2:
        func_021F462C(a, ((struct Obj03901 *)q)->f8);
        break;
    }
}
