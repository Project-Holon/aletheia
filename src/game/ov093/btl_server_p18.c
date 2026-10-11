/*
 * file:     btl_server_p18.c
 * unit:     yes
 * function: func_021C95D0, func_021C962C, func_021C96D4, func_021C9728, func_021C9750, func_021C9778, func_021C97A4, func_021C97D0, func_021C9828, func_021C9898, func_021C98C4, func_021C98E4, func_021C99A0, func_021C9A24, func_021C9A60, func_021C9BB8, func_021C9CC0, func_021C9DCC, func_021C9DE8, func_021C9E3C, func_021C9ECC, func_021C9F0C, func_021C9F4C, func_021C9F6C, func_021CA128, func_021CA158, func_021CA1D0, func_021CA248, func_021CA270, func_021CA2E8, func_021CA318, func_021CA370, func_021CA394, func_021CA3AC, func_021CA3D0, func_021CA47C, func_021CA570, func_021CA5CC, func_021CA6C4, func_021CA6FC, func_021CA738, func_021CA748, func_021CA7C4, func_021CA7D4, func_021CA7F4, func_021CA8F8, func_021CAA24
 * address:  0x021C95D0
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
 *   func_021C961C  0x021C961C  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021C2314  0x021C2314  thumb  ov093
 *   func_021C96B4  0x021C96B4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021C96C4  0x021C96C4  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021D66B0  0x021D66B0  thumb  ov093
 *   func_021E8DA8  0x021E8DA8  thumb  ov093
 *   func_021E8CFC  0x021E8CFC  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 *   func_021C5A1C  0x021C5A1C  thumb  ov093
 *   func_021C5A34  0x021C5A34  thumb  ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021D6440 0x021D6440 thumb ov093
 *   func_021C60EC 0x021C60EC thumb ov093
 *   func_021C6110 0x021C6110 thumb ov093
 *   func_021C7BA8  0x021C7BA8  thumb  ov093
 *   func_021C9818  0x021C9818  thumb  ov093
 *   func_021C9888  0x021C9888  thumb  ov093
 *   func_021C4BAC  0x021C4BAC  thumb  ov093
 *   func_021C3C60 0x021C3C60 thumb ov093
 *   func_021EF8E8 0x021EF8E8 thumb ov093
 *   func_021C4C50 0x021C4C50 thumb ov093
 *   func_021C3B8C  0x021C3B8C  thumb  ov093
 *   func_021C3BB8  0x021C3BB8  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021C7BF8  0x021C7BF8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021C5DAC  0x021C5DAC  thumb  ov093
 *   func_021C5EFC  0x021C5EFC  thumb  ov093
 *   func_021C5E48  0x021C5E48  thumb  ov093
 *   func_021C5F98  0x021C5F98  thumb  ov093
 *   func_021C9A50 0x021C9A50 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021C9BA8 0x021C9BA8 thumb ov093
 *   func_021C7B3C 0x021C7B3C thumb ov093
 *   func_021C7B7C 0x021C7B7C thumb ov093
 *   func_021D8510 0x021D8510 thumb ov093
 *   func_021D66D0 0x021D66D0 thumb ov093
 *   func_021D8484 0x021D8484 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021C195C 0x021C195C thumb ov093
 *   func_021C3FDC 0x021C3FDC thumb ov093
 *   func_021C7A54 0x021C7A54 thumb ov093
 *   func_021C7AA0 0x021C7AA0 thumb ov093
 *   func_021C2250 0x021C2250 thumb ov093
 *   func_021D6738 0x021D6738 thumb ov093
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021D5B48  0x021D5B48  thumb  ov093
 *   func_021C2128  0x021C2128  thumb  ov093
 *   func_021DCF78  0x021DCF78  thumb  ov093
 *   func_021DCF9C  0x021DCF9C  thumb  ov093
 *   func_021CD4FC  0x021CD4FC  thumb  ov093
 *   func_021CD568  0x021CD568  thumb  ov093
 *   func_021C6E00  0x021C6E00  thumb  ov093
 *   func_021C88E4  0x021C88E4  thumb  ov093
 *   func_021C60D4  0x021C60D4  thumb  ov093
 *   func_021D5734  0x021D5734  thumb  ov093
 *   func_021C0780 0x021C0780 thumb ov093
 *   func_021C64B4 0x021C64B4 thumb ov093
 *   func_021CA0B8 0x021CA0B8 thumb ov093
 *   func_021CA0C8 0x021CA0C8 thumb ov093
 *   func_021CA0D8 0x021CA0D8 thumb ov093
 *   func_021CA0E8 0x021CA0E8 thumb ov093
 *   func_021CA0F8 0x021CA0F8 thumb ov093
 *   func_021CA108 0x021CA108 thumb ov093
 *   func_021C5718 0x021C5718 thumb ov093
 *   func_021BF83C 0x021BF83C thumb ov093
 *   func_021BF3D8 0x021BF3D8 thumb ov093
 *   func_021BF4AC 0x021BF4AC thumb ov093
 *   func_021BF8D4 0x021BF8D4 thumb ov093
 *   func_021CA118 0x021CA118 thumb ov093
 *   func_021BD1E0 0x021BD1E0 thumb ov093
 *   func_021BD200 0x021BD200 thumb ov093
 *   func_021C091C 0x021C091C thumb ov093
 *   func_021BD60C 0x021BD60C thumb ov093
 *   func_021BC2B0  0x021BC2B0  thumb  ov093
 *   func_021C8374  0x021C8374  thumb  ov093
 *   func_021BDD00  0x021BDD00  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021BB930  0x021BB930  thumb  ov093
 *   func_021C2CA8  0x021C2CA8  thumb  ov093
 *   func_021D65C8  0x021D65C8  thumb  ov093
 *   func_021D6D7C  0x021D6D7C  thumb  ov093
 *   func_021CA238  0x021CA238  thumb  ov093
 *   func_021C1D60 0x021C1D60 thumb ov093
 *   func_021D5FA4  0x021D5FA4  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B8DEC  0x021B8DEC  thumb  ov093
 *   func_021BD9D4  0x021BD9D4  thumb  ov093
 *   func_021BDA00  0x021BDA00  thumb  ov093
 *   func_021D67D8 0x021D67D8 thumb ov093
 *   func_021C3810  0x021C3810  thumb  ov093
 *   func_021BD148 0x021BD148 thumb ov093
 *   func_021BD170 0x021BD170 thumb ov093
 *   func_021BD1B0 0x021BD1B0 thumb ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9C98  0x021B9C98  thumb  ov093
 *   func_021BD43C  0x021BD43C  thumb  ov093
 *   func_021BD4E4  0x021BD4E4  thumb  ov093
 *   func_021D6C24 0x021D6C24 thumb ov093
 *   func_021D5C30 0x021D5C30 thumb ov093
 *   func_021D6C50 0x021D6C50 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021E0434 0x021E0434 thumb ov093
 *   func_021CA5BC  0x021CA5BC  thumb  ov093
 *   func_021D6C2C  0x021D6C2C  thumb  ov093
 *   func_021C7F68 0x021C7F68 thumb ov093
 *   func_021D5BDC 0x021D5BDC thumb ov093
 *   func_021C5418 0x021C5418 thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 *   func_0203EFC8 0x0203EFC8 arm
 *   func_021C6F34 0x021C6F34 thumb ov093
 *   func_021C5620 0x021C5620 thumb ov093
 *   func_021C70E4 0x021C70E4 thumb ov093
 *   func_021D6D54  0x021D6D54  thumb  ov093
 *   func_021D66D8  0x021D66D8  thumb  ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021CB214 0x021CB214 thumb ov093
 *   func_021CA8C8 0x021CA8C8 thumb ov093
 *   func_021CAA58 0x021CAA58 thumb ov093
 *   func_021CACF4 0x021CACF4 thumb ov093
 *   func_021CA8D8 0x021CA8D8 thumb ov093
 *   func_021CA8E8 0x021CA8E8 thumb ov093
 *   func_021CAFD8 0x021CAFD8 thumb ov093
 *   func_021CB174 0x021CB174 thumb ov093
 *   func_021CA9D4 0x021CA9D4 thumb ov093
 *   func_021CA9E4 0x021CA9E4 thumb ov093
 *   func_021CA9F4 0x021CA9F4 thumb ov093
 *   func_021CAA04 0x021CAA04 thumb ov093
 *   func_021CAA14 0x021CAA14 thumb ov093
 *   func_021D80BC 0x021D80BC thumb ov093
 */
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj09973.h"
#include "../../matched/include/Obj05194.h"
#include "../../matched/include/Obj21127.h"
#include "../../matched/include/Obj18348.h"
#include "../../matched/include/Obj09976.h"
#include "../../matched/include/Obj09977.h"
#include "../../matched/include/Obj13344.h"

