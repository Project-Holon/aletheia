/*
 * file:     btl_server_p26.c
 * unit:     yes
 * function: func_021D0B6C, func_021D0BB0, func_021D0C78, func_021D0CC4, func_021D0D38,func_021D0D44, func_021D0D50, func_021D0E7C, func_021D102C, func_021D1058, func_021D10B8, func_021D123C, func_021D127C, func_021D1290, func_021D13A4, func_021D13FC, func_021D1410, func_021D1708, func_021D171C, func_021D185C, func_021D18EC, func_021D1960, func_021D1A18, func_021D1A60, func_021D1A74, func_021D1BD0, func_021D1C40, func_021D1CAC, func_021D1CF4, func_021D1DF4, func_021D1E6C, func_021D1EB4, func_021D1F10, func_021D1F58, func_021D1FB4, func_021D2000, func_021D2030, func_021D20BC, func_021D210C, func_021D215C, func_021D21D4, func_021D2234, func_021D2278, func_021D2320, func_021D2374, func_021D23B8, func_021D2424, func_021D2490, func_021D2510, func_021D2580, func_021D25C4, func_021D2628, func_021D266C, func_021D2700, func_021D2814, func_021D284C, func_021D28AC, func_021D2930, func_021D2990, func_021D299C, func_021D29CC, func_021D2A20, func_021D2C7C, func_021D2CA8, func_021D2FD8, func_021D3138, func_021D31A0, func_021D324C, func_021D32E0, func_021D344C, func_021D34B0, func_021D34E8
 * address:  0x021D0B6C
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
 *   func_021D8394  0x021D8394  thumb  ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B99C0 0x021B99C0 thumb ov093
 *   func_021B8E28 0x021B8E28 thumb ov093
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021EEC20  0x021EEC20  thumb  ov093
 *   func_021B8DE4  0x021B8DE4  thumb  ov093
 *   func_021EAF18  0x021EAF18  thumb  ov093
 *   func_021EABC4  0x021EABC4  thumb  ov093
 *   func_021EAC54  0x021EAC54  thumb  ov093
 *   func_021CE1B0 0x021CE1B0 thumb ov093
 *   func_021D0980 0x021D0980 thumb ov093
 *   func_021CFD50 0x021CFD50 thumb ov093
 *   func_021D09E0 0x021D09E0 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021D83C4 0x021D83C4 thumb ov093
 *   func_021D8434 0x021D8434 thumb ov093
 *   func_021D0B10 0x021D0B10 thumb ov093
 *   func_021E9A78 0x021E9A78 thumb ov093
 *   func_021CE068 0x021CE068 thumb ov093
 *   func_021CE08C 0x021CE08C thumb ov093
 *   func_021E9B14 0x021E9B14 thumb ov093
 *   func_021E9B20 0x021E9B20 thumb ov093
 *   func_021CE0E0 0x021CE0E0 thumb ov093
 *   func_021B86C0 0x021B86C0 thumb ov093
 *   func_021EA7FC 0x021EA7FC thumb ov093
 *   func_021EA814 0x021EA814 thumb ov093
 *   func_021B9AB0  0x021B9AB0  thumb  ov093
 *   func_021D83FC  0x021D83FC  thumb  ov093
 *   func_021EAF50 0x021EAF50 thumb ov093
 *   func_021EAF78 0x021EAF78 thumb ov093
 *   func_021EA614 0x021EA614 thumb ov093
 *   func_021EA710 0x021EA710 thumb ov093
 *   func_021EA720 0x021EA720 thumb ov093
 *   func_021D121C 0x021D121C thumb ov093
 *   func_021D122C 0x021D122C thumb ov093
 *   func_021EE608  0x021EE608  thumb  ov093
 *   func_021BB4E0  0x021BB4E0  thumb  ov093
 *   func_021EE638  0x021EE638  thumb  ov093
 *   func_021B904C 0x021B904C thumb ov093
 *   func_021B86C8 0x021B86C8 thumb ov093
 *   func_021B916C 0x021B916C thumb ov093
 *   func_021B86DC 0x021B86DC thumb ov093
 *   func_02005D90 0x02005D90 thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_02005E50 0x02005E50 thumb
 *   func_02005D28 0x02005D28 thumb
 *   func_021B902C  0x021B902C  thumb  ov093
 *   func_021B8FF4   0x021B8FF4  thumb ov093
 *   func_021B919C   0x021B919C  thumb ov093
 *   func_021B9210   0x021B9210  thumb ov093
 *   func_021B9244   0x021B9244  thumb ov093
 *   func_021BA004   0x021BA004  thumb ov093
 *   func_021BA020   0x021BA020  thumb ov093
 *   func_021BA1A8   0x021BA1A8  thumb ov093
 *   func_021EA6B0   0x021EA6B0  thumb ov093
 *   func_021F7998   0x021F7998  thumb ov094
 *   func_021F7EB4   0x021F7EB4  thumb ov094
 *   func_021F7F58   0x021F7F58  thumb ov094
 *   func_021F878C   0x021F878C  thumb ov094
 *   func_021EA600 0x021EA600 thumb ov093
 *   func_021BA02C  0x021BA02C  thumb  ov093
 *   func_02024450  0x02024450  thumb
 *   func_0202435C  0x0202435C  thumb
 *   func_021EA5E4  0x021EA5E4  thumb  ov093
 *   sub_02045808   0x02045808  arm
 *   func_021EA5F0  0x021EA5F0  thumb  ov093
 *   func_021BB570 0x021BB570 thumb ov093
 *   func_021B9184 0x021B9184 thumb ov093
 *   func_02082A90 0x02082A90 arm
 *   func_021EA824 0x021EA824 thumb ov093
 *   func_021D3F4C 0x021D3F4C thumb ov093
 *   func_021CD5E0 0x021CD5E0 thumb ov093
 *   d_021F00DC 0x021F00DC data a4
 *   func_021CDEE8  0x021CDEE8  thumb  ov093
 *   func_021B9F70  0x021B9F70  thumb  ov093
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021EA458  0x021EA458  thumb  ov093
 *   func_021EA478  0x021EA478  thumb  ov093
 *   func_021B9920 0x021B9920 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8CE8 0x021B8CE8 thumb ov093
 *   func_021B8BEC 0x021B8BEC thumb ov093
 *   func_021EA488 0x021EA488 thumb ov093
 *   func_021EA4C4 0x021EA4C4 thumb ov093
 *   func_021CDECC 0x021CDECC thumb ov093
 *   func_021B9064  0x021B9064  thumb  ov093
 *   func_021D5C44  0x021D5C44  thumb  ov093
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021EA678  0x021EA678  thumb  ov093
 *   func_020061E4  0x020061E4  thumb
 *   func_021EA694  0x021EA694  thumb  ov093
 *   func_021EA6F4  0x021EA6F4  thumb  ov093
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021D80A8  0x021D80A8  thumb  ov093
 *   func_0201BD28  0x0201BD28  thumb
 *   func_021B8590 0x021B8590 thumb ov093
 *   func_021EA0A0 0x021EA0A0 thumb ov093
 *   func_021EA0E4 0x021EA0E4 thumb ov093
 *   func_021B8DC0  0x021B8DC0  thumb  ov093
 *   func_021EA354  0x021EA354  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021EA0F4  0x021EA0F4  thumb  ov093
 *   func_021EA120  0x021EA120  thumb  ov093
 *   func_021CD644  0x021CD644  thumb  ov093
 *   func_021EA280  0x021EA280  thumb  ov093
 *   func_021EA2BC  0x021EA2BC  thumb  ov093
 *   func_021EA384  0x021EA384  thumb  ov093
 *   func_021EA3A0  0x021EA3A0  thumb  ov093
 *   func_021F81D0  0x021F81D0  thumb  ov094
 *   func_021EA40C  0x021EA40C  thumb  ov093
 *   func_021EA428  0x021EA428  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D646C  0x021D646C  thumb  ov093
 *   func_021EA438  0x021EA438  thumb  ov093
 *   func_021EA448  0x021EA448  thumb  ov093
 *   func_021EA7C8  0x021EA7C8  thumb  ov093
 *   func_021EA7E8  0x021EA7E8  thumb  ov093
 *   func_021EA7D8  0x021EA7D8  thumb  ov093
 *   func_021EF9C0  0x021EF9C0  thumb  ov093
 *   d_021EFFAE     0x021EFFAE  data   ov093  a2
 *   func_021EF9C8  0x021EF9C8  thumb  ov093
 *   func_021EA838  0x021EA838  thumb  ov093
 *   func_021EA850  0x021EA850  thumb  ov093
 *   func_021B8DEC  0x021B8DEC  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9C10  0x021B9C10  thumb  ov093
 *   func_021EA904  0x021EA904  thumb  ov093
 *   func_021EA950  0x021EA950  thumb  ov093
 *   func_021F7E94 0x021F7E94 thumb ov094
 *   func_021F88BC  0x021F88BC  thumb  ov094
 *   func_021F7EA4  0x021F7EA4  thumb  ov094
 *   func_021D6C50  0x021D6C50  thumb  ov093
 *   func_021EA8B4  0x021EA8B4  thumb  ov093
 *   func_021EA8D4  0x021EA8D4  thumb  ov093
 *   func_021D7AD4  0x021D7AD4  thumb  ov093
 *   func_021EA1B8  0x021EA1B8  thumb  ov093
 *   func_021EA1F0  0x021EA1F0  thumb  ov093
 *   func_021EA8E4 0x021EA8E4 thumb ov093
 *   func_021EA8F4 0x021EA8F4 thumb ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   d_021EFF88     0x021EFF88  data  ov093  a2
 *   func_021F8204 0x021F8204 thumb ov094
 *   func_021D69B8 0x021D69B8 thumb ov093
 *   func_021F8134 0x021F8134 thumb ov094
 *   func_021F8180 0x021F8180 thumb ov094
 *   func_021D6EA0 0x021D6EA0 thumb ov093
 *   func_021D6BFC 0x021D6BFC thumb ov093
 *   func_021F8150 0x021F8150 thumb ov094
 *   func_02006238 0x02006238 thumb
 *   func_021EA3B8 0x021EA3B8 thumb ov093
 *   func_021EA3D4 0x021EA3D4 thumb ov093
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   func_02005F38 0x02005F38 thumb
 *   func_02005E9C 0x02005E9C thumb
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_021BA238 0x021BA238 thumb ov093
 *   func_021EADA4 0x021EADA4 thumb ov093
 *   func_021EADB4 0x021EADB4 thumb ov093
 *   func_021EADC4 0x021EADC4 thumb ov093
 *   func_021EADD4 0x021EADD4 thumb ov093
 *   func_021EADE4 0x021EADE4 thumb ov093
 *   func_021EADF4 0x021EADF4 thumb ov093
 *   func_021B9358 0x021B9358 thumb ov093
 *   d_021F3B64 0x021F3B64 data a4
 *   func_02006254 0x02006254 thumb
 *   func_020181F4   0x020181F4  thumb
 *   func_02018328   0x02018328  thumb
 *   func_021B9AF8   0x021B9AF8  thumb ov093
 *   func_021B9CBC   0x021B9CBC  thumb ov093
 *   func_021EA638   0x021EA638  thumb ov093
 *   func_021EAC64   0x021EAC64  thumb ov093
 *   func_021EAC80   0x021EAC80  thumb ov093
 *   g_021F3B64      0x021F3B64  data
 *   func_021F7CFC 0x021F7CFC thumb ov094
 *   func_021F883C 0x021F883C thumb ov094
 *   d_021EFF80 0x021EFF80 data a2
 *   func_021BA2D4 0x021BA2D4 thumb ov093
 *   func_021F7C0C 0x021F7C0C thumb ov094
 *   func_021B92A0 0x021B92A0 thumb ov093
 *   func_021F7D44  0x021F7D44  thumb  ov094
 *   func_021B9C50  0x021B9C50  thumb  ov093
 *   func_021EAA6C  0x021EAA6C  thumb  ov093
 *   func_021EAAD8  0x021EAAD8  thumb  ov093
 *   func_021D66D0  0x021D66D0  thumb  ov093
 *   func_021EA768  0x021EA768  thumb  ov093
 *   func_021EA778  0x021EA778  thumb  ov093
 *   func_021EA7A8  0x021EA7A8  thumb  ov093
 *   func_021EA7B8  0x021EA7B8  thumb  ov093
 *   func_021B9A24 0x021B9A24 thumb ov093
 *   func_021D6C2C  0x021D6C2C  thumb  ov093
 *   func_021EA868  0x021EA868  thumb  ov093
 *   func_021EA878  0x021EA878  thumb  ov093
 *   func_021D3558  0x021D3558  thumb
 */
