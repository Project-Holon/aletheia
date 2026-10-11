/*
 * file:     scrcmd_proc.c
 * unit:     yes
 * function: func_0215B488, func_0215B4AC, func_0215B4DC, func_0215B500, func_0215B558, func_0215B5A8, func_0215B5BC, func_0215B660, func_0215B6C0, func_0215B704, func_0215B74C, func_0215B7E8, func_0215B824, func_0215B848, func_0215B888, func_0215B904, func_0215B994, func_0215BA18, func_0215BAB0, func_0215BAF4, func_0215BB50, func_0215BBD0, func_0215BCA0, func_0215BCE8, func_0215BD2C, func_0215BE24, func_0215BF30, func_0215BF7C, func_0215BFD4, func_0215C01C, func_0215C064, func_0215C0D0, func_0215C138, func_0215C180, func_0215C200, func_0215C2D0, func_0215C40C, func_0215C4C8, func_0215C510, func_0215C558, func_0215C584, func_0215C5B0, func_0215C5EC, func_0215C610, func_0215C63C, func_0215C69C, func_0215C6F0, func_0215C700, func_0215C72C, func_0215C7C4, func_0215C7E0, func_0215C870, func_0215C89C, func_0215C95C, func_0215CA64, func_0215CAB4, func_0215CB08, func_0215CBF0, func_0215CC38, func_0215CC4C, func_0215CCE8, func_0215CD3C, func_0215CD80, func_0215CDB8, func_0215CDF0, func_0215CE70, func_0215CE98, func_0215CEBC, func_0215CEE8, func_0215CF00, func_0215CF54, func_0215CF84, func_0215CFB4, func_0215CFD8, func_0215CFFC, func_0215D034, func_0215D06C, func_0215D0A4, func_0215D0D4, func_0215D110, func_0215D14C, func_0215D198, func_0215D1E4, func_0215D2A4
 * address:  0x0215B488
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   d_02171170 0x02171170 data a2
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C   0x02017E1C  thumb
 *   func_0201BA34  0x0201BA34  thumb
 *   func_02011330  0x02011330  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_0201AB08  0x0201AB08  thumb
 *   func_0201AB18  0x0201AB18  thumb
 *   func_0201AA14  0x0201AA14  thumb
 *   func_0201AA1C  0x0201AA1C  thumb
 *   func_0201AA50  0x0201AA50  thumb
 *   func_0201AA88  0x0201AA88  thumb
 *   func_0201AAD4  0x0201AAD4  thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_02007984  0x02007984  thumb
 *   func_020079A0  0x020079A0  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02012944  0x02012944  thumb
 *   func_02017D30  0x02017D30  thumb
 *   func_020180F4  0x020180F4  thumb
 *   func_020181F4  0x020181F4  thumb
 *   func_02017D70  0x02017D70  thumb
 *   func_02008530  0x02008530  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02008500  0x02008500  thumb
 *   func_0204589C  0x0204589C  arm
 *   func_02045808  0x02045808  arm
 *   func_02008550  0x02008550  thumb
 *   g0209DF08      0x0209DF08  data  a1
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02017988  0x02017988  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_020185C4  0x020185C4  thumb
 *   d_02171180     0x02171180  data   ov010  a2
 *   d_0217118E     0x0217118E  data   ov010  a2
 *   d_02171190     0x02171190  data   ov010  a2
 *   func_02017A20  0x02017A20  thumb
 *   func_0216F948  0x0216F948  thumb  ov010
 *   func_0216FAA0  0x0216FAA0  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   d_02171182 0x02171182 data a1
 *   func_020173F0  0x020173F0  thumb
 *   func_02008510  0x02008510  thumb
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0202F190  0x0202F190  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   g_020A7370     0x020A7370  data
 *   func_020186C8 0x020186C8 thumb
 *   func_02017430 0x02017430 thumb
 *   func_02020FE4 0x02020FE4 thumb
 *   func_0202142C 0x0202142C thumb
 *   func_020127A4 0x020127A4 thumb
 *   func_02012AC8 0x02012AC8 thumb
 *   func_02013E4C 0x02013E4C thumb
 *   func_020185F4  0x020185F4  thumb
 *   func_020074D8  0x020074D8  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C278 0x0200C278 thumb
 *   func_0200C29C 0x0200C29C thumb
 *   func_0200C274 0x0200C274 thumb
 *   func_020145CC   0x020145CC  thumb
 *   func_0215897C   0x0215897C  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02158FB4  0x02158FB4  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_020120B4  0x020120B4  thumb
 *   func_020113D0  0x020113D0  thumb
 *   d_021728F0     0x021728F0  data  a1
 *   func_02158FB8  0x02158FB8  thumb  ov010
 *   func_020120F0  0x020120F0  thumb
 *   func_02158FBC  0x02158FBC  thumb  ov010
 *   func_0202E474  0x0202E474  thumb
 *   ov070_id       0x00000046  data
 *   d_021BB96C     0x021BB96C  data  ov070 a4
 *   func_02014840  0x02014840  thumb
 *   ov136_id       0x00000088  data
 *   d_021C78A4     0x021C78A4  data  ov136  a1
 *   func_0216F940  0x0216F940  thumb  ov010
 *   func_0216F918 0x0216F918 thumb ov010
 *   func_02014808 0x02014808 thumb
 *   ov173_id 0x000000AD data
 *   d_021B81D0 0x021B81D0 data ov173 a4
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02012B58  0x02012B58  thumb
 *   func_0215841C  0x0215841C  thumb  ov010
 *   func_02175FB4  0x02175FB4  thumb  ov011
 *   func_0215840C  0x0215840C  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_02175648  0x02175648  thumb  ov011
 *   d_021BA758     0x021BA758  data  ov099  a1
 *   ov071_id       0x00000047  data
 *   func_02158F50  0x02158F50  thumb  ov010
 *   func_02161B90  0x02161B90  thumb  ov010
 *   ov174_id       0x000000AE  data
 *   d_021B74A0     0x021B74A0  data  a1 ov174
 *   func_02165344  0x02165344  thumb  ov010
 *   ov221_id       0x000000DD  data
 *   ov222_id       0x000000DE  data
 *   ov224_id       0x000000E0  data
 *   d_021BA1A4     0x021BA1A4  data  ov221  a4
 *   d_021BA250     0x021BA250  data  ov222  a4
 *   d_021B9BF8     0x021B9BF8  data  ov224  a4
 *   ov223_id       0x000000DF  data
 *   d_021BC8C4     0x021BC8C4  data  ov223
 *   func_020124AC  0x020124AC  thumb
 *   func_02154438  0x02154438  thumb  ov002
 *   ov002_id       0x00000002  data
 *   func_021543BC  0x021543BC  thumb  ov003
 *   ov003_id       0x00000003  data
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021F36C0  0x021F36C0  thumb  ov037
 *   ov037_id       0x00000025  data
 *   func_021F36E8 0x021F36E8 thumb ov037
 *   func_021F3724 0x021F3724 thumb ov037
 *   func_021F3768  0x021F3768  thumb  ov037
 *   func_021F3800 0x021F3800 thumb ov037
 *   func_02188D50  0x02188D50  thumb
 *   func_021C3400  0x021C3400  thumb  ov021
 *   func_021C32F4 0x021C32F4 thumb ov021
 *   func_021C335C  0x021C335C  thumb
 *   func_0200BDB0  0x0200BDB0  thumb
 *   func_021C3204 0x021C3204 thumb ov021
 *   func_021C3270 0x021C3270 thumb ov021
 *   func_021C340C  0x021C340C  thumb
 *   func_021C34C4  0x021C34C4  thumb
 *   func_021C34F8 0x021C34F8 thumb ov021
 *   func_021C341C 0x021C341C thumb ov021
 *   func_021C3490 0x021C3490 thumb ov021
 *   func_021C34B4 0x021C34B4 thumb ov021
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_021BE92C  0x021BE92C  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02014910  0x02014910  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   d_02172900     0x02172900  data
 */
#include "../../matched/include/Obj04130.h"
#include "../../matched/include/Obj17690.h"
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj04131.h"
#include "../../matched/include/Obj17693.h"
#include "../../matched/include/Obj17694.h"
#include "../../matched/include/Obj17695.h"

struct BigObj;
struct Stream;
struct Sav;
struct Buf;
struct Sub0200852CObj;
struct U16Vec;
struct Blk37;
struct Ctx;
struct Party;
struct PartyMon;
struct MsgBank;
struct Personal;
struct SaveBlock;
struct Rec44;
struct Sub02007454Entry;
struct Spec;
struct Blk34;
struct IcaAnime;
struct Pair;
struct Rec;
struct Big;
struct Out;
struct Desc;
struct Evt;
struct Obj;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef short s16;

typedef struct {
    u16 h;
    void *p0;
    void *p1;
    void *p2;
    int z;
    int c0;
    int c1;
    int c2;
    int c3;
} Req;

typedef struct {
    u16 h;
    int p0;
    int p1;
    int p2;
    int z;
    int c0;
    int c1;
    int c2;
    int c3;
} Req_0215BBD0;

typedef struct Spec_0 {
    u16 f00;            /* 0x00 */
    u16 pad02;
    u32 f04;            /* 0x04 */
    u32 f08;            /* 0x08 */
    u32 f0c;            /* 0x0C */
    u32 f10;            /* 0x10 */
    u32 f14;            /* 0x14 */
    u32 f18;            /* 0x18 */
    u32 f1c;            /* 0x1C */
    u32 f20;            /* 0x20 */
} Spec_0;

typedef struct Spec_1 {
    u16 f00;            /* 0x00 */
    u16 pad02;
    int f04;            /* 0x04 */
    int f08;            /* 0x08 */
    int f0c;            /* 0x0C */
    int f10;            /* 0x10 */
    int f14;            /* 0x14 */
    int f18;            /* 0x18 */
    int f1c;            /* 0x1C */
    int f20;            /* 0x20 */
} Spec_1;

typedef unsigned long long u64;

typedef struct Spec {
    u16 f00, pad02;
    u32 f04, f08, f0c, f10, f14, f18, f1c, f20;
} Spec;

typedef struct ProcHandoff {
    void *work;         /* 0x00 */
    u32 arg1;           /* 0x04 */
    u32 arg0;           /* 0x08 */
} ProcHandoff;

typedef enum { B_FALSE, B_TRUE } Bool;

typedef struct Outputs { u16 *first; u16 *second; } Outputs;

typedef struct Context { char pad[0x34]; u32 first; u32 second; } Context;

typedef struct Pair { Context *context; Outputs *outputs; } Pair;

typedef struct Rec {
    u32 *src;
    u16 *dst;
} Rec;

