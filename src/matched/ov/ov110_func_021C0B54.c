/*
 * function: PMS_SELECT_GRAPHIC_CreateRows
 * address: 0x021C0B54
 * packet: pkt_ov110_021C0B54
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 Thumb 0x02024910 lacks an outside witness. Verified EXACT in blocker.log:
 *   void *PMS_WORD_GetSaveEntry(char *p,int i) { return p+8+i*8; }
 * symbols:
 *   PMS_SELECT_GRAPHIC_GetSceneActorUnit 0x021C1718 thumb ov110
 *   PMS_SELECT_GRAPHIC_RedrawRows 0x021C0C44 thumb ov110
 *   PMS_SELECT_GRAPHIC_PlaceScrollThumb 0x021C0D34 thumb ov110
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   PMS_WORD_GetSaveEntry 0x02024910 thumb
 *   PMSI_PARAM_IsComplete  0x02024464  thumb  arm9
 *   PMS_DRAW_Create  0x0202DB0C  thumb  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned int PMS_SELECT_GRAPHIC_GetSceneActorUnit(u8 *p);
typedef unsigned int   u32;
struct Obj;
struct PmsDraw;
struct T;
extern struct PmsDraw *PMS_DRAW_Create(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
extern void *PMS_WORD_GetSaveEntry(char *p, int idx);
extern int PMSI_PARAM_IsComplete(struct T *p, u32 a1);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void PMS_SELECT_GRAPHIC_RedrawRows(void *);
extern void PMS_SELECT_GRAPHIC_PlaceScrollThumb(char *p, int force);
void PMS_SELECT_GRAPHIC_CreateRows(char *p) {
    int i;
    unsigned v;
    *(void **)(p+0x8c)=PMS_DRAW_Create((u32)PMS_SELECT_GRAPHIC_GetSceneActorUnit(*(void **)(p+0x50)),(int)0,(u32)(*(void **)(p+0x5c)),(u32)(*(void **)(p+0x58)),(int)8,(int)4,*(u16 *)(p+4));
    *(u8 *)(p+0x97)=0;
    for(i=0;i<20;i++) {
        if(!PMSI_PARAM_IsComplete(PMS_WORD_GetSaveEntry(*(void **)(p+0x20),i),(u16)(*(u16 *)(p+4)))) break;
        (*(u8 *)(p+0x97))++;
    }
    v=*(u8 *)(p+0x97);
    *(u8 *)(p+0x98)=v;
    if(v<20) (*(u8 *)(p+0x98))++;
    CLACT_SetActorDrawEnable(*(void **)(p+8),(int)(*(u8 *)(p+0x98)>3));
    for(i=0;i<4;i++) *(void **)(p+0x6c+i*4)=(void *)BMP_WIN_Create((int)2,(int)2,(u8)(i*6+2),(int)25,(int)4,(int)9,(int)1);
    PMS_SELECT_GRAPHIC_RedrawRows(p);
    PMS_SELECT_GRAPHIC_PlaceScrollThumb(p,1);
}
