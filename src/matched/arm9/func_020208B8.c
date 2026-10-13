/*
 * function: BMP_MENULIST_ScrollRows
 * address:  0x020208B8
 * packet:   pkt_02020408
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_MENULIST_DrawItems  0x0202055C  thumb
 *   BMP_MENULIST_ShiftWindow  0x02020CA0  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj {
    void *arr;
    void *unk04;
    void *unk08;
    void *unk0C;
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
    u16 f1Amid2 : 8;
    u16 f1Atop : 1;
    u8 pad1C[0x20 - 0x1C];
    u16 f20;
    u16 f22;
    u8 pad24[0x40 - 0x24];
    u16 f40;
    u16 f42;
};

struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_MENULIST_DrawItems(struct Obj *o, u32 a, u32 b, u32 c, u32 d);
extern void BMP_MENULIST_ShiftWindow(void *win, u32 a, u32 b, u32 c, u16 tile);

void BMP_MENULIST_ScrollRows(struct Obj *obj, int n, u32 flag)
{
    u8 step;

    if (n >= (int)obj->rows) {
        BMP_Clear((struct CharBuf *)((u32)func_02045770((struct Descriptor *)obj->unk0C)), obj->f18lo);
        BMP_MENULIST_DrawItems(obj, obj->f40, 0, obj->rows, 1);
        return;
    }

    step = (u8)(obj->f22 + obj->f1Amid);
    if (flag == 0) {
        u8 k = obj->f18lo;
        BMP_MENULIST_ShiftWindow(obj->unk0C, 1, (u8)(n * step), (u8)((k << 4) | k), 0);
        BMP_MENULIST_DrawItems(obj, obj->f40, 0, n, 1);
    } else {
        u8 k = obj->f18lo;
        BMP_MENULIST_ShiftWindow(obj->unk0C, 0, (u8)(n * step), (u8)((k << 4) | k), 0);
        BMP_MENULIST_DrawItems(obj, (u16)(obj->f40 + (obj->rows - n)), (u16)(obj->rows - n), n, 0);
    }
}
