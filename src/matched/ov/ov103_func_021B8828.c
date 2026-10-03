/*
 * function: func_021B8828
 * address: 0x021B8828
 * packet: pkt_ov103_021B8828
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7250 0x021B7250 thumb ov101
 *   func_021B630C 0x021B630C thumb ov101
 *   func_021B63CC 0x021B63CC thumb ov101
 *   func_021B6424 0x021B6424 thumb ov101
 *   func_021B72A0 0x021B72A0 thumb ov101
 *   func_021B6480 0x021B6480 thumb ov101
 *   func_021B8358 0x021B8358 thumb ov103
 *   func_021B8138 0x021B8138 thumb ov103
 *   func_021B8B38 0x021B8B38 thumb ov103
 *   func_021B8DE4 0x021B8DE4 thumb ov103
 *   func_021B8BC0 0x021B8BC0 thumb ov103
 *   func_021B8338 0x021B8338 thumb ov103
 *   func_021B8A44 0x021B8A44 thumb ov103
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200A9D4 0x0200A9D4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {int x,y;} Pair;
typedef struct {Pair point[12];} Line;
typedef struct {Pair origin,end;Line a,b;u32 tail[2];} Block;
extern int func_021B7250(int *);
extern int func_021B630C(int *,int);
extern void func_021B63CC(int *,int);
extern int func_021B6424(int);
extern void func_021B72A0(int,int);
extern int func_021B6480(int *);
extern void func_021B8358(u8 *);
extern void func_021B8138(u8 *,void *,int,int,s16);
extern int func_021B8B38(u8 *,const Block *);
extern u8 func_021B8DE4(u8 *);
extern void func_021B8BC0(u8 *,Block *);
extern void func_021B8338(u8 *,void (*)(u8 *,u16 *));
extern void func_021B8A44(u8 *,u16 *);
struct Big;
struct Ctx;
struct T0200A9A4;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200A8A0(void *);
extern u32 func_02008530(const void *);
extern int func_0200A9D4(struct T0200A9A4 *o, u32 v);
extern void func_020061E4(u32);
#define CTX (*(u8 **)(p+0xb0c))
void func_021B8828(u8 *p,u16 *state) {
 Block ref; Block cur;
 if(*state<5 && func_021B7250(*(int **)(p+0xa38))==1) {
  *(u32 *)(CTX+12)=1; func_021B8358(p); return;
 }
 switch(*state) {
 case 0: if(func_021B630C(*(int **)(CTX+4),4)) *state=1; break;
 case 1: func_021B8138(p+0x184,p+0x174,4,0,0); *state=2; break;
 case 2:
  ref.origin=*(Pair *)(p+0xa3c);
  ref.end=*(Pair *)(p+0xa44);
  ref.a=*(Line *)(p+0xa4c);
  ref.b=*(Line *)(p+0xaac);
  ref.tail[0]=*(u32 *)(p+0x738);
  if(*(void **)CTX) {
   void *src;
   src=func_0200A8A0(func_02012EBC(func_020120F4(*(void **)CTX)));
   ref.tail[1]=func_0200A9D4(src,func_02008530(*(u8 **)(CTX+8)+12))==0;
  }
  if(func_021B8B38(p+0x75c,&ref)) *state=3; break;
 case 3:
  func_021B63CC(*(int **)(CTX+4),3);
  if(func_021B6424(*(int *)(CTX+4))) *state=4; break;
 case 4:
  if(func_021B630C(*(int **)(CTX+4),5)) {
   func_021B72A0(*(int *)(p+0xa38),0); *state=5;
  } break;
 case 5:
  if(*(u16 *)(p+0x72e)>=60) {
   func_020061E4(0x64b);func_021B8138(p+0x184,p+0x174,5,0,0);
   *(u32 *)(p+0x73c)=0; *state=6;
  } break;
 case 6:
  if((*(u32 *)(p+0x73c))++<30) return;
  CTX[0x10]=func_021B8DE4(p);
  func_021B8BC0(p+0x75c,&cur);
  CTX[0x11]=*(u32 *)(p+0x738)+cur.tail[0];
  CTX[0x12]=cur.tail[1];
  *(u32 *)(CTX+12)=0;*state=7;return;
 case 7:func_021B8358(p);return;
 }
 if(*state<3 && func_021B6480(*(int **)(CTX+4))) func_021B8338(p,func_021B8A44);
 if(*state>=1 && *state<=5) { if(*(u16 *)(p+0x72e)<=60) ++*(u16 *)(p+0x72e); }
}
