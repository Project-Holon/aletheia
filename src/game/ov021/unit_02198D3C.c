/*
 * file:     unit_02198D3C.c
 * unit:     yes
 * function: func_02198D3C, func_02198D4C, func_02198D5C, func_02198D6C, func_02198D7C, func_02198D94, func_02198DA4, func_02198DB4, func_02198DC4, func_02198DD4, func_02198DEC, func_02198DFC, func_02198E0C, func_02198E1C, func_02198E2C, func_02198E44, func_02198E60, func_02198E7C, func_02198E98, func_02198EB0, func_02198EC8, func_02198F20, func_02198F68, func_02198FB0, func_02199034, func_02199050, func_02199070, func_02199088, func_021990A0, func_021990B8, func_021990D4, func_0219912C, func_021991F0, func_02199234, func_02199268, func_02199298, func_021992CC, func_021992FC, func_0219932C, func_02199360, func_02199394, func_021993C8, func_021993FC, func_02199430, func_02199460, func_02199490, func_021994C0, func_021994F0, func_02199520, func_02199550, func_02199584, func_021995B8, func_021995E8, func_02199618, func_0219964C, func_02199680, func_021996B4, func_021996E8, func_0219971C, func_02199750, func_02199784, func_021997B8, func_021997EC, func_02199820, func_02199854, func_02199888, func_02199970, func_02199AEC, func_02199B10, func_02199B38, func_02199B60, func_02199B88, func_02199BAC, func_02199BD8, func_02199C00, func_02199C28, func_02199C50, func_02199C7C, func_02199CA4, func_02199CC8, func_02199CE4, func_02199D00, func_02199D14, func_02199D4C, func_02199D8C, func_02199DB4, func_02199EAC, func_02199EC0, func_02199ED4, func_02199F30, func_02199F50, func_02199F94, func_0219A014, func_0219A028, func_0219A03C, func_0219A058, func_0219A07C, func_0219A098, func_0219A0CC, func_0219A0D8, func_0219A0E4, func_0219A0F0, func_0219A0FC, func_0219A108, func_0219A114, func_0219A120, func_0219A12C, func_0219A138, func_0219A144, func_0219A150, func_0219A1E8, func_0219A24C, func_0219A250, func_0219A260, func_0219A270, func_0219A280, func_0219A290, func_0219A2B8, func_0219A3D8, func_0219A4CC, func_0219A528, func_0219A54C, func_0219A574, func_0219A580, func_0219A58C, func_0219A598, func_0219A5A4, func_0219A5C8, func_0219A5D4, func_0219A5E0, func_0219A604, func_0219A638, func_0219A660, func_0219A6CC, func_0219A750, func_0219A75C, func_0219A780, func_0219A7A8, func_0219A7C4, func_0219A7DC, func_0219A87C, func_0219A89C, func_0219A8C0, func_0219A900, func_0219AA08, func_0219AA38, func_0219AA68, func_0219AA78, func_0219AA88, func_0219AA98, func_0219AAA8, func_0219AAB8, func_0219AAC8, func_0219AAD8, func_0219AAE8, func_0219AAF8, func_0219AB08, func_0219AB18, func_0219AB28, func_0219AB38, func_0219AB48, func_0219AB58, func_0219AB68, func_0219AB8C, func_0219ACE8, func_0219AD18, func_0219AD48, func_0219AD58, func_0219AD68, func_0219AD78, func_0219AD88, func_0219AD98, func_0219ADA8, func_0219ADB8, func_0219ADC8, func_0219ADEC, func_0219AE10, func_0219AE68, func_0219AEC8, func_0219B030, func_0219B060, func_0219B074, func_0219B0C4, func_0219B0D8, func_0219B0F0, func_0219B104, func_0219B120, func_0219B13C, func_0219B200, func_0219B2E8, func_0219B334, func_0219B358, func_0219B374, func_0219B390, func_0219B404, func_0219B414, func_0219B41C, func_0219B440, func_0219B45C, func_0219B478, func_0219B494, func_0219B4C8
 * address:  0x02198D3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02198C08  0x02198C08  thumb
 *   func_02198C4C       0x02198C4C  thumb
 *   DWCca_ghttp_caList  0x021D4A44  data
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02198E44  0x02198E44  thumb
 *   func_02198E60  0x02198E60  thumb
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_020508EC  0x020508EC  arm
 *   func_0219BF48  0x0219BF48  thumb  ov021
 *   func_021D04A4  0x021D04A4  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   d_021DDBD4     0x021DDBD4  data   ov021  a4
 *   func_021D04C4  0x021D04C4  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0219BF3C  0x0219BF3C  thumb  ov021
 *   func_0219BF54  0x0219BF54  thumb  ov021
 *   d_021D4C1C     0x021D4C1C  data   a4
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D600  0x0216D600  thumb  ov010
 *   func_0216DA70  0x0216DA70  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D80C  0x0216D80C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D818  0x0216D818  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D824  0x0216D824  thumb  ov010
 *   func_0216D848  0x0216D848  thumb  ov010
 *   func_0216D860  0x0216D860  thumb  ov010
 *   func_0216D87C  0x0216D87C  thumb  ov010
 *   func_02163F8C  0x02163F8C  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   d_021D4B44     0x021D4B44  data  ov021  a4
 *   d_021D4204     0x021D4204  data  ov021  a4
 *   d_021D4C04     0x021D4C04  data  a4
 *   d_021D41E0     0x021D41E0  data  ov021  a4
 *   d_021D4210     0x021D4210  data  a4
 *   d_021D4C10     0x021D4C10  data  a4
 *   d_021D4648     0x021D4648  data  a4
 *   d_021D4BF8     0x021D4BF8  data  a4
 *   d_021D4BEC     0x021D4BEC  data  a4
 *   d_021D4BE0     0x021D4BE0  data  a4
 *   d_021D4BD4     0x021D4BD4  data  a4
 *   d_021D4BC8     0x021D4BC8  data  a4
 *   d_021D4BBC     0x021D4BBC  data  a4
 *   d_021D4BB0     0x021D4BB0  data  a4
 *   d_021D4BA4     0x021D4BA4  data  a4
 *   d_021D4B98  0x021D4B98  data  a4
 *   d_021D4B8C  0x021D4B8C  data  a4
 *   d_021D4B80  0x021D4B80  data  a4
 *   d_021D4B74  0x021D4B74  data  a4
 *   d_021D4B68  0x021D4B68  data  a4
 *   d_021D4B5C  0x021D4B5C  data  a4
 *   d_021D4B50  0x021D4B50  data  a4
 *   d_021D45E8  0x021D45E8  data  a4
 *   d_021D4B38  0x021D4B38  data  a4
 *   d_021D4B2C  0x021D4B2C  data  a4
 *   d_021D4B20  0x021D4B20  data  a4
 *   d_021D4B14  0x021D4B14  data  a4
 *   d_021D4B08  0x021D4B08  data  a4
 *   d_021D4AFC  0x021D4AFC  data  a4
 *   d_021D4AF0  0x021D4AF0  data  a4
 *   d_021D4AE4  0x021D4AE4  data  a4
 *   d_021D4AD8  0x021D4AD8  data  a4
 *   _s32_div_f     0x0209C0A4  arm
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_02163E7C  0x02163E7C  thumb  ov010
 *   func_02163FC0  0x02163FC0  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_0219FC68  0x0219FC68  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   d_021D4ACC     0x021D4ACC  data  a4
 *   func_0219FCC0  0x0219FCC0  thumb  ov021
 *   func_0219FE64  0x0219FE64  thumb  ov021
 *   func_0219FE20  0x0219FE20  thumb  ov021
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb
 *   d_021D4FA4     0x021D4FA4  data  a4
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 *   func_02164168  0x02164168  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   d_021D5074  0x021D5074  data  a4
 *   func_0216DA7C  0x0216DA7C  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_021639C0  0x021639C0  thumb  ov010
 *   func_0216DA44  0x0216DA44  thumb  ov010
 *   func_0216D7E8  0x0216D7E8  thumb  ov010
 *   func_0216D7F8  0x0216D7F8  thumb  ov010
 *   func_0216D660  0x0216D660  thumb  ov010
 *   func_0216D66C  0x0216D66C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   d_021D4DE8  0x021D4DE8  data  a4
 *   d_021D5024     0x021D5024  data  a4
 *   d_021D5038     0x021D5038  data  a4
 *   d_021D4DB8  0x021D4DB8  data  a4
 *   d_021D504C     0x021D504C  data  a4
 *   d_021D5060     0x021D5060  data  a4
 *   func_0216D5D4  0x0216D5D4  thumb  ov010
 *   func_021642A4  0x021642A4  thumb  ov010
 *   d_021D4D60  0x021D4D60  data  a4
 *   func_0216D608  0x0216D608  thumb  ov010
 *   d_021D4D04  0x021D4D04  data  a4
 *   d_021D4D78  0x021D4D78  data  a4
 *   func_0216D63C  0x0216D63C  thumb  ov010
 *   func_021AE198  0x021AE198  thumb  ov021
 *   func_0216E0E8  0x0216E0E8  thumb  ov010
 *   d_021D4F90     0x021D4F90  data    a2
 *   func_0203630C  0x0203630C  arm
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_0216D7C4  0x0216D7C4  thumb  ov010
 *   func_020362DC  0x020362DC  arm
 *   func_020056EC  0x020056EC  thumb
 *   d_021D50F8  0x021D50F8  data  a4
 *   func_021642B4  0x021642B4  thumb  ov010
 *   d_021D4FEC  0x021D4FEC  data  a4
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   d_021D4FCC     0x021D4FCC  data    a4
 *   func_0216D550  0x0216D550  thumb  ov010
 *   data_021D5278  0x021D5278  data   ov021  a4
 *   d_021D52CC  0x021D52CC  data  a4
 *   d_021D5320  0x021D5320  data  a4
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 */
#include "../../matched/include/Obj17953.h"
#include "../../matched/include/Obj04222.h"
#include "../../matched/include/Obj09499.h"
#include "../../matched/include/Obj12643.h"
#include "../../matched/include/Obj12644.h"
#include "../../matched/include/Obj17954.h"
#include "../../matched/include/Obj12074.h"
#include "../../matched/include/Obj17955.h"
#include "../../matched/include/Obj12075.h"
#include "../../matched/include/Obj17956.h"
#include "../../matched/include/Obj17957.h"
#include "../../matched/include/Obj17958.h"

struct Actor;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int BOOL;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { int x, y, z; } Vec;

typedef struct { int w[10]; } T40;

typedef struct {
    u8  count;
    u8  axis;
    u8  moveAxis;
    u8  negate;
    int speed;
    int accum;
    u16 angle;
    u16 step;
} State_02198EB0;

typedef struct { u16 a; u16 b; u32 c; u32 d; } S12;

typedef struct {
    int pos;
    int vel;
    u16 timer;
    u8  last;
} State_02199DB4;

typedef struct { u16 x; s16 n; u32 v; } St_0219A150;

typedef struct {
    s16 state;
    s16 timer;
    int mode;
    u32 arg;
    u32 v;
} St_0219A260;

typedef struct { int left, top, right, bottom; } Rect;

typedef struct { u32 v; int n; } St_02198D3C;

