/*
 * file:     mystery_util_p02.c
 * unit:     yes
 * function: func_021DA3EC, func_021DA4A8, func_021DA4DC, func_021DA698, func_021DA6D0, func_021DA840, func_021DA84C, func_021DA854, func_021DA890, func_021DA898, func_021DA8AC, func_021DA8B0, func_021DA8B8, func_021DA8C0, func_021DA8C4, func_021DA8CC, func_021DA958, func_021DA978, func_021DA994, func_021DA9EC, func_021DA9F0, func_021DA9F8, func_021DAA28, func_021DAAA4, func_021DAB50, func_021DAC18, func_021DAE1C, func_021DAEF0, func_021DAFCC, func_021DB018, func_021DB3E8, func_021DB478, func_021DB528, func_021DB54C
 * address:  0x021DA3EC
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
 *   func_020457B0 0x020457B0 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045838 0x02045838 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_021D9BE8 0x021D9BE8 thumb ov121
 *   func_02045770 0x02045770 arm
 *   func_02043814 0x02043814 arm
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021DA1BC 0x021DA1BC thumb ov121
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045874 0x02045874 arm
 *   func_02045808 0x02045808 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   d_021DFBA0 0x021DFBA0 data a4
 *   d_021DF7C0 0x021DF7C0 data a4
 *   d_021DF76C 0x021DF76C data a4
 *   d_021DF770 0x021DF770 data a4
 *   func_021DA2A8 0x021DA2A8 thumb ov121
 *   func_021DA280 0x021DA280 thumb ov121
 *   func_020409B4 0x020409B4 arm
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021DA2C8  0x021DA2C8  thumb
 *   func_02043678 0x02043678 arm
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 *   func_020257D0  0x020257D0  thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_020437DC 0x020437DC arm
 *   func_020437E4 0x020437E4 arm
 *   d_020A1B38 0x020A1B38 data a4
 *   func_02061CA4 0x02061CA4 arm
 *   func_02082A7C 0x02082A7C arm
 *   func_0203084C 0x0203084C arm
 *   func_02040618 0x02040618 arm
 *   func_021DBDF4 0x021DBDF4 thumb ov121
 *   func_021DCFC8 0x021DCFC8 thumb ov121
 *   func_021DBDBC 0x021DBDBC thumb ov121
 *   func_021DBF04 0x021DBF04 thumb ov121
 *   func_021DC02C 0x021DC02C thumb ov121
 *   func_021DD24C 0x021DD24C thumb ov121
 *   func_021DE0AC 0x021DE0AC thumb ov121
 *   func_021DC08C 0x021DC08C thumb ov121
 *   func_021DCEC4 0x021DCEC4 thumb ov121
 *   d_021DFBB0 0x021DFBB0 data a4
 *   d_021DF8FC 0x021DF8FC data a4
 *   d_021DF890 0x021DF890 data a4
 *   func_021DD980 0x021DD980 thumb ov121
 *   func_021DD1FC 0x021DD1FC thumb ov121
 *   func_021D9E04 0x021D9E04 thumb ov121
 *   func_0200A348 0x0200A348 thumb
 *   func_021DBEE4 0x021DBEE4 thumb ov121
 *   func_020414EC 0x020414EC arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021DD240 0x021DD240 thumb ov121
 *   func_021DDF84 0x021DDF84 thumb ov121
 *   func_021DE0DC 0x021DE0DC thumb ov121
 *   func_021DCFA4 0x021DCFA4 thumb ov121
 *   func_021D9B34 0x021D9B34 thumb ov121
 *   func_021DD9CC 0x021DD9CC thumb ov121
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_02040C14 0x02040C14 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045374 0x02045374 arm
 *   func_021D99A4 0x021D99A4 thumb ov121
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_021DCF54 0x021DCF54 thumb ov121
 *   func_0204B294 0x0204B294 arm
 *   func_0204B604 0x0204B604 arm
 *   func_02040588 0x02040588 arm
 *   data_021DF86E 0x021DF86E data a1
 *   func_02040DA8 0x02040DA8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_020452E8 0x020452E8 arm
 *   func_021D9A40 0x021D9A40 thumb ov121
 *   func_021DBDB8 0x021DBDB8 thumb ov121
 *   func_021D9B28 0x021D9B28 thumb ov121
 *   func_021D9B2C 0x021D9B2C thumb ov121
 *   func_021D9AC8 0x021D9AC8 thumb ov121
 *   func_021DB938 0x021DB938 thumb ov121
 *   d_021DF86E 0x021DF86E data ov121 a2
 *   d_021DF86F 0x021DF86F data ov121 a1
 *   func_021DBF08 0x021DBF08 thumb ov121
 *   func_021DBF10 0x021DBF10 thumb ov121
 *   func_021DBF40 0x021DBF40 thumb ov121
 *   func_021DBF70 0x021DBF70 thumb ov121
 *   func_021DBF9C 0x021DBF9C thumb ov121
 *   func_021DBFE4 0x021DBFE4 thumb ov121
 *   func_021DC004 0x021DC004 thumb ov121
 *   func_021DC024 0x021DC024 thumb ov121
 *   func_021DC03C 0x021DC03C thumb ov121
 *   func_02041300 0x02041300 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02045334 0x02045334 arm
 *   func_0204B6F4 0x0204B6F4 arm
 */
#include "../../matched/include/Obj03262.h"
#include "../../matched/include/Obj06449.h"
#include "../../matched/include/Obj22885.h"
#include "../../matched/include/Obj22886.h"
#include "../../matched/include/Obj22887.h"
#include "../../matched/include/Obj22888.h"
#include "../../matched/include/Obj13954.h"
#include "../../matched/include/Obj22889.h"
#include "../../matched/include/Obj03786.h"
#include "../../matched/include/Obj00360.h"
#include "../../matched/include/Obj06450.h"
#include "../../matched/include/Obj22893.h"
#include "../../matched/include/Obj13955.h"
#include "../../matched/include/Obj06451.h"
#include "../../matched/include/Obj08095.h"
#include "../../matched/include/Obj10414.h"
#include "../../matched/include/Obj10415.h"
#include "../../matched/include/Obj03787.h"
#include "../../matched/include/Obj22897.h"
#include "../../matched/include/Obj05358.h"
#include "../../matched/include/Obj02470.h"
#include "../../matched/include/Obj00910.h"
#include "../../matched/include/Obj01058.h"
#include "../../matched/include/Obj01153.h"
#include "../../matched/include/Obj10417.h"
#include "../../matched/include/Obj22899.h"
#include "../../matched/include/Obj00828.h"

struct CharBuf;
struct U16Vec;
struct MsgBank;
struct Bmp;
struct Descriptor;
struct Obj;
struct Vec2;
struct Grid;
struct Param;
struct Sys;
struct Obj020437AC;
struct PrintSys;
struct StrObj;
struct Actor;
struct Cfg;
struct WordSet;
typedef unsigned int u32;
typedef signed short s16;

typedef unsigned short u16;


typedef unsigned char u8;

typedef struct { int x,y; } Pair;

struct In {
    void *bank;
    u32 f4;
    u32 f8;
    u32 *fC_;
    u32 ids[4];
    u32 f20;
    u16 f24;
    u16 f26;
    u16 f28;
    u16 f2a;
    s16 f2c;
    s16 f2e;
    u16 f30;
    u16 pad32;
    u32 f34;
    u32 f38;
    u32 *f3c;
};

struct Out {
    void *f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u16 pad10;
    u16 pal[5];
    u16 pad1c[3];
    u16 f22;
    u16 f24;
    u16 f26;
    u16 f28;
    u16 f2a;
    u16 f2c;
    u16 f2e;
    u16 f30;
    u16 pad32;
    u32 f34;
    u32 f38;
    u8 pad3c[0x24];
    u32 *f60;
};

