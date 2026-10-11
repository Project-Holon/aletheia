/*
 * file:     btl_server_p12.c
 * unit:     yes
 * function: func_021C5308, func_021C5350, func_021C5418, func_021C5474, func_021C5480, func_021C54BC, func_021C54C8, func_021C54FC, func_021C5540, func_021C557C, func_021C5604, func_021C5620, func_021C56A8, func_021C5718, func_021C572C, func_021C5750, func_021C5774, func_021C5798, func_021C5840, func_021C59C4, func_021C5A1C, func_021C5A34, func_021C5A4C, func_021C5A8C, func_021C5B74, func_021C5BE4, func_021C5C1C, func_021C5C74, func_021C5D88, func_021C5DAC, func_021C5E48, func_021C5EFC, func_021C5F98, func_021C604C, func_021C6080, func_021C60D4, func_021C60EC, func_021C6110, func_021C6134, func_021C6158, func_021C6190, func_021C62D8, func_021C6350, func_021C6394, func_021C63D0, func_021C6458, func_021C64B4, func_021C6564, func_021C65A8, func_021C6668, func_021C66AC, func_021C6720, func_021C676C, func_021C6848, func_021C6878, func_021C68A8, func_021C6948, func_021C69B8, func_021C6A04, func_021C6A9C, func_021C6B5C, func_021C6BB8, func_021C6BF8, func_021C6CAC, func_021C6DD0, func_021C6E00, func_021C6E3C, func_021C6F0C, func_021C6F34, func_021C6FC0, func_021C7008, func_021C7038, func_021C70E4, func_021C7194, func_021C71E0, func_021C728C, func_021C7330, func_021C7374, func_021C7474, func_021C75EC, func_021C7664, func_021C76F4, func_021C7780, func_021C77B0, func_021C7820, func_021C785C, func_021C78A8, func_021C78F4, func_021C7998, func_021C79E0, func_021C7A54, func_021C7AA0, func_021C7AD0, func_021C7B0C, func_021C7B3C, func_021C7B7C, func_021C7BA8, func_021C7BF8, func_021C7C18, func_021C7C24, func_021C7CBC, func_021C7CC8, func_021C7CD4, func_021C7CDC, func_021C7CE8, func_021C7CF4, func_021C7D00
 * address:  0x021C5308
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
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021CB2D4  0x021CB2D4  thumb  ov093
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021D69B8 0x021D69B8 thumb ov093
 *   func_021BA1CC 0x021BA1CC thumb ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021BD1D0  0x021BD1D0  thumb  ov093
 *   func_021C54AC  0x021C54AC  thumb  ov093
 *   func_021D62D8  0x021D62D8  thumb  ov093
 *   func_021D61F0  0x021D61F0  thumb  ov093
 *   func_021D6314  0x021D6314  thumb  ov093
 *   func_021C5698  0x021C5698  thumb  ov093
 *   func_021D6238  0x021D6238  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D7E10  0x021D7E10  thumb  ov093
 *   func_021CD63C  0x021CD63C  thumb  ov093
 *   func_021D5DC0 0x021D5DC0 thumb ov093
 *   func_021D5E38 0x021D5E38 thumb ov093
 *   func_021D5FA4  0x021D5FA4  thumb  ov093
 *   func_021C5BD4  0x021C5BD4  thumb  ov093
 *   func_021D5FB8 0x021D5FB8 thumb ov093
 *   func_021D6034  0x021D6034  thumb  ov093
 *   func_021E8A78  0x021E8A78  thumb  ov093
 *   func_021B911C 0x021B911C thumb ov093
 *   func_021D5F90 0x021D5F90 thumb ov093
 *   func_021D56A0  0x021D56A0  thumb  ov093
 *   func_021D5674  0x021D5674  thumb  ov093
 *   func_021D5FE4 0x021D5FE4 thumb ov093
 *   func_021D6008 0x021D6008 thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021B9D10 0x021B9D10 thumb ov093
 *   func_021E02DC 0x021E02DC thumb ov093
 *   func_021E03D8 0x021E03D8 thumb ov093
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D75EC 0x021D75EC thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7A44  0x021D7A44  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021C1678  0x021C1678  thumb  ov093
 *   func_021C16F8  0x021C16F8  thumb  ov093
 *   func_021C8810  0x021C8810  thumb  ov093
 *   sub_0201C1C8   0x0201C1C8  thumb
 *   sub_0201C1E8   0x0201C1E8  thumb
 *   sub_0201BD28   0x0201BD28  thumb
 *   func_021D57FC  0x021D57FC  thumb  ov093
 *   func_021C6648  0x021C6648  thumb  ov093
 *   func_021C6658  0x021C6658  thumb  ov093
 *   func_021C6710  0x021C6710  thumb  ov093
 *   func_021C6828  0x021C6828  thumb  ov093
 *   func_021C6838  0x021C6838  thumb  ov093
 *   func_021C6928  0x021C6928  thumb  ov093
 *   func_021C6938  0x021C6938  thumb  ov093
 *   func_021D5C08  0x021D5C08  thumb  ov093
 *   sub_0201C1F4  0x0201C1F4  thumb
 *   func_021D7674  0x021D7674  thumb  ov093
 *   func_021D7B10  0x021D7B10  thumb  ov093
 *   func_021BF324  0x021BF324  thumb  ov093
 *   sub_0201C284  0x0201C284  thumb
 *   func_021D5F14  0x021D5F14  thumb  ov093
 *   func_021D7930  0x021D7930  thumb  ov093
 *   func_0201BD28 0x0201BD28 thumb
 *   func_0201C1BC 0x0201C1BC thumb
 *   func_021D7B3C 0x021D7B3C thumb ov093
 *   func_021D70E4 0x021D70E4 thumb ov093
 *   func_021E8CFC 0x021E8CFC thumb ov093
 *   func_021E8D04 0x021E8D04 thumb ov093
 *   func_021E8DA8 0x021E8DA8 thumb ov093
 *   func_021D79E8 0x021D79E8 thumb ov093
 *   func_021EF948 0x021EF948 thumb ov093
 *   func_021D5814  0x021D5814  thumb  ov093
 *   func_021C6FB0  0x021C6FB0  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021C88E4  0x021C88E4  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021C70D4  0x021C70D4  thumb  ov093
 *   func_021D794C  0x021D794C  thumb  ov093
 *   func_021CD568  0x021CD568  thumb  ov093
 *   func_021D7BA4  0x021D7BA4  thumb  ov093
 *   func_0201C1D8  0x0201C1D8  thumb
 *   func_0201C1E8 0x0201C1E8 thumb
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D58A8 0x021D58A8 thumb ov093
 *   func_021D5AD8 0x021D5AD8 thumb ov093
 *   func_021C2AB0 0x021C2AB0 thumb ov093
 *   func_021C82B8  0x021C82B8  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021D7B2C  0x021D7B2C  thumb  ov093
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021C7D24 0x021C7D24 thumb ov093
 *   func_021B86A0 0x021B86A0 thumb ov093
 */
#include "../../matched/include/Obj05193.h"
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj21097.h"
#include "../../matched/include/Obj06227.h"
#include "../../matched/include/Obj18306.h"
#include "../../matched/include/Obj07752.h"
#include "../../matched/include/Obj21098.h"
#include "../../matched/include/Obj21099.h"
#include "../../matched/include/Obj13335.h"
#include "../../matched/include/Obj04360.h"
#include "../../matched/include/Obj13336.h"
#include "../../matched/include/Obj01688.h"
#include "../../matched/include/Obj09972.h"
#include "../../matched/include/Obj21104.h"
#include "../../matched/include/Obj07759.h"
#include "../../matched/include/Obj18319.h"
#include "../../matched/include/Obj18320.h"
#include "../../matched/include/Obj18322.h"
#include "../../matched/include/Obj18323.h"

#define OBJECT(i) (*(u8 **)((u32)p + (i) * 16 + 0x7e0))
#define SKIP(i) p[(i) * 16 + 0x7ed]
#define FLAG(i) p[(i) * 16 + 0x7ee]
struct Entry;
struct Obj;
struct Result;
struct S2;
struct Unk021D62A8;
struct UtilWork;
struct UtilSlots;
struct Unk021D5FA4;
struct Arr;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Entry { u32 value; u8 flag; u8 a, b, c, d, e, f, pad; };

struct Slot { u32 kind : 3; u32 rest : 29; };

typedef struct { int x; } S;

typedef struct { u8 *p; u32 type:4; u32 pad:3; u32 key:16; u32 rest:9; u8 bytes[5]; u8 skip; u8 flag; u8 unused; } Entry;

struct O { u16 h; u8 b; };

struct Out64B4 {
    u16 h0;
    u16 h2;
    u16 h4;
    u8 b6;
    u8 pad7;
    u32 w8;
    u32 wC;
    u32 w10;
};

struct Q { u16 h0; u8 pad[6]; u32 w8; };

typedef enum { KIND_NONE, KIND_FIRST, KIND_SECOND } Kind;

/* 021C7CD4  movs r1,#0x7e; lsls r1,#6; ldrh r0,[r0,r1] */
struct Q6 { u8 pad[0x1f80]; u16 v; };

