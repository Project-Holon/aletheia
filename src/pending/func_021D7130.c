/*
 * function: func_021D7130
 * address:  0x021D7130
 * packet:   pkt_021D7130
 * region:   ov118
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF / WIP (partial reconstruction; full body is 0xB4A bytes)
 *
 * Attempting the big function. The real body is 0xB4A bytes (2890) of code
 * from 0x021D7130 to 0x021D7C7A, an unrolled event/demo state machine of 57
 * guards, each `if (*(u32 *)(this + 0xF2C) == func_021D6734(K)) { ... }`,
 * plus a handful of shared tails. func_021D6734 (0x021D6734) is a two-byte
 * `bx lr` in ov118, so every guard compares the fetched constant against the
 * word at 0xF2C. This file reconstructs the preamble and 16 guards and the
 * guard bodies match the original word for word, but a prefix cannot match
 * the prologue: mwcc colors the whole function globally and, because r6/r7
 * have no live range in a prefix, it emits `push {r3, r4, r5, lr}` and keeps
 * the offset constant in r5 where the original keeps it in r4 and pushes
 * r6/r7. The function is therefore all-or-nothing and is reported as DIFF
 * (compiled 500 bytes against the original's 2890; first bytes diverge at
 * the prologue). Reconstructing it needs the whole body, not a prefix.
 *
 * symbols:
 *   func_021D6734  0x021D6734  thumb  ov118
 *   func_021D6600  0x021D6600  thumb  ov118
 *   func_021D667C  0x021D667C  thumb  ov118
 *   func_021D6EAC  0x021D6EAC  thumb  ov118
 *   func_021D6F0C  0x021D6F0C  thumb  ov118
 *   func_021DFA60  0x021DFA60  thumb  ov119
 *   func_021E3230  0x021E3230  thumb  ov119
 *   func_021E3208  0x021E3208  thumb  ov119
 *
 * The real function is a generated event/demo state machine: 57 guards of
 * the form
 *     if (*(u32 *)(this + 0xF2C) == func_021D6734(K)) { ... }
 * followed by shared tails. This file reconstructs the preamble and the
 * leading chain to probe the codegen.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void func_021DFA60(u32);
extern u32 func_021D6734(u32);
extern void func_021E3230(void *);
extern void func_021E3208(void *, int);
extern void func_02015F50(u32, int, int, int, int);
extern void func_021D6600(void *);
extern void func_02015EA0(u32);
extern void func_020515CC(u32, int, int, void *);
extern void func_021D6EAC(void);
extern void func_021D6F0C(void);

void func_021D7130(void *p)
{
    u8 *this = p;
    func_021DFA60(*(u32 *)(this + 0xF2C));

    if (*(u32 *)(this + 0xF2C) == func_021D6734(0x12D)) {
        func_021E3230(this);
        func_021E3208(this, 4);
    }
    if (*(u32 *)(this + 0xF2C) == func_021D6734(0x2B6)) {
        func_021E3230(this);
        func_021E3208(this, 5);
    }
    if (*(u32 *)(this + 0xF2C) == func_021D6734(1)) {
        func_02015F50(*(u32 *)(this + 0x844), 8, 8, 0, 0xFFFF);
    }
    if (*(u32 *)(this + 0xF2C) == func_021D6734(2)) {
        func_02015F50(*(u32 *)(this + 0x844), 0x10, 0x10, 0, 0xFFFF);
    }
    if (*(u32 *)(this + 0xF2C) == func_021D6734(3)) {
        func_021D667C(this);
        func_021D6600(this);
    }
    if (*(u32 *)(this + 0xF2C) == func_021D6734(4)) {
        func_02015EA0(*(u32 *)(this + 0x844));
    }
    if (*(u32 *)(this + 0xF2C) == func_021D6734(0x356)) {
        func_020515CC(*(u32 *)(*(u32 *)(this + 0xc)), 0xa, 0, this);
    }
    if (*(u32 *)(this + 0xF2C) == func_021D6734(0x65)) {
        func_020515CC(*(u32 *)(*(u32 *)(this + 0xc) + 4), 1, 0, this);
    }
    if (*(u32 *)(this + 0xF2C) == func_021D6734(0x9a)) {
        func_020515CC(*(u32 *)(*(u32 *)(this + 0xc) + 8), 2, 0, this);
    }
    if (*(u32 *)(this + 0xF2C) == func_021D6734(0x356)) {
        func_020515CC(*(u32 *)(*(u32 *)(this + 0xc) + 0x20), 2, 0, this);
    }
    if (*(u32 *)(this + 0xF2C) == func_021D6734(0xe)) {
        func_020515CC(*(u32 *)(*(u32 *)(this + 0xc) + 0xc), 3, 0, this);
    }
    if (*(u32 *)(this + 0xF2C) == func_021D6734(0x483)) {
        func_020515CC(*(u32 *)(*(u32 *)(this + 0xc) + 0x1c), 3, 0, this);
    }
    if (*(u32 *)(this + 0xF2C) == func_021D6734(0x9a)) {
        func_020515CC(*(u32 *)(*(u32 *)(this + 0xc) + 0x10), 4, (int)func_021D6EAC, this);
    }
    if (*(u32 *)(this + 0xF2C) == func_021D6734(0x152)) {
        func_020515CC(*(u32 *)(*(u32 *)(this + 0xc) + 0x14), 5, 0, this);
    }
    if (*(u32 *)(this + 0xF2C) == func_021D6734(0x2BC)) {
        func_020515CC(*(u32 *)(*(u32 *)(this + 0xc) + 0x18), 6, (int)func_021D6F0C, this);
    }
    if (*(u32 *)(this + 0xF2C) == func_021D6734(0x47F)) {
        func_021D6600(this);
    }
}