typedef int (*Step)(u32, u8 *);

typedef struct { u16 x; u8 b; u8 pad; int n; } St_0219A5E0;

typedef struct { int v[5]; } Arr;

typedef struct { u8 a; s8 b; u8 c[3]; u8 f; } St_0219A7DC;

typedef struct St_0219AE10 {
    u8 f0;
    s8 step;
    u8 last;
    u8 axis;
    u8 id;
    u8 f5;
    u8 f6;
    u8 f7;
    s8 f8;
} St_0219AE10;

typedef struct { u32 id; u32 *tbl; } Ent;

typedef u32 (*Handler)(u32);

extern void func_02198C08(u32 a1, u32 a2, u32 a3, u32 a4);
extern int func_02198C4C(u32 a, u32 *b);
extern u32 func_0216D674(void *p, u16 v);
extern void *func_0216D6BC();
extern u32 func_0216D7CC(u32);
int func_02198E44();
extern void func_020061E4(unsigned int arg);
int func_02198E60();
extern void *func_0216D6D4(void *p);
extern int func_0216D7A8(void *p, unsigned int v);
extern void *func_0216D67C(void *a0);
extern u32 func_0216D520(void *p);
extern u32 func_0219C9DC(u8 *p);
extern u32 func_020508EC(u8 *p, int i, u16 *out);
extern int func_0219BF48(u32 a);
extern void func_021D04A4(void *a);
extern void func_0216D8C0(u32, Vec *);
extern void *func_0216D568(void *p, u32 v);
extern char *func_0216D570(char *p, u32 v);
extern int func_021D04C4(u32 a);
extern u32 func_021AC154(u32);
extern void func_0219BF3C(int a, u32 v);
extern void func_0219BF54(int a0);
extern void func_0216D5E0(int a0, int a1);
extern int func_0216D600(int a0, u16 a1);
extern void func_0216DA70(void *a0);
extern int func_0216D83C(void *p);
extern u32 func_0216D80C(u32, u32);
extern int func_0216D854(void *p);
extern u32 func_0216D818(u32, u32);
extern int func_0216D86C(void *p);
extern u32 func_0216D824(u32, u32);
extern void func_0216D848(char *p, short v);
extern void func_0216D860(char *p, short v);
extern void func_0216D87C(char *p, short v);
extern u32 func_02163F8C(u32, int *);
extern int func_02163F10(int a0);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void func_0216D89C(u32, Vec *);
extern void func_02163E7C(int a, int b);
extern void func_02163FC0(int a, int dir, int amt);
extern int func_02164010(int a);
extern int func_0219FC68(u32, u16 *, u16 *);
extern u16 func_0216D598(void *p);
extern int func_0219FCC0(u32, u16 *, u16 *);
extern void func_0219FE64(u32 a);
extern u32 func_0219FE20(u32, u32, u32, u32);
extern void *func_0216D684();
extern int func_0216DA50(u32);
extern void *func_0216D69C(void *p);
extern u16 func_0216D5A8(u8 *p);
extern int func_02164168(int a);
extern u16 func_0216D5F8(void *p);
extern u16 func_0216D5A0(void *p);
extern void func_0216DA7C(u8 *p);
extern int func_02197E7C(int a, int b);
extern void func_0216D438(char *a0, int a1);
extern u32 func_02197EDC(u8 *p);
extern void func_0216D60C(u32, u16);
extern int func_021639C0(u32, u16);
extern void func_0216DA44(u32);
extern int func_0216D7E8(void *p);
extern int func_0216D7F8(void *p);
extern int func_0216D660(void *p);
extern int func_0216D66C(void *p);
extern int func_021641E8(int a);
extern int func_021641F8(u16);
int func_0219A528();
void func_0219A54C(u32 a);
int func_0219A574(u32 a);
int func_0219A580(u32 a);
int func_0219A58C(u32 a);
int func_0219A598(u32 a);
void func_0219A5A4(u32 a, u8 b);
void func_0219A5C8(u32 a);
void func_0219A5D4(u32 a);
void func_0219A5E0(u32 a);
int func_0219A604(u32 a, u8 *s);
int func_0219A638(u32 a, u32 b, u32 c, u32 d);
int func_0219A660(u32 a, St_0219A5E0 *p);
int func_0219A6CC(u32 a, s8 *b);
void func_0219A750(u32 a);
void func_0219A75C(u32 a);
int func_0219A780(char *a, u32 b, u32 c, u32 d);
int func_0219A7A8(u32 a, u32 b, u32 c, u32 d);
int func_0219A7C4(int a, u8 *p);
extern int func_0216D5D4(void *p);
extern u16 func_021642A4(int i);
extern u16 func_0216D608(void *p);
extern int func_0216D63C(char *a0, int a1);
extern int func_021AE198(int a, int b, int c, int d);
extern int func_0216E0E8(int a0, int a1);
extern unsigned int func_0203630C(void);
extern void *func_0216DEE0(void *a0);
extern u16 func_0216D7C4(u8 *p);
extern u32 func_020362DC(void);
extern u32 func_020056EC(u32);
extern u16 func_021642B4(int x0, int y0, int x1, int y1);
extern int func_0216D55C(int a, int b);
extern u32 *func_0216D548(u32 *p, u32 v);
extern u32 *func_0216D550(u32 *p, u32 v);
extern int func_0216D804(void *p);
extern int func_0216D81C(void *p);
u32 func_02198D3C(u32 a1);
u32 func_02198D4C(u32 a1);
u32 func_02198D5C(u32 a1);
u32 func_02198D6C(u32 a1);
BOOL func_02198D7C(char *url);
u32 func_02198D94(u32 a1);
u32 func_02198DA4(u32 a1);
u32 func_02198DB4(u32 a1);
u32 func_02198DC4(u32 a1);
BOOL func_02198DD4(char *url);
u32 func_02198DEC(u32 a1);
u32 func_02198DFC(u32 a1);
u32 func_02198E0C(u32 a1);
u32 func_02198E1C(u32 a1);
BOOL func_02198E2C(char *url);
;
void func_02198E98(void *pipe);
void func_02198EB0(void *pipe);
int func_02198EC8(u32 a);
int func_02198F20(u32 a);
int func_02198F68(u32 a);
int func_02198FB0(u32 a);
int func_02199034(u32 a, u16 b, u32 c, u32 d);
int func_02199050(u32 a);
int func_02199070(u32 a, u32 b, u32 c, u32 d);
int func_02199088(u32 a, u32 b, u32 c, u32 d);
int func_021990A0(u32 a, u32 b, u32 c, u32 d);
int func_021990B8(u32 a, u32 b, u32 c, u32 d);
int func_021990D4(u32 a);
void func_0219912C(u32 a, Vec *b, u32 c, u32 d, u32 e, u8 f);
int func_021991F0(u32 a);
int func_02199234(u32 a);
int func_02199268(u32 a);
int func_02199298(u32 a);
int func_021992CC(u32 a);
int func_021992FC(u32 a);
int func_0219932C(u32 a);
int func_02199360(u32 a);
int func_02199394(u32 a);
int func_021993C8(u32 a);
int func_021993FC(u32 a);
int func_02199430(u32 a);
int func_02199460(u32 a);
int func_02199490(u32 a);
int func_021994C0(u32 a);
int func_021994F0(u32 a);
int func_02199520(u32 a);
int func_02199550(u32 a);
int func_02199584(u32 a);
int func_021995B8(u32 a);
int func_021995E8(u32 a);
int func_02199618(u32 a);
int func_0219964C(u32 a);
int func_02199680(u32 a);
int func_021996B4(u32 a);
int func_021996E8(u32 a);
int func_0219971C(u32 a);
int func_02199750(u32 a);
int func_02199784(u32 a);
int func_021997B8(u32 a);
int func_021997EC(u32 a);
int func_02199820(u32 a);
int func_02199854(u32 a);
void func_02199888(u32 a, int b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h, u8 i);
int func_02199970(u32 a);
int func_02199AEC(u32 a);
int func_02199B10(u32 a);
int func_02199B38(u32 a);
int func_02199B60(u32 a);
int func_02199B88(u32 a);
int func_02199BAC(u32 a);
int func_02199BD8(u32 a);
int func_02199C00(u32 a);
int func_02199C28(u32 a);
int func_02199C50(u32 a);
int func_02199C7C(u32 a);
int func_02199CA4(u32 a);
int func_02199CC8(u32 a, u32 b, u32 c, u32 d);
int func_02199CE4(u32 a);
int func_02199D00(u32 a, u32 b, u32 c, u32 d);
int func_02199D14(u32 a);
int func_02199D4C(u32 a);
int func_02199D8C(u32 a);
int func_02199DB4(u32 a);
int func_02199EAC(u32 a, u32 b, u32 c, u32 d);
int func_02199EC0(u32 a, u32 b, u32 c, u32 d);
int func_02199ED4(u32 a);
int func_02199F30(u32 a);
int func_02199F50(u32 a);
int func_02199F94(u32 a);
int func_0219A014(u32 a, u32 b, u32 c, u32 d);
int func_0219A028(u32 a, u32 b, u32 c, u32 d);
int func_0219A03C(u32 a, u32 b, u32 c, u32 d);
int func_0219A058(u32 a, u32 b, u32 c, u32 d);
int func_0219A07C(u32 a, u32 b, u32 c, u32 d);
int func_0219A098(u32 a, u32 b);
int func_0219A0CC(u32 a);
int func_0219A0D8(u32 a);
int func_0219A0E4(u32 a);
int func_0219A0F0(u32 a);
int func_0219A0FC(u32 a);
int func_0219A108(u32 a);
int func_0219A114(u32 a);
int func_0219A120(u32 a);
int func_0219A12C(u32 a);
int func_0219A138(u32 a);
int func_0219A144(u32 a);
void func_0219A150(u32 a);
u16 func_0219A1E8(u16 key, u16 v);
void func_0219A24C(void);
void func_0219A250(u32 a1);
void func_0219A260(u32 a1);
void func_0219A270(u32 a1);
void func_0219A280(u32 a1);
void func_0219A290(u32 a, u32 b, u32 c, u32 d);
void func_0219A2B8(u32 a);
void func_0219A3D8(u32 a, Rect *r);
int func_0219A4CC(u32 a, u32 b);
int func_0219A7DC(u32 a, s8 *b);
void func_0219A87C(u32 a);
void func_0219A89C(u32 a);
int func_0219A8C0(u32 a, u8 *b);
int func_0219A900(u32 a, u8 *b);
int func_0219AA08(u32 a, u32 b, u32 c, u32 d);
void func_0219AA38(u32 a, u32 b, u32 c, u32 d);
void func_0219AA68(u32 a1);
void func_0219AA78(u32 a1);
void func_0219AA88(u32 a1);
void func_0219AA98(u32 a1);
void func_0219AAA8(u32 a1);
void func_0219AAB8(u32 a1);
void func_0219AAC8(u32 a1);
void func_0219AAD8(u32 a1);
void func_0219AAE8(u32 a1);
void func_0219AAF8(u32 a1);
void func_0219AB08(u32 a1);
void func_0219AB18(u32 a1);
void func_0219AB28(u32 a1);
void func_0219AB38(u32 a1);
void func_0219AB48(u32 a1);
void func_0219AB58(u32 a1);
void func_0219AB68(u32 a);
int func_0219AB8C(char *a, u8 *b);
int func_0219ACE8(u32 a, u32 b, u32 c, u32 d);
void func_0219AD18(u32 a, u32 b, u32 c, u32 d);
void func_0219AD48(u32 a1);
void func_0219AD58(u32 a1);
void func_0219AD68(u32 a1);
void func_0219AD78(u32 a1);
void func_0219AD88(u32 a1);
void func_0219AD98(u32 a1);
void func_0219ADA8(u32 a1);
void func_0219ADB8(u32 a1);
void func_0219ADC8(u32 a);
void func_0219ADEC(St_0219A7DC *p);
int func_0219AE10(char *a, u8 *b);
int func_0219AE68(int a, s8 *b);
int func_0219AEC8(char *a, St_0219AE10 *b);
int func_0219B030(u32 a, u32 b, u32 c, u32 d);
int func_0219B060(void);
int func_0219B074(int a);
int func_0219B0C4(void);
int func_0219B0D8(u32 *t, u32 v);
int func_0219B0F0(u32 a, u32 b);
u32 func_0219B104(u32 a, u32 b);
u32 *func_0219B120(u32 id);
int func_0219B13C(u32 a);
int func_0219B200(int a, int id, int end);
int func_0219B2E8(int a, u8 *b);
int func_0219B334(u32 a);
int func_0219B358(u32 a);
void func_0219B374(u32 a, u8 *s);
void func_0219B390(int a, s8 *b);
void func_0219B404(u32 a, u8 *s);
int func_0219B414(int a);
int func_0219B41C(u32 a, u32 b, u32 c, u32 d);
int func_0219B440(char *a);
u32 func_0219B45C(u32 a, u32 b, u32 c, u32 d);
u32 func_0219B478(u32 a);
int func_0219B494(int a);
int func_0219B4C8(int a);
extern char DWCca_ghttp_caList[];
extern int *d_021DDBD4[2];
extern T40 d_021D4C1C;
extern const Vec d_021D4B44;
extern const Vec d_021D4204;
extern const Vec d_021D4C04;
extern const Vec d_021D41E0;
extern const Vec d_021D4210;
extern const Vec d_021D4C10;
extern const Vec d_021D4648;
extern const Vec d_021D4BF8;
extern const Vec d_021D4BEC;
extern const Vec d_021D4BE0;
extern const Vec d_021D4BD4;
extern const Vec d_021D4BC8;
extern const Vec d_021D4BBC;
extern const Vec d_021D4BB0;
extern const Vec d_021D4BA4;
extern const Vec d_021D4B98;
extern const Vec d_021D4B8C;
extern const Vec d_021D4B80;
extern const Vec d_021D4B74;
extern const Vec d_021D4B68;
extern const Vec d_021D4B5C;
extern const Vec d_021D4B50;
extern const Vec d_021D45E8;
extern const Vec d_021D4B38;
extern const Vec d_021D4B2C;
extern const Vec d_021D4B20;
extern const Vec d_021D4B14;
extern const Vec d_021D4B08;
extern const Vec d_021D4AFC;
extern const Vec d_021D4AF0;
extern const Vec d_021D4AE4;
extern const Vec d_021D4AD8;
extern const Vec d_021D4ACC;
extern u8 d_021D4FA4[];
extern u16 d_021D5074[][6];
extern Step d_021D4DE8[];
extern const Arr d_021D5024;
extern const Arr d_021D5038;
extern Step d_021D4DB8[];
extern const Arr d_021D504C;
extern const Arr d_021D5060;
extern Step d_021D4D60[];
extern Step d_021D4D04[];
extern Step d_021D4D78[];
extern u16 d_021D4F90[];
extern Ent d_021D50F8[];
extern u32 d_021D4FEC[];
extern u32 d_021D4FCC[][4];
extern Handler d_021D52CC[];
extern Handler d_021D5320[];