struct Rec {
    u8 a;
    u8 b;
    u8 pad[6];
    void *h;
    u8 rest[12];
};

struct Tbl { struct Rec r[4]; };

struct Pt { s16 x; s16 y; };

typedef struct {int x,y;} TablePair;


typedef unsigned long long u64;

typedef struct {s16 x,y;} Position;

typedef signed int     s32;

typedef struct { void *win; s16 x,y; int z; int pal; u8 a,b; u16 c; int d; } Desc_021DA3EC;




typedef struct {u32 w[9];} Input;

typedef struct {u32 w[51];} Record;

typedef struct {u32 w[12];} Desc_021DAB50;

typedef struct Obj_021DAE1C { char pad[0xa7c]; char *slots[12]; } Obj_021DAE1C;

typedef struct Item { char raw[0xdc]; } Item;

typedef struct Obj_021DAEF0 { char pad[0x28]; Item items[12]; char tail[0xacc-0x28-12*0xdc]; volatile int index; } Obj_021DAEF0;


typedef struct { u16 h[4]; } Row;

typedef struct { u8 b[16]; } Tmp;

typedef union Rect { s16 h[4]; u8 b[8]; } Rect;

typedef struct Cur { s16 x; s16 y; } Cur;

typedef struct Pos { s16 x; s16 y; u8 pad[3]; u8 flag; } Pos;

extern struct U16Vec *func_020457B0(u32 capacity, u16 heapId);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_020307B0(void *p);
extern void func_021D9BE8(int,Pair *,void *,void *,int,Pair *);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043814(struct Bmp *dst, const struct Bmp *src);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,int);
extern void *func_021DA1BC(void *,const char *,u32,u16,u8,u32,u32,int,u16);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_021DA2A8(u8 *);
extern void func_021DA280(u8 *);
extern void func_020409B4(u32 index);
extern u32 func_020362DC(void);
extern u32 func_0203633C(void);
extern void func_020061E4(u32 a);
extern u64 _u32_div_f(u32,u32);
extern int func_021DA2C8(u8 *p);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern void func_0202570C(struct Grid *g);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_020257D0(struct Obj *o);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void func_02082A7C(int,void *,int);
extern void *func_0203084C(u32 heapId);
extern void func_02040618(u32,u32,u32);
extern u32 func_0200A348(struct Obj *);
extern u32 func_0200A0E4(u8 *p, u32 a);
extern int func_0200A000(char *p, int idx, void *buf);
extern void func_021DBDF4(char *,const Record *,char *,u16);
extern void *func_021DCFC8(const Desc_021DAB50 *,u16);
extern u32 func_021DBDBC(u32 p);
extern int func_021DBF04(int *p);
extern char *func_021DC02C(void *);
extern void *func_021DD24C(void *,void *,void *,u16);
extern void func_021DE0AC(u8 *p, u32 b);
extern void func_021DC08C(void *task, u32 *state, char *p);
extern void func_021DCEC4(void *arg, int *state, char *p);
extern void func_021DD980(char *);
extern void func_021DD1FC(void **);
extern void func_021D9E04(u8 *p);
extern void func_021DBEE4(u32 p);
extern void func_020414EC(u32);
extern void func_02041B6C(u32);
extern int func_021DD240(void **p);
extern void func_021DDF84(char *);
extern void func_021DE0DC(char *p);
extern void func_021DCFA4(u8 *p, int b, int c, u16 d);
extern int func_021D9B34(u8 *p);
extern void func_021DD9CC(char *p);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern unsigned int func_02049658(void *, u32, u32, u32, u32, u32, u16);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void func_02049238(void *);
extern void func_02040C14(u32, u32, u32, u32);
extern void func_0201F5BC(u32, u32, u32, u32, u16);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *, u32, u32, u32, u16);
extern u32 func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern void func_02045374(struct Cfg *cfg);
extern void *func_021D99A4(u32, u32, u16, u16, u8, u8, u8, u32, u16);
extern s32 func_0204AC18(void *, u32, u32, u32, u16, u16, u16);
extern s32 func_0204AF28(void *, u32, u32, u32);
extern s32 func_0204A6C8(void *, u32, u32, u32, u16);
extern void func_021DCF54(char *, void *, int, int, u8, u16);
extern struct Obj *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern void func_0204B604(struct Actor *actor, u32 which, u32 set);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_021D9A40(u8 *p);
extern int func_021DBDB8(char *);
extern void func_021D9B28(u8 *p, unsigned v);
extern void func_021D9B2C(char *p, u32 a, u32 b, int c);
extern void func_021D9AC8(u8 *p, int a, int b);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021DB938(char *,int,u16);
extern void func_02041300(u32,u16,u8,u8,u8,u8,u8);
extern void func_020413B0(u32,u32,u32,u8,u8,u8);
extern void func_02045334(struct Descriptor *d);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void *func_021DBF08(void *);
extern void *func_021DBF10(void *, u16);
extern u32 func_021DBF40(void *);
extern u32 func_021DBF70(void *);
extern int func_021DBF9C(void *);
extern int func_021DBFE4(void *);
extern int func_021DC004(void *);
extern int func_021DC024(void *);
extern int func_021DC03C(void *);
void func_021DA3EC(char *p,char *desc,void *dst);
void func_021DA4A8(u8 *p);
struct Out *func_021DA4DC(const struct In *in, u16 heap);
void func_021DA698(u8 *p);
int func_021DA6D0(u8 *p);
int func_021DA840(void **p);
void func_021DA84C(u8 *p,u32 i,u32 value);
void *func_021DA854(void *a,void *b,u16 heap);
void func_021DA890(void *p);
void func_021DA898(char *p);
int func_021DA8AC(u32 *p);
void func_021DA8B0(u32 *p,u32 a);
void func_021DA8B8(u32 *p);
void func_021DA8C0(u32 *p,u32 a);
void func_021DA8C4(u32 *p);
void *func_021DA8CC(const char *p,u16 a,u16 b,int c,u8 d,int e,void *f,void *g,u16 heap);
void func_021DA958(u8 *p);
void func_021DA978(char *p);
void func_021DA994(char *p,int a,int b,int c);
void func_021DA9EC(u8 *p,int a);
void func_021DA9F0(u32 *p,u32 a,u32 b,u32 c);
int func_021DA9F8(u8 *p);
void func_021DAA28(char *p,int a,int *out);
s32 func_021DAAA4(int a,u16 *p,int angle,int bank,u8 index,u16 c1,u16 c2);
void func_021DAB50(void *a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last);
char *func_021DAC18(const Input *src,u16 heap);
void func_021DAE1C(Obj_021DAE1C *obj);
void func_021DAEF0(Obj_021DAEF0 *obj);
void func_021DAFCC(char *p);
int func_021DB008(char *p);
void func_021DB018(u8 *p, u16 heap);
void func_021DB3E8(char *p);
void func_021DB478(char *p,int a,int b,int c,u16 heap);
void func_021DB528(char *p,int a);
void func_021DB54C(char *p, int a, int b, int c, u16 index, u16 heap);
extern char d_021DFBA0[];
extern const struct Tbl d_021DF7C0;
extern const TablePair d_021DF76C[];
extern const TablePair d_021DF770[];
extern const s16 d_020A1B38[];
extern char d_021DFBB0[],d_021DF8FC[],d_021DF890[];
extern const Row data_021DF86E[];
extern const Rect d_021DF86E[];
extern const u8 d_021DF86F[];



/*
 * extent: two bytes of zero alignment padding follow the return.
 */
