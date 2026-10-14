/*
 * function: ZUKAN_LIST_StateScroll
 * address: 0x021BD148
 * packet: pkt_ov209_021BD148
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: unsigned short bitfield base keeps ldrh before the 16/17 extraction; unsigned emits ldr (DIFF1).
 * symbols:
 *   FRAME_LIST_Update 0x021B7AB0 thumb ov067
 *   ZUKAN_LIST_IsActorAnimActive 0x021BD8C4 thumb ov209
 *   ZUKAN_LIST_UpdateArrowActors 0x021BE5D4 thumb ov209
 */
#include "../include/Obj00088.h"
struct Timer { unsigned short low : 1; unsigned short high : 15; };
struct S;
extern int FRAME_LIST_Update(struct S *p);
typedef unsigned int   u32;
extern u32 ZUKAN_LIST_IsActorAnimActive(char *p, u32 idx);
extern void ZUKAN_LIST_UpdateArrowActors(char *, int);
int ZUKAN_LIST_StateScroll(char *p)
{
    switch (*(int *)&((struct Obj00088 *)p)->f14) {
    case 0:
        if (FRAME_LIST_Update((struct S *)(*(char * *)&((struct Obj00088 *)p)->fC2C)) == -1) (*(int *)&((struct Obj00088 *)p)->f14)++;
        break;
    case 1:
        if (((struct Timer *)(p + 0xc24))->high == 60 || ZUKAN_LIST_IsActorAnimActive(p, ((struct Timer *)(p + 0xc24))->high) == 0) {
            *(int *)&((struct Obj00088 *)p)->f14 = 0;
            ZUKAN_LIST_UpdateArrowActors(p, 0);
            return 4;
        }
        break;
    }
    return 5;
}
