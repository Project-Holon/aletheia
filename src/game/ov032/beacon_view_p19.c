/*
 * file:     beacon_view_p19.c
 * unit:     yes
 * function: func_021F30B4, func_021F30D4
 * address:  0x021F30B4
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   d_021F36A0     0x021F36A0  data  a1
 */
#include "../../matched/include/Obj07640.h"

struct Descriptor;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    u32 count;
    u32 *items;
} ResList;

typedef struct {
    u16 count;
    u16 base;
} ResSpec;

typedef signed int     s32;

extern u32 func_020452E8(struct Descriptor *d);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
void func_021F30B4(char *p);
void func_021F30D4(char *this, ResList *out, const ResSpec *spec, void *arc);
extern char d_021F36A0[];

void func_021F30B4(char *p)
{
    int i;
    for (i = 0; i < 3; i++)
        func_020452E8(*(struct Descriptor **)(p + i * 20 + 0x17c));
}


void func_021F30D4(char *this, ResList *out, const ResSpec *spec, void *arc)
{
    int i;

    func_02082BCC(out, 0, 0x18);
    for (i = 0; i < 3; i++) {
        out[i].count = spec[i].count;
        if (out[i].count != 0)
            out[i].items = func_02030734(((struct Obj07640 *)this)->f94, out[i].count << 2, 1, d_021F36A0, 0x4C3);
    }
    for (i = 0; i < out[0].count; i++)
        out[0].items[i] = func_0204ABF0(arc, spec[0].base + i, 1, 0, ((struct Obj07640 *)this)->f94);
    for (i = 0; i < out[1].count; i++)
        out[1].items[i] = func_0204A6C8(arc, spec[1].base + i, 0, 1, ((struct Obj07640 *)this)->f94);
    for (i = 0; i < out[2].count; i++)
        out[2].items[i] = func_0204AF28(arc, spec[2].base + i * 2, spec[2].base + 1 + i * 2, ((struct Obj07640 *)this)->f94);
}
