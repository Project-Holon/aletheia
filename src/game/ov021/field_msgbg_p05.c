/*
 * file:     field_msgbg_p05.c
 * unit:     yes
 * function: func_0218ADC8, func_0218AE04, func_0218AE48, func_0218AEAC
 * address:  0x0218ADC8
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
 *   func_02014110  0x02014110  thumb
 *   func_02012878  0x02012878  thumb
 *   func_02188C9C  0x02188C9C  thumb
 *   func_02162564  0x02162564  thumb  ov010
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_0218AECC  0x0218AECC  thumb
 *   func_021626E8  0x021626E8  thumb  ov010
 */
#include "../../matched/include/Obj00705.h"

struct BigObj;
struct Rec1C;
struct Q;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef struct Vec { int x, y, z; } Vec;

typedef struct Obj {
    char pad[0x24];
    unsigned short dir;     /* 0x24 */
    char pad26[0x34 - 0x26];
    Vec *pos;               /* 0x34 */
} Obj;

extern u16 func_02188C9C(u8 *p);
extern void func_02014110(void *p, u16 a, s16 b, u16 c, u16 d, u32 e, u32 f, u32 g);
extern void func_02012878(struct BigObj *p, const struct Rec1C *src);
extern int func_02162564(char *p, struct Q *q);
extern void *func_021625CC(char *p, unsigned i);
extern int func_0218AECC(char *a0, int a1);
extern u8 func_021626E8(u8 *p);
void func_0218ADC8(u8 *p, int id, u32 *pos);
u32 func_0218AE04(u8 *p, void *arg);
void func_0218AE48(Obj *p, Vec *out);
int func_0218AEAC(u8 *p);


/*
 * Builds a 0x1C byte rectangle record with func_02014110 from the object's
 * map value, an id and three words, and hands it to func_02012878.
 *
 * Addresses are Black-image addresses.
 */
void func_0218ADC8(u8 *p, int id, u32 *pos)
{
    u8 buf[0x1C];

    func_02014110(buf, func_02188C9C(*(u8 * *)&((struct Obj00705 *)p)->f14), id, 0, 0, pos[0], pos[1], pos[2]);
    func_02012878(((struct Obj00705 *)p)->f8, (const struct Rec1C *)buf);
}


/*
 * Returns the current entry id from func_02162564 when it is usable
 * (func_0218AEAC or func_0218AECC accepts it), else 0xFFFF.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0218AE04(u8 *p, void *arg)
{
    u32 id = (u32)func_02162564(((struct Obj00705 *)p)->fC, arg);
    void *obj;

    if (id == 0xFFFF)
        return 0xFFFF;
    obj = func_021625CC(((struct Obj00705 *)p)->fC, (u16)id);
    if (!func_0218AEAC(obj) && !func_0218AECC(obj, ((struct Obj00705 *)p)->f24))
        return 0xFFFF;
    return id;
}


void func_0218AE48(Obj *p, Vec *out)
{
    *out = *p->pos;
    switch (p->dir) {
    case 0:
        out->z -= 0x10000;
        break;
    case 1:
        out->z += 0x10000;
        break;
    case 2:
        out->x -= 0x10000;
        break;
    case 3:
        out->x += 0x10000;
        break;
    }
}


/*
 * True when func_021626E8 reports kind 0, 5 or 6.
 *
 * Addresses are Black-image addresses.
 */
int func_0218AEAC(u8 *p)
{
    u8 v = func_021626E8(p);
    return v == 0 || v == 5 || v == 6;
}
