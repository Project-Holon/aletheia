/*
 * file:     mystery_net_p06.c
 * unit:     yes
 * function: func_021DE5D8, func_021DE5F8, func_021DE618, func_021DE61C, func_021DE690, func_021DE6F8, func_021DE70C, func_021DE7BC, func_021DE7FC, func_021DE830, func_021DE8D0, func_021DE910, func_021DE958, func_021DEDC8, func_021DEE14, func_021DEE38, func_021DEE68, func_021DEE84, func_021DEE90, func_021DEEA4, func_021DEEAC, func_021DEED0, func_021DEEF8, func_021DEF38, func_021DEF54, func_021DEF6C
 * address:  0x021DE5D8
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FBB0 0x0200FBB0 thumb
 *   func_0200F83C 0x0200F83C thumb
 *   func_0200FBA0 0x0200FBA0 thumb
 *   func_0203CBAC 0x0203CBAC arm
 *   func_02043598 0x02043598 arm
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_02010360 0x02010360 thumb
 *   func_0203D010 0x0203D010 arm
 *   d_021DFABC 0x021DFABC data a4
 *   func_020103E4 0x020103E4 thumb
 *   func_0203CEAC 0x0203CEAC arm
 *   func_02010498  0x02010498  thumb
 *   func_0201058C  0x0201058C  thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_021576D0 0x021576D0 thumb ov010
 *   func_021578A0 0x021578A0 thumb ov010
 *   d_0209DF0C 0x0209DF0C data
 *   func_02157938 0x02157938 thumb ov010
 *   func_0203D210 0x0203D210 arm
 *   func_02157928 0x02157928 thumb ov010
 *   func_02157910 0x02157910 thumb ov010
 *   func_02157DD8 0x02157DD8 thumb ov010
 *   func_02157E34 0x02157E34 thumb ov010
 *   func_02157E8C 0x02157E8C thumb ov010
 *   func_02157E78 0x02157E78 thumb ov010
 *   func_02157E6C 0x02157E6C thumb ov010
 *   func_02156DE0 0x02156DE0 thumb ov009
 *   func_021C5928 0x021C5928 arm ov114
 *   func_021C5C04 0x021C5C04 arm ov114
 *   func_021C5C38 0x021C5C38 arm ov114
 *   func_021C5CFC 0x021C5CFC arm ov114
 *   func_021C5AB8 0x021C5AB8 arm ov114
 *   func_021C5E14 0x021C5E14 arm ov114
 *   func_021C5DB4 0x021C5DB4 arm ov114
 *   func_0203F0A8 0x0203F0A8 arm
 *   func_0203C9AC 0x0203C9AC arm
 *   _ull_mul 0x0209C054 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021DFBD8 0x021DFBD8 data a4
 *   d_021DFBD0 0x021DFBD0 data a4
 *   d_021DFBF8 0x021DFBF8 data a4
 *   d_021DFBEC 0x021DFBEC data a4
 *   d_021DFC00 0x021DFC00 data a4
 *   func_021C5B80 0x021C5B80 arm ov114
 *   d_021DFA8C 0x021DFA8C data a1
 *   func_02045A98 0x02045A98 arm
 *   func_021DEFAC 0x021DEFAC thumb ov121
 */
#include "../../matched/include/Obj10424.h"
#include "../../matched/include/Obj08100.h"
#include "../../matched/include/Obj22915.h"
#include "../../matched/include/Obj08101.h"
#include "../../matched/include/Obj22916.h"
#include "../../matched/include/Obj10427.h"
#include "../../matched/include/Obj06455.h"
#include "../../matched/include/Obj22917.h"
#include "../../matched/include/Obj08102.h"
#include "../../matched/include/Obj22918.h"
#include "../../matched/include/Obj08104.h"
#include "../../matched/include/Obj22920.h"
#include "../../matched/include/Obj13960.h"
#include "../../matched/include/Obj22922.h"
#include "../../matched/include/Obj22925.h"

#define Q(k) (*(u32 *)(q+(k)))
#define W(k) (*(u32 *)(p+(k)))
struct Req;
struct Rec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 kind;u8 flag,pad;u16 heap;u32 bytes;void *data;u32 lang,align;u8 reserved[96];u32 last;} Config;

typedef struct Descriptor {
    int kind;
    u16 zero, heap;
    int size;
    void *data;
    int setting;
    int flags;
    u8 pad[0x60];
    int enabled;
} Descriptor;

