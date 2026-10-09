/*
 * file:     event_poke_status.c
 * unit:     yes
 * function: func_0215932C, func_02159340, func_02159370, func_02159398, func_021593B8, func_021593DC, func_021593F0, func_02159404, func_02159420, func_0215942C, func_0215944C, func_0215946C, func_0215948C, func_021594B0, func_021594E0, func_02159570, func_021595A0, func_021595CC, func_02159644, func_02159658, func_02159670, func_021596B4, func_021596E8, func_02159708, func_02159728, func_02159750, func_02159778, func_021597AC, func_021597CC, func_021597EC, func_0215980C, func_02159830, func_02159854, func_02159874, func_02159894, func_021598AC, func_021598C8, func_021598E4, func_021598EC, func_02159934, func_02159960, func_02159974, func_02159984, func_02159998, func_021599A8, func_02159A64, func_02159AE8, func_02159B10, func_02159B38, func_02159B48, func_02159B94, func_02159BBC, func_02159BC4, func_02159BD4, func_02159BF4, func_02159BF8, func_02159BFC, func_02159C00, func_02159C20, func_02159C2C, func_02159C48, func_02159C68, func_02159CC4, func_02159D04, func_02159D68, func_02159D84, func_02159DC8, func_02159DCC, func_02159DEC, func_02159E00, func_02159E60, func_02159E8C, func_02159F04, func_02159F28, func_02159F54, func_02159F80, func_02159F84, func_02159F94, func_02159FA8, func_02159FE0, func_0215A014, func_0215A048, func_0215A064, func_0215A07C, func_0215A0E8, func_0215A168, func_0215A214, func_0215A2E4, func_0215A370, func_0215A438, func_0215A460, func_0215A480, func_0215A490, func_0215A4A0, func_0215A4B4, func_0215A4C8, func_0215A4D8, func_0215A4EC, func_0215A500, func_0215A514, func_0215A554, func_0215A55C, func_0215A5A4, func_0215A5CC, func_0215A5D0, func_0215A5D4, func_0215A5D8, func_0215A5DC, func_0215A5E4, func_0215A5EC, func_0215A5F4, func_0215A5FC, func_0215A60C, func_0215A610, func_0215A614, func_0215A61C, func_0215A624, func_0215A630, func_0215A63C, func_0215A644, func_0215A64C, func_0215A654, func_0215A660, func_0215A66C, func_0215A678, func_0215A684, func_0215A6FC, func_0215A738, func_0215A760, func_0215A77C, func_0215A7F0, func_0215A864, func_0215A920, func_0215A954, func_0215A990, func_0215A9C0, func_0215AA24, func_0215AA34, func_0215AA48, func_0215AA4C, func_0215AA50, func_0215AA60, func_0215AA90, func_0215AABC, func_0215AADC, func_0215AAF4, func_0215AB18, func_0215AB3C, func_0215AB60, func_0215AB98, func_0215ABD0, func_0215ABEC, func_0215AC1C, func_0215AC3C, func_0215AC68, func_0215ACA8, func_0215ACC8, func_0215AD38, func_0215AD50, func_0215AD7C, func_0215ADCC, func_0215AE34, func_0215AEB8, func_0215AEE8, func_0215AF40, func_0215AF98, func_0215AFE0, func_0215AFF4, func_0215B014, func_0215B028, func_0215B068, func_0215B084, func_0215B0B4, func_0215B104, func_0215B138, func_0215B158, func_0215B190, func_0215B214, func_0215B26C, func_0215B2C4, func_0215B328, func_0215B350, func_0215B378, func_0215B3AC, func_0215B3DC, func_0215B408, func_0215B438, func_0215B464
 * address:  0x0215932C
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
 *   func_02011330   0x02011330  thumb
 *   func_0201137C  0x0201137C  thumb
 *   func_02011398  0x02011398  thumb
 *   func_0209C2B0  0x0209C2B0  arm
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_021589A0  0x021589A0  thumb  ov010
 *   func_0215AA4C  0x0215AA4C  thumb  ov010
 *   func_021587E0  0x021587E0  thumb  ov010
 *   func_0215AA34  0x0215AA34  thumb  ov010
 *   func_0215AA48  0x0215AA48  thumb  ov010
 *   func_0215AA24  0x0215AA24  thumb  ov010
 *   func_02158A34  0x02158A34  thumb  ov010
 *   func_020113D0  0x020113D0  thumb
 *   func_02011290  0x02011290  thumb
 *   func_0201134C  0x0201134C  thumb
 *   func_020113B0  0x020113B0  thumb
 *   d_021705DC     0x021705DC  data  ov010
 *   func_02012B38   0x02012B38  thumb
 *   func_02014474   0x02014474  thumb
 *   func_02014460  0x02014460  thumb
 *   func_02014314  0x02014314  thumb
 *   func_0201433C  0x0201433C  thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021B1BB8  0x021B1BB8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_021B1BE8  0x021B1BE8  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_020288C4  0x020288C4  thumb
 *   func_0202972C  0x0202972C  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159204 0x02159204 thumb ov010
 *   func_020362DC  0x020362DC  arm
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CCC  0x02188CCC  thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_02012DD0  0x02012DD0  thumb
 *   func_021A0F90  0x021A0F90  thumb  ov021
 *   func_021A153C  0x021A153C  thumb  ov021
 *   func_021A1548  0x021A1548  thumb  ov021
 *   func_021590FC  0x021590FC  thumb  ov010
 *   func_021D11D8  0x021D11D8  thumb
 *   func_021D1194  0x021D1194  thumb
 *   func_021590F4  0x021590F4  thumb  ov010
 *   func_02188C84  0x02188C84  thumb
 *   func_021D1164  0x021D1164  thumb
 *   func_021D11B0  0x021D11B0  thumb
 *   func_021A1524  0x021A1524  thumb  ov021
 *   func_021A1530  0x021A1530  thumb  ov021
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_02012DAC  0x02012DAC  thumb
 *   func_02158FE0   0x02158FE0  thumb  ov010
 *   func_0215901C   0x0215901C  thumb  ov010
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02030734  0x02030734  arm
 *   func_02082A7C  0x02082A7C  arm
 *   d_021728AC  0x021728AC  data
 *   func_02048F60  0x02048F60  arm
 *   func_02159D04  0x02159D04  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_02159D68  0x02159D68  thumb  ov010
 *   func_02159C2C  0x02159C2C  thumb  ov010
 *   func_02159B94  0x02159B94  thumb  ov010
 *   func_02082A48  0x02082A48  arm
 *   func_02082A90  0x02082A90  arm
 *   func_020490F4  0x020490F4  arm
 *   func_020493D4  0x020493D4  arm
 *   d_021728BC  0x021728BC  data
 *   func_0204944C  0x0204944C  arm
 *   func_02049238  0x02049238  arm
 *   d_02170FB0 0x02170FB0 data
 *   func_02012138  0x02012138  thumb
 *   func_0202E83C  0x0202E83C  thumb
 *   func_0215843C  0x0215843C  thumb  ov010
 *   func_020143CC  0x020143CC  thumb
 *   func_02159F04 0x02159F04 thumb ov010
 *   d_02170FF4 0x02170FF4 data a2
 *   d_02170FEC 0x02170FEC data
 *   d_02170FF0 0x02170FF0 data
 *   func_02014184 0x02014184 thumb
 *   func_02159F84  0x02159F84  thumb  ov010
 *   func_02159F80  0x02159F80  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   d_021728CC  0x021728CC  data
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_021BE92C  0x021BE92C  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02014910  0x02014910  thumb
 *   func_020145CC  0x020145CC  thumb
 *   ov131_id       0x00000083  data
 *   d_021DC800     0x021DC800  data  ov131
 *   func_020120B4  0x020120B4  thumb
 *   func_021589D0  0x021589D0  thumb  ov010
 *   func_02159124  0x02159124  thumb  ov010
 *   func_0202A230  0x0202A230  thumb
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_02012964  0x02012964  thumb
 *   d_021728E0     0x021728E0  data  ov010  a4
 *   func_02158F6C 0x02158F6C thumb ov010
 *   func_02045C04  0x02045C04  arm
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02197DA0  0x02197DA0  thumb
 *   func_02197DAC  0x02197DAC  thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02190A20  0x02190A20  thumb  ov021
 *   func_0201F91C  0x0201F91C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02045874  0x02045874  arm
 *   func_02190A64  0x02190A64  thumb  ov021
 *   func_02190ACC  0x02190ACC  thumb  ov021
 *   func_02190AC4  0x02190AC4  thumb  ov021
 *   func_02190AEC  0x02190AEC  thumb  ov021
 *   func_02190B08  0x02190B08  thumb  ov021
 *   func_02190988  0x02190988  thumb  ov021
 *   d_02171140     0x02171140  data  ov010  a4
 *   func_021909BC  0x021909BC  thumb
 *   func_02045808  0x02045808  arm
 *   func_021909E4 0x021909E4 thumb ov021
 *   func_02020D0C  0x02020D0C  thumb
 *   func_020202EC  0x020202EC  thumb
 *   func_02159190  0x02159190  thumb  ov010
 *   func_02191164  0x02191164  thumb  ov021
 *   func_02191184  0x02191184  thumb  ov021
 *   func_0215909C  0x0215909C  thumb  ov010
 *   func_021590D4  0x021590D4  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_020083E4  0x020083E4  thumb
 *   func_020083EC  0x020083EC  thumb
 *   func_02159B10   0x02159B10  thumb  ov010
 *   func_020056EC   0x020056EC  thumb
 *   func_0216F830  0x0216F830  thumb  ov010
 *   func_021690B4  0x021690B4  thumb  ov010
 *   func_021690F0  0x021690F0  thumb  ov010
 *   func_021690D0  0x021690D0  thumb  ov010
 *   func_021690E0  0x021690E0  thumb  ov010
 *   func_02169100  0x02169100  thumb  ov010
 *   func_02169110  0x02169110  thumb  ov010
 *   func_02012984  0x02012984  thumb
 *   func_02087D28 0x02087D28 arm
 *   func_02008550   0x02008550  thumb
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C234 0x0200C234 thumb
 *   func_0200C248  0x0200C248  thumb
 *   func_0203F4E4  0x0203F4E4  arm
 *   func_02012F5C  0x02012F5C  thumb
 *   func_02008A7C  0x02008A7C  thumb
 *   func_0200C258  0x0200C258  thumb
 *   func_020071EC  0x020071EC  thumb
 *   func_020071E4  0x020071E4  thumb
 *   func_0200723C  0x0200723C  thumb
 *   func_02012900  0x02012900  thumb
 *   func_02012AA0  0x02012AA0  thumb
 *   func_02012AE4  0x02012AE4  thumb
 *   func_0201289C  0x0201289C  thumb
 *   func_02159F28  0x02159F28  thumb  ov010
 *   func_02159CC4  0x02159CC4  thumb  ov010
 *   func_02012974  0x02012974  thumb
 *   func_02013B44  0x02013B44  thumb
 *   func_02159F54  0x02159F54  thumb  ov010
 *   func_020173F0  0x020173F0  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_0200D064  0x0200D064  thumb
 *   func_0200CED4  0x0200CED4  thumb
 *   func_0200D0CC  0x0200D0CC  thumb
 *   func_0200CF28  0x0200CF28  thumb
 *   func_0200CA28  0x0200CA28  thumb
 *   func_0200CA40  0x0200CA40  thumb
 *   func_02008428  0x02008428  thumb
 *   func_0201293C 0x0201293C thumb
 *   func_02007A68 0x02007A68 thumb
 *   func_020089C0  0x020089C0  thumb
 *   func_02008554  0x02008554  thumb
 *   func_02025C88  0x02025C88  thumb
 *   func_020089F4  0x020089F4  thumb
 *   func_02008A00  0x02008A00  thumb
 *   func_0200C308 0x0200C308 thumb
 *   func_0200C2F0   0x0200C2F0  thumb
 *   func_0200725C  0x0200725C  thumb
 *   func_020073D8  0x020073D8  thumb
 *   func_0200ECB4  0x0200ECB4  thumb
 *   func_020072A4  0x020072A4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_02162A74  0x02162A74  thumb  ov010
 *   func_02162708  0x02162708  thumb  ov010
 *   func_02162748  0x02162748  thumb  ov010
 *   func_0215F6E8  0x0215F6E8  thumb  ov010
 *   func_0215898C  0x0215898C  thumb  ov010
 *   func_02012A44 0x02012A44 thumb
 *   func_0216EFA8 0x0216EFA8 thumb ov010
 *   d_02171160 0x02171160 data a2
 */
#include "../../matched/include/Obj12274.h"
#include "../../matched/include/Obj05851.h"
#include "../../matched/include/Obj12031.h"
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj12037.h"
#include "../../matched/include/Obj12278.h"
#include "../../matched/include/Obj17651.h"
#include "../../matched/include/Obj17652.h"
#include "../../matched/include/Obj07280.h"
#include "../../matched/include/G_ov010_02170FEC.h"
#include "../../matched/include/Obj07281.h"
#include "../../matched/include/Obj04920.h"
#include "../../matched/include/Obj03073.h"
#include "../../matched/include/Obj05883.h"
#include "../../matched/include/Obj04882.h"
#include "../../matched/include/Obj17653.h"
#include "../../matched/include/Obj17654.h"
#include "../../matched/include/Obj17655.h"
#include "../../matched/include/Obj17656.h"
#include "../../matched/include/Obj17657.h"
#include "../../matched/include/Obj17658.h"
#include "../../matched/include/Obj17659.h"
#include "../../matched/include/Obj17660.h"
#include "../../matched/include/Obj17661.h"
#include "../../matched/include/Obj17662.h"
#include "../../matched/include/Obj17663.h"
#include "../../matched/include/Obj18787.h"
#include "../../matched/include/Obj18788.h"
#include "../../matched/include/Obj18789.h"
#include "../../matched/include/Obj18790.h"
#include "../../matched/include/Obj18791.h"
#include "../../matched/include/Obj18792.h"
#include "../../matched/include/Obj18793.h"
#include "../../matched/include/Obj05852.h"
#include "../../matched/include/Obj17665.h"
#include "../../matched/include/Obj18799.h"
#include "../../matched/include/Obj18800.h"
#include "../../matched/include/Obj04148.h"
#include "../../matched/include/Obj12038.h"
#include "../../matched/include/Obj12286.h"
#include "../../matched/include/Obj17666.h"
#include "../../matched/include/Obj17667.h"
#include "../../matched/include/Obj17686.h"
#include "../../matched/include/Obj17687.h"