struct Msg;
struct QF;
struct UtilWork;
struct Unk021D62A8;
struct QJ;
struct QI;
struct Out64B4;
struct Unk021BD1E0;
struct Unk021BD200;
struct Work;
struct Unk021D5FA4;
struct R4;
struct Unk021D6C50;
struct Unk021D6C2C;
struct Slot;
struct R5;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 w; u8 b4; u8 b5; } Ent_021C95D0;

typedef struct { u32 w; u16 h4; u8 b6; u8 b7; } Ent_021C962C;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Cmd_021C96D4 {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 10;
    u32 flag : 1;
};

struct Cmd_021C97D0 {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u32 w4;
    u32 w8;
    u8 b12;
};

typedef struct { int x; } S;

struct Cmd_021C98E4 {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 3;
    u32 pad2 : 7;
    u32 flag : 1;
    u32 pad3 : 8;
    u8 b4;
    u8 b5;
    u8 b6;
};

struct Msg {
    u16 a;
    u16 kind : 8;
    u16 n : 7;
    u16 flag : 1;
    u8 data[0x1C];
    u32 w20;
};

struct Cmd_021C9A24 { u32 a:8; u32 id:5; u32 pad:19; u32 w4; u8 b8; u8 pad9[3]; u8 data[16]; u8 b28; };

typedef struct { u32 low:8,index:5,pad:10,flag:1,high:8; u16 value; u8 id,a; u8 pad8[4]; u8 msg[36]; } Ent;

typedef struct { u32 low:8,index:5,pad:10,flag:1,high:8; u16 value; u8 id,a,b,c; u8 padA[2]; u8 msg[36]; } Ent_021C9BB8;

typedef struct { u32 low:8,index:5,pad:10,flag:1,high:8; u8 id,pad5[3]; u8 msg[108]; } Ent_021C9CC0;

struct Cmd_021C9DE8 {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u32 f0 : 1;
    u32 f1 : 1;
};

struct Cmd_021C9E3C {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u8 b4;
    u8 b5;
    u16 h6;
};

struct Cmd_021C9ECC {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u32 w4;
};

struct Cmd_021C9F0C {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u16 h8;
};

struct Out { u16 h0,h2,h4; u8 b6,pad7; u32 w8,wc,w10; };

struct State { u16 h0; u8 b2,b3,b4; u8 flag:1; u8 rest:7; };

struct Bits { u32 low : 8; u32 index : 5; u32 high : 19; };

struct Cmd_021CA158 {
    u8 pad[0x4C];
    u8 b4c;
    u8 b4d;
};

struct Cmd_021CA1D0 {
    u32 pad;
    u8 b4;
    u8 b5;
};

struct Cmd_021CA248 {
    u32 pad;
    u8 b4;
    u8 b5;
    u16 h6;
};

struct Q_021C95D0 {
    u32 a : 8;
    u32 b : 5;
    u32 c : 19;
    u16 e;
    u8 f;
    u8 lo : 4;
    u8 hi : 4;
};

struct Cmd_021CA2E8 { u32 a:8; u32 id:5; u32 b:10; u32 flag:1; u32 c:8; u8 target; };

struct Cmd { u32 a:8; u32 id:5; u32 b:19; };

struct Q_021CA5CC {
    u32 lo : 23;
    u32 f : 1;
    u32 hi : 8;
    u8 pad4[0];
};

typedef struct {
    u8 unk0[0x4A8];
    u8 *state;          /* 0x4A8 */
} BattleCtx_021CA7C4;

typedef struct {
    u8 unk0[5];
    u8 flag : 1;
    u8 unk5 : 7;
} BattleState;

typedef struct {
    u8 unk0[0x4A8];
    BattleState *state; /* 0x4A8 */
} BattleCtx_021CA7D4;

struct Flags { u32 a:1; u32 b:31; };

