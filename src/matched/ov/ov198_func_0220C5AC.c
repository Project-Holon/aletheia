/*
 * function: func_0220C5AC
 * address: 0x0220C5AC
 * packet: pkt_ov198_0220C5AC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj10841.h"
#include "../include/Obj25141.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
void func_0220C5AC(char *p, int i, u16 x, u16 y)
{
    void *t;
    void *f;
    t = func_02045EC0(((struct Obj10841 *)p)->f1EA0, 0x14);
    f = ((struct Obj10841 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(*(void **)(p + 0x1F70 + i * 8)), x, y, (u32)t, ((struct Obj25141 *)(*(char * *)&((struct Obj10841 *)p)->f0))->fC, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
}
