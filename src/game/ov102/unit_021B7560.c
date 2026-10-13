/*
 * file:     unit_021B7560.c
 * unit:     yes
 * function: func_021B7560, func_021B7734, func_021B7798, func_021B7860, func_021B78D0, func_021B78E4, func_021B78EC, func_021B78F4, func_021B78FC, func_021B7908, func_021B7A60, func_021B7AAC, func_021B7AB4, func_021B7BC0, func_021B7C04, func_021B7C0C, func_021B7C14, func_021B7C1C, func_021B7C20, func_021B7C88, func_021B7CB0, func_021B7CBC, func_021B7CC0, func_021B7CC4, func_021B7CC8, func_021B7D38, func_021B7DA8, func_021B7DC4, func_021B7DFC, func_021B7E60, func_021B7F08, func_021B7F18, func_021B7F24, func_021B81B0, func_021B82DC, func_021B8320, func_021B838C, func_021B83E0, func_021B842C, func_021B8464, func_021B85F4, func_021B8624, func_021B86F8, func_021B86FC, func_021B870C, func_021B8724, func_021B8794, func_021B879C, func_021B87BC, func_021B87C8, func_021B87FC, func_021B8810, func_021B8868, func_021B8874, func_021B88F8, func_021B8934, func_021B89B8, func_021B89F0, func_021B8A40
 * address:  0x021B7560
 * region:   ov102
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
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_020070A4 0x020070A4 thumb
 *   func_0200A8A0 0x0200A8A0 thumb
 *   func_021B70DC 0x021B70DC thumb ov101
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   func_021B63CC 0x021B63CC thumb ov101
 *   d_021B8AD4 0x021B8AD4 data a4
 *   func_021B71C0 0x021B71C0 thumb ov101
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_0204B92C 0x0204B92C arm
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020433E0 0x020433E0 arm
 *   func_020056A0 0x020056A0 thumb
 *   d_021B8B2C 0x021B8B2C data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_0204A600 0x0204A600 arm
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
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_021B7250 0x021B7250 thumb ov101
 *   func_021B7264 0x021B7264 thumb ov101
 *   func_021B72A0 0x021B72A0 thumb ov101
 *   func_021B72A8 0x021B72A8 thumb ov101
 *   func_021B63BC 0x021B63BC thumb ov101
 *   func_021B6150 0x021B6150 thumb ov101
 *   func_021B6254 0x021B6254 thumb ov101
 *   func_021B62AC 0x021B62AC thumb ov101
 *   func_021B6568 0x021B6568 thumb ov101
 *   func_021B657C 0x021B657C thumb ov101
 *   func_021B630C 0x021B630C thumb ov101
 *   func_021B6518 0x021B6518 thumb ov101
 *   func_021B652C 0x021B652C thumb ov101
 *   func_021B6540 0x021B6540 thumb ov101
 *   func_021B6554 0x021B6554 thumb ov101
 *   func_021B6424 0x021B6424 thumb ov101
 *   func_021B6480 0x021B6480 thumb ov101
 *   func_020061E4 0x020061E4 thumb
 *   func_0200ED48 0x0200ED48 thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200ED54 0x0200ED54 thumb
 *   func_020870D0 0x020870D0 arm
 *   func_0209C2B0 0x0209C2B0 arm
 *   func_021B7254 0x021B7254 thumb ov101
 *   func_021B63C4 0x021B63C4 thumb ov101
 *   func_021B61E8 0x021B61E8 thumb ov101
 *   func_021B62FC 0x021B62FC thumb ov101
 *   func_021B71E4 0x021B71E4 thumb ov101
 *   func_02051B84 0x02051B84 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02051C6C 0x02051C6C arm
 *   func_020413B0 0x020413B0 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_021B8A90 0x021B8A90 thumb ov102
 *   func_0204B878  0x0204B878  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_02005728  0x02005728  thumb
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_0200A8AC  0x0200A8AC  thumb
 *   func_0200A8F8  0x0200A8F8  thumb
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020419E4 0x020419E4 arm
 *   d_021B8AEC 0x021B8AEC data a4
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B84C 0x0204B84C arm
 *   d_020A1448 0x020A1448 data a4
 *   d_021B8AC4 0x021B8AC4 data a4
 *   d_021B8B5C 0x021B8B5C data a4
 *   d_021B8B0C 0x021B8B0C data a4
 */
#include "../../matched/include/Obj03229.h"
#include "../../matched/include/Obj22136.h"
#include "../../matched/include/Obj22137.h"
#include "../../matched/include/Obj22138.h"
#include "../../matched/include/Obj22139.h"
#include "../../matched/include/Obj22140.h"
#include "../../matched/include/Obj22141.h"
#include "../../matched/include/Obj07973.h"
#include "../../matched/include/Obj07975.h"
#include "../../matched/include/Obj22143.h"
#include "../../matched/include/Obj22144.h"
#include "../../matched/include/Obj22145.h"
#include "../../matched/include/Obj22146.h"
#include "../../matched/include/Obj03230.h"
#include "../../matched/include/Obj13726.h"
#include "../../matched/include/Obj06365.h"
#include "../../matched/include/Obj22147.h"
#include "../../matched/include/Obj05269.h"
#include "../../matched/include/Obj02809.h"
#include "../../matched/include/Obj13727.h"
#include "../../matched/include/Obj22148.h"
#include "../../matched/include/Obj01917.h"
#include "../../matched/include/Obj22149.h"
#include "../../matched/include/Obj22150.h"
#include "../../matched/include/Obj10235.h"
#include "../../matched/include/Obj22151.h"
#include "../../matched/include/Obj10237.h"
#include "../../matched/include/Obj22152.h"
#include "../../matched/include/Obj22153.h"
#include "../../matched/include/Obj22154.h"
#include "../../matched/include/Obj07976.h"
#include "../../matched/include/Obj22155.h"
#include "../../matched/include/Obj22156.h"
#include "../../matched/include/Obj22157.h"
#include "../../matched/include/Obj22158.h"
#include "../../matched/include/Obj07977.h"
#include "../../matched/include/Obj22159.h"
#include "../../matched/include/Obj22160.h"
#include "../../matched/include/Obj22161.h"
#include "../../matched/include/Obj22162.h"
#include "../../matched/include/Obj22163.h"
#include "../../matched/include/Obj13728.h"
#include "../../matched/include/Obj22165.h"
#include "../../matched/include/Obj13729.h"
#include "../../matched/include/Obj07978.h"
#include "../../matched/include/Obj22167.h"
#include "../../matched/include/Obj07980.h"
#include "../../matched/include/Obj04424.h"
#include "../../matched/include/Obj22169.h"
#include "../../matched/include/Obj05270.h"

