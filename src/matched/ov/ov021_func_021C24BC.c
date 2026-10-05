/*
 * function: func_021C24BC
 * address:  0x021C24BC
 * packet:   pkt_ov021_021C24BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * Unlabelled thumb leaf (push {r4} only), reached through the pool word
 * 0x021C24BD in func_021C24A8. Char-pointer offsets give the same bytes
 * scheduled differently (34 differ); the struct-typed accesses keep the
 * zero-initialiser stores ahead of the loads, as in the original.
 * Addresses are Black-image addresses.
 */

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct {
    int f0;
    Vec v;
} Inner;

typedef struct {
    char pad0[0x20];
    Inner **f20;
    int f24;
    Vec f28;
} Obj;

void func_021C24BC(Obj *p)
{
    Vec o = { 0, 0, 0 };

    o.z = 0x40;
    p->f28.x = o.x + (*p->f20)->v.x;
    p->f28.y = o.y + (*p->f20)->v.y;
    p->f28.z = o.z + (*p->f20)->v.z;
}
