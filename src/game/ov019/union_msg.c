/*
 * file:     union_msg.c
 * unit:     yes
 * function: func_0217EC04, func_0217EC1C, func_0217EC28, func_0217EC34, func_0217EC40, func_0217EC54, func_0217EC68, func_0217EC78, func_0217EC88, func_0217EC94, func_0217ECA0, func_0217ECAC, func_0217ECB8, func_0217ECD0, func_0217ECE8, func_0217ED04, func_0217ED10, func_0217ED2C, func_0217ED48, func_0217ED64, func_0217ED80, func_0217ED8C, func_0217ED98, func_0217EDA4, func_0217EDB0, func_0217EDBC, func_0217EDC8, func_0217EDD4, func_0217EDE0, func_0217EDEC, func_0217EDF8, func_0217EE04, func_0217EE10, func_0217EE1C, func_0217EE28, func_0217EE34, func_0217EE40, func_0217EE4C, func_0217EE90, func_0217EFE0, func_0217F020, func_0217F044, func_0217F060, func_0217F074, func_0217F098, func_0217F128, func_0217F188, func_0217F1EC, func_0217F210, func_0217F22C, func_0217F24C, func_0217F268, func_0217F2A8, func_0217F2F4, func_0217F310, func_0217F360, func_0217F378, func_0217F380, func_0217F388, func_0217F4AC, func_0217F4B4, func_0217F5E0, func_0217F624, func_0217F640, func_0217F794, func_0217F7B8, func_0217F7E4, func_0217F858, func_0217F894
 * address:  0x0217EC04
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02034714  0x02034714  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_020084F4  0x020084F4  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   d_0218031C 0x0218031C data a2
 *   d_0218034C  0x0218034C  data a2
 *   d_02180330  0x02180330  data a2
 *   d_02180348  0x02180348  data a2
 *   d_021805E4 0x021805E4 data a2
 *   d_02180648  0x02180648  data a2
 *   d_0218053C  0x0218053C  data a2
 *   d_02180570  0x02180570  data a2
 *   d_02180300  0x02180300  data a2
 *   d_0218032C  0x0218032C  data a2
 *   d_02180320  0x02180320  data a2
 *   d_02180318  0x02180318  data a2
 *   d_02180328 0x02180328 data a2
 *   d_02180324 0x02180324 data a2
 *   func_020056EC 0x020056EC thumb
 *   d_02180380 0x02180380 data a2
 *   d_0218033C  0x0218033C  data a2
 *   d_02180368 0x02180368 data a2
 *   d_02180370 0x02180370 data a2
 *   d_02180360 0x02180360 data a2
 *   d_02180390     0x02180390  data  a2
 *   d_02180314  0x02180314  data a2
 *   d_02180310  0x02180310  data a2
 *   d_02180340  0x02180340  data a2
 *   d_02180304  0x02180304  data a2
 *   d_02180308  0x02180308  data a2
 *   d_02180344  0x02180344  data a2
 *   d_02180350  0x02180350  data a2
 *   d_02180338  0x02180338  data a2
 *   d_0218035C  0x0218035C  data a2
 *   d_02180358  0x02180358  data a2
 *   d_02180354  0x02180354  data a2
 *   d_021802F8  0x021802F8  data a2
 *   d_021802F0  0x021802F0  data a2
 *   d_021802F4  0x021802F4  data a2
 *   d_02180334  0x02180334  data a2
 *   d_0218030C  0x0218030C  data a2
 *   d_021802FC  0x021802FC  data a2
 *   func_0200856C  0x0200856C  thumb
 *   func_02008570  0x02008570  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045924  0x02045924  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F048  0x0201F048  thumb
 *   func_0201F094  0x0201F094  thumb
 *   d_021807F8     0x021807F8  data  a1
 *   func_02024988  0x02024988  thumb
 *   func_020249A0  0x020249A0  thumb
 *   d_0218044C     0x0218044C  data
 *   func_0201EC74 0x0201EC74 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   d_021806AC 0x021806AC data a1
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_02191558  0x02191558  thumb  ov021
 *   func_021915EC  0x021915EC  thumb  ov021
 *   func_0219160C  0x0219160C  thumb  ov021
 *   func_021915B4  0x021915B4  thumb  ov021
 *   func_021904C8  0x021904C8  thumb  ov021
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_021916A8  0x021916A8  thumb  ov021
 *   func_021916E0 0x021916E0 thumb ov021
 *   func_02190BE4 0x02190BE4 thumb ov021
 *   func_021909BC 0x021909BC thumb ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_02190A28  0x02190A28  thumb  ov021
 *   func_02190988  0x02190988  thumb  ov021
 *   func_0219049C  0x0219049C  thumb  ov021
 *   func_021909E4  0x021909E4  thumb  ov021
 *   d_0218042C 0x0218042C data a4
 *   d_021804DC 0x021804DC data a4
 *   d_0218046C     0x0218046C  data  a4
 *   d_021805A4     0x021805A4  data  a4
 *   d_021807FC     0x021807FC  data  a1
 *   d_0218050C     0x0218050C  data  a4
 *   d_021804B4     0x021804B4  data  a4
 *   d_021803A0     0x021803A0  data  ov019  a1
 *   func_0219161C  0x0219161C  thumb  ov021
 *   func_0201A4D4  0x0201A4D4  thumb
 *   func_0200AE3C  0x0200AE3C  thumb
 *   func_02191648  0x02191648  thumb  ov021
 *   func_02191674  0x02191674  thumb  ov021
 *   func_021904A8 0x021904A8 thumb ov021
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0201A570 0x0201A570 thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F8  0x020120F8  thumb
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_02012AD0  0x02012AD0  thumb
 *   d_02180718     0x02180718  data   ov019 a4
 *   func_02009D50 0x02009D50 thumb
 *   sub_020490F4   0x020490F4  arm
 *   sub_02034714   0x02034714  arm
 *   MTX_Identity33_  0x0207ADC4  arm
 *   func_0217C2AC  0x0217C2AC  thumb  ov019
 *   func_0217C5A8  0x0217C5A8  thumb  ov019
 *   func_0217C88C  0x0217C88C  thumb  ov019
 *   func_0217CEB8  0x0217CEB8  thumb  ov019
 *   func_0217D7A4  0x0217D7A4  thumb  ov019
 *   func_0217D890  0x0217D890  thumb  ov019
 */
