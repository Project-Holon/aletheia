/*
 * file:     mystery_util_p03.c
 * unit:     yes
 * function: func_021DB938, func_021DBA78, func_021DBA94, func_021DBC08, func_021DBCC8, func_021DBDB8, func_021DBDBC, func_021DBDF4, func_021DBEE4, func_021DBF04, func_021DBF08, func_021DBF10, func_021DBF40, func_021DBF70, func_021DBF9C, func_021DBFE4, func_021DC004, func_021DC024, func_021DC02C
 * address:  0x021DB938
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
 *   d_021DF86E 0x021DF86E data ov121 a2
 *   func_02041300 0x02041300 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02040618 0x02040618 arm
 *   func_0200A094  0x0200A094  thumb
 *   func_0200A348  0x0200A348  thumb
 *   func_0200A0E4  0x0200A0E4  thumb
 *   func_0200A000  0x0200A000  thumb
 *   func_021DD980  0x021DD980  thumb  ov121
 *   func_0200A254  0x0200A254  thumb
 *   func_021DD24C  0x021DD24C  thumb  ov121
 *   func_02082BCC 0x02082BCC arm
 *   func_02043678 0x02043678 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_020437AC 0x020437AC arm
 *   func_020490F4 0x020490F4 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_02020E60 0x02020E60 thumb
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 */
#include "../../matched/include/Obj13956.h"
#include "../../matched/include/Obj13957.h"
#include "../../matched/include/Obj02834.h"
#include "../../matched/include/Obj22900.h"
#include "../../matched/include/Obj03788.h"
#include "../../matched/include/Obj10418.h"
#include "../../matched/include/Obj13958.h"
#include "../../matched/include/Obj22903.h"
#include "../../matched/include/Obj08097.h"
#include "../../matched/include/Obj06452.h"
#include "../../matched/include/Obj22905.h"

struct CharBuf;
struct Descriptor;
struct Obj_021DB938;
struct Actor;
struct PtS;
struct Vec2;
struct Bmp;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
struct Obj020437AC;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef union Rect { u16 h[4]; u8 b[8]; } Rect;

typedef signed short s16;

typedef signed char s8;

typedef struct Item {
    unsigned char raw[0xDC];
} Item;

typedef struct Obj_021DB938 {
    unsigned char pad00[0xC];
    void *list;
    unsigned char pad10[0x14];
    u16 f24;
    unsigned char pad26[2];
    Item items[12];
    unsigned char pad[0xA7C - 0x28 - 12 * 0xDC];
    void *slots[12];
    unsigned char padAAC[0xAD4 - 0xAAC];
    int dirty;
} Obj_021DB938;

typedef struct Obj_021DBCC8 {
    unsigned char pad00[0xC];
    void *list;
    unsigned char pad10[0x10];
    void *ctx;
    u16 f24;
    unsigned char pad26[2];
    Item items[12];
    unsigned char pad[0xA7C - 0x28 - 12 * 0xDC];
    void *slots[12];
    unsigned char padAAC[4];
    void *desc;
    unsigned char padAB4[0xAD4 - 0xAB4];
    int dirty;
} Obj_021DBCC8;

typedef struct { u32 w[51]; } Record;

