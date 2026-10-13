/*
 * function: UNION_SUBDISP_CreateLineWindows
 * address:  0x021F0430
 * packet:   pkt_ov031_021F0430
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Re-reading the just-stored p->a[i] as the source of the second store
 * (instead of a local or a chained assignment) is what makes the compiler
 * form &p->a[i] before the call in a callee-saved register, which in turn
 * leaves room for only the first stack constant (7) to be hoisted.
 *
 * symbols:
 *   BMP_WIN_Create  0x020450F0  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

struct Slot {
    u32 h;
    u8  f;
    u8  pad[3];
};

struct Obj {
    char pad0[0x4C];
    u32 a[3];
    char pad1[0x64 - 0x58];
    struct Slot s[3];
};

void UNION_SUBDISP_CreateLineWindows(struct Obj *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        p->a[i] = BMP_WIN_Create(5, 1, (u8)(i * 0x38 / 8), 0x1D, 7, 0xF, 1);
        p->s[i].h = p->a[i];
        p->s[i].f = 0;
    }
}
