/*
 * file:     iss_city_sys_p06.c
 * unit:     yes
 * function: func_0202ADD8, func_0202AE04, func_0202AE08, func_0202AE34, func_0202AE60, func_0202AE64, func_0202AE68
 * address:  0x0202ADD8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_0202AF30  0x0202AF30  thumb
 */
#include "../../matched/include/Obj16760.h"
#include "../../matched/include/Obj11306.h"
#include "../../matched/include/Obj17264.h"

typedef unsigned char u8;

typedef unsigned int  u32;

struct Container {
    u8 pad[0x14];
    void **items;
    u8 count;
};

typedef signed int   s32;

extern u32 sub_0202AF30(void *obj);
extern int func_0202AD8C(int a0);
extern int func_0202AE9C(void *obj);
extern u32 func_0202AE64(u8 *p);
extern void func_0202AEB8(void *obj, u32 value);
u32 sub_0202AE04(void *obj);
int func_0202AE08(void *obj);
int func_0202AE34(void *obj);
void sub_0202AE60(void *obj, u32 value);
u32 sub_0202AE64(void *obj);
int func_0202AE68(void *obj);


u8 func_0202ADD8(struct Container *p, u32 key)
{
    int i;
    u8 count = p->count;

    for (i = 0; i < count; i++) {
        if (key == sub_0202AF30(p->items[i])) {
            return (u8)i;
        }
    }

    return 0xff;
}


/*
 * A plain word getter at offset 0x10. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202AE04.c \
 *       --func sub_0202AE04 --addr 0x0202AE04 --cc 1.1p1 --thumb
 */
u32 sub_0202AE04(void *obj)
{
    return ((struct Obj16760 *)obj)->f10;
}


int func_0202AE08(void *obj)
{
    s32 val = (s32)sub_0202AE04(obj) + 2;

    if (val >= 0x7f) {
        val = 0x7f;
    }

    if (val == (s32)sub_0202AE04(obj)) {
        return 0;
    }

    sub_0202AE60(obj, val);
    return 1;
}


int func_0202AE34(void *obj)
{
    s32 val = (s32)sub_0202AE04(obj) - 2;

    if (val <= 0) {
        val = 0;
    }

    if (val == (s32)sub_0202AE04(obj)) {
        return 0;
    }

    sub_0202AE60(obj, val);
    return 1;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * A setter at offset 0x10 immediately followed by a getter at offset 0xc,
 * back to back with no gap. Neither has a relocation.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202AE60.c \
 *       --addr 0x0202AE60 --thumb
 */
void sub_0202AE60(void *obj, u32 value)
{
    ((struct Obj17264 *)obj)->f10 = value;
}


u32 sub_0202AE64(void *obj)
{
    return ((struct Obj11306 *)obj)->fC;
}


/*
 * Blocked: 0202AE9C (thumb, from name) has no witness outside 0202AE68..0202AE9A. Every concrete byte reproduces.
 */
int func_0202AE68(void *obj)
{
    int v;

    if (func_0202AD8C((int)obj) == 0) {
        return 0;
    }
    v = func_0202AE9C(obj);
    if (v == func_0202AE64(obj)) {
        return 0;
    }
    func_0202AEB8(obj, v);
    return 1;
}
