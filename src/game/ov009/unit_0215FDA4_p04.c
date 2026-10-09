/*
 * file:     unit_0215FDA4_p04.c
 * unit:     yes
 * function: func_02160108, func_02160130, func_0216017C, func_021601CC, func_02160238, func_021602B8, func_02160764
 * address:  0x02160108
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02150FEC  0x02150FEC  data
 *   func_020948E0  0x020948E0  arm
 *   cert_item_len  0x0216017C  arm  ov009
 *   MI_CpuCopy8    0x02082D44  arm
 *   strlen         0x0209477C  arm
 *   memcmp         0x020923F0  arm
 *   make_dn        0x021601CC  arm  ov009
 *   parse_time     0x02160238  arm  ov009
 *   object         0x021A1D48  data
 *   func_02164CC4  0x02164CC4  arm  ov009
 *   func_0216009C  0x0216009C  arm  ov009
 *   func_0216469C  0x0216469C  arm  ov009
 *   func_021600E4  0x021600E4  arm  ov009
 *   func_02164D20  0x02164D20  arm  ov009
 *   func_020923F0  0x020923F0  arm
 *   g_021A8280     0x021A8280  data
 *   g_021A82B0     0x021A82B0  data
 */
#include "../../matched/arm9_sdk/libc/memcmp/string.h"

typedef struct {
	char *name;
} CaInfo;

typedef struct {
	char pad0[0x814];
	CaInfo **rootCa;
	int rootCaNum;
} Con;

struct _CPSSslConnection {
    unsigned char pad0[0x458];
    unsigned int f458;
    unsigned int f45c;
    unsigned char *f460;
    unsigned char *f464;
    unsigned char pad1[0x484 - 0x468];
    unsigned int f484;
    unsigned char *f488;
    unsigned int f48c;
    unsigned char *f490;
    unsigned char f494[0x100];
    unsigned int f594;
    unsigned char f598[8];
    unsigned int f5a0;
    unsigned char *f5a4;
    unsigned int f5a8;
    unsigned char f5ac;
    unsigned char f5ad;
    unsigned char f5ae;
    unsigned char f5af;
    unsigned char f5b0[0x100];
    unsigned char f6b0[0x100];
    unsigned char f7b0[0x50];
    unsigned char pad4[0x80c - 0x800];
    unsigned int f80c;
};

typedef struct SOCLCaInfo {
    char *dn;
    int modulo_len;
    unsigned char *modulo;
    int exponent_len;
    unsigned char *exponent;
} SOCLCaInfo;

typedef struct CPSSslConnection {
    unsigned char pad0[0x468];
    unsigned char hash[0x47c - 0x468];  /* +0x468 */
    int hash_len;                       /* +0x47c */
    unsigned char pad480[0x5a4 - 0x480];
    unsigned char *sig;                 /* +0x5a4 */
    int sig_len;                        /* +0x5a8 */
} CPSSslConnection;

typedef unsigned char  u8;

extern int func_020948E0(const char *s1, const char *s2);
extern int cert_item_len(unsigned char **ps);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void make_dn(char *d, char *s, int len);
extern unsigned long parse_time(unsigned char *s, int type);
extern void func_02164CC4(unsigned short *d, unsigned char *s, int numbytes, int digits);
extern unsigned long func_0216009C(void);
extern void func_0216469C(unsigned short *c, unsigned short *a, unsigned short *b, int digits,
                          unsigned short *n);
extern void func_021600E4(unsigned long old_priority);
extern void func_02164D20(unsigned char *d, unsigned short *s, int numbytes, int digits);
extern int func_020923F0(const u8 *a, const u8 *b, int n);
/* * Hands a and b to the +0xc child of the object at +0xa4 as its +0x814 and * +0x818 words. */ void func_02160108(int a, int b);
/* * note: a do-while behind an `if (n > 0)` guard puts the list load after the loop entry test. * * sdk: get_rootCA (libssl.TWL.HYB.a(ssl.o)) */ CaInfo *func_02160130(Con *con, char *dn);
/* * sdk: cert_item_len (libssl.TWL.HYB.a(ssl.o)) */ static int func_0216017C(unsigned char **ps);
/* * sdk: make_dn (libssl.TWL.HYB.a(ssl.o)) */ static void func_021601CC(char *d, char *s, int len);
/* * sdk: parse_time (libssl.TWL.HYB.a(ssl.o)) */ static unsigned long func_02160238(unsigned char *s, int type);
extern char g_02150FEC[];
extern unsigned char *object[];

