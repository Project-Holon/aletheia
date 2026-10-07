/*
 * file:     irc_ranking_p06.c
 * unit:     yes
 * function: func_021B8518, func_021B8524, func_021B8648, func_021B8690, func_021B87B0, func_021B89F4, func_021B8A28, func_021B8A6C, func_021B8AD0, func_021B8B4C, func_021B8B5C, func_021B8B9C, func_021B8D5C, func_021B8D8C, func_021B8D90, func_021B8D9C, func_021B8DA8
 * address:  0x021B8518
 * region:   ov106
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02041300 0x02041300 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040618 0x02040618 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02043678 0x02043678 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201BABC 0x0201BABC thumb
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_02045808 0x02045808 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_020437AC 0x020437AC arm
 *   func_021B9298 0x021B9298 thumb ov106
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_021B7F7C 0x021B7F7C thumb ov106
 *   func_02049EB4 0x02049EB4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02041090 0x02041090 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200A930 0x0200A930 thumb
 *   func_0200A8E4 0x0200A8E4 thumb
 *   func_0200A908 0x0200A908 thumb
 *   func_02030734 0x02030734 arm
 *   func_02045924 0x02045924 arm
 *   d_021B9680 0x021B9680 data a1
 *   func_02035D20 0x02035D20 arm
 *   func_02035CB8 0x02035CB8 arm
 *   func_020362DC 0x020362DC arm
 *   func_0203630C 0x0203630C arm
 */
#include "../../matched/include/Obj22264.h"
#include "../../matched/include/Obj01390.h"
#include "../../matched/include/Obj10254.h"
#include "../../matched/include/Obj13760.h"
#include "../../matched/include/Obj22265.h"

#define H(o) (*(s16_021B8690 *)(p + (o)))
#define W(o) (*(u32 *)(p + (o)))
struct Descriptor;
struct CharBuf;
struct Cfg;
struct Bmp;
struct MsgBank;
struct Obj;
struct StrObj;
struct U16Vec;
struct WordSet;
struct Obj020437AC;
struct Actor;
struct PtS;
struct Big;
struct Entry;
struct Rec;
struct Strbuf;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_021B8518;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32_021B8518;

typedef signed short s16_021B8524;

typedef signed short s16_021B8690;

typedef signed short s16_021B87B0;

typedef struct {void *text;u32 id:7,value:10,tag:8,seq:7;u16 number;u8 a,b,c,active,pad[2];} Item_021B87B0;

typedef struct {s16_021B87B0 x,y;u16 z;u8 a,b;} Param;

typedef signed short s16_021B8A6C;

typedef struct {s16_021B8A6C x,y;} Pair;

typedef struct {
 void *text;
 u32 id:7, value:10, tag:8, seq:7;
 u16 number;
 u8 a,b,c,active,pad[2];
} Item_021B8B9C;

typedef signed int     s32_021B8B9C;

typedef short s16_021B8D8C;

typedef int s32_021B8D8C;

typedef short s16_021B8D90;

typedef int s32_021B8D90;

typedef short s16_021B8D9C;

typedef int s32_021B8D9C;

extern void func_02041300(u32,int,int,int,u8,u8,u8);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_020409B4(unsigned int);
extern void func_02040618(u32, u32, u32);
extern void func_02082BCC(void *,int,u32);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7A4(void *,s16_021B87B0,s16_021B87B0,void *,void *);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201BABC(u32,u32,u32,u32);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern void func_02049238(void *);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern u32 func_0201BB5C(u32,u32,u32,u32);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern void func_020437AC(struct Obj020437AC *);
extern void func_021B9298(const struct Bmp *a, const struct Bmp *b, int x, int y, u16 sx, u16 sy, u16 w, u16 h);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(void *,Pair *,u16);
extern u32 func_021B7F7C(u8 *,u32);
extern void *func_02049EB4(u32,u32,u32,u32,u16);
extern u32 func_020307B0(void *p);
extern void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_020413B0(u32,u8,u8,u8,u8,u8);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200A8A0(void *);
extern s32_021B8B9C func_0200A8AC(struct Rec *r);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern u8 func_0200A930(char *p);
extern struct Entry *func_0200A8C8(struct Rec *r, u32 index);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern u8 func_0200A8D0(struct Rec *r, u32 index);
extern u16 func_0200A8E4(struct Rec *r, u32 index);
extern u32 func_0200A8F8(struct Rec *r, u32 index);
extern void func_0200A908(void *,u32,u16 *,u8 *,u8 *,u8 *);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
s16_021B8518 func_021B8518(u8 *p);
void func_021B8524(u8 *p);
void func_021B8648(u8 *p);
void func_021B8690(void *unused, u8 *p);
void func_021B87B0(u8 *p,const Item_021B87B0 *item,void *sys,u32 first,u32 second,void *msg,u32 font,void *set,void *bg,s16_021B87B0 y1,s16_021B87B0 y2,u16 heap);
void func_021B89F4(u8 *p);
void func_021B8A28(u32 *p,u32 a,u32 b,u16 c);
void func_021B8A6C(u8 *p,int delta);
void func_021B8AD0(u8 *p,u8 *a,u16 b);
void func_021B8B4C(void *p);
void func_021B8B5C(u8 *p, u32 a, int b, u8 c);
void *func_021B8B9C(void *sys,u16 heap);
void func_021B8D5C(u8 *p);
u32 func_021B8D8C(u8 *p);
void func_021B8D90(void *p);
void func_021B8D9C(void *p);
void func_021B8DA8(int *p);
extern const char d_021B9680[];


