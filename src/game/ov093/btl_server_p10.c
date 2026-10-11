/*
 * file:     btl_server_p10.c
 * unit:     yes
 * function: func_021C1184, func_021C1194, func_021C1198, func_021C11A4, func_021C11F0, func_021C14E0, func_021C15AC, func_021C15D4, func_021C15E8, func_021C1624, func_021C1678, func_021C16F8, func_021C1758, func_021C1788, func_021C17CC, func_021C1828, func_021C1880, func_021C18D4, func_021C1910, func_021C195C, func_021C199C, func_021C19D8, func_021C1A10, func_021C1A54, func_021C1B5C, func_021C1C88, func_021C1CCC, func_021C1CE4, func_021C1D60, func_021C1DCC, func_021C1E14, func_021C1E74, func_021C2048, func_021C20BC, func_021C20D0, func_021C2128, func_021C2204, func_021C2250, func_021C2314, func_021C232C, func_021C236C, func_021C2488, func_021C25A4, func_021C264C, func_021C26A8, func_021C26FC, func_021C2758, func_021C27A0, func_021C282C, func_021C2910, func_021C2AB0, func_021C2AF0, func_021C2B3C, func_021C2BA4, func_021C2BF0, func_021C2C50, func_021C2CA8, func_021C2CD8, func_021C2D10, func_021C2DC4
 * address:  0x021C1184
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
 *   func_021C0C34  0x021C0C34  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D6D7C  0x021D6D7C  thumb  ov093
 *   func_021D5FC0  0x021D5FC0  thumb  ov093
 *   func_021C14B0  0x021C14B0  thumb  ov093
 *   func_021C14C0  0x021C14C0  thumb  ov093
 *   func_021C14D0  0x021C14D0  thumb  ov093
 *   func_021C0C38  0x021C0C38  thumb  ov093
 *   func_021C0CB4  0x021C0CB4  thumb  ov093
 *   func_021C0CE8  0x021C0CE8  thumb  ov093
 *   func_021C0D70  0x021C0D70  thumb  ov093
 *   func_021C4104  0x021C4104  thumb  ov093
 *   func_021C4218  0x021C4218  thumb  ov093
 *   func_021C4F64  0x021C4F64  thumb  ov093
 *   func_021C5798  0x021C5798  thumb  ov093
 *   func_021C5840  0x021C5840  thumb  ov093
 *   func_021C59C4  0x021C59C4  thumb  ov093
 *   d_021F3B2C  0x021F3B2C  data  ov093  a4
 *   d_021F3B20  0x021F3B20  data  ov093  a4
 *   d_021F3B38  0x021F3B38  data  a4
 *   d_021F3B26  0x021F3B26  data  ov093  a4
 *   d_021F3B23  0x021F3B23  data  ov093  a4
 *   d_021F3B20b 0x021F3B20  data  ov093  a4
 *   func_021C156C  0x021C156C  thumb  ov093
 *   func_021C157C  0x021C157C  thumb  ov093
 *   func_021C6B5C  0x021C6B5C  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021C6BB8  0x021C6BB8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021C158C  0x021C158C  thumb  ov093
 *   func_021C159C  0x021C159C  thumb  ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D6848  0x021D6848  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   sub_0201C1BC   0x0201C1BC  thumb
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021C1B2C 0x021C1B2C thumb ov093
 *   func_021C1B3C 0x021C1B3C thumb ov093
 *   func_021C1B4C 0x021C1B4C thumb ov093
 *   func_021C1C48 0x021C1C48 thumb ov093
 *   func_021C1C58 0x021C1C58 thumb ov093
 *   func_021C1C68 0x021C1C68 thumb ov093
 *   func_021C1C78 0x021C1C78 thumb ov093
 *   func_021C7664 0x021C7664 thumb ov093
 *   func_021C1D30  0x021C1D30  thumb  ov093
 *   func_021C1D40  0x021C1D40  thumb  ov093
 *   func_021C1D50  0x021C1D50  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021C557C  0x021C557C  thumb  ov093
 *   func_021D5BB0  0x021D5BB0  thumb  ov093
 *   func_021C76F4  0x021C76F4  thumb  ov093
 *   func_021C7780  0x021C7780  thumb  ov093
 *   sub_0201BD28   0x0201BD28  thumb
 *   func_021D7B3C  0x021D7B3C  thumb  ov093
 *   func_021C5D88  0x021C5D88  thumb  ov093
 *   func_021C78F4  0x021C78F4  thumb  ov093
 *   func_021C3370  0x021C3370  thumb  ov093
 *   func_021C334C  0x021C334C  thumb  ov093
 *   func_0201C1E8 0x0201C1E8 thumb
 *   func_021D75A8 0x021D75A8 thumb ov093
 *   func_021D7674 0x021D7674 thumb ov093
 *   func_021C728C 0x021C728C thumb ov093
 *   func_021C7374 0x021C7374 thumb ov093
 *   func_021C7474 0x021C7474 thumb ov093
 *   func_021D7A44 0x021D7A44 thumb ov093
 *   func_021D7B10 0x021D7B10 thumb ov093
 *   func_021D7C38 0x021D7C38 thumb ov093
 *   func_021B911C 0x021B911C thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021C75EC 0x021C75EC thumb ov093
 *   func_021D7A6C 0x021D7A6C thumb ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021C6CAC  0x021C6CAC  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C7330 0x021C7330 thumb ov093
 *   func_021C5B74  0x021C5B74  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021C8810  0x021C8810  thumb  ov093
 *   func_021BC2B0  0x021BC2B0  thumb  ov093
 *   func_021C21F4 0x021C21F4 thumb ov093
 *   func_021CD4FC 0x021CD4FC thumb ov093
 *   func_021CC918 0x021CC918 thumb ov093
 *   func_021C6DD0 0x021C6DD0 thumb ov093
 *   func_021C88E4 0x021C88E4 thumb ov093
 *   func_021CD568 0x021CD568 thumb ov093
 *   func_021D805C 0x021D805C thumb ov093
 *   func_021D5B44  0x021D5B44  thumb  ov093
 *   func_021C7AD0  0x021C7AD0  thumb  ov093
 *   func_021C7B0C  0x021C7B0C  thumb  ov093
 *   func_021C60EC  0x021C60EC  thumb  ov093
 *   func_021C6134  0x021C6134  thumb  ov093
 *   func_021DCF24  0x021DCF24  thumb  ov093
 *   func_021DCF5C  0x021DCF5C  thumb  ov093
 *   func_021D6730  0x021D6730  thumb  ov093
 *   func_021C5BE4 0x021C5BE4 thumb ov093
 *   sub_0201BF58 0x0201BF58 thumb
 *   func_021D7C70 0x021D7C70 thumb ov093
 *   func_021C2564 0x021C2564 thumb ov093
 *   func_021C2574 0x021C2574 thumb ov093
 *   func_021C2584 0x021C2584 thumb ov093
 *   func_021C2594 0x021C2594 thumb ov093
 *   func_021C5718 0x021C5718 thumb ov093
 *   func_021C8828  0x021C8828  thumb  ov093
 *   func_021C5C74  0x021C5C74  thumb  ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D57FC 0x021D57FC thumb ov093
 *   func_021E8D24 0x021E8D24 thumb ov093
 *   func_021C5C1C 0x021C5C1C thumb ov093
 *   func_021C5480 0x021C5480 thumb ov093
 *   func_021C2AA0 0x021C2AA0 thumb ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_021D8510 0x021D8510 thumb ov093
 *   func_021D66D8 0x021D66D8 thumb ov093
 *   func_021D8484 0x021D8484 thumb ov093
 *   func_021D7D6C 0x021D7D6C thumb ov093
 *   func_021C3FDC 0x021C3FDC thumb ov093
 *   func_021EF884  0x021EF884  thumb  ov093
 *   func_021D70E4 0x021D70E4 thumb ov093
 *   func_021C2E64 0x021C2E64 thumb ov093
 *   func_021C2E1C  0x021C2E1C  thumb  ov093
 *   func_021C2E2C  0x021C2E2C  thumb  ov093
 *   func_021C2E3C  0x021C2E3C  thumb  ov093
 */
