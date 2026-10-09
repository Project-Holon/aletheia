/*
 * file:     sta_acting.c
 * unit:     yes
 * function: func_021F8480, func_021F8640, func_021F879C, func_021F899C, func_021F8BD4, func_021F8D88, func_021F8DA0, func_021F8DC4, func_021F8E58, func_021F8E88, func_021F8EA8, func_021F90E0, func_021F9140, func_021F91A8, func_021F91CC, func_021F92CC, func_021F9374, func_021F93D8, func_021F94B0, func_021F94F8, func_021F95CC, func_021F95E8, func_021F95F0, func_021F9664, func_021F9680, func_021F9690, func_021F969C, func_021F96B0, func_021F96C4, func_021F96D0, func_021F9730, func_021F9754, func_021F9768, func_021F9774, func_021F9794, func_021F99F4, func_021F9A48, func_021F9AD8, func_021F9CF4, func_021F9D08, func_021F9D18, func_021F9D80, func_021F9D90, func_021F9DA0, func_021F9DA4, func_021F9DAC, func_021F9DB0, func_021F9DB8, func_021F9DC0, func_021F9DC4, func_021F9DCC, func_021F9DD4, func_021F9DDC, func_021F9DE8, func_021F9DF4, func_021F9DFC, func_021F9E00, func_021F9E04, func_021F9E08, func_021F9E0C, func_021F9E18
 * address:  0x021F8480
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021FD8D4 0x021FD8D4 thumb ov132
 *   func_020490F4 0x020490F4 arm
 *   func_021F6BD8 0x021F6BD8 thumb ov112
 *   func_021F9FEC 0x021F9FEC thumb ov132
 *   func_021FA5B0 0x021FA5B0 thumb ov132
 *   func_021FAAF4 0x021FAAF4 thumb ov132
 *   func_0203D34C 0x0203D34C arm
 *   d_021FDCA0 0x021FDCA0 data a1
 *   g_02FFFC3C 0x02FFFC3C data a4
 *   func_02005D28 0x02005D28 thumb
 *   func_02006504 0x02006504 thumb
 *   func_02006518 0x02006518 thumb
 *   func_0207D534 0x0207D534 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021FAB58 0x021FAB58 thumb ov132
 *   func_02045808 0x02045808 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02031140 0x02031140 arm
 *   func_021FA64C 0x021FA64C thumb ov132
 *   func_021FA04C 0x021FA04C thumb ov132
 *   func_021F6F4C 0x021F6F4C thumb ov112
 *   func_021F6C7C 0x021F6C7C thumb ov112
 *   func_021F9E94 0x021F9E94 thumb ov132
 *   func_021F6A24 0x021F6A24 thumb ov112
 *   func_021F7120 0x021F7120 thumb ov112
 *   func_021F51B0 0x021F51B0 thumb ov112
 *   func_021F4948 0x021F4948 thumb ov112
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204ED24 0x0204ED24 arm
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_02049238 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021FA6CC 0x021FA6CC thumb ov132
 *   func_021FABD8 0x021FABD8 thumb ov132
 *   func_021F9ECC 0x021F9ECC thumb ov132
 *   func_021FA064 0x021FA064 thumb ov132
 *   func_021F9ED4 0x021F9ED4 thumb ov132
 *   func_021F9E4C 0x021F9E4C thumb ov132
 *   func_021FAD7C 0x021FAD7C thumb ov132
 *   func_021FCDEC 0x021FCDEC thumb ov132
 *   func_021FCE00 0x021FCE00 thumb ov132
 *   func_021F6F64 0x021F6F64 thumb ov112
 *   func_021F7160 0x021F7160 thumb ov112
 *   func_021F6A58 0x021F6A58 thumb ov112
 *   func_021F51E8 0x021F51E8 thumb ov112
 *   func_021F6CB0 0x021F6CB0 thumb ov112
 *   func_021F6E74 0x021F6E74 thumb ov112
 *   func_021F75A0 0x021F75A0 thumb ov112
 *   func_021F51F4 0x021F51F4 thumb ov112
 *   func_021F718C 0x021F718C thumb ov112
 *   func_021F6F8C 0x021F6F8C thumb ov112
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02047970 0x02047970 arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204F7DC 0x0204F7DC arm
 *   func_0204A648 0x0204A648 arm
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_02006238 0x02006238 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   d_02FFFC3C 0x02FFFC3C data a4
 *   d_021FDE80 0x021FDE80 data a4
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02040588 0x02040588 arm
 *   func_02046440 0x02046440 arm
 *   func_0204044C 0x0204044C arm
 *   func_02046BE0 0x02046BE0 arm
 *   func_02048A24 0x02048A24 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   func_0204EBD4 0x0204EBD4 arm
 *   func_0204ED70 0x0204ED70 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0202223C 0x0202223C thumb
 *   func_02022224 0x02022224 thumb
 *   d_021FDBA0 0x021FDBA0 data a4
 *   d_021FDAA0 0x021FDAA0 data a4
 *   d_021FDB40 0x021FDB40 data a4
 *   d_021FDB60 0x021FDB60 data a4
 *   d_021FDB80 0x021FDB80 data a4
 *   d_021FDAC0 0x021FDAC0 data a4
 *   d_021FDAE0 0x021FDAE0 data a4
 *   d_021FDB00 0x021FDB00 data a4
 *   d_021FDB20 0x021FDB20 data a4
 *   d_021FDAB0 0x021FDAB0 data a4
 *   d_020A1448 0x020A1448 data a4
 *   d_021FDA7C 0x021FDA7C data a4
 *   d_021FDBF8 0x021FDBF8 data a4
 *   d_021FDBD4 0x021FDBD4 data a4
 *   func_02049BDC 0x02049BDC arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02082A60 0x02082A60 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021F6F24 0x021F6F24 thumb ov112
 *   func_02157364  0x02157364  thumb  ov010
 *   func_021F6FB0  0x021F6FB0  thumb  ov112
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_021F5164 0x021F5164 thumb ov112
 *   func_021F5438 0x021F5438 thumb ov112
 *   func_021F48C0 0x021F48C0 thumb ov112
 *   func_021F709C 0x021F709C thumb ov112
 *   func_021F760C 0x021F760C thumb ov112
 *   func_021F8054 0x021F8054 thumb ov112
 *   d_021FDBE0 0x021FDBE0 data a4
 *   func_021F69E4 0x021F69E4 thumb ov112
 *   func_021F9E50 0x021F9E50 thumb ov132
 *   func_021F8044 0x021F8044 thumb ov112
 *   func_021F6F04 0x021F6F04 thumb ov112
 *   func_021F7098 0x021F7098 thumb ov112
 *   func_021F75DC 0x021F75DC thumb ov112
 *   func_021F6AF0 0x021F6AF0 thumb ov112
 *   func_021FA57C 0x021FA57C thumb ov132
 *   func_0203630C 0x0203630C arm
 *   func_02048AFC 0x02048AFC arm
 *   func_02048B44 0x02048B44 arm
 *   func_02040618 0x02040618 arm
 *   d_021FDBEC 0x021FDBEC data a4
 *   _fflt 0x0209BDBC arm
 *   _ffltu 0x0209BE04 arm
 *   _fdiv 0x0209CE10 arm
 *   _fsub 0x0209CB8C arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fgr 0x0209BBB0 arm
 *   _ffix 0x0209C494 arm
 *   func_021FAC74 0x021FAC74 thumb ov132
 *   d_021FDBD0 0x021FDBD0 data a1
 *   func_0204A380 0x0204A380 arm
 *   func_021FAD0C 0x021FAD0C thumb ov132
 *   d_020A1B38 0x020A1B38 data a2
 *   func_02061CA4 0x02061CA4 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045C44 0x02045C44 arm
 *   func_02049B40 0x02049B40 arm
 *   func_0203101C 0x0203101C arm
 *   func_0201C440 0x0201C440 thumb
 *   func_020310C4 0x020310C4 arm
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_021FA558 0x021FA558 thumb ov132
 *   func_021FA56C 0x021FA56C thumb ov132
 *   func_02006448  0x02006448  thumb
 *   func_020064F4  0x020064F4  thumb
 *   func_020064B8  0x020064B8  thumb
 *   func_02005D90  0x02005D90  thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021F7A80 0x021F7A80 thumb ov112
 *   func_021FD8C4 0x021FD8C4 thumb ov132
 *   func_021F79A8 0x021F79A8 thumb ov112
 *   func_02005728 0x02005728 thumb
 *   func_021FD9FC 0x021FD9FC thumb ov132
 *   func_021FD9A0 0x021FD9A0 thumb ov132
 *   func_021FDA18 0x021FDA18 thumb ov132
 *   func_021FD9D0 0x021FD9D0 thumb ov132
 *   func_0203D378 0x0203D378 arm
 *   func_021FDA24 0x021FDA24 thumb ov132
 *   func_021F5140 0x021F5140 thumb ov112
 *   func_02157394 0x02157394 thumb ov010
 *   func_021FD974 0x021FD974 thumb ov132
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ll_mul 0x0209C054 arm
 *   _ull_mul 0x0209C054 arm
 *   func_021F9EDC  0x021F9EDC  thumb
 *   func_021F9F58  0x021F9F58  thumb
 *   func_021F9F74 0x021F9F74 thumb ov132
 *   func_021FAAB8  0x021FAAB8  thumb
 *   func_021F4F10 0x021F4F10 thumb ov112
 */
