/*
 * function: BTL_MAIN_ResolveIllusionPoke
 * address:  0x021B937C
 * packet:   pkt_ov093_021B937C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_IsIllusionActive  0x021D6C24  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_MAIN_PokeIdToClientIdThunk  0x021B8DDC  thumb  ov093
 *   BTL_POKEPARAM_GetDisplayMon  0x021D5864  thumb  ov093
 *   BTL_SIDE_GetSlotOfClientThunk  0x021B9AF8  thumb  ov093
 *   BTL_SLOT_GetCount  0x021B9B94  thumb  ov093
 *   BTL_SLOT_GetPokeParam  0x021B9C00  thumb  ov093
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct R4;
struct S2;
struct Work;
extern int BTL_POKEPARAM_IsIllusionActive(struct R4 *p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);
extern void *BTL_POKEPARAM_GetDisplayMon(struct Work *p);
extern char *BTL_SIDE_GetSlotOfClientThunk(char *p, int i);
struct Q1;
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
extern void *BTL_POKEPARAM_GetMon(void *m);

u8 *BTL_MAIN_ResolveIllusionPoke(int a, char *b, u8 *c)
{
    u8 *t;
    void *v;
    void *k;
    int e;
    char *g;
    u32 n;
    u32 i;

    if (BTL_POKEPARAM_IsIllusionActive((struct R4 *)c)) {
        e = BTL_MAIN_PokeIdToClientIdThunk(BTL_POKEPARAM_GetPokeId(c));
        k = BTL_POKEPARAM_GetDisplayMon((struct Work *)c);
        g = BTL_SIDE_GetSlotOfClientThunk(b, e);
        n = BTL_SLOT_GetCount((struct Q1 *)g);
        for (i = 0; i < n; i++) {
            t = BTL_SLOT_GetPokeParam((struct S2 *)g, (u8)i);
            v = BTL_POKEPARAM_GetMon(t);
            if (v == k)
                return t;
        }
    }
    return c;
}