void func_021DA3EC(char *p,char *desc,void *dst)
{
    u32 i;
    Pair pos,out;
    void *text=func_020457B0(512,((struct Obj06449 *)p)->f0);
    for(i=0;i<((struct Obj22885 *)(*(char * *)&((struct Obj06449 *)p)->f4))->f4;i++) {
        char *d=desc+i*24;
        if(((struct Obj03262 *)d)->f0) {
            func_02043B5C(*(void **)(p+i*4+8),(u8)(((struct Obj03262 *)d)->f14&31));
            pos.x=((struct Obj03262 *)d)->f10;
            pos.y=((struct Obj03262 *)d)->f12;
            func_021D9BE8(((struct Obj03262 *)d)->fC,&pos,*(void **)(p+i*4+8),text,((struct Obj22886 *)(*(char * *)&((struct Obj06449 *)p)->f4))->f8,&out);
            if(((struct Obj03262 *)d)->f8) func_02045838(text,(struct U16Vec *)(((struct Obj03262 *)d)->f8));
            else func_02045CAC((struct MsgBank *)(((struct Obj22887 *)(*(char * *)&((struct Obj06449 *)p)->f4))->fC),((struct Obj03262 *)d)->f4,text);
            func_0201C724(dst,(u32)(*(void **)(p+i*4+8)),(s16)out.x,(s16)out.y,(u32)text,((struct Obj22888 *)(*(char * *)&((struct Obj06449 *)p)->f4))->f8,((struct Obj03262 *)d)->f14);
        }
    }
    func_020307B0(text);
}



void func_021DA4A8(u8 *p) { u32 i; for(i=0;i<((struct Obj22889 *)(*(u8 * *)&((struct Obj13954 *)p)->f4))->f4;i++) { void *out=*(void **)(p+8+i*4); func_02043814(out,func_02045770(*(void **)(*(u8 **)(*(u8 * *)&((struct Obj13954 *)p)->f4+16+i*4)+12))); } }



/*
 * note (2026-10-05, lane T7, pengy's share): written bottom-up from the listing.
 *   heap is u16 (callees take it as u16). The input record is const, the
 *   output field f60 is a pointer typed like in->f3c: with a u32 f60 the second
 *   read of in->f3c was merged (4 B short). Struct copy t = d_021DF7C0 (4 records of
 *   24 B). The caller passes a 0x38 B input record and heap.
 */
struct Out *func_021DA4DC(const struct In *in, u16 heap)
{
    struct Tbl t;
    struct Pt pt;
    u32 i;
    u8 c;
    u16 w;
    struct Out *out = func_02030734(heap, 0x64, 0, d_021DFBA0, 0x4e7);
    func_02082BCC(out, 0, 0x64);
    out->fC = in->f20;
    out->f4 = (u32)in->fC_;
    out->f26 = in->f26;
    out->f2a = in->f28;
    out->f2c = in->f2a;
    out->f28 = in->f24;
    out->f34 = in->f34;
    out->f38 = in->f38;
    out->f2e = in->f2c;
    out->f30 = in->f30;
    out->f60 = in->f3c;
    if (in->f3c) {
        u32 v = *in->f3c;
        out->f8 = v;
        out->f8 = (v > out->fC - 1) ? out->fC - 1 : v;
    }
    for (i = 0; i < out->fC; i++)
        out->pal[i] = *(u16 *)(0x05000000 + in->f2a * 32 + (i + 10) * 2);
    out->f22 = *(u16 *)(0x0500001E + in->f2a * 32);
    t = d_021DF7C0;
    for (i = 0; i < out->fC; i++) {
        struct Rec *r = &t.r[i];
        r->b += (u8)in->f2c;
        r->a += (u8)in->f2e;
        if (in->bank) r->h = func_02045EC0(in->bank, in->ids[i]);
        else r->h = func_02045874((struct U16Vec *)in->ids[i], (u16)((heap & 0x7FFF) | 0x8000));
    }
    c = in->f26;
    w = in->f24;
    out->f0 = func_021DA1BC(0, (const char *)&t, out->fC, w, c, in->f8, (u32)in->bank, in->f4, heap);
    for (i = 0; i < out->fC; i++)
        if (t.r[i].h) func_02045808(t.r[i].h);
    pt.x = d_021DF76C[out->f8].x;
    pt.y = d_021DF770[out->f8].x + in->f2c * 8;
    func_0204B404((void *)out->f4, (const struct Vec2 *)(&pt), 0);
    func_0204B3DC((void *)out->f4, 1);
    func_0204B878((void *)out->f4, out->f30);
    func_0204B92C((void *)out->f4, 1);
    return out;
}



void func_021DA698(u8 *p) { if(*(u32 * *)&((struct Obj03786 *)p)->f60 && ((struct Obj03786 *)p)->f8!=3) **(u32 * *)&((struct Obj03786 *)p)->f60=((struct Obj03786 *)p)->f8; func_0204B3DC(((struct Obj03786 *)p)->f4,0); func_021DA2A8(*(u8 * *)&((struct Obj03786 *)p)->f0); func_021DA280(*(u8 * *)&((struct Obj03786 *)p)->f0); func_020409B4((u8)(((struct Obj03786 *)p)->f28)); func_020307B0(p); }





/*
 * arithmetic: direct division helper uses quotient r0/remainder r1 as a scalar u64;
 *             the caller admits count zero, so ordinary C remainder is not used.
 */
int func_021DA6D0(u8 *p)
{
    u32 keys=func_020362DC();
    u32 repeat=func_0203633C();
    int changed=0;
    int i;
    int phase;
    int oldphase;
    u32 index;
    Position pos;
    if(repeat&64) {
        index=((struct Obj00360 *)p)->f8==0 ? ((struct Obj00360 *)p)->fC-1 : ((struct Obj00360 *)p)->f8-1;
        ((struct Obj00360 *)p)->f8=index;
        if(((struct Obj00360 *)p)->fC!=1) func_020061E4(0x548);
        changed=1;
    } else if(repeat&128) {
        if(((struct Obj00360 *)p)->fC!=1) func_020061E4(0x548);
        ((struct Obj00360 *)p)->f8+=1;
        ((struct Obj00360 *)p)->f8=(u32)(_u32_div_f(((struct Obj00360 *)p)->f8,((struct Obj00360 *)p)->fC)>>32);
        changed=1;
    } else if(keys&1) {
        func_020061E4(0x54c);
        return ((struct Obj00360 *)p)->f8;
    } else if(keys&2) {
        func_020061E4(0x551);
        if(((struct Obj00360 *)p)->fC==1) return -2;
        if(((struct Obj00360 *)p)->f8!=3) **(u32 * *)&((struct Obj00360 *)p)->f60=((struct Obj00360 *)p)->f8;
        ((struct Obj00360 *)p)->f8=((struct Obj00360 *)p)->fC-1;
        return ((struct Obj00360 *)p)->f8;
    }
    if(changed) {
        pos.x=d_021DF76C[*(u32 *)(p+8)].x;
        pos.y=d_021DF76C[*(u32 *)(p+8)].y+((struct Obj00360 *)p)->f2E*8;
        func_0204B404(((struct Obj00360 *)p)->f4,(const struct Vec2 *)(&pos),0);
        if(((struct Obj00360 *)p)->f8==3) func_0204B878(((struct Obj00360 *)p)->f4,2);
        else func_0204B878(((struct Obj00360 *)p)->f4,((struct Obj00360 *)p)->f30);
        if(*(void (**)(u32))(p+0x34)) (*(void (**)(u32))(p+0x34))(((struct Obj00360 *)p)->f38);
    }
    oldphase=((struct Obj00360 *)p)->f24;
    phase=oldphase+0x400;
    if(phase>=0x10000) ((struct Obj00360 *)p)->f24=oldphase-0xfc00;
    else ((struct Obj00360 *)p)->f24=phase;
    for(i=0;i<4;i++) {
        u8 *v=p+i*4;
        if(((struct Obj06450 *)v)->f4C!=((struct Obj06450 *)v)->f3C && ((struct Obj00360 *)p)->f24>=0x7dff && ((struct Obj00360 *)p)->f24<=0x81ff)
            ((struct Obj06450 *)v)->f3C=((struct Obj06450 *)v)->f4C;
        if(((struct Obj06450 *)v)->f3C)
            func_021DAAA4((int)((void *)15),(u16 *)(p+0x1a+i*2),((struct Obj00360 *)p)->f24,(u8)(((struct Obj00360 *)p)->f2C),(u8)(i+10),*(u16 *)(p+0x12+i*2),((struct Obj00360 *)p)->f22);
    }
    return -1;
}






