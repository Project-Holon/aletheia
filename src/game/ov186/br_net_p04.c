/*
 * file:     br_net_p04.c
 * unit:     yes
 * function: func_021FF968, func_021FF99C, func_021FF9D0, func_021FFA14, func_021FFA40, func_021FFA6C, func_021FFA98, func_021FFB14, func_021FFB50, func_021FFB58, func_021FFB68, func_021FFB70, func_021FFB80, func_021FFBD4
 * address:  0x021FF968
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D683C 0x021D683C thumb ov125
 *   func_02034714 0x02034714 arm
 *   func_021FF8E4 0x021FF8E4 thumb ov186
 *   d_02200D98 0x02200D98 data a1
 *   func_021D69DC 0x021D69DC thumb ov125
 *   func_021D68EC 0x021D68EC thumb ov125
 *   func_021D6968 0x021D6968 thumb ov125
 *   func_021D69B4 0x021D69B4 thumb ov125
 *   func_021D698C 0x021D698C thumb ov125
 *   func_021D6A08 0x021D6A08 thumb ov125
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_02200D8C 0x02200D8C data a1
 *   func_020307B0 0x020307B0 arm
 *   func_02012E40 0x02012E40 thumb
 *   func_021D7124 0x021D7124 thumb ov125
 *   func_021D6770 0x021D6770 thumb ov125
 *   func_02156DE0 0x02156DE0 thumb ov009
 *   func_0201C440 0x0201C440 thumb
 *   func_02200228 0x02200228 thumb ov186
 *   func_0220014C 0x0220014C thumb ov186
 *   d_02200D9C 0x02200D9C data a1
 */
#include "../../matched/include/Obj24866.h"
#include "../../matched/include/Obj14482.h"
#include "../../matched/include/Obj08337.h"
#include "../../matched/include/Obj14483.h"
#include "../../matched/include/Obj24867.h"
#include "../../matched/include/Obj24868.h"
#include "../../matched/include/Obj24869.h"
#include "../../matched/include/Obj24870.h"
#include "../../matched/include/Obj24871.h"
#include "../../matched/include/Obj24872.h"
#include "../../matched/include/Obj24873.h"
#include "../../matched/include/Obj14485.h"
#include "../../matched/include/Obj10800.h"
#include "../../matched/include/Obj01967.h"

typedef unsigned int   u32;

typedef struct {
    int (*fn)(void *, void *, int);
    char  pad_04[4];
    int   arg_08;
} S;

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef signed int s32;

extern int func_021D683C(char *,void *);
extern void func_02034714(const char *,unsigned,const char *);
extern void func_021FF8E4(void *,int,int);
extern int func_021D69DC(char *,int,int);
extern int func_021D68EC(char *, int, unsigned, int, unsigned char);
extern int func_021D6968(char *);
extern int func_021D69B4(char *);
extern int func_021D698C(char *);
extern int func_021D6A08(char *p, int a, int b);
extern void *func_02030734(unsigned,unsigned,int,const char *,unsigned short);
extern void func_02082BCC(void *,int,unsigned);
extern u32 func_020307B0(void *p);
extern u8 func_02012E40(const u8 *o);
extern void func_021D7124(char *, int, int, int);
extern void func_021D6770(char *);
extern void func_02156DE0(int, int);
extern u32 func_0201C440(void *p);
extern int func_02200228(unsigned short, unsigned *);
extern int func_0220014C(void *p, u32 n, const u16 *ids);
void func_021FF968(char *p,int unused,char *q);
void func_021FF99C(char *p,int unused,char *q);
void func_021FF9D0(char *p, int unused, char *q);
void func_021FFA14(char *p,int unused,char *q);
void func_021FFA40(char *p,int unused,char *q);
void func_021FFA6C(char *p,int unused,char *q);
void func_021FFA98(char *p, int unused, char *q);
void func_021FFACC(char *p);
void func_021FFAD8(char *p);
void func_021FFAE4(char *p);
void func_021FFAF0(char *p);
void func_021FFAFC(char *p);
void func_021FFB08(char *p);
char *func_021FFB14(void *p,int f,unsigned heap);
void func_021FFB50(void *p);
void func_021FFB58(S *p);
void func_021FFB68(char *p, int v);
int func_021FFB70(int *p,int value);
int func_021FFB80(char *p, int b, int kind, int d);
char *func_021FFBD4(void *owner, void *table, int a, int b, int c, int d, int e, unsigned short heap);
extern const char d_02200D98[];
extern const char d_02200D8C[];
extern const char d_02200D9C[];

void func_021FF968(char *p,int unused,char *q) {if(!func_021D683C(q,((struct Obj24866 *)q)->f5A8))func_02034714(d_02200D98,0,d_02200D98);func_021FFB68(p,(int)func_021FF8E4);}

