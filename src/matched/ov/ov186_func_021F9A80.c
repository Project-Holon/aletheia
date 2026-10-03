/*
 * function: func_021F9A80
 * address: 0x021F9A80
 * packet: pkt_ov186_021F9A80
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * tail: existing matched accessor followers 021F9B98 and 021F9B9C; lead only.
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
typedef unsigned short u16;
typedef unsigned u32;
struct Ops {u32 id,size,fn;void (*init)(void *,u32,void *,int);void (*update)(void *,u32);};
struct Slot {u32 active;void *work;const struct Ops *ops;int arg;};
extern const char d_02200D04[],d_02200D14[];
extern void func_02034714(const char *,u32,const char *);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02082BCC(void *,int,u32),func_020307B0(void *);
extern void func_02031348(u32,u32,u32,void *);
extern u32 func_02031330(void *);
void func_021F9A80(char *p)
{
 struct Slot *current,*old,*next;
 current=(struct Slot *)(p+0x2c);
 old=(struct Slot *)(p+0x1c);
 next=(struct Slot *)(p+0x3c);
 switch(*(u32 *)(p+0x18)){
 case 0:*old=*current;*current=*next;*(u32 *)(p+0x18)=1;break;
 case 1:{
  int mode;
  if(!current->active)func_02034714(d_02200D14,0,d_02200D14);
  if(!current->ops->init)func_02034714(d_02200D14,0,d_02200D14);
  current->work=func_02030734(*(u16 *)(p+0x10),current->ops->size,0,d_02200D04,0xd2);
  func_02082BCC(current->work,0,current->ops->size);
  mode=-2;if(!*(u32 *)(p+0x6c))mode=old->arg;
  current->ops->init(current->work,*(u32 *)(p+0xc),old->work,mode);
  *(u32 *)(p+0x6c)=0;
  if(old->work)func_020307B0(old->work);
  func_02031348(*(u32 *)p,current->ops->fn,current->ops->id,current->work);
  *(u32 *)(p+0x18)=2;break;
 }
 case 2:if(!func_02031330(*(void **)p))*(u32 *)(p+0x18)=3;break;
 case 3:
  if(!current->active)func_02034714(d_02200D14,0,d_02200D14);
  if(current->ops->update)current->ops->update(current->work,*(u32 *)(p+0xc));
  if(*(u32 *)(p+0x64))*(u32 *)(p+0x18)=0;
  else{if(current->work)func_020307B0(current->work);*(u32 *)(p+0x18)=4;}
  break;
 case 4:*(u32 *)(p+0x14)=1;break;
 }
}
