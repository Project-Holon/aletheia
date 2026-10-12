/*
 * file:     btl_net.c
 * unit:     yes
 * function: func_021D3A20, func_021D3A40, func_021D3A7C, func_021D3A98, func_021D3AB4, func_021D3AD0, func_021D3AEC, func_021D3B08, func_021D3B28, func_021D3B5C, func_021D3B74, func_021D3B88, func_021D3B9C, func_021D3BB0, func_021D3BC0, func_021D3BE0, func_021D3C0C, func_021D3C2C, func_021D3C44, func_021D3C70, func_021D3C90, func_021D3CA8, func_021D3CC8, func_021D3CFC, func_021D3D1C, func_021D3D2C, func_021D3D50, func_021D3D70, func_021D3D7C, func_021D3D90, func_021D3D9C, func_021D3DC4, func_021D3E70, func_021D3EC8, func_021D3F04, func_021D3F48, func_021D3F4C, func_021D3F54, func_021D3F60, func_021D3F64, func_021D3F88, func_021D3F98, func_021D3FA8, func_021D3FAC, func_021D3FC4, func_021D3FD0, func_021D3FDC, func_021D4150, func_021D4230, func_021D4254, func_021D4270, func_021D4294, func_021D42BC, func_021D4330, func_021D4348, func_021D4360, func_021D4378, func_021D4394, func_021D43B8, func_021D43E0, func_021D440C, func_021D4438, func_021D446C, func_021D44B4, func_021D44CC, func_021D4500, func_021D450C, func_021D4558, func_021D45B8, func_021D45FC, func_021D4648, func_021D4674, func_021D4680, func_021D46B0, func_021D46FC, func_021D4784, func_021D47A4, func_021D4800, func_021D4808, func_021D4838, func_021D4880, func_021D4898, func_021D48CC, func_021D4908, func_021D4954, func_021D499C, func_021D49B0, func_021D49CC, func_021D49E0, func_021D4A0C, func_021D4A64, func_021D4A6C, func_021D4AF4, func_021D4B18, func_021D4B58, func_021D4B98, func_021D4BD4, func_021D4BFC, func_021D4C14, func_021D4C58, func_021D4C60, func_021D4C6C, func_021D4C84, func_021D4CB8, func_021D4CE0, func_021D4CEC, func_021D4D24, func_021D4D5C, func_021D4D64, func_021D4D84, func_021D4EFC, func_021D4F84, func_021D505C, func_021D50B4, func_021D5150, func_021D51CC, func_021D51DC, func_021D5208, func_021D5244, func_021D52B4, func_021D533C, func_021D5364, func_021D539C, func_021D53B8, func_021D53C0, func_021D53C8, func_021D53DC, func_021D5440, func_021D5444, func_021D5448, func_021D5450, func_021D5478, func_021D54B4, func_021D54C0, func_021D54D0, func_021D54E0, func_021D54F4, func_021D5528, func_021D554C, func_021D5568, func_021D5584, func_021D55A0, func_021D55D8, func_021D5608, func_021D5640, func_021D5674, func_021D56A0, func_021D56CC, func_021D5734, func_021D5750, func_021D5778, func_021D57A8, func_021D57FC, func_021D5814, func_021D5844, func_021D5848, func_021D5854, func_021D5864, func_021D587C, func_021D58A8, func_021D590C, func_021D5970, func_021D59B4, func_021D5AD8, func_021D5B40, func_021D5B44, func_021D5B48, func_021D5B68, func_021D5B7C, func_021D5BA4, func_021D5BB0, func_021D5BDC, func_021D5C08, func_021D5C30, func_021D5C44, func_021D5CB4, func_021D5D14, func_021D5D50, func_021D5D68, func_021D5DC0
 * address:  0x021D3A20
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
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D6730 0x021D6730 thumb ov093
 *   func_021D6744 0x021D6744 thumb ov093
 *   func_021D5FE4 0x021D5FE4 thumb ov093
 *   func_021D6008 0x021D6008 thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021D6440 0x021D6440 thumb ov093
 *   func_021D66D0 0x021D66D0 thumb ov093
 *   func_021D64F0   0x021D64F0  thumb
 *   func_021EF9F4 0x021EF9F4 thumb ov093
 *   func_021EFAD8 0x021EFAD8 thumb ov093
 *   func_021EFB34 0x021EFB34 thumb ov093
 *   func_021EFA94 0x021EFA94 thumb ov093
 *   func_021D69A0 0x021D69A0 thumb ov093
 *   func_021D65C8 0x021D65C8 thumb ov093
 *   func_021D6D5C 0x021D6D5C thumb ov093
 *   func_021D6D70   0x021D6D70  thumb
 *   func_021CD9F4 0x021CD9F4 thumb ov093
 *   func_021B9B10 0x021B9B10 thumb ov093
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B9D10 0x021B9D10 thumb ov093
 *   func_021D6738   0x021D6738  thumb
 *   func_021D6264 0x021D6264 thumb ov093
 *   func_021D6848 0x021D6848 thumb ov093
 *   func_021D6408 0x021D6408 thumb ov093
 *   func_021D6E88 0x021D6E88 thumb ov093
 *   func_021EFC78   0x021EFC78  thumb
 *   func_021D67D8 0x021D67D8 thumb ov093
 *   func_021EF9A8 0x021EF9A8 thumb ov093
 *   func_021B9F84 0x021B9F84 thumb ov093
 *   d_021EFF74  0x021EFF74  data  a1
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D805C  0x021D805C  thumb  ov093
 *   func_021D7B60  0x021D7B60  thumb  ov093
 *   d_021EFF94  0x021EFF94  data  ov093  a1
 *   func_021D5F14  0x021D5F14  thumb  ov093
 *   d_021EFFA0 0x021EFFA0 data a1
 *   func_021EAE74 0x021EAE74 thumb ov093
 *   func_021EAE64 0x021EAE64 thumb ov093
 *   func_021EAE04 0x021EAE04 thumb ov093
 *   func_021EAECC 0x021EAECC thumb ov093
 *   func_02005E30 0x02005E30 thumb
 *   func_02005CA4 0x02005CA4 thumb
 *   func_02006734 0x02006734 thumb
 *   func_021F8B10 0x021F8B10 thumb ov094
 *   func_021B92A0 0x021B92A0 thumb ov093
 *   func_021EAE14 0x021EAE14 thumb ov093
 *   d_021F3B88 0x021F3B88 data ov093 a4
 *   d_021F3A98 0x021F3A98 data ov093 a4
 *   func_02030734 0x02030734 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_0203D1B4 0x0203D1B4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_0201A918 0x0201A918 thumb
 *   sub_02030734   0x02030734  arm
 *   func_02007B50  0x02007B50  thumb
 *   func_02007B00  0x02007B00  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02008468 0x02008468 thumb
 *   func_021F3A98   0x021F3A98  data
 *   func_02045A98  0x02045A98  arm
 *   MIi_CpuClear16 0x02082A48  arm
 *   sub_020458F8   0x020458F8  arm
 *   sub_02045A90   0x02045A90  arm
 *   sub_0201F41C   0x0201F41C  thumb
 *   func_0203A424 0x0203A424 arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02082D44 0x02082D44 arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02019C90  0x02019C90  thumb
 *   func_02017F90  0x02017F90  thumb
 *   func_021D63B8  0x021D63B8  thumb  ov093
 *   func_021D7D18  0x021D7D18  thumb  ov093
 *   func_021D67F4  0x021D67F4  thumb  ov093
 *   func_021D6DC4  0x021D6DC4  thumb  ov093
 *   d_021F3AA4     0x021F3AA4  data  a1
 *   func_02017D30 0x02017D30 thumb
 *   func_02017D70 0x02017D70 thumb
 *   func_020181F4  0x020181F4  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_0201C158 0x0201C158 thumb
 *   func_02017F00  0x02017F00  thumb
 *   func_021E8CE0  0x021E8CE0  thumb  ov093
 *   func_021EF948 0x021EF948 thumb ov093
 *   func_021D78E4  0x021D78E4  thumb  ov093
 *   data_021F040C  0x021F040C  data  ov093
 *   _dflt   0x0209B750  arm
 *   _dfltu  0x0209B790  arm
 *   _ddiv   0x0209D1E0  arm
 *   _dgr    0x0209B864  arm
 *   _dmul   0x0209B2E8  arm
 *   _dadd   0x0209AC04  arm
 *   _dsub   0x0209AF34  arm
 *   _dfix   0x0209C508  arm
 */
#include "../../matched/include/Obj13430.h"

struct QK;
struct QJ;
struct BtlNet;
struct Arr;
struct UtilSlots;
struct Q1;
struct Unk021D62A8;
struct Link;
struct Entry;
struct U16Vec;
struct Sav;
#include "btl_net_types.h"

typedef struct { u32 v; } Slot;

struct Rec { u16 a, b; u8 c, d, e; };

struct HalfRec { u16 a, b, c, d; };

typedef struct {
    u8 a;
    u8 b;
} Pair_021D3E70;

typedef struct { u8 a,b; } Pair_021D3EC8;

struct Q {
    u8 state, mode;
    u8 flag0:1, flag1:1, flag2:1, flag3:1, flag4:1, flag5:1, rest:2;
    u8 unk3;
    u16 delay, current, target, maximum, tick;
};

typedef struct {
    int w[8];
} S32;

struct BtlNetRec {
    u8 pad00[0xbb8];
    u16 fBB8;
    u16 fBBA;
};

struct BtlNetSync {
    struct {
        u8 val;
        u8 ok;
    } e[4];
    u8 n;
    u8 mx;
    u8 pad[2];
};

struct BtlNet {
    void *link;                 /* 0x00 */
    u16 heap;                   /* 0x04 */
    u8 id;                      /* 0x06 */
    u8 f07;                     /* 0x07 */
    u16 mask;                   /* 0x08 */
    u8 f0a, count, f0c, f0d, f0e, f0f, f10;
    u8 states[4];               /* 0x11 */
    u8 pad15[3];
    S32 f18;                    /* 0x18 */
    struct BtlNetRec rec0;      /* 0x38 */
    struct BtlNetRec peer[4];   /* 0xbf4 */
    void *tblA[4];              /* 0x3ae4 */
    void *tblB[4];
    void *tblC[4];
    void *f3b14;
    void *f3b18;
    union {
        u32 f3b1c;
        u16 buf[2];
    } u;                        /* 0x3b1c */
    struct BtlNetSync sync;     /* 0x3b20 */
};

typedef union {
    u32 w;
    struct {
        u32 type : 8;
        u32 size : 24;
    } h;
} Hdr_021D3A20;

