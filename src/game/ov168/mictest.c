/*
 * file:     mictest.c
 * unit:     yes
 * function: func_02183B60, func_02183C50, func_02183CCC, func_02183D0C, func_02183D1C, func_02183D34, func_02183D3C, func_02183D40, func_02183D44, func_02183D4C, func_02183DAC, func_02183E18, func_02183E60, func_02183EC0, func_02183ED4, func_02183F08, func_02183F30, func_02183F40, func_02183F6C, func_02183F98, func_02183FA0, func_02183FC4, func_02184138, func_02184144, func_0218414C, func_021841C8, func_021841F4, func_021841F8, func_021842B4, func_021842BC, func_02184360, func_02184398, func_02184408, func_0218441C, func_02184470, func_0218448C, func_0218449C, func_021844C8, func_021845AC, func_021845E0, func_02184600, func_02184680, func_02184780, func_02184818, func_0218483C, func_0218484C
 * address:  0x02183B60
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030734 0x02030734 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_020056A0 0x020056A0 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   d_02184A20 0x02184A20 data a4
 *   func_02030EAC  0x02030EAC  arm
 *   func_02030DA4  0x02030DA4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   PROCSYS_ReplaceGlobal  0x020312F8  arm
 *   ov088_id       0x00000058  data  a1
 *   d_021BD574     0x021BD574  data  a4
 *   func_02030D28   0x02030D28  arm
 *   WIPE_SYS_Start   0x0202208C  thumb
 *   WIPE_SYS_EndCheck   0x020221A4  thumb
 *   func_0218484C   0x0218484C  thumb
 *   func_02006D94   0x02006D94  thumb
 *   func_020061E4   0x020061E4  thumb
 *   CLACT_SetActorAnimSeq   0x0204B878  arm
 *   CLACT_IsActorAnimActive   0x0204B98C  arm
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   WIPE_ResetWndMask  0x02022224  thumb
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   NNS_GfdDoVramTransfer  0x02061C44  arm
 *   SDK_AUTOLOAD_MAIN_TWL_START  0x02FE0000  data
 *   CLACT_InitSystem  0x0204A48C  arm
 *   func_020434DC  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   gClActorInitParam     0x020A1448  data  a4
 *   d_021848D4     0x021848D4  data  ov168  a4
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_AddActorAnimFrame  0x0204B8D4  arm
 *   CLACT_DrawSystem  0x0204A600  arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   func_020490F4 0x020490F4 arm
 *   func_020275E4 0x020275E4 thumb
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 *   CLACT_SetActorFlip 0x0204B604 arm
 *   d_02184910 0x02184910 data a4
 *   d_021848AC 0x021848AC data a4
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   func_02040588 0x02040588 arm
 *   d_02184878 0x02184878 data a4
 *   d_02184964 0x02184964 data a1
 *   func_020403F4  0x020403F4  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02049B40 0x02049B40 arm
 *   func_02049624 0x02049624 arm
 *   func_0204989C 0x0204989C arm
 *   func_020419E4 0x020419E4 arm
 *   func_02045B38 0x02045B38 arm
 *   BMP_WIN_CreateAt 0x02045180 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   d_02184888 0x02184888 data a1
 *   d_02184868 0x02184868 data a2
 *   func_020452E8 0x020452E8 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   SND_MIC_Init 0x02006CBC thumb
 *   func_02034F84 0x02034F84 arm
 *   func_02006D44  0x02006D44  thumb
 *   func_02034FB8  0x02034FB8  arm
 *   func_02006D64   0x02006D64  thumb
 *   func_0208B500  0x0208B500  arm
 *   func_0208B528  0x0208B528  arm
 *   d_02184A40 0x02184A40 data a4
 *   func_020056EC 0x020056EC thumb
 *   func_02030DA8  0x02030DA8  arm
 *   TCBL_IsDeletePending  0x02030EE8  arm
 *   func_0203F5FC  0x0203F5FC  arm
 *   CLACT_SetActorPosAxis  0x0204B550  arm
 *   _ll_mul        0x0209C054  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_0207C9D0 0x0207C9D0 arm
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 */
#include "../../matched/include/Obj02210.h"
#include "../../matched/include/Obj23813.h"
#include "../../matched/include/Obj14257.h"
#include "../../matched/include/Obj23817.h"
#include "../../matched/include/Obj14259.h"
#include "../../matched/include/Obj23818.h"
#include "../../matched/include/Obj01262.h"
#include "../../matched/include/Obj10642.h"
#include "../../matched/include/Obj23820.h"
#include "../../matched/include/Obj23821.h"
#include "../../matched/include/Obj03845.h"
#include "../../matched/include/Obj14260.h"
#include "../../matched/include/Obj23822.h"
#include "../../matched/include/Obj10643.h"
#include "../../matched/include/Obj23823.h"
#include "../../matched/include/Obj01947.h"
#include "../../matched/include/Obj04544.h"
#include "../../matched/include/Obj10644.h"

