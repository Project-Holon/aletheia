/*
 * function: PMSIV_EDIT_Redraw
 * address: 0x021BC23C
 * packet: pkt_ov110_021BC23C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding at 0x021BC31E.
 * symbols:
 *   PMSIV_EDIT_ApplyPalette 0x021BC0CC thumb ov110
 *   PMS_INPUT_GetInputMode 0x021BF6D8 thumb ov110
 *   PMSIV_EDIT_ClearSlotBox 0x021BC58C thumb ov110
 *   PMS_INPUT_GetWord 0x021BF6F0 thumb ov110
 *   PMSIV_EDIT_DrawSlotWord 0x021BC5BC thumb ov110
 *   PMSIV_EDIT_DrawFreeText 0x021BC340 thumb ov110
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct { s16 x,y; } Pair;
typedef struct { void *root; u8 *state; int pad; void *desc[2]; u8 gap0[8]; void *items[2][2]; u8 gap[12]; Pair pos[2]; int pad40; int count; } Obj;
extern void PMSIV_EDIT_ApplyPalette(u8 *p);
typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern unsigned PMS_INPUT_GetInputMode(u8 *);
extern void PMSIV_EDIT_ClearSlotBox(void *,Pair *);
extern u32 PMS_INPUT_GetWord(u8 *p, u32 i);
struct Vec2;
extern void PMSIV_EDIT_DrawSlotWord(u8 *p, struct Descriptor *window, const struct Vec2 *input, u32 id, struct Obj *sprite);
extern int PMSIV_EDIT_DrawFreeText(Obj *,void *,u8);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_02041B6C(unsigned);
void PMSIV_EDIT_Redraw(Obj *p)
{
    int i,j;
    PMSIV_EDIT_ApplyPalette((u8 *)p);
    for(i=0;i<2;i++) {
        for(j=0;j<2;j++) {
            if(p->items[j][i]) CLACT_SetActorDrawEnable(p->items[j][i],0);
        }
        BMP_Clear(BMP_WIN_GetBmp(p->desc[i]),15);
        switch(PMS_INPUT_GetInputMode(p->state)) {
        case 0:
            PMSIV_EDIT_ClearSlotBox(p->desc[i],&p->pos[0]);
            PMSIV_EDIT_DrawSlotWord((u8 *)p,p->desc[i],(const struct Vec2 *)(&p->pos[0]),PMS_INPUT_GetWord(p->state,0),p->items[0][i]);
            break;
        case 1:
            PMSIV_EDIT_ClearSlotBox(p->desc[i],&p->pos[0]);
            PMSIV_EDIT_ClearSlotBox(p->desc[i],&p->pos[1]);
            PMSIV_EDIT_DrawSlotWord((u8 *)p,p->desc[i],(const struct Vec2 *)(&p->pos[0]),PMS_INPUT_GetWord(p->state,0),p->items[0][i]);
            PMSIV_EDIT_DrawSlotWord((u8 *)p,p->desc[i],(const struct Vec2 *)(&p->pos[1]),PMS_INPUT_GetWord(p->state,1),p->items[1][i]);
            break;
        case 2:
            p->count=PMSIV_EDIT_DrawFreeText(p,p->desc[i],i);
            break;
        }
        BMP_WIN_TransferChars(p->desc[i]);
    }
    func_02041B6C(0);
    func_02041B6C(4);
}
