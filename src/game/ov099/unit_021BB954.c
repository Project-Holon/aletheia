/*
 * file:     unit_021BB954.c
 * unit:     yes
 * function: func_021BB954, func_021BB9C8, func_021BB9F4, func_021BBA20, func_021BBA4C, func_021BBC0C, func_021BBC34, func_021BBD0C, func_021BBD80, func_021BBDD0, func_021BBE50, func_021BBE7C, func_021BBEB4, func_021BC06C, func_021BC090, func_021BC0C4, func_021BC104, func_021BC14C, func_021BC1C4, func_021BC1E8, func_021BC228, func_021BC29C, func_021BC2C0, func_021BC43C, func_021BC468, func_021BC4A8, func_021BC4D4, func_021BC51C, func_021BC544, func_021BC5FC, func_021BC620, func_021BC6B0, func_021BC6F4, func_021BC73C, func_021BC76C, func_021BC784, func_021BC79C, func_021BC7B4, func_021BC850, func_021BC868, func_021BC940, func_021BC958, func_021BC9FC, func_021BCA14, func_021BCAB8, func_021BCAD0, func_021BCB70, func_021BCB8C, func_021BCBB0, func_021BCBBC, func_021BCBD8, func_021BCC4C, func_021BCC58, func_021BCCB8, func_021BCD58, func_021BCDB0, func_021BCE30, func_021BCE80, func_021BCEAC, func_021BCECC, func_021BCF4C, func_021BCF6C
 * address:  0x021BB954
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021C3A70  0x021C3A70  data  a4
 *   d_021C3B68  0x021C3B68  data  a4
 *   d_021C3AD0  0x021C3AD0  data  a4
 *   func_021BAC24  0x021BAC24  thumb  ov099
 *   data_021C3B30  0x021C3B30  data
 *   data_021C3B34  0x021C3B34  data
 *   data_021C3A78  0x021C3A78  data
 *   data_021C3A00  0x021C3A00  data
 *   data_021C3A18  0x021C3A18  data
 *   func_020450F0 0x020450F0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020456F8 0x020456F8 arm
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 *   sub_020456F8  0x020456F8  arm
 *   func_0201F7A8  0x0201F7A8  thumb
 *   sub_020452E8  0x020452E8  arm
 *   func_020185F4 0x020185F4 thumb
 *   func_0201BA68 0x0201BA68 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0201BBE8 0x0201BBE8 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_020490F4  0x020490F4  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC78  0x0201BC78  thumb
 *   func_0201BCB4  0x0201BCB4  thumb
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   unit_0204B92C  0x0204B92C  arm
 *   unit_0204B3DC  0x0204B3DC  arm
 *   data_021C39F0 0x021C39F0 data a4
 *   func_02020D10 0x02020D10 thumb
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201A4D4 0x0201A4D4 thumb
 *   func_0200AE3C 0x0200AE3C thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_0201A570 0x0201A570 thumb
 *   func_0202F038  0x0202F038  thumb
 *   func_0202EE8C  0x0202EE8C  thumb
 *   func_0202020C  0x0202020C  thumb
 *   func_0201F868  0x0201F868  thumb
 *   func_02156BC4  0x02156BC4  thumb  ov009
 *   func_02156330  0x02156330  thumb  ov009
 *   func_021563C0  0x021563C0  thumb  ov009
 *   func_021C24A4  0x021C24A4  thumb  ov099
 *   func_021C2864  0x021C2864  thumb  ov099
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1E8  0x0203D1E8  arm
 *   func_0203D378  0x0203D378  arm
 *   func_02039C68  0x02039C68  arm
 *   func_021BA874  0x021BA874  thumb  ov099
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_021BA928  0x021BA928  thumb  ov099
 *   func_021BA828  0x021BA828  thumb  ov099
 *   func_021BA858  0x021BA858  thumb  ov099
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_021BAD50  0x021BAD50  thumb  ov099
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_020200CC 0x020200CC thumb
 *   func_0202EB14 0x0202EB14 thumb
 *   func_0202EB0C 0x0202EB0C thumb
 *   func_021BDDD0 0x021BDDD0 thumb ov099
 *   func_021B9B64  0x021B9B64  thumb  ov099
 *   func_020362DC 0x020362DC arm
 *   d_021C37DC     0x021C37DC  data  a4
 *   func_021C282C  0x021C282C  thumb  ov099
 *   func_021BAADC  0x021BAADC  thumb  ov099
 *   func_021C18C8  0x021C18C8  thumb  ov099
 *   func_02012934 0x02012934 thumb
 *   func_0201A090 0x0201A090 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200BBA8 0x0200BBA8 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 *   sub_020307B0  0x020307B0  arm
 *   d_021C3A30     0x021C3A30  data  a4
 *   func_020307B0  0x020307B0  arm
 *   func_0201A354  0x0201A354  thumb
 *   func_021BDDF4  0x021BDDF4  thumb  ov099
 *   func_021BA978  0x021BA978  thumb  ov099
 */
#include "../../matched/include/Obj01245.h"
#include "../../matched/include/Obj03731.h"
#include "../../matched/include/Obj07943.h"
#include "../../matched/include/Obj09193.h"
#include "../../matched/include/Obj00976.h"
#include "../../matched/include/Obj04412.h"
#include "../../matched/include/Obj05261.h"
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj13686.h"
#include "../../matched/include/Obj10203.h"
#include "../../matched/include/Obj06354.h"
#include "../../matched/include/Obj00467.h"
#include "../../matched/include/Obj22023.h"
#include "../../matched/include/Obj22024.h"
#include "../../matched/include/Obj22025.h"
#include "../../matched/include/Obj22026.h"
#include "../../matched/include/Obj22027.h"
#include "../../matched/include/Obj13687.h"
#include "../../matched/include/Obj22028.h"
#include "../../matched/include/Obj06355.h"
#include "../../matched/include/Obj04413.h"
#include "../../matched/include/Obj07225.h"
#include "../../matched/include/Obj04414.h"
#include "../../matched/include/Obj18192.h"
#include "../../matched/include/Obj00977.h"
#include "../../matched/include/Obj18193.h"
#include "../../matched/include/Obj01915.h"
#include "../../matched/include/Obj22029.h"
#include "../../matched/include/Obj18194.h"
#include "../../matched/include/Obj01916.h"
#include "../../matched/include/Obj22030.h"
#include "../../matched/include/Obj18201.h"
#include "../../matched/include/Obj02154.h"
#include "../../matched/include/Obj22031.h"
#include "../../matched/include/Obj07944.h"
#include "../../matched/include/Obj22032.h"
#include "../../matched/include/Obj03732.h"
#include "../../matched/include/Obj07945.h"
#include "../../matched/include/Obj22033.h"
#include "../../matched/include/Obj12113.h"
#include "../../matched/include/Obj18202.h"
#include "../../matched/include/Obj05262.h"
#include "../../matched/include/Obj22034.h"
#include "../../matched/include/Obj22035.h"

struct Desc;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Obj;
struct Reg;
struct Link;
struct Entry;
struct PrintSys;
struct BigObj;
struct Big;
struct O;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32_021BB954;

struct Pair_021BB954 { u32_021BB954 a, b; };

typedef unsigned long  u32_021BB9C8;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef unsigned long  u32_021BBA20;

typedef signed long    s32_021BBA20;

typedef unsigned int u32_021BBA4C;

typedef unsigned long  u32_021BBC0C;

typedef signed long    s32_021BBC0C;

typedef struct {
    char pad[0x1A0];
    void *f1A0;
} S_021BB954;

typedef unsigned int u32_021BBC34;

typedef struct { u16 a,b,c; u8 d,e; } Rec;

typedef signed int     s32_021BBC34;

typedef signed int     s32_021BBD0C;

typedef unsigned int   u32_021BBD0C;

typedef unsigned long  u32_021BBD80;

typedef signed long    s32_021BBD80;

typedef unsigned long  u32_021BBDD0;

typedef signed long    s32_021BBDD0;

typedef unsigned long  u32_021BBE50;

typedef struct {
    char pad[0x150];
    void *arr[12];
} S_021BBE50;

typedef unsigned int u32_021BBE7C;

