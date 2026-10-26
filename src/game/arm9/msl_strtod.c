/*
 * file:     msl_strtod.c
 * unit:     yes
 * function: __strtold, strtod, atof, __strtoul, strtoul, strtol, __strtoull, strtoll, atoi, atoll
 * address:  0x02094B8C
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
 *   errno  0x02153FAC  data
 *   _ll_udiv  0x0209C00C  arm
 *   fabs  0x0209A504  arm
 *   __float_huge  0x020A8814  data
 *   __ctype_map  0x020A61DC  data  a2
 *   s_infinity     0x020A62E4  data  a1
 *   s_nan          0x020A62DC  data  a1
 *   __upper_map    0x020A615C  data  a1
 *   __double_huge  0x020A881C  data  a4
 *   nan 0x02091374 arm arm9
 *   MSL_C_LIB_StrReadProc 0x020946D8 arm arm9
 *   __dec2num 0x0209739C arm arm9
 *   _dgr                         0x0209B864  arm
 *   _dls                         0x0209B9A0  arm
 *   _dneq                        0x0209BAC8  arm
 *   _dsub                        0x0209AF34  arm
 *   _f2d                         0x0209BD38  arm
 *   _fsub                        0x0209CB8C  arm
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "msl_crt_shared_types.h"
#include "msl_stdio_shared_types.h"
#include "msl_strtod_shared_types.h"

#define isalpha(c)  (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x1))

#define isspace(c)  (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x100))

#define isxdigit(c) (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x400))

#define toupper(c)  (((c) < 0 || (c) >= 0x80) ? (c) : __upper_map[c])

#define INFINITY __float_huge

#define HUGE_VAL __double_huge

#define hex_success(count, s) ((count) - 1 > 2 && ((s) & (hex_leading_sig_zeroes | \
                           hex_int_digit_loop | hex_frac_digit_loop | \
                           hex_leading_exp_zeroes | hex_exp_digit_loop)))

#define fetch()    (count++, (*ReadProc)(ReadProcArg, 0, 0))

#define unfetch(c) (*ReadProc)(ReadProcArg, c, 1)

#include "../types.h"

typedef struct { unsigned char c[9]; } model9;

typedef struct { unsigned char c[5]; } model5;

enum scan_states {
    start              = 0x0001,
    sig_start          = 0x0002,
    leading_sig_zeroes = 0x0004,
    int_digit_loop     = 0x0008,
    frac_start         = 0x0010,
    frac_digit_loop    = 0x0020,
    sig_end            = 0x0040,
    exp_start          = 0x0080,
    leading_exp_digit  = 0x0100,
    leading_exp_zeroes = 0x0200,
    exp_digit_loop     = 0x0400,
    finished           = 0x0800,
    failure            = 0x1000,
    nan_state          = 0x2000,
    infin_state        = 0x4000,
    hex_state          = 0x8000
};

enum hex_scan_states {
    not_hex                = 0x0000,
    hex_start              = 0x0001,
    hex_leading_sig_zeroes = 0x0002,
    hex_int_digit_loop     = 0x0004,
    hex_frac_digit_loop    = 0x0008,
    hex_sig_end            = 0x0010,
    hex_exp_start          = 0x0020,
    hex_leading_exp_digit  = 0x0040,
    hex_leading_exp_zeroes = 0x0080,
    hex_exp_digit_loop     = 0x0100
};

#include "msl_fdlibm.h"

#include "msl_crt.h"

#include "msl_stdlib.h"

#include "msl_strtod.h"

/* Scan state of strtod, strtol and strtoll: the string reader state, then the results of the scan. */
typedef struct MslStrtoState {
    MslStringScan scan;
    int overflow;
    int negative;
    int length;
} MslStrtoState;

/* Scan state of strtod: the string reader state, the overflow flag and the scanned length. */
typedef struct MslStrtodState {
    MslStringScan scan;
    int overflow;
    int length;
} MslStrtodState;

#include "msl_ansi_fp.h"

extern const unsigned short __ctype_map[];

extern const u8 __upper_map[];

extern float __float_huge;

extern double __double_huge;

extern const model9 s_infinity;

extern const model5 s_nan;

extern int errno;

#define isdigit(c)  (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x8))

#define final_state(s) ((s) & (finished | failure))