#include "../../matched/include/Obj21076.h"
#include "../../matched/include/Obj13320.h"
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj02778.h"
#include "../../matched/include/Obj21078.h"
#include "../../matched/include/Obj09968.h"
#include "../../matched/include/Obj13323.h"
#include "../../matched/include/Obj13324.h"
#include "../../matched/include/Obj13325.h"
#include "../../matched/include/Obj21079.h"
#include "../../matched/include/Obj09967.h"
#include "../../matched/include/Obj21082.h"
#include "../../matched/include/Obj21083.h"
#include "../../matched/include/Obj21084.h"
#include "../../matched/include/Obj21085.h"

struct Q;
struct UtilWork;
struct QI;
struct Unk021D62A8;
struct S;
struct Msg;
struct QK;
struct QF;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Fl { u32 f : 1; };

typedef struct { u16 v; u16 idx:5, b:4, pad:4, c:1, pad2:1, flag:1; } Rec;

typedef struct { u8 pad0[2]; u8 n; u8 pad3[1]; Rec r[1]; } List;

struct St { u8 pad[5]; u8 f : 1; };

struct Rec { u16 a; u16 b; u8 c; u8 d; u8 e; };

typedef struct { u32 a:10,b:9,c:9,d:1,e:1,f:1,g:1; } Lock;

typedef struct { u16 v; } W;

typedef struct { u32 v; } Word;

typedef struct { u8 pad[5]; u8 f:1; } BF_021C1184;

typedef struct { u8 pad[0x78a]; u8 low:4; u8 f:1; } State;

struct Slot { u32 a : 3; u32 rest : 29; };

struct Unk021D62A8 { u8 pad[0x1c]; struct Slot e[6]; };

struct Msg { u16 a; u16 kind:8; u16 n:7; u16 flag:1; u8 data[0x1c]; u32 w20; };

typedef struct { u8 pad[5]; u8 f : 1; } BF_021C2AB0;