#define FX_F32_TO_FX32(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))
#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))
struct Obj0203159C;
struct Ctx;
struct Node;
struct S020315D4;
struct Actor;
struct Obj;
struct DispVram;
struct Cfg;
struct Bank;
struct CharBuf;
struct Descriptor;
struct Rec;
struct Blk37;
struct DispConfig;
struct GfFont;
struct BgTemplate;
struct MsgBank;
struct U16Vec;
struct S02030EE8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef enum {OBJECT_SIZE=0x150} Size;

enum Result {DONE=1};

typedef void (*fn_02183D1C)(int *, int *);

typedef struct {u32 group,id,config;} Row;

typedef struct {short x,y,id;u8 a,b;} Config;

typedef signed int     s32;

typedef signed short s16;

typedef struct { u32 pad0; const u8 *data; int count; } Buf;

typedef int fx32;

typedef long long fx64;

typedef struct {
    u32 handle;
    u32 timer;
    fx32 x;
    fx32 y;
    fx32 z0;
    fx32 vx;
    fx32 vy;
    fx32 w0;
    fx32 w1;
    fx32 w2;
    u32 h;
    u32 task;
} Obj;

extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,u32);
extern u32 func_02030CB0(u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void *func_020056A0(u32,u32,u32);
extern void GFL_USE_FadeOutBgm(u32 a);
extern void func_02030EAC(struct Node *n);
extern void func_02030DA4(int);
extern u32 func_020307B0(void *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void PROCSYS_ReplaceGlobal(u32 a1, u32 a2, u32 a3);
extern void func_02030D28(struct Ctx *c);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 WIPE_SYS_EndCheck(void);
extern int func_0218484C(void);
extern u32 func_02006D94(void);
extern void func_020061E4(u32 a);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern u32 WIPE_ResetWndMask(void *win);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void NNS_GfdDoVramTransfer(void);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_020434DC(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void CLACT_ExitSystem(void);
extern void CLACT_AddActorAnimFrame(struct Obj *p, u32 arg);
extern void CLACT_DrawSystem(void);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_020275E4(void);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern int CLACT_RegisterCellAnim(void *,u32,u32,u32);
extern void ARC_TOOL_DeleteHandle(void *);
extern struct Obj *CLACT_CreateActor(void *,u32,u32,u32,const void *,u16,u16);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);
extern void CLACT_SetActorFlip(struct Actor *actor, u32 which, u32 set);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_VBlankSystem(void);
extern void func_0203F8F4(u16);
extern void BMP_WIN_Init(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(unsigned);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u16 heapId);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(u32 v);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern void func_020419E4(void);
extern struct MsgBank *func_02045B38(unsigned int resident, unsigned int arcId, unsigned int fileId, unsigned int heapId);
extern unsigned int BMP_WIN_CreateAt(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, u8 c, u8 d, unsigned int offset);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(unsigned);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void SND_MIC_Init(u16 heap);
extern void func_02034F84(u32 v);
extern void func_02006D44(void);
extern void func_02034FB8(u32 v);
extern void func_02006D64(u32 n);
extern void func_0208B500(int *);
extern int func_0208B528(void);
extern u32 func_020056EC(u32 range);
extern u32 func_02030DA8(int owner, void (*fn)(), int arg, int n);
extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);
extern int func_0203F5FC(u32 x);
extern void CLACT_SetActorPosAxis(struct Actor *actor, signed short value, u32 axis);
extern void func_0207C9D0(void *, void *, void *);
extern int TOUCHPANEL_HitTrg(const void *p);
enum Result func_02183B60(void *obj);
int func_02183C50(int a, int b, int c, void *p);
int func_02183CCC(int a, int b, int c, char *p);
void func_02183D0C(int *p, int a, int b);
void func_02183D1C(int *p);
void func_02183D34(unsigned int *p,unsigned int v);
unsigned int func_02183D3C(unsigned int *p);
int func_02183D40(unsigned int *p);
void func_02183D44(unsigned int *p);
void func_02183D4C(int a, int *state);
void func_02183DAC(int a, int *state);
void func_02183E18(int a, int *state);
void func_02183E60(int a, int *state);
void func_02183EC0(int *p);
void func_02183ED4(int a0);
void func_02183F08(void);
void func_02183F30(void);
void func_02183F40(void *unused, char *p);
void func_02183F6C(int unused, u32 b);
void func_02183F98(void *a0);
void func_02183FA0(void **p);
void func_02183FC4(char *p,u16 heap);
void func_02184138(char *p);
void func_02184144(void *p);
void func_0218414C(char *p, int heap);
void func_021841C8(void *a0);
void func_021841F4(char *a0);
void func_021841F8(void *p, int heap);
void func_021842B4(void *p);
void func_021842BC(void **p, int heap);
void func_02184360(char *p);
void func_02184398(u8 *p, int heap, u32 b, u32 c);
void func_02184408(int *p);
void func_0218441C(int *p);
void func_02184470(int *p);
void func_0218448C(int *p);
int func_0218449C(Buf *p);
void func_021844C8(int event, char *p);
int func_021845AC(u8 n);
int func_021845E0(char *p);
int func_02184600(char *p, int unused, s16 x, s16 y, void *owner);
void func_02184680(int a0, u32 handle, int a2, s16 a3, s16 e, int f, u32 g, u32 h, u32 i);
void func_02184780(void *task, int *p);
void func_02184818(char *p);
int func_0218483C(void);
extern const char d_02184A20[];
extern char ov088_id[];
extern char d_021BD574[];
extern u32 SDK_AUTOLOAD_MAIN_TWL_START[];
extern const Row d_02184910[];
extern const Config d_021848AC[];
extern int d_02184878[];
extern u8 d_02184964[];
extern const u8 d_02184888[];
extern u16 d_02184868[];
extern unsigned d_02184A40;








enum Result func_02183B60(void *obj)
{
    u8 *p;
    Size size;
    int result=1;
    GFL_HEAP_CreateChildHeap(1,73,0x70000);
    size=OBJECT_SIZE;
    p=PROCSYS_AllocProcWork(obj,size,73);
    func_02082BCC(p,0,size);
    ((struct Obj02210 *)((unsigned)p))->f14C=73;
    func_02183ED4(73);
    func_02183F30();
    ((struct Obj02210 *)p)->f140=func_02030734((u16)((struct Obj02210 *)((unsigned)p))->f14C,func_02030CB0(5),0,d_02184A20,0x21d);
    ((struct Obj02210 *)((unsigned)p))->f144=func_02030CBC(5,((struct Obj02210 *)p)->f140);
    ((struct Obj02210 *)((unsigned)p))->f148=func_020056A0((u32)func_02183F40,(u32)p,1);
    func_0218414C((char *)p+0xe4,((struct Obj02210 *)((unsigned)p))->f14C);
    func_021841F8(p+0xe4,((struct Obj02210 *)((unsigned)p))->f14C);
    func_021842BC((void **)(p+0xe4),((struct Obj02210 *)((unsigned)p))->f14C);
    func_02183F6C((int)p,*(u32 *)&((struct Obj02210 *)((unsigned)p))->f14C);
    func_02183FC4((char *)p,((struct Obj02210 *)((unsigned)p))->f14C);
    func_02184398((u8 *)(p+0xf8),((struct Obj02210 *)((unsigned)p))->f14C,(int)func_021844C8,(int)p);
    func_02183D0C((int *)((unsigned)p+0x130),(int)p,(int)func_02183D4C);
    GFL_USE_FadeOutBgm(10);
    return result;
}









int func_02183C50(int a, int b, int c, void *p)
{
    unsigned short v;

    func_02184408((int *)((char *)p + 0xf8));
    func_02030EAC((struct Node *)(*(int *)((char *)p + 0x148)));
    func_02030DA4(*(int *)((char *)p + 0x144));
    func_020307B0((void *)(*(int *)((char *)p + 0x140)));
    func_02184138(p);
    func_02183F98(p);
    func_02184360((char *)p + 0xe4);
    func_021841C8((char *)p + 0xe4);
    func_02183F08();
    v = (unsigned short)*(int *)((char *)p + 0x14c);
    func_020315D4((struct S020315D4 *)a);
    func_020306F0(v);
    GFL_USE_FadeInBgmFull(0xa);
    PROCSYS_ReplaceGlobal((u32)ov088_id, (u32)d_021BD574, 0);
    return 1;
}









/*
 * Gate on p+0x130, then run the four init/teardown helpers and the
 *   word at p+0x144 through func_02030D28.
 */
int func_02183CCC(int a, int b, int c, char *p)
{
    if (func_02183D40((unsigned int *)(p + 0x130)))
        return 1;
    func_02183D1C((int *)(p + 0x130));
    func_02183FA0((void **)p);
    func_021841F4(p + 0xE4);
    func_0218441C((int *)(p + 0xF8));
    func_02030D28((struct Ctx *)(((struct Obj23813 *)p)->f144));
    return 0;
}









void func_02183D0C(int *p, int a, int b)
{
    *p = a;
    ((struct Obj14257 *)p)->fC = 0;
    func_02183D34((unsigned int *)p, b);
}









void func_02183D1C(int *p)
{
    if (func_02183D40((unsigned int *)p) == 0)
        ((fn_02183D1C)(*(void **)((char *)p + 4)))(p, (int *)((char *)p + 8));
}








void func_02183D34(unsigned int *p,unsigned int v) { p[1]=v; p[2]=0; }








unsigned int func_02183D3C(unsigned int *p) { return p[0]; }








int func_02183D40(unsigned int *p) { return p[3]; }








/*
 * extent: 6-byte body followed by two bytes of zero alignment padding.
 */
void func_02183D44(unsigned int *p) { p[3]=1; }









void func_02183D4C(int a, int *state)
{
    int x = func_02183D3C((unsigned int *)a);
    switch (*state) {
    case 0:
        WIPE_SYS_Start(0, 1, 1, 0, 6, 1, ((struct Obj23817 *)x)->f14C);
        *state = 1;
        break;
    case 1:
        if (WIPE_SYS_EndCheck())
            *state = 2;
        break;
    case 2:
        func_02183D34((unsigned int *)a, (unsigned int)func_02183DAC);
        break;
    }
}









void func_02183DAC(int a, int *state)
{
    int x = func_02183D3C((unsigned int *)a);
    switch (*state) {
    case 0:
        func_02184470((int *)(x + 0xF8));
        *state = 1;
        break;
    case 1:
        if (func_0218484C() && func_02006D94()) {
            func_020061E4(0x551);
            *state = 2;
        }
        break;
    case 2:
        func_0218448C((int *)(x + 0xF8));
        *state = 3;
        break;
    case 3:
        func_02183D34((unsigned int *)a, (unsigned int)func_02183E18);
        break;
    }
}









/*
 * Three-state step over the object at *(x+0xC): start on 0, poll on 1,
 *   install 0x2183E60 on 2.
 */
void func_02183E18(int a, int *state)
{
    int x = func_02183D3C((unsigned int *)a);
    switch (*state) {
    case 0:
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj14259 *)x)->fC), 1);
        *state = 1;
        break;
    case 1:
        if (CLACT_IsActorAnimActive((struct Actor *)(((struct Obj14259 *)x)->fC)) == 0)
            *state = 2;
        break;
    case 2:
        func_02183D34((unsigned int *)a, (unsigned int)func_02183E60);
        break;
    }
}