#define success(s) ((s) & (leading_sig_zeroes | int_digit_loop | frac_digit_loop | \
                           leading_exp_zeroes | exp_digit_loop | finished))

/*
 * MSL __strtold (C99 soft-float number scanner, decimal and hex paths).
 *
 * EXACT, 3864 bytes against 3864, 17 of 17 relocation sites resolved
 * (match.py one, 1.1p1 -O4,p, 2026-09-24, wave 21 lane A).
 *
 * What closed the MATCH cap: the two local model arrays.  MSL writes them
 * as `unsigned char model[] = "INFINITY";` and `... = "NAN(";`, which makes
 * the compiler emit anonymous string literals (@52/@70) into the object's
 * own .rodata; those two ABS32 pool words (+0x0EF0, +0x0EF4) had no name
 * and no witness.  Here each array is a one-member struct copied from an
 * extern pinned to the address the image's pool word names (0x020A62E4
 * "INFINITY", 0x020A62DC "NAN("), the same treatment as a __FILE__ string
 * (docs/idioms/file-string-is-an-abs32-into-the-string-area.md).  The
 * struct copy is byte-identical to the literal initialiser (same 4x2-byte
 * copy loop plus tail byte, same unrolled 5-byte copy).  s_infinity attests
 * by `string`, s_nan and __double_huge by sole-ref.
 *
 * Register colouring of the hex tail: the hex block declares hexresult,
 * ui2, ch2, p, hch in that order (wave 20 lane 20M); see
 * docs/idioms/declaration-position-orders-block-scope-colouring.md and
 * docs/notes/pkt_02094B8C.c.txt.
 */