#include "../../matched/include/Obj13365.h"
#include "../../matched/include/Obj03198.h"
#include "../../matched/include/Obj09995.h"
#include "../../matched/include/Obj05202.h"
#include "../../matched/include/Obj01236.h"
#include "../../matched/include/Obj00819.h"
#include "../../matched/include/Obj13368.h"
#include "../../matched/include/Obj13369.h"
#include "../../matched/include/Obj05203.h"
#include "../../matched/include/Obj00066.h"
#include "../../matched/include/Obj01237.h"
#include "../../matched/include/Obj01691.h"
#include "../../matched/include/Obj21146.h"
#include "../../matched/include/Obj06240.h"
#include "../../matched/include/Obj07782.h"
#include "../../matched/include/Obj05206.h"
#include "../../matched/include/Obj05207.h"
#include "../../matched/include/Obj10019.h"
#include "../../matched/include/Obj10021.h"
#include "../../matched/include/Obj07783.h"
#include "../../matched/include/Obj06241.h"
#include "../../matched/include/Obj07784.h"
#include "../../matched/include/Obj04364.h"
#include "../../matched/include/Obj21158.h"
#include "../../matched/include/Obj03693.h"
#include "../../matched/include/Obj13398.h"
#include "../../matched/include/Obj00268.h"
#include "../../matched/include/G_StateData.h"

struct Q1;
struct S2;
struct L;
struct G;
struct H;
struct U16Vec;
struct S;
struct Rat;
struct Unk021D6C50;
struct Obj;
struct Result;
struct T;
struct QJ;
struct Unk021D6C2C;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    void *battle;         /* 0x00 */
    u8 unk04[0x50];
    void *msgWin;         /* 0x54 */
    u8 msg[0x14E];        /* 0x58 */
    u8 unk1A6;            /* 0x1A6 */
} BattleSeq_021D0B6C;

typedef struct { u8 pad[0x1B3]; volatile u8 count; } CountField;

typedef struct { u8 pad[0x1B2]; unsigned char f0:5; unsigned char flag:1; unsigned char f6:2; } Flags;

typedef struct {
    void *battle;         /* 0x00 */
    void *unk04;          /* 0x04 */
    u8 unk08[0x4C];
    void *msgWin;         /* 0x54 */
    u8 msg[0x14E];        /* 0x58 */
    u8 unk1A6;            /* 0x1A6 */
} BattleSeq_021D123C;

typedef struct { u8 pad[0x1B2]; unsigned char f0:5; unsigned char flag:1; unsigned char f6:2; } Flags_021D1410;

typedef struct { u32 wpos, rpos; } Buf;

typedef struct { u8 pad[0x1B2]; unsigned char f0:3; unsigned char flag:1; unsigned char f4:4; } Flags_021D1A60;

typedef int (*Callback)(u8 *, int *, int *);

typedef struct { int code; Callback fn; } Entry;

typedef struct {
    u8 unk00[0x54];
    void *win;            /* 0x54 */
} Seq_021D123C;

typedef struct {
    u32 unk00;
    void *unk04;
    u8 unk08[0x4C];
    void *win;
} Seq_021D2030;

typedef struct {
    u32 unk00;
    u32 unk04;
    u8 unk08[0x4C];
    void *win;            /* 0x54 */
} Seq_021D20BC;

typedef struct {
    u32 unk00;
    u32 unk04;
    u8 unk08[0x4C];
    void *win;            /* 0x54 */
} Seq_021D210C;

typedef struct {
    u8 unk00[0x54];
    void *win;            /* 0x54 */
    u8 unk58[0x134 - 0x58];
    u32 unk134;
} Seq_021D215C;

typedef struct {
    u32 unk00;
    u32 unk04;
    u8 unk08[0x4C];
    void *win;            /* 0x54 */
} Seq_021D21D4;

typedef struct {
    u32 unk00;
    u32 unk04;
} Seq_021D2234;

typedef struct { u16 a; u16 b; } Pair16;

typedef struct { u8 data[0x24]; } MsgParam;

typedef struct {
    void *battle;
    void *party;
    u8 unk008[0x4c];
    void *msgWin;
    MsgParam msg;
    u8 unk07C[0x11e];
    u16 level;
    u8 unk19C[0xa];
    u8 side;
} LearnSeq_021D123C;

struct StateDataL { u8 pad0[8]; int counter; u32 remaining; u32 pad10; u8 result[14]; };

typedef struct {
    void *battle;       /* 0x000 */
    void *party;        /* 0x004 */
    u8 unk008[0x4C];
    void *msgWin;       /* 0x054 */
    MsgParam msg;       /* 0x058 */
    u8 unk07C[0x11E];
    u16 level;          /* 0x19A */
    u8 unk19C[0xA];
    u8 side;            /* 0x1A6 */
} LearnSeq_021D2C7C;

union DView { struct StateDataL s; u32 w[9]; };

