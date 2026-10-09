/*
 * file:     unit_021B7560_p01.c
 * unit:     yes
 * function: func_021B7560, func_021B7730, func_021B7778, func_021B784C, func_021B78A0, func_021B78BC, func_021B78C8, func_021B78D4, func_021B78E0, func_021B78F4, func_021B7A3C, func_021B7A80, func_021B7A88, func_021B7BC0, func_021B7C04, func_021B7C0C, func_021B7C14, func_021B7C1C, func_021B7C20, func_021B7C6C, func_021B7C94, func_021B7CA0, func_021B7CA4, func_021B7CA8, func_021B7CAC, func_021B7CB0, func_021B7D20, func_021B7D90, func_021B7DAC, func_021B7DE4, func_021B7E48, func_021B7EEC, func_021B7F78, func_021B8008, func_021B80BC, func_021B80CC, func_021B80D8
 * address:  0x021B7560
 * region:   ov105
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02012138 0x02012138 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02041F6C 0x02041F6C arm
 *   func_02041FB0 0x02041FB0 arm
 *   func_021B8348 0x021B8348 thumb ov105
 *   func_021B658C 0x021B658C thumb ov101
 *   func_021B70DC 0x021B70DC thumb ov101
 *   func_021B728C 0x021B728C thumb ov101
 *   func_021B84B4 0x021B84B4 thumb ov105
 *   func_021B8840 0x021B8840 thumb ov105
 *   func_021B8598 0x021B8598 thumb ov105
 *   func_021B71C0 0x021B71C0 thumb ov101
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021B85A4 0x021B85A4 thumb ov105
 *   func_021B71E4 0x021B71E4 thumb ov101
 *   func_021B63D0 0x021B63D0 thumb ov101
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_020056A0 0x020056A0 thumb
 *   d_021B89D8 0x021B89D8 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02049740 0x02049740 arm
 *   func_02049238 0x02049238 arm
 *   d_021B8964 0x021B8964 data ov105 a4
 *   d_021B89B8 0x021B89B8 data a4
 *   d_021B8A08 0x021B8A08 data ov105 a4
 *   d_021B8998 0x021B8998 data ov105 a4
 *   func_0203FB44 0x0203FB44 arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B84C 0x0204B84C arm
 *   func_0204B800 0x0204B800 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 *   d_020A1448 0x020A1448 data a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_020450F0 0x020450F0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_02045738 0x02045738 arm
 *   func_02045740 0x02045740 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201EF6C 0x0201EF6C thumb
 *   func_021B80E8 0x021B80E8 thumb ov105
 */
#include "../../matched/include/Obj03234.h"
#include "../../matched/include/Obj22237.h"
#include "../../matched/include/Obj10249.h"
#include "../../matched/include/Obj22238.h"
#include "../../matched/include/Obj22239.h"
#include "../../matched/include/Obj22240.h"
#include "../../matched/include/Obj07989.h"
#include "../../matched/include/Obj22243.h"
#include "../../matched/include/Obj22244.h"
#include "../../matched/include/Obj22245.h"
#include "../../matched/include/Obj22246.h"
#include "../../matched/include/Obj22247.h"
#include "../../matched/include/Obj03235.h"
#include "../../matched/include/Obj13752.h"
#include "../../matched/include/Obj06374.h"
#include "../../matched/include/Obj22248.h"
#include "../../matched/include/Obj05277.h"
#include "../../matched/include/Obj02813.h"
#include "../../matched/include/Obj05278.h"
#include "../../matched/include/Obj05279.h"
#include "../../matched/include/Obj13753.h"
#include "../../matched/include/Obj22249.h"

#define CTX (*(u8 **)(p+0x1a4))
struct Task;
struct Obj0203159C;
struct Ctx;
struct Rec;
struct S020315D4;
struct DispVram;
struct Node;
struct DispConfig;
struct BgTemplate;
struct Cfg;
struct Bank;
struct Obj;
struct GfFont;
struct MsgBank;
struct WordSet;
struct PrintSys;
struct CharBuf;
struct Descriptor;
struct U16Vec;
struct StrObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Data { u32 f00; u8 f04,f05; u16 f06; u8 f08,f09,f0a; u8 low:4; u8 high:4; u8 tail[32]; } Data;