typedef struct {
    u8 pad00[0x14];
    void *f14;
} In;

typedef struct {
    u8 pad00[0x28];
    u8 f28[0x40];
    u32 f68;
} Out;

typedef struct {
    u32 type : 8;
    u32 size : 24;
} Hdr_021D4CB8;

extern u8 *func_021B9934(char *p, int i);
extern void func_021D6730(struct QK *p, u16 v);
extern void func_021D6744(u8 *p, u8 a, int f, u8 b, u16 c, u16 d);
extern void func_021D5FE4(u8 *, u32);
extern void func_021D6008(u8 *, u32);
extern void func_021D5FC0(struct BtlMon *, u32);
extern void func_021D6440(u8 *, u32);
extern void func_021D66D0(struct QJ *p, u32 v);
extern void func_021D64F0(void *p);
extern int func_021EF9F4(void *, u32, Slot, int);
extern int func_021EFAD8(char *a, u32 b, u32 c);
extern void func_021EFB34(struct BtlNet *, u8);
extern int func_021EFA94(void *, int);
extern void func_021D69A0(u8 *, int, u8);
extern void func_021D65C8(struct BtlMon *, struct BtlMon *);
extern void func_021D6D5C(u8 *, u16);
extern void func_021D6D70(unsigned char *p);
extern void func_021CD9F4(u8 *p, u8 n);
extern void func_021B9B10(u8 *, u8, int);
extern char *func_021B9AEC(char *, int);
extern void func_021B9D10(char *, struct Arr *, int);
extern void func_021D6738(u8 *p);
extern void func_021D6264(struct UtilSlots *p, int v);
extern void func_021D6848(u8 *p, struct Rec *r);
extern void func_021D6408(u8 *);
extern void func_021D6E88(u8 *);
extern void func_021D67D8(u8 *p, u32 n);
extern u8 func_021EF9A8(u32 *);
extern u16 func_021B9F84(char *p, int i, unsigned int j);
extern u8 func_021B9B94(struct Q1 *p);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern u32 func_021D805C(void *p, u32 n);
extern u32 func_021D7B60(void *p, u32 b);
extern u8 func_021D5F14(struct BtlMon *p);
extern void func_021EAE74(char *p, u32 a, u32 b);
extern int func_021EAE64(void *);
extern void func_021EAE04(u32 *p);
extern void func_021EAECC(u8 *p, int v, int w);
extern void func_02005E30(u32);
extern void func_02005CA4(int,u32);
extern void func_02006734(u8);
extern int func_021F8B10(void);
extern void func_021B92A0(u8 *p);
extern int func_021EAE14(u32 *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_0203D1A4(struct Link *p);
extern int func_0203D1B4(void);
extern u32 func_020307B0(void *p);
extern u32 func_0200FB24(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern int func_0201A918(void);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02007B50(void **p);
extern u32 func_02007B00(void);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern int func_02008468(void);
extern u16 func_02045A98(void);
extern void MIi_CpuClear16(u16 data, void *dst, u32 size);
extern u16 sub_020458F8(struct U16Vec *vec);
extern u16 *sub_02045A90(struct U16Vec *vec);
extern void sub_0201F41C(const u16 *src, u16 *dst, u32 n);
extern void func_0203A424(char *p, int a, int b, int c);
extern unsigned int func_02039CB4(struct Link *a0, unsigned int a1, unsigned int a2);
extern void func_02082D44(const void *, void *, u32);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern u32 func_02017E1C(void *, u32, u32);
extern u32 func_02019C90(u16, u16, u32);
extern u32 func_02017F90(void *);
extern void func_021D63B8(u8 *p, int all);
extern union BtlMonSlot func_021D7D18(int);
extern void func_021D67F4(u8 *p);
extern void func_021D6DC4(u8 *p);
extern u32 func_02017D30(struct Sav *p);
extern u32 func_02017D70(struct Sav *p, u32 f);
extern void func_020181F4(void *p, u16 move, u32 slot);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_0201C158(u32, u32);
extern u8 func_02017F00(void *h);
extern u16 func_021E8CE0(u32 a, u32 b);
extern int func_021EF948(int);
extern unsigned short func_021D78E4(unsigned short a, int i);
int func_021D3A20(u32 *a, int *b, u32 *c);
int func_021D3A40(u32 *a, int *b, const u32 *c);
int func_021D3A7C(u32 *a, int *b, u32 *c);
int func_021D3A98(u32 *a, int *b, u32 *c);
int func_021D3AB4(u32 *a, int *b, u32 *c);
int func_021D3AD0(u32 *a, int *b, u32 *c);
int func_021D3AEC(u32 *a, int *b, u32 *c);
int func_021D3B08(u32 *a, int *b, u32 *c);
int func_021D3B28(u32 *a, int *b, const u32 *c);
int func_021D3B5C(u8 *p, int b, u32 *q);
int func_021D3B74(u32 *a, int *b, u32 *c);
int func_021D3B88(u32 *a, int *b, u32 *c);
int func_021D3B9C(char *p, int unused, unsigned int *a);
int func_021D3BB0(char *p, int unused, unsigned int *a);
int func_021D3BC0(char *p, int unused, unsigned int *a);
int func_021D3BE0(char *p, int unused, unsigned int *a);
int func_021D3C0C(char *p, int unused, unsigned int *a);
int func_021D3C2C(u8 *p, int b, u32 *q);
int func_021D3C44(u8 *p, int unused, unsigned int *a);
int func_021D3C70(char *p, int unused, unsigned int *a);
int func_021D3C90(u8 *p, int b, u32 *q);
int func_021D3CA8(char *p, int unused, unsigned int *a);
int func_021D3CC8(char *p, int unused, const unsigned int *a);
int func_021D3CFC(char *p, int unused, unsigned int *a);
int func_021D3D1C(u8 *p);
int func_021D3D2C(char *p, int unused, unsigned int *a);
int func_021D3D50(char *p, int unused, unsigned int *a);
u8 func_021D3D70(u8 *p);
u32 func_021D3D7C(u8 *p);
u8 func_021D3D84(u8 *p);
u8 func_021D3D90(u8 *p);
void func_021D3D9C(u8 *p);
u32 func_021D3DC4(u8 *a, void *b, void *c);
int func_021D3E70(void *s, void *m);
int func_021D3EC8(void *s,struct Unk021D62A8 *m);
void func_021D3F04(struct BtlNetEntry *p);
void func_021D3F48(u8 *p, u32 v);
int func_021D3F4C(struct BtlNetEntry *p);
void func_021D3F54(u8 *p);
u8 func_021D3F60(u8 *p);
void func_021D3F64(struct BtlNetEntry *p, u16 v);
void func_021D3F88(struct BtlNetEntry *p);
int func_021D3F98(u8 *p);
u16 func_021D3FA8(u8 *p);
int func_021D3FAC(struct BtlNetEntry *p);
void func_021D3FC4(struct BtlNetEntry *p);
void func_021D3FD0(unsigned char *p);
void func_021D3FDC(u8 *p, struct Q *q);
void func_021D4150(void *link, u16 mask, u16 heap);
int func_021D4230(void);
void func_021D4254(void);
int func_021D4270(void);
int func_021D4294(u16 v);
void func_021D42BC(int idx, int unused, u16 *data);
u8 func_021D4330(int i);
int func_021D4348(void);
int func_021D4360(void);
u8 func_021D4378(void);
u8 func_021D4394(u32 a);
u32 func_021D43B8(u32 a);
void func_021D43E0(int unused0, int unused1, S32 *src);
int func_021D440C(S32 *dst);
u8 func_021D4438(u32 a);
void *func_021D446C(int idx, int unused, u32 size);
void func_021D44B4(int idx, void *p);
int func_021D44CC(void);
void func_021D4500(void);
u32 func_021D450C(u32 *a);
void *func_021D4558(int idx, int unused, u32 size);
void func_021D45B8(int a, int b);
int func_021D45FC(void);
u32 func_021D4648(u32 a);
void func_021D4674(void);
u32 func_021D4680(u32 *a);
void *func_021D46B0(int a, int b, u32 size);
void func_021D46FC(u32 a, u32 b, const Hdr_021D3A20 *c);
int func_021D4784(u32 a);
void *func_021D47A4(u8 a);
void func_021D4800(void);
int func_021D4808(u32 a);
void *func_021D4838(int idx, int unused, u32 size);
void func_021D4880(int idx, void *p);
int func_021D4898(void);
void *func_021D48CC(u8 a);
u32 func_021D4908(void *a);
u32 func_021D4954(void *a, int b, int c);
void func_021D499C(int unused, void *p);
int func_021D49B0(void);
void *func_021D49CC(void);
void func_021D49E0(void);
void func_021D4A04(void);
Out *func_021D4A0C(In *a, u32 heap);
void func_021D4A64(void *p);
void func_021D4A6C(void);
void func_021D4AF4(int a);
int func_021D4B18(int a);
u32 func_021D4B58(u32 a, u32 b, u32 c);
int func_021D4B98(void);
u16 func_021D4BD4(int a, u8 **q);
struct BtlNetRec *func_021D4BFC(int idx);
void func_021D4C14(int idx, u32 v);
void func_021D4C58(u32 a);
unsigned char func_021D4C60(void);
u16 func_021D4C6C(u8 **out);
u32 func_021D4C84(u32 a, u32 b);
void func_021D4CB8(int unused, u32 v);
struct BtlNetRec *func_021D4CE0(void);
void func_021D4CEC(void);
void *func_021D4D24(u32 a, u16 b);
void func_021D4D5C(void *p);
void func_021D4D64(u32 *p, const void *src, u32 a);
struct BtlMon *func_021D4D84(void *a, u8 b, u32 c);
void func_021D4EFC(struct BtlMon *a, void *mon, u32 c, u32 d);
int func_021D4F84(struct BtlMon *p, void *h, int reset);
void func_021D505C(struct BtlMon *a);
void func_021D50B4(struct BtlMon *p);
void func_021D5150(struct BtlMon *p);
void func_021D51CC(u8 *p);
void func_021D51DC(struct BtlMoveSlot *p, u32 a, u32 b, u32 c);
void func_021D5208(struct BtlMoveInfo *p, u32 a, u32 b);
int func_021D5244(struct BtlMoveInfo *e, void *h, u8 k);
void func_021D52B4(struct BtlMon *p, void *h, u32 flag);
void func_021D533C(struct BtlMon *p);
void func_021D5364(struct BtlMon *p);
void func_021D539C(struct BtlMon *p);
void func_021D53B8(void *p);
void func_021D53C0(unsigned char *p);
void func_021D53C8(unsigned char *p);
int func_021D53DC(signed char *p);
u8 func_021D5440(u8 *p);
u16 func_021D5444(struct BtlMon *p);
u8 func_021D5448(struct BtlMon *p);
u8 func_021D5450(struct BtlMon *p);
u8 func_021D5478(struct BtlMon *p);
u8 func_021D54B4(u8 *p);
u16 func_021D54C0(struct BtlMon *p, int i);
u32 func_021D54D0(struct BtlMon *p, u8 i);
u32 func_021D54E0(struct BtlMon *p, u32 i);
void func_021D54F4(struct BtlMon *src, struct BtlMon *dst);
u16 func_021D5528(struct BtlMon *p, u8 i, u8 *a, u8 *b);
u8 func_021D554C(struct BtlMon *p, u8 i);
u8 func_021D5568(struct BtlMon *p, u32 i);
u8 func_021D5584(struct BtlMon *p, u32 i);
int func_021D55A0(struct BtlMon *p, int id);
int func_021D55D8(struct BtlMon *p, int i, int s);
void func_021D5608(struct BtlMon *p, int i, u8 n);
void func_021D5640(struct BtlMon *p, u32 i, u32 n);
u16 func_021D5674(struct BtlMon *p, u32 i, u8 n);
u16 func_021D56A0(struct BtlMon *p, u32 i, u8 n);
void func_021D56CC(struct BtlMon *p, int i);
void func_021D5734(struct BtlMon *p, u8 i, u16 a, u8 b, u32 c);
int func_021D5750(struct BtlMon *p, u16 id);
u8 func_021D5778(struct BtlMon *p, u16 id);
void func_021D57A8(u8 *p, u8 *a, u8 *b);
u16 func_021D57FC(void *p);
int func_021D5814(void *p, int k);
void *func_021D5844(void *m);
void func_021D5848(struct BtlMon *p, void *v);
void func_021D5854(struct BtlMon *p);
void *func_021D5864(struct BtlMon *p);
int func_021D587C(void *p, int k);
int func_021D58A8(u8 *p, int k);
void func_021D590C(void **p, u16 *out);
void func_021D5970(u8 *p, int k, u16 v);
int func_021D59B4(u8 *p, int k);
int func_021D5AD8(u8 *p, int k);
u16 func_021D5B40(struct BtlMon *p);
void func_021D5B44(struct BtlMon *p, u16 v);
int func_021D5B48(u8 *p);
int func_021D5B68(void *p);
int func_021D5B7C(void *m);
unsigned short func_021D5BA4(int *p);
int func_021D5BB0(struct BtlMon *p, u32 n);
int func_021D5BDC(struct BtlMon *p, u32 n);
u32 func_021D5C08(struct BtlMon *p);
int func_021D5C30(struct BtlMon *p);
int func_021D5C44(struct BtlMon *p);
s8 *func_021D5CB4(s8 *p, int i, u8 *a, u8 *b);
int func_021D5D14(s8 *p, int i, int sign);
int func_021D5D50(s8 *p, int i);
int func_021D5D68(s8 *p);
u8 func_021D5DC0(s8 *p, int i, u8 n);
extern u8 d_021EFF74[];
extern Pair_021D3E70 d_021EFF94[];
extern Pair_021D3EC8 d_021EFFA0[];
extern struct BtlNet *d_021F3B88;
extern const char d_021F3A98[];
extern const char d_021F3AA4[];
extern const u32 data_021F040C[4];
































int func_021D3A20(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D6730((struct QK *)x, c[1]);
    return 1;
}
































int func_021D3A40(u32 *a, int *b, const u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D6744(x, c[1], c[2], c[3], c[4], c[5]);
    return 1;
}
































int func_021D3A7C(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D5FE4(x, c[1]);
    return 1;
}
































int func_021D3A98(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D6008(x, c[1]);
    return 1;
}
































int func_021D3AB4(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D5FC0((struct BtlMon *)x, c[1]);
    return 1;
}
































int func_021D3AD0(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D6440(x, c[1]);
    return 1;
}
































int func_021D3AEC(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D66D0((struct QJ *)x, c[1]);
    return 1;
}
































int func_021D3B08(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D5B44((struct BtlMon *)x, c[1]);
    return 1;
}
































int func_021D3B28(u32 *a, int *b, const u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D5734((struct BtlMon *)x, c[1], c[4], c[2], c[3]);
    return 1;
}

































/*
 * Leaf with no calls and no pool; 9 instructions, 22 bytes: push {r3, lr}; ldr r1, [r2]; ldr r0, [r0, #4]; lsls r1, r1, #0x18; lsrs r1, r1, #0x18; bl func_021B9934; bl func_021D64F0; movs r0, #1; pop {r3, pc}.
 */
int func_021D3B5C(u8 *p, int b, u32 *q)
{
    func_021D64F0(func_021B9934(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)*q));
    return 1;
}
































int func_021D3B74(u32 *a, int *b, u32 *c)
{
    Slot s;
    s.v = c[1];
    func_021EF9F4((void *)a[13], c[0], s, 0);
    return 1;
}
































int func_021D3B88(u32 *a, int *b, u32 *c)
{
    func_021EFAD8((char *)a[13], c[0], (u8)c[1]);
    return 1;
}
































/*
 * extent: trailing 2-byte alignment padding.
 * ABI: narrow extern arguments follow explicit caller truncation.
 */
int func_021D3B9C(char *p, int unused, unsigned int *a)
{
    func_021EFB34(*(struct BtlNet * *)&((struct BtlNetCtx *)p)->f34, a[0]);
    return 1;
}
































/*
 * extent: compiled 14 bytes followed by 2-byte alignment padding.
 * ABI: narrow extern arguments follow explicit caller truncation.
 */
int func_021D3BB0(char *p, int unused, unsigned int *a)
{
    func_021EFA94(((struct BtlNetCtx *)p)->f34, a[0]);
    return 1;
}
































/*
 * ABI: narrow extern arguments follow explicit caller truncation.
 */
int func_021D3BC0(char *p, int unused, unsigned int *a)
{
    u8 *obj = func_021B9934(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)a[0]);
    func_021D69A0(obj, a[1], a[2]);
    return 1;
}
































