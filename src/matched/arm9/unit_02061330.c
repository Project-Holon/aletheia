/*
 * function: NNS_G2dCallVtableSlot0
 * address:  0x02061330
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * unit:     yes
 *
 * functions:
 *   NNS_G2dCallVtableSlot0  0x02061330  arm
 *   NNS_G2dCallVtableSlot1  0x02061344  arm
 *
 * Two two-argument vtable forwarders, 20 bytes each, no relocations at all.
 * The object at r0 holds a pointer to a table of function pointers at r0[0];
 * the call dispatches through slot 0 (0x02061330) and slot 1 (0x02061344).
 *
 * The tell that the callee takes *two* arguments is the register the loaded
 * pointer lands in.  Written as a one-argument call (`o->vt->f0(o)`) mwcc
 * keeps the function pointer in r1, which is free; the original puts it in
 * r2, which is only necessary when r0 and r1 are both argument registers, so
 * the wrapper forwards its own second parameter.  Same bytes either way for
 * the load pair, four differing bytes for the register choice.
 *
 * The wrapper's own arity is not visible in its body (the caller's r1 is
 * simply passed on), so the two-parameter reading is the one that reproduces
 * the register numbering; the functions are only reachable through a pointer
 * table, so no call site can be consulted.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02061330.c \
 *       --addr 0x02061330 --arm
 *   EXACT, 40 bytes, 2 functions, 0 relocation sites.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef void (*Vfn)(void *self, u32 x);

struct Vt02061330 { Vfn f0; Vfn f1; };
struct Obj02061330 { struct Vt02061330 *vt; };

void NNS_G2dCallVtableSlot0(struct Obj02061330 *o, u32 x)
{
    o->vt->f0(o, x);
}

void NNS_G2dCallVtableSlot1(struct Obj02061330 *o, u32 x)
{
    o->vt->f1(o, x);
}