/*
 * Step a two-slot state machine: publish through WIPE_SYS_Start on state 0,
 *   poll WIPE_SYS_EndCheck on 1, install func_02183EC0 on 2.
 */
void func_02183E60(int a, int *state)
{
    int x = func_02183D3C((unsigned int *)a);
    switch (*state) {
    case 0:
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, ((struct Obj23818 *)x)->f14C);
        *state = 1;
        break;
    case 1:
        if (WIPE_SYS_EndCheck())
            *state = 2;
        break;
    case 2:
        func_02183D34((unsigned int *)a, (unsigned int)func_02183EC0);
        break;
    }
}









void func_02183EC0(int *p)
{
    func_02184818((char *)func_02183D3C((unsigned int *)((int)p)));
    func_02183D44((unsigned int *)p);
}









void func_02183ED4(int a0)
{
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32 *)0x04000000 &= 0xFFFFE0FFu;
    *(volatile u32 *)0x04001000 &= 0xFFFFE0FFu;
    WIPE_ResetWndMask((void *)0);
    WIPE_ResetWndMask((void *)1);
}









void func_02183F08(void)
{
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32 *)0x04000000 &= 0xFFFFE0FFu;
    *(volatile u32 *)0x04001000 &= 0xFFFFE0FFu;
}









void func_02183F30(void)
{
    BG_SYS_SetVramBanks((void *)0x021848D4);
}









