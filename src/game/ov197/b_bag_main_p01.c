/*
 * file:     b_bag_main_p01.c
 * unit:     yes
 * function: func_0220B31C, func_0220B3EC, func_0220B4B8, func_0220B520, func_0220B584, func_0220B6C4, func_0220B774, func_0220B78C, func_0220B814, func_0220B880, func_0220B904, func_0220B928, func_0220B980, func_0220B990, func_0220B9A4, func_0220B9D8, func_0220BA2C, func_0220BB1C, func_0220BB78, func_0220BB98, func_0220BBD8, func_0220BBE4
 * address:  0x0220B31C
 * region:   ov197
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045334 0x02045334 arm
 *   func_02045738 0x02045738 arm
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201D304 0x0201D304 thumb
 *   d_0220DA38 0x0220DA38 data a4
 *   func_0201EFA4 0x0201EFA4 thumb
 *   d_0220DA3C 0x0220DA3C data a4
 *   func_02041300 0x02041300 arm
 *   d_0220DA28 0x0220DA28 data a1
 *   d_0220DA19 0x0220DA19 data a1
 *   func_0220B1D4 0x0220B1D4 thumb ov197
 *   func_020457B0 0x020457B0 arm
 *   func_02020FB4 0x02020FB4 thumb
 *   d_0220DA08 0x0220DA08 data a1
 *   func_0201F73C 0x0201F73C thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0220B0B0 0x0220B0B0 thumb
 *   func_0220B094  0x0220B094  thumb  ov196
 *   sub_02007F68 0x02007F68 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   func_02048F60 0x02048F60 arm
 *   func_020081DC 0x020081DC thumb
 *   func_020307B0 0x020307B0 arm
 *   d_0220DB3C 0x0220DB3C data a4
 *   d_0220DB3F 0x0220DB3F data a4
 *   func_0202F114 0x0202F114 thumb
 *   func_0202F138 0x0202F138 thumb
 *   sub_0202F144 0x0202F144 thumb
 *   func_0202C9B4 0x0202C9B4 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_0202CA3C 0x0202CA3C thumb
 *   func_0202CFEC 0x0202CFEC thumb
 *   func_0202CB18 0x0202CB18 thumb
 *   func_02049238 0x02049238 arm
 *   func_0202CB4C 0x0202CB4C thumb
 *   d_0220DB44 0x0220DB44 data a4
 */
#include "../../matched/include/Obj00845.h"
#include "../../matched/include/Obj24993.h"
#include "../../matched/include/Obj24994.h"
#include "../../matched/include/Obj00314.h"
#include "../../matched/include/Obj24999.h"
#include "../../matched/include/Obj25000.h"
#include "../../matched/include/Obj25001.h"
#include "../../matched/include/Obj25002.h"
#include "../../matched/include/Obj25003.h"
#include "../../matched/include/Obj25004.h"
#include "../../matched/include/Obj04597.h"
#include "../../matched/include/Obj25005.h"
#include "../../matched/include/Obj25007.h"
#include "../../matched/include/Obj25008.h"
#include "../../matched/include/Obj14543.h"
#include "../../matched/include/Obj25009.h"
#include "../../matched/include/Obj25010.h"
#include "../../matched/include/Obj06648.h"
#include "../../matched/include/Obj14544.h"
#include "../../matched/include/Obj05520.h"
#include "../../matched/include/Obj25011.h"
#include "../../matched/include/Obj08354.h"
#include "../../matched/include/Obj01176.h"
#include "../../matched/include/Obj25012.h"
#include "../../matched/include/Obj25013.h"

struct CharBuf;
struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
struct Cfg;
struct Item;
struct WinMgr;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16_0220B31C;

typedef unsigned long u32_0220B31C;

typedef signed short s16_0220B3EC;

typedef unsigned long u32_0220B3EC;

typedef unsigned int   u32_0220B4B8;

typedef signed short s16_0220B584;

typedef unsigned long u32_0220B584;

typedef unsigned int u32_0220B78C;

typedef unsigned int   u32_0220B814;

typedef struct { unsigned short entry[36][2]; } Row;

typedef unsigned int u32_0220B880;

typedef unsigned int u32_0220B928;

