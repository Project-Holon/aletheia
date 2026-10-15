/*
 * function: __strtold
 * address:  0x02094B8C
 * packet:   pkt_02094B8C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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
 *
 * symbols:
 *   __ctype_map    0x020A61DC  data  a2
 *   __upper_map    0x020A615C  data  a1
 *   __float_huge   0x020A8814  data
 *   __double_huge  0x020A881C  data  a4
 *   __dec2num  0x0209739C  arm
 *   nan  0x02091374  arm
 *   _fsub          0x0209CB8C  arm
 *   _f2d           0x0209BD38  arm
 *   _dsub          0x0209AF34  arm
 *   _dneq          0x0209BAC8  arm
 *   _dls           0x0209B9A0  arm
 *   _dgr           0x0209B864  arm
 *   s_infinity     0x020A62E4  data  a1
 *   s_nan          0x020A62DC  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct decimal {
    unsigned char sign;
    char unused;
    short exp;
    struct {
        unsigned char length;
        unsigned char text[32];
        unsigned char unused;
    } sig;
} decimal;

extern const u16 __ctype_map[];
extern const u8 __upper_map[];
extern float __float_huge;
extern double __double_huge;
typedef struct { unsigned char c[9]; } model9;
typedef struct { unsigned char c[5]; } model5;
extern const model9 s_infinity;
extern const model5 s_nan;
extern double __dec2num(const decimal *d);      /* __dec2num */
extern double nan(const char *tagp);      /* nan */

#define isdigit(c)  (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x8))
#define isalpha(c)  (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x1))
#define isspace(c)  (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x100))
#define isxdigit(c) (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_map[c] & 0x400))
#define toupper(c)  (((c) < 0 || (c) >= 0x80) ? (c) : __upper_map[c])

#define INFINITY __float_huge
#define HUGE_VAL __double_huge

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

#define final_state(s) ((s) & (finished | failure))
#define success(s) ((s) & (leading_sig_zeroes | int_digit_loop | frac_digit_loop | \
                           leading_exp_zeroes | exp_digit_loop | finished))
#define hex_success(count, s) ((count) - 1 > 2 && ((s) & (hex_leading_sig_zeroes | \
                           hex_int_digit_loop | hex_frac_digit_loop | \
                           hex_leading_exp_zeroes | hex_exp_digit_loop)))

#define fetch()    (count++, (*ReadProc)(ReadProcArg, 0, 0))
#define unfetch(c) (*ReadProc)(ReadProcArg, c, 1)

double __strtold(int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg,
                     int *chars_scanned, int *overflow)
{
    int scan_state = start;
    int hex_scan_state = not_hex;
    int count = 0;
    int spaces = 0;
    int c;
    decimal d = {0, 0, 0, {0, ""}};
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
            p[ch2 / 8] |= (unsigned char)(hch << (8 - NibbleIndex));
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

