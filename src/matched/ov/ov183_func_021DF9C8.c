/*
 * function: func_021DF9C8
 * address: 0x021DF9C8
 * packet: pkt_ov183_021DF9C8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E037C 0x021E037C thumb ov183
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 */
#include "../include/Obj10749.h"
#include "../include/Obj14433.h"
extern void func_021E037C(char *, char *);
extern void BR_RES_ReleaseSprite(char *p, unsigned i);
extern void func_021FD820(char *);
extern void func_021FD15C(void *, int);
extern void BMP_OAM_DeleteSys(void *);
struct PrintSys;
struct S020315D4;
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void func_020315D4(struct S020315D4 *p);
int func_021DF9C8(void *p, int unused, char *q, char *data)
{
    int i;
    func_021E037C(data, q);
    BR_RES_ReleaseSprite((char *)(((struct Obj14433 *)q)->f8), 6);
    for (i = 0; i < 2; i++) func_021FD820(*(char **)(data + i * 4 + 0x3c));
    func_021FD15C(((struct Obj10749 *)data)->f38, ((struct Obj14433 *)q)->f8);
    BMP_OAM_DeleteSys(((struct Obj10749 *)data)->f44);
    PRINTSYS_QUE_Delete(((struct Obj10749 *)data)->f48);
    func_020315D4(p);
    return 1;
}