int func_021D3BE0(char *p, int unused, unsigned int *a)
{
    u8 *first = func_021B9934(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)a[0]);
    u8 *second = func_021B9934(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)a[1]);
    func_021D65C8((struct BtlMon *)second, (struct BtlMon *)first);
    return 1;
}
































int func_021D3C0C(char *p, int unused, unsigned int *a)
{
    u8 *obj = func_021B9934(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)a[0]);
    func_021D6D5C(obj, a[1]);
    return 1;
}

































/*
 * Leaf with no calls and no pool; 9 instructions, 22 bytes: push {r3, lr}; ldr r1, [r2]; ldr r0, [r0, #4]; lsls r1, r1, #0x18; lsrs r1, r1, #0x18; bl func_021B9934; bl func_021D6D70; movs r0, #1; pop {r3, pc}.
 */
int func_021D3C2C(u8 *p, int b, u32 *q)
{
    func_021D6D70(func_021B9934(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)*q));
    return 1;
}
































int func_021D3C44(u8 *p, int unused, unsigned int *a)
{
    u8 index = a[0];
    u8 value = a[1];
    if (index == p[0x1a6]) func_021CD9F4(p, value);
    else func_021B9B10(*(u8 * *)&((struct BtlNetCtx *)p)->f00, index, value);
    return 1;
}
































int func_021D3C70(char *p, int unused, unsigned int *a)
{
    u8 index = a[0];
    struct Arr *obj = (struct Arr *)func_021B9AEC(*(char * *)&((struct BtlNetCtx *)p)->f04, index);
    func_021B9D10(*(char * *)&((struct BtlNetCtx *)p)->f00, obj, index);
    return 1;
}

































/*
 * Leaf with no calls and no pool; 9 instructions, 22 bytes: push {r3, lr}; ldr r1, [r2]; ldr r0, [r0, #4]; lsls r1, r1, #0x18; lsrs r1, r1, #0x18; bl func_021B9934; bl func_021D6738; movs r0, #1; pop {r3, pc}.
 */
int func_021D3C90(u8 *p, int b, u32 *q)
{
    func_021D6738(func_021B9934(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)*q));
    return 1;
}
































int func_021D3CA8(char *p, int unused, unsigned int *a)
{
    u8 *obj = func_021B9934(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)a[0]);
    func_021D6264((struct UtilSlots *)obj, (u8)a[1]);
    return 1;
}
































/*
 * lever: const source pointer restores the five-load acquisition order.
 * ABI: narrow extern arguments follow explicit caller truncation.
 * Record byte 7 is uninitialized padding, preserved as in the listing.
 */
int func_021D3CC8(char *p, int unused, const unsigned int *a)
{
    struct Rec r;
    u8 *obj;
    u16 x, y;
    u8 z, w, v;
    obj = func_021B9934(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)a[0]);
    x = a[4]; y = a[5]; z = a[3]; w = a[2]; v = a[1];
    r.a = x; r.b = y; r.c = z; r.d = v; r.e = w;
    func_021D6848(obj, (struct Rec *)((struct HalfRec *)&r));
    return 1;
}
































int func_021D3CFC(char *p, int unused, unsigned int *a)
{
    u8 *obj = func_021B9934(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)a[0]);
    func_021D6408(obj);
    func_021D6E88(obj);
    return 1;
}

































/* 021D3D1C  3-arg call on field 0x34, then returns 1 */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; ldr r0, [r0, #0x34]; movs r1, #0; movs r2, #0; bl func_021EFC78; movs r0, #1; pop {r3, pc}.
 */
int func_021D3D1C(u8 *p)
{
    func_021EFC78(((struct BtlNetCtx *)p)->f34, 0, 0);
    return 1;
}
































int func_021D3D2C(char *p, int unused, unsigned int *a)
{
    int index = a[1];
    u8 *obj = func_021B9934(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)a[0]);
    func_021D5970(obj, index, a[2]);
    return 1;
}
































int func_021D3D50(char *p, int unused, unsigned int *a)
{
    u8 *obj = func_021B9934(*(char * *)&((struct BtlNetCtx *)p)->f04, (u8)a[0]);
    func_021D67D8(obj, (u16)a[1]);
    return 1;
}

































/*
 * ldrb at #0x1a6 (pool constant)
 */
u8 func_021D3D70(u8 *p)
{
    return ((struct BtlNetCtx *)p)->f1a6;
}
































/*
 * Claimed follower 021D3D84 is included; target byte accessor has a verified shard.
 */
u32 func_021D3D7C(u8 *p) { return ((struct BtlNetCtx *)p)->f118; }
