typedef unsigned int   u32_0220B990;

typedef signed short   s16_0220B990;

typedef signed char    s8;

typedef short s16_0220B9A4;

typedef unsigned int u32_0220B9A4;

typedef struct In { u8 sel; u8 pad[0xc]; u16 cur; } In;

typedef struct S { u8 *d; u8 pad[0x533 - 4]; In in; } S;

typedef short s16_0220BA2C;

typedef unsigned int u32_0220BA2C;

typedef short s16_0220BBD8;

typedef unsigned int u32_0220BBD8;

typedef unsigned long u32_0220BBE4;

typedef struct {u16 member;u8 w,h;} Config;

extern void *func_02045770(struct Descriptor *p);
extern u8 func_02045738(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32_0220B31C index);
extern void func_0201EFA4(struct WordSet *p, u32_0220B31C i, u32_0220B31C a, u32_0220B31C b, u32_0220B31C c, u32_0220B31C d);
extern void func_0201EF40(struct WordSet *p, u32_0220B31C i, u32_0220B31C v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C724(void *owner, u32_0220B31C a, u32_0220B31C b, u32_0220B31C c, u32_0220B31C d, u32_0220B31C e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045334(struct Descriptor *d);
extern u32_0220B31C func_0201D304(struct StrObj *s, u32_0220B31C a, u32_0220B31C b);
extern void func_02041300(unsigned,int,int,int,u8,u8,u8);
extern void func_0220B1D4(char *,int,int,int,unsigned short);
extern struct U16Vec *func_020457B0(u32_0220B814 capacity, u32_0220B814 heapId);
extern void func_02020FB4(void *,unsigned,unsigned);
extern void func_0201F73C(void *, int, int, int);
extern void func_0201DD78(u32_0220B928 r, u32_0220B928 g, u32_0220B928 b);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *a0, u32_0220B928 a1, u32_0220B928 a2, void *a3, u32_0220B928 a4, u32_0220B928 a5, void *a6, u32_0220B928 a7, u16 a8, u32_0220B928 a9);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32_0220B928 bit);
extern int func_0220B0B0(void *, int, int);
extern u32_0220B990 func_0220B094(u8 *, u32_0220B990);
extern u32_0220B9A4 sub_02007F68(u8 *,u16,u16,u16);
extern void *func_02048F60(u32_0220BA2C archive_id, u32_0220BA2C member, u32_0220BA2C heap);
extern struct Item *func_020081DC(u8 *base, u32_0220BA2C id, u32_0220BA2C index);
extern u32_0220BA2C func_020307B0(void *p);
extern unsigned func_0202F114(const unsigned char *,unsigned);
extern unsigned short func_0202F138(unsigned);
extern u32_0220BBD8 sub_0202F144(u32_0220BBD8);
extern struct WinMgr *func_0202C9B4(u32_0220BBE4,u32_0220BBE4,u32_0220BBE4);
extern void *func_020490F4(u32_0220BBE4 id, u32_0220BBE4 heap);
extern void func_0202CA3C(struct WinMgr *mgr, u32_0220BBE4 idx, u32_0220BBE4 bg, u32_0220BBE4 w, u32_0220BBE4 h);
extern void func_0202CFEC(struct Obj *o, u32_0220BBE4 i, u8 a, u8 b, s8 c, s8 d);
extern void func_0202CB18(struct WinMgr *mgr,u32_0220BBE4,void *,u32_0220BBE4,u32_0220BBE4);
extern void func_02049238(void *);
extern void func_0202CB4C(struct WinMgr *mgr,u32_0220BBE4,s8,s8);
void func_0220B31C(char *p,u32_0220B31C i,int id,int w,int unused,int unused2);
void func_0220B3EC(char *p, u32_0220B3EC i, int id, int w, int unused, int y, int unused2);
void func_0220B4B8(char *p,u16 i);
void func_0220B520(char *p);
void func_0220B584(char *p);
void func_0220B6C4(char *p);
void func_0220B774(char *a);
void func_0220B78C(u8 *p, u32_0220B78C idx);
void func_0220B814(char *p,int n);
void func_0220B880(char *p);
void func_0220B904(char *p);
void func_0220B928(char *p);
int func_0220B980(char *a);
u32_0220B990 func_0220B990(u8 *p);
int func_0220B9A4(char *p);
void func_0220B9D8(u8 *p);
void func_0220BA2C(u8 *p);
void func_0220BB1C(char *p);
void func_0220BB78(char *p);
unsigned func_0220BB98(const char *p, unsigned n);
int func_0220BBD8(u32_0220BBD8 key);
void func_0220BBE4(char *p);
extern const char d_0220DA38[];
extern const char d_0220DA3C[];
extern const char d_0220DA28[],d_0220DA19[];
extern const u8 d_0220DA08[];
extern const u8 d_0220DB3C[];
extern const u8 d_0220DB3F[];
extern const Config d_0220DB44[14];

