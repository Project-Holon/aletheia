/*
 * file:     fldmmdl_p31.c
 * unit:     yes
 * function: func_0216DDDC, func_0216DE54, func_0216DE94
 * address:  0x0216DDDC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216DD60  0x0216DD60  thumb  ov010
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 *   func_0209C054  0x0209C054  arm
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216DBB4  0x0216DBB4  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 */
struct Ctx;
struct Rec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef int s32;

typedef long long s64;

typedef struct {
    int n;
    u8 *e[16];
} List;

extern u32 func_0216DD60(u32 a, u32 b, u32 c, u32 d, List *out);
extern u32 func_0216D8AC(void *p);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern u16 func_0216D5A0(void *obj);
extern int func_0216DBB4(void *obj);
extern u16 func_0216D588(void *obj);
u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);
void *func_0216DE54(void *map, u32 kind);
void *func_0216DE94(void *map, u32 id);


u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d)
{
    List buf;
    u32 i;
    u32 n;

    n = func_0216DD60(a, b, c, d, &buf);
    if (n == 0)
        return 0;
    for (i = 0; i < n; i++) {
        s32 q = func_0216D8AC(buf.e[i]) - x;

        if (q < 0)
            q = (s32)(((s64)q * (s64)(s32)0xFFFFF000 + 0x800) >> 12);
        if (q < lim)
            return buf.e[i];
    }
    return 0;
}


/*
 * First object of the given kind in the map (func_0216DD1C walks it),
 * or NULL.
 */
void *func_0216DE54(void *map, u32 kind)
{
    u32 iter;
    void *obj;

    iter = 0;
    while (func_0216DD1C(map, (struct Rec **)(&obj), &iter) == 1) {
        if (func_0216D5A0(obj) == kind)
            return obj;
    }
    return 0;
}


/*
 * First free object (func_0216DBB4 zero) with the given id in the map,
 * or NULL (func_0216DE54 is the by-kind twin).
 */
void *func_0216DE94(void *map, u32 id)
{
    u32 iter;
    void *obj;

    iter = 0;
    while (func_0216DD1C(map, (struct Rec **)(&obj), &iter) == 1) {
        if (func_0216DBB4(obj) == 0 && func_0216D588(obj) == id)
            return obj;
    }
    return 0;
}