typedef unsigned long long u64;

typedef struct { char pad[0x6e0];u32 flag; } Flag;

typedef enum { NO_DIGIT = -1 } Digit;

extern u32 func_0200FB24(void);
extern u32 func_0200FBB0(void);
extern void func_0200F83C(void),func_0200FBA0(void);
extern void func_0203CBAC(struct Req *req, unsigned int a2, unsigned int a3);
extern void func_02043598(u32 mask, u32 enable);
extern int func_0203CD98(void);
extern void func_0203D34C(unsigned, unsigned);
extern u8 *func_02010360(int idx, void *heap);
extern void func_0203D010(void);
extern void func_020103E4(u8 *p);
extern int func_0203CEAC(int);
extern void func_02010498(void);
extern u32 func_0201058C(void *key);
extern void func_02082BCC(void *,int,u32);
extern void *func_021576D0(u8 *p);
extern int func_021578A0(u32 *);
extern int func_02157938(void *a0);
extern unsigned func_0203D210(void);
extern void func_02157928(u8 *);
extern int func_02157910(u8 *);
extern void *func_02157DD8(u8 *p);
extern int func_02157E34(void *);
extern int func_02157E8C(void *a0);
extern void func_02157E78(u8 *p);
extern unsigned char func_02157E6C(char *p);
extern void func_02156DE0(int,int);
extern int func_021C5928(void (*callback)(int, int, int), char *gamecd, char *passwd);
extern int func_021C5C04(char *,char *,char *);
extern int func_021C5C38(void *,u32,u32);
extern int func_021C5CFC(void *,char *,u32);
extern void func_021C5AB8(void);
extern int func_021C5E14(u32 *,u32 *);
extern int func_021C5DB4(void);
extern u32 func_0203F0A8(void);
extern void func_0203C9AC(int,u32,u32,u32);
extern int func_021C5B80(void);
extern unsigned short func_02045A98(void);
extern int func_021DEFAC(struct Rec *r, void *gs, u16 heap);
int func_021DE5D8(void *a0);
int func_021DE5F8(void *a0);
void func_021DE618(void);
void func_021DE61C(void *a, int *state, char *p);
void func_021DE690(void *a, int *state, char *p);
void func_021DE6F8(int a, int b, char *c);
void func_021DE70C(void *a,int *state,char *p);
void func_021DE7BC(void *a, int *state, char *p);
void func_021DE7FC(void *a,int b,char *p);
void func_021DE830(void *a, int *state, char *p);
void func_021DE8D0(void *a, int *state, char *p);
void func_021DE910(void *a, int *state, char *p);
void func_021DE958(void *task,int *state,char *p);
void func_021DEDC8(void *a, int *state, char *p);
void func_021DEE14(char *p, int *state, int value);
void func_021DEE38(u32 p,int a,int *state,int b,int c);
void func_021DEE68(void *p, int a, void *b);
void func_021DEE84(void *p);
void func_021DEE90(char *p);
void func_021DEEA4(u32 *p,void *f);
int func_021DEEAC(int *p, int value);
void *func_021DEEBC(char *p);
int func_021DEEC0(void);
int func_021DEEC4(int a, int b);
void func_021DEED0(char *p);
void func_021DEED8(int a, int b);
void func_021DEEEC(void);
int func_021DEEF8(const signed char *p);
int func_021DEF38(const unsigned *p, unsigned size);
int func_021DEF54(char *p, int unused, int type);
int func_021DEF6C(char *p, void *a, unsigned short b);
extern unsigned d_021DFABC[];
extern u8 d_0209DF0C;
extern char d_021DFBD8[],d_021DFBD0[],d_021DFBF8[],d_021DFBEC[];
extern int d_021DFC00[];
extern const signed char d_021DFA8C[][2];

int func_021DE5D8(void *a0) {int r=0; if(func_0200FB24()) {func_0200FBB0();func_0200F83C();func_0200FBA0();r=1;} return r;}

int func_021DE5F8(void *a0) {int r=0; if(func_0200FB24()) {func_0200FBB0();func_0200F83C();func_0200FBA0();r=1;} return r;}

/*
 * extent: empty callback followed by zero alignment padding then labelled 021DE61C.
 */
void func_021DE618(void) {}

