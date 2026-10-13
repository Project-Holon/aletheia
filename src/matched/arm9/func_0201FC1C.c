/*
 * function: BMP_MENU_GetMaxItemWidth
 * address:  0x0201FC1C
 * packet:   pkt_0201F93C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Elem {
    u32 f0;
    u32 f4;
};

struct Obj {
    struct Elem *arr;
    u8   pad[5];
    u8   unk09;
    u8   unk0a;
    u8   pad2[0x11];
    u32  unk1c;
};

struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);

u32 BMP_MENU_GetMaxItemWidth(struct Obj *o)
{
    u32 best = 0;
    u8 i;

    for (i = 0; i < o->unk09 * o->unk0a; i++) {
        u32 r = (u8)func_0201D304((struct StrObj *)o->arr[i].f0, o->unk1c, 0);

        if (best < r) {
            best = r;
        }
    }
    return best;
}