void func_021FF99C(char *p,int unused,char *q) {if(!func_021D69DC(q,((struct Obj14482 *)q)->f5B0,((struct Obj14482 *)q)->f5B4))func_02034714(d_02200D98,0,d_02200D98);func_021FFB68(p,(int)func_021FF8E4);}

void func_021FF9D0(char *p, int unused, char *q)
{
    if (!func_021D68EC(q, ((struct Obj08337 *)q)->f5B0, ((struct Obj08337 *)q)->f5B4, ((struct Obj08337 *)q)->f5B2, ((struct Obj08337 *)q)->f5B3))
        func_02034714(d_02200D98, 0, d_02200D98);
    func_021FFB68(p, (int)func_021FF8E4);
}

void func_021FFA14(char *p,int unused,char *q) {if(!func_021D6968(q))func_02034714(d_02200D98,0,d_02200D98);func_021FFB68(p,(int)func_021FF8E4);}

void func_021FFA40(char *p,int unused,char *q) {if(!func_021D69B4(q))func_02034714(d_02200D98,0,d_02200D98);func_021FFB68(p,(int)func_021FF8E4);}

void func_021FFA6C(char *p,int unused,char *q) {if(!func_021D698C(q))func_02034714(d_02200D98,0,d_02200D98);func_021FFB68(p,(int)func_021FF8E4);}

void func_021FFA98(char *p, int unused, char *q)
{
    if (!func_021D6A08(q, ((struct Obj14483 *)q)->f5B0, ((struct Obj14483 *)q)->f5B4))
        func_02034714(d_02200D98, 0, d_02200D98);
    func_021FFB68(p, (int)func_021FF8E4);
}

void func_021FFACC(char *p) { ((struct Obj24867 *)p)->f5B8 = 1; }

void func_021FFAD8(char *p) { ((struct Obj24868 *)p)->f5BC = 1; }

void func_021FFAE4(char *p) { ((struct Obj24869 *)p)->f5C0 = 1; }

void func_021FFAF0(char *p) { ((struct Obj24870 *)p)->f5C8 = 1; }

void func_021FFAFC(char *p) { ((struct Obj24871 *)p)->f5C4 = 1; }

void func_021FFB08(char *p) { ((struct Obj24872 *)p)->f5D8 = 1; }

char *func_021FFB14(void *p,int f,unsigned heap) {char *q=func_02030734(heap,16,0,d_02200D8C,0x44f);func_02082BCC(q,0,16);((struct Obj24873 *)q)->f8=p;func_021FFB68(q,f);return q;}

void func_021FFB50(void *p) {func_020307B0(p);}


void func_021FFB58(S *p)
{
    if (p->fn != 0)
        p->fn(p, (char *)p + 4, p->arg_08);
}


void func_021FFB68(char *p, int v)
{
    ((struct Obj14485 *)p)->f0 = v;
    ((struct Obj14485 *)p)->f4 = 0;
}

int func_021FFB70(int *p,int value)
{
    if(*p==value) return 1;
    return 0;
}

int func_021FFB80(char *p, int b, int kind, int d)
{
    if (func_02012E40(((struct Obj10800 *)p)->f5E0)) return 1;
    func_021D7124(p, b, kind, d);
    if (kind == 3 || kind == 6) {
        if (((struct Obj10800 *)p)->f5A4) {
            func_021D6770(p);
            ((struct Obj10800 *)p)->f5A4 = 0;
        }
        func_02156DE0(0, 0);
    }
    return 0;
}

char *func_021FFBD4(void *owner, void *table, int a, int b, int c, int d, int e, unsigned short heap)
{
    char *p;
    int i = 0;
    p = func_02030734(heap, 0x90, 0, d_02200D9C, 0x11a);
    func_02082BCC(p, 0, 0x90);
    ((struct Obj01967 *)p)->f24 = heap;
    ((struct Obj01967 *)p)->f7C = owner;
    ((struct Obj01967 *)p)->f28 = table;
    ((struct Obj01967 *)p)->f30 = c;
    ((struct Obj01967 *)p)->f34 = a;
    ((struct Obj01967 *)p)->f38 = b;
    ((struct Obj01967 *)p)->f3C = (void *)func_0201C440((void *)(((struct Obj01967 *)p)->f24));
    *(int *)&((struct Obj01967 *)p)->f80 = func_02200228((heap & 0x7fff) | 0x8000, (unsigned *)(p + 0x84));
    ((struct Obj01967 *)p)->f74 = d;
    ((struct Obj01967 *)p)->f78 = e;
    for (; i < 9; i++) *(unsigned char *)(p + i + 0x14) = func_0220014C(((struct Obj01967 *)p)->f7C, i, (const u16 *)(((struct Obj01967 *)p)->f80));
    return p;
}
