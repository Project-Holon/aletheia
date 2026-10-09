/*
 * file:     br_codein_p03.c
 * unit:     yes
 * function: func_021E06D0, func_021E0754, func_021E075C, func_021E0764, func_021E0774, func_021E07A4, func_021E0808, func_021E083C, func_021E0840, func_021E08E4, func_021E0954, func_021E0A88, func_021E0C04, func_021E0CE8, func_021E0D00, func_021E0D38, func_021E0D90, func_021E0E40, func_021E0E4C, func_021E0E90, func_021E1008, func_021E10A0, func_021E10BC, func_021E10DC, func_021E10F4
 * address:  0x021E06D0
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_020490F4 0x020490F4 arm
 *   func_021E1244 0x021E1244 thumb ov183
 *   func_021E1910 0x021E1910 thumb ov183
 *   func_020056A0 0x020056A0 thumb
 *   func_021E16E4 0x021E16E4 thumb ov183
 *   d_021E3968 0x021E3968 data ov183
 *   func_02030EAC 0x02030EAC arm
 *   func_02049238 0x02049238 arm
 *   func_02051C6C 0x02051C6C arm
 *   func_020307B0 0x020307B0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02034714 0x02034714 arm
 *   func_02045808 0x02045808 arm
 *   d_021E3974 0x021E3974 data a4
 *   func_021FC124 0x021FC124 thumb ov186
 *   d_021E3978 0x021E3978 data ov183
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_02025538  0x02025538  thumb
 *   func_0202570C 0x0202570C thumb
 *   func_02025588 0x02025588 thumb
 *   func_021E111C 0x021E111C thumb ov183
 */
#include "../../matched/include/Obj03331.h"
#include "../../matched/include/Obj24624.h"
#include "../../matched/include/Obj24625.h"
#include "../../matched/include/Obj10751.h"
#include "../../matched/include/Obj14437.h"
#include "../../matched/include/Obj00143.h"
#include "../../matched/include/Obj08317.h"
#include "../../matched/include/Obj08316.h"
#include "../../matched/include/Obj02895.h"
#include "../../matched/include/Obj14438.h"
#include "../../matched/include/Obj05480.h"
#include "../../matched/include/Obj05481.h"
#include "../../matched/include/Obj24626.h"

struct Node;
struct U16Vec;
struct Obj;
struct Actor;
struct Coordinates;
struct Vec2;
struct PtS;
struct Grid;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32_021E06D0;

typedef unsigned long long u64;

struct Source { int words[10]; };

typedef unsigned int   u32_021E0774;

typedef unsigned int u32_021E07A4;

struct Object { int capacity; int entries[4]; int unused; void *vector; void *a; void *b; void *c; };

typedef unsigned int   u32_021E0808;

struct Triple { int a, b, c; };

typedef unsigned int   u32_021E0840;

typedef unsigned int u32_021E0954;

typedef struct {u16 a,b,c;u8 flag,pad;} Params;

typedef unsigned int u32_021E0A88;

typedef unsigned long u32_021E0C04;

typedef short s16;

struct Params {s16 x,y,a,b,z;u8 mode,flag;};

typedef unsigned int   u32_021E0D00;

struct Coordinates { u8 pad[0x298]; u8 rect[32][4]; };

typedef unsigned int   u32_021E0D38;

typedef unsigned int   u32_021E0D90;

typedef unsigned long u32_021E0E90;

typedef struct {s16 a,b,x,y;} Coords;

typedef unsigned int   u32_021E10DC;

