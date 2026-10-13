/*
 * function: EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect5
 * address:  0x021BEC84
 * packet:   pkt_ov021_021BEC84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   EVENT_FIELDMAP_CONTROL_RunWipeInEffect5  0x021BF348  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_GetFadeKind  0x021BEA6C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef unsigned char  u8;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int EVENT_FIELDMAP_CONTROL_RunWipeInEffect5(u32 p0, int *st, u8 *q);
extern int EVENT_FIELDMAP_CONTROL_GetFadeKind(int x);

void *EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect5(void *a, u32 b)
{
    void *t = func_020122C0(a, 0, EVENT_FIELDMAP_CONTROL_RunWipeInEffect5, 0x2c);
    u32 *w = func_020124E8(t);

    w[0] = (u32)a;
    w[1] = b;
    w[2] = 5;
    w[3] = (u32)EVENT_FIELDMAP_CONTROL_GetFadeKind(5);
    return t;
}
