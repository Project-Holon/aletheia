/*
 * file:     plist_battle_p17.c
 * unit:     yes
 * function: func_021BD59C, func_021BD61C, func_021BD634, func_021BD8B0, func_021BD8E4, func_021BD9C8, func_021BDABC, func_021BDBE0, func_021BDBF8, func_021BDC3C
 * address:  0x021BD59C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020450F0  0x020450F0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_02045808  0x02045808  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_020452E8 0x020452E8 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_021BA4F8 0x021BA4F8 thumb ov091
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02061CA4 0x02061CA4 arm
 *   d_020A1B38 0x020A1B38 data a2
 *   func_02040588 0x02040588 arm
 *   func_021B7034 0x021B7034 thumb ov091
 *   func_021B6F28 0x021B6F28 thumb ov091
 *   func_021B7040 0x021B7040 thumb ov091
 *   func_021B6F0C 0x021B6F0C thumb ov091
 *   func_021BBA54 0x021BBA54 thumb ov091
 *   func_021BB97C 0x021BB97C thumb ov091
 *   func_021BB99C 0x021BB99C thumb ov091
 *   func_021B9788 0x021B9788 thumb ov091
 *   func_021BB98C 0x021BB98C thumb ov091
 *   func_021B9E3C 0x021B9E3C thumb ov091
 *   func_021B9E20 0x021B9E20 thumb ov091
 *   func_021BB200 0x021BB200 thumb ov091
 *   func_02051614 0x02051614 arm
 *   func_02051574 0x02051574 arm
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02051534 0x02051534 arm
 *   func_02047970 0x02047970 arm
 *   func_02006BD0 0x02006BD0 thumb
 *   func_0205121C 0x0205121C arm
 *   func_0203D7C8 0x0203D7C8 arm
 *   func_02050C04 0x02050C04 arm
 *   func_02051230 0x02051230 arm
 *   func_021BB3D4 0x021BB3D4 thumb ov091
 *   func_020515B4 0x020515B4 arm
 *   d_021BED58 0x021BED58 data ov091 a4
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_02050DB8 0x02050DB8 arm
 *   func_0203D7FC 0x0203D7FC arm
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017988 0x02017988 thumb
 *   func_0200CDE0 0x0200CDE0 thumb
 */
#include "../../matched/include/Obj04353.h"
#include "../../matched/include/Obj13262.h"
#include "../../matched/include/Obj00009.h"
#include "../../matched/include/Obj06215.h"
#include "../../matched/include/Obj09935.h"
#include "../../matched/include/Obj20927.h"

#define P(k) (*(void **)(p+(k)))
#define H(k) (*(u16 *)(p+(k)))
#define T (*(u16 *)((u8 *)P(0x280)+0x60))
struct MsgBank;
struct U16Vec;
struct Descriptor;
struct WordSet;
struct CharBuf;
struct StrObj;
struct PrintSys;
struct Cfg;
struct Blk37;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short s16_021BD634;

typedef short s16_021BDABC;

typedef struct { s16_021BDABC x,y; } Pair;

extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_020452E8(struct Descriptor *d);
extern struct U16Vec *func_020457B0(u32,u32);
extern struct WordSet *func_0201EC64(u32);
extern void func_0201EFA4(struct WordSet *,u32,u32,u32,u32,u32);
extern void func_02043B5C(struct CharBuf *,u8);
extern void func_0201F250(struct WordSet *,void *,void *);
extern u32 func_0201D304(struct StrObj *,u32,u32);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_021BA4F8(u8 *);
extern u32 func_0201C6C4(struct PrintSys *,void *);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(u32);
extern int func_02061CA4(void *,u32,u32,int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021B7034(char *);
extern void func_021B6F28(char *);
extern void func_021B7040(unsigned p);
extern void func_021B6F0C(void *p);
extern void func_021BBA54(unsigned short *a, u32 b);
extern void func_021BB97C(u16 *p, u32 s);
extern void func_021BB99C(int a, int b, int c, int d);
extern void func_021B9788(u8 *,int,int,int);
extern void func_021BB98C(void *p, u32 s);
extern void func_021B9E3C(char *p);
extern void func_021B9E20(u8 *);
extern void func_020061E4(u32);
extern void func_021BB200(u8 *,u8 *,int,int);
extern int func_02051614(int **p);
extern int func_02006238(void);
extern u32 func_02017E1C(void *,u32,u32);
extern u32 func_02006984(u32,u32,u32,u32,u32,u32,u32,u32);
extern u32 func_02006BD0(u32 i);
extern int func_02051574(void);
extern void func_02047964(void);
extern void func_020479D8(void);
extern int func_02051534(void);
extern void func_02047970(void);
extern int func_0205121C(u32,u32,u32);
extern void *func_0203D7C8(u32,u32,const char *,u16);
extern int func_02050C04(int,int,int,int);
extern u32 func_020056BC(void);
extern void func_02051230(u8 *,u32,u32,u32);
extern void func_021BB3D4(void *a, u8 *s, u16 *out);
extern int func_020515B4(void *p, int b, int c);
extern void func_02050DB8(u8 *);
extern void func_0203D7FC(void *);
extern u32 func_02017988(void *, u32);
extern void func_0200CDE0(struct Blk37 *, void *);
void func_021BD59C(char *p);
void func_021BD61C(char *p);
void func_021BD634(u8 *p);
void func_021BD8B0(char *p);
void func_021BD8E4(u8 *p);
void func_021BD9C8(u8 *p);
void func_021BDABC(u8 *p);
void func_021BDBE0(unsigned int p);
int func_021BDBF8(char *p);
void func_021BDC3C(u32 p, void *m);
extern s16_021BD634 d_020A1B38[];
extern u8 d_021BED58[];


void func_021BD59C(char *p)
{
    int s;
    ((struct Obj04353 *)p)->f1FC = func_020450F0(4, 7, 0x15, 0xB, 3, 0xE, 1);
    ((struct Obj04353 *)p)->f200 = func_020450F0(4, 0x14, 0x15, 5, 3, 0xE, 1);
    s = (int)func_02045EC0((struct MsgBank *)(((struct Obj04353 *)p)->f134), 0xAD);
    func_0201C724((void *)(((struct Obj04353 *)p)->f140), (int)func_02045770((struct Descriptor *)((struct Obj04353 *)p)->f1FC), 0, 4, s,
                  ((struct Obj04353 *)p)->f138, 0x3C40);
    func_02045808((struct U16Vec *)s);
    ((struct Obj04353 *)p)->f204 = 1;
}

void func_021BD61C(char *p) { func_020452E8(*(struct Descriptor * *)&((struct Obj13262 *)p)->f1FC); func_020452E8(*(struct Descriptor * *)&((struct Obj13262 *)p)->f200); }

#define W(k) (*(u32 *)(p+(k)))

/*
 * note: minute and second are u8 locals: widening the explicit byte casts
 *   to u32 keeps the size but moves the text spill before outgoing stores.
 */
void func_021BD634(u8 *p)
{
    u32 width;
    u8 minute;
    u8 second;
    void *text;
    struct U16Vec *buf;
    struct WordSet *words;
    u16 timer;
    struct Descriptor *window;
    u8 amount;
    u8 i;
    u8 red;
    u8 green;
    u8 blue;
    u16 color;
    int value;
    timer=T;
    if(p[0x20d]!=timer) {
        minute=(u8)(timer/60);
        second=(u8)(timer%60);
        buf=func_020457B0(32,H(0));
        words=func_0201EC64(H(0));
        if(minute==0) {
            text=func_02045EC0(P(0x134),175);
            func_0201EFA4(words,1,second,2,1,1);
        } else {
            text=func_02045EC0(P(0x134),174);
            func_0201EFA4(words,0,minute,2,1,1);
            func_0201EFA4(words,1,second,2,2,1);
        }
        func_02043B5C(func_02045770(P(0x200)),0);
        func_0201F250(words,buf,text);
        width=func_0201D304((struct StrObj *)buf,W(0x138),0);
        func_0201C724(P(0x140),(u32)func_02045770(P(0x200)),(s16_021BD634)(36-width),4,(u32)buf,W(0x138),0x3c40);
        func_0201ED04(words);
        func_02045808(buf);
        func_02045808(text);
        W(0x208)=1;
        p[0x20d]=T;
    }
    if(T==0) func_021BA4F8(p);
    if(W(0x208)==1) {
        if(func_0201C6C4(P(0x140),func_02045770(P(0x200)))==0) {
            W(0x208)=0;
            window=P(0x200);
            func_02045334(window);
            func_02045374((struct Cfg *)window);
            func_02041B6C(func_02045730(window));
        }
    }
    if(W(0x204)==1) {
        if(func_0201C6C4(P(0x140),func_02045770(P(0x1fc)))==0) {
            W(0x204)=0;
            window=P(0x1fc);
            func_02045334(window);
            func_02045374((struct Cfg *)window);
            func_02041B6C(func_02045730(window));
        }
    }
    if(T<=10) {
        amount=(d_020A1B38[(((H(0x24e)<<16)/60)>>4)*2+1]+4096)*32/8192;
        for(i=0;i<16;i++) {
            color=*(u16 *)(p+(u32)i*2+0x20e);
            green=(color&0x3e0)>>5;
            blue=(color&0x7c00)>>10;
            red=color&31;
            value=red+amount;
            if(value>31) value=31;
            red=value;
            *(u16 *)(p+(u32)i*2+0x22e)=(blue<<10)|(red|(green<<5));
        }
        func_02061CA4((void *)31,64,(u32)(p+0x22e),32);
        H(0x24e)++;
        if(H(0x24e)>=60) H(0x24e)=0;
    }
}

void func_021BD8B0(char *p) { ((struct Obj00009 *)p)->f268=0; ((struct Obj00009 *)p)->f26C=0; ((struct Obj00009 *)p)->f270=0; func_02040588(0,0); func_021B7034(p); func_021B6F28(p); func_021BDABC((u8 *)p); p[12]=15; }

#undef W
#define W(o) (*(u32 *)(p+(o)))

void func_021BD8E4(u8 *p)
{
    void (*cb)(u8 *);
    func_021BDBE0((unsigned int)p);
    func_021B7040((unsigned int)p);
    func_021B6F0C(p);
    func_021BBA54((short unsigned int *)p,W(0x150));
    if (W(0x264) == 1) {
        cb = (void (*)(u8 *))func_021B9E3C;
        if (*(u32 *)(W(0x280)+0x34) == 0) cb = func_021B9E20;
        func_021BB97C((u16 *)p,W(0x150));
        func_021BB99C((int)p,W(0x150),0,W(0x38));
        func_021B9788(p,0xa6,1,(int)cb);
        func_021BB98C(p,W(0x150));
    } else if (W(0x264) == 2) {
        cb = (void (*)(u8 *))func_021B9E3C;
        if (*(u32 *)(W(0x280)+0x34) == 0) cb = func_021B9E20;
        func_021BB97C((u16 *)p,W(0x150));
        func_021BB99C((int)p,W(0x150),0,W(0x38));
        func_021B9788(p,0xa6,1,(int)cb);
        func_021BB98C(p,W(0x150));
    } else if (W(0x264) == 3) {
        func_021BB97C((u16 *)p,W(0x150));
        func_021BB99C((int)p,W(0x150),0,W(0x38));
        func_021B9788(p,0xa6,1,(int)func_021B9E3C);
        func_021BB98C(p,W(0x150));
    } else {
        p[0xc] = 0x13;
    }
}

#undef W
#define W(o) (*(u32 *)(p+(o)))

/*
 *   unsigned int func_02051614(unsigned int **p) { return (*p)[2]; }
 */
void func_021BD9C8(u8 *p)
{
    u32 species,form;
    if (W(0x26c) == 0) {
        p[0x268]++;
        if (p[0x268] == 1) {
            func_02040588(0,1);
            if (W(0x264)-1 <= 1) func_020061E4(0x643);
            else if (W(0x264) == 3) func_020061E4(0x644);
        }
        if (p[0x268] > p[0x269]) {
            func_021BB200(p,*(u8 **)(p+W(0x2c)*4+0x160),W(0x38),0);
            W(0x26c) = 1;
        }
    }
    if (func_02051614((int **)W(0x260)) <= 0 && func_02006238() == 0) {
        if (W(0x270) == 0) {
            species = func_02017E1C((void *)W(0x38),5,0);
            form = func_02017E1C((void *)W(0x38),0x6f,0);
            W(0x274) = func_02006984(species,form,0x40,0,0,0,0,0);
            W(0x270) = 1;
        } else {
            if (func_02006BD0(W(0x274)) == 0) p[0xc] = 0x10;
        }
    }
    func_02051574();
    func_02047964();
    func_020479D8();
    func_02051534();
    func_02047970();
}

#undef W
#define W(o) (*(u32 *)(p+(o)))

/*
 * lever: two-halfword coordinate struct keeps its address sp-relative; int alias added 4 B.
 */
void func_021BDABC(u8 *p)
{
    u8 count;
    int member;
    int handle;
    Pair xy;
    int vec[3];
    u8 i;
    count = 0;
    member = 0x1c;
    if (W(0x264)-1 <= 1) {
        member = 0x1b;
        count = 3;
        p[0x269] = 0x41;
    } else if (W(0x264) == 3) {
        count = 2;
        p[0x269] = 0x26;
    }
    handle = func_0205121C(0x4c,member,((struct Obj06215 *)p)->f0);
    W(0x25c) = (u32)func_0203D7C8(((struct Obj06215 *)p)->f0,0x5000,(const char *)d_021BED58,0xea);
    W(0x260) = func_02050C04(W(0x25c),0x5000,0,((struct Obj06215 *)p)->f0);
    func_02051230((u8 *)W(0x260),handle,0,func_020056BC());
    func_021BB3D4(p,(u8 *)(*(int *)(p+W(0x2c)*4+0x160)),(u16 *)(&xy));
    xy.x -= 0x28;
    xy.y += 4;
    if (xy.x > 0) vec[0] = (int)(0.5f+(float)(xy.x<<12))/0x26;
    else vec[0] = (int)((float)(xy.x<<12)-0.5f)/0x26;
    if (xy.y > 0) vec[1] = (int)(0.5f+(float)(xy.y<<12))/0x26;
    else vec[1] = (int)((float)(xy.y<<12)-0.5f)/0x26;
    vec[2] = 0x40000;
    for (i=0;i<count;i++) func_020515B4((void *)W(0x260),i,(int)vec);
}

void func_021BDBE0(unsigned int p)
{
    func_02050DB8(*(u8 * *)&((struct Obj09935 *)p)->f260);
    func_0203D7FC(((struct Obj09935 *)p)->f25C);
}


int func_021BDBF8(char *p)
{
    int r = 0;
    if (func_02017E1C(((struct Obj00009 *)p)->f38, 5, 0) != 0x1E7)
        return 0;
    if (func_02017E1C(((struct Obj00009 *)p)->f38, 6, r) != 0x70)
        return 0;
    if (func_02017E1C(((struct Obj00009 *)p)->f38, 0x6F, r) == 0)
        r = 1;
    return r;
}

/*
 * Extent tail: two bytes of alignment padding at 0x021BDC5A.
 */
void func_021BDC3C(u32 p, void *m)
{
    func_02017988(m, 1);
    func_0200CDE0(*(struct Blk37 **)(((struct Obj20927 *)p)->f280 + 0x18), m);
}