;


;



;




;





;






;







;








;









;










;











;












;













;














;















;
















;

















;


















;



















;




















;





















;






















;























;
























;

























;





























/*
 * Calls func_02198C08(its own argument 1, 0x0, 0x3, 0x7) and returns 0x1.
 */
u32 func_02198D3C(u32 a1)
{
    func_02198C08(a1, 0x0, 0x3, 0x7);

    return 0x1;
}





























/*
 * Calls func_02198C08(its own argument 1, 0x1, 0x3, 0x7) and returns 0x1.
 */
u32 func_02198D4C(u32 a1)
{
    func_02198C08(a1, 0x1, 0x3, 0x7);

    return 0x1;
}





























/*
 * Calls func_02198C08(its own argument 1, 0x2, 0x3, 0x7) and returns 0x1.
 */
u32 func_02198D5C(u32 a1)
{
    func_02198C08(a1, 0x2, 0x3, 0x7);

    return 0x1;
}





























/*
 * Calls func_02198C08(its own argument 1, 0x3, 0x3, 0x7) and returns 0x1.
 */
u32 func_02198D6C(u32 a1)
{
    func_02198C08(a1, 0x3, 0x3, 0x7);

    return 0x1;
}





























/*
 * TwlDWC GHTTP root CA list setter (libdwcghttp / dwc_ghttp.o).
 * Forwards the URL and this file's CA list to ghttpSetRootCAList and
 * returns whether it reports success (1).
 */
BOOL func_02198D7C(char *url)
{
    if (func_02198C4C((u32)url, (u32 *)DWCca_ghttp_caList) == 1)
    {
        return 1;
    }
    return 0;
}





























/*
 * Calls func_02198C08(its own argument 1, 0x0, 0x7, 0x8) and returns 0x1.
 */
u32 func_02198D94(u32 a1)
{
    func_02198C08(a1, 0x0, 0x7, 0x8);

    return 0x1;
}





























/*
 * Calls func_02198C08(its own argument 1, 0x1, 0x7, 0x8) and returns 0x1.
 */
u32 func_02198DA4(u32 a1)
{
    func_02198C08(a1, 0x1, 0x7, 0x8);

    return 0x1;
}





























/*
 * Calls func_02198C08(its own argument 1, 0x2, 0x7, 0x8) and returns 0x1.
 */
u32 func_02198DB4(u32 a1)
{
    func_02198C08(a1, 0x2, 0x7, 0x8);

    return 0x1;
}





























/*
 * Calls func_02198C08(its own argument 1, 0x3, 0x7, 0x8) and returns 0x1.
 */
u32 func_02198DC4(u32 a1)
{
    func_02198C08(a1, 0x3, 0x7, 0x8);

    return 0x1;
}





























BOOL func_02198DD4(char *url)
{
    if (func_02198C4C((u32)url, (u32 *)DWCca_ghttp_caList) == 1)
    {
        return 1;
    }
    return 0;
}





























/*
 * Calls func_02198C08(its own argument 1, 0x0, 0xc, 0x9) and returns 0x1.
 */
u32 func_02198DEC(u32 a1)
{
    func_02198C08(a1, 0x0, 0xc, 0x9);

    return 0x1;
}





























/*
 * Calls func_02198C08(its own argument 1, 0x1, 0xc, 0x9) and returns 0x1.
 */
u32 func_02198DFC(u32 a1)
{
    func_02198C08(a1, 0x1, 0xc, 0x9);

    return 0x1;
}





























/*
 * Calls func_02198C08(its own argument 1, 0x2, 0xc, 0x9) and returns 0x1.
 */
u32 func_02198E0C(u32 a1)
{
    func_02198C08(a1, 0x2, 0xc, 0x9);

    return 0x1;
}





























/*
 * Calls func_02198C08(its own argument 1, 0x3, 0xc, 0x9) and returns 0x1.
 */
u32 func_02198E1C(u32 a1)
{
    func_02198C08(a1, 0x3, 0xc, 0x9);

    return 0x1;
}





























BOOL func_02198E2C(char *url)
{
    if (func_02198C4C((u32)url, (u32 *)DWCca_ghttp_caList) == 1)
    {
        return 1;
    }
    return 0;
}





























