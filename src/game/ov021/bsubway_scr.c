/*
 * file:     bsubway_scr.c
 * unit:     yes
 * function: func_021C87A0, func_021C87AC, func_021C87B8, func_021C87C8, func_021C87D4, func_021C87E0, func_021C8810, func_021C881C, func_021C8848, func_021C8868, func_021C88AC, func_021C88EC, func_021C8960, func_021C8984, func_021C89A8, func_021C89BC, func_021C8A30, func_021C8A74, func_021C8A7C, func_021C8A8C, func_021C8A9C, func_021C8AAC, func_021C8AD0, func_021C8B14, func_021C8B48, func_021C8B5C, func_021C8B78, func_021C8B9C, func_021C8BC4, func_021C8BD8, func_021C8BFC, func_021C8C88, func_021C8CF0, func_021C8CF8, func_021C8D08, func_021C8D18, func_021C8D3C, func_021C8D74, func_021C8DC4, func_021C8DD4, func_021C8DE4, func_021C8DF4, func_021C8E14, func_021C8E30, func_021C8E5C, func_021C8E68, func_021C8E8C, func_021C8EA0, func_021C8F38, func_021C8F7C, func_021C8FB8, func_021C8FDC, func_021C8FE0, func_021C8FF0, func_021C9064, func_021C909C, func_021C90AC, func_021C90D0, func_021C90E4, func_021C9164, func_021C9190, func_021C9208, func_021C9258, func_021C928C, func_021C92B0, func_021C9314, func_021C9334, func_021C9360, func_021C939C, func_021C93D0, func_021C93E4, func_021C9450, func_021C94AC, func_021C94B4, func_021C94BC, func_021C94E0, func_021C94F4, func_021C952C, func_021C9550, func_021C95D8, func_021C963C, func_021C9660, func_021C9690, func_021C96CC, func_021C978C, func_021C97B8, func_021C9828, func_021C9854, func_021C98F4, func_021C9924, func_021C9934, func_021C9B24, func_021C9B78, func_021C9BCC, func_021C9C54, func_021C9CAC, func_021C9D30, func_021C9D70, func_021C9DB0, func_021C9E8C, func_021C9F44, func_021C9FD0, func_021C9FFC, func_021CA048, func_021CA05C, func_021CA150, func_021CA164, func_021CA1E4, func_021CA210, func_021CA234, func_021CA238, func_021CA23C, func_021CA250, func_021CA258, func_021CA270, func_021CA2A4, func_021CA2CC, func_021CA2DC, func_021CA338, func_021CA3B4, func_021CA4C0, func_021CA544, func_021CA57C, func_021CA598, func_021CA5C4, func_021CB6DC, func_021CB700, func_021CB754, func_021CB7E8, func_021CB86C, func_021CB8AC, func_021CB914, func_021CB934, func_021CB9BC, func_021CB9E4, func_021CBBA0, func_021CBBAC, func_021CBBD0, func_021CBC14, func_021CBC94, func_021CBCC4, func_021CBD08, func_021CBD84, func_021CBD90, func_021CBED8, func_021CBEFC, func_021CBF38, func_021CBF98
 * address:  0x021C87A0
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
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012ED0  0x02012ED0  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_021C8608  0x021C8608  thumb  ov021
 *   func_021666A4  0x021666A4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021C8738  0x021C8738  thumb  ov021
 *   func_021C86E8  0x021C86E8  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   d_021DAB24  0x021DAB24  data  ov021  a4
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_02006148  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021AB0D4  0x021AB0D4  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   _u32_div_f     0x0209C2B0  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02006224  0x02006224  thumb
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021639C0  0x021639C0  thumb  ov010
 *   d_021DAB54  0x021DAB54  data  a4
 *   d_021DAB44  0x021DAB44  data  ov021  a4
 *   func_021A2F98  0x021A2F98  thumb  ov021
 *   func_021ACBC8  0x021ACBC8  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021ABE8C  0x021ABE8C  thumb  ov021
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   func_021AD598  0x021AD598  thumb  ov021
 *   func_02005C64  0x02005C64  thumb
 *   func_0200616C  0x0200616C  thumb
 *   d_021DE544  0x021DE544  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   d_021DAB6C     0x021DAB6C  data  a4
 *   d_021DAB7C     0x021DAB7C  data  a4
 *   func_0204762C  0x0204762C  arm
 *   func_02047738  0x02047738  arm
 *   func_02047504  0x02047504  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   d_021DABA4  0x021DABA4  data  a4
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0204784C  0x0204784C  arm
 *   func_020478B8  0x020478B8  arm
 *   func_02047828  0x02047828  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_02047AC8  0x02047AC8  arm
 *   d_021DABCC     0x021DABCC  data  a4
 *   d_021DABB8  0x021DABB8  data  ov021  a4
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 *   func_0216DA30  0x0216DA30  thumb  ov010
 *   func_02047910  0x02047910  arm
 *   d_021DAC08     0x021DAC08  data  a4
 *   d_021DAB90  0x021DAB90  data  ov021  a4
 *   d_021DAC44  0x021DAC44  data  ov021  a4
 *   d_021DE558  0x021DE558  data  ov021  a4
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0218BA04  0x0218BA04  thumb  ov021
 *   d_021DE578  0x021DE578  data  ov021  a4
 *   d_021DE56C  0x021DE56C  data  ov021  a4
 *   d_021DAC80     0x021DAC80  data  a4
 *   d_021DAC94  0x021DAC94  data  ov021  a4
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_0218C638  0x0218C638  thumb  ov021
 *   func_0218C69C  0x0218C69C  thumb  ov021
 *   func_02012EE4  0x02012EE4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   d_021DE58C     0x021DE58C  data  ov021
 *   func_02008550  0x02008550  thumb
 *   func_020071CC  0x020071CC  thumb
 *   func_0200D868  0x0200D868  thumb
 *   func_0200D85C  0x0200D85C  thumb
 *   func_0200DA14  0x0200DA14  thumb
 *   func_0200DB44  0x0200DB44  thumb
 *   func_0200DAC4  0x0200DAC4  thumb
 *   func_0200D914  0x0200D914  thumb
 *   func_0200D884  0x0200D884  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_0200DA54  0x0200DA54  thumb
 *   func_0200DB80  0x0200DB80  thumb
 *   func_020130B4  0x020130B4  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0200DB1C  0x0200DB1C  thumb
 *   func_0200DB08  0x0200DB08  thumb
 *   func_0200DAEC  0x0200DAEC  thumb
 *   func_0200DC08  0x0200DC08  thumb
 *   func_0200DA80  0x0200DA80  thumb
 *   d_021DACDC     0x021DACDC  data  a1
 *   func_0200DB60  0x0200DB60  thumb
 *   func_0200DEA8  0x0200DEA8  thumb
 *   func_02168AEC  0x02168AEC  thumb  ov010
 *   func_0200DBA0  0x0200DBA0  thumb
 *   func_0200DBF0  0x0200DBF0  thumb
 *   func_0200DC0C  0x0200DC0C  thumb
 *   func_0200DBFC  0x0200DBFC  thumb
 *   data_021DACD0  0x021DACD0  data
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_0200DC94  0x0200DC94  thumb
 *   func_0200DC50  0x0200DC50  thumb
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02012ED8  0x02012ED8  thumb
 *   data_021DAD24  0x021DAD24  data
 *   data_021DAD36  0x021DAD36  data
 *   data_021DAD70  0x021DAD70  data
 *   data_021DAD88  0x021DAD88  data
 *   data_021DADAC  0x021DADAC  data
 *   data_021DAE50  0x021DAE50  data
 *   func_0200B424  0x0200B424  thumb
 *   func_0200B5CC  0x0200B5CC  thumb
 *   func_0200BA38  0x0200BA38  thumb
 *   func_0200BA58  0x0200BA58  thumb
 *   func_0200BA68  0x0200BA68  thumb
 *   func_0200BBA8  0x0200BBA8  thumb
 *   func_0200D87C  0x0200D87C  thumb
 *   func_0200D9E8  0x0200D9E8  thumb
 *   func_0200DA28  0x0200DA28  thumb
 *   func_0200DB30  0x0200DB30  thumb
 *   func_0200DE5C  0x0200DE5C  thumb
 *   func_0200DE64  0x0200DE64  thumb
 *   func_0200DE94  0x0200DE94  thumb
 *   func_0200DF40  0x0200DF40  thumb
 *   func_0200DF4C  0x0200DF4C  thumb
 *   func_0200DF58  0x0200DF58  thumb
 *   func_0200DF94  0x0200DF94  thumb
 *   func_0200ED48  0x0200ED48  thumb
 *   func_0200ED54  0x0200ED54  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0200FB38  0x0200FB38  thumb
 *   func_020113D0  0x020113D0  thumb
 *   func_02012124  0x02012124  thumb
 *   func_02012134  0x02012134  thumb
 *   func_020124AC  0x020124AC  thumb
 *   func_0201289C  0x0201289C  thumb
 *   ov007_id       0x00000007  data  a1
 *   ov100_id       0x00000064  data  a1
 *   ov214_id       0x000000D6  data  a1
 *   func_0201296C  0x0201296C  thumb
 *   func_02014184  0x02014184  thumb
 *   func_02014314  0x02014314  thumb
 *   func_0201433C  0x0201433C  thumb
 *   func_02014808  0x02014808  thumb
 *   func_02019ED4  0x02019ED4  thumb
 *   func_0201A354  0x0201A354  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0202B578  0x0202B578  thumb
 *   func_0202C0D0  0x0202C0D0  thumb
 *   func_02039338  0x02039338  arm
 *   func_02087BCC  0x02087BCC  arm
 *   func_021542C0  0x021542C0  thumb  ov007
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02158FE0  0x02158FE0  thumb  ov010
 *   func_02167AB0  0x02167AB0  thumb  ov010
 *   func_02167B00  0x02167B00  thumb  ov010
 *   func_02167B24  0x02167B24  thumb  ov010
 *   func_02167BFC  0x02167BFC  thumb  ov010
 *   func_02167CF4  0x02167CF4  thumb  ov010
 *   func_0216C538  0x0216C538  thumb  ov010
 *   func_0216C640  0x0216C640  thumb  ov010
 *   func_0216C6E8  0x0216C6E8  thumb  ov010
 *   func_0216C860  0x0216C860  thumb  ov010
 *   func_0216CB48  0x0216CB48  thumb  ov010
 *   func_0216D63C  0x0216D63C  thumb  ov010
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216DAF8  0x0216DAF8  thumb  ov010
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216E014  0x0216E014  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021A30B0  0x021A30B0  thumb  ov021
 *   func_021A3190  0x021A3190  thumb  ov021
 *   func_021A31A4  0x021A31A4  thumb  ov021
 *   data_021BB474  0x021BB474  data  ov214
 *   data_021BB6A4  0x021BB6A4  data  ov100
 *   func_021CD48C  0x021CD48C  thumb  ov021
 *   func_021D024C  0x021D024C  thumb  ov021
 *   func_021D028C  0x021D028C  thumb  ov021
 *   func_021EEE78  0x021EEE78  thumb  ov188
 *   func_021F37C0  0x021F37C0  thumb  ov052
 *   func_021F380C  0x021F380C  thumb  ov052
 *   func_021F388C  0x021F388C  thumb  ov052
 *   func_02167CB4  0x02167CB4  thumb  ov010
 *   func_02167B34  0x02167B34  thumb  ov010
 *   func_021CD688  0x021CD688  thumb  ov021
 *   func_021CD5A4  0x021CD5A4  thumb  ov021
 *   func_02167D00  0x02167D00  thumb  ov010
 *   func_0203D378  0x0203D378  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_02167B18  0x02167B18  thumb  ov010
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_0215A684  0x0215A684  thumb  ov010
 *   func_0215A690  0x0215A690  thumb  ov010
 *   func_02188C54  0x02188C54  thumb
 *   func_02190BE4  0x02190BE4  thumb
 *   func_02190C78  0x02190C78  thumb
 *   func_021909BC  0x021909BC  thumb
 *   func_0200DFB4  0x0200DFB4  thumb
 *   func_0216CE6C  0x0216CE6C  thumb  ov010
 *   func_0216D620  0x0216D620  thumb  ov010
 *   func_0216D5B4  0x0216D5B4  thumb  ov010
 *   d_021DADD0     0x021DADD0  data  a2
 *   d_021DAD48     0x021DAD48  data  a2
 *   d_021DAD5C     0x021DAD5C  data  a2
 *   d_021DAEBC     0x021DAEBC  data  a2
 *   d_021DADF8     0x021DADF8  data  a4
 *   data_021DAEBC  0x021DAEBC  data
 *   func_0200B6E0  0x0200B6E0  thumb
 *   func_0201A920  0x0201A920  thumb
 *   func_0201A954  0x0201A954  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_021681C8  0x021681C8  thumb  ov010
 *   _s32_div_f  0x0209C0A4  arm
 *   d_021DB3D0  0x021DB3D0  data
 *   d_021DB3D8  0x021DB3D8  data
 *   d_021DB3E4  0x021DB3E4  data
 *   d_021DB3F4  0x021DB3F4  data
 *   func_02168878  0x02168878  thumb  ov010
 *   func_021688BC  0x021688BC  thumb  ov010
 *   func_021684E8  0x021684E8  thumb  ov010
 *   func_020056EC  0x020056EC  thumb
 */
#include "../../matched/include/Obj18340.h"
#include "../../matched/include/Obj18341.h"
#include "../../matched/include/Obj00876.h"
#include "../../matched/include/Obj12134.h"
#include "../../matched/include/Obj12135.h"
#include "../../matched/include/Obj12136.h"
#include "../../matched/include/Obj18342.h"
#include "../../matched/include/Obj18343.h"
#include "../../matched/include/Obj09714.h"
#include "../../matched/include/Obj18344.h"
#include "../../matched/include/Obj02730.h"
#include "../../matched/include/Obj20227.h"
#include "../../matched/include/Obj20228.h"
#include "../../matched/include/Obj12137.h"
#include "../../matched/include/Obj12138.h"
#include "../../matched/include/Obj05093.h"
#include "../../matched/include/Obj03617.h"
#include "../../matched/include/Obj02732.h"
#include "../../matched/include/Obj00116.h"
#include "../../matched/include/Obj02733.h"
#include "../../matched/include/Obj04291.h"
#include "../../matched/include/Obj05094.h"
#include "../../matched/include/Obj20232.h"
#include "../../matched/include/Obj07233.h"
#include "../../matched/include/Obj01671.h"
#include "../../matched/include/Obj07584.h"
#include "../../matched/include/Obj18345.h"
#include "../../matched/include/Obj18346.h"
#include "../../matched/include/Obj12970.h"
#include "../../matched/include/Obj18347.h"
#include "../../matched/include/Obj09722.h"
#include "../../matched/include/Obj00335.h"
#include "../../matched/include/Obj02400.h"
#include "../../matched/include/Obj12971.h"
#include "../../matched/include/Obj05095.h"
#include "../../matched/include/Obj06094.h"
#include "../../matched/include/Obj20240.h"
#include "../../matched/include/Obj12974.h"
#include "../../matched/include/Obj12976.h"

#define NULL ((void *)0)
#define FLAGS(w) ((Flags_021CA5C4 *)((w) + 0xc))
struct Ctx;
struct Big;
struct Stream;
struct Desc;
struct Obj;
struct Obj00020;
struct VecFx32;
struct T_021C87A0;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct Rec;
struct Tagged;
struct Actor;
struct AnmCtl;
struct Arg;
struct Blk1AC;
struct Blk3C;
struct Sub020071CCCtrl;
struct Sub0200852CObj;
struct BigObj;
struct Src;
struct Buf3FC;
struct L0200ED54;
struct Pair;
struct RecSlot;
struct SaveBlock;
struct Rec1C;
struct PartyCaller;
struct Handle;
struct SubEnt;
struct Party;
struct PartyMon;
struct Bs;
struct TrainerRec;
struct BattleMon;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed short s16;

typedef struct { u32 f0; s16 f4; s16 f6; int f8; } Clock;

typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; void *f14; u32 f18; u32 f1C; u32 f20; u32 f24; } P;

typedef signed char    s8;

typedef struct { u16 id; u16 pad; u32 v; } EntV;

struct Work8A30 {
    void *sys;
    u8 *owner;
    u8 *f8;
    void *fC;
    u32 f10;
    u16 f14;
    u16 pad16;
    u32 f18;
};

typedef int (*TaskFn)(void *task, int *state, void *work);

typedef struct { u32 x, y, z; } V;

typedef struct {
    u16 id;
    u16 a;
    u16 b;
} EntAB;

typedef struct { u16 id; u16 a; } EntA;

struct Work8C88 {
    void *sys;
    u8 *owner;
    u8 *f8;
    void *fC;
    u32 f10;
    u32 f14;
    u32 f18;
    int f1C;
    int f20;
    int f24;
};

typedef signed int     s32;

typedef struct A4 { u32 v[4]; } A4;

typedef struct A5 { u32 v[5]; } A5;

typedef struct { u32 a; V v; } T_021C87A0;

typedef struct T_021C8FF0 { int w[15]; } T_021C8FF0;

typedef struct { u32 a; V v; u32 c; } T_021C9064;

typedef struct { u8 pad[0x15]; u8 f15; u8 f16; u8 f17; u32 f18; } Fld15;

typedef struct S5 { u32 v[5]; } S5;


