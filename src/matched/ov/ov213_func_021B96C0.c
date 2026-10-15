/*
 * function: COMM_BTL_DEMO_MAIN_Delete
 * address: 0x021B96C0
 * packet: pkt_ov213_021B96C0
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   COMM_BTL_DEMO_MAIN_UpdateNetKind 0x021BA514 thumb ov213
 *   UI_SCENE_Delete 0x021B613C thumb ov067
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   COMM_BTL_DEMO_MAIN_DeleteCursor 0x021BA710 thumb ov213
 *   COMM_BTL_DEMO_MAIN_DeleteGraphics 0x021BA7B8 thumb ov213
 *   COMM_BTL_DEMO_GRAPHIC_Delete 0x021BAC0C thumb ov213
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   overlay_id 0x00000043 data a1
 */
#include "../../matched/include/Obj06704.h"
typedef unsigned short u16;typedef unsigned int u32;
struct Rec;struct PrintSys;struct S020315D4;
extern void BG_SYS_ResetSlot(u32,u32,u32);extern void COMM_BTL_DEMO_MAIN_UpdateNetKind(char *);
extern void UI_SCENE_Delete(void *);extern void MSGDATA_Delete(struct Rec *);
extern void PRINTSYS_QUE_Delete(struct PrintSys *);extern void GF_FONT_Delete(void *);
extern void COMM_BTL_DEMO_MAIN_DeleteCursor(char *),COMM_BTL_DEMO_MAIN_DeleteGraphics(char *),COMM_BTL_DEMO_GRAPHIC_Delete(unsigned char *);
extern void PROCSYS_FreeProcWork(struct S020315D4 *);extern void GFL_HEAP_DeleteChecked(u32);extern void GF_OVERLAY_Unload(int);
extern char overlay_id[];
int COMM_BTL_DEMO_MAIN_Delete(struct S020315D4 *owner,int unused,const void *cfg,char *p) {
u16 heap;
BG_SYS_ResetSlot(3,0,0);
if(*(int *)((unsigned)cfg+0x44)==2 || *(int *)((unsigned)cfg+0x44)==4)COMM_BTL_DEMO_MAIN_UpdateNetKind(p);
UI_SCENE_Delete(((struct Obj06704 *)p)->f49C4);
MSGDATA_Delete(*(void **)((unsigned)p+0x49c0));
PRINTSYS_QUE_Delete(((struct Obj06704 *)p)->f49BC);
GF_FONT_Delete(*(void **)((unsigned)p+0x49b8));
COMM_BTL_DEMO_MAIN_DeleteCursor(p+0xc);COMM_BTL_DEMO_MAIN_DeleteGraphics(p+0x24);
COMM_BTL_DEMO_GRAPHIC_Delete(((struct Obj06704 *)p)->f49B4);
heap=*(u16 *)p;PROCSYS_FreeProcWork(owner);GFL_HEAP_DeleteChecked(heap);GF_OVERLAY_Unload((int)overlay_id);return 1;
}
