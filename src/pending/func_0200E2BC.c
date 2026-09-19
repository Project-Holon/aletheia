/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * function: func_0200E2BC
 * address:  0x0200E2BC
 * packet:   pkt_0200E2BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * 172 bytes of code and literal pool, 0x0200E2BC..0x0200E368.  Every concrete
 * byte reproduces; the diff is empty apart from one wildcarded call field.
 * The verdict prints as MATCH* because the extent also runs over the six-byte
 * unlabelled leaf at 0x0200E368 (`movs r0, #0xa1; lsls r0, r0, #2; bx lr`,
 * i.e. `return 0x284;`), which saves no lr and so never gets a label -- see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  That leaf is
 * worth seeding into layout/function_starts.txt by the integrator; it is not
 * mine to edit.
 *
 * Blocked on the `label` class: the call at +0x36 targets func_02007248,
 * whose only caller in the whole image is this function, so the compared
 * range is its only witness.  Nothing in the C can change that; it graduates
 * the day 0x02007248 has an EXACT entry of its own (it is a band member of
 * the 65-128 byte wave, pkt_02007248).
 *
 * What it is: a keyed probe of a 0x850-byte record buffer.  It allocates the
 * buffer through the debug allocator, then for each of two sub-tables asks
 * func_02007248 for sub-table i and scans the 530 entries of the filled
 * buffer for the key: with `mode == 1` it compares an 11-bit field and a
 * 6-bit field of the 32-bit key, otherwise it memcmps four bytes.  On a hit
 * it stops early, frees the buffer and returns 1, else it frees and returns 0.
 *
 * Three tells that cost a compile each and are the point of keeping this file:
 *  - the two masked fields are **bitfields**, not masks.  `(x & 0x7ff)` and
 *    `((x >> 23) & 0x3f)` compile to a pool load of the mask plus `ands`,
 *    eight bytes longer; the 11/12/6/3-bit struct pins the lsls/lsrs pairs
 *    the original has, exactly as in docs/idioms/
 *    shift-pair-with-no-matching-type-is-a-bitfield.md.
 *  - `found = 1; break;` is written out in **both** arms of the mode test.
 *    Behind a single shared statement the compiler puts the block after the
 *    else arm and every arm branches to it; duplicated, it lands in the first
 *    arm and the second branches back to it, which is the original.
 *  - the failed query arm must fall into the `if (found == 1) break;` check,
 *    so the source wraps the scan in `if (query(...) == 1) { ... }` rather
 *    than using `continue`; `continue` jumps straight to the i++ and shifts
 *    one bcond by 6 bytes (1 differing instruction, nothing else).
 * Both loop counters are `s32`: `u32` gives `blo` where the original has
 * `blt` (2 bytes).
 *
 * The allocator's 5th argument is the same 0x850 as the size, and the line
 * argument 0x1ac is written 0x6b << 2.
 *
 * Verified with
 *   python tools/match.py one --src src/pending/func_0200E2BC.c \
 *       --func func_0200E2BC --addr 0x0200E2BC --cc 1.1p1 --thumb
 *
 * symbols:
 *   func_02030734     0x02030734  arm
 *   func_020307B0     0x020307B0  arm
 *   func_02007248     0x02007248  thumb
 *   func_0200E06C     0x0200E06C  thumb
 *   memcmp            0x0203EFC8  arm
 *   sFile_020A720C    0x020A720C  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    u32 lo  : 11;
    u32 mid : 12;
    u32 hi  : 6;
    u32 top : 3;
} Key;

extern void *func_02030734(void *heap, u32 size, u32 flag, char *file, u32 line);
extern void  func_020307B0(void *p);
extern u32   func_02007248(void *a, u32 b, u32 c, void *d, u32 e);
extern void  func_0200E06C(void *p);
extern int   memcmp(const void *a, const void *b, u32 n);
extern char  sFile_020A720C[];

u32 func_0200E2BC(void *a0, u32 *a1, void *heap, u32 mode)
{
    u32 *buf;
    Key *key = (Key *)a1;
    u32 found = 0;
    s32 i;
    s32 j;

    buf = func_02030734(heap, 0x850, 1, sFile_020A720C, 0x1ac);
    for (i = 0; i < 2; i++) {
        if (func_02007248(a0, 0x3d, i, buf, 0x850) == 1) {
            func_0200E06C(buf);
            for (j = 0; j < 530; j++) {
                if (mode == 1) {
                    if (key->lo != ((Key *)buf)[j].lo) continue;
                    if (key->hi != ((Key *)buf)[j].hi) continue;
                    found = 1;
                    break;
                } else {
                    if (memcmp(&buf[j], a1, 4) != 0) continue;
                    found = 1;
                    break;
                }
            }
        }
        if (found == 1) break;
    }
    func_020307B0(buf);
    return found;
}