typedef struct V3 { int v[3]; } V3;

typedef struct T_021C9208 { int w[15]; } T_021C9208;

typedef struct { u32 a; V v; } T_021C9258;

typedef struct S4 { u32 v[4]; } S4;



typedef struct { u32 a[6]; u32 b[9]; } T_021C8FE0;


typedef struct { u32 f0; u32 f4; u32 f8[3]; } Q_021C94F4;

typedef struct Rec { u32 h; V3 pos; } Rec;

typedef struct { u32 f0; u32 f4; u32 f8[3]; u32 f14; } Q_021C9550;


typedef struct { u32 f0; u32 f4; u32 f8[3]; u32 f14; } Q;


typedef struct BsubwayScrWork {
    u32 f0;
    u32 f4;
    u32 f8;
    u8 pad0C[0x10 - 0xC];
    u8 f10;
    u8 f11;
    u8 f12;
    u8 f13;
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
    u8 pad28[0x34 - 0x28];
    u32 f34;
    u32 f38;
} BsubwayScrWork;

typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; u32 f10; } W_021C98F4;

typedef struct {
    u32 magic;
    u32 heap;
    u8 f8;
    u8 kind;
    u8 fa;
    u8 fb;
    u16 lo : 5;
    u16 sel : 3;
    u16 hi : 8;
    u8 pad0e[0x1e - 0x0e];
    u8 f1e[4];
    u8 pad22[0x32 - 0x22];
    u16 f32[14];
    u8 pad4e[0x6c - 0x4e];
    void *sys;
    void *f70;
    void *f74;
    void *f78;
    u8 pad7c[0x2c8 - 0x7c];
    u8 big[3][0x120];
    u8 small[22][0x14];
} Obj;

typedef struct {
    u8  pad0[0xc];
    u16 lo  : 5;
    u16 sel : 3;
    u16 hi  : 8;
} Sel;

typedef struct {
    u8  pad0[0x22];
    u16 a22[4];
    u16 a2a[4];
} Stats;

typedef struct { u16 b0 : 1; u16 b1 : 2; } Bits;

typedef struct {
    u8  pad0[0xc];
    u16 done : 1;
    u16 rest : 15;
} Latch;

typedef struct {
    u16 tag : 11;
    u16 hi  : 5;
    u16 val;
    u8  pad4[0x38];
} TagVal;

typedef struct { u8 pad[0xe]; u16 fE; } Cnt;

typedef struct {
    u16 species : 11;
    u16 form    : 5;
    u16 item;
    u16 moves[4];
    u32 f0c;
    u32 f10;
    u32 f14;
    u8  f18[6];
    u8  ppups;
    u8  f1f;
    u8  f20;
    u8  f21;
    u16 name[13];
} PartySlot;

typedef struct TrainerRec {
    u32 otId;
    u16 member[2];
    u32 pid[2];
} TrainerRec;

typedef struct {
    u16 b0  : 1;
    u16 f1  : 2;
    u16 f3  : 2;
    u16 f5  : 3;
    u16 b8  : 1;
    u16 b9  : 1;
    u16 f10 : 2;
    u16 b12 : 1;
    u16 f13 : 3;
} Flags_021CA5C4;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} Trip;

typedef struct {
    u32 w[7];
} Rec1C;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Vec;

typedef struct {
    u32 val;
    u16 *dst;
} Wait;

typedef enum {
    SLOT_0
} Slot;

typedef struct {
    u8  pad0[0xc];
    u16 lo   : 9;
    u16 flag : 1;
    u16 hi   : 6;
} Owner;

typedef struct {
    void *owner;
    u16 *result;
    u32 screen;
    u32 arg;
} Work;

typedef struct {
    s16 x;
    s16 pad0;
    s16 y;
    s16 pad1;
} Pt;

typedef struct {
    u16 id;
    u16 idx;
    s16 x;
    u16 pad6;
    s16 y;
    u16 k;
    u32 padc;
} Ent;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
} Flags_021CB86C;

typedef struct {
    u8  pad0[0xa];
    u16 fa;
    u16 fc;
    u16 fe;
} Entry;

typedef struct {
    u16 lo;
    u16 hi;
} Range;

typedef struct {
    u8 raw[0x3c];
} BattleMon;

extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012ED0(struct Big *p);
extern char *func_021C8608(void);
extern void func_021666A4(int a0);
extern void *func_0215A5F4(void *p);
extern u16 func_02011330(struct Stream *s);
extern unsigned short *func_02159AE8(void *a0, void *a1);
extern int func_021C8738(char *p, int k);
extern u32 func_021C86E8(u32, u32, u32);
extern u16 func_02159B10(void *a, void *b);
extern int func_0216D454(int a);
extern int func_02006148(u32 a0);
extern void func_020061F8(int a);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern u16 func_0216D5F8(void *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern u32 func_02188C98(u8 *p);
extern int func_021AB0D4(void *a, void *b);
extern u16 func_021AB0F0(u32 a);
extern u32 *func_0216D550(u32 *p, u32 v);
extern void func_0216D5E0(int a, int b);
extern u32 *func_0216D548(u32 *p, u32 v);
extern void func_0216D410(u32 a, u32 b);
extern int func_02006224(u32 a0);
extern void func_020061E4(u32 id);
extern u32 func_021639C0(u32, u32);
extern u32 func_021A2F98(u8 *p);
extern u32 func_021ACBC8(u32, u32);
extern u32 func_02188CD0(u8 *p);
extern int func_021ABE8C(struct T_021C87A0 *a, int id);
extern void func_021ABE30(int a, int *b, int c);
extern void func_021AD598(u32 a, u32 b, u32 c);
extern int func_02005C64(void);
extern void func_0200616C(void *arg, int i);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_021ABE24(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern int func_02046FF8(int *self);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void func_0204762C(struct Rec *p);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *v);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(u32 a, void *tbl, u32 c, u32 d, void *t, u32 f);
extern int func_021AC1AC(u32 a);
extern void func_021AC1CC(u32 a, void *p);
extern void func_021AC154(u32 a);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
extern int func_020478B8(void *a, int idx, int amount);
extern u32 func_02047828(struct AnmCtl *c, u32 idx, s32 *frame);
extern void func_0207ADC4(void *p);
extern void func_021AC1B8(u32 a, void *t);
extern int func_02047AC8(void *a0, struct Arg *a1);
extern int func_021AC1E0(u32 a);
extern int func_0216DA30(int a0, int a1);
extern int func_02047910(void *a, int idx, int amount);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern void func_02082D44(void *src, void *dst, int n);
extern void func_0218BA04(u32 a, u32 b, u32 *c, u32 d);
extern u32 func_0218DC6C(u8 *p);
extern int func_0218C638(int a, int b, int c);
extern void func_0218C69C(unsigned char *p, int b, int i, int c);
extern char *func_02012EE4(char *base, int v);
extern u8 *func_02012944(void *p);
extern void *func_02012EBC(struct Big *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void func_0200D868(struct Blk3C *p, u32 v);
extern void func_0200D85C(struct Blk3C *p);
extern void func_0200DA14(struct Blk3C *p);
extern u32 func_0200DB44(struct Blk1AC *p, u32 i);
extern u16 func_0200DAC4(struct Blk1AC *p, u32 i);
extern void func_0200D914(struct Blk3C *p, u32 id, const void *src);
extern u32 func_0200D884(struct Blk3C *p, u32 id, void *out);
extern void *func_020127A4(void *p);
extern u16 func_0200DA54(struct Blk3C *p);
extern u16 func_0200DB80(struct Blk1AC *p, u32 i);
extern int func_020130B4(int a0);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *m, u32 id, u32 v);
extern void func_0200DB1C(struct Blk1AC *p, u32 i);
extern void func_0200DB08(struct Blk1AC *p, u32 i, u16 v);
extern void func_0200DAEC(struct Blk1AC *p, u32 i, u16 v);
extern u8 func_0200DC08(struct Blk1AC *p);
extern void func_0200DA80(struct Blk1AC *p, s32 v);
extern void func_0200DB60(struct Blk1AC *p, u32 i);
extern void func_0200DEA8(u32 h, u8 *list, u8 n, u16 id);
extern u16 func_02168AEC(u16 a0);
extern u32 func_0200DBA0(struct Blk1AC *p, s32 i, u32 op);
extern void func_0200DBF0(struct Blk1AC *p);
extern u8 func_0200DC0C(struct Blk1AC *p, u32 kind);
extern void func_0200DBFC(struct Blk1AC *p);
extern void *func_0200BAC8(void *p);
extern void *func_0200BAF4(int a0, int a1);
extern void *func_02012934(const struct BigObj *p);
extern int func_0209C0A4(int a, int b);
extern void func_0200DC94(struct Blk1AC *p, const struct Src *q);
extern void func_0200DC50(struct Blk1AC *p, u32 which, const void *src);
extern int func_02158F58(int a0);
extern void *func_02158F54(void *p);
extern void *func_02012ED8(struct Big *p);
extern u32 func_0201296C(const struct BigObj *p);
extern u16 *func_02158FE0(void *a, void *b, unsigned int id);
extern void func_0215897C(void *h, void *task);
extern void func_02087BCC(u32 a);
extern u32 func_0200D87C(struct Blk3C *p);
extern u16 func_021A3050(u8 *p);
extern u16 func_02188C9C(u8 *p);
extern void func_02014184(Rec1C *out, u32 id, s16 n, u32 a, u32 b, u32 c);
extern void func_0201289C(struct BigObj *p, const struct Rec1C *src);
extern void func_02014314(char *a0, int a1);
extern void func_0201433C(char *a0, int a1);
extern u32 func_021A30B0(u8 *p);
extern u16 func_021A3190(int i, int j);
extern void *func_02188C7C(unsigned char *p);
extern void *func_0216DE94(void *a, u32 id);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
extern void func_021F37C0(void *a, int b, int c);
extern int func_021F380C(int a);
extern void func_021D024C(void *o, u32 v);
extern void func_021D028C(void *o, u32 v);
extern void func_0216E014(void *a, int *p, int b);
extern int func_0216DB4C(void *a0, int a1);
extern int func_021A31A4(int i, int v);
extern u32 func_0200BBA8(void *a);
extern void func_0216DAF8(void *o);
extern int func_0216D63C(char *a0, int a1);
extern void *func_0216CB48(u32 x, u32 v, u32 id);
extern struct Buf3FC *func_0200DF58(struct RecSlot *p, u32 heap);
extern u32 func_0200DF94(struct Buf3FC *b);
extern struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern int func_021542C0(int x, struct Pair *p);
extern u8 func_0200DE94(struct RecSlot *p);
extern u8 func_0200DE5C(struct RecSlot *p);
extern u8 func_0200DE64(struct RecSlot *p);
extern void *func_0216C860(void *a);
extern int func_0200DF40(struct RecSlot *p);
extern u8 func_0200DF4C(struct RecSlot *p);
extern void *func_0216C538(struct PartyCaller *c, void *sys, u8 useOwn);
extern void *func_0216C640(u8 *w, u32 x, void *s);
extern void *func_0216C6E8(u8 *d, void *sys, u32 idx, u16 id, u8 dir);
extern u32 func_02012134(u32 *p);
extern u32 func_0202B578(u32 *p);
extern void func_0202C0D0(u8 *p, u32 a);
extern void *func_0201A354(int a, int b);
extern int func_02019ED4(void *ctx, void *q);
extern u32 func_0200B5CC(void *a, u32 heap, u32 *dp, u32 id);
extern void func_0200BA58(void);
extern void func_021EEE78(void *p);
extern void func_0200BA68(void);
extern void func_020113D0(char *p, int val);
extern void func_0200B424(void);
extern void *func_02014808(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void func_021F388C(int a);
extern u32 func_0201AA18(void *party);
extern void func_0200D9E8(struct Blk3C *p, s32 a, s32 b, s32 c);
extern void func_0200DA28(struct Blk3C *p);
extern void func_0200DB30(struct Blk1AC *p, u32 i);
extern void func_02167B00(u32 a);
extern void func_02167AB0(void *p);
extern int func_02167B24(int a0);
extern u32 func_021CD48C(u32 a, void *b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void func_02167BFC(struct Obj *o, u32 cmd, u32 arg);
extern void func_02167CF4(u8 *w, u8 v);
extern u16 func_02039338(void);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
extern void *func_0200ED48(void *p);
extern void func_0200FB38(void);
extern void func_02012124(struct Ctx *p, u32 v);
extern u32 func_0200FB24(void);
extern u32 func_0200BA38(u32 v);
extern int func_02167CB4(struct Obj *o);
extern int func_02167B34(int a0);
extern u32 func_021CD688(u8 *p);
extern u32 func_021CD5A4(u32 *p);
extern int func_02167D00(struct Obj *o, u16 *out);
extern u32 func_0203D378(void);
extern void func_0203D7BC(u8 a0);
extern void func_02167B18(void *p);
extern int func_0203D1B4(void);
extern int func_0203CEAC(int a0);
extern int func_0203CDBC(void);
extern void func_0215A684(int *p, unsigned short v);
extern int func_0215A690(char *a0);
extern u32 func_02188C54(u8 *p);
extern u32 *func_02190BE4(u16 *a, u32 b);
extern int func_02190C78(struct Handle *h);
extern int func_021909BC(void *a);
extern u32 func_0200DFB4(struct SubEnt *e);
extern void *func_0216CE6C(void *o, int x, int y, u16 d, u32 a, u32 b, u32 c, u32 e);
extern int func_0216D620(int a0, int a1, int a2);
extern void func_0216D5B4(void *h, u16 v);
extern u32 func_0200B6E0(void *a, u16 b, u32 c, u32 d, u32 e, u16 *state, u16 *sub);
extern struct Party *func_0201A920(u32 heap);
extern void func_0201A954(struct Party *p, s32 capacity);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern struct Bs *func_021681C8(void *sys, void *partyA, u32 mode0, struct TrainerRec *recA, struct TrainerRec *recB, int n);
extern u8 func_02168878(u8 *list, u16 v, u8 n, u16 *a, u16 *b, u8 *e, u16 id);
extern void *func_021688BC(u8 *party, int id, u16 heap);
extern u32 func_021684E8(struct BattleMon *out, u32 member, u32 otId, u32 pid, u8 iv, u8 itemIdx, int useItem, u16 heap);
extern u32 func_020056EC(u32 max);
extern u32 _u32_div_f(u32 a, u32 b);
u32 func_021C87A0(void *p, u32 i);
u32 func_021C87AC(void *p, u32 i);
u32 func_021C87B8(void *p, u32 i, u32 j);
u32 func_021C87C8(void *p, u32 i);
void func_021C87D4(char *p, int i, int v);
int func_021C87E0(Clock *p);
u32 func_021C8810(u32 a);
int func_021C881C(void *task, u32 a);
int func_021C8848(u32 a, u32 b, u32 c, u32 d);
int func_021C8868(int a, int b);
int func_021C88AC(u32 a, u32 b, u32 c, u32 d);
int func_021C88EC(int a, int b);
int func_021C8960(u32 a, u32 b, u32 c, u32 d);
EntV *func_021C8984(u16 id);
int func_021C89A8(u16 a);
int func_021C89BC(int a, int *st, int *p);
void *func_021C8A30(u32 prio, void *sys, struct Obj00020 *owner);
int func_021C8A74(u16 a);
int func_021C8A7C(u32 a);
int func_021C8A8C(u32 a);
int func_021C8A9C(u32 a);
u16 func_021C8AAC(P *p);
void func_021C8AD0(int *p);
void func_021C8B14(P *p);
void func_021C8B48(P *p);
int func_021C8B5C(u32 a);
void func_021C8B78(P *p);
const EntAB *func_021C8B9C(u16 id);
int func_021C8BC4(u16 a);
EntA *func_021C8BD8(u16 id);
int func_021C8BFC(int a, int *st, int *p);
void *func_021C8C88(u32 prio, void *sys, struct Obj00020 *owner);
int func_021C8CF0(u16 a);
int func_021C8CF8(u32 a);
int func_021C8D08(u32 a);
u16 func_021C8D18(P *p);
void func_021C8D3C(P *p);
void func_021C8D74(int *p);
void func_021C8DC4(P *p);
void func_021C8DD4(P *p);
int func_021C8DE4(u32 a);
void func_021C8DF4(P *p);
void func_021C8E14(P *p);
void func_021C8E30(P *p);
void func_021C8E5C(int *p);
u32 *func_021C8E68(u32 a, u32 heap);
void func_021C8E8C(u32 a, u8 *p);
void func_021C8EA0(u32 *p);
void func_021C8F38(u8 *p);
void func_021C8F7C(u32 a, u32 b);
void func_021C8FB8(u32 a, u32 *out);
void func_021C8FDC(void);
void func_021C8FE0(u32 a, u32 *p);
void func_021C8FF0(u32 a, u32 *b);
void func_021C9064(u32 a, V *v, u32 c);
void func_021C909C(u32 a);
void func_021C90AC(u32 a);
int func_021C90D0(u32 a, u32 b, u32 c, u32 d);
void func_021C90E4(u32 a, u32 *q);
void func_021C9164(void *task, BsubwayScrWork *e);
void func_021C9190(u32 a, u8 *b);
void func_021C9208(u32 a, u32 *b);
void func_021C9258(u32 a, V *v);
void func_021C928C(u32 a);
void func_021C92B0(u32 a, u32 *q);
void func_021C9314(void *task, BsubwayScrWork *e);
void func_021C9334(void *task, BsubwayScrWork *e);
void func_021C9360(u32 a, BsubwayScrWork *e);
u32 *func_021C939C(u32 a, u32 heap);
void func_021C93D0(void **q);
void func_021C93E4(u32 a, u8 *q, u32 x, u32 y, u32 z, u32 w, u32 n, u32 cnt);
u32 func_021C9450(u32 a, u32 b, u32 c, u32 d, int e, int f);
int func_021C94AC(u32 a);
int func_021C94B4(u32 a);
u32 *func_021C94BC(u32 a, u32 heap);
void func_021C94E0(u32 a, u8 *p);
void func_021C94F4(Q_021C94F4 *q);
void func_021C952C(Q_021C94F4 *q);
void func_021C9550(u32 a, u32 b);
void func_021C95D8(u32 a, u32 *b);
void func_021C963C(void *task, Q_021C9550 *q);
void func_021C9660(u32 a, Q_021C9550 *q);
void func_021C9690(u32 a, BsubwayScrWork *e);
int func_021C96CC(u32 a, u32 *q, u32 *p);
u32 func_021C978C(u32 a, u32 b, u32 c);
int func_021C97B8(u32 a, u32 *q, u32 *p);
u32 func_021C9828(u32 a, u32 b, u32 c);
int func_021C9854(u32 a, u32 *q, u32 *p);
u32 func_021C98F4(u32 a, u32 b, u32 c, u32 d);
int func_021C9924(u32 a);
Obj *func_021C9934(void *arg, int mode, u32 kind);
void func_021C9B24(u32 a, u8 *p);
void func_021C9B78(u8 *p);
void func_021C9BCC(u8 *p);
void func_021C9C54(u8 *p, u32 x);
void func_021C9CAC(u8 *p);
u32 func_021C9D30(const struct Ctx *a0);
void func_021C9D70(u32 unused, u8 *p);
u32 func_021C9DB0(u8 *p);
void func_021C9E8C(u8 *p);
u32 func_021C9F44(u8 *p, u32 x);
int func_021C9FD0(u8 *p);
void func_021C9FFC(u8 *p, u32 x);
int func_021CA048(u32 a, u32 b);
void func_021CA05C(u8 *p);
u32 func_021CA150(u8 *p, int i);
int func_021CA164(void *a, int unused, int mode);
void func_021CA1E4(u8 *p);
void *func_021CA210(u8 *p);
u16 func_021CA234(u8 *p);
void func_021CA238(u8 *p, u16 v);
void func_021CA23C(u8 *p);
int func_021CA250(u32 a);
void func_021CA258(Cnt *p, u32 a, u32 b);
int func_021CA270(u16 kind);
int func_021CA2A4(const u16 *arr, u16 val, u16 n);
u16 func_021CA2CC(u16 v);
void func_021CA2DC(u8 *p, u32 h, int flag, u16 v);
void func_021CA338(u8 *p, u8 alt);
void func_021CA3B4(PartySlot *s, u32 m);
void func_021CA4C0(u8 *p, u32 unused, int flag);
int func_021CA544(u32 a, u32 b);
int func_021CA57C(u32 a, u32 b);
int func_021CA598(u32 a, u32 b);
int func_021CA5C4(void *a, u32 b);
int func_021CB6DC(void *task, void *p);
int func_021CB700(u32 unused, u32 a);
int func_021CB754(u32 unused, u32 a);
int func_021CB7E8(u32 unused, u32 a);
int func_021CB86C(u32 unused, u32 a);
int func_021CB8AC(void *task, int *state, Owner **work);
void *func_021CB914(void *a, u32 owner);
int func_021CB934(void *task, int *state, Work *w);
void *func_021CB9BC(void *a, u32 owner, u32 result, u32 arg);
void func_021CB9E4(u8 *p, void *a1, void *a2, void *a3);
u32 func_021CBBA0(u32 a);
u32 func_021CBBAC(u8 *p, u32 idx);
void func_021CBBD0(u8 *p, u32 idx, u16 *a, u16 *b, u16 *c);
int func_021CBC14(u32 unused, u32 a);
int func_021CBC94(u32 kind);
int func_021CBCC4(void *p);
u32 func_021CBD08(u8 *p, int a);
void *func_021CBD84(void *a);
u16 func_021CBD90(void *ctx, u32 round, u32 stage, u32 line, u8 alt);
u8 func_021CBED8(u8 *p, u8 *list, u16 v, u8 n, u16 *a, u16 *b, u8 *e, u16 id);
u8 func_021CBEFC(u32 v);
void func_021CBF38(void *unused, u8 *party, u16 id, int useItem, TrainerRec *rec, u16 heap);
u16 func_021CBF98(void *ctx);
extern EntV d_021DAB24[4];
extern const EntAB d_021DAB54[4];
extern EntA d_021DAB44[4];
extern char d_021DE544[];
extern const A4 d_021DAB6C;
extern const A5 d_021DAB7C;
extern u8 d_021DABA4[];
extern T_021C8FF0 d_021DABCC;
extern u8 d_021DABB8[];
extern T_021C9208 d_021DAC08;
extern u8 d_021DAB90[];
extern T_021C8FE0 d_021DAC44;
extern char d_021DE558[];
extern char d_021DE578[];
extern u32 d_021DE56C[3];
extern u32 d_021DAC80[];
extern T_021C8FE0 d_021DAC94;
extern const char d_021DE58C[];
extern const u8 d_021DACDC[7][10];
extern const u8 data_021DACD0[];
extern u8 data_021BB474[];
extern u8 data_021BB6A4[];
extern char ov007_id[];
extern char ov100_id[];
extern char ov214_id[];
extern const u16 data_021DAD36[];
extern const u32 data_021DAD88[];
extern const Trip data_021DAD70[];
extern const Trip data_021DAE50[];
extern const u32 data_021DADAC[];
extern const u16 data_021DAD24[];
extern const Pt d_021DADD0[];
extern const u16 d_021DAD48[];
extern const u16 d_021DAD5C[];
extern const Ent d_021DAEBC[];
extern const u32 d_021DADF8[];
extern const Entry data_021DAEBC[];
extern const Range d_021DB3D0[];
extern const Range d_021DB3D8[];
extern const Range d_021DB3E4[];
extern const Range d_021DB3F4[];











u32 func_021C87A0(void *p, u32 i)
{
    return *(u32 *)((u8 *)p + i * 0x1C + 0x18);
}











/*
 * Unlabelled leaf in the 0x1C-byte record accessor run; called from ov010
 * func_02166734 case 6. 10 bytes plus 2 bytes of padding.
 */
u32 func_021C87AC(void *p, u32 i)
{
    return *(u32 *)((u8 *)p + i * 0x1C + 0x10);
}











/*
 * Unlabelled leaf in the 0x1C-byte record accessor run; called from ov010
 * func_02166734 case 7. 14 bytes plus 2 bytes of padding.
 * lever: the record pointer as its own local; the flat
 *   `p + i*0x1C + j*4 + 0x1C` spelling is DIFF4 (adds order).
 */
u32 func_021C87B8(void *p, u32 i, u32 j)
{
    u8 *e = (u8 *)p + i * 0x1C;
    return ((u32 *)(e + 0x1C))[j];
}











/*
 * Unlabelled leaf in the 0x1C-byte record accessor run; called from ov010
 * func_02166734 case 8. 10 bytes plus 2 bytes of padding.
 */
u32 func_021C87C8(void *p, u32 i)
{
    return *(u32 *)((u8 *)p + i * 0x1C + 0x24);
}










void func_021C87D4(char *p, int i, int v)
{
    *(int *)(p + i * 0x1c + 0x24) = v;
}










int func_021C87E0(Clock *p)
{
    if (p->f4 >= 5400 && p->f8 >= 4)
        return 2;
    return p->f4 % 1350 == 0;
}











u32 func_021C8810(u32 a)
{
*(u32 *)((u8 *)(a) + ((109 << 2))) = 1;
return a;
}










int func_021C881C(void *task, u32 a)
{
    u32 *p = (u32 *)func_02012ED0(func_020120F4((void *)func_02188C80(func_0201210C(func_0215A5DC((void *)a)))));
    if (*p == 0)
        *p = (u32)func_021C8608();
    return 0;
}











/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C8848(u32 a, u32 b, u32 c, u32 d)
{
func_021666A4((int)func_02012ED0(func_020120F4(func_02188C80(func_0201210C(func_0215A5DC((void *)b))))));
return 0;
}











int func_021C8868(int a, int b)
{
    int *r4;
    int r7;
    unsigned short *r5;

    func_0215A5F4((void *)b);
    r4 = (int *)func_02012ED0(func_020120F4((void *)func_02188C80(func_0201210C(func_0215A5DC((void *)b)))));
    r7 = func_02011330((struct Stream *)a);
    r5 = func_02159AE8((void *)a, (void *)b);
    *r5 = func_021C8738((char *)(*r4), r7);
    return 0;
}











int func_021C88AC(u32 a, u32 b, u32 c, u32 d)
{
func_0215A5F4((void *)b);
func_021C86E8(((struct Obj18340 *)((u8 *)(func_02012ED0(func_020120F4(func_02188C80(func_0201210C(func_0215A5DC((void *)b))))))))->f0, func_02011330((struct Stream *)a), func_02011330((struct Stream *)a));
return 0;
}











int func_021C88EC(int a, int b)
{
    int *r7;
    int sp;
    int r5;
    int v;

    func_0215A5F4((void *)b);
    r7 = (int *)func_02012ED0(func_020120F4(func_0215A5DC((void *)b)));
    sp = (int)func_02159B10((void *)a, (void *)b);
    r5 = func_02011330((struct Stream *)a);
    func_02011330((struct Stream *)a);
    v = (int)func_02159B10((void *)a, (void *)b);
    switch (r5) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    case 8:
        func_021C87D4((char *)(*r7), sp, v == 1);
        break;
    }
    return 0;
}











int func_021C8960(u32 a, u32 b, u32 c, u32 d)
{
func_021C8810(((struct Obj18341 *)((u8 *)(func_02012ED0(func_020120F4(func_02188C80(func_0201210C(func_0215A5DC((void *)b))))))))->f0);
return 0;
}








EntV *func_021C8984(u16 id)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        if (id == d_021DAB24[i].id)
            return &d_021DAB24[i];
    }
    return 0;
}









