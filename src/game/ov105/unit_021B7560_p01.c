/*
 * file:     unit_021B7560_p01.c
 * unit:     yes
 * function: func_021B7560, func_021B7730, func_021B7778, func_021B784C, func_021B78A0, func_021B78BC, func_021B78C8, func_021B78D4, func_021B78E0, func_021B78F4, func_021B7A3C
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
 *   func_021B7C20 0x021B7C20 thumb ov105
 *   func_021B7CB0 0x021B7CB0 thumb ov105
 *   func_021B7D20 0x021B7D20 thumb ov105
 *   func_021B7E48 0x021B7E48 thumb ov105
 *   func_021B8348 0x021B8348 thumb ov105
 *   func_021B658C 0x021B658C thumb ov101
 *   func_021B7F78 0x021B7F78 thumb ov105
 *   func_021B7CA0 0x021B7CA0 thumb ov105
 *   func_021B7CA4 0x021B7CA4 thumb ov105
 *   func_021B70DC 0x021B70DC thumb ov101
 *   func_021B728C 0x021B728C thumb ov101
 *   func_021B84B4 0x021B84B4 thumb ov105
 *   func_021B8840 0x021B8840 thumb ov105
 *   func_021B80BC 0x021B80BC thumb ov105
 *   func_021B80D8 0x021B80D8 thumb ov105
 *   func_021B8598 0x021B8598 thumb ov105
 *   func_021B7D90 0x021B7D90 thumb ov105
 *   func_021B71C0 0x021B71C0 thumb ov101
 *   func_021B7C6C 0x021B7C6C thumb ov105
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021B7C94 0x021B7C94 thumb ov105
 *   func_021B7DAC 0x021B7DAC thumb ov105
 *   func_021B85A4 0x021B85A4 thumb ov105
 *   func_021B71E4 0x021B71E4 thumb ov101
 *   func_021B63D0 0x021B63D0 thumb ov101
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_021B7A88 0x021B7A88 thumb ov105
 *   func_020056A0 0x020056A0 thumb
 *   d_021B89D8 0x021B89D8 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_021B7BC0 0x021B7BC0 thumb ov105
 *   func_021B7C04  0x021B7C04  thumb  ov105
 *   func_021B7C14  0x021B7C14  thumb  ov105
 *   func_021B7C1C  0x021B7C1C  thumb  ov105
 *   func_021B7A80 0x021B7A80 thumb ov105
 *   func_021B7C0C 0x021B7C0C thumb ov105
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
 */
#include "../../matched/include/Obj03234.h"
#include "../../matched/include/Obj22237.h"
#include "../../matched/include/Obj10249.h"
#include "../../matched/include/Obj22238.h"
#include "../../matched/include/Obj22239.h"
#include "../../matched/include/Obj22240.h"

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
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Data { u32 f00; u8 f04,f05; u16 f06; u8 f08,f09,f0a; u8 low:4; u8 high:4; u8 tail[32]; } Data;

typedef struct {u32 objects[3]; u16 current[3]; u16 bound[3]; int step[3]; u8 pad[12]; u8 digits[3];u8 pad1;int state[3];} Display;

typedef struct Obj { u8 pad[0x78]; int busy; u8 pad7c[6]; u16 counter; } Obj;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,int);
extern u32 func_02012138(const struct Ctx *p);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02041F6C(u32 which, u32 op, u32 value);
extern void func_02041FB0(u32,u32,u16);
extern void func_021B7C20(u32 *p, int flag, int heap);
extern void func_021B7CB0(struct Rec *p, u32 a, u32 b, u8 c, u8 d, u8 e, u8 f, u16 g);
extern void func_021B7D20(u8 *,u32,u32,u8,u8,u8,u8,u16,u8,u16);
extern void func_021B7E48(u8 *,void *,int);
extern void func_021B8348(Display *,void *,int);
extern void func_021B658C(void *,Data *);
extern void func_021B7F78(u8 *,void *,int,u8 *,u8 *,int);
extern int func_021B7CA0(void *),func_021B7CA4(void *);
extern void *func_021B70DC(u32,u32,u16,u16,u8,u32,u32,u32,u16);
extern void func_021B728C(int,int);
extern void func_021B84B4(u8 *,int,int,int);
extern unsigned int func_021B8840(unsigned int x, int y);
extern void func_021B80BC(unsigned char *p, unsigned int v);
extern void func_021B80D8(u8 *p);
extern void func_021B8598(void *);
extern void func_021B7D90(unsigned char *p);
extern void func_021B71C0(void *p);
extern void func_021B7C6C(unsigned char *p);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int);
extern void func_0204E720(u32,int,int,int);
extern int func_0204E804(void);
extern u32 func_021B7C94(u8 *);
extern int func_021B7DAC(u8 *,u8 *);
extern void func_021B78BC(u8 *),func_021B85A4(u8 *);
extern void func_021B71E4(int);
extern int func_021B63D0(Obj *);
extern void func_0204335C(u32 keep);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32 swap);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_021B7A88(void **p, const void *config, int heap);
extern void *func_020056A0(void (*)(void *),void *,int);
extern void func_02030EAC(struct Node *);
extern void func_021B7BC0(void **);
extern void func_021B7C04(void *);
extern u32 func_021B7C14(u8 *p, int i);
extern u32 func_021B7C1C(u32 *p);
extern void func_021B7A80(void *);
extern void func_021B7C0C(void *);
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
extern const u8 d_021B89D8[];
extern const u8 d_021B8964[],d_021B8A08[];
extern const int d_021B89B8[],d_021B8998[];
extern const int d_021B89B8[];

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
