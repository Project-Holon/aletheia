/*
 * function: func_021BD174
 * address: 0x021BD174
 * packet: pkt_ov216_021BD174
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * checks: 1 ABI rederived from matched bodies/callers; C58 remains wide because caller truncates to u16. 2 no twin. 3 prior enum/const trials exhausted; 4 far-offset-before-index modular integer address formation rescues MATCH*722; 5 current idioms/neighbours read. Six authorized ov010 leaves EXACT with adjacent TU audits; prior once300 not repeated.
 * tail: 2B zero alignment at 021BD446..021BD448.
 * symbols:
 *   func_02165CC0 0x02165CC0 thumb ov010
 *   func_02021F64 0x02021F64 thumb
 *   func_021BCD08 0x021BCD08 thumb ov216
 *   func_021BCDC0 0x021BCDC0 thumb ov216
 *   func_02165C34 0x02165C34 thumb ov010
 *   func_021BD07C 0x021BD07C thumb ov216
 *   func_02165C60 0x02165C60 thumb ov010
 *   func_0204581C 0x0204581C arm
 *   func_0201F1C8 0x0201F1C8 thumb
 *   func_021BCEA4 0x021BCEA4 thumb ov216
 *   func_02165C78 0x02165C78 thumb ov010
 *   func_0201F198 0x0201F198 thumb
 *   func_02165D10 0x02165D10 thumb ov010
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_02165C58 0x02165C58 thumb ov010
 *   func_0201F048 0x0201F048 thumb
 *   func_02165C5C 0x02165C5C thumb ov010
 *   func_0201F094 0x0201F094 thumb
 *   func_02165D40 0x02165D40 thumb ov010
 *   func_02165D48 0x02165D48 thumb ov010
 *   func_0202DCC4 0x0202DCC4 thumb
 *   func_0202DC9C 0x0202DC9C thumb
 *   func_02165C90 0x02165C90 thumb ov010
 *   func_0202DC48 0x0202DC48 thumb
 *   func_02165CE8 0x02165CE8 thumb ov010
 *   func_02025C88 0x02025C88 thumb
 *   func_0202DAA4 0x0202DAA4 thumb
 *   func_02165CB4 0x02165CB4 thumb ov010
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BCE7C 0x021BCE7C thumb ov216
 */