double __strtold(int max_width, int (*ReadProc)(MslStringScan *, u32, u32), void *ReadProcArg,
                     int *chars_scanned, int *overflow)
{
    int scan_state = start;
    int hex_scan_state = not_hex;
    int count = 0;
    int spaces = 0;
    int c;
    decimal2 d = {0, 0, 0, {0, ""}};
    int sig_negative = 0;
    int exp_negative = 0;
    long exp_value = 0;
    int exp_adjust = 0;
    double result;
    int sign_detected = 0;
    unsigned char *chptr;
    unsigned char mantissa[8];
    unsigned char uch, uch1;
    unsigned long ui = 0;
    unsigned long chindex;
    int NibbleIndex;
    int expsign = 0;
    int exp_negsign = 0;
    unsigned intdigits = 0;
    unsigned maxdigits;

    *overflow = 0;
    c = fetch();

    while (count <= max_width && c != -1 && !final_state(scan_state))
    {
        switch (scan_state)
        {
        case start:
            if (isspace(c))
            {
                c = fetch();
                count--;
                spaces++;
                break;
            }
            switch (toupper(c))
            {
            case '-':
                sig_negative = 1;
            case '+':
                c = fetch();
                sign_detected = 1;
                break;
            case 'I':
                c = fetch();
                scan_state = infin_state;
                break;
            case 'N':
                c = fetch();
                scan_state = nan_state;
                break;
            default:
                scan_state = sig_start;
                break;
            }
            break;

        case infin_state:
        {
            int i = 1;
            model9 model = s_infinity;

            while ((i < 8) && (toupper(c) == model.c[i]))
            {
                i++;
                c = fetch();
            }
            if ((i == 3) || (i == 8))
            {
                if (sig_negative)
                    result = -INFINITY;
                else
                    result = INFINITY;
                *chars_scanned = spaces + i + sign_detected;
                return result;
            }
            else
                scan_state = failure;
            break;
        }

        case nan_state:
        {
            int i = 1, j = 0;
            model5 model = s_nan;
            char nan_arg[32] = "";

            while ((i < 4) && (toupper(c) == model.c[i]))
            {
                i++;
                c = fetch();
            }
            if ((i == 3) || (i == 4))
            {
                if (i == 4)
                {
                    while ((j < 32) && (isdigit(c) || isalpha(c) || c == '.'))
                    {
                        nan_arg[j++] = c;
                        c = fetch();
                    }
                    if (c != ')')
                    {
                        scan_state = failure;
                        break;
                    }
                    else
                        j++;
                }
                nan_arg[j] = '\0';
                if (sig_negative)
                    result = -nan(nan_arg);
                else
                    result = nan(nan_arg);
                *chars_scanned = spaces + i + j + sign_detected;
                return result;
            }
            else
                scan_state = failure;
            break;
        }

        case sig_start:
            if (c == '.')
            {
                scan_state = frac_start;
                c = fetch();
                break;
            }
            if (!isdigit(c))
            {
                scan_state = failure;
                break;
            }
            if (c == '0')
            {
                c = fetch();
                if (toupper(c) == 'X')
                {
                    scan_state = hex_state;
                    hex_scan_state = hex_start;
                }
                else
                    scan_state = leading_sig_zeroes;
                break;
            }
            scan_state = int_digit_loop;
            break;

        case leading_sig_zeroes:
            if (c == '0')
            {
                c = fetch();
                break;
            }
            scan_state = int_digit_loop;
            break;

        case int_digit_loop:
            if (!isdigit(c))
            {
                if (c == '.')
                {
                    scan_state = frac_digit_loop;
                    c = fetch();
                }
                else
                    scan_state = sig_end;
                break;
            }
            if (d.sig.length < 20)
                d.sig.text[d.sig.length++] = c;
            else
                exp_adjust++;
            c = fetch();
            break;

        case frac_start:
            if (!isdigit(c))
            {
                scan_state = failure;
                break;
            }
            scan_state = frac_digit_loop;
            break;

        case frac_digit_loop:
            if (!isdigit(c))
            {
                scan_state = sig_end;
                break;
            }
            if (d.sig.length < 20)
            {
                if (c != '0' || d.sig.length)
                    d.sig.text[d.sig.length++] = c;
                exp_adjust--;
            }
            c = fetch();
            break;

        case sig_end:
            if (toupper(c) == 'E')
            {
                scan_state = exp_start;
                c = fetch();
                break;
            }
            scan_state = finished;
            break;

        case exp_start:
            if (c == '+')
            {
                c = fetch();
            }
            else if (c == '-')
            {
                c = fetch();
                exp_negative = 1;
            }
            scan_state = leading_exp_digit;
            break;

        case leading_exp_digit:
            if (!isdigit(c))
            {
                scan_state = failure;
                break;
            }
            if (c == '0')
            {
                scan_state = leading_exp_zeroes;
                c = fetch();
                break;
            }
            scan_state = exp_digit_loop;
            break;

        case leading_exp_zeroes:
            if (c == '0')
            {
                c = fetch();
                break;
            }
            scan_state = exp_digit_loop;
            break;

        case exp_digit_loop:
            if (!isdigit(c))
            {
                scan_state = finished;
                break;
            }
            exp_value = exp_value * 10 + (c - '0');
            if (exp_value > 308)
                *overflow = 1;
            c = fetch();
            break;

        case hex_state:
            switch (hex_scan_state)
            {
            case hex_start:
                chptr = (unsigned char *)&mantissa;
                intdigits = 0;
                maxdigits = 14;
                chptr[0] = 0;
                chptr[1] = 0;
                chptr[2] = 0;
                chptr[3] = 0;
                chptr[4] = 0;
                chptr[5] = 0;
                chptr[6] = 0;
                chptr[7] = 0;
                NibbleIndex = 0;
                hex_scan_state = hex_leading_sig_zeroes;
                c = fetch();
                break;

            case hex_leading_sig_zeroes:
                if (c == '0')
                {
                    c = fetch();
                    break;
                }
                hex_scan_state = hex_int_digit_loop;
                break;

            case hex_int_digit_loop:
                if (!isxdigit(c))
                {
                    if (c == '.')
                    {
                        hex_scan_state = hex_frac_digit_loop;
                        c = fetch();
                    }
                    else
                        hex_scan_state = hex_sig_end;
                    break;
                }
                if (intdigits < maxdigits)
                {
                    intdigits++;
                    uch = chptr[NibbleIndex / 2];
                    c = toupper(c);
                    uch1 = (c >= 'A') ? c - 'A' + 10 : c - '0';
                    if (NibbleIndex % 2)
                        uch |= uch1;
                    else
                        uch |= (unsigned char)(uch1 << 4);
                    chptr[NibbleIndex++ / 2] = uch;
                    c = fetch();
                    break;
                }
                c = fetch();
                break;

            case hex_frac_digit_loop:
                if (!isxdigit(c))
                {
                    hex_scan_state = hex_sig_end;
                    break;
                }
                if (intdigits < maxdigits)
                {
                    uch = chptr[NibbleIndex / 2];
                    c = toupper(c);
                    uch1 = (c >= 'A') ? c - 'A' + 10 : c - '0';
                    if (NibbleIndex % 2)
                        uch |= uch1;
                    else
                        uch |= (unsigned char)(uch1 << 4);
                    chptr[NibbleIndex++ / 2] = uch;
                    c = fetch();
                    break;
                }
                c = fetch();
                break;

            case hex_sig_end:
                if (toupper(c) == 'P')
                {
                    hex_scan_state = hex_exp_start;
                    c = fetch();
                    break;
                }
                scan_state = finished;
                break;

            case hex_exp_start:
                if (c == '-')
                    exp_negsign = 1;
                else if (c != '+')
                {
                    unfetch(c);
                    count--;
                }
                hex_scan_state = hex_leading_exp_digit;
                c = fetch();
                break;

            case hex_leading_exp_digit:
                if (!isdigit(c))
                {
                    scan_state = failure;
                    break;
                }
                if (c == '0')
                {
                    hex_scan_state = hex_leading_exp_zeroes;
                    c = fetch();
                    break;
                }
                hex_scan_state = hex_exp_digit_loop;
                break;

            case hex_leading_exp_zeroes:
                if (c == '0')
                {
                    c = fetch();
                    break;
                }
                hex_scan_state = hex_exp_digit_loop;
                break;

            case hex_exp_digit_loop:
                if (!isdigit(c))
                {
                    scan_state = finished;
                    break;
                }
                expsign = expsign * 10 + (c - '0');
                if (exp_value > 0x7FFF)
                    *overflow = 1;
                c = fetch();
                break;
            }
            break;
        }
    }

    if (scan_state != hex_state ? !success(scan_state) : !hex_success(count, hex_scan_state))
    {
        count = 0;
        *chars_scanned = 0;
    }
    else
    {
        count--;
        *chars_scanned = count + spaces;
    }

    unfetch(c);

    if (hex_scan_state == not_hex)
    {
        if (exp_negative)
            exp_value = -exp_value;
        {
            int n = d.sig.length;
            unsigned char *p = &d.sig.text[n];

            while (n-- && *--p == '0')
                exp_adjust++;
            d.sig.length = n + 1;
            if (d.sig.length == 0)
                d.sig.text[d.sig.length++] = '0';
        }
        if (exp_value < -308 || exp_value > 308)
        {
            if (*overflow == 0 && d.sig.text[0] == '0' && d.sig.text[1] == 0)
                return 0.0;
            *overflow = 1;
        }
        exp_value += exp_adjust;
        if (*overflow)
        {
            if (exp_negative)
                return 0.0;
            else
                return sig_negative ? -HUGE_VAL : HUGE_VAL;
        }
        d.exp = (short)exp_value;
        result = __dec2num(&d);
        if (result != 0.0 && result < 2.2250738585072014e-308)
        {
            *overflow = 1;
        }
        else if (result > 1.7976931348623157e+308)
        {
            *overflow = 1;
            result = HUGE_VAL;
        }
        if (sig_negative && success(scan_state))
            result = -result;
        return result;
    }
    else
    {
        double hexresult;
        unsigned long ui2;
        unsigned long ch2;
        unsigned char *p = (unsigned char *)&hexresult;
        unsigned char hch;

        if (exp_negsign)
            expsign = -expsign;
        expsign += intdigits * 4;
        hch = mantissa[0];
        for (ui = 0; ui < 4 && !(hch & (0x80 >> ui)); ui++)
            expsign--;
        expsign--;
        if ((chindex = ++ui) != 0)
        {
            uch1 = 0;
            for (chptr = mantissa + 7; chptr >= mantissa; chptr--)
            {
                hch = *chptr;
                *chptr = (hch << chindex) | uch1;
                uch1 = hch >> (8 - chindex);
            }
        }
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
        p[7] = 0;
        for (ui2 = 0, ch2 = 12; ui2 < 52; ui2 += 8)
        {
            hch = mantissa[ui2 / 8];
            if (ui2 + 8 > 52)
                hch &= 0xff << (52 - ui2);
            NibbleIndex = ch2 % 8;
            p[ch2 / 8] |= (unsigned char)(hch >> NibbleIndex);
            ch2 += 8;
#ifdef __MWERKS__
            p[ch2 / 8] |= (unsigned char)(hch << (8 - NibbleIndex));
#else
            if (ch2 / 8 < sizeof(hexresult))
                p[ch2 / 8] |= (unsigned char)(hch << (8 - NibbleIndex));
#endif
        }
        expsign += exp_value + 0x3FF;
        if (expsign & ~0x7FF)
        {
            *overflow = 1;
            return 0.0;
        }
        p[0] |= (unsigned)(expsign << 21) >> 25;
        p[1] |= (unsigned)(expsign << 21) >> 17;
        if (sig_negative)
            p[0] |= 0x80;
        for (NibbleIndex = 0; NibbleIndex < 4; NibbleIndex++)
        {
            hch = p[NibbleIndex];
            p[NibbleIndex] = p[7 - NibbleIndex];
            p[7 - NibbleIndex] = hch;
        }
        return *(double *)p;
    }
}