#include "../../matched/include/Obj19442.h"

struct Big;
struct Ctx_0217BD9C;
struct Rec44;
struct Sub0200852CObj;
struct Obj_0217E188;
struct Sub02008700Obj;
struct WordSet;
struct MsgBank;
struct U16Vec;
struct Fx;
struct R;
struct Handle;
struct Pair;
struct VecFx32;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef short          s16;
typedef int            s32;

typedef struct { int x,y,z; } VecFx32;
#include "../ov012/union_comm_types.h"

#ifndef NULL
#define NULL ((void *)0)
#endif



typedef struct Tmpl {
    u16 f0;
    u16 f2;
    u32 f4[4];
    u16 f14;
    u16 f16;
    u16 f18;
    u16 f1A;
    u32 f1C;
} Tmpl;

typedef struct Ent_0217F388 {
    void *p;
    u8    b;
    u8    pad5[3];
} Ent_0217F388;

typedef struct Pair {
    u32 f0;
    u32 f4;
} Pair;


struct P16 { short x; short z; };

struct Bits_0217DC94 { u8 pad[7]; unsigned char low:3; unsigned char kind:1; unsigned char high:4; };



extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const void *site, unsigned short tag);
extern void *func_02012EBC(void *p);
extern u32 func_020307B0(void *p);
void func_02034714(const void *expr, u32 line, const void *file);
extern void func_02082D44(const void *a, void *b, int c);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const void *obj);
extern void *func_02188CB4(void *p);
const void *func_020084F4(const void *p);
void func_0201F02C(void *p, u32 i, void *a);
extern u32 func_020056EC(u32 v);
extern u8 func_0200856C(const void *obj);
extern u8 func_02008570(const void *obj);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045924(void *o, const void *src);
extern void func_0201EE0C(void *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_02045808(void *vec);
extern void *func_02045EC0(void *bank, u32 index);
extern void func_0201F048(void *p, u32 i, u32 n);
extern void func_0201F094(void *p, u32 i, u32 a, u32 n);
extern void *func_02024988(int a0);
extern void func_020249A0(void *p, int bit);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern u32 func_0201ED04(void *p);
extern unsigned int func_02188C54(void *p);
extern int func_021904B0(u32 a, u32 b);
extern struct R *func_02191558(void *a, u32 b, u32 c, u16 d, u16 e, u16 f, u16 g);
extern void func_021915EC(void *r);
extern void func_0219160C(void *p);
extern int func_021915B4(void *a);
extern u32 func_021904C8(void *a0);
extern void func_02045CAC(void *bank, u32 index, void *dest);
extern void func_0201F250(void *ws, void *dst, void *src);
extern void func_021916A8(void *r, u32 b, u16 c, u32 d);
extern u32 func_021916E0(void *p);
extern u32 *func_02190BE4(void *a, u32 b);
extern int func_021909BC(void *a);
extern int func_02190C78(void *h);
extern u32 func_02190A28(const void *arr, int n, u32 c, u16 d);
extern struct Handle *func_02190988(void *a, const void *b, u32 c, u32 d, u32 x, u16 y, u16 z, u32 w);
extern int func_0219049C(void *p);
extern int func_021909E4(void *h);
extern void func_0219161C(void *r, int b, int c, u32 d);
extern u8 *func_0201A4D4(void *a0, u32 a1, u16 a2, u32 a3);
extern void *func_0200AE3C(void *p, u32 heap);
extern void func_02191648(void *r, int b, int c, u32 d);
extern void  func_02191674(void *a, int b, u16 c, u32 d, int e);
extern u32 func_021904A8(void *p);
extern u32 func_0201C6B4(const void *p);
extern void func_0201A570(void *p);
extern void *func_02188C80(void *p);
extern u8 *func_020120F8(const void *p);
extern void func_021A3038(void *a, void *v);
extern u16 func_02012AD0(const void *p);
extern int func_02009D50(void *obj, const void *unused, u32 id, u32 kind, void *out);
u16 func_0217EC04(void ***ctx);
u16 func_0217EC1C(int i);
u16 func_0217EC28(int i);
u16 func_0217EC34(int i);
u16 func_0217EC40(int i, int j);
u16 func_0217EC54(int i, int j);
u16 func_0217EC68(int i);
u16 func_0217EC78(int i);
u16 func_0217EC88(int i);
u16 func_0217EC94(int i);
u16 func_0217ECA0(int i);
u16 func_0217ECAC(int i);
u16 func_0217ECB8(void ***ctx);
u16 func_0217ECD0(void ***ctx);
u16 func_0217ECE8(int i);
u16 func_0217ED04(int i);
u16 func_0217ED10(int i);
u16 func_0217ED2C(int i);
u16 func_0217ED48(int i);
u16 func_0217ED64(int i);
u16 func_0217ED80(int i);
u16 func_0217ED8C(int i);
u16 func_0217ED98(int i);
u16 func_0217EDA4(int i);
u16 func_0217EDB0(int i);
u16 func_0217EDBC(int i);
u16 func_0217EDC8(int i);
u16 func_0217EDD4(int i);
u16 func_0217EDE0(int i);
u16 func_0217EDEC(int i);
u16 func_0217EDF8(int i);
u16 func_0217EE04(int i);
u16 func_0217EE10(int i);
u16 func_0217EE1C(int i);
u16 func_0217EE28(int i);
u16 func_0217EE34(int i);
u16 func_0217EE40(int i);
int func_0217EE4C(UnionRoomWork *unisys, int language, int version);
void func_0217EE90(UnionRoomWork *unisys);
void func_0217EFE0(int gameData, unsigned int language);
void func_0217F020(UnionRoomWork *unisys);
void func_0217F044(UnionRoomWork *unisys);
int func_0217F060(int i);
void func_0217F074(UnionRoomWork *unisys);
void func_0217F098(UnionRoomWork *unisys, u8 *fieldmap);
void func_0217F128(UnionRoomWork *unisys);
void func_0217F188(UnionRoomWork *unisys, u32 msgId);
u32 func_0217F1EC(UnionRoomWork *unisys);
void func_0217F210(UnionRoomWork *unisys, u8 *fieldmap, u32 msgId);
void func_0217F22C(UnionRoomWork *unisys, u32 fieldmap);
void func_0217F24C(UnionRoomWork *unisys);
int func_0217F268(UnionRoomWork *unisys, u32 *isYes);
void func_0217F2A8(UnionRoomWork *unisys, u32 fieldmap, u32 listData, u32 listCount, u32 menuHeader);
void func_0217F2F4(UnionRoomWork *unisys);
int func_0217F310(UnionRoomWork *unisys, u32 fieldmap);
void func_0217F360(UnionRoomWork *unisys, u32 fieldmap);
void func_0217F378(UnionRoomWork *unisys);
int func_0217F380(UnionRoomWork *unisys, int fieldmap);
void func_0217F388(UnionRoomWork *unisys, int fieldmap, int kind, u8 *arg);
void func_0217F4AC(UnionRoomWork *unisys);
int func_0217F4B4(UnionRoomWork *unisys, int *hit, u8 *st, int *flag, u32 fieldmap);
void func_0217F5E0(UnionRoomWork *unisys, u32 fieldmap);
void func_0217F624(UnionRoomWork *unisys);
void func_0217F640(UnionRoomWork *unisys, u32 fieldmap, u32 failMask, int mode, int titleKind);
u32 func_0217F794(UnionRoomWork *unisys, u32 fieldmap);
void func_0217F7B8(UnionRoomWork *unisys);
int func_0217F7E4(u32 arg);
int func_0217F858(int a);
int func_0217F894(void *p,char *q);
extern const u16 d_0218031C[];
extern const u16 d_0218034C[];
extern const u16 d_02180330[];
extern const u16 d_02180348[];
extern const u16 d_021805E4[][2];
extern const u16 d_02180648[][2];
extern const u16 d_0218053C[];
extern const u16 d_02180570[];
extern const u16 d_02180300[];
extern const u16 d_0218032C[];
extern const u16 d_02180320[];
extern const u16 d_02180318[];
extern const u16 d_02180328[];
extern const u16 d_02180324[];
extern const u16 d_02180380[][2];
extern const u16 d_0218033C[];
extern const u16 d_02180368[][2];
extern const u16 d_02180370[][2];
extern const u16 d_02180360[][2];
extern const u16 d_02180390[][2];
extern const u16 d_02180314[];
extern const u16 d_02180310[];
extern const u16 d_02180340[];
extern const u16 d_02180304[];
extern const u16 d_02180308[];
extern const u16 d_02180344[];
extern const u16 d_02180350[];
extern const u16 d_02180338[];
extern const u16 d_0218035C[];
extern const u16 d_02180358[];
extern const u16 d_02180354[];
extern const u16 d_021802F8[];
extern const u16 d_021802F0[];
extern const u16 d_021802F4[];
extern const u16 d_02180334[];
extern const u16 d_0218030C[];
extern const u16 d_021802FC[];
extern const char d_021807F8[];
extern int d_0218044C[];
extern const u8 d_021806AC[][4];
extern const u32 d_0218042C[];
extern const u32 d_021804DC[];
extern const Tmpl d_0218046C;
extern const Ent_0217F388  d_021805A4[];
extern const char d_021807FC[];
extern const u32  d_0218050C[];
extern const u32  d_021804B4[];
extern const u8  d_021803A0[][2][2];
extern struct P16 d_02180718[];


u16 func_0217EC04(void ***ctx)
{
    return d_0218031C[func_02008550(**ctx)];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from func_0217C2AC.
 */
u16 func_0217EC1C(int i)
{
    return d_0218034C[i];
}


u16 func_0217EC28(int i)
{
    return d_02180330[i];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from func_0217C5A8.
 */
u16 func_0217EC34(int i)
{
    return d_02180348[i];
}


u16 func_0217EC40(int i, int j)
{
    return d_021805E4[i - 2][j];
}


u16 func_0217EC54(int i, int j)
{
    return d_02180648[i - 2][j];
}


u16 func_0217EC68(int i)
{
    return d_0218053C[i - 2];
}


u16 func_0217EC78(int i)
{
    return d_02180570[i - 2];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from func_0217C2AC and func_0217C88C.
 */
u16 func_0217EC88(int i)
{
    return d_02180300[i];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from func_0217D7A4 / func_0217D890.
 */
u16 func_0217EC94(int i)
{
    return d_0218032C[i];
}


u16 func_0217ECA0(int i)
{
    return d_02180320[i];
}


u16 func_0217ECAC(int i)
{
    return d_02180318[i];
}


u16 func_0217ECB8(void ***ctx)
{
    return d_02180328[func_02008550(**ctx)];
}


u16 func_0217ECD0(void ***ctx)
{
    return d_02180324[func_02008550(**ctx)];
}


/*
 * Extent follower func_0217ED04 is already filed separately.
 */
u16 func_0217ECE8(int i)
{
    return d_02180380[func_020056EC(4)][i];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from func_0217CEB8.
 */
u16 func_0217ED04(int i)
{
    return d_0218033C[i];
}


u16 func_0217ED10(int i)
{
    return d_02180368[func_020056EC(2)][i];
}


u16 func_0217ED2C(int i)
{
    return d_02180370[func_020056EC(4)][i];
}


u16 func_0217ED48(int i)
{
    return d_02180360[func_020056EC(2)][i];
}


u16 func_0217ED64(int i)
{
    return d_02180390[func_020056EC(4)][i];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run)
 * inside the listing extent of func_0217ED64.
 */
u16 func_0217ED80(int i)
{
    return d_02180314[i];
}


u16 func_0217ED8C(int i)
{
    return d_02180310[i];
}


u16 func_0217ED98(int i)
{
    return d_02180340[i];
}


u16 func_0217EDA4(int i)
{
    return d_02180304[i];
}


u16 func_0217EDB0(int i)
{
    return d_02180308[i];
}


u16 func_0217EDBC(int i)
{
    return d_02180344[i];
}


u16 func_0217EDC8(int i)
{
    return d_02180350[i];
}


u16 func_0217EDD4(int i)
{
    return d_02180338[i];
}


u16 func_0217EDE0(int i)
{
    return d_0218035C[i];
}


u16 func_0217EDEC(int i)
{
    return d_02180358[i];
}


u16 func_0217EDF8(int i)
{
    return d_02180354[i];
}


u16 func_0217EE04(int i)
{
    return d_021802F8[i];
}


u16 func_0217EE10(int i)
{
    return d_021802F0[i];
}


u16 func_0217EE1C(int i)
{
    return d_021802F4[i];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run)
 * inside the listing extent of func_0217ED64.
 */
u16 func_0217EE28(int i)
{
    return d_02180334[i];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from func_0217D890.
 */
u16 func_0217EE34(int i)
{
    return d_0218030C[i];
}


u16 func_0217EE40(int i)
{
    return d_021802FC[i];
}


int func_0217EE4C(UnionRoomWork *unisys, int language, int version)
{
    int myStatus = (int)func_02012944((void *)unisys->parent->gameData);
    int myLanguage = func_0200856C((const struct Sub0200852CObj *)myStatus);
    int myVersion = func_02008570((const struct Sub0200852CObj *)myStatus);

    if (language == 0)
        return 15;
    if (myLanguage != language) {
        if (version == 0)
            return 13;
        return 12;
    }
    if (version == 0 || myVersion == version)
        return 15;
    return 14;
}


void func_0217EE90(UnionRoomWork *unisys)
{
    void *greetingStr;
    void *nameStr;
    u32 myStatus;
    u16 *nameChars;
    UnionMySituation *situation = &unisys->mySituation;
    int language;
    u8 sex;
    int greetingMsgId;
    const UnionBeacon *partner;

    myStatus = (u32)unisys->parent->myStatus;
    if (unisys->msgWork.msgData == 0)
        func_02034714(d_021807F8, 0, d_021807F8);
    if (unisys->msgWork.wordSet == 0)
        func_02034714(d_021807F8, 0, d_021807F8);

    partner = situation->connect.talkParam;
    if (partner != 0) {
        nameChars = (u16 *)partner->name;
        language = partner->language;
        sex = partner->sex;
    } else {
        nameChars = (u16 *)func_020084F4((const void *)myStatus);
        language = 2;
        sex = (int)func_02008550((const struct Sub0200852CObj *)myStatus);
    }
    nameStr = func_020457B0(0x20, UNION_HEAP_ID);
    func_02045924(nameStr, nameChars);
    func_0201EE0C(unisys->msgWork.wordSet, 0, nameStr, sex, 1, language);
    func_02045808(nameStr);
    func_0201F02C(unisys->msgWork.wordSet, 1, (void *)myStatus);

    switch (language) {
    case 1: greetingMsgId = 0xe7; break;
    case 2: greetingMsgId = 0xe8; break;
    case 3: greetingMsgId = 0xe9; break;
    case 4: greetingMsgId = 0xea; break;
    case 5: greetingMsgId = 0xeb; break;
    case 7: greetingMsgId = 0xec; break;
    case 8: greetingMsgId = 0xee; break;
    default: greetingMsgId = 0xed; break;
    }
    greetingStr = func_02045EC0(unisys->msgWork.msgData, greetingMsgId);
    func_0201EE0C(unisys->msgWork.wordSet, 2, greetingStr, sex, 1, language);
    func_02045808(greetingStr);

    if (situation->connect.talkParam != 0 && situation->connect.talkParam->nation != 0) {
        func_0201F048(unisys->msgWork.wordSet, 3, situation->connect.talkParam->nation);
        if (situation->connect.talkParam->area != 0)
            func_0201F094(unisys->msgWork.wordSet, 4, situation->connect.talkParam->nation, situation->connect.talkParam->area);
    }
    func_0217EFE0((int)unisys->parent->gameData, language);
}


void func_0217EFE0(int gameData, unsigned int language)
{
    int pmsWordSave;
    unsigned short langIndex;

    pmsWordSave = (int)func_02024988((int)func_02012EBC((struct Big *)gameData));
    langIndex = language - 1;
    if (language >= 1 && language <= 8) {
        if (langIndex < 8) {
            func_020249A0((int *)pmsWordSave, d_0218044C[langIndex]);
            return;
        }
        func_020249A0((int *)pmsWordSave, 7);
        return;
    }
    func_020249A0((int *)pmsWordSave, 7);
}


void func_0217F020(UnionRoomWork *unisys)
{
    if (unisys->msgWork.wordSet == 0) {
        unisys->msgWork.wordSet = func_0201EC74(5, 0x40, UNION_HEAP_ID);
        func_0217EE90(unisys);
    }
}


void func_0217F044(UnionRoomWork *unisys)
{
    if (unisys->msgWork.wordSet != 0) {
        func_0201ED04(unisys->msgWork.wordSet);
        unisys->msgWork.wordSet = 0;
    }
}


int func_0217F060(int i)
{
    if (i >= 27) return 0;
    return d_021806AC[i][0];
}


void func_0217F074(UnionRoomWork *unisys)
{
    func_0217F7B8(unisys);
    func_0217F624(unisys);
    func_0217F24C(unisys);
    func_0217F2F4(unisys);
    func_0217F128(unisys);
}


void func_0217F098(UnionRoomWork *unisys, u8 *fieldmap)
{
    int fieldMsgBg;

    if (unisys->msgWork.talkWin == 0) {
        if (unisys->msgWork.msgData != 0)
            func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
        fieldMsgBg = func_02188C54(fieldmap);
        unisys->msgWork.msgData = (struct MsgBank *)func_021904B0(fieldMsgBg, 200);
        unisys->msgWork.strTemp = (struct Strbuf *)func_020457B0(0x100, UNION_HEAP_ID);
        unisys->msgWork.strExpand = (struct Strbuf *)func_020457B0(0x100, UNION_HEAP_ID);
        func_0217F020(unisys);
        unisys->msgWork.talkWin = func_02191558((struct Fx *)fieldMsgBg, (u32)unisys->msgWork.msgData, 0, 1, 0x13, 0x1e, 4);
    } else {
        func_021915EC(unisys->msgWork.talkWin);
    }
}


void func_0217F128(UnionRoomWork *unisys)
{
    if (unisys->msgWork.talkWin != 0) {
        func_0219160C(unisys->msgWork.talkWin);
        func_021915B4(unisys->msgWork.talkWin);
        unisys->msgWork.talkWin = 0;
        unisys->msgTalkPrinting = 0;
        func_02045808(unisys->msgWork.strTemp);
        func_02045808(unisys->msgWork.strExpand);
        unisys->msgWork.strTemp = 0;
        unisys->msgWork.strExpand = 0;
    }
    if (unisys->msgWork.msgData != 0) {
        func_0217F044(unisys);
        func_021904C8(unisys->msgWork.msgData);
        unisys->msgWork.msgData = 0;
    }
}


void func_0217F188(UnionRoomWork *unisys, u32 msgId)
{
    if (unisys->msgWork.talkWin == 0) {
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    func_02045CAC(unisys->msgWork.msgData, msgId, unisys->msgWork.strTemp);
    func_0201F250(unisys->msgWork.wordSet, unisys->msgWork.strExpand, unisys->msgWork.strTemp);
    func_021916A8(unisys->msgWork.talkWin, 0, 0, (u32)unisys->msgWork.strExpand);
    unisys->msgTalkPrinting = 1;
}


u32 func_0217F1EC(UnionRoomWork *unisys)
{
    if (unisys->msgWork.talkWin == 0 || unisys->msgTalkPrinting == 0)
        return 1;
    return func_021916E0(unisys->msgWork.talkWin);
}


void func_0217F210(UnionRoomWork *unisys, u8 *fieldmap, u32 msgId)
{
    func_0217F098(unisys, fieldmap);
    func_0217EE90(unisys);
    func_0217F188(unisys, msgId);
}


void func_0217F22C(UnionRoomWork *unisys, u32 fieldmap)
{
    if (unisys->msgWork.yesNo == 0) {
        unisys->msgWork.yesNo = func_02190BE4((u16 *)func_02188C54((u8 *)fieldmap), 0);
    }
}


void func_0217F24C(UnionRoomWork *unisys)
{
    if (unisys->msgWork.yesNo != 0) {
        func_021909BC(unisys->msgWork.yesNo);
        unisys->msgWork.yesNo = 0;
    }
}


int func_0217F268(UnionRoomWork *unisys, u32 *isYes)
{
    int result;

    if (unisys->msgWork.yesNo == 0) {
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    result = func_02190C78(unisys->msgWork.yesNo);
    if (result == 2) {
        return 0;
    }
    *isYes = (result == 0) ? 1 : 0;
    return 1;
}


void func_0217F2A8(UnionRoomWork *unisys, u32 fieldmap, u32 listData, u32 listCount, u32 menuHeader)
{
    u32 fieldMsgBg = func_02188C54((u8 *)fieldmap);

    if (unisys->msgWork.menu == 0) {
        u32 menuList = func_02190A28((const struct Pair *)listData, listCount, (u32)unisys->msgWork.msgData, UNION_HEAP_ID);
        unisys->msgWork.menu = func_02190988((u16 *)fieldMsgBg, (const u8 *)menuHeader, menuList, 0, 0, 0, 0, 1);
    }
}


void func_0217F2F4(UnionRoomWork *unisys)
{
    if (unisys->msgWork.menu != 0) {
        func_021909BC(unisys->msgWork.menu);
        unisys->msgWork.menu = 0;
    }
}


int func_0217F310(UnionRoomWork *unisys, u32 fieldmap)
{
    u32 fieldMsgBg = func_02188C54((u8 *)fieldmap);

    if (fieldMsgBg == 0) {
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    if (fieldMsgBg != 0 && func_0219049C((u8 *)fieldMsgBg) == 0) {
        return -1;
    }
    if (unisys->msgWork.menu == 0) {
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    return func_021909E4(unisys->msgWork.menu);
}


void func_0217F360(UnionRoomWork *unisys, u32 fieldmap)
{
    func_0217F2A8(unisys, fieldmap, (u32)d_021804DC, 6, (u32)d_0218042C);
}


void func_0217F378(UnionRoomWork *unisys)
{
    func_0217F2F4(unisys);
}


/*
 * Unlabelled tail-call thunk (ldr r3 / bx r3, no push); called from
 * func_0217C2AC.
 */
int func_0217F380(UnionRoomWork *unisys, int fieldmap)
{
    return func_0217F310(unisys, fieldmap);
}


void func_0217F388(UnionRoomWork *unisys, int fieldmap, int kind, u8 *arg)
{
    Tmpl t;
    u8 v;
    u32 *obj;

    arg[3] = kind;
    t = d_0218046C;
    v = d_021805A4[kind].b;
    t.f0 = v;
    t.f2 = v;
    t.f1A = t.f0 << 1;
    if (kind == 1 || kind == 5)
        t.f18 = 0x1e;
    if (kind >= 5)
        t.f16 = 5;

    if (kind == 1) {
        obj = func_02030734(0x41, 0x30, 1, d_021807FC, 0x647);
        func_02082D44(d_0218050C, obj, 0x30);
        obj[0] = arg[0] + 0xff;
        obj[2] = arg[1] + 0x104;
        obj[4] = arg[2] + 0x106;
        func_0217F2A8(unisys, fieldmap, (u32)obj, v, (u32)(&t));
        func_020307B0(obj);
    } else if (kind == 5) {
        obj = func_02030734(0x41, 0x28, 1, d_021807FC, 0x657);
        func_02082D44(d_021804B4, obj, 0x28);
        obj[0] = arg[1] + 0x104;
        obj[2] = arg[2] + 0x106;
        func_0217F2A8(unisys, fieldmap, (u32)obj, v, (u32)(&t));
        func_020307B0(obj);
    } else {
        func_0217F2A8(unisys, fieldmap, (u32)d_021805A4[kind].p, v, (u32)(&t));
    }
}


/*
 * Unlabelled tail-call thunk (ldr r3 / bx r3, no push); called from
 * func_0217C88C.
 */
void func_0217F4AC(UnionRoomWork *unisys)
{
    func_0217F2F4(unisys);
}


#pragma opt_propagation off


/*
 * note: final push 2026-10-05 G4L6. Case -2 reads the entry table by byte offset (off = st[3] * 8,
 *   set after the zero test) with opt_propagation off, so the table address stays one live value
 *   for the pair-pointer load (indexed) and the count byte (+4). Struct-index forms and the
 *   un-pragma'd forms propagate the address into each use (two pool words) or hoist the pool load.
 */
int func_0217F4B4(UnionRoomWork *unisys, int *hit, u8 *st, int *flag, u32 fieldmap)
{
    u32 key;
    u32 i;
    const Pair *pairs;

    *hit = 0;
    *flag = 0;
    key = func_0217F310(unisys, fieldmap);
    switch (key) {
    case (u32)-1:
        return key;
    case (u32)-2: {
        u32 off;
        const u8 *base;
        if (st[3] == 0)
            return key;
        off = st[3] * 8;
        base = (const u8 *)d_021805A4;
        pairs = *(const Pair * const *)(base + off);
        key = pairs[*(base + off + 4) - 1].f4;
        break;
    }
    case 0x64:
        return d_021803A0[st[0]][st[1]][st[2]];
    case 0x96:
        *flag = 1;
        return d_021803A0[st[0]][st[1]][st[2]];
    }

    if (st[3] == 0) {
        if (key == (u32)d_0218050C) {
            if (st[0] == 4)
                st[0] = 0;
        } else if (key == (u32)d_021804B4) {
            st[0] = 4;
        }
    }

    for (i = 0; (i < 8) ? 1 : 0; i++) {
        if (d_021805A4[i].p == (const Pair *)key) {
            *hit = 1;
            return i;
        }
        switch (st[3]) {
        case 0:
        case 1:
            break;
        case 2:
            if (key < 5) {
                st[0] = key;
                *hit = 1;
                return 1;
            }
            break;
        case 3:
        case 6:
            if (key < 2) {
                st[1] = key;
                *hit = 1;
                if (st[3] == 6)
                    return 5;
                return 1;
            }
            break;
        case 4:
        case 7:
            if (key < 2) {
                st[2] = key;
                *hit = 1;
                if (st[3] == 7)
                    return 5;
                return 1;
            }
            break;
        case 5:
            break;
        }
    }
    func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    return 0;
}


#pragma opt_propagation reset


#pragma opt_propagation reset


void func_0217F5E0(UnionRoomWork *unisys, u32 fieldmap)
{
    if (unisys->msgWork.infoWin == 0) {
        u32 infoWin = (u32)func_02191558((struct Fx *)func_02188C54((u8 *)fieldmap), (u32)unisys->msgWork.msgData, 0, 1, 1, 0x1e, 2);
        unisys->msgWork.infoWin = (void *)infoWin;
        func_0219161C((struct R *)infoWin, 0, 0, 0x103);
    }
}


void func_0217F624(UnionRoomWork *unisys)
{
    if (unisys->msgWork.infoWin) {
        func_021915B4(unisys->msgWork.infoWin);
        unisys->msgWork.infoWin = 0;
    }
}


/*
 * pass 4 2026-10-06 P4L11: closed. The palette value is assigned as a full
 * constant in each arm (pal = 0x1040 / 0x440). mwcc splits each constant into
 * movs + lsls #6 and merges the common shift at the join, which gives the same
 * stream as "pal = 0x41 / 0x11; pal <<= 6;" but a different pre-allocation
 * graph: self r5, h and pal r7, flag and tile temps r6 as in the original.
 * EXACT under --lang c99 and --lang c.
 */
void func_0217F640(UnionRoomWork *unisys, u32 fieldmap, u32 failMask, int mode, int titleKind)
{
    u32 fieldMsgBg = func_02188C54((u8 *)fieldmap);
    void *title;
    long i;
    int flag;

    if (unisys->msgWork.wordSet == 0)
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    if (unisys->msgWork.infoWin != 0)
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    if (unisys->regulationText != 0)
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);

    flag = 1;
    if (mode != 1)
        flag = 0;
    unisys->msgWork.infoWin = func_02191558((struct Fx *)fieldMsgBg, (u32)unisys->msgWork.msgData, 0, 1, 1, 0x1a, 0x10);
    unisys->regulationText = (UnionRegulationText *)func_0201A4D4(unisys->regulation, (u32)unisys->msgWork.wordSet, UNION_HEAP_ID, flag);
    func_0217EE90(unisys);

    if (titleKind == 0) {
        title = func_0200AE3C(unisys->regulation, UNION_HEAP_ID);
        func_02191648(unisys->msgWork.infoWin, 0, 0, (u32)title);
        func_02045808(title);
    } else {
        func_0219161C(unisys->msgWork.infoWin, 0, 0, titleKind == 1 ? 0x14f : 0x150);
    }

    for (i = 0; i < 6; i++) {
        int pal;
        if (failMask & (1 << i)) {
            pal = 0x1040;
        } else {
            pal = 0x440;
        }
        func_02191674(unisys->msgWork.infoWin, 0, (i * 2 + 4) * 8, (u32)unisys->regulationText->label[i], pal);
        func_02191674(unisys->msgWork.infoWin, 0x70, (i * 2 + 4) * 8, (u32)unisys->regulationText->value[i], pal);
    }
}


u32 func_0217F794(UnionRoomWork *unisys, u32 fieldmap)
{
    u32 printQue = func_021904A8((u32 *)func_02188C54((u8 *)fieldmap));

    if (unisys->regulationText == 0)
        return 1;
    return func_0201C6B4((void *)printQue);
}


void func_0217F7B8(UnionRoomWork *unisys)
{
    if (unisys->regulationText) {
        func_021915B4(unisys->msgWork.infoWin);
        unisys->msgWork.infoWin = 0;
        func_0201A570(unisys->regulationText);
        unisys->regulationText = 0;
    }
}


int func_0217F7E4(u32 arg)
{
    int v[3];
    u32 r4;
    void *h5;
    u32 i;
    int x, z;

    h5 = func_02188CB4((void *)arg);
    r4 = (u32)func_020120F8((const struct Ctx_0217DC94 *)func_02188C80((void *)arg));
    func_021A3038(h5, (struct VecFx32 *)v);
    v[0] = (v[0] >> 4) / 4096;
    v[2] = (v[2] >> 4) / 4096;
    func_02012AD0((const struct Rec44 *)r4);
    x = v[0];
    z = v[2];
    for (i = 0; i < 1; i++) {
        if (x == d_02180718[i].x && z == d_02180718[i].z) {
            return 1;
        }
    }
    return 0;
}


int func_0217F858(int a) { if(a>=4 && a<=23) return 1; switch(a) { case 3:return 4; case 24:return 2; case 25:return 5; case 26:return 3; default:return 0; } }


int func_0217F894(void *p,char *q) { u32 out; if(func_02009D50(p,q+12,((struct Obj19442 *)q)->f5C, ((struct Bits_0217DC94 *)q)->kind,&out)==1) { return 1; } else { return 0; } }
