/*
 * function: MB_SEQ_PushPartyList
 * address:  0x021C7494
 * packet:   pkt_ov136_021C7494
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PROCSYS_Push  0x02031348  arm
 *   ov091_id 0x0000005B data
 *   gPartyListProcData 0x021BED00 data ov091 a4
 */
#include "../include/Obj10610.h"
#include "../include/Obj23650.h"

typedef unsigned char u8;
typedef unsigned int u32;
struct Bf7 {
    u8 v : 7;
    u8 w : 1;
};
extern const u8 gPartyListProcData[];
extern u8 ov091_id[];
extern void PROCSYS_Push(void *, u32, const void *, void *);
int MB_SEQ_PushPartyList(u8 *p)
{
    u32 v = ((struct Bf7 *)(p + 0x21))->v;
    ((struct Obj23650 *)(*(u8 * *)&((struct Obj10610 *)p)->f10))->f3C = v;
    PROCSYS_Push(((struct Obj10610 *)p)->f30, (u32)ov091_id, gPartyListProcData, ((struct Obj10610 *)p)->f10);
    return 0;
}
