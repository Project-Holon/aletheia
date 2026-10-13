/*
 * function: func_021B95A0
 * address: 0x021B95A0
 * packet: pkt_ov224_021B95A0
 * region: ov224
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 func_02043588 is defined in src/matched/arm9/unit_02043570.c
 *   but omitted from its function: header; the integrator owns this unit.
 * blocker: verified EXACT 16-byte ARM C copied from
 *   src/pending/ov/ov133_func_021B69AC.c after the caller's MATCH verdict:
 *   extern void func_02043558(void),func_02043570(void);
 *   void func_02043588(void) { func_02043558(); func_02043570(); }
 * tu: MATCH 376 bytes, 29/30 relocations; --suggest-split has no viable partition.
 * lever: non-const resource table retains original outgoing stack-store order.
 * volatile: display control rereads 021B961C-021B962C.
 * arity: 0203159C retains consumed r0 allocation despite own void declaration.
 * arity: BG callees narrow bytes explicitly before each call.
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204047C 0x0204047C arm
 *   func_02043588 0x02043588 arm
 *   func_0207D518 0x0207D518 arm
 *   func_02043558 0x02043558 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_02043598 0x02043598 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204E720 0x0204E720 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_021B9940 0x021B9940 thumb ov224
 *   func_021B9820 0x021B9820 thumb ov224
 *   func_021B9824 0x021B9824 thumb ov224
 *   d_021B9C04 0x021B9C04 data a4
 *   d_021B9D40 0x021B9D40 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { ZERO=0,ONE=1 } Index;
typedef enum { MODE=2 } Mode;
struct BgTemplate {u32 words[8];};
struct Entry { u32 id; struct BgTemplate bg; u32 kind,visible; };
struct Assets {u32 palette,screen,chars;};
struct Work {u16 heap,pad2; void **args; void *screen,*font;u32 string;void *task;};
struct GfFont; struct Obj0203159C;
extern const struct Entry d_021B9C04[];
extern struct Assets d_021B9D40[];
extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *,u32,u32);
extern void func_02082BCC(void *,u32,u32);
extern void *func_021B9940(u32,u32);
extern struct GfFont *func_0201D7EC(int,int,int,int,u32);
extern u32 func_0201C440(void *);
extern void func_0204047C(int,u16);
extern void *func_020056A0(u32,u32,u32);
extern void func_021B9820(void);
extern void func_021B9824(u16 *);
extern void func_02043588(void);
extern void func_0207D518(u32);
extern void func_02043558(void);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern void func_02043598(u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_02049238(void *);
extern void func_020409B4(u32);
extern void func_0204E720(u32,int,int,int);
extern void func_0203D34C(u32,u32);
static inline void SetMode(Mode mode) {
 *(volatile u32 *)0x04001000 &= 0xffff1fff;
 *(volatile u32 *)0x04001000 |= mode<<15;
}
int func_021B95A0(struct Obj0203159C *proc,void *unused,void **args)
{
 struct Work *p;
 Index i;
 const struct Entry *row;
 u32 id,choice;
 u16 heap;
 void *arc;
 func_0203064C((u32)((void *)1),0x88,0x30000);
 p=func_0203159C(proc,0x18,0x88);
 func_02082BCC(p,0,0x18);
 p->heap=0x88; p->args=args;
 p->screen=func_021B9940(1,p->heap);
 p->font=func_0201D7EC(23,0,0,0,p->heap);
 p->string=func_0201C440((void *)(u32)p->heap);
 func_0204047C(1,1); func_0204047C(2,0);
 p->task=func_020056A0((u32)func_021B9820,(u32)p,1);
 func_021B9824((u16 *)p);
 i=ZERO;
 *(volatile u16 *)0x04001050=0;
 SetMode(MODE);
 func_02043588();
 func_0207D518(0);
 func_02043558();
 do {
  row=&d_021B9C04[i]; id=row->id;
  func_0203FCA0((u8)id,&row->bg,(u8)row->kind);
  func_020414AC(id);
  func_02040588(id,row->visible);
  i++;
 }while(i<1U);
 func_02043598(16,1);
 heap=p->heap;
 choice=1;
 if(*((u8 *)*p->args+0x1d)!=1) choice=0;
 arc=func_020490F4(30,heap);
 func_02049B68(arc,d_021B9D40[choice].palette,4,0,0,heap);
 func_02049658(arc,d_021B9D40[choice].screen,4,0,0,0,heap);
 func_020498F4(arc,d_021B9D40[choice].chars,4,0,0,0,heap);
 func_02049238(arc);
 func_020409B4(4);
 func_0204E720(3,16,0,0);
 func_0203D34C(0,p->heap);
 return 1;
}