extern int func_021C961C(int a, u8 b);
extern u8 *func_021B9934(char *p, int i);
extern int func_021D5B68(void *p);
extern int func_021C2314(u8 *p, u8 *a);
extern int func_021C96B4(int a, u8 b);
extern u16 func_021D5444(struct QF *p);
extern int func_021C96C4(int a);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021D66B0(u8 *p, int n);
extern int func_021E8DA8(int a);
extern u8 func_021E8CFC(int v);
extern void func_021CD64C(void *w, u8 id, ...);
extern void func_021C5A1C(u8 *p, u8 *a);
extern void func_021C5A34(u8 *p, u8 *a);
extern void func_021D5FC0(struct UtilWork *, u32);
extern void func_021D6440(u8 *p, u32 n);
extern void func_021C60EC(u8 *, u8 *, u32);
extern void func_021C6110(u8 *, u8 *, u32);
extern void func_021C7BA8(u8 *p, u8 a, u32 b, u32 c, u32 *out);
extern int func_021C9818(u32 b, u32 a, u32 v);
extern int func_021C9888(u32 a, u32 i);
extern void func_021C4BAC(u8 *p, int k, int v);
extern int func_021C3C60(u8 *, int, S, int);
extern int func_021EF8E8(int);
extern void func_021C4C50(u8 *, int);
extern int func_021C3B8C(void *w, u32 a, u32 b);
extern void func_021C3BB8(u8 *p, u32 a, u32 b);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021C7BF8(u8 *p);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021C5DAC(u8 *p, u32 a, int n, const int *v);
extern void func_021C5EFC(u8 *p, u32 a, int n, const int *v);
extern void func_021C5E48(u8 *p, u32 a, u32 b, int n, int *v);
extern void func_021C5F98(u8 *p, u32 a, u32 b, int n, int *v);
extern int func_021C9A50(u32, u8, u8, const void *, u8);
extern int func_021D59B4(u8 *p, int k);
extern int func_021C9BA8(u16);
extern void func_021C7B3C(u8 *p, u32 a, u16 b, u16 c);
extern void func_021C7B7C(u8 *p, unsigned int i);
extern void func_021D8510(void *p);
extern void func_021D66D0(struct QJ *p, u32 v);
extern void *func_021D8484(void *);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021C195C(u8 *p, u8 *q, u32 n);
extern void func_021C3FDC(u8 *, u8 *);
extern int func_021C7A54(u8 *, u8 *, u32);
extern void func_021C7AA0(u8 *, u8 *);
extern void func_021C2250(u8 *p, u8 *a, u16 b, u32 c);
extern void func_021D6738(u8 *);
extern u16 func_021D5B40(struct QI *p);
extern int func_021D5B48(u8 *p);
extern int func_021C2128(u8 *p, u8 *a);
extern void *func_021DCF78(void *p, unsigned int k);
extern void func_021DCF9C(void *n);
extern int func_021CD4FC(void *p, int k);
extern void func_021CD568(void *p, int a, int k, u32 b);
extern void func_021C6E00(u8 *p, u8 *a, u8 k);
extern int func_021C88E4(u8 *p);
extern void func_021C60D4(u8 *p, u8 *a);
extern void func_021D5734(u8 *p, u8 i, u16 a, u8 b, u32 c);
extern void func_021C0780(u8 *, u8 *, int, u8);
extern void func_021C64B4(u8 *p, u16 q, u8 *a, struct Out64B4 *out);
extern void func_021CA0B8(void *);
extern void func_021CA0C8(void *);
extern void func_021CA0D8(void *, u8 *);
extern void func_021CA0E8(void *, int);
extern void func_021CA0F8(void *);
extern int func_021CA108(void *);
extern void func_021C5718(u8 *, u8 *, u32);
extern void func_021BF83C(u8 *, u16 *, u8 *, int);
extern void func_021BF3D8(u8 *, int, u8 *, int, void *);
extern void func_021BF4AC(u8 *, u8 *, u8 *, void *, void *);
extern void func_021BF8D4(u8 *, u16 *, u8 *, int);
extern int func_021CA118(void *);
extern void func_021BD1E0(struct Unk021BD1E0 *p);
extern void func_021BD200(struct Unk021BD200 *p, u8 *q, u8 *a, int t);
extern void func_021C091C(u8 *, u8 *, u8 *, u8 *, u32, u32);
extern int func_021BD60C(u8 *, u8 *, u8);
extern int func_021BC2B0(u8 *p);
extern int func_021C8374(u8 *p, int i);
extern int func_021BDD00(u8 *p, u8 *a, int c);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern void func_021BB930(u8 *p, u32 value);
extern void func_021C2CA8(u8 *p, u8 *a);
extern void func_021D65C8(struct Work *p, struct Work *q);
extern u32 func_021D6D7C(u8 *p);
extern int func_021CA238(void *p, u8 i);
extern int func_021C1D60(u8 *, u8 *, u32);
extern void func_021D5FA4(struct Unk021D5FA4 *p, u16 n);
extern u8 func_021B8DDC(u32 x);
extern int func_021B8DEC(void *p, int s);
extern void func_021BD9D4(void *w, int a, int b, int c, int d);
extern int func_021BDA00(u8 *p);
extern void func_021D67D8(u8 *, u32);
extern int func_021C3810(u8 *p, u8 *a, u8 *b, int force, int *out, u16 move, int ignore, const struct Msg *msg);
extern int func_021BD148(void *, u8);
extern int func_021BD170(u8 *, u8 *);
extern int func_021BD1B0(void *, u8);
extern char *func_021B9AEC(char *p, int i);
extern int func_021B9C98(u8 *p, u32 v);
extern void func_021BD43C(u8 *p, int i, u8 a, u8 b, int c);
extern void func_021BD4E4(u8 *p, int i, u8 a, u8 b);
extern int func_021D6C24(struct R4 *p);
extern int func_021D5C30(struct UtilWork *p);
extern int func_021D6C50(struct Unk021D6C50 *a, struct Unk021D6C50 *b);
extern u8 func_021D5440(u8 *p);
extern void func_021E0434(u8 *);
extern int func_021CA5BC(u8 *p, int k);
extern void func_021D6C2C(struct Unk021D6C2C *p);
extern u8 func_021C7F68(int *p, int b, u8 *out);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern int func_021C5418(u8 *, u8 *, int);
extern u8 func_021D69AC(u8 *, int);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern int func_021C6F34(u8 *, u8 *, int);
extern void func_021C5620(u8 *p, u8 *a, int k, struct Slot *out);
extern void func_021C70E4(u8 *, int, int, int, int, u32);
extern int func_021D6D54(struct R5 *p);
extern void func_021D66D8(void *m, int v);
extern u32 func_021B8588(void **p);
extern u8 func_021CB214(u8 *p, u8 *a, u8 *b);
extern void func_021CA8C8(void *);
extern int func_021CAA58(u8 *p, u8 *a, u16 move, u8 *q, int id, void *out);
extern int func_021CACF4(u8 *p, u8 *a, u16 move, u8 *q, long id, void *out);
extern u8 *func_021CA8D8(void *, int);
extern u8 func_021CA8E8(void *, u8);
extern int func_021CAFD8(u8 *, u32, u8 *, const u8 *, u16, void *);
extern void *func_021CB174(u8 *p, unsigned int n, int k);
extern void func_021CA9D4(void *, void *);
extern void func_021CA9E4(void *, void *);
extern void func_021CA9F4(void *, void *);
extern void func_021CAA04(void *, void *);
extern void func_021CAA14(void *, void *);
extern int func_021D80BC(void *, int, int, u16);
int func_021C95D0(int p, const Ent_021C95D0 *e);
int func_021C962C(int p, const Ent_021C962C *e);
int func_021C96D4(char *w, struct Cmd_021C96D4 *c);
int func_021C9728(u8 *p, u8 *q);
int func_021C9750(u8 *p, u8 *q);
int func_021C9778(u8 *p, u8 *q);
int func_021C97A4(u8 *p, u8 *q);
int func_021C97D0(void *w, const struct Cmd_021C97D0 *c);
int func_021C9828(void *w, u8 *s);
int func_021C9898(u8 *p, u8 *q);
int func_021C98C4(u8 *p, u8 *q);
u8 func_021C98E4(u8 *w, struct Cmd_021C98E4 *c);
int func_021C99A0(void *w, const struct Msg *m);
u8 func_021C9A24(void *p, const struct Cmd_021C9A24 *q);
int func_021C9A60(u8 *p, const Ent *e);
int func_021C9BB8(u8 *p, const Ent_021C9BB8 *e);
int func_021C9CC0(u8 *p, const Ent_021C9CC0 *e);
int func_021C9DCC(u8 *p, u8 *q);
int func_021C9DE8(u8 *w, struct Cmd_021C9DE8 *c);
int func_021C9E3C(u8 *w, struct Cmd_021C9E3C *c);
int func_021C9ECC(u8 *w, struct Cmd_021C9ECC *c);
int func_021C9F0C(u8 *w, const struct Cmd_021C9F0C *c);
int func_021C9F4C(u8 *p, u8 *q);
u8 func_021C9F6C(u8 *p, u8 *q);
int func_021CA128(u8 *p, struct Bits *q);
int func_021CA158(u8 *w, struct Cmd_021CA158 *c);
int func_021CA1D0(u8 *w, const struct Cmd_021CA1D0 *c);
u8 func_021CA248(u8 *p, const u8 *q);
int func_021CA270(u8 *w, const struct Cmd_021CA248 *c);
int func_021CA2E8(u8 *p, const u8 *q);
u8 func_021CA318(u8 *p, const struct Q_021C95D0 *q);
int func_021CA370(u8 *p, const u8 *q);
u8 func_021CA394(u8 *p, const u8 *q);
int func_021CA3AC(u8 *p, const u8 *q);
int func_021CA3D0(u8 *p, u8 *q);
int func_021CA47C(u8 *p, struct Cmd_021CA2E8 *q);
int func_021CA570(u8 *p, u8 *q);
int func_021CA5CC(const u8 *p, const struct Cmd *q);
int func_021CA6C4(u8 *p, const u8 *q);
int func_021CA6FC(u8 *p, const u8 *q);
int func_021CA738(u8 *p);
int func_021CA748(u8 *p, const struct Q_021CA5CC *q);
u8 func_021CA7C4(BattleCtx_021CA7C4 *s, u8 *cmd);
u8 func_021CA7D4(BattleCtx_021CA7D4 *s, void *cmd);
int func_021CA7F4(u8 *p, u8 *a, u16 b, const u8 *q, void *out);
int func_021CA8F8(u8 *p, u8 *a, int unused, u8 *q, int id, void *out);
int func_021CAA24(u8 *p, u8 *q, int m, int n, int value);












