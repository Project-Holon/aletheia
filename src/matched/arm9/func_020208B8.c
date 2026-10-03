/*
 * function: func_020208B8
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
 *   func_02043B5C  0x02043B5C  arm
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

extern u32  func_02045770(void *p);
extern void func_02043B5C(u32 a, u32 b);
extern void func_0202055C(struct Obj *o, u32 a, u32 b, u32 c, u32 d);
extern void func_02020CA0(void *win, u32 a, u32 b, u32 c, u16 tile);

void func_020208B8(struct Obj *obj, int n, u32 flag)
{
    u8 step;

    if (n >= (int)obj->rows) {
        func_02043B5C(func_02045770(obj->unk0C), obj->f18lo);
        func_0202055C(obj, obj->f40, 0, obj->rows, 1);
        return;
    }

    step = (u8)(obj->f22 + obj->f1Amid);
    if (flag == 0) {
        u8 k = obj->f18lo;
        func_02020CA0(obj->unk0C, 1, (u8)(n * step), (u8)((k << 4) | k), 0);
        func_0202055C(obj, obj->f40, 0, n, 1);
    } else {
        u8 k = obj->f18lo;
        func_02020CA0(obj->unk0C, 0, (u8)(n * step), (u8)((k << 4) | k), 0);
        func_0202055C(obj, (u16)(obj->f40 + (obj->rows - n)), (u16)(obj->rows - n), n, 0);
    }
}
