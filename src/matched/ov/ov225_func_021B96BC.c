/*
 * function: func_021B96BC
 * address: 0x021B96BC
 * packet: pkt_ov225_021B96BC
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * lever: repeat shared constructor/store tails in their arms and keep done as int; enum done adds truncation pairs (584B/404 concrete).
 * trailing: separately matched callback021B98FC (2B) and two alignment bytes at021B98FE; lead576B.
 * attempts: four one calls in final retry; direct-goto enum baseline DIFF66/576, repeated tails enum DIFF404/584, wide store casts unchanged, repeated tails int EXACT*576.
 * symbols:
 *   func_0204E804 0x0204E804 arm
 *   func_0204E720 0x0204E720 arm
 *   func_021BB31C 0x021BB31C thumb ov225
 *   func_021BB308 0x021BB308 thumb ov225
 *   func_021BB6E0 0x021BB6E0 thumb ov225
 *   func_021BB844 0x021BB844 thumb ov225
 *   func_021BB7F4 0x021BB7F4 thumb ov225
 *   func_021BB2B4 0x021BB2B4 thumb ov225
 *   func_021BBA64 0x021BBA64 thumb ov225
 *   func_021BBA14 0x021BBA14 thumb ov225
 *   func_021B9BEC 0x021B9BEC thumb ov225
 *   func_021B9BE0 0x021B9BE0 thumb ov225
 *   func_021B9C98 0x021B9C98 thumb ov225
 *   func_021B9CB0 0x021B9CB0 thumb ov225
 *   func_021B9BC8 0x021B9BC8 thumb ov225
 *   func_021B9C0C 0x021B9C0C thumb ov225
 *   func_021B9CC8 0x021B9CC8 thumb ov225
 *   func_021B9BF8 0x021B9BF8 thumb ov225
 *   func_021BBA74 0x021BBA74 thumb ov225
 *   func_021BBB0C 0x021BBB0C thumb ov225
 *   func_021BBAE8 0x021BBAE8 thumb ov225
 *   func_021BB854 0x021BB854 thumb ov225
 *   func_021B9E60 0x021B9E60 thumb ov225
 */
