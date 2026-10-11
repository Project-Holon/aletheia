/*
 * file:     btl_server_p11.c
 * unit:     yes
 * function: func_021C2E4C, func_021C2E64, func_021C2F70, func_021C3008, func_021C312C, func_021C3184, func_021C3274, func_021C334C, func_021C3370, func_021C3394, func_021C33E8, func_021C3438, func_021C36A0, func_021C36E8, func_021C3720, func_021C376C, func_021C3810, func_021C39CC, func_021C39F4, func_021C3A4C, func_021C3AA8, func_021C3B68, func_021C3B8C, func_021C3BB8, func_021C3BE0, func_021C3C10, func_021C3C60, func_021C3CCC, func_021C3D08, func_021C3E0C, func_021C3FDC, func_021C4034, func_021C4104, func_021C41C0, func_021C4218, func_021C4268, func_021C4304, func_021C43F0, func_021C446C, func_021C4614, func_021C4744, func_021C4838, func_021C4910, func_021C493C, func_021C4A64, func_021C4B3C, func_021C4B8C, func_021C4B9C, func_021C4BAC, func_021C4C24, func_021C4C40, func_021C4C50, func_021C4D1C, func_021C4E38, func_021C4EA4, func_021C4F64, func_021C5098, func_021C5108, func_021C51D0, func_021C5200
 * address:  0x021C2E4C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_0201C020 0x0201C020 thumb
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021C78A8 0x021C78A8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   sub_0201C0BC  0x0201C0BC  thumb
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021D5D14 0x021D5D14 thumb ov093
 *   func_021C5A4C 0x021C5A4C thumb ov093
 *   func_021D6D7C 0x021D6D7C thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021C77B0 0x021C77B0 thumb ov093
 *   func_021C5A8C 0x021C5A8C thumb ov093
 *   func_021C785C 0x021C785C thumb ov093
 *   func_021C7820 0x021C7820 thumb ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   sub_0201BD28  0x0201BD28  thumb
 *   sub_0201BF58  0x0201BF58  thumb
 *   func_021D7C70  0x021D7C70  thumb  ov093
 *   func_021C3244  0x021C3244  thumb  ov093
 *   func_021C3254  0x021C3254  thumb  ov093
 *   func_021C3264  0x021C3264  thumb  ov093
 *   func_021C25A4  0x021C25A4  thumb  ov093
 *   func_021C331C  0x021C331C  thumb  ov093
 *   func_021C332C  0x021C332C  thumb  ov093
 *   func_021C333C  0x021C333C  thumb  ov093
 *   func_021C79E0  0x021C79E0  thumb  ov093
 *   func_021D5B48  0x021D5B48  thumb  ov093
 *   func_021D5B7C 0x021D5B7C thumb ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021C3428  0x021C3428  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021C5B74  0x021C5B74  thumb  ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021C3660 0x021C3660 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021BF324 0x021BF324 thumb ov093
 *   func_021C6948 0x021C6948 thumb ov093
 *   func_021BFA00 0x021BFA00 thumb ov093
 *   func_021C572C 0x021C572C thumb ov093
 *   func_021CC8B8 0x021CC8B8 thumb ov093
 *   func_021C5774 0x021C5774 thumb ov093
 *   func_021C6A9C 0x021C6A9C thumb ov093
 *   func_021C3670 0x021C3670 thumb ov093
 *   func_021D7AD4 0x021D7AD4 thumb ov093
 *   func_021C3680 0x021C3680 thumb ov093
 *   func_021C1678 0x021C1678 thumb ov093
 *   func_021C3690 0x021C3690 thumb ov093
 *   func_021C1828 0x021C1828 thumb ov093
 *   func_021C1C88 0x021C1C88 thumb ov093
 *   func_021C88E4 0x021C88E4 thumb ov093
 *   func_021D5FB8  0x021D5FB8  thumb  ov093
 *   func_021C604C 0x021C604C thumb ov093
 *   func_021C16F8 0x021C16F8 thumb ov093
 *   func_021D6D90  0x021D6D90  thumb  ov093
 *   func_021C37E0  0x021C37E0  thumb  ov093
 *   func_021C37F0  0x021C37F0  thumb  ov093
 *   func_021C3800  0x021C3800  thumb  ov093
 *   func_021C5718  0x021C5718  thumb  ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 *   func_021B8E28 0x021B8E28 thumb ov093
 *   func_021BB85C 0x021BB85C thumb ov093
 *   func_021B990C 0x021B990C thumb ov093
 *   func_021BDD7C 0x021BDD7C thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 *   func_021BD9D4 0x021BD9D4 thumb ov093
 *   func_021BDA00 0x021BDA00 thumb ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021D8244 0x021D8244 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B99C0  0x021B99C0  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021C3A98  0x021C3A98  thumb  ov093
 *   func_0201C184  0x0201C184  thumb
 *   func_021EF884 0x021EF884 thumb ov093
 *   func_021EF894 0x021EF894 thumb ov093
 *   func_021EF8A4 0x021EF8A4 thumb ov093
 *   func_021C7998 0x021C7998 thumb ov093
 *   func_021EF8C8  0x021EF8C8  thumb  ov093
 *   func_021E8A98  0x021E8A98  thumb  ov093
 *   func_021EF8F8  0x021EF8F8  thumb  ov093
 *   func_021C3DFC 0x021C3DFC thumb ov093
 *   func_021C3FAC 0x021C3FAC thumb ov093
 *   func_021C3FBC 0x021C3FBC thumb ov093
 *   func_021C3FCC 0x021C3FCC thumb ov093
 *   func_021C7B3C 0x021C7B3C thumb ov093
 *   func_021C7B7C 0x021C7B7C thumb ov093
 *   func_021D66D0 0x021D66D0 thumb ov093
 *   func_021D8564 0x021D8564 thumb ov093
 *   func_021C195C 0x021C195C thumb ov093
 *   func_021BD2B4  0x021BD2B4  thumb  ov093
 *   func_021BD34C  0x021BD34C  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C40F4  0x021C40F4  thumb  ov093
 *   func_021D6D5C  0x021D6D5C  thumb  ov093
 *   func_021C5DAC  0x021C5DAC  thumb  ov093
 *   func_021C5D88  0x021C5D88  thumb  ov093
 *   func_021C5840  0x021C5840  thumb  ov093
 *   func_021C59C4  0x021C59C4  thumb  ov093
 *   func_021D6D9C  0x021D6D9C  thumb  ov093
 *   func_021C1DCC  0x021C1DCC  thumb  ov093
 *   func_021C1880  0x021C1880  thumb  ov093
 *   func_021C4208  0x021C4208  thumb  ov093
 *   func_021D6D70  0x021D6D70  thumb  ov093
 *   func_021C43C0  0x021C43C0  thumb  ov093
 *   func_021C43D0  0x021C43D0  thumb  ov093
 *   func_021C43E0  0x021C43E0  thumb  ov093
 *   func_021C443C  0x021C443C  thumb  ov093
 *   func_021C444C  0x021C444C  thumb  ov093
 *   func_021C445C  0x021C445C  thumb  ov093
 *   func_021BC2B0 0x021BC2B0 thumb ov093
 *   func_021C45E4 0x021C45E4 thumb ov093
 *   func_021C45F4 0x021C45F4 thumb ov093
 *   func_021C4604 0x021C4604 thumb ov093
 *   func_021D6408 0x021D6408 thumb ov093
 *   func_021D6E88 0x021D6E88 thumb ov093
 *   func_021D701C 0x021D701C thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021B9064 0x021B9064 thumb ov093
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B9B98 0x021B9B98 thumb ov093
 *   func_021B9CE8 0x021B9CE8 thumb ov093
 *   func_021C4724 0x021C4724 thumb ov093
 *   func_021C4734 0x021C4734 thumb ov093
 *   func_021B8DEC 0x021B8DEC thumb ov093
 *   func_021B99F0 0x021B99F0 thumb ov093
 *   func_021BD43C 0x021BD43C thumb ov093
 *   func_021BD4E4 0x021BD4E4 thumb ov093
 *   func_021B8630 0x021B8630 thumb ov093
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_0202E7E0 0x0202E7E0 thumb
 *   func_0202E7E4 0x0202E7E4 thumb
 *   func_021C48E0  0x021C48E0  thumb  ov093
 *   func_021C48F0  0x021C48F0  thumb  ov093
 *   func_021C4900  0x021C4900  thumb  ov093
 *   func_021C4A24 0x021C4A24 thumb ov093
 *   func_021C4A34 0x021C4A34 thumb ov093
 *   func_021C4A44 0x021C4A44 thumb ov093
 *   func_021C4A54 0x021C4A54 thumb ov093
 *   func_021D6064 0x021D6064 thumb ov093
 *   func_021D806C 0x021D806C thumb ov093
 *   func_021C20BC 0x021C20BC thumb ov093
 *   func_021C5480 0x021C5480 thumb ov093
 *   func_021C8810 0x021C8810 thumb ov093
 *   func_021C4B2C 0x021C4B2C thumb ov093
 *   func_021C20D0 0x021C20D0 thumb ov093
 *   func_06898D54 0x06898D54 thumb ov095
 *   func_021EF934 0x021EF934 thumb ov093
 *   func_021C4C40 0x021C4C40 thumb ov093
 *   func_021C4CEC  0x021C4CEC  thumb  ov093
 *   func_021C4CFC  0x021C4CFC  thumb  ov093
 *   func_021C4D0C  0x021C4D0C  thumb  ov093
 *   func_021EF8B8 0x021EF8B8 thumb ov093
 *   func_021C2AB0 0x021C2AB0 thumb ov093
 *   func_021C4E08 0x021C4E08 thumb ov093
 *   func_021C4E18 0x021C4E18 thumb ov093
 *   func_021C4E28 0x021C4E28 thumb ov093
 *   func_021D5BDC 0x021D5BDC thumb ov093
 *   func_021D7BD4 0x021D7BD4 thumb ov093
 *   func_021C70E4 0x021C70E4 thumb ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C5078 0x021C5078 thumb ov093
 *   func_021BA1A8 0x021BA1A8 thumb ov093
 *   func_021D646C 0x021D646C thumb ov093
 *   func_021B92B0 0x021B92B0 thumb ov093
 *   func_021C5088 0x021C5088 thumb ov093
 *   func_021B902C 0x021B902C thumb ov093
 *   func_021BA1B4 0x021BA1B4 thumb ov093
 *   func_021B8640  0x021B8640  thumb  ov093
 *   func_021B8DE4  0x021B8DE4  thumb  ov093
 *   func_021C50F8  0x021C50F8  thumb  ov093
 *   func_021BFF60 0x021BFF60 thumb ov093
 *   func_021D8510 0x021D8510 thumb ov093
 *   func_021DCF24 0x021DCF24 thumb ov093
 *   func_021D8538 0x021D8538 thumb ov093
 *   func_021DCFA4 0x021DCFA4 thumb ov093
 *   func_021E0434 0x021E0434 thumb ov093
 *   func_021BD338 0x021BD338 thumb ov093
 *   func_021D6264 0x021D6264 thumb ov093
 *   func_021EF90C 0x021EF90C thumb ov093
 *   func_021B85EC 0x021B85EC thumb ov093
 *   func_021C52C8 0x021C52C8 thumb ov093
 *   func_021C52D8 0x021C52D8 thumb ov093
 *   func_021C52E8 0x021C52E8 thumb ov093
 *   func_021BC310 0x021BC310 thumb ov093
 *   func_021B86DC 0x021B86DC thumb ov093
 *   func_021C5308 0x021C5308 thumb ov093
 *   func_021C52F8 0x021C52F8 thumb ov093
 */
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj13327.h"
#include "../../matched/include/Obj09969.h"
#include "../../matched/include/Obj21086.h"
#include "../../matched/include/Obj09970.h"
#include "../../matched/include/Obj21090.h"
#include "../../matched/include/Obj13329.h"
#include "../../matched/include/Obj09971.h"
#include "../../matched/include/Obj21091.h"
#include "../../matched/include/Obj13330.h"
#include "../../matched/include/Obj13331.h"
#include "../../matched/include/Obj03191.h"
#include "../../matched/include/Obj07754.h"
#include "../../matched/include/Obj21095.h"
#include "../../matched/include/Obj21096.h"
#include "../../matched/include/Obj05192.h"
#include "../../matched/include/Obj07755.h"

