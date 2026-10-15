/*
 * function: LOADER_DECRYPT_DecodeBlocks
 * address:  0x02188A48
 * packet:   pkt_ov230_02188A48
 * region:   ov230
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 * extent:   0x02188A48..0x02188B48 (244 B code + 12 B pool: gLoaderDecryptBssStart,
 *           0xF0618C46, 0xFFFFFA7E). Start evidence: the only caller,
 *           LOADER_ENTRY_Start, ends `bne 0x02188A48` (always taken, r0 = the
 *           descriptor table at 0x021889BC); the word before is the
 *           `bx lr` that ends LOADER_DECRYPT_ClassifyOpcode (0x02188A0C..0x02188A48); the
 *           first word is `push {r4-sl,lr}`.
 * note:     ov230 code decryptor. For each {start, end} pair in the table
 *           (zero-terminated) it walks the words in [start-0x1600,
 *           end-bss-0x1600): branch words (LOADER_DECRYPT_ClassifyOpcode kind 1 = BLX,
 *           3 = B) get their offset moved by -0x582 and bit 24 flipped;
 *           BL (kind 2) gets bit 24 flipped and then, like every other
 *           word, is XOR-decrypted with a 24-bit rolling key. Then it
 *           flushes the range (LOADER_DECRYPT_SyncCacheRange) and clears the pair. The
 *           first statement clears the 12-byte stub at t-3 (021889B0).
 * note 2026-10-05 (wave D9r lane 15): DIFF 8 B short under the pinned
 *           dsi/1.1p1, the same 248 B every spelling gives: 1.1p1 always
 *           cross-jumps the case 1/3 tail (`str r1,[r8]; bic r6,r0,#0xff000000`)
 *           into the default arm's identical tail, so case 1/3 ends
 *           `eor; b <default str>`. The image keeps both tails. Tried
 *           with no effect on that merge: store/key order in each arm,
 *           separate w/v locals, a re-read of *p for the key, the switch
 *           body in a static inline, `continue` in case 1/3, default as code
 *           after the switch, if/else dispatch, guarded do-while, cases 1
 *           and 3 written out separately (breaks the dispatch). Every other
 *           byte matches under 1.1p1 (registers, ldr split, pool).
 *           THIS EXACT SOURCE IS EXACT (256 B, 3 of 3 relocations resolved)
 *           under --cc ../2.0/sp2 --flags=-O4,p, the same tell as
 *           docs/idioms/a-flag-dispatch-four-bytes-short-is-the-front-end-tail-merging-the-arms.md
 *           (1.1p1 merges identical tails that 2.0/sp2 keeps). The lane
 *           brief pins the compiler, so it is parked here; promoting it
 *           means `compiler: ../2.0/sp2`, status EXACT, move to
 *           src/matched/ov/. LOADER_DECRYPT_ClassifyOpcode (matched, 1.1p1) is also EXACT*
 *           under ../2.0/sp2, so ov230 may be a 2.0/sp2 library object.
 *           Source levers: `h[0] = h[1] = h[2] = 0` (puts `mov r0,#0`
 *           before `sub r1,sb,#0xc`); a `bss` local and `p` declared last
 *           give the image's r7/r8 colours; p assigned before size splits
 *           the ldm.
 * symbols:
 *   LOADER_DECRYPT_ClassifyOpcode  0x02188A0C  arm  ov230
 *   LOADER_DECRYPT_SyncCacheRange  0x021889E4  arm  ov230
 *   gLoaderDecryptBssStart  0x021899A0  data  ov230
 */

typedef unsigned int u32;

extern char gLoaderDecryptBssStart[];
extern int LOADER_DECRYPT_ClassifyOpcode(u32 word);
extern void LOADER_DECRYPT_SyncCacheRange(void *addr, u32 size);

void LOADER_DECRYPT_DecodeBlocks(u32 *t)
{
    u32 *h;
    u32 size;
    u32 *end;
    u32 key;
    u32 w;
    u32 bss;
    u32 *p;

    h = t - 3;
    h[0] = h[1] = h[2] = 0;
    bss = (u32)gLoaderDecryptBssStart;
    do {
        p = (u32 *)(t[0] - 0x1600);
        size = t[1] - bss - 0x1600;
        end = p + size / 4;
        key = 0xF0618C46;
        for (; p < end; p++) {
            switch (LOADER_DECRYPT_ClassifyOpcode(*p)) {
            case 1:
            case 3:
                w = *p;
                w = ((w & 0xFF000000) ^ 0x01000000) | (((w & 0xFFFFFF) + 0xFFFFFA7E) & 0xFFFFFF);
                *p = w;
                key = (key ^ (w >> 24)) & 0xFFFFFF;
                break;
            case 2:
                *p ^= 0x01000000;
            default:
                w = *p ^ key;
                key = (key ^ w ^ (w >> 8)) & 0xFFFFFF;
                *p = w;
                break;
            }
        }
        LOADER_DECRYPT_SyncCacheRange((void *)(t[0] - 0x1600), size);
        t[1] = 0;
        t[0] = 0;
        t += 2;
    } while (*t != 0);
}
