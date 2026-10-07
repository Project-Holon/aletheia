/*
 * file:     btl_server_p67.c
 * unit:     yes
 * function: func_021C5350, func_021C5418, func_021C5474, func_021C5480
 * address:  0x021C5350
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021D69B8 0x021D69B8 thumb ov093
 *   func_021BA1CC 0x021BA1CC thumb ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021C6110  0x021C6110  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021C5620  0x021C5620  thumb  ov093
 *   func_021BD1D0  0x021BD1D0  thumb  ov093
 *   func_021C54AC  0x021C54AC  thumb  ov093
 */
#include "../../matched/include/Obj05193.h"
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj21097.h"

struct Obj;
struct Result;
struct S2;
struct Unk021D62A8;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Entry { u32 value; u8 flag; u8 a, b, c, d, e, f, pad; };

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Slot { u32 kind : 3; u32 rest : 29; };

extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern int func_021D59B4(u8 *p, int k);
extern u8 func_021D5440(u8 *p);
extern void func_021CD64C(void *, u8, ...);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021D69B8(struct Obj *p, u32 *remaining, struct Result *r);
extern void func_021BA1CC(char **p, int i, u32 delta);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void func_021C6110(u8 *p, u8 *a, unsigned int n);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021C5620(u8 *p, u8 *a, int k, struct Slot *out);
extern void func_021BD1D0(u8 *p, u8 n);
extern int func_021C54AC(void *p, int v);
int func_021C5350(u8 *p, u8 *g, const struct Entry *q);
int func_021C5418(u8 *p, u8 *a, int b);
void *func_021C5474(char *p);
void func_021C5480(u8 *p, u8 *a, int b);

/*
 * lever: const entry source schedules byte arguments early; k precedes entry in declarations.
 */
int func_021C5350(u8 *p, u8 *g, const struct Entry *q)
{
    u32 i;
    int result = 0;
    u8 *a;
    int k;
    u32 value;
    int cmd;
    const struct Entry *entry;
    u32 remaining;
    for (i = 0; i < 6; i++) {
        entry = &q[i];
        if (!entry->value) continue;
        a = (u8 *)func_021B9BF0((struct S2 *)g, (u8)i);
        if (func_021D59B4(a, 15) >= 100) continue;
        value = entry->value;
        cmd = entry->flag ? 0x2b : 0x2a;
        k = func_021D5440(a);
        func_021CD64C(((struct Obj05193 *)p)->fC, 0x5a, (u16)cmd, k, value, 0xffff0000);
        func_021CD4B0(((struct Obj05193 *)p)->fC, 0x3e, k, q->a, q->b, q->c, q->d, q->e, q->f);
        remaining = value;
        while (func_021D69B8((struct Obj *)a, &remaining, (struct Result *)(p + 0x4c0))) {}
        func_021CD4B0(((struct Obj05193 *)p)->fC, 0x45, k, value);
        func_021BA1CC(((struct Obj05193 *)p)->f4, 0x1b, value);
        result = 1;
    }
    return result;
}


int func_021C5418(u8 *p, u8 *a, int b)
{
    u8 n;
    if (func_021D5BDC((struct UtilWork *)a, b)) {
        n = func_021D5440(a);
        func_021C6110(p, a, b);
        b = 0x1a;
        if (func_021D62C4((struct Unk021D62A8 *)a, 0x1a)) {
            func_021C5620(p, a, b, 0);
        }
        func_021CD4B0(((struct Obj00003 *)p)->fC, 0x31, n, 0);
        func_021BD1D0(p, n);
        return 1;
    }
    return 0;
}


void *func_021C5474(char *p)
{
    ((struct Obj21097 *)p)->f220 = 0;
    return p;
}


void func_021C5480(u8 *p, u8 *a, int b)
{
    int r = func_021C54AC(p + 0x1AB8, func_021D5440(a));
    if (r != 6) {
        func_021CD4B0(((struct Obj00003 *)p)->fC, 0x4d, r, b);
    }
}
