/*
 * function: POKE_REGULATION_CheckParty
 * address:  0x0201A090
 * packet:   pkt_0201A090
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201AA50   0x0201AA50  thumb
 *   func_0200AE54   0x0200AE54  thumb
 *   func_0201AA18   0x0201AA18  thumb
 *   func_0201AB28   0x0201AB28  thumb
 *   POKE_REGULATION_CheckPokemonFlags   0x02019FD0  thumb
 *   POKE_TOOL_GetPartyValue   0x02017E1C  thumb
 *   POKE_REGULATION_FindValidOrder   0x0201A59C  thumb
 *
 * poke_tool.c (wave 13): the party legality check against a rule set.
 * Three parallel six-entry u16 arrays (species, item, form) are collected
 * from the non-egg members; the rule set's queries 2 (minimum count),
 * 7 (duplicate species allowed), 8 (duplicate items allowed) and 0xB/0xC (a
 * required species/form) set bits 0x01/0x08/0x10/0x80 of *mask and the
 * error codes 4/2/3/7, a failing member check gives 5, and when nothing
 * failed POKE_REGULATION_FindValidOrder decides between 0 and 1.
 *
 * WHAT CLOSED IT (docs/notes/POKE_REGULATION_CheckParty.c.txt: 478 against 476, err
 * spilled to sp+8 with a six-register push): the arrays are indexed plainly,
 * `species[i]` -- the note's invented `j = i * 2; species[j >> 1]` was the
 * source of the `lsls/bics` fixups; the compiler itself CSEs `i * 2` into
 * the sp+8 slot.  Then the permuter (hill, one mutation) found the last
 * lever: in the duplicate-item test the mask update comes BEFORE the error
 * code (`*mask |= 0x10; err = 3;`), the opposite of the species test.  That
 * order is what keeps err in r7 for the whole function.
 *
 * EXACT* only because of the two-byte alignment pad at 0x0201A26A; the
 * follower 0x0201A26C is its own labelled EXACT entry.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0201AA50(void *p);
struct Reg;
extern u32 func_0200AE54(struct Reg *p, u32 id);
extern u32   func_0201AA18(void *party);
extern void *func_0201AB28(void *p, u32 idx);
extern int   POKE_REGULATION_CheckPokemonFlags(void *rules, void *mon, u32 *mask);
extern u32   POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
extern int POKE_REGULATION_FindValidOrder(void *a0, void *a1, void *a2);

int POKE_REGULATION_CheckParty(void *rules, void *party, u32 *mask)
{
    u16 species[6];
    u16 item[6];
    u16 form[6];
    int i;
    int total;
    int n;
    int err;
    void *mon;
    int k;
    int want_s, want_f;

    n = 0;
    err = 0;
    if (rules == 0)
        return 0;
    for (i = 0; i < 6; i++) {
        species[i] = 0;
        form[i] = 0;
        item[i] = 0;
    }
    total = func_0201AA50(party);
    if (total < (int)func_0200AE54(rules, 2)) {
        *mask |= 1;
        err = 4;
    }
    for (i = 0; i < (int)func_0201AA18(party); i++) {
        mon = func_0201AB28(party, i);
        if (POKE_REGULATION_CheckPokemonFlags(rules, mon, mask) == 0)
            err = 5;
        if (POKE_TOOL_GetPartyValue(mon, 0x4c, 0) == 0) {
            species[i] = POKE_TOOL_GetPartyValue(mon, 5, 0);
            item[i] = POKE_TOOL_GetPartyValue(mon, 6, 0);
            form[i] = POKE_TOOL_GetPartyValue(mon, 0x6f, 0);
            n += POKE_TOOL_GetPartyValue(mon, 0x9e, 0);
        }
    }
    if ((int)func_0200AE54(rules, 7) == 0 && total > 1) {
        for (i = 0; i < 5; i++) {
            for (k = i + 1; k < 6; k++) {
                if (species[i] == species[k] && species[i] != 0) {
                    err = 2;
                    *mask |= 8;
                }
            }
        }
    }
    if ((int)func_0200AE54(rules, 8) == 0 && total > 1) {
        for (i = 0; i < 5; i++) {
            for (k = i + 1; k < 6; k++) {
                if (item[i] == item[k] && species[i] != 0 && item[i] != 0) {
                    *mask |= 0x10;
                    err = 3;
                }
            }
        }
    }
    want_s = (int)func_0200AE54(rules, 0xb);
    want_f = (int)func_0200AE54(rules, 0xc);
    i = 0;
    if (want_s != 0 && total > 1) {
        for (i = 0; i < 6; i++) {
            if (want_s == species[i] && want_f == form[i])
                break;
        }
    }
    if (i == 6) {
        *mask |= 0x80;
        err = 7;
    }
    if (err == 0 && POKE_REGULATION_FindValidOrder(rules, party, 0) == 0)
        err = 1;
    return err;
}
