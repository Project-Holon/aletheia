/*
 * function: func_021BD3B8
 * address: 0x021BD3B8
 * packet: pkt_ov172_021BD3B8
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_02030EAC 0x02030EAC arm
 *   DRAW_SYSTEM_DeleteCanvas 0x021B6C34 thumb ov172
 *   func_021BBA88 0x021BBA88 thumb ov172
 *   CTVT_DRAW_Free 0x021BA2B8 thumb ov172
 *   CTVT_TALK_Delete 0x021B8CB0 thumb ov172
 *   func_021B7DCC 0x021B7DCC thumb ov172
 *   CTVT_CAMVIEW_Delete 0x021B70A8 thumb ov172
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   func_021BDC70 0x021BDC70 thumb ov172
 *   func_021BDB5C 0x021BDB5C thumb ov172
 *   func_021BD7D0 0x021BD7D0 thumb ov172
 */
#include "../include/Obj03855.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
struct Node;
struct TaskMenuState;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void func_02030EAC(struct Node *n);
extern void DRAW_SYSTEM_DeleteCanvas(char *);
extern void func_021BBA88(int unused, int v);
extern void CTVT_DRAW_Free(int unused, int v);
extern void CTVT_TALK_Delete(void *, char *);
extern void func_021B7DCC(void *p, char *q);
extern void CTVT_CAMVIEW_Delete(int unused, char *q);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void func_021BDC70(u32 *a0);
extern void func_021BDB5C(u8 *);
extern void func_021BD7D0(void *);
void func_021BD3B8(u8 *p)
{
    u8 i;
    for (i=0; i<4; i++) BMP_WIN_Delete((struct Descriptor *)(*(u32 *)(p + i*4 + 0x1b8)));
    func_02030EAC((struct Node *)(((struct Obj03855 *)p)->f4));
    DRAW_SYSTEM_DeleteCanvas(*(char * *)&((struct Obj03855 *)p)->f1F4);
    func_021BBA88((int)p, ((struct Obj03855 *)p)->f1F0);
    CTVT_DRAW_Free((int)p, ((struct Obj03855 *)p)->f1EC);
    CTVT_TALK_Delete(p, *(char * *)&((struct Obj03855 *)p)->f1E8);
    func_021B7DCC(p, (char *)(((struct Obj03855 *)p)->f1E4));
    CTVT_CAMVIEW_Delete((int)p, (char *)(((struct Obj03855 *)p)->f1E0));
    APP_TASKMENU_RES_Delete((struct TaskMenuState *)(((struct Obj03855 *)p)->f1D4));
    func_021BDC70((u32 *)p);
    func_021BDB5C(p);
    func_021BD7D0(p);
}