int func_021C89A8(u16 a)
{
if (func_021C8984(a) != 0) {
    return 1;
}
return 0;
}










int func_021C89BC(int a, int *st, int *p)
{
    switch (*st) {
    case 0:
        if (func_021C89A8(func_021C8AAC((P *)p)) == 0) {
            *st = 2;
        } else {
            *st = 1;
        }
        break;
    case 1:
        func_021C8AD0(p);
        if (func_0216D454(p[3])) {
            func_021C8B48((P *)p);
            if (func_021C8B5C((u32)p)) {
                func_020061F8(func_02006148(0x694));
                *st = 2;
            } else {
                func_021C8B14((P *)p);
            }
        }
        break;
    case 2:
        func_021C8B78((P *)p);
        return 1;
    }
    return 0;
}










/*
 * Creates task func_021C89BC with a 0x1C byte work area and fills it from the
 * owner object.
 *
 * Addresses are Black-image addresses.
 */
void *func_021C8A30(u32 prio, void *sys, struct Obj00020 *owner)
{
    void *task = func_020122C0(sys, (void *)prio, (TaskFn)func_021C89BC, 0x1C);
    struct Work8A30 *w = func_020124E8(task);

    w->sys = sys;
    w->owner = (u8 *)owner;
    w->f8 = func_02188CB4(owner);
    w->fC = func_021A3074(w->f8);
    w->f10 = 0;
    w->f14 = func_0216D5F8(w->fC);
    w->f18 = 0;
    return task;
}










/*
 * Tail-call thunk: forwards to func_021C89A8 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
int func_021C8A74(u16 a)
{
    return func_021C89A8(a);
}









int func_021C8A7C(u32 a)
{
if (*(u32 *)&((struct Obj00876 *)((u8 *)(a)))->f10 != 0) {
    return *(u16 *)((u8 *)(*(u32 *)&((struct Obj00876 *)((u8 *)(a)))->f10) + 2);
}
return 0;
}









int func_021C8A8C(u32 a)
{
if (*(u32 *)&((struct Obj00876 *)((u8 *)(a)))->f10 != 0) {
    return *(u16 *)((u8 *)(*(u32 *)&((struct Obj00876 *)((u8 *)(a)))->f10) + 4);
}
return 0;
}









int func_021C8A9C(u32 a)
{
if (((struct Obj12134 *)((u8 *)(a)))->f10 != 0) {
    return *(u16 *)((u8 *)(((struct Obj12134 *)((u8 *)(a)))->f10) + 6);
}
return 0;
}








u16 func_021C8AAC(P *p)
{
    V t;
    func_021A3038((unsigned char *)p->f8, (struct VecFx32 *)&t);
    return func_021AB0F0(func_021AB0D4((void *)func_02188C98((u8 *)p->f4), &t));
}









void func_021C8AD0(int *p)
{
    int d = func_021C8A9C((u32)p);

    ((struct Obj00876 *)p)->f18 = ((struct Obj00876 *)p)->f18 + 1;
    if (((struct Obj00876 *)p)->f18 % d == 0) {
        ((struct Obj00876 *)p)->f14 = (((struct Obj00876 *)p)->f14 + 1) % 4;
        func_0216D550((u32 *)(*(int *)&((struct Obj00876 *)p)->fC), 8);
        func_0216D5E0(*(int *)&((struct Obj00876 *)p)->fC, ((struct Obj00876 *)p)->f14);
        func_0216D548((u32 *)(*(int *)&((struct Obj00876 *)p)->fC), 8);
    }
}








void func_021C8B14(P *p)
{
    func_0216D410(p->fC, func_021C8A7C((u32)p));
    func_0216D548((u32 *)p->fC, 8);
    if (func_02006224(func_02006148(0x694)) == 0)
        func_020061E4(0x694);
}








void func_021C8B48(P *p)
{
    void *e = func_021C8984(func_021C8AAC(p));
    if (e != 0)
        p->f10 = e;
}









int func_021C8B5C(u32 a)
{
if (func_021639C0(((struct Obj00876 *)((u8 *)(a)))->fC, func_021C8A8C(a)) != 0) {
    return 1;
}
return 0;
}








void func_021C8B78(P *p)
{
    func_0216D550((u32 *)p->fC, 8);
    if (p->f10 != 0)
        func_0216D5E0(p->fC, func_021C8A8C((u32)p));
}








/*
 * 2026-10-02: the base/offset register swap of the earlier DIFF closed by
 * declaring the table const (the const element type recolours the hoisted
 * table base into r3).
 */
const EntAB *func_021C8B9C(u16 id)
{
    u32 i;

    for (i = 0; i < 4; i++) {
        if (d_021DAB54[i].id == id)
            return &d_021DAB54[i];
    }
    return 0;
}







int func_021C8BC4(u16 a)
{
if (func_021C8B9C(a) != 0) {
    return 1;
}
return 0;
}







EntA *func_021C8BD8(u16 id)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        if (id == d_021DAB44[i].id)
            return &d_021DAB44[i];
    }
    return 0;
}








int func_021C8BFC(int a, int *st, int *p)
{
    switch (*st) {
    case 0:
        if (func_021C8BC4(func_021C8D18((P *)p)) == 0) {
            *st = 2;
        } else {
            func_021ACBC8(func_021A2F98((u8 *)p[2]), 0);
            func_021C8E30((P *)p);
            *st = 1;
        }
        break;
    case 1:
        func_021C8E30((P *)p);
        if (func_0216D454(p[3])) {
            func_021C8D74(p);
            func_021C8DC4((P *)p);
            func_021C8DD4((P *)p);
            if (p[4] == 0 && p[5] == 0) {
                func_021C8E5C(p);
                *st = 2;
            } else {
                func_021C8D3C((P *)p);
            }
        }
        break;
    case 2:
        func_021C8DE4((u32)p);
        return 1;
    }
    return 0;
}







/*
 * Creates task func_021C8BFC with a 0x28 byte work area, fills it from the
 * owner, and loads three resources (0x55E, 0x6E2, 0x769) through
 * func_02006148.
 *
 * Addresses are Black-image addresses.
 */
void *func_021C8C88(u32 prio, void *sys, struct Obj00020 *owner)
{
    void *v = func_02188CB4(owner);
    void *task = func_020122C0(sys, (void *)prio, (TaskFn)func_021C8BFC, 0x28);
    struct Work8C88 *w = func_020124E8(task);

    w->sys = sys;
    w->owner = (u8 *)owner;
    w->f8 = (u8 *)v;
    w->fC = func_021A3074(w->f8);
    w->f10 = 0;
    w->f14 = 0;
    w->f18 = 0;
    w->f1C = func_02006148(0x55E);
    w->f20 = func_02006148(0x6E2);
    w->f24 = func_02006148(0x769);
    return task;
}







