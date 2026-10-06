/*
 * function: func_0216628C
 * address: 0x0216628C
 * packet: pkt_ov010_0216628C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * closed 2026-10-05: the unlabelled leaves it calls are now matched files, so every relocation resolves.
 *
 * Maps the slot's kind (0..3, via the 0x0200E184 thunk) to a new kind,
 * asks func_0200E164 for a free slot, and moves the word at obj[slot]
 * there; kind 3 also runs func_0200E27C on it. Returns 0 on failure.
 *
 * 2026-10-05 (P25L5): all 128 bytes match. The word move is a one-word
 * struct copy (W, lever "one-word structs for word copies"); the plain
 * u32 copy gave 8 bytes off (cmp r5,#3 after the str, dst*4 in r0).
 * Only blocker: func_0200E184 is a Thumb veneer (ldr r3,[pc]; bx r3) to
 * the real function at 0x0200E0BC (44 bytes, maps a value to 0..3 by a
 * 4-entry threshold table). It has no witness outside this function, so
 * the relocation stays unresolved. No C can express the veneer; the
 * integrator should seed a label or witness for 0x0200E184.
 * Tried and inert (8 bytes off): raw byte offsets, u16 dst (31 off),
 * const callee proto, u8 obj, u8 kind, inline copy helper, byte offset
 * locals, per-arm store (45 off), each pragma (scheduling, peephole,
 * opt_propagation, opt_common_subs, opt_lifetimes, opt_dead_assignments).
 *
 * symbols:
 *   func_0200E184  0x0200E184  thumb
 *   func_0200E164  0x0200E164  thumb
 *   func_0200E06C  0x0200E06C  thumb
 *   func_0200E27C  0x0200E27C  thumb
 *   func_0200E024  0x0200E024  thumb
 *   func_0200E18C  0x0200E18C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 w;
} W;

extern u32 func_0200E184(u32 slot);
extern u32 func_0200E164(u32 *obj, u32 kind);
extern void func_0200E06C(char *p);
extern void func_0200E27C(u8 *obj, int idx);
extern void func_0200E024(void *obj);
extern void func_0200E18C(u32 *obj, u32 slot);

int func_0216628C(u32 *obj, u32 slot)
{
    u32 kind;
    u32 dst;

    switch (func_0200E184(slot)) {
    case 0:
        kind = 2;
        break;
    case 1:
        kind = 3;
        break;
    case 2:
        kind = 0;
        break;
    case 3:
        kind = 1;
        break;
    default:
        return 0;
    }
    dst = func_0200E164(obj, kind);
    if (dst == 0xFFFF)
        return 0;
    func_0200E06C((char *)obj);
    ((W *)obj)[dst] = ((W *)obj)[slot];
    if (kind == 3)
        func_0200E27C((u8 *)obj, (u16)dst);
    func_0200E024(obj);
    func_0200E18C(obj, slot);
    return 1;
}