typedef struct {u32 objects[3]; u16 current[3]; u16 bound[3]; int step[3]; u8 pad[12]; u8 digits[3];u8 pad1;int state[3];} Display;

typedef struct Obj { u8 pad[0x78]; int busy; u8 pad7c[6]; u16 counter; } Obj;

typedef short s16;

typedef signed char s8;

typedef int s32;

typedef int s32_021B7A80;

typedef signed int     s32_021B7A88;

typedef int s32_021B7C94;

struct Rec { u32 f0; u32 f4; u8 f8; u8 pad9[3]; u32 fC; u16 f10; };

typedef struct { void *descriptor,*window; u8 active,pad[3]; void *buffer; u16 color; } Window;

extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,int);
extern u32 func_02012138(const struct Ctx *p);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02041F6C(u32 which, u32 op, u32 value);
extern void func_02041FB0(u32,u32,u16);
extern void func_021B8348(Display *,void *,int);
extern void func_021B658C(void *,Data *);
extern void *func_021B70DC(u32,u32,u16,u16,u8,u32,u32,u32,u16);
extern void func_021B728C(int,int);
extern void func_021B84B4(u8 *,int,int,int);
extern unsigned int func_021B8840(unsigned int x, int y);
extern void func_021B8598(void *);
extern void func_021B71C0(void *p);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int);
extern void func_0204E720(u32,int,int,int);
extern int func_0204E804(void);
extern void func_021B85A4(u8 *);
extern void func_021B71E4(int);
extern int func_021B63D0(Obj *);
extern void func_0204335C(u32 keep);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32 swap);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void *func_020056A0(void (*)(void *),void *,int);
extern void func_02030EAC(struct Node *);
extern void func_0203F8F4(int);
extern void func_02045088(int);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(unsigned int bgId, const struct BgTemplate *tmpl, unsigned int type);
extern void func_020414AC(u8);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *,int,int,int,int,int);
extern void func_02049658(void *,int,int,int,int,int,int);
extern void func_020498F4(void *,int,int,int,int,int,int);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void *func_02049740(void *,int,int,int,int,int);
extern void func_02049238(void *);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02040DA8(u32,u32,u32);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void *func_0204ABF0(void *,int,int,int,int);
extern void *func_0204A6C8(void *,int,int,int,int);
extern s32_021B7A88 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void *func_0204B294(void *,void *,void *,void *,void *,int,int);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B84C(void *,int);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_0201DD60(void);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201ED04(struct WordSet *);
extern void func_02045C04(struct Rec *);
extern void func_0201C4C0(struct PrintSys *);
extern void func_0201D83C(void *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_02045808(struct U16Vec *);
extern void func_020452E8(struct Descriptor *);
extern unsigned int func_0201C6C4(struct PrintSys *,void *);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045740(void *);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern unsigned func_0201D42C(void *,int);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201EF6C(struct WordSet *p, u32 i, u32 v, u32 a, u32 b);
extern void func_021B80E8(u8 *,u16 *);
int func_021B7560(struct Task *a,void *b,u8 *context);
int func_021B7730(int a,int b,int c,u8 *p);
int func_021B7778(void *a,u32 *state,void *b,u8 *p);
void func_021B784C(u8 *p,int a);
void func_021B78A0(unsigned char *p);
void func_021B78BC(u8 *p);
u32 func_021B78C8(u8 *p, int i);
u32 func_021B78D4(u8 *p);
void func_021B78E0(int a, unsigned char *p);
void func_021B78F4(void **p,int heap);
void func_021B7A3C(u32 *p);
void func_021B7A80(void *a0);
void func_021B7A88(void **p,const void *config,int heap);
void func_021B7BC0(void **p);
void func_021B7C04(void *a0);
void func_021B7C0C(void *p);
u32 func_021B7C14(u8 *p, int i);
u32 func_021B7C1C(u32 *p);
void func_021B7C20(u32 *p, int flag, int heap);
void func_021B7C6C(unsigned char *p);
u32 func_021B7C94(u8 *p);
int func_021B7CA0(void *p);
int func_021B7CA4(void *p);
int func_021B7CA8(void *p);
int func_021B7CAC(void *p);
void func_021B7CB0(struct Rec *p, u32 a, u32 b, u8 c, u8 d, u8 e, u8 f, u16 g);
void func_021B7D20(u8 *p,u32 a,u32 b,u8 c,u8 d,u8 e,u8 f,u16 color,u8 heap,u16 size);
void func_021B7D90(unsigned char *p);
int func_021B7DAC(unsigned char *p,unsigned char *q);
void func_021B7DE4(u8 *p,void *a,int b,int x,s16 y);
void func_021B7E48(u8 *p,void *a,int b);
void func_021B7EEC(u8 *p, void *a, u8 b, u16 c, u16 d);
void func_021B7F78(u8 *p, void *a, int b, u8 *c, u8 *d, int a5);
void func_021B8008(Window *p, void *a, u8 *b, unsigned c, int d);
void func_021B80BC(unsigned char *p, unsigned int v);
void func_021B80CC(unsigned char *p);
void func_021B80D8(u8 *p);
extern const u8 d_021B89D8[];
extern const u8 d_021B8964[],d_021B8A08[];
extern const int d_021B89B8[],d_021B8998[];
extern const int d_021B89B8[];
extern const u8 d_020A1448[];


int func_021B7560(struct Task *a,void *b,u8 *context)
{
    Data first,second;
    u8 *p;
    u32 handle;
    int tag,font;
    func_0203064C(1,60,0x20000);
    p=func_0203159C((struct Obj0203159C *)a,0x1a8,60);
    func_02082BCC(p,0,0x1a8);
    *(u8 * *)&((struct Obj03234 *)p)->f1A4=context;
    func_021B784C(p,60);
    func_021B7C20((u32 *)(p+0xb0),0,60);
    if(*(void **)CTX) func_02012138(*(void **)CTX);
    func_021B7CB0((struct Rec *)(p+0xc0),5,1,(u32)18,30,5,5,60);
    func_0201F73C(((struct Obj03234 *)p)->fC0,0,(u16)(((struct Obj03234 *)p)->f0),6);
    func_021B7D20(p+0xd4,7,6,3,20,5,8,1,1,60);
    func_021B7E48(p+0xd4,p+0xb0,1);
    func_02041F6C(7,3,4096);
    func_02041F6C(7,6,4096);
    func_02041FB0(7,9,128);
    func_02041FB0(7,12,40);
    func_021B8348((Display *)(p+0xe8),p,CTX[12]);
    if(*(void **)CTX) {
        func_021B658C(*(void **)CTX,&first);
        func_021B7F78(p+0xc0,p+0xb0,0,(u8 *)&first,*(u8 **)(CTX+8),60);
    }
    handle=func_021B78D4(p);
    tag=func_021B7CA0(p+0xb0);
    font=func_021B7CA4(p+0xb0);
    ((struct Obj03234 *)p)->f188=func_021B70DC(2,handle,0,13,13,2,tag,font,60);
    func_021B728C(*(int *)&((struct Obj03234 *)p)->f188,0);
    func_021B84B4(p+0x128,3,CTX[12],60);
    if(*(void **)CTX) {
        func_021B658C(*(void **)CTX,&second);
        if(second.low && ((Data *)*(void **)(CTX+8))->low) ((struct Obj03234 *)p)->f19C=1;
        else ((struct Obj03234 *)p)->f19C=0;
        ((struct Obj03234 *)p)->f1A0=func_021B8840(CTX[12],((struct Obj03234 *)p)->f19C);
    }
    func_021B80BC(p,(unsigned int)func_021B80D8);
    return 1;
}


/*
 * extent: Two zero alignment bytes after return, before 021B7778.
 */
int func_021B7730(int a,int b,int c,u8 *p) {
 func_021B8598(p+0x128); func_021B7D90(p+0xd4);
 func_021B71C0((void *)(((struct Obj22237 *)p)->f188)); func_021B7D90(p+0xc0);
 func_021B78A0(p); func_021B7C6C(p+0xb0);
 func_020315D4((struct S020315D4 *)a); func_020306F0(60); return 1;
}


/*
 * extent: 210-byte code; 021B784A..021B784C is two zero alignment bytes.
 * prototype: 7C94 tail-forwards u32 from own matched 0201C4E4;
 * caller tests r0. The owner's void declaration stays untouched.
 */
int func_021B7778(void *a,u32 *state,void *b,u8 *p)
{
    Obj *object;
    switch(*state) {
    case 0: *state=1; break;
    case 1: func_0204E720(3,16,0,0); *state=2; break;
    case 2: if(!func_0204E804()) *state=3; break;
    case 3:
        (*(void (**)(u8 *,u16 *))(p+0x18c))(p,(u16 *)(p+0x190));
        if(((struct Obj10249 *)p)->f194) *state=4;
        break;
    case 4: func_0204E720(3,0,16,0); *state=5; break;
    case 5: if(!func_0204E804()) *state=6; break;
    case 6: return 1;
    }
    if(func_021B7C94(p+0xb0)) {
        func_021B7DAC(p+0xc0,p+0xb0);
        func_021B7DAC(p+0xd4,p+0xb0);
    }
    func_021B78BC(p);
    func_021B85A4(p+0x128);
    func_021B71E4(((struct Obj10249 *)p)->f188);
    object=*(Obj * *)&((struct Obj22238 *)(*(u8 * *)&((struct Obj10249 *)p)->f1A4))->f4;
    if(object) func_021B63D0(object);
    return 0;
}


void func_021B784C(u8 *p,int a) {
 func_02082BCC(p,0,0xb0); func_0204335C(0); func_020433E0((const struct DispVram *)d_021B89D8);
 func_0204363C(0); func_0204361C(); func_020434CC();
 func_021B7A88((void **)(p+4),d_021B89D8,a); func_021B78F4((void **)p,a);
 ((struct Obj22239 *)p)->fAC=func_020056A0((void (*)(void *))func_021B78E0,p,0);
}


void func_021B78A0(unsigned char *p) { func_02030EAC(*(struct Node * *)&((struct Obj22240 *)p)->fAC); func_021B7A3C((unsigned int *)p); func_021B7BC0((void **)(p+4)); }


/*
 * evidence: func_021B7C04 is ov105's own code ("ldr r3, =0x0204A600; bx r3"
 * after the pop at 0x021B7C00), inside ov105's window, so only ov105 can be
 * resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference;
 * it attests as sole-ref/code from ov105's own listing.  The old hint ov021
 * named a different overlay's function mapped over the same address.
 */
void func_021B78BC(u8 *p) { func_021B7C04(p + 4); }


/*
 * Unblocked by matching func_021B7C14 in ov105 (pkt_ov105_021B7C14).
 */
u32 func_021B78C8(u8 *p, int i) { return func_021B7C14(p + 4, i); }


u32 func_021B78D4(u8 *p) { return func_021B7C1C((u32 *)(p + 4)); }


void func_021B78E0(int a, unsigned char *p) { func_021B7A80(p); func_021B7C0C(p+4); }


void func_021B78F4(void **p,int heap)
{
    int i,id;
    void *archive;
    func_0203F8F4(heap); func_02045088(heap); func_0203FC28((struct DispConfig *)d_021B8964);
    for(i=0;i<8;++i) {
        id=d_021B89B8[i];
        func_0203FCA0((u8)id,(const struct BgTemplate *)(d_021B8A08+i*32),(u8)d_021B8998[i]);
        func_020414AC((u8)id); func_02040588((u8)id,1);
    }
    archive=func_020490F4(0x5e,heap);
    func_02049B68(archive,16,0,0,0,heap);
    func_02049B68(archive,16,4,0,0,heap);
    func_02049658(archive,0,2,0,0,0,heap);
    func_02049658(archive,0,6,0,0,0,heap);
    func_02049658(archive,48,4,0,0,0,heap);
    func_02049658(archive,13,1,0,0,0,heap);
    func_020498F4(archive,4,2,0,0,0,heap);
    func_020498F4(archive,4,6,0,0,0,heap);
    func_020498F4(archive,46,4,0,0,0,heap);
    func_020498F4(archive,14,1,0,0,0,heap);
    func_02040C14(5,0,1,0);
    *p=func_02049740(archive,49,5,0,0,heap);
    func_02049238(archive);
}


void func_021B7A3C(u32 *p) {
 int i;
 func_0203FB44(5,(u16)(*p),(u16)(*p>>16));
 func_02040DA8(5,1,0);
 for(i=0;i<8;i++) func_020403F4((u8)d_021B89B8[i]);
 func_020450C8(); func_0203F9B4();
}



void func_021B7A80(void *a0) { func_020419E4(); }



/*
 * lever: later pos2 declaration reproduces its lower stack slot.
 */
void func_021B7A88(void **p,const void *config,int heap)
{
    u16 pos[4],pos2[4];
    void *archive;
    int i;
    func_02082BCC(p,0,0xa8);
    func_0204A48C((const struct Cfg *)d_020A1448,(unsigned int)config,heap);
    p[0]=func_0204B100(128,0,heap);
    func_0204B270(p[0]);
    func_020434DC(16,1); func_02043598(16,1);
    archive=func_020490F4(0x5e,heap);
    p[1]=func_0204ABF0(archive,12,0,0,heap);
    p[2]=func_0204A6C8(archive,11,0,0,heap);
    p[3]=(void *)func_0204AF28(archive,10,9,heap);
    func_02049238(archive);
    func_02082BCC(pos,0,8);
    for(i=0;i<3;++i) p[4+i]=func_0204B294(p[0],p[2],p[1],p[3],pos,0,heap);
    func_02082BCC(pos2,0,8);
    pos2[0]=128; pos2[1]=96;
    p[41]=func_0204B294(p[0],p[2],p[1],p[3],pos2,0,heap);
    func_0204B3DC(p[41],0); func_0204B84C(p[41],0); func_0204B800(p[41],0);
    func_0204B92C(p[41],1); func_0204B878(p[41],11);
    for(i=0;i<3;++i) {
        func_0204B3DC(p[4+i],0); func_0204B84C(p[4+i],0); func_0204B800(p[4+i],0);
    }
}



void func_021B7BC0(void **p) {
 int i;
 for(i=0;i<38;i++) if(p[i+4]) func_0204B3B4(p[i+4]);
 func_0204ADA4((u32)p[1]); func_0204A8D4((u32)p[2]); func_0204AFD8((u32)p[3]);
 func_0204B1CC(p[0]); func_0204A5AC(); func_02082BCC(p,0,0xa8);
}



void func_021B7C04(void *a0) { func_0204A600(); }



void func_021B7C0C(void *p) { func_0204A648(); }




u32 func_021B7C14(u8 *p, int i)
{
    return *(u32 *)(p + i * 4 + 0x10);
}




u32 func_021B7C1C(u32 *p)
{
    return *p;
}



void func_021B7C20(u32 *p, int flag, int heap) {
 func_02082BCC(p, 0, 0x10);
 func_0201DD60();
 if (flag == 0) {
  p[0] = (u32)func_0201D7EC(0x17, 0, 0, 0, heap);
 }
 p[2] = func_0201C440((void *)heap);
 p[1] = (u32)func_02045B38(0, 2, 0x33, heap);
 p[3] = (u32)func_0201EC64(heap);
}



void func_021B7C6C(unsigned char *p) { func_0201ED04(*(struct WordSet * *)&((struct Obj07989 *)p)->fC); func_02045C04(*(struct Rec * *)&((struct Obj07989 *)p)->f4); func_0201C4C0(*(struct PrintSys * *)&((struct Obj07989 *)p)->f8); func_0201D83C(((struct Obj07989 *)p)->f0); func_02082BCC(p,0,16); }



u32 func_021B7C94(u8 *p) { return func_0201C4E4((struct PrintSys *)(((struct Obj22243 *)p)->f8)); }




/*
 * four int getters at +0, +8, +4, +c.
 */
int func_021B7CA0(void *p)
{
    return ((struct Obj22244 *)p)->f0;
}




int func_021B7CA4(void *p)
{
    return ((struct Obj22245 *)p)->f8;
}




int func_021B7CA8(void *p)
{
    return ((struct Obj22246 *)p)->f4;
}




int func_021B7CAC(void *p)
{
    return ((struct Obj22247 *)p)->fC;
}



void func_021B7CB0(struct Rec *p, u32 a, u32 b, u8 c, u8 d, u8 e, u8 f, u16 g)
{
    int q;
    func_02082BCC(p, 0, 20);
    p->f10 = 15;
    p->f0 = func_020450F0(a, b, c, d, e, f, 1);
    p->fC = (u32)func_020457B0(255, g);
    p->f4 = p->f0;
    p->f8 = 0;
    func_02043B5C(func_02045770((struct Descriptor *)p->f0), p->f10);
    q = p->f0;
    func_02045334((void *)q);
    func_02045374((struct Cfg *)q);
    func_020409B4(func_02045730((struct Descriptor *)q));
}



void func_021B7D20(u8 *p,u32 a,u32 b,u8 c,u8 d,u8 e,u8 f,u16 color,u8 heap,u16 size) {
 void *q;
 func_02082BCC(p,0,0x14); ((struct Obj03235 *)p)->f10=color;
 ((struct Obj03235 *)p)->f0=(void *)func_020450F0(a,b,c,d,e,f,heap);
 ((struct Obj03235 *)p)->fC=func_020457B0(0xff,size);
 ((struct Obj03235 *)p)->f4=((struct Obj03235 *)p)->f0; p[8]=0;
 func_02043B5C(func_02045770(((struct Obj03235 *)p)->f0),((struct Obj03235 *)p)->f10);
 q=((struct Obj03235 *)p)->f0; func_02045334(q); func_02045374(q); func_020409B4(func_02045730(q));
}



void func_021B7D90(unsigned char *p) { func_02045808(*(struct U16Vec * *)&((struct Obj13752 *)p)->fC); func_020452E8(*(struct Descriptor * *)&((struct Obj13752 *)p)->f0); func_02082BCC(p,0,20); }



int func_021B7DAC(unsigned char *p,unsigned char *q) { struct PrintSys *s; s=*(struct PrintSys * *)&((struct Obj22248 *)q)->f8; if(p[8]) { if(!func_0201C6C4(s,func_02045770(*(struct Descriptor * *)&((struct Obj06374 *)p)->f4))) { func_02045334(*(struct Descriptor * *)&((struct Obj06374 *)p)->f4); p[8]=0; } } if(!p[8]) return 1; return 0; }



void func_021B7DE4(u8 *p,void *a,int b,int x,s16 y) {
 int bank; int font; int tag;
 bank=func_021B7CA8(a); font=func_021B7CA4(a); tag=func_021B7CA0(a);
 func_02043B5C(func_02045770(((struct Obj05277 *)p)->f0),((struct Obj05277 *)p)->f10);
 func_02045CAC((struct MsgBank *)bank,b,((struct Obj05277 *)p)->fC);
 func_0201C6FC((struct PrintSys *)font,(u32)func_02045770(((struct Obj05277 *)p)->f4),(s16)x,y,((struct Obj05277 *)p)->fC,tag); p[8]=1;
}



void func_021B7E48(u8 *p,void *a,int b)
{
 int bank; int font; int tag; u16 x,y;
 bank=func_021B7CA8(a); font=func_021B7CA4(a); tag=func_021B7CA0(a);
 func_02043B5C(func_02045770(((struct Obj02813 *)p)->f0),((struct Obj02813 *)p)->f10);
 func_02045CAC((struct MsgBank *)bank,b,((struct Obj02813 *)p)->fC);
 x=func_02045738(((struct Obj02813 *)p)->f0)*4; y=func_02045740(((struct Obj02813 *)p)->f0)*4;
 x-= (u16)(func_0201D304(((struct Obj02813 *)p)->fC,tag,0)/2);
 y-= (u16)(func_0201D42C(((struct Obj02813 *)p)->fC,tag)/2);
 func_0201C724((void *)font,(u32)func_02045770(((struct Obj02813 *)p)->f4),(s16)x,(s16)y,(u32)(((struct Obj02813 *)p)->fC),tag,15812);
 p[8]=1;
}



void func_021B7EEC(u8 *p, void *a, u8 b, u16 c, u16 d)
{
 void *msg; int bank; void *text; int font; int tag;
 func_02043B5C(func_02045770(((struct Obj05278 *)p)->f0),((struct Obj05278 *)p)->f10);
 msg=(void *)func_021B7CAC(a); bank=func_021B7CA8(a);
 func_0201EFA4(msg,d,c,3,0,1);
 text=func_02045EC0((struct MsgBank *)bank,b);
 func_0201F250(msg,((struct Obj05278 *)p)->fC,text); func_02045808(text);
 font=func_021B7CA4(a); tag=func_021B7CA0(a);
 func_0201C6FC((struct PrintSys *)font,(u32)func_02045770(((struct Obj05278 *)p)->f4),0,0,((struct Obj05278 *)p)->fC,tag);
 p[8]=1;
}



void func_021B7F78(u8 *p, void *a, int b, u8 *c, u8 *d, int a5)
{
 void *msg; int bank; void *text; int font; int tag;
 func_02043B5C(func_02045770(((struct Obj05279 *)p)->f0),((struct Obj05279 *)p)->f10);
 msg=(void *)func_021B7CAC(a); bank=func_021B7CA8(a);
 func_0201F02C(msg,0,d+12); func_0201F02C(msg,1,c+12);
 text=func_02045EC0((struct MsgBank *)bank,b);
 func_0201F250(msg,((struct Obj05279 *)p)->fC,text); func_02045808(text);
 font=func_021B7CA4(a); tag=func_021B7CA0(a);
 func_0201C6FC((struct PrintSys *)font,(u32)func_02045770(((struct Obj05279 *)p)->f4),0,0,((struct Obj05279 *)p)->fC,tag);
 p[8]=1;
}



void func_021B8008(Window *p, void *a, u8 *b, unsigned c, int d)
{
 void *msg; int bank; void *text; int font; int tag; int flag;
 func_02043B5C(func_02045770(p->descriptor),p->color);
 msg=(void *)func_021B7CAC(a);
 bank=func_021B7CA8(a);
 b+=12; func_0201F02C(msg,0,b); flag=0;
 if(c>1) flag=1;
 func_0201EF6C(msg,1,134,flag,0); func_0201EFA4(msg,2,c,1,0,1);
 text=func_02045EC0((void *)bank,d);
 func_0201F250(msg,p->buffer,text); func_02045808(text);
 font=func_021B7CA4(a); tag=func_021B7CA0(a);
 func_0201C6FC((struct PrintSys *)font,(u32)func_02045770(p->window),0,0,p->buffer,tag);
 p->active=1;
}




void func_021B80BC(unsigned char *p, unsigned int v) { ((struct Obj13753 *)p)->f18C=v; ((struct Obj13753 *)p)->f190=0; }




void func_021B80CC(unsigned char *p) { ((struct Obj22249 *)p)->f194=1; }



void func_021B80D8(u8 *p)
{
    func_021B80BC(p,(unsigned int)func_021B80E8);
}
