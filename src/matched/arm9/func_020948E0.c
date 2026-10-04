/*
 * function: func_020948E0
 * address:  0x020948E0
 * packet:   pkt_02094750
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * MSL strcmp, the 4-byte-at-a-time form.  Compare the first byte; if the two
 * pointers share a 4-byte alignment, copy the (3 - align) leading bytes one at
 * a time, then compare whole words using the Alan Mycroft null-byte test
 * (w + 0xFEFEFEFF) & ~w & 0x80808080 -- the two constants are the pool words at
 * 0x020949EC and 0x020949F0 and carry no relocation -- and fall into a
 * byte-by-byte epilogue at the word that carries the terminator.  A misaligned
 * pair, and a word mismatch, both enter that epilogue directly.
 *
 * HOW THE 2026-09-21 WALL WAS CLOSED.  docs/notes/func_020948E0.c.txt records
 * this as a 28-of-276-byte near miss "solely in register allocation between
 * r2, r4 and lr" (and that note's own source did not compile: it says
 * `(const u32 *)p2` for `s2`).  Two separate things were wrong, and both are
 * readable off the image:
 *
 *   1. ONE VARIABLE HOLDS BOTH THE WORD AND THE BYTE.  The image branches out
 *      of the word loop with `b #0x20949bc`, landing on `cmp r2, #0` -- and r2
 *      at that point holds the 32-bit WORD w1 just loaded by
 *      `ldr r2,[r0,#4]!`, not a byte.  That is sound (the haszero test has
 *      already proved no byte of the word is zero) and it is only expressible
 *      if the same `u32` names both.  Declaring a separate `unsigned char c1`
 *      for the byte adds a third value live across the word loop and widens
 *      the prologue to `push {r3, r4, r5, lr}` -- the documented symptom, and
 *      the whole 28-byte residue.
 *   2. THE FALL-THROUGH FROM find_in_word.  The image's find_in_word block at
 *      0x020949A8 ends with `popne {r4, pc}` and FALLS THROUGH into the
 *      epilogue's `cmp r2, #0`; the two `goto byte_loop` paths branch to that
 *      `cmp` instead.  Spelling the epilogue's first test as a fresh
 *      `*(const u8 *)s1 == 0` re-loads the byte and costs four bytes.
 *
 * Note the ASYMMETRY of the two haszero tests, which is in the image and is
 * not a transcription slip: the PRE-loop test at +0x74 is the full
 * `(w + C) & ~w & M` (three instructions, `mvn`/`add`/`and` then `tst`), while
 * the test INSIDE the loop at +0xA8 is only `(w + C) & M` -- `add lr,r2,r3` /
 * `tst lr,ip`, with no `mvn`.  Writing the full expression in both places
 * compiles the loop body two instructions long.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020948E0.c \
 *       --func func_020948E0 --addr 0x020948E0 --cc 1.1p1 --arm
 */
#include "../include/Obj00079.h"
#include "../include/Obj02480.h"
typedef unsigned int u32;
typedef unsigned char u8;

int func_020948E0(const char *s1, const char *s2)
{
    int diff;
    u32 align;
    u32 w1;
    u32 w2;

    w1 = *(const u8 *)&((struct Obj00079 *)s1)->f0;
    diff = w1 - *(const u8 *)&((struct Obj02480 *)s2)->f0;
    if (diff != 0) {
        return diff;
    }

    align = (u32)s1 & 3;
    if (((u32)s2 & 3) != align) {
        goto byte_loop;
    }

    if (align != 0) {
        if (w1 == 0) {
            return 0;
        }
        align = 3 - align;
        if (align != 0) {
            do {
                w1 = *(const u8 *)++s1;
                diff = w1 - *(const u8 *)++s2;
                if (diff != 0) {
                    return diff;
                }
                if (w1 == 0) {
                    return 0;
                }
            } while (--align != 0);
        }
        s1++;
        s2++;
    }

    w1 = *(const u32 *)s1;
    w2 = *(const u32 *)s2;
    if ((((w1 + 0xfefefeff) & ~w1) & 0x80808080) != 0) {
        goto find_in_word;
    }
    if (w1 != w2) {
        goto mismatch_word;
    }

    do {
        w1 = *(const u32 *)(s1 += 4);
        w2 = *(const u32 *)(s2 += 4);
        if (((w1 + 0xfefefeff) & 0x80808080) != 0) {
            goto find_in_word;
        }
    } while (w1 == w2);

mismatch_word:
    s1--;
    s2--;
    goto byte_loop;

find_in_word:
    w1 = *(const u8 *)&((struct Obj00079 *)s1)->f0;
    diff = w1 - *(const u8 *)&((struct Obj02480 *)s2)->f0;
    if (diff != 0) {
        return diff;
    }

byte_loop:
    if (w1 == 0) {
        return 0;
    }
    do {
        w1 = *(const u8 *)++s1;
        diff = w1 - *(const u8 *)++s2;
        if (diff != 0) {
            return diff;
        }
    } while (w1 != 0);

    return 0;
}