extern u8 func_021D5440(u8 *p);
extern unsigned char func_021B9A40(unsigned int x);
extern u8 func_021B8FF4(u8 *);
extern char *func_021B9AEC(char *p, int i);
extern void func_021CB2D4(u8 *p, char *g, u8 *a, u8 *q);
extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern int func_021D59B4(u8 *p, int k);
extern void func_021CD64C(void *, u8, ...);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021D69B8(struct Obj *p, u32 *remaining, struct Result *r);
extern void func_021BA1CC(char **p, int i, u32 delta);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021BD1D0(u8 *p, u8 n);
extern int func_021C54AC(void *p, int v);
extern u16 func_021D62D8(struct UtilSlots *p, int i);
extern void func_021D61F0(struct UtilSlots *p);
extern struct Slot func_021D6314(u8 *p, int i);
extern int func_021C5698(void *p, int v);
extern void func_021D6238(struct UtilSlots *p, int k);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_021D7E10(struct Unk021D62A8 *p);
extern void func_021CD63C(void *p, int v);
extern u8 func_021D5DC0(s8 *p, int i, u8 n);
extern u8 func_021D5E38(s8 *p, int i, u8 n);
extern void func_021D5FA4(struct Unk021D5FA4 *p, u16 n);
extern int func_021C5BD4(void *p, int v);
extern void func_021D5FB8(u8 *);
extern void func_021D6034(u8 *a, int k, S s);
extern int func_021E8A78(S s);
extern int func_021B911C(void *, int);
extern void func_021D5F90(u8 *, u16);
extern void func_021D56A0(u8 *a, int b, int c);
extern void func_021D5674(u8 *a, int b, int c);
extern void func_021D5FE4(u8 *p, unsigned int n);
extern void func_021D6008(u8 *, unsigned int);
extern void func_021D5FC0(struct UtilWork *, unsigned int);
extern void func_021B9D10(char *, struct Arr *, int);
extern int func_021E02DC(u8 *, u16, u32);
extern void func_021E03D8(u8 *a, int b);
extern void func_021D74F8(int);
extern void func_021D75EC(int, u32);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int);
extern void func_021D75A8(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern int func_021D775C(int key);
extern u32 func_021D7A44(u32 a, u32 b, u32 c, u32 d);
extern u32 func_021D78AC(u32 range);
extern u32 _u32_div_f(u32, u32);
extern int func_021C1678(u8 *p, u8 *a, u8 *b, u32 c, u16 *d);
extern void func_021C16F8(u8 *p, u8 *q, int v);
extern void func_021C8810(u8 *p);
extern u8 sub_0201C1C8(void *p);
extern int sub_0201C1E8(int a);
extern u32 sub_0201BD28(u16 id, u32 field);
extern u16 func_021D57FC(void *p);
extern u32 func_021C6648(u8 *d);
extern u8 *func_021C6658(u8 *d, u32 i);
extern u8 *func_021C6710(u32 a, int b);
extern u32 func_021C6828(u8 *d);
extern u8 *func_021C6838(u8 *d, u32 i);
extern u32 func_021C6928(u8 *d);
extern u8 *func_021C6938(u8 *d, u32 i);
extern u32 func_021D5C08(struct UtilWork *p);
extern u32 sub_0201C1F4(u16 id);
extern void func_021D7674(int key, u32 a, u32 b, u32 c);
extern u32 func_021D7B10(u32 a, u32 b);
extern int func_021BF324(u8 *p, u8 *a, u8 *b);
extern u8 func_021D5F14(struct UtilWork *p);
extern int func_021D7930(int i);
extern u32 sub_0201C284(u16 id);
extern u32 func_0201BD28(u32 v, u32 n);
extern u32 func_0201C1BC(u16);
extern u32 func_021D7B3C(u32, u32);
extern void func_021D70E4(void *a, int id);
extern u8 func_021E8CFC(int);
extern int func_021E8D04(int);
extern int func_021E8DA8(int);
extern int func_021D79E8(int, int);
extern int func_021EF948(int);
extern int func_021D5814(void *p, int k);
extern void func_021C6FB0(u8 *p, u8 *a);
extern u32 func_021CC8D8(void *, int);
extern int func_021C88E4(u8 *p);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021C70D4(u8 *p, u8 *b);
extern int func_021D794C(int a, int b);
extern void func_021CD568(u8 *w, u16 v, u32 id, ...);
extern int func_021D7BA4(int a);
extern u16 func_0201C1D8(void *p);
extern int func_0201C1E8(int a);
extern u8 *func_021B9934(char *p, int i);
extern int func_021D58A8(u8 *, int);
extern int func_021D5AD8(u8 *, int);
extern int func_021C2AB0(u8 *);
extern int func_021C82B8(void *p, int z);
extern int func_021D76BC(int key, u32 val);
extern u32 func_021D7B2C(u32 a, u32 b);
void func_02082BCC(void *, int, u32);
extern u8 func_021B8DDC(u32 x);
extern int func_021B9A24(unsigned int a, unsigned int b);
extern int func_021C7D24(u8 *);
extern int func_021B86A0(unsigned int **, unsigned int);
int func_021C5308(u8 *p, u8 *a);
int func_021C5350(u8 *p, u8 *g, const struct Entry *q);
int func_021C5418(u8 *p, u8 *a, int b);
void *func_021C5474(char *p);
void func_021C5480(u8 *p, u8 *a, int b);
void func_021C54BC(u8 *p, u8 *a);
void func_021C54C8(u8 *p, u8 *a);
void func_021C54FC(u8 *p, u8 *a);
void func_021C5540(u8 *p, u8 *a, int c);
void func_021C557C(u8 *p, u8 *a, int k, int flag);
void func_021C5604(u8 *p, u8 *a, int b);
void func_021C5620(u8 *p, u8 *a, int k, struct Slot *out);
int func_021C56A8(u8 *p, int *pv);
void func_021C5718(u8 *p);
void func_021C572C(u8 *p, u8 *a, u32 v);
void func_021C5750(u8 *p, u8 *a);
void func_021C5774(u8 *p, u8 *a);
void func_021C5798(u8 *p, u16 *a, u32 n, int *arr, u8 **ptrs, u16 *vals, u8 *unused1, int unused2);
void func_021C5840(u8 *p, u32 count, int *v, u8 **a, int flag);
void func_021C59C4(u8 *p, u32 n, u8 **a, u8 *b, int flag);
void func_021C5A1C(u8 *p, u8 *a);
void func_021C5A34(u8 *p, u8 *a);
void func_021C5A4C(u8 *p, u8 *a, int b, int c);
void func_021C5A8C(u8 *p, u8 *a, int c, int d, u16 msg, int flag);
void func_021C5B74(u8 *p, u8 *a, int c, int d);
void func_021C5BE4(u8 *p, u8 *a, int c);
void func_021C5C1C(u8 *p, u8 *a, int k, S s);
void func_021C5C74(u8 *p, u8 *a, int kind, u32 v);
void func_021C5D88(u8 *p, u8 *a, int b);
void func_021C5DAC(u8 *p, u32 a, int n, const int *v);
void func_021C5E48(u8 *p, u32 a, u32 b, int n, int *v);
void func_021C5EFC(u8 *p, u32 a, int n, const int *v);
void func_021C5F98(u8 *p, u32 a, u32 b, int n, int *v);
void func_021C604C(u8 *p, u8 *a, int n);
void func_021C6080(u8 *p, u8 *a, int b, int c, int d);
void func_021C60D4(u8 *p, u8 *a);
void func_021C60EC(u8 *p, u8 *a, u32 n);
void func_021C6110(u8 *p, u8 *a, unsigned int n);
void func_021C6134(u8 *p, u8 *a, unsigned int n);
void func_021C6158(u8 *p, u8 *a);
int func_021C6190(u8 *p, u8 *a);
int func_021C62D8(u8 *p, u8 *a, u32 unused, u32 c, struct O *out);
u8 func_021C6350(u8 *p, u8 *a);
void func_021C6394(u8 *p, u8 *a, unsigned int n);
u32 func_021C63D0(u8 *p, u8 *q);
int func_021C6458(u8 *p, u8 *a, u32 c, u32 d, u8 *e);
void func_021C64B4(u8 *p, u16 q, u8 *a, struct Out64B4 *out);
void func_021C6564(u8 *p, u8 *a, u32 c, u32 d);
int func_021C65A8(u8 *p, u8 *a, u32 e, u8 *d);
int func_021C6668(u8 *p, u8 *a, u8 *a2, u16 a3);
int func_021C66AC(u8 *p, u8 *a, u32 c);
int func_021C6720(u8 *p, u8 *a, u32 c);
int func_021C676C(u8 *p, u8 *a, u8 *d, u16 unused, u8 *out8, u32 *out32);
void func_021C6848(u8 *p, u8 *a);
void func_021C6878(u8 *p, u8 *a, int a2);
int func_021C68A8(u8 *p, u8 *a, u8 *d, u16 a3);
int func_021C6948(u8 *p, u8 *a, u8 *b, u32 v);
int func_021C69B8(u8 *p, u8 *a, u32 c, u16 id);
int func_021C6A04(u8 *p, u8 *a, u8 *b, struct Q *q);
int func_021C6A9C(u8 *p, u8 *a, u8 *b, u16 id);
int func_021C6B5C(u8 *p, u8 *a, u8 *b, u8 *q);
void func_021C6BB8(u8 *p, u8 *a, u8 *b);
int func_021C6BF8(u8 *p, u8 *a, u8 *b, u16 q);
int func_021C6CAC(u8 *p, u8 *a, u16 b, int amount, int *out);
void func_021C6DD0(u8 *p, u8 *a);
void func_021C6E00(u8 *p, u8 *a, u8 k);
int func_021C6E3C(u8 *p, u8 *a, u8 *b, u8 *q, int flag);
int func_021C6F0C(u8 *p, u8 *a, int k);
int func_021C6F34(u8 *p, u8 *a, int f);
void func_021C6FC0(u8 *p, u8 *q);
void func_021C7008(u8 *p, u8 *a);
int func_021C7038(u8 *p, u8 *a, u8 *b, u32 q, u8 s);
void func_021C70E4(u8 *p, int a, int b, int c, int e, u32 f);
int func_021C7194(u8 *p, u8 *a, u32 v);
int func_021C71E0(u8 *p, u8 *a, u32 x, u8 *out);
u16 func_021C728C(u8 *p, u8 *a, u8 *b, u8 *s);
int func_021C7330(u8 *p, u8 *a);
u16 func_021C7374(u8 *p, u8 *a, u8 *b, u8 *c, int flag);
u16 func_021C7474(u8 *p, u8 *a, u8 *b, u8 *c, u32 flag);
int func_021C75EC(u8 *p, u8 *a, int k);
int func_021C7664(u8 *p, u32 x, u8 *a);
int func_021C76F4(u8 *p, u8 *a, u32 k);
void func_021C7780(u8 *p, u8 *a);
int func_021C77B0(u8 *p, u8 *a, u32 b, u32 c, u32 d, u32 e);
void func_021C7820(u8 *p, u8 *a, u32 k);
void func_021C785C(u8 *p, u32 a, u8 *b, u32 c, u32 d);
void func_021C78A8(u8 *p, u8 *a, u32 b, u32 c, u32 d);
u16 func_021C78F4(u8 *p, u8 *a, u8 *b, u32 s);
void func_021C7998(u8 *p, u32 x);
u32 func_021C79E0(u8 *p, u32 x, u8 *a);
int func_021C7A54(u8 *p, u8 *a, u32 c);
void func_021C7AA0(u8 *p, u8 *a);
void func_021C7AD0(u8 *p, u8 *a, u32 k);
void func_021C7B0C(u8 *p, u8 *a);
void func_021C7B3C(u8 *p, u32 a, u16 b, u16 c);
void func_021C7B7C(u8 *p, unsigned int i);
void func_021C7BA8(u8 *p, u8 a, u32 b, u32 c, u32 *out);
void func_021C7BF8(u8 *p);
void func_021C7C18(void *p);
void func_021C7C24(u16 *p, int unused, u8 *b, u8 *c, int e);
u16 func_021C7CBC(u8 *p);
u16 func_021C7CC8(u8 *p);
u16 func_021C7CD4(struct Q6 *p);
u16 func_021C7CDC(u8 *p);
u16 func_021C7CE8(u8 *p);
void *func_021C7CF4(int *p, int i);
int func_021C7D00(u8 *p, int b);











int func_021C5308(u8 *p, u8 *a)
{
    char *g;
    if (func_021B9A40(func_021D5440(a)) == 1) {
        g = func_021B9AEC(*(char * *)&((struct Obj05193 *)p)->f8, func_021B8FF4(*(u8 * *)&((struct Obj05193 *)p)->f4));
        func_021CB2D4(p, g, a, p + 0x1B08);
        return func_021C5350(p, (u8 *)g, (const struct Entry *)(p + 0x1B08));
    }
    return 0;
}











/*
 * lever: const entry source schedules byte arguments early; k precedes entry in declarations.
 */
int func_021C5350(u8 *p, u8 *g, const struct Entry *q)
{
    u32 i;
    int result = 0;
    u8 *a;
    int k;
    u32 value;
    int cmd;
    const struct Entry *entry;
    u32 remaining;
    for (i = 0; i < 6; i++) {
        entry = &q[i];
        if (!entry->value) continue;
        a = (u8 *)func_021B9BF0((struct S2 *)g, (u8)i);
        if (func_021D59B4(a, 15) >= 100) continue;
        value = entry->value;
        cmd = entry->flag ? 0x2b : 0x2a;
        k = func_021D5440(a);
        func_021CD64C(((struct Obj05193 *)p)->fC, 0x5a, (u16)cmd, k, value, 0xffff0000);
        func_021CD4B0(((struct Obj05193 *)p)->fC, 0x3e, k, q->a, q->b, q->c, q->d, q->e, q->f);
        remaining = value;
        while (func_021D69B8((struct Obj *)a, &remaining, (struct Result *)(p + 0x4c0))) {}
        func_021CD4B0(((struct Obj05193 *)p)->fC, 0x45, k, value);
        func_021BA1CC(((struct Obj05193 *)p)->f4, 0x1b, value);
        result = 1;
    }
    return result;
}












int func_021C5418(u8 *p, u8 *a, int b)
{
    u8 n;
    if (func_021D5BDC((struct UtilWork *)a, b)) {
        n = func_021D5440(a);
        func_021C6110(p, a, b);
        b = 0x1a;
        if (func_021D62C4((struct Unk021D62A8 *)a, 0x1a)) {
            func_021C5620(p, a, b, 0);
        }
        func_021CD4B0(((struct Obj00003 *)p)->fC, 0x31, n, 0);
        func_021BD1D0(p, n);
        return 1;
    }
    return 0;
}












void *func_021C5474(char *p)
{
    ((struct Obj21097 *)p)->f220 = 0;
    return p;
}












void func_021C5480(u8 *p, u8 *a, int b)
{
    int r = func_021C54AC(p + 0x1AB8, func_021D5440(a));
    if (r != 6) {
        func_021CD4B0(((struct Obj00003 *)p)->fC, 0x4d, r, b);
    }
}












/*
 * leaf: Sole blocker of func_021BCCE0; ordinary default-argument tail call.
 * extent: Next function 021C54C8 is already separately matched; 12-byte leaf.
 * semantics: Forwards both pointer inputs unchanged; literal argument 0x350.
 */
void func_021C54BC(u8 *p, u8 *a)
{
    func_021C5D88(p, a, 0x350);
}













void func_021C54C8(u8 *p, u8 *a)
{
    func_021C5480(p, a, 0x25B);
    func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x15C, func_021D5440(a), 0xffff0000);
}