#include "../../matched/include/Obj00675.h"
#include "../../matched/include/Obj00191.h"
#include "../../matched/include/Obj23177.h"
#include "../../matched/include/Obj23178.h"
#include "../../matched/include/Obj00503.h"
#include "../../matched/include/Obj14083.h"
#include "../../matched/include/Obj23181.h"
#include "../../matched/include/Obj01410.h"
#include "../../matched/include/Obj10530.h"
#include "../../matched/include/Obj14084.h"
#include "../../matched/include/Obj08150.h"
#include "../../matched/include/Obj05397.h"
#include "../../matched/include/Obj10531.h"
#include "../../matched/include/Obj01257.h"
#include "../../matched/include/Obj23182.h"
#include "../../matched/include/Obj23183.h"
#include "../../matched/include/Obj02849.h"
#include "../../matched/include/Obj00832.h"
#include "../../matched/include/Obj03817.h"
#include "../../matched/include/Obj10532.h"
#include "../../matched/include/Obj23184.h"
#include "../../matched/include/Obj10533.h"
#include "../../matched/include/Obj23185.h"
#include "../../matched/include/Obj23186.h"
#include "../../matched/include/Obj23187.h"
#include "../../matched/include/Obj23188.h"
#include "../../matched/include/Obj23189.h"
#include "../../matched/include/Obj23190.h"
#include "../../matched/include/Obj08153.h"
#include "../../matched/include/Obj14085.h"
#include "../../matched/include/Obj08155.h"
#include "../../matched/include/Obj00159.h"
#include "../../matched/include/Obj10534.h"
#include "../../matched/include/Obj23204.h"
#include "../../matched/include/Obj08154.h"
#include "../../matched/include/Obj03287.h"
#include "../../matched/include/Obj14086.h"
#include "../../matched/include/Obj14087.h"
#include "../../matched/include/Obj14088.h"
#include "../../matched/include/Obj23210.h"
#include "../../matched/include/Obj23211.h"
#include "../../matched/include/Obj23212.h"
#include "../../matched/include/Obj23213.h"
#include "../../matched/include/Obj23214.h"
#include "../../matched/include/Obj23215.h"
#include "../../matched/include/Obj23216.h"
#include "../../matched/include/Obj23217.h"
#include "../../matched/include/Obj23218.h"
#include "../../matched/include/Obj23219.h"
#include "../../matched/include/Obj23220.h"
#include "../../matched/include/Obj23221.h"

#define FX(x) ((int)(((x) > 0) ? ((x) * 4096.0f + 0.5f) : ((x) * 4096.0f - 0.5f)))
struct Descriptor;
struct Node;
struct PrintSys;
struct Rec;
struct S02031140;
struct U16Vec;
struct Board;
struct Camera;
struct Lights;
struct BgTemplate;
struct Blk3;
struct Cfg;
struct DispConfig;
struct DispVram;
struct Light;
struct Object;
struct GfFont;
struct MsgBank;
struct Tcbl;
struct Rec3;
struct CharBuf;
typedef unsigned int u32_021F8480;

typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32_021F8640;

typedef unsigned u32_021F879C;

typedef unsigned u32_021F899C;

typedef int BOOL;

typedef struct { u32_021F899C w[3]; } Vec3;

typedef struct { Vec3 a,b,c; } Vectors;

typedef struct { u32_021F899C w[7]; } Blob28;

typedef enum { MAIN_SUB=0,SUB_MAIN=1 } GXDispSelect;

typedef unsigned int u32_021F8BD4;

typedef unsigned int   u32;

typedef signed int     s32;

typedef short s16_021F8D88;

struct Vec { int x, y, z; };

struct Slots { u8 pad[0x44]; void *slots[4]; };

typedef struct Object Object;

typedef signed short s16_021F8DC4;

typedef struct { int x, y, z; } Vec;

struct Bytes { u8 a, b, c, d; };

typedef signed char s8;

typedef struct {
    u8 pad[0x168];
    u16 phase;
    u16 base[16];
    s8 dr[16];
    s8 dg[16];
    s8 db[16];
    u16 out[16];
} Fade;

typedef enum { ZERO } Zero;

typedef signed short s16;

typedef enum { ENABLED = 1 } Enabled;

typedef unsigned long long u64;

typedef enum { ACTION7 = 7, ACTION8 = 8 } Action;

