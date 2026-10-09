/*
 * file:     pokelist.c
 * unit:     yes
 * function: func_021B6240, func_021B6534, func_021B65B8, func_021B660C, func_021B6818, func_021B68F0, func_021B6B24, func_021B6D64, func_021B6D90, func_021B6F0C, func_021B6F28, func_021B6FEC, func_021B7034, func_021B7040, func_021B7078, func_021B709C, func_021B71B0, func_021B71E4, func_021B7268, func_021B7298, func_021B7624, func_021B7698, func_021B7B98, func_021B7CC4, func_021B8180, func_021B83D8, func_021B8418, func_021B8508, func_021B86D8, func_021B8758, func_021B892C, func_021B8A8C, func_021B8AC4
 * address:  0x021B6240
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02030734  0x02030734  arm
 *   func_0201A920  0x0201A920  thumb
 *   func_0201A954  0x0201A954  thumb
 *   func_020173F0  0x020173F0  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0203630C  0x0203630C  arm
 *   func_0201A354  0x0201A354  thumb
 *   func_02005728  0x02005728  thumb
 *   func_0201A59C  0x0201A59C  thumb
 *   func_020355D8  0x020355D8  arm
 *   d_021BED0C     0x021BED0C  data  a1
 *   d_021BEA78     0x021BEA78  data  a2
 *   d_021BEA84     0x021BEA84  data  a2
 *   d_021BEA90     0x021BEA90  data  a2
 *   d_021BEA9C     0x021BEA9C  data  a2
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   d_021BED80     0x021BED80  data  a1
 *   func_0201AA18  0x0201AA18  thumb
 *   func_020355C4  0x020355C4  arm
 *   func_020212B0  0x020212B0  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_021BA6A0  0x021BA6A0  thumb  ov091
 *   func_021BA81C  0x021BA81C  thumb  ov091
 *   func_021BB43C  0x021BB43C  thumb  ov091
 *   func_02027F60  0x02027F60  thumb
 *   func_021B9A84  0x021B9A84  thumb  ov091
 *   func_021BCCCC  0x021BCCCC  thumb  ov091
 *   func_020056A0  0x020056A0  thumb
 *   func_021BB594  0x021BB594  thumb  ov091
 *   func_021BBA8C  0x021BBA8C  thumb  ov091
 *   func_02041B6C  0x02041B6C  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_021BBE44  0x021BBE44  thumb  ov091
 *   func_021BBAE0  0x021BBAE0  thumb  ov091
 *   func_021BB5FC  0x021BB5FC  thumb  ov091
 *   func_020452E8  0x020452E8  arm
 *   func_021BA890  0x021BA890  thumb  ov091
 *   func_02027FD8  0x02027FD8  thumb
 *   func_021BCD80  0x021BCD80  thumb  ov091
 *   func_0202208C  0x0202208C  thumb
 *   func_020221A4  0x020221A4  thumb
 *   func_021B981C  0x021B981C  thumb  ov091
 *   func_021B9020  0x021B9020  thumb  ov091
 *   func_021B9750  0x021B9750  thumb  ov091
 *   func_021B97D4  0x021B97D4  thumb  ov091
 *   func_021BB30C  0x021BB30C  thumb  ov091
 *   func_020061E4  0x020061E4  thumb
 *   func_021BB358  0x021BB358  thumb  ov091
 *   func_021B6184  0x021B6184  thumb  ov090
 *   func_021BB714  0x021BB714  thumb  ov091
 *   func_021BB7E8  0x021BB7E8  thumb  ov091
 *   func_021BBA68  0x021BBA68  thumb  ov091
 *   func_021BC6CC  0x021BC6CC  thumb  ov091
 *   func_021BD8B0  0x021BD8B0  thumb  ov091
 *   func_021BD9C8  0x021BD9C8  thumb  ov091
 *   func_021BD8E4  0x021BD8E4  thumb  ov091
 *   func_021B61E8  0x021B61E8  thumb  ov090
 *   func_021B61FC  0x021B61FC  thumb  ov090
 *   func_0204B98C  0x0204B98C  arm
 *   func_021BA8CC  0x021BA8CC  thumb  ov091
 *   func_021BB644  0x021BB644  thumb  ov091
 *   func_021BCDE8  0x021BCDE8  thumb  ov091
 *   func_021BBE50  0x021BBE50  thumb  ov091
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0204A600  0x0204A600  arm
 *   func_02082A60  0x02082A60  arm
 *   func_02061CA4  0x02061CA4  arm
 *   d_021BEBFC     0x021BEBFC  data  a1
 *   d_021BEC04     0x021BEC04  data  a1
 *   d_020A1B38     0x020A1B38  data  a2
 *   func_0204A648  0x0204A648  arm
 *   func_020434CC  0x020434CC  arm
 *   func_02043588  0x02043588  arm
 *   func_0202223C  0x0202223C  thumb
 *   func_02022224  0x02022224  thumb
 *   func_020433E0  0x020433E0  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_02045088  0x02045088  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_02040618  0x02040618  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_02061C30  0x02061C30  arm
 *   d_021BEC3C     0x021BEC3C  data  a4
 *   d_021BEAEC     0x021BEAEC  data  a4
 *   d_021BEAFC     0x021BEAFC  data  a4
 *   d_021BEB1C     0x021BEB1C  data  a4
 *   d_021BEB3C     0x021BEB3C  data  a4
 *   d_021BEB5C     0x021BEB5C  data  a4
 *   d_021BEB9C     0x021BEB9C  data  a4
 *   d_021BEBBC     0x021BEBBC  data  a4
 *   d_021BEBDC     0x021BEBDC  data  a4
 *   d_020A1448     0x020A1448  data  a4
 *   func_0207D4B0 0x0207D4B0 arm
 *   d_021BEB7C 0x021BEB7C data a4
 *   func_02046440  0x02046440  arm
 *   func_02048A24  0x02048A24  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_02050B80  0x02050B80  arm
 *   d_021BEAB8     0x021BEAB8  data  a4
 *   d_021BEAD0     0x021BEAD0  data  a4
 *   d_021BEAC4     0x021BEAC4  data  a4
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_020403F4  0x020403F4  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02050ED4 0x02050ED4 arm
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B270  0x0204B270  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201C450  0x0201C450  thumb
 *   func_0201DD68  0x0201DD68  thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049EF4  0x02049EF4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0201BC40  0x0201BC40  thumb
 *   func_0201BCB4  0x0201BCB4  thumb
 *   func_020275E4  0x020275E4  thumb
 *   func_02027624  0x02027624  thumb
 *   func_02027628  0x02027628  thumb
 *   func_02027630  0x02027630  thumb
 *   func_020413B0  0x020413B0  arm
 *   func_02027758  0x02027758  thumb
 *   func_0202775C  0x0202775C  thumb
 *   func_02027760  0x02027760  thumb
 *   func_02027764  0x02027764  thumb
 *   func_02027614  0x02027614  thumb
 *   func_02027618  0x02027618  thumb
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 *   func_02027694  0x02027694  thumb
 *   func_02027698  0x02027698  thumb
 *   func_0202769C  0x0202769C  thumb
 *   func_020276A0  0x020276A0  thumb
 *   func_020276B4  0x020276B4  thumb
 *   func_020276B8  0x020276B8  thumb
 *   func_020276BC  0x020276BC  thumb
 *   func_020276C0  0x020276C0  thumb
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_021BBDEC 0x021BBDEC thumb ov091
 *   func_021BC1B4 0x021BC1B4 thumb ov091
 *   func_021BC1D0 0x021BC1D0 thumb ov091
 *   func_021BC2C8 0x021BC2C8 thumb ov091
 *   func_021BA65C 0x021BA65C thumb ov091
 *   func_021BB7A4 0x021BB7A4 thumb ov091
 *   func_021BAFA0 0x021BAFA0 thumb ov091
 *   func_021BDC5C 0x021BDC5C thumb ov091
 *   func_021BDCA0 0x021BDCA0 thumb ov091
 *   func_021B9F34 0x021B9F34 thumb ov091
 *   func_021BA004 0x021BA004 thumb ov091
 *   func_021B9E20 0x021B9E20 thumb ov091
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 *   func_02009050 0x02009050 thumb
 *   func_0200902C 0x0200902C thumb
 *   func_021B907C 0x021B907C thumb ov091
 *   func_021BC17C 0x021BC17C thumb ov091
 *   func_021BDD78 0x021BDD78 thumb ov091
 *   func_021BC350 0x021BC350 thumb ov091
 *   func_021BE2B4 0x021BE2B4 thumb ov091
 *   func_021BB200 0x021BB200 thumb ov091
 *   func_021BB2C0 0x021BB2C0 thumb ov091
 *   func_021BA670 0x021BA670 thumb ov091
 *   func_021BDCC0 0x021BDCC0 thumb ov091
 *   func_021BDD58 0x021BDD58 thumb ov091
 *   func_021BC30C 0x021BC30C thumb ov091
 *   func_021B9BF4 0x021B9BF4 thumb ov091
 *   func_021B9788 0x021B9788 thumb ov091
 *   func_021BA624 0x021BA624 thumb ov091
 *   func_021BB97C 0x021BB97C thumb ov091
 *   func_021BB99C 0x021BB99C thumb ov091
 *   func_021BB9AC 0x021BB9AC thumb ov091
 *   func_021BB9BC 0x021BB9BC thumb ov091
 *   func_021BB9CC 0x021BB9CC thumb ov091
 *   func_021BB98C 0x021BB98C thumb ov091
 *   func_021BC24C 0x021BC24C thumb ov091
 *   func_021BC288 0x021BC288 thumb ov091
 *   func_021BDBF8 0x021BDBF8 thumb ov091
 *   func_021BDC3C 0x021BDC3C thumb ov091
 *   func_021B9AC8 0x021B9AC8 thumb ov091
 *   func_021BA5B4 0x021BA5B4 thumb ov091
 *   func_021BA60C 0x021BA60C thumb ov091
 *   func_021B9E3C 0x021B9E3C thumb ov091
 *   func_021BA4E4 0x021BA4E4 thumb ov091
 *   func_021BA098 0x021BA098 thumb ov091
 *   func_021B9EB0 0x021B9EB0 thumb ov091
 *   func_021BD4EC  0x021BD4EC  thumb  ov091
 *   func_021BB468  0x021BB468  thumb  ov091
 *   func_021BC228  0x021BC228  thumb  ov091
 *   func_021BBAF8  0x021BBAF8  thumb  ov091
 *   func_021F6744  0x021F6744  thumb  ov112
 *   func_021B9AB4  0x021B9AB4  thumb  ov091
 *   func_021BBE5C  0x021BBE5C  thumb  ov091
 *   func_021B8F68  0x021B8F68  thumb  ov091
 *   func_02041300  0x02041300  arm
 *   func_021BBE68  0x021BBE68  thumb  ov091
 *   func_0204B878  0x0204B878  arm
 *   func_021B9968  0x021B9968  thumb  ov091
 *   func_021BB464  0x021BB464  thumb  ov091
 *   func_021BA288  0x021BA288  thumb  ov091
 *   _u32_div_f     0x0209C2B0  arm
 *   func_02019E54  0x02019E54  thumb
 *   func_021BB9EC  0x021BB9EC  thumb  ov091
 *   func_021B8DB4 0x021B8DB4 thumb ov091
 *   func_020362DC  0x020362DC  arm
 *   func_0203633C  0x0203633C  arm
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_021B9AA0  0x021B9AA0  thumb  ov091
 *   func_021BB3C4  0x021BB3C4  thumb  ov091
 *   d_021BEAB0     0x021BEAB0  data  a1
 *   d_021BEAAA     0x021BEAAA  data  a1
 */
