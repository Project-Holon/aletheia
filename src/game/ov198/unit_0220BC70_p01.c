/*
 * file:     unit_0220BC70_p01.c
 * unit:     yes
 * function: func_0220BC70, func_0220BD34, func_0220BD84, func_0220BDA0, func_0220BDD4
 * address:  0x0220BC70
 * region:   ov198
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
 *   d_02211BDA 0x02211BDA data a1
 *   d_02211B80 0x02211B80 data a1
 *   d_02211CB0 0x02211CB0 data a1
 *   d_02211BFE 0x02211BFE data a1
 *   d_02211C24 0x02211C24 data a1
 *   d_02211B98 0x02211B98 data a1
 *   d_02211BB6 0x02211BB6 data a1
 *   d_02211C68 0x02211C68 data a1
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020452E8 0x020452E8 arm
 */
#include "../../matched/include/Obj25130.h"
#include "../../matched/include/Obj14554.h"
#include "../../matched/include/Obj25132.h"

struct Descriptor;
struct CharBuf;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Item { u8 a,b,c,d,e,f; } Item;

typedef struct Bits { unsigned char low:5; unsigned char high:3; } Bits;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 func_020452E8(struct Descriptor *d);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
void func_0220BC70(u8 *p,u32 state);
void func_0220BD34(u8 *p);
void func_0220BD84(u8 *p);
void func_0220BDA0(u8 *p);
void func_0220BDD4(char *p);
extern Item d_02211BDA[],d_02211B80[],d_02211CB0[],d_02211BFE[],d_02211C24[],d_02211B98[],d_02211BB6[],d_02211C68[];

/*
 * precondition: game callers supply state 0..8; every case initializes s.
 * evidence: C88's nine callers pass constants0..8; F4E0 dominates BC24
 * with state-byte2180 stores0/4/6. C88 stores its bounded state at2177+9.
 * Domain and decoded-call audit: Wave30 S26/BC70-domain-review.md.
 */
void func_0220BC70(u8 *p,u32 state)
{
    Item *s;
    u32 i;
    func_0220BD84(p);
    func_0220BD34(p);
    switch(state) {
    case 0: case 8: s=d_02211BDA; p[0x2174]=6; break;
    case 1: s=d_02211B80; p[0x2174]=4; break;
    case 2: s=d_02211CB0; p[0x2174]=22; break;
    case 3: s=d_02211BFE; p[0x2174]=6; break;
    case 4: s=d_02211C24; p[0x2174]=11; break;
    case 5: s=d_02211B98; p[0x2174]=5; break;
    case 6: s=d_02211BB6; p[0x2174]=6; break;
    case 7: s=d_02211C68; p[0x2174]=12; break;
    }
    for(i=0;i<p[0x2174];i++,s++)
        *(void **)(p+i*8+0x1F70)=(void *)func_020450F0(s->a,s->b,s->c,s->d,s->e,s->f,1);
}

void func_0220BD34(u8 *p)
{
    if (((Bits *)(p+0x2175))->low == 1)
        ((struct Obj25130 *)p)->f2170=(void *)func_020450F0(5,0,0,32,16,0,1);
    ((Bits *)(p+0x2175))->low ^= 1;
}


/*
 * Addresses are Black-image addresses.
 */
void func_0220BD84(u8 *p)
{
    u32 t = ((struct Obj14554 *)p)->f2170;

    if (t != 0) {
        func_020452E8((struct Descriptor *)t);
        ((struct Obj14554 *)p)->f2170 = 0;
    }
}

void func_0220BDA0(u8 *p){u32 i;for(i=0;i<p[0x2174];i++)func_02043B5C(func_02045770(*(struct Descriptor **)(p+i*8+0x1f70)),0);}


void func_0220BDD4(char *p)
{
    unsigned int i;
    for (i = 0; i < ((struct Obj25132 *)p)->f2174; i++)
    {
        func_020452E8(*(void **)(p + 0x1f70 + i * 8));
    }
}
