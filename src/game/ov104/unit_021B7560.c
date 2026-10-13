/*
 * file:     unit_021B7560.c
 * unit:     yes
 * function: func_021B7560, func_021B7768, func_021B77EC, func_021B78EC, func_021B7940, func_021B795C, func_021B7968, func_021B7974, func_021B7980, func_021B7994, func_021B7AD4, func_021B7B24, func_021B7B2C, func_021B7CA4, func_021B7D0C, func_021B7D14, func_021B7D1C, func_021B7D24, func_021B7D28, func_021B7DAC, func_021B7DD4, func_021B7DE0, func_021B7DE4, func_021B7DE8, func_021B7DEC, func_021B7DF0, func_021B7E58, func_021B7EC8, func_021B7EE4, func_021B7F1C, func_021B7F80, func_021B7F90, func_021B8030, func_021B80B8, func_021B80D4, func_021B80F8, func_021B8104, func_021B816C, func_021B8178, func_021B817C, func_021B818C, func_021B8198, func_021B8220, func_021B829C, func_021B8384, func_021B8528, func_021B85D8, func_021B85E4, func_021B8614, func_021B8624, func_021B86A0, func_021B8724, func_021B874C, func_021B8768, func_021B87F4, func_021B8810, func_021B8834, func_021B884C, func_021B8880, func_021B89DC, func_021B8A88, func_021B8ADC, func_021B8AEC, func_021B8C3C, func_021B8D08, func_021B8D20, func_021B8DA4, func_021B8E8C, func_021B8E90, func_021B8EA4, func_021B8EB0, func_021B8F00
 * address:  0x021B7560
 * region:   ov104
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
 *   func_021B70DC 0x021B70DC thumb ov101
 *   func_021B63CC 0x021B63CC thumb ov101
 *   func_0207D658 0x0207D658 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021B8F08 0x021B8F08 thumb ov104
 *   func_02030EAC 0x02030EAC arm
 *   func_021B71C0 0x021B71C0 thumb ov101
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021B71E4 0x021B71E4 thumb ov101
 *   func_021B63D0 0x021B63D0 thumb ov101
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   d_021B8F78 0x021B8F78 data a4
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
 *   func_02049B40 0x02049B40 arm
 *   d_021B8F30 0x021B8F30 data ov104
 *   d_021B8F5C 0x021B8F5C data
 *   d_021B8FB4 0x021B8FB4 data
 *   d_021B8F40 0x021B8F40 data ov104
 *   func_02040DA8 0x02040DA8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   d_020A1448 0x020A1448 data
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B84C 0x0204B84C arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204A600  0x0204A600  arm
 *   func_0204A648 0x0204A648 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_020450F0 0x020450F0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_02045738 0x02045738 arm
 *   func_02045740 0x02045740 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021B7250 0x021B7250 thumb ov101
 *   func_021B6480 0x021B6480 thumb ov101
 *   func_021B727C 0x021B727C thumb ov101
 *   func_021B63BC 0x021B63BC thumb ov101
 *   func_021B630C 0x021B630C thumb ov101
 *   func_021B6424 0x021B6424 thumb ov101
 *   func_021B72A0 0x021B72A0 thumb ov101
 *   func_02087058 0x02087058 arm
 *   func_02086FE8 0x02086FE8 arm
 *   func_020870D0 0x020870D0 arm
 *   _ll_udiv 0x0209C00C arm
 *   func_021B64F0 0x021B64F0 thumb ov101
 *   d_021B8F28 0x021B8F28 data a4
 *   func_021B6508 0x021B6508 thumb ov101
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_021B64B8 0x021B64B8 thumb ov101
 *   func_02039338 0x02039338 arm
 *   func_02035D20 0x02035D20 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   d_020A1B38 0x020A1B38 data a2
 *   func_02061CA4 0x02061CA4 arm
 *   func_020056EC 0x020056EC thumb
 *   g_020A1B38 0x020A1B38 data a2
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CCA4 0x0207CCA4 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   func_0207CEE4 0x0207CEE4 arm
 *   func_0204B404 0x0204B404 arm
 *   _fflt 0x0209BDBC arm
 *   _ffix 0x0209C494 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 */
#include "../../matched/include/Obj07986.h"
#include "../../matched/include/Obj13741.h"
#include "../../matched/include/Obj07987.h"
#include "../../matched/include/Obj22214.h"
#include "../../matched/include/Obj22215.h"
#include "../../matched/include/Obj22216.h"
#include "../../matched/include/Obj22217.h"
#include "../../matched/include/Obj07988.h"
#include "../../matched/include/Obj22219.h"
#include "../../matched/include/Obj22220.h"
#include "../../matched/include/Obj22221.h"
#include "../../matched/include/Obj22222.h"
#include "../../matched/include/Obj22223.h"
#include "../../matched/include/Obj03233.h"
#include "../../matched/include/Obj13743.h"
#include "../../matched/include/Obj06372.h"
#include "../../matched/include/Obj22224.h"
#include "../../matched/include/Obj05273.h"
#include "../../matched/include/Obj02812.h"
#include "../../matched/include/Obj05274.h"
#include "../../matched/include/Obj10245.h"
#include "../../matched/include/Obj10246.h"
#include "../../matched/include/Obj22226.h"
#include "../../matched/include/Obj22227.h"
#include "../../matched/include/Obj13744.h"
#include "../../matched/include/Obj13745.h"
#include "../../matched/include/Obj05275.h"
#include "../../matched/include/Obj04432.h"
#include "../../matched/include/Obj22229.h"
#include "../../matched/include/Obj01389.h"
#include "../../matched/include/Obj22230.h"
#include "../../matched/include/Obj22231.h"
#include "../../matched/include/Obj22232.h"
#include "../../matched/include/Obj04433.h"
#include "../../matched/include/Obj22233.h"
#include "../../matched/include/Obj10248.h"
#include "../../matched/include/Obj02453.h"
#include "../../matched/include/Obj22235.h"
#include "../../matched/include/Obj04434.h"
#include "../../matched/include/Obj22236.h"

#define CTX(p) (*(u8 **)((p)+0x8b0))
#define W(o) (*(u32 *)(p+(o)))
#define SHIFT(v,n) ((int)((u32)(v)<<(n)))
struct Obj0203159C;
struct Ctx;
struct Node;
struct S020315D4;
struct Obj;
struct DispVram;
struct DispConfig;
struct Cfg;
struct Bank;
struct GfFont;
struct MsgBank;
struct WordSet;
struct Rec;
struct PrintSys;
struct Descriptor;
struct U16Vec;
struct CharBuf;
struct StrObj;
struct Entry;
struct Link;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

typedef struct { u8 pad[0x78]; int busy; u8 pad7c[6]; unsigned short counter; } Obj;

typedef signed char s8;

typedef int s32;

typedef enum { BG0=0 } BgId;

