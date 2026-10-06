/*
 * function: func_021624B0
 * address:  0x021624B0
 * packet:   pkt_ov010_021624B0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * blocker: 81 concrete bytes differ; compiled126/original128. Far-offset,
 * counter webs and header store scheduling remain; target has126 code bytes plus padding.
 * checks: 1 own unit_02013EC0 confirms u32 accessor; own archive length/read inputs confirmed, corrected accessor prototype81/126; 2 0216242C/58/5C/78 no parser twin; 3 u16 offset126/150, unsigned x/a81/126; 4 shared enum far-offset and first-field-through-object idioms improved81; 5 refreshed idioms and neighbours, no stack object.
 * search: once300 --types baseline102/128; best55/126 rejected for
 * copy(a->a_@8): a_=a before a is assigned, and type:ret-var(a).
 * Corrected assignment order plus void return yields DIFF113/130.
 * Historical134/129 and128/102 spellings superseded by valid126/81 spelling.
 * evidence: scratchpad/overlay-newpass-20261003-w75/R5/4b0-*.log;
 * emitted baseline agreed with fixed one; search spent, never repeat.
 *
 * wave76: Seven compiles: enum far-offset/raw first header read81/126; enum running offset81/126; zero participates in data pointer118/132; named n0/n2 counters90/122; u16 offset126/150; unsigned x/a81/126; corrected u32 accessor prototype81/126. Final authorized retry exhausted; old permuter300 not repeated.
 * evidence76: scratchpad/overlay-newpass-20261003-w76/R2/; each log awaited to terminal exit.
 *
 * recoup 2026-10-05 (lane E2, wave P16): DIFF 73/128 (compiled 126). Callee types checked: func_02013ECC is
 * sub_02013ECC in unit_02013EC0 (u32 id -> u32), func_020493D4 returns u32, func_0204944C is void; all as declared.
 * Twin search: grep -rl func_020493D4 / func_0204944C / func_02013ECC src/matched/ov: ov010 021695BC (same
 * len/read pair, different fields), ov010 02169A88, 02164890; no parser twin with these constants.
 * New lever that moved the head: the argument 0 is a literal and "off = 0" is written AFTER the
 * func_0204944C call. Then "adds r1,r6" is scheduled early and off shares the register of "a" (movs r6,#0), so
 * bytes 0x00..0x38 match except the register of k. Plain-literal form without the far offset local (members
 * o->size, &o->hdr) matched the head with 52 of 128 bytes right but loses the push r7 frame (sub sp,#4 instead,
 * 102 B off): original holds 0x14 in r7, compiled holds it in r2.
 * Residue: allocator colours of h (orig r3, compiled r1), d (orig r2, compiled r0), and n0 (orig r1,
 * compiled r4); the original keeps k (r4) live through the 0x14 constant, so r7 is chosen for 0x14.
 * Tried, no gain: d typed char *; named 0x14 local; d after the p120 store (96 B); n0 u8-local; size local (122 B);
 * k as int local with (k + 4) grouping (132 B, loads n0 twice); declaration orders (2); pragmas opt_lifetimes,
 * opt_propagation, opt_common_subs, opt_dead_assignments, scheduling, peephole off (none matched).
 * Idioms checked: a-far-byte-offset-in-a-local-loads-the-byte-before-the-stack-variable (no change),
 * a-far-offset-before-the-index-keeps-base-and-index-separate-across-calls (n/a),
 * pointer-sum-with-a-far-offset-associates-differently (h as named pointer local: no change),
 * raw-field-offsets-can-share-a-constant-without-an-enum-local (raw: 102 B, frame lost; enum: 73 B, better),
 * a-pool-address-takes-ip-only-when-the-low-scratch-is-reserved (rotation of roles, same class of residue).
 *
 * final push 2026-10-05 G8L2: DIFF 54/126 (was 73). New lever: group the far offset as (size_offset + 4) for BOTH the
 * header pointer and the first-byte read (`(char *)o + (size_offset + 4)`), so the offset sum is built before the base add
 * as the listing shows (`adds r0,r4,#4; adds r3,r5,r0`); bytes 0x00..0x29 now match exactly, push r7 frame kept.
 * Residue: colours of h (orig r3, compiled r1), d (r2/r0), size (r0/r2), sum (r1/r3) and the 0x14 constant (orig r7,
 * compiled r2); n0 and n2 are read twice (orig once) and k+4 is shared (orig recomputes it before the far byte read).
 * Tried, worse: n0..n3 locals (62/122, k+4 CSE'd), u8/int locals, statement order off-before-store (62, 69),
 * plain struct members o->size/&o->hdr (102, k+4 recomputed as in orig but no r7 frame), off0..off3 separate locals
 * (87 or 102), 4 declaration orders (102), all six per-function pragmas on the plain-member form (102 each),
 * n0 read before h (63). Matched-assembly regex search for `adds rA,rK,#4; adds rB,r5,rA; ldr [rB,rK]`: this function only.
 * Idioms read: of-two-equal-temps-the-later-born-one-gets-the-lower-register,
 * opt-propagation-off-with-named-locals-pins-argument-constants-against-stack-stores (no loops here; no change).
 * pass 2 2026-10-06 P2L46: no gain, best stays 54/126 (40 compiles, 3 rounds). Findings: the original is 128 bytes
 * because the second 0x14 multiply copies n2 into r0; this copy is a post-colouring two-address fixup (seen in matched
 * ov093 021ED4E4, ov170 021EC548), so the whole residue is colouring: the int form colours h and d first (r1/r0),
 * the original colours them last (r3/r2) and puts 0x14 in r7. Probe without the zero local (off = n0 * 0x14) gives
 * the exact head 0x2A..0x3A (h r3, d r2), so the zero web is what pushes h/d into the early set. Record-pointer steps
 * `off = (u32)((T14 *)off + n0)` (T14/T24 = 0x14/0x24-byte structs) give 74/128 with the head exact and the right
 * size, but the zero then folds into `adds r0,r0,#0` and 0x14 takes r6. Tried, no gain: opt_propagation off with
 * sz/char * cursor, opt_common_subs off, off = 0 inside the call argument or before the first step, int off,
 * u16 n locals, d as char * or no d local (97), typed record pointer chain (88), product locals, x reused for the id,
 * statement reorders (107), field read-backs (61). Idioms read: a-record-array-type-multiplies-a-dying-index-into-a-
 * fresh-register, an-integer-table-base-multiplies-into-a-copy-of-the-index, a-compound-product-on-a-byte-offset-local-
 * gives-the-index-the-late-colour, an-early-spilled-multiply-with-a-copy-into-r0-is-base-first-and-a-zero-local-on-the-
 * offset. Research: scratchpad/wD9r/p2_P2L46/research.md.
 * pass 3 2026-10-06 P3L18: no gain, best stays 54/126 (40 compiles, 3 rounds). Tried, no gain: multiply before
 * the c store (one read per count, 62/122; only n2 69/124), off declaration order, off reusing r or x, off = 0
 * at four positions (before calls 75/67, after the call 54), off = 0 as the call argument (67; plain 76), d
 * defined late (97, 96; enum 116), h assigned after the n0 step (97), plain form without h (134), inline
 * helper for the step (zero folds, 87) or for the whole parse (129), buffer pointer local (85/120), size
 * local, p120 store last (60, wrong store order), counts read up front (98), nested block locals, register,
 * unsigned long off, non-const H, u8/u16 n locals, &o->size + 1 for h, separate off0..off3 (87, zero folds).
 * Probes without the p120 or c12 stores keep h/d in r1/r0. Findings: in the plain-member form h is copy-
 * propagated into the first count read ([o, k+4]), which is why the original reads n0 off o; the zero survives
 * as a register only when off has several assignments. The residue stays the early colouring of h/d.
 * Matched-assembly search (`movs rZ,#0` before a call, later `adds rA, rZ, rB`): ov021 021AD82C, ov093
 * 021EDB3C, ov040 021F381C, ov036 021F36C0, no header-parser twin. Research: scratchpad/wD9r/p3_P3L18/research.md.
 * symbols:
 *   func_02013ECC  0x02013ECC  thumb
 *   func_020493D4  0x020493D4  arm
 *   func_0204944C  0x0204944C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
struct ArcFile;

typedef struct {
    u8 n[4];
    u8 data[1];
} H;

typedef struct {
    int pad0;
    struct ArcFile *f4;
    u8 pad8[0xA];
    u16 c12;
    u16 c14;
    u16 c16;
    u16 c18;
    u16 pad1A;
    char *p1C;
    char *p20;
    char *p24;
    char *p28;
    u16 c2C;
    u16 c2E;
    u16 c30;
    u16 c32;
    u8 pad34[0x120 - 0x34];
    char *p120;
    int size;
    H hdr;
} O;

extern unsigned func_02013ECC(unsigned);
extern unsigned func_020493D4(struct ArcFile *, unsigned);
extern void func_0204944C(struct ArcFile *, unsigned, unsigned, unsigned, void *);

void func_021624B0(O *o, int x)
{
    int a;
    unsigned r;
    unsigned d;
    unsigned off;
    const H *h;
    enum { SIZE_OFFSET = 0x124 } size_offset;

    a = func_02013ECC(x);
    r = func_020493D4(o->f4, a);
    size_offset = SIZE_OFFSET;
    func_0204944C(o->f4, a, 0, r, (char *)o + size_offset);
    off = 0;
    h = (const H *)((char *)o + (size_offset + 4));
    d = (unsigned)h + 4;
    o->p120 = (char *)h + *(int *)((char *)o + size_offset);
    o->c12 = *((u8 *)o + (size_offset + 4));
    off += h->n[0] * 0x14;
    o->p1C = (char *)d;
    o->p20 = (char *)(d + off);
    off += h->n[1] * 0x24;
    o->c14 = h->n[1];
    o->p24 = (char *)(d + off);
    o->c16 = h->n[2];
    off += h->n[2] * 0x14;
    o->p28 = (char *)(d + off);
    o->c18 = h->n[3];
    o->c2C = o->c12;
    o->c2E = o->c14;
    o->c30 = o->c16;
    o->c32 = o->c18;
}