#define W(k) (*(u32 *)(p+(k)))
#define H(k) (*(u16 *)(p+(k)))
#define O ((u8 *)W(0x48c))
#define C (*(void **)(O+4))
struct Obj0203159C;
struct Big;
struct Ctx;
struct Sub02007084Ctrl;
struct Row;
struct State;
struct S020315D4;
struct Obj;
struct DispVram;
struct Node;
struct BgTemplate;
struct DispConfig;
struct Cfg;
struct Bank;
struct GfFont;
struct MsgBank;
struct WordSet;
struct Rec;
struct PrintSys;
struct CharBuf;
struct Descriptor;
struct U16Vec;
struct StrObj;
struct L0200ED54;
struct R;
struct Sub0200852CObj;
struct Struct021B8A90;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef signed char s8;

typedef int s32;

struct State { void *bank; u32 palette, chars, other; void *actors[32]; };

typedef struct {
    u32 win;     /* +0x00 */
    u32 win2;    /* +0x04 */
    u8  f8;      /* +0x08 */
    u8  pad9[3];
    u32 que;     /* +0x0C */
    u16 chr;     /* +0x10 */
} Rec;

typedef short s16_021B81B0;

typedef signed short s16_021B8464;

typedef struct Pair { int object; u16 heap,pad; } Pair;

typedef struct Row_021B81B0 { u16 id,x,y,w,h,color; } Row_021B81B0;

typedef struct State_021B81B0 { void *bank; u32 windows[4]; u8 bounds[20]; const Row_021B81B0 *rows; u16 count,bg,index,done,state,ticks; u32 enable; } State_021B81B0;

typedef struct { u16 tag,x,y,w,h,pad; } Row_021B85F4;

typedef struct {
    struct Ctx *ctx;
    u8 pad04[0x28-4];
    u8 *rows;
    u16 count, pad2e, index, done, phase, timer;
    u32 enabled;
} State_021B85F4;

typedef int s32_021B8868;

typedef signed int     s32_021B8934;

