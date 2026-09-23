/*
 * function: func_0202F9F8
 * address:  0x0202F9F8
 * packet:   pkt_0202F9F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocking: evidence, not codegen.  Every concrete byte matches (MATCH*: the
 *           listing extent runs over the unlabelled 4-byte follower at
 *           0x0202FAB0).  Five ABS32 sites have no witness outside the range:
 *           the two pooled overlay ids 0x58 / 0xB3 (linker symbols, see
 *           docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md)
 *           and the three overlay-resident proc descriptors 0x021BD8E8,
 *           0x021B68D8, 0x021BD574, whose only pool words image-wide are
 *           this function's.
 *
 * symbols:
 *   ov088_id       0x00000058  data  a1
 *   ov179_id       0x000000B3  data  a1
 *   d_021BD8E8     0x021BD8E8  data
 *   d_021B68D8     0x021B68D8  data
 *   d_021BD574     0x021BD574  data
 *   g_02146948     0x02146948  data
 *   g_02146948_arg 0x02146948  data
 *   func_020312CC  0x020312CC  arm
 *
 * time_icon.c.  A five-state proc driver, the net_save.c shape of
 * src/pending/func_02010AC4.c: state 0 starts overlay 0x58's proc on
 * &g_02146948.f04, states 1 to 3 (re)start overlay 0xB3's proc on the
 * record, with state 2 bailing to 4 when f03 is set, and state 4 starts
 * overlay 0x58's second proc and resets to 0.
 *
 * Two pool words both name 0x02146948 (0x0202FA9C, the base of the field
 * stores, and 0x0202FAA8, the third call argument).  mwcc merges pool words
 * per symbol and CSEs the loaded address, so one symbol gives one word and
 * reuses r2 as the store base (184 -> 172 bytes, 98 out).  Two symbols at
 * the same address reproduce both words; g_02146948_arg is that second
 * name.  The state-2 test is written with the work in the `if` and the
 * bail-out after it (fall-through arm is the source order), so its
 * `*state = 4` block is the one state 3 branches back into.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202F9F8.c
 *       --func func_0202F9F8 --addr 0x0202F9F8 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct State {
    u16 f00;
    u8  f02;
    u8  f03;
    u32 f04;
};

extern u8 ov088_id[];
extern u8 ov179_id[];
extern u8 d_021BD8E8[];
extern u8 d_021B68D8[];
extern u8 d_021BD574[];
extern struct State g_02146948;
extern u8 g_02146948_arg[];

extern void func_020312CC(void *ovl, void *proc, void *arg);

int func_0202F9F8(void *unused, u32 *state)
{
    switch (*state) {
    case 0:
        func_020312CC(ov088_id, d_021BD8E8, &g_02146948.f04);
        *state = 1;
        break;
    case 1:
        g_02146948.f04 = 1;
        g_02146948.f00 = 0;
        g_02146948.f02 = 1;
        g_02146948.f03 = 0;
        func_020312CC(ov179_id, d_021B68D8, g_02146948_arg);
        *state = 2;
        break;
    case 2:
        if (g_02146948.f03 == 0) {
            g_02146948.f00 = 1;
            g_02146948.f03 = 0;
            func_020312CC(ov179_id, d_021B68D8, g_02146948_arg);
            *state = 3;
            break;
        }
        *state = 4;
        break;
    case 3:
        g_02146948.f00 = 2;
        g_02146948.f03 = 0;
        func_020312CC(ov179_id, d_021B68D8, g_02146948_arg);
        *state = 4;
        break;
    case 4:
        func_020312CC(ov088_id, d_021BD574, 0);
        *state = 0;
        break;
    }
    return 0;
}
