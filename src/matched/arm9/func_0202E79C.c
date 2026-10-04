/*
 * function: func_0202E79C
 * address:  0x0202E79C
 * packet:   pkt_0202E79C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_020084A0  0x020084A0  thumb
 */
#include "../include/Obj08810.h"
typedef unsigned int u32;
typedef unsigned char u8;

extern void func_02082BCC(void *p, u32 v, u32 n);
struct Sub0200852CObj;
extern void func_020084A0(struct Sub0200852CObj *p);

void func_0202E79C(u8 *p)
{
    func_02082BCC(p, 0, 0x4c);
    ((struct Obj08810 *)p)->f0 = 0;
    ((struct Obj08810 *)p)->f4 = 0;
    ((struct Obj08810 *)p)->f8 = 0;
    func_020084A0((struct Sub0200852CObj *)(p + 0xc));
    func_020084A0((struct Sub0200852CObj *)(p + 0x2c));
}
