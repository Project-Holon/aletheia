/*
 * file:     p_sta_oam_p11.c
 * unit:     yes
 * function: func_021D697C, func_021D6A38, func_021D6CDC, func_021D6D04, func_021D6D18
 * address:  0x021D697C
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_021D60A4 0x021D60A4 thumb ov131
 *   func_021D785C 0x021D785C thumb ov131
 *   func_021D7A1C 0x021D7A1C thumb ov131
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02049F34 0x02049F34 arm
 *   func_02049DB4 0x02049DB4 arm
 *   func_0204ADEC 0x0204ADEC arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_02048AFC 0x02048AFC arm
 *   func_02048AD0 0x02048AD0 arm
 *   d_021DC204 0x021DC204 data a4
 *   d_021DC21C 0x021DC21C data a4
 *   d_021DC1B0 0x021DC1B0 data a4
 *   d_021DC1A4 0x021DC1A4 data a4
 *   d_021DC18C 0x021DC18C data a4
 *   d_021DC1BC 0x021DC1BC data a4
 *   func_0201ACDC 0x0201ACDC thumb
 *   func_020452E8 0x020452E8 arm
 *   func_021D797C  0x021D797C  thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_02045808 0x02045808 arm
 */
#include "../../matched/include/Obj00436.h"
#include "../../matched/include/Obj00112.h"
#include "../../matched/include/Obj00472.h"
#include "../../matched/include/Obj10508.h"
#include "../../matched/include/Obj14066.h"
#include "../../matched/include/Obj14067.h"
#include "../../matched/include/Obj23137.h"
#include "../../matched/include/Obj01546.h"

struct Personal;
struct Cfg;
struct Descriptor;
struct Light;
struct Obj;
struct Sub0204A9D0;
struct MsgBank;
struct U16Vec;
struct WordSet;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {u32 x,y,z;} Vec;

typedef signed int     s32;

extern void *func_021D6064(unsigned char *p);
extern int func_0201ACC4(void *p, u32 pos);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern void *func_0201ADE4(u32,int,u32);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern int func_021D60A4(char *p);
extern void func_021D785C(u8 *p, u8 *q, void *mon);
extern void func_021D7A1C(void *,void *,Vec *);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
extern u32 func_020275E4(void);
extern int func_02027720(int);
extern int func_0202772C(int);
extern void *func_02049F34(u32,u32,u32,u32);
extern void *func_02049DB4(u32,u32,u32,u32,u16);
extern void func_0204ADEC(u32,void *,u32);
extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern u32 func_020307B0(void *p);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern u32 func_0201B28C(void *);
extern u32 func_02017EB4(void *);
extern u32 func_02017F90(void *);
extern int func_020276C4(int a0);
extern u32 func_0201B268(void *);
extern void func_02015C78(void *,u32 *);
extern void func_02015D30(void *,u32 *);
extern void func_02048AFC(void *,const Vec *);
extern void func_02048AD0(struct Light *l);
extern void func_0201ACDC(void *p, u32 pos, u32 mode);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_021D797C(u8 *p, void **q);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *,u32,u32,u32,u32,u32,u16);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02018438(void *);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
void func_021D697C(unsigned char *p,int *q);
void func_021D6A38(u8 *p,u8 *q);
void func_021D6CDC(unsigned char *a,unsigned char *b);
void func_021D6D04(void *a, u8 *p);
void func_021D6D18(u8 *p,u8 *q,void *mon);
extern const Vec d_021DC204,d_021DC21C,d_021DC1B0,d_021DC1A4,d_021DC18C,d_021DC1BC;

void func_021D697C(unsigned char *p,int *q) {
 void *m=func_021D6064(p);
 void *t;
 int a,b;
 if((*(unsigned char **)(p+8))[12]==1) q[3]=func_0201ACC4(**(void ** *)&((struct Obj00436 *)p)->f8,((struct Obj00436 *)p)->f18); else q[3]=1;
 if(*(int *)&((struct Obj00436 *)p)->f38==0) {
 a=func_02017E88(m,5,0);
 b=func_02017E88(m,111,0);
 t=func_0201ADE4((unsigned short)a,(unsigned short)b,((struct Obj00436 *)p)->f0);
 if(func_0201AE1C(t,16)==1) q[4]=1; else q[4]=0;
 q[5]=func_0201AE1C(t,38);
 func_0201AE14(t);
 } else {q[4]=0;q[5]=0;}
 q[6]=(int)func_020450F0(1,19,0,13,4,14,1);
 q[7]=(int)func_020450F0(1,19,17,13,4,14,1);
 func_021D6D18(p,(u8 *)q,m);
}

