/*
 * function: BATTLE_REC_TOOL_UnpackPlayers
 * address: 0x021EF090
 * packet: pkt_ov188_021EF090
 * region: ov188
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTATUS_Copy 0x02008494 thumb
 *   BATTLE_REC_TOOL_UnpackPlayerProfile 0x021EF140 thumb ov188
 */
#include "../include/Obj14492.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MYSTATUS_Copy(void *, void *);
extern void BATTLE_REC_TOOL_UnpackPlayerProfile(u8 *, u8 *);
void BATTLE_REC_TOOL_UnpackPlayers(u8 *a, u8 *b)
{
    unsigned i;
    u8 *p;
    for(i=0;i<4;i++) {
        p = b+i*0x44;
        switch(((struct Obj14492 *)p)->f16C8) {
        case 1: MYSTATUS_Copy(b+0x16CC+i*0x44, *(void **)(a+0x34+i*4)); break;
        case 2: BATTLE_REC_TOOL_UnpackPlayerProfile(*(u8 **)(a+0x48+i*4), b+0x16CC+i*0x44); break;
        }
        a[0x44+i] = ((struct Obj14492 *)p)->f16CA;
    }
}