extern void *func_02030734(u32_021E06D0 heapId, u32_021E06D0 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, u32_021E06D0);
extern unsigned func_021FC20C(char *p);
extern void *func_020490F4(u32_021E06D0 id, u32_021E06D0 heap);
extern void func_021E1244(char *);
extern void func_021E1910(char *);
extern void *func_020056A0(void (*)(void), void *, int);
extern int func_021E16E4(char *p);
extern void func_02030EAC(struct Node *n);
extern void func_02049238(void *);
extern void func_02051C6C(void *);
extern u32_021E0774 func_020307B0(void *p);
extern void *func_020457B0(u32_021E07A4, u16);
extern void func_02034714(const char *expr, u32_021E0808 line, const char *file);
extern void func_02045808(struct U16Vec *vec);
extern int func_021FC124(void *, int, struct Triple *);
extern void func_0204B3B4(struct Obj *p);
extern struct Obj *func_0204B294(void *,u32_021E0954,u32_021E0954,u32_021E0954,const void *,u16,u16);
extern void func_0204B688(struct Actor *actor, u32_021E0954 value);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32_021E0A88 v);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32_021E0C04 which);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B8C4(struct Obj *p, u32_021E0D38 value);
extern u16 func_0204B898(struct Obj *p);
extern u32_021E0D90 func_0204B98C(struct Actor *a);
extern void *func_02025538(unsigned int a0, void *a1);
extern void func_0202570C(struct Grid *);
extern void func_02025588(void *);
extern void func_021E111C(const void *,int,int,int,int);
char *func_021E06D0(const struct Source *src, u16 heap);
void func_021E0754(char *p);
int func_021E075C(char *p);
u64 func_021E0764(char *p);
void func_021E0774(char *p);
struct Object *func_021E07A4(int heap, int n, void *a, void *b, void *c, int *entries);
void func_021E0808(char *p);
void func_021E083C(void);
void func_021E0840(char *p);
void func_021E08E4(char *p);
void func_021E0954(char *p);
void func_021E0A88(char *p);
void func_021E0C04(char *p);
void func_021E0CE8(char *p, int index, int a2);
void func_021E0D00(char *p,int i);
void func_021E0D38(struct Coordinates *p, int index);
void func_021E0D90(char *p);
int func_021E0E40(int a, int b);
void func_021E0E4C(char *p);
void func_021E0E90(char *p,int animated);
void func_021E1008(char *p);
void func_021E10A0(char *p);
void func_021E10BC(char *p);
void func_021E10DC(char *p);
void func_021E10F4(char *p);
extern char d_021E3968[];
extern char d_021E3974[];
extern char d_021E3978[];

/*
 * extent: 0754 tail-call stub; 075C state getter; 0764 64-bit getter; 0772 padding.
 */
char *func_021E06D0(const struct Source *src, u16 heap)
{
    char *p;
    p = func_02030734(heap, 0x368, 0, d_021E3968, 56);
    func_02082BCC(p, 0, 0x368);
    *(struct Source *)(p + 0x324) = *src;
    ((struct Obj03331 *)p)->f34C = heap;
    ((struct Obj03331 *)p)->f25C = src->words[7];
    ((struct Obj03331 *)p)->f310 = func_021FC20C((char *)src->words[8]);
    ((struct Obj03331 *)p)->f258 = func_020490F4(59, ((struct Obj03331 *)p)->f34C);
    func_021E1244(p);
    func_021E1910(p);
    ((struct Obj03331 *)p)->f314 = func_020056A0(func_021E083C, p, 16);
    return p;
}

void func_021E0754(char *p)
{
    func_021E16E4(p);
}

int func_021E075C(char *p)
{
    return ((struct Obj24624 *)p)->f350;
}

u64 func_021E0764(char *p)
{
    return ((struct Obj24625 *)p)->f360;
}

void func_021E0774(char *p){func_02030EAC(((struct Obj10751 *)p)->f314);func_021E08E4(p);func_02049238(((struct Obj10751 *)p)->f258);func_02051C6C(((struct Obj10751 *)p)->f294);func_020307B0(p);}

struct Object *func_021E07A4(int heap, int n, void *a, void *b, void *c, int *entries)
{
    int i;
    struct Object *p;
    p = func_02030734((u16)heap, 40, 0, d_021E3968, 192);
    p->a = a;
    p->b = b;
    p->capacity = n;
    p->vector = func_020457B0(n + 1, heap);
    p->c = c;
    for (i = 0; i < 3; i++) p->entries[i] = entries[i];
    p->entries[i] = entries[i - 1];
    return p;
}

