/*
 * file:     field_effect_p42.c
 * unit:     yes
 * function: func_021AB880, func_021AB884, func_021AB888, func_021AB890
 * address:  0x021AB880
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021D8EF4  0x021D8EF4  data  a4
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CBD0  0x0207CBD0  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0207CFB8  0x0207CFB8  arm
 */
#include "../../matched/include/Obj18077.h"
#include "../../matched/include/Obj18078.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct Vec { int x, y, z; } Vec;

typedef struct Range { unsigned long lo, hi; int min, max; Vec dir; } Range;

extern void func_0207CA00(const Vec *a, const Vec *b, Vec *out);
extern int func_0207CBD0(const Vec *v);
extern void func_0207CCA4(const Vec *v, Vec *out);
extern unsigned long func_0207CFB8(int x, int z);
u32 func_021AB880(u8 *p);
u32 func_021AB884(u8 *p);
void *func_021AB888(void);
int func_021AB890(void *self, const Range *r, Vec *ref);


/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021AB880(u8 *p)
{
    return ((struct Obj18077 *)p)->f0;
}


/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
u32 func_021AB884(u8 *p)
{
    return ((struct Obj18078 *)p)->f4;
}

void *func_021AB888(void)
{
    return (void *)0x021D8EF4;
}


static inline void VecSet(Vec *v, int x, int y, int z) { v->x = x; v->y = y; v->z = z; }


/*
 * Lever: `const Range *` together with the inline VecSet helper gives the
 * y, x, z load order of the 12-byte vector fill; either alone does not.
 */
int func_021AB890(void *self, const Range *r, Vec *ref)
{
    Vec out;
    Vec a;
    int d;
    unsigned long ang;

    VecSet(&a, r->dir.x, r->dir.y, r->dir.z);
    func_0207CA00(ref, &a, &out);
    out.y = 0;
    d = func_0207CBD0(&out);
    func_0207CCA4(&out, &out);
    ang = func_0207CFB8(out.x, out.z);
    if (r->min <= d && r->max > d) {
        if (r->hi < r->lo) {
            if (r->hi >= ang || (ang < 0x10000 && ang >= r->lo))
                return 1;
        } else {
            if (r->lo <= ang && r->hi > ang)
                return 1;
        }
    }
    return 0;
}
