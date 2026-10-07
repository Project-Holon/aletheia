/*
 * function: func_021F37FC
 * address: 0x021F37FC
 * packet: pkt_ov048_021F37FC
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F37A4 0x021F37A4 thumb ov048
 */
#include "../../../matched/include/Obj00377.h"
#include "../../../matched/include/Obj09834.h"
typedef unsigned short u16;
extern char *func_021F37A4(int a);
void func_021F37FC(int *p) { char *q; q=func_021F37A4(p[1]); p[4]=((struct Obj09834 *)q)->f0; p[6]=((struct Obj09834 *)q)->f4; ((struct Obj00377 *)p)->f64=((struct Obj09834 *)q)->f8; }
