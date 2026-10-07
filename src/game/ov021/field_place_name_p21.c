/*
 * file:     field_place_name_p21.c
 * unit:     yes
 * function: func_021BD93C, func_021BD94C
 * address:  0x021BD93C
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
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3098  0x021A3098  thumb  ov021
 */
#include "../../matched/include/Obj18244.h"

struct Obj00020;
struct BigObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    char pad[8];
    void *f8;
    char pad2[0x14];
    u16 h20;
    char pad3[0x23];
    u8 b45;
    char pad4[2];
    int f48;
} Inner;

typedef struct {
    char pad[8];
    Inner *f8;
} Obj;

extern void *func_02188CB4(struct Obj00020 *p);
extern u32 func_021A3098(u8 *p);
extern u32 func_02012A30(const struct BigObj *p);
extern void func_02029D44(u32 a, u32 b, u16 c, u8 d);
void func_021BD93C(u32 a, u32 b, u32 c, u32 d);
void func_021BD94C(Obj *p);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD93C(u32 a, u32 b, u32 c, u32 d)
{
func_021A3098(func_02188CB4((struct Obj00020 *)(*(u32 *)((u8 *)(((struct Obj18244 *)((u8 *)(a)))->f8) + 12))));
}


void func_021BD94C(Obj *p)
{
    Inner *q = p->f8;
    void *r = q->f8;

    func_02029D44(func_02012A30(r), (u32)r, q->h20, q->b45);
    q->f48 = 1;
}