void func_021C54FC(u8 *p, u8 *a)
{
    u8 v = func_021D62D8((struct UtilSlots *)a, 7);
    func_021C5480(p, a, 0x25C);
    func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x14d, func_021D5440(a), v, 0xffff0000);
}












void func_021C5540(u8 *p, u8 *a, int c)
{
    int n;
    n = func_021D5440(a);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x36, n);
    func_021C5B74(p, a, (int)(0u - (u32)c), 1);
    func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, 0x50, n, 0xffff0000);
}













void func_021C557C(u8 *p, u8 *a, int k, int flag)
{
    u8 n = func_021D5440(a);
    func_021D61F0((struct UtilSlots *)a);
    func_021CD4B0(((struct Obj06227 *)p)->fC, 0x10, n);
    func_021CD4B0(((struct Obj06227 *)p)->fC, 0x35, n, 0);
    if (flag != 0) {
        switch (k) {
        case 2:
            func_021CD64C(((struct Obj06227 *)p)->fC, 0x5b, 0x138, n, 0xffff0000);
            break;
        case 3:
            func_021CD64C(((struct Obj06227 *)p)->fC, 0x5b, 0x126, n, 0xffff0000);
            break;
        default:
            func_021CD64C(((struct Obj06227 *)p)->fC, 0x5b, 0x156, n, 0xffff0000);
            break;
        }
    }
}













void func_021C5604(u8 *p, u8 *a, int b)
{
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x59, func_021D5440(a), b);
}










void func_021C5620(u8 *p, u8 *a, int k, struct Slot *out)
{
    u8 n;
    if (k != 0) {
        n = func_021D5440(a);
        if (out != 0) *out = func_021D6314(a, k);
        if (k < 6) {
            func_021D61F0((struct UtilSlots *)a);
            func_021CD4B0(((struct Obj00003 *)p)->fC, 0x10, n);
            if (func_021C5698(p + 0x1AB8, n) != 6) {
                func_021CD4B0(((struct Obj00003 *)p)->fC, 0x35, n, 0);
            }
        } else {
            func_021D6238((struct UtilSlots *)a, k);
            func_021CD4B0(((struct Obj00003 *)p)->fC, 0x11, n, (u16)k);
        }
    }
}