/* * sdk: cert_item_len (libssl.TWL.HYB.a(ssl.o)) */ static int func_0216017C(unsigned char **ps);

/* * sdk: make_dn (libssl.TWL.HYB.a(ssl.o)) */ static void func_021601CC(char *d, char *s, int len);

/* * sdk: parse_time (libssl.TWL.HYB.a(ssl.o)) */ static unsigned long func_02160238(unsigned char *s, int type);




/*
 * Hands a and b to the +0xc child of the object at +0xa4 as its +0x814 and
 * +0x818 words.
 */
void func_02160108(int a, int b)
{
    char *p = *(char **)(*(char **)(g_02150FEC + 4) + 0xa4);
    char *q;

    if (p != 0 && (q = *(char **)(p + 0xc)) != 0) {
        *(int *)(q + 0x814) = a;
        *(int *)(q + 0x818) = b;
    }
}




/*
 * note: a do-while behind an `if (n > 0)` guard puts the list load after the loop entry test.
 *
 * sdk:      get_rootCA (libssl.TWL.HYB.a(ssl.o))
 */
CaInfo *func_02160130(Con *con, char *dn)
{
	int i = 0;
	CaInfo **list;
	int n = con->rootCaNum;
	if (n > 0) {
		list = con->rootCa;
		do {
			CaInfo *ca = list[i];
			if (func_020948E0(ca->name, dn) == 0) {
				return ca;
			}
			i++;
		} while (i < n);
	}
	return 0;
}



/*
 * sdk:      cert_item_len (libssl.TWL.HYB.a(ssl.o))
 */
static int func_0216017C(unsigned char **ps)
{
    unsigned char *s;
    int len;
    int lenlen;

    s = *ps;
    len = *s++;
    if (len & 0x80) {
        lenlen = len & 0x7f;
        len = 0;
        while (lenlen--) {
            if (len & 0xff000000)
                return -1;
            len = (len << 8) + *s++;
        }
    }
    *ps = s;
    return len;
}



/*
 * sdk:      make_dn (libssl.TWL.HYB.a(ssl.o))
 */
static void func_021601CC(char *d, char *s, int len)
{
    char *d0;

    d0 = d;
    if (*d != 0) {
        do
            d++;
        while (*d != 0);
        if (d - d0 >= 255)
            return;
        *d++ = ',';
        *d++ = ' ';
    }
    while (len-- != 0 && d - d0 < 255)
        *d++ = *s++;
    *d = 0;
}



/*
 * sdk:      parse_time (libssl.TWL.HYB.a(ssl.o))
 */
static unsigned long func_02160238(unsigned char *s, int type)
{
    unsigned long year;

    year = s[0] * 10 + s[1] - 528;
    s += 2;
    if (type == 0x17) {
        if (year < 50)
            year += 2000;
        else
            year += 1900;
    } else {
        year = year * 100 + (s[0] * 10 + s[1] - 528);
        s += 2;
    }
    return (year << 16) + ((s[0] * 10 + s[1] - 528) << 8) + (s[2] * 10 + s[3] - 528);
}




