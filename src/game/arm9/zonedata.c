/*
 * file:     zonedata.c
 * unit:     yes
 * function: func_020139B0, func_02013A48, func_02013A80, func_02013A94, func_02013AD0, func_02013B10, func_02013B38, func_02013B44, func_02013B50, func_02013B5C, func_02013B68, func_02013B74, func_02013B90, func_02013BA8, func_02013BBC, func_02013BD0, func_02013BDC, func_02013C10, func_02013C20, func_02013C30, func_02013C40, func_02013C50, func_02013C60, func_02013C70, func_02013C80, func_02013C9C, func_02013CC8, func_02013CE0, func_02013D00, func_02013D20, func_02013D34, func_02013D5C, func_02013D74, func_02013D9C, func_02013DB8, func_02013DD0, func_02013DE0, func_02013DF0, func_02013E04, func_02013E40, func_02013E4C, func_02013E6C, func_02013E7C, func_02013E90, func_02013EC0, func_02013ECC, func_02013ED8, func_02013EEC, func_02013F2C, func_02013F6C, func_02013FA8, func_02013FD8, func_02013FFC, func_0201400C, func_02014018, func_02014024, func_02014034, func_02014044, func_0201405C, func_02014068, func_0201407C, func_020140B4, func_020140BC, func_020140C0, func_020140CC, func_020140D8, func_020140DC, func_020140E0, func_020140E4, func_020140E8, func_020140F8, func_02014110, func_02014134, func_0201416C, func_02014184, func_020141A8, func_020141DC, func_020141E0, func_020141F0, func_02014204, func_02014264, func_02014274, func_020142A4, func_020142E8, func_02014314, func_0201433C, func_02014368, func_02014388, func_020143CC, func_020143D8, func_020143F0, func_0201440C, func_0201441C, func_02014428, func_02014444, func_0201444C, func_02014450, func_02014454, func_02014458, func_0201445C, func_02014460, func_02014464, func_02014468, func_0201446C, func_02014470, func_02014474, func_02014478, func_0201447C, func_02014484, func_02014488, func_020144DC, func_0201450C, func_02014554, func_02014584, func_020145CC, func_020145FC, func_02014628, func_02014698, func_020146F8, func_02014728, func_02014758, func_020147B0, func_02014808, func_02014840, func_02014878
 * address:  0x020139B0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_sub02013AD0Obj  0x02146264  data
 *   sZonedataFile     0x020A72B0  data
 *   func_02030734     0x02030734  arm
 *   func_020490F4     0x020490F4  arm
 *   func_0204A298     0x0204A298  arm
 *   func_020307B0     0x020307B0  arm
 *   func_02049238     0x02049238  arm
 *   sub_020A72A8_Key  0x020A72A8  data
 *   sub_020A72AA_Val  0x020A72AA  data
 *   sub_02013A94      0x02013A94  thumb
 *   sub_0204944C      0x0204944C  arm
 *   tbl_0209E010  0x0209E010  data
 *   sub_0209E026_Map  0x0209E026  data
 *   func_02013D9C  0x02013D9C  thumb
 *   func_02013B10  0x02013B10  thumb
 *   d_0209DFC0     0x0209DFC0  data  a4
 *   d_0209DFEC     0x0209DFEC  data  a4
 *   sub_02013D74  0x02013D74  thumb
 *   func_02013B44  0x02013B44  thumb
 *   g_sub02013AD0Obj2  0x02146264  data
 *   sub_0209DFC8_Map  0x0209DFC8  data
 *   func_02020E08  0x02020E08  thumb
 *   sub_020307B0  0x020307B0  arm
 *   sub_02082BCC  0x02082BCC  arm
 *   sub_02146268_Sys  0x02146268  data
 *   sub_02014368  0x02014368  thumb
 *   sub_0209E050_Map  0x0209E050  data
 *   sBtlSetupFile  0x020A72BC  data
 *   ENV_SetResourceSet  0x020307B0  arm
 *   sub_020120F0   0x020120F0  thumb
 *   sub_02012A30   0x02012A30  thumb
 *   sub_020289B8   0x020289B8  thumb
 *   func_0215FA44  0x0215FA44  thumb  ov010
 *   func_02188BD8  0x02188BD8  thumb  ov021
 *   func_02188BE8  0x02188BE8  thumb ov021
 *   func_0215FA34  0x0215FA34  thumb  ov010
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   ov091_id        0x0000005B  data
 *   ov131_id        0x00000083  data
 *   g_021BED00      0x021BED00  data
 *   g_021DC800      0x021DC800  data
 */
#include "../../matched/include/Obj00193.h"
#include "../../matched/include/Obj15653.h"
#include "../../matched/include/Obj05792.h"
#include "../../matched/include/Obj06860.h"
#include "../../matched/include/Obj06862.h"
#include "../../matched/include/Obj08750.h"

struct ArcFile;
struct t_020141E0;
struct BigObj;
struct Ctx;
struct Sys;
struct IcaAnime;
struct Desc;
struct Obj;
struct Evt;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct ZoneDataMgr {
    void *archive;
    u8    record[0x34 - 0x04];
    u16   cached_id;
    u16   pad36;
    void *table38;
    void *table3c;
    u16   count40;
    u8    count42;
    u8    count43;
    void *table44;
    u8    subst_on[0x4c - 0x48];
};

typedef int             s32_02013AD0;

struct Sub02013AD0Rec_02013AD0 {
    u8  unk00;
    u16 unk02;
    u16 unk04;
    u16 unk06;
    u8  pad08[0x0a - 0x08];
    u16 unk0a;
    u8  pad0c[0x24 - 0x0c];
    u32 unk24;
    u32 unk28;
    u32 unk2c;
};

struct Sub02013AD0Rec_02013BA8 {
    u8 pad00[0x1c];
    struct {
        u16 lo6 : 6;
        u16 mid3 : 3;
        u16 hi7 : 7;
    } unk1c;
    u16 unk1e;
    u16 unk20;
};

struct ZoneRec {
    u8  pad00[0x0c - 0x00];
    u16 conn0c;
    u16 conn0e;
    u16 conn10;
    u16 conn12;
};

struct Sub02013AD0Rec_02013C10 {
    u8 pad00[0x1c];
    struct {
        u16 lo6 : 6;
        u16 mid3 : 3;
        u16 hi7 : 7;
    } unk1c;
    struct {
        u16 pad0 : 10;
        u16 flag10 : 1;
        u16 pad11 : 1;
        u16 flag12 : 1;
        u16 flag13 : 1;
        u16 flag14 : 1;
        u16 flag15 : 1;
    } unk1e;
};

typedef signed short s16_020139B0;

typedef signed char s8;

typedef signed int     s32_02013C70;

struct Ent0209E026 {
    unsigned short code : 11;
    unsigned short kind : 5;
};

typedef signed int     s32_02013C9C;

struct Sub02013AD0Rec_02013DF0 {
    u8 pad00[4];
    u16 unk04;
    u8 pad06[0x14 - 6];
    u16 unk14;
    u16 unk16;
    u16 unk18;
    struct {
        u16 lo10 : 10;
        u16 hi6 : 6;
    } unk1a;
};

struct Sub02013AD0Rec_02013EC0 {
    u8 pad00[0x14];
    u16 unk14;
    u16 unk16;
};

typedef int             s32_02013DF0;

/* the record sub_02013AD0() returns; only the two 5 bit fields at 0x1e
 * that this file reads. */
struct Sub02013AD0Rec_02013ED8 {
    u8  pad00[0x1e];
    u16 lo5 : 5;
    u16 mid5 : 5;
    u16 hi6 : 6;
};

struct Sub02013ED8Pair {
    u16 key;
    u16 val;
};

struct Sub02013ED8Obj {
    u8                        pad00[0x38];
    const struct Sub02013ED8Pair *arr1;    /* 0x38 */
    const struct Sub02013ED8Pair *arr2;    /* 0x3c */
    u16                        count1;      /* 0x40 */
    u8                         count2;      /* 0x42 */
    u8                         count3;      /* 0x43 */
    const struct Sub02013ED8Pair *arr3;    /* 0x44 */
};

struct Ent0209DFC8 {
    unsigned short code : 11;
    unsigned short kind : 5;
};

struct Sub020140BCObj {
    u16 f00;
    u16 f02;
    u8  f04;
    u8  f05;
    u8  f06;
    u8  f07;
    u8  f08;
    u8  f09;
};

typedef struct {
    u32 x00;
    u16 x04, x06, x08, x0A;
    u32 x0C, x10, x14, x18;
} Rect14110;

typedef signed short s16_02014134;

typedef signed int s32;

typedef struct {
    u32 live;
    u16 id;
    s16_02014134 slot;
    s16_02014134 count;
    u16 pad;
    u32 zero;
    u32 a;
    u32 b;
    u32 c;
} Rec1C;

typedef short s16_020141A8;

struct t_020139B0 {
    u32 a;      /* 0x00 */
    u16 b;      /* 0x04 */
    s16_020141A8 c;      /* 0x06 */
    u16 d;      /* 0x08 */
    u16 e;      /* 0x0a */
    u32 f;      /* 0x0c */
    u16 g;      /* 0x10 */
    u8  on;     /* 0x12 */
    u8  kind;   /* 0x13 */
    s16_020141A8 h;      /* 0x14 */
    u16 i;      /* 0x16 */
};

typedef struct Rec020141DC {
    int f0;
    int f4;
    int f8;
    int fC;
} Rec020141DC;

typedef struct Vec020141E0 {
    int x;
    int y;
    int z;
} Vec020141E0;

typedef struct Rec020141E0 {
    int f0;
    int f4;
    int f8;
    int fC;
    Vec020141E0 v;
} Rec020141E0;

typedef struct Vec020141F0 {
    int x;
    int y;
    int z;
} Vec020141F0;

typedef struct Rec020141F0 {
    int f0;
    int f4;
    int f8;
    int fC;
    Vec020141F0 v;
} Rec020141F0;

typedef short s16_020141E0;

struct t_020141E0 {
    u32 a;      /* 0x00 */
    u16 b;      /* 0x04 */
    s16_020141E0 c;      /* 0x06 */
    u16 d;      /* 0x08 */
    u16 e;      /* 0x0a */
    u32 f;      /* 0x0c */
    u16 g;      /* 0x10 */
    u8  pad[2];
    u16 h;      /* 0x14 */
    u16 i;      /* 0x16 */
};

struct v3 { u32 x, y, z; };

struct Sub02014444Obj {
    u32 f00;
    u8  f04;
    u8  f05;
    u8  f06;
    u16 f08;
    u8  pad0A[7];
    u8  f11;
    u16 f12;
};

