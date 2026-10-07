/*
 * file:     irc_ranking_p03.c
 * unit:     yes
 * function: func_021B78D8, func_021B78E0, func_021B7948, func_021B7984, func_021B7BC4, func_021B7D14, func_021B7F00, func_021B7F74, func_021B7F7C
 * address:  0x021B78D8
 * region:   ov106
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021B84D0 0x021B84D0 thumb ov106
 *   func_021B78D0 0x021B78D0 thumb ov106
 *   func_021B727C 0x021B727C thumb ov101
 *   func_021B8FA8 0x021B8FA8 thumb ov106
 *   func_021B900C 0x021B900C thumb ov106
 *   func_021B8E50 0x021B8E50 thumb ov106
 *   func_021B8408 0x021B8408 thumb ov106
 *   func_021B9134 0x021B9134 thumb ov106
 *   func_021B8E90 0x021B8E90 thumb ov106
 *   func_0207CA68 0x0207CA68 arm
 *   d_021B949C 0x021B949C data a4
 *   func_021B9198 0x021B9198 thumb ov106
 *   func_021B913C 0x021B913C thumb ov106
 *   func_021B7250 0x021B7250 thumb ov101
 *   func_021B838C 0x021B838C thumb ov106
 *   func_021B8DA8 0x021B8DA8 thumb ov106
 *   func_021B8FD0 0x021B8FD0 thumb ov106
 *   func_021B71E4 0x021B71E4 thumb ov101
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ll_mul 0x0209C054 arm
 *   func_0207C768 0x0207C768 arm
 *   func_021B84C4 0x021B84C4 thumb ov106
 *   func_021B8518 0x021B8518 thumb ov106
 *   _fflt 0x0209BDBC arm
 *   func_02082BCC 0x02082BCC arm
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
 *   func_02049B40 0x02049B40 arm
 *   func_02049238 0x02049238 arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02012944 0x02012944 thumb
 *   func_021B91A8 0x021B91A8 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021B94A8 0x021B94A8 data
 *   d_021B9524 0x021B9524 data a4
 *   func_020452E8 0x020452E8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 */
#include "../../matched/include/Obj22258.h"
#include "../../matched/include/Obj10252.h"
#include "../../matched/include/Obj10253.h"
#include "../../matched/include/G_BgEntry.h"
#include "../../matched/include/Obj13758.h"

#define SCALE(a) ((int)(((long long)func_0207C768(ROUND(a)-81920,163840)*245760+2048)>>12))
struct DispConfig;
struct Descriptor;
struct MsgBank;
struct GfFont;
struct StrObj;
struct Cfg;
struct CharBuf;
struct Rec;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_021B78D8;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32_021B78D8;

typedef signed int     s32_021B78E0;

typedef signed int     s32_021B7948;

typedef signed short s16_021B7984;

typedef struct { int x,y; } Pair;

typedef struct { int x,y,z; } Vec;

typedef signed short s16_021B7BC4;

struct BgTemplate { u8 bytes[32]; };

typedef struct { u32 bg; struct BgTemplate t; u32 type; } BgEntry;

typedef short s16_021B7F74;

typedef int s32_021B7F74;

typedef short s16_021B7F7C;

typedef int s32_021B7F7C;

extern void func_0204E720(u32 a, s32_021B78E0 b, s32_021B78E0 c, s32_021B78E0 d);
extern int func_0204E804(void);
extern int func_021B84D0(u8 *);
extern void func_021B78D0(u8 *,u32);
extern int func_021B727C(int),func_021B7250(int *);
extern void *func_021B8FA8(u8 *p, int *out);
extern int func_021B8E50(u8 *,Pair *,Pair *,Pair *),func_021B8E90(u8 *,Pair *,Pair *,Vec *,int *);
extern int func_0207CA68(const Vec *,const Vec *),func_0207C768(int,int);
extern void func_021B900C(u8 *,int,int),func_021B8408(u8 *,s16_021B7984),func_021B9134(u8 *);
extern int func_021B9198(int *p);
extern s16_021B7984 func_021B913C(u8 *);
extern void func_021B838C(u8 *);
extern void func_021B8DA8(int *);
extern void func_021B8FD0(u8 *);
extern void func_021B71E4(int a);
extern s16_021B7BC4 func_021B84C4(u8 *),func_021B8518(u8 *);
extern void func_021B8408(u8 *,s16_021B7BC4);
extern void func_02082BCC(void *, int, u32);
extern void func_0203F8F4(u32);
extern void func_02045088(u32);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_020490F4(unsigned int id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern unsigned int func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02040C14(u32, u32, u32, u32);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 flags);
extern void func_02049B40(u32, u32, u32, u32, u32, u32);
extern void func_02049238(void *);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *, u32);
extern u8 *func_02012944(void *p);
extern void func_021B91A8(struct Descriptor *, struct StrObj *, void *, u32);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern void func_020409B4(u32);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
void func_021B78D8(u8 *p);
void func_021B78E0(u8 *a, int *state, u8 *p);
void func_021B7948(u8 *a,int *s);
void func_021B7984(u8 *a,u32 unused,u8 *p);
void func_021B7BC4(u8 *a,u32 unused,u8 *p);
void func_021B7D14(u32 *p, void *arg, u32 heap);
void func_021B7F00(u32 *p);
void func_021B7F74(u8 *a0);
u32 func_021B7F7C(u8 *p, u32 i);
extern const Vec d_021B949C;
extern struct DispConfig d_021B94A8;
extern BgEntry d_021B9524[];