struct BgTemplate { u8 bytes[32]; };

typedef int s32_021B7B24;

typedef struct { char pad[0x60]; u32 f60; } S;

typedef signed int     s32_021B7B2C;

typedef struct { u16 x,y,z,w; } Desc;

typedef int s32_021B7980;

typedef struct {
    void *f0;
    void *f4;
    u8 f8;
    u8 pad_9[3];
    void *fC;
    u16 f10;
} Rec;

typedef enum { BASE=0x814 } Offset;

typedef struct {int words[33];} Block_021B7980;

typedef struct { u32 f0; u32 f4; } Pair;

typedef struct { u32 words[33]; } Record;

typedef struct { int words[33]; } Block_021B8880;

typedef signed int     s32_021B8880;

typedef enum { COLOR_TWO=2, COLOR_FIVE=5 } Color;

typedef enum { END_Y=-36 } EndY;

typedef struct { int x,y,z; } Vec;

typedef struct { int x, y; } Point;

typedef struct {
    void *object;
    u32 index, active;
    int sx, sy, sz, ex, ey, ez;
    u32 counter, lifetime;
} Particle;

typedef int s32_021B8E8C;

typedef int s32_021B8EA4;

typedef signed int     s32_021B8EB0;

extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *,u32,u32);
extern void func_02082BCC(void *,int,int);
extern u32 func_02012138(const struct Ctx *);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02041F6C(u32 which, u32 op, u32 value);
extern void func_02041FB0(u32,u32,u16);
extern void *func_021B70DC(u32,u32,u16,u16,u8,u32,u32,u32,u16);
extern void func_021B63CC(int *,int);
extern void func_0207D658(u32,int,int);
extern void *func_020056A0(u32,u32,u32);
extern void func_021B8F08(void *,u8 *);
extern void func_02030EAC(struct Node *n);
extern void func_021B71C0(void *p);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int);
extern void func_0204E720(u32,int,int,int);
extern int func_0204E804(void);
extern void func_021B71E4(int);
extern int func_021B63D0(struct Obj *p);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32 swap);
extern void func_0204361C(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02040C14(u32,u32,u32,u32);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void func_02049238(void *);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void func_02040DA8(u32,u32,u32);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void func_0204A48C(const struct Cfg *,u32,u32);
extern struct Bank *func_0204B100(int,u8,u32);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *);
extern void func_020434DC(u32,u32);
extern void func_02043598(u32,u32);
extern signed int func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32_021B7B2C func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021B7B2C func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern s32_021B7B2C func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_0204B84C(S *,u32);
extern void func_0204B92C(struct Obj *,u32);
extern void func_0204B878(struct Obj *,u16);
extern void func_0204B6F4(struct Obj *,u32,u32);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(int);
extern void func_0204A648(void);
extern void func_0201DD60(void);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02045C04(struct Rec *rec);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045808(struct U16Vec *);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_020061E4(u32 a);
extern int func_021B7250(int *p);
extern int func_021B6480(int *p);
extern int func_021B727C(int);
extern void func_021B63BC(int *);
extern int func_021B630C(int *,int);
extern int func_021B6424(int);
extern void func_021B72A0(int,int);
extern int func_02087058(void);
extern void func_02086FE8(void);
extern unsigned long long func_020870D0(void);
extern void func_021B64F0(u32 p, u32 a, u32 b, u32 c, u32 d);
extern void func_021B6508(u32 p, u32 a);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern u32 func_021B64B8(u32 p, u32 a, u32 b, u32 c, u8 d, u32 e, u32 f, u32 g);
extern u16 func_02039338(void);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern s32_021B8880 func_02061CA4(void *p, u32 a, u32 b, s32_021B8880 size);
extern u32 func_020056EC(u32);
extern void func_0207CA00(const Vec *,const Vec *,Vec *);
extern void func_0207CCA4(const Vec *,Vec *);
extern int func_0207CBD0(Vec *);
extern void func_0207CEE4(int,Vec *,Vec *,Vec *);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern float _fflt(int);
extern int _ffix(float);
extern float _fadd(float, float);
extern float _fsub(float, float);
int func_021B7560(struct Obj0203159C *obj,void *state,u8 *context);
int func_021B7768(int a,int b,int c,u8 *p);
int func_021B77EC(void *a,u32 *state,void *b,u8 *p);
void func_021B78EC(u8 *p,u16 a);
void func_021B7940(u8 *p);
void func_021B795C(u8 *p);
int func_021B7968(u8 *p, int i);
u32 func_021B7974(u8 *p);
void func_021B7980(u32 unused,u8 *p);
void func_021B7994(void *p,u16 heap);
void func_021B7AD4(u32 *p);
void func_021B7B24(void *a0);
void func_021B7B2C(u32 *p,const void *config,u16 heap);
void func_021B7CA4(void **p);
void func_021B7D0C(int x);
void func_021B7D14(void *p);
int func_021B7D1C(unsigned char *p, int i);
u32 func_021B7D24(u32 *p);
void func_021B7D28(unsigned *p, int mode, u16 heap);
void func_021B7DAC(u8 *p);
int func_021B7DD4(u8 *p);
int func_021B7DE0(void *p);
int func_021B7DE4(void *p);
int func_021B7DE8(void *p);
int func_021B7DEC(void *p);
void func_021B7DF0(Rec *p, u32 a, u32 b, u8 c, u8 d, u8 e, u8 f, u16 size);
void func_021B7E58(u8 *p,u32 a,u32 b,u8 c,u8 d,u8 e,u8 f,u16 color,u8 heap,u16 size);
void func_021B7EC8(u8 *p);
int func_021B7EE4(u8 *p,u8 *q);
void func_021B7F1C(u8 *p,void *a,int b,int x,s16 y);
void func_021B7F80(u8 *p,void *a,int b);
void func_021B7F90(u8 *p,void *a,int b,u16 c);
void func_021B8030(u8 *p, void *a, int b, u8 *c, s16 x, s16 y, u16 a6);
void func_021B80B8(u8 *p);
void func_021B80D4(int *p, u8 *q, int a2);
void func_021B80F8(void *p);
void func_021B8104(u32 *p);
void func_021B816C(u8 *p);
u32 func_021B8178(u8 *p);
void func_021B817C(char *p, u32 v);
void func_021B818C(u8 *p);
void func_021B8198(u8 *p,u16 *state);
void func_021B8220(u8 *p,u16 *state);
void func_021B829C(u8 *p,u16 *state);
void func_021B8384(u8 *p,u16 *state);
void func_021B8528(u8 *p,u16 *state);
void func_021B85D8(void *p);
void func_021B85E4(u8 *p);
int func_021B8614(u8 *p);
void func_021B8624(u8 *p);
int func_021B86A0(u8 *p);
void func_021B8724(u8 *p,int a);
void func_021B874C(u8 *p);
int func_021B8768(u8 *p,const Block_021B7980 *q);
void func_021B87F4(u8 *p,Record *out);
void func_021B8810(int a,int b,int c,u8 *p,int e);
u8 *func_021B8834(int a,u8 *p);
int func_021B884C(u32 *p);
int func_021B8880(u8 *p);
s32_021B8880 func_021B89DC(int a,u16 *p,int angle,int bank,u8 index,u16 c1,u16 c2);
void func_021B8A88(u8 *p,void *a,int b,int c,int d);
void func_021B8ADC(void *p);
void func_021B8AEC(u8 *p);
void func_021B8C3C(u8 *p, const void *a, int color);
void func_021B8D08(unsigned int *p, unsigned int a, int b);
void func_021B8D20(u8 *p);
void func_021B8DA4(Particle *p, const Point *a, const Point *b, int color, u32 lifetime);
u32 func_021B8E8C(u8 *p);
void func_021B8E90(int *p, int a1);
void func_021B8EA4(void *p);
void func_021B8EB0(u8 *p);
void func_021B8F00(void *p);
extern const u8 d_021B8F78[];
extern struct DispConfig d_021B8F30;
extern const u32 d_021B8F5C[];
extern const struct BgTemplate d_021B8FB4[];
extern const u32 d_021B8F40[];
extern const struct Cfg d_020A1448;
extern const u32 d_021B8F28[];
extern const s16 d_020A1B38[];
extern const s16 g_020A1B38[];




