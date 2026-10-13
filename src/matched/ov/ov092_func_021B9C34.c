/*
 * function: EVENT_BATTLE_RETURN_ApplyBurmyForms
 * address:  0x021B9C34
 * packet:   pkt_ov092_021B9C34
 * region:   ov092
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   FLDMMDL_ApplyBurmyFormForPlace  0x0216E62C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u32 f00;
    u8 *f04;
};

extern u32 POKEPARTY_GetCount(void *party);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void FLDMMDL_ApplyBurmyFormForPlace(int a, int p, int id);

void EVENT_BATTLE_RETURN_ApplyBurmyForms(struct S *s, void *party, int c)
{
    int i;

    if (*(u32 *)s->f04 - 2 > 1) {
        for (i = 0; i < (int)POKEPARTY_GetCount(party); i++) {
            if (s->f04[0xc2 + i] != 0) {
                FLDMMDL_ApplyBurmyFormForPlace(s->f00, (int)POKEPARTY_GetMember(party, i), c);
            }
        }
    }
}