extern u32 func_021C0C34(u8 *d);
extern u8 func_021D5440(u8 *p);
extern u32 func_021D6D7C(u8 *p);
extern void func_021D5FC0(struct UtilWork *p, u32 n);
extern u8 func_021C14B0(void *p, int n);
extern void func_021C14C0(void *w, u8 *c, int h, int f);
extern void func_021C14D0(void *w, u8 *c, int d, int f);
extern int func_021C0C38(u8 *p, const List *l, u32 *o0, u16 *o1, u32 *o2, u8 *o3);
extern int func_021C0CB4(u8 *p, const struct Q *q, u32 *out);
extern int func_021C0CE8(u8 *p, const struct Q *q, u32 *o1, u16 *o2, u32 *o3, u8 *o4, u8 *o5);
extern u32 func_021C0D70(const u8 *q);
extern int func_021C4104(u8 *p, u8 *q, u8 *c, u16 d, int sa, u8 sb, u16 *e);
extern void func_021C4218(u8 *p, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3);
extern int func_021C4F64(u8 *p, u8 *a);
extern void func_021C5798(u8 *p, u16 *a, u32 n, int *arr, u8 **ptrs, u16 *vals, u8 *unused1, int unused2);
extern void func_021C5840(u8 *p, u32 count, int *v, u8 **a, int flag);
extern void func_021C59C4(u8 *p, u32 n, u8 **a, u8 *b, int flag);
extern void func_021C156C(u8 *c);
extern u8 *func_021C157C(u8 *c);
extern int func_021C6B5C(u8 *p, u8 *a, u8 *b, u8 *q);
extern u32 func_021CC8D8(void *, int);
extern void func_021C6BB8(u8 *p, u8 *a, u8 *r);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021C158C(u8 *c, u8 *r);
extern u8 *func_021C159C(u8 *c);
extern void func_021CD64C(void *, u8, ...);
extern int func_021D59B4(u8 *p, int k);
extern void func_021D74F8(int line);
extern void func_021D75EC(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int line);
extern void func_021D7630(int key, u32 val);
extern int func_021D775C(int key);
extern void func_021D6848(u8 *c, struct Rec *r);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern u32 sub_0201C1BC(u16 move);
extern u16 func_021D5B40(struct QI *p);
extern void func_021C1B2C(u8 *);
extern u8 *func_021C1B3C(u8 *);
extern u8 *func_021C1B4C(u8 *);
extern u32 func_021C1C48(u8 *);
extern u8 *func_021C1C58(u8 *, u32);
extern int func_021C1C68(u8 *, u8 *, u32 *);
extern int func_021C1C78(u8 *, u8 *, u32 *);
extern int func_021C7664(u8 *, u32, u8 *);
extern void func_021C1D30(u8 *w);
extern u8 *func_021C1D40(u8 *w);
extern u8 *func_021C1D50(u8 *w);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern void func_021C557C(u8 *p, u8 *a, int k, int flag);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern int func_021C76F4(u8 *p, u8 *q, u32 n);
extern void func_021C7780(u8 *p, u8 *q);
extern u32 sub_0201BD28(u16 id, u32 field);
extern u32 func_021D7B3C(u32 a, u32 b);
extern void func_021C5D88(u8 *p, u8 *a, int b);
extern u16 func_021C78F4(u8 *p, u8 *a, u8 *b, u32 s);
extern int func_021C3370(u8 *p, void *q);
extern int func_021C334C(u8 *p, u8 *q, int a, int b);
extern int func_0201C1E8(int a);
extern void func_021D75A8(int, u32);
extern void func_021D7674(int, u32, u32, u32);
extern u16 func_021C728C(u8 *, u8 *, u8 *, u8 *);
extern u16 func_021C7374(u8 *p, u8 *a, u8 *b, u8 *c, int flag);
extern u16 func_021C7474(u8 *p, u8 *a, u8 *b, u8 *c, u32 flag);
extern u32 func_021D7A44(u32 a, u32 b, u32 c, u32 d);
extern u32 func_021D7B10(u32, u32);
extern u32 func_021D7C38(int a, int b);
extern int func_021B911C(void *, int);
extern u32 func_021D78AC(u32);
extern int func_021C75EC(u8 *, u8 *, int);
extern u32 func_021D7A6C(u32, u32);
extern int func_021D5B68(void *p);
extern int func_021C6CAC(u8 *p, u8 *a, u32 b, u32 c, int *out);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *l, u32 v);
extern int func_021C7330(u8 *, u8 *);
extern void func_021C5B74(u8 *p, u8 *a, int c, int k);
extern int func_021C99A0(void *w, const struct Msg *m);
extern void func_021C8810(u8 *l);
extern int func_021BC2B0(u8 *p);
extern int func_021C21F4(void *, u32);
extern u32 func_021CD4FC(u8 *, u32);
extern u32 func_021CC918(void *, u16, int);
extern void func_021C6DD0(u8 *, u8 *);
extern int func_021C88E4(u8 *);
extern void func_021CD568(void *, u32, u32, ...);
extern u32 func_021D805C(void *p, u32 n);
extern void func_021D5B44(struct QI *p, u16 v);
extern void func_021C7AD0(u8 *p, u8 *a, u32 b);
extern void func_021C7B0C(u8 *p, u8 *a);
extern void func_021C60EC(u8 *p, u8 *a, u32 n);
extern void func_021C6134(u8 *p, u8 *a, unsigned int n);
extern void func_021DCF24(u8 *a);
extern void *func_021DCF5C(void *p);
extern void func_021D6730(struct QK *p, u16 v);
extern void func_021C5BE4(u8 *, u8 *, int);
extern W sub_0201BF58(u16);
extern void func_021D7C70(W, u32, Word *);
extern u32 func_021C2564(u32);
extern void func_021C2574(u32);
extern u8 *func_021C2584(u32);
extern u8 *func_021C2594(u32);
extern void func_021C5718(u8 *, u8 *, u32);
extern u32 func_021C8828(u8 *p);
extern void func_021C5C74(u8 *p, u8 *a, int kind, u32 v);
extern int func_021D62C4(struct Unk021D62A8 *, int);
extern u16 func_021D57FC(void *);
extern int func_021E8D24(int x, int k);
extern void func_021C5C1C(u8 *, u8 *, int, Word);
extern void func_021C5480(u8 *, u8 *, int);
extern void func_021C2AA0(int, Word, u8 *, struct Msg *);
extern u16 func_021D5444(struct QF *p);
extern void func_021D8510(void *p);
extern void func_021D66D8(void *, u8);
extern void *func_021D8484(void *a);
extern int func_021D7D6C(int);
extern void func_021C3FDC(u8 *, u8 *);
extern int func_021EF884(void);
extern void func_021D70E4(void *a, int id);
extern int func_021C2E64(u8 *, const u16 *, u8 *, u8 *, int);
extern void func_021C2E1C(u32 c);
extern u32 func_021C2E2C(u32 c);
extern u32 func_021C2E3C(u32 c);
int func_021C1184(const u8 *p);
u8 func_021C1194(u8 *p);
void func_021C1198(unsigned char *p, int x);
u32 func_021C11A4(u8 *p, u16 *a, u8 *b, u8 *c, u8 *d, u8 *e, u32 f, struct Fl g);
int func_021C11F0(u8 *p, u8 *x, u8 *unused, u8 *y, u16 *e, u8 *st, u32 a6, struct Fl a7);
void func_021C14E0(u8 *p, u8 *a, int b, u8 *c);
void func_021C15AC(u8 *p, int k);
u32 func_021C15D4(void *p, u32 n);
void func_021C15E8(u8 *p, u8 *a, u8 *b, u16 *c);
void func_021C1624(u8 *p, u8 *a, u8 *b, u16 *c);
int func_021C1678(u8 *p, u8 *a, u8 *b, u32 c, u16 *d);
void func_021C16F8(u8 *p, u8 *a, int k);
void func_021C1758(u8 *p, u8 *q, int k);
void func_021C1788(u8 *p, u32 x, u8 *a, u32 n, u32 *arr);
void func_021C17CC(u8 *p, u32 x, u8 *a, u32 n, u8 **arr);
void func_021C1828(u8 *p, u8 b, u8 *x, u8 *c, u8 *q, u16 w);
void func_021C1880(u8 *p, u8 *q, u8 *a, u8 *b, u32 s0, int s1);
void func_021C18D4(u8 *p, u8 *a, u8 *q, u32 v);
void func_021C1910(u8 *p, u8 *a, u8 *q, u32 v);
void func_021C195C(u8 *p, u8 *q, u32 n);
void func_021C199C(u8 *p, u8 *q, u32 n);
void func_021C19D8(u8 *p, u8 *a, u8 *q);
void func_021C1A10(u8 *p, u8 *a, u8 *q);
void func_021C1A54(u8 *p, u8 *a, u8 *b, u8 *c, u32 unused, u32 d);
void func_021C1B5C(u8 *p, u8 *a, u8 *b, u8 *c, u32 d, u8 e, int f);
void func_021C1C88(u8 *p, u8 *a, u32 unused, u8 *q, u32 v);
int func_021C1CCC(u8 *p, u16 *x, u8 *a, u8 *q);
void func_021C1CE4(u8 *p, u8 *q, u32 unused, u8 *w);
int func_021C1D60(u8 *p, u8 *q, u32 n);
void func_021C1DCC(u8 *p, u8 *q, u32 a, u8 *b, u32 s);
int func_021C1E14(u8 *p, u8 *q, u32 a, u32 b);
int func_021C1E74(u8 *p, u8 *a, u8 *b, u8 *c, u32 d, u32 e, u32 f, int g, u16 *out);
void func_021C2048(u8 *p, u8 *a, u32 b, u32 c);
int func_021C20BC(u8 *p, u8 *a, int r);
int func_021C20D0(u8 *p, u8 *a, int c, u8 *l);
int func_021C2128(u8 *p, u8 *a);
int func_021C2204(u8 *p, u8 *a, u16 c);
void func_021C2250(u8 *p, u8 *a, u16 b, u32 c);
int func_021C2314(u8 *p, u8 *a);
void func_021C232C(u8 *p, const u16 *a, u8 *b, u8 *c);
u32 func_021C236C(u8 *p, u16 id, u8 *a, u8 *b, Word *dest);
void func_021C2488(u8 *p, u16 id, u8 *a, u32 c);
int func_021C25A4(u8 *p, u8 *a, u8 *b, u32 unused, u32 s0, Word s1, u32 s2);
int func_021C264C(u8 *p, u8 *a, u8 *b, u32 c);
void func_021C26A8(u8 *p, u32 a, u8 *b, u8 *c, u32 d);
void func_021C26FC(u8 *p, u8 *a, u8 *b, u32 c, Word *d);
int func_021C2758(u8 *p, u8 *x, u8 *y, int z, Word a, u32 b, u32 c);
int func_021C27A0(u8 *p, u8 *x, u8 *y, int z, Word a, u8 b, u32 c);
int func_021C282C(u8 *a, struct Unk021D62A8 *b, int c, Word d, u8 e);
void func_021C2910(u8 *p, u8 *a, u8 *b, int kind, Word value, int f, int g, const struct Msg *m);
int func_021C2AB0(u8 *p);
int func_021C2AF0(u8 *p, u8 *a);
int func_021C2B3C(u8 *p, u8 *a, u8 *b, u32 c);
void func_021C2BA4(u8 *p, u8 *a, u8 *b, u32 c);
void func_021C2BF0(u8 *p, u8 *a, u8 *b, u32 c, u32 d);
void func_021C2C50(u8 *p, u8 *a, u8 *b, u32 c);
void func_021C2CA8(u8 *p, u8 *a);
void func_021C2CD8(u8 *p, u16 *q, u8 *a, u8 *b);
int func_021C2D10(u8 *p, u16 *q, u8 *b, u8 *c);
void func_021C2DC4(u8 *p, u32 a, u32 b, u32 c);
extern u32 d_021F3B2C[];
extern u8 d_021F3B20[];
extern u8 *d_021F3B38[];
extern u16 d_021F3B26[];
extern u8 d_021F3B23[];
extern u32 d_021F3B20b[];











