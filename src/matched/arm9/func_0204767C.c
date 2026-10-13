/*
 * function: G3D_SYSTEM_CreateObject
 * address:  0x0204767C
 * packet:   pkt_0204767C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _G3dSystem     0x02146A5C  data
 *   str_020A7EA8   0x020A7EA8  data
 *   func_02030734  0x02030734  arm
 *
 * Allocate a 0x10-byte descriptor from the module heap: a 0x2185 tag, the
 * caller's key, the count, and -- only when the count is non-zero -- a second
 * allocation of count*4 bytes holding a copy of the caller's array.  Both
 * allocations pass the same module name and differ only in their line
 * constant (0x75b and 0x765).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_SYSTEM_CreateObject.c \
 *       --func G3D_SYSTEM_CreateObject --addr 0x0204767C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern struct Mod *_G3dSystem;
extern char        str_020A7EA8[];

extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);

struct Mod {
    u8  pad_00[0x18];
    u16 f18;
};

struct Desc {
    u16 tag;
    u8  pad_02[2];
    u32 key;
    u32 array;
    u16 count;
};

void *G3D_SYSTEM_CreateObject(u32 a0, u32 *a1, int a2)
{
    struct Desc *d;
    int i;

    d = (struct Desc *)func_02030734(_G3dSystem->f18, 0x10, 0, str_020A7EA8,
                                     0x75b);
    d->tag = 0x2185;
    d->key = a0;
    d->count = (u16)a2;
    if (a2 == 0) {
        d->array = 0;
    } else {
        d->array = (u32)func_02030734(_G3dSystem->f18, a2 * 4, 1, str_020A7EA8,
                                 0x765);
        if (a1 != 0 && (int)a2 > 0) {
            for (i = 0; i < a2; i++)
                ((u32 *)d->array)[i] = a1[i];
        }
    }
    return d;
}
