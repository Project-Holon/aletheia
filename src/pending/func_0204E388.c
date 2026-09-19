/*
 * function: func_0204E388
 * address:  0x0204E388
 * packet:   pkt_0204E130
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  label -- 0204E4C0 and 0204E410, each reached only from this body
 *           (the tool prints "no witness outside 0204E388..0204E410"); both
 *           are the single caller site and neither packet is this lane's.
 *
 * symbols:
 *   func_0204E410  0x0204E410  arm
 *   func_0204E4C0  0x0204E4C0  arm
 *   func_02045A98  0x02045A98  arm
 *
 * Byte-identical at 136 bytes with every concrete byte right; only the two
 * PC24 call fields at +0x4C and +0x54 stay wildcarded.  No `--suggest-split`
 * cut exists: the compared range is already one function and both call sites
 * are inside it.
 *
 * Shape notes worth keeping.  `return` type is void: the epilogue is
 * `bl func_02045A98; strh r0,[r5]; pop` and nothing copies r0 afterwards, but
 * a u16 return forces `c` live across the loop and costs a callee-saved sb.
 * The first byte must be spelled `u8 ch = *p; p++;` -- `u8 ch = *p++;` emits
 * `ldrb r0,[r6],#1` and loses the `and r0,r0,#0xff` that reuses the loop
 * test's `ldrsb`, four bytes short.  The lead-byte test is one `||` of a `&&`
 * and a compare, and the two-byte value is spelled `(ch << 8) + *p`, not
 * `|`: the original shows `add r0,r1,r0,lsl #8` (one byte at +0x40).
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern u16 func_0204E410(u8 c);
extern u16 func_0204E4C0(u16 c);
extern u16 func_02045A98(void);

void func_0204E388(char *p, u16 *out, int max)
{
    int n = 0;
    u16 c;

    while (*p != 0 && n < max - 1) {
        u8 ch = *p;

        p++;
        if ((ch >= 0x81 && ch <= 0x9f) || ch >= 0xe0)
            c = func_0204E4C0((u16)((ch << 8) + (u8)*p++));
        else
            c = func_0204E410(ch);
        if (c != 0xfffe) {
            *out++ = c;
            n++;
        }
    }
    *out = func_02045A98();
}
