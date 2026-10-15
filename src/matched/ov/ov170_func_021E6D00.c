/*
 * function: BOX2_SEQ_StatePlaceItem
 * address:  0x021E6D00
 * packet:   pkt_ov170_021E6D00
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb
 *   BOX2_SEQ_CreateB 0x021EA728 thumb
 *   BOX2_SEQ_SetSlotActorMode 0x021ECB60 thumb
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb
 *   BOX2_MAIN_SetBoxValueAt 0x021DD2B4 thumb
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb
 *   BOX2_MAIN_CanPlaceInBox 0x021DD718 thumb
 *   BOX2_MAIN_RecalcPartyParam 0x021DD8A8 thumb
 *   BOX2_SEQ_ShowSlotIcon 0x021EC48C thumb
 *   BOX2_MAIN_ChangeBoxFormPreserve 0x021DEFEC thumb
 *   BOX2_SEQ_SetSlotCharacter 0x021ED094 thumb
 *   BOX2_SEQ_SetActorAffineMode 0x021ED108 thumb
 *   BOX2_SEQ_SetActorAnimSeq 0x021EBFA8 thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   BOX2_SEQ_CreateHandSlotActorsB 0x021ED1C8 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_MAIN_Check122C 0x021E122C thumb
 *
 * Twin of BOX2_SEQ_StateMoveItemScroll driven by the work fields: moves the held item from
 * slot 0xA16E to slot 0xA17E, swapping with what is there.
 */

typedef struct {
    unsigned short idx;
    unsigned short slot;
} Entry;

typedef struct {
    unsigned char lo : 4;
    unsigned char hi : 4;
} Nib;

extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern void BOX2_SEQ_CreateB(void *p);
extern void BOX2_SEQ_SetSlotActorMode(char *w, int i, int f);
typedef unsigned int   u32;
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void BOX2_MAIN_SetBoxValueAt(int a, int b, int c, int d, int e);
extern int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b);
extern int BOX2_MAIN_CanPlaceInBox(void **pp, void *mon);
extern void BOX2_MAIN_RecalcPartyParam(void **pp, u32 idx);
extern void BOX2_SEQ_ShowSlotIcon(unsigned char *p, int box, int pos, int win);
extern void BOX2_MAIN_ChangeBoxFormPreserve(char *p, int b);
extern void BOX2_SEQ_SetSlotCharacter(char *w, unsigned item);
extern void BOX2_SEQ_SetActorAffineMode(char *w, int on);
extern void BOX2_SEQ_SetActorAnimSeq(char *w, int i, int v);
extern void BOX2_SEQ_SetActorDrawEnable(char *w, int i, int v);
extern void BOX2_SEQ_CreateHandSlotActorsB(char *w);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_Check122C(unsigned char *p);

#define WORK(p) (*(char **)((p) + 0x2C))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
#define ITEM(p) (*(unsigned short *)(WORK(p) + 0xA16C))
#define WIN(p, i) (*(unsigned char *)(WORK(p) + (i) + 0x3DD2))
#define CUR(p) (*(unsigned short *)(WORK(p) + 0xA16E))
#define TGT(p) (*(unsigned char *)(WORK(p) + 0xA17E))
#define STATE(p) (*(int *)((p) + 0x28))
#define NIB(p) ((Nib *)((p) + 0x1C))

int BOX2_SEQ_StatePlaceItem(unsigned char *p)
{
    unsigned short item;
    if (NIB(p)->lo == 0)
        NIB(p)->hi = 1;
    if (TGT(p) == CUR(p) && (p[0x17] == 0xFF || p[0x17] == p[0x14])) {
        ITEM(p) = 0;
        BOX2_UI_DeleteSlotObjects((char *)p, 0, 1, 1);
        return 0x40;
    }
    if (p[0x17] == p[0x14] || CUR(p) >= 0x1E)
        BOX2_SEQ_SetSlotActorMode(WORK(p), CUR(p), 1);
    BOX2_SEQ_SetSlotActorMode(WORK(p), TGT(p), 0);
    item = BOX2_MAIN_GetPartyValueAt((void ***)p, TGT(p), p[0x14], 6, 0);
    BOX2_MAIN_SetBoxValueAt((int)p, TGT(p), p[0x14], 6, ITEM(p));
    if (BOX2_MAIN_CanPlaceInBox((void **)p, (void *)BOX2_MAIN_GetMonAt((void ***)p, p[0x14], TGT(p))) == 1) {
        BOX2_MAIN_RecalcPartyParam((void **)p, TGT(p));
        BOX2_SEQ_ShowSlotIcon(p, p[0x14], TGT(p), WIN(p, TGT(p)));
    }
    BOX2_MAIN_ChangeBoxFormPreserve((char *)p, TGT(p));
    ITEM(p) = item;
    BOX2_MAIN_SetBoxValueAt((int)p, CUR(p), p[0x17], 6, ITEM(p));
    if (BOX2_MAIN_CanPlaceInBox((void **)p, (void *)BOX2_MAIN_GetMonAt((void ***)p, p[0x17], CUR(p))) == 1) {
        BOX2_MAIN_RecalcPartyParam((void **)p, CUR(p));
        if (p[0x17] == 0xFF || p[0x17] == p[0x14])
            BOX2_SEQ_ShowSlotIcon(p, p[0x14], CUR(p), WIN(p, CUR(p)));
    }
    if (ITEM(p) == 0) {
        BOX2_UI_DeleteSlotObjects((char *)p, 0, 1, 1);
        return 0x40;
    }
    BOX2_SEQ_CreateB(p);
    (*(Entry **)(WORK(p) + 0x60))->idx = TGT(p);
    BOX2_SEQ_SetSlotCharacter(WORK(p), ITEM(p));
    BOX2_SEQ_SetActorAffineMode(WORK(p), 1);
    BOX2_SEQ_SetActorAnimSeq(WORK(p), 10, 1);
    BOX2_SEQ_SetActorDrawEnable(WORK(p), 10, 1);
    BOX2_SEQ_CreateHandSlotActorsB(WORK(p));
    GFL_USE_PlaySeDefaultVolume(0x666);
    return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_Check122C, 0x43);
}
