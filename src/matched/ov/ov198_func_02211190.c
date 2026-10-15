/*
 * function: B_PLIST_MAIN_PrintRowMessage
 * address: 0x02211190
 * packet: pkt_ov198_02211190
 * region: ov198
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_MAIN_IsBattleSlot 0x02210F04 thumb ov198
 *   B_PLIST_MAIN_IsIndexValid 0x02210F84 thumb ov198
 *   B_PLIST_MAIN_IsIndexInParty 0x02210F98 thumb ov198
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_SetSlotMonSpecies 0x0201EEF4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 */
#include "../include/Obj01431.h"
#include "../include/Obj08366.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *, int);
extern u32 B_PLIST_MAIN_IsBattleSlot(u32, u32);
extern int B_PLIST_MAIN_IsIndexValid(char **, unsigned);
struct MsgBank;
struct U16Vec;
struct WordSet;
extern unsigned B_PLIST_MAIN_IsIndexInParty(u8 *p, int index);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void WORDSET_SetSlotMonSpecies(struct WordSet *p, u32 i, void *mon);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
int B_PLIST_MAIN_PrintRowMessage(u8 *p)
{
    u8 *row;
    int idx;
    void *text;
    idx = B_PLIST_MAIN_GetOrderIndex(p, (*(u8 **)p)[0x20]);
    row = p + 4 + idx * 0x4c;
    if (B_PLIST_MAIN_IsBattleSlot((u32)p, idx) == 1) {
        text = func_02045EC0(((struct Obj01431 *)p)->f1EA0, 0x5a);
        WORDSET_CopyTaggedText(((struct Obj01431 *)p)->f1EA4, ((struct Obj01431 *)p)->f1EA8, text);
        STRBUF_Delete(text);
        return 0;
    }
    if (B_PLIST_MAIN_IsIndexValid((char **)p, (*(u8 **)p)[0x20]) == 0) {
        if (B_PLIST_MAIN_IsIndexValid((char **)p, idx) == 1)
            text = func_02045EC0(((struct Obj01431 *)p)->f1EA0, 0x6b);
        else
            text = func_02045EC0(((struct Obj01431 *)p)->f1EA0, 0x6a);
        WORDSET_SetSlotMonSpecies(((struct Obj01431 *)p)->f1EA4, 0, ((struct Obj08366 *)row)->f0);
        WORDSET_CopyTaggedText(((struct Obj01431 *)p)->f1EA4, ((struct Obj01431 *)p)->f1EA8, text);
        STRBUF_Delete(text);
        return 0;
    }
    if (B_PLIST_MAIN_IsIndexInParty(p, (*(u8 **)p)[0x20]) == 1) {
        text = func_02045EC0(((struct Obj01431 *)p)->f1EA0, 0x56);
        WORDSET_SetSlotMonSpecies(((struct Obj01431 *)p)->f1EA4, 0, ((struct Obj08366 *)row)->f0);
        WORDSET_CopyTaggedText(((struct Obj01431 *)p)->f1EA4, ((struct Obj01431 *)p)->f1EA8, text);
        STRBUF_Delete(text);
        return 0;
    }
    if (((struct Obj08366 *)row)->f10 != 0) {
        text = func_02045EC0(((struct Obj01431 *)p)->f1EA0, 0x56);
        WORDSET_SetSlotMonSpecies(((struct Obj01431 *)p)->f1EA4, 0, ((struct Obj08366 *)row)->f0);
        WORDSET_CopyTaggedText(((struct Obj01431 *)p)->f1EA4, ((struct Obj01431 *)p)->f1EA8, text);
        STRBUF_Delete(text);
        return 0;
    }
    return 1;
}
