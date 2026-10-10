/*
 * file:     net_state_p03.c
 * unit:     yes
 * function: func_020377B8, func_0203781C, func_02037858, func_02037894, func_02037928, func_020379C8, func_02037A44, func_02037A6C, func_02037B08, func_02037BA4, func_02037BE8, func_02037C10, func_02037D78, func_02037D98, func_02037E60, func_02037F48, func_0203802C, func_020380E4, func_020381D8, func_02038298, func_02038340, func_02038380, func_02038524, func_02038570, func_020385C4, func_020387A0, func_02038924, func_02038A48, func_02038A90, func_02038AE0, func_02038C18, func_02038D30, func_02038D4C, func_02038D68, func_02038DF0, func_02039050, func_020390BC, func_02039160, func_020392B8, func_020392EC, sub_02039338, sub_020393A8, sub_020393D0, func_02039414, func_02039468, func_020394C0, func_020394DC, func_020394F0, func_02039548, sub_02039560, sub_02039578, sub_02039594, func_020395E0, func_020395EC, func_02039658, func_0203971C, func_02039764, func_02039834, func_020398B4, func_0203996C, func_020399A8, func_020399B8, func_020399DC, func_020399EC, func_02039A2C, func_02039A5C, func_02039ACC, func_02039B5C, func_02039C2C, func_02039C3C, func_02039C68, func_02039CA0, func_02039CB4, func_02039CD8, func_02039D94, func_0203A020, func_0203A118, func_0203A150, func_0203A27C, func_0203A28C, func_0203A2F0, func_0203A338, func_0203A388, func_0203A424, func_0203A458, func_0203A494, func_0203A53C, func_0203A574, func_0203A5E4, func_0203A634, func_0203A67C, func_0203A70C, func_0203A730, func_0203A748, func_0203A770, func_0203A7EC, func_0203A804, func_0203A81C, func_0203A858, func_0203A85C, func_0203A958, func_0203AA94, func_0203ABC0, func_0203ACAC, func_0203AD74, func_0203AD8C, func_0203AE20, func_0203AEEC, func_0203AF40
 * address:  0x020377B8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203D798   0x0203D798  arm
 *   func_0203D788   0x0203D788  arm
 *   func_02037288   0x02037288  arm
 *   func_02037680   0x02037680  arm
 *   func_020377AC   0x020377AC  arm
 *   g_020A7A20      0x020A7A20  data
 *   func_020307B0   0x020307B0  arm
 *   func_02036B88   0x02036B88  arm
 *   g_021469D0      0x021469D0  data
 *   func_02039338   0x02039338  arm
 *   func_020393A8   0x020393A8  arm
 *   func_020370F4  0x020370F4  arm
 *   func_020393D0  0x020393D0  arm
 *   func_02037478  0x02037478  arm
 *   lbl_020A7A20    0x020A7A20  data
 *   func_0203D6BC   0x0203D6BC  arm
 *   d_020A7A20     0x020A7A20  data
 *   func_0203D680  0x0203D680  arm
 *   func_020366A8  0x020366A8  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_02036428  0x02036428  arm
 *   func_02034714  0x02034714  arm
 *   func_02037224  0x02037224  arm
 *   d_020A7A24     0x020A7A24  data
 *   d_020A7A50     0x020A7A50  data
 *   func_02037258  0x02037258  arm
 *   str_020A7A24   0x020A7A24  data
 *   str_020A7A54   0x020A7A54  data
 *   func_02039548  0x02039548  arm
 *   func_0203CA98  0x0203CA98  arm
 *   func_0203C9AC  0x0203C9AC  arm
 *   g_020A7A24     0x020A7A24  data
 *   g_020A7A50     0x020A7A50  data
 *   str_020A7A50   0x020A7A50  data
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02036A50  0x02036A50  arm
 *   func_0203C990  0x0203C990  arm
 *   func_02039594  0x02039594  arm
 *   func_020368C0  0x020368C0  arm
 *   func_0203996C   0x0203996C  arm
 *   func_02037234   0x02037234  arm
 *   func_020365E8  0x020365E8  arm
 *   func_02036540  0x02036540  arm
 *   func_02036500  0x02036500  arm
 *   func_020364D4  0x020364D4  arm
 *   func_02082D44  0x02082D44  arm
 *   g_021469DC     0x021469DC  data
 *   func_0203666C   0x0203666C  arm
 *   func_02036B98 0x02036B98 arm
 *   str_020A7A68   0x020A7A68  data
 *   str_020A7A78   0x020A7A78  data
 *   func_02082BCC  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   file_020A7A68  0x020A7A68  data
 *   g_021469D4     0x021469D4  data
 *   msg_020A7A7C   0x020A7A7C  data
 *   msg_020A7A88   0x020A7A88  data
 *   func_02087C6C  0x02087C6C  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   msg_020A7A94   0x020A7A94  data
 *   func_020395E0  0x020395E0  arm
 *   func_0203D378  0x0203D378  arm
 *   func_0203D394  0x0203D394  arm
 *   func_0203D4D0  0x0203D4D0  arm
 *   func_0203D650  0x0203D650  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_0203DAC4  0x0203DAC4  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *   file_020A7AB0  0x020A7AB0  data
 *   file_020A7ACC  0x020A7ACC  data
 *   g_021469D8     0x021469D8  data
 *   g_020A7AE8     0x020A7AE8  data
 *   g_020A7AF8     0x020A7AF8  data
 *   g_020A7AE8_arr 0x020A7AE8  data
 *   g_020A7B08     0x020A7B08  data
 *   sNet3730       0x020A7AF8  data
 *   sNet3733       0x020A7B20  data
 *   sNet3734       0x020A7B50  data
 *   g_020A7B78     0x020A7B78  data
 *   _u32_div_f     0x0209C2B0  arm
 *   g_020A7BA8     0x020A7BA8  data
 *   g_020A7BB4     0x020A7BB4  data
 *   func_020889C0     0x020889C0  arm
 *   func_0203F034     0x0203F034  arm
 *   func_0203F0A8     0x0203F0A8  arm
 *   g_02FFFC3C        0x02FFFC3C  data
 *   func_020370C8  0x020370C8  arm
 *   unk_0203C00C   0x0203C00C  arm
 */
#include "../../matched/include/Obj11351.h"
#include "../../matched/include/Obj15917.h"
#include "../../matched/include/Obj15920.h"
#include "../../matched/include/Obj15922.h"
#include "../../matched/include/Obj05734.h"
#include "../../matched/include/Obj11352.h"
#include "../../matched/include/Obj05735.h"
#include "../../matched/include/Obj15929.h"
#include "../../matched/include/Obj15930.h"
#include "../../matched/include/Obj06938.h"
#include "../../matched/include/Obj15931.h"
#include "../../matched/include/Obj15934.h"
#include "../../matched/include/Obj03449.h"
#include "../../matched/include/Obj06939.h"
#include "../../matched/include/Obj15941.h"
#include "../../matched/include/Obj08833.h"
#include "../../matched/include/Obj15944.h"
#include "../../matched/include/Obj15945.h"
#include "../../matched/include/Obj11357.h"
#include "../../matched/include/Obj11358.h"
#include "../../matched/include/Obj15949.h"
#include "../../matched/include/Obj04750.h"
#include "../../matched/include/Obj08835.h"
#include "../../matched/include/Obj15952.h"
#include "../../matched/include/Obj15954.h"
#include "../../matched/include/Obj06942.h"

struct Conn;
struct Hdr;
struct Entry;
struct Src;
struct St;
struct NetEntry;
struct Obj_02039C68;
struct RTCDate;
struct RTCTime;
struct NetState;
typedef unsigned char  u8;

typedef unsigned short u16;

struct Votes {
    u16 tag[8];
    u8  mask[8];
    u8  ready[8];
};

typedef unsigned int   u32;

typedef signed int     s32;

struct NetRing {
    u8  pad00[8];
    u32 state;          /* 0x08 */
    u8  pad0C[4];
};

/* The object g_021469D0 points at (0x1f0 bytes, allocated by func_02037288). */
struct Net {
    u8  *f00;           /* 0x00 */
    u8  *f04;
    u8  *f08;
    u8  *f0C;
    u8  *f10;
    u8  *f14;
    u8  *f18;
    struct NetRing f1C;
    struct NetRing f2C;
    struct NetRing f3C;
    struct NetRing f4C[8];
    u8  fCC[0x28];
    u8  fF4[0x28];
    u8  f11C[8][16];
    u8  f19C[16];
    u32 f1AC;
    int f1B0;
    int f1B4[8];
    u8  f1D4;
    u8  f1D5;
    u8  f1D6;
    u8  f1D7[8];
    u8  pad1DF;
    u32 f1E0;
    u16 f1E4;
    u8  pad1E6;
    u8  f1E7;
    u8  f1E8;
    u8  f1E9;
    u8  f1EA;
    u8  f1EB;
    u8  f1EC;
    u8  f1ED;
    u8  pad1EE[2];
};

struct Ctx_020377B8 {
    u8   pad00[0x340];
    u32 *f340;
};

struct Oth_020377B8 {
    u8 pad00[0x64];
    u8 f64;
    u8 f65;
};

struct Vtbl {
    u8   pad00[0x64];
    u32 (*f64)(u32, u32, u32, void *);   /* 0x64 */
    u8   pad68[0x70 - 0x68];
    u32 (*f70)(void);                    /* 0x70 */
};

struct Ctx_02037E60 {
    u8           pad00[0x340];
    struct Vtbl *f340;                   /* 0x340 */
};

struct Ctx {
    u8   pad00[0x340];
    u32 *f340;
};

struct Oth_02038380 {
    u8 pad00[0x65];
    u8 f65;
};

struct Oth {
    u8 pad00[0x64];
    u8 f64;
    u8 f65;
};

struct Hdr
{
    u8 f00;
    u8 f01;
    u8 f02;
    u8 f03;
    u8 f04;
    u8 f05;
    u8 f06;
    u8 body[1];
};

struct Glob_020377B8
{
    u8 pad_00[0x65];
    u8 f65;
};

struct Conn
{
    u8 pad_00[0x24];
    u32 f24;
};

struct Vt_020377B8
{
    u8 pad_00[0x7c];
    u8 (*f7c)(void);
    u8 pad_80[0x30];
    s32 (*fb0)(void);
};

struct Sys
{
    u8 pad_00[0x340];
    struct Vt_020377B8 *f340;
};

struct Buf
{
    void *ptr;
    u16 len;
};

struct Rec_020377B8 {
    u8  pad_00[0x64];
    u8  f64;
};

struct Err {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
};

typedef signed short   s16;

struct Src {
    u8  pad00[0x0c];
    s16 pos;
};

struct St {
    s32 done;
    u8 *dst;
    u16 left;
    u16 total;
    u16 h;
    u8  f0E;
    u8  f0F;
};

typedef signed char   s8;

typedef int           s32_020390BC;

typedef signed int     s32_020392B8;

struct Slots {
    u8 pad_00[0x80];
    s32 (*unk80)(void);
};

struct Owner_020377B8 {
    u8 pad_00[0x340];
    struct Slots *unk340;
};

struct Mode {
    u8 pad_00[0x65];
    u8 unk65;
};

struct LinkDriver_020377B8 {
    unsigned char pad00[0x7c];
    u32 (*get_mask)(void);
};

struct LinkRoot_020377B8 {
    unsigned char pad000[0x340];
    struct LinkDriver_020377B8 *driver;
};

struct LinkDriver_020393D0 {
    u8 pad00[0x88];
    int (*busy)(void);
};

struct LinkRoot_020393D0 {
    u8 pad000[0x340];
    struct LinkDriver_020393D0 *driver;
};

typedef struct {
    u8 pad_000[0x65];
    u8 f065;
} T_0203D798;

struct Session {
    u8 pad00[0x64];
    u8 unk_64;
    u8 state;
};

struct Entry {
    void *obj;
    u8    pad_04[4];
    void *slot[8];
    u8    pad_28[0x16];
    u16   key3e;
    u16   key40;
    u8    pad_42[2];
    u16   key44;
    u16   key46;
    u8    pad_48;
    u8    f49;
    u8    f4a;
    u8    pad_4b[5];
};

struct Owner_0203996C {
    u8 pad_00[0x70];
    struct Entry table[9];
};

struct Msg_02039B5C {
    u16 tag;
    u8  mask;
};

struct Msg_02039C2C {
    u16 tag;
};

struct Obj_0203996C {
    u16 pad[0x44 / 2];
    u16 tag;
};

struct Rec_0203996C {
    u8  pad_00[0x46];
    u16 tag;
    u8  slot;
    u8  remote;
};

struct Link {
    u8 pad_00[0x44];
    u16 unk44;
    u16 unk46;
    u8 unk48;
    u8 unk49;
};

struct Obj_02039C68 {
    u8   pad_00[8];
    void *slot[8];
    u8   pad_28[0x16];
    u16  key;
};

struct Msg
{
    u8 pad_00[6];
    u8 mac[6];
    u8 f0c;
    u8 f0d;
    u8 f0e;
    u8 f0f;
};

struct Peer
{
    u8 pad_00[0x4a];
    u8 f4a;
};

struct Glob_0203A118
{
    u8 pad_00[0xc];
    void (*f0c)(int, u32);
    u8 pad_10[0x57];
    u8 f67;
    u8 pad_68[6];
    u16 f6e;
};

struct Slot {
    void *buf;
    u32   len;
};

struct NetCmdGrp {
    void *list;
    int   count;
    u32   f8;
    u32   key;
};

struct NetCmdSlot {
    u32 f0;
    u32 f4;
    u32 f8;
    u16 fC;
    u16 fE;
    u16 f10;
    u16 f12;
    u16 f14;
    u8  f16;
    u8  f17;
};

struct NetCmdEnt {
    u32 f00;
    u32 f04;
    u16 f08;
    u16 f0A;
    u16 f0C;
    u16 f0E;
    u16 f10;
    u8  f12;
};

struct NetCmd {
    struct NetCmdGrp  grp[4];
    struct NetCmdSlot slot[5];
    struct NetCmdEnt  ent[9];
    u8 pad16c[0xb4];
    u8 f220[8];
    u8 f228;
    u8 pad229[3];
};

struct HugeRecv {
    u32 a;
    int count;
    u32 c;
    u32 key;
};

typedef struct {
    u8 lo : 4;
    u8 hi : 4;
} Status;

struct NetState {
    void *unk0;
    void *unk4;
    void *unk8;
    unsigned char pad[0x46 - 0xC];
    u16 unk46;
};

typedef unsigned long long u64;

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext64;

struct Date { u32 year; u32 mon; u32 day; u32 wday; };

struct Time { u32 hour; u32 min; u32 sec; };

struct Vt_0203A118 {
    u8  pad_00[4];
    void (*f04)(u16 key, void *obj, u32 zero, u32 arg);
};

struct Obj {
    u8         pad_00[0x340];
    struct Vt_0203A118 *f340;
    u8         pad_344[8];
    u32        f34c;
};

struct Cur {
    u8  pad_00[0x56];
    u16 f56;
    u8  pad_58[0xd];
    u8  f65;
};

struct Rec {
    u8  pad_00[0x2c];
    void (*f2c)(u32 a);
};

extern void *func_0203D798(void);
extern void *func_0203D788(void);
extern int func_02037288(u32 a0, u32 heap, u32 c);
extern void func_02037680(int i);
extern void  func_020377AC(void);
extern u32 func_020307B0(void *p);
extern void  func_02036B88(void *p);
extern u16 func_02039338(void);
extern int   func_020393A8(void);
extern u32  func_020370F4(u32 a);
extern int  func_020393D0(void);
extern void func_02037478(void);
extern u32 func_0203D6BC(void);
extern u32 func_0203D680(void);
extern int func_020366A8(struct Conn *p);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern struct Entry *func_020399A8(void);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void func_02036428(u8 *dst, u8 *src, s32 len);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02037224(u8 v, int b);
extern u32  func_02037258(void);
extern void func_02039548(void);
extern u32 func_0203CA98(void);
extern void func_0203C9AC(int a, u32 b, u32 c, u32 d);
extern void MI_CpuFill8(void *, u8, u32);
extern int func_02036A50(u32 list, u16 *info);
extern u32 func_0203C990(void);
extern int    func_02039594(void);
extern int    func_020368C0(void *tbl, u32 a, u32 b, u32 c, u32 d, u32 e,
                            u32 f);
