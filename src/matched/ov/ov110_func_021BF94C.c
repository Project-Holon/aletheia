/*
 * function: PMSIV_WORDWIN_CreateActors
 * address: 0x021BF94C
 * packet: pkt_ov110_021BF94C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding at 0x021BF9EE.
 * lever: typed items member and z=i preserve indexed base and copied zero.
 * symbols:
 *   PMS_INPUT_VIEW_GetUiRes 0x021BAC64 thumb ov110
 *   PMS_INPUT_VIEW_CreateActor 0x021BAC78 thumb ov110
 *   PMS_INPUT_VIEW_GetCursorRes 0x021BAC50 thumb ov110
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x,y,z; } Triple;
typedef struct { void *root; void *a; void *b; void *c; void *d; void *first; void *unused; void *second; void *items[10]; } Obj;
extern void PMS_INPUT_VIEW_GetUiRes(void *,Triple *,int,int);
struct Obj;
extern struct Obj *PMS_INPUT_VIEW_CreateActor(char *p, unsigned int *r, short x, short y, unsigned int a, int mode);
struct V3;
extern void PMS_INPUT_VIEW_GetCursorRes(char *p, struct V3 *out, int i);
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorBgPriority(void *,int);
void PMSIV_WORDWIN_CreateActors(Obj *p) {
    Triple t;
    Triple s;
    int i;
    int z;
    i=0;
    PMS_INPUT_VIEW_GetUiRes(p->root,&t,0,0);
    p->first=PMS_INPUT_VIEW_CreateActor(p->root,(unsigned int *)(&t),62,24,4,1);
    CLACT_SetActorAnimSeq(p->first,8);
    CLACT_SetActorDrawEnable(p->first,0);
    p->second=PMS_INPUT_VIEW_CreateActor(p->root,(unsigned int *)(&t),244,18,5,1);
    CLACT_SetActorAnimSeq(p->second,18);
    CLACT_SetActorDrawEnable(p->second,0);
    z=i;
    for(;i<10;i++) {
        PMS_INPUT_VIEW_GetCursorRes(p->root,(struct V3 *)(&s),z);
        p->items[i]=PMS_INPUT_VIEW_CreateActor(p->root,(unsigned int *)(&s),z,z,z,1);
        CLACT_SetActorAnimSeq(p->items[i],i);
        CLACT_SetActorDrawEnable(p->items[i],z);
        CLACT_SetActorBgPriority(p->items[i],1);
    }
}
