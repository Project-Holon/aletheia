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
 *   func_0201D5C4 0x0201D5C4 thumb
 *   func_0201D5CC 0x0201D5CC thumb
 *   func_0201D670 0x0201D670 thumb
 *   func_0201D5F4 0x0201D5F4 thumb
 *   func_0201D658 0x0201D658 thumb
 *   func_0201D688 0x0201D688 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201EF8C 0x0201EF8C thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201F020 0x0201F020 thumb
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
extern u32 func_0201D5C4(void);
extern u32 func_0201D5CC(const u16 *p);
extern u32 func_0201D670(const u16 *p, u32 i);
extern u32 func_0201D5F4(const u16 *p);
extern u32 func_0201D658(const u16 *p);
extern u16 *func_0201D688(u16 *p);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201EF8C(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201F020(struct WordSet *p, u32 i, u32 v);
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
    tag = func_0201D5C4();
    for (i = 0; i < 8; i++)
        removed[i] = 0;
    p = STRBUF_GetChars(s);
    while (*p != end) {
        if (*p == tag) {
            if (func_0201D5CC(p)) {
                slot = func_0201D670(p, 0);
                if ((u8)func_0201D5F4(p) == 1 && func_0201D658(p) == 14) {
                    for (i = slot + 1; i < 8; i++)
                        removed[i]++;
                }
            }
            p = func_0201D688(p);
        } else
            p++;
    }
    p = STRBUF_GetChars(s);
    while (*p != end) {
        if (*p == tag) {
            if (func_0201D5CC(p)) {
                slot = func_0201D670(p, 0);
                index = slot;
                group = func_0201D5F4(p);
                if (slot >= removed[slot])
                    index = slot - removed[slot];
                if (group == 2) {
                    kind = func_0201D658(p) + 1;
                    func_0201EFA4(w, slot, values[index], kind, 0, 1);
                } else {
                    switch (func_0201D658(p)) {
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
                        func_0201F020(w, slot, values[index]);
                        break;
                    case 6:
                        func_0201EF8C(w, slot, values[index]);
                        break;
                    case 7:
                        func_0201EF34(w, slot, values[index]);
                        break;
                    case 9:
                        func_0201EF40(w, slot, values[index]);
                        break;
                    case 15:
                        func_0201F020(w, slot, values[index]);
                        break;
                    }
                }
            }
            p = func_0201D688(p);
        } else
            p++;
    }
}
