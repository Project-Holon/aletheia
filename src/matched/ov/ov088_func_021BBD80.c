/*
 * unit:     yes
 * function: func_021BBD80, func_021BBE3C
 * address:  0x021BBD80
 * packet:   pkt_ov088_021BBD80
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 0x021BBE3C is an unlabelled tail-call stub (function_starts seed).
 * Twin of func_021BBBAC (same print_line inline).
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
 *   func_020452E8  0x020452E8  arm
 */
#include "../include/Obj06205.h"
#include "../include/Obj13235.h"
#include "../include/Obj20821.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Descriptor;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(u32 a, u32 bmp, u32 x, u32 y, u32 text, u32 f, u16 color);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32);
extern void func_021BBA64(u8 x, u8 y, u8 w, u8 h, u8 bg);
extern void func_020452E8(struct Descriptor *d);

static inline void print_line(char *p, u32 id, u32 y, u16 color)
{
    u32 s = (u32)func_02045EC0((struct MsgBank *)(((struct Obj06205 *)p)->f5C), id);
    u32 a = ((struct Obj06205 *)p)->f68;
    func_0201C724(a, (u32)func_02045770((struct Descriptor *)((struct Obj06205 *)p)->fF0), 0, y, s, ((struct Obj06205 *)p)->f58, color);
    ((struct Obj06205 *)p)->fF4 = 1;
    func_02045808((struct U16Vec *)s);
}

void func_021BBD80(char *p)
{
    ((struct Obj13235 *)p)->fF0 = func_020450F0(4, 2, 3, 0x1e, 0x13, 5, 1);
    print_line(p, 0x14, 0, 0x14c0);
    print_line(p, 0x15, 0x18, 0x440);
    func_02045374((struct Cfg *)(((struct Obj13235 *)p)->fF0));
    func_02041B6C(4);
    func_021BBA64(0, 1, 0x20, 0x16, 5);
}

void func_021BBE3C(char *p)
{
    func_020452E8(((struct Obj20821 *)p)->fF0);
}