/*
 * Addresses are Black-image addresses.
 */
int func_021DA840(void **p)
{
    return func_021DA2C8(*p);
}





void func_021DA84C(u8 *p,u32 i,u32 value)
{
    *(u32 *)(p+i*4+76)=value;
}





void *func_021DA854(void *a,void *b,u16 heap) { u8 *p; p=func_02030734(heap,20,0,d_021DFBA0,0x61c); func_02082BCC(p,0,20); ((struct Obj22893 *)p)->fC=a; func_021DA8B0((u32 *)p,(u32)b); return p; }





void func_021DA890(void *p) { func_020307B0(p); }






void func_021DA898(char *p)
{
    if (((struct Obj13955 *)p)->f4 == 0)
        (*(void (**)(char *, char *, u32))p)(p, p + 8, ((struct Obj13955 *)p)->fC);
}






int func_021DA8AC(u32 *p) { return p[1]; }






void func_021DA8B0(u32 *p,u32 a) { p[0]=a; p[2]=0; }






void func_021DA8B8(u32 *p) { p[1]=1; }






void func_021DA8C0(u32 *p,u32 a) { p[4]=a; }






void func_021DA8C4(u32 *p) { p[2]=p[4]; }





/*
 * lever: a and b are u16; the descriptor input pointer is const.
 */
void *func_021DA8CC(const char *p,u16 a,u16 b,int c,u8 d,int e,void *f,void *g,u16 heap)
{
    Desc_021DA3EC desc;
    char *out=func_02030734(heap,36,0,d_021DFBA0,0x6b1);
    func_02082BCC(out,0,36);
    ((struct Obj06451 *)out)->f20=g;
    ((struct Obj06451 *)out)->f18=func_020457B0(128,heap);
    ((struct Obj06451 *)out)->f0=func_02043678(a,b,32,heap);
    func_02082BCC(&desc,0,24);
    desc.win=((struct Obj06451 *)out)->f0;
    desc.x=((struct Obj08095 *)p)->f0;
    desc.y=((struct Obj08095 *)p)->f2;
    desc.z=c;
    desc.a=((struct Obj08095 *)p)->f6;
    desc.c=e;
    desc.d=e;
    desc.b=((struct Obj08095 *)p)->f7;
    desc.pal=d;
    ((struct Obj06451 *)out)->f1C=func_020255A0(f,(const struct Param *)(&desc));
    return out;
}





void func_021DA958(u8 *p) { func_0202570C(((struct Obj10414 *)p)->f1C); func_020437AC(((struct Obj10414 *)p)->f0); func_02045808(((struct Obj10414 *)p)->f18); func_020307B0(p); }






void func_021DA978(char *p)
{
    func_02043B5C((struct CharBuf *)(((struct Obj10415 *)p)->f0), (unsigned char)(((struct Obj10415 *)p)->f4 & 0x1f));
    func_020257D0(((struct Obj10415 *)p)->f1C);
}





/*
 * extent: two bytes of zero alignment padding after the return.
 */
void func_021DA994(char *p,int a,int b,int c)
{
    int xy[2];
    func_02043B5C((struct CharBuf *)(((struct Obj03787 *)p)->f0),(u8)(((struct Obj03787 *)p)->f4&31));
    func_02045CAC((struct MsgBank *)a,b,((struct Obj03787 *)p)->f18);
    func_021DAA28(p,c,xy);
    func_0201C724(((struct Obj03787 *)p)->f20,((struct Obj03787 *)p)->f0,(s16)xy[0],(s16)xy[1],(u32)(((struct Obj03787 *)p)->f18),c,((struct Obj03787 *)p)->f4);
    ((struct Obj03787 *)p)->f8=1;
}






void func_021DA9EC(u8 *p,int a) { ((struct Obj22897 *)p)->f4=a; }






void func_021DA9F0(u32 *p,u32 a,u32 b,u32 c) { p[3]=a; p[4]=b; p[5]=c; }





int func_021DA9F8(u8 *p) { if(((struct Obj05358 *)p)->f8) { if(func_0201C6C4((struct PrintSys *)(((struct Obj05358 *)p)->f20),(void *)(((struct Obj05358 *)p)->f0))==0) { func_020257D0(((struct Obj05358 *)p)->f1C); ((struct Obj05358 *)p)->f8=0; } } if(((struct Obj05358 *)p)->f8==0) return 1; return 0; }





/*
 * extent: two bytes of zero alignment padding after the return.
 * lever: case 0 is an eight-byte aggregate copy (existing pair-copy idiom).
 */
void func_021DAA28(char *p,int a,int *out)
{
    int x,y;
    switch(((struct Obj02470 *)p)->f14) {
    case 0:
        *(Pair *)out=*(Pair *)(p+12);
        break;
    case 1:
        x=func_020437DC((const struct Bmp *)(((struct Obj02470 *)p)->f0))/2;
        y=func_020437E4((const struct Bmp *)(((struct Obj02470 *)p)->f0))/2;
        x-=func_0201D304(((struct Obj02470 *)p)->f18,a,0)/2;
        y-=func_0201D42C(((struct Obj02470 *)p)->f18,(void *)a)/2;
        out[0]=x+((struct Obj02470 *)p)->fC;
        out[1]=y+((struct Obj02470 *)p)->f10;
        break;
    case 2:
        x=func_020437E4((const struct Bmp *)(((struct Obj02470 *)p)->f0))/2;
        x-=func_0201D42C(((struct Obj02470 *)p)->f18,(void *)a)/2;
        out[0]=((struct Obj02470 *)p)->fC;
        out[1]=x+((struct Obj02470 *)p)->f10;
        break;
    }
}



static inline u16 blend(u16 c1,u16 c2,s16 factor) {
 u8 g1,r1,b1; int db,dr,dg;
 g1=(c1&0x3e0)>>5;
 r1=c1&31;
 b1=(c1&0x7c00)>>10;
 db=(factor*((u8)((c2&0x7c00)>>10)-b1))>>12;
 dr=(factor*((u8)(c2&31)-r1))>>12;
 dg=(factor*((u8)((c2&0x3e0)>>5)-g1))>>12;
 return ((u8)(b1+db)<<10)|((u8)(r1+dr)|((u8)(g1+dg)<<5));
}



/*
 * lever: twin ov104 021B89DC blend spelling, first argument passed through to func_02061CA4.
 */
s32 func_021DAAA4(int a,u16 *p,int angle,int bank,u8 index,u16 c1,u16 c2) {
 *p=blend(c1,c2,(s16)((d_020A1B38[((angle>>4)*2)+1]+0x1000)/2));
 return func_02061CA4((void *)a,bank*32+index*2,(u32)p,2);
}








#pragma opt_loop_invariants off