typedef struct {
    int   f00;
    int   f04;
    int   f08;
    int   f0c;
    int   f10;
    void (*f14)(void *);
    void *f18;
} S;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204A298(int a0, int a1, int a2, int a3, u32 *out);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *handle);
extern u16 sub_02013A94(u32 key);
extern void sub_0204944C(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
extern u32 func_02013B10(u32 id, const u16 *table, s32_02013C70 count);
extern u32 func_02013D9C(u32 id);
extern int sub_02013D74(u32 key);
extern u32 func_02013B44(u32 id);
extern void *func_02020E08(u32 archive_id, u32 heap, u32 offset, u32 size);
extern u32 sub_020307B0(void *p);
extern u32  func_02014274(u32 a);
extern u32 sub_02082BCC(u32 a, u32 b, u32 c);
extern void sub_02014368(char *a0, int a1, int a2);
extern void ENV_SetResourceSet(u32 a, u32 b, u32 c);
extern u32 sub_02012A30(const struct BigObj *p);
extern u32 sub_020120F0(const struct Ctx *p);
extern u32 sub_020289B8(struct Sys *s);
extern void func_0215FA44(void);
extern void func_02188BD8(u8 *obj);
extern unsigned int func_02012A30(const struct BigObj *v);
extern u32 func_020120F0(const struct Ctx *p);
extern void func_020120C0(struct IcaAnime *p);
extern void *func_0201210C(const struct Ctx *p);
extern int  func_02188BE8(void *v);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_020120F4(const struct Ctx *p);
extern void func_0215FA34(void);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
void func_020139B0(u32 heap);
void func_02013A48(void);
void sub_02013A80(u32 index, u8 on);
u16 func_02013A94(u32 key);
void *sub_02013AD0(u32 id);
u32 sub_02013B10(u32 id, const u16 *table, s32_02013AD0 count);
u32 sub_02013B38(u32 id);
u32 sub_02013B44(u32 id);
u32 sub_02013B50(u32 id);
u32 sub_02013B5C(u32 id);
u32 sub_02013B68(u32 id);
void sub_02013B74(u32 id, u32 *out);
void sub_02013B90(u32 id, u32 *out);
u8 sub_02013BA8(u32 id);
u8 sub_02013BBC(u32 id);
u32 sub_02013BD0(u32 id);
u32 func_02013BDC(u32 id, u32 which);
u32 sub_02013C10(u32 id);
u32 sub_02013C20(u32 id);
u32 sub_02013C30(u32 id);
u32 sub_02013C40(u32 id);
u32 sub_02013C50(u32 id);
u32 sub_02013C60(u32 id);
int func_02013C70(u32 a);
int func_02013C80(int a0);
int func_02013C9C(u16 key);
u32 sub_02013CC8(u32 id);
u32 sub_02013CE0(u32 id);
u32 sub_02013D00(u32 id);
u32 sub_02013D20(u32 id);
u32 sub_02013D34(u32 id);
u32 sub_02013D5C(u32 id);
int func_02013D74(u32 key);
u32 sub_02013D9C(u32 id);
u32 sub_02013DB8(u32 id);
int func_02013DD0(int a0);
int func_02013DE0(u16 a0);
u32 sub_02013DF0(u32 id);
u32 sub_02013E04(u32 id);
u32 sub_02013E40(u32 id);
u32 sub_02013E4C(u32 id);
u32 sub_02013E6C(u32 id);
u32 sub_02013E7C(u32 id);
u32 func_02013E90(u32 a, u32 b);
u32 sub_02013EC0(u32 id);
u32 sub_02013ECC(u32 id);
u8 sub_02013ED8(u32 id);
u32 sub_02013EEC(u32 id);
u32 sub_02013F2C(u32 id);
u32 sub_02013F6C(u32 id);
int func_02013FA8(u16 key);
u8 sub_02013FD8(u32 id);
u32 sub_02013FEC(u32 id);
u32 sub_02013FFC(u32 id);
u32 sub_0201400C(u32 id);
u32 sub_02014018(u32 id);
u32 sub_02014024(u32 id);
u32 sub_02014034(u32 id);
u32 sub_02014044(u32 id);
u8 sub_0201405C(u32 id);
u32 sub_02014068(u32 id);
void *sub_0201407C(u32 heap, u16 index, u32 delta);
u32 sub_020140B4(void *a);
u16 sub_020140BC(struct Sub020140BCObj *p);
u32 sub_020140C0(struct Sub020140BCObj *p);
u32 sub_020140CC(struct Sub020140BCObj *p);
u8 sub_020140D8(struct Sub020140BCObj *p);
u8 sub_020140DC(struct Sub020140BCObj *p);
u8 sub_020140E0(struct Sub020140BCObj *p);
u8 sub_020140E4(struct Sub020140BCObj *p);
u32 sub_020140E8(u32 x);
void func_020140F8(Rect14110 *p);
void func_02014110(Rect14110 *p, u16 a, u16 b, u16 c, u16 d, u32 e, u32 f, u32 g);
void func_02014134(u8 *p, u16 b, int c, u16 d, u16 e, u16 f, u16 g, s16_02014134 h);
void func_0201416C(Rect14110 *p, u16 a, u16 b, u16 c);
void func_02014184(Rec1C *r, u16 id, s16_02014134 count, u32 a, u32 b, u32 c);
void func_020141A8(struct t_020139B0 *p, int b, int d, u16 g, u16 i, s16_020141A8 h);
int func_020141DC(const Rec020141DC *p);
void func_020141E0(const Rec020141E0 *p, Vec020141E0 *out);
void func_020141F0(Rec020141F0 *p, const Vec020141F0 *v);
void func_02014204(struct t_020141E0 *p, int id);
void sub_02014264(void *p);
u32 sub_02014274(u32 idx);
u32 sub_020142A4(u32 idx);
u32 sub_020142D0(void);
u32 sub_020142D8(u32 a);
u32 func_020142E8(void *bitmap, s32 id);
void func_02014314(char *a0, int a1);
void func_0201433C(char *a0, int a1);
void func_02014368(char *a0, int a1, int a2);
char *func_02014388(char *a0, u32 a1);
u32 sub_020143CC(u32 a, u32 b);
void sub_020143D8(u32 a, u32 y, u32 z);
void sub_020143F0(u8 *a);
u8 sub_0201440C(u8 *a);
u8 func_0201441C(int i);
void func_02014428(u32 heap);
void sub_02014444(u32 a, u32 b, u32 c);
u32 sub_0201444C(struct Sub02014444Obj *o);
void sub_02014450(struct Sub02014444Obj *o, u32 v);
void sub_02014454(struct Sub02014444Obj *o, u8 v);
u8 sub_02014458(struct Sub02014444Obj *o);
void sub_0201445C(struct Sub02014444Obj *o, u8 v);
u8 sub_02014460(struct Sub02014444Obj *o);
void sub_02014464(struct Sub02014444Obj *o, u8 v);
u8 sub_02014468(struct Sub02014444Obj *o);
void sub_0201446C(struct Sub02014444Obj *o, u16 v);
u16 sub_02014470(struct Sub02014444Obj *o);
void sub_02014474(struct Sub02014444Obj *o, u16 v);
u16 sub_02014478(struct Sub02014444Obj *o);
u8 sub_0201447C(struct Sub02014444Obj *o, u8 v);
u8 sub_02014484(struct Sub02014444Obj *o);
int sub_02014488(void *a0, u32 *a1, u8 *a2);
void *func_020144DC(void *a0, int a1);
int func_0201450C(int a0, int *a1, int *a2);
void *func_02014554(void *a0, int a1);
int func_02014584(int a0, int *a1, int *a2);
void *func_020145CC(void *a0);
void *func_020145FC(void *a0);
u32 func_02014628(void *obj, u32 *mode, u32 *p);
u32 func_02014698(void *obj, u32 *mode, u32 *args);
void *func_020146F8(char *a0, int a1, int a2, int a3, int a4);
void *func_02014728(char *a0, int a1, int a2, int a3, int a4);
int func_02014758(int a0, int *a1, S *a2);
int func_020147B0(int a0, int *a1, S *a2);
void *func_02014808(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
void *func_02014840(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
u32 func_02014878(u32 a0, u32 *mode, u32 *p);
extern struct ZoneDataMgr *g_sub02013AD0Obj;
extern const char sZonedataFile[];
extern u16 sub_020A72A8_Key[];
extern u16 sub_020A72AA_Val[];
extern u8   tbl_0209E010[];
extern struct Ent0209E026 sub_0209E026_Map[];
extern const int d_0209DFC0[];
extern const int d_0209DFEC[];
extern struct Sub02013ED8Obj *g_sub02013AD0Obj2;
extern struct Ent0209DFC8 sub_0209DFC8_Map[];
extern char sub_02146268_Sys[];
extern u8 sub_0209E050_Map[];
extern u8    sBtlSetupFile;
extern u8   ov091_id[];
extern u8   ov131_id[];









/*
 * Blocked on: the `string` class, and permanently.  Every concrete byte of
 * this function is reproduced; the only unresolved relocation is the ABS32 at
 * +0x90 naming "zonedata.c" at 0x020A72B0, and no pool anywhere else in the
 * image holds that word.  The string class cannot rescue it either: the six
 * bytes immediately before 0x020A72B0 are the { u16 key; u16 value }
 * substitution table func_02013A94 reads (0x0000 -> 0x01a8, 0x0126 -> 0x0127),
 * not a preceding string's terminator, so attest_string's condition (5) fails.
 * See docs/idioms/a-string-after-a-data-table-has-no-witness.md.  Nothing in
 * the C can change this; it is evidence-starved, not mistranslated.
 *
 * The constructor of the zone-header subsystem, and the function that names
 * the original source file: it passes "zonedata.c" (0x020A72B0) and line 0x60
 * to the allocator, so the 0x4c byte object it builds at 0x02146264 is the
 * ZoneData manager, and every accessor built on sub_02013AD0 reads through it.
 *
 * Three things this function pins down about the on-disk zone data.
 *
 * +0x00 is a persistent archive handle opened by func_020490F4(0x0c, heap).
 * func_02048DDC, which func_020490F4 calls to bind the handle, indexes a 235
 * entry char* table at 0x020A6C58 (installed by func_02048CEC from
 * 0x020055FA with count 0xeb) by that same id, and entry 0x0c of that table
 * is the string "a/0/1/2".  sub_02013AD0 then reads records out of that
 * handle at 0x30 * id for 0x30 bytes, so the zone header table is sub-file 0
 * of a/0/1/2 with a 48-byte stride.
 *
 * +0x34 is seeded with 0x1ab = 427 before any record is cached.  a/0/1/2's
 * only sub-file is 20496 bytes, exactly 427 * 48, so 427 is one past the last
 * zone id and the seed is a deliberate never-matches cache tag rather than a
 * real id.  That count is content, not code, and is the kind of constant that
 * may differ in White; nothing here reads a version identifier.
 *
 * The three func_0204A298 calls each load a whole sub-file into the heap and
 * write back its byte size through the fifth argument: (0x51, 13) is
 * a/0/8/1 sub-file 13, (0x52, 1) is a/0/8/2 sub-file 1 and (0x95, 0) is
 * a/1/4/9 sub-file 0, by the same id-to-name table as above.  Each size is
 * divided by four into a companion count field (+0x40 u16, +0x42 u8,
 * +0x43 u8), and func_02013EEC, func_02013F2C and func_02013F6C walk the
 * matching pointer as an array of 4-byte { u16 key; u16 value } entries, so
 * all three are (zone id -> value) side tables, not part of the record.
 *
 * Two locals, not one: the first two sizes land in the local at sp+8 and the
 * third in a separate local at sp+4.  Declaration order is stack order, so
 * the twice-used local has to be declared first.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020139B0.c \
 *       --func func_020139B0 --addr 0x020139B0 --cc 1.1p1 --thumb
 */
void func_020139B0(u32 heap)
{
    u32 size;
    u32 size2;

    if (g_sub02013AD0Obj != 0)
        return;

    g_sub02013AD0Obj = func_02030734(heap, 0x4c, 1, sZonedataFile, 0x60);
    g_sub02013AD0Obj->archive = func_020490F4(0x0c, heap);

    g_sub02013AD0Obj->table38 = (void *)func_0204A298(0x51, 13, 0, heap, &size);
    g_sub02013AD0Obj->count40 = size >> 2;

    g_sub02013AD0Obj->table3c = (void *)func_0204A298(0x52, 1, 0, heap, &size);
    g_sub02013AD0Obj->count42 = size >> 2;

    g_sub02013AD0Obj->table44 = (void *)func_0204A298(0x95, 0, 0, heap, &size2);
    g_sub02013AD0Obj->count43 = size2 >> 2;

    g_sub02013AD0Obj->cached_id = 0x1ab;
}









/*
 * A whole translation-unit range, matched as one byte range.
 *
 * 0x02013A80 is an unlabelled follower: it saves no lr, so disasm.py prints it
 * as the tail of func_02013A48 instead of as a function of its own, and
 * func_02013A48 alone verifies EXACT* for that reason.  Taking the two as one
 * 76-byte unit closes the star; seed 0x02013A80 into
 * layout/function_starts.txt anyway.
 *
 * The destructor of the zone-header subsystem allocated by func_020139B0, and
 * a second, independent reading of the manager's field map: it frees +0x44,
 * +0x3c and +0x38 with the plain heap free func_020307B0, which is what makes
 * those three heap buffers rather than pointers into the image, and closes
 * +0x00 with func_02049238 (archive close plus free), which is what makes
 * +0x00 an archive handle and not a fourth buffer.  The manager itself is
 * freed last and the global cleared.
 *
 * Release order is the reverse of the order func_020139B0 fills the fields
 * in, so the two functions together fix the field order as well as the types.
 *
 * The global is reloaded before every call because it is an ordinary extern,
 * not a same-file static: each `ldr r0, [r4]` in the original is a fresh read
 * of 0x02146264, and writing the frees through the global directly (rather
 * than caching it in a local) is what reproduces them.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013A48.c \
 *       --func func_02013A48 --addr 0x02013A48 --cc 1.1p1 --thumb
 */
void func_02013A48(void)
{
    if (g_sub02013AD0Obj == 0)
        return;

    func_020307B0(g_sub02013AD0Obj->table44);
    func_020307B0(g_sub02013AD0Obj->table3c);
    func_020307B0(g_sub02013AD0Obj->table38);
    func_02049238(g_sub02013AD0Obj->archive);
    func_020307B0(g_sub02013AD0Obj);
    g_sub02013AD0Obj = 0;
}









void sub_02013A80(u32 index, u8 on)
{
    if (g_sub02013AD0Obj != 0)
        g_sub02013AD0Obj->subst_on[index] = on;
}









u16 func_02013A94(u32 key)
{
    int i;
    char *p = *(char **)0x02146264;

    for (i = 0; i < 2; i++) {
        if (*(u8 *)(p + 0x48 + i) != 0 && key == sub_020A72A8_Key[i * 2])
            return sub_020A72AA_Val[i * 2];
    }
}










/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02013B50, sub_02013B5C, sub_02013B68, sub_02013B74,
 *           sub_02013B90
 *
 * alias: the record-cache accessor every function in unit_02013BA8.c,
 * unit_02013C10.c, unit_02013CC8.c, unit_02013D9C.c, unit_02013DF0.c and
 * unit_02013EC0.c is built on, plus the leaf accessors those files' own
 * declarations of sub_02013B10 and sub_02013B44 point at.
 *
 * sub_02013A94, the id remapper this file calls, is immediately before it
 * and is a documented near miss (see below); it is only reached here as an
 * ordinary extern call, which does not need its body to be attested, only
 * the call to it.
 *
 * g_sub02013AD0Obj is a single cached object (call it P): P+0x00 is the
 * handle sub_0204944C reads records from, P+0x04..0x33 (0x30 bytes) is the
 * cached record every accessor in the other files of this run reads
 * through the pointer sub_02013AD0() returns, and P+0x34 is the id that
 * record was cached for.  sub_02013AD0 reloads the record through
 * sub_0204944C only when the requested id (after remapping through
 * sub_02013A94) does not match the cached one.
 *
 * sub_02013B74 and sub_02013B90 read the same three fields (+0x24, +0x28,
 * +0x2c); sub_02013B74 additionally shifts each left 16 bits, which is an
 * integer-to-Fx32 conversion (multiply by 0x10000) rather than a
 * truncation, since the source field is the full 32-bit word both
 * functions load.
 *
 * Near miss: sub_02013A94 (0x02013A94 to 0x02013AD0, 60 bytes) reproduces
 * every concrete byte but caps at MATCH.  It reads a two-entry { from; to }
 * substitution table at 0x020A72A8; the only other two words in the image
 * that hold that address are themselves data (an unrelated 0x01A80000 in
 * two overlay listings, not a reference to it), so the table has no
 * attestable witness anywhere outside this one function's own pool.  It is
 * not in this file.  What looks like a small version- or form-exclusive id
 * substitution, gated per entry by a two-byte flag array on the same
 * cached object this file's sub_02013AD0 maintains, is worth flagging as
 * possibly version-specific, though nothing at this address range says
 * which meaning it carries.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013AD0.c \
 *       --addr 0x02013AD0 --thumb
 */
void *sub_02013AD0(u32 id)
{
    u32 rid;

    if (g_sub02013AD0Obj == 0)
        return 0;

    rid = sub_02013A94(id);
    if (rid == g_sub02013AD0Obj->cached_id)
        return &g_sub02013AD0Obj->record;

    sub_0204944C(g_sub02013AD0Obj->archive, 0, rid * 0x30, 0x30,
                 &g_sub02013AD0Obj->record);
    g_sub02013AD0Obj->cached_id = rid;
    return &g_sub02013AD0Obj->record;
}










u32 sub_02013B10(u32 id, const u16 *table, s32_02013AD0 count)
{
    u32 rid = sub_02013A94(id);
    s32_02013AD0 i;

    for (i = 0; i < count; i++) {
        if (rid == table[i])
            return 1;
    }
    return 0;
}










u32 sub_02013B38(u32 id)
{
    struct Sub02013AD0Rec_02013AD0 *r = sub_02013AD0(id);
    return r->unk02;
}










u32 sub_02013B44(u32 id)
{
    struct Sub02013AD0Rec_02013AD0 *r = sub_02013AD0(id);
    return r->unk04;
}










u32 sub_02013B50(u32 id)
{
    struct Sub02013AD0Rec_02013AD0 *r = sub_02013AD0(id);
    return r->unk00;
}










u32 sub_02013B5C(u32 id)
{
    struct Sub02013AD0Rec_02013AD0 *r = sub_02013AD0(id);
    return r->unk06;
}










u32 sub_02013B68(u32 id)
{
    struct Sub02013AD0Rec_02013AD0 *r = sub_02013AD0(id);
    return r->unk0a;
}










void sub_02013B74(u32 id, u32 *out)
{
    struct Sub02013AD0Rec_02013AD0 *r = sub_02013AD0(id);

    out[0] = r->unk24 << 0x10;
    out[1] = r->unk28 << 0x10;
    out[2] = r->unk2c << 0x10;
}










void sub_02013B90(u32 id, u32 *out)
{
    struct Sub02013AD0Rec_02013AD0 *r = sub_02013AD0(id);

    out[0] = r->unk24;
    out[1] = r->unk28;
    out[2] = r->unk2c;
}










/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: three bitfield accessors on the record sub_02013AD0() returns for a
 * given id.  The halfword at +0x1c of that record is split into three
 * bitfields with no gap: bits[0:5] (6 bits, read by the neighbouring
 * sub_02013C10, not in this file), bits[6:8] (3 bits, sub_02013BA8) and
 * bits[9:15] (7 bits, sub_02013BBC).  sub_02013BD0 reads the separate plain
 * halfword at +0x20.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013BA8.c \
 *       --addr 0x02013BA8 --thumb
 */
u8 sub_02013BA8(u32 id)
{
    struct Sub02013AD0Rec_02013BA8 *r = sub_02013AD0(id);
    return r->unk1c.mid3;
}










u8 sub_02013BBC(u32 id)
{
    struct Sub02013AD0Rec_02013BA8 *r = sub_02013AD0(id);
    return r->unk1c.hi7;
}










u32 sub_02013BD0(u32 id)
{
    struct Sub02013AD0Rec_02013BA8 *r = sub_02013AD0(id);
    return r->unk20;
}










/*
 * The only indexed accessor on the zone record: four u16 lanes at record
 * +0x0c, +0x0e, +0x10 and +0x12 selected by a second argument bounded to
 * 0..3, with 0 returned for anything else.  That is what makes those eight
 * bytes one array of four rather than four unrelated fields, and it is the
 * only place in the subsystem where a record field is read by index.
 *
 * The dispatch is the dense PC-relative halfword table
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md): the four
 * displacements in the table at 0x02013BF8 are exactly the four `ldrh r4`
 * encodings, so all four case labels existed and none of them is empty.
 *
 * The zero default is initialised before the call to sub_02013AD0, not in a
 * default arm: `movs r4, #0` sits at +0x04, ahead of the `bl`, which is what
 * lets every arm share one `adds r0, r4, #0` exit instead of carrying its own
 * return (docs/idioms/initialise-the-result-before-the-input-or-every-arm-
 * duplicates-the-return.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013BDC.c \
 *       --func func_02013BDC --addr 0x02013BDC --cc 1.1p1 --thumb
 */
u32 func_02013BDC(u32 id, u32 which)
{
    u16 v = 0;
    struct ZoneRec *r = sub_02013AD0(id);

    switch (which) {
    case 0:
        v = r->conn0c;
        break;
    case 1:
        v = r->conn0e;
        break;
    case 2:
        v = r->conn10;
        break;
    case 3:
        v = r->conn12;
        break;
    }
    return v;
}










/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02013C50, sub_02013C60
 *
 * alias: continues the run of leaf accessors on the record sub_02013AD0()
 * returns for a given id.  sub_02013BDC, the dense-switch dispatcher
 * immediately before this range, is a documented near miss and is not in
 * this file; see its header note for why.
 *
 * The record's halfword at +0x1c holds the same three-way bitfield as
 * unit_02013BA8.c (bits[0:5] here, bits[6:8] and bits[9:15] there);
 * sub_02013C10 is the low six bits and needs no narrowing return, unlike its
 * two neighbours there, which return u8 and pick up an extra truncation pair
 * for it.  The halfword at +0x1e is five single-bit flags at bits 10, 12,
 * 13, 14 and 15 (bit 11 has no accessor in this range).
 *
 * Near miss: sub_02013C70, sub_02013C80 and sub_02013C9C (0x02013C70 to
 * 0x02013CC8, 88 bytes) reproduce every concrete byte but cap at MATCH.
 * sub_02013C70 tail calls sub_02013B10 (defined in the neighbouring packet)
 * through a pool word, and also holds a pointer to sub_02013C70_Table
 * (0x0209E010); sub_02013C9C searches sub_02013C9C_Table (0x0209E026).  All
 * three addresses are named in the image only inside this same 88-byte
 * range: the other five images of the sub_02013B10 pointer are themselves
 * unlabelled leaf thunks (data words, not literal pools, in the same
 * function's neighbourhood further down this file), sub_02013C9C's only
 * caller anywhere is sub_02013C80 one function above it, and neither table
 * is referenced from anywhere else at all.  No cut of this file moves any
 * of those three witnesses outside the range that needs them, so this is
 * the "only caller in the ROM" case from docs/MATCHING.md rather than
 * anything a rewrite of the C would fix.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013C10.c \
 *       --addr 0x02013C10 --thumb
 */
u32 sub_02013C10(u32 id)
{
    struct Sub02013AD0Rec_02013C10 *r = sub_02013AD0(id);
    return r->unk1c.lo6;
}










u32 sub_02013C20(u32 id)
{
    struct Sub02013AD0Rec_02013C10 *r = sub_02013AD0(id);
    return r->unk1e.flag10;
}










u32 sub_02013C30(u32 id)
{
    struct Sub02013AD0Rec_02013C10 *r = sub_02013AD0(id);
    return r->unk1e.flag14;
}










u32 sub_02013C40(u32 id)
{
    struct Sub02013AD0Rec_02013C10 *r = sub_02013AD0(id);
    return r->unk1e.flag13;
}










u32 sub_02013C50(u32 id)
{
    struct Sub02013AD0Rec_02013C10 *r = sub_02013AD0(id);
    return r->unk1e.flag12;
}










u32 sub_02013C60(u32 id)
{
    struct Sub02013AD0Rec_02013C10 *r = sub_02013AD0(id);
    return r->unk1e.flag15;
}










/*
 *           pool word inside this eight-byte range, so the `literal`
 *           class has no outside witness and no cut moves one there.
 *           Same finding as src/matched/unit_02013C10.c's header.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02013C70.c \
 *       --func func_02013C70 --addr 0x02013C70 --cc 1.1p1 --thumb
 */
int func_02013C70(u32 a)
{
    return func_02013B10(a, (const u16 *)tbl_0209E010, 0xb);
}









int func_02013C80(int a0)
{
    if ((unsigned int)func_02013C9C(func_02013A94(a0)) != (unsigned int)(~0)) {
        return 1;
    } else {
        return 0;
    }
}











int func_02013C9C(u16 key)
{
    u32 r = func_02013A94(key);
    u32 i;

    for (i = 0; i < 0x14; i++) {
        if (r == sub_0209E026_Map[i].code)
            return sub_0209E026_Map[i].kind;
    }
    return -1;
}











/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02013D34, sub_02013D5C
 *
 * alias: a run of id-classification predicates on the remapped id
 * sub_02013A94() returns, plus sub_02013D34, which is a plain disjunction
 * of three of them.  sub_02013C70/C80/C9C, immediately before this file,
 * and sub_02013D74, immediately after it, are documented near misses and
 * are not in this file; see unit_02013C10.c and unit_02013D9C.c.
 *
 * sub_02013CE0 and sub_02013D00 reject an id outside a two-value window by
 * adding a POOL CONSTANT rather than subtracting an immediate (0xff6a /
 * 0xffb5, i.e. +65386 / +65461, not -0x96 / -0x4b): those values do not fit
 * an 8-bit immediate as spelled, and mwccarm never folds the arithmetic
 * back down to a subs regardless of how the literal is written in C, so the
 * pool word is what has to be reproduced, not a stylistic choice.
 *
 * sub_02013D34 is a genuine `||` of sub_02013CC8, sub_02013CE0 and
 * sub_02013D20 (single conjunction/disjunction sharing one exit block),
 * confirmed by trying it first as three separate `if (x) return 1;`
 * statements: that phrasing gives each early return its own copy of the
 * epilogue and comes out with the wrong branch polarity on the last check,
 * because at that point every one of the three callees becomes a real
 * `label`-attested extern (this file is the second caller each of them
 * needed) rather than a `local` call, and the codegen the docs describe
 * for a single boolean expression is what the original bytes show.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013CC8.c \
 *       --addr 0x02013CC8 --thumb
 */
u32 sub_02013CC8(u32 id)
{
    return sub_02013A94(id) == 0x1a6;
}











u32 sub_02013CE0(u32 id)
{
    return (u16)(sub_02013A94(id) + 0xff6a) <= 1;
}











u32 sub_02013D00(u32 id)
{
    return (u16)(sub_02013A94(id) + 0xffb5) <= 1;
}











u32 sub_02013D20(u32 id)
{
    return sub_02013A94(id) == 0x34;
}











u32 sub_02013D34(u32 id)
{
    return sub_02013CC8(id) || sub_02013CE0(id) || sub_02013D20(id);
}











u32 sub_02013D5C(u32 id)
{
    return sub_02013A94(id) == 0x117;
}











/*
 * zonedata.c: true when the zone id is in 0x121..0x13C or func_02013D9C
 * accepts it.  The image shares one `movs r0, #1` exit between the range
 * test and the callee test, which only one disjunction gives
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md).
 */
int func_02013D74(u32 key)
{
    u32 v = func_02013A94(key);

    if ((v >= 0x121 && v <= 0x13c) || func_02013D9C(v) == 1)
        return 1;
    return 0;
}











/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: the id-classification predicate started in unit_02013CC8.c, plus
 * one unlabelled leaf immediately after it, read out of the bytes the same
 * way as the ones in unit_0200E884.c: sub_02013DB8 saves no registers and
 * calls nothing, so disasm.py never gave it a label.  It is the same range
 * check as sub_02013D74 (a documented near miss two functions before this
 * one) but on the RAW id, with no call to sub_02013A94 at all, which is
 * exactly what its lack of a stack frame says.
 *
 * Near miss: 0x02013DD0 to 0x02013DF0 (32 bytes, two more unlabelled leaves)
 * immediately follows and is not in this file.  Both tail call
 * sub_02013B10 (defined in the neighbouring packet) through a pool word
 * over a different fixed table (0x0209DFC0 count 4, 0x0209DFEC count 9),
 * the same shape as sub_02013C70 in unit_02013C10.c, and for the same
 * reason: every other place either pointer or table address appears in the
 * image is itself one of these unlabelled thunks rather than a literal pool
 * or a direct call, so neither has an attestable witness outside its own
 * bytes.  sub_02013DF0 onward resumes in unit_02013DF0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013D9C.c \
 *       --addr 0x02013D9C --thumb
 */
u32 sub_02013D9C(u32 id)
{
    u32 v = sub_02013A94(id);

    return v >= 0x118 && v <= 0x120;
}











u32 sub_02013DB8(u32 id)
{
    return id >= 0x121 && id <= 0x13c;
}











/*
 * Unlabelled Thumb leaf inside func_02013D9C's listing extent: a tail call
 * to func_02013B10 with a fixed table and count. Filed as the witness for
 * the ov021 and ov018 callers.
 */
int func_02013DD0(int a0)
{
    return func_02013B10(a0, (const u16 *)d_0209DFC0, 4);
}











/*
 * Unlabelled Thumb leaf after func_02013DD0: a tail call
 * to func_02013B10 with a fixed table and count. Filed as the witness for
 * the ov020 caller func_021862A8 (wave D4 lane 12).
 */
int func_02013DE0(u16 a0)
{
    return func_02013B10(a0, (const u16 *)d_0209DFEC, 9);
}










/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02013E6C, sub_02013E7C
 *
 * alias: the last id predicate, sub_02013E04, and three more leaf accessors
 * on the record sub_02013AD0() returns.  sub_02013D74 (a documented near
 * miss, see unit_02013C10.c) is only reached here as an ordinary extern
 * call from sub_02013E04, which does not need sub_02013D74's own body to
 * be attested, only the call to it.
 *
 * sub_02013E04 returns true only when NONE of five predicates
 * (sub_02013CC8, sub_02013CE0, sub_02013D00, sub_02013D5C, sub_02013D74)
 * match, written as the direct disjunction `if (a || b || c || d || e)
 * return 0; return 1;`.  Splitting the disjunction into two `if`s, or
 * writing the same thing as `if (x) return 0;` five times, both changed
 * which comparisons share the shared-exit block with which: this compiler
 * only tail-merges an early `return 0;` across every operand of one `||`
 * expression, and only the last operand gets different codegen (its
 * comparison result stands for the whole expression rather than branching
 * past a shared block), so the five calls have to be one source-level
 * disjunction to reproduce the original's four-shared/one-different shape.
 *
 * The record's halfword at +0x1a is a ten-bit low field and a six-bit high
 * field, the same two-way split as the +0x1c and +0x1e halfwords documented
 * in unit_02013C10.c and unit_02013BA8.c.  sub_02013E4C reads the low field
 * and then substitutes 0x70 for either of the two values immediately above
 * it (0x70 and 0x71): the substitution test adds the POOL CONSTANT 0xff90
 * (-0x70 as an unsigned 16-bit value) rather than subtracting the immediate
 * 0x70, the same non-foldable-immediate shape documented in
 * unit_02013CC8.c for sub_02013CE0 and sub_02013D00.
 *
 * Near miss: sub_02013E90 (0x02013E90 to 0x02013EC0, 48 bytes) reproduces
 * every concrete byte of its first half (the va==vb case) but the two
 * remaining special cases (0 and 0xaf treated as equivalent to each other)
 * compile to a different shared-exit shape than the original under every
 * phrasing tried: two plain `&&` conjunctions, one written as a nested
 * `if`, and both orders of the pair.  It is not in this file; see
 * unit_02013EC0.c for what resumes after it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013DF0.c \
 *       --addr 0x02013DF0 --thumb
 */
u32 sub_02013DF0(u32 id)
{
    return sub_02013A94(id) == 0x4e;
}










u32 sub_02013E04(u32 id)
{
    if (sub_02013CC8(id) || sub_02013CE0(id) || sub_02013D00(id) ||
        sub_02013D5C(id) || sub_02013D74(id))
        return 0;
    return 1;
}










u32 sub_02013E40(u32 id)
{
    struct Sub02013AD0Rec_02013DF0 *r = sub_02013AD0(id);
    return r->unk18;
}










u32 sub_02013E4C(u32 id)
{
    struct Sub02013AD0Rec_02013DF0 *r = sub_02013AD0(id);
    u32 v = r->unk1a.lo10;

    if ((u16)(v + 0xff90) <= 1)
        v = 0x70;
    return v;
}










u32 sub_02013E6C(u32 id)
{
    struct Sub02013AD0Rec_02013DF0 *r = sub_02013AD0(id);
    return r->unk1a.hi6;
}










u32 sub_02013E7C(u32 id)
{
    struct Sub02013AD0Rec_02013DF0 *r = sub_02013AD0(id);
    return r->unk04 == 0;
}










/*
 * "Do these two zones share a region?": both ids are reduced through
 * func_02013B44, the accessor for record +0x04, and the two results compared.
 * The +0x04 lane is therefore a grouping key rather than a per-zone index,
 * which agrees with the data: 238 distinct values over 427 records.
 *
 * On top of plain equality, 0 and 0xaf are treated as the same group in either
 * order.  That is a hard-coded pair of content constants, not a computed one,
 * and is exactly the kind of value that may differ in White; nothing here
 * reads a version identifier.
 *
 * The equality test is one `if` with its own return, and the special case is a
 * single disjunction afterwards: writing the special case as two separate
 * `if`s gives each its own epilogue instead of the shared one the original
 * has (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013E90.c \
 *       --func func_02013E90 --addr 0x02013E90 --cc 1.1p1 --thumb
 */
u32 func_02013E90(u32 a, u32 b)
{
    u32 ga = func_02013B44(a);
    u32 gb = func_02013B44(b);

    if (ga == gb)
        return 1;
    if ((ga == 0 && gb == 0xaf) || (ga == 0xaf && gb == 0))
        return 1;
    return 0;
}










/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: the last two leaf accessors on the record sub_02013AD0() returns,
 * and the end of pkt_02013BA8.  sub_02013E90, immediately before this
 * file, is a documented near miss; see unit_02013DF0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013EC0.c \
 *       --addr 0x02013EC0 --thumb
 */
u32 sub_02013EC0(u32 id)
{
    struct Sub02013AD0Rec_02013EC0 *r = sub_02013AD0(id);
    return r->unk14;
}










u32 sub_02013ECC(u32 id)
{
    struct Sub02013AD0Rec_02013EC0 *r = sub_02013AD0(id);
    return r->unk16;
}










/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: continues the record-cache family of unit_02013AD0.c and
 * unit_02013BA8.c: every accessor here that calls sub_02013AD0() reads
 * through the same cached record, at offsets not used by those two files.
 * g_sub02013AD0Obj2 is the same cache object (0x02146264) as
 * unit_02013AD0.c's g_sub02013AD0Obj, redeclared here with only the extra
 * fields (0x38..0x43, two of its three small lookup tables and their
 * counts) this file touches; nothing about the two declarations needs to
 * agree byte for byte, only the addresses they claim.
 *
 * The halfword at the cached record's offset 0x1e holds two adjacent 5 bit
 * fields with no gap (bits[0:4] and bits[5:9]); sub_02013ED8 is the
 * accessor for the high one (unit_02014034.c has the low one).
 * sub_02013EEC/F2C/F6C are three independent { key(u16); val(u16) } lookup
 * tables reached through the cache object, differing only in the width of
 * their count field and in their not-found sentinel (0x0FFFFFFF for the
 * first two, 0 for the third).  The third table's array pointer and count
 * sit at offsets 0x44/0x43, immediately after this file's range in the
 * struct, and are declared again in unit_02014034.c.
 *
 * Near miss: sub_02013FA8 (0x02013FA8..0x02013FD8, 48 bytes), a five entry
 * table lookup unrelated to the cache object, reproduces every concrete
 * byte and caps at MATCH: the only pool word anywhere in the image that
 * names its table address is its own, so the honesty rule refuses the
 * witness.  Parked at src/pending/sub_02013FA8.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013ED8.c \
 *       --addr 0x02013ED8 --thumb
 */
u8 sub_02013ED8(u32 id)
{
    struct Sub02013AD0Rec_02013ED8 *r = sub_02013AD0(id);
    return r->mid5;
}










u32 sub_02013EEC(u32 id)
{
    u32 result = 0x0FFFFFFFu;
    u32 rid;
    s32_02013DF0 i;

    rid = sub_02013A94(id);
    for (i = 0; i < g_sub02013AD0Obj2->count1; i++) {
        if (rid == g_sub02013AD0Obj2->arr1[i].key) {
            result = g_sub02013AD0Obj2->arr1[i].val;
            break;
        }
    }
    return result;
}










u32 sub_02013F2C(u32 id)
{
    u32 result = 0x0FFFFFFFu;
    u32 rid;
    s32_02013DF0 i;

    rid = sub_02013A94(id);
    for (i = 0; i < g_sub02013AD0Obj2->count2; i++) {
        if (rid == g_sub02013AD0Obj2->arr2[i].key) {
            result = g_sub02013AD0Obj2->arr2[i].val;
            break;
        }
    }
    return result;
}










u32 sub_02013F6C(u32 id)
{
    u32 result = 0;
    u32 rid;
    s32_02013DF0 i;

    rid = sub_02013A94(id);
    for (i = 0; i < g_sub02013AD0Obj2->count3; i++) {
        if (rid == g_sub02013AD0Obj2->arr3[i].key) {
            result = g_sub02013AD0Obj2->arr3[i].val;
            break;
        }
    }
    return result;
}










int func_02013FA8(u16 key)
{
    u32 v = func_02013A94(key);
    u32 i;

    for (i = 0; i < 5; i++) {
        if (v == sub_0209DFC8_Map[i].code)
            return sub_0209DFC8_Map[i].kind;
    }
    return 0xffff;
}










/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02014018, sub_02014024, sub_02014034, sub_02014044,
 *           sub_0201405C, sub_02014068
 *
 * alias: sub_02013FD8 is the low 5 bit accessor of the cache record's
 * offset 0x1e halfword (unit_02013ED8.c has the high one).
 *
 * sub_02013FEC, sub_02013FFC and sub_02014024 are plain tail calls to
 * sub_02013B10 (unit_02013AD0.c) against three small { key; value } tables
 * of their own (0x0209DFDC/8, 0x0209DFB8/4, 0x0209DFD2/5); mwccarm emits a
 * tail call as a pool word and `bx` even to a function outside the unit
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), so each is a function
 * with no prologue, invisible to disasm.py's prologue sweep and printed
 * inside the extent of the labelled accessor at 0x02013FD8.  The pool
 * words that hold sub_02013B10's own address are wildcarded (`literal`
 * class, attested by the same address in unit_02013AD0.c's callers); the
 * table addresses themselves need no attestation, since they are ordinary
 * immediate constants passed by value, not relocated pointers into this
 * range.
 *
 * sub_02014034 and sub_02014044 are plain range/equality tests on the raw
 * id (no call to sub_02013AD0).  sub_0201405C is another cache-record
 * accessor, the byte at offset 0x01.  sub_02014068 forwards to the
 * existing sub_02013E40 (unit_02013DF0.c region), an accessor on the same
 * cache record's offset 0x18.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013FD8.c \
 *       --addr 0x02013FD8 --thumb
 */
u8 sub_02013FD8(u32 id)
{
    struct { u8 pad[0x1e]; u16 lo5 : 5; u16 mid5 : 5; u16 hi6 : 6; } *r =
        sub_02013AD0(id);
    return r->lo5;
}










u32 sub_02013FEC(u32 id)
{
    return sub_02013B10(id, (const u16 *)0x0209DFDC, 8);
}










u32 sub_02013FFC(u32 id)
{
    return sub_02013B10(id, (const u16 *)0x0209DFB8, 4);
}










u32 sub_0201400C(u32 id)
{
    return id == 0xF6;
}










u32 sub_02014018(u32 id)
{
    return id == 0xF7;
}










u32 sub_02014024(u32 id)
{
    return sub_02013B10(id, (const u16 *)0x0209DFD2, 5);
}










u32 sub_02014034(u32 id)
{
    return id >= 0x4C && id <= 0x69;
}










u32 sub_02014044(u32 id)
{
    return id == 0x17A || id == 0x176;
}










u8 sub_0201405C(u32 id)
{
    struct { u8 unk00; u8 unk01; } *r = sub_02013AD0(id);
    return r->unk01;
}










u32 sub_02014068(u32 id)
{
    return sub_02013E40(id) == 0xD6;
}










/*
 * The reader for the raw file a/0/1/3 (archive id 13, the identity-mapped
 * name table entry at 0x020A6C58[13]).  a/0/1/3 is not a NARC: it is a flat
 * 2820-byte file of 282 fixed 10-byte records, so this function does not go
 * through the arc_tool.c member API at all.  It calls func_02020E08, the
 * by-id raw byte-range read (open the whole file by its name-table path,
 * then read `size` bytes at `offset`), with offset = index * 10 and size = 10.
 *
 * Two facts about the domain fall straight out of the code:
 *
 *   - the clamp constant in the pool at 0x020140B0 is 0x11A = 282, exactly
 *     the record count of a/0/1/3, so `index` is a record index;
 *   - sub_020140E8 (already EXACT, src/matched/sub_020140E8.c) answers
 *     "2 <= index < 0xD2", and only for that window is `delta` added.  The
 *     window is 208 records wide, a multiple of four, and the callers pass
 *     the season for `delta`: the file's records 2..209 are four seasonal
 *     variants of 52 base entries and records 210..281 have none.
 *
 * The record index itself comes from the zone table: ov021's fieldmap.c
 * and ov020's event_mapchange.c both call this as
 * sub_0201407C(heap, sub_02013B38(zone_id), season), and sub_02013B38
 * (EXACT in src/matched/unit_02013AD0.c) returns the u16 at +2 of the
 * a/0/1/2 zone record.  That field ranges 2..273 over all 427 zones, i.e.
 * it stays inside this function's 282-record clamp.  See the "Archive
 * readers traced by call graph" section of docs/ASSETS.md.
 *
 * The narrowing to u16 is real, not an artefact: `index + delta` is
 * truncated before the clamp, so a caller passing 0xFFFF for delta walks
 * the index backwards rather than off the end of the file.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201407C.c \
 *       --func sub_0201407C --addr 0x0201407C --cc 1.1p1 --thumb
 */
void *sub_0201407C(u32 heap, u16 index, u32 delta)
{
    u16 record = index;

    if (sub_020140E8(index) != 0) {
        record = (u16)(index + (u16)delta);
    }
    if (record >= 282) {
        record = 0;
    }
    return func_02020E08(13, heap, record * 10, 10);
}









/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_020140D8, sub_020140DC, sub_020140E0, sub_020140E4
 *
 * alias: sub_020140B4 is a bare tail call to the ARM function
 * sub_020307B0: the compiler cannot tell caller and callee interwork, so
 * it always spends a pool word and `bx` rather than ever emitting a direct
 * branch (docs/idioms/tail-call-is-a-pool-word-and-bx.md), even though the
 * wrapper's own body is otherwise empty.
 *
 * sub_020140BC through sub_020140E4 are seven more leaf accessors on a
 * small object passed in directly (not through sub_02013AD0()), hiding in
 * the same way: none of the seven save `lr`, so disasm.py's prologue sweep
 * never labels them and they print as a run of `.word`s between two
 * literal pools (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * Two of them (offsets 0x04 and 0x05) return the sentinel 0xFFFFFFFF in
 * place of a stored byte value of 0xFF, rather than the plain
 * zero-extended byte every other accessor here returns.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020140B4.c \
 *       --addr 0x020140B4 --thumb
 */
u32 sub_020140B4(void *a)
{
    return sub_020307B0(a);
}









u16 sub_020140BC(struct Sub020140BCObj *p)
{
    return p->f02;
}








u32 sub_020140C0(struct Sub020140BCObj *p)
{
    if (p->f04 == 0xFF)
        return (u32)-1;
    return p->f04;
}








u32 sub_020140CC(struct Sub020140BCObj *p)
{
    if (p->f05 == 0xFF)
        return (u32)-1;
    return p->f05;
}








u8 sub_020140D8(struct Sub020140BCObj *p)
{
    return p->f06;
}








u8 sub_020140DC(struct Sub020140BCObj *p)
{
    return p->f07;
}








u8 sub_020140E0(struct Sub020140BCObj *p)
{
    return p->f08;
}








u8 sub_020140E4(struct Sub020140BCObj *p)
{
    return p->f09;
}









/*
 * A plain range test on the raw id, called by sub_0201407C
 * (unit_02013ED8.c is a sibling file, not this one; the call there is
 * attested by this function's own definition living outside its range).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020140E8.c \
 *       --func sub_020140E8 --addr 0x020140E8 --cc 1.1p1 --thumb
 */
u32 sub_020140E8(u32 x)
{
    return x >= 2 && x < 0xD2;
}









void func_020140F8(Rect14110 *p)
{
    p->x00 = 0;
    p->x04 = 0;
    p->x06 = 0;
    p->x08 = 0;
    p->x0A = 0;
    p->x0C = 0;
    p->x10 = 0;
    p->x14 = 0;
    p->x18 = 0;
}








/*
 * Initialiser: clears +0x00 and +0x0C, stores four halfwords at +0x04..+0x0A
 * and three words at +0x10..+0x18.
 *
 * Addresses are Black-image addresses.
 */
void func_02014110(Rect14110 *p, u16 a, u16 b, u16 c, u16 d, u32 e, u32 f, u32 g)
{
    p->x00 = 0;
    p->x04 = a;
    p->x06 = b;
    p->x08 = c;
    p->x0A = d;
    p->x0C = 0;
    p->x10 = e;
    p->x14 = f;
    p->x18 = g;
}









/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02014134.c \
 *       --func func_02014134 --addr 0x02014134 --cc 1.1p1 --thumb
 */
void func_02014134(u8 *p, u16 b, int c, u16 d, u16 e, u16 f, u16 g, s16_02014134 h)
{
    ((struct Obj00193 *)p)->f0 = 0;
    ((struct Obj00193 *)p)->f4 = b;
    ((struct Obj00193 *)p)->f6 = c;
    ((struct Obj00193 *)p)->f8 = d;
    ((struct Obj00193 *)p)->fA = e;
    ((struct Obj00193 *)p)->fC = 1;
    *(u8 *)(p + 0x12) = 1;
    *(u16 *)&((struct Obj00193 *)p)->f10 = f;
    *(u16 *)(p + 0x16) = g;
    *(u16 *)&((struct Obj00193 *)p)->f14 = h;
    *(u8 *)(p + 0x13) = func_0201441C(func_02014274(d));
}









void func_0201416C(Rect14110 *p, u16 a, u16 b, u16 c)
{
    func_020140F8(p);
    p->x04 = a;
    p->x06 = b;
    p->x0A = c;
}







/*
 * Fills a 0x1C-byte record: live flag 1, id, slot -1, count, two cleared
 * fields and three caller words.  Filed as the call witness for the ov021
 * script dispatcher 0x021CA5C4.  The slot field is s16: -1 is then derived
 * from the live flag's 1 (`subs r1, r4, #2`); a u16 field loads 0xFFFF from
 * the pool.
 */
void func_02014184(Rec1C *r, u16 id, s16_02014134 count, u32 a, u32 b, u32 c)
{
    r->live = 1;
    r->id = id;
    r->slot = -1;
    r->count = count;
    r->pad = 0;
    r->zero = 0;
    r->a = a;
    r->b = b;
    r->c = c;
}








/*
 * The explicit-parameter initialiser of the 0x18-byte record that
 * func_02014204 fills from a table id: a = 1, b, c = -1, d, e = 0, f = 1,
 * the 0x12 byte = 1, then g/h/i from the three trailing parameters (two on
 * the stack) and the 0x13 byte from func_0201441C(func_02014274(d)).
 *
 * What closed it (wave 17, from 47 out): nothing new in the source; the
 * s16_020141A8 field written -1 is the image's `subs r0, r5, #2` off the constant 1
 * kept in r5.  The earlier 47 was measured against a 92-byte extent that
 * ran over the unlabelled leaves at 0x020141DC; once 0x020141DC was seeded
 * (seed round 9) the extent is the real 52 bytes and this source is exact.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020141A8.c \
 *       --func func_020141A8 --addr 0x020141A8 --cc 1.1p1 --thumb
 */
void func_020141A8(struct t_020139B0 *p, int b, int d, u16 g, u16 i, s16_020141A8 h)
{
    p->a = 1;
    p->b = b;
    p->c = -1;
    p->d = d;
    p->e = 0;
    p->f = 1;
    p->on = 1;
    p->g = g;
    p->i = i;
    p->h = h;
    p->kind = func_0201441C(func_02014274(d));
}








/*
 * note:     wave 17 lane untried_small: a getter of the +0xC word; listing extent runs over the unlabelled neighbours 0x020141E0 and 0x020141F0.
 */
int func_020141DC(const Rec020141DC *p)
{
    return p->fC;
}










/*
 * note:     wave 18 lane ties_b: unlabelled follower of func_020141DC; copies the three words at +0x10 out, read into locals last-to-first.
 */
void func_020141E0(const Rec020141E0 *p, Vec020141E0 *out)
{
    int z = p->v.z;
    int y = p->v.y;
    int x = p->v.x;

    out->x = x;
    out->y = y;
    out->z = z;
}










/*
 * note:     wave 18 lane ties_b: unlabelled follower; clears the +0xC word and struct-assigns the three words at +0x10.
 */
void func_020141F0(Rec020141F0 *p, const Vec020141F0 *v)
{
    p->fC = 0;
    p->v = *v;
}










/*
 *           inside this function, and src/pending/func_02013C70.c is itself
 *           only MATCH (its pool word for tbl_0209E010 has no outside
 *           witness), so no `matched` entry can attest the site.  Every
 *           concrete byte here is correct; --suggest-split reports no
 *           viable cut.
 */
void func_02014204(struct t_020141E0 *p, int id)
{
    struct v3 v;

    func_020140F8((Rect14110 *)p);
    p->a = 1;
    p->b = id;
    p->c = -1;
    p->d = 2;
    p->e = 0;
    if (func_02013C70(id) != 0) {
        sub_02013B90(id, (u32 *)(&v));
        p->f = 1;
        *((u8 *)p + 0x12) = 1;
        p->g = v.x;
        p->i = v.y;
        p->h = v.z;
    } else {
        sub_02013B74(id, (u32 *)(&v));
        p->f = 0;
        *(struct v3 *)((u8 *)p + 0x10) = v;
    }
}










/*
 * A one-line forwarder: func_02014204 with its second argument pinned to
 * 0x187.  This IS compiled C, not a linker veneer: an ARM long-branch
 * veneer never materialises an argument, and the four-byte-ARM-veneer shape
 * (docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md)
 * does not apply -- this is six bytes of Thumb plus two pool words, the
 * ordinary tail-call form
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The constant lands in
 * a pool rather than a `movs` because 0x187 is out of the Thumb immediate
 * range.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02014264.c \
 *       --func sub_02014264 --addr 0x02014264 --cc 1.1p1 --thumb
 */
void sub_02014264(void *p)
{
    func_02014204(p, 0x187);
}










/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: sub_02014274 and sub_020142A4 are two dense switches over a small
 * id (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md): the
 * range each `cmp`/`bhi` accepts has one slot with no case of its own,
 * which lands on the same body as the function's default arm
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md); the id that
 * hits it is not a real case, it is written as the default.
 *
 * sub_020142D0 is a bare constant getter, hiding the same way the tail
 * calls elsewhere in this packet do: no prologue, so disasm.py's sweep
 * never labels it. sub_020142D8 is a tail call to the ARM function
 * sub_02082BCC forwarding its own argument and two more constants; the
 * same target is reached by an ordinary `blx` from unit_02014368.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014274.c \
 *       --addr 0x02014274 --thumb
 */
u32 sub_02014274(u32 idx)
{
    switch (idx) {
    case 1: return 0;
    case 2: return 1;
    case 3: return 2;
    case 4: return 3;
    default: return 1;
    }
}










u32 sub_020142A4(u32 idx)
{
    switch (idx) {
    case 0: return 1;
    case 1: return 2;
    case 2: return 3;
    case 3: return 4;
    default: return 2;
    }
}










u32 sub_020142D0(void)
{
    return 0x3EA;
}










u32 sub_020142D8(u32 a)
{
    return sub_02082BCC(a, 0, 0x3EA);
}










/*
 * Test one flag in a bitmap: the lookup at 0x02014388 resolves the flag id
 * to the byte that holds it, and this function picks the bit out of that
 * byte.  A null byte pointer reads as "clear" rather than asserting.
 *
 * The bit number is `id % 8` on a *signed* id, not `id & 7`.  That is the
 * whole reason for the `lsrs #31 / lsls #29 / subs / rors #29 / adds`
 * quintet: an unsigned id folds to a single `movs r1, #7 / ands`, and a
 * plain mask loses four instructions.  The two forms differ only for
 * negative ids, where the shift count would be negative, so the source is
 * relying on the caller never passing one.
 *
 * The null check and the bit test share one `return 0`, so they are nested
 * ifs, not an early return followed by a second one: written as
 * `if (byte == 0) return 0;` the compiler gives the null arm its own
 * `movs r0, #0 / pop` and the function grows two bytes
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * EXACT*: the extent runs to 44 bytes because the next function has no
 * label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020142E8.c \
 *       --func func_020142E8 --addr 0x020142E8 --cc 1.1p1 --thumb
 */
u32 func_020142E8(void *bitmap, s32 id)
{
    u8 *byte = (u8 *)func_02014388((char *)bitmap, id);

    if (byte != 0) {
        if ((*byte & (1 << (id % 8))) != 0) {
            return 1;
        }
    }
    return 0;
}










void func_02014314(char *a0, int a1)
{
    unsigned char *p = (u8 *)func_02014388((char *)a0, a1);

    if (p != 0)
        *p |= 1 << (a1 % 8);
}










void func_0201433C(char *a0, int a1)
{
    unsigned char *p = (unsigned char *)func_02014388(a0, a1);

    if (p != 0)
        *p &= 0xff ^ (1 << (a1 % 8));
}










void func_02014368(char *a0, int a1, int a2)
{
    int i;

    for (i = a1; i <= a2; i++)
        func_0201433C(a0, (u16)i);
}









char *func_02014388(char *a0, u32 a1)
{
    int i;

    if (a1 == 0)
        return 0;
    if (a1 < 0x4000) {
        i = a1 >> 3;
        if (i >= 0x16c)
            return 0;
        return a0 + 0x27c + i;
    }
    i = (int)(a1 - 0x4000) / 8;
    if (i >= 8)
        return 0;
    return sub_02146268_Sys + i;
}









/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: sub_020143CC turns a large id (b >= 0x4000) into a byte offset
 * into the caller's own buffer, two bytes per id; sub_020143D8 zero-fills
 * the span between two such ids by tail-calling the ARM memset-shaped
 * sub_02082BCC (the same target unit_02014274.c's sub_020142D8 reaches
 * directly, this file reaches it through sub_020143CC first).
 *
 * sub_020143F0 clears a whole run of flag bits with sub_02014368
 * (unit_020142E8.c, out of range here) and then sets one more byte flag at
 * a fixed offset (0x3E8) of its own; sub_0201440C is the matching
 * read-and-clear accessor for that same flag byte.  Both are leaves with
 * no `lr` to save, so disasm.py's sweep does not label sub_0201440C
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020143CC.c \
 *       --addr 0x020143CC --thumb
 */
u32 sub_020143CC(u32 a, u32 b)
{
    return a + ((b - 0x4000) << 1);
}









void sub_020143D8(u32 a, u32 y, u32 z)
{
    u32 base = sub_020143CC(a, y);
    sub_02082BCC(base, 0, (z - y) << 1);
}









void sub_020143F0(u8 *a)
{
    sub_02014368((char *)((u32)a), 0xAA0, 0xB5F);
    a[0x3E8] = 1;
}









u8 sub_0201440C(u8 *a)
{
    u8 v = a[0x3E8];
    a[0x3E8] = 0;
    return v;
}








u8 func_0201441C(int i)
{
    return sub_0209E050_Map[i];
}








/*
 * Heap-allocates a 0x14-byte block tagged with the file string at
 * 0x020A72BC and line 0x33, then clears the u16 at +0x12.  The earlier
 * near miss in docs/notes/pkt_0201441C.c.txt declared the string at
 * 0x020A729C, 0x20 too low: the pool word in the image is the little-endian
 * bc 72 0a 02 at 0x02014440, and the one "differing byte" was bit 5 of that
 * address, not a register choice.
 */
void func_02014428(u32 heap)
{
    u8 *p = func_02030734(heap, 0x14, 1, (const char *)&sBtlSetupFile, 0x33);

    ((struct Obj15653 *)p)->f12 = 0;
}








/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02014458, sub_0201445C, sub_02014460, sub_02014464,
 *           sub_02014468, sub_0201446C, sub_02014470, sub_02014474,
 *           sub_02014478, sub_0201447C, sub_02014484
 *
 * alias: sub_02014444 is a tail-call trampoline for the SDK's
 * ENV_SetResourceSet, forwarding up to three register arguments
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Everything after it is
 * fourteen accessors on one small object: a u32 field at +0, three u8 fields
 * at +4/+5/+6 (the last pair, sub_02014464/sub_02014468, are the only two
 * with real prologue-less labels; the rest hide in the listing as .word runs
 * between the two literal pools either side of them, per
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), a u16 at +8, a
 * u16 at +0x12, and a u8 at +0x11 reached two ways: a plain getter
 * (sub_02014484) and a set-and-return-old accessor (sub_0201447C) used by a
 * caller that wants the previous value in the same instruction that installs
 * the new one.
 *
 * The struct is otherwise opaque; nothing in this range or its callers names
 * it, so the seven-byte gap between +8 and +0x11 is left as padding rather
 * than guessed at.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014444.c \
 *       --addr 0x02014444 --thumb
 */
void sub_02014444(u32 a, u32 b, u32 c)
{
    ENV_SetResourceSet(a, b, c);
}








u32 sub_0201444C(struct Sub02014444Obj *o)
{
    return o->f00;
}







void sub_02014450(struct Sub02014444Obj *o, u32 v)
{
    o->f00 = v;
}







void sub_02014454(struct Sub02014444Obj *o, u8 v)
{
    o->f04 = v;
}







u8 sub_02014458(struct Sub02014444Obj *o)
{
    return o->f04;
}







void sub_0201445C(struct Sub02014444Obj *o, u8 v)
{
    o->f05 = v;
}







u8 sub_02014460(struct Sub02014444Obj *o)
{
    return o->f05;
}







void sub_02014464(struct Sub02014444Obj *o, u8 v)
{
    o->f06 = v;
}







u8 sub_02014468(struct Sub02014444Obj *o)
{
    return o->f06;
}







void sub_0201446C(struct Sub02014444Obj *o, u16 v)
{
    o->f08 = v;
}







u16 sub_02014470(struct Sub02014444Obj *o)
{
    return o->f08;
}







void sub_02014474(struct Sub02014444Obj *o, u16 v)
{
    o->f12 = v;
}







u16 sub_02014478(struct Sub02014444Obj *o)
{
    return o->f12;
}







u8 sub_0201447C(struct Sub02014444Obj *o, u8 v)
{
    u8 old = o->f11;
    o->f11 = v;
    return old;
}







u8 sub_02014484(struct Sub02014444Obj *o)
{
    return o->f11;
}








/*
 * promoted: seed round 9, EXACT (fresh match.py one) once the ov010 callees
 *           0x0215FA34 and 0x0215FA44 were seeded in layout/function_starts.txt
 * note:     re-verified 2026-09-20: MATCH*; see verify output
 * note:     re-verified 2026-09-22 (family wave 6, field_status.c) in a
 *           fresh process after the evidence rules widened twice: still
 *           MATCH*, 3 of 5 sites resolved, no change to the C.  The two
 *           blockers were re-checked against the overlay listings by hand
 *           and are CLOSED AT THE BOTTOM, not merely unfiled: neither
 *           0x02188BD8 nor 0x0215FA44 is a function start in ANY candidate
 *           overlay, so no `thumb ovNNN` region hint on the symbols: line
 *           can resolve them.  0x02188BD8 falls mid-instruction in ov009
 *           (inside `bl func_02193734`) and in ov096, and lands on plain
 *           .word data in ov021 and ov230; 0x0215FA44 falls inside a `str`
 *           in ov009 and on .word data in ov010.  A region hint only picks
 *           between labelled candidates; it cannot create a label.  This
 *           row therefore needs a decompiled overlay, not a better hint.
 *
 * blocking: unresolved: 02188BD8 (thumb, from header) has no witness outside 02014488..02014; unresolved: 0215FA44 (thumb, from header) has no witness outside 02014488..02014
 *
 * wave15:   overlay callees are unlabelled Thumb starts: 0x0215FA34 and
 *           0x0215FA44 in ov010 (.word 0x4B024801, ldr r0/ldr r3 thunks),
 *           0x02188BD8 in ov021; need seeds in those overlays' listings.
 */
int sub_02014488(void *a0, u32 *a1, u8 *a2)
{
    void *v = (void *)((struct Obj05792 *)a2)->f8;
    void *w = (void *)((struct Obj05792 *)a2)->f0;
    void *x = (void *)((struct Obj05792 *)a2)->f4;
    void *y;

    y = (void *)sub_02012A30(v);
    switch (*a1) {
    case 0:
        func_02188BD8(x);
        *a1 = *a1 + 1;
        break;
    case 1:
        if (sub_020120F0(w) != 0) {
            break;
        }
        if (sub_020289B8(y) == 1) {
            break;
        }
        if (((struct Obj05792 *)a2)->fC != 0) {
            func_0215FA44();
        }
        return 1;
    }
    return 0;
}







void *func_020144DC(void *a0, int a1)
{
    void *r7 = func_020122C0(a0, 0, (void *)sub_02014488, 0x10);
    int *r4 = func_020124E8(r7);

    r4[0] = (int)a0;
    r4[1] = a1;
    r4[2] = (int)func_020120F4(a0);
    r4[3] = 1;
    return r7;
}







/*
 * promoted: seed round 9, EXACT (fresh match.py one) once the ov010 callees
 *           0x0215FA34 and 0x0215FA44 were seeded in layout/function_starts.txt
 * note:     re-verified 2026-09-20: MATCH*; see verify output
 * note:     re-verified 2026-09-22 (family wave 6, field_status.c): still
 *           MATCH*, 2 of 4 sites resolved, no change to the C.  Same two
 *           overlay targets as src/pending/sub_02014488.c, and re-checked
 *           the same way: 0x02188BD8 and 0x0215FA44 are a function start
 *           in none of the overlays whose window covers them, so the
 *           `label` refusal is not an ambiguity a region hint can settle.
 *           listing carries a func_ label at either address; 4 overlays
 *           overlap 0x02188BD8 (ov009, ov021, ov096, ov230) and 2 overlap
 *           0x0215FA44 (ov009, ov010), so `label` refuses to guess.
 *
 * Byte-correct at all 70 bytes; 2 of 4 relocation sites stay wildcarded.
 * Seeded from an arm9 dispatcher (arm9_main calls the same pair at 0x020144A8
 * and 0x020144CE, which is inside the same source unit but outside this
 * compared range - it is still not a label, so it does not attest).
 *
 * This row was screened `ready` by the band brief; it is one of the minority
 * the screen cannot see, because the call targets are overlay exports rather
 * than arm9 or runtime code.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201450C.c \
 *       --func func_0201450C --addr 0x0201450C --cc 1.1p1 --thumb
 * wave15:   overlay callees are unlabelled Thumb starts: 0x0215FA34 and
 *           0x0215FA44 in ov010 (.word 0x4B024801, ldr r0/ldr r3 thunks),
 *           0x02188BD8 in ov021; need seeds in those overlays' listings.
 */
int func_0201450C(int a0, int *a1, int *a2)
{
    int v7 = a2[0];
    int v6 = a2[1];

    func_02012A30((const struct BigObj *)a2[2]);
    switch (*a1) {
    case 0:
        func_02188BD8((u8 *)v6);
        *a1 = *a1 + 1;
        break;
    case 1:
        if (func_020120F0((const struct Ctx *)v7) == 0) {
            if (a2[3] != 0) {
                func_0215FA44();
            }
            return 1;
        }
        break;
    }
    return 0;
}







void *func_02014554(void *a0, int a1)
{
    void *r7 = func_020122C0(a0, 0, (void *)func_0201450C, 0x10);
    int *r4 = func_020124E8(r7);

    r4[0] = (int)a0;
    r4[1] = a1;
    r4[2] = (int)func_020120F4(a0);
    r4[3] = 0;
    return r7;
}





/*
 *           02014584..020145CA.  This is the chain class of the band brief:
 *           0x020120C0's only callers are inside this range, so `label` has
 *           nothing to point at.  It is NOT a lane-2 row (it lives in
 *           pkt_020120B4 and is a chain row of the 0-64 band list), so this
 *           file cannot be finished from inside the lane.  Filing
 *           0x020120C0's own EXACT entry converts the site to `matched` and
 *           this file prints EXACT with no change to the C below.
 *
 * Byte-correct at all 70 concrete bytes; 3 of 4 relocation sites resolved.
 *
 * Two spelling points that were needed to get this far:
 *   - func_02188BE8 lives in ov021 and is THUMB.  Left to the name-based
 *     fallback it is inferred `arm` and match.py stops with an ISA conflict
 *     ("the source declares arm, the image says thumb"), which reads like a
 *     compile failure but is a symbols: block omission.  Naming the region
 *     (`func_02188BE8  0x02188BE8  thumb ov021`) resolves the site through
 *     `label` (9 outside branches, e.g. 0x02012078).
 *   - `switch (*a1)` with `break` in the arms, not `return 0`: the original
 *     has exactly one `movs r0,#0 / pop` epilogue, shared by the arms and by
 *     the fall-through.  Writing `return 0` in each arm duplicates it and
 *     costs 36 bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02014584.c \
 *       --func func_02014584 --addr 0x02014584 --cc 1.1p1 --thumb
 */
int func_02014584(int a0, int *a1, int *a2)
{
    int v = *a2;

    switch (*a1) {
    case 0:
        if (func_020120F0((const struct Ctx *)v) == 0) {
            func_020120C0((struct IcaAnime *)v);
            *a1 = *a1 + 1;
        }
        break;
    case 1:
        if (func_02188BE8(func_0201210C((void *)v)) != 0) {
            *a1 = *a1 + 1;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}





/*
 * promoted: seed round 9, EXACT (fresh match.py one) once the ov010 callees
 *           0x0215FA34 and 0x0215FA44 were seeded in layout/function_starts.txt
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * note:     re-verified 2026-09-22 (family wave 6, field_status.c): still
 *           MATCH, 3 of 4 sites resolved, no change to the C.  The single
 *           blocker 0x0215FA34 is the same overlay-export class as the
 *           two in sub_02014488.c: ov009 and ov010 both cover it and
 *           neither labels a function there, so no region hint helps.
 * wave15:   overlay callees are unlabelled Thumb starts: 0x0215FA34 and
 *           0x0215FA44 in ov010 (.word 0x4B024801, ldr r0/ldr r3 thunks),
 *           0x02188BD8 in ov021; need seeds in those overlays' listings.
 */
void *func_020145CC(void *a0)
{
    void *r6 = func_020122C0(a0, 0, (void *)func_02014584, 0x10);
    u32 *r4 = func_020124E8(r6);

    r4[0] = (u32)a0;
    r4[1] = 0;
    r4[2] = (u32)func_020120F4(a0);
    func_0215FA34();
    return r6;
}




void *func_020145FC(void *a0)
{
    void *r7 = func_020122C0(a0, 0, (void *)func_02014584, 0x10);
    int *r4 = func_020124E8(r7);

    r4[0] = (int)a0;
    r4[1] = 0;
    r4[2] = (int)func_020120F4(a0);
    return r7;
}




/*
 * The shared tail of the three working cases sits INSIDE case 0's arm (a
 * label a later arm jumps back to is what makes 0x02014658 fall out of case 0
 * with no branch) and the default arm's `return 0` is reached by a `goto`
 * rather than copied, which is what puts the single `movs r0, #0` epilogue at
 * 0x02014692.  `u32 a0 = p[0];` before the switch is load-bearing: without it
 * each arm reloads p[0] and the whole dispatch shifts.
 */
u32 func_02014628(void *obj, u32 *mode, u32 *p)
{
    u32 a0 = p[0];
    void *r;

    switch (*mode) {
    case 0:
        r = (void *)func_021BE8D4((void *)a0, p[1], 0, 0);
    tail:
        func_02012374(obj, r);
        (*mode)++;
        goto ret0;
    case 1:
        r = (void *)func_02014728((char *)a0, p[1], p[2], p[3], p[4]);
        goto tail;
    case 2:
        r = (void *)func_021BE92C((void *)a0, p[1], 0, 0, 1, 0, 0);
        goto tail;
    case 3:
        return 1;
    default:
    ret0:
        return 0;
    }
}



/*
 * The step function func_02014728 installs (argsize 0x14, args p[0]..p[4]),
 * one stage per call on *mode.  Closed in wave 13: the earlier goto/label
 * spelling (docs/notes/func_02014698.c.txt, one byte out) was the wrong
 * shape.  Written plainly -- every arm carries its own `(*mode)++; break;`
 * and case 2 is `if (poll() == 0) (*mode)++;` -- the compiler cross-jumps
 * the repeated increments itself, and that leaves case 2's tail jump on
 * case 1's `b inc` block exactly as the image has it.
 */
u32 func_02014698(void *obj, u32 *mode, u32 *args)
{
    u32 a0 = args[0];

    switch (*mode) {
    case 0:
        func_02012374(obj, func_020144DC((void *)a0, args[1]));
        (*mode)++;
        break;
    case 1:
        func_020120B4((struct IcaAnime *)a0, args[2], (void *)args[3], (void *)args[4]);
        (*mode)++;
        break;
    case 2:
        if (func_020120F0((const struct Ctx *)a0) == 0) {
            (*mode)++;
        }
        break;
    case 3:
        func_02012374(obj, func_020145CC((void *)a0));
        (*mode)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}



void *func_020146F8(char *a0, int a1, int a2, int a3, int a4)
{
    void *r = func_020122C0(a0, 0, (void *)((int)func_02014628), 0x14);
    u32 *p = func_020124E8(r);

    p[0] = (u32)a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    p[4] = a4;
    return r;
}



void *func_02014728(char *a0, int a1, int a2, int a3, int a4)
{
    void *r = func_020122C0(a0, 0, (void *)((int)func_02014698), 0x14);
    u32 *p = func_020124E8(r);

    p[0] = (u32)a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    p[4] = a4;
    return r;
}



/*
 * A three-state step machine over a descriptor `a2`.  State 0 forwards five
 * of the descriptor's leading words (four in registers, the fifth on the
 * stack) to func_020146F8 and hands the result to func_02012374, then bumps
 * the counter.  State 1 calls the descriptor's own callback slot (+0x14) with
 * the pointer at +0x18.  State 2 frees the +0x18 pointer and returns 1.  The
 * `*a1 = *a1 + 1` in state 1 is a separate arm in the source; the compiler
 * cross-jumps it onto state 0's increment, which is why the listing shows the
 * state-1 arm branching backwards into state 0's tail.
 *
 * EXACT*: the compared extent runs four bytes past the body into the next
 * function's alignment pad (the follower at 0x020147B0 saves lr, so its label
 * exists and the extent is only the pad - no byte of it differs).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02014758.c \
 *       --func func_02014758 --addr 0x02014758 --cc 1.1p1 --thumb
 */
int func_02014758(int a0, int *a1, S *a2)
{
    switch (*a1) {
    case 0:
        func_02012374((struct Evt *)a0, func_020146F8((char *)a2->f00, a2->f04, a2->f08, a2->f0c,
                                        a2->f10));
        *a1 = *a1 + 1;
        break;
    case 1:
        if (a2->f14 != 0) {
            a2->f14(a2->f18);
        }
        *a1 = *a1 + 1;
        break;
    case 2:
        if (a2->f18 != 0) {
            func_020307B0(a2->f18);
        }
        return 1;
    }
    return 0;
}



/*
 * Byte-for-byte the twin of func_02014758 (same 86-byte shape, same three
 * states) with func_020146F8 replaced by func_02014728.  The only other
 * difference is the literal pool holding 0x020307B0: 0x02014758's pool is
 * reachable with `blx 0x20307b0`'s 26-bit reach, this one needs no change.
 *
 * EXACT*: the compared extent runs into the four-byte alignment pad before
 * the next labelled function; no byte of the body differs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020147B0.c \
 *       --func func_020147B0 --addr 0x020147B0 --cc 1.1p1 --thumb
 */
int func_020147B0(int a0, int *a1, S *a2)
{
    switch (*a1) {
    case 0:
        func_02012374((struct Evt *)a0, func_02014728((char *)a2->f00, a2->f04, a2->f08, a2->f0c,
                                        a2->f10));
        *a1 = *a1 + 1;
        break;
    case 1:
        if (a2->f14 != 0) {
            a2->f14(a2->f18);
        }
        *a1 = *a1 + 1;
        break;
    case 2:
        if (a2->f18 != 0) {
            func_020307B0(a2->f18);
        }
        return 1;
    }
    return 0;
}



/*
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT.
 */
void *func_02014808(char *a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    void *r = func_020122C0(a0, 0, (void *)((int)func_02014758), 0x1c);
    u32 *p = func_020124E8(r);

    p[0] = (u32)a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    p[4] = a4;
    p[5] = a5;
    p[6] = a6;
    return r;
}



void *func_02014840(char *a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    void *r = func_020122C0(a0, 0, (void *)((int)func_020147B0), 0x1c);
    u32 *p = func_020124E8(r);

    p[0] = (u32)a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    p[4] = a4;
    p[5] = a5;
    p[6] = a6;
    return r;
}



/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id sites
 *           ov091_id (91) and ov131_id (131) resolve as `overlay_id` (a
 *           layout overlay index, loaded by a pc-relative load of this
 *           function, reaching the id register of a known overlay loader),
 *           which was the last blocker.
 *
 * A six-state machine on obj->f1e.  Every concrete byte matches: 152 of 152
 * against the listing extent, the two relocation sites that are attestable
 * (both calls) resolve as `label`, and both 0x021BED00/0x021DC800 pool words
 * resolve as `literal`; only the two small pooled words stay wildcarded.
 *
 * The small pooled words are the SDK's FS_OVERLAY_ID() shape (see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md): a
 * value that mwccarm materialises with `movs` for any literal in 0..255, and
 * therefore cannot be written as a number - the source passes an address the
 * linker resolved to 91 / 131, and is declared here as a symbol of that
 * absolute value.
 *
 * Two levers mattered, both from the wave-r6 list:
 *   * the switch value is read once into a local before the dispatch
 *     (`ldr r1, [r4]` before `cmp r1, #5`), which is what puts p[0] in r0;
 *   * a case that ends in "return 0" must `break` instead, so every arm
 *     shares the one epilogue at 0x020148FC instead of duplicating it.
 * The state-2 arm is three statements - `if (v == 0) { *mode = 5; break; }`,
 * `if (v == 1) { ...; *mode = 3; break; }` and a trailing `*mode = 5;` - and
 * only that spelling reproduces the arm's out-of-line `movs r0, #5` block at
 * 0x020148D2 with the second test as `bne` rather than `beq`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02014878.c \
 *       --func func_02014878 --addr 0x02014878 --cc 1.1p1 --thumb
 */
u32 func_02014878(u32 a0, u32 *mode, u32 *p)
{
    u32 v = p[0];

    switch (*mode) {
    case 0:
        func_020120B4((struct IcaAnime *)v, (u32)ov091_id, (void *)0x021BED00, (void *)p[2]);
        *mode = 1;
        break;
    case 1:
        if (func_020120F0((const struct Ctx *)v) != 0)
            break;
        *mode = 2;
        break;
    case 2:
        if (*(u32 *)(p[2] + 0x40) == 0) {
            *mode = 5;
            break;
        }
        if (*(u32 *)(p[2] + 0x40) == 1) {
            *(u8 *)(p[3] + 0xf) = (u8)*(u32 *)(p[2] + 0x3c);
            *mode = 3;
            break;
        }
        *mode = 5;
        break;
    case 3:
        func_020120B4((struct IcaAnime *)v, (u32)ov131_id, (void *)0x021DC800, (void *)p[3]);
        *mode = 4;
        break;
    case 4:
        if (func_020120F0((const struct Ctx *)v) != 0)
            break;
        *(u32 *)(p[2] + 0x3c) = *(u8 *)(p[3] + 0xf);
        *mode = 0;
        break;
    case 5:
        return 1;
    default:
        break;
    }
    return 0;
}