void func_021B78D8(u8 *p) { ((struct Obj22258 *)p)->f4 = 1; }

void func_021B78E0(u8 *a, int *state, u8 *p)
{
    switch (*state) {
    case 0: func_0204E720(3,16,0,0); *state = 1; break;
    case 1: if (!func_0204E804()) *state = 2; break;
    case 2:
        if (func_021B84D0(p+0x38) != 65535) func_021B78D0(p+0x28,(u32)func_021B7BC4);
        else func_021B78D0(a,(u32)func_021B7984);
        break;
    }
}

void func_021B7948(u8 *a,int *s) { switch (*s) { case 0: func_0204E720(3,0,16,0); *s=1; break; case 1: if (!func_0204E804()) *s=2; break; case 2: func_021B78D8(a); break; } }

#define ROUND(a) ((int)((a)!=0 ? (float)((a)<<12)+0.5f : (float)((a)<<12)-0.5f))

/*
 * note: Unsigned conversion and ROUND use runtime-proven add C95C/sub CB8C. 8FA8 stores word +28 then tail-calls 3630C; 8E90 reads five inputs, writes Pair/Vec/word outputs.
 */
void func_021B7984(u8 *a,u32 unused,u8 *p) {
    u32 value;
    Pair pair;
    Vec vec;
    int duration;
    if(!func_021B727C(*(int *)&((struct Obj10252 *)p)->f614)) {
        if(((u32)func_021B8FA8(p+0x5d4,(int *)(&value)))&128) {
            if(ROUND(value)>81920)func_021B900C(p+0x600,SCALE(value),12);
            else func_021B900C(p+0x600,8192,12);
        } else if(((u32)func_021B8FA8(p+0x5d4,(int *)(&value)))&64) {
            if(ROUND(value)>81920)func_021B900C(p+0x600,-SCALE(value),12);
            else func_021B900C(p+0x600,-8192,12);
        } else if(func_021B8E50(p+0x5d4,0,0,&pair)) {
            func_021B8408(p+0x38,-pair.y);
            func_021B9134(p+0x600);
        } else if(func_021B8E90(p+0x5d4,0,0,&vec,&duration))
            func_021B900C(p+0x600,func_0207CA68(&d_021B949C,&vec),duration);
    }
    if(func_021B9198((int *)(p+0x600)))func_021B8408(p+0x38,func_021B913C(p+0x600));
    if(func_021B7250(*(int * *)&((struct Obj10252 *)p)->f614)==1)func_021B78D0(a,(u32)func_021B7948);
    func_021B838C(p+0x38);
    func_021B8DA8((int *)(p+0x5d4));
    func_021B8FD0(p+0x600);
    func_021B71E4(*(u32 *)&((struct Obj10252 *)p)->f614);
}

#undef ROUND
#define ROUND(a) ((int)((a)>0 ? (float)((a)<<12)+0.5f : (float)((a)<<12)-0.5f))

/*
 * note: The signed-halfword result of 021B913C is already sign-extended by its body. ROUND follows the runtime-confirmed add/subtract mapping.
 */