/*
 * lever: block-local Vec zero initializers materialize addresses before
 *   stores; explicit visibility if/else calls retain original branch shape;
 *   mask update before i++ retains the original loop scheduling.
 * output: 49F34/49DB4 call 4A1BC, whose returned allocation is nonzero:
 *   30734 null failure calls 88234 -> 882C0 -> 882C8 halt loop (882CC
 *   branches back). Both 62A98 and 62A4C assign *out on every returning
 *   path, including absent block. No output default or success assumption.
 * interface: 785C receives the visibly loaded third mon word even though
 *   its own body ignores it. 4ADEC's fourth legacy parameter is overwritten
 *   before use, original sets only r0-r2; 276C4 reads only r0 and replaces
 *   r1-r3 before each call, so unused legacy trailing inputs are omitted.
 * arithmetic: local u8 i=0..5 and mask truncates modulo256; all vectors
 *   assigned from three-word ROM templates or all three explicit zeros.
 */
void func_021D6A38(u8 *p,u8 *q)
{
    void *pal,*chr;
    void *mon,*other,*window,*loaded;
    u32 form,archive,status;
    u8 i,mask;
    mon=func_021D6064(p);
    other=(void *)func_021D60A4((char *)p);
    func_021D785C(p,q,mon);
    window=((struct Obj00472 *)q)->f18;
    func_02045334(window);
    func_02045374(window);
    func_02041B6C(func_02045730(window));
    window=((struct Obj00472 *)q)->f1C;
    func_02045334(window);
    func_02045374(window);
    func_02041B6C(func_02045730(window));
    form=func_02017E88(mon,0x98,0);
    archive=func_020275E4();
    loaded=func_02049F34(archive,func_02027720(form),(u32)&pal,((struct Obj00112 *)p)->f0);
    func_0204ADEC(((struct Obj00112 *)p)->f9C,pal,1);
    func_020307B0(loaded);
    archive=func_020275E4();
    loaded=func_02049DB4(archive,func_0202772C(form),0,(u32)&chr,((struct Obj00112 *)p)->f0);
    func_0204A9D0(((struct Obj00112 *)p)->fD0,chr);
    func_020307B0(loaded);
    func_0204B3DC(((struct Obj00472 *)q)->f20,1);
    status=func_02017E88(mon,11,0);
    for(i=0,mask=1;i<6;mask=(u8)(mask<<1),i++) {
        if(status & mask) func_0204B878(*(void **)(q+0x24+i*4),i*2+1);
        else func_0204B878(*(void **)(q+0x24+i*4),i*2);
    }
    if(func_0201B28C(mon)==1) func_0204B3DC(((struct Obj00472 *)q)->f40,1);
    else func_0204B3DC(((struct Obj00472 *)q)->f40,0);
    if(func_02017EB4(mon)==1 && ((struct Obj00112 *)p)->f38==0)
        func_0204B3DC(((struct Obj00472 *)q)->f3C,1);
    else func_0204B3DC(((struct Obj00472 *)q)->f3C,0);
    if(((struct Obj00472 *)q)->fC==1) {
        Vec a=d_021DC204;
        Vec b=d_021DC21C;
        Vec c={0,0,0};
        Vec d=d_021DC1B0;
        func_02015C78(((struct Obj00472 *)q)->f0,&c.x);
        func_021D7A1C(p,q,&d);
        func_02015D30(((struct Obj00472 *)q)->f0,&b.x);
        func_02048AFC(((struct Obj00112 *)p)->f70,&a);
        func_02048AD0(((struct Obj00112 *)p)->f70);
        ((struct Obj00472 *)q)->f8=0;
    } else {
        Vec e=d_021DC1A4;
        Vec f=d_021DC18C;
        Vec g={0,0,0};
        Vec h=d_021DC1BC;
        func_02015C78(((struct Obj00472 *)q)->f0,&g.x);
        func_021D7A1C(p,q,&h);
        func_02015D30(((struct Obj00472 *)q)->f4,&f.x);
        func_02048AFC(((struct Obj00112 *)p)->f70,&e);
        func_02048AD0(((struct Obj00112 *)p)->f70);
        ((struct Obj00472 *)q)->f8=2;
    }
    if((u8)func_02017F90(other)!=0) {
        func_0204B878(((struct Obj00472 *)q)->f48,func_020276C4((int)other));
        func_0204B3DC(((struct Obj00472 *)q)->f48,1);
        func_0204B3DC(((struct Obj00472 *)q)->f44,0);
    } else {
        func_0204B3DC(((struct Obj00472 *)q)->f48,0);
        if(func_0201B268(mon)==1) func_0204B3DC(((struct Obj00472 *)q)->f44,1);
        else func_0204B3DC(((struct Obj00472 *)q)->f44,0);
    }
    {
    Vec zero={0,0,0};
    func_02015C78(((struct Obj00472 *)q)->f0,&zero.x);
    func_02015C78(((struct Obj00472 *)q)->f4,&zero.x);
    q[0x78]=0;q[0x79]=0;q[0x80]=0;q[0x81]=0;
    ((struct Obj00472 *)q)->f6C=0;((struct Obj00472 *)q)->f5C=0;
    q[0x88]=0;q[0x89]=0;
    }
}