extern void *func_02030734(u32_021F8480 heapId, u32_021F8480 size, int clear, const char *site, u16 tag);
extern void *func_020056A0(void (*)(void),void *,u32_021F8480);
extern u32_021F8480 func_021FD8D4(char *p);
extern void *func_020490F4(u32_021F8480 id, u32_021F8480 heap);
extern void *func_021F6BD8(u16,void *);
extern char *func_021F9FEC(u32_021F8480,void *,u32_021F8480);
extern char *func_021FA5B0(u32_021F8480,void *,char *);
extern void *func_021FAAF4(u32_021F8480,void *);
extern void func_0203D34C(u32_021F8480,u32_021F8480);
extern void func_02005D28(void);
extern void func_02006504(void);
extern void func_02006518(void);
extern void func_0207D534(volatile u16 *,int);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_021FAB58(char *);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32_021F8640 func_02045C04(struct Rec *rec);
extern u32_021F8640 func_020452E8(struct Descriptor *d);
extern u32_021F8640 func_0201D83C(void *ptr);
extern void func_02031140(struct S02031140 *p);
extern void func_021FA64C(char *);
extern void func_021FA04C(u8 *p);
extern void func_021F6F4C(u8 *p);
extern void func_021F6C7C(char *p);
extern void func_021F9E94(u8 *p);
extern void func_021F6A24(char *p);
extern void func_021F7120(char *p);
extern void func_021F51B0(int a);
extern void func_021F4948(u8 *p);
extern void func_0204A5AC(void);
extern void func_0204ED24(void *);
extern u32_021F8640 func_02048AC4(void *ptr);
extern void func_02046788(void);
extern void func_020403F4(u32_021F8640);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02030EAC(struct Node *n);
extern void func_02049238(void *);
extern u32_021F8640 func_020307B0(void *p);
extern void func_0202208C(void *,u32_021F879C,u32_021F879C,u32_021F879C,u32_021F879C,u32_021F879C,u32_021F879C);
extern u32_021F879C func_020221A4(void);
extern u32_021F879C func_0200FB24(void);
extern int func_02006238(void);
extern void func_021FCDEC(int,int);
extern int func_021FCE00(char *p, int id);
extern u8 func_021FAD7C(char *);
extern void func_021FA6CC(char *p);
extern void func_021FABD8(char *p);
extern int func_021F9ECC(u8 *a0);
extern void func_021FA064(char *p);
extern int func_021F9ED4(u8 *a0);
extern void func_021F9E4C(u8 *);
extern void func_021F6F64(u8 *);
extern void func_021F7160(u8 *);
extern void func_021F6A58(char *p);
extern void func_021F51E8(u8 *);
extern void func_021F6CB0(char *p);
extern void func_021F6E74(u8 *);
extern void func_021F75A0(u8 *);
extern void func_021F51F4(void **p);
extern void func_021F718C(char *p);
extern void func_021F6F8C(u8 *);
extern void func_02047964(void);
extern void func_020479D8(void);
extern void func_02047970(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_0204F7DC(struct Board *b, struct Camera *cam, struct Lights *lights);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0202223C(u32_021F899C,u32_021F899C);
extern u32_021F899C func_02022224(void *);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_02046440(u32_021F899C,u32_021F899C,u32_021F899C,u32_021F899C,u16,u16,void (*)(void));
extern void func_0204044C(u32_021F899C);
extern void func_02046BE0(u32_021F899C,u32_021F899C);
extern void *func_02048A24(u32_021F899C,u32_021F899C,u32_021F899C,u32_021F899C,u32_021F899C,u32_021F899C,u32_021F899C,u32_021F899C,const Vec3 *,const Vec3 *,const Vec3 *,u16);
extern void func_02048AD0(struct Light *l);
extern void func_0207DCF8(const void *);
extern void *func_0204EBD4(u8 *src, void *heap);
extern void func_0204ED70(u8 *dst, struct Blk3 *src);
extern void func_0204A48C(const struct Cfg *cfg, u32_021F899C arg, u32_021F899C heapId);
extern void func_02049BDC(void *a0, u32_021F8BD4 a1, u32_021F8BD4 a2, u32_021F8BD4 a3, u32_021F8BD4 a4, u32_021F8BD4 a5, u16 a6);
extern u32_021F8BD4 func_02049658(void *a, u32_021F8BD4 b, u32_021F8BD4 c, u32_021F8BD4 d, u32_021F8BD4 e, u32_021F8BD4 f, u16 g);
extern void func_020498F4(void *a, u32_021F8BD4 b, u32_021F8BD4 c, u32_021F8BD4 d, u32_021F8BD4 e, u32_021F8BD4 f, u16 g);
extern void func_02049B68(void *a, u32_021F8BD4 b, u32_021F8BD4 c, u32_021F8BD4 d, u32_021F8BD4 e, u16 f);
extern void func_02082A60(const void *,void *,u32_021F8BD4);
extern void func_020409B4(u32_021F8BD4);
extern u8 *func_021F6F24(u32_021F8BD4 heap, u32_021F8BD4 v);
extern u8 func_02157364(char *a0);
extern void func_021F6FB0(void *, int);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32);
extern void func_020414AC(u32);
extern void *func_021F5164(u32);
extern void func_021F5438(void **p, int b);
extern struct Object *func_021F48C0(u32 owner, int count, u16 heap);
extern u8 *func_021F709C(u16 heap, u32 b, u32 c, u32 d, u32 e);
extern void *func_021F760C(void *,void *);
extern void func_021F8054(void *unused, u32 *p, const u32 *q);
extern Object *func_021F69E4(u16,void *);
extern char *func_021F9E50(unsigned);
extern u32 func_0203630C(void);
extern void func_021F8044(void *unused, u32 *p, u32 *q);
extern void func_021F6F04(void *, void *, Vec *);
extern void func_021F7098(u8 *p, u16 v);
extern void func_021F75DC(u8 *p, u16 v);
extern void func_021F6AF0(void *, u16);
extern void func_021FA57C(void *unused, int x);
extern void func_02048AFC(void *, const Vec *);
extern void func_02048B44(void *, const Vec *);
extern void func_02040618(u32, u32, u32);
extern void *func_021FAC74(char *p, void *arg, int flag);
extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern char *func_021FAD0C(char *p, char *base, unsigned index, unsigned char flag);
extern int func_02061CA4(void *, u32, u32, int);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045C44(const void *file, u32 heapId);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_0201C440(void *);
extern void func_020310C4(struct Tcbl *p);
extern unsigned func_0201CE30(void *);
extern void func_0201CE48(struct Rec3 *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_0201CCE4(void *, u32, u32, void *, void *, u32, void *, u32, u16, u32);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_021FA558(char *, int, int);
extern void func_021FA56C(char *, u8);
extern int func_02006448(u32 a0, u32 a1, u32 a2);
extern void func_020064F4(u32 a);
extern int func_020064B8(u32, u32, u32, u32);
extern void func_02005D90(int, int);
extern void func_020061E4(u32 a);
extern int func_021F7A80(char *,char *);
extern int func_021FD8C4(void *, int);
extern void func_021F79A8(char *, char *, int);
extern u32 func_02005728(u32);
extern int func_021FD9FC(char *p);
extern int func_021FD9A0(void *, unsigned);
extern void func_021FDA18(unsigned char *p);
extern void func_021FD9D0(unsigned char *p, unsigned char key);
extern u32 func_0203D378(void);
extern void func_021FDA24(void *, u32, u32, u32);
extern unsigned char func_021F5140(void *p, int i);
extern u16 func_02157394(int a0, int a1);
extern void func_021FD974(char *p, u32 key, u8 value);
extern u32 func_0203F0A8(void);
extern char *func_021F9EDC(char *p, u32 a);
extern void func_021F9F58(u8 *unused, u8 *p);
extern void func_021F9F74(char *, unsigned, const int *);
extern void func_021FAAB8(char *p, unsigned flag);
extern u32 func_021F4F10(u8 *);
u8 *func_021F8480(u8 *input, int heap);
void func_021F8640(char *p);
int func_021F879C(u8 *p);
void func_021F8994(void);
void func_021F899C(u8 *p);
void func_021F8BD4(u8 *p);
void func_021F8D88(u8 *p, u32 a1);
void func_021F8DA0(const struct BgTemplate *p,u32 id,u32 type);
void func_021F8DC4(u8 *p);
void func_021F8E58(char *p);
void func_021F8E88(char *p);
void func_021F8EA8(u8 *p);
void func_021F90E0(u8 *p);
void func_021F9140(u8 *p, u8 n, u8 i);
void func_021F91A8(char *p, u8 n, u8 mask);
void func_021F91CC(Fade *p);
void func_021F92CC(u8 *p);
void func_021F9374(u8 *p);
void func_021F93D8(u8 *p, u16 index, u32 speed);
void func_021F94B0(u8 *p);
void func_021F94F8(char *p);
void func_021F95CC(char *p, u8 v, int c);
void func_021F95E8(char *p);
void func_021F95F0(u8 *p);
void func_021F9664(char *p, int a);
void func_021F9680(char *p, int a);
void func_021F9690(char *p);
int func_021F969C(char *p, u32 a, u32 b, u32 d);
void func_021F96B0(char *p, int a);
void func_021F96C4(char *p);
void func_021F96D0(char *p);
void func_021F9730(char *p,int value);
void func_021F9754(char *p, u32 i, int v);
int func_021F9768(char *p);
int func_021F9774(char *p,u32 i);
void func_021F9794(char *p);
int func_021F99F4(char *p, unsigned i, unsigned j);
void func_021F9A48(char *p);
void func_021F9AD8(char *p, int mode, u8 slot);
void func_021F9CF4(char *p);
void func_021F9D08(char *p);
void func_021F9D18(char *p, unsigned i);
void func_021F9D80(char *p);
void func_021F9D90(char *p);
void *func_021F9DA0(char *p);
void *func_021F9DA4(char *p,u32 i);
void *func_021F9DAC(void *p);
u32 *func_021F9DB0(void *p,u8 i);
void func_021F9DB8(void *p,void *v,u32 i);
void *func_021F9DC0(void *p);
void *func_021F9DC4(void *p,u8 i);
void func_021F9DCC(void *p,void *v,u32 i);
void *func_021F9DD4(void *p);
void *func_021F9DDC(void *p,u8 i);
void func_021F9DE8(void *p,void *v,u8 i);
void *func_021F9DF4(void *p);
u16 func_021F9DFC(void *p);
void func_021F9E00(void *p,u16 v);
u16 func_021F9E04(u8 *p);
void func_021F9E08(u8 *p,u16 v);
u32 func_021F9E0C(u8 *p);
int func_021F9E18(char *p);
extern const char d_021FDCA0[];
extern u32_021F8480 g_02FFFC3C;
extern u32_021F879C d_02FFFC3C;
extern u32_021F879C d_021FDE80;
extern const Vectors d_021FDA7C;
extern const Blob28 d_021FDBF8;
extern const Vec3 d_021FDBD4;
extern const u32_021F899C d_021FDBA0[];
extern const u32_021F899C d_021FDAA0[];
extern const u32_021F899C d_021FDB40[];
extern const u32_021F899C d_021FDB60[];
extern const u32_021F899C d_021FDB80[];
extern const u32_021F899C d_021FDAC0[];
extern const u32_021F899C d_021FDAE0[];
extern const u32_021F899C d_021FDB00[];
extern const u32_021F899C d_021FDB20[];
extern const u32_021F899C d_021FDAB0[];
extern const u32_021F899C d_020A1448[];
extern const struct Vec d_021FDBE0;
extern const Vec d_021FDBEC;
extern const struct Bytes d_021FDBD0;
extern const s16_021F8DC4 d_020A1B38[];



u8 *func_021F8480(u8 *input, int heap)
{
    u8 *p;
    u8 i;
    p=func_02030734(heap,0x1f0,1,d_021FDCA0,0x11a);
    *(u16 *)p=heap;
    *(void **)(p+0x30)=input;
    i=0;
    *(u16 *)(p+2)=0;
    *(u16 *)(p+4)=127;
    *(u16 *)(p+6)=128;
    *(u16 *)(p+8)=0;
    *(u32_021F8480 *)(p+0xb4)=0;
    *(u32_021F8480 *)(p+0x1c)=0;
    *(u32_021F8480 *)(p+0x164)=0;
    *(u32_021F8480 *)(p+0xc)=1;
    *(u32_021F8480 *)(p+0x14)=0;
    *(u32_021F8480 *)(p+0x10)=0;
    *(u32_021F8480 *)(p+0x24)=0;
    *(u32_021F8480 *)(p+0x28)=0;
    *(u32_021F8480 *)(p+0x2c)=0;
    *(void **)(p+0x20)=func_020056A0(func_021F8994,p,64);
    if(**(u32_021F8480 **)(p+0x30)==0){
        for(;i<4;i++){
            if(**(u32_021F8480 **)(*(u8 **)(p+0x30)+4+i*4)==0){p[0xa]=i;break;}
        }
        if(i==4)p[0xa]=1;
    }else p[0xa]=func_021FD8D4((void *)**(u32_021F8480 **)(p+0x30));
    for(i=0;i<4;i++)p[0xf7+i]=0;
    func_021F95F0(p);
    *(u32_021F8480 *)(p+0xec)=1;
    p[0xf0]=4;
    p[0xf1]=4;
    p[0xf2]=4;
    p[0x11c]=4;
    *(u16 *)(p+0x11e)=0;
    *(u32_021F8480 *)(p+0x15c)=0;
    *(u16 *)(p+0x168)=0;
    for(i=0;i<4;i++){
        *(u32_021F8480 *)(p+0xfc+i*4)=0;
        *(u16 *)(p+0x124+i*2)=0;
        *(u32_021F8480 *)(p+0x13c+i*8)=0;
        *(u32_021F8480 *)(p+0x140+i*8)=0;
    }
    *(void **)(p+0x18)=func_020490F4(47,*(u16 *)p);
    func_021F899C(p);
    func_021F8BD4(p);
    func_021F92CC(p);
    func_021F8DC4(p);
    func_021F8E58((char *)p);
    func_021F8E88((char *)p);
    *(void **)(p+0x90)=func_021F6BD8(*(u16 *)p,p);
    *(void **)(p+0xb8)=func_021F9FEC(*(u16 *)p,p,*(u32_021F8480 *)(p+0x30));
    *(void **)(p+0xa4)=func_021FA5B0(*(u16 *)p,p,*(char **)(*(u8 **)(p+0x30)+p[0xa]*4+4));
    *(void **)(p+0xb0)=func_021FAAF4(*(u16 *)p,p);
    func_021F9CF4((char *)p);
    func_0203D34C(0,*(u16 *)p);
    func_021F8D88(p,0);
    *(u32_021F8480 *)(p+0x1dc)=*(u32_021F8480 *)((*(u8 ***)(p+0x30))[6]+0x14);
    *(u32_021F8480 *)(p+0x1e0)=*(u32_021F8480 *)((*(u8 ***)(p+0x30))[6]+0x18);
    *(u32_021F8480 *)(p+0x1e4)=*(u32_021F8480 *)((*(u8 ***)(p+0x30))[6]+0x1c);
    *(u32_021F8480 *)(p+0x1ec)=g_02FFFC3C;
    return p;
}



/*
 * volatile: hardware display register 0x04000000 read at 0x021F868C.
 */
void func_021F8640(char *p)
{
    if(((struct Obj00675 *)p)->f2C==1)func_02005D28();
    if(((struct Obj00675 *)p)->f28==1)func_02006504();
    if(((struct Obj00675 *)p)->f24==1)func_02006518();
    func_0207D534((volatile u16 *)0x0400006c,-16);
    func_0207D534((volatile u16 *)0x0400106c,-16);
    func_0207D63C((void *)0x04000050,0,0,31,31);
    *(volatile u32_021F8640 *)0x04000000 &= 0xffff1fff;
    func_021F9D08(p);
    func_021FAB58(((struct Obj00675 *)p)->fB0);
    if(((struct Obj00675 *)p)->fE0!=0)func_02045808(((struct Obj00675 *)p)->fE0);
    func_0201C6EC(((struct Obj00675 *)p)->fE8);
    func_0201C4C0(((struct Obj00675 *)p)->fE8);
    func_02045C04(((struct Obj00675 *)p)->fDC);
    func_020452E8(((struct Obj00675 *)p)->fD0);
    func_0201D83C(((struct Obj00675 *)p)->fD4);
    func_02031140(((struct Obj00675 *)p)->fCC);
    func_021FA64C(*(char * *)&((struct Obj00675 *)p)->fA4);
    func_021FA04C(((struct Obj00675 *)p)->fB8);
    func_021F6F4C(((struct Obj00675 *)p)->f3C);
    func_021F6C7C(((struct Obj00675 *)p)->f90);
    func_021F9E94(((struct Obj00675 *)p)->f6C);
    func_021F6A24(((struct Obj00675 *)p)->f54);
    func_021F7120(((struct Obj00675 *)p)->f40);
    func_021F51B0((int)(((struct Obj00675 *)p)->f34));
    func_021F4948(((struct Obj00675 *)p)->f38);
    func_0204A5AC();
    func_0204ED24(((struct Obj00675 *)p)->fAC);
    func_02048AC4(((struct Obj00675 *)p)->fA8);
    func_02046788();
    func_020403F4(0);
    func_020403F4(1);
    func_020403F4(2);
    func_020403F4(3);
    func_020403F4(5);
    func_020403F4(7);
    func_020450C8();
    func_0203F9B4();
    func_02030EAC(((struct Obj00675 *)p)->f20);
    func_02049238(((struct Obj00675 *)p)->f18);
    func_020307B0(p);
}



/*
 * extent: lead followed by 021F8994 tail-call stub.
 * note: 021F6E74 retains the explicitly loaded pointer despite own void prototype.
 */
int func_021F879C(u8 *p)
{
    u32_021F879C tick;
    tick=d_02FFFC3C;
    ((struct Obj00191 *)p)->f1E8=tick-((struct Obj00191 *)p)->f1EC;
    ((struct Obj00191 *)p)->f1EC=tick;
    switch(((struct Obj00191 *)p)->f1C) {
    case 0:
        func_0202208C(0,1,1,0,6,1,((struct Obj00191 *)p)->f0);
        ((struct Obj00191 *)p)->f1C=1;
        break;
    case 1:
        if(func_020221A4()==1) {
            if(**(u32_021F879C * *)&((struct Obj00191 *)p)->f30!=0) {
                ((struct Obj00191 *)p)->f1C=7;
                func_021FCDEC(**(int * *)&((struct Obj00191 *)p)->f30,200);
            } else ((struct Obj00191 *)p)->f1C=4;
        }
        break;
    case 2:
        if(func_02006238()==0) {
            func_0202208C(0,0,0,0,6,1,((struct Obj00191 *)p)->f0);
            ((struct Obj00191 *)p)->f1C=3;
        }
        break;
    case 3:
        if(func_020221A4()==1) return 1;
        break;
    case 4:
        if((((struct Obj00191 *)p)->f2)++ >=60) ((struct Obj00191 *)p)->f1C=5;
        break;
    case 5:
        if(((struct Obj00191 *)p)->f164==0) {
            ((struct Obj00191 *)p)->fB4=((struct Obj23178 *)(*(u8 * *)&((struct Obj23177 *)(*(u8 * *)&((struct Obj00191 *)p)->f30))->f18))->fC;
            func_021F90E0(p);
            ((struct Obj00191 *)p)->f1C=6;
        }
        break;
    case 6:
        if(func_021FAD7C(*(char * *)&((struct Obj00191 *)p)->fB0)==0) {
            ((struct Obj00191 *)p)->fB4=0;
            if(((struct Obj00191 *)p)->f164==0) ((struct Obj00191 *)p)->f1C=2;
            else ((struct Obj00191 *)p)->f1C=255;
        }
        break;
    case 7:
        if(func_021FCE00(*(void **)*(u8 * *)&((struct Obj00191 *)p)->f30,200)==1)
            ((struct Obj00191 *)p)->f1C=4;
        break;
    }
    func_021F8EA8(p);
    func_021FA6CC((char *)(*(u8 * *)&((struct Obj00191 *)p)->fA4));
    func_021F9794((char *)p);
    if(d_021FDE80==0) func_021FABD8((char *)(*(u8 * *)&((struct Obj00191 *)p)->fB0));
    func_021F6F64(*(u8 * *)&((struct Obj00191 *)p)->f3C);
    func_021F7160(*(u8 * *)&((struct Obj00191 *)p)->f40);
    func_021F6A58((char *)(*(u8 * *)&((struct Obj00191 *)p)->f54));
    func_021F9ECC(*(u8 * *)&((struct Obj00191 *)p)->f6C);
    func_021F9374(p);
    func_021F51E8(*(u8 * *)&((struct Obj00191 *)p)->f34);
    func_021F6CB0((char *)(*(u8 * *)&((struct Obj00191 *)p)->f90));
    func_021F94F8((char *)p);
    func_021FA064((char *)(*(u8 * *)&((struct Obj00191 *)p)->fB8));
    func_021F91CC((Fade *)p);
    func_02047964(); func_020479D8();
    func_021F6E74(*(u8 * *)&((struct Obj00191 *)p)->f90);
    func_021F75A0(*(u8 * *)&((struct Obj00191 *)p)->f40);
    func_021F51F4((void **)(*(u8 * *)&((struct Obj00191 *)p)->f34));
    func_021F718C((char *)(*(u8 * *)&((struct Obj00191 *)p)->f40));
    func_021F6F8C(*(u8 * *)&((struct Obj00191 *)p)->f3C);
    func_0204F7DC(((struct Obj00191 *)p)->fAC,((struct Obj00191 *)p)->fA8,0);
    func_021F9ED4(*(u8 * *)&((struct Obj00191 *)p)->f6C);
    func_021F9E4C(p);
    func_02047970(); func_0204A600();
    if(**(u32_021F879C * *)&((struct Obj00191 *)p)->f30!=0 && ((struct Obj00191 *)p)->f1C!=0 &&
       ((struct Obj00191 *)p)->f1C!=1 && ((struct Obj00191 *)p)->f1C!=2 &&
       ((struct Obj00191 *)p)->f1C!=3 && func_0200FB24()!=0)
        ((struct Obj00191 *)p)->f1C=2;
    return 0;
}



void func_021F8994(void) { func_0204A648(); }



static inline void GX_SetVisiblePlane(int plane) { *(volatile u32_021F899C *)0x04000000=(*(volatile u32_021F899C *)0x04000000&~0x1F00u)|((u32_021F899C)plane<<8); }



static inline void GXS_SetVisiblePlane(int plane) { *(volatile u32_021F899C *)0x04001000=(*(volatile u32_021F899C *)0x04001000&~0x1F00u)|((u32_021F899C)plane<<8); }



static inline void GX_SetDispSelect(GXDispSelect sel) { *(volatile u16 *)0x04000304=(u16)((*(volatile u16 *)0x04000304&~0x8000u)|(sel<<15)); }



static inline void G3X_EdgeMarking(BOOL enable) { if(enable) *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060&~0x3000u)|0x20); else *(volatile u16 *)0x04000060&=(u16)~0x3020; }