int func_021B7560(struct Obj0203159C *obj,void *state,u8 *context) {
 u8 *p; u32 bank; int tag; int font;
 func_0203064C(1,0x38,0x20000);
 p=func_0203159C(obj,0x8b4,0x38);
 func_02082BCC(p,0,0x8b4);
 CTX(p)=context;
 func_021B78EC(p,0x38);
 func_021B7D28((unsigned int *)(p+0xbc),0,(u32)0x38);
 if(*(void **)CTX(p)) func_02012138(*(struct Ctx **)CTX(p));
 func_021B7DF0((Rec *)(p+0xcc),5,1,18,30,5,8,0x38);
 func_0201F73C(((struct Obj07986 *)p)->fCC,0,(u16)(((struct Obj07986 *)p)->f0),6);
 func_021B8E90((int *)(p+0x7cc),0x38);
 if(*(void **)CTX(p)) func_021B8030(p+0xcc,p+0xbc,0,*(u8 **)(CTX(p)+8),0,0,0x38);
 else func_021B7F1C(p+0xcc,p+0xbc,0,0,0);
 func_021B80D4((int *)(p+0x7b0),p,0x38);
 func_021B7E58(p+0x7dc,7,6,3,20,5,8,1,1,0x38);
 func_021B7F80(p+0x7dc,p+0xbc,7);
 func_02041F6C(7,3,0x1000);
 func_02041F6C(7,6,0x1000);
 func_02041FB0(7,9,0x80);
 func_02041FB0(7,12,0x28);
 func_021B7E58(p+0x7f0,2,8,10,16,2,13,0,0,0x38);
 func_021B8724(p+0xe0,(int)(*(void **)(CTX(p)+4)));
 func_021B85D8(p+0x814);
 func_021B8A88(p+0x278,p,1,0,0);
 bank=func_021B7974(p);
 tag=func_021B7DE0(p+0xbc);
 font=func_021B7DE4(p+0xbc);
 ((struct Obj07986 *)p)->f7AC=func_021B70DC(2,bank,0,14,13,2,tag,font,0x38);
 func_021B63CC(*(int **)(CTX(p)+4),1);
 func_0207D658(0x04000050,0x22,-8);
 ((struct Obj07986 *)p)->f8A4=func_020056A0((u32)func_021B8F08,(u32)p,0);
 func_021B817C((char *)p,(u32)func_021B8198);
 return 1;
}




/*
 * volatile: 021B7784 writes the hardware register at 0x04000050.
 */
int func_021B7768(int a,int b,int c,u8 *p) {
 func_02030EAC((struct Node *)(((struct Obj13741 *)p)->f8A4));func_021B8ADC(p+0x278);
 *(volatile unsigned short *)0x04000050=0;
 func_021B71C0((void *)(((struct Obj13741 *)p)->f7AC));func_021B874C(p+0xe0);func_021B80F8(p+0x7b0);func_021B8EA4(p+0x7cc);func_021B7EC8(p+0x7f0);func_021B7EC8(p+0x7dc);func_021B7EC8(p+0xcc);func_021B7940(p);func_021B7DAC(p+0xbc);func_020315D4((struct S020315D4 *)a);func_020306F0(56);return 1;
}




/*
 * prototype: 021B7DD4 tail-forwards live r0 from u32 0201C4E4; caller reads it.
 */
int func_021B77EC(void *a,u32 *state,void *b,u8 *p) {
 switch(*state) {
 case 0: *state=1; break;
 case 1: func_0204E720(3,16,0,0); *state=2; break;
 case 2: if(!func_0204E804()) *state=3; break;
 case 3: (*(void (**)(u8 *,unsigned short *))(p+0x804))(p,(unsigned short *)(p+0x808)); if(((struct Obj07987 *)p)->f80C) *state=4; func_021B8EB0(p+0x7cc); break;
 case 4: func_0204E720(3,0,16,0); *state=5; break;
 case 5: if(!func_0204E804()) *state=6; break;
 case 6: return 1;
 }
 if(func_021B7DD4(p+0xbc)) { func_021B7EE4(p+0xcc,p+0xbc); func_021B7EE4(p+0x7dc,p+0xbc); func_021B7EE4(p+0x7f0,p+0xbc); }
 func_021B795C(p);
 func_021B8AEC(p+0x278);
 if(!((struct Obj07987 *)p)->f8AC) func_021B71E4(((struct Obj07987 *)p)->f7AC);
 func_021B63D0((struct Obj *)(*(Obj * *)&((struct Obj22214 *)(*(u8 * *)&((struct Obj07987 *)p)->f8B0))->f4));
 return 0;
}




void func_021B78EC(u8 *p,u16 a) { func_02082BCC(p,0,0xbc); BG_SYS_ClearGraphicsMemory(0); func_020433E0((const struct DispVram *)d_021B8F78); func_0204363C(0); func_0204361C(); BG_SYS_ClearMainPlanes(); func_021B7B2C((u32 *)(p+4),d_021B8F78,a); func_021B7994(p,a); ((struct Obj22215 *)p)->fB8=func_020056A0((u32)((void (*)(void *))func_021B7980), (u32)p, 0); }



/*
 * extent: two zero alignment bytes follow compiled code.
 */
void func_021B7940(u8 *p) { func_02030EAC(*(struct Node * *)&((struct Obj22216 *)p)->fB8); func_021B7AD4((u32 *)p); func_021B7CA4((void **)(p+4)); }