static int cert_item(struct _CPSSslConnection *con, unsigned char **ps,
                     int level, int seq, int mode)
{
    unsigned char *s;
    unsigned char *end;
    int len;
    int i;
    unsigned char type;

    s = *ps;
    type = *s++;
    len = cert_item_len(&s);
    if (len < 0 || len > 0x7d0)
        return 1;

    switch (type & 0x1f) {
    case 2:
        if (con->f5ad != 0) {
            if (seq == 0) {
                while (*s == 0) {
                    s++;
                    len--;
                }
                switch (mode) {
                case 0:
                    if (len <= 0x100) {
                        MI_CpuCopy8(s, con->f494, len);
                        con->f594 = len;
                    }
                    break;
                case 2:
                    con->f484 = len;
                    con->f488 = s;
                    break;
                }
            } else if (seq == 1) {
                while (*s == 0) {
                    s++;
                    len--;
                }
                switch (mode) {
                case 0:
                    if (len <= 8) {
                        MI_CpuCopy8(s, con->f598, len);
                        con->f5a0 = len;
                    }
                    break;
                case 2:
                    con->f48c = len;
                    con->f490 = s;
                    break;
                }
            }
        }
        s += len;
        break;
    case 3:
        i = 0;
        if (level == 1 && mode != 2) {
            con->f5a4 = s + 1;
            con->f5a8 = len - 1;
        }
        if (con->f5ad != 0) {
            s++;
            if (cert_item(con, &s, level, i, mode) != 0)
                return 1;
            con->f5ad = 0;
            goto done;
        }
        s += len;
        break;
    case 6:
        for (i = 0; i < 6; i++) {
            if (memcmp(s, object[i], strlen((char *)object[i])) == 0) {
                switch (i) {
                case 1:
                case 2:
                    if (mode == 0)
                        con->f45c = i;
                    con->f5ad = i;
                    break;
                case 3:
                case 4:
                    if (mode != 2)
                        con->f458 = i;
                    break;
                case 5:
                    if (mode != 2)
                        con->f5ae = i;
                    break;
                }
                break;
            }
        }
        s += len;
        break;
    case 12:
    case 19:
    case 20:
    case 22:
        i = 0;
        if (mode != 2) {
            if (con->f5ac != 0) {
                make_dn((char *)con->f6b0, (char *)s, len);
                if (con->f5ae == 5 && len <= 0x4f) {
                    MI_CpuCopy8(s, con->f7b0, len);
                    con->f7b0[len] = 0;
                }
            } else {
                make_dn((char *)con->f5b0, (char *)s, len);
            }
        }
        con->f5ae = i;
        s += len;
        break;
    case 23:
    case 24:
        i = 1;
        if (mode != 2) {
            unsigned long cert_date;
            cert_date = parse_time(s, type & 0x1f);
            if (seq == 0) {
                if (con->f80c >= cert_date)
                    con->f5af = 1;
            } else {
                if (con->f80c > cert_date)
                    con->f5af = 0;
            }
        }
        s += len;
        con->f5ac = 1;
        goto done;
    case 16:
        if (level == 0 && seq == 0 && mode != 2)
            con->f460 = s;
        end = s + len;
        i = 0;
        while (s < end) {
            if (cert_item(con, &s, level + 1, i++, mode) != 0)
                return 1;
        }
        if (level == 1 && seq == 0 && mode != 2)
            con->f464 = s;
        goto done;
    case 17:
        end = s + len;
        while (s < end) {
            if (cert_item(con, &s, level + 1, 0, mode) != 0)
                return 1;
        }
        goto done;
    default:
        if (type == 0xa0) {
            end = s + len;
            while (s < end) {
                if (cert_item(con, &s, level + 1, 0, mode) != 0)
                    return 1;
            }
            goto done;
        }
        s += len;
        break;
    }

done:
    *ps = s;
    return 0;
}


extern unsigned short *(*g_021A8280)(unsigned long size);

extern void (*g_021A82B0)(void *p);


/*
 * sdk:      validate_signature (libssl.TWL.HYB.a(ssl.o))
 *
 * The DWARF declares CPSi_char_from_big(d, s, numbytes); the call site also
 * loads digits into r3, so the file passes it as a fourth argument.
 */
static int func_02160764(CPSSslConnection *con, SOCLCaInfo *ca)
{
    unsigned short *tmp_var;
    unsigned short *b;
    unsigned short *c;
    unsigned short *n;
    int digits;
    unsigned char *s;
    int result;
    int i;
    unsigned long old_priority;

    if (con->sig == 0 || con->sig_len == 0 || ca->exponent == 0 || ca->exponent_len == 0 ||
        ca->modulo == 0 || ca->modulo_len == 0)
        return 2;
    digits = ca->modulo_len * 2 / 2;
    tmp_var = g_021A8280(digits * 8);
    if (tmp_var == 0)
        return 2;
    b = tmp_var + digits;
    c = b + digits;
    n = c + digits;
    func_02164CC4(b, con->sig, con->sig_len, digits);
    func_02164CC4(c, ca->exponent, ca->exponent_len, digits);
    func_02164CC4(n, ca->modulo, ca->modulo_len, digits);
    old_priority = func_0216009C();
    func_0216469C(tmp_var, b, c, digits, n);
    func_021600E4(old_priority);
    s = (unsigned char *)b;
    func_02164D20(s, tmp_var, ca->modulo_len, digits);
    result = 0;
    if (s[0] != 0 || s[1] != 1) {
        result = 2;
    } else {
        for (i = 2; i < ca->modulo_len; i++) {
            if (s[i] != 0xff)
                break;
        }
        if (i + 1 >= ca->modulo_len || s[i] != 0 || s[i + 1] != 0x30 ||
            func_020923F0(con->hash, s + ca->modulo_len - con->hash_len, con->hash_len) != 0)
            result = 2;
    }
    g_021A82B0(tmp_var);
    return result;
}