s16_021B8518 func_021B8518(u8 *p) { return ((struct Obj22264 *)p)->f55A; }

void func_021B8524(u8 *p) {
    int i, y;
    func_02041300(p[0x548],0,0,0,32,24,0);
    func_02041300(p[0x54a],0,0,0,32,24,0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01390 *)p)->f568)),0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01390 *)p)->f56C)),0);
    for (i=((struct Obj01390 *)p)->f55C-1; i<((struct Obj01390 *)p)->f55C+10; i++) {
        if (i>=0 && i<((struct Obj01390 *)p)->f554) {
            y=(i-((struct Obj01390 *)p)->f55C)*3+4;
            if (y>=0 && y<=24)
                func_021B8A28((u32 *)(p+0x188+i*32),((struct Obj01390 *)p)->f568,p[0x548],(u16)y);
        }
    }
    for (i=((struct Obj01390 *)p)->f55C+4; i<((struct Obj01390 *)p)->f55C+17; i++) {
        if (i>=0 && i<((struct Obj01390 *)p)->f554) {
            y=(i-(((struct Obj01390 *)p)->f55C+4))*3;
            if (y>=0 && y<=24)
                func_021B8A28((u32 *)(p+0x188+i*32),((struct Obj01390 *)p)->f56C,p[0x54a],(u16)y);
        }
    }
}

void func_021B8648(u8 *p) {
    int i;
    for(i=0;i<2;i++) {
        func_02045334(*(void **)((u8 *)((unsigned int *)p+i)+0x568));
        func_02045374(*(void **)((u8 *)((unsigned int *)p+i)+0x568));
    }
    func_020409B4(p[0x548]);
    func_020409B4(p[0x54a]);
    func_020409B4(p[0x549]);
    func_020409B4(p[0x54b]);
}

/*
 * Evidence: original signed halfword loads and stores fix scroll widths.
 * ARM9 sub_02040618's legacy fourth input is forwarded only to
 * sub_02042360, whose complete three-input body does not read it;
 * this caller supplies only three inputs, so the unused fourth is omitted.
 */
void func_021B8690(void *unused, u8 *p)
{
    s16_021B8690 step, x, y;
    if (W(0x590)) {
        func_021B8648(p);
        W(0x590) = 0;
        W(0x598) = 1;
    }
    if (W(0x598)) {
        step = H(0x556) % 24;
        if (step == 0) {
            x = H(0x564) + step;
            y = H(0x566) + step;
            H(0x560) = H(0x55e);
            H(0x562) = 1;
        } else {
            if ((H(0x55e) >= 0 && H(0x560) >= 0) ||
                (H(0x55e) < 0 && H(0x560) < 0) || H(0x562) != 0) {
                H(0x562) = 0;
                if (H(0x55e) >= 0) {
                    x = H(0x564) + step;
                    y = H(0x566) + step;
                    H(0x560) = 1;
                } else {
                    x = H(0x564) - (23 - step);
                    y = H(0x566) - (23 - step);
                    H(0x560) = -1;
                }
            } else {
                if (H(0x560) >= 0) {
                    x = H(0x564) + step;
                    y = H(0x566) + step;
                    H(0x560) = 1;
                } else {
                    x = H(0x564) - (23 - step);
                    y = H(0x566) - (23 - step);
                    H(0x560) = -1;
                }
            }
        }
        func_02040618(p[0x548], 3, x);
        func_02040618(p[0x549], 3, x);
        func_02040618(p[0x54a], 3, y);
        func_02040618(p[0x54b], 3, y);
        W(0x598) = 0;
    }
}

/*
 * lever: the r3 and first-stack token parameters and the loop's token local
 *   are full words (u32); as u16 the prologue spill of r3 and the in-arm token
 *   reload scheduled differently (43 bytes).  func_0204B294 takes the word in
 *   its u32 third slot, so no narrowing is visible anywhere.
 */
