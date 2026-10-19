/*
 * function: BOX2_SEQ_StateMoveItemB
 * address: 0x021E6C3C
 * packet: pkt_ov170_021E6C3C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_SetSlotActorMode 0x021ECB60 thumb ov170
 *   BOX2_SEQ_DeleteB 0x021EA750 thumb ov170
 *   FILE_UTIL_IsMailItem 0x0202136C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb ov170
 *   BOX2_SEQ_PrintMessageC 0x021EBB28 thumb ov170
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   BOX2_MAIN_RefreshCurrentBoxMonInfo 0x021DEFEC thumb ov170
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb ov170
 */
#include "../include/Obj00000.h"
extern void BOX2_SEQ_SetSlotActorMode(char *w, int i, int f);
extern void BOX2_SEQ_DeleteB(char *p);
extern unsigned FILE_UTIL_IsMailItem(unsigned short v);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
extern void BOX2_SEQ_PrintMessageC(char *p, int b);
typedef unsigned char  u8;
struct Sound;
extern u8 CURSOR_MOVE_GetCurrent(struct Sound *obj);
extern void BOX2_MAIN_RefreshCurrentBoxMonInfo(char *p, int b);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
#define WORK(p) (*(char **)((p) + 0x2C))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
typedef struct { unsigned char pad[0x1C]; unsigned char lo:4; unsigned char hi:4; } Flags;
int BOX2_SEQ_StateMoveItemB(unsigned char *p)
{
    unsigned short *o;
    unsigned char old;
    unsigned short slot, item;
    unsigned char r;
    if (((Flags *)p)->lo == 0)
        ((Flags *)p)->hi = 1;
    o = *(unsigned short **)(WORK(p) + 0x60);
    BOX2_SEQ_SetSlotActorMode(WORK(p), o[0], 0);
    old = p[0x16];
    slot = o[1];
    p[0x16] = o[0];
    BOX2_SEQ_DeleteB((char *)p);
    item = *(unsigned short *)(WORK(p) + 0xA16C);
    *(unsigned short *)(WORK(p) + 0xA16C) = 0;
    if (FILE_UTIL_IsMailItem(item) == 1 && slot != old) {
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_SEQ_PrintMessageC((char *)p, 0x18);
        ((struct Obj00000 *)p)->f28 = 0x44;
        return 6;
    }
    BOX2_SEQ_SetCursorDraw((char **)p, 1);
    r = CURSOR_MOVE_GetCurrent(*(void **)(WORK(p) + 0x70));
    if (r < 0x24)
        BOX2_MAIN_RefreshCurrentBoxMonInfo((char *)p, r);
    BOX2_UI_DeleteSlotObjects((char *)p, 0, 1, 1);
    return 0x40;
}
