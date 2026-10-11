/*
 * file:     btl_server_p24.c
 * unit:     yes
 * function: func_021CC768, func_021CC800, func_021CC8A0, func_021CC8B0, func_021CC8B8, func_021CC8C0, func_021CC8C8, func_021CC8D8, func_021CC918, func_021CC95C, func_021CC960, func_021CC96C, func_021CC974, func_021CC99C, func_021CC9A4, func_021CC9AC, func_021CCA74, func_021CCAA8, func_021CCAD4, func_021CCAE0, func_021CCB18, func_021CCB34, func_021CCB78, func_021CCB98, func_021CCBE8, func_021CCC0C, func_021CD0F0, func_021CD4B0, func_021CD4FC, func_021CD568, func_021CD5E0, func_021CD63C, func_021CD644, func_021CD64C, func_021CD6AC, func_021CD6EC, func_021CD6F0, func_021CD8E0, func_021CD914, func_021CD924, func_021CD938, func_021CD95C, func_021CD960, func_021CD978, func_021CD97C, func_021CD984, func_021CD9B0, func_021CD9C8, func_021CD9DC, func_021CD9E0, func_021CD9F4, func_021CDA0C, func_021CDA18, func_021CDC0C, func_021CDD34, func_021CDD50, func_021CDD94, func_021CDDA0, func_021CDDCC, func_021CDDDC, func_021CDE8C, func_021CDECC, func_021CDEE8, func_021CDF1C, func_021CDF58, func_021CDFE4, func_021CE040, func_021CE044, func_021CE068, func_021CE08C, func_021CE0BC, func_021CE0E0, func_021CE0F8, func_021CE150, func_021CE160, func_021CE170, func_021CE1B0, func_021CE2E8, func_021CE308, func_021CE3B4, func_021CE3C8, func_021CE4D0, func_021CE7D4, func_021CE8F0, func_021CEA94, func_021CECB4, func_021CED4C, func_021CEDC0
 * address:  0x021CC768
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
 *   func_021B8B9C  0x021B8B9C  thumb  ov093
 *   func_021B8BC4  0x021B8BC4  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   _u32_div_f     0x0209C2B0  arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021EFE9C     0x021EFE9C  data  a4
 *   data_021F3A84 0x021F3A84 data
 *   func_02034714 0x02034714 arm
 *   data_021EFF14  0x021EFF14  data  ov093
 *   data_021F3B44  0x021F3B44  data  ov093
 *   func_02030734 0x02030734 arm
 *   d_021F3A88 0x021F3A88 data a4
 *   func_021EEA58 0x021EEA58 thumb ov093
 *   func_021B9AF8 0x021B9AF8 thumb ov093
 *   func_021BA08C 0x021BA08C thumb ov093
 *   func_021D8230 0x021D8230 thumb ov093
 *   func_021D3F04 0x021D3F04 thumb ov093
 *   func_021D3D9C 0x021D3D9C thumb ov093
 *   func_021B9FBC 0x021B9FBC thumb ov093
 *   func_021BA820 0x021BA820 thumb ov093
 *   func_02187F00 0x02187F00 thumb ov096
 *   func_021B90F8 0x021B90F8 thumb ov093
 *   func_021EE5E4 0x021EE5E4 thumb ov093
 *   func_021EE600 0x021EE600 thumb ov093
 *   func_02188080 0x02188080 thumb ov096
 *   func_020307B0 0x020307B0 arm
 *   func_021EEAE0 0x021EEAE0 thumb ov093
 *   func_021EE63C 0x021EE63C thumb ov093
 *   func_021EE830 0x021EE830 thumb ov093
 *   func_021D3F48 0x021D3F48 thumb ov093
 *   func_021EE674 0x021EE674 thumb ov093
 *   func_021EEBDC 0x021EEBDC thumb ov093
 *   func_021D3F64 0x021D3F64 thumb ov093
 *   func_021D3F88 0x021D3F88 thumb ov093
 *   func_021D3FDC 0x021D3FDC thumb ov093
 *   func_021EEBE8 0x021EEBE8 thumb ov093
 *   func_021EEC20 0x021EEC20 thumb ov093
 *   func_021D3FAC 0x021D3FAC thumb ov093
 *   func_021D3FC4 0x021D3FC4 thumb ov093
 *   func_021D3F4C 0x021D3F4C thumb ov093
 *   func_021EEC4C 0x021EEC4C thumb ov093
 *   func_021D3F60 0x021D3F60 thumb ov093
 *   func_02005CA4 0x02005CA4 thumb
 *   func_02006740 0x02006740 thumb
 *   func_02005E50 0x02005E50 thumb
 *   func_021D3FA8 0x021D3FA8 thumb ov093
 *   func_021BA73C 0x021BA73C thumb ov093
 *   func_02006734 0x02006734 thumb
 *   func_021D3F98 0x021D3F98 thumb ov093
 *   func_021EAE24 0x021EAE24 thumb ov093
 *   func_02005DF8 0x02005DF8 thumb
 *   func_021F88BC 0x021F88BC thumb ov094
 *   func_021F8678 0x021F8678 thumb ov094
 *   func_021EAE34 0x021EAE34 thumb ov093
 *   func_021EAE74 0x021EAE74 thumb ov093
 *   func_021BA7F8 0x021BA7F8 thumb ov093
 *   d_021EFFEC 0x021EFFEC data a4
 *   func_021F8524 0x021F8524 thumb ov094
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021E90A0  0x021E90A0  thumb  ov093
 *   func_021E90D0  0x021E90D0  thumb  ov093
 *   func_021BA5C4  0x021BA5C4  thumb  ov093
 *   func_021BA5D0  0x021BA5D0  thumb  ov093
 *   func_021F84E8  0x021F84E8  thumb  ov094
 *   func_021F8504  0x021F8504  thumb  ov094
 *   func_021EAEA8  0x021EAEA8  thumb  ov093
 *   func_021EE688  0x021EE688  thumb  ov093
 *   func_021D3F54  0x021D3F54  thumb  ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B86C0 0x021B86C0 thumb ov093
 *   func_021B9064 0x021B9064 thumb ov093
 *   func_021B9920 0x021B9920 thumb ov093
 *   func_021EAA00  0x021EAA00  thumb  ov093
 *   func_021EAA5C  0x021EAA5C  thumb  ov093
 *   func_021EAA34  0x021EAA34  thumb  ov093
 *   func_0203F0A8  0x0203F0A8  arm
 *   _ull_mul       0x0209C054  arm
 *   func_021EAF18  0x021EAF18  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021EAF50  0x021EAF50  thumb  ov093
 *   func_021EAF78  0x021EAF78  thumb  ov093
 *   func_021EE6B8 0x021EE6B8 thumb ov093
 *   func_021D3FD0 0x021D3FD0 thumb ov093
 *   func_021EA614 0x021EA614 thumb ov093
 *   func_021EA710 0x021EA710 thumb ov093
 *   func_021D8434 0x021D8434 thumb ov093
 *   func_021D0B10  0x021D0B10  thumb  ov093
 *   func_021CF41C  0x021CF41C  thumb  ov093
 *   func_021CF360  0x021CF360  thumb  ov093
 *   func_021B990C  0x021B990C  thumb  ov093
 *   func_021CF470  0x021CF470  thumb  ov093
 *   func_021EAE44 0x021EAE44 thumb ov093
 *   func_021EAE54 0x021EAE54 thumb ov093
 *   func_021CF81C 0x021CF81C thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_021D81F8 0x021D81F8 thumb ov093
 *   func_021D82D0 0x021D82D0 thumb ov093
 *   func_021CF58C 0x021CF58C thumb ov093
 *   func_021CF2F0 0x021CF2F0 thumb ov093
 *   func_021EA65C 0x021EA65C thumb ov093
 *   func_021E9760 0x021E9760 thumb ov093
 *   func_021E979C 0x021E979C thumb ov093
 *   func_021E97A4 0x021E97A4 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021E9964 0x021E9964 thumb ov093
 *   func_021CF430 0x021CF430 thumb ov093
 *   func_021BA1EC 0x021BA1EC thumb ov093
 *   func_021B86E4 0x021B86E4 thumb ov093
 *   func_021CF43C 0x021CF43C thumb ov093
 *   func_021D8454 0x021D8454 thumb ov093
 *   func_021CE7C4 0x021CE7C4 thumb ov093
 *   func_021CF3B8 0x021CF3B8 thumb ov093
 *   func_021E9974 0x021E9974 thumb ov093
 *   func_021E9954 0x021E9954 thumb ov093
 *   func_021CF220 0x021CF220 thumb ov093
 *   func_021CEEB8 0x021CEEB8 thumb ov093
 *   func_021CF078 0x021CF078 thumb ov093
 *   func_021B904C 0x021B904C thumb ov093
 *   func_021BA004 0x021BA004 thumb ov093
 *   func_021BA020 0x021BA020 thumb ov093
 *   func_021F7F58 0x021F7F58 thumb ov094
 *   func_021F7998 0x021F7998 thumb ov094
 *   func_021EA6B0 0x021EA6B0 thumb ov093
 *   func_021D7F38 0x021D7F38 thumb ov093
 *   func_021F87EC 0x021F87EC thumb ov094
 *   func_021F8774 0x021F8774 thumb ov094
 *   func_02005E30 0x02005E30 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021B99B8 0x021B99B8 thumb ov093
 *   func_0202A298 0x0202A298 thumb
 *   func_021D7B60 0x021D7B60 thumb ov093
 *   func_021D5B48 0x021D5B48 thumb ov093
 *   func_021B9B98 0x021B9B98 thumb ov093
 *   d_021EFF78 0x021EFF78 data ov093 a2
 *   func_021CF524 0x021CF524 thumb ov093
 *   func_021E97BC 0x021E97BC thumb ov093
 *   func_021E9808 0x021E9808 thumb ov093
 *   func_021E98AC 0x021E98AC thumb ov093
 *   func_021E98B4 0x021E98B4 thumb ov093
 *   func_021B9AB0 0x021B9AB0 thumb ov093
 *   func_021D832C 0x021D832C thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_021CF5B0 0x021CF5B0 thumb ov093
 *   func_021D8340 0x021D8340 thumb ov093
 *   func_021D83FC 0x021D83FC thumb ov093
 *   func_021D7EF0 0x021D7EF0 thumb ov093
 *   func_021E98BC 0x021E98BC thumb ov093
 *   func_021E9920 0x021E9920 thumb ov093
 *   func_021E98E8 0x021E98E8 thumb ov093
 *   func_021E9858 0x021E9858 thumb ov093
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021D5584  0x021D5584  thumb  ov093
 *   func_021E9CE0  0x021E9CE0  thumb  ov093
 *   func_021E9B14  0x021E9B14  thumb  ov093
 *   func_021E9B20  0x021E9B20  thumb  ov093
 *   func_021CF8D4 0x021CF8D4 thumb ov093
 *   func_021E9A78 0x021E9A78 thumb ov093
 *   func_021CEE98 0x021CEE98 thumb ov093
 *   func_021CEEA8 0x021CEEA8 thumb ov093
 *   func_021D8394 0x021D8394 thumb ov093
 */
#include "../../matched/include/Obj09984.h"
#include "../../matched/include/Obj21130.h"
#include "../../matched/include/Obj18356.h"
#include "../../matched/include/Obj01891.h"
#include "../../matched/include/Obj05197.h"
#include "../../matched/include/Obj13352.h"
#include "../../matched/include/Obj13353.h"
#include "../../matched/include/Obj07767.h"
#include "../../matched/include/Obj18365.h"
#include "../../matched/include/Obj18367.h"
#include "../../matched/include/Obj00463.h"
#include "../../matched/include/Obj00818.h"
#include "../../matched/include/Obj09986.h"
#include "../../matched/include/Obj01689.h"
#include "../../matched/include/Obj06232.h"
#include "../../matched/include/Obj04362.h"
#include "../../matched/include/Obj01892.h"
#include "../../matched/include/Obj07768.h"
#include "../../matched/include/Obj21134.h"
#include "../../matched/include/Obj13355.h"
#include "../../matched/include/Obj01893.h"
#include "../../matched/include/Obj07769.h"
#include "../../matched/include/Obj03688.h"
#include "../../matched/include/Obj13356.h"
#include "../../matched/include/Obj00662.h"
#include "../../matched/include/Obj02785.h"
#include "../../matched/include/Obj03689.h"
#include "../../matched/include/Obj00434.h"
#include "../../matched/include/Obj21136.h"
#include "../../matched/include/Obj05199.h"
#include "../../matched/include/Obj03194.h"