int func_021C56A8(u8 *p, int *pv)
{
    int ret = 0;
    int r = func_021D62A8((struct Unk021D62A8 *)p);
    int t;
    switch (*pv) {
    case 0:
        break;
    case 0x24:
        if (r) ret = r;
        *pv = 0;
        break;
    case 0x25:
        if (r) {
            ret = r;
            *pv = 6;
        } else {
            if (func_021D62C4((struct Unk021D62A8 *)p, 6)) ret = 6;
            *pv = 0;
        }
        break;
    case 0x26:
        t = func_021D7E10((struct Unk021D62A8 *)p);
        if (t) return t;
        *pv = ret;
        return t;
    default:
        if (func_021D62C4((struct Unk021D62A8 *)p, *pv)) ret = *pv;
        *pv = 0;
        break;
    }
    return ret;
}











/* 021C5718  4-arg call, field 0xc and the pool constant 0xffff0000 */
void func_021C5718(u8 *p)
{
    func_021CD64C((void *)(((struct Obj18306 *)p)->fC), 0x5a, 0x47, 0xffff0000);
}













void func_021C572C(u8 *p, u8 *a, u32 v)
{
    func_021CD64C(((struct Obj07752 *)p)->fC, 0x5b, 213, func_021D5440(a), 0xffff0000);
}













void func_021C5750(u8 *p, u8 *a)
{
    func_021CD64C(((struct Obj21098 *)p)->fC, 0x5b, 210, func_021D5440(a), 0xffff0000);
}













void func_021C5774(u8 *p, u8 *a)
{
    func_021CD64C(((struct Obj21099 *)p)->fC, 0x5b, 216, func_021D5440(a), 0xffff0000);
}














void func_021C5798(u8 *p, u16 *a, u32 n, int *arr, u8 **ptrs, u16 *vals, u8 *unused1, int unused2)
{
    u32 i;
    u8 hi;
    u8 lo;
    int k;
    lo = 0;
    hi = 0;
    for (i = 0; i < n; i++) {
        func_021C604C(p, ptrs[i], vals[i]);
        if (arr[i] > 3) hi++;
        if (arr[i] < 3) lo++;
    }
    if (hi) k = 2;
    else if (lo) k = 3;
    else k = 1;
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x33, (u8)n, (u8)k, *a);
    for (i = 0; i < n; i++) {
        func_021CD63C(((struct Obj00003 *)p)->fC, func_021D5440(ptrs[i]));
    }
}













void func_021C5840(u8 *p, u32 count, int *v, u8 **a, int flag)
{
    u8 low = 0;
    u8 high = 0;
    u32 i;
    u8 list[3];
    for (i = 0; i < count; i++) {
        if (v[i] > 3) high++;
        if (v[i] < 3) low++;
    }
    if (flag) {
        if (high) {
            u8 n = 0;
            for (i = 0; i < count; i++) {
                if (v[i] > 3) list[n++] = func_021D5440(a[i]);
            }
            switch (high) {
            case 1: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 6, list[0], 0xffff0000); break;
            case 2: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 9, list[0], list[1], 0xffff0000); break;
            case 3: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 12, list[0], list[1], list[2], 0xffff0000); break;
            }
        }
        if (low) {
            u8 n;
            i = 0;
            n = 0;
            for (; i < count; i++) {
                if (v[i] < 3) list[n++] = func_021D5440(a[i]);
            }
            switch (low) {
            case 1: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 15, list[0], 0xffff0000); break;
            case 2: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 18, list[0], list[1], 0xffff0000); break;
            case 3: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 21, list[0], list[1], list[2], 0xffff0000); break;
            }
        }
    } else {
        if (high) func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, 78, 0xffff0000);
        else if (low) func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, 79, 0xffff0000);
    }
}














void func_021C59C4(u8 *p, u32 n, u8 **a, u8 *b, int flag)
{
    u32 i;
    for (i = 0; i < n; i++) {
        if (b[i]) {
            if (flag) {
                func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x180, func_021D5440(a[i]), 0xffff0000);
            } else {
                func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, 0x51, 0xffff0000);
            }
        }
    }
}












void func_021C5A1C(u8 *p, u8 *a)
{
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x57, func_021D5440(a));
}












void func_021C5A34(u8 *p, u8 *a)
{
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x58, func_021D5440(a));
}













void func_021C5A4C(u8 *p, u8 *a, int b, int c)
{
    u8 n = func_021D5440(a);
    if (c > 0) {
        func_021CD64C(((struct Obj13335 *)p)->fC, 0x5b, 0x99, n, b, 0xffff0000);
    } else {
        func_021CD64C(((struct Obj13335 *)p)->fC, 0x5b, 0xae, n, b, 0xffff0000);
    }
}











void func_021C5A8C(u8 *p, u8 *a, int c, int d, u16 msg, int flag)
{
    u8 n = func_021D5440(a);
    if (d > 0) {
        int x = func_021D5DC0((s8 *)a, c, d);
        u8 t = x;
        func_021CD4B0(((struct Obj04360 *)p)->fC, 9, n, (u8)c, t);
        func_021CD4B0(((struct Obj04360 *)p)->fC, 0x37, n, (u8)c, t);
        if (flag) {
            if (msg == 0) func_021CD64C(((struct Obj04360 *)p)->fC, 0x5b, 0x1b, n, c, x, 0xffff0000);
            else func_021CD64C(((struct Obj04360 *)p)->fC, 0x5b, 0x3aa, n, msg, c, x, 0xffff0000);
        }
    } else {
        int x = func_021D5E38((s8 *)a, c, -d);
        u8 t = x;
        func_021CD4B0(((struct Obj04360 *)p)->fC, 10, n, (u8)c, t);
        func_021CD4B0(((struct Obj04360 *)p)->fC, 0x38, n, (u8)c, t);
        func_021CD64C(((struct Obj04360 *)p)->fC, 0x5b, 0x5a, n, c, x, 0xffff0000);
    }
}












void func_021C5B74(u8 *p, u8 *a, int c, int d)
{
    u8 n = func_021D5440(a);
    if (c > 0) {
        func_021D5FA4((struct Unk021D5FA4 *)a, (u16)c);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 2, n, (u16)c);
    } else if (c < 0) {
        func_021C604C(p, a, -c);
    }
    if (d) {
        if (func_021C5BD4(p + 0x1AB8, n) != 6) {
            func_021CD4B0(((struct Obj00003 *)p)->fC, 0x41, n);
        }
    }
}










void func_021C5BE4(u8 *p, u8 *a, int c)
{
    int n;
    func_021D59B4(a, 13);
    n = func_021D5440(a);
    func_021D5FB8(a);
    func_021CD4B0(((struct Obj13336 *)p)->fC, 3, n);
    func_021CD4B0(((struct Obj13336 *)p)->fC, 0x43, n, c);
}











void func_021C5C1C(u8 *p, u8 *a, int k, S s)
{
    u8 n = func_021D5440(a);
    func_021D6034(a, k, s);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0xf, n, (u8)k, s.x);
    if (k < 6) {
        if (k == 5 && func_021E8A78(s)) k = 6;
        func_021CD4B0(((struct Obj00003 *)p)->fC, 0x35, n, k);
    }
}










void func_021C5C74(u8 *p, u8 *a, int kind, u32 v)
{
    u8 n = func_021D5440(a);
    switch (kind) {
    case 1:
        switch (v) {
        case 5: func_021CD64C(((struct Obj01688 *)p)->fC, 0x5b, 0xf9, n, 0xffff0000); break;
        case 4: func_021CD64C(((struct Obj01688 *)p)->fC, 0x5b, 0x10b, n, 0xffff0000); break;
        case 1: func_021CD64C(((struct Obj01688 *)p)->fC, 0x5b, 0x11a, n, 0xffff0000); break;
        case 2: func_021CD64C(((struct Obj01688 *)p)->fC, 0x5b, 0x13b, n, 0xffff0000); break;
        case 3: func_021CD64C(((struct Obj01688 *)p)->fC, 0x5b, 0x129, n, 0xffff0000); break;
        case 6: func_021CD64C(((struct Obj01688 *)p)->fC, 0x5b, 0x162, n, 0xffff0000); break;
        case 15: func_021CD64C(((struct Obj01688 *)p)->fC, 0x5b, 0x18, n, 0xffff0000); break;
        case 20: return;
        default: func_021CD64C(((struct Obj01688 *)p)->fC, 0x5a, 0x47, 0xffff0000); break;
        }
        p[0x78a] |= 0x10;
        break;
    case 2:
        func_021CD64C(((struct Obj01688 *)p)->fC, 0x5b, 0xd2, n, 0xffff0000);
        p[0x78a] |= 0x10;
        break;
    default:
        func_021CD64C(((struct Obj01688 *)p)->fC, 0x5a, 0x47, 0xffff0000);
        p[0x78a] |= 0x10;
        break;
    }
}











void func_021C5D88(u8 *p, u8 *a, int b)
{
    func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, b, func_021D5440(a), 0xffff0000);
}











