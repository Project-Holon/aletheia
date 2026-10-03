/*
 * function: func_021B95A0
 * address: 0x021B95A0
 * packet: pkt_ov213_021B95A0
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: hardware display register 0x04000304 is read then written.
 * Loading ov067: pooled overlay ID 67 reaches02034AC4/FS_LoadOverlay before dispatcher allocation.
 * create retains r0 allocation result; canonical callee is void but caller uses r0.
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
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int complete(void);
extern int overlayLoad(int);
extern void heapCreate(void *,u32,u32);
extern void *create(void *,u32,u32);
extern void clear(void *,u32,u32);
extern void initialize(u8 *);
extern void *video(u32,u32);
extern void *font(int,int,int,int,u32);
extern void *messages(u32,u32,u32,u32);
extern void *text(u32);
extern int modeFor(const char *);
extern void *dispatch(u32,const void *,u8,u32,void *);
extern const char callbacks[];
extern void graphics(int,u16,int);
extern void menu(char *,void *,int);
extern void cursor(char *,void *,int);
extern void music(u32,u32);
extern void fade(u32,int,int,int);
extern const char ov067_id[];
struct Args { u8 pad[0x40]; u32 a40,a44,a48,a4C,a50; };
struct Obj { u16 heap,pad2; struct Args *args; u8 pad8[0x49B4-8]; void *video,*font,*text,*messages,*dispatch; u8 mode,pad49C9[3]; u32 x49CC; };
int func_021B95A0(void *manager,int *state,struct Args *args)
{
    struct Obj *p;
    if(*state==1 && complete()==1) return 1;
    overlayLoad((int)ov067_id);
    heapCreate((void *)1,116,0x80000);
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
