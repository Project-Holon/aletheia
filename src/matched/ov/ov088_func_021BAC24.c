/*
 * function: func_021BAC24
 * address:  0x021BAC24
 * packet:   pkt_ov088_021BAC24
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 *   func_0202E940  0x0202E940  thumb
 *   func_0202E9AC  0x0202E9AC  thumb
 */
#include "../include/Obj00014.h"

typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049238(void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CodeIn;
extern struct CodeIn *func_0202E940(u16 a0, u16 a1, u32 a2, u16 heap);
extern void func_0202E9AC(struct CodeIn *p, u8 *a1, u32 a2, u32 a3, u32 a4);

void func_021BAC24(char *p)
{
    void *h;
    h = func_020490F4(0x23, 0x800B);
    ((struct Obj00014 *)p)->f11C = (int)func_0202E940(0x20, 0x10, 2, 0xb);
    func_0202E9AC((struct CodeIn *)(((struct Obj00014 *)p)->f11C), h, 4, 0x20, 0x30);
    func_02049238(h);
}
