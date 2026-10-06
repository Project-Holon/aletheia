/*
 * file:     time_icon_p05.c
 * unit:     yes
 * function: func_0202F0B0, sub_0202F114, sub_0202F138
 * address:  0x0202F0B0
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
 *   func_02045770   0x02045770  arm
 *   func_02043B5C   0x02043B5C  arm
 *   func_020439A0   0x020439A0  arm
 *   func_02045334   0x02045334  arm
 *   g_020A03C8      0x020A03C8  data
 */
#include "../../matched/include/Obj01310.h"

struct Descriptor;
struct Bmp;
struct CharBuf;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

struct Entry {
    u16 a;
    u16 b;
};

extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void func_02045334(struct Descriptor *a);
void func_0202F0B0(u8 *p);
u32 sub_0202F114(const u8 *p, u32 i);
u16 sub_0202F138(u32 i);
extern struct Entry g_020A03C8[];



/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F0B0.c \
 *       --func func_0202F0B0 --addr 0x0202F0B0 --cc 1.1p1 --thumb
 */
void func_0202F0B0(u8 *p)
{
    if (((struct Obj01310 *)p)->f18 == 0)
        return;

    if (((struct Obj01310 *)p)->f13 == 0) {
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01310 *)p)->f8)), ((struct Obj01310 *)p)->f12);
        func_020439A0((struct Bmp *)(((struct Obj01310 *)p)->fC), (struct Bmp *)((u32)func_02045770((struct Descriptor *)((struct Obj01310 *)p)->f8)), 0,
                      (u32)((struct Obj01310 *)p)->f15 << 4, 0, 0, 0x10, 0x10, 0);
        func_02045334((struct Descriptor *)((struct Obj01310 *)p)->f8);

        ((struct Obj01310 *)p)->f13 = ((struct Obj01310 *)p)->f14;
        ((struct Obj01310 *)p)->f15 = ((struct Obj01310 *)p)->f15 + 1;

        if (((struct Obj01310 *)p)->f15 == 8)
            ((struct Obj01310 *)p)->f15 = 0;
    } else {
        ((struct Obj01310 *)p)->f13 = ((struct Obj01310 *)p)->f13 - 1;
    }
}



/*
 * Bit i of a byte array, inverted: 1 when the bit is clear.  Unlabelled leaf
 * in the 0x0202F114..0x0202F190 gap between func_0202F0B0 and func_0202F190.
 *
 * The byte index and the bit number are both `u8` locals: the original
 * truncates each with its own `lsls #0x18`/`lsrs #0x18` pair, and `i >> 3`
 * or `i & 7` folded into the shift expression loses them (the front end
 * knows both are already in range and drops the conversions).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202F114.c \
 *       --func sub_0202F114 --addr 0x0202F114 --cc 1.1p1 --thumb
 */
u32 sub_0202F114(const u8 *p, u32 i)
{
    u8 idx = (u8)(i >> 3);
    u8 bit = (u8)(i & 7);

    if ((p[idx] & (1 << bit)) != 0)
        return 0;
    return 1;
}


/*
 * First field of entry i of the 0x2E-entry table; the sibling lookups
 * sub_0202F144 (second field) and sub_0202F170 (index) share it.  All three
 * are unlabelled leaf functions in the 0x0202F114..0x0202F190 gap.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202F138.c \
 *       --func sub_0202F138 --addr 0x0202F138 --cc 1.1p1 --thumb
 */
u16 sub_0202F138(u32 i)
{
    return g_020A03C8[i].a;
}