void func_02183F40(void *unused, char *p)
{
    NNS_GfdDoVramTransfer();
    func_02184144(p);
    func_021842B4(p + 0xe4);
    *(u32 *)((u8 *)SDK_AUTOLOAD_MAIN_TWL_START + 0x3FF8) |= 1;
}









void func_02183F6C(int unused, u32 b)
{
    CLACT_InitSystem((void *)0x020A1448, (u32)((void *)0x021848D4), (u16)b);
    func_020434DC(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}








void func_02183F98(void *a0) { CLACT_ExitSystem(); }









void func_02183FA0(void **p)
{
    u16 i;

    for (i = 0; i < 7; i++)
        CLACT_AddActorAnimFrame(p[i], 0x1000);
    CLACT_DrawSystem();
}








/*
 * abi: ABF0 and B294 results remain live and are stored by this caller; their extern return types reflect that use.
 */
void func_02183FC4(char *p,u16 heap)
{
    void *first,*second;
    u16 i;
    const Row *r;
    char *q;
    i=0;
    ((struct Obj01262 *)p)->f1C=CLACT_CreateUnit(32,0,heap);
    first=func_020490F4(106,heap);
    second=func_020490F4(func_020275E4(),heap);
    ((struct Obj01262 *)p)->f24=CLACT_RegisterPalette(first,6,0,0,heap);
    ((struct Obj01262 *)p)->f20=CLACT_RegisterCharacter(first,7,0,0,heap);
    ((struct Obj01262 *)p)->f28=CLACT_RegisterCellAnim(first,8,9,heap);
    ((struct Obj01262 *)p)->f30=CLACT_RegisterPalette(first,10,0,32,heap);
    ((struct Obj01262 *)p)->f2C=CLACT_RegisterCharacter(first,11,0,0,heap);
    ((struct Obj01262 *)p)->f34=CLACT_RegisterCellAnim(first,12,13,heap);
    ((struct Obj01262 *)p)->f3C=CLACT_RegisterPalette(first,14,0,64,heap);
    ((struct Obj01262 *)p)->f38=CLACT_RegisterCharacter(first,15,0,0,heap);
    ((struct Obj01262 *)p)->f40=CLACT_RegisterCellAnim(first,16,17,heap);
    ((struct Obj01262 *)p)->f48=CLACT_RegisterPalette(second,31,1,0,heap);
    ((struct Obj01262 *)p)->f44=CLACT_RegisterCharacter(second,32,0,1,heap);
    ((struct Obj01262 *)p)->f4C=CLACT_RegisterCellAnim(first,18,19,heap);
    ARC_TOOL_DeleteHandle(second);
    ARC_TOOL_DeleteHandle(first);
    do{
        r=&d_02184910[i];
        q=p+r->group*4;
        *(void **)(p+i*4)=CLACT_CreateActor((void *)*(u32 *)&((struct Obj01262 *)p)->f1C,((struct Obj10642 *)q)->f20,((struct Obj10642 *)q)->f24,((struct Obj10642 *)q)->f28,&d_021848AC[r->config],r->id,heap);
        func_0204B92C(*(void **)(p+i*4),1);
        ++i;
    }while(i<7);
    for(i=0;i<3;i++)func_0204B3DC(*(void **)(p+i*4+0x10),0);
    CLACT_SetActorAffineMode(((struct Obj01262 *)p)->f0,0);
    CLACT_SetActorFlip(((struct Obj01262 *)p)->f0,1,1);
    ((struct Obj01262 *)p)->fE0=10;
}








void func_02184138(char *p) { CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj23820 *)p)->f1C); }








