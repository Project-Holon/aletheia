/*
 * function: __strtoul
 * address:  0x02095B3C
 * packet:   pkt_020949F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * MSL __strtoul: the scan-state machine every strtol/strtoul/atoi entry
 * drives (strtoul and strtol are two of its wrappers).  The
 * source is the Metrowerks one nearly verbatim: the power-of-two scan
 * states (start 1 .. failure 0x40, `tst #0x60` = final_state, `tst #0x34`
 * = success), fetch() as `(count++, ReadProc(arg, 0, 0))` and unfetch as
 * `ReadProc(arg, c, 1)`, the `c = fetch(); count--; spaces++;` whitespace
 * skip, and the <ctype.h> macros written as `(c < 0 || c >= 0x80) ? 0 :
 * __ctype_map[c] & bit` -- mwcc folds that pair of signed tests into the
 * image's single unsigned `cmp #0x80 / movhs`.  Bits: 0x100 space, 8 digit,
 * 1 alpha; __upper_map is the 128-byte toupper table sitting directly below
 * __ctype_map.  EOF and ULONG_MAX share the one `mvn fp, #0` register.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/__strtoul.c \
 *       --func __strtoul --addr 0x02095B3C --cc 1.1p1 --arm
 *   EXACT, 880 bytes, 4 relocation sites, all resolved.
 *
 * symbols:
 *   __ctype_map    0x020A61DC  data  a2
 *   __upper_map    0x020A615C  data  a1
 *   _u32_div_f     0x0209C2B0  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern const u16 __ctype_map[];
extern const u8 __upper_map[];
extern u32 _u32_div_f(u32 a, u32 b);

#define isspace(c) (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x100))
#define isdigit(c) (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x8))
#define isalpha(c) (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x1))
#define toupper(c) (((c) < 0 || (c) >= 0x80) ? (c) : __upper_map[c])

enum { start = 1, check_for_zero = 2, leading_zero = 4, need_digit = 8,
       digit_loop = 16, finished = 32, failure = 64 };

#define final_state(s) ((s) & (finished | failure))
#define success(s)     ((s) & (leading_zero | digit_loop | finished))
#define fetch()        (count++, (*ReadProc)(ReadProcArg, 0, 0))
#define unfetch(c)     (*ReadProc)(ReadProcArg, c, 1)

u32 __strtoul(int base, int max_width, int (*ReadProc)(void *, int, int),
                  void *ReadProcArg, int *chars_scanned, int *negative,
                  int *overflow)
{
    int scan_state = start;
    int count = 0;
    int spaces = 0;
    u32 value = 0;
    u32 value_max = 0;
    int c;

    *negative = *overflow = 0;

    if (base < 0 || base == 1 || base > 36 || max_width < 1)
        scan_state = failure;
    else
        c = fetch();

    if (base != 0)
        value_max = 0xFFFFFFFFu / base;

    while (count <= max_width && c != -1 && !final_state(scan_state)) {
        switch (scan_state) {
        case start:
            if (isspace(c)) {
                c = fetch();
                count--;
                spaces++;
                break;
            }
            if (c == '+') {
                c = fetch();
            } else if (c == '-') {
                c = fetch();
                *negative = 1;
            }
            scan_state = check_for_zero;
            break;
        case check_for_zero:
            if (base == 0 || base == 16) {
                if (c == '0') {
                    scan_state = leading_zero;
                    c = fetch();
                    break;
                }
            }
            scan_state = need_digit;
            break;
        case leading_zero:
            if (c == 'X' || c == 'x') {
                base = 16;
                scan_state = need_digit;
                c = fetch();
                break;
            }
            if (base == 0)
                base = 8;
            scan_state = digit_loop;
            break;
        case need_digit:
        case digit_loop:
            if (base == 0)
                base = 10;
            if (!value_max)
                value_max = 0xFFFFFFFFu / base;
            if (isdigit(c)) {
                if ((c -= '0') >= base) {
                    if (scan_state == digit_loop)
                        scan_state = finished;
                    else
                        scan_state = failure;
                    c += '0';
                    break;
                }
            } else if (!isalpha(c) || (toupper(c) - 'A' + 10) >= base) {
                if (scan_state == digit_loop)
                    scan_state = finished;
                else
                    scan_state = failure;
                break;
            } else {
                c = toupper(c) - 'A' + 10;
            }
            if (value > value_max)
                *overflow = 1;
            value *= base;
            if (c > (0xFFFFFFFFu - value))
                *overflow = 1;
            value += c;
            scan_state = digit_loop;
            c = fetch();
            break;
        }
    }

    if (!success(scan_state)) {
        count = value = 0;
        *chars_scanned = 0;
    } else {
        count--;
        *chars_scanned = count + spaces;
    }
    unfetch(c);
    return value;
}