#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += 4) - 4))
#define Q ((struct L *)p)
#define W(o) (*(u32 *)(p+(o)))
#define P(o) (*(void **)(p+(o)))
struct S2;
struct Q1;
struct Q2;
struct QE;
struct S;
struct Qd;
struct Q3;
struct L;
struct H;
struct Unk021D82D0;
struct Unk021D62A8;
struct UtilWork;
struct Unk021D82FC;
struct QG;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Lock {
    u32 a : 10;
    u32 b : 9;
    u32 c : 9;
    u32 d : 1;
    u32 e : 1;
    u32 f : 1;
    u32 g : 1;
};

typedef struct {
    u32 a : 10;
    u32 b : 9;
    u32 c : 9;
    u32 d : 1;
    u32 e : 1;
    u32 f : 1;
    u32 g : 1;
} Bf;

struct S {
    unsigned int x : 10;
};

/* 021CC96C  ldr r0,[r0]; lsls #1; lsrs #0x1f */
struct Q9 { u32 a : 30; u32 b : 1; u32 c : 1; };

typedef struct { unsigned low:28, a:1, b:1, c:1, d:1; } Word;

/* 021CC99C  ldr r0,[r0]; lsls #3; lsrs #0x1f */
struct Q10 { u32 a : 28; u32 b : 1; u32 c : 3; };

struct SizeEntry {
    u8 id;
    u8 size;
};

struct Rec {
    u32 id : 8;
    u32 b : 5;
    u32 size : 10;
    u32 x : 1;
    u32 pad : 2;
    u32 y : 1;
    u32 rest : 5;
};

struct Pack {
    u32 lo : 10;
    u32 off : 9;
    u32 rest : 13;
    u8 data[500];
};

typedef struct { unsigned low:10, size:9, high:13; } A;

typedef struct { unsigned low:13, size:10, high:9; } B;

typedef struct {
    u32 unk0;
    u32 pos;
} ByteStream;

typedef char *va_list;

typedef struct {
    u32 wpos;
    u32 rpos;
    u8 buf[3000];
} Buf_021CC768;

typedef struct { u8 f0:1,f1:1,f2:1,f3:1,f4:1,f5:1,rest:2; } Flags_021CC768;

struct Copy24 { int x[6]; };

/* 021CD95C  str r1,[r0,#0x54] */
struct QA { u8 pad[0x54]; u32 v; };

/* 021CD978  ldr r0,[r0,#0x50] */
struct QB { u8 pad[0x50]; u32 v; };

/* 021CD97C  push {r3,lr}; ldr r1,[r0,#0x28]; blx r1; pop {r3,pc} */
struct R2 { u8 pad[0x28]; void (*fn)(struct R2 *); };

/* 021CD9DC  ldrh r0,[r0,#0x22] */
struct QD { u8 pad[0x22]; u16 v; };

/* 021CDA0C  str r1,[r0,#0x28]; movs r1,#0x6a; movs r2,#0; lsls r1,#2;
 *           strb r2,[r0,r1] */
struct QE { u8 pad[0x28]; u32 v; u8 rest[0x1a8 - 0x2c]; u8 z; };

typedef int (*Callback)(u8 *,int *);

typedef struct { u8 f0:1,f1:1,f2:1,f3:1,f4:1,f5:1,rest:2; } Flags_021CDA18;

typedef struct { u8 id; u8 flag; u16 pad; Callback callbacks[3]; } Entry;

typedef struct {
    int a;
    int b;
} S;

struct Flags_021CDDA0 { u8 pad[0x1b2]; u8 low:4; u8 flag:1; u8 high:3; };

struct Flags_021CDDCC { u8 pad[0x1b2]; u8 low:5; u8 flag:1; u8 high:2; };

typedef unsigned long long u64;

typedef struct { u8 a : 5; u8 flag : 1; } Flags_021CE1B0;

typedef struct { u32 kind : 4; u32 rest : 28; } Command;

typedef struct { u8 a : 2; u8 f : 1; } Flags_021CE308;

struct L { u8 pad[0x11D]; u8 idx; u8 pad2[0x1A6-0x11E]; u8 sel; };

typedef struct { u8 flag : 1; u8 rest : 7; } Flags_021CE7D4;

typedef enum { OFFSET = 0x19a } Off;

struct Offsets { Off skip,ok0,ok1,ok2,ok3,invalid; };

typedef struct { u32 kind:4; u32 sub:3; u32 id:16; u32 rest:9; } Record;

typedef struct { u8 *q; u8 f[4]; } Ent;

extern int func_021B8B9C(unsigned char *p, unsigned char k);
extern unsigned char func_021B8BC4(int unused, unsigned int b);
extern char *func_021B9AEC(char *p, int i);
extern u8 func_021B9B94(struct Q1 *p);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D59B4(u8 *p, int k);
extern u32 _u32_div_f(u32, u32);
extern void func_02082BCC(void *, int, u32);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u16, u32, int, const char *, u16);
extern void *func_021EEA58(u32, int, u32, u32);
extern char *func_021B9AF8(char *, int);
extern u32 func_021BA08C(struct Q2 *p);
extern void func_021D8230(u8 *);
extern void func_021D3F04(u8 *);
extern void func_021D3D9C(u8 *);
extern int func_021B9FBC(char *, int);
extern u32 func_021BA820(int *);
extern void *func_02187F00(void **, u32, u32, u32, u16);
extern int func_021B90F8(u8 *);
extern void *func_021EE5E4(u32);
extern void func_021EE600(void *);
extern void func_02188080(void *);
extern u32 func_020307B0(void *p);
extern void func_021EEAE0(void *);
extern u16 *func_021EE63C(u16 *, u32 *);
extern u32 func_021EE830(void *);
extern void func_021D3F48(u8 *,u32);
extern void func_021EE674(void *);
extern void func_021EEBDC(void *);
extern void func_021D3F64(u8 *,u16);
extern void func_021D3F88(struct S *p);
extern void func_021D3FDC(u8 *p, struct Qd *q);
extern u8 func_021EEBE8(void *);
extern int func_021EEC20(int,u32 **);
extern int func_021D3FAC(u8 *);
extern void func_021D3FC4(u8 *);
extern int func_021D3F4C(void *);
extern int func_021EEC4C(void *,void *,u32);
extern u8 func_021D3F60(u8 *);
extern void func_02005CA4(int,u32);
extern void func_02006740(void);
extern int func_02005E50(void);
extern u16 func_021D3FA8(u8 *p);
extern void func_021BA73C(char *,int);
extern void func_02006734(u8);
extern int func_021D3F98(u8 *);
extern void func_021EAE24(u8 *p);
extern void func_02005DF8(u32 a);
extern void func_021F88BC(int);
extern void *func_021F8678(void);
extern int func_021EAE34(u8 *p);
extern void func_021EAE74(char *p, u32 a, u32 b);
extern void func_021BA7F8(char *p);
extern int func_021F8524(int);
extern void *func_021B86B8(void ***p);
extern void func_021E90A0(unsigned int *o, unsigned int key);
extern int func_021E90D0(struct S *s);
extern u16 func_021BA5C4(u8 *p);
extern u16 func_021BA5D0(struct Q3 *p);
extern void func_021F84E8(int a, int b);
extern void func_021F8504(u32 a, u32 b, u32 c);
extern void func_021EAEA8(u8 *p, int v);
extern int func_021EE688(int, int);
extern void func_021D3F54(u8 *p);
extern u32 func_021B8588(void **);
extern u8 func_021B86C0(u8 **);
extern u32 func_021B9064(u8 *p, int k, int x);
extern u8 *func_021B9920(void *p, u32 i, u8 j);
extern void func_021EAA00(u8 *p, u8 v);
extern void func_021EAA5C(u8 *o);
extern int func_021EAA34(u8 *o, u8 *out);
extern u32 func_0203F0A8(void);
extern void func_021EAF18(struct L *p, int kind, int id);
extern u8 func_021D5440(u8 *p);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EAF78(u8 *o, u8 v);
extern u32 *func_021EE6B8(void *,u8,u8 *,u8 *);
extern void func_021D3FD0(unsigned char *p);
extern void func_021EA614(char *p, struct H *h);
extern int func_021EA710(u32 *p);
extern void func_021D8434(u32 *p);
extern void func_021D0B10(u8 *p, u32 a, u32 b, void *q, void *out);
extern void func_021CF41C(u8 *p);
extern void func_021CF360(u8 *p);
extern void *func_021B990C(char *p, unsigned int i, unsigned int j);
extern u32 func_021CF470(u8 *p, void *q, u8 *o);
extern void func_021EAE44(void *);
extern int func_021EAE54(void *);
extern u32 func_021CF81C(u8 *,void *,u8 *);
extern u16 func_021D54C0(u8 *p, int i);
extern u32 func_021D81F8(void *,void *,void *,u32,void *);
extern void func_021D82D0(struct Unk021D82D0 *out, u32 id, u32 sub);
extern void func_021CF58C(struct Unk021D82D0 *out, u8 *p, void *q);
extern u32 func_021CF2F0(u8 *p, s32 *st);
extern void func_021EA65C(char *p, struct H *h);
extern void func_021E9760(char *, u8 *, int, int);
extern void func_021E979C(char *p);
extern int func_021E97A4(char *p);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021E9964(u32);
extern void func_021CF430(u8 *, u32, u32);
extern int func_021BA1EC(char **p);
extern int func_021B86E4(unsigned int **p);
extern u8 func_021CF43C(u8 *, u32);
extern u32 func_021D8454(u32 *);
extern void func_021CE7C4(u8 *);
extern void func_021CF3B8(u8 *, u32);
extern int func_021E9974(u32);
extern void func_021E9954(void *);
extern u32 func_021CF220(u8 *p, int *st);
extern u32 func_021CEEB8(u8 *p, int *st);
extern u32 func_021CF078(u8 *p, u32 *st);
extern u8 func_021B904C(u8 *p, int k);
extern u16 func_021BA004(char *p, int i);
extern unsigned short func_021BA020(char *p, int i);
extern void func_021F7F58(int, u32, u32, u32, u32);
extern void func_021F7998(u32 a);
extern int func_021EA6B0(char *, u16, u16);
extern int func_021D7F38(u32 n);
extern void func_021F87EC(u32);
extern int func_021F8774(void);
extern void func_02005E30(u32);
extern void func_02005D90(u16, u16);
extern int func_021F7EB4(void);
extern int func_021D5B68(void *);
extern int func_021B99B8(void *pp, unsigned int b);
extern u32 func_0202A298(u32,u32,u32);
extern u32 func_021D7B60(void *p, u32 b);
extern int func_021D5B48(u8 *p);
extern u8 func_021B9B98(u8 *p);
extern u32 func_021CF524(u32, void *, u32);
extern void func_021E97BC(char *p, u8 *a, int b);
extern void func_021E9808(char *p, u32 *q, int c);
extern void func_021E98AC(void *);
extern u32 func_021E98B4(void *);
extern int func_021B9AB0(int);
extern u32 func_021D832C(struct Unk021D82FC *p);
extern u8 func_021D5778(struct UtilWork *p, u16 id);
extern int func_021CF5B0(u8 *g, void *m, u32 move, void *out);
extern u32 func_021D8340(u32 *);
extern void func_021D83FC(u32 *p, u32 sub);
extern u32 func_021D7EF0(u32);
extern void func_021E98BC(char *p, u8 *a, int b);
extern void func_021E9920(void *);
extern int func_021E98E8(char *p);
extern void func_021E9858(char *p);
extern u8 func_021D5448(struct QG *p);
extern u8 func_021D5584(struct UtilWork *p, u32 i);
extern void func_021E9CE0(u8 *p, u8 a, u8 b);
extern void func_021E9B14(unsigned int *p);
extern int func_021E9B20(u8 *p);
extern u32 func_021CF8D4(u8 *, void *, u8 *, u16 *);
extern void func_021E9A78(char *, const u8 *, int, int, u8 *);
extern u32 func_021CEE98(u8 *);
extern u32 func_021CEEA8(u8 *);
extern void func_021D8394(void *, u8, u32);
int func_021CC768(void *a, u8 *p, u8 *q, int want);
void func_021CC800(u8 *a, u32 *out1, u32 *out2, u8 want);
void func_021CC8A0(u32 *p);
void func_021CC8B0(u32 *p, u32 i, u32 b);
u32 func_021CC8B8(u32 *p, u32 i);
u32 func_021CC8C0(u32 *p, u32 i);
void func_021CC8C8(u32 *p);
struct Lock func_021CC8D8(struct Lock *p, int line);
u32 func_021CC918(Bf *p, u32 v);
void func_021CC95C(u32 *p, u32 v, int line);
unsigned short func_021CC960(struct S *p);
int func_021CC96C(struct Q9 *p);
void func_021CC974(Word *p,int flag);
int func_021CC99C(struct Q10 *p);
u32 func_021CC9A4(u32 *p);
struct Rec *func_021CC9AC(struct Pack *p, int id, int b);
void func_021CCA74(A *p,B *q);
void func_021CCAA8(Buf_021CC768 *p,u8 v);
u8 func_021CCAD4(u8 *p);
void func_021CCAE0(Buf_021CC768 *p,u16 v);
u32 func_021CCB18(Buf_021CC768 *p);
void func_021CCB34(Buf_021CC768 *w, u32 v);
u32 func_021CCB78(ByteStream *s);
void func_021CCB98(Buf_021CC768 *w, u32 v);
u32 func_021CCBE8(Buf_021CC768 *p);
void func_021CCC0C(void *w, u32 id, int cmd, s32 *a);
void func_021CD0F0(void *r, int cmd, s32 *a);
void func_021CD4B0(void *w, volatile u32 id, ...);
u32 func_021CD4FC(Buf_021CC768 *w, u32 id);
void func_021CD568(Buf_021CC768 *w, u32 x, u32 id, ...);
int func_021CD5E0(Buf_021CC768 *r, s32 *a);
void func_021CD63C(void *p, u8 v);
u8 func_021CD644(u8 *p);
void func_021CD64C(void *w, u8 id, ...);
void func_021CD6AC(void *r, u8 cmd, s32 *out);
void func_021CD6EC(void);
u8 *func_021CD6F0(u8 *a, u8 *b, int c, int d, u16 idx, u16 kind, u8 e, int f, int g, struct Copy24 *h, u16 heap);
void func_021CD8E0(u8 *p);
void func_021CD914(u8 *p);
u16 *func_021CD924(u8 *p, u32 *out);
void func_021CD938(u8 *p,void *a);
void func_021CD95C(struct QA *p, u32 v);
void func_021CD960(u8 *p, u32 v);
u32 func_021CD978(struct QB *p);
void func_021CD97C(struct R2 *p);
void func_021CD984(u8 *p,u16 n);
void func_021CD9B0(u8 *p);
u32 func_021CD9C8(u8 *p);
u16 func_021CD9DC(struct QD *p);
u32 func_021CD9E0(u8 *p);
void func_021CD9F4(u8 *p,u8 n);
void func_021CDA0C(struct QE *p, u32 v);
int func_021CDA18(u8 *p);
int func_021CDC0C(u8 *p);
void func_021CDD34(u8 *p);
Callback func_021CDD50(u8 *p,u32 id,int *out);
void func_021CDD94(char *p, int *o);
int func_021CDDA0(u8 *p);
u32 func_021CDDCC(struct Flags_021CDDCC *p);
int func_021CDDDC(u8 *p, int *st);
int func_021CDE8C(int a, int b);
void func_021CDECC(u8 *p);
u32 func_021CDEE8(u8 *p);
void *func_021CDF1C(u8 *p);
int func_021CDF58(u8 *p, int *st);
u32 func_021CDFE4(u32 mode);
int func_021CE040(void);
void func_021CE044(u8 *p);
void func_021CE068(u8 *p);
int func_021CE08C(u8 *p);
int func_021CE0BC(u8 *p,void *q);
void func_021CE0E0(u8 *p);
void func_021CE0F8(u8 *p, u8 *q, u8 *o);
void func_021CE150(u8 *p, void *q);
u32 func_021CE160(u8 *p);
u32 func_021CE170(u8 *p, s32 *st);
int func_021CE1B0(u8 *p,int *state);
void func_021CE2E8(u8 *p);
u32 func_021CE308(u8 *p);
void func_021CE3B4(u8 *p, void *q);
int func_021CE3C8(u8 *p,int *state);
int func_021CE4D0(u8 *p, u32 *st);
u32 func_021CE7D4(u8 *p, int *st);
u32 func_021CE8F0(const u8 *p, u16 *out);
int func_021CEA94(u8 *p, u32 *state);
void func_021CECB4(u8 *p, Ent *out);
u32 func_021CED4C(u8 *p, s32 *st);
u32 func_021CEDC0(u8 *p, int *st);
extern struct SizeEntry d_021EFE9C[0x3B];
extern char data_021F3A84[];
extern const u8 data_021EFF14[];
extern s32 data_021F3B44[];
extern u8 d_021F3A88[];
extern const Entry d_021EFFEC[15];
extern const u16 d_021EFF78[4];








