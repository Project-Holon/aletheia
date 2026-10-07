/*
 * file:     unit_021B95A0_p01.c
 * unit:     yes
 * function: func_021B95A0, func_021B96C0, func_021B9740, func_021B9794, func_021B9830, func_021B9858, func_021B9864
 * address:  0x021B95A0
 * region:   ov213
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   complete 0x0204E804 arm
 *   overlayLoad 0x02034AC4 arm
 *   heapCreate 0x0203064C arm
 *   create 0x0203159C arm
 *   clear 0x02082BCC arm
 *   initialize 0x021BAA20 thumb ov213
 *   video 0x021BAB64 thumb ov213
 *   font 0x0201D7EC thumb
 *   messages 0x02045B38 arm
 *   text 0x0201C440 thumb
 *   modeFor 0x021B9E28 thumb ov213
 *   dispatch 0x021B6100 thumb ov067
 *   callbacks 0x021BB02C data ov213 a4
 *   graphics 0x021B9794 thumb ov213
 *   menu 0x021BA780 thumb ov213
 *   cursor 0x021BA6C8 thumb ov213
 *   music 0x0203D34C arm
 *   fade 0x0204E720 arm
 *   ov067_id 0x00000043 data a1
 *   func_02041EE4 0x02041EE4 arm
 *   func_021BA514 0x021BA514 thumb ov213
 *   func_021B613C 0x021B613C thumb ov067
 *   func_02045C04 0x02045C04 arm
 *   sub_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_021BA710 0x021BA710 thumb ov213
 *   func_021BA7B8 0x021BA7B8 thumb ov213
 *   func_021BAC0C 0x021BAC0C thumb ov213
 *   sub_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   sub_02034A5C 0x02034A5C arm
 *   overlay_id 0x00000043 data a1
 *   func_021BA7D0 0x021BA7D0 thumb ov213
 *   func_021B6144 0x021B6144 thumb ov067
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021BAC68 0x021BAC68 thumb ov213
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   d_021BAF14 0x021BAF14 data a4
 *   func_021BA408 0x021BA408 thumb ov213
 *   func_021BA624 0x021BA624 thumb ov213
 *   func_021B61F8 0x021B61F8 thumb ov067
 *   func_021BA38C 0x021BA38C thumb ov213
 *   func_021BA920 0x021BA920 thumb ov213
 */
#include "../../matched/include/Obj06704.h"

struct Rec;
struct PrintSys;
struct S020315D4;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Args { u8 pad[0x40]; u32 a40,a44,a48,a4C,a50; };

struct Obj { u16 heap,pad2; struct Args *args; u8 pad8[0x49B4-8]; void *video,*font,*text,*messages,*dispatch; u8 mode,pad49C9[3]; u32 x49CC; };

typedef struct {unsigned a,b,c;} Entry;

typedef struct Context Context;

struct Resource {u32 f0, f4; u8 *util; u16 index;};

extern int complete(void);
extern int overlayLoad(int);
extern void heapCreate(u32,u32,u32);
extern void *create(void *,u32,u32);
extern void clear(void *,u32,u32);
extern void initialize(u8 *);
extern void *video(u32,u32);
extern void *font(int,int,int,int,u32);
extern void *messages(u32,u32,u32,u32);
extern void *text(u32);
extern int modeFor(const char *);
extern void *dispatch(u32,const void *,u8,u32,void *);
extern void graphics(int,u16,int);
extern void menu(char *,void *,int);
extern void cursor(char *,void *,int);
extern void music(u32,u32);
extern void fade(u32,int,int,int);
extern void func_02041EE4(u32,u32,u32);
extern void func_021BA514(char *);
extern void func_021B613C(void *);
extern void func_02045C04(struct Rec *);
extern void sub_0201C4C0(struct PrintSys *);
extern void func_0201D83C(void *);
extern void func_021BA710(char *),func_021BA7B8(char *),func_021BAC0C(unsigned char *);
extern void sub_020315D4(struct S020315D4 *);
extern void func_020306F0(u32);
extern void sub_02034A5C(int);
extern void func_021BA7D0(unsigned char *p);
extern void func_021BAC68(char *p);
extern int func_021B6144(struct S *s);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *,unsigned,unsigned,unsigned,unsigned,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void func_02049238(void *);
extern void func_021BA408(char *);
extern void func_021BA624(char *);
extern void func_021B61F8(unsigned char *task, int value);
extern void func_021BA38C(Context *);
extern u32 func_02048A18(u8 *, int);
extern int func_021BA920(int *p, u32 b, u32 c);
int func_021B95A0(void *manager,int *state,struct Args *args);
int func_021B96C0(struct S020315D4 *owner,int unused,const void *cfg,char *p);
int func_021B9740(int a,int b,int c,char *p);
void func_021B9794(int a,u16 heap,int index);
void func_021B9830(u8 *task, char *p);
int func_021B9858(void *unused, Context *p);
void func_021B9864(u8 *p);
extern const char callbacks[];
extern const char ov067_id[];
extern char overlay_id[];
extern const Entry d_021BAF14[];