struct Pair_021BBE50 { u32_021BBE7C a, b; };

typedef unsigned int u32_021BBEB4;

struct O {
    u8 p0[0xdc];
    void *fdc, *fe0, *fe4, *fe8, *fec, *ff0, *ff4;
    u8 pf8[0x19c - 0xf8];
    void *f19c;
    u8 p1a0[0x1334 - 0x1a0];
    u32_021BBEB4 f1334;
    u8 p1338[0x1344 - 0x1338];
    void **f1344;
    void **f1348;
};

typedef unsigned long  u32_021BC090;

typedef struct {
    char pad[0x100];
    u32_021BC090 f100;
    char pad2[0x8C];
    u32_021BC090 f190;
    char pad3[0x2C];
    u32_021BC090 f1C0;
} S;

typedef unsigned int   u32_021BC0C4;

typedef unsigned int u32_021BC14C;

typedef unsigned long  u32_021BC1C4;

typedef unsigned long  u32_021BC29C;

typedef signed long    s32_021BC29C;

typedef unsigned int u32_021BC2C0;

typedef signed int     s32_021BC2C0;

typedef unsigned long  u32_021BC43C;

typedef enum { K274 = 0x274 } Off_021BB954;

typedef unsigned int u32_021BC51C;

typedef unsigned long  u32_021BC544;

typedef struct { u32_021BC544 a, b, c; } Tri;

typedef enum { K242 = 0x242 } Off_021BC51C;

typedef unsigned long  u32_021BC5FC;

typedef unsigned long  u32_021BC620;

typedef unsigned int u32_021BC6B0;

typedef unsigned long  u32;

typedef enum { K73 = 0x73 } Idx;

typedef unsigned int u32_021BC868;

typedef signed int     s32_021BC868;

typedef unsigned long  u32_021BC940;

typedef signed long    s32_021BC940;

typedef unsigned long  u32_021BC958;

typedef signed int     s32_021BC958;

typedef unsigned long  u32_021BC9FC;

typedef signed long    s32_021BC9FC;

typedef unsigned long  u32_021BCA14;

typedef signed int     s32_021BCA14;

typedef unsigned long  u32_021BCAB8;

typedef signed long    s32_021BCAB8;

typedef unsigned long  u32_021BCAD0;

typedef signed int     s32_021BCAD0;

typedef unsigned int u32_021BCB70;

typedef unsigned int u32_021BCB8C;

typedef unsigned long  u32_021BCBB0;

typedef unsigned long  u32_021BCBBC;

typedef unsigned long  u32_021BCD58;

typedef unsigned int u32_021BCDB0;

typedef unsigned int u32_021BCE30;

typedef unsigned long  u32_021BCE80;

typedef unsigned int u32_021BCEAC;

typedef unsigned long  u32_021BCECC;

typedef unsigned long  u32_021BCF4C;

typedef unsigned int u32_021BCF6C;

extern void func_021BAC24(char *, struct Desc *, struct Pair_021BB954 *, int, int, u32_021BB954);
extern u32_021BBA4C func_020450F0(u32_021BBA4C layer, u32_021BBA4C a, u32_021BBA4C b, u32_021BBA4C tiles, u8 c, u8 d, u8 slot);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern struct U16Vec *func_020457B0(u32_021BBA4C capacity, u32_021BBA4C heapId);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020456F8(struct Descriptor *d);
extern u32_021BBA4C func_0201AA18(void *);
extern void *func_0201AB28(void *,u32_021BBA4C);
extern u32_021BBA4C func_02017E1C(void *,u32_021BBA4C,u32_021BBA4C);
extern void func_02045CAC(struct MsgBank *bank, u32_021BBA4C index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32_021BBA4C i, u32_021BBA4C a, u32_021BBA4C b, u32_021BBA4C c, u32_021BBA4C d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern void func_02041B6C(u32_021BBA4C);
extern void sub_020456F8(struct Descriptor *d);
extern void func_0201F7A8(void *desc, u32_021BBC0C kind);
extern u32_021BBC0C sub_020452E8(struct Descriptor *d);
extern void *func_020185F4(void *);
extern u32_021BBC34 func_0201BA68(void *);
extern s32_021BBC34 func_0204A6C8(void *a, u32_021BBC34 b, u32_021BBC34 c, u32_021BBC34 a3, u16 flags);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern int func_0201BBE8(void *);
extern void func_0204B6F4(struct Obj *o, u32_021BBC34 v, u32_021BBC34 flag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *a0, u32_021BBD0C a1, u32_021BBD0C a2, u32_021BBD0C a3, u16 a4);
extern int func_0201BC78(void);
extern int func_0201BCB4(void);
extern s32_021BBD0C func_0204AF28(void *owner, u32_021BBD0C first, u32_021BBD0C second, u32_021BBD0C mode);
extern void func_02049238(void *o);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32_021BBD80 i);
extern void func_0204ADA4(u32_021BBD80 i);
extern void func_0204AFD8(u32_021BBD80 i);
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void unit_0204B92C(struct Obj *p, unsigned int v);
extern void unit_0204B3DC(struct Obj *p, unsigned int v);
extern void func_02020D10(u8 *p, u32_021BBE7C v);
extern int func_021BA8BC(void *);
extern void func_0201DD68(void);
extern u8 *func_0201A4D4(u8 *a0, u32_021BBEB4 a1, u16 a2, u32_021BBEB4 a3);
extern void *func_0200AE3C(struct Reg *p, u32_021BBEB4 heap);
extern void func_0201C7D0(void *,int,s16,void *,void *,u32_021BBEB4);
extern void func_0201A570(void *);
extern void func_0202F038(u8 *p);
extern u8 *func_0202EE8C(u32_021BC090 a, void *b, u8 c, u8 d, u16 e);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern u32_021BC0C4 func_0201F868(void *p);
extern void func_02156BC4(int);
extern int func_02156330(void);
extern void func_021563C0(int a);
extern void func_021C24A4(void *w, int v);
extern void func_021C2864(void *a, u8 v);
extern struct Entry *func_020399A8(void);
extern int func_0203D1E8(u32_021BC14C unused, void *arg);
extern u32_021BC14C func_0203D378();
extern void func_02039C68(struct Link *p, u32_021BC14C lo, u32_021BC14C hi);
extern void func_021BA874(char *p, int id);
extern void func_021BAAB8(char *p, int a, int b);
extern int func_021BA928();
extern void func_021BA828(char *p);
extern u32_021BB954 func_021BA858(char *p);
extern void func_021BA8EC(char *p);
extern void func_021BAD50(int a);
extern u32_021BC2C0 func_0201C6C4(struct PrintSys *p, void *v);
extern s32_021BC2C0 func_020200CC(struct Obj *o);
extern int func_0202EB14(void);
extern u32_021BC2C0 func_0202EB0C(void);
extern int func_021BDDD0(char *);
extern void func_021B9B64(char *p);
extern u32_021BC51C func_020362DC(void);
extern int func_021C282C(u8 *p);
extern void func_021BAADC(char *p, int a, int b);
extern void func_021C18C8(char *p, int a, int b);
extern void *func_02012934(const struct BigObj *);
extern int func_0201A090(void *, void *, u32_021BCB70 *);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200BAC8(void *);
extern u32_021BCB8C func_0200BBA8(void *);
extern void *func_0200BAF4(int a0, int a1);
extern u32_021BCBB0 sub_020307B0(void *p);
extern u32 func_020307B0(void *p);
extern void *func_0201A354(int a, int b);
extern int func_021BDDF4(char *p);
extern void func_021BA978(char *p, int a, int b, int c);
void func_021BB954(char *p, int flag);
void func_021BB9C8(int a);
void func_021BB9F4(int a);
void func_021BBA20(int a);
void func_021BBA4C(char *p,void *party);
void func_021BBC0C(S_021BB954 *s);
void func_021BBC34(char *p, void *a, int k, u32_021BBC34 o);
void func_021BBD0C(char *p, int a, int b);
void func_021BBD80(char *s);
void func_021BBDD0(void *pv, int flag);
void func_021BBE50(S_021BBE50 *s);
void func_021BBE7C(char *p);
void func_021BBEB4(struct O *p, int mask, u32_021BBEB4 a, int mode);
void func_021BC06C(char *p);
void func_021BC090(S *s);
void func_021BC0C4(char *p);
void func_021BC104(char *p);
int func_021BC14C(char *p, int v);
int func_021BC1C4(char *p, int v);
int func_021BC1E8(char *p, int r);
int func_021BC228(char *p, int r);
int func_021BC29C(char *p, int v);
int func_021BC2C0(char *p,int v);
int func_021BC43C(char *p, int v);
int func_021BC468(char *p, int v);
int func_021BC4A8(char *p, int v);
int func_021BC4D4(char *p, int v);
int func_021BC51C(char *p, int ret);
int func_021BC544(char *p, int v);
int func_021BC5C0(char *p, int v);
int func_021BC5D4(char *p, int v);
int func_021BC5E8(char *p, int v);
int func_021BC5FC(char *p, int v);
int func_021BC620(char *p, int v);
int func_021BC6B0(char *p, int v);
int func_021BC6F4(char *p, int v);
int func_021BC73C(char *p, int v);
int func_021BC76C(u8 *p, int b);
int func_021BC784(u8 *p, int b);
int func_021BC79C(u8 *p, int b);
int func_021BC7B4(char *p, int v);
int func_021BC850(char *p, int v);
int func_021BC868(char *p, int v);
int func_021BC940(char *p, int v);
int func_021BC958(char *p, int v);
int func_021BC9FC(char *p, int v);
int func_021BCA14(char *p, int v);
int func_021BCAB8(char *p, int v);
int func_021BCAD0(char *p, int v);
int func_021BCB70(void *rules, const struct BigObj *obj, u32_021BCB70 *mask);
int func_021BCB8C(void *p);
void func_021BCBB0(void *p);
int func_021BCBBC(int a, int b, int *out);
u32 func_021BCBD8(char *p, int m);
u32 func_021BCC4C(char *p);
void func_021BCC58(char *p, u32 x);
int func_021BCCB8(char *p, int v);
int func_021BCD58(char *p, int v);
int func_021BCDB0(char *p, int v);
int func_021BCE30(char *p, int v);
int func_021BCE80(char *p, int v);
int func_021BCEAC(char *p, int ret);
int func_021BCECC(char *p, int v);
int func_021BCF4C(char *p, int v);
int func_021BCF6C(char *p, int ret);
int func_021BCF8C(char *p, int ret);
int func_021BCF98(char *p, int ret);
extern char d_021C3A70[];
extern char d_021C3B68[];
extern struct Pair_021BB954 d_021C3AD0[];
extern u8 data_021C3B30[];
extern u8 data_021C3B34[];
extern u8 data_021C3A78[];
extern struct Pair_021BBE50 data_021C39F0[];
extern const Tri d_021C37DC;
extern const u32 d_021C3A30[];