struct Unk021D62A8;
struct Msg;
struct B;
struct Q1;
struct S_021C2E4C;
struct S2;
struct QJ;
union Slot;
struct UtilWork;
struct S;
struct UtilSlots;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed int s32;

typedef struct { u32 x; } W_021C2E4C;

enum Kind { K0, K1, K10 = 10 };

struct Lock { u32 a:10; u32 b:9; u32 c:9; u32 d:1; u32 e:1; u32 f:1; u32 g:1; };

typedef signed char s8;

typedef signed short s16;

typedef struct { u8 pad[5]; u8 f : 1; } BF;

typedef struct { u16 v; } W_021C312C;

typedef struct { u32 x; } O;

typedef struct { u32 v; } Word_021C2E4C;

struct Flags_021C2E4C { u8 pad[5]; u8 a:1; u8 rest:7; };

typedef struct { u8 pad[5]; u8 f : 1; } Q;

enum Mode { M0, M1, M2, Mneg = -1 };

struct Pair { u8 count, id; };

struct Msg { u16 a; u16 kind:8; u16 n:7; u16 flag:1; u8 data[0x1c]; u32 w20; };

typedef enum { FALSE = 0, TRUE = 1 } BOOL;

typedef struct { int x; } S_021C2E4C;

typedef struct { u8 pad[5]; u8 a:1,b:1,c:6; } Flag;

typedef struct { u8 a:4,b:1,c:3; } ByteFlag;

typedef struct { int a; u8 b; } S_021C4104;

typedef unsigned long long u64;

typedef struct { u32 value; } Word_021C4910;

struct Flags_021C5108 { u8 a:1; u8 b:1; u8 rest:6; };

