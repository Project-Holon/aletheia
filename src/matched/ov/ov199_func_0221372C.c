/*
 * function: func_0221372C
 * address: 0x0221372C
 * packet: pkt_ov199_0221372C
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   func_0203133C 0x0203133C arm
 *   func_020307B0 0x020307B0 arm
 *   d_02213D00 0x02213D00 data a4 ov199
 */
#include "../include/Obj14584.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct S020314B8;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_02213D00[];
extern void func_0203133C(struct S020314B8 *p);
extern u32 func_020307B0(void *p);
void func_0221372C(char *p)
{
    if (((struct Obj14584 *)p)->f4) func_02034714(d_02213D00, 0, d_02213D00);
    func_0203133C(((struct Obj14584 *)p)->f0);
    func_020307B0(p);
}