/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D7CC (0x0216D7CC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02198E44(a, b, c, d)
u32 a, b, c, d;


























{
func_0216D6BC(a, 4, c);
func_0216D674((void *)a, 10);
func_0216D7CC(a);
return 0;
}



int func_02198E60(a, b, c, d)
u32 a, b, c, d;


























{
func_0216D6BC(a, 4, c);
func_0216D674((void *)a, 11);
func_0216D7CC(a);
return 0;
}


int func_02198E7C(u32 a, u32 b, u32 c, u32 d)
{
func_0216D6BC(a, 4, c);
func_0216D674((void *)a, 12);
func_0216D7CC(a);
return 0;
}




























/*
 * libmatch places DSPi_WaitForPipe (TwlSDK/libdsp dsp_pipe.o) here, but the
 * call site is func_020061E4, not OS_SleepThread (0x020857B0), and the pool
 * word is the small constant 0x7B7, not DSPiBlockingQueue's absolute address:
 * the overlay stores bss pointers base-relative, so the pool word carries the
 * bss offset.  Reproduced as the literal constant the image holds.
 */
void func_02198E98(void *pipe)
{
    func_020061E4(0x7B7);
    func_02198E44(pipe);
}










































/*
 * libmatch places DSPi_WaitForPipe (TwlSDK/libdsp dsp_pipe.o) here, but the
 * call site is func_020061E4, not OS_SleepThread (0x020857B0), and the pool
 * word is the small constant 0x7B7, not DSPiBlockingQueue's absolute address:
 * the overlay stores bss pointers base-relative, so the pool word carries the
 * bss offset.  Reproduced as the literal constant the image holds.  The
 * second call is to the 0xb variant (func_02198E60) of the sync helper.
 */
void func_02198EB0(void *pipe)
{
    func_020061E4(0x7B7);
    func_02198E60(pipe);
}










































/*
 * Promoted 2026-10-01: the arm9 leaf func_020508EC is now filed EXACT
 * (src/matched/arm9/func_020508EC.c), which witnesses the call.
 *
 * Addresses are Black-image addresses.
 */
int func_02198EC8(u32 a)
{
    u32 r;
    u16 out;

    func_0216D6D4((void *)a);
    r = func_0216D7A8((void *)a, 0);
    if (r != 0xFFFF) {
        if (func_020508EC((u8 *)func_0219C9DC((u8 *)func_0216D520(func_0216D67C((void *)a))), (u16)r, &out) == 1) {
            func_0216D674((void *)a, 0);
            func_0216D7CC(a);
            return 1;
        }
    }
    return 0;
}










































int func_02198F20(u32 a)
{
    u32 r;
    u16 out;

    func_0216D6D4((void *)a);
    r = func_0216D7A8((void *)a, 0);
    if (r != 0xFFFF) {
        if (func_020508EC((u8 *)func_0219C9DC((u8 *)func_0216D520(func_0216D67C((void *)a))), (u16)r, &out) == 1) {
            func_0216D7CC(a);
            return 1;
        }
    }
    return 0;
}










































/*
 * Addresses are Black-image addresses.
 */
int func_02198F68(u32 a)
{
    u32 t;

    func_0216D6BC(a, 4);
    t = func_0219BF48(a);
    if (t != 0) {
        func_021D04A4((void *)t);
    }
    {
        Vec v = { 0, 0, 0 };
        func_0216D8C0(a, &v);
    }
    func_0216D568((void *)a, 160);
    func_0216D570((char *)a, (2 << 14));
    func_0216D7CC(a);
    return 0;
}










































int func_02198FB0(u32 a)
{
    u32 *p;
    u32 r;

    p = func_0216D6D4((void *)a);
    {
        Vec v = { 0, 0, 0 };
        v.y = d_021DDBD4[0][p[0]];
        func_0216D8C0(a, &v);
        r = func_0219BF48(a);
        if (r != 0) {
            if (func_021D04C4(r) == 1) {
                func_021AC154(r);
                func_0219BF3C(a, 0);
            }
        }
        p[0] = p[0] + 2;
        if (p[0] < 16) {
            return 0;
        }
        v.y = 0;
        func_0216D8C0(a, &v);
    }
    func_0216D568((void *)a, 1344);
    func_0219BF54(a);
    func_0216D7CC(a);
    return 1;
}








































int func_02199034(u32 a, u16 b, u32 c, u32 d)
{
((struct Obj17953 *)((u8 *)(func_0216D6BC(a, 4, c))))->f2 = c;
return func_0216D674((void *)a, b);
}







































int func_02199050(u32 a)
{
    u16 *p;

    p = func_0216D6D4((void *)a);
    p[0]++;
    if (p[0] >= p[1]) {
        func_0216D7CC((u32)((u8 *)a));
    }
    return 0;
}






































int func_02199070(u32 a, u32 b, u32 c, u32 d)
{
func_02199034(a, 1, 40, d);
func_0216D7CC(a);
return 0;
}






































int func_02199088(u32 a, u32 b, u32 c, u32 d)
{
func_02199034(a, 2, 40, d);
func_0216D7CC(a);
return 0;
}






































int func_021990A0(u32 a, u32 b, u32 c, u32 d)
{
func_02199034(a, 0, 12, d);
func_0216D7CC(a);
return 0;
}






































int func_021990B8(u32 a, u32 b, u32 c, u32 d)
{
func_0216D6BC(a, 4, c);
func_0216D674((void *)a, 1);
func_0216D7CC(a);
return 1;
}






































int func_021990D4(u32 a)
{
    Vec v = { 0, 0, 0 };
    T40 t;
    int *p;
    int i;

    t = d_021D4C1C;
    p = func_0216D6D4((void *)a);
    i = p[0];
    if (i >= 10) {
        i = 9;
    }
    v.y = t.w[i];
    func_0216D8C0(a, &v);
    p[0] = p[0] + 1;
    if (p[0] >= 20) {
        func_0216D7CC(a);
    }
    return 0;
}






































void func_0219912C(u32 a, Vec *b, u32 c, u32 d, u32 e, u8 f)
{
    u32 *q;

    q = func_0216D6BC(a, 16, c);
    q[0] = e;
    *(Vec *)(q + 1) = *b;
    func_0216D5E0(a, (u16)c);
    func_0216D600(a, (u16)d);
    func_0216D674((void *)a, f);
    func_0216DA70((void *)a);
    func_0216D80C(a, func_0216D83C((void *)a));
    func_0216D818(a, func_0216D854((void *)a));
    func_0216D824(a, func_0216D86C((void *)a));
    if (b->x < 0) {
        func_0216D848((char *)a, -1);
    } else if (b->x > 0) {
        func_0216D848((char *)a, 1);
    }
    if (b->y < 0) {
        func_0216D860((char *)a, -1);
    } else if (b->y > 0) {
        func_0216D860((char *)a, 1);
    }
    if (b->z < 0) {
        func_0216D87C((char *)a, -1);
    } else if (b->z > 0) {
        func_0216D87C((char *)a, 1);
    }
    func_0216D7CC(a);
}






































int func_021991F0(u32 a)
{
    int *p;

    p = func_0216D6D4((void *)a);
    func_02163F8C(a, p + 1);
    p[0] = p[0] - 1;
    if (p[0] > 0) {
        return 0;
    }
    func_0216D568((void *)a, 1088);
    func_02163F10(a);
    func_0216D674((void *)a, 0);
    func_0216D7CC(a);
    return 1;
}





































int func_02199234(u32 a)
{
    Vec t = d_021D4B44;
    func_0219912C(a, &t, 2, 0, 8, 3);
    return 1;
}





































int func_02199268(u32 a)
{
    Vec t = d_021D4204;
    func_0219912C(a, &t, 3, 1, 8, 3);
    return 1;
}





































/*
 * Byte-correct (2026-10-01).  Sole blocker: the ABS32 pool word for the const
 * Vec initialiser is an ov021 data start that another overlay mapped over the
 * same window also starts an object at, so the symbols hint is contested and
 * no single-reference witness exists.  No C change needed to promote.
 *
 * 2026-10-01: the own-overlay data hint is dropped from symbols: so the
 *   own-window rule (code running in ov021 can only see ov021's bytes in its
 *   window) fixes the overlay; with the hint the tool refused it as contested.
 *
 * Addresses are Black-image addresses.
 */
int func_02199298(u32 a)
{
    Vec t = d_021D4C04;
    func_0219912C(a, &t, 1, 2, 8, 3);
    return 1;
}





































int func_021992CC(u32 a)
{
    Vec t = d_021D41E0;
    func_0219912C(a, &t, 0, 3, 8, 3);
    return 1;
}





































int func_021992FC(u32 a)
{
    Vec t = d_021D4210;
    func_0219912C(a, &t, 3, 0, 8, 3);
    return 1;
}





































int func_0219932C(u32 a)
{
    Vec t = d_021D4C10;
    func_0219912C(a, &t, 2, 1, 8, 3);
    return 1;
}





































int func_02199360(u32 a)
{
    Vec t = d_021D4648;
    func_0219912C(a, &t, 0, 2, 8, 3);
    return 1;
}





































int func_02199394(u32 a)
{
    Vec t = d_021D4BF8;
    func_0219912C(a, &t, 1, 2, 8, 3);
    return 1;
}





































int func_021993C8(u32 a)
{
    Vec t = d_021D4BEC;
    func_0219912C(a, &t, 1, 0, 8, 3);
    return 1;
}





































int func_021993FC(u32 a)
{
    Vec t = d_021D4BE0;
    func_0219912C(a, &t, 0, 1, 8, 3);
    return 1;
}





































int func_02199430(u32 a)
{
    Vec t = d_021D4BD4;
    func_0219912C(a, &t, 3, 2, 8, 3);
    return 1;
}





































int func_02199460(u32 a)
{
    Vec t = d_021D4BC8;
    func_0219912C(a, &t, 2, 3, 8, 3);
    return 1;
}




































int func_02199490(u32 a)
{
    Vec t = d_021D4BBC;
    func_0219912C(a, &t, 1, 0, 4, 4);
    return 1;
}




































int func_021994C0(u32 a)
{
    Vec t = d_021D4BB0;
    func_0219912C(a, &t, 0, 1, 4, 4);
    return 1;
}




































int func_021994F0(u32 a)
{
    Vec t = d_021D4BA4;
    func_0219912C(a, &t, 3, 2, 4, 4);
    return 1;
}




































int func_02199520(u32 a)
{
    Vec t = d_021D4B98;
    func_0219912C(a, &t, 2, 3, 4, 4);
    return 1;
}




































int func_02199550(u32 a)
{
    Vec t = d_021D4B8C;
    func_0219912C(a, &t, 1, 0, 2, 5);
    return 1;
}




































int func_02199584(u32 a)
{
    Vec t = d_021D4B80;
    func_0219912C(a, &t, 0, 1, 2, 5);
    return 1;
}




































int func_021995B8(u32 a)
{
    Vec t = d_021D4B74;
    func_0219912C(a, &t, 3, 2, 2, 5);
    return 1;
}




































int func_021995E8(u32 a)
{
    Vec t = d_021D4B68;
    func_0219912C(a, &t, 2, 3, 2, 5);
    return 1;
}




































int func_02199618(u32 a)
{
    Vec t = d_021D4B5C;
    func_0219912C(a, &t, 2, 0, 4, 10);
    return 1;
}




































int func_0219964C(u32 a)
{
    Vec t = d_021D4B50;
    func_0219912C(a, &t, 3, 1, 4, 10);
    return 1;
}




































int func_02199680(u32 a)
{
    Vec t = d_021D45E8;
    func_0219912C(a, &t, 1, 2, 4, 10);
    return 1;
}




































int func_021996B4(u32 a)
{
    Vec t = d_021D4B38;
    func_0219912C(a, &t, 0, 3, 4, 10);
    return 1;
}




































int func_021996E8(u32 a)
{
    Vec t = d_021D4B2C;
    func_0219912C(a, &t, 3, 0, 4, 10);
    return 1;
}




































int func_0219971C(u32 a)
{
    Vec t = d_021D4B20;
    func_0219912C(a, &t, 2, 1, 4, 10);
    return 1;
}




































int func_02199750(u32 a)
{
    Vec t = d_021D4B14;
    func_0219912C(a, &t, 0, 2, 4, 10);
    return 1;
}




































int func_02199784(u32 a)
{
    Vec t = d_021D4B08;
    func_0219912C(a, &t, 1, 2, 4, 10);
    return 1;
}




































int func_021997B8(u32 a)
{
    Vec t = d_021D4AFC;
    func_0219912C(a, &t, 1, 0, 4, 10);
    return 1;
}




































int func_021997EC(u32 a)
{
    Vec t = d_021D4AF0;
    func_0219912C(a, &t, 0, 1, 4, 10);
    return 1;
}




































int func_02199820(u32 a)
{
    Vec t = d_021D4AE4;
    func_0219912C(a, &t, 3, 2, 4, 10);
    return 1;
}




































int func_02199854(u32 a)
{
    Vec t = d_021D4AD8;
    func_0219912C(a, &t, 2, 3, 4, 10);
    return 1;
}




































void func_02199888(u32 a, int b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h, u8 i)
{
    u8 *q;
    int dir;

    dir = 1;
    q = func_0216D6BC(a, 16, c);
    q[0] = e;
    ((struct Obj04222 *)q)->f4 = b;
    q[2] = g;
    q[1] = h;
    q[3] = i;
    ((struct Obj04222 *)q)->fE = 0x1000 / q[0];
    func_0216D5E0(a, (u16)c);
    func_0216D600(a, (u16)d);
    func_0216D674((void *)a, f);
    func_0216DA70((void *)a);
    func_0216D80C(a, func_0216D83C((void *)a));
    func_0216D818(a, func_0216D854((void *)a));
    func_0216D824(a, func_0216D86C((void *)a));
    if (b != 0) {
        switch (g) {
        case 0:
            if (b < 0)
                dir = -1;
            func_0216D848((char *)a, dir);
            break;
        case 1:
            if (b < 0)
                dir = -1;
            func_0216D860((char *)a, dir * 2);
            break;
        case 2:
            if (b < 0)
                dir = -1;
            func_0216D87C((char *)a, dir);
            break;
        }
    }
    func_0216D7CC(a);
}




































int func_02199970(u32 a)
{
    State_02198EB0 *p;
    Vec v;
    int t;
    int s;

    p = func_0216D6D4((void *)a);
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&v);
    switch (p->moveAxis) {
    case 0:
        v.x += p->speed;
        break;
    case 1:
        v.y += p->speed;
        break;
    case 2:
        v.z += p->speed;
        break;
    }
    func_0216D89C(a, &v);
    t = p->speed;
    if (t < 0)
        t = -t;
    p->accum += t;
    p->angle += p->step;
    if (p->angle > 0xF00)
        p->angle = 0xF00;
    {
    Vec w = { 0, 0, 0 };
    s = d_021DDBD4[1][(u16)(p->angle / 256)];
    if (p->negate == 1)
        s = -s;
    switch (p->axis) {
    case 0:
        w.x = s;
        break;
    case 1:
        w.y = s;
        break;
    case 2:
        w.z = s;
        break;
    }
    func_0216D8C0(a, &w);
    }
    p->count--;
    if (p->accum >= 0x10000 && p->count != 0) {
        int b;
        int dir;

        p->accum -= 0x10000;
        dir = 1;
        b = p->speed;
        func_0216D80C(a, func_0216D83C((void *)a));
        func_0216D818(a, func_0216D854((void *)a));
        func_0216D824(a, func_0216D86C((void *)a));
        switch (p->moveAxis) {
        case 0:
            if (b < 0)
                dir = -1;
            func_0216D848((char *)a, dir);
            break;
        case 1:
            if (b < 0)
                dir = -1;
            func_0216D860((char *)a, dir * 2);
            break;
        case 2:
            if (b < 0)
                dir = -1;
            func_0216D87C((char *)a, dir);
            break;
        }
    }
    if (p->count != 0)
        return 0;
    {
        Vec z = { 0, 0, 0 };
        func_0216D8C0(a, &z);
    }
    func_0216D568((void *)a, 0x540);
    func_02163F10(a);
    func_0216D674((void *)a, 0);
    func_0216D7CC(a);
    return 1;
}




































