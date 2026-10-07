/*
 * function: func_021BAC24
 * address: 0x021BAC24
 * packet: pkt_ov099_021BAC24
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_020450F0 0x020450F0 arm
 *   func_02045374 0x02045374 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_0201FF30 0x0201FF30 thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02020CF8 0x02020CF8 thumb
 *   func_02041B6C 0x02041B6C arm
 * prototype-evidence: visibly supplied fifth F878 and second 20CF8 inputs
 *   are retained despite legacy bodies not reading them; caller truncations
 *   fix 450F0 x/y/width/height and F73C tile parameters as u8/u16.
 */
#include "../../../matched/include/Obj00976.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 a, b; } Pair;
typedef struct { u32 w[13]; } Desc;
struct PrintSys;
struct Slot;
struct Cfg;
struct Obj;
extern void func_0201C6EC(struct PrintSys *);
extern void func_0201DD68(void);
extern struct Slot *func_0201F81C(u32, u32);
extern void func_0201F878(struct Slot *, u32, u32, u32, u32);
extern int func_021BA8BC(void *);
struct Src;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045374(struct Cfg *);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern struct Obj *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap);
extern u32 func_0201C6B4(const struct PrintSys *);
extern u32 func_0201C4E4(struct PrintSys *);
extern void func_02020CF8(struct Obj *p, int heap);
extern void func_02041B6C(u32);
void func_021BAC24(char *p, Desc *out, Pair *items, int count, int kind, u32 width)
{
    int i;
    int y;
    func_0201C6EC(*(struct PrintSys * *)&((struct Obj00976 *)p)->f1B4);
    func_0201DD68();
    *(struct Slot * *)&((struct Obj00976 *)p)->fB8 = func_0201F81C(count, 0x21);
    for (i = 0; i < count; i++)
        func_0201F878(*(struct Slot * *)&((struct Obj00976 *)p)->fB8, ((struct Obj00976 *)p)->fE0, items[i].a, items[i].b, 0x21);
    *(int *)&((struct Obj00976 *)p)->f1A4 = func_021BA8BC(((struct Obj00976 *)p)->f1A4);
    y = 5;
    if (kind == 5)
        y = 13;
    *(u32 *)&((struct Obj00976 *)p)->f1A4 = func_020450F0(2, (u8)(31 - width), (u8)y, (u8)width, (u32)count * 2, 15, 1);
    func_02045374(*(struct Cfg * *)&((struct Obj00976 *)p)->f1A4);
    func_0201F73C(((struct Obj00976 *)p)->f1A4, 2, (u16)(((struct Obj00976 *)p)->f1330), 14);
    out->w[0] = *(u32 *)&((struct Obj00976 *)p)->fB8;
    out->w[3] = *(u32 *)&((struct Obj00976 *)p)->f1A4;
    out->w[11] = *(u32 *)&((struct Obj00976 *)p)->f1B4;
    out->w[10] = (u32)(p + 0x1ac);
    out->w[12] = ((struct Obj00976 *)p)->fE8;
    out->w[7] = (u32)p;
    *(struct Obj * *)&((struct Obj00976 *)p)->fBC = func_0201FF30((struct Src *)out, 0, *(u16 *)(p + 0x234 + kind * 2), 0x21);
    if (func_0201C6B4(*(struct PrintSys * *)&((struct Obj00976 *)p)->f1B4) == 0) {
        do {
            func_0201C4E4(*(struct PrintSys * *)&((struct Obj00976 *)p)->f1B4);
        } while (func_0201C6B4(*(struct PrintSys * *)&((struct Obj00976 *)p)->f1B4) == 0);
    }
    func_02020CF8(*(struct Obj * *)&((struct Obj00976 *)p)->fBC, 0x21);
    func_02041B6C(2);
}
