/*
 * file:     backup_system.c
 * unit:     yes
 * function: func_020316C8, func_0203174C, func_0203192C, FSi_ConvertStringSjisToUnicode, func_0203195C, func_02031994, func_020319A4, func_020319C0, func_020319E4, func_020319F0, func_02031AE0, func_02031B8C, func_02031BB4, func_02031C04, func_02031C10, func_02031C30, func_02031DC0, func_02031E68, func_02031E70, func_02031E7C, func_02031EAC, func_02031ECC, func_02031EE8, func_02031EF8, func_02031F54, func_02031F94, func_02031F9C, cnt16, func_02031FE0, func_02032688, sub_020328E0, sub_02032930, sub_02032970, sub_020329AC, sub_02032A9C, sub_02032BF8, sub_02032C84, func_02032CD0, sub_020331A4, sub_020331D0, sub_02033200, sub_02033264, sub_020332A4, sub_020332FC, sub_0203331C, sub_0203335C, func_020333F8, func_02033410, func_02033478, func_02033494, func_020334B0, func_020334CC, func_020334E8, func_02033534, func_020335AC, func_020335E8, func_020336A4, func_020336B8, func_020337B8, func_0203386C, func_020338B8, func_020338F8, func_02033908, func_020339B4, func_020339D0, func_02033A3C, func_02033A88, func_02033B68, func_02033BAC, sub_02033BF0, sub_02033BF8, sub_02033C00, sub_02033C9C, sub_02033CA8, sub_02033CC0, sub_02033CFC, sub_02033E30, sub_02033F64, sub_02033FB0, sub_020340D0, sub_020341F0, func_0203422C, sub_020342F8, sub_02034348, sub_02034394, sub_020343C0, sub_020344C4, func_020344C8, sub_02034508, sub_02034520, func_02034558, func_020345DC, sub_020345F8, sub_02034630, sub_02034640, func_02034660, sub_020346B8, sub_020346D8, sub_020346EC, func_02034704, sub_02034714, sub_02034734
 * address:  0x020316C8
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
 *   func_02030734  0x02030734  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_020819B8  0x020819B8  arm
 *   str_020A7848   0x020A7848  data
 *   g_02146994     0x02146994  data
 *   func_02033BF8  0x02033BF8  arm
 *   func_02034714  0x02034714  arm
 *   str_020A7858   0x020A7858  data
 *   str_020A7868   0x020A7868  data
 *   func_02034F84  0x02034F84  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02034FB8  0x02034FB8  arm
 *   func_020329AC  0x020329AC  arm
 *   func_02033200  0x02033200  arm
 *   func_020331A4  0x020331A4  arm
 *   MATH_CalcCRC16CCITT  0x02081B8C  arm
 *   func_02082A60  0x02082A60  arm
 *   func_02033BF0  0x02033BF0  arm
 *   func_0203331C  0x0203331C  arm
 *   func_02081B8C  0x02081B8C  arm
 *   func_020332FC  0x020332FC  arm
 *   func_02032A9C  0x02032A9C  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_020332A4  0x020332A4  arm
 *   str_020A7888   0x020A7888  data  a1
 *   MI_CpuFill8    0x02082BCC  arm
 *   str_020A78A0   0x020A78A0  data
 *   str_020A78B0   0x020A78B0  data
 *   func_02084EB8  0x02084EB8  arm
 *   func_02075E9C  0x02075E9C  arm
 *   func_02076B2C  0x02076B2C  arm
 *   func_02075EAC  0x02075EAC  arm
 *   func_02084F10  0x02084F10  arm
 *   CARDi_RequestStreamCommand 0x02076AC0  arm
 *   func_02076B80           0x02076B80  arm
 *   d_020A789C  0x020A789C  data
 *   g_02146998     0x02146998  data
 *   g_020A789C     0x020A789C  data
 *   func_02075DD8  0x02075DD8  arm
 *   func_02076B8C 0x02076B8C  arm
 *   func_02076B98 0x02076B98  arm
 *   g_020A78CC       0x020A78CC  data
 *   MIi_CpuClear32   0x02082A7C  arm
 *   str_020A78CC   0x020A78CC  data
 *   str_020A78D8   0x020A78D8  data
 *   str_020A78F0   0x020A78F0  data
 *   str_020A7908   0x020A7908  data
 *   func_02034734  0x02034734  arm
 *   str_020A793C   0x020A793C  data
 *   sub_02033C00_File  0x020A7958  data
 *   func_02033CFC  0x02033CFC  arm
 *   func_02033E30  0x02033E30  arm
 *   g_RunLenAny    0x020A06A0  data
 *   g_RunLenTail   0x020A05A0  data
 *   g_RunLenHead   0x020A04A0  data
 *   func_020342F8  0x020342F8  arm
 *   func_020343C0  0x020343C0  arm
 *   func_02034508  0x02034508  arm
 *   func_02033FB0  0x02033FB0  arm
 *   func_020340D0  0x020340D0  arm
 *   func_02034348  0x02034348  arm
 *   Areaman_RunMask   0x020A048C  data
 *   Areaman_TailMask  0x020A0495  data
 *   func_020344C4  0x020344C4  arm
 *   g_FlagTable  0x020A07C8  data
 *   sub_02030734  0x02030734  arm
 *   s_clact_c     0x020A7964  data
 *   g_Table1  0x020A07A0  data
 *   g_Table2  0x020A07A4  data
 *   func_02033CA8  0x02033CA8  arm
 *   sub_0203422C  0x0203422C  arm
 *   g_Sink  0x0214699C  data
 *   _u32_div_f    0x0209C2B0  arm
 */
#include "../../matched/include/Obj15875.h"
#include "../../matched/include/Obj06929.h"
#include "../../matched/include/Obj11324.h"
#include "../../matched/include/Obj02604.h"
#include "../../matched/include/Obj08815.h"
#include "../../matched/include/Obj15878.h"
#include "../../matched/include/Obj15879.h"
#include "../../matched/include/Obj03443.h"
#include "../../matched/include/Obj08816.h"
#include "../../matched/include/Obj16793.h"
#include "../../matched/include/Obj08817.h"
#include "../../matched/include/Obj08818.h"
#include "../../matched/include/Obj15881.h"
#include "../../matched/include/Obj08819.h"
#include "../../matched/include/Obj11327.h"
#include "../../matched/include/Obj15882.h"
#include "../../matched/include/Obj01312.h"
#include "../../matched/include/Obj11330.h"
#include "../../matched/include/Obj11331.h"
#include "../../matched/include/Obj11332.h"

struct MATHCRC16Table;
struct Obj02033410;
struct Obj02033BF0;
struct Blk;
struct In;
struct T;
struct SaveBackup;
struct Save;
struct Save_02032CD0;
struct Obj020332FC;
struct Obj0203335C;
struct Save_020339B4;
struct Struct_020344C8;
struct AreaMan;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct SaveBackup {
    u8  pad00[0x0C];
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u8  unk18;
    u8  unk19;
    u8  pad1A[2];
    u8  unk1C;
    u8  pad1D[11];
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u8  unk38[0x108];
    u32 unk140;
    u32 unk144;
};

struct SaveMain {
    u32 unk000;
    u8 crcTable[0x200];
    u32 unk204;
    u32 unk208;
    u16 unk20C;
};

struct In {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
};

struct Blk {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u8  pad10[0x1c - 0x10];
    u8  f1c;
    u8  f1d;
    u8  pad1e[0x24 - 0x1e];
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u8  pad38[0x138 - 0x38];
    u32 f138;
    u32 f13c;
    u32 f140;
};

typedef struct Save Save;

struct Save {
    u8   pad00[0x2c];
    u8  *f2c;
    u32  f30;
    u8  *f34;
    u8   pad38[0x108];
    u32  f140;
};

typedef struct Save_02032CD0 Save_02032CD0;

struct Save_02032CD0 {
    u32  f00;
    u32  f04;
    u8   pad08[0xc];
    u32  f14;
    u8   f18;
    u8   f19;
    u8   pad1A[0x12];
    u8  *f2c;
    u8   pad30[0x114];
    u32  f144;
    u32  f148;
    u32  f14c;
    u32  f150;
};

struct Obj020332FC {
    char pad[0x138];
    u32 *slots;
};

struct Obj0203335C {
    char pad[0x2c];
    void *unk2c;
    char pad30[0x108];
    u32 *slots;
};

struct Obj02033410 {
    char pad[0x2c];
    void *unk2c;
    char pad30[0x108];
    u32 *slots;
    u32  nbytes;
};

typedef struct T {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
} T;

struct Src { u32 id; void *fn; u32 w08; };

struct Dst { u32 id; u32 size; u32 offset; };

struct Save_020339B4 {
    struct Src *src;   /* +0x00 */
    u32 count;         /* +0x04 */
    u32 f08;           /* +0x08 */
    u32 f0c;           /* +0x0c */
    u32 f10;           /* +0x10 */
    struct Dst *dst;   /* +0x14 */
    u32 f18;           /* +0x18 */
};

struct Obj02033BF0 {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0c;
};

struct AreaMan {
    u16 unk00;
    u16 unk02;
    u32 *guard;
    u32 unk08;
    u8 bits[1];
};

struct Struct_020344C8 {
    u8 pad[2];
    u16 count;
    u32 unk_4;
    void *ptr;
    u8 data[];
};

struct Job {
    u32 f00;
    u32 f04;
    u32 f08;
    u8  pad_0c[0x10];
    u8  f1c;
};

struct State {
    u32 f00;
    u32 f04;
    u8  pad08[0x14];
    u8  f1c;
};

struct Obj {
    u32  f00;
    u32  f04;
    u8   pad08[0x16];
    u8   f1e;
    u8   f1f;
    u32 *f20;
    u8   pad24[4];
    u32  f28;
};

typedef struct Obj02031DC0 {
    u32 f00;
    u32 f04;
    u8  pad08[0x14];
    u8  f1c;
} Obj02031DC0;

struct Footer {
    u32 gen;
    u32 size;
    u32 id;
    u16 pad;
    u16 crc;
};

typedef signed int     s32;

typedef struct {
    u32 f0;
    u32 size;
    u32 off;
} Ent;

typedef struct {
    u32 f0;
    u32 f4;
    u32 fn;
} PtrEnt;

typedef u32 (*FP)(void);

struct Obj02034508 {
    char pad[8];
    u32 unk08;
};

struct FlagEntry {
    u32 flag;
    u32 value;
};

struct Bank {
    void *data;
    u16   height;
    u16   base;
};

struct Struct020345DC {
    void *ptr;
};

struct Entry8 {
    u32 key;
    u32 pad;
};

struct Sentinel {
    u32 lo;
    u32 hi;
};

struct Owner {
    void *unk_00;
};

struct Item020346D8 {
    u16 pad0;
    u16 pad2;
    u16 unk04;
    u16 unk06;
    u8 pad_08[0x24];
    void * f2C;
    unsigned int f30;
    unsigned int f34;
    u8 pad_38[0x108];
    unsigned int f140;
};

typedef void (*AssertHandler)(void);

struct Sink {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    AssertHandler handler;
};

extern void *func_02030734(u16 heap, u32 size, int align, const char *file,
                         u16 line);
