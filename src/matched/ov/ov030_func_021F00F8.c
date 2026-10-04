/*
 * unit: yes
 * function: func_021F00F8, func_021F0114
 * address: 0x021F00F8
 * packet: pkt_ov030_021F00F8
 * region: ov030
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: empty follower func_021F0114 then two-byte zero padding.
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_0201283C 0x0201283C thumb
 *   func_0201058C 0x0201058C thumb
 */
#include "../include/Obj13049.h"
typedef unsigned int u32;
struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_0201058C(void *key);
void func_021F00F8(char *p)
{
    if (*(void (**)(char *))p != 0) {
        (*(void (**)(char *))p)(p);
    }
    func_0201058C((void *)func_0201283C(func_020120F4(((struct Obj13049 *)p)->f18)));
}
void func_021F0114(void)
{
}
