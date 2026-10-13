/*
 * file:     field_fog.c
 * unit:     yes
 * function: func_0219F058, func_0219F0B0, func_0219F0F8, func_0219F114, func_0219F128, func_0219F17C, func_0219F188, func_0219F22C, func_0219F248, func_0219F25C, func_0219F2B0, func_0219F354, func_0219F3F0, func_0219F484, func_0219F490, func_0219F52C, func_0219F5C8, func_0219F5D4, func_0219F628, func_0219F634, func_0219F750, func_0219F7CC, func_0219F870, func_0219F8C8, func_0219F8E0, func_0219F8F4, func_0219F990, func_0219FAB4, func_0219FADC, func_0219FB20, func_0219FB2C, func_0219FB48, func_0219FB5C, func_0219FC5C, func_0219FC68, func_0219FCC0, func_0219FD1C, func_0219FD94, func_0219FE20, func_0219FE64, func_0219FE9C, func_0219FEB0, func_0219FFBC, func_0219FFD4, func_021A000C, func_021A006C, func_021A0084, func_021A00E0, func_021A00F4, func_021A00FC, func_021A0104, func_021A0138, func_021A0140, func_021A0170, func_021A01A4, func_021A01AC, func_021A01B4, func_021A01BC, func_021A01C4, func_021A01CC, func_021A01D4, func_021A01D8, func_021A01FC, func_021A0224, func_021A0244, func_021A0250, func_021A0260, func_021A0280, func_021A0290, func_021A02A8, func_021A02C4, func_021A02F4, func_021A030C, func_021A0338, func_021A0354, func_021A0358, func_021A0380, func_021A0390, func_021A03A4, func_021A03B8, func_021A03CC, func_021A03D0, func_021A0448, func_021A0458, func_021A0568, func_021A0590, func_021A05D8, func_021A0618, func_021A063C, func_021A065C, func_021A066C, func_021A0734, func_021A0748, func_021A07B0, func_021A07B4, func_021A07F8, func_021A0818, func_021A0860, func_021A08CC, func_021A0918, func_021A0974, func_021A0980, func_021A0A50, func_021A0B14, func_021A0B34, func_021A0B4C, func_021A0C50, func_021A0C60, func_021A0C74, func_021A0CE4, func_021A0CF4, func_021A0D44, func_021A0D68, func_021A0E58, func_021A0EB0, func_021A0ED4, func_021A0EE4, func_021A0F30, func_021A0F40, func_021A0F7C, func_021A0F90, func_021A0F94, func_021A0FA0, func_021A0FA8, func_021A0FB4, func_021A0FE8, func_021A1050, func_021A10C0, func_021A10D4, ov021_func_021A10E0, func_021A1138
 * address:  0x0219F058
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F29D8  0x021F29D8  thumb  ov029
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216D6F0  0x0216D6F0  thumb  ov010
 *   func_0216D910  0x0216D910  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_02050848  0x02050848  arm
 *   func_02050880  0x02050880  arm
 *   func_0205082C  0x0205082C  arm
 *   func_0205085C  0x0205085C  arm
 *   func_0216D6D8  0x0216D6D8  thumb  ov010
 *   func_0219C814  0x0219C814  thumb  ov021
 *   func_0219C8D4  0x0219C8D4  thumb  ov021
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_02050080  0x02050080  arm
 *   func_0204F638  0x0204F638  arm
 *   func_0216D678  0x0216D678  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B0C  0x02048B0C  arm
 *   func_02048B30  0x02048B30  arm
 *   func_0207BCA0  0x0207BCA0  arm
 *   func_02082B60  0x02082B60  arm
 *   func_0207B0A4  0x0207B0A4  arm
 *   func_0207B51C  0x0207B51C  arm
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_0207C9D0  0x0207C9D0  arm
 *   d_021D854C     0x021D854C  data  ov021  a4
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D8B0  0x0216D8B0  thumb  ov010
 *   func_02197C9C  0x02197C9C  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_02188CBC  0x02188CBC  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3080  0x021A3080  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_02013D9C  0x02013D9C  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   func_020508EC  0x020508EC  arm
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   data_021D8548  0x021D8548  data  ov021  a1
 *   func_02189A78  0x02189A78  thumb  ov021
 *   func_0216D538  0x0216D538  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0219D738  0x0219D738  thumb  ov021
 *   func_021642D4  0x021642D4  thumb  ov010
 *   func_020507A0  0x020507A0  arm
 *   func_020507F0  0x020507F0  arm
 *   func_0216DAB4  0x0216DAB4  thumb  ov010
 *   func_0219C648  0x0219C648  thumb  ov021
 *   func_0219D634  0x0219D634  thumb  ov021
 *   func_0219D49C  0x0219D49C  thumb  ov021
 *   func_021C6664  0x021C6664  thumb  ov021
 *   func_021C6678  0x021C6678  thumb  ov021
 *   func_021C66EC  0x021C66EC  thumb  ov021
 *   func_0219D680  0x0219D680  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   d_021DDE1C     0x021DDE1C  data
 *   func_020307B0  0x020307B0  arm
 *   func_0207DC44  0x0207DC44  arm
 *   func_0207DD10  0x0207DD10  arm
 *   func_020490F4  0x020490F4  arm
 *   d_021DDE28     0x021DDE28  data
 *   func_02049238  0x02049238  arm
 *   func_0204A380  0x0204A380  arm
 *   func_02082D44  0x02082D44  arm
 *   d_021DDE38  0x021DDE38  data  ov021
 *   _u32_div_f     0x0209C2B0  arm
 *   func_02048CA4  0x02048CA4  arm
 *   func_02048CDC  0x02048CDC  arm
 *   func_0206AA8C  0x0206AA8C  arm
 *   func_0206AAB0  0x0206AAB0  arm
 *   func_0207DD24  0x0207DD24  arm
 *   func_020490A8  0x020490A8  arm
 *   func_02048F4C  0x02048F4C  arm
 *   func_0207CDB8  0x0207CDB8  arm
 *   func_02011400  0x02011400  thumb
 *   func_0207CB68  0x0207CB68  arm
 *   func_0207CAA4  0x0207CAA4  arm
 *   func_0207D184  0x0207D184  arm
 *   func_0207B65C  0x0207B65C  arm
 *   func_0207BC08  0x0207BC08  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   d_020A1B38  0x020A1B38  data  a2
 *   func_021A0EE4  0x021A0EE4  thumb  ov021
 *   d_021DDE48  0x021DDE48  data  ov021
 *   d_021D872C  0x021D872C  data  a4
 *   d_021D8738     0x021D8738  data
 *   func_02189A2C  0x02189A2C  thumb  ov021
 *   func_0202208C  0x0202208C  thumb
 *   func_020221A4  0x020221A4  thumb
 *   d_021D8734  0x021D8734  data  a4
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009210  0x02009210  thumb
 *   func_020090E0  0x020090E0  thumb
 *   func_02013D20  0x02013D20  thumb
 *   func_02013D00  0x02013D00  thumb
 *   func_02188E30  0x02188E30  thumb  ov021
 *   func_021D3270  0x021D3270  thumb  ov021
 *   func_02193060  0x02193060  thumb  ov021
 *   func_020414EC  0x020414EC  arm
 *   func_021902A4  0x021902A4  thumb  ov021
 *   func_02009208  0x02009208  thumb
 *   func_02009200  0x02009200  thumb
 *   func_0201214C  0x0201214C  thumb
 *   func_02012204  0x02012204  thumb
 *   func_02012210  0x02012210  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_021F279C  0x021F279C  thumb  ov029
 *   abs_id_1d      0x0000001D  data
 *   func_021F27D8  0x021F27D8  thumb  ov029
 *   func_021F2984  0x021F2984  thumb  ov029
 *   func_02034A5C  0x02034A5C  arm
 *   func_021F2980 0x021F2980 thumb ov029
 *   func_021F2994  0x021F2994  thumb  ov029
 *   func_021F2848  0x021F2848  thumb  ov029
 */
#include "../../matched/include/Obj17977.h"
#include "../../matched/include/Obj17978.h"
#include "../../matched/include/Obj02378.h"
#include "../../matched/include/Obj17979.h"
#include "../../matched/include/Obj05015.h"
#include "../../matched/include/Obj03121.h"
#include "../../matched/include/Obj17980.h"
#include "../../matched/include/Obj01851.h"
#include "../../matched/include/Obj01852.h"
#include "../../matched/include/Obj09179.h"
#include "../../matched/include/Obj17981.h"
#include "../../matched/include/Obj17982.h"
#include "../../matched/include/Obj17983.h"
#include "../../matched/include/Obj01496.h"
#include "../../matched/include/Obj17984.h"
#include "../../matched/include/Obj17985.h"
#include "../../matched/include/Obj09535.h"
#include "../../matched/include/Obj09536.h"
#include "../../matched/include/Obj03581.h"
#include "../../matched/include/Obj12078.h"
#include "../../matched/include/Obj12079.h"
#include "../../matched/include/Obj07212.h"
#include "../../matched/include/Obj12080.h"
#include "../../matched/include/Obj12081.h"
#include "../../matched/include/Obj17986.h"
#include "../../matched/include/Obj12696.h"
#include "../../matched/include/Obj12082.h"
#include "../../matched/include/Obj07213.h"
#include "../../matched/include/Obj12697.h"
#include "../../matched/include/Obj17987.h"
#include "../../matched/include/Obj04228.h"
#include "../../matched/include/Obj07486.h"
#include "../../matched/include/Obj17988.h"
#include "../../matched/include/Obj04229.h"
#include "../../matched/include/Obj01497.h"
#include "../../matched/include/Obj07487.h"
#include "../../matched/include/Obj12698.h"
#include "../../matched/include/Obj09537.h"
#include "../../matched/include/Obj19694.h"
#include "../../matched/include/Obj19695.h"
#include "../../matched/include/Obj19696.h"
#include "../../matched/include/Obj12699.h"
#include "../../matched/include/Obj12700.h"
#include "../../matched/include/Obj19697.h"
#include "../../matched/include/Obj19698.h"
#include "../../matched/include/Obj01498.h"
#include "../../matched/include/Obj02080.h"
#include "../../matched/include/Obj03124.h"
#include "../../matched/include/Obj01034.h"
#include "../../matched/include/Obj03125.h"
#include "../../matched/include/Obj07214.h"
#include "../../matched/include/Obj05021.h"
#include "../../matched/include/G_021D8738.h"
#include "../../matched/include/Obj02081.h"
#include "../../matched/include/Obj17989.h"
#include "../../matched/include/Obj12083.h"
#include "../../matched/include/Obj07215.h"
#include "../../matched/include/Obj17990.h"
#include "../../matched/include/Obj17991.h"

#define GX_RGB(r, g, b) ((u16)(((r) << 0) | ((g) << 5) | ((b) << 10)))
struct Trip;
struct Obj00020;
struct LightSlot;
struct Big;
struct Ctx;
struct Sub020090B0Obj;
struct Sub02009210Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;


typedef struct { s32 x, y, z; } Vec;

typedef struct {
    u16 id;
    u8  b2;
    u8  b3;
    u8  b4;
    u8  b5;
} E;

typedef struct {
    u32 x, y, z;
} V3;