extern void func_02082A7C(u32 a, void *p, u32 n);
extern void func_020819B8(struct MATHCRC16Table *table, u16 poly);
extern u32 func_02033BF8(struct Obj02033BF0 *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_020307B0(void *p);
extern void  func_02034F84(u32 a);
extern void func_02034FB8(u32 v);
extern void func_020329AC(void);
extern u32 func_02033200(struct SaveBackup *p, u32 id);
extern void func_02032970(struct SaveBackup *p, u32 flag);
extern void func_020331D0(struct SaveBackup *p);
extern void func_020331A4(struct SaveBackup *p, u32 result, u32 flag);
extern u16 MATH_CalcCRC16CCITT(const void *table, const void *data, u32 len);
extern void  func_02082A60(const void *src, void *dst, u32 size);
extern u32 func_02033BF0(struct Obj02033BF0 *p);
extern void func_0203331C(struct Obj020332FC *p, u32 idx, u32 val);
extern u16 func_02081B8C(struct MATHCRC16Table *table, void *data, u32 dataLength);
extern u32 func_020332FC(struct Obj020332FC *p, u32 idx);
extern u32 func_02032A9C(struct SaveBackup *p, u32 id, u32 mode, u32 *a,
                         u32 *b, u32 *c, u32 *d);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern u16 func_020332A4(struct SaveBackup *p, u32 id);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern int  func_02084EB8(u32 a);
extern void func_02075E9C(u16 a);
extern int func_02076B2C(int type);
extern void func_02075EAC(u16 a);
extern void func_02084F10(u16 a);
extern int  CARDi_RequestStreamCommand(u32 src, u32 dst, u32 len, void *callback,
                                       void *arg, int is_async, int req_type,
                                       int req_retry, int req_mode);
extern int  func_02076B80(void);
extern u32  func_02075DD8(void);
extern u32 func_02076B8C(void);
extern void func_02076B98(void);
extern void  MIi_CpuClear32(u32 v, void *dst, u32 n);
extern void func_02034734(const char *expr, u32 line, const char *file, ...);
extern s32 func_02033CFC(struct AreaMan *p, u32 start, u32 limit, u32 len);
extern s32 func_02033E30(struct AreaMan *p, u32 start, u32 limit, u32 len);
extern s32 func_020342F8(u32 byte, u32 bit, u32 len);
extern s32 func_020343C0(struct AreaMan *p, s32 pos, u32 len);
extern void func_02034508(struct AreaMan *p, s32 pos, u32 len, u32 line);
extern s32 func_02033FB0(struct AreaMan *p, u32 start, u32 limit, u32 len);
extern s32 func_020340D0(struct AreaMan *p, u32 start, u32 limit, u32 len);
extern s32 func_02034348(u32 byte, u32 bit, u32 len);
extern void func_02034394(u8 *q, u32 bit, u32 len);
extern void func_020344C4(u8 x);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern unsigned int func_02033C9C(void *a);
extern u32 sub_020307B0(void *p);
extern s32 func_02033CA8(struct AreaMan *p, u32 len);
extern void sub_0203422C(struct AreaMan *p, u32 start, s32 len);
void func_020316C8(u32 a0, u32 a1, u32 a2);
struct Blk *func_0203174C(const struct In *in, u32 heap, u32 c, u32 d, u32 e);
u32 func_0203192C(void *a, void *b);
asm void FSi_ConvertStringSjisToUnicode(void);
void func_0203195C(u8 *p);
u32 func_02031994(u8 *p, u32 *out);
u32 func_020319A4(u8 *p, u32 id);
void func_020319C0(u8 *p);
void func_020319E4(void);
int func_020319F0(struct Job *job, u32 heap);
int func_02031AE0(struct State *o, u32 a1);
void func_02031B8C(u8 *p);
int func_02031BB4(u32 a0);
void func_02031C04(struct SaveBackup *a0);
void func_02031C10(u8 *a, u8 *b, u32 v);
int func_02031C30(struct Obj *q, struct Obj *p);
int func_02031DC0(Obj02031DC0 *a0, u32 a1, u32 a2);
int func_02031E68(const char *ptr);
void * func_02031E70(void);
u16 func_02031E7C(struct SaveBackup *p, u8 *buf);
u32 func_02031EAC(u32 *p, u32 sel);
int func_02031ECC(int p0);
int func_02031EE8(int p0, int p1);
u32 func_02031EF8(void *p, void *buf, u32 sel);
void func_02031F54(const struct SaveBackup *p, u8 *buf);
void func_02031F94(int *p, int v);
void func_02031F9C(u32 *out, void *p, void *buf, u32 sel);
int func_02031FE0(Save *self, u32 heap, u32 mode, u32 gen);
int func_02032688(Save *self, int mode, int arg3);
int sub_020328E0(struct SaveBackup *p, u32 sel);
int sub_02032930(struct SaveBackup *p, u32 sel);
void sub_02032970(struct SaveBackup *p, u32 flag);
void sub_020329AC(struct SaveBackup *p, u32 *total, u32 *nominal);
u32 sub_02032A9C(struct SaveBackup *p, u32 id, u32 mode, u32 *pa, u32 *pb, u32 *pc, u32 *pd);
u16 sub_02032BF8(struct SaveBackup *p, u32 id, u32 x, u32 unused);
int sub_02032C84(struct SaveBackup *p, u32 sel);
int func_02032CD0(Save_02032CD0 *p, u32 *out);
void sub_020331A4(struct SaveBackup *p, u32 result, u32 flag);
void sub_020331D0(struct SaveBackup *p);
u32 sub_02033200(struct SaveBackup *p, u32 id);
u16 sub_02033264(struct SaveBackup *p, u32 id);
u16 sub_020332A4(struct SaveBackup *p, u32 id);
u32 sub_020332FC(struct Obj020332FC *p, u32 idx);
void sub_0203331C(struct Obj020332FC *p, u32 idx, u32 val);
void sub_0203335C(struct Obj0203335C *p);
void func_020333F8(Save *self);
void func_02033410(struct Obj02033410 *p, u32 val);
void func_02033478(int a0, int a1, int a2);
void func_02033494(int a0, int a1, int a2, int a3);
void func_020334B0(u16 a0, int a1);
int func_020334CC(u32 a, u32 b, u32 c);
int func_020334E8(u8 *p, u32 b, u32 c, u32 d, u32 e);
int func_02033534(u32 a);
u32 func_020335AC(u32 a, u32 b, u32 c, u32 d);
int func_020335E8(u32 a0, u32 a1, u32 a2, void (*a3)(void));
void func_020336A4(void);
u16 func_020336B8(u32 a0, u32 a1, u32 a2, void *a3);
int func_020337B8(u16 a0, u32 *a1, u32 a2);
void func_0203386C(u16 a);
void func_020338B8(u16 a, u32 b, void (*cb)(u32));
void *func_020338F8(void);
void *func_02033908(u16 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
void func_020339B4(int *p);
void func_020339D0(u32 a, T *sb);
u32 func_02033A3C(u32 *p, u32 i);
void func_02033A88(struct Save_020339B4 *p, u32 v);
u32 func_02033B68(u8 *p, u32 i);
u32 func_02033BAC(u8 *p, u32 i);
u32 sub_02033BF0(struct Obj02033BF0 *p);
u32 sub_02033BF8(struct Obj02033BF0 *p);
struct AreaMan *sub_02033C00(u32 size, u16 heap);
u32 sub_02033C9C(void *a);
s32 sub_02033CA8(struct AreaMan *p, u32 len);
s32 sub_02033CC0(struct AreaMan *p, u32 start, u32 limit, u32 len);
s32 sub_02033CFC(struct AreaMan *p, u32 start, u32 limit, u32 len);
s32 sub_02033E30(struct AreaMan *p, u32 start, u32 limit, u32 len);
s32 sub_02033F64(struct AreaMan *p, u32 start, u32 limit, u32 len);
s32 sub_02033FB0(struct AreaMan *p, u32 start, u32 limit, u32 len);
s32 sub_020340D0(struct AreaMan *p, u32 start, u32 limit, u32 len);
s32 sub_020341F0(struct AreaMan *p, u32 start, u32 len);
void func_0203422C(struct AreaMan *p, u32 start, s32 len);
s32 sub_020342F8(u32 bits, u32 start, u32 len);
s32 sub_02034348(u32 bits, u32 start, u32 len);
void sub_02034394(u8 *p, u32 start, u32 len);
s32 sub_020343C0(struct AreaMan *p, s32 start, u32 len);
void sub_020344C4(void);
void func_020344C8(struct Struct_020344C8 *param);
void sub_02034508(struct Obj02034508 *p);
u32 sub_02034520(u32 flags);
struct Bank *func_02034558(u16 heapId, u32 kind, u32 flags, u32 base, u32 b);
void func_020345DC(struct Struct020345DC *obj);
u32 sub_020345F8(u32 key);
void sub_02034630(struct Sentinel *p);
int sub_02034640(struct Sentinel *p);
int func_02034660(u8 *p, u32 a, void **out);
void sub_020346B8(struct Owner *owner, struct Sentinel *p);
u32 sub_020346D8(struct Item020346D8 *a, u32 *b);
void sub_020346EC(u32 a, u32 b, u32 c);
void func_02034704(u32 v);
void sub_02034714(const char *expr, u32 line, const char *file);
void sub_02034734(const char *expr, u32 line, const char *file, ...);
extern struct SaveMain *g_02146994;
extern const char str_020A7848[];
extern const u8 str_020A7858[];
extern const u8 str_020A7868[];
extern const char str_020A7888[];
extern const u8 str_020A78A0[];
extern const u8 str_020A78B0[];
extern u32 d_020A789C;
extern u32 g_02146998;
extern u32  g_020A789C[];
extern u32 g_020A78CC[];
extern const u8 str_020A78CC[];
extern const u8 str_020A78D8[];
extern const u8 str_020A78F0[];
extern const u8 str_020A7908[];
extern const u8 str_020A793C[];
extern const char sub_02033C00_File[];
extern const u8 g_RunLenAny[256];
extern const u8 g_RunLenTail[256];
extern const u8 g_RunLenHead[256];
extern const u8 Areaman_RunMask[];
extern const u8 Areaman_TailMask[];
extern const struct FlagEntry g_FlagTable[9];
extern char  s_clact_c[];
extern const struct Entry8 g_Table1[5];
extern const struct Entry8 g_Table2[5];
extern struct Sink g_Sink;



/*
 * Blocked at MATCH on the `label`/`matched` classes: all 124 concrete bytes
 * of the body reproduce and 6 of 7 relocation sites resolve, but
 * func_02033534 (PC24 at +0x6c) has exactly one branch reference image-wide
 * and it is this call, so the site has no witness outside 020316C8..0203174C
 * and no cut frees it.  Filing 0x02033534 as an EXACT manifest entry promotes
 * this file with no change to the C.
 *
 * backup_system.c: the one-time allocation of the 0x210-byte save block.
 * The first parameter is narrowed to 16 bits at function entry (the split
 * `lsl r0, r0, #0x10` / `lsr r0, r0, #0x10` pair); written with the mask
 * folded into the call site.
 * The file string is at 0x020A7848 ("backup_system.c", pool word at
 * 0x02031744) and __LINE__ = 0xdf.  The second size argument 0x1100 - 0xdf
 * is spelled as the subtraction because 0x1021 is not an ARM-encodable
 * immediate and mwcc had 0xdf live in a register from the allocator's line
 * argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020316C8.c \
 *       --func func_020316C8 --addr 0x020316C8 --cc 1.1p1 --arm
 */
void func_020316C8(u32 a0, u32 a1, u32 a2)
{
    struct SaveMain *p = func_02030734((u16)a0, 0x210, 0, str_020A7848, 0xdf);

    g_02146994 = p;
    func_02082A7C(0, p, 0x210);
    func_020819B8((struct MATHCRC16Table *)g_02146994->crcTable, 0x1100 - 0xdf);
    g_02146994->unk204 = a1;
    p = g_02146994;
    p->unk208 = a2;
    g_02146994->unk000 = func_02033534((u32)p);
}



/*
 * backup_system.c.  The save-block constructor; its already-matched caller
 * src/matched/func_0203192C.c fixes the five-argument signature.  The
 * allocator func_02030734 takes (heap, size, align, __FILE__, __LINE__)
 * with the line on the stack: 0x10e, 0x125 and 0x131.  0x154 is the block
 * size, kept live in sb, and the second assert's line 0x116 is derived from
 * it as `sub r1, sb, #0x3e` and the last allocation's 0x131 as
 * `add r0, sb, #0x130`
 * (docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md).
 * The `in` parameter must be `const`: without it an unrelated store may
 * alias the fields and the compiler reloads them, 151 concrete bytes out at
 * the same 480
 * (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md).
 * The heap id is narrowed per call site because the callee prototypes take
 * `u16`; a `(u16)heap` cast in the body is CSEd into one register instead.
 * The two size roundings are the `((n + k) >> s) << t` shape written out,
 * with the `tst`/`addne` correction being the low-bit remainder test the
 * front end derives from `+ 2` / `& 0xf`.
 */
struct Blk *func_0203174C(const struct In *in, u32 heap, u32 c, u32 d, u32 e)
{
    struct Blk *b;
    u32 n;
    void *tbl;

    if (g_02146994 == 0)
        func_02034714(str_020A7848, 0x10c, (const char *)str_020A7858);

    b = (struct Blk *)func_02030734(heap, 0x154, 1, str_020A7848, 0x10e);
    b->f00 = in->f08;
    b->f04 = in->f0c;
    b->f08 = in->f10;
    b->f0c = in->f14;

    if (c != 0 && d < b->f08)
        func_02034714(str_020A7848, 0x154 - 0x3e, (const char *)str_020A7868);

    b->f140 = in->f04 << 1;
    if ((in->f04 & 1) != 0)
        b->f140 = b->f140 + 2;

    n = in->f04 + 2;
    b->f13c = (n >> 4) << 2;
    if ((n & 0xf) != 0)
        b->f13c = b->f13c + 4;

    b->f138 = (u32)func_02030734(heap, b->f13c, 1, str_020A7848,
                                 0x125);
    tbl = func_02033908((u16)heap, in->f00, in->f04, b->f08, 0x10, 4, b->f140);
    b->f2c = (u32)tbl;
    b->f30 = func_02033BF8(tbl);
    if (c != 0) {
        b->f34 = c;
        b->f1d = 0;
    } else {
        b->f34 = (u32)func_02030734(heap, b->f08, 1, str_020A7848,
                                    0x131);
        b->f1d = 1;
    }
    b->f1c = 0;
    b->f28 = 0;
    b->f24 = 0;
    if (e == 1)
        func_020319C0((u8 *)b);
    else
        func_02033410((struct Obj02033410 *)b, 1);
    return b;
}



/*
 * backup_system.c.  A one-line forwarder: its two arguments go straight
 * through to 0x0203174C together with three zero/one flags, the fifth landing
 * on the stack.  The two zero arguments cost a single `mov r2, #0` plus the
 * `mov r3, r2` copy the compiler makes instead of a second move, and the `1`
 * is materialised into `ip` because an ARM `str` has no immediate form.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203192C.c \
 *       --func func_0203192C --addr 0x0203192C --cc 1.1p1 --arm
 */
u32 func_0203192C(void *a, void *b)
{
    return (u32)func_0203174C(a, (u32)b, 0, 0, 1);
}



asm void FSi_ConvertStringSjisToUnicode(void)
{
    stmfd sp!, {r3, lr}
    ldr ip, [sp, #8]
    str ip, [sp]
    bl func_0203174C
    ldmfd sp!, {r3, pc}
}



/*
 * A four-store teardown of one record: release the object at +0x2c, the one
 * at +0x138 unconditionally, the one at +0x34 only when the byte at +0x1d is
 * exactly 1, then the record itself.  The release callee is the overruled
 * SDK address 0x020307B0 (layout/symbols_sdk.txt calls it ENV_SetResourceSet,
 * the game code proves otherwise); it is already matched, which is what
 * attests the three PC24 sites.  0x020339B4, the +0x2c argument's own
 * destructor, was matched in the same wave and attests the fourth.
 *
 * The leaf follower at 0x02031994 (a two-field getter, no prologue) carries
 * no label, so the inferred extent from this address runs long: EXACT*.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203195C.c \
 *       --func func_0203195C --addr 0x0203195C --arm --cc 1.1p1
 */
void func_0203195C(u8 *p)
{
    func_020339B4((int *)(((struct Obj06929 *)p)->f2C));
    func_020307B0(((struct Obj06929 *)p)->f138);
    if (p[0x1d] == 1) {
        func_020307B0(((struct Obj06929 *)p)->f34);
    }
    func_020307B0(p);
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031994.c \\
 *       --func func_02031994 --addr 0x02031994 --arm --cc 1.1p1
 */
u32 func_02031994(u8 *p, u32 *out)
{
    *out = ((struct Obj11324 *)p)->f30;
    return ((struct Obj11324 *)p)->f34;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020319A4.c \\
 *       --func func_020319A4 --addr 0x020319A4 --arm --cc 1.1p1
 */
u32 func_020319A4(u8 *p, u32 id)
{
    return func_02033B68(*(u8 * *)&((struct Item020346D8 *)p)->f2C, id) + ((struct Item020346D8 *)p)->f34;
}



/*
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT*.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020319C0.c \\
 *       --func func_020319C0 --addr 0x020319C0 --arm --cc 1.1p1
 */
void func_020319C0(u8 *p)
{
    func_020339D0(((struct Obj02604 *)p)->f34, (struct T *)*(u32 *)&((struct Obj02604 *)p)->f2C);
    func_02033410((struct Obj02033410 *)p, 1);
}



void func_020319E4(void)
{
    func_020329AC();
}



/*
 * Erase the whole backup device in 0x1000-byte pages.  A 0x1000-byte scratch
 * page is allocated on the heap named by the u16 second argument (the
 * __FILE__ is "backup_system.c" at 0x020A7848 and the __LINE__ is 0x1e8),
 * filled with 0xff by func_02082A7C, and written over every page of the
 * device: the job's +8 word is the total length, its +0 word the destination
 * base, and the device handle comes from the +0x208 field of the object
 * behind the global at 0x02146994, re-read once per page along with the base.
 *
 * The literal 1 is materialised ONCE into r4 and reused as the second
 * argument of the first func_02033200 call
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md);
 * the second call's 2 is its own `mov`.  The 0x1000 page size is materialised
 * twice, once for the allocation and once into callee-saved r8 for the loop,
 * because the fill call in between clobbers it.
 *
 * The lengths compare unsigned (`bls`/`blo`), so a zero-length device skips
 * the loop entirely; the +4 word is a second length whose inequality with
 * +0 triggers an extra func_02033200(obj, 2) pass before the fill.
 *
 * Declaration order is one/off/page, which is what shares r4 between the
 * literal 1 and the loop cursor and leaves r5 for the scratch page
 * (docs/idioms/declaration-order-decides-which-register-a-local-gets.md);
 * page-first gives the exact same 240 bytes with r4 and r5 swapped, 12 out.
 * The heap id is a u32 parameter truncated at the call site, not a u16
 * parameter: the explicit `(u16)` is what produces the `lsl`/`lsr` pair at
 * +0x0008/+0x0018, and a u16 parameter folds it to a single `mov` for 236.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020319F0.c \
 *       --func func_020319F0 --addr 0x020319F0 --cc 1.1p1 --arm
 */
int func_020319F0(struct Job *job, u32 heap)
{
    u32 one;
    u32 off;
    void *page;

    page = func_02030734((u16)heap, 0x1000, 0, str_020A7848, 0x1e8);

    one = 1;
    func_02034F84(one);
    func_02033200((struct SaveBackup *)job, one);
    if (job->f00 != job->f04)
        func_02033200((struct SaveBackup *)job, 2);

    func_02082A7C(0xFFFFFFFF, page, 0x1000);

    for (off = 0; off < job->f08; off += 0x1000)
        func_020335AC(off + job->f00, (u32)page, 0x1000, g_02146994->unk208);

    func_020307B0(page);
    func_020319C0((u8 *)job);
    job->f1c = 0;
    func_02034FB8(1);
    return 1;
}



/*
 * Dispatch one step of the object's state machine: if the manager global's
 * front object is unarmed the call reports 4 immediately; otherwise the
 * object is either re-armed (its two queue cursors agree) or advanced, and
 * the call's status is dispatched through the dense switch that runs from
 * case 0 to case 4.  The armed transition stamps the progress byte at +0x1c.
 *
 * Two spellings were load-bearing in reaching EXACT, both worth keeping:
 *   - if/else polarity: the unequal arm is written first so it becomes the
 *     fall-through arm and the equal arm goes out of line at +0x40;
 *   - the case order 1, 2, 3, 0, 4: mwcc lays the arm bodies out in source
 *     order and the original's case-0 body sits after case 3's, at +0x90.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031AE0.c \
 *       --func func_02031AE0 --addr 0x02031AE0 --cc 1.1p1 --arm
 */
int func_02031AE0(struct State *o, u32 a1)
{
    u32 r;

    if (g_02146994->unk000 == 0)
        return 4;

    if (o->f00 != o->f04)
        r = func_02031FE0((struct Save *)o, a1, 0, 0);
    else
        r = func_02032688((struct Save *)o, 0, 0);

    switch (r) {
    case 1:
        o->f1c = 1;
        return 1;
    case 2:
        o->f1c = 1;
        return 2;
    case 3:
        return 3;
    case 0:
        return 0;
    case 4:
        return 4;
    }
    return 4;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031B8C.c \\
 *       --func func_02031B8C --addr 0x02031B8C --arm --cc 1.1p1
 */
void func_02031B8C(u8 *p)
{
    if (*(u32 *)(*(u32 *)0x02146994) != 0) {
        func_02032970((struct SaveBackup *)p, 1);
    }
}



/*
 * Blocked at MATCH on the `label`/`matched` classes: 75 of 76 bytes
 * reproduce and the only unresolved site is the PC24 at +0x24 to
 * func_02032CD0, whose single branch reference image-wide is this call, so
 * there is no witness outside 02031BB4..02031C04.  Filing 0x02032CD0 as an
 * EXACT manifest entry promotes this file with no change to the C.
 *
 * 0x02031BB4 is called from 0x02031B88 (the same packet's neighbour) and the
 * stack slot it hands func_02032CD0 is the pushed r3 scratch word, so the
 * local's address is taken but its value is never read here.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02031BB4.c \
 *       --func func_02031BB4 --addr 0x02031BB4 --cc 1.1p1 --arm
 */
int func_02031BB4(u32 a0)
{
    int r;
    u32 v;

    if (g_02146994->unk000 == 0)
        return 3;
    r = func_02032CD0((struct Save_02032CD0 *)a0, &v);
    if (r != 0 && r != 1)
        func_020331A4((struct SaveBackup *)a0, r, 1);
    return r;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031C04.c \\
 *       --func func_02031C04 --addr 0x02031C04 --arm --cc 1.1p1
 */
void func_02031C04(struct SaveBackup *a0)
{
    func_020331D0(a0);
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031C10.c \\
 *       --func func_02031C10 --addr 0x02031C10 --arm --cc 1.1p1
 */
void func_02031C10(u8 *a, u8 *b, u32 v)
{
    ((struct Obj08815 *)a)->f20 = v;
    a[0x1e] = 0;
    a[0x1f] = 2;
    b[0x1e] = 0;
    b[0x1f] = 2;
}



/*
 * Drive a two-copy save through func_02032CD0 (the write state machine),
 * one step per call, on the state byte at q+0x1E: open a generation on `p`
 * (sub_02032970), write `p`, copy its generation word to *q->f20 and open one
 * on `q`, write `q` (on failure also report it against `p` when p's two
 * area words differ), finish `p` if its two area words differ, then finish
 * `q`, answering 3 when p's result byte says so.  Both objects are the same
 * save-record type (both go to func_02032CD0 and func_020331A4).
 * Wave 11, 2026-09-23.
 *
 * The one lever the 2026-09-21 lanes named and did not reach: case 4 is
 * written with the UNEQUAL test first and the bare `q->f1e++` in the `else`
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).  That moves the
 * `state = s + 1` block out of line (0x02031D78) and lets case 1's
 * `state++; break;` share case 4's `b 0x02031C70`.  All four func_02032CD0
 * result tests are negated (`r != 0 && r != 1`), per the note.
 */
int func_02031C30(struct Obj *q, struct Obj *p)
{
    u32 tmp;
    int r;

    switch (q->f1e) {
    case 0:
        sub_02032970((struct SaveBackup *)p, 1);
        q->f1e++;
        break;
    case 1:
        r = func_02032CD0((struct Save_02032CD0 *)p, &tmp);
        if (r != 0 && r != 1) {
            func_020331A4((struct SaveBackup *)p, r, 1);
            if (r == 3)
                return 3;
            q->f1e++;
            break;
        }
        if (tmp == 1)
            q->f1e++;
        break;
    case 2:
        *q->f20 = p->f28;
        sub_02032970((struct SaveBackup *)q, 0);
        q->f1e++;
        break;
    case 3:
        r = func_02032CD0((struct Save_02032CD0 *)q, &tmp);
        if (r != 0 && r != 1) {
            func_020331A4((struct SaveBackup *)q, r, 1);
            if (p->f00 != p->f04)
                func_020331A4((struct SaveBackup *)p, r, 1);
            return 3;
        }
        if (tmp == 1)
            q->f1e++;
        break;
    case 4:
        if (p->f00 != p->f04) {
            r = func_02032CD0((struct Save_02032CD0 *)p, &tmp);
            if (r != 0 && r != 1) {
                func_020331A4((struct SaveBackup *)p, r, 0);
                p->f1f = r;
                q->f1e++;
            }
        } else {
            q->f1e++;
        }
        break;
    case 5:
        r = func_02032CD0((struct Save_02032CD0 *)q, &tmp);
        if (r != 0 && r != 1) {
            func_020331A4((struct SaveBackup *)q, r, 1);
            if (p->f1f == 3)
                r = 3;
            return r;
        }
        break;
    }
    return 0;
}



/*
 * Drive one step of the object's state machine.  The engine pointer is read
 * through the global at 0x02146994 twice (`ldr ip,[pc]; ldr ip,[ip]; cmp`),
 * so the declaration is a `u32 *` and a null engine reports 4 without
 * touching anything.  The object's +0x00 and +0x04 words then pick which of
 * the two engine entry points runs - different words take func_02031FE0 with
 * the object, the first argument, a hard 1 and the third argument, equal
 * words take func_02032688 - and that call's status picks the arm: 1 and 2
 * also set the +0x1C byte, 0/3/4 report themselves and anything above 4
 * reports 4.
 *
 * The case labels are NOT in numeric order in the source.  Written
 * `case 0: return 0; case 1: ... case 2: ... case 3: return 3; case 4:
 * return 4;` the five arms come out in the table's own order and the
 * function is 8 bytes of DIFF (every arm's body is 8 bytes early, case 0's
 * body lands first instead of just before case 4's).  mwccarm emits the
 * bodies in the order the labels are written, so the source order here is
 * 1, 2, 3, 0, 4 - which is what reproduces the listing: the table's entry 0
 * branches past the three arms to 0x02031E4C.
 *
 * EXACT* rather than EXACT: the byte comparison passes at all 168 bytes (164
 * of code plus the pool word for 0x02146994) and all three sites resolve,
 * but the listing's next label is beyond 0x02031E68, where the follower at
 * 0x02031E68 (`ldr r0,[r0,#0x144]; bx lr`) has no func_ entry point, so the
 * inferred extent runs long.  Report the unlabelled follower rather than
 * edit layout/function_starts.txt.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031DC0.c \
 *       --func func_02031DC0 --addr 0x02031DC0 --cc 1.1p1 --arm
 */
int func_02031DC0(Obj02031DC0 *a0, u32 a1, u32 a2)
{
    int st;

    if (g_02146994->unk000 == 0)
        return 4;
    if (a0->f00 != a0->f04)
        st = func_02031FE0((struct Save *)a0, a1, 1, a2);
    else
        st = func_02032688((struct Save *)a0, 1, a2);
    switch (st) {
    case 1:
        a0->f1c = 1;
        return 1;
    case 2:
        a0->f1c = 1;
        return 2;
    case 3:
        return 3;
    case 0:
        return 0;
    case 4:
        return 4;
    }
    return 4;
}



int func_02031E68(const char *ptr)
{
    return *(const int *)&((struct Obj15878 *)ptr)->f144;
}



void * func_02031E70(void)
{
    return func_020338F8();
}


/*
 * backup_system.c.  The CRC-16/CCITT of one backup record: the table is the
 * CRC table that lives inline at +4 of the object at 0x02146994 (the same
 * `struct { u8 pad000[4]; u8 crcTable[1]; }` shape src/matched/sub_020332A4.c
 * uses), the data starts at `buf + p->unk30 - 0x10 - p->unk140` and runs for
 * p->unk140 bytes.  The result is what src/matched/func_02031EF8.c compares
 * against the footer halfword and what src/matched/func_02031F54.c stores
 * into it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031E7C.c \
 *       --func func_02031E7C --addr 0x02031E7C --cc 1.1p1 --arm
 */
u16 func_02031E7C(struct SaveBackup *p, u8 *buf)
{
    return MATH_CalcCRC16CCITT(g_02146994->crcTable,
                               buf + (p->unk30 - 0x10 - p->unk140),
                               p->unk140);
}


/*
 * backup_system.c.  The length accessor of the backup header: it reports the
 * length word at +4, but only when the sequence word at +0 differs from it;
 * when the two agree the length at +0 is returned instead.  `sel` chooses the
 * copy: only sel == 2 gets the +4 length, everything else gets 0.  Callers
 * feed the answer straight to a read, e.g. src/pending/sub_02031FE0.c:
 * `func_020335E8(func_02031EAC(p, 1), buf0, p->unk30, ...)`.
 *
 * Both loads happen in source order (+4 first), and the equal case returns the
 * halfword already in r0, so the tail is a bare `bxeq lr`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031EAC.c \
 *       --func func_02031EAC --addr 0x02031EAC --cc 1.1p1 --arm
 */
u32 func_02031EAC(u32 *p, u32 sel)
{
    u32 len;

    len = p[1];
    if (p[0] == len)
        return p[0];
    if (sel != 2)
        len = p[0];
    return len;
}


int func_02031ECC(int p0){ return (*(int *)&((struct Item020346D8 *)p0)->f34 + ((*(int *)&((struct Item020346D8 *)p0)->f30 - 0x10) - *(int *)&((struct Item020346D8 *)p0)->f140)); }


int func_02031EE8(int p0, int p1){ return (p1 + (((struct Obj15879 *)p0)->f30 - 0x10)); }


/*
 * backup_system.c.  Verifies one copy of a backup area and returns 0 when both
 * words of its footer agree with the descriptor, 1 when the running check
 * disagrees, 2 when the length or the sequence number disagrees.
 *
 * The footer descriptor comes from func_02031EE8(p, buf) (src/matched/
 * func_02031EE8.c): it is `buf + p->unk30 - 0x10`.  Word +4 and word +8 of that
 * footer are compared against p->unk30 and p->unkC, and the halfword at +0xE is
 * compared against func_02031E7C(p, buf), the CRC16 of the area (the packet's
 * only SDK call).  Only 0x02031F9C calls this function anywhere in the image,
 * which is why that file was parked at MATCH until this one landed; it can now
 * be promoted.
 *
 * The third parameter is dead in the body (the original never reads r2) and the
 * callers pass nothing for it; it is kept in the declaration only because
 * src/matched/sub_02031F9C.c declares the same three-argument prototype.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031EF8.c \
 *       --func func_02031EF8 --addr 0x02031EF8 --cc 1.1p1 --arm
 */
u32 func_02031EF8(void *p, void *buf, u32 sel)
{
    u8 *q;

    q = (u8 *)func_02031EE8((int)p, (int)buf);

    if (((struct Obj08816 *)q)->f4 != ((struct Obj03443 *)p)->f30)
        return 2;
    if (((struct Obj08816 *)q)->f8 != ((struct Obj03443 *)p)->fC)
        return 2;
    if (((struct Obj08816 *)q)->fE != func_02031E7C(p, buf))
        return 1;
    return 0;
}


/*
 * backup_system.c.  Writes the footer descriptor that func_02031EF8 verifies,
 * at func_02031EE8(p, buf) (buf + p->unk30 - 0x10): generation p->unk28,
 * size p->unk30, id p->unk0C, then the CRC-16/CCITT from func_02031E7C at
 * +0x0E.  Closed wave 12: the record pointer is `const`.  With a non-const
 * pointer every field load stays below the previous footer store (the
 * compiler must assume they alias) and six instructions come out in the
 * wrong order; with const the loads float above the stores exactly as the
 * image has them (docs/idioms/const-pointer-lets-a-field-load-survive-a-
 * store.md).  dsi/1.1p1 only; ../2.0/sp2 keeps the 16-byte residue.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02031F54.c \
 *       --func func_02031F54 --addr 0x02031F54 --arm
 */
void func_02031F54(const struct SaveBackup *p, u8 *buf)
{
    struct Footer *q = (struct Footer *)func_02031EE8((int)p, (int)buf);
    q->gen = p->unk28;
    q->size = p->unk30;
    q->id = p->unk0C;
    q->crc = func_02031E7C((struct SaveBackup *)p, buf);
}


void func_02031F94(int *p, int v){ p[10] = v; }


/*
 * PROMOTED TO EXACT.  This file was parked at MATCH because its only open
 * relocation site was the `bl` to 0x02031EF8: that function's one and only
 * branch in the whole image is the one inside this file
 * (match.image_call_sites(0x02031EF8) == [0x02031FCC]), so the `label` class
 * had no outside witness and there was no literal or runtime witness either.
 * 0x02031EF8 is now matched itself (src/matched/func_02031EF8.c), so the site
 * resolves in the `matched` class and every byte here is attested.
 *
 * backup_system.c.  Fills the two-word record descriptor `out` for one of the
 * two copies of a backup area: word 0 is the verification answer from
 * 0x02031EF8 (0 both words of the footer agree, 1 the running check disagrees,
 * 2 the length or the sequence number disagrees), word 1 is the first word of
 * that footer, reached through 0x02031EE8, buf + (p->unk30 - 0x10).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02031F9C.c \
 *       --func func_02031F9C --addr 0x02031F9C --cc 1.1p1 --arm
 */
void func_02031F9C(u32 *out, void *p, void *buf, u32 sel)
{
    u8 *q;

    q = (u8 *)func_02031EE8((int)p, (int)buf);
    out[0] = func_02031EF8(p, buf, sel);
    out[1] = ((struct Obj16793 *)q)->f0;
}


static inline u16 cnt16(u8 *p){ return ((struct Obj15881 *)p)->f0; }


/*
 * backup_system.c.  The two-copy load: read both copies of the save area
 * (func_020335E8 at func_02031EAC(self, 1) into the staging buffer self->f34
 * and at (self, 2) into a heap block from func_02030734, line 0x429), repair
 * one copy from the other when only one read failed, check both footers
 * (func_02031F9C, the mode == 1 generation test), cross-copy the footer block
 * when exactly one is bad, pick the newer good copy, then walk every record
 * checking its CRC against both copies, marking each record 0/1/2 through
 * func_0203331C and retrying with the other copy if the walk breaks.  A
 * completed walk copies the marked records back and commits the generation
 * (func_02031F94).  The two-copy twin of func_02032688
 * (docs/notes/pkt_02031FE0.c.txt holds the history from wave 11).
 *
 * Closed wave 19 by `unsigned long AB` together with the declaration order
 * AB, pa, pb, i, A, B: the long-typed A + B colours apart from the u32
 * locals (image: AB r4, B r8, A r7).  Either change alone is 13 or 22 bytes
 * out; the earlier 9-byte residue was this one register swap.  The inline
 * cnt16 on the two record-counter compares and the one-argument
 * func_020333F8 are load-bearing (wave 12); func_02030734 uses its real
 * prototype with an explicit (u16) heap.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02031FE0.c \
 *       --func func_02031FE0 --addr 0x02031FE0 --arm
 */
int func_02031FE0(Save *self, u32 heap, u32 mode, u32 gen)
{
    u32 pairB[2];
    u32 pairA[2];
    u8 *bufs[2];
    u32 gens[2];
    u32 ids[2];
    u8 *h;
    u16 *tbl;
    u8 *cur;
    u32 k;
    u8 *buf;
    int okA;
    int okB;
    unsigned long AB;
    u8 *pa;
    u8 *pb;
    u32 i;
    u32 A;
    u32 B;
    u32 off;

    func_020333F8(self);
    h = self->f34;
    buf = func_02030734((u16)heap, self->f30, 0, str_020A7848, 0x429);
    okA = func_020335E8(func_02031EAC((u32 *)self, 1), (u32)h, self->f30, (void (*)(void))g_02146994->unk204);
    okB = func_020335E8(func_02031EAC((u32 *)self, 2), (u32)buf, self->f30, (void (*)(void))g_02146994->unk204);
    if (okA == 0 && okB == 0) {
        func_02033410((struct Obj02033410 *)self, 1);
        func_02082A7C(0, h, self->f30);
        func_020307B0(buf);
        return 0;
    }
    if (okA == 1 && okB == 0) {
        func_02033410((struct Obj02033410 *)self, 2);
        func_02082A60(h, buf, self->f30);
    } else if (okA == 0 && okB == 1) {
        func_02033410((struct Obj02033410 *)self, 1);
        func_02082A60(buf, h, self->f30);
    }

    func_02031F9C(pairA, self, h, 0);
    func_02031F9C(pairB, self, buf, 1);
    if (mode == 1) {
        if (pairA[1] != gen)
            pairA[0] = 2;
        if (pairB[1] != gen)
            pairB[0] = 2;
    }

    if (pairA[0] == 0) {
        if (pairB[0] != 0) {
        func_0203331C((struct Obj020332FC *)self, func_02033BF0((struct Obj02033BF0 *)self->f2c), 2);
        func_0203331C((struct Obj020332FC *)self, func_02033BF0((struct Obj02033BF0 *)self->f2c) + 1, 2);
        off = self->f30 - 0x10 - self->f140;
        func_02082A60(h + off, buf + off, self->f140 + 0x10);
        }
    } else if (pairB[0] == 0) {
        if (pairA[0] != 0) {
        func_0203331C((struct Obj020332FC *)self, func_02033BF0((struct Obj02033BF0 *)self->f2c), 1);
        func_0203331C((struct Obj020332FC *)self, func_02033BF0((struct Obj02033BF0 *)self->f2c) + 1, 1);
        off = self->f30 - 0x10 - self->f140;
        func_02082A60(buf + off, h + off, self->f140 + 0x10);
        }
    } else {
        if (pairA[0] == 1 || pairB[0] == 1) {
            func_02033410((struct Obj02033410 *)self, 1);
            func_020307B0(buf);
            return 3;
        }
        func_02033410((struct Obj02033410 *)self, 1);
        func_020307B0(buf);
        return 0;
    }

    if (pairA[0] == 0
        && ((pairA[1] == 0 && pairB[1] == 0xFFFFFFFF) || pairA[1] >= pairB[1]
            || pairB[0] != 0)) {
        bufs[0] = h;
        bufs[1] = buf;
        ids[0] = 1;
        ids[1] = 2;
        gens[0] = pairA[1];
        gens[1] = pairB[1];
    } else {
        ids[0] = 2;
        bufs[0] = buf;
        bufs[1] = h;
        ids[1] = 1;
        gens[0] = pairB[1];
        gens[1] = pairA[1];
    }

    for (k = 0; k < 2; k++) {
        off = self->f30 - 0x10 - self->f140;
        cur = bufs[k];
        tbl = (u16 *)(bufs[k] + off);
        for (i = 0; i < func_02033BF0((struct Obj02033BF0 *)self->f2c); i++) {
            A = func_02033B68(self->f2c, i);
            B = func_02033BAC(self->f2c, i);
            AB = A + B;
            pa = h + AB;
            pb = buf + AB;
            func_0203331C((struct Obj020332FC *)self, i, 0);
            if (((struct Obj08817 *)pa)->f2 != tbl[i]
                && ((struct Obj08818 *)pb)->f2 != tbl[i])
                break;
            if (((struct Obj08817 *)pa)->f2 == tbl[i]) {
                if (((struct Obj08817 *)pa)->f2 != func_02081B8C((struct MATHCRC16Table *)g_02146994->crcTable, h + A, B))
                    func_0203331C((struct Obj020332FC *)self, i, 1);
            } else {
                func_0203331C((struct Obj020332FC *)self, i, 1);
            }
            if (((struct Obj08818 *)pb)->f2 == tbl[i]) {
                if (((struct Obj08818 *)pb)->f2 != func_02081B8C((struct MATHCRC16Table *)g_02146994->crcTable, buf + A, B)) {
                    if (func_020332FC((struct Obj020332FC *)self, i) == 1)
                        break;
                    func_0203331C((struct Obj020332FC *)self, i, 2);
                }
            } else {
                if (func_020332FC((struct Obj020332FC *)self, i) == 1)
                    break;
                func_0203331C((struct Obj020332FC *)self, i, 2);
            }
            if (func_020332FC((struct Obj020332FC *)self, i) == 0) {
                if (cnt16(pa) != *(u16 *)(bufs[k] + AB))
                    func_0203331C((struct Obj020332FC *)self, i, 1);
                if (cnt16(pb) != *(u16 *)(bufs[k] + AB)) {
                    if (func_020332FC((struct Obj020332FC *)self, i) == 1)
                        break;
                    func_0203331C((struct Obj020332FC *)self, i, 2);
                }
            }
        }
        if (i >= func_02033BF0((struct Obj02033BF0 *)self->f2c)) {
            u32 id = ids[k ^ 1];

            func_0203331C((struct Obj020332FC *)self, func_02033BF0((struct Obj02033BF0 *)self->f2c) + 1, id);
            func_0203331C((struct Obj020332FC *)self, func_02033BF0((struct Obj02033BF0 *)self->f2c), id);
            break;
        }
    }
    if (k >= 2) {
        func_02033410((struct Obj02033410 *)self, 1);
        func_020307B0(buf);
        return 3;
    }

    off = self->f30 - 0x10 - self->f140;
    func_02082A60(bufs[k] + off, h + off, self->f140 + 0x10);
    for (i = 0; i < func_02033BF0((struct Obj02033BF0 *)self->f2c); i++) {
        if (func_020332FC((struct Obj020332FC *)self, i) == 1) {
            A = func_02033B68(self->f2c, i);
            B = func_02033BAC(self->f2c, i);
            func_02082A60(buf + A, h + A, B + 4);
        }
    }
    func_02031F94((int *)self, gens[k]);
    func_020307B0(buf);
    for (i = 0; i < func_02033BF0((struct Obj02033BF0 *)self->f2c); i++)
        func_020332FC((struct Obj020332FC *)self, i);
    return 1;
}


/*
 * backup_system.c.  The one-copy load: read copy 1 of the save area into the
 * staging buffer self->f34 (func_020335E8 at func_02031EAC(self, 1)); on a
 * read failure clear the marks (func_02033410(self, 1)), zero the buffer and
 * answer 0.  Otherwise check the footer (func_02031F9C; with mode == 1 a
 * generation other than arg3 counts as bad), answer 3 or 0 for a bad footer,
 * then walk every record checking its stored CRC against the footer's CRC
 * table and recomputing it (func_02081B8C over g_02146994's inline table),
 * marking each record 0, or 1 on a recompute mismatch.  A completed walk marks
 * the two trailing slots 1 and commits the footer's generation
 * (func_02031F94); a broken one answers 3.  The one-copy twin of
 * func_02031FE0 (docs/notes/pkt_02031FE0.c.txt holds the history).
 *
 * Closed wave 12 by the callee's real argument list: func_020333F8 takes
 * self ONLY (src/matched/func_020333F8.c forwards self->+0x138/+0x13C to a
 * clear and never reads its other parameters).  Passing (self, mode, arg3)
 * as every earlier draft did left four instructions of the first read's
 * argument setup in the wrong order (10 bytes).  The redundant re-test
 * `if (crc == base[i])` after the `!= ... goto done` is in the image (a dead
 * second compare), and `u8 *h` first / `u32 i` last in the declarations set
 * the loop's registers.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02032688.c \
 *       --func func_02032688 --addr 0x02032688 --arm
 */
int func_02032688(Save *self, int mode, int arg3)
{
    u32 pair[2];
    u8 *h;
    u32 j, A, B;
    int saved;
    u8 *base;
    u8 *gp;
    u32 i;

    func_020333F8(self);
    h = self->f34;
    if (func_020335E8(func_02031EAC((u32 *)self, 1), (u32)h, self->f30,
                      (void (*)(void))g_02146994->unk204) == 0) {
        func_02033410((struct Obj02033410 *)self, 1);
        func_02082A7C(0, h, self->f30);
        return 0;
    }
    func_02031F9C(pair, self, h, 0);
    if (mode == 1) {
        if ((s32)pair[1] != arg3)
            pair[0] = 2;
    }
    if (pair[0] != 0) {
        if (pair[0] == 1) {
            func_02033410((struct Obj02033410 *)self, 1);
            return 3;
        }
        func_02033410((struct Obj02033410 *)self, 1);
        return 0;
    }

    base = h + (self->f30 - 0x10 - self->f140);
    saved = (s32)pair[1];
    for (i = 0; i < func_02033BF0((struct Obj02033BF0 *)self->f2c); i++) {
        A = func_02033B68(self->f2c, i);
        B = func_02033BAC(self->f2c, i);
        gp = h + (A + B);
        func_0203331C((struct Obj020332FC *)self, i, 0);
        if (((struct Obj08819 *)gp)->f2 != *(u16 *)(base + i * 2))
            goto done;
        if (((struct Obj08819 *)gp)->f2 == *(u16 *)(base + i * 2)) {
            if (((struct Obj08819 *)gp)->f2 != func_02081B8C((struct MATHCRC16Table *)g_02146994->crcTable, h + A, B)) {
                func_0203331C((struct Obj020332FC *)self, i, 1);
                goto done;
            }
        }
    }
done:
    if (i >= func_02033BF0((struct Obj02033BF0 *)self->f2c)) {
        func_0203331C((struct Obj020332FC *)self, func_02033BF0((struct Obj02033BF0 *)self->f2c) + 1, 1);
        func_0203331C((struct Obj020332FC *)self, func_02033BF0((struct Obj02033BF0 *)self->f2c), 1);
    } else {
        func_02033410((struct Obj02033410 *)self, 1);
        return 3;
    }
    func_02031F94((int *)self, saved);
    for (j = 0; j < func_02033BF0((struct Obj02033BF0 *)self->f2c); j++)
        func_020332FC((struct Obj020332FC *)self, j);
    return 1;
}


/*
 * PARKED AT MATCH.  Every concrete byte is right.  The one open site is the
 * `bl` to 0x02031F54: the image holds exactly one branch to that address,
 * the one inside this function, so the `label` class has no outside witness
 * and no split can make one.  It closes the day a second caller turns up or
 * 0x02031F54 itself is matched.
 *
 * savedata.c.  Writes the sixteen byte footer of a backup record: the
 * destination is the last sixteen bytes of the area that starts at +0x30
 * and runs for the length 0x02031EAC reports, the source is the matching
 * sixteen bytes of the staging buffer at +0x34, and the fourth argument is
 * the handle the global at 0x02146994 keeps at +0x208.  The call to
 * 0x02031F54 in between is made for its effect only; its result is dropped.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_020328E0.c  *       --func sub_020328E0 --addr 0x020328E0 --cc 1.1p1 --arm
 */
int sub_020328E0(struct SaveBackup *p, u32 sel)
{
    u32 dst;
    u32 area;
    u32 buf;

    area = p->unk30;
    dst = area + func_02031EAC((u32 *)p, sel) - 0x10;
    buf = p->unk34;
    func_02031F54(p, (u8 *)buf);
    return func_020336B8(dst, buf + (area - 0x10), 0xF, (void *)g_02146994->unk208);
}


/*
 * savedata.c.  The one byte twin of sub_020328E0: same area and staging
 * buffer, but it rewrites only the single trailing byte of the record.
 * Unlike sub_020328E0 it does not touch 0x02031F54 first, so nothing has to
 * survive the call and the function gets away with three saved registers.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02032930.c  *       --func sub_02032930 --addr 0x02032930 --cc 1.1p1 --arm
 */
int sub_02032930(struct SaveBackup *p, u32 sel)
{
    u32 area = p->unk30;
    u32 end = area + func_02031EAC((u32 *)p, sel);

    return func_020336B8(end - 1, p->unk34 + (area - 1), 1, (void *)g_02146994->unk208);
}


/*
 * savedata.c.  Opens a new backup generation: clears the two status bytes
 * and the two counters, remembers the generation the write is going to
 * carry in +0x10 and bumps the running generation in +0x28, then, when the
 * caller asked for it, raises the "busy" flag through the setter veneer at
 * 0x02034F84.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02032970.c  *       --func sub_02032970 --addr 0x02032970 --cc 1.1p1 --arm
 */
void sub_02032970(struct SaveBackup *p, u32 flag)
{
    u32 gen;

    p->unk18 = 0;
    p->unk14 = 0;
    p->unk19 = 0;
    gen = p->unk28;
    p->unk28 = gen + 1;
    p->unk144 = 0;
    p->unk10 = gen;

    if (flag == 1) {
        func_02034F84(1);
    }
}


/*
 * savedata.c.  Walks every record of the save table and reports two running
 * totals through the caller's two out-parameters: the nominal size of every
 * record, and the size actually accounted for.  A record 0x020332FC says is
 * not resident is pumped through the seven-argument step function at
 * 0x02032A9C until it stops answering 0, and a step that answers 2 drops
 * that record's contribution to the second total to zero.
 *
 * The four scratch cells the step function writes through are stack locals
 * whose addresses are taken, which is why the frame is 0x24 bytes with the
 * first three outgoing stack arguments at the bottom; per
 * docs/idioms/local-declaration-order-is-stack-order.md the first declared
 * of the four sits highest, at sp+0x20, and the fourth at sp+0x14, matching
 * the order they are passed in.  The fourth is deliberately not initialised:
 * the original zeroes only three of the four.
 *
 * The outer loop is a do/while, not a for: the bound is recomputed by a call
 * at the bottom of every iteration and the compiler has no way to rotate an
 * unknown bound, so the test really is written after the body.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020329AC.c \
 *       --func sub_020329AC --addr 0x020329AC --cc 1.1p1 --arm
 */
void sub_020329AC(struct SaveBackup *p, u32 *total, u32 *nominal)
{
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u32 size;
    u32 i;
    u32 r;

    i = 0;
    func_02034F84(1);

    *total = 0;
    *nominal = 0;
    a = 0;
    b = 0;
    c = 0;

    do {
        size = func_02033BAC((u8 *)p->unk2C, i);
        *nominal = *nominal + size;

        if (func_020332FC((struct Obj020332FC *)p, i) == 0) {
            do {
                r = func_02032A9C(p, i, 1, &a, &b, &c, &d);
                if (r == 2) {
                    size = 0;
                }
            } while (r == 0);
        }

        *total = *total + size;
        i++;
    } while (i < func_02033BF0((struct Obj02033BF0 *)p->unk2C));

    func_02034FB8(1);
}


/*
 * savedata.c.  One resumable step of a record copy: read the record out of
 * Flash into the 0x38 scratch area 0x100 bytes at a time and hand each
 * chunk to 0x0203EFC8, stopping either when the record is exhausted (answer
 * 2) or when the running byte budget in *pb crosses 0x800 (answer 0, with
 * the remaining length and the progress written back through *pa and *pc so
 * the caller can call again).  A read or write failure answers 1.
 *
 * The seven arguments mean the last three arrive on the stack; the compiler
 * keeps the sixth in its own incoming slot and reloads it, which is why
 * there is a `ldr r2, [sp, #0x2c]` / `str r2, [sp, #0x2c]` pair that looks
 * like a no-op in the prologue.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02032A9C.c \
 *       --func sub_02032A9C --addr 0x02032A9C --cc 1.1p1 --arm
 */
u32 sub_02032A9C(struct SaveBackup *p, u32 id, u32 mode, u32 *pa, u32 *pb,
                 u32 *pc, u32 *pd)
{
    u32 off;
    u32 rem;
    u32 chunk;
    u32 done;
    u8 *src;
    u32 acc;

    off = func_02031EAC((u32 *)p, mode);
    off = off + func_02033B68((u8 *)p->unk2C, id);

    rem = *pa;
    if (rem != 0) {
        done = *pc;
        off = off + done;
    } else {
        rem = func_02033BAC((u8 *)p->unk2C, id);
        done = 0;
    }

    src = (u8 *)func_020319A4((u8 *)p, id);

    *pa = 0;
    *pc = 0;
    *pd = 0;

    do {
        if (rem > 0x100) {
            chunk = 0x100;
            rem = rem - 0x100;
        } else {
            chunk = rem;
            rem = 0;
        }

        acc = *pb + chunk;
        *pb = acc;
        if (acc > 0x800) {
            *pd = 1;
            *pb = 0;
        }

        if (func_020335E8(off, (u32)p->unk38, chunk, (void (*)(void))g_02146994->unk204) == 0) {
            return 1;
        }

        if (func_0203EFC8(p->unk38, src + done, chunk) != 0) {
            return 1;
        }

        done = done + chunk;
        off = off + chunk;

        if (*pd == 1) {
            if (rem == 0) {
                return 2;
            }
            *pa = rem;
            *pc = done;
            return 0;
        }
    } while (rem != 0);

    return 2;
}


/*
 * savedata.c.  Commits one record of a backup generation: refresh the
 * record's CRC through sub_020332A4 (src/matched/sub_020332A4.c) and file
 * it in the halfword table 0x02031ECC owns, then write the record itself,
 * four bytes longer than its payload, to the Flash offset that 0x02031EAC
 * and 0x02033B68 name between them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02032BF8.c \
 *       --func sub_02032BF8 --addr 0x02032BF8 --cc 1.1p1 --arm
 */
u16 sub_02032BF8(struct SaveBackup *p, u32 id, u32 x, u32 unused)
{
    u16 *tbl;
    u32 base;
    u32 off;
    u32 len;
    u32 src;

    tbl = (u16 *)func_02031ECC((int)p);
    tbl[id] = func_020332A4(p, id);
    base = func_02031EAC((u32 *)p, x);
    off = func_02033B68((u8 *)p->unk2C, id);
    len = func_02033BAC((u8 *)p->unk2C, id);
    src = func_020319A4((u8 *)p, id);
    func_020336B8(base + off, src, len + 4, (void *)g_02146994->unk208);
}


/*
 * savedata.c.  Writes the trailing block of a backup record: the length is
 * the +0x140 field, the destination is that many bytes back from the end
 * of the area, and the source is whatever 0x02031ECC hands back.  The
 * destination has to be computed before the 0x02031ECC call so that the
 * register holding `p` can be reused for it, which is what keeps the frame
 * down to three saved registers.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02032C84.c \n *       --func sub_02032C84 --addr 0x02032C84 --cc 1.1p1 --arm
 */
int sub_02032C84(struct SaveBackup *p, u32 sel)
{
    u32 dst;
    u32 src;

    dst = p->unk30 + func_02031EAC((u32 *)p, sel);
    dst = dst - 0x10 - p->unk140;
    src = func_02031ECC((int)p);
    return func_020336B8(dst, src, p->unk140, (void *)g_02146994->unk208);
}


/*
 * The backup_system.c save-write state machine, one step per call, on the
 * state byte at +0x18 (docs/families/backup_system.h's unk18).  States:
 *   0-1   pump every not-yet-resident record through sub_02032A9C (the
 *         resumable Flash copy; `done` is its yield flag), refreshing each
 *         record's counter with sub_02033264; a 0 answer without the yield
 *         flag raises the backup_system.c line 0x72A assertion
 *   2-4   for every marked record, start its write (sub_02032BF8) and poll
 *         it (func_020337B8 on the handle kept at g_02146994+0x20C), summing
 *         the written sizes into +0x144
 *   5-6   the trailing block (sub_02032C84), 7-8 the footer (sub_020328E0,
 *         returns 1 when committed), 9-10 the footer's last byte
 *         (sub_02032930); state 10 then either restarts at state 2 for the
 *         second copy (sub_0203335C swaps the 1/2 marks, *out = 1) or
 *         finishes (func_020333F8) and answers 2
 *   11    answers 2
 * A failed poll answers 3, or 2 once the first copy has been written (+0x19).
 * Wave 11, 2026-09-23 -- first transcription, EXACT after one declaration
 * swap (`st` before `done`: later declaration, lower address).  The constants
 * 0/1/2/3 live in callee-saved registers across the whole switch, which is
 * dsi/1.1p1's own habit (../2.0/sp2 is 957 bytes out).
 */
int func_02032CD0(Save_02032CD0 *p, u32 *out)
{
    u32 st;
    u32 done;
    u32 v;
    u32 r;

    *out = 0;
    switch (p->f18) {
    case 0:
        p->f148 = 0;
        p->f14c = 0;
        p->f150 = 0;
        p->f18++;
    case 1:
        done = 0;
        do {
            if (done == 1)
                return 0;
            if (func_020332FC((struct Obj020332FC *)p, p->f14) == 0) {
                r = sub_02032A9C((struct SaveBackup *)p, p->f14, 1, &p->f148, &p->f14c, &p->f150, &done);
                if (r == 1) {
                    func_0203331C((struct Obj020332FC *)p, p->f14, 1);
                } else if (r == 0) {
                    if (done != 1)
                        func_02034714(str_020A7848, 0x72A, str_020A7888);
                    return 0;
                } else {
                    goto next;
                }
            }
            sub_02033264((struct SaveBackup *)p, p->f14);
        next:
            p->f14++;
        } while (p->f14 < func_02033BF0((struct Obj02033BF0 *)p->f2c));
        p->f18++;
        break;
    case 2:
        p->f14 = 0;
        p->f18++;
    case 3:
        for (; p->f14 < func_02033BF0((struct Obj02033BF0 *)p->f2c); p->f14++) {
            v = func_020332FC((struct Obj020332FC *)p, p->f14);
            if (v != 0) {
                g_02146994->unk20C = sub_02032BF8((struct SaveBackup *)p, p->f14, v, p->f19);
                p->f18++;
                break;
            }
        }
        if (p->f14 >= func_02033BF0((struct Obj02033BF0 *)p->f2c)) {
            p->f14 = 0;
            p->f18 = 5;
        }
        break;
    case 4:
        if (func_020337B8(g_02146994->unk20C, &st, g_02146994->unk208) == 0)
            break;
        if (st == 0)
            return p->f19 == 0 ? 3 : 2;
        p->f144 += func_02033BAC(p->f2c, p->f14);
        p->f14++;
        p->f18 = 3;
        break;
    case 5:
        v = func_020332FC((struct Obj020332FC *)p, func_02033BF0((struct Obj02033BF0 *)p->f2c));
        if (v == 0) {
            v = 1;
            func_0203331C((struct Obj020332FC *)p, func_02033BF0((struct Obj02033BF0 *)p->f2c), v);
        }
        g_02146994->unk20C = sub_02032C84((struct SaveBackup *)p, v);
        p->f18++;
    case 6:
        if (func_020337B8(g_02146994->unk20C, &st, g_02146994->unk208) == 0)
            break;
        if (st == 0)
            return p->f19 == 0 ? 3 : 2;
        p->f18++;
        break;
    case 7:
        v = func_020332FC((struct Obj020332FC *)p, func_02033BF0((struct Obj02033BF0 *)p->f2c) + 1);
        if (v == 0) {
            v = 1;
            func_0203331C((struct Obj020332FC *)p, func_02033BF0((struct Obj02033BF0 *)p->f2c) + 1, v);
        }
        g_02146994->unk20C = sub_020328E0((struct SaveBackup *)p, v);
        p->f18++;
    case 8:
        if (func_020337B8(g_02146994->unk20C, &st, g_02146994->unk208) == 0)
            break;
        if (st == 0)
            return p->f19 == 0 ? 3 : 2;
        p->f18++;
        return 1;
    case 9:
        g_02146994->unk20C = sub_02032930((struct SaveBackup *)p, func_020332FC((struct Obj020332FC *)p, func_02033BF0((struct Obj02033BF0 *)p->f2c) + 1));
        p->f18++;
    case 10:
        if (func_020337B8(g_02146994->unk20C, &st, g_02146994->unk208) == 0)
            break;
        if (st == 0)
            return p->f19 == 0 ? 3 : 2;
        if (++p->f19 == 1 && p->f00 != p->f04) {
            sub_0203335C((struct Obj0203335C *)p);
            p->f18 = 2;
            *out = 1;
            return 0;
        }
        func_020333F8((Save *)p);
        p->f18++;
        return 2;
    case 11:
        return 2;
    }
    return 0;
}


/*
 * savedata.c.  The completion callback of a backup write: on result 3 the
 * generation counter is rolled back to the one the write carried, on any
 * other result the failure byte at +0x1C is raised instead, and either way
 * the "busy" flag is dropped through the veneer at 0x02034FB8 when the
 * caller asked for it.  The two arms share one epilogue, which is why they
 * are written as an if/else over predicated stores rather than two
 * statements.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020331A4.c  *       --func sub_020331A4 --addr 0x020331A4 --cc 1.1p1 --arm
 */
void sub_020331A4(struct SaveBackup *p, u32 result, u32 flag)
{
    if (result == 3) {
        p->unk28 = p->unk10;
    } else {
        p->unk1C = 1;
    }

    if (flag == 1) {
        func_02034FB8(1);
    }
}


/*
 * PARKED AT MATCH.  Every concrete byte is right.  The one open site is the
 * `bl` to 0x0203386C, which has exactly one caller image-wide, this one, so
 * `label` has nothing outside the range to point at.
 *
 * savedata.c.  The same completion path as sub_020331A4 but for the
 * unconditional case: roll the generation back, hand the halfword at
 * +0x20C of the object the global at 0x02146994 points at to 0x0203386C,
 * and drop the busy flag.
 *
 * The `add r0, r0, #0x200` before the `ldrh r0, [r0, #0xc]` is the reach of
 * the Thumb-era halfword load showing through, not a second object: see
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_020331D0.c  *       --func sub_020331D0 --addr 0x020331D0 --cc 1.1p1 --arm
 */
void sub_020331D0(struct SaveBackup *p)
{
    p->unk28 = p->unk10;
    func_0203386C(g_02146994->unk20C);
    func_02034FB8(1);
}


/*
 * savedata.c.  Blanks the sixteen byte footer of a backup record by
 * pushing an all-0xFF block from the stack over it.  The 0x10 is kept in a
 * callee-saved register because it is both the fill length and the write
 * length, one on each side of the MI_CpuFill8 call.
 *
 * 0x02031EAC takes two arguments here.  sub_020328E0 in the same file
 * reaches it with only r0 set, which is the leftover-argument shape of
 * docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md
 * seen from the caller side; two arguments is the honest prototype.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02033200.c \n *       --func sub_02033200 --addr 0x02033200 --cc 1.1p1 --arm
 */
u32 sub_02033200(struct SaveBackup *p, u32 id)
{
    u8 tmp[0x10];

    MI_CpuFill8(tmp, 0xFF, sizeof(tmp));
    return func_020335AC(p->unk30 + func_02031EAC((u32 *)p, id) - 0x10, (u32)tmp, sizeof(tmp),
                  g_02146994->unk208);
}


/*
 * savedata.c.  Bumps the halfword counter that sits at the head of one of
 * the records inside the staging buffer and answers the new value.  The
 * closing `ldrh` is not a redundant reload: reloading the halfword is one
 * instruction where truncating the incremented value in a register would
 * be two, so the compiler reads the store back rather than masking.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02033264.c \n *       --func sub_02033264 --addr 0x02033264 --cc 1.1p1 --arm
 */
u16 sub_02033264(struct SaveBackup *p, u32 id)
{
    u32 base;
    u32 off;
    u16 *q;

    base = func_02033B68((u8 *)p->unk2C, id);
    off = func_02033BAC((u8 *)p->unk2C, id);
    q = (u16 *)(p->unk34 + (base + off));
    *q = *q + 1;
    return *q;
}


/*
 * savedata.c.  Recomputes the CRC-16/CCITT of one record in the staging
 * buffer and stores it in the halfword that follows the record.  The table
 * argument is the global at 0x02146994 plus four, i.e. a MATHCRC16Table
 * that lives inline at +4 of that object rather than a pointer kept there.
 * As in sub_02033264 the answer is read back out of the halfword it was
 * just stored into.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020332A4.c \n *       --func sub_020332A4 --addr 0x020332A4 --cc 1.1p1 --arm
 */
u16 sub_020332A4(struct SaveBackup *p, u32 id)
{
    u32 base;
    u32 len;
    u16 *q;
    u32 buf;

    base = func_02033B68((u8 *)p->unk2C, id);
    len = func_02033BAC((u8 *)p->unk2C, id);
    buf = p->unk34;
    q = (u16 *)(buf + (base + len));
    q[1] = MATH_CalcCRC16CCITT(g_02146994->crcTable, (void *)(buf + base), len);
    return q[1];
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * A packed 2-bit-per-slot array getter. The backing store is a u32 array
 * reached through offset 0x138 of the object; slot `idx` lives in word
 * `idx >> 4` at bit position `(idx & 0xf) * 2`. The companion setter at
 * 0x0203331C (immediately following, same file) computes its clear mask
 * through a `long long` NOT (docs/idioms/a-64-bit-complement-is-eors-with-minus-one-not-mvns.md)
 * that this getter does not need and is left open.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020332FC.c \
 *       --addr 0x020332FC --arm
 */
u32 sub_020332FC(struct Obj020332FC *p, u32 idx)
{
    return (p->slots[idx >> 4] >> ((idx & 0xf) * 2)) & 3;
}


/*
 * backup_system.c.  The packed 2-bit-per-slot array SETTER, companion to
 * the getter src/matched/unit_020332FC.c at 0x020332FC (same file, the
 * function immediately before it).  The backing store is a u32 array at
 * offset 0x138 of the object; slot `idx` lives in word `idx >> 4` at bit
 * position `(idx & 0xf) * 2`.
 *
 * Two spellings carry this function and neither is optional:
 *
 * 1. The clear mask is a 64-bit complement, not `~`.  The original's
 *    `mov r3, #3` / `sub r1, r3, #4` / `eor r1, r1, r3, lsl lr` triple is
 *    the low half of a `long long` NOT with the high half dead-code
 *    eliminated -- see docs/idioms/
 *    a-64-bit-complement-is-eors-with-minus-one-not-mvns.md.  Spelling it
 *    `~(3 << sh)` compiles to `mvn r1, r1, lsl r4` and loses four bytes
 *    (60 against 64); the literal `3` must stay inline in the `^ -1` form
 *    so the same `mov r3, #3` feeds both the `sub` that makes -1 and the
 *    shifted operand of the `eor`.  Binding it to a `long long mask = 3;`
 *    local instead costs a second constant materialisation (68 bytes).
 *
 * 2. The word index of the CLEAR half goes through a two-step copy chain
 *    (`tmp1 = idx >> 4; tmp = tmp1;`) while the SET half re-reads
 *    `idx >> 4` and `sh` directly.  Without the copy chain the compiler
 *    colours the shift amount r4 and the word index lr, which is the
 *    exact reverse of the original (10 concrete bytes, a pure r4 <-> lr
 *    swap with every instruction otherwise identical).  The extra copy
 *    splits the word index's live range so the allocator numbers the
 *    shift amount first and it takes lr.  Found by tools/permuter.py
 *    (--mode anneal, `expand(sh) ; temp(tmp=idx >> 4) ; temp(tmp1=idx >> 4)
 *    ; reorder(-1)`), then reduced by hand: dropping either temp returns
 *    the residue to the same 10 bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203331C.c \
 *       --func sub_0203331C --addr 0x0203331C --cc 1.1p1 --arm
 */
void sub_0203331C(struct Obj020332FC *p, u32 idx, u32 val)
{
    u32 sh = (idx & 0xf) * 2;
    u32 tmp;
    u32 tmp1;

    tmp1 = idx >> 4;
    tmp = tmp1;
    p->slots[tmp] &= (3 << ((idx & 0xf) * 2)) ^ -1;
    p->slots[idx >> 4] |= val << sh;
}


/*
 * backup_system.c.  Swaps the two record marks across the whole packed
 * 2-bit-per-slot bitmap at +0x138: every slot holding 1 becomes 2 and every
 * slot holding 2 becomes 1 (0 and 3 are left alone).  The slot count is
 * sub_02033BF0(p->unk2c) + 2, the same count func_02033410 fills; the one-slot
 * getter and setter are src/matched/unit_020332FC.c and sub_0203331C.c.
 * Called by func_02032CD0 when a save generation completes.
 *
 * Three spellings carry it (docs/notes/sub_0203335C.c.txt has four lanes of
 * measurements at 21 bytes out before these were found):
 *
 * 1. The clear mask is the 64-bit complement written on a widened value,
 *    `(long long)(3 << sh) ^ -1` (docs/idioms/
 *    a-64-bit-complement-is-eors-with-minus-one-not-mvns.md).  With the int
 *    form `(3 << sh) ^ -1` every instruction is right but the hoisted 3 is
 *    coloured before the word index; the widened form numbers the 3 and the
 *    -1 after it and gives the image's sb/r7/r8 for 3/-1/mask.
 * 2. The first read indexes with `(int) w` while the clear and the set
 *    index with the plain u32 `w`; without the cast the word index, the
 *    slots pointer and the slot value rotate (r2/r6/r5 -> r6/r5/r2, 28
 *    bytes).  Found by tools/permuter.py anneal, then isolated by a sweep.
 * 3. The bound is a copy `n_ = n` tested by the loop, the guard tests `n`
 *    (the lever that closed func_02033410); all loop values are u32 so the
 *    wrap uses subhs/addhs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203335C.c \
 *       --func sub_0203335C --addr 0x0203335C --cc 1.1p1 --arm
 */
void sub_0203335C(struct Obj0203335C *p)
{
    u32 n;
    u32 w;
    u32 sh;
    u32 n_;
    u32 i;
    u32 v;

    n = sub_02033BF0(p->unk2c) + 2;
    w = 0;
    sh = 0;
    i = 0;
    n_ = n;
    if (n == 0) {
        return;
    }
    do {
        v = (p->slots[(int)w] >> sh) & 3;
        if (v != 0) {
            if (v == 1) {
                v = 2;
            } else if (v == 2) {
                v = 1;
            }
            p->slots[w] &= (long long)(3 << sh) ^ -1;
            p->slots[w] |= v << sh;
        }
        sh += 2;
        i++;
        if (sh >= 0x20) {
            sh -= 0x20;
            w++;
        }
    } while (i < n_);
}


void func_020333F8(Save *self)
{
    func_02082A7C(0, (void *)((struct Obj11327 *)self)->f138, ((struct Obj11327 *)self)->f13C);
}


/*
 * backup_system.c.  Fills the whole packed 2-bit-per-slot bitmap at offset
 * 0x138 with one repeated value: MIi_CpuClear32 (func_02082A7C) wipes
 * p->nbytes bytes of it, then `val` is OR'd in two bits at a time for
 * sub_02033BF0(p->unk2c) + 2 slots.  The getter/setter for one slot of the
 * same bitmap are src/matched/unit_020332FC.c and
 * src/matched/sub_0203331C.c.
 *
 * Two spellings carry this function:
 *
 * 1. The shift amount and the word index must be u32, not int.  An int
 *    gives the SIGNED conditional pair `subge`/`addge` where the original
 *    has the unsigned `subhs`/`addhs`; docs/notes/pkt_02033410.c.txt
 *    records that this alone was worth 38 of the original 44 residue bytes.
 *
 * 2. The loop bound is read through a COPY of the count declared before the
 *    counter (`n_ = n;` with `u32 n_;` ahead of `u32 i;`).  Written the
 *    obvious way -- the loop testing `n` directly -- the allocator swaps
 *    the counter and the bound (original `mov ip, r6` / `adds r3, r0, #2`
 *    / `add ip, ip, #1` / `cmp ip, r3`; compiled the same four with r3 and
 *    ip exchanged), which is 9 concrete bytes at the right size and is the
 *    residue the old note parked at.  The extra copy splits the bound's
 *    live range so it is numbered after the counter and takes r3.  Found
 *    by tools/permuter.py --mode hill (`copy(n->n_@9) ; decl-order(n_<->i)`).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02033410.c \
 *       --func func_02033410 --addr 0x02033410 --cc 1.1p1 --arm
 */
void func_02033410(struct Obj02033410 *p, u32 val)
{
    u32 n;
    u32 w;
    u32 sh;
    u32 n_;
    u32 i;

    func_02082A7C(0, p->slots, p->nbytes);
    n = sub_02033BF0(p->unk2c) + 2;
    w = 0;
    sh = 0;
    n_ = n;
    i = 0;
    if (n_ == 0) {
        return;
    }
    do {
        i++;
        p->slots[w] |= val << sh;
        sh += 2;
        if (sh >= 0x20) {
            sh -= 0x20;
            w++;
        }
    } while (i < n_);
}


void func_02033478(int a0, int a1, int a2){ func_020335AC((int)a0, (int)a1, (int)a2, (int)*(int *)(((char *)(*(int *)((char *)(0x2146994))) + 520))); }


/*
 * Tail-call accessor, the sibling of func_02033478: load the object at
 * 0x02146994, read its field at +0x208, and forward r0-r2 plus that word
 * as the fourth argument of func_020336B8.  Unlabelled in the listing (it
 * saves no lr), so it is invisible to `sole-ref/code` until this entry
 * exists; it is the witness that unblocks the thumb caller func_021DFE00.
 */
void func_02033494(int a0, int a1, int a2, int a3){ func_020336B8((int)a0, (int)a1, (int)a2, (void *)((int)*(int *)(((char *)(*(int *)((char *)(0x2146994))) + 520)))); }


/*
 * Tail-call accessor, the sibling of func_02033478: load the object at
 * 0x02146994, read its field at +0x208, and forward r0-r1 plus that word
 * as the third argument of func_020337B8.  The loaded word lands in r2
 * (not r3 like func_02033494), which is what fixes the arity at three.
 * Unlabelled in the listing (it saves no lr), so it is invisible to
 * `sole-ref/code` until this entry exists; it is the witness that
 * unblocks the thumb caller func_021DFE00.
 */
void func_020334B0(u16 a0, int a1){ func_020337B8(a0, (u32 *)a1, g_02146994->unk208); }


/*
 * Tail-call thunk: forwards its arguments to func_020335E8 with the word at
 * +0x204 of the object at g_02146994 as the last argument.  No arm9 code
 * calls it; its callers are Thumb blx in ov228, so the listing carried it as
 * raw words until the seed in layout/function_starts.txt.
 */
int func_020334CC(u32 a, u32 b, u32 c)
{
    return func_020335E8(a, b, c, (void (*)(void))g_02146994->unk204);
}


int func_020334E8(u8 *p, u32 b, u32 c, u32 d, u32 e)
{
    u32 n = func_02031EAC((u32 *)p, c + 1);
    u32 m = func_02033B68(*(u8 * *)&((struct Obj15882 *)p)->f2C, b);

    return func_020335E8(n + m, d, e, (void (*)(void))g_02146994->unk204);
}


/*
 *           --suggest-split offers nothing (single function, the one
 *           unresolved site's only witness is inside this range).
 *           the only branch to it in the image is this function's own call.
 *           Every concrete byte of the body reproduces.
 */
int func_02033534(u32 a)
{
    int id = func_02084EB8(a);
    u32 h;

    if (id == -3) {
        func_02034714((const char *)str_020A78A0, 0x38, (const char *)str_020A78B0);
    }
    func_02075E9C((u16)id);
    h = 0x00ff1302;
    if (func_02076B2C(h) == 0) {
        h = 0;
    }
    func_02075EAC((u16)id);
    func_02084F10((u16)id);
    return h != 0;
}


/*
 * The retry loop is a `while (call(...) == 0) ;` with an uninitialised `v`:
 * zeroing `v` first costs a `mov r4, #0` + `str r4, [sp]` the original does
 * not have, and 8 bytes of frame.  The second call site resolves on the
 * `literal` class (the word 0x020337B8 appears in the callee's own pool).
 */
u32 func_020335AC(u32 a, u32 b, u32 c, u32 d)
{
    u32 v;
    u16 h = func_020336B8(a, b, c, (void *)d);

    while (func_020337B8(h, &v, d) == 0) {
        ;
    }
    return v;
}


/*
 * EXACT* rather than EXACT: the follower at 0x020336A4 (20 bytes, an
 * unlabelled leaf holding a two-instruction store and `bx lr` between the
 * pool words) saves no lr, so disasm.py gives no label and the inferred
 * extent runs 188 -> 208.  Every concrete byte of the 188 is identical.
 * Report the follower rather than editing layout/function_starts.txt.
 * The result of CARDi_RequestStreamCommand lands in r6 only after the
 * intervening call to the void func_02076B80: mwcc keeps r0 live across a
 * void-returning call and defers the move.  Same body as func_02033534 with
 * a two-function stream instead of CARD_IdentifyBackup.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020335E8.c \
 *       --func func_020335E8 --addr 0x020335E8 --cc 1.1p1
 */
int func_020335E8(u32 a0, u32 a1, u32 a2, void (*a3)(void))
{
    int id = func_02084EB8(a0);
    int r;

    if (id == -3) {
        func_02034714((const char *)str_020A78A0, 0xa4, (const char *)str_020A78B0);
    }
    func_02075E9C((u16)id);
    r = CARDi_RequestStreamCommand(a0, a1, a2, 0, 0, 1, 6, 1, 0);
    r = func_02076B80();
    func_02075EAC((u16)id);
    func_02084F10((u16)id);
    if (r == 0 && a3 != 0) {
        a3();
    }
    return r;
}


/*
 * The dma completion callback passed by func_020336B8: it raises the flag
 * that the synchronous path lowers before the asynchronous request.
 */
void func_020336A4(void)
{
    d_020A789C = 1;
}


/*
 * Two stream commands plus a 4-byte status read into a stack word.  The
 * first passes is_async = 0 and the retry count exercises the function at
 * 0x020336A4 (an unlabelled leaf, the follower of func_020335E8, which sets
 * the flag at 0x02146998) as the dma callback.  d_02146998 is raised around
 * the synchronous read and d_020A789C lowered before the asynchronous one.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020336B8.c \
 *       --func func_020336B8 --addr 0x020336B8 --cc 1.1p1
 */
u16 func_020336B8(u32 a0, u32 a1, u32 a2, void *a3)
{
    int id = func_02084EB8(a0);
    u32 buf;

    if (id == -3) {
        func_02034714((const char *)str_020A78A0, 0xd4, (const char *)str_020A78B0);
    }
    func_02075E9C((u16)id);

    g_02146998 = 1;
    if (CARDi_RequestStreamCommand(0, (u32)&buf, 4, 0, 0, 0, 6, 1, 0) == 0) {
        func_020338B8((u16)id, 1, a3);
    }

    d_020A789C = 0;
    CARDi_RequestStreamCommand(a1, a0, a2, func_020336A4, 0, 1, 7, 10, 2);
    return (u16)id;
}


int func_020337B8(u16 a0, u32 *a1, u32 a2)
{
    if (g_020A789C[0] == 1) {
        func_02075EAC(a0);
        func_02084F10(a0);
        g_02146998 = 0;

        switch (func_02075DD8()) {
        case 0:
            *a1 = 1;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 7:
        default:
            *a1 = 0;
            func_020338B8(a0, 0, (void (*)(u32))a2);
            break;
        case 6:
            *a1 = 0;
            func_020338B8(a0, 1, (void (*)(u32))a2);
            break;
        }
        return 1;
    }
    return 0;
}


void func_0203386C(u16 a)
{
    if (func_02076B8C() == 0) {
        func_02076B98();
        func_02076B80();
    }
    if (g_02146998 != 1) {
        return;
    }
    func_02075EAC(a);
    func_02084F10(a);
    g_02146998 = 0;
}


void func_020338B8(u16 a, u32 b, void (*cb)(u32))
{
    func_02075EAC(a);
    func_02084F10(a);
    g_02146998 = 0;
    if (cb != 0) {
        cb(b);
    }
}


/*
 * Accessor for the singleton pointer at 0x02146998.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020338F8.c \
 *       --func func_020338F8 --addr 0x020338F8 --cc 1.1p1 --arm
 */
void *func_020338F8(void)
{
    return (void *)g_02146998;
}


/*
 * Seven arguments, the last three on the stack.  A 0x1c-byte record is taken
 * from the pool `a0` names (tag 0x49) and cleared, four of the caller's
 * values are stored into it (- / +4 / +0x10 / +8 in that order), a second
 * run of 12 * a2 bytes is taken with tag 0x4f and its address goes to +0x14,
 * the last stack argument to +0x18, and the whole record plus the second
 * stack argument goes to func_02033A88.
 *
 * Blocked on: the call to func_02033A88 at +0x98 is the only branch to that
 * address anywhere in the image, so `label` refuses it (its sole witness is
 * this function's own call site) and the site stays wildcarded.  Every other
 * byte, including the other four relocation sites, is right.  0x02033A88 is
 * in pkt_02033A88, not this lane's packets; filing it first would turn this
 * row EXACT with no change to the C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02033908.c \
 *       --func func_02033908 --addr 0x02033908 --cc 1.1p1 --arm
 */
void *func_02033908(u16 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6)
{
    u8 *p = (u8 *)func_02030734(a0, 0x1c, 0, (const char *)g_020A78CC, 0x49);

    MIi_CpuClear32(0, p, 0x1c);
    *(u32 *)&((struct Obj01312 *)p)->f0 = a1;
    ((struct Obj01312 *)p)->f4 = a2;
    ((struct Obj01312 *)p)->f10 = a3;
    ((struct Obj01312 *)p)->f8 = a4;
    *(u32 *)&((struct Obj01312 *)p)->f14 = (u32)func_02030734(a0, a2 * 12, 1, (const char *)g_020A78CC, 0x4f);
    ((struct Obj01312 *)p)->f18 = a6;
    func_02033A88((struct Save_020339B4 *)p, a5);
    return p;
}


/*
 * Destructor for one record: release the pointer held at +0x14, then the
 * record itself.  Both releases go through the overruled SDK address
 * 0x020307B0, which is already matched, so both PC24 sites attest on the
 * `matched` class.  This function is itself the only blocker for
 * src/matched/func_0203195C.c and the parked save-backup file
 * src/pending/sub_020331D0.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020339B4.c \
 *       --func func_020339B4 --addr 0x020339B4 --arm --cc 1.1p1
 */
void func_020339B4(int *p)
{
    func_020307B0((void *)p[5]);
    func_020307B0(p);
}


void func_020339D0(u32 a, T *sb)
{
    PtrEnt *ptrs = (PtrEnt *)sb->f00;
    u32 n = sb->f04;
    int i;

    func_02082A7C(0, (void *)a, sb->f10);
    for (i = 0; i < n; i++) {
        u32 off = ((Ent *)sb->f14)[i].off;
        func_02082A7C(0, (void *)(a + off), ((Ent *)sb->f14)[i].size);
        ((void (*)(u32))ptrs[i].fn)(a + off);
    }
}


u32 func_02033A3C(u32 *p, u32 i)
{
    FP fp;
    u32 base = p[0];

    if (i >= p[1]) {
        func_02034714((const char *)str_020A78CC, 0x85, (const char *)str_020A78D8);
    }
    fp = *(FP *)(base + i * 0xc + 4);
    return (fp() + 3) & ~3;
}


/*
 * note:     savedata.c: lay out the save blocks (id check, per-block size
 *           from func_02033A3C, offsets rounded up to 0x100) and assert the
 *           total fits.  Closed in wave 16 by two declaration facts:
 *           func_02034734 takes FIVE arguments (the total in r3 and the
 *           limit on the stack, which is what the image's `sub sp, sp, #8`
 *           and `str r4, [sp]` are), and the locals are declared src, i,
 *           count, dst, total (i before count puts i in r5 and count in r6).
 *           The `mov r1, r5` the old note called dead is func_02033A3C's
 *           second argument.
 */
void func_02033A88(struct Save_020339B4 *p, u32 v)
{
    struct Src *src;
    u32 i;
    u32 count;
    struct Dst *dst;
    u32 total;
    u32 size;
    u32 off;
    u32 pad;

    src = p->src;
    count = p->count;
    dst = p->dst;
    total = 0;

    for (i = 0; i < count; i++) {
        if (i != src[i].id) {
            func_02034714((const char *)str_020A78CC, 0x9e, (const char *)str_020A78F0);
        }
        dst[i].id = src[i].id;
        size = func_02033A3C((u32 *)p, i);
        dst[i].size = size;
        dst[i].offset = total;
        off = v + size;
        pad = off & 0xff;
        if (pad != 0)
            pad = 0x100 - pad;
        else
            pad = 0;
        total += off + pad;
    }
    p->f0c = p->f08 + (total + p->f18);
    if (p->f0c > p->f10) {
        func_02034734((const char *)str_020A78CC, 0xb3, (const char *)str_020A7908, p->f0c, p->f10);
    }
}


u32 func_02033B68(u8 *p, u32 i)
{
    if (i >= ((struct Obj11330 *)p)->f4) {
        func_02034714((const char *)str_020A78CC, 0xc7, (const char *)str_020A793C);
    }
    return *(u32 *)(((struct Obj11330 *)p)->f14 + i * 0xc + 8);
}


u32 func_02033BAC(u8 *p, u32 i)
{
    if (i >= ((struct Obj11331 *)p)->f4) {
        func_02034714((const char *)str_020A78CC, 0xd6, (const char *)str_020A793C);
    }
    return *(u32 *)(((struct Obj11331 *)p)->f14 + i * 0xc + 4);
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * Two plain field accessors on the same object, no relocations. Called
 * repeatedly through the rest of this packet.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02033BF0.c \
 *       --addr 0x02033BF0 --arm
 */
u32 sub_02033BF0(struct Obj02033BF0 *p)
{
    return p->unk04;
}


u32 sub_02033BF8(struct Obj02033BF0 *p)
{
    return p->unk0c;
}


/*
 * alias: "areaman.c".  The pool word at 0x02033C94 holds 0x020A7958 and the
 * bytes there spell "areaman.c", so this range is the head of that file; the
 * `string` class closes the site because "gmdataid < svdt->table_max" ends
 * with its NUL at 0x020A7956 and two bytes of padding put the next string at
 * 0x020A7958 by construction.
 *
 * The constructor of the area manager: `size` is a count of areas, and the
 * object carries a bitmap one bit per area.  The byte count is rounded up
 * from the bit count and then up again to a multiple of four, the allocation
 * is 0xC bytes of header plus the bitmap plus the four byte guard word
 * 0x573C765A that is written immediately past the bitmap, and the bitmap
 * itself is cleared.  The guard word is what the checker in this subsystem
 * re-reads to catch an overrun.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02033C00.c \
 *       --func sub_02033C00 --addr 0x02033C00 --cc 1.1p1 --arm
 */
struct AreaMan *sub_02033C00(u32 size, u16 heap)
{
    struct AreaMan *p;
    u32 n;
    u16 nbytes;

    n = ((size & 7) != 0) + (size >> 3);
    while ((n & 3) != 0) {
        n++;
    }
    nbytes = (u16)n;

    p = func_02030734(heap, nbytes + 0x10, 0, sub_02033C00_File, 0x94);
    p->unk00 = (u16)size;
    p->unk02 = nbytes;
    p->guard = (u32 *)(p->bits + nbytes);
    *p->guard = 0x573C765A;
    p->unk08 = 0;
    MI_CpuFill8(p->bits, 0, nbytes);
    return p;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * Four to eight byte function with no prologue at all: a pool word and a
 * bx, exactly the tail-call veneer idiom recorded in
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md. No arguments are touched,
 * so the call forwards whatever the caller left in the argument registers.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02033C9C.c \
 *       --addr 0x02033C9C --arm
 */
u32 sub_02033C9C(void *a)
{
    return func_020307B0(a);
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * Previously parked at MATCH: the two dispatch arms 0x02033CFC and
 * 0x02033E30 are each reached by exactly one branch in the whole image, the
 * one in sub_02033CC0 itself, so neither had an outside witness.  Both now
 * close on the `matched` class (src/matched/sub_02033CFC.c and
 * src/matched/sub_02033E30.c); nothing in this file had to change.
 *
 * areaman.c, the front door of the variable length record allocator built on
 * the 0x02033C00 object.  sub_02033CA8 is the "search the whole bitmap" entry
 * point: it forwards to the ranged form with a start of zero and a limit of
 * the object's bit count.  sub_02033CC0 validates the request against the
 * bitmap extent and then dispatches on the run length: runs shorter than
 * eight bits go to the bit-at-a-time scanner at 0x02033CFC, longer runs to
 * the word-at-a-time scanner at 0x02033E30.  Both dispatch arms are written
 * out as their own return so that each gets its own `bl`/`pop` pair, which is
 * what the original has.
 *
 * The forwarding tail call in sub_02033CA8 is the pool-word-and-bx idiom
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md): one section per function
 * means the call to the very next function in the same file still costs a
 * pool word.  Keeping the two in one unit makes that site `local`, which is
 * what closes it without an outside witness.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/unit_02033CA8.c \
 *       --addr 0x02033CA8 --arm
 */
s32 sub_02033CA8(struct AreaMan *p, u32 len)
{
    return sub_02033CC0(p, 0, p->unk00, len);
}


s32 sub_02033CC0(struct AreaMan *p, u32 start, u32 limit, u32 len)
{
    if (limit < len || start + len > p->unk00) {
        return -1;
    }

    if (len < 8) {
        return func_02033CFC(p, start, limit, len);
    }

    return func_02033E30(p, start, limit, len);
}


s32 sub_02033CFC(struct AreaMan *p, u32 start, u32 limit, u32 len)
{
    s32 found;
    s32 last;
    s32 lastByte;
    s32 i;
    s32 bit;
    u32 tail;

    last = start + limit + 1 - len;
    lastByte = last / 8;
    i = start >> 3;
    found = -1;

    if ((start & 7) + len <= 8) {
        bit = func_020342F8(p->bits[i], start & 7, len);
        if (bit != -1) {
            found = bit + i * 8;
            goto done;
        }
    }

    while (i <= lastByte) {
        if (g_RunLenAny[p->bits[i]] >= len) {
            bit = func_020342F8(p->bits[i], 0, len);
            if (bit != -1) {
                found = bit + i * 8;
                goto done;
            }
        } else {
            tail = g_RunLenTail[p->bits[i]];
            if (tail != 0 && i < lastByte) {
                if (g_RunLenHead[p->bits[i + 1]] >= len - tail) {
                    found = (8 - tail) + i * 8;
                    goto done;
                }
            }
        }
        i++;
    }

done:
    if (found != -1 && found <= last) {
        if (func_020343C0(p, found, len) == 0) {
            return -1;
        }
        func_02034508(p, found, len, 0x17c);
        return found;
    }
    return -1;
}


/*
 * areaman.c.  The word-at-a-time run scanner: the long-run arm of
 * sub_02033CC0's dispatch (see src/pending/unit_02033CA8.c), taken when the
 * requested run is eight bits or longer.  Where sub_02033CFC walks bit by
 * bit, this one anchors on the trailing free run of byte `i`, skips whole
 * zero bytes, and then checks the leading free run of the byte the tail
 * lands in.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02033E30.c \
 *       --func sub_02033E30 --addr 0x02033E30 --cc 1.1p1 --arm
 */
s32 sub_02033E30(struct AreaMan *p, u32 start, u32 limit, u32 len)
{
    u32 last;
    s32 lastByte;
    s32 run;
    s32 t;
    s32 n;
    s32 i;
    s32 q;
    s32 j;
    s32 r;
    s32 found;

    i = start >> 3;
    last = start + limit - len;
    lastByte = last / 8;

    run = 8 - (start & 7);
    t = g_RunLenTail[p->bits[i]];
    if (t < run) {
        run = t;
    }

    while (i <= lastByte) {
        if (run != 0) {
            n = len - run;
            q = n / 8;
            r = n % 8;
            j = i + 1;
            while (q != 0) {
                if (p->bits[j] != 0) {
                    break;
                }
                j++;
                q--;
            }
            if (q == 0) {
                found = -1;
                if (r == 0) {
                    found = (8 - run) + i * 8;
                } else if (g_RunLenHead[p->bits[j]] >= r) {
                    found = (8 - run) + i * 8;
                }
                if (found != -1) {
                    if (func_020343C0(p, found, len) == 0) {
                        return -1;
                    }
                    func_02034508(p, found, len, 0x1db);
                    return found;
                }
            }
        }
        i++;
        if (i <= lastByte) {
            run = g_RunLenTail[p->bits[i]];
        }
    }

    return -1;
}


s32 sub_02033F64(struct AreaMan *p, u32 start, u32 limit, u32 len)
{
    s32 pos;

    if (limit < len) {
        return -1;
    }

    if (len < 8) {
        pos = func_02033FB0(p, start, limit, len);
    } else {
        pos = func_020340D0(p, start, limit, len);
    }

    func_02034508(p, pos, len, 0x230);
    return pos;
}


/*
 * areaman.c.  The downward bit-at-a-time run scanner: the short-run arm of
 * sub_02033F64's dispatch (see src/pending/sub_02033F64.c), the mirror of
 * sub_02033CFC walking towards lower addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02033FB0.c \
 *       --func sub_02033FB0 --addr 0x02033FB0 --cc 1.1p1 --arm
 */
s32 sub_02033FB0(struct AreaMan *p, u32 start, u32 limit, u32 len)
{
    s32 i;
    s32 last;
    s32 lastByte;
    s32 found;
    s32 bit;
    u32 head;

    last = start - limit + 1;
    lastByte = last / 8;
    i = start >> 3;
    found = -1;

    if ((start & 7) != 0) {
        bit = func_02034348(p->bits[i], start & 7, len);
        if (bit != -1) {
            found = bit + i * 8;
            goto done;
        }
    }

    while (i >= lastByte) {
        if (g_RunLenAny[p->bits[i]] >= len) {
            bit = func_02034348(p->bits[i], 7, len);
            if (bit != -1) {
                found = bit + i * 8;
                goto done;
            }
        } else {
            head = g_RunLenHead[p->bits[i]];
            if (head != 0 && i > lastByte) {
                if (g_RunLenTail[p->bits[i - 1]] >= len - head) {
                    found = (8 - (len - head)) + (i - 1) * 8;
                    goto done;
                }
            }
        }
        i--;
    }

done:
    if (found != -1 && found >= last) {
        if (func_020343C0(p, found, len) == 0) {
            found = -1;
        }
        return found;
    }
    return -1;
}


/*
 * areaman.c.  The downward word-at-a-time run scanner: the long-run arm of
 * sub_02033F64's dispatch (see src/pending/sub_02033F64.c), the mirror of
 * sub_02033E30 walking towards lower addresses.  The anchor is the leading
 * free run of byte `i`, whole zero bytes are skipped downwards, and the
 * trailing free run of the byte the remainder lands in closes the request.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020340D0.c \
 *       --func sub_020340D0 --addr 0x020340D0 --cc 1.1p1 --arm
 */
s32 sub_020340D0(struct AreaMan *p, u32 start, u32 limit, u32 len)
{
    s32 i;
    u32 last;
    s32 lastByte;
    s32 run;
    s32 r;
    s32 t;
    s32 n;
    s32 q;
    s32 j;
    s32 found;

    last = start - limit + 1;
    i = start >> 3;
    lastByte = last / 8;

    run = (start & 7) + 1;
    t = g_RunLenHead[p->bits[i]];
    if (t < run) {
        run = t;
    }

    while (i >= lastByte) {
        if (run != 0) {
            n = len - run;
            q = n / 8;
            r = n % 8;
            j = i - 1;
            while (q != 0) {
                if (j < lastByte || p->bits[j] != 0) {
                    break;
                }
                j--;
                q--;
            }
            if (q == 0) {
                found = -1;
                if (r == 0) {
                    found = (j + 1) * 8;
                } else if (j >= lastByte && g_RunLenTail[p->bits[j]] >= r) {
                    found = (8 - r) + j * 8;
                }
                if (found != -1 && found >= last) {
                    if (func_020343C0(p, found, len) == 0) {
                        found = -1;
                    }
                    return found;
                }
            }
        }
        i--;
        if (i >= lastByte) {
            run = g_RunLenHead[p->bits[i]];
        }
    }

    return -1;
}


/*
 * areaman.c.  Test-and-report: ask the range checker at 0x020343C0 whether
 * the run [start, start+len) is free, and if it is not, report it through
 * the assert sink at 0x02034508 with line 0x304 before answering.  The
 * three arguments are held in callee-saved registers across the first call
 * precisely because the second call needs them again.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020341F0.c \
 *       --func sub_020341F0 --addr 0x020341F0 --cc 1.1p1 --arm
 */
s32 sub_020341F0(struct AreaMan *p, u32 start, u32 len)
{
    if (func_020343C0(p, start, len) == 0) {
        return 0;
    }

    func_02034508(p, start, len, 0x304);
    return 1;
}


/*
 * areaman.c.  Clear `len` bits starting at bit `start` of the bitmap: a run
 * inside one byte goes to func_02034394 (q, bit, len); otherwise the head
 * bits are cleared with the tail mask, whole bytes are zeroed and the run
 * mask clears the head of the last byte.  func_020344C8 then refreshes the
 * manager.
 *
 * What closed it (wave 17, from 17 out): the byte cursor past the head is
 * the PARAMETER reused, `start = idx + 1;`, not idx incremented.  That puts
 * the cursor in start's own register r1 and rotates the zero and the count
 * to the image's r2 / r3; the same lever closed sub_020343C0.
 * docs/idioms/a-dead-parameter-reused-as-the-index-rotates-the-loop-registers.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203422C.c \
 *       --func func_0203422C --addr 0x0203422C --cc 1.1p1 --arm
 */
void func_0203422C(struct AreaMan *p, u32 start, s32 len)
{
    u32 bit = start % 8;
    u32 idx = start / 8;
    s32 avail;
    s32 rest;
    u32 nfull;
    u32 tail;
    u32 mask;

    if ((bit + len) <= 8) {
        func_02034394(&p->bits[idx], bit, len);
    } else {
        avail = 8 - bit;
        mask = Areaman_TailMask[avail];
        rest = len - avail;
        nfull = rest / 8;
        tail = rest % 8;
        p->bits[idx] &= (u8)~mask;
        start = idx + 1;
        while (nfull-- != 0) {
            p->bits[start] = 0;
            start++;
        }
        p->bits[start] &= (u8)~Areaman_RunMask[tail];
    }
    func_020344C8((struct Struct_020344C8 *)p);
}


/*
 * areaman.c.  The forward bit-run scanner inside one byte of the bitmap:
 * given the byte, a starting bit and a run length, walk the run mask down
 * from `start` and return the first bit position at which `len` consecutive
 * bits are all clear, or -1.
 *
 * 0x020A048C is a nine byte table, 00 80 C0 E0 F0 F8 FC FE FF, i.e. the
 * mask of the top `len` bits of a byte; the entry for len == 8 is the last,
 * which is why the length guard is `> 8` here and `>= 8` in the backward
 * scanner at 0x02034348 (that one indexes the same table after adding one).
 * The address has three pool words in the image (0x02034344, 0x02034390 and
 * 0x020343BC), so compiling this function alone leaves two of them outside
 * the compared range and the `literal` class closes the site.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020342F8.c \
 *       --func sub_020342F8 --addr 0x020342F8 --cc 1.1p1 --arm
 */
s32 sub_020342F8(u32 bits, u32 start, u32 len)
{
    u8 mask;
    u32 last;

    if (len <= 8) {
        last = 8 - len;
        mask = Areaman_RunMask[len] >> start;

        while (start <= last) {
            if ((bits & mask) == 0) {
                return start;
            }
            mask >>= 1;
            start++;
        }
    }

    return -1;
}


/*
 * areaman.c.  The backward twin of sub_020342F8: same run-mask table, but
 * the cursor walks down from `start` instead of up, so the mask is shifted
 * left each step and the loop ends when the signed cursor goes negative.
 * The cursor really is signed here, which is the only reason the original
 * can reuse the flags of the `subs` that computes it for both the entry
 * guard (`bmi`) and the loop back edge (`bpl`).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02034348.c \
 *       --func sub_02034348 --addr 0x02034348 --cc 1.1p1 --arm
 */
s32 sub_02034348(u32 bits, u32 start, u32 len)
{
    u8 mask;
    s32 i;

    if (len < 8) {
        i = (s32)(start + 1) - (s32)len;
        mask = Areaman_RunMask[len] >> i;

        while (i >= 0) {
            if ((bits & mask) == 0) {
                return i;
            }
            mask <<= 1;
            i--;
        }
    }

    return -1;
}


/*
 * areaman.c.  Clears a run of `len` bits starting at bit `start` inside one
 * bitmap byte, using the same 0x020A048C run-mask table as the two scanners.
 * The `and r1, r1, #0xff` after the complement is the u8 truncation, not a
 * mask written in the source.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02034394.c \
 *       --func sub_02034394 --addr 0x02034394 --cc 1.1p1 --arm
 */
void sub_02034394(u8 *p, u32 start, u32 len)
{
    u8 mask = Areaman_RunMask[len] >> start;

    *p = *p & (u8)~mask;
}


/*
 * areaman.c.  Mark `len` bits starting at bit `start` of the bitmap as used:
 * fails (0) past the managed range or when any target bit is already set
 * (dumping the mask and the byte through the release-empty hook
 * func_020344C4 when p->unk08 is set), otherwise sets the head bits, fills
 * whole bytes with 0xFF and ORs the tail mask into the last byte.
 *
 * What closed it (wave 17, from 44 out): the byte index is the PARAMETER
 * reused, `start = start / 8;`, not a fresh local.  That is the image's
 * `asr r1, r1, #3` into start's own register, which is what rotates the
 * index/count/tail registers to r1/r3/r2; with it the then-arm zeros go in
 * the natural order `nfull = 0; tail = 0;` (the image's `mov r3, #0` /
 * `mov r2, r3`).  docs/idioms/a-dead-parameter-reused-as-the-index-rotates-the-loop-registers.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020343C0.c \
 *       --func sub_020343C0 --addr 0x020343C0 --cc 1.1p1 --arm
 */
s32 sub_020343C0(struct AreaMan *p, s32 start, u32 len)
{
    u32 bit;
    u32 avail;
    u32 nfull;
    u32 tail;
    u32 mask;
    u8 *q;
    u8 v;

    if (start + len > p->unk00) {
        return 0;
    }

    bit = start % 8;
    avail = 8 - bit;
    start = start / 8;
    if (avail >= len) {
        mask = Areaman_RunMask[len] >> bit;
        nfull = 0;
        tail = 0;
    } else {
        len = len - avail;
        mask = Areaman_TailMask[avail];
        nfull = len >> 3;
        tail = len & 7;
    }
    q = &p->bits[start];
    v = p->bits[start];
    if ((mask & v) != 0) {
        if (p->unk08 != 0) {
            func_020344C4((u8)mask);
            func_020344C4(p->bits[start]);
        }
        return 0;
    }
    start++;
    *q = v | (u8)mask;
    while (nfull-- != 0) {
        p->bits[start] = 0xFF;
        start++;
    }
    if (tail != 0) {
        p->bits[start] |= Areaman_RunMask[tail];
    }
    return 1;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * A single instruction: `bx lr`. An empty function body, kept as a real
 * entry point because it is called through a pointer field elsewhere in
 * this packet (sub_020344C8 calls it once per loop iteration).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020344C4.c \
 *       --addr 0x020344C4 --arm
 */
void sub_020344C4(void)
{
}


void func_020344C8(struct Struct_020344C8 *param)
{
    if (param->ptr != 0) {
        int i;
        for (i = 0; i < param->count; i++) {
            func_020344C4(param->data[i]);
        }
    }
}


/*
 * Guard-and-forward: calls the offset-8 field of `p` through
 * func_020344C8 only when that field is non-zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/unit_02034508.c \
 *       --func sub_02034508 --addr 0x02034508 --cc 1.1p1 --arm
 */
void sub_02034508(struct Obj02034508 *p)
{
    if (p->unk08 != 0) {
        func_020344C8((struct Struct_020344C8 *)p);
    }
}


/*
 * Sums the values of a nine-entry {flags, value} table for every entry
 * whose flag bit is set in the argument, then scales the total left by
 * 10 (`<< 0xa`).
 *
 * Every concrete byte matches; g_FlagTable has no witness anywhere else
 * in the ARM9 image, so its one ABS32 site stays unresolved under the
 * honesty rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02034520.c \
 *       --func sub_02034520 --addr 0x02034520 --cc 1.1p1 --arm
 */
u32 sub_02034520(u32 flags)
{
    u32 i;
    u32 sum = 0;

    for (i = 0; i < 9; i++) {
        if (flags & g_FlagTable[i].flag) {
            sum += g_FlagTable[i].value;
        }
    }
    return sum << 0xa;
}


/*
 * vman.c: allocate a VRAM bank record and carve its area: the flag set's
 * size less the base, divided by the row height (0x20, or the caller's
 * value when kind is 1).  The 13-byte register rotation of
 * docs/notes/func_02034558.r6.c.txt was the height LOCAL: the image stores
 * the height into the record in each arm and the divide re-reads the field
 * (`strh` then `ldrh r1, [r5, #4]`), so there is no height value to
 * allocate.  Its two callees are matched now, so nothing caps it.
 */
struct Bank *func_02034558(u16 heapId, u32 kind, u32 flags, u32 base, u32 b)
{
    struct Bank *bank;
    u32 size;

    bank = sub_02030734(heapId, 8, 0, s_clact_c, 0x7a);
    size = sub_02034520(flags) - base;
    if (kind == 1)
        bank->height = sub_020345F8(b);
    else
        bank->height = 0x20;
    bank->data = sub_02033C00(size / bank->height, heapId);
    bank->base = base;
    return bank;
}


void func_020345DC(struct Struct020345DC *obj)
{
    func_02033C9C(obj->ptr);
    sub_020307B0(obj);
}


/*
 * A five-entry linear search over g_Table1 keyed by the argument,
 * returning the matching entry of g_Table2 or a default of 0x20.
 *
 * Every concrete byte matches; neither table is referenced by any other
 * pool word or ABS32 site anywhere else in the ARM9 image, so both stay
 * unresolved under the honesty rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_020345F8.c \
 *       --func sub_020345F8 --addr 0x020345F8 --cc 1.1p1
 */
u32 sub_020345F8(u32 key)
{
    u32 i;

    for (i = 0; i < 5; i++) {
        if (g_Table1[i].key == key) {
            return g_Table2[i].key;
        }
    }
    return 0x20;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * The packet's first function, sub_020345F8 (a five-entry linear search
 * over two small tables, neither of which has a witness anywhere else in
 * the ARM9 image), matches byte for byte but keeps two wildcarded ABS32
 * sites, so it is MATCH rather than EXACT and lives at
 * src/pending/sub_020345F8.c instead of in this file.
 *
 * sub_02034630/sub_02034640 are a sentinel pair on a two-word struct:
 * sub_02034630 marks it invalid (both words 0xFFFFFFFF) and sub_02034640
 * reports whether it currently is.
 *
 * The rest of this packet (sub_02034660, sub_020346B8, sub_020346D8,
 * sub_020346EC) is a separate, non-contiguous piece of this same small
 * file; see unit_020346D8.c and unit_020346EC.c for the two of those four
 * that matched cleanly. sub_02034660 (calls sub_0209C2B0 twice and
 * sub_02033CA8) and sub_020346B8 (calls sub_0203422C then this file's own
 * sub_02034630) are left open: both reach into the array/table subsystem
 * around pkt_020339D0 whose argument shapes are not pinned down yet.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020345F8.c \
 *       --addr 0x02034630 --arm
 */
void sub_02034630(struct Sentinel *p)
{
    p->lo = 0xFFFFFFFFu;
    p->hi = 0xFFFFFFFFu;
}


int sub_02034640(struct Sentinel *p)
{
    return p->lo == 0xFFFFFFFFu && p->hi == 0xFFFFFFFFu;
}


int func_02034660(u8 *p, u32 a, void **out)
{
    u16 d = ((struct Obj11332 *)p)->f4;
    u32 q = a / d;
    u32 v;

    if (a % d != 0) {
        q++;
    }
    v = func_02033CA8((struct AreaMan *)(((struct Obj11332 *)p)->f0), q);
    if (v != (u32)-1) {
        out[0] = (void *)v;
        out[1] = (void *)q;
        return 1;
    }
    return 0;
}


/*
 * Hand a two-word handle back to the owner it came from and then invalidate
 * it in place.  The owner's first word is the object sub_0203422C works on;
 * the handle's two words are its argument pair, which is what the `ldm r4,
 * {r1, r2}` is: one aggregate read of the Sentinel that
 * src/matched/unit_02034630.c pins.
 *
 * The handle is copied into a callee-saved register before the call because
 * it is needed again afterwards for sub_02034630, and the owner load is not:
 * it is consumed by the first call and never referenced again.
 *
 * This is the function that unblocks src/matched/sub_0204A8D4.c, which is its
 * only caller image-wide and therefore had no `label` witness for the site.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020346B8.c \
 *       --func sub_020346B8 --addr 0x020346B8 --cc 1.1p1 --arm
 */
void sub_020346B8(struct Owner *owner, struct Sentinel *p)
{
    sub_0203422C(owner->unk_00, p->lo, p->hi);
    sub_02034630(p);
}


/*
 * A plain multiply-add accessor: two u16 fields of `a` combine with one
 * u32 read through `b` (itself dereferenced once) as `*b * a->unk04 +
 * a->unk06`. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/unit_020346D8.c \
 *       --func sub_020346D8 --addr 0x020346D8 --cc 1.1p1 --arm
 */
u32 sub_020346D8(struct Item020346D8 *a, u32 *b)
{
    return *b * a->unk04 + a->unk06;
}


/*
 * Stores its three call arguments into fixed offsets of a fixed global.
 * g_Sink is the same address sub_02034714 (pkt_02034714, this packet's
 * neighbour) reads back at +0xc as a callback pointer: this is the
 * "register" half of an assert/panic hook the next packet's first
 * function fires. This function only ever touches offsets 0, 4 and 8, so
 * the callback slot at +0xc is left out of the struct here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/unit_020346EC.c \
 *       --func sub_020346EC --addr 0x020346EC --cc 1.1p1 --arm
 */
void sub_020346EC(u32 a, u32 b, u32 c)
{
    g_Sink.unk8 = a;
    g_Sink.unk4 = b;
    g_Sink.unk0 = c;
}


void func_02034704(u32 v)
{
    g_Sink.handler = (AssertHandler)v;
}


/*
 * The assert/panic hook trampoline this territory's `bl 0x2034714` sites
 * all reach (see e.g. sub_02033A3C, which loads an expression string,
 * mov r1,#0x85, a file string, then calls here): if a handler is
 * registered at g_Sink+0xc (the field sub_020346EC in the neighbouring
 * packet never writes), call it. This is the forwarding-call idiom from
 * docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md
 * read in reverse: the call is `h()`, zero C-visible arguments, and it is
 * only because this function never touches r1/r2 (its own `line`/`file`
 * parameters) anywhere else that they survive, unclobbered, into the
 * callee's argument registers. Writing the call as `h(line, file)`
 * forces two `mov`s that are not in the original and breaks the match.
 * `expr`, `line` and `file` are declared to keep the prototype honest for
 * callers but are otherwise dead in this function's own body.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/unit_02034714.c \
 *       --func sub_02034714 --addr 0x02034714 --cc 1.1p1 --arm
 */
void sub_02034714(const char *expr, u32 line, const char *file)
{
    AssertHandler h = g_Sink.handler;

    if (h) {
        h();
    }
}


/*
 * The printf-shaped sibling of sub_02034714 (src/matched/unit_02034714.c):
 * byte for byte the same body, dispatching the hook at g_Sink+0xC through
 * `blx` so a Thumb handler works, wrapped in a variadic frame.
 *
 * The whole difference between the two functions is the trailing `...`.
 * A variadic function homes all four argument registers so the callee's
 * va_list has somewhere contiguous to walk, which is the leading
 * `push {r0, r1, r2, r3}` here (the same shape
 * docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md
 * describes for &param), and it is also what turns the epilogue from
 * `pop {r3, pc}` into `pop {r3, lr}` / `add sp, sp, #0x10` / `bx lr`:
 * the homed block has to be discarded before the return.  No `va_start`
 * appears because this function never reads the variadic tail itself; the
 * registered handler does.
 *
 * As in sub_02034714, the hook is called with no C-visible arguments.  The
 * named parameters survive into it only because nothing here clobbers
 * r0-r3 before the `blx`, so writing the call as `h(expr, line, file)`
 * would add `mov`s the original does not have.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02034734.c \
 *       --func sub_02034734 --addr 0x02034734 --cc 1.1p1 --arm
 */
void sub_02034734(const char *expr, u32 line, const char *file, ...)
{
    AssertHandler h = g_Sink.handler;

    if (h) {
        h();
    }
}
