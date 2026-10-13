/*
 * function: func_021B96C0
 * address: 0x021B96C0
 * packet: pkt_ov213_021B96C0
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02041EE4 0x02041EE4 arm
 *   func_021BA514 0x021BA514 thumb ov213
 *   UI_SCENE_Delete 0x021B613C thumb ov067
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_021BA710 0x021BA710 thumb ov213
 *   func_021BA7B8 0x021BA7B8 thumb ov213
 *   func_021BAC0C 0x021BAC0C thumb ov213
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   overlay_id 0x00000043 data a1
 */
#include "../../matched/include/Obj06704.h"
typedef unsigned short u16;typedef unsigned int u32;
struct Rec;struct PrintSys;struct S020315D4;
extern void func_02041EE4(u32,u32,u32);extern void func_021BA514(char *);
extern void UI_SCENE_Delete(void *);extern void MSGDATA_Delete(struct Rec *);
extern void PRINTSYS_QUE_Delete(struct PrintSys *);extern void GF_FONT_Delete(void *);
extern void func_021BA710(char *),func_021BA7B8(char *),func_021BAC0C(unsigned char *);
extern void PROCSYS_FreeProcWork(struct S020315D4 *);extern void func_020306F0(u32);extern void GF_OVERLAY_Unload(int);
extern char overlay_id[];
int func_021B96C0(struct S020315D4 *owner,int unused,const void *cfg,char *p) {
u16 heap;
func_02041EE4(3,0,0);
if(*(int *)((unsigned)cfg+0x44)==2 || *(int *)((unsigned)cfg+0x44)==4)func_021BA514(p);
UI_SCENE_Delete(((struct Obj06704 *)p)->f49C4);
MSGDATA_Delete(*(void **)((unsigned)p+0x49c0));
PRINTSYS_QUE_Delete(((struct Obj06704 *)p)->f49BC);
GF_FONT_Delete(*(void **)((unsigned)p+0x49b8));
func_021BA710(p+0xc);func_021BA7B8(p+0x24);
func_021BAC0C(((struct Obj06704 *)p)->f49B4);
heap=*(u16 *)p;PROCSYS_FreeProcWork(owner);func_020306F0(heap);GF_OVERLAY_Unload((int)overlay_id);return 1;
}