/*
 * lever: int factor before the loop, narrowed to s16 at the inline blend argument
 * inside the loop, with #pragma opt_loop_invariants off: the IR keeps the
 * conversion in the loop (no div+convert fold to lsls #0xf) and the backend
 * hoists it, giving asrs #1; lsls #0x10; asrs #0x10. Counter initialised at its
 * declaration (int i=0; for(;...)) sets the i/index birth order (r6/r4).
 * note pass 2 2026-10-06 P2L51: closed from 147/200 (h5 pragma form 7/200, i/index swap fixed by i=0 at declaration).
 */
void func_021DAB50(void *a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last) {
 int i=0;
 int factor=(d_020A1B38[((angle>>4)*2)+1]+0x1000)/2;
 for(;i<16;i++) p[i]=blend(first[i],last[i],factor);
 func_02061CA4(a,bank*32,(u32)p,32);
}




#pragma opt_loop_invariants reset




char *func_021DAC18(const Input *src,u16 heap)
{
    char *out;
    int count=0;
    u32 i;
    int j;
    Desc_021DAB50 d;
    Record record;
    const char *table;
    int n;
    void *callback;
    out=func_02030734(heap,0xc70,0,d_021DFBB0,0x19f);
    func_02082BCC(out,0,0xc70);
    ((struct Obj00910 *)out)->fAD0=1;
    *(Input *)out=*src;
    ((struct Obj00910 *)out)->f24=heap;
    func_02082A7C(-1,out+0xb48,32);
    func_02082A7C(-1,out+0xb88,32);
    func_02082A7C(-1,out+0xb68,32);
    for(i=0;i<func_0200A348(((struct Obj00910 *)out)->fC);i++) {
        if(func_0200A0E4(((struct Obj00910 *)out)->fC,i)) {
            count++;
            func_0200A000(((struct Obj00910 *)out)->fC,i,&record);
            func_021DBDF4(out+40+i*0xdc,&record,out,heap);
        }
    }
    callback=(void *)func_021DC08C;
    if(((struct Obj00910 *)out)->f0) callback=(void *)func_021DCEC4;
    ((struct Obj00910 *)out)->fAC4=func_021DA854(out,callback,heap);
    func_021DB018((u8 *)out,heap);
    func_021DB478(out,1,0,((struct Obj00910 *)out)->fAC8,heap);
    if(count) {table=d_021DF8FC;n=3;}
    else {table=d_021DF890;n=2;}
    ((struct Obj00910 *)out)->fAB8=func_021DA1BC(0,table,n,1,3,((struct Obj00910 *)out)->f14,((struct Obj00910 *)out)->f1C,*(int *)&((struct Obj00910 *)out)->f10,heap);
    func_02082BCC(&d,0,48);
    d.w[0]=6;d.w[1]=4;d.w[2]=14;d.w[3]=15;d.w[4]=11;d.w[5]=14;
    d.w[6]=((struct Obj00910 *)out)->f8;d.w[7]=*(u32 *)&((struct Obj00910 *)out)->fC;d.w[8]=((struct Obj00910 *)out)->f1C;
    d.w[9]=((struct Obj00910 *)out)->f10;d.w[10]=((struct Obj00910 *)out)->f14;d.w[11]=((struct Obj00910 *)out)->f18;
    ((struct Obj00910 *)out)->fAB0=func_021DCFC8(&d,heap);
    if(func_021DBDBC((u32)out)) {
        for(j=0;j<12;j++) {
            if(func_021DBF04((int *)(out+40+j*0xdc)))
                *(void **)(out+0xa7c+j*4)=func_021DD24C(func_021DC02C(out+40+j*0xdc),((struct Obj00910 *)out)->fAB0,(void *)src->w[8],heap);
        }
        func_021DE0AC(((struct Obj00910 *)out)->fA7C,0);
        func_0203084C(29);
    }
    func_02040618(3,3,0);
    func_02040618(7,3,0);
    return out;
}




/*
 * lever: The slot array at +0xa7c is the same layout as func_021DBC08;
 * its member access keeps the offset loaded before the loop index.
 */
void func_021DAE1C(Obj_021DAE1C *obj)
{
    char *p=(char *)obj;
    int i;
    u32 j;
    for(i=0;i<12;i++) {
        if(obj->slots[i]) {
            func_021DD980(obj->slots[i]);
            obj->slots[i]=0;
        }
    }
    func_021DD1FC(*(void ** *)&((struct Obj01058 *)p)->fAB0);
    if(((struct Obj01058 *)p)->fABC) {
        func_021D9E04(((struct Obj01058 *)p)->fABC);
        ((struct Obj01058 *)p)->fABC=0;
    }
    func_02040618(3,0,0);
    func_02040618(2,0,0);
    func_021DA2A8(((struct Obj01058 *)p)->fAB8);
    func_021DA280(((struct Obj01058 *)p)->fAB8);
    func_021DB528(p,1);
    func_021DB528(p,0);
    func_021DB3E8(p);
    for(j=0;j<func_0200A348(((struct Obj01058 *)p)->fC);j++)
        func_021DBEE4((u32)(p+0x28+j*0xdc));
    func_020414EC(4);
    func_020414EC(6);
    func_02041B6C(4);
    func_02041B6C(6);
    func_021DA890(((struct Obj01058 *)p)->fAC4);
    func_020307B0(p);
}




void func_021DAEF0(Obj_021DAEF0 *obj)
{
    char *p=(char *)obj;
    int flag;
    u16 old;
    int angle;
    func_021DA898(*(char * *)&((struct Obj01153 *)p)->fAC4);
    func_021DD240(((struct Obj01153 *)p)->fAB0);
    if(((struct Obj01153 *)p)->fA78) {
        flag=0;
        if(*(char * *)&((struct Obj01153 *)p)->fAAC) {
            func_021DDF84(*(char * *)&((struct Obj01153 *)p)->fAAC);
            *(char * *)&((struct Obj01153 *)p)->fAAC=0;
        }
        if(obj->index<4 && func_021DBF04((int *)(&obj->items[obj->index+((struct Obj01153 *)p)->fAC8*4]))) {
            flag=1;
            func_021DE0AC(*(void **)(p+0xa7c+(((struct Obj01153 *)p)->fACC+((struct Obj01153 *)p)->fAC8*4)*4),1);
        }
        if(flag==0) func_021DE0DC(((struct Obj01153 *)p)->fAB0);
        ((struct Obj01153 *)p)->fA78=0;
    }
    old=((struct Obj01153 *)p)->fBAC;
    angle=old+0x400;
    if(angle>=0x10000)
        ((struct Obj01153 *)p)->fBAC=old-0xfc00;
    else
        ((struct Obj01153 *)p)->fBAC=angle;
    func_021DCFA4((u8 *)(p+0xbae),14,0,((struct Obj01153 *)p)->fBAC);
    func_021DCFA4((u8 *)(p+0xc0e),14,2,((struct Obj01153 *)p)->fBAC);
}




static inline void update(void *p)
{
    if(p) func_021DD9CC(p);
}




/*
 * extent: unit includes tail-call follower func_021DB008 (function-start seed).
 */
void func_021DAFCC(char *p)
{
    int i;
    func_021DA2C8(((struct Obj10417 *)p)->fAB8);
    if(((struct Obj10417 *)p)->fAB4) func_021D9B34(((struct Obj10417 *)p)->fAB4);
    for(i=0;i<12;i++) {
        void *q=*(void **)(p+i*4+0xa7c);
        if(q) update(q);
    }
}




int func_021DB008(char *p)
{
    return func_021DA8AC(((struct Obj22899 *)p)->fAC4);
}




#pragma opt_dead_assignments off