extern void func_0203064C(u32 src,u32 dst,u32 size);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,u32);
extern u32 func_02012138(const struct Ctx *p);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02041F6C(u32 which, u32 op, u32 value);
extern void func_02041FB0(u32,u32,u16);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02007084Ctrl *func_020070A4(void);
extern void *func_0200A8A0(void *);
extern void *func_021B70DC(u32,u32,u16,u16,u8,u32,u32,u32,u16);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void func_021B63CC(int *,int);
extern void func_021B71C0(void *p);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned);
extern void func_0204E720(u32, int, int, int);
extern int func_0204E804(void);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void GFL_USE_CancelChangeAndPlayBgm(u32, u16);
extern void BG_SYS_ClearGraphicsMemory(unsigned);
extern void func_0204363C(unsigned);
extern void func_0204361C(void);
extern void func_020433E0(const struct DispVram *c);
extern unsigned func_020056A0(void (*)(unsigned,void *),void *,unsigned);
extern void func_02030EAC(struct Node *);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_02040C14(u32,u32,u32,u32);
extern u32 func_02049740(void *,u32,u32,u32,u32,u16);
extern void func_02049238(void *);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02040DA8(unsigned,unsigned,unsigned);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void func_020434DC(u32,u32);
extern void func_02043598(u32,u32);
extern int func_0204ABF0(void *,u32,u32,u32,u16);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern struct Obj *func_0204B294(void *,u32,u32,u32,const void *,u16,u16);
extern void func_0204B3DC(struct Obj *,unsigned int);
extern void func_0204B84C(void *,u32);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(unsigned);
extern void func_0204A8D4(unsigned);
extern void func_0204AFD8(unsigned);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_0201DD60(void);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_02049B40(unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void func_0201ED04(void *);
extern void func_02045C04(struct Rec *);
extern void func_0201C4C0(unsigned);
extern void func_0201D83C(void *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_02045808(struct U16Vec *);
extern void func_020452E8(struct Descriptor *);
extern int func_0201C6C4(int,int);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern int func_021B7250(int *p);
extern void func_021B7264(int p);
extern void func_021B72A0(int p, int b);
extern void func_021B72A8(unsigned *p, unsigned b);
extern void func_021B63BC(int *p);
extern int func_021B6150(struct Obj *p);
extern int func_021B6254(int *p);
extern int func_021B62AC(int *p);
extern int func_021B630C(int *p, int value);
extern int func_021B6568(int *p, int resource);
extern int func_021B6518(u32 p, u32 a, u32 b);
extern void func_021B657C(int *p, struct R *out);
extern int func_021B652C(u32 p);
extern int func_021B6540(u32 p);
extern int func_021B6554(int *p);
extern int func_021B6424(int p);
extern int func_021B6480(int *p);
extern void func_020061E4(u32 a);
extern void *func_0200ED48(void *);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
extern unsigned long long func_020870D0(void);
extern u32 func_0209C2B0(u32,u32);
extern int func_021B7254(int *p);
extern void func_021B63C4(int *);
extern int func_021B61E8(struct Obj *o);
extern int func_021B62FC(int *);
extern void func_021B71E4(int);
extern void *func_02051B84(u8 *,int,int,int);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201DD78(u32,u32,u32);
extern void func_0201C7A4(void *x, s16_021B8464 y, s16_021B8464 z, void *s, void *w);
extern void func_0201DD68(void);
extern void func_02051C6C(void *);
extern int func_02051C88(struct Ctx *);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041EE4(u32,u32,u32);
extern int func_021B8A90(struct Struct021B8A90 *p);
extern void func_0204B878(int p, int a);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u32 func_02005728(u32 range);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern s32_021B8934 func_0200A8AC(struct Rec *r);
extern u32 func_0200A8F8(struct Rec *r, u32 index);
int func_021B7560(void *owner,int unused,void *arg);
int func_021B7734(unsigned a,int b,int c,char *p);
int func_021B7798(void *unused, u32 *state, int unused2, char *p);
void func_021B7860(char *p,u16 b);
void func_021B78D0(void *p);
void func_021B78E4(void *p);
u32 func_021B78EC(void *p, int i);
unsigned func_021B78F4(unsigned *p);
void func_021B78FC(unsigned a,void *p);
void func_021B7908(u32 *p,u16 heap);
void func_021B7A60(unsigned *p);
void func_021B7AAC(unsigned a,void *p);
void func_021B7AB4(struct State *p,const void *config,u16 heap);
void func_021B7BC0(void *p);
void func_021B7C04(void);
void func_021B7C0C(void *p);
u32 func_021B7C14(u8 *p, int i);
unsigned func_021B7C1C(unsigned *p);
void func_021B7C20(unsigned *p,u16 heap);
void func_021B7C88(void *p);
void func_021B7CB0(u8 *p);
int func_021B7CBC(void *p);
int func_021B7CC0(void *p);
int func_021B7CC4(void *p);
void func_021B7CC8(Rec *p, int a, int b, u8 c, u8 d, u8 e, u8 f, u16 heap);
void func_021B7D38(u8 *p, int a, int b, u8 c, u8 d, u8 e, u8 f, u16 g, u8 h, u16 heap);
void func_021B7DA8(void *p);
int func_021B7DC4(unsigned char *p,unsigned char *q);
void func_021B7DFC(u8 *p, void *q, int n, int x, s16 y);
void func_021B7E60(u8 *p, void *q, int n);
void func_021B7F08(unsigned p,unsigned x);
void func_021B7F18(u8 *p);
void func_021B7F24(u8 *p,u16 *state);
void func_021B81B0(u8 *p,u16 *state);
void func_021B82DC(u8 *p, u16 *state);
void func_021B8320(u8 *p, u16 *state);
void func_021B838C(u8 *p, u16 *state);
void func_021B83E0(u8 *p);
void func_021B842C(unsigned char *p);
void func_021B8464(State_021B81B0 *p, int bg, const Row_021B81B0 *rows, int count, void *object, u16 heap);
void func_021B85F4(u8 *p);
void func_021B8624(State_021B85F4 *p);
void func_021B86F8(u8 *p, u32 v);
int func_021B86FC(u8 *p);
int func_021B870C(u8 *p, int *out);
void func_021B8724(u8 *p);
void func_021B8794(u16 value, int flag, u8 *p);
void func_021B879C(void *p, u32 a1);
void func_021B87BC(void *p);
void func_021B87C8(u8 *p);
void func_021B87FC(int *p);
void func_021B8810(int a0, int b, int c, int a3);
void func_021B8868(void *p);
void func_021B8874(u32 *p);
void func_021B88F8(int *p);
void func_021B8934(u8 *a, void *b, void *c, int d);
void func_021B89B8(u8 *p);
void func_021B89F0(u8 *p);
void func_021B8A40(int *p, int a, int b, int n);
extern u32 d_021B8AD4[];
extern unsigned d_021B8B2C[];
extern u32 d_021B8AC4[], d_021B8AEC[], d_021B8B0C[];
extern const u32 d_021B8B5C[][8];
extern unsigned d_021B8AEC[];
extern char d_020A1448[];





int func_021B7560(void *owner,int unused,void *arg)
{
    u8 *p;
    void *save;
    u32 handle;
    int first,second;
    func_0203064C(1,59,0x40000);
    p=func_0203159C(owner,0x4a4,59);
    func_02082BCC(p,0,0x4a4);
    ((struct Obj03229 *)p)->f48C=arg;
    func_021B7C20((u32 *)(p+0x9c),59);
    func_021B7860((char *)p,59);
    func_021B7908((u32 *)(p+0x94),59);
    if(**(void ** *)&((struct Obj03229 *)p)->f48C) func_02012138(**(void ** *)&((struct Obj03229 *)p)->f48C);
    func_021B8464((State_021B81B0 *)(p+0xc0),2,(const Row_021B81B0 *)d_021B8AD4,2,p+0x9c,59);
    func_021B7CC8((Rec *)(p+0xac),5,1,18,30,5,8,59);
    func_0201F73C(((struct Obj03229 *)p)->fAC,0,(u16)(((struct Obj03229 *)p)->f94),6);
    func_021B7DFC(p+0xac,p+0x9c,5,0,0);
    func_021B7D38(p+0x46c,7,6,3,20,5,8,1,1,59);
    func_021B7E60(p+0x46c,p+0x9c,10);
    func_02041F6C(7,3,0x1000);
    func_02041F6C(7,6,0x1000);
    func_02041FB0(7,9,128);
    func_02041FB0(7,12,40);
    func_021B879C(p+0xfc,59);
    save=**(void ** *)&((struct Obj03229 *)p)->f48C;
    if(save) save=func_02012EBC(func_020120F4(save));
    else save=func_020070A4();
    func_021B8934((u8 *)((int)(p+0x118)),(void *)((int)p),(void *)((int)func_0200A8A0(save)),59);
    handle=func_021B78F4((unsigned int *)p);
    first=func_021B7CBC(p+0x9c);
    second=func_021B7CC0(p+0x9c);
    ((struct Obj03229 *)p)->f468=func_021B70DC(2,handle,0,14,0,2,first,second,59);
    switch(((struct Obj22136 *)(*(u8 * *)&((struct Obj03229 *)p)->f48C))->f8) {
    case 0: func_021B7F08((unsigned int)p,(unsigned int)func_021B81B0); break;
    case 1: func_021B7F08((unsigned int)p,(unsigned int)func_021B8320); break;
    case 2: func_021B7F08((unsigned int)p,(unsigned int)func_021B81B0); break;
    }
    GFL_USE_CancelChangeAndStopBgm();
    func_021B63CC(*(int * *)&((struct Obj22137 *)(*(u8 * *)&((struct Obj03229 *)p)->f48C))->f4,0);
    return 1;
}





/*
 * func_021B71C0 0x021B71C0 thumb ov101
 * func_021B89B8 0x021B89B8 thumb ov102
 * func_021B87BC 0x021B87BC thumb ov102
 * func_021B85F4 0x021B85F4 thumb ov102
 * func_021B7DA8 0x021B7DA8 thumb ov102
 * func_021B7A60 0x021B7A60 thumb ov102
 * func_021B78D0 0x021B78D0 thumb ov102
 * func_021B7C88 0x021B7C88 thumb ov102
 * func_020315D4 0x020315D4 arm
 * func_020306F0 0x020306F0 arm
 */
int func_021B7734(unsigned a,int b,int c,char *p) {
 func_021B71C0((void *)(((struct Obj22138 *)p)->f468));
 func_021B89B8((u8 *)(p+0x118));
 func_021B87BC(p+0xfc);
 func_021B85F4((u8 *)(p+0xc0));
 func_021B7DA8(p+0x46c);
 func_021B7DA8(p+0xac);
 func_021B7A60((unsigned int *)(p+0x94));
 func_021B78D0(p);
 func_021B7C88(p+0x9c);
 func_020315D4((struct S020315D4 *)a);
 func_020306F0(0x3b);
 return 1;
}




int func_021B7798(void *unused, u32 *state, int unused2, char *p)
{
    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        func_0204E720(3, 16, 0, 0);
        *state = 2;
        break;
    case 2:
        if (func_0204E804() == 0) {
            func_0204B92C((void *)func_021B78EC(p, 31), 1);
            func_021B87FC((int *)(p + 0xfc));
            GFL_USE_CancelChangeAndPlayBgm(0x52a, 0xffff);
            *state = 3;
        }
        break;
    case 3:
        func_021B89F0((u8 *)(p + 0x118));
        func_021B87C8((u8 *)(p + 0xfc));
        (*(void (**)(char *, char *))(p + 0x480))(p, p + 0x484);
        if (((struct Obj22139 *)p)->f488 != 0) *state = 4;
        break;
    case 4:
        func_0204E720(3, 0, 16, 0);
        *state = 5;
        break;
    case 5:
        if (func_0204E804() == 0) *state = 6;
        break;
    case 6:
        return 1;
    }
    func_021B842C((unsigned char *)p);
    return 0;
}



/*
 * volatile: 0x021B787A and 0x021B7884 read display registers for update.
 * func_02082BCC 0x02082BCC arm
 * BG_SYS_ClearGraphicsMemory 0x0204335C arm
 * func_0204363C 0x0204363C arm
 * func_0204361C 0x0204361C arm
 * func_020433E0 0x020433E0 arm
 * func_021B7AB4 0x021B7AB4 thumb ov102
 * func_021B78FC 0x021B78FC thumb ov102
 * func_020056A0 0x020056A0 thumb
 * d_021B8B2C 0x021B8B2C data a4
 */
void func_021B7860(char *p,u16 b) {
 func_02082BCC(p,0,0x94);
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 *(volatile unsigned *)0x04000000 &= ~0xe000;
 *(volatile unsigned *)0x04001000 &= ~0xe000;
 BG_SYS_ClearGraphicsMemory(0);
 func_0204363C(0);
 func_0204361C();
 func_020433E0((const struct DispVram *)d_021B8B2C);
 func_021B7AB4((struct State *)p,d_021B8B2C,b);
 ((struct Obj22140 *)p)->f90=func_020056A0(func_021B78FC,p,0);
}



void func_021B78D0(void *p) { func_02030EAC(*(struct Node * *)&((struct Obj22141 *)p)->f90); func_021B7BC0(p); }



/*
 * evidence: func_021B7C04 is ov102's own code ("ldr r3, =0x0204A600; bx r3"
 * after the pop at 0x021B7C00), inside ov102's window, so only ov102 can be
 * resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference;
 * it attests as sole-ref/code from ov102's own listing.  The old hint ov021
 * named a different overlay's function mapped over the same address.
 */
void func_021B78E4(void *p) { func_021B7C04(); }








u32 func_021B78EC(void *p, int i) { return func_021B7C14(p, i); }








unsigned func_021B78F4(unsigned *p) { return func_021B7C1C(p); }








/*
 * func_021B7C0C 0x021B7C0C thumb ov102
 */
void func_021B78FC(unsigned a,void *p) { func_021B7C0C(p); }








void func_021B7908(u32 *p,u16 heap)
{
    int i;
    u32 layer;
    void *arc;
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)d_021B8AC4);
    for(i=0;i<8;i++) {
        layer=d_021B8AEC[i];
        func_0203FCA0((u8)layer,(const struct BgTemplate *)d_021B8B5C[i],(u8)d_021B8B0C[i]);
        func_020414AC(layer);
        func_02040588(layer,1);
    }
    arc=func_020490F4(94,heap);
    func_02049B68(arc,1,0,0,0,heap);
    func_02049B68(arc,1,4,0,0,heap);
    func_02049658(arc,0,3,0,0,0,heap);
    func_02049658(arc,0,6,0,0,0,heap);
    func_02049658(arc,48,4,0,0,0,heap);
    func_02049658(arc,42,2,0,0,0,heap);
    func_020498F4(arc,4,3,0,0,0,heap);
    func_020498F4(arc,4,6,0,0,0,heap);
    func_020498F4(arc,44,4,0,0,0,heap);
    func_020498F4(arc,43,2,0,0,0,heap);
    func_02040C14(5,0,1,0);
    p[0]=func_02049740(arc,49,5,0,0,heap);
    func_02049238(arc);
    p[1]=func_020056A0(func_021B7AAC,p,0);
}