/*
 * extent: existing matched callback 021E083C and its alignment follow the pool.
 */
void func_021E0808(char *p){if(!((struct Obj14437 *)p)->f18)func_02034714(d_021E3974,0,d_021E3974);if(!p)func_02034714(d_021E3974,0,d_021E3974);func_02045808(((struct Obj14437 *)p)->f18);func_020307B0(p);}

/*
 * leaf: empty callback solely blocks owned constructor 021E06D0; parent cleared.
 * extent: bx lr at 083C; 083E alignment; existing owned 0840 follows.
 */
void func_021E083C(void)
{
}

void func_021E0840(char *p)
{
    struct Triple t;
    if (!func_021FC124(((struct Obj00143 *)p)->f344, 11, &t)) func_02034714(d_021E3978, 0, d_021E3978);
    ((struct Obj00143 *)p)->f260 = t.c;
    ((struct Obj00143 *)p)->f26C = t.b;
    ((struct Obj00143 *)p)->f284 = t.a;
    if (!func_021FC124(((struct Obj00143 *)p)->f344, 12, &t)) func_02034714(d_021E3978, 0, d_021E3978);
    ((struct Obj00143 *)p)->f268 = t.c;
    ((struct Obj00143 *)p)->f274 = t.b;
    ((struct Obj00143 *)p)->f28C = t.a;
    if (!func_021FC124(((struct Obj00143 *)p)->f344, 6, &t)) func_02034714(d_021E3978, 0, d_021E3978);
    *(int *)&((struct Obj00143 *)p)->f264 = t.c;
    *(int *)&((struct Obj00143 *)p)->f270 = t.b;
    *(int *)&((struct Obj00143 *)p)->f288 = t.a;
}

/*
 * extent: 021E0952 alignment padding.
 */
void func_021E08E4(char *p)
{
    int i;
    for (i = 0; i < ((struct Obj08317 *)p)->f23C; i++) func_0204B3B4(*(void **)(p + i * 28 + 12));
    for (i = 0; i < 2; i++) {
        func_0204B3B4(*(void **)(p + i * 28 + 0x15c));
        func_0204B3B4(*(void **)(p + i * 28 + 0x1e8));
    }
    for (i = 0; i < 3; i++) func_0204B3B4(*(void **)(p + i * 28 + 0x194));
    func_021E10BC(p);
}

/*
 * lever: The explicit entry guard encloses a do-while; a for adds a second entry test (308 B DIFF to 306 B EXACT*).
 * trailing: 021E0A86..021E0A88 is two zero alignment bytes.
 * abi: 0204B294 caller uses returned r0 despite callee's void spelling; fifth payload remains its u32 address word.
 * note 2026-10-05 (wave D9r lane 131): removed the 7 dead first assignments
 * (`heapA=0x25c;` before `heapA=0x34c;`; `aA=0x25c;` before `aA=0x26c;` and
 * 5 more). Game code has no line table, so these were stand-ins. The plain
 * single assignment gives EXACT* in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void func_021E0954(char *p)
{
    int i,special,normal,base;
    u32_021E0954 owner;
    int heapA,aA,bA,cA,heapB,aB,bB,cB,countOffset,recordOffset;
    Params params;
    normal=0;
    base=0x25c;
    owner=*(u32_021E0954 *)(p+base);
    params.a=normal;params.b=normal;params.c=normal;params.flag=10;params.pad=normal;
    special=0;i=0;
    if(*(int *)(p+base-0x20)+2>0) {
        heapA=0x34c;
        aA=0x26c;
        bA=0x260;
        cA=0x284;
        heapB=0x34c;
        aB=0x26c;
        bB=0x260;
        cB=0x284;
        countOffset=0x23c;
        recordOffset=0x150;
        do {
            char *q;
            q=p+special*28;
            if(i==*(int *)(q+recordOffset)+special+1) {
                void *obj;
                params.a=i*8+76;params.b=24;params.c=22;
                obj=func_0204B294((void *)owner,*(u32_021E0954 *)(p+aB),*(u32_021E0954 *)(p+bB),*(u32_021E0954 *)(p+cB),&params,1,*(u16 *)(p+heapB));
                ((struct Obj08316 *)q)->f15C=obj;func_0204B688(obj,1);
                special++;
            } else {
                void *obj;
                params.a=i*8+76;params.b=24;
                q=p+normal*28;
                params.c=func_021E0E40(((struct Obj08316 *)q)->f0,((struct Obj08316 *)q)->f8);
                obj=func_0204B294((void *)owner,*(u32_021E0954 *)(p+aA),*(u32_021E0954 *)(p+bA),*(u32_021E0954 *)(p+cA),&params,1,*(u16 *)(p+heapA));
                ((struct Obj08316 *)q)->fC=obj;func_0204B688(obj,1);
                normal++;
            }
            i++;
        } while(i<*(int *)(p+countOffset)+2);
    }
}

/*
 * abi: 0204B294 r0 consumed after call; pointer request passed as the unchanged u32 fifth payload.
 */
