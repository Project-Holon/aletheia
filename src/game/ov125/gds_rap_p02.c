/*
 * file:     gds_rap_p02.c
 * unit:     yes
 * function: func_021D6B40, func_021D6FB0, func_021D7060, func_021D7064, func_021D7120, func_021D7124, func_021D7154, func_021D71CC, func_021D71D8, func_021D730C, func_021D732C, func_021D7354, func_021D7374, func_021D73B8
 * address:  0x021D6B40
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D7700  0x021D7700  thumb  ov125
 *   func_021D75C0  0x021D75C0  thumb  ov125
 *   func_021D860C  0x021D860C  arm  ov125
 *   func_021D8654  0x021D8654  arm  ov125
 *   func_021D8694  0x021D8694  arm  ov125
 *   func_021D8754  0x021D8754  arm  ov125
 *   func_021D879C  0x021D879C  arm  ov125
 *   func_021D87FC  0x021D87FC  arm  ov125
 *   func_021D885C  0x021D885C  arm  ov125
 *   func_021D88BC  0x021D88BC  arm  ov125
 *   func_021D88F0  0x021D88F0  arm  ov125
 *   func_021B9748  0x021B9748  thumb  ov114
 *   func_021B9774  0x021B9774  thumb  ov114
 *   func_021B9790  0x021B9790  thumb  ov114
 *   func_021B97F4  0x021B97F4  thumb  ov114
 *   func_021B9800  0x021B9800  thumb  ov114
 *   func_021B9838  0x021B9838  thumb  ov114
 *   func_021B98A0  0x021B98A0  thumb  ov114
 *   func_021B98D8  0x021B98D8  thumb  ov114
 *   func_021B98F8  0x021B98F8  thumb  ov114
 *   func_021B99B8  0x021B99B8  thumb  ov114
 *   func_021B99DC  0x021B99DC  thumb  ov114
 *   func_021B99F0  0x021B99F0  thumb  ov114
 *   func_021B99F4  0x021B99F4  thumb  ov114
 *   func_021B9A14  0x021B9A14  thumb  ov114
 *   func_0200853C  0x0200853C  thumb
 *   func_02045F5C  0x02045F5C  arm
 *   func_0200B784  0x0200B784  thumb
 *   func_0200B91C  0x0200B91C  thumb
 *   func_0200BA44  0x0200BA44  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   d_021D8D28  0x021D8D28  data a4
 *   d_020A7370  0x020A7370  data
 *   func_021D85C0 0x021D85C0 arm ov125
 *   func_021D85DC 0x021D85DC arm ov125
 *   func_021D75E8 0x021D75E8 thumb ov125
 *   func_021D85E8 0x021D85E8 arm ov125
 *   func_0200B490 0x0200B490 thumb
 *   func_0200B4B8 0x0200B4B8 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_021D85F4 0x021D85F4 arm ov125
 *   func_02034714 0x02034714 arm
 *   func_021D73F0 0x021D73F0 thumb ov125
 *   func_021D74B4 0x021D74B4 thumb ov125
 *   func_021D7520 0x021D7520 thumb ov125
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../../matched/include/Obj00327.h"
#include "../../matched/include/Obj10460.h"
#include "../../matched/include/Obj22998.h"
#include "../../matched/include/Obj22999.h"
#include "../../matched/include/Obj23000.h"
#include "../../matched/include/Obj02838.h"
#include "../../matched/include/Obj23004.h"

#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))
#define OBJ (*(u8 **)(p + 0x404))
struct Big;
struct MsgData;
struct RecC4;
struct Sub0200852CObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int count; char entries[1]; } List;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern char *func_021D7700(void);
extern void func_021D75C0(void);
extern int func_021D860C(void *, u32);
extern int func_021D8654(int value, int n);
extern int func_021D8694(u32, void *, u32, u32);
extern int func_021D8754(void *, u32);
extern int func_021D879C(int value, int n);
extern int func_021D87FC(int value, int n);
extern int func_021D885C(int value, int n);
extern int func_021D88BC(u32, u32, u32, u32);
extern int func_021D88F0(u32, u32, u32);
extern int func_021B9748(u8 *);
extern void func_021B9774(u8 *);
extern int func_021B9790(u8 *);
extern u8 *func_021B97F4(u8 *);
extern u8 *func_021B9800(int a, int b, int c);
extern void func_021B9838(u8 *);
extern void func_021B98A0(u8 *p, int a, int b, int c);
extern void func_021B98D8(u8 *p, int a, int n);
extern int func_021B98F8(u8 *);
extern void func_021B99B8(u8 *);
extern int func_021B99DC(u8 *);
extern int func_021B99F0(u8 *);
extern u32 func_021B99F4(u32 p, u32 i);
extern u8 *func_021B9A14(u8 *p, u32 i);
extern void func_02082D44(const void *, void *, u32);
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern void func_0200B784(u16, int *, int *);
extern u8 *func_0200B91C(void);
extern void func_0200BA44(struct RecC4 *p);
extern u8 *func_02012944(void *p);
extern void *func_02012EBC(struct Big *p);
extern void func_02045F5C(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern unsigned int func_021D85C0(void);
extern int func_021D85DC(void);
extern void func_0200B490(void);
extern void func_0200B4B8(void);
extern char *func_021D85E8(void);
extern int func_021D75E8(int, int, int, u16 *, int, u16);
extern int func_021D85F4(void);
extern int func_021D73F0(char *, const u16 *);
extern int func_021D74B4(char *, const u16 *);
extern int func_021D7520(char *, const u16 *);
extern void MI_CpuFill8(void *, int, unsigned int);
int func_021D6B40(u8 *p, int *done);
int func_021D6FB0(char *p);
int func_021D7060(void);
int func_021D7064(char *p, const u16 *s);
int func_021D7120(void);
void func_021D7124(char *p, int unused, int k, int a3);
int func_021D7154(int a, int index, int *outer, int *inner);
void func_021D71CC(const void *src,void *dst,u32 n);
int func_021D71D8(char *p);
int func_021D72EC(char *p, int **out);
void func_021D72F8(char *p);
int func_021D730C(char *p);
int func_021D732C(char *p, const unsigned short *s);
int func_021D7354(char *p, const unsigned short *s);
int func_021D7374(char *a, void **out, int max);
int func_021D73B8(char *p, const unsigned short *s);
extern const char d_021D8D28[];
extern void *d_020A7370;


/*
 * 2026-10-05 (wD9r lane109): EXACT. The 0x55F1 inner switch is written out as an expanded inline:
 *   r = 0; cases 0..2 set r and break; case 3 sets t and `goto join`; then `t = r; join: ret = t;`.
 *   t is declared first, so the merged ret/t/r value keeps an early local's spill slot ([sp,#8]);
 *   a real static inline helper put it in the inline return temp's slot ([sp]).
 */