typedef struct Relearn {
    void *mon;          /* 0x00 */
    void *sess;         /* 0x04 */
    u32 f08;            /* 0x08 */
    void *sys;          /* 0x0C */
    void *moves;        /* 0x10 */
    u8 pad14[5];
    u8 f19;             /* 0x19 */
} Relearn;

typedef struct Name20 {
    u16 s[20];
} Name20;

typedef struct Profile16 {
    u32 w[4];
} Profile16;

typedef struct Rec28 {
    u8 data[0x28];
} Rec28;

typedef struct LinkState {
    u8 pad00[0x86];
    u16 self : 3;       /* 0x086 */
    u16 rest : 13;
    u8 pad88[0x1AC - 0x88];
    Rec28 recs[1];      /* 0x1AC */
} LinkState;

typedef struct ProfileWork {
    void *sys;          /* 0x00 */
    Name20 name;        /* 0x04 */
    Profile16 profile;  /* 0x2C */
    u8 slot;            /* 0x3C */
    u8 remote;          /* 0x3D */
    u8 pad3E[2];
} ProfileWork;

typedef struct Box8_0215CAB4 {
    u16 v;              /* 0x00 */
    u16 pad02;
    void *sys;          /* 0x04 */
} Box8_0215CAB4;

typedef struct Box8_0215CB08 {
    void *sys;          /* 0x00 */
    u32 v;              /* 0x04 */
} Box8_0215CB08;

typedef struct Req_0215C40C {
    void *sys;          /* 0x00 */
    u32 one;            /* 0x04 */
    u32 flag;           /* 0x08 */
    u32 kind;           /* 0x0C */
} Req_0215C40C;

typedef signed int     s32;

typedef struct { u32 a; u32 b; } Arg;

typedef struct { u32 pad[15]; u32 f3c; } O8;

typedef struct { u8 pad[15]; u8 fF; } OC;

typedef struct {
    void *f0;
    void *f4;
    O8 *f8;
    OC *fC;
    u16 *f10;
} Ctx_0215D1E4;

typedef struct {
    void *f00;
    u32 pad04[2];
    u32 f0c;
    u32 pad10[9];
    u32 f34;
    u32 f38;
    u32 f3c;
} A;

typedef struct {
    void *f00;
    u32 f04;
    u32 f08;
    u8 f0c;
    u8 f0d;
    u8 f0e;
    u8 f0f;
    u8 f10;
    u8 pad11[7];
    u32 f18;
} B;

typedef struct {
    void *f0;
    u32 f4;
    A *f8;
    B *fC;
    u32 f10;
} Ctx_0215D2A4;