/*
 * note: Packed word supplies low/high halfwords, not duplicate low halves. Includes tail-call follower 021B7AAC.
 */
void func_021B7A60(unsigned *p) {
 int i;
 unsigned q;
 func_02030EAC((struct Node *)p[1]);
 q=p[0];
 func_0203FB44(5,(u16)q,(u16)(q>>16));
 func_02040DA8(5,1,0);
 for(i=0;i<8;i++) func_020403F4((u8)d_021B8AEC[i]);
 func_020450C8();
 func_0203F9B4();
}








void func_021B7AAC(unsigned a,void *p) { func_020419E4(); }








/*
 * declaration: 0204ABF0 forwards the live result of int-returning 0204AC18; 0204B294 forwards the pointer result of 0204CFDC. Its fifth word is copied unchanged as 0204CFDC's request pointer.
 */
void func_021B7AB4(struct State *p,const void *config,u16 heap)
{
    void *arc;
    int i;
    u16 point[4];
    func_02082BCC(p,0,0x90);
    func_0204A48C((const struct Cfg *)d_020A1448,(u32)config,heap);
    p->bank=func_0204B100(128,0,heap);
    CLACT_SetUnitDefaultRenderer(p->bank);
    func_020434DC(16,1);
    func_02043598(16,1);
    arc=func_020490F4(94,heap);
    p->palette=func_0204ABF0(arc,12,1,0,heap);
    p->chars=func_0204A6C8(arc,11,0,1,heap);
    p->other=func_0204AF28(arc,10,9,heap);
    func_02049238(arc);
    func_02082BCC(point,0,8);
    for(i=0;i<30;i++) {
        p->actors[i]=func_0204B294(p->bank,p->chars,p->palette,p->other,point,1,heap);
        func_0204B3DC(p->actors[i],0);
        func_0204B84C(p->actors[i],3);
        func_0204B92C(p->actors[i],1);
    }
    point[0]=129; point[1]=104; point[2]=15;
    p->actors[31]=func_0204B294(p->bank,p->chars,p->palette,p->other,point,1,heap);
    func_0204B3DC(p->actors[31],1);
    func_0204B84C(p->actors[31],2);
    func_0204B92C(p->actors[31],0);
}








void func_021B7BC0(void *p) {
 int i;
 for(i=0;i<32;i++) {
  if(*(void **)((char *)p+16+i*4)) func_0204B3B4(*(void **)((char *)p+16+i*4));
 }
 func_0204ADA4(((struct Obj07973 *)p)->f4);
 func_0204A8D4(((struct Obj07973 *)p)->f8);
 func_0204AFD8(((struct Obj07973 *)p)->fC);
 func_0204B1CC(((struct Obj07973 *)p)->f0);
 func_0204A5AC();
 func_02082BCC(p,0,0x90);
}








 void func_021B7C04(void) { func_0204A600(); }








void func_021B7C0C(void *p) { func_0204A648(); }









u32 func_021B7C14(u8 *p, int i)
{
    return *(u32 *)(p + i * 4 + 0x10);
}








unsigned func_021B7C1C(unsigned *p) { return *p; }








