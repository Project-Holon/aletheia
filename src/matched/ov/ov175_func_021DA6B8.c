/*
 * function: func_021DA6B8
 * address:  0x021DA6B8
 * packet:   pkt_ov175_021DA6B8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203CA98 0x0203CA98 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_021DAE18 0x021DAE18 thumb ov175
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_021DC2C0 0x021DC2C0 thumb ov175
 *   func_021DC2D8 0x021DC2D8 thumb ov175
 *   func_021DEE3C 0x021DEE3C arm ov175
 *   func_021DCE24 0x021DCE24 thumb ov175
 *   func_021DCE08 0x021DCE08 thumb ov175
 *   func_021DF490 0x021DF490 arm ov175
 *   func_0203D378 0x0203D378 arm
 *   func_021DF018 0x021DF018 arm ov175
 *   func_021DF20C 0x021DF20C arm ov175
 *   func_02082D44 0x02082D44 arm
 *   func_021DEFDC 0x021DEFDC arm ov175
 *   func_021DF224 0x021DF224 arm ov175
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021DF1C8 0x021DF1C8 arm ov175
 *   func_021DF09C 0x021DF09C arm ov175
 *   func_021DAE54 0x021DAE54 thumb ov175
 *   func_021DF130 0x021DF130 arm ov175
 *   func_021DADB4 0x021DADB4 thumb ov175
 *   func_021DADCC 0x021DADCC thumb ov175
 *   func_021DAE00 0x021DAE00 thumb ov175
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
struct Entry;
typedef struct Sys {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
} Sys;
extern Sys *func_0203CA98(void);
extern int func_0200FB24(void);
extern void func_021DAE18(char *obj);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Entry *a0, unsigned int a1, unsigned int a2);
extern unsigned int func_02039CB4(struct Entry *a0, unsigned int a1, unsigned int a2);
extern int func_021DC2C0(char *, void *);
extern u32 func_021DC2D8(char *, u32 *);
extern int func_021DEE3C(int theGameId, int ssl_type);
extern void func_021DCE24(char *, int, int);
extern void func_021DCE08(char *, u32, int);
extern int func_021DF490(char *);
extern u32 func_0203D378(void);
extern int func_021DF018(void *, int, char *);
extern void *func_021DF20C(void);
extern void func_02082D44(const void *, void *, u32);
extern void func_021DEFDC(void);
extern void *func_021DF224(void);
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
extern int func_021DF1C8(char *);
extern int func_021DF09C(u32, void *, int, char *);
extern int func_021DAE54(char *, char *, char *, u32, u32, u32, u32, u32);
extern int func_021DF130(u32, u32, void *, int, char *);
extern void func_021DADB4(void);
extern void func_021DADCC(void);
extern void func_021DAE00(void);

int func_021DA6B8(char *p, u32 *out)
{
    Sys *s;
    int r;
    char *dst;
    void *src;

    if (out != 0)
        *out = *(u32 *)(p + 0x16c);
    s = func_0203CA98();
    if (s->fc - 0x3f0 <= 1)
        *(u32 *)(p + 0x160) = 1;
    if (func_0200FB24() == 1) {
        if (s->f4 == 6 || s->f4 == 3) {
            func_021DAE18(p);
            return 2;
        }
    } else if (*(u32 *)(p + 0x160) == 0 && func_0200FB24() == 2) {
        func_021DAE18(p);
        return 2;
    }
    if (*(u32 *)(p + 0x160) != 0 && *(u32 *)(p + 0x1ac) != 0 && *(u32 *)(p + 0x164) == 0
        && *(u32 *)(p + 0x12c) > 7 && *(u32 *)(p + 0x12c) < 10) {
        *(u32 *)(p + 0x168) = 0;
        *(u32 *)(p + 0x12c) = 6;
    }

    switch (*(u32 *)(p + 0x12c)) {
    case 0:
        if (*(u32 *)(p + 0x160) != 0) {
            *(u32 *)(p + 0x12c) = 4;
            break;
        }
        func_02039C68(func_020399A8(), 4, 0x24);
        *(u32 *)(p + 0x12c) = 1;
        break;
    case 1:
        if (*(u32 *)(p + 0x160) != 0) {
            *(u32 *)(p + 0x12c) = 4;
            break;
        }
        if (func_02039CB4(func_020399A8(), 4, 0x24) != 0 || *(u32 *)(p + 0x160) != 0)
            *(u32 *)(p + 0x12c) = 2;
        break;
    case 2:
        if (*(u32 *)(p + 0x160) != 0) {
            *(u32 *)(p + 0x12c) = 4;
            break;
        }
        if (func_021DC2C0(p, p + 0x188) != 0 || *(u32 *)(p + 0x160) != 0)
            *(u32 *)(p + 0x12c) = 3;
        break;
    case 3:
        if (*(u32 *)(p + 0x160) != 0) {
            *(u32 *)(p + 0x12c) = 4;
            break;
        }
        if (func_021DC2D8(p, (u32 *)(p + 0x18c)) != 0 || *(u32 *)(p + 0x160) != 0)
            *(u32 *)(p + 0x12c) = 4;
        break;
    case 4:
        *(u32 *)(p + 0x134) = 0;
        *(u32 *)(p + 0x170) = 1;
        r = func_021DEE3C(0xb5f, 0);
        if (r != 0) {
            func_021DCE24(p + 0x18, r, 0x751);
            func_021DAE18(p);
            return 2;
        }
        *(u32 *)(p + 0x12c) = 5;
        break;
    case 5:
        r = func_021DF490(*(char **)(p + 0x1464) + 4);
        if (r != 0) {
            func_021DCE24(p + 0x18, r, 0x761);
            func_021DAE18(p);
            return 2;
        }
        *(u32 *)(p + 0x12c) = 6;
        break;
    case 6:
        if (func_0203D378() != 0 || *(u32 *)(p + 0x160) != 0) {
        (*(u32 *)(p + 0x134))++;
        r = func_021DF018(func_021DADB4, 100, p);
        *(u32 *)(p + 0x164) = 1;
        if (r != 0) {
            func_021DCE24(p + 0x18, r, 0x773);
            func_021DAE18(p);
            return 2;
        }
        *(u32 *)(p + 0x1a0) = 0;
        *(u32 *)(p + 0x12c) = 7;
        } else
            *(u32 *)(p + 0x12c) = 8;
        break;
    case 7:
        if (*(u32 *)(p + 0x134) == 0) {
            dst = *(char **)(p + 0x1464) + 0xc;
            src = func_021DF20C();
            func_02082D44(src, dst, 0x28);
            *(u32 *)(p + 0x12c) = 8;
            break;
        }
        if ((*(u32 *)(p + 0x1a0))++ > 0xe10) {
            func_021DCE08(p + 0x18, 1, 0x78f);
            func_021DAE18(p);
            return 2;
        }
        func_021DEFDC();
        if (*(u32 *)(p + 0x15c) != 0) {
            func_021DCE24(p + 0x18, *(u32 *)(p + 0x15c), 0x797);
            func_021DAE18(p);
            return 2;
        }
        break;
    case 8:
        if (*(u32 *)(p + 0x160) != 0) {
            *(u32 *)(p + 0x12c) = 0xb;
            break;
        }
        dst = *(char **)(p + 0x1464) + 0x34;
        src = func_021DF224();
        func_02082D44(src, dst, 0x28);
        func_02039C68(func_020399A8(), 1, 0x24);
        *(u32 *)(p + 0x12c) = 9;
        break;
    case 9:
        if (func_02039CB4(func_020399A8(), 1, 0x24) != 0 || *(u32 *)(p + 0x160) != 0)
            *(u32 *)(p + 0x12c) = 0xa;
        break;
    case 10:
        if (func_0203D378() != 0 || *(u32 *)(p + 0x160) != 0) {
            if (func_0203D3A8(func_020399A8(), 0x2400, 0x68, *(u32 *)(p + 0x1464) + 4) != 0 || *(u32 *)(p + 0x160) != 0)
                *(u32 *)(p + 0x12c) = 0xb;
        } else if (*(u32 *)(p + 0x138) != 0 || *(u32 *)(p + 0x160) != 0) {
            *(u32 *)(p + 0x138) = 0;
            r = func_021DF1C8(*(char **)(p + 0x1464) + 0x74);
            dst = *(char **)(p + 0x1464) + 0xc;
            src = func_021DF20C();
            func_02082D44(src, dst, 0x28);
            if (r != 0) {
                func_021DCE24(p + 0x18, r, 0x7cd);
                func_021DAE18(p);
                return 2;
            }
            *(u32 *)(p + 0x12c) = 0xb;
        }
        break;
    case 11:
        (*(u32 *)(p + 0x134))++;
        r = func_021DF09C(*(u32 *)(p + 0x1a8), func_021DADCC, 100, p);
        if (r != 0) {
            func_021DCE24(p + 0x18, r, 0x7dd);
            func_021DAE18(p);
            return 2;
        }
        *(u32 *)(p + 0x1a0) = 0;
        *(u32 *)(p + 0x12c) = 0xc;
        break;
    case 12:
        if (*(u32 *)(p + 0x134) == 0) {
            *(u32 *)(p + 0x12c) = 0xd;
            break;
        }
        if ((*(u32 *)(p + 0x1a0))++ > 0xe10) {
            func_021DCE08(p + 0x18, 1, 0x7f2);
            func_021DAE18(p);
            return 2;
        }
        func_021DEFDC();
        if (*(u32 *)(p + 0x15c) != 0) {
            func_021DCE24(p + 0x18, *(u32 *)(p + 0x15c), 0x7fa);
            func_021DAE18(p);
            return 2;
        }
        break;
    case 13:
        if (*(u32 *)(p + 0x160) != 0) {
            *(u32 *)(p + 0x12c) = 0x13;
            break;
        }
        func_02039C68(func_020399A8(), 2, 0x24);
        *(u32 *)(p + 0x12c) = 0xe;
        break;
    case 14:
        if (func_02039CB4(func_020399A8(), 2, 0x24) != 0 || *(u32 *)(p + 0x160) != 0)
            *(u32 *)(p + 0x12c) = 0xf;
        break;
    case 15:
        if (func_0203D378() != 0) {
            if (func_0203D3A8(func_020399A8(), 0x2400, 0x68, *(u32 *)(p + 0x1464) + 4) != 0 || *(u32 *)(p + 0x160) != 0)
                *(u32 *)(p + 0x12c) = 0x10;
        } else if (*(u32 *)(p + 0x138) != 0 || *(u32 *)(p + 0x160) != 0) {
            if (*(u32 *)(p + 0x160) == 0)
                *(u32 *)(p + 0x168) = 1;
            *(u32 *)(p + 0x138) = 0;
            *(u32 *)(p + 0x12c) = 0x10;
        }
        break;
    case 16:
        if (func_0203D378() == 0) {
            if (func_0203D3A8(func_020399A8(), 0x2400, 0x68, *(u32 *)(p + 0x1464) + 4) != 0 || *(u32 *)(p + 0x160) != 0)
                *(u32 *)(p + 0x12c) = 0x11;
        } else if (*(u32 *)(p + 0x138) != 0 || *(u32 *)(p + 0x160) != 0) {
            if (*(u32 *)(p + 0x160) == 0)
                *(u32 *)(p + 0x168) = 1;
            *(u32 *)(p + 0x138) = 0;
            *(u32 *)(p + 0x12c) = 0x11;
        }
        break;
    case 17:
        func_02039C68(func_020399A8(), 3, 0x24);
        *(u32 *)(p + 0x12c) = 0x12;
        break;
    case 18:
        if (func_02039CB4(func_020399A8(), 3, 0x24) != 0 || *(u32 *)(p + 0x160) != 0)
            *(u32 *)(p + 0x12c) = 0x13;
        break;
    case 19:
        r = func_021DAE54(*(char **)(p + 0x1464) + 4, *(char **)(p + 0x1464) + 0x6c, p + 0x180, *(u32 *)(p + 0x1a8),
                          *(u32 *)(p + 0x158), *(u32 *)(p + 0x160), *(u32 *)(p + 0x1ac), *(u32 *)(p + 0x168));
        if (r != 0) {
            func_021DCE24(p + 0x18, r, 0x86d);
            func_021DAE18(p);
            return 2;
        }
        *(u32 *)(p + 0x12c) = 0x14;
        break;
    case 20:
        (*(u32 *)(p + 0x134))++;
        r = func_021DF130(*(u32 *)(*(char **)(p + 0x1464) + 8), *(u32 *)(p + 0x1a8), func_021DAE00, 100, p);
        if (r != 0) {
            func_021DCE24(p + 0x18, r, 0x87c);
            func_021DAE18(p);
            return 2;
        }
        *(u32 *)(p + 0x1a0) = 0;
        *(u32 *)(p + 0x12c) = 0x15;
        break;
    case 21:
        if (*(u32 *)(p + 0x134) == 0) {
            *(u32 *)(p + 0x12c) = 0x16;
            break;
        }
        if ((*(u32 *)(p + 0x1a0))++ > 0xe10) {
            func_021DCE08(p + 0x18, 1, 0x890);
            func_021DAE18(p);
            return 2;
        }
        func_021DEFDC();
        if (*(u32 *)(p + 0x15c) != 0) {
            func_021DCE24(p + 0x18, *(u32 *)(p + 0x15c), 0x898);
            func_021DAE18(p);
            return 2;
        }
        break;
    case 22:
        *(u32 *)(p + 0x16c) = 1;
        func_021DAE18(p);
        *(u32 *)(p + 0x12c) = 0x17;
        break;
    case 23:
        func_02039C68(func_020399A8(), 5, 0x24);
        *(u32 *)(p + 0x12c) = 0x18;
        break;
    case 24:
        if (func_02039CB4(func_020399A8(), 5, 0x24) != 0 || *(u32 *)(p + 0x160) != 0)
            *(u32 *)(p + 0x12c) = 0x19;
        break;
    case 25:
        return 1;
    }
    return 0;
}