struct Stream;
struct Ring;
struct BigObj;
struct Cursor;
struct Cur;
struct Sub02014444Obj;
struct Ctx;
struct Sys;
struct Sub02008C20Obj;
struct SaveBlock;
struct Rec44;
struct MapMatrix;
struct MatrixFile;
struct Obj_02159C48;
struct ArcFile;
struct Obj;
struct Desc;
struct Blk37;
struct Evt;
struct IcaAnime;
struct MsgBank;
struct Slot;
struct U16Vec;
struct WordSet;
struct Handle;
struct P;
struct Q_0215A9C0;
struct Big;
struct Sub02008700Obj;
struct OSOwnerInfoEx;
struct Sub0200852CObj;
struct Blk34;
struct Sub020089A8Obj;
struct RtcDate;
struct Sub020071E4Ctrl;
struct Rec1C;
struct Ctrl;
struct Sub020072A4Ctrl;
struct Sub020073D8Ctrl;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed int     s32;

struct P { int _0[3]; u8 _p[2]; u8 e; u8 _f[5]; u8 *cur; };

typedef unsigned long long u64;

struct MapMatrix {
    u16 field00;
    u16 zone_id;
    u32 matrix_id;
    u16 width;
    u16 height;
    u16 mode;
    u16 pad0e;
    u32 count;
    u16 zone_grid[900];
    u32 map_grid[900];
};

typedef struct Obj_02159BF4 {
    char pad[8];
    unsigned short f;
} Obj_02159BF4;

typedef struct Obj_02159BF8 {
    char pad[0xA];
    unsigned short f;
} Obj_02159BF8;

typedef struct Obj_02159BFC {
    char pad[0x10];
    int f;
} Obj_02159BFC;

typedef struct Obj_02159C48 {
    u16 f00;
    u16 f02;
    u32 pad04[3];
    u32 f10;
} Obj_02159C48;

struct MatrixFile {
    u16 mode;
    u16 pad02;
    u16 width;
    u16 height;
    u32 cells[];
};

typedef struct Obj_02159D68 {
    u16 f00;
    u16 pad02;
    void *f04;
    u32 f08;
    u8 f0c[1];
} Obj_02159D68;

typedef signed short   s16;

typedef struct Ent_02159C48 { u8 f00; u8 f01; u16 f02; u16 f04; } Ent_02159C48;

typedef struct Ent_02170FEC {
    u16 h0;
    u16 flag0 : 1;
    u16 flag1 : 1;
    u16 rest : 14;
    u16 h4;
    u16 h6_lo : 8;
    u16 h6_hi : 8;
    u16 h8;
    char pad[10];
} Ent_02170FEC;

typedef struct {
    void *f0;
    void *f4;
    u32 *f8;
    void *fC;
    u16 *f10;
    u16 *f14;
} Task;

typedef struct { u32 pad[15]; int f3c; } O8_0215A214;

typedef struct {
    void *f0;
    void *f4;
    O8_0215A214 *f8;
    void *fC;
    u16 *f10;
    u16 *f14;
} Ctx_0215A214;

typedef struct { u8 pad[0x11]; u8 f11; u8 f12; } O8_0215A370;

typedef struct {
    void *f0;
    void *f4;
    O8_0215A370 *f8;
    u16 *fC;
    u16 *f10;
} Ctx_0215A370;

typedef struct {
    int w[6];
} S24;


typedef signed char    s8;

typedef struct { int w[4]; } S16;

typedef struct { unsigned short id; S16 r; } T;

typedef struct {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k[8];
} Q_0215A77C;

typedef struct {
    unsigned short id;
    unsigned short pad[15];
    int pad20;
} P;

typedef struct {
    unsigned short a;
    unsigned short pad[5];
    int g;
    int h;
    int i;
    int j;
    int pad1c;
    int k[32];
} Q_0215A7F0;

typedef struct {
    int a0;
    int a1;
    unsigned short a2;
    unsigned short f1 : 3;
    unsigned short f2 : 4;
    int c3;
    unsigned short h8;
    unsigned short h9;
    int d5;
    int d6;
    int d7;
} L32;

typedef struct {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
    int pad8;
    int padc;
    int pad10;
    int pad14;
    int j;
    int k;
} Q_0215A864;

typedef struct {
    char pad[0x20];
    int k[8];
} Q_0215A9C0;

typedef struct Info { u8 language, color, month, day; u16 name[11], nameLength, comment[27], commentLength; u8 country, padding; } Info;

typedef struct {
    int a;
    int b;
    int c;
    int d;
} V4;

typedef struct {
    int w[7];
} V28;


