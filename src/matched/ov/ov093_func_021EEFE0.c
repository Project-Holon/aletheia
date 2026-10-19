/*
 * function: BTL_MSG_ExpandTags
 * address: 0x021EEFE0
 * packet: pkt_ov093_021EEFE0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Two passes over message tags: count removed slots, then install values.
 * A u8 kind local narrows before argument setup; const values schedules
 * the index shift ahead of the last outgoing argument store.
 * symbols:
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   PRINTSYS_GetTagChar 0x0201D5C4 thumb
 *   PRINTSYS_IsWordSlotTag 0x0201D5CC thumb
 *   PRINTSYS_GetTagParam 0x0201D670 thumb
 *   PRINTSYS_GetTagGroup 0x0201D5F4 thumb
 *   PRINTSYS_GetTagKind 0x0201D658 thumb
 *   PRINTSYS_SkipTag 0x0201D688 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_SetSlotFromMsgB6 0x0201EF8C thumb
 *   WORDSET_SetSlotFromMsgCB 0x0201EF34 thumb
 *   WORDSET_SetSlotFromMsg36 0x0201EF40 thumb
 *   WORDSET_SetSlotFromMsgC7 0x0201F020 thumb
 *   BTL_MSG_SetPokeName 0x021EED00 thumb ov093
 *   BTL_MSG_SetPokeSpecies 0x021EED24 thumb ov093
 *   BTL_MSG_SetPokeNickname 0x021EED48 thumb ov093
 *   BTL_MSG_SetClientValue 0x021EED6C thumb ov093
 *   BTL_MSG_SetClientName 0x021EED90 thumb ov093
 *   gBtlMsgFlags 0x021F63D8 data ov093 a4
 */

#include "../include/G_H.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern struct H gBtlMsgFlags;
extern u16 STRBUF_GetEosChar(void);
struct U16Vec;
struct WordSet;
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern u32 PRINTSYS_GetTagChar(void);
extern u32 PRINTSYS_IsWordSlotTag(const u16 *p);
extern u32 PRINTSYS_GetTagParam(const u16 *p, u32 i);
extern u32 PRINTSYS_GetTagGroup(const u16 *p);
extern u32 PRINTSYS_GetTagKind(const u16 *p);
extern u16 *PRINTSYS_SkipTag(u16 *p);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_SetSlotFromMsgB6(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_SetSlotFromMsgCB(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_SetSlotFromMsg36(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_SetSlotFromMsgC7(struct WordSet *p, u32 i, u32 v);
extern void BTL_MSG_SetPokeName(u8 a, u32 b);
extern void BTL_MSG_SetPokeSpecies(u8 a, u32 b);
extern void BTL_MSG_SetPokeNickname(u8 a, u8 b);
extern void BTL_MSG_SetClientValue(void *w, u8 i, u8 a);
extern void BTL_MSG_SetClientName(void *w, u8 i, u8 a);

void BTL_MSG_ExpandTags(void *s, const u32 *values, void *w)
{
    u16 end;
    u32 tag;
    u8 removed[8];
    u16 *p;
    u32 i;
    u32 slot;
    u32 index;
    u8 group;
    u8 kind;
    end = STRBUF_GetEosChar();
    tag = PRINTSYS_GetTagChar();
    for (i = 0; i < 8; i++)
        removed[i] = 0;
    p = STRBUF_GetChars(s);
    while (*p != end) {
        if (*p == tag) {
            if (PRINTSYS_IsWordSlotTag(p)) {
                slot = PRINTSYS_GetTagParam(p, 0);
                if ((u8)PRINTSYS_GetTagGroup(p) == 1 && PRINTSYS_GetTagKind(p) == 14) {
                    for (i = slot + 1; i < 8; i++)
                        removed[i]++;
                }
            }
            p = PRINTSYS_SkipTag(p);
        } else
            p++;
    }
    p = STRBUF_GetChars(s);
    while (*p != end) {
        if (*p == tag) {
            if (PRINTSYS_IsWordSlotTag(p)) {
                slot = PRINTSYS_GetTagParam(p, 0);
                index = slot;
                group = PRINTSYS_GetTagGroup(p);
                if (slot >= removed[slot])
                    index = slot - removed[slot];
                if (group == 2) {
                    kind = PRINTSYS_GetTagKind(p) + 1;
                    WORDSET_SetSlotNumber(w, slot, values[index], kind, 0, 1);
                } else {
                    switch (PRINTSYS_GetTagKind(p)) {
                    case 14:
                        BTL_MSG_SetClientValue(w, slot, values[index]);
                        break;
                    case 0:
                        BTL_MSG_SetClientName(w, slot, values[index]);
                        break;
                    case 2:
                        if (gBtlMsgFlags.f1a == 0)
                            BTL_MSG_SetPokeName(values[index], slot);
                        else
                            BTL_MSG_SetPokeSpecies(values[index], slot);
                        break;
                    case 12:
                        BTL_MSG_SetPokeSpecies(values[index], slot);
                        break;
                    case 1:
                        BTL_MSG_SetPokeNickname(values[index], slot);
                        break;
                    case 3:
                        WORDSET_SetSlotFromMsgC7(w, slot, values[index]);
                        break;
                    case 6:
                        WORDSET_SetSlotFromMsgB6(w, slot, values[index]);
                        break;
                    case 7:
                        WORDSET_SetSlotFromMsgCB(w, slot, values[index]);
                        break;
                    case 9:
                        WORDSET_SetSlotFromMsg36(w, slot, values[index]);
                        break;
                    case 15:
                        WORDSET_SetSlotFromMsgC7(w, slot, values[index]);
                        break;
                    }
                }
            }
            p = PRINTSYS_SkipTag(p);
        } else
            p++;
    }
}