extern void func_021D8394(void *dst, u8 a, u8 b);
extern u8 func_021B9B94(struct Q1 *p);
extern u8 func_021B99C0(void *, int);
extern void func_021B8E28(u8 *, u8, u8 *, u8 *);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B68(void *);
extern int func_021EEC20(int, u8 **);
extern u8 func_021B8DE4(char *p, int i);
extern void func_021EAF18(struct L *p, int kind, int id);
extern void func_021EABC4(u8 *a, u32 x, u32 y, u32 z);
extern int func_021EAC54(void *win, int *out);
extern u8 func_021D0980(u8 *,u8 *);
extern u8 *func_021CFD50(struct G *g, int k);
extern void func_021D09E0(u8 *p, u8 *order, u8 count, void *target);
extern u32 func_021B8588(void **);
extern void func_021D83C4(u32 *p);
extern void func_021D8434(u32 *p);
extern int func_021CE1B0(u8 *,int *);
extern void func_021D0B10(u8 *p, u32 a, u32 b, void *q, void *out);
extern void func_021E9A78(char *p, const u8 *q, int x, int y, u8 *r);
extern void func_021CE068(u8 *);
extern int func_021CE08C(u8 *);
extern void func_021E9B14(unsigned int *p);
extern int func_021E9B20(u8 *p);
extern void func_021CE0E0(u8 *p);
extern u8 func_021B86C0(u8 **p);
extern void func_021EA7FC(char *p);
extern int func_021EA814(u32 *p);
extern int func_021B9AB0(int k);
extern void func_021D83FC(u32 *p, u32 sub);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EAF78(u8 *p, u8 v);
extern void func_021EA614(char *p, struct H *h);
extern int func_021EA710(u32 *p);
extern int func_021EA720(u32 *p);
extern int func_021D121C(void *);
extern u8 func_021D122C(void *);
extern void func_021EE608(u8 *p, const u8 *src, int n);
extern void func_021BB4E0(int, int, int);
extern u8 func_021EE638(u8 *p);
extern u8 func_021B904C(u8 *p, int k);
extern int func_021B86C8(unsigned char **p);
extern void func_021B916C(u8 *p, u32 x);
extern u16 func_021B86DC(void **p);
extern void func_02005D90(u16, u16);
extern void func_02005E30(u32);
extern int func_02005E50(void);
extern void func_02005D28(void);
extern int func_021B902C(int a, int b);
extern void func_021F878C(u32 a);
extern int func_021BA1A8(char **p, int m);
extern u8 func_021B8FF4(u8 *p);
extern unsigned short func_021BA020(char *p, int i);
extern u16 func_021BA004(char *p, int i);
extern u32 func_021B919C(u8 *p);
extern u32 func_021B9210(u8 *p);
extern u32 func_021B9244(char *p);
extern int func_021EA6B0(char *p, u16 a, u16 b);
extern int func_021F7EB4(void);
extern void func_021F7F58(int a, u32 b, u32 c, u32 d, u32 e);
extern void func_021F7998(u32 a);
extern void func_021EA600(char *p);
extern void *func_021BA02C(char *p, int i, int mode);
extern int func_02024450(const u16 *p);
extern void *func_0202435C(void *slots, unsigned int heap);
extern void func_021EA5E4(unsigned char *p, void *src);
extern void sub_02045808(struct U16Vec *vec);
extern void func_021EA5F0(char *p, struct H *h);
extern int func_021BB570(u8 *, int, void *, u32);
extern void func_021B9184(void *);
extern void func_02082A90(const void *, void *, u32);
extern void func_021EA824(char *p);
extern int func_021D3F4C(void *);
extern int func_021CD5E0(Buf *, int *);
extern u32 func_021CDEE8(u8 *p);
extern int func_021B9F70(u8 *p, int i);
extern u8 func_021B8E70(u8 *p, u32 k);
extern void func_021EA458(char *ctx, u16 a, u16 b);
extern int func_021EA478(u32 *p);
extern u8 *func_021B9920(void *p, u32 i, u8 j);
extern u8 func_021D5440(u8 *p);
extern int func_021B8CE8(int a, int b, int c);
extern u8 func_021B8BEC(u8 *, u32, u8);
extern void func_021EA488(struct S *s, u8 a, u8 b, u8 c);
extern int func_021EA4C4(struct S *s);
extern void func_021CDECC(u8 *p);
extern u32 func_021B9064(u8 *p, int k, int x);
extern int func_021D5C44(struct Rat *p);
extern u32 func_021CD9E0(u8 *p);
extern void func_021EA678(char *p, u16 k, int *c);
extern void func_020061E4(unsigned int arg);
extern void func_021EA694(char *p, u16 k, int *c);
extern void func_021EA6F4(void *p, u8 b, u16 c);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern int func_021D80A8(void *p);
extern u32 func_0201BD28(u32 v, u32 n);
extern unsigned int func_021B8590(unsigned char *p);
extern void func_021EA0A0(u32 *p, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u8 s7);
extern int func_021EA0E4(u32 *p);
extern unsigned char func_021B8DC0(unsigned char *p, void *a, unsigned int b);
extern void func_021EA354(void *ctx, int a, int b);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern void func_021EA0F4(struct S *s, u32 a, u32 b, u32 c);
extern int func_021EA120(struct S *s);
extern u8 func_021CD644(u8 *p);
extern void func_021EA280(char *ctx, u32 n, int b, const u8 *c, u16 e);
extern int func_021EA2BC(char *ctx);
extern void func_021EA384(char *ctx, int a);
extern int func_021EA3A0(u32 *p);
extern void func_021F81D0(u32 a, u32 b);
extern void func_021EA40C(char *ctx, int a);
extern int func_021EA428(u32 *p);
extern u8 *func_021B9934(char *p, int i);
extern void func_021D646C(void *p);
extern void func_021EA438(u32 *p, u32 a2);
extern int func_021EA448(u32 *p);
extern void func_021EA7C8(void *ctx, int a);
extern int func_021EA7E8(void *w, int v);
extern void func_021EA7D8(void *ctx, int a);
extern int *func_021EF9C0(int *p, int a, int b);
extern void func_021EF9C8(int *p);
extern void func_021EA838(u32 *p, u32 k);
extern int func_021EA850(u32 *p, u32 k);
extern int func_021B8DEC(void *p, u32 k);
extern char *func_021B9AEC(char *p, int i);
extern void func_021B9C10(u32 *p, int a, int b);
extern void func_021EA904(void *w, u32 a, u32 b, u32 c, int d, int e);
extern int func_021EA950(void *w);
extern void func_021F7E94(int a);
extern void func_021F88BC(int v);
extern void func_021F7EA4(u32 v);
extern int func_021D6C50(struct Unk021D6C50 *a, struct Unk021D6C50 *b);
extern void func_021EA8B4(char *ctx, u32 a, u32 b);
extern int func_021EA8D4(u32 *p);
extern int func_021D7AD4(int a);
extern void func_021EA1B8(struct S *s, u32 a, int b, int c);
extern int func_021EA1F0(struct S *s);
extern void func_021EA8E4(u32 *p);
extern int func_021EA8F4(u32 *p);
extern void *func_021D5844(void *m);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02017E40(void *p, u32 id, u32 v);
extern int func_021F8204(int);
extern int func_021D69B8(struct Obj *p, u32 *remaining, struct Result *r);
extern void func_021F8134(int, u32);
extern int func_021F8180(void);
extern void func_021D6EA0(void *);
extern void func_021D6BFC(u8 *p);
extern void func_021F8150(int, void *);
extern int func_02006238(void);
extern void func_021EA3B8(char *ctx, int a, int b);
extern int func_021EA3D4(void *);
extern void func_02005DE4(void *);
extern int func_02005E64(void);
extern int func_02005F38(void);
extern int func_02005E9C(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_021BA238(char *p, void *m);
extern void func_021EADA4(u8 *, int, struct T *);
extern int func_021EADB4(u8 *);
extern void func_021EADC4(u8 *);
extern int func_021EADD4(u8 *);
extern void func_021EADE4(u8 *);
extern int func_021EADF4(u8 *);
extern void func_021B9358(char *p, int i);
extern int func_02006254(unsigned int);
extern u16 func_02018328(void *p, u32 *idx, u32 heap);
extern void func_021EA638(char *p, struct H *h, int c);
extern char *func_021B9AF8(char *p, int i);
extern int func_021B9CBC(u8 *p, int v);
extern void func_021EAC64(u8 *p, u8 a, int c);
extern int func_021EAC80(u8 *p, u8 *out);
extern void func_020181F4(void *p, u16 move, u32 slot);
extern void func_021F7CFC(u32, u16, u8, int, int);
extern void func_021F883C(u32);
extern void func_021BA2D4(u32 p, u32 *q);
extern void func_021F7C0C(void);
extern void func_021B92A0(u8 *p);
extern void func_021F7D44(int a, u16 b);
extern void func_021B9C50(u8 **p, int k, u8 **o1, u8 **o2);
extern void func_021EAA6C(u32 a, int b, int c);
extern int func_021EAAD8(u32 a);
extern void func_021D66D0(struct QJ *p, u32 v);
extern void func_021EA768(u32 *p, u32 a2, u32 a3);
extern int func_021EA778(u32 *p, u32 a2);
extern void func_021EA7A8(u32 *p, u32 a2);
extern int func_021EA7B8(u32 *p, u32 a2);
extern int func_021B9A24(u32, u32);
extern void func_021D6C2C(struct Unk021D6C2C *p);
extern void func_021EA868(u32 *p, u32 a2, u32 a3);
extern int func_021EA878(u32 *p);
extern int func_021D3558(u16 v);
void func_021D0B6C(u8 *g, u8 *s);
void func_021D0BB0(u8 *p);
u8 func_021D0C78(BattleSeq_021D0B6C *s, u8 *out);
int func_021D0CC4(BattleSeq_021D0B6C *s, int *state);
int func_021D0D38(u8 *p, int *state);
int func_021D0D44(u8 *p, int *state);
int func_021D0D50(u8 *p);
int func_021D0E74(u8 *p,int *state);
int func_021D0E7C(u8 *p, int *state, u8 param);
int func_021D102C(char *p);
int func_021D1058(u8 *s, void *q);
int func_021D10B8(u8 *p, int *state);
int func_021D123C(int a);
int func_021D127C(u8 *p, int *state);
int func_021D1290(u8 *p, int *state, void *a2);
int func_021D13A4(BattleSeq_021D123C *s);
int func_021D13FC(u8 *p, int *state);
int func_021D1410(BattleSeq_021D123C *s, int *state, void *q);
int func_021D1708(u8 *p, int *state);
int func_021D171C(u8 *p, int *state, void *a2);
void func_021D185C(BattleSeq_021D123C *s, int a, int b);
int func_021D18EC(BattleSeq_021D123C *s, int *state);
int func_021D1960(BattleSeq_021D123C *s, int *state);
int func_021D1A18(BattleSeq_021D123C *s, int *state);
int func_021D1A60(u8 *p, int *state);
int func_021D1A74(u8 *p, int *state, void *a2);
int func_021D1BD0(BattleSeq_021D123C *s, int *state, int *pp);
int func_021D1C40(BattleSeq_021D123C *s, u8 x, int *out);
int func_021D1CAC(BattleSeq_021D123C *s, int *state, int *pp);
int func_021D1CF4(u8 *p, int *state, const u32 *params);
int func_021D1DF4(BattleSeq_021D123C *s);
int func_021D1E6C(Seq_021D123C *s, int *state, u32 *a);
int func_021D1EB4(Seq_021D123C *s, int *state, u32 *a);
int func_021D1F10(Seq_021D123C *s, int *state, u32 *a);
int func_021D1F58(Seq_021D123C *s, int *state, u32 *a);
int func_021D1FB4(Seq_021D123C *s, int *state, u32 *a);
u32 func_021D2000(Seq_021D2030 *p, u32 k, u8 b);
int func_021D2030(Seq_021D2030 *s, int *state, const u32 *a);
int func_021D20BC(Seq_021D20BC *s, int *state, u32 *a);
int func_021D210C(Seq_021D210C *s, int *state, u32 *a);
int func_021D215C(Seq_021D215C *s, int *state, u32 *a);
int func_021D21D4(Seq_021D21D4 *s, int *state, u32 *a);
int func_021D2234(Seq_021D2234 *s, int *state, u32 *a);
int func_021D2278(Seq_021D2030 *s, int *state, u32 *a);
int func_021D2320(u8 *p, int *st, u32 *c);
int func_021D2374(u8 *p, int *st, u32 *c);
int func_021D23B8(u8 *p, int *st, u32 *c);
int func_021D2424(u8 *p, int *st, u32 *c);
int func_021D2490(u8 *p, int *st, u32 *c);
int func_021D2510(u8 *p, int *st, u32 *c);
int func_021D2580(u8 *p, int *st, u32 *c);
int func_021D25C4(u8 *p, int *st, u32 *c);
int func_021D2628(u8 *p, int *st, u32 *c);
int func_021D266C(u8 *p, int *st, u32 *c);
int func_021D2700(u32 *p, int *st, u32 *c);
int func_021D2814(char *p, int *state, unsigned int *q);
int func_021D284C(u8 *p, int *st, u32 *c);
int func_021D28AC(u8 *p, int *st, u32 *c);
int func_021D2930(u32 *a, int *b, u32 *c);
int func_021D2990(int a, int b, int *c);
int func_021D299C(char *p, int *state);
int func_021D29CC(u32 *a, int b, u32 *c);
int func_021D2A20(u8 *p, int *state, u32 *args);
int func_021D2C7C(int n);
int func_021D2CA8(LearnSeq_021D2C7C *s, int *state, void *mon);
int func_021D2FD8(u32 *a, int *b, const u32 *c);
int func_021D3138(u32 *a, int *b, u32 *c);
int func_021D31A0(u32 *a, int *b, u32 *c);
int func_021D324C(u32 *a, int *b, u32 *c);
int func_021D32E0(u32 *a, int *b, u32 *c);
int func_021D344C(u32 *a, int *b, u32 *c);
int func_021D34B0(char *p, int *state, unsigned int *q);
int func_021D34E8(u32 *a, int *b, u32 *c);
extern const Entry d_021F00DC[];
extern Pair16 d_021EFFAE[5];
extern u16 d_021EFF88[];
extern union DView d_021F3B64;
extern struct StateData g_021F3B64;
extern const u16 d_021EFF80[];






void func_021D0B6C(u8 *g, u8 *s)
{
    u8 i;

    for (i = 0; i < s[6]; i++)
        func_021D8394(g + 0x124 + i * 4, s[i + 3], s[i]);
    *(u8 * *)&((struct Obj13365 *)g)->fD8 = g + 0x124;
    ((struct Obj13365 *)g)->fDC = s[6] << 2;
}





void func_021D0BB0(u8 *p)
{
    u8 pair[2];
    u8 start;
    u8 count;
    u32 n;
    u32 i;
    u32 j;
    count = 0;
    n = func_021B9B94(((struct Obj03198 *)p)->f118);
    start = func_021B99C0(((struct Obj03198 *)p)->f0, p[0x1a6]);
    for (i = 0; i < p[0x1b3]; i++) {
        func_021B8E28(*(u8 * *)&((struct Obj03198 *)p)->f0, p[0x1b5 + i], &pair[1], &pair[0]);
        for (j = start; j < n; j++) {
            if (!func_021D5B68(func_021B9C00(((struct Obj03198 *)p)->f118, (u8)j))) {
                func_021D8394(p + 0x124 + count++ * 4, pair[0], j);
                start = j + 1;
                break;
            }
        }
    }
    ((struct Obj03198 *)p)->fD8 = p + 0x124;
    ((struct Obj03198 *)p)->fDC = count * 4;
}






u8 func_021D0C78(BattleSeq_021D0B6C *s, u8 *out)
{
    u8 *arr;
    u8 n;
    u32 i;
    u32 cnt;

    n = func_021EEC20(((struct Obj09995 *)s)->f50, &arr);
    i = 0;
    cnt = 0;
    for (; i < n; i++) {
        if (s->unk1A6 == func_021B8DE4(s->battle, arr[i])) {
            out[cnt] = arr[i];
            cnt++;
        }
    }
    return cnt;
}






int func_021D0CC4(BattleSeq_021D0B6C *s, int *state)
{
    int t;
    u8 *q;
    u8 f;

    switch (*state) {
    case 0:
        func_021EAF18((struct L *)s->msg, 3, 5);
        func_021EAF18((struct L *)((u8 *)s + 0x7c), 3, 1);
        func_021EABC4(s->msgWin, (u32)s->msg, (u32)((u8 *)s + 0x7c), 0);
        (*state)++;
        break;
    case 1:
        if (func_021EAC54(s->msgWin, &t)) {
            f = 0;
            if (t != 0)
                f = 1;
            q = (u8 *)s + 0x1ac;
            *q = f;
            *(u8 * *)&((struct Obj05202 *)s)->fD8 = q;
            ((struct Obj05202 *)s)->fDC = 1;
            return 1;
        }
        break;
    }
    return 0;
}




int func_021D0D38(u8 *p, int *state)
{
    return func_021D0E7C(p, state, 2);
}




int func_021D0D44(u8 *p, int *state)
{
    return func_021D0E7C(p, state, 1);
}





/*
 * lever: separate order[6] then pair[2] stack arrays keep the order base
 * at sp+6 and the index in the ldrb register offset; one buffer or a
 * struct member array reassociates this into a base+index and immediate 2.
 * follower: 021D0E74 is an eight-byte tail-call stub to func_021CE1B0;
 * included in this complete 300-byte unit after parent ownership audit.
 */
int func_021D0D50(u8 *p)
{
    u8 order[6];
    u8 pair[2];
    u8 count;
    u8 n;
    u8 i;
    u8 *target;
    int result;
    p[0x1b3] = func_021D0C78((BattleSeq_021D0B6C *)p, p+0x1b5);
    if (p[0x1b3]) {
        n = func_021D0980(p,order);
        if (n) {
            count = p[0x1b3];
            target = func_021CFD50((struct G *)p,p[0x1b5]);
            if (target) func_021D09E0(p,order,n,target);
            if (count > n) {
                if (func_021B8588(*(void ** *)&((struct Obj01236 *)p)->f0) == 3) {
                    result = func_021D1058(p,p+0x124);
                    if (result) {
                        *(int *)&((struct Obj01236 *)p)->fDC = result;
                        ((struct Obj01236 *)p)->fD8 = p+0x124;
                        return 1;
                    }
                }
                count = n;
            }
            for (i=0;i<count;i++) {
                func_021B8E28(*(u8 * *)&((struct Obj01236 *)p)->f0,p[0x1b5+i],pair,pair+1);
                func_021D8394(p+0x124+i*4,pair[1],order[i]);
            }
            ((struct Obj01236 *)p)->fD8 = p+0x124;
            ((struct Obj01236 *)p)->fDC = count*4;
        } else {
            if (func_021D102C((char *)p)) {
                result = func_021D1058(p,p+0x124);
                if (result) {
                    *(int *)&((struct Obj01236 *)p)->fDC = result;
                    ((struct Obj01236 *)p)->fD8 = p+0x124;
                    return 1;
                }
            }
            func_021D83C4((u32 *)(p+0x124));
            ((struct Obj01236 *)p)->fD8 = p+0x124;
            ((struct Obj01236 *)p)->fDC = 4;
        }
    } else {
        func_021D8434((u32 *)(p+0x124));
        ((struct Obj01236 *)p)->fD8 = p+0x124;
        ((struct Obj01236 *)p)->fDC = 4;
    }
    return 1;
}





int func_021D0E74(u8 *p,int *state)
{
    return func_021CE1B0(p,state);
}





/*
 * lever: the state-0 fallbacks and single-mon path set state 4, not 6;
 * duplicating the state-4 assignment inside both fallback arms preserves
 * the late cross-jump of D8/DC stores. Factoring it outside adds 12 bytes.
 * volatile: count at 021D0EB2 is reread at 021D0EB6 and 021D0ECC.
 */
int func_021D0E7C(u8 *p, int *state, u8 param)
{
    u8 order[6];
    u8 pair[2];
    u32 n;
    u32 count;
    int mode;
    void *mon;
    switch (*state) {
    case 0:
        ((CountField *)p)->count = func_021D0C78((BattleSeq_021D0B6C *)p, p + 0x1B5);
        if (((CountField *)p)->count != 0) {
            n = func_021D0980(p, order);
            if (n != 0) {
                count = ((CountField *)p)->count;
                if (count > n) count = n;
                if (func_021D102C((char *)p) != 0) {
                    mon = func_021B9C00(((struct Obj00819 *)p)->f118, 0);
                    if (n == 1 && func_021D5B68(mon) != 0) {
                        func_021D8394(p + 0x124, 0, order[0]);
                        *(u8 * *)&((struct Obj00819 *)p)->fD8 = p + 0x124;
                        ((struct Obj00819 *)p)->fDC = 4;
                        *state = 4;
                        break;
                    }
                }
                func_021B8E28(*(u8 * *)&((struct Obj00819 *)p)->f0, p[0x1B5], &pair[1], &pair[0]);
                func_021D0B10(p, param, count, p + 0x184, p + 0x190);
                func_021E9A78(((struct Obj00819 *)p)->f54, p + 0x184, pair[0], 0, p + 0x190);
                func_021CE068(p);
                *state = 1;
            } else {
                if (func_021D102C((char *)p) != 0 && (mode = func_021D1058(p, p + 0x124)) != 0) {
                    ((struct Obj00819 *)p)->fDC = mode;
                    *(u8 * *)&((struct Obj00819 *)p)->fD8 = p + 0x124;
                    *state = 4;
                } else {
                    func_021D83C4((u32 *)(p + 0x124));
                    *(u8 * *)&((struct Obj00819 *)p)->fD8 = p + 0x124;
                    ((struct Obj00819 *)p)->fDC = 4;
                    *state = 4;
                }
            }
        } else {
            func_021D8434((u32 *)(p + 0x124));
            *(u8 * *)&((struct Obj00819 *)p)->fD8 = p + 0x124;
            ((struct Obj00819 *)p)->fDC = 4;
            *state = 4;
        }
        break;
    case 1:
        if (func_021CE08C(p) != 0) {
            func_021E9B14(((struct Obj00819 *)p)->f54);
            *state = 2;
        } else if (func_021E9B20(((struct Obj00819 *)p)->f54) != 0) {
            func_021D0B6C(p, p + 0x190);
            *state = 3;
        }
        break;
    case 2:
        if (func_021E9B20(((struct Obj00819 *)p)->f54) != 0) {
            func_021D0BB0(p);
            *state = 3;
        }
        break;
    case 3:
        func_021CE0E0(p);
        *state = 4;
        break;
    case 4:
        if (func_021B86C0(((struct Obj00819 *)p)->f0) != 0) {
            p[0x1A9] = 1;
            func_021EA7FC(((struct Obj00819 *)p)->f54);
            *state = 5;
        } else {
            *state = 6;
        }
        break;
    case 5:
        if (func_021EA814(((struct Obj00819 *)p)->f54) != 0) {
            *state = 6;
        }
        break;
    case 6:
        return 1;
    }
    return 0;
}





/*
 * extent: compiled 42 bytes followed by two zero alignment bytes.
 */
int func_021D102C(char *p)
{
    if (func_021B8588(((struct Obj13368 *)p)->f0) == 3 && func_021D5B68(func_021B9C00(((struct Obj13368 *)p)->f118, 0)) != 0) return 1;
    return 0;
}






int func_021D1058(u8 *s, void *q)
{
    int k;

    k = 2;
    if (func_021D5B68(func_021B9C00(((struct Obj13369 *)s)->f118, (u8)func_021B9AB0(2))) == 0) {
        func_021D83FC(q, k);
        return 4;
    }
    k = 3;
    if (func_021D5B68(func_021B9C00(((struct Obj13369 *)s)->f118, (u8)func_021B9AB0(3))) == 0) {
        func_021D83FC(q, k);
        return 4;
    }
    return 0;
}


int func_021D10B8(u8 *p, int *state)
{
    u8 *args;
    int choice;
    u8 count;
    switch (*state) {
    case 0:
        func_021EEC20(*(int *)(p + 0x50), &args);
        if (args[0] != 0x1F) {
            func_021EAF18((struct L *)(p + 0x58), 1, 0x14);
            func_021EAF50((struct L *)(p + 0x58), 1);
            func_021EAF50((struct L *)(p + 0x58), args[0]);
            func_021EAF78(p + 0x58, 0xFF);
            func_021EA614(*(void **)(p + 0x54), (struct H *)(p + 0x58));
            *state = 1;
        } else *state = 4;
        break;
    case 1:
        func_021EA710(*(void **)(p + 0x54));
        if (func_021EA720(*(void **)(p + 0x54)) != 0) {
            func_021EAF18((struct L *)(p + 0x58), 3, 6);
            func_021EAF18((struct L *)(p + 0x7C), 3, 7);
            func_021EABC4(*(void **)(p + 0x54), (u32)(p + 0x58), (u32)(p + 0x7C), 1);
            *state = 2;
        }
        break;
    case 2:
        if (func_021EA710(*(void **)(p + 0x54)) != 0) {
            if (func_021EAC54(*(void **)(p + 0x54), &choice) != 0) {
                if (choice == 0) {
                    func_021D0B10(p, 0, 1, p + 0x184, p + 0x190);
                    func_021E9A78(*(void **)(p + 0x54), p + 0x184, 0, 0, p + 0x190);
                    *state = 3;
                } else *state = 4;
            }
        }
        break;
    case 3:
        if (func_021E9B20(*(void **)(p + 0x54)) != 0) {
            if (func_021D121C(p + 0x190) == 0) {
                count = func_021D122C(p + 0x190);
                if (count != 0 && count < 6) {
                    func_021D8394(p + 0x124, 0, count);
                    *state = 5;
                } else {
invalid:
                    *state = 4;
                }
            } else goto invalid;
        }
        break;
    case 4:
        func_021D8434((u32 *)(p + 0x124));
        *state = 5;
    case 5:
        *(u8 **)(p + 0xD8) = p + 0x124;
        *(int *)(p + 0xDC) = 4;
        return 1;
    }
    return 0;
}










int func_021D123C(int a)
{
    u8 *tmp;
    int r4 = func_021EEC20(((struct Obj05203 *)a)->f50, &tmp);
    if (((struct Obj05203 *)a)->f10 != 0)
        func_021EE608((u8 *)(((struct Obj05203 *)a)->f10), (const u8 *)tmp, r4);
    if (((struct Obj05203 *)a)->fA0 != 0) {
        func_021BB4E0(((struct Obj05203 *)a)->fA0, (int)tmp, r4);
        ((struct Obj05203 *)a)->f1AE = func_021EE638((u8 *)tmp);
    }
    return 1;
}









/*
 * extent: compiled 18 bytes followed by two zero alignment bytes.
 * interface: r2 loads p+0x54 before bl; retained as third argument even where callee does not read it.
 */
int func_021D127C(u8 *p, int *state)
{
    void *q;
    q = ((struct Obj00066 *)p)->f54;
    if (q != 0) return func_021D1290(p, state, q);
    return 1;
}








/*
 * lever: the 0x1B2 bit5 test is a byte bitfield, not a shifted integer mask.
 */
int func_021D1290(u8 *p, int *state, void *a2)
{
    int idx;
    int mode;
    u8 flag;
    u16 msg;
    switch (*state) {
    case 0:
        if (((Flags *)p)->flag != 0)
            return 1;
        idx = func_021B904C(((struct Obj00066 *)p)->f0, 0);
        mode = func_021D13A4((BattleSeq_021D123C *)p);
        flag = func_021B86C8((unsigned char **)(*(u8 * *)&((struct Obj00066 *)p)->f0));
        func_021B916C(((struct Obj00066 *)p)->f0, mode);
        switch (mode) {
        case 1: msg = flag != 0 ? 0x31 : 0x30; break;
        case 0: msg = flag != 0 ? 0x33 : 0x32; break;
        case 2: msg = flag != 0 ? 0x35 : 0x34; break;
        default: return 1;
        }
        func_021EAF18((struct L *)(p + 0x58), 1, msg);
        func_021EAF50((struct L *)(p + 0x58), idx);
        if (flag != 0)
            func_021EAF50((struct L *)(p + 0x58), func_021B904C(((struct Obj00066 *)p)->f0, 1));
        func_021EA614(((struct Obj00066 *)p)->f54, (struct H *)(p + 0x58));
        if (mode == 1) {
            func_02005D90(func_021B86DC(((struct Obj00066 *)p)->f0), 0xFFFF);
            (*state)++;
        } else {
            func_02005E30(0x1E);
            *state += 2;
        }
        break;
    case 1:
        if (func_021EA710(((struct Obj00066 *)p)->f54) != 0)
            return 1;
        break;
    case 2:
        if (func_021EA710(((struct Obj00066 *)p)->f54) != 0)
            (*state)++;
        break;
    case 3:
        if (func_02005E50() == 0) {
            func_02005D28();
            return 1;
        }
        break;
    }
    return 0;
}








int func_021D13A4(BattleSeq_021D123C *s)
{
    u16 *q;

    func_021EEC20(((struct Obj00066 *)s)->f50, (u8 **)&q);
    switch (q[1]) {
    case 0:
        if (func_021B902C((u8)q[0], (u8)s->unk1A6) == 0)
            return 1;
        break;
    case 1:
        if (func_021B902C((u8)q[0], (u8)s->unk1A6) == 0)
            return 0;
        break;
    }
    return q[1];
}






int func_021D13FC(u8 *p, int *state)
{
    void *q;
    q = ((struct Obj00066 *)p)->f54;
    if (q != 0) return func_021D1410((BattleSeq_021D123C *)p, state, q);
    return 1;
}










int func_021D1410(BattleSeq_021D123C *s, int *state, void *q)
{
    int a;
    int b;

    switch (*state) {
    case 0:
        if (func_021D13A4(s) == 1) {
            func_021F878C(func_021B86DC(s->battle));
            a = func_021B904C(s->battle, 0);
            b = func_021B904C(s->battle, 1);
            if (a == b) {
                func_021EAF18((struct L *)s->msg, 1, 44);
                func_021EAF50((struct L *)s->msg, a);
            } else {
                func_021EAF18((struct L *)s->msg, 1, 45);
                func_021EAF50((struct L *)s->msg, a);
                func_021EAF50((struct L *)s->msg, b);
            }
            func_021EA614(s->msgWin, (struct H *)s->msg);
            *state = 1;
        } else if (func_021BA1A8(s->battle, 0x100) == 0) {
            a = func_021B8FF4(s->battle);
            func_021EAF18((struct L *)s->msg, 1, 54);
            func_021EAF50((struct L *)s->msg, a);
            func_021EAF50((struct L *)s->msg, a);
            func_021EA614(s->msgWin, (struct H *)s->msg);
            *state = 9;
        } else {
            return 1;
        }
        break;
    case 1:
        if (func_021EA710(s->msgWin)) {
            a = func_021B904C(s->battle, 0);
            func_021F7F58(func_021BA020(s->battle, a), 9, 0, 0, 0);
            func_021F7998(0x270);
            *state = 2;
        }
        break;
    case 2:
        if (func_021F7EB4() == 0) {
            a = func_021B904C(s->battle, 0);
            func_021EA6B0(s->msgWin, func_021BA004(s->battle, a), 1);
            *state = 3;
        }
        break;
    case 3:
        if (func_021EA710(s->msgWin)) {
            a = func_021B904C(s->battle, 0);
            if (a != func_021B904C(s->battle, 1)) {
                func_021F7998(0x271);
                *state = 4;
            } else {
                *state = 7;
            }
        }
        break;
    case 4:
        if (func_021F7EB4() == 0) {
            a = func_021B904C(s->battle, 1);
            func_021F7F58(func_021BA020(s->battle, a), 9, 0, 0, 0);
            func_021F7998(0x270);
            *state = 5;
        }
        break;
    case 5:
        if (func_021F7EB4() == 0) {
            a = func_021B904C(s->battle, 1);
            func_021EA6B0(s->msgWin, func_021BA004(s->battle, a), 1);
            *state = 6;
        }
        break;
    case 6:
        if (func_021EA710(s->msgWin))
            *state = 7;
        break;
    case 7:
        a = func_021B919C(s->battle);
        if (a) {
            b = func_021B8FF4(s->battle);
            func_021EAF18((struct L *)s->msg, 1, 58);
            func_021EAF50((struct L *)s->msg, b);
            func_021EAF50((struct L *)s->msg, a);
            func_021EA614(s->msgWin, (struct H *)s->msg);
        }
        if (func_021B9210(s->battle) == 0)
            *state = 11;
        else
            *state = 8;
        break;
    case 8:
        if (func_021EA710(s->msgWin)) {
            a = func_021B9210(s->battle);
            if (a) {
                b = func_021B8FF4(s->battle);
                func_021EAF18((struct L *)s->msg, 1, 59);
                func_021EAF50((struct L *)s->msg, b);
                func_021EAF50((struct L *)s->msg, a);
                func_021EA614(s->msgWin, (struct H *)s->msg);
            }
            *state = 11;
        }
        break;
    case 9:
        if (func_021EA710(s->msgWin)) {
            a = func_021B9244(s->battle);
            if (a) {
                func_021EAF18((struct L *)s->msg, 1, 56);
                func_021EAF50((struct L *)s->msg, s->unk1A6);
                func_021EAF50((struct L *)s->msg, a);
                func_021EA614(s->msgWin, (struct H *)s->msg);
            }
            *state = 10;
        }
        break;
    case 10:
        if (func_021EA710(s->msgWin)) {
            func_021EAF18((struct L *)s->msg, 1, 57);
            func_021EAF50((struct L *)s->msg, s->unk1A6);
            func_021EA614(s->msgWin, (struct H *)s->msg);
            *state = 11;
        }
        break;
    case 11:
        if (func_021EA710(s->msgWin))
            return 1;
        break;
    default:
        return 1;
    }
    return 0;
}










/*
 * extent: compiled 18 bytes followed by two zero alignment bytes.
 * interface: r2 loads p+0x54 before bl; retained as third argument even where callee does not read it.
 */
int func_021D1708(u8 *p, int *state)
{
    void *q;
    q = ((struct Obj00066 *)p)->f54;
    if (q != 0) return func_021D171C(p, state, q);
    return 1;
}










/*
 * lever: the 0x1B2 bit5 test is a byte bitfield, preserving the shift pair.
 */
int func_021D171C(u8 *p, int *state, void *a2)
{
    u32 mode;
    int idx;
    switch (*state) {
    case 0:
        if (((Flags_021D1410 *)p)->flag != 0) return 1;
        mode = func_021D13A4((BattleSeq_021D123C *)p);
        func_021B916C(((struct Obj00066 *)p)->f0, mode);
        if (mode == 1) func_021F878C(func_021B86DC(((struct Obj00066 *)p)->f0));
        if (mode <= 1) {
            idx = func_021B904C(((struct Obj00066 *)p)->f0, 0);
            func_021F7F58(func_021BA020(((struct Obj00066 *)p)->f0, idx), 9, 0, 0, 0);
            func_021F7998(0x270);
            func_021D185C((BattleSeq_021D123C *)p, mode, 0);
            *state = 1;
        } else return 1;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021EA600(((struct Obj00066 *)p)->f54);
            *state = 2;
        }
        break;
    case 2:
        if (func_021EA710(((struct Obj00066 *)p)->f54) != 0) {
            idx = func_021B904C(((struct Obj00066 *)p)->f0, 0);
            if (idx == func_021B904C(((struct Obj00066 *)p)->f0, 1)) return 1;
            func_021F7998(0x271);
            *state = 3;
        }
        break;
    case 3:
        if (func_021F7EB4() == 0) {
            mode = func_021D13A4((BattleSeq_021D123C *)p);
            idx = func_021B904C(((struct Obj00066 *)p)->f0, 1);
            func_021F7F58(func_021BA020(((struct Obj00066 *)p)->f0, idx), 9, 0, 0, 0);
            func_021F7998(0x270);
            func_021D185C((BattleSeq_021D123C *)p, mode, 1);
            *state = 4;
        }
        break;
    case 4:
        if (func_021F7EB4() == 0) {
            func_021EA600(((struct Obj00066 *)p)->f54);
            *state = 5;
        }
        break;
    case 5:
        if (func_021EA710(((struct Obj00066 *)p)->f54) != 0) return 1;
        break;
    }
    return 0;
}