extern u8 func_021D5440(u8 *p);
extern u8 func_0201C020(u16);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021C78A8(u8 *, u8 *, u32, u32, u32);
extern u8 sub_0201C0BC(u16 id, u32 idx, s32 *out);
extern void func_021D74F8(int line);
extern void func_021D75EC(int key, u32 val);
extern void func_021D75A8(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern int func_021D5D14(s8 *p, int i, int sign);
extern void func_021C5A4C(u8 *p, u8 *a, int b, int c);
extern u32 func_021D6D7C(u8 *p);
extern void func_021CD64C(void *, u8, ...);
extern int func_021C77B0(u8 *, u8 *, u32, u32, u32, u32);
extern void func_021C5A8C(u8 *p, u8 *a, int c, int d, u16 msg, int flag);
extern void func_021C785C(u8 *, u32, u8 *, u32, u32);
extern void func_021C7820(u8 *, u8 *, u32);
extern void func_021D7630(int key, u32 val);
extern u32 sub_0201BD28(u16 id, u32 field);
extern W_021C312C sub_0201BF58(u16 id);
extern void func_021D7C70(W_021C312C, u32, Word_021C2E4C *);
extern void func_021C3244(u32 c);
extern u32 func_021C3254(u32 c);
extern u32 func_021C3264(u32 c);
extern int func_021C25A4(u8 *p, u32 a, u32 b, u32 unused, u32 s0, O s1, u32 s2);
extern void func_021C331C(u32 c);
extern u32 func_021C332C(u32 c);
extern u32 func_021C333C(u32 c);
extern u32 func_021C79E0(u8 *p, u32 x, u8 *a);
extern int func_021D5B48(u8 *p);
extern int func_021D5B7C(void *);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021C3428(int, int);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C5B74(u8 *p, u8 *a, int c, int d);
extern int func_021D59B4(u8 *p, int k);
extern u32 func_021C3660(void *, u32);
extern int func_021D5B68(void *);
extern int func_021BF324(u8 *, u8 *, u8 *);
extern int func_021C6948(u8 *, u8 *, u8 *, u32);
extern int func_021BFA00(u8 *, u8 *, u8 *, void *);
extern void func_021C572C(u8 *, u8 *, u32);
extern u32 func_021CC8B8(u32 *, u32);
extern void func_021C5774(u8 *, u8 *);
extern int func_021C6A9C(u8 *, u8 *, u8 *, u16);
extern u8 func_021C3670(u8 *, u8);
extern int func_021D7AD4(int);
extern void func_021C3680(void *, u32, u16, int);
extern int func_021C1678(u8 *, u8 *, u8 *, u32, u16 *);
extern void func_021C3690(void *, u32, u16, int);
extern void func_021C1828(u8 *p, u8 b, u8 *x, u8 *c, u8 *q, u16 w);
extern void func_021C1C88(u8 *, u8 *, u32, u8 *, u32);
extern int func_021C88E4(u8 *);
extern void func_021D5FB8(u8 *p);
extern void func_021C604C(u8 *, u8 *, int);
extern void func_021C16F8(u8 *, u8 *, int);
extern int func_021D6D90(u8 *p);
extern void func_021C37E0(int it);
extern int func_021C37F0(int it);
extern int func_021C3800(int it);
extern void func_021C5718(u8 *p, int b, int c);
extern int func_021B8D8C(void *, void *, u32);
extern u8 func_021D69AC(u8 *, int);
extern void func_021B8E28(u8 *, int, u8 *, u8 *);
extern u8 *func_021BB85C(u8 *p, unsigned int i);
extern void *func_021B990C(char *p, unsigned int i, unsigned int j);
extern void func_021BDD7C(u8 *, u8 *, u32);
extern int func_021C99A0(void *, const struct Msg *);
extern void func_021BD9D4(u8 *p, u8 i, u8 a, u8 b, int c);
extern int func_021BDA00(u8 *);
extern u8 func_021B8DDC(u32 x);
extern void func_021D8244(struct B *p, int n);
extern u32 func_021B8588(void **p);
extern void *func_021B86B8(void ***);
extern u8 func_021B9B94(struct Q1 *p);
extern int func_021B99C0(struct S_021C2E4C **p, u32 b);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern u32 func_021D78AC(u32 range);
extern void func_021C3A98(u8 *p, u8 *a);
extern u32 func_0201C184(int id);
extern int func_021EF884(void);
extern int func_021EF894(void);
extern void func_021EF8A4(u32, u32);
extern void func_021C7998(u8 *, u32);
extern int func_021EF8C8(int a, S_021C2E4C c);
extern int func_021E8A98(S_021C2E4C c);
extern void func_021EF8F8(int a, int r);
extern int func_021C3DFC(u8 *);
extern u8 *func_021C3FAC(u8 *, int);
extern int func_021C3FBC(u16);
extern int func_021C3FCC(u16);
extern void func_021C7B3C(u8 *p, u32 a, u16 b, u16 c);
extern void func_021C7B7C(u8 *p, unsigned int i);
extern void func_021D66D0(struct QJ *p, u32 v);
extern void func_021D8564(int a, int b);
extern void func_021C195C(u8 *p, u8 *q, u32 n);
extern void func_021BD2B4(u8 *it, u8 **q);
extern int func_021BD34C(u8 *it, u8 **q, u8 **x);
extern int func_021B9A24(unsigned int a, unsigned int b);
extern int func_021D7B74(u8 *p, u32 k);
extern int func_021C40F4(u8 *p, int i);
extern void func_021D6D5C(u8 *a, u16 v);
extern void func_021C5DAC(u8 *p, u32 a, int n, const int *v);
extern void func_021C5D88(u8 *p, u8 *a, int b);
extern void func_021C5840(u8 *p, u32 count, int *v, u8 **a, int flag);
extern void func_021C59C4(u8 *p, u32 n, u8 **a, u8 *b, int flag);
extern int func_021D6D9C(u8 *c, u16 *d);
extern void func_021C1DCC(u8 *p, u8 *q, u32 a, u8 *b, u32 s);
extern void func_021C1880(u8 *p, u8 *q, u8 *a, u8 *b, u32 s0, int s1);
extern int func_021C4208(u8 *p, int i);
extern void func_021D6D70(u8 *p);
extern int func_021C43C0(u8 *c);
extern int func_021C43D0(u8 *c);
extern u8 *func_021C43E0(u8 *c, u8 i);
extern void func_021C443C(u8 *a);
extern void func_021C444C(u8 *a, u8 *x);
extern void func_021C445C(u8 *a, u8 *p);
extern int func_021BC2B0(u8 *);
extern void func_021C45E4(u8 *);
extern u8 *func_021C45F4(u8 *);
extern u8 *func_021C4604(u8 *);
extern void func_021D6408(u8 *);
extern void func_021D6E88(u8 *);
extern void func_021D701C(void);
extern u8 func_021B8FF4(u8 *);
extern u32 func_021B9064(u8 *p, int k, int x);
extern char *func_021B9AEC(char *p, int i);
extern u8 func_021B9B98(u8 *p);
extern void *func_021B9CE8(u8 *p);
extern u32 func_021C4724(u8 *, u32);
extern u32 func_021C4734(u8 *, u32);
extern u8 func_021B8DEC(void *, int);
extern u32 func_021B99F0(u32);
extern void func_021BD43C(u8 *, int, u8, u8, int);
extern void func_021BD4E4(u8 *, int, u8, u8);
extern u32 func_021B8630(u32 **p);
extern u32 func_0202E7E0(void *);
extern u32 func_0203F0A8(void);
extern u8 *func_021B9934(char *, int);
extern void func_0202E7E4(void *);
extern void func_021C48E0(u8 *a);
extern u8 *func_021C48F0(u8 *a);
extern u8 *func_021C4900(u8 *a);
extern u32 func_021C4A24(u8 *);
extern u8 *func_021C4A34(u8 *, u32);
extern u8 *func_021C4A44(u32);
extern void func_021C4A54(u8 *, u8 *, Word_021C4910, u32, u8 *);
extern int func_021D6064(u8 *p, u32 k, union Slot *out, int *changed);
extern u32 func_021D806C(const u8 *p);
extern int func_021C20BC(u8 *, u8 *, int);
extern void func_021C5480(u8 *, u8 *, int);
extern void func_021C8810(u8 *);
extern void func_021C4B2C(u8 *, u8 *, u32);
extern int func_021C20D0(u8 *p, u8 *a, int c, u8 *l);
extern void func_06898D54(void (*cb)(u8, u32, u32), u32 arg);
extern int func_021EF934(int, int);
extern void func_021C4C40(int, void *);
extern void func_021C4CEC(u8 *a);
extern u8 *func_021C4CFC(u8 *a);
extern u8 *func_021C4D0C(u8 *a);
extern u32 func_021EF8B8(void);
extern int func_021C2AB0(u8 *);
extern void func_021C4E08(void *);
extern u8 *func_021C4E18(void *);
extern u8 *func_021C4E28(void *);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern int func_021D7BD4(void *, int);
extern void func_021C70E4(u8 *p, int a, int b, int c, int e, u32 f);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 val);
extern int func_021C8010(u8 *p, u32 x);
extern void func_021C5078(u8 *, u8);
extern int func_021BA1A8(char **p, int m);
extern void func_021D646C(u8 *);
extern void func_021B92B0(char *p, void *m, int k);
extern void func_021C5088(u8 *, u8);
extern int func_021B902C(int, int);
extern void func_021BA1B4(char **p, int i);
extern unsigned int func_021B8640(unsigned int **p);
extern u8 func_021B8DE4(char *p, int i);
extern u8 func_021C50F8(u8 *q, u8 i);
extern void func_021BFF60(u8 *, u8 *, int);
extern void func_021D8510(void *p);
extern void func_021DCF24(u8 *);
extern void func_021D8538(void *p);
extern void func_021DCFA4(void *p);
extern void func_021E0434(u8 *);
extern void func_021BD338(u8 *, u8 *);
extern void func_021D6264(struct UtilSlots *p, int v);
extern int func_021EF90C(int a);
extern int func_021B85EC(u32 **p);
extern u32 func_021C52C8(u8 *, int);
extern int func_021C52D8(u8 *, int, u8);
extern int func_021C52E8(u8 *, int, u8);
extern int func_021BC310(u8 *);
extern u16 func_021B86DC(void **p);
extern int func_021C5308(u8 *, u8 *);
extern void func_021C52F8(u8 *, int, u8);
u32 func_021C2E4C(u8 *p);
int func_021C2E64(u8 *p, const u16 *q, u8 *a, u8 *b, int k);
void func_021C2F70(u8 *p, u16 x, u32 y, u8 *c, u8 *s0, s32 *s1, s32 *s2);
int func_021C3008(u8 *p, u8 b, u8 *a, enum Kind kind, int value, u8 f, u16 g, u32 h, int i, u32 j);
int func_021C312C(u8 *p, u8 *a, enum Kind b, u8 c, u16 e, int d);
void func_021C3184(u8 *p, const u16 *q, u32 r, u32 c);
void func_021C3274(u8 *p, u32 q, u32 b, u32 c);
int func_021C334C(u8 *p, u8 *q, int a, int b);
int func_021C3370(u8 *p, void *q);
int func_021C3394(u8 *p, u8 *q, int r);
void func_021C33E8(int a, int b, int c);
void func_021C3438(u8 *p, u16 *q, u8 *a, u8 *out);
void func_021C36A0(u8 *p, u8 *a, u16 *b, int c);
void func_021C36E8(u8 *p, u8 *q, u16 *r, int a, int b, u16 c);
u16 func_021C3720(u8 *p, u8 *a, u16 *b, int c);
void func_021C376C(u8 *p, u16 a1, int b, int it);
int func_021C3810(u8 *p, u8 *a, u8 *b, int force, int *out, u16 move, int ignore, const struct Msg *msg);
BOOL func_021C39CC(u8 *p);
int func_021C39F4(u8 *a, u8 *b);
int func_021C3A4C(u8 *p, int unused, u8 *a);
void func_021C3AA8(u8 *p, u16 *a, u8 *b);
int func_021C3B68(u8 *p, int a, u8 b);
BOOL func_021C3B8C(void *p, u32 a, u32 b);
void func_021C3BB8(u8 *p, u32 a, u32 b);
void func_021C3BE0(u8 *p, u32 a);
u8 func_021C3C10(u8 *p, int k, u8 *a);
int func_021C3C60(u8 *p, int a, S_021C2E4C c, int d);
void func_021C3CCC(u8 *p, u8 *b, int c);
void func_021C3D08(u8 *p, u16 *b, u8 *a, u8 *c);
void func_021C3E0C(u8 *p, u8 *a, u8 *c);
void func_021C3FDC(u8 *p, u8 *a);
int func_021C4034(u8 *p, u8 *a);
u16 func_021C4104(u8 *p, u32 q, u8 *c, u16 d, S_021C4104 s, u16 *e);
void func_021C41C0(u8 *p, u8 *a);
void func_021C4218(u8 *p, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3);
void func_021C4268(u8 *p, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3);
int func_021C4304(u8 *p, u16 *b, u8 *a, u8 *c, int *out);
void func_021C43F0(u8 *p, u8 *a);
int func_021C446C(u8 *p);
void func_021C4614(u8 *p);
void func_021C4744(u8 *p);
int func_021C4838(u8 *p, u8 *a, u8 *b);
void func_021C4910(u8 *p, u32 a, int k);
int func_021C493C(u8 *p, u8 *a);
void func_021C4A64(u8 *p, u8 *a, u32 b, u32 c);
int func_021C4B3C(u8 *p, u8 *a, u32 b, u32 c);
void func_021C4B8C(u8 *p);
void func_021C4B9C(int v, int k, u8 *p);
void func_021C4BAC(u8 *p, int k, int v);
void func_021C4C24(u8 *p);
void CallbackForJpeg(int result, void *arg);
void func_021C4C50(u8 *p, int k);
int func_021C4D1C(u8 *p, void *it);
int func_021C4E38(u8 *p, u8 *a, u32 b, u32 c);
void func_021C4EA4(u8 *p, u8 *a, int k, int n);
int func_021C4F64(u8 *p, u8 *a);
u32 func_021C5098(u8 *p);
void func_021C5108(u8 *p, u8 *a, int b);
void func_021C51D0(u8 *p, u8 *a);
int func_021C5200(u8 *p);
























u32 func_021C2E4C(u8 *p)
{
    if (++((struct Obj00003 *)p)->f778 == 0)
        ((struct Obj00003 *)p)->f778 = 1;
    return ((struct Obj00003 *)p)->f778;
}

