void func_02184144(void *p) { CLACT_VBlankSystem(); }








void func_0218414C(char *p, int heap)
{
    unsigned i;
    unsigned bg;
    func_0203F8F4(heap);
    BMP_WIN_Init(heap);
    func_0203FC28((struct DispConfig *)d_02184878);
    ((struct Obj23821 *)p)->f10 = GF_FONT_Create(23, 0, 0, 0, (u16)heap);
    for (i = 0; i < 5; i++) {
        bg = d_02184964[i * 0x24 + 0x20];
        func_0203FCA0(bg, (const struct BgTemplate *)(d_02184964 + i * 0x24), d_02184964[i * 0x24 + 0x21]);
        func_020414EC(bg);
        func_02040B94(bg, 32, 0, (u16)heap);
        func_02040588(bg, 1);
    }
}









void func_021841C8(void *a0)
{
    u32 i;

    for (i = 0; i < 5; i++)
        func_020403F4(d_02184964[i * 0x24 + 0x20]);
    BMP_WIN_Exit();
    func_0203F9B4();
}









void func_021841F4(char *a0) {  }








void func_021841F8(void *p, int heap)
{
    func_02049B40(106, 0, 0, 0, 32, heap);
    func_02049B40(106, 1, 4, 0, 32, heap);
    func_02049B40(23, 5, 0, 416, 32, heap);
    func_02049B40(23, 5, 4, 416, 32, heap);
    func_02049624((void *)106, (void *)4, (void *)5, 0, 0, 0, heap);
    func_0204989C(106, 5, 5, 0, 0, 0, heap);
    func_02049624((void *)106, (void *)2, (void *)1, 0, 0, 0, heap);
    func_0204989C(106, 3, 1, 0, 0, 0, heap);
}