void func_021B795C(u8 *p) { func_021B7D0C((int)(p + 4)); }



int func_021B7968(u8 *p, int i) { return func_021B7D1C(p + 4, i); }



/*
 * Unblocked by matching func_021B7D24 in ov104 (pkt_ov104_021B7D24).
 */
u32 func_021B7974(u8 *p) { return func_021B7D24((u32 *)(p + 4)); }








void func_021B7980(u32 unused,u8 *p) { func_021B7B24(p); func_021B7D14(p+4); }








void func_021B7994(void *p,u16 heap) {
 int i; BgId bg; void *archive;
 func_0203F8F4(heap);
 func_02045088(heap);
 func_0203FC28(&d_021B8F30);
 for(i=0;i<7;i++) {
  bg=d_021B8F5C[i];
  func_0203FCA0((u8)bg,&d_021B8FB4[i],(u8)d_021B8F40[i]);
  func_020414AC(bg);
  func_02040588(bg,1);
 }
 archive=func_020490F4(0x5e,heap);
 func_02049B68((void *)((u32)archive),1,0,0,0,heap);
 func_02049B68((void *)((u32)archive),1,4,0,0,heap);
 func_02049658((void *)((u32)archive),0x24,1,0,0,0,heap);
 func_02049658((void *)((u32)archive),0,6,0,0,0,heap);
 func_02049658((void *)((u32)archive),0x30,4,0,0,0,heap);
 func_020498F4((void *)((u32)archive),0x25,1,0,0,0,heap);
 func_020498F4((void *)((u32)archive),4,6,0,0,0,heap);
 func_020498F4((void *)((u32)archive),0x2f,4,0,0,0,heap);
 func_02040C14(5,0,1,0);
 ((struct Obj22217 *)p)->f0=func_02049740((void *)((u32)archive),0x31,5,0,0,heap);
 func_02049238(archive);
 func_02049B40(0x17,5,0,0x1a0,0x20,heap);
 func_02040C14(2,0,1,0);
}








void func_021B7AD4(u32 *p) { int i; func_02040DA8(2,1,0); func_0203FB44(5,(u16)(*p),(u16)(*p>>16)); func_02040DA8(5,1,0); for(i=0;i<7;i++) func_020403F4((u8)d_021B8F5C[i]); func_020450C8(); func_0203F9B4(); }








void func_021B7B24(void *a0) { func_020419E4(); }








/*
 * prototype: ABF0 forwards AC18's index; B294 forwards CFDC's pointer live in r0.
 */
void func_021B7B2C(u32 *p,const void *config,u16 heap) {
 void *archive; int i; Desc desc;
 func_02082BCC(p,0,0xb4);
 func_0204A48C(&d_020A1448,(u32)config,heap);
 p[0]=(u32)func_0204B100(0x80,0,heap);
 CLACT_SetUnitDefaultRenderer((struct Bank *)p[0]);
 func_020434DC(0x10,1);
 func_02043598(0x10,1);
 archive=func_020490F4(0x5e,heap);
 p[1]=func_0204ABF0((void *)archive,0x23,0,0,heap);
 p[2]=func_0204A6C8((void *)((u32)archive),0x22,0,0,heap);
 p[3]=func_0204AF28((void *)((u32)archive),0x21,0x20,heap);
 p[7]=func_0204AC18((void *)((u32)archive),0xc,0,0xe0,0xc,1,heap);
 p[8]=func_0204A6C8((void *)((u32)archive),0xb,0,0,heap);
 p[9]=func_0204AF28((void *)((u32)archive),0xa,9,heap);
 p[4]=func_0204ABF0((void *)archive,0x23,1,0,heap);
 p[5]=func_0204A6C8((void *)((u32)archive),0x22,0,1,heap);
 p[6]=func_0204AF28((void *)((u32)archive),0x21,0x20,heap);
 func_02049238(archive);
 func_02082BCC(&desc,0,8);
 for(i=0;i<30;i++) {
  p[i+10]=(u32)func_0204B294((void *)p[0],p[2],p[1],p[3],&desc,0,heap);
  func_0204B3DC((struct Obj *)p[i+10],0);
  func_0204B84C((S *)p[i+10],3);
  func_0204B92C((struct Obj *)p[i+10],1);
  func_0204B878((struct Obj *)p[i+10],0);
 }
 desc.x=128; desc.y=96;
 for(i=31;i<34;i++) {
  desc.z=i-30;
  p[i+10]=(u32)func_0204B294((void *)p[0],p[8],p[7],p[9],&desc,0,heap);
  func_0204B3DC((struct Obj *)p[i+10],0);
  func_0204B6F4((struct Obj *)p[i+10],0,1);
 }
}








void func_021B7CA4(void **p) { int i; for(i=0;i<35;i++) if(p[i+10]) func_0204B3B4(p[i+10]); func_0204ADA4((u32)p[1]); func_0204A8D4((u32)p[2]); func_0204AFD8((u32)p[3]); func_0204ADA4((u32)p[4]); func_0204A8D4((u32)p[5]); func_0204AFD8((u32)p[6]); func_0204ADA4((u32)p[7]); func_0204A8D4((u32)p[8]); func_0204AFD8((u32)p[9]); func_0204B1CC(p[0]); func_0204A5AC(); func_02082BCC(p,0,0xb4); }









/*
 * Thumb long-branch veneer in a .word run:
 *   ldr r3,[pc,#0]; bx r3; .word 0x0204A600
 * Declared as an ordinary tail-call extern at the veneer address.
 */
void func_021B7D0C(int x)
{
    func_0204A600(x);
}








void func_021B7D14(void *p) { func_0204A648(); }








/*
 * Unlabelled leaf accessor, witness for the thunk func_021B7968.
 */
int func_021B7D1C(unsigned char *p, int i)
{
    return *(int *)(p + i * 4 + 0x28);
}









/*
 * First-word accessor.
 */
u32 func_021B7D24(u32 *p)
{
    return *p;
}








/*
 * func_02082BCC 0x02082BCC arm
 * func_0201DD60 0x0201DD60 thumb
 * func_0201D7EC 0x0201D7EC thumb
 * func_0201C440 0x0201C440 thumb
 * func_02045B38 0x02045B38 arm
 * func_0201EC64 0x0201EC64 thumb
 * func_02049B40 0x02049B40 arm
 */
void func_021B7D28(unsigned *p, int mode, u16 heap) {
 func_02082BCC(p,0,0x10);
 func_0201DD60();
 switch (mode) {
 case 0:
  p[0]=(unsigned int)func_0201D7EC(0x17,0,0,0,heap);
  break;
 case 1:
  p[0]=(unsigned int)func_0201D7EC(0x17,1,0,0,heap);
  break;
 }
 p[2]=func_0201C440((void *)heap);
 p[1]=(unsigned int)func_02045B38(0,2,0x34,heap);
 p[3]=(unsigned int)func_0201EC64(heap);
 func_02049B40(0x17,5,4,0x1C0,0x20,heap);
 func_02049B40(0x17,5,0,0x1C0,0x20,heap);
}