extern u16 func_02159B10(void *,void *);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_0201BA34(void *a0);
extern u16 func_02011330(struct Stream *s);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_0201AB08(void *p);
extern u32 func_0201AB18(void *p);
extern u32 func_0201AA14(void *p);
extern u32 func_0201AA1C(void *p);
extern u32 func_0201AA50(void *p);
extern u32 func_0201AA88(void *p);
extern u32 func_0201AAD4(void *p);
extern u32 func_0201293C(const struct BigObj *p);
extern int func_02007984(void *);
extern int func_020079A0(void *);
extern void *func_0215A5DC(void *a0);
extern u16 func_0215A5CC(void *);
extern u8 *func_02012944(void *p);
extern u32 func_02017D30(struct Sav *p);
extern void func_020180F4(void *p, int move);
extern void func_020181F4(void *p, u16 move, u32 slot);
extern u32 func_02017D70(struct Sav *p, u32 f);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02008500(void *player, void *str);
extern int func_0204589C(struct Buf *a, struct Buf *b);
extern void func_02045808(struct U16Vec *vec);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_0215A5F4(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02017988(void *p, u32 a);
extern void *func_0200CA1C(void *);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern u32 func_02017A20(void *p, u32 idx, u32 val);
extern u16 *func_0216F948(void *mon, u32 heap);
extern int func_0216FAA0(u16 *p);
extern u32 func_020307B0(void *p);
extern void func_020185C4(void *);
extern void *func_020173F0(u32 species, u32 level, u64 id, u32 heap);
extern void *func_02008510(void *a, int tag);
extern void *func_0201ADE4(unsigned int species, int form, unsigned int heap);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0202F190(void *mon, u32 a1, void *a2, u32 a3, u32 heap);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern void *func_02017430(u16, u16, u64, u32, u64, u16);
extern int func_02020FE4(u16, u32, u16);
extern unsigned short func_0202142C(int a0);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern u32 func_02013E4C(u32 id);
extern void *func_020185F4(void *p);
extern int func_020074D8(void **save, const struct Sub02007454Entry *src);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern void *func_02012F08(int *p);
extern u32 func_0200C278(struct Blk34 *p, u32 v);
extern u32 func_0200C29C(struct Blk34 *p, u32 v);
extern u32 func_0200C274(struct Blk34 *p);
extern void *func_020145CC(void *);
extern void func_0215897C(void *, void *);
extern void *func_0201210C(const struct Ctx *p);
extern int func_020144DC(int a0, int a1);
extern void *func_02158FB4(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern void func_020113D0(char *p, int val);
extern u32 func_02158FB8(void *p);
extern u32 func_020120F0(const struct Ctx *p);
extern int func_02158FBC();
extern void *func_0202E474(const struct BigObj *a0, int a1, int a2, int a3);
extern void *func_02014840(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern int func_0216F940();
extern void *func_0216F918(u32 heap);
extern void *func_02014808(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158344(int a0);
extern u8 func_02012B58(const struct BigObj *p);
extern u8 func_0215841C(void *p);
extern int func_02175FB4(u8 *p);
extern Name20 *func_0215840C(LinkState *s, int idx);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern void func_02175648(void *sv, struct Out *o);
extern void *func_02158F50(void *p);
extern void *func_02161B90(void *p, void *a1, int kind, int sub, int flag);
extern void func_02165344(void);
extern struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern void func_02154438(s32 a, s32 *b);
extern void func_021543BC(void);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern void func_021F36C0(unsigned int a0, int a1, int a2);
extern void func_021F36E8(void *, int);
extern void func_021F3724(unsigned int a0, int a1);
extern void func_021F3768(unsigned int a0, unsigned short **a1);
extern void func_021F3800(unsigned int a0);
extern void *func_02188D50(void *a0);
extern int func_021C3400(void *a);
extern void func_021C32F4(unsigned int *, unsigned int);
extern void func_021C335C(void **p);
extern void *func_0200BDB0(void *);
extern void func_021C3204(unsigned int *, unsigned int, unsigned int);
extern void func_021C3270(unsigned int *, unsigned int, unsigned int);
extern int func_021C340C();
extern u8 func_021C34C4(void **p);
extern void *func_021C34F8(void *, unsigned int);
extern int func_021C341C(unsigned int *, unsigned int);
extern int func_021C3490(void **,int);
extern int func_021C34B4(void **,int);
extern void *func_021BE8D4(void *, void *, int, int);
extern void *func_021BE92C(void *, void *, int, int, int, int, int);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_02014910(char *a0, int a1, int a2, int a3);
extern u32 func_0200CA38(struct Blk37 *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
int func_0215B488(int a,int b);
int func_0215B4AC(void *a0, u32 a1, void **a2);
int func_0215B4DC(void *a0, void *a1, void *a2);
int func_0215B500(int a0, int a1);
int func_0215B558(int a0, int a1);
int func_0215B5A8(int a0, int a1);
int func_0215B5BC(void *a0, void *a1);
int func_0215B660(int a0, int a1, int a2);
int func_0215B6C0(int a0, int a1, int a2);
int func_0215B704(int a0, int a1, int a2);
int func_0215B74C(int a0, int a1);
int func_0215B7E8(int a,int b);
int func_0215B824(int a0, int a1, int a2);
int func_0215B848(int a0, int a1);
int func_0215B888(void *a0, void *a1);
int func_0215B904(void *a0, void *a1);
int func_0215B994(void *a0, void *a1);
int func_0215BA18(void *a0, void *a1);
int func_0215BAB0(int a0, int a1, int a2);
int func_0215BAF4(void *a0, void *a1);
int func_0215BB50(void *a0, void *a1);
int func_0215BBD0(void *a0, void *a1);
int func_0215BCA0(int a0, int a1, int a2);
int func_0215BCE8(void *a0, void *a1);
int func_0215BD2C(void *c, void *vm);
int func_0215BE24(void *c, void *vm);
int func_0215BF30(void *a0, void *a1);
int func_0215BF7C(void *a0, void *a1);
int func_0215BFD4(int a0, int a1, int a2);
int func_0215C01C(void *a0, void *a1);
int func_0215C064(void *a0, void *a1);
int func_0215C0D0(void *a0, void *a1);
int func_0215C138(void *c, void *vm);
int func_0215C180(void *c, void *vm);
int func_0215C200(void *c, void *vm);
int func_0215C2D0(void *c, void *vm);
void *func_0215C40C(void *a, Spec *s);
int func_0215C4C8(void *a, void *b);
int func_0215C510(void *a, void *b);
int func_0215C558(int a,int b);
int func_0215C584(int a,int b);
int func_0215C5B0(void *a, void *b);
int func_0215C5EC(void *a0, void *a1);
int func_0215C610(int a0, int a1);
void func_0215C63C(void *c, void *vm, u32 ovId, const void *proc, void *work, u32 arg0, u32 arg1);
int func_0215C69C(int a0, int a1);
int func_0215C6F0(int a0, int a1);
void func_0215C700(Pair *p);
int func_0215C72C(void *c, void *vm);
void func_0215C7C4(Rec *r);
int func_0215C7E0(void *c, void *vm);
int func_0215C870(int a0, int a1);
int func_0215C89C(void *c, void *vm);
int func_0215C95C(void *c, void *vm);
int func_0215CA64(void *c, void *vm);
int func_0215CAB4(void *c, void *vm);
int func_0215CB08(void *c, void *vm);
int func_0215CBF0(void *c, void *vm);
int func_0215CC38(int a0, int a1);
int func_0215CC4C(void *c, void *vm);
int func_0215CCE8(void *a, void *b);
int func_0215CD3C(void *a, void *b);
int func_0215CD80(void *a, void *b);
int func_0215CDB8(void *a, void *b);
int func_0215CDF0(void *a, void *b);
int func_0215CE70(void *a, void *b);
int func_0215CE98(int a0, int a1);
int func_0215CEBC(void *a, void *b);
int func_0215CEE8(int a0, int a1);
int func_0215CF00(void *a, void *b);
int func_0215CF54(void *a, void *b);
int func_0215CF84(void *a, void *b);
int func_0215CFB4(int a0, int a1);
int func_0215CFD8(int a0, int a1);
int func_0215CFFC(void *a, void *b);
int func_0215D034(void *a, void *b);
int func_0215D06C(void *a, void *b);
int func_0215D0A4(void *a, void *b);
int func_0215D0D4(void *a,void *b);
int func_0215D110(void *a,void *b);
int func_0215D14C(void *a, void *b);
int func_0215D198(void *x);
int func_0215D1E4(void *a, u32 *st, Ctx_0215D1E4 *c);
void *func_0215D2A4(void *a, u32 b, u32 c);
extern const u16 d_02171170[];
extern u8 g0209DF08;
extern u16 d_02171180[];
extern struct { u16 a; u16 b; } d_0217118E[6];
extern const u8 d_02171182[];
extern void *g_020A7370;
extern const char d_021728F0[];
extern const u8 d_021BB96C[];
extern u8 ov070_id[];
extern const u8 d_021C78A4[];
extern u8 ov136_id[];
extern const u8 d_021B81D0[];
extern u8 ov173_id[];
extern const u8 d_021BA758[];
extern u8 ov071_id[];
extern const u8 d_021B74A0[];
extern u8 ov174_id[];
extern const u8 d_021BA1A4[];
extern const u8 d_021BA250[];
extern const u8 d_021B9BF8[];
extern u8 ov221_id[];
extern u8 ov222_id[];
extern u8 ov224_id[];
extern const u8 d_021BC8C4[];
extern u8 ov223_id[];
extern u8 ov002_id[];
extern char ov003_id[];
extern char ov037_id[];
extern const char d_02172900[];


/*
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 */
int func_0215B488(int a,int b)
{
    int k = func_02159B10((void *)a,(void *)b);
    u16 *out = func_02159AE8((void *)a,(void *)b);
    *out = d_02171170[k];
    return 0;
}



int func_0215B4AC(void *a0, u32 a1, void **a2)
{
    int t4;
    u32 t5;
    void **t6;
    int n;
    void *p;
    void *v0;
    void *v1;

t5 = a1 + 0;
t6 = a2;
    v0 = func_0215A5E4(a0);
loc_0215B4B6:
    v1 = func_02012934(v0);
loc_0215B4BA:
    n = func_0201AA18(v1);
loc_0215B4C0:
    if (t5 >= (unsigned)n) goto loc_0215B4C8;
loc_0215B4C4:
t4 = 1;
    goto loc_0215B4CC;
loc_0215B4C8:
t4 = 0;
t5 = 0;
loc_0215B4CC:
    p = func_0201AB28(v1, t5);
loc_0215B4D4:
*t6 = p;
    return t4;}



/*
 * Unpacks a record into a local and, when the overlay call says it took,
 * forwards the record and the third argument to the arm9 side.
 */
int func_0215B4DC(void *a0, void *a1, void *a2)
{
    int v;

    if (func_0215B4AC(a0, (u32)a1, (void **)(&v)) == 1)
        return func_02017E1C((void *)v, (u32)a2, 0);

    return 0;
}



int func_0215B500(int a0, int a1)
{
    int a2;
    int t4;
    int t5;
    int t6;

t4 = a1 + 0;
a1 = 0x4c;
a2 = 0;
t5 = a0 + 0;
t6 = 0;
    a0 = func_02017E1C((void *)a0, a1, a2);
loc_0215B510:
    if (a0 == 0) goto loc_0215B518;
loc_0215B514:
a0 = t6 + 0;
    return a0;
loc_0215B518:
a0 = t5 + 0;
a1 = 0x36;
a2 = t6 + 0;
    a0 = func_02017E1C((void *)a0, a1, a2);
loc_0215B522:
    if (t4 == a0) goto loc_0215B550;
loc_0215B526:
a0 = t5 + 0;
a1 = 0x37;
a2 = t6 + 0;
    a0 = func_02017E1C((void *)a0, a1, a2);
loc_0215B530:
    if (t4 == a0) goto loc_0215B550;
loc_0215B534:
a0 = t5 + 0;
a1 = 0x38;
a2 = t6 + 0;
    a0 = func_02017E1C((void *)a0, a1, a2);
loc_0215B53E:
    if (t4 == a0) goto loc_0215B550;
loc_0215B542:
a0 = t5 + 0;
a1 = 0x39;
a2 = t6 + 0;
    a0 = func_02017E1C((void *)a0, a1, a2);
loc_0215B54C:
    if (t4 != a0) goto loc_0215B554;
loc_0215B550:
a0 = 1;
    return a0;
loc_0215B554:
a0 = t6 + 0;
    return a0;}


int func_0215B558(int a0, int a1)
{
    u16 *p = func_02159AE8((void *)a0, (void *)a1);
    u16 *q = func_02159AE8((void *)a0, (void *)a1);
    int obj;
    if (func_0215B4AC((void *)a1, func_02159B10((void *)a0, (void *)a1), (void **)(&obj)) == 1) {
        *p = func_02017E1C((void *)obj, 0xAE, 0);
        *q = func_02017E1C((void *)obj, 0xAF, 0);
    } else {
        *p = 0;
        *q = 0;
    }
    return 0;
}



int func_0215B5A8(int a0, int a1)
{
    void *v0;
    void *v1;

a0 = a1 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215B5B0:
    v1 = func_02012934(v0);
loc_0215B5B4:
    func_0201BA34(v1);
loc_0215B5B8:
a0 = 0;
    return a0;}


#pragma opt_lifetimes off


#pragma opt_propagation off


/*
 * 2026-10-05 (wave P14 C6): closed with per-function opt_lifetimes off plus
 * opt_propagation off. Without them the two zeros (the named argument zero z
 * and the initial sum) merge into one register and the first add folds to
 * adds r0,r0,#0 (35 B off, 166 B). opt_lifetimes off alone: 2 B off.
 */
int func_0215B5BC(void *a0, void *a1)
{
    u16 *out = (u16 *)func_02159AE8(a0, a1);
    int idx = func_02159B10(a0, a1);
    int z = 0;
    u16 sum = 0;
    void *obj;
    if (func_0215B4AC(a1, idx, &obj) == 1) {
        sum = z + (u16)func_02017E1C(obj, 0xD, z);
        sum = sum + (u16)func_02017E1C(obj, 0xE, z);
        sum = sum + (u16)func_02017E1C(obj, 0xF, z);
        sum = sum + (u16)func_02017E1C(obj, 0x10, z);
        sum = sum + (u16)func_02017E1C(obj, 0x11, z);
        sum = sum + (u16)func_02017E1C(obj, 0x12, z);
    }
    *out = sum;
    return 0;
}


#pragma opt_lifetimes reset


#pragma opt_propagation reset



int func_0215B660(int a0, int a1, int a2)
{
    unsigned char fr[4];
    int t5;
    int t6;
    u16 *q;
t6 = a0 + 0;
t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215B66C:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0215B676:
a1 = a0 + 0;
t6 = 0;
a0 = t5 + 0;
a2 = (int)(fr + 0);
*q = t6;
    a0 = func_0215B4AC((void *)a0, a1, (void **)a2);
loc_0215B684:
    if (a0 != 1) goto loc_0215B6BA;
loc_0215B688:
    a0 = *(int *)&((struct Obj04130 *)fr)->f0;
a1 = 0xa0;
a2 = t6 + 0;
    a0 = (int)func_02017E1C((void *)a0, a1, a2);
loc_0215B692:
a0 = a0 << 0x10;
t5 = (unsigned)a0 >> 0x10;
    a0 = *(int *)&((struct Obj04130 *)fr)->f0;
a1 = 0xa1;
a2 = t6 + 0;
    a0 = (int)func_02017E1C((void *)a0, a1, a2);
loc_0215B6A0:
a0 = a0 << 0x10;
a0 = (unsigned)a0 >> 0x10;
    if (t5 == a0) goto loc_0215B6B6;
loc_0215B6A8:
    a0 = *(int *)&((struct Obj04130 *)fr)->f0;
a1 = 0x4c;
a2 = t6 + 0;
    a0 = (int)func_02017E1C((void *)a0, a1, a2);
loc_0215B6B2:
    if (a0 != 1) goto loc_0215B6BA;
loc_0215B6B6:
a0 = 1;
*q = a0;
loc_0215B6BA:
a0 = 0;
    return a0;
}



int func_0215B6C0(int a0, int a1, int a2)
{
    unsigned char fr[4];
    int t5;
    int t6;
    u16 *q;
t6 = a0 + 0;
t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215B6CC:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0215B6D6:
a1 = a0 + 0;
t6 = 0;
a0 = t5 + 0;
a2 = (int)(fr + 0);
*q = t6;
    a0 = func_0215B4AC((void *)a0, a1, (void **)a2);
loc_0215B6E4:
    if (a0 != 1) goto loc_0215B6FE;
loc_0215B6E8:
    a0 = *(int *)&((struct Obj04130 *)fr)->f0;
a1 = 0x4c;
a2 = t6 + 0;
    a0 = func_02017E1C((void *)a0, a1, a2);
loc_0215B6F2:
    if (a0 != 0) goto loc_0215B6FA;
loc_0215B6F6:
*q = t6;
    goto loc_0215B6FE;
loc_0215B6FA:
a0 = 1;
*q = a0;
loc_0215B6FE:
a0 = 0;
    return a0;
}



int func_0215B704(int a0, int a1, int a2)
{
    unsigned char fr[4];
    int t5;
    int t6;
    u16 *q;
t6 = a0 + 0;
t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215B710:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0215B71A:
a1 = a0 + 0;
t6 = 0;
a0 = t5 + 0;
a2 = (int)(fr + 0);
*q = t6;
    a0 = func_0215B4AC((void *)a0, a1, (void **)a2);
loc_0215B728:
    if (a0 != 1) goto loc_0215B746;
loc_0215B72C:
    a0 = *(int *)&((struct Obj04130 *)fr)->f0;
a1 = 0x4c;
a2 = t6 + 0;
    a0 = (int)func_02017E1C((void *)a0, (u32)a1, (u32)a2);
loc_0215B736:
    if (a0 != 0) goto loc_0215B746;
loc_0215B73A:
    a0 = *(int *)&((struct Obj04130 *)fr)->f0;
a1 = 9;
a2 = t6 + 0;
    a0 = (int)func_02017E1C((void *)a0, (u32)a1, (u32)a2);
loc_0215B744:
*q = a0;
loc_0215B746:
a0 = 0;
    return a0;
}


int func_0215B74C(int a0, int a1)
{
    int a = func_02159B10((void *)a0, (void *)a1);
    int b = func_02159B10((void *)a0, (void *)a1);
    int mode = func_02011330((struct Stream *)a0);
    int obj = 0;
    u8 v;
    if (func_0215B4AC((void *)a1, a, (void **)(&obj)) == 0) {
        return 0;
    }
    if (func_02017E1C((void *)obj, 0x4C, 0) == 1) {
        return 0;
    }
    v = func_02017E1C((void *)obj, 9, 0);
    switch (mode) {
    case 0:
        if ((u32)b > 0xFF) {
            v = 0xFF;
        } else {
            v = b;
        }
        break;
    case 1:
        if (v + b > 0xFF) {
            v = 0xFF;
        } else {
            v = v + (u8)b;
        }
        break;
    case 2:
        if (v < b) {
            v = 0;
        } else {
            v = v - (u8)b;
        }
        break;
    }
    func_02017E40((void *)obj, 9, v);
    return 0;
}


int func_0215B7E8(int a,int b)
{
    u16 *out = func_02159AE8((void *)a,(void *)b);
    int k = func_02159B10((void *)a,(void *)b);
    if (func_0215B4DC((void *)b,(void *)k,(void *)0x4C) != 0) *out = 0x28A; else *out = func_0215B4DC((void *)b,(void *)k,(void *)5);
    return 0;
}



int func_0215B824(int a0, int a1, int a2)
{
    int t5;
    int t6;
    u16 *q;

t6 = a0 + 0;
t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215B82E:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0215B838:
a1 = a0 + 0;
a0 = t5 + 0;
a2 = 0x6f;
    a0 = func_0215B4DC((void *)a0, (void *)a1, (void *)a2);
loc_0215B842:
*q = a0;
a0 = 0;
    return a0;}



int func_0215B848(int a0, int a1)
{
    int t4;
    int t5;
    unsigned short *v0;
    void *p;

t4 = a0 + 0;
t5 = a1 + 0;
    v0 = func_02159AE8((void *)a0, (void *)a1);
loc_0215B852:
a0 = t4 + 0;
a1 = t5 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0215B85C:
t4 = a0 + 0;
a0 = t5 + 0;
    p = func_0215A5E4((void *)a0);
loc_0215B864:
    p = func_02012934(p);
loc_0215B868:
    if (t4 == 1) goto loc_0215B87A;
loc_0215B86C:
    if (t4 != 2) goto loc_0215B880;
loc_0215B870:
    a0 = func_0201AB08(p);
loc_0215B874:
a0 = a0 << 0x10;
a0 = (unsigned)a0 >> 0x10;
    goto loc_0215B882;
loc_0215B87A:
    a0 = func_0201AB18(p);
loc_0215B87E:
    goto loc_0215B874;
loc_0215B880:
a0 = 0;
loc_0215B882:
((struct Obj17690 *)((char *)v0))->f0 = a0;
a0 = 0;
    return a0;}



int func_0215B888(void *a0, void *a1)
{
    u16 *out = func_02159AE8(a0, a1);
    int sel = func_02159B10(a0, a1);
    void *h = func_02012934(func_0215A5E4(a1));
    int r;

    switch (sel) {
    case 0:
        r = func_0201AA18(h);
        break;
    case 1:
        r = func_0201AA1C(h);
        break;
    case 2:
        r = func_0201AA50(h);
        break;
    case 3:
        r = func_0201AA88(h);
        break;
    case 4:
        r = func_0201AAD4(h);
        break;
    case 5: {
        int a = func_0201AA14(h);
        int b = func_0201AA18(h);
        if (a < b) {
            r = 0;
        } else {
            r = a - b;
        }
        break;
    }
    default:
        r = 0;
        break;
    }
    *out = r;
    return 0;
}



int func_0215B904(void *a0, void *a1)
{
    u32 key = func_02159B10(a0, a1);
    u16 *out = func_02159AE8(a0, a1);
    void *list = func_02012934(func_0215A5E4(a1));
    u16 n = func_0201AA18(list);
    u16 cnt = 0;
    int i;

    if (key != 0 && key <= 0x289) {
        for (i = 0; i < n; i++) {
            void *e = func_0201AB28(list, i);
            u16 t;

            if (e != 0 && func_02017E1C(e, 0x4C, 0) == 0) {
                t = func_02017E1C(e, 5, 0);
                if (t == key) {
                    cnt++;
                }
            }
        }
        *out = cnt;
    } else {
        *out = 0;
    }
    return 0;
}



int func_0215B994(void *a0, void *a1)
{
    u16 *out = func_02159AE8(a0, a1);
    int sel = func_02159B10(a0, a1);
    void *h = func_0215A5E4(a1);
    void *d = (void *)func_0201293C(h);
    int r;

    func_02012934(h);
    switch (sel) {
    case 0:
        r = func_02007984(d);
        break;
    case 1:
    case 2:
        r = func_020079A0(d);
        break;
    case 3:
        r = func_02007984(d) - func_020079A0(d);
        break;
    case 5: {
        int v = func_02007984(d);
        if (v > 720) {
            r = 0;
        } else {
            r = 720 - v;
        }
        break;
    }
    default:
        r = 0;
        break;
    }
    *out = r;
    return 0;
}



int func_0215BA18(void *a0, void *a1)
{
    u32 key = func_02159B10(a0, a1);
    u16 *out = func_02159AE8(a0, a1);
    u16 *idx = func_02159AE8(a0, a1);
    void *list = func_02012934(func_0215A5E4(a1));
    u16 n = func_0201AA18(list);
    int i;

    if (key != 0 && key <= 0x289) {
        for (i = 0; i < n; i++) {
            void *e = func_0201AB28(list, i);
            u16 t;

            if (e != 0 && func_02017E1C(e, 0x4C, 0) == 0) {
                t = func_02017E1C(e, 5, 0);
                if (t == key) {
                    break;
                }
            }
        }
        if (i < n) {
            *out = 1;
            *idx = i;
        } else {
            *out = 0;
        }
    } else {
        *out = 0;
    }
    return 0;
}



int func_0215BAB0(int a0, int a1, int a2)
{
    int v0;
    int t5;
    int t6;
    int t7;
    u16 *q;
t6 = a0 + 0;
t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215BABA:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0215BAC4:
t7 = a0 + 0;
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0215BACE:
a1 = a0 + 0;
a0 = 0;
*q = a0;
a0 = t5 + 0;
a2 = (int)&v0;
    a0 = func_0215B4AC((void *)a0, a1, (void **)a2);
loc_0215BADC:
    if (a0 != 1) goto loc_0215BAF0;
loc_0215BAE0:
    a0 = v0;
a1 = t7 + 0;
    a0 = func_0215B500(a0, a1);
loc_0215BAE8:
    if (a0 != 1) goto loc_0215BAF0;
loc_0215BAEC:
a0 = 1;
*q = a0;
loc_0215BAF0:
a0 = 0;
    return a0;
}



int func_0215BAF4(void *a0, void *a1)
{
    void *list = func_02012934(func_0215A5E4(a1));
    u16 *out = func_02159AE8(a0, a1);
    void *key = (void *)func_02159B10(a0, a1);
    int i;
    int n = func_0201AA18(list);

    *out = 6;
    for (i = 0; i < n; i++) {
        if (func_0215B500((int)func_0201AB28(list, i), (int)key) == 1) {
            *out = i;
            break;
        }
    }
    return 0;
}



int func_0215BB50(void *a0, void *a1)
{
    void *h;
    u16 n;
    u16 *out;
    void *t1;
    void *t2;
    void *t3;
    Req r;

    func_0215A5DC(a1);
    h = func_0215A5E4(a1);
    n = func_0215A5CC(a1);
    func_02012934(h);
    func_02012944(h);
    out = func_02159AE8(a0, a1);
    t1 = (void *)func_02159B10(a0, a1);
    t2 = (void *)func_02159B10(a0, a1);
    t3 = (void *)func_02159B10(a0, a1);
    r.h = n;
    r.p0 = t1;
    r.p1 = t2;
    r.p2 = t3;
    r.z = 0;
    r.c0 = 2;
    r.c1 = 2;
    r.c2 = 2;
    r.c3 = 4;
    *out = func_0215C510(h, &r);
    return 0;
}







/*
 * Sibling of func_0215BB50 (same request record, eight reads instead of
 * three, three of them clamped to 2), and of func_0215C200: the u16 locals
 * are what make the second clamp reload its value from the spill slot.
 */
int func_0215BBD0(void *a0, void *a1)
{
    void *h;
    u16 n;
    u16 *out;
    u16 t1;
    u16 t2;
    u16 t3;
    u16 t4;
    u16 t5;
    u16 t6;
    u16 t7;
    u16 t8;
    Req_0215BBD0 r;

    func_0215A5DC(a1);
    h = func_0215A5E4(a1);
    n = func_0215A5CC(a1);
    func_02012934(h);
    func_02012944(h);
    out = func_02159AE8(a0, a1);
    t1 = func_02159B10(a0, a1);
    t2 = func_02159B10(a0, a1);
    t3 = func_02159B10(a0, a1);
    t4 = func_02159B10(a0, a1);
    t5 = func_02159B10(a0, a1);
    t6 = func_02159B10(a0, a1);
    t7 = func_02159B10(a0, a1);
    t8 = func_02159B10(a0, a1);
    r.h = n;
    r.p0 = t1;
    r.p1 = t2;
    r.p2 = t3;
    r.z = t7;
    r.c0 = t4;
    if (r.c0 >= 3)
        r.c0 = 2;
    r.c1 = t5;
    if (r.c1 >= 3)
        r.c1 = 2;
    r.c2 = t6;
    if (r.c2 >= 3)
        r.c2 = 2;
    r.c3 = t8;
    *out = func_0215C510(h, &r);
    return 0;
}







int func_0215BCA0(int a0, int a1, int a2)
{
    int v0;
    int t4;
    int t5;
    int t6;
    u16 *q;
t5 = a0 + 0;
t4 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215BCAA:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0215BCB4:
a1 = a0 + 0;
a0 = t4 + 0;
a2 = (int)&v0;
t5 = 0;
    a0 = func_0215B4AC((void *)a0, a1, (void **)a2);
loc_0215BCC0:
    if (a0 != 1) goto loc_0215BCE0;
loc_0215BCC4:
t4 = t5 + 0;
t6 = t5 + 0;
loc_0215BCC8:
a1 = t4 + 0;
    a0 = v0;
a1 = a1 + 0x36;
a2 = t6 + 0;
    a0 = func_02017E1C((void *)a0, a1, a2);
loc_0215BCD4:
    if (a0 == 0) goto loc_0215BCDA;
loc_0215BCD8:
t5 = t5 + 1;
loc_0215BCDA:
t4 = t4 + 1;
    if (t4 < 4) goto loc_0215BCC8;
loc_0215BCE0:
*q = t5;
a0 = 0;
    return a0;
}







int func_0215BCE8(void *a0, void *a1)
{
    u16 *out;
    void *k;
    char *p;
    void *v;

    out = func_02159AE8(a0, a1);
    k = (char *)func_02159B10(a0, a1);
    p = (char *)func_02159B10(a0, a1);
    if (func_0215B4AC(a1, (u32)k, &v) == 1) {
        *out = func_02017E1C(v, (u32)(p + 0x36), 0);
    } else {
        *out = 0;
    }
    return 0;
}







/*
 * Script command: reads a party slot, a move slot and a move. A move slot
 * past 4 goes to func_020180F4 (teach into a free slot); a zero move deletes
 * the slot, shifting the later moves (ids 0x36 move, 0x3A pp, 0x3E pp-ups)
 * down one; otherwise func_020181F4 sets the move into the slot.
 */
int func_0215BD2C(void *c, void *vm)
{
    u16 slot;
    u16 moveSlot;
    u16 move;
    void *mon;
    u32 saved;
    u8 i;
    u32 m;
    u32 ppUp;
    u32 pp;

    slot = func_02159B10(c, vm);
    moveSlot = func_02159B10(c, vm);
    move = func_02159B10(c, vm);
    if (func_0215B4AC(vm, slot, &mon) == 0) {
        return 0;
    }
    saved = func_02017D30(mon);
    if (moveSlot > 4) {
        func_020180F4(mon, move);
    } else if (move == 0) {
        i = moveSlot;
        if (moveSlot < 3) {
            for (; i < 3; i++) {
                m = func_02017E1C(mon, i + 0x37, 0);
                if (m == 0) {
                    break;
                }
                ppUp = func_02017E1C(mon, i + 0x3F, 0);
                pp = func_02017E1C(mon, i + 0x3B, 0);
                func_02017E40(mon, i + 0x36, m);
                func_02017E40(mon, i + 0x3E, ppUp);
                func_02017E40(mon, i + 0x3A, pp);
            }
        }
        func_02017E40(mon, i + 0x36, 0);
        func_02017E40(mon, i + 0x3E, 0);
        func_02017E40(mon, i + 0x3A, 0);
    } else {
        func_020181F4(mon, move, (u8)moveSlot);
    }
    func_02017D70(mon, saved);
    return 0;
}







/*
 * Script command: is the party member in the given slot the player's own
 * catch (trainer id, OT name, OT gender and game version all match)?
 * Writes the answer to a script variable.
 *
 * Levers (2026-09-28 tree_ov010_4): the allocation check as
 * `if (a && b) {...} else fail` (moves the failure block after the name
 * test), the name test as `== 0` (func_0204589C answers "equal"), and the
 * version read into a local before the compare (`cmp r0, r1`).
 */
int func_0215BE24(void *c, void *vm)
{
    void *player;
    void *mon;
    u16 *res;
    u32 slot;
    u32 heap;
    void *a;
    void *b;
    u32 ver;

    res = func_02159AE8(c, vm);
    slot = func_02159B10(c, vm);
    player = func_02012944(func_0215A5E4(vm));
    mon = 0;
    if (!func_0215B4AC(vm, slot, &mon)) {
        *res = 0;
        return 0;
    }
    if (func_02017E1C(mon, 7, 0) != func_02008530(player)) {
        *res = 0;
        return 0;
    }
    heap = func_0215A5CC(vm);
    a = func_020457B0(16, heap);
    b = func_020457B0(16, heap);
    if (a != 0 && b != 0) {
        func_02017E1C(mon, 0x8D, (u32)a);
        func_02008500(player, b);
        if (func_0204589C(a, b) == 0) {
            func_02045808(a);
            func_02045808(b);
            *res = 0;
            return 0;
        }
    } else {
        *res = 0;
        return 0;
    }
    func_02045808(a);
    func_02045808(b);
    if (func_02017E1C(mon, 0x9A, 0) != func_02008550(player)) {
        *res = 0;
        return 0;
    }
    ver = func_02017E1C(mon, 0x77, 0);
    if (ver != g0209DF08) {
        *res = 0;
        return 0;
    }
    *res = 1;
    return 0;
}







int func_0215BF30(void *a0, void *a1)
{
    void *k = (void *)func_02159B10(a0, a1);
    void *v = (void *)func_02159B10(a0, a1);
    void *h;
    void *e;

    func_0215A5F4(a1);
    h = func_020120F4(func_0215A5DC(a1));
    e = func_0201AB28(func_02012934(h), (u32)k);
    func_02017988(e, (u32)v);
    func_0200CFA0(func_0200CA1C(h), e);
    return 0;
}







int func_0215BF7C(void *a0, void *a1)
{
    void *k = (void *)func_02159B10(a0, a1);
    void *v = (void *)func_02159B10(a0, a1);
    void *w = (void *)func_02159B10(a0, a1);
    void *h;
    void *e;

    func_0215A5F4(a1);
    h = func_020120F4(func_0215A5DC(a1));
    e = func_0201AB28(func_02012934(h), (u32)k);
    func_02017A20(e, (u32)w, (u32)v);
    func_0200CFA0(func_0200CA1C(h), e);
    return 0;
}







int func_0215BFD4(int a0, int a1, int a2)
{
    int v0;
    int t5;
    int t6;
    int t7;
    void *buf;
    u16 *q;
t6 = a0 + 0;
t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215BFDE:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0215BFE8:
t6 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0215A5CC((void *)a0);
loc_0215BFF0:
t7 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
a2 = (int)&v0;
    a0 = func_0215B4AC((void *)a0, a1, (void **)a2);
loc_0215BFFC:
    if (a0 != 1) goto loc_0215C016;
loc_0215C000:
    a0 = v0;
a1 = t7 + 0;
    buf = func_0216F948((void *)a0, a1);
loc_0215C008:
    a0 = func_0216FAA0(buf);
loc_0215C00E:
*q = a0;
    a0 = func_020307B0(buf);
loc_0215C016:
a0 = 0;
    return a0;
}







int func_0215C01C(void *a0, void *a1)
{
    u16 *out = func_02159AE8(a0, a1);
    int k = func_02159B10(a0, a1);
    int j = func_02159B10(a0, a1);
    u16 t = func_0215B4DC(a1, (void *)k, (void *)0x95);

    if (t == d_02171180[j]) {
        *out = 1;
    } else {
        *out = 0;
    }
    return 0;
}







int func_0215C064(void *a0, void *a1)
{
    u16 *o0 = func_02159AE8(a0, a1);
    u16 *o1 = func_02159AE8(a0, a1);
    u16 *o2 = func_02159AE8(a0, a1);
    void *v;

    if (func_0215B4AC(a1, func_02159B10(a0, a1), &v) == 1) {
        *o0 = func_02017E1C(v, 0x92, 0);
        *o1 = func_02017E1C(v, 0x93, 0);
        *o2 = func_02017E1C(v, 0x94, 0);
    } else {
        *o0 = 0;
        *o1 = 0;
        *o2 = 0;
    }
    return 0;
}







int func_0215C0D0(void *a0, void *a1)
{
    int k = func_02159B10(a0, a1);
    u32 x = func_02159B10(a0, a1);
    u32 y = func_02159B10(a0, a1);
    void *v;
    u32 i;

    for (i = 0; i < 6; i++) {
        if (x == d_0217118E[i].a) {
            if (y <= d_0217118E[i].b && func_0215B4AC(a1, k, &v) == 1) {
                func_02017E40(v, x, y);
                func_020185C4(v);
            }
            return 0;
        }
    }
    return 0;
}






/*
 * lever: selector remains live in r2 and is func_0215B4DC's third argument.
 */
int func_0215C138(void *c, void *vm)
{
    u16 *dst;
    u32 arg;
    u32 sel;
    u32 i;
    dst = func_02159AE8(c, vm);
    arg = func_02159B10(c, vm);
    sel = func_02159B10(c, vm);
    for (i = 0; i < 12; i++) {
        if (sel == d_02171182[i]) {
            *dst = func_0215B4DC(vm, (void *)arg, (void *)sel);
            return 0;
        }
    }
    *dst = 0;
    return 0;
}





/*
 * Script command: reads a destination variable and three arguments,
 * fills a 0x24-byte spec on the stack (function 0x0215C4C8 consumes it)
 * and stores the returned value through the destination.
 */
int func_0215C180(void *c, void *vm)
{
    void *sys;
    u16 v;
    u16 *dst;
    u32 a;
    u32 b;
    u32 d;
    Spec_0 s;

    func_0215A5DC(vm);
    sys = func_0215A5E4(vm);
    v = func_0215A5CC(vm);
    func_02012934(sys);
    func_02012944(sys);
    dst = func_02159AE8(c, vm);
    a = func_02159B10(c, vm);
    b = func_02159B10(c, vm);
    d = func_02159B10(c, vm);
    s.f00 = v;
    s.f04 = a;
    s.f08 = b;
    s.f0c = d;
    s.f10 = 0;
    s.f14 = 2;
    s.f18 = 2;
    s.f1c = 2;
    s.f20 = 4;
    *dst = func_0215C4C8(sys, &s);
    return 0;
}





/*
 * Script command, sibling of func_0215C180: reads a destination variable
 * and eight arguments, three of them clamped to 2 when 3 or more, fills
 * the 0x24-byte spec func_0215C4C8 consumes and stores its result.
 *
 * The arguments are u16 (func_02159B10 returns u16): the widening copy
 * into each int field is why the clamp of the spilled one reloads its
 * slot, and comparing the int field (not the u16 local) gives blt.
 */
int func_0215C200(void *c, void *vm)
{
    void *sys;
    u16 v;
    u16 *dst;
    u16 a;
    u16 b;
    u16 d;
    u16 e;
    u16 f;
    u16 g;
    u16 h;
    u16 i;
    Spec_1 s;

    func_0215A5DC(vm);
    sys = func_0215A5E4(vm);
    v = func_0215A5CC(vm);
    func_02012934(sys);
    func_02012944(sys);
    dst = func_02159AE8(c, vm);
    a = func_02159B10(c, vm);
    b = func_02159B10(c, vm);
    d = func_02159B10(c, vm);
    e = func_02159B10(c, vm);
    f = func_02159B10(c, vm);
    g = func_02159B10(c, vm);
    h = func_02159B10(c, vm);
    i = func_02159B10(c, vm);
    s.f00 = v;
    s.f04 = a;
    s.f08 = b;
    s.f0c = d;
    s.f10 = h;
    s.f14 = e;
    if (s.f14 >= 3) {
        s.f14 = 2;
    }
    s.f18 = f;
    if (s.f18 >= 3) {
        s.f18 = 2;
    }
    s.f1c = g;
    if (s.f1c >= 3) {
        s.f1c = 2;
    }
    s.f20 = i;
    *dst = func_0215C4C8(sys, &s);
    return 0;
}





/*
 * Script command: add a level-1 Pokemon egg of the given species and
 * form to the party (hatch counter from the personal data, the egg name
 * from message 0x28A), writing 1 to the result word, or 0 when the
 * party is full. First draft.
 */
int func_0215C2D0(void *c, void *vm)
{
    void *sys;
    u32 heap;
    void *party;
    void *my;
    u16 *res;
    u32 species;
    u32 form;
    void *mon;
    u32 t;
    u32 info;
    u32 v;

    func_0215A5DC(vm);
    sys = func_0215A5E4(vm);
    heap = func_0215A5CC(vm);
    party = func_02012934(sys);
    my = func_02012944(sys);
    res = func_02159AE8(c, vm);
    species = func_02159B10(c, vm);
    form = func_02159B10(c, vm);
    if ((int)func_0201AA14(party) <= (int)func_0201AA18(party)) {
        *res = 0;
        return 0;
    }
    mon = func_020173F0(species, 1, (u64)-1, heap);
    func_02017E40(mon, 0x6F, form);
    t = (u32)func_02008510(func_02012944(sys), heap);
    func_02017E40(mon, 0x8D, t);
    func_02045808((struct U16Vec *)t);
    info = (u32)func_0201ADE4((u16)func_02017E1C(mon, 5, 0), (u16)func_02017E1C(mon, 0x6F, 0), heap);
    v = func_0201AE1C((const struct Personal *)info, 0x15);
    func_0201AE14((void *)info);
    func_02017E40(mon, 9, v);
    func_02017E40(mon, 0x4C, 1);
    t = (u32)func_02045EC0(g_020A7370, 0x28A);
    func_02017E40(mon, 0x73, t);
    func_02045808((struct U16Vec *)t);
    func_020185C4(mon);
    func_0202F190(mon, 5, my, 0xEA63, heap);
    func_0201A98C(party, mon);
    func_020307B0(mon);
    *res = 1;
    return 0;
}





/*
 * lever: func_02017430's matched signature has two u64 inputs; widening the
 * personality result to u64 schedules its high zero before the low-word store.
 */
void *func_0215C40C(void *a, Spec *s)
{
    void *r7;
    void *r4;
    u32 t;
    r7 = func_02012944(a);
    r4 = (void *)func_02008530((const struct Sub0200852CObj *)func_02012944(a));
    t = func_020186C8((u32)r4, (u16)s->f04, (u16)s->f08, (u32)s->f18, (u32)s->f14, (u32)s->f1c);
    r4 = func_02017430(s->f04, s->f0c, (u32)r4, -1, t, s->f00);
    func_02017E40(r4, 0x6F, s->f08);
    func_02017E40(r4, 6, s->f10);
    if (func_02020FE4(s->f20, 0xF, s->f00) == 4)
        func_02017E40(r4, 0x98, (u32)func_0202142C((u16)s->f20));
    func_0202F190(r4, 0, (void *)r7, func_02013E4C(func_02012AC8(func_020127A4(a))), s->f00);
    func_020185C4(r4);
    return r4;
}






int func_0215C4C8(void *a, void *b)
{
    void *r6;
    void *r5;

    r6 = (void *)func_0201293C(a);
    if (func_02007984(r6) >= 0x2D0)
        return 0;
    r5 = func_0215C40C(a, b);
    func_020074D8(r6, (const struct Sub02007454Entry *)((u32)func_020185F4(r5)));
    func_0200CDE0(func_0200CA1C(a), r5);
    func_020307B0(r5);
    return 1;
}






int func_0215C510(void *a, void *b)
{
    void *r6;
    void *r5;

    r6 = func_02012934(a);
    if ((int)func_0201AA14(r6) <= (int)func_0201AA18(r6))
        return 0;
    r5 = func_0215C40C(a, b);
    func_0201A98C(r6, r5);
    func_0200CDE0(func_0200CA1C(a), r5);
    func_020307B0(r5);
    return 1;
}





/*
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 */
int func_0215C558(int a,int b)
{
    void *p = func_0215A5E4((void *)b);
    int k;
    func_020127A4(p);
    k = func_02159B10((void *)a,(void *)b);
    func_0200C278(func_02012F08(p),k);
    return 0;
}





int func_0215C584(int a,int b)
{
    void *p = func_0215A5E4((void *)b);
    int k;
    func_020127A4(p);
    k = func_02159B10((void *)a,(void *)b);
    func_0200C29C(func_02012F08(p),k);
    return 0;
}






int func_0215C5B0(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    unsigned int v = func_02159B10(a, b);
    void *q = func_0215A5E4(b);
    func_020127A4(q);
    *p = v <= func_0200C274(func_02012F08(q)) ? 1 : 0;
    return 0;
}





/*
 * Two overlay lookups on the second argument, the second of them classified
 * by an arm9 call, then submitted together.
 */
int func_0215C5EC(void *a0, void *a1)
{
    void *v = func_0215A5F4(a1);

    func_0215897C(v, func_020145CC(func_0215A5DC(a1)));

    return 1;
}








int func_0215C610(int a0, int a1)
{
    int t4;
    void *v0;
    void *v1;
    void *v2;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215C61A:
a0 = t4 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0215C622:
    v2 = func_0201210C(v1);
loc_0215C628:
    a0 = func_020144DC((int)v1, (int)v2);
loc_0215C630:
a1 = a0 + 0;
    func_0215897C(v0, (void *)a1);
loc_0215C638:
a0 = 1;
    return a0;}









/*
 * Starts a child process from an overlay on behalf of a script command:
 * allocates the 12-byte hand-off record (work pointer and two words),
 * launches the process over the work with func_020120B4, parks the record in the
 * script's slot and waits on func_0215C69C.
 */
void func_0215C63C(void *c, void *vm, u32 ovId, const void *proc, void *work, u32 arg0, u32 arg1)
{
    void *sys;
    void **slot;
    ProcHandoff *h;

    sys = func_0215A5DC(vm);
    slot = func_02158FB4(func_0215A5F4(vm));
    h = func_02030734(4, sizeof(ProcHandoff), 1, d_021728F0, 0x8B);
    h->work = work;
    h->arg1 = arg1;
    h->arg0 = arg0;
    func_020120B4(sys, ovId, (void *)proc, work);
    *slot = h;
    func_020113D0(c, (int)func_0215C69C);
}









int func_0215C69C(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;

t4 = a1 + 0;
a0 = t4 + 0;
    t6 = func_0215A5DC((void *)a0);
loc_0215C6A6:
a0 = t4 + 0;
    a0 = (int)func_0215A5F4((void *)a0); /* int-typed on purpose: pointer local changes codegen */
loc_0215C6AE:
t4 = a0 + 0;
    a0 = func_02158FB8((void *)a0);
loc_0215C6B4:
t5 = a0 + 0;
    a0 = func_020120F0(t6);
loc_0215C6BC:
    if (a0 == 0) goto loc_0215C6C4;
loc_0215C6C0:
a0 = 0;
    return a0;
loc_0215C6C4:
a1 = *(int *)&((struct Obj00005 *)t5)->f8;
    if (a1 == 0) goto loc_0215C6D0;
loc_0215C6CA:
a0 = t5 + 0;
    a0 = ((int (*)())a1)(a0);
loc_0215C6CE:
    goto loc_0215C6E4;
loc_0215C6D0:
a0 = *(int *)&((struct Obj00005 *)((char *)t5))->f0;
    if (a0 == 0) goto loc_0215C6DA;
loc_0215C6D6:
    func_020307B0((void *)a0);
loc_0215C6DA:
a0 = *(int *)&((struct Obj00005 *)t5)->f4;
    if (a0 == 0) goto loc_0215C6E4;
loc_0215C6E0:
    func_020307B0((void *)a0);
loc_0215C6E4:
a0 = t4 + 0;
    a0 = func_02158FBC(a0);
loc_0215C6EA:
a0 = 1;
    return a0;}









int func_0215C6F0(int a0, int a1)
{
    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215C6F8:
    a0 = func_02158FBC(v0);
loc_0215C6FC:
a0 = 1;
    return a0;}







/*
 * lever: Stores in both if/else arms retain the zero-first full branch;
 * a local flag (u32, u16, or enum) folds to 42 bytes and DIFF 33.
 */
void func_0215C700(Pair *p)
{
    Context *c = p->context;
    Outputs *o = p->outputs;
    if (c->first == 0)
        *o->first = B_FALSE;
    else
        *o->first = B_TRUE;
    *o->second = c->second;
    func_020307B0(p->outputs);
    func_020307B0(p->context);
}








/*
 * Script command: reads a selector and two words, maps the selector
 * (0 -> 4, 1 -> 5, else 0), then opens overlay 0x46 over a work built
 * from func_0202E474 with an 8-byte hand-off record.
 *
 * 2026-10-05 (wave D9): EXACT. The ov070 token on the d_021BB96C data line
 * (the proc table lives in ov070, the overlay this function opens) gave the
 * witness; ov070_id then resolved through the overlay_id walk (func_0215C63C
 * is a registered consumer). Source unchanged.
 */
int func_0215C72C(void *c, void *vm)
{
    u32 sel;
    u32 a;
    u32 b;
    u32 k;
    void *work;
    u32 *h;

    func_0215A5DC(vm);
    func_0215A5F4(vm);
    sel = func_02159B10(c, vm);
    a = (u32)func_02159AE8(c, vm);
    b = (u32)func_02159AE8(c, vm);
    if (sel == 0)
        k = 4;
    else if (sel == 1)
        k = 5;
    else
        k = 0;
    work = func_0202E474((const struct BigObj *)func_0215A5E4(vm), 0, k, 4);
    h = func_02030734(4, 8, 1, d_021728F0, 0x118);
    h[0] = a;
    h[1] = b;
    func_0215C63C(c, vm, (u32)ov070_id, d_021BB96C, work, (u32)func_0215C700, (u32)h);
    return 1;
}






/*
 * Unlabelled Thumb leaf (callback of func_0215C7E0): stores whether the
 * first record's word at +4 equals 1 into the halfword the second record
 * points to, then frees the first record's first word.
 */
void func_0215C7C4(Rec *r)
{
    if (r->src[1] == 1)
        *r->dst = 1;
    else
        *r->dst = 0;
    func_020307B0(r->src);
}








/*
 * Script command: allocates two 8-byte records (a work holding the
 * system's word, then a hand-off holding the work and one script word),
 * launches overlay 0x88 over them with the func_0215C7C4 callback and
 * parks the result in the script's slot.
 *
 * 2026-10-05 (wave D9): EXACT. d_021C78A4 resolves once its symbols line carries the ov136 token (the overlay the function loads); func_0215C7C4 has its own witness.
 */
int func_0215C7E0(void *c, void *vm)
{
    void *slot;
    void *sys;
    void *w;
    void *x;
    u32 *a;
    u32 *b;

    slot = func_0215A5F4(vm);
    sys = func_0215A5DC(vm);
    w = func_020120F4(sys);
    x = func_0201210C(sys);
    a = func_02030734(4, 8, 0, d_021728F0, 0x14F);
    b = func_02030734(4, 8, 0, d_021728F0, 0x150);
    a[0] = (u32)w;
    b[0] = (u32)a;
    b[1] = (u32)func_02159AE8(c, vm);
    func_0215897C(slot, func_02014840(sys, (int)x, (u32)ov136_id, (int)d_021C78A4, (int)a, (int)((void *)func_0215C7C4), (int)b));
    return 1;
}








int func_0215C870(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj04131 *)((char *)t4))->f0;
a0 = ((struct Obj04131 *)a0)->f1A;
    if (a0 == 0) goto loc_0215C880;
loc_0215C87C:
    if (a0 == 1) goto loc_0215C884;
loc_0215C880:
a1 = 0;
    goto loc_0215C886;
loc_0215C884:
a1 = 1;
loc_0215C886:
a0 = ((struct Obj04131 *)t4)->f4;
*(u16 *)&((struct Obj04131 *)((char *)a0))->f0 = a1;
a0 = ((struct Obj04131 *)((char *)t4))->f0;
a0 = ((struct Obj04131 *)a0)->f10;
    a0 = (int)func_020307B0((void *)a0);
loc_0215C892:
a0 = ((struct Obj04131 *)((char *)t4))->f0;
    a0 = func_0216F940(a0);
loc_0215C898:
    return a0;}








static inline void init_record(Relearn *r, void *mon, void *sess, void *sys, void *moves)
{
    enum One { ONE = 1 } one;
    r->mon = mon;
    r->sess = sess;
    r->f08 = 0;
    r->sys = sys;
    r->moves = moves;
    one = ONE;
    r->f19 = one;
}







/*
 * lever: enum one assigned immediately before the f19 store in the inline
 * record initializer separates it from the constant return and selects r0.
 */
int func_0215C89C(void *c, void *vm)
{
    void *slot;
    void *sys;
    void *w;
    void *x;
    u32 a;
    u32 idx;
    void *mon;
    void *sess;
    void *moves;
    Relearn *r;
    u32 *h;

    slot = func_0215A5F4(vm);
    sys = func_0215A5DC(vm);
    w = func_020120F4(sys);
    x = func_0201210C(sys);
    a = (u32)func_02159AE8(c, vm);
    idx = func_02159B10(c, vm);
    mon = func_0201AB28(func_02012934(w), idx);
    sess = func_02012944(w);
    moves = func_0216F948(mon, 4);
    r = func_0216F918(4);
    init_record(r, mon, sess, sys, moves);
    h = func_02030734(4, 8, 0, d_021728F0, 0x19B);
    h[0] = (u32)r;
    h[1] = a;
    func_0215897C(slot, func_02014808(sys, (int)x, (u32)ov173_id, (int)d_021B81D0, (int)r, (int)((void *)func_0215C870), (int)h));
    return 1;
}








/*
 * Script command: opens the ov071 process on a 0x40-byte work. When the
 * current link record is usable (another player's slot, flagged, and
 * marked at +0x922) the work takes that player's name and profile;
 * otherwise it is filled from the local player. The chosen slot index
 * (0 for the local player) is stored at +0x3C.
 *
 * MATCH, bytes exact (2026-09-28 tree_ov010_4; lever: one `idx` local
 * set in both arms, which is what keeps the r6 zero). Three wildcards:
 * ov011 0x02175FB4 is an unlabelled leaf (`ldrb r0, [r0, #0x10]; bx lr`),
 * and the pooled 0x47 (ov071_id) and 0x021BA758 (the ov071 process
 * template) only reach an overlay loader through func_0215C63C, so no
 * class attests them.
 *
 * 2026-10-05 (wave D9): d_021BA758 now resolves with the ov099 token on its symbols line (`data  ov099  a1`; other covering overlays stay contested or unresolved). Only ov071_id remains: it reaches func_0215C63C, which is not in match.py OVERLAY_ID_CONSUMERS (forwards r2 to func_020120B4 r1); a data token on the id line does not help. Needs the consumer entry (tools), not C.
 */
int func_0215C95C(void *c, void *vm)
{
    void *sys;
    void *p;
    void *q;
    ProfileWork *w;
    LinkState *st;
    u8 idx;

    sys = func_0215A5DC(vm);
    p = (void *)func_02012138(sys);
    q = func_020120F4(sys);
    func_0215A5F4(vm);
    st = (LinkState *)func_02158344((int)p);
    w = func_02030734(4, sizeof(ProfileWork), 1, d_021728F0, 0x1BC);
    if (st != 0 && st->self != func_02012B58(q)
        && func_02175FB4((u8 *)(&st->recs[func_0215841C(q)])) == 1
        && ((u8 *)st)[0x922] == 1) {
        idx = func_0215841C(q);
        w->name = *func_0215840C(st, idx);
        w->profile = *(Profile16 *)((u8 *)st + 0x914);
        w->remote = 1;
    } else {
        func_0200BE48(func_02012EBC(q));
        func_02175648(q, (struct Out *)(&w->profile));
        idx = 0;
        w->remote = 0;
    }
    w->sys = sys;
    w->slot = idx;
    func_0215C63C(c, vm, (u32)ov071_id, d_021BA758, w, 0, 0);
    return 1;
}








/*
 * Script command: reads two words and stores func_02161B90's result
 * (over the system and the script's cell) in the script's slot.
 */
int func_0215CA64(void *c, void *vm)
{
    void *slot;
    void *sys;
    u32 a;
    u32 b;

    slot = func_0215A5F4(vm);
    sys = func_0215A5DC(vm);
    a = func_02159B10(c, vm);
    b = func_02159B10(c, vm);
    func_0215897C(slot, func_02161B90(sys, func_02158F50(slot), a, b, 0));
    return 1;
}








/*
 * Script command: reads one halfword and the system, boxes them in an
 * 8-byte record and opens overlay 0xAE over it.
 *
 * Bytes exact.
 *
 * 2026-10-05 (wave D9): EXACT. The ov174 token on the d_021B74A0 data line (the
 * proc table lives in ov174, which this function loads) gave the witness; the
 * ov174_id word then resolved through the overlay_id walk. Source unchanged.
 */
int func_0215CAB4(void *c, void *vm)
{
    u16 v;
    Box8_0215CAB4 *b;

    v = func_02159B10(c, vm);
    b = func_02030734(4, 8, 1, d_021728F0, 0x205);
    b->v = v;
    b->sys = func_0215A5E4(vm);
    func_0215C63C(c, vm, (u32)ov174_id, d_021B74A0, b, 0, 0);
    return 1;
}








/*
 * Script command: reads a mode (0-2) and a word; unless the mode is 2
 * calls func_02165344, then boxes the system object (and the word) in a
 * hand-off record and opens overlay 0xDD, 0xDE or 0xE0 over it through
 * func_0215C63C.
 *
 * MATCH, bytes exact. Blockers: the three overlay ids (ABS32 0xDD, 0xDE,
 * 0xE0) have no witness: `overlay_id` would carry them, but func_0215C63C
 * (which forwards its r2 to func_020120B4's r1) is not in match.py's
 * OVERLAY_ID_CONSUMERS. d_021BA250 (ov222) and d_021B9BF8 (ov224) are
 * contested hints that resolve once the function loads those overlays
 * through an overlay_id site. d_021BA1A4 (ov221) already resolves.
 *
 * 2026-10-05 (wave D9): re-tried overlay tokens on the contested hints; they stay contested because the id sites do not attest. Residue is the three id words (ov221_id, ov222_id, ov224_id) reaching func_0215C63C, which is not in OVERLAY_ID_CONSUMERS; add that consumer (r2 -> func_020120B4 r1) and the hints resolve. Not fixable in C.
 */
int func_0215CB08(void *c, void *vm)
{
    void *sys;
    void *sub;
    u32 mode;
    u32 v;
    Box8_0215CB08 *b;
    void **w;

    sys = func_020120F4(func_0215A5DC(vm));
    sub = func_02012944(sys);
    mode = func_02159B10(c, vm);
    v = func_02159B10(c, vm);
    if (mode != 2) {
        func_02165344();
    }
    switch (mode) {
    case 0:
        b = func_02030734(4, 8, 1, d_021728F0, 0x22B);
        b->sys = sys;
        b->v = v;
        func_0215C63C(c, vm, (u32)ov221_id, d_021BA1A4, b, 0, 0);
        break;
    case 1:
        b = func_02030734(4, 8, 1, d_021728F0, 0x233);
        b->sys = sys;
        b->v = v;
        func_0215C63C(c, vm, (u32)ov222_id, d_021BA250, b, 0, 0);
        break;
    case 2:
        w = func_02030734(4, 4, 1, d_021728F0, 0x23C);
        *w = sub;
        func_0215C63C(c, vm, (u32)ov224_id, d_021B9BF8, w, 0, 0);
        break;
    }
    return 1;
}








/*
 * Script command: reads one word from the script stream, boxes it in a
 * 4-byte hand-off record and opens overlay 0xDF over it.
 *
 * 2026-10-05 (D9 lane 02): d_021BC8C4 resolves with the ov223 token (the overlay it points into) on its data line; ov223_id resolves as an overlay id word.
 *
 * 2026-10-05 (wave D8): ov223_id and d_021BC8C4 are data with no witness; not fixable in C. Source re-read against the listing, unchanged.
 */
int func_0215CBF0(void *c, void *vm)
{
    u32 v;
    u32 *w;

    v = (u32)func_02159AE8(c, vm);
    w = func_02030734(4, 8, 1, d_021728F0, 0x254);
    w[0] = v;
    func_0215C63C(c, vm, (u32)ov223_id, d_021BC8C4, w, 0, 0);
    return 1;
}








int func_0215CC38(int a0, int a1)
{
    int t4;
    void *v0;
    void *v1;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215CC42:
a0 = t4 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0215CC48:
a0 = 1;
    return a0;}








/*
 * Script command: reads a kind (0xF-0x13 mapped to 0-4) and a flag (0/1),
 * builds a four-word request on the stack and launches func_02154438
 * (ov002) through func_020124AC, parking the result in the script's slot.
 */
int func_0215CC4C(void *c, void *vm)
{
    void *slot;
    void *sys;
    u32 kind;
    u32 flag;
    u32 k;
    u32 f;
    Req_0215C40C r;

    slot = func_0215A5F4(vm);
    sys = func_0215A5DC(vm);
    kind = func_02159B10(c, vm);
    flag = func_02159B10(c, vm);
    switch (kind) {
    case 0xF:
        k = 0;
        break;
    case 0x10:
        k = 1;
        break;
    case 0x11:
        k = 2;
        break;
    case 0x12:
        k = 3;
        break;
    case 0x13:
        k = 4;
        break;
    }
    switch (flag) {
    case 0:
        f = 0;
        break;
    case 1:
        f = 1;
        break;
    }
    r.sys = func_0201210C(sys);
    r.one = 1;
    r.flag = f;
    r.kind = k;
    func_0215897C(slot, func_020124AC(sys, (u32)ov002_id, (void *)func_02154438, (u32)(&r)));
    return 1;
}








/*
 * The ov003 callback 0x021543BC (unlabelled leaf, formerly the blocker) is
 * matched in pkt_ov003_021543BC and attests as matched.
 */
int func_0215CCE8(void *a, void *b)
{
    Arg arg;
    void *t = func_0215A5F4(b);
    void *h = func_0215A5DC(b);
    u32 k = !func_02159B10(a, b) ? 1 : 2;
    arg.a = (u32)func_0201210C(h);
    arg.b = k;
    func_0215897C(t, func_020124AC(h, (u32)ov003_id, (void *)func_021543BC, (u32)(&arg)));
    return 1;
}








int func_0215CD3C(void *a, void *b)
{
    void *h = func_0215A5DC(b);
    u16 *p = func_02159AE8(a, b);
    u16 *q = func_02159AE8(a, b);
    func_02034AC4((u32)ov037_id);
    func_021F36C0((unsigned int)h, *p, *q);
    func_02034A5C((u32)ov037_id);
    return 0;
}








int func_0215CD80(void *a, void *b)
{
    void *p = func_0215A5DC(b);
    int v = func_02159B10(a, b);
    func_02034AC4((int)ov037_id);
    func_021F36E8(p, v);
    func_02034A5C((int)ov037_id);
    return 0;
}







int func_0215CDB8(void *a, void *b)
{
    void *p = func_0215A5DC(b);
    int v = func_02159B10(a, b);
    func_02034AC4((int)ov037_id);
    func_021F3724((unsigned int)p, v);
    func_02034A5C((int)ov037_id);
    return 0;
}







int func_0215CDF0(void *a, void *b)
{
    unsigned short *v[8];
    void *h = func_0215A5DC(b);
    v[0] = func_02159AE8(a, b);
    v[1] = func_02159AE8(a, b);
    v[2] = func_02159AE8(a, b);
    v[3] = func_02159AE8(a, b);
    v[4] = func_02159AE8(a, b);
    v[5] = func_02159AE8(a, b);
    v[6] = func_02159AE8(a, b);
    v[7] = func_02159AE8(a, b);
    func_02034AC4((u32)ov037_id);
    func_021F3768((unsigned int)h, v);
    func_02034A5C((u32)ov037_id);
    return 0;
}







int func_0215CE70(void *a, void *b)
{
    void *p = func_0215A5DC(b);
    func_02034AC4((int)ov037_id);
    func_021F3800((unsigned int)p);
    func_02034A5C((int)ov037_id);
    return 0;
}







/*
 * unblocked: func_021C3400 (ov021, unlabelled leaf) was matched bottom-up
 *   and filed as pkt_021C3400; the `ov021` token then resolves the site as
 *   `matched, overlay`.  Extent runs 36 bytes against 34 compiled: the
 *   unlabelled follower.
 */
int func_0215CE98(int a0, int a1)
{    int t5;
    unsigned short *v0;
    void *v1;
    void *v2;

t5 = a1 + 0;
    v0 = func_02159AE8((void *)a0, (void *)a1);
loc_0215CEA0:
a0 = t5 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0215CEA8:
    v2 = func_0201210C(v1);
loc_0215CEAC:
    a0 = func_021C3400(func_02188D50(v2));
loc_0215CEB0:
loc_0215CEB4:
((struct Obj17693 *)((char *)v0))->f0 = a0;
a0 = 0;
    return a0;}







int func_0215CEBC(void *a, void *b)
{
    void *p = func_0215A5DC(b);
    void *q = func_02012934(func_0215A5E4(b));
    func_021C32F4(func_02188D50(func_0201210C(p)), (unsigned int)q);
    return 0;
}







int func_0215CEE8(int a0, int a1)
{
    void *v0;
    void *v1;

a0 = a1 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215CEF0:
    v1 = func_0201210C(v0);
loc_0215CEF4:
    func_021C335C((void **)func_02188D50(v1));
loc_0215CEF8:
loc_0215CEFC:
a0 = 0;
    return a0;}







int func_0215CF00(void *a, void *b)
{
    void *t = func_0215A5F4(b);
    unsigned short *v = func_02159AE8(a, b);
    void *p = func_0215A5E4(b);
    void *h = func_0215A5DC(b);
    void *s = func_0201210C(h);
    func_02012934(p);
    func_0200BDB0(func_02012EBC(p));
    func_0215897C(t, func_0215D2A4(h, (u32)s, (u32)v));
    return 1;
}







int func_0215CF54(void *a, void *b)
{
    int v = func_02159B10(a, b);
    void *q = func_02012934(func_0215A5E4(b));
    func_021C3204(func_02188D50(func_0201210C(func_0215A5DC(b))), (unsigned int)q, v);
    return 0;
}







int func_0215CF84(void *a, void *b)
{
    int v = func_02159B10(a, b);
    void *q = func_02012934(func_0215A5E4(b));
    func_021C3270(func_02188D50(func_0201210C(func_0215A5DC(b))), v, (unsigned int)q);
    return 0;
}







int func_0215CFB4(int a0, int a1)
{    int t5;
    unsigned short *v0;
    void *v1;
    void *v2;

t5 = a1 + 0;
    v0 = func_02159AE8((void *)a0, (void *)a1);
loc_0215CFBC:
a0 = t5 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0215CFC4:
    v2 = func_0201210C(v1);
loc_0215CFC8:
    a0 = func_021C340C(func_02188D50(v2));
loc_0215CFCC:
loc_0215CFD0:
((struct Obj17694 *)((char *)v0))->f0 = a0;
a0 = 0;
    return a0;}







int func_0215CFD8(int a0, int a1)
{    int t5;
    unsigned short *v0;
    void *v1;
    void *v2;

t5 = a1 + 0;
    v0 = func_02159AE8((void *)a0, (void *)a1);
loc_0215CFE0:
a0 = t5 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0215CFE8:
    v2 = func_0201210C(v1);
loc_0215CFEC:
    a0 = func_021C34C4((void **)func_02188D50(v2));
loc_0215CFF0:
loc_0215CFF4:
((struct Obj17695 *)((char *)v0))->f0 = a0;
a0 = 0;
    return a0;}







/*
 * interface: func_021C34F8 has two observed inputs. Its full ov021 body
 * and 0200BCA8/0200BC2C read r0/r1 only; legacy trailing r2/r3 are omitted.
 */
int func_0215CFFC(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    int v = func_02159B10(a, b);
    void *q = func_021C34F8(func_02188D50(func_0201210C(func_0215A5DC(b))), v);
    *p = func_02017E1C(q, 5, 0);

    return 0;
}







int func_0215D034(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    int v = func_02159B10(a, b);
    void *q = func_021C34F8(func_02188D50(func_0201210C(func_0215A5DC(b))), v);
    *p = func_02017E1C(q, 111, 0);

    return 0;
}







int func_0215D06C(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    int v = func_02159B10(a, b);
    void *q = func_021C34F8(func_02188D50(func_0201210C(func_0215A5DC(b))), v);
    *p = func_02017E1C(q, 110, 0);

    return 0;
}







int func_0215D0A4(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    int v = func_02159B10(a, b);
    *p = func_021C341C(func_02188D50(func_0201210C(func_0215A5DC(b))), v);

    return 0;
}






int func_0215D0D4(void *a,void *b)
{
 u16 *p = func_02159AE8(a,b);
 int i = func_02159B10(a,b);
 void **q = func_02188D50(func_0201210C(func_0215A5DC(b)));
 func_021C34F8(q,i);
 *p = func_021C3490(q,i);
 return 0;
}






int func_0215D110(void *a,void *b)
{
 u16 *p = func_02159AE8(a,b);
 int i = func_02159B10(a,b);
 void **q = func_02188D50(func_0201210C(func_0215A5DC(b)));
 func_021C34F8(q,i);
 *p = func_021C34B4(q,i);
 return 0;
}







int func_0215D14C(void *a, void *b)
{
    int f;
    u16 *p;
    void *r;
    void *s = func_02188D50(func_0201210C(func_0215A5DC(b)));
    p = func_02159AE8(a, b);
    f = func_02159B10(a, b);
    r = func_021C34F8(s, func_02159B10(a, b));
    if (f == 0)
        *p = func_0215D198(r);
    else
        *p = 0;
    return 0;
}







int func_0215D198(void *x)
{
    int a = func_02017E1C(x, 5, 0);
    int b = func_02017E1C(x, 0x6e, 0);
    if (a == 0x20 || a == 0x1d) {
        a = 0;
        if (func_02017E1C(x, 0x75, 0) == 0)
            return a;
    }
    switch (b) {
    case 2:
    default: return 0;
    case 0: return 1;
    case 1: return 2;
    }
}







int func_0215D1E4(void *a, u32 *st, Ctx_0215D1E4 *c)
{
    u32 s = *st;
    void *p0 = c->f0;
    switch (s) {
    case 0:
        func_02012374(a, func_021BE8D4(p0, c->f4, 0, 0));
        *st = 1;
        break;
    case 1:
        func_02012374(a, (struct Evt **)func_020144DC((int)p0, (int)c->f4));
        c->f8->f3c = c->fC->fF;
        *st = 2;
        break;
    case 2:
        func_02012374(a, func_02014910(p0, (int)c->f4, (int)c->f8, (int)c->fC));
        *st = 3;
        break;
    case 3:
        func_02012374(a, func_020145CC(p0));
        *st = 4;
        break;
    case 4:
        func_02012374(a, func_021BE92C(p0, c->f4, 0, 0, 1, 0, 0));
        *st = 5;
        break;
    case 5:
        *c->f10 = c->f8->f3c;
        func_020307B0(c->f8);
        func_020307B0(c->fC);
        return 1;
    }
    return 0;
}







void *func_0215D2A4(void *a, u32 b, u32 c)
{
    void *r7 = func_020120F4(a);
    void *v = func_02012934(r7);
    u32 w = (u32)func_0200CA1C(r7);
    A *x = func_02030734(4, 0x98, 0, d_02172900, 0x22B);
    B *y;
    Ctx_0215D2A4 *ctx;
    void *h;
    x->f00 = v;
    x->f34 = 0x12;
    x->f38 = 0;
    x->f3c = 0;
    y = func_02030734(4, 0x28, 0, d_02172900, 0x232);
    y->f00 = x->f00;
    y->f04 = x->f0c;
    y->f08 = (u32)r7;
    y->f0c = 1;
    y->f0e = func_0201AA18(v);
    y->f0d = 0;
    y->f10 = 0;
    y->f0f = 0;
    y->f18 = func_0200CA38((struct Blk37 *)w);
    h = func_020122C0(a, 0, (void *)func_0215D1E4, 0x14);
    ctx = func_020124E8(h);
    ctx->f0 = a;
    ctx->f4 = b;
    ctx->f8 = x;
    ctx->fC = y;
    ctx->f10 = c;
    return h;
}