void func_021842B4(void *p) { func_020419E4(); }








void func_021842BC(void **p, int heap)
{
    int i;
    const u8 *row;
    void *a;
    void *b;
    void *s;
    p[3] = func_02045B38((int)0,(int)2,(int)65,(u16)heap);
    for (i=0;i<3;i++) {
        row = d_02184888+i*12;
        p[i] = (void *)BMP_WIN_CreateAt((int)row[0],(int)row[1],(int)row[2],(int)row[3],row[4],row[5],(int)(((struct Obj03845 *)row)->f6));
        a = func_02045770(p[i]);
        BMP_Clear(a,0);
        BMP_WIN_ClearScreen(p[i]);
        b = func_02045EC0(p[3],i);
        PRINTSYS_PrintColor(a,row[8],0,b,p[4],d_02184868[i]);
        STRBUF_Delete(b);
        s = p[i];
        BMP_WIN_TransferChars(s);
        BMP_WIN_MakeScreen(s);
        func_020409B4(func_02045730(s));
    }
}








void func_02184360(char *p) { int i; for(i=0;i<3;i++) {BMP_Clear(func_02045770(*(void **)(p+i*4)),0);BMP_WIN_ClearScreen(*(struct Descriptor **)(p+i*4));func_020452E8(*(struct Descriptor **)(p+i*4));} MSGDATA_Delete(*(struct Rec * *)&((struct Obj14260 *)p)->fC);GF_FONT_Delete(((struct Obj14260 *)p)->f10); }








/*
 * 2026-10-05 (wD8 lane06): closed with plain literals (no size local). mwcc keeps one constant of the
 *   block in a callee-saved register and derives the others from it: with the 0x100 store written right
 *   after the aligned-pointer store, 0x120 wins r6 and 0x100 becomes `subs r6,#0x20`. With the 0x100 store
 *   last, 1 wins and 0x100 becomes `adds r0,#0xff` (108 bytes). Earlier lanes needed an enum local here.
 */
