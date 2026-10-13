/*
 * function: func_021E11A8
 * address: 0x021E11A8
 * packet: pkt_ov119_021E11A8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200566C 0x0200566C thumb
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   func_021E106C 0x021E106C thumb ov119
 *   func_021E12F8 0x021E12F8 thumb ov119
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   TCBL_Destroy 0x02031140 arm
 */
#include "../include/Obj00001.h"
extern void func_0200566C(void);
struct PrintSys;
struct Rec3;
extern int APP_KEYCURSOR_Delete(int a0);
typedef unsigned char  u8;
struct Descriptor;
struct Rec;
struct S02031140;
struct TaskMenuState;
struct U16Vec;
struct WordSet;
extern void func_021E106C(char *p);
extern void func_021E12F8(char *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern unsigned int APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
extern unsigned int func_0201ED04(struct WordSet *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void TCBL_Destroy(struct S02031140 *p);
void func_021E11A8(char *p)
{
    int i;
    func_0200566C();
    if(*(int *)&((struct Obj00001 *)p)->f744) {
        APP_KEYCURSOR_Delete((int)(((struct Obj00001 *)p)->f74C));
        func_021E106C(p);
        func_021E12F8(p);
        if(((struct Obj00001 *)p)->f72C) {PRINTSYS_PrintStreamDelete((struct Rec3 *)(((struct Obj00001 *)p)->f72C));((struct Obj00001 *)p)->f72C=0;}
        if(((struct Obj00001 *)p)->f648) {APP_TASKMENU_WIN_Delete(((struct Obj00001 *)p)->f648);((struct Obj00001 *)p)->f648=0;}
        if(((struct Obj00001 *)p)->f6B0) {APP_TASKMENU_RES_Delete(((struct Obj00001 *)p)->f6B0);((struct Obj00001 *)p)->f6B0=0;}
        if(((struct Obj00001 *)p)->f6B4) {BMP_WIN_Delete(((struct Obj00001 *)p)->f6B4);((struct Obj00001 *)p)->f6B4=0;}
        for(i=0;i<2;i++) {if(*(void **)(p+i*4+0x5bc)) {BMP_WIN_Delete(*(void **)(p+i*4+0x5bc));*(void **)(p+i*4+0x5bc)=0;}}
        func_0201ED04(((struct Obj00001 *)p)->f724);
        MSGDATA_Delete(((struct Obj00001 *)p)->f720);
        GF_FONT_Delete(((struct Obj00001 *)p)->f728);
        STRBUF_Delete(((struct Obj00001 *)p)->f730);
        STRBUF_Delete(((struct Obj00001 *)p)->f734);
        STRBUF_Delete(((struct Obj00001 *)p)->f738);
        STRBUF_Delete(((struct Obj00001 *)p)->f73C);
        PRINTSYS_QUE_Clear((struct PrintSys *)(*(unsigned *)&((struct Obj00001 *)p)->f740));
        PRINTSYS_QUE_Delete((struct PrintSys *)(*(unsigned *)&((struct Obj00001 *)p)->f740));
        TCBL_Destroy(((struct Obj00001 *)p)->f744);
        *(int *)&((struct Obj00001 *)p)->f744=0;
    }
}
