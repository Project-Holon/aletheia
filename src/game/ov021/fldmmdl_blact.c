/*
 * file:     fldmmdl_blact.c
 * unit:     yes
 * function: func_0219C4AC, func_0219C52C, func_0219C554, func_0219C5D0, func_0219C5FC, func_0219C624, func_0219C630, func_0219C648, func_0219C658, func_0219C680, func_0219C6B8, func_0219C74C, func_0219C780, func_0219C7B4, func_0219C7EC, func_0219C814, func_0219C880, func_0219C8D4, func_0219C928, func_0219C98C, func_0219C9D0, func_0219C9DC, func_0219C9E0, func_0219CA00, func_0219CA34, func_0219CA40, func_0219CA6C, func_0219CA98, func_0219CAD8, func_0219CAF4, func_0219CB24, func_0219CB64, func_0219CB98, func_0219CBD4, func_0219CBE0, func_0219CC80, func_0219CCF0, func_0219CD68, func_0219CDAC, func_0219CE60, func_0219CEAC, func_0219CF00, func_0219CF54, func_0219CFB0, func_0219D064, func_0219D0F4, func_0219D144, func_0219D184, func_0219D1F8, func_0219D208, func_0219D2CC, func_0219D2F4, func_0219D324, func_0219D390, func_0219D3B4, func_0219D3E4, func_0219D3F0, func_0219D448, func_0219D488, func_0219D49C, func_0219D4AC, func_0219D4EC, func_0219D524, func_0219D558, func_0219D584, func_0219D604, func_0219D634, func_0219D680, func_0219D6B8, func_0219D6CC, func_0219D724, func_0219D738, func_0219D780, func_0219D7AC, func_0219D7D0, func_0219D7F0, func_0219D824, func_0219D85C, func_0219D8DC, func_0219D930, func_0219D990, func_0219D9D8, func_0219DA20, func_0219DA80, func_0219DAA4, func_0219DAD0, func_0219DB04, func_0219DB0C, func_0219DB44, func_0219DB48, func_0219DB5C, func_0219DBC8, func_0219DC08, func_0219DC18, func_0219DC28, func_0219DC34, func_0219DC58, func_0219DC64, func_0219DC70, func_0219DC7C, func_0219DC88, func_0219DCC4, func_0219DD18, func_0219DD24, func_0219DD34, func_0219DD44, func_0219DD54, func_0219DD64, func_0219DD74, func_0219DD84, func_0219DD94, func_0219DDA4, func_0219DDB4, func_0219DDC4, func_0219DDD4, func_0219DDE4, func_0219DDF4, func_0219DE04, func_0219DE14, func_0219DE24, func_0219DE34, func_0219DE44, func_0219DE54, func_0219DE64, func_0219DE98, func_0219DECC, func_0219DEDC, func_0219DEEC, func_0219DEFC, func_0219DF0C, func_0219DF1C, func_0219DF2C, func_0219DF3C, func_0219DF4C, func_0219DF5C, func_0219DF6C, func_0219DF7C, func_0219DF8C, func_0219DF9C, func_0219DFAC, func_0219DFBC, func_0219DFCC, func_0219DFDC, func_0219DFEC, func_0219DFFC, func_0219E00C, func_0219E084, func_0219E0A8, func_0219E1B0, func_0219E1D0, func_0219E1F4, func_0219E218, func_0219E238, func_0219E258, func_0219E27C, func_0219E29C, func_0219E2C0, func_0219E2F4, func_0219E334, func_0219E348, func_0219E354, func_0219E370, func_0219E398, func_0219E418, func_0219E424, func_0219E498, func_0219E570, func_0219E634, func_0219E664, func_0219E6C8, func_0219E764, func_0219E784, func_0219E828, func_0219E834, func_0219E844, func_0219E854, func_0219E938, func_0219E940, func_0219E968, func_0219E9A8, func_0219E9F8, func_0219EA10, func_0219EA24, func_0219EA40, func_0219EA5C, func_0219EA78, func_0219EA94, func_0219EAB8, func_0219EAD8, func_0219EAEC, func_0219EB18, func_0219EB4C, func_0219EB90, func_0219EBA0, func_0219EBF4, func_0219ED7C, func_0219ED8C, func_0219EDC4, func_0219EF04, func_0219EF14, func_0219EF44, func_0219EF6C, func_0219EF7C, func_0219EFFC, func_0219F018, func_0219F01C, func_0219F030, func_0219F048, func_0219F04C, func_0219F050, func_0219F054
 * address:  0x0219C4AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02046FF8  0x02046FF8  arm
 *   func_02050080  0x02050080  arm
 *   func_02047388  0x02047388  arm
 *   func_020473B8  0x020473B8  arm
 *   func_0204F044  0x0204F044  arm
 *   func_02050238  0x02050238  arm
 *   func_02046EFC  0x02046EFC  arm
 *   d_021D75C4     0x021D75C4  data  a4
 *   d_021D8064     0x021D8064  data  a4
 *   func_02050330  0x02050330  arm
 *   func_02050304  0x02050304  arm
 *   func_0204F214  0x0204F214  arm
 *   func_0216D4F8  0x0216D4F8  thumb  ov010
 *   sub_02030734   0x02030734  arm
 *   func_0216D51C  0x0216D51C  thumb  ov010
 *   func_0204ED70  0x0204ED70  arm
 *   func_0204EDB0  0x0204EDB0  arm
 *   d_021DDD70     0x021DDD70  data  a1
 *   d_021D8058     0x021D8058  data  a4
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216E2E8  0x0216E2E8  thumb  ov010
 *   func_0216E2E0  0x0216E2E0  thumb  ov010
 *   func_0216E2AC  0x0216E2AC  thumb  ov010
 *   func_02050340  0x02050340  arm
 *   func_02050804  0x02050804  arm
 *   func_0205082C  0x0205082C  arm
 *   func_020507F0  0x020507F0  arm
 *   d_021D75D0     0x021D75D0  data  a4
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_02050894  0x02050894  arm
 *   func_020508D8  0x020508D8  arm
 *   func_02050278  0x02050278  arm
 *   func_0216DFC4  0x0216DFC4  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_02050468  0x02050468  arm
 *   func_02030734  0x02030734  arm
 *   func_0216E3C8  0x0216E3C8  thumb  ov010
 *   func_0216D518  0x0216D518  thumb  ov010
 *   func_02046E24  0x02046E24  arm
 *   func_0216D4F0  0x0216D4F0  thumb  ov010
 *   func_0216D758  0x0216D758  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216E204  0x0216E204  thumb  ov010
 *   func_0216DA30  0x0216DA30  thumb  ov010
 *   d_021D7F68  0x021D7F68  data  ov021
 *   func_020500F0  0x020500F0  arm
 *   func_0216D524  0x0216D524  thumb  ov010
 *   d_021DDD80     0x021DDD80  data ov021 a4
 *   func_0216D528  0x0216D528  thumb  ov010
 *   func_021C6580  0x021C6580  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_0216E3CC  0x0216E3CC  thumb  ov010
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021C6628  0x021C6628  thumb  ov021
 *   func_0216D6F4  0x0216D6F4  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_0216DA20  0x0216DA20  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_02197EB4  0x02197EB4  thumb  ov021
 *   func_0216DB10  0x0216DB10  thumb  ov010
 *   func_0216D708  0x0216D708  thumb  ov010
 *   func_0216D530  0x0216D530  thumb
 *   func_021BB3C4  0x021BB3C4  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0207CDB8  0x0207CDB8  arm
 *   func_0207CFB8  0x0207CFB8  arm
 *   d_021D80E4     0x021D80E4  data   ov021  a1
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216DA70  0x0216DA70  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216DCB4  0x0216DCB4  thumb  ov010
 *   func_0216D7E0  0x0216D7E0  thumb  ov010
 *   func_0216D7D8  0x0216D7D8  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216DB24  0x0216DB24  thumb  ov010
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_0216D7E4  0x0216D7E4  thumb  ov010
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_021AC760  0x021AC760  thumb  ov021
 *   func_021BBDD4  0x021BBDD4  thumb  ov021
 *   func_0216D98C  0x0216D98C  thumb  ov010
 *   func_021AC2C0  0x021AC2C0  thumb  ov021
 *   func_021AC578  0x021AC578  thumb  ov021
 *   func_0216DC34  0x0216DC34  thumb  ov010
 *   func_02163F40  0x02163F40  thumb  ov010
 *   func_0216DC18  0x0216DC18  thumb  ov010
 *   func_021BBFB8  0x021BBFB8  thumb  ov021
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_0216D7CC  0x0216D7CC  thumb
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_021B8028  0x021B8028  thumb  ov021
 *   func_021B8040  0x021B8040  thumb  ov021
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   d_021DDD94     0x021DDD94  data
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_021B7EE4  0x021B7EE4  thumb  ov021
 *   func_021B7DC0  0x021B7DC0  thumb
 *   func_021B7E60  0x021B7E60  thumb
 *   func_021B8038  0x021B8038  thumb
 *   func_021BB480  0x021BB480  thumb
 *   func_021B810C  0x021B810C  thumb  ov021
 *   func_021B80E0  0x021B80E0  thumb  ov021
 *   func_021B7DE0  0x021B7DE0  thumb  ov021
 *   func_021B7CD8  0x021B7CD8  thumb  ov021
 *   func_021B7D38  0x021B7D38  thumb  ov021
 *   func_021B7C38  0x021B7C38  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_021B7ED4  0x021B7ED4  thumb  ov021
 *   func_021B83B0  0x021B83B0  thumb  ov021
 *   func_0201441C  0x0201441C  thumb
 *   func_021B7C90  0x021B7C90  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D80C  0x0216D80C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D818  0x0216D818  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D824  0x0216D824  thumb  ov010
 *   func_0216D844  0x0216D844  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D874  0x0216D874  thumb  ov010
 *   func_021B8050  0x021B8050  thumb  ov021
 *   func_021B80D8  0x021B80D8  thumb  ov021
 *   func_0207AF1C  0x0207AF1C  thumb
 *   func_0207B51C  0x0207B51C  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   d_021D84D4     0x021D84D4  data  ov021  a1
 *   d_021D841C     0x021D841C  data  ov021  a2
 *   d_020A1B38     0x020A1B38  data  a2
 *   func_02164380  0x02164380  thumb  ov010
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0216D660  0x0216D660  thumb  ov010
 *   func_0216D66C  0x0216D66C  thumb  ov010
 *   func_020056EC  0x020056EC  thumb
 *   d_021D84E8  0x021D84E8  data
 *   func_021BB394  0x021BB394  thumb  ov021
 *   func_021BB3A0  0x021BB3A0  thumb  ov021
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb  ov010
 *   d_021D84AC     0x021D84AC  data
 *   func_0216DA7C  0x0216DA7C  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216DA44  0x0216DA44  thumb  ov010
 *   func_0216D5D4  0x0216D5D4  thumb  ov010
 *   func_021642A4  0x021642A4  thumb  ov010
 *   func_0216D608  0x0216D608  thumb  ov010
 *   d_021DDDB8     0x021DDDB8  data
 *   d_021DDDA0     0x021DDDA0  data
 *   d_021DDDAC     0x021DDDAC  data
 *   d_021DDE08     0x021DDE08  data
 *   func_0204A298  0x0204A298  arm
 *   func_0209C2B0  0x0209C2B0  arm
 *   func_02158768  0x02158768  thumb  ov010
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 */
#include "../../matched/include/Obj03116.h"
#include "../../matched/include/Obj03579.h"
#include "../../matched/include/Obj17967.h"
#include "../../matched/include/Obj07474.h"
#include "../../matched/include/Obj00429.h"
#include "../../matched/include/Obj03118.h"
#include "../../matched/include/Obj09509.h"
#include "../../matched/include/Obj17968.h"
#include "../../matched/include/Obj17969.h"
#include "../../matched/include/Obj17970.h"
#include "../../matched/include/Obj19659.h"
#include "../../matched/include/Obj02077.h"
#include "../../matched/include/Obj02698.h"
#include "../../matched/include/Obj04225.h"
#include "../../matched/include/Obj06000.h"
#include "../../matched/include/Obj19662.h"
#include "../../matched/include/Obj12672.h"
#include "../../matched/include/Obj04224.h"
#include "../../matched/include/Obj05011.h"
#include "../../matched/include/Obj19665.h"
#include "../../matched/include/Obj03580.h"
#include "../../matched/include/Obj12673.h"
#include "../../matched/include/Obj03117.h"
#include "../../matched/include/Obj07477.h"
#include "../../matched/include/Obj09512.h"
#include "../../matched/include/Obj12675.h"
#include "../../matched/include/Obj06001.h"
#include "../../matched/include/Obj12676.h"
#include "../../matched/include/Obj01353.h"
#include "../../matched/include/Obj00808.h"
#include "../../matched/include/Obj07478.h"
#include "../../matched/include/Obj02699.h"
#include "../../matched/include/Obj03119.h"
#include "../../matched/include/Obj02700.h"
#include "../../matched/include/Obj04226.h"
#include "../../matched/include/Obj17972.h"
#include "../../matched/include/Obj06002.h"
#include "../../matched/include/Obj09515.h"
#include "../../matched/include/Obj09517.h"
#include "../../matched/include/Obj07479.h"
#include "../../matched/include/Obj05013.h"
#include "../../matched/include/Obj17973.h"
#include "../../matched/include/Obj17975.h"
#include "../../matched/include/Obj12077.h"
#include "../../matched/include/Obj17976.h"
#include "../../matched/include/Obj07482.h"
#include "../../matched/include/Obj12689.h"
#include "../../matched/include/Obj05014.h"
#include "../../matched/include/Obj09178.h"

struct Board;
struct Layer;
struct Tagged;
struct Blk3;
struct Record;
struct BbActDesc;
struct BbActSys;
struct BbActRec;
struct Sub;
struct Ctx;
struct Rec;
struct Mgr;
struct Desc;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed char    s8;

typedef struct { u32 a, b, c; } T12;

typedef struct { int x, y, z; } V3_0219C4AC;

typedef struct {
    u16 slot;
    u16 v12;
    u16 v14;
    u8 k;
    u8 pad;
    u32 flag;
    u32 w;
    V3_0219C4AC pos;
    void (*f1c)(u32, u32, u8 *);
    u32 f20;
} Desc;

typedef signed int     s32;

typedef struct { u16 a; u16 b; u16 c; u16 pad; } Ent;

typedef struct { int n; Ent *e; } Tbl;

typedef struct { int f0; int f4; u8 pad8[0xc]; Tbl tbl; } BlactSys;

typedef struct { u16 id; u8 pad[5]; u8 f7; u8 f8; } D;

typedef struct { u16 id; u8 pad[10]; } A;

typedef struct { u8 pad[16]; u32 f10; } B;

typedef struct { u32 f0; u8 pad[12]; u32 f10; u8 pad2[20]; } C;

typedef struct { u8 pad[4]; u16 n0; u16 n1; u16 n2; u16 pad2; A *a; B *b; C *c; } R;

typedef struct {
    u16 x, y, w, h;
} Rect;

typedef struct {
    u32 head;
    Rect r;
} Obj;

typedef struct { int a; int b; int c; } S3;

typedef struct { u32 p; u16 id; u16 pad; u32 x; } Slot;

typedef struct { u16 a; u16 b; } E4;

typedef int BOOL;

typedef struct {
    u16 a;
    u16 b;
    s16 c;
    u16 d;
    u16 e;
    u16 f;
} S_0219C4AC;

typedef struct {
    s32 x, y, z;
} V3_0219E084;

typedef struct {
    s32 speed;
    s32 acc;
    u16 step;
    u16 pos;
    s8 id;
    s8 count;
    s8 f0e;
    s8 table;
} E_0219C4AC;

typedef signed long long s64;

typedef struct {
    u32 pad0;
    s16 lx;
    u16 ly;
} L;

