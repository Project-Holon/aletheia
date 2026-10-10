/*
 * file:     intrude_field.c
 * unit:     yes
 * function: func_0217AE20, func_0217AFC4, func_0217B044, func_0217B084, func_0217B1DC, func_0217B214, func_0217B410, func_0217B4D8, func_0217B5DC, func_0217B600, func_0217B810, func_0217B82C, func_0217B930, func_0217B94C, func_0217B968, func_0217BA48, func_0217BA54, func_0217BAB4, func_0217BBCC, func_0217BBD8, func_0217BC94, func_0217BCDC, func_0217BDE0, func_0217BEA8, func_0217BED4, func_0217BF1C, func_0217BF28, func_0217BF2C, func_0217BF84, func_0217BFD8, func_0217C070, func_0217C094, func_0217C0A8, func_0217C11C, func_0217C14C, func_0217C194, func_0217C1D0, func_0217C274, func_0217C294, func_0217C2A0, func_0217C37C, func_0217C458, func_0217C4D0, func_0217C658, func_0217C688
 * address:  0x0217AE20
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02026474  0x02026474  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_02026454  0x02026454  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02012950  0x02012950  thumb
 *   func_02175004  0x02175004  thumb  ov011
 *   func_02175598  0x02175598  thumb  ov011
 *   func_02167590  0x02167590  thumb  ov010
 *   func_021677E4  0x021677E4  thumb  ov010
 *   func_021675D0  0x021675D0  thumb  ov010
 *   func_02167848  0x02167848  thumb  ov010
 *   func_021679C4  0x021679C4  thumb  ov010
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_021A3460  0x021A3460  thumb  ov021
 *   func_021679A4  0x021679A4  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_021907A8  0x021907A8  thumb  ov021
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_02190788  0x02190788  thumb  ov021
 *   func_02190740  0x02190740  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020124E4  0x020124E4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_02158344  0x02158344  thumb  ov010
 *   func_021584A4  0x021584A4  thumb
 *   func_02175BE4  0x02175BE4  thumb  ov011
 *   func_02175548  0x02175548  thumb
 *   func_0217C758  0x0217C758  thumb
 *   func_0217C820  0x0217C820  thumb
 *   func_02188D20  0x02188D20  thumb
 *   func_02188C9C  0x02188C9C  thumb
 *   func_02190758  0x02190758  thumb
 *   func_021BC5A0  0x021BC5A0  thumb
 *   func_020120F8  0x020120F8  thumb
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0216B340  0x0216B340  thumb  ov010
 *   d_02182B90     0x02182B90  data   a4
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0201210C  0x0201210C  thumb
 *   func_02012798  0x02012798  thumb
 *   func_02012A90  0x02012A90  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02185214  0x02185214  thumb
 *   func_02188BE8  0x02188BE8  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021909BC  0x021909BC  thumb
 *   func_02190BE4  0x02190BE4  thumb
 *   func_02190C78  0x02190C78  thumb
 *   func_02190E40  0x02190E40  thumb
 *   func_02190E74  0x02190E74  thumb
 *   func_02190EF0  0x02190EF0  thumb
 *   func_02190F64  0x02190F64  thumb
 *   func_021A3238  0x021A3238  thumb
 *   func_0202648C  0x0202648C  thumb
 *   func_02026460  0x02026460  thumb
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   func_02012204  0x02012204  thumb
 *   func_020120D8  0x020120D8  thumb
 *   func_020392B8  0x020392B8  arm
 *   func_0202640C  0x0202640C  thumb
 *   func_02030734  0x02030734  arm
 *   func_020263D8  0x020263D8  thumb
 *   d_02183AE0     0x02183AE0  data   a1
 *   func_02012AE4  0x02012AE4  thumb
 *   func_02175E90  0x02175E90  thumb  ov011
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_02175274  0x02175274  thumb  ov011
 *   func_02039338  0x02039338  arm
 *   func_02175710  0x02175710  thumb  ov011
 *   func_02161FEC  0x02161FEC  thumb  ov010
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_02159B48  0x02159B48  thumb  ov010
 *   func_02159B94  0x02159B94  thumb  ov010
 *   func_02159BBC  0x02159BBC  thumb
 *   func_0218CD20  0x0218CD20  thumb  ov021
 *   func_02012114  0x02012114  thumb
 *   func_02008550  0x02008550  thumb
 *   func_021A3220  0x021A3220  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_021A322C  0x021A322C  thumb  ov021
 *   func_02175B8C  0x02175B8C  thumb  ov011
 *   func_02175BBC  0x02175BBC  thumb  ov011
 *   func_02175B34  0x02175B34  thumb  ov011
 *   func_02175CF4  0x02175CF4  thumb  ov011
 *   func_0216D828  0x0216D828  thumb  ov010
 *   func_02182124  0x02182124  thumb  ov018
 *   d_021DB810     0x021DB810  data   ov021  a2
 *   d_021DB834     0x021DB834  data   ov021  a2
 *   d_02182B9C 0x02182B9C data ov018 a4
 *   d_02182B60     0x02182B60  data   a4
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   d_02182B6C     0x02182B6C  data   a4
 *   d_02182B54 0x02182B54 data a4
 *   func_02013D9C  0x02013D9C  thumb
 *   func_0202647C  0x0202647C  thumb
 *   func_02176258 0x02176258 thumb ov011
 *   func_02026478  0x02026478  thumb
 *   func_02012B80  0x02012B80  thumb
 *   d_021700A4 0x021700A4 data a4
 *   d_02170128 0x02170128 data a2
 *   d_021835D4     0x021835D4  data   a4
 *   func_0202A188  0x0202A188  thumb
 *   d_0218360C     0x0218360C  data   a4
 *   d_0218362C     0x0218362C  data   a4
 *   func_0216D63C 0x0216D63C thumb ov010
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02008530  0x02008530  thumb
 *   func_020186C8  0x020186C8  thumb
 *   func_020173F0  0x020173F0  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02018A00  0x02018A00  thumb
 *   func_02017988  0x02017988  thumb
 *   func_0201808C  0x0201808C  thumb
 *   func_020180F4  0x020180F4  thumb
 *   func_02166618  0x02166618  thumb  ov010
 *   func_02166640  0x02166640  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0202A128  0x0202A128  thumb
 *   func_0202A170  0x0202A170  thumb
 *   func_02005728  0x02005728  thumb
 *   d_02183678     0x02183678  data  a4
 *   d_021835F8     0x021835F8  data  a4
 *   d_02183650     0x02183650  data  a4
 *   func_0217F2B4  0x0217F2B4  thumb  ov018
 *   func_02174E14  0x02174E14  thumb  ov011
 *   func_0217F528  0x0217F528  thumb  ov018
 *   func_021762D8  0x021762D8  thumb  ov011
 *   func_0217F574  0x0217F574  thumb  ov018
 *   func_02029830  0x02029830  thumb
 *   func_02005F38  0x02005F38  thumb
 *   func_02029620  0x02029620  thumb
 *   func_0217F58C  0x0217F58C  thumb  ov018
 *   func_02173FC0  0x02173FC0  thumb  ov011
 *   func_02175A24  0x02175A24  thumb  ov011
 *   func_0217F318  0x0217F318  thumb  ov018
 *   func_020061E4  0x020061E4  thumb
 *   d_021836A0     0x021836A0  data  a1
 */
#include "../../matched/include/Obj09386.h"
#include "../../matched/include/Obj09388.h"
#include "../../matched/include/Obj12483.h"
#include "../../matched/include/Obj19353.h"
#include "../../matched/include/Obj12484.h"

struct Ctx;
struct SaveBlock;
struct Sub24;
struct Rec44;
struct Work_0217AE20;
struct BigObj;
struct Src;
struct Desc;
struct Obj_0217AE20;
struct Rec_0217AE20;
struct WordSet;
struct U16Vec;
struct MsgBank;
struct VecFx32;
struct Comm;
struct Evt;
struct Vec12;
struct Fx;
struct Obj2;
struct Obj00020;
struct Sub0200852CObj;
struct Mon;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    int f0;
    u8 pad4[0x12];
    u16 lo : 9;
    u16 mode : 6;
    u16 hi : 1;
    u16 f18;
    u16 pad1a;
} Rec_0217AE20;

