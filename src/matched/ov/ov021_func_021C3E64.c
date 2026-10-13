/*
 * function: SODATEYA_ApplyPowerItemRule
 * address:  0x021C3E64
 * packet:   pkt_ov021_021C3E64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   func_02005728  0x02005728  thumb  ov021
 *   sSodateyaPowerItemIds     0x021DA930  data  ov021  a4
 *
 * The flag array at q+0x58 must be a struct member (q->a[ia]); spelled
 * q[0x16 + ia] the compiler folds 0x16 into the index and spills it.
 */

typedef unsigned int u32;

typedef struct { u32 v[6]; } T6;
typedef struct {
    u32 f0[0x16];
    u32 a[6];
    u32 b[6];
    u32 n;
} S;

extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u32 func_02005728(u32 n);
extern const T6 sSodateyaPowerItemIds;

void SODATEYA_ApplyPowerItemRule(u32 *p, S *q)
{
    T6 t;
    int fa;
    int fb;
    int ia;
    int ib;
    u32 a;
    u32 b;
    int i;

    fa = 0;
    fb = 0;
    a = POKE_TOOL_GetPartyValue((void *)p[0], 6, 0);
    b = POKE_TOOL_GetPartyValue((void *)p[1], 6, 0);
    t = sSodateyaPowerItemIds;
    for (i = 0; i < 6; i++) {
        if (a == t.v[i]) {
            fa = 1;
            ia = i;
            break;
        }
    }
    for (i = 0; i < 6; i++) {
        if (b == t.v[i]) {
            fb = 1;
            ib = i;
            break;
        }
    }
    if (fa && fb) {
        if (func_02005728(2) == 0) {
            q->a[ia] = 1;
            q->n++;
        } else {
            q->b[ib] = 1;
            q->n++;
        }
    } else if (fa) {
        q->a[ia] = 1;
        q->n++;
    } else if (fb) {
        q->b[ib] = 1;
        q->n++;
    }
}