int func_021CC768(void *a, u8 *p, u8 *q, int want)
{
    int d0;
    int d1;
    int res;
    int vc;
    int v8;
    int v4;
    int v0;

    d0 = q[0] - p[0];
    d1 = q[1] - p[1];
    if (d0 != d1) {
        res = 1;
        if (d0 < d1)
            res = 0;
        if ((u8)res == want)
            return 1;
        return 0;
    }
    func_021CC800(a, (u32 *)(&v8), (u32 *)(&v0), 0);
    func_021CC800(a, (u32 *)(&vc), (u32 *)(&v4), 1);
    if (v0 != v4) {
        res = 1;
        if (v0 > v4)
            res = 0;
        if ((u8)res == want)
            return 1;
        return 0;
    }
    if (v8 != vc) {
        res = 1;
        if (v8 > vc)
            res = 0;
        if ((u8)res == want)
            return 1;
        return 0;
    }
    return 2;
}








void func_021CC800(u8 *a, u32 *out1, u32 *out2, u8 want)
{
    u32 sum;
    u32 j;
    u32 i;
    char *p;
    u32 n;
    u8 *t;

    sum = 0;
    *out1 = 0;
    *out2 = 0;
    for (j = 0; j < 4; j++) {
        if (func_021B8B9C(((struct Obj09984 *)a)->f4, j) != 0 &&
            want == func_021B8BC4((int)(((struct Obj09984 *)a)->f4), (u8)j)) {
            p = func_021B9AEC(((struct Obj09984 *)a)->f8, j);
            n = func_021B9B94((struct Q1 *)p);
            for (i = 0; i < n; i++) {
                t = func_021B9C00((struct S2 *)p, (u8)i);
                sum += func_021D59B4(t, 14);
                *out1 += func_021D59B4(t, 13);
            }
        }
    }
    *out2 = _u32_div_f(*out1 * 100, sum);
}







void func_021CC8A0(u32 *p) { u32 i; for (i=0;i<24;i++) p[i]=6; }








void func_021CC8B0(u32 *p, u32 i, u32 b)
{
    *(u32 *)&p[i] = b;
}








/*
 * indexed load
 */
u32 func_021CC8B8(u32 *p, u32 i)
{
    return p[i];
}








u32 func_021CC8C0(u32 *p, u32 i)
{
    return p[i];
}






void func_021CC8C8(u32 *p) { *p++=0; func_02082BCC(p,0,500); }






struct Lock func_021CC8D8(struct Lock *p, int line)
{
    struct Lock old = *p;
    p->a = 0;
    p->c = p->b;
    p->e = 0;
    p->d = 0;
    p->f = 0;
    return old;
}







u32 func_021CC918(Bf *p, u32 v)
{
    u32 old = ((struct Obj21130 *)p)->f0;
    p->a = v;
    p->c = p->b;
    p->e = 0;
    p->d = 0;
    p->f = 0;
    return old;
}







/* 021CC95C  str r1,[r0] */
/*
 * Stores the second argument (a u32) into the field at offset 0.
 */
void func_021CC95C(u32 *p, u32 v, int line) { *p = v; }







unsigned short func_021CC960(struct S *p)
{
    return p->x;
}






/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; lsls r0, r0, #1; lsrs r0, r0, #0x1f; bx lr.
 */
int func_021CC96C(struct Q9 *p) { return p->b; }






void func_021CC974(Word *p,int flag) { if(flag) {p->a=1;p->b=1;} else p->a=0; p->c=1; }






/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; lsls r0, r0, #3; lsrs r0, r0, #0x1f; bx lr.
 */
int func_021CC99C(struct Q10 *p) { return p->b; }







u32 func_021CC9A4(u32 *p)
{
    return (((struct Obj18356 *)p)->f0 << 2) >> 31;
}







struct Rec *func_021CC9AC(struct Pack *p, int id, int b)
{
    u32 i;
    u32 size;
    u32 off;
    u32 j;
    struct Rec *rec;

    i = 0;
    size = 0;
    for (; i < 0x3B; i++) {
        if (id == d_021EFE9C[i].id) {
            size = d_021EFE9C[i].size;
            break;
        }
    }
    if (size != 0) {
        while (size & 3) {
            size++;
        }
        off = p->off;
        if (off + size <= 500) {
            rec = (struct Rec *)(p->data + off);
            for (j = 0; j < size; j++) {
                p->data[p->off + j] = 0;
            }
            rec->id = id;
            rec->size = size;
            rec->b = b;
            rec->x = 0;
            rec->y = 1;
            p->off = p->off + size;
            return rec;
        }
    }
    return 0;
}






void func_021CCA74(A *p,B *q) { unsigned a,b,t; a=p->size;b=q->size;if(b<=a) {t=(u32)q-((u32)p+4);t+=b;if(t==a) p->size=a-b;} }






void func_021CCAA8(Buf_021CC768 *p,u8 v) {if(p->wpos>=3000)func_02034714(data_021F3A84,0,data_021F3A84);p->buf[p->wpos++]=v;}







/* 021CCAD4  ldr r2,[r0,#4]; adds r1,r2,#1; str r1,[r0,#4]; adds r0,r0,r2;
 *           ldrb r0,[r0,#8] */
/*
 * Leaf with no calls and no pool; 6 instructions, 12 bytes: ldr r2, [r0, #4]; adds r1, r2, #1; str r1, [r0, #4]; adds r0, r0, r2; ldrb r0, [r0, #8]; bx lr.
 */
u8 func_021CCAD4(u8 *p)
{
    u32 off = ((struct Obj01891 *)p)->f4;
    ((struct Obj01891 *)p)->f4 = off + 1;
    return *(u8 *)(p + off + 8);
}






void func_021CCAE0(Buf_021CC768 *p,u16 v) {if(p->wpos>=2999)func_02034714(data_021F3A84,0,data_021F3A84);p->buf[p->wpos++]=v>>8;p->buf[p->wpos++]=v;}







/*
 * lever: Once-300 permuter expands the byte-source local and binds rpos
 *        separately before the two loads; retain unsigned full-word cursor.
 *        The signed 32-bit temporary preserves its input bits; convert back
 *        to u32 before every modular address sum, then cast the final address.
 */
