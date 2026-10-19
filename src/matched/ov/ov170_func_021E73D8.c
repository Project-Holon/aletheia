/*
 * function: BOX2_SEQ_StatePlaceItemB
 * address:  0x021E73D8
 * packet:   pkt_ov170_021E73D8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_IsActorAnimActive 0x021EBFEC thumb
 *   BOX2_SEQ_SetActorAffineMode 0x021ED108 thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb
 *   BOX2_MAIN_SetBoxValueAt 0x021DD2B4 thumb
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb
 *   BOX2_MAIN_CanPlaceInBox 0x021DD718 thumb
 *   BOX2_MAIN_RecalcPartyParam 0x021DD8A8 thumb
 *   BOX2_SEQ_ShowSlotIcon 0x021EC48C thumb
 *   BOX2_MAIN_RefreshCurrentBoxMonInfo 0x021DEFEC thumb
 *   BOX2_SEQ_DeleteB 0x021EA750 thumb
 *   BOX2_UI_ShowWindowB 0x021EF68C thumb
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   CURSOR_MOVE_SetState 0x020260F4 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_SetSlotCharacter 0x021ED094 thumb
 *   BOX2_SEQ_SetActorAnimSeq 0x021EBFA8 thumb
 *   BOX2_SEQ_CreateHandSlotActorsB 0x021ED1C8 thumb
 *   BOX2_SEQ_ReturnAfterClear 0x021E8F50 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_SEQ_StateExitBox 0x021E1988 thumb
 *
 * Item swap on drop (template 021E6A60): moves the held item onto the
 * target slot, returns the target's old item to the source, and either
 * finishes or keeps the new item held.
 */

typedef struct {
    unsigned short idx;
    unsigned short slot;
} Entry;

extern unsigned int BOX2_SEQ_IsActorAnimActive(char *p, int i);
extern void BOX2_SEQ_SetActorAffineMode(char *w, int on);
extern void BOX2_SEQ_SetActorDrawEnable(char *w, int i, int v);
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void BOX2_MAIN_SetBoxValueAt(int a, int b, int c, int d, int e);
extern int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b);
extern int BOX2_MAIN_CanPlaceInBox(void **pp, void *mon);
extern void BOX2_MAIN_RecalcPartyParam(unsigned char *p, unsigned idx);
extern void BOX2_SEQ_ShowSlotIcon(unsigned char *p, int box, int pos, int win);
extern void BOX2_MAIN_RefreshCurrentBoxMonInfo(char *p, int b);
extern void BOX2_SEQ_DeleteB(char *p);
extern void BOX2_UI_ShowWindowB(char *w);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sound;
struct Struct_02025CD0;
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
extern void CURSOR_MOVE_SetState(struct Struct_02025CD0 *obj, u32 state);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern void BOX2_SEQ_SetSlotCharacter(char *w, unsigned item);
extern void BOX2_SEQ_SetActorAnimSeq(char *w, int i, int v);
extern void BOX2_SEQ_CreateHandSlotActorsB(char *w);
extern int BOX2_SEQ_ReturnAfterClear(char *p, int v);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_SEQ_StateExitBox(unsigned char *p);

#define WORK(p) (*(char **)((p) + 0x2C))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
#define ITEM(p) (*(unsigned short *)(WORK(p) + 0xA16C))
#define WIN(p, i) (*(unsigned char *)(WORK(p) + (i) + 0x3DD2))

int BOX2_SEQ_StatePlaceItemB(unsigned char *p)
{
    Entry *o;
    unsigned short item;

    if (BOX2_SEQ_IsActorAnimActive(WORK(p), 10) == 1)
        return 0x49;
    BOX2_SEQ_SetActorAffineMode(WORK(p), 0);
    BOX2_SEQ_SetActorDrawEnable(WORK(p), 10, 0);
    o = *(Entry **)(WORK(p) + 0x60);
    item = BOX2_MAIN_GetPartyValueAt((void ***)p, o->idx, p[0x14], 6, 0);
    BOX2_MAIN_SetBoxValueAt((int)p, o->idx, p[0x14], 6, ITEM(p));
    if (BOX2_MAIN_CanPlaceInBox((void **)p, (void *)BOX2_MAIN_GetMonAt((void ***)p, p[0x14], o->idx)) == 1) {
        BOX2_MAIN_RecalcPartyParam(p, o->idx);
        BOX2_SEQ_ShowSlotIcon(p, p[0x14], o->idx, WIN(p, o->idx));
    }
    BOX2_MAIN_RefreshCurrentBoxMonInfo((char *)p, o->idx);
    ITEM(p) = item;
    BOX2_MAIN_SetBoxValueAt((int)p, p[0x16], p[0x17], 6, ITEM(p));
    if (p[0x17] == 0xFF || p[0x17] == p[0x14]) {
        if (BOX2_MAIN_CanPlaceInBox((void **)p, (void *)BOX2_MAIN_GetMonAt((void ***)p, p[0x14], p[0x16])) == 1) {
            BOX2_MAIN_RecalcPartyParam(p, p[0x16]);
            BOX2_SEQ_ShowSlotIcon(p, p[0x14], p[0x16], WIN(p, p[0x16]));
        }
    }
    if (ITEM(p) == 0) {
        p[0x16] = o->idx;
        BOX2_SEQ_DeleteB((char *)p);
        BOX2_UI_ShowWindowB(WORK(p));
        CURSOR_MOVE_SetCurrent(OBJ(p), p[0x16] - 0x1E);
        BOX2_MAIN_RefreshCurrentBoxMonInfo((char *)p, p[0x16]);
        CURSOR_MOVE_SetState(OBJ(p), 1);
        return 0x46;
    }
    GFL_USE_PlaySeDefaultVolume(0x666);
    BOX2_SEQ_SetSlotCharacter(WORK(p), ITEM(p));
    BOX2_SEQ_SetActorAffineMode(WORK(p), 1);
    BOX2_SEQ_SetActorAnimSeq(WORK(p), 10, 1);
    BOX2_SEQ_SetActorDrawEnable(WORK(p), 10, 1);
    BOX2_SEQ_CreateHandSlotActorsB(WORK(p));
    return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_SEQ_StateExitBox, BOX2_SEQ_ReturnAfterClear((char *)p, 0x4A));
}
