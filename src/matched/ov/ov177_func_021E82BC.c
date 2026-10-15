/*
 * function: WIFIBATTLEMATCH_VIEW_DeletePartyWindow
 * address: 0x021E82BC
 * packet: pkt_ov177_021E82BC
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware write 021E82C4.
 * symbols:
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj06583.h"
struct Descriptor;
struct Obj;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern u32 func_020307B0(void *p);
void WIFIBATTLEMATCH_VIEW_DeletePartyWindow(char *p)
{
 int i;
 *(volatile unsigned short *)0x04000050 = 0;
 for(i=0;i<6;i++) {if(*(void **)(p+i*4+0x68)!=0){BMP_WIN_ClearScreen(*(void **)(p+i*4+0x68));BMP_WIN_Delete(*(void **)(p+i*4+0x68));}}
 for(i=0;i<14;i++)if(*(void **)(p+i*4+0x30)!=0)CLACT_DeleteActor(*(void **)(p+i*4+0x30));
 CLACT_ReleaseCharacter((u32)(((struct Obj06583 *)p)->f28));CLACT_ReleaseCellAnim((u32)(((struct Obj06583 *)p)->f2C));CLACT_ReleasePalette((u32)(((struct Obj06583 *)p)->f24));
 for(i=0;i<6;i++)if(*(void **)(p+i*4+0x30)!=0)CLACT_ReleaseCharacter((u32)(*(void **)(p+i*4+4)));
 CLACT_ReleaseCellAnim((u32)(((struct Obj06583 *)p)->f20));CLACT_ReleasePalette((u32)(((struct Obj06583 *)p)->f0));func_020307B0(p);
}