void func_021DE61C(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        func_0203CBAC((struct Req *)d_021DFABC, 0, (unsigned)p);
        func_02043598(0x10, 0);
        *state = 1;
        break;
    case 1:
        if (func_0203CD98()) {
            func_0203D34C(1, ((struct Obj10424 *)p)->f58);
            ((struct Obj10424 *)p)->f10 = func_02010360(4, (void *)(((struct Obj10424 *)p)->f58));
            func_0203D010();
            *state = 2;
        }
        break;
    case 2:
        func_02043598(0x10, 1);
        func_021DEEA4(a, func_021DE6F8);
        break;
    }
}

void func_021DE690(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        func_020103E4(((struct Obj08100 *)p)->f10);
        *(int *)&((struct Obj08100 *)p)->f10 = 0;
        *state = 1;
        break;
    case 1:
        if (func_0203CEAC((int)func_021DEED0)) *state = 2;
        else *state = 3;
        break;
    case 2:
        if (((struct Obj08100 *)p)->f5C) {
            ((struct Obj08100 *)p)->f5C = 0;
            *state = 3;
        }
        break;
    case 3:
        func_021DEEA4(a, func_021DE618);
        break;
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_021DE6F8(int a, int b, char *c)
{
    func_02010498();
    ((struct Obj22915 *)c)->f54 = func_0201058C(0);
}

void func_021DE70C(void *a,int *state,char *p) {Config cfg;u32 h; switch(*state) {case 0: func_02082BCC(&cfg,0,124);cfg.kind=9;cfg.bytes=720;cfg.data=p+1956;cfg.lang=d_0209DF0C;cfg.align=2097152;cfg.last=1;cfg.flag=0;cfg.heap=((struct Obj08101 *)p)->f58;h=(u32)func_021576D0((u8 *)(&cfg));((struct Obj08101 *)p)->f798=h;func_021578A0((u32 *)h);func_02043598(16,0);((struct Obj08101 *)p)->f17A4=0;*state=1;break;case 1:if(func_0203CD98()) {func_0203D34C(1,((struct Obj08101 *)p)->f58);func_02043598(16,1);*state=2;}break;case 2:func_021DEEA4(a,func_021DE7FC);break;} }

void func_021DE7BC(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        func_02157938((void *)(((struct Obj22916 *)p)->f798));
        *state = 1;
        break;
    case 1:
        if (func_0203D210()) *state = 2;
        break;
    case 2:
        func_021DEEA4(a, func_021DE618);
        break;
    }
}

void func_021DE7FC(void *a,int b,char *p) {func_02157928(*(u8 * *)&((struct Obj10427 *)p)->f798);if(func_02157910(*(u8 * *)&((struct Obj10427 *)p)->f798)) {((struct Obj10427 *)p)->f17A4=1;func_021DEEA4(a,func_021DE7BC);}}

void func_021DE830(void *a, int *state, char *p)
{
    Descriptor d;
    switch (*state) {
    case 0:
        func_02082BCC(&d, 0, 0x7c);
        d.kind = 9;
        d.size = 0x2d0;
        d.data = p + 0x7a4;
        d.zero = 0;
        d.heap = ((struct Obj06455 *)p)->f58;
        d.setting = d_0209DF0C;
        d.enabled = 1;
        d.flags = 0x200000;
        ((struct Obj06455 *)p)->f79C = func_02157DD8((u8 *)(&d));
        func_02157E34(((struct Obj06455 *)p)->f79C);
        ((struct Obj06455 *)p)->f17A4 = 0;
        *state = 1;
        break;
    case 1:
        if (func_0203CD98()) {
            func_0203D34C(1, ((struct Obj06455 *)p)->f58);
            *state = 2;
        }
        break;
    case 2:
        func_021DEEA4(a, func_021DE910);
        break;
    }
}

void func_021DE8D0(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        func_02157E8C((void *)(((struct Obj22917 *)p)->f79C));
        *state = 1;
        break;
    case 1:
        if (func_0203D210()) *state = 2;
        break;
    case 2:
        func_021DEEA4(a, func_021DE618);
        break;
    }
}

void func_021DE910(void *a, int *state, char *p)
{
    int result;
    func_02157E78(((struct Obj08102 *)p)->f79C);
    result = func_02157E6C(((struct Obj08102 *)p)->f79C);
    if (result != 0) {
        switch (result) {
        case 1: ((struct Obj08102 *)p)->f17A4 = 1; break;
        case 2:
        case 3: ((struct Obj08102 *)p)->f17A4 = 2; break;
        }
        func_021DEEA4(a, func_021DE8D0);
    }
}

