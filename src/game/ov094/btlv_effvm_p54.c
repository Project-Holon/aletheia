/*
 * file:     btlv_effvm_p54.c
 * unit:     yes
 * function: func_021FDD60, func_021FDFA0
 * address:  0x021FDD60
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FCD14 0x021FCD14 thumb ov094
 *   func_021F8710 0x021F8710 thumb ov094
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020515CC 0x020515CC arm
 *   func_021FD1CC 0x021FD1CC thumb ov094
 *   d_0220AE68 0x0220AE68 data ov094 a1
 *   func_0201134C 0x0201134C thumb
 *   func_02051648 0x02051648 arm
 *   func_02051788 0x02051788 arm
 *   func_021FE38C 0x021FE38C thumb ov094
 *   func_021FD1A8 0x021FD1A8 thumb ov094
 *   func_021FD9F0 0x021FD9F0 thumb ov094
 *   func_021FCF2C 0x021FCF2C thumb ov094
 *   func_021F8694 0x021F8694 thumb ov094
 *   func_021FF3F4 0x021FF3F4 thumb ov094
 *   _s32_div_f 0x0209C0A4 arm
 *   d_02209E10 0x02209E10 data
 *   d_02209DB4 0x02209DB4 data
 */
#include "../../matched/include/Obj00325.h"

struct Cursor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { unsigned low:6; unsigned b6:1; } Flags;

typedef struct {
    Flags flags;
    char pad04[8];
    int *objects[16];
    char pad4c[0x90];
    int dc;
    char pade0[0x158];
    u16 heap;
    char pad23a[0xe];
    u8 kind;
    char pad249[0xf];
    u16 f258;
} State;

typedef struct { int v[23]; } Rec;

typedef struct { int x, y, z; } Vec;

typedef struct { u32 v[8]; } Desc;

extern int func_021FCD14(State *, int, int *);
extern int func_021F8710(void);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020307B0(void *p);
extern int func_020515CC(int *, int, int, int);
extern void func_021FD1CC(void *p);
extern u32 func_0201134C(struct Cursor *p);
extern void func_02051648(void *, Desc *, u16, Vec *, Vec *, Vec *, u16);
extern int func_02051788(char *p);
extern u32 func_021FE38C(char *, u32);
extern int func_021FD1A8(char *, int);
extern void func_021FD9F0(void *p);
extern int func_021FCF2C(int a, int idx);
extern int func_021F8694(void);
extern void func_021FF3F4(void *obj, void *out, int idx);
extern int _s32_div_f(int, int);
void func_021FDD60(State *s, Rec *r, int slot, int arg);
int func_021FDFA0(void *a, char *s, int mode);
extern char d_0220AE68[];
extern const Vec d_02209E10, d_02209DB4;


/*
 * lever: declare count before n to place them at sp+0x18 and sp+0x14;
 *   reversed declarations produced five differing spill/reload bytes.
 */
void func_021FDD60(State *s, Rec *r, int slot, int arg)
{
    int targets[8];
    int keys[8];
    int count;
    int n;
    int i;
    Rec *p;

    if (r->v[2] == r->v[1] && (u32)(r->v[2] - 11) <= 1) {
        if (r->v[2] == 12)
            r->v[22] = 1;
        count = func_021FCD14(s, 16, targets);
        if (count != 0) {
            for (i = 0; i < count; i++) {
                p = func_02030734((u16)((s->heap & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x1c0e);
                *p = *r;
                p->v[1] = targets[i];
                p->v[2] = targets[i];
                if (func_020515CC(s->objects[slot], arg, (int)func_021FD1CC, (int)p) == -1)
                    func_020307B0(p);
            }
        }
    } else if (r->v[2] == r->v[1] && s->kind == 12 && !s->flags.b6 && s->f258 != 0x16e && (u32)(r->v[2] - 9) <= 1) {
        if (r->v[2] == 10)
            r->v[22] = 1;
        switch (func_021F8710()) {
        default:
        case 0: case 3:
            keys[0] = s->dc;
            n = 1;
            break;
        case 1:
            keys[0] = (s->dc & 1) ? 1 : 0;
            n = 1;
            break;
        case 2:
            keys[0] = (s->dc & 1) ? 19 : 18;
            keys[1] = (s->dc & 1) ? 21 : 20;
            n = 2;
            break;
        }
        if (n != 0) {
            for (i = 0; i < n; i++) {
                p = func_02030734((u16)((s->heap & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x1c45);
                *p = *r;
                p->v[1] = keys[i];
                p->v[2] = keys[i];
                if (func_020515CC(s->objects[slot], arg, (int)func_021FD1CC, (int)p) == -1)
                    func_020307B0(p);
            }
        }
    } else {
        p = func_02030734((u16)((s->heap & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x1c56);
        *p = *r;
        if (func_020515CC(s->objects[slot], arg, (int)func_021FD1CC, (int)p) == -1)
            func_020307B0(p);
    }
}

int func_021FDFA0(void *a, char *s, int mode)
{
    int *p;
    int idx;
    int x;
    int y;
    int flags;

    idx = func_021FD1A8(s, func_021FE38C(s, func_0201134C(a)));
    x = func_0201134C(a);
    flags = 0;
    *(int **)(s + 0x1f4 + ((struct Obj00325 *)s)->f234 * 4) = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x40, 0, d_0220AE68, 0x1c79);
    p = *(int **)(s + 0x1f4 + ((struct Obj00325 *)s)->f234 * 4);
    ((struct Obj00325 *)s)->f234 += 1;
    p[0] = func_0201134C(a);
    p[4] = func_0201134C(a);
    p[5] = func_0201134C(a);
    y = func_0201134C(a);
    p[6] = 0;
    p[9] = p[8] = func_0201134C(a);
    p[10] = 0;
    p[11] = func_0201134C(a);
    p[12] = func_0201134C(a);
    p[13] = 0;
    p[14] = func_0201134C(a);
    p[7] = _s32_div_f(0x10000, p[8]);
    p[15] = mode;
    if (idx == 16)
        goto end;
    if (mode == 1) {
        if (func_02051788(*(void **)(s + 0xc + idx * 4)) == 0) {
            Desc desc;
            Vec zero = {0, 0, 0};
            Vec v1;
            Vec v2;
            v1 = d_02209E10;
            v2 = d_02209DB4;
            desc.v[0] = 2;
            desc.v[1] = 0x3000;
            desc.v[2] = 0xffffd000;
            desc.v[3] = 0xffffc000;
            desc.v[4] = 0x4000;
            desc.v[5] = 0x1000;
            desc.v[6] = 0x200000;
            desc.v[7] = 0x1000;
            func_02051648(*(void **)(s + 0xc + idx * 4), &desc, 0x2000, &zero, &v1, &v2, (((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000);
        }
    }
    switch (p[0]) {
    case 0:
    case 1:
        flags = func_021FCF2C((int)a, 14);
        func_021FF3F4((void *)func_021F8694(), &p[1], flags);
        break;
    case 2:
    case 3:
        flags = func_021FCF2C((int)a, 16);
        func_021FF3F4((void *)func_021F8694(), &p[1], flags);
        break;
    case 4:
    case 5:
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        break;
    }
    if (flags & 1)
        p[6] = 0x8000;
    p[2] += y;
    if (func_020515CC(*(int **)(s + 0xc + idx * 4), x, (int)func_021FD9F0, (int)p) == -1)
        func_020307B0(p);
end:
    return ((struct Obj00325 *)s)->f23C;
}
