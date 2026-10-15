/*
 * function: BR_CODEIN_StatDestroy
 * address: 0x021DEA30
 * packet: pkt_ov183_021DEA30
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_CODEIN_SearchDeleteList 0x021DF388 thumb ov183
 *   BR_UTIL_Delete 0x021FC734 thumb ov186
 *   BR_BTN_DeleteObject 0x021FB494 thumb ov186
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   BR_UTIL_DeleteTask 0x021FD714 thumb ov186
 *   BR_UTIL_DeleteTextWin 0x021FD15C thumb ov186
 *   BR_UTIL_DeleteHandles 0x021FD820 thumb ov186
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 */
#include "../include/Obj00923.h"
#include "../include/Obj24582.h"
#include "../include/Obj24583.h"
#include "../include/Obj24584.h"
typedef unsigned char  u8;
struct PrintSys;
struct S020315D4;
extern void BR_CODEIN_SearchDeleteList(char *p);
extern void BR_UTIL_Delete(u8 *p);
extern void BR_BTN_DeleteObject(char *p);
extern void BR_RES_ReleaseSprite(char *p, unsigned i);
extern void BR_RES_ApplyBgSet(int a, unsigned mode);
extern void BR_UTIL_DeleteTask(void *);
extern void BR_UTIL_DeleteTextWin(void *, int);
extern void BR_UTIL_DeleteHandles(char *r5);
extern void BMP_OAM_DeleteSys(void *);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void func_020315D4(struct S020315D4 *p);
int BR_CODEIN_StatDestroy(void *a, int b, char *q, char *p)
{
    int i;
    if (((struct Obj00923 *)p)->f100 != 0) {
        BR_CODEIN_SearchDeleteList(p + 0x28);
        ((struct Obj00923 *)p)->f100 = 0;
    }
    if (((struct Obj00923 *)p)->fC != 0) {
        BR_UTIL_Delete(((struct Obj00923 *)p)->fC);
        ((struct Obj00923 *)p)->fC = 0;
    }
    if (((struct Obj00923 *)p)->f8 != 0) {
        BR_UTIL_Delete(((struct Obj00923 *)p)->f8);
        ((struct Obj00923 *)p)->f8 = 0;
    }
    if (((struct Obj00923 *)p)->f4 != 0) {
        BR_BTN_DeleteObject(((struct Obj00923 *)p)->f4);
        ((struct Obj00923 *)p)->f4 = 0;
    }
    if (((struct Obj00923 *)p)->f104 != 0) {
        BR_RES_ReleaseSprite(((struct Obj24583 *)(*(char * *)&((struct Obj00923 *)p)->f108))->f10, 6);
        BR_RES_ApplyBgSet((int)(((struct Obj24584 *)(*(char * *)&((struct Obj00923 *)p)->f108))->f10), 24);
        ((struct Obj00923 *)p)->f104 = 0;
    }
    BR_UTIL_DeleteTask(((struct Obj00923 *)p)->f10);
    if (((struct Obj00923 *)p)->f24 != 0) {
        BR_UTIL_DeleteTextWin(((struct Obj00923 *)p)->f24, ((struct Obj24582 *)q)->f10);
        ((struct Obj00923 *)p)->f24 = 0;
    }
    for (i = 0; i < 2; i++) BR_UTIL_DeleteHandles(*(void **)(p + 0x1C + i * 4));
    BMP_OAM_DeleteSys(((struct Obj00923 *)p)->f0);
    PRINTSYS_QUE_Delete(((struct Obj00923 *)p)->f14);
    func_020315D4(a);
    return 1;
}