u8 func_021D3D84(u8 *p) { return func_021EF9A8(*(u32 * *)&((struct BtlNetCtx *)p)->f34); }

































/*
 * ldrb at #0x1ab (pool constant)
 */
u8 func_021D3D90(u8 *p)
{
    return ((struct BtlNetCtx *)p)->f1ab;
}
































/*
 * Byte narrowing before call proves u8 third argument despite wide callee definition.
 */
void func_021D3D9C(u8 *p) {
    u32 i;
    for(i=0;i<4;i++) *(u16 *)(p+i*2+0xe8)=func_021B9F84(*(char * *)&((struct BtlNetCtx *)p)->f00,p[0x1a6],(u8)i);
}

































u32 func_021D3DC4(u8 *a, void *b, void *c)
{
    u32 i;
    u32 r;
    u32 v;
    u32 lim;
    u32 off;
    u8 *t;

    lim = func_021B9B94(c);
    if (func_021D62C4(b, 0x13) != 0)
        return 0;
    for (i = 0; i < 4; i++) {
        if (d_021EFF74[i] < lim)
            break;
        off = i * 2;
        if (*(u16 *)(a + off + 0xe8) != 0) {
            r = 0;
            if (func_021D805C((void *)(u32)*(u16 *)(a + off + 0xe8), 0x29) != 0) {
                r = func_021D59B4(b, 0xd);
                if (r > func_021D7B60(b, 4))
                    continue;
                r = 1;
            } else {
                if (func_021D3E70((void *)(u32)*(u16 *)(a + off + 0xe8), b) != 0)
                    r = 1;
                else if (func_021D3EC8((void *)(u32)*(u16 *)(a + off + 0xe8), b) != 0)
                    r = 1;
            }
            if (r != 0) {
                t = a + 0xe8;
                v = *(u16 *)(t + off);
                *(u16 *)(t + off) = 0;
                return v;
            }
        }
    }
    return 0;
}

































int func_021D3E70(void *s, void *m)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        if (func_021D805C(s, d_021EFF94[i].a) != 0 && func_021D5D14(m, d_021EFF94[i].b, 1) != 0)
            return 1;
    }
    if (func_021D805C(s, 0x24) != 0 && func_021D5F14(m) == 0)
        return 1;
    return 0;
}
































int func_021D3EC8(void *s,struct Unk021D62A8 *m) { u32 i; for(i=0;i<7;i++) if(func_021D805C(s,d_021EFFA0[i].a) && func_021D62C4(m,d_021EFFA0[i].b)) return 1; return 0; }

































void func_021D3F04(struct BtlNetEntry *p)
{
    p->b1 = 0;
    p->f3 = 0;
    p->b0 = 0;
    p->f1 = 0;
    p->h6 = 0;
    p->f2 = 0;
    p->h8 = 0;
    p->f0 = 0;
    p->h10 = 0;
    p->f4 = 0;
    p->f5 = 0;
    p->h12 = 0;
    p->h4 = 0;
}

































/*
 * strh v at #0xa
 */
void func_021D3F48(u8 *p, u32 v)
{
    *(u16 *)&p[0xa] = v;
}
































int func_021D3F4C(struct BtlNetEntry *p)
{
    return p->f2;
}
































/*
 * Extent follower 021D3F60 is already filed separately.
 */
void func_021D3F54(u8 *p) { p[2] |= 8; }
































/*
 * extent: Parent approved only the bounded four-byte accessor. Unapproved
 * followers 021D3F64 and 021D3F88, matched 021D3F98 and code 021D3FA8 follow;
 * no follower is included in this source.
 */
u8 func_021D3F60(u8 *p)
{
    return p[1];
}
































/*
 * note 2026-10-05: object is the same 14-byte record as func_021D3F04 (bit flags in byte 2).
 *   Sets h8 = v, bit0 = 1, h12 = 0, clears bits 1 and 2. Source order h12 = 0 before h8 = v:
 *   the scheduler hoists the strh, and r1 (v) stays live so the zero takes r2.
 */
void func_021D3F64(struct BtlNetEntry *p, u16 v)
{
    p->f0 = 1;
    p->h12 = 0;
    p->h8 = v;
    p->f1 = 0;
    p->f2 = 0;
}
































/*
 * Extent follower 021D3F98 is already filed separately; bitfield clear produces bics.
 */
void func_021D3F88(struct BtlNetEntry *p) { p->b0=0; p->f0=0; }
































int func_021D3F98(u8 *p)
{
    if (((struct Obj13430 *)p)->fC == ((struct Obj13430 *)p)->f8) return 1;
    return 0;
}

































/*
 * ldrh at #0x8
 */
u16 func_021D3FA8(u8 *p)
{
    return *(u16 *)&p[0x8];
}
































/*
 * extent: Twenty-two code bytes plus two zero padding bytes at 021D3FC2;
 * the approved separate 021D3FC4 leaf and existing 021D3FD0 follow.
 */
int func_021D3FAC(struct BtlNetEntry *p)
{
    if (p->f1) return 0;
    p->f4 = 1;
    return 1;
}
































/*
 * match-note: Clearing the unsigned-char bitfield emits bics #0x10;
 * raw p[2] &= ~0x10 emits ands #0xef and was four bytes out.
 * extent: Ten bytes of code, two zero padding bytes at 021D3FCE, then
 * existing matched func_021D3FD0 at 021D3FD0; no follower included.
 */
void func_021D3FC4(struct BtlNetEntry *p)
{
    p->f4 = 0;
}
































void func_021D3FD0(unsigned char *p)
{
    p[2] |= 0x20;
}
































/*
 * note 2026-10-05: now verifies EXACT (func_021F8B10 resolves).
 * match-note: A goto to the bottom epilogue reproduces the entry guards;
 * input is called before adjusted=0, preserving the original scheduling.
 */
void func_021D3FDC(u8 *p, struct Q *q)
{
    int changed, adjusted, input;
    if (p[0x1a7] != 2 || q->flag4 || q->flag5 || !q->maximum) goto done;
    changed = 0;
    if (q->flag3) {
        q->flag3 = 0;
        if (!q->flag0) {
            if (q->current < q->maximum && q->state == 0) {
                ++q->current;
                if (!q->delay) q->target = q->current;
                changed = 1;
            }
        } else {
            if (q->tick < q->target) {
                ++q->tick;
                if (q->tick == q->target) {
                    q->current = q->target;
                    if (*(void **)(p+0x54)) func_021EAE74(*(void **)(p+0x54),q->current,q->target);
                }
            }
            return;
        }
    }
    if (!q->current || !*(void **)(p+0x54)) return;
    switch (q->state) {
    case 0:
        input = func_021EAE64(*(void **)(p+0x54));
        adjusted = 0;
        switch (input) {
        case 2:
            q->mode = 1;
            func_021EAE04(*(void **)(p+0x54));
            q->flag1 = 1;
            q->state = 1;
            func_021EAECC(*(void **)(p+0x54),q->current,1);
            func_02005E30(30);
            func_02005CA4(0,62);
            func_02006734(0);
            func_021F8B10();
            func_021B92A0((u8 *)(*(u32 *)p));
            break;
        case 0:
            if (q->target > 1) { --q->target; adjusted = 1; }
            q->delay = 45;
            break;
        case 1:
            if (q->target < q->maximum) { ++q->target; adjusted = 1; }
            q->delay = 45;
            break;
        }
        if (adjusted || changed) func_021EAE74(*(void **)(p+0x54),q->current,q->target);
        if (q->delay) {
            --q->delay;
            if (!q->delay) {
                q->mode = 2;
                func_021EAE04(*(void **)(p+0x54));
                q->flag1 = 1;
                q->state = 1;
                func_02005E30(30);
                func_02005CA4(0,62);
                func_02006734(0);
                func_021F8B10();
            }
        }
        break;
    case 1:
        if (func_021EAE14(*(void **)(p+0x54))) { q->flag2 = 1; q->state = 2; }
        break;
    case 2:
        break;
    }
done:
    return;
}
































/*
 * lever: Separate loop counters; use the first counter's initialized zero
 * for f0d/f0e stores before entering that loop.
 */
void func_021D4150(void *link, u16 mask, u16 heap)
{
    u32 count, i, j, k, limit;
    if (link) {
        d_021F3B88 = func_02030734(heap, 0x3b2c, 1, d_021F3A98, 0xd4);
        d_021F3B88->link = link;
        d_021F3B88->mask = mask;
        d_021F3B88->heap = heap;
        d_021F3B88->id = func_0203D1A4(link);
        d_021F3B88->f07 = 0x28;
        i = 0;
        d_021F3B88->f0d = i;
        d_021F3B88->f0e = i;
        count = 0;
        for (; i < 4; i++) if (mask & (1U << i)) count++;
        limit = func_0203D1B4();
        if (count > limit) count = limit;
        d_021F3B88->count = count;
        d_021F3B88->f0f = 0;
        d_021F3B88->f10 = 0;
        d_021F3B88->f0a = 0;
        for (j = 0; j < 4; j++) {
            d_021F3B88->tblA[j] = 0;
            d_021F3B88->tblB[j] = 0;
            d_021F3B88->states[j] = 4;
        }
        for (k = 0; k < 4; k++) d_021F3B88->tblC[k] = 0;
        d_021F3B88->f3b14 = 0;
        d_021F3B88->f3b18 = 0;
        func_021D4AF4(1);
    } else d_021F3B88 = 0;
}
































int func_021D4230(void) { int r; if(d_021F3B88) { r=1; if(func_021D4B18(1)==0) r=0; return r; } return 1; }
































void func_021D4254(void) { if(d_021F3B88) { func_021D4A6C(); func_020307B0(d_021F3B88); } }
































int func_021D4270(void) { if(d_021F3B88) { if(func_0200FB24()) return 1; return 0; } return 0; }






























int func_021D4294(u16 v)
{
    u16 *b = d_021F3B88->u.buf;
    b[0] = 0x64;
    b[1] = v;
    return func_0203D3A8(d_021F3B88->link, 0x100, 4, (u32)((void *)b));
}






























void func_021D42BC(int idx, int unused, u16 *data)
{
    struct BtlNet *d = d_021F3B88;
    struct BtlNetSync *s = &d->sync;
    int i;

    if (s->e[idx].ok == 0) {
        u16 v = data[0];
        d->states[idx] = data[1];
        s->e[idx].val = v;
        s->e[idx].ok = 1;
        if (s->mx < v)
            s->mx = v;
        s->n++;
        if (s->n >= d_021F3B88->count) {
            d_021F3B88->f07 = 0x28;
            for (i = 0; i < 4; i++) {
                if (s->e[i].ok != 0 && s->mx == s->e[i].val) {
                    d_021F3B88->f07 = i;
                    return;
                }
            }
        }
    }
}






