void func_021DE958(void *task,int *state,char *p)
{
    char *q=p+0x60;
    int i,n,j,valid;
    u32 rnd,t,ratio;
    switch(*state) {
    case 0:
        func_02156DE0((int)func_021DEF54,(int)q);
        func_02082BCC(q,0,0x734);
        Q(0x70c)=0;Q(0x710)=0;Q(0x724)=0;Q(0x728)=(u32)(p+0x7a4);
        W(0x17a4)=0;
        if(!func_021C5928((void (*)(int,int,int))func_021DEED8,d_021DFBD0,d_021DFBD8)) {
            W(0x17a4)=2;*state=9;
        } else {Q(0x730)=1;func_021DEE14(q,state,1);}
        break;
    case 1:
        if(Q(0x710)) {W(0x17a4)=2;func_021DEE38((u32)q,3,state,7,7);}
        else if(!func_021C5C04(d_021DFBEC,d_021DFBF8,d_021DFBF8)) {
            W(0x17a4)=2;func_021DEE38((u32)q,4,state,9,9);
        } else *state=3;
        break;
    case 3:
        if(!func_021C5C38(q,0,10)) {W(0x17a4)=2;func_021DEE38((u32)q,4,state,9,9);}
        else func_021DEE14(q,state,2);
        break;
    case 2:
        for(i=0;i<10;i++) {
            if(!func_021DEF38((const unsigned *)(q+0xb0*i),0xb0)) {
                if(func_021DEEF8((const signed char *)(q+0xb0*i+0x93))&0x200000)
                    ((Flag *)((u32)q+(u32)i*4))->flag=1;
                else ((Flag *)((u32)q+(u32)i*4))->flag=0;
            } else ((Flag *)((u32)q+(u32)i*4))->flag=0;
        }
        Q(0x714)=0;
        for(i=0;i<10;i++) if(((Flag *)((u32)q+(u32)i*4))->flag) Q(0x714)++;
        *state=4;break;
    case 4:
        n=Q(0x714);
        if(n==1) {
            for(i=0;i<10;i++) if(((Flag *)((u32)q+(u32)i*4))->flag) {Q(0x724)=i;break;}
        } else if(n>1) {
            j=0;rnd=func_0203F0A8();
            if(n) rnd=(u32)(((u64)rnd*(u32)n)>>32);
            for(i=0;i<10;i++) {
                if(((Flag *)((u32)q+(u32)i*4))->flag) {
                    if(j==rnd) {Q(0x724)=i;break;}
                    j++;
                }
            }
            Q(0x724)=i;
        } else {W(0x17a4)=2;func_021DEE38((u32)q,1,state,8,8);break;}
        *state=5;break;
    case 5:
        if(!func_021C5CFC(q+Q(0x724)*0xb0,(char *)Q(0x728),0x1000)) {
            W(0x17a4)=2;func_021DEE38((u32)q,4,state,9,9);
        } else {
            Q(0x718)=0;d_021DFC00[1]=0;d_021DFC00[3]=0;Q(0x72c)=0;*state=6;
        }break;
    case 6:
        func_021C5AB8();
        if(Q(0x72c)++>7200) {
            func_0203C9AC(0,0,0,0x3f5);W(0x17a4)=2;func_021DEE38((u32)q,3,state,7,7);
        }
        if(!d_021DFC00[1]) {
            if(Q(0x70c)) {W(0x17a4)=2;func_021DEE38((u32)q,3,state,7,7);break;}
            if(func_021C5E14((u32 *)(q+0x71c),(u32 *)(q+0x720))==1) {
                ratio=Q(0x71c)*100/Q(0x720);
                if(Q(0x718)!=ratio) Q(0x718)=ratio;
            }
        } else if(d_021DFC00[3]) {W(0x17a4)=2;func_021DEE38((u32)q,4,state,9,9);}
        else if(!Q(0x710)) {W(0x17a4)=1;func_021DEE38((u32)q,1,state,8,8);}
        else {W(0x17a4)=2;func_021DEE38((u32)q,3,state,8,8);}
        break;
    case 7:func_021C5DB4();*state=8;break;
    case 8:*state=9;break;
    case 9:Q(0x730)=0;func_02156DE0(0,0);func_021DEEA4(task,func_021DEDC8);break;
    case 100:
        func_021C5AB8();
        if(Q(0x72c)++>7200) {
            func_0203C9AC(0,0,0,0x3f5);W(0x17a4)=2;func_021DEE38((u32)q,3,state,9,9);
        }
        if(d_021DFC00[1]) {
            d_021DFC00[1]=0;
            if(d_021DFC00[3]) {W(0x17a4)=2;func_021DEE38((u32)q,3,state,9,9);}
            else *state=Q(0x708);
        } else if(Q(0x70c)) Q(0x710)=1;
        break;
    case 200:
        func_021C5AB8();
        if(Q(0x72c)++>7200) {func_0203C9AC(0,0,0,0x3f5);*state=Q(0x708);}
        if(d_021DFC00[0]) {d_021DFC00[0]=0;*state=Q(0x708);}
        else if(Q(0x70c)) Q(0x710)=1;
        break;
    }
}