u32 func_021CCB18(Buf_021CC768 *p)
{
    const u8 *q;
    u16 v;
    int tmp;
    tmp = p->rpos;
    q = (const u8 *)((u32)p + p->rpos);
    v = (*(const u8 *)((u32)p + (u32)tmp + 8) << 8) |
        *(const u8 *)((u32)p + p->rpos + 9);
    p->rpos += 2;
    return v;
}







void func_021CCB34(Buf_021CC768 *w, u32 v)
{
    if (w->wpos >= 0xBB6) {
        func_02034714(data_021F3A84, 0, data_021F3A84);
    }
    w->buf[w->wpos++] = v >> 16;
    w->buf[w->wpos++] = v >> 8;
    w->buf[w->wpos++] = v;
}







/* read a 24-bit big-endian value and advance the cursor */
u32 func_021CCB78(ByteStream *s)
{
    u32 pos = s->pos;
    u8 *p = (u8 *)s + pos;
    u32 v = (p[8] << 16) | (p[9] << 8) | p[10];

    s->pos = pos + 3;
    return v;
}







void func_021CCB98(Buf_021CC768 *w, u32 v)
{
    if (w->wpos >= 0xBB5) {
        func_02034714(data_021F3A84, 0, data_021F3A84);
    }
    w->buf[w->wpos++] = v >> 24;
    w->buf[w->wpos++] = v >> 16;
    w->buf[w->wpos++] = v >> 8;
    w->buf[w->wpos++] = v;
}






u32 func_021CCBE8(Buf_021CC768 *p) {u32 v;u8 *q;q=(u8*)p+p->rpos;v=((u32)q[8]<<24)|((u32)q[9]<<16)|((u32)q[10]<<8)|q[11];p->rpos+=4;return v;}







void func_021CCC0C(void *w, u32 id, int cmd, s32 *a)
{
    int i;

    func_021CCAE0(w, id);
    switch (cmd) {
    case 1:
        func_021CCAA8(w, a[0]);
        break;
    case 17:
        func_021CCAE0(w, a[0]);
        break;
    case 2:
        func_021CCAA8(w, a[0]);
        func_021CCAA8(w, a[1]);
        break;
    case 18:
        func_021CCAA8(w, a[0]);
        func_021CCAE0(w, a[1]);
        break;
    case 34:
        func_021CCAA8(w, a[0]);
        func_021CCB98(w, a[1]);
        break;
    case 50:
        func_021CCAA8(w, ((a[0] & 0xF) << 4) | (a[1] & 0xF));
        break;
    case 66:
        func_021CCAA8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        break;
    case 3:
        func_021CCAA8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        func_021CCAA8(w, a[2]);
        break;
    case 19:
        func_021CCAA8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        func_021CCAE0(w, a[2]);
        break;
    case 35:
        func_021CCAE0(w, (a[2] & 0x1F) | (((a[1] & 0x1F) << 5) | ((a[0] & 0x1F) << 10)));
        break;
    case 51:
        func_021CCB34(w, (a[2] & 0x3FFF) | (((a[1] & 0x1F) << 14) | ((a[0] & 0x1F) << 19)));
        break;
    case 67:
        func_021CCAA8(w, a[0]);
        func_021CCAA8(w, a[1]);
        func_021CCAE0(w, a[2]);
        break;
    case 83:
        func_021CCAA8(w, a[0]);
        func_021CCAA8(w, a[1]);
        func_021CCB98(w, a[2]);
        break;
    case 20:
        func_021CCAA8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        func_021CCAA8(w, ((a[2] & 0x1F) << 3) | (a[3] & 7));
        break;
    case 4:
        func_021CCAA8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        func_021CCAA8(w, a[2]);
        func_021CCAE0(w, a[3]);
        break;
    case 36:
        func_021CCB34(w, (a[2] & 0x3FFF) | (((a[1] & 0x1F) << 14) | ((a[0] & 0x1F) << 19)));
        func_021CCAA8(w, a[3]);
        break;
    case 52:
        func_021CCB34(w, (a[2] & 0x3FFF) | (((a[1] & 0x1F) << 14) | ((a[0] & 0x1F) << 19)));
        func_021CCAE0(w, a[3]);
        break;
    case 68:
        func_021CCAE0(w, (a[2] & 0x3F) | (((a[1] & 0x1F) << 6) | ((a[0] & 0x1F) << 11)));
        func_021CCAE0(w, a[3]);
        break;
    case 84:
        func_021CCAA8(w, a[0]);
        func_021CCAA8(w, a[1]);
        func_021CCAE0(w, a[2]);
        func_021CCAE0(w, a[3]);
        break;
    case 5:
        func_021CCAE0(w, (a[2] & 0x1F) | (((a[1] & 0x1F) << 5) | ((a[0] & 0x1F) << 10)));
        func_021CCAE0(w, a[3]);
        func_021CCAE0(w, a[4]);
        break;
    case 21: {
        u8 hi = ((a[0] & 0x1F) << 3) | (a[1] & 7);
        u8 lo = ((a[2] & 0x7F) << 1) | (a[3] & 1);
        func_021CCAE0(w, hi);
        func_021CCAE0(w, lo);
        func_021CCAE0(w, a[4]);
        break;
    }
    case 37:
        func_021CCAA8(w, ((a[0] & 7) << 5) | ((a[1] & 7) << 2) | ((a[2] & 1) << 1) | (a[3] & 1));
        func_021CCAE0(w, a[4]);
        break;
    case 6: {
        u16 v0 = (a[2] & 0x1F) | (((a[1] & 0x1F) << 5) | ((a[0] & 0x1F) << 10));
        u16 v1 = (a[5] & 0x1F) | (((a[4] & 0x1F) << 5) | ((a[3] & 0x1F) << 10));
        func_021CCAE0(w, v0);
        func_021CCAE0(w, v1);
        break;
    }
    case 22:
        func_021CCAA8(w, ((a[0] & 7) << 5) | ((a[1] & 3) << 3) | ((a[2] & 1) << 2) | ((a[3] & 1) << 1) | (a[4] & 1));
        func_021CCAE0(w, a[5]);
        break;
    case 38:
        func_021CCB34(w, ((a[0] & 0x1F) << 15) | ((a[1] & 0x1F) << 10) | ((a[2] & 0x1F) << 5) | (a[3] & 0x1F));
        func_021CCAE0(w, a[4]);
        func_021CCAE0(w, a[5]);
        break;
    case 7:
        for (i = 0; i < 7; i++)
            func_021CCAA8(w, a[i]);
        break;
    case 8:
        for (i = 0; i < 8; i++)
            func_021CCAA8(w, a[i]);
        break;
    }
}







