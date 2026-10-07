/*
 * file:     wifibattlematch_net_p17.c
 * unit:     yes
 * function: func_021DA4B8, func_021DA4E8, func_021DA4F0, func_021DA4F8, func_021DA5B0, func_021DA6B8
 * address:  0x021DA4B8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuCopy8         0x02082D44  arm
 *   DWC_AddMatchKeyInt  0x0216C8DC  arm  ov009
 *   d_021E2E10          0x021E2E10  data
 *   DWC_GetMatchIntValue  0x0216CB30  arm
 *   _s32_div_f            0x0209C0A4  arm
 *   func_021DB228  0x021DB228  thumb
 *   func_021DB218  0x021DB218  thumb
 *   func_021DB248  0x021DB248  thumb
 *   func_021DB238  0x021DB238  thumb
 *   func_021DB160  0x021DB160  thumb
 *   func_021DAFB8  0x021DAFB8  thumb
 *   func_02034714  0x02034714  arm
 *   func_0203D378  0x0203D378  arm
 *   d_021E2EF8     0x021E2EF8  data
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
#include "../../matched/include/Obj08280.h"
#include "../../matched/include/Obj01069.h"

struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned long u32;

struct MatchKey {
    int  value;
    u8   id;
    u8   pad_05;
    char name[3];
    u8   term;
    u8   pad_0a[2];
};

typedef unsigned short u16;

typedef int (*ReportFn)(u32 *ctx);

typedef struct Sys {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
} Sys;

typedef signed int     s32;

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u8 DWC_AddMatchKeyInt(u8 keyID, const char *keyString, const int *valueSrc);
extern int DWC_GetMatchIntValue(int index, const char *key, int idefault);
extern int func_021DB228(u32 *ctx);
extern int func_021DB218(u32 *ctx);
extern int func_021DB248(u32 *ctx);
extern int func_021DB238(u32 *ctx);
extern void func_021DB160(int *ctx, int *input, int invert);
extern void func_021DAFB8(int *ctx, const u32 *record, int invert);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_0203D378(void);
extern u32 func_0203CA98(void);
extern u32 func_0200FB24(void);
extern void func_021DAE18(char *obj);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *p, u32 lo, u32 hi);
extern u32 func_02039CB4(struct Link *p, u32 lo, u32 hi);
extern int func_021DC2C0(u32 ignored, void *p);
extern u32 func_021DC2D8(char *, u32 *);
extern int func_021DEE3C(int theGameId, int ssl_type);
extern void func_021DCE24(char *, int, int);
extern void func_021DCE08(char *, u32, int);
extern int func_021DF490(void **p);
extern int func_021DF018(u32 a0, u32 a1, u32 a2);
extern void *func_021DF20C(void);
extern void func_02082D44(const void *, void *, u32);
extern s32 func_021DEFDC(void);
extern void *func_021DF224(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern u32 func_021DF1C8(u32 a);
extern int func_021DF09C(u32 a0, u32 a1, u32 a2, u32 a3);
extern int func_021DAE54(char *, char *, char *, u32, u32, u32, u32, u32);
extern int func_021DF130(u32 a0, u32 a1, u32 a2, u32 a3, char *a4);
extern void func_021DADB4(int result, char *obj);
extern void func_021DADCC(int result, char *obj);
extern void func_021DAE00(int result, char *obj);
void func_021DA4B8(char *obj, int i, int value);
int func_021DA4E8(int index, void *param);
int func_021DA4F0(int index, void *param);
int func_021DA4F8(int index, void *param);
void func_021DA5B0(char *obj, int mode, int kind, u32 a3, u32 *rec, u32 slot);
int func_021DA6B8(char *p, u32 *out);
extern const char *const d_021E2E10[];
extern const char d_021E2EF8[];


/*
 * Registers match key i: stores the value, copies the three-byte key name from the table at 0x021E2E10, and keeps the key id DWC_AddMatchKeyInt returns.
 */