void func_021B7DAC(u8 *p) { func_0201ED04(*(struct WordSet * *)&((struct Obj07988 *)p)->fC); func_02045C04(*(struct Rec * *)&((struct Obj07988 *)p)->f4); func_0201C4C0(((struct Obj07988 *)p)->f8); func_0201D83C(((struct Obj07988 *)p)->f0); func_02082BCC(p,0,16); }








int func_021B7DD4(u8 *p) { return func_0201C4E4((struct PrintSys *)(((struct Obj22219 *)p)->f8)); }









int func_021B7DE0(void *p)
{
    return ((struct Obj22220 *)p)->f0;
}









int func_021B7DE4(void *p)
{
    return ((struct Obj22221 *)p)->f8;
}









/*
 * four int getters at +0, +8, +4, +c.
 */
int func_021B7DE8(void *p)
{
    return ((struct Obj22222 *)p)->f4;
}









int func_021B7DEC(void *p)
{
    return ((struct Obj22223 *)p)->fC;
}








void func_021B7DF0(Rec *p, u32 a, u32 b, u8 c, u8 d, u8 e, u8 f, u16 size)
{
    void *q;
    func_02082BCC(p, 0, 0x14);
    p->f10 = 15;
    p->f0 = (void *)func_020450F0(a, b, c, d, e, f, 1);
    p->fC = func_020457B0(0xff, size);
    p->f4 = p->f0;
    p->f8 = 0;
    func_021B80B8((u8 *)p);
    q = p->f0;
    func_02045334(q);
    func_02045374(q);
    func_020409B4(func_02045730(q));
}








/*
 * lever: c and its callee parameter are u8; u32 hoists its spill reload.
 */
void func_021B7E58(u8 *p,u32 a,u32 b,u8 c,u8 d,u8 e,u8 f,u16 color,u8 heap,u16 size) { void *q; func_02082BCC(p,0,0x14); ((struct Obj03233 *)p)->f10=color; ((struct Obj03233 *)p)->f0=(void *)func_020450F0(a,b,c,d,e,f,heap); ((struct Obj03233 *)p)->fC=func_020457B0(0xff,size); ((struct Obj03233 *)p)->f4=((struct Obj03233 *)p)->f0; p[8]=0; func_02043B5C(func_02045770(((struct Obj03233 *)p)->f0),((struct Obj03233 *)p)->f10); q=((struct Obj03233 *)p)->f0; func_02045334(q); func_02045374(q); func_020409B4(func_02045730(q)); }








void func_021B7EC8(u8 *p) { func_02045808(*(struct U16Vec * *)&((struct Obj13743 *)p)->fC); func_020452E8(*(struct Descriptor * *)&((struct Obj13743 *)p)->f0); func_02082BCC(p,0,20); }








int func_021B7EE4(u8 *p,u8 *q) { void *v; v=((struct Obj22224 *)q)->f8; if(p[8]) { if(!func_0201C6C4(v,func_02045770(((struct Obj06372 *)p)->f4))) { func_02045334(*(struct Descriptor * *)&((struct Obj06372 *)p)->f4); p[8]=0; } } if(!p[8]) return 1; return 0; }








void func_021B7F1C(u8 *p,void *a,int b,int x,s16 y) { int bank; int font; int tag; bank=func_021B7DE8(a); font=func_021B7DE4(a); tag=func_021B7DE0(a); func_02043B5C(func_02045770(((struct Obj05273 *)p)->f0),((struct Obj05273 *)p)->f10); func_02045CAC((struct MsgBank *)bank,b,((struct Obj05273 *)p)->fC); func_0201C6FC((struct PrintSys *)font,(u32)func_02045770(((struct Obj05273 *)p)->f4),(s16)x,y,((struct Obj05273 *)p)->fC,tag); p[8]=1; }








void func_021B7F80(u8 *p,void *a,int b) { func_021B7F90(p,a,b,0x3dc4); }








void func_021B7F90(u8 *p,void *a,int b,u16 c) { int bank; int font; int tag; u16 x; u16 y; bank=func_021B7DE8(a); font=func_021B7DE4(a); tag=func_021B7DE0(a); func_02043B5C(func_02045770(((struct Obj02812 *)p)->f0),((struct Obj02812 *)p)->f10); func_02045CAC((struct MsgBank *)bank,b,((struct Obj02812 *)p)->fC); x=func_02045738(((struct Obj02812 *)p)->f0)*4; y=func_02045740(((struct Obj02812 *)p)->f0)*4; x-=(u16)(func_0201D304(((struct Obj02812 *)p)->fC,tag,0)/2); y-=(u16)(func_0201D42C(((struct Obj02812 *)p)->fC,(void *)tag)/2); func_0201C724((void *)font,(u32)func_02045770(((struct Obj02812 *)p)->f4),(s16)x,(s16)y,(u32)(((struct Obj02812 *)p)->fC),tag,c); p[8]=1; }








void func_021B8030(u8 *p, void *a, int b, u8 *c, s16 x, s16 y, u16 a6) { int set; int bank; void *text; int font; int tag; func_02043B5C(func_02045770(((struct Obj05274 *)p)->f0),((struct Obj05274 *)p)->f10); set=func_021B7DEC(a); bank=func_021B7DE8(a); func_0201F02C((struct WordSet *)set,0,c+0xc); text=func_02045EC0((struct MsgBank *)bank,b); func_0201F250((struct WordSet *)set,((struct Obj05274 *)p)->fC,text); func_02045808(text); font=func_021B7DE4(a); tag=func_021B7DE0(a); func_0201C6FC((struct PrintSys *)font,(u32)func_02045770(((struct Obj05274 *)p)->f4),x,y,((struct Obj05274 *)p)->fC,tag); p[8]=1; }








void func_021B80B8(u8 *p) { func_02043B5C(func_02045770(((struct Obj10245 *)p)->f0),((struct Obj10245 *)p)->f10); func_02045334(((struct Obj10245 *)p)->f0); }








void func_021B80D4(int *p, u8 *q, int a2) { int i; func_02082BCC(p,0,0x1c); for(i=0;i<3;i++) *p=func_021B7968(q,i+0x1f); }








void func_021B80F8(void *p) { func_02082BCC(p, 0, 0x1c); }








void func_021B8104(u32 *p) { if(p[5]) { if(p[3]==0) { func_020061E4(0x66a); func_0204B3DC((void *)p[0],1); func_0204B878((void *)p[0],4-p[4]); } if(p[3]++>=60) { p[3]=0; p[4]++; } if(p[4]==3) { func_020061E4(0x66b); p[6]=1; p[5]=0; func_0204B3DC((void *)p[0],0); } } }