void func_021C5DAC(u8 *p, u32 a, int n, const int *v)
{
    switch (n) {
    default:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, a, 0xffff0000);
        break;
    case 1:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, a, v[0], 0xffff0000);
        break;
    case 2:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, a, v[0], v[1], 0xffff0000);
        break;
    case 3:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, a, v[0], v[1], v[2], 0xffff0000);
        break;
    case 4:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, a, v[0], v[1], v[2], v[3], 0xffff0000);
        break;
    }
}











void func_021C5E48(u8 *p, u32 a, u32 b, int n, int *v)
{
    switch (n) {
    default:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5c, a, b, 0xffff0000);
        break;
    case 1:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5c, a, b, v[0], 0xffff0000);
        break;
    case 2:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5c, a, b, v[0], v[1], 0xffff0000);
        break;
    case 3:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5c, a, b, v[0], v[1], v[2], 0xffff0000);
        break;
    case 4:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5c, a, b, v[0], v[1], v[2], v[3], 0xffff0000);
        break;
    }
}











void func_021C5EFC(u8 *p, u32 a, int n, const int *v)
{
    switch (n) {
    default:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, a, 0xffff0000);
        break;
    case 1:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, a, v[0], 0xffff0000);
        break;
    case 2:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, a, v[0], v[1], 0xffff0000);
        break;
    case 3:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, a, v[0], v[1], v[2], 0xffff0000);
        break;
    case 4:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, a, v[0], v[1], v[2], v[3], 0xffff0000);
        break;
    }
}











void func_021C5F98(u8 *p, u32 a, u32 b, int n, int *v)
{
    switch (n) {
    default:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5d, a, b, 0xffff0000);
        break;
    case 1:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5d, a, b, v[0], 0xffff0000);
        break;
    case 2:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5d, a, b, v[0], v[1], 0xffff0000);
        break;
    case 3:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5d, a, b, v[0], v[1], v[2], 0xffff0000);
        break;
    case 4:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5d, a, b, v[0], v[1], v[2], v[3], 0xffff0000);
        break;
    }
}










void func_021C604C(u8 *p, u8 *a, int n)
{
    if (func_021B911C(((struct Obj00003 *)p)->f4, 4) == 0) {
        func_021D5F90(a, n);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 1, func_021D5440(a), (u16)n);
    }
}











void func_021C6080(u8 *p, u8 *a, int b, int c, int d)
{
    u8 n = func_021D5440(a);
    if (d) {
        func_021D56A0(a, b, c);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 8, n, b, c);
    } else {
        func_021D5674(a, b, c);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 7, n, b, c);
    }
}










void func_021C60D4(u8 *p, u8 *a)
{
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x42, func_021D5440(a));
}










void func_021C60EC(u8 *p, u8 *a, u32 n)
{
    func_021D5FE4(a, n);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x19, func_021D5440(a), n);
}










void func_021C6110(u8 *p, u8 *a, unsigned int n)
{
    func_021D6008(a, n);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x1a, func_021D5440(a), n);
}










void func_021C6134(u8 *p, u8 *a, unsigned int n)
{
    func_021D5FC0((struct UtilWork *)a, n);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x1b, func_021D5440(a), n);
}










void func_021C6158(u8 *p, u8 *a)
{
    unsigned int i;
    struct Arr *arr;
    for (i = 0; i < a[0]; i++) {
        arr = (struct Arr *)func_021B9AEC(*(char * *)&((struct Obj09972 *)p)->f8, a[i + 1]);
        func_021CD4B0(((struct Obj09972 *)p)->fC, 0x2a, a[i + 1]);
        func_021B9D10(*(char * *)&((struct Obj09972 *)p)->f4, arr, a[i + 1]);
    }
}










static inline u16 entry_key(Entry *e)
{
    if (e->type == 1) return e->key;
    return 0;
}










int func_021C6190(u8 *p, u8 *a)
{
    u32 i;
    for (i = 0; i < p[0x782]; i++) {
        u16 key;
        if (OBJECT(i) == a) continue;
        if (SKIP(i)) continue;
        key = entry_key((Entry *)(p + 0x7e0) + i);
        if (key == 228) {
            if (func_021E02DC(OBJECT(i), key, func_021D59B4(OBJECT(i), 12)))
                FLAG(i) = 1;
        }
    }
    p[0x788] = 0;
    func_021D74F8(11288);
    func_021D75EC(6, func_021D5440(a));
    func_021D70F0(p, 0x53);
    func_021D7540(11291);
    for (i = 0; i < p[0x782]; i++) {
        u16 key;
        if (FLAG(i)) {
            key = entry_key((Entry *)(p + 0x7e0) + i);
            if (key == 228) func_021E03D8(*(u8 **)(p + i * 16 + 0x7e0), key);
            FLAG(i) = 0;
        }
    }
    return p[0x788];
}










int func_021C62D8(u8 *p, u8 *a, u32 unused, u32 c, struct O *out)
{
    int t;
    int line = 11327;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0xE, c);
    func_021D75A8(0x12, 0);
    func_021D75A8(0xD, 6);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x18);
    out->h = func_021D775C(0x12);
    out->b = func_021D775C(0xD);
    t = func_021D775C(0x41);
    func_021D7540(line + 13);
    return t == 0;
}










u8 func_021C6350(u8 *p, u8 *a)
{
    u8 r;
    func_021D74F8(11357);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x11, 1);
    func_021D70F0(p, 0xF);
    r = func_021D775C(0x11);
    func_021D7540(11362);
    return r;
}









void func_021C6394(u8 *p, u8 *a, unsigned int n)
{
    func_021D74F8(11378);
    func_021D75A8(2, func_021D5440(a));
    func_021D75A8(0x12, n);
    func_021D70F0(p, 0x15);
    func_021D7540(11382);
}










u32 func_021C63D0(u8 *p, u8 *q)
{
    u16 dmg;
    int r;
    int a = func_021D59B4(q, 8);
    int b = func_021D59B4(q, 9);
    int c = func_021D59B4(q, 0xF);

    dmg = func_021D7A44(0x28, a, c, b);
    dmg = _u32_div_f((100 - func_021D78AC(16)) * dmg, 100);
    if (dmg == 0) {
        dmg = 1;
    }
    r = func_021C1678(p, q, q, 0, &dmg);
    func_021C5540(p, q, dmg);
    if (r != 0) {
        func_021C16F8(p, q, r);
    }
    return dmg;
}










int func_021C6458(u8 *p, u8 *a, u32 c, u32 d, u8 *e)
{
    int r;
    int line = 11440;
    func_021C8810(e);
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x12, d);
    func_021D75EC(0x3F, (u32)e);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x19);
    r = func_021D775C(0x51);
    func_021D7540(line + 7);
    return r;
}










/*
 * Byte-correct except the call to the unlabelled arm9 leaf 0x0201C1E8,
 * which has no witness outside this function (evidence class: none until the
 * leaf is filed; it is Ilias's, inside a labelled arm9 region). Verified C for
 * that leaf (`one` --thumb, no --region, EXACT, 12 bytes):
 *
 *   extern u32 sub_0201BD28(void *p, u32 id);   // symbols: sub_0201BD28 0x0201BD28 thumb
 *   u32 sub_0201C1E8(void *p) { return sub_0201BD28(p, 2); }
 *
 * Once the leaf's shard exists re-run this file; it should go EXACT.
 */
void func_021C64B4(u8 *p, u16 q, u8 *a, struct Out64B4 *out)
{
    int line = 11464;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x16, sub_0201C1C8((void *)q));
    func_021D75A8(0x1C, func_021D57FC(a));
    func_021D75A8(0x1A, sub_0201C1E8(q));
    func_021D75A8(0x1B, sub_0201BD28(q, 0x1B));
    func_021D7630(0x4B, 0);
    func_021D70F0(p, 0x28);
    out->h0 = q;
    out->h2 = q;
    out->b6 = func_021D775C(0x16);
    out->h4 = func_021D775C(0x1C);
    out->w8 = func_021D775C(0x1A);
    out->wC = func_021D775C(0x1B);
    out->w10 = 0;
    if (func_021D775C(0x4B) != 0) {
        out->b6 = 0x11;
    }
    func_021D7540(11493);
}










void func_021C6564(u8 *p, u8 *a, u32 c, u32 d)
{
    func_021D74F8(11508);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x12, c);
    func_021D75EC(0x22, d);
    func_021D70F0(p, 0x21);
    func_021D7540(11513);
}










int func_021C65A8(u8 *p, u8 *a, u32 e, u8 *d)
{
    u32 n;
    u32 i;
    int r;
    u16 t;
    n = func_021C6648(d);
    func_021D74F8(11533);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x12, e);
    func_021D75EC(5, n);
    for (i = 0; i < n; i++) {
        func_021D75EC(i + 6, func_021D5440(func_021C6658(d, i)));
    }
    func_021D7630(0x3E, 0);
    func_021D7630(0x13, 0);
    func_021D70F0(p, 0x24);
    r = func_021D775C(0x3E);
    t = func_021D775C(0x13);
    func_021D7540(11550);
    if (t != 0) {
        **(u16 * *)&((struct Obj21104 *)p)->f4A8 = t;
    }
    return r;
}








