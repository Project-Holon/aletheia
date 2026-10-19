/*
 * function: ITEMMENU_PrintItemList
 * address:  0x021BA218
 * packet:   pkt_ov070_021BA218
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * lever:    `color` is a u16 local; as int the stack argument to
 *           PRINTSYS_PrintColor gains an lsls/lsrs #16 pair.
 *
 * symbols:
 *   ITEMMENU_GetItemCount  0x021B61C8  thumb  ov070
 *   ITEMMENU_FlushWindowAt  0x021BB724  thumb  ov070
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   FILE_UTIL_CreateItemArcHandle  0x02020F14  thumb
 *   ITEMMENU_GetSlot  0x021B616C  thumb  ov070
 *   FILE_UTIL_LoadArcMember  0x02020F20  thumb
 *   FILE_UTIL_GetItemRecordParam  0x02021014  thumb
 *   d_021BBA79     0x021BBA79  data  ov070  a1
 *   ITEMMENU_GetRowColorKind  0x021BA1D0  thumb  ov070
 *   BMP_Clear  0x02043B5C  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   FILE_UTIL_GetMachineMove  0x020212B0  thumb
 *   ITEMMENU_RegisterItemName  0x021B61F4  thumb  ov070
 *   WORDSET_SetSlotFromMsgCB  0x0201EF34  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   FILE_UTIL_GetMachineIndex  0x02021350  thumb
 *   FILE_UTIL_GetId  0x0202130C  thumb
 *   ITEMMENU_IsItemRegistered  0x021B83A0  thumb  ov070
 *   func_020307B0  0x020307B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */
#include "../include/Obj01514.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef short s16;

extern int ITEMMENU_GetItemCount(u8 *p);
extern void ITEMMENU_FlushWindowAt(void **p);
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec;
struct WordSet;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32);
extern void *FILE_UTIL_CreateItemArcHandle(u32 a);
extern void *ITEMMENU_GetSlot(u8 *p, int i);
extern int FILE_UTIL_LoadArcMember(int h, int id, u16 heap);
extern u32 FILE_UTIL_GetItemRecordParam(struct Rec *p, u32 sel);
extern const u8 d_021BBA79[];
extern int ITEMMENU_GetRowColorKind(int);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u16 FILE_UTIL_GetMachineMove(u16 id);
extern void ITEMMENU_RegisterItemName(u8 *p, int a, unsigned int b);
extern void WORDSET_SetSlotFromMsgCB(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern u8 FILE_UTIL_GetMachineIndex(u16 id);
extern u32 FILE_UTIL_GetId(u32 id);
extern int ITEMMENU_IsItemRegistered(char *p, int value);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(int);

void ITEMMENU_PrintItemList(char *p)
{
    int h;
    int i;
    int idx;
    u16 *e;
    int rec;
    u32 kind;
    u16 color;
    u16 r;
    u32 w;

    if (ITEMMENU_GetItemCount((u8 *)p) == 0) {
        ITEMMENU_FlushWindowAt((void **)(p + 0x774));
    } else {
        w = ((struct Obj01514 *)p)->f774;
        BMP_WIN_ClearScreen((struct Descriptor *)w);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)w));
    }
    if (((struct Obj01514 *)p)->f818 == ((struct Obj01514 *)p)->f814) {
        return;
    }
    h = (int)FILE_UTIL_CreateItemArcHandle(((struct Obj01514 *)p)->f544);
    for (i = 0; i < 8; i++) {
        *(u32 *)(p + i * 4 + 0x654) = 0;
        idx = ((struct Obj01514 *)p)->f814 + i;
        if (idx < 0) {
            continue;
        }
        e = ITEMMENU_GetSlot((u8 *)p, idx);
        if (e == 0 || *e == 0) {
            continue;
        }
        rec = FILE_UTIL_LoadArcMember(h, *e, ((struct Obj01514 *)p)->f544);
        kind = FILE_UTIL_GetItemRecordParam((struct Rec *)rec, 0xf);
        if (d_021BBA79[i] == 0) {
            if (ITEMMENU_GetRowColorKind(*e) == 1) {
                color = 0x18AD;
            } else {
                color = 0x82D;
            }
        } else {
            if (ITEMMENU_GetRowColorKind(*e) == 1) {
                color = 0x20ED;
            } else {
                color = 0x106D;
            }
        }
        BMP_Clear((struct CharBuf *)(*(u32 *)(p + i * 4 + 0x614)), 0xd);
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj01514 *)p)->f51C), 0x82, (void *)(((struct Obj01514 *)p)->f524));
        r = FILE_UTIL_GetMachineMove(*e);
        if (r == 0) {
            ITEMMENU_RegisterItemName((u8 *)p, 0, *e);
        } else {
            WORDSET_SetSlotFromMsgCB((struct WordSet *)(((struct Obj01514 *)p)->f520), 0, r);
        }
        WORDSET_CopyTaggedText((struct WordSet *)(((struct Obj01514 *)p)->f520), (void *)(((struct Obj01514 *)p)->f528), (void *)(((struct Obj01514 *)p)->f524));
        PRINTSYS_PrintColor((void *)(*(u32 *)(p + i * 4 + 0x614)), 0, 0, (void *)(((struct Obj01514 *)p)->f528), (void *)(((struct Obj01514 *)p)->f530), color);
        if (kind == 4) {
            *(u32 *)(p + i * 4 + 0x654) = 4;
        } else if (kind == 5) {
            *(u32 *)(p + i * 4 + 0x654) = 5;
        } else if (kind == 1) {
            *(u32 *)(p + i * 4 + 0x654) = 6;
        } else if (FILE_UTIL_GetMachineIndex(*e) != 0xff) {
            *(u32 *)(p + i * 4 + 0x654) = 8;
        } else if (FILE_UTIL_GetId(*e) != 0xff) {
            *(u32 *)(p + i * 4 + 0x654) = 7;
        } else if (FILE_UTIL_GetItemRecordParam((struct Rec *)rec, 4) == 0) {
            *(u32 *)(p + i * 4 + 0x654) = 3;
        } else if (ITEMMENU_IsItemRegistered(p, *e) == 0) {
            *(u32 *)(p + i * 4 + 0x654) = 2;
        } else {
            *(u32 *)(p + i * 4 + 0x654) = 1;
        }
        func_020307B0((void *)rec);
    }
    ARC_TOOL_DeleteHandle(h);
    ((struct Obj01514 *)p)->f83C = 1;
}