#include "../../matched/include/Obj04352.h"
#include "../../matched/include/Obj00009.h"
#include "../../matched/include/Obj20854.h"
#include "../../matched/include/Obj07728.h"
#include "../../matched/include/Obj20855.h"
#include "../../matched/include/Obj00047.h"
#include "../../matched/include/Obj01888.h"
#include "../../matched/include/Obj02767.h"
#include "../../matched/include/Obj06209.h"
#include "../../matched/include/Obj20856.h"
#include "../../matched/include/Obj20857.h"
#include "../../matched/include/Obj20858.h"
#include "../../matched/include/Obj20859.h"
#include "../../matched/include/Obj06210.h"

#define H(o) (*(u16 *)(p + (o)))
#define reg_GX_DISPCNT (*(volatile u32 *)0x04000000)
#define reg_GXS_DB_DISPCNT (*(volatile u32 *)0x04001000)
#define reg_GX_POWCNT (*(volatile u16 *)0x04000304)
#define SD (*(u8 **)(p+0x280))
#define HS(k) (*(u16 *)(SD+(k)))
#define TS(k) (*(u32 *)(SD+(k)))
struct Party;
struct PartyMon;
struct Obj0203159C;
struct S020315D4;
struct R;
struct Descriptor;
struct Node;
struct TaskMenuState;
struct Actor;
struct PrintSys;
struct S;
struct Pal;
struct Cfg;
struct DispConfig;
struct DispVram;
struct Light;
struct BgTemplate;
struct Bank;
struct Obj;
struct GfFont;
struct MsgBank;
struct Rec;
struct Sub02008F80Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef struct {
    u16 v[5];
} Ten;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u16 h6;
    u8 pad8[0xa8 - 8];
    u16 ha8;
} S;

typedef struct {
    void *list;
    u16 *t;
    u8 b;
} E;

typedef struct {
    void *party;
    u8 pad04[0x14 - 4];
    S *s;
    u8 pad18[0x34 - 0x18];
    int v34;
    u8 pad38[0x3c - 0x38];
    int v3c;
    u8 pad40[0x44 - 0x40];
    u16 h44;
    u8 pad46[0x49 - 0x46];
    u8 b49[6];
    u8 pad4f[0x60 - 0x4f];
    u16 h60;
    u8 pad62[0x64 - 0x62];
    int v64;
    E e[3];
    int v8c;
    int v90;
    u8 b94;
} Q_021B6240;

typedef struct {
    u16 heap;
    u8 pad[0x280 - 2];
    Q_021B6240 *q;
} P_021B6240;

typedef signed int     s32;

typedef struct {
    u8 pad0[0x14];
    void *v14;
    u8 pad18[0x68 - 0x18];
    struct {
        void *a;
        void *b;
        u8 pad[4];
    } e[3];
} Q_021B6534;

typedef struct {
    u8 pad[640];
    Q_021B6534 *q;
} P_021B6534;

typedef struct {
    u8 pad0[0x60];
    u16 v60;
    u8 pad62[0x90 - 0x62];
    u32 v90;
} Q_021B65B8;

typedef struct {
    u8 pad[640];
    Q_021B65B8 *q;
} P_021B65B8;

typedef void (*Fn)(u8 *p);

typedef signed char s8;

typedef short s16;

struct C3 { u16 v[3]; };

struct Pal {
    u8 pad0[0x10];
    u32 mode;
    u8 pad1[0x2c];
    u16 src[3][16];
    u16 dst[3][16];
    u8 step;
    u8 pad2;
    u16 phase;
};

typedef struct {
    u32 w[12];
} A48;

typedef struct {
    u32 w[7];
} B28;

typedef enum { GX_DISP_SELECT_SUB_MAIN = 0, GX_DISP_SELECT_MAIN_SUB = 1 } GXDispSelect;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} R;

extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Party *func_0201A920(u32 heap);
extern void func_0201A954(struct Party *p, s32 capacity);
extern void *func_020173F0(u16 species, u16 level, u64 id, u16 heap);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern u32 func_020307B0(void *p);
extern u32 func_0203630C(void);
extern void *func_0201A354(int a, int b);
extern u32 func_02005728(u32 range);
extern int func_0201A59C(void *a0, void *a1, void *a2);
extern void func_020355D8(int a);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern u32 func_0201AA18(void *);
extern u8 func_020355C4(void);
extern u16 func_020212B0(u16 id);
extern void *func_0201AB28(void *p, u32 idx);
extern u8 *func_021BA6A0(u8 *p, int k, void *mon);
extern int func_021BA81C(u8 *p, int k);
extern int func_021BB43C(int *p);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern int func_021B9A84(u32 p);
extern void func_021BCCCC(int p);
extern int func_020056A0(void (*cb)(void *, u8 *), u8 *p, int pri);
extern u32 *func_021BB594(u16 *h);
extern u32 *func_021BBA8C(u16 *h);
extern void func_02041B6C(u32 id);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02030EAC(struct Node *n);
extern void func_021BBE44(int x);
extern void func_021BBAE0(int a, unsigned char *b);
extern void func_021BB5FC(void *a, int *s);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_021BA890(void *ignored, u8 *p);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_021BCD80(char *a);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);
extern void func_021B981C(u8 *p);
extern void func_021B9020(u8 *p);
extern void func_021B9750(unsigned p);
extern void func_021B97D4(u8 *p);
extern void func_021BB30C(u8 *p, int s);
extern void func_020061E4(u32 id);
extern int func_021BB358(u8 *p, struct S *s);
extern u32 func_021B6184(u8 *p, u8 b, u16 a);
extern void func_021BB714(void *a, u32 *s, u32 k);
extern void func_021BB7E8(u8 *a, u32 *s, u32 x);
extern void func_021BBA68(u8 *p, u8 *s);
extern void func_021BC6CC(u8 *p);
extern void func_021BD8B0(char *p);
extern void func_021BD9C8(u8 *p);
extern void func_021BD8E4(u8 *p);
extern void func_021B61E8(void *a, int b);
extern int func_021B61FC(int w, int a);
extern u32 func_0204B98C(struct Actor *a);
extern void func_021BA8CC(u8 *p, int s);
extern void func_021BB644(u8 *p, u8 *s);
extern void func_021BCDE8(char *a);
extern void func_021BBE50(int x);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0204A600(void);
extern void func_02082A60(void *src, void *dst, u32 size);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void func_0204A648(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0202223C(u32 a, u32 color);
extern void func_02022224(int a);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16 heapId);
extern void func_02045088(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0207D63C(u32 r, int a, int b, int c, int d);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_02061C30(void);
extern void func_0207D4B0(int,int,int);
extern void func_02046440(int, int, int, int, int, int, int);
extern int func_02048A24(int, int, int, int, int, int, int, int, void *, void *, void *, int);
extern void func_02048AD0(struct Light *l);
extern void func_02050B80(u32 heap);
extern void func_0204A5AC(void);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02050ED4(void);
extern unsigned int func_02048AC4(void *ptr);
extern void func_02046788(void);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020414AC(unsigned);
extern void func_020409B4(u32 index);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_0204B1CC(struct Bank *bank);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02049B40(u32 h, u32 a, u32 c, u32 d, u32 e, u16 heap);
extern void *func_0201C450(u16 n, u32 heap);
extern void func_0201DD68(void);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void *func_02049EF4(void *h, u32 a1, u32 a2, void **out, u16 heap);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC3C(void);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_02027630(void);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern int func_02027758(void);
extern int func_0202775C(int a);
extern int func_02027760(int a);
extern int func_02027764(int a);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern u32 func_02027694(void);
extern u32 func_02027698(void);
extern u32 func_0202769C(u32 a);
extern u32 func_020276A0(u32 a);
extern u32 func_020276B4(void);
extern u32 func_020276B8(void);
extern u32 func_020276BC(u32 a);
extern u32 func_020276C0(u32 a);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_02017E1C(void *,u32,u32);
extern u32 func_0202136C(u16);
extern struct Sub02008F80Obj *func_02009050(struct Sub02008F80Obj *arr, u32 unused, int i, u32 heap);
extern void func_0200902C(struct Sub02008F80Obj *arr, u32 unused, int i);
extern void func_021B907C(u8 *);
extern int func_021BC17C(unsigned short *p, int id);
extern int func_021BDD78(void *a, u32 id, int slot, u32 heap);
extern int func_021BC350(u8 *,int);
extern int func_021BE2B4(void *mon, u16 item, u16 moveSlot, u16 arg, int heap);
extern void func_021BB200(u8 *a, u8 *s, int p, int q);
extern void func_021BB2C0(u8 *a, u8 *s);
extern u32 func_021BA670(u8 *p, u16 id);
extern int func_021BDCC0(char *p, u32 a1);
extern void func_021BDD58(u32 p, void *m);
extern void func_021BC30C(int p);
extern u32 func_021B9BF4(u8 *p, void *mon, u32 param);
extern void func_021B9788(u8 *,int,int,int);
extern void func_021BA624(u8 *,void *,u16);
extern void func_021BB97C(u16 *p, u32 s);
extern void func_021BB99C(int a, int b, int c, int d);
extern void func_021BB9AC(int a, int b, int c, int d);
extern void func_021BB9BC(int a, u32 b, u32 c, int d);
extern void func_021BB9CC(int a, int b, int c, int d);
extern void func_021BB98C(void *p, u32 s);
extern void func_021BC24C(void *unused, void *a, int b);
extern void func_021BC288(int unused, int a, int b);
extern int func_021BDBF8(u8 *,u32);
extern void func_021BDC3C(u32 p, void *m);
extern int func_021B9AC8(u8 *p, void *mon, u8 bit);
extern u32 func_021BA5B4(u8 *p, void *q);
extern void func_021BA60C(u8 *p, void *q);
extern void func_021B9E3C(char *p);
extern void func_021BA4E4(u8 *p);
extern void func_021BA098(u8 *p);
extern void func_021B9EB0(u8 *p);
extern int func_021BBDEC(int p, int unused, int id, int r3, u8 a4, int a5);
extern int func_021BC1B4(unsigned short *p, void *id);
extern int func_021BC1D0(u8 *);
extern void func_021BC2C8(int p);
extern u32 func_021BA65C(u8 *p, u16 id);
extern void func_021BB7A4(void *p, u32 *s);
extern void func_021BAFA0(u8 *a, u8 *s, int k);
extern int func_021BDC5C(u8 *,u32);
extern void func_021BDCA0(u32 p, void *m);
extern void func_021B9F34(u8 *p);
extern void func_021BA004(u8 *p);
extern void func_021B9E20(u8 *p);
extern void func_021BD4EC(char *p);
extern int func_021BB468(int unused, int *p);
extern int func_021BC228(int unused, int id);
extern void func_021BBAF8(u8 *a, u8 *b, int *items);
extern int func_021F6744(void *p);
extern int func_021B9AB4(u8 *p);
extern void func_021BBE5C(int h, int f);
extern void func_021B8F68(u8 *p, int v);
extern void func_02041300(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6);
extern void func_021BBE68(int h, int f);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021B9968(u8 *p);
extern unsigned short func_021BB464(int unused, unsigned short *p);
extern void func_021BA288(u8 *p);
extern int  func_02019E54(u32 a0, u32 a1, u32 a2);
extern void func_021BB9EC(int a, int b, int c, int d, unsigned char e);
extern void func_021B8DB4(unsigned char *);
extern u32  func_020362DC(void);
extern unsigned int func_0203633C(void);
extern u32 func_0204B3F4(struct Obj *p);
extern int func_021B9AA0(u32 p);
extern int func_021BB3C4(void *unused, u32 p);
int func_021B6240(struct Obj0203159C *a0, int *seq, Q_021B6240 *q, P_021B6240 *p);
int func_021B6534(int a0, int a1, int a2, P_021B6534 *p);
int func_021B65B8(int a0, int a1, int a2, P_021B65B8 *p);
int func_021B660C(u8 *p);
int func_021B6818(u8 *p);
int func_021B68F0(u8 *p);
void func_021B6B24(struct Pal *p);
void func_021B6D64(void *tcb, u8 *p);
void func_021B6D90(u8 *p);
void func_021B6F0C(void *p);
void func_021B6F28(char *p);
void func_021B6FEC(int a);
void func_021B7034(int unused);
void func_021B7040(unsigned p);
void func_021B7078(const void *p, unsigned id,unsigned type);
void func_021B709C(u8 *p);
void func_021B71B0(unsigned p);
void func_021B71E4(char *p);
void func_021B7268(unsigned p);
void func_021B7298(u8 *p);
void func_021B7624(char *p);
void func_021B7698(u8 *p);
void func_021B7B98(u8 *p);
void func_021B7CC4(u8 *p);
void func_021B8180(u8 *p);
void func_021B83D8(u8 *p);
void func_021B8418(u8 *p);
void func_021B8508(u8 *p);
void func_021B86D8(u8 *p);
void func_021B8758(u8 *p);
void func_021B892C(u8 *p);
void func_021B8A8C(unsigned char *p);
void func_021B8AC4(u8 *p);
extern const char d_021BED0C[];
extern const Ten d_021BEA78;
extern const Ten d_021BEA84;
extern const u16 d_021BEA90[];
extern const u16 d_021BEA9C[];
extern u8 d_021BED80;
extern const struct C3 d_021BEBFC;
extern const struct C3 d_021BEC04;
extern s16 d_020A1B38[];
extern A48 d_021BEC3C;
extern B28 d_020A1448;
extern char d_021BEAEC[];
extern char d_021BEAFC[];
extern char d_021BEB1C[];
extern char d_021BEB3C[];
extern char d_021BEB5C[];
extern char d_021BEB9C[];
extern char d_021BEBBC[];
extern char d_021BEBDC[];
extern char d_021BEB7C[];
extern char d_021BEAB8[];
extern char d_021BEAD0[];
extern char d_021BEAC4[];
extern const u8 d_021BEAB0[];
extern const u8 d_021BEAAA[];


#define W(o) (*(int *)(p + (o)))








/*
 * Byte-correct; the one wildcard is the arm9 call to 0x0201A354 (+0x10E).
 *   data run, Ilias's) has no witness outside this range. Verified C for it
 *   (from src/pending/ov/ov021_func_021B57CC.c, match.py one --thumb, EXACT,
 *   16 bytes):
 *     extern int func_02048F60();  (symbols: func_02048F60 0x02048F60 arm)
 *     int func_0201A354(int a, int b) { return func_02048F60(0x69, a, b); }
 *   Levers: the four 10-byte stack copies declared b, d, c, a (reverse of
 *   their frame order); t[4] spelled `k + 0xff11` (pool word, then +0xee
 *   for t[5]); `k = 0` before the b49 clear loop, which stores k.
 */
int func_021B6240(struct Obj0203159C *a0, int *seq, Q_021B6240 *q, P_021B6240 *p)
{
    Ten b;
    Ten d;
    Ten c;
    Ten a;
    u8 i;
    u8 k;
    void *mon;
    S *s;
    u16 *t;

    switch (*seq) {
    case 0:
        func_0203064C(1, 0x17, 0x30000);
        p = func_0203159C(a0, 0x284, 0x17);
        p->heap = 0x17;
        if (q == 0) {
            q = func_02030734(0x17, 0x98, 1, d_021BED0C, 0x52);
            q->party = func_0201A920(0x17);
            q->v3c = 0;
            func_0201A954(q->party, 6);
            a = d_021BEA78;
            for (i = 0; i < 6; i++) {
                mon = func_020173F0(d_021BEA90[i], d_021BEA9C[i], 0xffffffff, 0x17);
                b = a;
                func_02017E40(mon, 0x8e, (u32)&b);
                func_02017E40(mon, 0x9a, 0);
                func_0201A98C(q->party, mon);
                func_020307B0(mon);
            }
            q->v34 = 0;
            if (func_0203630C() & 0x100) {
                s = func_0201A354(0xf, 0x17);
                q->s = s;
                s->b2 = 1;
                s->b3 = 6;
                s->b4 = 1;
                s->b5 = 0;
                s->ha8 = 0;
                s->h6 = 0xc8;
                k = 0;
                for (i = 0; i < 6; i++)
                    q->b49[i] = 0;
                q->v34 = 0x16;
                for (k = 0; k < 3; k++) {
                    c = d_021BEA84;
                    q->e[k].list = func_0201A920(0x17);
                    for (i = 0; i < 6; i++) {
                        mon = func_020173F0(func_02005728(0xfa), 0x64, 0xffffffff, 0x17);
                        d = c;
                        func_02017E40(mon, 0x8e, (u32)&d);
                        func_02017E40(mon, 0x9a, 0);
                        func_02017E40(mon, 6, func_02005728(2));
                        func_0201A98C(q->e[k].list, mon);
                        func_020307B0(mon);
                    }
                    t = func_02030734(0x17, 0xc, 0, d_021BED0C, 0xae);
                    t[0] = 0x3077;
                    t[1] = 0x308c;
                    t[2] = 0x3044;
                    t[3] = 0x3084;
                    t[4] = k + 0xff11;
                    t[5] = 0xffff;
                    q->e[k].t = t;
                    q->e[k].b = func_02005728(2);
                }
                q->v64 = 2;
                q->v8c = 1;
                q->v90 = 1;
                q->h60 = 0xff;
                q->b94 = 0;
                func_0201A59C(s, q->party, 0);
            } else if (func_0203630C() & 0x400) {
                q->v34 = 5;
                q->h44 = 0x2c;
            } else if (func_0203630C() & 0x800) {
                q->v34 = 0x19;
            }
            func_020355D8(1);
        }
        p->q = q;
        *seq = 1;
    case 1:
        if (func_021B660C((u8 *)p) == 1)
            return 1;
        break;
    }
    return 0;
}








int func_021B6534(int a0, int a1, int a2, P_021B6534 *p)
{
    u8 i;

    if (func_021B6818((u8 *)p) == 0)
        return 0;
    if (a2 == 0) {
        for (i = 0; i < 3; i++) {
            if (p->q->e[i].a != 0)
                func_020307B0(p->q->e[i].a);
            if (p->q->e[i].b != 0)
                func_020307B0(p->q->e[i].b);
        }
        if (p->q->v14 != 0)
            func_020307B0(p->q->v14);
        func_020307B0(*(void **)p->q);
        func_020307B0(p->q);
    }
    func_020315D4((struct S020315D4 *)a0);
    func_020306F0(0x17);
    return 1;
}








int func_021B65B8(int a0, int a1, int a2, P_021B65B8 *p)
{
    Q_021B65B8 *q;

    if (a2 == 0) {
        q = p->q;
        if (q->v90 == 1 && q->v60 != 0) {
            d_021BED80++;
            if (d_021BED80 > 0x3c) {
                d_021BED80 = 0;
                q->v60 = q->v60 - 1;
            }
        }
    }
    if (func_021B68F0((u8 *)p) == 1)
        return 1;
    return 0;
}








/*
 * The 0x160 table is indexed as `p + i * 4 + 0x160` (base plus scaled
 * index, then the field offset) and the list lookup goes through a temp:
 * that is what puts the row address after func_0201AB28 and keeps the
 * three 0x160 offsets as spilled loop invariants.
 */
int func_021B660C(u8 *p)
{
    u8 n;
    u8 i;
    u8 *q;
    int e;

    n = func_0201AA18((void *)*(int *)W(0x280));
    W(8) = func_020355C4();
    W(0x3c) = 0x17;
    p[0xc] = 0;
    p[0xe] = 0;
    W(0x2c) = 0;
    W(0x38) = 0;
    W(0x30) = 9;
    W(0x34) = 9;
    W(0x14) = 0;
    W(0x10) = 0;
    p[0x105] = 0;
    p[0x100] = 0;
    H(0x102) = 0;
    H(0x110) = 0;
    p[0x114] = 0;
    W(0x120) = 0;
    W(0x130) = 0;
    W(0x1e8) = 0;
    W(0x108) = 0;
    W(0x10c) = 0;
    W(0x118) = 0;
    W(0x264) = 0;
    W(0x250) = 0;
    W(0x278) = 0;
    *(u8 *)(W(0x280) + 0x63) = 0;
    W(0x28) = 1;
    W(0x24) = 0;
    for (i = 0; i < 0x17; i++)
        ((int *)(p + 0x178))[i] = -1;
    W(0x1c) = *(int *)(W(0x280) + 0x34) == 0x19 ? 1 : 0;
    q = (u8 *)W(0x280);
    if (((struct Obj04352 *)q)->f34 == 0x18) {
        ((struct Obj04352 *)q)->f34 = 3;
        W(0x18) = 1;
    } else {
        W(0x18) = 0;
    }
    q = (u8 *)W(0x280);
    if (((struct Obj04352 *)q)->f34 == 0x1a) {
        ((struct Obj04352 *)q)->f34 = 1;
        W(0x20) = 1;
    } else {
        W(0x20) = 0;
    }
    q = (u8 *)W(0x280);
    if (((struct Obj04352 *)q)->f34 == 6 && ((struct Obj04352 *)q)->f46 == 0)
        *(u16 *)(W(0x280) + 0x46) = func_020212B0(((struct Obj04352 *)q)->f44);
    func_021B6D90(p);
    func_021B7298(p);
    func_021B71E4((char *)p);
    for (i = 0; i < 6; i++) {
        if (i < n) {
            e = (int)func_0201AB28(*(void **)W(0x280), i);
            *(int *)(p + i * 4 + 0x160) = (int)func_021BA6A0(p, i, (void *)e);
        } else
            *(int *)(p + i * 4 + 0x160) = func_021BA81C(p, i);
        if (func_021BB43C((int *)(*(int *)(p + i * 4 + 0x160))) <= 5)
            p[0x105]++;
    }
    W(0x254) = (int)func_02027F60(0, 1, W(0x138), W(0x140), H(0));
    func_021B709C(p);
    if (func_021B9A84((u32)p) == 1)
        func_021BCCCC((int)p);
    W(4) = func_020056A0(func_021B6D64, p, 8);
    W(0x150) = (int)func_021BB594((u16 *)p);
    W(0x154) = (int)func_021BBA8C((u16 *)p);
    func_021B7698(p);
    func_02041B6C(3);
    func_02041B6C(2);
    func_02041B6C(7);
    func_0203D34C(1, H(0));
    return 1;
}








int func_021B6818(u8 *p)
{
    u8 i;

    func_02030EAC((struct Node *)W(4));
    if (func_021B9A84((u32)p) == 1) {
        func_021BBE44(W(0x108));
        func_021BBE44(W(0x10c));
        W(0x108) = 0;
        W(0x10c) = 0;
    }
    func_021BBAE0((int)p, (unsigned char *)W(0x154));
    func_021BB5FC(p, (int *)W(0x150));
    if (W(0x130) != 0)
        func_020452E8((struct Descriptor *)W(0x130));
    for (i = 0; i < 6; i++)
        func_021BA890(p, (u8 *)(((int *)(p + 0x160))[i]));
    func_02027FD8((struct TaskMenuState *)W(0x254));
    func_021B7268((unsigned int)p);
    if (func_021B9A84((u32)p) == 1)
        func_021BCD80((char *)p);
    func_021B71B0((unsigned int)p);
    func_021B7624((char *)p);
    func_021B6FEC((int)p);
    if (W(0x18) == 1)
        *(int *)(W(0x280) + 0x34) = 0x18;
    if (W(0x1c) == 1)
        *(int *)(W(0x280) + 0x34) = 0x19;
    if (W(0x20) == 1)
        *(int *)(W(0x280) + 0x34) = 0x1a;
    func_020355D8(W(8));
    return 1;
}








/*
 * Case 20 is written before case 19: case 19's fallback repeats case 20's
 * body and mwcc tail-merges it into the earlier copy, which puts case 20's
 * code first in the original.
 */
int func_021B68F0(u8 *p)
{
    u8 i;
    Fn fn;

    switch (p[0xc]) {
    case 0:
        func_0202208C((void *)2, 1, 1, 0, 6, 1, H(0));
        p[0xc] = 1;
        break;
    case 1:
        if (func_020221A4() == 1)
            p[0xc] = p[0xd];
        break;
    case 2:
    case 3:
    case 4:
        func_021B83D8(p);
        break;
    case 5:
        func_021B981C(p);
        break;
    case 6:
        func_021B9020(p);
        break;
    case 7:
        func_021B9750((unsigned int)p);
        break;
    case 9:
        func_021B97D4(p);
        break;
    case 10:
        func_021BB30C(p, *(int *)(p + W(0x2c) * 4 + 0x160));
        if (W(0x24) == 1) {
            W(0x24) = 0;
            func_020061E4(0x56f);
        }
        p[0xc] = 0xb;
    case 11:
        if (func_021BB358(p, (struct S *)(*(int *)(p + W(0x2c) * 4 + 0x160))) == 1) {
            fn = *(Fn *)&((struct Obj00009 *)p)->f120;
            if (fn != 0)
                fn(p);
            else
                p[0xc] = 0x15;
        }
        break;
    case 12:
        p[0x114]++;
        if (p[0x114] > 0x10) {
            if (W(0x20) == 1) {
                if (func_021B6184((u8 *)W(0x280), 0, 0) == 1) {
                    p[0xc] = 0x11;
                    func_021BBE44(W(0x108));
                    func_021BBE44(W(0x10c));
                    W(0x108) = 0;
                    W(0x10c) = 0;
                    func_021BB714(p, (u32 *)W(0x150), 0);
                    func_021BB7E8(p, (u32 *)W(0x150), 0xb0);
                    func_021BBA68(p, (u8 *)W(0x150));
                }
            } else {
                p[0xc] = 0x13;
            }
        }
        break;
    case 13:
        func_021BC6CC(p);
        break;
    case 14:
        func_021BD8B0((char *)p);
        break;
    case 15:
        func_021BD9C8(p);
        break;
    case 16:
        func_021BD8E4(p);
        break;
    case 17:
        func_021B61E8((void *)W(0x280), 2);
        p[0xc] = 0x12;
        break;
    case 18:
        if (func_021B61FC(W(0x280), 2) == 1)
            p[0xc] = 0x13;
        break;
    case 20:
        func_0202208C(0, 0, 0, 0, 6, 1, H(0));
        p[0xc] = 0x15;
        break;
    case 19:
        if (W(0x1e8) == 0 || func_0204B98C((struct Actor *)W(0x1e8)) == 0) {
            func_0202208C(0, 0, 0, 0, 6, 1, H(0));
            p[0xc] = 0x15;
        }
        break;
    case 21:
        if (func_020221A4() == 1)
            return 1;
        break;
    }
    for (i = 0; i < 6; i++)
        func_021BA8CC(p, ((int *)(p + 0x160))[i]);
    func_021BB644(p, (u8 *)W(0x150));
    func_021B6B24((struct Pal *)p);
    if (func_021B9A84((u32)p) == 1) {
        func_021BCDE8((char *)p);
        func_021BBE50(W(0x108));
        func_021BBE50(W(0x10c));
    }
    func_0201C4E4((struct PrintSys *)W(0x140));
    func_0204A600();
    return 0;
}








/*
 * Palette fade (u8 step countdown at +0x100, brighten src[3][16] into dst, skipping
 * columns 2..4, then a sine blend of dst[i][2..4] between two 3-colour tables, then
 * func_02061CA4(15, 0xc0, dst, 0x60)).
 * note: final push 2026-10-05 G9L1, EXACT in c99 and c. Four source facts closed the draft
 * (182 B off): (1) the phase update stores in each if/else arm (p->phase = p->phase - 0xfc00
 * or p->phase = t), so the 0x102 offset stays live in r1 and v sits in r3; (2) each blended
 * channel is clamped into a shared int t (`...; r = t;`) and assigned to a u8 local, which
 * puts the byte truncation at the join as in the image; (3) the blend deltas are written
 * red first (ar, br, dr, then green, then blue); the scheduler still emits green first, but
 * the red values are born first and take the registers the image shows; (4) f is declared
 * after the counters, and b is u16 while a is int. Earlier notes: hi and lo are two struct C3
 * locals, each delta is read three times (clamp), tried-and-failed forms in git history.
 * Callee 02061CA4 matches its 4-parameter definition.
 */
void func_021B6B24(struct Pal *p)
{
    u8 i;
    u8 i2;
    u8 j;
    u8 j2;
    u8 k;
    int f;
    struct C3 hi;
    struct C3 lo;

    func_02082A60(p->src, p->dst, 0x60);
    if (p->step != 0) {
        p->step--;
        k = p->step;
        if (k > 6) {
            k = 12 - k;
        }
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 16; j++) {
                if (j >= 2 && j <= 4) {
                    continue;
                }
                {
                    u16 c = p->src[i][j];
                    u8 g = (c & 0x3e0) >> 5;
                    u8 b = (c & 0x7c00) >> 10;
                    u8 r = c & 0x1f;
                    int t;
                    t = r + k * 2;
                    if (t > 31) t = 31;
                    r = t;
                    t = g + k * 2;
                    if (t > 31) t = 31;
                    g = t;
                    t = b + k * 2;
                    if (t > 31) t = 31;
                    b = t;
                    p->dst[i][j] = r | (g << 5) | (b << 10);
                }
            }
        }
    }
    hi = d_021BEBFC;
    lo = d_021BEC04;
    if (p->mode == 0) {
        int t = p->phase + 0x400;
        if (t >= 0x10000) {
            p->phase = p->phase - 0xfc00;
        } else {
            p->phase = t;
        }
    } else {
        p->phase = 0xc000;
    }
    f = (d_020A1B38[(p->phase >> 4) * 2] + 0x1000) / 2;
    for (i2 = 0; i2 < 3; i2++) {
        for (j2 = 0; j2 < 3; j2++) {
            int a = hi.v[j2];
            u16 b = lo.v[j2];
            u8 ar = a & 0x1f;
            u8 br = b & 0x1f;
            s8 dr = ((br - ar) * f) >> 12;
            u8 ag = (a & 0x3e0) >> 5;
            u8 bg = (b & 0x3e0) >> 5;
            s8 dg = ((bg - ag) * f) >> 12;
            u8 ab = (a & 0x7c00) >> 10;
            u8 bb = (b & 0x7c00) >> 10;
            s8 db = ((bb - ab) * f) >> 12;
            u8 r, g, bl;
            int t;
            if (ar + dr > 31) t = 31; else if (ar + dr < 0) t = 0; else t = ar + dr;
            r = t;
            if (ag + dg > 31) t = 31; else if (ag + dg < 0) t = 0; else t = ag + dg;
            g = t;
            if (ab + db > 31) t = 31; else if (ab + db < 0) t = 0; else t = ab + db;
            bl = t;
            p->dst[i2][j2 + 2] = r | (g << 5) | (bl << 10);
        }
    }
    func_02061CA4((void *)15, 0xc0, (u32)p->dst, 0x60);
}