/*
 * Width: printer x truncates to signed halfword in original; extern keeps s16 despite owner u32.
 */
void func_0220B31C(char *p,u32_0220B31C i,int id,int w,int unused,int unused2)
{
    char *windows=p+0x28;
    void *handle=*(void **)(windows+w*8);
    void *text;
    void *font;
    void *surface;
    u32_0220B31C width;
    int page;
    func_02043B5C(func_02045770(handle),0);
    page=(u32_0220B31C)p+((u8 *)p)[0x533]*0x90;
    if(*(u16 *)(page+i*4+0x150)!=0){
        text=func_02045EC0(((struct Obj00845 *)p)->fC,*(u32_0220B31C *)(d_0220DA38+id*8));
        page=(u32_0220B31C)p+((u8 *)p)[0x533]*0x90;
        func_0201EF40(((struct Obj00845 *)p)->f10,0,*(u16 *)(page+i*4+0x150));
        func_0201F250(((struct Obj00845 *)p)->f10,((struct Obj00845 *)p)->f14,text);
        width=func_0201D304(((struct Obj00845 *)p)->f14,((struct Obj24993 *)(*(char * *)&((struct Obj00845 *)p)->f0))->f4,0);
        width=func_02045738(handle)*8-width;
        font=((struct Obj00845 *)p)->f18;
        surface=func_02045770(*(void **)(windows+w*8));
        func_0201C724(font,(u32_0220B31C)surface,(s16_0220B31C)(width/2),(s16_0220B31C)7,(u32_0220B31C)(((struct Obj00845 *)p)->f14),((struct Obj24994 *)(*(char * *)&((struct Obj00845 *)p)->f0))->f4,0x3C40);
        (p+w*8)[0x2C]=1;
        func_02045808(text);
    }else{
        func_02045334(handle);
    }
}

/*
 * Width: original narrows y to signed halfword before printer; corresponding extern keeps s16 despite owner u32.
 */
void func_0220B3EC(char *p, u32_0220B3EC i, int id, int w, int unused, int y, int unused2)
{
  char *windows = p + 0x28;
  void *handle = *((void **) (windows + (w * 8)));
  void *text;
  void *font;
  void *surface;
  int page;
  char *tmp;
  u16 pad;
  u32_0220B3EC *tmp1;
  char *tmp2;
  func_02043B5C(func_02045770(handle), 0);
  page = ((u32_0220B3EC) p) + (((u8 *) p)[0x533] * 0x90);
  if (((*((u16 *) ((page + (i * 4)) + 0x152))) != 0) && ((*((int *) ((*((char **) p)) + 8))) != 1))
  {
    text = func_02045EC0(*((void **) (p + 0xC)), *((u32_0220B3EC *) (d_0220DA3C + (id * 8))));
    page = ((u32_0220B3EC) p) + (((u8 *) p)[0x533] * 0x90);
    func_0201EFA4(*((void **) (p + 0x10)), 0, *((u16 *) (((u32_0220B3EC) (page + (i * 4))) + 0x152)), 3, 0, 1);
    tmp2 = p + 0x14;
    func_0201F250(*((void **) (p + 0x10)), *((void **) tmp2), text);
    font = *((void **) (p + 0x18));
    surface = func_02045770(*((void **) (windows + (w * 8))));
    tmp = p + 0x14;
    tmp1 = (u32_0220B3EC *) ((*((char **) p)) + 4);
    func_0201C724(font, (u32_0220B3EC)surface, (s16_0220B3EC)0, (s16_0220B3EC)y, (u32_0220B3EC)(*((void **) tmp)), *tmp1, 0x3C40);
    (p + (w * 8))[0x2C] = 1;
    func_02045808(text);
  }
  else
  {
    func_02045334(handle);
  }
}