int func_021C1184(const u8 *p)
{
    return p[1] == 0;
}













/* 021C1194  ldrb r0,[r0,#3] */
u8 func_021C1194(u8 *p) { return p[3]; }












void func_021C1198(unsigned char *p, int x)
{
    if (p[5] == 3) {
        p[5] = x;
    }
}











u32 func_021C11A4(u8 *p, u16 *a, u8 *b, u8 *c, u8 *d, u8 *e, u32 f, struct Fl g)
{
    u32 r;
    if ((u8)func_021C0C34(d) != 0) {
        r = func_021C11F0(p, b, c, d, a, e, f, g);
        func_021C18D4(p, b, (u8 *)a, r);
        return r;
    }
    return 0;
}










/*
 * 2026-10-05 Q10/Q10b/Q10c/G7L9 (pengy share, user-approved): body from the listing, 47 of 704 bytes off (spill
 *   slot order m/k*4 around the third count, and the 5798/5840/59C4 argument order). Facts kept: v28 is u8,
 *   021C4104 takes sa/sb as separate stack args, 021C1198 takes an int, a7 is a one-bit field struct, the last
 *   loop's byte argument is d_021F3B20[k], 021C5798 has 8 parameters (two unused).
 * pass 2 2026-10-06 P2L45: EXACT (was 47 bytes off). Closing form: variables reused as a person would. The third
 *   count reuses `cnt` (no separate cnt3), the m loop reuses `j` from the cnt2 loop, and the later loops reuse
 *   `i` (neutral). A reused variable gets a second web numbered after the declared locals, which puts the m index
 *   at the lowest slot and the k*4 temp above the count (36 B). Then `cnt` and `cnt2` as u8 (the counts are u8
 *   results): mwcc keeps the reload of a spilled narrow local below the outgoing stack stores
 *   (docs/idioms/a-reload-kept-below-outgoing-stack-stores-is-a-narrow-local.md), which fixes the
 *   5798/5840/59C4 order; u8 cnt2 fixes the cnt/cnt2 slot swap. No (u8) casts needed. EXACT in --lang c99 and c.
 */
int func_021C11F0(u8 *p, u8 *x, u8 *unused, u8 *y, u16 *e, u8 *st, u32 a6, struct Fl a7)
{
    int sum;
    u8 v28;
    u8 cnt;
    u8 cnt2;
    int h;
    int i;
    int j;
    int flag;

    v28 = func_021C14B0(p + 0x1AB8, func_021D5440(x));
    sum = func_021C0D70(y);
    cnt = func_021C0C38(p, (List *)y, (u32 *)d_021F3B38, (u16 *)d_021F3B26, (u32 *)d_021F3B2C, (u8 *)d_021F3B20);
    for (i = 0; i < cnt; i++) {
        if (func_021D6D7C(d_021F3B38[i])) {
            h = func_021C4104(p, x, d_021F3B38[i], d_021F3B26[i], d_021F3B2C[i], d_021F3B20[i], e);
            func_021C14C0(*(void **)(p + 0x860), d_021F3B38[i], h, 1);
            sum -= d_021F3B26[i] - h;
        }
    }
    if (func_021C1184(st)) {
        cnt2 = func_021C0CB4(p, (const struct Q *)y, (u32 *)d_021F3B38);
        for (j = 0; j < cnt2; j++)
            func_021C15E8(p, x, d_021F3B38[j], e);
    }
    st[1] = st[1] + 1;
    cnt = func_021C0CE8(p, (const struct Q *)y, (u32 *)d_021F3B38, d_021F3B26, d_021F3B2C, d_021F3B20, d_021F3B23);
    if (cnt == 0)
        return sum;
    func_021C1788(p, (u32)e, x, cnt, (u32 *)d_021F3B38);
    flag = a7.f;
    func_021C5798(p, e, cnt, (int *)d_021F3B2C, d_021F3B38, d_021F3B26, d_021F3B20, flag);
    if (func_021C1194(st) == 0)
        func_021C5840(p, cnt, (int *)d_021F3B2C, d_021F3B38, flag);
    else
        func_021C1198(st, d_021F3B20b[3]);
    func_021C59C4(p, cnt, d_021F3B38, d_021F3B20, flag);
    for (j = 0; j < cnt; j++) {
        func_021C14D0(*(void **)(p + 0x860), d_021F3B38[j], d_021F3B26[j], 0);
        func_021C1828(p, v28, x, d_021F3B38[j], (u8 *)e, d_021F3B26[j]);
        func_021D5FC0((struct UtilWork *)d_021F3B38[j], 2);
    }
    for (i = 0; i < cnt; i++) {
        if (d_021F3B23[i])
            func_021C16F8(p, d_021F3B38[i], d_021F3B23[i]);
    }
    for (i = 0; i < cnt; i++) {
        func_021C1CCC(p, e, x, d_021F3B38[i]);
        func_021C1DCC(p, (u8 *)e, (u32)x, d_021F3B38[i], d_021F3B26[i]);
        func_021C1880(p, (u8 *)e, x, d_021F3B38[i], d_021F3B26[i], 0);
        func_021C4218(p, x, d_021F3B38[i], (u8 *)e, d_021F3B2C[i], d_021F3B26[i], d_021F3B20[i], 0);
    }
    for (i = 0; i < cnt; i++)
        func_021C4F64(p, d_021F3B38[i]);
    func_021C4F64(p, x);
    return sum;
}









void func_021C14E0(u8 *p, u8 *a, int b, u8 *c)
{
    u8 *r;
    u32 s;
    func_021C156C(c);
    r = func_021C157C(c);
    if (r != 0) {
        do {
            if (func_021C6B5C(p, a, r, (u8 *)b) != 0) {
                struct St *st = *(struct St * *)&((struct Obj21076 *)p)->f4A8;
                if (st->f == 0) st->f = 1;
                s = func_021CC8D8(p + 0x1d74, 0x197b);
                func_021C6BB8(p, a, r);
                func_021CC95C((u32 *)(p + 0x1d74), s, 0x197f);
                func_021C158C(c, r);
            }
            r = func_021C159C(c);
        } while (r != 0);
    }
}












void func_021C15AC(u8 *p, int k)
{
    if (k < 3) {
        func_021CD64C(((struct Obj13320 *)p)->fC, 0x5a, 0x4f, 0xffff0000);
    } else if (k > 3) {
        func_021CD64C(((struct Obj13320 *)p)->fC, 0x5a, 0x4e, 0xffff0000);
    }
}













u32 func_021C15D4(void *p, u32 n)
{
    u32 v = func_021D59B4(p, 13);
    if (n > v) n = v;
    return n;
}













/*
 * interface: Complete lock word returned in r0 at 021CC900; restore
 * 021CC95C stores the unchanged full r1 word. Scalar u32 preserves all bits.
 */
void func_021C15E8(u8 *p, u8 *a, u8 *b, u16 *c)
{
    u32 s = func_021CC8D8(p + 0x1d74, 6570);
    func_021C1624(p, a, b, c);
    func_021CC95C((u32 *)(p + 0x1d74), s, 6570 + 4);
}












void func_021C1624(u8 *p, u8 *a, u8 *b, u16 *c)
{
    func_021D74F8(0x19bd);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x12, c[0]);
    func_021D75EC(0x16, ((u8 *)c)[6]);
    func_021D70F0(p, 0x45);
    func_021D7540(0x19bd + 7);
}












