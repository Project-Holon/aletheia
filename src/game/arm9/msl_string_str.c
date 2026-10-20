/*
 * file:     msl_string_str.c
 * unit:     yes
 * function: strlen, strcpy, strncpy, strcat, strcmp, strncmp, strchr, strcspn, strstr
 * address:  0x0209477C
 * region:   arm9
 * compiler: dsi/1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from msl_c_lib.c by tools/splitfile.py.
 *
 * symbols:
 */
#include "msl_crt_shared_types.h"

#define K1 0xFEFEFEFF

#define K2 0x80808080

int strlen(const u8 *s);

char *strcpy(char *dst, const char *src);

u8 *strncpy(u8 *dest, const u8 *src, u32 n);

u8 *strcat(u8 *dest, const u8 *src);

int strcmp(const char *s1, const char *s2);

int strncmp(const u8 *s1, const u8 *s2, u32 n);

u8 *strchr(const u8 *s, int c);

int strcspn(const u8 *s, const u8 *reject);

u8 *strstr(const u8 *s1, const u8 *s2);

/*
 * A plain byte-string length counter (strlen over a u8 buffer, not the C
 * library helper): count bytes up to and including the NUL, then return the
 * count minus one.  Self-contained, no external symbol.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/strlen.c \
 *       --func strlen --addr 0x0209477C --cc 1.1p1 --arm
 */
int strlen(const u8 *s)
{
    int n = -1;

    do {
        n++;
    } while (*s++ != 0);

    return n;
}

/*
 * MSL strcpy, the 4-byte-at-a-time form (MSL_C string.c).  If source and
 * destination share a 4-byte alignment, copy the (3 - align) leading bytes,
 * then whole words while the Mycroft null-byte test
 * (w + 0xFEFEFEFF) & ~w & 0x80808080 is clear (both constants are plain pool
 * words, no relocation), and finish byte by byte from the word that carries
 * the terminator.  A misaligned pair goes to the byte loop directly.
 *
 * HOW THE 2-BYTE WALL WAS CLOSED (wave 17).  docs/notes/pkt_02094798.c.txt
 * held this at 198/200 with the loop test's `and` accumulating into the
 * register holding w + K1 instead of the one holding ~w.  Every expression
 * spelling of the test left that choice alone.  MSL spells the test as three
 * statements on one mask local, `t = w + K1; t &= ~w; t &= K2;`, in both the
 * pre-loop and the loop test, and leaves the loop with `if (t) goto adjust`
 * inside `do { } while (1)`.  That source is EXACT under 1.1p1 and 1.2.
 */
char *strcpy(char *dst, const char *src)
{
    u8 *destb;
    u8 *fromb;
    u32 w;
    u32 t;
    u32 align;

    fromb = (u8 *)src;
    destb = (u8 *)dst;

    if ((align = ((sptr)fromb & 3)) != ((sptr)destb & 3)) {
        goto bytecopy;
    }

    if (align) {
        if ((*destb = *fromb) == 0) {
            return dst;
        }
        for (align = 3 - align; align; align--) {
            if ((*(++destb) = *(++fromb)) == 0) {
                return dst;
            }
        }
        ++destb;
        ++fromb;
    }

    w = *(u32 *)fromb;
    t = w + K1;
    t &= ~w;
    t &= K2;
    if (t) {
        goto bytecopy;
    }
    destb -= 4;
    do {
        destb += 4;
        *(u32 *)destb = w;
        fromb += 4;
        w = *(u32 *)fromb;
        t = w + K1;
        t &= ~w;
        t &= K2;
        if (t) {
            goto adjust;
        }
    } while (1);

adjust:
    destb += 4;
bytecopy:
    if ((*destb = *fromb) == 0) {
        return dst;
    }
    do {
        if ((*(++destb) = *(++fromb)) == 0) {
            return dst;
        }
    } while (1);
    return dst;
}

/*
 * strncpy and strcat implementations in standard string utility module.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02094860.c \
 *       --addr 0x02094860 --arm --cc 1.1p1
 */
u8 *strncpy(u8 *dest, const u8 *src, u32 n)
{
    u8 *d = dest;

    if (n == 0) {
        return dest;
    }

    do {
        u8 *prev = d;
        *d++ = *src++;
        if (*prev == 0) {
            if (--n == 0) {
                return dest;
            }
            do {
                *d++ = 0;
            } while (--n != 0);
            return dest;
        }

        if (--n == 0) {
            return dest;
        }
    } while (1);
}

u8 *strcat(u8 *dest, const u8 *src)
{
    u8 *d = dest;

    while (*d++)
        ;
    --d;
    while (*d++ = *src++)
        ;

    return dest;
}

/*
 * MSL strcmp, the 4-byte-at-a-time form.  Compare the first byte; if the two
 * pointers share a 4-byte alignment, copy the (3 - align) leading bytes one at
 * a time, then compare whole words using the Alan Mycroft null-byte test
 * (w + 0xFEFEFEFF) & ~w & 0x80808080 -- the two constants are the pool words at
 * 0x020949EC and 0x020949F0 and carry no relocation -- and fall into a
 * byte-by-byte epilogue at the word that carries the terminator.  A misaligned
 * pair, and a word mismatch, both enter that epilogue directly.
 *
 * HOW THE 2026-09-21 WALL WAS CLOSED.  docs/notes/strcmp.c.txt records
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
 *   python3 tools/match.py one --src src/matched/strcmp.c \
 *       --func strcmp --addr 0x020948E0 --cc 1.1p1 --arm
 */