void func_021DA4B8(char *obj, int i, int value)
{
    struct MatchKey *k = (struct MatchKey *)(obj + 0xc4) + i;

    k->value = value;
    MI_CpuCopy8(d_021E2E10[i], k->name, 3);
    k->term = 0;
    k->id = DWC_AddMatchKeyInt(k->id, k->name, &k->value);
}


/*
 * Matchmaking evaluation callback that forwards to the key-distance scorer func_021DA4F8 (unlabelled; its address is a code pointer in func_021DA0D4's pool).
 */
int func_021DA4E8(int index, void *param)
{
    return func_021DA4F8(index, param);
}

/*
 * Matchmaking evaluation callback that scores every candidate 1000 (unlabelled; its address is a code pointer in func_021DA0D4's pool).
 */
int func_021DA4F0(int index, void *param)
{
    return 1000;
}


/*
 * Matchmaking evaluation callback: reads the candidate's keys 3..6; a candidate with none of them scores 0, one whose key 4 differs from ours scores 0, otherwise 1000 less the key 3 distance and 32 times the distance between the two key5*50/(key6+5) ratios, floored at 0.
 */
int func_021DA4F8(int index, void *param)
{
    char *p = param;
    int b, a, c, d;
    int q1, q2, da, dq, score;

    a = DWC_GetMatchIntValue(index, p + 0xee, -1);
    b = DWC_GetMatchIntValue(index, p + 0x106, -1);
    c = DWC_GetMatchIntValue(index, p + 0x112, -1);
    d = DWC_GetMatchIntValue(index, p + 0xfa, -1);

    if (a == -1 && b == -1 && d == -1 && c == -1)
        return 0;
    if (d == ((struct Obj08280 *)p)->fF4) {
        q1 = b * 50 / (c + 5);
        q2 = ((struct Obj08280 *)p)->f100 * 50 / (((struct Obj08280 *)p)->f10C + 5);
        da = a - ((struct Obj08280 *)p)->fE8;
        if (da < 0)
            da = -da;
        dq = q1 - q2;
        if (dq < 0)
            dq = -dq;
        score = 1000 - da - dq * 32;
        if (score < 0)
            return 0;
        return score;
    }
    return 0;
}


/*
 * Arms a storage-server report: resets the report state words, stores mode and the result slot, and picks the report callback at +0x158 from mode (0: plain, 1 with a result slot, or 1 without one, which also stores a3 and the two record words) and kind (0 or 2; anything else asserts).
 */
void func_021DA5B0(char *obj, int mode, int kind, u32 a3, u32 *rec, u32 slot)
{
    ((struct Obj01069 *)obj)->f1494 = 0;
    ((struct Obj01069 *)obj)->f12C = 0;
    ((struct Obj01069 *)obj)->f1A8 = 1;
    ((struct Obj01069 *)obj)->f14C = 0;
    ((struct Obj01069 *)obj)->f138 = 0;
    ((struct Obj01069 *)obj)->f1AC = mode;
    ((struct Obj01069 *)obj)->f160 = slot;
    ((struct Obj01069 *)obj)->f164 = 0;
    ((struct Obj01069 *)obj)->f168 = 0;
    ((struct Obj01069 *)obj)->f16C = 0;
    if (mode == 0) {
        switch (kind) {
        case 0:
            *(ReportFn *)&((struct Obj01069 *)obj)->f158 = func_021DB228;
            break;
        case 2:
            *(ReportFn *)&((struct Obj01069 *)obj)->f158 = func_021DB218;
            break;
        default:
            func_02034714(d_021E2EF8, 0, d_021E2EF8);
            break;
        }
    } else if (mode == 1) {
        if (slot != 0) {
            switch (kind) {
            case 0:
                *(ReportFn *)&((struct Obj01069 *)obj)->f158 = func_021DB248;
                break;
            case 2:
                *(ReportFn *)&((struct Obj01069 *)obj)->f158 = func_021DB238;
                break;
            default:
                func_02034714(d_021E2EF8, 0, d_021E2EF8);
                break;
            }
        } else {
            func_0203D378();
            ((struct Obj01069 *)obj)->f180 = a3;
            ((struct Obj01069 *)obj)->f184 = rec[0];
            ((struct Obj01069 *)obj)->f188 = rec[4];
            switch (kind) {
            case 0:
                *(ReportFn *)&((struct Obj01069 *)obj)->f158 = (ReportFn)func_021DB160;
                break;
            case 2:
                *(ReportFn *)&((struct Obj01069 *)obj)->f158 = (ReportFn)func_021DAFB8;
                break;
            default:
                func_02034714(d_021E2EF8, 0, d_021E2EF8);
                break;
            }
        }
    }
}