int func_021C1678(u8 *p, u8 *a, u8 *b, u32 c, u16 *d)
{
    int r;
    if (func_021D59B4(b, 13) > *d) return 0;
    func_021D74F8(0x19df);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x51, c);
    func_021D7630(0x3a, 0);
    func_021D70F0(p, 0x74);
    r = func_021D775C(0x3a);
    func_021D7540(0x19df + 7);
    if (r != 0) *d = func_021D59B4(b, 13) - 1;
    return r;
}












/*
 * The empty `case 3: break;` is what keeps the `cmp r4, #3` and the
 * unconditional branch; a plain `if (k == 3) {}` compiles differently.
 */
void func_021C16F8(u8 *p, u8 *a, int k)
{
    u32 s;
    u8 n = func_021D5440(a);
    switch (k) {
    case 1:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x202, n, 0xffff0000);
        return;
    case 3:
        break;
    }
    s = func_021CC8D8(p + 0x1d74, 0x1a04);
    func_021C1758(p, a, k);
    func_021CC95C((u32 *)(p + 0x1d74), s, 0x1a07);
}












void func_021C1758(u8 *p, u8 *q, int k)
{
    func_021D74F8(0x1a17);
    func_021D75EC(2, func_021D5440(q));
    func_021D70F0(p, 0x75);
    func_021D7540(0x1a17 + 3);
}











void func_021C1788(u8 *p, u32 x, u8 *a, u32 n, u32 *arr)
{
    u32 s = func_021CC8D8(p + 0x1D74, 6697);
    func_021C17CC(p, x, a, n, (u8 **)arr);
    func_021CC95C((u32 *)(p + 0x1D74), s, 6702);
}











void func_021C17CC(u8 *p, u32 x, u8 *a, u32 n, u8 **arr)
{
    u32 i;
    func_021D74F8(6719);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(5, n);
    for (i = 0; i < n; i++) {
        func_021D75EC(6 + i, func_021D5440(arr[i]));
    }
    func_021D70F0(p, 0x44);
    func_021D7540(6727);
}











/*
 * The Rec build loads q[6] and q[0] first (ldrb, ldrh) only when both are
 * read into their own locals (c6 before a0), assigned after the second
 * func_021D5440 call; reading them straight into the fields interleaves
 * loads and stores.
 */
void func_021C1828(u8 *p, u8 b, u8 *x, u8 *c, u8 *q, u16 w)
{
    struct Rec r;
    u8 c6;
    u16 a0;
    u8 n = func_021D5440(x);
    u8 m = func_021D5440(c);
    c6 = q[6];
    a0 = ((struct Obj02778 *)q)->f0;
    r.a = a0;
    r.b = w;
    r.c = c6;
    r.d = n;
    r.e = b;
    func_021D6848(c, &r);
    func_021CD4B0(((struct Obj21078 *)p)->fC, 0x2d, m, n, b, q[6], ((struct Obj02778 *)q)->f0, w);
}











void func_021C1880(u8 *p, u8 *q, u8 *a, u8 *b, u32 s0, int s1)
{
    switch (sub_0201C1BC(((struct Obj09968 *)q)->f0)) {
    case 7:
        func_021C2CD8(p, (u16 *)q, a, a);
        break;
    case 6:
        if (s1 == 0) {
            func_021C2CD8(p, (u16 *)q, a, b);
        }
        break;
    case 4:
        if (s1 == 0) {
            func_021C232C(p, (const u16 *)q, a, b);
        }
        break;
    }
}











void func_021C18D4(u8 *p, u8 *a, u8 *q, u32 v)
{
    u32 s = func_021CC8D8(p + 0x1d74, 6802);
    func_021C1910(p, a, q, v);
    func_021CC95C((u32 *)(p + 0x1d74), s, 6802 + 3);
}











void func_021C1910(u8 *p, u8 *a, u8 *q, u32 v)
{
    func_021D74F8(6823);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, ((struct Obj13323 *)q)->f0);
    func_021D75EC(0x16, q[6]);
    func_021D75EC(0x32, v);
    func_021D70F0(p, 0x4d);
    func_021D7540(6829);
}











void func_021C195C(u8 *p, u8 *q, u32 n)
{
    if (func_021D5B40((struct QI *)q)) {
        u32 s = func_021CC8D8(p + 0x1D74, 6844);
        func_021C199C(p, q, n);
        func_021CC95C((u32 *)(p + 0x1D74), s, 6850);
    }
}










void func_021C199C(u8 *p, u8 *q, u32 n)
{
    func_021D74F8(0x1acf);
    func_021D75EC(2, func_021D5440(q));
    func_021D75EC(0x2e, n);
    func_021D70F0(p, 0x91);
    func_021D7540(0x1acf + 4);
}










void func_021C19D8(u8 *p, u8 *a, u8 *q)
{
    u32 s = func_021CC8D8(p + 0x1d74, 6874);
    func_021C1A10(p, a, q);
    func_021CC95C((u32 *)(p + 0x1d74), s, 6874 + 2);
}










void func_021C1A10(u8 *p, u8 *a, u8 *q)
{
    func_021D74F8(6890);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, ((struct Obj13324 *)q)->f0);
    func_021D75EC(0x16, q[6]);
    func_021D70F0(p, 0x81);
    func_021D7540(6897);
}









void func_021C1A54(u8 *p, u8 *a, u8 *b, u8 *c, u32 unused, u32 d)
{
    u32 lock;
    u8 *x;
    func_021C1CE4(p, a, (u32)b, c);
    lock = func_021CC8D8(p + 0x1d74, 0x1b07);
    func_021C1B5C(p, b, c, a, d, 0, 0x84);
    func_021C1B5C(p, b, c, a, d, 1, 0x83);
    func_021C1B5C(p, b, c, a, d, 0, 0x85);
    func_021C1B2C(c);
    x = func_021C1B3C(c);
    while (x) {
        func_021C195C(p, x, 1);
        x = func_021C1B4C(c);
    }
    func_021C1B5C(p, b, c, a, d, 0, 0x86);
    func_021C1B5C(p, b, c, a, d, 1, 0x87);
    func_021C1C88(p, b, (u32)c, a, d);
    func_021CC95C((u32 *)(p + 0x1d74), lock, 0x1b1b);
}






void func_021C1B5C(u8 *p, u8 *a, u8 *b, u8 *c, u32 d, u8 e, int f)
{
    u32 sum;
    u32 n;
    u32 got;
    u32 i;
    u32 v;
    u8 *x;
    int ok;
    n = func_021C1C48(b);
    sum = 0;
    got = 0;
    func_021D74F8(0x1b2b);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x4d, d);
    func_021D75EC(0x12, ((struct Obj13325 *)c)->f0);
    func_021D75EC(0x16, c[6]);
    for (i = 0; i < n; i++) {
        x = func_021C1C58(b, i);
        if (e) ok = func_021C1C68(b, x, &v);
        else ok = func_021C1C78(b, x, &v);
        if (ok) {
            sum += v;
            func_021D75EC(got + 6, func_021D5440(x));
            got++;
        }
    }
    if (got) {
        func_021D75EC(5, got);
        func_021D7630(0x47, 0);
        func_021D7630(0x48, 0);
        func_021D75EC(0x32, sum);
        func_021D70F0(p, 0x82);
        if (!func_021D775C(0x48)) func_021D70F0(p, f);
    }
    func_021D7540(0x1b52);
}







