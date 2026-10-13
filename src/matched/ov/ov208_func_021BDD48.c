/*
 * function: func_021BDD48
 * address: 0x021BDD48
 * packet: pkt_ov208_021BDD48
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 021BDD96..021BDD98 is two-byte zero alignment padding.
 * matching: the signed short offset parameter schedules its spill before the count load.
 * symbols:
 *   CLACT_GetActorPos 0x0204B53C arm
 *   CLACT_SetActorPos 0x0204B528 arm
 */
#include "../include/Obj25442.h"
typedef unsigned short u16;
struct Pt { u16 x,y; };
struct Actor { char pad[0xc]; struct Pt pos; };
extern void CLACT_GetActorPos(const struct Actor *,struct Pt *);
extern void CLACT_SetActorPos(struct Actor *,const struct Pt *);
void func_021BDD48(char *p,short offset)
{
    unsigned char i;
    struct Pt pt;
    for(i=0;i<((struct Obj25442 *)p)->f68;i++) {
        CLACT_GetActorPos(*(struct Actor **)(p+i*8+0x70),&pt);
        pt.y=*(short *)(*(char **)(p+i*8+0x6c)+6);
        pt.y=(short)pt.y+offset;
        CLACT_SetActorPos(*(struct Actor **)(p+i*8+0x70),&pt);
    }
}