extern void func_02041300(u32,u16,u8,u8,u8,u8,u8);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_0204B3B4(struct Obj_021DB938 *p);
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj_021DB938 *p, const struct Vec2 *delta, u32 which);
extern void func_0204B3DC(struct Obj_021DB938 *p, u32 v);
extern void func_02040618(u32,u32,u32);
extern void func_0200A094(void *list, u32 idx);
extern u32 func_0200A348(struct Obj_021DB938 *list);
extern u32 func_0200A0E4(u8 *p, u32 a);
extern int func_0200A000(char *p, int idx, void *buf);
extern void func_021DD980(char *p);
extern void func_0200A254(void *, u32, u32);
extern void *func_021DD24C(void *,void *,void *,u16);
extern void func_02082BCC(void *,int,int);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045808(struct U16Vec *vec);
extern void func_020437AC(struct Obj020437AC *);
extern void *func_020490F4(u32,u16);
extern int func_0201BC3C(void);
extern u32 func_02020E60(u16,u32);
extern u32 func_0201BB5C(u32,u32,u32,u32);
extern u32 func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
void func_021DB938(char *p,int a,u16 index);
void func_021DBA78(u8 *p,int a);
int func_021DBA94(char *p);
void func_021DBC08(Obj_021DB938 *o, int idx);
void func_021DBCC8(Obj_021DBCC8 *o, u32 a, u32 b);
int func_021DBDB8(char *p);
u32 func_021DBDBC(u32 p);
void func_021DBDF4(char *out,const Record *src,char *p,u16 heap);
void func_021DBEE4(u32 p);
int func_021DBF04(int *p);
void *func_021DBF08(void *p);
void *func_021DBF10(void *p,u16 heap);
u32 func_021DBF40(void *p);
u32 func_021DBF70(void *p);
int func_021DBF9C(void *p);
int func_021DBFE4(void *p);
int func_021DC004(void *p);
int func_021DC024(void *p);
char *func_021DC02C(void *p);
extern const Rect d_021DF86E[];




void func_021DB938(char *p,int a,u16 index)
{
    Rect rect;
    int y,x,tile;
    int yy;
    rect=d_021DF86E[index];
    if((a && ((struct Obj13956 *)p)->fAD0==0) || (a==0 && ((struct Obj13956 *)p)->fAD0)) {
        index+=4;
        rect.b[0]+=32;
        rect.b[2]+=32;
    }
    for(y=0;y<7;y++) {
        yy=rect.b[1]+y;
        tile=y*32+384;
        for(x=0;x<12;x++)
            func_02041300(3,(u16)(x+tile),(u8)(rect.b[0]+x),yy,1,1,3);
    }
    func_02043B5C(func_02045770(*(void **)(p+0xb08+index*4)),0);
    func_02045334(*(void **)(p+0xb08+index*4));
    if(*(void **)(p+0xb28+index*4)) {
        func_0204B3B4((struct Obj_021DB938 *)(*(void **)(p+0xb28+index*4)));
        *(void **)(p+0xb28+index*4)=0;
        if(*(u32 *)(p+0xb88+index*4)!=-1) {
            func_0204ADA4(*(u32 *)(p+0xb88+index*4));
            *(u32 *)(p+0xb88+index*4)=-1;
        }
        if(*(u32 *)(p+0xb48+index*4)!=-1) {
            func_0204A8D4(*(u32 *)(p+0xb48+index*4));
            *(u32 *)(p+0xb48+index*4)=-1;
        }
        if(*(u32 *)(p+0xb68+index*4)!=-1) {
            func_0204AFD8(*(u32 *)(p+0xb68+index*4));
            *(u32 *)(p+0xb68+index*4)=-1;
        }
    }
}





void func_021DBA78(u8 *p,int a) { int v; if(a) v=-1; else v=1; ((struct Obj13957 *)p)->fADC=v; ((struct Obj13957 *)p)->fAD8=0; }