void func_02184398(u8 *p, int heap, u32 b, u32 c)
{
    u8 *buf;
    SND_MIC_Init(heap);
    func_02034F84(8);
    buf = func_02030734((u16)heap, 0x120, 0, d_02184A20, 0x603);
    func_02082BCC(buf, 0, 0x120);
    *(u8 **)(p + 0x1c) = buf;
    *(u32 *)p = 0;
    *(u32 *)(p + 4) = ((u32)buf + 0x1f) & ~0x1f;
    *(u32 *)(p + 8) = 0x100;
    *(u32 *)(p + 0xc) = 0x1001;
    *(u32 *)(p + 0x10) = 1;
    *(u32 *)(p + 0x14) = b;
    *(u32 *)(p + 0x18) = c;
    *(u32 *)(p + 0x34) = func_02006D94();
}









void func_02184408(int *p)
{
    func_020307B0((void *)(((struct Obj23822 *)p)->f1C));
    func_02006D44();
    func_02034FB8(8);
}








/*
 * Latch the polled flag into p[0x34], arming and disarming the p[0x2c]
 *   work item while p[0x30] tracks the busy state.
 */
void func_0218441C(int *p)
{
    int x;
    int y;
    func_02006D64(1);
    x = func_02006D94();
    if (x != 0 && p[13] != 0)
        goto end;
    if (p[12] == 0) {
        if (p[10] != 0) {
            func_0218448C(p);
            p[11] = 1;
        }
        p[12] = 1;
    }
    if (x == 0)
        goto end;
    if (p[13] != 0)
        goto end;
    y = p[11];
    p[12] = 0;
    if (y != 0) {
        func_02184470(p);
        p[11] = 0;
    }
end:
    p[13] = x;
}








void func_02184470(int *p)
{
    if (((struct Obj10643 *)p)->f30 == 0) {
        func_0208B500(p);
        ((struct Obj10643 *)p)->f28 = 1;
    } else {
        ((struct Obj10643 *)p)->f2C = 1;
    }
}








void func_0218448C(int *p)
{
    func_0208B528();
    ((struct Obj23823 *)p)->f28 = 0;
}





int func_0218449C(Buf *p)
{
    int max = 0;
    int i;
    int n = p->count - 1;
    const u8 *d = p->data;
    i = 0;
    for (; i < n; i++) {
        u32 v = d[i];
        if (v < 0x80) v = 255 - v;
        if ((int)v > max) max = v;
    }
    return max;
}





void func_021844C8(int event, char *p)
{
    char *q;
    int n,anim;
    if(event==0){
        q=p+0xf8;
        n=func_0218449C((Buf *)q);
        if(((struct Obj04544 *)q)->f20<n){
            anim=func_021845AC(n);
            ((struct Obj04544 *)q)->f20=n;
            ((struct Obj04544 *)q)->f24=1;
        }else{
            anim=func_021845AC(((struct Obj04544 *)q)->f20);
            ((struct Obj04544 *)q)->f20-=2;
        }
        if(anim!=0){
            if(((struct Obj04544 *)q)->f24!=0){
                CLACT_SetActorAnimSeq(((struct Obj01947 *)p)->f8,1);
                ((struct Obj04544 *)q)->f24=0;
            }
            if(func_021845E0(p)){
                func_02184600(p,((struct Obj01947 *)p)->f14C,128,64,((struct Obj01947 *)p)->f144);
            }else{
                --((struct Obj01947 *)p)->fE0;
                if(((struct Obj01947 *)p)->fE0==0){
                    func_02184600(p,((struct Obj01947 *)p)->f14C,128,64,((struct Obj01947 *)p)->f144);
                    ((struct Obj01947 *)p)->fE0=10;
                }
            }
            CLACT_SetActorAnimSeq(((struct Obj01947 *)p)->f0,anim);
            CLACT_SetActorAnimSeq(((struct Obj01947 *)p)->f4,anim);
        }else if(anim==0){
            CLACT_SetActorAnimSeq(((struct Obj01947 *)p)->f8,0);
            CLACT_SetActorAnimSeq(((struct Obj01947 *)p)->f0,0);
            CLACT_SetActorAnimSeq(((struct Obj01947 *)p)->f4,0);
        }
        ++d_02184A40;
    }
}






int func_021845AC(u8 n) { if(n<=150)return 0;if(n>=151 && n<=162)return 1;if(n>=163 && n<=176)return 2;if(n>=177 && n<=197)return 3;if(n>=198)n=4;return n; }




