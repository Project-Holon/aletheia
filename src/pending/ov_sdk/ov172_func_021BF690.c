/*
 * function: func_021BF690
 * address:  0x021BF690
 * packet:   pkt_ov172_021BF690
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * 2026-10-01 (lane02): 964 B / 726 -> 984/984 B / 434 concrete. Size closed by:
 *   (1) the 9-bit walk caches bits/byte in locals `s`/`t` (DWARF names; the
 *   image keeps them in lr/r4 and stores bits each pass); (2) `bcode2.bits
 *   -= 9` after the 9-bit peek; (3) the post-walk checks are one inline
 *   `if (k > 16 || v+k < 0 || v+k+0x46 >= 0x1800) {err; return 0;}` and each
 *   case ends `val = jw[idx]; break;` (cross-jumped tail, default returns
 *   val); (4) the first section (p1/p2 set, 8-bit refill, fast path) goes
 *   through a `BitState *bc = &bcode2` pointer while the err stores name
 *   bcode2 (the image reloads &bcode2 for err while r4 holds the base), a
 *   stand-in for what is likely an inline helper's pointer parameter. Residue:
 *   colouring (v lr vs r5, pooled 1 vs 0 in r3) and loop 2 still reloads.
 *   Moving loop 2 onto bc as well regressed (976/768).
 *
 * blocker:  wave8 second retry: 964 of 984 (was 896).  Two real levers
 *           landed: (1) bcode2.byte is signed (`asr`, not `lsr`, on the peek
 *           shift) and (2) the switch arms now write the bounds check + err
 *           return out inline in each case with only the *success* load
 *           shared (`break;` then one `return jw[idx];`), matching the
 *           original's per-arm err copies.  Still 20 B short and the
 *           callee-saved assignment is unresolved (this C gets v=r8,
 *           bcode2=sl; original holds v=r5, bcode2=r4/reloded r3).  The
 *           remaining shortfall is the allocator merging the per-arm err
 *           blocks / sharing more than the original.  Not EXACT.
 *
 * old-blocker:  full reconstruction; compiled 896 of 984 bytes.  The two refill
 *           sites (bits<8 at the top, bits<9 in the 9-bit walk) are emitted
 *           as two separate straight-line copies in the original but the
 *           front end here cross-jumps/merges them, and the callee-saved
 *           assignment differs (original holds v in r5 and bcode2 in r4,
 *           this C gets v in r8 and bcode2 in sl).  `bcode2.byte` is signed
 *           (original `asr`, not `lsr`, on the peek shift).  Needs register
 *           pinning through local declaration order and forcing the refill
 *           duplication; not reached in this pass.
 *           wave8 retry: aliasing global as first-declared local pointer
 *           `BitState *bc = &bcode2;` did NOT pin bcode2 to r4 (went r7) and
 *           regressed to 884 B/746 sites; moving the `v` declaration to last
 *           was byte-identical.  Allocator pushes the two long-lived values
 *           (bcode2, v) to r8/sl by use density, not declaration order.
 *
 * sdk:      hloadbit (libssp.TWL.HYB.a jpegdec.o)
 *
 * Bit/Huffman reader for one coefficient table.  ntbl[n] is the byte offset
 * of table n inside jw; bcode2.p1 and bcode2.p2 are both pointed at
 * jw + ntbl[n].  p1 is read as a signed 16-bit differential table, p2 as a
 * 32-bit table.  A first 8-bit lookup at jw[nb+0xae+peek] gives the fast
 * path (its value is the bit count to consume, its partner at
 * jw[nb+0x1ae+peek] is the result byte).  A zero there switches to the
 * 9-bit Huffman walk bounded by p2[0x1a] and p2[r8+0x11], ending at the
 * case-constant offset (0x14/0x38/0x14c/0x170) into jw.
 *
 * symbols:
 *   ntbl   0x021C725C  data
 *   jw     0x021C959C  data
 *   bcode2 0x021C88F0  data
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;

typedef struct {
    s32 byte;      /* +0x00 current byte register */
    u32 pad04;     /* +0x04 */
    u32 limit;     /* +0x08 input size */
    u32 esc;       /* +0x0c escape flag */
    s32 bits;      /* +0x10 bits available */
    u32 pad14;     /* +0x14 */
    u8 *p1;        /* +0x18 jw + ntbl[n] */
    s32 err;       /* +0x1c error flag */
    u8 *p2;        /* +0x20 jw + ntbl[n] */
} BitState;

