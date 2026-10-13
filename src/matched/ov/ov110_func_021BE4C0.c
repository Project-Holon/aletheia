/*
 * function: PMS_INPUT_HandleBrowse
 * address: 0x021BE4C0
 * packet: pkt_ov110_021BE4C0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_VIEW_IsTaskNotRunning 0x021B9C90 thumb ov110
 *   PMS_INPUT_VIEW_IsIdle 0x021B9C74 thumb ov110
 *   PMS_INPUT_VIEW_StartTask 0x021B9BEC thumb ov110
 *   PMS_INPUT_HandleBrowseInput 0x021BEADC thumb ov110
 *   PMS_INPUT_SetHandler 0x021BD7A0 thumb ov110
 *   PMS_INPUT_HandleMenu 0x021BD894 thumb ov110
 */
#include "../include/Obj00012.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef int (*Handler)(u8 *,void *);
extern int PMS_INPUT_VIEW_IsTaskNotRunning(unsigned int a, int b);
extern int PMS_INPUT_VIEW_IsIdle(unsigned int a);
extern void PMS_INPUT_VIEW_StartTask(u8 *,int);
extern void PMS_INPUT_HandleBrowseInput(u8 *p, void *q);
extern void PMS_INPUT_SetHandler(u8 *,Handler);
extern int PMS_INPUT_HandleMenu(u8 *,void *);
int PMS_INPUT_HandleBrowse(u8 *p,unsigned *q) {
 switch(*q) {
 case 0:
  if(PMS_INPUT_VIEW_IsTaskNotRunning((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14),18) && PMS_INPUT_VIEW_IsTaskNotRunning((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14),33) && PMS_INPUT_VIEW_IsTaskNotRunning((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14),32)) PMS_INPUT_HandleBrowseInput(p,q);
  break;
 case 1:
  if(PMS_INPUT_VIEW_IsTaskNotRunning((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14),32)) {
   if(((struct Obj00012 *)p)->f50!=253) { ((struct Obj00012 *)p)->f4C=((struct Obj00012 *)p)->f50; PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00012 *)p)->f14,18); }
   *q=0;
  }
  break;
 case 2:
  if(PMS_INPUT_VIEW_IsIdle((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) { if(*(Handler *)&((struct Obj00012 *)p)->f28==PMS_INPUT_HandleMenu) PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00012 *)p)->f14,4); *q=3; }
  break;
 case 3:
  if(PMS_INPUT_VIEW_IsIdle((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) PMS_INPUT_SetHandler(p,*(Handler *)&((struct Obj00012 *)p)->f28);
  break;
 case 4:
  if(PMS_INPUT_VIEW_IsTaskNotRunning((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14),25)) *q=0;
  break;
 }
 return 0;
}
