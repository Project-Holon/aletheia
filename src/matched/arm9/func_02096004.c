/*
 * function: __strtoull
 * address:  0x02096004
 * packet:   pkt_020949F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * MSL __strtoull: the 64-bit twin of src/matched/__strtoul.c (__strtoul),
 * driven by the strtoll wrapper strtoll.  Identical source with
 * `value`/`value_max` widened to unsigned long long and ULLONG_MAX in both
 * places; ULLONG_MAX / base goes through _ll_udiv with the int base
 * sign-extended (`asr r3, sb, #0x1f`), and the constant -1 lives in one stack
 * slot (sp+0x18) that serves both EOF and ULLONG_MAX.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/__strtoull.c \
 *       --func __strtoull --addr 0x02096004 --cc 1.1p1 --arm
 *   EXACT, 1012 bytes, 4 relocation sites, all resolved.
 *
 * symbols:
 *   __ctype_map    0x020A61DC  data  a2
 *   __upper_map    0x020A615C  data  a1
 *   _ll_udiv       0x0209C00C  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern const u16 __ctype_map[];
extern const u8 __upper_map[];
typedef unsigned long long u64;

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

u64 __strtoull(int base, int max_width, int (*ReadProc)(void *, int, int),
                  void *ReadProcArg, int *chars_scanned, int *negative,
                  int *overflow)
{
    int scan_state = start;
    int count = 0;
    int spaces = 0;
    u64 value = 0;
    u64 value_max = 0;
    int c;

    *negative = *overflow = 0;

    if (base < 0 || base == 1 || base > 36 || max_width < 1)
        scan_state = failure;
    else
        c = fetch();

    if (base != 0)
        value_max = 0xFFFFFFFFFFFFFFFFull / base;

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
                value_max = 0xFFFFFFFFFFFFFFFFull / base;
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
            if (c > (0xFFFFFFFFFFFFFFFFull - value))
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