int func_021C95D0(int p, const Ent_021C95D0 *e)
{
    int a;

    if (func_021C961C(p + 0x1ab8, e->b4)) {
        a = (int)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, e->b4);
        if (func_021D5B68((void *)a) == 0 || e->b5) {
            func_021C99A0((void *)p, (void *)((u8 *)e + 8));
            func_021C2314((u8 *)p, (u8 *)a);
            return 1;
        }
    }
    return 0;
}












int func_021C962C(int p, const Ent_021C962C *e)
{
    int a;

    if (func_021C96B4(p + 0x1ab8, e->b6)) {
        a = (int)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, e->b6);
        if (func_021D5B68((void *)a) == 0 && func_021C96C4(func_021D5444((void *)a)) == 0) {
            func_021CD4B0(((struct Obj00003 *)p)->fC, 0x16, e->b6, e->h4);
            func_021D66B0((void *)a, e->h4);
            if (e->b7 == 0 && func_021E8DA8(e->h4))
                func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x380, e->b6, func_021E8CFC(e->h4), 0xffff0000);
            return 1;
        }
    }
    return 0;
}













int func_021C96D4(char *w, struct Cmd_021C96D4 *c)
{
    u8 *r = 0;
    int id = c->id;
    if (id != 0x1F) {
        r = func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, (u8)id);
    }
    if (c->flag && r) func_021C5A1C((u8 *)w, r);
    func_021C99A0(w, (const struct Msg *)((u8 *)c + 4));
    if (c->flag && r) func_021C5A34((u8 *)w, r);
    return 1;
}













/*
 * extent: two bytes of trailing alignment padding.
 */