static inline void GX_SetVisibleWnd(int window)
{
    reg_GX_DISPCNT = reg_GX_DISPCNT & ~0xE000 | (window << 13);
}








void func_021B6D64(void *tcb, u8 *p)
{
    if (((struct Obj20854 *)p)->f10 == 1)
        GX_SetVisibleWnd(1);
    else
        GX_SetVisibleWnd(0);
    func_0204A648();
}






static inline void GX_SetVisiblePlane(int plane)
{
    reg_GX_DISPCNT = (u32)((reg_GX_DISPCNT & ~0x1f00) | (plane << 8));
}






static inline void GXS_SetVisiblePlane(int plane)
{
    reg_GXS_DB_DISPCNT = (u32)((reg_GXS_DB_DISPCNT & ~0x1f00) | (plane << 8));
}






static inline void GX_SetDispSelect(GXDispSelect sel)
{
    reg_GX_POWCNT = (u16)((reg_GX_POWCNT & ~0x8000) | (sel << 15));
}






void func_021B6D90(u8 *p)
{
    A48 a;
    B28 b;

    a = d_021BEC3C;
    if (func_021B9A84((u32)p) == 1) {
        a.w[6] = 8;
        a.w[8] = 0;
    } else {
        a.w[6] = 0x100;
    }
    func_020434CC();
    func_02043588();
    GX_SetVisiblePlane(0);
    GXS_SetVisiblePlane(0);
    func_0202223C(0, 0);
    func_0202223C(1, 0);
    func_02022224(0);
    func_02022224(1);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    func_020433E0((const struct DispVram *)(&a));
    func_0203F8F4(*(u16 *)p);
    func_02045088(*(u16 *)p);
    func_0203FC28((struct DispConfig *)d_021BEAEC);
    func_021B7078(d_021BEBDC, 3, 0);
    func_021B7078(d_021BEBBC, 2, 0);
    func_021B7078(d_021BEB9C, 1, 0);
    func_021B7078(d_021BEB5C, 7, 0);
    func_021B7078(d_021BEB3C, 6, 0);
    func_021B7078(d_021BEB1C, 5, 0);
    func_021B7078(d_021BEAFC, 4, 0);
    func_021B6F0C(p);
    func_0207D63C(0x04000050, 0x14, 8, 0x10, 10);
    func_0207D63C(0x04001050, 4, 8, 0x10, 10);
    func_02040618(2, 0, 0x80);
    func_02040618(1, 0, 0x80);
    b = d_020A1448;
    func_0204A48C((const struct Cfg *)(&b), (u32)(&a), *(u16 *)p);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    func_02061C30();
}