void func_021BB954(char *p, int flag)
{
    if (flag) {
        char *q = *(char **)(p + 0x248);
        ((u32_021BB954 *)d_021C3A70)[0x18] = *(u8 *)(q + 0x21) + 0x83;
        ((u32_021BB954 *)d_021C3A70)[0x1A] = *(u8 *)(q + 0x22) + 0x87;
        ((u32_021BB954 *)d_021C3A70)[0x1C] = 0x8A - *(u8 *)(q + 0x20);
    } else {
        ((u32_021BB954 *)d_021C3A70)[0x18] = *(u16 *)(p + 0x134C) + 0x83;
        ((u32_021BB954 *)d_021C3A70)[0x1A] = *(u16 *)(p + 0x134E) + 0x87;
        ((u32_021BB954 *)d_021C3A70)[0x1C] = 0x8A - *(u8 *)(*(char **)(p + 0x248) + 0x48);
    }
    func_021BAC24(p, (struct Desc *)d_021C3B68, (struct Pair_021BB954 *)d_021C3AD0, 6, 0, 0x1E);
}












/*
 * Writes the two halfwords at 0x021C3B44 and runs the script pair with 5 / 1 / 0x11.
 */
void func_021BB9C8(int a)
{
    u16 *r = (u16 *)data_021C3B30;

    r[0xA] = 5;
    r[0xB] = 5;
    func_021BAC24((char *)a, (struct Desc *)data_021C3B34, (struct Pair_021BB954 *)data_021C3A78, 5, 1, 0x11);
}












/*
 * Writes the two halfwords at 0x021C3B44 and runs the script pair with 3 / 2 / 0x11.
 */
void func_021BB9F4(int a)
{
    u16 *r = (u16 *)data_021C3B30;

    r[0xA] = 3;
    r[0xB] = 3;
    func_021BAC24((char *)a, (struct Desc *)((void *)0x021C3B34), (struct Pair_021BB954 *)((void *)0x021C3A00), 3, 2, 0x11);
}











/*
 * Writes the two halfwords at 0x021C3B44 and runs the script pair with 3 / 3 / 0x14.
 */
void func_021BBA20(int a)
{
    u16 *r = (u16 *)data_021C3B30;

    r[0xA] = 3;
    r[0xB] = 3;
    func_021BAC24((char *)a, (struct Desc *)((void *)0x021C3B34), (struct Pair_021BB954 *)((void *)0x021C3A18), 3, 3, 0x14);
}










/*
 * Lever: binding the window address before the gender-zero call preserves its separate hoist and call site; form/gender declaration order fixes their spills.
 */
void func_021BBA4C(char *p,void *party)
{
    void *s,*t,*mon;
    int n,i,off;
    u32_021BBA4C species,gender,name,form;
    void **w;
    void *win;
    if (((struct Obj01245 *)p)->f1A0==0)
        ((struct Obj01245 *)p)->f1A0=(void *)func_020450F0(2,1,5,30,6,15,1);
    func_0201F73C(((struct Obj01245 *)p)->f1A0,2,(u16)(((struct Obj01245 *)p)->f1334),14);
    s=func_020457B0(0x40,0x21);
    t=func_020457B0(0x40,0x21);
    func_02043B5C(func_02045770(((struct Obj01245 *)p)->f1A0),255);
    func_020456F8(((struct Obj01245 *)p)->f1A0);
    n=func_0201AA18(party);
    for (i=0;i<n;i++) {
        mon=func_0201AB28(party,i);
        if (func_02017E1C(mon,0x4c,0)==0) {
            species=func_02017E1C(mon,0,0);
            form=func_02017E1C(mon,0xad,0);
            name=func_02017E1C(mon,0x9e,0);
            gender=func_02017E1C(mon,0x6e,0);
            func_02045CAC(((struct Obj01245 *)p)->fE0,0x74,t);
            func_0201EFA4(((struct Obj01245 *)p)->fDC,0,name,3,0,1);
            func_0201F250(((struct Obj01245 *)p)->fDC,s,t);
            off=i*40;
            func_0201C7A4(func_02045770(((struct Obj01245 *)p)->f1A0),off+1,32,s,((struct Obj01245 *)p)->fEC);
            if (gender!=2 && ((species!=0x1d && species!=0x20) || form!=0)) {
                if (gender==0) {
                    w=(void **)(p+0x1a0);
                    func_02045CAC(((struct Obj01245 *)p)->fE0,0x75,t);
                    win=*w;
                } else {
                    func_02045CAC(((struct Obj01245 *)p)->fE0,0x76,t);
                    win=((struct Obj01245 *)p)->f1A0;
                }
                func_0201C7A4(func_02045770(win),off+30,16,t,((struct Obj01245 *)p)->fE8);
            }
        }
    }
    func_02045808(s);
    func_02045808(t);
    func_02045374(((struct Obj01245 *)p)->f1A0);
    func_02045334(((struct Obj01245 *)p)->f1A0);
    func_02041B6C(2);
}











/*
 * Three-step release of the pointer at +0x1A0; the field is re-read for each
 * step, which is why the listing reloads it between the calls.
 */
void func_021BBC0C(S_021BB954 *s)
{
    if (s->f1A0 != 0) {
        sub_020456F8(s->f1A0);
        func_0201F7A8(s->f1A0, 1);
        sub_020452E8(s->f1A0);
        s->f1A0 = 0;
    }
}