void func_021B7C20(unsigned *p,u16 heap) {
 func_02082BCC(p,0,0x10);
 func_0201DD60();
 p[0]=(unsigned int)func_0201D7EC(0x17,0,0,0,heap);
 p[2]=func_0201C440((void *)heap);
 p[1]=(unsigned int)func_02045B38(0,2,0x31,heap);
 p[3]=(unsigned int)func_0201EC64(heap);
 func_02049B40(0x17,5,4,0,0x20,heap);
 func_02049B40(0x17,5,0,0,0x20,heap);
}








void func_021B7C88(void *p) { func_0201ED04(((struct Obj07975 *)p)->fC); func_02045C04(*(struct Rec * *)&((struct Obj07975 *)p)->f4); func_0201C4C0(((struct Obj07975 *)p)->f8); func_0201D83C(((struct Obj07975 *)p)->f0); func_02082BCC(p,0,16); }








void func_021B7CB0(u8 *p) { func_0201C4E4((struct PrintSys *)(((struct Obj22143 *)p)->f8)); }









/*
 * three int getters at +0, +8, +4.
 */
int func_021B7CBC(void *p)
{
    return ((struct Obj22144 *)p)->f0;
}









int func_021B7CC0(void *p)
{
    return ((struct Obj22145 *)p)->f8;
}









int func_021B7CC4(void *p)
{
    return ((struct Obj22146 *)p)->f4;
}








/*
 * lever: sibling of func_021B7D38 (same window builder, slot 1, chr 0xF); narrow u8 c parameter places its reload immediately before the call.
 */
void func_021B7CC8(Rec *p, int a, int b, u8 c, u8 d, u8 e, u8 f, u16 heap)
{
    int win;
    func_02082BCC(p, 0, 20);
    p->chr = 0xF;
    p->win = func_020450F0(a, b, c, d, e, f, 1);
    p->que = (int)func_020457B0(255, heap);
    p->win2 = p->win;
    p->f8 = 0;
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)p->win)), p->chr);
    win = p->win;
    func_02045334((struct Descriptor *)win);
    func_02045374((struct Cfg *)win);
    func_020409B4(func_02045730((struct Descriptor *)win));
}








void func_021B7D38(u8 *p, int a, int b, u8 c, u8 d, u8 e, u8 f, u16 g, u8 h, u16 heap)
{
    int win;
    func_02082BCC(p, 0, 20);
    ((struct Obj03230 *)p)->f10 = g;
    ((struct Obj03230 *)p)->f0 = func_020450F0(a, b, c, d, e, f, h);
    ((struct Obj03230 *)p)->fC = (int)func_020457B0(255, heap);
    ((struct Obj03230 *)p)->f4 = ((struct Obj03230 *)p)->f0;
    p[8] = 0;
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj03230 *)p)->f0)), ((struct Obj03230 *)p)->f10);
    win = ((struct Obj03230 *)p)->f0;
    func_02045334((struct Descriptor *)win);
    func_02045374((struct Cfg *)win);
    func_020409B4(func_02045730((struct Descriptor *)win));
}








void func_021B7DA8(void *p) { func_02045808(*(struct U16Vec * *)&((struct Obj13726 *)p)->fC); func_020452E8(*(struct Descriptor * *)&((struct Obj13726 *)p)->f0); func_02082BCC(p,0,20); }








int func_021B7DC4(unsigned char *p,unsigned char *q) { int a=((struct Obj22147 *)q)->f8; if (p[8]) { if (!func_0201C6C4(a,(int)func_02045770((struct Descriptor *)((struct Obj06365 *)p)->f4))) { func_02045334((struct Descriptor *)((struct Obj06365 *)p)->f4); p[8]=0; } } if (!p[8]) return 1; return 0; }








void func_021B7DFC(u8 *p, void *q, int n, int x, s16 y)
{
    int a, b, c;
    a = func_021B7CC4(q);
    b = func_021B7CC0(q);
    c = func_021B7CBC(q);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj05269 *)p)->f0)), ((struct Obj05269 *)p)->f10);
    func_02045CAC((struct MsgBank *)a, n, (void *)(((struct Obj05269 *)p)->fC));
    func_0201C6FC((struct PrintSys *)b, (int)func_02045770((struct Descriptor *)((struct Obj05269 *)p)->f4), (s16)x, (s16)y, (void *)(((struct Obj05269 *)p)->fC), (int)c);
    p[8] = 1;
}








void func_021B7E60(u8 *p, void *q, int n)
{
    int a, b, c;
    u16 x, y;
    a = func_021B7CC4(q);
    b = func_021B7CC0(q);
    c = func_021B7CBC(q);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj02809 *)p)->f0)), ((struct Obj02809 *)p)->f10);
    func_02045CAC((struct MsgBank *)a, n, (void *)(((struct Obj02809 *)p)->fC));
    x = func_02045738((struct Descriptor *)(((struct Obj02809 *)p)->f0)) * 4;
    y = func_02045740((struct Descriptor *)(((struct Obj02809 *)p)->f0)) * 4;
    x -= (u16)(func_0201D304((struct StrObj *)(((struct Obj02809 *)p)->fC), c, 0) >> 1);
    y -= (u16)(func_0201D42C((struct StrObj *)(((struct Obj02809 *)p)->fC), (void *)c) >> 1);
    func_0201C6EC((struct PrintSys *)b);
    func_0201C724((void *)b, (int)func_02045770((struct Descriptor *)((struct Obj02809 *)p)->f4), (s16)x, (s16)y, (int)(((struct Obj02809 *)p)->fC), (int)c, (int)0x3dc1);
    p[8] = 1;
}






void func_021B7F08(unsigned p,unsigned x) { ((struct Obj13727 *)p)->f480=x; ((struct Obj13727 *)p)->f484=0; }






void func_021B7F18(u8 *p) { ((struct Obj22148 *)p)->f488 = 1; }




/*
 * declaration: 0200ED48's void legacy declaration is a tail call to pointer-returning 020071CC; preserve the incoming save object and live pointer result through 020120F4/02012EBC/0200ED48.
 * func_021B7250 0x021B7250 thumb ov101
 * func_021B7264 0x021B7264 thumb ov101
 * func_021B72A0 0x021B72A0 thumb ov101
 * func_021B72A8 0x021B72A8 thumb ov101
 * func_021B63BC 0x021B63BC thumb ov101
 * func_021B6150 0x021B6150 thumb ov101
 * func_021B6254 0x021B6254 thumb ov101
 * func_021B62AC 0x021B62AC thumb ov101
 * func_021B6568 0x021B6568 thumb ov101
 * func_021B657C 0x021B657C thumb ov101
 * func_021B630C 0x021B630C thumb ov101
 * func_021B6518 0x021B6518 thumb ov101
 * func_021B652C 0x021B652C thumb ov101
 * func_021B6540 0x021B6540 thumb ov101
 * func_021B6554 0x021B6554 thumb ov101
 * func_021B63CC 0x021B63CC thumb ov101
 * func_021B6424 0x021B6424 thumb ov101
 * func_021B6480 0x021B6480 thumb ov101
 * func_021B7F08 0x021B7F08 thumb ov102
 * func_021B7DFC 0x021B7DFC thumb ov102
 * func_021B8724 0x021B8724 thumb ov102
 * func_021B8320 0x021B8320 thumb ov102
 * func_021B82DC 0x021B82DC thumb ov102
 * func_021B83E0 0x021B83E0 thumb ov102
 * func_020061E4 0x020061E4 thumb
 * func_020409B4 0x020409B4 arm
 * func_020120F4 0x020120F4 thumb
 * func_02012EBC 0x02012EBC thumb
 * func_0200ED48 0x0200ED48 thumb
 * func_02008530 0x02008530 thumb
 * func_0200ED54 0x0200ED54 thumb
 */
