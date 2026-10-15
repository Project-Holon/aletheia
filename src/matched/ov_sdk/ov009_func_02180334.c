/*
 * function: UTF8ToUCS2StringLen2
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
 * asking _ReadUCS2CharFromUTF8String to consume one character at a time from the remaining
 * `size` bytes, until the input ends, `max` units have been produced, or the
 * input is exhausted.  Returns one past the number of units written, or 0 on
 * a decoding failure; a null source writes a lone terminator and returns 1.
 *
 * symbols:
 *   _ReadUCS2CharFromUTF8String  0x021800CC  arm
 */

typedef unsigned short u16;

extern int _ReadUCS2CharFromUTF8String(char *theUTF8String, int theMaxBytes, unsigned short *theUnicodeCharOut);

int UTF8ToUCS2StringLen2(const unsigned char *src, int size, u16 *out, int max)
{
    int n = 0;
    int off = 0;
    u16 *dst = out;

    if (src == 0) {
        *out = 0;
        return 1;
    }
    while (*src != 0 && max + 1 > n && size > off) {
        int r = _ReadUCS2CharFromUTF8String((char *)src, size - off, dst);

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