typedef struct FieldFogWork {
    u16 f0;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 f5;
    u8 f6;
    u8 pad07[0x8 - 0x7];
    u32 f8;
} FieldFogWork;

typedef struct { u8 b[4]; } U8x4;

typedef struct {
    u16 f0;
    u16 f2;
    u32 f4;
    int f8;
    u32 fc;
    int f10;
} Lerp;

typedef struct {
    u8 state;
    u8 pad[3];
    void *buf;
    int val;
} S;

typedef struct {
    u16 x, y, z;
} V3s;

typedef struct {
    u8 pad[0x35A];
    u8 used[4];
    u16 c[4];
    V3s b[4];
    u16 f37E;
    u16 f380;
    u16 f382;
    u16 f384;
    u16 f386;
    u16 f388;
    u16 active;
} W;

typedef struct {
    u16 h;
    s16 m;
} Time;

typedef struct {
    s16 base;
    s16 delta;
} Lerp021A0860;

typedef struct { s32 x, y, z; } V32;

typedef int BOOL;

typedef struct {
    u8 pad[0xF0];
    u16 cur;
    u16 max;
} Counter;

typedef struct {
    void (*init)(u32 *a, u32 prev);
    void (*update)(u32 *a, s32 flag);
    u32 f8;
    u32 fC;
    void (*exit)(u32 *a);
    u32 f14;
    u32 f18;
} Mode;

