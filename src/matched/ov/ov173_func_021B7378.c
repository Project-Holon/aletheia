/*
 * function: POKE_SUMMARY_MAIN_SetTextByKind
 * address: 0x021B7378
 * packet: pkt_ov173_021B7378
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORDSET_SetSlotMonNickname 0x0201EEF4 thumb
 *   WORDSET_SetSlotFromMsgCB 0x0201EF34 thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   POKE_SUMMARY_MAIN_GetRecordWord 0x021B7438 thumb ov173
 *   POKE_SUMMARY_MAIN_GetMoveWord 0x021B7448 thumb ov173
 *   func_02045EC0 0x02045EC0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   d_021B8350 0x021B8350 data a4
 */
#include "../include/Obj00544.h"
#include "../include/Obj24172.h"
#include "../include/Obj24173.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void WORDSET_SetSlotMonNickname(struct WordSet *p, u32 i, void *mon);
extern void WORDSET_SetSlotFromMsgCB(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern u16 POKE_SUMMARY_MAIN_GetRecordWord(char **);
extern unsigned short POKE_SUMMARY_MAIN_GetMoveWord(int *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern const u32 d_021B8350[][11];
void POKE_SUMMARY_MAIN_SetTextByKind(char *p, u32 kind)
{
    void *str;
    switch (kind) {
    case 0: WORDSET_SetSlotMonNickname(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0); break;
    case 1: WORDSET_SetSlotFromMsgCB(((struct Obj00544 *)p)->f48, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)p)); break;
    case 2: WORDSET_SetSlotMonNickname(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0); break;
    case 3:
        WORDSET_SetSlotMonNickname(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0);
        WORDSET_SetSlotFromMsgCB(((struct Obj00544 *)p)->f48, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)p)); break;
    case 4:
        WORDSET_SetSlotMonNickname(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0);
        WORDSET_SetSlotFromMsgCB(((struct Obj00544 *)p)->f48, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)p)); break;
    case 5:
        WORDSET_SetSlotMonNickname(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0);
        WORDSET_SetSlotFromMsgCB(((struct Obj00544 *)p)->f48, 1, POKE_SUMMARY_MAIN_GetMoveWord((int *)p)); break;
    case 6:
        WORDSET_SetSlotMonNickname(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0);
        WORDSET_SetSlotFromMsgCB(((struct Obj00544 *)p)->f48, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)p)); break;
    case 7: WORDSET_SetSlotFromMsgCB(((struct Obj00544 *)p)->f48, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)p)); break;
    case 8:
        WORDSET_SetSlotMonNickname(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0);
        WORDSET_SetSlotFromMsgCB(((struct Obj00544 *)p)->f48, 1, POKE_SUMMARY_MAIN_GetRecordWord((char **)p)); break;
    case 9: WORDSET_SetSlotMyStatus(((struct Obj00544 *)p)->f48, 2, (void *)(((struct Obj24172 *)(*(char * *)&((struct Obj00544 *)p)->f0))->f4)); break;
    case 10: WORDSET_SetSlotFromMsgCB(((struct Obj00544 *)p)->f48, 0, POKE_SUMMARY_MAIN_GetMoveWord((int *)p)); break;
    }
    str = func_02045EC0(((struct Obj00544 *)p)->f44, d_021B8350[((struct Obj24173 *)(*(char * *)&((struct Obj00544 *)p)->f0))->f19][kind]);
    WORDSET_CopyTaggedText(((struct Obj00544 *)p)->f48, ((struct Obj00544 *)p)->f4C, str);
    STRBUF_Delete(str);
}
