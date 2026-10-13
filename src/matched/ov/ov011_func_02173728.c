/*
 * function: INTRUDE_COMM_RecvMemberCount
 * address: 0x02173728
 * packet: pkt_ov011_02173728
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_COMM_GetGameData 0x02026478 thumb
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GAME_DATA_SetEnterMode 0x02012B4C thumb
 * The loaded byte stays live as r1 into 02012B4C.
 */
#include "../include/Obj12413.h"
typedef unsigned char u8;
struct Link;
typedef unsigned int   u32;
extern u32 GAME_COMM_GetGameData(void *obj);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern unsigned int GFL_NET_GetHandleNetID(struct Link *);
struct BigObj;
extern void GAME_DATA_SetEnterMode(struct BigObj *p, u8 v);
void INTRUDE_COMM_RecvMemberCount(unsigned int a, int b, u8 *c, u8 *d)
{
    void *h;
    unsigned int n;
    h = (void *)GAME_COMM_GetGameData(((struct Obj12413 *)d)->f4);
    if (a != GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) {
        n = *c;
        d[0x902] = n;
        GAME_DATA_SetEnterMode(h, n);
    }
}
