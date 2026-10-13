/*
 * function: PMSIV_MENU_CreateExtraItems
 * address: 0x021BD114
 * packet: pkt_ov110_021BD114
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_VIEW_CreateActor 0x021BAC78 thumb ov110
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   gPmsivMenuExtraItems 0x021C38D9 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { void *root; u8 pad[0x8c]; void *items[2]; } Object;
extern const u8 gPmsivMenuExtraItems[];
struct Obj;
extern struct Obj *PMS_INPUT_VIEW_CreateActor(char *p, unsigned int *r, short x, short y, unsigned int a, int mode);
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void PMSIV_MENU_CreateExtraItems(Object *p) {
    u8 i;
    for(i=0;i<2;i++) {
        p->items[i]=PMS_INPUT_VIEW_CreateActor(p->root,(unsigned int *)((u8 *)p+0x10),gPmsivMenuExtraItems[3*i],gPmsivMenuExtraItems[3*i+1],0,1);
        CLACT_SetActorAnimSeq(p->items[i],gPmsivMenuExtraItems[3*i+2]);
        CLACT_SetActorDrawEnable(p->items[i],0);
    }
}
