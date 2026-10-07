/*
 * file:     br_proc_sys_p05.c
 * unit:     yes
 * function: func_021F9A80, func_021F9B98
 * address:  0x021F9A80
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034714 0x02034714 arm
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 *   func_02031348 0x02031348 arm
 *   func_02031330 0x02031330 arm
 *   d_02200D04 0x02200D04 data a1
 *   d_02200D14 0x02200D14 data a1
 */
#include "../../matched/include/Obj01569.h"

typedef unsigned short u16;

typedef unsigned u32;

struct Ops {u32 id,size,fn;void (*init)(void *,u32,void *,int);void (*update)(void *,u32);};

struct Slot {u32 active;void *work;const struct Ops *ops;int arg;};

extern void func_02034714(const char *,u32,const char *);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02082BCC(void *,int,u32);
extern u32 func_020307B0(void *p);
extern void func_02031348(u32,u32,u32,void *);
extern u32 func_02031330(void *);
void func_021F9A80(char *p);
int func_021F9B98(int *p);
extern const char d_02200D04[],d_02200D14[];

/*
 * tail: existing matched accessor followers 021F9B98 and 021F9B9C; lead only.
 */
void func_021F9A80(char *p)
{
 struct Slot *current,*old,*next;
 current=(struct Slot *)(p+0x2c);
 old=(struct Slot *)(p+0x1c);
 next=(struct Slot *)(p+0x3c);
 switch(((struct Obj01569 *)p)->f18){
 case 0:*old=*current;*current=*next;((struct Obj01569 *)p)->f18=1;break;
 case 1:{
  int mode;
  if(!current->active)func_02034714(d_02200D14,0,d_02200D14);
  if(!current->ops->init)func_02034714(d_02200D14,0,d_02200D14);
  current->work=func_02030734(((struct Obj01569 *)p)->f10,current->ops->size,0,d_02200D04,0xd2);
  func_02082BCC(current->work,0,current->ops->size);
  mode=-2;if(!((struct Obj01569 *)p)->f6C)mode=old->arg;
  current->ops->init(current->work,((struct Obj01569 *)p)->fC,old->work,mode);
  ((struct Obj01569 *)p)->f6C=0;
  if(old->work)func_020307B0(old->work);
  func_02031348(*(u32 *)&((struct Obj01569 *)p)->f0,current->ops->fn,current->ops->id,current->work);
  ((struct Obj01569 *)p)->f18=2;break;
 }
 case 2:if(!func_02031330(((struct Obj01569 *)p)->f0))((struct Obj01569 *)p)->f18=3;break;
 case 3:
  if(!current->active)func_02034714(d_02200D14,0,d_02200D14);
  if(current->ops->update)current->ops->update(current->work,((struct Obj01569 *)p)->fC);
  if(((struct Obj01569 *)p)->f64)((struct Obj01569 *)p)->f18=0;
  else{if(current->work)func_020307B0(current->work);((struct Obj01569 *)p)->f18=4;}
  break;
 case 4:((struct Obj01569 *)p)->f14=1;break;
 }
}

/*
 * Follower021F9B9C has its existing matched source/shard; no unit.
 */
int func_021F9B98(int *p)
{
    return p[5];
}