/*
 * lever: enum Kind keeps the output guard in r0 and reloads it into r3 at the call.
 */
int func_021C2E64(u8 *p, const u16 *q, u8 *a, u8 *b, int k)
{
    u8 id;
    int result;
    u32 count, i;
    u32 serial;
    enum Kind kind;
    s32 value;
    int ok;
    u8 j;
    u32 lock;
    result = 0;
    id = func_021D5440(a);
    serial = func_021C2E4C(p);
    count = func_0201C020(*q);
    for (i = 0; i < count; i++) {
        ok = 0;
        func_021C2F70(p, *q, i, a, b, (s32 *)&kind, &value);
        if (kind != 0) {
            if (kind != 10) {
                ok = func_021C3008(p, id, b, kind, value, id, ok, serial, k, 1);
            } else {
                for (j = 1; j < 6; j++) {
                    if (func_021C3008(p, id, b, j, value, id, 0, serial, k, 1)) ok = 1;
                }
            }
            if (ok) {
                lock = func_021CC8D8((struct Lock *)(p + 0x1d74), 8247);
                func_021C78A8(p, b, *q, kind, value);
                func_021CC95C((u32 *)(p + 0x1d74), lock, 8249);
                result = 1;
            }
        }
    }
    return result;
}


























void func_021C2F70(u8 *p, u16 x, u32 y, u8 *c, u8 *s0, s32 *s1, s32 *s2)
{
    u32 m;
    *s1 = sub_0201C0BC(x, y, s2);
    func_021D74F8(8275);
    func_021D75EC(3, func_021D5440(c));
    func_021D75EC(4, func_021D5440(s0));
    func_021D75A8(0x1F, *s1);
    func_021D75A8(0x20, *s2);
    func_021D75A8(0x35, 1);
    func_021D70F0(p, 0x59);
    *s1 = func_021D775C(0x1F);
    *s2 = func_021D775C(0x20);
    m = (u8)func_021D775C(0x35);
    if (m > 1)
        *s2 = *s2 * m;
    func_021D7540(8290);
    if (*s1 == 8)
        *s1 = 0;
}























/*
 * lever: reassigning value to the transformed result keeps it in its incoming register.
 */
int func_021C3008(u8 *p, u8 b, u8 *a, enum Kind kind, int value, u8 f, u16 g, u32 h, int i, u32 j)
{
    int result;
    u32 lock;
    value = func_021C312C(p, a, kind, f, g, value);
    if (!func_021D5D14((s8 *)a, kind, value)) {
        if (i) {
            func_021C5A4C(p, a, kind, value);
            ((struct Obj00003 *)p)->f78A |= 0x10;
        }
        return 0;
    }
    if (func_021D6D7C(a)) {
        u8 id;
        id = func_021D5440(a);
        if (b != id) {
            if (i) func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0xd2, id, 0xffff0000);
            return 0;
        }
    }
    result = 1;
    if (func_021C77B0(p, a, kind, b, value, h)) {
        func_021C5A8C(p, a, kind, value, g, j);
        lock = func_021CC8D8(p + 0x1d74, 8349);
        func_021C785C(p, b, a, kind, value);
        func_021CC95C((u32 *)(p + 0x1d74), lock, 8351);
    } else {
        if (i) {
            lock = func_021CC8D8(p + 0x1d74, 8358);
            func_021C7820(p, a, h);
            func_021CC95C((u32 *)(p + 0x1d74), lock, 8360);
        }
        result = 0;
    }
    return result;
}
























/*
 * Note (final push 2026-10-05 G4L8): the script result is written back into the
 * stack parameter d (the caller func_021C3008 does value = func_021C312C(..., value)).
 * Assigning to a stack-passed parameter, instead of a fresh local r, keeps the end
 * line as its own pool word (no ldr + adds #7 fold). Both --lang c99 and c EXACT.
 */
int func_021C312C(u8 *p, u8 *a, enum Kind b, u8 c, u16 e, int d)
{
    func_021D74F8(8385);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(3, c);
    func_021D75EC(0x1F, b);
    func_021D7630(0x20, d);
    func_021D70F0(p, 0x5A);
    d = func_021D775C(0x20);
    func_021D7540(8392);
    return d;
}
























/*
 * sub_0201BF58 is declared here as returning a one-halfword struct (the
 * store of r0 with no sign extension and the dead-looking second strh are
 * the struct-return temp plus its copy); its own file says s16.
 * func_021D7C70's first argument and func_021C25A4's sixth are structs
 * passed by value.
 */
void func_021C3184(u8 *p, const u16 *q, u32 r, u32 c)
{
    u32 t, s;
    O out;
    W_021C312C v;
    s = sub_0201BD28(*q, 0xB);
    v = sub_0201BF58(*q);
    func_021D7C70(v, r, (Word_021C2E4C *)&out);
    func_021C3244(c);
    for (t = func_021C3254(c); t != 0; t = func_021C3264(c)) {
        if (func_021C2E64(p, (const u16 *)((u32)q), (u8 *)r, (u8 *)t, 1) != 0) {
            BF *f = *(BF * *)&((struct Obj13327 *)p)->f4A8;
            if (!f->f)
                f->f = 1;
        }
        if (func_021C25A4(p, r, t, *q, s, out, 1) != 0) {
            BF *f = *(BF * *)&((struct Obj13327 *)p)->f4A8;
            if (!f->f)
                f->f = 1;
        }
    }
}






















void func_021C3274(u8 *p, u32 q, u32 b, u32 c)
{
    u32 t;
    func_021C331C(c);
    for (t = func_021C332C(c); t != 0; t = func_021C333C(c)) {
        u8 m = func_021D5440((u8 *)t);
        if (func_021C3370(p, (void *)t) == 0) {
            if (func_021C334C(p, (u8 *)t, (u16)func_021C79E0(p, q, (u8 *)t), 1) != 0) {
                BF *f = *(BF * *)&((struct Obj09969 *)p)->f4A8;
                if (!f->f)
                    f->f = 1;
                func_021CD64C(((struct Obj09969 *)p)->fC, 0x5b, 387, m, 0xffff0000);
            }
        } else if (func_021D5B48((u8 *)t) != 0) {
            func_021CD64C(((struct Obj09969 *)p)->fC, 0x5b, 893, m, 0xffff0000);
        }
    }
}






















int func_021C334C(u8 *p, u8 *q, int a, int b)
{
    if (func_021C3394(p, q, b) == 0) {
        func_021C33E8((int)p, (int)q, a);
        return 1;
    }
    return 0;
}






















int func_021C3370(u8 *p, void *q)
{
    if (func_021D5B7C(q) == 0) return 1;
    if (func_021D5B48(q) != 0) return 1;
    return 0;
}























int func_021C3394(u8 *p, u8 *q, int r)
{
    if (func_021D62C4((struct Unk021D62A8 *)q, 15) != 0) {
        if (r != 0) {
            func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 887, func_021D5440(q), 0xffff0000);
            p[0x78A] |= 0x20;
        }
        return 1;
    }
    return 0;
}























void func_021C33E8(int a, int b, int c)
{
    int v = func_021C3428(a + 0x1ab8, func_021D5440((u8 *)b));
    if (v != 6)
        func_021CD4B0((void *)(*(int *)&((struct Obj00003 *)a)->fC), 0x4d, v, 0x263);
    func_021C5B74((u8 *)a, (u8 *)b, c, 1);
}




















void func_021C3438(u8 *p, u16 *q, u8 *a, u8 *out)
{
    u8 speed;
    u8 *b;
    u8 id;
    u32 item;
    u32 lock;
    u8 tag;
    int category;
    int event1, event2;
    u32 i;
    u16 half;
    struct Flags_021C2E4C *flags;
    i = 0;
    speed = (u8)func_021D59B4(a, 15);
    for (;;) {
        int kind;
        b = (u8 *)func_021C3660(out, i++);
        if (b == 0) break;
        if (func_021D5B68(b)) continue;
        id = func_021D5440(b);
        if (!func_021BF324(p, a, b)) {
            if (func_021C6948(p, a, b, *q)) {
                func_021C572C(p, b, *q);
                continue;
            }
        }
        if (func_021BFA00(p, a, b, (void *)(u32)*q)) {
            func_021C572C(p, b, *q);
            continue;
        }
        if (speed < (u8)func_021D59B4(b, 15)) {
            func_021C5774(p, b);
            continue;
        }
        item = func_021CC8B8((u32 *)(p + 0x1f88), id);
        if (item == 0) {
            func_021C5774(p, b);
            continue;
        }
        lock = func_021CC8D8(p + 0x1d74, 0x216b);
        if (func_021C6A9C(p, a, b, *q)) {
            tag = func_021C3670(p + 0x1ab8, func_021D5440(a));
            half = func_021D59B4(b, 13);
            category = func_021D7AD4(item);
            event1 = 0;
            event2 = 0;
            flags = *(struct Flags_021C2E4C * *)&((struct Obj21086 *)p)->f4A8;
            if (!flags->a) flags->a = 1;
            if (func_021D6D7C(b)) {
                half = func_021C3720(p, b, q, category);
                func_021C3680(out, (u32)b, half, 1);
                event1 = 1;
            } else {
                kind = func_021C1678(p, a, b, 1, &half);
                if (kind == 0) {
                    func_021C36A0(p, b, q, category);
                } else {
                    func_021C36E8(p, b, q, category, kind, half);
                    func_021C3690(out, (u32)b, half, 0);
                    event2 = 1;
                }
            }
            if (!event1) func_021C1828(p, tag, a, b, (u8 *)q, half);
            func_021C4218(p, a, b, (u8 *)q, item, half, 0, event1);
            if (event2 || event1) func_021C1C88(p, a, (u32)out, (u8 *)q, 0);
            func_021C4F64(p, b);
        } else if (!func_021C88E4(p)) {
            func_021C572C(p, b, *q);
        }
        func_021CC95C((u32 *)(p + 0x1d74), lock, 0x219c);
    }
}




