/*
 * extent: Follower 021DEE14 is filed separately and verified.
 */
void func_021DEDC8(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        if (func_0203CEAC(0)) *state = 1;
        else *state = 2;
        break;
    case 1:
        if (func_0203CD98() == 0) {
            ((struct Obj22918 *)p)->f5C = 0;
            *state = 2;
        }
        break;
    case 2:
        func_021DEEA4(a, func_021DE618);
        break;
    }
}

void func_021DEE14(char *p, int *state, int value)
{
    d_021DFC00[1] = 0;
    d_021DFC00[3] = 0;
    ((struct Obj08104 *)p)->f708 = value;
    ((struct Obj08104 *)p)->f72C = 0;
    *state = 100;
}

void func_021DEE38(u32 p,int a,int *state,int b,int c) {d_021DFC00[0]=0;d_021DFC00[3]=a;((struct Obj08104 *)p)->f708=b;((struct Obj08104 *)p)->f72C=0;*state=200;if(func_021C5B80()==0)*state=c;}


void func_021DEE68(void *p, int a, void *b)
{
    func_02082BCC(p, 0, 0x10);
    ((struct Obj22920 *)p)->fC = (u32)a;
    func_021DEEA4(p, b);
}

void func_021DEE84(void *p) {func_02082BCC(p,0,16);}


void func_021DEE90(char *p)
{
    if (((struct Obj13960 *)p)->f4 == 0)
        (*(void (**)(char *, char *, u32))p)(p, p + 8, ((struct Obj13960 *)p)->fC);
}

void func_021DEEA4(u32 *p,void *f) {p[0]=(u32)f;p[2]=0;}

int func_021DEEAC(int *p, int value)
{
    return *p == value;
}

void *func_021DEEBC(char *p)
{
    return p + 0x14;
}

int func_021DEEC0(void)
{
    return 0x20;
}

int func_021DEEC4(int a, int b)
{
    return a == b;
}

void func_021DEED0(char *p)
{
    ((struct Obj22922 *)p)->f5C = 1;
}

void func_021DEED8(int a, int b)
{
    d_021DFC00[1] = 1;
    d_021DFC00[3] = b;
    func_021DEEEC();
}

void func_021DEEEC(void)
{
    d_021DFC00[0] = 1;
}

/*
 * lever: Assign the sentinel before the signed-byte load to retain movs/mvns.
 */
int func_021DEEF8(const signed char *p)
{
    unsigned i;
    Digit digit;
    int result;
    int value;
    result = 0;
    for (;;) {
        digit = NO_DIGIT;
        value = *p;
        for (i = 0; i < 23; i++) {
            if (value == d_021DFA8C[i][0]) {
                digit = d_021DFA8C[i][1];
                break;
            }
        }
        if (digit == -1) break;
        result = (result << 4) + digit;
        p++;
    }
    return result;
}

/*
 * extent: Next follower 021DEF54 has its own file.
 */
int func_021DEF38(const unsigned *p, unsigned size)
{
    unsigned i;
    for (i = 0; i < size / 4; i++) {
        if (p[i] != 0) return 0;
    }
    return 1;
}

/*
 * extent: Ends at labelled function 021DEF6C.
 */
int func_021DEF54(char *p, int unused, int type)
{
    switch (type) {
    case 3:
    case 5:
    case 6:
        return ((struct Obj22925 *)p)->f730;
    }
    return 0;
}

int func_021DEF6C(char *p, void *a, unsigned short b)
{
    int count = 0;
    int found = 1;
    int i;
    for (i = 0; i < 253; i++) {
        if (*(unsigned short *)(p + i * 2 + 0xd0) == func_02045A98()) found = 0;
    }
    if (found) count++;
    return count + func_021DEFAC((struct Rec *)p, a, b);
}
