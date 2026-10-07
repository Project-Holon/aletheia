/*
 * file:     br_codein_p22.c
 * unit:     yes
 * function: func_021E009C, func_021E00D8, func_021E0214, func_021E024C, func_021E02F8, func_021E037C, func_021E03B0, func_021E04C8, func_021E050C, func_021E05C4, func_021E0618
 * address:  0x021E009C
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
 *   func_021FFC9C 0x021FFC9C thumb ov186
 *   func_021FFE90 0x021FFE90 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F898 0x0201F898 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02012944 0x02012944 thumb
 *   func_0200856C 0x0200856C thumb
 *   func_02008570 0x02008570 thumb
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_02045EC0 0x02045EC0 arm
 *   func_02025B64 0x02025B64 thumb
 *   func_0201F048 0x0201F048 thumb
 *   func_0201F094 0x0201F094 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_021FC8C8 0x021FC8C8 thumb ov186
 *   func_02082BCC 0x02082BCC arm
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   d_021E3780 0x021E3780 data a4
 *   d_021E372E 0x021E372E data a4
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FCC80 0x021FCC80 thumb ov186
 *   func_0201F868 0x0201F868 thumb
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FCD0C 0x021FCD0C thumb ov186
 *   func_021FCDA8 0x021FCDA8 thumb ov186
 *   func_02035D20 0x02035D20 arm
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC868 0x021FC868 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   d_021E37D8 0x021E37D8 data ov183
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FC7C4 0x021FC7C4 thumb ov186
 *   d_020A7370 0x020A7370 data a4
 *   g_021E3808     0x021E3808  data  ov183
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021E07A4 0x021E07A4 thumb ov183
 *   func_021E06D0 0x021E06D0 thumb ov183
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_021E0774 0x021E0774 thumb ov183
 *   func_021E0808 0x021E0808 thumb ov183
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_020315D4 0x020315D4 arm
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021E0754 0x021E0754 thumb ov183
 *   func_021E075C 0x021E075C thumb ov183
 *   func_021E0764 0x021E0764 thumb ov183
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021F9BF4 0x021F9BF4 thumb ov186
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FD854 0x021FD854 thumb ov186
 */
#include "../../matched/include/Obj00277.h"
#include "../../matched/include/Obj00351.h"
#include "../../matched/include/Obj02231.h"
#include "../../matched/include/Obj03330.h"
#include "../../matched/include/Obj04574.h"
#include "../../matched/include/Obj24622.h"
#include "../../matched/include/Obj01765.h"
#include "../../matched/include/Obj24623.h"
#include "../../matched/include/Obj01767.h"
#include "../../matched/include/Obj04576.h"

struct MsgBank;
struct Sub0200852CObj;
struct U16Vec;
struct WordSet;
struct Object;
struct Obj24810;
struct Obj0203159C;
struct Source;
struct PrintSys;
struct S020315D4;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char u8;

typedef struct {u32 words[10];} Config;

typedef struct {int a,b,c;} Triple;

typedef struct {u16 a,b,c;u8 flag,pad;} Params;

typedef struct {u8 a,b,c,d;u16 file;} Record;

typedef struct Slot Slot;

struct Record { u8 a, b, c, d; int value; };

typedef struct Rect { unsigned int x0, y0, x1, y1; } Rect;

struct Data { void *a, *b, *c, *d; u16 heap; u16 pad; void *e; };

typedef unsigned long long u64;