int func_021C9728(u8 *p, u8 *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[8]);
    if (!func_021D5B68(a)) {
        func_021D5FC0((struct UtilWork *)a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}













int func_021C9750(u8 *p, u8 *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[8]);
    if (!func_021D5B68(a)) {
        func_021D6440(a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}













int func_021C9778(u8 *p, u8 *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[8]);
    if (!func_021D5B68(a)) {
        func_021C60EC(p, a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}













int func_021C97A4(u8 *p, u8 *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[8]);
    if (!func_021D5B68(a)) {
        func_021C6110(p, a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}












int func_021C97D0(void *w, const struct Cmd_021C97D0 *c)
{
    u32 v;
    void *pv;
    v = c->w8;
    pv = &v;
    func_021C7BA8(w, c->id, c->w4, c->b12, pv);
    if (func_021C9818(c->b12, c->w4, ((struct Obj09973 *)pv)->f0) != 0) {
        func_021C99A0(w, (const struct Msg *)((u8 *)c + 0x10));
        return 1;
    }
    return 0;
}










static inline int test(u8 *s, u32 i)
{
    u8 idx = (i >> 3) + 1;
    u8 bit = i & 7;
    if (idx < s[4]) {
        if ((1 << bit) & s[4 + idx]) return 1;
        else return 0;
    }
    return 0;
}










int func_021C9828(void *w, u8 *s)
{
    int r = 0;
    u32 i;
    for (i = 0; i < 14; i++) {
        if (test(s, i) && func_021C9888(s[7], i)) {
            func_021C4BAC(w, i, s[7]);
            r = 1;
        }
    }
    return r;
}









/*
 * extent: two bytes of trailing alignment padding.
 */
int func_021C9898(u8 *p, u8 *q)
{
    if (func_021C3C60(p, *(int *)(q + 4), *(S *)(q + 8), q[12])) {
        func_021C99A0(p, (const struct Msg *)(q + 16));
        return 1;
    }
    return 0;
}










int func_021C98C4(u8 *p, u8 *q)
{
    if (func_021EF8E8(*(int *)(q + 4))) {
        func_021C4C50(p, *(int *)(q + 4));
        return 1;
    }
    return 0;
}











u8 func_021C98E4(u8 *w, struct Cmd_021C98E4 *c)
{
    u8 *id = func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, (u8)c->id);
    int r = 0;
    u32 s;
    if (c->b4 != 0) {
        if (func_021C3B8C(w, c->b4, c->b5) != 0) {
            if (c->flag) func_021C5A1C(w, id);
            func_021C3BB8(w, c->b4, c->b5);
            func_021C99A0(w, (const struct Msg *)((u8 *)c + 8));
            r = 1;
            if (c->flag) func_021C5A34(w, id);
        }
    } else if (c->b6 != 0) {
        if (c->flag) func_021C5A1C(w, id);
        func_021C99A0(w, (const struct Msg *)((u8 *)c + 8));
        s = func_021CC8D8(w + 0x1D74, 15467);
        func_021C7BF8(w);
        func_021CC95C((u32 *)(w + 0x1D74), s, 15469);
        r = 1;
        if (c->flag) func_021C5A34(w, id);
    }
    return r;
}











int func_021C99A0(void *w, const struct Msg *m)
{
    if (!m->flag) {
        switch (m->kind) {
        case 1:
            func_021C5DAC(w, m->a, m->n, (const int *)m->data);
            return 1;
        case 2:
            func_021C5EFC(w, m->a, m->n, (const int *)m->data);
            return 1;
        }
    } else {
        u16 x = m->w20;
        switch (m->kind) {
        case 1:
            func_021C5E48(w, m->a, x, m->n, (int *)m->data);
            return 1;
        case 2:
            func_021C5F98(w, m->a, x, m->n, (int *)m->data);
            return 1;
        }
    }
    return 0;
}










/*
 * lever: const source pointer hoists the id load before the outgoing
 * stack-argument store; mutable source gave 16 scheduling bytes different.
 */
u8 func_021C9A24(void *p, const struct Cmd_021C9A24 *q)
{
    int r;
    if (func_021C9A50(q->w4, q->b8, q->id, q->data, q->b28)) r = 1;
    else r = 0;
    return r;
}







int func_021C9A60(u8 *p, const Ent *e)
{
    u8 *a;
    u16 x;
    int line;
    u32 s;
    u32 t;
    a = func_021B9934(((struct Obj00003 *)p)->f8, e->id);
    x = func_021D59B4(a, 16);
    if (func_021C9BA8(x)) return 0;
    if (func_021D5B68(a)) return 0;
    if (e->a || e->value != x) {
        if (e->flag) func_021CD4B0(((struct Obj00003 *)p)->fC, 87, (u8)e->index);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 73, e->id, e->value);
        func_021C99A0(p, (const struct Msg *)e->msg);
        line = 15561;
        s = func_021CC8D8(p + 0x1d74, line);
        func_021C7B3C(p, e->id, x, e->value);
        func_021CC95C((u32 *)(p + 0x1d74), s, line + 2);
        func_021D8510(a);
        func_021D66D0((struct QJ *)a, e->value);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 29, e->id, e->value);
        func_021D8484(a);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 88, e->id);
        if (x != e->value) {
            t = func_021CC8D8(p + 0x1d74, line + 16);
            func_021C7B7C(p, e->id);
            line += 18;
            func_021CC95C((u32 *)(p + 0x1d74), t, line);
        }
        if (e->flag) func_021CD4B0(((struct Obj00003 *)p)->fC, 88, (u8)e->index);
        if (!func_021D62C4((struct Unk021D62A8 *)a, 16)) {
            if (x == 103) func_021C195C(p, a, 0);
            if (x == 127) func_021C3FDC(p, a);
        }
        return 1;
    }
    return 0;
}










int func_021C9BB8(u8 *p, const Ent_021C9BB8 *e)
{
    u8 *a;
    int line;
    u32 s;
    u8 f;
    u32 t;
    a = func_021B9934(((struct Obj00003 *)p)->f8, e->id);
    if (e->index != e->id) {
        line = 15615;
        s = func_021CC8D8(p + 0x1d74, line);
        f = func_021C7A54(p, a, e->value);
        func_021CC95C((u32 *)(p + 0x1d74), s, line + 2);
        if (f) {
            t = func_021CC8D8(p + 0x1d74, line + 6);
            func_021C7AA0(p, a);
            func_021CC95C((u32 *)(p + 0x1d74), t, line + 8);
            return 0;
        }
    }
    if (e->flag) func_021CD4B0(((struct Obj00003 *)p)->fC, 87, (u8)e->index);
    func_021C99A0(p, (const struct Msg *)e->msg);
    func_021C2250(p, a, e->value, 0);
    if (e->flag) func_021CD4B0(((struct Obj00003 *)p)->fC, 88, (u8)e->index);
    if (e->a) {
        func_021D6738(a);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 43, e->id);
    }
    if (e->b) {
        func_021D6738(func_021B9934(((struct Obj00003 *)p)->f8, e->c));
        func_021CD4B0(((struct Obj00003 *)p)->fC, 43, e->c);
    }
    func_021C195C(p, a, 0);
    return 1;
}











/*
 * lever: truncated accessor results live in u32 locals; u16 locals rotate seven spill offsets.
 */