void func_021BBC34(char *p, void *a, int k, u32_021BBC34 o)
{
    int i,n;
    char *base,*dst;
    void *mon;
    Rec rec;
    n = func_0201AA18(a);
    for (i=0;i<n;i++) {
        base = p + k*4;
        mon = func_020185F4(func_0201AB28(a,i));
        rec.a = i*40+22;
        rec.b = 54;
        rec.c = 0;
        rec.d = 0;
        rec.e = 0;
        dst = base+i*4;
        *(int *)&((struct Obj07943 *)dst)->f118 = func_0204A6C8((void *)o,func_0201BA68(mon),0,0,0x21);
        *(u32_021BBC34 *)&((struct Obj07943 *)dst)->f150 = (u32_021BBC34)func_0204B294((void *)((struct Obj03731 *)p)->f110,((struct Obj07943 *)dst)->f118,*(u32_021BBC34 *)&((struct Obj03731 *)p)->f148,*(u32_021BBC34 *)&((struct Obj03731 *)p)->f14C,&rec,0,0x21);
        func_0204B6F4(((struct Obj07943 *)dst)->f150,func_0201BBE8(mon),1);
    }
}










void func_021BBD0C(char *p, int a, int b)
{
    void *o;
    int t;

    o = func_020490F4(7, 0x21);
    ((struct Obj03731 *)p)->f148 = (void *)func_0204ACEC(o, func_0201BC3C(), 0, 0x160, 0x21);
    t = func_0201BC78();
    ((struct Obj03731 *)p)->f14C = (void *)func_0204AF28(o, t, func_0201BCB4(), 0x21);
    func_021BBC34(p, (void *)a, 0, (u32_021BBD0C)o);
    func_021BBC34(p, (void *)b, 6, (u32_021BBD0C)o);
    func_021BBE50((S_021BBE50 *)p);
    func_02049238(o);
}










void func_021BBD80(char *s)
{
    int i;

    if (((struct Obj09193 *)s)->f150 != 0) {
        for (i = 0; i < 12; i++) {
            if (*(void **)(s + i * 4 + 0x150) != 0) {
                func_0204B3B4(*(void **)(s + i * 4 + 0x150));
                func_0204A8D4((u32_021BBD80)(*(void **)(s + i * 4 + 0x118)));
            }
            *(u32_021BBD80 *)(s + i * 4 + 0x150) = 0;
        }
        func_0204ADA4((u32_021BBD80)(((struct Obj09193 *)s)->f148));
        func_0204AFD8((u32_021BBD80)(((struct Obj09193 *)s)->f14C));
    }
}










/*
 * Walks the twelve pointers at +0x150 in two halves of six: the first half is
 * handed pair (callee, then join call) with flag ? 1 : 0, the second half with
 * flag ? 0 : 1, each half skipping empty slots.
 *
 * Two rules of this overlay are load-bearing here.  First the duplicated call
 * per arm: the image has two call sites for each of the two calls, each with
 * its own literal, and 1.1p1 does not merge them because the arms are written
 * out.  A computed selector (`int k = flag ? 1 : 0;` passed to one call site)
 * compiles to 116 bytes against the image's 128, with the selector parked in a
 * callee-saved register.  Second the walked address is index-first
 * (`s + i * 4 + 0x150`) so that the scaled index is computed once into r5 (r4
 * in the second half) and the field constant stays in a register.
 *
 * The two halves share one counter: re-initialising the same variable
 * (`for (i = 6; i < 12; i++)`) is the image's shape - a second counter
 * variable costs 8 bytes and swaps r4/r5.
 */
void func_021BBDD0(void *pv, int flag)
{
    char *s = (char *)pv;
    int i;

    for (i = 0; i < 6; i++) {
        if (*(void **)(s + i * 4 + 0x150) != 0) {
            if (flag != 0) {
                func_0204B92C(*(void **)(s + i * 4 + 0x150), 1);
                func_0204B3DC(*(void **)(s + i * 4 + 0x150), 1);
            } else {
                func_0204B92C(*(void **)(s + i * 4 + 0x150), 0);
                func_0204B3DC(*(void **)(s + i * 4 + 0x150), 0);
            }
        }
    }

    for (i = 6; i < 12; i++) {
        if (*(void **)(s + i * 4 + 0x150) != 0) {
            if (flag != 0) {
                func_0204B92C(*(void **)(s + i * 4 + 0x150), 0);
                func_0204B3DC(*(void **)(s + i * 4 + 0x150), 0);
            } else {
                func_0204B92C(*(void **)(s + i * 4 + 0x150), 1);
                func_0204B3DC(*(void **)(s + i * 4 + 0x150), 1);
            }
        }
    }
}









void func_021BBE50(S_021BBE50 *s)
{
    int i;

    for (i = 0; i < 12; i++) {
        if (s->arr[i] != 0) {
            unit_0204B92C(s->arr[i], 0);
            unit_0204B3DC(s->arr[i], 0);
        }
    }
}








void func_021BBE7C(char *p)
{
    *(u16 *)(data_021C3B30 + 0x14) = 2;
    *(u16 *)(data_021C3B30 + 0x16) = 2;
    func_021BAC24(p, (struct Desc *)(data_021C3B30 + 4), (struct Pair_021BB954 *)data_021C39F0, 2, 5, 18);
    func_02020D10(*(u8 * *)&((struct Obj00976 *)p)->fBC, 1);
}








void func_021BBEB4(struct O *p, int mask, u32_021BBEB4 a, int mode)
{
    int base;
    int i;
    u32_021BBEB4 flags;
    void *t;
    u32_021BBEB4 w;
    base = 4;
    a = (a == 1) ? 1 : 0;
    p->f19c = (void *)func_021BA8BC(p->f19c);

    if (mode == 1) p->f19c = (void *)func_020450F0(2, 2, 5, 26, 12, 15, 1); else p->f19c = (void *)func_020450F0(2, 2, 5, 26, 16, 15, 1);
    func_02043B5C(func_02045770(p->f19c), 255);
    func_020456F8(p->f19c);
    func_02045374(p->f19c);
    func_0201F73C(p->f19c, 1, (u16)p->f1334, 14);
    func_0201DD68();
    p->f1344 = (void **)func_0201A4D4((u8 *)p->f1348, (u32_021BBEB4)p->fdc, 33, a);
    if (mode == 0) {
        t = func_0200AE3C((struct Reg *)p->f1348, 33);
        func_0201C7A4(func_02045770(p->f19c), 0, 0, t, p->fe8);
        func_02045808(t);
    } else if (mode != 1) {
        func_02045CAC(p->fe0, (mode == 2) ? 0x66 : 0x67, p->ff0);
        func_0201C7A4(func_02045770(p->f19c), 0, 0, p->ff0, p->fe8);
    }
    if (mode == 1) base = 0;
    for (i = 0; i < 6; i++) {
        if (mask & (1 << i)) flags = 0x41; else flags = 0x11;
        flags <<= 6;
        func_0201C7D0(func_02045770(p->f19c), 0, (s16)((base + i * 2) * 8), p->f1344[i + 1], p->fe8, flags);
        func_0201C7D0(func_02045770(p->f19c), 0x70, (s16)((base + i * 2) * 8), p->f1344[i + 7], p->fe8, flags);
    }
    func_02045334(p->f19c);
}








void func_021BC06C(char *p)
{
    func_0201A570(((struct Obj04412 *)p)->f1344);
    *(int *)&((struct Obj04412 *)p)->f1344 = 0;
    *(int *)&((struct Obj04412 *)p)->f19C = func_021BA8BC(((struct Obj04412 *)p)->f19C);
}








/*
 * Guarded release of the handle at +0x100, then a fresh object from the
 * five-argument factory, built from the blocks at +0x1C0 and +0x190 and stored
 * back at +0x100.  The 5th argument rides on the stack (`str r0, [sp]`).
 */
void func_021BC090(S *s)
{
    if (s->f100 != 0) {
        func_0202F038((u8 *)s->f100);
        s->f100 = 0;
    }

    s->f100 = (u32_021BC090)func_0202EE8C(s->f1C0, (void *)s->f190, 0xF, 0x10, 0x21);
}