int func_021DA6B8(char *p, u32 *out)
{
    Sys *s;
    int r;
    char *dst;
    void *src;

    if (out != 0)
        *out = *(u32 *)(p + 0x16c);
    s = (Sys *)func_0203CA98();
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
        func_02039C68((struct Link *)func_020399A8(), 4, 0x24);
        *(u32 *)(p + 0x12c) = 1;
        break;
    case 1:
        if (*(u32 *)(p + 0x160) != 0) {
            *(u32 *)(p + 0x12c) = 4;
            break;
        }
        if (func_02039CB4((struct Link *)func_020399A8(), 4, 0x24) != 0 || *(u32 *)(p + 0x160) != 0)
            *(u32 *)(p + 0x12c) = 2;
        break;
    case 2:
        if (*(u32 *)(p + 0x160) != 0) {
            *(u32 *)(p + 0x12c) = 4;
            break;
        }
        if (func_021DC2C0((u32)p, p + 0x188) != 0 || *(u32 *)(p + 0x160) != 0)
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
        r = func_021DF490((void **)(*(char **)(p + 0x1464) + 4));
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
        r = func_021DF018((u32)func_021DADB4, 100, (u32)p);
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
        func_02039C68((struct Link *)func_020399A8(), 1, 0x24);
        *(u32 *)(p + 0x12c) = 9;
        break;
    case 9:
        if (func_02039CB4((struct Link *)func_020399A8(), 1, 0x24) != 0 || *(u32 *)(p + 0x160) != 0)
            *(u32 *)(p + 0x12c) = 0xa;
        break;
    case 10:
        if (func_0203D378() != 0 || *(u32 *)(p + 0x160) != 0) {
            if (func_0203D3A8(func_020399A8(), 0x2400, 0x68, *(u32 *)(p + 0x1464) + 4) != 0 || *(u32 *)(p + 0x160) != 0)
                *(u32 *)(p + 0x12c) = 0xb;
        } else if (*(u32 *)(p + 0x138) != 0 || *(u32 *)(p + 0x160) != 0) {
            *(u32 *)(p + 0x138) = 0;
            r = func_021DF1C8((u32)(*(char **)(p + 0x1464) + 0x74));
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
        r = func_021DF09C(*(u32 *)(p + 0x1a8), (u32)func_021DADCC, 100, (u32)p);
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
        func_02039C68((struct Link *)func_020399A8(), 2, 0x24);
        *(u32 *)(p + 0x12c) = 0xe;
        break;
    case 14:
        if (func_02039CB4((struct Link *)func_020399A8(), 2, 0x24) != 0 || *(u32 *)(p + 0x160) != 0)
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
        func_02039C68((struct Link *)func_020399A8(), 3, 0x24);
        *(u32 *)(p + 0x12c) = 0x12;
        break;
    case 18:
        if (func_02039CB4((struct Link *)func_020399A8(), 3, 0x24) != 0 || *(u32 *)(p + 0x160) != 0)
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
        r = func_021DF130(*(u32 *)(*(char **)(p + 0x1464) + 8), *(u32 *)(p + 0x1a8), (u32)func_021DAE00, 100, p);
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
        func_02039C68((struct Link *)func_020399A8(), 5, 0x24);
        *(u32 *)(p + 0x12c) = 0x18;
        break;
    case 24:
        if (func_02039CB4((struct Link *)func_020399A8(), 5, 0x24) != 0 || *(u32 *)(p + 0x160) != 0)
            *(u32 *)(p + 0x12c) = 0x19;
        break;
    case 25:
        return 1;
    }
    return 0;
}
