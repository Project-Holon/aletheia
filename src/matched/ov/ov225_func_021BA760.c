/*
 * function: MANUAL_COMMON_UpdateListWork, MANUAL_COMMON_ListWorkTaskNoop
 * unit: yes
 * extent: lead 308 bytes; empty callback at 021BA894 and two zero alignment bytes.
 * arity: 02028178 retains original r1 payload despite unused input in its body.
 * address: 0x021BA760
 * packet: pkt_ov225_021BA760
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   MANUAL_COMMON_DeleteListWorkAssets 0x021BAA50 thumb ov225
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   MANUAL_COMMON_UpdateListWorkDrag 0x021BAE2C thumb ov225
 *   MANUAL_COMMON_UpdateTouchbar 0x021B9FBC thumb ov225
 *   MANUAL_COMMON_GetTouchbarPressed 0x021BA158 thumb ov225
 *   MANUAL_COMMON_GetTouchbarSelected 0x021BA154 thumb ov225
 *   MANUAL_COMMON_UpdateListWorkInput 0x021BAABC thumb ov225
 *   MANUAL_COMMON_GetCursorIndex 0x021BB034 thumb ov225
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 */
#include "../include/Obj00601.h"
#include "../include/Obj26179.h"
#include "../include/Obj26180.h"
#include "../include/Obj26181.h"
#include "../include/Obj26182.h"
#include "../include/Obj26183.h"
#include "../include/Obj26184.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *);
extern void MANUAL_COMMON_DeleteListWorkAssets(char *);
extern void APP_TASKMENU_WIN_Update(u8 *p);
extern int MANUAL_COMMON_UpdateListWorkDrag(char *);
extern void MANUAL_COMMON_UpdateTouchbar(char *);
extern unsigned MANUAL_COMMON_GetTouchbarPressed(char *);
extern unsigned MANUAL_COMMON_GetTouchbarSelected(char *);
extern int MANUAL_COMMON_UpdateListWorkInput(char *);
extern u16 MANUAL_COMMON_GetCursorIndex(u16 **);
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *);
int MANUAL_COMMON_UpdateListWork(char *p)
{
 u8 i;
 int result=0;
 unsigned selected;
 if(!PRINTSYS_QUE_IsFinished(*(const struct PrintSys * *)&((struct Obj26179 *)(*(char * *)&((struct Obj00601 *)p)->f4))->f14)) return 0;
 if(((struct Obj00601 *)p)->f90==0) result=1;
 else if(((struct Obj00601 *)p)->f90>0) {
  if(((struct Obj00601 *)p)->f90==1) MANUAL_COMMON_DeleteListWorkAssets(p);
  (((struct Obj00601 *)p)->f90)--;
 }
 if(((struct Obj00601 *)p)->f84!=1) {
  for(i=0;i<8;i++) {
   if(*(u8 **)(p+i*4+0xc) && *(void **)(p+i*4+0x2c))
    APP_TASKMENU_WIN_Update(*(u8 **)(p+i*4+0xc));
  }
 }
 if(((struct Obj00601 *)p)->f84==0 || ((struct Obj00601 *)p)->f84==2) {
  if(MANUAL_COMMON_UpdateListWorkDrag(p)) ((struct Obj00601 *)p)->f84=2;
  else ((struct Obj00601 *)p)->f84=0;
 }
 if(((struct Obj00601 *)p)->f84==0 || ((struct Obj00601 *)p)->f84==3) {
  MANUAL_COMMON_UpdateTouchbar(*(char * *)&((struct Obj26180 *)(*(char * *)&((struct Obj00601 *)p)->f4))->f34);
  if(((struct Obj00601 *)p)->f84==0) {
   if(MANUAL_COMMON_GetTouchbarPressed(*(char * *)&((struct Obj26181 *)(*(char * *)&((struct Obj00601 *)p)->f4))->f34)!=(unsigned)-1) ((struct Obj00601 *)p)->f84=3;
  } else {
   selected=MANUAL_COMMON_GetTouchbarSelected(*(char * *)&((struct Obj26182 *)(*(char * *)&((struct Obj00601 *)p)->f4))->f34);
   if(selected!=(unsigned)-1) {
    if(selected==1) ((struct Obj26183 *)(*(char * *)&((struct Obj00601 *)p)->f0))->f10=0;
    ((struct Obj00601 *)p)->f84=1;
    ((struct Obj00601 *)p)->f90=1;
   }
  }
 }
 if(((struct Obj00601 *)p)->f84==0 || ((struct Obj00601 *)p)->f84==4) {
  if(((struct Obj00601 *)p)->f84==0) {
   if(MANUAL_COMMON_UpdateListWorkInput(p)) ((struct Obj00601 *)p)->f84=4;
  } else {
   if(APP_TASKMENU_WIN_IsFinish(*(u8 **)(p+MANUAL_COMMON_GetCursorIndex((u16 **)p)*4+0xc))) {
    ((struct Obj26184 *)(*(char * *)&((struct Obj00601 *)p)->f0))->f10=1;
    ((struct Obj00601 *)p)->f84=1;
    ((struct Obj00601 *)p)->f90=1;
   }
  }
 }
 return result;
}

void MANUAL_COMMON_ListWorkTaskNoop(void) {}