extern u16 func_02011330(struct Stream *s);
extern int func_0201137C();
extern u32 func_02011398(struct Ring *r);
extern int func_0209C2B0();
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern int func_021589A0(int a, int b, int c);
extern u8 func_0215AA4C(void *p);
extern int func_021587E0(int a, int b);
extern int func_0215AA34(int a0);
extern void func_0215AA48(void *p, int v);
extern void *func_0215AA24(int a0);
extern void func_02158A34(void *, void *, int, int);
extern void func_020113D0(char *p, int val);
extern int func_02011290();
extern int func_0201134C();
extern int func_020113B0();
extern void func_020113B4(struct Ring *r, u32 v);
extern void *func_02012B38(const struct BigObj *p);
extern void func_02014474(void *, void *);
int func_02159670(struct P *p);
int func_021596B4(struct P *p);
int func_021596E8(void *a0, void *a1);
extern u8 func_02014460(struct Sub02014444Obj *o);
extern void func_02014314(char *, int);
extern void func_0201433C(char *a0, int a1);
extern u64 _u32_div_f(u32, u32);
extern int func_021B1BB8(int a, void *b);
extern void *func_020120F4(const struct Ctx *p);
extern void func_021B1BE8(int);
extern unsigned int func_02012A30(const struct BigObj *p);
extern s32 func_020288C4(struct Sys *s);
extern void *func_0202972C(void *a, u16 b);
extern void func_0215897C(void *vm, void *task);
extern void *func_02159204(void *);
extern u32 func_020362DC(void);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188CCC(void *);
extern u8 func_02012E40(const u8 *o);
extern int func_02012DD0(u8 *p);
extern u32 func_021A0F90(u8 *p);
extern int func_021A153C(u32 *p);
extern void func_021A1548(u32 *p);
extern u32 func_021590FC(void *p);
extern void func_021D11D8(int);
extern void func_021D1194(int);
extern void func_021590F4(void *p, u32 v);
extern int func_02188C84(void *);
extern int func_021D1164(int, void *);
extern void func_021D11B0(int);
extern void func_021A1524(u32 *p);
extern void func_021A1530(u32 *p);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern int func_02012DAC(int a0);
extern u16 *func_02158FE0(void *, void *, unsigned int);
int func_02159708(int a0, int a1);
int func_02159728(int a0, int a1);
int func_02159750(int a0, int a1);
int func_02159778(int a0, int a1);
/* * extent: two bytes of zero alignment padding at 0x021597CA. */ int func_021597AC(void *a, void *b);
int func_021597CC(int a0, int a1);
/* * extent: two bytes of zero alignment padding at 0x0215980A. */ int func_021597EC(void *a, void *b);
int func_0215980C(int a0, int a1);
/* * extent: two bytes of zero alignment padding at 0x02159852. * prototype: named runtime helper has opaque combined scalar return; * the original and compiled helper arguments are numerator r0, divisor r1. * low word is original r0 output, high word is original r1 remainder. * The original admits zero divisors. Direct helper call preserves that * behavior without expressing undefined C remainder on a zero divisor. * Fixed-flag run 1 proves u64 return in r0/r1: high-word extraction emits * no shift, and strh r1 immediately follows the original helper call. */ int func_02159830(void *a, void *b);
int func_02159854(int a0, int a1);
int func_02159874(int a0, int a1);
int func_02159894(int a0, int a1);
int func_021598AC(int a0, int a1);
int func_021598C8(int a0, int a1);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Tail call through a pool word and `bx r3`: a two-instruction * thunk into func_021B1BB8, the shape of the arm9 copy. * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_021598E4.c \ * --func func_021598E4 --addr 0x021598E4 --region ov010 --cc dsi/1.1p1 --thumb */ int func_021598E4(int a0, void *a1);
int func_021598EC(int a, int b);
/* * extent: two bytes of zero alignment padding at 0x0215995E. */ int func_02159934(void *a, void *b);
int func_02159960(int a0, int a1);
int func_02159974(char *p);
int func_02159984(int a0, int a1);
int func_02159998(char *p);
int func_021599A8(int a, int b);
int func_02159A64(int a, int b);
/* * Two record lookups on the second argument and a classification of the * first, submitted as three arguments. */ u16 *func_02159AE8(void *a0, void *a1);
extern unsigned int func_0215901C(void *a, void *b, unsigned int id);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082A7C(int, void *, int);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
void func_02159D04(struct MapMatrix *dst, const struct MatrixFile *src, u32 matrix_id, u16 zone_id);
extern u32 func_020307B0(void *p);
extern int func_02159D68(int x);
u16 func_02159BC4(const struct MapMatrix *m, u32 x, u32 y);
void sub_02159C00(struct MapMatrix *m, u32 width, u32 height);
/* * Same three-argument submission as its neighbour, aimed at the second * overlay handler. */ unsigned int func_02159B10(void *a0, void *a1);
int func_02159B38(int a0);
u16 *func_02159B48(int a);
int func_02159B94(int a0, int a1, u16 a2, int a3);
/* * Thumb tail call into ENV_SetResourceSet (ARM, 0x020307B0): `ldr r3, * [pc]` and `bx r3` plus the pool word, the shape of the arm9 copy * func_02011264. Unlabelled in the listing (no prologue, called only from * arm9), so it is emitted as data words. */ void func_02159BBC(void *ptr);
/* * Unlabelled leaf accessor (prints as .word): returns the field at +8. * Sole blocker of ov021 func_02189B30's MATCH. */ unsigned short func_02159BF4(Obj_02159BF4 *p);
/* * Unlabelled leaf accessor (prints as .word): returns the field at +0xA. * Sole blocker of ov021 func_02189B30's MATCH. */ unsigned short func_02159BF8(Obj_02159BF8 *p);
/* * Unlabelled leaf accessor (prints as .word): returns the field at +0x10. * Sole blocker of ov021 func_02189B30's MATCH. */ int func_02159BFC(Obj_02159BFC *p);
char *func_02159C20(char *p);
int func_02159C2C(struct Obj12037 *m, int x, int y);
extern void func_02082A48(u32 value, void *dst, u32 size);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void func_0204944C(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
extern void func_02049238(void *arc);
Obj_02159D68 *func_02159D84(int a, int b);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_02159DC8.c \ * --func func_02159DC8 --addr 0x02159DC8 --region ov010 --cc dsi/1.1p1 --thumb */ u32 func_02159DC8(void *p);
/* * Reads record n (16 bytes) from the archive at p+4 into p+0x1a through * func_0204944C, then returns the halfword read. */ u32 func_02159DCC(u8 *p, int n);
int func_02159DEC(struct Obj17652 *p);
int func_02159E00(u8 *a, u32 *b, u32 *c);
int func_02159E60(int x);
extern u32 func_02012138(const struct Ctx *p);
extern int func_0202E83C(void *a0);
extern int func_0215843C(void *p);
extern u32 func_020143CC(u32 a, u32 b);
void func_02159E8C(u8 *out, int obj);
Ent_02159C48 *func_02159F04(int unused, int x);
/* * extent: two bytes of zero alignment padding at 0x02159F52. */ void func_02159F28(int a, int b, int flag);
int func_02159F54(int a, int b);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Constant leaf: `movs r0, N; bx lr`. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_02159F80.c \ * --func func_02159F80 --addr 0x02159F80 --region ov010 --cc dsi/1.1p1 --thumb */ int func_02159F80(void);
int func_02159C48(struct Obj12037 *m, int a, int b);
void func_02159C68(Obj_02159C48 *a, int b, int c);
void func_02159CC4(u32 *a, int b, int c);
int func_02159F84(int a0);
/* * addressing: getter result converted to unsigned; scale/add modulo 32 bits * preserves the original muls/add address without assuming a valid array index. */ u16 func_02159F94(int a);
/* * extent: followed by independently matched ov010_func_02159FE0.c. * lever: const table declarations hoist the second table load before the stack argument. * prototype: both payload bytes come out of the halfword as bit fields, so the
 * u16 fifth input needs no extra truncation. */ void func_02159FA8(int a, int b);
extern void func_02014184(void *, int, int, int, int, int);
extern void *func_02012934(const struct BigObj *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_0200CA1C(void *a);
extern u32 func_0200CA38(struct Blk37 *p);
extern u32 func_0201AA18(void *p);
extern void *func_021BE8D4(void *, void *, int, int);
extern void *func_021BE92C(void *, void *, int, int, int, int, int);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_020144DC(int a0, int a1);
extern void *func_02014910(char *a0, int a1, int a2, int a3);
extern void *func_020145CC(void *);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern int func_021589D0(int);
extern char *func_02159124(char *p, int i);
extern u32 func_0202A230(void *a, u32 idx);
extern void *func_02158F54(void *p);
extern u32 func_02012964(const struct BigObj *p);
extern unsigned int func_02158F6C(void *);
extern int func_02045C04();
extern int func_02158F58(int a0);
extern int func_02197DA0();
extern int func_02197DAC();
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02082BCC(void *, int, int);
extern int func_02190A20(int, int);
extern unsigned int func_0201F91C(struct Slot *s);
extern void func_02045CAC(struct MsgBank *bank, unsigned int index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern struct U16Vec *func_02045874(struct U16Vec *src, unsigned int heapId);
extern int func_02190A64(u32 a, u32 b, u32 c, u32 d);
extern u32 func_02190ACC(u32 *obj, u32 *tab, u32 unused, u32 key);
extern unsigned func_02190AC4(void *p);
extern unsigned func_02190AEC(unsigned a, unsigned b, unsigned c, int d);
extern int func_02190B08(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 f);
extern struct Handle *func_02190988(u16 *a, const u8 *b, u32 c, u32 d, u32 x, u16 y, u16 z, u32 w);
extern int func_021909BC();
extern int func_02045808();
extern int func_021909E4(struct Handle *h);
extern u32 func_02020D0C(u8 *p);
extern void func_020202EC(struct Obj *obj, u16 *out);
extern int func_02159190(int);
extern void func_02191164(struct P *p);
extern void func_02191184(struct Q_0215A9C0 *q, u32 b, int c, u32 d);
extern void *func_0215909C(u8 *a);
extern int func_021590D4();
void func_0215A7F0(unsigned short *p, int a, int b, int c, struct U16Vec *s0, void *s1);
void func_0215A864(int *p);
int func_0215A920(int a0);
int func_0215A954(u8 *a);
int func_0215A990(u8 *a);
void func_0215A9C0(int a);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern int func_020083E4(unsigned short *p);
extern int func_020083EC();
extern u32 func_020056EC(u32 range);
extern int func_0216F830(void *save);
extern int func_021690B4(int a0);
extern int func_021690F0(int a0);
extern int func_021690D0(int a0);
extern int func_021690E0(int a0);
extern int func_02169100(int a0);
extern int func_02169110(int a0);
extern u8 func_02012984(const struct BigObj *p);
extern void func_02087D28(struct OSOwnerInfoEx *info);
int func_0215AA50(int a0, int a1);
/* * blocked: listing 48 compiled 46 */ int func_0215AA60(int a0, int a1);
/* * blocked: */ int func_0215AA90(int a0, int a1);
/* * Same slot overwrite, keyed off the second index helper and the * caller's second argument. */ int func_0215AABC(void *a0, void *a1);
int func_0215AADC(int a0, int a1);
int func_0215AAF4(int a0, int a1);
int func_0215AB18(int a0, int a1);
int func_0215AB3C(int a0, int a1);
int func_0215AB60(int a0, int a1);
int func_0215AB98(int a0, int a1);
int func_0215ABD0(int a0, int a1);
/* * extent: compiled 46 bytes; trailing 0x0215AC1A..0x0215AC1C is zero alignment. */ int func_0215ABEC(int a, int b);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_02012F08(int *p);
extern u32 func_0200C234(struct Blk34 *p, u32 bit);
extern void func_0200C248(struct Blk34 *p, u32 bit);
extern void func_0203F4E4(struct RtcDate *date);
extern void *func_02012F5C(void **h);
extern void func_02008A7C(struct Sub020089A8Obj *obj, u32 i, u32 a, u32 b, u32 c);
extern u32 func_0200C258(struct Blk34 *p);
extern unsigned char func_020071EC(const struct Sub020071E4Ctrl *ctrl);
extern u8 func_020071E4(const struct Sub020071E4Ctrl *ctrl);
extern void func_0200723C(int, unsigned *, unsigned *);
/* * The arm9 chain result is biased by the record's own 0x20 before the * halfword store. */ int func_0215AC1C(void *a0, void *a1);
/* * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained. */ int func_0215AC3C(int a,int b);
int func_0215AC68(int a, int b);
int func_0215ACA8(int a0, int a1);
int func_0215ACC8(int a, int b);
int func_0215AD38(int a0, int a1);
extern int func_02012900();
int func_0215AD50(int a0, int a1);
extern int *func_02012AA0(void);
extern u32 func_02012AE4(const struct Rec44 *p);
extern void func_0201289C(struct BigObj *p, const struct Rec1C *src);
int func_0215AD7C(int a, int b);
extern u32 func_02012974(const struct BigObj *p);
extern u32 func_02013B44(u32 id);
extern void *func_020173F0(u32 species, u32 level, u64 id, u32 heap);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern int func_0200D064();
extern int func_0200CED4();
extern u16 func_0200D0CC(struct Blk37 *p);
extern u16 func_0200CF28(struct Blk37 *p);
extern struct Blk37 *func_0200CA28(struct Blk37 *p);
extern struct Blk37 *func_0200CA40(struct Blk37 *p);
extern int func_02008428(unsigned short *p);
extern u32 func_0201293C(const struct BigObj *p);
extern void func_02007A68(void *save, u32 bits);
extern struct Sub020089A8Obj *func_020089C0(void *sys);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u32 func_02025C88(u32 x);
extern u8 func_020089F4(const struct Sub020089A8Obj *obj);
extern struct Sub020089A8Obj *func_02008A00(struct Sub020089A8Obj *obj);
extern u8 func_0200C308(struct Blk34 *p, u32 i);
extern void func_0200C2F0(struct Blk34 *p, u32 i, u8 v);
extern u32 func_0200725C(struct Ctrl *ctrl, u32 id, u8 heap);
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern u32 func_0200ECB4(char *o);
extern void func_020072A4(struct Sub020072A4Ctrl *ctrl, u32 id);
extern u32 func_02012844(const struct BigObj *p);
extern int func_02162A74(int, int, u16, u16, u16);
extern void func_02162708(struct Ctx *c, u32 idx, u16 a, u32 b, u16 e);
extern int func_02162748(int, int, int, u16, int, u16);
extern void *func_0215F6E8(void *p);
extern int func_0215898C();
extern u32 func_02012A44(const struct BigObj *p);
extern int func_0216EFA8(int,int);
int func_0215ADCC(int a0, int a1);
int func_0215AE34(int a0, int a1);
int func_0215AEB8(int a0, int a1);
int func_0215AEE8(int a0, int a1);
int func_0215AF40(int a0, int a1);
int func_0215AF98(int a0, int a1);
int func_0215AFE0(int a0, int a1);
int func_0215AFF4(int a0, int a1);
int func_0215B014(int a0, int a1);
/* * blocked: */ int func_0215B028(int a0, int a1);
/* * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained. */ int func_0215B068(int a,int b);
int func_0215B084(int a,int b);
int func_0215B0B4(int a0, int a1);
int func_0215B104(int a,int b);
/* * The third argument of the arm9 pair call is the slot the overlay index * returned, with a literal one alongside. */ int func_0215B138(void *a0, void *a1);
int func_0215B158(int a,int b);
int func_0215B190(int a0, int a1);
int func_0215B214(int a0, int a1);
int func_0215B26C(int a0, int a1);
int func_0215B2C4(int a0, int a1);
int func_0215B328(int a0, int a1);
int func_0215B350(int a0, int a1);
int func_0215B378(int a0, int a1);
int func_0215B3AC(int a0, int a1);
int func_0215B3DC(int a,int b);
int func_0215B408(int a0, int a1);
int func_0215B438(int a,int b);
int func_0215B464(int a,int b);
int func_0215932C(unsigned int a, unsigned int b);
int func_02159370(u8 *p);
/* * Halfword out of the record the overlay looks up, classified through an * arm9 call, and the class byte stored back on the object. */ int func_02159398(void *a0, void *a1);
int func_021593B8(u8 *a, void *b);
int func_021593DC(int a0, int a1);
int func_021593F0(int a0, int a1);
int func_02159404(int a0, int a1);
int func_02159420(int a0);
/* * One arm9 getter read twice, folded with '+', written back * through the arm9 setter. */ int func_0215942C(void *a0);
/* * One arm9 getter read twice, folded with '-', written back * through the arm9 setter. */ int func_0215944C(void *a0);
int func_0215946C(void *a0);
int func_0215948C(int a0, int a1);
int func_021594B0(int a0, int a1);
int func_021594E0(int p);
int func_02159570(int a0, int a1, int a2);
int func_021595A0(int a0, int a1);
int func_021595CC(int a, int b);
int func_02159644(int a0, int a1);
int func_02159658(int a0, int a1, int a2);
/* * Unlabelled leaf (push {r4,r5} only, so disasm.py prints it as .word * data): a 1-based index lookup over a 17-entry, 0x14-byte table. * Callee of ov020 func_021857C0. */ int func_02159FE0(int v);
void func_0215A014(void *a, int b);
/* * evidence: owner commit f860957 supplies the matched ARM9 Thumb02014184 * witness. Recheck the caller against that witness; no owner C compiled. * prototype: owner's u16 id is widened to int here because original r1 * is passed unchanged without narrowing. Remaining payloads retain 32 bits. * prior: wave49 one MATCH; tu --suggest-split left caller OUT. */ void func_0215A048(void *a, int b, int c, unsigned d, u16 e);
int func_0215A064(int a0);
void *func_0215A07C(int a, u16 *b, u16 *c);
void *func_0215A0E8(int a, int b, int c, int d, unsigned short e);
void *func_0215A168(int a, int b, int c);
int func_0215A214(void *a, u32 *st, Ctx_0215A214 *c);
int func_0215A2E4(int a, int b, int c, int d, int e, int f, unsigned short g);
/* * Case 2 loads 0x00000083 from the pool: an absolute symbol (overlay id), * see docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md. */ int func_0215A370(void *a, u32 *st, Ctx_0215A370 *c);
void func_0215A438(int a, int b, S24 *src);
/* * Map a tick count onto a 3000/5000 ms window, truncated to 16 bits. * * Addresses are Black-image addresses. */ u32 func_0215A460(u32 a);
u16 func_0215A480(unsigned a);
/* * extent: includes unlabelled range-test func_0215A4A0; function-start seed. */ u16 func_0215A490(unsigned a);
int func_0215A4A0(unsigned a);
int func_0215A4B4(int a0);
int func_0215A4C8(int a0);
/* * interface: original narrows r1 by shift pairs; u16 extern preserves this. */ unsigned func_0215A4D8(void *a, unsigned b);
void func_0215A4EC(char *a, unsigned b);
void func_0215A500(char *a, unsigned b);
void *func_0215A514(int a, int heap);
void func_0215A554(void *a0, unsigned a1, unsigned a2, unsigned a3);
/* * lever: const source pointer hoists its copy before the destination id store. */ void *func_0215A55C(const S16 *src, int v);
int func_0215A5A4(int a0);
u16 func_0215A5CC(void *a0);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Halfword-field getter/setter, pool-free leaf. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_0215A5D0.c \ * --func func_0215A5D0 --addr 0x0215A5D0 --region ov010 --cc dsi/1.1p1 --thumb */ u16 func_0215A5D0(void *p);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_0215A5D4.c \ * --func func_0215A5D4 --addr 0x0215A5D4 --region ov010 --cc dsi/1.1p1 --thumb */ u32 func_0215A5D4(void *p);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_0215A5D8.c \ * --func func_0215A5D8 --addr 0x0215A5D8 --region ov010 --cc dsi/1.1p1 --thumb */ u32 func_0215A5D8(void *p);
void *func_0215A5DC(void *a0);
void *func_0215A5E4(void *a0);
/* * Getter: word at +0xc of the object whose pointer sits at +0x20. * * Addresses are Black-image addresses. */ void *func_0215A5EC(void *p);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Double dereference: one field load then a load through the resulting pointer. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_0215A5F4.c \ * --func func_0215A5F4 --addr 0x0215A5F4 --region ov010 --cc dsi/1.1p1 --thumb */ void *func_0215A5F4(void *p);
int func_0215A5FC(int a0);
/* * Reads the word field at +0x14. * * Addresses are Black-image addresses. */ u32 func_0215A60C(u8 *p);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Halfword-field getter/setter, pool-free leaf. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_0215A610.c \ * --func func_0215A610 --addr 0x0215A610 --region ov010 --cc dsi/1.1p1 --thumb */ u16 func_0215A610(void *p);
/* * Setter: word at +0xfc of the object whose pointer sits at +0x20. * * Addresses are Black-image addresses. */ void func_0215A614(u8 *p, u32 v);
int func_0215A61C(int a0);
/* * Setter: word at +0x100 of the object whose pointer sits at +0x20. * Unlabelled leaf (leaf of func_021B0480). */ void func_0215A624(u8 *p, u32 v);
/* * Getter: word at +0x100 of the object whose pointer sits at +0x20. * Unlabelled leaf (leaf of func_021B0480). */ u32 func_0215A630(u8 *p);
/* * Address of the block at +0xD4 inside the object at +0x20. */ u8 *func_0215A63C(u8 *p);
/* * Unlabelled leaf (setter through the pointer at +0x20), filed as a blocker * of ov021 func_021C459C / func_021C4628. */ void func_0215A644(void *p, u32 v);
/* * Unlabelled leaf, blocker of ov021 func_021C457C/func_021C4608: reads the word at +0x10 of the record held at +0x20. * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here, * ov010 holds this Thumb routine, and the ov021 callers already name ov010 * (ov010 is the overlay resident with ov021). * * Addresses are Black-image addresses. */ void *func_0215A64C(void *p);
/* * Getter: byte at +0x104 of the object whose pointer sits at +0x20. * Unlabelled leaf (leaf of func_021B03E4). */ u32 func_0215A654(u8 *p);
/* * Setter: byte at +0x104 of the object whose pointer sits at +0x20. * Unlabelled leaf (leaf of func_021B03E4). */ void func_0215A660(u8 *p, u32 v);
/* * Reads the byte at +0x105 of the object at +0x20. */ u8 func_0215A66C(u8 *p);
void func_0215A678(u8 *p, u8 v);
void func_0215A684(int *p, unsigned short v);
int func_0215A690(int *p);
int func_0215A6AC(int *p);
void func_0215A6B8(int *p, int v);
int func_0215A6C4(int *p);
void func_0215A6D0(int *p, int v);
void func_0215A6DC(int *p, int v);
u32 func_0215A6FC(u32 a0, u32 a1, u32 a2, u32 a3);
int func_0215A738(int a0);
/* * interface: original narrows r1/r2 by shift pairs; u16 extern preserves this. */ void func_0215A760(u8 *a, unsigned b, unsigned c);
void func_0215A77C(unsigned short *p, unsigned short a, unsigned short b, unsigned short c, unsigned short d, int e, int f, int g, int h);
extern u8 d_021705DC[][3];
extern const char d_021728AC[];
extern const char d_021728BC[];
extern Ent_02159C48 d_02170FB0[];
extern u16 d_02170FF4[][10];
extern const Ent_02170FEC d_02170FEC[];
extern const u16 d_02170FF0[][10];
extern const char d_021728CC[];
extern u8 ov131_id[];
extern u8 d_021DC800[];
extern int d_021728E0;
extern L32 d_02171140;
extern const u16 d_02171160[];






int func_0215932C(unsigned int a, unsigned int b)
{
    if (a < b) return 0;
    if (a == b) return 1;
    return 2;
}






static inline int ReadByte(u8 *p)
{
    int v = **(u8 * *)&((struct Obj12274 *)p)->f14;
    (*(u8 * *)&((struct Obj12274 *)p)->f14)++;
    return v;
}






/*
 * extent: two-byte zero alignment padding follows the 46-byte function.
 * lever: inline byte reader binds the load before incrementing the cursor;
 * a postincrement expression schedules the cursor store before the load.
 */
int func_02159340(u8 *p)
{
    u8 a, b;
    a = (*(u32 **)(p + 28))[ReadByte(p)];
    b = (*(u32 **)(p + 28))[ReadByte(p)];
    p[14] = func_0215932C(a, b);
    return 0;
}






int func_02159370(u8 *p)
{
    u8 a, b;
    a = (*(u32 **)(p + 28))[ReadByte(p)];
    b = ReadByte(p);
    p[14] = func_0215932C(a, b);
    return 0;
}













/*
 * Halfword out of the record the overlay looks up, classified through an
 * arm9 call, and the class byte stored back on the object.
 */
int func_02159398(void *a0, void *a1)
{
    u16 v = *func_02159AE8(a0, a1);

    *(u8 *)((char *)a0 + 0xE) = func_0215932C(v, func_02011330(a0));

    return 0;
}












int func_021593B8(u8 *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    u16 *q = func_02159AE8(a, b);
    a[14] = func_0215932C(*p, *q);
    return 0;
}













int func_021593DC(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
    a0 = func_02011330((struct Stream *)a0);
loc_021593E4:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0201137C(a0, a1);
loc_021593EC:
a0 = 0;
    return a0;}













int func_021593F0(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_021593F8:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0201137C(a0, a1);
loc_02159400:
a0 = 0;
    return a0;}













int func_02159404(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    u16 *q;

t5 = a0 + 0;
t6 = a1 + 0;
    a0 = func_02011398((struct Ring *)a0);
loc_0215940E:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_02159418:
*q = t4;
a0 = 0;
    return a0;}













int func_02159420(int a0)
{

    a0 = func_02011398((struct Ring *)a0);
loc_02159426:
a0 = 0;
    return a0;}













/*
 * One arm9 getter read twice, folded with '+', written back
 * through the arm9 setter.
 */
int func_0215942C(void *a0)
{
    int v = func_02011398(a0);
    int w = func_02011398(a0);

    func_0201137C(a0, w + v);

    return 0;
}













/*
 * One arm9 getter read twice, folded with '-', written back
 * through the arm9 setter.
 */
int func_0215944C(void *a0)
{
    int v = func_02011398(a0);

    func_0201137C(a0, func_02011398(a0) - v);

    return 0;
}











/*
 * One arm9 getter read twice, folded with '*', written back
 * through the arm9 setter.
 */
int func_0215946C(void *a0)
{
    int v = func_02011398(a0);
    int w = func_02011398(a0);

    func_0201137C(a0, w * v);

    return 0;
}











int func_0215948C(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
    a0 = func_02011398((struct Ring *)a0);
loc_02159494:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02011398((struct Ring *)a0);
loc_0215949C:
a1 = t4 + 0;
    a0 = func_0209C2B0(a0, a1);
loc_021594A2:
a1 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0201137C(a0, a1);
loc_021594AA:
a0 = 0;
    return a0;}











int func_021594B0(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_021594BC:
    a0 = func_0201296C(v0);
loc_021594C0:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_021594CA:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_020142E8((void *)a0, a1);
loc_021594D2:
a1 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0201137C(a0, a1);
loc_021594DA:
a0 = 0;
    return a0;}










int func_021594E0(int p)
{
    u32 a = func_02011398((struct Ring *)p);
    u32 b = func_02011398((struct Ring *)p);
    int r;
    switch (func_02011330((struct Stream *)p)) {
    case 0: r = (b < a) ? 1 : 0; break;
    case 1: r = (b == a) ? 1 : 0; break;
    case 2: r = (b > a) ? 1 : 0; break;
    case 3: r = (b <= a) ? 1 : 0; break;
    case 4: r = (b >= a) ? 1 : 0; break;
    case 5: r = (b != a) ? 1 : 0; break;
    case 6: r = (b == 1 || a == 1) ? 1 : 0; break;
    case 7: r = (b == 1 && a == 1) ? 1 : 0; break;
    default: r = 0; break;
    }
    func_0201137C((struct Ring *)p, r);
    return 0;
}










int func_02159570(int a0, int a1, int a2)
{
    int t4;
    int t5;
    void *v0;
    void *v1;

t5 = a1 + 0;
t4 = a0 + 0;
a0 = t5 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215957C:
a0 = t5 + 0;
    v1 = func_0215A5F4((void *)a0);
loc_02159582:
a0 = t4 + 0;
    a0 = func_02011330((struct Stream *)a0);
loc_0215958A:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02159B38(a0);
loc_02159592:
a1 = a0 + 0;
a2 = t4 + 0;
    a0 = func_021589A0((int)v1, a1, a2);
loc_0215959C:
a0 = 1;
    return a0;}










int func_021595A0(int a0, int a1)
{    int t5;
    void *v0;

t5 = a1 + 0;
a0 = t5 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_021595AA:
a0 = t5 + 0;
    a0 = func_0215AA4C((void *)a0);
loc_021595B2:
a1 = a0 + 0;
    a0 = func_021587E0((int)v0, a1);
loc_021595BA:
    if (a0 != 0) goto loc_021595C8;
loc_021595BE:
a0 = t5 + 0;
    a0 = func_0215AA34(a0);
loc_021595C4:
a0 = 1;
    return a0;
loc_021595C8:
a0 = 0;
    return a0;}









int func_021595CC(int a, int b)
{
    void *x = func_0215A5DC((void *)b);
    void *y = func_0215A5F4((void *)b);
    int z = func_02011330((struct Stream *)a);
    if (func_0215A5D4((void *)b) == 0) {
        func_0215AA48((void *)b, func_021589A0((int)y, func_02159B38(b), z));
        func_0215AA24(b);
        func_020113D0((char *)a, (int)func_021595A0);
        return 1;
    }
    func_0215AA24(b);
    func_02158A34(x, y, z, func_0215A5D8((void *)b));
    func_0215AA34(b);
    return 0;
}









int func_02159644(int a0, int a1)
{
    int t4;
    void *v0;

t4 = a0 + 0;
a0 = a1 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215964E:
a0 = t4 + 0;
    a0 = func_02011290(a0);
loc_02159654:
a0 = 1;
    return a0;}









int func_02159658(int a0, int a1, int a2)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0201134C(a0);
loc_02159660:
a2 = a0 + 0;
a1 = *(int *)&((struct Obj00005 *)t4)->f14;
a0 = t4 + 0;
a1 = a1 + a2;
    a0 = func_020113B0(a0, a1, a2);
loc_0215966C:
a0 = 0;
    return a0;}









int func_02159670(struct P *p)
{
    u8 *q = p->cur;
    u8 c = *q;
    int n;
    p->cur = q + 1;
    n = func_0201134C((struct Cursor *)p);
    if (c == 0xFF) {
        if (func_02011398((struct Ring *)p) == 1)
            goto end;
    } else {
        if (d_021705DC[c][p->e] != 1)
            goto end;
    }
    func_020113B0((struct Cur *)p, (u32)(p->cur + n));
end:
    return 0;
}

/*
 * prototype: 020113B4's matched ARM9 unit copies the full-word second
 * input unchanged into +0x14; original caller supplies a cursor address.
 * Pointer declaration preserves that payload and matches the fixed flags.
 */
int func_021596B4(struct P *p)
{
    u8 *q = p->cur;
    u8 c = *q;
    int n;
    p->cur = q + 1;
    n = func_0201134C((struct Cursor *)p);
    if (d_021705DC[c][p->e] == 1)
        func_020113B4((struct Ring *)p, (u32)(p->cur + n));
    return 0;
}


/*
 * The record's arm9 handle and the caller's second argument are the two
 * operands of the arm9 pair call.
 */
int func_021596E8(void *a0, void *a1)
{
    void *v = (void *)func_02011330(a0);

    func_02014474(func_02012B38(func_0215A5E4(a1)), v);

    return 0;
}



int func_02159708(int a0, int a1)
{
    int t5;
    void *p;
    u16 *q;
    void *v0;

t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_02159710:
a0 = t5 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_02159718:
    p = func_02012B38((const struct BigObj *)v0);
loc_0215971C:
    a0 = func_02014460(p);
loc_02159720:
*q = a0;
a0 = 0;
    return a0;}



int func_02159728(int a0, int a1)
{
    void *v0 = func_0215A5E4((void *)a1);
    char *p = (char *)func_0201296C(v0);
    int x = func_02159B10((void *)a0, (void *)a1);
    func_02014314(p, x);
    return 0;
}



int func_02159750(int a0, int a1)
{
    void *v0 = func_0215A5E4((void *)a1);
    char *p = (char *)func_0201296C(v0);
    int x = func_02159B10((void *)a0, (void *)a1);
    func_0201433C(p, x);
    return 0;
}



int func_02159778(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    int t7;
    u16 *q;
    void *v0;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_02159784:
    a0 = func_0201296C(v0);
loc_02159788:
t6 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_02159792:
t7 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215979C:
a0 = t6 + 0;
a1 = t7 + 0;
    a0 = func_020142E8((void *)a0, a1);
loc_021597A6:
*q = a0;
a0 = 0;
    return a0;}


/*
 * extent: two bytes of zero alignment padding at 0x021597CA.
 */
int func_021597AC(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    *p = *p + func_02159B10(a, b);
    return 0;
}



int func_021597CC(int a0, int a1)
{
    int t5;
    int t6;
    u16 *q;

t5 = a0 + 0;
t6 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_021597D6:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_021597E0:
a1 = *q;
a0 = a1 - a0;
*q = a0;
a0 = 0;
    return a0;}


/*
 * extent: two bytes of zero alignment padding at 0x0215980A.
 */
int func_021597EC(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    *p = *p * func_02159B10(a, b);
    return 0;
}



int func_0215980C(int a0, int a1)
{
    int t5;
    int t6;
    u16 *q;

t5 = a0 + 0;
t6 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_02159816:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_02159820:
a1 = a0 + 0;
a0 = *q;
    a0 = func_0209C2B0(a0, a1);
loc_02159828:
*q = a0;
a0 = 0;
    return a0;}


/*
 * extent: two bytes of zero alignment padding at 0x02159852.
 * prototype: named runtime helper has opaque combined scalar return;
 * the original and compiled helper arguments are numerator r0, divisor r1.
 * low word is original r0 output, high word is original r1 remainder.
 * The original admits zero divisors. Direct helper call preserves that
 * behavior without expressing undefined C remainder on a zero divisor.
 * Fixed-flag run 1 proves u64 return in r0/r1: high-word extraction emits
 * no shift, and strh r1 immediately follows the original helper call.
 */
int func_02159830(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    u32 divisor = func_02159B10(a, b);
    *p = (u32)(_u32_div_f(*p, divisor) >> 32);
    return 0;
}



int func_02159854(int a0, int a1)
{
    int t5;
    int t6;
    u16 *q;

t5 = a0 + 0;
t6 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215985E:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_02159868:
a1 = *q;
a0 = a0 & a1;
*q = a0;
a0 = 0;
    return a0;}



int func_02159874(int a0, int a1)
{
    int t5;
    int t6;
    u16 *q;

t5 = a0 + 0;
t6 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215987E:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_02159888:
a1 = *q;
a0 = a0 | a1;
*q = a0;
a0 = 0;
    return a0;}



int func_02159894(int a0, int a1)
{
    int t5;
    u16 *q;

t5 = a0 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215989C:
a0 = t5 + 0;
    a0 = func_02011330((struct Stream *)a0);
loc_021598A4:
*q = a0;
a0 = 0;
    return a0;}



int func_021598AC(int a0, int a1)
{
    int t5;
    int t6;
    u16 *q;
    u16 *dst;

t5 = a0 + 0;
t6 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_021598B6:
a0 = t5 + 0;
a1 = t6 + 0;
    dst = func_02159AE8((void *)a0, (void *)a1);
loc_021598C0:
a0 = *dst;
*q = a0;
a0 = 0;
    return a0;}



int func_021598C8(int a0, int a1)
{
    int t5;
    int t6;
    u16 *q;

t5 = a0 + 0;
t6 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_021598D2:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_021598DC:
*q = a0;
a0 = 0;
    return a0;}



/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_021B1BB8, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021598E4.c \
 *       --func func_021598E4 --addr 0x021598E4 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_021598E4(int a0, void *a1)
{
    return func_021B1BB8(a0, a1);
}



int func_021598EC(int a, int b)
{
    void *x = func_0215A5F4((void *)b);
    void *y = func_0215A5DC((void *)b);
    int h = (int)func_020120F4(y);
    int r = 0;
    func_021B1BE8(b);
    if (func_020288C4((struct Sys *)((int)func_02012A30((const struct BigObj *)h)))) {
        func_0215897C(x, func_0202972C(y, r));
        r = 1;
    }
    return r;
}


/*
 * extent: two bytes of zero alignment padding at 0x0215995E.
 */
int func_02159934(void *a, void *b)
{
    void *x = func_0215A5F4(b);
    void *t;
    func_0215A5DC(b);
    t = func_02159204(b);
    if (t == 0)
        return 1;
    func_0215897C(x, t);
    return 1;
}



int func_02159960(int a0, int a1)
{

    a0 = func_020362DC();
loc_02159966:
a1 = 3;
    if ((a0 & a1) == 0) goto loc_02159970;
loc_0215996C:
a0 = 1;
    return a0;
loc_02159970:
a0 = 0;
    return a0;}


int func_02159974(char *p)
{
    func_020113D0(p, (int)func_02159960);
    return 1;
}



int func_02159984(int a0, int a1)
{

    a0 = func_020362DC();
loc_0215998A:
a1 = 0xf3;
    if ((a0 & a1) == 0) goto loc_02159994;
loc_02159990:
a0 = 1;
    return a0;
loc_02159994:
a0 = 0;
    return a0;}


int func_02159998(char *p)
{
    func_020113D0(p, (int)func_02159984);
    return 1;
}



int func_021599A8(int a, int b)
{
    void *s4 = func_0215A5E4((void *)b);
    void *s0 = func_0215A5F4((void *)b);
    int h;
    int ret;
    h = func_02188CCC(func_0201210C(func_0215A5DC((void *)b)));
    if (func_02012E40(s4) == 0) {
        ret = 1;
        if (func_021A0F90((u8 *)h) == 7) {
            if (func_021A153C((u32 *)h) == 0)
                ret = 0;
        }
    } else {
        switch (func_02012DD0(s4)) {
        case 0:
        case 1:
            ret = 0;
            break;
        case 2:
            *func_02159AE8((void *)a, (void *)b) = 1;
            ret = 0;
            break;
        case 3:
            *func_02159AE8((void *)a, (void *)b) = 0;
            ret = 1;
            if (func_021A0F90((u8 *)h) == 7)
                func_021A1548((u32 *)h);
            break;
        }
    }
    if (ret == 1) {
        int t = func_021590FC(s0);
        func_021D11D8(t);
        func_021D1194(t);
        func_021590F4(s0, 0);
    }
    return ret;
}



int func_02159A64(int a, int b)
{
    void *s0 = func_0215A5F4((void *)b);
    void *s4 = func_0215A5E4((void *)b);
    int y, z, t;
    void *x;
    x = func_0201210C(func_0215A5DC((void *)b));
    y = func_02188C84(x);
    z = func_02188CCC(x);
    t = func_021D1164(y, x);
    func_021D11B0(t);
    if (func_021A0F90((u8 *)z) == 7) {
        func_021A1524((u32 *)z);
        func_021A1530((u32 *)z);
    }
    func_021590F4(s0, t);
    func_02008DF0(func_02012F2C(s4), 1);
    func_02012DAC((int)s4);
    func_020113D0((char *)a, (int)func_021599A8);
    return 1;
}



/*
 * Two record lookups on the second argument and a classification of the
 * first, submitted as three arguments.
 */
u16 *func_02159AE8(void *a0, void *a1)
{
    void *v = func_0215A5E4(a1);

    return func_02158FE0(func_0215A5F4(a1), v, func_02011330(a0));
}



/*
 * Same three-argument submission as its neighbour, aimed at the second
 * overlay handler.
 */
unsigned int func_02159B10(void *a0, void *a1)
{
    void *v = func_0215A5E4(a1);

    return func_0215901C(func_0215A5F4(a1), v, func_02011330(a0));
}



int func_02159B38(int a0)
{
    void *p;
    void *v0;

    v0 = func_0215A5E4((void *)a0);
loc_02159B3E:
    p = func_020127A4((struct SaveBlock *)v0);
loc_02159B42:
    a0 = func_02012AC8(p);
loc_02159B46:
    return a0;}



u16 *func_02159B48(int a)
{
    u16 *p = func_02030734(a, 0x152c, 1, d_021728AC, 0x4b);
    *p = a;
    func_02082A7C(-1, (u8 *)p + 0x71c, 0xe10);
    func_02082A7C(0xffff, (u8 *)p + 0x14, 0x708);
    return p;
}



int func_02159B94(int a0, int a1, u16 a2, int a3)
{
    void *file = func_02048F60(9, a1, a3);
    func_02159D04((struct MapMatrix *)a0, file, a1, a2);
    return func_020307B0(file);
}



/*
 * Thumb tail call into ENV_SetResourceSet (ARM, 0x020307B0): `ldr r3,
 * [pc]` and `bx r3` plus the pool word, the shape of the arm9 copy
 * func_02011264.  Unlabelled in the listing (no prologue, called only from
 * arm9), so it is emitted as data words.
 */
/*
 * Thumb tail call into ENV_SetResourceSet (ARM, 0x020307B0): `ldr r3,
 * [pc, #0]; bx r3` plus the pool word, the shape of the arm9 copy
 * func_02011264.  Unlabelled in the listing (no prologue, called only from
 * arm9), so it is emitted as data words.
 */
void func_02159BBC(void *ptr)
{
    func_020307B0(ptr);
}



/*
 * Read one cell of the matrix object's zone grid: the u16 array at +0x14,
 * row-major over the object's own width at +0x08.  Leaf, no relocations.
 *
 * The companion grid is the u32 array at +0x71C holding a/0/0/8 sub-file
 * indices; func_02159C20 hands out its base.  Both are decoded by
 * func_02159D04 out of one a/0/0/9 sub-file.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02159BC4.c \
 *       --func func_02159BC4 --addr 0x02159BC4 --region ov010 --cc 1.1p1 --thumb
 */
u16 func_02159BC4(const struct MapMatrix *m, u32 x, u32 y)
{
    return m->zone_grid[x + y * m->width];
}


int func_02159BD4(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t4 = a2 + 0;
a0 = a1 + 0;
    a0 = func_02159D68(a0);
loc_02159BE0:
t6 = a0 + 0;
a0 = t4 + 0;
    a0 = func_02159D68(a0);
loc_02159BE8:
a2 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159BC4((const struct MapMatrix *)a0, a1, a2);
loc_02159BF2:
    return a0;}



/*
 * Unlabelled leaf accessor (prints as .word): returns the field at +8.
 * Sole blocker of ov021 func_02189B30's MATCH.
 */
unsigned short func_02159BF4(Obj_02159BF4 *p)
{
    return p->f;
}



/*
 * Unlabelled leaf accessor (prints as .word): returns the field at +0xA.
 * Sole blocker of ov021 func_02189B30's MATCH.
 */
unsigned short func_02159BF8(Obj_02159BF8 *p)
{
    return p->f;
}



/*
 * Unlabelled leaf accessor (prints as .word): returns the field at +0x10.
 * Sole blocker of ov021 func_02189B30's MATCH.
 */
int func_02159BFC(Obj_02159BFC *p)
{
    return p->f;
}



/*
 * Set the matrix object's dimensions, refusing anything that would not fit
 * the two fixed 900-entry grids: width and height are each capped at 30 and
 * their product at 900.  That is what pins the object's layout, since
 * 0x14 + 900 * 2 is exactly the 0x71C where the u32 map-model grid starts.
 *
 * The product is computed before the guards rather than after, so all three
 * checks share one exit and the whole body is a single conjunction
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 * 900 is spelled 0xe1 << 2 because it is not an 8-bit Thumb immediate.
 *
 * Another leaf with no lr save, so disasm.py left it unlabelled.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02159C00.c \
 *       --func sub_02159C00 --addr 0x02159C00 --region ov010 --cc 1.1p1 --thumb
 */
void sub_02159C00(struct MapMatrix *m, u32 width, u32 height)
{
    u32 n = width * height;

    if (width <= 30 && height <= 30 && n <= 900) {
        m->width = (u16)width;
        m->height = (u16)height;
        m->count = n;
    }
}


char *func_02159C20(char *p)
{
    return p + 0x71c;
}





int func_02159C2C(struct Obj12037 *m, int x, int y)
{
    if (y >= 0 && y < m->fA && x >= 0 && x < m->f8)
        return 1;
    return 0;
}








int func_02159C48(struct Obj12037 *m, int a, int b)
{
    int x = func_02159D68(a);
    int y = func_02159D68(b);
    return func_02159C2C(m, x, y);
}








void func_02159C68(Obj_02159C48 *a, int b, int c)
{
    u32 v[2];
    int r = func_02159E00((u8 *)b, &v[1], &v[0]);
    switch (r) {
    case 0:
        break;
    case 2:
        func_02159B94((int)a, (u16)v[0], a->f02, c);
        return;
    case 1: {
        u32 i;
        for (i = 0; i < a->f10; i++) {
            u32 *p = (u32 *)((u8 *)a + i * 4);
            if (v[1] == ((struct Obj12278 *)p)->f71C)
                ((struct Obj12278 *)p)->f71C = v[0];
        }
        break;
    }
    }
}








void func_02159CC4(u32 *a, int b, int c)
{
    void *l = func_02159D84(c, b);
    int n = func_02159DC8(l);
    int i;
    for (i = 0; i < n; i++) {
        u32 t = func_02159DCC(l, i);
        if (t == a[1])
            func_02159C68((struct Obj_02159C48 *)a, (int)l, c);
    }
    func_02159DEC(l);
}








/*
 * The map-matrix decoder: unpack one a/0/0/9 sub-file into the runtime matrix
 * object. File = { u16 mode; u16 pad; u16 width; u16 height; u32 cells[] },
 * plus a second block of the same length when mode == 1. Block one is copied
 * into the u32 grid at +0x71C. Block two is narrowed into the u16 grid at
 * +0x14; without it the u16 grid is filled with the caller's zone id.
 *
 * final push 2026-10-05 G4L1: closed by storing zone_id first (dst->zone_id =
 * zone_id before the matrix_id store). That gives the parameter the earliest
 * birth, so it takes r7 (the later-born cells and pool take r6 and r4). EXACT
 * in c99 and c.
 */
void func_02159D04(struct MapMatrix *dst, const struct MatrixFile *src,
                   u32 matrix_id, u16 zone_id)
{
    u32 n;
    const u32 *cells;
    const u32 *second;
    u32 i;
    u16 *zone_grid;

    dst->zone_id = zone_id;
    dst->matrix_id = matrix_id;
    n = src->width * src->height;
    dst->height = src->height;
    dst->count = n;
    dst->mode = src->mode;
    dst->width = src->width;
    cells = src->cells;
    func_02082A90(cells, dst->map_grid, n * 4);

    zone_grid = dst->zone_grid;
    if (dst->mode == 1) {
        second = cells + dst->count;
        for (i = 0; i < dst->count; i++)
            zone_grid[i] = (u16)second[i];
    } else {
        func_02082A48(zone_id, zone_grid, 0x708);
    }
}


/*
 * extent: two bytes of zero alignment padding at 0x02159D82.
 */
int func_02159D68(int x)
{
    return x / 4096 / 16 / 32;
}



Obj_02159D68 *func_02159D84(int a, int b)
{
    Obj_02159D68 *p = func_02030734(a, 0x2c, 1, d_021728BC, 0x77);
    p->f00 = a;
    p->f04 = func_020490F4(10, a);
    p->f08 = ((u32)func_020493D4(p->f04, 0) << 16) >> 20;
    func_02159E8C(p->f0c, b);
    return p;
}



/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02159DC8.c \
 *       --func func_02159DC8 --addr 0x02159DC8 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_02159DC8(void *p) { return ((struct Obj17651 *)p)->f8; }



/*
 * Reads record n (16 bytes) from the archive at p+4 into p+0x1a through
 * func_0204944C, then returns the halfword read.
 */
u32 func_02159DCC(u8 *p, int n)
{
    func_0204944C(*(struct ArcFile **)(p + 4), 0, n << 4, 0x10, p + 0x1a);
    return *(u16 *)(p + 0x1a);
}



int func_02159DEC(struct Obj17652 *p)
{
    func_02049238((void *)p->f4);
    return func_020307B0(p);
}



int func_02159E00(u8 *a, u32 *b, u32 *c)
{
    u8 *r4 = a + 0x1a;
    u8 *r5 = a + 0xc;
    int sel = r4[3];
    u32 old = ((struct Obj07280 *)r4)->f4;
    int idx;
    u32 cur;
    switch (sel) {
    case 0:
        idx = r5[0];
        break;
    case 1:
        idx = r5[1];
        break;
    case 2:
        idx = r5[2];
        break;
    default:
        idx = (r5 + func_02159E60(sel))[3];
        break;
    }
    cur = *(u16 *)(r4 + idx * 2 + 4);
    *b = old;
    *c = cur;
    if (old == cur)
        return 0;
    if (r4[2] == 1)
        return 2;
    if (r4[2] == 0)
        return 1;
    return 0;
}

int func_02159E60(int x)
{
    unsigned int i;
    for (i = 0; i < 10; i++) {
        if (x == d_02170FB0[i].f00)
            return i;
    }
    return -1;
}



void func_02159E8C(u8 *out, int obj)
{
    int a = func_0201296C(func_020120F4((const struct Ctx *)obj));
    int b = func_02012138((const struct Ctx *)obj);
    int c = func_0202E83C((void *)obj);
    int i;
    out[0] = c;
    out[1] = (func_0215843C((void *)b) != 0x15);
    out[2] = (out[1] == 0) ? 0 : c + 1;
    for (i = 0; i < 10; i++) {
        Ent_02159C48 *e = &d_02170FB0[i];
        u16 *p = (u16 *)func_020143CC(a, e->f02);
        if (*p == e->f04)
            out[3 + i] = 1;
        else
            out[3 + i] = 0;
    }
}


Ent_02159C48 *func_02159F04(int unused, int x)
{
    unsigned int i;
    for (i = 0; i < 10; i++) {
        Ent_02159C48 *p = &d_02170FB0[i];
        if (p->f01 == x)
            return p;
    }
    return 0;
}


/*
 * extent: two bytes of zero alignment padding at 0x02159F52.
 */
void func_02159F28(int a, int b, int flag)
{
    Ent_02159C48 *p = func_02159F04(a, b);
    u16 *q;
    if (p) {
        q = (u16 *)func_020143CC(func_0201296C((const struct BigObj *)a), p->f02);
        if (flag)
            *q = p->f04;
        else
            *q = 0;
    }
}


int func_02159F54(int a, int b)
{
    Ent_02159C48 *p = func_02159F04(a, b);
    u16 *q;
    if (p) {
        q = (u16 *)func_020143CC(func_0201296C((const struct BigObj *)a), p->f02);
        if (p->f04 == *q)
            return 1;
        else
            return 0;
    }
    return 0;
}



/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Constant leaf: `movs r0, N; bx lr`.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02159F80.c \
 *       --func func_02159F80 --addr 0x02159F80 --region ov010 --cc dsi/1.1p1 --thumb
 */
/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Constant leaf: `movs r0, #N; bx lr`.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02159F80.c \
 *       --func func_02159F80 --addr 0x02159F80 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_02159F80(void) { return 1; }





int func_02159F84(int a0)
{

    if (a0 <= 0) goto loc_02159F8C;
loc_02159F88:
    if ((unsigned)a0 <= (unsigned)0x11) goto loc_02159F90;
loc_02159F8C:
a0 = 0;
    return a0;
loc_02159F90:
a0 = 1;
    return a0;}


/*
 * addressing: getter result converted to unsigned; scale/add modulo 32 bits
 * preserves the original muls/add address without assuming a valid array index.
 */
u16 func_02159F94(int a) { return *(u16 *)((unsigned)d_02170FF4 + (unsigned)func_0215A064(a) * 20u); }


/*
 * extent: followed by independently matched ov010_func_02159FE0.c.
 * lever: const table declarations hoist the second table load before the stack argument.
 * prototype: both payload bytes come out of the halfword as bit fields, so the
 * u16 fifth input needs no extra truncation.
 */
void func_02159FA8(int a, int b)
{
    int i = func_0215A064(a);
    const Ent_02170FEC *e = &d_02170FEC[i];
    u32 w = d_02170FF0[i][0];
    func_0215A048((void *)b, w, 0, e->h6_lo, e->h6_hi);
}









/*
 * Unlabelled leaf (push {r4,r5} only, so disasm.py prints it as .word
 * data): a 1-based index lookup over a 17-entry, 0x14-byte table.
 * Callee of ov020 func_021857C0.
 */
int func_02159FE0(int v)
{
    unsigned int i;

    for (i = 0; i < 17; i++) {
        if (v == d_02170FEC[i].h4 && d_02170FEC[i].flag0)
            return i + 1;
    }
    return 0;
}








void func_0215A014(void *a, int b) {
 unsigned i;
 const Ent_02170FEC *p;
 for(i=0; i<17; i++) {
 p = &d_02170FEC[i];
 if (b == p->h8 && p->flag1) {
 func_02014314((char *)func_0201296C(a), p->h0);
 return;
 }
 }
}








/*
 * evidence: owner commit f860957 supplies the matched ARM9 Thumb02014184
 * witness. Recheck the caller against that witness; no owner C compiled.
 * prototype: owner's u16 id is widened to int here because original r1
 * is passed unchanged without narrowing. Remaining payloads retain 32 bits.
 * prior: wave49 one MATCH; tu --suggest-split left caller OUT.
 */
void func_0215A048(void *a, int b, int c, unsigned d, u16 e) {
 func_02014184(a, b, 1, d << 16, 0, (unsigned)e << 16);
}









int func_0215A064(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_02159F84(a0);
loc_0215A06C:
    if (a0 != 0) goto loc_0215A076;
loc_0215A070:
    a0 = func_02159F80();
loc_0215A074:
t4 = a0 + 0;
loc_0215A076:
a0 = t4 - 1;
    return a0;}









void *func_0215A07C(int a, u16 *b, u16 *c)
{
    void *h = func_02012934(func_020120F4((void *)a));
    u32 *p = func_02030734(4, 0x98, 1, d_021728CC, 0x40);
    void *r;
    Task *q;
    ((struct Obj07281 *)p)->f0 = h;
    p[0x34 / 4] = 3;
    p[0x38 / 4] = 0;
    p[0x3c / 4] = 0;
    r = func_020122C0((void *)a, 0, func_0215A214, 0x18);
    q = func_020124E8(r);
    q->f0 = (void *)a;
    q->f4 = func_0201210C((void *)a);
    q->f8 = p;
    q->fC = 0;
    q->f10 = b;
    q->f14 = c;
    return r;
}









void *func_0215A0E8(int a, int b, int c, int d, unsigned short e)
{
    void *h = func_02012934(func_020120F4((const struct Ctx *)a));
    u32 *p = func_02030734(4, 0x98, 1, d_021728CC, 0x66);
    void *r;
    u32 *q;
    p[0] = (u32)h;
    p[0x34 / 4] = 0x18;
    p[0x38 / 4] = 0;
    p[0x3c / 4] = 0;
    *((unsigned char *)p + 0x5e) = d;
    ((struct Obj04920 *)p)->f46 = e;
    r = func_020122C0((void *)a, 0, func_0215A214, 0x18);
    q = func_020124E8(r);
    q[0] = a;
    q[1] = (u32)func_0201210C((void *)a);
    q[2] = (u32)p;
    q[3] = 0;
    q[4] = b;
    q[5] = c;
    return r;
}









void *func_0215A168(int a, int b, int c)
{
    void *h = func_020120F4((const struct Ctx *)a);
    void *l = func_02012934(h);
    int m = (int)func_0200CA1C(h);
    u32 *p = func_02030734(4, 0x98, 1, d_021728CC, 0x90);
    u32 *s;
    void *r;
    u32 *q;
    p[0] = (u32)l;
    p[0x34 / 4] = 0x19;
    p[0x38 / 4] = 0;
    p[0x3c / 4] = 0;
    s = func_02030734(4, 0x28, 1, d_021728CC, 0x97);
    s[0] = (u32)l;
    s[2] = (u32)h;
    ((u8 *)s)[0xc] = 1;
    ((u8 *)s)[0xd] = 1;
    ((u8 *)s)[0xe] = func_0201AA18(l);
    ((u8 *)s)[0x10] = 0;
    s[0x18 / 4] = func_0200CA38((struct Blk37 *)m);
    s[0x20 / 4] = 0;
    r = func_020122C0((void *)a, 0, func_0215A214, 0x18);
    q = func_020124E8(r);
    q[0] = a;
    q[1] = (u32)func_0201210C((void *)a);
    q[2] = (u32)p;
    q[3] = (u32)s;
    q[4] = b;
    q[5] = c;
    return r;
}









int func_0215A214(void *a, u32 *st, Ctx_0215A214 *c)
{
    u32 s = *st;
    void *p0 = c->f0;
    int v;
    switch (s) {
    case 0:
        func_02012374(a, func_021BE8D4(p0, c->f4, 0, 0));
        *st = 1;
        break;
    case 1:
        func_02012374(a, (struct Evt **)func_020144DC((int)p0, (int)c->f4));
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
        v = c->f8->f3c;
        if (v <= 5) {
            *c->f14 = v;
            *c->f10 = 1;
        } else {
            *c->f14 = 0;
            *c->f10 = 0;
        }
        func_020307B0(c->f8);
        if (c->fC != 0)
            func_020307B0(c->fC);
        return 1;
    }
    return 0;
}









int func_0215A2E4(int a, int b, int c, int d, int e, int f, unsigned short g)
{
    int t8 = (int)func_020120F4((const struct Ctx *)a);
    void *t12 = func_02012934((void *)t8);
    char *p = (char *)func_02030734(4, 0x98, 1, (const char *)&d_021728CC, 0x11d);
    int r;
    int *q;

    ((struct Obj03073 *)p)->f0 = (int)t12;
    p[0xc] = 1;
    p[0xe] = func_0201AA18(t12);
    p[0xf] = c;
    p[0x10] = 1;
    ((struct Obj03073 *)p)->f14 = g;
    p[0xd] = (f == 1) ? 3 : 2;
    ((struct Obj03073 *)p)->f20 = 0;
    ((struct Obj03073 *)p)->f8 = t8;
    r = (int)func_020122C0((void *)a, 0, func_0215A370, 0x14);
    q = func_020124E8((struct Obj *)r);
    q[0] = a;
    q[1] = b;
    q[2] = (int)p;
    q[3] = d;
    q[4] = e;
    return r;
}









/*
 * Case 2 loads 0x00000083 from the pool: an absolute symbol (overlay id),
 * see docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 */
int func_0215A370(void *a, u32 *st, Ctx_0215A370 *c)
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
        *st = 2;
        break;
    case 2:
        func_020120B4(p0, (u32)ov131_id, d_021DC800, c->f8);
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
        if (c->f8->f12 == 0) {
            *c->f10 = c->f8->f11;
            *c->fC = 1;
        } else {
            *c->f10 = 0;
            *c->fC = 0;
        }
        func_020307B0(c->f8);
        return 1;
    }
    return 0;
}









