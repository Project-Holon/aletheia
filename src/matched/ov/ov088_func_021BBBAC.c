/*
 * function: func_021BBBAC
 * address:  0x021BBBAC
 * packet:   pkt_ov088_021BBBAC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Four identical print blocks are one static inline helper: it loads
 * p+0x68 before the bitmap call and keeps 0x440 rematerialised per site.
 *
 * symbols:
 *   func_020450F0  0x020450F0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045374  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_021BBA64  0x021BBA64  thumb  ov088
 *   func_02041EE4  0x02041EE4  arm
 *   func_021BB9DC  0x021BB9DC  thumb  ov088
 */
#include "../include/Obj06204.h"
#include "../include/Obj13234.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32);
extern void func_021BBA64(u8 x, u8 y, u8 w, u8 h, u8 bg);
extern void func_02041EE4(u32, u32, u32);
extern void func_021BB9DC(char *, int);

static inline void print_line(char *p, u32 id, u32 y, u16 color)
{
    u32 s = (u32)func_02045EC0((struct MsgBank *)(((struct Obj06204 *)p)->f5C), id);
    u32 a = ((struct Obj06204 *)p)->f68;
    func_0201C724((void *)a, (u32)func_02045770((struct Descriptor *)((struct Obj06204 *)p)->fF0), 0, y, s, ((struct Obj06204 *)p)->f58, color);
    ((struct Obj06204 *)p)->fF4 = 1;
    func_02045808((struct U16Vec *)s);
}

void func_021BBBAC(char *p)
{
    ((struct Obj13234 *)p)->fF0 = func_020450F0(0, 2, 2, 0x1e, 0x14, 5, 1);
    print_line(p, 0x16, 0, 0x14c0);
    print_line(p, 0x17, 0x18, 0x440);
    print_line(p, 0x18, 0x80, 0x440);
    print_line(p, 0x19, 0x90, 0x440);

    func_02045374((struct Cfg *)(((struct Obj13234 *)p)->fF0));
    func_02041B6C(0);
    func_021BBA64(0x20, 1, 0x20, 0x16, 2);
    func_02041EE4(1, 0, 0x100);
    func_02041EE4(1, 3, 0);
    func_02041EE4(2, 0, 0x100);
    func_02041EE4(2, 3, 0);
    func_021BB9DC(p, 0);
}