void func_021C1C88(u8 *p, u8 *a, u32 unused, u8 *q, u32 v)
{
    func_021D74F8(7009);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x4d, v);
    func_021D75EC(0x12, ((struct Obj21079 *)q)->f0);
    func_021D70F0(p, 0x88);
    func_021D7540(7014);
}







int func_021C1CCC(u8 *p, u16 *x, u8 *a, u8 *q)
{
    int n;
    n = func_021C7664(p, *x, a);
    return func_021C1D60(p, q, n);
}








void func_021C1CE4(u8 *p, u8 *q, u32 unused, u8 *w)
{
    u8 *t;
    if (q[6] == 9) {
        func_021C1D30(w);
        t = func_021C1D40(w);
        while (t) {
            int k = 3;
            if (func_021D62A8((struct Unk021D62A8 *)t) == 3 && func_021D6D7C(t) == 0) {
                func_021C557C(p, t, k, 1);
            }
            t = func_021C1D50(w);
        }
    }
}







int func_021C1D60(u8 *p, u8 *q, u32 n)
{
    if (func_021D5BB0((struct UtilWork *)q, 5)) {
        func_021D5FC0((struct UtilWork *)q, 6);
        return 1;
    }
    if (func_021C76F4(p, q, n)) {
        func_021D5FC0((struct UtilWork *)q, 4);
        return 1;
    }
    if (n >= 100) {
        u32 s = func_021CC8D8(p + 0x1D74, 7085);
        func_021C7780(p, q);
        func_021CC95C((u32 *)(p + 0x1D74), s, 7087);
    }
    return 0;
}







void func_021C1DCC(u8 *p, u8 *q, u32 a, u8 *b, u32 s)
{
    if (sub_0201C1BC(((struct Obj09967 *)q)->f0) == 8) {
        if (func_021C1E14(p, (u8 *)a, (u32)b, (u16)func_021D7B3C(s, sub_0201BD28(((struct Obj09967 *)q)->f0, 0x19)))) {
            func_021C5D88(p, b, 0x383);
        }
    }
}







int func_021C1E14(u8 *p, u8 *q, u32 a, u32 b)
{
    u32 s = func_021CC8D8(p + 0x1D74, 7154);
    int r = 0;
    u8 *t = (u8 *)func_021C78F4(p, q, (u8 *)a, b);
    if (t) {
        if (func_021C3370(p, q) == 0) {
            r = func_021C334C(p, q, (int)t, 1);
        }
    }
    func_021CC95C((u32 *)(p + 0x1D74), s, 7168);
    return r;
}






/*
 *   Call +0x10 has no witness outside 021C1E74..021C2048; all concrete
 *   bytes match, and the other 39 relocation sites resolve.
 *   Verified one --thumb, no --region, dsi/1.1p1 -O4,p: EXACT, 12 bytes.
 *   typedef unsigned short u16; typedef unsigned int u32;
 *   extern u32 sub_0201BD28(u16, u32);
 * lever: a separately narrowed u8 level local avoids the extra r0-to-r2
 *   copy from narrowing an inline call argument. value * scale selects
 *   the original multiplication destination; scale * value adds a copy.
 */
int func_021C1E74(u8 *p, u8 *a, u8 *b, u8 *c, u32 d, u32 e, u32 f, int g, u16 *out)
{
    int category = func_0201C1E8(*(u16 *)c);
    int flag = 0;
    u32 result;
    u32 x;
    u32 y;
    u32 value;
    u32 factor;
    u16 scale;
    u8 level;
    func_021D74F8(0x1c21);
    func_021D75EC(0x38, d);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x45, f);
    func_021D75EC(0x16, c[6]);
    func_021D75EC(0x12, *(u16 *)c);
    func_021D75EC(0x1a, category);
    func_021D75A8(0x37, 0);
    func_021D70F0(p, 0x46);
    result = (u32)func_021D775C(0x37);
    if (result) {
        flag = 1;
    } else {
        x = func_021C728C(p, a, b, c);
        y = func_021C7374(p, a, b, c, f);
        value = func_021C7474(p, a, b, c, f);
        level = func_021D59B4(a, 15);
        value = func_021D7A44(x, y, level, value);
        if (e != 0x1000) value = func_021D7B10(value, e);
        factor = func_021D7C38(func_021C2AB0(p), c[6]);
        if (factor != 0x1000) value = func_021D7B10(value, factor);
        if (f) value *= 2;
        if (!func_021B911C(*(void **)(p + 4), 7)) {
            if (g) scale = 85;
            else scale = 100 - func_021D78AC(16);
            value = (u32)(value * scale) / 100u;
        }
        if (c[6] != 17) value = func_021D7B10(value, func_021C75EC(p, a, c[6]));
        value = func_021D7A6C(value, d);
        if (category == 1 && func_021D62A8((struct Unk021D62A8 *)a) == 4 && func_021D59B4(a, 17) != 62) {
            value = (u32)(50u * value) / 100u;
        }
        if (!value) value = 1;
        func_021D7674(0x35, 0x1000, 0x29, 0x20000);
        func_021D75A8(0x32, value);
        func_021D70F0(p, 0x47);
        factor = (u32)func_021D775C(0x35);
        result = func_021D7B10((u32)func_021D775C(0x32), factor);
    }
    func_021D70F0(p, 0x48);
    func_021D7540(0x1c8d);
    *out = result;
    return flag;
}







void func_021C2048(u8 *p, u8 *a, u32 b, u32 c)
{
    int loc;
    int r;
    if (func_021D5B68(a) != 0)
        return;
    r = func_021C6CAC(p, a, b, c, &loc);
    if (r == 0)
        return;
    func_021C8838(p + 0x1AE4, 2, 378);
    func_021C8860((struct S *)(p + 0x1AE4), func_021D5440(a));
    if (loc == 0 && func_021C20BC(p, a, r) == 0)
        return;
    func_021C20D0(p, a, r, p + 0x1AE4);
}






/*
 * extent: two zero alignment bytes follow the return at 0x021C20CE.
 */
int func_021C20BC(u8 *p, u8 *a, int r)
{
    if (func_021C7330(p, a))
        return 1;
    return 0;
}







int func_021C20D0(u8 *p, u8 *a, int c, u8 *l)
{
    int r;
    c = -c;
    if (c != 0) {
        func_021C5B74(p, a, c, 1);
        func_021D5FC0((struct UtilWork *)a, 2);
        if (l != 0) {
            func_021C99A0(p, (const struct Msg *)l);
            func_021C8810(l);
        }
        r = 1;
        func_021C195C(p, a, 1);
        if (func_021C4F64(p, a) != 0) {
            func_021BC2B0(p);
            return r;
        }
        return r;
    }
    return 0;
}





int func_021C2128(u8 *p, u8 *a)
{
    int t = func_021D5B40((struct QI *)a);
    int result = 0;
    u32 s;
    u32 v;
    u32 pos;
    if (func_021C21F4(p + 0x1ab8, func_021D5440(a))) {
        s = func_021CC8D8(p + 0x1d74, 0x1cea);
        if (func_021C2204(p, a, (u16)t) == 0) result = 1;
        if (result) {
            pos = func_021CD4FC((u8 *)(((struct Obj00003 *)p)->fC), 0x42);
            v = func_021CC918(p + 0x1d74, (u16)t, 0x1cf4);
            func_021C6DD0(p, a);
            if (func_021C88E4(p) != 2) result = 0;
            func_021CC95C((u32 *)(p + 0x1d74), v, 0x1cf9);
            if (result) {
                func_021CD568(((struct Obj00003 *)p)->fC, pos, 0x42, func_021D5440(a));
                if (func_021D805C((void *)((u16)t), 0x10)) func_021C2250(p, a, 0, 1);
            }
        }
        func_021CC95C((u32 *)(p + 0x1d74), s, 0x1d06);
    }
    return result;
}