int func_021D6B40(u8 *p, int *done)
{
    int t;
    int n, m;
    int idx, sub;
    int n2, m2;
    int ret;
    int r;
    char *base;
    char *base2;
    int i;
    u8 *h;
    int a, b;
    u8 x;

    *done = 0;
    ret = 0;
    switch (*(int *)(p + 0x3d8)) {
    case 0x5208:
        ret = func_021D860C(p + 0x174, W(0x3ac));
        break;
    case 0x5209:
        ret = func_021D8654(H(0x3a4), W(0x3ac));
        break;
    case 0x55f0:
        switch (B(0x402)) {
        case 0:
            base = func_021D7700();
            if (OBJ != 0)
                func_02034714(d_021D8D28, ret, d_021D8D28);
            OBJ = func_021B9800((u16)W(0x13c), func_0200853C((const struct Sub0200852CObj *)func_02012944((void *)W(0))), W(0x494));
            func_021B98A0(OBJ, (u16)W(0x13c), 0x540, 3);
            func_0200B784(*(u16 *)(base + 0xa6), &n, &m);
            B(0x490) = 0;
            for (i = 0; i < n; i++) {
                func_021B98D8(OBJ, (int)(base + 0xd00 + i * 0x2a4), *(u16 *)(base + i * 0x2a4 + 0xcfe) * 0x70);
                B(0x490) += (u8)*(u16 *)(base + i * 0x2a4 + 0xcfe);
            }
            if (!func_021B98F8(OBJ))
                func_02034714(d_021D8D28, 0, d_021D8D28);
            if (!(func_021B9748(OBJ) == 0 ? 1 : 0))
                func_02034714(d_021D8D28, 0, d_021D8D28);
            B(0x402)++;
            break;
        case 1:
            a = func_021B99DC(OBJ);
            b = func_021B9790(OBJ);
            if (a != 200 && b != 15) {
                switch (func_021B99DC(OBJ)) {
                case 0x190: B(0x493) = 0x96; break;
                case 0x191: B(0x493) = 0x97; break;
                case 0x198: B(0x493) = 0x98; break;
                default: B(0x493) = 0x99; break;
                }
                func_021B99B8(OBJ);
                func_021B9774(OBJ);
                func_021B9838(OBJ);
                OBJ = 0;
                *done = 1;
                return 1;
            }
            if (b == 0) {
                h = func_021B97F4(OBJ);
                if (func_021B99F0(h) == 0) {
                    B(0x492) = 0;
                    func_02082D44(func_021B9A14(h, B(0x490)), p + 0x40a, 0x80);
                    for (i = 0; i < B(0x490); i++)
                        W(0x48c) = func_021B99F4((u32)h, i);
                    B(0x402)++;
                } else {
                    base2 = func_021D7700();
                    if (B(0x403) == 1)
                        B(0x492) = 1;
                    func_0200B784(*(u16 *)(base2 + 0xa6), &n2, &m2);
                    for (i = 0; i < B(0x490); i++) {
                        W(0x48c) = func_021B99F4((u32)h, i);
                        if (W(0x48c) != 0 && B(0x403) == 0) {
                            if (!func_021D7154((int)p, i, &idx, &sub))
                                break;
                            {
                                char *e = base2 + 0xd00 + idx * 0x2a4 + sub * 0x70;
                                func_02045F5C(d_020A7370, *(u16 *)(e + 6), (u16 *)(e + 0x32), 11);
                            }
                            W(0x5a0) = 1;
                        }
                    }
                    if (B(0x403) == 0) {
                        func_0200BA44((struct RecC4 *)func_0200B91C());
                        B(0x402) = 0;
                        B(0x403)++;
                    } else {
                        B(0x402)++;
                    }
                }
                func_021B99B8(OBJ);
                func_021B9838(OBJ);
                OBJ = 0;
                break;
            }
            if (b != 15 && OBJ != 0) {
                func_021B99B8(OBJ);
                func_021B9774(OBJ);
                func_021B9838(OBJ);
                OBJ = 0;
                return 1;
            }
            return 0;
        case 2:
            func_02012EBC((struct Big *)W(0));
            func_021D75C0();
            B(0x402)++;
            break;
        case 3:
            ret = func_021D8694(W(0x174), p + 0x40a, 0x80, W(0x3ac));
            break;
        }
        break;
    case 0x55f1:
        r = 0;
        switch (W(0x3e0)) {
        case 0:
            r = func_021D8754(p + 0x174, W(0x3ac));
            break;
        case 1:
            r = func_021D879C(0x64, W(0x3ac));
            break;
        case 2:
            r = func_021D885C(0x64, W(0x3ac));
            break;
        case 3:
            t = func_021D87FC(0x64, W(0x3ac));
            goto join;
            break;
        }
        t = r;
    join:
        ret = t;
        break;
    case 0x55f2:
        ret = func_021D88BC(W(0x3a4), W(0x3a8), 0x64, W(0x3ac));
        break;
    case 0x55f3:
        ret = func_021D88F0(W(0x3a4), W(0x3a8), W(0x3ac));
        break;
    default:
        func_02034714(d_021D8D28, 0, d_021D8D28);
        break;
    }
    if (ret == 1)
        W(0x3dc) = W(0x3d8);
    return ret;
}

