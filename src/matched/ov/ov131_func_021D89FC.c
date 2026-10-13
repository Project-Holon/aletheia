/*
 * function: P_STA_RIBBON_DeleteObjects
 * address: 0x021D89FC
 * packet: pkt_ov131_021D89FC
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   P_STA_OAM_DeleteBitmapActors 0x021DBC3C thumb ov131
 *   BMP_Delete 0x020437AC arm
 */
#include "../include/Obj23148.h"
typedef unsigned char  u8;
struct Obj;
struct Obj020437AC;
extern void CLACT_DeleteActor(struct Obj *p);
extern void P_STA_OAM_DeleteBitmapActors(u8 *p);
extern void BMP_Delete(struct Obj020437AC *p);
struct E { unsigned char p[0x7c]; void *f7c; void *f80; unsigned char q[0x14 - 0x8]; };
void P_STA_RIBBON_DeleteObjects(void *unused, unsigned char *s) {
 unsigned char i;
 CLACT_DeleteActor(((struct Obj23148 *)s)->f54);
 for (i = 0; i < 10; i++) {
  struct E *e = (struct E *)(s + i * 20);
  P_STA_OAM_DeleteBitmapActors(e->f80);
  BMP_Delete(e->f7c);
 }
}