int func_021C6668(u8 *p, u8 *a, u8 *a2, u16 a3)
{
    int r;
    func_021D74F8(11574);
    func_021D75A8(3, func_021D5440(a));
    func_021D75A8(0x51, 0);
    func_021D70F0(p, 0x2E);
    r = func_021D775C(0x51);
    func_021D7540(11579);
    return r;
}








int func_021C66AC(u8 *p, u8 *a, u32 c)
{
    u8 *q;
    int r;
    q = func_021C6710(c, 0);
    func_021D74F8(11599);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, q ? func_021D5440(q) : 0x1F);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x93);
    r = func_021D775C(0x41);
    func_021D7540(11605);
    return r;
}







int func_021C6720(u8 *p, u8 *a, u32 c)
{
    int r;
    func_021D74F8(11622);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, c);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x94);
    r = func_021D775C(0x51);
    func_021D7540(11628);
    return r;
}







int func_021C676C(u8 *p, u8 *a, u8 *d, u16 unused, u8 *out8, u32 *out32)
{
    u32 n;
    u32 i;
    int t;
    n = func_021C6828(d);
    func_021D74F8(11648);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(5, n);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            func_021D75EC(i + 6, func_021D5440(func_021C6838(d, i)));
        }
    } else {
        func_021D75EC(6, 0x1F);
    }
    func_021D7630(0x41, 0);
    func_021D7630(0x51, 0);
    func_021D7630(0x4F, 0);
    func_021D70F0(p, 0x95);
    if (func_021D775C(0x51) != 0) {
        *out8 = func_021D775C(6);
    } else {
        *out8 = 0x1F;
    }
    *out32 = func_021D775C(0x4F);
    t = func_021D775C(0x41);
    func_021D7540(11677);
    return t == 0;
}






void func_021C6848(u8 *p, u8 *a)
{
    func_021D74F8(11692);
    func_021D75EC(3, func_021D5440(a));
    func_021D70F0(p, 0x96);
    func_021D7540(11695);
}






void func_021C6878(u8 *p, u8 *a, int a2)
{
    func_021D74F8(11709);
    func_021D75EC(3, func_021D5440(a));
    func_021D70F0(p, 0x97);
    func_021D7540(11712);
}






int func_021C68A8(u8 *p, u8 *a, u8 *d, u16 a3)
{
    u32 n;
    u32 i;
    u8 t;
    n = func_021C6928(d);
    func_021D74F8(11731);
    func_021D75EC(3, func_021D5440(a));
    func_021D7630(0x41, 0);
    func_021D75EC(5, n);
    for (i = 0; i < n; i++) {
        func_021D75EC(i + 6, func_021D5440(func_021C6938(d, i)));
    }
    func_021D70F0(p, 0x98);
    t = func_021D775C(0x41);
    func_021D7540(11742);
    return t == 0;
}







int func_021C6948(u8 *p, u8 *a, u8 *b, u32 v)
{
    int r = 0;
    u32 t = func_021D5C08((struct UtilWork *)b);
    if (t != 0x10) {
        func_021D74F8(11765);
        func_021D75EC(3, func_021D5440(a));
        func_021D75EC(4, func_021D5440(b));
        func_021D75EC(0x21, t);
        func_021D7630(0x42, 1);
        func_021D70F0(p, 0x99);
        if (func_021D775C(0x42)) r = 1;
        func_021D7540(11775);
    }
    return r;
}








int func_021C69B8(u8 *p, u8 *a, u32 c, u16 id)
{
    int r = sub_0201C1F4(id);
    if (r == 0) {
        func_021D74F8(0x2E15);
        func_021D75EC(3, func_021D5440(a));
        func_021D7630(0x51, 0);
        func_021D70F0(p, 0x32);
        r = func_021D775C(0x51);
        func_021D7540(0x2E1A);
    }
    return r;
}








int func_021C6A04(u8 *p, u8 *a, u8 *b, struct Q *q)
{
    int x, y;
    u32 t = sub_0201BD28(q->h0, 4);
    func_021D74F8(0x2E2F);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x12, q->h0);
    func_021D75EC(0x1a, q->w8);
    func_021D7630(0x2b, t);
    func_021D7674(0x35, 4 << 10, 0x19A, 4 << 15);
    func_021D70F0(p, 0x34);
    x = func_021D775C(0x2b);
    y = func_021D775C(0x35);
    func_021D7540(0x2E39);
    return func_021D7B10(x, y);
}








int func_021C6A9C(u8 *p, u8 *a, u8 *b, u16 id)
{
    u8 x, y, c;
    int r, t;
    x = func_021D59B4(a, 15);
    y = func_021D59B4(b, 15);
    if (x < y) return 0;
    func_021D74F8(0x2E5A);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    r = 0;
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x70);
    t = func_021D775C(0x41);
    func_021D7540(0x2E60);
    if (t) return r;
    if (func_021BF324(p, a, b)) {
        r = 1;
    } else {
        c = sub_0201BD28(id, 4);
        c += (u8)(x - y);
        if (func_021D78AC(100) < c) r = 1;
    }
    return r;
}








int func_021C6B5C(u8 *p, u8 *a, u8 *b, u8 *q)
{
    int r;
    func_021D74F8(11907);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x16, q[6]);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x30);
    r = func_021D775C(0x51);
    func_021D7540(11914);
    return r;
}








void func_021C6BB8(u8 *p, u8 *a, u8 *b)
{
    func_021D74F8(11928);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D70F0(p, 0x31);
    func_021D7540(11932);
}








#pragma opt_lifetimes off







/*
 * note 2026-10-05 (wave P13 B10): the older DIFF (12 B, p and h/r in each other's
 *   r4/r5) closed with #pragma opt_lifetimes off around the function, see
 *   docs/idioms/a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off.md.
 *   Source is unchanged from the old draft. Plain literals already (11952, 0x2c).
 *   Callees: func_021D5F14 returns u8, func_021D7930 takes u8 (both matched);
 *   sub_0201BD28 and sub_0201C284 return u32 (matched arm9 units).
 */
int func_021C6BF8(u8 *p, u8 *a, u8 *b, u16 q)
{
    int r, n;
    u16 h;
    h = sub_0201BD28(q, 7);
    h = h + func_021D5F14((struct UtilWork *)a);
    func_021D74F8(11952);
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(3, func_021D5440(a));
    func_021D75A8(0x2c, h);
    r = 0;
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x36);
    if (func_021D775C(0x41) == 0) {
        if (sub_0201C284(q)) {
            r = 1;
        } else {
            n = func_021D775C(0x2c);
            if (n > 4) n = 4;
            r = func_021D7930((u8)((u16)n));
        }
        if (func_021B911C((void *)(*(int *)(p + 4)), 3)) r = 1;
    }
    func_021D7540(11975);
    return r;
}








#pragma opt_lifetimes reset







/*
 * note 2026-10-05 (wave P8): earlier DIFF (288 vs 292 B) closed by local declaration
 *   order (line, n, v, t, y, z, x, then kind); spill slots follow it. Plain literals
 *   12019 and 12032 are EXACT, so no line local. Also EXACT with --lang c.
 */
int func_021C6CAC(u8 *p, u8 *a, u16 b, int amount, int *out)
{
    u8 n, v;
    u8 t, y, z, x;
    int kind;
    n = func_021D5440(a);
    v = func_0201BD28((u32)b, 30);
    kind = 0;
    *out = kind;
    if (v) kind = KIND_FIRST;
    else {
        v = func_0201BD28((u32)b, 31);
        if (v) kind = KIND_SECOND;
    }
    if (func_0201C1BC(b) == 8) return 0;
    func_021D74F8(12019);
    func_021D75EC(3, n);
    func_021D75A8(0x35, v);
    func_021D75A8(0x36, 0);
    func_021D7630(0x41, 0);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x50);
    x = func_021D775C(0x35);
    y = func_021D775C(0x41);
    z = func_021D775C(0x51);
    t = func_021D775C(0x36);
    func_021D7540(12032);
    if (z == 0 && y == 1) return 0;
    x += t;
    if (x) {
        if (kind == KIND_SECOND) {
            amount = func_021D7B3C(func_021D59B4(a, 14), x);
            if (amount < 1) amount = 1;
        } else if (amount != 0) {
            amount = func_021D7B3C(amount, x);
            if (amount < 1) amount = 1;
        }
        *out = z;
        return amount;
    }
    return 0;
}






void func_021C6DD0(u8 *p, u8 *a)
{
    int line = 12077;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D70F0(p, 114);
    func_021D7540(line + 3);
}






void func_021C6E00(u8 *p, u8 *a, u8 k)
{
    int line = 12093;
    func_021D74F8(line);
    func_021D75A8(2, func_021D5440(a));
    func_021D75A8(3, k);
    func_021D70E4(p, 115);
    func_021D7540(line + 4);
}