void func_021B6F0C(void *p) { func_0207D4B0(1,0,0); func_021B7078(d_021BEB7C,0,0); }





void func_021B6F28(char *p)
{
    int r;

    func_0207D4B0(1, 0, 1);
    func_02046440(0, 1, 0, 1, 0, ((struct Obj07728 *)p)->f0, 0);
    *(volatile u16 *)0x04000008 = *(volatile u16 *)0x04000008 & ~3;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x20;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x10;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 8;
    r = func_02048A24(2, 0, 0x50D7, 0, 0x6BCA, 0x1000, 0x80000, 0, d_021BEAB8, d_021BEAD0, d_021BEAC4, ((struct Obj07728 *)p)->f0);
    ((struct Obj07728 *)p)->f258 = r;
    func_02048AD0((struct Light *)r);
    func_0207D63C(0x04000050, 4, 0x1e, 0x10, 10);
    func_02050B80(((struct Obj07728 *)p)->f0);
}





/*
 * `ldr ip,[pc,#4]; ldr r0,[pc,#4]; bx ip; .word 0x02061B5C; .word 0x02146B80`,
 * no witness outside this range.  Leaf C tried (DIFF only, the two loads and
 * the two pool words come out swapped, 8 bytes):
 *   extern void func_02061B5C(void *); extern char d_02146B80[];
 *   void func_02061C30(void) { func_02061B5C(d_02146B80); }
 *   (`return func_02061B5C((int)d_02146B80)` with int types: same DIFF)
 */
void func_021B6FEC(int a)
{
    func_02061C30();
    func_0204A5AC();
    func_021B7034(a);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020450C8();
    func_0203F9B4();
}




void func_021B7034(int unused)
{
    func_020403F4(0);
}



void func_021B7040(unsigned p) { func_02050ED4(); func_02048AC4((void *)(((struct Obj20855 *)p)->f258)); func_02046788(); func_020403F4(0); func_0207D63C(0x04000050,20,8,16,10); }



void func_021B7078(const void *p, unsigned id,unsigned type) { func_0203FCA0(id,p,type); func_02040588(id,1); func_020414AC(id); func_020409B4(id); }