void func_0215A438(int a, int b, S24 *src)
{
    int *q = (int *)func_02159124((char *)func_021589D0(a), b);

    *(S24 *)q = *src;
    q[6] = 0;
}








/*
 * Map a tick count onto a 3000/5000 ms window, truncated to 16 bits.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0215A460(u32 a)
{
if (a < 5000)
return (u16)(a - 3000);
return (u16)(a - 5000);
}








u16 func_0215A480(unsigned a) { return a + 3000; }








/*
 * extent: includes unlabelled range-test func_0215A4A0; function-start seed.
 */
u16 func_0215A490(unsigned a) { return a + 5000; }








int func_0215A4A0(unsigned a) { if (a >= 5000) return 1; return 0; }









int func_0215A4B4(int a0)
{
    int a1;

a1 = 2;
    a0 = func_0202A230((void *)a0, a1);
loc_0215A4BC:
    if (a0 != 1) goto loc_0215A4C4;
loc_0215A4C0:
a0 = 1;
    return a0;
loc_0215A4C4:
a0 = 0;
    return a0;}








int func_0215A4C8(int a0)
{
    int a1;

a1 = 2;
    a0 = func_0202A230((void *)a0, a1);
loc_0215A4D0:
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    return a0;}







/*
 * interface: original narrows r1 by shift pairs; u16 extern preserves this.
 */
