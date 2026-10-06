/*
 * function: func_021B9D54
 * address: 0x021B9D54
 * packet: pkt_ov133_021B9D54
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9C08 0x021B9C08 thumb ov133
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj00004.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void func_021B9C08(u8 *p, unsigned int index, void *object);
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EE0C(void *, u32, void *, u32, u32, u32);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
void func_021B9D54(u8 *p, int state)
{
    int index;
    void *w;
    void *str;
    if (state == 8) {
        func_021B9C08(p, 5, 0);
        return;
    }
    index = 0;
    switch (state) {
    case 0:
    case 1: index = 0x10; break;
    case 2: index = 0x11; break;
    case 3: index = 0x17; break;
    case 4: index = 0x14; break;
    case 5: index = 0x15; break;
    case 6:
    case 7: index = 0x16; break;
    }
    w = func_0201EC64(((struct Obj00004 *)p)->f0);
    str = func_02045EC0(((struct Obj00004 *)p)->f18E0, index);
    func_0201EE0C(w, 0, str, 0, 1, 2);
    func_021B9C08(p, 4, w);
    func_02045808(str);
    func_0201ED04(w);
}