#include "../include/Obj00100.h"
#include "../include/Obj26116.h"
#include "../include/Obj26117.h"
#include "../include/Obj26118.h"
#include "../include/Obj26119.h"
#include "../include/Obj26120.h"
#include "../include/Obj26122.h"
#include "../include/Obj26124.h"
#include "../include/Obj26125.h"
#include "../include/Obj26126.h"
#include "../include/Obj26127.h"
#include "../include/Obj26128.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum {ZERO=0,ONE=1} Flag;
extern int func_0204E804(void);
extern void func_0204E720(u32,int,int,int);
extern int func_021BB31C(char *);
extern void func_021BB308(char *);
extern char *func_021BB6E0(char *,char *);
extern int func_021BB844(char *);
extern void func_021BB7F4(char *);
extern char *func_021BB2B4(char *,char *);
extern int func_021BBA64(char *);
extern void func_021BBA14(char *);
extern u16 func_021B9BEC(char *,int);
extern u16 func_021B9BE0(char *,int);
extern int func_021B9C98(void *,int,int);
struct Big;
extern void func_021B9CB0(void *unused, int code, struct Big *save);
extern u16 func_021B9BC8(char *,int);
extern u16 func_021B9C0C(char *,int,int);
extern int func_021B9CC8(unsigned unused, unsigned key);
extern u16 func_021B9BF8(char *,int,int);
extern char *func_021BBA74(char *,char *);
extern int func_021BBB0C(char *);
extern void func_021BBAE8(char *p);
extern char *func_021BB854(char *,char *);
extern void func_021B9E60(char *);
int func_021B96BC(void *a,u32 *state,void *unused,char *p)
{
 int done;
 u32 count;
 u16 id,i,item,selected;
 switch(*state) {
 case 0: *state=1; break;
 case 1: if(!func_0204E804()) *state=2; break;
 case 2:
  done=0;
  switch(((struct Obj00100 *)p)->f10) {
  case 0:
   if(!func_021BB31C(*(char * *)&((struct Obj00100 *)p)->f1C)) goto innerDone;
   {
    if(((struct Obj00100 *)p)->f18<=1) {
     if(((struct Obj00100 *)p)->f18==0) ((struct Obj26116 *)(*(char * *)&((struct Obj00100 *)p)->f4))->f4=0;
     else if(((struct Obj00100 *)p)->f18==1) ((struct Obj26117 *)(*(char * *)&((struct Obj00100 *)p)->f4))->f4=1;
     done=1;
    } else {
     func_021BB308(*(char * *)&((struct Obj00100 *)p)->f1C);
     if(((struct Obj00100 *)p)->f18==2) {
      ((struct Obj00100 *)p)->f10=1;
      ((struct Obj00100 *)p)->f20=0; ((struct Obj00100 *)p)->f22=0;
      *(char * *)&((struct Obj00100 *)p)->f2C=func_021BB6E0(p+0x20,*(char * *)&((struct Obj00100 *)p)->f8);
     } else if(((struct Obj00100 *)p)->f18==3) {
      ((struct Obj00100 *)p)->f10=2; ((struct Obj00100 *)p)->f30=1;
      ((struct Obj00100 *)p)->f34=done;
      ((struct Obj00100 *)p)->f36=done; ((struct Obj00100 *)p)->f38=done;
      *(char * *)&((struct Obj00100 *)p)->f44=func_021BB854(p+0x30,*(char * *)&((struct Obj00100 *)p)->f8);
     }
    }
   }
   break;
  case 1:
   if(!func_021BB844(*(char * *)&((struct Obj00100 *)p)->f2C)) {
   default:
innerDone:
    break;
   } else {
    func_021BB7F4(*(char * *)&((struct Obj00100 *)p)->f2C);
    if(((struct Obj00100 *)p)->f24==0) {
     ((struct Obj00100 *)p)->f10=done;
     *(char * *)&((struct Obj00100 *)p)->f1C=func_021BB2B4(p+0x14,*(char * *)&((struct Obj00100 *)p)->f8);
    } else {
     ((struct Obj00100 *)p)->f10=2; ((struct Obj00100 *)p)->f30=0;
     ((struct Obj00100 *)p)->f34=((struct Obj00100 *)p)->f28;
     ((struct Obj00100 *)p)->f36=done; ((struct Obj00100 *)p)->f38=done;
     *(char * *)&((struct Obj00100 *)p)->f44=func_021BB854(p+0x30,*(char * *)&((struct Obj00100 *)p)->f8);
    }
   }
   break;
  case 2:
   if(func_021BBA64(*(char * *)&((struct Obj00100 *)p)->f44)) {
    func_021BBA14(*(char * *)&((struct Obj00100 *)p)->f44);
    if(((struct Obj00100 *)p)->f3C==0) {
     if(((struct Obj00100 *)p)->f30==0) { ((struct Obj00100 *)p)->f10=1; *(char * *)&((struct Obj00100 *)p)->f2C=func_021BB6E0(p+0x20,*(char * *)&((struct Obj00100 *)p)->f8); }
     else if(((struct Obj00100 *)p)->f30==1) { ((struct Obj00100 *)p)->f10=done; *(char * *)&((struct Obj00100 *)p)->f1C=func_021BB2B4(p+0x14,*(char * *)&((struct Obj00100 *)p)->f8); }
    } else {
     ((struct Obj00100 *)p)->f10=3;
     id=((struct Obj00100 *)p)->f40;
     count=func_021B9BEC(*(char * *)&((struct Obj26118 *)(*(char * *)&((struct Obj00100 *)p)->f8))->f2C,id);
     selected=func_021B9BE0(*(char * *)&((struct Obj26119 *)(*(char * *)&((struct Obj00100 *)p)->f8))->f2C,id);
     if(!func_021B9C98(*(char * *)&((struct Obj26120 *)(*(char * *)&((struct Obj00100 *)p)->f8))->f2C,selected,**(int * *)&((struct Obj00100 *)p)->f8))
      func_021B9CB0(*(char * *)&((struct Obj26122 *)(*(char * *)&((struct Obj00100 *)p)->f8))->f2C,selected,(struct Big *)(**(int * *)&((struct Obj00100 *)p)->f8));
     ((struct Obj00100 *)p)->f4A=func_021B9BC8(*(char * *)&((struct Obj26124 *)(*(char * *)&((struct Obj00100 *)p)->f8))->f2C,id);
     ((struct Obj00100 *)p)->f48=func_021B9BEC(*(char * *)&((struct Obj26125 *)(*(char * *)&((struct Obj00100 *)p)->f8))->f2C,id);
     for(i=0;i<count;i++) {
      item=func_021B9C0C(*(char * *)&((struct Obj26126 *)(*(char * *)&((struct Obj00100 *)p)->f8))->f2C,id,i);
      if(!func_021B9CC8((unsigned int)(*(char * *)&((struct Obj26127 *)(*(char * *)&((struct Obj00100 *)p)->f8))->f2C),item)) item=65535;
      *(u16 *)(p+i*4+0x4c)=item;
      *(u16 *)(p+i*4+0x4e)=func_021B9BF8(*(char * *)&((struct Obj26128 *)(*(char * *)&((struct Obj00100 *)p)->f8))->f2C,id,i);
     }
     *(char * *)&((struct Obj00100 *)p)->f74=func_021BBA74(p+0x48,*(char * *)&((struct Obj00100 *)p)->f8);
    }
   }
   break;
  case 3:
   if(func_021BBB0C(*(char * *)&((struct Obj00100 *)p)->f74)) {
    func_021BBAE8(((struct Obj00100 *)p)->f74);
    if(((struct Obj00100 *)p)->f70==0) {
     ((struct Obj00100 *)p)->f10=2;
     *(char * *)&((struct Obj00100 *)p)->f44=func_021BB854(p+0x30,*(char * *)&((struct Obj00100 *)p)->f8);
    }
   }
   break;
  }
  if(done) { *state=3; func_0204E720(3,0,16,0); }
  break;
 case 3: if(!func_0204E804()) *state=4; break;
 case 4: return 1;
 }
 func_021B9E60(*(char * *)&((struct Obj00100 *)p)->f8);
 return 0;
}
