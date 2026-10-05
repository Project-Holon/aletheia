/*
 * function: func_0220AF40
 * address: 0x0220AF40
 * packet: pkt_ov207_0220AF40
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * checks: 1 own ARM9/ov206/ov207 bodies and B428 show confirm live arity; 2 B048/B318/B260/B55C neighbours reread, no initializer twin; 3 unsigned flag and enum zero field compile unchanged6; 4 bool-store and enum-zero idioms read, two manual zero/flag changes worse76 or unchanged6; 5 full unfiltered idiom directory and matched neighbours refreshed, scalar frame. Final retry exhausted; prior once300 not repeated; best264B/DIFF6 retained.
 * residue: zero-field store and flag initialization schedule, six concrete bytes.
 * ABI: 0203159C leaves the allocated pointer in r0; this caller stores it although its matched declaration is void.
 * recoup 2026-10-05 (lane X7): callee types rechecked against matched definitions (0220B318, 0220B428, 0220B55C, 021B9DE0, 0203159C returns a pointer; no void-return problem). Residue 6 B: original keeps the hoisted zero in r6 for str [0x10]/[0x14], then re-materialises flag with movs r6,#0 after the reload of args[0]; ours stores [0x14] through a fresh r0. Tried, all worse or unchanged: zero store after flag=0 (76 B), p->zero=flag (76), flag as inline ternary in the call (76), flag zeroed after p->zero (76), zero via a separate local z (76), flag declared after p (6), flag u32 (6), all six per-function pragmas (6 each).
 * recoup 2026-10-05 P29R9: 17 compiles, none better than 6 B. New tries: if/else flag after zero (76), flag=(args[0]!=0)?1:0 statement (76), flag=0 right before the if (76), p->zero=flag=0 and flag=p->zero=0 (76 each), u8 flag (6), u32 zero field (6), flag initialised in declaration before p (45), zero store before enabled if (154), const u32 *args (41), enabled arms reversed (9), flag if(==0)/else (76). Whenever flag=0 is placed after the zero store, mwcc stops hoisting the zero constant (r6) and the 0x6a constant takes r7. Residue unchanged: original keeps the hoisted zero for [0x14] and re-materialises flag zero after the args[0] reload.
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   overlay67 0x00000043 data
 *   overlay206 0x000000CE data
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0220B318 0x0220B318 thumb ov207
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0220B428 0x0220B428 thumb ov207
 *   func_021B9DE0 0x021B9DE0 thumb ov206
 *   func_0220B55C 0x0220B55C thumb ov207
 *   func_0203D34C 0x0203D34C arm
 *   func_0220B260 0x0220B260 thumb ov207
 *   func_0220B2F8 0x0220B2F8 thumb ov207
 *   func_020056A0 0x020056A0 thumb
 *   func_0204E720 0x0204E720 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Main { u16 heap,pad; void *display,*font; u32 gfx; int enabled,zero; u32 unused[2]; void *mon,*other,*task; int flag,last; };
extern char overlay67[],overlay206[];
extern int func_02034AC4(int);
extern void func_0203064C(void *,u32,u32);
extern struct Main *func_0203159C(void *,u32,u32);
extern void func_02082BCC(void *,int,int);
extern void *func_0220B318(int,int);
extern void *func_0201D7EC(int,int,int,int,u32);
extern u32 func_0201C440(void *);
extern u32 func_0220B428(void *);
extern void *func_021B9DE0(u16,void *,u32,u32,u32,u32,u8,u32,u32,u32,u32,u32,u32);
extern void *func_0220B55C(u16,u32,u32,u32,u32,u32,u32,u32,u32);
extern void func_0203D34C(u32,u32);
extern void func_0220B260(u32 *);
extern void func_0220B2F8(int,char *);
extern void *func_020056A0(u32,u32,u32);
extern void func_0204E720(u32,int,int,int);
int func_0220AF40(void *owner,int unused,u32 *args)
{
    struct Main *p;
    int flag;
    func_02034AC4((int)overlay67);
    func_02034AC4((int)overlay206);
    func_0203064C((void *)1,0x6a,0x80000);
    p=func_0203159C(owner,0x34,0x6a);
    func_02082BCC(p,0,0x34);
    p->heap=0x6a;
    p->display=func_0220B318(1,p->heap);
    p->font=func_0201D7EC(0x17,0,0,0,p->heap);
    p->gfx=func_0201C440((void *)(u32)p->heap);
    flag=0;
    if(args[0]==0) p->enabled=0; else p->enabled=1;
    p->zero=0;
    if(args[0]!=0) flag=1;
    p->mon=func_021B9DE0(p->heap,(void *)args[1],args[2],1,flag,0,0,func_0220B428(p->display),(u32)p->font,p->gfx,0,0,0);
    p->other=func_0220B55C(p->heap,args[1],args[3],args[4],args[5],func_0220B428(p->display),(u32)p->font,p->gfx,args[6]);
    func_0203D34C(0,p->heap);
    if(p->enabled==1) func_0220B260((u32 *)p);
    p->task=func_020056A0((u32)func_0220B2F8,(u32)p,1);
    func_0204E720(3,16,0,2);
    return 1;
}
