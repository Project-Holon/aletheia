/*
 * function: ZUKAN_DETAIL_MAIN_Exit
 * address: 0x021BCB4C
 * packet: pkt_ov208_021BCB4C
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 102 code bytes, then two zero alignment bytes at 021BCBB2.
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   ZUKAN_DETAIL_PROCSYS_FreeNode 0x021BC26C thumb ov208
 *   func_020307B0 0x020307B0 arm
 *   ZUKAN_DETAIL_COMMON_DeleteContext 0x021BC39C thumb ov208
 *   ZUKAN_DETAIL_HEADBAR_Delete 0x021BE778 thumb ov208
 *   ZUKAN_DETAIL_TOUCHBAR_Delete 0x021BD954 thumb ov208
 *   func_02030EAC 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   ZUKAN_DETAIL_GRAPHIC_ExitBgGraphics 0x021BCEC0 thumb ov208
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../include/Obj02253.h"
extern void FADE_Start(unsigned,int,int,int);
extern void ZUKAN_DETAIL_PROCSYS_FreeNode(void *);
struct PrintSys;
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void ZUKAN_DETAIL_COMMON_DeleteContext(void *);
struct Node;
struct Ov208Mgr;
struct PrintSys;
struct S020315D4;
extern void ZUKAN_DETAIL_HEADBAR_Delete(struct Ov208Mgr *m);
extern void ZUKAN_DETAIL_TOUCHBAR_Delete(struct Ov208Mgr *m);
extern void func_02030EAC(struct Node *n);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void ZUKAN_DETAIL_GRAPHIC_ExitBgGraphics(char *);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
int ZUKAN_DETAIL_MAIN_Exit(void *a,int b,int c,char *p)
{
    FADE_Start(3,16,16,0);
    if(((struct Obj02253 *)p)->f20)ZUKAN_DETAIL_PROCSYS_FreeNode(((struct Obj02253 *)p)->f20);
    if(((struct Obj02253 *)p)->f24)func_020307B0((void *)(((struct Obj02253 *)p)->f24));
    ZUKAN_DETAIL_COMMON_DeleteContext(((struct Obj02253 *)p)->f1C);
    ZUKAN_DETAIL_HEADBAR_Delete(((struct Obj02253 *)p)->f18);
    ZUKAN_DETAIL_TOUCHBAR_Delete(((struct Obj02253 *)p)->f14);
    func_02030EAC(((struct Obj02253 *)p)->f10);
    PRINTSYS_QUE_Clear((struct PrintSys *)(*(unsigned *)&((struct Obj02253 *)p)->fC));
    PRINTSYS_QUE_Delete(((struct Obj02253 *)p)->fC);
    GF_FONT_Delete(((struct Obj02253 *)p)->f8);
    ZUKAN_DETAIL_GRAPHIC_ExitBgGraphics(*(char * *)&((struct Obj02253 *)p)->f4);
    func_020315D4(a);
    func_020306F0(149);
    return 1;
}
