/*
 * function: ZUKAN_LIST_CreateActors
 * address: 0x021BDC08
 * packet: pkt_ov209_021BDC08
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_CreateUnit 0x0204B100 arm
 *   ZUKAN_CreateActor 0x021C940C thumb ov212
 *   CLACT_SetActorVisible 0x0204BA20 arm
 *   ZUKAN_LIST_SetActorVisible 0x021BD8D8 thumb ov209
 *   ZUKAN_LIST_StartActorAnim 0x021BD890 thumb ov209
 *   ZUKAN_SAVE_GetDexObtained 0x0200CA54 thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled 0x0200CA38 thumb
 *   GAME_DATA_CheckSaveFlag 0x02012BF8 thumb
 *   gZukanListActorDescTable 0x021BE9F0 data a4
 */
#include "../include/Obj04617.h"
#include "../include/Obj25570.h"
#include "../include/Obj25571.h"
#include "../include/Obj25572.h"
#include "../include/Obj25573.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Template { u32 w0, w4, w8, wC, w10; u16 h14, h16; } Template;
extern const Template gZukanListActorDescTable[10];
struct Actor;
struct Bank;
struct Blk37;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
struct Obj;
extern struct Obj *ZUKAN_CreateActor(u32 bank, const u8 *t, u16 heap);
extern void CLACT_SetActorVisible(struct Actor *a, u32 v);
extern void ZUKAN_LIST_SetActorVisible(char *p, u32 idx, u32 value);
extern void ZUKAN_LIST_StartActorAnim(char *, int, int);
extern u32 ZUKAN_SAVE_GetDexObtained(struct Blk37 *p);
extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *p);
extern int GAME_DATA_CheckSaveFlag(int, int);
void ZUKAN_LIST_CreateActors(char *p)
{
    unsigned i;
    Template t;
    ((struct Obj04617 *)p)->fA70 = CLACT_CreateUnit(60, 0, 0x6b);
    for (i = 0; i < 60; i++)
        *(unsigned *)(p + i * 4 + 0xa74) = 0;
    for (i = 0; i <= 9; i++) {
        t = gZukanListActorDescTable[i];
        t.w8 = *(u32 *)(p + t.w8 * 4 + 0xb64);
        t.wC = *(u32 *)(p + t.wC * 4 + 0xbf4);
        t.w10 = *(u32 *)(p + t.w10 * 4 + 0xc0c);
        *(void **)(p + i * 4 + 0xa74) = ZUKAN_CreateActor((u32)(((struct Obj04617 *)p)->fA70), (const u8 *)(&t), 0x6b);
        CLACT_SetActorVisible(*(void **)(p + i * 4 + 0xa74), 0);
    }
    if (((struct Obj25570 *)(*(char * *)&((struct Obj04617 *)p)->f0))->fA <= 7) {
        ZUKAN_LIST_SetActorVisible(p, 0, 0);
        ZUKAN_LIST_SetActorVisible(p, 1, 0);
    }
    if (ZUKAN_SAVE_GetDexObtained(((struct Obj25571 *)(*(char * *)&((struct Obj04617 *)p)->f0))->f4) == 0)
        ZUKAN_LIST_SetActorVisible(p, 9, 0);
    if (ZUKAN_SAVE_IsNationalDexEnabled(((struct Obj25572 *)(*(char * *)&((struct Obj04617 *)p)->f0))->f4) == 0)
        ZUKAN_LIST_SetActorVisible(p, 8, 0);
    if (((struct Obj25573 *)(*(char * *)&((struct Obj04617 *)p)->f0))->f8 == 1) {
        ZUKAN_LIST_SetActorVisible(p, 8, 0);
        ZUKAN_LIST_SetActorVisible(p, 5, 0);
    } else if (GAME_DATA_CheckSaveFlag(**(int * *)&((struct Obj04617 *)p)->f0, 15) == 1)
        ZUKAN_LIST_StartActorAnim(p, 5, 7);
}
