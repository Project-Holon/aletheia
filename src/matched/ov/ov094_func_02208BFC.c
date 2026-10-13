/*
 * function: func_02208BFC
 * address: 0x02208BFC
 * packet: pkt_ov094_02208BFC
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: owner->entries[i] preserves the base/index register ordering;
 *   raw-offset EntryFlags casts and a named raw owner leave four bytes out.
 * symbols:
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   PALANM_RequestFade 0x0202173C thumb
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   d_0220AB4C 0x0220AB4C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { int bits[8]; } Masks;
typedef struct { int health; char pad4[4]; u32 active:1; char padc[0x74]; } EntryFlags;
typedef struct { char pad[0xa8]; EntryFlags entries[8]; } Owner;
typedef struct { Owner *owner; int state, mask, count; } State;
extern const Masks d_0220AB4C;
extern int func_021F86E0(void);
extern void *func_021F86D4(void);
extern int PALANM_RequestFade(void *, u16, u16, s16, u8, u8, u16, void *);
extern u32 PALANM_GetFadeRequestBits(const char *);
void func_02208BFC(void *unused, State *s)
{
    Masks masks = d_0220AB4C;
    int i;
    void *pal;
    switch (s->state) {
    case 0:
        s->mask = 0;
        for (i = 0; i < 8; i++) {
            if (s->owner->entries[i].active && s->owner->entries[i].health > 0)
                s->mask |= masks.bits[i];
        }
        if (s->mask) {
            pal = (void *)func_021F86E0();
            PALANM_RequestFade(pal, 4, s->mask, 0, 0, 8, 16, func_021F86D4());
            s->state = 1;
        }
        break;
    case 1:
        if (!PALANM_GetFadeRequestBits((const char *)func_021F86E0())) {
            pal = (void *)func_021F86E0();
            PALANM_RequestFade(pal, 4, s->mask, 0, 8, 0, 16, func_021F86D4());
            s->state = 2;
        }
        break;
    case 2:
        if (!PALANM_GetFadeRequestBits((const char *)func_021F86E0())) {
            s->count++;
            if (s->count == 3) {
                s->count = 0;
                s->state = 3;
            } else {
                s->state = 0;
            }
        }
        break;
    case 3:
        for (i = 0; i < 8; i++) {
            if (s->owner->entries[i].active)
                break;
        }
        if (i == 8)
            s->state = 0;
        break;
    }
}