u8 func_021D4330(int i)
{
    return d_021F3B88->sync.e[i].ok;
}






























int func_021D4348(void)
{
    if (d_021F3B88->f07 != 0x28)
        return 1;
    return 0;
}






























int func_021D4360(void)
{
    if (d_021F3B88->f07 == d_021F3B88->id)
        return 1;
    return 0;
}






























u8 func_021D4378(void)
{
    struct BtlNet *p = d_021F3B88;

    if (p != 0)
        return p->sync.mx;
    return 100;
}





























/*
 * Unlabelled leaf (no push), filed as the blocker of func_021D4B58.
 */
u8 func_021D4394(u32 a)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (a == d_021F3B88->states[i]) {
            return (u8)i;
        }
    }
    return 0x28;
}





























u32 func_021D43B8(u32 a)
{
    return func_0203D3F8((u32)d_021F3B88->link, 0xff, 0x101, 0x20, a, 0, 0, 0);
}





























/*
 * Unlabelled leaf (no lr prologue, hidden in the pool run after
 * func_021D43B8).  Copies a 32-byte aggregate into the object at
 * d_021F3B88+0x18 once, gated on byte +0xa.
 */
void func_021D43E0(int unused0, int unused1, S32 *src)
{
    if (d_021F3B88->f0a == 0) {
        d_021F3B88->f18 = *src;
        d_021F3B88->f0a = 1;
    }
}





























/*
 * Unlabelled leaf (hidden in the pool run after func_021D43E0): if the
 * object at d_021F3B88 has byte +0xa set, copies its 32-byte aggregate
 * at +0x18 into dst and returns 1, else returns 0.
 */
int func_021D440C(S32 *dst)
{
    if (d_021F3B88->f0a != 0) {
        *dst = d_021F3B88->f18;
        return 1;
    }
    return 0;
}


























u8 func_021D4438(u32 a) { u32 r; r=func_0201A918(); return func_0203D3F8((u32)d_021F3B88->link,255,0x102,r,a,0,1,1); }


























void *func_021D446C(int idx, int unused, u32 size)
{
    d_021F3B88->tblA[idx] = sub_02030734((u16)((d_021F3B88->heap & 0x7fff) | 0x8000), size, 1, d_021F3A98, 0x1ce);
    return d_021F3B88->tblA[idx];
}


























void func_021D44B4(int idx, void *p)
{
    d_021F3B88->tblB[idx] = p;
}
























int func_021D44CC(void) { int i; for(i=0;i<4;i++) if(func_021D4330(i) && d_021F3B88->tblB[i]==0) return 0; return 1; }

























void func_021D4500(void)
{
    func_021D4CEC();
    func_021D4A6C();
}

























u32 func_021D450C(u32 *a)
{
    u32 t;

    if (func_02007B50((void **)a) != 0) {
        t = func_02007B00();
    } else {
        t = 4;
        a = &d_021F3B88->u.f3b1c;
        *a = 0;
    }
    return func_0203D3F8((u32)d_021F3B88->link, 0xff, 0x103, t, (u32)a, 0, 1, 1);
}
























void *func_021D4558(int idx, int unused, u32 size)
{
    if (size == 4)
        return &d_021F3B88->peer[idx];
    d_021F3B88->tblA[idx] = sub_02030734((u16)((d_021F3B88->heap & 0x7fff) | 0x8000), size, 1, d_021F3A98, 0x21f);
    return d_021F3B88->tblA[idx];
}
























/*
 * Unlabelled leaf (hidden in the pool run after func_021D4558).  Setter
 * through d_021F3B88: a special value for b==4, otherwise a plain u32
 * store.
 */
void func_021D45B8(int a, int b)
{
    if (b == 4) {
        struct BtlNetRec *q = &d_021F3B88->peer[a];
        q->fBB8 = b;
        q->fBBA = 0;
    } else {
        d_021F3B88->tblB[a] = (void *)b;
    }
}






















int func_021D45FC(void)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (func_021D4330(i) != 0 && d_021F3B88->peer[i].fBBA != 0 && d_021F3B88->tblB[i] == 0)
            return 0;
    }
    return 1;
}





















/*
 * Indexed struct arrays preserve scaled-index-before-base-load order.
 */
u32 func_021D4648(u32 a) { u32 r; r=func_021D4394(a); if(r!=40) { if(d_021F3B88->tblB[r]) return (u32)d_021F3B88->tblA[r]; } return 0; }






















void func_021D4674(void)
{
    func_021D4CEC();
    func_021D4A6C();
}



















u32 func_021D4680(u32 *a) { return func_0203D3F8((u32)d_021F3B88->link,255,0x104,(*a>>8)+4,(u32)a,0,1,1); }



















void *func_021D46B0(int a, int b, u32 size)
{
    if (d_021F3B88->f3b14 == 0)
        d_021F3B88->f3b14 = sub_02030734((u16)((d_021F3B88->heap & 0x7fff) | 0x8000), size, 1, d_021F3A98, 0x279);
    return d_021F3B88->f3b14;
}



















/*
 * Lever: the message header is read as bitfields (type:8, size:24) through a `const`
 * pointer. Plain `(u8)*c` / `*c >> 8` loads *c before &d (8 bytes out); bitfields through a
 * non-const pointer put &d first but reload *c for the size; `const` lets the size share
 * the first load (const-pointer-lets-a-field-load-survive-a-store.md).
 *
 * Message handler: ensures d->tblC[type] is allocated (sub_02030734 with size, tag 0x282),
 * copies the payload (c+1) into it, frees d->f3b14 and clears it.
 */
void func_021D46FC(u32 a, u32 b, const Hdr_021D3A20 *c)
{
    if (d_021F3B88->tblC[c->h.type] == 0) {
        d_021F3B88->tblC[c->h.type] = sub_02030734((u16)((d_021F3B88->heap & 0x7fff) | 0x8000), c->h.size, 1, d_021F3A98, 0x282);
    }
    MI_CpuCopy8(c + 1, d_021F3B88->tblC[c->h.type], c->h.size);
    func_020307B0(d_021F3B88->f3b14);
    d_021F3B88->f3b14 = 0;
}


















int func_021D4784(u32 a)
{
    if (d_021F3B88->tblC[a]) return 1;
    return 0;
}

















void *func_021D47A4(u8 a)
{
    u32 idx = func_021D4394(a);
    void *p;
    u32 n;
    u32 i;

    if (idx != 0x28) {
        return d_021F3B88->tblA[idx];
    }
    p = d_021F3B88->tblC[a];
    if (p != 0) {
        n = func_0201AA18(p);
        for (i = 0; i < n; i++) {
            func_0201AB28(p, i);
        }
        return p;
    }
    return 0;
}
















void func_021D4800(void)
{
    func_021D4A6C();
}
















int func_021D4808(u32 a)
{
    u32 r = func_02008468();
    return func_0203D3F8((u32)d_021F3B88->link, 255, 0x105, r, a, 0, 1, 1);
}















void *func_021D4838(int idx, int unused, u32 size)
{
    d_021F3B88->tblA[idx] = sub_02030734((u16)((d_021F3B88->heap & 0x7fff) | 0x8000), size, 1, d_021F3A98, 0x2d4);
    return d_021F3B88->tblA[idx];
}














void func_021D4880(int idx, void *p)
{
    d_021F3B88->tblB[idx] = p;
}














int func_021D4898(void)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (func_021D4330(i) != 0 && d_021F3B88->tblB[i] == 0)
            return 0;
    }
    return 1;
}














void *func_021D48CC(u8 a)
{
    int i = func_021D4394(a);
    void *p;
    if (i != 0x28) return d_021F3B88->tblA[i];
    p = d_021F3B88->f3b14;
    if (p != 0 && d_021F3B88->f3b18 != 0) return p;
    return 0;
}














u32 func_021D4908(void *a)
{
    void *o;
    u32 r;

    o = (void *)func_021D4A0C((In *)a, (u16)((d_021F3B88->heap & 0x7fff) | 0x8000));
    r = func_0203D3F8((u32)d_021F3B88->link, 0xff, 0x106, 0x6c, (u32)o, 0, 1, 0);
    func_021D4A64(o);
    return r;
}














/*
 * Read the 0x7fff-wide field at +4 of the structure the global pointer
 * 0x021F3B88 holds, set its top bit, and hand the (u16) of it to the ARM
 * helper 0x02030734 as (value, c, 1, 0x021F3A98, 0x031E).  The helper's
 * result is stored at +0x3b14 and read straight back out.
 */
u32 func_021D4954(void *a, int b, int c)
{
    u32 v = (u16)(0x8000 | (d_021F3B88->heap & 0x7fff));
    u32 r = (u32)func_02030734(v, c, 1, (const char *)0x021f3a98, 0x31e);

    d_021F3B88->f3b14 = (void *)r;
    return (u32)d_021F3B88->f3b14;
}












void func_021D499C(int unused, void *p)
{
    d_021F3B88->f3b18 = p;
}












/*
 * Unlabelled leaf called by func_021B7968 (+0x1E4): reports whether the
 * pending object word at +0x3b18 of the d_021F3B88 block is set; the
 * block layout follows ov093_func_021D49E0.c.
 */
int func_021D49B0(void)
{
    if (d_021F3B88->f3b18)
        return 1;
    return 0;
}













/*
 * Unlabelled leaf called by func_021B7968 (+0x1EC): returns the object
 * word at +0x3b14 of the d_021F3B88 block (the word func_021D49E0 frees).
 */
void *func_021D49CC(void)
{
    return d_021F3B88->f3b14;
}













/*
 * Extent follower 021D4A04 is a tail-call stub; function_start seed.
 */
void func_021D49E0(void)
{
    func_020307B0(d_021F3B88->f3b14);
    d_021F3B88->f3b14 = 0;
    d_021F3B88->f3b18 = 0;
}













void func_021D4A04(void)
{
    func_021D4A6C();
}













Out *func_021D4A0C(In *a, u32 heap)
{
    Out *o = sub_02030734(heap, 0x6c, 1, d_021F3A98, 0x349);

    MI_CpuCopy8(a, o, 0x28);
    MIi_CpuClear16(func_02045A98(), o->f28, 0x40);
    if (a->f14 != 0) {
        o->f68 = sub_020458F8(a->f14);
        sub_0201F41C(sub_02045A90(a->f14), (u16 *)o->f28, 0x20);
    }
    return o;
}












void func_021D4A64(void *p)
{
    func_020307B0(p);
}












