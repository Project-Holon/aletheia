/*
 * function: func_021DE55C
 * address: 0x021DE55C
 * packet: pkt_ov137_021DE55C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   KEY_GetCont 0x0203630C arm
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   KEY_GetTrg 0x020362DC arm
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 */
#include "../include/Obj05428.h"
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int     s32;
struct Rec;
struct Rec3;
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern unsigned int KEY_GetCont(void);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern u32 KEY_GetTrg(void);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
int func_021DE55C(char *p) {
    int state;
    if (((struct Obj05428 *)p)->fF0 == 0) return 1;
    state = PRINTSYS_PrintStreamGetState(((struct Obj05428 *)p)->fF0);
    if (state == 0) {
        if (KEY_GetCont() & 1)
            PRINTSYS_PrintStreamShortWait(((struct Obj05428 *)p)->fF0, 0);
    } else if (state == 1) {
        if (KEY_GetTrg() & 1)
            PRINTSYS_PrintStreamReleasePause(((struct Obj05428 *)p)->fF0);
    } else if (state == 2) {
        PRINTSYS_PrintStreamDelete(((struct Obj05428 *)p)->fF0);
        ((struct Obj05428 *)p)->fF0 = 0;
        return 1;
    }
    return 0;
}