void func_021B816C(u8 *p) { ((struct Obj10246 *)p)->fC = 0; ((struct Obj10246 *)p)->f10 = 0; ((struct Obj10246 *)p)->f14 = 1; }








u32 func_021B8178(u8 *p) { return ((struct Obj22226 *)p)->f18; }







void func_021B817C(char *p, u32 v) {
    *(u32 *)(p + 0x804) = v;
    *(u16 *)(p + 0x808) = 0;
}








void func_021B818C(u8 *p) { ((struct Obj22227 *)p)->f80C = 1; }







void func_021B8198(u8 *p,u16 *state) { switch(*state) { case 0: ((struct Obj13744 *)p)->f80A=0; *state=1; break; case 1: func_02040588(2,0); *state=3; break; case 3: func_021B816C(p+0x7b0); func_021B817C((char *)p,(u32)func_021B8220); break; } if(func_021B7250(((struct Obj13744 *)p)->f7AC)==1) { *(u32 *)(CTX(p)+0xc)=1; func_021B818C(p); } if(func_021B6480(*(void **)(CTX(p)+4))!=0) func_021B817C((char *)p,(u32)func_021B8528); }







void func_021B8220(u8 *p,u16 *state) { func_021B8104((u32 *)(p+0x7b0)); if(func_021B8178(p+0x7b0)) { ((struct Obj13745 *)p)->f8A8=1; func_021B85E4(p+0x814); func_021B8F00(p+0x7cc); func_021B817C((char *)p,(u32)func_021B829C); } if(func_021B7250(((struct Obj13745 *)p)->f7AC)==1) { *(u32 *)(CTX(p)+0xc)=1; func_021B818C(p); } if(func_021B6480(*(void **)(CTX(p)+4))!=0) func_021B817C((char *)p,(u32)func_021B8528); }







/*
 * lever: Enum subblock offset and grouped offset arithmetic retain the far-field register.
 */
void func_021B829C(u8 *p,u16 *state) {
 Offset base=BASE;
 int point[2];
 *(u32 *)(p+(base+0x98))=0;
 if(!func_021B727C(*(int *)(p+(base-0x68)))) {
  if(func_021B884C((u32 *)point)) {
   func_021B8C3C(p+0x278,point,func_021B86A0(p+base));
   if(!*(u16 *)(p+(base+0x8c))) func_021B8624(p+base);
   ((struct Obj05275 *)p)->f8AC=1;
  }
 }
 if(func_021B8614(p+base)) {
  if(!((struct Obj05275 *)p)->f89C) {
   func_021B7F1C(p+0xcc,p+0xbc,1,0,0);
   func_020061E4(0x654);
   ((struct Obj05275 *)p)->f89C=1;
  }
  if(((struct Obj05275 *)p)->f89C) func_021B8384(p,(u16 *)(p+0x8a0));
 }
 if(!((struct Obj05275 *)p)->f89C) {
  if(func_021B7250(*(int * *)&((struct Obj05275 *)p)->f7AC)==1) { *(u32 *)(CTX(p)+0xc)=1; func_021B818C(p); }
  if(func_021B6480(*(int **)(CTX(p)+4))) func_021B817C((char *)p,(u32)func_021B8528);
 }
}







void func_021B8384(u8 *p,u16 *state) {
 Block_021B7980 data; int diff;
 if(*state<5 && func_021B7250(*(int * *)&((struct Obj04432 *)p)->f7AC)==1) {
  func_021B63BC(*(int **)(CTX(p)+4));
  *(u32 *)(CTX(p)+0xc)=1;
  func_021B818C(p);
  return;
 }
 switch(*state) {
 case 0: if(func_021B630C(*(int **)(CTX(p)+4),2)) *state=1; break;
 case 1: func_021B7F1C(p+0xcc,p+0xbc,2,0,0); *state=2; break;
 case 2: if(func_021B8768(p+0xe0, (const Block_021B7980 *)((Block_021B7980 *)(p+0x814)))) *state=3; break;
 case 3: func_021B63CC(*(int **)(CTX(p)+4),2); if(func_021B6424(*(int *)(CTX(p)+4))) *state=4; break;
 case 4: if(func_021B630C(*(int **)(CTX(p)+4),3)) { func_021B72A0(*(int *)&((struct Obj04432 *)p)->f7AC,0); *state=5; } break;
 case 5: if(((struct Obj04432 *)p)->f80A>=60) { func_020061E4(0x64b); func_021B7F1C(p+0xcc,p+0xbc,3,0,0); *state=6; } break;
 case 6:
  if((((struct Obj04432 *)p)->f8A2)++<30) return;
  CTX(p)[0x10]=func_021B8880(p);
  func_021B87F4(p+0xe0, (Record *)&data);
  diff=((struct Obj04432 *)p)->f88E-*(u16 *)((u8 *)&data+122);
  if(diff<0) diff=-diff;
  *(int *)(CTX(p)+0x14)=diff;
  *(int *)(CTX(p)+0xc)=0;
  *state=7; return;
 case 7: func_021B818C(p); return;
 }
 if(*state>=1 && *state<=5) { if(((struct Obj04432 *)p)->f80A<=60) ++((struct Obj04432 *)p)->f80A; }
 if(*state<3) { if(func_021B6480(*(int **)(CTX(p)+4))) func_021B817C((char *)p,(u32)func_021B8528); }
}







/*
 * extent: 174 code bytes then two zero alignment bytes before 021B85D8.
 */
void func_021B8528(u8 *p,u16 *state) { switch(*state) { case 0: if(func_021B6480(*(void **)(CTX(p)+4))>0) { CTX(p)[0x10]=0; *(u32 *)(CTX(p)+0xc)=1; func_021B818C(p); return; } if(func_021B6480(*(void **)(CTX(p)+4))<0) *state=1; break; case 1: CTX(p)[0x10]=0; *(u32 *)(CTX(p)+0xc)=2; *state=2; break; case 2: func_021B7F1C(p+0xcc,p+0xbc,4,0,0); *state=3; break; case 3: if(func_021B630C(*(void **)(CTX(p)+4),6)) *state=4; break; case 4: func_021B818C(p); break; } }







void func_021B85D8(void *p) { func_02082BCC(p, 0, 0x84); }







void func_021B85E4(u8 *p) { if(func_02087058()) func_02086FE8(); *(unsigned long long *)(p+0x7c)=(func_020870D0()<<6)/33514; }







int func_021B8614(u8 *p) { if(((struct Obj22229 *)p)->f78>=10) return 1; return 0; }