int func_021C2204(u8 *p, u8 *a, u16 c)
{
    int r;
    func_021D74F8(7449);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x2d, c);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x90);
    r = func_021D775C(0x41);
    func_021D7540(7455);
    return r;
}









void func_021C2250(u8 *p, u8 *a, u16 b, u32 c)
{
    u32 s;
    u16 t;
    int name;
    name = func_021D5440(a);
    t = (u16)(int)func_021D5B40((struct QI *)a);
    s = func_021CC8D8(p + 0x1D74, 7469);
    func_021C7AD0(p, a, b);
    func_021CC95C((u32 *)(p + 0x1D74), s, 7471);
    if (b == 0)
        func_021C60EC(p, a, 15);
    func_021DCF24(a);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x1E, name, b);
    func_021D5B44((struct QI *)a, b);
    if (b != 0)
        func_021DCF5C(a);
    s = func_021CC8D8(p + 0x1D74, 7485);
    func_021C7B0C(p, a);
    func_021CC95C((u32 *)(p + 0x1D74), s, 7487);
    if (c != 0) {
        func_021D6730((struct QK *)a, t);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 0x17, name, t);
        func_021C6134(p, a, 8);
    }
}








/*
 * extent: two zero alignment bytes follow the return at 0x021C232A.
 * interface: func_021C5BE4 reads r0/r1/r2 and forwards r2 unchanged;
 * func_021C4F64 has two arguments in its existing DIFF note.
 */
int func_021C2314(u8 *p, u8 *a)
{
    func_021C5BE4(p, a, 0);
    return func_021C4F64(p, a);
}







void func_021C232C(u8 *p, const u16 *a, u8 *b, u8 *c)
{
    Word loc;
    u32 r;
    r = func_021C236C(p, *a, b, c, &loc);
    if (r != 0 && func_021D5B68(c) == 0)
        func_021C25A4(p, b, c, *a, r, loc, 0);
}





static inline int chance(u32 n)
{
    return func_021D78AC(100) < n;
}





u32 func_021C236C(u8 *p, u16 id, u8 *a, u8 *b, Word *dest)
{
    u32 s;
    W w;
    Word out;
    u8 rate;
    u32 result;
    u8 changedRate;
    u8 veto;
    s = sub_0201BD28(id, 11);
    w = sub_0201BF58(id);
    rate = sub_0201BD28(id, 12);
    func_021D7C70(w, (u32)a, &out);
    func_021D74F8(0x1d7c);
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, id);
    func_021D75A8(0x1d, s);
    func_021D7630(0x41, 0);
    func_021D7630(0x1e, out.v);
    func_021D75A8(0x26, rate);
    func_021D70F0(p, 0x64);
    result = func_021D775C(0x1d);
    rate = func_021D775C(0x26);
    veto = func_021D775C(0x41);
    if (result == 0xffff) result = 0;
    out.v = func_021D775C(0x1e);
    func_021D7540(0x1d8f);
    if (!veto && result) {
        if (chance(rate)) {
            *dest = out;
            return result;
        }
        if (func_021B911C(((struct Obj21082 *)p)->f4, 0)) {
            *dest = out;
            return result;
        }
    }
    return 0;
}




void func_021C2488(u8 *p, u16 id, u8 *a, u32 c)
{
    u32 s;
    W w;
    Word out;
    u8 *t;
    int got;
    s = sub_0201BD28(id, 11);
    w = sub_0201BF58(id);
    got = 0;
    if (func_021C2564(c)) {
        func_021C2574(c);
        for (t = func_021C2584(c); t; t = func_021C2594(c)) {
            func_021D7C70(w, (u32)a, &out);
            if (func_021C25A4(p, a, t, id, s, out, 1)) {
                BF_021C1184 *flag = *(BF_021C1184 * *)&((struct Obj21083 *)p)->f4A8;
                if (!flag->f) flag->f = 1;
                got = 1;
            }
        }
        if (!got && !((State *)p)->f) func_021C5718(p, a, id);
    } else {
        func_021C5718(p, a, id);
    }
}







int func_021C25A4(u8 *p, u8 *a, u8 *b, u32 unused, u32 s0, Word s1, u32 s2)
{
    int t;
    func_021C8810(p + 0x1AE4);
    if (s0 == 0xFFFF) {
        s0 = func_021C264C(p, a, b, (u32)(p + 0x1AE4));
        if (s0 == 0 || s0 == 0xFFFF)
            return 0;
    } else {
        func_021C26A8(p, s0, a, b, (u32)(p + 0x1AE4));
    }
    func_021C26FC(p, a, b, s0, &s1);
    t = func_021C8828(p + 0x1AE4) ? 0 : 1;
    if (func_021C2758(p, b, a, s0, s1, s2, t) != 0) {
        if (t == 0) {
            func_021C99A0(p, (const struct Msg *)(p + 0x1AE4));
            func_021C8810(p + 0x1AE4);
        }
        return 1;
    }
    return 0;
}








int func_021C264C(u8 *p, u8 *a, u8 *b, u32 c)
{
    int r;
    func_021D74F8(7681);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x3f, c);
    func_021D75A8(0x1d, 0);
    func_021D70F0(p, 0x60);
    r = func_021D775C(0x1d);
    func_021D7540(7688);
    return r;
}








void func_021C26A8(u8 *p, u32 a, u8 *b, u8 *c, u32 d)
{
    func_021D74F8(7704);
    func_021D75EC(3, func_021D5440(b));
    func_021D75EC(4, func_021D5440(c));
    func_021D75EC(0x3f, d);
    func_021D75EC(0x1d, a);
    func_021D70F0(p, 0x61);
    func_021D7540(7710);
}








void func_021C26FC(u8 *p, u8 *a, u8 *b, u32 c, Word *d)
{
    func_021D74F8(7726);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x1d, c);
    func_021D75A8(0x1e, d->v);
    func_021D70F0(p, 0x62);
    d->v = func_021D775C(0x1e);
    func_021D7540(7726 + 7);
}






int func_021C2758(u8 *p, u8 *x, u8 *y, int z, Word a, u32 b, u32 c)
{
    if (func_021C27A0(p, x, y, z, a, 0, b) == 0) {
        func_021C2910(p, x, y, z, a, c, 0, 0);
        return 1;
    }
    return 0;
}





/*
 * The fifth parameter is a one-word struct passed by value and handed on
 * to func_021C282C by value (`add r3, sp, #0x20; ldr r3, [r3]`, the
 * push-r0-r3 struct idiom); a plain u32 folds to `ldr r3, [sp, #0x20]`.
 * The caller func_021C2758 passes it as a plain u32 word. Declaring s
 * before t puts s in [sp, #8].
 */
