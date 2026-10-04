/*
 * function: func_021B75A4
 * address: 0x021B75A4
 * packet: pkt_ov180_021B75A4
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: const descriptor parameter orders its argument loads before stack stores.
 * symbols:
 *   func_0204B294 0x0204B294 arm
 */
#include "../include/Obj08299.h"
#include "../include/Obj24493.h"
struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
void func_021B75A4(char *p,const char *q) {
    func_0204B294((void *)((struct Obj24493 *)p)->f9044,*(int *)(p+0x90cc+*(const int *)&((struct Obj08299 *)q)->f8*4),*(int *)(p+0x90e4+*(const int *)&((struct Obj08299 *)q)->fC*4),*(int *)(p+0x9100+*(const int *)&((struct Obj08299 *)q)->f10*4),(void *)q,*(const unsigned short *)&((struct Obj08299 *)q)->f16,141);
}