static inline void G3X_AntiAlias(BOOL enable) { if(enable) *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060&~0x3000u)|0x10); else *(volatile u16 *)0x04000060&=(u16)~0x3010; }



static inline void G3X_AlphaBlend(BOOL enable) { if(enable) *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060&~0x3000u)|8); else *(volatile u16 *)0x04000060&=(u16)~0x3008; }



static inline void GX_SetVisibleWnd(int window) { *(volatile u32_021F899C *)0x04000000=(*(volatile u32_021F899C *)0x04000000&~0xE000u)|((u32_021F899C)window<<13); }



static inline void G2_SetWndOBJInsidePlane(int wnd,BOOL effect) { u32_021F899C tmp; tmp=(*(volatile u16 *)0x0400004A&~0x3F00u)|((u32_021F899C)wnd<<8); if(effect) tmp|=0x2000; *(volatile u16 *)0x0400004A=(u16)tmp; }



static inline void G2_SetWndOutsidePlane(int wnd,BOOL effect) { u32_021F899C tmp; tmp=(*(volatile u16 *)0x0400004A&~0x3Fu)|(u32_021F899C)wnd; if(effect) tmp|=0x20; *(volatile u16 *)0x0400004A=(u16)tmp; }



void func_021F899C(u8 *p)
{
    Blob28 big;
    Vec3 small;
    void *light,*board;
    func_020434CC(); func_02043588();
    GX_SetVisiblePlane(0); GXS_SetVisiblePlane(0);
    func_0202223C(0,0); func_0202223C(1,0);
    func_02022224(0); func_02022224((void *)1);
    GX_SetDispSelect(SUB_MAIN);
    func_020433E0((const struct DispVram *)d_021FDBA0);
    func_0203F8F4(*(u16 *)p); func_02045088(*(u16 *)p);
    func_0203FC28((struct DispConfig *)d_021FDAA0);
    func_021F8DA0((const struct BgTemplate *)d_021FDB40,1,0);
    func_021F8DA0((const struct BgTemplate *)d_021FDB60,2,0);
    func_021F8DA0((const struct BgTemplate *)d_021FDB80,3,0);
    func_021F8DA0((const struct BgTemplate *)d_021FDAC0,5,0);
    func_021F8DA0((const struct BgTemplate *)d_021FDAE0,6,0);
    func_021F8DA0((const struct BgTemplate *)d_021FDB00,4,0);
    func_021F8DA0((const struct BgTemplate *)d_021FDB20,7,0);
    func_02040588(0,1);
    func_02046440(0,2,0,4,0,*(u16 *)p,0);
    func_0204044C(3);
    func_02046BE0(0,1);
    light=func_02048A24(2,0xC000,0,0,0x10000,0x1000,0x3E8000,0,&d_021FDA7C.c,&d_021FDA7C.a,&d_021FDA7C.b,*(u16 *)p);
    *(void **)(p+0xA8)=light;
    func_02048AD0(light);
    func_0207DCF8(d_021FDAB0);
    G3X_EdgeMarking(0); G3X_AntiAlias(1); G3X_AlphaBlend(1);
    func_02046BE0(0,0);
    big=d_021FDBF8;
    small=d_021FDBD4;
    board=func_0204EBD4((u8 *)(&big),(void *)(u32_021F899C)*(u16 *)p);
    *(void **)(p+0xAC)=board;
    func_0204ED70(board,(struct Blk3 *)(&small));
    func_0204A48C((const struct Cfg *)d_020A1448,(u32_021F899C)d_021FDBA0,*(u16 *)p);
    func_020434DC(16,1); func_02043598(16,1);
    func_0207D63C((void *)0x04000050,8,1,0,10);
    GX_SetVisibleWnd(4);
    G2_SetWndOBJInsidePlane(23,1);
    G2_SetWndOutsidePlane(31,1);
}