int func_021D6FB0(char *p)
{
    unsigned int state;
    if (((struct Obj00327 *)p)->f3DC == 0x55f4) return 1;
    state = func_021D85C0();
    ((struct Obj00327 *)p)->f140 = state;
    if (state != ((struct Obj00327 *)p)->f144) {
        switch (state) {
        case 7:
            ((struct Obj00327 *)p)->f168 = 1;
            ((struct Obj00327 *)p)->f16C = 0;
            ((struct Obj00327 *)p)->f170 = 7;
            ((struct Obj00327 *)p)->f164 = 1;
            ((struct Obj00327 *)p)->f3FC = func_021D7120;
            break;
        case 8:
            ((struct Obj00327 *)p)->f3FC = func_021D7060;
            func_021D71D8(p);
            break;
        case 9:
            ((struct Obj00327 *)p)->f168 = 0;
            ((struct Obj00327 *)p)->f16C = 0;
            ((struct Obj00327 *)p)->f170 = func_021D85DC();
            ((struct Obj00327 *)p)->f164 = 1;
            ((struct Obj00327 *)p)->f3FC = func_021D7120;
            break;
        case 0: case 1: case 2: case 3: case 4: case 5: case 6:
        default: break;
        }
        ((struct Obj00327 *)p)->f144 = ((struct Obj00327 *)p)->f140;
    }
    return 1;
}

int func_021D7060(void) { return 1; }

int func_021D7064(char *p, const u16 *s)
{
    char *base;
    char *out;
    char *r;
    int outer, inner;
    int n, m;
    int i;
    int *obj;
    int result;
    if (s[2] == 0 && ((struct Obj10460 *)p)->f5A0 != 0) {
        r = func_021D7700();
        func_0200B490();
        func_0200B784(((struct Obj22998 *)r)->fA6, &n, &m);
        i = 0;
        out = p + 0x498;
        base = r + 0xd00;
        for (; i < 12; i++) {
            if (!func_021D7154((int)p, i, &outer, &inner)) break;
            func_021D71CC(out + i * 22, base + outer * 676 + inner * 112 + 50, 11);
        }
        func_0200BA44((struct RecC4 *)func_0200B91C());
        func_0200B4B8();
    }
    obj = (int *)func_021D85E8();
    result = func_021D75E8(((struct Obj10460 *)p)->f0, obj[1], obj[2], (u16 *)(s + 2), (int)(s + 3), (u16)((struct Obj10460 *)p)->f13C);
    if (result == 2 || result == 3) return 1;
    return 0;
}

