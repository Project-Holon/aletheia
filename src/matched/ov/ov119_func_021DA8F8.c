/*
 * function: func_021DA8F8
 * address: 0x021DA8F8
 * packet: pkt_ov119_021DA8F8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021DD1B8 0x021DD1B8 thumb ov119
 *   func_021DF904 0x021DF904 thumb ov119
 *   DWC_RAP_SetVchatTalkLock 0x0215642C thumb ov009
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021DD528 0x021DD528 thumb ov119
 *   func_021DD68C 0x021DD68C thumb ov119
 *   func_021DF78C 0x021DF78C thumb ov119
 *   func_021DF7AC 0x021DF7AC thumb ov119
 *   func_02082BCC 0x02082BCC arm
 *   func_021D8C84 0x021D8C84 thumb ov119
 *   func_02027858 0x02027858 thumb
 *   func_021E4420 0x021E4420 thumb ov119
 *   func_021E6700 0x021E6700 thumb ov119
 *   func_021DBB6C 0x021DBB6C thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DA898 0x021DA898 thumb ov119
 *   func_021DB7AC 0x021DB7AC thumb ov119
 */
#include "../include/Obj03773.h"
typedef unsigned char u8;
struct Entry;
struct Link;
extern struct Entry *func_020399A8(void);
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
extern int func_021D8A24(void *),func_021D8AA8(void *);
typedef unsigned int   u32;
struct MsgBank;
struct TaskMenu;
extern void func_021E1098(char *);
extern void func_021DD1B8(char *);
extern void func_021DF904(void *);
extern void DWC_RAP_SetVchatTalkLock(int);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E1024(void *);
extern void func_021DD528(char *,int);
extern void func_021DD68C(char *p);
extern void func_021DF78C(void *);
extern void func_021DF7AC(void *,int);
extern void func_02082BCC(void *,int,int);
extern void func_021D8C84(void *);
extern void func_02027858(struct TaskMenu *m);
extern void func_021E4420(char *p);
extern void func_021E6700(void *);
extern void func_021DBB6C(char *);
extern void func_021D8E84(void *,int);
extern void func_021DA898(char *);
extern void func_021DB7AC(char *,int,int);
void func_021DA8F8(char *p)
{
 if(func_021D8A24(p) && !func_02039CB4((struct Link *)func_020399A8(),18,8)) return;
 func_021E1098(p);
 if(func_021D8AA8(p)) {
  func_021DD1B8(p);func_021DF904(p);
  if(((struct Obj03773 *)p)->f118C==2) DWC_RAP_SetVchatTalkLock(0);
  func_02045CAC((struct MsgBank *)(((struct Obj03773 *)p)->f720),134,(void *)(((struct Obj03773 *)p)->f738));func_021E1024(p);
  func_021DD528(p,0);func_021DD68C(p);
  ((struct Obj03773 *)p)->f11E8=0;((struct Obj03773 *)p)->f11E9=0;
  func_021DF78C(p);func_021DF7AC(p,1);
  func_02082BCC(p+0xca0,0,0x78);func_02082BCC(p+0xd18,0,0x3c);func_02082BCC(p+0xd54,0,0x3c);
  func_021D8C84(p);
  if(((struct Obj03773 *)p)->f64C) {func_02027858((struct TaskMenu *)(((struct Obj03773 *)p)->f64C));((struct Obj03773 *)p)->f64C=0;}
  func_021E4420(p);func_021E6700(p);func_021DBB6C(p);
 }
 func_021D8E84(p,(int)func_021DA898);func_021DB7AC(p,0,1);
}