void func_021F8BD4(u8 *p)
{
    u16 palette[16];
    u8 i=0;
    u16 old,new;
    func_02049BDC((void *)(((struct Obj00503 *)p)->f18),2,0,32,32,32,((struct Obj00503 *)p)->f0);
    func_02049658((void *)(((struct Obj00503 *)p)->f18),8,3,0,0,0,((struct Obj00503 *)p)->f0);
    func_020498F4((void *)(((struct Obj00503 *)p)->f18),14,3,0,0,0,((struct Obj00503 *)p)->f0);
    func_02049BDC((void *)(((struct Obj00503 *)p)->f18),3,0,0,0,32,((struct Obj00503 *)p)->f0);
    func_02049658((void *)(((struct Obj00503 *)p)->f18),9,2,0,0,0,((struct Obj00503 *)p)->f0);
    func_020498F4((void *)(((struct Obj00503 *)p)->f18),15,2,0,0,0,((struct Obj00503 *)p)->f0);
    func_02049B68((void *)(((struct Obj00503 *)p)->f18),5,4,0,0,((struct Obj00503 *)p)->f0);
    func_02049658((void *)(((struct Obj00503 *)p)->f18),13,5,0,0,0,((struct Obj00503 *)p)->f0);
    func_020498F4((void *)(((struct Obj00503 *)p)->f18),17,5,0,0,0,((struct Obj00503 *)p)->f0);
    func_02049658((void *)(((struct Obj00503 *)p)->f18),12,6,0,0,0,((struct Obj00503 *)p)->f0);
    func_020498F4((void *)(((struct Obj00503 *)p)->f18),16,6,0,0,0,((struct Obj00503 *)p)->f0);
    func_02049658((void *)(((struct Obj00503 *)p)->f18),11,4,0,0,0,((struct Obj00503 *)p)->f0);
    func_02082A60((void *)0x05000400,p+0x16a,32);
    func_02082A60((void *)0x05000420,palette,32);
    for(i=0;i<16;i++){
        old=*(u16 *)(p+0x16a+i*2);
        new=palette[i];
        p[0x18a+i]=(u8)(new&31)-(u8)(old&31);
        p[0x19a+i]=(u8)((new&0x3e0)>>5)-(u8)((old&0x3e0)>>5);
        p[0x1aa+i]=(u8)((new&0x7c00)>>10)-(u8)((old&0x7c00)>>10);
    }
    func_020409B4(3);
    func_020409B4(5);
    ((struct Obj00503 *)p)->f3C=func_021F6F24(((struct Obj00503 *)p)->f0,(u32_021F8BD4)p);
}






/*
 * Unblocked by matching func_02157364 (ov010, EXACT, Thumb): the +0008 call
 * site now attests as `matched`. ov009 holds ARM code at that address; ov010
 * is the coherent Thumb leaf, so the declaration is thumb/ov010 (the earlier
 * `arm` was wrong).
 *
 * Addresses are Black-image addresses.
 */
void func_021F8D88(u8 *p, u32 a1)
{
    int v = func_02157364(((struct Obj23181 *)((u8 *)((struct Obj14083 *)p)->f30))->f14);
    func_021F6FB0(((struct Obj14083 *)p)->f3C, v);
}





void func_021F8DA0(const struct BgTemplate *p,u32 id,u32 type) { func_0203FCA0(id,p,type); func_02040588(id,1); func_020414AC(id); func_020409B4(id); }





void func_021F8DC4(u8 *p)
{
    struct Vec pos;
    u8 i;
    pos = d_021FDBE0;
    ((struct Obj01410 *)p)->f34=func_021F5164(((struct Obj01410 *)p)->f0);
    func_021F5438(((struct Obj01410 *)p)->f34,0x20000);
    ((struct Obj01410 *)p)->f38=func_021F48C0(((struct Obj01410 *)p)->fAC,36,((struct Obj01410 *)p)->f0);
    ((struct Obj01410 *)p)->f40=func_021F709C(((struct Obj01410 *)p)->f0,(u32)p,(u32)(((struct Obj01410 *)p)->f34),(u32)(((struct Obj01410 *)p)->f38),((struct Obj01410 *)p)->fAC);
    for (i=0;i<4;i++) *(u32 *)(p+0x44+i*4)=0;
    for (i=0;i<4;i++) {
        ((struct Slots *)p)->slots[i]=func_021F760C(((struct Obj01410 *)p)->f40,*(void **)(*(u8 * *)&((struct Obj01410 *)p)->f30+4+i*4));
        func_021F8054(((struct Obj01410 *)p)->f40,((struct Slots *)p)->slots[i],(const u32 *)(&pos));
        pos.z-=0x1e000;
    }
}





void func_021F8E58(char *p){int tmp[3]={0};int i;for(i=0;i<5;i++)*(int *)((u32)p+i*4+0x58)=0;*(Object * *)&((struct Obj10530 *)p)->f54=func_021F69E4(((struct Obj10530 *)p)->f0,((struct Obj10530 *)p)->fAC);}





void func_021F8E88(char *p){int i;*(char * *)&((struct Obj14084 *)p)->f6C=func_021F9E50(((struct Obj14084 *)p)->f0);for(i=0;i<8;i++)*(int *)((u32)p+i*4+0x70)=0;}





/*
 * blocker C (read-only root show):
 *   void func_02048AFC(char *p, const Vec *v) { *(Vec *)(p + 0x20) = *v; }
 *   void func_02048B44(char *p, const Vec *v) { *(Vec *)(p + 0x38) = *v; }
 */