unsigned func_0215A4D8(void *a, unsigned b) { return func_020142E8(a, (u16)(b + 1420)); }







void func_0215A4EC(char *a, unsigned b) { func_02014314(a, (u16)(b + 1420)); }







void func_0215A500(char *a, unsigned b) { func_0201433C(a, (u16)(b + 1420)); }








void *func_0215A514(int a, int heap)
{
    int *p = (int *)func_02030734(heap, 0x110, 1, (const char *)&d_021728E0, 0x78);

    p[0] = a;
    p[1] = (int)func_02158F54((void *)a);
    p[2] = (int)func_020120F4((const struct Ctx *)p[1]);
    p[3] = func_02012964((const struct BigObj *)p[2]);
    *((char *)p + 0x104) = 7;
    return p;
}






/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_020307B0, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0215A554.c \
 *       --func func_0215A554 --addr 0x0215A554 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0215A554(void *a0, unsigned a1, unsigned a2, unsigned a3)
{

    func_020307B0(a0);
}















/*
 * lever: const source pointer hoists its copy before the destination id store.
 */
void *func_0215A55C(const S16 *src, int v)
{
    T *p;
    const S16 *s;
    p = (T *)func_02030734((unsigned short)((v & 0x7fff) | 0x8000), 0x24, 1, (const char *)&d_021728E0, 0x94);
    s = src;
    p->id = v;
    p->r = *s;
    ((struct Obj05883 *)p)->f20 = func_02158F6C((void *)src->w[3]);
    return p;
}
















