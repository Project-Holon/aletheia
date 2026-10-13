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
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   FLDMMDL_ApplyBurmyFormForPlace  0x0216E62C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u32 f00;
    u8 *f04;
};

extern u32 func_0201AA18(void *party);
extern void *func_0201AB28(void *p, u32 idx);
extern void FLDMMDL_ApplyBurmyFormForPlace(int a, int p, int id);

void EVENT_BATTLE_RETURN_ApplyBurmyForms(struct S *s, void *party, int c)
{
    int i;

    if (*(u32 *)s->f04 - 2 > 1) {
        for (i = 0; i < (int)func_0201AA18(party); i++) {
            if (s->f04[0xc2 + i] != 0) {
                FLDMMDL_ApplyBurmyFormForPlace(s->f00, (int)func_0201AB28(party, i), c);
            }
        }
    }
}