typedef struct { int key; int val; } Entry;

typedef struct {
    u8  pad[0xc];
    s16 cnt;
    u16 val;
} E_0219EB4C;

typedef struct {
    u8 pad[0xc];
    u8 lo : 4;
    u8 hi : 4;
    u8 z;
    u8 c;
    u8 d;
} E_0219EBA0;

typedef struct {
    u16 a;
    u16 pad;
    s16 c;
    u16 d;
} S_0219EAD8;

typedef struct {
    u8  pad[0xc];
    u8  state : 4;
    u8  hi : 4;
    s8  cnt;
    s8  e;
    u8  f;
} E_0219EAD8;

typedef struct {
    u16 f0;
    u16 f2;
    s16 f4;
    u16 f6;
} Pos;

typedef struct {
    u16 a;
    u16 b;
    s16 c;
    u16 d;
} T;

typedef struct {
    u8  pad[0xc];
    u8  state;
    u8  d;
    s8  e;
    u8  f;
} E;

struct S {
    u32 *f0;
    u32 f4;
    u16 h8;
    u16 hA;
    u16 hC;
    u16 hE;
    u8  pad10[8];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u8  pad28[12];
    u32 f34;
};

extern int func_02046FF8(int *self);
extern u32 func_02050080(u32 *p);
extern u32 func_02047388(struct Layer *layer);
extern u32 func_020473B8(struct Layer *layer);
extern int func_0204F044(struct Board *b, int w, int h, int a3, u32 a4, u8 a5, u8 a6);
extern u32 func_02050238(void *p, u32 b, u32 c);
extern void func_02046EFC(struct Tagged *p);
extern u16 func_02050330(u8 *p, int i);
extern int func_02050304(int a0, int a1);
extern void func_0204F214(u8 *a0, int i);
extern u32 func_0216D4F8(u8 *p);
extern void *sub_02030734(u32, u32, int, const char *, u16);
extern void func_0216D51C(u8 *p, u32 v);
extern void func_0204ED70(u8 *dst, struct Blk3 *src);
extern void func_0204EDB0(u8 *dst, u8 *src);
extern u32 func_0216D520(void *p);
extern u32 func_020307B0(void *p);
extern void *func_0216D67C(void *a0);
extern void func_0216E2E8(const char *ctx, u32 id, struct Record *out);
extern u16 func_0216E2E0(void *p);
extern void func_0216E2AC(u32, int, u8 *);
extern u16 func_02050340(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern void func_02050804(void *p, int idx, u32 v, u16 h);
extern void func_0205082C(void *p, int idx, u32 h);
extern void func_020507F0(void *p, int idx, u32 v);
extern void *func_0216E3C4(void *p);
extern void func_02197CCC(u8 *p, s32 *out);
extern int func_02050894(void *p, int idx, int j);
extern u32 func_020508D8(u8 *o, u32 i);
extern void func_02050278(struct BbActSys *o, u32 first, u32 count);
extern int func_0216DFC4(void *a, u32 id);
extern u16 func_0216D598(void *p);
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void *func_0216E3C8(void *p);
extern u32 func_0216D518(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern u16 func_0216D4F0(void *p);
extern void func_0216D758(void *a0);
extern void func_02082BCC(u8 *p, u32 a, u32 b);
extern int func_0216D7A8(void *p, unsigned int v);
extern void func_0216E204(char *a, u32 v);
extern int func_0216DA30(int a0, int a1);
extern u16 func_020500F0(struct BbActSys *o, const struct BbActRec *recs, u32 n);
extern void func_0216D524(void *p, void *v);
extern u32 func_0216D528(u8 *p);
extern void func_021C6580(u8 *p, int i);
extern void func_021C6AE0(u32 a);
extern void func_021C6AF0(u32 *, u32, u16);
extern void func_021C6AF8(u32 *p, u32 v);
extern void func_021C6AFC(u32 *, u16);
extern u32 func_021C6574(u32, u32 *, u32);
extern u8 *func_0216E3CC(u8 *p);
extern u32 func_021C6590(u32, u32, u32, u32);
extern void func_021C6628(u32, u32);
extern u32 *func_0216D548(u32 *p, u32 v);
extern void func_0216D6F4(void *a0);
extern int func_0216DA20(void *p, unsigned int v);
extern u32 func_0216D57C(void *p, u32 v);
extern void func_02197EB4(u32);
extern int func_0216DB10(void *a0);
extern void func_0216D708(void *a0);
extern void *func_0216D530(void *p);
extern u32 func_021BB3C4(u8 *p, char *a1);
extern u16 func_0216D5F8(void *p);
extern void func_0207CDB8(s16 *, s16 *);
extern int func_0207CFB8(int, int);
extern int func_0216DA5C(void *a0);
extern u16 func_0216D5A0(void *p);
extern void func_0216DA70(void *a0);
extern char *func_0216D570(char *p, u32 v);
extern int func_0216DCB4(void *a0);
extern void func_0216D7E0(void *p, u32 v);
extern void func_0216D7D8(void *p, u32 v);
extern void *func_0216D568(void *p, u32 v);
extern int func_0216DB24(int a0);
extern u32 func_0216D7DC(void *p);
extern u32 func_0216D7E4(void *p);
extern u16 func_021AB0F8(u32 attr);
extern void func_021AC760(u32 a, u32 b, u32 c, int d);
extern void func_021BBDD4(int a, int b, int c);
extern int func_0216D98C(int a0);
extern void func_021AC2C0(u32, u32);
extern u32 func_021AC578(u32, u32);
extern int func_0216DC34(void *a0);
extern int func_02163F40(int a, int dir);
extern int func_0216DC18(void *a0, int a1);
extern void func_021BBFB8(u32, u32, u32, u32);
extern u32 func_0216D534(void *p);
extern u32 func_02188CD0(u8 *p);
extern void func_0216D7CC(u8 *p);
extern int func_02163F10(int a0);
extern void func_0216D5E0(int a0, int a1);
extern void func_0216D674(void *p, u16 v);
extern void func_0216D60C(u32, u16);
extern void func_021B8028();
extern u8 func_021B8040(u8 *p);
extern void func_0216D89C();
extern void *func_0216D6BC(int a0, int a1, int a2);
extern void *func_0216D6D4(void *p);
extern void func_020061E4(u32 a);
extern void func_0216D8C0(u32, V3_0219E084 *);
extern void *func_0216D69C(void *);
extern void func_021B7EE4(void *p, void *r);
extern void *func_021BB480(void *p);
extern u8 func_021B8038(u8 *p);
extern int func_021B7E60(void *p, u32 a, void *out, void *b);
extern u32 func_021B7DC0(void *p, void *out);
extern void func_021B810C(struct Sub *o);
extern void func_021B80E0(void *p, u32 a, u32 b);
extern int func_021B7DE0();
extern int func_021B7CD8();
extern void func_021B7D38();
extern int func_021B7C38(u8 *o);
extern u32 func_0207C768(u32 a, u32 b);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern int func_0216D55C(int a0, int a1);
extern void func_021B7ED4();
extern int func_021B83B0(const s32 *a, const s32 *b, s32 r);
extern u8 func_0201441C(int i);
extern int func_021B7C90(struct Mgr *m, void *r, void *key, void *q);
extern int func_0216D83C(void *p);
extern void func_0216D80C();
extern int func_0216D854(void *p);
extern void func_0216D818();
extern int func_0216D86C(void *p);
extern void func_0216D824();
extern void func_0216D844(void *p, short v);
extern void func_0216D85C(void *p, int v);
extern void func_0216D874(int a0, int a1);
extern void func_021B8050(struct Sub *o, s16 *out);
extern u32 func_021B80D8(u8 *p);
extern void func_0207AF1C();
extern void func_0207B51C();
extern void func_0207CCA4();
extern int func_02164380(void *a, u16 *b);
extern void *func_0216D684(u32, u32);
extern int func_0216D660(void *p);
extern int func_0216D66C(void *p);
extern u32 func_020056EC(u32);
extern u32 func_021BB394(u8 *p);
extern u32 *func_0216D550(u32 *p, u32 v);
extern void func_021BB3A0(u8 *p, u32 a1);
extern void func_0216DA50(u8 *p);
extern void func_0216DA7C(u8 *p);
extern int func_02197E7C(int a, int b);
extern void func_0216D438(char *a0, int a1);
extern u32 func_02197EDC(u8 *p);
extern void func_0216DA44(u32);
extern int func_0216D5D4(void *p);
extern u16 func_021642A4(int i);
extern u16 func_0216D608(void *p);
extern int func_0204A298(int a0, int a1, int a2, int a3, u32 *out);
extern u32 func_0209C2B0(u32, u32);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
int func_0219C4AC(u32 a, u32 b, u32 c, u32 d);
void func_0219C52C(u32 a, u32 b);
void func_0219C554(u32 a, u32 b, u32 c);
void func_0219C5D0(u32 a);
void func_0219C5FC(u32 a);
int func_0219C624(void *p);
int func_0219C630(void *p);
int func_0219C648(u32 a);
void func_0219C658(u32 a, u32 b);
void func_0219C680(u32 a);
u32 func_0219C6B8(u32 a, V3_0219C4AC *b, int c, u32 d, u16 e);
u32 func_0219C74C(u32 a, u16 e);
u32 func_0219C780(u32 a, V3_0219C4AC *b, int c, u32 d, u16 e, u16 g);
u32 func_0219C7B4(u32 a, u16 e, u16 g);
u32 func_0219C7EC(u32 a, u32 b);
int func_0219C814(u32 a, u16 *b);
void func_0219C880(u8 *o, u32 a, u32 b, u16 c);
void func_0219C8D4(u32 o, u32 a);
int func_0219C928(u32 a, const u8 *b, u16 *c, V3_0219C4AC *d, u32 s0, u32 s1);
void func_0219C98C(u32 a, u16 *b);
void func_0219C9D0(u32 a, u32 b, u8 *p);
u32 func_0219C9DC(u8 *p);
void func_0219C9E0(u32 a, u16 *x, u16 *y);
void func_0219CA00(u32 *s, u32 n, u32 heap);
void func_0219CA34(u8 *p);
void func_0219CA40(Tbl *t, u16 a, u16 b, u16 c);
void func_0219CA6C(Tbl *t, u16 k);
int func_0219CA98(u32 *o, u32 key, u16 *a, u16 *b);
void func_0219CAD8(u8 *a, u32 b);
void func_0219CAF4(BlactSys *s);
void func_0219CB24(BlactSys *o, u32 a, u16 b, u32 c, u8 s0, u32 s1);
void func_0219CB64(u8 *s, const D *d, u32 g);
void func_0219CB98(BlactSys *s, u16 k);
int func_0219CBD4(u32 a, u32 b, u32 c, u32 d);
void func_0219CBE0(u8 *o);
void func_0219CC80(u8 *o);
int func_0219CCF0(u8 *s);
void func_0219CD68(u8 *o, u16 a, u8 b, u8 c, u16 d, u32 e);
void func_0219CDAC(u8 *o);
int func_0219CE60(u8 *o, u32 a, u32 b, u32 c, u16 e, u32 w);
void func_0219CEAC(int *obj);
int func_0219CF00(int *t, unsigned int id, unsigned short *out);
int func_0219CF54(int *t, unsigned int id);
void func_0219CFB0(int *obj, int a1, unsigned char *src, int a3, int a5, int a6, S3 *a7);
typedef struct BlactEntry {
    u16 *res;
    int f4;
    u16 f8;
    u8 fA;
    u8 fB;
    u8 fC;
    u8 fD;
    u8 pad_E[2];
    int f10;
    void (*f14)(u32, int);
    int f18;
    V3_0219C4AC pos;
} BlactEntry;

void func_0219D064(int *obj, BlactEntry *rec);
void func_0219D0F4(int *obj);
int func_0219D144(int *obj, unsigned int a, int b);
void func_0219D184(int *obj, int key);
void func_0219D1F8(u8 *p);
void func_0219D208(int a, unsigned int id);
void func_0219D2CC(int *obj);
void func_0219D2F4(u8 *s);
void func_0219D324(int *obj, int *rec);
void func_0219D390(u8 *s);
int func_0219D3B4(u8 *s, u32 p, u16 id);
char *func_0219D3E4(int i);
unsigned short func_0219D3F0(int *o, int a1, int a2, int a3, int a4, int a5);
void func_0219D448(int a, int b);
void func_0219D488(u32 a);
u32 func_0219D49C(u32 a);
void func_0219D4AC(int *obj, int a);
void func_0219D4EC(u8 *s);
u16 func_0219D524(u32 *s, u32 b, u32 a);
u16 func_0219D558(u8 *s, u16 k);
u32 func_0219D584(u32 a, u32 *b, u32 c, u16 *d);
void func_0219D604(u8 *s, u16 k);
u32 func_0219D634(u32 a);
void func_0219D680(u32 a, u32 b);
int func_0219D6B8(u32 *a, u32 b, u32 c, u32 d);
void func_0219D6CC(u32 a);
int func_0219D724(u32 a, char *b);
u32 func_0219D738(u32 a, int b);
int func_0219D780(u32 a);
void func_0219D7AC(u32 a);
void func_0219D7D0(u32 a);
void func_0219D7F0(u32 a);
void func_0219D824(u32 a);
u32 func_0219D85C(u32 a);
void func_0219D8DC(void *a);
void func_0219D930(void *a);
void func_0219D990(void *a);
void func_0219D9D8(void *a);
void func_0219DA20(void *a);
void func_0219DA80(u32 a, u32 b, u32 a2, u32 a3);
void func_0219DAA4(u32 a, u32 b, u32 a2, u32 a3);
void func_0219DAD0(u32 a, u32 x, u32 b, u8 *p);
void func_0219DB04(u32 a, u32 b, u32 c, u32 d);
void func_0219DB0C(u32 a, u32 a1, u32 a2, u32 a3);
void func_0219DB44(u32 a0, u32 a1, u32 a2, u32 a3);
int func_0219DB48(u32 a, u32 b, u32 c, u32 d);
void func_0219DB5C(void *a, u32 b, u32 c, u8 *d);
void func_0219DBC8(void *a, u32 b, u32 c, u8 *d);
int func_0219DC08(u32 a);
int func_0219DC18(u32 a, u32 b, u32 c, u32 d);
int func_0219DC28(u8 *a);
void func_0219DC34(u32 a, u32 b);
u32 func_0219DC58(u32 a1);
u32 func_0219DC64(u32 a1);
u32 func_0219DC70(u32 a1);
u32 func_0219DC7C(u32 a1);
void func_0219DC88(u32 a, u32 b, u32 c, u16 d);
int func_0219DCC4(u32 o);
int func_0219DD18(u32 a, u32 b, u32 c, u32 d);
u32 func_0219DD24(u32 a1);
u32 func_0219DD34(u32 a1);
u32 func_0219DD44(u32 a1);
u32 func_0219DD54(u32 a1);
u32 func_0219DD64(u32 a1);
u32 func_0219DD74(u32 a1);
u32 func_0219DD84(u32 a1);
u32 func_0219DD94(u32 a1);
u32 func_0219DDA4(u32 a1);
u32 func_0219DDB4(u32 a1);
u32 func_0219DDC4(u32 a1);
u32 func_0219DDD4(u32 a1);
u32 func_0219DDE4(u32 a1);
u32 func_0219DDF4(u32 a1);
u32 func_0219DE04(u32 a1);
u32 func_0219DE14(u32 a1);
u32 func_0219DE24(u32 a1);
u32 func_0219DE34(u32 a1);
u32 func_0219DE44(u32 a1);
u32 func_0219DE54(u32 a1);
void func_0219DE64(u32 a, u32 b, u16 c, u16 d);
int func_0219DE98(u32 a);
u32 func_0219DECC(u32 a1);
u32 func_0219DEDC(u32 a1);
u32 func_0219DEEC(u32 a1);
u32 func_0219DEFC(u32 a1);
u32 func_0219DF0C(u32 a1);
u32 func_0219DF1C(u32 a1);
u32 func_0219DF2C(u32 a1);
u32 func_0219DF3C(u32 a1);
u32 func_0219DF4C(u32 a1);
u32 func_0219DF5C(u32 a1);
u32 func_0219DF6C(u32 a1);
u32 func_0219DF7C(u32 a1);
u32 func_0219DF8C(u32 a1);
u32 func_0219DF9C(u32 a1);
u32 func_0219DFAC(u32 a1);
u32 func_0219DFBC(u32 a1);
u32 func_0219DFCC(u32 a1);
u32 func_0219DFDC(u32 a1);
u32 func_0219DFEC(u32 a1);
u32 func_0219DFFC(u32 a1);
void func_0219E00C(u32 o, u32 id, u32 p, u8 q, u16 sa, s16 sc, u16 se, u32 fn);
void func_0219E084(u32 a, u32 b, u32 c, u8 d, u16 e, s16 f, u16 g);
int func_0219E0A8(u32 o);
int func_0219E1B0(u32 a);
int func_0219E1D0(u32 a);
int func_0219E1F4(u32 a);
int func_0219E218(u32 a);
int func_0219E238(u32 a);
int func_0219E258(u32 a);
int func_0219E27C(u32 a);
int func_0219E29C(u32 a);
void func_0219E2C0(void *a, void *r);
void func_0219E2F4(void *o, void *out);
int func_0219E334(u32 a, u32 b);
void *func_0219E348(void *a);
void func_0219E354(u32 a);
void func_0219E370(u32 a, u32 b, u32 c);
u32 func_0219E398(u32 o, u32 a, char *b, u32 *out);
int func_0219E418(u32 a, u16 b);
int func_0219E424(u32 o, u32 k, u32 x);
int func_0219E498(u32 o, u32 k);
u32 func_0219E570(u32 o, u32 k, u32 flag);
int func_0219E634(void *a, void *b);
int func_0219E664(void *o, u32 k, void *buf);
void func_0219E6C8(u32 o, u16 id);
void func_0219E764(u32 a, s16 *b);
void func_0219E784(u32 o, u32 idx, s16 *v);
void *func_0219E828(u32 a);
void func_0219E834(u32 a, u32 b, u32 c, u32 d);
int func_0219E844(u32 *a, u32 b, u32 c, u32 d);
void func_0219E854(u32 o);
void func_0219E864(u32 o);
void func_0219E870(u32 o);
void func_0219E87C(u32 o);
void func_0219E888(u32 o);
void func_0219E894(u32 o);
void func_0219E8A0(u32 o);
void func_0219E8AC(u32 o);
void func_0219E8B8(u32 o);
void func_0219E8C4(u32 o);
void func_0219E8D0(u32 o);
void func_0219E8DC(u32 o);
int func_0219E8E8(u32 o);
int func_0219E8F0(u32 *o);
void func_0219E8F8(u32 o);
void func_0219E904(u32 o);
int func_0219E910(u32 o);
int func_0219E918(u32 *o);
void func_0219E920(u32 o);
int func_0219E928(u32 o);
int func_0219E930(u32 *o);
u32 func_0219E938(int a0);
u32 func_0219E940(int x);
void *func_0219E968(u32 a, u32 size);
int func_0219E9A8(u32 o, int a, int b, L *l);
int func_0219E9F8(u32 *arr, u32 v);
int func_0219EA10(u32 *a, int b);
u32 func_0219EA24(u32 a, u32 b);
int func_0219EA40(int key);
int func_0219EA5C(void *a, u32 b);
void func_0219EA78(Obj *p, u32 a1);
u32 func_0219EA94(u32 a, u32 *b);
void func_0219EAB8(u32 a, u32 b);
void func_0219EAD8(Obj *p, const Rect *s);
void func_0219EAEC(u8 *p, u32 a);
void func_0219EB18(u32 a, u16 b);
int func_0219EB4C(u32 o);
int func_0219EB90(u32 *a);
void func_0219EBA0(u32 o, u32 k);
int func_0219EBF4(u32 o);
int func_0219ED7C(u32 *a);
void func_0219ED8C(u32 a);
int func_0219EDC4(u32 o);
int func_0219EF04(u32 *a);
void func_0219EF14(u8 *p);
u8 *func_0219EF44(u32 heap);
void func_0219EF6C(u8 *p);
void func_0219EF7C(struct S *p, u32 b, u32 c);
void func_0219EFFC(u8 *a);
u8 *func_0219F018(u8 *p);
int func_0219F01C(u32 a, u32 b, u32 c, u32 e0, u32 e1, u16 id);
int func_0219F030(void *a, u32 b, u32 c, u32 d);
void func_0219F048(void);
void func_0219F04C(void);
void func_0219F050(void);
void func_0219F054(void);
extern u16 d_021D75C4[][2];
extern u16 d_021D8064[];
extern unsigned char d_021DDD70[];
extern T12 d_021D8058;
extern u16 d_021D75D0[][2];
extern char d_021D7F68[];
extern unsigned char d_021DDD80[];
extern u8 d_021D80E4[];
extern s32 *d_021DDD94[];
extern u8  d_021D84D4[][4];
extern u16 d_021D841C[];
extern s16 d_020A1B38[];
extern Entry d_021D84E8[];
extern u32 d_021D84AC[];
extern char d_021DDDB8[];
extern char d_021DDDA0[];
extern char d_021DDDAC[];
extern char d_021DDE08[];
















/*
 * Former blocker (now filed in src/matched/arm9): func_02050080 (0x02050080) is an unlabelled arm9 leaf with no witness
 * outside this range (Ilias's). Verified C, EXACT under --arm --region arm9:
 *     u32 func_02050080(u32 *p) { return p[1]; }
 */
int func_0219C4AC(u32 a, u32 b, u32 c, u32 d)
{
    int r = -1;
    if (func_02046FF8((int *)b) == 1) {
        u32 x = func_02050080((u32 *)a);
        u16 *e = d_021D75C4[c];
        u32 w = func_02047388((struct Layer *)b);
        r = func_02050238((void *)a, func_0204F044((struct Board *)x, w, func_020473B8((struct Layer *)b), 0, d_021D8064[d], (u8)e[0], (u8)e[1]), 0);
        func_02046EFC((struct Tagged *)b);
    }
    return r;
}
















void func_0219C52C(u32 a, u32 b)
{
    u32 x = func_02050330((u8 *)a, b);
    u32 y = func_02050080((u32 *)a);
    func_02050304(a, b);
    func_0204F214((u8 *)y, x);
}
















void func_0219C554(u32 a, u32 b, u32 c)
{
    u8 *p = sub_02030734(func_0216D4F8((u8 *)a), 0x24, 1, (const char *)d_021DDD70, 360);
    u32 h;
    T12 t;
    u8 z;
    ((struct Obj03116 *)p)->f10 = a;
    ((struct Obj03116 *)p)->f4 = b;
    ((struct Obj03116 *)p)->f2 = c;
    func_0216D51C((u8 *)a, (u32)p);
    func_0219CAD8(p, c);
    func_0219CBE0(p);
    func_0219D2CC((int *)p);
    h = func_02050080((u32 *)b);
    t = d_021D8058;
    func_0204ED70((u8 *)h, (struct Blk3 *)(&t));
    z = 0;
    func_0204EDB0((u8 *)h, &z);
}
















void func_0219C5D0(u32 a)
{
    u32 s = func_0216D520((void *)a);
    func_0219D2F4((u8 *)s);
    func_0219CC80((u8 *)s);
    func_0219CAF4((BlactSys *)s);
    func_020307B0((void *)s);
    func_0216D51C((u8 *)a, 0);
}
















void func_0219C5FC(u32 a)
{
    u8 *s = (u8 *)func_0216D520((void *)a);
    if (s != 0) {
        if (*(u32 *)&((struct Obj03579 *)s)->f1C != 0) {
            func_0219D0F4((int *)s);
            func_0219CDAC(s);
        }
        func_0219D390(s);
        s[0] = 0;
    }
}
















/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219C624(void *p)
{
func_0219CEAC((int *)func_0216D520(p));
}
















int func_0219C630(void *p)
{
if (func_0219CCF0((u8 *)func_0216D520(p)) == 1) {
    return 1;
}
return 0;
}
















int func_0219C648(u32 a)
{
return ((struct Obj17967 *)((u8 *)(func_0216D520(func_0216D67C((void *)a)))))->f0;
}
















void func_0219C658(u32 a, u32 b)
{
    u8 buf[28];
    u8 *s = (u8 *)func_0216D520((void *)a);
    func_0216E2E8((const char *)a, b, (struct Record *)buf);
    func_0219CB64(s, (const D *)buf, 0);
}
















/*
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 */
void func_0219C680(u32 a)
{
    u8 buf[28];
    u8 *s = (u8 *)func_0216D520((void *)a);
    int n = func_0216E2E0((void *)a);
    int i;
    for (i = 0; i < n; i++) {
        func_0216E2AC(a, i, buf);
        func_0219CB64(s, (const D *)buf, 0);
    }
}
















/*
 * Former blocker (now filed in src/matched/arm9): func_0205082C (0x0205082C) and func_020507F0 (0x020507F0) are
 * unlabelled arm9 leaves (Ilias's), no witness outside this range. Verified C,
 * both EXACT under --arm --region arm9 (func_020500A0 is the arm9 label at 0x020500A0):
 *     void func_020507F0(void *p, int idx, u32 v)
 *     { char *e = (char *)(*(u32 *)((char *)p + 24) + idx * 40); *(u32 *)(e + 24) = v; }
 *     void func_0205082C(void *p, int idx, u16 h)
 *     { char *e = (char *)(*(u32 *)((char *)p + 24) + idx * 40); *(u16 *)(e + 14) = h; func_020500A0(e); }
 * func_0219C9D0 (function pointer word) is filed as pkt_ov021_0219C9D0.
 */
u32 func_0219C6B8(u32 a, V3_0219C4AC *b, int c, u32 d, u16 e)
{
    u8 *m = (u8 *)func_0216D520((void *)a);
    Desc s;
    u32 r;
    u32 *q;
    u16 *t = d_021D75D0[c];
    u32 h;
    s.slot = e;
    s.v12 = d_021D75D0[c][0];
    s.v14 = t[1];
    s.pos = *b;
    s.k = 0x1f;
    s.flag = 1;
    s.w = 1;
    s.f1c = func_0219C9D0;
    s.f20 = (u32)m;
    r = func_02050340((struct BbActSys *)(((struct Obj07474 *)m)->f4), ((struct Obj07474 *)m)->f8, (const struct BbActDesc *)(&s), 1, 0);
    q = (u32 *)func_0219D3E4(d);
    if (q[0] != 0) {
        func_02050804((void *)(((struct Obj07474 *)m)->f4), r, q[0], (u16)q[1]);
        h = ((struct Obj07474 *)m)->f4;
        func_0205082C((void *)h, r, 0);
        func_020507F0((void *)h, r, 1);
    }
    return r;
}
















u32 func_0219C74C(u32 a, u16 e)
{
    u32 o = (u32)func_0216D67C((void *)a);
    u8 *d = func_0216E3C4((void *)a);
    V3_0219C4AC v;
    func_02197CCC((u8 *)a, (s32 *)(&v));
    return func_0219C6B8(o, &v, d[7], d[9], e);
}
















u32 func_0219C780(u32 a, V3_0219C4AC *b, int c, u32 d, u16 e, u16 g)
{
    u32 r = func_0219C6B8(a, b, c, d, e);
    if (g != 0xFFFF) {
        func_02050894((void *)(*(u32 *)(func_0216D520((void *)a) + 4)), r, g);
    }
    return r;
}
















u32 func_0219C7B4(u32 a, u16 e, u16 g)
{
    u32 o = (u32)func_0216D67C((void *)a);
    u8 *d = func_0216E3C4((void *)a);
    V3_0219C4AC v;
    func_02197CCC((u8 *)a, (s32 *)(&v));
    return func_0219C780(o, &v, d[7], d[9], e, g);
}
















u32 func_0219C7EC(u32 a, u32 b)
{
    u16 t[2];
    func_0219CBD4(func_0216D520(func_0216D67C((void *)a)), b, (u32)(&t[1]), (u32)(&t[0]));
    return func_0219C74C(a, t[1]);
}

















int func_0219C814(u32 a, u16 *b)
{
    u32 m = func_0216D520(func_0216D67C((void *)a));
    u16 *p = func_0216E3C4((void *)a);
    u16 loc[2];
    func_0219CBD4(m, *p, (u32)(&loc[1]), (u32)(&loc[0]));
    if (loc[1] != 0xFFFF && (2 & loc[0]) == 0) {
        *b = func_0219C7EC(a, *p);
        return 1;
    }
    *b = 0xFFFF;
    func_0219CFB0((int *)m, a, (u8 *)p, (int)b, 0, 0, 0);
    return 0;
}

















/*
 * Former blocker (now filed in src/matched/arm9): the only unresolved site is the call to func_020508D8
 * (0x020508D8, arm, arm9), an unlabelled arm9 leaf with no witness (Ilias's).
 * Verified C for the leaf (EXACT, dsi/1.1p1 -O4,p --arm --region arm9):
 *     u32 func_020508D8(u8 *o, u32 i)
 *     {
 *         return *(u16 *)(*(u8 **)(o + 0x18) + i * 0x28 + 4);
 *     }
 *
 * Addresses are Black-image addresses.
 */
void func_0219C880(u8 *o, u32 a, u32 b, u16 c)
{
    u16 v[2];
    if (func_0219CBD4((u32)o, c, (u32)(&v[1]), (u32)(&v[0])) == 1) {
        if (v[0] & 2) {
            u32 t = func_020508D8((u8 *)(((struct Obj00429 *)o)->f4), b);
            func_02050278((struct BbActSys *)(((struct Obj00429 *)o)->f4), t, 1);
        }
        if (v[0] & 1) {
            if (func_0216DFC4((void *)a, c) == 0)
                func_0219CB98((BlactSys *)o, c);
        }
    }
}

















/*
 * Addresses are Black-image addresses.
 */
void func_0219C8D4(u32 o, u32 a)
{
    u16 t = func_0216D598((void *)o);
    u8 *c = (u8 *)func_0216D520(func_0216D67C((void *)o));
    if (a == 0xFFFF) {
        func_0219D184((int *)c, (u32)o);
        return;
    }
    if (func_0219D3B4(c, o, a) != 1) {
        func_0219C880(c, o, (u16)a, t);
        func_02050468((struct BbActSys *)(((struct Obj00429 *)c)->f4), a, 1);
    }
}

















/* b is const: that is what lets the b[7]/b[9] loads schedule above the
 * outgoing stack-argument store of v. */
int func_0219C928(u32 a, const u8 *b, u16 *c, V3_0219C4AC *d, u32 s0, u32 s1)
{
    u16 v;
    u32 t = func_0216D520((void *)a);
    func_0219CBD4(t, *(const u16 *)&((struct Obj03118 *)b)->f0, (u32)(&v), (u32)c);
    if (!(*c & 2)) {
        c[1] = func_0219C6B8(a, d, b[7], b[9], v);
        return 1;
    }
    c[1] = 0xFFFF;
    func_0219CFB0((int *)t, 0, (u8 *)b, (int)&c[1], s0, s1, (S3 *)d);
    return 0;
}

















void func_0219C98C(u32 a, u16 *b)
{
    u8 *c = (u8 *)func_0216D520((void *)a);
    if (b[1] != 0xFFFF) {
        if (b[0] & 2) {
            u32 t = func_020508D8((u8 *)(((struct Obj09509 *)c)->f4), b[1]);
            func_02050278((struct BbActSys *)(((struct Obj09509 *)c)->f4), t, 1);
        }
        func_02050468((struct BbActSys *)(((struct Obj09509 *)c)->f4), b[1], 1);
    }
    b[0] = 0;
    b[1] = 0xFFFF;
}

















void func_0219C9D0(u32 a, u32 b, u8 *p)
{
    *p |= 1;
}

















/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
u32 func_0219C9DC(u8 *p)
{
    return ((struct Obj17968 *)p)->f4;
}

















void func_0219C9E0(u32 a, u16 *x, u16 *y)
{
    u8 *d = func_0216E3C4((void *)a);
    u16 *t = d_021D75D0[d[7]];
    *x = t[0];
    *y = t[1];
}

















void func_0219CA00(u32 *s, u32 n, u32 heap)
{
    u16 *p = (u16 *)func_02030734(heap, n * 8, 1, (const char *)d_021DDD70, 0x484);
    s[0] = n;
    s[1] = (u32)p;
    do {
        p[0] = 0xFFFF;
        p[1] = 0xFFFF;
        p += 4;
    } while (--n);
}

















/*
 * Tail-call thunk: the object's word at +0x4.
 *
 * Addresses are Black-image addresses.
 */
void func_0219CA34(u8 *p)
{
    func_020307B0((void *)(((struct Obj17969 *)p)->f4));
}
















void func_0219CA40(Tbl *t, u16 a, u16 b, u16 c)
{
    int i;
    Ent *e = t->e;
    i = 0;
    do {
        if (e->a == 0xFFFF) {
            e->a = a;
            e->b = b;
            e->c = c;
            return;
        }
        i++;
        e++;
    } while (i < t->n);
}
















void func_0219CA6C(Tbl *t, u16 k)
{
    int i;
    Ent *e = t->e;
    i = 0;
    do {
        if (e->a == k) {
            e->a = 0xFFFF;
            e->b = 0xFFFF;
            e->c = 0;
            return;
        }
        i++;
        e++;
    } while (i < t->n);
}
















/*
 * Linear search of an 8-byte-entry table (count at +0, entries at *(+4)).
 *
 * Addresses are Black-image addresses.
 */
int func_0219CA98(u32 *o, u32 key, u16 *a, u16 *b)
{
    int i = 0;
    u16 *e = (u16 *)o[1];
    if (a) *a = 0xFFFF;
    do {
        if (e[0] == key) {
            if (a) *a = e[1];
            if (b) *b = e[2];
            return 1;
        }
        i++;
        e += 4;
    } while (i < (int)o[0]);
    return 0;
}














/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D4F8 (0x0216D4F8) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_0219CAD8(u8 *a, u32 b)
{
    func_0219CA00((u32 *)(a + 20), b, func_0216D4F8((u8 *)((struct Obj17970 *)a)->f10));
}














void func_0219CAF4(BlactSys *s)
{
    int i;
    Ent *e = s->tbl.e;
    i = 0;
    do {
        if (e->a != 0xFFFF) {
            func_0219CB98(s, e->a);
        }
        i++;
        e++;
    } while (i < s->tbl.n);
    func_0219CA34((u8 *)&s->tbl);
}














/*
 * Addresses are Black-image addresses.
 */
void func_0219CB24(BlactSys *o, u32 a, u16 b, u32 c, u8 s0, u32 s1)
{
    int r = -1;
    u16 t;
    if (s1 & 2) r = 2;
    t = func_0219D3F0((int *)o, b, c, s0, a, r);
    func_0219CA40(&o->tbl, b, t, (u16)s1);
}





















void func_0219CB64(u8 *s, const D *d, u32 g)
{
    u16 *q = func_0216E3C8((void *)d);
    func_0219CB24((BlactSys *)s, (u32)func_02046E24(func_0216D518((u8 *)(((struct Obj19659 *)s)->f10)), *q), d->id, d->f7, d->f8, g);
}





















void func_0219CB98(BlactSys *s, u16 k)
{
    u16 t[2];
    func_0219CA98((u32 *)&s->tbl, k, &t[0], &t[1]);
    if (t[1] & 2) {
        func_02050278((struct BbActSys *)(s->f4), t[0], 1);
    } else {
        func_0219C52C(s->f4, t[0]);
    }
    func_0219CA6C(&s->tbl, k);
}





















/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219CBD4(u32 a, u32 b, u32 c, u32 d)
{
return func_0219CA98((u32 *)(a + 20), b, (u16 *)c, (u16 *)d);
}





















/*
 * Addresses are Black-image addresses.
 */
void func_0219CBE0(u8 *o)
{
    u32 h = func_0216D4F8((u8 *)(((struct Obj03116 *)o)->f10));
    u8 *p = func_02030734(h, 0x18, 1, (const char *)d_021DDD70, 1491);
    u16 *e;
    int i;
    ((struct Obj02077 *)p)->f4 = ((struct Obj03116 *)o)->f2;
    ((struct Obj02077 *)p)->f8 = func_0216D4F0((void *)(((struct Obj03116 *)o)->f10));
    ((struct Obj02077 *)p)->f6 = 1;
    e = (u16 *)func_02030734(h, 0xc * ((struct Obj02077 *)p)->f4, 1, (const char *)d_021DDD70, 1498);
    *(u16 * *)&((struct Obj02077 *)p)->fC = e;
    i = 0;
    if (i < ((struct Obj02077 *)p)->f4) {
        for (; i < ((struct Obj02077 *)p)->f4; i++, e += 6)
            *e = 0xFFFF;
    }
    ((struct Obj02077 *)p)->f10 = (u32)func_02030734(h, 0x14 * ((struct Obj02077 *)p)->f6, 1, (const char *)d_021DDD70, 1511);
    ((struct Obj02077 *)p)->f14 = (u32)func_02030734(h, 0x28 * ((struct Obj02077 *)p)->f8, 1, (const char *)d_021DDD70, 1513);
    ((struct Obj02077 *)p)->f0 = 1;
    *(u8 * *)&((struct Obj03116 *)o)->f1C = p;
}





















void func_0219CC80(u8 *o)
{
    u8 *c = *(u8 * *)&((struct Obj04225 *)o)->f1C;
    u32 i;
    u32 n;
    u8 *p;
    if (c == 0) return;
    i = 0;
    ((struct Obj02698 *)c)->f0 = i;
    func_020307B0((void *)(((struct Obj02698 *)c)->fC));
    p = *(u8 * *)&((struct Obj02698 *)c)->f10;
    if (i < ((struct Obj02698 *)c)->f6) {
        for (; i < ((struct Obj02698 *)c)->f6; i++, p += 0x14) {
            if (((struct Obj06000 *)p)->f10 != 0)
                func_02046EFC((struct Tagged *)(((struct Obj06000 *)p)->f10));
        }
    }
    func_020307B0((void *)(*(u32 *)&((struct Obj02698 *)c)->f10));
    i = 0;
    p = *(u8 * *)&((struct Obj02698 *)c)->f14;
    if (i < ((struct Obj02698 *)c)->f8) {
        for (; i < ((struct Obj02698 *)c)->f8; i++, p += 0x28) {
            if (((struct Obj06000 *)p)->f0 != 0 && ((struct Obj06000 *)p)->f10 != 0)
                func_02046EFC((struct Tagged *)(((struct Obj06000 *)p)->f10));
        }
    }
    func_020307B0((void *)(*(u32 *)&((struct Obj02698 *)c)->f14));
    func_020307B0((void *)((u32)c));
    *(u32 *)&((struct Obj04225 *)o)->f1C = 0;
}





















/*
 * The record pointers are const: mwcc then rereads each u16 count inside its
 * loop and keeps r in r0 instead of hoisting the count into a register.
 */
int func_0219CCF0(u8 *s)
{
    const R *r = *(const R * *)&((struct Obj19662 *)s)->f1C;
    u32 i;
    const A *a;
    const B *b;
    const C *c;

    a = r->a;
    for (i = 0; i < r->n0; i++, a++) {
        if (a->id != 0xFFFF) {
            return 1;
        }
    }
    b = r->b;
    for (i = 0; i < r->n1; i++, b++) {
        if (b->f10 != 0) {
            return 1;
        }
    }
    c = r->c;
    for (i = 0; i < r->n2; i++, c++) {
        if (c->f0 != 0 && c->f10 != 0) {
            return 1;
        }
    }
    return 0;
}





















/*
 * Fills the first free 0xC-byte entry (tag 0xFFFF... see pool) of the table.
 *
 * Addresses are Black-image addresses.
 */
void func_0219CD68(u8 *o, u16 a, u8 b, u8 c, u16 d, u32 e)
{
    u8 *ctx = *(u8 * *)&((struct Obj00429 *)o)->f1C;
    u32 i;
    u32 n = ((struct Obj12672 *)ctx)->f4;
    o = *(u8 * *)&((struct Obj12672 *)ctx)->fC;
    for (i = 0; i < n; i++, o += 0xc) {
        if (((struct Obj00429 *)o)->f0 == 0xFFFF) {
            ((struct Obj00429 *)o)->f0 = a;
            *(u8 *)&((struct Obj00429 *)o)->f4 = b;
            *(u8 *)(o + 5) = c;
            ((struct Obj00429 *)o)->f2 = d;
            ((struct Obj00429 *)o)->f8 = e;
            return;
        }
    }
}





















/*
 * Commits pending 0xC-byte entries through func_0219CE60, then compacts the
 * table so the free (0xFFFF) entries sit at the end.
 *
 * Addresses are Black-image addresses.
 */
void func_0219CDAC(u8 *o)
{
    u8 *ctx = *(u8 * *)&((struct Obj03579 *)o)->f1C;
    u32 j = 0;
    u32 k = 0;
    u8 *e = *(u8 * *)&((struct Obj05011 *)ctx)->fC;
    u8 *base;
    for (; j < ((struct Obj05011 *)ctx)->f4; j++, e += 0xc) {
        if (((struct Obj04224 *)e)->f0 != 0xFFFF) {
            if (func_0219CE60(o, ((struct Obj04224 *)e)->f0, e[4], e[5], ((struct Obj04224 *)e)->f2, ((struct Obj04224 *)e)->f8) == 0)
                break;
            ((struct Obj04224 *)e)->f0 = 0xFFFF;
            k++;
            if (k >= ((struct Obj05011 *)ctx)->f6)
                break;
        }
    }
    if (k != 0) {
        j = 0;
        base = *(u8 * *)&((struct Obj05011 *)ctx)->fC;
        for (; j < (u32)((struct Obj05011 *)ctx)->f4 - 1; j++) {
            T12 *ent = (T12 *)(base + 12 * j);
            if (((struct Obj19665 *)ent)->f0 == 0xFFFF) {
                for (k = j + 1; k < ((struct Obj05011 *)ctx)->f4; k++) {
                    if (*(u16 *)(base + 12 * k) != 0xFFFF) {
                        *ent = *(T12 *)(base + 12 * k);
                        *(u16 *)(base + 12 * k) = 0xFFFF;
                        break;
                    }
                }
            }
        }
    }
}





















/*
 * Claims the first free 0x14-byte slot of the table at *(*(+0x1c)+0x10).
 *
 * Addresses are Black-image addresses.
 */
int func_0219CE60(u8 *o, u32 a, u32 b, u32 c, u16 e, u32 w)
{
    u8 *ctx = *(u8 * *)&((struct Obj03579 *)o)->f1C;
    u8 *p = *(u8 * *)&((struct Obj12673 *)ctx)->f10;
    u32 i;
    for (i = 0; i < ((struct Obj12673 *)ctx)->f6; i++, p += 0x14) {
        if (((struct Obj03580 *)p)->f10 == 0) {
            ((struct Obj03580 *)p)->f0 = 0;
            ((struct Obj03580 *)p)->f8 = a;
            ((struct Obj03580 *)p)->fA = b;
            ((struct Obj03580 *)p)->fB = c;
            ((struct Obj03580 *)p)->f4 = w;
            ((struct Obj03580 *)p)->f10 = (u32)func_02046E24(func_0216D518((u8 *)(((struct Obj03579 *)o)->f10)), e);
            ((struct Obj03580 *)p)->f0 = 1;
            return 1;
        }
    }
    return 0;
}





















void func_0219CEAC(int *obj)
{
    unsigned int i;
    int *p;
    int *t;

    t = (int *)obj[7];
    if (t != 0 && t[0] == 1) {
        i = 0;
        p = (int *)t[4];
        if (!(i < ((struct Obj07477 *)t)->f6)) {
            return;
        }
        for (; i < ((struct Obj07477 *)t)->f6; i++, p += 5) {
            if (p[4] != 0 && ((struct Obj03117 *)p)->f0 == 1) {
                ((struct Obj03117 *)p)->f0 = 0;
                func_0219CB24((BlactSys *)obj, p[4], ((struct Obj03117 *)p)->f8, *((unsigned char *)p + 0xa),
                              *((unsigned char *)p + 0xb), p[1]);
                p[4] = 0;
            }
        }
    }
}





















int func_0219CF00(int *t, unsigned int id, unsigned short *out)
{
    unsigned int i;
    unsigned char *p;
    unsigned int n;
    unsigned int j;
    unsigned char *q;
    unsigned int m;

    t = (int *)t[7];
    i = 0;
    n = *(unsigned short *)&((struct Obj00429 *)t)->f4;
    p = (unsigned char *)t[3];
    for (; i < n; i++, p += 12) {
        if (((struct Obj12675 *)p)->f0 == id) {
            *out = ((struct Obj12675 *)p)->f8;
            return 1;
        }
    }
    m = *(unsigned short *)((char *)t + 6);
    j = 0;
    q = (unsigned char *)t[4];
    for (; j < m; j++, q += 20) {
        if (((struct Obj09512 *)q)->f8 == id && ((struct Obj09512 *)q)->f10 != 0) {
            *out = ((struct Obj09512 *)q)->f4;
            return 1;
        }
    }
    return 0;
}





















int func_0219CF54(int *t, unsigned int id)
{
    unsigned int i;
    unsigned char *p;
    unsigned int n;
    unsigned int j;
    unsigned char *q;
    unsigned int m;

    t = (int *)t[7];
    i = 0;
    n = *(unsigned short *)&((struct Obj00429 *)t)->f4;
    p = (unsigned char *)t[3];
    for (; i < n; i++, p += 12) {
        if (((struct Obj12676 *)p)->f0 == id) {
            ((struct Obj12676 *)p)->f0 = 0xFFFF;
            return 1;
        }
    }
    m = *(unsigned short *)((char *)t + 6);
    j = 0;
    q = (unsigned char *)t[4];
    for (; j < m; j++, q += 20) {
        if (*(int *)&((struct Obj06001 *)q)->f10 != 0 && ((struct Obj06001 *)q)->f8 == id) {
            *q = 0;
            func_02046EFC(((struct Obj06001 *)q)->f10);
            *(int *)&((struct Obj06001 *)q)->f10 = 0;
            return 1;
        }
    }
    return 0;
}





















void func_0219CFB0(int *obj, int a1, unsigned char *src, int a3, int a5, int a6, S3 *a7)
{
    unsigned int i;
    unsigned int n;
    int *p;
    unsigned short v[2];
    unsigned short *t;

    i = 0;
    n = func_0216D4F0((void *)obj[4]);
    p = *(int **)(obj[7] + 0x14);
    for (; i < n; i++, p += 10) {
        if (p[0] == 0) {
            *((unsigned char *)p + 0xd) = 0;
            p[1] = a1;
            p[0] = a3;
            ((struct Obj01353 *)p)->f8 = ((struct Obj03118 *)src)->f0;
            *((unsigned char *)p + 0xa) = src[7];
            *((unsigned char *)p + 0xb) = src[8];
            *((unsigned char *)p + 0xc) = src[9];
            func_0219CBD4((u32)obj, ((struct Obj01353 *)p)->f8, (u32)(&v[1]), (u32)(&v[0]));
            if (v[1] == 0xFFFF && func_0219CF00(obj, ((struct Obj01353 *)p)->f8, &v[0]) == 0) {
                t = func_0216E3C8(src);
                v[0] = 1;
                func_0219CD68((u8 *)obj, ((struct Obj01353 *)p)->f8, *((unsigned char *)p + 0xa),
                              *((unsigned char *)p + 0xb), *t, 1);
            }
            p[5] = a5;
            p[6] = a6;
            if (a7 != 0) {
                *(S3 *)(p + 7) = *a7;
            }
            *((unsigned char *)p + 0xd) = 1;
            return;
        }
    }
}





















void func_0219D064(int *obj, BlactEntry *rec)
{
    unsigned short x[3];
    u32 r;

    x[0] = 0xFFFF;
    rec->fD = 0;
    if (rec->f10 != 0) {
        x[2] = func_0219D3F0(obj, rec->f8, rec->fA,
                             rec->fB, rec->f10, 1);
        rec->f10 = 0;
        func_0219CBD4((u32)obj, rec->f8, (u32)(&x[0]), (u32)(&x[1]));
    } else {
        func_0219CBD4((u32)obj, rec->f8, (u32)(&x[2]), (u32)(&x[1]));
    }
    if (rec->f4 != 0) {
        r = func_0219C7B4(rec->f4, x[2], x[0]);
    } else {
        r = func_0219C780(obj[4], &rec->pos, rec->fA,
                          rec->fC, x[2], x[0]);
    }
    *rec->res = r;
    if (rec->f14 != 0) {
        rec->f14(*rec->res, rec->f18);
    }
    if (rec->f4 != 0) {
        func_0216D758((void *)rec->f4);
    }
}





















void func_0219D0F4(int *obj)
{
    unsigned int i;
    unsigned int n;
    BlactEntry *p;
    unsigned short sp[2];

    i = 0;
    n = func_0216D4F0((void *)obj[4]);
    p = *(BlactEntry **)(obj[7] + 0x14);
    if (n == 0) {
        return;
    }
    for (; i < n; i++, p++) {
        if (p->res != 0 && p->fD == 1) {
            if (func_0219CBD4((u32)obj, p->f8, (u32)(&sp[0]), (u32)(&sp[1])) == 1) {
                func_0219D064(obj, p);
                func_0219D1F8((u8 *)p);
            }
        }
    }
}





















int func_0219D144(int *obj, unsigned int a, int b)
{
    unsigned int i;
    unsigned int n;
    int *p;

    i = 0;
    n = func_0216D4F0((void *)obj[4]);
    p = *(int **)(obj[7] + 0x14);
    for (; i < n; i++, p += 10) {
        if (p[0] != 0 && p[1] != 0 && p[1] != b && ((struct Obj07478 *)p)->f8 == a) {
            return 1;
        }
    }
    return 0;
}





















void func_0219D184(int *obj, int key)
{
    unsigned int i;
    unsigned int n;
    int *p;
    unsigned short s;

    i = 0;
    n = func_0216D4F0((void *)obj[4]);
    p = *(int **)(obj[7] + 0x14);
    for (; i < n; i++, p += 10) {
        if (p[0] != 0 && p[1] == key) {
            *((unsigned char *)p + 0xd) = 0;
            if (func_0219CF00(obj, ((struct Obj02699 *)p)->f8, &s) == 1 && (s & 1)) {
                if (func_0219D144(obj, ((struct Obj02699 *)p)->f8, p[1]) == 0) {
                    func_0219CF54(obj, ((struct Obj02699 *)p)->f8);
                }
            }
            if (p[4] != 0) {
                func_02046EFC((void *)p[4]);
                p[4] = 0;
            }
            func_0219D1F8((u8 *)p);
            return;
        }
    }
}





















/*
 * Clears the byte at +0xd, then tail calls with 0 and 0x28.
 *
 * Addresses are Black-image addresses.
 */
void func_0219D1F8(u8 *p)
{
    p[0xd] = 0;
    func_02082BCC(p, 0, 0x28);
}





















void func_0219D208(int a, unsigned int id)
{
    int *ctx;
    int i;
    unsigned char *r;
    unsigned short h;
    unsigned short v[2];

    ctx = (int *)func_0216D520(func_0216D67C((void *)a));
    r = (unsigned char *)ctx[8];
    func_0219CBD4((u32)ctx, id, (u32)(&v[1]), (u32)(&v[0]));
    if (v[1] != 0xFFFF && !(v[0] & 2)) {
        func_0216E204((char *)a, id);
        return;
    }
    i = 0;
    h = func_0216D7A8((void *)a, 0);
    if (h == 0xFFFF) {
        func_0216E204((char *)a, id);
        return;
    }
    for (; i < 4; i++) {
        if (((struct Obj03119 *)r)->f0 == 0) {
            break;
        }
    }
    if (i >= 4) {
        func_0216E204((char *)a, id);
        return;
    }
    ((struct Obj03119 *)r)->f0 = a;
    ((struct Obj03119 *)r)->f4 = h;
    ((struct Obj03119 *)r)->f6 = func_0216D598((void *)a);
    ((struct Obj03119 *)r)->f8 = id;
    func_0216E204((char *)a, id);
    i = 0;
    if (func_0216D7A8((void *)a, 0) != 0xFFFF) {
        func_0219C880((u8 *)ctx, a, ((struct Obj03119 *)r)->f4, ((struct Obj03119 *)r)->f6);
        func_02050468((struct BbActSys *)ctx[1], ((struct Obj03119 *)r)->f4, 1);
        ((struct Obj03119 *)r)->f0 = i;
    }
}




















/*
 * Promoted 2026-09-27 (lane ov010 blocker tree).  The call at +0x08 is a
 * Thumb `bl` (d0 f7 10 f9), not an interworking `blx`: the target must be
 * Thumb.  The old header called 0x0216D4F8 `arm ov009`, but ov009's byte
 * there is an ARM fragment with no start, while ov010 holds an EXACT Thumb
 * getter (src/matched/func_0216D4F8.c, shard layout/matched/ov010/
 * pkt_0216D4F8.json).  With the region/ISA hint fixed to `thumb ov010` the
 * site resolves as `matched` and the entry is EXACT.
 */
void func_0219D2CC(int *obj)
{
    ((struct Obj03116 *)obj)->f20 =
        (int)func_02030734(func_0216D4F8((u8 *)obj[4]), 0x30, 1, (const char *)d_021DDD70, 0x979);
}




















void func_0219D2F4(u8 *s)
{
    Slot *e = *(Slot * *)&((struct Obj04225 *)s)->f20;
    int i;
    if (e != 0) {
        for (i = 0; i < 4; i++, e++) {
            if (e->p != 0) {
                func_02050468((struct BbActSys *)(((struct Obj04225 *)s)->f4), e->id, 1);
                e->p = 0;
            }
        }
        func_020307B0(((struct Obj04225 *)s)->f20);
    }
}




















void func_0219D324(int *obj, int *rec)
{
    int h;
    unsigned short n;

    h = rec[0];
    if (func_0216DA30(h, (int)rec) == 0) {
        func_0219C880((u8 *)obj, h, ((struct Obj02700 *)rec)->f4, *((unsigned short *)(rec + 1) + 1));
        func_02050468((struct BbActSys *)obj[1], ((struct Obj02700 *)rec)->f4, 1);
        rec[0] = 0;
        return;
    }
    if ((unsigned short)func_0216D7A8((void *)h, 0) != 0xFFFF) {
        n = *((unsigned short *)(rec + 1) + 1);
        if (n != func_0216D598((void *)h)) {
            func_0219C880((u8 *)obj, h, ((struct Obj02700 *)rec)->f4, n);
        }
        func_02050468((struct BbActSys *)obj[1], ((struct Obj02700 *)rec)->f4, 1);
        rec[0] = 0;
    }
}




















void func_0219D390(u8 *s)
{
    Slot *e = *(Slot * *)&((struct Obj03579 *)s)->f20;
    int i;
    if (e != 0) {
        for (i = 0; i < 4; i++, e++) {
            if (e->p != 0) {
                func_0219D324((int *)s, (int *)e);
            }
        }
    }
}




















int func_0219D3B4(u8 *s, u32 p, u16 id)
{
    Slot *e = *(Slot * *)&((struct Obj00429 *)s)->f20;
    int i;
    if (e != 0) {
        for (i = 0; i < 4; i++, e++) {
            if (e->p != 0 && e->p == p && e->id == id) {
                return 1;
            }
        }
    }
    return 0;
}




















/*
 * Indexes an array of 8-byte records based at 0x021D7F68.
 */
char *func_0219D3E4(int i)
{
    return d_021D7F68 + i * 8;
}




















unsigned short func_0219D3F0(int *o, int a1, int a2, int a3, int a4, int a5)
{
    unsigned short *q;
    struct {
        int w0;
        unsigned char b4;
        unsigned char b5;
        unsigned char b6;
        unsigned char b7;
        int w2;
    } s;

    if (a5 == -1) {
        return (unsigned short)func_0219C4AC(o[1], a4, a2, a3);
    }
    s.w0 = a4;
    s.b4 = 0;
    s.b5 = d_021D8064[a3];
    q = d_021D75C4[a2];
    s.b6 = q[0];
    s.b7 = q[1];
    s.w2 = a5;
    return func_020500F0((struct BbActSys *)o[1], (const struct BbActRec *)(&s), 1);
}


















void func_0219D448(int a, int b)
{
    int h;
    int *p;

    h = func_0216D4F8((u8 *)a);
    p = (int *)func_02030734(h, 0x10, 1, (const char *)d_021DDD80, 0x48);
    p[0] = a;
    p[1] = b;
    ((struct Obj04226 *)p)->f8 = func_0216D4F0((void *)a);
    func_0219D4AC(p, h);
    func_0216D524((void *)a, p);
}

















void func_0219D488(u32 a)
{
    void *s = (void *)func_0216D528((u8 *)a);
    func_0219D4EC(s);
    func_020307B0(s);
}

















/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D528 (0x0216D528) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0219D49C(u32 a)
{
return ((struct Obj17972 *)((u8 *)(func_0216D528((u8 *)((u32)func_0216D67C((void *)a))))))->f4;
}


















/*
 * Allocates n*4 bytes (n = *(u16 *)(obj+8)), stores the pointer at obj+0xc,
 * then writes 0xFFFF into the high halfword of each 4-byte entry.
 */
void func_0219D4AC(int *obj, int a)
{
    int i;
    *(int *)&((struct Obj04226 *)obj)->fC =
        (int)(unsigned short *)func_02030734(a, ((struct Obj04226 *)obj)->f8 * 4,
                                             1, (const char *)d_021DDD80, 0x7f);
    for (i = 0; i < (int)((struct Obj04226 *)obj)->f8; i++) {
        unsigned short *p = *(unsigned short * *)&((struct Obj04226 *)obj)->fC;
        p[i * 2 + 1] = 0xFFFF;
    }
}


















void func_0219D4EC(u8 *s)
{
    int i = 0;
    E4 *e = *(E4 * *)&((struct Obj06002 *)s)->fC;
    if (i < ((struct Obj06002 *)s)->f8) {
        for (; i < ((struct Obj06002 *)s)->f8; i++, e++) {
            if (e->b != 0xFFFF) {
                func_021C6580((u8 *)(((struct Obj06002 *)s)->f4), e->a);
            }
        }
    }
    func_020307B0(((struct Obj06002 *)s)->fC);
}


















u16 func_0219D524(u32 *s, u32 b, u32 a)
{
    int i;
    E4 *e = *(E4 * *)&((struct Obj09515 *)s)->fC;
    int n = ((struct Obj09515 *)s)->f8;
    for (i = 0; i < n; i++, e++) {
        if (e->b == 0xFFFF) {
            e->b = b;
            e->a = a;
            return i;
        }
    }
    return 0;
}


















u16 func_0219D558(u8 *s, u16 k)
{
    int i;
    E4 *e = *(E4 * *)&((struct Obj09517 *)s)->fC;
    int n = ((struct Obj09517 *)s)->f8;
    for (i = 0; i < n; i++, e++) {
        if (e->b == k) {
            return e->a;
        }
    }
    return 0xFFFF;
}
















/*
 * Addresses are Black-image addresses.
 */
u32 func_0219D584(u32 a, u32 *b, u32 c, u16 *d)
{
    u32 buf[9];
    u32 t;
    u32 r;
    int i;
    t = func_0216D518((u8 *)a);
    func_021C6AE0((u32)buf);
    if (d[0] != 0xFFFF) {
        func_021C6AF0(buf, t, d[0]);
    }
    if (d[1] != 0xFFFF) {
        func_021C6AF0(buf, t, d[1]);
    }
    func_021C6AF8((u32 *)buf, t);
    for (i = 0; i < 3; i++) {
        if (d[i + 2] != 0xFFFF) {
            func_021C6AFC(buf, d[i + 2]);
        }
    }
    r = func_021C6574(b[1], buf, 0);
    func_0219D524(b, c, r);
    return r;
}
















void func_0219D604(u8 *s, u16 k)
{
    int i;
    int n = ((struct Obj07479 *)s)->f8;
    E4 *e = *(E4 * *)&((struct Obj07479 *)s)->fC;
    for (i = 0; i < n; i++, e++) {
        if (e->b == k) {
            func_021C6580((u8 *)(((struct Obj07479 *)s)->f4), e->a);
            e->b = 0xFFFF;
            return;
        }
    }
}
















u32 func_0219D634(u32 a)
{
    u16 *p;
    u32 b;
    u32 *s;
    u32 r;
    p = func_0216E3C4((void *)a);
    b = (u32)func_0216D67C((void *)a);
    s = (u32 *)func_0216D528((u8 *)b);
    r = func_0219D558((u8 *)s, *p);
    if (r == 0xFFFF) {
        r = func_0219D584(b, s, *p, (u16 *)func_0216E3CC((u8 *)p));
    }
    return func_021C6590(s[1], r, 0, 0);
}
















void func_0219D680(u32 a, u32 b)
{
    u8 *s = (u8 *)func_0216D528(func_0216D67C((void *)a));
    u16 v = func_0216D598((void *)a);
    func_021C6628(((struct Obj07479 *)s)->f4, b);
    if (func_0216DFC4((void *)a, v) == 0) {
        func_0219D604(s, v);
    }
}
















/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219D6B8(u32 *a, u32 b, u32 c, u32 d)
{
func_0216D6F4((void *)a);
return (int)func_0216D548(a, 2);
}
















void func_0219D6CC(u32 a)
{
    u32 k = 2;
    if (func_0216DA20((void *)a, 2) == 0) {
        func_0219D7AC(a);
        func_0219D7D0(a);
        if (func_0216D57C((void *)a, k << 8) != 0) {
            func_02197EB4(a);
        } else if (func_0216DB10((void *)a) == 0 && func_0219D780(a) == 1) {
            func_0216D708((void *)a);
        }
        func_0219D7F0(a);
        func_0219D824(a);
    }
}
















/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D530 (0x0216D530) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219D724(u32 a, char *b)
{
return func_021BB3C4((u8 *)func_0216D530(func_0216D67C((void *)a)), b);
}
















u32 func_0219D738(u32 a, int b)
{
    s16 v[4];
    int r;
    func_0219E784(a, func_0216D5F8((void *)a), v);
    v[1] = 0;
    func_0207CDB8(v, v);
    r = func_0207CFB8(v[0], v[2]) - b;
    if (r < 0) {
        r += 0x10000;
    }
    return d_021D80E4[r >> 12];
}
















int func_0219D780(u32 a)
{
    if (func_0216DA5C((void *)a) == 1) {
        return 1;
    }
    if (func_0216D57C((void *)a, 0x800) == 0) {
        return 1;
    }
    func_0216D5A0((void *)a);
    return 1;
}
















void func_0219D7AC(u32 a)
{
    if (func_0216D57C((void *)a, 0x800) != 0 && func_0219D85C(a) == 1) {
        func_0216DA70((void *)a);
    }
}
















void func_0219D7D0(u32 a)
{
    if (func_0216D57C((void *)a, 0x20) != 0) {
        func_0219D8DC((void *)a);
    }
    func_0216D570((char *)a, 0xA0);
}
















void func_0219D7F0(u32 a)
{
    if (func_0216D57C((void *)a, 0x80) != 0) {
        func_0219D990((void *)a);
    } else if (func_0216D57C((void *)a, 0x20) != 0) {
        func_0219D930((void *)a);
    }
    func_0216D570((char *)a, 0xA0);
}
















void func_0219D824(u32 a)
{
    if (func_0216D57C((void *)a, 0x100) != 0) {
        func_0219DA20((void *)a);
    } else if (func_0216D57C((void *)a, 0x40) != 0) {
        func_0219D9D8((void *)a);
    }
    func_0216D570((char *)a, 0x140);
}
















/*
 * Addresses are Black-image addresses.
 */
u32 func_0219D85C(u32 a)
{
    u32 v1[2];
    u32 v0[2];
    u32 r6 = -1;
    u32 r5 = -1;
    u32 t;
    if (func_0216DCB4((void *)a) == 0) {
        t = (u32)func_0216D530(func_0216D67C((void *)a));
        func_0219E2F4((void *)a, v0);
        func_0219E334(a, (u32)v1);
        r6 = func_021BB3C4((u8 *)t, (char *)v1);
        r5 = func_021BB3C4((u8 *)t, (char *)v0);
    }
    func_0216D7E0((void *)a, r6);
    func_0216D7D8((void *)a, r5);
    if (r5 == -1) {
        func_0216D568((void *)a, 0x800);
        return 0;
    }
    func_0216D570((char *)a, 0x800);
    return 1;
}
















void func_0219D8DC(void *a)
{
    u32 b;
    u32 c;
    u32 d;
    if (func_0219D85C((u32)a) != 0 && func_0216DB24((int)a) == 1) {
        b = func_0216D7DC((void *)a);
        c = func_0216D7E4((void *)a);
        d = (u32)func_0216E3C4((void *)a);
        func_0219DA80((u32)a, b, c, d);
        func_0219DB04((u32)a, b, c, d);
        func_0219DB5C(a, b, c, (u8 *)d);
    }
}
















void func_0219D930(void *a)
{
    u32 b;
    u32 c;
    u32 d;
    if (func_0219D85C((u32)a) != 0 && func_0216DB24((int)a) == 1) {
        b = func_0216D7DC((void *)a);
        c = func_0216D7E4((void *)a);
        d = (u32)func_0216E3C4((void *)a);
        func_0219DAA4((u32)a, b, c, d);
        func_0219DAD0((u32)a, b, c, (u8 *)d);
        func_0219DB0C((u32)a, b, c, d);
        func_0219DB5C(a, b, c, (u8 *)d);
    }
}
















void func_0219D990(void *a)
{
    u32 b;
    u32 c;
    u32 d;
    if (func_0219D85C((u32)a) != 0 && func_0216DB24((int)a) == 1) {
        b = func_0216D7DC((void *)a);
        c = func_0216D7E4((void *)a);
        d = (u32)func_0216E3C4((void *)a);
        func_0219DB0C((u32)a, b, c, d);
        func_0219DB5C(a, b, c, (u8 *)d);
    }
}
















void func_0219D9D8(void *a)
{
    u32 b;
    u32 c;
    u32 d;
    if (func_0219D85C((u32)a) != 0 && func_0216DB24((int)a) == 1) {
        b = func_0216D7DC((void *)a);
        c = func_0216D7E4((void *)a);
        d = (u32)func_0216E3C4((void *)a);
        func_0219DBC8(a, b, c, (u8 *)d);
        func_0219DB44((u32)a, b, c, d);
    }
}
















void func_0219DA20(void *a)
{
    u32 b;
    u32 c;
    u32 d;
    if (func_0219D85C((u32)a) != 0 && func_0216DB24((int)a) == 1) {
        b = func_0216D7DC((void *)a);
        c = func_0216D7E4((void *)a);
        d = (u32)func_0216E3C4((void *)a);
        func_0219DBC8(a, b, c, (u8 *)d);
        func_0219DB44((u32)a, b, c, d);
        func_0219DAA4((u32)a, b, c, d);
        func_0219DB48((u32)a, b, c, d);
    }
}
















void func_0219DA80(u32 a, u32 b, u32 a2, u32 a3)
{
    if (func_021AB0F8(b) & 0x20)
        func_021AC760(func_0219DC08(a), a, 0, 0);
}
















void func_0219DAA4(u32 a, u32 b, u32 a2, u32 a3)
{
    if (b != 0xFFFFFFFF && (func_021AB0F8(b) & 0x20))
        func_021AC760(func_0219DC08(a), a, 1, 0);
}
















void func_0219DAD0(u32 a, u32 x, u32 b, u8 *p)
{
    u32 h;
    int f;
    if (b != 0xFFFFFFFF && (func_021AB0F8(b) & 8)) {
        h = func_0219DC08(a);
        f = 0;
        if (p[5] == 2)
            f = 1;
        func_021BBDD4(a, h, f);
    }
}













/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_0219DB04(u32 a, u32 b, u32 c, u32 d)
{
    func_0219DB0C(a, b, c, d);
}















/*
 * Addresses are Black-image addresses.
 */
void func_0219DB0C(u32 a, u32 a1, u32 a2, u32 a3)
{
    if (func_0216D98C((int)func_0216D67C((void *)a)) != 0) {
        if (func_0216D57C((void *)a, 0x4000) == 0) {
            func_021AC2C0(a, func_0219DC08(a));
            func_0216D568((void *)a, 0x4000);
        }
    }
}
















/*
 * An empty function.
 */
void func_0219DB44(u32 a0, u32 a1, u32 a2, u32 a3)
{
}
















/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219DB48(u32 a, u32 b, u32 c, u32 d)
{
return func_021AC578(a, func_0219DC08(a));
}















void func_0219DB5C(void *a, u32 b, u32 c, u8 *d)
{
    u32 m;
    u32 e;
    u32 f;
    if (d[6] != 0 && func_0216DC34((void *)a) == 0) {
        m = -1;
        if (b != -1) {
            if (func_021AB0F8(b) & 0x40) {
                m = b;
            } else {
                b = func_02163F40((int)a, 1);
                if (func_021AB0F8(b) & 0x40) {
                    m = b;
                }
            }
            if (m != -1) {
                e = func_0219DC08((u32)a);
                f = (u32)func_0216D67C((void *)a);
                func_0216DC18(a, 1);
                func_021BBFB8(f, (u32)a, e, 1);
            }
        }
    }
}















void func_0219DBC8(void *a, u32 b, u32 c, u8 *d)
{
    int r;
    if (d[6] != 0 && func_0216DC34((void *)a) != 0) {
        r = func_02163F40((int)a, 1);
        if (r == -1) {
            func_0216DC18(a, 0);
            return;
        }
        if ((func_021AB0F8(r) & 0x40) == 0) {
            func_0216DC18(a, 0);
        }
    }
}















int func_0219DC08(u32 a)
{
return func_02188CD0((u8 *)func_0216D534((void *)func_0216D67C((void *)a)));
}













int func_0219DC18(u32 a, u32 b, u32 c, u32 d)
{
func_0216D568((void *)a, (1 << 10));
return 0;
}












/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D7CC (0x0216D7CC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219DC28(u8 *a)
{
    func_0216D7CC(a);
    return 1;
}











/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D7CC (0x0216D7CC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_0219DC34(u32 a, u32 b)
{
func_0216D5E0(a, ((b << 16) >> 16));
func_0216D674((void *)a, 0);
func_02163F10(a);
func_0216D7CC((u8 *)a);
}












/*
 * Calls func_0219DC34(its own argument 1, 0x0) and returns 0x1.
 */
u32 func_0219DC58(u32 a1)
{
    func_0219DC34(a1, 0x0);

    return 0x1;
}












/*
 * Calls func_0219DC34(its own argument 1, 0x1) and returns 0x1.
 */
u32 func_0219DC64(u32 a1)
{
    func_0219DC34(a1, 0x1);

    return 0x1;
}












/*
 * Calls func_0219DC34(its own argument 1, 0x2) and returns 0x1.
 */
u32 func_0219DC70(u32 a1)
{
    func_0219DC34(a1, 0x2);

    return 0x1;
}











/*
 * Calls func_0219DC34(its own argument 1, 0x3) and returns 0x1.
 */
u32 func_0219DC7C(u32 a1)
{
    func_0219DC34(a1, 0x3);

    return 0x1;
}











/*
 * Addresses are Black-image addresses.
 */
void func_0219DC88(u32 a, u32 b, u32 c, u16 d)
{
    func_0219E370(a, (u16)b, c);
    func_0219E6C8(a, b);
    func_0216D60C((u32)a, (u16)b);
    func_0216D674((void *)a, d);
    func_0216D568((void *)a, 0x20);
    func_0216D7CC((u8 *)a);
}
















/*
 * Addresses are Black-image addresses.
 */
int func_0219DCC4(u32 o)
{
    u32 a;
    u8 buf[12];

    a = (u32)func_0219E348((void *)o);
    func_0219E354(o);
    func_021B8028(a, buf);
    func_0216D89C(o, buf);
    if (func_021B8040((u8 *)a)) {
        return 0;
    }
    func_0216D568((void *)o, 0x440);
    func_0216D674((void *)o, 0);
    func_0216D7CC((u8 *)o);
    return 0;
}
















/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219DD18(u32 a, u32 b, u32 c, u32 d)
{
func_0216D674((void *)a, 0);
return 0;
}
















/*
 * Calls func_0219DC88(its own argument 1, 0x0, 0x10, 0x2) and returns 0x1.
 */
u32 func_0219DD24(u32 a1)
{
    func_0219DC88(a1, 0x0, 0x10, 0x2);

    return 0x1;
}
















/*
 * Calls func_0219DC88(its own argument 1, 0x1, 0x10, 0x2) and returns 0x1.
 */
u32 func_0219DD34(u32 a1)
{
    func_0219DC88(a1, 0x1, 0x10, 0x2);

    return 0x1;
}
















/*
 * Calls func_0219DC88(its own argument 1, 0x2, 0x10, 0x2) and returns 0x1.
 */
u32 func_0219DD44(u32 a1)
{
    func_0219DC88(a1, 0x2, 0x10, 0x2);

    return 0x1;
}
















/*
 * Calls func_0219DC88(its own argument 1, 0x3, 0x10, 0x2) and returns 0x1.
 */
u32 func_0219DD54(u32 a1)
{
    func_0219DC88(a1, 0x3, 0x10, 0x2);

    return 0x1;
}
















/*
 * Calls func_0219DC88(its own argument 1, 0x0, 0x8, 0x3) and returns 0x1.
 */
u32 func_0219DD64(u32 a1)
{
    func_0219DC88(a1, 0x0, 0x8, 0x3);

    return 0x1;
}
















/*
 * Calls func_0219DC88(its own argument 1, 0x1, 0x8, 0x3) and returns 0x1.
 */
u32 func_0219DD74(u32 a1)
{
    func_0219DC88(a1, 0x1, 0x8, 0x3);

    return 0x1;
}
















/*
 * Calls func_0219DC88(its own argument 1, 0x2, 0x8, 0x3) and returns 0x1.
 */
u32 func_0219DD84(u32 a1)
{
    func_0219DC88(a1, 0x2, 0x8, 0x3);

    return 0x1;
}
















/*
 * Calls func_0219DC88(its own argument 1, 0x3, 0x8, 0x3) and returns 0x1.
 */
u32 func_0219DD94(u32 a1)
{
    func_0219DC88(a1, 0x3, 0x8, 0x3);

    return 0x1;
}
















/*
 * Calls func_0219DC88(its own argument 1, 0x0, 0x4, 0x4) and returns 0x1.
 */
u32 func_0219DDA4(u32 a1)
{
    func_0219DC88(a1, 0x0, 0x4, 0x4);

    return 0x1;
}
















/*
 * Calls func_0219DC88(its own argument 1, 0x1, 0x4, 0x4) and returns 0x1.
 */
u32 func_0219DDB4(u32 a1)
{
    func_0219DC88(a1, 0x1, 0x4, 0x4);

    return 0x1;
}
















/*
 * Calls func_0219DC88(its own argument 1, 0x2, 0x4, 0x4) and returns 0x1.
 */
u32 func_0219DDC4(u32 a1)
{
    func_0219DC88(a1, 0x2, 0x4, 0x4);

    return 0x1;
}
















/*
 * Calls func_0219DC88(its own argument 1, 0x3, 0x4, 0x4) and returns 0x1.
 */
u32 func_0219DDD4(u32 a1)
{
    func_0219DC88(a1, 0x3, 0x4, 0x4);

    return 0x1;
}
















/*
 * Calls func_0219DC88(its own argument 1, 0x0, 0x2, 0x5) and returns 0x1.
 */
u32 func_0219DDE4(u32 a1)
{
    func_0219DC88(a1, 0x0, 0x2, 0x5);

    return 0x1;
}
















/*
 * Calls func_0219DC88(its own argument 1, 0x1, 0x2, 0x5) and returns 0x1.
 */
u32 func_0219DDF4(u32 a1)
{
    func_0219DC88(a1, 0x1, 0x2, 0x5);

    return 0x1;
}
















/*
 * Calls func_0219DC88(its own argument 1, 0x2, 0x2, 0x5) and returns 0x1.
 */
u32 func_0219DE04(u32 a1)
{
    func_0219DC88(a1, 0x2, 0x2, 0x5);

    return 0x1;
}
















/*
 * Calls func_0219DC88(its own argument 1, 0x3, 0x2, 0x5) and returns 0x1.
 */
u32 func_0219DE14(u32 a1)
{
    func_0219DC88(a1, 0x3, 0x2, 0x5);

    return 0x1;
}
















/*
 * Calls func_0219DC88(its own argument 1, 0x0, 0x4, 0xa) and returns 0x1.
 */
u32 func_0219DE24(u32 a1)
{
    func_0219DC88(a1, 0x0, 0x4, 0xa);

    return 0x1;
}
















/*
 * Calls func_0219DC88(its own argument 1, 0x1, 0x4, 0xa) and returns 0x1.
 */
u32 func_0219DE34(u32 a1)
{
    func_0219DC88(a1, 0x1, 0x4, 0xa);

    return 0x1;
}
















/*
 * Calls func_0219DC88(its own argument 1, 0x2, 0x4, 0xa) and returns 0x1.
 */
u32 func_0219DE44(u32 a1)
{
    func_0219DC88(a1, 0x2, 0x4, 0xa);

    return 0x1;
}
















/*
 * Calls func_0219DC88(its own argument 1, 0x3, 0x4, 0xa) and returns 0x1.
 */
u32 func_0219DE54(u32 a1)
{
    func_0219DC88(a1, 0x3, 0x4, 0xa);

    return 0x1;
}
















void func_0219DE64(u32 a, u32 b, u16 c, u16 d)
{
    u16 *q = func_0216D6BC((u32)a, (u32)4, c);
    q[0] = d;
    q[1] = c;
    func_0216D5E0((u32)a, (u16)b);
    func_0216D674((void *)a, d);
    func_02163F10(a);
    func_0216D7CC((u8 *)a);
}
















int func_0219DE98(u32 a)
{
    s16 *q = func_0216D6D4((void *)a);
    q[1]--;
    if (q[1] > 0)
        return 0;
    func_0216D568((void *)a, 0x400);
    func_0216D674((void *)a, 0);
    func_0216D7CC((u8 *)a);
    return 1;
}
















/*
 * Calls func_0219DE64(its own argument 1, 0x0, 0x20, 0x1) and returns 0x1.
 */
u32 func_0219DECC(u32 a1)
{
    func_0219DE64(a1, 0x0, 0x20, 0x1);

    return 0x1;
}
















/*
 * Calls func_0219DE64(its own argument 1, 0x1, 0x20, 0x1) and returns 0x1.
 */
u32 func_0219DEDC(u32 a1)
{
    func_0219DE64(a1, 0x1, 0x20, 0x1);

    return 0x1;
}
















/*
 * Calls func_0219DE64(its own argument 1, 0x2, 0x20, 0x1) and returns 0x1.
 */
u32 func_0219DEEC(u32 a1)
{
    func_0219DE64(a1, 0x2, 0x20, 0x1);

    return 0x1;
}















/*
 * Calls func_0219DE64(its own argument 1, 0x3, 0x20, 0x1) and returns 0x1.
 */
u32 func_0219DEFC(u32 a1)
{
    func_0219DE64(a1, 0x3, 0x20, 0x1);

    return 0x1;
}















/*
 * Calls func_0219DE64(its own argument 1, 0x0, 0x10, 0x2) and returns 0x1.
 */
u32 func_0219DF0C(u32 a1)
{
    func_0219DE64(a1, 0x0, 0x10, 0x2);

    return 0x1;
}















/*
 * Calls func_0219DE64(its own argument 1, 0x1, 0x10, 0x2) and returns 0x1.
 */
u32 func_0219DF1C(u32 a1)
{
    func_0219DE64(a1, 0x1, 0x10, 0x2);

    return 0x1;
}















/*
 * Calls func_0219DE64(its own argument 1, 0x2, 0x10, 0x2) and returns 0x1.
 */
u32 func_0219DF2C(u32 a1)
{
    func_0219DE64(a1, 0x2, 0x10, 0x2);

    return 0x1;
}















/*
 * Calls func_0219DE64(its own argument 1, 0x3, 0x10, 0x2) and returns 0x1.
 */
u32 func_0219DF3C(u32 a1)
{
    func_0219DE64(a1, 0x3, 0x10, 0x2);

    return 0x1;
}















/*
 * Calls func_0219DE64(its own argument 1, 0x0, 0x8, 0x3) and returns 0x1.
 */
u32 func_0219DF4C(u32 a1)
{
    func_0219DE64(a1, 0x0, 0x8, 0x3);

    return 0x1;
}















/*
 * Calls func_0219DE64(its own argument 1, 0x1, 0x8, 0x3) and returns 0x1.
 */
u32 func_0219DF5C(u32 a1)
{
    func_0219DE64(a1, 0x1, 0x8, 0x3);

    return 0x1;
}















/*
 * Calls func_0219DE64(its own argument 1, 0x2, 0x8, 0x3) and returns 0x1.
 */
u32 func_0219DF6C(u32 a1)
{
    func_0219DE64(a1, 0x2, 0x8, 0x3);

    return 0x1;
}















/*
 * Calls func_0219DE64(its own argument 1, 0x3, 0x8, 0x3) and returns 0x1.
 */
u32 func_0219DF7C(u32 a1)
{
    func_0219DE64(a1, 0x3, 0x8, 0x3);

    return 0x1;
}















/*
 * Calls func_0219DE64(its own argument 1, 0x0, 0x2, 0x5) and returns 0x1.
 */
u32 func_0219DF8C(u32 a1)
{
    func_0219DE64(a1, 0x0, 0x2, 0x5);

    return 0x1;
}















/*
 * Calls func_0219DE64(its own argument 1, 0x1, 0x2, 0x5) and returns 0x1.
 */
u32 func_0219DF9C(u32 a1)
{
    func_0219DE64(a1, 0x1, 0x2, 0x5);

    return 0x1;
}















/*
 * Calls func_0219DE64(its own argument 1, 0x2, 0x2, 0x5) and returns 0x1.
 */
u32 func_0219DFAC(u32 a1)
{
    func_0219DE64(a1, 0x2, 0x2, 0x5);

    return 0x1;
}















/*
 * Calls func_0219DE64(its own argument 1, 0x3, 0x2, 0x5) and returns 0x1.
 */
u32 func_0219DFBC(u32 a1)
{
    func_0219DE64(a1, 0x3, 0x2, 0x5);

    return 0x1;
}














/*
 * Calls func_0219DE64(its own argument 1, 0x0, 0x4, 0x4) and returns 0x1.
 */
u32 func_0219DFCC(u32 a1)
{
    func_0219DE64(a1, 0x0, 0x4, 0x4);

    return 0x1;
}














/*
 * Calls func_0219DE64(its own argument 1, 0x1, 0x4, 0x4) and returns 0x1.
 */
u32 func_0219DFDC(u32 a1)
{
    func_0219DE64(a1, 0x1, 0x4, 0x4);

    return 0x1;
}














/*
 * Calls func_0219DE64(its own argument 1, 0x2, 0x4, 0x4) and returns 0x1.
 */
u32 func_0219DFEC(u32 a1)
{
    func_0219DE64(a1, 0x2, 0x4, 0x4);

    return 0x1;
}












/*
 * Calls func_0219DE64(its own argument 1, 0x3, 0x4, 0x4) and returns 0x1.
 */
u32 func_0219DFFC(u32 a1)
{
    func_0219DE64(a1, 0x3, 0x4, 0x4);

    return 0x1;
}











void func_0219E00C(u32 o, u32 id, u32 p, u8 q, u16 sa, s16 sc, u16 se, u32 fn)
{
    u8 *e;

    e = func_0216D6BC(o, 0x10, p);
    e[0xc] = id;
    ((struct Obj05013 *)e)->f0 = p;
    e[0xd] = q;
    e[0xe] = sa;
    e[0xf] = sc;
    ((struct Obj05013 *)e)->f8 = se;
    if (p == 0) {
        func_02163F10(o);
    } else {
        func_0219E370(o, (u16)id, 8);
        func_0219E6C8(o, id);
    }
    func_0216D568((void *)o, 0xa0);
    func_0216D60C((u32)o, (u16)id);
    func_0216D674((void *)o, sa);
    func_0216D7CC((u8 *)o);
    if (fn) {
        func_020061E4(fn);
    }
}











/*
 * Addresses are Black-image addresses.
 */
void func_0219E084(u32 a, u32 b, u32 c, u8 d, u16 e, s16 f, u16 g)
{
    func_0219E00C(a, b, c, d, e, f, g, 0x55E);
}












int func_0219E0A8(u32 o)
{
    E_0219C4AC *e;
    u32 a;
    s32 t;
    s32 k;
    u8 buf[12];
    V3_0219E084 v;
    s32 z[3];

    e = func_0216D6D4((void *)o);
    e->count--;
    if (e->speed != 0) {
        a = (u32)func_0219E348((void *)o);
        func_0219E354(o);
        func_021B8028(a, buf);
        func_0216D89C(o, buf);
        if (e->acc >= 0x10000 && e->count > 0) {
            e->acc = 0;
            func_0219E370(o, e->id, 8);
            func_0219E6C8(o, e->id);
            func_0216D568((void *)o, 0x20);
        }
        t = e->speed;
        if (t < 0) {
            t = -t;
        }
        e->acc += t;
    }
    e->pos += e->step;
    if (e->pos > 0xF00) {
        e->pos = 0xF00;
    }
    t = (u16)(e->pos / 256);
    k = e->table;
    v.x = 0;
    v.y = d_021DDD94[k][t];
    v.z = 0;
    func_0216D8C0(o, &v);
    if (e->count > 0 || func_021B8040((u8 *)a)) {
        return 0;
    }
    {
        V3_0219E084 *pv = (V3_0219E084 *)z;
        pv->x = 0;
        pv->y = 0;
        pv->z = 0;
        func_0216D8C0(o, pv);
    }
    func_0216D568((void *)o, 0x540);
    func_02163F10(o);
    func_0216D674((void *)o, 0);
    func_0216D7CC((u8 *)o);
    func_020061E4(0x67B);
    return 1;
}












int func_0219E1B0(u32 a)
{
    func_0219E084(a, 0, 0x2000, 8, 3, 0, 0x200);
    return 1;
}












int func_0219E1D0(u32 a)
{
    func_0219E084(a, 1, 0x2000, 8, 3, 0, 0x200);
    return 1;
}












int func_0219E1F4(u32 a)
{
    func_0219E084(a, 2, 0x2000, 8, 3, 0, 0x200);
    return 1;
}












int func_0219E218(u32 a)
{
    func_0219E084(a, 3, 0x2000, 8, 3, 0, 0x200);
    return 1;
}












int func_0219E238(u32 a)
{
    func_0219E084(a, 0, 0x2000, 16, 3, 0, 0x100);
    return 1;
}












int func_0219E258(u32 a)
{
    func_0219E084(a, 1, 0x2000, 16, 3, 0, 0x100);
    return 1;
}












/*
 * Addresses are Black-image addresses.
 */
int func_0219E27C(u32 a)
{
    func_0219E084(a, 2, 0x2000, 16, 3, 0, 0x100);
    return 1;
}












int func_0219E29C(u32 a)
{
    func_0219E084(a, 3, 0x2000, 16, 3, 0, 0x100);
    return 1;
}












void func_0219E2C0(void *a, void *r)
{
    void **p = func_0216D69C(a);
    u8 buf[12];
    func_021B7EE4(*p, r);
    func_0219EAD8((Obj *)p, (const Rect *)r);
    func_021B8028((u32)(*p), buf);
    func_0216D89C((u32)a, buf);
}











void func_0219E2F4(void *o, void *out)
{
    void **h;

    func_021BB480(func_0216D530(func_0216D67C(o)));
    h = func_0216D69C(o);
    if (func_021B8040(*h))
        func_021B7E60(*h, func_021B8038(*h), out, 0);
    else
        func_021B7DC0(*h, out);
}










/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219E334(u32 a, u32 b)
{
return func_021B7DC0((void *)(((struct Obj17973 *)((u8 *)(func_0216D69C((void *)a))))->f0), (void *)b);
}










void *func_0219E348(void *a)
{
    return *(void **)func_0216D69C(a);
}










/*
 * Addresses are Black-image addresses.
 */
void func_0219E354(u32 a)
{
    u32 *p = func_0216D69C((void *)a);
    func_021B810C((void *)*p);
    func_0219EA78((Obj *)p, a);
}










void func_0219E370(u32 a, u32 b, u32 c)
{
    u32 *p = func_0216D69C((void *)a);
    u32 x = func_0219E938(b);
    func_021B80E0((void *)*p, func_0219E940(c), x);
}










u32 func_0219E398(u32 o, u32 a, char *b, u32 *out)
{
    u32 r;
    u32 **p;
    u32 v;

    r = 0;
    p = func_0216D69C((void *)o);
    v = (u32)func_0216D530(func_0216D67C((void *)o));
    if (!func_021B7DE0(*p, a)) {
        r |= 1;
    }
    if (!func_021B7DE0(*p, b)) {
        r |= 1;
    }
    if (!func_0216DCB4((void *)o)) {
        p = (u32 **)func_021BB3C4((u8 *)v, b);
        if (func_021AB0F8((u32)p) & 1) {
            r |= 2;
        }
        if (out) {
            *out = (u32)p;
        }
    }
    if (func_0219E498(o, (u32)b)) {
        r |= 4;
    }
    return r;
}










/*
 * Tail-call thunk: pins the third argument to 0.
 *
 * Addresses are Black-image addresses.
 */
int func_0219E418(u32 a, u16 b)
{
    return func_0219E424(a, b, 0);
}










int func_0219E424(u32 o, u32 k, u32 x)
{
    u32 v;
    u32 **p;
    u32 a[2];
    u32 b[2];
    int r;
    u32 t;

    v = (u32)func_021BB480(func_0216D530(func_0216D67C((void *)o)));
    p = func_0216D69C((void *)o);
    func_021B7DC0(*p, a);
    t = func_0216D5F8((void *)o);
    if (t == k) {
        r = func_021B7E60(*p, func_0219E938(k), b, 0);
    } else {
        r = func_021B7CD8(v, a, func_0219E938(k), b);
    }
    if (r) {
        return func_0219E398(o, (u32)a, (char *)b, (u32 *)x);
    }
    return 1;
}










/*
 * Addresses are Black-image addresses.
 * EXACT* is the 2-byte alignment pad after the last pop.
 */
int func_0219E498(u32 o, u32 k)
{
    u32 t;
    u32 h;
    u32 m;
    u8 rec[12];
    u8 tA[12];
    u32 cur;
    u32 st;
    u32 lim;
    u32 s;
    int z;

    s = (u32)func_0216D67C((void *)o);
    h = (u32)func_021BB480(func_0216D530((void *)s));
    st = 0;
    func_021B7D38(h, k, rec);
    m = func_0207C768(func_021B7C38((u8 *)h), 0x4000);
    while (func_0216DD1C((struct Ctx *)s, (struct Rec **)(&cur), &st) == 1) {
        lim = 0x4000 >> 1;
        if (cur == o) {
            continue;
        }
        if (func_0216D55C(cur, 0x80) != 0) {
            continue;
        }
        z = (func_0216D55C(cur, lim) == 0);
        if (!z) {
            t = (u32)func_0219E348((void *)cur);
            if (func_021B8040((u8 *)t)) {
                func_021B7E60((void *)t, func_021B8038((u8 *)t), 0, tA);
                if (func_021B83B0((const s32 *)rec, (const s32 *)tA, m)) {
                    return 1;
                }
            }
            func_021B7ED4(t, tA);
            if (func_021B83B0((const s32 *)rec, (const s32 *)tA, m)) {
                return 1;
            }
        }
    }
    return 0;
}










u32 func_0219E570(u32 o, u32 k, u32 flag)
{
    u32 h;
    u32 m;
    u8 rec[12];
    u8 buf[12];
    u32 st;
    u32 cur;
    u8 tB[8];
    u8 tA[8];
    u32 lim;
    int z;

    st = 0;
    h = (u32)func_021BB480(func_0216D530((void *)o));
    func_021B7D38(h, k, rec);
    m = func_0207C768(func_021B7C38((u8 *)h), 0x4000);
    while (func_0216DD1C((struct Ctx *)o, (struct Rec **)(&cur), &st) == 1) {
        lim = 0x4000 >> 1;
        z = (func_0216D55C(cur, lim) == 0);
        if (!z) {
            if (flag) {
                func_0219E334(cur, (u32)tB);
                func_021B7D38(h, tB, buf);
                if (func_021B83B0((const s32 *)rec, (const s32 *)buf, m)) {
                    return cur;
                }
            }
            func_0219E2F4((void *)cur, tA);
            func_021B7D38(h, tA, buf);
            if (func_021B83B0((const s32 *)rec, (const s32 *)buf, m)) {
                return cur;
            }
        }
    }
    return 0;
}









/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219E634(void *a, void *b)
{
    void **p;

    func_0216D530(func_0216D67C(a));
    p = func_0216D69C(a);
    return func_021B7E60(*p, func_0201441C(func_0216D5F8(a)), b, 0);
}










/*
 * Addresses are Black-image addresses.
 */
int func_0219E664(void *o, u32 k, void *buf)
{
    void *h;
    u32 t;
    void **p;

    h = func_021BB480(func_0216D530(func_0216D67C(o)));
    t = func_0216D5F8(o);
    p = func_0216D69C(o);
    if (t != k) {
        func_0219E2F4(o, buf);
        return func_021B7CD8(h, buf, func_0201441C(k), buf);
    }
    return func_021B7E60(*p, func_0201441C(k), buf, 0);
}










void func_0219E6C8(u32 o, u16 id)
{
    u32 h;
    s32 v[3];
    u32 a[2];

    h = (u32)func_021BB480(func_0216D530(func_0216D67C((void *)o)));
    func_0219E2F4((void *)o, a);
    func_021B7C90((struct Mgr *)h, a, (void *)func_0201441C(id), v);
    func_0216D80C(o, func_0216D83C((void *)o));
    func_0216D818(o, func_0216D854((void *)o));
    func_0216D824(o, func_0216D86C((void *)o));
    func_0216D844((void *)o, (v[0] >> 4) / 4096);
    func_0216D85C((void *)o, (s16)((v[1] >> 4) / 4096));
    func_0216D874((u32)o, (s16)((v[2] >> 4) / 4096));
}









/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_0219E764(u32 a, s16 *b)
{
func_0219E348((void *)a);
func_0219E784(a, (((u32)func_0216D5F8((void *)a) << 16) >> 16), b);
}







static inline void setv(V3_0219E084 *p, s32 x, s32 y, s32 z)
{
    p->x = x;
    p->y = y;
    p->z = z;
}







static inline void setw(s16 *p, s32 x, s32 y, s32 z)
{
    p[0] = x;
    p[1] = y;
    p[2] = z;
}







void func_0219E784(u32 o, u32 idx, s16 *v)
{
    u32 t;
    u32 n;
    s32 k;
    s32 c;
    s32 m[9];
    V3_0219E084 vec;

    t = (u32)func_0219E348((void *)o);
    func_021B8050((struct Sub *)t, v);
    n = func_021B80D8((u8 *)t);
    k = (d_021D841C[d_021D84D4[n][idx]] >> 4) * 2;
    c = d_020A1B38[k + 1];
    v[1] = (s16)(((s64)c * v[1] + 0x800) >> 12);
    setv(&vec, v[0], v[1], v[2]);
    func_0207AF1C(m, d_020A1B38[k], c);
    func_0207B51C(&vec, m, &vec);
    func_0207CCA4(&vec, &vec);
    setw(v, vec.x, vec.y, vec.z);
}







void *func_0219E828(u32 a)
{
    return func_0219E968(a, 0xc);
}








/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_0219E834(u32 a, u32 b, u32 c, u32 d)
{
    func_0219EA78((Obj *)func_0216D69C((void *)a), a);
}









int func_0219E844(u32 *a, u32 b, u32 c, u32 d)
{
return func_0219EA94((u32)func_0216D69C((void *)a), a);
}









/*
 * Addresses are Black-image addresses.
 * func_0219E854 is followed by twenty unlabelled tail-call thunks (pool
 * word plus `bx r3`), eleven of them passing a state index 0..10 to
 * func_0219EB18; the unit covers the whole 228-byte run.
 */
void func_0219E854(u32 o)
{
    func_0219EAB8((u32)func_0216D69C((void *)o), o);
}









void func_0219E864(u32 o) { func_0219EB18(o, 0); }








void func_0219E870(u32 o) { func_0219EB18(o, 1); }








void func_0219E87C(u32 o) { func_0219EB18(o, 2); }








void func_0219E888(u32 o) { func_0219EB18(o, 3); }








void func_0219E894(u32 o) { func_0219EB18(o, 4); }








void func_0219E8A0(u32 o) { func_0219EB18(o, 5); }








void func_0219E8AC(u32 o) { func_0219EB18(o, 6); }








void func_0219E8B8(u32 o) { func_0219EB18(o, 7); }








void func_0219E8C4(u32 o) { func_0219EB18(o, 8); }








void func_0219E8D0(u32 o) { func_0219EB18(o, 9); }








void func_0219E8DC(u32 o) { func_0219EB18(o, 10); }








int func_0219E8E8(u32 o) { return func_0219EB4C(o); }








int func_0219E8F0(u32 *o) { return func_0219EB90(o); }








void func_0219E8F8(u32 o) { func_0219EBA0(o, 0); }








void func_0219E904(u32 o) { func_0219EBA0(o, 9); }








int func_0219E910(u32 o) { return func_0219EBF4(o); }








int func_0219E918(u32 *o) { return func_0219ED7C(o); }








void func_0219E920(u32 o) { func_0219ED8C(o); }








int func_0219E928(u32 o) { return func_0219EDC4(o); }








int func_0219E930(u32 *o) { return func_0219EF04(o); }









/*
 * Tail-call thunk: forwards to func_0201441C with no argument change.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0219E938(int a0)
{
    return func_0201441C(a0);
}









/*
 * Addresses are Black-image addresses.
 */
u32 func_0219E940(int x)
{
    u32 r = 1;
    switch (x) {
    case 16: r = 0; break;
    case 4: r = 2; break;
    case 2: r = 3; break;
    case 8: break;
    }
    return r;
}









void *func_0219E968(u32 a, u32 size)
{
    u8 buf[8];
    int ok = func_02164380((void *)a, (u16 *)buf);
    void *q = func_0216D684(a, size);
    func_0219EA5C(q, a);
    if (ok) {
        func_0219E2C0((void *)a, buf);
    } else {
        func_02082BCC(buf, 0, 8);
        func_0219E2C0((void *)a, buf);
    }
    return q;
}









int func_0219E9A8(u32 o, int a, int b, L *l)
{
    int x;
    int y;
    int lo;
    int hi;

    x = func_0216D660((void *)o);
    y = func_0216D66C((void *)o);
    if (x != -1) {
        lo = b - x;
        hi = b + x;
        if (lo > l->lx || hi < l->lx) {
            return 1;
        }
    }
    if (y != -1) {
        hi = a + y;
        lo = a - y;
        if (lo > l->ly || hi < l->ly) {
            return 1;
        }
    }
    return 0;
}









int func_0219E9F8(u32 *arr, u32 v)
{
    int i;
    for (i = 0; arr[i] != v; i++) {
    }
    return i;
}







/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219EA10(u32 *a, int b)
{
return *(u32 *)((u8 *)(a) + ((func_020056EC(func_0219E9F8((u32 *)a, b)) << 2)));
}







/*
 * Addresses are Black-image addresses.
 */
u32 func_0219EA24(u32 a, u32 b)
{
    u32 *t = (u32 *)func_0219EA40(a);
    return t[func_020056EC(func_0219E9F8(t, b))];
}







int func_0219EA40(int key)
{
    Entry *e = d_021D84E8;
    int k = 0;
    do {
        if (k == key) {
            return e->val;
        }
        e++;
        k = e->key;
    } while (k != 11);
    return 0;
}







/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D530 (0x0216D530) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219EA5C(void *a, u32 b)
{
((struct Obj12077 *)((u8 *)(a)))->f0 = func_021BB394((u8 *)func_0216D530(func_0216D67C((void *)b)));
((struct Obj12077 *)((u8 *)(a)))->f6 = 2;
return 2;
}







void func_0219EA78(Obj *p, u32 a1)
{
    u16 buf[4];
    func_021B7DC0((void *)p->head, buf);
    func_0219EAD8(p, (const Rect *)buf);
}







u32 func_0219EA94(u32 a, u32 *b)
{
func_021BB3A0((u8 *)func_0216D530(func_0216D67C((void *)b)), ((struct Obj17976 *)((u8 *)(a)))->f0);
return (u32)func_0216D550(b, (2 << 12));
}






void func_0219EAB8(u32 a, u32 b)
{
*(u32 *)&((struct Obj07482 *)((u8 *)(a)))->f0 = func_021BB394((u8 *)func_0216D530(func_0216D67C((void *)b)));
func_0219EAEC((u8 *)a, b);
}







/*
 * The source pointer is const: that lets mwcc load s->h above the store of w.
 *
 * Addresses are Black-image addresses.
 */
void func_0219EAD8(Obj *p, const Rect *s)
{
    p->r = *s;
}







/*
 * Addresses are Black-image addresses.
 */
void func_0219EAEC(u8 *p, u32 a)
{
    u8 buf[12];
    if (p[6] != 2) {
        func_021B7EE4(((struct Obj07482 *)p)->f0, p + 4);
        func_021B8028(((struct Obj07482 *)p)->f0, buf);
        func_0216D89C(a, buf);
    }
}







void func_0219EB18(u32 a, u16 b)
{
    u8 *q = func_0219E968(a, 16);
    ((struct Obj12689 *)q)->fC = func_0219EA10(d_021D84AC, -1);
    ((struct Obj12689 *)q)->fE = b;
    func_0216D674((void *)a, 0);
    func_0216DA50((u8 *)a);
}







int func_0219EB4C(u32 o)
{
    E_0219EB4C *e;

    e = func_0216D69C((void *)o);
    e->cnt = e->cnt - 1;
    if (e->cnt <= 0) {
        e->cnt = func_0219EA10((u32 *)d_021D84AC, -1);
        func_0216D5E0((u32)o, (u16)func_0219EA24(e->val, 9));
    }
    func_0219EA78((Obj *)e, o);
}







/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219EB90(u32 *a)
{
return func_0219EA94((u32)func_0216D69C((void *)a), a);
}







void func_0219EBA0(u32 o, u32 k)
{
    E_0219EBA0 *e;
    S_0219EAD8 s;

    e = func_0219E968(o, 0x10);
    func_0219E2F4((void *)o, &s);
    e->lo = 0;
    e->z = 0;
    e->hi = k;
    e->d = s.d;
    e->c = s.c;
    func_0216D674((void *)o, 0);
    func_0216DA50((u8 *)o);
}






int func_0219EBF4(u32 o)
{
    E_0219EAD8 *e;
    u32 k;
    u16 a[4];
    u16 b[4];

    e = func_0216D69C((void *)o);
    switch (e->state) {
    case 0:
        func_0216DA50((u8 *)o);
        func_0216DA7C((u8 *)o);
        func_0216D438((char *)o, (u16)((u32)func_02197E7C((u16)((u32)func_0216D5F8((void *)o)), (u32)0)));
        e->state++;
        break;
    case 1:
        if (!func_02197EDC((u8 *)o)) {
            break;
        }
        e->cnt = func_0219EA10((u32 *)d_021D84AC, -1);
        e->state++;
    case 2:
        e->cnt--;
        if (e->cnt != 0) {
            break;
        }
        e->state++;
    case 3:
        k = func_0219EA24(e->hi, 9);
        func_0216D60C(o, k);
        if (func_0219E418(o, k)) {
            e->state = 0;
            break;
        }
        func_0219E2F4((void *)o, a);
        func_0219E664((void *)o, (u16)k, b);
        if (a[0] != b[0]) {
            e->state = 0;
            break;
        }
        if (func_0219E9A8(o, e->f, e->e, (L *)b)) {
            e->state = 0;
            break;
        }
        func_0216D438((char *)o, (u16)((u32)func_02197E7C((u16)k, (u32)0xc)));
        func_0216DA44(o);
        e->state++;
    case 4:
        if (func_02197EDC((u8 *)o)) {
            func_0216DA50((u8 *)o);
            e->state = 0;
        }
        break;
    }
    func_0219EA78((Obj *)e, o);
}






int func_0219ED7C(u32 *a)
{
return func_0219EA94((u32)func_0216D69C((void *)a), a);
}






void func_0219ED8C(u32 a)
{
    u8 *q = func_0219E968(a, 16);
    Pos pos;
    func_0219E2F4((void *)a, &pos);
    q[0xc] = 0;
    q[0xd] = 0;
    q[0xf] = pos.f6;
    q[0xe] = pos.f4;
    func_0216D674((void *)a, 0);
    func_0216DA50((u8 *)a);
}





/*
 * Addresses are Black-image addresses.
 */
int func_0219EDC4(u32 o)
{
    E *e;
    u32 s;
    u32 k;
    u32 z;
    int r;
    T c;
    T b;

    e = func_0216D69C((void *)o);
    switch (e->state) {
    case 0:
        k = func_0216D5D4((void *)o);
        if (e->d == 1) {
            k = (u32)func_021642A4((u16)k);
        }
        func_0216D60C((u32)o, (u16)k);
        e->state = 1;
    case 1:
        func_0219E2F4((void *)o, &c);
        if (e->d != 0 && e->f == c.d && e->e == c.c) {
            func_0216D60C((u32)o, (u16)((u32)func_021642A4((u16)func_0216D608((void *)o))));
            e->d = 0;
        }
        z = 0;
        k = func_0216D608((void *)o);
        s = (u32)func_0219E418(o, (u16)k);
        func_0219E664((void *)o, (u16)k, &b);
        r = func_0219E9A8(o, e->f, e->e, (L *)&b);
        if (c.a != b.a) {
            z = 1;
        }
        if ((s & 1) || r || z) {
            e->d = 1;
            k = (u32)func_021642A4((u16)k);
            s = (u32)func_0219E418(o, (u16)k);
            func_0219E664((void *)o, (u16)k, &b);
        }
        func_0216D438((char *)o, (u16)((u32)func_02197E7C((u16)k, (u16)(s == 0 ? 0xc : 0x20))));
        func_0216DA44(o);
        e->state = 2;
        break;
    case 2:
        if (func_02197EDC((u8 *)o) == 1) {
            func_0216DA50((u8 *)o);
            e->state = 0;
        }
        break;
    }
    func_0219EA78((Obj *)e, o);
}





/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219EF04(u32 *a)
{
return func_0219EA94((u32)func_0216D69C((void *)a), a);
}





void func_0219EF14(u8 *p)
{
    func_02082BCC(p, 0, 0x30);
    ((struct Obj05014 *)p)->f8 = 0x14;
    ((struct Obj05014 *)p)->fA = 3;
    ((struct Obj05014 *)p)->fC = 3;
    ((struct Obj05014 *)p)->f20 = d_021DDDB8;
    ((struct Obj05014 *)p)->f24 = d_021DDDA0;
    ((struct Obj05014 *)p)->f28 = d_021DDDAC;
}





u8 *func_0219EF44(u32 heap)
{
    u8 *p = (u8 *)func_02030734((u16)heap, 0x38, 1, d_021DDE08, 0xC0);
    func_0219EF14(p + 8);
    return p;
}





/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_0219EF6C(u8 *p)
{
    func_0219EFFC(p);
    func_020307B0(p);
}





void func_0219EF7C(struct S *p, u32 b, u32 c)
{
    u32 loc;
    p->f0 = (u32 *)func_0204A298(0x4f, b, 0, (u16)c, &loc);
    p->f4 = loc;
    p->f18 = (u32)p->f0 + p->f0[2];
    p->h8 = func_0209C2B0(p->f0[3] - p->f0[2], 0x70);
    p->f1c = (u32)p->f0 + p->f0[3];
    p->hA = func_0209C2B0(p->f0[4] - p->f0[3], 0x48);
    p->f20 = (u32)p->f0 + p->f0[4];
    p->hC = func_0209C2B0(p->f0[5] - p->f0[4], 0x24);
    p->f24 = (u32)p->f0 + p->f0[5];
    p->hE = func_0209C2B0(p->f0[6] - p->f0[5], 0x24);
    p->f34 = *(u32 *)((u8 *)p->f0 + p->f0[1]);
}



/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_0219EFFC(u8 *a)
{
    if (((struct Obj09178 *)a)->f0 != 0) {
        func_020307B0((void *)(((struct Obj09178 *)a)->f0));
        ((struct Obj09178 *)a)->f0 = 0;
    }
    func_0219EF14(a + 8);
}



/*
 * Returns the object pointer advanced by 0x8 bytes.
 */
u8 *func_0219F018(u8 *p)
{
    return p + 0x8;
}



int func_0219F01C(u32 a, u32 b, u32 c, u32 e0, u32 e1, u16 id)
{
return (int)func_02158768(a, ((c << 16) >> 16), e1, *(u16 *)((u8 *)((u8 *)&e1) + 4));
}



int func_0219F030(void *a, u32 b, u32 c, u32 d)
{
func_0216DAC8((unsigned int *)a, 1);
return (int)func_0216D568(a, (1 << 15));
}


void func_0219F048(void)
{
}


void func_0219F04C(void)
{
}


void func_0219F050(void)
{
}


void func_0219F054(void)
{
}