void func_021B7F24(u8 *p,u16 *state)
{
    void *save;
    if(*state<14 && func_021B7250((void *)W(0x468))==1) {
        func_021B63BC(C);
        func_021B7F08((unsigned int)p,(unsigned int)func_021B8320);
        func_021B7264((int)((void *)W(0x468)));
        func_021B72A8((void *)W(0x468),0);
        func_020409B4(0);
        func_021B7DFC(p+0xac,p+0x9c,5,0,0);
        func_021B8724(p+0xc0);
        return;
    }
    switch(*state) {
    case 0: func_021B63BC(C); *state=1; break;
    case 1:
        if(func_021B6150(C)) { func_020061E4(1620); func_021B72A0((int)((void *)W(0x468)),1); *state=2; }
        break;
    case 2: if(func_021B6254(C)) *state=3; break;
    case 3: func_021B7DFC(p+0xac,p+0x9c,4,0,0); *state=4; break;
    case 4: if(func_021B62AC(C)) *state=5; break;
    case 5:
        if(func_021B6568(C,*(u32 *)O)) {
            func_021B657C(C,(struct R *)(*(u32 *)(O+16)));
            if(*(u32 *)O) {
                save=func_0200ED48(func_02012EBC(func_020120F4(*(void **)O)));
                func_0200ED54(save,func_02008530((const struct Sub0200852CObj *)(*(u8 **)(O+16)+12)));
            }
            *state=6;
        }
        break;
    case 6: if(func_021B630C(C,0)) *state=8; break;
    case 8:
        W(0x4a0)=1;
        if(func_021B6518((u32)C,W(0x498),W(0x494))) *state=9;
        break;
    case 9: if(func_021B652C((u32)C)) *state=10; break;
    case 10: if(func_021B6540((u32)C)) *state=11; break;
    case 11: if(func_021B6554(C)) *state=12; break;
    case 12: func_021B63CC(C,1); if(func_021B6424((int)C)) *state=13; break;
    case 13: if(func_021B630C(C,1)) { func_021B72A0((int)((void *)W(0x468)),0); *state=14; } break;
    case 14:
        if(H(0x486)>=60) { func_020061E4(1611); func_021B7DFC(p+0xac,p+0x9c,2,0,0); *state=15; }
        break;
    case 15:
        if(W(0x49c)++>=30) { *(u32 *)(O+12)=0; func_021B7F08((unsigned int)p,(unsigned int)func_021B82DC); }
        return;
    }
    if(*state>=3 && *state<=14 && H(0x486)<=60) H(0x486)++;
    if(*state<12 && func_021B6480(C)) func_021B7F08((unsigned int)p,(unsigned int)func_021B83E0);
}









void func_021B81B0(u8 *p,u16 *state)
{
    switch(*state) {
    case 0:
        ((struct Obj01917 *)p)->f494=2;
        ((struct Obj01917 *)p)->f4A0=0;
        ((struct Obj01917 *)p)->f490=func_0209C2B0((u32)func_020870D0()<<6,33514);
        *state=1;
        break;
    case 1:
        func_021B8624((State_021B85F4 *)(p+0xc0));
        if(func_021B86FC(p+0xc0)) func_021B72A0((int)(((struct Obj01917 *)p)->f468),0);
        if(func_021B870C(p+0xc0,(int *)(p+0x494))) {
            switch(((struct Obj01917 *)p)->f494) {
            case 0: *state=2; break;
            case 1:
                ((struct Obj22149 *)(*(u8 * *)&((struct Obj01917 *)p)->f48C))->fC=1;
                func_021B7F08((unsigned int)p,(unsigned int)func_021B82DC);
                break;
            }
        }
        ((struct Obj01917 *)p)->f498=func_0209C2B0((u32)func_020870D0()<<6,33514)-((struct Obj01917 *)p)->f490;
        if(func_021B7254(((struct Obj01917 *)p)->f468)) func_021B86F8(p+0xc0,0);
        if(func_021B7250(((struct Obj01917 *)p)->f468)==1) {
            func_021B63BC(((struct Obj22150 *)(*(u8 * *)&((struct Obj01917 *)p)->f48C))->f4);
            func_021B7F08((unsigned int)p,(unsigned int)func_021B838C);
        }
        break;
    case 2:
        func_021B7DFC(p+0xac,p+0x9c,3,0,0);
        func_021B72A8(((struct Obj01917 *)p)->f468,1);
        func_021B72A0((int)(((struct Obj01917 *)p)->f468),0);
        func_021B7F08((unsigned int)p,(unsigned int)func_021B7F24);
        break;
    }
}









void func_021B82DC(u8 *p, u16 *state)
{
    switch (*state) {
    case 0:
        if (((struct Obj22151 *)(*(u8 * *)&((struct Obj10235 *)p)->f48C))->fC == 1) {
            if ((((struct Obj10235 *)p)->f486)++ > 10) {
                ((struct Obj10235 *)p)->f486 = 0;
                *state = 1;
            }
        } else {
            *state = 1;
        }
        break;
    case 1:
        func_021B7F18(p);
        break;
    }
}









void func_021B8320(u8 *p, u16 *state)
{
    switch (*state) {
    case 0:
        func_021B7DFC(p + 0xac, p + 0x9c, 5, 0, 0);
        func_021B63C4(*(int * *)&((struct Obj22152 *)(*(u8 * *)&((struct Obj10237 *)p)->f48C))->f4);
        func_021B63BC(*(int * *)&((struct Obj22153 *)(*(u8 * *)&((struct Obj10237 *)p)->f48C))->f4);
        *state = 1;
        break;
    case 1:
        if (func_021B61E8((struct Obj *)(*(int * *)&((struct Obj22154 *)(*(u8 * *)&((struct Obj10237 *)p)->f48C))->f4)))
            *state = 2;
        break;
    case 2:
        func_021B7F08((unsigned int)p, (unsigned int)func_021B81B0);
        break;
    }
}