void func_021C36A0(u8 *p, u8 *a, u16 *b, int c)
{
    int i = func_021D5440(a);
    func_021D5FB8(a);
    func_021CD4B0(((struct Obj09970 *)p)->fC, 3, i);
    func_021CD4B0(((struct Obj09970 *)p)->fC, 0x32, i, (u8)c, *b);
    func_021CD4B0(((struct Obj09970 *)p)->fC, 0x34, i);
}




















/*
 * The final 00 00 at 0x021C371E is alignment padding before 0x021C3720.
 * A separate call-result local keeps the halfword load before that call.
 */
void func_021C36E8(u8 *p, u8 *q, u16 *r, int a, int b, u16 c)
{
    int n;
    int v;
    func_021C604C(p, q, c);
    n = *r;
    v = func_021D5440(q);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x32, v, (u8)a, n);
    func_021C16F8(p, q, b);
}





















u16 func_021C3720(u8 *p, u8 *a, u16 *b, int c)
{
    int i = func_021D5440(a);
    u16 v = func_021D6D90(a);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x34, i);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x32, i, (u8)c, *b);
    func_021C41C0(p, a);
    return v;
}





















void func_021C376C(u8 *p, u16 a1, int b, int it)
{
    int v = 0;
    int r;
    func_021C37E0(it);
    r = func_021C37F0(it);
    while (r) {
        if (func_021C3810(p, (u8 *)b, (u8 *)r, 0, &v, 0, 0, 0)) {
            Q *q = *(Q * *)&((struct Obj21090 *)p)->f4A8;
            if (!q->f)
                q->f = 1;
        } else if (v == 0) {
            func_021C5718(p, b, a1);
        }
        r = func_021C3800(it);
    }
}


















static inline u8 rule(u8 n)
{
    if (n != 0) {
        n--;
        if (n < 24) return n;
    }
    return 31;
}


















/*
 * lever: func_021B8E28 receives the full position int; its own u8 signature adds an absent truncation.
 */
int func_021C3810(u8 *p, u8 *a, u8 *b, int force, int *out, u16 move, int ignore, const struct Msg *msg)
{
    enum Mode mode;
    int position;
    u32 lock;
    u8 blocked;
    struct Pair pair;
    *out = 0;
    if (force) mode = M1;
    else mode = func_021C39CC(p);
    if (mode == M2) return 0;
    position = func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, func_021D5440(b));
    if (position == 6) return 0;
    if (func_021D5B68(b)) return 0;
    if (func_021D62C4((struct Unk021D62A8 *)b, 33)) return 0;
    if (rule(func_021D69AC(b, 4)) != 31) return 0;
    lock = func_021CC8D8(p + 0x1d74, 8732);
    blocked = func_021C3A4C(p, (int)a, b);
    if (blocked && func_021C88E4(p)) *out = 1;
    func_021CC95C((u32 *)(p + 0x1d74), lock, 8740);
    if (blocked) return 0;
    func_021B8E28(*(u8 * *)&((struct Obj00003 *)p)->f4, position, &pair.id, &pair.count);
    if (mode == M1) {
        u8 id;
        mode = func_021C39F4(p, func_021BB85C(*(u8 * *)&((struct Obj00003 *)p)->f0, pair.id));
        if (mode >= 0) {
            id = func_021D5440((u8 *)func_021B990C((char *)(*(u32 *)&((struct Obj00003 *)p)->f8), pair.id, (u8)mode));
            func_021BDD7C(p, b, move);
            if (msg) func_021C99A0(p, msg);
            func_021BD9D4(p, pair.id, pair.count, (u8)mode, 0);
            func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 845, id, 0xffff0000);
            func_021BDA00(p);
        } else return 0;
    } else {
        int slot;
        slot = func_021B8DDC(func_021D5440(a));
        if (!ignore) {
            u8 speed;
            speed = (u8)func_021D59B4(a, 15);
            if ((u8)func_021D59B4(b, 15) > speed) return 0;
        }
        func_021D8244((struct B *)(p + 0x4b8), slot);
        func_021BDD7C(p, b, move);
        *(u32 *)&((struct Obj00003 *)p)->f14 = 5;
    }
    return 1;
}


















BOOL func_021C39CC(u8 *p)
{
    u32 a;
    void *b;
    a = func_021B8588(((struct Obj13329 *)p)->f4);
    b = func_021B86B8(*(void *** *)&((struct Obj13329 *)p)->f4);
    if (a == 0) {
        if (b == 0) {
            return FALSE;
        } else {
            return TRUE;
        }
    }
    return TRUE;
}



















int func_021C39F4(u8 *a, u8 *b)
{
    u8 buf[8];
    u32 n;
    u32 i;
    int c;

    n = func_021B9B94(((struct Obj09971 *)b)->f4);
    i = func_021B99C0(((struct Obj21091 *)a)->f4, b[0xb]);
    c = 0;
    for (; i < n; i++) {
        if (func_021D5B7C(func_021B9C00(((struct Obj09971 *)b)->f4, (u8)i))) {
            buf[c] = i;
            c++;
        }
    }
    if (c != 0) {
        return buf[func_021D78AC(c)];
    }
    return -1;
}



















int func_021C3A4C(u8 *p, int unused, u8 *a)
{
    int r;
    func_021D74F8(8877);
    func_021D7630(0x41, 0);
    func_021D75EC(4, func_021D5440(a));
    func_021D70F0(p, 0x8b);
    func_021C3A98(p, a);
    r = func_021D775C(0x41);
    func_021D7540(8883);
    return r;
}



















void func_021C3AA8(u8 *p, u16 *a, u8 *b)
{
    u8 k = func_0201C184(*a);
    if (k) {
        int x = func_021C3C10(p, k, b);
        if (func_021C3B68(p, k, (u8)(x + 5))) {
            Q *q = *(Q * *)&((struct Obj13330 *)p)->f4A8;
            if (!q->f)
                q->f = 1;
            return;
        }
        func_021C5718(p, (int)b, *a);
    } else {
        u32 s;
        int e;
        s = func_021CC8D8(p + 0x1d74, 0x22c8);
        func_021C3CCC(p, b, *a);
        e = (func_021C88E4(p) == 2);
        func_021CC95C((u32 *)(p + 0x1d74), s, 0x22cc);
        if (e) {
            Q *q = *(Q * *)&((struct Obj13330 *)p)->f4A8;
            if (!q->f)
                q->f = 1;
        } else {
            func_021C5718(p, (int)b, *a);
        }
    }
}


















int func_021C3B68(u8 *p, int a, u8 b)
{
    if (func_021C3B8C(p, a, b)) {
        func_021C3BB8(p, a, b);
        return 1;
    }
    return 0;
}


















BOOL func_021C3B8C(void *p, u32 a, u32 b)
{
    if (a >= 5) return FALSE;
    if (a == func_021EF884() && (b != 255 || func_021EF894() == 255)) {
        return FALSE;
    }
    return TRUE;
}


















void func_021C3BB8(u8 *p, u32 a, u32 b)
{
    func_021EF8A4(a, b);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x3f, a, b);
    func_021C3BE0(p, a);
}


















/*
 * interface: Lock scalar word return preserves the complete r0 payload,
 * as in matched caller 021C3810; restore consumes the same word.
 */
void func_021C3BE0(u8 *p, u32 a)
{
    u32 old;
    int line = 0x2303;
    old = func_021CC8D8(p + 0x1d74, line);
    func_021C7998(p, a);
    func_021CC95C((u32 *)(p + 0x1d74), old, line + 2);
}



















u8 func_021C3C10(u8 *p, int k, u8 *a)
{
    u8 r;
    func_021D74F8(8983);
    func_021D75EC(0x39, k);
    func_021D75EC(3, func_021D5440(a));
    func_021D75A8(0x24, 0);
    func_021D70F0(p, 0x7c);
    r = func_021D775C(0x24);
    func_021D7540(8989);
    return r;
}



















/*
 * The handed address 0x021C3C62 is the second label after `push {r0-r3}`
 * (0x021C3C60). The third parameter is a one-word struct passed by value
 * (its home slot is read through `add r7, sp, #0x20`).
 */
int func_021C3C60(u8 *p, int a, S_021C2E4C c, int d)
{
    int r;
    if (func_021EF8C8(a, c)) {
        func_021CD4B0(((struct Obj13331 *)p)->fC, 0x21, (u8)a, c.x);
        return 1;
    }
    if (d) {
        r = func_021E8A98(c);
        if (r != 0x1f) {
            func_021EF8F8(a, r);
            func_021CD4B0(((struct Obj13331 *)p)->fC, 0x22, (u8)a, r);
            return 1;
        }
    }
    return 0;
}


















void func_021C3CCC(u8 *p, u8 *b, int c)
{
    int line = 0x2360;
    func_021D74F8(line);
    func_021D75A8(3, func_021D5440(b));
    func_021D75A8(0x12, c);
    func_021D70F0(p, 0x9e);
    func_021D7540(line + 4);
}

















