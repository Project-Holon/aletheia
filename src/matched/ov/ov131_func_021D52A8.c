/*
 * function: func_021D52A8
 * address: 0x021D52A8
 * packet: pkt_ov131_021D52A8
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_021D52D4 0x021D52D4 thumb ov131
 *   func_021D54A8 0x021D54A8 thumb ov131
 */
#include "../include/Obj00039.h"
typedef unsigned int   u32;
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int func_021D52D4(char *);
extern void func_021D54A8(char *);
void func_021D52A8(char *p)
{
    if (((struct Obj00039 *)p)->f44 == 1 && func_0201C6B4(((struct Obj00039 *)p)->f84) == 1 && func_021D52D4(p) == 0) {
        func_021D54A8(p);
    }
}