void func_021B838C(u8 *p, u16 *state)
{
    switch (*state) {
    case 0:
        *state = 1;
        func_021B63C4(*(int * *)&((struct Obj22155 *)(*(u8 * *)&((struct Obj07976 *)p)->f48C))->f4);
        func_021B63BC(*(int * *)&((struct Obj22156 *)(*(u8 * *)&((struct Obj07976 *)p)->f48C))->f4);
        break;
    case 1:
        if (func_021B61E8((struct Obj *)(*(int * *)&((struct Obj22157 *)(*(u8 * *)&((struct Obj07976 *)p)->f48C))->f4)))
            *state = 2;
        break;
    case 2:
        ((struct Obj22158 *)(*(u8 * *)&((struct Obj07976 *)p)->f48C))->fC = 2;
        func_021B7F18(p);
        break;
    }
}







void func_021B83E0(u8 *p)
{
    func_021B6480(*(int * *)&((struct Obj22159 *)(*(u8 * *)&((struct Obj07977 *)p)->f48C))->f4);
    if (func_021B62FC(*(int * *)&((struct Obj22160 *)(*(u8 * *)&((struct Obj07977 *)p)->f48C))->f4)) {
        func_021B63CC(*(int * *)&((struct Obj22161 *)(*(u8 * *)&((struct Obj07977 *)p)->f48C))->f4, 1);
        ((struct Obj22162 *)(*(u8 * *)&((struct Obj07977 *)p)->f48C))->fC = 0;
        func_021B7F08((unsigned int)p, (unsigned int)func_021B82DC);
    } else {
        func_021B7F08((unsigned int)p, (unsigned int)func_021B81B0);
    }
}






void func_021B842C(unsigned char *p) { func_021B7CB0(p+0x9c); func_021B7DC4(p+0xac,p+0x9c); func_021B7DC4(p+0x46c,p+0x9c); func_021B71E4(((struct Obj22163 *)p)->f468); func_021B78E4(p); }





/*
 * note: Separate fifth object pointer and sixth u16 heap reproduce the incoming pointer home store and halfword slot at +4; byte-correct caller 021B7560 supplies the same two slots. Struct-typed state and const Row input preserve loads across bounds stores.
 * func_02082BCC 0x02082BCC arm
 * func_02051B84 0x02051B84 arm
 * func_021B8794 0x021B8794 thumb ov102
 * func_020450F0 0x020450F0 arm
 * func_02045770 0x02045770 arm
 * func_02043B5C 0x02043B5C arm
 * func_02045334 0x02045334 arm
 * func_02045374 0x02045374 arm
 * func_02045730 0x02045730 arm
 * func_020409B4 0x020409B4 arm
 * func_021B7CC4 0x021B7CC4 thumb ov102
 * func_02045EC0 0x02045EC0 arm
 * func_0201DD78 0x0201DD78 thumb
 * func_021B7CBC 0x021B7CBC thumb ov102
 * func_0201D304 0x0201D304 thumb
 * func_0201D42C 0x0201D42C thumb
 * func_0201C7A4 0x0201C7A4 thumb
 * func_02045808 0x02045808 arm
 * func_0201DD68 0x0201DD68 thumb
 */
void func_021B8464(State_021B81B0 *p, int bg, const Row_021B81B0 *rows, int count, void *object, u16 heap)
{
    int i;
    const Row_021B81B0 *row;
    u32 win,width,height;
    void *text,*target;
    func_02082BCC(p,0,60);
    p->count=count;
    p->rows=rows;
    p->bg=bg;
    p->enable=1;
    for(i=0;i<p->count;i++) {
        row=rows+i;
        p->bounds[i*4]=row->y*8+1;
        p->bounds[i*4+1]=(row->y+row->h)*8-1;
        p->bounds[i*4+2]=row->x*8+1;
        p->bounds[i*4+3]=(row->x+row->w)*8-1;
    }
    p->bounds[i*4]=255;
    p->bank=func_02051B84(p->bounds,(int)func_021B8794,(int)p,heap);
    for(i=0;i<p->count;i++) {
        row=rows+i;
        p->windows[i]=func_020450F0(bg,(u8)(row->x+4),(u8)(row->y+1),(u8)(row->w-8),row->h-2,row->color,1);
        func_02043B5C(func_02045770((struct Descriptor *)p->windows[i]),4);
        win=p->windows[i];
        func_02045334((struct Descriptor *)win);
        func_02045374((struct Cfg *)win);
        func_020409B4(func_02045730((struct Descriptor *)win));
        text=func_02045EC0((struct MsgBank *)func_021B7CC4(object),rows[i].id);
        func_0201DD78(15,14,4);
        width=func_0201D304(text,func_021B7CBC(object),0);
        height=func_0201D42C(text,(void *)func_021B7CBC(object));
        target=func_02045770((struct Descriptor *)p->windows[i]);
        func_0201C7A4(target,(row->w-8)*4-(width>>1),(row->h-2)*4-(height>>1),text,(void *)func_021B7CBC(object));
        func_02045808(text);
        func_02045334((struct Descriptor *)p->windows[i]);
    }
    func_0201DD68();
}





void func_021B85F4(u8 *p) { int i; for(i=0;i<((struct Obj13728 *)p)->f2C;i++)func_020452E8(*(void **)(p+4+i*4)); func_02051C6C(((struct Obj13728 *)p)->f0); func_02082BCC(p,0,60); }





#pragma opt_propagation off





void func_021B8624(State_021B85F4 *p)
{
    switch(p->phase) {
    case 0:
        p->done=0;
        if(func_02051C88(p->ctx) && p->enabled) {
            func_020061E4(1352);
            p->timer=0;
            p->phase=1;
        }
        break;
    case 1: {
        u8 palette0;
        u8 win;
        u8 a,b,c,d;
        u8 blink;
        const Row_021B85F4 *row;
        u16 i;
        int off;
        u8 *rows;
        u8 palette1;
        blink=(u8)((p->timer/4)%2);
        win=func_02045730(*(struct Descriptor **)((u8 *)p+4+p->index*4));
        i=p->index;
        off=i*12;
        rows=p->rows;
        row=(const Row_021B85F4 *)(rows+off);
        a=row->x; b=row->y; c=row->w; d=row->h;
        switch(i) {
        case 0: palette1=12; palette0=11; break;
        case 1: palette1=9; palette0=4; break;
        }
        if (blink == 0) {
            func_020413B0(win,a,b,c,d,palette0);
            func_020409B4(win);
        } else {
            func_020413B0(win,a,b,c,d,palette1);
            func_020409B4(win);
        }
        (p->timer)++;
        if(p->timer>=16) {
            p->done=1;
            p->phase=0;
        }
        break;
    }
    }
}





#pragma opt_propagation reset






void func_021B86F8(u8 *p, u32 v) { ((struct Obj22165 *)p)->f38 = v; }





/*
 * note: 2026-10-05 wave P27: u16 field at +0x34 tested for non-zero. 14 B compiled, 2 B trailing pad. Twin shape in ov068 021BA6B8 area (ldrh #0x34 callers).
 */
