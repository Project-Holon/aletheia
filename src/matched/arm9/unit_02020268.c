/*
 * unit:     yes
 * function: BMP_MENULIST_SetColors, BMP_MENULIST_SetOverrideColors, BMP_MENULIST_GetListIndex, BMP_MENULIST_GetPos, BMP_MENULIST_GetCursorY, BMP_MENULIST_GetRowY, BMP_MENULIST_GetItemValue, BMP_MENULIST_GetAttr
 * address:  0x02020268
 * packet:   pkt_02020268
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_MENULIST_GetRowY  0x02020324  thumb
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02020268.c \
 *       --addr 0x02020268 --thumb
 *
 * The bmp_menulist.c attribute block 0x02020268..0x02020408, eight
 * functions of which only 0x02020268 was ever near a label.  The
 * worklist entry 0x020202CC (a "32-byte open function") is NOT a
 * function start: it is the middle of BMP_MENULIST_SetOverrideColors (the colour-override
 * setter), seeded into layout/function_starts.txt from a pending header
 * that misnamed sub_02022AC4's tail-call target (the pool word there is
 * 0x020222CD; see docs/notes/pkt_02022940.c.txt, wave 11).  The 32 bytes
 * the worklist counted are BMP_MENULIST_SetOverrideColors's last eight instructions.
 *
 *   BMP_MENULIST_SetColors  set the three colour nibbles f17hi / f18lo / f18hi
 *   BMP_MENULIST_SetOverrideColors  set the override nibbles f34lo / f34hi / f35lo and the
 *                  override flag f38top (BMP_MENULIST_Create seeds the same
 *                  three from f17hi / f18lo / f18hi)
 *   BMP_MENULIST_GetListIndex  *out = f40 + f42 (list index of the cursor row)
 *   BMP_MENULIST_GetPos  optional out-pointers for f40 and f42
 *   BMP_MENULIST_GetCursorY  tail call to BMP_MENULIST_GetRowY with the cursor row f42
 *   BMP_MENULIST_GetRowY  pixel y of row n: f17lo + n * (u8)(f22 + f1Amid),
 *                  the expression unit_020206C0 inlines
 *   BMP_MENULIST_GetItemValue  arr[n].unk04, the item's value word
 *   BMP_MENULIST_GetAttr  twenty-way attribute getter; case 4 has no arm and
 *                  shares the default's -1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Elem {
    u32 unk00;
    u32 unk04;
};

struct Obj {
    struct Elem *arr;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u16 count;
    u16 rows;
    u8 f14;
    u8 f15;
    u8 f16;
    u8 f17lo : 4;
    u8 f17hi : 4;
    u8 f18lo : 4;
    u8 f18hi : 4;
    u8 f19;
    u16 f1Alo : 3;
    u16 f1Amid : 4;
    u16 f1Apad : 2;
    u16 f1Amid2 : 6;
    u16 f1Atop : 1;
    u32 f1C;
    u16 f20;
    u16 f22;
    u8 pad24[0x34 - 0x24];
    u8 f34lo : 4;
    u8 f34hi : 4;
    u8 f35lo : 4;
    u8 f35hi : 4;
    u8 f36 : 6;
    u8 f36top : 2;
    u8 f37;
    u8 f38 : 7;
    u8 f38top : 1;
    u8 pad39[0x40 - 0x39];
    u16 f40;
    u16 f42;
};

void BMP_MENULIST_SetColors(struct Obj *obj, u8 a, u8 b, u8 c)
{
    obj->f17hi = a;
    obj->f18lo = b;
    obj->f18hi = c;
}

void BMP_MENULIST_SetOverrideColors(struct Obj *obj, u8 a, u8 b, u8 c)
{
    obj->f34lo = a;
    obj->f34hi = b;
    obj->f35lo = c;
    obj->f38top = 1;
}

void BMP_MENULIST_GetListIndex(struct Obj *obj, u16 *out)
{
    *out = obj->f40 + obj->f42;
}

void BMP_MENULIST_GetPos(struct Obj *obj, u16 *a, u16 *b)
{
    if (a != 0) {
        *a = obj->f40;
    }
    if (b != 0) {
        *b = obj->f42;
    }
}

u16 BMP_MENULIST_GetRowY(struct Obj *obj, u32 n);

u16 BMP_MENULIST_GetCursorY(struct Obj *obj)
{
    return BMP_MENULIST_GetRowY(obj, obj->f42);
}

u16 BMP_MENULIST_GetRowY(struct Obj *obj, u32 n)
{
    return (u16)(obj->f17lo + n * (u8)(obj->f22 + obj->f1Amid));
}

u32 BMP_MENULIST_GetItemValue(struct Obj *obj, u32 n)
{
    return obj->arr[n].unk04;
}

u32 BMP_MENULIST_GetAttr(struct Obj *obj, u32 what)
{
    switch (what) {
    case 0:  return obj->unk04;
    case 1:  return obj->unk08;
    case 2:  return obj->count;
    case 3:  return obj->rows;
    case 5:  return obj->f14;
    case 6:  return obj->f15;
    case 7:  return obj->f16;
    case 8:  return obj->f17lo;
    case 9:  return obj->f22 + obj->f1Amid;
    case 10: return obj->f17hi;
    case 11: return obj->f18lo;
    case 12: return obj->f18hi;
    case 13: return obj->f1Alo;
    case 14: return obj->f1Amid;
    case 15: return obj->f1Apad;
    case 16: return obj->f1Amid2;
    case 17: return obj->f1Atop;
    case 18: return obj->unk0C;
    case 19: return obj->f1C;
    }
    return -1;
}
