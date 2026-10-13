/*
 * function: IRC_RESULT_InitScoreDisplay
 * address: 0x021B8348
 * packet: pkt_ov105_021B8348
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   IRC_RESULT_GetScreenActor 0x021B78C8 thumb ov105
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   IRC_RESULT_SetScoreDigits 0x021B8440 thumb ov105
 */
typedef unsigned char u8; typedef unsigned short u16; typedef short s16; typedef unsigned int u32;
typedef struct {u32 objects[3]; u16 current[3]; u16 bound[3]; int step[3]; u8 pad[12]; u8 digits[3];u8 pad1;int state[3];} Display;
typedef struct {s16 x,y;} Pair;
extern void MI_CpuFill8(void *,int,int);
extern u32 IRC_RESULT_GetScreenActor(u8 *p, int i);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
extern void IRC_RESULT_SetScoreDigits(Display *,unsigned);
void IRC_RESULT_InitScoreDisplay(Display *p,void *a,int n)
{
 int i; Pair pos;
 MI_CpuFill8(p,0,64);
 for(i=0;i<3;i++) {
  p->objects[i]=IRC_RESULT_GetScreenActor(a,i);
  if(n<100) pos.x=74+i*36;
  else if(n>=0 && n<10) pos.x=56+i*36;
  else pos.x=92+i*36;
  pos.y=84;
  CLACT_AddActorSurfacePos((struct Obj *)p->objects[i],(const struct Vec2 *)(&pos),0);
  CLACT_SetActorDrawEnable((struct Obj *)p->objects[i],0);
  p->current[i]=0;p->bound[i]=60;
  p->step[i]=4079/p->bound[i];
 }
 IRC_RESULT_SetScoreDigits(p,n);
}
