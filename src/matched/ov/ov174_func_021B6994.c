/*
 * function: LOCAL_TVT_SYS_DeleteTextWindow
 * address: 0x021B6994
 * packet: pkt_ov174_021B6994
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 0x021B6A02..0x021B6A04 is two zero alignment bytes.
 * symbols:
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   LOCAL_TVT_CHARA_ShowWindow 0x021B7350 thumb ov174
 */
#include "../include/Obj02218.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Descriptor;
struct Rec3;
struct U16Vec;
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_02041B6C(unsigned);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
struct Descriptor;
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void LOCAL_TVT_CHARA_ShowWindow(int,int *);
void LOCAL_TVT_SYS_DeleteTextWindow(u8 *p)
{
 void *tmp; u8 i;
 if(((struct Obj02218 *)p)->f5C){
 BMP_MENUWORK_DrawWindowBorder(((struct Obj02218 *)p)->f5C,1);tmp=((struct Obj02218 *)p)->f5C;
 BMP_WIN_ClearScreen(tmp);func_02041B6C(BMP_WIN_GetBgLayer(tmp));
 BMP_WIN_Delete(((struct Obj02218 *)p)->f5C);((struct Obj02218 *)p)->f5C=0;
 }
 if(((struct Obj02218 *)p)->f64){PRINTSYS_PrintStreamDelete(((struct Obj02218 *)p)->f64);((struct Obj02218 *)p)->f64=0;}
 if(((struct Obj02218 *)p)->f70){STRBUF_Delete(((struct Obj02218 *)p)->f70);((struct Obj02218 *)p)->f70=0;}
 for(i=0;i<((struct Obj02218 *)p)->f8;i++) if(*(int **)(p+28+i*4)) LOCAL_TVT_CHARA_ShowWindow((int)p,*(int **)(p+28+i*4));
}