int func_021845E0(char *p) { int i;for(i=0;i<3;i++)if(*(void **)(p+i*0x30+0x7c))return 0;return 1; }


int func_02184600(char *p, int unused, s16 x, s16 y, void *owner)
{
    void *sprite = 0;
    char *entry = 0;
    int i;
    int a;
    int b;
    int c;
    for (i = 0; i < 3; i++) {
        if (*(int *)(p + i * 0x30 + 0x7c) == 0) {
            entry = p + 0x50 + i * 0x30;
            sprite = *(void **)(p + (i + 4) * 4);
            break;
        }
    }
    if (entry) {
        a = func_020056EC(0x1001) + 0x1333;
        b = func_020056EC(61) + 60;
        c = func_020056EC(15) + 6;
        func_02184680((int)owner, (u32)sprite, (int)entry, x, y, a, b, c, 1);
        return 1;
    }
    return 0;
}



/*
 * note (2026-10-05, wD9r lane41): closed by the parameter width. x and y (a3, e) are s16, and
 *   CLACT_SetActorPosAxis takes an s16 second argument as in the matched sibling ov168 02184780. With an s16
 *   stack parameter the y load stays with the entry parameter copies (ldr r5,[sp,#0x18] before the
 *   pool load); an int parameter sinks it to the end of the entry block.
 */
void func_02184680(int a0, u32 handle, int a2, s16 a3, s16 e, int f, u32 g, u32 h, u32 i)
{
    Obj *o;
    u32 t;
    int c;

    t = func_02030DA8(a0, func_02184780, a2, 0);
    ((u32 *)a2)[0x2c / 4] = t;
    o = (Obj *)TCBL_IsDeletePending((struct S02030EE8 *)t);
    o->handle = handle;
    o->timer = i;
    o->x = FX_F32_TO_FX32(a3);
    o->y = FX_F32_TO_FX32(e);
    o->z0 = 0;
    c = func_0203F5FC((u16)(g + 0x5a));
    o->vx = FX_MUL(f, c);
    c = func_0203F5FC((u16)g);
    o->vy = -FX_MUL(f, c);
    o->w0 = 0;
    o->w1 = 0;
    o->w2 = 0x6000;
    o->h = h;
    CLACT_SetActorPosAxis((struct Actor *)o->handle, a3, 0);
    CLACT_SetActorPosAxis((struct Actor *)o->handle, e, 1);
}



/*
 * extent: two-byte alignment padding at 0x02184816.
 * Verified blocker C copied from ov137_func_021E09C0.c;
 * S13/blocker_0203F5FC-r1.log reports EXACT, 64 bytes:
 */
void func_02184780(void *task, int *p)
{
    s16 x;
    s16 y;
    int angle;
    if (p[1] != 0) {
        p[1]--;
        if (p[1] == 0)
            func_0204B3DC((void *)p[0], 1);
        return;
    }
    func_0207C9D0(p + 2, p + 5, p + 2);
    x = p[2] >> 12;
    y = p[3] >> 12;
    p[8] += p[9];
    while (p[8] > 0x168000)
        p[8] -= 0x168000;
    angle = func_0203F5FC((u16)(p[8] >> 12));
    x += (s16)((p[10] * angle) >> 12);
    CLACT_SetActorPosAxis((void *)p[0], x, 0);
    CLACT_SetActorPosAxis((void *)p[0], y, 1);
    if (y < -16) {
        func_0204B3DC((void *)p[0], 0);
        func_02030EAC(task);
        p[11] = 0;
    }
}



void func_02184818(char *p) { int i; char *q;for(i=0;i<3;i++){q=p+i*0x30;if(*(struct Node * *)&((struct Obj10644 *)q)->f7C){func_02030EAC(*(struct Node * *)&((struct Obj10644 *)q)->f7C);*(struct Node * *)&((struct Obj10644 *)q)->f7C=0;}} }




int func_0218483C(void)
{
    return TOUCHPANEL_HitTrg((void *)0x0218486E);
}

extern u32 func_020362DC(void);

int func_0218484C(void)
{
    return func_0218483C() == 0 || (func_020362DC() & 2) != 0;
}