extern u8 *func_0216E3C4(void *);
extern void *func_0216D6F0(void *p);
extern int func_0216D910(int a0);
extern u32 func_0219C9DC(u8 *p);
extern u16 func_02050848(u8 *p, int i);
extern u16 func_02050880(u8 *p, int i);
extern void func_0205082C(void *p, int idx, u32 h);
extern void func_0205085C(void *p, int idx, u32 v);
extern void *func_0216D6D8(int a0, int a1);
extern int func_0219C814(u32 a, u16 *b);
extern u32 func_0219C8D4(u32, u32);
extern void func_02197CCC(u8 *p, s32 *out);
extern u32 func_02050080(u32 *p);
extern void func_0204F638(u8 *a0, int i, struct Trip *src);
extern u16 func_0216D678(void *p);
extern u16 func_0216D598(void *p);
extern void func_02048AE8(u32, s32 *);
extern void func_02048B0C(u32, s32 *);
extern void func_02048B30(u32, s32 *);
extern void func_0207BCA0(s32 *, s32 *, s32 *, s32 *);
extern void func_02082B60(s32 *, s32 *);
extern void func_0207B0A4(s32 *, s32 *);
extern void func_0207B51C(s32 *, s32 *, s32 *);
extern void *func_0216D67C(void *a0);
extern u32 func_0216D534(void *p);
extern void *func_02188C58(void *p);
extern u32 func_0218EC2C(u8 *p);
extern void func_0207C9D0(Vec *, Vec *, Vec *);
extern u16 func_0216D5F8(void *p);
extern void func_0216D8B0(u8 *p, u8 *q);
extern s32 func_02197C9C(u32);
extern int func_0216D83C(void *p);
extern u16 func_0216D590(void *p);
extern u16 func_0216D588(void *p);
extern int func_02188CBC(u32);
extern void *func_02188CB4(struct Obj00020 *p);
extern u32 func_021A3080(u8 *p);
extern void func_0216D8C0(u32, Vec *);
extern u32 func_02013D9C(u32 id);
extern int func_0216D7A8(void *p, unsigned int v);
extern u32 func_020508EC(u8 *p, int i, u16 *out);
extern u32 func_02082BCC(u32, u32, u32, u32);
extern u32 func_02189A78(u8 *p);
extern u32 func_0216D538(u8 *p);
extern int func_0216D55C(int a0, int a1);
extern u32 func_0219D738(u32 a, int b);
extern u8 func_021642D4(int i, int v);
extern int func_0219C648(u32 a);
extern int func_0216DAB4(void *a0);
extern void func_020507F0(void *p, int idx, u32 v);
extern int func_020507A0(void *p, int idx, u32 x);
extern u32 func_0219D634(u32 a);
extern u32 func_0219D49C(u32);
extern void func_021C6664(u32, u32, u32 *);
extern void func_021C6678(u32, u32, u32);
extern int func_021C66EC(u32 *a, int idx, int v);
extern void func_0219D680(u32 a, u32 b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_0207DC44(int enable, int fogMode, int fogSlope, int fogOffset);
extern void func_0207DD10(u8 *);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049238(u32 arc);
extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(void *src, void *dst, u32 n);
extern void func_02048CA4(u32, u8, const V3s *);
extern void func_02048CDC(struct LightSlot *slots, u32 i, u16 *in);
extern void func_0206AA8C(u32 v, u32 bits, u32 flag);
extern void func_0206AAB0(u32 v, u32 bits, u32 flag);
extern void func_0207DD24(u16, int, int, int, int);
extern u32 func_020490A8(u32 b, u32 c);
extern void func_02048F4C(void *a, u32 b, u32 c);
extern void func_0207CDB8(void *a, void *b);
extern u8 func_02011400(int row, int col);
extern void func_0207CB68(const s16 *a, u32 b, s16 *c);
extern s32 func_0207CAA4(const s16 *a, u32 b);
extern u16 func_0207D184(s32 x);
extern void func_0207B65C(void *o, void *m, s32 a, s32 b);
extern void func_0207BC08(void *m, void *n, void *o);
extern void func_0207CCA4(void *a, void *b);
extern u32 func_021A0EE4();
extern int func_02189A2C(int *a);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);
extern void *func_02188C80(void *p);
extern u16 func_02188C9C(u8 *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern u32 func_02009210();
extern u32 func_020090E0(void);
extern u32 func_02013D20(void);
extern u32 func_02013D00(u32);
int func_021A0F30(u32 a, u32 b);
void func_021A0F40(u32 *p, u32 v);
extern u32 func_02188E30(u8 *p);
extern void func_021D3270(u32, u32, u32, u32, u32, u32);
extern void func_02193060(u32);
extern void func_020414EC(u32 i);
extern void func_021902A4(u32, u32);
extern u8 func_02009208(const struct Sub020090B0Obj *obj);
extern void func_02009200(u32, u32);
extern u32 func_0201214C(const struct Ctx *);
extern u32 func_02012204(const struct Ctx *p);
extern void func_02012210(struct Ctx *p);
extern int func_02034AC4(int);
extern void *func_021F279C(int a, int b, int c, int d);
extern char *func_021F27D8(int a0, int a1, int a2, void (*cb)(int), int arg, int flag);
extern void func_021F2984(char *p);
extern void func_02034A5C(int);
int func_021A0F7C(u32 a, u32 b, u32 c, u32 d);
u32 func_021A0F90(u8 *p);
int func_021A0F94(u32 a);
void func_021A0FA0(int *p, int v);
void func_021A0FA8(int *p);
void func_021A0FB4(u32 *p, u32 a);
void ov021_func_021A0FE8(u32 *p);
void ov021_func_021A1050(u32 *p);
void func_021A10C0(u32 *p);
u32 func_021F2980(u32 a);
u32 func_021A10D4(u32 *p);
extern int func_021F2994(int *p);
extern u32 func_021F2848(u32, u32);
void func_0219F058(u32 a, u16 *o1, u16 *o2);
void func_0219F0B0(u32 a, u32 b, u32 c);
void func_0219F0F8(u32 a);
int func_0219F114(u32 a, u32 b, u32 c, u32 d);
void func_0219F128(u32 a);
int func_0219F17C(u32 a, u32 b, u32 c, u32 d);
void func_0219F188(u32 a);
void func_0219F22C(u32 a);
int func_0219F248(u32 a, u32 b, u32 c, u32 d);
void func_0219F25C(u32 a);
void func_0219F2B0(u32 a);
void func_0219F354(u32 a);
void func_0219F3F0(u32 a);
int func_0219F484(u32 a, u32 b, u32 c, u32 d);
void func_0219F490(u32 a);
void func_0219F52C(u32 a);
void func_0219F5C8(void *a, int v);
void func_0219F5D4(u32 a, s32 *b, s32 *c);
int func_0219F628(u32 a, u32 b, u32 c, u32 d);
void func_0219F634(u32 o);
void func_0219F750(u32 a);
int func_0219F7CC(u32 a, u32 b);
void func_0219F870(u32 a);
void func_0219F8C8(u32 a);
int func_0219F8E0(u32 a, u32 b, u32 c, u32 d);
void func_0219F8F4(u32 a);
void func_0219F990(u32 a, u8 *p, u8 b);
void func_0219FAB4(u32 a, u32 b, u8 *c, int *d);
int func_0219FADC(u8 *p, int a, u8 *q);
int func_0219FB20(u32 a, u32 b, u32 c, u32 d);
void func_0219FB2C(u32 a);
int func_0219FB48(u32 a, u32 b, u32 c, u32 d);
void func_0219FB5C(u32 a);
int func_0219FC5C(u32 a, u32 b, u32 c, u32 d);
int func_0219FC68(u32 a, u16 *o1, u16 *o2);
int func_0219FCC0(u32 a, u16 *o1, u16 *o2);
void func_0219FD1C(u32 a);
void func_0219FD94(u32 a);
u32 func_0219FE20(u32 a, u32 a1, u32 a2, u32 a3);
void func_0219FE64(u32 a);
void func_0219FEB0(u8 *s, u32 a, u32 r, u16 id);
void func_0219FFBC(u32 a, u32 *p);
u32 func_0219FFD4(u32 a);
void func_021A000C(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_021A006C(u32 a);
void func_021A0084(u32 a);
void func_021A00E0(u32 a);
void func_021A00F4(u32 a);
void func_021A00FC(u32 a);
u8 *func_021A0104(u16 heap);
void func_021A0138(u32 a);
void func_021A0140(u8 *p);
void func_021A0170(u8 *p, u32 a1, u32 a2, u32 a3);
int func_021A01A4(u32 a, u32 b);
int func_021A01AC(u32 a, u32 b);
int func_021A01B4(u32 a, u32 b);
int func_021A01BC(u32 a, u32 b);
int func_021A01C4(u32 a, u32 b);
int func_021A01CC(u32 a, u32 b);
u32 func_021A01D4(u8 *p);
void func_021A01D8(u8 *p);
void func_021A01FC(u8 *p, u32 a, u32 b, u32 c);
void func_021A0224(u8 *p, u32 a, u32 b, u32 c, u32 d, u16 e);
int func_021A0244(u8 *p);
int func_021A0250(u8 *a);
void func_021A0260(Lerp *s, u32 a, u32 b, u16 c, u16 d, u16 e);
int func_021A0280(u32 a);
u32 func_021A0290(Lerp *s);
u16 func_021A02A8(Lerp *s);
u8 *func_021A02C4(u16 heap);
int func_021A02F4(void *a);
void func_021A030C(u8 *p, u32 a);
void func_021A0338(u8 *p, u32 id, u32 c, u8 d);
u8 func_021A0354(u8 *p);
void func_021A0358(S *s);
int func_021A0380(int *p);
int func_021A0390(int *p);
int func_021A03A4(int *p);
int func_021A03B8(int *p);
int func_021A03CC(int *p);
u8 *func_021A03D0(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_021A0448(u8 *p);
void func_021A0458(u8 *a, s32 b);
void func_021A0568(u8 *p, int force);
void func_021A0590(u8 *a, u32 b, u32 c, u32 d);
void func_021A05D8(u8 *a);
void func_021A0618(u8 *p, u32 a, u32 b, u32 c);
void func_021A063C(u8 *p, u16 a, u32 b);
int func_021A065C(u8 *p);
void func_021A066C(const W *w, u32 a, u32 p);
void func_021A0734(u8 *a, u32 b);
void func_021A0748(u8 *a, u32 b, u32 c);
void func_021A07B0(void);
u32 func_021A07B4(u8 *p, int t);
int func_021A07F8(u32 a, Time *t);
void func_021A0818(s16 *o, s32 a, u32 b);
u16 func_021A0860(Lerp021A0860 *c, int t, int n);
void func_021A08CC(s32 *o, const s16 *in, u32 c);
void func_021A0918(u8 *a, s32 x, s32 y, s16 *out);
void func_021A0974(u32 a1, u32 a2, u32 a3);
void func_021A0980(u8 *a, u8 *b, u8 *c, u32 d);
void func_021A0A50(u8 *a, u8 *b, u32 c, u32 d);
void func_021A0B14(Counter *p);
int func_021A0B34(u32 a);
void func_021A0B4C(const u8 *a, u8 *b);
int func_021A0C50(u32 a, u16 b, u32 c, u32 d);
void func_021A0C60(u16 *p, u16 a, u16 b);
s32 func_021A0C74(u16 *a, void *b, void *c, void *d);
int func_021A0CE4(u16 *p);
u32 *func_021A0CF4(u32 a, u32 b, u32 c);
u8 func_021A0D44(u32 *p);
void func_021A0D68(u32 *a);
void func_021A0E58(u32 *a);
int func_021A0EB0(u32 *p, u32 a);
int func_021A0ED4(u32 a);
u32 ov021_func_021A10E0(u32 *p, u32 x);
extern const Vec d_021D854C;
extern const U8x4 data_021D8548;
extern char d_021DDE1C[];
extern char d_021DDE28[];
extern u8 d_021DDE38[];
extern s16 d_020A1B38[];
extern u8 d_021DDE48[];
extern const Mode d_021D872C[];
extern struct G_021D8738 d_021D8738[];
extern u8 d_021D8734[];
extern unsigned char abs_id_1d[];













void func_0219F058(u32 a, u16 *o1, u16 *o2)
{
    u16 *q;
    u32 r;
    if (func_0216E3C4((void *)a)[2] == 1) {
        q = func_0216D6F0((void *)a);
        if (*q != 0xFFFF) {
            r = func_0219C9DC((u8 *)func_0216D910(a));
            *o1 = func_02050848((u8 *)r, *q);
            *o2 = func_02050880((u8 *)r, *q);
        } else {
            *o1 = 0;
            *o2 = 0;
        }
    } else {
        *o1 = 0;
        *o2 = 0;
    }
}













/*
 * Leaf callees now filed; formerly MATCH. Leaf sources verified from a scratch
 * file (region arm9, --arm, dsi/1.1p1 -O4,p; typedefs u8/u16/u32):
 *   func_0205082C:
 *   void func_0205082C(u8 *p, int i, u16 v)
 *   {
 *       u8 *e = *(u8 **)(p + 0x18) + i * 40;
 *       *(u16 *)(e + 0xe) = v;
 *       func_020500A0(e);   // 0x020500A0: extern void (u8 *), arm
 *   }
 *
 * Addresses are Black-image addresses.
 */
void func_0219F0B0(u32 a, u32 b, u32 c)
{
    u16 *q;
    u32 r;
    if (func_0216E3C4((void *)a)[2] == 1) {
        q = func_0216D6F0((void *)a);
        if (*q != 0xFFFF) {
            r = func_0219C9DC((u8 *)func_0216D910(a));
            func_0205082C((void *)r, *q, b);
            func_0205085C((void *)r, *q, c);
        }
    }
}













/*
 * Addresses are Black-image addresses.
 */
void func_0219F0F8(u32 a)
{
    u8 *q = func_0216D6D8(a, 8);
    func_0219FE9C(q + 4);
    func_0219C814(a, (u16 *)q);
}













/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219F114(u32 a, u32 b, u32 c, u32 d)
{
return func_0219C8D4(a, ((struct Obj17977 *)((u8 *)(func_0216D6F0((void *)a))))->f0);
}













/*
 * Leaf callees now filed; formerly MATCH. Leaf sources verified from a scratch
 * file (region arm9, --arm, dsi/1.1p1 -O4,p; typedefs u8/u16/u32):
 *   func_02050080:
 *   u32 func_02050080(u8 *p) { return *(u32 *)(p + 4); }
 *
 * Addresses are Black-image addresses.
 */
void func_0219F128(u32 a)
{
    s32 buf[3];
    u16 *q;
    u32 r;
    q = func_0216D6F0((void *)a);
    if (*q != 0xFFFF) {
        r = func_0219C9DC((u8 *)func_0216D910(a));
        func_0219FEB0((u8 *)(q + 2), a, r, *q);
    func_02197CCC((u8 *)a, buf);
    func_0219FFBC(a, (u32 *)buf);
    r = func_02050080((u32 *)r);
    func_0204F638((u8 *)r, *q, (struct Trip *)buf);
    }
}













int func_0219F17C(u32 a, u32 b, u32 c, u32 d)
{
return ((struct Obj17978 *)((u8 *)(func_0216D6F0((void *)a))))->f0;
}













/*
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * Addresses are Black-image addresses.
 */
void func_0219F188(u32 a)
{
    s32 buf[3];
    u8 *q;
    u32 flag;
    u32 r;
    u32 x;
    u32 y;
    flag = 0;
    q = (u8 *)func_0216D6F0((void *)a);
    if (((struct Obj02378 *)q)->f0 != 0xFFFF) {
        r = func_0219C9DC((u8 *)func_0216D910(a));
        x = func_0219FFD4(a);
        y = func_0216D678((void *)a);
        if (q[4] != x) {
            q[4] = x;
            q[5] = y;
            func_0205082C((void *)r, ((struct Obj02378 *)q)->f0, x);
            flag = 1;
        } else if (q[5] != y) {
            func_0205082C((void *)r, ((struct Obj02378 *)q)->f0, x);
            func_0205085C((void *)r, ((struct Obj02378 *)q)->f0, flag);
            q[5] = y;
        }
        func_021A000C(a, r, ((struct Obj02378 *)q)->f0, flag, 0);
    func_02197CCC((u8 *)a, buf);
    func_0219FFBC(a, (u32 *)buf);
    r = func_02050080((u32 *)r);
    func_0204F638((u8 *)r, ((struct Obj02378 *)q)->f0, (struct Trip *)buf);
    }
}













void func_0219F22C(u32 a)
{
    u8 *q = func_0216D6D8(a, 8);
    func_0219FE9C(q + 4);
    func_0219C814(a, (u16 *)q);
}













int func_0219F248(u32 a, u32 b, u32 c, u32 d)
{
return func_0219C8D4(a, ((struct Obj17979 *)((u8 *)(func_0216D6F0((void *)a))))->f0);
}













void func_0219F25C(u32 a)
{
    s32 buf[3];
    u16 *q;
    u32 r;
    q = func_0216D6F0((void *)a);
    if (*q != 0xFFFF) {
        r = func_0219C9DC((u8 *)func_0216D910(a));
        func_0219FEB0((u8 *)(q + 2), a, r, *q);
    func_02197CCC((u8 *)a, buf);
    func_0219FFBC(a, (u32 *)buf);
    r = func_02050080((u32 *)r);
    func_0204F638((u8 *)r, *q, (struct Trip *)buf);
    }
}













/*
 * Leaf callees now filed; formerly MATCH. Leaf sources verified from a scratch
 * file (region arm9, --arm, dsi/1.1p1 -O4,p; typedefs u8/u16/u32):
 *   func_0205082C:
 *   void func_0205082C(u8 *p, int i, u16 v)
 *   {
 *       u8 *e = *(u8 **)(p + 0x18) + i * 40;
 *       *(u16 *)(e + 0xe) = v;
 *       func_020500A0(e);   // 0x020500A0: extern void (u8 *), arm
 *   }
 *   func_02050080:
 *   u32 func_02050080(u8 *p) { return *(u32 *)(p + 4); }
 *
 * Addresses are Black-image addresses.
 */
void func_0219F2B0(u32 a)
{
    s32 buf[3];
    u8 *q;
    u32 flag;
    u32 r;
    u32 f;
    u32 x;
    u32 k;
    u32 w;
    flag = 0;
    f = 0;
    q = (u8 *)func_0216D6F0((void *)a);
    if (((struct Obj05015 *)q)->f0 != 0xFFFF) {
        r = func_0219C9DC((u8 *)func_0216D910(a));
        x = func_0219FFD4(a);
        if (func_0216D598((void *)a) == 0xCC) {
            f = 1;
        }
        k = func_0216E3C4((void *)a)[3];
        if (k == 0xF) {
            k = 4;
        } else if (k == 5) {
            k = 8;
        } else {
            k = 0x10;
        }
        w = (u16)(k + x);
        if (q[4] != x) {
            q[4] = x;
            func_0205082C((void *)r, ((struct Obj05015 *)q)->f0, w);
            flag = 1;
        }
        func_021A000C(a, r, ((struct Obj05015 *)q)->f0, flag, f);
    func_02197CCC((u8 *)a, buf);
    func_0219FFBC(a, (u32 *)buf);
    r = func_02050080((u32 *)r);
    func_0204F638((u8 *)r, ((struct Obj05015 *)q)->f0, (struct Trip *)buf);
    }
}













void func_0219F354(u32 a)
{
    FieldFogWork *p;
    u32 h;
    u32 n;
    u32 v;
    u8 flag;
    u32 buf[3];

    p = func_0216D6F0((void *)a);
    if (p->f0 != 0xFFFF) {
        h = func_0219C9DC((u8 *)func_0216D910(a));
        n = func_0216D678((void *)a);
        if (n >= 10) {
            flag = 0;
            v = func_0219FFD4(a);
            if (n != p->f5) {
                flag = 1;
                p->f4 = v;
                p->f5 = n;
                p->f6 = 0;
                func_0205082C((void *)h, p->f0, (u16)(n + 30));
            }
            func_021A000C(a, h, p->f0, flag, 0);
        } else {
            func_0219FEB0(&p->f4, a, h, p->f0);
        }
        func_02197CCC((u8 *)a, (s32 *)buf);
        func_0219FFBC(a, buf);
        func_0204F638((u8 *)func_02050080((u32 *)h), p->f0, (struct Trip *)buf);
    }
}













void func_0219F3F0(u32 a)
{
    s32 buf[3];
    u8 *q;
    u32 r;
    u32 x;
    u32 y;
    q = (u8 *)func_0216D6F0((void *)a);
    if (((struct Obj03121 *)q)->f0 != 0xFFFF) {
        r = func_0219C9DC((u8 *)func_0216D910(a));
        x = func_0216D678((void *)a);
        if (x >= 10) {
            y = func_0219FFD4(a);
            if (x != q[5]) {
                q[4] = y;
                q[5] = x;
                q[6] = 0;
                func_0205082C((void *)r, ((struct Obj03121 *)q)->f0, (u16)(x + 0x1e));
            }
            func_021A000C(a, r, ((struct Obj03121 *)q)->f0, 1, 0);
        } else {
            func_0219FEB0((u8 *)((u16 *)(q + 4)), a, r, ((struct Obj03121 *)q)->f0);
        }
    func_02197CCC((u8 *)a, buf);
    func_0219FFBC(a, (u32 *)buf);
    r = func_02050080((u32 *)r);
    func_0204F638((u8 *)r, ((struct Obj03121 *)q)->f0, (struct Trip *)buf);
    }
}













int func_0219F484(u32 a, u32 b, u32 c, u32 d)
{
return ((struct Obj17980 *)((u8 *)(func_0216D6F0((void *)a))))->f0;
}













void func_0219F490(u32 a)
{
    s32 buf[3];
    u8 *q;
    u32 x;
    u32 r;
    q = (u8 *)func_0216D6F0((void *)a);
    if (((struct Obj01851 *)q)->f0 != 0xFFFF) {
        r = func_0219C9DC((u8 *)func_0216D910(a));
        x = func_0216D678((void *)a);
        if (q[5] >= 2) {
            q[5] = 0;
            func_0205082C((void *)r, ((struct Obj01851 *)q)->f0, q[5]);
            func_0205085C((void *)r, ((struct Obj01851 *)q)->f0, 0);
        }
        if (x < 2 && q[5] != x) {
            q[5] = x;
            func_0205082C((void *)r, ((struct Obj01851 *)q)->f0, q[5]);
            func_0205085C((void *)r, ((struct Obj01851 *)q)->f0, 0);
        }
        func_021A000C(a, r, ((struct Obj01851 *)q)->f0, 0, 0);
    func_02197CCC((u8 *)a, buf);
    func_0219FFBC(a, (u32 *)buf);
    r = func_02050080((u32 *)r);
    func_0204F638((u8 *)r, ((struct Obj01851 *)q)->f0, (struct Trip *)buf);
    }
}












void func_0219F52C(u32 a)
{
    s32 buf[3];
    u8 *q;
    u32 x;
    u32 r;
    q = (u8 *)func_0216D6F0((void *)a);
    if (((struct Obj01852 *)q)->f0 != 0xFFFF) {
        r = func_0219C9DC((u8 *)func_0216D910(a));
        x = func_0216D678((void *)a);
        if (q[5] >= 3) {
            q[5] = 0;
            func_0205082C((void *)r, ((struct Obj01852 *)q)->f0, q[5]);
            func_0205085C((void *)r, ((struct Obj01852 *)q)->f0, 0);
        }
        if (x < 3 && q[5] != x) {
            q[5] = x;
            func_0205082C((void *)r, ((struct Obj01852 *)q)->f0, q[5]);
            func_0205085C((void *)r, ((struct Obj01852 *)q)->f0, 0);
        }
        func_021A000C(a, r, ((struct Obj01852 *)q)->f0, 0, 0);
    func_02197CCC((u8 *)a, buf);
    func_0219FFBC(a, (u32 *)buf);
    r = func_02050080((u32 *)r);
    func_0204F638((u8 *)r, ((struct Obj01852 *)q)->f0, (struct Trip *)buf);
    }
}












void func_0219F5C8(void *a, int v)
{
    ((char *)func_0216D6F0(a))[2] = v;
}













void func_0219F5D4(u32 a, s32 *b, s32 *c)
{
    s32 v1[3];
    s32 v2[3];
    s32 v3[3];
    s32 m4[12];
    s32 m3[9];
    func_02048AE8(a, v1);
    func_02048B0C(a, v2);
    func_02048B30(a, v3);
    func_0207BCA0(v1, v2, v3, m4);
    func_02082B60(m4, m3);
    func_0207B0A4(m3, m3);
    func_0207B51C(b, m3, c);
}













int func_0219F628(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj09179 *)((u8 *)(d)))->f0 = 0;
((struct Obj09179 *)((u8 *)(d)))->f4 = 0;
((struct Obj09179 *)((u8 *)(d)))->f8 = 0;
return 0;
}













void func_0219F634(u32 o)
{
    E *e;
    u32 h;
    u32 a;
    u32 b;
    u16 c;
    Vec pos;
    Vec d;
    Vec tmp;
    u32 flag;
    u32 x;

    flag = 0;
    e = func_0216D6F0((void *)o);
    if (e->id == 0xFFFF) {
        return;
    }
    h = func_0219C9DC((u8 *)func_0216D910(o));
    a = func_0219FFD4(o);
    b = func_0216D678((void *)o);
    c = a + b * 4;
    if (a != e->b4 || e->b5 != b) {
        e->b4 = a;
        flag = 1;
        e->b5 = b;
        func_0205082C((void *)h, e->id, c);
        func_0205085C((void *)h, e->id, 0);
    }
    func_021A000C(o, h, e->id, flag, 1);
    func_02197CCC((u8 *)o, (s32 *)(&pos));
    func_0219FFBC(o, (u32 *)(&pos));
    x = func_02050848((u8 *)h, e->id);
    func_0219F628(o, x, func_02050880((u8 *)h, e->id), (u32)(&d));
    pos.x += d.x;
    pos.y += d.y;
    pos.z += d.z;
    if (e->b2 == 0) {
        tmp = d_021D854C;
        func_0219F5D4(func_0218EC2C(func_02188C58((void *)func_0216D534(func_0216D67C((void *)o)))), (s32 *)(&tmp), (s32 *)(&tmp));
        func_0207C9D0(&pos, &tmp, &pos);
    } else {
        pos.y -= 0xC000;
        pos.z += 0x8000;
    }
    func_0204F638((u8 *)func_02050080((u32 *)h), e->id, (struct Trip *)(&pos));
}













/*
 * Blocked at MATCH: func_02050080 (0x02050080), func_0205082C (0x0205082C) is an unlabelled arm9 leaf
 * (the integrator's, inside a labelled arm9 function) with no witness outside this range.
 * Leaf C for the arm9 owner:
 *   u32 func_02050080(u32 *p) { return p[1]; }  (EXACT as arm9 leaf, verified)
 *   void func_0205082C(u8 *p, int i, u16 h): strh into the record at +0xE, then tail-calls func_020500A0 (bx ip, pool 0x020500A0); not compiled here
 *
 * Addresses are Black-image addresses.
 */
void func_0219F750(u32 a)
{
    u16 *p;
    u32 buf[3];
    u32 h;
    u32 v;

    p = func_0216D6F0((void *)a);
    if (*p != 0xFFFF) {
        h = func_0219C9DC((u8 *)func_0216D910(a));
        v = func_0219FFD4(a);
        if (((u8 *)p)[4] != v) {
            func_0205082C((void *)h, *p, v);
            func_0205085C((void *)h, *p, 0);
            ((u8 *)p)[4] = v;
        }
        func_021A000C(a, h, *p, 0, 0);
        func_02197CCC((u8 *)a, (s32 *)buf);
        func_0219FFBC(a, buf);
        func_0204F638((u8 *)func_02050080((u32 *)h), *p, (struct Trip *)buf);
    }
}













/*
 * Blocked at MATCH: func_02050880 (0x02050880) is an unlabelled arm9 leaf
 * (the integrator's, inside a labelled arm9 function) with no witness outside this range.
 * Leaf C for the arm9 owner:
 *   u16 func_02050880(u8 *p, int i) { return *(u16 *)(*(u8 **)(p + 0x18) + i * 40 + 0x10); }  (EXACT, verified)
 *
 * Addresses are Black-image addresses.
 */
int func_0219F7CC(u32 a, u32 b)
{
    u32 idx;
    u16 *p;
    u32 h;
    u32 t;

    p =func_0216D6F0((void *)a);
    if (*p == 0xFFFF) {
        return 0;
    }
    if (b < 0x18) {
        if (b < 6) idx = 0;
        else if (b < 0xC) idx = 1;
        else if (b < 0x12) idx = 2;
        else idx = 3;
    } else if (b < 0x28) {
        if (b < 0x1C) idx = 4;
        else if (b < 0x20) idx = 5;
        else if (b < 0x24) idx = 6;
        else idx = 7;
    } else if (b < 0x30) {
        if (b < 0x2A) idx = 8;
        else if (b < 0x2C) idx = 9;
        else if (b < 0x2E) idx = 10;
        else idx = 11;
    } else {
        idx = 12;
    }
    h = func_0219C9DC((u8 *)func_0216D910(a));
    t = func_02050880((u8 *)h, *p);
    if (t != idx) {
        func_0205085C((void *)h, *p, 0);
    }
    return 1;
}













/*
 * Blocked at MATCH: func_02050080 (0x02050080) is an unlabelled arm9 leaf
 * (the integrator's, inside a labelled arm9 function) with no witness outside this range.
 * Leaf C for the arm9 owner:
 *   u32 func_02050080(u32 *p) { return p[1]; }  (EXACT as arm9 leaf, verified)
 *
 * Addresses are Black-image addresses.
 */
void func_0219F870(u32 a)
{
    u16 *p;
    u32 buf[3];
    u32 h;

    p = func_0216D6F0((void *)a);
    if (*p != 0xFFFF) {
        h = func_0219C9DC((u8 *)func_0216D910(a));
        func_021A000C(a, h, *p, 0, 0);
        func_02197CCC((u8 *)a, (s32 *)buf);
        func_0219FFBC(a, buf);
        func_0204F638((u8 *)func_02050080((u32 *)h), *p, (struct Trip *)buf);
    }
}













void func_0219F8C8(u32 a)
{
    u8 *q = func_0216D6D8(a, 8);
    q[2] = 9;
    func_0219C814(a, (u16 *)q);
}













int func_0219F8E0(u32 a, u32 b, u32 c, u32 d)
{
return func_0219C8D4(a, ((struct Obj17981 *)((u8 *)(func_0216D6F0((void *)a))))->f0);
}













void func_0219F8F4(u32 a)
{
    FieldFogWork *p;
    u8 flag;
    u32 h;
    u32 n;
    u32 buf[3];
    u32 v[3];

    p = func_0216D6F0((void *)a);
    if (p->f0 != 0xFFFF) {
        flag = 0;
        h = func_0219C9DC((u8 *)func_0216D910(a));
        n = func_0216D5F8((void *)a);
        if (n != p->f2) {
            flag = 1;
            p->f2 = n;
            p->f3 = 0;
            p->f8 = 0;
            func_0205082C((void *)h, p->f0, p->f2);
            {
                V3 *pv = (V3 *)v;
                pv->x = 0;
                pv->y = 0;
                pv->z = 0;
                func_0216D8B0((u8 *)a, (u8 *)pv);
            }
        }
        func_0219F990(a, (u8 *)p, n);
        func_02197CCC((u8 *)a, (s32 *)buf);
        func_0219FFBC(a, buf);
        func_0204F638((u8 *)func_02050080((u32 *)h), p->f0, (struct Trip *)buf);
        func_021A000C(a, h, p->f0, flag, 0);
    }
}













void func_0219F990(u32 a, u8 *p, u8 b)
{
    Vec d;
    Vec v;
    u32 u;
    s32 s14;
    u32 s10;
    s32 sc;
    u8 *info;
    int clr;
    int ok;
    int ff;
    u32 t;
    u8 m;
    void *x;

    ok = 1;
    info = func_0216E3C4((void *)a);
    ff = 0;
    d.x = 0;
    d.y = 0;
    d.z = 0;
    s14 = func_02197C9C(a);
    func_0216D8B0((u8 *)a, (u8 *)(&v));
    sc = func_0216D83C((void *)a);
    s10 = func_0216D590((void *)a);
    t = func_0216D588((void *)a);
    if (t == 0xff)
        ff = ok;
    clr = (t == 0xfc) ? 1 : 0;
    if (ff != 0) {
        u = func_0216D534(func_0216D67C((void *)a));
        if (func_02188CBC(u) != 0 && (x = func_02188CB4((void *)u)) != 0) {
            ok = func_021A3080(x) != 0;
        }
    }
    if (s14 != 0 || (v.y > 0x1800 && info[3] != 11)) {
        d.y = v.y;
    } else if (func_0219FADC(p, b, info) == 0 && ok != 0) {
        d.y = d.y + 0x1800;
    }
    if (func_02013D9C(s10) != 0 && ff == 0) {
        m = sc % 3;
        if (m == 0)
            d.z = d.z - 0x219a;
        else if (m == 2)
            d.z = d.z + 0x219a;
        d.z = d.z - 0x2000;
    }
    func_0219FAB4(a, b, info, (int *)(&d));
    if (clr) {
        d.x = 0;
        d.y = 0;
        d.z = 0;
    }
    func_0216D8C0(a, &d);
    p[3]++;
}













void func_0219FAB4(u32 a, u32 b, u8 *c, int *d)
{
    if (c[7] == 0) {
        switch (b) {
        case 2:
            *d -= 0x2000;
            break;
        case 3:
            *d += 0x2000;
            break;
        }
    }
}













int func_0219FADC(u8 *p, int a, u8 *q)
{
    int m = p[3] % 20;
    u8 k = q[3];
    p[3] = m;
    if (k == 11) {
        if (a == 1) {
            if (m < 5 || m >= 15)
                return 1;
        } else {
            if (m < 10)
                return 1;
        }
    } else {
        if ((m >= 5 && m < 10) || m >= 15)
            return 1;
    }
    return 0;
}













int func_0219FB20(u32 a, u32 b, u32 c, u32 d)
{
return ((struct Obj17982 *)((u8 *)(func_0216D6F0((void *)a))))->f0;
}













void func_0219FB2C(u32 a)
{
    u8 *q = func_0216D6D8(a, 8);
    func_0219FE9C(q + 4);
    func_0219C814(a, (u16 *)q);
}












int func_0219FB48(u32 a, u32 b, u32 c, u32 d)
{
return func_0219C8D4(a, ((struct Obj17983 *)((u8 *)(func_0216D6F0((void *)a))))->f0);
}












void func_0219FB5C(u32 a)
{
    s32 buf[3];
    u32 flag;
    u32 r;
    u32 x;
    u8 *q;
    u32 t;
    u32 y;
    u32 m;

    flag = 0;
    q = (u8 *)func_0216D6F0((void *)a);
    if (((struct Obj01496 *)q)->f0 == 0xFFFF)
        return;
    r = func_0219C9DC((u8 *)func_0216D910(a));
    t = func_0216D598((void *)a);
    x = func_0216D678((void *)a);
    if (t == 0xd3 || t == 0xd5 || t == 0x79) {
        m = 0;
        if (x == q[5])
            goto tail;
        switch (x) {
        case 10:
            m = 1;
            break;
        case 11:
            m = 2;
            break;
        case 12:
            m = 3;
            break;
        }
        q[5] = x;
        func_0205082C((void *)r, ((struct Obj01496 *)q)->f0, m);
        flag = 1;
    } else if (t == 0xd4 || t == 0xd6) {
        y = func_0219FFD4(a);
        m = 0;
        if (x < 10) {
            if (y == q[4] && x == q[5])
                goto tail;
            if (y == 0)
                m = 0;
            else if (y == 1)
                m = 1;
            q[4] = y;
        } else {
            if (x == q[5])
                goto tail;
            switch (x) {
            case 10:
                m = 2;
                break;
            case 11:
                m = 3;
                break;
            }
        }
        q[5] = x;
        func_0205082C((void *)r, ((struct Obj01496 *)q)->f0, m);
        flag = 1;
    } else {
        if (x == q[5])
            goto tail;
        q[5] = x;
        func_0205082C((void *)r, ((struct Obj01496 *)q)->f0, flag);
        flag = 1;
    }
tail:
    func_021A000C(a, r, ((struct Obj01496 *)q)->f0, flag, 1);
    func_02197CCC((u8 *)a, buf);
    func_0219FFBC(a, (u32 *)buf);
    func_0204F638((u8 *)func_02050080((u32 *)r), ((struct Obj01496 *)q)->f0, (struct Trip *)buf);
}












int func_0219FC5C(u32 a, u32 b, u32 c, u32 d)
{
return ((struct Obj17984 *)((u8 *)(func_0216D6F0((void *)a))))->f0;
}












/*
 * Blocked at MATCH: func_02050848 (0x02050848), func_02050880 (0x02050880) is an unlabelled arm9 leaf
 * (the integrator's, inside a labelled arm9 function) with no witness outside this range.
 * Leaf C for the arm9 owner:
 *   u16 func_02050848(u8 *p, int i) { return *(u16 *)(*(u8 **)(p + 0x18) + i * 40 + 0xe); }  (EXACT, verified)
 *   u16 func_02050880(u8 *p, int i) { return *(u16 *)(*(u8 **)(p + 0x18) + i * 40 + 0x10); }  (EXACT, verified)
 *
 * Addresses are Black-image addresses.
 */
int func_0219FC68(u32 a, u16 *o1, u16 *o2)
{
    u32 t;
    u16 *p;
    u32 h;

    t = func_0216D598((void *)a);
    if (t == 0xD3 || t == 0xD5) {
        p = func_0216D6F0((void *)a);
        if (*p != 0xFFFF) {
            h = func_0219C9DC((u8 *)func_0216D910(a));
            *o1 = func_02050848((u8 *)h, *p);
            *o2 = func_02050880((u8 *)h, *p);
            return 1;
        }
        return 0;
    }
    *o1 = 0;
    *o2 = 0;
    return 1;
}












int func_0219FCC0(u32 a, u16 *o1, u16 *o2)
{
    u16 *p;
    u32 h;

    if ((u16)(func_0216D598((void *)a) + 0xFF23) <= 1) {
        p = func_0216D6F0((void *)a);
        if (*p != 0xFFFF) {
            h = func_0219C9DC((u8 *)func_0216D910(a));
            *o1 = func_02050848((u8 *)h, *p);
            *o2 = func_02050880((u8 *)h, *p);
            return 1;
        }
        return 0;
    }
    *o1 = 0;
    *o2 = 0;
    return 1;
}












void func_0219FD1C(u32 a)
{
    u32 flag;
    u16 *p;
    u32 buf[3];
    u32 h;
    u32 v;

    flag = 0;
    p = func_0216D6F0((void *)a);
    if (*p != 0xFFFF) {
        h = func_0219C9DC((u8 *)func_0216D910(a));
        v = func_0216D678((void *)a);
        if (v != ((u8 *)p)[5] && v < 2) {
            ((u8 *)p)[5] = v;
            func_0205082C((void *)h, *p, v);
            flag = 1;
        }
        func_021A000C(a, h, *p, flag, 0);
        func_02197CCC((u8 *)a, (s32 *)buf);
        func_0219FFBC(a, buf);
        func_0204F638((u8 *)func_02050080((u32 *)h), *p, (struct Trip *)buf);
    }
}












void func_0219FD94(u32 a)
{
    u16 *p;
    u32 buf[3];
    u32 h;
    u32 v;
    u32 flag;

    flag = 0;
    p = func_0216D6F0((void *)a);
    if (*p != 0xFFFF) {
        h = func_0219C9DC((u8 *)func_0216D910(a));
        v = func_0216D678((void *)a);
        if (v != ((u8 *)p)[5]) {
            switch (v) {
            case 10: flag = 1; break;
            case 11: flag = 2; break;
            case 12: flag = 3; break;
            }
            ((u8 *)p)[5] = v;
            func_0205082C((void *)h, *p, flag);
            flag = 1;
        }
        func_021A000C(a, h, *p, flag, 0);
        func_02197CCC((u8 *)a, (s32 *)buf);
        func_0219FFBC(a, buf);
        func_0204F638((u8 *)func_02050080((u32 *)h), *p, (struct Trip *)buf);
    }
}












/*
 * Blocked at MATCH: func_020508EC (0x020508EC) is an unlabelled arm9 leaf
 * (the integrator's, inside a labelled arm9 function) with no witness outside this range.
 * Leaf C for the arm9 owner:
 *   u32 func_020508EC(u8 *p, int i, u16 *out) reads a u16 at record+0x1C, stores it, returns a range test; see the pending ov021 files that already name it
 *
 * Addresses are Black-image addresses.
 */
u32 func_0219FE20(u32 a, u32 a1, u32 a2, u32 a3)
{
    u32 t;
    u16 out;

    if (func_0216D598((void *)a) != 0x7B) {
        return 1;
    }
    t = (u16)func_0216D7A8((void *)a, 0);
    if (t != 0xFFFF) {
        if (func_020508EC((u8 *)func_0219C9DC((u8 *)func_0216D910(a)), t, &out) == 1) {
            return 1;
        }
    }
    return 0;
}











void func_0219FE64(u32 a)
{
    u16 v;
    u16 z;
    if (func_0216D598((void *)a) == 0x7B) {
        z = 0;
        v = func_0216D7A8((void *)a, 0);
        if (v != 0xFFFF) {
            func_0205085C((void *)func_0219C9DC((u8 *)func_0216D910(a)), v, z);
        }
    }
}











int func_0219FE9C(u32 a, u32 b, u32 c, u32 d)
{
func_02082BCC(a, 0, 4, d);
((struct Obj17985 *)((u8 *)(a)))->f0 = 8;
return 8;
}











void func_0219FEB0(u8 *s, u32 a, u32 r, u16 id)
{
    U8x4 tbl;
    u32 flag;
    u16 k;
    u32 y;
    u32 x;

    flag = 0;
    y = func_0219FFD4(a);
    x = func_0216D678((void *)a);
    k = y + x * 4;
    if (s[3] != 0 && x == s[1])
        s[3] = flag;
    if (y != s[0]) {
        flag = 1;
        s[1] = x;
        s[0] = y;
        s[2] = 0;
        func_0205082C((void *)r, id, k);
    } else if (x != s[1]) {
        flag = 1;
        if (x == 0) {
            if (s[1] == 0) {
                func_0205082C((void *)r, id, k);
                s[1] = x;
                s[3] = 0;
            } else {
                if (s[3] == 0) {
                    s[3]++;
                    flag = 0;
                    goto tail;
                }
                tbl = data_021D8548;
                s[2] = func_02050880((u8 *)r, id);
                if (s[2] >= 4)
                    s[2] = 0;
                s[2] = tbl.b[s[2]];
                func_0205082C((void *)r, id, k);
                s[1] = x;
                s[3] = 0;
            }
        } else {
            if (s[1] != 0) {
                s[2] = func_02050880((u8 *)r, id);
                s[2] = (s[2] >= 2) ? 0 : 2;
            }
            func_0205082C((void *)r, id, k);
            func_0205085C((void *)r, id, s[2]);
            s[1] = x;
            s[3] = 0;
        }
    }
tail:
    func_021A000C(a, r, id, flag, 0);
}











void func_0219FFBC(u32 a, u32 *p)
{
    p[1] += func_02189A78((u8 *)func_0216D534(func_0216D67C((void *)a)));
}











u32 func_0219FFD4(u32 a){
    u32 x = func_0216D538(func_0216D67C((void *)a));
    u32 y = func_0216D5F8((void *)a);
    if (func_0216D55C(a, 0x2000))
        func_0219D738(a, x);
    else
        func_021642D4(y, x);
}











/*
 * Blocked at MATCH: func_020507F0 (0x020507F0) is an unlabelled arm9 leaf
 * (the integrator's, inside a labelled arm9 function) with no witness outside this range.
 * Leaf C for the arm9 owner:
 *   void func_020507F0(u8 *p, int i, u32 v) { *(u32 *)(*(u8 **)(p + 0x18) + i * 40 + 0x18) = v; }  (EXACT, verified)
 *
 * Addresses are Black-image addresses.
 */
void func_021A000C(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    u32 f;
    u32 k;

    f = 1;
    k = func_0219C648(a);
    if (d == 0) {
        if (e == 1) {
            if (k == 1 && func_0216D55C(a, 0x10) != 0) f = 0;
        } else {
            if (k == 1 && func_02197C9C(a) == 1) f = 0;
        }
    }
    func_020507F0((void *)b, c, f);
    f = 1;
    if (func_0216DAB4((void *)a) == 1) f = 0;
    func_020507A0((void *)b, c, f);
}











void func_021A006C(u32 a)
{
    u16 *q = (u16 *)func_0216D6D8(a, 2);
    *q = func_0219D634(a);
}











void func_021A0084(u32 a)
{
    u32 f;
    u32 q;
    u32 buf[3];
    u16 *p;

    p = func_0216D6F0((void *)a);
    q = func_0219D49C(a);
    func_02197CCC((u8 *)a, (s32 *)buf);
    func_021C6664(q, *p, buf);
    f = 0;
    if (func_0216DAB4((void *)a) == 1) f = 1;
    func_021C6678(q, *p, f);
    if (func_02197C9C(a) == 0) {
        func_021C66EC((u32 *)q, *p, 0x1000);
    }
}








void func_021A00E0(u32 a)
{
    func_0219D680(a, *(u16 *)func_0216D6F0((void *)a));
}






void func_021A00F4(u32 a) { func_021A00E0(a); }






void func_021A00FC(u32 a) { func_021A006C(a); }











u8 *func_021A0104(u16 heap)
{
    u8 *p = (u8 *)func_02030734(heap, 0x44, 1, d_021DDE1C, 0x89);
    p[1] = 0;
    p[3] = 0x1F;
    ((struct Obj09535 *)p)->f4 = 0x7FFF;
    func_021A01D8(p);
    return p;
}












/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021A0138(u32 a)
{
    func_020307B0((void *)a);
}












void func_021A0140(u8 *p)
{
    if (func_021A0250(p + 0x2c)) {
        func_021A0280((u32)(p + 0x2c));
        ((struct Obj09536 *)p)->f4 = func_021A0290((Lerp *)(p + 0x2c));
        p[2] = func_021A02A8((Lerp *)(p + 0x2c));
        ((struct Obj09536 *)p)->f40 = 1;
    }
}











static inline void SetFogColor(u16 color, int alpha)
{
    *(volatile u32 *)0x04000358 = (u32)(color | (alpha << 16));
}











void func_021A0170(u8 *p, u32 a1, u32 a2, u32 a3)
{
    if (((struct Obj03581 *)p)->f40) {
        func_0207DC44(p[0], p[1], p[2], ((struct Obj03581 *)p)->f4);
        SetFogColor(((struct Obj03581 *)p)->f8, p[3]);
        func_0207DD10(p + 0xc);
        ((struct Obj03581 *)p)->f40 = 0;
    }
}











int func_021A01A4(u32 a, u32 b)
{
((struct Obj12078 *)((u8 *)(a)))->f0 = b;
((struct Obj12078 *)((u8 *)(a)))->f40 = 1;
return a;
}











int func_021A01AC(u32 a, u32 b)
{
((struct Obj12079 *)((u8 *)(a)))->f1 = b;
((struct Obj12079 *)((u8 *)(a)))->f40 = 1;
return a;
}











int func_021A01B4(u32 a, u32 b)
{
((struct Obj07212 *)((u8 *)(a)))->f2 = b;
((struct Obj07212 *)((u8 *)(a)))->f40 = 1;
return a;
}










int func_021A01BC(u32 a, u32 b)
{
((struct Obj07212 *)((u8 *)(a)))->f4 = b;
((struct Obj07212 *)((u8 *)(a)))->f40 = 1;
return a;
}










int func_021A01C4(u32 a, u32 b)
{
((struct Obj12080 *)((u8 *)(a)))->f8 = b;
((struct Obj12080 *)((u8 *)(a)))->f40 = 1;
return a;
}










int func_021A01CC(u32 a, u32 b)
{
((struct Obj12081 *)((u8 *)(a)))->f3 = b;
((struct Obj12081 *)((u8 *)(a)))->f40 = 1;
return a;
}










/*
 * Loads the byte at +0x2 of the object.
 */
u32 func_021A01D4(u8 *p)
{
    return ((struct Obj17986 *)p)->f2;
}










void func_021A01D8(u8 *p)
{
    int i;
    for (i = 0; i < 32; i++) {
        p[0xC + i] = i * 4;
        p[0xC + i] += (i * 4) / 32;
    }
}










void func_021A01FC(u8 *p, u32 a, u32 b, u32 c)
{
    func_021A0260((Lerp *)(p + 0x2c), ((struct Obj12696 *)p)->f4, a, p[2], b, c);
}










void func_021A0224(u8 *p, u32 a, u32 b, u32 c, u32 d, u16 e)
{
    func_021A0260((Lerp *)(p + 0x2c), a, b, c, d, e);
}










/*
 * Tail-call thunk on the object 0x2c bytes in.
 *
 * Addresses are Black-image addresses.
 */
int func_021A0244(u8 *p)
{
    return func_021A0250((u8 *)(p + 0x2c));
}

















int func_021A0250(u8 *a){
if (((struct Obj12082 *)((u8 *)(a)))->f0 < ((struct Obj12082 *)((u8 *)(a)))->f2) {
    return 1;
}
return 0;
}

















void func_021A0260(Lerp *s, u32 a, u32 b, u16 c, u16 d, u16 e)
{
    s->f0 = 0;
    s->f2 = e;
    s->f4 = a;
    s->f8 = b - a;
    s->fc = c;
    s->f10 = d - c;
}

















int func_021A0280(u32 a)
{
if (((struct Obj07213 *)((u8 *)(a)))->f0 < ((struct Obj07213 *)((u8 *)(a)))->f2) {
    ((struct Obj07213 *)((u8 *)(a)))->f0 = (((struct Obj07213 *)((u8 *)(a)))->f0 + 1);
}
return a;
}

















u32 func_021A0290(Lerp *s)
{
    int q = s->f8 * s->f0 / s->f2;
    return q + s->f4;
}

















u16 func_021A02A8(Lerp *s)
{
    int q = s->f10 * s->f0 / s->f2;
    return q + s->fc;
}

















u8 *func_021A02C4(u16 heap)
{
    u8 *p = (u8 *)func_02030734(heap, 0x10, 1, d_021DDE28, 0x51);
    ((struct Obj12697 *)p)->f8 = 0x0FFFFFFF;
    ((struct Obj12697 *)p)->fC = func_020490F4(0x51, heap);
    return p;
}

















int func_021A02F4(void *a)
{
func_02049238(((struct Obj17987 *)((u8 *)(a)))->fC);
func_021A0358((S *)a);
return func_020307B0(a);
}

















void func_021A030C(u8 *p, u32 a)
{
    if (p[0] == 1) {
        ((s8 *)p)[1]--;
        if (((s8 *)p)[1] <= 0) {
            ((struct Obj04228 *)p)->f4 = (unsigned int)func_0204A380((void *)(((struct Obj04228 *)p)->fC), ((struct Obj04228 *)p)->f2, 0, a);
            p[0] = 0;
        }
    }
}

















void func_021A0338(u8 *p, u32 id, u32 c, u8 d)
{
    if (id != 0x0FFFFFFF) {
        p[0] = 1;
        ((struct Obj07486 *)p)->f2 = id;
        p[1] = d;
    }
    ((struct Obj07486 *)p)->f8 = c;
}

















/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021A0354(u8 *p)
{
    return ((struct Obj17988 *)p)->f0;
}

















void func_021A0358(S *s)
{
    if (s->buf != 0) {
        func_020307B0(s->buf);
        s->buf = 0;
    }
    s->val = 0x0FFFFFFF;
    if (s->state == 1) {
        s->state = 0;
    }
}
















/*
 * Unlabelled leaf, filed as a blocker of the ov024/ov025 lane S26.
 */
int func_021A0380(int *p)
{
    return p[1] != 0 ? 1 : 0;
}
















int func_021A0390(int *p)
{
    return p[2] != 0x0FFFFFFF ? 1 : 0;
}
















int func_021A03A4(int *p)
{
    int *q = (int *)p[1];

    if (q != 0) {
        return q[0];
    }
    return 0x0FFFFFFF;
}
















int func_021A03B8(int *p)
{
    int *q = (int *)p[1];

    if (q != 0) {
        return q[1];
    }
    return 0x0FFFFFFF;
}
















int func_021A03CC(int *p)
{
    return p[2];
}
















u8 *func_021A03D0(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f)
{
    u8 *p;

    p = func_02030734(f, 0x490, 1, (const char *)d_021DDE38, 0x167);
    ((struct Obj04229 *)p)->f2 = c;
    func_021A0734(p, a);
    ((struct Obj04229 *)p)->f38A = 1;
    ((struct Obj04229 *)p)->f350 = func_021A07B4(p, b);
    func_02082D44(p + 0x10 + ((struct Obj04229 *)p)->f350 * 0x34, p + 0x356, 0x34);
    ((struct Obj04229 *)p)->f38C = 1;
    ((struct Obj04229 *)p)->f8 = d;
    ((struct Obj04229 *)p)->f4 = e;
    return p;
}
















/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021A0448(u8 *p)
{
    func_021A07B0();
    func_020307B0(p);
}
















void func_021A0458(u8 *a, s32 b)
{
    s32 prev;
    s32 cur;
    s32 t;
    s32 wrapped;
    s32 i;
    u32 m;

    if (((struct Obj01497 *)a)->fC == 0)
        return;
    switch (((struct Obj01497 *)a)->f0) {
    case 0:
        cur = func_021A07F8(((struct Obj01497 *)a)->f2, (Time *)(a + 0x10 + ((struct Obj01497 *)a)->f350 * 0x34));
        wrapped = 0;
        i = ((struct Obj01497 *)a)->f350 - 1;
        if (i < 0) {
            prev = 0;
            t = func_021A07F8(((struct Obj01497 *)a)->f2, (Time *)(a + 0x10 + (*(s32 *)&((struct Obj01497 *)a)->fC - 1) * 0x34));
            if (t <= b) {
                prev = t;
                wrapped = 1;
                cur += 86400;
            }
        } else {
            prev = func_021A07F8(((struct Obj01497 *)a)->f2, (Time *)(a + 0x10 + i * 0x34));
        }
        if ((prev > b || cur <= b) && wrapped == 0) {
            m = (*(u32 *)&((struct Obj01497 *)a)->f350 + 1) % ((struct Obj01497 *)a)->fC;
            *(u32 *)&((struct Obj01497 *)a)->f350 = m;
            func_021A0974((u32)(a + 0x390), (u32)(a + 0x356), (u32)(a + 0x10 + m * 0x34));
        }
        break;
    case 1:
        if (func_021A0C74((u16 *)(a + 0x484), a + 0x390, a + 0x356, a + 0x10 + ((struct Obj01497 *)a)->f350 * 0x34))
            ((struct Obj01497 *)a)->f0 = 0;
        break;
    }
    if (func_021A0B34((u32)(a + 0x390))) {
        func_021A0B14((Counter *)(a + 0x390));
        func_021A0B4C(a + 0x390, a + 0x356);
        ((struct Obj01497 *)a)->f38C = 1;
    }
    ((struct Obj01497 *)a)->f48C = b;
}
















void func_021A0568(u8 *p, int force)
{
    if (((struct Obj07487 *)p)->f38C != 0 || force != 0) {
        func_021A066C((const W *)p, ((struct Obj07487 *)p)->f8, ((struct Obj07487 *)p)->f4);
        ((struct Obj07487 *)p)->f38C = 0;
    }
}
















void func_021A0590(u8 *a, u32 b, u32 c, u32 d)
{
    u32 r;

    func_021A07B0();
    func_021A0748(a, b, c);
    r = func_021A07B4(a, ((struct Obj12698 *)a)->f48C);
    ((struct Obj12698 *)a)->f350 = r;
    func_021A0980(a + 0x390, a + 0x356, a + 0x10 + r * 0x34, d);
}
















void func_021A05D8(u8 *a)
{
    u32 r;

    func_021A07B0();
    func_021A0734(a, ((struct Obj09537 *)a)->f354);
    r = func_021A07B4(a, ((struct Obj09537 *)a)->f48C);
    ((struct Obj09537 *)a)->f350 = r;
    func_021A0974((u32)(a + 0x390), (u32)(a + 0x356), (u32)(a + 0x10 + r * 0x34));
}
















void func_021A0618(u8 *p, u32 a, u32 b, u32 c)
{
    func_021A0C50((u32)(p + 0x484), b, (u16)c, a);
    ((struct Obj19694 *)p)->f0 = 1;
}
















void func_021A063C(u8 *p, u16 a, u32 b)
{
    func_021A0C60((u16 *)(p + 0x484), b, a);
    ((struct Obj19695 *)p)->f0 = 1;
}















/*
 * Unlabelled tail-call stub, filed for the ov026 lane.
 */
int func_021A065C(u8 *p)
{
    return func_021A0CE4((u16 *)(p + 0x484));
}















void func_021A066C(const W *w, u32 a, u32 p)
{
    int i;
    V3s zb = {0, 0, 0};
    u16 zc = 0;

    if (w->active == 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        if (w->used[i]) {
            func_02048CA4(p, i, &w->b[i]);
            func_02048CDC((struct LightSlot *)p, (u8)i, (u16 *)(&w->c[i]));
        } else {
            func_02048CA4(p, i, &zb);
            func_02048CDC((struct LightSlot *)p, (u8)i, &zc);
        }
    }
    func_0206AA8C(w->f37E, w->f380, 1);
    func_0206AAB0(w->f382, w->f384, 0);
    func_021A01C4(a, w->f386);
    func_0207DD24(w->f388, 0x1F, 0x7FFF, 0, 0);
}















void func_021A0734(u8 *a, u32 b)
{
    ((struct Obj19696 *)a)->f354 = b;
    func_021A0748(a, 0x3d, b);
}















void func_021A0748(u8 *a, u32 b, u32 c)
{
    u32 i;
    s32 j;
    u8 *q;

    ((struct Obj12699 *)a)->fC = func_020490A8(b, c) / 0x34;
    func_02048F4C(a + 0x10, b, c);
    for (i = 0; i < ((struct Obj12699 *)a)->fC; i++) {
        q = a + 0x20 + i * 0x34;
        for (j = 0; j < 4; j++) {
            func_0207CDB8(q + j * 6, q + j * 6);
        }
    }
}














/*
 * An empty function.
 */
void func_021A07B0(void)
{
}














u32 func_021A07B4(u8 *p, int t)
{
    int prev = 0;
    u32 i;
    int v;
    for (i = 0; i < ((struct Obj12700 *)p)->fC; i++) {
        v = func_021A07F8(((struct Obj12700 *)p)->f2, (Time *)(p + 0x10 + i * 0x34));
        if (prev <= t && v > t)
            return i;
        prev = v;
    }
    return 0;
}













int func_021A07F8(u32 a, Time *t)
{
    int h = func_02011400(a, t->h);
    return h * 3600 + t->m * 60;
}













void func_021A0818(s16 *o, s32 a, u32 b)
{
    o[0] = a & 0x1f;
    o[1] = (s16)(b & 0x1f) - (u16)o[0];
    o[2] = (a & 0x3e0) >> 5;
    o[3] = (s16)((b & 0x3e0) >> 5) - (u16)o[2];
    o[4] = (a & 0x7c00) >> 10;
    o[5] = (s16)((b & 0x7c00) >> 10) - (u16)o[4];
}












/*
 * Colour interpolation: three {base, delta} s16 pairs, each channel
 * base + delta * t / n, packed GX_RGB. Each channel is an s16 local set
 * from the quotient and then `+=` its base; a single-expression
 * initialiser lets the compiler hoist all three divisions and evaluate
 * them right to left.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021A0860(Lerp021A0860 *c, int t, int n)
{
    s16 r = (s16)(c[0].delta * t / n);
    s16 g, b;

    r += c[0].base;
    g = (s16)(c[1].delta * t / n);
    g += c[1].base;
    b = (s16)(c[2].delta * t / n);
    b += c[2].base;
    return GX_RGB(r, g, b);
}












static inline void set(V32 *o, s32 x, s32 y, s32 z)
{
    o->x = x;
    o->y = y;
    o->z = z;
}












/*
 * Addresses are Black-image addresses.
 * The `const` on `in` is what puts its three loads ahead of the stores in
 * the original's order (in[2], in[1], in[0]; stores o[1], o[2], o[0]).
 */
void func_021A08CC(s32 *o, const s16 *in, u32 c)
{
    s16 v[3];

    set((V32 *)o, in[0], in[1], in[2]);
    func_0207CB68(in, c, v);
    set((V32 *)(o + 3), v[0], v[1], v[2]);
    ((struct Obj19697 *)o)->f18 = func_0207D184(func_0207CAA4(in, c));
}












void func_021A0918(u8 *a, s32 x, s32 y, s16 *out)
{
    s32 m[12];
    s32 v[3];
    s32 vx, vy, vz;
    u32 i;

    i = (u16)(((struct Obj19698 *)a)->f18 * x / y) >> 4;
    func_0207B65C(m, a + 0xc, d_020A1B38[i * 2], d_020A1B38[i * 2 + 1]);
    func_0207BC08(a, m, v);
    func_0207CCA4(v, v);
    vz = v[2];
    vy = v[1];
    vx = v[0];
    out[0] = vx;
    out[1] = vy;
    out[2] = vz;
}












/*
 * Calls func_021A0980(its own argument 1, its own argument 2, its own argument 3, 0x3c) and returns nothing.
 */
void func_021A0974(u32 a1, u32 a2, u32 a3)
{
    func_021A0980((u8 *)a1, (u8 *)a2, (u8 *)a3, 0x3c);
}












void func_021A0980(u8 *a, u8 *b, u8 *c, u32 d)
{
    u8 *p0;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    int i;

    i = 0;
    ((struct Obj02080 *)a)->fF0 = i;
    ((struct Obj02080 *)a)->fF2 = d;
    ((struct Obj02080 *)a)->f0 = ((struct Obj03124 *)c)->f0;
    ((struct Obj02080 *)a)->f2 = ((struct Obj03124 *)c)->f2;
    p0 = a;
    p0 += 8;
    p1 = a;
    p1 += 0x38;
    p2 = b;
    p2 += 0x10;
    p3 = c;
    p3 += 0x10;
    for (; i < 4; i++) {
        func_021A0818((s16 *)(p0 + i * 12), *(u16 *)(b + 8 + i * 2), *(u16 *)(c + 8 + i * 2));
        func_021A08CC((s32 *)(p1 + i * 0x1c), (const s16 *)(p2 + i * 6), (u32)(p3 + i * 6));
        a[4 + i] = c[4 + i];
    }
    func_021A0818((s16 *)(a + 0xa8), ((struct Obj01498 *)b)->f28, ((struct Obj03124 *)c)->f28);
    func_021A0818((s16 *)(a + 0xb4), ((struct Obj01498 *)b)->f2A, ((struct Obj03124 *)c)->f2A);
    func_021A0818((s16 *)(a + 0xc0), ((struct Obj01498 *)b)->f2C, ((struct Obj03124 *)c)->f2C);
    func_021A0818((s16 *)(a + 0xcc), ((struct Obj01498 *)b)->f2E, ((struct Obj03124 *)c)->f2E);
    func_021A0818((s16 *)(a + 0xd8), ((struct Obj01498 *)b)->f30, ((struct Obj03124 *)c)->f30);
    func_021A0818((s16 *)(a + 0xe4), ((struct Obj01498 *)b)->f32, ((struct Obj03124 *)c)->f32);
}












void func_021A0A50(u8 *a, u8 *b, u32 c, u32 d)
{
    s32 i;

    ((struct Obj02080 *)a)->fF0 = 0;
    ((struct Obj02080 *)a)->fF2 = d;
    ((struct Obj02080 *)a)->f0 = ((struct Obj01498 *)b)->f0;
    ((struct Obj02080 *)a)->f2 = ((struct Obj01498 *)b)->f2;
    for (i = 0; i < 4; i++) {
        func_021A0818((s16 *)(a + 8 + i * 12), *(u16 *)(b + 8 + i * 2), c);
        func_021A08CC((s32 *)(a + 0x38 + i * 0x1c), (const s16 *)(b + 0x10 + i * 6), (u32)(b + 0x10 + i * 6));
        a[4 + i] = b[4 + i];
    }
    func_021A0818((s16 *)(a + 0xa8), ((struct Obj01498 *)b)->f28, c);
    func_021A0818((s16 *)(a + 0xb4), ((struct Obj01498 *)b)->f2A, c);
    func_021A0818((s16 *)(a + 0xc0), ((struct Obj01498 *)b)->f2C, c);
    func_021A0818((s16 *)(a + 0xcc), ((struct Obj01498 *)b)->f2E, c);
    func_021A0818((s16 *)(a + 0xd8), ((struct Obj01498 *)b)->f30, c);
    func_021A0818((s16 *)(a + 0xe4), ((struct Obj01498 *)b)->f32, c);
}












void func_021A0B14(Counter *p)
{
    if (p->cur < p->max)
        p->cur++;
}












int func_021A0B34(u32 a)
{
if (*(u16 *)((u8 *)((a + 240))) < *(u16 *)((u8 *)((a + 242)))) {
    return 1;
}
return 0;
}











/*
 * Inverse of func_021A0A50. The source pointer must be const: without it
 * the six trailing strh stores are scheduled ahead of the next call's
 * `adds rN, #0xf0/#0xf2` address setup (24 bytes differ).
 *
 * Addresses are Black-image addresses.
 */
void func_021A0B4C(const u8 *a, u8 *b)
{
    s32 i;
    u16 r;

    ((struct Obj03125 *)b)->f0 = *(const u16 *)&((struct Obj01034 *)a)->f0;
    ((struct Obj03125 *)b)->f2 = *(const s16 *)&((struct Obj01034 *)a)->f2;
    for (i = 0; i < 4; i++) {
        *(u16 *)(b + 8 + i * 2) = func_021A0860((Lerp021A0860 *)(a + 8 + i * 12), *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2);
        func_021A0918((u8 *)(a + 0x38 + i * 0x1c), *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2, (s16 *)(b + 0x10 + i * 6));
        b[4 + i] = a[4 + i];
    }
    r = func_021A0860((Lerp021A0860 *)(a + 0xa8), *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2);
    ((struct Obj03125 *)b)->f28 = r;
    r = func_021A0860((Lerp021A0860 *)(a + 0xb4), *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2);
    ((struct Obj03125 *)b)->f2A = r;
    r = func_021A0860((Lerp021A0860 *)(a + 0xc0), *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2);
    ((struct Obj03125 *)b)->f2C = r;
    r = func_021A0860((Lerp021A0860 *)(a + 0xcc), *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2);
    ((struct Obj03125 *)b)->f2E = r;
    r = func_021A0860((Lerp021A0860 *)(a + 0xd8), *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2);
    ((struct Obj03125 *)b)->f30 = r;
    r = func_021A0860((Lerp021A0860 *)(a + 0xe4), *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2);
    ((struct Obj03125 *)b)->f32 = r;
}











int func_021A0C50(u32 a, u16 b, u32 c, u32 d)
{
((struct Obj07214 *)((u8 *)(a)))->f0 = 1;
((struct Obj07214 *)((u8 *)(a)))->f2 = b;
((struct Obj07214 *)((u8 *)(a)))->f4 = c;
((struct Obj07214 *)((u8 *)(a)))->f6 = d;
return a;
}











void func_021A0C60(u16 *p, u16 a, u16 b)
{
    p[0] = 1;
    p[1] = a;
    p[3] = b;
    p[2] = 0xFFFF;
}











s32 func_021A0C74(u16 *a, void *b, void *c, void *d)
{
    switch (a[0]) {
    case 1:
        func_021A0A50(b, c, a[3], a[1]);
        a[0] = 2;
        break;
    case 2:
        if (func_021A0B34((u32)b) == 0) {
            if (a[2] != 0xFFFF) {
                func_021A0980(b, c, d, a[2]);
            }
            a[0] = 3;
        }
        break;
    case 3:
        if (func_021A0B34((u32)b) == 0) {
            a[0] = 0;
        }
        break;
    case 0:
        return 1;
    }
    return 0;
}










/*
 * Unlabelled leaf (ldrh; nonzero test), filed for the ov026 lane.
 */
int func_021A0CE4(u16 *p)
{
    if (*p != 0) {
        return 1;
    }
    return 0;
}










/*
 * Addresses are Black-image addresses.
 * d_021D872C is a const table of Mode rows (0x1C bytes each): the
 * `const` lets its load move ahead of the p[1] store, as in the original.
 */
u32 *func_021A0CF4(u32 a, u32 b, u32 c)
{
    u32 *p;
    u32 r;

    p = (u32 *)func_02030734((u16)a, 0x2c, 1, (const char *)d_021DDE48, 0x13c);
    p[2] = 0;
    ((struct Obj05021 *)p)->fC = a;
    p[8] = 0;
    p[5] = b;
    r = func_021A0EE4(p, c);
    p[0] = r;
    p[1] = r;
    d_021D872C[r].init(p, 0xb);
    return p;
}









/*
 * Addresses are Black-image addresses.
 */
u8 func_021A0D44(u32 *p)
{
    u32 id = p[0];
    d_021D8738[id].fn(p);
    func_020307B0(p);
    return id;
}









void func_021A0D68(u32 *a)
{
    switch (a[2]) {
    case 0:
        d_021D872C[a[0]].update(a, func_02189A2C((int *)a[5]) == 0);
        break;
    case 1:
        func_0202208C((void *)4, 0, 0, 0, 1, 1, ((struct Obj02081 *)a)->fC);
        a[2] = 2;
        break;
    case 2:
        if (func_020221A4() == 1) {
            d_021D872C[a[0]].exit(a);
            d_021D872C[a[1]].init(a, a[0]);
            a[0] = a[1];
            a[2] = 4;
        }
        break;
    case 3:
        break;
    case 4:
        func_0202208C((void *)4, 1, 1, 0, 1, 1, ((struct Obj02081 *)a)->fC);
        a[2] = 5;
        break;
    case 5:
        if (func_020221A4() == 1) {
            a[2] = 0;
        }
        d_021D872C[a[0]].update(a, func_02189A2C((int *)a[5]) == 0);
        break;
    }
}









void func_021A0E58(u32 *a)
{
    s32 r;

    switch (a[2]) {
    case 0:
        if (*(u32 *)(d_021D8734 + a[0] * 0x1c) != 0) {
            r = func_02189A2C((int *)a[5]);
            ((void (*)(u32 *, s32))*(u32 *)(d_021D8734 + a[0] * 0x1c))(a, r == 0);
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        break;
    }
}









int func_021A0EB0(u32 *p, u32 a)
{
    if (p[2] == 0 && d_021D8738[p[0]].init != 0)
        return d_021D8738[p[0]].init(p, a);
    return 0;
}









/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A0ED4(u32 a)
{
if (((struct Obj17989 *)((u8 *)(a)))->f8 == 0) {
    return 1;
}
return 0;
}









u32 ov021_func_021A0EE4(p, x)
u32 *p;





u32 x;





{
    u32 a, b;
    if (x == 0) {
        a = (u32)func_020120F4(func_02188C80((void *)p[5]));
        b = func_02188C9C((u8 *)p[5]);
        if (func_02013D20() != 0 || func_02013D00(b) != 0)
            return 5;
        func_02012EBC((struct Big *)a);
        func_02009210();
        if (func_020090E0() == 0)
            return 5;
    }
    return x;
}


int func_021A0F30(u32 a, u32 b)
{
((struct Obj12083 *)((u8 *)(a)))->f4 = func_021A0EE4(a, b);
((struct Obj12083 *)((u8 *)(a)))->f8 = 1;
return 1;
}


void func_021A0F40(u32 *p, u32 v)
{
    u32 n = func_021A0EE4(p);
    d_021D872C[p[0]].exit(p);
    p[1] = n;
    d_021D872C[n].init(p, p[0]);
    p[0] = p[1];
    p[2] = 0;
}






/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A0F7C(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj07215 *)((u8 *)(a)))->f18 = c;
((struct Obj07215 *)((u8 *)(a)))->f1C = d;
((struct Obj07215 *)((u8 *)(a)))->f4 = func_021A0EE4(a, b, c, d);
((struct Obj07215 *)((u8 *)(a)))->f8 = 1;
return 1;
}