void func_021B8624(u8 *p) { if(((struct Obj01389 *)p)->f78<10) { ((Pair *)p)[((struct Obj01389 *)p)->f78].f0=(func_020870D0()<<6)/33514-*(unsigned long long *)(p+0x7c); if(((struct Obj01389 *)p)->f78==0) ((Pair *)p)[((struct Obj01389 *)p)->f78].f4=0; else ((Pair *)p)[((struct Obj01389 *)p)->f78].f4=((Pair *)p)[((struct Obj01389 *)p)->f78].f0-((Pair *)p)[((struct Obj01389 *)p)->f78-1].f0; ++((struct Obj01389 *)p)->f78; } else if(((struct Obj01389 *)p)->f7A<99) ++((struct Obj01389 *)p)->f7A; }







static inline int magnitude(int x) { return x<0 ? -x : x; }







int func_021B86A0(u8 *p) {
 int diff; int result; int sound; u16 n;
 n=((struct Obj22230 *)p)->f78;
 if(n<2) { sound=0x64c; result=3; }
 else {
  diff=*(int *)(p+(n-1)*8+4)-*(int *)(p+(n-2)*8+4);
  if(magnitude(diff)>=0 && magnitude(diff)<50) {sound=0x64c;result=3;}
  else if(diff<0) {
   if(magnitude(diff)<200) {sound=0x64f;result=1;} else {sound=0x650;result=0;}
  } else {
   if(magnitude(diff)<200) {sound=0x64d;result=5;} else {sound=0x64e;result=6;}
  }
 }
 func_020061E4(sound); return result;
}







void func_021B8724(u8 *p,int a) { func_02082BCC(p,0,0x198); ((struct Obj22231 *)p)->f0=a; func_021B64F0(a,0xf00,(int)d_021B8F28,1,(int)p); }







void func_021B874C(u8 *p) { func_021B6508(((struct Obj22232 *)p)->f0,0xf00); func_02082BCC(p,0,0x198); }







/*
 * extent: Two zero alignment bytes at 021B87F2 before 021B87F4.
 */
int func_021B8768(u8 *p,const Block_021B7980 *q) {
 switch(((struct Obj04433 *)p)->f4) {
 case 0: *(Block_021B7980 *)(p+0x110)=*q; ((struct Obj04433 *)p)->f4=1; break;
 case 1:
  if(func_021B64B8(((struct Obj04433 *)p)->f0,0xf00,0x84,(u32)(p+0x110),(u8)(func_0203D1A4((struct Link *)((int)func_020399A8()))==0),0,0,1)) ((struct Obj04433 *)p)->f4=2;
  break;
 case 2:
  if(((struct Obj04433 *)p)->f194) { ((struct Obj04433 *)p)->f194=0; ((struct Obj04433 *)p)->f4=0; return 1; }
  break;
 }
 return 0;
}






/*
 * extent: Two zero bytes of alignment padding follow the return.
 */
void func_021B87F4(u8 *p,Record *out) { *out=*(Record *)(p+8); }






void func_021B8810(int a,int b,int c,u8 *p,int e) { if(e==(int)func_020399A8() && a!=func_02039338()) ((struct Obj22233 *)p)->f194=1; }






u8 *func_021B8834(int a,u8 *p) { if(a==func_02039338()) return p+0x8c; else return p+8; }






int func_021B884C(u32 *p) { u32 x,y; if(func_02035D20(&x,&y)) { if(x<=256 && y<=168) { p[0]=x; p[1]=y; return 1; } } return 0; }





/*
 * lever: Direct word indexing retains the second stack record's base across the call.
 */
int func_021B8880(u8 *p) {
 Block_021B8880 a; Block_021B8880 b; int d; u32 score, sum; int i; Block_021B8880 *bp;
 a=*(Block_021B8880 *)(p+0x814);
 bp=&b;
 func_021B87F4(p+0xe0, (Record *)bp);
 d=a.words[(*(u16 *)((u8 *)&a+120)-1)*2]-a.words[0]
  -(b.words[(*(u16 *)((u8 *)&b+120)-1)*2]-b.words[0]);
 if(d<0) d=-d;
 if(d==0) score=100;
 else if((u32)d<500) score=90;
 else if((u32)d<1000) score=80;
 else if((u32)d<3000) score=70;
 else if((u32)d<5000) score=60;
 else if((u32)d<10000) score=50;
 else if((u32)d<15000) score=40;
 else if((u32)d<20000) score=30;
 else if((u32)d<25000) score=20;
 else if((u32)d<30000) score=10;
 sum=0;
 for(i=1;i<10;i++) {
  d=*(int *)((u32)&a+i*8+4)-*(int *)((u32)&b+i*8+4);
  if(d<0) d=-d;
  if(d==0) sum+=100;
  else if((u32)d<50) sum+=90;
  else if((u32)d<100) sum+=80;
  else if((u32)d<200) sum+=70;
  else if((u32)d<300) sum+=60;
  else if((u32)d<400) sum+=50;
  else if((u32)d<500) sum+=40;
  else if((u32)d<600) sum+=30;
  else if((u32)d<1000) sum+=20;
  else if((u32)d<15000) sum+=10;
 }
 return (u8)((score+sum/9)/2);
}





static inline u16 blend(int angle,u16 c1,u16 c2) {
 u8 g1,r1,b1; int db,dr,dg; s16 factor;
 g1=(c1&0x3e0)>>5;
 factor=(s16)((d_020A1B38[((angle>>4)*2)+1]+0x1000)/2);
 r1=c1&31;
 b1=(c1&0x7c00)>>10;
 db=(factor*((u8)((c2&0x7c00)>>10)-b1))>>12;
 dr=(factor*((u8)(c2&31)-r1))>>12;
 dg=(factor*((u8)((c2&0x3e0)>>5)-g1))>>12;
 return ((u8)(b1+db)<<10)|((u8)(r1+dr)|((u8)(g1+dg)<<5));
}





/*
 * lever: Byte RGB endpoints and named signed db/dr/dg deltas, with the
 * cosine factor computed after green extraction, retain channel lifetimes.
 * Evidence: ov105_func_021B8734 blend spelling and own ARM9 queue body.
 */
s32_021B8880 func_021B89DC(int a,u16 *p,int angle,int bank,u8 index,u16 c1,u16 c2) {
 *p=blend(angle,c1,c2);
 return func_02061CA4((void *)a,bank*32+index*2,(u32)p,2);
}





void func_021B8A88(u8 *p,void *a,int b,int c,int d) {
 int i;
 func_02082BCC(p,0,0x534); ((struct Obj10248 *)p)->f528=b;
 ((struct Obj10248 *)p)->f52C=0; ((struct Obj10248 *)p)->f530=10;
 for(i=0;i<30;i++) func_021B8D08((unsigned int *)(p+i*0x2c),(unsigned int)((void *)func_021B7968(a,c+i)),d);
}





void func_021B8ADC(void *p) { func_02082BCC(p,0,0x534); }





static inline void initialize(Point *start,Point *end,int x,EndY endY)
{
    int yy=endY;
    end->y=yy;
    start->x=end->x=x;
    start->y=228;

}





