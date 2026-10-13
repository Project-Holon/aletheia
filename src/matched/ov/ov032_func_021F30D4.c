/*
 * function: func_021F30D4
 * address:  0x021F30D4
 * packet:   pkt_ov032_021F30D4
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F30D4  0x021F30D4  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   d_021F36A0     0x021F36A0  data  a1
 */
#include "../include/Obj07640.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 count;
    u32 *items;
} ResList;

typedef struct {
    u16 count;
    u16 base;
} ResSpec;

extern char d_021F36A0[];
extern void func_02082BCC(void *p, int v, int n);
typedef signed int     s32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

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
        out[0].items[i] = CLACT_RegisterPalette(arc, spec[0].base + i, 1, 0, ((struct Obj07640 *)this)->f94);
    for (i = 0; i < out[1].count; i++)
        out[1].items[i] = CLACT_RegisterCharacter(arc, spec[1].base + i, 0, 1, ((struct Obj07640 *)this)->f94);
    for (i = 0; i < out[2].count; i++)
        out[2].items[i] = CLACT_RegisterCellAnim(arc, spec[2].base + i * 2, spec[2].base + 1 + i * 2, ((struct Obj07640 *)this)->f94);
}