void func_021F8EA8(u8 *p)
{
    Vec v;
    s16_021F8DC4 target;
    u8 index;
    if (func_0203630C() & 16) {
        if (*(u16 *)(p + 6) + 2 < 256) *(u16 *)(p + 6) = *(u16 *)(p + 6) + 2;
        else *(u16 *)(p + 6) = 256;
    }
    if (func_0203630C() & 32) {
        if (*(u16 *)(p + 6) - 2 > 0) *(u16 *)(p + 6) = *(u16 *)(p + 6) - 2;
        else *(u16 *)(p + 6) = 0;
    }
    if (!(func_0203630C() & 48) && !*(int *)(p + 0x14) && !*(int *)(p + 0x10) && !*(int *)(p + 0xC)) {
        if (*(u8 *)(p + 0xF2) == 4) {
            index = *(u8 *)(p + 0xF1);
            if (index == 4) index = *(u8 *)(p + 0xA);
            if (*(void **)(p + 0x44 + index * 4)) {
                func_021F8044(*(void **)(p + 0x40), *(void **)(p + 0x44 + index * 4), (u32 *)(&v));
                target = (float)v.x / 4096.0f - 128.0f;
            }
        } else {
            func_021F6F04(*(void **)(p + 0x90), *(void **)(p + 0x94 + *(u8 *)(p + 0xF2) * 4), &v);
            target = (float)v.x / 4096.0f - 128.0f;
        }
        if (target > 256) target = 256;
        else if (target < 0) target = 0;
        if (target != *(u16 *)(p + 4)) *(u16 *)(p + 6) = target;
    }
    if (*(u16 *)(p + 6) != *(u16 *)(p + 4)) {
        Vec scale = d_021FDBEC;
        Vec translation = {0, 0, 0};
        if (*(u16 *)(p + 4) > *(u16 *)(p + 6)) {
            if (*(u16 *)(p + 4) > 4 && *(u16 *)(p + 4) - 4 > *(u16 *)(p + 6)) *(u16 *)(p + 4) -= 4;
            else *(u16 *)(p + 4) = *(u16 *)(p + 6);
        } else if (*(u16 *)(p + 4) < *(u16 *)(p + 6)) {
            if (*(u16 *)(p + 4) + 4 < *(u16 *)(p + 6)) *(u16 *)(p + 4) += 4;
            else *(u16 *)(p + 4) = *(u16 *)(p + 6);
        }
        scale.x = FX((float)*(u16 *)(p + 4) / 16.0f);
        translation.x = FX((float)*(u16 *)(p + 4) / 16.0f);
        func_02048AFC(*(void **)(p + 0xA8), &scale);
        func_02048B44(*(void **)(p + 0xA8), &translation);
        func_02048AD0(*(void **)(p + 0xA8));
        func_02040618(2, 0, *(u16 *)(p + 4));
        func_021F7098(*(void **)(p + 0x3C), *(u16 *)(p + 4));
        func_021F75DC(*(void **)(p + 0x40), *(u16 *)(p + 4));
        func_021F6AF0(*(void **)(p + 0x54), *(u16 *)(p + 4));
        func_021FA57C(*(void **)(p + 0xB8), *(u16 *)(p + 4));
    }
    if (*(u16 *)(p + 8) == 224) *(int *)(p + 0xC) = 0;
    func_02040618(2, 3, *(u16 *)(p + 8));
}





void func_021F90E0(u8 *p)
{
    u8 i;
    u32 *table;
    struct Bytes order;
    table = *(u32 * *)&((struct Obj08150 *)p)->fB4;
    order = d_021FDBD0;
    func_021FAC74(((struct Obj08150 *)p)->fB0, (u8 *)table + table[0], 1);
    for (i = 0; i < 4; i++) {
        if (table[0] != table[((u8 *)&order)[i]]) {
            func_021FAC74(((struct Obj08150 *)p)->fB0, *(u8 * *)&((struct Obj08150 *)p)->fB4 + table[((u8 *)&order)[i]], 1);
        }
    }
}





void func_021F9140(u8 *p, u8 n, u8 i)
{
    void *table;
    u16 score;
    table = func_0204A380((void *)(((struct Obj05397 *)p)->f18), n + 0x37, 0, ((struct Obj05397 *)p)->f0);
    score = *(u16 *)(*(u8 **)(*(u8 * *)&((struct Obj05397 *)p)->f30 + i * 4 + 4) + 0x4a);
    if (score >= 70) {
        func_021FAD0C(((struct Obj05397 *)p)->fB0, table, 0, (u8)(1 << i));
    } else if (score >= 40) {
        func_021FAD0C(((struct Obj05397 *)p)->fB0, table, 1, (u8)(1 << i));
    } else {
        func_021FAD0C(((struct Obj05397 *)p)->fB0, table, 2, (u8)(1 << i));
    }
}





void func_021F91A8(char *p, u8 n, u8 mask){void *table;table=func_0204A380((void *)(((struct Obj10531 *)p)->f18),n+0x4b,0,((struct Obj10531 *)p)->f0);func_021FAD0C(((struct Obj10531 *)p)->fB0,table,0,mask);}





/*
 * Palette fade, 16 colours. The object holds a u16 phase at +0x168 (advanced by 0x160, wrapped at
 * 0x10000), 16 base colours at +0x16A, s8 red, green and blue deltas at +0x18A, +0x19A, +0x1AA,
 * and 16 output colours at +0x1BA. The factor is (cos table entry + 0x1000) / 2. Each channel gets
 * (s8 delta * factor >> 12) added, then the colours go to func_02061CA4(31, 0, out, 32).
 * Twins for the channel pack: ov068 021B9D68, ov104 021B89DC.
 * What closed it: a struct view of the object (p->phase, p->base[i], p->out[i]) with no colour
 * local (every channel reads p->base[i], CSE keeps one load), which makes the allocator spill p
 * instead of p + 2i; compound assignment `p->phase += 0x160` in the else wrap
 * arm (the else arm then recomputes the sum, as the image does); `u8 i` declared before
 * `int factor`. final push 2026-10-05 G9L6.
 */
void func_021F91CC(Fade *p)
{
    u8 i;
    int factor;
    if (p->phase + 0x160 >= 0x10000)
        p->phase = p->phase - 0xFEA0;
    else
        p->phase += 0x160;
    factor = (d_020A1B38[(p->phase >> 4) * 2] + 0x1000) / 2;
    for (i = 0; i < 16; i++) {
        u8 b = (p->base[i] & 0x7C00) >> 10;
        u8 r = p->base[i] & 0x1F;
        u8 g = (p->base[i] & 0x3E0) >> 5;
        int B = b + (s8)((p->db[i] * factor) >> 12);
        int R = r + (s8)((p->dr[i] * factor) >> 12);
        int G = g + (s8)((p->dg[i] * factor) >> 12);
        p->out[i] = (B << 10) | (R | (G << 5));
    }
    func_02061CA4((void *)31, 0, (u32)p->out, 32);
}




void func_021F92CC(u8 *p)
{
    int zero;
    ((struct Obj01257 *)p)->fD0=func_020450F0(1,4,20,24,4,15,1);
    func_02045334((struct Descriptor *)((struct Obj01257 *)p)->fD0);
    func_02045374((struct Cfg *)(((struct Obj01257 *)p)->fD0));
    func_020409B4(1);
    zero=0;
    ((struct Obj01257 *)p)->fD4=(u32)func_0201D7EC(23,0,0,0,((struct Obj01257 *)p)->f0);
    ((struct Obj01257 *)p)->fDC=(u32)func_02045C44(((struct Obj23183 *)(*(u8 * *)&((struct Obj23182 *)(*(u8 * *)&((struct Obj01257 *)p)->f30))->f18))->f8,((struct Obj01257 *)p)->f0);
    func_02049B40(23,5,0,480,32,((struct Obj01257 *)p)->f0);
    ((struct Obj01257 *)p)->fCC=(u32)func_0203101C(((struct Obj01257 *)p)->f0,((struct Obj01257 *)p)->f0,3,256);
    ((struct Obj01257 *)p)->fD8=zero;
    ((struct Obj01257 *)p)->fE0=zero;
    ((struct Obj01257 *)p)->fE4=zero;
    ((struct Obj01257 *)p)->fE8=func_0201C440((void *)(u32)((struct Obj01257 *)p)->f0);
}




void func_021F9374(u8 *p)
{
    func_020310C4(((struct Obj02849 *)p)->fCC);
    if (((struct Obj02849 *)p)->fD8 && func_0201CE30(((struct Obj02849 *)p)->fD8) == 2) {
        func_0201CE48(((struct Obj02849 *)p)->fD8);
        ((struct Obj02849 *)p)->fD8 = 0;
    }
    if (((struct Obj02849 *)p)->fE4 == 1) {
        func_0201C4E4(((struct Obj02849 *)p)->fE8);
        if (func_0201C6B4(((struct Obj02849 *)p)->fE8) == 1) {
            func_02045334(((struct Obj02849 *)p)->fD0);
            ((struct Obj02849 *)p)->fE4 = 0;
        }
    }
}




/*
 * abi: 0201CCE4 forwards the pointer result of matched 0201CD10; the caller stores it at d8.
 */
void func_021F93D8(u8 *p, u16 index, u32 speed)
{
    Zero zero;
    if (((struct Obj00832 *)p)->fD8) {
        func_0201CE48(((struct Obj00832 *)p)->fD8);
        ((struct Obj00832 *)p)->fD8 = 0;
    }
    if (((struct Obj00832 *)p)->fE0) {
        func_02045808(((struct Obj00832 *)p)->fE0);
        ((struct Obj00832 *)p)->fE0 = 0;
    }
    func_02043B5C(func_02045770(((struct Obj00832 *)p)->fD0), 0);
    zero = ZERO;
    ((struct Obj00832 *)p)->fE0 = func_02045EC0(((struct Obj00832 *)p)->fDC, index);
    if (speed != 255) {
        ((struct Obj00832 *)p)->fD8 = func_0201CCE4(((struct Obj00832 *)p)->fD0, zero, zero,
            ((struct Obj00832 *)p)->fE0, ((struct Obj00832 *)p)->fD4, speed,
            ((struct Obj00832 *)p)->fCC, 2, ((struct Obj00832 *)p)->f0, zero);
    } else {
        func_0201C6FC(((struct Obj00832 *)p)->fE8, (u32)func_02045770(((struct Obj00832 *)p)->fD0),
            zero, zero, ((struct Obj00832 *)p)->fE0, *(u32 *)&((struct Obj00832 *)p)->fD4);
        ((struct Obj00832 *)p)->fE4 = 1;
        func_02045808(((struct Obj00832 *)p)->fE0);
        ((struct Obj00832 *)p)->fE0 = (void *)zero;
    }
}