void func_021E0A88(char *p)
{
    int base,zero;
    u32_021E0A88 owner;
    Params params;
    base=0x25c;owner=*(u32_021E0A88 *)(p+base);zero=0;
    params.a=zero;params.b=zero;params.c=zero;params.flag=zero;params.pad=zero;
    *(u32_021E0A88 *)(p+base-0xc8)=(u32_021E0A88)func_0204B294((void *)owner,*(u32_021E0A88 *)(p+base+0x18),*(u32_021E0A88 *)(p+base+0xc),*(u32_021E0A88 *)(p+base+0x30),&params,1,*(u16 *)(p+base+0xf0));
    func_0204B688(*(void **)(p+base-0xc8),1);
    *(u32_021E0A88 *)(p+base-0xac)=(u32_021E0A88)func_0204B294((void *)owner,*(u32_021E0A88 *)(p+base+0x18),*(u32_021E0A88 *)(p+base+0xc),*(u32_021E0A88 *)(p+base+0x30),&params,1,*(u16 *)(p+base+0xf0));
    func_0204B688(*(void **)(p+base-0xac),1);
    *(u32_021E0A88 *)(p+base-0x90)=(u32_021E0A88)func_0204B294((void *)owner,*(u32_021E0A88 *)(p+base+0x18),*(u32_021E0A88 *)(p+base+0xc),*(u32_021E0A88 *)(p+base+0x30),&params,1,*(u16 *)(p+base+0xf0));
    func_0204B688(*(void **)(p+base-0x90),1);
    func_021E0D00(p,0);
    func_0204B878(*(void **)(p+base-0xc8),0);func_0204B92C(*(void **)(p+base-0xc8),1);
    *(u16 *)(p+base-0xa4)=zero;*(u16 *)(p+base-0xa2)=zero;*(u32_021E0A88 *)(p+base-0xb8)=1;
    func_021E0D38((struct Coordinates *)p,0);
    func_0204B878(*(void **)(p+base-0xac),*(u32_021E0A88 *)(p+base-0xb8));
    func_0204B92C(*(void **)(p+base-0xac),1);func_0204B688(*(void **)(p+base-0xac),1);
    *(u16 *)(p+base-0x88)=zero;*(u16 *)(p+base-0x86)=zero;*(u32_021E0A88 *)(p+base-0x9c)=1;
    func_021E0D38((struct Coordinates *)p,zero);
    func_0204B878(*(void **)(p+base-0x90),*(u32_021E0A88 *)(p+base-0x9c));
    func_0204B688(*(void **)(p+base-0x90),1);func_0204B92C(*(void **)(p+base-0x90),1);
    func_021E0CE8(p,1,zero);func_021E0CE8(p,2,zero);
}

/*
 * Caller evidence: 0204B294 leaves its forwarded return word live in r0; consumed by store and 0204B688 here.
 */
