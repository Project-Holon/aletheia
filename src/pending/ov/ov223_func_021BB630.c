/*
 * function: func_021BB630
 * address: 0x021BB630
 * packet: pkt_ov223_021BB630
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * 2026-10-04: DIFF, compiled 308 vs 372 bytes. Semantics read from the listing: three 0x94-stride
 * fade slots, state u16 at +0xD4 (1 = fade in, 3 = fade out), step u16 at +0xD6 (0..0x10); per step it blends
 * the palette at +0x74 with the one at +0x94 into +0xB4 channel by channel (func_021BB520 splits RGB555),
 * weights (16-t) and t, signed /16; then uploads +0xB4 through func_02061CA4. Case 1 stores d6+1 and then 0x10
 * (as listed). Residue: the original recomputes p+i*0x94 at every access (reloads [sp],[sp+4], no CSE, r4 free
 * for the inner loop's t) while this draft hoists p+i*0x94 into r4 for the first half, and the prologue differs
 * (original push {r3-r7,lr}; sub sp,#0x20 with spills [sp+8] = 0x94 palette word, [sp+0x10] = j*2).
 * Tried: off local vs inline i*0x94 expressions (same code). Not tried: a static inline accessor per field.
 *
 * symbols:
 *   func_021BB520 0x021BB520 thumb ov223
 *   func_02061CA4 0x02061CA4 arm
 *   d_021BC6FC 0x021BC6FC data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 d_021BC6FC[];
extern void func_021BB520(u16 c, u16 *r, u16 *g, u16 *b);
extern int func_02061CA4(void *, unsigned, unsigned, int);
void func_021BB630(u8 *p)
{
    u8 i;
    for (i = 0; i < 3; i++) {
        int go = 0;
        switch (*(u16 *)(p + i * 0x94 + 0xD4)) {
        case 1:
            if (*(u16 *)(p + i * 0x94 + 0xD6) == 0x10) {
                *(u16 *)(p + i * 0x94 + 0xD4) = 2;
            } else {
                *(u16 *)(p + i * 0x94 + 0xD6) = *(u16 *)(p + i * 0x94 + 0xD6) + 1;
                *(u16 *)(p + i * 0x94 + 0xD6) = 0x10;
                go = 1;
            }
            break;
        case 3:
            if (*(u16 *)(p + i * 0x94 + 0xD6) == 0) {
                *(u16 *)(p + i * 0x94 + 0xD4) = 0;
            } else {
                *(u16 *)(p + i * 0x94 + 0xD6) = *(u16 *)(p + i * 0x94 + 0xD6) - 1;
                go = 1;
            }
            break;
        }
        if (go) {
            u16 d4 = *(u16 *)(p + i * 0x94 + 0xD4);
            if (d4 == 1 || d4 == 3) {
                u8 *e = p + i * 0x94;
                u8 j;
                u16 w[6];
                for (j = 0; j < 0x10; j++) {
                    u32 t = *(u16 *)(e + 0xD6);
                    func_021BB520(*(u16 *)(e + 0x74 + j * 2), &w[5], &w[4], &w[3]);
                    func_021BB520(*(u16 *)(e + 0x94 + j * 2), &w[2], &w[1], &w[0]);
                    *(u16 *)(e + 0xB4 + j * 2) =
                        (u16)((w[3] * (16 - t) + w[0] * t) / 16) << 10 |
                        (u16)((w[5] * (16 - t) + w[2] * t) / 16) |
                        (u16)((w[4] * (16 - t) + w[1] * t) / 16) << 5;
                }
            }
            func_02061CA4((void *)0x1E, d_021BC6FC[i] << 5, (u32)(p + 0xB4 + i * 0x94), 0x20);
        }
    }
}