void func_021D6CDC(unsigned char *a,unsigned char *b) {
 unsigned char *q=*(unsigned char * *)&((struct Obj14066 *)a)->f8;
 if(q[12]==1) func_0201ACDC(((struct Obj14067 *)q)->f0,a[0x1a],(u32)(((struct Obj10508 *)b)->fC));
 func_020452E8(((struct Obj10508 *)b)->f1C);
 func_020452E8(((struct Obj10508 *)b)->f18);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D6D04(void *a, u8 *p)
{
    func_021D797C(a, (void **)p);
    func_0204B3DC(((struct Obj23137 *)p)->f20, 0);
}

void func_021D6D18(u8 *p,u8 *q,void *mon)
{
    void *ws,*buf,*name,*text;
    ws=func_0201EC64(((struct Obj00436 *)p)->f0);
    buf=func_020457B0(32,((struct Obj00436 *)p)->f0);
    name=func_020457B0(32,((struct Obj00436 *)p)->f0);
    func_02017E88(mon,115,(u32)name);
    func_0201EE0C(ws,0,name,0,1,2);
    text=func_02045EC0(((struct Obj00436 *)p)->f7C,0);
    func_0201F250(ws,buf,text);
    func_0201C724(((struct Obj00436 *)p)->f84,(u32)func_02045770(((struct Obj01546 *)q)->f18),25,1,(u32)buf,((struct Obj00436 *)p)->f80,1088);
    func_02045808(name);func_02045808(text);func_02045808(buf);func_0201ED04(ws);
    if(((struct Obj00436 *)p)->f38==0 && func_02017E88(mon,173,0)==1){
        u32 form=func_02017E88(mon,110,0);
        if(form==0){
            buf=func_02045EC0(((struct Obj00436 *)p)->f7C,1);
            func_0201C724(((struct Obj00436 *)p)->f84,(u32)func_02045770(((struct Obj01546 *)q)->f18),89,1,(u32)buf,((struct Obj00436 *)p)->f80,5312);
            func_02045808(buf);
        }else if(form==1){
            buf=func_02045EC0(((struct Obj00436 *)p)->f7C,2);
            func_0201C724(((struct Obj00436 *)p)->f84,(u32)func_02045770(((struct Obj01546 *)q)->f18),89,1,(u32)buf,((struct Obj00436 *)p)->f80,3200);
            func_02045808(buf);
        }
    }
    if(((struct Obj00436 *)p)->f38==0){
        void *text2;
        ws=func_0201EC64(((struct Obj00436 *)p)->f0);buf=func_020457B0(16,((struct Obj00436 *)p)->f0);
        func_0201EFA4(ws,0,func_02018438(mon),3,0,1);
        text2=func_02045EC0(((struct Obj00436 *)p)->f7C,3);
        func_0201F250(ws,buf,text2);
        func_0201C724(((struct Obj00436 *)p)->f84,(u32)func_02045770(((struct Obj01546 *)q)->f18),9,17,(u32)buf,((struct Obj00436 *)p)->f80,1088);
        func_02045808(text2);func_02045808(buf);func_0201ED04(ws);
    }
    buf=func_02045EC0(((struct Obj00436 *)p)->f7C,4);
    func_0201C724(((struct Obj00436 *)p)->f84,(u32)func_02045770(((struct Obj01546 *)q)->f1C),10,1,(u32)buf,((struct Obj00436 *)p)->f80,1088);
    func_02045808(buf);
    {
        void *text3;
        ws=func_0201EC64(((struct Obj00436 *)p)->f0);buf=func_020457B0(16,((struct Obj00436 *)p)->f0);
        func_0201EF40(ws,0,func_02017E88(mon,6,0));
        text3=func_02045EC0(((struct Obj00436 *)p)->f7C,5);
        func_0201F250(ws,buf,text3);
        func_0201C724(((struct Obj00436 *)p)->f84,(u32)func_02045770(((struct Obj01546 *)q)->f1C),6,17,(u32)buf,((struct Obj00436 *)p)->f80,1088);
        func_02045808(text3);func_02045808(buf);func_0201ED04(ws);
    }
}
