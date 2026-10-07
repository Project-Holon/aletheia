/*
 * file:     unit_021B7560_p04.c
 * unit:     yes
 * function: func_021B8348, func_021B83E0
 * address:  0x021B8348
 * region:   ov105
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021B78C8 0x021B78C8 thumb ov105
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021B8440 0x021B8440 thumb ov105
 */
struct Obj;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

typedef struct {u32 objects[3]; u16 current[3]; u16 bound[3]; int step[3]; u8 pad[12]; u8 digits[3];u8 pad1;int state[3];} Display_021B8348;

typedef struct {s16 x,y;} Pair;

typedef struct { u32 objects[3]; u8 pad[0x24]; u8 digits[3]; u8 pad1; int state[3]; } Display_021B83E0;

extern void func_02082BCC(void *,int,int);
extern u32 func_021B78C8(u8 *p, int i);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B3DC(struct Obj *,unsigned int);
extern void func_021B8440(Display_021B8348 *,unsigned);
void func_021B8348(Display_021B8348 *p,void *a,int n);
void func_021B83E0(Display_021B83E0 *p, int i);

void func_021B8348(Display_021B8348 *p,void *a,int n)
{
 int i; Pair pos;
 func_02082BCC(p,0,64);
 for(i=0;i<3;i++) {
  p->objects[i]=func_021B78C8(a,i);
  if(n<100) pos.x=74+i*36;
  else if(n>=0 && n<10) pos.x=56+i*36;
  else pos.x=92+i*36;
  pos.y=84;
  func_0204B404((struct Obj *)p->objects[i],(const struct Vec2 *)(&pos),0);
  func_0204B3DC((struct Obj *)p->objects[i],0);
  p->current[i]=0;p->bound[i]=60;
  p->step[i]=4079/p->bound[i];
 }
 func_021B8440(p,n);
}

void func_021B83E0(Display_021B83E0 *p, int i)
{
    if (p->state[i] == 0) {
        if (i == 0 && p->digits[2 - i] == 0) {
            p->state[i] = 1;
            return;
        }
        if (i == 0 && p->digits[2 - i] == 0 && i == 1 && p->digits[2 - i] == 0) {
            p->state[i] = 1;
            return;
        }
        p->state[i] = 1;
        func_0204B3DC((struct Obj *)p->objects[i], 1);
    }
}
