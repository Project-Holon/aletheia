/*
 * function: PMSI_PARAM_ValidateWord
 * address:  0x020246C8
 * packet:   pkt_020245D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * pmsi_param.c's single-word validator (see docs/families/pmsi_param.h and
 * PMSI_PARAM_IsValid, which runs the same two-arm check over a word array).
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 116/116, 1 byte out at +0x3E
 * for three waves, docs/notes/PMSI_PARAM_ValidateWord.diff.c.txt): the flag arm writes
 * the fail tail `ok = 0; *p = 0x6A1; goto done;` out after the range test,
 * like the flag == 0 arm does. The image's `blt` lands on an unconditional
 * `b bad` instead of on `bad` itself: a branch that jump threading did not
 * follow is a branch into a cross-jumped copy of a written-out tail, because
 * cross-jumping runs after threading. Falling into the shared `bad:` label
 * lets 1.1p1 thread the hop away.
 *
 * symbols:
 *   sub_02024508   0x02024508  thumb
 *   sub_02024520   0x02024520  thumb
 *   PMSI_PARAM_IsSpecialWord  0x02024768  thumb
 *   PMS_WORD_SplitWordId  0x020248D8  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

extern u32 sub_02024508(u32 x);
extern u32 sub_02024520(u32 x);
extern s32 PMSI_PARAM_IsSpecialWord(u32 v);
extern int PMS_WORD_SplitWordId(u32 v, u32 *a1, u32 *a2);

u32 PMSI_PARAM_ValidateWord(u16 *p, u32 mode, u32 flag)
{
    u32 ok = 1;
    u32 y, x;

    if (mode != 0) {
        if (*p == 0xFFFF) {
            return ok;
        }
    } else {
        if (*p == 0xFFFF) {
            *p = 0x6A1;
            return 0;
        }
    }

    if (sub_02024508(*p) != 0) {
        s32 v;

        if (flag != 0) {
            v = sub_02024520(*p);
            if (v >= 1 && v < 11) {
                goto done;
            }
            ok = 0;
            *p = 0x6A1;
            goto done;
        } else {
            ok = 0;
            *p = 0x6A1;
            goto done;
        }
    } else {
        if (PMSI_PARAM_IsSpecialWord(*p) == 0) {
            if (PMS_WORD_SplitWordId(*p, &x, &y) != 0) {
                goto done;
            }
        }
    }
bad:
    ok = 0;
    *p = 0x6A1;
done:
    return ok;
}