void func_021BC0C4(char *p)
{
    if (((struct Obj05261 *)p)->f1A4 != 0) {
        func_021BBD80(p);
        func_021BBC0C((S_021BB954 *)p);
        ((struct Obj05261 *)p)->f1A4 = (void *)func_021BA8BC(((struct Obj05261 *)p)->f1A4);
        func_0202020C(((struct Obj05261 *)p)->fBC, 0, 0);
        func_0201F868(((struct Obj05261 *)p)->fB8);
        ((struct Obj05261 *)p)->fB8 = 0;
    }
}








void func_021BC104(char *p)
{
    char *q = *(char * *)&((struct Obj00008 *)p)->f248;

    if (((struct Obj13686 *)q)->f44 != 0 && ((struct Obj13686 *)q)->f45 != 0) {
        func_02156BC4(1);
        func_021563C0(func_02156330());
        func_021C24A4(p, 0x2A);
        func_021C2864(((struct Obj00008 *)p)->f8, 1);
    } else {
        func_021C2864(((struct Obj00008 *)p)->f8, 0);
    }
}







/*
 * 2026-10-05 (wD5 lane01): EXACT. Each arm ends with `off -= 0x76; p[off] = 0x42 / 0x49;`; tail
 *   merging builds the shared join. The value local r merged at the join swapped p and off.
 *   Older notes below.
 *
 * note (2026-10-04): DIFF, 124 vs 120 bytes. Original pushes r3-r7 (v in r6, zero local in r7), loads the 0x242 pool offset into r5 inside each arm and reuses it at the join as subs r5,#0x76 for the 0x1CC store; ours reads 0x242 into r1 (dies at the ldrh), builds 0x1CC separately, and uses only r4-r6. Semantics are right; the open question is what keeps the 0x242 constant live to the join.
 *
 * note (2026-10-04, lane17): lane17 wave D2: re-read, no new change. Same residue as the note above (0x242 pool offset kept in r5 to the join; pushes r3-r7).
 *
 * note: 2026-10-05 (wD4 lane20): constant-in-a-local lever applied: int off = 0x242 assigned in each arm, join is off -= 0x76; p[off] = r. Down from 50 to 14 differing bytes, same size, r4-r7 push set now matches, offset kept live to the join. Residue: p/off colour swap only (image p r4, off r5; ours p r5, off r4). Tried declaration orders of z/r/off, off initialised at the top (loses the r7 zero), off -= inside the index expression.
 */
int func_021BC14C(char *p, int v)
{
    int z;
    int off;
    func_0203D1E8((u32_021BC14C)func_020399A8(), 0);
    z = 0;
    if (func_0203D378() == 0) {
        *(int *)(p + 0x135C) = 3;
        off = 0x242;
        func_021BA874(p, *(u16 *)(p + off) - 1);
        func_021BAAB8(p, 0x5F, z);
        off -= 0x76;
        *(int *)(p + off) = 0x42;
    } else {
        *(int *)(p + 0x135C) = 4;
        off = 0x242;
        func_021BA874(p, *(u16 *)(p + off) - 1);
        func_021BAAB8(p, 0x7E, z);
        func_021BC090((S *)p);
        func_02039C68((struct Link *)func_020399A8(), 0x1B, 0xA);
        off -= 0x76;
        *(int *)(p + off) = 0x49;
    }
    return v;
}







/*
 * Early-returns the selector when the guard is false, else runs the setup and stamps 0x43.
 */
int func_021BC1C4(char *p, int v)
{
    if (func_021BA928(p, v) == 0) {
        return v;
    }

    func_021BA828(p);
    *(u32_021BC1C4 *)&((struct Obj00008 *)p)->f1CC = 0x43;
    return v;
}







int func_021BC1E8(char *p, int r)
{
    int v;

    func_0201DD68();
    v = func_021BA858(p);
    if (v == -1)
        return r;
    if (v == 0)
        ((struct Obj10203 *)p)->f1353 = 0x44;
    else
        ((struct Obj10203 *)p)->f1353 = 0x4A;
    func_021BA8EC(p);
    ((struct Obj10203 *)p)->f1CC = 0x8A;
    return r;
}







int func_021BC228(char *p, int r)
{
    if (func_0203D378(func_0203D1E8((int)func_020399A8(), (void *)0)) != 0) {
        ((struct Obj06354 *)p)->f135C = 3;
        func_021BA874((char *)p, ((struct Obj06354 *)p)->f242 - 1);
        func_021BAAB8(p, 0x60, 0);
        ((struct Obj06354 *)p)->f1CC = 0x45;
    } else {
        ((struct Obj06354 *)p)->f135C = 4;
        func_021BAAB8(p, 0x4C, 0);
        func_021BC090((S *)p);
        func_02039C68((struct Link *)func_020399A8(), 0x1B, 0xA);
        ((struct Obj06354 *)p)->f1CC = 0x49;
    }
    return r;
}







/*
 * Early-returns the selector when the guard is false, else runs the second setup and stamps 0x46.
 */
int func_021BC29C(char *p, int v)
{
    if (func_021BA928(p, v) == 0) {
        return v;
    }

    func_021BAD50((int)p);
    *(u32_021BC29C *)&((struct Obj00008 *)p)->f1CC = 0x46;
    return v;
}






/*
 * Lever: case4/case5 guard is a switch, retaining two compares; an equality disjunction folds to a range.
 */
int func_021BC2C0(char *p,int v)
{
    int r;
    void *q;
    q = ((struct Obj00467 *)p)->f1B8;
    if (((struct Obj00467 *)p)->f1B0 != 0) {
        if (func_0201C6C4(q,func_02045770(((struct Obj00467 *)p)->f1AC)) == 0) {
            func_02045334(((struct Obj00467 *)p)->f1AC);
            ((struct Obj00467 *)p)->f1B0=0;
        }
    }
    r=func_020200CC(((struct Obj00467 *)p)->fBC);
    switch(r) {
    case 4: case 5:
        if (((struct Obj22023 *)(*(char * *)&((struct Obj00467 *)p)->f248))->f46==0) return v;
        break;
    }
    if (r!=-1) func_021BA8EC(p);
    switch(r) {
    case -1: return v;
    case -2:
        ((struct Obj00467 *)p)->f1353=0x9b;
        ((struct Obj00467 *)p)->f1CC=0x8a;
        break;
    case 4:
        if (((struct Obj22024 *)(*(char * *)&((struct Obj00467 *)p)->f248))->f45==0) {
            func_021BAAB8(p,0x8c,0);
            ((struct Obj00467 *)p)->f1CC=0x47;
        } else {
            ((struct Obj00467 *)p)->f1353=0x4b;
            ((struct Obj00467 *)p)->f1CC=0x8a;
        }
        break;
    case 5:
        if (((struct Obj22025 *)(*(char * *)&((struct Obj00467 *)p)->f248))->f45==0) {
            func_021BAAB8(p,0x8c,0);
            ((struct Obj00467 *)p)->f1CC=0x47;
        } else if (func_0202EB14()==0 && func_0202EB0C()!=0) {
            func_021BAAB8(p,0x95,0);
            ((struct Obj00467 *)p)->f1CC=0xa4;
        } else {
            ((struct Obj00467 *)p)->f1353=0x4c;
            ((struct Obj00467 *)p)->f1CC=0x8a;
        }
        break;
    case 6:
        if (func_021BDDD0(p)==0) {
            func_021BAAB8(p,0x79,0);
            ((struct Obj00467 *)p)->f1CC=0x47;
        } else if (((struct Obj22026 *)(*(char * *)&((struct Obj00467 *)p)->f248))->f44!=((struct Obj22027 *)(*(char * *)&((struct Obj00467 *)p)->f248))->f45) {
            ((struct Obj00467 *)p)->f1352=6;
            ((struct Obj00467 *)p)->f1CC=0x7d;
        } else {
            ((struct Obj00467 *)p)->f1353=0x4d;
            ((struct Obj00467 *)p)->f1CC=0x8a;
        }
        break;
    case 7: ((struct Obj00467 *)p)->f1CC=0x4e; break;
    }
    ((struct Obj00467 *)p)->f1A4=(void *)func_021BA8BC(((struct Obj00467 *)p)->f1A4);
    func_0202020C(((struct Obj00467 *)p)->fBC,0,(u16 *)(p+0x23c));
    func_0201F868(((struct Obj00467 *)p)->fB8);
    return v;
}






