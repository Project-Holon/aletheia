/*
 * function: DENDOU_VIEW_ExitPageCounterOam
 * address: 0x021DE884
 * packet: pkt_ov171_021DE884
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_Delete 0x020437AC arm
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 */
#include "../include/Obj08252.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Grid;
struct Obj020437AC;
extern void BMP_OAM_Delete(struct Grid *g);
extern void BMP_Delete(struct Obj020437AC *p);
extern void BMP_OAM_DeleteSys(void *);
void DENDOU_VIEW_ExitPageCounterOam(int *p) { BMP_OAM_Delete(((struct Obj08252 *)p)->fC54); BMP_Delete(((struct Obj08252 *)p)->fC58); BMP_OAM_DeleteSys(((struct Obj08252 *)p)->fC50); }
