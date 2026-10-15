/*
 * function: BR_BTN_Delete
 * address:  0x021F9F48
 * packet:   pkt_021F9F48
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BR_UTIL_DeleteTask  0x021FD714  thumb  ov186
 *   BR_UTIL_DeleteTextWin  0x021FD15C  thumb  ov186
 *   BR_BTN_DeleteRecord  0x021FACE0  thumb  ov186
 *   BR_RES_ReleaseSprite  0x021FC0C8  thumb  ov186
 *   BR_BTN_DATA_Delete  0x021FB63C  thumb  ov186
 *   func_020307B0  0x020307B0  arm
 *   BMP_OAM_DeleteSys  0x02025588  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 */
#include "../include/Obj01175.h"
typedef unsigned char u8;
typedef unsigned int u32;

struct PrintSys;
extern void BR_UTIL_DeleteTask(void *p);
extern void BR_UTIL_DeleteTextWin(void *p, int a1);
extern void BR_BTN_DeleteRecord(char *p);
extern void BR_RES_ReleaseSprite(char *p, unsigned i);
extern void BR_BTN_DATA_Delete(void *p);
extern u32 func_020307B0(void *p);
extern void BMP_OAM_DeleteSys(void *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

void BR_BTN_Delete(u8 *p)
{
    int i;

    BR_UTIL_DeleteTask((void *)(((struct Obj01175 *)p)->fC));
    if (((struct Obj01175 *)p)->f50 != 0) {
        BR_UTIL_DeleteTextWin((void *)(((struct Obj01175 *)p)->f50), ((struct Obj01175 *)p)->f4);
        ((struct Obj01175 *)p)->f50 = 0;
    }
    for (i = 0; i < ((struct Obj01175 *)p)->f3B; i++)
        BR_BTN_DeleteRecord((char *)(((struct Obj01175 *)p)->f3C + i * 0x44));
    func_020307B0((void *)((struct Obj01175 *)p)->f3C);
    for (i = 0; i < ((struct Obj01175 *)p)->f39; i++)
        BR_BTN_DeleteRecord((char *)(((struct Obj01175 *)p)->f40 + i * 0x44));
    func_020307B0((void *)((struct Obj01175 *)p)->f40);
    BR_RES_ReleaseSprite((char *)(((struct Obj01175 *)p)->f4), ((struct Obj01175 *)p)->f10);
    BR_RES_ReleaseSprite((char *)(((struct Obj01175 *)p)->f4), ((struct Obj01175 *)p)->f10 + 1);
    BR_BTN_DATA_Delete((void *)(((struct Obj01175 *)p)->f44));
    BMP_OAM_DeleteSys((void *)(((struct Obj01175 *)p)->f48));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj01175 *)p)->f4C));
    func_020307B0(p);
}