int func_021D7120(void) { return 1; }


void func_021D7124(char *p, int unused, int k, int a3)
{
    if ((k == 3 || k == 6) && *(u8 **)(p + 0x404) != 0) {
        func_021B99B8(*(u8 **)(p + 0x404));
        func_021B9774(*(u8 **)(p + 0x404));
        func_021B9838(*(u8 **)(p + 0x404));
        *(int *)(p + 0x404) = 0;
    }
}

int func_021D7154(int a, int index, int *outer, int *inner)
{
    char *p;
    int n, other;
    int i;
    i = 0;
    p = func_021D7700();
    func_0200B784(((struct Obj22999 *)p)->fA6, &n, &other);
    for (*outer = 0; *outer < n; ++*outer) {
        for (*inner = 0; *inner < *(u16 *)(p + *outer * 676 + 0xcfe); ++*inner) {
            if (i == index) return 1;
            ++i;
        }
    }
    return 0;
}

void func_021D71CC(const void *src,void *dst,u32 n) {func_02082D44(src,dst,n*2);}

int func_021D71D8(char *p)
{
    const u16 *state;
    int result = 1;
    state = (const u16 *)func_021D85E8();
    func_021D85F4();
    if (((struct Obj00327 *)p)->f3DC != state[0]) func_02034714(d_021D8D28, 0, d_021D8D28);
    ((struct Obj00327 *)p)->f3F0 = 0;
    switch (state[0]) {
    case 0: break;
    case 21000:
        result = func_021D732C(p, state);
        ((struct Obj00327 *)p)->f3F0 = ((struct Obj00327 *)p)->f14C;
        break;
    case 21001:
        result = func_021D7354(p, state);
        ((struct Obj00327 *)p)->f3F0 = ((struct Obj00327 *)p)->f150;
        break;
    case 22000:
        result = func_021D73B8(p, state);
        ((struct Obj00327 *)p)->f3F0 = ((struct Obj00327 *)p)->f154;
        if (result == 1) ((struct Obj00327 *)p)->f3FC = (void *)func_021D7064;
        break;
    case 22001:
        result = func_021D73F0(p, state);
        ((struct Obj00327 *)p)->f3F0 = ((struct Obj00327 *)p)->f158;
        break;
    case 22002:
        result = func_021D74B4(p, state);
        ((struct Obj00327 *)p)->f3F0 = ((struct Obj00327 *)p)->f15C;
        break;
    case 22003:
        result = func_021D7520(p, state);
        ((struct Obj00327 *)p)->f3F0 = ((struct Obj00327 *)p)->f160;
        break;
    }
    if (result == 0) {
        ((struct Obj00327 *)p)->f168 = 2;
        ((struct Obj00327 *)p)->f16C = state[0];
        ((struct Obj00327 *)p)->f170 = state[1];
        ((struct Obj00327 *)p)->f164 = 1;
    } else ((struct Obj00327 *)p)->f164 = 0;
    return result;
}

int func_021D72EC(char *p, int **out)
{
    *out = (int *)(p + 0x164);
    return ((struct Obj23000 *)p)->f164;
}

void func_021D72F8(char *p)
{
    MI_CpuFill8(p + 0x164, 0, 16);
}

int func_021D730C(char *p) { if (*(unsigned int *)&((struct Obj02838 *)p)->f3D8==0x55f4 && ((struct Obj02838 *)p)->f3DC==0x55f4) return 1; return 0; }

int func_021D732C(char *p, const unsigned short *s) { int r=0; switch (s[1]) { case 0: r=1; break; case 1: case 2: case 3: case 4: case 5: case 6: break; default: break; } return r; }

int func_021D7354(char *p, const unsigned short *s) { int r=0; switch (s[1]) { case 0: r=1; break; case 1: case 2: case 3: break; default: break; } return r; }

int func_021D7374(char *a, void **out, int max)
{
    int p;
    char *base;
    int n;
    int i;
    p = (int)(func_021D85E8() + 4);
    n = ((struct Obj23004 *)p)->f0;
    if (n > max) n = max;
    base = (char *)(p + 4);
    for (i = 0; i < n; i++) out[i] = base + i * 572 + 12;
    for (; i < max; i++) out[i] = 0;
    return n;
}

int func_021D73B8(char *p, const unsigned short *s) { int r=0; switch (s[1]) { case 0: r=1; break; case 1: case 2: case 3: case 4: case 5: case 6: case 7: break; default: break; } return r; }
