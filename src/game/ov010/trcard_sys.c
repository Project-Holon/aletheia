/*
 * file:     trcard_sys.c
 * unit:     yes
 * function: func_0216E474, func_0216E47C, func_0216E490, func_0216E4B0, func_0216E4EC, func_0216E51C, func_0216E544, func_0216E57C, func_0216E5B0, func_0216E5FC, func_0216E618, func_0216E62C, func_0216E680, func_0216E68C, func_0216E7C8, func_0216E818, func_0216E8CC, func_0216E910, func_0216E95C, func_0216EAB0, func_0216EB98, func_0216EDFC, func_0216EE20, func_0216EE40, func_0216EE7C, func_0216EF84, func_0216EFA8, func_0216EFCC, func_0216EFDC, func_0216EFF0, func_0216F02C, func_0216F054, func_0216F064, func_0216F070, func_0216F07C, func_0216F088, func_0216F0AC, func_0216F144, func_0216F174, func_0216F1E0, func_0216F228, func_0216F244, func_0216F288, func_0216F2B4, func_0216F2E0, func_0216F31C, func_0216F378, func_0216F3B0, func_0216F3D4, func_0216F40C, func_0216F7BC, func_0216F7F4, func_0216F830, func_0216F8B8, func_0216F8C8, func_0216F8DC, func_0216F900, func_0216F918, func_0216F940, func_0216F948, func_0216FAA0, func_0216FAB4, func_0216FC4C, func_0216FC50, func_0216FC74, func_0216FCA0, func_0216FD54, func_0216FE04, func_0216FE2C
 * address:  0x0216E474
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
 *   MIi_CpuClear32  0x02082A7C  arm
 *   d_02172A70 0x02172A70 data a2
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216D67C 0x0216D67C thumb ov010
 *   func_0216D88C 0x0216D88C thumb ov010
 *   func_0216DDDC  0x0216DDDC  thumb  ov010
 *   func_0216E51C  0x0216E51C  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017988  0x02017988  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   d_02172554  0x02172554  data  ov010  a2
 *   d_02172556  0x02172556  data  ov010  a2
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201313C  0x0201313C  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021CF5D8  0x021CF5D8  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02012F20  0x02012F20  thumb
 *   func_0202E79C  0x0202E79C  thumb
 *   func_02012A44  0x02012A44  thumb
 *   func_0215F6E8  0x0215F6E8  thumb  ov010
 *   func_0201235C  0x0201235C  thumb
 *   func_021BE92C  0x021BE92C  thumb
 *   func_0202E818  0x0202E818  thumb
 *   func_02181D8C  0x02181D8C  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AAABC  0x021AAABC  thumb  ov021
 *   func_02013090  0x02013090  thumb
 *   func_021AA5CC  0x021AA5CC  thumb  ov021
 *   func_02013144  0x02013144  thumb
 *   func_021CF748  0x021CF748  thumb  ov021
 *   func_0201A920  0x0201A920  thumb
 *   func_020173EC  0x020173EC  thumb
 *   func_02030734  0x02030734  arm
 *   func_0201756C  0x0201756C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_021AA304  0x021AA304  thumb  ov021
 *   func_020135C0  0x020135C0  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_02172B54     0x02172B54  data
 *   func_02012FD8  0x02012FD8  thumb
 *   sub_0200E740   0x0200E740  thumb
 *   sub_020124E8   0x020124E8  thumb
 *   sub_0200E788   0x0200E788  thumb
 *   sub_0200E74C   0x0200E74C  thumb
 *   sub_0200E7B4   0x0200E7B4  thumb
 *   sub_0200E7A4   0x0200E7A4  thumb
 *   func_02017588  0x02017588  thumb
 *   sub_0200E76C   0x0200E76C  thumb
 *   sub_0200E780   0x0200E780  thumb
 *   sub_0200E7AC   0x0200E7AC  thumb
 *   func_020178D8  0x020178D8  thumb
 *   func_02017FA8  0x02017FA8  thumb
 *   func_02012444  0x02012444  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_02012F50  0x02012F50  thumb
 *   func_0201447C  0x0201447C  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02029B28  0x02029B28  thumb
 *   func_02029BCC  0x02029BCC  thumb
 *   func_02029C00  0x02029C00  thumb
 *   func_02029CC0  0x02029CC0  thumb
 *   func_0202E80C  0x0202E80C  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_02011D34  0x02011D34  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_02168D30  0x02168D30  thumb  ov010
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021882DC  0x021882DC  arm  ov230d
 *   func_02188354  0x02188354  arm  ov230d
 *   func_02188390  0x02188390  arm  ov230d
 *   func_021CF498  0x021CF498  thumb  ov021
 *   ov093_id       0x0000005D  data
 *   ov092_id       0x0000005C  data
 *   ov230_id       0x000000E6  data
 *   d_021EFDAC     0x021EFDAC  data  ov093
 *   d_021B9D94     0x021B9D94  data  ov092
 *   g_0214624C     0x0214624C  data
 *   func_0202A230   0x0202A230  thumb
 *   func_0202A3FC   0x0202A3FC  thumb
 *   d_021725C0     0x021725C0  data
 *   func_0216505C  0x0216505C  thumb  ov010
 *   func_02165078  0x02165078  thumb  ov010
 *   func_021653F4  0x021653F4  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_0201AB18  0x0201AB18  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_021654AC  0x021654AC  thumb  ov010
 *   func_02165424  0x02165424  thumb  ov010
 *   func_02165468  0x02165468  thumb  ov010
 *   func_021654F0  0x021654F0  thumb  ov010
 *   func_02045808  0x02045808  arm
 *   d_021725D8  0x021725D8  data  ov010  a1
 *   d_021725B8     0x021725B8  data
 *   func_02012A4C 0x02012A4C thumb
 *   func_0215E5B0 0x0215E5B0 thumb ov010
 *   func_020127A4 0x020127A4 thumb
 *   func_02012AC8 0x02012AC8 thumb
 *   func_0202C83C 0x0202C83C thumb
 *   func_02082A7C 0x02082A7C arm
 *   func_020130B4  0x020130B4  thumb
 *   func_0203F0A8  0x0203F0A8  arm
 *   func_02031330  0x02031330  arm
 *   func_0203133C  0x0203133C  arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   d_02172B64     0x02172B64  data  ov010
 *   func_02012944  0x02012944  thumb
 *   func_02008554  0x02008554  thumb
 *   func_02027174  0x02027174  thumb
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_02031324 0x02031324 arm
 *   func_02031348 0x02031348 arm
 *   d_021725FC 0x021725FC data a4
 *   func_02012EBC 0x02012EBC thumb
 *   d_021C39D4 0x021C39D4 data ov110 a4
 *   ov110_id 0x0000006E data a1
 *   func_0216F088  0x0216F088  thumb  ov010
 *   func_0200E6F0  0x0200E6F0  thumb
 *   func_0200E714  0x0200E714  thumb
 *   func_0202715C  0x0202715C  thumb
 *   d_021C892C 0x021C892C data a4 ov111
 *   func_02008DFC  0x02008DFC  thumb
 *   d_02172620     0x02172620  data  a2
 *   func_020089C0  0x020089C0  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_02008B14  0x02008B14  thumb
 *   func_02008C58  0x02008C58  thumb
 *   func_0200E6E8  0x0200E6E8  thumb
 *   func_020084BC  0x020084BC  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0200C274  0x0200C274  thumb
 *   func_0200C234  0x0200C234  thumb
 *   func_02012FCC  0x02012FCC  thumb
 *   func_0200864C  0x0200864C  thumb
 *   func_02008650  0x02008650  thumb
 *   func_02008A0C  0x02008A0C  thumb
 *   func_02008A28  0x02008A28  thumb
 *   func_0200E6FC  0x0200E6FC  thumb
 *   func_0200C1DC  0x0200C1DC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_02010F7C  0x02010F7C  thumb
 *   func_0200BF54  0x0200BF54  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_02010F8C  0x02010F8C  thumb
 *   func_0200C184  0x0200C184  thumb
 *   func_02008EA0  0x02008EA0  thumb
 *   func_02008E78  0x02008E78  thumb
 *   func_0200921C  0x0200921C  thumb
 *   func_020090E0  0x020090E0  thumb
 *   func_0200BF94  0x0200BF94  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_0200D0AC  0x0200D0AC  thumb
 *   func_020089D0  0x020089D0  thumb
 *   func_020089CC  0x020089CC  thumb
 *   func_0216FEAC  0x0216FEAC  thumb  ov010
 *   MIi_CpuCopy16  0x02082A60  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   RTC_ConvertSecondToDateTime  0x020891E0  arm
 *   func_02045A98  0x02045A98  arm
 *   func_02012EF0  0x02012EF0  thumb
 *   func_02012F44  0x02012F44  thumb
 *   func_0200D298  0x0200D298  thumb
 *   func_0200DBA0  0x0200DBA0  thumb
 *   func_0200A73C  0x0200A73C  thumb
 *   func_0200BDF8  0x0200BDF8  thumb
 *   func_0200BDFC  0x0200BDFC  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_021F385C  0x021F385C  thumb  ov059
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021F38BC  0x021F38BC  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   d_02172B74 0x02172B74 data ov010 a1
 *   func_0201ADD0  0x0201ADD0  thumb
 *   func_02047250        0x02047250  arm
 *   STD_GetStringLength  0x0208CC78  arm
 *   func_0206E62C        0x0206E62C  arm
 *   func_0201D7EC        0x0201D7EC  thumb
 *   func_0201D83C        0x0201D83C  thumb
 *   d_021726A0           0x021726A0  data
 *   func_020437D4  0x020437D4  arm
 *   func_020437EC  0x020437EC  arm
 *   func_0216FC50 0x0216FC50 thumb ov010
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_020437DC  0x020437DC  arm
 *   func_020437E4  0x020437E4  arm
 *   func_02043994  0x02043994  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   func_02043678  0x02043678  arm
 *   func_0207F7A0  0x0207F7A0  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0207F7FC  0x0207F7FC  arm
 *   func_0207F9B4  0x0207F9B4  arm
 *   func_020437AC  0x020437AC  arm
 *   func_0207FA0C 0x0207FA0C arm
 *   func_0207FA40 0x0207FA40 arm
 *   func_0207FADC 0x0207FADC arm
 */
#include "../../matched/include/Obj09169.h"
#include "../../matched/include/Obj19138.h"
#include "../../matched/include/Obj19139.h"
#include "../../matched/include/Obj00020.h"
#include "../../matched/include/Obj12059.h"
#include "../../matched/include/Obj19144.h"
#include "../../matched/include/Obj12060.h"
#include "../../matched/include/Obj09170.h"
#include "../../matched/include/Obj19150.h"
#include "../../matched/include/Obj07206.h"
#include "../../matched/include/Obj07207.h"
#include "../../matched/include/Obj09171.h"
#include "../../matched/include/Obj19151.h"
#include "../../matched/include/Obj01640.h"
#include "../../matched/include/Obj12408.h"
#include "../../matched/include/Obj19152.h"
#include "../../matched/include/Obj19154.h"
#include "../../matched/include/Obj19155.h"
#include "../../matched/include/Obj19156.h"
#include "../../matched/include/Obj09341.h"
#include "../../matched/include/Obj12410.h"

struct Actor;
struct VecFx32;
struct Blk37;
struct BigObj;
struct Ctx;
struct Desc;
struct Evt;
struct Obj;
struct S0201235C;
struct Work;
struct Sub02008C20Obj;
struct Party;
struct PartyMon;
struct Info;
struct Record;
struct Result;
struct Sub02014444Obj;
struct U16Vec;
struct Rec44;
struct SaveBlock;
struct BattleEndCtx;
struct Obj0203159C;
struct Profile;
struct Sub0200852CObj;
struct S020315D4;
struct Big;
struct Rec0200E714;
struct Blk34;
struct PlayTime;
struct Rec0200E6FC;
struct Rec1B0;
struct Sub020089A8Obj;
struct Sub02008AECSession;
struct Sub020090B0Obj;
struct Sub02009210Obj;
struct Blk1AC;
struct Rec94;
struct GfFont;
struct Bmp;
struct Obj020437AC;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { int x,y,z; } Vec_0216E544;