void func_021F94B0(u8 *p)
{
    if (((struct Obj03817 *)p)->fD8) {
        func_0201CE48(((struct Obj03817 *)p)->fD8);
        ((struct Obj03817 *)p)->fD8 = 0;
    }
    if (((struct Obj03817 *)p)->fE0) {
        func_02045808(((struct Obj03817 *)p)->fE0);
        ((struct Obj03817 *)p)->fE0 = 0;
    }
    func_02043B5C(func_02045770(((struct Obj03817 *)p)->fD0), 0);
    func_02045334(((struct Obj03817 *)p)->fD0);
}




void func_021F94F8(char *p)
{
    u8 count, i, j, selected, index;
    if (*(int *)(p + 0xEC) != 1) return;
    count = 0;
    i = 0;
    for (; i < 4; i++) func_021FA558(*(char **)(p + 0xB8), i, 0);
    func_021FA56C(*(char **)(p + 0xB8), 255);
    *(u8 *)(p + 0xF1) = 4;
    *(u8 *)(p + 0xF2) = 4;
    for (j = count; j < 4; j = (u8)(j + 1)) {
        if (*(int *)(p + 0x94 + j * 4) != 0) {
            selected = j;
            count = (u8)(count + 1);
        }
    }
    index = *(u8 *)(p + 0x11C);
    if (index < 4) {
        *(u8 *)(p + 0xF1) = index;
        func_021FA558(*(char **)(p + 0xB8), index, 1);
    } else if ((index = *(u8 *)(p + 0xF0)) < 4) {
        *(u8 *)(p + 0xF1) = index;
        func_021FA558(*(char **)(p + 0xB8), index, 1);
    } else if (count == 1) {
        *(u8 *)(p + 0xF2) = selected;
        func_021FA56C(*(char **)(p + 0xB8), selected);
    } else {
        for (j = 0; j < 4; j = (u8)(j + 1)) {
            if (*(u8 *)(p + 0xF3 + j) == 0)
                func_021FA558(*(char **)(p + 0xB8), j, 1);
        }
    }
    *(int *)(p + 0xEC) = 0;
}





/*
 * The original stores p+0xEC = 1 unconditionally after the if/else, so the
 * store is a shared tail reached by both arms (b .end out of the `c == 1`
 * arm); writing it inside the else made the compiler emit two epilogues.
 * See docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md.
 */
void func_021F95CC(char *p, u8 v, int c)
{
    if (c == 1) {
        ((struct Obj10532 *)p)->fF0 = v;
    } else {
        ((struct Obj10532 *)p)->fF0 = 4;
    }
    ((struct Obj10532 *)p)->fEC = 1;
}




void func_021F95E8(char *p){((struct Obj23184 *)p)->fEC=1;}




void func_021F95F0(u8 *p)
{
    u8 i, j;
    u16 score;
    for (i = 0; i < 4; i++) p[0xf3 + i] = 0;
    for (i = 0; i < 4; i++) {
        score = (u16)(*(u16 *)((*(u8 ***)(p + 0x30))[i + 1] + 0x4a) + p[0xf7 + i]);
        for (j = 0; j < 4; j++) {
            if (i != j) {
                if ((u16)(*(u16 *)((*(u8 ***)(p + 0x30))[j + 1] + 0x4a) + p[0xf7 + j]) > score) p[0xf3 + i]++;
            }
        }
    }
}





/*
 * Addresses are Black-image addresses.
 */
void func_021F9664(char *p, int a)
{
    ((struct Obj10533 *)p)->f24 = 1;
    func_02006448(((struct Obj10533 *)p)->f1DC, ((struct Obj10533 *)p)->f1E0, a);
}





void func_021F9680(char *p, int a)
{
    ((struct Obj23185 *)p)->f28 = 1;
    func_020064F4(a);
}




void func_021F9690(char *p){((struct Obj23186 *)p)->f28=0;func_02006504();}





/*
 * lever: The matched 020064B8 body reads four arguments; incoming r3 is
 * forwarded unchanged, preventing the erroneous three-argument tail call.
 *
 * Addresses are Black-image addresses.
 */
int func_021F969C(char *p, u32 a, u32 b, u32 d)
{
    return func_020064B8(a, b, ((struct Obj23187 *)p)->f1E4, d);
}





void func_021F96B0(char *p, int a)
{
    ((struct Obj23188 *)p)->f2C = 1;
    func_02005D90(a, 0xffff);
}




void func_021F96C4(char *p){((struct Obj23189 *)p)->f2C=0;func_02005D28();}




void func_021F96D0(char *p)
{
    u8 i;
    u8 min = 255;
    char *a = *(char * *)&((struct Obj23190 *)p)->f30;
    for (i = 0; i < 4; i++) {
        u16 v = *(u16 *)(*(char **)(a + i * 4 + 4) + 0x4a) + *(u8 *)(p + i + 0xf7);
        if (min > v) min = v;
    }
    if (min >= 70) func_020061E4(1578);
    else if (min >= 30) func_020061E4(1579);
    else if (min >= 1) func_020061E4(1580);
}



void func_021F9730(char *p,int value){if(!**(int * *)&((struct Obj08153 *)p)->f30)func_021F9754(p,((struct Obj08153 *)p)->fA,value);else{((struct Obj08153 *)p)->f15C=1;((struct Obj08153 *)p)->f160=value;}}



void func_021F9754(char *p, u32 i, int v)
{
    Enabled one;
    one = ENABLED;
    i = (u32)p + i * 4;
    ((struct Obj14085 *)i)->fFC = one;
    ((struct Obj14085 *)i)->f10C = v;
}



int func_021F9768(char *p){return func_021F9774(p,((struct Obj08155 *)p)->fA);}



int func_021F9774(char *p,u32 i){if(func_021F7A80(*(char * *)&((struct Obj08155 *)p)->f40,*(char **)((u32)p+i*4+0x44))==1)return 1;return *(int *)((u32)p+0xfc+i*4);}



/*
 * lever: slots[count] = i; count++; keeps the byte store before the increment; if/else field stores preserve the shared flag-store block.
 */
void func_021F9794(char *p)
{
    u8 count = 0;
    u8 slots[4];
    u8 i;
    int action;
    int index;
    int result;
    func_021F9A48(p);
    if (**(void ** *)&((struct Obj00159 *)p)->f30 && ((struct Obj00159 *)p)->f15C == 1) {
        if (func_021FD8C4(**(void ** *)&((struct Obj00159 *)p)->f30, (u8)((struct Obj00159 *)p)->f160) == 1)
            ((struct Obj00159 *)p)->f15C = 0;
    }
    if (!**(void ** *)&((struct Obj00159 *)p)->f30) {
        for (i = 0; i < 4; i++) {
            if (*(int *)(p + i * 4 + 0xFC) == 1) {
                func_021F79A8(*(char * *)&((struct Obj00159 *)p)->f40, *(char **)(p + i * 4 + 0x44), *(int *)(p + i * 4 + 0x10C));
                slots[count] = i;
                count++;
                *(int *)(p + i * 4 + 0xFC) = 0;
                if (*(int *)(p + i * 4 + 0x10C) == 7) *(int *)(p + i * 8 + 0x13C) = 1;
                else if (*(int *)(p + i * 4 + 0x10C) == 8) *(int *)(p + i * 8 + 0x140) = 1;
                func_021F9AD8(p, 2, i);
            }
        }
        if (count != 0) {
            if (((struct Obj00159 *)p)->f11C == 4) ((struct Obj00159 *)p)->f120 = 1;
            else ((struct Obj00159 *)p)->f120 = 0;
            ((struct Obj00159 *)p)->f11E = 180;
            ((struct Obj00159 *)p)->f11C = slots[func_02005728(count)];
            ((struct Obj00159 *)p)->f11D = *(int *)(p + ((struct Obj00159 *)p)->f11C * 4 + 0x10C);
            ((struct Obj00159 *)p)->fEC = 1;
        }
    } else {
        index = func_021FD9FC(**(void ** *)&((struct Obj00159 *)p)->f30);
        if ((unsigned)index < 4) {
            if (((struct Obj00159 *)p)->f11C == 4) ((struct Obj00159 *)p)->f120 = 1;
            else ((struct Obj00159 *)p)->f120 = 0;
            ((struct Obj00159 *)p)->f11E = 180;
            ((struct Obj00159 *)p)->f11C = index;
            ((struct Obj00159 *)p)->f11D = func_021FD9A0(**(void ** *)&((struct Obj00159 *)p)->f30, index);
            ((struct Obj00159 *)p)->fEC = 1;
            func_021FDA18(**(void ** *)&((struct Obj00159 *)p)->f30);
        }
        for (i = 0; i < 4; i++) {
            action = func_021FD9A0(**(void ** *)&((struct Obj00159 *)p)->f30, i);
            if (action != 10) {
                func_021F79A8(*(char * *)&((struct Obj00159 *)p)->f40, *(char **)(p + i * 4 + 0x44), action);
                func_021FD9D0(**(void ** *)&((struct Obj00159 *)p)->f30, i);
                if (action == 7) *(int *)(p + i * 8 + 0x13C) = 1;
                else if (action == 8) *(int *)(p + i * 8 + 0x140) = 1;
                func_021F9AD8(p, 2, i);
            }
        }
    }
    if (((struct Obj00159 *)p)->f11E != 0) {
        if (((struct Obj00159 *)p)->f11E > ((struct Obj00159 *)p)->f1E8) {
            ((struct Obj00159 *)p)->f11E -= (u16)((struct Obj00159 *)p)->f1E8;
            return;
        }
        ((struct Obj00159 *)p)->f11E = 0;
        if (((struct Obj00159 *)p)->f120 == 1) {
            if (!**(void ** *)&((struct Obj00159 *)p)->f30) {
                result = func_021F99F4(p, ((struct Obj00159 *)p)->f11C, ((struct Obj00159 *)p)->f11D);
                *(int *)(*(char **)(*(char * *)&((struct Obj00159 *)p)->f30 + ((struct Obj00159 *)p)->f11C * 4 + 4) + ((struct Obj00159 *)p)->f11D * 4 + 0x54) = 1;
                func_020061E4(result);
            } else if (func_0203D378() == 1) {
                result = func_021F99F4(p, ((struct Obj00159 *)p)->f11C, ((struct Obj00159 *)p)->f11D);
                if (result == 1580) func_021FDA24(**(void ** *)&((struct Obj00159 *)p)->f30, ((struct Obj00159 *)p)->f11C, ((struct Obj00159 *)p)->f11D, 1);
                else func_021FDA24(**(void ** *)&((struct Obj00159 *)p)->f30, ((struct Obj00159 *)p)->f11C, ((struct Obj00159 *)p)->f11D, 2);
            }
        }
        ((struct Obj00159 *)p)->f11C = 4;
        ((struct Obj00159 *)p)->fEC = 1;
    }
}