void func_021B87B0(u8 *p,const Item_021B87B0 *item,void *sys,u32 first,u32 second,void *msg,u32 font,void *set,void *bg,s16_021B87B0 y1,s16_021B87B0 y2,u16 heap) {
 Param cfg; u32 member,mode1,mode2; void *arc; void *a,*b,*c,*text; int i,width; u32 token;
 i=0;
 func_02082BCC(p,0,32);
 *(const Item_021B87B0 **)p=item; *(void **)(p+28)=bg;
 *(void **)(p+4)=func_02043678(32,3,32,heap);
 a=func_020457B0(32,heap); b=func_020457B0(32,heap);
 c=func_020457B0(32,heap); text=func_020457B0(32,heap);
 func_02045CAC(msg,5,a);func_02045CAC(msg,7,b);func_02045CAC(msg,8,c);
 func_0201EFA4(set,0,item->seq,2,0,1);
 func_0201EFA4(set,2,item->id,3,0,1);
 func_0201EFA4(set,3,item->value,3,0,1);
 func_0201F250(set,text,a);
 width=func_0201D304(text,font,0)>>1;
 func_0201C7A4(*(void **)(p+4),38-width,5,text,(void *)font);
 func_0201C7A4(*(void **)(p+4),52,5,item->text,(void *)font);
 func_0201F250(set,text,b);
 width=func_0201D304(text,font,0)>>1;
 func_0201C7A4(*(void **)(p+4),142-width,5,text,(void *)font);
 func_0201F250(set,text,c);
 width=func_0201D304(text,font,0)>>1;
 func_0201C7A4(*(void **)(p+4),194-width,5,text,(void *)font);
 func_02045808(text);func_02045808(c);func_02045808(b);func_02045808(a);
 member=func_0201BABC(item->number,item->a,item->b,item->c);
 mode1=func_0201BC40(); mode2=func_0201BCB4();
 arc=func_020490F4(7,heap);
 *(u32 *)(p+20)=func_0204A6C8(arc,member,0,2,heap);
 *(u32 *)(p+24)=func_0204AF28(arc,mode1,mode2,heap);
 func_02049238(arc);
 func_02082BCC(&cfg,0,8);cfg.z=1;cfg.b=1;
 for(;i<2;i++) {
  u8 *q;
  cfg.x=232;
  if(i==0) {cfg.y=y1;token=first;} else {cfg.y=y2;token=second;}
  *(s16_021B87B0 *)(p+16+i*2)=cfg.y;
  q=p+i*4;
  *(void **)(q+8)=func_0204B294(sys,*(u32 *)(p+20),token,*(u32 *)(p+24),&cfg,i,heap);
  func_0204B6F4(*(void **)(q+8),func_0201BB5C(item->number,item->a,item->b,item->c),0);
  if(cfg.y>-16 && cfg.y<208) func_0204B3DC(*(void **)(q+8),1);
  else func_0204B3DC(*(void **)(q+8),0);
 }
}

void func_021B89F4(u8 *p) { int i; for(i=0;i<2;i++) func_0204B3B4(*(void **)(p+8+i*4)); func_0204A8D4(((struct Obj10254 *)p)->f14); func_0204AFD8(((struct Obj10254 *)p)->f18); func_020437AC(*(struct Obj020437AC * *)&((struct Obj10254 *)p)->f4); func_02082BCC(p,0,32); }

/*
 * extent: two zero padding bytes follow the return, before 0x021B8A6C.
 */
void func_021B8A28(u32 *p,u32 a,u32 b,u16 c) {
    func_021B9298((const struct Bmp *)p[1],(const struct Bmp *)((u32)func_02045770((struct Descriptor *)a)),0,0,0,c,32,3);
    func_021B8B5C((u8 *)p[7],b,c,(*(u32 *)(p[0]+4)<<7)>>24);
}

void func_021B8A6C(u8 *p,int delta) {
    Pair pos;
    int offsets[2];
    int i;
    offsets[0]=-delta;
    offsets[1]=-delta;
    for(i=0;i<2;i++) {
        func_0204B454(*(void **)((u8 *)((unsigned int *)p+i)+8),(struct PtS *)&pos,(u16)i);
        pos.y=offsets[i]+*(s16_021B8A6C *)((u8 *)((s16_021B8A6C *)p+i)+16);
        func_0204B404(*(void **)((u8 *)((unsigned int *)p+i)+8),&pos,i);
        if(pos.y>-16 && pos.y<208) func_0204B3DC(*(void **)((u8 *)((unsigned int *)p+i)+8),1);
        else func_0204B3DC(*(void **)((u8 *)((unsigned int *)p+i)+8),0);
    }
}

