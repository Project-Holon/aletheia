/*
 * function: func_021BAD74
 * address: 0x021BAD74
 * packet: pkt_ov099_021BAD74
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C37A0 0x021C37A0 data a4
 *   d_021C3730 0x021C3730 data a4
 *   func_021B97F4 0x021B97F4 thumb ov099
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021C27E0 0x021C27E0 thumb ov099
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   BMP_MENULIST_Create 0x0201FF30 thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BMP_MENULIST_ResetCursorTile 0x02020CF8 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 * prototype-evidence: C23B8 forwards the visibly supplied index to ov009
 *   56860, whose full body returns the address consumed here; BDD48's
 *   result is explicitly narrowed to u16 here, so its extern is wide.
 *   F878/20CF8 retain visibly supplied unused trailing heap arguments.
 * layout-evidence: the template copy is 13 words; count/rows occupy +10/+12.
 */
#include "../include/Obj01244.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 a, b; } Pair;
typedef struct {
    u32 w0, w4, w8, wc;
    u16 count, rows;
    u32 w14, w18, w1c, w20, w24, w28, w2c, w30;
} Desc;
struct W;
struct S;
struct Slot;
struct PrintSys;
struct Obj;
struct Cfg;
extern Desc d_021C37A0;
extern const Pair d_021C3730[];
extern u8 func_021B97F4(struct W *);
extern int func_021C23B8(int i);
extern u32 func_021BDD48(int, struct S *);
extern int func_021C27E0(struct S *);
extern struct Slot *BMP_MENUWORK_Create(u32, u32);
extern void BMP_MENUWORK_AddMsgItem(struct Slot *, u32, u32, u32, u32);
struct Src;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern struct Obj *BMP_MENULIST_Create(struct Src *src, u16 a, u16 b, u32 heap);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *);
extern void BMP_MENULIST_ResetCursorTile(struct Obj *p, int heap);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern void func_02041B6C(u32);
void func_021BAD74(char *p)
{
    int n;
    Desc desc;
    struct S *state;
    u16 kind;
    u32 i;
    n = 2;
    desc = d_021C37A0;
    state = (struct S *)func_021C23B8(func_021B97F4((struct W *)(p + 0x274)) - 1);
    kind = (u16)func_021BDD48((int)p, state);
    func_021C27E0(state);
    func_021C27E0(*(struct S * *)&((struct Obj01244 *)p)->f8);
    *(struct Slot * *)&((struct Obj01244 *)p)->fB8 = BMP_MENUWORK_Create(2, 33);
    for (i = 0; i < 2; i++) {
        if (i == 0 && kind != 2 && kind != 5 && kind != 1) {
            desc.rows--;
            desc.count--;
            n--;
        } else {
            BMP_MENUWORK_AddMsgItem(*(struct Slot * *)&((struct Obj01244 *)p)->fB8, ((struct Obj01244 *)p)->fE0, d_021C3730[i].a, d_021C3730[i].b, 33);
        }
    }
    *(u32 *)&((struct Obj01244 *)p)->f1A4 = BMP_WIN_Create(2, 16, (u8)((3 - n) * 2 + 11), 15, n * 2, 15, 1);
    func_0201F73C(((struct Obj01244 *)p)->f1A4, 2, (u16)(((struct Obj01244 *)p)->f1334), 14);
    desc.w0 = *(u32 *)&((struct Obj01244 *)p)->fB8;
    desc.wc = *(u32 *)&((struct Obj01244 *)p)->f1A4;
    desc.w2c = *(u32 *)&((struct Obj01244 *)p)->f1B4;
    desc.w28 = (u32)(p + 0x1ac);
    desc.w30 = ((struct Obj01244 *)p)->fE8;
    *(struct Obj * *)&((struct Obj01244 *)p)->fBC = BMP_MENULIST_Create((struct Src *)(&desc), 0, 0, 33);
    if (PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct Obj01244 *)p)->f1B4) == 0) {
        do {
            PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct Obj01244 *)p)->f1B4);
        } while (PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct Obj01244 *)p)->f1B4) == 0);
    }
    BMP_MENULIST_ResetCursorTile(*(struct Obj * *)&((struct Obj01244 *)p)->fBC, 33);
    BMP_WIN_MakeScreen(*(struct Cfg * *)&((struct Obj01244 *)p)->f1A4);
    func_02041B6C(2);
}