typedef struct
{
    int x;
    int y;
    int z;
} Vec_0216E57C;

typedef struct
{
    char pad00[44];
    unsigned int raw44;
} Context;

typedef short s16_0216E474;

typedef int s32_0216E5B0;

typedef s32_0216E5B0 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct {
    u16 x;
    u16 y;
    int z;
} Pos;

typedef struct {
    u8 pad00[0x18];
    int f18;
    Pos pos;
} Obj;

typedef struct Battle {
    u32 f00;
    u32 f04;            /* 0x04 */
} Battle;

typedef struct Holder {
    u8 pad00[0x18];
    u8 f18[4];          /* 0x18 */
} Holder;

typedef struct Task {
    u8 pad00[8];
    Holder *f08;        /* 0x08 */
    u8 pad0C[0x14 - 0x0C];
    u32 f14;            /* 0x14 */
    u8 pad18[0x24 - 0x18];
    u32 f24;            /* 0x24 */
} Task;

typedef struct Work {
    void *sys;          /* 0x00 */
    Battle *bs;         /* 0x04 */
    u32 f08;            /* 0x08 */
    u32 f0c;            /* 0x0C */
} Work;

typedef u32 (*TaskFn_0216E5B0)(void *task, u32 *state, Task *work);

typedef unsigned long long u64;

typedef struct Loc {
    u32 f00;            /* 0x00 */
    u32 f04;            /* 0x04 */
    u8 pad08[8];
} Loc;

typedef struct Work_0216E95C {
    u8 pad00[8];
    Holder *f08;        /* 0x08 */
    u8 pad0C[0x14 - 0x0C];
    u32 f14;            /* 0x14 */
    u8 pad18[0x24 - 0x18];
    u32 f24;            /* 0x24 */
} Work_0216E95C;

typedef u32 (*TaskFn_0216E910)(void *task, u32 *state, Work_0216E95C *work);

typedef signed int s32_0216E910;

typedef struct Info {
    u8 pad00[0x18];
    u16 f18;            /* 0x18 */
} Info;

typedef struct Work_0216EB98 {
    void *sys;          /* 0x00 */
    void *f04;          /* 0x04 */
    Info *f08;          /* 0x08 */
    void *f0c;          /* 0x0C */
    Info *f10;          /* 0x10 */
    u32 f14;            /* 0x14 */
    u32 f18;            /* 0x18 */
    u32 f1c;            /* 0x1C */
    u8 pad20[4];
    void *f24;          /* 0x24 */
} Work_0216EB98;

typedef void (*IdHandler)(u16 id);

typedef struct BattleEnd {
    u32 mode;           /* 0x00 */
    u8 pad04[0x48];
    u32 *result;        /* 0x4C */
    u8 pad50[0x3C];
    u32 outcome;        /* 0x8C */
} BattleEnd;

typedef struct BattleEndCtx {
    u32 f00;
    void *sys;          /* 0x04 */
    BattleEnd *st;      /* 0x08 */
} BattleEndCtx;

typedef struct {
    int w[6];
} T24;

typedef struct {
    u32 f00;
    u8 pad04[0x14];
    T24 *f18;
    int f1c;
} W_0216F0AC;

typedef struct { int w[8]; } W_0216F144;

typedef long long s64;

typedef struct RTCDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
} RTCDate;

typedef struct RTCTime {
    u32 hour;
    u32 minute;
    u32 second;
} RTCTime;

typedef struct Profile {
    u8 kind;            /* 0x00 */
    u8 pad01[2];
    u8 f03;             /* 0x03 */
    u8 b0 : 1;          /* 0x04 */
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 pad05;
    u8 f06;             /* 0x06 */
    u8 pad07;
    u16 f08;            /* 0x08 */
    u16 name[8];        /* 0x0A */
    u8 pad1A[2];
    u32 f1c;            /* 0x1C */
    u32 f20;            /* 0x20 */
    u32 f24;            /* 0x24 */
    u16 f28;            /* 0x28 */
    u16 f2a;            /* 0x2A */
    u16 hour2;          /* 0x2C */
    u8 f2e;             /* 0x2E */
    u8 year1;           /* 0x2F */
    u8 month1;          /* 0x30 */
    u8 day1;            /* 0x31 */
    u8 year2;           /* 0x32 */
    u8 month2;          /* 0x33 */
    u8 day2;            /* 0x34 */
    u8 minute2;         /* 0x35 */
    u8 pad36[2];
    u32 f38;            /* 0x38 */
    u32 f3c;            /* 0x3C */
    u32 f40;            /* 0x40 */
    u32 f44;            /* 0x44 */
    u32 f48;            /* 0x48 */
    u32 f4c;            /* 0x4C */
    u32 f50;            /* 0x50 */
    u32 f54;            /* 0x54 */
    u32 f58;            /* 0x58 */
    u16 f5c;            /* 0x5C */
    u16 f5e;            /* 0x5E */
    u16 f60;            /* 0x60 */
    u16 f62;            /* 0x62 */
    u16 f64;            /* 0x64 */
    u16 f66;            /* 0x66 */
    u32 fl0 : 1;        /* 0x68 */
    u32 fl1 : 1;
    u32 fl2 : 1;
    u32 fl3 : 1;
    u32 fl4 : 1;
    u8 f6c[8];          /* 0x6C */
    u8 f74[0x600];      /* 0x74 */
} Profile;

typedef struct Clock {
    u8 pad[0x24];
    s64 sec1;           /* 0x24 */
    s64 sec2;           /* 0x2C */
} Clock;

typedef struct { void *f00; void *f04; void *f08; u32 f0c; u32 f10; u32 f14; } Record_0216F2E0;

typedef struct { u8 *f00; void *f04; void *f08; u32 f0c; u32 f10; u32 f14; } Record_0216F7F4;

typedef signed int     s32;

typedef struct Ent {
    u16 move;
    u16 level;
} Ent;

typedef struct Res {
    u8 pad00[8];
    u32 f08;            /* 0x08 */
    u8 pad0C[2];
    u16 texDict;        /* 0x0E */
    u8 pad10[0x2C - 0x10];
    u32 f2c;            /* 0x2C */
    u8 pad30[4];
    u16 plttDict;       /* 0x34 */
} Res;

typedef struct Fmt {
    u16 w;              /* 0x00 */
    u16 f02;
    u32 tex;            /* 0x04 */
    u32 pltt;           /* 0x08 */
} Fmt;

typedef struct TexKey {
    u16 texFmt;         /* 0x00 */
    u16 plttFmt;        /* 0x02 */
    u32 f04;            /* 0x04 */
    u32 f08;            /* 0x08 */
    u32 texOfs;         /* 0x0C */
    u32 plttOfs;        /* 0x10 */
} TexKey;

typedef struct TexReq {
    u16 texFmt;         /* 0x00 */
    u16 plttFmt;        /* 0x02 */
    u32 f04;            /* 0x04 */
    u32 f08;            /* 0x08 */
    u32 texOfs;         /* 0x0C */
    u32 plttOfs;        /* 0x10 */
    void *font;         /* 0x14 */
} TexReq;

typedef signed short s16_0216FC74;

struct Rec {
    u8 x;
    u8 y;
    u8 pad[10];
};

struct Pos {
    u8 pad[0x0c];
    u16 x;
    u16 y;
};

extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern u16 func_0216D598(void *p);
extern u16 func_0216D590(void *p);
extern u16 func_0216D588(void *p);
extern void *func_0216D67C(void *);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
int func_0216E51C();
int func_0216E544(void *a, Vec_0216E544 *out);
void func_0216E57C(void *a, int a1);
extern u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32_0216E5B0 x, s32_0216E5B0 lim, u32 d);
extern void *func_0200CA1C(void *a);
extern unsigned int func_02017E1C(void *a, unsigned int b, unsigned int c);
extern u32 func_02017988(void *p, u32 a);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_0201313C(void *p, int i);
extern void *func_0201AB28(void *party, u32 i);
extern void *func_0201210C(const struct Ctx *p);
extern void func_021CF5D8(u32 species, u32 a, u32 b, void *c, u32 *d, void *e);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_02012F20(int p0);
extern void func_0202E79C(u8 *p);
extern u32 func_02012A44(const struct BigObj *p);
extern void *func_0215F6E8(void *sys);
extern void func_0201235C(struct S0201235C *o, u32 *out);
extern void *func_021BE92C(void *sys, void *proc, u32 a, u32 b, u32 c, u32 d, u32 e);
extern int func_0202E818(int *p);
extern void *func_02181D8C(void *sys, u32 v);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u32 func_02188CE8(u8 *p);
extern void func_021AAABC(int s);
extern void *func_02013090(u32 heap);
extern void func_021AA5CC(struct Ctx *ctx, void *a1, u32 mode, u32 flag, void *mon, u32 a5, u16 heap);
extern void func_02013144(char *p, int v);
extern void func_021CF748(u32 a, u32 x, int *out, u16 *out2);
extern void *func_0201A920(u16 heap);
extern u32 func_020173EC(void);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern void func_0201756C(void *mon, u16 species, u16 level, u64 id);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_021AA304(struct Info *out, void *a1, void *a2);
extern void func_020135C0(void *bs, void *ctx, void *p1, void *p2, Loc *loc, u32 heap);
extern u32 func_020307B0(void *p);
extern void *func_02012FD8(void **p);
extern u32   sub_0200E740(const void *obj, u32 idx);
extern void *sub_020124E8(struct Obj *p);
extern u32   sub_0200E788(const void *obj, u32 a, u32 b);
extern u32   sub_0200E74C(const void *obj, u32 idx);
extern u32   sub_0200E7B4(const void *obj, u32 idx);
extern u32   sub_0200E7A4(const void *obj, u32 idx);
extern void  func_02017588(void *p, u16 species, u32 level, u64 id, u32 pow, u64 rnd);
extern u32   sub_0200E76C(const void *obj, u32 idx);
extern u8    sub_0200E780(const void *obj, u32 idx);
extern void *sub_0200E7AC(void *obj, u32 idx);
extern void func_020178D8(void *p, u32 a);
extern u32   func_02017FA8(void *p);
extern void func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern void *func_02012B38(const struct BigObj *p);
extern void *func_02012F50(void *base);
extern u8 func_0201447C(struct Sub02014444Obj *o, u8 v);
extern int func_020144DC(int a0, int a1);
extern void *func_020145CC(void *sys);
extern void *func_02029B28(void *a, u16 b);
extern void *func_02029BCC(void *a, u32 b);
extern void *func_02029C00(void *a);
extern void *func_02029CC0(void *a);
extern void func_0202E80C(u32 *p);
extern int func_02034AC4(s32_0216E910 handle);
extern void func_02034A5C(s32_0216E910 handle);
extern void *func_020056A0(void (*callback)(void *, void *), void *work, u32 key);
extern void func_02011D34(void);
extern void func_02168D30(struct Record *r, struct Result *s);
extern int func_02189A08(unsigned char *p);
extern u32 func_021882DC(void (*a)(void), void (*b)(void), u32 c);
extern u32 func_02188354(void (*a)(void), void (*b)(void), u32 c);
extern u32 func_02188390(void (*a)(void), void (*b)(void), u32 c);
extern void func_021CF498(struct Ctx *c, u32 x, int idx);
extern u32 func_0202A230(void *a, u32 idx);
extern u8 func_0202A3FC(u32 key);
extern int func_0216505C(int a0);
extern int func_02165078(int a0);
extern void func_021653F4(u16 species);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AB18(void *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_021654AC(void *name);
extern void func_02165424(void *name);
extern void func_02165468(void *name);
extern void func_021654F0(void *name);
extern void func_02045808(struct U16Vec *vec);
extern void func_02012A4C(struct BigObj *p, u32 v);
extern void func_0215E5B0(void *a0, struct Work *w);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern int func_0202C83C(int,int);
extern void func_02082A7C(int,void *,int);
extern int func_020130B4(int a0);
extern u32 func_0203F0A8(void);
int func_0216E5B0(void *map, const VecFx32 *pos);
int func_0216E5FC(u16 id);
void func_0216E618(Obj *o, u16 x, u16 y, int z);
void func_0216E62C(int a, int p, int id);
int func_0216E680(int a0);
int func_0216E68C(void *evt, u32 *state, Work *w);
int func_0216E7C8(int a0, int a1, int a2, int a3, int a4);
int func_0216E818(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
int func_0216E8CC(int a0, int a1, int a2);
int func_0216E910(void *a0, void *a1, void *a2);
void *func_0216E95C(void *sys, u32 arg, u32 heap);
void *func_0216EAB0(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 idx);
int func_0216EB98(void *evt, u32 *state, Work_0216EB98 *w);
int func_0216EDFC(void *a0);
void func_0216EE20(u16 id, int col);
void func_0216EE40(void *p, int which);
void func_0216EE7C(BattleEndCtx *c);
int func_0216EF84(int a0);
int func_0216EFA8(int a, int b);
u8 func_0216EFCC(int i);
int func_0216EFDC(int *w);
void func_0216EFF0(int *p,void *a);
void func_0216F02C(void **p,void *a,void *b);
int func_0216F054(int a0);
int func_0216F064(int a0);
int func_0216F070(int a0);
extern unsigned int func_02031330(void *p);
extern int func_0203133C();
extern void func_0203064C(unsigned int a, unsigned int b, unsigned int c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
extern u8 *func_02012944(void *p);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern int func_02027174();
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void *func_02031324(int a0);
extern void func_02031348(void *,u32,const void *,void *);
int func_0216F07C(int a0);
int func_0216F088(int a0);
int func_0216F0AC(void *a, int b, T24 *c);
int func_0216F144(void *a,int b,int c);
int func_0216F174(int a, int *b, int c, int d);
int func_0216F1E0(int a0, int a1, int a2, int a3);
int func_0216F228(void *a, int b, int c, char *d);
int func_0216F244(char *a, char *b);
int func_0216F288(int *p);
int func_0216F2B4(char *p);
extern void *func_02012EBC(struct Big *p);
extern int func_0200E6F0(void);
extern void func_0200E714(struct Rec0200E714 *dst, int idx, struct Rec0200E714 *src);
extern void func_0202715C(u32 a0);
extern u32 func_02008DFC(struct Sub02008C20Obj *obj, int i);
extern struct Sub020089A8Obj *func_020089C0(void *sys);
extern void *func_02012F08(int *p);
extern struct Sub02008AECSession *func_02008B14(void *sys);
extern struct Sub02008C20Obj *func_02008C58(void *sys);
extern void *func_0200E6E8(u32 a);
extern int func_020084BC(const u16 *values);
extern const void *func_020084F4(const void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u32 func_0200C274(struct Blk34 *p);
extern u32 func_0200C234(struct Blk34 *p, u32 bit);
extern int func_02012FCC(int p0);
extern u16 func_0200864C(const struct PlayTime *p);
extern u8 func_02008650(const struct PlayTime *p);
extern u16 func_02008A0C(const struct Sub020089A8Obj *obj);
extern u8 func_02008A28(const struct Sub020089A8Obj *obj);
extern void func_0200E6FC(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern u32 func_0200C1DC(struct Blk34 *p);
extern u16 *func_0200BE48(void *sys);
extern void *func_02010F7C(u32 heap);
extern void func_0200BF54(struct Rec1B0 *p, u8 *dest, u32 n);
extern void *func_020127B8(void *save);
extern void func_02010F8C(void *p);
extern u32 func_0200C184(struct Blk34 *p);
extern u32 func_02008EA0(struct Sub02008C20Obj *obj);
extern u8 func_02008E78(struct Sub02008C20Obj *obj);
extern struct Sub02009210Obj *func_0200921C(void *p);
extern u8 func_020090E0(const struct Sub020090B0Obj *obj);
extern unsigned long long func_0200BF94(struct Rec1B0 *p);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, int id);
extern u32 func_0200D0AC(struct Blk37 *p, u32 heap);
extern int func_020089D0(const struct Sub020089A8Obj *obj);
extern void *func_020089CC(void *p);
extern int func_0216FEAC(void *tbl, void *pos, u8 *flags);
extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void RTC_ConvertSecondToDateTime(RTCDate *date, RTCTime *time, s64 sec);
extern u16 func_02045A98(void);
extern void *func_02012EF0(void **p);
extern void *func_02012F44(void *save);
extern int func_0200D298(void *p);
extern u32 func_0200DBA0(struct Blk1AC *p, s32 i, u32 op);
extern u32 func_0200A73C(struct Big *p);
extern u16 func_0200BDF8(struct Rec1B0 *p);
extern u16 func_0200BDFC(struct Rec1B0 *p);
extern void *func_0215A5DC(void *a0);
extern void func_021F385C(void *);
extern void *func_0215A5F4(void *p);
extern void *func_021F38BC();
extern int func_0215897C();
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern void func_0201ADD0(unsigned int a, int b, void *buf);
extern Res *func_02047250(void *p);
extern int STD_GetStringLength(const char *s);
extern void *func_0206E62C(const void *dict, const char *name);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201D83C(void *ptr);
extern void *func_020437D4(const struct Bmp *bmp);
extern u32 func_020437EC(const struct Bmp *bmp);
int func_0216F2E0(char *p);
int func_0216F31C(char *a);
int func_0216F378(char *p);
int func_0216F3B0(char *p);
u32 func_0216F3D4(void *p, int idx, u32 cap);
void func_0216F40C(Profile *out, void *save, int mode, int flag, volatile u16 heap);
Record_0216F2E0 *func_0216F7BC(void *a,u32 heap,void *b);
Record_0216F7F4 *func_0216F7F4(void *a,u8 *b,u32 heap);
int func_0216F830(void *save);
int func_0216F8B8(int a0, int a1);
int func_0216F8C8(int a0, int a1);
int func_0216F8DC(int a0, int a1);
void func_0216F900(void *p);
void *func_0216F918(u32 heap);
void func_0216F940(void *a0, unsigned a1, unsigned a2, unsigned a3);
u16 *func_0216F948(void *mon, u32 heap);
int func_0216FAA0(u16 *p);
int func_0216FAB4(void *file, const char *texName, void *extra, const char *plttName, u32 a4, u16 a5, u16 a6, u16 a7, u16 heap, TexKey *out);
int func_0216FC4C(void);
void func_0216FC50(void *bmp);
extern void func_0201C7D0(void *,s16_0216FC74,s16_0216FC74,void *,void *,u16);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern u8 func_02043994(struct Bmp *b);
extern int _s32_div_f(int a, int b);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_0207F7A0(void);
extern void func_020862F0(void *p, int n);
extern void func_0207F7FC(void *p, int src, int n);
extern void func_0207F9B4(void);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_0207FA0C(void);
extern void func_0207FA40(void *,u32,u32);
extern void func_0207FADC(void);
u32 func_0216E474(void);
void func_0216E47C(void *block);
int func_0216E490(int a0);
int func_0216E4B0(int a, int b);
int func_0216E4EC(int a0, int a1);
void func_0216FC74(void *a, u16 b, u16 c, u16 d, void *e, void *f);
void func_0216FCA0(void *a, void *b);
void func_0216FD54(char *a, u32 b, u16 c, u16 d, u16 e, u16 f);
void func_0216FE04(char *p,void *q);
int func_0216FE2C(struct Rec *tbl, int idx, struct Pos *pos, u8 *flags);
extern const u16 d_02172A70[][4];
extern u16 d_02172554[][2];
extern u16 d_02172556[][2];
extern const char d_02172B54[];
extern u8 ov093_id[];
extern u8 ov092_id[];
extern u8 ov230_id[];
extern u8 d_021EFDAC[];
extern u8 d_021B9D94[];
extern u32 g_0214624C;
extern const IdHandler d_021725C0[][2];
extern u8 d_021725D8[][5];
extern u8 d_021725B8[];
extern char d_02172B64[];
extern char d_021725FC[];
extern const u32 d_021C39D4[];
extern char ov110_id[];
extern const u32 d_021C892C[];
extern u16 d_02172620[][7];
extern char d_02172B74[];
extern const Fmt d_021726A0[];






/*
 * Save-table size callback: returns 0x168, the size of the block that
 * func_0216E47C fills.  Pointer word 0x0216E475 at arm9 0x0209DC90.
 */
u32 func_0216E474(void)
{
    return 0x168;
}






/*
 * Save-table init callback: fills the 0x168-byte block with 0xFF bytes
 * (tail call to MIi_CpuClear32 through the pool word at 0x0216E48C).
 * Pointer word 0x0216E47D at arm9 0x0209DC94.
 */
void func_0216E47C(void *block)
{
    MIi_CpuClear32(0xFFFFFFFF, block, 0x168);
}








int func_0216E490(int a0)
{
    int a1;
    int a2;

a1 = 0;
a2 = ((struct Obj09169 *)((char *)a0))->f0;
a1 = ~a1;
    if (a2 != a1) goto loc_0216E4A6;
loc_0216E49A:
a2 = ((struct Obj09169 *)a0)->f4;
    if (a2 != a1) goto loc_0216E4A6;
loc_0216E4A0:
a0 = ((struct Obj09169 *)a0)->f8;
    if (a0 == a1) goto loc_0216E4AA;
loc_0216E4A6:
a0 = 1;
    return a0;
loc_0216E4AA:
a0 = 0;
    return a0;}






/*
 * lever: declaring x and y before the unsigned-long index restores the
 * table base, sentinel and index register allocation. The once300
 * permuter found this ordering; explicit-region one resolves both pools.
 */
int func_0216E4B0(int a, int b)
{
    int x;
    int y;
    unsigned long i;
    i = 0;
    do
    {
        x = d_02172A70[i][0];
        y = d_02172A70[i][1];
        if ((x == a) && (y == b))
            return d_02172A70[i][2];
        i++;
    }
    while ((x != 65535) && (y != 65535));
    return 30;
}






int func_0216E4EC(int a0, int a1)
{
    int idx = 30;

    if (func_0216E5FC(func_0216D598((void *)a0)) == 1)
        idx = func_0216E4B0(func_0216D590((void *)a0), func_0216D588((void *)a0));
    return idx;
}





int func_0216E51C(a, a1) void *a;




 int a1;




 { int i; unsigned int base; i=func_0216E4EC((int)a, a1); if(i!=30) { base=((struct Obj19138 *)((char *)func_0216D67C(a)))->f2C; return func_0216E490((int)((void *)(base+i*12))); } return 0; }

int func_0216E544(void *a, Vec_0216E544 *out) { int i; Vec_0216E544 *p; unsigned int base; i=func_0216E4EC((int)a, (int)out); if(i!=30) { base=((struct Obj19139 *)((char *)func_0216D67C(a)))->f2C; p=(Vec_0216E544 *)(base+i*12); if(func_0216E490((int)p)) { *out=*p; return 1; } } return 0; }


/*
 * lever: binding the getter's pointer result to tmp restores the base
 * load before the stride, while retaining the unsigned raw address sum.
 * Context shape: matched CC58 allocates 0x48 and stores input c at +44.
 * E4EC returns 30 unless E4FA compares equal to 1, then returns E4B0's
 * halfword or 30. Thus i <=65535 and i*12 <=786420; no Vec array bound
 * is assumed. D88C unconditionally initializes all 12 bytes of v.
 */
void func_0216E57C(void *a, int a1)
{
    int i;
    Vec_0216E57C *p;
    Vec_0216E57C v;
    Context *tmp;
    i = func_0216E4EC((int)a, a1);
    if (i != 30)
    {
        tmp = func_0216D67C(a);
        p = (Vec_0216E57C *) (tmp->raw44 + (i * 12));
        func_0216D88C(a, (struct VecFx32 *)&v);
        *p = v;
    }
}




/*
 * Whether the map cell under pos (x, z in whole tiles of 16 units) holds a
 * hit whose check returns 1.
 */
int func_0216E5B0(void *map, const VecFx32 *pos)
{
    void *hit = func_0216DDDC((u32)map, (s16_0216E474)((pos->x >> 4) / 4096), (s16_0216E474)((pos->z >> 4) / 4096), pos->y, 0x20000, (int)0);

    if (hit != 0 && func_0216E51C(hit) == 1)
        return 1;
    return 0;
}




/*
 * True for kind 0x6D and 0x2003..0x2005. The range test must be written
 * as `(u16)(id + 0xDFFD) <= 2`: `id >= 0x2003 && id <= 0x2005` keeps two
 * compares, `(u16)(id - 0x2003)` pools 0x2003 and subtracts.
 */
int func_0216E5FC(u16 id)
{
    if (id == 0x6D || (u16)(id + 0xDFFD) <= 2)
        return 1;
    return 0;
}




/*
 * Unlabelled leaf (sole blocker of ov018 func_0217C758): clears the word
 * at +0x18 and fills the {u16, u16, int} record at +0x1C.
 */
void func_0216E618(Obj *o, u16 x, u16 y, int z)
{
    Pos *p;

    o->f18 = 0;
    p = &o->pos;
    p->x = x;
    p->y = y;
    p->z = z;
}




void func_0216E62C(int a, int p, int id)
{
    int h;
    int t;
    int i;

    h = (int)func_0200CA1C((void *)a);
    t = func_02017E1C((void *)p, 5, 0);
    for (i = 0; i < 25; i++) {
        if (id == d_02172554[i][0]) {
            int v = d_02172556[i][0];
            if (t == 0x19c) {
                func_02017988((void *)p, (u16)v);
                func_0200CFA0((struct Blk37 *)h, (void *)p);
            }
            return;
        }
    }
}






int func_0216E680(int a0)
{
    int t4;

t4 = a0 + 0;
    if (t4 == 0) goto loc_0216E688;
loc_0216E686:
    a0 = ((int (*)())t4)();
loc_0216E688:
a0 = ~t4;
    return a0;}




/*
 * Four-state proc that pushes the tutorial capture task (func_0216EB98)
 * for the opponent's first Pokemon and then the result screens.
 * Byte-correct first draft (func_021CF5D8's species is a u32 here: no
 * truncation at the call).
 * Blocker (MATCH): two arm9 Thumb callees have no func_ label and no
 * matched file: 0x0201313C (`return bs->party[side]`, 8 bytes) and
 * 0x0202E818 (16 bytes). Seeds for the arm9 lane.
 *
 * 2026-10-05: byte-identical; the two wildcards resolve once shards exist for arm9 func_0201313C (matched file exists, no shard) and func_0202E818 (new matched/arm9 file, EXACT, this lane).
 */
int func_0216E68C(void *evt, u32 *state, Work *w)
{
    void *sys = w->sys;
    void *ctx = func_020120F4(sys);
    void *task;
    Task *t;
    u32 species;
    u32 flag;

    switch (*state) {
    case 0:
        task = func_020122C0(sys, 0, func_0216EB98, 0x28);
        t = func_020124E8(task);
        func_0216F02C((void **)t, sys, w->bs);
        flag = 1;
        t->f14 = 1;
        species = func_02017E1C(func_0201AB28(func_0201313C(w->bs, 1), 0), 5, 0);
        {
            void *proc = func_0201210C(sys);

            if (w->bs->f04 != 1)
                flag = 0;
            func_021CF5D8(species, w->f0c, flag, proc, &t->f24, t->f08->f18);
        }
        func_02012374(evt, task);
        (*state)++;
        break;
    case 1:
        if (w->f08 == 1) {
            func_0202E79C((void *)func_02012F20((int)ctx));
            return 1;
        }
        if (func_0216EFA8(func_02012A44(ctx), 0) == 1) {
            func_0202E79C((void *)func_02012F20((int)ctx));
            func_0201235C(evt, func_0215F6E8(sys));
        } else {
            func_02012374(evt, func_021BE92C(sys, func_0201210C(sys), 0, 0, 1, 0, 0));
        }
        (*state)++;
        break;
    case 2:
        if (func_0202E818((void *)func_02012F20((int)ctx)) == 1)
            func_02012374(evt, func_02181D8C(sys, 4));
        (*state)++;
        break;
    case 3:
        func_0202E79C((void *)func_02012F20((int)ctx));
        return 1;
    }
    return 0;
}




/*
 * Allocates a 0x10-byte task record (handler func_0216E68C) and fills it
 * from the arguments.
 */
int func_0216E7C8(int a0, int a1, int a2, int a3, int a4)
{
    int h;
    u32 *t;

    h = (int)func_020122C0((void *)a0, 0, func_0216E68C, 0x10);
    t = func_020124E8((struct Obj *)h);
    t[0] = a0;
    t[1] = a2;
    t[2] = a3;
    t[3] = a4;
    func_0216EE40((void *)a2, 0);
    func_02008DF0(func_02012F2C(func_020120F4((const struct Ctx *)a0)), 5);
    func_021AAABC(func_02188CE8((u8 *)a1));
    return h;
}




int func_0216E818(int a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    int h;
    int *t;
    int v;
    int w;
    int x;

    h = (int)func_020122C0((void *)a0, 0, func_0216EB98, 0x28);
    t = func_020124E8((struct Obj *)h);
    v = func_02188CE8((u8 *)a1);
    w = (int)func_02012F2C(func_020120F4((const struct Ctx *)a0));
    x = (int)func_02013090(4);
    func_021AA5CC((struct Ctx *)v, (void *)x, a2, a3, (void *)a4, a5, 4);
    func_0216EE20(a4, 0);
    func_02008DF0((struct Sub02008C20Obj *)w, 6);
    func_02008DF0((struct Sub02008C20Obj *)w, 0x56);
    func_0216F02C((void **)t, (void *)a0, (void *)x);
    t[5] = 1;
    if (a6 & 1) {
        func_02013144((char *)x, 0x100);
        t[6] = 1;
    }
    func_021CF748(a4, a1, (int *)((int)t + 0x24), (u16 *)(t[2] + 0x18));
    func_021AAABC(func_02188CE8((u8 *)a1));
    return h;
}




int func_0216E8CC(int a0, int a1, int a2)
{
    int h;
    int *t;

    h = (int)func_020122C0((void *)a0, 0, func_0216EB98, 0x28);
    t = func_020124E8((struct Obj *)h);
    func_0216F02C((void **)t, (void *)a0, (void *)a2);
    t[5] = 0;
    t[6] = 1;
    t[8] = 1;
    t[9] = 9;
    func_021AAABC(func_02188CE8((u8 *)a1));
    return h;
}




int func_0216E910(void *a0, void *a1, void *a2)
{
    int h;
    int *t;

    h = (int)func_020122C0((void *)a0, 0, func_0216EB98, 0x28);
    t = func_020124E8((struct Obj *)h);
    func_0216F02C((void **)t, (void *)a0, (void *)a2);
    t[5] = 0;
    t[7] = 1;
    t[6] = 1;
    t[9] = 9;
    *(u16 *)((char *)t[2] + 0x18) = 0x46b;
    func_021AAABC(func_02188CE8((u8 *)a1));
    return h;
}




/*
 * Set up the scripted catching-tutorial battle (Minccino Lv7 against
 * Patrat Lv2) and push func_0216EB98 as its task. First draft.
 */
void *func_0216E95C(void *sys, u32 arg, u32 heap)
{
    Loc loc;
    u16 h;
    void *ctx;
    void *bs;
    void *party1;
    void *party2;
    void *mon;
    void *task;
    Work_0216E95C *w;

    h = (heap & 0x7FFF) | 0x8000;
    ctx = func_020120F4(sys);
    bs = func_02013090(heap);
    party1 = func_0201A920(h);
    party2 = func_0201A920(h);
    mon = func_02030734(h, func_020173EC(), 1, d_02172B54, 0x1DA);
    func_0201756C(mon, 572, 7, 0);
    func_02017E40(mon, 0x36, 1);
    func_02017E40(mon, 0x37, 45);
    func_02017E40(mon, 0x38, 0);
    func_02017E40(mon, 0x39, 0);
    func_0201A98C(party1, mon);
    func_0201756C(mon, 504, 2, 0);
    func_02017E40(mon, 0x36, 33);
    func_02017E40(mon, 0x37, 43);
    func_02017E40(mon, 0x38, 0);
    func_02017E40(mon, 0x39, 0);
    func_0201A98C(party2, mon);
    func_021AA304((struct Info *)(&loc), ctx, (void *)arg);
    loc.f04 = 5;
    loc.f00 = 0;
    func_020135C0(bs, ctx, party1, party2, &loc, heap);
    func_020307B0(mon);
    func_020307B0(party2);
    func_020307B0(party1);
    task = func_020122C0(sys, 0, func_0216EB98, 0x28);
    w = func_020124E8(task);
    func_0216F02C((void **)w, sys, bs);
    w->f14 = 1;
    func_021CF5D8(504, 5, 0, (void *)arg, &w->f24, w->f08->f18);
    w->f24 = 0;
    return task;
}




/*
 * Every concrete byte matches; the one wildcard is the bl to 0x02012FD8, an
 * unlabelled 12-byte arm9 Thumb leaf (ldr r0,[r0]; tail call
 * func_020071CC(r0, 0x43)) with no label, no shard and so no witness.
 * as `void *func_02012FD8(void **p) { return func_020071CC(*p, 0x43); }`
 * (symbols: func_020071CC 0x020071CC thumb), which is outside an overlay
 * lane's write set; once it has a shard this file should verify EXACT.
 *
 * The level argument to func_02017588 is passed untruncated here, so its
 * extern takes u32 level rather than the u16 other callers declare.
 */
void *func_0216EAB0(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 idx)
{
    void *data;
    void *task;
    void *mon;
    u32 old;
    u32 species;
    u32 level;
    u32 id;
    u32 rnd;

    data = func_02012FD8(func_020120F4(a0));
    task = (void *)func_0216E818((int)a0, a1, a2, a3, a4, a5, a6);
    if (sub_0200E740(data, idx) != 0) {
        mon = func_0201AB28(*(void **)(*(u8 **)((u8 *)sub_020124E8(task) + 8) + 0x28), 0);
        old = func_02017E1C(mon, 5, 0);
        species = sub_0200E788(data, idx, 0x15);
        level = sub_0200E74C(data, idx);
        id = sub_0200E7B4(data, idx);
        rnd = sub_0200E7A4(data, idx);
        func_02017588(mon, species, level, id, -1, rnd);
        if (sub_0200E76C(data, idx) != 0) {
            func_02017E40(mon, 10, sub_0200E780(data, idx));
        }
        func_02017E40(mon, 0x74, (u32)sub_0200E7AC(data, idx));
        func_020178D8(mon, (u16)old);
        func_02017FA8(mon);
    }
    return task;
}




/*
 * lever:    case 1's argument-less `bl func_02189A08` takes proc (the
 *           func_0201210C result) as its hidden r0 argument: the matched
 *           ov021 definition is int func_02189A08(unsigned char *p). That
 *           keeps proc in r0 through the dispatch, the index in r1 and the
 *           r2 copy of proc for cases 2 and 10 (457 -> 2 bytes). The ov230
 *           probe calls resolve with the `ov230d` token, prototypes copied
 *           from the matched twin src/matched/arm9/func_02011D9C.c.
 * residue:  case 7 zeroes its spilled `ok` (sp+0xC) through r2 in the image
 *           (`movs r2,#0; str r2,[sp,#0xc]` at 0x0216ECCC), r0 in the compile.
 *           No change from ok as u32, u8, enum, function-scope, passed as the
 *           seed, or with start/end locals ahead of it; permuter 300 found
 *           nothing (baseline agrees, DIFF 2/612).
 *           unlabelled: `ldr r1,[r0]; str r1,[r0,#8]; movs r1,#0; str
 *           r1,[r0]; bx lr`, verified C not filed: arm9 is the integrator's);
 *           0x0216EFDC (ov010 unlabelled tail-call leaf, not filed while an
 *           arm9 leaf blocks); ov093_id/ov092_id pooled ids passed to
 *           func_02012444, which is not in OVERLAY_ID_CONSUMERS;
 *           d_021EFDAC/d_021B9D94 (proc data of ov093/ov092) unwitnessed.
 * prototype conflicts (parked, matched callees not edited):
 *           func_0216F054 (ov010 0x0216F054, src/matched/ov/func_0216F054.c)
 *           is defined int(int a0, int a1) but a1 is overwritten before any
 *           read (`ldr r1,[r0,#0x20]` at 0x0216F054); the three call sites
 *           here set only r0 (`adds r0, r5, #0; bl`). func_02012F20 (arm9,
 *           src/matched/arm9/func_02012F20.c) is defined int(int p0..p3) and
 *           reads only p0; both sites here set only r0 (`ldr r0,[sp,#0x10];
 *           bl`). The C below declares both with one parameter.
 * runs:     4 iteration + checks (2 + 2 + 1) + permuter 300; one cleanup run.
 * checks:   1 every callee re-derived from its matched definition: func_02189A08 takes the live proc in r0 (fixed), F054/2F20 definitions over-declare (conflict above); 2 twin func_02011D9C gives the ov230d probe tokens and prototypes (resolved 3 sites), u32 start local no change; 3 ok as u32 / enum no change; 4 u8 flag idiom (a-narrow-flag-local-is-spilled) no change, zero-register idioms read; 5 idioms re-listed, nothing new applies
 * note:     2026-10-05 wave P19 lane 6 recoup: byte-correct (612/612, 0 bytes off).
 *           Lever: case 7 writes ok in both arms (`if (probe == ~f) ok = 1; else ok = 0;`
 *           with `int ok;` uninitialised), which moves the spilled zero to r2 (was r0,
 *           2 bytes). Tried before it: six per-function pragmas (lifetimes 14 B, the rest
 *           2 B), function-scope ok, ok as the probe seed or a separate zero local, probe
 *           result in a local (3 B), ternary sum (258 B). Data words resolve with
 *           `data ov093` / `data ov092` tokens. Leaf witnesses filed:
 *           src/matched/arm9/func_0202E80C.c and src/matched/ov/ov010_func_0216EFDC.c (both
 *           EXACT c99 and c); the three unresolved call sites resolve once the integrator
 *           refreshes the manifest. Callee arity conflicts (matched definitions
 *           over-declare, callers pass less): func_0216F054 and func_02012F20.
 */
int func_0216EB98(void *evt, u32 *state, Work_0216EB98 *w)
{
    void *sys = w->sys;
    void *p04 = w->f04;
    void *proc = func_0201210C(sys);
    u32 sum = 0x013A1AB5;

    switch (*state) {
    case 0:
        func_02012374(evt, func_02029BCC(sys, w->f08->f18));
        (*state)++;
        break;
    case 1:
        func_021CF498((void *)func_02189A08(proc), (u32)evt, (int)w->f24);
        (*state)++;
        break;
    case 2:
        func_02012374(evt, (void *)func_020144DC((int)sys, (int)proc));
        (*state)++;
        break;
    case 3:
        func_0201447C(func_02012B38(p04), 1);
        func_0202E79C((u8 *)func_02012F20((int)p04));
        func_02012444(evt, (u32)ov093_id, (u32)d_021EFDAC, (u32)w->f08);
        (*state)++;
        break;
    case 4:
        w->f10 = w->f08;
        w->f0c = p04;
        func_02012444(evt, (u32)ov092_id, (u32)d_021B9D94, (u32)&w->f0c);
        (*state)++;
        break;
    case 5:
        func_02034AC4((s32_0216E910)ov230_id);
        func_0201447C(func_02012B38(p04), 0);
        func_0202E80C((void *)func_02012F20((int)p04));
        (*state)++;
        break;
    case 6: {
        int ok = 0;

        if (func_021882DC((void (*)(void))func_0216E680, (void (*)(void))func_0216F064, 0) == ~(u32)func_0216F064)
            ok = 1;
        sum += ok ? 0 : 0x3D1;
        func_0216EFF0((int *)w, p04);
        if (w->f1c != 0)
            func_02168D30(*(void **)func_02012F50(p04), (struct Result *)w->f08);
        (*state)++;
        ok = 0;
        if (func_02188354((void (*)(void))func_0216E680, (void (*)(void))func_0216F070, 0) == ~(u32)func_0216F070)
            ok = 1;
        sum += ok ? 0 : 0x5D1;
        break;
    }
    case 7: {
        int ok;

        if (func_02188390((void (*)(void))func_0216E680, (void (*)(void))func_0216F07C, 0) == ~(u32)func_0216F07C)
            ok = 1;
        else
            ok = 0;
        sum += ok * 0x9D;
        if (w->f18 == 0 && func_0216EFDC((int *)w) == 1)
            func_02012374(evt, func_02029B28(sys, 0x1E));
        else
            func_02012374(evt, func_02029C00(sys));
        func_02034A5C((s32_0216E910)ov230_id);
        (*state)++;
        break;
    }
    case 8:
        if (w->f18 == 0 && func_0216EFDC((int *)w) == 1) {
            if (w->f14 == 1) {
                func_0216F054((int)w);
                return 1;
            }
            func_0216F054((int)w);
            func_0201235C(evt, func_0215F6E8(sys));
            return 0;
        }
        func_02012374(evt, func_020145CC(sys));
        (*state)++;
        break;
    case 9:
        func_02012374(evt, func_02029CC0(sys));
        (*state)++;
        break;
    case 10:
        if (w->f14 == 0)
            func_02012374(evt, (void *)(int)func_021BE92C(sys, (void *)((int)proc), 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 11:
        func_0216F054((int)w);
        return 1;
    }
    if (sum % 0x1933 != 0) {
        func_020056A0((void (*)(void *, void *))func_02011D34, 0, 0x7F);
        g_0214624C++;
    }
    return 0;
}




/*
 * Mode word out of the overlay call decides between zero, one and two;
 * two of the modes are refused outright.
 */
int func_0216EDFC(void *a0)
{
    int r = 1;
    int v;

    v = func_0202A3FC(func_0202A230(a0, 1));

    if (v == 0xC || v == 9)
        return 0;
    if (v != 2)
        r = 2;

    return r;
}




/*
 * Dispatches through the two-column handler table d_021725C0, row chosen
 * by func_0216EDFC's classification of `id`.
 */
void func_0216EE20(u16 id, int col)
{
    d_021725C0[func_0216EDFC((void *)id)][col](id);
}




/*
 * Reports the species of the first party member to one of three
 * notifiers.
 *
 * MATCH, first draft (2026-09-28 tree_ov010_4): the one wildcard is arm9
 * 0x0201313C, an unlabelled Thumb leaf (`lsls r1, #2; adds r0, r1;
 * ldr r0, [r0, #0x24]; bx lr`) inside the listing's ARM data run.
 *
 * 2026-10-05: byte-identical; the wildcard is arm9 func_0201313C (matched file exists, no shard yet); integrator shard resolves it.
 */
void func_0216EE40(void *p, int which)
{
    u16 species;

    species = func_02017E1C(func_0201AB28(func_0201313C(p, 1), 0), 5, 0);
    switch (which) {
    case 0:
        func_0216505C(species);
        break;
    case 1:
        func_02165078(species);
        break;
    case 2:
        func_021653F4(species);
        break;
    }
}




/*
 * After a battle: unless the outcome is 0 or 2, reports the lead party
 * member's state (fainted, at half HP or less, a move out of PP, a status
 * condition) by name, then reports the species depending on the mode and
 * outcome.
 */
void func_0216EE7C(BattleEndCtx *c)
{
    BattleEnd *st;
    void *party;
    void *mon;
    void *name;
    u16 hp;
    u16 maxHp;
    int i;

    st = c->st;
    party = func_02012934(c->sys);
    mon = func_0201AB28(party, func_0201AB18(party));
    if (st->outcome != 0 && st->outcome != 2) {
        name = func_020457B0(12, 0x8004);
        func_02017E1C(mon, 0x73, (u32)name);
        hp = func_02017E1C(mon, 0xA0, 0);
        maxHp = func_02017E1C(mon, 0xA1, 0);
        if (hp == 0)
            func_021654AC(name);
        else if (hp * 2 <= maxHp)
            func_02165424(name);
        for (i = 0; i < 4; i++) {
            if (func_02017E1C(mon, 0x36 + i, 0) != 0 && func_02017E1C(mon, 0x3A + i, 0) == 0) {
                func_02165468(name);
                break;
            }
        }
        if (func_02017E1C(mon, 0x9D, 0) != 0)
            func_021654F0(name);
        func_02045808(name);
    }
    switch (st->mode) {
    case 0:
        if (st->outcome == 3)
            func_0216EE40(st, 2);
        else if (st->outcome == 1)
            func_0216EE40(st, 1);
        break;
    case 1:
        if (st->outcome == 1)
            func_0216EE20(*st->result, 1);
        break;
    }
}




int func_0216EF84(int a0)
{
    int a1;
    int t4;
    void *p;

t4 = *(int *)&((struct Obj00020 *)a0)->f8;
a0 = ((struct Obj00020 *)((char *)a0))->f0;
    p = func_020120F4((const struct Ctx *)a0);
loc_0216EF8E:
    a0 = (int)func_02012F2C(p);
loc_0216EF92:
a1 = ((struct Obj12059 *)((char *)t4))->f0;
    if (a1 != 0) goto loc_0216EFA6;
loc_0216EF98:
t4 = t4 + 0x8c;
a1 = ((struct Obj12059 *)((char *)t4))->f0;
    if (a1 != 4) goto loc_0216EFA6;
loc_0216EFA0:
a1 = 0x4f;
    a0 = func_02008DF0((struct Sub02008C20Obj *)a0, a1);
loc_0216EFA6:
    return a0;}




int func_0216EFA8(int a, int b)
{
    if (b == 4)
        return 0;
    if (d_021725D8[a][b] == 0)
        return 1;
    return 0;
}




/*
 * Unlabelled leaf, blocker of ov021 func_021B50D0: byte table lookup, 0xFF maps to 1.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u8 func_0216EFCC(int i)
{
    u8 v = d_021725B8[i];

    if (v == 0xff) {
        v = 1;
    }
    return v;
}




/*
 * note:     2026-10-05 wave P19 lane 6: tiny unlabelled tail-call leaf filed as
 *           the witness for the calls in ov010 func_0216EB98. Reads the info
 *           block at w[2] and tail-calls func_0216EFA8(info[0x8c / 4], info[0]).
 */
int func_0216EFDC(int *w)
{
    int *q = (int *)w[2];
    return func_0216EFA8(q[0x8c / 4], q[0]);
}



/*
 * func_0202C83C's body consumes only r0/r1, forwarding those to
 * func_0202C794; original supplies no new r2/r3. Legacy trailing
 * arguments are omitted. func_02012AC8 consumes the preceding result.
 */
void func_0216EFF0(int *p,void *a) {
    func_02012A4C(a,((struct Obj19144 *)(*(char * *)&((struct Obj00020 *)p)->f8))->f8C);
    func_0215E5B0(a,(void *)p[2]);
    func_0216EE7C((struct BattleEndCtx *)p);
    func_0216EF84((int)p);
    func_0202C83C(p[0],func_02012AC8(func_020127A4(a)));
}



void func_0216F02C(void **p,void *a,void *b) { int zero=0; func_02082A7C(0,p,40); p[0]=a; p[1]=func_020120F4(a); p[2]=b; p[5]=(void *)zero; p[6]=(void *)zero; p[7]=(void *)zero; }




int func_0216F054(int a0)
{
    int a1;

a1 = ((struct Obj12060 *)a0)->f20;
    if (a1 != 0) goto loc_0216F062;
loc_0216F05C:
a0 = ((struct Obj12060 *)a0)->f8;
    a0 = func_020130B4(a0);
loc_0216F062:
    return a0;}




int func_0216F064(int a0)
{

    a0 = func_0203F0A8();
loc_0216F06A:
    a0 = func_0203F0A8();
loc_0216F06E:
    return a0;}




int func_0216F070(int a0)
{

    a0 = func_0203F0A8();
loc_0216F076:
    a0 = func_0203F0A8();
loc_0216F07A:
    return a0;}




int func_0216F07C(int a0)
{

    a0 = func_0203F0A8();
loc_0216F082:
    a0 = func_0203F0A8();
loc_0216F086:
    return a0;}




int func_0216F088(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj09170 *)((char *)t4))->f0;
    if (a0 == 0) goto loc_0216F0A8;
loc_0216F092:
    a0 = func_02031330((void *)a0);
loc_0216F096:
    if (a0 != 0) goto loc_0216F0A8;
loc_0216F09A:
a0 = ((struct Obj09170 *)((char *)t4))->f0;
    a0 = func_0203133C(a0);
loc_0216F0A0:
a0 = 0;
((struct Obj09170 *)((char *)t4))->f0 = a0;
a0 = 1;
    return a0;
loc_0216F0A8:
a0 = 0;
    return a0;}




int func_0216F0AC(void *a, int b, T24 *c)
{
    W_0216F0AC *w;

    func_0203064C(1, 0x26, 0x18000);
    w = func_0203159C(a, 0x20, 0x26);
    func_02082BCC(w, 0, 0x20);
    w->f00 = 0x26;
    w->f18 = func_02030734((u16)w->f00, 0x18, 1, d_02172B64, 0x9f);
    *w->f18 = *c;
    *(void **)w->f18 = func_02030734((u16)w->f00, 0x678, 1, d_02172B64, 0xa1);
    func_0216F40C(*(void **)w->f18, (void *)c->w[1], 0, w->f18->w[2], (u16)w->f00);
    w->f1c = ((struct Obj19150 *)(*(char **)w->f18))->f6;
    return 1;
}



int func_0216F144(void *a,int b,int c) { W_0216F144 *w; func_0203064C(1,38,0x18000); w=func_0203159C(a,32,38); func_02082BCC(w,0,32); w->w[0]=38; w->w[6]=c; return 1; }




int func_0216F174(int a, int *b, int c, int d)
{
    switch (*b) {
    case 0:
        *b = func_0216F244((char *)d, (char *)c);
        break;
    case 1:
        *b = func_0216F288((int *)d);
        break;
    case 2:
        *b = func_0216F2B4((char *)d);
        break;
    case 3:
        *b = func_0216F2E0((char *)d);
        break;
    case 4:
        *b = func_0216F31C((char *)d);
        break;
    case 5:
        *b = func_0216F378((char *)d);
        break;
    case 6:
        *b = func_0216F3B0((char *)d);
        break;
    case 7:
    default:
        return 1;
    }
    return 0;
}




/*
 * blocked:  listing 72 compiled 70
 */
int func_0216F1E0(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;
    int t6;
    u8 *p;

t5 = a2 + 0;
t6 = a0 + 0;
a0 = ((struct Obj09171 *)t5)->f8;
t4 = a3 + 0;
    if (a0 == 0) goto loc_0216F202;
loc_0216F1EE:
a0 = ((struct Obj09171 *)t5)->f4;
    p = func_02012944((void *)a0);
loc_0216F1F4:
    a0 = func_02008554((const struct Sub0200852CObj *)p);
loc_0216F1F8:
a1 = ((struct Obj07207 *)t4)->f1C;
    if (a1 == a0) goto loc_0216F202;
loc_0216F1FE:
    a0 = func_02027174(a0);
loc_0216F202:
a0 = ((struct Obj07207 *)t4)->f18;
a0 = ((struct Obj07206 *)a0)->f10;
((struct Obj09171 *)t5)->f10 = a0;
a0 = ((struct Obj07207 *)t4)->f18;
a0 = ((struct Obj07206 *)((char *)a0))->f0;
    a0 = func_020307B0((void *)a0);
loc_0216F210:
a0 = ((struct Obj07207 *)t4)->f18;
    a0 = func_020307B0((void *)a0);
loc_0216F216:
a0 = t6 + 0;
    func_020315D4((struct S020315D4 *)a0);
loc_0216F21C:
a0 = 0x26;
    func_020306F0(a0);
loc_0216F222:
a0 = 1;
    return a0;}




int func_0216F228(void *a, int b, int c, char *d)
{
    func_020307B0(((struct Obj19151 *)d)->f18);
    func_020315D4(a);
    func_020306F0(0x26);
    return 1;
}




int func_0216F244(char *a, char *b)
{
    char *q;

    switch (((struct Obj19152 *)b)->f14) {
    case 1:
        return 1;
    case 2:
        return 1;
    case 3:
        return 5;
    case 0:
    default:
        q = **(char ** *)&((struct Obj01640 *)a)->f18;
        if (((struct Obj12408 *)q)->f33 == 0 && ((struct Obj12408 *)q)->f1C != 0)
            return 5;
        return 1;
    }
}



/*
 * func_02031324 forwards r0 to 02031354, which reads the heap input
 * and returns the allocation in r0. func_02031348 forwards all four
 * inputs to 020314F4, which reads/stores r0-r3. Legacy void(void)
 * prototypes omit these live inputs and the observed return value.
 */
int func_0216F288(int *p) { if(p[2]==0) p[2]=(int)func_02031324((u16)p[0]); func_02031348((void *)p[2],-1,d_021725FC,(void *)p[6]); return 2; }



/*
 * Extent: two-byte zero alignment padding at 0216F2DE.
 */
int func_0216F2B4(char *p) { int v; if (!func_0216F088((int)(p+8))) return 2; v=((struct Obj19154 *)(*(char * *)&((struct Obj01640 *)p)->f18))->fC; if(v==1) return 3; if(v==2) return 5; return 7; }





/*
 * Interface: 02031324 veneer forwards heap in r0 and returns allocation from
 * 02031354; 02031348 forwards all four arguments to 020314F4.
 */
int func_0216F2E0(char *p) { if (((struct Obj01640 *)p)->f8==0) ((struct Obj01640 *)p)->f8=func_02031324((u16)(((struct Obj01640 *)p)->f0)); ((struct Obj01640 *)p)->fC=func_02012EBC(((struct Obj19155 *)(*(char * *)&((struct Obj01640 *)p)->f18))->f4); func_02031348(((struct Obj01640 *)p)->f8,(u32)ov110_id,d_021C39D4,p+12); return 4; }






/*
 * Byte-correct. Blocker: func_0200E714 (site +004C) is an unlabelled ARM9 Thumb
 * leaf (copies four halfwords to dst[idx*4]) whose only caller is this
 * function; no witness. Its C is parked: docs/notes/pkt_ov010_0200E714.c.txt
 * (register naming r3/r4 swapped).
 */
int func_0216F31C(char *a)
{
    char *w;
    u16 *src;
    int t;

    if (func_0216F088((int)(a + 8)) == 0)
        return 4;
    if (*(u16 **)(a + 0x14) != 0) {
        func_02012EBC((struct Big *)(*(int *)(*(char **)(a + 0x18) + 4)));
        t = func_0200E6F0();
        w = **(char ***)(a + 0x18);
        src = *(u16 **)(a + 0x14);
        *(u16 *)(w + 0x6c) = src[0];
        *(u16 *)(w + 0x6e) = src[1];
        *(u16 *)(w + 0x70) = src[2];
        *(u16 *)(w + 0x72) = src[3];
        func_0200E714((struct Rec0200E714 *)t, 0, *(void **)(a + 0x14));
        func_0202715C((u32)(*(void **)(a + 0x14)));
    }
    return 1;
}





/*
 * hint. Pooled request ID is 110, so no proven ov111 loading path yet.
 * 2026-10-05: data hints now carry an overlay token that has a witness; EXACT.
 *
 * Interface: veneers preserve arguments and result as shown by their full
 * forwarding targets 02031354 and 020314F4.
 */
int func_0216F378(char *p) { if (*(void **)(p+8)==0) *(void **)(p+8)=func_02031324((u16)(*(u32 *)p)); *(void **)(p+12)=func_02012EBC(*(void **)(*(char **)(p+24)+4)); func_02031348(*(void **)(p+8),(u32)ov110_id,d_021C892C,*(void **)(p+24)); return 6; }





/*
 * Extent: two-byte zero alignment padding at 0216F3D2.
 */
int func_0216F3B0(char *p) { if (!func_0216F088((int)(p+8))) return 6; if (((struct Obj19156 *)(*(char * *)&((struct Obj01640 *)p)->f18))->fC==3) return 1; return 7; }






/*
 * Sums func_02008DFC over one seven-entry row of a u16 table (rows of 14
 * bytes at 0x02172620), stopping at the first zero entry and clamping the
 * running sum to cap.
 */
u32 func_0216F3D4(void *p, int idx, u32 cap)
{
    u32 sum;
    int i;

    sum = 0;
    for (i = 0; i < 7; i++) {
        if (d_02172620[idx][i] == 0)
            break;
        sum += func_02008DFC(p, d_02172620[idx][i]);
        if (sum > cap)
            sum = cap;
    }
    return sum;
}






/*
 * Fills a 0x674-byte profile record from the save (name, flags, two RTC
 * dates, seven capped counters, a 0x600-byte blob). Byte-correct: 944/944,
 * every concrete byte right.
 *
 * Levers: the fifth (stack) parameter is `volatile u16`, which is what makes
 * the image re-read it from its stack home at both uses (0x0216F66C and
 * 0x0216F760); held in a register it takes r6 and the constant 1 that the
 * image keeps in r7 from 0x0216F608 to the fl0 insert at 0x0216F6E2 is
 * rematerialised instead. `out->f08 = 0` is written before `out->kind`.
 *
 * Blocker (MATCH, two sites): 0x02010F7C and 0x02010F8C are unlabelled ARM9
 * Thumb thunks whose only caller is this function, so neither call has a
 * witness. 0x02010F7C is `ldr r3, =0x02048F61; adds r2, r0, #0; movs r0,
 * #0x26; movs r1, #0; bx r3` (a heap-id forwarder, `return
 * func_02048F60(0x26, 0, heap);`), 0x02010F8C is `ldr r3, =0x020307B1;
 * bx r3` (`func_020307B0(p);`). Matching either thunk (ARM9 territory)
 * closes that site.
 */
void func_0216F40C(Profile *out, void *save, int mode, int flag, volatile u16 heap)
{
    RTCDate date;
    RTCTime time;
    u8 work[4];
    void *x28;
    void *x24;
    void *player;
    void *x1c;
    Clock *clock;
    void *x14;
    void *x10;
    void *x0c;
    void *p;
    void *q;
    u8 i;
    u8 bit;

    x28 = func_02012EBC(save);
    x24 = func_020089C0(x28);
    player = func_02012944(save);
    x1c = func_02012F08(save);
    clock = (Clock *)func_02008B14(x28);
    x14 = func_02008C58(x28);
    x10 = func_0200E6E8((u32)x28);
    x0c = func_0200CA1C(save);

    if (func_020084BC(player) == 0) {
        MIi_CpuCopy16(func_020084F4(player), out->name, 16);
    } else {
        out->name[0] = 'N';
        out->name[1] = 'o';
        out->name[2] = 'N';
        out->name[3] = 'a';
        out->name[4] = 'm';
        out->name[5] = 'e';
        out->name[6] = func_02045A98();
    }
    out->f03 = (u32)func_0216F830(save);
    out->b1 = (u32)func_02008550(player);
    out->f28 = func_02008530(player);
    out->f20 = func_0200C274(x1c);
    out->f08 = 0;
    out->kind = 0x15;
    for (i = 0, bit = 1; i < 8; i++) {
        if (func_0200C234(x1c, i) == 1)
            out->f08 |= bit;
        bit <<= 1;
    }

    if (mode == 1) {
        p = (void *)func_02012FCC((int)save);
        out->f06 = (u32)func_02008554(player);
        out->b0 = 0;
        out->f1c = 0;
        out->f2a = (u32)func_0200864C(p);
        out->f2e = (u32)func_02008650(p);
    } else {
        out->f06 = (u32)func_02008554(player);
        out->b0 = 1;
        out->f1c = (u32)func_02012FCC((int)save);
    }
    out->f48 = (u32)func_02008A0C(x24);
    out->b4 = (u32)func_02008A28(x24);
    func_0200E6FC(x10, (u32)0, (struct Rec0200E6FC *)out->f6c);

    RTC_ConvertSecondToDateTime(&date, &time, clock->sec1);
    out->year1 = date.year;
    out->month1 = date.month;
    out->day1 = date.day;
    if (clock->sec2 == 0) {
        out->year2 = 0;
        out->month2 = 0;
        out->day2 = 0;
        out->hour2 = 0;
        out->minute2 = 0;
    } else {
        RTC_ConvertSecondToDateTime(&date, &time, clock->sec2);
        out->year2 = date.year;
        out->month2 = date.month;
        out->day2 = date.day;
        out->hour2 = time.hour;
        out->minute2 = time.minute;
    }

    out->f38 = func_0216F3D4(x14, 0, 999999999);
    out->f3c = func_0216F3D4(x14, 1, 999999999);
    out->f40 = func_0216F3D4(x14, 2, 999999999);
    out->f44 = func_0216F3D4(x14, 3, 999999999);
    out->f4c = func_0216F3D4(x14, 4, 999999999);
    out->f50 = func_0216F3D4(x14, 5, 999999999);
    out->f54 = func_0216F3D4(x14, 6, 999999999);
    out->f58 = func_0200C1DC(x1c);
    out->f5c = func_0216F3D4(x14, 7, 9999);

    q = func_0200BE48(x28);
    p = func_02010F7C(heap);
    func_0200BF54(q, work, 2);
    out->f5e = func_0216FEAC(p, func_020127B8(save), work);
    func_02010F8C(p);

    out->f60 = func_0216F3D4(x14, 8, 9999);
    out->f62 = func_0200C184(x1c);
    out->f64 = func_02008EA0(x14);
    out->f66 = (u32)func_02008E78(x14);
    out->fl0 = (u32)func_020090E0((const struct Sub020090B0Obj *)func_0200921C(save));
    if (func_0200BF94((struct Rec1B0 *)func_0200BE48(x28)) != 0)
        out->fl1 = 1;
    if (out->f60 != 0)
        out->fl2 = 1;
    if (func_02008DFC(x14, (u16)0x78))
        out->fl3 = 1;
    if (func_02008DFC(x14, (u16)0x79))
        out->fl4 = 1;
    if (func_020142E8((void *)func_0201296C(save), 2402) == 1)
        out->b2 = 1;
    else
        out->b2 = 0;
    out->f24 = func_0200D0AC(x0c, heap);
    out->b3 = (u32)func_020089D0(x24);
    MI_CpuCopy8(func_020089CC(x24), out->f74, 0x600);
    out->b6 = flag;
}





Record_0216F2E0 *func_0216F7BC(void *a,u32 heap,void *b) { Record_0216F2E0 *p; p=func_02030734(heap,24,1,d_02172B64,0x321); func_02082BCC(p,0,24); p->f00=0; p->f04=a; p->f0c=0; p->f08=b; return p; }




Record_0216F7F4 *func_0216F7F4(void *a,u8 *b,u32 heap) { Record_0216F7F4 *p; p=func_02030734(heap,24,1,d_02172B64,0x33a); p->f00=b; p->f04=a; p->f0c=0; b[4]=b[4]&~0x40; p->f00[4]|=0x80; return p; }





/*
 * Counts how many of five save-data conditions hold.
 *
 * Byte-correct (MATCH*, the 136-byte extent includes two bytes of pad).
 * unlabelled ARM9 Thumb thunk (`ldr r0, [r0]; ldr r3, =0x020071CD;
 * movs r1, #0x3a; bx r3`, i.e. `return func_020071CC(*p, 0x3A);`, with the
 * sibling at 0x02012F00 passing 0x3B) whose only caller is this function.
 * Matching that thunk (ARM9 territory) or seeding its start closes this file.
 */
int func_0216F830(void *save)
{
    int n;
    void *a;
    void *b;
    void *c;

    n = 0;
    a = func_02012EF0(save);
    b = func_02012F44(save);
    c = func_020127B8(save);
    if (func_020142E8((void *)func_0201296C(save), 0x960))
        n++;
    if (func_0200D298(func_0200CA1C(save)))
        n++;
    if (func_0200DBA0(a, 7, 0) && func_0200DBA0(a, 8, 0))
        n++;
    if (func_0200A73C(b))
        n++;
    if (func_0200BDF8(c) >= 30 && func_0200BDFC(c) >= 30)
        n++;
    return n;
}





int func_0216F8B8(int a0, int a1)
{
    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0216F8C0:
    func_0216F900(v0);
loc_0216F8C4:
a0 = 0;
    return a0;}





/*
 * blocked:
 */
int func_0216F8C8(int a0, int a1)
{
    func_021F385C((void *)func_0201210C((void *)func_0215A5DC((void *)a1)));
    return 0;
}





int func_0216F8DC(int a0, int a1)
{    int t5;
    void *task;
    void *v0;
    void *v1;

t5 = a1 + 0;
a0 = t5 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216F8E6:
a0 = t5 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216F8EE:
    task = func_021F38BC(v1);
loc_0216F8F2:
    a0 = func_0215897C(v0, task);
loc_0216F8FA:
a0 = 1;
    return a0;}




/*
 * Extent: two-byte zero alignment padding at 0216F916.
 * Interface: the call explicitly supplies r1=0x36 even though the leaf reads only r0.
 */
void func_0216F900(void *p) { *func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(p)), 0x36) = 1; }




void *func_0216F918(u32 heap) { void *p; p=func_02030734(heap,28,0,d_02172B74,35); func_02082BCC(p,0,28); return p; }





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
 *   python tools/match.py one --src src/matched/func_0216F940.c \
 *       --func func_0216F940 --addr 0x0216F940 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216F940(void *a0, unsigned a1, unsigned a2, unsigned a3)
{

    func_020307B0(a0);
}





static inline int Ent_IsEnd(Ent x)
{
    return x.move == 0xFFFF && x.level == 0xFFFF;
}





static inline u16 Ent_Level(Ent x)
{
    return x.level;
}





static inline u16 Ent_Move(Ent x)
{
    return x.move;
}





/*
 * Builds the list of level-up moves a mon could still learn: reads
 * species/form/level and its 4 current moves, loads the learnset (26
 * {move, level} pairs, 0xFFFF/0xFFFF terminated) with func_0201ADD0, and
 * collects moves at or below its level that it neither knows nor already
 * collected. Returns the 0x34-byte list (caller frees); frees the learnset.
 *
 * pass 2 2026-10-06 P2L52: EXACT (also EXACT with --lang c). Load-bearing:
 *   - Every entry access is a by-value inline helper called on `tbl[j]`
 *     itself (no named entry local). The argument is not a plain local, so
 *     each call keeps its own parameter copy (the 8 stack Ent slots of the
 *     image): CSE makes the shared tbl[j] temp at sp+0x18, loop invariants
 *     make the copies before the k and m loops, and the parameter copies in
 *     the loops keep their stores inside the loop. Named Ent locals or
 *     helpers called on a plain local are copy-propagated or substituted.
 *   - `for` loops everywhere with `n = 0, j = 0` in the j loop (propagation
 *     on: the hoisted zero argument is the copy of i, the m guard is
 *     `cmp n,#0; bls`). A do-while k or m loop hoists the in-loop copy.
 *   - `Ent *tbl` declared first: spill slots species 0x10, form 0xc, tbl 0x14.
 *   - The file name pool word is d_02172B74 (the old header said 02173B74).
 */
u16 *func_0216F948(void *mon, u32 heap)
{
    Ent *tbl;
    u16 cur[4];
    u16 species;
    u8 form;
    u8 level;
    u8 i;
    u8 n;
    u8 j;
    u8 k;
    u8 m;
    u16 *out;

    species = func_02017E1C(mon, 5, 0);
    form = func_02017E1C(mon, 0x6F, 0);
    level = func_02017E1C(mon, 0x9E, 0);
    for (i = 0; i < 4; i++)
        cur[i] = func_02017E1C(mon, 0x36 + i, 0);
    tbl = (Ent *)func_02030734(heap, 0x68, 0, d_02172B74, 0x55);
    out = (u16 *)func_02030734(heap, 0x34, 0, d_02172B74, 0x56);
    func_0201ADD0(species, form, tbl);
    for (n = 0, j = 0; j < 26; j++) {
        if (Ent_IsEnd(tbl[j])) {
            out[n] = 0xFFFF;
            break;
        }
        if (Ent_Level(tbl[j]) > level)
            continue;
        for (k = 0; k < 4; k++) {
            if (cur[k] == Ent_Move(tbl[j]))
                break;
        }
        if (k != 4)
            continue;
        for (m = 0; m < n; m++) {
            if (out[m] == Ent_Move(tbl[j]))
                break;
        }
        if (m != n)
            continue;
        out[n] = Ent_Move(tbl[j]);
        n++;
    }
    func_020307B0(tbl);
    return out;
}



int func_0216FAA0(u16 *p) { if (*p != 0xffff) return 1; return 0; }




/*
 * Look up a texture and a palette by name in a G3D texture resource,
 * derive their formats from the 7-entry d_021726A0 table, and load them
 * through func_0216FD54 (optionally func_0216FE04). One lever: the four
 * stack aggregates declared in reverse of their frame order.
 */
int func_0216FAB4(void *file, const char *texName, void *extra, const char *plttName, u32 a4, u16 a5, u16 a6, u16 a7, u16 heap, TexKey *out)
{
    TexKey key;
    char tn[16];
    char pn[16];
    TexReq req;
    u16 ofs;
    Res *res;
    u16 *e;
    u32 v;
    u32 fmtT;
    u32 fmtP;
    u32 j;
    int i;
    void *font;

    key.texFmt = 6;
    key.plttFmt = 6;
    key.texOfs = 0;
    key.plttOfs = 0;
    res = func_02047250(file);
    key.f04 = res->f08;
    key.f08 = res->f2c;
    ofs = res->texDict;
    for (i = 0; i < STD_GetStringLength(texName); i++)
        tn[i] = texName[i];
    for (; i < 16; i++)
        tn[i] = 0;
    e = func_0206E62C((u8 *)res + ofs, tn);
    if (e == 0)
        return 0;
    v = ((struct Obj09341 *)e)->f0;
    key.texOfs = (v & 0xFFFF) << 3;
    fmtT = (v & 0x700000) >> 20;
    fmtP = (v & 0x3800000) >> 23;
    for (j = 0; j < 7; j++) {
        if (fmtT == d_021726A0[j].tex) {
            key.texFmt = j;
            break;
        }
    }
    for (j = 0; j < 7; j++) {
        if (fmtP == d_021726A0[j].pltt) {
            key.plttFmt = j;
            break;
        }
    }
    ofs = res->plttDict;
    for (i = 0; i < STD_GetStringLength(plttName); i++)
        pn[i] = plttName[i];
    for (; i < 16; i++)
        pn[i] = 0;
    e = func_0206E62C((u8 *)res + ofs, pn);
    if (e == 0)
        return 0;
    if (e[1] == 1)
        return 0;
    key.plttOfs = (e[0] & 0xFFFF) << 3;
    font = func_0201D7EC(0x17, 0, 0, 0, heap);
    req.texFmt = key.texFmt;
    req.plttFmt = key.plttFmt;
    req.f04 = key.f04;
    req.font = font;
    req.texOfs = key.texOfs;
    req.f08 = key.f08;
    req.plttOfs = key.plttOfs;
    func_0216FD54((char *)(&req), a4, a5, a6, a7, heap);
    if (extra != 0)
        func_0216FE04((char *)(&req), extra);
    func_0201D83C(font);
    if (out != 0)
        *out = key;
    return 1;
}



int func_0216FC4C(void)
{
    return 7;
}




/*
 * Clears the pixel buffer of a bitmap: gets the buffer (func_020437D4) and
 * its byte size (func_020437EC), then stores 0 in every byte. The loop label
 * sits on the strb, so the `adds r1, r2, #0` before it is the zero copied
 * from the counter, not a store of i (docs/idioms/a-copy-of-the-counter-before-the-loop-label-is-a-stored-zero.md).
 */
void func_0216FC50(void *bmp)
{
    u8 *buf;
    u32 n;
    u32 i;

    buf = (u8 *)func_020437D4(bmp);
    n = func_020437EC(bmp);
    for (i = 0; i < n; i++) {
        buf[i] = 0;
    }
}


void func_0216FC74(void *a, u16 b, u16 c, u16 d, void *e, void *f) { func_0216FC50(e); func_0201C7D0(e,b,c,a,f,d); }


/*
 * DIFF, 12 concrete bytes, 180/180 bytes, all 9 relocations resolved.
 * Tile-order copy: w, h in 8-pixel units, d = depth byte, t = (d<<13)>>16;
 * dst[i] = src[(r/t + w*(q/8))*d + (q%8)*t + r%t] with s = w*t, q = i/s, r = i%s.
 * recoup 2026-10-05 (lane B2, 21 compiles): the old draft (docs/notes) had the
 * right logic. Division calls are CSE'd by mwcc (equal calls merge at the first
 * use), so the old tmp/q/pad locals were unnecessary. Clean form with r named and
 * the quotient written inline twice gives the hoisted stride spilled (as the
 * original) and the original register colours, 24 B off. Residue: the original
 * calls i/s FIRST (quotient into r4) then i%s (remainder into r7); mwcc emits the
 * remainder first, and the four spill slots (w, d, total, stride) come out in
 * reverse order of the original (orig 8,4,0xc,0x10; ours 0x10,0xc,4,8).
 * Tried and worse: named q (97 B, stride no longer hoisted, i/q colours swap),
 * all-inline with quotient term leftmost (24 B, same) or rightmost (81 B),
 * named q plus inline r (97 B), q named plus one inline quotient (73 B), s named
 * in loop (127 B), total as loop bound (124 B), w/h/t as plain /8 (166 B: the
 * original keeps the lsls 13 / lsrs 16 pair), pragmas scheduling,
 * opt_propagation, opt_lifetimes off (24, 27, 24 B).
 * Callee types checked: func_020437DC/E4 u16, func_02043994 u8 (sub_02043994.c),
 * func_020437D4 returns a pointer (ov208 callers); all as declared here.
 * No tile-order twin (grep func_02043994, func_020437E4+func_020437DC in src/matched/ov).
 * Idioms read: div-and-mod-are-two-calls, a-self-recompute-pins-an-operand-before-the-other-side-calls,
 * a-field-captured-before-a-named-divider-stays-live-across-the-call,
 * binding-a-modulo-result-to-a-local-moves-the-add-destination,
 * a-byte-count-local-preserves-word-spills-and-reloads,
 * a-spilled-value-below-the-cse-temps-is-an-inline-expression-not-a-named-local.
 *
 * final push 2026-10-05 G6L2 (about 38 compiles, 3 rounds): 24 -> 12 B. The lsls #13 / lsrs #16
 * pair is the u16 truncation of x / 8: w, h, t are u16 locals (w = f() / 8, t = d / 8) and d is
 * a u8 local (the callee returns u8). Narrow locals take the lowest spill slots: the four spill
 * slots now match the original (d 4, w 8, total 0xc, stride 0x10). With >> 3 instead of / 8 the
 * w and d slots swap (19 B).
 * Residue (12 B): the original calls i / s FIRST (quotient into r4) and i % s second (remainder
 * into r7); we emit the remainder first, and the tail copy of (q % 8) goes into r2 where we copy t.
 * Call order follows source order only when q is a named statement before r; every such form
 * (named q with named or inline r, s named inside or before the loop, block-scope locals,
 * declaration orders, opt_propagation/opt_lifetimes/scheduling off) emitted the quotient first
 * but kept the stride in r7 and spilled the remainder (182 B, about 95 B off). All-inline index
 * in any term order (q%8 first, r%t first, w*q/8 first) and a named q%8 term keep remainder first.
 * Idioms read: of-two-equal-temps-the-later-born-one-gets-the-lower-register,
 * opt-propagation-off-with-named-locals-pins-argument-constants-against-stack-stores,
 * div-and-mod-are-two-calls, binding-a-modulo-result-to-a-local-moves-the-add-destination.
 * Matched twin for callee types: ov121 021DA338 (u16, u16, u8).
 *
 * pass 2 2026-10-06 P2L24: EXACT (c99 and c). Fix: q = i / s as a named statement before r = i % s
 * (quotient call first, as the original) together with (q / 8) * w instead of w * (q / 8): the operand
 * order of that product decides which value the allocator spills, and with it the named-q form keeps
 * the stride spilled. The unused `total` local is dropped (the loop bound is the inline product).
 */
void func_0216FCA0(void *a, void *b)
{
  u8 *src;
  u8 *dst;
  u16 w;
  u16 h;
  u8 d;
  u16 t;
  int i;
  int r;
  int q;
  w = func_020437DC(a) / 8;
  h = func_020437E4(a) / 8;
  d = func_02043994(a);
  t = d / 8;
  src = func_020437D4(a);
  dst = func_020437D4(b);
  for (i = 0; i < ((w * h) * d); i++)
  {
    q = i / (w * t);
    r = i % (w * t);
    dst[i] = src[((r / t) + (q / 8) * w) * d + (q % 8) * t + r % t];
  }
}



/*
 * EXACT in --lang c99 and --lang c, 176/176 bytes, all 12 relocations resolved.
 * recoup 2026-10-05 (lane C1, ~27 compiles): the older draft (docs/notes) was 110 B off at 172 B.
 * Fixes: hi and wi are plain u32 with an unsigned shift, no u16 or enum (no lsls/lsrs pairs),
 * the area is signed (int)(wi * h) / 8 with h the raw table halfword, and n is an int (a u32 n
 * lets mwcc sink the divide chain below func_0207F7A0; int n keeps it before the call as the
 * original does). Table const, order of wi/hi loads, n position, int/u16 h, callee u32 params,
 * and the six per-function pragmas (on the earlier form) did not help.
 * Residue: (1) entry spills: the original stores r2, r3, r1 with the table index load between;
 * ours stores r1, r2, r3 and loads the u16 argument f before the h spill. (2) base (a+0xc) is
 * loaded early into r4 and off into r5 in the original; ours loads base after the chain into r5
 * and off into r4, so the final add is r5,r4 instead of r4,r5.
 *
 * final push 2026-10-05 G5L10 (40 compiles, 3 rounds): 23 -> 7 B. Fixes: (1) c and d are u16
 * here and u16 in func_0216FC74 (the caller func_0216FAB4 declares them u16): the entry
 * spills come out r2, r3, r1 as in the original; b is u32 (FAB4 passes u32). (2) the tail
 * mirrors the matched sibling func_0216FE04 (u32 b,a; a = base field first, then b = (u16)field*8):
 * base is read BEFORE off and declared AFTER it (u32 off; u32 base;), which gives the base load
 * right after the offset load and the final add r4,r5.
 * Residue (7 B): the original loads the heap halfword f (add r3,sp,#0x38; ldrh r3,[r3,#4])
 * after the wi index load (ldrh r0,[r5]) and after the h spill and lsrs; ours hoists it above
 * the h spill. Tried without effect: const a, struct view of a, inline alloc helper, u16 heap
 * local, *(u16 *)&f, w local, wi/hi inline or reordered (wi before hi or h declared last
 * moves spill slots, 154 B), u32 heap callee param (117 B), five opt_ pragmas, peephole off.
 * pass 2 2026-10-06 P2L15 (40 compiles, 3 rounds, no change to the form, still 7 B): cause found.
 * The image's heap load waits for `str h` because that store goes to a memory OBJECT; a spill
 * store never blocks a stack-parameter load. Diagnostic `func_020437AC(&h)` puts the f load at
 * +0x20 exactly; `&vram, &buf, &h` with declarations vram, buf, h also gives the image frame
 * (h 0x14, buf 0x18, vram 0x1c), so the original keeps h, buf and vram in memory. Every memory
 * form tried (aggregate {h,buf,vram} with an address use, value temp, wi first, u32 c/d, u16 b)
 * also flips the entry (str r1,[sp,#8] first, index in r1). Forms that do not keep h in memory:
 * inline out-pointer helper, hp = &h, unused &w, union, one-member struct/array, nested blocks
 * (all folded or scalarised). optimization_level 1 shows the f load is textually last.
 * pass 3 2026-10-06 P3L08 (3 compiles): EXACT. h is a u16 local (the table halfword) and
 * hi = (u32)h >> 3 keeps lsrs. mwcc keeps the u16 stack parameter f load behind the spill
 * store of a narrow local, but hoists it above the spill of a u32 local (docs/idioms
 * a-u16-stack-parameter-passed-to-a-u16-callee-stays-behind-a-spill-store.md, sub_0201B2B0
 * pidHigh; a-reload-kept-below-outgoing-stack-stores-is-a-narrow-local.md for the (u32) widen).
 * The earlier u16 h try (154 B) used h >> 3, which promotes to int and gives asrs.
 */
void func_0216FD54(char *a, u32 b, u16 c, u16 d, u16 e, u16 f)
{
    u16 h;
    u32 hi;
    u32 wi;
    void *buf;
    void *tmp;
    void *vram;
    int n;
    u32 off;
    u32 base;

    h = d_021726A0[*(u16 *)(a + 2)].w;
    hi = (u32)h >> 3;
    wi = (u32)d_021726A0[*(u16 *)a].w >> 3;
    tmp = func_02043678(wi, hi, 0x20, f);
    buf = func_02043678(wi, hi, 0x20, f);
    func_0216FC74((void *)b, c, d, e, buf, *(void **)(a + 0x14));
    func_0216FCA0(buf, tmp);
    vram = func_020437D4(tmp);
    base = *(u32 *)(a + 0xc);
    off = (u16)*(int *)(a + 4) << 3;
    n = ((int)(wi * h) / 8) << 5;
    func_0207F7A0();
    func_020862F0(vram, n);
    func_0207F7FC(vram, base + off, n);
    func_0207F9B4();
    func_020437AC(buf);
    func_020437AC(tmp);
}


void func_0216FE04(char *p,void *q) { u32 b,a; a=((struct Obj12410 *)p)->f10; b=(u16)((struct Obj12410 *)p)->f8*8; func_0207FA0C(); func_020862F0(q,32); func_0207FA40(q,a+b,32); func_0207FADC(); }



/*
 * Classifies table entry idx (12-byte records) against a position:
 * 0 = inside, 1 = within three steps on one axis, 2 = out of reach or
 * locked. 0xFF marks an unused record; 0xFE records are gated by a bit
 * (idx - 0x21) of the 16-bit mask at flags.
 */
int func_0216FE2C(struct Rec *tbl, int idx, struct Pos *pos, u8 *flags)
{
    int x;
    int y;
    int m;

    x = tbl[idx].x;
    if (x == 0xff)
        return 2;
    if (x == 0xfe) {
        m = flags[0] | (flags[1] << 8);
        if (m & (1 << (idx - 0x21)))
            return 0;
        return 2;
    }
    if (x <= pos->x) {
        y = tbl[idx].y;
        if (y <= pos->y)
            return 0;
        if (y - pos->y <= 3)
            return 1;
    } else {
        y = tbl[idx].y;
        if (y <= pos->y) {
            if (x <= pos->x)
                return 0;
            if (x - pos->x <= 3)
                return 1;
        }
    }
    return 2;
}
