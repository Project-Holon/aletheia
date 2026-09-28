/*
 * function: func_02096990
 * address:  0x02096990
 * packet:   pkt_020949F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * MSL __two_exp (ansi_fp.c): 2^exp as a decimal record.  A switch over the
 * tabulated exponents -64, -53, -32, -16 and -8..8, each arm handing a digit
 * string and a decimal exponent to __str2dec (func_020968F4); every other
 * exponent recurses on exp/2 (spelled the MSL way,
 * `((long)((0x80000000UL & exp) >> 31) + exp) >> 1`), squares the half with
 * __timesdec (func_02096774), and on an odd exponent copies the result to a
 * stack temporary and multiplies by "2" (exp > 0) or "5"e-1.  `decimal x2,
 * temp;` in that order puts temp at sp+0 and x2 at sp+0x26.
 *
 * Earlier notes (docs/notes/pkt_02096990.c.txt) held this out of scope for
 * lack of witnesses on the 21 digit strings; under the widened sole-ref
 * class every one resolves (`string` or `sole-ref`), so the body is EXACT.
 * The strings are declared by address because they sit in the packed MSL
 * rodata area and mwcc would otherwise emit its own copies.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02096990.c \
 *       --func func_02096990 --addr 0x02096990 --cc 1.1p1 --arm
 *   EXACT, 896 bytes, 46 relocation sites, all resolved.
 *
 * symbols:
 *   func_020968F4  0x020968F4  arm
 *   func_02096774  0x02096774  arm
 *   s_020A8ABC     0x020A8ABC  data  a1
 *   s_020A8AEC     0x020A8AEC  data  a1
 *   s_020A8B14     0x020A8B14  data  a1
 *   s_020A8B2C     0x020A8B2C  data  a1
 *   s_020A8B3C     0x020A8B3C  data  a1
 *   s_020A8B44     0x020A8B44  data  a1
 *   s_020A8B4C     0x020A8B4C  data  a1
 *   s_020A8B54     0x020A8B54  data  a1
 *   s_020A8B5C     0x020A8B5C  data  a1
 *   s_020A8B60     0x020A8B60  data  a1
 *   s_020A8B64     0x020A8B64  data  a1
 *   s_020A8B68     0x020A8B68  data  a1
 *   s_020A8B6C     0x020A8B6C  data  a1
 *   s_020A8B70     0x020A8B70  data  a1
 *   s_020A8B74     0x020A8B74  data  a1
 *   s_020A8B78     0x020A8B78  data  a1
 *   s_020A8B7C     0x020A8B7C  data  a1
 *   s_020A8B80     0x020A8B80  data  a1
 *   s_020A8B84     0x020A8B84  data  a1
 *   s_020A8B88     0x020A8B88  data  a1
 *   s_020A8B8C     0x020A8B8C  data  a1
 */
typedef unsigned char u8;
typedef signed short s16;

typedef struct decimal {
    char sign;
    char unused;
    s16 exp;
    struct {
        u8 length;
        u8 text[32];
        u8 unused;
    } sig;
} decimal;

extern const char s_020A8ABC[];
extern const char s_020A8AEC[];
extern const char s_020A8B14[];
extern const char s_020A8B2C[];
extern const char s_020A8B3C[];
extern const char s_020A8B44[];
extern const char s_020A8B4C[];
extern const char s_020A8B54[];
extern const char s_020A8B5C[];
extern const char s_020A8B60[];
extern const char s_020A8B64[];
extern const char s_020A8B68[];
extern const char s_020A8B6C[];
extern const char s_020A8B70[];
extern const char s_020A8B74[];
extern const char s_020A8B78[];
extern const char s_020A8B7C[];
extern const char s_020A8B80[];
extern const char s_020A8B84[];
extern const char s_020A8B88[];
extern const char s_020A8B8C[];

extern void func_020968F4(decimal *d, const char *s, s16 exp);
extern void func_02096774(decimal *r, const decimal *x, const decimal *y);

void func_02096990(decimal *result, long exp)
{
    switch (exp) {
    case -64:
        func_020968F4(result, s_020A8ABC, -20);
        return;
    case -53:
        func_020968F4(result, s_020A8AEC, -16);
        return;
    case -32:
        func_020968F4(result, s_020A8B14, -10);
        return;
    case -16:
        func_020968F4(result, s_020A8B2C, -5);
        return;
    case -8:
        func_020968F4(result, s_020A8B3C, -3);
        return;
    case -7:
        func_020968F4(result, s_020A8B44, -3);
        return;
    case -6:
        func_020968F4(result, s_020A8B4C, -2);
        return;
    case -5:
        func_020968F4(result, s_020A8B54, -2);
        return;
    case -4:
        func_020968F4(result, s_020A8B5C, -2);
        return;
    case -3:
        func_020968F4(result, s_020A8B60, -1);
        return;
    case -2:
        func_020968F4(result, s_020A8B64, -1);
        return;
    case -1:
        func_020968F4(result, s_020A8B68, -1);
        return;
    case 0:
        func_020968F4(result, s_020A8B6C, 0);
        return;
    case 1:
        func_020968F4(result, s_020A8B70, 0);
        return;
    case 2:
        func_020968F4(result, s_020A8B74, 0);
        return;
    case 3:
        func_020968F4(result, s_020A8B78, 0);
        return;
    case 4:
        func_020968F4(result, s_020A8B7C, 1);
        return;
    case 5:
        func_020968F4(result, s_020A8B80, 1);
        return;
    case 6:
        func_020968F4(result, s_020A8B84, 1);
        return;
    case 7:
        func_020968F4(result, s_020A8B88, 2);
        return;
    case 8:
        func_020968F4(result, s_020A8B8C, 2);
        return;
    }

    {
        decimal x2, temp;

        func_02096990(&x2, ((long)((0x80000000UL & exp) >> 31) + exp) >> 1);
        func_02096774(result, &x2, &x2);
        if (exp & 1) {
            temp = *result;
            if (exp > 0)
                func_020968F4(&x2, s_020A8B70, 0);
            else
                func_020968F4(&x2, s_020A8B68, -1);
            func_02096774(result, &temp, &x2);
        }
    }
}
