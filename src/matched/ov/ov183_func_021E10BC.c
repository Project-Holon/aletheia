/*
 * function: func_021E10BC
 * address: 0x021E10BC
 * packet: pkt_ov183_021E10BC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 */
#include "../include/Obj08317.h"
struct Grid;
extern void BMP_OAM_Delete(struct Grid *);
extern void BMP_OAM_DeleteSys(void *);
void func_021E10BC(char *p){ BMP_OAM_Delete(*(struct Grid * *)&((struct Obj08317 *)p)->f304); BMP_OAM_Delete(*(struct Grid * *)&((struct Obj08317 *)p)->f308); BMP_OAM_DeleteSys(((struct Obj08317 *)p)->f300); }
