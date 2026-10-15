/*
 * function: B_PLIST_MAIN_ReadParty
 * address: 0x0221099C
 * packet: pkt_ov198_0221099C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * remainder: two-byte alignment padding at 02210A4A.
 * symbols:
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   B_PLIST_MAIN_ReadSummary 0x022107A8 thumb ov198
 */
#include "../include/Obj04603.h"
#include "../include/Obj25259.h"
#include "../include/Obj25260.h"
#include "../include/Obj25261.h"
#include "../include/Obj25262.h"
#include "../include/Obj25263.h"
#include "../include/Obj25264.h"
#include "../include/Obj25265.h"
typedef unsigned char u8;
extern unsigned POKEPARTY_GetCount(void *);
extern void *POKEPARTY_GetMember(void *,unsigned);
struct Summary;
extern void B_PLIST_MAIN_ReadSummary(void *unused, void *mon, struct Summary *p);
void B_PLIST_MAIN_ReadParty(u8 *p)
{
    unsigned i;
    if (((struct Obj25259 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f18==0) {
        for (i=0;i<6;i++) {
            if (i<POKEPARTY_GetCount(((struct Obj25260 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f4))
                B_PLIST_MAIN_ReadSummary(p,POKEPARTY_GetMember(((struct Obj25261 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f4,i),(struct Summary *)(p+4+i*76));
            else B_PLIST_MAIN_ReadSummary(p,0,(struct Summary *)(p+4+i*76));
        }
    } else {
        for (i=0;i<3;i++) {
            if (i<POKEPARTY_GetCount(((struct Obj25262 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f4))
                B_PLIST_MAIN_ReadSummary(p,POKEPARTY_GetMember(((struct Obj25263 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f4,i),(struct Summary *)(p+4+i*76));
            else B_PLIST_MAIN_ReadSummary(p,0,(struct Summary *)(p+4+i*76));
            if (i<POKEPARTY_GetCount(((struct Obj25264 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f8))
                B_PLIST_MAIN_ReadSummary(p,POKEPARTY_GetMember(((struct Obj25265 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f8,i),(struct Summary *)(p+4+(i+3)*76));
            else B_PLIST_MAIN_ReadSummary(p,0,(struct Summary *)(p+4+(i+3)*76));
        }
    }
}