int func_021BC43C(char *p, int v)
{
    func_021B9B64(p + 0x274);

    if (func_021BA928(p) != 0) {
        func_021BA828(p);
        *(u32_021BC43C *)&((struct Obj00008 *)p)->f1CC = 0xA5;
    }

    return v;
}






/*
 * Levers: the 0x274 offset is an enum-typed local (keeps r4 = 0x274 live and
 * derives 0x1CC as `o - 0xa8`); the two stores are written out in each arm.
 */
int func_021BC468(char *p, int v)
{
    int r;
    Off_021BB954 o;

    r = func_021BA858(p);
    o = K274;
    func_021B9B64(p + o);
    if (r == -1) {
        return v;
    }
    if (r == 0) {
        ((struct Obj13687 *)p)->f1353 = 0x4c;
        *(u32_021BC43C *)(p + (o - 0xa8)) = 0x8a;
    } else {
        ((struct Obj13687 *)p)->f1353 = 0x9b;
        *(u32_021BC43C *)(p + (o - 0xa8)) = 0x8a;
    }
    return v;
}






/*
 * Re-arms, then runs the setup and stamps 0xA7 when the guard answers true.
 */
int func_021BC4A8(char *p, int v)
{
    func_021B9B64(p + 0x274);

    if (func_021BA928(p) != 0) {
        func_021BA828(p);
        *(u32_021BC43C *)&((struct Obj00008 *)p)->f1CC = 0xA7;
    }

    return v;
}






int func_021BC4D4(char *p, int v)
{
    int r;
    Off_021BB954 o;

    r = func_021BA858(p);
    o = K274;
    func_021B9B64(p + o);
    if (r == -1) {
        return v;
    }
    if (r == 0) {
        *(u32_021BC43C *)(p + (o - 0xa8)) = 0x52;
        func_021BA8EC(p);
    } else {
        ((struct Obj22028 *)p)->f1353 = 0x90;
        *(u32_021BC43C *)(p + (o - 0xa8)) = 0x8a;
    }
    return v;
}





/*
 * note: Two bytes of alignment padding follow at 0x021BC542.
 * prototype-evidence: r1 is forwarded unchanged from entry into BA928.
 */
int func_021BC51C(char *p, int ret)
{
    if (func_021BA928(p, ret) == 0) return ret;
    if (func_020362DC() != 0) *(u32_021BC51C *)&((struct Obj00008 *)p)->f1CC = 0x44;
    return ret;
}






/*
 * Unit of the lead function plus three unlabelled tail-call stubs
 * (0x021BC5C0/5D4/5E8) that store 0x4b/0x4c/0x4d at +0x132c and tail-call it.
 * The ov099 hint on the 12-byte table is contested, so the data token is bare.
 * The 0x242 offset is an enum-typed local (keeps r4 live, 0x1CC = o - 0x76).
 */
int func_021BC544(char *p, int v)
{
    Tri t = d_021C37DC;
    Off_021BC51C o;

    if (func_0203D378() == 0) {
        o = K242;
        func_021BA874(p, *(u16 *)(p + o) - 1);
        func_021BAAB8(p, ((u32_021BC544 *)&t)[((struct Obj06355 *)p)->f132C - 0x4b], 0);
        *(u32_021BC544 *)(p + (o - 0x76)) = 0x4f;
    } else {
        func_021BAAB8(p, 0x4c, 0);
        func_021BC090((S *)p);
        func_02039C68((struct Link *)func_020399A8(), 0x1b, 0xa);
        ((struct Obj06355 *)p)->f1CC = 0x49;
    }
    return v;
}






int func_021BC5C0(char *p, int v)
{
    ((struct Obj06355 *)p)->f132C = 0x4b;
    return func_021BC544(p, v);
}






int func_021BC5D4(char *p, int v)
{
    ((struct Obj06355 *)p)->f132C = 0x4c;
    return func_021BC544(p, v);
}






int func_021BC5E8(char *p, int v)
{
    ((struct Obj06355 *)p)->f132C = 0x4d;
    return func_021BC544(p, v);
}






int func_021BC5FC(char *p, int v)
{
    if (func_021BA928(p, v) == 0) {
        return v;
    }

    func_021BA828(p);
    *(u32_021BC5FC *)&((struct Obj00008 *)p)->f1CC = 0x50;
    return v;
}






/*
 * Lever: the +0x1CC store is written out in each arm (no early return), so the
 * compiler cross-jumps them into one shared store block.
 */
int func_021BC620(char *p, int v)
{
    int r;

    func_0201DD68();
    r = func_021BA858(p);
    if (r == -1) {
        return v;
    }
    if (r == 0) {
        if (func_021BDDD0(p) == 0 && ((struct Obj04413 *)p)->f132C == 0x4d) {
            func_021BAAB8(p, 0x79, 0);
            ((struct Obj04413 *)p)->f1CC = 0x96;
        } else if (func_0202EB14() == 0 && func_0202EB0C() != 0
                   && ((struct Obj04413 *)p)->f132C == 0x4c) {
            func_021BAAB8(p, 0x95, 0);
            ((struct Obj04413 *)p)->f1CC = 0xa6;
        } else {
            ((struct Obj04413 *)p)->f1CC = 0x52;
            func_021BA8EC(p);
        }
    } else {
        ((struct Obj04413 *)p)->f1353 = 0x90;
        ((struct Obj04413 *)p)->f1CC = 0x8a;
    }
    return v;
}






int func_021BC6B0(char *p, int v)
{
    if (func_021BA928(p, v) == 0)
        return v;
    if (func_020362DC() == 0)
        return v;
    if (*(u32_021BC6B0 *)(p + 0x135C) - 3 <= 1u)
        *(u8 *)(p + 0x1353) = 0x90;
    else
        *(u8 *)(p + 0x1353) = 0x97;
    *(u32_021BC6B0 *)(p + 0x1CC) = 0x8A;
    return v;
}





int func_021BC6F4(char *p, int v)
{
    u32 *a = (u32 *)p;
    Idx k;

    if (func_0203D378() != 0) {
        k = K73;
        func_021BAAB8(p, 0x73, 0);
        func_02039C68((struct Link *)func_020399A8(), 0x1b, 0xa);
        a[k] = 0x49;
    } else {
        func_021BAAB8(p, 0x72, 0);
        a[0x78] = 0x78;
        a[0x73] = 0x8f;
    }
    return v;
}





/*
 * Ages the counter at +0x1E0 into the guard call, then stamps the byte at
 * +0x1353 and selector 0x8A when it has gone negative; returns the selector.
 * The guard call takes the aged value, not the selector.
 */
int func_021BC73C(char *p, int v)
{
    func_021BA928(p, --((struct Obj07225 *)p)->f1E0);

    if (((struct Obj07225 *)p)->f1E0 < 0) {
        ((struct Obj07225 *)p)->f1353 = 0x79;
        ((struct Obj07225 *)p)->f1CC = 0x8A;
    }

    return v;
}



int func_021BC76C(u8 *p, int b)
{
    p[0x1353] = 0x51;
    *(u32 *)(p + 0x1cc) = 0x8a;
    return b;
}



int func_021BC784(u8 *p, int b)
{
    p[0x1353] = 0x4a;
    *(u32 *)(p + 0x1cc) = 0x8a;
    return b;
}



int func_021BC79C(u8 *p, int b)
{
    p[0x1353] = 0x84;
    *(u32 *)(p + 0x1cc) = 0x8a;
    return b;
}








