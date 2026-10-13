/*
 * function: EVENT_FIELDMAP_CONTROL_CreateSeasonFadeInEventWithCallback
 * address:  0x021BE9A0
 * packet:   pkt_021BE9A0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator with callback, then link-node field setup with two byte fields and
 * two trailing stack arguments.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   EVENT_FIELDMAP_CONTROL_GetFadeKind  0x021BEA6C  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_RunSeasonFadeInWithCallback  0x021BF0E4  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
int EVENT_FIELDMAP_CONTROL_GetFadeKind(int x);
int EVENT_FIELDMAP_CONTROL_RunSeasonFadeInWithCallback(u32 p0, int *st, u8 *q);

void *EVENT_FIELDMAP_CONTROL_CreateSeasonFadeInEventWithCallback(void *p, int a1, int a2, int a3, int a4, int a5)
{
    void *r0v = func_020122C0(p, 0, EVENT_FIELDMAP_CONTROL_RunSeasonFadeInWithCallback, 0x2C);
    int *r4 = func_020124E8(r0v);

    r4[0] = (int)p;
    r4[1] = a1;
    r4[2] = 3;
    ((u8 *)r4)[0x20] = a2;
    ((u8 *)r4)[0x21] = a3;
    r4[3] = (int)EVENT_FIELDMAP_CONTROL_GetFadeKind(r4[2]);
    r4[9] = a4;
    r4[10] = a5;
    return r0v;
}