int func_021C9CC0(u8 *p, const Ent_021C9CC0 *e)
{
    u8 *a;
    u8 *b;
    u16 x;
    u16 y;
    u32 s;
    u8 f;
    u32 t;
    a = func_021B9934(((struct Obj00003 *)p)->f8, (u8)e->id);
    b = func_021B9934(((struct Obj00003 *)p)->f8, (u8)e->index);
    x = (u16)(int)func_021D5B40((struct QI *)b);
    y = (u16)(int)func_021D5B40((struct QI *)a);
    s = func_021CC8D8(p + 0x1d74, 15671);
    f = func_021C7A54(p, a, x);
    func_021CC95C((u32 *)(p + 0x1d74), s, 15673);
    if (f) {
        t = func_021CC8D8(p + 0x1d74, 15676);
        func_021C7AA0(p, a);
        func_021CC95C((u32 *)(p + 0x1d74), t, 15678);
        return 0;
    }
    if (e->flag) func_021C5A1C(p, b);
    func_021C99A0(p, (const struct Msg *)e->msg);
    func_021C99A0(p, (const struct Msg *)(e->msg + 36));
    func_021C99A0(p, (const struct Msg *)(e->msg + 72));
    if (e->flag) func_021C5A34(p, b);
    func_021C2250(p, b, y, 0);
    func_021C2250(p, a, x, 0);
    func_021C195C(p, b, 0);
    func_021C195C(p, a, 0);
    return 1;
}











int func_021C9DCC(u8 *p, u8 *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[4]);
    func_021C195C(p, a, *(u32 *)(q + 8));
    return 1;
}











int func_021C9DE8(u8 *w, struct Cmd_021C9DE8 *c)
{
    u8 *r = func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, (u8)c->id);
    if (func_021D5B68(r) == 0 || c->f1) {
        if (c->f0 && func_021D5B48(r) != 0) return 0;
        if (func_021C2128(w, r) != 0) return 1;
    }
    return 0;
}











int func_021C9E3C(u8 *w, struct Cmd_021C9E3C *c)
{
    int r = (int)func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, c->b4);
    int x;
    int t;
    u32 s;
    if (func_021D5B68((void *)r) == 0) {
        x = (int)func_021DCF78((void *)r, c->h6);
        if (x != 0) {
            t = func_021CD4FC(((struct Obj00003 *)w)->fC, 0x42);
            s = func_021CC8D8(w + 0x1D74, 15755);
            func_021C6E00(w, (u8 *)r, c->id);
            if (func_021C88E4(w) == 2) {
                func_021CD568(((struct Obj00003 *)w)->fC, t, 0x42, c->b4);
            }
            func_021CC95C((u32 *)(w + 0x1D74), s, 15762);
            func_021DCF9C((void *)x);
            return 1;
        }
    }
    return 0;
}











int func_021C9ECC(u8 *w, struct Cmd_021C9ECC *c)
{
    u8 *r = func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, (u8)c->id);
    if (c->w4 == 0) {
        func_021C60D4(w, r);
        func_021C99A0(w, (const struct Msg *)((u8 *)c + 8));
    }
    func_021C2250(w, r, 0, 1);
    return 1;
}











int func_021C9F0C(u8 *w, const struct Cmd_021C9F0C *c)
{
    u8 *r = func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, c->b4);
    func_021CD4B0(((struct Obj00003 *)w)->fC, 0x1F, c->b4, c->b5, c->b6, c->b7, c->h8);
    func_021D5734(r, c->b5, c->h8, c->b6, c->b7);
    return 1;
}








int func_021C9F4C(u8 *p, u8 *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[4]);
    func_021C0780(p, a, q[5], q[6]);
    return 1;
}







u8 func_021C9F6C(u8 *p, u8 *q)
{
    u8 work[28];
    struct Out *out = (struct Out *)(work + 8);
    u16 *saved;
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[4]);
    u8 *b = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[5]);
    struct State *state;
    u32 flag;
    func_021C64B4(p, *(u16 *)(q + 6), a, (struct Out64B4 *)out);
    func_021CA0B8(((struct Obj00003 *)p)->f860);
    func_021CA0C8(((struct Obj00003 *)p)->f868);
    func_021CA0D8(((struct Obj00003 *)p)->f868, b);
    func_021CA0E8(((struct Obj00003 *)p)->f868, 1);
    func_021CA0F8(((struct Obj00003 *)p)->f868);
    if (func_021CA108(((struct Obj00003 *)p)->f868)) {
        func_021C5718(p, a, ((u16 *)work)[4]);
        return 0;
    }
    func_021BF83C(p, (u16 *)out, a, *(int *)&((struct Obj00003 *)p)->f868);
    func_021BF3D8(p, (int)out, a, *(int *)&((struct Obj00003 *)p)->f868, p + 0x1f88);
    func_021BF4AC(p, (u8 *)out, a, ((struct Obj00003 *)p)->f868, p + 0x1f88);
    func_021BF8D4(p, (u16 *)out, a, *(int *)&((struct Obj00003 *)p)->f868);
    if (func_021CA118(((struct Obj00003 *)p)->f868)) return 0;
    state = *(struct State * *)&((struct Obj00003 *)p)->f4A8;
    saved = (u16 *)work;
    saved[0] = ((struct Obj05194 *)state)->f0;
    saved[1] = ((struct Obj05194 *)state)->f2;
    saved[2] = ((struct Obj05194 *)state)->f4;
    func_021BD1E0((struct Unk021BD1E0 *)state);
    func_021BD200((struct Unk021BD200 *)(*(struct State * *)&((struct Obj00003 *)p)->f4A8), p, a, *(int *)&((struct Obj00003 *)p)->f868);
    (*(struct State * *)&((struct Obj00003 *)p)->f4A8)->b4 = 1;
    func_021C091C(p, (u8 *)out, a, *(u8 * *)&((struct Obj00003 *)p)->f868, (u32)(p + 0x1f88), 1);
    state = *(struct State * *)&((struct Obj00003 *)p)->f4A8;
    flag = state->flag;
    ((struct Obj05194 *)state)->f0 = saved[0];
    ((struct Obj05194 *)state)->f2 = saved[1];
    ((struct Obj05194 *)state)->f4 = saved[2];
    return flag;
}






int func_021CA128(u8 *p, struct Bits *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (u8)q->index);
    if (func_021BD60C(p, a, 1)) {
        ((struct Obj00003 *)p)->f14 = 5;
        return 1;
    }
    return 0;
}








int func_021CA158(u8 *w, struct Cmd_021CA158 *c)
{
    u8 *r = func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, c->b4c);
    if (func_021BC2B0(w) == 0 && func_021C8374(w, c->b4c) == 0 && ((struct Obj00003 *)w)->f14 == 0) {
        func_021C99A0(w, (const struct Msg *)((u8 *)c + 4));
        if (func_021BDD00(w, r, c->b4d) != 0) {
            func_021BB930(((struct Obj00003 *)w)->f0, func_021B8D8C(((struct Obj00003 *)w)->f4, ((struct Obj00003 *)w)->f8, c->b4c));
            func_021C99A0(w, (const struct Msg *)((u8 *)c + 0x28));
            ((struct Obj00003 *)w)->f14 = 1;
            return 1;
        }
    }
    return 0;
}








