/*
 * function: func_02180334
 * address:  0x02180334
 * packet:   pkt_02156B70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Transcode the null-terminated text at `src` into 16-bit units at `out`,
 * asking func_021800CC to consume one character at a time from the remaining
 * `size` bytes, until the input ends, `max` units have been produced, or the
 * input is exhausted.  Returns one past the number of units written, or 0 on
 * a decoding failure; a null source writes a lone terminator and returns 1.
 */

typedef unsigned short u16;

extern int func_021800CC(char *theUTF8String, int theMaxBytes, unsigned short *theUnicodeCharOut);

int func_02180334(const unsigned char *src, int size, u16 *out, int max)
{
    int n = 0;
    int off = 0;
    u16 *dst = out;

    if (src == 0) {
        *out = 0;
        return 1;
    }
    while (*src != 0 && max + 1 > n && size > off) {
        int r = func_021800CC((char *)src, size - off, dst);

        if (r == 0) {
            *out = 0;
            return 0;
        }
        off += r;
        src += r;
        n++;
        dst++;
    }
    *dst = 0;
    return n + 1;
}
