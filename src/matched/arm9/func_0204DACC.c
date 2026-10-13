/*
 * function: CLACT_SetupCharacterVram
 * address:  0x0204DACC
 * packet:   pkt_0204DACC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02063790    0x02063790  arm
 *   CLACT_IsVramTypeCompatible    0x0204D9B4  arm
 *   VMAN_Alloc    0x02034660  arm
 *   func_020346D8    0x020346D8  arm
 *   CLACT_UpdateObjMapping    0x0204DC70  arm
 *   func_02063828    0x02063828  arm
 *   func_02063A54    0x02063A54  arm
 *   func_02063C80    0x02063C80  arm
 *
 * Upload one 0x40-byte cell's two graphics halves to VRAM. The optional
 * fourth argument supplies an override key: when it is null the key comes
 * from the sink's +0x10 field and the "overridden" flag stays clear;
 * otherwise it is the first word of the override's +0x0C block, with the
 * flag set. func_02063790 resets the cell's three-word handle triple, then
 * each half (the +0x2C descriptor against bank +0x00 and kind 1, the +0x34
 * descriptor against bank +0x04 and kind 2) is uploaded only when
 * CLACT_IsVramTypeCompatible admits the mode pair and VMAN_Alloc finds the resource:
 * func_020346D8 turns the descriptor into a byte offset, CLACT_UpdateObjMapping
 * selects the VRAM window, and one of the three upload entries is chosen by
 * the override flag and, failing that, by the sink's own +0x08 selector.
 * Finally the sink pointer is published at +0x28 (null when not overridden)
 * and the key is packed into the low 31 bits of the word at +0x3C.
 */
#include "../include/Obj08865.h"

typedef unsigned int u32;
typedef unsigned char u8;

struct Cell;

struct Res {
    u32 f00;
    u32 f04;
    u32 f08;
};

struct Sink {
    u32 f00;
    u32 f04;
    u32 f08;
    u8  pad0C[4];
    u32 f10;
};

struct Ovr {
    u8  pad00[0xc];
    u32 *f0C;
};

struct Item020346D8;
struct Out;
struct TargetStruct;
extern void func_02063790(u32 *p);
extern u32 CLACT_IsVramTypeCompatible(u32 a, u32 b);
extern int VMAN_Alloc(u8 *p, u32 a, void **out);
extern u32 func_020346D8(struct Item020346D8 *a, u32 *b);
extern void CLACT_UpdateObjMapping(struct TargetStruct *obj, int which);
extern void func_02063828(struct Res *r, u32 dst, int mode, struct Out *out);
extern void func_02063A54(struct Res *r, u32 dst, int mode, struct Out *out);
extern void func_02063C80(struct Res *r, u32 dst, int mode, struct Out *out);

void CLACT_SetupCharacterVram(struct Res *r, u32 idx, struct Sink *s, struct Ovr *ovr,
                   u32 mode)
{
    u8 *cell;
    u32 ovrd;
    u32 key;
    u32 kind;
    u32 off;

    cell = (u8 *)r->f08 + idx * 0x40;

    if (ovr == 0) {
        key = s->f10;
        ovrd = 0;
    } else {
        ovrd = (ovr->f0C != 0);
        if (ovrd) key = *ovr->f0C;
        else key = 0;
        ovrd = 1;
    }

    func_02063790((u32 *)cell);

    if (CLACT_IsVramTypeCompatible(mode, 0) != 0) {
        if (VMAN_Alloc((u8 *)r->f00, key, (void **)(cell + 0x2c)) != 0) {
            off = func_020346D8((struct Item020346D8 *)r->f00, (u32 *)(cell + 0x2c));
            kind = 1;
            CLACT_UpdateObjMapping((struct TargetStruct *)s, (int)kind);
            if (ovrd != 0) {
                func_02063C80((struct Res *)s, off, (int)kind, (struct Out *)cell);
            } else if (s->f08 != 0) {
                func_02063828((struct Res *)s, off, (int)kind, (struct Out *)cell);
            } else {
                func_02063A54((struct Res *)s, off, (int)kind, (struct Out *)cell);
            }
        }
    }

    if (CLACT_IsVramTypeCompatible(mode, 1) != 0) {
        if (VMAN_Alloc((u8 *)r->f04, key, (void **)(cell + 0x34)) != 0) {
            off = func_020346D8((struct Item020346D8 *)r->f04, (u32 *)(cell + 0x34));
            kind = 2;
            CLACT_UpdateObjMapping((struct TargetStruct *)s, (int)kind);
            if (ovrd != 0) {
                func_02063C80((struct Res *)s, off, (int)kind, (struct Out *)cell);
            } else if (s->f08 != 0) {
                func_02063828((struct Res *)s, off, (int)kind, (struct Out *)cell);
            } else {
                func_02063A54((struct Res *)s, off, (int)kind, (struct Out *)cell);
            }
        }
    }

    if (ovrd == 0) s = 0;
    ((struct Obj08865 *)cell)->f28 = (u32)s;
    ((struct Obj08865 *)cell)->f3C = (((struct Obj08865 *)cell)->f3C & 0x80000001)
                          | ((key << 2) >> 1);
}
