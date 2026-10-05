/*
 * function: func_021D5AC0
 * address: 0x021D5AC0
 * packet: pkt_ov123_021D5AC0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * 2026-10-05 (wD8 lane04): still DIFF (76 vs 80 B). Image layout: case 3's `b end` stub is the FIRST case body (before case 6 and case 8). Tried: case 3 written first in the switch (76 B, still merged), case 3 with the two tail stores repeated plus break or return (cross-jumped fully, 76 B), a non-inline empty static function called in case 3 (inlined away, 76 B).
 * 2026-10-05 (wD7 lane19): still DIFF (76 vs 80 B). New tests in case 3: an empty static inline with a u32 parameter called as nop_arg(mode) (copy removed, 76 B); dead stores `*(d+0xB4) = mode` / `*(d+0xB0) = 1` (kept, 88 B); `mode = 3;` (80 B but emits movs r4,#3 + b). Conclusion: the stub needs a copy that lives until register coalescing (as the rejected `state = mode`); no natural source found.
 * note (2026-10-05, integrator): D6 lane 17 got EXACT only with a redundant `state = mode;` in case 3 (`u32 state = mode; ... case 3: state = mode; break;`). Rejected as a stand-in: a redundant statement needs line-table evidence, and game overlays have none. The real source of the case 3 `b end` stub is still unknown.
 * 2026-10-05 (wD5 lane19): no new variant beyond the D2/D4 list; case 3 still merges with the end label (76 B vs 80 B).
 * 2026-10-05 (wD4 lane16): also tried empty static inline call, `if (mode == 100) {}`, `{ u32 t = mode; (void)t; }`, `for (;;) { break; }` in case 3: all 76 bytes, case 3 still merges with the end label. Residue unchanged.
 * note 2026-10-04: DIFF, 4 bytes short. Dense jump table matches once cases 0,1,2,4,5,7 are explicit. Original case 3
 *   (table entry 0x10) targets its own `b end` at +0x26, i.e. an arm with an empty body that is not merged with the end label;
 *   cases 0,1,2,4,5,7 and the bhi go straight to end. Tried: plain break, default label, empty static inline call in case 3
 *   (inlined away or emitted as bl). Rest of body matches.
 * 2026-10-04 (wD2 lane19): also tried `goto done` from case 3, `if (mode != 3) break;`, `do {} while (0)`, `while (0) {}`,
 *   dead local `u32 t = mode;`/`mode + 1`, `mode = mode;`, `d = d;`, and default-only form: all emit the same 76 bytes (case 3 merges with end).
 *   Original is 80 bytes: the 4 extra bytes are the `b end` stub for case 3 plus alignment padding before the pool.
 * symbols:
 *   func_0200F7DC 0x0200F7DC thumb
 *   d_021DAC20 0x021DAC20 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *d_021DAC20;
extern void func_0200F7DC(void);
void func_021D5AC0(void *unused, u32 mode)
{
    switch (mode) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 7:
        break;
    case 3:
        break;
    case 6:
        *(u32 *)(d_021DAC20 + 0xC8) = 1;
        break;
    case 8:
        func_0200F7DC();
        break;
    }
    *(u32 *)(d_021DAC20 + 0xB0) = 1;
    *(u32 *)(d_021DAC20 + 0xB4) = mode;
}