/*
 * Tail-call thunk: forwards to func_021C8BC4 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
int func_021C8CF0(u16 a)
{
    return func_021C8BC4(a);
}







int func_021C8CF8(u32 a)
{
if (((struct Obj12135 *)((u8 *)(a)))->f10 != 0) {
    return *(u16 *)((u8 *)(((struct Obj12135 *)((u8 *)(a)))->f10) + 2);
}
return 0;
}







int func_021C8D08(u32 a)
{
if (((struct Obj12136 *)((u8 *)(a)))->f14 != 0) {
    return *(u16 *)((u8 *)(((struct Obj12136 *)((u8 *)(a)))->f14) + 2);
}
return 0;
}






u16 func_021C8D18(P *p)
{
    V t;
    func_021A3038((unsigned char *)p->f8, (struct VecFx32 *)&t);
    return func_021AB0F0(func_021AB0D4((void *)func_02188C98((u8 *)p->f4), &t));
}






void func_021C8D3C(P *p)
{
    if (p->f14 != 0) {
        func_0216D410(p->fC, func_021C8D08((u32)p));
        func_021C8DF4(p);
        p->f18 = 1;
        return;
    }
    if (p->f10 != 0)
        func_0216D410(p->fC, func_021C8CF8((u32)p));
}







void func_021C8D74(int *p)
{
    int buf[3];
    int v;
    int r5;

    if (p[5] != 0) {
        r5 = func_02188CD0((u8 *)p[1]);
        v = 9;
        if (func_021ABE8C((struct T_021C87A0 *)r5, v) == 0) {
            func_021ABE30(r5, &v, 1);
        }
        func_021A3038((unsigned char *)p[2], (struct VecFx32 *)buf);
        func_021AD598(r5, 0, (u32)buf);
        func_021C8E14((P *)p);
        p[5] = 0;
        p[6] = 0;
    }
}






void func_021C8DC4(P *p)
{
    p->f10 = (void *)func_021C8B9C(func_021C8D18(p));
}






void func_021C8DD4(P *p)
{
    p->f14 = func_021C8BD8(func_021C8D18(p));
}







int func_021C8DE4(u32 a)
{
return func_021ACBC8(func_021A2F98((u8 *)(((struct Obj18342 *)((u8 *)(a)))->f8)), 1);
}






void func_021C8DF4(P *p)
{
    if (func_02005C64() == 0) {
        func_020061F8(p->f24);
        func_0200616C((void *)0x55e, p->f1C);
    }
}






void func_021C8E14(P *p)
{
    if (func_02005C64() == 0)
        func_0200616C((void *)0x6e2, p->f20);
}






void func_021C8E30(P *p)
{
    if (func_02005C64() == 0 && p->f18 == 0 && func_02006224(p->f24) == 0)
        func_0200616C((void *)0x769, p->f24);
}







/*
 * Tail-call thunk: the object's word at +0x24.
 *
 * Addresses are Black-image addresses.
 */
void func_021C8E5C(int *p)
{
    func_020061F8(((struct Obj18343 *)p)->f24);
}






u32 *func_021C8E68(u32 a, u32 heap)
{
    u32 *q = func_02030734(heap, 0x34, 1, d_021DE544, 0xa9);
    q[0] = a;
    func_021C8EA0(q);
    return q;
}







/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021C8E8C(u32 a, u8 *p)
{
    func_021C8F38(p);
    func_020307B0(p);
}







/*
 * Addresses are Black-image addresses.
 */
void func_021C8EA0(u32 *p)
{
    A4 a;
    A5 b;
    u32 r6;
    u32 i;

    a = d_021DAB6C;
    b = d_021DAB7C;
    r6 = func_021ABE24((u8 *)p[0]);
    for (i = 0; i < 4; i++) {
        p[1 + i] = (u32)func_02046E24(r6, a.v[i]);
        func_02046FF8((int *)p[1 + i]);
    }
    for (i = 0; i < 5; i++) {
        p[5 + i] = (u32)func_02046E24(r6, b.v[i]);
    }
    p[11] = (u32)func_02047400((void *)p[1], 0, (void *)p[1]);
    p[10] = (u32)func_02047564((struct G3dOwner *)p[11], (const struct G3dOwner *)p[5], 0);
    p[12] = (u32)func_0204767C(p[11], p + 10, 1);
    func_020477A4((struct G3dSys *)p[12], 0);
}







void func_021C8F38(u8 *p)
{
    u32 i;

    func_0204762C((struct Rec *)(((struct Obj09714 *)p)->f28));
    func_02047738((struct Rec *)(((struct Obj09714 *)p)->f30));
    func_02047504((struct Rec *)(((struct Obj09714 *)p)->f2C));
    for (i = 0; i < 4; i++) {
        func_020470D0((u32 *)(*(u32 *)(p + i * 4 + 4)));
        func_02046EFC((struct Tagged *)(*(u32 *)(p + i * 4 + 4)));
    }
    for (i = 0; i < 5; i++) {
        func_02046EFC((struct Tagged *)(*(u32 *)(p + i * 4 + 0x14)));
    }
}





void func_021C8F7C(u32 a, u32 b)
{
    V pos;
    T_021C87A0 t;
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&pos);
    t.a = func_021ABEA0(b, 0xb);
    t.v = pos;
    func_021ABFA8(b, d_021DABA4, 0, 0, &t, 0);
}





void func_021C8FB8(u32 a, u32 *out)
{
    u32 *r = (u32 *)func_021AC1AC(a);
    *out = r[0];
    func_021AC1CC(a, &r[1]);
    func_020061E4(0x6a2);
}


void func_021C8FDC(void) {}









void func_021C8FE0(u32 a, u32 *p)
{
    if (p[2] == 1)
        func_021AC154(a);
}










void func_021C8FF0(u32 a, u32 *b)
{
    T_021C8FF0 t;
    u32 h;

    if (b[2] == 0) {
        t = d_021DABCC;
        h = *(u32 *)(b[0] + 0x30);
        func_0204784C((struct AnmCtl *)h, 0, (s32 *)(b + 1));
        if (func_020478B8((void *)h, 0, 0x1000) == 0) {
            b[2] = 1;
        }
        if (func_02047828((struct AnmCtl *)h, 0, (s32 *)(b + 1)) == 0) {
            b[2] = 1;
        }
        func_0207ADC4(&t.w[6]);
        func_021AC1B8(a, &t);
        func_02047AC8((void *)h, (struct Arg *)(&t));
    }
}









void func_021C9064(u32 a, V *v, u32 c)
{
    T_021C9064 t;
    t.a = func_021ABEA0(a, 0xb);
    t.v = *v;
    t.c = c;
    func_021ABFA8(a, d_021DABB8, 0, 0, &t, 0);
}









void func_021C909C(u32 a)
{
    if (a != 0)
        ((u8 *)func_021AC1E0(a))[0x14] = 1;
}









void func_021C90AC(u32 a)
{
    u32 z;
    Fld15 *e;
    if (a != 0) {
        z = 0;
        e = (Fld15 *)func_021AC1E0(a);
        e->f15 = 1;
        e->f16 = 0;
        func_0204784C((struct AnmCtl *)e->f18, 1, (s32 *)(&z));
    }
}










int func_021C90D0(u32 a, u32 b, u32 c, u32 d)
{
if (a != 0) {
    return ((struct Obj18344 *)((u8 *)(func_021AC1E0(a))))->f16;
}
return 1;
}










void func_021C90E4(u32 a, u32 *q)
{
    *(S5 *)q = *((S5 *)func_021AC1AC(a));
    func_021AC1CC(a, q + 1);
    q[9] = (u32)func_02047400((void *)(((u32 *)q[0])[2]), 0, (void *)(((u32 *)q[0])[2]));
    q[7] = (u32)func_02047564((struct G3dOwner *)q[9], (const struct G3dOwner *)(((u32 *)q[0])[6]), 0);
    q[8] = (u32)func_02047564((struct G3dOwner *)q[9], (const struct G3dOwner *)(((u32 *)q[0])[7]), 0);
    q[6] = (u32)func_0204767C(q[9], q + 7, 2);
    func_020477A4((struct G3dSys *)q[6], 0);
    func_020477A4((struct G3dSys *)q[6], 1);
    q[14] = (u32)func_02047400((void *)(((u32 *)q[0])[4]), 0, (void *)(((u32 *)q[0])[4]));
    q[13] = (u32)func_0204767C(q[14], 0, 0);
}








void func_021C9164(void *task, BsubwayScrWork *e)
{
    func_0204762C((struct Rec *)e->f1C);
    func_0204762C((struct Rec *)e->f20);
    func_02047738((struct Rec *)e->f18);
    func_02047504((struct Rec *)e->f24);
    func_02047738((struct Rec *)e->f34);
    func_02047504((struct Rec *)e->f38);
}









void func_021C9190(u32 a, u8 *b)
{
    V3 v;

    if (func_0216DA30(((struct Obj02730 *)b)->f10, (int)b) != 0) {
        func_0216D88C((const struct Actor *)((struct Obj02730 *)b)->f10, (struct VecFx32 *)&v);
        *(V3 *)(b + 0x28) = v;
        func_021AC1CC(a, &v);
        ((struct Obj02730 *)b)->f2C -= 0x4000;
        ((struct Obj02730 *)b)->f30 += 0x2800;
        if (b[0x14] == 0) {
            func_02047910((void *)(((struct Obj02730 *)b)->f18), 0, 0x1000);
        }
        if (b[0x15] == 1 && b[0x16] == 0) {
            if (func_020478B8((void *)(((struct Obj02730 *)b)->f18), 1, 0x1000) == 0) {
                b[0x16] = 1;
            }
        }
    }
}









void func_021C9208(u32 a, u32 *b)
{
    T_021C9208 t = d_021DAC08;

    func_0207ADC4(&t.w[6]);
    func_021AC1B8(a, &t);
    func_02047AC8((void *)b[6], (struct Arg *)(&t));
    *(V3 *)&t = *(V3 *)(b + 10);
    func_02047AC8((void *)b[13], (struct Arg *)(&t));
}








void func_021C9258(u32 a, V *v)
{
    T_021C9258 t;
    t.a = func_021ABEA0(a, 0xb);
    t.v = *v;
    func_021ABFA8(a, d_021DAB90, 0, 0, &t, 0);
}








void func_021C928C(u32 a)
{
    u32 z;
    BsubwayScrWork *e;
    if (a != 0) {
        e = (BsubwayScrWork *)func_021AC1E0(a);
        if (e->f10 == 0) {
            z = 0;
            e->f10 = 1;
            func_0204784C((struct AnmCtl *)e->f14, 1, (s32 *)(&z));
        }
    }
}









void func_021C92B0(u32 a, u32 *q)
{
    *(S4 *)q = *((S4 *)func_021AC1AC(a));
    func_021AC1CC(a, q + 1);
    q[8] = (u32)func_02047400((void *)(((u32 *)q[0])[3]), 0, (void *)(((u32 *)q[0])[3]));
    q[6] = (u32)func_02047564((struct G3dOwner *)q[8], (const struct G3dOwner *)(((u32 *)q[0])[8]), 0);
    q[7] = (u32)func_02047564((struct G3dOwner *)q[8], (const struct G3dOwner *)(((u32 *)q[0])[9]), 0);
    q[5] = (u32)func_0204767C(q[8], q + 6, 2);
    func_020477A4((struct G3dSys *)q[5], 0);
    func_020477A4((struct G3dSys *)q[5], 1);
}








void func_021C9314(void *task, BsubwayScrWork *e)
{
    func_0204762C((struct Rec *)e->f18);
    func_0204762C((struct Rec *)e->f1C);
    func_02047738((struct Rec *)e->f14);
    func_02047504((struct Rec *)e->f20);
}








void func_021C9334(void *task, BsubwayScrWork *e)
{
    func_02047910((void *)e->f14, 0, 0x1000);
    if (e->f10 == 1 && func_020478B8((void *)e->f14, 1, 0x1000) == 0)
        e->f10 = 0;
}








void func_021C9360(u32 a, BsubwayScrWork *e)
{
    T_021C8FE0 t = d_021DAC44;
    func_0207ADC4(t.b);
    func_021AC1B8(a, &t);
    func_02047AC8((void *)e->f14, (struct Arg *)(&t));
}








u32 *func_021C939C(u32 a, u32 heap)
{
    u32 *q = func_02030734(heap, 4, 1, d_021DE558, 0x4f);
    q[0] = func_0204A1BC(0x9c, a, 0, heap);
    return q;
}








void func_021C93D0(void **q)
{
    func_020307B0(q[0]);
    func_020307B0(q);
}









void func_021C93E4(u32 a, u8 *q, u32 x, u32 y, u32 z, u32 w, u32 n, u32 cnt)
{
    u8 *t = (u8 *)func_021C94AC(a);
    u8 *qb = q + 4;
    u8 *tb = t + 4;
    u32 i;

    for (i = 0; i < cnt; i++) {
        func_02082D44(tb + (x + (y + i) * ((struct Obj20228 *)t)->f0) * 0x18,
                      qb + (z + (w + i) * ((struct Obj20227 *)q)->f0) * 0x18, n * 0x18);
    }
}









u32 func_021C9450(u32 a, u32 b, u32 c, u32 d, int e, int f)
{
    u32 *t = (u32 *)func_021C94B4(a);
    u32 *e0 = t + 1;
    u32 i;
    u32 loc[4];

    for (i = 0; i < t[0]; i++) {
        func_02082D44(e0 + i * 4, loc, 0x10);
        loc[0] += e << 16;
        loc[2] -= f << 16;
        func_0218BA04(b, c, loc, d + i);
    }
    return d + t[0];
}









int func_021C94AC(u32 a)
{
return (((struct Obj12137 *)((u8 *)(a)))->f0 + *(u16 *)((u8 *)(((struct Obj12137 *)((u8 *)(a)))->f0)));
}









int func_021C94B4(u32 a)
{
return (((struct Obj12138 *)((u8 *)(a)))->f0 + *(u16 *)((u8 *)(((struct Obj12138 *)((u8 *)(a)))->f0) + 2));
}








u32 *func_021C94BC(u32 a, u32 heap)
{
    u32 *q = func_02030734(heap, 0x1c, 1, d_021DE578, 0x66);
    q[0] = a;
    func_021C94F4((Q_021C94F4 *)q);
    return q;
}









void func_021C94E0(u32 a, u8 *p)
{
    func_021C952C((Q_021C94F4 *)p);
    func_020307B0(p);
}









void func_021C94F4(Q_021C94F4 *q)
{
    u32 h = func_021ABE24((u8 *)q->f0);
    int i;
    q->f4 = (u32)func_02046E24(h, 0x52);
    func_02046FF8((int *)q->f4);
    for (i = 0; i < 3; i++)
        q->f8[i] = (u32)func_02046E24(h, d_021DE56C[i]);
}









void func_021C952C(Q_021C94F4 *q)
{
    int i;
    for (i = 0; i < 3; i++)
        func_02046EFC((struct Tagged *)q->f8[i]);
    func_020470D0((u32 *)q->f4);
    func_02046EFC((struct Tagged *)q->f4);
}










void func_021C9550(u32 a, u32 b)
{
    V3 v;
    Rec r;

    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&v);
    switch (func_0216D5F8((void *)a)) {
    case 0:
        v.v[2] -= 0x10000;
        break;
    case 1:
        v.v[2] += 0x10000;
        break;
    case 2:
        v.v[0] -= 0x10000;
        break;
    case 3:
        v.v[0] += 0x10000;
        break;
    }
    r.h = func_021ABEA0(b, 0xc);
    r.pos = v;
    func_021ABFA8(b, d_021DAC80, 0, 0, &r, 0);
}










/*
 * The `adds r4, r6, #0` before the first loop is the second loop's counter
 * initialised to 0 and shared as the first loop's constant 0 argument; both
 * loops use one counter i. Callee widths from arm9 func_02048744.
 * Addresses are Black-image addresses.
 */
void func_021C95D8(u32 a, u32 *b)
{
    u32 *p = (u32 *)func_021AC1AC(a);
    int i;

    b[0] = p[0];
    func_021AC1CC(a, p + 1);
    b[5] = (u32)func_02047400((void *)(((u32 *)b[0])[1]), 0, (void *)(((u32 *)b[0])[1]));
    for (i = 0; i < 3; i++)
        b[2 + i] = (u32)func_02047564((struct G3dOwner *)b[5], (const struct G3dOwner *)(((u32 *)b[0])[2 + i]), 0);
    b[1] = (u32)func_0204767C(b[5], b + 2, 3);
    for (i = 0; i < 3; i++)
        func_020477A4((struct G3dSys *)b[1], (u16)i);
}









void func_021C963C(void *task, Q_021C9550 *q)
{
    int i;
    for (i = 0; i < 3; i++)
        func_0204762C((struct Rec *)q->f8[i]);
    func_02047738((struct Rec *)q->f4);
    func_02047504((struct Rec *)q->f14);
}









void func_021C9660(u32 a, Q_021C9550 *q)
{
    int done = 1;
    int i;
    for (i = 0; i < 3; i++) {
        if (func_020478B8((void *)q->f4, (u16)i, (u32)0x1000) == 1)
            done = 0;
    }
    if (done)
        func_021AC154(a);
}









void func_021C9690(u32 a, BsubwayScrWork *e)
{
    T_021C8FE0 t = d_021DAC94;
    func_0207ADC4(t.b);
    func_021AC1B8(a, &t);
    func_02047AC8((void *)e->f4, (struct Arg *)(&t));
}