/*
 * lever: assign the doubled index after the flag branch; the flag is unsigned byte evidence.
 */
void func_0220B4B8(char *p,u16 i)
{
    int base=*(short *)(*(char * *)&((struct Obj00845 *)p)->f0+((u8 *)p)[0x533]*2+0x38)*6;
    int row=5;
    int twice;
    if(((u8 *)p)[0x141]!=0)row=0x11;
    twice=i*2;
    func_0220B31C(p,i+base,i,row+twice,0,0);
    func_0220B3EC(p,i+base,i,row+1+twice,0,4,0);
}

void func_0220B520(char *p)
{
    u16 i;
    func_02041300(5,0,0,0,0x20,0x13,0x11);
    for(i=0;i<6;i++)func_0220B4B8(p,i);
    if(((u8 *)p)[0x141]==0)
        *(const char * *)&((struct Obj00314 *)p)->f59C=d_0220DA28;
    else
        *(const char * *)&((struct Obj00314 *)p)->f59C=d_0220DA19;
    ((u8 *)p)[0x141]^=1;
}

/*
 * matching: parenthesised byte-pointer plus page keeps the page load before the far-field add; a flat offset sum differs in two bytes.
 * Width: original narrows x to signed 16 bits before each 0201C724 call; s16 extern preserves those caller truncations despite owner u32 x.
 */