void func_021B709C(u8 *p)
{
    R b;
    R a;
    int x;
    u32 bank;

    bank = (u32)func_0204B100(10, 8, ((struct Obj00047 *)p)->f0);
    *(u32 *)&((struct Obj00047 *)p)->f1D4 = bank;
    func_0204B270((struct Bank *)bank);
    b.a = 0;
    b.b = 0;
    b.c = 0;
    b.d = 10;
    b.e = 3;
    ((struct Obj00047 *)p)->f1D8 = (int)func_0204B294((void *)((struct Obj00047 *)p)->f1D4, ((struct Obj00047 *)p)->f198,
                                        ((struct Obj00047 *)p)->f178, ((struct Obj00047 *)p)->f1B4, &b, 0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1DC = (int)func_0204B294((void *)((struct Obj00047 *)p)->f1D4, ((struct Obj00047 *)p)->f198,
                                        ((struct Obj00047 *)p)->f178, ((struct Obj00047 *)p)->f1B4, &b, 0, ((struct Obj00047 *)p)->f0);
    func_0204B92C((struct Obj *)((struct Obj00047 *)p)->f1D8, 1);
    func_0204B92C((struct Obj *)((struct Obj00047 *)p)->f1DC, 1);
    func_0204B3DC((struct Obj *)((struct Obj00047 *)p)->f1D8, 0);
    func_0204B3DC((struct Obj *)((struct Obj00047 *)p)->f1DC, 0);
    a.a = 0xe0;
    a.b = 0xa8;
    a.c = 1;
    a.d = 0;
    a.e = 0;
    x = (int)func_0204B294((void *)((struct Obj00047 *)p)->f1D4, ((struct Obj00047 *)p)->f1A0,
                      ((struct Obj00047 *)p)->f17C, ((struct Obj00047 *)p)->f1BC, &a, 0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1E0 = x;
    func_0204B92C((struct Obj *)x, 1);
    a.a = 0xc4;
    a.c = 0;
    x = (int)func_0204B294((void *)((struct Obj00047 *)p)->f1D4, ((struct Obj00047 *)p)->f1A0,
                      ((struct Obj00047 *)p)->f17C, ((struct Obj00047 *)p)->f1BC, &a, 0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1E4 = x;
    func_0204B92C((struct Obj *)x, 1);
}


void func_021B71B0(unsigned p) { func_0204B3B4(((struct Obj01888 *)p)->f1E0); func_0204B3B4(((struct Obj01888 *)p)->f1E4); func_0204B3B4(((struct Obj01888 *)p)->f1D8); func_0204B3B4(((struct Obj01888 *)p)->f1DC); func_0204B1CC(((struct Obj01888 *)p)->f1D4); }



void func_021B71E4(char *p)
{
    ((struct Obj02767 *)p)->f138 = func_0201D7EC(0x17, 0, 0, 0, ((struct Obj02767 *)p)->f0);
    ((struct Obj02767 *)p)->f13C = func_0201D7EC(0x17, 3, 0, 0, ((struct Obj02767 *)p)->f0);
    ((struct Obj02767 *)p)->f134 = func_02045B38(0, 2, 0x9d, ((struct Obj02767 *)p)->f0);
    func_02049B40(0x17, 5, 0, 0x1c0, 0x20, ((struct Obj02767 *)p)->f0);
    func_02049B40(0x17, 5, 4, 0x1c0, 0x20, ((struct Obj02767 *)p)->f0);
    ((struct Obj02767 *)p)->f140 = func_0201C450(0x1800, ((struct Obj02767 *)p)->f0);
    func_0201DD68();
}


void func_021B7268(unsigned p) { func_0201C6EC((struct PrintSys *)(((struct Obj06209 *)p)->f140)); func_0201C4C0((struct PrintSys *)(((struct Obj06209 *)p)->f140)); func_02045C04((struct Rec *)(((struct Obj06209 *)p)->f134)); func_0201D83C(((struct Obj06209 *)p)->f13C); func_0201D83C(((struct Obj06209 *)p)->f138); }



/*
 * Graphics setup: loads BG/char/screen/palette data from archive 0x4c, the
 * 0x07 archive and the func_020275E4 archive into p's handle table
 * (p+0x178..0x1d0), then copies palette RAM 0x050000C0 back to p+0x40.
 * The second-archive loads still pass the first (closed) handle to
 * func_02049B68/02049658/020498F4, as the original does.  The 0x158 store
 * goes through a local: stored directly, the allocator rematerialises the
 * shared 0xc0 offset base instead of reloading its [sp+0xc] spill slot.
 */
void func_021B7298(u8 *p)
{
    void *h;
    void *h2;
    void *t;

    h = func_020490F4(0x4c, ((struct Obj00047 *)p)->f0);
    func_02049B68(h, 6, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    func_02049B68(h, 0, 0, 0x1a0, 0x20, ((struct Obj00047 *)p)->f0);
    func_02049658(h, 0xf, 3, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    func_020498F4(h, 0x14, 3, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    func_02049658(h, 0xc, 2, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    t = func_02049EF4(h, 0x12, 0, (void **)(p + 0x15c), ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f158 = t;
    func_02049B68(h, 5, 4, 0, 0, ((struct Obj00047 *)p)->f0);
    func_02049658(h, 0xe, 7, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    func_020498F4(h, 0x13, 7, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    *(u32 *)&((struct Obj00047 *)p)->f178 = func_0204AC18(h, 4, 0, 0, 0, 3, ((struct Obj00047 *)p)->f0);
    *(u32 *)&((struct Obj00047 *)p)->f198 = func_0204A6C8(h, 0xb, 0, 0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f19C = func_0204A6C8(h, 8, 0, 0, ((struct Obj00047 *)p)->f0);
    *(u32 *)&((struct Obj00047 *)p)->f1B4 = func_0204AF28(h, 0x17, 0x1a, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1B8 = func_0204AF28(h, 0x16, 0x19, ((struct Obj00047 *)p)->f0);
    func_02049238(h);

    h2 = func_020490F4(7, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f190 = func_0204ACEC(h2, func_0201BC3C(), 0, 0xc0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1D0 = func_0204AF28(h2, func_0201BC40(), func_0201BCB4(), ((struct Obj00047 *)p)->f0);
    func_02049238(h2);

    h2 = func_020490F4(func_020275E4(), ((struct Obj00047 *)p)->f0);
    func_02049B68(h, func_02027624(), 0, 0x160, 0x20, ((struct Obj00047 *)p)->f0);
    func_02049658(h, func_02027628(), 1, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    func_020498F4(h, func_02027630(), 1, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    func_020413B0(1, 0, 0, 0x40, 0x20, 0xb);
    ((struct Obj00047 *)p)->f18C = func_0204AC18(h2, func_02027758(), 0, 0xa0, 0, 1, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1B0 = func_0204A6C8(h2, func_0202775C(2), 0, 0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1CC = func_0204AF28(h2, func_02027760(2), func_02027764(2), ((struct Obj00047 *)p)->f0);
    *(u32 *)&((struct Obj00047 *)p)->f17C = func_0204AC18(h2, func_02027614(), 0, 0x120, 0, 3, ((struct Obj00047 *)p)->f0);
    *(u32 *)&((struct Obj00047 *)p)->f1A0 = func_0204A6C8(h2, func_02027618(), 0, 0, ((struct Obj00047 *)p)->f0);
    *(u32 *)&((struct Obj00047 *)p)->f1BC = func_0204AF28(h2, func_0202761C(2), func_02027620(2), ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f180 = func_0204AC18(h2, func_02027694(), 0, 0x60, 0, 1, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1A4 = func_0204A6C8(h2, func_02027698(), 0, 0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1C0 = func_0204AF28(h2, func_0202769C(2), func_020276A0(2), ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f188 = func_0204AC18(h2, func_020276B4(), 0, 0x80, 0, 1, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1AC = func_0204A6C8(h2, func_020276B8(), 0, 0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1C8 = func_0204AF28(h2, func_020276BC(2), func_020276C0(2), ((struct Obj00047 *)p)->f0);
    func_02049238(h2);
    func_02082A60((void *)0x050000C0, p + 0x40, 0x60);
}



void func_021B7624(char *p)
{
    u8 i;

    func_020307B0(((struct Obj20856 *)p)->f158);
    for (i = 0; i < 8; i++) {
        if (*(int *)(p + i * 4 + 0x178) != -1)
            func_0204ADA4(*(int *)(p + i * 4 + 0x178));
    }
    for (i = 8; i < 15; i++) {
        if (*(int *)(p + i * 4 + 0x178) != -1)
            func_0204A8D4(*(int *)(p + i * 4 + 0x178));
    }
    for (i = 15; i < 23; i++) {
        if (*(int *)(p + i * 4 + 0x178) != -1)
            func_0204AFD8(*(int *)(p + i * 4 + 0x178));
    }
}

#undef W

#define W(k) (*(u32 *)(p+(k)))


/*
 * lever: one named offset shared across the case 7/8 branch join.
 */
void func_021B7698(u8 *p)
{
    u32 old;
    int r,id,off;
    switch (TS(0x34)) {
    case 1:
        W(0x108)=func_021BBDEC((int)p,W(0x154),0,0x16,0x15,0);
        func_021B7B98(p); p[0xd]=2; return;
    case 22: case 23:
        W(0x108)=func_021BBDEC((int)p,W(0x154),0,0xc,0x15,0);
        W(0x10c)=func_021BBDEC((int)p,W(0x154),1,0x16,0x15,1);
        func_021B7B98(p); p[0xd]=2; return;
    case 0: case 6: case 9: case 14: case 16: case 18: case 21: case 25:
        func_021B7B98(p); p[0xd]=2; return;
    case 3:
        W(0x14)=0; func_021B7B98(p); p[0xd]=2; return;
    case 5:
        if (func_021BC1B4((short unsigned int *)p,(void *)HS(0x44))==1) {
            r=func_021BC1D0(p);
            if (r != -1) {
                W(0x2c)=r; W(0x38)=(u32)func_0201AB28((void *)TS(0),r);
                func_021BC350(p,0);
                func_021BE2B4((void *)W(0x38),HS(0x44),(int)0,HS(0x30),(u16)(((struct Obj00009 *)p)->f0));
                func_021BB2C0(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)));
                W(0x24)=1; p[0xd]=p[0xc]; p[0xc]=0;
                func_021BA670(p,HS(0x44)); return;
            }
            func_021BC2C8((int)p); p[0xd]=p[0xc]; p[0xc]=0; return;
        }
        if (func_021BA65C(p,HS(0x44)) != 0) {
            func_021B7B98(p); p[0xd]=2; return;
        }
        TS(0x40)=10;
        func_021BB7A4(p,(u32 *)W(0x150)); func_021BB97C((u16 *)p,W(0x150));
        func_021BB9AC((int)p,(u32)W(0x150),(u32)0,(u16)HS(0x44));
        func_021B9788(p,0xb3,1,(int)func_021B9E3C);
        func_021BB98C(p,W(0x150)); p[0xd]=p[0xc]; p[0xc]=0; return;
    case 7: case 8:
        W(0x2c)=TS(0x3c); W(0x38)=(u32)func_0201AB28((void *)TS(0),TS(0x3c));
        if (SD[0x48] < 4) {
            old=func_02017E1C((void *)W(0x38),SD[0x48]+0x36,0);
            off=0x150;
            func_021BB97C((u16 *)p,W(off)); func_021BB99C((int)p,W(off),0,W(0x38));
            func_021BB9CC((int)p,(u32)W(off),(u32)1,(u16)old);
            func_021B9788(p,0x28,1,(int)func_021BA004);
        } else {
            off=0x150;
            func_021BB97C((u16 *)p,W(off)); func_021BB9CC((int)p,(u32)W(off),(u32)1,(u16)HS(0x46));
            func_021B9788(p,0x23,0,(int)func_021B9F34);
        }
        func_021BB98C(p,W(off));
        p[0xd]=7; p[0xc]=0; W(0x14)=0;
        func_021BAFA0(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)),1); return;
    case 10:
        W(0x2c)=TS(0x3c); W(0x38)=(u32)func_0201AB28((void *)TS(0),TS(0x3c));
        if (HS(0x44) == 0) {
            TS(0x34)=0; func_021B7B98(p); p[0xd]=2;
        } else {
            old=func_02017E1C((void *)W(0x38),6,0);
            if (old == 0) {
                func_021BA624(p,(void *)W(0x38),HS(0x44));
                func_021BB2C0(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)));
                func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
                func_021BB9AC((int)p,(u32)W(0x150),(u32)1,(u16)HS(0x44));
                func_021BC24C(p,(void *)W(0x38),(u16)HS(0x44));
                func_021BC288((int)p,(int)((void *)W(0x38)),HS(0x44));
                if (func_021BDBF8(p,W(0x38))==1) {
                    func_021BDC3C((u32)p,(void *)W(0x38)); func_021B9788(p,0x56,1,(int)func_021BA4E4); W(0x264)=1;
                } else func_021B9788(p,0x56,1,(int)func_021B9E20);
                func_021BB98C(p,W(0x150)); TS(0x34)=0;
            } else {
                func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
                func_021BB9BC((int)p,W(0x150),1,(u16)old);
                func_021B9788(p,0x3a,0,(int)func_021BA098); func_021BB98C(p,W(0x150));
            }
        }
        p[0xd]=7; p[0xc]=0; W(0x14)=1;
        func_021BAFA0(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)),1); return;
    case 11: case 12:
        W(0x2c)=TS(0x3c); W(0x38)=(u32)func_0201AB28((void *)TS(0),TS(0x3c));
        old=func_02017E1C((void *)W(0x38),6,0);
        func_021BB97C((u16 *)p,W(0x150));
        if (old == 0) {
            id=0x56;
            func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9AC((int)p,(u32)W(0x150),(u32)1,(u16)HS(0x44));
        } else {
            id=0x40;
            func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9AC((int)p,(u32)W(0x150),(u32)1,(u16)old);
            func_021BB9AC((int)p,(u32)W(0x150),(u32)2,(u16)HS(0x44));
        }
        func_021BA624(p,(void *)W(0x38),HS(0x44));
        func_021BB2C0(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)));
        func_021BC24C(p,(void *)W(0x38),(u16)HS(0x44));
        func_021BC288((int)p,(int)((void *)W(0x38)),HS(0x44));
        if (func_021BDC5C(p,W(0x38))==1) {
            func_021BDCA0((u32)p,(void *)W(0x38)); func_021B9788(p,id,1,(int)func_021BA4E4); W(0x264)=2;
        } else if (TS(0x34)==11) func_021B9788(p,id,1,(int)func_021B9E3C);
        else func_021B9788(p,id,1,(int)func_021B9E20);
        func_021BB98C(p,W(0x150));
        if (TS(0x34)==11) TS(0x40)=10; else TS(0x34)=0;
        p[0xd]=7; p[0xc]=0; W(0x14)=1;
        break;
    }
}



/*
 * EXACT*: the listing extent's last two bytes (0x021B7CC2) are alignment
 * padding before the next function, not a follower.
 */
void func_021B7B98(u8 *p)
{
    func_020409B4(0);
    switch (((struct Obj20857 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f34) {
    case 0:
        func_021BB714(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0);
        func_021BB7E8(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 9);
        ((struct Obj00009 *)p)->f14 = 1;
        break;
    case 1:
        func_021BD4EC((char *)p);
        func_0204B3DC((struct Obj *)((struct Obj00009 *)p)->f1E0, 0);
        ((struct Obj00009 *)p)->f14 = 0;
        break;
    case 22:
    case 23:
        ((struct Obj00009 *)p)->f14 = 0;
        break;
    case 5:
    case 16:
        func_021BB714(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0);
        func_021BB7E8(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0xd);
        ((struct Obj00009 *)p)->f14 = 0;
        ((struct Obj00009 *)p)->f28 = 0;
        break;
    case 9:
    case 14:
        func_021BB714(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0);
        func_021BB7E8(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0xc);
        ((struct Obj00009 *)p)->f14 = 0;
        ((struct Obj00009 *)p)->f28 = 0;
        break;
    case 6:
        func_021BB714(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0);
        func_021BB7E8(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0xe);
        ((struct Obj00009 *)p)->f14 = 0;
        ((struct Obj00009 *)p)->f28 = 0;
        break;
    case 18:
        func_021BB714(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0);
        func_021BB7E8(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0x10);
        ((struct Obj00009 *)p)->f14 = 0;
        break;
    case 3:
    case 25:
        func_021BB714(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0);
        func_021BB7E8(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 9);
        ((struct Obj00009 *)p)->f14 = 0;
        break;
    case 21:
        func_021BB714(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0);
        func_021BB7E8(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0xa3);
        func_0204B3DC((struct Obj *)((struct Obj00009 *)p)->f1E0, 0);
        ((struct Obj00009 *)p)->f14 = 0;
        break;
    }
    func_021B8418(p);
}


#undef W

#undef W
#define W(k) (*(u32 *)(p+(k)))


void func_021B7CC4(u8 *p)
{
    u32 old,buf;
    int r;
    if (SD[0x63] == 1) { p[0xc]=0x13; return; }
    switch (TS(0x34)) {
    case 0: case 1: case 18: case 21: case 22: case 23: case 25:
        func_021B907C(p); func_020409B4(0); func_021B8180(p); return;
    case 5:
        if (func_021BC17C((short unsigned int *)p,HS(0x44)) == 1) {
            func_021B907C(p); func_021B8180(p); return;
        }
        if (func_021BDD78((void *)W(0x38),(u16)HS(0x44),0,(u16)(((struct Obj00009 *)p)->f0)) == 1) {
            r=func_021BC350(p,0);
            func_021BE2B4((void *)W(0x38),HS(0x44),(int)0,HS(0x30),(u16)(((struct Obj00009 *)p)->f0));
            if (r == 2) func_021BB200(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)),(u32)W(0x38),0);
            else if (r == 19 || r == 13) {
                func_021BB200(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)),(u32)W(0x38),0);
                func_020061E4(0x56f);
            } else {
                func_021BB2C0(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)));
                func_020061E4(0x56f);
            }
            func_021BA670(p,HS(0x44)); return;
        }
        if (HS(0x44)==0x1d2 && func_021BDCC0((char *)p,W(0x38))==1) {
            func_021BDD58((u32)p,(void *)W(0x38)); TS(0x40)=10; p[0xc]=14; W(0x264)=3; return;
        }
        func_021BC30C((int)p); return;
    case 16:
        if (func_021B9BF4(p,(void *)W(0x38),HS(0x44)) != 0) {
            func_021BA670(p,HS(0x44)); p[0xc]=19; TS(0x3c)=W(0x2c); TS(0x40)=8;
        } else func_021B9788(p,0x51,1,(int)func_021B9E3C);
        return;
    case 9:
        old=func_02017E1C((void *)W(0x38),6,0);
        if (old == 0) {
            if (func_0202136C(HS(0x44)) == 1) {
                p[0xc]=19; TS(0x3c)=W(0x2c); TS(0x40)=6; return;
            }
            TS(0x40)=10;
            func_021BA624(p,(void *)W(0x38),HS(0x44));
            func_021BB2C0(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)));
            func_021BB97C((u16 *)p,W(0x150));
            func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9AC((int)p,W(0x150),1,HS(0x44));
            func_021BC24C(p,(void *)W(0x38),(u16)HS(0x44));
            func_021BC288((int)p,(int)((void *)W(0x38)),HS(0x44));
            if (func_021BDBF8(p,W(0x38)) == 1) {
                func_021BDC3C((u32)p,(void *)W(0x38));
                func_021B9788(p,0x56,1,(int)func_021BA4E4); W(0x264)=1;
            } else func_021B9788(p,0x56,1,(int)func_021B9E3C);
            func_021BB98C(p,W(0x150)); return;
        }
        if (func_0202136C(old)==1) {
            TS(0x40)=10; func_021B9788(p,0x39,1,(int)func_021B9E3C); return;
        }
        func_021BB97C((u16 *)p,W(0x150));
        func_021BB99C((int)p,W(0x150),0,W(0x38));
        func_021BB9BC((int)p,W(0x150),1,(u16)old);
        func_021B9788(p,0x3a,0,(int)func_021BA098);
        func_021BB98C(p,W(0x150)); return;
    case 14:
        if (func_02017E1C((void *)W(0x38),6,0) == 0) {
            buf=(u32)func_02009050((void *)TS(8),0,HS(0x5c),((struct Obj00009 *)p)->f0);
            func_02017E40((void *)W(0x38),0xa7,buf); func_020307B0((void *)buf);
            func_02017E40((void *)W(0x38),6,HS(0x44));
            func_0200902C((void *)TS(8),0,HS(0x5c));
            func_021B9788(p,0x62,1,(int)func_021B9E3C);
        } else func_021B9788(p,0x63,1,(int)func_021B9E3C);
        return;
    case 6:
        switch ((u32)func_021B9AC8(p,(void *)W(0x38),TS(0x3c))) {
        case 0:
            TS(0x40)=10;
            func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9CC((int)p,W(0x150),1,HS(0x46));
            func_021B9788(p,0x29,1,(int)func_021B9E3C); func_021BB98C(p,W(0x150));
            func_021BA5B4(p,(void *)W(0x38)); func_021BA60C(p,(void *)W(0x38)); return;
        case 1:
            func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9CC((int)p,W(0x150),1,HS(0x46));
            func_021B9788(p,0x20,0,(int)func_021B9EB0); func_021BB98C(p,W(0x150)); return;
        case 2:
            TS(0x40)=10;
            func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9CC((int)p,W(0x150),1,HS(0x46));
            func_021B9788(p,0x2a,1,(int)func_021B9E3C); func_021BB98C(p,W(0x150)); return;
        case 3:
            TS(0x40)=10;
            func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9CC((int)p,W(0x150),1,HS(0x46));
            func_021B9788(p,0x2b,1,(int)func_021B9E3C); func_021BB98C(p,W(0x150)); return;
        }
        return;
    case 3:
        p[0xc]=19; TS(0x3c)=W(0x2c); TS(0x40)=0; return;
    default:
        func_021B907C(p); func_021B8180(p); return;
    }
}


#undef W

#undef W

#define W(o) (*(u32 *)(p + (o)))



/*
 * EXACT*: the extent's last two bytes (0x021B83D6) are alignment padding.
 * func_021BBAF8 is declared with a third argument: this caller loads
 * `add r2, sp, #0` (the 32-byte buf) before the bl.  The switch value is
 * signed (bgt/blt compare tree).
 */
void func_021B8180(u8 *p)
{
    int buf[8];

    func_020409B4(0);
    switch (((struct Obj20858 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f34) {
    case 0:
        if (func_021BB468((int)p, (int *)(*(u32 *)(p + W(0x2c) * 4 + 0x160))) == 1) {
            buf[1] = 3;
            buf[2] = 6;
            buf[0] = 0;
            buf[3] = 0x10;
        } else {
            buf[1] = 1;
            buf[2] = 3;
            buf[3] = 4;
            buf[0] = 0;
            buf[4] = 6;
            buf[5] = 0x10;
            if (func_0202136C(func_02017E1C((void *)W(0x38), 6, 0)) == 1) {
                buf[3] = 5;
            }
        }
        func_021BB97C((u16 *)p, W(0x150));
        func_021BB99C((int)p, W(0x150), 0, W(0x38));
        func_021BB714(p, (u32 *)W(0x150), 2);
        func_021BB7E8(p, (u32 *)W(0x150), 0x12);
        func_021BB98C(p, W(0x150));
        break;
    case 1:
    case 22:
    case 23:
        if (func_021BB468((int)p, (int *)(*(u32 *)(p + W(0x2c) * 4 + 0x160))) == 1) {
            buf[0] = 0;
            buf[1] = 6;
            buf[2] = 0x10;
        } else {
            buf[0] = 8;
            buf[1] = 0;
            buf[2] = 6;
            buf[3] = 0x10;
        }
        func_021BB97C((u16 *)p, W(0x150));
        func_021BB99C((int)p, W(0x150), 0, W(0x38));
        func_021BB714(p, (u32 *)W(0x150), 2);
        func_021BB7E8(p, (u32 *)W(0x150), 0x12);
        func_021BB98C(p, W(0x150));
        break;
    case 5:
        buf[0] = 2;
        buf[1] = 6;
        buf[2] = 0x10;
        func_021BB97C((u16 *)p, W(0x150));
        func_021BB99C((int)p, W(0x150), 0, W(0x38));
        func_021BB714(p, (u32 *)W(0x150), 2);
        func_021BB7E8(p, (u32 *)W(0x150), func_021BC228((int)p, ((struct Obj20859 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f44));
        func_021BB98C(p, W(0x150));
        break;
    case 18:
        if (func_021BB468((int)p, (int *)(*(u32 *)(p + W(0x2c) * 4 + 0x160))) == 1) {
            buf[1] = 6;
            buf[0] = 0;
            buf[2] = 0x10;
        } else {
            buf[0] = 7;
            buf[2] = 6;
            buf[1] = 0;
            buf[3] = 0x10;
        }
        func_021BB97C((u16 *)p, W(0x150));
        func_021BB99C((int)p, W(0x150), 0, W(0x38));
        func_021BB714(p, (u32 *)W(0x150), 2);
        func_021BB7E8(p, (u32 *)W(0x150), 0x12);
        func_021BB98C(p, W(0x150));
        break;
    case 21:
        if (func_021BB468((int)p, (int *)(*(u32 *)(p + W(0x2c) * 4 + 0x160))) == 1) {
            buf[0] = 0xb;
            buf[2] = 6;
            buf[3] = 0x10;
            buf[1] = 0;
            func_021BB714(p, (u32 *)W(0x150), 2);
            func_021BB7E8(p, (u32 *)W(0x150), 0xa2);
        } else {
            buf[1] = 6;
            buf[2] = 0x10;
            buf[0] = 0;
            func_021BB97C((u16 *)p, W(0x150));
            func_021BB99C((int)p, W(0x150), 0, W(0x38));
            func_021BB714(p, (u32 *)W(0x150), 2);
            func_021BB7E8(p, (u32 *)W(0x150), 0x12);
            func_021BB98C(p, W(0x150));
        }
        break;
    case 25:
        if (func_021F6744((void *)W(0x38)) == 1) {
            buf[0] = 0xb;
            buf[1] = 0;
            buf[2] = 6;
            buf[3] = 0x10;
        } else {
            buf[0] = 0;
            buf[1] = 6;
            buf[2] = 0x10;
        }
        func_021BB97C((u16 *)p, W(0x150));
        func_021BB99C((int)p, W(0x150), 0, W(0x38));
        func_021BB714(p, (u32 *)W(0x150), 2);
        func_021BB7E8(p, (u32 *)W(0x150), 0x12);
        func_021BB98C(p, W(0x150));
        break;
    default:
        buf[0] = 0;
        buf[1] = 6;
        buf[2] = 0x10;
        break;
    }
    func_021BBAF8(p, (u8 *)W(0x154), buf);
}



void func_021B83D8(u8 *p)
{
    switch (p[0xe]) {
    case 0:
        p[0xe] = 1;
        p[0xf] = 4;
        break;
    case 1:
        func_021B8A8C(p);
        break;
    case 2:
        if (p[0xc] == 3) {
            func_021B86D8(p);
        } else if (p[0xc] == 4) {
            func_021B8758(p);
        } else {
            func_021B8508(p);
        }
        break;
    }
}


#undef W

#undef W

#define W(o) (*(int *)(p + (o)))



/*
 * The extent's last two bytes are alignment padding (00 00), not a follower.
 */
void func_021B8418(u8 *p)
{
    W(0x2c) = *(int *)(W(0x280) + 0x3c);
    p[0xe] = 0;
    W(0x3c) = 0x17;
    if (func_021B9A84((u32)p) == 1) {
        func_021BBE5C(W(0x108), 0);
        func_021BBE5C(W(0x10c), 0);
    }
    if (W(8) == 0) {
        if (W(0x2c) <= 5) {
            func_021B8F68(p, W(0x2c));
            func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 1);
        } else {
            func_021BBE5C(*(int *)(p + (u8)(W(0x2c) - 6) * 4 + 0x108), 1);
        }
    } else {
        func_0204B3DC((struct Obj *)W(0x1d8), 0);
        if (W(0x2c) <= 5) {
            if (p[0xc] == 3) {
                func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 1);
            } else {
                func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 0);
            }
        } else {
            func_021BBE5C(*(int *)(p + (u8)(W(0x2c) - 6) * 4 + 0x108), 0);
        }
    }
    func_0204B3DC((struct Obj *)W(0x1e4), W(0x14));
    if (func_021B9A84((u32)p) == 1 || func_021B9AB4(p) == 0) {
        func_0204B3DC((struct Obj *)W(0x1e0), 0);
    } else {
        func_0204B3DC((struct Obj *)W(0x1e0), 1);
    }
}


#undef W

#undef W

#define W(o) (*(int *)(p + (o)))



/*
 * Case bodies are laid out 3, 0, 1, 2: case 3 is written first.
 */
void func_021B8508(u8 *p)
{
    u8 i;
    u8 k;
    int n;

    func_021BB7A4(p, (u32 *)W(0x150));
    if (func_021B9A84((u32)p) == 1) {
        func_02041300(0, 0, 0, 0x15, 0x20, 3, 0x10);
        for (i = 0; i < 6; i++) {
            ((u8 *)W(0x280))[i + 0x49] = 0;
        }
        for (k = 0; k < 6; k++) {
            n = func_021BB43C((int *)(*(int *)(p + k * 4 + 0x160)));
            if (n <= 5) {
                ((u8 *)W(0x280))[n + 0x49] = k + 1;
            }
        }
    }
    switch (p[0xf]) {
    case 3:
        func_0204B3DC((struct Obj *)W(0x1d8), 0);
        W(0x38) = (int)func_0201AB28(*(void **)W(0x280), W(0x2c));
        *(int *)(W(0x280) + 0x3c) = W(0x2c);
        func_020061E4(0x54c);
        func_021B7CC4(p);
        return;
    case 0:
        if (func_021B9A84((u32)p) == 1) {
            func_021B892C(p);
            return;
        }
        p[0xc] = 0x13;
        *(int *)(W(0x280) + 0x3c) = 6;
        *(int *)(W(0x280) + 0x40) = 0;
        func_020061E4(0x54c);
        return;
    case 1:
        if (W(0x2c) <= 5) {
            func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 0);
            func_0204B3DC((struct Obj *)W(0x1d8), 0);
        }
        if (func_021B9A84((u32)p) == 1) {
            func_021BBE5C(W(0x108), 0);
            func_021BBE68(W(0x10c), 1);
            p[0xc] = 0xc;
            W(0x2c) = 7;
        } else {
            p[0xc] = 0x13;
            W(0x1e8) = W(0x1e0);
            func_0204B878((struct Obj *)W(0x1e8), 9);
        }
        *(int *)(W(0x280) + 0x3c) = 7;
        *(int *)(W(0x280) + 0x40) = 0;
        func_020061E4(0x551);
        return;
    case 2:
        if (W(0x2c) <= 5) {
            func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 0);
            func_0204B3DC((struct Obj *)W(0x1d8), 0);
        }
        p[0xc] = 0x13;
        *(int *)(W(0x280) + 0x3c) = 8;
        *(int *)(W(0x280) + 0x40) = 0;
        func_020061E4(0x556);
        W(0x1e8) = W(0x1e4);
        func_0204B878((struct Obj *)W(0x1e8), 8);
        return;
    }
}


#undef W

#undef W

#define W(o) (*(int *)(p + (o)))



void func_021B86D8(u8 *p)
{
    func_021BB7A4(p, (u32 *)W(0x150));
    if (p[0xf] == 3 && W(0x2c) == W(0x30)) {
        p[0xf] = 1;
    }
    if (p[0xf] != 1) {
        if (p[0xf] == 3) {
            func_021B9968(p);
        }
    } else {
        W(0x38) = 0;
        p[0xc] = 2;
        func_021B8F68(p, W(0x2c));
        func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x30) * 4 + 0x160)), 0);
        func_0204B3DC((struct Obj *)W(0x1dc), 0);
        W(0x30) = 9;
        *(int *)(W(0x280) + 0x3c) = W(0x2c);
        func_021B7B98(p);
        func_020061E4(0x551);
    }
}


#undef W

#undef W

#define W(o) (*(u32 *)(p + (o)))



void func_021B8758(u8 *p)
{
    u32 a, b;
    void *o;
    u32 c, d, e;

    func_021BB7A4(p, (u32 *)W(0x150));
    if (p[0xf] == 3) {
        W(0x38) = (u32)func_0201AB28((void *)*(u32 *)W(0x280), W(0x2c));
        a = func_02017E1C((void *)W(0x38), 0xa0, 0);
        b = func_02017E1C((void *)W(0x38), 0xa1, 0);
        if (W(0x2c) == W(0x34) || a == 0 || b == a) {
            func_021B9788(p, 0x64, 1, (int)func_021B9E20);
            func_021B8F68(p, W(0x2c));
            func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x34) * 4 + 0x160)), 0);
            func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 0);
            func_0204B3DC((struct Obj *)W(0x1dc), 0);
            ((u32 *)W(0x280))[0x3c / 4] = W(0x2c);
            return;
        }
        func_021BB2C0(p, (u8 *)(*(u32 *)(p + W(0x2c) * 4 + 0x160)));
        W(0x38) = (u32)func_0201AB28((void *)*(u32 *)W(0x280), W(0x2c));
        p[0xc] = 10;
        ((struct Obj00009 *)p)->f11C = func_021BB464((int)p, (short unsigned int *)(*(u32 *)(p + W(0x2c) * 4 + 0x160)));
        W(0x120) = (u32)func_021BA288;
        func_021B8F68(p, W(0x2c));
        func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x34) * 4 + 0x160)), 0);
        func_0204B3DC((struct Obj *)W(0x1dc), 0);
        o = func_0201AB28((void *)*(u32 *)W(0x280), W(0x34));
        c = func_02017E1C(o, 0xa1, 0);
        d = func_02017E1C(o, 0xa0, 0);
        e = c / 5;
        if (a + e > b) {
            func_02017E40(o, 0xa0, d - (b - a));
        } else {
            func_02017E40(o, 0xa0, d - e);
        }
        ((u32 *)W(0x280))[0x3c / 4] = W(0x2c);
        W(0x2c) = W(0x34);
        func_021BB2C0(p, (u8 *)(*(u32 *)(p + W(0x2c) * 4 + 0x160)));
        func_020061E4(0x56f);
        return;
    }
    W(0x38) = 0;
    p[0xc] = 2;
    func_021B8F68(p, W(0x2c));
    func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x34) * 4 + 0x160)), 0);
    func_0204B3DC((struct Obj *)W(0x1dc), 0);
    W(0x34) = 9;
    ((u32 *)W(0x280))[0x3c / 4] = W(0x2c);
    func_021B7B98(p);
    func_020061E4(0x551);
}