extern int func_021FFC9C(char *);
extern int func_021FFE90(int *, u16 *);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern Slot *func_0201F81C(u32,u32);
extern void func_0201F898(struct Slot *table, u32 a, u32 b, u32 tag);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u8 *func_02012944(void *p);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern int func_021FC21C(char *);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u8 func_02025B64(u32);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void *func_021FC8C8(Config *,u32);
extern void func_02082BCC(void *,u32,u32);
extern int func_021FC124(int,int,Triple *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
extern void func_021FB494(char *p);
extern void func_021FCC80(char *p);
extern u32 func_0201F868(void *p);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_020409B4(u32 index);
extern void func_021FCD0C(char *p);
extern int func_021FCDA8(char *p);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021FB4B4(unsigned int *obj, int x, int y);
extern void func_021FD860(int, int, int *);
extern void *func_021FC6A4(unsigned short plane, unsigned a, unsigned short b, unsigned short c, unsigned char d, unsigned char e, void *owner, unsigned short heap);
extern void func_021FC868(u8 *p, u32 a, u32 b, u32 c);
extern void func_021FC754(char *p, void *a, void *b, void *font, unsigned short value);
extern void func_021FC734(u8 *p);
extern void func_021FC7C4(char *,void *,void *,u16);
extern unsigned func_021F9B9C(struct Obj24810 *p);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_021FBE54(char *, unsigned int, unsigned int);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern struct Object *func_021E07A4(int heap, int n, void *a, void *b, void *c, int *entries);
extern char *func_021E06D0(const struct Source *src, u16 heap);
extern u32 func_0201C440(void *p);
extern void *func_021FD12C(int, void *, u16);
extern void func_021FD170(char *p, char *q, void *text);
extern void func_021FD15C(void *p, int a1);
extern void func_021E0774(char *p);
extern void func_021E0808(char *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_021FD820(char *r5);
extern void func_021FC0C8(char *p, unsigned i);
extern void func_020315D4(struct S020315D4 *p);
extern void func_021FE784(int, int, int, int);
extern int func_021FE7B0(int *);
extern void func_021E0754(char *p);
extern int func_021E075C(char *p);
extern unsigned long long func_021E0764(char *p);
extern void func_021F9BA0(unsigned *ctx);
extern void func_021F9BF4(unsigned *ctx, unsigned index);
extern void func_021FD1BC(void *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021FD854(char *p);
int func_021E009C(char *p, char *q);
int func_021E00D8(char *p,char *q);
int func_021E0214(char *p, char *q);
int func_021E024C(char *p, char *q);
void func_021E02F8(char *p, int *q);
void func_021E037C(char *p,char *q);
void func_021E03B0(char *p,char *q,int mode);
int func_021E04C8(void);
int func_021E050C(void *task, int unused, char *q);
int func_021E05C4(void *a, int unused, int *q, void **p);
int func_021E0618(int unused, int *state, int *q, int *p);
extern const Config d_021E3780;
extern const Record d_021E372E[];
extern const struct Record d_021E37D8[];
extern int d_020A7370;
extern Rect g_021E3808[];

/*
 * lever: Repeat the reset store in both result arms, with return 1 shared after them; hoisting the store removes the branch at 0x021E00C8.
 */
int func_021E009C(char *p, char *q)
{
    u16 out;
    int result;
    func_021FFC9C(*(char * *)&((struct Obj00277 *)p)->f1C);
    result = func_021FFE90(*(int * *)&((struct Obj00277 *)p)->f1C, &out);
    if (result) {
        if (result == 2) {
            ((struct Obj00351 *)q)->f14 = out;
            func_021E03B0(p, q, 1);
            ((struct Obj00277 *)p)->f50 = 0;
        } else {
            ((struct Obj00277 *)p)->f50 = 0;
        }
        return 1;
    }
    return 0;
}

int func_021E00D8(char *p,char *q)
{
    int first,second,a,b;
    void *v,*text,*data;
    int ws;
    Config cfg;
    Triple triple;
    Params params;
    first=func_021FC20C(*(char * *)&((struct Obj03330 *)q)->f8);
    second=func_021FC214(*(char * *)&((struct Obj03330 *)q)->f8);
    func_021FB964((void *)(*(int *)&((struct Obj03330 *)q)->f8),28,((struct Obj02231 *)p)->f54);
    text=func_020457B0(128,((struct Obj02231 *)p)->f54);
    v=func_02012944(((struct Obj03330 *)q)->f10);
    a=func_0200856C(v);b=func_02008570(v);
    ws=func_021FC21C(*(char * *)&((struct Obj03330 *)q)->f8);
    data=func_02045EC0((void *)second,125);
    if(!func_02025B64(a))func_0201F048((void *)ws,0,a);
    else func_0201F094((void *)ws,0,a,b);
    func_0201F250((void *)ws,text,data);
    func_02045808(data);
    *(Slot * *)&((struct Obj02231 *)p)->f14=func_0201F81C(1,((struct Obj02231 *)p)->f54);
    func_0201F898(*(Slot * *)&((struct Obj02231 *)p)->f14,(u32)text,0,((struct Obj02231 *)p)->f54);
    func_02045808(text);
    cfg=d_021E3780;
    cfg.words[0]=*(u32 *)&((struct Obj02231 *)p)->f14;cfg.words[1]=1;
    cfg.words[5]=*(u32 *)&((struct Obj03330 *)q)->f8;cfg.words[6]=((struct Obj03330 *)q)->f4;
    ((struct Obj02231 *)p)->f18=func_021FC8C8(&cfg,((struct Obj02231 *)p)->f54);
    func_02082BCC(&params,0,8);
    func_021FC124(*(int *)&((struct Obj03330 *)q)->f8,6,&triple);
    params.a=d_021E372E[0].a;params.b=d_021E372E[0].b;params.c=d_021E372E[0].c;params.flag=1;
    ((struct Obj02231 *)p)->fC=func_021FB378(&params,d_021E372E[0].file,96,1,*(int *)&((struct Obj03330 *)q)->f4,((struct Obj02231 *)p)->f44,first,second,&triple,((struct Obj02231 *)p)->f54);
    return 1;
}

int func_021E0214(char *p, char *q)
{
    if (((struct Obj04574 *)p)->fC) {
        func_021FB494(((struct Obj04574 *)p)->fC);
        ((struct Obj04574 *)p)->fC = 0;
    }
    func_021FCC80(((struct Obj04574 *)p)->f18);
    ((struct Obj04574 *)p)->f18 = 0;
    func_0201F868(((struct Obj04574 *)p)->f14);
    ((struct Obj04574 *)p)->f14 = 0;
    func_021FBDA4(((struct Obj24622 *)q)->f8, 28);
    func_020409B4(4);
    return 1;
}

/*
 * trailing: two zero alignment bytes at 0x021E02F6
 */
int func_021E024C(char *p, char *q)
{
    int selected, pressed;
    unsigned int x, y;
    func_021FCD0C(((struct Obj00277 *)p)->f18);
    selected = func_021FCDA8(((struct Obj00277 *)p)->f18);
    pressed = func_02035D20(&x, &y);
    pressed &= func_021FB4B4((unsigned int *)(((struct Obj00277 *)p)->fC), x, y);
    if (selected != -1) {
        unsigned int x1, y1;
        int args[2];
        void *v;
        int a;
        func_02035D20(&x1, &y1);
        args[0] = x1;
        args[1] = y1;
        func_021FD860(((struct Obj00277 *)p)->f40, 1, args);
        v = func_02012944(((struct Obj00351 *)q)->f10);
        a = func_0200856C(v);
        ((struct Obj00351 *)q)->f17 = func_02008570(v);
        ((struct Obj00351 *)q)->f16 = a;
        func_021E03B0(p, q, 2);
        ((struct Obj00277 *)p)->f50 = 0;
        return 1;
    } else if (pressed != 0) {
        unsigned int x2, y2;
        int args[2];
        func_02035D20(&x2, &y2);
        args[0] = x2;
        args[1] = y2;
        func_021FD860(((struct Obj00277 *)p)->f40, 1, args);
        ((struct Obj00277 *)p)->f50 = 0;
        return 1;
    }
    return 0;
}

void func_021E02F8(char *p, int *q)
{
    int first, second, i;
    const struct Record *r;
    first = func_021FC20C((char *)q[2]);
    second = func_021FC214((char *)q[2]);
    func_021FB964((void *)q[2], 25, ((struct Obj01765 *)p)->f54);
    for (i = 0; i < 6; i++) {
        r = &d_021E37D8[i];
        *(void **)(p + i * 4 + 0x20) = func_021FC6A4(1, r->a, r->b, r->c, r->d, 14, ((struct Obj01765 *)p)->f48, ((struct Obj01765 *)p)->f54);
        func_021FC868(*(void **)(p + i * 4 + 0x20), 0, 1, 0);
        func_021FC754(*(void **)(p + i * 4 + 0x20), (void *)second, (void *)r->value, (void *)first, 15776);
    }
}

/*
 * extent: final two bytes are alignment padding.
 */
void func_021E037C(char *p,char *q){int i;for(i=0;i<6;i++){if(*(void **)(p+i*4+0x20)){func_021FC734(*(void **)(p+i*4+0x20));*(void **)(p+i*4+0x20)=0;}}func_021FBDA4(((struct Obj24623 *)q)->f8,25);func_020409B4(1);}

void func_021E03B0(char *p,char *q,int mode)
{
    int first,second,ws;
    void *data,*text;
    first=func_021FC20C(*(char * *)&((struct Obj00351 *)q)->f8);
    second=func_021FC214(*(char * *)&((struct Obj00351 *)q)->f8);
    switch(mode) {
    case 0:
        if(((struct Obj00351 *)q)->f18!=19)func_021FC754(*(char * *)&((struct Obj00277 *)p)->f24,(void *)second,(void *)(((struct Obj00351 *)q)->f18+205),(void *)first,0x3da0);
        else func_021FC754(*(char * *)&((struct Obj00277 *)p)->f24,(void *)second,(void *)117,(void *)first,0x3da0);
        return;
    case 1:
        if(((struct Obj00351 *)q)->f14!=0xffff)func_021FC754(*(char * *)&((struct Obj00277 *)p)->f2C,(void *)d_020A7370,(void *)(u32)((struct Obj00351 *)q)->f14,(void *)first,0x3da0);
        else func_021FC754(*(char * *)&((struct Obj00277 *)p)->f2C,(void *)second,(void *)117,(void *)first,0x3da0);
        return;
    case 2:
        if(((struct Obj00351 *)q)->f16==255 && ((struct Obj00351 *)q)->f17==255) {
            func_021FC754(*(char * *)&((struct Obj00277 *)p)->f34,(void *)second,(void *)117,(void *)first,0x3da0);
            return;
        }
        ws=func_021FC21C(*(char * *)&((struct Obj00351 *)q)->f8);
        data=func_02045EC0((void *)second,24);
        text=func_020457B0(128,((struct Obj00277 *)p)->f54);
        if(!func_02025B64(((struct Obj00351 *)q)->f16))func_0201F048((void *)ws,0,((struct Obj00351 *)q)->f16);
        else func_0201F094((void *)ws,0,((struct Obj00351 *)q)->f16,((struct Obj00351 *)q)->f17);
        func_0201F250((void *)ws,text,data);
        func_021FC7C4(*(char * *)&((struct Obj00277 *)p)->f34,text,(void *)first,0x3da0);
        func_02045808(data);func_02045808(text);
        break;
    }
}


/*
 * Hit-test a point against a table of three rectangles; returns the index
 * of the first hit, or 3 when none (or when no point is available).
 */
int func_021E04C8(void)
{
    unsigned int x, y;
    int i;

    if (func_02035D20(&x, &y)) {
        for (i = 0; i < 3; i++) {
            const Rect *r = &g_021E3808[i];
            if (x - r->x0 <= r->x1 - r->x0 && y - r->y0 <= r->y1 - r->y0) {
                return i;
            }
        }
    }
    return 3;
}

/*
 * extent: 021E05C2 alignment padding.
 */
int func_021E050C(void *task, int unused, char *q)
{
    struct Data *p;
    int entries[3];
    func_021FC20C((char *)(*(int *)&((struct Obj01767 *)q)->f8));
    func_021FC214(*(char * *)&((struct Obj01767 *)q)->f8);
    p = func_0203159C(task, 24, func_021F9B9C(((struct Obj01767 *)q)->fC));
    func_02082BCC(p, 0, 24);
    p->heap = func_021F9B9C(((struct Obj01767 *)q)->fC);
    func_021FB964((void *)(*(int *)&((struct Obj01767 *)q)->f8), 29, p->heap);
    func_021FBE54(*(char * *)&((struct Obj01767 *)q)->f8, 11, p->heap);
    func_021FBE54(*(char * *)&((struct Obj01767 *)q)->f8, 12, p->heap);
    func_021FBE54(*(char * *)&((struct Obj01767 *)q)->f8, 6, p->heap);
    p->e = func_021FD760((unsigned int)(((struct Obj01767 *)q)->f4), (char *)(*(int *)&((struct Obj01767 *)q)->f8), 1, p->heap);
    entries[0] = 2;
    entries[1] = 5;
    entries[2] = 5;
    p->a = func_021E07A4(p->heap, 12, ((struct Obj01767 *)q)->f4, (void *)(*(int *)&((struct Obj01767 *)q)->f8), p->e, entries);
    p->b = func_021E06D0(p->a, p->heap);
    p->d = (void *)func_0201C440((void *)p->heap);
    p->c = func_021FD12C(*(int *)&((struct Obj01767 *)q)->f8, p->d, p->heap);
    func_021FD170(p->c, (char *)(*(int *)&((struct Obj01767 *)q)->f8), (void *)104);
    return 1;
}

/*
 * extent: 021E0616 alignment padding; next owned function starts 021E0618.
 */
int func_021E05C4(void *a, int unused, int *q, void **p)
{
    func_021FD15C((void *)((int)p[2]), q[2]);
    func_021E0774(p[1]);
    func_021E0808(p[0]);
    func_0201C4C0(p[3]);
    func_021FD820(p[5]);
    func_021FBDA4(q[2], 29);
    func_021FC0C8((char *)q[2], 6);
    func_021FC0C8((char *)q[2], 12);
    func_021FC0C8((char *)q[2], 11);
    func_020315D4(a);
    return 1;
}

/*
 * extent: 021E06CE alignment padding.
 */
int func_021E0618(int unused, int *state, int *q, int *p)
{
    switch (*state) {
    case 0:
        func_021FE784(q[0], 2, 3, 0);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0((int *)q[0])) *state = 2;
        break;
    case 2:
        func_021E0754((char *)p[1]);
        switch (func_021E075C((char *)p[1])) {
        case 1: func_021F9BA0((unsigned int *)q[3]); *state = 3; break;
        case 2: ((struct Obj04576 *)q)->f10 = func_021E0764((char *)p[1]); func_021F9BF4((unsigned int *)q[3], 2); *state = 3; break;
        }
        break;
    case 3:
        func_021FE784(q[0], 2, 3, 1);
        *state = 4;
        break;
    case 4:
        if (func_021FE7B0((int *)q[0])) *state = 5;
        break;
    case 5: return 1;
    }
    if (p[2]) func_021FD1BC((void *)p[2]);
    func_0201C4E4((struct PrintSys *)p[3]);
    func_021FD854((char *)p[5]);
    return 0;
}
