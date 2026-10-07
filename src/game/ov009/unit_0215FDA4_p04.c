/*
 * file:     unit_0215FDA4_p04.c
 * unit:     yes
 * function: func_0216017C, func_021601CC, func_02160238, func_021602B8
 * address:  0x0216017C
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
 *   cert_item_len  0x0216017C  arm  ov009
 *   MI_CpuCopy8    0x02082D44  arm
 *   strlen         0x0209477C  arm
 *   memcmp         0x020923F0  arm
 *   make_dn        0x021601CC  arm  ov009
 *   parse_time     0x02160238  arm  ov009
 *   object         0x021A1D48  data
 */
#include "../../matched/arm9_sdk/libc/memcmp/string.h"

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

extern int cert_item_len(unsigned char **ps);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void make_dn(char *d, char *s, int len);
extern unsigned long parse_time(unsigned char *s, int type);
extern unsigned char *object[];

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