/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A0F90(u8 *p)
{
    return ((struct Obj17990 *)p)->f0;
}






int func_021A0F94(u32 a)
{
if (a != 0) {
    return ((struct Obj17991 *)((u8 *)(a)))->f10;
}
return 0;
}






/*
 * Guarded store of the second argument at +0x10.
 *
 * Addresses are Black-image addresses.
 */
void func_021A0FA0(int *p, int v)
{
    if (p == 0)
        return;
    p[4] = v;
}






/*
 * Tail call with a zero second argument.
 *
 * Addresses are Black-image addresses.
 */
void func_021A0FA8(int *p)
{
    func_021A0FA0(p, 0);
}






/*
 * Addresses are Black-image addresses.
 */
void func_021A0FB4(u32 *p, u32 a)
{
    func_021D3270(func_02188E30((u8 *)p[5]), 1, 0, 0, 0, 0);
    func_02193060(0);
    func_020414EC(1);
    func_021902A4(1, a);
}





void ov021_func_021A0FE8(u32 *p)
{
    u32 a, b, c, d;
    a = (u32)func_02188C80((void *)p[5]);
    b = (u32)func_02009210(func_02012EBC(func_020120F4((const struct Ctx *)a)));
    func_02034AC4((int)abs_id_1d);
    c = func_02009208((const struct Sub020090B0Obj *)b);
    d = func_0201214C((const struct Ctx *)a);
    p[8] = (u32)func_021F279C(b, (int)p, a, d == 1 && c == 0);
    func_02009200(b, d);
    if (func_02012204((const struct Ctx *)a) != 0)
        func_02012210((struct Ctx *)a);
}