int func_0215A5A4(int a0)
{
    struct Obj04882 *p = (struct Obj04882 *)a0;
    if (p->f1C != 0)
        func_020307B0((void *)p->f1C);
    if (p->f14 != 0)
        func_02045C04(p->f14);
    func_0215A738((int)p);
    return func_020307B0(p);
}


















u16 func_0215A5CC(void *a0)
{
    return ((struct Obj17653 *)a0)->f0;
}
















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0215A5D0.c \
 *       --func func_0215A5D0 --addr 0x0215A5D0 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0215A5D0(void *p) { return ((struct Obj17654 *)p)->f4; }
















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0215A5D4.c \
 *       --func func_0215A5D4 --addr 0x0215A5D4 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0215A5D4(void *p) { return ((struct Obj17655 *)p)->fC; }















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0215A5D8.c \
 *       --func func_0215A5D8 --addr 0x0215A5D8 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0215A5D8(void *p) { return ((struct Obj17656 *)p)->f8; }

















void *func_0215A5DC(void *a0)
{
    return ((struct Obj17657 *)(*(char * *)&((struct Obj00005 *)a0)->f20))->f4;
}

















void *func_0215A5E4(void *a0)
{
    return ((struct Obj17658 *)(*(char * *)&((struct Obj00005 *)a0)->f20))->f8;
}














/*
 * Getter: word at +0xc of the object whose pointer sits at +0x20.
 *
 * Addresses are Black-image addresses.
 */
void *func_0215A5EC(void *p)
{
    return ((struct Obj17659 *)(*(u8 * *)&((struct Obj00005 *)p)->f20))->fC;
}















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Double dereference: one field load then a load through the resulting pointer.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0215A5F4.c \
 *       --func func_0215A5F4 --addr 0x0215A5F4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0215A5F4(void *p) { return ((struct Obj17660 *)(((struct Obj00005 *)p)->f20))->f0; }















int func_0215A5FC(int a0)
{
    void *v0;

    v0 = func_0215A5F4((void *)a0);
loc_0215A602:
    a0 = func_02158F58((int)v0);
loc_0215A606:
a0 = *(int *)&((struct Obj00005 *)((char *)a0))->f0;
    return a0;}
















/*
 * Reads the word field at +0x14.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0215A60C(u8 *p)
{
    return ((struct Obj17661 *)p)->f14;
}















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0215A610.c \
 *       --func func_0215A610 --addr 0x0215A610 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0215A610(void *p) { return ((struct Obj17662 *)p)->f18; }














/*
 * Setter: word at +0xfc of the object whose pointer sits at +0x20.
 *
 * Addresses are Black-image addresses.
 */
void func_0215A614(u8 *p, u32 v)
{
*(u32 *)((u8 *)((struct Obj17663 *)p)->f20 + 0xfc) = v;
}

















int func_0215A61C(int a0)
{

a0 = *(int *)&((struct Obj00005 *)a0)->f20;
a0 = a0 + 0xfc;
a0 = *(int *)&((struct Obj00005 *)((char *)a0))->f0;
    return a0;}















/*
 * Setter: word at +0x100 of the object whose pointer sits at +0x20.
 * Unlabelled leaf (leaf of func_021B0480).
 */
void func_0215A624(u8 *p, u32 v)
{
    *(u32 *)((u8 *)((struct Obj18787 *)p)->f20 + 0x100) = v;
}















/*
 * Getter: word at +0x100 of the object whose pointer sits at +0x20.
 * Unlabelled leaf (leaf of func_021B0480).
 */
u32 func_0215A630(u8 *p)
{
    return *(u32 *)((u8 *)((struct Obj18788 *)p)->f20 + 0x100);
}














/*
 * Address of the block at +0xD4 inside the object at +0x20.
 */
u8 *func_0215A63C(u8 *p)
{
    return *(u8 * *)&((struct Obj00005 *)p)->f20 + 0xd4;
}














/*
 * Unlabelled leaf (setter through the pointer at +0x20), filed as a blocker
 * of ov021 func_021C459C / func_021C4628.
 */
void func_0215A644(void *p, u32 v)
{
    ((struct Obj18789 *)(*(char * *)&((struct Obj00005 *)p)->f20))->f10 = v;
}














/*
 * Unlabelled leaf, blocker of ov021 func_021C457C/func_021C4608: reads the word at +0x10 of the record held at +0x20.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
void *func_0215A64C(void *p)
{
    return ((struct Obj18791 *)(*(char * *)&((struct Obj18790 *)p)->f20))->f10;
}














/*
 * Getter: byte at +0x104 of the object whose pointer sits at +0x20.
 * Unlabelled leaf (leaf of func_021B03E4).
 */
u32 func_0215A654(u8 *p)
{
    return *((u8 *)((struct Obj18792 *)p)->f20 + 0x104);
}














/*
 * Setter: byte at +0x104 of the object whose pointer sits at +0x20.
 * Unlabelled leaf (leaf of func_021B03E4).
 */
void func_0215A660(u8 *p, u32 v)
{
    *((u8 *)((struct Obj18793 *)p)->f20 + 0x104) = v;
}














/*
 * Reads the byte at +0x105 of the object at +0x20.
 */
u8 func_0215A66C(u8 *p)
{
    return (*(u8 **)(p + 0x20))[0x105];
}












/*
 * Writes the byte at +0x105 of the object at +0x20 (setter twin of
 * func_0215A66C). Unlabelled leaf, blocker of ov021 func_021B0BAC.
 */
void func_0215A678(u8 *p, u8 v)
{
    (*(u8 **)(p + 0x20))[0x105] = v;
}











#define W(p) (*(int *)((char *)(p)))










#define S(p, o) (*(unsigned short *)((char *)(*(int *)((char *)(p) + 0x20)) + (o)))










#define I(p, o) (*(int *)((char *)(*(int *)((char *)(p) + 0x20)) + (o)))











void func_0215A684(int *p, unsigned short v)
{
    S(p, 0x106) = v;
}











int func_0215A690(int *p)
{
    unsigned short *q = &S(p, 0x106);
    if (*q == 0) {
        return 1;
    }
    *q = *q - 1;
    return 0;
}











int func_0215A6AC(int *p)
{
    return I(p, 0x108);
}











void func_0215A6B8(int *p, int v)
{
    I(p, 0x108) = v;
}











int func_0215A6C4(int *p)
{
    return I(p, 0x10c);
}











void func_0215A6D0(int *p, int v)
{
    I(p, 0x10c) = v;
}











void func_0215A6DC(int *p, int v)
{
    int i;
    char *q = (char *)*(int *)&((struct Obj00005 *)p)->f20;
    for (i = 0; i < 8; i++) {
        int *e = (int *)(q + i * 4);
        if (e[5] == 0) {
            e[5] = v;
            return;
        }
    }
}











u32 func_0215A6FC(u32 a0, u32 a1, u32 a2, u32 a3)
{
    int t4;
    int t5;
    int t6;
    int t7;

t5 = a0 + 0;
t7 = 0;
t4 = 0;
loc_0215A704:
a0 = ((struct Obj05852 *)t5)->f20;
t6 = t4 << 2;
a0 = a0 + t6;
a0 = ((struct Obj05852 *)a0)->f14;
    if (a0 == 0) goto loc_0215A72E;
loc_0215A710:
    a0 = func_02197DA0(a0);
loc_0215A714:
    if (a0 != 1) goto loc_0215A72C;
loc_0215A718:
a0 = ((struct Obj05852 *)t5)->f20;
a0 = a0 + t6;
a0 = ((struct Obj05852 *)a0)->f14;
    a0 = func_02197DAC(a0);
loc_0215A722:
a0 = ((struct Obj05852 *)t5)->f20;
a1 = a0 + t6;
a0 = 0;
((struct Obj17665 *)a1)->f14 = a0;
    goto loc_0215A72E;
loc_0215A72C:
t7 = 1;
loc_0215A72E:
t4 = t4 + 1;
    if (t4 < 8) goto loc_0215A704;
loc_0215A734:
a0 = t7 + 0;
    return a0;}