int func_02199AEC(u32 a)
{
    func_02199888(a, 0x2000, 2, 0, 8, 3, 1, 1, 0);
    return 1;
}



































int func_02199B10(u32 a)
{
    func_02199888(a, -0x2000, 3, 1, 8, 3, 1, 1, 0);
    return 1;
}



































int func_02199B38(u32 a)
{
    func_02199888(a, 0x2000, 1, 2, 8, 3, 2, 1, 0);
    return 1;
}



































int func_02199B60(u32 a)
{
    func_02199888(a, -0x2000, 0, 3, 8, 3, 2, 1, 0);
    return 1;
}



































int func_02199B88(u32 a)
{
    func_02199888(a, 0x2000, 3, 0, 8, 3, 1, 1, 0);
    return 1;
}



































int func_02199BAC(u32 a)
{
    func_02199888(a, -0x2000, 2, 1, 8, 3, 1, 1, 0);
    return 1;
}



































int func_02199BD8(u32 a)
{
    func_02199888(a, -0x2000, 0, 2, 8, 3, 2, 1, 0);
    return 1;
}



































int func_02199C00(u32 a)
{
    func_02199888(a, 0x2000, 1, 2, 8, 3, 2, 1, 0);
    return 1;
}



































int func_02199C28(u32 a)
{
    func_02199888(a, 0x2000, 1, 0, 8, 3, 2, 1, 0);
    return 1;
}



































int func_02199C50(u32 a)
{
    func_02199888(a, -0x2000, 0, 1, 8, 3, 2, 1, 0);
    return 1;
}



































int func_02199C7C(u32 a)
{
    func_02199888(a, -0x2000, 3, 2, 8, 3, 0, 1, 0);
    return 1;
}



































int func_02199CA4(u32 a)
{
    func_02199888(a, 0x2000, 2, 3, 8, 3, 0, 1, 0);
    return 1;
}


































int func_02199CC8(u32 a, u32 b, u32 c, u32 d)
{
func_0216D6BC(a, 4, c);
func_0216D674((void *)a, 1);
func_0216D7CC(a);
return 0;
}


































int func_02199CE4(u32 a)
{
    int *p = func_0216D6D4((void *)a);
    if (++*p >= 22) {
        func_0216D7CC(a);
    }
    return 0;
}


































int func_02199D00(u32 a, u32 b, u32 c, u32 d)
{
func_0216D674((void *)a, 10);
func_0216D7CC(a);
return 1;
}
































int func_02199D14(u32 a)
{
    S12 *p = func_0216D6BC(a, 12);
    p->a = 12;
    p->b = 2;
    p->c = 2;
    p->d = 0x8000;
    func_02163E7C((u32)a, (u16)p->c);
    func_0216D674((void *)a, p->a);
    func_0216D7CC(a);
    return 1;
}
































int func_02199D4C(u32 a)
{
    s16 *p;

    p = func_0216D6D4((void *)a);
    func_02163FC0(a, (u16)((u32 *)p)[1], ((u32 *)p)[2]);
    func_02164010(a);
    p[1] = p[1] - 1;
    if (p[1] > 0) {
        return 0;
    }
    func_02163F10(a);
    func_0216D7CC(a);
    return 1;
}
































int func_02199D8C(u32 a)
{
    u8 *p = func_0216D6BC(a, 16);
    ((struct Obj09499 *)p)->f4 = 0x2000;
    ((struct Obj09499 *)p)->f8 = 0;
    p[10] = 0;
    func_0216D674((void *)a, 11);
    func_0216D7CC(a);
    return 1;
}































int func_02199DB4(u32 a)
{
    State_02199DB4 *p;
    u16 v[2];

    p = func_0216D6D4((void *)a);
    if (func_0219FC68(a, &v[1], &v[0]) != 1)
        return 0;
    p->timer = p->timer + 1;
    v[0] = v[0] - 1;
    if (func_0216D598((void *)a) == 0xD3) {
        if (v[1] == 2 && p->last != v[0]) {
            p->last = v[0];
            switch (v[0]) {
            case 7:
            case 12:
            case 17:
                func_020061E4(0x7E5);
                break;
            case 10:
            case 15:
            case 20:
                func_020061E4(0x7E6);
                break;
            }
        }
    } else if (p->timer == 0x5F) {
        func_020061E4(0x7E7);
    }
    if (p->timer < 0x5F)
        return 0;
    p->pos += p->vel;
    {
        Vec w = { 0, 0, 0 };
        w.y = p->pos;
        func_0216D8C0(a, &w);
    }
    if (p->pos / 0x8000 < 16)
        return 0;
    func_0216D674((void *)a, 0);
    func_0216D7CC(a);
    return 1;
}































int func_02199EAC(u32 a, u32 b, u32 c, u32 d)
{
func_0216D674((void *)a, 10);
func_0216D7CC(a);
return 1;
}































int func_02199EC0(u32 a, u32 b, u32 c, u32 d)
{
func_0216D674((void *)a, 11);
func_0216D7CC(a);
return 0;
}































/*
 * Former blocker (now filed in src/matched/arm9): func_020508EC (0x020508EC, arm9, unlabelled leaf, Ilias's).
 * Verified EXACT from a scratch file (region arm9, --arm, dsi/1.1p1 -O4,p):
 *
 *   u32 func_020508EC(u8 *p, int i, u16 *out)
 *   {
 *       u16 v = *(u16 *)(*(u8 **)(p + 0x18) + i * 40 + 0x1c);
 *       *out = v;
 *       return (u16)(v + 4 + 0xC000) <= 3;
 *   }
 *
 * Addresses are Black-image addresses.
 */
int func_02199ED4(u32 a)
{
    u32 s;
    u32 r;
    u16 out;

    s = func_0219C9DC((u8 *)func_0216D520(func_0216D67C((void *)a)));
    r = func_0216D7A8((void *)a, 0);
    if (r != 0xFFFF) {
        if (func_020508EC((u8 *)s, (u16)r, &out) == 0) {
            return 0;
        }
    }
    func_0216D5E0(a, 1);
    func_0216D674((void *)a, 0);
    func_0216D7CC(a);
    return 1;
}































int func_02199F30(u32 a)
{
    Vec t = {0, 0, 0};
    func_0216D8C0(a, &t);
    func_0216D7CC(a);
    return 1;
}































int func_02199F50(u32 a)
{
    u16 *p;
    Vec t = d_021D4ACC;
    p = func_0216D6BC(a, 6);
    *p = 0;
    ((struct Obj12643 *)p)->f2 = 0;
    func_0216D8C0(a, &t);
    func_0216D674((void *)a, 10);
    func_0216D7CC(a);
    return 1;
}






























int func_02199F94(u32 a)
{
    u16 *p;
    u16 v[2];
    p = func_0216D6D4((void *)a);
    if (func_0219FCC0(a, &v[1], &v[0]) != 1)
        return 0;
    p[0] = p[0] + 1;
    v[0] = v[0] - 1;
    if (func_0216D598((void *)a) == 0xDD && v[1] == 0 && *((u8 *)p + 2) != v[0]) {
        *((u8 *)p + 2) = v[0];
        switch (v[0]) {
        case 0:
            func_020061E4(0x7E5);
            break;
        case 3:
            func_020061E4(0x7E6);
            break;
        }
    }
    if (p[0] < 0x5F)
        return 0;
    func_0216D7CC(a);
    return 1;
}






























int func_0219A014(u32 a, u32 b, u32 c, u32 d)
{
func_0216D674((void *)a, 10);
func_0216D7CC(a);
return 0;
}






























int func_0219A028(u32 a, u32 b, u32 c, u32 d)
{
func_0216D674((void *)a, 11);
func_0216D7CC(a);
return 0;
}






























int func_0219A03C(u32 a, u32 b, u32 c, u32 d)
{
func_0216D674((void *)a, 12);
func_0219FE64(a);
func_0216D7CC(a);
return 0;
}






























int func_0219A058(u32 a, u32 b, u32 c, u32 d)
{
if (func_0219FE20(a, b, c, d) == 1) {
    func_0216D674((void *)a, 0);
    func_0216D7CC(a);
    return 1;
}
return 0;
}




























int func_0219A07C(u32 a, u32 b, u32 c, u32 d)
{
if (func_0219FE20(a, b, c, d) == 1) {
    func_0216D7CC(a);
    return 1;
}
return 0;
}



























int func_0219A098(u32 a, u32 b)
{
    u16 *p;
    int k = 8;
    p = func_0216D684(a, 8);
    p[1] = func_0219B0F0((u32)d_021D4FA4, k - 9);
    ((struct Obj12644 *)p)->f4 = b;
    func_0216D674((void *)a, 0);
    return func_0216DA50(a);
}
























int func_0219A0CC(u32 a) { return func_0219A098(a, 0); }























int func_0219A0D8(u32 a) { return func_0219A098(a, 1); }






















int func_0219A0E4(u32 a) { return func_0219A098(a, 2); }





















int func_0219A0F0(u32 a) { return func_0219A098(a, 3); }




















int func_0219A0FC(u32 a) { return func_0219A098(a, 4); }



















int func_0219A108(u32 a) { return func_0219A098(a, 5); }


















int func_0219A114(u32 a) { return func_0219A098(a, 6); }

















int func_0219A120(u32 a) { return func_0219A098(a, 7); }
