extern int func_020365E8(char *p);
extern struct Entry *func_0203996C(s32 idx);
extern void func_02037234(u8 *p);
extern u32 func_02036540(u32 a);
extern u32 func_02036500(u32 a);
extern int  func_020364D4(struct Src *s, u8 *buf, u32 n, u32 max);
extern void func_02082D44(void *dst, const void *src, int n);
extern void func_0203666C(u32 h);
extern int func_02036B98(char *p, int v);
extern void *func_02082BCC(void *dst, int val, u32 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02087C6C(void *p);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern int func_020395E0(int slot);
extern u32 func_0203D378(void);
extern u32 func_0203D394(struct NetEntry *e);
extern u32 func_0203D4D0(u8 *e, u32 a, u32 b, u32 c, void *d, u32 e2, u32 f, u32 g2);
extern u32 func_0203D650(void);
extern void MI_CpuCopy8(const void *src, void *dst, u32 n);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void func_0203DAC4(const u8 *mac);
extern void OS_GetMacAddress(u8 *);
extern int func_020889C0(struct RTCDate *date, struct RTCTime *time);
extern void func_0203F034(u32 seed);
extern u32 func_0203F0A8(void);
extern void  func_020370C8(void);
extern void unk_0203C00C(void);
u32 func_020377B8(u8 arg0);
void func_0203781C(u32 arg);
void func_02037858(u32 arg);
void func_02037894(u8 a0, u16 a1, u32 a2, u32 a3);
u32 func_02037928(u32 a0, u16 a1);
int func_020379C8(u32 p);
void func_02037A44(int a);
void func_02037A6C(u32 a0, u32 a1, u16 a2, u32 a3);
void func_02037B08(void);
void func_02037BA4(void);
void func_02037BE8(u32 a);
int func_02037C10(void);
void func_02037D78(void);
int func_02037D98(int a);
void func_02037E60(void);
void func_02037F48(void);
void func_0203802C(void);
u32 func_020380E4(u32 a0, u8 *rec, u32 len);
void func_020381D8(u32 a0, u32 a1);
void func_02038298(void);
void func_02038340(void);
void func_02038380(void);
int func_02038524(void);
void func_02038570(void);
void func_020385C4(void);
int func_020387A0(u32 i, u8 *p, s32 n);
int func_02038924(u32 a0, u8 *p, s32 n);
int func_02038A48(int a);
int func_02038A90(u32 a);
s32 func_02038AE0(struct Hdr *h, struct Conn *c, s32 len, u8 a3);
int func_02038C18(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
void func_02038D30(int a0, int a1, int a2, int a3);
void func_02038D4C(int a0, int a1, int a2, int a3);
void func_02038D68(int a0, u32 a1, u32 a2, u8 *a3);
void func_02038DF0(struct Src *src, s32 a1, u8 *buf, struct St *st, u32 n);
void func_02039050(void);
void func_020390BC(void);
int func_02039160(u32 mode);
u32 func_020392B8(void);
int func_020392EC(void);
u16 sub_02039338(void);
int sub_020393A8(void);
int sub_020393D0(void);
u32 func_02039414(void);
void func_02039468(u32 a, u32 b);
int func_020394C0(void);
void sub_020394DC(u8 v);
void func_020394F0(u32 a);
void sub_02039548(void);
void sub_02039560(void);
void sub_02039578(void);
int sub_02039594(void);
int sub_020395E0(int slot);
int func_020395EC(struct Entry *a);
void func_02039658(struct Entry *e, u32 idx);
void func_0203971C(unsigned char *a, u32 b);
struct Entry *func_02039764(u32 idx);
void func_02039834(void);
void func_020398B4(void);
struct Entry *sub_0203996C(s32 idx);
struct Entry *sub_020399A8(void);
u32 func_020399B8(u8 *p);
int func_020399DC(struct Entry *p);
int func_020399EC(void);
void func_02039A2C(int a);
void func_02039A5C(void);
int func_02039ACC(void);
void func_02039B5C(u32 slot, u32 a1, struct Msg_02039B5C *msg, u32 a3, u32 link);
void func_02039C2C(u32 a0, u32 a1, struct Msg_02039C2C *msg, u32 a3, struct Obj_0203996C *obj);
void func_02039C3C(struct Rec_0203996C *p, u16 tag);
void sub_02039C68(struct Link *p, u32 lo, u32 hi);
u32 sub_02039CA0(struct Link *p, u32 key);
u32 sub_02039CB4(struct Link *p, u32 lo, u32 hi);
int func_02039CD8(struct Obj_02039C68 *p);
void func_02039D94(void);
void func_0203A020(u32 idx, u32 a1, const u8 *a2, u32 a3, u8 *base);
void func_0203A118(u8 *p);
void func_0203A150(int a0, int a1, struct Msg *msg, int a3, struct Peer *peer);
void func_0203A27C(u32 a0, u32 a1, u8 *msg, u32 a3, u32 a4);
u16 func_0203A28C(u16 mask, u32 idx, u32 set);
u32 func_0203A2F0(u32 a0, u32 a1);
void func_0203A338(u32 a0);
void func_0203A388(int id, u32 len, const void *src, u32 a3, void *obj);
void func_0203A424(char *p, int a, int b, int c);
void func_0203A458(u8 *a0, u32 a1);
void func_0203A494(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
void func_0203A53C(void);
void func_0203A574(u32 a, u32 b, u32 c, u32 d);
void func_0203A5E4(u32 key);
u32 func_0203A634(u32 a0);
struct NetCmdGrp *func_0203A67C(u32 cmd);
int func_0203A70C(u32 idx);
u32 func_0203A730(u32 cmd);
int func_0203A748(u32 idx);
void func_0203A770(u32 a, u32 b, int c, u32 d, u32 e, u32 f);
int func_0203A7EC(unsigned int idx);
int func_0203A804(unsigned int idx);
u32 func_0203A81C(u32 a0, u32 a1, u32 a2);
void func_0203A858(void);
void func_0203A85C(int a0, u32 a1, void *a2, int a3, volatile int a4);
void func_0203A958(int a0, int a1, const u8 *a2, int a3, int a4);
u32 func_0203AA94(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
u32 func_0203ABC0(void);
void func_0203ACAC(void);
void func_0203AD74(struct NetState *s, void *p, u16 v);
void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
void func_0203AD8C(u32 a0);
void func_0203AE20(MATHRandContext64 *o);
void func_0203AEEC(u8 *p);
void func_0203AF40(struct Rec *p);
extern u8 g_020A7A20[];
extern struct Net *g_021469D0;
extern u8 lbl_020A7A20[];
extern u8 d_020A7A20[];
extern u8 d_020A7A24[];
extern u8 d_020A7A50[];
extern const u8 str_020A7A24[];
extern const u8 str_020A7A54[];
extern u8   g_020A7A24[];
extern u8   g_020A7A50[];
extern const u8 str_020A7A50[];
extern const u8 str_020A7A68[];
extern const u8 str_020A7A78[];
extern const char file_020A7A68[];
extern struct Votes *g_021469D4;
extern const char msg_020A7A7C[];
extern const char msg_020A7A88[];
extern const char msg_020A7A94[];
extern const char file_020A7AB0[];
extern const char file_020A7ACC[];
extern struct NetCmd *g_021469D8;
extern struct NetCmdGrp g_020A7AE8;
extern char  g_020A7AF8[];
extern struct NetCmdGrp g_020A7AE8_arr;
extern char   g_020A7B08[];
extern char sNet3730[];
extern char sNet3733[];
extern char sNet3734[];
extern char  g_020A7B78[];
extern u8  *g_021469DC;
extern char g_020A7BA8[];
extern char g_020A7BB4[];
extern u32 g_02FFFC3C;





















/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020377B8.c \
 *       --func func_020377B8 --addr 0x020377B8 --cc 1.1p1 --arm
 */
u32 func_020377B8(u8 arg0)
{
    u32 zero;
    char *a = func_0203D798();
    char *b = func_0203D788();
    u16 val;
    void (*f)(void *);

    ((struct Obj11351 *)a)->f66 = arg0;
    f = *(void (**)(void *))(*(char * *)&((struct Obj15917 *)b)->f340 + 0x68);
    f(func_020377AC);

    zero = 0;
    val = ((struct Obj11351 *)a)->f56;
    func_02037288(0x80, val, zero);

    func_02037680(zero);
    func_02037680(1);
    func_02037680(2);

    return 1;
}





















/*
 * Reset-and-notify hook: two context getters, the per-slot reset for `arg`,
 * and then the hook at +8 of the first context if it is installed, called with
 * the first context's word at +0x34C and the incoming argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203781C.c \
 *       --func func_0203781C --addr 0x0203781C --cc 1.1p1 --arm
 */
void func_0203781C(u32 arg)
{
    char *a = func_0203D798();
    char *b = func_0203D788();
    void (*hook)(u32, u32);

    func_02037680(arg);

    hook = *(void (**)(u32, u32))(a + 8);
    if (hook == 0)
        return;
    hook(((struct Obj15920 *)b)->f34C, arg);
}





















/*
 * Byte-for-byte twin of func_0203781C (same 60 bytes, same call order): two
 * context getters, the per-slot reset for `arg`, then the hook at +8 of the
 * first context when it is installed, called with the first context's word at
 * +0x34C and the argument.  Two copies of the same 60 bytes exist in the image
 * and this is the second, so the pair also demonstrates that the listing's
 * duplicate-glue pattern is real code and not one function reached twice.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037858.c \
 *       --func func_02037858 --addr 0x02037858 --cc 1.1p1 --arm
 */
void func_02037858(u32 arg)
{
    char *a = func_0203D798();
    char *b = func_0203D788();
    void (*hook)(u32, u32);

    func_02037680(arg);

    hook = *(void (**)(u32, u32))(a + 8);
    if (hook == 0)
        return;
    hook(((struct Obj15922 *)b)->f34C, arg);
}




















/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037894.c \
 *       --func func_02037894 --addr 0x02037894 --cc 1.1p1 --arm
 */
void func_02037894(u8 a0, u16 a1, u32 a2, u32 a3)
{
    char *a = func_0203D798();
    char *b = func_0203D788();
    u32 flag;
    u16 val;
    void (*f1)(void *);
    void (*f2)(void *);
    void (*f3)(u32, u32);

    ((struct Obj11352 *)a)->f66 = a0;

    f1 = *(void (**)(void *))(*(char * *)&((struct Obj05734 *)b)->f340 + 0x3C);
    f1(func_0203781C);

    f2 = *(void (**)(void *))(*(char * *)&((struct Obj05734 *)b)->f340 + 0x68);
    f2(func_020387A0);

    if (((struct Obj05734 *)b)->f64 != 0 && ((struct Obj05734 *)b)->f6C != 0) {
        flag = 1;
    } else {
        flag = 0;
    }

    a = func_0203D798();
    val = ((struct Obj11352 *)a)->f56;
    func_02037288(a1, val, flag);

    f3 = *(void (**)(u32, u32))(*(char * *)&((struct Obj05734 *)b)->f340 + 0x40);
    f3(a2, a3);
}




















/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037928.c \
 *       --func func_02037928 --addr 0x02037928 --cc 1.1p1 --arm
 */
u32 func_02037928(u32 a0, u16 a1)
{
    char *b = func_0203D788();
    void (*f1)(void *);
    u32 (*f2)(u32, u32);
    void (*f3)(void *);
    u32 res;
    u32 flag;
    char *a;
    u16 val;

    f1 = *(void (**)(void *))(*(char * *)&((struct Obj05735 *)b)->f340 + 0x3C);
    f1(func_02037858);

    f2 = *(u32 (**)(u32, u32))(*(char * *)&((struct Obj05735 *)b)->f340 + 0x44);
    res = f2(a0, 0);

    if (res == 1) {
        f3 = *(void (**)(void *))(*(char * *)&((struct Obj05735 *)b)->f340 + 0x68);
        f3(func_02038924);

        if (((struct Obj05735 *)b)->f64 != 0 && ((struct Obj05735 *)b)->f6C != 0) {
            flag = 1;
        } else {
            flag = 0;
        }

        a = func_0203D798();
        val = ((struct Obj15929 *)a)->f56;
        func_02037288(a1, val, flag);

        g_020A7A20[1] = 4;
    }

    return res;
}




















/*
 * Context teardown through three vtable slots at +0x3c, +0xbc and +0x68 of the
 * object the context's word at +0x340 names.  The first and third are handed a
 * function address as their argument (0x02037858 and 0x02038924), which is why
 * the pool holds two code pointers; the +0xbc slot's answer decides whether the
 * rest runs, and the byte at +1 of the object at 0x020A7A20 is set to 4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020379C8.c \
 *       --func func_020379C8 --addr 0x020379C8 --cc 1.1p1 --arm
 */
int func_020379C8(u32 p)
{
    int   r;
    char *c = func_0203D788();

    (*(void (**)(u32))(*(char **)(c + 0x340) + 0x3C))((u32)func_02037858);
    r = (*(int (**)(void))(*(char **)(c + 0x340) + 0xBC))();
    if (r == 1) {
        (*(void (**)(u32))(*(char **)(c + 0x340) + 0x68))((u32)func_02038924);
        func_02037288(p, *(u16 *)((char *)func_0203D798() + 0x56), 0);
        g_020A7A20[1] = 4;
    }
    return r;
}




















void func_02037A44(int a)
{
    int *r = func_0203D788();
    int *t = *(int * *)&((struct Obj15930 *)r)->f340;
    if (t == 0)
        return;
    ((void (*)(int))t[0x30])(a);
}





















/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037A6C.c \
 *       --func func_02037A6C --addr 0x02037A6C --cc 1.1p1 --arm
 */
void func_02037A6C(u32 a0, u32 a1, u16 a2, u32 a3)
{
    char *b = func_0203D788();
    char *a = func_0203D798();
    void (*f1)(void *);
    u32 flag;
    u16 val;
    void (*f2)(u32, u32, u32, u32, u32);

    f1 = *(void (**)(void *))(*(char * *)&((struct Obj06938 *)b)->f340 + 0x68);
    f1(func_02038924);

    if (a0 != 0) {
        if (((struct Obj06938 *)b)->f64 != 0 && ((struct Obj06938 *)b)->f6C != 0) {
            flag = 1;
        } else {
            flag = 0;
        }

        a = func_0203D798();
        val = ((struct Obj15931 *)a)->f56;
        func_02037288(a2, val, flag);

        g_020A7A20[1] = 4;
    }

    f2 = *(void (**)(u32, u32, u32, u32, u32))(*(char * *)&((struct Obj06938 *)b)->f340 + 0x48);
    f2(a0, a1, 0, 0, a3);
}





















/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037B08.c \
 *       --func func_02037B08 --addr 0x02037B08 --cc 1.1p1 --arm
 */
void func_02037B08(void)
{
    func_0203D788();
    func_0203D798();

    if (g_021469D0 == 0) {
        return;
    }

    func_020307B0(g_021469D0->f14);
    func_020307B0(g_021469D0->f18);
    func_020307B0(g_021469D0->f10);

    func_02036B88(g_021469D0->fF4);
    func_02036B88(g_021469D0->fCC);

    func_020307B0(g_021469D0->f00);
    func_020307B0(g_021469D0->f04);
    func_020307B0(g_021469D0->f08);
    func_020307B0(g_021469D0->f0C);

    func_020307B0(g_021469D0);

    g_021469D0 = 0;
}



















/*
 * 64 bytes gated on the byte at +0x1EC of the object the global pointer names:
 * when it is set, the first getter's non-zero answer runs func_02037B08 and
 * returns, the second getter's non-zero answer returns without it, and
 * everything else runs func_02037B08.  The two `bl func_02037B08` are separate
 * copies in the original, which is what the two arms give.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037BA4.c \
 *       --func func_02037BA4 --addr 0x02037BA4 --cc 1.1p1 --arm
 */
void func_02037BA4(void)
{
    if (g_021469D0->f1EC == 0)
        return;
    if (func_02039338() == 0) {
        if (func_020393A8() == 0)
            func_02037B08();
        return;
    }
    func_02037B08();
}



















/*
 * Guards the eight-slot table behind the global at 0x021469D0: an unarmed
 * global returns through `popeq`, an index past 7 through `popcs` (the compare
 * is unsigned, so a negative index is rejected as well), and only a live slot
 * reaches func_02037680.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037BE8.c \
 *       --func func_02037BE8 --addr 0x02037BE8 --cc 1.1p1 --arm
 */
void func_02037BE8(u32 a)
{
    if (g_021469D0 == 0)
        return;
    if (a >= 8)
        return;
    func_02037680(a);
}



















/*
 * The net tick dispatcher.  Two shapes are load-bearing: the f1EA/0x393D0
 * early exit is an out-of-line `goto bail` block placed AFTER the main body,
 * and the main path's `return 1` is reached by a `goto done` that lands on
 * the SAME `mov r0,#1; pop` the bail block falls into.  Writing either as a
 * plain `return 1` duplicates the epilogue and loses the `b #0x2037d6c`.
 */
int func_02037C10(void)
{
    struct Ctx_020377B8 *c = func_0203D788();
    struct Oth_020377B8 *o = func_0203D798();

    if (g_021469D0 == 0) {
        if (c != 0)
            ((void (*)(u32))c->f340[0xc / 4])(0);
        return 1;
    }

    {
        u32 (*h)(void) = (u32 (*)(void))c->f340[0x84 / 4];
        if (h != 0) {
            func_020370F4(h());
        }
    }

    if (g_021469D0->f1EA != 0)
        goto bail;
    if (func_020393D0() != 0)
        goto bail;

    if (o->f64 == 0 && (o->f65 == 0 || o->f65 == 5)) {
        func_02037F48();
    } else if ((u8)(o->f65 + 0xfd) <= 1) {
        func_0203802C();
    } else if ((u8)(o->f65 + 0xff) <= 1) {
        func_02038298();
    } else {
        func_02038340();
        func_02039050();
        if (func_02039338() == 0) {
            if (func_02039160(0) != 0 && o->f64 != 0)
                func_020385C4();
        }
        if (func_02039338() != 0)
            goto skip;
    }
    func_020390BC();
skip:
    if (o->f65 != 1 && o->f65 != 2) {
        ((void (*)(u16))c->f340[0xc / 4])(
            g_021469D0->f1E4);
    }
    func_0203ACAC();
    func_02037BA4();
    goto done;

bail:
    ((void (*)(u32))c->f340[0xc / 4])(0);
done:
    return 1;
}


















/*
 * Teardown hook for the same global src/matched/func_02037BE8.c guards: the
 * armed pointer goes to func_02037478, an unarmed one is a `popeq`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037D78.c \
 *       --func func_02037D78 --addr 0x02037D78 --cc 1.1p1 --arm
 */
void func_02037D78(void)
{
    struct Net *v;

    v = g_021469D0;
    if (v == 0)
        return;
    func_02037478();
}


















int func_02037D98(int a)
{
    int r = 0;
    if (lbl_020A7A20[1] != 4)
        return r;
    if (a != 0) {
        struct Net *p = g_021469D0;
        if (p->f1B0 > 0)
            return r;
        if (func_02038AE0((struct Hdr *)p->f00, (struct Conn *)p->fCC, func_0203D6BC(), p->f1D5) != 0) {
            struct Net *q = g_021469D0;
            q->f1D5++;
        }
        lbl_020A7A20[1] = 0;
        r = 1;
    } else {
        struct Net *p = g_021469D0;
        if (func_02038AE0((struct Hdr *)p->f00, (struct Conn *)p->fCC, func_0203D6BC(), p->f1D5) != 0) {
            struct Net *q = g_021469D0;
            q->f1D5++;
            lbl_020A7A20[1] = 0;
            r = 1;
        }
    }
    return r;
}
















void func_02037E60(void)
{
    struct Ctx_02037E60 *c = func_0203D788();
    u32 v = func_0203D6BC();
    u32 r;

    r = c->f340->f70();
    if (r == 0)
        return;
    r = func_02039338();
    r = func_02039160(r);
    if (r == 0)
        return;
    if (g_020A7A20[1] != 0)
        return;
    if (func_02039338() != 0) {
        r = c->f340->f64((u32)g_021469D0->f00, v, 0, func_02038A48);
        if (r == 0)
            return;
        g_020A7A20[1] = 2;
        g_021469D0->f1B0 = g_021469D0->f1B0 + 1;
    } else {
        g_020A7A20[1] = 2;
        func_02038A48(1);
        func_020387A0(0, (u8 *)g_021469D0->f00, (u16)v);
        g_021469D0->f1B0 = g_021469D0->f1B0 + 1;
    }
}

















/*
 * Declaration order is what closes this one: p must be declared LAST of the
 * four locals so it takes r6 and the loop index takes r4 (see
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 * The failure arm of the +0x5C poll is an out-of-line `goto`, not an
 * if-converted tail; the (u16) truncation of v happens after the n>0 test
 * and the index is zeroed before it.
 */
void func_02037F48(void)
{
    s32 i;
    s32 n;
    u32 v;
    u8 *p;

    p = func_0203D788();

    if (((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0x58))() == 0)
        return;

    if (g_021469D0->f1EB != 0)
        func_02037D98(1);

    if (((u32 (*)(u32)) * (u32 *)(*(u32 *)(p + 0x340) + 0x5C))((u32)g_021469D0->f00) != 1)
        goto fail;

    *(u8 *)(d_020A7A20 + 1) = 4;
    g_021469D0->f1EB = 1;

    v = func_0203D6BC();
    n = func_0203D680();
    i = 0;
    if (n > 0) {
        v = (unsigned short)v;
        do {
        func_020387A0((unsigned short)i,
                      (u8 *)(((u32 (*)(u32))
                           * (u32 *)(*(u32 *)(p + 0x340) + 0x60))(i)), v);
            i++;
        } while (i < n);
    }
    return;

fail:
    g_021469D0->f1EB = 0;
}

















/*
 * Fourth entry of this packet's chain, and the one the lane table expected to
 * need two callees filed: it calls func_020381D8, whose own entry is in this
 * shard, so that site resolves through `matched`; 0x020366A8 and 0x0203D3A8,
 * the other two the table named, turn out to have outside witnesses
 * (0x02038B48 and 0x02039AAC) once the compared range is this one function
 * rather than the whole packet.
 *
 * The two literals in the tail are different objects: the first argument to
 * func_020381D8 is one dereference of the 0x021469D0 pointer word, and the
 * final store is into the byte at 0x020A7A20 + 1.  Reading them as the same
 * symbol makes the compiler pool the address once and spend a second
 * callee-saved register on the transfer value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203802C.c \
 *       --func func_0203802C --addr 0x0203802C --cc 1.1p1 --arm
 */
void func_0203802C(void)
{
    u8 *p;
    u32 v;

    p = func_0203D788();

    if (func_020366A8((struct Conn *)g_021469D0->fCC) != 0)
        func_0203D3A8(func_020399A8(), 0x10, 0, 0);

    v = *(u32 *)(((struct Obj15934 *)p)->f340 + 0x9C);
    if (v != 0)
        ((void (*)(void))v)();
    if (((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0x6C))() != 1)
        return;

    v = func_0203D6BC();
    if (((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0xA0))() != 1)
        return;
    if (func_02037D98(0) == 0)
        return;

    func_020381D8((u32)g_021469D0->f00, v);
    *(u8 *)(d_020A7A20 + 1) = 4;
}

















/*
 * Validates one incoming record against the per-slot table reached through
 * 0x021469D0: the byte at +4 of the record is a presence/state tag (0xFF is
 * "locked out", bit 1 is the "no free slot" rejection), then the two-byte
 * header of the body is checked against the result of 0x0203F1FC, then the
 * slot's own counter byte at 0x1D7+slot is compared with rec[5]-1 before
 * being overwritten with rec[5].  Slot `a0` lives at 0x54 + (a0 << 4), so the
 * per-slot block is 16 bytes and the counter table is a byte array.
 *
 * The +8 bit of rec[4] biases the third argument by 0xFF; both the globals are
 * re-read from the pointer word after every call, which is why the C indexes
 * g_021469D0 directly instead of caching it in a local.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020380E4.c \
 *       --func func_020380E4 --addr 0x020380E4 --cc 1.1p1 --arm
 */
u32 func_020380E4(u32 a0, u8 *rec, u32 len)
{
    int v;
    u32 n;

    func_0203D798();
    func_0203D6BC();

    if (rec[4] == 0xFF)
        return 0;
    if (g_021469D0->f4C[a0].state == 0 && (rec[4] & 2))
        return 0;

    v = func_0203F1FC(rec + 2, len - 2);
    if (rec[0] != (u8)v || ((v & 0xFF00) >> 8) != rec[1])
        return 0;
    if (g_021469D0->f1D7[a0] != 0 &&
        (u8)(rec[5] - 1) != g_021469D0->f1D7[a0])
        return 0;

    g_021469D0->f1D7[a0] = rec[5];
    n = rec[2];
    if (rec[4] & 8)
        n += 0xFF;
    func_02036428((u8 *)&g_021469D0->f4C[a0], rec + 7, n);
    g_021469D0->f4C[a0].state = 1;
    return 1;
}

















/*
 * Second half of this packet's chain: it calls func_020380E4, whose own entry
 * is in this shard, so the call site is attested by `matched` rather than by
 * the single in-range witness the lane table saw.
 *
 * The flow: two global locks are set up, then the interface object reached
 * through *(p + 0x340) is asked twice (its +0xA4 and +0xAC entries); only if
 * both answer non-zero does the transfer run - otherwise the two literals at
 * 0x020A7A24/0x020A7A50 go to 0x02034714 with 0x400.  The transfer calls the
 * object's +0x64 entry with the two arguments and zeroed r2/r3, reads the
 * +0x80 entry for the record number, and hands (u16)record-number, first
 * argument and (u16)second argument to func_020380E4 before the fixed 4 /
 * 0x40C delay through 0x02037224.
 *
 * The guards' polarity is the `bne` / `beq` pair at +0x2C and +0x38: the two
 * object calls are one conjunction whose false arm is the failure block
 * written first, which is the if/else spelling and not a guard chain.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020381D8.c \
 *       --func func_020381D8 --addr 0x020381D8 --cc 1.1p1 --arm
 */
void func_020381D8(u32 a0, u32 a1)
{
    u8 *p;
    u32 v;

    func_0203D798();
    p = func_0203D788();

    if (((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0xA4))() == 0 ||
        ((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0xAC))() == 0) {
        func_02034714((const char *)d_020A7A24, 0x400, (const char *)d_020A7A50);
        return;
    }

    if (*(u8 *)(d_020A7A20 + 1) != 0)
        return;
    ((void (*)(u32, u32, u32, u32))
         * (u32 *)(*(u32 *)(p + 0x340) + 0x64))(a0, a1, 0, 0);
    v = ((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0x80))();
    func_020380E4((u16)v, (u8 *)a0, (u16)a1);
    func_02037224(4, 0x40C);
}

















/*
 * Third entry of this packet's chain, and the one that shows why the object
 * word has to be re-read rather than cached: 0x021469D0 is a pointer word and
 * every use of the object it points at goes back through the pool address, so
 * the C indexes g_021469D0 directly each time.
 *
 * The state machine is three bytes of the object (0x1E7 = "armed", 0x1ED =
 * "in flight", 0x1D5 = a mode byte feeding 0x02038AE0): returning early
 * unless armed, arming the in-flight flag once 0x02038AE0 agrees, and only
 * then running the object's +0x64 entry, which clears the flag when it
 * returns non-zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02038298.c \
 *       --func func_02038298 --addr 0x02038298 --cc 1.1p1 --arm
 */
void func_02038298(void)
{
    u8 *p;
    u32 v;

    func_0203D798();
    p = func_0203D788();
    v = func_0203D6BC();

    if (g_021469D0->f1E7 == 0)
        return;
    if (g_021469D0->f1ED == 0) {
        if (func_02038AE0((struct Hdr *)g_021469D0->f00, (struct Conn *)g_021469D0->fCC,
                          func_0203D6BC(),
                          g_021469D0->f1D5) != 0)
            g_021469D0->f1ED = 1;
    }

    if (g_021469D0->f1ED != 1)
        return;
    if (((u32 (*)(u32, u32, u32, u32))
             * (u32 *)(*(u32 *)(p + 0x340) + 0x64))((u32)g_021469D0->f00, v,
                                                    0, 0) == 0)
        return;
    g_021469D0->f1ED = 0;
}
















/*
 * Promoted from src/pending/ on lane 1.  All 64 concrete bytes are right; the
 * one open site was the PC24 at +0x0038, the `bl` to func_02037E60, which had
 * exactly one branch reference in the whole image (this one) and so no
 * `label` witness.  With src/matched/func_02037E60.c filed EXACT the site
 * resolves through the `matched` class and the file prints EXACT with no
 * change to its C.
 *
 * The reading: refresh the UI object, ask its +0x340 owner's +0x70 virtual
 * whether the session is still up, then let the two teardown probes decide
 * whether func_02037D98(1) and func_02037E60 are reached.  The first
 * func_0203D798() result is discarded - the image overwrites r0 with
 * func_0203D788()'s answer immediately - which is why the call stands on its
 * own statement rather than as an initialiser.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02038340.c \
 *       --func func_02038340 --addr 0x02038340 --cc 1.1p1 --arm
 */
void func_02038340(void)
{
    void *p;

    func_0203D798();
    p = func_0203D788();
    if (((int (*)(void))*(unsigned int *)(*(unsigned int *)((char *)p + 0x340) + 0x70))() == 0)
        return;
    if (func_02039160(func_02039338()) == 0)
        return;
    func_02037D98(1);
    func_02037E60();
}














void func_02038380(void)
{
    struct Ctx *c = func_0203D788();

    func_0203D680();
    if (g_020A7A20[0] == 1) {
        if ((int)func_020392B8() > 1) {
            func_02037224(2, 0x46a);
            if (((int (*)(void))c->f340[0x70 / 4])() != 0) {
                u32 t = func_02037258();
                if (((int (*)(u32, u32, u32, u32))c->f340[0x64 / 4])(
                        (u32)g_021469D0->f08, t, 0, (u32)func_02038A90) != 0)
                    goto tail;
                func_02037224(1, 0x46a + 4);
                goto tail;
            }
            if (((struct Oth_02038380 *)func_0203D798())->f65 != 3 && ((struct Oth_02038380 *)func_0203D798())->f65 != 4)
                goto tail;
            if (((int (*)(void))c->f340[0xa0 / 4])() == 0) {
                func_02037224(1, 0x475);
                goto tail;
            }
            if (g_021469D0->f08[2] == 0)
                return;
            {
                u32 t = func_0203D6BC();
                ((void (*)(u32, u32, u32, u32))c->f340[0x64 / 4])(
                    (u32)g_021469D0->f08, t, 0x64, 0);
            }
        }
    }
tail:
    if (g_020A7A20[0] == 2) {
        func_02038570();
        func_02038924(0, g_021469D0->f08, (u16)func_02037258());
        func_02037224(3, 0x490 - 3);
    }
    if (((int (*)(void))c->f340[0x70 / 4])() == 0)
        goto last;
    if (((struct Oth_02038380 *)func_0203D798())->f65 == 3)
        goto last;
    if (((struct Oth_02038380 *)func_0203D798())->f65 != 4)
        return;
last:
    func_02037224(4, 0x492);
}













int func_02038524(void)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (func_02039160((u16)i) != 0 && g_021469D0->f1B4[i] > 0) {
            return 0;
        }
    }
    return 1;
}














void func_02038570(void)
{
    int i;
    int n = func_0203D680();

    for (i = 0; i < n; i++) {
        if (func_02039160((u16)i) != 0) {
            g_021469D0->f1B4[i] += 1;
        }
    }
}














/*
 * net_system.c.  The outer per-frame entry: it dispatches on the link-state
 * byte at +0x65 of the 0x0203D798 object, in two two-wide bands written as
 * unsigned-wrapped range tests ((u8)(s - 1) <= 1 and (u8)(s - 3) <= 1), and
 * falls through to func_02038380 in both of the middle bands.
 * func_02037224 takes the caller's __LINE__ as its second argument; the four
 * line numbers are 0x4d5, 0x4da, 0x4e1 and 0x4f4.  The assert at +0x50 is
 * the usual func_02034714(file, line, expr) triple.
 */
void func_020385C4(void)
{
    struct Ctx *c = func_0203D788();
    struct Oth *o = func_0203D798();
    u8 s = o->f65;

    if ((u8)(s + 0xff) <= 1) {
        if (func_02039160(0) == 0)
            return;
        if (o->f64 != 0)
            func_02034714((const char *)str_020A7A24, 0x4d5, (const char *)str_020A7A54);
        if (g_020A7A20[0] == 4 && g_021469D0->f1AC != 0
            && func_02038524() != 0)
            func_02037224(1, 0x4da);
        if (g_020A7A20[0] != 1)
            return;
        {
            u32 t = func_02037258();
            if (((int (*)(u32, u32, u32, u32))c->f340[0x64 / 4])(
                    (u32)g_021469D0->f08, t, 0, 0) == 0)
                return;
        }
        func_02037224(4, 0x4e1);
        func_02038570();
        return;
    }
    if ((u8)(s + 0xfd) <= 1) {
        if (g_020A7A20[0] == 4) {
            struct Net *g = g_021469D0;
            u32 t = func_02037258();

            func_02038AE0((struct Hdr *)g->f08, (struct Conn *)g->fF4, t, g->f1D4);
            g = g_021469D0;
            g->f1D4 = (u8)(g->f1D4 + 1);
            func_02037224(1, 0x4f4);
        }
        func_02038380();
        return;
    }
    if (((int (*)(void))c->f340[0x70 / 4])() == 0)
        return;
    if (func_02038524() == 0)
        return;
    if (g_020A7A20[0] == 4) {
        struct Net *g = g_021469D0;
        u32 t = func_02037258();

        func_02038AE0((struct Hdr *)g->f08, (struct Conn *)g->fF4, t, g->f1D4);
        g = g_021469D0;
        g->f1D4 = (u8)(g->f1D4 + 1);
        func_02037224(1, 0x501);
    }
    func_02038380();
}














/*
 * The indexed twin of src/matched/func_02038924.c (the own-slot variant):
 * same receive/validate/copy shape, but every global offset is scaled by
 * the slot index -- the 0x1B4 credit counter by i*4, the 0x54 accepted
 * flag and the 0x4C payload by i*16, the 0x1D7 sequence byte by i.  The
 * extra middle block this one has and 0x02038924 does not is the sequence
 * check at 0x1D7+i with its own 0x3F3 error line.
 */
int func_020387A0(u32 i, u8 *p, s32 n)
{
    struct Net *g;
    u8 *q;
    u32 v;
    s32 len;
    int r;

    func_0203D6BC();
    if (p == 0)
        return 0;
    g = g_021469D0;
    g->f1B4[i] = g->f1B4[i] - 1;
    if (i == 0)
        g_021469D0->f1E4 = p[3];
    v = p[4];
    if (v == 0xff)
        return 0;
    if (g_021469D0->f4C[i].state == 0) {
        if (v & 2)
            return 0;
    }
    r = func_0203F1FC(p + 2, n - 2);
    if (p[0] != (u8)r || ((r & 0xff00) >> 8) != p[1]) {
        func_02039548();
        q = (u8 *)func_0203CA98();
        if (((struct Obj03449 *)q)->fC == 0)
            func_0203C9AC(((struct Obj03449 *)q)->f0, ((struct Obj03449 *)q)->f4, ((struct Obj03449 *)q)->f8, 0x3f2);
        return 0;
    }
    {
        u8 *s = g_021469D0->f1D7;
        if (s[i] != 0 && (u8)(p[5] - 1) != s[i]) {
            func_02039548();
            q = (u8 *)func_0203CA98();
            if (((struct Obj03449 *)q)->fC == 0)
                func_0203C9AC(((struct Obj03449 *)q)->f0, ((struct Obj03449 *)q)->f4, ((struct Obj03449 *)q)->f8, 0x3f3);
            return 0;
        }
        s[i] = p[5];
    }
    len = p[2];
    if (p[4] & 8)
        len += 0xff;
    func_02036428((u8 *)&g_021469D0->f4C[i], p + 7, len);
    g_021469D0->f4C[i].state = 1;
    return 1;
}













int func_02038924(u32 a0, u8 *p, s32 n)
{
    struct Net *g;
    u8 *q;
    u32 v;
    s32 len;
    int r;

    (int)func_0203D798();
    func_0203D6BC();
    g = g_021469D0;
    g->f1B0 = g->f1B0 - 1;
    if (p == 0)
        return 0;
    if (a0 == 0)
        g_021469D0->f1E4 = p[3];
    v = p[4];
    if (v == 0xff)
        return 0;
    if (g_021469D0->f2C.state == 0) {
        if (v & 2)
            return 0;
    }
    r = func_0203F1FC((const u8 *)(p + 2), n - 2);
    if (p[0] != (u8)r || ((r & 0xff00) >> 8) != p[1]) {
        func_02039548();
        q = (u8 *)func_0203CA98();
        if (((struct Obj06939 *)q)->fC == 0)
            func_0203C9AC(((struct Obj06939 *)q)->f0, ((struct Obj06939 *)q)->f4, ((struct Obj06939 *)q)->f8, 0x3f2);
        return 0;
    }
    g_021469D0->f1D6 = p[5];
    len = p[2];
    if (p[4] & 8)
        len += 0xff;
    func_02036428((u8 *)&g_021469D0->f2C, p + 7, len);
    g_021469D0->f2C.state = 1;
    return 1;
}













/*
 * Idempotent bring-up: when the argument is non-zero and the mode byte at
 * 0x020A7A21 still reads 2, it is flipped to 4 and the call is skipped; in
 * every other case the 0x5C0-byte block at 0x020A7A24 is handed to
 * func_02034714 with 0x020A7A50 as the third argument.  Either way the
 * function answers 1 through the single shared epilogue (`mov r0, #1;
 * pop {r3, pc}`), which is why the taken arm ends in `beq` to that epilogue
 * and not in a predicated return.
 *
 * The three globals are *arrays*, not pointers: the image loads the pool word
 * straight into r0 and then does `ldrb r1, [r0, #1]`, so `extern u8
 * g_020A7A20[]` with a `[1]` subscript is the spelling that reproduces it - as
 * `extern u8 *g_020A7A20` the compiler adds a second load and the file grows
 * to 88 bytes.  The arm's two instructions are predicated (`moveq`/`strbeq`)
 * rather than branched.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02038A48.c \
 *       --func func_02038A48 --addr 0x02038A48 --cc 1.1p1 --arm
 */
int func_02038A48(int a)
{
    if (a != 0 && g_020A7A20[1] == 2) {
        g_020A7A20[1] = 4;
    } else {
        func_02034714((const char *)g_020A7A24, 0x5C0, (const char *)g_020A7A50);
    }
    return 1;
}













int func_02038A90(u32 a)
{
    func_0203D6BC();
    func_0203D680();
    func_0203D798();
    if (a != 0) {
        func_02037224(4, 0x5d4);
    } else {
        func_02034714((const char *)str_020A7A24, 0x5d8, (const char *)str_020A7A50);
    }
    return 1;
}













s32 func_02038AE0(struct Hdr *h, struct Conn *c, s32 len, u8 a3)
{
    struct Glob_020377B8 *g;
    struct Sys *sys;
    struct Buf buf;
    s32 n;
    u16 v;

    g = func_0203D798();
    sys = func_0203D788();

    MI_CpuFill8(h, 0, (u32)len);

    if (c->f24 == 0)
        h->f04 = 1;
    else
        h->f04 = 2;
    c->f24 = 0;

    h->f03 = sys->f340->f7c();

    if (func_020366A8(c) == 0)
    {
        if ((u8)(g->f65 + 0xfd) > 1)
            goto body;
        if (sys->f340->fb0() != 1)
            goto body;
    }
    h->f04 = 0xff;
    return 0;

body:
    ;

    buf.len = (u16)(len - 7);
    buf.ptr = &h->body[0];
    if (func_02036A50((u32)c, (u16 *)(&buf)) == 0)
        c->f24 = 1;

    if (buf.len != 0xffff)
        n = (len - buf.len) - 7;
    else
        n = len - 7;

    if (n > 0xff)
    {
        n = n + 1;
        h->f04 = h->f04 | 8;
    }

    h->f02 = (u8)n;
    h->f05 = a3;

    v = func_0203F1FC(&h->f02, len - 2);
    h->f00 = (u8)v;
    h->f01 = (u8)((v & 0xff00) >> 8);

    return 1;
}












/*
 * Seven-argument entry to the comms send path.  The seventh argument is a
 * flag whose INVERSE becomes the `broadcast` byte handed to func_020368C0:
 * `flag == 0` gives 1, anything else gives 0, materialised as
 * `mov r5,#1` / `cmp r4,#0` / `movne r5,#0` before the first call.
 *
 * The module handle behind the global at 0x021469D0 is fetched once and every
 * later read comes off the same pooled base; a null handle, a busy queue
 * (func_02039414 non-zero or func_0203C990 zero) and a failed func_02039594
 * all return 0 early.  func_0203D798's result is only used for its +0x64
 * byte, which selects the +0xf4 table over the +0xcc one when the fifth
 * argument is the 0xff wildcard.
 *
 * The broadcast flag is additionally cleared when the third argument is not
 * less than the handle's +0x1e0 word: `cmp r7,r0` / `cmpge r5,#1` /
 * `moveq r5,#0` is the conjunction `if (a3 >= lim && flag != 0) flag = 0;`
 * written as one expression
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * On a failed send the error path reports through func_0203CA98's three-word
 * record with line 0x3f4 and returns 0; a successful send returns 1.
 *
 * Addresses are Black-image addresses.
 *
 * BYTE-CORRECT, PARKED: 280 bytes, 0 concrete mismatches.  Capped at MATCH by
 * the sole unresolved site, the PC24 at +0x00D0 naming func_020368C0
 * (0x020368C0).  That address has no branch anywhere in the image outside this
 * function's own `bl` and no manifest entry, so neither `label` nor `matched`
 * can attest it; the call is the last thing before the function's two tail
 * exits, so no cut frees it either.  Filing 0x020368C0 promotes this file
 * unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02038C18.c \
 *       --func func_02038C18 --addr 0x02038C18 --cc 1.1p1 --arm
 */
int func_02038C18(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7)
{
    struct Rec_020377B8 *rec;
    struct Net *h;
    struct Err *err;
    void *tbl;
    u32 flag;

    flag = 1;
    if (a7 != 0)
        flag = 0;

    rec = func_0203D798();
    if (g_021469D0 == 0)
        return 0;
    if (func_02039414() != 0 || func_0203C990() != 0)
        return 0;
    if (func_02039594() == 0)
        return 0;

    h = g_021469D0;
    if ((int)a3 >= (int)h->f1E0 && flag == 1)
        flag = 0;

    if (rec->f64 != 0 && a5 == 0xff)
        tbl = h->fF4;
    else
        tbl = h->fCC;

    if (func_020368C0(tbl, a1, a2, a3, a4, flag, a6) != 0)
        return 1;

    func_02039548();
    err = (struct Err *)func_0203CA98();
    if (err->f0c == 0)
        func_0203C9AC(err->f00, err->f04, err->f08, 0x3f4);
    return 0;
}











void func_02038D30(int a0, int a1, int a2, int a3)
{
    func_020365E8((char *)&g_021469D0->f1C);
}











void func_02038D4C(int a0, int a1, int a2, int a3)
{
    func_020365E8((char *)&g_021469D0->f3C);
}












/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02038D68.c \
 *       --func func_02038D68 --addr 0x02038D68 --cc 1.1p1 --arm
 */
void func_02038D68(int a0, u32 a1, u32 a2, u8 *a3)
{
    u32 v;

    func_0203D798();
    v = (u32)func_0203996C(func_02039338());
    func_0203A770(a3[0x0E], a3[0x0F], a0, a1, a2, v);

    if (func_02039338() == 0) {
        v = (u32)func_0203996C(0xFF);
        if (a0 < 0x11)
            func_0203A770(a3[0x0E], a3[0x0F], a0, a1, a2, v);
    }

    func_02037234(a3);
}












/*
 * net_system.c packet reassembly: drain a slot's receive ring (src, the
 * 0x10-byte slot header func_0203640C builds; +0x0C is its read cursor)
 * into the reassembly record st, one chunk per turn, asserting at line
 * 0x6E3 on a zero header.  Written fresh from the image: the old note
 * (docs/notes/pkt_02038DF0.c.txt) kept no recoverable source.
 *
 * What closed it:
 *   - func_020364D4 is written in BOTH arms of the func_0203A804 test,
 *       if (!func_0203A804(h)) len = f(src, buf, left, left);
 *       else                   len = f(src, buf, left, n - 7);
 *     The compiler hoists the shared argument setup above the branch and
 *     sinks the call below it, which is the image's `mov r3, r2 / b /
 *     ldr r3, [sp, #4]` diamond.  A ternary argument (any spelling) is
 *     if-converted to moveq/ldrne and is 8 bytes short.
 *   - n is u32 (with it s32 the stack parameter is loaded after the guard
 *     instead of in the prologue); `int lim = n - 7` assigned inside the
 *     loop is an equivalent EXACT spelling.
 *   - h is u32 and declared after len/sv/p (permuter decl-order);
 *     func_02036540's result is narrowed through a u16 local at the 0xFFFF
 *     re-seed (the lsl/lsr pair), so it is declared returning u32 here.
 */
void func_02038DF0(struct Src *src, s32 a1, u8 *buf, struct St *st, u32 n)
{
    int len;
    s16 sv;
    u8 *p;
    u32 h;
    int cnt;

    func_0203D798();
    while (func_020365E8((char *)src) != 0) {
        h = st->h;
        if (h == 0) {
            h = func_02036540((u32)src);
            if (h == 0) {
                func_02034714((const char *)str_020A7A24, 0x6E3, (const char *)str_020A7A50);
                continue;
            }
        }
        sv = src->pos;
        st->h = h;
        if (st->total == 0xFFFF) {
            if (func_020365E8((char *)src) < 3) {
                src->pos = sv;
                return;
            }
            {
                u16 v = func_02036540((u32)src);
                st->left = v;
                st->total = v;
            }
            st->f0E = a1;
            st->f0F = func_02036500((u32)src);
        }
        sv = src->pos;
        if (func_0203A804(h) && func_0203A634(st->f0F)) {
            if (st->dst == 0)
                st->dst = (u8 *)func_0203A81C(h, st->f0E, st->total);
            p = st->dst + st->done;
        } else {
            p = buf;
            st->dst = buf;
        }
        if (!func_0203A634(st->f0F))
            p = 0;
        if (!func_0203A804(h))
            len = func_020364D4(src, buf, st->left, st->left);
        else
            len = func_020364D4(src, buf, st->left, n - 7);
        st->left = st->left - (u16)len;
        cnt = len;
        if (st->total > st->done) {
            cnt = st->total - st->done;
            if (cnt > len)
                cnt = len;
            if (p != 0)
                func_02082D44(buf, p, cnt);
        }
        st->done += cnt;
        if (st->left == 0) {
            func_02038D68(h, st->total, (u32)st->dst, (u8 *)st);
            continue;
        }
        if (!func_0203A7EC(h))
            return;
        if (func_0203A804(h))
            return;
        if (!func_0203A634(st->f0F))
            return;
        st->left += (u16)len;
        src->pos = sv;
        return;
    }
}










void func_02039050(void)
{
    int i;
    struct Net *p;

    if (g_021469D0 == 0)
        return;

    func_0203666C((u32)&g_021469D0->f2C);

    for (i = 0; i < 4; i++) {
        if ((int)func_020365E8((char *)&g_021469D0->f2C) <= 0)
            return;

        p = g_021469D0;
        func_02038DF0((struct Src *)&p->f2C, 0xFF, p->f18,
                      (struct St *)p->f19C, func_02037258());
    }
}











/*
 * n slots of 0x10 bytes at g+0x4c, each prepared by func_0203666C and then
 * offered to func_02038DF0 up to four times, with the record at g+0x11c and
 * the frame returned by func_0203D6BC handed to each call.
 *
 * Three spellings are load-bearing.  The global is re-read through
 * g_021469D0 itself in every statement (mwcc keeps its address in `sb` and
 * reloads the value, because the calls may store through it).  There is no
 * explicit `if (n <= 0) return;`: with `n = func_0203D680();` followed
 * straight by `for (i = 0; i < n; i++)` the loop's pre-test folds to
 * `cmp r7, #0` / `pople` because i is known zero, and the loop-exit
 * epilogue tail-merges with the function's own.  And the inner body is
 * `if (test > 0) call(...)` rather than `if (test <= 0) break;`, because
 * the original's branch lands on the inner increment (the continue path).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020390BC.c \
 *       --func func_020390BC --addr 0x020390BC --cc 1.1p1 --arm
 */
void func_020390BC(void)
{
    s32_020390BC i, j, n;
    u8 *s;

    s = (u8 *)func_0203D6BC();
    if (g_021469D0 == 0)
        return;

    n = func_0203D680();

    for (i = 0; i < n; i++) {
        func_0203666C((u32)&g_021469D0->f4C[i]);
        for (j = 0; j < 4; j++) {
            if (func_020365E8((char *)&g_021469D0->f4C[i]) > 0)
                func_02038DF0((struct Src *)&g_021469D0->f4C[i], i,
                              g_021469D0->f18,
                              (struct St *)g_021469D0->f11C[i], (u32)s);
        }
    }
}











int func_02039160(u32 mode)
{
    u8 *p5;
    u8 *p4;
    struct Net *g;
    u32 v;
    u16 m;

    p5 = (u8 *)func_0203D788();
    p4 = (u8 *)func_0203D798();
    g = g_021469D0;
    if (g == 0)
        return 0;
    v = (u8)(p4[0x65] + 0xff);
    if (v <= 1) {
        if (g->f1E7 != 0) {
            if (((int (*)(void))(*(u32 *)(*(u32 *)(p5 + 0x340) + 0x80)))() != -1) {
                if (mode == 0)
                    return 1;
                if (mode == 1)
                    return 1;
            }
        }
        return 0;
    }
    v = (u8)(p4[0x65] + 0xfd);
    if (v <= 1) {
        if (mode < 2 || mode == 0xff) {
            if (((int (*)(void))(*(u32 *)(*(u32 *)(p5 + 0x340) + 0x70)))() != 0)
                return 1;
        }
        return 0;
    }
    if (func_020392EC() == 0)
        return 0;
    if (((int (*)(void))(*(u32 *)(*(u32 *)(p5 + 0x340) + 0x70)))() == 0)
        return 0;
    if (mode == (u32)func_02039338())
        return 1;
    if (func_02039338() == 0 || p4[0x64] == 0) {
        m = (u16)((int (*)(void))(*(u32 *)(*(u32 *)(p5 + 0x340) + 0x7c)))();
        if (((1 << mode) & m) != 0)
            return 1;
    } else {
        if (((1 << mode) & g_021469D0->f1E4) != 0)
            return 1;
    }
    return 0;
}











/*
 * Counts the eight slots whose test function answers non-zero.  The slot
 * number goes in as a `u16` - the `lsl #16` / `lsr #16` pair in the loop is
 * that narrowing - so the callee is declared with a `u16` parameter and the
 * cast costs nothing at the call site.  The counter is in r4 and the index in
 * r5, which is the declaration order below.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020392B8.c \
 *       --func func_020392B8 --addr 0x020392B8 --cc 1.1p1 --arm
 */
u32 func_020392B8(void)
{
    u32 count;
    s32_020392B8 i;

    count = 0;
    for (i = 0; i < 8; i++) {
        if (func_02039160((u16)i) != 0)
            count++;
    }
    return count;
}











/*
 * Returns 1 while the state byte at +0x65 is one to four, but only while the
 * global at 0x021469D0 is live; otherwise it dispatches through the vtable at
 * +0x340 of the net state and returns that hook's value (+0x6C slot).
 *
 * The `add r0, r0, #0xff` / `and r0, r0, #0xff` pair is `(u8)(v - 1)`: mwcc
 * writes the -1 as +0xFF because the truncation to u8 makes the two
 * equivalent and 0xFF keeps the `and` mask a plain immediate.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020392EC.c \
 *       --func func_020392EC --addr 0x020392EC --cc 1.1p1 --arm
 */
int func_020392EC(void)
{
    u8 *s = (void *)func_0203D788();
    u8 *p = (void *)func_0203D798();

    if (g_021469D0 != 0 && (u8)(p[0x65] + 0xFF) <= 3)
        return 1;

    return (*(int (**)(void))(*(u32 *)(s + 0x340) + 0x6C))();
}








u16 sub_02039338(void)
{
    struct Owner_020377B8 *owner;
    u8 sel;
    s32 v;

    if (g_021469D0 == 0) {
        goto none;
    }

    owner = func_0203D788();
    sel = ((struct Mode *)func_0203D798())->unk65 + 0xff;

    if (sel <= 1) {
        v = owner->unk340->unk80();
        if (v == -1) {
            goto none;
        }
        return (u16)v;
    }

    return (u16)owner->unk340->unk80();

none:
    return 0;
}







int sub_020393A8(void)
{
    u16 mask;

    mask = ((struct LinkRoot_020377B8 *)func_0203D788())->driver->get_mask();
    return mask & 0xFFFE;
}







/*
 * Is the link busy?  The +0x1e9 flag on the link state forces a yes, and
 * otherwise the driver's own predicate at +0x88 decides.
 *
 * The two halves of the flag test share one `ne` chain and a single `popne`,
 * so they are one `&&` rather than nested `if`s.  func_0203D788 is called
 * before the flag is even read because its result is needed on the fall
 * through path, and the compiler will not sink a call past a branch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020393D0.c \n *       --func sub_020393D0 --addr 0x020393D0 --cc 1.1p1 --arm
 */
int sub_020393D0(void)
{
    struct LinkRoot_020393D0 *root;

    root = func_0203D788();

    if (g_021469D0 != 0 && g_021469D0->f1E9 != 0) {
        return 1;
    }
    return root->driver->busy() != 0;
}








/*
 * Asks the transport's +0x88 virtual whether the link is up, falling back to
 * the +0x1E9 flag of the object at 0x021469D0 when the virtual is missing or
 * answers zero.  Both re-tests are conditional-execution chains (`cmpne`), so
 * the source is the `!= 0 && ...` spelling in each place.  The result local
 * is declared after the context refresh and assigned at its first use: with
 * `u32 r = 0;` ahead of the refresh the value is live across func_0203D788
 * and the allocator spends a callee-saved register on it (`push {r4, lr}`
 * instead of the original's `push {r3, lr}`).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039414.c  *       --func func_02039414 --addr 0x02039414 --cc 1.1p1 --arm
 */
u32 func_02039414(void)
{
    u8 *p = func_0203D788();
    u32 r = 0;

    if (p != 0 && ((struct Obj15941 *)p)->f340 != 0)
        r = ((u32 (*)(void))*(u32 *)(*(u32 *)(p + 0x340) + 0x88))();
    if (r == 0) {
        struct Net *q = g_021469D0;

        if (q != 0 && q->f1E9 != 0)
            r = 1;
    }
    return r;
}








void func_02039468(u32 a, u32 b)
{
    u8 *s = (u8 *)func_0203D798();

    if (s[0x64] != 0 && b == 0xff) {
        func_02036B98((char *)g_021469D0->fF4, a);
    } else {
        func_02036B98((char *)g_021469D0->fCC, a);
    }
}








/*
 * Leaf that saves no lr: tail-calls func_020366A8 on the 0xCC queue of the
 * net_system record (docs/families/net_system.h, fCC).  Reached only through
 * the long-branch veneer at 0x0203D56C.
 */
int func_020394C0(void)
{
    return func_020366A8((struct Conn *)g_021469D0->fCC);
}







/*
 * A leaf setter on the link state: store the argument byte at +0x1e7.  It
 * saves no registers, so disasm.py gives it no label and it prints as a run
 * of `.word`s between two pools
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020394DC.c \n *       --func sub_020394DC --addr 0x020394DC --cc 1.1p1 --arm
 */
void sub_020394DC(u8 v)
{
    g_021469D0->f1E7 = v;
}







void func_020394F0(u32 a)
{
    u8 v = ((T_0203D798 *)func_0203D798())->f065;

    if ((u8)(v + 0xff) > 1) {
        return;
    }
    g_021469D0->f1AC = a;
    if (a == 0) {
        return;
    }
    g_021469D0->f1B0 = 0;
    g_021469D0->f1B4[0] = 0;
    g_021469D0->f1B4[1] = 0;
}







/*
 * Set the +0x1e9 flag on the link state.  sub_02039560 is the clearing half;
 * the two are byte-for-byte the same but for the stored constant.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02039548.c \n *       --func sub_02039548 --addr 0x02039548 --cc 1.1p1 --arm
 */
void sub_02039548(void)
{
    g_021469D0->f1E9 = 1;
}






/*
 * Clear the +0x1e9 flag sub_02039548 sets.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02039560.c \n *       --func sub_02039560 --addr 0x02039560 --cc 1.1p1 --arm
 */
void sub_02039560(void)
{
    g_021469D0->f1E9 = 0;
}






/*
 * Set the +0x1ea flag, but only when the link state has been constructed.
 * The guard and the store share one `ne` predication rather than a branch,
 * and the stored 1 is materialised into r0, the register the pool address
 * was loaded into, because that register is dead by then.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02039578.c \n *       --func sub_02039578 --addr 0x02039578 --cc 1.1p1 --arm
 */
void sub_02039578(void)
{
    if (g_021469D0 != 0) {
        g_021469D0->f1EA = 1;
    }
}






/*
 * May the caller proceed?  With no link state, or with the +0x64 byte of the
 * session record set, the answer is an unconditional yes; in the two session
 * states 0 and 5 it is whatever the +0x1eb byte of the link state says; any
 * other state is a yes.
 *
 * The `state == 0 || state == 5` pair is one `cmp` / `cmpne` chain feeding a
 * single `eq` block, so it has to be written as one disjunction: as two
 * `if`s the shared block is duplicated.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02039594.c \n *       --func sub_02039594 --addr 0x02039594 --cc 1.1p1 --arm
 */
int sub_02039594(void)
{
    struct Session *s;

    if (g_021469D0 == 0) {
        goto yes;
    }

    s = func_0203D798();
    if (s->unk_64 != 0) {
        goto yes;
    }
    if (s->state == 0 || s->state == 5) {
        return g_021469D0->f1EB;
    }
yes:
    return 1;
}






/*
 * Clamp a slot index to the sentinel: anything from 8 up becomes 0xff, and
 * everything below passes through untouched.  Twelve bytes, no prologue.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020395E0.c \n *       --func sub_020395E0 --addr 0x020395E0 --cc 1.1p1 --arm
 */
int sub_020395E0(int slot)
{
    if (slot >= 8) {
        slot = 0xFF;
    }
    return slot;
}







/*
 *           0x020A7A68 ends at 0x020A7A75; the 3-byte gap kills the `string`
 *           class, so 0x020A7A78 has no witness outside 020395EC..02039658.
 *           Every concrete byte of the body reproduces.
 */
int func_020395EC(struct Entry *a)
{
    struct Entry *v;
    int i;

    func_0203D788();
    v = func_0203996C(0xff);
    if (v == a) {
        return 0xff;
    }
    for (i = 0; i < 9; i++) {
        v = func_0203996C(i);
        if (v == a) {
            return i;
        }
    }
    func_02034714((const char *)str_020A7A68, 0x6e, (const char *)str_020A7A78);
    return -1;
}






/*
 * Reset one slot entry while KEEPING its eight resource pointers.  The eight
 * pointers at +8 are stashed on the stack, each live one's 0x10-byte record
 * is zeroed in place, the entry's own object at +0 is released, the whole
 * 0x50-byte entry is wiped, and the eight pointers are written straight back
 * -- so the resource objects survive the reset and only the entry's state
 * does not.  A real slot index (anything but the 0xFF own-slot spelling)
 * first has its bit cleared out of the +0x40 mask through func_0203A28C and
 * its +0x3E companion zeroed.  func_02039834 and func_020398B4 both drive
 * this in a loop over the nine slots.
 *
 * THE STACK BUFFER HOLDS NINE POINTERS, NOT EIGHT, AND ONLY EIGHT ARE USED.
 * Declared `void *saved[8]` the function is byte-identical but for its frame:
 * `sub sp, sp, #0x20` with r3 in the push, against the image's
 * `sub sp, sp, #0x24` with a seven-register push.  The ninth word is what
 * takes the frame to 0x24 and lets the prologue drop the r3 home slot; the
 * unused slot is not padding the compiler inserted but a declared one.  Nine
 * is also the family's own table size (sub_0203996C resolves nine 0x50-byte
 * entries, eight peers plus the own slot), so the buffer was almost
 * certainly spelled with the same manifest constant as the table and the
 * loop simply stops at the eight peers.  tools/permuter.py exhausted hill
 * mode (206 single mutations, none better) on the eight-element version:
 * the array's own size is outside its mutation set.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039658.c \
 *       --func func_02039658 --addr 0x02039658 --cc 1.1p1 --arm
 */
void func_02039658(struct Entry *e, u32 idx)
{
    void *saved[9];
    int i;

    if (idx != 0xff) {
        u16 h = e->key40;
        e->key3e = 0;
        e->key40 = func_0203A28C(h, idx, 0);
    }

    for (i = 0; i < 8; i++) {
        if (e->slot[i] != 0)
            func_02082BCC(e->slot[i], 0, 0x10);
        saved[i] = e->slot[i];
    }

    if (e->obj != 0) {
        func_020307B0(e->obj);
        e->obj = 0;
    }

    func_02082BCC(e, 0, 0x50);

    for (i = 0; i < 8; i++)
        e->slot[i] = saved[i];

    func_02037BE8(idx);
}






/*
 * Clears the slot's `0x3e` field, refreshes its `0x40` field from the
 * selector, then clears the 0x10-byte record its indexed pointer names.
 * The early `popeq` is the null test written as an early return.
 */
void func_0203971C(unsigned char *a, u32 b)
{
    if (b != 0xFF) {
        u16 h = ((struct Obj08833 *)a)->f40;
        ((struct Obj08833 *)a)->f3E = 0;
        ((struct Obj08833 *)a)->f40 = (u16)func_0203A28C(h, b, 0);
    }
    {
        void *p = *(void **)(a + b * 4 + 8);
        if (p == 0)
            return;
        func_02082BCC(p, 0, 0x10);
    }
}






/*
 * (Re)initialise one slot entry and hand it back.  The entry is wiped to
 * 0x50 zero bytes, its packed key at +0x44/+0x46 is set to the 0xFF
 * sentinel and its +0x49/+0x4A state bytes cleared.  Only the OWN slot
 * (index 0xFF) owns the eight 0x10-byte resource records at +8: for it the
 * old eight are released before the wipe and eight fresh ones allocated
 * after it out of the heap named by the record's +0x56 halfword (line 0xC7);
 * a peer slot keeps a null array on both sides of the wipe.
 *
 * This is func_02039834's per-slot worker and the constructive twin of
 * func_02039658 (which keeps the resource pointers rather than
 * reallocating them).
 *
 * TWO LEVERS, and only one of them is an allocation tie.
 *
 * IT RETURNS THE ENTRY.  The image's `mov r0, r8` at +0xBC, between the
 * +0x46 store and the +0x49 store, is the return value: both callers
 * (func_02039834, func_020398B4) discard it, so nothing downstream forces
 * it, but written `void` the function is four bytes short and that `mov` is
 * simply missing.  A dead-looking `mov r0, <callee-saved>` just before the
 * epilogue of a function whose callers ignore the result is the tell.
 *
 * DECLARATION ORDER: `struct Entry *e;` before `u8 *g;`.  The other way
 * round the two swap colours -- the record goes to r8 and the entry to sb,
 * against the image's sb and r8 -- for ten `mov`/`ldr` operands and no size
 * change (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 * tools/permuter.py --explain reports this residue as exactly one swapped
 * pair (r8 <-> sb), which is what says to reach for declaration order rather
 * than for the body.
 *
 * The allocation loop's counter is a SECOND variable from the release
 * loop's, zeroed before the wipe call rather than at the loop head: that is
 * the `mov sl, #0` at +0x50 sitting above `bl func_02082BCC`, where reusing
 * `i` would re-zero it after the call.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039764.c \
 *       --func func_02039764 --addr 0x02039764 --cc 1.1p1 --arm
 */
struct Entry *func_02039764(u32 idx)
{
    struct Entry *e;
    u8 *g;
    int i;

    g = func_0203D798();
    func_0203D788();
    e = (struct Entry *)func_0203996C(idx);

    if (idx == 0xff) {
        for (i = 0; i < 8; i++) {
            if (e->slot[i] != 0)
                func_020307B0(e->slot[i]);
        }
    }

    i = 0;
    func_02082BCC(e, 0, 0x50);

    if (idx == 0xff) {
        for (; i < 8; i++)
            e->slot[i] = func_02030734(((struct Obj15944 *)g)->f56, 0x10, 1, file_020A7A68, 0xc7);
    }

    e->f4a = 0;
    e->key44 = 0xff;
    e->key46 = 0xff;
    e->f49 = 0;
    return e;
}






/*
 * Module bring-up, the twin of func_020398B4's teardown: reset all eight
 * peer slots through func_02039764, reset the own slot (0xFF) too, assert
 * that the module handle g_021469D4 is NOT already live, then allocate the
 * 0x20-byte handle for it out of the heap named by the record's +0x56
 * halfword (line 0xE5; the assert is line 0xE3).
 *
 * TWO LEVERS, both of which the note in docs/notes/pkt_02039764.c.txt was
 * one step short of.
 *
 * DECLARATION ORDER: `int i;` before `u8 *p;`.  With `p` declared first the
 * allocator colours the object pointer r4 and the reset index r5, which is
 * the swap of the image's r5/r4 the note recorded; swapping the two
 * declarations swaps the colours back
 * (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 * The note tried this "and it does not move it" only because the remaining
 * residue below masked the result.
 *
 * ASSERT POLARITY: the guard is `g_021469D4 != 0`, not `== 0`.  The image
 * skips the report with `beq`, so the report runs on the NON-null handle:
 * bringing a module up twice is the error, where func_020398B4's matching
 * assert at line 0x100 fires on the null handle because tearing down a dead
 * module is the error there.  Getting it backwards is a one-byte diff
 * (the condition field of a single branch) and nothing else.
 *
 * The note's second finding is now stale: func_02039764's only branch sites
 * image-wide are this function's own two calls, so `label` still refuses it,
 * but `sole-ref/code` carries it (0x02039764 is a traced function start), and
 * msg_020A7A7C resolves through `sole-ref` the same way.  This file is EXACT,
 * not the MATCH the note predicted.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039834.c \
 *       --func func_02039834 --addr 0x02039834 --cc 1.1p1 --arm
 */
void func_02039834(void)
{
    int i;
    u8 *p;

    p = func_0203D798();
    for (i = 0; i < 8; i++) {
        func_02039764(i);
    }
    func_02039764(0xff);

    if (g_021469D4 != 0) {
        func_02034714(file_020A7A68, 0xe3, msg_020A7A7C);
    }
    g_021469D4 = func_02030734(((struct Obj15945 *)p)->f56, 0x20, 1, file_020A7A68, 0xe5);
}





/*
 * The teardown twin of func_02039834: clear every one of the eight peer slots
 * (func_02039658 on each slot's entry), release the eight resource handles the
 * own-slot entry parks at +8..+0x24, clear the own slot too, then assert the
 * module handle g_021469D4 is live and free it.
 *
 * The own-slot entry is taken once, before the release loop, and the address
 * of each handle word is recomputed per iteration rather than kept in a
 * cursor: func_020307B0 is an ordinary extern, so the store after it needs a
 * fresh `add r0, r5, r6, lsl #2`
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 * The two `mov` of the slot key 0xff share one register with the clear loop's
 * counter, which is why the tail spells the key as `mov r4, #0xff`.
 *
 * The __FILE__ argument is "net_handle.c" at 0x020A7A68, line 0x100.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020398B4.c \
 *       --func func_020398B4 --addr 0x020398B4 --cc 1.1p1 --arm
 */
void func_020398B4(void)
{
    struct Entry *own;
    int i;
    u32 key;

    for (i = 0; i < 8; i++) {
        func_02039658((struct Entry *)(sub_0203996C(i)), i);
    }

    own = sub_0203996C(0xff);

    for (i = 0; i < 8; i++) {
        if (own->slot[i] != 0) {
            func_020307B0(own->slot[i]);
            own->slot[i] = 0;
        }
    }

    key = 0xff;
    func_02039658((struct Entry *)(sub_0203996C(key)), key);

    if (g_021469D4 == 0) {
        func_02034714(file_020A7A68, 0x100, msg_020A7A88);
    }
    func_020307B0(g_021469D4);
    g_021469D4 = 0;
}







/*
 * Resolves a slot index to one of the nine 0x50-byte entries at +0x70 of
 * func_0203D788()'s record.  0xff is the "own slot" spelling and names entry
 * 8, which is why it is a separate constant add and not a folded index; every
 * other index is bounds-checked against nine and scaled with an `mla`,
 * 0x50 being too awkward for a shift pair.
 *
 * The record's own +0x340 field (see src/matched/sub_02039338.c) is exactly
 * where this table ends: 0x70 + 9 * 0x50.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203996C.c \
 *       --func sub_0203996C --addr 0x0203996C --cc 1.1p1 --arm
 */
struct Entry *sub_0203996C(s32 idx)
{
    struct Owner_0203996C *owner = func_0203D788();

    if (owner != 0) {
        if (idx == 0xff) {
            return &owner->table[8];
        }
        if (idx < 9) {
            return &owner->table[idx];
        }
    }
    return 0;
}







/*
 * A two-call forwarder: the index func_02039338 returns goes straight to
 * func_0203996C through r0, and that entry is returned.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020399A8.c  *       --func sub_020399A8 --addr 0x020399A8 --cc 1.1p1 --arm
 */
struct Entry *sub_020399A8(void)
{
    return func_0203996C(func_02039338());
}







/*
 * A null-tolerant predicate on a slot's +0x4A state.  This is the if/else
 * spelling rather than if-return-then-return: the null arm branches to an
 * epilogue of its own at the end, and the tested arm is the fall-through, so
 * the source condition is the `!= 0` one.  The `? ==5 : 0` shape is the
 * `moveq r0, #1` / `movne r0, #0` pair.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020399B8.c \
 *       --func func_020399B8 --addr 0x020399B8 --cc 1.1p1 --arm
 */
u32 func_020399B8(u8 *p)
{
    if (p != 0)
        return p[0x4A] == 5;
    else
        return 0;
}






/*
 * Entry accessor: returns byte 0x4A of a 0x50-byte entry, or 8 for null.
 */
int func_020399DC(struct Entry *p)
{
    if (p) return p->f4a;
    return 8;
}






/*
 * Count how many of the eight slots answer non-zero to the probe: when
 * func_0203D788() is null the count is zero, otherwise every slot is asked
 * through func_0203996C(i) and func_020399B8(), and each non-zero answer bumps
 * the counter (the `addne r5, r5, #1` after the loop's `add r4, r4, #1`).
 *
 * The counter is left uninitialised at its declaration and assigned `0` in
 * BOTH arms of the guard.  That is what puts `mov r5, #0` between the guard's
 * `cmp` and its `beq`, and what keeps the exit a single shared epilogue
 * instead of the predicated `moveq r0, r5; popeq` pair.  Declaring
 * `int c = 0;` up front instead hoists the zero above the call (4 bytes of
 * different scheduling), and `if (f() == 0) return c;` predicates the whole
 * early exit and grows the body to 68 bytes.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020399EC.c \
 *       --func func_020399EC --addr 0x020399EC --cc 1.1p1 --arm
 */
int func_020399EC(void)
{
    int i;
    int c;

    if (func_0203D788() != 0) {
        c = 0;
        for (i = 0; i < 8; i++) {
            if (func_020399B8((u8 *)func_0203996C(i)) != 0)
                c++;
        }
    } else {
        c = 0;
    }
    return c;
}





void func_02039A2C(int a)
{
    char *q;
    if (func_02039338())
        return;
    q = (char *)func_0203996C(0xff) + a * 2;
    q[0x2c] = (char)a;
    q[0x2d] = 1;
}






/*
 * Retire every armed two-byte slot of the own-slot entry: early-out when
 * func_02039338() reports busy, otherwise take the 0xFF entry and, for each
 * of the eight slot pairs at +0x2C, clear the +0x2D flag byte once
 * func_0203D3A8(entry, 5, 2, &pair) accepts it.
 *
 * THE LAST STORE'S OFFSET IS A NAMED LOCAL, THE OTHER TWO ARE NOT.  Written
 * with `i * 2` spelled at all three uses, the whole function comes out
 * shifted one register up (r5/r6 for entry/index against the image's r4/r5,
 * with an extra callee-saved in the push) and 4 bytes short.  Binding
 * `off = i * 2` at the top of the loop body and using it ONLY at the final
 * `strb` gives that store its own value number: the predicated arm then has
 * to re-materialise the field address as `addne r0, r4, r5, lsl #1` followed
 * by `strbne r6, [r0, #0x2d]`, which is exactly the image's shape, where a
 * shared offset lets the compiler fold 0x2D into a second base register and
 * index off it.  Substituting `off` at the other two uses as well loses it
 * again, and so does declaring `off` inside the loop body rather than beside
 * `p` and `i` (declaration order is stack and colouring order,
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *
 * Found by tools/permuter.py (mode hill, 148 compiles, mutation
 * `temp(tmp=i * 2)`); the note in docs/notes/pkt_02039A5C.c.txt had ruled out
 * the three hand spellings that keep every offset an expression.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039A5C.c \
 *       --func func_02039A5C --addr 0x02039A5C --cc 1.1p1 --arm
 */
void func_02039A5C(void)
{
    u8 *p;
    int i;
    int off;

    if (func_02039338() != 0) {
        return;
    }
    p = (u8 *)func_0203996C(0xff);
    for (i = 0; i < 8; i++) {
        off = i * 2;
        if (*(u8 *)(p + 0x2d + i * 2) != 0) {
            if (func_0203D3A8((struct Entry *)p, 5, 2, (u32)(p + 0x2c + i * 2)) != 0) {
                *(u8 *)(p + 0x2d + off) = 0;
            }
        }
    }
}






/*
 * Seeds the current record's +0x4a state byte: state 2 re-arms the eight-slot
 * table through func_0203D3A8 with a 3-byte payload built in a 12-byte stack
 * buffer, any state below 2 is stepped up by one, anything else is left alone.
 * The early `beq` on func_02039160() is the R4 shared-tail lever: the first
 * exit branches to the function's last `return 0` instead of predicating
 * `moveq r0, #0` / `popeq` (which cost 12 bytes).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039ACC.c \
 *       --func func_02039ACC --addr 0x02039ACC --cc 1.1p1 --arm
 */
int func_02039ACC(void)
{
    u8 buf[12];
    u8 *p;
    u8 v;
    u8 *q;
    u32 f;

    p = (u8 *)func_020399A8();
    v = (u8)func_020395EC((struct Entry *)p);
    func_0203D788();
    q = func_0203D798();
    if (func_02039160(func_02039338()) != 0) {
        f = ((struct Obj11357 *)p)->f4A;
        if (f == 2) {
            func_02087C6C(buf);
            buf[6] = v;
            buf[7] = ((struct Obj11358 *)q)->f67;
            buf[8] = ((struct Obj11358 *)q)->f6E;
            return func_0203D3A8((struct Entry *)p, 3, 9, (u32)buf);
        }
        if (f < 2)
            ((struct Obj11357 *)p)->f4A = f + 1;
    }
    return 0;
}






/*
 * Record one peer's vote and raise the "everyone agreed" flag when the last
 * one lands.  The 3-byte message at `msg` is a u16 tag plus a u8 mask; the
 * sender's slot is `slot`, and the vote is only taken when func_020395EC says
 * the link is still the own link (0xff) and the slot is a real one.
 *
 * Both halves of the vote table hang off the one module global g_021469D4:
 * the u16 tags are the array at +0, the masks the bytes at +0x10 and the
 * ready flags the bytes at +0x18.  The global is re-read after each store and
 * inside the scan because every callee here is an ordinary extern.
 *
 * The scan then walks all eight slots: an ACTIVE slot must have voted the same
 * mask and the same tag, and must NOT carry that slot's own bit in its mask,
 * or the function returns without raising the flag; an INACTIVE slot is only allowed
 * through when func_02039160 says it is not merely late.  `1 << i` is kept
 * live in sb across the whole loop, which is what puts `mov sb, #1` above the
 * loop head rather than a rematerialised constant in the arm
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * EXACT* only: the inferred extent runs 20 bytes long because the unlabelled
 * leaf at 0x02039C2C (`ldrh r1,[r2] / ldr r0,[sp] / strh r1,[r0,#0x44] / bx lr`,
 * 16 bytes, saves no lr so disasm.py never labels it) follows this function's
 * own pool word at 0x02039C28.  Never a byte difference; 0x02039C2C wants
 * seeding into layout/function_starts.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039B5C.c \
 *       --func func_02039B5C --addr 0x02039B5C --cc 1.1p1 --arm
 */
void func_02039B5C(u32 slot, u32 a1, struct Msg_02039B5C *msg, u32 a3, u32 link)
{
    u16 tag = msg->tag;
    u8  mask = msg->mask;
    int i;
    u32 one;

    if (func_020395EC((void *)link) != 0xff) {
        return;
    }
    if (slot == 0xff) {
        return;
    }

    g_021469D4->tag[slot] = tag;
    g_021469D4->mask[slot] = mask;

    i = 0;
    one = 1;

    for (; i < 8; i++) {
        if (func_020399B8((u8 *)sub_0203996C(i)) != 0) {
            if (mask == g_021469D4->mask[i]) {
                if (tag != g_021469D4->tag[i]) {
                    return;
                }
            } else if ((mask & (one << i)) != 0) {
                return;
            }
        } else if (func_02039160((u16)i) == 1) {
            return;
        }
    }

    g_021469D4->ready[slot] = 1;
}






/*
 * A message handler from the dispatch table at 0x020A0870, sharing the
 * five-argument shape of its table neighbour func_02039B5C: the first four
 * arguments arrive in r0-r3 and the fifth, the receiver object, on the
 * stack.  This one copies the message's 16-bit tag into the receiver's
 * 0x44 field and ignores everything else.
 */
void func_02039C2C(u32 a0, u32 a1, struct Msg_02039C2C *msg, u32 a3, struct Obj_0203996C *obj)
{
    obj->tag = msg->tag;
}






/*
 * Arm one pending vote on the record at `p`: park the tag at +0x46, mark the
 * slot unresolved with 0xff at +0x48, and record at +0x49 whether the record
 * is NOT the own link -- func_020395EC returning 0xff is the own link, which
 * is the one case that stores zero.
 *
 * The record pointer is copied to r4 before the two stores because the call
 * clobbers r0; the boolean is built with the `moveq`/`movne` pair rather than
 * a branch, which is 1.1p1's normal shape for a comparison stored straight to
 * memory.  The pair's ORDER is the source order of the arms: written as
 * `p->remote = (... != 0xff)` or as a ternary, 1.1p1 emits `movne r0,#1`
 * first and is 4 bytes out; the explicit if/else with the `== 0xff` arm first
 * puts `moveq r0,#0` first, as the image has it
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039C3C.c \
 *       --func func_02039C3C --addr 0x02039C3C --cc 1.1p1 --arm
 */
void func_02039C3C(struct Rec_0203996C *p, u16 tag)
{
    p->tag = tag;
    p->slot = 0xff;
    if (func_020395EC((struct Entry *)p) == 0xff) {
        p->remote = 0;
    } else {
        p->remote = 1;
    }
}






/*
 * A whole translation unit, matched as one byte range.
 *
 * The setter and the two matchers for the packed 16-bit key at +0x44/+0x46
 * of the link record: the key is always assembled as `lo + (hi << 8)` from a
 * pair of separate arguments rather than passed whole.
 *
 * sub_02039CA0 has no label in the listing: it is a leaf that saves nothing,
 * so disasm.py prints it inside sub_02039C68's extent (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Keeping the
 * three in one unit is what reproduces its bytes at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02039C68.c \
 *       --addr 0x02039C68 --arm
 */
void sub_02039C68(struct Link *p, u32 lo, u32 hi)
{
    if (p == 0) {
        return;
    }

    p->unk46 = lo + (hi << 8);
    p->unk48 = 0xff;

    if (func_020395EC((struct Entry *)p) == 0xff) {
        p->unk49 = 0;
    } else {
        p->unk49 = 1;
    }
}




u32 sub_02039CA0(struct Link *p, u32 key)
{
    return p->unk44 == key;
}




u32 sub_02039CB4(struct Link *p, u32 lo, u32 hi)
{
    if (p == 0) {
        return 1;
    }
    return p->unk44 == lo + (hi << 8);
}





/*
 * Sweep the eight slot pointers at +0x8.  A slot that is still marked in use
 * (+0xd non-zero) and whose bit is not set in the key word at +0x3e is torn
 * down through the eight-argument delegate; a delegate failure aborts the
 * whole sweep with 0, otherwise the key's bit is set.  Falling off the end
 * clears the key word and reports success.
 *
 * The eight-argument call's first stack slot is the slot pointer itself and
 * the remaining three are the constants 1, 0, 1 (r5 is the object, 0xff/4/
 * 0x10 are the register arguments).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039CD8.c \
 *       --func func_02039CD8 --addr 0x02039CD8 --cc 1.1p1 --arm
 */
int func_02039CD8(struct Obj_02039C68 *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (((struct Obj15949 *)((char *)p->slot[i]))->fD == 0)
            continue;
        if (func_0203A2F0(p->key, i) != 0)
            continue;
        if (func_0203D3F8((u32)p, 0xff, 4, 0x10, (u32)p->slot[i], 1, 0, 1) != 0)
            func_0203A28C(p->key, i, 1);
        else
            return 0;
    }
    p->key = 0;
    return 1;
}





/*
 * The net_handle.c tick (docs/families/net_handle.h).  Closed from the
 * 652-byte / 14-out source of docs/notes/pkt_02039D94.c.txt with two
 * changes:
 *   1. The two owner callbacks at g+0x14 / g+0x10 each TAKE func_0203D650's
 *      result as their argument: `a = g->get_a(func_0203D650())`.  That is
 *      why the image calls through r1 (`ldr r1, [r4, #0x14]; blx r1`):
 *      r0 is holding the argument.  Called with no argument the compile
 *      goes through r0 (4 bytes out).
 *   2. Phases 2 and 4 reuse the entry pointer `e` for the own entry
 *      (func_0203996C(0xff)); there is no separate `own` local.  With a
 *      separate local the own pointer and the loop index swap sb/sl in
 *      phase 2 (or r6/r7 in phase 4).
 */
void func_02039D94(void)
{
    u8 *e;
    u8 *g;
    int i;

    for (i = 0; i < 8; i++) {
        u32 s = func_020395E0(i);
        e = (u8 *)func_0203996C(s);
        if (func_02039160((u16)s) == 0)
            func_020399B8(e);
    }

    func_02039A5C();

    if (func_0203D378() != 0) {
        e = (u8 *)func_0203996C(0xff);
        for (i = 0; i < 9; i++) {
            if (g_021469D4->ready[i] != 1)
                continue;
            if (func_0203D4D0(e, g_021469D4->mask[i], 8, 2,
                              &g_021469D4->tag[i], 0, 0, 0) == 0)
                continue;
            if (g_021469D4->mask[i] == 0)
                func_02034714(file_020A7A68, 0x29a, msg_020A7A94);
            g_021469D4->ready[i] = 0;
        }
    }

    for (i = 0; i < 9; i++) {
        u8 *p;
        p = (u8 *)func_0203996C(func_020395E0(i));
        if (func_0203D394((struct NetEntry *)p) == 0)
            continue;
        if (p[0x49] == 0)
            continue;
        if (func_020395EC((struct Entry *)p) == 0xff)
            continue;
        if (func_0203D3A8((struct Entry *)p, (u16)7, (u16)4, (u32)(p + 0x46)) != 0)
            p[0x49] = 0;
    }

    if (func_02039338() == 0) {
        e = (u8 *)func_0203996C(0xff);
        if (e != 0) {
            for (i = 0; i < 8; i++) {
                u8 *s = *(u8 **)(e + i * 4 + 8);
                if (s == 0 || s[0xd] == 0)
                    continue;
                if (func_0203A2F0(((struct Obj04750 *)e)->f40, i) != 0)
                    continue;
                if (func_02039CD8((struct Obj_02039C68 *)e) != 0)
                    ((struct Obj04750 *)e)->f40 =
                        func_0203A28C(((struct Obj04750 *)e)->f40, i, 1);
            }
        }
    }

    g = func_0203D798();
    if (g[0x65] == 4)
        return;

    e = (u8 *)func_020399A8();
    if (e[0x4e] != 1)
        return;

    if (((struct Obj08835 *)g)->f10 != 0 && ((struct Obj08835 *)g)->f14 != 0) {
        u32 a;
        u32 b;
        a = (*(u32 (**)(u32))(g + 0x14))(func_0203D650());
        b = (*(u32 (**)(u32))(g + 0x10))(func_0203D650());
        if (func_0203D3A8((struct Entry *)e, (u16)0xa, (u16)a, (u32)((void *)b)) != 0)
            e[0x4e] = 0;
    } else {
        e[0x4e] = 0;
    }
}




/*
 * net_handle.c: claim a connection slot for the message a2 (MAC copy,
 * id bytes, OS_GetMacAddress) when this machine owns the table, else mark
 * the table dirty.
 *
 * The 11-byte residue of docs/notes/pkt_02039CD8.c.txt and
 * pkt_02039D94.c.txt (the in-use `strb` scheduled after the MI_CpuCopy8
 * argument setup, the `1` in r3) was the message parameter's pointee
 * qualifier: `const u8 *a2`.  With a2 const-qualified the store to p[0xd]
 * no longer has to be ordered against the reads of a2 that feed the call.
 * A top-level `u8 * const a2` does nothing.  `volatile` on the owner
 * record stays load-bearing (the zero arm's load order).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A020.c  *       --func func_0203A020 --addr 0x0203A020 --arm --cc 1.1p1
 */
void func_0203A020(u32 idx, u32 a1, const u8 *a2, u32 a3, u8 *base)
{
  volatile u8 *r4 = func_0203D798();
  u8 *p;
  u8 *own;
  own = (u8 *) func_0203996C(0xff);
  if (own != base)
    goto mismatch;
  p = *((u8 **) ((base + (idx * 4)) + 8));
  if (p[0xd] != 0)
    return;
  p[0xd] = 1;
  MI_CpuCopy8(a2, p + 6, 6);
  p[0xc] = a2[6];
  func_02087C6C(p);
  if (a2[8] == 0)
    goto zero;
  if ((a2[6] != 0) && (a2[7] != r4[0x67]))
  {
    if ((*((u16 *) (r4 + 0x6e))) == a2[8])
    {
      p[0xf] = *((u16 *) (r4 + 0x6e));
      p[0xe] = *((u16 *) (r4 + 0x6e));
      return;
    }
  }
  if (((a2[6] == 0) && (a2[7] == r4[0x67])) && ((*((u16 *) (r4 + 0x6e))) == a2[8]))
  {
    p[0xf] = *((u16 *) (r4 + 0x6e));
    p[0xe] = *((u16 *) (r4 + 0x6e));
  }
  else
  {
    p[0xf] = 0xff;
    p[0xe] = 0;
  }
  return;
  zero:
  {
    u8 hi = r4[0x67];
    u8 lo = a2[7];
    p[0xf] = hi;
    p[0xe] = lo;
  }

  return;
  mismatch:
  base[0x4e] = 1;

}








/*
 * Conditional state repair: when the context's +0x352 flag is clear the
 * object's +0x4A state is only pushed to 7 if it is not already 5, otherwise
 * 7 is stored unconditionally.  The `!= 0` arm is the branch and the `== 0`
 * arm is the fall-through, so that polarity is the source order; the inner
 * store is the conditional `movne`/`strbne` pair.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A118.c \
 *       --func func_0203A118 --addr 0x0203A118 --cc 1.1p1 --arm
 */
void func_0203A118(u8 *p)
{
    if (((struct Obj15952 *)((char *)func_0203D788()))->f352 == 0) {
        if (p[0x4A] != 5)
            p[0x4A] = 7;
    } else {
        p[0x4A] = 7;
    }
}








void func_0203A150(int a0, int a1, struct Msg *msg, int a3, struct Peer *peer)
{
    struct Glob_0203A118 *g;
    u8 mac[8];
    u32 id;

    g = func_0203D798();
    id = func_020395EC((struct Entry *)peer);
    if (id == 0xff)
    {
        peer->f4a = 5;
        return;
    }

    if (g->f6e != 0)
    {
        if (g->f6e != msg->f0f)
            func_0203A118((u8 *)peer);
        if (g->f6e != msg->f0e)
            func_0203A118((u8 *)peer);
    }
    else
    {
        if (g->f67 != msg->f0f)
            func_0203A118((u8 *)peer);
        if (g->f67 != msg->f0e)
            func_0203A118((u8 *)peer);
    }

    OS_GetMacAddress(mac);
    if (func_0203EFC8(msg->mac, mac, 6) == 0)
    {
        if (msg->f0c != func_020395EC((struct Entry *)peer))
            func_0203A118((u8 *)peer);
    }

    if (peer->f4a == 7)
        return;

    func_0203996C(msg->f0c)->f4a = 5;

    if (g->f0c != 0)
        g->f0c(a3, msg->f0c);

    func_0203DAC4(msg->mac);
    func_0203DAC4((const u8 *)msg);
}









/*
 * A message-table handler that forwards to func_0203A338 with the message's
 * first byte as its only argument.  The five-argument table shape puts the
 * message pointer in r2, so the whole body is `ldrb r0,[r2]` followed by the
 * tail call, which one section per function forces to be a pool word and a
 * `bx ip` rather than a displacement branch
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The remaining
 * parameters are leftovers and are not passed
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A27C.c \
 *       --func func_0203A27C --addr 0x0203A27C --cc 1.1p1 --arm
 */
void func_0203A27C(u32 a0, u32 a1, u8 *msg, u32 a3, u32 a4)
{
    func_0203A338(*msg);
}









/*
 * Set or clear one bit of the 16-bit slot mask, reporting at line 0x391 (913)
 * when the bit index is the 0xFF sentinel.  This is the write half of
 * func_0203A2F0's read (line 0x3AB), sharing its file/message pair.
 *
 * The mask is a u16 throughout, which is what the `lsl #0x10` / `lsr #16`
 * pairs around every store of it are: `1 << idx` is built in a word, narrowed
 * to 16 bits for the OR, and the complement for the clear arm is narrowed
 * THREE times: `~` widens back to int, the AND is done in int, and the result
 * is narrowed once more on the way to the variable.  Writing the clear arm as
 * the compound `mask &= (u16)~(u16)(1 << idx)` is 8 bytes short (one
 * `lsl`/`lsr` pair missing); the narrowing has to be spelled on the whole
 * assignment, `mask = (u16)((u16)mask & (u16)~(u16)(1 << idx))`.  The
 * set arm is the `orrne` and the clear arm the `mvneq` chain, so the source
 * polarity is `set != 0` first (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A28C.c \
 *       --func func_0203A28C --addr 0x0203A28C --cc 1.1p1 --arm
 */
u16 func_0203A28C(u16 mask, u32 idx, u32 set)
{
    if (idx == 0xFF)
        func_02034714(file_020A7A68, 0x391, file_020A7AB0);

    if (set != 0)
        mask |= (u16)(1 << idx);
    else
        mask = (u16)((u16)mask & (u16)~(u16)(1 << idx));

    return mask;
}









/*
 * Tests one bit of a channel mask, the 0xFF argument being a non-fatal
 * report at line 0x3AB (939).  The mask is truncated to a byte before the
 * `tst`, which is the `(u8)` cast in the shift expression, and the result is
 * materialised as 1/0 in r0 rather than left as the `tst` flags.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A2F0.c \
 *       --func func_0203A2F0 --addr 0x0203A2F0 --cc 1.1p1 --arm
 */
u32 func_0203A2F0(u32 a0, u32 a1)
{
    if (a1 == 0xFF)
        func_02034714(file_020A7A68, 0x3AB, file_020A7AB0);
    return (a0 & (u8)(1 << a1)) != 0;
}









/*
 * Promoted from src/pending/ on lane 1: every concrete byte is right (80 of
 * 80).  The one open site was the `bl` to 0x0203971C, whose only branch site
 * image-wide is this one, so `label` had no outside witness.  With
 * src/matched/func_0203971C.c filed EXACT the site resolves through the
 * `matched` class and the file prints EXACT with no change to its C.
 *
 * Pushes a slot's identity into both halves of the table, reporting at line
 * 0x3BE (958) when the identity is the 0xFF sentinel.  Each half is
 * `record((struct Entry *)func_0203996C(selector), id)` with the selector's result already in
 * r0, so the second call's first argument is the first call's return value
 * and no local is needed to hold it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A338.c \
 *       --func func_0203A338 --addr 0x0203A338 --cc 1.1p1 --arm
 */
void func_0203A338(u32 a0)
{
    if (a0 == 0xFF)
        func_02034714(file_020A7A68, 0x3BE, file_020A7AB0);
    func_02039658((struct Entry *)func_0203996C(a0), a0);
    func_0203971C((unsigned char *)(struct Entry *)func_0203996C(0xFF), a0);
}









/*
 * Install a payload into slot `id`: bail out when the receiver is the own
 * link (func_020395EC returning 0xFF), report at line 0x3D1 (977) when the
 * slot index is out of range, free whatever the slot already holds, allocate
 * `len` bytes out of the heap named by the record's +0x56 halfword (line
 * 0x3D8), publish the buffer and its length together, and copy the payload
 * in.
 *
 * THIS FUNCTION TAKES FIVE PARAMETERS, NOT FOUR.  That is the whole of what
 * docs/notes/pkt_0203A388.c.txt diagnosed as a register-colouring residue.
 * The prologue is `push {r3, r4, r5, r6, r7, lr}`, six registers and so 0x18
 * bytes of frame, which makes the `ldr r0, [sp, #0x18]` at +0x18 a read
 * ABOVE the frame -- the caller's fifth argument -- and not the r3 home slot
 * the note read it as.  r3 is a dead fourth argument, the table-handler shape
 * this family uses throughout (func_0203A150, func_02039B5C, func_0203A27C).
 * Written with four parameters the compiler has to keep the receiver in a
 * register across func_0203D798, which costs r8, an extra callee-saved and a
 * spill slot: 172 bytes against 156.  With the fifth parameter the body is
 * size-exact and two bytes out, both of them trivial:
 *
 *   - the slot bound is SIGNED (`int id`, `id >= 9`).  The image's `blt`
 *     becomes `blo` the moment the index is unsigned.
 *   - the allocator's name argument is the file string 0x020A7A68, the same
 *     word the assert's first argument uses, NOT the message 0x020A7ACC.
 *     Both are pool words at nearly the same displacement, so the wrong one
 *     costs exactly one byte of `ldr` offset.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A388.c \
 *       --func func_0203A388 --addr 0x0203A388 --cc 1.1p1 --arm
 */
void func_0203A388(int id, u32 len, const void *src, u32 a3, void *obj)
{
    u8 *g;
    struct Slot *s;

    g = func_0203D798();
    if (func_020395EC(obj) == 0xff)
        return;
    if (id >= 9)
        func_02034714(file_020A7A68, 0x3D1, file_020A7ACC);
    s = (struct Slot *)(struct Entry *)func_0203996C(id);
    if (s->buf != 0)
        func_020307B0(s->buf);
    s->buf = func_02030734(((struct Obj15954 *)g)->f56, len, 1, file_020A7A68, 0x3D8);
    s->len = len;
    MI_CpuCopy8(src, s->buf, len);
}








void func_0203A424(char *p, int a, int b, int c)
{
    if (p == 0)
        return;
    ((struct Obj06942 *)p)->f46 = (unsigned short)(a + (b << 8));
    p[0x48] = (char)c;
    if (func_020395EC((struct Entry *)p) == 0xff)
        p[0x49] = 0;
    else
        p[0x49] = 1;
}









/*
 * Broadcasts a byte value to the +0xE and +0xF bytes of all nine channel
 * records at ((u32 *)arg0)[i + 2], skipping the ones whose +0xD flag is
 * clear.  The argument truncation is written at both stores and the compiler
 * hoists the single `and r1, r1, #0xff` out of the loop into the argument
 * register itself, after the loop counter has been initialised.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A458.c \
 *       --func func_0203A458 --addr 0x0203A458 --cc 1.1p1 --arm
 */
void func_0203A458(u8 *a0, u32 a1)
{
    int i;

    if (a0 == 0)
        return;
    for (i = 0; i < 9; i++) {
        u8 *q = *(u8 **)(a0 + (i << 2) + 8);

        if (q != 0 && q[0xD] != 0) {
            q[0xE] = (u8)a1;
            q[0xF] = (u8)a1;
        }
    }
}









/*
 * Lazy-init wrapper: the 0x22c-byte context at g_021469D8 is allocated on
 * first use with the debug allocator (heap 0, size 0x22c, flags 1, line
 * 0x96), the delegate func_0203A574 is called, arg3 is published at +8 of
 * the state object in g_020A7AE8, and the 8-byte run at +0x220 plus the byte
 * at +0x228 are cleared.
 *
 * The clearing loop reloads g_021469D8 from memory on every iteration
 * (`ldr r1, [r0]` sits inside the back edge), which is what a global
 * POINTER read in a loop body compiles to when nothing in the loop proves it
 * cannot change -- writing `u8 *p = g_021469D8;` first would hoist the load
 * and change three instructions.  The loop counter is initialised before the
 * `str r5, [r0, #8]` store (`mov r3, #0` at +0x60), and the byte index is
 * added to the reloaded pointer rather than to a running cursor.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A494.c \
 *       --func func_0203A494 --addr 0x0203A494 --cc 1.1p1 --arm
 */
void func_0203A494(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    int i;

    if (g_021469D8 == 0) {
        g_021469D8 = (struct NetCmd *)func_02030734(0, 0x22c, 1, g_020A7AF8, 0x96);
    }
    func_0203A574(a0, a1, a2, a3);
    g_020A7AE8.f8 = a3;
    for (i = 0; i < 8; i++) {
        g_021469D8->f220[i] = 0;
    }
    g_021469D8->f228 = 0;
}





void func_0203A53C(void)
{
    if (g_021469D8 == 0)
        return;
    func_02082BCC(g_021469D8, 0, 0x22c);
    func_020307B0(g_021469D8);
    g_021469D8 = 0;
}





void func_0203A574(u32 a, u32 b, u32 c, u32 d)
{
    struct NetCmdGrp *p = g_021469D8->grp;
    int i;

    if (p == 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        if (p[i].key == 0 || p[i].key == a) {
            p[i].key = a;
            g_021469D8->grp[i].list = (void *)b;
            g_021469D8->grp[i].count = c;
            g_021469D8->grp[i].f8 = d;
            return;
        }
    }
}




void func_0203A5E4(u32 key)
{
    struct NetCmdGrp *e = g_021469D8->grp;
    int i;

    if (e == 0)
        return;
    for (i = 0; i < 4; i++) {
        if (e[i].key == key) {
            func_02082BCC(&e[i], 0, 0x10);
            return;
        }
    }
}






/*
 * Bit test against a channel mask: 0xFF is always live, otherwise the bit of
 * the argument named by the index func_02039338() reports decides, and a zero
 * index falls back to the 0x80 bit.  `1 << f()` is emitted as the shifted
 * register of a `tst`, and each success path is the conditional
 * `movne r0, #1` / `popne` pair, so the source is the return chain above a
 * final plain `return 0;`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A634.c \
 *       --func func_0203A634 --addr 0x0203A634 --cc 1.1p1 --arm
 */
u32 func_0203A634(u32 a0)
{
    if (a0 == 0xFF)
        return 1;
    if (a0 & (1 << func_02039338()))
        return 1;
    if (func_02039338() == 0 && (a0 & 0x80) != 0)
        return 1;
    return 0;
}






/*
 * net_command.c's command-record lookup.  The 16-bit command is split into
 * a group (the high byte, kept unshifted throughout: the original compares
 * the masked value, never a shifted one) and an index (the low byte).
 *
 * Group 0 is the static base table at 0x020A7AE8 -- a { void *list; int
 * listNum; } pair whose strings name it "_BaseTable" (the assert text at
 * 0x020A7B08 reads "_BaseTable.listNum > co...", 0x020A7AF8 is
 * "net_command.c", and the line number is 0x10D).  listNum is SIGNED: the
 * guard is `bgt`, not `bhi`.
 *
 * Any other group scans the four 0x10-byte records behind the pointer at
 * 0x021469D8, the _pCommandWork context src/matched/func_0203A494.c
 * allocates; the second assert string at 0x020A7B20 names those records
 * "_pCommandWork->aNetHugeRecv[index].used".
 *
 * TWO POOL WORDS FOR ONE ADDRESS.  The original spends two separate pool
 * entries on 0x020A7AE8 (at +0x78 and +0x88).  It is one object reached by
 * two declarations: the `.listNum` guard reads the struct, while the
 * returned pointer is the list base spelled as an array.  Collapsing them
 * into a single `&g_020A7AE8` makes the file 140 bytes, four short.
 *
 * DECLARATION ORDER.  `int i` must be declared BEFORE the two masks, and
 * the index must be `int`, not `u32`.  With the masks first the 3-register
 * rotation r2 -> ip -> r3 -> r2 appears and nothing else moves it (found by
 * tools/permuter.py: decl-order(lo<->i) ; decl-order(hi<->i)).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A67C.c \
 *       --func func_0203A67C --addr 0x0203A67C --cc 1.1p1 --arm
 */
struct NetCmdGrp *func_0203A67C(u32 cmd)
{
    int i;
    u32 hi = cmd & 0xff00;
    int lo = (int)(cmd & 0xff);

    if (hi == 0) {
        if (g_020A7AE8.count <= lo)
            func_02034714(g_020A7AF8, 0x10D, g_020A7B08);
        return &g_020A7AE8_arr;
    }
    for (i = 0; i < 4; i++) {
        struct NetCmdGrp *r = g_021469D8->grp + i;
        if (hi == r->key) {
            if (r->count <= lo)
                return 0;
            return (struct NetCmdGrp *)r;
        }
    }
    return 0;
}






int func_0203A70C(u32 idx)
{
    int *p = (int *)func_0203A67C(idx);
    if (p != 0) {
        char *base = (char *)*p;
        u32 off = ((idx << 24) >> 21);
        return *(int *)(base + off);
    }
    return 0;
}






/*
 * The null-tolerant third word of the object func_0203A67C caches: the
 * conditional `ldrne` / `moveq` pair is exactly the `? :` form, not an
 * if/return, which would have needed a second epilogue.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A730.c \
 *       --func func_0203A730 --addr 0x0203A730 --cc 1.1p1 --arm
 */
u32 func_0203A730(u32 cmd)
{
    u32 *p = (u32 *)func_0203A67C(cmd);

    return p != 0 ? p[2] : 0;
}






int func_0203A748(u32 idx)
{
    int *p = (int *)func_0203A67C(idx);
    if (p != 0) {
        char *base = (char *)*p;
        u32 off = ((idx << 24) >> 21);
        return *(int *)(base + off + 4);
    }
    return 0;
}






void func_0203A770(u32 a, u32 b, int c, u32 d, u32 e, u32 f)
{
    u32 ok;
    u32 fn;

    if (func_0203A634(b) == 0) {
        return;
    }
    ok = 1;
    if (func_020399B8((u8 *)f) == 0) {
        if (c >= 0x11) {
            ok = 0;
        }
    }
    if (ok == 0) {
        return;
    }
    fn = func_0203A70C(c);
    if (fn == 0) {
        return;
    }
    ((void (*)(u32, u32, u32, u32, u32))fn)(a, d, e, func_0203A730(c), f);
}






int func_0203A7EC(unsigned int idx)
{
    return func_0203A70C(idx) != 0;
}






int func_0203A804(unsigned int idx)
{
    return func_0203A748(idx) != 0;
}






/*
 * Indirect dispatch: the first argument names a slot whose function pointer
 * comes back from func_0203A748; a null slot answers 0 with the conditional
 * `moveq`/`popeq` pair, and otherwise the pointer is called with the second
 * argument, the current value func_0203A730 reports and the third argument.
 * func_0203A730's own body ignores its parameter, but the caller still loads
 * one, so the source declares it with a parameter.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A81C.c \
 *       --func func_0203A81C --addr 0x0203A81C --cc 1.1p1 --arm
 */
u32 func_0203A81C(u32 a0, u32 a1, u32 a2)
{
    u32 (*f)(u32, u32, u32) = (u32 (*)(u32, u32, u32))func_0203A748(a0);

    if (f == 0)
        return 0;
    return f(a1, func_0203A730(a0), a2);
}




void func_0203A858(void)
{
}







/*
 * One slot of a network table: index 0xff aliases to slot 8, the incoming
 * tag must match func_020399A8(), and the entry is swept copy-then-count.
 * The global pointer at 0x021469D8 is re-read after every call, so the C
 * dereferences it afresh in each statement rather than keeping a local.
 *
 * The fifth parameter is volatile: every use re-reads its incoming stack
 * slot (ldr r1,[sp,#0x20] after the tag call, ldr r0,[sp,#0x20] again for
 * func_0203A770) instead of living in a callee-saved register, which is what
 * keeps the saved set at r4-r8 rather than adding sb.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A85C.c \
 *       --func func_0203A85C --addr 0x0203A85C --cc 1.1p1
 */
void func_0203A85C(int a0, u32 a1, void *a2, int a3, volatile int a4)
{
    int idx = a0;

    if (a0 == 0xff) {
        idx = 8;
    }
    if (a4 != (u32)func_020399A8()) {
        return;
    }
    if (g_021469D8->ent[idx].f12 == 0) {
        return;
    }
    if (g_021469D8->ent[idx].f04 != 0) {
        MI_CpuCopy8(a2,
                    (void *)(g_021469D8->ent[idx].f04
                             + g_021469D8->ent[idx].f0C
                                   * g_021469D8->ent[idx].f0A),
                    a1);
    }
    g_021469D8->ent[idx].f0C++;
    if (g_021469D8->ent[idx].f0C != g_021469D8->ent[idx].f0E) {
        return;
    }
    if (g_021469D8->ent[idx].f04 != 0) {
        func_0203A770(a0, g_021469D8->ent[idx].f10,
                      g_021469D8->ent[idx].f08, g_021469D8->ent[idx].f00,
                      g_021469D8->ent[idx].f04, a4);
    }
    g_021469D8->ent[idx].f12 = 0;
}






/*
 * net_command.c: register the command record a2 in slot a0 (0xff -> 8) of
 * the 0x14-stride table at g_021469D8 + 0xb8, asserting the slot was free
 * (line 0x1ff) and that func_0203A81C accepted it (line 0x203).
 *
 * Closed from docs/notes/pkt_0203A958.c.txt (39 bytes out) by the same
 * lever as func_0203A020 in net_handle.c: the record parameter is
 * `const u8 *a2`, which lets the `*(u32 *)a2` load hoist above the in-use
 * strb and the five halfword copies interleave as the image has them.
 * The permuter's old `tmp` local for the +6 halfword is then unneeded.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A958.c  *       --func func_0203A958 --addr 0x0203A958 --arm --cc 1.1p1
 */
void func_0203A958(int a0, int a1, const u8 *a2, int a3, int a4)
{
  int i;
  u16 v0, v2, v8, v6;
  i = a0;
  if (a0 == 0xff)
    i = 8;
  if (a4 != (int)func_020399A8())
    return;
  if (func_0203A81C(*((u16 *) (a2 + 6)), a0, *((u32 *) a2)) == 0)
    return;
  if ((g_021469D8->ent[i].f12) != 0)
    func_02034714(sNet3730, 0x1ff, sNet3733);
  g_021469D8->ent[i].f12 = 1;
  {
    u32 w = *((u32 *) a2);
    g_021469D8->ent[i].f00 = w;
    g_021469D8->ent[i].f04 = func_0203A81C(*((u16 *) (a2 + 6)), a0, w);
  }
  if ((g_021469D8->ent[i].f04) == 0)
    func_02034714(sNet3730, 0x203, sNet3734);
  v0 = *((u16 *) (a2 + 6));
  v2 = *((u16 *) (a2 + 8));
  v8 = *((u16 *) (a2 + 0xa));
  v6 = *((u16 *) (a2 + 4));
  g_021469D8->ent[i].f08 = v0;
  g_021469D8->ent[i].f0A = v2;
  g_021469D8->ent[i].f10 = v8;
  g_021469D8->ent[i].f0E = v6;
  g_021469D8->ent[i].f0C = 0;
}







/*
 * The net_command.c command-queue trio, 0x0203AA94..0x0203AD6C, folded into
 * one translation unit: the enqueue (func_0203AA94), the header pump
 * (func_0203ABC0) and the chunk pump (func_0203ACAC).  All three walk the
 * same five 0x18-byte slot table at g_021469D8 and share the 4-bit status
 * nibble pair at record +0x17 / table +0x57.  Filed as a unit because the
 * three are individually EXACT and reproduce the range with its pools.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203AA94.c \
 *       --addr 0x0203AA94 --arm
 */
u32 func_0203AA94(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    u8 *cfg;
    struct NetCmd *t;
    u8 *st57;
    struct NetCmdSlot *s;
    int i;
    int mtu;
    Status *sc;
    Status *st;

    cfg = func_0203D798();
    t = g_021469D8;
    st57 = &t->slot[0].f17;
    for (i = 0; i < 5; i++) {
        sc = (Status *)&st57[i * 0x18];
        if (sc->hi)
            continue;
        if (sc->lo == 0)
            break;
    }
    if (i == 5)
        return 0;

    s = &t->slot[i];
    s->f4 = a3;
    mtu = cfg[0x61] - 0xc;
    if (mtu <= 0)
        func_02034714(g_020A7AF8, 0x22b, g_020A7B78);
    s->fE = cfg[0x61] - 0xc;
    s->f14 = a3 / s->fE;
    s->f10 = a3 % s->fE;
    if (s->f10 != 0)
        s->f14 = s->f14 + 1;
    s->f12 = 0;
    s->fC = a2;
    s->f16 = a1;
    s->f8 = a4;
    s->f0 = func_020395EC((void *)a0);
    st = (Status *)&s->f17;
    st->hi = 1;
    return st->hi;
}







u32 func_0203ABC0(void)
{
    u16 hdr[6];
    struct NetCmdSlot *s;
    Status *st;
    struct NetCmdSlot *t;
    int i;

    t = g_021469D8->slot;
    for (i = 0; i < 5; i++) {
        s = t + i;
        st = (Status *)&s->f17;
        if (st->hi) {
            hdr[2] = s->f14;
            *(u32 *)&hdr[0] = s->f4;
            hdr[3] = s->fC;
            hdr[4] = s->fE;
            hdr[5] = s->f16;
            st->lo = func_02038C18(0xd, (u32)hdr, 0xc, 1,
                                   s->f0, s->f16, 0);
            st->hi = 1 - st->lo;
            return st->lo;
        }
    }
    return 0;
}







void func_0203ACAC(void)
{
    int i;
    u32 n;
    u32 c;
    u32 base;
    struct NetCmd *t;
    struct NetCmdSlot *s;

    t = g_021469D8;
    for (i = 0; i < 5; i++) {
        if ((u32)(t->slot[i].f17 << 0x1c) >> 0x1c) {
            s = &t->slot[i];
            c = s->f12;
            n = s->fE;
            base = s->f8 + n * c;
            if (c + 1 == s->f14)
                n = s->f10;
            if (func_02038C18(0xc, base, n, 1,
                              s->f0, s->f16, 1) != 0)
                s->f12 = s->f12 + 1;
            if (s->f12 == s->f14)
                s->f17 = s->f17 & ~0xf;
            return;
        }
    }
    func_0203ABC0();
}






/*
 * Setter and its tail-call export in net_state.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203AD74.c \
 *       --addr 0x0203AD74 --arm --cc 1.1p1
 */
void func_0203AD74(struct NetState *s, void *p, u16 v)
{
    s->unk8 = p;
    s->unk46 = v;
}





void func_0203AD80(struct NetState *s, void *p, u16 v, int line)
{
    func_0203AD74(s, p, v);
}






/*
 * One-shot constructor: the singleton must still be NULL (otherwise
 * func_02034714(__FILE__, 0xb8, __FILE__)), 0x64 bytes are allocated with
 * the debug allocator, a halfword 0x32 and a byte 1 are set at +0x46 and
 * +0x4c, the embedded object at +0xc is initialised, and the 5-argument
 * delegate func_0203A494 is called with four zeros.
 *
 * The fields are written through the global every time -- the second and
 * third uses reload `[r1]` (`ldr r0, [r1]` twice after the store) while the
 * first reuses the allocator's return value in r0 -- which is what
 * `g_021469DC->f46 = ...` spells and what a local pointer would not.
 *
 * Parked at MATCH, blocking class: label.  The only unresolved relocation is
 * the call at +0x68
 *   +0068 PC24 func_0203AE20 -> unresolved: 0203AE20 (arm, from header) has
 *                                            no witness outside
 *                                            0203AD8C..0203AE20
 * -- the callee 0x0203AE20 sits at the very end of this function's listing
 * extent and this call is its only branch anywhere in the image, so the
 * `label` class has no outside witness.  It graduates for free, with no
 * change to this C, as soon as src/matched/ holds a func_0203AE20 entry:
 * the `matched` class then witnesses the site.  func_0203AE20 itself is
 * chain-capped on 0x0203F0A8 (see docs/notes/func_0203F0A8.c.txt), which is
 * why the pair is parked rather than finished here.
 */
void func_0203AD8C(u32 a0)
{
    if (g_021469DC != 0) {
        func_02034714(g_020A7BA8, 0xb8, g_020A7BB4);
    }
    g_021469DC = (u8 *)func_02030734(a0, 0x64, 1, g_020A7BA8, 0xb9);
    *(u16 *)(g_021469DC + 0x46) = 0x32;
    *(u8 *)(g_021469DC + 0x4c) = 1;
    func_0203AE20((MATHRandContext64 *)(g_021469DC + 0xc));
    func_0203A494(0, 0, 0, 0, a0);
}






static inline void MATH_InitRand64(MATHRandContext64 *context, u64 seed)
{
    context->x = seed;
    context->mul = 0x5d588b656c078965ULL;
    context->add = 0x269ec3ULL;
}






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203AE20.c  *       --func func_0203AE20 --addr 0x0203AE20 --cc 1.1p1 --arm
 *
 * net_state.c RNG seeder.  Mixes the MAC with the RTC date/time and the
 * system word 0x02FFFC3C, seeds func_0203F034, draws two words into one
 * u64 seed, and initialises a NitroSDK MATHRandContext64 with the SDK's
 * own MATH_InitRand64 inline (x = seed, mul 0x5D588B656C078965, add
 * 0x269EC3).  Wave 14 closed the 8-byte tail tie of
 * docs/notes/pkt_0203AE20.c.txt: +0x08..+0x14 are two u64 members, not
 * four u32 words, so the constants are stored as u64 pairs.
 */
void func_0203AE20(MATHRandContext64 *o)
{
  struct Date d;
  struct Time t;
  u8 mac[6];
  u32 seed;
  OS_GetMacAddress(mac);
  func_020889C0((struct RTCDate *)(&d), (struct RTCTime *)(&t));
  seed = ((d.year + ((d.day * (d.mon << 8)) << 16)) + (t.hour << 16)) + ((t.min + t.sec) << 24);
  seed = seed + (mac[5] + ((mac[3] << 16) + (mac[4] << 8)));
  seed = seed + g_02FFFC3C;
  func_0203F034(seed);
  {
    u32 hi = func_0203F0A8();
    MATH_InitRand64(o, (((u64) hi) << 32) + func_0203F0A8());
  }
}






/*
 * Shuts the network down when the transport's +0x74 virtual answers non-zero:
 * tears the tables down, saves the completion callback out of +0x28, drops
 * the context and finally calls the saved callback.  The callback load is
 * scheduled before func_020307B0 rather than after it and the context is
 * zeroed after that call too - the store-landing-after-the-next-call shape,
 * so the C keeps the callback in a local across the call.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203AEEC.c \
 *       --func func_0203AEEC --addr 0x0203AEEC --cc 1.1p1 --arm
 */
void func_0203AEEC(u8 *p)
{
    void (*f)(void);

    if (((u32 (*)(void))*(u32 *)(*(u32 *)((char *)func_0203D788() + 0x340) + 0x74))() == 0)
        return;
    func_0203A53C();
    func_020370C8();
    func_02037B08();
    f = (void (*)(void))*(u32 *)(*(u32 *)((char *)(0x21469DC)) + 0x28);
    func_020307B0((void *)*(u32 *)((char *)(0x21469DC)));
    *(u32 *)((char *)(0x21469DC)) = 0;
    if (f != 0)
        f();
}






/*
 * Closes docs/notes/pkt_0203AF40.c.txt, which parked this at "DIFF, 10
 * concrete bytes" with an r4/r5 end-to-end swap and additionally predicted a
 * MATCH ceiling.  BOTH of those conclusions were wrong.
 *
 * 1. The r4/r5 swap was an artefact of that attempt's declaration order, not
 *    the real residue.  Declaring the two call results in source order
 *    (`s = func_0203D788()` then `c = func_0203D798()`) puts them in r5/r0
 *    exactly as the image does and the swap never appears.  That left a
 *    2-byte residue at +0x54/+0x58, not 10.
 *
 * 2. THE 2-BYTE RESIDUE: the image reloads the +0x2C callback into r1 and
 *    does `blx r1`, where the obvious C reloads into r0.  The tell is the
 *    `bl func_0203D650` immediately before it whose result looks discarded.
 *    It is not discarded -- it is the callback's ARGUMENT.  Spelling the
 *    field `void (*f2c)(u32)` and writing `p->f2c(func_0203D650())` pins r0
 *    to the argument, so the function pointer has to land in r1.  EXACT.
 *    This is the same shape src/pending/func_0203B52C.c documents for its
 *    own callback ("takes func_0203D650's return value in r0, which is why
 *    the function pointer is loaded into r1") -- a family idiom, not a
 *    one-off.
 *
 * 3. The note's MATCH-ceiling claim ("0x0203C00C is a data address with no
 *    outside witness") is also wrong: 0x0203C00C has TWENTY pool words
 *    image-wide (layout/data_objects.txt line 207 lists six plus twelve
 *    more) and resolves `literal x20, e.g. 0203B5CC`.  All 7 relocation
 *    sites resolve and the file is EXACT, not MATCH.
 *
 * The permuter was run before the hand fix and found nothing: --mode hill
 * --budget 800 (120 singles tried) and --mode anneal --budget 900 (900
 * compiles in 84s) both stayed flat at asm=10 bytes-out=2.  The lever is a
 * change to a function-pointer's SIGNATURE (arity), which is outside the
 * mutation table -- the same class of miss the permuter.md field reports
 * record for `cnt = *p++` and `int weight`.
 */
void func_0203AF40(struct Rec *p)
{
    struct Obj *s = func_0203D788();
    struct Cur *c = func_0203D798();

    if (c->f65 != 1 && c->f65 != 2)
        s->f340->f04(c->f56, s, 0, s->f34c);
    func_02037D78();
    if (p->f2c != 0) {
        p->f2c(func_0203D650());
        p->f2c = 0;
    }
    func_0203AD80((struct NetState *)g_021469DC, (void *)unk_0203C00C, 0, 0x12f);
}