#undef W

#undef W

#define W(o) (*(u32 *)(p + (o)))



/*
 * The six-byte buffer is a block-scope initialised array
 * (an-initialised-local-array-takes-its-address-before-the-stores.md):
 * six assignments sink `add r7, sp, #4` below the stores.
 */
void func_021B892C(u8 *p)
{
    u8 *q;
    u8 i;
    int n;
    int r;

    q = (u8 *)((u32 *)W(0x280))[0x14 / 4];
    if (W(0x2c) != 6) {
        if ((int)W(0x2c) <= 5) {
            func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 0);
            func_0204B3DC((struct Obj *)W(0x1d8), 0);
        }
        W(0x2c) = 6;
    }
    ((u32 *)W(0x280))[0x3c / 4] = 6;
    {
        u8 buf[6] = {0, 0, 0, 0, 0, 0};
        for (i = 0; i < 6; i++) {
            n = func_021BB43C((int *)(*(int *)(p + i * 4 + 0x160)));
            if (n <= 5) {
                buf[n] = i + 1;
            }
        }
        r = func_02019E54((u32)q, *(u32 *)W(0x280), (u32)buf);
    }
    if (q[2] > p[0x105]) {
        func_021B9788(p, q[2] + 0x56, 1, (int)func_021B9E20);
        func_020061E4(0x557);
        return;
    }
    if (q[3] < p[0x105]) {
        func_021B9788(p, q[3] + 0x5c, 1, (int)func_021B9E20);
        func_020061E4(0x557);
        return;
    }
    if (r == 1) {
        func_021BB97C((u16 *)p, W(0x150));
        func_021BB9EC((int)p, W(0x150), 0, ((struct Obj06210 *)q)->f6, 3);
        func_021B9788(p, 0x92, 1, (int)func_021B9E20);
        func_020061E4(0x557);
        func_021BB98C(p, W(0x150));
        return;
    }
    if (r == 7) {
        func_021B9788(p, 0x94, 1, (int)func_021B9E20);
        func_020061E4(0x557);
        return;
    }
    func_021BBE5C(W(0x10c), 0);
    func_021BBE68(W(0x108), 1);
    p[0xc] = 0xc;
    ((u32 *)W(0x280))[0x3c / 4] = 6;
    ((u32 *)W(0x280))[0x40 / 4] = 0;
    W(0x118) = 1;
    func_020061E4(0x54c);
}