int func_021F99F4(char *p, unsigned i, unsigned j)
{
    u16 v;
    u8 old;
    v = func_02157394((int)(((struct Obj23204 *)(*(char * *)&((struct Obj10534 *)p)->f30))->f14), (u8)(int)func_021F5140((void *)func_021F9E0C((u8 *)p), (u16)(*(u16 *)(*(char **)(*(char * *)&((struct Obj10534 *)p)->f30 + i * 4 + 4) + j * 6 + 0x14))));
    old = *(u8 *)(p + 0xf7 + i);
    *(u8 *)(p + 0xf7 + i) = old + v;
    func_021F95F0((u8 *)p);
    return (unsigned)v >= 7 ? 1579 : 1580;
}



void func_021F9A48(char *p)
{
    u8 i;
    if (**(void ** *)&((struct Obj08154 *)p)->f30 != 0 && func_0203D378() != 1) return;
    for (i = 0; i < 4; i++) {
        if (*(u16 *)(p + i * 2 + 0x124) != 0) {
            *(u16 *)(p + i * 2 + 0x124) -= 1;
            if (*(u16 *)(p + i * 2 + 0x124) == 0) {
                if (**(void ** *)&((struct Obj08154 *)p)->f30 == 0) func_021F9754(p, i, *(int *)(p + i * 4 + 0x12c));
                else func_021FD974(**(void ** *)&((struct Obj08154 *)p)->f30, i, *(int *)(p + i * 4 + 0x12c));
            }
        }
    }
}



static inline u32 random_below(u32 n)
{
    u32 draw;
    draw = func_0203F0A8();
    return ((u64)draw * n) >> 32;
}



/*
 * lever: The final random choice is a ternary; an if/else shares the earlier action-seven assignment and leaves 36 bytes different.
 * ABI: The matched 0203D378 body returns u32(void); the preceding guard loads r0 without an argument to that call.
 */
void func_021F9AD8(char *p, int mode, u8 slot)
{
    u8 i;
    if (**(void ** *)&((struct Obj08155 *)p)->f30 && func_0203D378() != 1) return;
    for (i = 0; i < 4; i++) {
        int eligible[2] = {0, 0};
        char *record = *(char **)(*(char * *)&((struct Obj08155 *)p)->f30 + i * 4 + 4);
        Action action;
        int value;
        if (((struct Obj03287 *)record)->f0 != 2 || func_021F9774(p, i) == 1 || *(u16 *)(p + i * 2 + 0x124) != 0) continue;
        if (((struct Obj03287 *)record)->f3E != 255 && !*(int *)(p + i * 8 + 0x13C)) eligible[0] = 1;
        if (((struct Obj03287 *)record)->f44 != 255 && !*(int *)(p + i * 8 + 0x140)) eligible[1] = 1;
        if (!eligible[0] && !eligible[1]) continue;
        if (eligible[0] == 1 && eligible[1] == 0) action = ACTION7;
        else if (eligible[1] == 1 && eligible[0] == 0) action = ACTION8;
        else {
            action = (u8)random_below(2) == 0 ? ACTION7 : ACTION8;
        }
        switch (mode) {
        case 1:
            if (((struct Obj03287 *)record)->f78 == 65533 && i == slot) {
                *(u16 *)(p + i * 2 + 0x124) = random_below(30) + 30;
                *(int *)(p + i * 4 + 0x12C) = action;
            }
            break;
        case 2:
            if (((struct Obj03287 *)record)->f78 == 65535 && random_below(100) < 50) {
                *(u16 *)(p + i * 2 + 0x124) = random_below(60) + 60;
                *(int *)(p + i * 4 + 0x12C) = action;
            }
            if (((struct Obj03287 *)record)->f78 == 65534 && random_below(100) < 25) {
                *(u16 *)(p + i * 2 + 0x124) = random_below(60) + 60;
                *(int *)(p + i * 4 + 0x12C) = action;
            }
            break;
        case 0:
            if (((struct Obj03287 *)record)->f78 != 0 && ((struct Obj03287 *)record)->f78 < 65533) {
                value = ((struct Obj03287 *)record)->f78 + (s8)(random_below(121) - 60);
                if (value < 0) *(u16 *)(p + i * 2 + 0x124) = 0;
                else *(u16 *)(p + i * 2 + 0x124) = value;
                *(int *)(p + i * 4 + 0x12C) = action;
            }
            break;
        }
    }
}




void func_021F9CF4(char *p)
{
    ((struct Obj14086 *)p)->fBC = func_021F9EDC(((struct Obj14086 *)p)->f6C, 0x36);
}




void func_021F9D08(char *p)
{
    func_021F9F58(((struct Obj14087 *)p)->f6C, ((struct Obj14087 *)p)->fBC);
}



void func_021F9D18(char *p, unsigned i)
{
    Vec v;
    u8 j;
    func_021F8044(((struct Obj14088 *)p)->f40, *(void **)(p + i * 4 + 0x44), (unsigned int *)(&v));
    v.x /= 16;
    v.y = (0xc0000 - (v.y - 0x20000)) / 16;
    v.z = 0xb4000;
    for (j = 0; j < 3; j++) func_021F9F74(*(char * *)&((struct Obj14088 *)p)->fBC, j, &v.x);
    func_020061E4(1961);
}




void func_021F9D80(char *p)
{
    func_021FAAB8(((struct Obj23210 *)p)->fA4, 1);
}



void func_021F9D90(char *p){func_021FAAB8(((struct Obj23211 *)p)->fA4,0);}



void *func_021F9DA0(char *p){return ((struct Obj23212 *)p)->f40;}



void *func_021F9DA4(char *p,u32 i){return *(void **)((u32)p+4*i+0x44);}



void *func_021F9DAC(void *p){return ((struct Obj23213 *)p)->f54;}



u32 *func_021F9DB0(void *p,u8 i){return *(u32 **)((u8 *)p+(u32)i*4+0x58);}



void func_021F9DB8(void *p,void *v,u32 i){*(void **)((u8 *)p+i*4+0x58)=v;}



void *func_021F9DC0(void *p){return ((struct Obj23214 *)p)->f6C;}



void *func_021F9DC4(void *p,u8 i){return *(void **)((u8 *)p+(u32)i*4+0x70);}



void func_021F9DCC(void *p,void *v,u32 i){*(void **)((u8 *)p+i*4+0x70)=v;}



void *func_021F9DD4(void *p){return ((struct Obj23215 *)p)->f90;}



void *func_021F9DDC(void *p,u8 i){return *(void **)((u8 *)p+(u32)i*4+0x94);}



void func_021F9DE8(void *p,void *v,u8 i){*(void **)((u8 *)p+(u32)i*4+0x94)=v;}



void *func_021F9DF4(void *p){return ((struct Obj23216 *)p)->fB8;}



u16 func_021F9DFC(void *p){return ((struct Obj23217 *)p)->f8;}



void func_021F9E00(void *p,u16 v){((struct Obj23218 *)p)->f8=v;}



u16 func_021F9E04(u8 *p) { return ((struct Obj23219 *)p)->f4; }



void func_021F9E08(u8 *p,u16 v) { ((struct Obj23220 *)p)->f6=v; }



u32 func_021F9E0C(u8 *p) { return func_021F4F10(*(u8 * *)&((struct Obj10534 *)p)->f38); }



/*
 * note: unlabelled getter witnessing ov112 021F6CE0.
 */
int func_021F9E18(char *p) { return ((struct Obj23221 *)p)->f11C; }
