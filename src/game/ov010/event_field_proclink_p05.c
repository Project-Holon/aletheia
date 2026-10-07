/*
 * file:     event_field_proclink_p05.c
 * unit:     yes
 * function: func_0215F118, func_0215F168, func_0215F1C8, func_0215F214
 * address:  0x0215F118
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
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02158FB4  0x02158FB4  thumb  ov010
 *   func_02189734  0x02189734  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   d_0217294C     0x0217294C  data  ov010  a4
 *   func_020113D0  0x020113D0  thumb
 *   func_0202EB44  0x0202EB44  thumb
 */
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj17702.h"
#include "../../matched/include/Obj17703.h"

struct BigObj;
struct Ctx;
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Area {
    u16 x;              /* 0x00 */
    u16 z;              /* 0x02 */
    u16 w;              /* 0x04 */
    u16 h;              /* 0x06 */
} Area;

typedef signed int     s32;

typedef unsigned char u8;

extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
extern u32 func_02012138(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02158FB4(void *p);
extern int func_02189734();
extern int func_020307B0();
extern u16 *func_02159AE8(void *a, void *b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020113D0(char *p, int val);
extern int func_0202EB44();
int func_0215F118(const Area *a, u16 x, u16 z, u32 flag, void *field);
int func_0215F168(int a0, int a1);
int func_0215F1C8(void *a, void *b);
int func_0215F214(int a0, int a1);
extern const char d_0217294C[];


/*
 * Inside test of (x, z) against an Area's half extents, refused when the
 * flag is already set in the field's save block.
 */
int func_0215F118(const Area *a, u16 x, u16 z, u32 flag, void *field)
{
    int dx;
    int dz;

    if (func_020142E8((void *)func_0201296C(func_020120F4(func_02188C80(field))), flag) != 0)
        return 0;
    dx = a->x - x;
    dz = a->z - z;
    if (dx < 0)
        dx = -dx;
    if (dx < a->w) {
        if (dz < 0)
            dz = -dz;
        if (dz < a->h)
            return 1;
    }
    return 0;
}


int func_0215F168(int a0, int a1)
{
    int t4;
    int t6;
    void *p;
    void *v0;
    void *v1;
    void *v2;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215F172:
a0 = t4 + 0;
    v1 = func_0215A5F4((void *)a0);
loc_0215F17A:
    a0 = func_02012138(v0);
loc_0215F182:
t6 = a0 + 0;
    v2 = func_0201210C(v0);
loc_0215F18A:
    p = func_02158FB4(v1);
loc_0215F190:
t4 = ((struct Obj17702 *)((char *)p))->f0;
a0 = t6 + 0;
    a0 = func_02189734(a0);
loc_0215F198:
    if (a0 == 0) goto loc_0215F1A6;
loc_0215F19C:
    if (a0 == 1) goto loc_0215F1AA;
loc_0215F1A0:
    if (a0 == 2) goto loc_0215F1B4;
loc_0215F1A4:
    goto loc_0215F1C4;
loc_0215F1A6:
a0 = 0;
    return a0;
loc_0215F1AA:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_0215F1B0:
a0 = 1;
    return a0;
loc_0215F1B4:
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
a1 = 2;
*(u16 *)&((struct Obj00005 *)((char *)a0))->f0 = a1;
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_0215F1C0:
a0 = 1;
    return a0;
loc_0215F1C4:
a0 = 0;
    return a0;}


int func_0215F1C8(void *a, void *b)
{
    void **slot;
    u16 *w;
    void **p;

    slot = func_02158FB4(func_0215A5F4(b));
    w = func_02159AE8(a, b);
    p = func_02030734(4, 4, 1, d_0217294C, 0x63);
    *slot = p;
    *p = w;
    *w = 0;
    func_020113D0(a, (int)func_0215F168);
    return 1;
}


/*
 * blocked:  listing 20 compiled 18
 */
int func_0215F214(int a0, int a1)
{    unsigned short *v0;

    v0 = func_02159AE8((void *)a0, (void *)a1);
loc_0215F21A:
    a0 = func_0202EB44();
loc_0215F220:
((struct Obj17703 *)((char *)v0))->f0 = a0;
a0 = 0;
    return a0;}