typedef struct {
    u8 a : 2;
    u8 state : 2;
    u8 rest : 4;
} Flags;

typedef struct {
    u8 pad0[8];
    int f8;
    u8 padc[0x78];
    u16 f84;
    u8 pad86[6];
    Rec_0217AE20 recs[3];
    u8 padE0[0x81B];
    u8 f8fb;
    u8 pad8fc;
    u8 f8fd;
    u8 pad8fe[6];
    Flags f904;
    u8 pad905[0xB];
    u8 f910;
} Obj_Hdr;

typedef short s16_0217AE20;

typedef struct {
    int f00;
    void *f04;
    int pad[2];
    int f10;
    u16 f14;
    u16 f16;
} Task;

typedef struct {
    unsigned char *f0;
    int f4;
    int f8;
    int fc;
    int f10;
    u16 f14;
} Obj_0217B084;

typedef struct {
    unsigned char *f0;
    int f4;
    int f8;
    int fc;
    struct WordSet *f10;
    u16 f14;
    u8 f16;
    u8 f17;
    int f18;
} Obj_0217AE20;

typedef struct {
    u8 pad0[0x86];
    u16 slot : 3;
    u16 rest : 13;
} Peer;

typedef struct {
    u8 b0;
    u8 b1;
    u16 h2;
} Tmp;

typedef struct { int x, y, z; } V12;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    u8 f10[0x18];
    u16 f28;
} Obj_0217B600;

typedef struct {
    int f0;
    int f4;
    u8 f8[1];
} Work_0217AE20;

typedef struct { int x, y, z; } Vec;

typedef struct {
    int f00;
    int f04;
    int pad;
    u16 pad2;
    u8 f0e;
} Rec_0217B600;

typedef struct { u16 f : 3; u16 g : 13; } Fh;

typedef struct { u8 lo : 4; u8 b4 : 1; u8 hi : 3; } Fb;

typedef struct { u32 f : 4; u32 g : 28; } Fw;

typedef struct { s16_0217AE20 x, y, z; } Vec3s;

typedef struct { s16_0217AE20 x, y, z, w; } Ent_0217B600;

typedef struct { u32 x:10; u32 rest:22; u32 y, z; } Entry_0217AE20;

typedef struct { u16 a, b; int c; } Sub;

typedef struct {
    u16 f00, f02;
    u16 pad04[3];
    u16 f0a;
    u16 pad0c[8];
    Sub s;
} Buf;

typedef enum { INDEX_ZERO, INDEX_ONE } Index;

typedef struct { u16 f0, f2, f4, f6, f8; } Ent_0217BED4;

typedef struct { u8 bit:1; u8 rest:7; } Bits_0217AE20;

typedef struct {
    u16 h0;
    u16 h2;
    int w4;
} T;

typedef struct {
    int w[7];
    T t;
} S_0217C14C;

typedef struct {
    u16 h[14];
    T t;
} S_0217C1D0;

typedef struct {
    u32 x : 11;
    u32 gap : 10;
    u32 y : 2;
    u32 z : 6;
    u32 e : 3;
} B;

typedef struct {
    u16 h0;
    u8 b2;
    u8 b3;
} E;

typedef struct {
    int f0;
    int f4;
    int f8;
} O;

typedef unsigned long long u64;

typedef struct {
    u32 species : 11;
    u32 move : 10;
    u32 f21 : 2;
    u32 f23 : 6;
    u32 f29 : 3;
} Entry_0217C2A0;

typedef struct {
    int f0;
    int f4;
    int f8;
} Ctx;

typedef struct {
    int w[13];
} B52;

typedef struct {
    u16 h0;
    u16 pad2;
    void *w4;
    u8 pad8[0x30];
    B52 b38;
    u8 pad6c[0x18];
    u8 b84;
    u8 pad85[3];
} Obj;

typedef signed short s16_0217C2A0;

typedef struct {
    void *f0;
    int f4;
    s16_0217C2A0 f8;
    s16_0217C2A0 fA;
    u16 fC;
    u8 fE;
    u8 fF;
    u8 f10;
    u8 f11;
    u8 f12;
    u8 f13;
    int f14;
} Rec;

typedef struct {
    u32 lo : 4;
    u32 mid : 14;
    u32 hi : 11;
    u32 top : 3;
} Bits_0217C2A0;

typedef struct {
    u8 mask : 3;
    u8 rest : 5;
} Mask;

typedef struct {
    int f00;
    Bits_0217C2A0 f04;
    Mask f08;
    u8 pad09;
    u16 f0A[3];
    u8 f10[8];
    u8 f18[0x1C];
} Info;

typedef struct {
    u16 f00;
    int f04;
    u8 f08[0x30];
    Info f38;
    Rec f6C;
    u8 f84;
} Work_0217C2A0;

typedef struct {
    void *f0;
    int f4;
    s16_0217C2A0 f8, fA;
    u16 fC;
    u8 fE, fF, f10, f11, f12, f13;
    int f14;
} Rec_0217C658;

typedef struct {
    void *f0;
    unsigned char *f4;
    s16_0217C2A0 f8;
    s16_0217C2A0 fA;
    u16 fC;
    u8 fE;
    u8 fF;
    u8 f10;
    u8 f11;
    u8 f12;
    u8 f13;
    int f14;
} Rec_0217C688;