void ov021_func_021A1050(u32 *p)
{
    u32 a, b, c, d;
    a = (u32)func_02188C80((void *)p[5]);
    b = (u32)func_02012EBC(func_020120F4((const struct Ctx *)a));
    func_02034AC4((int)abs_id_1d);
    c = func_0201214C((const struct Ctx *)a);
    d = (u32)func_02009210((void *)b);
    p[8] = (u32)func_021F27D8(d, (int)p, (int)func_02188C80((void *)p[5]), (void (*)(int))p[6], p[7], c);
    func_02009200(d, c);
    if (func_02012204((const struct Ctx *)a) != 0)
        func_02012210((struct Ctx *)a);
    p[0] = 0;
    p[1] = 0;
}



void func_021A10C0(u32 *p)
{
    func_021F2984((char *)p[8]);
    func_02034A5C((int)abs_id_1d);
}

u32 func_021A10D4(u32 *p) { return func_021F2980(p[8]); }


u32 ov021_func_021A10E0(u32 *p, u32 x)
{
    u32 a, b;
    if (x != 0) {
        a = (u32)func_02188C80((void *)p[5]);
        b = (u32)func_02009210(func_02012EBC(func_020120F4((const struct Ctx *)a)));
        if (func_02012204((const struct Ctx *)a) != 0) {
            if (func_0201214C((const struct Ctx *)a) != 0) {
                func_02012210((struct Ctx *)a);
            } else if (func_021F2994((int *)p[8]) != 0) {
                func_02009200(b, 0);
                func_02012210((struct Ctx *)a);
            }
        }
    }
    return func_021F2848(p[8], x);
}

int func_021F29D8();
typedef struct HidObj_021A1138 {
    int f0[8];
    char * f20;
} HidObj_021A1138;

int func_021A1138(HidObj_021A1138 *w, int b)
{
    return func_021F29D8(w->f20, b, w);
}