int func_021C27A0(u8 *p, u8 *x, u8 *y, int z, Word a, u8 b, u32 c)
{
    int r;
    u32 s;
    int t;
    r = func_021C282C(p, (struct Unk021D62A8 *)x, z, a, b);
    if (r != 0) {
        if (c != 0)
            func_021C5C74(p, x, r, z);
        return 1;
    }
    s = func_021CC8D8(p + 0x1D74, 7779);
    t = func_021C2B3C(p, y, x, z);
    if (t != 0 && c != 0) {
        func_021C2BA4(p, x, y, z);
        p[0x78A] |= 0x10;
    }
    func_021CC95C((u32 *)(p + 0x1D74), s, 7792);
    return t;
}




int func_021C282C(u8 *a, struct Unk021D62A8 *b, int c, Word d, u8 e)
{
    u16 t;
    if (func_021D62C4(b, c) && e != 2) return 1;
    if (c < 6 && func_021D62A8(b) && e == 0) return 3;
    if (func_021C2AB0(a) == 1 && c == 3) return 3;
    if (c == 5) {
        t = func_021D57FC(b);
        if (func_021E8D24(t, 8) || func_021E8D24(t, 3)) return 2;
    }
    if (c == 4 && func_021E8D24(func_021D57FC(b), 9)) return 2;
    if (c == 3 && func_021E8D24(func_021D57FC(b), 14)) return 2;
    if (c == 18 && func_021E8D24(func_021D57FC(b), 11)) return 2;
    if (c == 14 && func_021D62A8(b)) return 3;
    if (c == 16 && func_021D59B4((u8 *)b, 16) == 121) return 3;
    return 0;
}




void func_021C2910(u8 *p, u8 *a, u8 *b, int kind, Word value, int f, int g, const struct Msg *m)
{
    u32 lock;
    func_021C5C1C(p, a, kind, value);
    switch (kind) {
    case 5: func_021C5480(p, a, 599); break;
    case 4: func_021C5480(p, a, 600); break;
    case 1: func_021C5480(p, a, 602); break;
    case 3: func_021C5480(p, a, 601); break;
    case 2: func_021C5480(p, a, 598); break;
    case 6: func_021C5480(p, a, 603); break;
    case 7: func_021C5480(p, a, 604); break;
    case 0: break;
    }
    if (f) {
        func_021C2AA0(kind, value, a, (struct Msg *)(p + 0x1ae4));
        func_021C99A0(p, (struct Msg *)(p + 0x1ae4));
        func_021C8810((u8 *)(p + 0x1ae4));
    } else if (m) func_021C99A0(p, m);
    if (kind == 3 && func_021D5444((struct QF *)a) == 492 && func_021D59B4(a, 19) == 1) {
        func_021D8510(a);
        func_021D66D8(a, 0);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 79, func_021D5440(a), 0);
        func_021D8484(a);
        func_021C5D88(p, a, 222);
    }
    lock = func_021CC8D8(p + 0x1d74, 7936);
    if (func_021D7D6C(kind)) {
        func_021C2BF0(p, a, b, kind, value.v);
    } else if (kind == 16) {
        func_021C2CA8(p, (u8 *)((int)a));
        if (func_021D59B4(a, 17) == 127) func_021C3FDC(p, a);
    } else func_021C2C50(p, a, b, kind);
    func_021CC95C((u32 *)(p + 0x1d74), lock, 7951);
    if (!g) func_021C195C(p, a, 3);
}





int func_021C2AB0(u8 *p)
{
    int r;
    int t;
    func_021D74F8(7971);
    func_021D7630(0x41, 0);
    r = 0;
    func_021D70F0(p, 0x7a);
    t = func_021D775C(0x41);
    func_021D7540(7975);
    if (t == 0)
        r = func_021EF884();
    return r;
}





int func_021C2AF0(u8 *p, u8 *a)
{
    int r;
    func_021D74F8(7997);
    func_021D75EC(2, func_021D5440(a));
    func_021D7674(0x35, 2 << 11, 410, 2 << 16);
    func_021D70F0(p, 0x7B);
    r = func_021D775C(0x35);
    func_021D7540(8002);
    return r;
}





int func_021C2B3C(u8 *p, u8 *a, u8 *b, u32 c)
{
    int r;
    func_021D74F8(8021);
    func_021D75EC(3, a ? func_021D5440(a) : 0x1F);
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x1D, c);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x65);
    r = func_021D775C(0x41);
    func_021D7540(8028);
    return r;
}





void func_021C2BA4(u8 *p, u8 *a, u8 *b, u32 c)
{
    func_021D74F8(8042);
    func_021D75A8(4, func_021D5440(a));
    func_021D75A8(3, func_021D5440(b));
    func_021D75A8(0x1D, c);
    func_021D70F0(p, 0x67);
    func_021D7540(8047);
}





void func_021C2BF0(u8 *p, u8 *a, u8 *b, u32 c, u32 d)
{
    func_021D74F8(8062);
    func_021D75EC(4, func_021D5440(a));
    func_021D75EC(3, (u8)(b ? func_021D5440(b) : 0x1F));
    func_021D75EC(0x1D, c);
    func_021D75EC(0x1E, d);
    func_021D70F0(p, 0x68);
    func_021D7540(8071);
}





void func_021C2C50(u8 *p, u8 *a, u8 *b, u32 c)
{
    func_021D74F8(8085);
    func_021D75EC(4, func_021D5440(a));
    func_021D75EC(3, (u8)(b ? func_021D5440(b) : 0x1F));
    func_021D75EC(0x1D, c);
    func_021D70F0(p, 0x69);
    func_021D7540(8093);
}




void func_021C2CA8(u8 *p, u8 *a)
{
    func_021D74F8(8105);
    func_021D75EC(2, func_021D5440(a));
    func_021D70E4(p, 0x6a);
    func_021D7540(8108);
}




/*
 * extent: two bytes of zero alignment padding at 0x021C2D0E.
 */
void func_021C2CD8(u8 *p, u16 *q, u8 *a, u8 *b)
{
    if (func_021D5B68(b) == 0) {
        if (func_021C2D10(p, q, a, b) != 0)
            func_021C2E64(p, q, a, b, 0);
    }
}




int func_021C2D10(u8 *p, u16 *q, u8 *b, u8 *c)
{
    u8 s, x, y;
    u32 t;
    s = sub_0201BD28(*q, 0x12);
    func_021D74F8(8142);
    func_021D75EC(3, func_021D5440(b));
    func_021D75EC(4, func_021D5440(c));
    func_021D75EC(0x12, *q);
    t = 0;
    func_021D7630(0x41, 0);
    func_021D75A8(0x26, s);
    func_021D70F0(p, 0x51);
    x = func_021D775C(0x41);
    y = func_021D775C(0x26);
    func_021D7540(8152);
    if (x == 0) {
        if (func_021D78AC(100) < y)
            t = 1;
        if (t)
            return 1;
        if (func_021B911C((void *)(((struct Obj21084 *)p)->f4), 0) != 0)
            return 1;
    }
    return 0;
}



void func_021C2DC4(u8 *p, u32 a, u32 b, u32 c)
{
    u32 t;
    func_021C2E1C(c);
    for (t = func_021C2E2C(c); t != 0; t = func_021C2E3C(c)) {
        if (func_021C2E64(p, (const u16 *)a, (u8 *)b, (u8 *)t, 1) != 0) {
            BF_021C2AB0 *f = *(BF_021C2AB0 * *)&((struct Obj21085 *)p)->f4A8;
            if (!f->f)
                f->f = 1;
        }
    }
}