int func_021C96CC(u32 a, u32 *q, u32 *p)
{
    int v[3];
    int box[4];
    u32 h;
    u32 r;

    switch (q[0]) {
    case 0:
        func_020061E4(0x55B);
        func_021A3038(func_02188CB4((struct Obj00020 *)p[1]), (struct VecFx32 *)v);
        box[0] = v[2] - 0x10000;
        box[1] = v[2] + 0x10000;
        box[2] = v[0] - 0x10000;
        box[3] = v[0] + 0x10000;
        h = func_0218DC6C((u8 *)func_02188C98((void *)p[1]));
        r = func_0218C638(h, 4, (int)box);
        if (r != 0) {
            p[2] = r;
            func_0218C69C((unsigned char *)h, r, 0, 0);
        }
        q[0]++;
        break;
    case 1:
        if (func_02006224(func_02006148(0x55B)) == 0) {
            q[0]++;
        }
        break;
    case 2:
        func_020061E4(0x55C);
        if (p[2] != 0) {
            h = func_0218DC6C((u8 *)func_02188C98((void *)p[1]));
            func_0218C69C((unsigned char *)h, p[2], 1, 2);
        }
        q[0]++;
        break;
    case 3:
        return 1;
    }
    return 0;
}








u32 func_021C978C(u32 a, u32 b, u32 c)
{
    u32 t = (u32)func_020122C0((void *)b, (void *)a, func_021C96CC, 0x14);
    BsubwayScrWork *w = func_020124E8((struct Obj *)t);
    w->f0 = b;
    w->f4 = c;
    w->f8 = 0;
    return t;
}









int func_021C97B8(u32 a, u32 *q, u32 *p)
{
    int v[3];
    int box[4];
    u32 h;
    u32 r;

    switch (q[0]) {
    case 0:
        func_021A3038(func_02188CB4((struct Obj00020 *)p[1]), (struct VecFx32 *)v);
        box[0] = v[2] - 0x10000;
        box[1] = v[2] + 0x10000;
        box[2] = v[0] - 0x10000;
        box[3] = v[0] + 0x10000;
        h = func_0218DC6C((u8 *)func_02188C98((void *)p[1]));
        r = func_0218C638(h, 4, (int)box);
        if (r != 0) {
            p[2] = r;
            func_0218C69C((unsigned char *)h, r, 1, 2);
        }
        q[0]++;
        break;
    case 1:
        return 1;
    }
    return 0;
}








u32 func_021C9828(u32 a, u32 b, u32 c)
{
    u32 t = (u32)func_020122C0((void *)b, (void *)a, func_021C97B8, 0x14);
    BsubwayScrWork *w = func_020124E8((struct Obj *)t);
    w->f0 = b;
    w->f4 = c;
    w->f8 = 0;
    return t;
}