int strcmp(const char *s1, const char *s2)
{
    int diff;
    u32 align;
    u32 w1;
    u32 w2;

    w1 = *(const u8 *)s1;
    diff = w1 - *(const u8 *)s2;
    if (diff != 0) {
        return diff;
    }

    align = (uptr)s1 & 3;
    if (((uptr)s2 & 3) != align) {
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
    w1 = *(const u8 *)s1;
    diff = w1 - *(const u8 *)s2;
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

/*
 * strncmp and strchr implementations in standard string utility module.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020949F4.c \
 *       --addr 0x020949F4 --arm --cc 1.1p1
 */
int strncmp(const u8 *s1, const u8 *s2, u32 n)
{
    if (n != 0) {
        do {
            u8 c2 = *s2++;
            u8 c1 = *s1++;
            if (c1 != c2) {
                return c1 - c2;
            }
            if (c1 == 0) {
                break;
            }
        } while (--n != 0);
    }

    return 0;
}

u8 *strchr(const u8 *s, int c)
{
    u8 m = (u8)c;
    u8 ch;

    ch = *s++;
    while (ch != 0) {
        if (ch == m)
            return (u8 *)s - 1;
        ch = *s++;
    }
    return m ? 0 : (u8 *)s - 1;
}

/*
 * strcspn, in the MSL string module this pseudo-family is made of
 * (strncmp strncmp, strchr strchr, strstr strstr).
 * Builds a 32-byte bitmap of the reject set on the stack, then scans the
 * subject until a member is hit, returning the index of that byte.
 *
 * TWO SPELLINGS ARE LOAD-BEARING, and both were missed by the two earlier
 * lanes recorded in docs/notes/strcspn.c.txt and
 * docs/notes/pkt_02094A60.c.txt, which between them left this at
 * DIFF / 188 bytes against 192 / 124 concrete bytes out:
 *
 *  - The character is `int c`, NOT `u8 c`.  The original masks it with a
 *    separate `and ip, r4, #0xff` whose result lives across the pointer
 *    load and indexes the map as `ldrb r3, [lr, ip, asr #3]` -- an
 *    ARITHMETIC shift, which is what an `int` shift compiles to.  With
 *    `u8 c` the cast is a no-op, the mask disappears, the map index folds
 *    into the load and the function loses four bytes and a saved register
 *    (`push {r4, lr}` for the original's `push {r3, r4, r5, lr}`).  This
 *    one change alone takes the body from 124 concrete bytes out to 10,
 *    size-exact, with every byte from +0x30 to the epilogue identical.
 *
 *  - The clear loop's COUNTER must be declared BEFORE the cursor
 *    (`u32 i = 8;` then `u8 *p = map;`).  This is
 *    docs/idioms/declaration-order-decides-which-register-a-local-gets.md:
 *    the original puts the cursor in ip and the counter in r3
 *    (`add ip, sp, #0` / `mov r3, #8` / ... / `subs r3, r3, #1`), and the
 *    reverse declaration order hands them the opposite pair, the residual
 *    10 bytes.  `int i` instead of `u32 i` is 160 bytes out: the signed
 *    counter costs a separate `cmp`/`bgt` in place of `subs`/`bne`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/strcspn.c \
 *       --func strcspn --addr 0x02094A60 --cc 1.1p1 --arm
 *   EXACT, 192 bytes, no relocation sites.
 */
int strcspn(const u8 *s, const u8 *reject)
{
    u8 map[32];
    u32 i = 8;
    u8 *p = map;
    int c;
    const u8 *p_reject;
    const u8 *p_s;

    do {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p += 4;
    } while (--i);

    c = *reject;
    p_reject = reject + 1;

    if (c != 0) {
        do {
            map[(u8)c >> 3] |= (u8)(1 << (c & 7));
            c = *p_reject++;
        } while (c != 0);
    }

    c = *s;
    p_s = s + 1;

    if (c != 0) {
        do {
            if (map[(u8)c >> 3] & (u8)(1 << (c & 7))) {
                break;
            }
            c = *p_s++;
        } while (c != 0);
    }

    return (u32)(p_s - s) - 1;
}

/*
 * strstr implementation in standard string utility module.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/strstr.c \
 *       --func strstr --addr 0x02094B20 --cc 1.1p1 --arm
 */
u8 *strstr(const u8 *s1, const u8 *s2)
{
    u8 c2;
    u8 c1;
    const u8 *p;

    if (s2 == 0 || (c2 = *s2) == 0) {
        return (u8 *)s1;
    }

    c1 = *s1;
    p = s1 + 1;

    if (c1 != 0) {
        do {
            if (c1 == c2) {
                const u8 *p2 = s2 + 1;
                const u8 *p1 = p;
                u8 sc2, sc1;

                do {
                    sc2 = *p2++;
                    sc1 = *p1++;
                    if (sc1 != sc2) {
                        break;
                    }
                } while (sc1 != 0);

                if (sc2 == 0) {
                    return (u8 *)p - 1;
                }
            }
            c1 = *p++;
        } while (c1 != 0);
    }

    return 0;
}