void func_021D4A6C(void)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (d_021F3B88->tblA[i] != 0) {
            func_020307B0(d_021F3B88->tblA[i]);
            d_021F3B88->tblA[i] = 0;
            d_021F3B88->tblB[i] = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        if (d_021F3B88->tblC[i] != 0) {
            func_020307B0(d_021F3B88->tblC[i]);
            d_021F3B88->tblC[i] = 0;
        }
    }
    if (d_021F3B88->f3b14 != 0) {
        func_020307B0(d_021F3B88->f3b14);
        d_021F3B88->f3b14 = 0;
        d_021F3B88->f3b18 = 0;
    }
}









void func_021D4AF4(int a)
{
    if (d_021F3B88 != 0) {
        d_021F3B88->f0f = a;
        d_021F3B88->f10 = 1;
        func_0203A424(d_021F3B88->link, a, 1, d_021F3B88->mask);
    }
}









int func_021D4B18(int a)
{
    struct BtlNet *p = d_021F3B88;
    int r;

    if (p != 0) {
        if (p->f10 != 0) {
            r = func_02039CB4((struct Link *)p->link, p->f0f, 1);
            if (r != 0) {
                d_021F3B88->f0f = 0;
                d_021F3B88->f10 = 0;
                return r;
            }
        } else {
            func_0203A424(p->link, a, 1, p->mask);
        }
        return 0;
    }
    return 1;
}








u32 func_021D4B58(u32 a, u32 b, u32 c)
{
    u32 r = func_021D4394(a);

    if (r != 0x28) {
        return func_0203D3F8((u32)d_021F3B88->link, r, 0x107, c, b, 0, 0, 1);
    }
    return 1;
}







int func_021D4B98(void)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (func_021D4330(i) != 0 && d_021F3B88->peer[i].fBBA != 0)
            return 0;
    }
    return 1;
}








/*
 * Index a 0xBBC-stride table hanging off the pointer global at 0x021F3B88
 * plus 0xBF4, return the element's +0xBB8 halfword through *q.  The image
 * reaches 0xBBC and 0xBB8 by subtracting 0x38 and 0x3c from the 0xBF4 it
 * already has in r2 (mwcc's constant reuse), which the same expression here
 * reproduces.
 */
u16 func_021D4BD4(int a, u8 **q)
{
    struct BtlNetRec *r = &d_021F3B88->peer[func_021D4394(a)];
    *q = (u8 *)r;
    return r->fBB8;
}






/*
 * evidence: 0203159C leaves its allocation in r0, read here despite legacy void.
 * 021D4D38 r2 is explicitly loaded here and retained in the extern.
 */
struct BtlNetRec *func_021D4BFC(int idx)
{
    return &d_021F3B88->peer[idx];
}






void func_021D4C14(int idx, u32 v)
{
    struct BtlNetRec *r = &d_021F3B88->peer[idx];
    r->fBB8 = (u16)v;
    r->fBBA = 0;
    d_021F3B88->peer[idx].fBB8 = (u16)v;
    d_021F3B88->peer[idx].fBBA = 0;
}






/*
 * tail-call thunk to func_021D4CEC
 */
void func_021D4C58(u32 a)
{
    func_021D4CEC();
}







unsigned char func_021D4C60(void)
{
    return d_021F3B88->f0d;
}






u16 func_021D4C6C(u8 **out)
{
    struct BtlNetRec *r = &d_021F3B88->rec0;
    *out = (u8 *)r;
    return r->fBB8;
}





u32 func_021D4C84(u32 a, u32 b)
{
    struct BtlNet *p = d_021F3B88;
    u32 r;

    r = func_0203D3F8((u32)p->link, p->f07, 0x108, b, a, 0, 1, 1);
    if (r != 0) {
        p = d_021F3B88;
        p->f0d = 0;
    }
    return r;
}




void func_021D4CB8(int unused, u32 v)
{
    struct BtlNet *d = d_021F3B88;

    if (d->f0d == 0) {
        struct BtlNetRec *r = &d->rec0;
        r->fBB8 = (u16)v;
        r->fBBA = 0;
        d_021F3B88->f0d = 1;
    }
}




struct BtlNetRec *func_021D4CE0(void)
{
    return &d_021F3B88->rec0;
}




/*
 * Lever: shared entry pointer, based at +0xbf4, preserves the single
 * global read and the +0xbb8/+0xbba field offsets within each iteration.
 */
void func_021D4CEC(void)
{
    int i;
    for (i = 0; i < 4; i++) {
        struct BtlNetRec *r = &d_021F3B88->peer[i];
        r->fBB8 = 0;
        r->fBBA = 1;
    }
}







void *func_021D4D24(u32 a, u16 b)
{
    Hdr_021D4CB8 *h = sub_02030734(b, a + 4, 1, d_021F3A98, 0x477);

    h->size = a;
    h->type = 4;
    return h;
}






void func_021D4D5C(void *p) { func_020307B0(p); }






void func_021D4D64(u32 *p, const void *src, u32 a)
{
    *p = (*p & ~255u) | (u8)a;
    func_02082D44(src, p + 1, *p >> 8);
}




/*
 * 2026-10-03 (wave B3 lane 03): EXACT. func_021D7D18 returns a one-word
 * union by value (as in its own matched definition). That return reserves
 * the frame word (push r4-r6 + sub sp,#8) and also stops mwcc from deriving
 * 0x272 from the hoisted 0x1f8 and 0x143 from the argument 0x9e, which was
 * the whole earlier DIFF. With a u32 return every spelling of the body
 * keeps the constant chain (push r3-r7).
 */
struct BtlMon *func_021D4D84(void *a, u8 b, u32 c)
{
    struct BtlMon *p;
    u32 n;

    p = sub_02030734(c, 0x1f8, 1, d_021F3AA4, 0xe3);
    p->f19 = b;
    p->f0c = func_02017E1C(a, 5, 0);
    p->f00 = a;
    p->f10 = func_02017E1C(a, 0xa0, 0);
    p->f0e = func_02017E1C(a, 0xa1, 0);
    p->f12 = func_02017E1C(a, 6, 0);
    if (p->f12 > 0x272) p->f12 = 0;
    p->f14 = 0;
    p->b5 = 0;
    p->f04 = 0;
    p->b6 = 0;
    p->b7 = 0;
    p->lo = func_02017E1C(a, 0x6f, 0);
    p->f16 = func_02017E1C(a, 0xa, 0);
    p->f18 = func_02017E1C(a, 0x9e, 0);
    p->f1a = func_02019C90(p->f0c, p->lo, 1);
    func_021D4EFC(p, a, 1, 1);
    p->n140 = func_021D4F84(p, a, 1);
    p->f143 = 0;
    func_021D53C0(p->f0fc);
    func_021D63B8((u8 *)p, 1);
    n = func_02017F90(a);
    if (n != 0) {
        p->w1c[n] = func_021D7D18(n);
        *((u8 *)p + 0xac + n) = 0;
    }
    p->f148 = 10000;
    p->f146 = 0;
    p->f1f2 = 0;
    p->f14a = 0;
    p->f14c = 0;
    p->f144 = 0x11;
    p->f14e = 0;
    p->f1f4 = 0;
    p->f1f6 = 0x1f;
    p->f142 = 0;
    MI_CpuFill8(p->f153, 0, sizeof(p->f153));
    MI_CpuFill8(p->f155, 0, sizeof(p->f155));
    func_021D67F4((u8 *)p);
    func_021D6DC4((u8 *)p);
    return p;
}






void func_021D4EFC(struct BtlMon *a, void *mon, u32 c, u32 d)
{
    if (c != 0) {
        a->f10 = func_02017E1C(mon, 0xa0, 0);
        a->f0e = func_02017E1C(mon, 0xa1, 0);
    }
    a->f08 = func_02017E1C(mon, 8, 0);
    func_021D52B4(a, mon, d);
    if (d != 0) {
        a->f13c = func_02017E1C(mon, 0xa, 0);
    }
    a->f141 = func_02017E1C(mon, 0x6f, 0);
    a->f13e = func_02019C90(a->f0c, a->f141, 0x26);
    if (a->f13e < 1) {
        a->f13e = 1;
    }
}





