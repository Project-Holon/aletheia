/*
 * function: func_021B8348
 * address: 0x021B8348
 * packet: pkt_ov105_021B8348
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021B78C8 0x021B78C8 thumb ov105
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021B8440 0x021B8440 thumb ov105
 */
typedef unsigned char u8; typedef unsigned short u16; typedef short s16; typedef unsigned int u32;
typedef struct {u32 objects[3]; u16 current[3]; u16 bound[3]; int step[3]; u8 pad[12]; u8 digits[3];u8 pad1;int state[3];} Display;
typedef struct {s16 x,y;} Pair;
extern void func_02082BCC(void *,int,int);
extern u32 func_021B78C8(u8 *p, int i);
extern void func_0204B404(u32,Pair *,int);
struct Obj;
extern void func_0204B3DC(struct Obj *,unsigned int);
extern void func_021B8440(Display *,unsigned);
void func_021B8348(Display *p,void *a,int n)
{
 int i; Pair pos;
 func_02082BCC(p,0,64);
 for(i=0;i<3;i++) {
  p->objects[i]=func_021B78C8(a,i);
  if(n<100) pos.x=74+i*36;
  else if(n>=0 && n<10) pos.x=56+i*36;
  else pos.x=92+i*36;
  pos.y=84;
  func_0204B404(p->objects[i],&pos,0);
  func_0204B3DC((struct Obj *)p->objects[i],0);
  p->current[i]=0;p->bound[i]=60;
  p->step[i]=4079/p->bound[i];
 }
 func_021B8440(p,n);
}
