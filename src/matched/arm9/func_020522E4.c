/*
 * function: BUTTON_MAN_Ucs2CharToSjis
 * address:  0x020522E4
 * packet:   pkt_020522E4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_02045A98  0x02045A98  arm
 *
 * The per-character encoder behind BUTTON_MAN_ConvertUcs2ToSjis: one UCS-2 code unit to
 * Shift-JIS.  The terminator (func_02045A98's value) writes a NUL and raises
 * *stop; printable ASCII is copied; hiragana, both katakana runs and the
 * full-width A-Z, a-z and 0-9 are offset into their Shift-JIS rows and
 * written high byte first; the long-vowel mark, U+8140 (passed through as the
 * SJIS ideographic space), and the two gender signs are special-cased; any
 * other code writes '?'.  Returns 1 when two bytes were written.
 *
 * Levers: dst is plain (signed) char -- the 0x81 lead byte is `mvn r1,#0x7e`
 * and the trail bytes 0x89/0x8a are derived from it by `add` -- and the
 * result `two` is declared BEFORE the character (declaration order decides
 * the r4/r5 colours).  dsi/1.1p1; 1.2 and 2.0 are 170-220 bytes longer.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 func_02045A98(void);

int BUTTON_MAN_Ucs2CharToSjis(u16 *src, char *dst, u32 *stop)
{
    int two = 0;
    u16 c = *src;
    u16 v;

    if (c == func_02045A98()) {
        *dst = 0;
        if (stop != 0)
            *stop = 1;
    } else if (c >= 0x20 && c <= 0x7e) {
        *dst = c;
    } else if (c >= 0x3041 && c <= 0x3093) {
        v = c + 0x525E;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0x30A1 && c <= 0x30DF) {
        v = c + 0x529F;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0x30E0 && c <= 0x30F3) {
        v = c + 0x52A0;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0xFF21 && c <= 0xFF3A) {
        v = c - 0x7CC1;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0xFF41 && c <= 0xFF5A) {
        v = c - 0x7CC0;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0xFF10 && c <= 0xFF19) {
        v = c - 0x7CC1;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c == 0x30FC) {
        dst[0] = 0x81;
        dst[1] = 0x5B;
        two = 1;
    } else if (c == 0x8140) {
        dst[0] = 0x81;
        dst[1] = 0x40;
        two = 1;
    } else if (c == 0x2642) {
        dst[0] = 0x81;
        dst[1] = 0x89;
        two = 1;
    } else if (c == 0x2640) {
        dst[0] = 0x81;
        dst[1] = 0x8A;
        two = 1;
    } else {
        *dst = '?';
    }
    return two;
}
