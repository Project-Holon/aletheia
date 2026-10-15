/*
 * function: LOCAL_TVT_SYS_UpdateText
 * address: 0x021B687C
 * packet: pkt_ov174_021B687C
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_Main 0x020310C4 arm
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   LOCAL_TVT_CHARA_SetState 0x021B7364 thumb ov174
 *   func_02028484 0x02028484 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 */
#include "../include/Obj00152.h"
typedef unsigned char u8;
typedef signed int     s32;
typedef unsigned int   u32;
struct Blk;
struct Ctx;
struct PrintSys;
struct Rec3;
struct Tcbl;
struct U16Vec;
extern void TCBL_Main(struct Tcbl *p);
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern unsigned PRINTSYS_PrintStreamGetState(void *);
extern void LOCAL_TVT_CHARA_SetState(char *p, int v);
extern s32 func_02028484(struct Blk *blk, void *h);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
void LOCAL_TVT_SYS_UpdateText(u8 *p)
{
    TCBL_Main(((struct Obj00152 *)p)->f58);
    if(((struct Obj00152 *)p)->f64) {
        APP_KEYCURSOR_Update(((struct Obj00152 *)p)->f7C,((struct Obj00152 *)p)->f64,((struct Obj00152 *)p)->f5C);
        if(PRINTSYS_PrintStreamGetState(((struct Obj00152 *)p)->f64)!=0) LOCAL_TVT_CHARA_SetState(*(void **)(p+28+((struct Obj00152 *)p)->f88*4),0);
        else LOCAL_TVT_CHARA_SetState(*(void **)(p+28+((struct Obj00152 *)p)->f88*4),1);
        if(func_02028484((struct Blk *)(p+128),((struct Obj00152 *)p)->f64)==1) {
            PRINTSYS_PrintStreamDelete(((struct Obj00152 *)p)->f64);
            ((struct Obj00152 *)p)->f64=0;
            STRBUF_Delete(((struct Obj00152 *)p)->f70);
            ((struct Obj00152 *)p)->f70=0;
        }
    }
    PRINTSYS_QUE_Main(((struct Obj00152 *)p)->f78);
}
