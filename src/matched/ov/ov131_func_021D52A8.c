/*
 * function: P_STATUS_UpdateInput
 * address: 0x021D52A8
 * packet: pkt_ov131_021D52A8
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   P_STATUS_CheckKey 0x021D52D4 thumb ov131
 *   P_STATUS_CheckTouch 0x021D54A8 thumb ov131
 */
#include "../include/Obj00039.h"
typedef unsigned int   u32;
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int P_STATUS_CheckKey(char *);
extern void P_STATUS_CheckTouch(char *);
void P_STATUS_UpdateInput(char *p)
{
    if (((struct Obj00039 *)p)->f44 == 1 && func_0201C6B4(((struct Obj00039 *)p)->f84) == 1 && P_STATUS_CheckKey(p) == 0) {
        P_STATUS_CheckTouch(p);
    }
}
