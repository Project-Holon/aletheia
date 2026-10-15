/*
 * function: MYSTERY_TaskCleanup
 * address: 0x021D80C0
 * packet: pkt_ov121_021D80C0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_DeleteSaveMenu 0x021D8198 thumb ov121
 *   MYSTERY_DeleteCardMenu 0x021D8380 thumb ov121
 *   MYSTERY_DeletePartyMenu 0x021D849C thumb ov121
 *   MYSTERY_ALBUM_Delete 0x021DD980 thumb ov121
 *   MYSTERY_ALBUM_DeleteSlotWork 0x021DD1FC thumb ov121
 *   MYSTERY_UTIL_MarkTaskDone 0x021DA8B8 thumb ov121
 */
#include "../include/Obj00326.h"
extern void MYSTERY_DeleteSaveMenu(char *),MYSTERY_DeleteCardMenu(char *),MYSTERY_DeletePartyMenu(char *),MYSTERY_ALBUM_Delete(char *);
extern void MYSTERY_ALBUM_DeleteSlotWork(void **);
typedef unsigned int   u32;
extern void MYSTERY_UTIL_MarkTaskDone(u32 *p);
void MYSTERY_TaskCleanup(void *p,int n,char *q) {
 MYSTERY_DeleteSaveMenu(q);MYSTERY_DeleteCardMenu(q);MYSTERY_DeletePartyMenu(q);
 if(*(char * *)&((struct Obj00326 *)q)->f0) {MYSTERY_ALBUM_Delete(*(char * *)&((struct Obj00326 *)q)->f0);MYSTERY_ALBUM_DeleteSlotWork(*(void ** *)&((struct Obj00326 *)q)->f4);}
 MYSTERY_UTIL_MarkTaskDone(p);
}