int func_021D4F84(struct BtlMon *p, void *h, int reset)
{
    u8 t = func_02017D30(h);
    u32 count = 0;
    u32 i;
    if (reset) {
        for (i = 0; i < 4; i++) {
            p->e[i].cur.lo = 0;
            p->e[i].cur.hi = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        if (func_021D5244(&p->e[i].cur, h, i)) count++;
    }
    if (reset) {
        for (i = 0; i < 4; i++) {
            p->e[i].h[3] = p->e[i].h[0];
            p->e[i].h[4] = p->e[i].h[1];
            p->e[i].h[5] = p->e[i].h[2];
            p->e[i].fC = 1;
        }
    }
    func_02017D70(h,t);
    return count;
}






void func_021D505C(struct BtlMon *a)
{
    void *mon = a->f00;
    u32 i;

    for (i = 0; i < 4; i++) {
        func_020181F4(mon, a->e[i].cur.id, (u8)i);
        func_02017E40(mon, 0x3a + i, a->e[i].cur.pp);
        func_02017E40(mon, 0x3e + i, a->e[i].cur.ppUp);
    }
}






void func_021D50B4(struct BtlMon *p)
{
    void *h = p->f00;
    u32 i;
    p->n140 = 0;
    for (i = 0; i < 4; i++) {
        if (func_021D5244(&p->e[i].cur, h, i)) p->n140++;
        if (p->e[i].fC != 0) {
            p->e[i].h[3] = p->e[i].h[0];
            p->e[i].h[4] = p->e[i].h[1];
            p->e[i].h[5] = p->e[i].h[2];
        }
    }
}






void func_021D5150(struct BtlMon *p)
{
    u32 i;
    p->n140 = 0;
    for (i = 0; i < 4; i++) {
        p->e[i].h[3] = p->e[i].h[0];
        p->e[i].h[4] = p->e[i].h[1];
        p->e[i].h[5] = p->e[i].h[2];
        if (p->e[i].h[3] != 0) p->n140++;
        p->e[i].fC = 1;
    }
}





/* 021D51CC  first round: `p[x] &= ~0xf` narrowed the mask to 0xf0 and used
 * ands; the image keeps a 32-bit intermediate and bics with 0xf. */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: ldrb r2, [r0, #0xb]; movs r1, #0xf; bics r2, r1; strb r2, [r0, #0xb]; ldrb r2, [r0, #5]; bics r2, r1; strb r2, [r0, #5]; bx lr.
 */
void func_021D51CC(u8 *p)
{
    u32 v;
    v = p[0xb];
    v &= ~0xf;
    p[0xb] = v;
    v = p[5];
    v &= ~0xf;
    p[5] = v;
}




void func_021D51DC(struct BtlMoveSlot *p, u32 a, u32 b, u32 c)
{
    if (c != 0) {
        func_021D5208(&p->cur, a, b);
        if (p->fC != 0) {
            p->h[3] = p->h[0];
            p->h[4] = p->h[1];
            p->h[5] = p->h[2];
        }
    } else {
        func_021D5208(&p->saved, a, b);
        p->fC = 0;
    }
}





void func_021D5208(struct BtlMoveInfo *p, u32 a, u32 b)
{
    p->id = a;
    p->lo = 0;
    p->hi = 0;
    if (a != 0) p->ppMax = func_0201C158(a, 0);
    else p->ppMax = 0;
    if (b != 0 && p->ppMax > b) p->ppMax = b;
    p->pp = p->ppMax;
}






int func_021D5244(struct BtlMoveInfo *e, void *h, u8 k)
{
    int r = 1;
    u16 v = func_02017E1C(h, k + 0x36, 0);
    if (e->id != v) {
        e->lo = 0;
        e->hi = 0;
    }
    e->id = v;
    if (e->id != 0) {
        e->pp = func_02017E1C(h, k + 0x3a, 0);
        e->ppMax = func_02017E1C(h, k + 0x42, 0);
        e->ppUp = func_02017E1C(h, k + 0x3e, 0);
    } else {
        r = 0;
        e->pp = 0;
        e->ppMax = 0;
        e->ppUp = 0;
    }
    return r;
}






void func_021D52B4(struct BtlMon *p, void *h, u32 flag)
{
    if (flag) {
        p->ff8 = func_02017E1C(h, 0xae, 0);
        p->ff9 = func_02017E1C(h, 0xaf, 0);
    }
    p->ffa = func_02017F00(h);
    ((struct BtlMon *)p)->fee = func_02017E1C(h, 0xa2, 0);
    ((struct BtlMon *)p)->ff0 = func_02017E1C(h, 0xa3, 0);
    ((struct BtlMon *)p)->ff2 = func_02017E1C(h, 0xa5, 0);
    ((struct BtlMon *)p)->ff4 = func_02017E1C(h, 0xa6, 0);
    ((struct BtlMon *)p)->ff6 = func_02017E1C(h, 0xa4, 0);
}





void func_021D533C(struct BtlMon *p)
{
    if (p->b5 != 0) {
        func_021D4EFC(p, p->f00, 0, 1);
        func_021D5150(p);
        p->b5 = 0;
    }
}






void func_021D5364(struct BtlMon *p)
{
    u32 i;
    for (i = 0; i < 4; i++) func_021D51CC((u8 *)(&p->e[i]));
    p->f14a = 0;
    p->f14c = 0;
    p->f144 = 0x11;
    p->f14e = 0;
}






void func_021D539C(struct BtlMon *p)
{
    u32 i;
    for (i = 0; i < 5; i++) p->f157[i] = 0;
}






/*
 * tail-call thunk to func_020307B0
 */
void func_021D53B8(void *p)
{
    func_020307B0(p);
}






/*
 * tail-call thunk to func_021D53C8
 */
void func_021D53C0(unsigned char *p)
{
    func_021D53C8(p);
}




/*
 * Unlabelled ov093 leaf: writes 6 into the first seven bytes of its argument.
 * Matched to provide the `matched` witness for the two pending files that call
 * it (func_021D53C0, func_021D5F08).
 */
void func_021D53C8(unsigned char *p)
{
    p[0] = 6;
    p[1] = 6;
    p[2] = 6;
    p[3] = 6;
    p[4] = 6;
    p[5] = 6;
    p[6] = 6;
}




int func_021D53DC(signed char *p)
{
    int changed = 0;
    int i = 0;
    if (p[i] < 6) { p[i] = 6; changed = 1; }
    i = 1;
    if (p[i] < 6) { p[i] = 6; changed = 1; }
    i = 2;
    if (p[i] < 6) { p[i] = 6; changed = 1; }
    i = 3;
    if (p[i] < 6) { p[i] = 6; changed = 1; }
    i = 4;
    if (p[i] < 6) { p[i] = 6; changed = 1; }
    i = 5;
    if (p[i] < 6) { p[i] = 6; changed = 1; }
    i = 6;
    if (p[i] < 6) { p[i] = 6; changed = 1; }
    return changed;
}





/* 021D5440  ldrb r0,[r0,#0x19] */
/*
 * Reads the u8 field at #0x19 of the argument and returns it.
 */
u8 func_021D5440(u8 *p) { return p[0x19]; }




/*
 * Reads the u16 field at #0xc of the argument and returns it.
 */
u16 func_021D5444(struct BtlMon *p) { return p->f0c; }




/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #5; lsls r1, r1, #6; ldrb r0, [r0, r1]; bx lr.
 */
u8 func_021D5448(struct BtlMon *p) { return p->n140; }





/*
 * volatile: 0x021D54A6 (n140 re-read as the loop bound of func_021D5478)
 */
u8 func_021D5450(struct BtlMon *p)
{
    u32 n;
    u32 i;
    i = 0;
    n = 0;
    for (; i < 4; i++) {
        if (p->e[i].cur.id == 0) break;
        n++;
    }
    return n;
}





u8 func_021D5478(struct BtlMon *p)
{
    u8 n;
    u8 i;
    i = 0;
    n = 0;
    for (; i < *(volatile u8 *)&p->n140; i++) {
        if (p->e[i].saved.lo != 0) n++;
    }
    return n;
}





/*
 * ldrb at #0x143 (pool constant)
 */
u8 func_021D54B4(u8 *p)
{
    return ((struct BtlMon *)p)->f143;
}





/*
 * lever: the halfword is the first member of a 14-byte record in the array
 * at +0x10a; the image's `adds r2,#0xfc` is the constant 0x10a folded with
 * the stride, not a +0xa field.
 */
u16 func_021D54C0(struct BtlMon *p, int i)
{
    return p->e[i].saved.id;
}




u32 func_021D54D0(struct BtlMon *p, u8 i) { return p->e[i].cur.id; }




/* 021D54E0  the image extracts with lsls #0x1c / lsrs #0x1c, which is a 4-bit
 * unsigned bitfield read -- neither `& 0xf` nor the shift pair written out in
 * C reproduces it (both narrow to a mask). */
u32 func_021D54E0(struct BtlMon *p, u32 i)
{
    return p->e[i].saved.lo;
}





void func_021D54F4(struct BtlMon *src, struct BtlMon *dst)
{
    u32 i;
    for (i = 0; i < 4; i++) dst->e[i] = src->e[i];
    dst->n140 = src->n140;
}





u16 func_021D5528(struct BtlMon *p, u8 i, u8 *a, u8 *b)
{
    *a = p->e[i].saved.pp;
    *b = p->e[i].saved.ppMax;
    return p->e[i].saved.id;
}



u8 func_021D554C(struct BtlMon *p, u8 i) { return p->e[i].saved.ppMax - p->e[i].saved.pp; }



u8 func_021D5568(struct BtlMon *p, u32 i) { return p->e[i].cur.ppMax - p->e[i].cur.pp; }




u8 func_021D5584(struct BtlMon *p, u32 i)
{
    if (i < p->n140) return p->e[i].saved.pp;
    return 0;
}




int func_021D55A0(struct BtlMon *p, int id)
{
    u32 i;
    for (i = 0; i < *(volatile u8 *)&p->n140; i++) {
        if (id == p->e[i].saved.id) return p->e[i].saved.pp;
    }
    return 0;
}



/*
 * lever: the index is added in each arm of the table select, so the sum is
 * formed once and shared by the halfword and byte loads.
 */
int func_021D55D8(struct BtlMon *p, int i, int s)
{
    struct BtlMoveInfo *e;
    if (s) e = &p->e[i].cur; else e = &p->e[i].saved;
    if (e->id != 0 && e->pp == e->ppMax) return 1;
    return 0;
}




void func_021D5608(struct BtlMon *p, int i, u8 n)
{
    if (p->e[i].saved.pp >= n) p->e[i].saved.pp -= n;
    else p->e[i].saved.pp = 0;
    if (p->e[i].fC != 0) {
        p->e[i].cur.pp = p->e[i].saved.pp;
        func_02017E40(p->f00, i + 0x3A, p->e[i].cur.pp);
    }
}



void func_021D5640(struct BtlMon *p, u32 i, u32 n)
{
    int v;
    if (p->e[i].fC == 0) {
        v = (int)((u32)p->e[i].cur.pp - n);
        if (v < 0) v = 0;
        p->e[i].cur.pp = v;
        func_02017E40(p->f00, i + 0x3a, p->e[i].cur.pp);
    }
}



u16 func_021D5674(struct BtlMon *p, u32 i, u8 n)
{
    struct BtlMoveSlot *e = &p->e[i];
    e->saved.pp += n;
    if (e->saved.pp > e->saved.ppMax) e->saved.pp = e->saved.ppMax;
    if (e->fC) e->cur.pp = e->saved.pp;
    return e->saved.id;
}



u16 func_021D56A0(struct BtlMon *p, u32 i, u8 n)
{
    struct BtlMoveSlot *e = &p->e[i];
    e->cur.pp += n;
    if (e->cur.pp > e->cur.ppMax) e->cur.pp = e->cur.ppMax;
    if (e->fC) e->saved.pp = e->cur.pp;
    return e->cur.id;
}




void func_021D56CC(struct BtlMon *p, int i)
{
    struct BtlMoveSlot *e = &p->e[i];
    if (e->saved.hi == 0) {
        e->saved.hi = 1;
        p->f143++;
    }
    e->saved.lo = 1;
    if (e->fC != 0) {
        e->cur.lo = e->saved.lo;
        e->cur.hi = e->saved.hi;
    }
}



void func_021D5734(struct BtlMon *p, u8 i, u16 a, u8 b, u32 c)
{ func_021D51DC(&p->e[i], a, b, c); }



int func_021D5750(struct BtlMon *p, u16 id)
{ u32 i; for(i=0;i<4;i++) if(id == p->e[i].saved.id) return 1; return 0; }




u8 func_021D5778(struct BtlMon *p, u16 id)
{
    u32 i;
    if (id != 0) {
        for (i = 0; i < 4; i++) {
            if (id == p->e[i].saved.id) return (u8)i;
        }
    }
    return 4;
}




void func_021D57A8(u8 *p, u8 *a, u8 *b)
{
    int r = func_021D62C4((struct Unk021D62A8 *)p, 0x18);
    u8 v;
    v = p[0xF8];
    if (v == 2 && r) *a = 0x11;
    else *a = v;
    v = p[0xF9];
    if (v == 2 && r) *b = 0x11;
    else *b = v;
    if (*a == 0x11) {
        if (*b == 0x11) *b = 0;
        *a = *b;
    } else if (*b == 0x11) {
        *b = *a;
    }
}




u16 func_021D57FC(void *p)
{
    u8 a;
    u8 b;
    func_021D57A8(p, &a, &b);
    return func_021E8CE0(a, b);
}




int func_021D5814(void *p, int k)
{
    u8 a;
    u8 b;
    if (k != 0x11) {
        func_021D57A8(p, &a, &b);
        if (a == k || b == k) return 1;
    }
    return 0;
}




/* 021D5844  ldr r0,[r0] */
/*
 * Reads the u32 field at offset 0 of the argument and returns it.
 */
void *func_021D5844(void *m) { return ((struct BtlMon *)m)->f00; }



/*
 * Leaf with no calls and no pool; 6 instructions, 12 bytes: ldrb r2, [r0, #0x1b]; str r1, [r0, #4]; movs r1, #0x40; orrs r1, r2; strb r1, [r0, #0x1b]; bx lr.
 */
void func_021D5848(struct BtlMon *p, void *v)
{
    p->f04 = v;
    p->b6 = 1;
}



void func_021D5854(struct BtlMon *p) { p->f04 = 0; p->b6 = 0; }



void *func_021D5864(struct BtlMon *p) { if (p->f04 && p->b6) return p->f04; return p->f00; }



int func_021D587C(void *p, int k)
{
    switch(k) {
    case 9: if (func_021EF948(6)) k = 11; break;
    case 11: if (func_021EF948(6)) k = 9; break;
    }
    return k;
}




int func_021D58A8(u8 *p, int k)
{
    int v = func_021D587C(p, k);
    switch (v) {
    case 8:
        return ((struct BtlMon *)p)->fee;
    case 9:
        return ((struct BtlMon *)p)->ff0;
    case 10:
        return ((struct BtlMon *)p)->ff2;
    case 11:
        return ((struct BtlMon *)p)->ff4;
    case 12:
        return ((struct BtlMon *)p)->ff6;
    case 6:
        return 6;
    case 7:
        return 6;
    }
    return func_021D59B4(p, v);
}




void func_021D590C(void **p, u16 *out)
{
    u8 v = func_02017D30(*p);
    out[1] = func_02017E1C(*p, 0xa1, 0);
    out[2] = func_02017E1C(*p, 0xa2, 0);
    out[3] = func_02017E1C(*p, 0xa3, 0);
    out[4] = func_02017E1C(*p, 0xa5, 0);
    out[5] = func_02017E1C(*p, 0xa6, 0);
    out[6] = func_02017E1C(*p, 0xa4, 0);
    func_02017D70(*p, v);
}




void func_021D5970(u8 *p, int k, u16 v)
{
    switch (func_021D587C(p, k)) {
    case 8:
        ((struct BtlMon *)p)->fee = v;
        break;
    case 9:
        ((struct BtlMon *)p)->ff0 = v;
        break;
    case 10:
        ((struct BtlMon *)p)->ff2 = v;
        break;
    case 11:
        ((struct BtlMon *)p)->ff4 = v;
        break;
    case 12:
        ((struct BtlMon *)p)->ff6 = v;
        break;
    }
}




/*
 * lever: the switch value stays in r1 and is the hidden second argument of
 * func_021D58A8; case 17 falls through into case 16.
 *
 * Addresses are Black-image addresses.
 */
int func_021D59B4(u8 *p, int k)
{
    int v = func_021D587C(p, k);

    switch (v) {
    case 8:
        return func_021D78E4(func_021D58A8(p, v), *(u8 *)&((struct BtlMon *)p)->ffc);
    case 9:
        return func_021D78E4(func_021D58A8(p, v), *(u8 *)&((struct BtlMon *)p)->ffd);
    case 10:
        return func_021D78E4(func_021D58A8(p, v), *(u8 *)&((struct BtlMon *)p)->ffe);
    case 11:
        return func_021D78E4(func_021D58A8(p, v), *(u8 *)&((struct BtlMon *)p)->fff);
    case 12:
        return func_021D78E4(func_021D58A8(p, v), ((struct BtlMon *)p)->f100);
    case 1:
        return ((struct BtlMon *)p)->ffc;
    case 2:
        return ((struct BtlMon *)p)->ffd;
    case 3:
        return ((struct BtlMon *)p)->ffe;
    case 4:
        return ((struct BtlMon *)p)->fff;
    case 5:
        return *(s8 *)&((struct BtlMon *)p)->f100;
    case 6:
        return ((struct BtlMon *)p)->f101;
    case 7:
        return ((struct BtlMon *)p)->f102;
    case 15:
        return ((struct BtlMon *)p)->f18;
    case 18:
        return ((struct BtlMon *)p)->ffa;
    case 13:
        return ((struct BtlMon *)p)->f10;
    case 14:
        return ((struct BtlMon *)p)->f0e;
    case 21:
        return ((struct BtlMon *)p)->f1a;
    case 17:
        if (func_021D62C4((struct Unk021D62A8 *)p, 0x10) != 0)
            return 0;
    case 16:
        return ((struct BtlMon *)p)->f13c;
    case 19:
        return ((struct BtlMon *)p)->f141;
    case 20:
        return ((struct BtlMon *)p)->f08;
    case 0:
        break;
    }
    return 0;
}




int func_021D5AD8(u8 *p, int k)
{
    int r = 0;
    switch (func_021D587C(p, k)) {
    case 8:
        if (((struct BtlMon *)p)->ffc < 6) r = 1;
        break;
    case 10:
        if (((struct BtlMon *)p)->ffe < 6) r = 1;
        break;
    case 9:
        if (((struct BtlMon *)p)->ffd > 6) r = 1;
        break;
    case 11:
        if (((struct BtlMon *)p)->fff > 6) r = 1;
        break;
    }
    if (r) return func_021D58A8(p, k);
    return func_021D59B4(p, k);
}



/*
 * Reads the u16 field at #0x12 of the argument and returns it.
 */
u16 func_021D5B40(struct BtlMon *p) { return p->f12; }



/* 021D5B44  strh r1,[r0,#0x12] */
/*
 * Stores the second argument (a u16) into the field at #0x12.
 */
void func_021D5B44(struct BtlMon *p, u16 v) { p->f12 = v; }



int func_021D5B48(u8 *p)
{
    if (func_021D59B4(p, 0xd) == func_021D59B4(p, 0xe)) return 1;
    return 0;
}




int func_021D5B68(void *p)
{
    if (func_021D59B4(p, 13) == 0) return 1;
    return 0;
}



/*
 * extent: follower 021D5BA4 is already filed in pkt_021D5BA4.
 */
int func_021D5B7C(void *m)
{
    int ok;
    ok = 0;
    if (func_02017E1C(((struct BtlMon *)m)->f00, 0x4c, 0)) return ok;
    if (func_021D5B68(m) == 0) ok = 1;
    return ok;
}




/*
 * Unlabelled ov093 leaf hidden in a .word run: returns the unsigned halfword
 * at +0x146 of its argument.  Matched to supply the `matched` witness for the
 * pending ov096 caller func_02189A9C.
 */
unsigned short func_021D5BA4(int *p)
{
    return ((struct BtlMon *)p)->f146;
}




int func_021D5BB0(struct BtlMon *p, u32 n)
{
    return (p->f153[(u8)(n >> 3)] & (u8)(1 << (n & 7))) ? 1 : 0;
}




int func_021D5BDC(struct BtlMon *p, u32 n)
{
    return (p->f155[(u8)(n >> 3)] & (u8)(1 << (n & 7))) ? 1 : 0;
}




u32 func_021D5C08(struct BtlMon *p)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        if (func_021D5BDC(p, data_021F040C[i])) return data_021F040C[i];
    }
    return 0x10;
}