/*
 * closed 2026-10-05 (recoup integrator): func_02049658 returns u32 (its matched definition tail-returns sub_0204968C); with the void declaration the later register zeros were copied from the pooled zero; with the real return type the
 *   bytes are EXACT in c99 and c.
 * note (2026-10-05, lane P10): full body written; size is exact (976 bytes), 110 bytes differ.
 *   Fixed: heap is u16 with the matched u16 callee prototypes (no lsls/lsrs pairs); 0xAB4, 0xBA8
 *   and 320 held as int locals (off, off2, w) so the pool words and derived offsets matched.
 *   Residue 1: colour swap. Original has the early zero (and loop counter i) in r6 and arc in r4;
 *   the build has them swapped (j then takes r6 vs r4 the same way). Tried, no change: i,j and arc
 *   declaration order, separate arc names, loop-scoped i and j, named zero z (propagated),
 *   j = 0 at the top (worse). Pragmas opt_lifetimes/propagation/common_subs/dead_assignments/
 *   scheduling/peephole off: no help.
 *   Residue 2: the original uses movs for zero arguments in r0-r3 between 0xCC and 0x140 (before
 *   the first loop); the build copies the zero register there.
 *   Residue 3: in loop 2 the original forms add r0,sp,#0x44 once before the j test; the build
 *   adds it in each arm. A ternary for the x store and a real Tmp struct were worse.
 * note (2026-10-05, lane P10b): 110 -> 85 bytes, size exact (976). Fixed: loop 2 now writes
 *   the t stores in each if/else arm (x, y=0x10 and z=9 in both arms), so the &t add is hoisted
 *   above the j test and the tail shape matches (residue 3 closed, 110 -> 94). The locals off, off2
 *   and w were stand-ins (literals give identical bytes) and are gone. opt_dead_assignments off
 *   fixes the r0/r1 table-base colours in the i < 4 arm (94 -> 85).
 *   Left: the colour swap. Original W1 = early zero and loop-1 counter i in r6, arcs r4, W2 = copy
 *   of it (`adds r4,r6,#0` before loop 1) = zero args after the loop and loop-2 counter j in r4.
 *   Build: W1 r4, arcs and W2 r6. Likely W1 is coloured before W2 because W1 has about ten extra
 *   uses: between 0xCC and 0x140 the build copies zeros off W1 (adds rN,r4,#0) where the original
 *   has movs. Tried (no help): i=0 at the top of the function (hoists the movs above the first
 *   call, +12 B), `i = 0; j = i;` before loop 1 with empty for inits (+12 B, worse regs), pointer
 *   local for &t in loop 2 (hoisted to r7, worse), j/i and arc declaration order again with the
 *   new loop 2, pragmas opt_lifetimes, opt_propagation, scheduling, peephole (no change),
 *   opt_common_subs (much worse), lifetimes+dead_assignments (85, same), propagation+dead (worse).
 *   Parked per the human-written rule: not tried, a human-spelled zero local reused as the
 *   stack zero arguments (i passed as args 5 and 6) could explain r6 holding a live variable.
 * note (2026-10-05, lane P10c): still 85 B, no change kept. The pragma opt_dead_assignments off
 *   lines are present (the 85 B state). Callee prototypes already match the matched callers (u32
 *   args, u16 heap), so no argument type differs between the stack zeros and the register zeros.
 *   Facts: mine already uses movs for register zeros before +0xB0 and copies only from the last
 *   02049658/020498F4 pair on (+0xB0, +0xD0, +0xF6..+0x134); the original uses movs everywhere in
 *   W1's range, and the copy count raises W1's use count, which colours W1 before the arcs.
 *   Loop 2 original: k is a separate fresh `movs r7,#0`, j is r4.
 *   Tried (each one compile): (1) coordinator lead: i = 0 before the first call, i passed only as
 *   the two stack zero args of 02049658/020498F4, literal 0 for r1-r3 (87 B; the compiler folds
 *   i to 0 so register zeros still copy); (2) i = 0 early with `for (; i < 8; i++)` as in the
 *   matched twin ov099 021BE040 (87 B); (3) static inline helper pair(arc, x, y, heap) for the
 *   three 02049658/020498F4 pairs (85 B, +0xB0 now movs, others unchanged); (4) late zeros
 *   (02049B68 r2, 02040C14 r1/r3, 0201F5BC r0/r3, 0204ACEC r2) spelled 0u (85 B, no change);
 *   (5) first 23 lines of calls inside a static inline setup1(heap) helper (85 B); (6) helper
 *   variant with opt_propagation off (901 B) and opt_lifetimes off (85 B). Idea not done: a
 *   source where W1 is not provably 0 after the first loop-free section.
 */
void func_021DB018(u8 *p, u16 heap)
{
    Tmp t;
    void *arc;
    int i, j;
    u32 k;
    arc = func_020490F4(34, heap);
    func_02049B68(arc, 1, 0, 0, 320, heap);
    func_02049658(arc, 10, 3, 0, 0, 0, heap);
    func_020498F4(arc, 17, 3, 0, 0, 0, heap);
    func_02049658(arc, 10, 1, 0, 0, 0, heap);
    func_020498F4(arc, 19, 1, 0, 0, 0, heap);
    func_020409B4(3);
    func_02049B68(arc, 1, 4, 0, 320, heap);
    func_02049658(arc, 10, 7, 0, 0, 0, heap);
    func_020498F4(arc, 18, 7, 0, 0, 0, heap);
    func_02049238(arc);
    arc = func_020490F4(23, heap);
    func_02049B68(arc, 5, 0, 480, 32, heap);
    func_02049B68(arc, 5, 4, 480, 32, heap);
    func_02049238(arc);
    func_02040C14(1, 0, 1, 0);
    func_02040C14(2, 0, 1, 0);
    func_0201F5BC(0, 1, 13, 0, heap);
    arc = func_020490F4(7, heap);
    *(int *)(p + 0xBA8) = func_0204ACEC(arc, func_0201BC3C(), 0, 384, heap);
    func_02049238(arc);
    for (i = 0; i < 8; i++) {
        if (i >= 4) {
            *(u16 *)(t.b + 8) = data_021DF86E[i - 4].h[0];
            *(u16 *)(t.b + 10) = data_021DF86E[i - 4].h[1];
            *(u16 *)(t.b + 12) = data_021DF86E[i - 4].h[2];
            *(u16 *)(t.b + 14) = data_021DF86E[i - 4].h[3];
            t.b[8] += 0x20;
            t.b[10] += 0x20;
        } else {
            *(u16 *)(t.b + 8) = data_021DF86E[i].h[0];
            *(u16 *)(t.b + 10) = data_021DF86E[i].h[1];
            *(u16 *)(t.b + 12) = data_021DF86E[i].h[2];
            *(u16 *)(t.b + 14) = data_021DF86E[i].h[3];
        }
        *(u32 *)(p + i * 4 + 0xBA8 - 0xA0) = func_020450F0(2, t.b[10], t.b[11], 10, 2, 15, 0);
        func_02045374(*(void **)(p + i * 4 + 0xBA8 - 0xA0));
        func_020409B4(2);
    }
    *(void **)(p + 0xAB4) = func_021D99A4(0, 1, 13, 22, 6, 2, 3, *(u32 *)(p + 0x14), heap);
    arc = func_020490F4(34, heap);
    *(s32 *)(p + 0xAB4 + 0x50) = func_0204AC18(arc, 0, 0, 0, 0, 6, heap);
    *(s32 *)(p + 0xAB4 + 0x4C) = func_0204AF28(arc, 32, 35, heap);
    *(s32 *)(p + 0xAB4 + 0x48) = func_0204A6C8(arc, 9, 0, 0, heap);
    func_021DCF54((char *)p + 0xBAE, arc, 0, 0, 1, heap);
    func_021DCF54((char *)p + 0xC0E, arc, 0, 2, 3, heap);
    func_02049238(arc);
    func_02082BCC(&t, 0, 8);
    *(u16 *)(t.b) = 0;
    *(u16 *)(t.b + 2) = 24;
    t.b[7] = 1;
    t.b[6] = 1;
    {
        struct Obj *o = func_0204B294(*(void **)(p + 8), *(u32 *)(p + 0xAB4 + 0x48), *(u32 *)(p + 0xAB4 + 0x50), *(u32 *)(p + 0xAB4 + 0x4C), &t, 0, heap);
        *(struct Obj **)(p + 0xAB4 + 0x38) = o;
        *(u16 *)(t.b + 4) = 2;
        o = func_0204B294(*(void **)(p + 8), *(u32 *)(p + 0xAB4 + 0x48), *(u32 *)(p + 0xAB4 + 0x50), *(u32 *)(p + 0xAB4 + 0x4C), &t, 0, heap);
        *(struct Obj **)(p + 0xAB4 + 0x3C) = o;
        func_0204B3DC(o, 0);
    }
    t.b[6] = 0;
    k = 0;
    for (j = 0; j < 2; j++) {
        struct Obj *o;
        u8 *q;
        if (j == 0) {
            *(u16 *)(t.b) = 0x10;
            *(u16 *)(t.b + 2) = 0x10;
            *(u16 *)(t.b + 4) = 9;
        } else {
            *(u16 *)(t.b) = 0xF0;
            *(u16 *)(t.b + 2) = 0x10;
            *(u16 *)(t.b + 4) = 9;
        }
        q = p + j * 4;
        o = func_0204B294(*(void **)(p + 8), *(u32 *)(p + 0xAB4 + 0x48), *(u32 *)(p + 0xAB4 + 0x50), *(u32 *)(p + 0xAB4 + 0x4C), &t, k, heap);
        *(struct Obj **)(q + 0xAB4 + 0x40) = o;
        func_0204B92C(*(struct Obj **)(q + 0xAB4 + 0x40), 1);
        func_0204B3DC(*(struct Obj **)(q + 0xAB4 + 0x40), k);
        if (j == 0) func_0204B604((struct Actor *)(*(struct Obj **)(q + 0xAB4 + 0x40)), 1, 1);
        else func_0204B604((struct Actor *)(*(struct Obj **)(q + 0xAB4 + 0x40)), 1, 0);
    }
    func_02040588(2, 1);
}