void func_021E0C04(char *p) {
    struct Params pos;
    u32_021E0C04 manager=*(u32_021E0C04 *)&((struct Obj00143 *)p)->f25C;
    pos.a=0;pos.b=0;pos.z=0;pos.mode=10;pos.flag=0;
    *(u32_021E0C04 *)&((struct Obj00143 *)p)->f1E8=(u32_021E0C04)func_0204B294((void *)manager,((struct Obj00143 *)p)->f270,((struct Obj00143 *)p)->f264,((struct Obj00143 *)p)->f288,&pos.a,1,((struct Obj00143 *)p)->f34C);
    func_0204B688(((struct Obj00143 *)p)->f1E8,1);
    pos.z=1;
    *(u32_021E0C04 *)&((struct Obj00143 *)p)->f204=(u32_021E0C04)func_0204B294((void *)manager,((struct Obj00143 *)p)->f270,((struct Obj00143 *)p)->f264,((struct Obj00143 *)p)->f288,&pos.a,1,((struct Obj00143 *)p)->f34C);
    func_0204B688(((struct Obj00143 *)p)->f204,1);
    pos.x=((struct Obj00143 *)p)->f2F2;pos.y=((struct Obj00143 *)p)->f2F0+16;
    func_0204B404(((struct Obj00143 *)p)->f1E8,(const struct Vec2 *)(&pos.x),1);
    func_0204B878(((struct Obj00143 *)p)->f1E8,0);
    pos.x=((struct Obj00143 *)p)->f2F6;pos.y=((struct Obj00143 *)p)->f2F4+16;
    func_0204B404(((struct Obj00143 *)p)->f204,(const struct Vec2 *)(&pos.x),1);
    func_0204B878(((struct Obj00143 *)p)->f204,1);
}


void func_021E0CE8(char *p, int index, int a2)
{
    func_0204B3DC((struct Obj *)*(int *)(p + index * 0x1c + 0x194), (unsigned int)a2);
}

void func_021E0D00(char *p,int i){short pos[2];void *obj;obj=*(void **)(p+i*28+12);((struct Obj02895 *)p)->f188=i;func_0204B454(obj,(struct PtS *)pos,1);pos[1]+=16;func_0204B404(((struct Obj02895 *)p)->f194,(const struct Vec2 *)pos,1);}

/*
 * extent: 021E0D8E alignment padding.
 */
void func_021E0D38(struct Coordinates *p, int index)
{
    int width = p->rect[index + 12][1] - p->rect[index + 12][0];
    int height = p->rect[index + 12][3] - p->rect[index + 12][2];
    s16 pos[2];
    pos[0] = height / 2 + p->rect[index + 12][2];
    pos[1] = width / 2 + p->rect[index + 12][0];
    func_0204B404(((struct Obj02895 *)p)->f1B0, (const struct Vec2 *)pos, 1);
    func_0204B8C4(((struct Obj02895 *)p)->f1B0, 0);
}

/*
 * extent: 021E0E3E alignment padding.
 */
void func_021E0D90(char *p)
{
    int i, state;
    for (i = 1; i < 3; i++) {
        state = func_0204B898(*(void **)(p + i * 28 + 0x194));
        if (state == 3) {
            if (!func_0204B98C(*(void **)(p + i * 28 + 0x194))) {
                func_0204B878(*(void **)(p + i * 28 + 0x194), *(int *)(p + i * 28 + 0x188));
                if (((struct Obj14438 *)p)->f2FC == 1) func_021E0CE8(p, 1, 0);
                else func_021E0CE8(p, 1, 1);
                func_021E0CE8(p, 2, 0);
            }
        } else {
            if (state != *(int *)(p + i * 28 + 0x188)) func_0204B878(*(void **)(p + i * 28 + 0x194), *(int *)(p + i * 28 + 0x188));
            if (func_0204B898(*(void **)(p + i * 28 + 0x194)) != 3) {
                if (((struct Obj14438 *)p)->f2FC == 1) func_021E0CE8(p, 1, 0);
                else func_021E0CE8(p, 1, 1);
            }
        }
    }
}

int func_021E0E40(int a, int b) { int n=0; if(b==0)n=11; return n+a; }