extern u32 func_02012138(const void *p);
extern u32 func_02026474(void *obj);
extern void *func_020120F4(const void *p);
extern u8 func_02012E40(const void *o);
extern u32 func_02026454(void *obj);
extern void *func_020127A4(void *p);
extern u16 func_02012AC8(const void *p);
extern u32 func_02013D5C(u32 id);
extern u32 func_0200FB24(void);
extern int func_02012B70(const void *p);
extern u8 func_02012B58(const void *p);
extern struct Rec44 *func_02012950(void *p, u32 i);
extern void func_02175004(void *p);
extern u16 func_02175598(void *o, u32 id);
extern void func_02167590(void *a, void *w);
extern int func_021677E4(void *p, int i);
extern void func_021675D0(void *w, int idx, int a2, void *src);
extern void func_02167848(void *a0, int a1, void *a2);
extern int func_021679C4(void *w, int i);
extern unsigned int func_021A3098(void *p);
extern int func_021A3460(u32 a, u32 b, u32 c, u32 d);
extern int func_021679A4(int, int, int, int, void *, void *);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(void *p);
extern void MI_CpuFill8(void *p, int v, int n);
extern void *func_021A3074(void *p);
extern int func_0216D3CC(int a0);
extern u16 func_0216D5F8(void *p);
extern void func_0216D410(void *a0, u16 a1);
extern int func_0216D454(int a0, u32 a1, u32 a2, u32 a3);
extern int func_0216D480(void *p);
extern void func_0216D9A0(void *map);
extern u32 *func_0216D9E4(void *c);
extern void *func_02188C7C(void *p);
extern u32 func_02188C54(void *p);
extern int func_021904B0(u32 a, u32 b);
extern int func_021907A8();
extern int func_0219077C(void *p);
extern void func_02190788(void *p);
extern int func_02190740(u32 a, u32 b, u32 c, u32 d);
extern int func_02190728(void *a);
extern u32 func_020362DC(void);
extern u32 func_02045C04(void *rec);
extern void func_02082BCC(void *, int, int);
extern void *func_020124E4(void *p);
extern u8 *func_02012944(void *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201F02C(void *p, u32 i, void *a);
extern void func_0201F250(void *ws, void *dst, void *src);
extern u32 func_0201ED04(void *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(void *bank, u32 index);
extern void func_02045808(void *vec);
extern int func_02158344(int a0);
extern int func_021584A4();
extern int func_02175BE4(void *a);
extern void func_02175548();
extern void func_0217C758();
extern int func_0217C820();
extern int func_02188D20();
extern u16 func_02188C9C(void *p);
extern void func_02190758();
extern void func_021BC5A0();
extern u8 *func_020120F8(const void *p);
extern void func_021A3038(void *p, void *out);
extern struct Desc *func_0216B340(int a0, int a1, void *a2, int a3, int a4);
extern int func_0203D1B4();
extern void *func_0201210C(const void *p);
extern u8 *func_02012798(void *p, int i);
extern void func_02012A90(void *p, const void *src);
extern void func_02012374(void *evt, void *out);
extern void func_02026400(void *p);
extern int func_02185214();
extern int func_02188BE8();
extern void *func_02188CB4();
extern void func_021909BC();
extern int func_02190BE4();
extern int func_02190C78();
extern int func_02190E40();
extern void func_02190E74();
extern int func_02190EF0();
extern int func_02190F64();
extern int func_021A3238();
extern u32 func_0202648C(void *obj);
extern u32 func_02026460(void *obj);
extern int func_02035390(void);
extern int func_020353B0(void);
extern u32 func_02012204(const void *p);
extern int func_020120D8(void *p);
extern int func_020392B8(void);
extern void func_0202640C(void *p, u32 a, u32 b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const void *site, u16 tag);
extern void func_020263D8(void *p, u32 a1, u32 a2);
extern unsigned int func_02012AE4(const void *p);
extern int func_02175E90(void *p, void *q);
extern void func_021A3044(void *p, void *v);
extern void func_02175274(void *, int);
extern u16 func_02039338(void);
extern void func_02175710(void *o, u32 v);
extern void func_02161FEC(void *p, u16 v);
extern unsigned int func_02188C98(void *p);
extern u16 *func_02159B48(int a);
extern int func_02159B94(int a0, int a1, int a2, int a3);
extern void func_02159BBC(int);
extern void func_0218CD20(int, int, int);
extern u32 func_02012114(const void *p);
extern u8 func_02008550(const void *obj);
extern void func_021A3220(void *p, u32 res);
extern void func_0216D8C0(void *, void *);
extern void func_021A322C(void *p);
extern int func_02175B8C(void *);
extern int func_02175BBC(void *);
extern u8 *func_02175B34(void *);
extern int func_02175CF4(void *p, void *q);
extern void func_0216D828(void *, void *);
extern int func_02182124(int, void *, void *);
extern void func_0216CE60(int a, int b, int c);
extern u32 func_02013D9C(u32 id);
extern u32 func_0202647C(void *obj);
extern int func_02176258(void *);
extern unsigned int func_02026478(void *obj);
extern u8 func_02012B80(const void *p);
extern u32 func_0202A188(void *p, u32 a, u32 v2, u32 v3);
extern int func_0216D63C(void *, int);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern u32 func_020307B0(void *p);
extern u32 func_02008530(const void *obj);
extern u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern void *func_020173F0(u16, u16, u64, int);
extern void func_02017588(void *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02018A00(void *p, u32 a, u32 b);
extern u32 func_02017988(void *p, u32 a);
extern u16 func_0201808C(void *, u16);
extern void func_020180F4(void *p, int move);
extern int func_02166618(int);
extern int func_02166640(int);
extern u16 func_02188C84(void *p);
extern int func_0216D83C(void *);
extern int func_0216D86C(void *);
extern int func_0202A128(int);
extern void func_0202A170(int);
extern u32 func_02005728(u32 range);
extern void func_0217F2B4();
extern void func_02174E14(void *p, int a);
extern void func_0217F528(void *, void *, int, int, int, int);
extern void func_021762D8(void *, void *, int, u16);
extern void func_0217F574(void *p, unsigned int index, int a, int b);
extern void *func_02029830(void *a, u32 b);
extern int func_02005F38(void);
extern void *func_02029620(void *a, u32 b, u32 c);
extern void func_0217F58C(void *);
extern int func_02173FC0(int a, void *b);
extern int func_02175A24(void *);
extern void func_0217F318(void *);
extern void func_020061E4(u32 a);
void func_0217AE20(u8 *a0, int a1, int a2);
int func_0217AFC4(int *a, u8 *b, int *out);
void *func_0217B044(void *a, int b, int c, u16 d, u16 e, int f);
int func_0217B084(int a0, int *state, Obj_0217B084 *o, u32 a3);
void *func_0217B1DC(void *a, int b, int c, unsigned short d);
int func_0217B214(int a0, int *state, Obj_0217AE20 *o);
int func_0217B410(int a0, int a1, int a2);
void *func_0217B4D8(int a0, int a1, int a2, int *a3, u16 a4, u16 a5);
void *func_0217B5DC(void *a, int b, int c);
int func_0217B600(int a0, int *state, Obj_0217B600 *o);
void *func_0217B810(void *a, u8 *pos);
int func_0217B82C(int a0, int *state, Work_0217AE20 *w);
int func_0217B930(int *p);
int func_0217B94C(int *p);
void func_0217B968(int a0, void *a1, void *a2, void *a3);
void func_0217BA48(int a, int b);
void func_0217BA54(void *a);
void func_0217BAB4(int a0, void *a1, void *a2, u8 *p);
void func_0217BBCC(int a, int b, char *p);
void func_0217BBD8(u8 *a, int b, u8 *c);
void func_0217BC94(int a, int n);
void func_0217BCDC(u8 *p, void *a1, int id, u8 kind, u8 flag);
int func_0217BDE0(int a, u8 *b, int c);
Entry_0217AE20 *func_0217BEA8(u32 a);
int func_0217BED4(int a, V12 *out);
void func_0217BF1C(void *p);
u8 func_0217BF28(u8 *p);
void func_0217BF2C(int a, u16 b, u16 c, int d, u16 e, u16 f, u16 g);
void func_0217BF84(int a);
int func_0217BFD8(const struct Ctx *a, int b);
int func_0217C070(u8 *p);
void func_0217C094(unsigned char *p);
u8 func_0217C0A8(void *a0);
int func_0217C11C(u32 value);
void func_0217C14C(int a0, u16 a1, u16 a2, int a3);
void func_0217C194(int p);
void func_0217C1D0(const O *o, const B *p, u16 a2, u16 a3, u16 xh0, int xw4);
void func_0217C274(unsigned int *out, char *p);
int func_0217C294(char *a0);
void *func_0217C2A0(int heap, void *a1, const Entry_0217C2A0 *e);
void func_0217C37C(int a0, int a1, Entry_0217C2A0 *list, int a3, int kind);
struct Desc *func_0217C458(void *a0, void *a1, u8 *a2, int a3);
int func_0217C4D0(void *task, int *state, Work_0217C2A0 *w);
void func_0217C658(Rec_0217C658 *p, void *a, int b, u16 c, u8 d, u8 e);
int func_0217C688(Rec_0217C688 *r, void *a1);
extern const V12 d_02182B90;
extern const char d_02183AE0[];
extern u16 d_021DB810[];
extern Ent_0217B600 d_021DB834[];
extern Entry_0217AE20 d_02182B9C[];
extern const V12 d_02182B60;
extern const Buf d_02182B6C;
extern const Ent_0217BED4 d_02182B54[];
extern const u32 d_021700A4;
extern const u16 d_02170128[];
extern const S_0217C14C d_021835D4;
extern const E d_0218360C[];
extern const S_0217C1D0 d_0218362C;
extern const u8 d_02183678[20][2];
extern const u8 d_021835F8[20][2];
extern const u8 d_02183650[20][2];
extern const u8 d_021836A0[4];






void func_0217AE20(u8 *a0, int a1, int a2)
{
    int h;
    Obj_Hdr *p;
    void *ctx;
    int skip;
    int i;
    int r;

    h = func_02012138((const struct Ctx *)a1);
    p = (Obj_Hdr *)func_02026474((void *)h);
    ctx = func_020120F4((const struct Ctx *)a1);
    if (func_02012E40(ctx) == 1)
        return;
    func_0217B968((int)a0, (void *)a1, (void *)h, (void *)a2);
    if (func_02026454((void *)h) != 2 || p == 0)
        return;
    h = func_02012AC8(func_020127A4(ctx));
    if (p->f910 == 0 && func_02013D5C(h) == 1)
        p->f910 = 1;
    func_0217BBD8(a0, a1, (u8 *)p);
    if (p->f8fd != 7 || func_0200FB24() != 0)
        return;
    if (func_02012B70(ctx) == 0) {
        if (p->f904.state == 0) {
            if (func_0217C11C(p->f84) == 1)
                p->f904.state = 1;
            else
                p->f904.state = 2;
        }
        if (p->f904.state == 2)
            return;
    }
    skip = func_02012B58(ctx);
    func_02175004((u8 *)p);
    func_02167590((void *)a1, (struct Work_0217AE20 *)p->f8);
    for (i = 0; i < 3; i++) {
        if (i == skip || !(p->f8fb & (1 << i)))
            continue;
        if (func_021677E4((void *)p->f8, i) == 0) {
            func_02012950(ctx, i);
            r = func_02175598((u8 *)(&p->recs[i]), (u32)func_02012950(ctx, i));
            if (p->recs[i].f18 != 0 || func_02012B70(ctx) != 0)
                func_021675D0((struct Work_0217AE20 *)p->f8, i, r, (struct Src *)(&p->recs[i]));
        } else {
            func_02167848((char *)p->f8, i, (char *)(&p->recs[i]));
            if (p->recs[i].f0 == 0) {
                if ((u16)(p->recs[i].mode + 0xFFFE) <= 1)
                    func_021679C4((struct Work_0217AE20 *)p->f8, i);
            }
        }
    }
    func_0217BAB4((int)a0, (void *)a1, (void *)a2, (u8 *)p);
}






int func_0217AFC4(int *a, u8 *b, int *out)
{
    int r;
    int idx;
    int hit;
    int ret;
    s16_0217AE20 v[3];

    ret = 0;
    hit = ret;
    if (a == 0 || a[2] == 0)
        return 0;
    r = func_021A3098(b);
    if (r != 0 && r != 1)
        return ret;
    func_021A3460((u32)b, (u32)(v + 2), (u32)(v + 1), (u32)v);
    for (;;) {
        r = func_021679A4(a[2], v[2], v[1], v[0], &idx, &hit);
        if (r != 1)
            break;
        if (*(int *)((char *)a + idx * 28 + 0x8c) == 0) {
            *out = idx;
            return 1;
        }
    }
    return 0;
}






void *func_0217B044(void *a, int b, int c, u16 d, u16 e, int f)
{
    void *t;
    Task *p;

    t = func_020122C0(a, 0, func_0217B084, sizeof(Task));
    p = func_020124E8(t);
    MI_CpuFill8(p, 0, sizeof(Task));
    p->f00 = b;
    p->f04 = func_021A3074((void *)c);
    p->f16 = d;
    p->f14 = e;
    p->f10 = f;
    return t;
}






int func_0217B084(int a0, int *state, Obj_0217B084 *o, u32 a3)
{
    u16 m;
    int t;
    int h;

    switch (*state) {
    case 0:
        if (func_0216D3CC(o->f4) == 1) {
            if (o->f14 == 3)
                t = 3;
            else
                t = 2;
            m = t;
            if (o->f14 != func_0216D5F8((void *)o->f4)) {
                func_0216D410((void *)o->f4, m);
                *state += 1;
            } else {
                *state = 2;
            }
        }
        break;
    case 1:
        if (func_0216D454(o->f4, (u32)state, (u32)o, a3) == 1) {
            func_0216D480((char *)o->f4);
            *state += 1;
        }
        break;
    case 2:
        func_0216D9A0(func_02188C7C(o->f0));
        h = func_02188C54(o->f0);
        o->f8 = func_021904B0(h, 0x2D);
        o->fc = func_021907A8(h, o->f8);
        func_02190740(o->fc, 0, 0, o->f10 == 0 ? 0x52 : 0x4F);
        *state += 1;
        break;
    case 3:
        if (func_0219077C((u8 *)o->fc) == 1)
            *state += 1;
        break;
    case 4:
        if (o->f10 == 0) {
            if (func_020362DC() & 3)
                *state += 1;
        } else {
            if (func_020362DC() & 0xF3)
                *state = 8;
        }
        break;
    case 5:
        func_02190788((u8 *)o->fc);
        func_02190740(o->fc, 0, 0, 0x53);
        *state += 1;
        break;
    case 6:
        if (func_0219077C((u8 *)o->fc) == 1)
            *state += 1;
        break;
    case 7:
        if (func_020362DC() & 0xF3)
            *state += 1;
        break;
    case 8:
        func_02190728((void *)o->fc);
        func_02045C04((struct Rec_0217AE20 *)o->f8);
        *state += 1;
        break;
    case 9:
        if (func_0216D3CC(o->f4) == 1) {
            func_0216D410((void *)o->f4, (u16)(o->f14 == 3 ? 10 : 11));
            *state += 1;
        }
        break;
    case 10:
        if (func_0216D454(o->f4, (u32)state, (u32)o, a3) == 1) {
            func_0216D480((char *)o->f4);
            func_0216D9E4(func_02188C7C(o->f0));
            return 1;
        }
        break;
    }
    return 0;
}





void *func_0217B1DC(void *a, int b, int c, unsigned short d) {
    void *t;
    u8 *p;
    t = func_020122C0(a, 0, func_0217B214, 0x30);
    p = func_020124E8(t);
    func_02082BCC(p, 0, 0x30);
    ((struct Obj09386 *)p)->f0 = b;
    ((struct Obj09386 *)p)->f4 = (int)func_021A3074((u8 *)c);
    ((struct Obj09386 *)p)->f14 = d;
    return t;
}






int func_0217B214(int a0, int *state, Obj_0217AE20 *o)
{
    void *w;
    int h;
    void *ctx;
    Peer *p;
    int t;
    struct U16Vec *a;
    void *b;
    Tmp tmp;

    w = func_020124E4((struct Obj_0217AE20 *)a0);
    h = func_02012138(w);
    ctx = func_020120F4(w);
    p = (Peer *)func_02158344(h);
    switch (*state) {
    case 0:
        func_0216D9A0(func_02188C7C(o->f0));
        *state += 1;
        break;
    case 1:
        if (func_0216D3CC(o->f4) == 0)
            break;
        if (p == 0) {
            *state = 6;
            break;
        }
        if (func_02175BE4((u8 *)p + 0x1AC) == 1) {
            o->f16 = 1;
            func_0217C758(&o->f18, w, o->f0, p, 0, 0, 0, o->f14, 0);
        } else if (func_021584A4(h, ctx, o->f14) == 1) {
            func_0217C758(&o->f18, w, o->f0, p, 0, 0, 0, o->f14, 1);
        } else {
            func_02175548(func_02012944(ctx), &tmp.h2, &tmp.b1, &tmp.b0);
            func_0217C758(&o->f18, w, o->f0, p, tmp.h2, tmp.b1, tmp.b0, o->f14, 1);
        }
        *state += 1;
        break;
    case 2:
        if (func_0217C820(&o->f18, p) == 1)
            *state += 1;
        break;
    case 3:
        if (p == 0) {
            *state = 6;
            break;
        }
        t = func_02188C54(o->f0);
        o->f8 = func_021904B0(t, 0x2D);
        o->fc = func_021907A8(t, o->f8);
        o->f10 = func_0201EC64(4);
        if (p->slot == func_02012B58(ctx)) {
            if (o->f16 == 1)
                func_02190740(o->fc, 0, 0, 0x4F);
            else
                func_02190740(o->fc, 0, 0, 0x4E);
        } else {
            a = func_020457B0(0x100, 0x15);
            func_0201F02C(o->f10, 0, func_02012950(ctx, p->slot));
            if (o->f16 == 1)
                b = func_02045EC0((struct MsgBank *)o->f8, 0x50);
            else
                b = func_02045EC0((struct MsgBank *)o->f8, 0x51);
            func_0201F250(o->f10, a, b);
            func_02190758(o->fc, 0, 0, a);
            func_02045808(b);
            func_02045808(a);
        }
        *state += 1;
        break;
    case 4:
        if (func_0219077C((u8 *)o->fc) == 1) {
            t = func_02188D20(o->f0);
            func_021BC5A0(t, func_02188C9C(o->f0));
            *state += 1;
        }
        break;
    case 5:
        if (func_020362DC() & 0xF3)
            *state += 1;
        break;
    case 6:
        if (o->fc != 0) {
            func_02190728((void *)o->fc);
            func_02045C04((struct Rec_0217AE20 *)o->f8);
            func_0201ED04(o->f10);
        }
        func_0216D9E4(func_02188C7C(o->f0));
        return 1;
    }
    return 0;
}






int func_0217B410(int a0, int a1, int a2)
{
    int h;
    int w;
    int i;
    int base;
    V12 pos;
    V12 v;

    h = func_02012AC8((const struct Rec44 *)func_020120F8((const struct Ctx *)a1));
    w = func_02158344(func_02012138((const struct Ctx *)a1));
    if (func_02013D5C(h) == 0)
        return 0;
    func_021A3038((unsigned char *)a2, (struct VecFx32 *)&pos);
    for (i = 0; i < 3; i++) {
        if (pos.x >= (i << 22) + 0x1F8000 && pos.x <= (i << 22) + 0x1F8000 && pos.z >= 0x2C8000 && pos.z <= 0x2C8000)
            return (int)func_0217B5DC((void *)a1, a0, (int)w);
    }
    base = 0x1F8000;
    for (i = 0; i < 3; i++) {
        if (pos.x >= base && pos.x < base + 0x20000 && pos.z == 0x158000) {
            v = d_02182B90;
            v.x += pos.x - base;
            return (int)func_0216B340(a1, 1, &v, 0, 4); /* int-typed on purpose: function returns int */
        }
        base += 0x400000;
    }
    return 0;
}






void *func_0217B4D8(int a0, int a1, int a2, int *a3, u16 a4, u16 a5)
{
    u8 *p;
    u16 r;
    int col;
    int x;
    int n;
    int sub;

    p = (u8 *)func_02158344(func_02012138((const struct Ctx *)a0));
    r = 9;
    x = *a3;
    n = 1;
    if (p)
        n = p[0x902];
    if (x <= 0) {
        x += n << 22;
    } else if (x >= n << 22) {
        x -= n << 22;
    }
    col = ((x >> 12) / 16) % 64;
    sub = x % 0x400000;
    if (a5 == 2) {
        if ((a4 != 3 || (a4 == 3 && sub <= 0x8000)) && col == 0)
            r = 2;
    } else if (a5 == 3) {
        if ((a4 != 2 || (a4 == 2 && sub >= 0x3F8000)) && col == 0x3F)
            r = 3;
    }
    if (r != 9) {
        if (p == 0 || func_0203D1B4() <= 1 || p[0x902] < 2)
            return func_0217B044((void *)a0, a1, a2, a4, r, 0);
        if (func_02175BE4(p + 0x1AC) == 1)
            return func_0217B044((void *)a0, a1, a2, a4, r, 1);
        return func_0217B1DC((void *)a0, a1, a2, r);
    }
    return 0;
}



void *func_0217B5DC(void *a, int b, int c) {
    void *t;
    u8 *p;
    t = func_020122C0(a, 0, func_0217B600, 0x2c);
    p = func_020124E8(t);
    func_02082BCC(p, 0, 0x2c);
    return t;
}






/*
 * Byte-correct (528 of 528 bytes).  Sole blocker: the THM_CALL at +0x13C to
 * 0x02012798, an unlabelled arm9 leaf that disasm.py prints as .word data in
 * pool_02012794 (asm/arm9/main.s), after the pop at 0x02012790 and before
 * func_020127A4; no listing labels it and this call is its only witness, so
 * every class refuses it.  Verified EXACT at 0x02012798 (arm9, thumb, 10 B):
 *
 *     u8 *func_02012798(u8 *p, int i) { return p + 4 + i * 0x44; }
 *
 * It is the Rec44 indexer that belongs beside func_02012950 in
 * src/matched/arm9/unit_02012924.c; once it is labelled or matched this file
 * should verify EXACT unchanged.  The 12-byte scratch is a cast u8 buffer
 * (docs/idioms/a-declared-struct-local-folds-to-sp-relative-a-cast-buffer-does-not.md):
 * the stores go through r7, which a declared struct folds to sp.
 */
int func_0217B600(int a0, int *state, Obj_0217B600 *o)
{
    int w;
    int g;
    int h;
    int t;
    int r;
    int ctx;
    int i;
    u8 v[12];
    V12 *pv;

    w = (int)func_020124E4((struct Obj_0217B600 *)a0);
    g = (int)func_0201210C((const struct Ctx *)w);
    h = func_02012138((const struct Ctx *)w);
    switch (*state) {
    case 0:
        func_0216D9A0(func_02188C7C((u8 *)g));
        t = func_02188C54((u8 *)g);
        o->f0 = func_021904B0(t, 0x2D);
        o->f8 = func_02190F64(t, o->f0);
        func_02190E74(o->f8, 0, 0, 0x54);
        *state += 1;
        break;
    case 1:
        if (func_02190EF0(o->f8) == 1) {
            o->fc = func_02190BE4(func_02188C54((u8 *)g), 0);
            *state += 1;
        }
        break;
    case 2:
        r = func_02190C78(o->fc);
        if (r != 2) {
            func_021909BC(o->fc);
            func_02190E40(o->f8);
            o->fc = 0;
            o->f8 = 0;
            if (r == 0)
                *state = 3;
            else
                *state = 11;
        }
        break;
    case 3:
        if (func_0200FB24() == 0 && func_02026454((void *)h) == 2) {
            func_02026400((struct Comm *)h);
            o->f4 = func_021907A8(func_02188C54((u8 *)g), o->f0);
            func_02190740(o->f4, 0, 0, 0x14);
        }
        *state += 1;
        break;
    case 4:
        if (o->f4 == 0 || func_0219077C((u8 *)o->f4) == 1)
            *state += 1;
        break;
    case 5:
        o->f28++;
        if (o->f4 != 0 && o->f28 <= 0x3C)
            break;
        if (func_02026454((void *)h) == 2)
            break;
        ctx = (int)func_020120F4((const struct Ctx *)w);
        pv = (V12 *)v;
        pv->x = 0;
        pv->y = 0;
        pv->z = 0;
        for (i = 0; i < 3; i++)
            func_02012A90((struct Rec44 *)func_02012798((u8 *)ctx, i), (const struct Vec12 *)pv);
        *state += 1;
        break;
    case 6:
        if (o->f4 != 0)
            func_02190728((void *)o->f4);
        func_02045C04((struct Rec_0217B600 *)o->f0);
        *state += 1;
        break;
    case 7:
        g = (int)func_0201210C((const struct Ctx *)w);
        if (func_02188BE8(g) != 1)
            break;
        if (func_021A3238(func_02188CB4(g)) == 0) {
            func_0217C658((Rec_0217C658 *)o->f10, (void *)w, g, 0, 0, 0);
            *state += 1;
        } else {
            *state = 9;
        }
        break;
    case 8:
        if (func_0217C688((Rec_0217C688 *)o->f10, 0) == 1)
            *state += 1;
        break;
    case 9:
        func_02012374((struct Evt *)a0, (struct Evt **)func_02185214(w));
        *state += 1;
        break;
    case 10:
        *state = 14;
        break;
    case 11:
        func_02045C04((struct Rec_0217B600 *)o->f0);
        *state = 12;
        break;
    case 12:
        t = (int)func_021A3074(func_02188CB4(g));
        if (func_0216D3CC(t) == 1) {
            func_0216D410((void *)t, 8);
            *state += 1;
        }
        break;
    case 13:
        if (func_0216D480((char *)func_021A3074(func_02188CB4(g))) == 1)
            *state = 14;
        break;
    case 14:
        func_0216D9E4(func_02188C7C((u8 *)g));
        return 1;
    }
    return 0;
}





void *func_0217B810(void *a, u8 *pos) {
    void *t;
    u8 *p;
    t = func_020122C0(a, 0, func_0217B82C, 0x20);
    p = func_020124E8(t);
    return t;
}







int func_0217B82C(int a0, int *state, Work_0217AE20 *w)
{
    int sys;
    void *obj;
    int hnd;

    sys = (int)func_020124E4((struct Obj_0217B600 *)a0);
    obj = func_0201210C((void *)sys);
    func_02012138((const struct Ctx *)sys);
    switch (*state) {
    case 0:
        func_0216D9A0(func_02188C7C(obj));
        hnd = func_02188C54(obj);
        w->f0 = func_021904B0(hnd, 0x2D);
        w->f4 = (int)(struct Obj2 *)func_02190F64((struct Fx *)hnd, w->f0);
        func_02190E74((u32 *)w->f4, 0, 0, 0x60);
        (*state)++;
        break;
    case 1:
        if (func_02190EF0((u32 *)w->f4) == 1) {
            func_02190E40(w->f4);
            func_02045C04((struct Rec_0217B600 *)w->f0);
            (*state)++;
        }
        break;
    case 2:
        obj = func_0201210C((void *)sys);
        if (func_02188BE8(obj) == 1) {
            if (func_021A3238((void *)func_02188CB4((void *)obj)) == 0) {
                func_0217C658((Rec_0217C658 *)w->f8, (void *)sys, (int)obj, 0, 0, 0);
                (*state)++;
            } else {
                *state = 4;
            }
        }
        break;
    case 3:
        if (func_0217C688((Rec_0217C688 *)w->f8, 0) == 1)
            (*state)++;
        break;
    case 4:
        func_02012374((struct Evt *)a0, (struct Evt **)func_02185214(sys));
        (*state)++;
        break;
    case 5:
        if (obj != 0 && func_02188BE8(obj) == 1) {
            func_0216D9E4(func_02188C7C((void *)obj));
            return 1;
        }
        break;
    }
    return 0;
}






int func_0217B930(int *p) { if (*p >= 0x348000 || *p <= 0xb8000) return 1; return 0; }






int func_0217B94C(int *p) { if (*p > 0x308000 || *p < 0xe8000) return 1; return 0; }







void func_0217B968(int a0, void *a1, void *a2, void *a3)
{
    Vec v;

    if (func_0202648C(a2) != 0)
        return;
    if (func_02026460(a2) == 1)
        return;
    if (func_0200FB24() != 0)
        return;
    if (func_02035390() == 1 && func_020353B0() == 1)
        return;
    if (func_02012204(a1) == 1)
        return;
    if (func_020120D8(a1) == 1)
        return;
    if (func_02013D5C(func_02012AC8((const struct Rec44 *)func_020127A4(func_020120F4(a1)))) == 0)
        return;
    func_021A3038(a3, (struct VecFx32 *)&v);
    switch (func_02026454(a2)) {
    case 0:
        if (func_0217B930((int *)(&v)) == 1)
            func_0217BA54(a1);
        break;
    case 2:
        if (func_0217B930((int *)(&v)) != 0)
            return;
        if (func_020392B8() > 1)
            return;
        if (((u8 *)func_02026474(a2))[0x8FD] == 4)
            return;
        func_02026400(a2);
        break;
    case 1:
        if (func_0217B930((int *)(&v)) == 1)
            func_0202640C(a2, (u32)func_0217BA48, (u32)a1);
        break;
    }
}







void func_0217BA48(int a, int b)
{
    if (b == 0)
        func_0217BA54((void *)a);
}







void func_0217BA54(void *a)
{
    int h;
    Rec_0217B600 *r;

    h = func_02012138(a);
    if (func_0200FB24() != 0)
        return;
    if (func_02012204(a) == 1)
        return;
    if (func_02035390() == 1 && func_020353B0() == 1)
        return;
    r = func_02030734(0x8005, 0x10, 1, d_02183AE0, 0x528);
    r->f0e = 1;
    r->f00 = (int)a;
    r->f04 = h;
    func_020263D8((struct Comm *)h, 2, (u32)r);
}







void func_0217BAB4(int a0, void *a1, void *a2, u8 *p)
{
    int x;
    int idx;
    Vec cur;
    Vec tmp;
    int flag;
    int prev;
    int limit;
    int sys;

    x = (int)func_020120F8(a1);
    sys = func_02012AC8((const struct Rec44 *)x);
    func_02012AE4((const struct Rec44 *)x);
    x = func_02012138(a1);
    flag = 0;
    func_020120F4(a1);
    if ((int)func_02026454((void *)x) != 2)
        return;
    if (p == 0)
        return;
    if (func_02013D5C(sys) == 0)
        return;
    if (p[0x902] < 2)
        return;
    if (func_02175E90(p, p + 0x1AC) == 1)
        return;
    func_021A3038(a2, (struct VecFx32 *)&cur);
    tmp = cur;
    x = cur.x;
    prev = ((Fh *)(p + 0x86))->f;
    limit = (p[0x901] + 1) << 22;
    if (x < 0) {
        tmp.x = limit + x;
        flag = 1;
    } else if (x > limit) {
        tmp.x = x - limit;
        flag = 1;
    }
    if (flag == 1) {
        x = tmp.x;
        if (func_020120D8(a1) == 1) {
            tmp = cur;
            flag = 0;
        }
    }
    idx = x / 0x400000;
    if (flag == 1) {
        func_021A3044(a2, &tmp);
        func_02175274(p, tmp.x);
    }
    idx += func_02039338();
    if (idx > p[0x901])
        idx -= p[0x901] + 1;
    if (prev == idx)
        return;
    func_02175710(p, idx);
    p[0x900] = 1;
    func_02161FEC((char *)(p + 0x35C), (u8)idx);
}






void func_0217BBCC(int a, int b, char *p)
{
    p[0x901] = 0;
}







void func_0217BBD8(u8 *a, int b, u8 *c)
{
    Vec v;
    int n;
    void *h;
    int buf;

    if (c == 0 || a == 0)
        return;
    if (func_02188C98(a) == 0)
        return;
    if (func_02013D5C(func_02188C9C((u8 *)a)) == 0)
        return;
    n = c[0x902] - 1;
    if (n <= 0)
        n = 1;
    if (((unsigned)(c[0x8f8] << 26) >> 31) == 1)
        n = 1;
    if (c[0x901] >= n)
        return;
    h = (void *)func_02188CB4((void *)a);
    if (h == 0)
        return;
    func_021A3038(h, (struct VecFx32 *)&v);
    v.x = v.x % 0x400000;
    if (func_0217B94C((int *)(&v)) == 1)
        return;
    buf = (int)func_02159B48(0x8015);
    func_02159B94(buf, 0x76, 0x76 + 0xa1, 0x8015);
    do {
        func_0218CD20((int)a, func_02188C98(a), buf);
        c[0x901]++;
    } while (c[0x901] < n);
    func_02159BBC(buf);
}







void func_0217BC94(int a, int n)
{
    int r;

    if (n >= 3)
        n = 2;
    r = (int)func_02159B48(0x15);
    func_02159B94(r, 0x76, 0x76 + 0xa1, 0x8015);
    while (n > 0) {
        func_0218CD20(a, func_02188C98((u8 *)a), r);
        n--;
    }
    func_02159BBC(r);
}







void func_0217BCDC(u8 *p, void *a1, int id, u8 kind, u8 flag)
{
    int res;
    void *obj;
    int has;
    int x;
    int y = (int)func_020120F4(a1);
    Vec v = { 0, 0, 0 };

    if (func_02012114(a1) == 0)
        return;
    x = (int)func_02012944(func_020120F4(a1));
    has = func_02008550((const struct Sub0200852CObj *)x);
    if (p != 0) {
        if (id == 0xFFFF) {
            if (((Fh *)(p + 0x86))->f == func_02012B58((const struct BigObj *)y))
                id = 0;
        }
        if (id == 0) {
            kind = has == 0 ? 3 : 4;
            flag = has;
        }
        if (((struct Obj09388 *)p)->f88 == id)
            return;
        ((struct Obj09388 *)p)->f88 = id;
        ((Fb *)(p + 0x8A))->lo = kind;
        ((Fb *)(p + 0x8A))->b4 = flag;
        p[0x900] = 1;
        res = func_02175598(p + 0x70, x);
    } else {
        id = 0;
        res = 1;
        if (has)
            res = 4;
    }
    obj = (void *)func_02188CB4(func_0201210C(a1));
    func_021A3220(obj, (u16)res);
    func_0216D8C0((void *)func_021A3074(obj), &v);
    if (id == 0)
        func_021A322C(obj);
}







int func_0217BDE0(int a, u8 *b, int c)
{
    u8 *e;
    int n;
    int idx;
    Vec3s v;

    if (func_02175B8C(b + 0x1AC) != 1)
        goto fail;
    if (func_02175BBC(b + 0x1AC) != 0)
        goto fail;
    e = func_02175B34(b + 0x1AC);
    if (e == 0)
        goto fail;
    if (((Fw *)(e + 4))->f != 4)
        goto fail;
    if (((Fh *)(b + 0x86))->f != e[0x28])
        goto fail;
    if (func_02175CF4((char *)b, b + 0x1AC) != 0)
        goto fail;
    n = func_02012AC8((const struct Rec44 *)func_020120F8((const struct Ctx *)a));
    func_0216D828((void *)func_021A3074((void *)c), &v);
    idx = ((struct Obj12483 *)e)->f14;
    if (n != d_021DB810[idx])
        goto fail;
    if (v.x != d_021DB834[idx].x)
        goto fail;
    if (v.y != d_021DB834[idx].y)
        goto fail;
    if (v.z != d_021DB834[idx].z)
        goto fail;
    return func_02182124(a, b, e);
fail:
    return 0;
}






Entry_0217AE20 *func_0217BEA8(u32 a) { u32 i; for (i=0; i<218; i++) { if (d_02182B9C[i].x == a) return &d_02182B9C[i]; } return 0; }







int func_0217BED4(int a, V12 *out)
{
    short *p;
    int x, y, z;

    if (func_02013D5C(a) != 1) {
        p = (short *)func_0217BEA8(a);
        if (p == 0)
            return 0;
        z = p[4] << 16;
        y = p[3] << 16;
        x = p[2] << 16;
        out->x = x;
        out->y = y;
        out->z = z;
    } else {
        *out = d_02182B60;
    }
    return 1;
}







void func_0217BF1C(void *p)
{
    func_02082BCC(p, 0, 0x10);
}







u8 func_0217BF28(u8 *p)
{
    return p[0xE];
}







void func_0217BF2C(int a, u16 b, u16 c, int d, u16 e, u16 f, u16 g)
{
    Buf buf;
    void *h;
    int k;
    Sub *q;

    h = func_02188C7C((void *)a);
    k = func_02188C9C((u8 *)a);
    buf = d_02182B6C;
    buf.f00 = g;
    buf.f02 = e;
    buf.f0a = f;
    q = &buf.s;
    q->a = b;
    q->b = c;
    q->c = d;
    func_0216CE60((int)h, (int)(&buf), k);
}






/*
 * lever: enum inner counter preserves the one-iteration loop; unsigned comparison;
 *   named column load fixes the Thumb add operands.
 */
void func_0217BF84(int a)
{
    Index i;
    int j;
    unsigned int column;
    j = 1;
    do {
        i = INDEX_ZERO;
        do {
            column = d_02182B54[i].f2;
            func_0217BF2C(a, column + (j << 6), d_02182B54[i].f4, 0x2001F, d_02182B54[i].f0, d_02182B54[i].f6, j + d_02182B54[i].f8 - 1);
            i++;
        } while ((unsigned int)i < 1);
        j++;
    } while (j < 3);
}







int func_0217BFD8(const struct Ctx *a, int b)
{
    int h;
    int t;
    int w;

    h = (int)func_020120F4((const struct Ctx *)a);
    t = func_02012138((const struct Ctx *)a);
    w = func_02158344(t);
    if (func_02012B70((const struct BigObj *)h) == 0)
        return 0;
    if (w != 0)
        return 0;
    if (func_02012204(a) == 1)
        return 1;
    if (func_02013D5C(b) == 1) {
        if (func_0202648C((void *)t) != 0)
            return 1;
        return 0;
    }
    if (func_02013D9C(b) == 1) {
        if (func_02026454((void *)t) == 2 || (func_02026454((void *)t) == 0 && func_0202647C((void *)t) == 2 && func_0202648C((void *)t) != 0))
            return 1;
        return 0;
    }
    return 1;
}






int func_0217C070(u8 *p)
{
    if (((Bits_0217AE20 *)(p + 0x93f))->bit == 1 || func_02176258(p) == 1)
        return 1;
    return 0;
}






void func_0217C094(unsigned char *p)
{
    if (p != 0) {
        p[0x8F8] |= 0x20;
    }
}







u8 func_0217C0A8(void *a0)
{
    int h;
    u8 *q;
    u8 *obj;

    h = func_02026478(a0);
    if (func_02012B70((const struct BigObj *)h) == 0) {
        obj = func_02012944((void *)h);
    } else if (func_02012B80((const struct BigObj *)h) == func_02012B58((const struct BigObj *)h)) {
        obj = func_02012944((void *)h);
    } else {
        q = 0;
        if (func_02026454(a0) == 2 && func_02026474(a0) != 0)
            q = (u8 *)func_02026474(a0);
        if (q == 0) {
            obj = func_02012944((void *)h);
        } else if (func_02013D5C(((struct Obj19353 *)q)->f84) == 1) {
            obj = func_02012944((void *)h);
        } else {
            obj = (u8 *)func_02012950((struct Sub24 *)h, func_02012B80((const struct BigObj *)h));
        }
    }
    return func_02008550((const struct Sub0200852CObj *)obj);
}





/*
 * lever: index declared before count preserves r3/r4 allocation.
 */
int func_0217C11C(u32 value)
{
    u32 i;
    u32 count;
    count = d_021700A4;
    for (i = 0; i < count; ++i) {
        if (value == d_02170128[i])
            return 1;
    }
    return 0;
}






void func_0217C14C(int a0, u16 a1, u16 a2, int a3)
{
    void *v;
    int c;
    S_0217C14C s;
    T *t;

    v = func_02188C7C((void *)a0);
    c = func_02188C9C((u8 *)a0);
    s = d_021835D4;
    t = &s.t;
    t->h0 = a1;
    t->h2 = a2;
    t->w4 = a3;
    func_0216CE60((int)v, (int)(&s), c);
}





/*
 * extent: two alignment bytes at 0x0217C1CE.
 */
void func_0217C194(int p)
{
    int i;
    if (func_02013D5C(func_02188C9C((u8 *)p)) != 0) {
        for (i = 0; i < 3; ++i)
            func_0217C14C(p, (((i << 22) + 0x1f8000) >> 12) / 16, 29, 32);
    }
}






/*
 * lever: const pointer parameters, u16 argument homes and u16 c/result
 * preserve the original spill and field-load scheduling together.
 */
void func_0217C1D0(const O *o, const B *p, u16 a2, u16 a3, u16 xh0, int xw4)
{
    const E *e;
    int v;
    u16 c;
    S_0217C1D0 s;
    T *t;

    e = &d_0218360C[p->e];
    v = (int)func_02188C7C((u8 *)o->f4);
    c = func_02188C9C((u8 *)o->f4);
    s = d_0218362C;
    s.h[0] = a2;
    s.h[1] = func_0202A188((u8 *)o->f0, (u16)p->x, (u16)p->y, (u16)p->z);
    s.h[2] = e->h0;
    s.h[10] = e->b2;
    s.h[11] = e->b3;
    s.h[7] = o->f8 + a2;
    s.h[8] = ((struct Obj12484 *)p)->f0;
    s.h[9] = ((struct Obj12484 *)p)->f0 >> 16;
    t = &s.t;
    t->h0 = a3;
    t->h2 = xh0;
    t->w4 = xw4;
    func_0216CE60(v, (int)(&s), c);
}





void func_0217C274(unsigned int *out, char *p)
{
    int lo;
    lo = func_0216D63C(p, 1);
    *out = lo | (func_0216D63C(p, 2) << 16);
}






/*
 * Recursive MATCH unblocker: callee of func_0216AC90 (ov010) +0026 and
 * func_0216ACCC (ov010) +0032. Thumb tail-call thunk to 0x0216D63C; the
 * address is coherent Thumb only in ov018 (mid-instruction in ov019/ov176,
 * ARM in ov009), so the ov018 shard makes both sites attest as `matched`.
 */
int func_0217C294(char *a0)
{
    return func_0216D63C(a0, 0);
}





/*
 * The const on the entry pointer is what lets the bitfield loads be
 * scheduled above the outgoing stack-argument stores (48 bytes otherwise).
 */
void *func_0217C2A0(int heap, void *a1, const Entry_0217C2A0 *e)
{
    u8 *tbl;
    u8 lvl;
    u32 id;
    u32 pid;
    void *mon;

    tbl = (u8 *)func_0204A1BC(0xE3, 0, 0, heap);
    lvl = tbl[e->species];
    func_020307B0(tbl);
    id = func_02008530((const struct Sub0200852CObj *)func_02012944(a1));
    pid = func_020186C8(id, (u16)e->species, (u16)e->f23, e->f21, 0, 0);
    mon = func_020173F0(e->species, lvl, -1, heap);
    func_02017588(mon, e->species, lvl, id, -1, pid);
    func_02018A00(mon, e->species, e->f23);
    func_02017988(mon, (u16)e->f23);
    if (e->move != 0) {
        if (func_0201808C(mon, e->move) == 0xFFFF)
            func_020180F4(mon, (u16)e->move);
    }
    return mon;
}





void func_0217C37C(int a0, int a1, Entry_0217C2A0 *list, int a3, int kind)
{
    const u8 (*tbl)[2];
    Ctx ctx;
    void *obj;
    u16 cx;
    u16 cy;
    int i;
    int dx;
    int dy;
    int x;
    int y;

    if (func_02166618(kind))
        tbl = d_02183678;
    else if (func_02166640(kind))
        tbl = d_021835F8;
    else
        tbl = d_02183650;

    ctx.f0 = func_0202A128(func_02188C84((u8 *)a0));
    ctx.f4 = a0;
    ctx.f8 = a1;
    obj = func_021A3074(func_02188CB4((void *)a0));
    cx = func_0216D83C(obj);
    cy = func_0216D86C(obj);

    for (i = 0; i < 20; i++) {
        if (list[i].species != 0) {
            dx = func_02005728(2) - 1;
            dy = func_02005728(2) - 1;
            x = dx + tbl[i][0];
            y = dy + tbl[i][1];
            if (cx == x && cy == y) {
                if (dx != 0)
                    x -= dx;
                else if (dy != 0)
                    y -= dy;
                else
                    x++;
            }
            func_0217C1D0((const O *)&ctx, (const B *)&list[i], i, x, y, 0);
        }
    }
    func_0202A170(ctx.f0);
}





struct Desc *func_0217C458(void *a0, void *a1, u8 *a2, int a3)
{
    B52 *src;
    Obj *o;
    struct Desc *x;

    src = (B52 *)func_02175B34(a2 + 0x1AC);
    func_020120F4(a0);
    x = func_020122C0(a0, 0, func_0217C4D0, 0x88);
    o = func_020124E8((struct Obj *)x);
    func_02082BCC(o, 0, 0x88);
    o->h0 = a3;
    o->w4 = a1;
    o->b38 = *src;
    o->b84 = 1;
    func_0217F2B4((u8 *)o + 8, a0);
    func_02174E14(a2, 5);
    return x;
}




/*
 * Task callback registered by func_0217C458 (0x88-byte work, state word
 * in the second argument).
 */
int func_0217C4D0(void *task, int *state, Work_0217C2A0 *w)
{
    void *sys;
    u8 *peer;
    u16 hi;
    u8 t;

    sys = func_020124E4(task);
    peer = (u8 *)func_02158344((int)((void *)func_02012138(sys)));
    if (peer == 0 && *state == 0)
        *state = 8;

    switch (*state) {
    case 0:
        if (w->f84 == 0) {
            *state = 4;
            break;
        }
        func_0217F528(w->f08, sys, 1, 1, 0x1E, 0x10);
        func_021762D8(&w->f38, w->f38.f18, *(int *)w->f08, w->f00);
        hi = w->f38.f04.hi;
        func_0217F574((void **)w->f08, (u16)w->f38.f04.lo, 8, 0);
        func_0217F574((void **)w->f08, (u16)hi, 8, 0x10);
        (*state)++;
        break;
    case 1:
        func_02012374(task, func_02029830(sys, 0x52B));
        (*state)++;
        break;
    case 2:
        if (func_02005F38() == 0) {
            func_02012374(task, func_02029620(sys, 0, 6));
            (*state)++;
        }
        break;
    case 3:
        func_0217F58C(w->f08);
        (*state)++;
        break;
    case 4:
        t = (int)func_02012B58(func_020120F4(sys));
        func_0217C658((Rec_0217C658 *)(&w->f6C), sys, w->f04, w->f38.f0A[t], w->f38.f10[t], w->f38.f08.mask & (1 << t));
        (*state)++;
        break;
    case 5:
        if (func_0217C688((Rec_0217C688 *)(&w->f6C), peer) == 1)
            (*state)++;
        break;
    case 6:
        if (peer != 0) {
            if (func_02173FC0((int)peer, peer + 0x1AC) == 1)
                (*state)++;
        } else {
            (*state)++;
        }
        break;
    case 7:
        if (peer != 0) {
            if (func_02175A24(peer + 0x1AC) == 1)
                (*state)++;
        } else {
            (*state)++;
        }
        break;
    case 8:
        func_0217F318(w->f08);
        if (peer != 0)
            func_02174E14(peer, 0);
        return 1;
    }
    return 0;
}



/*
 * extent: two alignment bytes at 0x0217C686.
 */
void func_0217C658(Rec_0217C658 *p, void *a, int b, u16 c, u8 d, u8 e)
{
    func_02082BCC(p, 0, sizeof(Rec_0217C658));
    p->f0 = a;
    p->f4 = b;
    p->fC = c;
    p->fE = d;
    p->fF = e;
    p->fA = 15;
    p->f8 = p->fA;
}




/*
 * Per-frame step of the 0x18-byte record func_0217C758 initialises.
 */
int func_0217C688(Rec_0217C688 *r, void *a1)
{
    void *obj;
    s16_0217C2A0 v;

    switch (r->f10) {
    case 0:
        r->fA = 15;
        r->f8 = r->fA;
        func_020061E4(0x738);
        r->f10++;
        break;
    case 1:
        if (func_02188BE8(r->f4) == 1) {
            obj = func_021A3074(func_02188CB4((struct Obj00020 *)r->f4));
            if (func_0216D3CC((int)obj) == 1) {
                if (r->fA >= 15 && r->f12 != 0 && d_021836A0[r->f11] == 1) {
                    r->f10++;
                    break;
                }
                r->f11 = (r->f11 + 1) & 3;
                v = r->fA;
                r->f8 = v;
                if (r->f12 == 0) {
                    r->fA--;
                    if (r->fA <= 1) {
                        func_020120F4(r->f0);
                        func_0217BCDC(a1, r->f0, r->fC, r->fE, r->fF);
                        r->f12++;
                    }
                } else if (v < 15) {
                    r->fA++;
                }
                func_0216D410(obj, d_021836A0[r->f11]);
            }
        }
        break;
    default:
        return 1;
    }
    return 0;
}