int func_021DBA94(char *p)
{
    int amount,i;
    s16 xy[4];
    if(((struct Obj02834 *)p)->fADC==0) goto idle;
    amount=(((struct Obj02834 *)p)->fADC*256)/16;
    for(i=0;i<8;i++) {
        if(*(void **)(p+i*4+0xb28)) {
            func_0204B454(*(void **)(p+i*4+0xb28),(struct PtS *)(xy+2),0);
            xy[2]-=(s16)amount;
            func_0204B404((struct Obj_021DB938 *)(*(void **)(p+i*4+0xb28)), (const struct Vec2 *)(xy+2), 0);
            func_0204B454(*(void **)(p+i*4+0xb28),(struct PtS *)xy,0);
            if(xy[0]>=-16 && xy[0]<=272 && xy[1]>=-16 && xy[1]<=208)
                func_0204B3DC((struct Obj_021DB938 *)(*(void **)(p+i*4+0xb28)), 1);
            else func_0204B3DC((struct Obj_021DB938 *)(*(void **)(p+i*4+0xb28)), 0);
        }
    }
    if(((struct Obj02834 *)p)->fAE0) {
        func_0204B454(((struct Obj02834 *)p)->fAF0,(struct PtS *)(xy+2),0);
        xy[2]-=(s16)amount;
        func_0204B404((struct Obj_021DB938 *)(((struct Obj02834 *)p)->fAF0), (const struct Vec2 *)(xy+2), 0);
        if(xy[2]>=-96 && xy[2]<=352 && xy[3]>=-96 && xy[3]<=288)
            func_0204B3DC((struct Obj_021DB938 *)(((struct Obj02834 *)p)->fAF0), 1);
        else func_0204B3DC((struct Obj_021DB938 *)(((struct Obj02834 *)p)->fAF0), 0);
    }
    func_02040618(3,1,amount);
    func_02040618(2,1,amount);
    if((((struct Obj02834 *)p)->fAD8)++>=15) {
        ((struct Obj02834 *)p)->fAD0^=1;
        ((struct Obj02834 *)p)->fADC=0;
    }
    return 0;
idle:
    return 1;
}





/*
 * Rebuild every entry from the list, free slot idx, then pull each later
 * slot down one place (swap into an empty slot), and mark the table dirty.
 */
void func_021DBC08(Obj_021DB938 *o, int idx)
{
    unsigned char buf[0xCC];
    u32 i;

    func_0200A094(o->list, idx);
    for (i = 0; i < func_0200A348((struct Obj_021DB938 *)o->list); i++)
        func_021DBEE4((u32)(&o->items[i]));
    for (i = 0; i < func_0200A348((struct Obj_021DB938 *)o->list); i++) {
        if (func_0200A0E4(o->list, i)) {
            func_0200A000(o->list, i, buf);
            func_021DBDF4((char *)(&o->items[i]), (const Record *)buf, (char *)((Obj_021DB938 *)o), o->f24);
        }
    }
    if (o->slots[idx] != 0) {
        func_021DD980(o->slots[idx]);
        o->slots[idx] = 0;
    }
    for (; idx < 11; idx++) {
        void *tmp = o->slots[idx];
        if (tmp == 0) {
            o->slots[idx] = o->slots[idx + 1];
            o->slots[idx + 1] = tmp;
        }
    }
    o->dirty = 1;
}





/*
 * note 2026-10-05 (lane Y6): no source existed. Same shape as matched sibling
 *   func_021DBC08 (rebuild entries from the list), then two slot teardowns and rebuilds from
 *   the descriptor. EXACT on the first compile with plain struct fields.
 */
void func_021DBCC8(Obj_021DBCC8 *o, u32 a, u32 b)
{
    unsigned char buf[0xCC];
    u32 i;

    func_0200A254(o->list, a, b);
    for (i = 0; i < func_0200A348((struct Obj_021DB938 *)o->list); i++)
        func_021DBEE4((u32)(&o->items[i]));
    for (i = 0; i < func_0200A348((struct Obj_021DB938 *)o->list); i++) {
        if (func_0200A0E4(o->list, i)) {
            func_0200A000(o->list, i, buf);
            func_021DBDF4((char *)(&o->items[i]), (const Record *)buf, (char *)((Obj_021DB938 *)o), o->f24);
        }
    }
    func_021DD980(o->slots[a]);
    func_021DD980(o->slots[b]);
    o->slots[a] = func_021DD24C(func_021DC02C(&o->items[a]), o->desc, o->ctx, o->f24);
    o->slots[b] = func_021DD24C(func_021DC02C(&o->items[b]), o->desc, o->ctx, o->f24);
    o->dirty = 1;
}





int func_021DBDB8(char *p) { return 3; }




/*
 * lever: Declare the index before the count, but initialise count first; this places index in r4 and count in r5.
 * prototype: func_0200A348 returns the value used by the bound. Its forwarding target 0200A400 reads only r0, so legacy trailing arguments are omitted.
 */
