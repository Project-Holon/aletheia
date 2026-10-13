/*
 * function: HAND_WAZA_ChatterOnDecideAddSick
 * address:  0x021E12A4
 * packet:   pkt_ov093_021E12A4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Lever: the constant 6 lives in r5 across the calls (movs r5,#6 before the
 * BTL_POKEPARAM_GetMon bl); an int local folds it into each use, an enum local keeps it.
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_SERVER_FLOW_QueryPokeClientFlag  0x021C7ED8  thumb  ov093
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   BTL_CALC_MakeSickContFromKind  0x021D7DC0  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef enum { K_SIX = 6 } K;

extern int BTL_EVENT_GetVar(int key);
struct QF;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern int BTL_SERVER_FLOW_QueryPokeClientFlag(u8 *p, int i);
extern void *BTL_POKEPARAM_GetMon(void *m);
extern void BTL_CALC_MakeSickContFromKind(int a, void *b, void *out);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_ChatterOnDecideAddSick(int unused, void *q, int id)
{
    void *m;
    u32 n;
    K a;
    int b;
    u32 out;

    if (id == BTL_EVENT_GetVar(3)) {
        m = BTL_SERVER_FLOW_GetPokeParam(q, id);
        if (BTL_POKEPARAM_GetSpecies(m) == 0x1b9) {
            n = BTL_SERVER_FLOW_QueryPokeClientFlag(q, id);
            if (n != 0) {
                a = K_SIX;
                BTL_POKEPARAM_GetMon(m);
                if (n > 2)
                    b = 0x1e;
                else
                    b = 10;
                BTL_CALC_MakeSickContFromKind(a, m, &out);
                BTL_EVENT_OverwriteVar(0x1d, a);
                BTL_EVENT_OverwriteVar(0x1e, out);
                BTL_EVENT_OverwriteVar(0x26, b);
            }
        }
    }
}