/*
 * extent: two zero padding bytes follow the return, before 0x021B8B4C.
 * lever: allocation declared before table keeps allocation in ip and table spilled;
 * table assignments repeat the data source to retain both stores without a reload.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`table=(int)data;` before `table=(int)data+12;`). Game code has no line
 * table, so these were stand-ins. The plain single assignment gives EXACT*
 * in --lang c99 and --lang c: the output bytes do not change. Older text in
 * this header that asks for the double assignment is superseded.
 */
void func_021B8AD0(u8 *p,u8 *a,u16 b) {
    void *data;
    void *allocation;
    int table;
    u16 x,y;
    int i,j;
    func_02082BCC(p,0,384);
    x=func_021B7F7C(a,1);
    y=func_021B7F7C(a,0);
    allocation=func_02049EB4(77,5,0,(u32)&data,b);
    table=(int)data+12;
    for(i=0;i<3;i++) {
        for(j=0;j<32;j++) {
            *(u16 *)(p+i*64+j*2)=*(u16 *)(table+i*64+j*2)+x;
            *(u16 *)(p+i*64+j*2+192)=*(u16 *)(table+i*64+j*2)+y;
        }
    }
    func_020307B0(allocation);
}

void func_021B8B4C(void *p) { func_02082BCC(p,0,384); }

void func_021B8B5C(u8 *p, u32 a, int b, u8 c) {
    if(a>=4) p+=192;
    func_02041090(a,(u32)p,0,(u8)b,32,3);
    func_020413B0(a,0,b,32,3,c);
}

void *func_021B8B9C(void *sys,u16 heap) {
 void *src; u16 count; u8 *out; Item_021B8B9C *item; u32 i; u8 prev,seq,active;
 src=func_0200A8A0(func_02012EBC(sys));
 count=func_0200A8AC(src);
 out=func_02030734(heap,count*16+4,0,d_021B9680,2724);
 func_02082BCC(out,0,count*16+4);
 *(u32 *)out=count;
 if(count) {
  prev=128; seq=0; active=func_0200A930(src);
  for(i=0;i<*(u32 *)out;i++) {
   item=(Item_021B8B9C *)(out+4+i*16);
   item->text=func_020457B0(8,heap);
   func_02045924(item->text,(const u16 *)func_0200A8C8(src,i));
   item->id=func_0200A8D0(src,i);
   item->value=func_0200A8E4(src,i);
   if(item->id<prev) item->seq=i+1;
   else if(item->id==prev) item->seq=seq;
   {
    u8 flag; int v;
    flag=func_0200A8F8(src,i);
    if(active==i) {
     v=flag==0;
     item->tag=5*(v+1);
     item->active=1;
    } else if(item->seq==1) {
     v=0; if(flag==0) v=5; item->tag=v+2;
    } else if(item->seq==2) {
     v=0; if(flag==0) v=5; item->tag=v+3;
    } else if(item->seq==3) {
     v=0; if(flag==0) v=5; item->tag=v+4;
    } else {
     v=0; if(flag==0) v=5; item->tag=v+1;
    }
   }
   func_0200A908(src,i,&item->number,&item->a,&item->b,&item->c);
   prev=item->id; seq=item->seq;
  }
 }
 return out;
}

/*
 * trailing: two-byte alignment padding, no follower.
 */
void func_021B8D5C(u8 *p) { u32 i; if (((struct Obj13760 *)p)->f0 != 0) { for(i=0;i<((struct Obj13760 *)p)->f0;i++) { struct U16Vec *v; v=*(struct U16Vec **)(p+4+i*16); if(v) func_02045808(v); } } func_020307B0(p); }


u32 func_021B8D8C(u8 *p) { return ((struct Obj22265 *)p)->f0; }

void func_021B8D90(void *p) { func_02082BCC(p, 0, 0x2c); }

void func_021B8D9C(void *p) { func_02082BCC(p, 0, 0x2c); }

/*
 * extent: two zero padding bytes follow the return, before 0x021B8E50.
 */
void func_021B8DA8(int *p) {
    int x,y;
    int d;
    if(func_02035D20((u32 *)(&x),(u32 *)(&y))) {
        p[0]=x;p[1]=y;p[2]=x;p[3]=y;p[4]=x;p[5]=y;
        p[6]=0;p[7]=0;p[8]=0;
    } else if(func_02035CB8((u32 *)(&x),(u32 *)(&y))) {
        d=y-p[1];
        if(d<0)d=-d;
        if(d>=1) {
            p[6]=x-p[4];p[7]=y-p[5];p[4]=x;p[5]=y;
        }
        p[2]=x;p[3]=y;p[8]++;p[9]=0;
    } else p[9]++;
    if(func_020362DC()&192) {p[10]=0;return;}
    if(func_0203630C()&192)p[10]++;
}