u32 func_021DBDBC(u32 p) { u32 i; u32 count=0; for (i=0;i<func_0200A348((struct Obj_021DB938 *)(((struct Obj22900 *)p)->fC));i++) { if (func_021DBF04((int *)(p+40+i*220))) count++; } return count; }



void func_021DBDF4(char *out,const Record *src,char *p,u16 heap)
{
    int flags;
    void *text,*other;
    s16 x,y;
    func_02082BCC(out,0,0xdc);
    if(src) {
        ((struct Obj10418 *)out)->f0=1;
        *(Record *)(out+4)=*src;
        ((struct Obj10418 *)out)->fD0=func_02043678(10,2,32,heap);
        flags=src->w[43];
        text=func_020457B0(128,heap);
        other=func_02045EC0(((struct Obj03788 *)p)->f1C,151);
        func_0201EFA4(((struct Obj03788 *)p)->f18,0,(u16)(flags>>16),4,1,1);
        func_0201EFA4(((struct Obj03788 *)p)->f18,1,(u8)(flags>>8),2,0,1);
        func_0201EFA4(((struct Obj03788 *)p)->f18,2,(u8)flags,2,0,1);
        func_0201F250(((struct Obj03788 *)p)->f18,text,other);
        x=40;
        x-=(s16)(func_0201D304(text,*(u32 *)&((struct Obj03788 *)p)->f10,0)/2);
        y=8-(s16)(func_0201D42C(text,((struct Obj03788 *)p)->f10)/2);
        func_0201C7A4(((struct Obj10418 *)out)->fD0,x,y,text,((struct Obj03788 *)p)->f10);
        func_02045808(text);
        func_02045808(other);
    }
}



void func_021DBEE4(u32 p) { if (((struct Obj13958 *)p)->f0) { func_020437AC(*(struct Obj020437AC * *)&((struct Obj13958 *)p)->fD0); func_02082BCC((void *)p,0,220); } }



int func_021DBF04(int *p) { return *p; }



void *func_021DBF08(void *p) { return ((struct Obj22903 *)p)->fD0; }


void *func_021DBF10(void *p,u16 heap) { switch(func_021DC024(p)) { case 1:return func_020490F4(7,heap); case 2:return func_020490F4(25,heap); default:return func_020490F4(34,heap); } }


/*
 * prototype: func_02020E60 item is u16 here, matching caller truncation before the call.
 */
u32 func_021DBF40(void *p) { switch(func_021DC024(p)) { case 1:return func_0201BC3C(); case 2:return func_02020E60(*(u32 *)func_021DC02C(p),2); default:return 3; } }


u32 func_021DBF70(void *p) { char *q; if (func_021DC024(p)==1) { q=func_021DC02C(p); return func_0201BB5C(((struct Obj08097 *)q)->f1A,((struct Obj08097 *)q)->f1C,((struct Obj08097 *)q)->f35,((struct Obj08097 *)q)->f5C); } return 0; }


int func_021DBF9C(void *p)
{
    char *q;
    switch(func_021DC024(p)) {
    case 1:
        q=func_021DC02C(p);
        return func_0201BABC(((struct Obj06452 *)q)->f1A,((struct Obj06452 *)q)->f1C,((struct Obj06452 *)q)->f35,((struct Obj06452 *)q)->f5C);
    case 2:
        q=func_021DC02C(p);
        return func_02020E60((u16)((struct Obj06452 *)q)->f0,1);
    default: return 12;
    }
}


int func_021DBFE4(void *p) { switch(func_021DC024(p)) { case 1: return func_0201BC40(); case 2: return 1; default:return 33; } }


int func_021DC004(void *p) { switch(func_021DC024(p)) { case 1: return func_0201BCB4(); case 2: return 0; default:return 36; } }


int func_021DC024(void *p) { return ((struct Obj22905 *)p)->fB7; }


char *func_021DC02C(void *p) { return (char *)p+4; }