int func_0219A12C(u32 a) { return func_0219A098(a, 8); }















int func_0219A138(u32 a) { return func_0219A098(a, 9); }














int func_0219A144(u32 a) { return func_0219A098(a, 10); }

















void func_0219A150(u32 a)
{
    St_0219A150 *p;
    u32 r;
    u16 t;
    u16 q;
    p = func_0216D69C((void *)a);
    if (func_0216D5A8((u8 *)a) == 11) {
        if (func_02164168(a) == 1 && func_0219B0C4() == 1) {
            t = func_0216D5F8((void *)a);
            q = func_0219A1E8(func_0216D5A0((void *)a), t);
            if (q != 9)
                func_0216D5E0((u32)a, (u16)q);
        }
    } else {
        r = func_0219B200(a, p->v, 9);
        if (r != 9) {
            func_0216D5E0((u32)a, (u16)r);
        } else if (p->x == 0) {
            p->n = p->n - 1;
            if (p->n <= 0) {
                p->n = func_0219B0F0((u32)d_021D4FA4, -1);
                r = func_0219B104(p->v, 9);
                func_0216D5E0((u32)a, (u16)r);
            }
        }
    }
    func_02163F10(a);
}


















static inline u16 NextInRow(u16 *row, u16 v)
{
    int i;
    u16 *p;

    for (i = 1, p = row; p[i] != 9; i++) {
        if (v == p[i]) {
            i++;
            if (p[i] == 9) i = 1;
            return p[i];
        }
    }
    return 9;
}


















/*
 * Row lookup: find the 6-halfword record whose key matches, then return the
 * entry after v in its 9-terminated list (wrapping to entry 1).  The row is
 * an inline argument formed through a (u8 *) byte offset, so the add stays
 * after the key compare; the helper's `for (i = 1, p = row; ...)` local copy
 * of the row gives the image's colours (row r0, index r3, v copied to r4).
 */
u16 func_0219A1E8(u16 key, u16 v)
{
    int i = 0;

    do {
        if (key == d_021D5074[i][0]) {
            return NextInRow((u16 *)((u8 *)d_021D5074 + i * 12), v);
        }
        i++;
    } while (d_021D5074[i][0] != 0xFF);
    return 9;
}

















/*
 * Empty callback: its address 0x0219A24D is stored in ov021 data at 0x021D5738.
 */
void func_0219A24C(void)
{
}


















/*
 * Calls func_0219A290(its own argument 1, 0xc, 0xb, 0x0) and returns nothing.
 */
void func_0219A250(u32 a1)
{
    func_0219A290(a1, 0xc, 0xb, 0x0);
}

















/*
 * Calls func_0219A290(its own argument 1, 0xc, 0xc, 0x0) and returns nothing.
 */
void func_0219A260(u32 a1)
{
    func_0219A290(a1, 0xc, 0xc, 0x0);
}

















/*
 * Calls func_0219A290(its own argument 1, 0xc, 0xd, 0x0) and returns nothing.
 */
void func_0219A270(u32 a1)
{
    func_0219A290(a1, 0xc, 0xd, 0x0);
}

















/*
 * Calls func_0219A290(its own argument 1, 0xc, 0xd, 0x2) and returns nothing.
 */
void func_0219A280(u32 a1)
{
    func_0219A290(a1, 0xc, 0xd, 0x2);
}

















void func_0219A290(u32 a, u32 b, u32 c, u32 d)
{
    u32 *p = func_0216D684(a, 16, c, d);
    p[1] = d;
    p[2] = b;
    p[3] = c;
    func_0216D674((void *)a, 0);
    func_0216DA50((u32)((u8 *)a));
}

















void func_0219A2B8(u32 a)
{
    St_0219A260 *p;
    u32 r;
    int f;

    p = func_0216D69C((void *)a);
    switch (p->state) {
    case 0:
        func_0216DA50((u32)((u8 *)a));
        func_0216DA7C((u8 *)a);
        func_0216D438((char *)a, (u16)((u32)func_02197E7C((u16)((u32)func_0216D5F8((void *)a)), (u16)0)));
        p->state++;
        break;
    case 1:
        if (func_02197EDC((u8 *)a) == 0)
            break;
        p->timer = func_0219B0F0((u32)d_021D4FA4, -1);
        p->state++;
    case 2:
        p->timer--;
        if (p->timer != 0)
            break;
        p->state++;
    case 3:
        r = func_0219B104(p->v, 9);
        func_0216D60C(a, r);
        if (p->mode == 1 && func_0219A4CC(a, r) == 0) {
            p->state = 0;
            return;
        }
        f = func_021639C0(a, r);
        if (f != 0) {
            if (p->mode == 2) {
                if (f & 1) {
                    p->state = 0;
                    return;
                }
            } else {
                p->state = 0;
                return;
            }
        }
        func_0216D438((char *)a, (u16)((u32)func_02197E7C((u16)r, (u16)p->arg)));
        func_0216DA44(a);
        p->state++;
    case 4:
        if (func_02197EDC((u8 *)a) != 0) {
            func_0216DA50((u32)((u8 *)a));
            p->state = 0;
        }
        break;
    }
}

















/*
 * Addresses are Black-image addresses.
 * Store order in each arm is left, right, top, bottom (x pair, then y pair);
 * the field order left, top, right, bottom puts stores to +0/+8 first.
 */
void func_0219A3D8(u32 a, Rect *r)
{
    int x;
    int y;
    int w;
    int h;

    x = func_0216D7E8((void *)a);
    y = func_0216D7F8((void *)a);
    w = func_0216D660((void *)a);
    h = func_0216D66C((void *)a);
    switch (func_0216D5A0((void *)a)) {
    case 6:
        r->left = x - w;
        r->right = x;
        r->top = y - h;
        r->bottom = y;
        break;
    case 7:
        r->left = x;
        r->right = x + w;
        r->top = y - h;
        r->bottom = y;
        break;
    case 8:
        r->left = x - w;
        r->right = x;
        r->top = y;
        r->bottom = y + h;
        break;
    case 9:
        r->left = x;
        r->right = x + w;
        r->top = y;
        r->bottom = y + h;
        break;
    case 10:
        r->left = x - w;
        r->right = x;
        r->top = y - h;
        r->bottom = y + h;
        break;
    case 11:
        r->left = x;
        r->right = x + w;
        r->top = y - h;
        r->bottom = y + h;
        break;
    case 12:
        r->left = x - w;
        r->right = x + w;
        r->top = y - h;
        r->bottom = y;
        break;
    case 13:
        r->left = x - w;
        r->right = x + w;
        r->top = y;
        r->bottom = y + h;
        break;
    }
}
















int func_0219A4CC(u32 a, u32 b)
{
    int r[4];
    int x;
    int y;
    func_0219A3D8(a, (Rect *)r);
    x = func_0216D83C((void *)a) + func_021641E8((u16)b);
    y = func_0216D86C((void *)a) + func_021641F8(b);
    if (r[0] > x || r[2] < x)
        return 0;
    if (r[1] > y || r[3] < y)
        return 0;
    return 1;
}
















/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216DA50 ((u32)((u8 *)0x0216DA50)) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219A528(a, b, c, d)
u32 a, b, c, d;













{
((struct Obj17954 *)((u8 *)(func_0216D684(a, 8, c, d))))->f0 = b;
func_0216D674((void *)a, 0);
func_0216DA50((u32)((u8 *)a));
return func_02163F10(a);
}



void func_0219A54C(u32 a)
{
    St_02198D3C *p = func_0216D69C((void *)a);
    switch (p->n) {
    case 0:
        func_0216D5E0(a, (unsigned short)p->v);
        p->n = p->n + 1;
        break;
    case 1:
        break;
    }
}

int func_0219A574(u32 a) { return func_0219A528(a, 0); }

int func_0219A580(u32 a) { return func_0219A528(a, 1); }

int func_0219A58C(u32 a) { return func_0219A528(a, 2); }

int func_0219A598(u32 a) { return func_0219A528(a, 3); }


void func_0219A5A4(u32 a, u8 b)
{
    u8 *p = func_0216D684(a, 8);
    *p = b;
    func_0216D674((void *)a, 0);
    func_0216DA50((u32)((u8 *)a));
    func_02163F10(a);
}

void func_0219A5C8(u32 a) { func_0219A5A4(a, 2); }

void func_0219A5D4(u32 a) { func_0219A5A4(a, 3); }






void func_0219A5E0(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    while (d_021D4DE8[(s8)p[2]](a, p) == 1) {
    }
}






int func_0219A604(u32 a, u8 *s)
{
    u32 v = func_0219B200(a, 0x26, 9);
    if (v == 9) {
        v = func_0216D5F8((void *)a);
    }
    func_0216D438((char *)a, (u16)((u32)func_02197E7C((u16)v, (u16)0)));
    s[2] = 1;
    return 1;
}





/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D5A8 (0x0216D5A8) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219A638(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC((u8 *)a) == 0) {
    return 0;
}
if (func_0216D5A8((u8 *)a) != 11) {
    ((struct Obj12074 *)((u8 *)(b)))->f4 = 0;
}
((struct Obj12074 *)((u8 *)(b)))->f2 = 2;
return 1;
}




int func_0219A660(u32 a, St_0219A5E0 *p)
{
    if (func_0216D5A8((u8 *)((u32)((u8 *)a))) == 11) {
        if (p->n != 0) {
            p->n = 0;
            return 0;
        }
        if (func_02164168(a) == 0)
            return 0;
        if (func_0219B0C4() == 0)
            return 0;
        p->n = p->n + 1;
    } else {
        if (p->n != 0) {
            if (func_0219B200(a, 0x26, 9) != 9) {
                p->b = 0;
                return 1;
            }
        }
        p->n = p->n + 1;
        if (p->n < 0x18)
            return 0;
    }
    p->b = 3;
    return 1;
}



int func_0219A6CC(u32 a, s8 *b)
{
    Arr ta = d_021D5024;
    Arr tb = d_021D5038;
    int *t;
    int i;
    int cur;
    t = ta.v;
    if (b[0] != 2)
        t = tb.v;
    cur = func_0216D5F8((void *)a);
    i = 0;
    if (t[0] != 9) {
        do {
            if (cur == t[i])
                break;
            i++;
        } while (t[i] != 9);
    }
    i++;
    if (t[i] == 9)
        i = 0;
    func_0216D5E0((u32)a, (u16)t[i]);
    b[2] = 0;
    return 1;
}

void func_0219A750(u32 a) { func_0219A5A4(a, 3); }




void func_0219A75C(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    while (d_021D4DB8[(s8)p[2]](a, p) == 1) {
    }
}




/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219A780(char *a, u32 b, u32 c, u32 d)
{
func_0216D438(a, (((u32)func_02197E7C((u32)(((u32)func_0216D5F8((void *)a) << 16) >> 16), (u32)0) << 16) >> 16));
((struct Obj17955 *)((u8 *)(b)))->f2 = 1;
return 1;
}



int func_0219A7A8(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC((u8 *)a) == 0) {
    return 0;
}
((struct Obj12075 *)((u8 *)(b)))->f4 = 0;
((struct Obj12075 *)((u8 *)(b)))->f2 = 2;
return 1;
}