/*
 * lever: named end-Y local stored before the shared X assignment yields the original 336-byte schedule.
 */
void func_021B8AEC(u8 *p)
{
    Point end,start;
    int i,offset,angle;
    u32 life;
    Color color;
    u8 direction;
    switch(W(0x528)) {
    case 0:
        if(W(0x52c)++>W(0x530)) {
            W(0x52c)=0;
            for(i=0;i<30;++i) {
                offset=i*44;
                if(!func_021B8E8C(p+offset)) {
                    direction=func_020056EC(2);
                    initialize(&start,&end,func_020056EC(256),-36);
                    life=func_020056EC(50)+110;
                    color=2;
                    if(func_020056EC(2)) color=5;
                    if(direction) func_021B8DA4((Particle *)(p+offset), (const Point *)&start, (const Point *)&end, color, life);
                    else func_021B8DA4((Particle *)(p+offset), (const Point *)&end, (const Point *)&start, color, life);
                    break;
                }
            }
        }
        break;
    case 1: break;
    case 2:
        if(W(0x52c)++>W(0x530)) {
            W(0x52c)=0;
            for(i=0;i<30;++i) {
                offset=i*44;
                if(!func_021B8E8C(p+offset)) {
                    angle=(u16)func_020056EC(65535)>>4;
                    end.x=SHIFT(g_020A1B38[angle*2],8)>>12;
                    end.y=SHIFT(g_020A1B38[angle*2+1],8)>>12;
                    start.x=128;start.y=96;
                    life=func_020056EC(50)+110;
                    color=2;
                    if(func_020056EC(2)) color=5;
                    func_021B8DA4((Particle *)(p+offset), (const Point *)&end, (const Point *)&start, color, life);
                    break;
                }
            }
        }
        break;
    }
    for(i=0;i<30;++i) func_021B8D20(p+i*44);
}




void func_021B8C3C(u8 *p, const void *a, int color)
{
    Vec origin, random, delta;
    Point end;
    int outer, i, offset, angle, tmp, rawY;
    origin.x=SHIFT(((const Point *)a)->x,12);
    origin.y=SHIFT(((const Point *)a)->y,12);
    origin.z=0;
    for(outer=0;outer<12;++outer) {
        for(i=0;i<30;++i) {
            tmp=i*44;
            offset=tmp;
            if(!func_021B8E8C(p+offset)) {
                angle=(u16)func_020056EC(65535)>>4;
                end.x=SHIFT(g_020A1B38[angle*2],8)>>12;
                end.y=SHIFT(g_020A1B38[angle*2+1],8)>>12;
                random.x=SHIFT(end.x,12);
                random.y=SHIFT(end.y,12);
                random.z=0;
                func_0207CA00(&random,&origin,&delta);
                func_0207CCA4(&delta,&delta);
                rawY=delta.y;
                end.x=SHIFT(delta.x,8)>>12;
                end.y=SHIFT(rawY,8)>>12;
                end.x=(int)((u32)end.x+(u32)((const Point *)a)->x);
                end.y=(int)((u32)end.y+(u32)((const Point *)a)->y);
                func_021B8DA4((Particle *)(p+offset), (const Point *)a, (const Point *)&end, color, func_020056EC(5)+40);
                break;
            }
        }
    }
}




void func_021B8D08(unsigned int *p, unsigned int a, int b) { func_02082BCC(p,0,44); p[0]=a; p[1]=b; }




/*
 * extent: Two zero alignment bytes at 021B8DA2 before 021B8DA4.
 * lever: Declare delta before pos; multiply length by counter in that order.
 */
void func_021B8D20(u8 *p) {
 u16 xy[2]; Vec delta; Vec pos; int length;
 if(((struct Obj02453 *)p)->f8) {
  func_0207CA00((Vec *)(p+0x18),(Vec *)(p+0xc),&delta);
  length=func_0207CBD0(&delta); func_0207CCA4(&delta,&delta);
  func_0207CEE4((u32)(length * ((struct Obj02453 *)p)->f24)/ ((struct Obj02453 *)p)->f28,&delta,(Vec *)(p+0xc),&pos);
  xy[0]=pos.x>>12; xy[1]=pos.y>>12;
  if((((struct Obj02453 *)p)->f24)++ > ((struct Obj02453 *)p)->f28) {
   xy[0]=((struct Obj02453 *)p)->f18; xy[1]=((struct Obj02453 *)p)->f1C;
   func_0204B3DC(((struct Obj02453 *)p)->f0,0); ((struct Obj02453 *)p)->f8=0;
  }
  func_0204B404(((struct Obj02453 *)p)->f0,(const struct Vec2 *)xy,(u16)(((struct Obj02453 *)p)->f4));
 }
}




static inline int convert(int v)
{
    float f;
    if (v > 0)
        f = _fadd(0.5f, _fflt((int)((u32)v << 12)));
    else
        f = _fsub(_fflt((int)((u32)v << 12)), 0.5f);
    return _ffix(f);
}




/*
 * Evidence: 44-byte particle layout from ov104_func_021B8D20; float
 * runtime identities from matched CLACT_ApplyActorTransform; object callees from
 * their own matched units. Unsigned shifts preserve 32-bit wrapping;
 * explicit runtime conversion retains all signed input values.
 */
void func_021B8DA4(Particle *p, const Point *a, const Point *b, int color, u32 lifetime)
{
    int sy, ey;
    p->active = 1;
    sy = convert(a->y);
    p->sx = convert(a->x);
    p->sz = 0;
    p->sy = sy;
    ey = convert(b->y);
    p->ex = convert(b->x);
    p->ez = 0;
    p->counter = 0;
    p->lifetime = lifetime;
    p->ey = ey;
    func_0204B3DC(p->object, 1);
    func_0204B6F4(p->object, (u8)color, 1);
}





u32 func_021B8E8C(u8 *p) { return ((struct Obj22235 *)p)->f8; }





void func_021B8E90(int *p, int a1)
{
    func_02082BCC(p, 0, 16);
    p[1] = 1;
}




void func_021B8EA4(void *p) { func_02082BCC(p, 0, 0x10); }




void func_021B8EB0(u8 *p) {
 int a;
 if(((struct Obj04434 *)p)->fC && ((struct Obj04434 *)p)->f4) {
  a=((struct Obj04434 *)p)->f2+0x400;
  if(a>=0x10000) ((struct Obj04434 *)p)->f2=((struct Obj04434 *)p)->f2-0xfc00;
  else ((struct Obj04434 *)p)->f2=a;
  func_021B89DC(15,(u16 *)p,((struct Obj04434 *)p)->f2,5,3,0x6adf,0x55fe);
 }
}





void func_021B8F00(void *p)
{
    ((struct Obj22236 *)p)->fC = 1;
}
