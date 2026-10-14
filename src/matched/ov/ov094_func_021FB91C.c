/*
 * function: BTLV_EFFVM_CmdSetGaugeVisibility
 * address:  0x021FB91C
 * packet:   pkt_ov094_021FB91C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   BTLV_EFFECT_GaugeSetSlotVisible  0x021F81B4  thumb  ov094
 *   BTLV_EFFVM_ResolveBattlerList  0x021FCA04  thumb  ov094
 *   BTLV_EFFECT_GaugeSetSideVisible  0x021F8198  thumb  ov094
 *   BTLV_EFFECT_IsPokeSpriteLoaded  0x021F7F1C  thumb  ov094
 *   BTLV_EFFECT_GetGauge  0x021F86B4  thumb  ov094
 *   BTLV_GAUGE_PlaceSlot  0x022079C0  thumb  ov094
 *
 * The last loop reads the list through `((int *)ids)[i]`. The cast stops
 * the element address folding into sp-relative form, so the compiler hoists
 * `add r6, sp, #0x10` to function entry (ahead of the s spill) and reloads
 * the element after each call, while the case 4 call still takes a fresh
 * `add r2, sp, #0x10`. A `p = ids` pointer local instead CSEs that argument
 * into r6 and leaves 6 bytes out. `pt.x *= -1` and `Pt pt = {0, 0};` in the
 * loop block are required for the rest.
 */
typedef unsigned int u32;

typedef struct {
    char pad[0xdc];
    int fdc;            /* 0xdc */
    char pade0[0x23c - 0xe0];
    int ret;            /* 0x23c */
} State;

typedef struct { short x, y; } Pt;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void BTLV_EFFECT_GaugeSetSlotVisible(u32 a, u32 b);
extern int BTLV_EFFVM_ResolveBattlerList(State *s, int id, int *out);
extern void BTLV_EFFECT_GaugeSetSideVisible(int a, int b);
extern int BTLV_EFFECT_IsPokeSpriteLoaded(int i);
extern int BTLV_EFFECT_GetGauge(void);
extern void BTLV_GAUGE_PlaceSlot(char *p, int i, Pt *pt);

int BTLV_EFFVM_CmdSetGaugeVisibility(void *r, State *s)
{
    int ids2[8];
    int ids[8];
    u32 a;
    u32 b;
    int n;
    int i;

    a = VM_GetU32(r);
    b = VM_GetU32(r);
    if (a <= 1) {
        switch (b) {
        case 3:
            BTLV_EFFECT_GaugeSetSlotVisible(a, s->fdc);
            break;
        case 4:
            n = BTLV_EFFVM_ResolveBattlerList(s, 0x10, ids2);
            if (n != 0) {
                for (i = 0; i < n; i++)
                    BTLV_EFFECT_GaugeSetSlotVisible(a, ids2[n]);
            }
            break;
        default:
            BTLV_EFFECT_GaugeSetSideVisible(a, b);
            break;
        }
    } else {
        n = 0;
        switch (b) {
        case 0:
            for (i = 0; i < 8; i += 2) {
                if (BTLV_EFFECT_IsPokeSpriteLoaded(i)) {
                    ids[n] = i;
                    n++;
                }
            }
            break;
        case 1:
            for (i = 1; i < 8; i += 2) {
                if (BTLV_EFFECT_IsPokeSpriteLoaded(i)) {
                    ids[n] = i;
                    n++;
                }
            }
            break;
        case 2:
            for (i = 0; i < 8; i++) {
                if (BTLV_EFFECT_IsPokeSpriteLoaded(i)) {
                    ids[n] = i;
                    n++;
                }
            }
            break;
        case 3:
            n = 1;
            ids[0] = s->fdc;
            break;
        case 4:
            n = BTLV_EFFVM_ResolveBattlerList(s, 0x10, ids);
            break;
        }
        if (n != 0) {
            for (i = 0; i < n; i++) {
                Pt pt = {0, 0};

                pt.x = (a == 2) ? 0x80 : -0x10;
                if (((int *)ids)[i] & 1)
                    pt.x *= -1;
                BTLV_GAUGE_PlaceSlot((char *)BTLV_EFFECT_GetGauge(), ((int *)ids)[i], &pt);
            }
        }
    }
    return s->ret;
}
