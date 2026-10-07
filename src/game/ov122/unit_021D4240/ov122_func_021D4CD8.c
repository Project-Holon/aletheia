/*
 * function: func_021D4CD8
 * address: 0x021D4CD8
 * packet: pkt_ov122_021D4CD8
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   data_021D58E0 0x021D58E0 data a4
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 */
#include "../../../matched/include/Obj01405.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct { int f00, f04, f08, f0c; } Row;
typedef struct { char pad00[0x10]; void *f10[11]; } Object;
extern Row data_021D58E0[];
extern unsigned int func_020450F0(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, u8 c, u8 d, u8 slot);
typedef unsigned int   u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7D0(void *, s16, s16, void *, void *, u16);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
void func_021D4CD8(int i, int value, int force, int mode, Object *p)
{
    if (p->f10[i] && !force) return;
    if (!p->f10[i])
        p->f10[i] = (void *)func_020450F0((int)7, (u8)data_021D58E0[i].f00, (u8)data_021D58E0[i].f04,
            (u8)data_021D58E0[i].f08, data_021D58E0[i].f0c, (int)13, (int)0);
    func_02043B5C(func_02045770(p->f10[i]), 0);
    if (mode) {
        func_02045CAC(((struct Obj01405 *)p)->f44, value, ((struct Obj01405 *)p)->f50);
        func_0201F250(((struct Obj01405 *)p)->f48, ((struct Obj01405 *)p)->f54, ((struct Obj01405 *)p)->f50);
    } else {
        func_02045CAC(((struct Obj01405 *)p)->f44, value, ((struct Obj01405 *)p)->f54);
    }
    func_0201C7D0(func_02045770(p->f10[i]), 0, 0, ((struct Obj01405 *)p)->f54, ((struct Obj01405 *)p)->f4C, 0x39e3);
    func_02045334(p->f10[i]);
    func_02045374(p->f10[i]);
}