/*
 * PROMOTED from src/pending/ with no change to the C (lane r5c, 2026-09-19):
 * the park's only blocker was the PC24 at +0x34, and 0x02094B8C is now a
 * layout/runtime_arm9.txt entry (_msl_scanf_strtod_core), so that site
 * attests as `runtime` and every relocation resolves:
 *
 *   +0034 PC24 __strtold   -> 02094B8C  [runtime x1, e.g. 02094B8C]
 *   +0058 PC24 fabs   -> 0209A504  [label x15, e.g. 02093310]
 *   +0080 ABS32 MSL_C_LIB_StrReadProc  -> 020946D8  [literal x15, e.g. 02095F38]
 *   +0084 ABS32 errno     -> 02153FAC  [literal x35, e.g. 02091D34]
 *
 * EXACT* and not EXACT: the compiled body is 136 bytes and the listing extent
 * is 152, because the follower at 0x02095B2C is the linker stub
 * (`ldr ip,[pc,#4]; mov r1,#0; bx ip; .word 0x02095AA4`), which carries no
 * func_ label and is not producible from C, so the inferred extent runs long
 * over it.  No byte inside the compared range differs.
 */
double strtod(const char *s, char **endptr)
{
    MslStrtodState st;
    double r;

    st.scan.eof = 0;
    st.scan.cur = s;
    r = __strtold(0x7FFFFFFF, MSL_C_LIB_StrReadProc, &st, &st.length, &st.overflow);
    if (endptr != 0)
        *endptr = (char *)s + st.length;
    fabs(r);
    if (st.overflow != 0)
        errno = 0x22;
    return r;
}