void func_021C3D08(u8 *p, u16 *b, u8 *a, u8 *c)
{
    int out;
    u32 s, r;
    Flag *f;
    if (func_021C3DFC(c) != 0) return;
    switch (*b) {
    case 0x11d:
        func_021C3E0C(p, a, c);
        return;
    case 0xa4:
        if (func_021C4034(p, a)) {
            f = *(Flag * *)&((struct Obj03191 *)p)->f4A8;
            if (f->a == 0) {
                f->a = 1;
                f->b = 1;
            }
        }
        return;
    default:
        s = func_021CC8D8(p + 0x1d74, 9087);
        r = func_021C88E4(p);
        if (func_021C4304(p, b, a, c, &out)) {
            r = func_021C88E4(p);
            if (r == 2) {
                f = *(Flag * *)&((struct Obj03191 *)p)->f4A8;
                if (f->a == 0) f->a = 1;
            }
        }
        if (r <= 1 && out != 0 && ((ByteFlag *)(p + 0x78a))->b == 0) {
            func_021CD64C(((struct Obj03191 *)p)->fC, 0x5a, 0x47, 0xffff0000);
        }
        func_021CC95C((u32 *)(p + 0x1d74), s, 9113);
    }
}















void func_021C3E0C(u8 *p, u8 *a, u8 *c)
{
    u8 *b;
    u32 x, y, ai, bi;
    u32 s, t;
    int line;
    Flag *f;
    b = func_021C3FAC(c, 0);
    x = func_021D59B4(a, 16);
    y = func_021D59B4(b, 16);
    if (x != y && !func_021C3FBC(x) && !func_021C3FCC(y)) {
        ai = func_021D5440(a);
        bi = func_021D5440(b);
        f = *(Flag * *)&((struct Obj03191 *)p)->f4A8;
        if (f->a == 0) f->a = 1;
        func_021CD4B0(((struct Obj03191 *)p)->fC, 0x4a, ai, bi, (u16)y, (u16)x);
        func_021CD64C(((struct Obj03191 *)p)->fC, 0x5b, 0x1fc, ai, 0xffff0000);
        line = 9140;
        s = func_021CC8D8(p + 0x1d74, line);
        func_021C7B3C(p, ai, x, y);
        func_021C7B3C(p, bi, y, x);
        func_021CC95C((u32 *)(p + 0x1d74), s, line + 3);
        func_021D66D0((struct QJ *)a, y);
        func_021D66D0((struct QJ *)b, x);
        func_021D8564((int)a, (int)b);
        func_021CD4B0(((struct Obj03191 *)p)->fC, 0x58, ai);
        func_021CD4B0(((struct Obj03191 *)p)->fC, 0x58, bi);
        if (x != y) {
            t = func_021CC8D8(p + 0x1d74, line + 16);
            func_021C7B7C(p, ai);
            func_021C7B7C(p, bi);
            line += 19;
            func_021CC95C((u32 *)(p + 0x1d74), t, line);
        }
        if (func_021D62C4((struct Unk021D62A8 *)a, 16) == 0) {
            if (x == 0x67) func_021C195C(p, a, 0);
            if (x == 0x7f) func_021C3FDC(p, a);
        }
        if (func_021D62C4((struct Unk021D62A8 *)b, 16) == 0) {
            if (y == 0x67) func_021C195C(p, b, 0);
            if (y == 0x7f) func_021C3FDC(p, b);
        }
    } else {
        func_021CD64C(((struct Obj03191 *)p)->fC, 0x5a, 0x47, 0xffff0000);
    }
}
















void func_021C3FDC(u8 *p, u8 *a)
{
    u32 it;
    u8 *cur;
    int k = func_021D5440(a);
    func_021BD2B4((u8 *)&it, (u8 **)p);
    while (func_021BD34C((u8 *)&it, (u8 **)p, &cur)) {
        if (func_021B9A24(k, func_021D5440(cur)) == 0)
            func_021C195C(p, cur, 0);
    }
}
















int func_021C4034(u8 *p, u8 *a)
{
    int n;
    int r;
    if (func_021D6D7C(a) == 0) {
        n = func_021D7B74(a, 4);
        if (func_021D59B4(a, 0xd) > n) {
            r = func_021C40F4(p + 0x1ab8, func_021D5440(a));
            if (r != 6) {
                func_021C5B74(p, a, -n, 1);
                func_021C195C(p, a, 1);
                func_021D6D5C(a, n);
                func_021CD4B0(((struct Obj00003 *)p)->fC, 0x27, func_021D5440(a), (u16)n);
                func_021CD4B0(((struct Obj00003 *)p)->fC, 0x51, r);
                func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x311, func_021D5440(a), 0xffff0000);
                return 1;
            }
        }
        func_021C5DAC(p, 0x7b, 0, 0);
    } else {
        func_021C5D88(p, a, 0x314);
    }
    return 0;
}















/*
 * Opens with `push {r0-r3}`: the address of parameters 3-6 is taken; the
 * fifth and sixth parameters are one 8-byte struct passed by value.
 */
u16 func_021C4104(u8 *p, u32 q, u8 *c, u16 d, S_021C4104 s, u16 *e)
{
    u16 ev = *e;
    u8 sa = s.a;
    int m = func_021D5440(c);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x54, m, sa, ev);
    func_021C5D88(p, c, 0x317);
    func_021C5840(p, 1, (int *)(&s), &c, 0);
    func_021C59C4(p, 1, &c, &s.b, 0);
    if (func_021D6D9C(c, &d))
        func_021C41C0(p, c);
    func_021C1DCC(p, (u8 *)e, q, c, d);
    func_021C1880(p, (u8 *)e, (u8 *)q, c, d, 1);
    func_021C4218(p, (u8 *)q, c, (u8 *)e, s.a, d, s.b, 1);
    return d;
}















void func_021C41C0(u8 *p, u8 *a)
{
    int i = func_021D5440(a);
    int r = func_021C4208(p + 0x1ab8, i);
    func_021C5D88(p, a, 0x31a);
    func_021D6D70(a);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x28, i);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x52, r);
}














void func_021C4218(u8 *p, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3)
{
    u32 s = func_021CC8D8(p + 0x1D74, 9310);
    func_021C4268(p, a, b, c, s0, s1, s2, s3);
    func_021CC95C((u32 *)(p + 0x1D74), s, 9313);
}















void func_021C4268(u8 *p, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3)
{
    u8 x = func_021D5440(b);
    func_021D74F8(9335);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, x);
    func_021D75EC(0x14, ((struct Obj07754 *)c)->f2);
    func_021D75EC(0x12, ((struct Obj07754 *)c)->f0);
    func_021D75EC(0x38, s0);
    func_021D75EC(0x16, c[6]);
    func_021D75EC(0x1a, ((struct Obj07754 *)c)->f8);
    func_021D75EC(0x32, s1);
    func_021D75EC(0x45, s2);
    func_021D75EC(0x46, s3);
    func_021D7630(0x47, 0);
    func_021D70F0(p, 0x4a);
    func_021D70F0(p, 0x4b);
    func_021D70F0(p, 0x4c);
    func_021D7540(9352);
}















int func_021C4304(u8 *p, u16 *b, u8 *a, u8 *c, int *out)
{
    u8 n1;
    u8 n2;
    u8 i;
    func_021D74F8(9370);
    func_021D75EC(3, func_021D5440(a));
    n1 = func_021C43C0(c);
    n2 = func_021C43D0(c);
    func_021D75EC(5, n2);
    func_021D7630(0x51, 1);
    for (i = 0; i < n2; i++) {
        func_021D75EC(i + 6, func_021D5440(func_021C43E0(c, i)));
    }
    func_021D75EC(0x12, *b);
    if (n1 != 0) {
        if (n2 != 0) {
            func_021D70F0(p, 0xa0);
        }
    } else {
        func_021D70F0(p, 0xa1);
    }
    *out = func_021D775C(0x51);
    func_021D7540(9402);
    if (func_021C88E4(p) != 0) {
        return 1;
    }
    return 0;
}












void func_021C43F0(u8 *p, u8 *a)
{
    u32 it;
    u8 *x;
    func_021C443C(a);
    func_021BD2B4((u8 *)&it, (u8 **)p);
    while (func_021BD34C((u8 *)&it, (u8 **)p, &x)) {
        func_021C444C(a, x);
    }
    func_021C445C(a, p);
}










int func_021C446C(u8 *p)
{
    u8 *a;
    u8 *q;
    int result = 0;
    a = *(u8 **)(p + 0x854);
    if (p[0x77e] == 0) {
        func_021C43F0(p, a);
        p[0x77e] = 1;
        func_021C4744(p);
    }
    switch (p[0x77e]) {
    case 0: break;
    case 1:
        p[0x77e]++;
        func_021CD4B0(*(void **)(p + 12), 0x56, 0);
        result = 0;
        if (func_021C4D1C(p, a)) { result = 1; break; }
        if (func_021BC2B0(p)) return 0;
    case 2:
        p[0x77e]++;
        if (func_021C4838(p, a, (u8 *)0x76)) { result = 1; break; }
        if (func_021BC2B0(p)) return 0;
    case 3:
        p[0x77e]++;
        if (func_021C493C(p, a)) { result = 1; break; }
        if (func_021BC2B0(p)) return 0;
    case 4:
        p[0x77e]++;
        func_021C4B8C(p);
        func_021C4C24(p);
    case 5:
        p[0x77e]++;
        if (func_021C4838(p, a, (u8 *)0x77)) { result = 1; break; }
        if (func_021BC2B0(p)) return 0;
    case 6:
        func_021C4838(p, a, (u8 *)0x78);
        p[0x77e]++;
        func_021C45E4(a);
        q = func_021C45F4(a);
        while (q) {
            func_021D6408(q);
            func_021D6E88(q);
            func_021CD4B0(*(void **)(p + 12), 0x2e, func_021D5440(q));
            q = func_021C4604(a);
        }
        func_021C4614(p);
        func_021D701C();
        if (*(u32 *)(p + 16) < 9999) (*(u32 *)(p + 16))++;
        p[0x77e] = 0;
        *(u32 *)(p + 0x774) = 0;
        return 0;
    default: break;
    }
    return result;
}









