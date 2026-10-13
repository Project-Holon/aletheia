/*
 * function: func_021BDC08
 * address: 0x021BDC08
 * packet: pkt_ov209_021BDC08
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_CreateUnit 0x0204B100 arm
 *   func_021C940C 0x021C940C thumb ov212
 *   CLACT_SetActorVisible 0x0204BA20 arm
 *   func_021BD8D8 0x021BD8D8 thumb ov209
 *   func_021BD890 0x021BD890 thumb ov209
 *   func_0200CA54 0x0200CA54 thumb
 *   func_0200CA38 0x0200CA38 thumb
 *   GAME_DATA_CheckSaveFlag 0x02012BF8 thumb
 *   d_021BE9F0 0x021BE9F0 data a4
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
extern const Template d_021BE9F0[10];
struct Actor;
struct Bank;
struct Blk37;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
struct Obj;
extern struct Obj *func_021C940C(u32 bank, const u8 *t, u16 heap);
extern void CLACT_SetActorVisible(struct Actor *a, u32 v);
extern void func_021BD8D8(char *p, u32 idx, u32 value);
extern void func_021BD890(char *, int, int);
extern u32 func_0200CA54(struct Blk37 *p);
extern u32 func_0200CA38(struct Blk37 *p);
extern int GAME_DATA_CheckSaveFlag(int, int);
void func_021BDC08(char *p)
{
    unsigned i;
    Template t;
    ((struct Obj04617 *)p)->fA70 = CLACT_CreateUnit(60, 0, 0x6b);
    for (i = 0; i < 60; i++)
        *(unsigned *)(p + i * 4 + 0xa74) = 0;
    for (i = 0; i <= 9; i++) {
        t = d_021BE9F0[i];
        t.w8 = *(u32 *)(p + t.w8 * 4 + 0xb64);
        t.wC = *(u32 *)(p + t.wC * 4 + 0xbf4);
        t.w10 = *(u32 *)(p + t.w10 * 4 + 0xc0c);
        *(void **)(p + i * 4 + 0xa74) = func_021C940C((u32)(((struct Obj04617 *)p)->fA70), (const u8 *)(&t), 0x6b);
        CLACT_SetActorVisible(*(void **)(p + i * 4 + 0xa74), 0);
    }
    if (((struct Obj25570 *)(*(char * *)&((struct Obj04617 *)p)->f0))->fA <= 7) {
        func_021BD8D8(p, 0, 0);
        func_021BD8D8(p, 1, 0);
    }
    if (func_0200CA54(((struct Obj25571 *)(*(char * *)&((struct Obj04617 *)p)->f0))->f4) == 0)
        func_021BD8D8(p, 9, 0);
    if (func_0200CA38(((struct Obj25572 *)(*(char * *)&((struct Obj04617 *)p)->f0))->f4) == 0)
        func_021BD8D8(p, 8, 0);
    if (((struct Obj25573 *)(*(char * *)&((struct Obj04617 *)p)->f0))->f8 == 1) {
        func_021BD8D8(p, 8, 0);
        func_021BD8D8(p, 5, 0);
    } else if (GAME_DATA_CheckSaveFlag(**(int * *)&((struct Obj04617 *)p)->f0, 15) == 1)
        func_021BD890(p, 5, 7);
}