/*
 * sdk:      FATFS_FormatDrive (libfatfs.TWL.HYB.a fatfs_api.o)
 */
double atof(const char *s)
{
    return strtod(s, 0);
}

#undef isdigit

#undef isdigit

#define isdigit(c) (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x8))

#undef final_state

#undef final_state

#undef final_state

#define final_state(s) ((s) & (dec_finished | dec_failure))

#undef success

#undef success

#undef success

#define success(s)     ((s) & (leading_zero | digit_loop | dec_finished))

/*
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
 */
u32 __strtoul(int base, int max_width, int (*ReadProc)(MslStringScan *, u32, u32),
                  void *ReadProcArg, int *chars_scanned, int *negative,
                  int *overflow)
{
    int scan_state = dec_start;
    int count = 0;
    int spaces = 0;
    u32 value = 0;
    u32 value_max = 0;
    int c;

    *negative = *overflow = 0;

    if (base < 0 || base == 1 || base > 36 || max_width < 1)
        scan_state = dec_failure;
    else
        c = fetch();

    if (base != 0)
        value_max = 0xFFFFFFFFu / base;

    while (count <= max_width && c != -1 && !final_state(scan_state)) {
        switch (scan_state) {
        case dec_start:
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
                        scan_state = dec_finished;
                    else
                        scan_state = dec_failure;
                    c += '0';
                    break;
                }
            } else if (!isalpha(c) || (toupper(c) - 'A' + 10) >= base) {
                if (scan_state == digit_loop)
                    scan_state = dec_finished;
                else
                    scan_state = dec_failure;
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

/*
 * MSL strtoul: the unsigned member of the strtoX wrapper family over the
 * scanner core at 0x02095B3C.  Four lanes and twenty-five spellings left this
 * at one instruction out (+0x70, `mvnne r0, #0` against 1.1p1's
 * `subne r0, r1, #0x23` fold from the 0x22 errno value) because every one of
 * them RETURNED the -1 from inside the error block.  The MSL source does not:
 *
 *     if (overflow) { value = ULONG_MAX; errno = ERANGE; }
 *     else if (negative) value = -value;
 *     return value;
 *
 * The -1 is assigned to the result variable BEFORE the errno store, the
 * negation is an ELSE-IF, and there is one return.  Under that shape the
 * value is a definition of `r` rather than a return constant and the back
 * end rematerialises it with `mvn`; the same compiler, no pin.  The return
 * type is u32 (unsigned long) and the core's return is u32 as well.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/strtoul.c \
 *       --func strtoul --addr 0x02095EAC --cc 1.1p1 --arm
 *   EXACT, 148 bytes, 3 relocation sites, all resolved.
 */
u32 strtoul(const char *s, char **endptr, int base)
{
    u32 len;
    u32 sign;
    u32 err;
    MslStringScan scan;
    u32 r;

    scan.cur = s;
    scan.eof = 0;
    r = __strtoul(base, 0x7FFFFFFFu, MSL_C_LIB_StrReadProc, &scan, (int *)(&len), (int *)(&sign), (int *)(&err));
    if (endptr != 0)
        *endptr = (char *)s + len;
    if (err != 0) {
        r = 0xFFFFFFFFu;
        errno = 0x22;
    } else if (sign != 0)
        r = -r;
    return r;
}

/*
 * The 32-bit member of the decimal-to-integer family (strtoul,
 * strtoll are its siblings and differ only in their callee and in the
 * width of the clamped result).  It runs the parser at 0x02095B3C over a
 * five-word working buffer with the sign flag 0x7FFFFFFF and the default
 * radix, stores the end-of-digits pointer through the optional out parameter,
 * and clamps the parsed magnitude to the int range: with a cleared sign a
 * magnitude above 0x7FFFFFFF does not fit and with a set sign the magnitude
 * may reach 0x80000000, after which the result is negated.
 *
 * Two things pin the source shape:
 *
 *  - The three range conditions have to be ONE disjunction.  Written as an
 *    if/else the shared error block is laid out after the final return and
 *    the whole tail shifts; as `||` the block lands exactly where the
 *    original has it, between the second range test and the negation, and
 *    the second test's branch inverts to `bls` over the error block.
 *  - The saturating values are INT_MIN for a set sign and INT_MAX for a
 *    cleared one.  mwcc materialises the pair as `movne r0, #0x80000000` /
 *    `mvneq r0, #0x80000000`, and the second is a `mvn` of 0x80000000, i.e.
 *    0x7FFFFFFF, not the same value written twice: a source whose two arms
 *    are equal is folded to a single `mov` and loses both the compare and
 *    twelve bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/strtol.c \
 *       --func strtol --addr 0x02095F40 --cc 1.1p1 --arm
 *   EXACT, 196 bytes, 3 relocation sites, all resolved.
 */
int strtol(const char *s, char **endptr, int base)
{
    MslStrtoState st;
    int r;
    int v;

    st.scan.cur = s;
    st.scan.eof = 0;
    r = (int)__strtoul(base, 0x7FFFFFFFu, MSL_C_LIB_StrReadProc, &st,
                           &st.length, &st.negative, &st.overflow);
    if (endptr != 0)
        *endptr = (char *)s + st.length;
    if (st.overflow != 0 ||
        (st.negative == 0 && (u32)r > 0x7FFFFFFFu) ||
        (st.negative != 0 && (u32)r > 0x80000000u)) {
        v = (st.negative != 0) ? (int)0x80000000 : (int)0x7FFFFFFF;
        errno = 0x22;
        return v;
    }
    if (st.negative != 0)
        r = -r;
    return r;
}

#undef isdigit

#undef isdigit

#define isdigit(c) (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x8))

/*
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
 */
u64 __strtoull(int base, int max_width, int (*ReadProc)(MslStringScan *, u32, u32),
                  void *ReadProcArg, int *chars_scanned, int *negative,
                  int *overflow)
{
    int scan_state = dec_start;
    int count = 0;
    int spaces = 0;
    u64 value = 0;
    u64 value_max = 0;
    int c;

    *negative = *overflow = 0;

    if (base < 0 || base == 1 || base > 36 || max_width < 1)
        scan_state = dec_failure;
    else
        c = fetch();

    if (base != 0)
        value_max = 0xFFFFFFFFFFFFFFFFull / base;

    while (count <= max_width && c != -1 && !final_state(scan_state)) {
        switch (scan_state) {
        case dec_start:
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
                        scan_state = dec_finished;
                    else
                        scan_state = dec_failure;
                    c += '0';
                    break;
                }
            } else if (!isalpha(c) || (toupper(c) - 'A' + 10) >= base) {
                if (scan_state == digit_loop)
                    scan_state = dec_finished;
                else
                    scan_state = dec_failure;
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

/*
 *           range: the only branch to it anywhere in the image is the bl in
 *           this function (it has a func_ label, but the label class needs a
 *           branch from outside the compared range as well), so that one
 *           relocation stays wildcarded and the file cannot be EXACT.  The
 *           file becomes EXACT* the day 0x02096004 gets a shard entry.
 *
 * bcd_to_s64: the 64-bit sibling of strtoul/strtol.  It hands
 * the decimal parser __strtoull a working buffer, a pointer to the first
 * byte after the parsed digits and a sign flag, then clamps the parsed
 * magnitude to the s64 range: with a zero sign a magnitude above
 * 0x7FFFFFFFFFFFFFFF does not fit, with a set sign the magnitude may reach
 * 0x8000000000000000, and the result is negated for the sign.
 *
 * The error path returns the saturating extremes of the original's own sign
 * flag, which is why the reserved word errno is set to 0x22 there.
 *
 * The bounded-magnitude test has to be one disjunction: written as an
 * if/else the shared error block is laid out after the final return and the
 * whole tail moves (66 bytes), while `||` over the three conditions places it
 * exactly where the original has it, between the second range test and the
 * negation.  The `-r` and the return then share one epilogue.
 *
 * trailing star: the listing's extent for this address runs to 0x02096508
 * because everything between the last code byte (0x020964D8) and the next
 * label is unlabelled: this function's own two-word pool at 0x020964D8 and
 * two sixteen-byte argument-defaulting thunks at 0x020964E0 and 0x020964F4
 * (`ldr ip,[pc,#8]; mov r1,#0; mov r2,#0xa; bx ip` -> 0x02095F40 and
 * 0x020963F8).  Needs seeds for both thunk addresses in
 * layout/function_starts.txt; neither is producible from C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/strtoll.c \
 *       --func strtoll --addr 0x020963F8 --cc 1.1p1 --arm
 *   MATCH* with no concrete byte differing; EXACT* once the symbols above
 *   are declared and the two thunk addresses are labelled.
 */
s64 strtoll(const char *s, char **endptr, int base)
{
    MslStrtoState st;
    s64 r;
    s64 v;

    st.scan.cur = s;
    st.scan.eof = 0;
    r = (s64)__strtoull(base, 0x7FFFFFFFu, MSL_C_LIB_StrReadProc, &st,
                           &st.length, &st.negative, &st.overflow);
    if (endptr != 0)
        *endptr = (char *)s + st.length;
    if (st.overflow != 0 ||
        (st.negative == 0 && (u64)r > 0x7FFFFFFFFFFFFFFFULL) ||
        (st.negative != 0 && (u64)r > 0x8000000000000000ULL)) {
        v = (st.negative != 0) ? (s64)0x8000000000000000ULL
                          : (s64)0x7FFFFFFFFFFFFFFFULL;
        errno = 0x22;
        return v;
    }
    if (st.negative != 0)
        r = -r;
    return r;
}

/*
 * Argument-defaulting thunk: call the int decimal parser strtol with
 * a null out-pointer and radix 10.  It is the `atoi` entry point the overlay
 * error parser uses.  Reproducible from C as an ordinary tail call; the
 * previous note that claimed otherwise was wrong.
 */
int atoi(const char *s)
{
    return strtol(s, 0, 10);
}

/*
 * Argument-defaulting thunk: call the s64 decimal parser strtoll with
 * a null out-pointer and radix 10.  Reproducible from C as an ordinary tail
 * call; the previous note that claimed otherwise was wrong.
 */
long long atoll(const char *s)
{
    return strtoll(s, 0, 10);
}
