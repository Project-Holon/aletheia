/*
 * function: func_021C4CDC
 * address:  0x021C4CDC
 * packet:   pkt_ov021_021C4CDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Copies the owner's current position into map-object slot id.
 *
 * symbols:
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6658  0x021C6658  thumb  ov021
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_021C67F4  0x021C67F4  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { int x, y, z; } V3;

typedef struct {
    u32 *owner;
    u32 f4;
    u32 f8;
    u32 fC;
    u16 id;
} S;

extern u32 func_021ABE18(u32 a);
extern int func_021C6658(u32 a, u32 b);
extern void func_021AC1B8(void *a, V3 *v);
extern void func_021C67F4(u32 o, u16 id);

void func_021C4CDC(void *a, S *s)
{
    u16 id = s->id;
    u32 o = func_021ABE18(*s->owner);
    V3 *dst = (V3 *)func_021C6658(o, id);
    V3 t;

    func_021AC1B8(a, &t);
    *dst = t;
    func_021C67F4(o, id);
}