void func_021E0E4C(char *p)
{
    int i;
    for (i = 0; i < ((struct Obj00143 *)p)->f23C; i++) {
        if (i >= ((struct Obj00143 *)p)->f248 && i < ((struct Obj00143 *)p)->f24C)
            *(int *)(p + i * 28 + 8) = 1;
        else
            *(int *)(p + i * 28 + 8) = 0;
    }
}

void func_021E0E90(char *p,int animated) {
    int i,group;
    s16 pos;
    char *record,*special;
    Coords coords;
    pos=*(s16 *)((u32_021E0E90)p+((struct Obj00143 *)p)->f240*2+0x214);
    group=0;
    for(i=0;i<((struct Obj00143 *)p)->f23C;i++){
        if(i>=((struct Obj00143 *)p)->f248&&i<((struct Obj00143 *)p)->f24C){
            if(i==((struct Obj00143 *)p)->f248)pos+=20;else pos+=32;
        }else{
            if(i==0)pos+=20;else pos+=8;
        }
        record=(char *)((u32_021E0E90)p+i*28);
        func_0204B454(((struct Obj05480 *)record)->fC,(struct PtS *)&coords.x,1);
        if(animated==0){
            coords.x=pos;
            func_0204B404(((struct Obj05480 *)record)->fC,(const struct Vec2 *)(&coords.x),1);
        }else{
            ((struct Obj05480 *)record)->f14=(pos-coords.x)/4;
            ((struct Obj05480 *)record)->f16=0;
            ((struct Obj05480 *)record)->f18=4;
            ((struct Obj05480 *)record)->f19=0;
        }
        special=(char *)((u32_021E0E90)p+group*28);
        if(i==((struct Obj05481 *)special)->f150&&group!=2){
            func_0204B454(((struct Obj05481 *)special)->f15C,(struct PtS *)&coords.a,1);
            if(((struct Obj00143 *)p)->f248==((struct Obj00143 *)p)->f24C)pos+=8;
            else {
                if(i>((struct Obj00143 *)p)->f248&&i<((struct Obj00143 *)p)->f24C)pos+=20;
                else pos+=8;
            }
            if(animated==0){
                coords.a=pos;
                func_0204B404(((struct Obj05481 *)special)->f15C,(const struct Vec2 *)(&coords.a),1);
            }else{
                ((struct Obj05481 *)special)->f164=(pos-coords.a)/4;
                ((struct Obj05481 *)special)->f166=0;
                ((struct Obj05481 *)special)->f168=4;
            }
            group++;
        }
    }
}

void func_021E1008(char *p)
{
    int i, x, y;
    s16 pos[2];
    for (i = 0; i < ((struct Obj00143 *)p)->f23C; i++) {
        if (i >= ((struct Obj00143 *)p)->f248 && i < ((struct Obj00143 *)p)->f24C) {
            x = 16;
            y = 16;
        } else {
            x = 4;
            y = 8;
        }
        func_0204B454(*(void **)(p + i * 28 + 12), (struct PtS *)pos, 1);
        (*(u8 **)(p + i * 28 + 16))[0] = pos[1] - y;
        (*(u8 **)(p + i * 28 + 16))[2] = pos[0] - x;
        (*(u8 **)(p + i * 28 + 16))[1] = pos[1] + y;
        (*(u8 **)(p + i * 28 + 16))[3] = pos[0] + x;
    }
}


void func_021E10A0(char *p)
{
    ((struct Obj00143 *)p)->f300 =
        func_02025538(((struct Obj00143 *)p)->f34C, ((struct Obj00143 *)p)->f25C);
}

void func_021E10BC(char *p){ func_0202570C(*(struct Grid * *)&((struct Obj08317 *)p)->f304); func_0202570C(*(struct Grid * *)&((struct Obj08317 *)p)->f308); func_02025588(((struct Obj08317 *)p)->f300); }


void func_021E10DC(char *p)
{
    func_02049238(func_020490F4(0x17, ((struct Obj24626 *)p)->f34C));
}

void func_021E10F4(char *p){ func_021E10DC(p);func_021E111C(p,0,32,8,0);func_021E111C(p,1,32,8,0); }