int func_021B86FC(u8 *p)
{
    return *(u16 *)(p + 0x34) != 0;
}






int func_021B870C(u8 *p, int *out) { if(((struct Obj13729 *)p)->f32) { if(out)*out=((struct Obj13729 *)p)->f30; return 1; } return 0; }






void func_021B8724(u8 *p)
{
    int i;
    u8 win;
    u8 palette;
    u8 a, b, c, d;
    u16 *row;
    ((struct Obj07978 *)p)->f34 = 0;
    ((struct Obj07978 *)p)->f32 = 0;
    for (i = 0; i < ((struct Obj07978 *)p)->f2C; i++) {
        win = func_02045730((struct Descriptor *)(*(int *)(p + i * 4 + 4)));
        row = (u16 *)(*(u8 * *)&((struct Obj07978 *)p)->f28 + i * 12);
        a = row[1];
        b = row[2];
        c = row[3];
        d = row[4];
        switch (i) {
        case 0: palette = 11; break;
        case 1: palette = 4; break;
        }
        func_020413B0(win, a, b, c, d, palette);
        func_020409B4(win);
    }
}






/*
 * extent: includes the 8-byte setter follower at 021B8794.
 */
void func_021B8794(u16 value, int flag, u8 *p)
{
    if (flag == 0) ((struct Obj22167 *)p)->f30 = value;
}






void func_021B879C(void *p, u32 a1) { func_02082BCC(p,0,28); func_02041EE4(4,3,88); func_02041EE4(7,3,88); }






void func_021B87BC(void *p) { func_02082BCC(p,0,28); }






void func_021B87C8(u8 *p) { if(((struct Obj07980 *)p)->f18) { if(func_021B8A90((struct Struct021B8A90 *)p))((struct Obj07980 *)p)->f18=0; func_02041EE4(4,3,88-((struct Obj07980 *)p)->f0); func_02041EE4(7,3,88-((struct Obj07980 *)p)->f0); } }






void func_021B87FC(int *p)
{
    p[6] = 1;
    func_021B8A40(p, 0, 0x58, 0x78);
}






void func_021B8810(int a0, int b, int c, int a3)
{
    u16 tmp[2];

    func_02082BCC((void *)a0, 0, 0x1c);
    ((struct Obj04424 *)a0)->f18 = b;
    func_0204B878(((struct Obj04424 *)a0)->f18, c != 0 ? 0xd : 0xc);
    func_021B88F8((int *)a0);
    tmp[0] = (u16)((struct Obj04424 *)a0)->f8;
    tmp[1] = (u16)((struct Obj04424 *)a0)->fC;
    func_0204B404((struct Obj *)(((struct Obj04424 *)a0)->f18), (const struct Vec2 *)tmp, 1);
    func_0204B3DC((struct Obj *)((struct Obj04424 *)a0)->f18, 1);
    CLACT_SetActorAnimFrame((struct Obj *)(((struct Obj04424 *)a0)->f18), func_02005728(0x2000));
}




void func_021B8868(void *p) { func_02082BCC(p, 0, 0x1c); }




/*
 * extent: two trailing zero padding bytes at 021B88F6.
 * lever: sign declared before start fixes r6/r7; diff * counter avoids a move.
 */
void func_021B8874(u32 *p)
{
    u16 xy[2];
    int sign;
    int start, diff, magnitude, start2, diff2, magnitude2;
    s8 sign2;
    start = p[2];
    diff = (int)p[0] - start;
    magnitude = diff < 0 ? -diff : diff;
    sign = (s8)(diff / magnitude);
    if (diff < 0) diff = -diff;
    xy[0] = start + sign * (((u32)diff * (u32)p[4]) / (u32)p[5]);
    start2 = p[3];
    diff2 = (int)p[1] - start2;
    magnitude2 = diff2 < 0 ? -diff2 : diff2;
    sign2 = diff2 / magnitude2;
    if (diff2 < 0) diff2 = -diff2;
    xy[1] = start2 + sign2 * (((u32)diff2 * (u32)p[4]) / (u32)p[5]);
    func_0204B404((struct Obj *)p[6], (const struct Vec2 *)xy, 1);
    if ((p[4])++ > (u32)p[5]) func_021B88F8((int *)p);
}




void func_021B88F8(int *p) { p[2]=func_02005728(256); p[3]=208; p[0]=p[2]+func_02005728(184)-92; p[1]=184-200; p[4]=0; p[5]=func_02005728(360)+240; }





/*
 * Clears 0x350 bytes, stores the record count (0x1e or from 0x0200A8AC) at +0x34e,
 * then initialises count records of 0x1c bytes through func_021B8810.
 * Note 2026-10-05: func_021B8810 is matched with three parameters, but this caller
 * loads d into r3 before the call, so the original call site passes four. The older
 * draft that declared three arguments dropped that load (DIFF 109/128).
 */
void func_021B8934(u8 *a, void *b, void *c, int d)
{
    int i;
    func_02082BCC(a, 0, 0x350);
    if (c == 0)
        *(u16 *)(a + 0x34e) = 0x1e;
    else
        *(u16 *)(a + 0x34e) = func_0200A8AC(c);
    for (i = 0; i < *(u16 *)(a + 0x34e); i++) {
        u32 t = func_021B78EC(b, i);
        u32 u;
        if (c == 0)
            u = func_02005728(2);
        else
            u = (func_0200A8F8(c, i) == 1);
        func_021B8810((int)(a + i * 0x1c), t, u, d);
    }
}




void func_021B89B8(u8 *p) { int i; for(i=0;i<((struct Obj22169 *)p)->f34E;i++)func_021B8868(p+i*28); func_02082BCC(p,0,848); }




/*
 * extent: two trailing zero padding bytes at 021B8A3E.
 */
void func_021B89F0(u8 *p)
{
    int i;
    for (i = 0; i < ((struct Obj05270 *)p)->f34C; i++)
        func_021B8874((u32 *)(p + i * 0x1c));
    if ((((struct Obj05270 *)p)->f348)++ > 30) {
        ((struct Obj05270 *)p)->f348 = 0;
        if (((struct Obj05270 *)p)->f34C < ((struct Obj05270 *)p)->f34E)
            (((struct Obj05270 *)p)->f34C)++;
    }
}




/*
 * extent: two trailing zero padding bytes at 021B8A8E.
 */
void func_021B8A40(int *p, int a, int b, int n)
{
    int d;
    float f;
    p[0] = a;
    p[1] = a;
    p[2] = b;
    p[5] = n;
    if (n) {
        d = b - a;
        if (d > 0)
            f = 0.5f + (float)(d << 12);
        else
            f = (float)(d << 12) - 0.5f;
        p[3] = (int)f / n;
        p[4] = 0;
    } else {
        p[4] = n - 2;
    }
}