int func_0219A7C4(int a, u8 *p) { int v = *(int *)(p + 4) + 1; *(int *)(p + 4) = v; if (v < 0x18) return 0; p[2] = 3; return 1; }














int func_0219A7DC(u32 a, s8 *b)
{
    Arr ta = d_021D504C;
    Arr tb = d_021D5060;
    int *t;
    int i;
    int cur;
    t = ta.v;
    if (b[0] != 2)
        t = tb.v;
    cur = func_0216D5F8((void *)a);
    i = 0;
    if (t[0] != 9) {
        do {
            if (cur == t[i])
                break;
            i++;
        } while (t[i] != 9);
    }
    i++;
    if (t[i] == 9)
        i = 0;
    func_0216D5E0((u32)a, (u16)t[i]);
    if (func_0216D5F8((void *)a) == func_0216D5D4((void *)a))
        b[0] = func_021642A4(b[0]);
    b[2] = 0;
    return 1;
}














void func_0219A87C(u32 a)
{
    u8 *p = func_0216D684(a, 8);
    if (func_0219B358(a) == 1) {
        func_0219B374(a, p + 4);
    }
}














void func_0219A89C(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    while (d_021D4D60[p[0]](a, p) == 1) {
    }
}














int func_0219A8C0(u32 a, u8 *b)
{
    u32 cur = func_0216D5D4((void *)a);
    if (b[1] == 1)
        cur = func_021642A4((u16)cur);
    func_0216D600(a, cur);
    if (func_0219B358(a) == 0)
        func_0216D5E0((u32)a, (u16)cur);
    b[0] = 1;
    return 1;
}














int func_0219A900(u32 a, u8 *b)
{
    int x;
    int y;
    int tx;
    int ty;
    u32 u;
    u32 d;
    int r;
    u32 k;

    if (func_0219B2E8(a, b + 2) == 0)
        return 0;
    if (b[1] != 0) {
        x = func_0216D7E8((void *)a);
        y = func_0216D7F8((void *)a);
        tx = func_0216D83C((void *)a);
        ty = func_0216D86C((void *)a);
        if (x == tx && y == ty) {
            u = (u32)func_021642A4((u16)func_0216D608((void *)a));
            func_0216D600(a, u);
            if (func_0219B358(a) == 0)
                func_0216D5E0((u32)a, (u16)u);
            b[1] = 0;
        }
    }
    d = func_0216D608((void *)a);
    r = func_021639C0(a, d);
    if (r & 1) {
        b[1] = 1;
        d = (u32)func_021642A4((u16)d);
        r = func_021639C0(a, d);
    }
    k = 12;
    if (func_0219B334(a) != 0 && func_0219B060() == 1 && func_02164168(a) == 1)
        k = 16;
    if (r != 0)
        k = 32;
    func_0216D438((char *)a, (u16)((u32)func_02197E7C((u16)d, (u16)k)));
    if (func_0219B358(a) == 1)
        func_0219B390((u32)a, (s8 *)(b + 4));
    func_0216DA44(a);
    b[0] = 2;
    return 1;
}













int func_0219AA08(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC((u8 *)a) == 1) {
    func_0216DA50(a);
    if (func_0219B358(a) == 1) {
        func_0219B404(a, (u8 *)(b + 4));
    }
    ((struct Obj17956 *)((u8 *)(b)))->f0 = 0;
}
return 0;
}













void func_0219AA38(u32 a, u32 b, u32 c, u32 d)
{
    u8 *p = func_0216D684(a, 12, c, d);
    p[2] = b;
    p[3] = c;
    p[4] = d;
    if (func_0219B358(a) == 1) {
        func_0219B374(a, p + 8);
    }
}













/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x0, 0xe) and returns nothing.
 */
void func_0219AA68(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x0, 0xe);
}













/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x0, 0xf) and returns nothing.
 */
void func_0219AA78(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x0, 0xf);
}













/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x1, 0x10) and returns nothing.
 */
void func_0219AA88(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x1, 0x10);
}













/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x1, 0x11) and returns nothing.
 */
void func_0219AA98(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x1, 0x11);
}













/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x0, 0x12) and returns nothing.
 */
void func_0219AAA8(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x0, 0x12);
}













/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x0, 0x13) and returns nothing.
 */
void func_0219AAB8(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x0, 0x13);
}













/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x1, 0x14) and returns nothing.
 */
void func_0219AAC8(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x1, 0x14);
}













/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x1, 0x15) and returns nothing.
 */
void func_0219AAD8(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x1, 0x15);
}













/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x1, 0x16) and returns nothing.
 */
void func_0219AAE8(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x1, 0x16);
}













/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x1, 0x17) and returns nothing.
 */
void func_0219AAF8(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x1, 0x17);
}












/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x0, 0x18) and returns nothing.
 */
void func_0219AB08(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x0, 0x18);
}












/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x0, 0x19) and returns nothing.
 */
void func_0219AB18(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x0, 0x19);
}












/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x1, 0x1a) and returns nothing.
 */
void func_0219AB28(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x1, 0x1a);
}












/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x1, 0x1b) and returns nothing.
 */
void func_0219AB38(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x1, 0x1b);
}












/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x0, 0x1c) and returns nothing.
 */
void func_0219AB48(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x0, 0x1c);
}












/*
 * Calls func_0219AA38(its own argument 1, 0x2, 0x0, 0x1d) and returns nothing.
 */
void func_0219AB58(u32 a1)
{
    func_0219AA38(a1, 0x2, 0x0, 0x1d);
}












void func_0219AB68(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    while (d_021D4D04[p[0]](a, p) == 1) {
    }
}












int func_0219AB8C(char *a, u8 *b)
{
    u32 *tbl;
    u32 v;
    int x0;
    int y0;
    int x1;
    int y1;
    int f;
    int m;

    if (func_0219B2E8((int)a, b + 5) == 0) {
        return 0;
    }
    if (b[1] == b[2]) {
        if (b[3] == 0) {
            x0 = func_0216D7E8((void *)a);
            if (x0 == func_0216D83C((void *)a)) {
                b[1]++;
            }
        } else {
            x0 = func_0216D7F8((void *)a);
            if (x0 == func_0216D86C((void *)a)) {
                b[1]++;
            }
        }
    }
    if (b[1] == 3) {
        x0 = func_0216D7E8((void *)a);
        y0 = func_0216D7F8((void *)a);
        x1 = func_0216D83C((void *)a);
        y1 = func_0216D86C((void *)a);
        if (x0 == x1 && y0 == y1) {
            b[1] = 0;
        }
    }
    tbl = func_0219B120(b[4]);
    v = tbl[b[1]];
    func_0216D600((int)a, (u16)v);
    if (func_0219B358((u32)a) == 0) {
        func_0216D5E0((int)a, (u16)v);
    }
    f = func_021639C0((int)a, (u16)v);
    if (f & 1) {
        b[1]++;
        v = tbl[b[1]];
        func_0216D600((int)a, (u16)v);
        if (func_0219B358((u32)a) == 0) {
            func_0216D5E0((int)a, (u16)v);
        }
        f = func_021639C0((int)a, (u16)v);
    }
    m = 12;
    if (func_0219B334((u32)a) != 0 && func_0219B060() == 1 && func_02164168((int)a) == 1) {
        m = 16;
    }
    if (f != 0) {
        m = 32;
    }
    func_0216D438(a, (u16)func_02197E7C((u16)v, (u16)m));
    if (func_0219B358((u32)a) == 1) {
        func_0219B390((int)a, (s8 *)(b + 8));
    }
    func_0216DA44((int)a);
    b[0] = 1;
    return 1;
}












int func_0219ACE8(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC((u8 *)a) == 1) {
    func_0216DA50(a);
    if (func_0219B358(a) == 1) {
        func_0219B404(a, (u8 *)(b + 8));
    }
    ((struct Obj17957 *)((u8 *)(b)))->f0 = 0;
}
return 0;
}












void func_0219AD18(u32 a, u32 b, u32 c, u32 d)
{
    u8 *p = func_0216D684(a, 12, c, d);
    p[2] = b;
    p[3] = c;
    p[4] = d;
    if (func_0219B358(a) == 1) {
        func_0219B374(a, p + 8);
    }
}












/*
 * Calls func_0219AD18(its own argument 1, 0x2, 0x1, 0x1e) and returns nothing.
 */
void func_0219AD48(u32 a1)
{
    func_0219AD18(a1, 0x2, 0x1, 0x1e);
}











/*
 * Calls func_0219AD18(its own argument 1, 0x2, 0x1, 0x1f) and returns nothing.
 */
void func_0219AD58(u32 a1)
{
    func_0219AD18(a1, 0x2, 0x1, 0x1f);
}











/*
 * Calls func_0219AD18(its own argument 1, 0x2, 0x0, 0x20) and returns nothing.
 */
void func_0219AD68(u32 a1)
{
    func_0219AD18(a1, 0x2, 0x0, 0x20);
}











/*
 * Calls func_0219AD18(its own argument 1, 0x2, 0x0, 0x21) and returns nothing.
 */
void func_0219AD78(u32 a1)
{
    func_0219AD18(a1, 0x2, 0x0, 0x21);
}











/*
 * Calls func_0219AD18(its own argument 1, 0x2, 0x1, 0x22) and returns nothing.
 */
void func_0219AD88(u32 a1)
{
    func_0219AD18(a1, 0x2, 0x1, 0x22);
}











/*
 * Calls func_0219AD18(its own argument 1, 0x2, 0x1, 0x23) and returns nothing.
 */
void func_0219AD98(u32 a1)
{
    func_0219AD18(a1, 0x2, 0x1, 0x23);
}











/*
 * Calls func_0219AD18(its own argument 1, 0x2, 0x0, 0x24) and returns nothing.
 */
void func_0219ADA8(u32 a1)
{
    func_0219AD18(a1, 0x2, 0x0, 0x24);
}










/*
 * Calls func_0219AD18(its own argument 1, 0x2, 0x0, 0x25) and returns nothing.
 */
void func_0219ADB8(u32 a1)
{
    func_0219AD18(a1, 0x2, 0x0, 0x25);
}










void func_0219ADC8(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    while (d_021D4D78[p[0]](a, p) == 1) {
    }
}










void func_0219ADEC(St_0219A7DC *p)
{
    if (p->f == 1) {
        p->b--;
        if (p->b < 0) {
            p->b = 3;
        }
    } else {
        p->b++;
    }
}









int func_0219AE10(char *a, u8 *b)
{
    u32 c;
    if (func_0216D5A8((u8 *)a) == 10) {
        c = func_0216D5F8((void *)a);
        if (func_021AE198((int)a, c, func_0216D63C((char *)a, 0), 0) != -1) {
            func_0216D438(a, func_02197E7C(c, 0x30));
            func_0216DA44((u32)a);
            b[0] = 1;
            return 1;
        }
    }
    b[0] = 2;
    return 1;
}









