/*
 * function: func_020933B8
 * address:  0x020933B8
 * packet:   pkt_020929E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * MSL printf back end: the decimal rounding / odometer carry on the digit
 * buffer `__num2dec`-style control block.  Rounds the ASCII digit string in
 * place at position `idx`, propagating a carry leftwards, and renormalises
 * the exponent field when the carry runs off the top.
 *
 *   +0x00  u16 unk0
 *   +0x02  s16 num     decimal exponent (ldrsh at 0x020934A0, strh at reset)
 *   +0x04  u8  len     significant-digit count
 *   +0x05  u8  str[]   '0'..'9' ASCII digits
 *
 * THE ONE SPELLING THAT MATTERS (this closed a 12-byte residue that four
 * earlier lanes could not move; see docs/notes/pkt_020933B8.c.txt for the
 * seven spellings that all landed on the same 264-byte if-converted form).
 * The carry loop must be a `while (idx != 0)` whose DECREMENT lives inside
 * the continue path, not a `for (; idx != 0; idx--)`:
 *
 *     if (carry != 0 || v == 0) { idx--; continue; }
 *     *q = (u8)(v + '0');
 *     break;
 *
 * Written as a `for` (or with the break arm as the positive condition),
 * mwcc 1.1p1 if-converts the two-instruction write arm to `addne`/`strbne`
 * and fuses the decrement into `subs r1, r1, #1`, which is 12 bytes short.
 * With the decrement on the continue path the write arm is no longer on the
 * fall-through, so it stays a real block (`add ip, r4, #0x30` / `strb ip,
 * [r3]` / `b END`) and the loop test stays its own `cmp r1, #0` / `bne`,
 * exactly as the image has it at 0x0209347C..0x02093494.
 *
 * Two spellings carried over from the note and still required:
 *   - the reset block is `len = 1; num = 0; str[0] = '0';` in that order;
 *   - the `idx == 0` tail must be an explicit `goto reset;` back into the
 *     `idx < 0` block, or the 5-instruction reset is duplicated inline.
 *
 * The trailing star is the unlabelled follower at 0x020934CC (a
 * `push {r0, r1, r2, r3}` argument home area, the real start of the
 * function disasm.py labels at 0x020934D0): the listing extent runs 280
 * bytes, the body is 276.  Wants a seed at 0x020934CC in
 * layout/function_starts.txt.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020933B8.c \
 *       --func func_020933B8 --addr 0x020933B8 --arm --cc 1.1p1
 *   EXACT*, 276 bytes, no relocation sites.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

typedef struct {
    u16 unk0;
    s16 num;
    u8  len;
    u8  str[1];
} Ctr;

void func_020933B8(Ctr *b, s32 idx)
{
    u8 *p;
    u8 *q;
    u32 v;
    u32 carry;

    if (idx < 0) {
    reset:
        b->len = 1;
        b->num = 0;
        b->str[0] = '0';
        return;
    }
    if (idx >= b->len)
        return;
    p = b->str;
    q = p + idx + 1;
    v = (u8)(*--q - '0');
    if (v == 5) {
        u8 *s = p + b->len;
        do {
            s--;
        } while (s > q && *s == '0');
        if (s == q)
            carry = (u8)q[-1] & 1;
        else
            carry = 1;
    } else {
        carry = v > 5;
    }
    while (idx != 0) {
        v = (u8)((*--q - '0') + carry);
        carry = v > 9;
        if (carry != 0 || v == 0) {
            idx--;
            continue;
        }
        *q = (u8)(v + '0');
        break;
    }
    if (carry != 0) {
        b->num = b->num + 1;
        b->len = 1;
        b->str[0] = '1';
        return;
    }
    if (idx == 0)
        goto reset;
    b->len = (u8)idx;
}