void func_021C4614(u8 *p)
{
    u32 first, a, b;
    char *x, *y;
    u8 *m, *n;
    u32 mi, ni, s, t;
    u8 v, w;
    if (func_021B8588(((struct Obj00003 *)p)->f4) != 2) return;
    a = func_021B8FF4(*(u8 * *)&((struct Obj00003 *)p)->f4);
    first = a;
    b = (u8)func_021B9064(((struct Obj00003 *)p)->f4, a, 0);
    if (a > b) { first = b; b = a; }
    x = func_021B9AEC(*(char * *)&((struct Obj00003 *)p)->f8, first);
    y = func_021B9AEC(*(char * *)&((struct Obj00003 *)p)->f8, b);
    if (func_021B9B98((u8 *)x) != 1) return;
    if (func_021B9B98((u8 *)y) != 1) return;
    m = func_021B9CE8((u8 *)x);
    n = func_021B9CE8((u8 *)y);
    mi = func_021D5440(m);
    ni = func_021D5440(n);
    s = func_021C4724(p + 0x1ab8, mi);
    t = func_021C4734(p + 0x1ab8, ni);
    if (s == 6 || t == 6) return;
    v = func_021B8DEC(((struct Obj00003 *)p)->f4, s);
    w = func_021B8DEC(((struct Obj00003 *)p)->f4, t);
    if (v != w) return;
    if (func_021B99F0(s) != 0) return;
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x50, first, v, b, w);
    func_021BD43C(p, first, v, 1, 1);
    func_021BD43C(p, b, w, 1, 1);
    func_021BD4E4(p, first, v, 1);
    func_021BD4E4(p, b, w, 1);
}









/*
 * Verified with one --thumb without region, dsi/1.1p1 -O4,p:
 * typedef unsigned int u32;
 * typedef struct { u32 a[8]; } Block;
 * typedef struct { u32 mode, old, other; Block current, previous; } State;
 * 0x0202E7E0 EXACT: u32 func_0202E7E0(State *p) { return p->mode; }
 * 0x0202E7E4 EXACT: void func_0202E7E4(State *p) {
 *     p->old = p->mode; p->previous = p->current; p->mode = 3;
 * }
 * lever: a u64 draw and a separate u32 slot preserve the high-product register.
 * note 2026-10-05 (D8 lane16): witnesses func_0202E7E0 and func_0202E7E4 filed as src/matched/arm9/func_0202E7E0.c and func_0202E7E4.c (both EXACT); this file becomes EXACT once the integrator seeds them.
 */
void func_021C4744(u8 *p)
{
    u8 list[4];
    u8 i, n;
    void *work;
    u32 mode, side;
    u8 *desc, *m;
    u32 value, slot;
    u64 draw;
    u8 id;
    int live;
    work = (void *)func_021B8630(*(void **)(p + 4));
    if (work == 0) return;
    mode = func_0202E7E0(work);
    if (mode == 0 || mode == 3) return;
    side = func_021B8FF4(*(u8 **)(p + 4));
    desc = func_021BB85C(*(void **)p, (int)side);
    i = 0;
    n = 0;
    for (; i < desc[9]; i++) {
        m = func_021B990C(*(void **)(p + 8), side, (u8)i);
        if (m != 0) {
            if (func_021D5B68(m) == 0) live = 1;
            else live = 0;
        } else live = 0;
        if (live) {
            if (func_021D5B48(m) == 0) list[n++] = func_021D5440(m);
        }
    }
    if (n == 0) return;
    draw = func_0203F0A8();
    slot = (u32)draw;
    if (n != 0) slot = (u32)((draw * (u32)n) >> 32);
    id = list[slot];
    m = func_021B9934(*(char **)(p + 8), id);
    value = (u32)func_021D59B4(m, 14);
    if (mode == 1) value >>= 1;
    if (value == 0) return;
    if (func_021C334C(p, m, (u16)value, (u32)0)) {
        func_021CD64C(*(void **)(p + 12), (u32)0x5a, 0x53, 4, id, 0xffff0000);
        func_0202E7E4(work);
    }
}










int func_021C4838(u8 *p, u8 *a, u8 *b)
{
    u32 s;
    u8 *q;
    func_021C48E0(a);
    s = func_021CC8D8(p + 0x1D74, 9644);
    func_021C4910(p, 0x1f, (int)b);
    func_021CC95C((u32 *)(p + 0x1D74), s, 9646);
    if (func_021BC2B0(p) == 0) {
        q = func_021C48F0(a);
        if (q != 0) {
            do {
                s = func_021CC8D8(p + 0x1D74, 9652);
                func_021C4910(p, func_021D5440(q), (int)b);
                func_021CC95C((u32 *)(p + 0x1D74), s, 9654);
                func_021C4F64(p, q);
                if (func_021BC2B0(p) != 0) {
                    break;
                }
                q = func_021C4900(a);
            } while (q != 0);
        }
    }
    return func_021C5200(p);
}








void func_021C4910(u8 *p, u32 a, int k)
{
    func_021D74F8(9667);
    func_021D75EC(2, a);
    func_021D70F0(p, k);
    func_021D7540(9670);
}








/*
 * lever: the first out-value is a one-word struct passed by value.
 */
int func_021C493C(u8 *p, u8 *a)
{
    u8 list[6];
    Word_021C4910 y;
    u32 x;
    u32 i, n, k, s;
    u8 *q, *m;
    list[0] = 0;
    list[1] = 0;
    list[2] = 0;
    list[3] = 0;
    list[4] = 3;
    list[5] = 0;
    i = 0;
    n = func_021C4A24(a);
    for (; i < n; i++) list[i] = func_021D5440(func_021C4A34(a, i));
    k = 0;
    for (;;) {
        q = func_021C4A44(k++);
        if (q == 0) break;
        for (i = 0; i < n; i++) {
            m = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, list[i]);
            if (func_021D5B68(m) == 0) {
                if (func_021D6064(m, (u32)q, (union Slot *)(&y), (int *)(&x))) {
                    s = func_021CC8D8(p + 0x1d74, 9719);
                    func_021C4A54(m, q, y, x, p);
                    func_021CC95C((u32 *)(p + 0x1d74), s, 9721);
                }
            }
        }
        if (func_021BC2B0(p)) break;
    }
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x15, (u8)n, (u8)k, func_021D806C(list));
    return func_021C5200(p);
}






void func_021C4A64(u8 *p, u8 *a, u32 b, u32 c)
{
    u32 lock;
    int r;
    lock = func_021CC8D8(p + 0x1d74, 0x261b);
    r = func_021C4B3C(p, a, b, c);
    if (r && func_021C20BC(p, a, r)) {
        switch (b) {
        case 0: case 1: case 2: case 3: break;
        case 5: func_021C5480(p, a, 0x257); break;
        case 4: func_021C5480(p, a, 0x258); break;
        case 6: case 7: case 8: break;
        case 10: func_021C5480(p, a, 0x273); break;
        case 9: func_021C5480(p, a, 0x274); break;
        }
        func_021C8810(p + 0x1ae4);
        func_021C4B2C(p + 0x1ae4, a, b);
        func_021C20D0(p, a, r, p + 0x1ae4);
    }
    func_021CC95C((u32 *)(p + 0x1d74), lock, 0x263b);
}








int func_021C4B3C(u8 *p, u8 *a, u32 b, u32 c)
{
    int r;
    func_021D74F8(9801);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x1d, b);
    func_021D75A8(0x32, c);
    func_021D70F0(p, 0x6b);
    r = func_021D775C(0x32);
    func_021D7540(9807);
    return r;
}









/*
 * C tail call through r3 into the ov095 walker func_06898D54 (ov095 is
 * loaded in VRAM at 0x0689xxxx), with the ov093 callback func_021C4B9C.
 * Earlier notes called this a linker thunk; it is plain mwcc C.
 * 2026-10-05 (D9r lane16): every byte right; MATCH only because the ABS32
 * to func_021C4B9C needs that file's manifest shard (filed EXACT this wave).
 * Re-run after the shard lands; expected EXACT, then move to src/matched/ov.
 */
void func_021C4B8C(u8 *p)
{
    func_06898D54((void (*)(u8,  u32,  u32))func_021C4B9C, (u32)p);
}









void func_021C4B9C(int v, int k, u8 *p)
{
    func_021C4BAC(p, k, v);
}









void func_021C4BAC(u8 *p, int k, int v)
{
    int r = -1;
    switch (k) {
    case 0: r = 0x7e; break;
    case 1: r = 0x82; break;
    case 2: r = 0x86; break;
    case 3: r = 0x8a; break;
    case 4: r = 0x8e; break;
    case 5: r = 0x92; break;
    case 6: r = 0x96; break;
    case 7: r = 0x9a; break;
    case 8: r = 0x9e; break;
    case 9: break;
    case 10: break;
    case 11: r = 0xa6; break;
    case 12: r = 0xaa; break;
    case 13: r = 0xae; break;
    }
    if (r >= 0) {
        func_021CD64C(((struct Obj21095 *)p)->fC, 0x5a, r, v, 0xffff0000);
    }
}








