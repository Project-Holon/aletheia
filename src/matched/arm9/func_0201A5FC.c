/*
 * function: POKE_REGULATION_CheckOrder
 * address:  0x0201A5FC
 * packet:   pkt_0201A5FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   REGULATION_GetRuleValue   0x0200AE54  thumb
 *   POKEPARTY_GetCount   0x0201AA18  thumb
 *   POKEPARTY_GetMember   0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue   0x02017E1C  thumb
 *   POKE_REGULATION_AdjustLevel   0x0201A26C  thumb
 *   POKE_REGULATION_CheckPokemon   0x02019DA4  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_CheckOrder.c  *       --func POKE_REGULATION_CheckOrder --addr 0x0201A5FC --cc 1.1p1 --thumb
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Reg;
extern u32 REGULATION_GetRuleValue(struct Reg *p, u32 id);
extern u32 POKEPARTY_GetCount(void *a1);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u32 POKE_REGULATION_AdjustLevel(void *a0, u32 a1);
extern int POKE_REGULATION_CheckPokemon(void *a0, void *a1);

int POKE_REGULATION_CheckOrder(void *a0, void *a1, u8 *a2, char *a3, u32 *a4)
{
    u8 count = 0;
    u32 arr5c[6] = {0};
    u32 arr44[6] = {0};
    u32 arr2c[6] = {0};
    u8 i;
    int flag;
    u32 acc;
    void *p;
    u32 v18;
    u32 v14;
    u32 v10;
    u8 n;
    u8 j;
    u32 v6;
    u32 k1;
    u8 k;
    u32 k2;
    u32 r;
    int found;

    acc = 0;
    v10 = (u32)(int)REGULATION_GetRuleValue(a0, (int)6);

    if (a3 != 0)
        *a3 = 0;
    if (a4 != 0)
        *a4 = 0;

    for (i = 0; i < 6; i++) {
        if (a2[i] == 0)
            continue;
        n = (u8)(a2[i] - 1);
        if ((int)n >= (int)POKEPARTY_GetCount(a1))
            continue;
        p = POKEPARTY_GetMember(a1, n);
        v18 = POKE_TOOL_GetPartyValue(p, 5, 0);
        v6 = POKE_TOOL_GetPartyValue(p, 6, 0);
        v14 = (u32)POKE_REGULATION_AdjustLevel(a0, POKE_TOOL_GetPartyValue(p, 0x9e, 0));
        r = POKE_REGULATION_CheckPokemon(a0, p);
        if (r != 0) {
            if (a4 != 0)
                *a4 |= r;
            continue;
        }
        flag = 1;
        for (j = 0; j < count; j++) {
            if ((int)REGULATION_GetRuleValue(a0, (int)7) == 0 && v18 == arr5c[j]) {
                flag = 0;
                if (a4 != 0)
                    *a4 |= 8;
                break;
            }
            if ((int)REGULATION_GetRuleValue(a0, (int)8) == 0 && v6 != 0 && v6 == arr2c[j]) {
                flag = 0;
                if (a4 != 0)
                    *a4 |= 0x10;
                break;
            }
        }
        if (flag == 0)
            continue;
        if (v10 != 0 && (u32)(acc + v14) > v10) {
            if (a4 != 0)
                *a4 |= 0x100;
            continue;
        }
        if (a3 != 0)
            a3[count] = (char)(n + 1);
        arr5c[count] = v18;
        arr44[count] = POKE_TOOL_GetPartyValue(p, 0x6f, 0);
        arr2c[count] = v6;
        acc = (u16)(acc + (u16)v14);
        count = (u8)(count + 1);
        if ((int)count < (int)REGULATION_GetRuleValue(a0, (int)3))
            continue;
        if (a4 != 0 && count < 6 && a2[count] != 0)
            *a4 |= 1;
        break;
    }

    if ((int)count >= (int)REGULATION_GetRuleValue(a0, (int)2)) {
        k1 = (u32)(int)REGULATION_GetRuleValue(a0, (int)0xb);
        found = 1;
        if (k1 != 0) {
            k2 = (u32)(int)REGULATION_GetRuleValue(a0, (int)0xc);
            found = 0;
            for (k = 0; k < count; k++) {
                if (k1 == arr5c[k] && k2 == arr44[k]) {
                    found = 1;
                    break;
                }
            }
        }
        if (found == 1)
            return 1;
        if (a4 != 0)
            *a4 |= 0x80;
    } else {
        if (a4 != 0)
            *a4 |= 1;
    }
    return 0;
}