/*
 * Verified C for it (match.py one --thumb, no --region, EXACT, 20 bytes):
 *   int func_02024450(u16 *p) { return *p != 0xffff; }
 */
void func_021D185C(BattleSeq_021D123C *s, int a, int b)
{
    int idx;
    void *p;
    void *r;
    int v;

    idx = func_021B904C(s->battle, b);
    p = func_021BA02C(s->battle, idx, a);
    if (p != 0 && func_02024450(p) != 0) {
        r = func_0202435C(p, (u16)((*(u16 *)((u8 *)s + 0x19a) & 0x7fff) | 0x8000));
        func_021EA5E4(s->msgWin, r);
        sub_02045808(r);
        return;
    }
    v = func_021BA004(s->battle, idx);
    if (v != 0) {
        func_021EAF18((struct L *)s->msg, 7, (int)0);
        func_021EAF50((struct L *)s->msg, (int)v);
        func_021EAF50((struct L *)s->msg, (int)a);
        func_021EA5F0(s->msgWin, (struct H *)s->msg);
    }
}










int func_021D18EC(BattleSeq_021D123C *s, int *state)
{
    int a;
    int b;

    switch (*state) {
    case 0:
        if (func_021BA1A8(s->battle, 0x200) == 0) {
            a = func_021B9210(s->battle);
            if (a != 0) {
                b = func_021B8FF4(s->battle);
                func_021EAF18((struct L *)s->msg, 1, 0x3b);
                func_021EAF50((struct L *)s->msg, b);
                func_021EAF50((struct L *)s->msg, a);
                func_021EA614(s->msgWin, (struct H *)s->msg);
            }
        }
        (*state)++;
    case 1:
        if (func_021EA710(s->msgWin) != 0)
            return 1;
        break;
    }
    return 0;
}