int func_021CA1D0(u8 *w, const struct Cmd_021CA1D0 *c)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, c->b4);
    u8 *b = func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, c->b5);
    if (func_021D62C4((struct Unk021D62A8 *)a, 0x10) != 0) func_021C2CA8(w, b);
    func_021D65C8((struct Work *)b, (struct Work *)a);
    func_021CD4B0(((struct Obj00003 *)w)->fC, 0x26, c->b4, c->b5);
    if (func_021D6D7C(b) != 0) {
        int r = func_021CA238(w + 0x1AB8, c->b5);
        func_021CD4B0(((struct Obj00003 *)w)->fC, 0x51, r);
    }
    return 1;
}






u8 func_021CA248(u8 *p, const u8 *q)
{
    u8 r;
    if (func_021C1D60(p, func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[4]), q[5])) r = 1;
    else r = 0;
    return r;
}







int func_021CA270(u8 *w, const struct Cmd_021CA248 *c)
{
    int s;
    int a;
    int b;
    func_021D5FA4((struct Unk021D5FA4 *)func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, c->b4), c->h6);
    func_021CD4B0(((struct Obj00003 *)w)->fC, 2, c->b4, c->h6);
    *(u8 *)(w + c->b4 + 0x7A9) = 0;
    func_021C99A0(w, (const struct Msg *)((u8 *)c + 8));
    s = func_021B8D8C(((struct Obj00003 *)w)->f4, ((struct Obj00003 *)w)->f8, c->b4);
    if (s != 6) {
        a = func_021B8DDC(c->b4);
        b = func_021B8DEC(((struct Obj00003 *)w)->f4, s);
        func_021BD9D4(w, a, b, b, 1);
        func_021BDA00(w);
    }
    return 1;
}






/*
 * extent: two zero bytes at 021CA316 are alignment padding.
 */
int func_021CA2E8(u8 *p, const u8 *q)
{
    func_021D67D8(func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[4]), *(const u16 *)(q + 6));
    func_021CD4B0(((struct Obj00003 *)p)->fC, 20, q[4], *(const u16 *)(q + 6));
    func_021C99A0(p, (const struct Msg *)(q + 8));
    return 1;
}







u8 func_021CA318(u8 *p, const struct Q_021C95D0 *q)
{
    int out[1];
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q->f);
    u8 *b = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (u8)q->b);
    if (func_021C3810(p, b, a, q->lo, out, q->e, q->hi, (const struct Msg *)((u8 *)q + 8))) return 1;
    return 0;
}






/*
 * extent: two zero bytes at 021CA392 are alignment padding.
 */
int func_021CA370(u8 *p, const u8 *q)
{
    if (func_021BD148(p, q[4])) {
        func_021C99A0(p, (const struct Msg *)(q + 8));
        return 1;
    }
    return 0;
}






/*
 * interface: r1 is the halfword loaded at 021CA396; cast preserves the
 * original payload while retaining the callee's pointer prototype.
 */
u8 func_021CA394(u8 *p, const u8 *q)
{
    u8 r;
    if (func_021BD170(p, (u8 *)(u32)*(const u16 *)&((struct Obj21127 *)q)->f4)) r = 1;
    else r = 0;
    return r;
}






/*
 * extent: two zero bytes at 021CA3CE are alignment padding.
 */
int func_021CA3AC(u8 *p, const u8 *q)
{
    if (func_021BD1B0(p, q[4])) {
        func_021C99A0(p, (const struct Msg *)(q + 8));
        return 1;
    }
    return 0;
}







int func_021CA3D0(u8 *p, u8 *q)
{
    int a, b;
    u8 *m1, *m2;
    char *o;
    s16 i, j;
    if (q[4] != q[5]) {
        a = func_021B8DDC(q[4]);
        b = func_021B8DDC(q[5]);
        if (a == b) {
            m1 = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[4]);
            m2 = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[5]);
            if (!func_021D5B68(m1) && !func_021D5B68(m2)) {
                o = func_021B9AEC(*(char * *)&((struct Obj00003 *)p)->f8, a);
                i = func_021B9C98((u8 *)o, (u32)m1);
                j = func_021B9C98((u8 *)o, (u32)m2);
                if (i >= 0 && j >= 0) {
                    func_021BD43C(p, a, i, j, 0);
                    func_021C99A0(p, (const struct Msg *)(q + 8));
                    func_021BD4E4(p, a, i, j);
                    return 1;
                }
            }
        }
    }
    return 0;
}






int func_021CA47C(u8 *p, struct Cmd_021CA2E8 *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (u8)q->id);
    u8 *b = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (u8)q->target);
    u16 k;
    int x, y;
    u32 lock;
    if (!func_021D6C24((struct R4 *)a) && !func_021D6C24((struct R4 *)b) && !func_021D5C30((struct UtilWork *)a)) {
        k = func_021D59B4(a, 16);
        if (func_021D6C50((struct Unk021D6C50 *)a, (struct Unk021D6C50 *)b)) {
            x = func_021D5440(a);
            y = func_021D5440(b);
            if (q->flag) func_021C5A1C(p, a);
            func_021E0434(a);
            func_021D8510(a);
            func_021D8484(a);
            func_021CD4B0(((struct Obj00003 *)p)->fC, 0x53, x, y);
            func_021C99A0(p, (const struct Msg *)((u8 *)q + 8));
            if (q->flag) func_021C5A34(p, a);
            if (k != func_021D59B4(a, 17)) {
                lock = func_021CC8D8(p + 0x1d74, 0x3f0a);
                func_021C7B7C(p, x);
                func_021CC95C((u32 *)(p + 0x1d74), lock, 0x3f0c);
            }
            return 1;
        }
    }
    return 0;
}







int func_021CA570(u8 *p, u8 *q)
{
    u8 *m;
    if (func_021CA5BC(p + 0x1AB8, q[4])) {
        m = func_021B9934(((struct Obj00003 *)p)->f8, q[4]);
        if (func_021D6C24((struct R4 *)m)) {
            func_021D6C2C((struct Unk021D6C2C *)m);
            func_021CD4B0(((struct Obj00003 *)p)->fC, 0x4b, q[4]);
            func_021C99A0(p, (const struct Msg *)(q + 8));
            return 1;
        }
    }
    return 0;
}