#pragma opt_dead_assignments reset



void func_021DB3E8(char *p)
{
    int i;
    func_02040DA8(2,1,0);
    func_02040DA8(1,1,0);
    for(i=0;i<2;i++) func_0204B3B4(*(void **)(p+0xaf4+i*4));
    func_0204B3B4(((struct Obj01058 *)p)->fAF0);
    func_0204B3B4(((struct Obj01058 *)p)->fAEC);
    func_0204A8D4((u32)(((struct Obj01058 *)p)->fAFC));
    func_0204AFD8((u32)(((struct Obj01058 *)p)->fB00));
    func_0204ADA4((u32)(((struct Obj01058 *)p)->fB04));
    func_021D9A40(((struct Obj01058 *)p)->fAB4);
    ((struct Obj01058 *)p)->fAB4=0;
    func_0204ADA4((u32)(((struct Obj01058 *)p)->fBA8));
    for(i=0;i<8;i++) func_020452E8(*(void **)(p+0xb08+i*4));
}



void func_021DB478(char *p,int a,int b,int c,u16 heap)
{
    int i;
    void *text,*other;
    for(i=0;i<4;i++) func_021DB54C(p,a,b,c,(u16)i,heap);
    text=func_020457B0(128,heap);
    other=func_02045EC0(((struct Obj00828 *)p)->f1C,150);
    func_0201EFA4(((struct Obj00828 *)p)->f18,0,c+1,1,1,1);
    func_0201EFA4(((struct Obj00828 *)p)->f18,1,func_021DBDB8(p),1,1,1);
    func_0201F250(((struct Obj00828 *)p)->f18,text,other);
    func_021D9B28(((struct Obj00828 *)p)->fAB4,0x39ea);
    func_021D9B2C(((struct Obj00828 *)p)->fAB4,0,0,1);
    func_021D9AC8(((struct Obj00828 *)p)->fAB4,(int)text,((struct Obj00828 *)p)->f10);
    func_02045808(text);
    func_02045808(other);
    func_020409B4(3);
}



void func_021DB528(char *p,int a) { int i; for(i=0;i<4;i++) func_021DB938(p,a,i); func_020409B4(3); }



#pragma opt_loop_invariants off



#pragma opt_lifetimes off



/*
 * note 2026-10-05 (lane P9): first draft, no source existed. DIFF, 1024 vs 1004 bytes.
 *   Structure matches the listing (loops, tail, callee arguments). Separate locals
 *   for rect/pos/cur (not one struct) give the right heap/index prologue; a static
 *   inline ents(p) = p + 0x28 gives the double store of the table base.
 *   Residue: the original keeps the two signed divisions by 3 inside the y loop
 *   (dividend (u8)k hoisted to a spill slot, rem first, quot second); every form
 *   tried hoists the whole tile base out of the loop (parenthesised, one expression,
 *   u8 m, inline cast, cols=3 local: 12 compiles). Spill slot numbers and register
 *   colours (rx r5, x r4, yy r7) follow from that. The 0x100 in the final block is
 *   built as r4(=1)+0xff in the original, not reproduced. Pool-base adds (p+0xb08
 *   etc.) are shared in the draft but recomputed in the original.
 *   Idioms checked: a-u16-stack-parameter-reloaded-per-call-means-u16-callee-parameters
 *   (heap already u16 in all prototypes), narrow-stack-parameters-and-callee-prototype-
 *   free-the-narrow-home-store (prologue now matches for 14 bytes).
 * note 2026-10-05 (lane P9b): still DIFF, 1028 vs 1004 bytes. 13 more compiles, none changed
 *   the size. Tried: tile base as a static inline tb(k, y) called in the y body; separate
 *   rem/quo locals (rem first); tile expression written inside the x loop call argument;
 *   y loop as do/while; m = (u8)k assigned inside the y body instead of before the loop
 *   (mwcc hoists the cast AND both divisions out of the y loop in every form, so LICM
 *   hoists in one step through the whole chain); per-function pragmas opt_loop_invariants,
 *   opt_lifetimes, opt_propagation, opt_common_subs off (size 1028/1028/1064/1100, no help).
 *   The original hoists the (u8)k cast but keeps both calls in the y body: the divisions
 *   must be loop-variant or non-hoistable at IR level for a reason no source form tried
 *   shows. Untested guesses: a hoist budget limit, or a different dividend source.
 *   Idioms checked: signed-modulo-magic-reappears-when-the-source-divides-by-the-same-
 *   constant-twice (not applicable, divisor 3 is a real call here); matched twin ov217
 *   021BD178 has the divisions inside the loop only because its operands depend on i, j.
 * note 2026-10-05 final push G10L1: DIFF, 53 of 1004 bytes off (was 470 of 1028 at the start of
 *   the push). Size now equals the original. What closed most of the residue:
 *   (1) the tail pos.x chain is `if (a) x = h2; else if (b) x = h2 - 0x100; else if (b == 0)
 *   x = h2 + 0x100; else x = h2;` (the original tests a once; 1028 -> 1016 bytes);
 *   (2) the cur block is `if (a == 0) { if (b) x -= 0x100; else if (b == 0) x += 0x100; }`
 *   (1016 -> 1004); (3) `#pragma opt_loop_invariants off` keeps both /3 and %3 calls inside the
 *   y loop (the old lane tried it only while the size was still wrong); (4) do-while loops with
 *   `x = 0;` first in the y body and `y = 0;` before the loops give the original head order;
 *   (5) a local for func_021DBF08's result puts that call before the idx*4 address work;
 *   (6) declaration order off, tab, idx, y, y2, y3 (one counter per loop), m, src, k, ry, rx
 *   gives the original spill slots for most locals; tab = p + 0x28 plain (no inline helper);
 *   (7) dy = 0 before func_02082BCC.
 *   Residue (53 bytes): rx and x swapped (original x r4, rx r5; mine rx r4, x r5; decl order of
 *   x/rx did not move it, 2 compiles); index and ry slots swapped (original index sp+0x18, ry
 *   sp+0x1c); obj and the p+0xb88 base temp slots swapped (original obj sp+0x48, temp sp+0x44);
 *   `dx = 0` (movs r6) sits before the call to func_021DBF9C in mine, just before the blx of
 *   func_0204A6C8 in the original.
 *   Idioms checked: of-two-equal-temps-the-later-born-one-gets-the-lower-register (no source
 *   order found that flips x/rx), a-separate-index-local-per-loop-reorders-spill-slots (y per
 *   loop: moved y2/y3 next to y), function-scope-versus-block-scope-decides-spill-slot-order,
 *   div-and-mod-are-two-calls, a-reloaded-loop-invariant-means-the-loop-was-not-rotated
 *   (goto loops still hoist). Twin: ov121 021DB938 (same top condition and loops).
 * note 2026-10-05 final push G10L1 round 2: DIFF, 28 of 1004 bytes off. `dx = 0;` moved to just
 *   after the func_0204A6C8 statement (53 -> 28; this also fixed the obj/temp slot swap).
 *   Remaining: x in r5 and rx in r4 (original x r4, rx r5), and the index/ry spill slots swapped
 *   (original index sp+0x18, ry sp+0x1c). Tried without effect: dx = 0 as a call argument (251),
 *   u8 rx/ry, a y=x=0 head, separate x2/x3 per loop, decl order of x/rx/tile; opt_propagation off
 *   (91), opt_common_subs off (758), opt_lifetimes off (25 but x r4, rx r6, tile r5, index/ry swap
 *   stays); callee prototypes re-grepped in src/matched (all match the draft). Without the
 *   pragma and with direct r.b[0]/r.b[1] reads (like matched 021DB938) the slots all match but
 *   both /3 and %3 are hoisted (84); `(u8)k` inline, `cols = 3` local did not stop the hoist.
 * note pass 2 2026-10-06 P2L41: EXACT (c99 and c). Closed with `#pragma opt_lifetimes off` (beside
 *   opt_loop_invariants off), one tile local per loop (tile, tile2, tile3, like y/y2/y3), x declared
 *   before rx, int ry passed straight to func_020413B0 with the u32 x/y prototype used by matched
 *   callers (ov217 021BA284, ov088 021BB810). Under lifetimes off the colour order follows degree
 *   then declaration order: per-loop tiles make the tiles drop out first, then rx, then x, giving
 *   x r4, rx r5, tile r6. Passing ry (not r.b[1]) keeps ry itself as the spilled web, so it takes
 *   the slot after k (sp+0x1c) and index takes sp+0x18.
 */
