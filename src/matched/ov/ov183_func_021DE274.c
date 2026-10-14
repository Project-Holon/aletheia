/*
 * function: func_021DE274
 * address: 0x021DE274
 * packet: pkt_ov183_021DE274
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DE940 0x021DE940 thumb ov183
 *   func_021DE780 0x021DE780 thumb ov183
 *   func_021DE404 0x021DE404 thumb ov183
 *   func_021DE55C 0x021DE55C thumb ov183
 *   func_021DE66C 0x021DE66C thumb ov183
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 */
#include "../include/Obj00440.h"
#include "../include/Obj00785.h"
typedef unsigned int u32;
struct Pair { int x,y; };
extern void BR_FADE_Start(int,int,int,int);
extern int BR_FADE_GetResult(int *);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int func_021DE940(char *,int,int);
extern int func_021FB4B4(unsigned int *obj, int x, int y);
extern void func_021FD860(int,int,struct Pair *);
extern void func_021DE780(char *,char *),func_021DE404(char *,char *),func_021DE55C(char *,char *),func_021DE66C(char *,char *);
typedef unsigned char  u8;
struct PrintSys;
extern void func_021F9BA0(unsigned *ctx);
extern int func_021FC830(u8 *p);
extern void func_021FD854(char *p);
extern void func_021FD1BC(void *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
int func_021DE274(void *unused,u32 *state,char *q,char *p)
{
 int x,y,i;
 struct Pair pair;
 switch(*state){
 case 0:BR_FADE_Start(*(int *)&((struct Obj00440 *)q)->f4,2,3,0);*state=1;break;
 case 1:if(BR_FADE_GetResult(*(int * *)&((struct Obj00440 *)q)->f4)) *state=2;break;
 case 2:
  if(TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))){
   ((struct Obj00785 *)p)->f68=func_021DE940(p,x,y);
   if(((struct Obj00785 *)p)->f68) *state=3;
   if(func_021FB4B4((unsigned int *)(((struct Obj00785 *)p)->fC),x,y)){
    pair.x=x;pair.y=y;
    func_021FD860(*(int *)&((struct Obj00785 *)p)->f64,1,&pair);
    *state=7;
   }
  }break;
 case 3:BR_FADE_Start(*(int *)&((struct Obj00440 *)q)->f4,2,1,1);++*state;break;
 case 4:if(BR_FADE_GetResult(*(int * *)&((struct Obj00440 *)q)->f4)) ++*state;break;
 case 5:
  func_021DE780(p,q);
  switch(*(u32 *)&((struct Obj00785 *)p)->f68){
  case 1:func_021DE404(p,q);break;
  case 2:func_021DE55C(p,q);break;
  case 3:func_021DE66C(p,q);break;
  }
  BR_FADE_Start(*(int *)&((struct Obj00440 *)q)->f4,2,1,0);++*state;break;
 case 6:if(BR_FADE_GetResult(*(int * *)&((struct Obj00440 *)q)->f4)) *state=2;break;
 case 7:BR_FADE_Start(*(int *)&((struct Obj00440 *)q)->f4,2,3,1);*state=8;break;
 case 8:if(BR_FADE_GetResult(*(int * *)&((struct Obj00440 *)q)->f4)) *state=9;break;
 case 9:func_021F9BA0(((struct Obj00440 *)q)->fC);return 1;
 }
 for(i=0;i<3;i++) if(*(void **)(p+i*4+0x10)) func_021FC830(*(void **)(p+i*4+0x10));
 for(i=0;i<18;i++) if(*(void **)(p+i*4+0x1c)) func_021FC830(*(void **)(p+i*4+0x1c));
 PRINTSYS_QUE_Main(((struct Obj00785 *)p)->f4);
 func_021FD854(((struct Obj00785 *)p)->f64);
 if(((struct Obj00785 *)p)->f8)func_021FD1BC(((struct Obj00785 *)p)->f8);
 return 0;
}
