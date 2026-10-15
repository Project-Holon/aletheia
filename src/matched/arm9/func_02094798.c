/*
 * function: strcpy
 * address:  0x02094798
 * packet:   pkt_02094798
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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

typedef unsigned char u8;
typedef unsigned int u32;

#define K1 0xFEFEFEFF
#define K2 0x80808080

char *strcpy(char *dst, const char *src)
{
    u8 *destb;
    u8 *fromb;
    u32 w;
    u32 t;
    u32 align;

    fromb = (u8 *)src;
    destb = (u8 *)dst;

    if ((align = ((int)fromb & 3)) != ((int)destb & 3)) {
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