int func_021C6E3C(u8 *p, u8 *a, u8 *b, u8 *q, int flag)
{
    int r, x;
    int changed = 0;
    if (q[6] == 17) return 3;
    x = func_021D57FC(b);
    r = func_021C7038(p, a, b, q[6], func_021E8CFC(x));
    if (func_021E8DA8(x) == 0)
        r = func_021D79E8(r, func_021C7038(p, a, b, q[6], func_021E8D04(x)));
    if (r != 0) {
        if (q[6] != 4) return r;
        changed = func_021C6F0C(p, b, 0);
        if (changed == 0) return r;
        r = 0;
    } else if (q[6] == 4) {
        if (func_021C6F0C(p, b, 1) == 0) return 3;
    }
    if (r == 0 && flag != 0) {
        if (changed == 0) func_021C5750(p, b);
        else func_021C6FC0(p, b);
    }
    return r;
}






int func_021C6F0C(u8 *p, u8 *a, int k)
{
    if (func_021EF948(2) == 0 && func_021C6F34(p, a, k) != 0)
        return 1;
    return 0;
}





int func_021C6F34(u8 *p, u8 *a, int f)
{
    int t;
    u8 x, y;
    if (f) {
        t = func_021D5814(a, 2);
    } else {
        t = 0;
    }
    func_021D74F8(12220);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x51, (u8)t);
    func_021D7630(0x41, (u8)0);
    func_021D70F0(p, 0x12);
    func_021C6FB0(p, a);
    x = func_021D775C(0x51);
    y = func_021D775C(0x41);
    func_021D7540(12228);
    if (y) return 0;
    return x;
}




void func_021C6FC0(u8 *p, u8 *q)
{
    u32 v = func_021CC8D8(p + 0x1D74, 12246);
    func_021C7008(p, q);
    if (func_021C88E4(p) != 2) func_021C5750(p, q);
    func_021CC95C((u32 *)(p + 0x1D74), v, 12253);
}




void func_021C7008(u8 *p, u8 *a)
{
    int line = 12265;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D70F0(p, 27);
    func_021D7540(line + 3);
}





int func_021C7038(u8 *p, u8 *a, u8 *b, u32 q, u8 s)
{
    int x, y, r;
    func_021D74F8(12290);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x15, s);
    func_021D75EC(0x16, q);
    func_021D7630(0x4b, 0);
    func_021D7630(0x4c, 0);
    func_021C70D4(p, b);
    func_021D70F0(p, 0x3e);
    x = func_021D775C(0x4b);
    y = func_021D775C(0x4c);
    func_021D7540(12303);
    if (y) return 3;
    r = func_021D794C(q, s);
    if (r == 0 && x) r = 3;
    return r;
}





void func_021C70E4(u8 *p, int a, int b, int c, int e, u32 f)
{
    int m;
    if (c != 6) {
        m = 2;
    } else {
        m = 1;
        if (b == 6) m = 0;
    }
    if (e) {
        switch (m) {
        case 0: func_021CD568(*(u8 * *)&((struct Obj00003 *)p)->fC, f, 0x4c, a); return;
        case 1: func_021CD568(*(u8 * *)&((struct Obj00003 *)p)->fC, f, 0x4d, b, a); return;
        case 2: func_021CD568(*(u8 * *)&((struct Obj00003 *)p)->fC, f, 0x4e, b, c, a); return;
        }
    } else {
        switch (m) {
        case 0: func_021CD4B0(*(u8 * *)&((struct Obj00003 *)p)->fC, 0x4c, a); return;
        case 1: func_021CD4B0(*(u8 * *)&((struct Obj00003 *)p)->fC, 0x4d, b, a); return;
        case 2: func_021CD4B0(*(u8 * *)&((struct Obj00003 *)p)->fC, 0x4e, b, c, a); return;
        }
    }
}





int func_021C7194(u8 *p, u8 *a, u32 v)
{
    int r;
    func_021D74F8(12399);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x17, v);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x4f);
    r = func_021D775C(0x51);
    func_021D7540(12405);
    return r;
}





int func_021C71E0(u8 *p, u8 *a, u32 x, u8 *out)
{
    u8 id = func_0201BD28(x, 8);
    u32 r;

    out[1] = 0;
    out[5] = 3;
    if (id > 1) {
        r = func_021D7BA4(id);
        func_021D74F8(12432);
        func_021D75EC(3, func_021D5440(a));
        func_021D75EC(0x29, id);
        func_021D75A8(0x2a, r);
        func_021D7630(0x51, 0);
        func_021D7630(0x42, 0);
        func_021D70F0(p, 0x35);
        if (id <= 5 && func_021D775C(0x51) != 0) {
            out[0] = id;
            out[2] = 0;
        } else {
            out[0] = func_021D775C(0x2a);
            out[2] = func_021D775C(0x42);
        }
        out[3] = 1;
        func_021D7540(12455);
        return 1;
    }
    out[0] = 1;
    out[2] = 0;
    out[3] = 0;
    return 0;
}





u16 func_021C728C(u8 *p, u8 *a, u8 *b, u8 *s)
{
    u32 t = func_0201C1D8((void *)(((struct Obj07759 *)s)->f0));
    u16 x;
    u32 y;

    func_021D74F8(12487);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x12, ((struct Obj07759 *)s)->f0);
    func_021D75EC(0x16, s[6]);
    func_021D75EC(0x1a, ((struct Obj07759 *)s)->f8);
    func_021D7630(0x30, t);
    func_021D70F0(p, 0x37);
    func_021D7674(0x31, 0x1000, 0x29, 0x200000);
    func_021D70F0(p, 0x38);
    x = func_021D775C(0x30);
    y = func_021D775C(0x31);
    func_021D7540(12500);
    return func_021D7B10(x, y);
}





int func_021C7330(u8 *p, u8 *a)
{
    int r;
    func_021D74F8(12521);
    func_021D75EC(4, func_021D5440(a));
    func_021D7630(0x51, 1);
    func_021D70F0(p, 0x80);
    r = func_021D775C(0x51);
    func_021D7540(12526);
    return r;
}





/*
 *   no witness outside this caller (7374-r2.log). Verified blocker C copied
 *   from ov093_func_021C1E74.c, whose header records its EXACT compile:
 *   typedef unsigned short u16; typedef unsigned int u32;
 *   extern u32 sub_0201BD28(u16, u32);
 * lever: bind the category call result before initialising k to prevent
 *   its constant assignment moving before the call.
 */
u16 func_021C7374(u8 *p, u8 *a, u8 *b, u8 *c, int flag)
{
    int k;
    u16 value;
    u8 index;
    int mode = func_0201C1E8(*(u16 *)c);
    k = 10;
    if (mode != 2) k = 8;
    func_021D74F8(12542);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75A8(0x3b, 0x1f);
    func_021D75A8(0x51, 0);
    func_021D70F0(p, 0x39);
    index = func_021D775C(0x3b);
    if (index != 0x1f) a = (u8 *)func_021B9934(*(char **)(p + 8), index);
    if (func_021D775C(0x51)) value = func_021D58A8(a, k);
    else if (flag) value = func_021D5AD8(a, k);
    else value = func_021D59B4(a, k);
    func_021D75EC(0x12, *(u16 *)c);
    func_021D75EC(0x16, c[6]);
    func_021D75EC(0x1a, *(u32 *)(c + 8));
    func_021D75A8(0x33, value);
    func_021D7674(0x35, 1 << 12, 410, 1 << 17);
    func_021D70F0(p, 0x3b);
    value = func_021D775C(0x33);
    value = func_021D7B10(value, func_021D775C(0x35));
    func_021D7540(12579);
    return value;
}





/*
 *   no witness outside this caller (7474-r1.log). Verified blocker C copied
 *   from ov093_func_021C1E74.c, whose header records its EXACT compile:
 *   typedef unsigned short u16; typedef unsigned int u32;
 *   extern u32 sub_0201BD28(u16, u32);
 */
u16 func_021C7474(u8 *p, u8 *a, u8 *b, u8 *c, u32 flag)
{
    int k;
    u32 field;
    u16 value;
    u8 other;
    int scale;
    int mode = func_0201C1E8(*(u16 *)c);
    k = 11;
    if (mode != 2) k = 9;
    field = *(u32 *)(c + 8);
    func_021D74F8(12595);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x3c, k);
    func_021D75A8(0x3d, 0);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x3a);
    if (func_021D775C(0x3d) & 1) {
        if (k == 9) k = 11;
        else k = 9;
        if (k == 9) field = 1;
        else field = 2;
    }
    other = func_021D775C(0x51);
    func_021D7540(12610);
    if (other) value = func_021D58A8(b, k);
    else if (flag) value = func_021D5AD8(b, k);
    else value = func_021D59B4(b, k);
    if (func_021C2AB0(p) == 4 && func_021D5814(b, 5) && k == 11)
        value = func_021D7B10(value, 6 << 10);
    func_021D74F8(12631);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x12, *(u16 *)c);
    func_021D75EC(0x16, c[6]);
    func_021D75EC(0x1a, field);
    func_021D75A8(0x34, value);
    func_021D7674(0x35, 4 << 10, 410, 4 << 15);
    func_021D70F0(p, 0x3c);
    value = func_021D775C(0x34);
    scale = func_021D775C(0x35);
    func_021D7540(12642);
    return func_021D7B10(value, scale);
}