int func_0215A738(int a0)
{
    int t4;
    int t5;
    int t6;
    int t7;

t4 = 0;
t5 = a0 + 0;
t7 = t4 + 0;
loc_0215A740:
a0 = ((struct Obj04882 *)t5)->f20;
t6 = t4 << 2;
a0 = a0 + t6;
a0 = ((struct Obj04882 *)a0)->f14;
    if (a0 == 0) goto loc_0215A756;
loc_0215A74C:
    a0 = func_02197DAC(a0);
loc_0215A750:
a0 = ((struct Obj04882 *)t5)->f20;
a0 = a0 + t6;
((struct Obj04882 *)a0)->f14 = t7;
loc_0215A756:
t4 = t4 + 1;
    if (t4 < 8) goto loc_0215A740;
loc_0215A75C:
    return a0;}









/*
 * interface: original narrows r1/r2 by shift pairs; u16 extern preserves this.
 */
void func_0215A760(u8 *a, unsigned b, unsigned c) {
 ((struct Obj05883 *)a)->f14 = func_02045B38(0, (u16)b, (u16)c, ((struct Obj05883 *)a)->f0);
 ((struct Obj05883 *)a)->f18 = c;
}










void func_0215A77C(unsigned short *p, unsigned short a, unsigned short b,
                   unsigned short c, unsigned short d, int e, int f, int g,
                   int h)
{
    char *base = *(char * *)&((struct Obj00005 *)p)->f20;
    Q_0215A77C *q = (Q_0215A77C *)(base + 0x34);

    func_02082BCC(q, 0, 0xa0);
    ((struct Obj18799 *)base)->f34 = a;
    q->b = b;
    q->c = c;
    q->d = d;
    q->e = e;
    q->f = f;
    q->g = g;
    q->i = h;
    func_02082A7C(0, (char *)q + 0x20, 0x80);
    if (q->i == 0) {
        q->h = 1;
        q->i = (int)func_02045B38(0, 3, 0x80 + 0x86, *p);
    }
    q->j = func_02190A20(0x20, *p);
}










void func_0215A7F0(unsigned short *p, int a, int b, int c, struct U16Vec *s0, void *s1)
{
    Q_0215A7F0 *q = (Q_0215A7F0 *)(*(char * *)&((struct Obj00005 *)p)->f20 + 0x34);

    if (b != 0xffff) {
        unsigned i = func_0201F91C((struct Slot *)q->j);
        if (i >= 0x20) {
            return;
        }
        func_02045CAC((struct MsgBank *)q->i, b, s1);
        func_0201F250((struct WordSet *)q->g, (void *)s0, (void *)s1);
        q->k[i] = (int)func_02045874(s0, *p);
    }
    func_02045CAC((struct MsgBank *)q->i, a, s1);
    func_0201F250((struct WordSet *)q->g, (void *)s0, (void *)s1);
    func_02190A64(q->j, (u32)s0, c, *p);
}


/*
 * The ov021 leaves 0x02190AC4 and 0x02190AEC (unlabelled, formerly the
 * blockers) are matched in their own shards and attest as matched.
 */
void func_0215A864(int *p)
{
    int x;
    int y;
    Q_0215A864 *q = (Q_0215A864 *)(*(char * *)&((struct Obj18800 *)p)->f20 + 0x34);
    L32 l = d_02171140;
    int t = func_0215A5FC((int)p);
    unsigned m;
    unsigned n;

    x = func_02190ACC((u32 *)t, (u32 *)q->j, l.h8, l.f1);
    if (q->e == 1) {
        q->a = q->a - (unsigned short)x;
    }
    n = func_02190AC4((void *)q->j);
    m = 6;
    if (n <= 6) {
        m = n;
    }
    y = func_02190AEC(m, l.h9, l.f2, n > 6);
    func_02190B08((u32)(&l), (unsigned short)func_02190AC4((void *)q->j), (unsigned short)q->a, (unsigned short)q->b, (unsigned short)x, (unsigned short)y);
    q->k = (int)func_02190988((u16 *)t, (const u8 *)(&l), q->j, (u32)((void *)func_0215A9C0), (u32)p, 0, q->c, q->d);
}


int func_0215A920(int a0)
{
    int t4;
    int t5;
    int t6;
    int t7;

t6 = a0 + 0;
a0 = *(int *)&((struct Obj04148 *)t6)->f1C;
    a0 = func_021909BC(a0);
loc_0215A92A:
a0 = ((struct Obj04148 *)t6)->f10;
    if (a0 != 1) goto loc_0215A936;
loc_0215A930:
a0 = ((struct Obj04148 *)t6)->f14;
    a0 = func_02045C04(a0);
loc_0215A936:
t4 = 0;
t7 = t4 + 0;
loc_0215A93A:
a0 = t4 << 2;
t5 = t6 + a0;
a0 = ((struct Obj12038 *)t5)->f20;
    if (a0 == 0) goto loc_0215A94A;
loc_0215A944:
    a0 = func_02045808(a0);
loc_0215A948:
((struct Obj12038 *)t5)->f20 = t7;
loc_0215A94A:
t4 = t4 + 1;
    if (t4 < 0x20) goto loc_0215A93A;
loc_0215A950:
    return a0;}

int func_0215A954(u8 *a) {
 u8 *p;
 int v;
 p = *(u8 * *)&((struct Obj12286 *)a)->f20 + 52;
 v = func_021909E4(((struct Obj04148 *)p)->f1C);
 if (v == -1) return 0;
 func_0215A920((int)p);
 if (v != -2) **(u16 * *)&((struct Obj04148 *)p)->f8 = v;
 else **(u16 * *)&((struct Obj04148 *)p)->f8 = 65534;
 return 1;
}

/*
 * lever: result declared before pointer gives original r4/result, r5/base.
 */
int func_0215A990(u8 *a) {
 int v;
 u8 *p;
 p = *(u8 * *)&((struct Obj12286 *)a)->f20 + 52;
 v = func_0215A954(a);
 if (v == 0 && (func_020362DC() & 1024)) {
 func_0215A920((int)p);
 **(u16 * *)&((struct Obj04148 *)p)->f8 = 65533;
 v = 1;
 }
 return v;
}


void func_0215A9C0(int a)
{
    unsigned short h = 0;
    int r = func_02020D0C((u8 *)a);
    Q_0215A9C0 *q = (Q_0215A9C0 *)(*(char * *)&((struct Obj00005 *)r)->f20 + 0x34);

    func_020202EC((struct Obj *)a, &h);
    if (q->k[h] != 0) {
        if (func_02159190(1) != 0) {
            int t = func_0215A61C(r);
            func_02191164((struct P *)t);
            func_02191184((struct Q_0215A9C0 *)t, 0, 0, q->k[h]);
        } else if (func_02159190(2) == 0) {
            func_02159190(3);
        }
    }
}


void *func_0215AA24(int a0)
{
    int t4;
    void *p;
    void *v0;

t4 = a0 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215AA2C:
    p = func_0215909C((u8 *)v0);
loc_0215AA30:
((struct Obj00005 *)t4)->f1C = p;
    return p;}


int func_0215AA34(int a0)
{
    int a1;
    int t4;
    void *v0;

t4 = a0 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215AA3C:
a1 = *(int *)&((struct Obj00005 *)t4)->f1C;
    a0 = func_021590D4(v0, a1);
loc_0215AA42:
a0 = 0;
*(int *)&((struct Obj00005 *)t4)->f1C = a0;
    return a0;}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Byte-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0215AA48.c \
 *       --func func_0215AA48 --addr 0x0215AA48 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0215AA48(void *p, int v) { ((struct Obj17666 *)p)->f1A = v; }


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Byte-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0215AA4C.c \
 *       --func func_0215AA4C --addr 0x0215AA4C --region ov010 --cc dsi/1.1p1 --thumb
 */
u8 func_0215AA4C(void *p) { return ((struct Obj17667 *)p)->f1A; }



int func_0215AA50(int a0, int a1)
{
    u16 *q;

    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AA56:
a1 = 0x15;
*q = a1;
a0 = 0;
    return a0;}



/*
 * blocked:  listing 48 compiled 46
 */
int func_0215AA60(int a0, int a1)
{
    void *p;
    struct Sub02008700Obj *t4;
    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AA68:
    p = func_02012EBC((struct Big *)v0);
loc_0215AA6C:
    t4 = func_0200873C(p);
loc_0215AA70:
    a0 = func_020083E4((short unsigned int *)t4);
loc_0215AA76:
a1 = a0 + 0;
    if (a1 != 0) goto loc_0215AA7E;
loc_0215AA7A:
a1 = 1;
    goto loc_0215AA84;
loc_0215AA7E:
    if (a1 != 1) goto loc_0215AA84;
loc_0215AA82:
a1 = 0;
loc_0215AA84:
    a0 = func_020083EC(t4, a1);
loc_0215AA8A:
a0 = 0;
    return a0;}



/*
 * blocked:
 */
int func_0215AA90(int a0, int a1)
{
    int t5;
    int t6;
    void *p;
    struct Sub02008700Obj *t4;
    u16 *q;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AA9C:
    p = func_02012EBC((struct Big *)v0);
loc_0215AAA0:
    t4 = func_0200873C(p);
loc_0215AAA4:
a0 = t5 + 0;
a1 = t6 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AAAE:
    a0 = func_020083E4((short unsigned int *)t4);
loc_0215AAB6:
*q = a0;
a0 = 0;
    return a0;}



/*
 * Same slot overwrite, keyed off the second index helper and the
 * caller's second argument.
 */
int func_0215AABC(void *a0, void *a1)
{
    u16 *p = func_02159AE8(a0, a1);

    *p = (u16)func_020056EC(func_02159B10(a0, a1));

    return 0;
}



int func_0215AADC(int a0, int a1)
{
    int t5;
    u16 *q;

t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AAE4:
a0 = t5 + 0;
    a0 = func_0215A610((void *)a0);
loc_0215AAEC:
*q = a0;
a0 = 0;
    return a0;}



int func_0215AAF4(int a0, int a1)
{    int t5;
    int t6;
    u16 *q;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AB00:
a0 = t5 + 0;
a1 = t6 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AB0A:
    a0 = func_0216F830(v0);
loc_0215AB12:
*q = a0;
a0 = 0;
    return a0;}



int func_0215AB18(int a0, int a1)
{    int t5;
    int t6;
    u16 *q;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AB24:
a0 = t5 + 0;
a1 = t6 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AB2E:
    a0 = func_021690B4((int)v0);
loc_0215AB36:
*q = a0;
a0 = 0;
    return a0;}



int func_0215AB3C(int a0, int a1)
{    int t5;
    int t6;
    u16 *q;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AB48:
a0 = t5 + 0;
a1 = t6 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AB52:
    a0 = func_021690F0((int)v0);
loc_0215AB5A:
*q = a0;
a0 = 0;
    return a0;}



int func_0215AB60(int a0, int a1)
{
    int t4;
    int t7;
    u16 *q;
    u16 *dst;
    void *v0;

t7 = a1 + 0;
t4 = a0 + 0;
a0 = t7 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AB6C:
a0 = t4 + 0;
a1 = t7 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AB76:
a0 = t4 + 0;
a1 = t7 + 0;
    dst = func_02159AE8((void *)a0, (void *)a1);
loc_0215AB80:
    a0 = func_021690D0((int)v0);
loc_0215AB88:
*q = a0;
    a0 = func_021690E0((int)v0);
loc_0215AB90:
*dst = a0;
a0 = 0;
    return a0;}



int func_0215AB98(int a0, int a1)
{
    int t4;
    int t7;
    u16 *q;
    u16 *dst;
    void *v0;

t7 = a1 + 0;
t4 = a0 + 0;
a0 = t7 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215ABA4:
a0 = t4 + 0;
a1 = t7 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215ABAE:
a0 = t4 + 0;
a1 = t7 + 0;
    dst = func_02159AE8((void *)a0, (void *)a1);
loc_0215ABB8:
    a0 = func_02169100((int)v0);
loc_0215ABC0:
*q = a0;
    a0 = func_02169110((int)v0);
loc_0215ABC8:
*dst = a0;
a0 = 0;
    return a0;}



int func_0215ABD0(int a0, int a1)
{
    int t5;
    u16 *q;
    void *v0;

t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215ABD8:
a0 = t5 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215ABE0:
    a0 = func_02012984(v0);
loc_0215ABE4:
*q = a0;
a0 = 0;
    return a0;}


/*
 * extent: compiled 46 bytes; trailing 0x0215AC1A..0x0215AC1C is zero alignment.
 */
int func_0215ABEC(int a, int b) {
 u16 *p, *q;
 Info info;
 p = func_02159AE8((void *)a, (void *)b);
 q = func_02159AE8((void *)a, (void *)b);
 func_02087D28((struct OSOwnerInfoEx *)(&info));
 *p = info.month;
 *q = info.day;
 return 0;
}



/*
 * The arm9 chain result is biased by the record's own 0x20 before the
 * halfword store.
 */
int func_0215AC1C(void *a0, void *a1)
{
    u16 *p = func_02159AE8(a0, a1);

    *p = (u16)func_02008550((const struct Sub0200852CObj *)((char *)func_020127A4(func_0215A5E4(a1)) + 0x20));

    return 0;
}


/*
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 */
int func_0215AC3C(int a,int b)
{
    u16 *out = func_02159AE8((void *)a,(void *)b);
    int k = func_02159B10((void *)a,(void *)b);
    *out = func_0200C234(func_02012F08(func_0215A5E4((void *)b)),k);
    return 0;
}



int func_0215AC68(int a, int b)
{
    V4 v;
    int r4 = func_02159B10((void *)a, (void *)b);
    void *r5 = func_0215A5E4((void *)b);

    func_0200C248(func_02012F08(r5), r4);
    func_0203F4E4((struct RtcDate *)(&v));
    func_02008A7C(func_02012F5C(r5), r4, v.a, v.b, v.c);
    return 0;
}



int func_0215ACA8(int a0, int a1)
{
    u16 *t4;
    int t5;
    void *p;
    void *v0;

t5 = a1 + 0;
    t4 = func_02159AE8((void *)a0, (void *)a1);
loc_0215ACB0:
a0 = t5 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215ACB8:
    p = func_02012F08((int *)v0);
loc_0215ACBC:
    a0 = func_0200C258(p);
loc_0215ACC0:
*t4 = a0;
a0 = 0;
    return a0;}



int func_0215ACC8(int a, int b)
{
    int r4;
    unsigned short *r7;
    unsigned short *m;
    unsigned short *r5;
    unsigned s2;
    unsigned s1;

    r4 = (int)func_02012EBC(func_0215A5E4((void *)b));
    r7 = func_02159AE8((void *)a, (void *)b);
    m = func_02159AE8((void *)a, (void *)b);
    r5 = func_02159AE8((void *)a, (void *)b);
    s2 = 0;
    s1 = 0;
    *r7 = func_020071EC((const struct Sub020071E4Ctrl *)r4);
    *m = func_020071E4((const struct Sub020071E4Ctrl *)r4);
    func_0200723C(r4, &s1, &s2);
    if (s1 * 3 < s2) {
        *r5 = 0;
    } else {
        *r5 = 1;
    }
    return 0;
}



