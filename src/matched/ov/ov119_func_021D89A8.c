/*
 * function: POKETRADE_PROC_CheckSaveFlag
 * address: 0x021D89A8
 * packet: pkt_ov119_021D89A8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02008FEC 0x02008FEC thumb
 *   MAIL_FindEmptySlot 0x02009020 thumb
 */
#include "../include/Obj22697.h"
struct Sub02008F80Obj;
extern struct Sub02008F80Obj *func_02008FEC(void *sys);
extern int MAIL_FindEmptySlot(void *obj, int v);

int POKETRADE_PROC_CheckSaveFlag(char *p)
{
    void *o = func_02008FEC(((struct Obj22697 *)p)->f82C);
    int r = 0;
    if (MAIL_FindEmptySlot(o, 0) == -1)
        r = 1;
    return r;
}