int func_021BC7B4(char *p, int v)
{
    int r4;
    int sel;

    func_021C282C(*(u8 * *)&((struct Obj04414 *)p)->f8);
    ((struct Obj04414 *)p)->f1351 = 0;
    sel = ((struct Obj04414 *)p)->f132C;
    switch (sel) {
    case 0x4b:
        r4 = 4;
        break;
    case 0x4c:
        r4 = 5;
        break;
    case 0x4d:
        r4 = 6;
        break;
    }
    switch (sel) {
    case 0x4b:
        func_021BC104(p);
        func_021BAADC(p, 0x7b, 0);
        func_021C18C8(p, 4, 4);
        func_021C24A4(p, 0);
        ((struct Obj04414 *)p)->f1355 = 0;
        ((struct Obj04414 *)p)->f1CC = 0x10;
        break;
    case 0x4c:
        func_021BA8EC(p);
        ((struct Obj04414 *)p)->f1D0 = r4;
        v = 2;
        break;
    case 0x4d:
        func_021BC104(p);
        func_021BA8EC(p);
        ((struct Obj04414 *)p)->f1D0 = r4;
        v = 2;
        break;
    }
    func_021C18C8(p, 4, r4);
    return v;
}








/*
 * Runs the setup for selector 0x54 with the true flag and stamps it 0x1CC bytes in.
 */
int func_021BC850(char *p, int v)
{
    func_021BB954(p, 1);
    ((struct Obj18192 *)p)->f1CC = 0x54;
    return v;
}







int func_021BC868(char *p, int v)
{
    int r;
    void *q;
    q = ((struct Obj00977 *)p)->f1B8;
    if (((struct Obj00977 *)p)->f1B0 != 0) {
        if (func_0201C6C4(q, func_02045770(((struct Obj00977 *)p)->f1AC)) == 0) {
            func_02045334(((struct Obj00977 *)p)->f1AC);
            ((struct Obj00977 *)p)->f1B0 = 0;
        }
    }
    r = func_020200CC(((struct Obj00977 *)p)->fBC);
    if (r == -1) return v;
    func_021BA8EC(p);
    ((struct Obj00977 *)p)->f1A4 = (void *)func_021BA8BC(((struct Obj00977 *)p)->f1A4);
    func_0202020C(((struct Obj00977 *)p)->fBC, 0, (u16 *)(p + 0x234));
    func_0201F868(((struct Obj00977 *)p)->fB8);
    if (r == -2) {
        if (((struct Obj00977 *)p)->f135C == 3 || ((struct Obj00977 *)p)->f135C == 4) {
            func_021BA874(p, ((struct Obj00977 *)p)->f242 - 1);
            func_021BAAB8(p, 0x60, 0);
            ((struct Obj00977 *)p)->f1CC = 0x45;
        } else {
            ((struct Obj00977 *)p)->f1CC = 0x1c;
        }
    } else {
        if (((struct Obj00977 *)p)->f135C == 3 || ((struct Obj00977 *)p)->f135C == 4) {
            ((struct Obj00977 *)p)->f1CC = r;
        } else if (r == 0x5b) {
            ((struct Obj00977 *)p)->f1CC = 0x75;
        } else {
            ((struct Obj00977 *)p)->f1CC = r;
        }
    }
    return v;
}








int func_021BC940(char *p, int v)
{
    func_021BB9C8((int)p);
    ((struct Obj18193 *)p)->f1CC = 0x56;
    return v;
}








/*
 * Twins: func_021BCA14 (+0x22 byte, +0x134e halfword) and func_021BCAD0
 * (stores 1 - r at +0x20).
 */
int func_021BC958(char *p, int v)
{
    int r;
    int q;

    q = ((struct Obj01915 *)p)->f1B8;
    if (((struct Obj01915 *)p)->f1B0 != 0) {
        if (func_0201C6C4((struct PrintSys *)q, (void *)((int)func_02045770((struct Descriptor *)((struct Obj01915 *)p)->f1AC))) == 0) {
            func_02045334((struct Descriptor *)((struct Obj01915 *)p)->f1AC);
            ((struct Obj01915 *)p)->f1B0 = 0;
        }
    }
    r = func_020200CC((struct Obj *)(((struct Obj01915 *)p)->fBC));
    if (r != -2) {
        if (r == -1) {
            return v;
        }
        ((struct Obj01915 *)p)->f134C = r;
        ((struct Obj22029 *)(*(char * *)&((struct Obj01915 *)p)->f248))->f21 = r;
    }
    ((struct Obj01915 *)p)->f1CC = 0x4e;
    func_021BA8EC(p);
    ((struct Obj01915 *)p)->f1A4 = (void *)func_021BA8BC(((struct Obj01915 *)p)->f1A4);
    func_0202020C((struct Obj *)(((struct Obj01915 *)p)->fBC), 0, (u16 *)(p + 0x236));
    func_0201F868((void *)(((struct Obj01915 *)p)->fB8));
    return v;
}








int func_021BC9FC(char *p, int v)
{
    func_021BB9F4((int)p);
    ((struct Obj18194 *)p)->f1CC = 0x58;
    return v;
}








/*
 * Twin of func_021BC958 (+0x22 byte, +0x134e halfword, +0x238 out slot).
 */
int func_021BCA14(char *p, int v)
{
    int r;
    int q;

    q = ((struct Obj01916 *)p)->f1B8;
    if (((struct Obj01916 *)p)->f1B0 != 0) {
        if (func_0201C6C4((struct PrintSys *)q, (void *)((int)func_02045770((struct Descriptor *)((struct Obj01916 *)p)->f1AC))) == 0) {
            func_02045334((struct Descriptor *)((struct Obj01916 *)p)->f1AC);
            ((struct Obj01916 *)p)->f1B0 = 0;
        }
    }
    r = func_020200CC((struct Obj *)(((struct Obj01916 *)p)->fBC));
    if (r != -2) {
        if (r == -1) {
            return v;
        }
        ((struct Obj01916 *)p)->f134E = r;
        ((struct Obj22030 *)(*(char * *)&((struct Obj01916 *)p)->f248))->f22 = r;
    }
    ((struct Obj01916 *)p)->f1CC = 0x4e;
    func_021BA8EC(p);
    ((struct Obj01916 *)p)->f1A4 = (void *)func_021BA8BC(((struct Obj01916 *)p)->f1A4);
    func_0202020C((struct Obj *)(((struct Obj01916 *)p)->fBC), 0, (u16 *)(p + 0x238));
    func_0201F868((void *)(((struct Obj01916 *)p)->fB8));
    return v;
}








int func_021BCAB8(char *p, int v)
{
    func_021BBA20((int)p);
    ((struct Obj18201 *)p)->f1CC = 0x5A;
    return v;
}








/*
 * Twin of func_021BC958: stores 1 - r at +0x20 of the record at +0x248 and
 * hands +0x23a to func_0202020C.
 */
int func_021BCAD0(char *p, int v)
{
    int r;
    int q;

    q = ((struct Obj02154 *)p)->f1B8;
    if (((struct Obj02154 *)p)->f1B0 != 0) {
        if (func_0201C6C4((struct PrintSys *)q, (void *)((int)func_02045770((struct Descriptor *)((struct Obj02154 *)p)->f1AC))) == 0) {
            func_02045334((struct Descriptor *)((struct Obj02154 *)p)->f1AC);
            ((struct Obj02154 *)p)->f1B0 = 0;
        }
    }
    r = func_020200CC((struct Obj *)(((struct Obj02154 *)p)->fBC));
    if (r != -2) {
        if (r == -1) {
            return v;
        }
        ((struct Obj22031 *)(*(char * *)&((struct Obj02154 *)p)->f248))->f20 = 1 - r;
    }
    ((struct Obj02154 *)p)->f1CC = 0x4e;
    func_021BA8EC(p);
    ((struct Obj02154 *)p)->f1A4 = (void *)func_021BA8BC(((struct Obj02154 *)p)->f1A4);
    func_0202020C((struct Obj *)(((struct Obj02154 *)p)->fBC), 0, (u16 *)(p + 0x23a));
    func_0201F868((void *)(((struct Obj02154 *)p)->fB8));
    return v;
}







int func_021BCB70(void *rules, const struct BigObj *obj, u32_021BCB70 *mask)
{
    *mask = 0;
    return func_0201A090(rules, func_02012934(obj), mask);
}






/*
 * note: Two bytes of alignment padding follow at 0x021BCBAE.
 */
int func_021BCB8C(void *p)
{
    void *obj = func_0200BAC8(func_02012EBC(p));
    if (func_0200BBA8(obj) == 0) return 0;
    return (int)func_0200BAF4((int)obj, 0x21);
}







/*
 * Free-like guard: calls sub_020307B0 only for a non-null pointer.
 */