void func_021DB54C(char *p, int a, int b, int c, u16 index, u16 heap)
{
    void *obj;
    int off;
    char *tab;
    int idx;
    int y, y2, y3;
    int m;
    const Rect *src;
    int k, ry;
    int x, rx, yy, tile, tile2, tile3;
    s16 dx, dy;
    void *dsc;
    Rect r;
    Pos pos;
    Cur cur;
    k = index + c * 4;
    tab = p + 0x28;
    off = k * 0xdc;
    idx = index;
    src = &d_021DF86E[index];
    r = *src;
    if ((a && *(u32 *)(p + 0xad0) == 0) || (a == 0 && *(u32 *)(p + 0xad0))) {
        idx += 4;
        r.b[0] += 32;
        r.b[2] += 32;
    }
    y = 0;
    ry = r.b[1];
    rx = r.b[0];
    m = (u8)k;
    do {
        x = 0;
        yy = ry + y;
        tile = y * 32 + ((m % 3) * 64 + 0x58 + (m / 3) * 2);
        do {
            func_02041300(3, (u16)(x + tile), (u8)(rx + x - 2), (u8)yy, 1, 1, 3);
            x++;
        } while (x < 2);
        y++;
    } while (y < 2);
    if (func_021DBF04((int *)(tab + off)) == 0) {
        y2 = 0;
        do {
            x = 0;
            yy = ry + y2;
            tile2 = y2 * 32 + 384;
            do {
                func_02041300(3, (u16)(x + tile2), (u8)(rx + x), (u8)yy, 1, 1, 3);
                x++;
            } while (x < 12);
            y2++;
        } while (y2 < 7);
        func_02043B5C(func_02045770(*(void **)(p + 0xb08 + idx * 4)), 0);
        func_02045334(*(void **)(p + 0xb08 + idx * 4));
        return;
    }
    y3 = 0;
    do {
        x = 0;
        yy = ry + y3;
        tile3 = y3 * 32 + 0x40;
        do {
            func_02041300(3, (u16)(x + tile3), (u8)(rx + x), (u8)yy, 1, 1, 5);
            x++;
        } while (x < 12);
        y3++;
    } while (y3 < 7);
    func_020413B0(3, r.b[0], ry, 12, 7, (u8)func_021DC03C(tab + off));
    dsc = func_021DBF08(tab + off);
    func_02043814(dsc, func_02045770(*(void **)(p + 0xb08 + idx * 4)));
    func_02045334(*(void **)(p + 0xb08 + idx * 4));
    obj = func_021DBF10(tab + off, heap);
    if (func_021DC024(tab + off) != 1)
        *(int *)(p + 0xb88 + idx * 4) = func_0204AC18(obj, func_021DBF40(tab + off), 0, (u16)((idx + 4) << 5), 0, 1, heap);
    *(int *)(p + 0xb68 + idx * 4) = func_0204AF28(obj, func_021DBFE4(tab + off), func_021DC004(tab + off), heap);
    *(int *)(p + 0xb48 + idx * 4) = func_0204A6C8(obj, func_021DBF9C(tab + off), 0, 0, heap);
    dx = 0;
    func_02049238(obj);
    dy = 0;
    func_02082BCC(&pos, 0, 8);
    pos.y = r.h[3];
    pos.flag = 1;
    if (func_021DC024(tab + off) == 2) {
        dx = 4;
        dy = 8;
    }
    if (a)
        pos.x = r.h[2];
    else if (b)
        pos.x = r.h[2] - 0x100;
    else if (b == 0)
        pos.x = r.h[2] + 0x100;
    else
        pos.x = r.h[2];
    pos.x += dx;
    pos.y += dy;
    *(void **)(p + 0xb28 + idx * 4) = func_0204B294(*(void **)(p + 8), *(u32 *)(p + 0xb48 + idx * 4),
        func_021DC024(tab + off) == 1 ? *(u32 *)(p + 0xba8) : *(u32 *)(p + 0xb88 + idx * 4),
        *(u32 *)(p + 0xb68 + idx * 4), &pos, 0, *(u16 *)(p + 0x24));
    func_0204B6F4(*(void **)(p + 0xb28 + idx * 4), (u8)func_021DBF70(tab + off), 0);
    func_0204B3DC(*(void **)(p + 0xb28 + idx * 4), 1);
    if (*(u32 *)(p + 0xae0) && *(u16 *)(p + 0xade) == k) {
        cur.x = src->b[0] * 8 - 0x18;
        cur.y = d_021DF86F[index * 8] * 8 - 8;
        if (a == 0) {
            if (b)
                cur.x -= 0x100;
            else if (b == 0)
                cur.x += 0x100;
        }
        func_0204B404(*(void **)(p + 0xaf0), (const struct Vec2 *)(&cur), 0);
    }
}



#pragma opt_lifetimes reset



#pragma opt_loop_invariants reset