#include "../include/Obj00051.h"
#include "../include/Obj05555.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
enum Index { IndexZero=0 };
struct Pair { u16 a,b; };
struct Quad { u16 a,b,c,d; };
struct Rgb555 { u16 r:5,g:5,b:5,pad:1; };
struct WordSet; struct U16Vec; struct Obj; struct Rec; struct S;
struct Obj0202DCC4; struct Obj0202DC98;
extern void func_02165CC0(int a0, int a1);
extern void func_02021F64(u16 *,u16 *,u32,int,u16);
extern void func_021BCD08(void *p, unsigned mode, unsigned a, unsigned b);
extern int func_021BCDC0(void *);
extern void func_02165C34(struct Rec *,void *);
extern void func_021BD07C(void *,void **,int,short,u8,u8,u8,u8);
extern u8 func_02165C60(void *);
extern void func_0204581C(struct U16Vec *);
extern void func_0201F1C8(struct WordSet *,u32,u32);
extern void func_021BCEA4(u8 *p, u8 n);
extern u8 func_02165C78(void *);
extern void func_0201F198(struct WordSet *,u32,u32);
struct R;
extern void func_02165D10(const struct S *p, u16 *a, u16 *b);
extern void func_0201EFA4(struct WordSet *,u32,u32,u32,u32,u32);
extern u8 func_02165C58(const u8 *p);
extern void func_0201F048(struct WordSet *,u32,u32);
extern u8 func_02165C5C(const u8 *p);
extern void func_0201F094(struct WordSet *,u32,u32,u32);
extern u32 func_02165D40(const struct S *p);
extern u32 func_02165D48(const struct S *p);
extern u32 func_0202DCC4(const struct Obj0202DCC4 *,u32);
extern void func_0202DC9C(struct Obj0202DC98 *,int,u32);
extern void func_02165C90(const struct R *p, struct Quad *q);
extern void func_0202DC48(u32,u32,u32,u32);
extern u8 func_02165CE8(struct S *);
extern u32 func_02025C88(u32);
extern void func_0202DAA4(void *set, u32 id, void *dstA, void *dstB, volatile u16 which);
extern u8 func_02165CB4(void *);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_021BCE7C(void *p, unsigned short value);
void func_021BD174(char *p,void *record,u16 unused,u8 slot)
{
    struct Pair colors;
    struct Quad data;
    struct Pair counts;
    char *q=(char *)p+0x15c+slot*128;
    u32 subtype;
    u16 value;
    int position;
    int index;
    func_02165CC0((int)(&colors.a),(int)record);
    func_02021F64(&colors.a,&colors.b,1,3,0);
    position=slot*16;
    func_021BCD08(&colors,1,(u16)(position+1),2);
    func_021BCD08(*(char * *)&((struct Obj00051 *)p)->f11C+func_021BCDC0(record)*32,1,(u16)(position+10),2);
    func_02165C34(record,((struct Obj00051 *)p)->f13C);
    func_021BD07C((char *)p,(void **)q,*(int *)&((struct Obj00051 *)p)->f13C,6,48,13,2,0);
    subtype=func_02165C60(record);
    if(subtype==255) func_0204581C(*(struct U16Vec * *)&((struct Obj00051 *)p)->f140);
    else {func_0201F1C8(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,0,subtype);func_021BCEA4((u8 *)p,5);}
    func_021BD07C((char *)p,(void **)(q+16),*(int *)&((struct Obj00051 *)p)->f140,6,48,13,2,1);
    subtype=func_02165C78(record);
    if(subtype==255) func_0204581C(*(struct U16Vec * *)&((struct Obj00051 *)p)->f140);
    else {func_0201F198(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,0,subtype);func_021BCEA4((u8 *)p,4);}
    func_021BD07C((char *)p,(void **)(q+32),*(int *)&((struct Obj00051 *)p)->f140,6,48,13,2,0);
    func_02165D10(record,&counts.b,&counts.a);
    func_0201EFA4(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,2,counts.b,3,0,1);
    func_0201EFA4(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,3,counts.a,2,2,1);
    func_021BCEA4((u8 *)p,6);
    func_021BD07C((char *)p,(void **)(q+48),*(int *)&((struct Obj00051 *)p)->f140,6,48,13,2,1);
    value=(unsigned)func_02165C58(record);
    func_0201F048(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,0,value);
    func_0201F094(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,1,value,func_02165C5C(record));
    func_021BCEA4((u8 *)p,8);
    func_021BD07C((char *)p,(void **)(q+80),*(int *)&((struct Obj00051 *)p)->f140,0,0,28,4,0);
    func_0201EFA4(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,0,func_02165D40(record),5,1,1);
    func_0201EFA4(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,1,func_02165D48(record),5,1,1);
    func_021BCEA4((u8 *)p,10);
    func_021BD07C((char *)p,(void **)(q+96),*(int *)&((struct Obj00051 *)p)->f140,21,0,6,4,0);
    if(func_0202DCC4(*(struct Obj0202DCC4 * *)&((struct Obj00051 *)p)->f158,slot)!=0) func_0202DC9C(*(struct Obj0202DC98 * *)&((struct Obj00051 *)p)->f158,slot,1);
    func_02165C90(record,&data);
    func_0202DC48(*(u32 *)&((struct Obj00051 *)p)->f158,((struct Obj05555 *)q)->f70,(u32)&data,slot);
    ((struct Obj05555 *)q)->f7C=func_02165CE8(record);
    index=slot*12;
    func_0202DAA4(((struct Obj00051 *)p)->f58,func_02025C88(((struct Obj05555 *)q)->f7C),*(void **)((u32)p+0x6c+(u32)index),*(void **)((u32)p+0x68+(u32)index),((struct Obj00051 *)p)->f2);
    subtype=func_02165CB4(record);
    if(subtype==0) {func_0204B3DC(*(struct Obj * *)&((struct Obj05555 *)q)->f74,0);return;}
    func_021BCE7C(((struct Obj05555 *)q)->f74,(u8)(subtype+1));
    func_0204B3DC(*(struct Obj * *)&((struct Obj05555 *)q)->f74,1);
}