/*
 * The extent continues into the existing SDK CallbackForJpeg at 021C4C40.
 * DWC_StartUtilityEx takes two full-word payloads; the original passes
 * the callback address and p unchanged in r0/r1.
 */
void func_021C4C24(u8 *p)
{
    func_021EF934((int)func_021C4C40, (int)p);
    func_021CD4B0(((struct Obj21096 *)p)->fC, 47, 0);
}








void CallbackForJpeg(int result, void *arg)
{
    func_021C4C50(arg, result);
}








void func_021C4C50(u8 *p, int k)
{
    int r = -1;
    u8 *q;
    switch (k) {
    case 0: break;
    case 1: r = 0x74; break;
    case 2: r = 0x76; break;
    case 3: break;
    case 4: break;
    case 5: break;
    case 6: r = 0xb3; break;
    case 7: r = 0xb5; break;
    }
    if (r >= 0) {
        func_021CD64C(((struct Obj05192 *)p)->fC, 0x5a, r, 0xffff0000);
    }
    func_021CD4B0(((struct Obj05192 *)p)->fC, 0x24, (u8)k);
    if (k == 7) {
        func_021C43F0(p, *(u8 * *)&((struct Obj05192 *)p)->f868);
        func_021C4CEC(*(u8 * *)&((struct Obj05192 *)p)->f868);
        q = func_021C4CFC(*(u8 * *)&((struct Obj05192 *)p)->f868);
        while (q) {
            if (func_021D5B7C(q)) {
                func_021C195C(p, q, 0);
            }
            q = func_021C4D0C(*(u8 * *)&((struct Obj05192 *)p)->f868);
        }
    }
}




int func_021C4D1C(u8 *p, void *it)
{
    int r;
    int changed;
    int mode;
    u8 *a;
    u32 lock;
    int line;
    r = func_021EF8B8();
    if (r) {
        func_021CD4B0(((struct Obj00003 *)p)->fC, 0x40, r);
        func_021C3BE0(p, 0);
        return 0;
    }
    changed = 0;
    mode = func_021C2AB0(p);
    func_021C4E08(it);
    a = func_021C4E18(it);
    if (a) {
        line = 0x26c6;
        line += 12;
        do {
            if (!func_021D5B68(a) && !func_021D5BDC((struct UtilWork *)a, 5) && !func_021D5BDC((struct UtilWork *)a, 4)) {
                lock = func_021CC8D8(p + 0x1d74, 0x26c6);
                r = func_021C4E38(p, a, mode, func_021D7BD4(a, mode));
                if (r) {
                    func_021C4EA4(p, a, mode, r);
                    changed = 1;
                }
                func_021CC95C((u32 *)(p + 0x1d74), lock, line);
                func_021C4F64(p, a);
            }
            a = func_021C4E28(it);
        } while (a);
    }
    if (changed) func_021C70E4(p, 0x255, 6, 6, 0, 0);
    return func_021C5200(p);
}





int func_021C4E38(u8 *p, u8 *a, u32 b, u32 c)
{
    u8 f;
    int r;
    int s;
    func_021D74F8(9960);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x39, b);
    r = 0;
    func_021D7630(0x41, 0);
    func_021D75A8(0x32, c);
    func_021D70F0(p, 0x7f);
    s = func_021D775C(0x32);
    f = func_021D775C(0x41);
    func_021D7540(9969);
    if (f == 0) {
        r = s;
    }
    return r;
}






void func_021C4EA4(u8 *p, u8 *a, int k, int n)
{
    u8 x = func_021D5440(a);
    switch (k) {
    case 4:
        func_021C8838(p + 0x1AE4, 2, 396);
        func_021C8860((struct S *)(p + 0x1AE4), x);
        break;
    case 3:
        func_021C8838(p + 0x1AE4, 2, 399);
        func_021C8860((struct S *)(p + 0x1AE4), x);
        break;
    default:
        func_021C8810(p + 0x1AE4);
        break;
    }
    if (n > 0 && func_021C20BC(p, a, n) != 0) {
        func_021C99A0(p, (const struct Msg *)(p + 0x1AE4));
        func_021C8810(p + 0x1AE4);
        func_021C70E4(p, 0x290, func_021C8010(p, x), 6, 0, 0);
        if ((int)func_021D59B4(a, 0xd) <= n) {
            func_021C70E4(p, 0x255, 6, 6, 0, 0);
        }
        func_021C20D0(p, a, n, 0);
    }
}





/*
 * note: 2026-10-05 recoup: `ok = 0;` written after the call to func_021C5108 (it is
 * only read by the later compare), not before it; this puts the zero store in r2 as in the
 * original. EXACT in c99 and c. Callees: func_021D59B4 and func_021BA1A8 return int,
 * func_021B8DDC (unlabelled in ov093 matched set) returns u8, func_021C5108 and
 * func_021B92B0 are void with three arguments.
 */
int func_021C4F64(u8 *p, u8 *a)
{
    u8 k = func_021D5440(a);
    u8 *flags = p + 0x7a9;
    int ok;
    int side;
    int health;
    if (!flags[k] && func_021D5B68(a)) {
    flags[k] = 1;
    func_021C5078(p + 0x3e0, k);
    if (!(func_021BA1A8(*(void **)(p + 4), 0x200) && func_021B8DDC(k) != 0) && p[0x789] != k)
        func_021CD64C(*(void **)(p + 12), 0x5b, 0, k, 0xffff0000);
    func_021CD4B0(*(void **)(p + 12), 0x39, k);
    func_021C5108(p, a, 0);
    ok = 0;
    func_021D646C(a);
    side = func_021B8DDC(k);
    if (side == func_021B8FF4(*(u8 **)(p + 4))) {
        health = func_021D59B4(a, 15);
        if (health + 30 <= (int)func_021C5098(p)) ok = 1;
        func_021B92B0((char *)(*(u8 **)(p + 4)), a, ok);
    }
    func_021C5088(p + 0x1ab8, k);
    side = func_021B8DDC(k);
    {
        int current = func_021B8FF4(*(u8 **)(p + 4));
        if (side == current) {
            func_021BA1B4((char **)(*(u8 **)(p + 4)), 0x4c);
        } else if (!func_021B902C(side, current)) {
            func_021BA1B4((char **)(*(u8 **)(p + 4)), 0x19);
            func_021BA1B4((char **)(*(u8 **)(p + 4)), 0x52);
        }
    }
    return 1;
    }
    return 0;
}



u32 func_021C5098(u8 *p)
{
    u32 best = 1;
    u32 n = func_021B8640((unsigned int **)(*(u8 * *)&((struct Obj07755 *)p)->f4));
    u8 x = func_021B8FF4(*(u8 * *)&((struct Obj07755 *)p)->f4);
    u32 i;
    for (i = 0; i <= n; i++) {
        if (func_021B902C(x, func_021B8DE4((char *)(*(u8 * *)&((struct Obj07755 *)p)->f4), (u8)i)) == 0) {
            int r = func_021C50F8(p + 0x1AB8, i);
            if (r != 0x1f) {
                u32 t = func_021D59B4((u8 *)func_021B9934(*(char * *)&((struct Obj07755 *)p)->f8, r), 0xf);
                if (t > best) {
                    best = t;
                }
            }
        }
    }
    return best;
}



/*
 * extent: 198 compiled bytes followed by two zero padding bytes at 021C51CE.
 */
void func_021C5108(u8 *p, u8 *a, int b)
{
    u32 it;
    u8 *cur;
    int k = func_021D5440(a);
    func_021C51D0(p, a);
    func_021BFF60(p, a, 0);
    if (b == 0) {
        func_021D8510(a);
        func_021DCF24(a);
    } else {
        func_021D8538(a);
        func_021DCFA4(a);
    }
    func_021E0434(a);
    func_021BD2B4((u8 *)&it, (u8 **)p);
    func_021BD338((u8 *)&it, p);
    while (func_021BD34C((u8 *)&it, (u8 **)p, &cur)) {
        func_021D6264((struct UtilSlots *)cur, k);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 0x2c, func_021D5440(cur), k);
    }
    func_021EF90C(k);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x23, k);
    if (!func_021BC2B0(p) && (u16)func_021D59B4(a, 0x11) == 0x7f)
        func_021C3FDC(p, a);
}



void func_021C51D0(u8 *p, u8 *a)
{
    int line = 0x27DF;
    func_021D74F8(line);
    func_021D75A8(2, func_021D5440(a));
    func_021D70F0(p, 0xA3);
    func_021D7540(line + 3);
}


int func_021C5200(u8 *p)
{
    int result = 0;
    u32 i;
    u32 count;
    u8 *a;
    if (func_021B85EC(((struct Obj00003 *)p)->f4)) {
        count = func_021C52C8(p + 0x3e0, 0);
        for (i = 0; i < count; i++) {
            if (!func_021C52D8(p + 0x3e0, 0, i)) {
                a = func_021B9934((char *)(*(u8 * *)&((struct Obj00003 *)p)->f8), func_021C52E8(p + 0x3e0, 0, i));
                if (!func_021B86B8(((struct Obj00003 *)p)->f4) && !((struct Flags_021C5108 *)(p + 0x78a))->b && func_021BC2B0(p) && func_021BC310(p)) {
                    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x55, func_021B86DC(((struct Obj00003 *)p)->f4));
                    ((struct Flags_021C5108 *)(p + 0x78a))->b = 1;
                }
                if (func_021C5308(p, a)) result = 1;
                func_021C52F8(p + 0x3e0, 0, i);
            }
        }
    }
    return result;
}