extern int ntbl[4];
extern u8 jw[6144];
extern BitState bcode2;

int func_021BF690(u8 *b, int *p, int n)
{
    int v;
    int i;
    u32 c;
    s32 bits;
    int idx;
    int val;
    int k;
    int s;
    int t;
    BitState *bc = &bcode2;

    v = ntbl[n];
    bc->p1 = jw + v;
    bc->p2 = jw + v;

    if (bc->bits < 8) {
        bc->byte <<= 8;
        i = *p;
        if ((u32)(i + 1) >= bc->limit)
            return 0;
        *p = i + 1;
        c = b[i];
        bc->esc = 0;
        if (c == 0xff) {
            (*p)++;
            c = 0xff;
            bc->esc = 1;
        }
        bc->bits += 8;
        bc->byte |= c;
    }

    bits = bc->bits;
    idx = v + 0xae + ((bc->byte >> (bits - 8)) & 0xff);
    if (idx < 0 || idx >= 0x1800) {
        bcode2.err = 1;
        return 0;
    }
    val = jw[idx];
    if (val != 0) {
        bc->bits = bits - val;
        idx = v + 0x1ae + ((bc->byte >> (bits - 8)) & 0xff);
        if (idx < 0 || idx >= 0x1800) {
            bcode2.err = 1;
            return 0;
        }
        return jw[idx];
    }

    while (bcode2.bits < 9) {
        bcode2.byte <<= 8;
        i = *p;
        if ((u32)(i + 1) >= bcode2.limit)
            return 0;
        *p = i + 1;
        c = b[i];
        bcode2.esc = 0;
        if (c == 0xff) {
            (*p)++;
            c = 0xff;
            bcode2.esc = 1;
        }
        bcode2.bits += 8;
        bcode2.byte |= c;
    }

    val = (bcode2.byte >> (bcode2.bits - 9)) & 0x1ff;
    bcode2.bits -= 9;
    if (v + 0x1a >= 0x1800) {
        bcode2.err = 1;
        return 0;
    }
    k = 9;
    if (val > ((s32 *)bcode2.p2)[0x1a]) {
        s = bcode2.bits;
        t = bcode2.byte;
        do {
            if (s == 0) {
                i = *p;
                if ((u32)(i + 1) >= bcode2.limit)
                    return 0;
                *p = i + 1;
                t = b[i];
                bcode2.byte = t;
                bcode2.esc = 0;
                if (t == 0xff) {
                    (*p)++;
                    bcode2.byte = 0xff;
                    t = 0xff;
                    bcode2.esc = 1;
                }
                s = 8;
            }
            val = (val << 1) | ((t >> (s - 1)) & 1);
            k++;
            s--;
            bcode2.bits = s;
            if (v + 0x11 + k >= 0x1800) {
                bcode2.err = 1;
                return 0;
            }
        } while (val > ((s32 *)bcode2.p2)[k + 0x11]);
    }

    if (k > 0x10 || v + k < 0 || v + k + 0x46 >= 0x1800) {
        bcode2.err = 1;
        return 0;
    }

    switch (n) {
    case 0:
        idx = val + ((s16 *)bcode2.p1)[k + 0x46]
              - ((s32 *)bcode2.p2)[k] + 0x14;
        if (idx < 0 || idx >= 0x1800) {
            bcode2.err = 1;
            return 0;
        }
        val = jw[idx];
        break;
    case 1:
        idx = val + ((s16 *)bcode2.p1)[k + 0x46]
              - ((s32 *)bcode2.p2)[k] + 0x38;
        if (idx < 0 || idx >= 0x1800) {
            bcode2.err = 1;
            return 0;
        }
        val = jw[idx];
        break;
    case 2:
        idx = val + ((s16 *)bcode2.p1)[k + 0x46]
              - ((s32 *)bcode2.p2)[k] + 0x14c;
        if (idx < 0 || idx >= 0x1800) {
            bcode2.err = 1;
            return 0;
        }
        val = jw[idx];
        break;
    case 3:
        idx = val + ((s16 *)bcode2.p1)[k + 0x46]
              - ((s32 *)bcode2.p2)[k] + 0x170;
        if (idx < 0 || idx >= 0x1800) {
            bcode2.err = 1;
            return 0;
        }
        val = jw[idx];
        break;
    }

    return val;
}




