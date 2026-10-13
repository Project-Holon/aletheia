/*
 * function: PMSIV_EDIT_CreateWordIcons
 * address: 0x021BC160
 * packet: pkt_ov110_021BC160
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding after return.
 * lever: typed two-by-two pointer member retains the inner indexed base.
 * symbols:
 *   PMS_INPUT_VIEW_GetCursorRes 0x021BAC50 thumb ov110
 *   PMS_INPUT_VIEW_CreateActor 0x021BAC78 thumb ov110
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef short s16;
typedef struct { int a,b,c; } Triple;
typedef struct { void *root; u8 pad[0x18]; void *items[2][2]; } Obj;
struct V3;
extern void PMS_INPUT_VIEW_GetCursorRes(char *p, struct V3 *out, int i);
struct Obj;
extern struct Obj *PMS_INPUT_VIEW_CreateActor(char *p, unsigned int *r, short x, short y, unsigned int a, int mode);
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void PMSIV_EDIT_CreateWordIcons(Obj *p)
{
    Triple t;
    int i,j;
    for (i=0;i<2;i++) {
        PMS_INPUT_VIEW_GetCursorRes(p->root,(struct V3 *)(&t),i);
        for (j=0;j<2;j++) {
            p->items[j][i]=PMS_INPUT_VIEW_CreateActor(p->root,(unsigned int *)(&t),0,0,2,i+1);
            CLACT_SetActorDrawEnable(p->items[j][i],0);
        }
    }
}
