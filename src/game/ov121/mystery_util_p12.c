/*
 * file:     mystery_util_p12.c
 * unit:     yes
 * function: func_021DB938, func_021DBA78, func_021DBA94, func_021DBC08
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
 *   func_021DBEE4  0x021DBEE4  thumb  ov121
 *   func_021DBDF4  0x021DBDF4  thumb  ov121
 *   func_021DD980  0x021DD980  thumb  ov121
 */
#include "../../matched/include/Obj13956.h"
#include "../../matched/include/Obj13957.h"
#include "../../matched/include/Obj02834.h"

struct CharBuf;
struct Descriptor;
struct Obj;
struct Actor;
struct PtS;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef union Rect { u16 h[4]; u8 b[8]; } Rect;

typedef signed short s16;

typedef signed char s8;

typedef struct Item {
    unsigned char raw[0xDC];
} Item;

typedef struct Obj {
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
} Obj;

extern void func_02041300(u32,u16,u8,u8,u8,u8,u8);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_02040618(u32,u32,u32);
extern void func_0200A094(void *list, u32 idx);
extern u32 func_0200A348(struct Obj *list);
extern u32 func_0200A0E4(u8 *p, u32 a);
extern int func_0200A000(char *p, int idx, void *buf);
extern void func_021DBEE4(u32 p);
extern void func_021DBDF4(Item *it, void *data, Obj *o, u16 f);
extern void func_021DD980(char *p);
void func_021DB938(char *p,int a,u16 index);
void func_021DBA78(u8 *p,int a);
int func_021DBA94(char *p);
void func_021DBC08(Obj *o, int idx);
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
        func_0204B3B4(*(void **)(p+0xb28+index*4));
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
            func_0204B404(*(void **)(p+i*4+0xb28),(const struct Vec2 *)(xy+2),0);
            func_0204B454(*(void **)(p+i*4+0xb28),(struct PtS *)xy,0);
            if(xy[0]>=-16 && xy[0]<=272 && xy[1]>=-16 && xy[1]<=208)
                func_0204B3DC(*(void **)(p+i*4+0xb28),1);
            else func_0204B3DC(*(void **)(p+i*4+0xb28),0);
        }
    }
    if(((struct Obj02834 *)p)->fAE0) {
        func_0204B454(((struct Obj02834 *)p)->fAF0,(struct PtS *)(xy+2),0);
        xy[2]-=(s16)amount;
        func_0204B404(((struct Obj02834 *)p)->fAF0,(const struct Vec2 *)(xy+2),0);
        if(xy[2]>=-96 && xy[2]<=352 && xy[3]>=-96 && xy[3]<=288)
            func_0204B3DC(((struct Obj02834 *)p)->fAF0,1);
        else func_0204B3DC(((struct Obj02834 *)p)->fAF0,0);
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
void func_021DBC08(Obj *o, int idx)
{
    unsigned char buf[0xCC];
    u32 i;

    func_0200A094(o->list, idx);
    for (i = 0; i < func_0200A348(o->list); i++)
        func_021DBEE4((u32)(&o->items[i]));
    for (i = 0; i < func_0200A348(o->list); i++) {
        if (func_0200A0E4(o->list, i)) {
            func_0200A000(o->list, i, buf);
            func_021DBDF4(&o->items[i], buf, o, o->f24);
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