void func_021B8A8C(unsigned char *p) { func_021B8AC4(p); if(p[15]==4) func_021B8DB4(p); if(p[15]!=4) p[14]=2; if(*(unsigned char *)(*(unsigned *)&((struct Obj00009 *)p)->f280+99)==1) { p[14]=2; p[15]=1; } }


#undef W

#undef W

#define W(o) (*(int *)(p + (o)))



/*
 * The two byte tables resolve as sole-ref only without an overlay token
 * (with `ov091` the hint is reported contested).  The spilled locals sit
 * up @0, done @4, old @8, trg @0xc: declared trg, old, done, up.
 */
void func_021B8AC4(u8 *p)
{
    u32 trg;
    int old;
    int done;
    u32 up;
    u32 rep;
    int dir;
    int max;
    u8 cnt;
    int n;

    trg = func_020362DC();
    rep = func_0203633C();
    if (W(8) == 1 && func_0204B3F4((struct Obj *)W(0x1d8)) == 0) {
        if (trg != 0 && (trg & 0x402) == 0) {
            if (W(0x2c) <= 5) {
                func_021B8F68(p, W(0x2c));
                func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 1);
            } else {
                func_021BBE5C(*(int *)(p + (u8)(W(0x2c) - 6) * 4 + 0x108), 1);
                func_0204B3DC((struct Obj *)W(0x1d8), 0);
            }
            func_020061E4(0x548);
            W(8) = 0;
        }
    } else {
        dir = 0;
        if (trg != 0) {
            W(8) = 0;
        }
        up = rep & 0x40;
        if (up) {
            dir = -2;
        } else if (rep & 0x80) {
            dir = 2;
        } else if (rep & 0x20) {
            dir = -1;
        } else if (rep & 0x10) {
            dir = 1;
        } else if (trg & 1) {
            if (W(0x2c) == 6) {
                p[0xf] = 0;
            } else if (W(0x2c) == 7) {
                p[0xf] = 1;
            } else if (W(0x28) == 0 && func_021BB468((int)p, (int *)(*(int *)(p + W(0x2c) * 4 + 0x160))) == 1) {
                func_020061E4(0x557);
            } else {
                p[0xf] = 3;
            }
        }
        if (dir != 0) {
            old = W(0x2c);
            done = 0;
            if (func_021B9A84((u32)p) == 1) {
                if (func_021B9AA0((u32)p) == 1) {
                    max = 7;
                } else {
                    max = 6;
                }
            } else {
                max = 5;
            }
            if ((u32)(W(0x2c) - 6) <= 1 && (rep & 0xc0)) {
                cnt = func_0201AA18((void *)*(int *)W(0x280));
                if (up) {
                    if (W(0x2c) == 7 || func_021B9AA0((u32)p) == 0) {
                        W(0x2c) = d_021BEAB0[cnt - 1];
                    } else {
                        W(0x2c) = d_021BEAAA[cnt - 1];
                    }
                } else {
                    if (W(0x2c) == 7 || func_021B9AA0((u32)p) == 0) {
                        if (cnt > 1) {
                            W(0x2c) = 1;
                        } else {
                            W(0x2c) = 0;
                        }
                    } else {
                        W(0x2c) = 0;
                    }
                }
            } else {
                do {
                    n = W(0x2c) + dir;
                    if (n > max) {
                        if (max == 6 && dir > 1 && old != 6) {
                            W(0x2c) = max;
                        } else {
                            W(0x2c) = n - (max + 1);
                        }
                    } else if (n < 0) {
                        if (max == 6 && dir < 1) {
                            W(0x2c) = max;
                        } else {
                            W(0x2c) = dir + (W(0x2c) + (max + 1));
                        }
                    } else {
                        W(0x2c) += dir;
                    }
                    if (W(0x2c) > 5 || func_021BB3C4(p, *(int *)(p + W(0x2c) * 4 + 0x160)) == 1) {
                        done = 1;
                    }
                } while (done == 0);
            }
            if (old != W(0x2c)) {
                if (W(0x2c) <= 5) {
                    func_021B8F68(p, W(0x2c));
                    func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 1);
                } else {
                    func_021BBE5C(*(int *)(p + (u8)(W(0x2c) - 6) * 4 + 0x108), 1);
                    func_0204B3DC((struct Obj *)W(0x1d8), 0);
                }
                if (old <= 5) {
                    func_021BAFA0(p, (u8 *)(*(int *)(p + old * 4 + 0x160)), 0);
                } else {
                    func_021BBE5C(*(int *)(p + (u8)(old - 6) * 4 + 0x108), 0);
                }
                p[0x100] = 0xc;
            }
            func_020061E4(0x548);
        }
    }
    if (trg & 2) {
        if (func_021B9A84((u32)p) == 0 || func_021B9AA0((u32)p) == 1) {
            if (func_021B9AB4(p) == 1) {
                p[0xf] = 1;
                W(0x1e8) = W(0x1e0);
                func_0204B878((struct Obj *)W(0x1e8), 9);
                W(8) = 0;
            }
        }
    } else if ((trg & 0x400) && W(0x14) == 1) {
        p[0xf] = 2;
        W(0x1e8) = W(0x1e4);
        func_0204B878((struct Obj *)W(0x1e8), 8);
        W(8) = 0;
    }
}