void func_021BCBB0(void *p)
{
    if (p != 0) {
        sub_020307B0(p);
    }
}







/*
 * Returns 4 or whatever func_0201A090 answers, and writes 0 or -1 through
 * the third argument.
 */
int func_021BCBBC(int a, int b, int *out)
{
    int r = 4;

    *out = 0;

    if (b != 0) {
        r = func_0201A090((void *)a, (void *)b, (u32_021BCB70 *)((u32_021BCBBC *)out));
    } else {
        *out = -1;
    }

    return r;
}





/*
 * tail-call stub, Ilias's) has no witness outside the unit. Verified C for it
 * (match.py one --thumb, no --region, EXACT, 16 bytes):
 *   extern int func_02048F60(int a, int b, int c);   (0x02048F60 arm)
 *   int func_0201A354(int a, int b) { return func_02048F60(0x69, a, b); }
 * The caller passes (t, 0x21).
 *
 * Unit of the lead function plus the unlabelled 12-byte tail-call stub at
 * 0x021BCC4C (mode 0 -> func_021BCBD8).
 */
u32 func_021BCBD8(char *p, int m)
{
    int a, b, c;
    u8 *rec;
    u32 t;

    switch (m) {
    case 0:
    default:
        a = *(u16 *)(p + 0x134c);
        b = *(u16 *)(p + 0x134e);
        c = *(u8 *)(*(char **)(p + 0x248) + 0x48);
        break;
    case 1:
        rec = *(u8 **)(p + 0x248);
        a = rec[0x21];
        b = rec[0x22];
        c = rec[0x20];
        break;
    }
    t = d_021C3A30[a + b * 4];
    if (*(int *)(p + 0x1348) != 0) {
        func_020307B0((void *)(*(int *)(p + 0x1348)));
    }
    *(int *)(p + 0x1348) = (int)func_0201A354(t, 0x21);
    if (c != 0) {
        t |= 0x80000000;
    }
    return t;
}





u32 func_021BCC4C(char *p)
{
    return func_021BCBD8(p, 0);
}





void func_021BCC58(char *p, u32 x)
{
    u32 m;
    int i;

    ((struct Obj22032 *)(*(char * *)&((struct Obj07944 *)p)->f248))->f48 = (x & 0x80000000) != 0;
    m = x & 0x0fffffff;
    for (i = 0; i < 8u; i++) {
        if (m == d_021C3A30[i]) {
            ((struct Obj07944 *)p)->f134C = i % 4;
            ((struct Obj07944 *)p)->f134E = i / 4;
        }
    }
}





int func_021BCCB8(char *p, int v)
{
    int m;
    u8 *q;

    m = ((struct Obj03732 *)p)->f135C;
    if (m == 3 || m == 1) {
        func_021BCBD8(p, 1);
    } else {
        func_021BCBD8(p, 0);
    }
    if (func_021BDDF4(p) == 0) {
        func_021BAAB8(p, 0x68, 0);
        ((struct Obj03732 *)p)->f1CC = 0x63;
        return v;
    }
    ((struct Obj03732 *)p)->f1352 = 7;
    q = *(u8 * *)&((struct Obj03732 *)p)->f248;
    if (q[0x44] != q[0x45]) {
        ((struct Obj03732 *)p)->f1CC = 0x7D;
    } else {
        ((struct Obj03732 *)p)->f1CC = 0x81;
    }
    func_021BA874(p, ((struct Obj03732 *)p)->f242 - 1);
    if (((struct Obj03732 *)p)->f135C - 3 <= 1u) {
        func_021BAAB8(p, 0xE, 0);
    } else {
        func_021BAAB8(p, 0x4C, 0);
    }
    func_021BC090((S *)p);
    return v;
}




int func_021BCD58(char *p, int v)
{
    int out;

    if (func_021BA928(p, v) == 0) {
        return v;
    }
    if (func_020362DC() != 0) {
        func_021BA8EC(p);
        func_021BCB70((void *)(((struct Obj07945 *)p)->f1348), (const struct BigObj *)(((struct Obj07945 *)p)->fC4), (u32_021BCB70 *)((u32_021BCD58 *)(&out)));
        func_021BBEB4((struct O *)p, out, ((struct Obj22033 *)(*(u8 * *)&((struct Obj07945 *)p)->f248))->f48, 2);
        ((struct Obj07945 *)p)->f1CC = 0x77;
    }
    return v;
}




int func_021BCDB0(char *p, int v)
{
    if (func_020362DC() != 0) {
        func_021BC06C(p);
        if (*(int *)(p + 0xCC) != 0) {
            int out;
            func_021BCBBC(*(int *)(p + 0x1348), *(int *)(p + 0xCC), &out);
            func_021BBEB4((struct O *)p, out, *(u8 *)(*(char **)(p + 0x248) + 0x48), 3);
            *(int *)(p + 0x1CC) = 0x78;
        } else {
            switch (*(int *)(p + 0x135C)) {
            case 3:
                *(int *)(p + 0x1CC) = 0x4E;
                break;
            case 2:
                *(u8 *)(p + 0x1353) = 0x97;
                *(int *)(p + 0x1CC) = 0x8A;
                break;
            case 4:
                *(u8 *)(p + 0x1353) = 0x90;
                *(int *)(p + 0x1CC) = 0x8A;
                break;
            default:
                *(int *)(p + 0x1CC) = 0x72;
                break;
            }
        }
    }
    return v;
}




int func_021BCE30(char *p, int v)
{
    if (func_020362DC() != 0) {
        func_021BC06C(p);
        func_021BA8EC(p);
        switch (*(int *)(p + 0x135C)) {
        case 3:
            *(int *)(p + 0x1CC) = 0x4E;
            break;
        case 2:
            *(u8 *)(p + 0x1353) = 0x97;
            *(int *)(p + 0x1CC) = 0x8A;
            break;
        case 4:
            *(u8 *)(p + 0x1353) = 0x90;
            *(int *)(p + 0x1CC) = 0x8A;
            break;
        default:
            *(int *)(p + 0x1CC) = 0x72;
            break;
        }
    }
    return v;
}




int func_021BCE80(char *p, int v)
{
    func_021BCBD8(p, 1);
    func_021BBEB4((struct O *)p, 0, ((struct Obj18202 *)(*(char * *)&((struct Obj12113 *)p)->f248))->f20, 0);
    ((struct Obj12113 *)p)->f1CC = 0x5D;
    return v;
}



int func_021BCEAC(char *p, int ret)
{
    if (func_020362DC() != 0) {
        func_021BC06C(p);
        ((struct Obj04412 *)p)->f1CC = 0x4E;
    }
    return ret;
}




int func_021BCECC(char *p, int v)
{
    if (func_0203D378() == 0) {
        func_021BCC4C((char *)p);
        func_021BBEB4((struct O *)p, 0, ((struct Obj22034 *)(*(u8 * *)&((struct Obj05262 *)p)->f248))->f48, 1);
        func_021BA874(p, ((struct Obj05262 *)p)->f242 - 1);
        func_021BA978(p, ((struct Obj05262 *)p)->f134C + 0x69 + (((struct Obj05262 *)p)->f134E << 2), 0, 1);
        ((struct Obj05262 *)p)->f1CC = 0x7A;
    } else {
        func_021BAAB8(p, 0x4C, 0);
        func_021BC090((S *)p);
        func_02039C68((struct Link *)func_020399A8(), 0x1B, 0xA);
        ((struct Obj05262 *)p)->f1CC = 0x49;
    }
    return v;
}




int func_021BCF4C(char *p, int v)
{
    if (func_021BA928(p, v) == 0) {
        return v;
    }

    *(u32_021BCF4C *)&((struct Obj00008 *)p)->f1CC = 0x7B;
    return v;
}



int func_021BCF6C(char *p, int ret)
{
    if (func_020362DC() != 0) {
        func_021BC06C(p);
        ((struct Obj04412 *)p)->f1CC = 0x7C;
    }
    return ret;
}



int func_021BCF8C(char *p, int ret)
{
    ((struct Obj22035 *)p)->f1CC = 0x60;
    return ret;
}



int func_021BCF98(char *p, int ret)
{
    return ret;
}