void func_021CD0F0(void *r, int cmd, s32 *a)
{
    u8 b;
    u32 h;
    u32 x;
    int i;

    switch (cmd) {
    case 1:
        a[0] = func_021CCAD4(r);
        break;
    case 17:
        a[0] = func_021CCB18(r);
        break;
    case 2:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCAD4(r);
        break;
    case 18:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCB18(r);
        break;
    case 34:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCBE8(r);
        break;
    case 50:
        b = func_021CCAD4(r);
        a[0] = (b >> 4) & 0xF;
        a[1] = b & 0xF;
        break;
    case 66:
        b = func_021CCAD4(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        break;
    case 3:
        b = func_021CCAD4(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        a[2] = func_021CCAD4(r);
        break;
    case 19:
        b = func_021CCAD4(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        a[2] = func_021CCB18(r);
        break;
    case 35:
        h = func_021CCB18(r);
        a[0] = (h >> 10) & 0x1F;
        a[1] = (h >> 5) & 0x1F;
        a[2] = h & 0x1F;
        break;
    case 51:
        x = func_021CCB78(r);
        a[0] = (x >> 19) & 0x1F;
        a[1] = (x >> 14) & 0x1F;
        a[2] = x & 0x3FFF;
        break;
    case 67:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCAD4(r);
        a[2] = func_021CCB18(r);
        break;
    case 83:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCAD4(r);
        a[2] = func_021CCBE8(r);
        break;
    case 20:
        b = func_021CCAD4(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        b = func_021CCAD4(r);
        a[2] = (b >> 3) & 0x1F;
        a[3] = b & 7;
        break;
    case 4:
        b = func_021CCAD4(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        a[2] = func_021CCAD4(r);
        a[3] = func_021CCB18(r);
        break;
    case 36:
        x = func_021CCB78(r);
        a[0] = (x >> 19) & 0x1F;
        a[1] = (x >> 14) & 0x1F;
        a[2] = x & 0x3FFF;
        a[3] = func_021CCAD4(r);
        break;
    case 52:
        x = func_021CCB78(r);
        a[0] = (x >> 19) & 0x1F;
        a[1] = (x >> 14) & 0x1F;
        a[2] = x & 0x3FFF;
        a[3] = func_021CCB18(r);
        break;
    case 68:
        h = func_021CCB18(r);
        a[0] = (h >> 11) & 0x1F;
        a[1] = (h >> 6) & 0x1F;
        a[2] = h & 0x3F;
        a[3] = func_021CCB18(r);
        break;
    case 84:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCAD4(r);
        a[2] = func_021CCB18(r);
        a[3] = func_021CCB18(r);
        break;
    case 5:
        h = func_021CCB18(r);
        a[0] = (h >> 10) & 0x1F;
        a[1] = (h >> 5) & 0x1F;
        a[2] = h & 0x1F;
        a[3] = func_021CCB18(r);
        a[4] = func_021CCB18(r);
        break;
    case 21: {
        u32 hi = func_021CCB18(r);
        u32 lo = func_021CCB18(r);
        a[0] = ((u8)hi >> 3) & 0x1F;
        a[1] = (u8)hi & 7;
        a[2] = ((u8)lo >> 1) & 0x7F;
        a[3] = (u8)lo & 1;
        a[4] = func_021CCB18(r);
        break;
    }
    case 37:
        x = func_021CCAD4(r);
        a[0] = (x >> 5) & 7;
        a[1] = (x >> 2) & 7;
        a[2] = (x >> 1) & 1;
        a[3] = x & 1;
        a[4] = func_021CCB18(r);
        break;
    case 6: {
        u32 v0 = func_021CCB18(r);
        u32 v1 = func_021CCB18(r);
        a[0] = (v0 >> 10) & 0x1F;
        a[1] = (v0 >> 5) & 0x1F;
        a[2] = v0 & 0x1F;
        a[3] = (v1 >> 10) & 0x1F;
        a[4] = (v1 >> 5) & 0x1F;
        a[5] = v1 & 0x1F;
        break;
    }
    case 22:
        x = func_021CCAD4(r);
        a[0] = (x >> 5) & 7;
        a[1] = (x >> 3) & 3;
        a[2] = (x >> 2) & 1;
        a[3] = (x >> 1) & 1;
        a[4] = x & 1;
        a[5] = func_021CCB18(r);
        break;
    case 38:
        x = func_021CCB78(r);
        a[0] = (x >> 15) & 0x1F;
        a[1] = (x >> 10) & 0x1F;
        a[2] = (x >> 5) & 0x1F;
        a[3] = x & 0x1F;
        a[4] = func_021CCB18(r);
        a[5] = func_021CCB18(r);
        break;
    case 7:
        for (i = 0; i < 7; i++)
            a[i] = func_021CCAD4(r);
        break;
    case 8:
        for (i = 0; i < 8; i++)
            a[i] = func_021CCAD4(r);
        break;
    }
}






void func_021CD4B0(void *w, volatile u32 id, ...)
{
    va_list ap;
    u32 i = 0;
    u8 cmd = data_021EFF14[id];
    u32 n = cmd & 0xF;
    va_start(ap, id);
    for (; i < n; i++) {
        data_021F3B44[i] = va_arg(ap, s32);
    }
    func_021CCC0C(w, id, cmd, data_021F3B44);
}







u32 func_021CD4FC(Buf_021CC768 *w, u32 id)
{
    u8 cmd;
    u8 n;
    u8 i;
    u8 len;
    u16 pos;

    cmd = data_021EFF14[id];
    n = cmd & 0xf;
    i = 0;
    if (n != 0) {
        do {
            data_021F3B44[i] = 0;
            i++;
        } while (i < n);
    }
    pos = w->wpos;
    func_021CCC0C(w, id, cmd, data_021F3B44);
    len = w->wpos - pos;
    w->wpos = pos;
    func_021CCAE0(w, 0x5f);
    func_021CCAA8(w, len - 3);
    w->wpos = pos + len;
    return pos;
}







void func_021CD568(Buf_021CC768 *w, u32 x, u32 id, ...)
{
    va_list ap;
    u32 i = 0;
    u8 cmd = data_021EFF14[id];
    u32 n = cmd & 0xF;
    u16 pos;

    va_start(ap, id);
    for (; i < n; i++) {
        data_021F3B44[i] = va_arg(ap, s32);
    }
    pos = w->rpos;
    w->rpos = x;
    func_021CCB18(w);
    func_021CCAD4((u8 *)w);
    w->rpos = pos;
    if (id != 0x5f) {
        pos = w->wpos;
        w->wpos = x;
        func_021CCC0C(w, id, cmd, data_021F3B44);
        w->wpos = pos;
    }
}












int func_021CD5E0(Buf_021CC768 *r, s32 *a)
{
    int c;
    u8 k;

    c = func_021CCB18(r);
    while (c == 0x5f) {
        r->rpos += func_021CCAD4((u8 *)r);
        if (r->rpos >= r->wpos) {
            return 0x5e;
        }
        c = func_021CCB18(r);
    }
    k = data_021EFF14[c];
    if (k != 0 && k != 0x10) {
        func_021CD0F0(r, k, a);
    } else {
        func_021CD6AC(r, c, a);
    }
    return c;
}












/*
 * tail-call thunk to func_021CCAA8
 */
void func_021CD63C(void *p, u8 v)
{
    func_021CCAA8(p, v);
}












/*
 * tail-call thunk to func_021CCAD4
 */
u8 func_021CD644(u8 *p)
{
    return func_021CCAD4(p);
}












void func_021CD64C(void *w, u8 id, ...)
{
    va_list ap;
    u16 v;
    s32 x;

    va_start(ap, id);
    v = va_arg(ap, s32);
    func_021CCAE0(w, id);
    func_021CCAE0(w, v);
    if (id == 0x5C) {
        func_021CCAE0(w, va_arg(ap, s32));
    }
    do {
        x = va_arg(ap, s32);
        func_021CCB98(w, x);
    } while (x != (s32)0xFFFF0000);
}












void func_021CD6AC(void *r, u8 cmd, s32 *out)
{
    int i;

    i = 1;
    out[0] = func_021CCB18(r);
    if (cmd == 0x5c) {
        out[1] = func_021CCB18(r);
        i++;
    }
    for (; i < 16; i++) {
        out[i] = func_021CCBE8(r);
        if (out[i] == 0xFFFF0000) {
            break;
        }
    }
}












/*
 * empty function: bx lr
 */
void func_021CD6EC(void)
{
}











u8 *func_021CD6F0(u8 *a, u8 *b, int c, int d, u16 idx, u16 kind, u8 e, int f, int g, struct Copy24 *h, u16 heap)
{
    u8 *p;
    u32 i;
    int flag, k;
    p = func_02030734(heap, 0x1b8, 1, (const char *)d_021F3A88, 0x209);
    flag = 1;
    if (c == 0 || e != 0)
        flag = 0;
    p[0x1a6] = idx;
    *(u16 *)(p + 0x19a) = heap;
    p[0x1a7] = e;
    *(void **)(p + 0x50) = func_021EEA58(d, (u8)idx, flag, heap);
    *(char **)(p + 0x118) = func_021B9AF8((char *)b, idx);
    *(u8 **)p = a;
    *(u8 **)(p + 4) = b;
    p[0x11c] = kind;
    p[0x11d] = 0;
    p[0x121] = idx;
    p[0xc4] = 0;
    *(int *)(p + 0x54) = 0;
    *(u16 *)(p + 0x19c) = 0;
    *(void **)(p + 0x134) = func_02030734(heap, 0xbc0, 1, (const char *)d_021F3A88, 0x21a);
    *(void **)(p + 0x28) = (void *)func_021CDA18;
    p[0x1a8] = 0;
    *(int *)(p + 0xa0) = 0;
    ((Flags_021CC768 *)(p + 0x1b2))->f3 = 0;
    p[0x1ae] = 0;
    p[0x1a9] = 0;
    p[0x1ab] = 0;
    *(u16 *)(p + 0xe4) = 0;
    *(u16 *)(p + 0xe6) = 0;
    p[0x1ad] = 0;
    ((Flags_021CC768 *)(p + 0x1b2))->f0 = 0;
    ((Flags_021CC768 *)(p + 0x1b2))->f1 = 0;
    ((Flags_021CC768 *)(p + 0x1b2))->f4 = 0;
    ((Flags_021CC768 *)(p + 0x1b2))->f5 = 0;
    *(u32 *)(p + 0x34) = func_021BA08C((struct Q2 *)a);
    p[0x1aa] = f;
    func_021D8230(p + 0x2c);
    func_021D3F04(p + 0x18);
    func_021D3D9C(p);
    *(struct Copy24 *)(p + 0xf4) = *h;
    if (p[0x1a7] == 1 && g == 0) {
        k = func_021B9FBC(*(char **)p, p[0x1a6]);
        *(void **)(p + 0xf0) = func_02187F00(*(void ***)p, func_021BA820(*(int **)p), *(u32 *)(p + 4), k, *(u16 *)(p + 0x19a));
    } else {
        *(int *)(p + 0xf0) = 0;
    }
    for (i = 0; i < 4; i++)
        p[0x112 + i] = 0;
    if (p[0x1a7] == 0 && func_021B90F8(*(u8 **)p))
        *(void **)(p + 0x10) = func_021EE5E4(heap);
    else
        *(void **)(p + 0x10) = 0;
    return p;
}










void func_021CD8E0(u8 *p) {
 if(*(void* *)&((struct Obj05197 *)p)->f10)func_021EE600(*(void* *)&((struct Obj05197 *)p)->f10);
 if(*(void* *)&((struct Obj05197 *)p)->fF0)func_02188080(*(void* *)&((struct Obj05197 *)p)->fF0);
 func_020307B0(*(void* *)&((struct Obj05197 *)p)->f134);
 func_021EEAE0(*(void* *)&((struct Obj05197 *)p)->f50);
 func_020307B0(p);
}










void func_021CD914(u8 *p) {p[0x1b2]|=2;}










u16 *func_021CD924(u8 *p, u32 *out) { if (*(u16 * *)&((struct Obj13352 *)p)->f10) return func_021EE63C(*(u16 * *)&((struct Obj13352 *)p)->f10,out); return 0; }










/*
 * Prototype: 021D3F48 stores only r1 low16; caller forwards full getter
 * result without truncation, so its extern argument is widened to u32.
 */
void func_021CD938(u8 *p,void *a) { p[0x1a7]=2; ((struct Obj13353 *)p)->f14=a; func_021D3F48(p+0x18,func_021EE830(a)); }










/*
 * Stores the second argument (a u32) into the field at #0x54.
 */
void func_021CD95C(struct QA *p, u32 v) { p->v = v; }











void func_021CD960(u8 *p, u32 v) {
    *(u32 *)(p + 0xA0) = v;
    p[0x1B2] |= 8;
}










/*
 * Reads the u32 field at #0x50 of the argument and returns it.
 */
u32 func_021CD978(struct QB *p) { return p->v; }










/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: push {r3, lr}; ldr r1, [r0, #0x28]; blx r1; pop {r3, pc}.
 */
void func_021CD97C(struct R2 *p) { p->fn(p); }










/*
 * Prototype: 021CDA0C stores its r1 payload unchanged at +0x28; caller
 * passes a callback address. Pointer replaces legacy u32 for that payload.
 */
void func_021CD984(u8 *p,u16 n) { func_021EE674(((struct Obj07767 *)p)->f14); func_021EEBDC(((struct Obj07767 *)p)->f50); func_021D3F64(p+0x18,n); func_021CDA0C((struct QE *)p,(u32)func_021CDC0C); }










void func_021CD9B0(u8 *p) { func_021D3F88((struct S *)(p+0x18)); func_021CDA0C((struct QE *)p,(u32)func_021CDA18); }











/* 021CD9C8  byte field 0x1a7 == 2 */
/*
 * 8 instructions, 16 bytes: ldr r1, pool_021CD9D8; ldrb r0, [r0, r1]; cmp r0, #2; bne loc_021CD9D4; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
u32 func_021CD9C8(u8 *p)
{
    return (((struct Obj18365 *)p)->f1A7 == 2);
}










/*
 * Reads the u16 field at #0x22 of the argument and returns it.
 */
u16 func_021CD9DC(struct QD *p) { return p->v; }











/* 021CD9E0  function-pointer slot 0x28 compared with 0x021CDC0D */
/*
 * 8 instructions, 16 bytes: ldr r1, [r0, #0x28]; ldr r0, pool_021CD9F0; cmp r1, r0; bne loc_021CD9EC; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
u32 func_021CD9E0(u8 *p)
{
    return (((struct Obj18367 *)p)->f28 == 0x021CDC0D);
}










/*
 * u8 step preserves the low-byte result for every incoming word; no
 * signed int addition overflow. Wide step emits an extra narrowing pair.
 */
void func_021CD9F4(u8 *p,u8 n) { p[0x1ab]+=n; if(p[0x1ab]>14) p[0x1ab]=14; }









void func_021CDA0C(struct QE *p, u32 v)
{
    p->v = v;
    p->z = 0;
}









int func_021CDA18(u8 *p)
{
    u32 id, *pair, x, y;
    int flag, n;
    func_021D3FDC(p,(struct Qd *)(p+0x18));
    switch (p[0x1a8]) {
    case 0:
        id = func_021EEBE8(((struct Obj00463 *)p)->f50);
        if (p[0x1a7] == 2 && (((Flags_021CDA18 *)(p+0x1b2))->f4 || ((Flags_021CDA18 *)(p+0x1b2))->f5) && !id) return 0;
        func_021CDD34(p);
        if (id == 9) {
            func_021EEC20(*(int *)&((struct Obj00463 *)p)->f50,&pair);
            x = pair[0]; y = pair[1];
            ((struct Obj00463 *)p)->f30 = y;
            ((struct Obj00463 *)p)->f2C = x;
            ((struct Obj00463 *)p)->fCC = 0;
            p[0x1a8] = 3;
        } else if (id) {
            *(Callback *)&((struct Obj00463 *)p)->fC8 = func_021CDD50(p,id,&flag);
            if (flag) {
                if (!func_021D3FAC(p+0x18)) { p[0x1a8] = 6; break; }
            } else func_021D3FC4(p+0x18);
            if (*(Callback *)&((struct Obj00463 *)p)->fC8) {
                p[0x1a8] = 1;
                ((struct Obj00463 *)p)->fCC = 0;
            } else {
                ((struct Obj00463 *)p)->fCC = 0;
                p[0x1a8] = 2;
            }
        } else if (((Flags_021CDA18 *)(p+0x1b2))->f1) return 1;
        break;
    case 1:
        if ((*(Callback *)(p+0xc8))(p,(int *)(p+0xcc))) {
            if (((Flags_021CDA18 *)(p+0x1b2))->f1) return 1;
            if (func_021D3F4C(p+0x18)) p[0x1a8] = 4;
            else p[0x1a8] = 2;
        }
        break;
    case 2:
        if (func_021EEC4C(((struct Obj00463 *)p)->f50,((struct Obj00463 *)p)->fD8,((struct Obj00463 *)p)->fDC)) p[0x1a8] = 0;
        if (((Flags_021CDA18 *)(p+0x1b2))->f1) return 1;
        break;
    case 3:
        if (func_021EEC4C(((struct Obj00463 *)p)->f50,((struct Obj00463 *)p)->fD8,((struct Obj00463 *)p)->fDC)) p[0x1a8] = 7;
        if (((Flags_021CDA18 *)(p+0x1b2))->f1) return 1;
        break;
    case 6:
        if (func_021D3F4C(p+0x18)) p[0x1a8] = 4;
        break;
    case 4:
        if (func_021D3F60(p+0x18) == 1) p[0x1a8] = 7;
        else {
            if (((struct Obj00463 *)p)->f54) { func_02005CA4(1,62); func_02006740(); }
            p[0x1a8] = 5;
        }
        break;
    case 5:
        if (!func_02005E50()) {
            n = func_021D3FA8(p+0x18);
            func_02005CA4(0,1);
            func_021BA73C(*(char * *)&((struct Obj00463 *)p)->f0,n);
            func_02006734(0);
        }
        break;
    case 7:
        return 1;
    }
    return 0;
}









/*
 * extent: The store-and-return follower at 0x021CDD34 is included here;
 * the larger lookup follower at 0x021CDD50 has its own verified shard.
 */
int func_021CDC0C(u8 *p)
{
    u32 id;
    u16 n;
    int zero;
    func_021D3FDC(p,(struct Qd *)(p+0x18));
    switch (p[0x1a8]) {
    case 0:
        p[0x1a8] = 1;
    case 1:
        if (!func_021D3F98(p+0x18)) {
            id = func_021EEBE8(((struct Obj00818 *)p)->f50);
            if (id) {
                zero = 0;
                *(Callback *)&((struct Obj00818 *)p)->fC8 = func_021CDD50(p,id,0);
                if (*(Callback *)&((struct Obj00818 *)p)->fC8) {
                    p[0x1a8] = 2;
                    ((struct Obj00818 *)p)->fCC = zero;
                }
                else {
                    func_021CDD34(p);
                    p[0x1a8] = 3;
                    ((struct Obj00818 *)p)->fCC = zero;
                }
            }
        } else {
            if (((struct Obj00818 *)p)->f54) {
                func_02005CA4(1,1);
                func_021EAE24(((struct Obj00818 *)p)->f54);
                func_02005DF8(30);
                func_021F88BC(0);
                func_02006740();
            }
            p[0x1a8] = 4;
        }
        break;
    case 2:
        if ((*(Callback *)(p+0xc8))(p,(int *)(p+0xcc))) {
            p[0x1a8] = 3;
            ((struct Obj00818 *)p)->fCC = 0;
            if (func_021F8678()) func_021F88BC(1);
        }
        break;
    case 3:
        if (func_021EEC4C(((struct Obj00818 *)p)->f50,((struct Obj00818 *)p)->fD8,((struct Obj00818 *)p)->fDC)) p[0x1a8] = 1;
        break;
    case 4:
        if (((struct Obj00818 *)p)->f54) {
            if (func_021EAE34(((struct Obj00818 *)p)->f54)) {
                if (!func_02005E50()) {
                    n = (int)func_021D3FA8(p+0x18);
                    func_021EAE74(((struct Obj00818 *)p)->f54,n,n);
                    func_021BA7F8(((struct Obj00818 *)p)->f0);
                }
            }
        }
        break;
    case 5: return 1;
    }
    return 0;
}









void func_021CDD34(u8 *p)
{
    ((struct Obj09986 *)p)->fE0 = 0;
    *(u8 * *)&((struct Obj09986 *)p)->fD8 = p+0xe0;
    ((struct Obj09986 *)p)->fDC = 4;
}









Callback func_021CDD50(u8 *p,u32 id,int *out)
{
    u32 i;
    for (i=0; i<15; i++) {
        if (d_021EFFEC[i].id == id) {
            if (out) *out = d_021EFFEC[i].flag;
            return d_021EFFEC[i].callbacks[p[0x1a7]];
        }
    }
    return 0;
}










void func_021CDD94(char *p, int *o)
{
    *(S *)o = *(S *)(p + 0x2c);
}









/*
 * unresolved THM_CALL at +0x14. Region hint ov094 does not supply a witness.
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Callee 0x021F8524 is an ov094 Thumb wrapper (pool-based tail), other overlay, not filed here (ov094 owner Ilias). Integrator: seed label.
 */
int func_021CDDA0(u8 *p) { if(p[0x1a7]!=2) { if(*(u16 *)(p+0xe6)) return func_021F8524(0); return 0; } return ((struct Flags_021CDDA0 *)p)->flag; }









u32 func_021CDDCC(struct Flags_021CDDCC *p) { return p->flag; }









/*
 * Levers (from the DIFF note): case 0 is the call written in each arm, `!= 4` arm first
 * (a-boolean-argument-is-a-call-in-each-arm.md; a flag value hoists `movs r1,#1`);
 * func_021F84E8 takes two arguments as its own file says, the second being the 0xe4
 * halfword still live in r1 from the || test; func_021D3FA8 is declared u32 here because
 * the original narrows its result before the u16 parameter of func_021EAEA8.
 */
int func_021CDDDC(u8 *p, int *st)
{
    switch (*st) {
    case 0:
        if ((int)func_021B86B8(*(void *** *)&((struct Obj01689 *)p)->f0) != 4) {
            func_021E90A0(((struct Obj01689 *)p)->f54, 0);
        } else {
            func_021E90A0(((struct Obj01689 *)p)->f54, 1);
        }
        *st = *st + 1;
        break;
    case 1:
        if (func_021E90D0(((struct Obj01689 *)p)->f54) == 0) {
            break;
        }
        ((struct Obj01689 *)p)->fE4 = func_021BA5C4(((struct Obj01689 *)p)->f0);
        ((struct Obj01689 *)p)->fE6 = func_021BA5D0(((struct Obj01689 *)p)->f0);
        if (((struct Obj01689 *)p)->fE4 != 0 || ((struct Obj01689 *)p)->fE6 != 0) {
            func_021F84E8(((struct Obj01689 *)p)->fE6, ((struct Obj01689 *)p)->fE4);
            if (((struct Obj01689 *)p)->fE6 != 0) {
                func_021F8504(0, 1, 1);
            }
        }
        func_021CDECC(p);
        if (func_021CD9E0(p) != 0) {
            func_021EAEA8(((struct Obj01689 *)p)->f54, (u16)((u32)func_021D3FA8(p + 0x18)));
        }
        return 1;
    }
    return 0;
}









int func_021CDE8C(int a, int b)
{
    int r4;
    if (((struct Obj06232 *)a)->f54 != 0) {
        r4 = func_021CDDDC((u8 *)a, (int *)b);
        if (r4 != 0) {
            if (func_021EE688(((struct Obj06232 *)a)->f14, ((struct Obj06232 *)a)->f1A6) != 0)
                func_021D3F54((u8 *)(a + 0x18));
        }
        return r4;
    }
    func_021EE688(((struct Obj06232 *)a)->f14, ((struct Obj06232 *)a)->f1A6);
    return 1;
}








void func_021CDECC(u8 *p) { void *a; a=func_021CDF1C(p); if(a) ((struct Obj04362 *)p)->f19C=func_021D59B4(a,13); }








u32 func_021CDEE8(u8 *p) { void *a; u32 now,old; a=func_021CDF1C(p); if(a) { now=func_021D59B4(a,13); old=((struct Obj04362 *)p)->f19C; if(now>=old) return 0; return _u32_div_f((old-now)*100,now); } return 0; }







/*
 * Prototype: original narrows getter result to u8 before 021B9920;
 * caller extern has u8 second argument; named u8 local keeps shift in r0.
 */
void *func_021CDF1C(u8 *p) { u8 side; if(func_021B8588(*(void ** *)&((struct Obj04362 *)p)->f0)==0 && func_021B86C0(*(u8 ** *)&((struct Obj04362 *)p)->f0)==0) { side=func_021B9064(*(u8 * *)&((struct Obj04362 *)p)->f0,p[0x1a6],0); return func_021B9920(*(char * *)&((struct Obj04362 *)p)->f4,side,0); } return 0; }








int func_021CDF58(u8 *p, int *st)
{
    u8 buf;

    switch (*st) {
    case 0:
        func_021EAA00(((struct Obj01892 *)p)->f54, p[0xc4]);
        func_021CE068(p);
        *st = *st + 1;
        break;
    case 1:
        if (func_021CE08C(p) != 0) {
            func_021EAA5C(((struct Obj01892 *)p)->f54);
            *st = 2;
        } else if (func_021EAA34(((struct Obj01892 *)p)->f54, &buf) != 0) {
            p[0xc4] = buf;
            *st = 3;
        }
        break;
    case 2:
        p[0xc4] = func_021CDFE4(p[0xc4]);
        *st = *st + 1;
        break;
    case 3:
        func_021CE0E0(p);
        *st = *st + 1;
        break;
    case 4:
        *(u8 * *)&((struct Obj01892 *)p)->fD8 = p + 0xc4;
        ((struct Obj01892 *)p)->fDC = 1;
        return 1;
    }
    return 0;
}






/*
 * Lever: each switch arm writes its own `mode = (u8)t;` before `break`. The copies are
 * cross-jumped into `b join` after branch threading, so each arm's `blo` keeps landing on
 * its own hop (a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy.md).
 * One shared `mode = (u8)t;` after the switch threads the hops away (4 bytes short).
 */
u32 func_021CDFE4(u32 mode)
{
    u32 v;
    int t;

    v = (u32)(((u64)func_0203F0A8() * 100) >> 32);
    if (mode == 0) {
        if (v < 0x1e) {
            mode = 3;
        } else if (v < 0x3c) {
            mode = 2;
        } else {
            mode = 1;
        }
    } else {
        switch (mode) {
        case 1:
        default:
            t = (v < 0x32) ? 2 : 3;
            mode = (u8)t;
            break;
        case 3:
            t = (v < 0x28) ? 2 : 1;
            mode = (u8)t;
            break;
        case 2:
            t = (v < 0x28) ? 3 : 1;
            mode = (u8)t;
            break;
        }
    }
    return mode;
}





int func_021CE040(void)
{
    return 1;
}





void func_021CE044(u8 *p) { p[0xc4]=func_021CDFE4(p[0xc4]); *(u8 * *)&((struct Obj07768 *)p)->fD8=p+0xc4; ((struct Obj07768 *)p)->fDC=1; }






void func_021CE068(u8 *p) { if(((struct Obj01892 *)p)->fE4) { func_021F8504(1,1,1); p[0x1ad]=0; } }






/*
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Same blocker as 021CDDA0: ov094 0x021F8524 needs a label/witness.
 */
int func_021CE08C(u8 *p) { if(*(u16 *)(p+0xe4)!=0) { if(p[0x1ad]==0) { if(func_021F8524(1)) p[0x1ad]=1; } return p[0x1ad]; } return 0; }






int func_021CE0BC(u8 *p,void *q) { if(func_021CE08C(p)) { if(q) func_021CE150(p,q); return 1; } return 0; }






void func_021CE0E0(u8 *p) { if(((struct Obj21134 *)p)->fE4!=0) func_021F8504(1,0,0); }







void func_021CE0F8(u8 *p, u8 *q, u8 *o)
{
    if (func_021B8588(*(void ** *)&((struct Obj13355 *)p)->f0) != 3) {
        func_021EAF18((struct L *)o, 1, 0x45);
        func_021EAF50((struct L *)o, func_021D5440(q));
        func_021EAF78(o, 0);
    } else {
        func_021EAF18((struct L *)o, 1, 0x46);
        func_021EAF50((struct L *)o, p[0x1a6]);
        func_021EAF78(o, 0);
    }
}






void func_021CE150(u8 *p, void *q) { ((struct Obj01892 *)p)->fD0=q; ((struct Obj01892 *)p)->fD4=0; }







/* 021CE160  the receiver pointer is also the FIRST argument: the image keeps
 * r0 = p, puts p+0xd4 in r1 and the slot from [p+0xd0] in r2. */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: push {r3, lr}; adds r2, r0, #0; adds r2, #0xd0; adds r1, r0, #0; ldr r2, [r2]; adds r1, #0xd4; blx r2; pop {r3, pc}.
 */
u32 func_021CE160(u8 *p)
{
    return ((u32 (*)(u8 *, u8 *)) * (u32 *)(p + 0xd0))(p, p + 0xd4);
}






u32 func_021CE170(u8 *p, s32 *st)
{
    switch (*st) {
    case 0:
        func_021CE150(p, (void *)((u32)func_021CE308));
        func_021CE068(p);
        *st = *st + 1;
        break;
    case 1:
        func_021CE08C(p);
        if (func_021CE160(p) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}





int func_021CE1B0(u8 *p,int *state)
{
    u8 count;
    u8 flag;
    u32 *data;
    switch (*state) {
    case 0:
        if (((Flags_021CE1B0 *)(p+0x1b2))->flag) {
            func_021CE2E8(p);
            return 1;
        }
        data = func_021EE6B8(((struct Obj01893 *)p)->f14,p[0x1a6],&count,&flag);
        if (flag) func_021D3F54(p+0x18);
        *(u32 * *)&((struct Obj01893 *)p)->fD8 = data;
        ((struct Obj01893 *)p)->fDC = count * 4;
        if (((Command *)data)->kind == 8) {
            func_021D3FD0(p+0x18);
            if (((struct Obj01893 *)p)->f54) {
                func_021EAF18((struct L *)(p+0x58),1,0xb7);
                func_021EA614(((struct Obj01893 *)p)->f54,(struct H *)(p+0x58));
                (*state)++;
            } else {
                func_021CE2E8(p);
                p[0x1b2] |= 0x10;
                return 1;
            }
        } else if (((Command *)data)->kind == 9) {
            p[0x1b2] |= 0x20;
            func_021D3FD0(p+0x18);
            if (((struct Obj01893 *)p)->f54) {
                func_021EAF18((struct L *)(p+0x58),1,0xb8);
                func_021EA614(((struct Obj01893 *)p)->f54,(struct H *)(p+0x58));
                *state += 2;
            } else {
                func_021CE2E8(p);
                return 1;
            }
        } else return 1;
        break;
    case 1:
        if (func_021EA710(((struct Obj01893 *)p)->f54)) {
            func_021CE2E8(p);
            p[0x1b2] |= 0x10;
            return 1;
        }
        break;
    case 2:
        if (func_021EA710(((struct Obj01893 *)p)->f54)) {
            func_021CE2E8(p);
            return 1;
        }
        break;
    }
    return 0;
}





void func_021CE2E8(u8 *p) { *(u8 * *)&((struct Obj07769 *)p)->fC=p+0x124; func_021D8434((u32 *)(p+0x124)); *(u8 * *)&((struct Obj07769 *)p)->fD8=*(u8 * *)&((struct Obj07769 *)p)->fC; ((struct Obj07769 *)p)->fDC=4; }






u32 func_021CE308(u8 *p)
{
    u32 i = 0;
    u32 w;
    p[0x11d] = 0;
    ((s8 *)p)[0x11e] = -1;
    p[0x11f] = 0;
    ((Flags_021CE308 *)(p + 0x1b2))->f = 0;
    func_021D0B10(p, 0, p[0x11c], p + 0x184, p + 0x190);
    func_021CF41C(p);
    func_021CF360(p);
    for (i = 0; i < 3; i++) {
        func_021D8434((u32 *)(p + 0x124 + i * 4));
    }
    for (i = 0; i < p[0x11c]; i++) {
        w = (u32)func_021B990C((char *)(((struct Obj03688 *)p)->f4), p[0x1a6], (u8)i);
        if (func_021CF470(p, (void *)w, 0) == 0) {
            p[0x11f] = i;
            break;
        }
    }
    func_021CE150(p, (void *)((u32)func_021CE4D0));
    return 0;
}





void func_021CE3B4(u8 *p, void *q) { func_021EA614(((struct Obj13356 *)p)->f54,q); p[0x120]=1; }





int func_021CE3C8(u8 *p,int *state)
{
    u8 out[4];
    u32 i;
    u32 id;
    switch (*state) {
    case 0:
        func_021EAE44(((struct Obj00662 *)p)->f54);
        (*state)++;
        break;
    case 1:
        if (func_021EAE54(((struct Obj00662 *)p)->f54)) {
            for (; p[0x11d] < p[0x11c]; p[0x11d]++) {
                ((struct Obj00662 *)p)->f8 = func_021B990C(((struct Obj00662 *)p)->f4,p[0x1a6],p[0x11d]);
                *(u8 * *)&((struct Obj00662 *)p)->fC = p+0x124+p[0x11d]*4;
                func_021D8434((u32 *)(*(u8 * *)&((struct Obj00662 *)p)->fC));
                if (!func_021CF470(p,((struct Obj00662 *)p)->f8,*(u8 * *)&((struct Obj00662 *)p)->fC)) {
                    i = func_021CF81C(p,((struct Obj00662 *)p)->f8,out);
                    if (i < 4) {
                        id = func_021D54C0(((struct Obj00662 *)p)->f8,i);
                        func_021D82D0((struct Unk021D82D0 *)(*(u8 * *)&((struct Obj00662 *)p)->fC),id,func_021D81F8(((struct Obj00662 *)p)->f0,((struct Obj00662 *)p)->f4,((struct Obj00662 *)p)->f8,id,p+0x38));
                    } else func_021CF58C((struct Unk021D82D0 *)(*(u8 * *)&((struct Obj00662 *)p)->fC),p,((struct Obj00662 *)p)->f8);
                }
            }
            (*state)++;
        }
        break;
    case 2:
        *(u8 * *)&((struct Obj00662 *)p)->fD8 = p+0x124;
        ((struct Obj00662 *)p)->fDC = p[0x11c]*4;
        func_021CE150(p,(void *)((u32)func_021CF2F0));
        break;
    }
    return 0;
}



/*
 * note 2026-10-05 (wave P26 lane 2): byte-identical to the original except that two call
 * relocations have no witness in the current index: func_021E979C and func_021E9954. Both
 * leaves are now filed (src/matched/ov/ov093_func_021E979C.c, ov093_func_021E9954.c, EXACT);
 * the verdict becomes EXACT once the integrator regenerates the index. The original extent is
 * 772 B: 756 B of C plus the 16 B linker veneer at 021CE7C4 (not C, resolved as a veneer witness).
 * Two changes closed the 253 B residue of the older draft: (1) no shared increment label and
 * no goto: each arm writes ++*st; break; so the compiler builds the single shared state store
 * and one epilogue (756 to 748 B, branch layout); (2) the countdown loop reads the index byte
 * through a struct field (struct L at 0x11D and 0x1A6) instead of a count pointer local, so
 * mwcc hoists three separate address computations (count pointer in r5, a copy in r6, a
 * stack copy for the loop test) as in the original.
 * Not tried again from the older note: unsigned-long state pointer, full-word countdown.
 * proof: full unsigned state dispatch <=8; byte selectors0..255; countdown assigned before reads; byte/state additions wrap at their original widths; fixed veneer is omitted from C.
 */
int func_021CE4D0(u8 *p, u32 *st)
{
    u32 result;
    switch (*st) {
    case 0:
        P(8) = func_021B990C(P(4), p[0x1A6], p[0x11D]);
        P(12) = p + 0x124 + p[0x11D] * 4;
        p[0x1AF] = 0;
        func_021D8434(P(12));
        if (func_021CF470(p, P(8), P(12))) {
            func_021CE150(p, (void *)((u32)func_021CF220));
            break;
        }
        if (func_021CE8F0(p, (unsigned short *)(p + 0x19E)) == 1) {
            func_021CE150(p, (void *)((u32)func_021CE7D4));
            break;
        }
        ++*st; break;
    case 1:
        if (*(signed char *)(p + 0x11E) != p[0x11D] || p[0x120]) {
            func_021CE0F8(p, P(8), p + 0x58);
            func_021EA65C(P(0x54), (struct H *)(p + 0x58));
            p[0x120] = 0;
            p[0x11E] = p[0x11D];
            ++*st; break;
        }
        *st += 2U;
        break;
    case 2:
        if (!func_021EA710(P(0x54))) return 0;
        ++*st;
        /* falls through */
    case 3:
        func_021E9760(P(0x54), P(8), p[0x11D] > p[0x11F], (int)P(12));
        ++*st; break;
    case 4:
        if (func_021CE0BC(p, (void *)((u32)func_021CE3C8))) {
            func_021E979C(P(0x54));
            return 0;
        }
        result = func_021E97A4(P(0x54));
        switch (result) {
        case 3:
            if (func_021D62C4(P(8), 0x21)) {
                func_021E9964(W(0x54));
                *st = 6;
            } else {
                func_021CF430(p, p[0x11D], 0);
                func_021CE150(p, (void *)((u32)func_021CEDC0));
            }
            break;
        case 1:
            func_021CF430(p, p[0x11D], 0);
            func_021CE150(p, (void *)((u32)func_021CEA94));
            break;
        case 2:
            if (func_021D62C4(P(8), 0x21)) *st = 6;
            else if (p[0x1AA] == 1 && !func_021BA1EC(P(0))) {
                func_021E9964(W(0x54));
                *st = 5;
            } else func_021CE150(p, (void *)((u32)func_021CEEB8));
            break;
        case 4:
            if (p[0x11D] == p[0x11F]) {
                if (func_021D62C4(P(8), 0x21) && func_021B86E4(P(0)) != 2) *st = 6;
                else {
                    func_021CF430(p, p[0x11D], 0);
                    func_021CE150(p, (void *)((u32)func_021CF078));
                }
                break;
            }
            if (p[0x11D] == 0) break;
            do {
                --Q->idx;
                if (!func_021CF470(p, func_021B990C(P(4), Q->sel, Q->idx), 0)) {
                    p[0x1AB] += func_021CF43C(p, p[0x11D]);
                    if (func_021D8454((u32 *)(p + 0x124 + p[0x11D] * 4)) == 3)
                        func_021CE7C4(p + 0x190);
                    if (func_021D8454((u32 *)(p + 0x124 + p[0x11D] * 4)) == 2)
                        func_021CF3B8(p, p[0x11D]);
                    func_021CE150(p, (void *)((u32)func_021CE4D0));
                    return 0;
                }
            } while (Q->idx != 0);
            break;
        }
        break;
    case 5:
        if (func_021E9974(W(0x54))) *st = 3;
        break;
    case 6:
        func_021E9954(P(0x54));
        ++*st; break;
    case 7:
        if (!func_021E9974(W(0x54))) break;
        func_021EAF18((struct L *)(p + 0x58), 1, 0xC5);
        func_021EAF50((struct L *)(p + 0x58), func_021D5440(P(8)));
        func_021CE3B4(p, p + 0x58);
        ++*st; break;
    case 8:
        if (func_021EA710(P(0x54))) *st = 1;
        break;
    }
    return 0;
}






u32 func_021CE7D4(u8 *p, int *st)
{
    u32 i;
    u16 k;
    u32 z;
    switch (*st) {
    case 0:
        z = 0;
        i = func_021B904C(((struct Obj02785 *)p)->f0, 0);
        k = func_021BA004(((struct Obj02785 *)p)->f0, i);
        func_021F7F58(func_021BA020(((struct Obj02785 *)p)->f0, i), 9, 0, 0, z);
        func_021F7998(0x270);
        func_021EA6B0(*(char * *)&((struct Obj02785 *)p)->f54, k, ((struct Obj02785 *)p)->f19E);
        if ((u16)(((struct Obj02785 *)p)->f19E + 0xffed) <= 1 &&
            func_021D7F38(func_021BA020(((struct Obj02785 *)p)->f0, i)) && !((Flags_021CE7D4 *)(p + 0x1b2))->flag) {
            func_021F87EC(0x47b);
            if (!func_021F8774()) {
                func_02005E30(8);
                *st = 1;
                break;
            }
        }
        *st = 2;
        break;
    case 1:
        if (!func_02005E50()) {
            func_02005D90(0x47b, 0xffff);
            p[0x1b2] = (p[0x1b2] & ~1) | 1;
            ++*st;
        }
        break;
    case 2:
        if (!func_021F7EB4() && func_021EA710(((struct Obj02785 *)p)->f54)) {
            func_021F7998(0x271);
            ++*st;
        }
        break;
    case 3:
        if (!func_021F7EB4()) func_021CE150(p, (void *)((u32)func_021CE4D0));
        break;
    }
    return 0;
}





static inline void init_offset(Off *value)
{
    *value = OFFSET;
    *value -= 0x88;
}





/*
 * lever: Six ordinary int offsets each receive 0x19a then 0x112;
 * a cached row pointer preserves their distinct stack homes and r5 base.
 * Reverse declarations and a full-word k local restore the spill order.
 * note 2026-10-05 (wave D9r lane 131): removed the 6 dead first assignments
 * (`invalid=0x19a;` before `invalid=0x112;`; `ok3=0x19a;` before
 * `ok3=0x112;` and 4 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
u32 func_021CE8F0(const u8 *p, u16 *out)
{
    u32 entry;
    int result;
    u32 count;
    u32 k;
    u32 key;
    u32 id, i;
    int a, b;
    u8 *mon;
    u8 *row;
    int skip,ok0,ok1,ok2,ok3,invalid;
    if ((u32)func_021B86B8(*(void *** *)&((struct Obj03689 *)p)->f0) != 1) goto fail;
    id = func_021B904C(((struct Obj03689 *)p)->f0,0);
    k = func_021BA004(((struct Obj03689 *)p)->f0,id);
    if (!k) goto fail;
    entry = (u32)func_021B9AEC(*(char * *)&((struct Obj03689 *)p)->f4,id);
    mon = func_021B990C(((struct Obj03689 *)p)->f4,id,(u8)0);
    if (func_021D5B68(mon)) {
        count = func_021B99B8(((struct Obj03689 *)p)->f0,id);
        for (i=1;i<count;i++) {
            mon = func_021B990C(((struct Obj03689 *)p)->f4,id,(u8)i);
            if (!func_021D5B68(mon)) break;
        }
    }
    result = -1;
    invalid=0x112;
    ok3=0x112;
    ok2=0x112;
    ok1=0x112;
    ok0=0x112;
    skip=0x112;
    for (i=0;i<4;i++) {
        row = (u8 *)p + i;
        if (!row[skip]) {
            key = d_021EFF78[i];
            if (func_0202A298(k,key,((struct Obj03689 *)p)->f19A)) {
                switch (key - 0x11) {
                case 1:
                    a = func_021D59B4(mon,13);
                    if ((u32)a <= func_021D7B60(mon,2)) { result = i; row[ok0] = 1; }
                    break;
                case 0:
                    if (!func_021D5B48(mon)) { result = i; row[ok1] = 1; }
                    break;
                case 2:
                    if (func_021B9B94((void *)entry) > 1 && func_021B9B98((u8 *)entry) == 1) { result = i; row[ok2] = 1; }
                    break;
                case 3:
                    if (func_021B9B94((void *)entry) > 1 && func_021B9B98((u8 *)entry) == 1) {
                        b = func_021D59B4(mon,13);
                        if ((u32)b <= func_021D7B60(mon,2)) { result = i; row[ok3] = 1; }
                    }
                    break;
                }
            } else row[invalid] = 1;
        }
    }
    if (result >= 0) { *out = d_021EFF78[result]; return 1; }
fail:
    return 0;
}





/*
 * witnesses: four ov093 blocker leaves 021E98AC, 021E98B4,
 * 021D7EF0, 021E9920 filed and individually shard-verified first.
 * lever: packed unsigned bitfields plus narrow caller extern CF5B0 move;
 * record declared before sub settles r6/r7 allocation (one variant).
 * interface: CF5B0 own source takes u32 move, but original narrows id at
 * 021CEBC6/021CEBCC; u16 extern preserves observed caller truncation.
 * CE3B4 ignores r1 but caller explicitly supplies p+0x58, retained here.
 * semantics: word bitfields use unsigned shifts; all dynamic address adds
 * and scaling are u32 modulo 2^32, without assuming selector/index bounds.
 * Byte increment is promoted in 0..255 then narrowed; all locals initialized
 * on each path to a use. The branch to state 4 has no uninitialized outputs.
 */
int func_021CEA94(u8 *p, u32 *state)
{
    void *m;
    u32 slot, k;
    u32 *record;
    u8 sub;
    switch (*state) {
    case 0:
        if (func_021B8588(((struct Obj00434 *)p)->f0) != 3) {
            if (func_021CF524((u32)p, ((struct Obj00434 *)p)->f8, *(u32 *)&((struct Obj00434 *)p)->fC))
                func_021CE150(p, (void *)((u32)func_021CF220));
            else *state = 1;
        } else {
            func_021CECB4(p, (Ent *)(p + 0xa4));
            *state = 2;
        }
        break;
    case 1:
        func_021E97BC(((struct Obj00434 *)p)->f54, (u8 *)(*(u32 *)&((struct Obj00434 *)p)->f8), *(u32 *)&((struct Obj00434 *)p)->fC);
        *state = 3;
        break;
    case 2:
        func_021E9808(((struct Obj00434 *)p)->f54, (u32 *)(p + 0xa4), *(int *)&((struct Obj00434 *)p)->fC);
        *state = 3;
        break;
    case 3:
        if (func_021CE0BC(p, (void *)((u32)func_021CE3C8))) {
            func_021E98AC(((struct Obj00434 *)p)->f54);
            return 0;
        }
        if (func_021E98B4(((struct Obj00434 *)p)->f54)) {
            k = func_021D8454(*(u32 * *)&((struct Obj00434 *)p)->fC);
            if (k == 0) func_021CE150(p, (void *)((u32)func_021CE4D0));
            else if (k == 5) func_021CE150(p, (void *)((u32)func_021CF220));
            else {
                m = ((struct Obj00434 *)p)->f8;
                record = *(u32 * *)&((struct Obj00434 *)p)->fC;
                sub = 0;
                slot = p[0x11d];
                if (func_021B8588(((struct Obj00434 *)p)->f0) == 3) {
                    sub = (u8)((Record *)(p + 0xbc))->sub;
                    slot = func_021B9AB0(sub);
                    m = *(void **)((u32)p + slot * 8U + 0xa4U);
                }
                if (func_021D832C((struct Unk021D82FC *)record)) {
                    p[0x1b0] = slot;
                    p[0x1b1] = func_021D5778(m, (u16)((Record *)record)->id);
                    if (p[0x1b1] != 4) {
                        func_021CE150(p, (void *)((u32)func_021CED4C));
                        return 0;
                    }
                }
                if (func_021CF5B0(p, m, (u16)((Record *)record)->id, p + 0x58)) {
                    func_021EAF78(p + 0x58, 0xff);
                    func_021CE3B4(p, p + 0x58);
                    *state = 7;
                } else {
                    if (func_021B8588(((struct Obj00434 *)p)->f0) == 3 && sub != 0 && sub != 1 && !func_021D5B68(m)) {
                        k = func_021D8340((u32 *)(p + 0xc0));
                        record = *(u32 * *)&((struct Obj00434 *)p)->fC;
                        *(u32 *)&((struct Obj00434 *)p)->fC = (u32)record + 4U;
                        func_021D83FC(record, sub);
                        func_021D82D0(((struct Obj00434 *)p)->fC, k, 6);
                        ++p[0x1af];
                    }
                    *state = 4;
                }
            }
        }
        break;
    case 4:
        if (func_021D7EF0(func_021B8588(((struct Obj00434 *)p)->f0))) *state = 5;
        else func_021CE150(p, (void *)((u32)func_021CF220));
        break;
    case 5:
        func_021E98BC(((struct Obj00434 *)p)->f54, (u8 *)(*(u32 *)&((struct Obj00434 *)p)->f8), *(u32 *)&((struct Obj00434 *)p)->fC);
        *state = 6;
        break;
    case 6:
        if (func_021CE0BC(p, (void *)((u32)func_021CE3C8))) {
            func_021E9920(((struct Obj00434 *)p)->f54);
            return 0;
        }
        k = func_021E98E8(((struct Obj00434 *)p)->f54);
        if (k == 1) func_021CE150(p, (void *)((u32)func_021CF220));
        else if (k == 2) *state = 1;
        break;
    case 7:
        if (func_021EA710(((struct Obj00434 *)p)->f54)) {
            func_021E9858(((struct Obj00434 *)p)->f54);
            *state = 3;
        }
        break;
    }
    return 0;
}




void func_021CECB4(u8 *p, Ent *out)
{
    u32 i;
    u32 j;
    u8 *q;
    u32 n;
    u32 k;
    Ent *e;
    for (i = 0; i < 3; i++) {
        q = func_021B9C00(((struct Obj21136 *)p)->f118, (u8)i);
        e = out + i;
        e->q = q;
        for (j = 0; j < 4; j++) {
            e->f[j] = 0;
        }
        if (func_021D5B68(q) == 0) {
            n = func_021D5448((struct QG *)q);
            for (k = 0; k < n; k++) {
                if (func_021D5584((struct UtilWork *)q, (u8)k) == 0 || func_021CF5B0(p, q, (u32)func_021D54C0(q, (u8)k), 0) != 0) {
                    e->f[k] = 0;
                } else {
                    e->f[k] = 1;
                }
            }
        }
    }
}




u32 func_021CED4C(u8 *p, s32 *st)
{
    u32 r;
    switch (*st) {
    case 0:
        func_021E9CE0((u8 *)(((struct Obj05199 *)p)->f54), p[0x1b0], p[0x1b1]);
        *st = *st + 1;
        break;
    case 1:
        r = 0;
        if (func_021CE0BC(p, 0) != 0) {
            func_021E9B14((unsigned int *)(((struct Obj05199 *)p)->f54));
            *st = 2;
            return r;
        }
        if (func_021E9B20((u8 *)(((struct Obj05199 *)p)->f54)) != 0) {
            func_021CE150(p, (void *)((u32)func_021CEA94));
        }
        break;
    case 2:
        if (func_021E9B20((u8 *)(((struct Obj05199 *)p)->f54)) != 0) {
            func_021CE150(p, (void *)((u32)func_021CE3C8));
        }
        break;
    }
    return 0;
}




u32 func_021CEDC0(u8 *p, int *st)
{
    u8 a;
    u16 b;
    u32 r, n;
    switch (*st) {
    case 0:
        r = 0;
        if ((u8)func_021CF8D4(p, ((struct Obj03194 *)p)->f8, &a, &b) != 4 ||
            a == func_021D5440(((struct Obj03194 *)p)->f8)) r = 1;
        func_021E9A78(*(char * *)&((struct Obj03194 *)p)->f54, p + 0x184, p[0x11d], r, p + 0x190);
        ++*st;
        break;
    case 1:
        r = 0;
        if (func_021CE0BC(p, 0)) {
            func_021E9B14((unsigned int *)(*(u32 *)&((struct Obj03194 *)p)->f54));
            *st = 2;
            return r;
        }
        if (func_021E9B20((u8 *)(*(u32 *)&((struct Obj03194 *)p)->f54))) {
            if (func_021CEE98(p + 0x190) == 0) {
                n = func_021CEEA8(p + 0x190);
                if (n < 6) {
                    func_021D8394(((struct Obj03194 *)p)->fC, p[0x11d], n);
                    func_021CE150(p, (void *)((u32)func_021CF220));
                    break;
                }
            }
            func_021CE150(p, (void *)((u32)func_021CE4D0));
        }
        break;
    case 2:
        if (func_021E9B20((u8 *)(*(u32 *)&((struct Obj03194 *)p)->f54))) func_021CE150(p, (void *)((u32)func_021CE3C8));
        break;
    }
    return 0;
}
