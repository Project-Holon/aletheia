/*
 * function: func_0220BA2C
 * address: 0x0220BA2C
 * packet: pkt_ov197_0220BA2C
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * 2026-10-05 (wD6 lane17): 48 -> 5 bytes. Second loop closed by writing the store in each arm
 *   (`if (v == 0) p[i+0x539] = 0; else p[i+0x539] = (v-1)/6;`, the join lever): 0x539 now takes r7 and
 *   0x535 is spilled, as in the original. Prologue closed by `i = 0;` after the func_02048F60 call.
 *   Residue: first loop only, `ldrb r0,[q,r7]; adds r4,p,r4` (idx*4 in r0, p + c*0x90 in r4) versus ours
 *   `adds r0,p,r4; ldrb r4,[q,r7]`. Tried: idx*4 first in the sum, `e += idx*4`, an int idx local read
 *   first, u16 * element form, Ent row/2D struct arrays (worse, 244-252 B).
 * 2026-10-05 (wD5 lane19): still DIFF 48 B. Tried: `q[0x535] * 4 + (p + c * 0x90)` and `(q[0x535] * 4) + p + c * 0x90` for the first-loop add order (no change / worse), `int o = 0x539` with p[i + o - 4], `int o = 0x535` with p[i + o + 4], base pointer b = p + 0x539 with b[i - 4]: all give the same 48 B or worse. Orig second loop: r7 = 0x539 pool word, 0x535 = r7 - 4 spilled to [sp,#0x14] and reloaded.
 *
 * 2026-10-04 (wave D2 lane 14): DIFF, 48 bytes, shape right. Done: u8 pointers (blo, ldrb), r and the
 * loop counters declared at function scope (r in r2, k in r3 as in the original). Residue: (1) the
 * original spills p+0x535 to [sp,#0x14] and keeps 0x539 in r7 in the second loop (frame 0x18 plus
 * push r3); this build keeps 0x535 in r7 and reloads the 0x539 pool word per use (frame 0x14).
 * (2) first loop: original loads byte q[0x535] into r0 before adding p to c*0x90 (adds r4,r6,r4);
 * this build adds first. Tried without effect: q = p + i locals, c/l pointer locals, explicit n,
 * row/e split, u32 add order, ternary vs if for the divide.
 *
 * 2026-10-05 (D4-18): still DIFF, 48 bytes. Tried: int o = 0x539 as loop-local and function-scope local with p[i + o - 4] for the 0x535 read (same output: the compiler hoists o-4 into r7 and reloads the 0x539 pool word per use, the original does the opposite and spills o-4 to [sp,#0x14]); first loop with no q/e locals (raw p[c + 0x535] repeated, 252 bytes, worse); second loop with *(u8 **)p repeated instead of s (no change). The original has one extra live value in the second loop (frame 0x18) that the source has not yet been found to supply.
 *
 * symbols:
 *   func_02048F60 0x02048F60 arm
 *   func_020081DC 0x020081DC thumb
 *   func_020307B0 0x020307B0 arm
 *   d_0220DB3C 0x0220DB3C data a4
 *   d_0220DB3F 0x0220DB3F data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *func_02048F60(u32, u32, u32);
extern u16 *func_020081DC(void *, int, u16);
extern void func_020307B0(void *);
extern const u8 d_0220DB3C[];
extern const u8 d_0220DB3F[];

void func_0220BA2C(u8 *p)
{
    u8 *tbl;
    u16 *r;
    u32 i, j, k;

    tbl = func_02048F60(0xE8, 0, *(u16 *)(*(u8 **)p + 0xC));
    i = 0;
    do {
        j = 0;
        for (;;) {
            r = func_020081DC(**(void ***)p, d_0220DB3C[i], (u16)j);
            if (r == 0)
                break;
            if (r[0] != 0 && r[1] != 0) {
                u32 m = tbl[r[0]];
                for (k = 0; k < 4; k++) {
                    if (m & (1 << k)) {
                        int c = d_0220DB3F[k];
                        u8 *q = p + c;
                        u8 *e = p + c * 0x90 + q[0x535] * 4;
                        *(u16 *)(e + 0x150) = r[0];
                        *(u16 *)(e + 0x152) = r[1];
                        q[0x535]++;
                    }
                }
            }
            j++;
        }
        i++;
    } while (i < 3);
    func_020307B0(tbl);
    for (i = 0; i < 4; i++) {
        u8 v = p[i + 0x535];
        u8 *s;
        if (v == 0)
            p[i + 0x539] = 0;
        else
            p[i + 0x539] = (v - 1) / 6;
        s = *(u8 **)p + i * 2;
        if (p[i + 0x539] < *(s16 *)(s + 0x38))
            *(s16 *)(s + 0x38) = p[i + 0x539];
    }
}