void func_0220B584(char *p)
{
    void *handle=((struct Obj00314 *)p)->f118;
    void *surface=func_02045770(handle);
    void *text;
    u32_0220B584 width;
    u32_0220B584 x;
    void *font;
    void *lastSurface;
    func_02043B5C(surface,0);
    text=func_02045EC0(((struct Obj00314 *)p)->fC,28);
    width=func_0201D304(text,((struct Obj24999 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f4,0);
    x=(func_02045738(handle)*8-width)/2;
    func_0201C724(((struct Obj00314 *)p)->f18,(u32_0220B584)surface,(s16_0220B584)x,(s16_0220B584)4,(u32_0220B584)text,((struct Obj25000 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f4,0x3C40);
    func_02045808(text);
    text=func_02045EC0(((struct Obj00314 *)p)->fC,29);
    func_0201EFA4(((struct Obj00314 *)p)->f10,0,((u8 *)p+((u8 *)p)[0x533])[0x539]+1,2,0,1);
    func_0201F250(((struct Obj00314 *)p)->f10,((struct Obj00314 *)p)->f14,text);
    func_0201C724(((struct Obj00314 *)p)->f18,(u32_0220B584)surface,(s16_0220B584)(x+width),(s16_0220B584)4,(u32_0220B584)(((struct Obj00314 *)p)->f14),((struct Obj25001 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f4,0x3C40);
    func_02045808(text);
    text=func_02045EC0(((struct Obj00314 *)p)->fC,30);
    func_0201EFA4(((struct Obj00314 *)p)->f10,0,*(s16_0220B584 *)(*(char * *)&((struct Obj00314 *)p)->f0+((u8 *)p)[0x533]*2+0x38)+1,2,0,1);
    func_0201F250(((struct Obj00314 *)p)->f10,((struct Obj00314 *)p)->f14,text);
    width=func_0201D304(((struct Obj00314 *)p)->f14,((struct Obj25002 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f4,0);
    font=((struct Obj00314 *)p)->f18;
    lastSurface=func_02045770(((struct Obj00314 *)p)->f118);
    func_0201C724(font,(u32_0220B584)lastSurface,(s16_0220B584)(x-width),(s16_0220B584)4,(u32_0220B584)(((struct Obj00314 *)p)->f14),((struct Obj25003 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f4,0x3C40);
    ((u8 *)p)[0x11C]=1;
    func_02045808(text);
}

void func_0220B6C4(char *p)
{
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj00314 *)p)->f110)),0);
    if(((struct Obj25004 *)(*(char * *)&((struct Obj00314 *)p)->f0))->f8!=1) {
        switch(((unsigned char *)p)[0x533]) {
        case 0:func_0220B1D4(p,29,22,4,0x3c40);func_0220B1D4(p,29,23,20,0x3c40);break;
        case 1:func_0220B1D4(p,29,24,4,0x3c40);func_0220B1D4(p,29,25,20,0x3c40);break;
        case 2:func_0220B1D4(p,29,26,12,0x3c40);break;
        case 3:func_0220B1D4(p,29,27,12,0x3c40);break;
        }
    } else func_02045334((struct Descriptor *)((struct Obj00314 *)p)->f110);
}


void func_0220B774(char *a)
{
    func_0220B520(a);
    func_0220B6C4(a);
    func_0220B584(a);
}


void func_0220B78C(u8 *p, u32_0220B78C idx)
{
    void *win = *(void **)(p + 0x120);
    void *msg = func_02045EC0(*(void **)(p + 0xc), 9);
    u8 sel = *(u8 *)(p + 0x533);
    u8 *row = p + sel * 0x90;
    void *w;
    func_0201EF40(*(void **)(p + 0x10), 0, *(u16 *)(row + 0x150 + idx * 4));
    func_0201F250(*(void **)(p + 0x10), *(void **)(p + 0x14), msg);
    func_02043B5C(func_02045770(win), 0);
    w = *(void **)(p + 0x18);
    func_0201C724(w, (u32_0220B78C)func_02045770(*(void **)(p + 0x120)), 0, 0,
                  *(u32_0220B78C *)(p + 0x14), *(u32_0220B78C *)(*(u8 **)p + 4), 0x3C40);
    *(u8 *)(p + 0x124) = 1;
    func_02045808(msg);
}

/*
 * matching: named row index in Row[36][2] restores base-add-before-column-shift; raw byte row differs in seven bytes.
 */
void func_0220B814(char *p,int n)
{
    void *owner;
    int index;
    Row *row;
    void *buf=func_020457B0(130,((struct Obj25005 *)(*(char * *)&((struct Obj04597 *)p)->f0))->fC);
    index=((struct Obj04597 *)p)->f533;
    row=(Row *)(p+0x150);
    func_02020FB4(buf,row[index].entry[n][0],((struct Obj25007 *)(*(char * *)&((struct Obj04597 *)p)->f0))->fC);
    owner=((struct Obj04597 *)p)->f18;
    func_0201C724(owner,(unsigned)func_02045770(((struct Obj04597 *)p)->f130),4,0,(unsigned)buf,((struct Obj25008 *)(*(char * *)&((struct Obj04597 *)p)->f0))->f4,0x3c40);
    ((struct Obj04597 *)p)->f134=1;
    func_02045808(buf);
}

/*
 * lever: the scaled index is its own int local added after each field
 *   offset (`*(short *)(*(char **)p + 0x30 + off)`), which puts the ldrb and
 *   lsls ahead of the `ldr r0,[r4]` base load (0220B8A4..0220B8AA). A row
 *   pointer `q = *(char **)p + idx*2` (either operand order, or as a short
 *   element address) loads the base first: 9 bytes.
 * prototype: func_0220B78C has no matched definition; (char *, unsigned) and
 *   void taken from its listing (r1 scaled by 4 as an index, no r0 use after).
 */
void func_0220B880(char *p)
{
    unsigned i;
    int x, y;
    int off;
    for (i = 31; i <= 34; i++)
        func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x28 + i * 8)), 0);
    off = *(u8 *)(p + 0x533) * 2;
    x = *(short *)(*(char **)p + 0x30 + off);
    y = *(short *)(*(char **)p + 0x38 + off) * 6;
    func_0220B78C((u8 *)p, x + y);
    func_0220B3EC(p, x + y, 0, 32, 0, 0, 0);
    func_0220B814(p, x + y);
    func_0220B1D4(p, 34, 31, 0, 0x3c40);
    *(const u8 **)(p + 0x59c) = d_0220DA08;
}


void func_0220B904(char *p)
{
    func_0201F73C(((struct Obj14543 *)p)->f24, 2, 1, 0xb);
    func_02043B5C(func_02045770(((struct Obj14543 *)p)->f24), 0xf);
    func_0220B928(p);
}

/*
 * lever: func_02012FFC() called inside the argument list (as the ov010
 *   0x02169EBC twin does) with its real signed char return; a font local
 *   computed before the call let mwcc CSE the two *p reads (DIFF 42).
 * prototypes: from the matched arm9 definitions, except func_0201CCE4,
 *   whose definition is declared void although it forwards func_0201CD10's
 *   r0; the return type is the ov010 twin's void *.
 */
void func_0220B928(char *p)
{
    void *d;
    func_0201DD78(1, 2, 0);
    *(void **)(p + 0x1c) = func_0201CCE4(*(void **)(p + 0x24), 0, 0, *(void **)(p + 0x14),
        *(u32_0220B928 *)(*(char **)p + 4), func_02012FFC(), *(void **)(p + 4), 10,
        *(u16 *)(*(char **)p + 0xc), 15);
    d = *(void **)(p + 0x24);
    func_02045334(d);
    func_02045374(d);
    func_02041B6C(func_02045730(d));
}


int func_0220B980(char *a)
{
    return func_0220B0B0(a + 0x28, ((struct Obj25009 *)a)->f18, 0x23);
}


/*
 * Addresses are Black-image addresses.
 */
u32_0220B990 func_0220B990(u8 *p)
{
    return func_0220B094(p + 0x28, ((struct Obj25010 *)p)->f59C);
}

/*
 * EXACT* tail: two zero alignment bytes after the function.
 */
int func_0220B9A4(char *p) { char *q; if(((struct Obj06648 *)p)->f540==0) return 0; q=*(char * *)&((struct Obj06648 *)p)->f0; if(sub_02007F68(*(u8 * *)&((struct Obj14544 *)q)->f0,((struct Obj06648 *)p)->f540,1,((struct Obj14544 *)q)->fC)==0) { ((struct Obj06648 *)p)->f540=0; ((struct Obj06648 *)p)->f542=0; return 0; } return 1; }

void func_0220B9D8(u8 *p)
{
    unsigned int i = 0;
    u8 sel = *(u8 *)(p + 0x533);
    u8 *row = p + sel * 0x90;
    u16 cur = *(u16 *)(p + 0x533 + 0xd);
    for (; i < 36; i++) {
        if (cur == *(u16 *)(row + 0x150 + i * 4)) {
            *(u16 *)(*(u8 **)p + sel * 2 + 0x30) = i % 6;
            *(u16 *)(*(u8 **)p + *(u8 *)(p + 0x533) * 2 + 0x38) = i / 6;
            return;
        }
    }
}


/*
 * 2026-10-05 (wD9r lane05): EXACT. The record address is an integer local reused for the row offset:
 *   `u32 e = c * 0x90; e = q[0x535] * 4 + (u32)(p + e);`. The mul stays first (e is defined in its own
 *   statement and used once more), and idx*4 is the first operand of the final add, so e shares idx*4's
 *   register (r0) and row takes r4 as in the original.
 */
void func_0220BA2C(u8 *p)
{
    u8 *tbl;
    u16 *r;
    u32_0220BA2C i, j, k;

    tbl = func_02048F60(0xE8, 0, *(u16 *)(*(u8 **)p + 0xC));
    i = 0;
    do {
        j = 0;
        for (;;) {
            r = (u16 *)func_020081DC(**(void ***)p, d_0220DB3C[i], (u16)j);
            if (r == 0)
                break;
            if (r[0] != 0 && r[1] != 0) {
                u32_0220BA2C m = tbl[r[0]];
                for (k = 0; k < 4; k++) {
                    if (m & (1 << k)) {
                        int c = d_0220DB3F[k];
                        u8 *q = p + c;
                        u32_0220BA2C e = c * 0x90;
                        e = q[0x535] * 4 + (u32_0220BA2C)(p + e);
                        *(u16 *)(e + 0x150) = r[0];
                        *(u16 *)(e + 0x152) = r[1];
                        q[0x535]++;
                    }
                }
            }
            j++;
        }
        i++;
    } while (i < 3);
    func_020307B0(tbl);
    for (i = 0; i < 4; i++) {
        u8 v = p[i + 0x535];
        u8 *s;
        if (v == 0)
            p[i + 0x539] = 0;
        else
            p[i + 0x539] = (v - 1) / 6;
        s = *(u8 **)p + i * 2;
        if (p[i + 0x539] < *(s16_0220BA2C *)(s + 0x38))
            *(s16_0220BA2C *)(s + 0x38) = p[i + 0x539];
    }
}

void func_0220BB1C(char *p)
{
    unsigned i;
    for(i=0;i<46;i++) {
        if(func_0202F114(*(const unsigned char * *)&((struct Obj25011 *)(*(char * *)&((struct Obj05520 *)p)->f0))->f10,i)==1) {
            *(unsigned short *)(p+0x150+((struct Obj05520 *)p)->f535*4)=func_0202F138(i);
            *(unsigned short *)(p+0x152+((struct Obj05520 *)p)->f535*4)=1;
            (((struct Obj05520 *)p)->f535)++;
        }
    }
    ((struct Obj05520 *)p)->f539=(((struct Obj05520 *)p)->f535-1)/6;
}


void func_0220BB78(char *p)
{
    ((struct Obj08354 *)p)->f270 = 4;
    ((struct Obj08354 *)p)->f272 = 0x1e;
    ((struct Obj08354 *)p)->f537 = 1;
    ((struct Obj08354 *)p)->f53B = 0;
}

/*
 * lever: one statement n = (n + k * 6) << 2, then p += index * 0x90 and a
 *   const u16 pointer s = p + n read as s[0xa8] / s[0xa9]; the byte-offset
 *   spelling (n += ..; n *= 4; slot + 0x150) sank the shift after the
 *   0x90 multiply (13 bytes), and a typed row struct folded 0x150 (60 bytes).
 */
unsigned func_0220BB98(const char *p, unsigned n)
{
    unsigned index = *(u8 *)(p + 0x533);
    const u16 *s;
    n = (n + *(short *)(*(char **)p + 0x38 + index * 2) * 6) << 2;
    p += index * 0x90;
    s = (const u16 *)(p + n);
    if (s[0xa8] != 0 && s[0xa9] != 0) return s[0xa8];
    return 0;
}

/*
 * Forward entry r0 as the key. The explicit result truncation requires a wide extern return.
 */
int func_0220BBD8(u32_0220BBD8 key) { return (u16)sub_0202F144(key); }

void func_0220BBE4(char *p)
{
    void *arc;
    unsigned i;
    ((struct Obj01176 *)p)->f520=func_0202C9B4(2,14,((struct Obj25012 *)(*(char * *)&((struct Obj01176 *)p)->f0))->fC);
    arc=func_020490F4(99,(u16)((((struct Obj25013 *)(*(char * *)&((struct Obj01176 *)p)->f0))->fC&0x7FFF)|0x8000));
    for(i=0;i<14;i++){
        func_0202CA3C(((struct Obj01176 *)p)->f520,i,6,d_0220DB44[i].w,d_0220DB44[i].h);
        func_0202CFEC(((struct Obj01176 *)p)->f520,i,0,64,0,64);
        func_0202CB18(((struct Obj01176 *)p)->f520,i,arc,d_0220DB44[i].member,1);
    }
    func_02049238(arc);
    func_0202CB4C(((struct Obj01176 *)p)->f520,0,0,1);
    func_0202CB4C(((struct Obj01176 *)p)->f520,1,0,10);
    func_0202CB4C(((struct Obj01176 *)p)->f520,2,16,1);
    func_0202CB4C(((struct Obj01176 *)p)->f520,3,16,10);
    func_0202CB4C(((struct Obj01176 *)p)->f520,4,32,1);
    func_0202CB4C(((struct Obj01176 *)p)->f520,5,48,1);
    func_0202CB4C(((struct Obj01176 *)p)->f520,6,32,7);
    func_0202CB4C(((struct Obj01176 *)p)->f520,7,48,7);
    func_0202CB4C(((struct Obj01176 *)p)->f520,8,32,13);
    func_0202CB4C(((struct Obj01176 *)p)->f520,9,48,13);
    func_0202CB4C(((struct Obj01176 *)p)->f520,11,32,19);
    func_0202CB4C(((struct Obj01176 *)p)->f520,12,37,19);
}