int func_021D5C30(struct BtlMon *p)
{
    if (func_021D5C08(p) != 16) return 1;
    return 0;
}




int func_021D5C44(struct BtlMon *p)
{
    double x = (double)(100 * p->f10) / (double)p->f0e;
    double y;
    if (x > 0)
        y = 4096.0 * x + 0.5;
    else
        y = 4096.0 * x - 0.5;
    return (int)y;
}



s8 *func_021D5CB4(s8 *p, int i, u8 *a, u8 *b)
{
    *a = 0;
    *b = 12;
    switch (i) {
    case 1: return p + 0xfc;
    case 2: return p + 0xfd;
    case 3: return p + 0xfe;
    case 4: return p + 0xff;
    case 5: return p + 0x100;
    case 6: return p + 0x101;
    case 7: return p + 0x102;
    default: return 0;
    }
}



/*
 * extent: final two bytes are zero alignment padding.
 * evidence: 021D5CB4 unconditionally writes both outputs before its switch.
 */
int func_021D5D14(s8 *p, int i, int sign)
{
    s8 a;
    s8 b;
    s8 *v;
    v = func_021D5CB4(p, i, (u8 *)&a, (u8 *)&b);
    if (sign > 0) return *v < b;
    else return *v > a;
}



/*
 * lever: a declared before b places b at stack offset zero.
 * evidence: 021D5CB4 unconditionally writes both outputs before its switch.
 */
int func_021D5D50(s8 *p, int i)
{
    s8 a;
    s8 b;
    s8 *v;
    v = func_021D5CB4(p, i, (u8 *)&a, (u8 *)&b);
    return b - *v;
}



int func_021D5D68(s8 *p)
{
    if (p[0xfc] < 6) return 1;
    if (p[0xfd] < 6) return 1;
    if (p[0xfe] < 6) return 1;
    if (p[0xff] < 6) return 1;
    if (p[0x100] < 6) return 1;
    if (p[0x101] < 6) return 1;
    if (p[0x102] < 6) return 1;
    return 0;
}



u8 func_021D5DC0(s8 *p, int i, u8 n)
{
    s8 *q;
    int t;
    switch (i) {
    case 1: q = p + 0xfc; break;
    case 2: q = p + 0xfd; break;
    case 3: q = p + 0xfe; break;
    case 4: q = p + 0xff; break;
    case 5: q = p + 0x100; break;
    case 6: q = p + 0x101; break;
    case 7: q = p + 0x102; break;
    default: return 0;
    }
    t = q[0];
    if (t < 12) {
        if (t + n > 12) n = 12 - t;
        q[0] += n;
        return n;
    }
    return 0;
}