int func_021C75EC(u8 *p, u8 *a, int k)
{
    int f = func_021D5814(a, k);
    u32 v = 0x1000;
    int x;
    int r;

    func_021D74F8(12664);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x51, f);
    func_021D70F0(p, 0x40);
    x = func_021D775C(0x51);
    if (x != 0)
        v = 0x1800;
    func_021D75EC(0x44, x);
    func_021D75A8(0x35, v);
    func_021D70F0(p, 0x41);
    r = func_021D775C(0x35);
    func_021D7540(12681);
    return r;
}





int func_021C7664(u8 *p, u32 x, u8 *a)
{
    int c41;
    int c45;
    int c26;
    int s;

    s = func_0201BD28(x, 10);
    func_021D74F8(12701);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x25, s);
    func_021D7630(0x45, 0);
    func_021D7630(0x41, 0);
    func_021D75A8(0x26, 0);
    func_021D70F0(p, 0x6c);
    c41 = func_021D775C(0x41);
    c45 = func_021D775C(0x45);
    c26 = func_021D775C(0x26);
    func_021D7540(12712);
    if (c41 != 0 && s != 0)
        return 0;
    if (s == 0)
        s = s + c26;
    if (c45 != 0)
        s = s << 1;
    return s;
}





int func_021C76F4(u8 *p, u8 *a, u32 k)
{
    int res;
    int c26;
    int c41;

    func_021D74F8(12745);
    func_021D75EC(4, func_021D5440(a));
    func_021D75A8(0x26, k);
    func_021D7630(0x41, 0);
    res = 0;
    func_021D70F0(p, 0x6d);
    c26 = func_021D775C(0x26);
    c41 = func_021D775C(0x41);
    func_021D7540(12753);
    if (c41 != 0)
        return 0;
    if (c26 != 0) {
        if (func_021C82B8(p, res) != 0)
            return 1;
        if (func_021D78AC(100) < (u8)c26)
            res = 1;
        return res;
    }
    return res;
}




void func_021C7780(u8 *p, u8 *a)
{
    int line = 12778;
    func_021D74F8(line);
    func_021D75A8(2, func_021D5440(a));
    func_021D70F0(p, 110);
    func_021D7540(line + 3);
}





int func_021C77B0(u8 *p, u8 *a, u32 b, u32 c, u32 d, u32 e)
{
    int r;
    int res;

    func_021D74F8(12801);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(3, c);
    func_021D75EC(0x1f, b);
    func_021D75EC(0x20, d);
    func_021D75EC(0x19, e);
    res = 0;
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x5b);
    r = func_021D775C(0x41);
    func_021D7540(12810);
    if (r == 0)
        res = 1;
    return res;
}




void func_021C7820(u8 *p, u8 *a, u32 k)
{
    int line = 12826;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(25, k);
    func_021D70F0(p, 92);
    func_021D7540(line + 4);
}





void func_021C785C(u8 *p, u32 a, u8 *b, u32 c, u32 d)
{
    func_021D74F8(12846);
    func_021D75EC(3, a);
    func_021D75EC(2, func_021D5440(b));
    func_021D75EC(0x1f, c);
    func_021D75EC(0x20, d);
    func_021D70F0(p, 0x5d);
    func_021D7540(12852);
}





void func_021C78A8(u8 *p, u8 *a, u32 b, u32 c, u32 d)
{
    func_021D74F8(12868);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, b);
    func_021D75EC(0x1f, c);
    func_021D75EC(0x20, d);
    func_021D70F0(p, 0x5e);
    func_021D7540(12874);
}





u16 func_021C78F4(u8 *p, u8 *a, u8 *b, u32 s)
{
    int k;
    u32 y;
    u16 r;

    if (b != 0)
        k = func_021D5440(b);
    else
        k = 0x1f;
    func_021D74F8(12894);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, (u8)k);
    func_021D7674(0x35, 0x1000, 410, 0x20000);
    func_021D75A8(0x20, s);
    func_021D70F0(p, 0x8c);
    s = (u16)func_021D775C(0x20);
    y = func_021D775C(0x35);
    if (s != 0)
        s = (u16)func_021D7B2C(s, y);
    func_021D76BC(0x20, s);
    func_021D70F0(p, 0x8d);
    r = func_021D775C(0x20);
    func_021D7540(12911);
    return r;
}





void func_021C7998(u8 *p, u32 x)
{
    func_021D74F8(12930);
    func_021D75EC(0x39, x);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x7d);
    if (func_021D775C(0x41) == 0)
        func_021D70F0(p, 0x7e);
    func_021D7540(12938);
}





u32 func_021C79E0(u8 *p, u32 x, u8 *a)
{
    u32 s = func_0201BD28(x, 0x1a);
    int c;
    u32 m;
    u32 r;

    func_021D74F8(12956);
    func_021D75EC(2, func_021D5440(a));
    func_021D75A8(0x35, 0);
    func_021D70F0(p, 0x8f);
    c = func_021D775C(0x35);
    func_021D7540(12961);
    m = func_021D59B4(a, 0xe);
    if (c != 0)
        r = func_021D7B10(m, c);
    else
        r = func_021D7B3C(m, s);
    if (r == 0)
        return 1;
    if (r > m)
        r = m;
    return r;
}





int func_021C7A54(u8 *p, u8 *a, u32 c)
{
    int r;
    func_021D74F8(12996);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x2d, c);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x9a);
    r = func_021D775C(0x41);
    func_021D7540(13002);
    return r;
}




void func_021C7AA0(u8 *p, u8 *a)
{
    int line = 13017;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D70F0(p, 155);
    func_021D7540(line + 3);
}




void func_021C7AD0(u8 *p, u8 *a, u32 k)
{
    int line = 13033;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(45, k);
    func_021D70F0(p, 156);
    func_021D7540(line + 4);
}




void func_021C7B0C(u8 *p, u8 *a)
{
    int line = 13050;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D70F0(p, 157);
    func_021D7540(line + 3);
}





void func_021C7B3C(u8 *p, u32 a, u16 b, u16 c)
{
    func_021D74F8(13068);
    func_021D75EC(2, a);
    func_021D75EC(0xf, b);
    func_021D75EC(0x10, c);
    func_021D70F0(p, 0x89);
    func_021D7540(13073);
}




void func_021C7B7C(u8 *p, unsigned int i) { func_021D74F8(13085); func_021D75EC(2,i); func_021D70F0(p,138); func_021D7540(13088); }





void func_021C7BA8(u8 *p, u8 a, u32 b, u32 c, u32 *out)
{
    func_021D74F8(13102);
    func_021D75EC(2, a);
    func_021D75EC(0x52, c);
    func_021D75EC(0x53, b);
    func_021D75A8(0x1e, *out);
    func_021D70F0(p, 0x9f);
    *out = func_021D775C(0x1e);
    func_021D7540(13109);
}




void func_021C7BF8(u8 *p) { func_021D74F8(13123); func_021D70F0(p, 121); func_021D7540(13125); }





void func_021C7C18(void *p)
{
    func_02082BCC(p, 0, (u32)0xc);
}





void func_021C7C24(u16 *p, int unused, u8 *b, u8 *c, int e)
{
    u8 x = func_021D5440(b);
    u8 y = func_021D5440(c);
    int mx = func_021B8DDC(x);
    int my = func_021B8DDC(y);
    u8 same = (func_021B9A24(x, y) == 0);
    u16 *q = 0;
    if (mx == 0) {
        if (same) {
            if (e == 0) {
                q = p;
            } else if (e > 3) {
                q = p + 1;
            } else if (e < 3) {
                q = p + 2;
            }
        }
    } else if (my == 0) {
        if (same) {
            if (e == 0) {
                q = p + 3;
            } else if (e > 3) {
                q = p + 4;
            } else if (e < 3) {
                q = p + 5;
            }
        }
    }
    if (q != 0) {
        if (*q < 9999) {
            *q += 1;
        }
    }
}





/*
 * ldrh at #0x1f7c (pool constant)
 */
u16 func_021C7CBC(u8 *p)
{
    return ((struct Obj18319 *)p)->f1F7C;
}





/*
 * ldrh at #0x1f7e (pool constant)
 */
u16 func_021C7CC8(u8 *p)
{
    return ((struct Obj18320 *)p)->f1F7E;
}




/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0x7e; lsls r1, r1, #6; ldrh r0, [r0, r1]; bx lr.
 */
u16 func_021C7CD4(struct Q6 *p) { return p->v; }





/*
 * ldrh at #0x1f82 (pool constant)
 */
u16 func_021C7CDC(u8 *p)
{
    return ((struct Obj18322 *)p)->f1F82;
}





u16 func_021C7CE8(u8 *p)
{
    return ((struct Obj18323 *)p)->f1F86;
}




/*
 * Forwarding tail call: p[2] and the caller's i go to func_021B9934, whose
 * listing reads both (lsls r1, r1, #2), and its result is returned.
 */
void *func_021C7CF4(int *p, int i)
{
    return func_021B9934((char *)p[2], i);
}



int func_021C7D00(u8 *p, int b) { int i = func_021C7D24(p + 0x1ab8); if (!func_021B86A0(*(unsigned int ** *)&((struct Obj00003 *)p)->f4, i)) i = 6; return i; }