int func_021B95A0(void *manager,int *state,struct Args *args)
{
    struct Obj *p;
    if(*state==1 && complete()==1) return 1;
    overlayLoad((int)ov067_id);
    heapCreate(1,116,0x80000);
    p=create(manager,0x49D8,116);
    clear(p,0,0x49D8);
    p->heap=116;
    p->args=args;
    p->mode=(u8)args->a44;
    p->x49CC=p->args->a40;
    initialize((u8 *)args);
    p->video=video(0,p->heap);
    p->font=font(23,0,0,0,p->heap);
    p->messages=messages(0,2,65,p->heap);
    p->text=text(p->heap);
    p->dispatch=dispatch(p->heap,callbacks,3,modeFor((char *)args),p);
    graphics((int)((char *)p+8),p->heap,p->args->a50);
    menu((char *)p+0x24,p->video,p->heap);
    cursor((char *)p+0xC,p->video,p->heap);
    *(volatile u16 *)0x04000304 |= 0x8000;
    music(0,p->heap);
    fade(3,16,0,1);
    *state=1;
    return 0;
}

int func_021B96C0(struct S020315D4 *owner,int unused,const void *cfg,char *p) {
u16 heap;
func_02041EE4(3,0,0);
if(*(int *)((unsigned)cfg+0x44)==2 || *(int *)((unsigned)cfg+0x44)==4)func_021BA514(p);
func_021B613C(((struct Obj06704 *)p)->f49C4);
func_02045C04(*(void **)((unsigned)p+0x49c0));
sub_0201C4C0(((struct Obj06704 *)p)->f49BC);
func_0201D83C(*(void **)((unsigned)p+0x49b8));
func_021BA710(p+0xc);func_021BA7B8(p+0x24);
func_021BAC0C(((struct Obj06704 *)p)->f49B4);
heap=*(u16 *)p;sub_020315D4(owner);func_020306F0(heap);sub_02034A5C((int)overlay_id);return 1;
}

int func_021B9740(int a,int b,int c,char *p)
{
    func_021BA7D0((unsigned char *)(p+0x24));
    if(func_021B6144(((struct Obj06704 *)p)->f49C4)) return 1;
    func_0201C4E4(((struct Obj06704 *)p)->f49BC);
    func_021BAC68(((struct Obj06704 *)p)->f49B4);
    (((struct Obj06704 *)p)->f49D4)++;
    func_02041EE4(3,0,((struct Obj06704 *)p)->f49D4/2);
    return 0;
}

/*
 * prototype: 49238 asm body saves entry r0 and forwards it to destructors; retain caller's resource argument.
 */
void func_021B9794(int a,u16 heap,int index)
{
    void *p;
    p=func_020490F4(181,heap);
    func_02049B68(p,d_021BAF14[index].a,0,0,0,heap);
    func_02049658(p,d_021BAF14[index].b,3,0,0,0,heap);
    func_020498F4(p,d_021BAF14[index].c,3,0,0,0,heap);
    func_02049B68(p,4,4,0,0,heap);
    func_02049658(p,3,6,0,0,0,heap);
    func_020498F4(p,5,6,0,0,0,heap);
    func_02049238(p);
}

void func_021B9830(u8 *task, char *p) {
    func_021BA408(p);
    func_021BA624(p + 0x498C);
    func_021B61F8(task,65534);
}

int func_021B9858(void *unused, Context *p) { func_021BA38C(p); return 1; }

void func_021B9864(u8 *p) {
    void *object;
    int i;
    struct Resource *sub;
    sub = (struct Resource *)(p+0x24);
    object = (void *)func_02048A18(sub->util, sub->index);
    for(i=0;i<2;i++) {
        int state = 1;
        if (*(u32 *)(p+0x4850+i*0x54)) state = 2;
        func_021BA920(object,i+1,state);
    }
}