int func_021D1960(BattleSeq_021D123C *s, int *state)
{
    int a;

    switch (*state) {
    case 0:
        func_021EAF18((struct L *)s->msg, 1, 0x36);
        func_021EAF50((struct L *)s->msg, s->unk1A6);
        func_021EA614(s->msgWin, (struct H *)s->msg);
        (*state)++;
        break;
    case 1:
        if (func_021EA710(s->msgWin) != 0) {
            a = func_021B9244(s->battle);
            if (a != 0) {
                func_021EAF18((struct L *)s->msg, 1, 0x37);
                func_021EAF50((struct L *)s->msg, s->unk1A6);
                func_021EAF50((struct L *)s->msg, a);
                func_021EA614(s->msgWin, (struct H *)s->msg);
            }
            (*state)++;
        }
        break;
    case 2:
        if (func_021EA710(s->msgWin) != 0) {
            func_021EAF18((struct L *)s->msg, 1, 0x39);
            func_021EAF50((struct L *)s->msg, s->unk1A6);
            func_021EA614(s->msgWin, (struct H *)s->msg);
            (*state)++;
        }
        break;
    case 3:
        if (func_021EA710(s->msgWin) != 0)
            (*state)++;
        break;
    default:
        return 1;
    }
    return 0;
}










int func_021D1A18(BattleSeq_021D123C *s, int *state)
{
    switch (*state) {
    case 0:
        func_021EAF18((struct L *)s->msg, 1, 0xb7);
        func_021EA614(s->msgWin, (struct H *)s->msg);
        (*state)++;
        break;
    case 1:
        if (func_021EA710(s->msgWin) != 0)
            (*state)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}








int func_021D1A60(u8 *p, int *state)
{
    void *q;
    q = ((struct Obj01237 *)p)->f54;
    if (q != 0) return func_021D1A74(p, state, q);
    return 1;
}








int func_021D1A74(u8 *p, int *state, void *a2)
{
    u8 *args;
    int size;
    u16 len;
    Buf *buf;
    u32 i;
    int code;
again:
    switch (*state) {
    case 0:
        size = func_021EEC20(((struct Obj01237 *)p)->f50, &args);
        if (*(u8 * *)&((struct Obj01237 *)p)->fA0 != 0 && p[0x1AE] != 0 && ((Flags_021D1A60 *)p)->flag != 0) {
            if (func_021BB570(*(u8 * *)&((struct Obj01237 *)p)->fA0, p[0x1AE], args, size) != 0) {
                func_021B9184(((struct Obj01237 *)p)->f0);
                ((Flags_021D1A60 *)p)->flag = 0;
            }
            p[0x1AE] = 0;
        }
        buf = *(Buf * *)&((struct Obj01237 *)p)->f134;
        len = size;
        func_02082A90(args, buf + 1, len);
        buf->wpos = len;
        buf->rpos = 0;
        if (p[0x1A9] != 0) {
            p[0x1A9] = 0;
            func_021EA824(((struct Obj01237 *)p)->f54);
        }
        (*state)++;
    case 1:
        buf = *(Buf * *)&((struct Obj01237 *)p)->f134;
        if (buf->rpos == buf->wpos) {
            *state = 4;
            return 1;
        }
        if (func_021D3F4C(p + 0x18) != 0) return 1;
        (*state)++;
    case 2:
        code = func_021CD5E0(*(Buf * *)&((struct Obj01237 *)p)->f134, (int *)(p + 0x138));
        ((struct Obj01237 *)p)->f178 = code;
        if (code == 0x5E) return 1;
        for (i = 0; i < 0x5D; i++) {
            if (code == d_021F00DC[i].code) break;
        }
        if (i == 0x5D) {
            *state = 1;
            goto again;
        }
        *(Callback *)&((struct Obj01237 *)p)->f17C = d_021F00DC[i].fn;
        ((struct Obj01237 *)p)->f180 = 0;
        (*state)++;
    case 3:
        if ((*(Callback *)(p + 0x17C))(p, (int *)(p + 0x180), (int *)(p + 0x138)) != 0) {
            *state = 1;
            goto again;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}







int func_021D1BD0(BattleSeq_021D123C *s, int *state, int *pp)
{
    int t;

    switch (*state) {
    case 0:
        func_021EAF18((struct L *)s->msg, 1, func_021D1C40(s, pp[0], &t));
        if (t != 0)
            func_021EAF50((struct L *)s->msg, pp[0]);
        func_021EAF50((struct L *)s->msg, pp[1]);
        func_021EA614(s->msgWin, (struct H *)s->msg);
        (*state)++;
        break;
    case 1:
        if (func_021EA710(s->msgWin) != 0)
            return 1;
        break;
    }
    return 0;
}










int func_021D1C40(BattleSeq_021D123C *s, u8 x, int *out)
{
    u32 v;

    if (x == s->unk1A6) {
        *out = 0;
        if (func_021B8588(s->battle) == 0 && func_021B86C0(s->battle) == 0) {
            v = func_021CDEE8((u8 *)s);
            if (v >= 0x4b)
                return 0x1d;
            if (v > 0x32)
                return 0x1c;
            if (v > 0x19)
                return 0x1b;
            if (v != 0)
                return 0x1a;
            return 0x19;
        }
        return 0x1a;
    }
    *out = 1;
    if (func_021B9F70(s->battle, x) != 0)
        return 0x1e;
    return 0x1f;
}










int func_021D1CAC(BattleSeq_021D123C *s, int *state, int *pp)
{
    switch (*state) {
    case 0:
        func_021EA458(s->msgWin, func_021B8E70(s->battle, (u8)pp[0]), (u16)pp[1]);
        (*state)++;
        break;
    case 1:
        if (func_021EA478(s->msgWin) != 0)
            return 1;
        break;
    }
    return 0;
}








static inline void message(u8 *p, int code, u32 value, u32 id)
{
    func_021EAF18((struct L *)(p + 0x58), 1, code);
    func_021EAF50((struct L *)(p + 0x58), value);
    func_021EAF50((struct L *)(p + 0x58), id);
    func_021EA614(((struct Obj21146 *)p)->f54, (struct H *)(p + 0x58));
}








/*
 * lever: append-id and send are written in every message arm; the inline
 * helper includes that tail. Factoring it outside the conditional merges
 * the initialisation call too early and loses 16 bytes.
 */
int func_021D1CF4(u8 *p, int *state, const u32 *params)
{
    u8 a = params[0];
    u8 b = params[1];
    u8 flag = params[3];
    u8 id;
    switch (*state) {
    case 0:
        if (flag != 0) {
            id = func_021D5440(func_021B9920(((struct Obj01691 *)p)->f4, a, b));
            if (func_021B8CE8((int)(((struct Obj01691 *)p)->f0), p[0x1A6], a) == 0) {
                if (p[0x1A6] == a) {
                    func_021EAF18((struct L *)(p + 0x58), 1, func_021D1DF4((BattleSeq_021D123C *)p));
                    func_021EAF50((struct L *)(p + 0x58), id);
                    func_021EA614(((struct Obj01691 *)p)->f54, (struct H *)(p + 0x58));
                } else {
                    message(p, 0x11, a, id);
                }
            } else if (func_021B9F70(((struct Obj01691 *)p)->f0, a) != 0) {
                message(p, 0xE, a, id);
            } else {
                message(p, 0x11, a, id);
            }
        }
        (*state)++;
        break;
    case 1:
        if (func_021EA710(((struct Obj01691 *)p)->f54) != 0) {
            func_021EA488(((struct Obj01691 *)p)->f54, func_021B8BEC(*(u8 * *)&((struct Obj01691 *)p)->f0, a, b), a, b);
            (*state)++;
        }
        break;
    case 2:
        if (func_021EA4C4(((struct Obj01691 *)p)->f54) != 0) {
            func_021CDECC(p);
            return 1;
        }
        break;
    }
    return 0;
}








int func_021D1DF4(BattleSeq_021D123C *s)
{
    u8 *m;
    u8 t;
    int v;

    if (func_021B8588(s->battle) == 0) {
        t = func_021B9064(s->battle, s->unk1A6, 0);
        m = func_021B9920(s->unk04, t, 0);
        if (func_021D5B68(m) != 0)
            return 0xb;
        v = func_021D5C44((struct Rat *)m);
        if (v >= 0x4d800)
            return 0xb;
        if (v >= 0x37000)
            return 0x15;
        if (v >= 0x20800)
            return 0x16;
        if (v >= 0xa000)
            return 0x17;
        return 0x18;
    }
    return 0xb;
}








int func_021D1E6C(Seq_021D123C *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        func_021EA678(s->win, a[0], (int *)(a + 1));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}








int func_021D1EB4(Seq_021D123C *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        func_021EA678(s->win, a[0], (int *)(a + 2));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA720(s->win)) {
            func_020061E4(a[1]);
        }
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}








int func_021D1F10(Seq_021D123C *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        func_021EA694(s->win, a[0], (int *)(a + 1));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}








int func_021D1F58(Seq_021D123C *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        func_021EA694(s->win, a[0], (int *)(a + 2));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA720(s->win)) {
            func_020061E4(a[1]);
        }
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}







int func_021D1FB4(Seq_021D123C *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        func_021EA6F4(s->win, a[0], a[1]);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}







/*
 * Unlabelled leaf (filed for the blocker of func_021D2030, lane S15).
 */
u32 func_021D2000(Seq_021D2030 *p, u32 k, u8 b)
{
    u8 *r;

    if (k != 0xAE) {
        return func_0201BD28(k, 0x1B);
    }
    r = func_021B98AC((char *const *)p->unk04, b);
    if (r) {
        return func_021D80A8(r);
    }
    return func_0201BD28(k, 0x1B);
}








/*
 * lever: word locals with casts at the four descriptor loads, t2 before v
 * in declaration order, and a named nested-call result keep v in r7 and
 * t1/t2 in the original spill slots. The u8 b in the callee's own source
 * is widened here: the original caller has no second truncation after v.
 */
int func_021D2030(Seq_021D2030 *s, int *state, const u32 *a)
{
    u32 t2;
    u8 v;
    u32 t1;
    u32 t3;
    u32 result;
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        if (func_021B8590((unsigned char *)s->unk00)) {
            v = (u8)a[0];
            t1 = (u8)a[1];
            t2 = (u16)a[2];
            t3 = (u8)a[3];
            result = func_021D2000(s, t2, v);
            func_021EA0A0(s->win, v, t1, t2, result, t3, 0);
            *state = *state + 1;
        } else {
            return 1;
        }
        break;
    case 1:
        if (func_021EA0E4(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D20BC(Seq_021D20BC *s, int *state, u32 *a)
{
    u32 t;

    switch (*state) {
    case 0:
        t = (u32)func_021B8DC0((unsigned char *)s->unk00, (void *)s->unk04, (u8)a[0]);
        func_021EA354(s->win, t, a[1] != 0);
        *state = *state + 1;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            return 1;
        }
        return 0;
    }
    return 0;
}









int func_021D210C(Seq_021D210C *s, int *state, u32 *a)
{
    int t;

    switch (*state) {
    case 0:
        t = func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
        func_021EA0F4(s->win, (u16)a[2], t, (u8)a[1]);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA120(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D215C(Seq_021D215C *s, int *state, u32 *a)
{
    u8 buf[8];
    u8 i;
    u16 n;
    u32 p1;
    u16 p2;

    switch (*state) {
    case 0:
        n = a[0];
        p1 = a[1];
        p2 = a[2];
        for (i = 0; i < n; i++) {
            buf[i] = func_021CD644((u8 *)s->unk134);
        }
        func_021EA280(s->win, n, p1, buf, p2);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA2BC(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D21D4(Seq_021D21D4 *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        func_021EA384(s->win, func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA3A0(s->win)) {
            func_021EA678(s->win, 0x61, (int *)a);
            *state = *state + 1;
        }
        break;
    case 2:
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D2234(Seq_021D2234 *s, int *state, u32 *a)
{
    int t;

    switch (*state) {
    case 0:
        t = func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
        func_021F81D0(a[1], func_021B8E70((u8 *)s->unk00, t));
        *state = *state + 1;
        break;
    case 1:
        return 1;
    }
    return 0;
}








int func_021D2278(Seq_021D2030 *s, int *state, u32 *a)
{
    int t;

    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s) == 0) {
            t = func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
            func_021EA0A0(s->win, t, t, 1, func_0201BD28(1, 0x1B), 0, 0);
        }
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA0E4(s->win)) {
            t = func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
            if (func_021CD9E0((u8 *)s) == 0) {
                func_020061E4(0x564);
            }
            func_021EA0F4(s->win, 1, t, 1);
            *state = *state + 1;
        }
        break;
    case 2:
        if (func_021EA120(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}








int func_021D2320(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021EA40C(((struct Obj06240 *)p)->f54, func_021B8D8C(((struct Obj06240 *)p)->f0, ((struct Obj06240 *)p)->f4, (u8)(*c)));
        (*st)++;
        break;
    case 1:
        if (func_021EA428(((struct Obj06240 *)p)->f54)) {
            func_021D646C(func_021B9934(((struct Obj06240 *)p)->f4, (u8)(*c)));
            return 1;
        }
        break;
    }
    return 0;
}








int func_021D2374(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021EA438(((struct Obj07782 *)p)->f54, func_021B8D8C(((struct Obj07782 *)p)->f0, ((struct Obj07782 *)p)->f4, (u8)(*c)));
        (*st)++;
        break;
    case 1:
        if (func_021EA448(((struct Obj07782 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}








int func_021D23B8(u8 *p, int *st, u32 *c)
{
    u32 t = func_021B8E70(((struct Obj05206 *)p)->f0, func_021B8D8C(((struct Obj05206 *)p)->f0, ((struct Obj05206 *)p)->f4, (u8)(*c)));

    switch (*st) {
    case 0:
        if (func_021CD9E0(p))
            return 1;
        if (!func_021B8590(((struct Obj05206 *)p)->f0))
            return 1;
        func_021EA7C8(((struct Obj05206 *)p)->f54, t);
        (*st)++;
        break;
    case 1:
        if (func_021EA7E8(((struct Obj05206 *)p)->f54, t))
            return 1;
        break;
    }
    return 0;
}








int func_021D2424(u8 *p, int *st, u32 *c)
{
    u32 t = func_021B8E70(((struct Obj05207 *)p)->f0, func_021B8D8C(((struct Obj05207 *)p)->f0, ((struct Obj05207 *)p)->f4, (u8)(*c)));

    switch (*st) {
    case 0:
        if (func_021CD9E0(p))
            return 1;
        if (!func_021B8590(((struct Obj05207 *)p)->f0))
            return 1;
        func_021EA7D8(((struct Obj05207 *)p)->f54, t);
        (*st)++;
        break;
    case 1:
        if (func_021EA7E8(((struct Obj05207 *)p)->f54, t))
            return 1;
        break;
    }
    return 0;
}








int func_021D2490(u8 *p, int *st, u32 *c)
{
    u8 id = c[0];

    switch (*st) {
    case 0:
        func_021EF9C0(((struct Obj10019 *)p)->f34, (u8)id, (u16)c[1]);
        if (func_021CD9E0(p))
            return 1;
        if (id < 5)
            func_021F7998(d_021EFFAE[id].b);
        (*st)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            func_021EA678(((struct Obj10019 *)p)->f54, d_021EFFAE[id].a, 0);
            (*st)++;
        }
        break;
    case 2:
        if (func_021EA710(((struct Obj10019 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}








int func_021D2510(u8 *p, int *st, u32 *c)
{
    u16 v;

    switch (*st) {
    case 0:
        switch ((u8)c[0]) {
        case 1:
            v = 0x59;
            break;
        case 2:
            v = 0x5a;
            break;
        case 4:
            v = 0x5b;
            break;
        case 3:
            v = 0x5c;
            break;
        default:
            return 1;
        }
        func_021EA678(((struct Obj10021 *)p)->f54, v, 0);
        (*st)++;
        break;
    case 1:
        if (func_021EA710(((struct Obj10021 *)p)->f54)) {
            func_021EF9C8(((struct Obj10021 *)p)->f34);
            return 1;
        }
        break;
    }
    return 0;
}








int func_021D2580(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021EA384(((struct Obj07783 *)p)->f54, func_021B8D8C(((struct Obj07783 *)p)->f0, ((struct Obj07783 *)p)->f4, (u8)(*c)));
        (*st)++;
        break;
    case 1:
        if (func_021EA3A0(((struct Obj07783 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}








int func_021D25C4(u8 *p, int *st, u32 *c)
{
    int t = func_021B8D8C(((struct Obj06241 *)p)->f0, ((struct Obj06241 *)p)->f4, (u8)(*c));

    switch (*st) {
    case 0:
        if (func_021CD9E0(p))
            return 1;
        if (!func_021B8590(((struct Obj06241 *)p)->f0))
            return 1;
        func_021EA838(((struct Obj06241 *)p)->f54, t);
        (*st)++;
        break;
    case 1:
        if (func_021EA850(((struct Obj06241 *)p)->f54, t))
            return 1;
        break;
    }
    return 0;
}








int func_021D2628(u8 *p, int *st, u32 *c)
{
    u8 id = *c;

    switch (*st) {
    case 0:
        func_021EA384(((struct Obj07784 *)p)->f54, func_021B8D8C(((struct Obj07784 *)p)->f0, ((struct Obj07784 *)p)->f4, id));
        (*st)++;
        break;
    case 1:
        if (func_021EA3A0(((struct Obj07784 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}








int func_021D266C(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0: {
        u8 a = c[0];
        u32 b = (u8)c[1];
        u32 d = (u8)c[2];
        int x = func_021B8DEC(((struct Obj04364 *)p)->f0, b);
        int y = func_021B8DEC(((struct Obj04364 *)p)->f0, d);
        u32 m = func_021B8E70(((struct Obj04364 *)p)->f0, b);
        u32 n = func_021B8E70(((struct Obj04364 *)p)->f0, d);
        func_021B9C10((u32 *)func_021B9AEC(((struct Obj04364 *)p)->f4, a), x, y);
        func_021EA904(((struct Obj04364 *)p)->f54, a, m, n, x, y);
        (*st)++;
        break;
    }
    case 1:
        if (func_021EA950(((struct Obj04364 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}







int func_021D2700(u32 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021F7998(0x281);
        (*st)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            u8 a = c[0], b = c[1];
            u32 x, y, v, w;
            x = func_021B8BEC((u8 *)p[0], a, b);
            y = func_021B8BEC((u8 *)p[0], a, 1);
            v = func_021B8E70((u8 *)p[0], x);
            w = func_021B8E70((u8 *)p[0], y);
            func_021B9C10((u32 *)func_021B9AEC((char *)p[1], a), b, 1);
            func_021EA904((u32 *)p[21], a, v, w, b, 1);
            (*st)++;
        }
        break;
    case 2:
        if (func_021EA950((void *)p[21])) {
            u8 a = c[2], b = c[3];
            u32 x, y, v, w;
            x = func_021B8BEC((u8 *)p[0], a, b);
            y = func_021B8BEC((u8 *)p[0], a, 1);
            v = func_021B8E70((u8 *)p[0], x);
            w = func_021B8E70((u8 *)p[0], y);
            func_021B9C10((u32 *)func_021B9AEC((char *)p[1], a), b, 1);
            func_021EA904((u32 *)p[21], a, v, w, b, 1);
            (*st)++;
        }
        break;
    case 3:
        if (func_021EA950((void *)p[21])) return 1;
        break;
    }
    return 0;
}







/*
 * evidence: Thumb 01 49 02 4b 18 47 c0 46; pools 0x26e and 0x021F7A29. No ARM9/SDK blocker work.
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Callee 0x021F7E94 is an ov094 Thumb tail stub (pool 0x26E, 0x021F7A29); other overlay, not filed. Integrator: seed label.
 */
int func_021D2814(char *p, int *state, unsigned int *q)
{
    switch (*state) {
    case 0:
        func_021F7E94((u8)func_021B8E70(*(void **)p, (u8)q[0]));
        (*state)++;
        break;
    case 1:
        if (func_021F7EB4() == 0) return 1;
        break;
    }
    return 0;
}








int func_021D284C(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0: {
        u32 t = func_021B8E70(((struct Obj21158 *)p)->f0, (u8)(*c));
        if (func_021CD9E0(p))
            func_021F88BC(1);
        func_021F7EA4(t);
        (*st)++;
        break;
    }
    case 1:
        if (!func_021F7EB4()) {
            if (func_021CD9E0(p))
                func_021F88BC(0);
            return 1;
        }
        break;
    }
    return 0;
}








int func_021D28AC(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0: {
        u8 *a = func_021B9934(*(char * *)&((struct Obj03693 *)p)->f4, (u8)c[0]);
        u8 *b = func_021B9934(*(char * *)&((struct Obj03693 *)p)->f4, (u8)c[1]);
        int d = (int)func_021B8DC0(((struct Obj03693 *)p)->f0, ((struct Obj03693 *)p)->f4, (u8)c[0]);
        int e = (int)func_021B8DC0(((struct Obj03693 *)p)->f0, ((struct Obj03693 *)p)->f4, (u8)c[1]);
        func_021D6C50((struct Unk021D6C50 *)a, (struct Unk021D6C50 *)b);
        func_021EA8B4(((struct Obj03693 *)p)->f54, d, e);
        (*st)++;
        break;
    }
    case 1:
        if (func_021EA8D4(((struct Obj03693 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}







int func_021D2930(u32 *a, int *b, u32 *c)
{
    int t;

    switch (*b) {
    case 0:
        if (func_021CD9E0((u8 *)a) == 0) {
            t = func_021B8D8C((void *)a[0], (void *)a[1], (u8)c[0]);
            func_021EA1B8((struct S *)a[0x15], (u16)c[2], t, func_021D7AD4(c[1]));
            (*b)++;
            break;
        }
        return 1;
    case 1:
        if (func_021EA1F0((struct S *)a[0x15]) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}







int func_021D2990(int a, int b, int *c)
{
    func_021F878C(*c);
    return 1;
}






int func_021D299C(char *p, int *state)
{
    switch (*state) {
    case 0:
        func_021EA8E4(((struct Obj13398 *)p)->f54);
        (*state)++;
        break;
    case 1:
        if (func_021EA8F4(((struct Obj13398 *)p)->f54) != 0) return 1;
        break;
    }
    return 0;
}






int func_021D29CC(u32 *a, int b, u32 *c)
{
    void *m;
    u32 i;
    int k;
    u32 v;

    m = func_021D5844(func_021B9934((char *)a[1], (u8)c[0]));
    for (i = 0; i < 6; i++) {
        if (d_021EFF88[i + 1] != 0) {
            k = d_021EFF88[i];
            v = c[i + 1] + func_02017E1C(m, k, 0);
            if (v > 0xff) {
                v = 0xff;
            }
            func_02017E40(m, k, v);
        }
    }
    return 1;
}





/*
 * evidence: 43/43 relocations resolved after parent-coordinated overlay
 * leaf witnesses; all ARM9 calls resolve without new ARM9 files.
 * lever: int id loaded via (u8) cast fixes spill slots; widening the
 * func_021B8DC0 third extern parameter removes absent call truncation.
 * StateData fields keep counter updates on one global base.
 */
int func_021D2A20(u8 *p, int *state, u32 *args)
{
    void *obj;
    int id;
    int index;
    int enabled;
    u32 remaining;
    id = (u8)args[0];
    obj = func_021B9934(*(char * *)&((struct Obj00268 *)p)->f4, id);
    index = func_021B8DC0(((struct Obj00268 *)p)->f0, ((struct Obj00268 *)p)->f4, id);
    enabled = 0;
    if (index != 0xff && func_021F8204(index)) enabled = 1;
    switch (*state) {
    case 0:
        d_021F3B64.s.remaining = args[1];
        d_021F3B64.s.counter = 0;
        *state = 1;
    case 1:
        if (d_021F3B64.s.remaining) {
            remaining = d_021F3B64.s.remaining;
            if (func_021D69B8(obj, &remaining, (struct Result *)d_021F3B64.s.result)) {
                *state = 3;
            } else {
                if (enabled) {
                    func_021F8134(index, d_021F3B64.s.remaining);
                    *state = 2;
                } else *state = 13;
                remaining = 0;
            }
            d_021F3B64.s.remaining = remaining;
        } else *state = 13;
        break;
    case 2:
        if (!func_021F8180()) *state = 13;
        break;
    case 3:
        func_021D6EA0(obj);
        func_021D6BFC(obj);
        if (enabled) {
            func_021F8150(index, obj);
            *state = 4;
        } else *state = 6;
        break;
    case 4:
        if (!func_021F8180() && !func_02006238()) {
            func_021EA3B8(((struct Obj00268 *)p)->f54, index, 0x25d);
            *state = 5;
        }
        break;
    case 5:
        if (func_021EA3D4(((struct Obj00268 *)p)->f54)) *state = 6;
        break;
    case 6:
        func_021EAF18((struct L *)(p + 0x58), 1, 0x3c);
        func_021EAF50((struct L *)(p + 0x58), (int)id);
        func_021EAF50((struct L *)(p + 0x58), (int)d_021F3B64.s.result[0]);
        func_021EA614(((struct Obj00268 *)p)->f54, (struct H *)(p + 0x58));
        *state = 7;
        break;
    case 7:
        if (func_021EA720(((struct Obj00268 *)p)->f54)) {
            func_02005DE4((void *)1);
            func_02005E64();
            func_02005D90(0x515, 0xffff);
        }
        if (func_021EA710(((struct Obj00268 *)p)->f54) && !func_02005F38()) {
            func_02005E9C();
            func_02005DE4(0);
            d_021F3B64.s.counter = 0;
            *state = 8;
        }
        break;
    case 8:
        d_021F3B64.s.counter++;
        if ((func_020362DC() & 3) || func_02035C60() || d_021F3B64.s.counter > 80) {
            d_021F3B64.s.counter = 0;
            func_021BA238(((struct Obj00268 *)p)->f0, obj);
            func_021EADA4(*(u8 * *)&((struct Obj00268 *)p)->f54, (int)obj, (struct T *)d_021F3B64.s.result);
            *state = 9;
        }
        break;
    case 9:
        if (func_021EADB4(((struct Obj00268 *)p)->f54) && ((func_020362DC() & 3) || func_02035C60())) {
            func_021EADC4(((struct Obj00268 *)p)->f54);
            *state = 10;
        }
        break;
    case 10:
        if (func_021EADD4(((struct Obj00268 *)p)->f54) && ((func_020362DC() & 3) || func_02035C60())) {
            func_021EADE4(((struct Obj00268 *)p)->f54);
            *state = 11;
        }
        break;
    case 11:
        if (func_021EADF4(((struct Obj00268 *)p)->f54)) {
            d_021F3B64.s.counter = 0;
            *state = 12;
        }
        break;
    case 12:
        if (func_021D2CA8((LearnSeq_021D2C7C *)p, &d_021F3B64.s.counter, obj)) *state = 1;
        break;
    case 13:
        func_021B9358(((struct Obj00268 *)p)->f0, id);
        return 1;
    }
    return 0;
}




int func_021D2C7C(int n)
{
    switch (n) {
    case 3:
        func_020061E4(0x56b);
        break;
    case 5:
        if (func_02006254(0x56b) != 0) return 1;
        break;
    }
    return 0;
}





int func_021D2CA8(LearnSeq_021D2C7C *s, int *state, void *mon)
{
    int idx = func_021D5440(mon);

    switch (*state) {
    case 0:
        g_021F3B64.iter = 0;
        g_021F3B64.move = 0;
        *state = 1;
    case 1:
        g_021F3B64.move = func_02018328(func_021D5844(mon), &g_021F3B64.iter, s->level);
        if (g_021F3B64.move == 0)
            return 1;
        if (g_021F3B64.move == 0xFFFE)
            break;
        if (g_021F3B64.move & 0x8000) {
            g_021F3B64.move &= 0x7FFF;
            *state = 5;
        } else {
            *state = 2;
        }
        break;
    case 2: {
        void *p = func_021B9934(s->party, idx);
        func_021D5844(p);
        func_021D6BFC(p);
        func_021EAF18((struct L *)(&s->msg), 5, 3);
        func_021EAF50((struct L *)(&s->msg), idx);
        func_021EAF50((struct L *)(&s->msg), g_021F3B64.move);
        func_021EA614(s->msgWin, (struct H *)(&s->msg));
        *state = 3;
    }
    case 3:
        if (func_021EA720(s->msgWin)) {
            func_02005DE4((void *)1);
            func_02005E64();
            func_02005D90(0x515, 0xFFFF);
        }
        if (func_021EA710(s->msgWin))
            *state = 4;
        break;
    case 4:
        if (func_02005F38() == 0) {
            func_02005E9C();
            func_02005DE4(0);
            *state = 1;
        }
        break;
    case 5:
        func_021EAF18((struct L *)(&s->msg), 5, 4);
        func_021EAF50((struct L *)(&s->msg), idx);
        func_021EAF50((struct L *)(&s->msg), g_021F3B64.move);
        func_021EAF78((u8 *)(&s->msg), 255);
        func_021EA614(s->msgWin, (struct H *)(&s->msg));
        *state = 6;
    case 6:
        if (func_021EA720(s->msgWin)) {
            MsgParam yes, no;
            func_021EAF18((struct L *)(&yes), 6, 2);
            func_021EAF18((struct L *)(&no), 6, 3);
            func_021EABC4(s->msgWin, (u32)(&yes), (u32)(&no), 1);
        }
        if (func_021EA710(s->msgWin))
            *state = 7;
        break;
    case 7: {
        int sel;
        if (func_021EAC54(s->msgWin, &sel)) {
            if (sel == 0) {
                func_021EAC64(s->msgWin, func_021B9CBC((u8 *)func_021B9AF8(s->party, s->side), idx), g_021F3B64.move);
                *state = 8;
            } else {
                *state = 10;
            }
        }
        break;
    }
    case 8: {
        u8 slot;
        void *pp;
        u16 old;
        if (func_021EAC80(s->msgWin, &slot) == 0)
            break;
        if (slot == 4) {
            *state = 5;
            break;
        }
        pp = func_021D5844(func_021B9934(s->party, idx));
        old = func_02017E1C(pp, slot + 54, 0);
        func_020181F4(pp, g_021F3B64.move, slot);
        func_021EAF18((struct L *)(&s->msg), 5, 5);
        func_021EAF50((struct L *)(&s->msg), idx);
        func_021EAF50((struct L *)(&s->msg), old);
        func_021EA638(s->msgWin, (struct H *)(&s->msg), (int)((void (*)(void))func_021D2C7C));
        *state = 9;
        break;
    }
    case 9:
        if (func_021EA710(s->msgWin))
            *state = 2;
        break;
    case 10:
        func_021EAF18((struct L *)(&s->msg), 5, 7);
        func_021EAF50((struct L *)(&s->msg), idx);
        func_021EAF50((struct L *)(&s->msg), g_021F3B64.move);
        func_021EAF78((u8 *)(&s->msg), 255);
        func_021EA614(s->msgWin, (struct H *)(&s->msg));
        *state = 11;
        break;
    case 11:
        if (func_021EA720(s->msgWin)) {
            MsgParam yes, no;
            func_021EAF18((struct L *)(&yes), 6, 4);
            func_021EAF50((struct L *)(&yes), g_021F3B64.move);
            func_021EAF18((struct L *)(&no), 6, 5);
            func_021EAF50((struct L *)(&no), g_021F3B64.move);
            func_021EABC4(s->msgWin, (u32)(&yes), (u32)(&no), 1);
        }
        if (func_021EA710(s->msgWin))
            *state = 12;
        break;
    case 12: {
        int sel;
        if (func_021EAC54(s->msgWin, &sel)) {
            if (sel == 0) {
                func_021EAF18((struct L *)(&s->msg), 5, 8);
                func_021EAF50((struct L *)(&s->msg), idx);
                func_021EAF50((struct L *)(&s->msg), g_021F3B64.move);
                func_021EA614(s->msgWin, (struct H *)(&s->msg));
                *state = 13;
            } else {
                *state = 5;
            }
        }
        break;
    }
    case 13:
        if (func_021EA710(s->msgWin))
            *state = 1;
        break;
    }
    return 0;
}




/*
 * lever: const on the read-only descriptor schedules c[1] before the
 * stack-argument store in the first arm.
 */
int func_021D2FD8(u32 *a, int *b, const u32 *c)
{
    switch (*b) {
    case 0:
        func_021F7CFC(func_021B8E70((u8 *)a[0], (u8)c[0]), (u16)c[5], (u8)c[1], c[2], c[4]);
        (*b)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            if (c[2]) {
                u8 *p = func_021B98AC((char *const *)a[1], (u8)c[0]);
                func_021EAF18((struct L *)((u8 *)a + 0x58), 1, 0x41);
                func_021EAF50((struct L *)((u8 *)a + 0x58), func_021D5440(p));
                func_021F883C(0x518);
            } else {
                int msg;
                if (c[1] < 4) msg = d_021EFF80[c[1]];
                else msg = 0x3d;
                func_021EAF18((struct L *)((u8 *)a + 0x58), 1, msg);
            }
            func_021EA614((char *)a[21], (struct H *)((u8 *)a + 0x58));
            (*b)++;
        }
        break;
    case 2:
        if (func_021EA710((u32 *)a[21])) {
            if (c[2]) {
                func_021BA2D4((u32)((void *)a[0]), (u32 *)func_021B98AC((char *const *)a[1], (u8)c[0]));
                (*b)++;
            } else return 1;
        }
        break;
    case 3:
        if (!func_02005F38()) {
            func_021F7C0C();
            func_02005D90(0x47c, 0xffff);
            func_021B92A0((u8 *)a[0]);
            if (c[3]) {
                u8 *p = func_021B98AC((char *const *)a[1], (u8)c[0]);
                func_021EAF18((struct L *)((u8 *)a + 0x58), 1, 0x42);
                func_021EAF50((struct L *)((u8 *)a + 0x58), func_021D5440(p));
                func_021EA614((char *)a[21], (struct H *)((u8 *)a + 0x58));
                (*b)++;
            } else return 1;
        }
        break;
    case 4:
        if (func_021EA710((u32 *)a[21])) (*b)++;
        break;
    default:
        return 1;
    }
    return 0;
}





int func_021D3138(u32 *a, int *b, u32 *c)
{
    switch (*b) {
    case 0:
        func_021F7D44(func_021B8E70((u8 *)a[0], (u8)c[0]), (u16)c[1]);
        (*b)++;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021EAF18((struct L *)((u8 *)a + 0x58), 1, 0x43);
            func_021EA614((char *)a[0x15], (struct H *)((u8 *)a + 0x58));
            (*b)++;
        }
        break;
    case 2:
        if (func_021EA710((u32 *)a[0x15]) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}





static inline u16 sel(u32 u, u32 k)
{
    if (u == 3) {
        return (k != 0) ? 0x26 : 0x27;
    }
    return (k != 0) ? 0x28 : 0x29;
}





/*
 * Levers: the 0x26..0x29 selection is a `static inline u16` helper returning nested
 * ternaries; inlined, its result stays in r0 and each arm branches (the inner join of the
 * u == 3 arm is the unthreaded `b` hop). Written in the caller (ternary, if/else, nested
 * ternary, call in each arm) it is if-converted into r1, and a plain `static` helper is
 * not inlined. `u` is `int` (permuter: u32 put c[1] first into r7 in case 0).
 */
int func_021D31A0(u32 *a, int *b, u32 *c)
{
    u32 v;
    int u;
    u8 k;
    char *p;

    switch (*b) {
    case 0:
        u = (u8)c[0];
        v = (u8)c[1];
        p = func_021B9AEC((char *)a[1], u);
        func_021B9C50((u8 **)p, v, 0, 0);
        func_021EAA6C(a[0x15], u, v);
        (*b)++;
        break;
    case 1:
        if (func_021EAAD8(a[0x15]) != 0) {
            u = (u8)c[1];
            if (u == 1) {
                return 1;
            }
            k = func_021B9F70((u8 *)a[0], (u8)c[0]);
            func_021EA678((char *)a[0x15], sel(u, k), (int *)c);
            (*b)++;
        }
        break;
    case 2:
        if (func_021EA710((u32 *)a[0x15]) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}





int func_021D324C(u32 *a, int *b, u32 *c)
{
    u32 u;
    int s;

    u = (u8)c[0];
    s = func_021B8D8C((void *)a[0], (void *)a[1], u);
    switch (*b) {
    case 0:
        if (func_021CD9E0((u8 *)a) != 0) {
            func_021D66D0((struct QJ *)func_021B9934((char *)a[1], u), c[1]);
            return 1;
        }
        func_021EA768((u32 *)a[0x15], s, 0);
        (*b)++;
        break;
    case 1:
        if (func_021EA778((u32 *)a[0x15], s) != 0) {
            func_021D66D0((struct QJ *)func_021B9934((char *)a[1], u), c[1]);
            func_021EA7A8((u32 *)a[0x15], s);
            (*b)++;
        }
        break;
    case 2:
        if (func_021EA7B8((u32 *)a[0x15], s) != 0) {
            (*b)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}




/*
 * pass 6 2026-10-06 P6L08: EXACT (364 B), also EXACT under -lang c99. The closing change is u16 x, y
 * with func_021D66D0 declared (void *, u16), non-const a, and source order u, v, x, y. The callee
 * (func_021D66D0.c, strh to a u16 field) also matches EXACT with a u16 parameter, so the prototype is
 * consistent. Why it closes (scheduler trace, scratchpad wD9r/p6_P6L08): the word spill of the narrow
 * variable x uses the unknown-memory alias set (AO1), not a fresh spill alias object. With non-const a,
 * the pointee of a is in that set, so `str x, [sp]` gets a memory edge to the a[1] load and the load
 * waits after it, as in the original. With const a, the pointee of a is not in the set (22 B).
 * Earlier passes (wave75 to pass 6 P6L04) stayed at 13 B with u32 locals.
 */
int func_021D32E0(u32 *a, int *b, u32 *c)
{
    u32 u, v;
    u16 x, y;
    int s, t;
    u8 *p, *q;
    u = (u8)c[0];
    v = (u8)c[1];
    x = (u16)c[2];
    y = (u16)c[3];
    s = func_021B8D8C((void *)a[0], (void *)a[1], u);
    t = func_021B8D8C((void *)a[0], (void *)a[1], v);
    p = func_021B9934((char *)a[1], u);
    q = func_021B9934((char *)a[1], v);
    switch (*b) {
    case 0:
        if (func_021CD9E0((u8 *)a)) {
            func_021D66D0((struct QJ *)p, x);
            func_021D66D0((struct QJ *)q, y);
            return 1;
        }
        if (func_021B9A24(u, v)) {
            func_021D66D0((struct QJ *)p, x);
            func_021D66D0((struct QJ *)q, y);
            return 1;
        }
        func_021EA768((u32 *)((int)a[21]), s, 0);
        d_021F3B64.w[1] = 8;
        (*b)++;
        break;
    case 1:
        func_021EA778((u32 *)a[21], s);
        if (d_021F3B64.w[1]) d_021F3B64.w[1]--;
        else {
            func_021EA768((u32 *)a[21], t, 0);
            (*b)++;
        }
        break;
    case 2: {
        u8 r, z;
        r = func_021EA778((u32 *)a[21], s);
        z = func_021EA778((u32 *)a[21], t);
        if (r && z) (*b)++;
        break;
    }
    case 3:
        func_021D66D0((struct QJ *)p, x);
        func_021D66D0((struct QJ *)q, y);
        d_021F3B64.w[1] = 0;
        (*b)++;
        break;
    case 4:
        d_021F3B64.w[1]++;
        if (d_021F3B64.w[1] > 8) {
            func_021EA7A8((u32 *)a[21], s);
            (*b)++;
        }
        break;
    case 5:
        if (func_021EA7B8((u32 *)a[21], s)) {
            func_021EA7A8((u32 *)a[21], t);
            (*b)++;
        }
        break;
    case 6:
        if (func_021EA7B8((u32 *)a[21], t)) (*b)++;
        break;
    default:
        return 1;
    }
    return 0;
}





int func_021D344C(u32 *a, int *b, u32 *c)
{
    u32 u;
    int s;
    u8 *m;
    int f;

    switch (*b) {
    case 0:
        u = (u8)c[0];
        s = func_021B8D8C((void *)a[0], (void *)a[1], u);
        m = func_021B9934((char *)a[1], u);
        f = func_021CD9E0((u8 *)a);
        func_021D6C2C((struct Unk021D6C2C *)m);
        func_021EA868((u32 *)a[0x15], s, f);
        (*b)++;
        break;
    case 1:
        if (func_021EA878((u32 *)a[0x15]) != 0) {
            (*b)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}




/*
 * extent: compiled 54 bytes followed by two zero alignment bytes.
 */
int func_021D34B0(char *p, int *state, unsigned int *q)
{
    if (*state == 0) {
        if (func_021CD9E0((u8 *)p) != 0) return 1;
        func_021F7998(q[0]);
        (*state)++;
    } else {
        if (func_021F7EB4() == 0) return 1;
    }
    return 0;
}





int func_021D34E8(u32 *a, int *b, u32 *c)
{
    u8 k;

    k = func_021B8E70((u8 *)a[0], (u8)c[0]);
    if (*b == 0) {
        if (func_021CD9E0((u8 *)a) != 0) {
            return 1;
        }
        if (func_021B8590((unsigned char *)a[0]) == 0) {
            if (func_021D3558((u16)c[1]) != 0) {
                return 1;
            }
        }
        func_021EA3B8((char *)a[0x15], k, (u16)c[1]);
        (*b)++;
    } else {
        if (func_021EA3D4((void *)a[0x15]) != 0) {
            return 1;
        }
    }
    return 0;
}
