/*
 * function: ZUKAN_DETAIL_TOUCHBAR_UpdateInput
 * address: 0x021BDFDC
 * packet: pkt_ov208_021BDFDC
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetRepeat 0x0203633C arm
 *   ZKND_TBAR_GetButtonVisible 0x021BD388 thumb
 *   ZKND_TBAR_GetButtonActorRaw 0x021BD3F8 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId 0x021BDB08 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_GetHeldButtonId 0x021BDB54 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_GetLeftPalette 0x021BE32C thumb
 *   ZUKAN_DETAIL_TOUCHBAR_GetRightPalette 0x021BE378 thumb
 *   ZKND_TBAR_SetButtonAnimSeq 0x021BD368 thumb
 *   func_021BE170 0x021BE170 thumb
 *   func_021BE1BC 0x021BE1BC thumb
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Ov208Slot { int *p; int q; };
struct Ov208Menu {
    char pad0[0x18];
    int mode;
    int f1c;
    char pad20[0x10];
    void *f30;
    char pad34[0x38];
    struct Ov208Slot tab[9];
};
extern u32 KEY_GetTrg(void);
extern u32 KEY_GetRepeat(void);
extern int ZKND_TBAR_GetButtonVisible(void *a, int b);
extern void ZKND_TBAR_GetButtonActorRaw(void *a, int b);
struct State;
extern unsigned ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId(const struct State *p);
extern unsigned ZUKAN_DETAIL_TOUCHBAR_GetHeldButtonId(const struct State *p);
extern u32 ZUKAN_DETAIL_TOUCHBAR_GetLeftPalette(u32 v);
extern u32 ZUKAN_DETAIL_TOUCHBAR_GetRightPalette(u32 v);
extern void ZKND_TBAR_SetButtonAnimSeq(int a, int b, int c);
extern void func_021BE170(struct Ov208Menu *m);
extern void func_021BE1BC(struct Ov208Menu *m);
void ZUKAN_DETAIL_TOUCHBAR_UpdateInput(struct Ov208Menu *m)
{
    u32 sel = 9;
    u32 trg = KEY_GetTrg();
    u32 held = KEY_GetRepeat();
    u32 a;
    u32 b;
    u32 c;
    volatile u32 d; /* volatile on purpose: image spills it to the stack and re-reads it */
    u8 i;
    if (held & 0x20) {
        switch (m->mode) {
        case 0:
            if (ZKND_TBAR_GetButtonVisible(m->f30, *m->tab[3].p))
                sel = 3;
            else
                sel = 4;
            break;
        case 1:
            sel = 6;
            break;
        case 2:
            sel = 5;
            break;
        case 3:
            sel = 4;
            break;
        }
    } else if (held & 0x10) {
        switch (m->mode) {
        case 0:
            sel = 5;
            break;
        case 1:
            sel = 4;
            break;
        case 2:
            if (ZKND_TBAR_GetButtonVisible(m->f30, *m->tab[3].p))
                sel = 3;
            else
                sel = 6;
            break;
        case 3:
            sel = 6;
            break;
        }
    }
    if (sel != 9)
        ZKND_TBAR_GetButtonActorRaw(m->f30, *m->tab[sel].p);
    if ((trg & 0xc0) == 0) {
        if (held & 0x40)
            ZKND_TBAR_GetButtonActorRaw(m->f30, *m->tab[8].p);
        else if (held & 0x80)
            ZKND_TBAR_GetButtonActorRaw(m->f30, *m->tab[7].p);
    }
    a = ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId((const struct State *)m);
    b = ZUKAN_DETAIL_TOUCHBAR_GetHeldButtonId((const struct State *)m);
    if (a != 0) {
        c = ZUKAN_DETAIL_TOUCHBAR_GetLeftPalette(a);
        d = ZUKAN_DETAIL_TOUCHBAR_GetRightPalette(a);
        if (c != 9 && d != 4) {
            for (i = 3; i <= 6; i++)
                ZKND_TBAR_SetButtonAnimSeq((int)m->f30, *m->tab[i].p, i != c);
            m->f1c = d;
            func_021BE170(m);
        }
    }
    if (b != 0) {
        switch (b) {
        case 15:
        case 16:
        case 17:
        case 18:
            func_021BE1BC(m);
            break;
        }
    }
}