void func_021B7BC4(u8 *a,u32 unused,u8 *p) {
    int target,current,last;
    target=(s16_021B7BC4)(func_021B84D0(p+0x38)-192);
    if(target<0) target=0;
    current=func_021B84C4(p+0x38);
    last=func_021B8518(p+0x38);
    if((s16_021B7BC4)target>current && current!=last) {
        int n=++((struct Obj10253 *)p)->f640;
        if(ROUND(n)>81920)
            func_021B900C(p+0x600,(int)(((long long)(int)func_0207C768((int)(ROUND(n)-81920),(int)163840)*245760+2048)>>12),12);
        else func_021B900C(p+0x600,8192,12);
    } else {
        func_021B9134(p+0x600);
        func_021B78D0(p+0x28,(u32)func_021B7984);
    }
    if(func_021B9198((int *)(p+0x600))) func_021B8408(p+0x38,func_021B913C(p+0x600));
    if(func_021B7250(*(int * *)&((struct Obj10253 *)p)->f614)==1)func_021B78D0(a,(u32)func_021B7948);
    func_021B838C(p+0x38);
    func_021B8FD0(p+0x600);
    func_021B71E4((u32)(*(u32 *)&((struct Obj10253 *)p)->f614));
}

void func_021B7D14(u32 *p, void *arg, u32 heap) {
 int i; int k; u32 bg; struct MsgBank *msg; struct GfFont *font; struct StrObj *str;
 func_02082BCC(p, 0, 0x10);
 func_0203F8F4(heap);
 func_02045088(heap);
 func_0203FC28(&d_021B94A8);
 for (i = 0; i < 8; i++) {
  bg = d_021B9524[i].bg;
  func_0203FCA0((u8)bg, &d_021B9524[i].t, (u8)d_021B9524[i].type);
  func_020414AC(bg);
  func_02040588(bg, 1);
 }
 p[0] = (u32)func_020490F4(0x4d, heap);
 func_02049B68((void *)p[0], 0, 0, 0, 0, heap);
 func_02049658((void *)p[0], 1, 3, 0, 0, 0, heap);
 func_02049658((void *)p[0], 3, 0, 0, 0, 0, heap);
 func_020498F4((void *)p[0], 4, 3, 0, 0, 0, heap);
 func_020498F4((void *)p[0], 6, 0, 0, 0, 0, heap);
 func_02049B68((void *)p[0], 0, 4, 0, 0, heap);
 k = 7;
 func_02049658((void *)p[0], 3, 7, 0, 0, 0, heap);
 func_020498F4((void *)p[0], 7, 7, 0, 0, 0, heap);
 func_02040C14(1, 0, 1, 0);
 func_02040C14(5, 0, 1, 0);
 p[1] = func_02049740((void *)p[0], 2, 1, 0, 0, heap);
 p[2] = func_02049740((void *)p[0], 2, 5, 0, 0, heap);
 func_02049B40(0x17, 5, 0, k << 6, 0x20, heap);
 func_02049B40(0x17, 5, 4, k << 6, 0x20, heap);
 func_02049238((void *)p[0]);
 msg = func_02045B38(0, 2, 0x32, heap);
 font = func_0201D7EC(0x17, 0, 0, 0, heap);
 p[3] = func_020450F0(0, 3, 1, 0x1a, (u32)2, (u32)0xe, (u32)1);
 func_02043B5C(func_02045770((struct Descriptor *)p[3]), 0xf);
 str = (struct StrObj *)func_02045EC0(msg, 0);
 func_021B91A8((struct Descriptor *)p[3], str, func_02012944(arg), (u32)font);
 func_02045808((struct U16Vec *)str);
 func_0201D83C(font);
 func_02045C04((struct Rec *)msg);
 func_02045334((struct Descriptor *)p[3]);
 func_02045374((struct Cfg *)p[3]);
 func_020409B4(0);
}

void func_021B7F00(u32 *p) {
    int i;
    func_020452E8((struct Descriptor *)p[3]);
    func_0203FB44((int)1,(u16)p[1],(u16)(p[1]>>16));
    func_0203FB44((int)5,(u16)p[2],(u16)(p[2]>>16));
    func_02040DA8(5,1,0);
    func_02040DA8(1,1,0);
    for(i=0;i<8;i++)func_020403F4((u8)d_021B9524[i].bg);
    func_020450C8();func_0203F9B4();
    func_02082BCC(p,0,16);
}

void func_021B7F74(u8 *a0) { func_020419E4(); }


u32 func_021B7F7C(u8 *p, u32 i) { return i ? ((struct Obj13758 *)p)->f4 : ((struct Obj13758 *)p)->f8; }