int func_0215AD38(int a0, int a1)
{
    int t5;
    u16 *q;

t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AD40:
a0 = t5 + 0;
    a0 = func_0215A5D0((void *)a0);
loc_0215AD48:
*q = a0;
a0 = 0;
    return a0;}


int func_0215AD50(int a0, int a1)
{    int t5;
    int t6;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AD5C:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0215AD66:
t5 = a0 + 0;
    a0 = func_02159F84(a0);
loc_0215AD6C:
    if (a0 != 1) goto loc_0215AD78;
loc_0215AD70:
a1 = t5 + 0;
    a0 = func_02012900(v0, a1);
loc_0215AD78:
a0 = 0;
    return a0;}


/*
 * unresolved: 0x02014184 is an unlabelled Thumb leaf in the ARM9 image (a
 * 64-byte run that disasm.py prints as ARM junk, no func_ label) with one
 * caller image-wide, so label / sole-ref/code refuse it. evidence class:
 * label / sole-ref/code (target not a traced function start).
 */
int func_0215AD7C(int a, int b)
{
    V28 v;
    void *t = func_0215A5E4((void *)b);
    void *r5 = func_020127A4(t);
    int *r4 = func_02012AA0();
    int r7 = func_02012AC8(r5);

    func_02014184(&v, r7, (short)func_02012AE4(r5), r4[0], r4[1], r4[2]);
    func_0201289C(t, (const struct Rec1C *)(&v));
    return 0;
}




int func_0215ADCC(int a0, int a1)
{
    int buf[7];
    int v8 = (int)func_0215A5E4((void *)a1);
    int c = func_02159B10((void *)a0, (void *)a1);
    int r6 = func_02159B10((void *)a0, (void *)a1);
    int r7 = func_02159B10((void *)a0, (void *)a1);
    int v10 = func_02159B10((void *)a0, (void *)a1);
    int v0 = func_02159B10((void *)a0, (void *)a1);
    func_02014184(buf, c, (s16)r6, r7 << 16, v10 << 16, v0 << 16);
    func_0201289C((struct BigObj *)v8, (const struct Rec1C *)buf);
    return 0;
}





int func_0215AE34(int a0, int a1)
{
    void *v0 = func_0215A5DC((void *)a1);
    void *p = func_0215A5E4((void *)a1);
    int x = func_02159B10((void *)a0, (void *)a1);
    int y = func_02159B10((void *)a0, (void *)a1);
    int flag = func_02159B10((void *)a0, (void *)a1);
    int q, s, t;
    u16 r;
    func_02159F28((int)p, x, y);
    if (flag != 0) {
        q = func_02012974(p);
        r = func_02012AC8(func_020127A4((struct SaveBlock *)p));
        s = func_02013B44(r);
        t = func_0215A5CC((void *)a1);
        func_02159B94(q, s, r, t);
        func_02159CC4((u32 *)q, (int)v0, t);
    }
    return 0;
}





int func_0215AEB8(int a0, int a1)
{
    int t4;
    int t5;
    int t7;
    u16 *q;
    void *v0;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AEC4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0215AECE:
t7 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AED8:
a1 = t7 + 0;
    a0 = func_02159F54((int)v0, a1);
loc_0215AEE2:
*q = a0;
a0 = 0;
    return a0;}





int func_0215AEE8(int a0, int a1)
{
    void *v0;
    int k;
    int m, o;
    void *n;
    v0 = func_0200CA1C((void *)func_0215A5E4((void *)a1));
    k = func_0215A5CC((void *)a1);
    m = (int)func_02159B10((void *)a0, (void *)a1);
    o = (int)func_02159B10((void *)a0, (void *)a1);
    n = func_020173F0(o, 1, 0xFFFFFFFF00000000ULL, k);
    switch (m) {
    case 0:
        func_0200CFA0(v0, n);
        break;
    case 1:
        break;
    }
    func_020307B0(n);
    return 0;
}




int func_0215AF40(int a0, int a1)
{
    void *v;
    int k, x;
    u16 *out;
    v = func_0200CA1C((void *)func_0215A5E4((void *)a1));
    k = (int)func_02159B10((void *)a0, (void *)a1);
    x = (int)func_02159B10((void *)a0, (void *)a1);
    out = func_02159AE8((void *)a0, (void *)a1);
    switch (k) {
    case 0:
        *out = func_0200D064(v, x);
        break;
    case 1:
        *out = func_0200CED4(v, x);
        break;
    default:
        *out = 0;
        break;
    }
    return 0;
}




int func_0215AF98(int a0, int a1)
{
    void *v;
    int k;
    u16 *out;
    v = func_0200CA1C((void *)func_0215A5E4((void *)a1));
    k = (int)func_02159B10((void *)a0, (void *)a1);
    out = func_02159AE8((void *)a0, (void *)a1);
    switch (k) {
    case 0:
        *out = func_0200D0CC(v);
        break;
    case 1:
        *out = func_0200CF28(v);
        break;
    default:
        *out = 0;
        break;
    }
    return 0;
}




int func_0215AFE0(int a0, int a1)
{
    void *p;
    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AFE8:
    p = func_0200CA1C(v0);
loc_0215AFEC:
    a0 = (int)func_0200CA28(p);
loc_0215AFF0:
a0 = 0;
    return a0;}




int func_0215AFF4(int a0, int a1)
{
    int t5;
    void *p;
    u16 *q;
    void *v0;

t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AFFC:
a0 = t5 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215B004:
    p = func_0200CA1C(v0);
loc_0215B008:
    a0 = func_0200CA38(p);
loc_0215B00C:
*q = a0;
a0 = 0;
    return a0;}




int func_0215B014(int a0, int a1)
{
    void *p;
    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215B01C:
    p = func_0200CA1C(v0);
loc_0215B020:
    a0 = (int)func_0200CA40(p);
loc_0215B024:
a0 = 0;
    return a0;}




int func_0215B028(int a0, int a1)
{
    int t5;
    int t6;
    void *p;
    void *q;
    struct Sub02008700Obj *t4;
    u16 *dst;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215B034:
    p = func_020120F4((const struct Ctx *)v0);
loc_0215B038:
    q = func_02012EBC(p);
loc_0215B03C:
    t4 = func_0200873C(q);
loc_0215B040:
a0 = t5 + 0;
a1 = t6 + 0;
    dst = func_02159AE8((void *)a0, (void *)a1);
loc_0215B04A:
    a0 = func_02008428((short unsigned int *)t4);
loc_0215B052:
    if (a0 == 0) goto loc_0215B05C;
loc_0215B056:
    if (a0 == 1) goto loc_0215B060;
loc_0215B05A:
    goto loc_0215B064;
loc_0215B05C:
a0 = 0;
    goto loc_0215B062;
loc_0215B060:
a0 = 1;
loc_0215B062:
*dst = a0;
loc_0215B064:
a0 = 0;
    return a0;}



int func_0215B068(int a,int b)
{
    func_02014314((char *)func_0201296C(func_0215A5E4((void *)b)), 0x963);
    return 0;
}



int func_0215B084(int a,int b)
{
    int k = (int)func_02159B10((void *)a, (void *)b);
    int p = func_0201293C(func_0215A5E4((void *)b));
    if ((u16)(k + 0xFFFF) <= 1) func_02007A68((void *)p,k);
    return 0;
}




int func_0215B0B4(int a0, int a1)
{
    int t4;
    int t6;
    char *sb;
    void *p;
    struct Sub020089A8Obj *obj;
    unsigned short *v0;
    unsigned short *v1;
    void *v2;

t6 = a0 + 0;
t4 = a1 + 0;
    v0 = func_02159AE8((void *)a0, (void *)a1);
loc_0215B0BE:
a0 = t6 + 0;
a1 = t4 + 0;
    v1 = func_02159AE8((void *)a0, (void *)a1);
loc_0215B0C8:
a0 = t4 + 0;
    v2 = func_0215A5E4((void *)a0);
loc_0215B0D0:
    sb = func_020127A4((struct SaveBlock *)v2);
loc_0215B0D6:
    p = func_02012EBC((struct Big *)v2);
loc_0215B0DE:
    obj = func_020089C0(p);
loc_0215B0E2:
sb = sb + 0x20;
    a0 = func_02008554((const struct Sub0200852CObj *)sb);
loc_0215B0EC:
    a0 = func_02025C88(a0);
loc_0215B0F0:
((struct Obj17687 *)((char *)v1))->f0 = a0;
    a0 = func_020089F4(obj);
loc_0215B0F8:
((struct Obj17686 *)((char *)v0))->f0 = a0;
    a0 = (int)func_02008A00(obj);
loc_0215B100:
a0 = 0;
    return a0;}



int func_0215B104(int a,int b)
{
    int k = (int)func_02159B10((void *)a, (void *)b);
    u16 *out = func_02159AE8((void *)a,(void *)b);
    *out = (func_0200C308(func_02012F08(func_0215A5E4((void *)b)),k) & 1) != 0;
    return 0;
}




/*
 * The third argument of the arm9 pair call is the slot the overlay index
 * returned, with a literal one alongside.
 */
int func_0215B138(void *a0, void *a1)
{
    void *v = (void *)func_02159B10(a0, a1);

    func_0200C2F0(func_02012F08(func_0215A5E4(a1)), (u32)v, 1);

    return 0;
}



int func_0215B158(int a,int b)
{
    int k = (int)func_02159B10((void *)a, (void *)b);
    u16 *out = func_02159AE8((void *)a,(void *)b);
    if (func_0200C308(func_02012F08(func_0215A5E4((void *)b)),k) == 3) *out = 1; else *out = 0;
    return 0;
}



int func_0215B190(int a0, int a1)
{
    void *p = func_0215A5E4((void *)a1);
    int q = func_0201296C(p);
    u16 *out = func_02159AE8((void *)a0, (void *)a1);
    void *t;
    int r;
    if (func_020142E8((void *)q, 0x97B) != 0) {
        t = func_02012EBC((struct Big *)p);
        r = func_0200725C(t, 8, 4);
        switch (r) {
        case 0:
            *out = 0;
            break;
        case 1:
        case 2:
            if (func_0200ECB4(func_020073D8(t, 8, 0)) == 0) {
                *out = 0;
            } else {
                *out = 1;
            }
            break;
        default:
            *out = 2;
            break;
        }
        func_020072A4(t, 8);
    } else {
        *out = 0;
    }
    return 0;
}



int func_0215B214(int a0, int a1)
{
    int v = (int)func_02159B10((void *)a0, (void *)a1);
    s16 x = (s16)func_02159B10((void *)a0, (void *)a1);
    s16 y = (s16)func_02159B10((void *)a0, (void *)a1);
    s16 z = (s16)func_02159B10((void *)a0, (void *)a1);
    func_02162A74(func_02012844(func_0215A5E4((void *)a1)), v, x, y, z);
    return 0;
}



int func_0215B26C(int a0, int a1)
{
    int v = (int)func_02159B10((void *)a0, (void *)a1);
    s16 x = (s16)func_02159B10((void *)a0, (void *)a1);
    s16 y = (s16)func_02159B10((void *)a0, (void *)a1);
    s16 z = (s16)func_02159B10((void *)a0, (void *)a1);
    func_02162708((struct Ctx *)func_02012844(func_0215A5E4((void *)a1)), (int)v, x, (u16)y, z);
    return 0;
}



int func_0215B2C4(int a0, int a1)
{
    int a = (int)func_02159B10((void *)a0, (void *)a1);
    int b = (int)func_02159B10((void *)a0, (void *)a1);
    s16 x = (s16)func_02159B10((void *)a0, (void *)a1);
    s16 y = (s16)func_02159B10((void *)a0, (void *)a1);
    s16 z = (s16)func_02159B10((void *)a0, (void *)a1);
    func_02162748(func_02012844(func_0215A5E4((void *)a1)), a, b, x, y << 16, z);
    return 0;
}




int func_0215B328(int a0, int a1)
{
    void *v0 = func_0215A5E4((void *)a1);
    char *p = (char *)func_0201296C(v0);
    unsigned x = func_02159B10((void *)a0, (void *)a1);
    func_0215A4EC(p, x);
    return 0;
}




int func_0215B350(int a0, int a1)
{
    void *v0 = func_0215A5E4((void *)a1);
    char *p = (char *)func_0201296C(v0);
    unsigned x = func_02159B10((void *)a0, (void *)a1);
    func_0215A500(p, x);
    return 0;
}




int func_0215B378(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    int t7;
    u16 *q;
    void *v0;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215B384:
    a0 = func_0201296C(v0);
loc_0215B388:
t6 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0215B392:
t7 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215B39C:
a0 = t6 + 0;
a1 = t7 + 0;
    a0 = func_0215A4D8((void *)a0, a1);
loc_0215B3A6:
*q = a0;
a0 = 0;
    return a0;}




int func_0215B3AC(int a0, int a1)
{    int t5;
    int t6;
    void *p;
    void *v0;
    void *v1;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215B3B8:
a0 = t6 + 0;
    v1 = func_0215A5F4((void *)a0);
loc_0215B3C0:
    p = func_0215F6E8(v0);
loc_0215B3C8:
    a0 = func_0215898C(v1, p);
loc_0215B3D0:
a0 = t5 + 0;
    a0 = func_02011290(a0);
loc_0215B3D6:
a0 = 1;
    return a0;}



int func_0215B3DC(int a,int b)
{
    u16 *out = func_02159AE8((void *)a,(void *)b);
    int z = 1;
    if (func_0216EFA8(func_02012A44(func_0215A5E4((void *)b)),1) == 1) *out = 0; else *out = z;
    return 0;
}




int func_0215B408(int a0, int a1)
{    int t5;
    int t6;
    void *p;
    void *v0;
    void *v1;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215B414:
a0 = t6 + 0;
    v1 = func_0215A5F4((void *)a0);
loc_0215B41C:
    p = func_0215F6E8(v0);
loc_0215B424:
    a0 = func_0215898C(v1, p);
loc_0215B42C:
a0 = t5 + 0;
    a0 = func_02011290(a0);
loc_0215B432:
a0 = 1;
    return a0;}



int func_0215B438(int a,int b)
{
    u16 *out = func_02159AE8((void *)a,(void *)b);
    int z = 0;
    if (func_0216EFA8(func_02012A44(func_0215A5E4((void *)b)),0) == 1) *out = z; else *out = 1;
    return 0;
}



int func_0215B464(int a,int b)
{
    int k = (int)func_02159B10((void *)a, (void *)b);
    u16 *out = func_02159AE8((void *)a,(void *)b);
    *out = d_02171160[k];
    return 0;
}