/*
 * lever: C7F68 returns its normalized u8 j, and u8 n restores the count reload.
 */
int func_021CA5CC(const u8 *p, const struct Cmd *q)
{
    u8 buf[8];
    u8 n;
    u8 i;
    u8 *a;
    int changed;
    u8 t;
    n = func_021C7F68((int *)p, (u16)(func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, (u8)q->id) | 0x800), buf);
    i = 0;
    if (i >= n) goto done;
loop:
    {
        a = (u8 *)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, buf[i]);
        changed = 0;
        if (func_021D5BDC((struct UtilWork *)a, 3)) {
            func_021C5418((u8 *)p, a, 3);
            t = func_021D69AC(a, 4);
            if (!(t && (t = (u8)(t - 1)) < 24)) t = 31;
            if (t != 31) func_0203EFC8(p, a, 1);
            changed = 1;
        }
        if (func_021C6F34((u8 *)p, a, 1)) changed = 1;
        if (func_021D62C4((struct Unk021D62A8 *)a, 30)) {
            func_021C5620((u8 *)p, a, 30, 0);
            changed = 1;
        }
        if (func_021D62C4((struct Unk021D62A8 *)a, 32)) {
            func_021C5620((u8 *)p, a, 32, 0);
            changed = 1;
        }
        if (changed) func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x43b, buf[i], 0xffff0000);
    }
    i++;
    if (i < n) goto loop;
done:
    return 1;
}





int func_021CA6C4(u8 *p, const u8 *q)
{
    u8 *m = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[4]);
    if (!func_021D5B68(m) && func_021C5418(p, m, *(const int *)(q + 8))) {
        func_021C99A0(p, (const struct Msg *)(q + 12));
        return 1;
    }
    return 0;
}





int func_021CA6FC(u8 *p, const u8 *q)
{
    if (q[11]) func_021CD4B0(((struct Obj00003 *)p)->fC, 86, 0);
    func_021C70E4(p, *(const u16 *)(q + 4), q[6], q[7], q[10], *(const u16 *)(q + 8));
    func_021C99A0(p, (const struct Msg *)(q + 12));
    return 1;
}






/* 021CA738  3-arg call on field 0xc, then returns 1 */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; ldr r0, [r0, #0xc]; movs r1, #0x56; movs r2, #0; bl func_021CD4B0; movs r0, #1; pop {r3, pc}.
 */
int func_021CA738(u8 *p)
{
    func_021CD4B0((void *)(((struct Obj18348 *)p)->fC), 0x56, 0);
    return 1;
}








/*
 * The listing extent (172 bytes) runs on into func_021CA7C4 and func_021CA7D4,
 * which are filed separately.
 */
int func_021CA748(u8 *p, const struct Q_021CA5CC *q)
{
    u8 t;
    void *m = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, ((u8 *)q)[4]);
    if (!func_021D5B68(m) && !func_021D6D54(m)) {
        t = func_021D59B4(m, 0x13);
        if (t != ((u8 *)q)[5]) {
            if (q->f) func_021C5A1C(p, m);
            func_021D66D8(m, ((u8 *)q)[5]);
            func_021CD4B0(((struct Obj00003 *)p)->fC, 0x4f, ((u8 *)q)[4], ((u8 *)q)[5]);
            func_021C99A0(p, (const struct Msg *)((u8 *)q + 8));
            if (q->f) func_021C5A34(p, m);
            return 1;
        }
    }
    return 0;
}









/* command handler: copy the argument byte of the command into the state block */
u8 func_021CA7C4(BattleCtx_021CA7C4 *s, u8 *cmd)
{
    s->state[4] = cmd[4];
    return 1;
}









/* command handler: latch the state flag once */
u8 func_021CA7D4(BattleCtx_021CA7D4 *s, void *cmd)
{
    BattleState *st = s->state;

    if (!st->flag)
        st->flag = 1;
    return 1;
}






int func_021CA7F4(u8 *p, u8 *a, u16 b, const u8 *q, void *out)
{
    u32 mode = func_021B8588(((struct Obj09976 *)p)->f4);
    u32 id = 31;
    if (!((struct Flags *)(q + 16))->a) id = func_021CB214(p, a, (u8 *)q);
    func_021CA8C8(out);
    p[0x77f] = 6;
    switch (mode) {
    case 0: default:
        id = func_021CA8F8(p, a, b, (u8 *)q, id, out);
        break;
    case 1:
        id = func_021CAA58(p, a, b, (u8 *)q, id, out);
        break;
    case 2:
        id = func_021CACF4(p, a, b, (u8 *)q, id, out);
        break;
    case 3:
        id = func_021CA8F8(p, a, b, (u8 *)q, id, out);
        break;
    }
    if (id == 1) {
        u8 *m = func_021CA8D8(out, 0);
        if (m) p[0x77f] = func_021CA8E8(p + 0x1ab8, func_021D5440(m));
        if (!func_021CAFD8(p, mode, a, q, b, out)) id = 0;
    }
    return id;
}


int func_021CA8F8(u8 *p, u8 *a, int unused, u8 *q, int id, void *out)
{
    int n = func_021B8D8C(*(void **)(p + 4), *(void **)(p + 8), func_021D5440(a));
    u8 *b;
    switch (*(u32 *)(q + 12)) {
    case 0: case 3: case 4: case 5: case 9:
        if (id == 31) b = func_021CB174(p, n, 0);
        else b = (u8 *)func_021B9934(*(char **)(p + 8), id);
        func_021CA9D4(out, b);
        return 1;
    case 1: case 7:
        if (id == 31) func_021CA9E4(out, a);
        else func_021CA9E4(out, (void *)func_021B9934(*(char **)(p + 8), id));
        return 1;
    case 8:
        func_021CA9F4(out, a);
        func_021CAA04(out, func_021CB174(p, n, 0));
        return 2;
    case 13:
        if (id != 31) {
            func_021CAA14(out, (void *)func_021B9934(*(char **)(p + 8), id));
            return 1;
        }
        return 0;
    case 2: case 6: case 10: case 11: case 12: default:
        return 0;
    }
}

int func_021CAA24(u8 *p, u8 *q, int m, int n, int value)
{
    if (((struct Obj09977 *)q)->f0 == 174) {
        if (((struct Obj09977 *)q)->fC == 0) {
            if (n == value || value == 6)
                return func_021D80BC(((struct Obj13344 *)p)->f4, ((struct Obj13344 *)p)->f8, m, 174);
        } else if (((struct Obj09977 *)q)->fC == 7 && n != value) {
            value = n;
        }
    }
    return value;
}