int func_021C9854(u32 a, u32 *q, u32 *p)
{
    int v[3];
    int box[4];
    u32 h;
    u32 r;

    switch (q[0]) {
    case 0:
        if (p[4] == 0)
            func_020061E4(0x55D);
        func_021A3038(func_02188CB4((struct Obj00020 *)p[1]), (struct VecFx32 *)v);
        box[0] = v[2] - 0x10000;
        box[1] = v[2] + 0x10000;
        box[2] = v[0] - 0x10000;
        box[3] = v[0] + 0x10000;
        h = func_0218DC6C((u8 *)func_02188C98((void *)p[1]));
        r = func_0218C638(h, 4, (int)box);
        if (r != 0) {
            p[2] = r;
            func_0218C69C((unsigned char *)h, r, 2, 0);
        }
        q[0]++;
        break;
    case 1:
        if (p[4] == 0) {
            if (func_02006224(func_02006148(0x55D)) == 0) {
                q[0]++;
            }
        } else {
            q[0]++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}








u32 func_021C98F4(u32 a, u32 b, u32 c, u32 d)
{
    u32 t = (u32)func_020122C0((void *)b, (void *)a, func_021C9854, 0x14);
    W_021C98F4 *w = func_020124E8((struct Obj *)t);
    w->f0 = b;
    w->f4 = c;
    w->f8 = 0;
    w->f10 = d;
    return t;
}









/*
 * Blocking site: the bl to func_02012EE4 at +0008 of this function.
 *
 * no listing carries a func_ label at this address -- disasm.py classified the bytes as data in every overlay whose window holds it -- and the only branches to it are these ov021 call sites, so the `label` class has no traced entry point to read and a region hint cannot invent one.  Filing a source for the TARGET (rule 10) would attest every caller that needs it, with no change here.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C9924(u32 a)
{
return (int)func_02012EE4((char *)func_020120F4((const struct Ctx *)a), 0);
}









Obj *func_021C9934(void *arg, int mode, u32 kind)
{
    void *sys;
    void *save;
    void *res;
    Obj *p;
    int i;
    u32 base;
    u32 k;
    u16 v;
    u8 t;

    sys = func_020120F4(arg);
    save = func_02012944(sys);
    res = func_02012EBC(sys);
    p = func_02030734(4, 0x7EC, 1, d_021DE58C, 0x5f);
    p->heap = 4;
    p->magic = 0x12345678;
    p->sys = sys;
    p->fa = func_02008550(save);
    p->f70 = func_020071CC(res, 0x39);
    p->f74 = func_020071CC(res, 0x3a);
    p->f78 = func_020071CC(res, 0x3b);
    func_0200D868(p->f70, 0);
    func_02012EE4(sys, (int)p);
    if (mode == 0) {
        p->kind = kind;
        p->f8 = func_021CA270(p->kind);
        for (i = 0; i < 4; i++)
            p->f1e[i] = 0xff;
        for (i = 0; i < 14; i++)
            p->f32[i] = 0xffff;
        func_0200D85C(p->f70);
        func_0200DA14(p->f70);
        if (func_0200DB44(p->f74, p->kind) == 1)
            func_021CA238((u8 *)p, func_0200DAC4(p->f74, p->kind));
        t = p->kind;
        func_0200D914(p->f70, 0, &t);
    } else {
        p->kind = func_0200D884(p->f70, 0, 0);
        p->f8 = func_021CA270(p->kind);
        if (func_0200D884(p->f70, 10, 0) != 0)
            func_021CA1E4((u8 *)p);
        func_0200D884(p->f70, 5, p->f1e);
        func_0200D884(p->f70, 8, p->f32);
        if (p->kind == 2 || p->kind == 7) {
            p->sel = (u8)func_0200D884(p->f70, 9, 0);
            func_0200D884(p->f70, 6, p->small[p->sel]);
            base = 0x12f;
            if (func_02008550((const struct Sub0200852CObj *)((u8 *)func_020127A4(sys) + 0x20)) != 0)
                base -= 3;
            i = p->sel;
            func_021CBF38(p, p->big[i], base + i, func_0200D884(p->f70, 7, 0), (TrainerRec *)p->small[i], p->heap);
        }
        k = p->kind;
        if (func_0200DB44(p->f74, k) == 1) {
            v = func_0200DA54(p->f70);
            func_021CA258((Cnt *)p, func_0200DB80(p->f74, k), v);
        }
    }
    return p;
}









void func_021C9B24(u32 a, u8 *p)
{
    if (p != 0) {
        if (((struct Obj05093 *)p)->f7C8 != 0) {
            func_020307B0(((struct Obj05093 *)p)->f7C8);
            ((struct Obj05093 *)p)->f7C8 = 0;
        }
        if (((struct Obj05093 *)p)->f7CC != 0) {
            func_020130B4((int)(((struct Obj05093 *)p)->f7CC));
            ((struct Obj05093 *)p)->f7CC = 0;
        }
        func_02082BCC(p, 0, 0x7EC);
        func_020307B0(p);
    }
    func_02012EE4(func_020120F4((const struct Ctx *)a), 0);
}








/*
 * Remaps kind 2/7 to 3/8, pushes it to the +0x70 object and refreshes the +0xe counter from +0x74.
 *
 * Addresses are Black-image addresses.
 */
void func_021C9B78(u8 *p)
{
    u8 v;

    if (p[9] == 2)
        v = 3;
    else if (p[9] == 7)
        v = 8;
    p[9] = v;
    func_0200D914((struct Blk3C *)(((struct Obj03617 *)p)->f70), 0, &v);
    if (func_0200DB44((struct Blk1AC *)(((struct Obj03617 *)p)->f74), p[9]) == 1)
        func_021CA238(p, func_0200DAC4((struct Blk1AC *)(((struct Obj03617 *)p)->f74), p[9]));
    else
        func_021CA250((u32)p);
}








/*
 * Pushes the kind, the +0x1e and +0x32 blocks and, for kind 2/7, the selected +0x628 entry to the +0x70 object.
 *
 * Addresses are Black-image addresses.
 */
void func_021C9BCC(u8 *p)
{
    u8 v = p[9];

    func_0200D914((struct Blk3C *)(((struct Obj02732 *)p)->f70), 0, &v);
    func_0200D914((struct Blk3C *)(((struct Obj02732 *)p)->f70), 5, p + 0x1e);
    func_0200D914((struct Blk3C *)(((struct Obj02732 *)p)->f70), 8, p + 0x32);
    func_0200D868((struct Blk3C *)(((struct Obj02732 *)p)->f70), 1);
    if (p[9] == 2 || p[9] == 7) {
        v = ((Sel *)p)->sel;
        func_0200D914((struct Blk3C *)(((struct Obj02732 *)p)->f70), 9, &v);
        func_0200D914((struct Blk3C *)(((struct Obj02732 *)p)->f70), 6, p + 0x628 + ((Sel *)p)->sel * 0x14);
        func_0200D914((struct Blk3C *)(((struct Obj02732 *)p)->f70), 7, p + 0x664 + ((Sel *)p)->sel);
    }
}








/*
 * Classifies the kind into the +8 count and reads two stats per slot into +0x22 and +0x2a.
 *
 * Addresses are Black-image addresses.
 */
void func_021C9C54(u8 *p, u32 x)
{
    void *h;
    int i;
    u32 m;

    p[8] = func_021CA270(p[9]);
    func_0200D884((struct Blk3C *)(((struct Obj00116 *)p)->f70), 5, p + 0x1e);
    h = func_021CA210(p);
    for (i = 0; i < p[8]; i++) {
        m = (u32)func_0201AB28(h, p[0x1e + i]);
        ((Stats *)p)->a22[i] = func_02017E1C((void *)m, 5, 0);
        ((Stats *)p)->a2a[i] = func_02017E1C((void *)m, 6, 0);
    }
}








/*
 * Like 0x021C9BCC with a reset of the +0x70 object and without the +0x32 block.
 *
 * Addresses are Black-image addresses.
 */
void func_021C9CAC(u8 *p)
{
    u8 v = p[9];

    func_0200D914((struct Blk3C *)(((struct Obj02733 *)p)->f70), 0, &v);
    func_0200DA14((struct Blk3C *)(((struct Obj02733 *)p)->f70));
    func_0200D914((struct Blk3C *)(((struct Obj02733 *)p)->f70), 5, p + 0x1e);
    func_0200D868((struct Blk3C *)(((struct Obj02733 *)p)->f70), 1);
    if (p[9] == 2 || p[9] == 7) {
        v = ((Sel *)p)->sel;
        func_0200D914((struct Blk3C *)(((struct Obj02733 *)p)->f70), 9, &v);
        func_0200D914((struct Blk3C *)(((struct Obj02733 *)p)->f70), 6, p + 0x628 + ((Sel *)p)->sel * 0x14);
        func_0200D914((struct Blk3C *)(((struct Obj02733 *)p)->f70), 7, p + 0x664 + ((Sel *)p)->sel);
    }
}








/*
 * Reads flag 0 of resource 0x39, resets it and forwards the flag to resource 0x3a.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C9D30(const struct Ctx *a0)
{
    u32 a = (u32)func_02012EBC((struct Big *)func_020120F4(a0));
    u32 b = (u32)func_020071CC((struct Sub020071CCCtrl *)a, 0x39);
    u32 c = (u32)func_020071CC((struct Sub020071CCCtrl *)a, 0x3a);
    u8 r = func_0200D884((struct Blk3C *)b, 0, 0);

    func_0200DA14((struct Blk3C *)b);
    func_0200DB1C((struct Blk1AC *)c, r);
    return r;
}








/*
 * Commits the +0xe counter for the current kind and redraws.
 *
 * Addresses are Black-image addresses.
 */
void func_021C9D70(u32 unused, u8 *p)
{
    u16 v = ((struct Obj00116 *)p)->fE;
    u8 kind = p[9];
    u32 h = ((struct Obj00116 *)p)->f74;

    func_0200DB08((struct Blk1AC *)h, kind, v);
    func_0200DAEC((struct Blk1AC *)h, kind, v);
    func_021CA2DC(p, (u32)func_02012EBC((struct Big *)(*(u32 *)&((struct Obj00116 *)p)->f6C)), 1, v);
    func_0200DB1C((struct Blk1AC *)(((struct Obj00116 *)p)->f74), kind);
    func_0200DA14((struct Blk3C *)(((struct Obj00116 *)p)->f70));
}








/*
 * Picks a step amount from a 7x10 byte table by mode byte +9 and a clamped
 * counter, adds it to the record at +0x74 and returns it.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C9DB0(u8 *p)
{
    int r;
    int row;
    int idx;
    u16 n;

    if (p[9] == 4) {
        r = 0;
        if ((u16)func_0200D884(((struct Obj04291 *)p)->f70, 0xB, 0) == 1) {
            idx = (s8)func_0200DC08(((struct Obj04291 *)p)->f74);
            if (idx < 0)
                idx = 0;
            else if (idx >= 10)
                idx = 9;
            r = d_021DACDC[6][idx];
        } else {
            r = 5;
        }
    } else {
        r = 0;
        n = func_0200DB80(((struct Obj04291 *)p)->f74, p[9]);
        switch (p[9]) {
        case 0:
            row = 0;
            break;
        case 5:
            row = 1;
            r = 1;
            break;
        case 1:
            row = 2;
            break;
        case 6:
            row = 3;
            r = 1;
            break;
        case 2:
            row = 4;
            break;
        case 3:
            row = 4;
            break;
        case 7:
            row = 5;
            r = 1;
            break;
        case 8:
            row = 5;
            r = 1;
            break;
        case 4:
            row = 6;
            break;
        default:
            row = 0;
            break;
        }
        n = n - 1;
        if ((s16)n < 0)
            idx = 0;
        else if (n >= 10)
            idx = 9;
        else
            idx = n;
        if (((Bits *)(p + 0xC))->b1) {
            if (r == 1)
                r = 30;
            else
                r = 10;
        } else {
            r = d_021DACDC[row][idx];
        }
    }
    if (r == 0)
        r = 1;
    func_0200DA80(((struct Obj04291 *)p)->f74, r);
    return r;
}








/*
 * Fills the +0x32 halfword list with distinct draws: 14 for kinds 2, 3, 7, 8, else 7.
 *
 * Addresses are Black-image addresses.
 */
void func_021C9E8C(u8 *p)
{
    u8 kind = p[9];
    u16 lim = func_021CA2CC(func_021CA234(p));
    int i;
    u16 v;

    if (kind == 2 || kind == 3 || kind == 7 || kind == 8) {
        if (lim < ((struct Obj05094 *)p)->f18)
            lim = ((struct Obj05094 *)p)->f18;
        for (i = 0; i < 14; i++) {
            do {
                v = func_021CBD90(p, lim, (u8)(i / 2), kind, (u8)(i & 1));
            } while (func_021CA2A4((u16 *)(p + 0x32), v, i));
            ((u16 *)(p + 0x32))[i] = v;
        }
    } else {
        for (i = 0; i < 7; i++) {
            do {
                v = func_021CBD90(p, lim, (u8)i, p[9], 0);
            } while (func_021CA2A4((u16 *)(p + 0x32), v, i));
            ((u16 *)(p + 0x32))[i] = v;
        }
    }
}








/*
 * Unless blocked, clamps each slot's +0x7c id to 1..6, copies it into +0x1e and reloads the slot's two stats.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C9F44(u8 *p, u32 x)
{
    void *h;
    u16 i;
    u8 *q;
    u32 m;

    if (((struct Obj00116 *)p)->f84 != 0 || ((struct Obj00116 *)p)->f82 == 7 || ((struct Obj00116 *)p)->f82 == 8)
        return 0;
    h = func_021CA210(p);
    for (i = 0; i < p[8]; i++) {
        q = p + i;
        if (q[0x7c] - 1 >= 6)
            q[0x7c] = 1;
        q[0x1e] = q[0x7c] - 1;
        m = (u32)func_0201AB28(h, q[0x1e]);
        ((Stats *)p)->a22[i] = func_02017E1C((void *)m, 5, 0);
        ((Stats *)p)->a2a[i] = func_02017E1C((void *)m, 6, 0);
    }
    return 1;
}








/*
 * Latches bit 0 of +0xc once the +0x70 object's count reaches 7.
 *
 * Addresses are Black-image addresses.
 */
int func_021C9FD0(u8 *p)
{
    if (((Latch *)p)->done == 0) {
        if (func_0200DA54((struct Blk3C *)(((struct Obj20232 *)p)->f70)) < 7)
            return 0;
        ((Latch *)p)->done = 1;
    }
    return 1;
}








/*
 * Commits the +0xe counter and the current kind's level and redraws.
 *
 * Addresses are Black-image addresses.
 */
void func_021C9FFC(u8 *p, u32 x)
{
    u8 kind = p[9];
    u16 v = func_021CA234(p);

    func_0200DB08((struct Blk1AC *)(((struct Obj00116 *)p)->f74), kind, v);
    func_0200DAEC((struct Blk1AC *)(((struct Obj00116 *)p)->f74), kind, func_0200DAC4((struct Blk1AC *)(((struct Obj00116 *)p)->f74), kind));
    func_0200DB60((struct Blk1AC *)(((struct Obj00116 *)p)->f74), kind);
    func_021CA2DC(p, (u32)func_02012EBC((struct Big *)(*(u32 *)&((struct Obj00116 *)p)->f6C)), 1, v);
    func_0200DA14((struct Blk3C *)(((struct Obj00116 *)p)->f70));
}








int func_021CA048(u32 a, u32 b)
{
((struct Obj07233 *)((u8 *)(a)))->fC = (((struct Obj07233 *)((u8 *)(a)))->fC & ~1);
((struct Obj07233 *)((u8 *)(a)))->fC = (((struct Obj07233 *)((u8 *)(a)))->fC & ~6);
return a;
}








/*
 * Draws the current page of the +0x32 list through 0x021CBED8; kinds 2, 3, 7, 8 draw two pages with the slot tags.
 *
 * Addresses are Black-image addresses.
 */
void func_021CA05C(u8 *p)
{
    u32 n = func_0200DA54((struct Blk3C *)(((struct Obj01671 *)p)->f70));
    int i;
    u32 j;
    u16 tags[2];
    u16 vals[2];

    switch (p[9]) {
    case 4:
        func_0200DEA8(((struct Obj01671 *)p)->f78, p + 0x88, n, ((struct Obj01671 *)p)->f4);
        return;
    case 2:
    case 3:
    case 7:
    case 8:
        i = 0;
        j = n * 2;
        func_021CBED8(p, p + 0x88, ((u16 *)(p + 0x32))[j], p[8], 0, 0, 0, ((struct Obj01671 *)p)->f4);
        for (; i < p[8]; i++) {
            tags[i] = ((TagVal *)(p + 0xb8))[i].tag;
            vals[i] = ((TagVal *)(p + 0xb8))[i].val;
        }
        func_021CBED8(p, p + 0x1a8, ((u16 *)(p + 0x32))[j + 1], p[8], (u16 *)tags, (u16 *)vals, 0, ((struct Obj01671 *)p)->f4);
        return;
    }
    func_021CBED8(p, p + 0x88, ((u16 *)(p + 0x32))[n], p[8], 0, 0, 0, ((struct Obj01671 *)p)->f4);
}








/*
 * Tail-calls into ov010 with the halfword at +0x8c of the 0x120-byte entry i.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CA150(u8 *p, int i)
{
    return func_02168AEC(*(u16 *)(p + i * 0x120 + 0x8c));
}








/*
 * Steps an arm9 object by mode (0, 3, 4) and reports whether it advanced.
 *
 * Addresses are Black-image addresses.
 */
int func_021CA164(void *a, int unused, int mode)
{
    u8 state = (int)func_0200DC08(a);
    u32 v;

    switch (mode) {
    case 0:
        return state;
    case 3:
        func_0200DBA0(a, 0, 2);
        if (state == 10)
            return 0;
        func_0200DBF0(a);
        return 1;
    case 4:
        v = func_0200DC0C(a, 3);
        if (state == 1)
            return 0;
        if (v >= data_021DACD0[state - 1]) {
            func_0200DBFC(a);
            func_0200DC0C(a, 2);
            func_0200DBA0(a, 0, 2);
            return 1;
        }
        return 0;
    }
    return 0;
}








/*
 * Releases the handle at +0x7c8 and allocates a fresh one from the object at +0x6c.
 *
 * Addresses are Black-image addresses.
 */
void func_021CA1E4(u8 *p)
{
    if (((struct Obj07584 *)p)->f7C8 != 0)
        func_020307B0(((struct Obj07584 *)p)->f7C8);
    ((struct Obj07584 *)p)->f7C8 = func_0200BAF4((int)func_0200BAC8(func_02012EBC((struct Big *)(((struct Obj07584 *)p)->f6C))), 4);
}








/*
 * Returns the object at +0x6c's handle unless the query on +0x70 is set, then the cached +0x7c8.
 *
 * Addresses are Black-image addresses.
 */
void *func_021CA210(u8 *p)
{
    if (func_0200D884((struct Blk3C *)(((struct Obj00116 *)p)->f70), 10, 0) == 0)
        return func_02012934(((struct Obj00116 *)p)->f6C);
    return ((struct Obj00116 *)p)->f7C8;
}








/*
 * Loads the 16-bit halfword at +0xe of the object.
 */
u16 func_021CA234(u8 *p)
{
    return ((struct Obj18345 *)p)->fE;
}








/*
 * Field setter at +0xe.
 *
 * Addresses are Black-image addresses.
 */
void func_021CA238(u8 *p, u16 v)
{
    ((struct Obj18346 *)p)->fE = v;
}






/*
 * Saturating increment of the halfword counter at +0xe.
 * Addresses are Black-image addresses.
 */
void func_021CA23C(u8 *p)
{
    u16 v = ((struct Obj12970 *)p)->fE;
    if (v < 0xffff)
        ((struct Obj12970 *)p)->fE = v + 1;
}






int func_021CA250(u32 a)
{
((struct Obj18347 *)((u8 *)(a)))->fE = 0;
return a;
}





void func_021CA258(Cnt *p, u32 a, u32 b)
{
    u32 v = a * 7;
    v += b;
    if (v > 0xffff)
        v = 0xffff;
    p->fE = v;
}






int func_021CA270(u16 kind)
{
    switch (kind) {
    case 0:
    case 4:
    case 5:
        return 3;
    case 1:
    case 6:
        return 4;
    case 2:
    case 3:
    case 7:
    case 8:
        return 2;
    }
    return 0;
}






/*
 * Linear search of a halfword array.
 * Addresses are Black-image addresses.
 */
int func_021CA2A4(const u16 *arr, u16 val, u16 n)
{
    u16 i;
    for (i = 0; i < n; i++) {
        if (val == arr[i])
            return 1;
    }
    return 0;
}






u16 func_021CA2CC(u16 v)
{
return (u16)func_0209C0A4(v, 7);
}






void func_021CA2DC(u8 *p, u32 h, int flag, u16 v)
{
    u8 b;

    switch (p[9]) {
    case 0:
        func_021CA4C0(p, h, 0);
        break;
    case 1:
        break;
    case 4:
        func_021CA4C0(p, h, 1);
        b = p[9];
        func_0200D914((struct Blk3C *)(((struct Obj00116 *)p)->f70), 0, &b);
        b = func_0200DA54((struct Blk3C *)(((struct Obj00116 *)p)->f70)) + 1;
        func_0200D914((struct Blk3C *)(((struct Obj00116 *)p)->f70), 1, &b);
        func_0200DC94((struct Blk1AC *)(((struct Obj00116 *)p)->f74), (const struct Src *)(((struct Obj00116 *)p)->f70));
        break;
    }
}






/*
 * Draws the three +0x628 entries through 0x021CBED8 and stores each result byte at +0x664.
 *
 * Addresses are Black-image addresses.
 */
void func_021CA338(u8 *p, u8 alt)
{
    int base = 300;
    int i;

    if (alt)
        base += 3;
    for (i = 0; i < 3; i++)
        p[0x664 + i] = func_021CBED8(p, p + 0x2c8 + i * 0x120, base + i, p[8],
                                     (u16 *)(p + 0x22), (u16 *)(p + 0x2a),
                                     p + 0x628 + i * 0x14, ((struct Obj09722 *)p)->f4);
}






/*
 * Packs one party member into a 0x3c-byte slot: species/form, item, four moves with their PP-up bits, ids, stats and nickname.
 *
 * Addresses are Black-image addresses.
 */
void func_021CA3B4(PartySlot *s, u32 m)
{
    int i;

    s->species = func_02017E1C((void *)m, 5, 0);
    s->form = func_02017E1C((void *)m, 0x6f, 0);
    s->item = func_02017E1C((void *)m, 6, 0);
    for (i = 0; i < 4; i++) {
        s->moves[i] = func_02017E1C((void *)m, 0x36 + i, 0);
        s->ppups |= func_02017E1C((void *)m, 0x3e + i, 0) << (i * 2);
    }
    s->f1f = func_02017E1C((void *)m, 0xc, 0);
    s->f0c = func_02017E1C((void *)m, 7, 0);
    s->f10 = func_02017E1C((void *)m, 0, 0);
    s->f14 = func_02017E1C((void *)m, 0xac, 0);
    for (i = 0; i < 6; i++)
        s->f18[i] = func_02017E1C((void *)m, 0xd + i, 0);
    s->f20 = func_02017E1C((void *)m, 0xa, 0);
    s->f21 = func_02017E1C((void *)m, 9, 0);
    func_02017E1C((void *)m, 0x74, (u32)s->name);
}





/*
 * Packs the three selected party members into a scratch buffer from bsubway_scr.c and hands it to the +0x74 object.
 *
 * Addresses are Black-image addresses.
 */
void func_021CA4C0(u8 *p, u32 unused, int flag)
{
    PartySlot *buf;
    int i;
    void *h;

    i = 0;
    buf = func_02030734((u16)(((u16)((struct Obj00116 *)p)->f4 & 0x7fff) | 0x8000), 0xb4, 0, d_021DE58C, 0x89a);
    func_02082BCC(buf, 0, 0xb4);
    h = func_021CA210(p);
    for (; i < 3; i++)
        func_021CA3B4(&buf[i], (u32)func_0201AB28(h, p[0x1e + i]));
    func_0200DC50((struct Blk1AC *)(((struct Obj00116 *)p)->f74), flag, buf);
    func_02082BCC(buf, 0, 0xb4);
    func_020307B0(buf);
}




int func_021CA544(u32 a, u32 b)
{
    void *h = func_0215A5F4((void *)b);
    u32 x, y;
    func_02158F58((int)h);
    x = (u32)func_02158F54(h);
    y = func_02011330((struct Stream *)a);
    func_021C9934((void *)x, y, func_02159B10((void *)a, (void *)b));
    return 0;
}




int func_021CA57C(u32 a, u32 b)
{
    void *h = func_0215A5F4((void *)b);
    func_02158F58((int)h);
    func_021C9924((u32)func_02158F54(h));
    return 0;
}




int func_021CA598(u32 a, u32 b)
{
    void *h = func_0215A5F4((void *)b);
    u32 x;
    func_02158F58((int)h);
    x = (u32)func_02158F54(h);
    func_021C9B24(x, func_02012ED8(func_020120F4((const struct Ctx *)x)));
    return 0;
}





/*
 * Script command dispatcher: reads a command id and two arguments from the
 * script, then runs one of 137 cases on the work area, the save blocks
 * 0x39/0x3A/0x3B and the result slot. Returns 1 when the case started a task
 * the script must wait for.  One 4376-byte function (0x021CA5C4..0x021CB6DC,
 * see layout/far_branch_functions.txt); every concrete byte matches.
 *
 * Shape notes (2026-10-01), all measured:
 * - The switch tree only reproduces with one more empty case label inside the
 *   0..113 jump table (any of 9, 10, 46..99, 102; its entry is the break, so
 *   the value is invisible).  Without it the top group becomes one 359..416
 *   table instead of compares for 358/359 and a 400..416 table.
 * - cmd, p1, p2 and s28 are u16 (u16 returns): u32 makes the tree unsigned,
 *   and u32 p1 truncates before each bitfield insert.
 * - Case 334's counter is an enum local: an int counter folds `i + n + 1` and
 *   the loop's entry guard.
 * - Case 351 writes the result in each arm (cross-jumped tail leaves the
 *   `b` to the next instruction); case 404 sets ret after the call (it is
 *   still scheduled into the argument stores); case 45/322 read the table
 *   row through a pointer and pass its three words as separate arguments.
 *
 * Witnesses (closed 2026-10-02, gA2): func_021542C0 (ov007), func_02167AB0
 *   and func_02167CF4 (ov010) were seeded in layout/function_starts.txt and
 *   filed EXACT; data_021BB474 (ov214) and data_021BB6A4 (ov100) are
 *   hand-declared proc tables in layout/data_objects.txt, and
 *   attest_xwin_loaded() no longer counts ov021's own start at 0x021BB474
 *   as a third-overlay contest.
 */
int func_021CA5C4(void *a, u32 b)
{
    Trip t;
    Rec1C r4;
    Vec v;
    Rec1C r45;
    Rec1C r322;
    Wait st;
    u32 out;
    u16 a40, b40, c40;
    u16 a41, b41, c41;
    u16 a42, b42, c42;
    u8 t108;
    u8 t324;
    int ret;
    void *h;
    u32 x;
    u32 s4c;
    u32 s48;
    u32 s44;
    u8 *w;
    u32 s40;
    u32 s3c;
    u32 s38;
    u32 s34;
    void *s30;
    u16 p1;
    u16 p2;
    u16 s28;
    u16 *dst;
    u16 cmd;

    ret = 0;
    h = func_0215A5F4((void *)b);
    func_02158F58((int)h);
    x = (u32)func_02158F54(h);
    s4c = (u32)func_020120F4((const struct Ctx *)x);
    s48 = (u32)func_02012EBC((struct Big *)s4c);
    s44 = func_0201296C((const struct BigObj *)s4c);
    w = func_02012ED8((struct Big *)s4c);
    s40 = (u32)func_020071CC((struct Sub020071CCCtrl *)s48, 0x39);
    s3c = func_0200D884((struct Blk3C *)s40, 0, 0);
    s38 = (u32)func_020071CC((struct Sub020071CCCtrl *)s48, 0x3a);
    s34 = (u32)func_020071CC((struct Sub020071CCCtrl *)s48, 0x3b);
    s30 = func_0201210C((void *)x);
    cmd = func_02011330(a);
    p1 = func_02159B10(a, (void *)b);
    p2 = func_02159B10(a, (void *)b);
    s28 = func_02011330(a);
    dst = func_02158FE0(h, (void *)s4c, s28);

    if (w == NULL && cmd >= 300)
        return ret;

    switch (cmd) {
    case 0:
        *dst = func_021CBCC4(s30);
        break;
    case 1:
        func_02087BCC(0);
        break;
    case 2:
        func_0200D85C((struct Blk3C *)s40);
        break;
    case 3:
        *dst = func_0200D87C((struct Blk3C *)s40);
        break;
    case 4: {
        void *o = func_02188CB4((void *)s30);
        u32 k = func_021A3050(o);
        int n;
        func_021A3038(o, (struct VecFx32 *)&t);
        switch (k) {
        case 0:
            n = 1;
            break;
        case 1:
            n = 2;
            break;
        case 2:
            n = 3;
            break;
        case 3:
            n = 4;
            break;
        default:
            n = 0;
            break;
        }
        func_02014184(&r4, func_02188C9C(s30), n, t.a, t.b, t.c);
        func_0201289C((struct BigObj *)s4c, (const struct Rec1C *)(&r4));
        func_02014314((char *)s44, 0x966);
        break;
    }
    case 5:
        func_0201433C((char *)s44, 0x966);
        break;
    case 6:
        *dst = func_0200DAC4((struct Blk1AC *)s38, p1);
        if (*dst > 9999)
            *dst = 9999;
        break;
    case 7:
        *dst = func_021C9D30((const struct Ctx *)x);
        break;
    case 12:
        *dst = func_021A3190(func_021A30B0(func_02188CB4((void *)s30)), 0);
        break;
    case 13: {
        void *o = func_0216DE94(func_02188C7C((void *)s30), p1);
        if (o != 0)
            func_0216DAC8(o, p2);
        break;
    }
    case 8:
        *dst = func_0200DA54((struct Blk3C *)s40) + 1;
        break;
    case 11:
        *dst = func_0200DA54((struct Blk3C *)(((struct Obj00335 *)w)->f70));
        *dst += 1;
        break;
    case 14:
        if (data_021DAD36[p1] == 11)
            *dst = 1;
        else
            *dst = func_0200DBA0((struct Blk1AC *)s38, data_021DAD36[p1], 0);
        break;
    case 15:
        if (data_021DAD36[p1] != 11)
            func_0200DBA0((struct Blk1AC *)s38, data_021DAD36[p1], 1);
        break;
    case 16:
        *dst = func_0200DBA0((struct Blk1AC *)s38, 10, 0);
        break;
    case 17:
        func_0200DBA0((struct Blk1AC *)s38, 10, 1);
        break;
    case 18:
        func_021F37C0(s30, data_021DAD88[p1], (int)(&data_021DAD70[p2]));
        break;
    case 19:
        func_021D024C((void *)func_021F380C((int)s30), p1);
        break;
    case 20:
        func_021D028C((void *)func_021F380C((int)s30), p1);
        break;
    case 21:
        *dst = func_0200D884((struct Blk3C *)s40, 0, 0);
        break;
    case 22:
        *dst = 0;
        switch (p1) {
        case 0:
        case 1:
        case 4:
        case 5:
        case 6:
            break;
        case 2:
        case 3:
        case 7:
        case 8:
            *dst = 1;
            break;
        }
        break;
    case 23: {
        u32 y = p2 << 16;
        void *o = func_0216DE94(func_02188C7C((void *)s30), p1);
        if (o != 0) {
            func_0216D88C(o, (struct VecFx32 *)&v);
            v.y = y;
            func_0216E014(o, (int *)(&v), func_0216D5F8(o));
            func_0216DB4C(o, 1);
        }
        break;
    }
    case 24: {
        void *o = func_0216DE94(func_02188C7C((void *)s30), p1);
        if (o != 0)
            func_0216DB4C(o, 0);
        break;
    }
    case 25: {
        void *o = func_0216DE94(func_02188C7C((void *)s30), p1);
        *dst = 0;
        if (o != 0)
            *dst = 1;
        break;
    }
    case 26: {
        void *o = func_0216DE94(func_02188C7C((void *)s30), p1);
        *dst = 0;
        if (o != 0)
            *dst = func_021CBBA0((u32)o);
        break;
    }
    case 27:
        *dst = func_021CA164((void *)s38, x, 0);
        if ((s16)*dst <= 0)
            *dst = 1;
        break;
    case 28:
        *dst = func_021CA164((void *)s38, x, 3);
        break;
    case 29:
        *dst = func_021CA164((void *)s38, x, 4);
        break;
    case 30:
        *dst = func_0200DB80((struct Blk1AC *)s38, p1);
        break;
    case 31:
        *dst = func_021A31A4(func_02008550((const struct Sub0200852CObj *)((u8 *)func_020127A4((struct SaveBlock *)s4c) + 0x20)) == 0 ? 1 : 0, 0);
        break;
    case 32: {
        u32 o = (u32)func_0200BAC8((void *)s48);
        *dst = 0;
        if (func_0200BBA8((void *)o) == 1)
            *dst = 1;
        break;
    }
    case 33:
        *dst = 0;
        break;
    case 34:
        func_021F37C0(s30, 7, (int)data_021DAD70);
        break;
    case 35: {
        void *o = func_0216DE94(func_02188C7C((void *)s30), p1);
        if (o != 0)
            func_0216D5E0((int)o, p2);
        break;
    }
    case 36: {
        void *o = func_0216DE94(func_02188C7C((void *)s30), p1);
        if (o != 0)
            func_0216DAF8(o);
        break;
    }
    case 37:
        func_0215897C(h, func_0216CB48(x, func_0216D63C(func_0216DE94(func_02188C7C((void *)s30), p1), 0), p1));
        ret = 1;
        break;
    case 38:
        *dst = func_0200DB44((struct Blk1AC *)s38, p1);
        break;
    case 39: {
        u32 o = func_0216D63C(func_0216DE94(func_02188C7C((void *)s30), p1), 0);
        *dst = 0;
        if (func_021CBBAC(w, o) == 1)
            *dst = 1;
        break;
    }
    case 40:
        func_021CBBD0(w, func_0216D63C(func_0216DE94(func_02188C7C((void *)s30), p1), 0), &a40, &b40, &c40);
        *dst = a40;
        break;
    case 41:
        func_021CBBD0(w, func_0216D63C(func_0216DE94(func_02188C7C((void *)s30), p1), 0), &a41, &b41, &c41);
        *dst = b41;
        break;
    case 42:
        func_021CBBD0(w, func_0216D63C(func_0216DE94(func_02188C7C((void *)s30), p1), 0), &a42, &b42, &c42);
        *dst = c42;
        break;
    case 43: {
        void *l = func_0200DF58((struct RecSlot *)s34, 4);
        *dst = func_0200DF94(l);
        func_020307B0(l);
        break;
    }
    case 44: {
        u32 f = 0;
        if (p1 == 1)
            f = 1;
        func_0215897C(h, func_021CB9BC((void *)x, b, (u32)dst, f));
        ret = 1;
        break;
    }
    case 45: {
        u16 i = func_021CBCC4(s30);
        const Trip *e = &data_021DAE50[i];
        func_02014184(&r45, data_021DADAC[i], 4, e->a, e->b, e->c);
        func_0201289C((struct BigObj *)s4c, (const struct Rec1C *)(&r45));
        func_02014314((char *)s44, 0x966);
        break;
    }
    case 100:
        if (p1 == 0)
            func_0200DBA0((struct Blk1AC *)s38, 1, 2);
        else
            func_0200DBA0((struct Blk1AC *)s38, 1, 1);
        break;
    case 101:
        *dst = func_0200DBA0((struct Blk1AC *)s38, 1, 0);
        break;
    case 103:
        st.val = 0;
        st.dst = dst;
        func_0215897C(h, func_020124AC((void *)x, (u32)ov007_id, (u32 (*)(void *, u32))func_021542C0, (u32)(&st)));
        ret = 1;
        break;
    case 104:
        ret = 1;
        st.val = 1;
        st.dst = dst;
        func_0215897C(h, func_020124AC((void *)x, (u32)ov007_id, (u32 (*)(void *, u32))func_021542C0, (u32)(&st)));
        break;
    case 105:
        st.val = 2;
        st.dst = dst;
        func_0215897C(h, func_020124AC((void *)x, (u32)ov007_id, (u32 (*)(void *, u32))func_021542C0, (u32)(&st)));
        ret = 1;
        break;
    case 106:
        *dst = func_0200DE94((struct RecSlot *)s34);
        break;
    case 107:
        *dst = func_0200DE5C((struct RecSlot *)s34);
        break;
    case 108:
        t108 = p1;
        func_0200D914((struct Blk3C *)s40, 11, &t108);
        break;
    case 109:
        *dst = func_0200D884((struct Blk3C *)s40, 11, 0);
        break;
    case 110:
        *dst = func_0200DE64((struct RecSlot *)s34);
        break;
    case 111:
        func_0215897C(h, func_0216C860((void *)x));
        ret = 1;
        break;
    case 112:
        *dst = func_0200DF40((struct RecSlot *)s34);
        break;
    case 113:
        *dst = func_0200DF4C((struct RecSlot *)s34);
        break;
    case 200:
        *dst = 0;
        break;
    case 102:
    case 201:
    case 202:
        break;
    case 203:
        *dst = 0;
        break;
    case 322:
        if (s3c < 9) {
            const Trip *e = &data_021DAE50[s3c];
            func_02014184(&r322, data_021DADAC[s3c], 4, e->a, e->b, e->c);
            func_0201289C((struct BigObj *)s4c, (const struct Rec1C *)(&r322));
            func_02014314((char *)s44, 0x966);
        }
        break;
    case 300:
        {
            u8 v = func_0200D884((struct Blk3C *)s40, 10, 0);
            func_0215897C(h, func_0216C538((struct PartyCaller *)w, (void *)x, v));
        }
        ret = 1;
        break;
    case 301:
        *dst = func_021C9F44(w, x);
        break;
    case 302:
        *dst = 0;
        break;
    case 303:
        if (func_021C9FD0(w) == 1)
            *dst = 1;
        else
            *dst = 0;
        break;
    case 304:
        func_021C9D70(x, w);
        break;
    case 305:
        func_021C9FFC(w, x);
        break;
    case 306:
        func_021C9BCC(w);
        break;
    case 307:
        func_021CA05C(w);
        break;
    case 308:
        *dst = func_021CA150(w, p1);
        break;
    case 309:
        func_0215897C(h, func_0216C640(w, x, s30));
        ret = 1;
        break;
    case 310:
        *dst = w[9];
        break;
    case 311:
        FLAGS(w)->f1 = p1;
        break;
    case 312:
        *dst = FLAGS(w)->f1;
        break;
    case 313:
        *dst = func_021C9DB0(w);
        break;
    case 314:
        FLAGS(w)->f5 = p1;
        break;
    case 315:
        *dst = FLAGS(w)->f5;
        break;
    case 316:
        func_021C9E8C(w);
        break;
    case 317:
        *dst = *(w + p1 + 0x1e);
        break;
    case 319:
        w[0x724] = 0;
        func_02082BCC(w + 0x6ae, 0, 0x46);
        break;
    case 320:
        func_0215897C(h, func_0216C6E8(w, (void *)x, p1, p2, 5));
        ret = 1;
        break;
    case 321:
        func_021C9CAC(w);
        break;
    case 323:
        func_021C9C54(w, x);
        break;
    case 324:
        t324 = p1;
        func_0200D914((struct Blk3C *)s40, 10, &t324);
        break;
    case 325:
        func_021C9B78(w);
        break;
    case 326:
        if (s3c - 5 <= 3)
            *dst = 1;
        else
            *dst = 0;
        break;
    case 329:
        func_021CB9E4(w, (void *)s4c, func_02188C7C((void *)s30), s30);
        break;
    case 330:
        FLAGS(w)->b8 = p1;
        break;
    case 331:
        *dst = FLAGS(w)->b8;
        break;
    case 332: {
        u8 *e = *(u8 * *)&((struct Obj00335 *)w)->f7CC;
        if (e == NULL)
            *dst = 0;
        else if (((struct Obj02400 *)e)->f8C == 1)
            *dst = 1;
        else
            *dst = 0;
        break;
    }
    case 333:
        func_021CA048((u32)w, x);
        break;
    case 334: {
        Slot i = 0;
        u16 n = func_0200DA54((struct Blk3C *)s40);
        if (n != 0) {
            void *p = (void *)func_0202B578((u32 *)func_02012134((u32 *)x));
            n = i + n + 1;
            for (; i < n; i++) {
                if (i < 9 && i != 0)
                    func_0202C0D0(p, i);
            }
        }
        break;
    }
    case 335:
        func_021CA338(w, func_02008550((const struct Sub0200852CObj *)((u8 *)func_020127A4((struct SaveBlock *)s4c) + 0x20)) == 0 ? 1 : 0);
        break;
    case 336:
        *dst = *(u16 *)(w + p1 * 2 + 0x22);
        break;
    case 337:
        FLAGS(w)->b9 = p1;
        break;
    case 338:
        *dst = FLAGS(w)->b9;
        break;
    case 339: {
        void *p4 = NULL;
        u32 mode;
        void *rules;
        void *party;
        u32 res;
        *dst = 0;
        mode = func_0200D884((struct Blk3C *)s40, 10, 0);
        rules = func_0201A354(func_021CBC94(s3c), 4);
        if (mode == 1) {
            p4 = func_0200BAF4((u32)func_0200BAC8((void *)s48), 4);
            party = p4;
        } else {
            party = func_02012934((void *)s4c);
        }
        res = func_02019ED4(rules, party);
        func_020307B0(rules);
        if (p4 != NULL)
            func_020307B0(p4);
        if (res <= 1)
            *dst = 1;
        break;
    }
    case 340:
        func_021CA1E4(w);
        break;
    case 341:
        *dst = func_021CBC94(s3c);
        break;
    case 342:
        *dst = func_021CA270(s3c);
        break;
    case 343:
        if (FLAGS(w)->f10 == 0) {
            FLAGS(w)->f10 = 1;
            if (func_0200B5CC((void *)s48, 4, &out, 0) == 1)
                FLAGS(w)->f10 = 2;
        }
        break;
    case 344:
        if (FLAGS(w)->f10 == 1)
            *dst = 0;
        else
            *dst = 1;
        break;
    case 345:
        func_0200BA58();
        func_021EEE78((void *)(*(u32 *)&((struct Obj00335 *)w)->f7CC));
        func_0200BA68();
        break;
    case 346:
        ((struct Obj00335 *)w)->f7E8 = 0;
        ((struct Obj00335 *)w)->f7EA = 0;
        ((struct Obj00335 *)w)->f10 = p1;
        func_020113D0(a, (int)func_021CBC14);
        FLAGS(w)->f10 = 2;
        ret = 1;
        break;
    case 347:
        if (*(u32 *)&((struct Obj00335 *)w)->f7CC != 0) {
            func_0200B424();
            func_020130B4(*(u32 *)&((struct Obj00335 *)w)->f7CC);
            *(u32 *)&((struct Obj00335 *)w)->f7CC = 0;
        }
        break;
    case 348:
        func_02082BCC(w + 0x7d0, 0, 0x18);
        ((struct Obj00335 *)w)->f7D0 = s4c;
        ((struct Obj00335 *)w)->f7D4 = 1;
        ((struct Obj00335 *)w)->f7D8 = 0;
        ((struct Obj00335 *)w)->f7DC = 1;
        ((struct Obj00335 *)w)->f7E0 = data_021DAD24[s3c];
        ((struct Obj00335 *)w)->f7E4 = func_021CA234(w);
        if (((struct Obj00335 *)w)->f7E4 > 9999)
            ((struct Obj00335 *)w)->f7E4 = 9999;
        func_0215897C(h, func_02014808((char *)x, (int)s30, (u32)ov214_id, (int)data_021BB474, (int)(w + 0x7d0), 0, 0));
        ret = 1;
        break;
    case 349:
        func_0200DA14((struct Blk3C *)s40);
        func_0200DB1C((struct Blk1AC *)s38, s3c);
        break;
    case 350:
        func_021F388C((int)s30);
        break;
    case 351: {
        u32 n = func_0200DA54((struct Blk3C *)s40);
        switch (s3c) {
        case 2:
        case 3:
        case 7:
        case 8:
            *dst = *(u16 *)(w + (n * 2 + p1) * 2 + 0x32);
            break;
        case 0:
        case 1:
        case 4:
        case 5:
        case 6:
        default:
            *dst = *(u16 *)(w + n * 2 + 0x32);
            break;
        }
        break;
    }
    case 352:
        func_0215897C(h, func_0216C6E8(w, (void *)x, p1, p2, 6));
        ret = 1;
        break;
    case 353: {
        u8 *e = *(u8 * *)&((struct Obj00335 *)w)->f7CC;
        if (e != NULL) {
            u32 kb6 = e[0xb6];
            u32 kbf = e[0xbf];
            int cnt;
            void *party = ((struct Obj02400 *)e)->f24;
            int i;
            int sa;
            int sb;
            cnt = func_0201AA18(party);
            sa = 0;
            sb = 0;
            for (i = 0; i < cnt; i++) {
                void *mon = func_0201AB28(party, i);
                int a1 = func_02017E1C(mon, 0xa0, 0);
                int b1 = func_02017E1C(mon, 0xa1, 0);
                sa += a1;
                sb += b1;
            }
            func_0200D9E8((struct Blk3C *)s40, kbf, kb6, (u16)(sb - sa));
        }
        break;
    }
    case 354:
        FLAGS(w)->b12 = p1;
        break;
    case 355:
        *dst = FLAGS(w)->b12;
        break;
    case 356:
        *dst = func_0200D884((struct Blk3C *)s40, 10, 0);
        break;
    case 357:
        func_0200DA28((struct Blk3C *)s40);
        func_021CA23C(w);
        *dst = func_021CA234(w);
        if (*dst > 9999)
            *dst = 9999;
        break;
    case 358:
        *dst = func_021CA234(w);
        if (*dst > 9999)
            *dst = 9999;
        break;
    case 359:
        if (func_0200DB44((struct Blk1AC *)s38, s3c) == 0) {
            func_0200DB30((struct Blk1AC *)s38, s3c);
            func_0200DA14((struct Blk3C *)s40);
            func_021CA250((u32)w);
        }
        break;
    case 400:
        if (FLAGS(w)->b9 == 1)
            func_02167B00((u32)w);
        else
            func_02167AB0(w);
        break;
    case 401:
        func_0215897C(h, func_021CB914((void *)x, (u32)w));
        ret = 1;
        break;
    case 402:
        w[0x727] = p1;
        ((struct Obj00335 *)w)->f72A = s28;
        func_02167B24(w[0x727]);
        func_020113D0(a, (int)func_021CB700);
        ret = 1;
        break;
    case 403:
        *(u16 * *)&((struct Obj00335 *)w)->f720 = dst;
        ((struct Obj00335 *)w)->f71C = func_021CD48C((u32)func_02012944((void *)s4c), s30, 2, 2, 4, 0, 2, 0);
        func_020113D0(a, (int)func_021CB754);
        ret = 1;
        break;
    case 404:
        *(u16 * *)&((struct Obj00335 *)w)->f720 = dst;
        ((struct Obj00335 *)w)->f71C = func_021CD48C((u32)func_02012944((void *)s4c), s30, 2, 2, 4, 1, 2, 0);
        ret = 1;
        func_020113D0(a, (int)func_021CB7E8);
        break;
    case 405:
        func_02167BFC((struct Obj *)w, p1, p2);
        func_020113D0(a, (int)func_021CB6DC);
        ret = 1;
        break;
    case 406:
        func_02167CF4(w, p1);
        ((struct Obj00335 *)w)->f72A = s28;
        func_020113D0(a, (int)func_021CB86C);
        ret = 1;
        break;
    case 407:
        *dst = func_02039338();
        break;
    case 408:
        func_02082BCC(w + 0x7a4, 0, 0x24);
        ((struct Obj00335 *)w)->f7A4 = s4c;
        ((struct Obj00335 *)w)->f7C0 = 11;
        func_0215897C(h, func_02014808((char *)x, (int)s30, (u32)ov100_id, (int)data_021BB6A4, (int)(w + 0x7a4), 0, 0));
        ret = 1;
        break;
    case 409:
        switch (((struct Obj00335 *)w)->f7C0) {
        case 11:
            *dst = 0;
            break;
        case 12:
            *dst = 1;
            break;
        case 13:
            *dst = 2;
            break;
        default:
            *dst = 1;
            break;
        }
        break;
    case 410:
        func_0200ED54(func_0200ED48((void *)s48), ((struct Obj00335 *)w)->f73C);
        break;
    case 411:
        *dst = func_021A3190(func_02039338() == 0 ? func_021A30B0(func_02188CB4((void *)s30)) : w[0x749], 0);
        break;
    case 412:
        *dst = func_021A3190(func_02039338() == 0 ? w[0x749] : func_021A30B0(func_02188CB4((void *)s30)), 0);
        break;
    case 413:
        func_0200FB38();
        break;
    case 414:
        func_02012124((struct Ctx *)x, 1);
        break;
    case 415:
        *dst = 0;
        if (func_0200FB24() != 0)
            *dst = 1;
        break;
    case 416: {
        u8 *e;
        *dst = 0;
        e = *(u8 * *)&((struct Obj00335 *)w)->f7CC;
        if (e != NULL && func_0200BA38(e[0x91]) == 1)
            *dst = 1;
        break;
    }
    case 501:
        break;
    }
    return ret;
}





/*
 * Task step: resolves the field's current map object and reports whether its fade has finished.
 *
 * Addresses are Black-image addresses.
 */
int func_021CB6DC(void *task, void *p)
{
    if (func_02167CB4(func_02012ED8(func_020120F4(func_02158F54(func_0215A5F4(p))))) == 1)
        return 1;
    return 0;
}





int func_021CB700(u32 unused, u32 a)
{
    void *t;
    u8 *p;
    void *s;
    u16 *q;

    s = func_0215A5F4((void *)a);
    t = func_020120F4(func_02158F54(s));
    p = func_02012ED8(t);
    q = func_02158FE0(s, t, ((struct Obj12971 *)p)->f72A);
    if (func_0200FB24() != 0) {
        *q = 0;
        return 1;
    }
    if (func_02167B34(p[0x727]) == 1) {
        *q = 1;
        return 1;
    }
    return 0;
}





int func_021CB754(u32 unused, u32 a)
{
    void *s, *h;
    void *t;
    u8 *p;
    int r;
    u32 z;

    t = func_0215A5F4((void *)a);
    func_02158F58((int)t);
    s = func_020120F4(func_02158F54(t));
    h = func_02012EBC(s);
    func_0201296C(s);
    p = func_02012ED8(s);
    z = 0;
    func_0200D884(func_020071CC(h, 0x39), 0, 0);
    func_020071CC(h, 0x3A);
    r = func_021CD688((u8 *)(((struct Obj05095 *)p)->f71C));
    if (r != 0) {
        func_021CD5A4((u32 *)(((struct Obj05095 *)p)->f71C));
        ((struct Obj05095 *)p)->f71C = z;
        switch (r) {
        case 1:
            **(u16 * *)&((struct Obj05095 *)p)->f720 = z;
            return 1;
        case 2:
            **(u16 * *)&((struct Obj05095 *)p)->f720 = 1;
            return 1;
        case 4:
        default:
            **(u16 * *)&((struct Obj05095 *)p)->f720 = 2;
            return 1;
        }
    }
    return z;
}





int func_021CB7E8(u32 unused, u32 a)
{
    void *s, *h;
    void *t;
    u8 *p;
    int r;
    u32 z;

    t = func_0215A5F4((void *)a);
    func_02158F58((int)t);
    s = func_020120F4(func_02158F54(t));
    h = func_02012EBC(s);
    func_0201296C(s);
    p = func_02012ED8(s);
    z = 0;
    func_0200D884(func_020071CC(h, 0x39), 0, 0);
    func_020071CC(h, 0x3A);
    r = func_021CD688((u8 *)(((struct Obj06094 *)p)->f71C));
    if (r != 0) {
        func_021CD5A4((u32 *)(((struct Obj06094 *)p)->f71C));
        ((struct Obj06094 *)p)->f71C = z;
        switch (r) {
        case 1:
            **(u16 * *)&((struct Obj06094 *)p)->f720 = z;
            return 1;
        case 2:
        default:
            **(u16 * *)&((struct Obj06094 *)p)->f720 = 1;
            return 1;
        }
    }
    return z;
}





int func_021CB86C(u32 unused, u32 a)
{
    void *t;
    void *s;
    u8 *p;
    u16 *q;

    s = func_0215A5F4((void *)a);
    t = func_020120F4(func_02158F54(s));
    p = func_02012ED8(t);
    q = func_02158FE0(s, t, ((struct Obj20240 *)p)->f72A);
    if (func_02167D00((struct Obj *)p, q) == 1)
        return 1;
    return 0;
}





/*
 * Task step: closes the message window, optionally resumes the field, then waits for the save to finish.
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 * The caller leaves the owner pointer in r0 for func_02167B18, so the extern
 * keeps one (ignored) parameter.
 *
 * Addresses are Black-image addresses.
 */
int func_021CB8AC(void *task, int *state, Owner **work)
{
    switch (*state) {
    case 0:
        if (func_0203D378() == 1)
            func_0203D7BC(0);
        if ((*work)->flag == 1)
            func_02167B18(*work);
        (*state)++;
        break;
    case 1:
        if (func_0203D378() == 1) {
            if (func_0203D1B4() <= 1) {
                func_0203CEAC(0);
                (*state)++;
            }
        } else {
            func_0203CEAC(0);
            (*state)++;
        }
        break;
    case 2:
        if (func_0203CDBC() == 1)
            return 1;
        break;
    }
    return 0;
}





/*
 * Starts the task 0x021CB8AC with a one-word work area holding the owner.
 *
 * Addresses are Black-image addresses.
 */
void *func_021CB914(void *a, u32 owner)
{
    void *task = func_020122C0(a, 0, (TaskFn)func_021CB8AC, 4);
    *(u32 *)func_020124E8(task) = owner;
    return task;
}





/*
 * Task step: fades out, runs the ov021 sub-screen on the +0xc argument, stores whether it was cancelled at *w[1].
 *
 * Addresses are Black-image addresses.
 */
int func_021CB934(void *task, int *state, Work *w)
{
    func_0215A5F4(w->owner);
    switch (*state) {
    case 0:
        func_0215A684(w->owner, 8);
        (*state)++;
    case 1:
        if (func_0215A690(w->owner) == 1) {
            w->screen = (u32)func_02190BE4((u16 *)func_02188C54(func_0201210C(func_0215A5DC(w->owner))), w->arg);
            (*state)++;
        }
        break;
    case 2:
        switch (func_02190C78((struct Handle *)w->screen)) {
        case 0:
            *w->result = 0;
            (*state)++;
            break;
        case 2:
            break;
        default:
            *w->result = 1;
            (*state)++;
            break;
        }
        break;
    case 3:
        func_021909BC((void *)w->screen);
        return 1;
    }
    return 0;
}





void *func_021CB9BC(void *a, u32 owner, u32 result, u32 arg)
{
    void *task = func_020122C0(a, 0, (TaskFn)func_021CB934, 0x10);
    u32 *w = func_020124E8(task);

    w[0] = owner;
    w[1] = result;
    w[3] = arg;
    return task;
}





/*
 * Spawns the marker objects for mode byte +9: in mode 4 up to five from the
 * 0x3B record list (newest first), otherwise every 0x021DAEBC entry whose
 * threshold equals the step count. The u16 accessor result held in a u32
 * local is what puts it in the top spill slot (a u16 or int local takes the
 * lowest). Unlabelled follower: 0x021CBBA0 (already filed).
 *
 * Addresses are Black-image addresses.
 */
void func_021CB9E4(u8 *p, void *a1, void *a2, void *a3)
{
    int i;
    u16 slot;
    u32 zone;
    u8 kind;
    const Pt *pt;
    u8 *list;
    u32 n;
    u8 *e;
    u16 v;
    void *h;
    u16 cnt;
    const Ent *ent;

    i = 0;
    zone = func_02188C9C(a3);
    slot = 0x80;
    kind = p[9];
    if (kind == 4) {
        pt = d_021DADD0;
        list = (u8 *)func_0200DF58(func_020071CC(func_02012EBC(a1), 0x3B), (int)4);
        n = func_0200DF94((struct Buf3FC *)list);
        if (n != 0) {
            e = list + (n - 1) * 0x22;
            while (n != 0 && i < 5) {
                u32 r = func_0200DFB4((struct SubEnt *)e) % 10;
                if (((Flags_021CB86C *)(e + 0x20))->b1 == 0)
                    v = d_021DAD48[r];
                else
                    v = d_021DAD5C[r];
                h = func_0216CE6C(a2, pt->x, pt->y, i % 4, slot, v, 2, zone);
                func_0216D620((int)h, (u16)(n - 1), 0);
                func_0216D5B4(h, 5);
                e -= 0x22;
                i++;
                slot++;
                pt++;
                n--;
            }
        }
        func_020307B0(list);
        return;
    }
    ent = d_021DAEBC;
    cnt = func_0200DB80(((struct Obj12974 *)p)->f74, kind);
    switch (kind) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        break;
    case 5:
    case 6:
    case 7:
    case 8:
        cnt += 3;
        break;
    }
    while (ent->id != 0xFFFF) {
        if (cnt == d_021DADF8[ent->idx - 1]) {
            h = func_0216CE6C(a2, ent->x, ent->y, i % 4, slot, ent->id, 2, zone);
            func_0216D620((int)h, (u16)i, 0);
            func_0216D620((int)h, (u16)ent->k, 1);
            func_0216D5B4(h, 5);
            if (slot < 0xFF)
                slot++;
        }
        ent++;
        i++;
    }
}





/*
 * Tail call into ov010 with a fixed second argument of 1 (unlabelled start).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CBBA0(u32 a)
{
    return func_0216D63C((char *)a, 1);
}





/*
 * Whether entry idx of the 16-byte table at 0x021DAEBC is available (never for kind 4; unlabelled start).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CBBAC(u8 *p, u32 idx)
{
    const Entry *e = &data_021DAEBC[idx];

    if (p[9] == 4)
        return 0;
    if (e->fe != 0)
        return 1;
    return 0;
}





/*
 * Reads the three halfwords of table entry idx, or the empty triple (0, 0, 4) (unlabelled start).
 *
 * Addresses are Black-image addresses.
 */
void func_021CBBD0(u8 *p, u32 idx, u16 *a, u16 *b, u16 *c)
{
    const Entry *e = &data_021DAEBC[idx];

    if (p[9] == 4) {
        *a = 0;
        *b = 0;
        *c = 4;
        return;
    }
    if (e->fe == 0) {
        *a = 0;
        *b = 0;
        *c = 4;
        return;
    }
    *a = e->fa;
    *b = e->fc;
    *c = e->fe;
}





/*
 * Shows the kind's message (20/21/22) with the +0x10 number capped at 9999 and reports whether it ended with 2 or 3.
 *
 * Addresses are Black-image addresses.
 */
int func_021CBC14(u32 unused, u32 a)
{
    void *t;
    u8 *p;
    int id;
    int v;
    int r;

    t = func_020120F4(func_02158F54(func_0215A5F4((void *)a)));
    p = func_02012ED8(t);
    id = 20;
    v = ((struct Obj12976 *)p)->f10;
    switch (p[9]) {
    case 0:
    case 4:
    case 5:
        break;
    case 1:
    case 6:
        id = 21;
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        id = 22;
        break;
    }
    if (v > 9999)
        v = 9999;
    r = func_0200B6E0(t, 4, id, v, 0, (u16 *)(p + 0x7e8), (u16 *)(p + 0x7ea));
    if (r == 2 || r == 3)
        return 1;
    return 0;
}





/*
 * Maps a kind 0..8 to the message id 20, 21 or 22.
 * Addresses are Black-image addresses.
 */
int func_021CBC94(u32 kind)
{
    int id = 20;

    switch (kind) {
    case 0:
    case 4:
    case 5:
        break;
    case 1:
    case 6:
        id = 21;
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        id = 22;
        break;
    }
    return id;
}





/*
 * Maps the owner's mode 0x43..0x49 to a small index.
 *
 * Addresses are Black-image addresses.
 */
int func_021CBCC4(void *p)
{
    u16 m = func_02188C9C(p);
    int r = 0;

    switch (m) {
    case 0x43:
        r = 0;
        break;
    case 0x44:
        r = 5;
        break;
    case 0x45:
        r = 1;
        break;
    case 0x46:
        r = 6;
        break;
    case 0x47:
        r = 2;
        break;
    case 0x48:
        r = 7;
        break;
    case 0x49:
        r = 4;
        break;
    }
    return r;
}





/*
 * Builds a party list from the selected slots and runs the ov010 summary on it.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CBD08(u8 *p, int a)
{
    void *list = func_0201A920(0x8004);
    void *h = func_021CA210(p);
    int i;
    u32 r;

    func_0201A954(list, p[8]);
    for (i = 0; i < p[8]; i++)
        func_0201A98C(list, func_0201AB28(h, p[0x1e + i]));
    r = (u32)func_021681C8((void *)a, list, p[9], (struct TrainerRec *)(p + 0x88), (struct TrainerRec *)(p + 0x2c8 + ((Sel *)p)->sel * 0x120), p[8]);
    func_020307B0(list);
    return r;
}




/*
 * Unlabelled leaf in ov021 (printed as a `.word` run at 0x021CBD84); the
 * matching byte at 0x021CBD8C is the pool word 0x0000074C.  Six-byte
 * accessor reached from ov010's func_0216CAD4 across the overlay pair.
 */
void *func_021CBD84(void *a)
{
    return (char *)a + 0x74c;
}





static inline u16 RandInRange(void *ctx, u32 tbl, u32 round)
{
    u16 span = ((const Range *)(tbl + round * 4))->hi - ((const Range *)(tbl + round * 4))->lo + 1;
    return func_021CBF98(ctx) % span + ((const Range *)(tbl + round * 4))->lo;
}





/*
 * Picks a battle-subway trainer id: the fixed boss ids on the boss round, otherwise a random id from the per-round range table of the line (normal or super, early or late stages).
 *
 * Each table arm calls the random-range helper with the table address cast to
 * an integer. A shared `const Range *tbl` local is a named variable and takes
 * the first callee-saved register (r4) ahead of the scaled index and the span;
 * per-arm calls leave the base as a short-lived load that colours after them
 * (r6, with round*4 in r4 and span in r5), and the arms' identical tails are
 * cross-jumped into one block. The integer base keeps `tbl + off` then `+2`
 * for hi instead of folding the field offset into a second pool word
 * (d_X + 2), and loads the base before the index shift. 0x0209C0A4 is
 * _s32_div_f, so the u16 % u16 modulo is signed (int promotion).
 *
 * Addresses are Black-image addresses.
 */
u16 func_021CBD90(void *ctx, u32 round, u32 stage, u32 line, u8 alt)
{
    int super;
    int boss;
    u16 id;

    id = 0;
    super = 0;
    boss = -1;

    switch (line) {
    case 5:
    case 6:
    case 7:
    case 8:
        super = 1;
        break;
    }

    if (stage == 6) {
        if (!super) {
            if (round == 2)
                boss = 0;
        } else {
            if (round == 6)
                boss = 1;
        }
    }

    if (boss != -1) {
        switch (line) {
        case 0:
        case 5:
            if (boss == 0)
                id = 0x132;
            else if (boss == 1)
                id = 0x133;
            break;
        case 1:
        case 6:
            if (boss == 0)
                id = 0x134;
            else if (boss == 1)
                id = 0x135;
            break;
        case 2:
        case 3:
        case 7:
        case 8:
            if (boss == 0) {
                if (alt == 0)
                    id = 0x137;
                else
                    id = 0x136;
            } else if (boss == 1) {
                if (alt == 0)
                    id = 0x139;
                else
                    id = 0x138;
            }
            break;
        }
    } else if (!super) {
        if (round >= 3)
            goto end;
        if (stage < 6) {
            id = RandInRange(ctx, (u32)d_021DB3D8, round);
            goto end;
        }
        if (round >= 2)
            goto end;
        id = RandInRange(ctx, (u32)d_021DB3D0, round);
    } else {
        if (round >= 4)
            goto rnd;
        if (stage < 6) {
            id = RandInRange(ctx, (u32)d_021DB3E4, round);
            goto end;
        }
        id = RandInRange(ctx, (u32)d_021DB3F4, round);
        goto end;
rnd:
        id = func_021CBF98(ctx) % 100 + 200;
    }
end:
    return id;
}





/*
 * Forwarder into ov010 that drops the first argument and returns its byte result.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021CBED8(u8 *p, u8 *list, u16 v, u8 n, u16 *a, u16 *b, u8 *e, u16 id)
{
    return func_02168878(list, v, n, a, b, e, id);
}





/*
 * Maps a value to a bracket 3..31 in steps of 20.
 * Addresses are Black-image addresses.
 */
u8 func_021CBEFC(u32 v)
{
    if (v < 100)
        return 3;
    if (v < 120)
        return 6;
    if (v < 140)
        return 9;
    if (v < 160)
        return 12;
    if (v < 180)
        return 15;
    if (v < 200)
        return 18;
    if (v < 220)
        return 21;
    return 31;
}





/*
 * Builds the two battle-subway opponent mons at +0x30 of the party block from a trainer record.
 *
 * Addresses are Black-image addresses.
 */
void func_021CBF38(void *unused, u8 *party, u16 id, int useItem, TrainerRec *rec, u16 heap)
{
    u8 iv;
    void *buf;
    int i;

    buf = func_021688BC(party, id, heap);
    iv = func_021CBEFC(id);

    for (i = 0; i < 2; i++)
        func_021684E8((struct BattleMon *)((BattleMon *)(party + 0x30) + i), rec->member[i], rec->otId, rec->pid[i], iv, i, useItem, heap);
    func_020307B0(buf);
}





/*
 * A 16-bit random value: the arm9 random source scaled down by 0xFFFF.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021CBF98(void *ctx)
{
    return func_020056EC(0xffffffff) / 0xffff;
}
