/*
 * function: func_0217BDE0
 * address:  0x0217BDE0
 * packet:   pkt_ov018_0217BDE0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02175B8C  0x02175B8C  thumb  ov011
 *   func_02175BBC  0x02175BBC  thumb  ov011
 *   func_02175B34  0x02175B34  thumb  ov011
 *   func_02175CF4  0x02175CF4  thumb  ov011
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D828  0x0216D828  thumb  ov010
 *   func_02182124  0x02182124  thumb  ov018
 *   d_021DB810     0x021DB810  data   ov021  a2
 *   d_021DB834     0x021DB834  data   ov021  a2
 */
#include "../include/Obj12483.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

typedef struct { u16 f : 3; u16 g : 13; } Fh;
typedef struct { u32 f : 4; u32 g : 28; } Fw;
typedef struct { s16 x, y, z; } Vec3s;
typedef struct { s16 x, y, z, w; } Ent;

extern u16 d_021DB810[];
extern Ent d_021DB834[];

extern int func_02175B8C(u8 *);
extern int func_02175BBC(u8 *);
extern u8 *func_02175B34(u8 *);
extern int func_02175CF4(char *p, u8 *q);
struct Ctx;
extern u8 *func_020120F8(const struct Ctx *p);
struct Rec44;
extern u16 func_02012AC8(const struct Rec44 *p);
extern void *func_021A3074(unsigned char *p);
extern void func_0216D828(void *, Vec3s *);
extern int func_02182124(int, u8 *, u8 *);

int func_0217BDE0(int a, u8 *b, int c)
{
    u8 *e;
    int n;
    int idx;
    Vec3s v;

    if (func_02175B8C(b + 0x1AC) != 1)
        goto fail;
    if (func_02175BBC(b + 0x1AC) != 0)
        goto fail;
    e = func_02175B34(b + 0x1AC);
    if (e == 0)
        goto fail;
    if (((Fw *)(e + 4))->f != 4)
        goto fail;
    if (((Fh *)(b + 0x86))->f != e[0x28])
        goto fail;
    if (func_02175CF4((char *)b, b + 0x1AC) != 0)
        goto fail;
    n = func_02012AC8((const struct Rec44 *)func_020120F8((const struct Ctx *)a));
    func_0216D828(func_021A3074((void *)c), &v);
    idx = ((struct Obj12483 *)e)->f14;
    if (n != d_021DB810[idx])
        goto fail;
    if (v.x != d_021DB834[idx].x)
        goto fail;
    if (v.y != d_021DB834[idx].y)
        goto fail;
    if (v.z != d_021DB834[idx].z)
        goto fail;
    return func_02182124(a, b, e);
fail:
    return 0;
}
