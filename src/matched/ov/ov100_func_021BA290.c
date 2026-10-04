/*
 * function: func_021BA290
 * address: 0x021BA290
 * packet: pkt_ov100_021BA290
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02027778 0x02027778 thumb
 *   func_02045808 0x02045808 arm
 *   func_02027CD8 0x02027CD8 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Template { int heap; u8 count,pad[3]; int ptr,flag; u8 x,y,z,w; };
typedef unsigned int   u32;
struct MsgBank;
struct TaskMenu;
struct TaskMenuTmpl;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_02045808(struct U16Vec *vec);
extern void func_02027CD8(int,int);
void func_021BA290(int a,int flag) {
 struct Template t;
 int v;
 t.heap=*(u16 *)(a+0x278);
 t.flag=1;
 t.x=32;t.y=24;t.z=13;t.w=3;
 if(flag!=0) {
  t.count=2;t.ptr=a+0xcc8;
  v=(int)func_020457B0(100,t.heap);*(int *)(a+0xcc8)=v;
  func_02045CAC((struct MsgBank *)(*(int *)(a+0x288)),0x23,(void *)v);
  *(u16 *)(a+0xccc)=0x39e3;*(int *)(a+0xcd0)=0;
  v=(int)func_020457B0(100,*(u16 *)(a+0x278));*(int *)(a+0xcd4)=v;
  func_02045CAC((struct MsgBank *)(*(int *)(a+0x288)),2,(void *)v);
  *(u16 *)(a+0xcd8)=0x39e3;*(int *)(a+0xcdc)=1;
  *(int *)(a+0xcc0)=(int)func_02027778((struct TaskMenuTmpl *)(&t),(void *)(*(int *)(a+0xcc4)));
  func_02045808((struct U16Vec *)(*(int *)(a+0xcc8)));func_02045808((struct U16Vec *)(*(int *)(a+0xcd4)));
  *(int *)(a+0xcbc)=0;
 } else {
  t.count=1;t.ptr=a+0xcc8;
  v=(int)func_020457B0(100,t.heap);*(int *)(a+0xcc8)=v;
  func_02045CAC((struct MsgBank *)(*(int *)(a+0x288)),2,(void *)v);
  *(u16 *)(a+0xccc)=0x39e3;*(int *)(a+0xcd0)=1;
  *(int *)(a+0xcc0)=(int)func_02027778((struct TaskMenuTmpl *)(&t),(void *)(*(int *)(a+0xcc4)));
  func_02045808((struct U16Vec *)(*(int *)(a+0xcc8)));*(int *)(a+0xcbc)=1;
 }
 switch(*(int *)(a+0x24c)) {case 9:case 10:case 11:break;default:func_02027CD8(*(int *)(a+0xcc0),1);break;}
}