int func_0219AE68(int a, s8 *b)
{
    u16 *p;
    u32 id;
    u32 r4;
    u32 v;
    int t;

    if (func_02197EDC((u8 *)a) == 1) {
        r4 = 0xff;
        v = func_0216D5A0((void *)a);
        p = d_021D4F90;
        id = 0x25;
        do {
            if (id == v) {
                r4 = p[1];
            } else if (p[1] == v) {
                r4 = id;
            }
            if (r4 != 0xff) {
                t = 4 - (b[1] + 1);
                func_0216E0E8(a, r4);
                b[1] = t;
                break;
            }
            p += 2;
            id = p[0];
        } while (id != 0xff);
        func_0216DA50((u32)((u8 *)a));
        b[0] = 2;
    }
    return 0;
}









/*
 * Twin of func_0219AB8C (same shape; the step field is signed and advanced
 * through func_0219ADEC).
 */
int func_0219AEC8(char *a, St_0219AE10 *b)
{
    u32 *tbl;
    u32 v;
    int x0;
    int y0;
    int x1;
    int y1;
    int f;
    int m;

    if (func_0219B2E8((int)a, &b->f6) == 0) {
        return 0;
    }
    if (b->step == b->last) {
        if (b->axis == 0) {
            x0 = func_0216D7E8((void *)a);
            if (x0 == func_0216D83C((void *)a)) {
                func_0219ADEC((St_0219A7DC *)b);
            }
        } else {
            x0 = func_0216D7F8((void *)a);
            if (x0 == func_0216D86C((void *)a)) {
                func_0219ADEC((St_0219A7DC *)b);
            }
        }
    }
    if (b->step == 3) {
        x0 = func_0216D7E8((void *)a);
        y0 = func_0216D7F8((void *)a);
        x1 = func_0216D83C((void *)a);
        y1 = func_0216D86C((void *)a);
        if (x0 == x1 && y0 == y1) {
            b->step = 0;
        }
    }
    tbl = func_0219B120(b->id);
    v = tbl[b->step];
    func_0216D600((int)a, (u16)v);
    if (func_0219B358((u32)a) == 0) {
        func_0216D5E0((int)a, (u16)v);
    }
    f = func_021639C0((int)a, (u16)v);
    if (1 & f) {
        func_0219ADEC((St_0219A7DC *)b);
        v = tbl[b->step];
        func_0216D600((int)a, (u16)v);
        if (func_0219B358((u32)a) == 0) {
            func_0216D5E0((int)a, (u16)v);
        }
        f = func_021639C0((int)a, (u16)v);
    }
    m = 12;
    if (func_0219B334((u32)a) != 0 && func_0219B060() == 1 && func_02164168((int)a) == 1) {
        m = 16;
    }
    if (f != 0) {
        m = 32;
    }
    func_0216D438(a, (u16)func_02197E7C((u16)v, (u16)m));
    if (func_0219B358((u32)a) == 1) {
        func_0219B390((int)a, &b->f8);
    }
    func_0216DA44((int)a);
    b->f0 = 3;
    return 1;
}








int func_0219B030(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC((u8 *)a) == 1) {
    func_0216DA50(a);
    if (func_0219B358(a) == 1) {
        func_0219B404(a, (u8 *)(b + 8));
    }
    ((struct Obj17958 *)((u8 *)(b)))->f0 = 0;
}
return 0;
}








int func_0219B060(void)
{
    if (func_0203630C() & 2) {
        return 1;
    }
    return 0;
}








int func_0219B074(int a)
{
    int t;

    t = (int)func_0216DEE0(func_0216D67C((void *)a));
    if (t != 0) {
        switch (func_0216D7C4((u8 *)t)) {
        case 0x58:
        case 0x59:
        case 0x5a:
        case 0x5b:
        case 0xa3:
        case 0xa4:
        case 0xa5:
        case 0xa6:
            return 1;
        }
    }
    return 0;
}








int func_0219B0C4(void)
{
    if (func_020362DC() & 2) {
        return 1;
    }
    return 0;
}







int func_0219B0D8(u32 *t, u32 v)
{
    int i;
    for (i = 0; v != t[i]; i++) {
    }
    return i;
}








int func_0219B0F0(u32 a, u32 b)
{
return *(u32 *)((u8 *)(a) + ((func_020056EC(func_0219B0D8((u32 *)a, b)) << 2)));
}








u32 func_0219B104(u32 a, u32 b)
{
    u32 *t = func_0219B120(a);
    return t[func_020056EC(func_0219B0D8(t, b))];
}








/*
 * The first key is the literal 0 held in a local (row 0 of the table has
 * key 0), then the walk reloads it at the loop bottom.
 */
u32 *func_0219B120(u32 id)
{
    Ent *p = d_021D50F8;
    u32 k = 0;
    do {
        if (k == id) {
            return p->tbl;
        }
        p++;
        k = p->id;
    } while (k != 0x27);
    return 0;
}








int func_0219B13C(u32 a)
{
    int k;
    u32 v;
    u32 e;
    int i;
    u32 o;
    int ox, oy, ax, ay, r;
    int x0, x1, y0, y1;

    k = func_0216D5A8((u8 *)a);
    if (k != 1 && k != 2) {
        return 9;
    }
    if (func_0219B074(a) == 0) {
        return 9;
    }
    i = 0;
    v = func_0216D5A0((void *)a);
    do {
        e = d_021D4FEC[i++];
    } while (e != v && e != 0xFF);
    if (v != e) {
        return 9;
    }
    o = (u32)func_0216DEE0(func_0216D67C((void *)a));
    if (o == 0) {
        return 9;
    }
    if (func_0216D854((void *)o) != func_0216D854((void *)a)) {
        return 9;
    }
    ox = func_0216D83C((void *)o);
    oy = func_0216D86C((void *)o);
    r = func_0216D63C((char *)a, 0);
    ax = func_0216D83C((void *)a);
    ay = func_0216D86C((void *)a);
    x0 = ax - r;
    x1 = ax + r;
    y0 = ay - r;
    y1 = ay + r;
    if (y0 <= oy && y1 >= oy && x0 <= ox && x1 >= ox) {
        return func_021642B4(ax, ay, ox, oy);
    }
    return 9;
}








int func_0219B200(int a, int id, int end)
{
    int *tbl;
    int n;
    int t;
    int i;
    int o;
    int ax;
    int ay;
    int ox;
    int oy;
    int dx;
    int dy;

    tbl = (int *)func_0219B120(id);
    n = func_0219B0D8((unsigned int *)tbl, end);
    if (n == 1) {
        return 9;
    }
    t = func_0219B13C(a);
    if (t != 9) {
        i = 0;
        do {
            if (t == tbl[i]) {
                return t;
            }
            i++;
        } while (i < n);
        o = (int)func_0216DEE0(func_0216D67C((void *)a));
        dx = 9;
        dy = 9;
        ax = func_0216D83C((void *)a);
        ay = func_0216D86C((void *)a);
        ox = func_0216D83C((void *)o);
        oy = func_0216D86C((void *)o);
        if (ax > ox) {
            dx = 2;
        } else if (ax < ox) {
            dx = 3;
        }
        if (ay > oy) {
            dy = 0;
        } else if (ay < oy) {
            dy = 1;
        }
        i = 0;
        if (dx == 9) {
            do {
                if (dy == tbl[i]) {
                    return dy;
                }
                i++;
            } while (i < n);
        } else if (dy == 9) {
            do {
                if (dx == tbl[i]) {
                    return dx;
                }
                i++;
            } while (i < n);
        } else {
            do {
                if (dx == tbl[i]) {
                    return dx;
                }
                if (dy == tbl[i]) {
                    return dy;
                }
                i++;
            } while (i < n);
        }
        return 9;
    }
    return t;
}








int func_0219B2E8(int a, u8 *b)
{
    if (func_0216D5A8((u8 *)a) != 12) {
        return 1;
    }
    if (b[0] == 0) {
        if (func_02164168(a) == 0) {
            return 0;
        }
        if (func_0219B0C4() == 0) {
            return 0;
        }
        b[0] = func_0216D63C((char *)a, 1);
    }
    if (b[0] != 0) {
        b[0]--;
    }
    return 1;
}







int func_0219B334(u32 a)
{
    u32 v = func_0216D5A8((u8 *)a);
    if (v == 13 || (u16)(v + 0xFFF1) <= 4) {
        return 1;
    }
    return 0;
}







int func_0219B358(u32 a)
{
    u32 v = func_0216D5A8((u8 *)a);
    if (v == 7 || v == 8 || v - 17 <= 1) {
        return 1;
    }
    return 0;
}







void func_0219B374(u32 a, u8 *s)
{
    u32 v = func_0216D5A8((u8 *)a);
    if (v == 7 || v == 17) {
        s[1] = 0;
    } else {
        s[1] = 1;
    }
}







void func_0219B390(int a, s8 *b)
{
    int i;
    u32 v;
    u32 n;

    v = func_0216D5F8((void *)a);
    for (i = 0; i < 4 && v != d_021D4FCC[b[1]][i]; i++) {
    }
    i++;
    b[0] = v;
    i %= 4;
    n = d_021D4FCC[b[1]][i];
    if (func_0216D55C(a, 8) != 0) {
        b[2] = 1;
    } else {
        b[2] = 0;
    }
    func_0216D5E0(a, (u16)n);
    func_0216D548((u32 *)a, 8);
}







void func_0219B404(u32 a, u8 *s)
{
    if (s[2] == 0) {
        func_0216D550((u32 *)a, 8);
    }
}







/*
 * Recursive MATCH unblocker: callee of func_02163010 (ov010) +000A.  An
 * unlabelled Thumb tail-call thunk that disasm.py emitted as a word run
 * (`ldr r3,[pc,#0]; bx r3; .word func_0219B440|1`), so no func_ label exists
 * for the caller to reach through `label`/`sole-ref/code`.  Matching it here
 * gives func_02163010's call site a `matched` witness.  Region hint ov021 is
 * required: ov009 overlaps 0x0219B414 but holds unrelated code there.
 */
int func_0219B414(int a)
{
    return func_0219B440((char *)a);
}





int func_0219B41C(u32 a, u32 b, u32 c, u32 d)
{
if (func_0219B45C(a, b, c, d) == 0) {
    return 0;
}
if (func_0219B478(a) != 0) {
    return 1;
}
return 0;
}




extern int (*const data_021D5278[])(char *);





/*
 * Recursive MATCH dependency: target of the Thumb tail-call thunk
 * func_0219B414 (ov021).  Indexes the function-pointer table at 0x021D5278 by
 * the word read at p+0x10 and tail-dispatches through it.
 */
int func_0219B440(char *a)
{
    int i = func_0216D5A8((u8 *)a);

    return data_021D5278[i](a);
}





u32 func_0219B45C(u32 a, u32 b, u32 c, u32 d)
{
    return d_021D52CC[func_0216D5A8((u8 *)a)](a);
}




u32 func_0219B478(u32 a)
{
    return d_021D5320[func_0216D5A8((u8 *)a)](a);
}




int func_0219B494(int a)
{
if (func_0216D83C((void *)a) != func_0216D804((void *)a)) {
    return 1;
}
if (func_0216D86C((void *)a) != func_0216D81C((void *)a)) {
    return 1;
}
return 0;
}




int func_0219B4C8(int a)
{
if (func_0216D83C((void *)a) != func_0216D804((void *)a)) {
    return 0;
}
if (func_0216D86C((void *)a) == func_0216D81C((void *)a)) {
    return 1;
}
return 0;
}
