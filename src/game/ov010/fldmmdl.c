/*
 * file:     fldmmdl.c
 * unit:     yes
 * function: func_0216BF38, func_0216BF74, func_0216BF9C, func_0216BFD4, func_0216C028, func_0216C0A4, func_0216C0C0, func_0216C0D4, func_0216C0E4, func_0216C0E8, func_0216C204, func_0216C270, func_0216C280, func_0216C2A4, func_0216C2FC, func_0216C44C, func_0216C484, func_0216C538, func_0216C640, func_0216C680, func_0216C6E8, func_0216C7FC, func_0216C860, func_0216C888, func_0216C8B0, func_0216C8CC, func_0216C978, func_0216C9CC, func_0216C9F4, func_0216CAA8, func_0216CAD4, func_0216CAF4, func_0216CB48, func_0216CC30, func_0216CC40, func_0216CC58, func_0216CCB0, func_0216CCCC, func_0216CCDC, func_0216CD30, func_0216CD50, func_0216CD64, func_0216CD78, func_0216CD88, func_0216CDB8, func_0216CDC4, func_0216CE60, func_0216CE6C, func_0216CEAC, func_0216CEE4, func_0216CF2C, func_0216CF6C, func_0216CFC4, func_0216D02C, func_0216D040, func_0216D0E8, func_0216D0F8, func_0216D1C8, func_0216D208, func_0216D230, func_0216D244, func_0216D268, func_0216D28C, func_0216D2AC, func_0216D2F8, func_0216D38C, func_0216D3A8, func_0216D3B4, func_0216D3CC, func_0216D410, func_0216D438, func_0216D454, func_0216D480, func_0216D4B4, func_0216D4D4, func_0216D4DC, func_0216D4E4, func_0216D4F0, func_0216D4F4, func_0216D4F8, func_0216D4FC, func_0216D508, func_0216D514, func_0216D518, func_0216D51C, func_0216D520, func_0216D524, func_0216D528, func_0216D52C, func_0216D530, func_0216D534, func_0216D538, func_0216D548, func_0216D550, func_0216D55C, func_0216D564, func_0216D568, func_0216D570, func_0216D57C, func_0216D584, func_0216D588, func_0216D58C, func_0216D590, func_0216D594, func_0216D598, func_0216D59C, func_0216D5A0, func_0216D5A4, func_0216D5A8, func_0216D5AC, func_0216D5B0, func_0216D5B4, func_0216D5B8, func_0216D5BC, func_0216D5D4, func_0216D5D8, func_0216D5E0, func_0216D5F8, func_0216D5FC, func_0216D600, func_0216D608, func_0216D60C, func_0216D620, func_0216D63C, func_0216D65C, func_0216D660, func_0216D668, func_0216D66C, func_0216D674, func_0216D678, func_0216D67C, func_0216D684, func_0216D69C, func_0216D6A0, func_0216D6B8, func_0216D6BC, func_0216D6D4, func_0216D6D8, func_0216D6F0, func_0216D6F4, func_0216D708, func_0216D71C, func_0216D730, func_0216D744, func_0216D758, func_0216D76C, func_0216D780, func_0216D794, func_0216D7A8, func_0216D7C0, func_0216D7C4, func_0216D7C8, func_0216D7CC, func_0216D7D4, func_0216D7D8, func_0216D7DC, func_0216D7E0, func_0216D7E4, func_0216D7E8, func_0216D7F0, func_0216D7F4, func_0216D7F8, func_0216D800, func_0216D804, func_0216D80C, func_0216D810, func_0216D818, func_0216D81C, func_0216D824, func_0216D828, func_0216D83C, func_0216D844, func_0216D848, func_0216D854, func_0216D85C, func_0216D860, func_0216D86C, func_0216D874, func_0216D87C, func_0216D888, func_0216D88C, func_0216D89C, func_0216D8AC, func_0216D8B0, func_0216D8C0, func_0216D8D0, func_0216D8E0, func_0216D8F0, func_0216D900, func_0216D910, func_0216D91C, func_0216D924, func_0216D92C, func_0216D948, func_0216D95C, func_0216D974, func_0216D98C, func_0216D9A0, func_0216D9E4, func_0216DA20, func_0216DA30, func_0216DA44, func_0216DA50, func_0216DA5C, func_0216DA70, func_0216DA7C, func_0216DA88, func_0216DA94, func_0216DAA0, func_0216DAB4, func_0216DAC8, func_0216DAE0, func_0216DAF8, func_0216DB04, func_0216DB10, func_0216DB24, func_0216DB4C, func_0216DB68, func_0216DB80, func_0216DB98, func_0216DBB4, func_0216DBCC, func_0216DBE8, func_0216DC00, func_0216DC18, func_0216DC34, func_0216DC4C, func_0216DC64, func_0216DC80, func_0216DC98, func_0216DCB4, func_0216DCCC, func_0216DCE8, func_0216DD04, func_0216DD1C, func_0216DD60, func_0216DDC0, func_0216DDDC, func_0216DE54, func_0216DE94, func_0216DEE0, func_0216DEEC, func_0216DF1C, func_0216DF64, func_0216DFAC, func_0216DFC4, func_0216E014, func_0216E084, func_0216E0AC, func_0216E0E8, func_0216E114, func_0216E160, func_0216E174, func_0216E180, func_0216E190, func_0216E1A4, func_0216E1C4, func_0216E204, func_0216E280, func_0216E290, func_0216E29C, func_0216E2AC, func_0216E2E0, func_0216E2E8, func_0216E39C, func_0216E3C4, func_0216E3C8, func_0216E3CC, func_0216E3D0, func_0216E3D8, func_0216E400, func_0216E40C, func_0216E418, func_0216E42C, func_0216E434, func_0216E464, func_0216E468, func_0216E46C, func_0216E470
 * address:  0x0216BF38
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
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0200D468  0x0200D468  thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200C38C 0x0200C38C thumb
 *   d_02172508 0x02172508 data a4
 *   func_0200C39C 0x0200C39C thumb
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045838  0x02045838  arm
 *   d_02172A60     0x02172A60  data  ov010  a1
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02045808  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0218FEA4  0x0218FEA4  thumb  ov021
 *   func_0218FE78  0x0218FE78  thumb  ov021
 *   func_0218FF00  0x0218FF00  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb
 *   func_0218FE98  0x0218FE98  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_020114D0  0x020114D0  thumb
 *   func_02006148  0x02006148  thumb
 *   func_0200616C  0x0200616C  thumb
 *   func_02011610  0x02011610  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE480  0x021BE480  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_02011590  0x02011590  thumb
 *   func_02011558  0x02011558  thumb
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_021854B0  0x021854B0  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0201235C  0x0201235C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_0218FE80  0x0218FE80  thumb  ov021
 *   func_0218FEA0  0x0218FEA0  thumb  ov021
 *   d_02172528     0x02172528  data  ov010  a4
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_021F3714  0x021F3714  thumb  ov050
 *   func_021F37B8  0x021F37B8  thumb  ov050
 *   func_021F3758  0x021F3758  thumb  ov050
 *   func_021F3808  0x021F3808  thumb  ov050
 *   func_021F3744  0x021F3744  thumb  ov050
 *   func_021F3788  0x021F3788  thumb  ov050
 *   func_021BE92C  0x021BE92C  thumb
 *   func_021D2D50  0x021D2D50  thumb
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_020061F8  0x020061F8  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02014910  0x02014910  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012934  0x02012934  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_0201A354  0x0201A354  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0200B400  0x0200B400  thumb
 *   func_021CBD08  0x021CBD08  thumb  ov021
 *   func_0216E8CC  0x0216E8CC  thumb  ov010
 *   func_02191388  0x02191388  thumb  ov021
 *   func_021914CC  0x021914CC  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_021912D8  0x021912D8  thumb  ov021
 *   func_021912F8  0x021912F8  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   sub_02045B38   0x02045B38  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0202435C  0x0202435C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_021B09D8  0x021B09D8  thumb
 *   func_021B09EC  0x021B09EC  thumb
 *   func_0219129C  0x0219129C  thumb  ov021
 *   func_02012EFC  0x02012EFC  thumb
 *   func_0200DF40  0x0200DF40  thumb
 *   func_0200DF4C  0x0200DF4C  thumb
 *   func_020146F8  0x020146F8  thumb
 *   id_00000045    0x00000045  data  a1
 *   d_021BA650     0x021BA650  data  a4 ov069
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02031324  0x02031324  arm
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02031330  0x02031330  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_0203A574  0x0203A574  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D594  0x0203D594  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0203D5A0  0x0203D5A0  arm
 *   func_02031348  0x02031348  arm
 *   func_0203A5E4  0x0203A5E4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   id_0000005D    0x0000005D  data  a1
 *   d_021F03C4     0x021F03C4  data  a4 ov093
 *   d_021EFDAC     0x021EFDAC  data  a4 ov026
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   d_02172548     0x02172548  data  ov010  a4
 *   func_02161824  0x02161824  thumb  ov010
 *   func_02029BCC  0x02029BCC  thumb
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AAABC  0x021AAABC  thumb  ov021
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF498  0x021CF498  thumb  ov021
 *   func_02029C00  0x02029C00  thumb
 *   func_02029CC0  0x02029CC0  thumb
 *   func_021CBD84   0x021CBD84  thumb  ov021
 *   sub_020122C0   0x020122C0  thumb
 *   sub_020124E8   0x020124E8  thumb
 *   func_021B0A40  0x021B0A40  thumb  ov021
 *   func_020071CC  0x020071CC  thumb
 *   func_0200DF58  0x0200DF58  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   d_02172B48     0x02172B48  data  ov010  a1
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02030DA4  0x02030DA4  arm
 *   func_02049238  0x02049238  arm
 *   func_02197C4C  0x02197C4C  thumb
 *   func_02030D28  0x02030D28  arm
 *   func_0219C5FC  0x0219C5FC  thumb
 *   func_0219C624  0x0219C624  thumb
 *   func_0219C630  0x0219C630  thumb
 *   func_02087A3C  0x02087A3C  arm
 *   func_0216E51C  0x0216E51C  thumb  ov010
 *   func_021642F8 0x021642F8 thumb ov010
 *   func_02164304 0x02164304 thumb ov010
 *   func_0216E544  0x0216E544  thumb  ov010
 *   func_02163010  0x02163010  thumb  ov010
 *   func_0219D6B8  0x0219D6B8  thumb
 *   func_02163028   0x02163028  thumb  ov010
 *   func_0219D6CC   0x0219D6CC  thumb
 *   func_02197C78  0x02197C78  thumb
 *   func_02163C04  0x02163C04  thumb  ov010
 *   func_0209C054  0x0209C054  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_02048F4C  0x02048F4C  arm
 *   func_0200F128 0x0200F128 thumb
 *   func_0204944C 0x0204944C arm
 *   func_020143CC 0x020143CC thumb
 *   d_021D5E04  0x021D5E04  data  ov021  a4
 *   d_021D770C  0x021D770C  data  ov021  a4
 *   func_020142E8  0x020142E8  thumb
 */
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj03544.h"
#include "../../matched/include/Obj02352.h"
#include "../../matched/include/Obj17766.h"
#include "../../matched/include/Obj01029.h"
#include "../../matched/include/Obj17767.h"
#include "../../matched/include/Obj17768.h"
#include "../../matched/include/Obj05905.h"
#include "../../matched/include/Obj02353.h"
#include "../../matched/include/Obj12397.h"
#include "../../matched/include/Obj12055.h"
#include "../../matched/include/Obj17769.h"
#include "../../matched/include/Obj07205.h"
#include "../../matched/include/Obj09165.h"
#include "../../matched/include/Obj04949.h"
#include "../../matched/include/Obj12056.h"
#include "../../matched/include/Obj02669.h"
#include "../../matched/include/Obj09166.h"
#include "../../matched/include/Obj17770.h"
#include "../../matched/include/Obj01464.h"
#include "../../matched/include/Obj17771.h"
#include "../../matched/include/Obj19116.h"
#include "../../matched/include/Obj19117.h"
#include "../../matched/include/Obj00113.h"
#include "../../matched/include/Obj02051.h"
#include "../../matched/include/Obj19118.h"
#include "../../matched/include/Obj09310.h"
#include "../../matched/include/Obj19119.h"
#include "../../matched/include/Obj17772.h"
#include "../../matched/include/Obj17773.h"
#include "../../matched/include/Obj12057.h"
#include "../../matched/include/Obj17774.h"
#include "../../matched/include/Obj17775.h"
#include "../../matched/include/Obj17776.h"
#include "../../matched/include/Obj17777.h"
#include "../../matched/include/Obj17778.h"
#include "../../matched/include/Obj17779.h"
#include "../../matched/include/Obj17780.h"
#include "../../matched/include/Obj17781.h"
#include "../../matched/include/Obj17782.h"
#include "../../matched/include/Obj19121.h"
#include "../../matched/include/Obj17783.h"
#include "../../matched/include/Obj17784.h"
#include "../../matched/include/Obj17785.h"
#include "../../matched/include/Obj17786.h"
#include "../../matched/include/Obj19122.h"
#include "../../matched/include/Obj17788.h"
#include "../../matched/include/Obj17789.h"
#include "../../matched/include/Obj17790.h"
#include "../../matched/include/Obj19125.h"
#include "../../matched/include/Obj17791.h"
#include "../../matched/include/Obj17792.h"
#include "../../matched/include/Obj17793.h"
#include "../../matched/include/Obj17794.h"
#include "../../matched/include/Obj17795.h"
#include "../../matched/include/Obj17796.h"
#include "../../matched/include/Obj17797.h"
#include "../../matched/include/Obj17798.h"
#include "../../matched/include/Obj17799.h"
#include "../../matched/include/Obj17800.h"
#include "../../matched/include/Obj17801.h"
#include "../../matched/include/Obj17802.h"
#include "../../matched/include/Obj17803.h"
#include "../../matched/include/Obj17804.h"
#include "../../matched/include/Obj17805.h"
#include "../../matched/include/Obj17806.h"
#include "../../matched/include/Obj17807.h"
#include "../../matched/include/Obj19126.h"
#include "../../matched/include/Obj17808.h"
#include "../../matched/include/Obj17809.h"
#include "../../matched/include/Obj17810.h"
#include "../../matched/include/Obj17811.h"
#include "../../matched/include/Obj17812.h"
#include "../../matched/include/Obj17813.h"
#include "../../matched/include/Obj19127.h"
#include "../../matched/include/Obj17814.h"
#include "../../matched/include/Obj17816.h"
#include "../../matched/include/Obj12058.h"
#include "../../matched/include/Obj19128.h"
#include "../../matched/include/Obj17824.h"
#include "../../matched/include/Obj17825.h"
#include "../../matched/include/Obj17826.h"
#include "../../matched/include/Obj17827.h"
#include "../../matched/include/Obj17828.h"
#include "../../matched/include/Obj17829.h"
#include "../../matched/include/Obj17830.h"
#include "../../matched/include/Obj17831.h"
#include "../../matched/include/Obj17832.h"
#include "../../matched/include/Obj17833.h"
#include "../../matched/include/Obj17834.h"
#include "../../matched/include/Obj17835.h"
#include "../../matched/include/Obj17836.h"
#include "../../matched/include/Obj17837.h"
#include "../../matched/include/Obj17838.h"
#include "../../matched/include/Obj17839.h"
#include "../../matched/include/Obj17840.h"
#include "../../matched/include/Obj17841.h"
#include "../../matched/include/Obj17842.h"
#include "../../matched/include/Obj17843.h"
#include "../../matched/include/Obj17844.h"
#include "../../matched/include/Obj19129.h"
#include "../../matched/include/Obj17845.h"
#include "../../matched/include/Obj17846.h"
#include "../../matched/include/Obj19130.h"
#include "../../matched/include/Obj17847.h"
#include "../../matched/include/Obj17848.h"
#include "../../matched/include/Obj19131.h"
#include "../../matched/include/Obj17849.h"
#include "../../matched/include/Obj17850.h"
#include "../../matched/include/Obj17851.h"
#include "../../matched/include/Obj09334.h"
#include "../../matched/include/Obj17852.h"
#include "../../matched/include/Obj19133.h"
#include "../../matched/include/Obj17853.h"
#include "../../matched/include/Obj17854.h"
#include "../../matched/include/Obj09167.h"
#include "../../matched/include/Obj09168.h"
#include "../../matched/include/Obj05908.h"
#include "../../matched/include/Obj17855.h"
#include "../../matched/include/Obj19134.h"
#include "../../matched/include/Obj12404.h"
#include "../../matched/include/Obj12405.h"
#include "../../matched/include/Obj19137.h"

struct Big;
struct Blk38;
struct Blk34;
struct Sub0200852CObj;
struct U16Vec;
struct Evt;
struct IcaAnime;
struct S0201235C;
struct Rec12;
struct Obj00020;
struct Desc;
struct Obj;
struct Work_0216C2FC;
struct BigObj;
struct Ctx;
struct Blk37;
struct S;
struct Actor;
struct MsgBank;
struct Rec;
struct Ent;
struct RecSlot;
struct S020314B8;
struct S020315D4;
struct Entry;
struct Sub020071CCCtrl;
struct Q;
struct Buf3FC;
struct Rec94;
struct Rec_0216D9A0;
struct ArcFile;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32_0216BF38;

typedef int s32_0216C0E8;

typedef s32_0216C0E8 fx32_0216BF38;

typedef struct VecFx32 {
    fx32_0216BF38 x;
    fx32_0216BF38 y;
    fx32_0216BF38 z;
} VecFx32;

typedef struct Pos {
    u32 f00;
    u32 f04;
    u32 f08;
} Pos;

typedef struct Work_0216C0E8 {
    void *sys;          /* 0x00 */
    void *field;        /* 0x04 */
    void *f08;          /* 0x08 */
    void *f0c;          /* 0x0C */
    void *anim;         /* 0x10 */
    u8 pad14[4];
    u8 f18[0x60 - 0x18];/* 0x18 */
    void *f60;          /* 0x60 */
} Work_0216C0E8;

typedef struct B32 { int w[8]; } B32;



typedef signed int     s32_0216C270;

typedef int s32_0216C2A4;

typedef s32_0216C2A4 fx32_0216C2A4;



typedef int s32_0216C2FC;

typedef s32_0216C2FC fx32_0216C2FC;

typedef struct VecFx32_0216C2FC {
    fx32_0216C2FC x;
    fx32_0216C2FC y;
    fx32_0216C2FC z;
} VecFx32_0216C2FC;

typedef struct Param {
    u16 f00;            /* 0x00 */
    u16 f02;            /* 0x02 */
    u16 f04;            /* 0x04 */
    u16 f06;            /* 0x06 */
    u16 f08;            /* 0x08 */
    u16 f0a;            /* 0x0A */
    u16 f0c;            /* 0x0C */
    u8 f0e;             /* 0x0E */
    u8 f0f;             /* 0x0F */
    u32 f10;            /* 0x10 */
    u32 f14;            /* 0x14 */
} Param;

typedef struct Work_0216C2FC {
    u16 f00;            /* 0x00 */
    void *sys;          /* 0x04 */
    void *field;        /* 0x08 */
    void *f0c;          /* 0x0C */
    void *anim;         /* 0x10 */
} Work_0216C2FC;

typedef struct Work_0216CB48 {
    void   *owner;      /* 0x00 */
    u32     field04;    /* 0x04 */
    VecFx32_0216C2FC pos;        /* 0x08 */
    u32     field14;    /* 0x14 */
    void   *field18;    /* 0x18 */
} Work_0216CB48;

typedef struct Work_0216C44C Work_0216C44C;

typedef struct SummaryArgs {
    void *party;        /* 0x08 */
    u32 f04;
    void *p;            /* 0x10 */
    u8 f0c;             /* 0x14 */
    u8 f0d;             /* 0x15 */
    u8 count;           /* 0x16 */
    u8 pad0f;
    u8 f10;             /* 0x18 */
    u8 pad11[7];
    void *f18;          /* 0x20 */
    u8 pad1c[0xC];
} SummaryArgs;

typedef struct PartyArgs {
    void *party;        /* 0x30 */
    u8 pad04[0x10];
    void *f14;          /* 0x44 */
    u8 pad18[0x1C];
    u32 f34;            /* 0x64 */
    u32 f38;            /* 0x68 */
    u8 pad3c[0x5C];
} PartyArgs;

typedef struct PartyTaskWork {
    void *sys;          /* 0x00 */
    void *q;            /* 0x04 */
    SummaryArgs sum;    /* 0x08 */
    PartyArgs pa;       /* 0x30 */
    void *outC8;        /* 0xC8 */
    void *outCC;        /* 0xCC */
    void *outD0;        /* 0xD0 */
    u8 padD4[4];
} PartyTaskWork;

typedef struct PartyCaller {
    u8 pad00[9];
    u8 kind;            /* 0x009 */
    u8 pad0A[0x72];
    u8 f7c[6];          /* 0x07C */
    u16 f82;            /* 0x082 */
    u16 f84;            /* 0x084 */
    u8 pad86[0x7C8 - 0x86];
    void *party;        /* 0x7C8 */
} PartyCaller;

typedef struct S { char p0[9]; unsigned char k; char p1[0x7CC - 10]; int f; } S;

typedef struct Spawn {
    void *sys;          /* 0x00 */
    u8 pad04[4];
    VecFx32_0216C2FC pos;        /* 0x08 */
    void *obj;          /* 0x14 */
    void *name;         /* 0x18 */
    u16 id;             /* 0x1C */
} Spawn;

typedef u32 (*TaskFn)(void *task, u32 *state, Spawn *work);

typedef signed int     s32_0216C8CC;

typedef int            s32_0216CB48;

typedef s32_0216CB48            fx32_0216C8CC;

typedef signed int     s32_0216CC40;

typedef struct Obj {
    char pad[0x44];
    void *f44;
} Obj;

typedef struct {
    u32 w[9];
} Rec;

typedef struct {
    u16 a, p0;
    u16 b, p1;
    u16 c, p2;
} In3;

typedef struct { u16 f, g; } W2;

typedef struct {
    u16 a, b, c;
    u16 pad0[3];
    u16 d;
    u16 pad1[5];
    u32 e;
    W2 w;
    u32 pad2;
} Big;

typedef struct {
    u16 id;
    u16 pad0[3];
    u16 key;
    u16 pad1[13];
} Ent;

typedef signed char s8;

typedef signed short   s16;

typedef int            s32;

typedef s32            fx32_0216CEE4;

typedef struct Src {
    u16  x;
    u16  y;
    fx32_0216CEE4 z;
} Src;

typedef signed short   s16_0216D6F0;

typedef int (*Callback)(void *, unsigned int);

typedef signed short   s16_0216D7C0;

typedef signed short   s16_0216D7C4;

typedef signed short   s16_0216D7C8;

typedef signed short   s16_0216D7D4;

typedef signed short   s16_0216D7D8;

typedef signed short   s16_0216D7DC;

typedef signed short   s16_0216D7E0;

typedef signed short   s16_0216D7E4;

typedef signed short   s16_0216D7E8;

typedef signed short   s16_0216D7F0;

typedef signed short   s16_0216D7F4;

typedef signed short   s16_0216D7F8;

typedef signed short   s16_0216D800;

typedef signed short   s16_0216D804;

typedef signed short   s16_0216D80C;

typedef signed short   s16_0216D810;

typedef signed short   s16_0216D818;

typedef signed short   s16_0216D81C;

typedef signed short   s16_0216D824;

typedef short s16_0216D828;

typedef struct { s16_0216D828 x, y, z; } Vec3s;

typedef signed short   s16_0216D83C;

typedef int s32_0216D60C;

typedef s32_0216D60C fx32_0216D438;

typedef struct Actor {
    u8 pad00[0x44];
    VecFx32_0216C2FC pos;        /* 0x44 */
} Actor;

typedef struct { u32 a, b, c; } Triple;

typedef struct S12 { u32 a, b, c; } S12;

typedef struct { int x, y, z; } Vec;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} Rec12;

typedef signed int     s32_0216D900;

typedef signed short   s16_0216D9A0;

typedef struct Rec_0216D9A0 {
    u8 data[0x100];
} Rec_0216D9A0;

typedef struct Ctx {
    u8 pad[0x18];
    Rec_0216D9A0 *recs;
} Ctx;

typedef struct {
    int n;
    u8 *e[16];
} List;

typedef long long s64;

typedef short s16_0216DEE0;

typedef struct {
    u16 w[14];
} Rec_0216E0E8;

typedef struct Record { u16 fields[14]; } Record;

extern void *func_0215A5E4(void *a0);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200D418(void *sys);
extern unsigned int func_02159B10(void *, void *);
extern unsigned short *func_02159AE8(void *a0, void *a1);
extern u8 func_0200D468(struct Blk38 *p, u32 i);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200C38C(struct Blk34 *p, s32_0216BF38 i, u32 v);
extern u32 func_0200C39C(struct Blk34 *p, s32_0216BF38 i);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern int func_02082BCC(void *, int, int);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern int func_02045808();
extern int func_020307B0(void *);
extern void func_0218FEA4(void *p);
extern void func_0218FE78(void *p, void *q);
extern int func_0218FF00(u32 a);
extern int func_021C6E48(void *p);
extern void func_0218FE98(void *p);
extern u16 func_02188C84(u8 *p);
extern void *func_020114D0(u32 heap, u32 a1, u32 a2);
extern int func_02006148(u32 a0);
extern void func_0200616C(void *arg, int i);
extern u32 func_02011610(struct IcaAnime *anim, struct Rec12 *out);
extern int func_02188D2C(int *);
extern VecFx32 *func_021BE480(void *p, int a, int b);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_021A3044(u8 *p, void *v);
extern u32 func_02011590(struct IcaAnime *p, s32_0216C0E8 v);
extern void func_02011558(struct IcaAnime *p);
extern void *func_021BE8D4(void *, void *, u32, u32);
extern void *func_021854B0(void *p, void *q, u32 id, Pos *pos, u32 flag);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_0201235C(struct S0201235C *o, u32 *out);
extern struct Desc *func_020122C0(void *, void *, void *, unsigned int);
extern void *func_020124E8(struct Obj *p);
extern void *func_02188C58(void *p);
extern unsigned int func_02188D38(u8 *p);
extern void *func_0218FE80(void *a);
extern void func_0218FEA0(u8 *p, unsigned int v);
extern void func_02163E58(void *a, VecFx32_0216C2FC *v, fx32_0216C2FC *y);
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern void func_021F3714(int *p);
extern void func_021F37B8(int a);
extern int func_021F3758(int *p);
extern int func_021F3808(int *p);
extern void func_021F3744(int *p);
extern void func_021F3788(int *p);
extern void *func_021BE92C(void *, void *, u32, u32, u32, u32, u32);
extern void *func_021D2D50(void *sys, Param *p);
extern void *func_021A3074(u8 *p);
extern void func_020061F8(int i);
extern void func_020061E4(u32 se);
extern int func_020144DC(int, int);
extern void *func_02014910(char *a0, int a1, int a2, int a3);
extern void *func_020145CC(void *a0);
extern void func_02082D44(void *, void *, int);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void *func_0201A354(int a, int b);
extern void *func_0200CA1C(void *p);
extern u32 func_0201AA18(void *p);
extern u32 func_0200CA38(struct Blk37 *p);
extern void func_0200B400(u32 heap);
extern u32 func_021CBD08(u8 *p, int a);
extern int func_0216E8CC(int, int, int);
extern int func_02191388();
extern void func_021914CC(struct S *s);
extern u32 func_020362DC(void);
extern int func_021912D8(u32);
extern int func_021912F8();
extern u32 func_02188C54(u8 *p);
extern struct MsgBank *sub_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_02045C04(struct Rec *rec);
extern void *func_0202435C(void *slots, unsigned int heap);
extern u32 func_02012964(const struct BigObj *p);
extern u32 func_0218EC2C(u8 *p);
extern void func_021B09D8(VecFx32_0216C2FC *, VecFx32_0216C2FC *, void *, void *, void *);
extern void func_021B09EC(int, int *, int *);
extern struct Ent *func_0219129C(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g);
extern void *func_02012EFC(void **p);
extern int func_0200DF40(struct RecSlot *p);
extern u8 func_0200DF4C(struct RecSlot *p);
extern void *func_020146F8(char *a0, int a1, int a2, int a3, int a4);
extern void func_0203064C(unsigned int src, unsigned int dst, unsigned int size);
extern int func_0203159C();
extern void *func_02031324(int a0);
extern void func_0203133C(struct S020314B8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int);
extern unsigned int func_02031330(void *p);
extern int func_02034AC4(s32_0216C8CC handle);
extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);
extern struct Entry *func_020399A8(void);
extern void func_0203D594(int, int);
extern u32 func_0200FB24(void);
extern int func_0203D5A0(int, int);
extern void func_02031348(int, int, char *, int);
extern void func_0203A5E4(u32 key);
extern void func_02034A5C(s32_0216C8CC handle);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx *p);
extern void *func_02161824(void *a, void *b);
extern void *func_02029BCC(void *a, u32 b);
extern u32 func_02188CE8(u8 *p);
extern void func_021AAABC(int);
extern int func_02189A08(unsigned char *p);
extern void func_021CF498(struct Ctx *c, u32 x, int idx);
extern void *func_02029C00(void *a);
extern void *func_02029CC0(void *a);
extern void *func_021CBD84(void *a);
extern struct Desc *sub_020122C0(void *owner, void *a, void *b, u32 size);
extern void *sub_020124E8(struct Obj *p);
extern int func_021B0A40(u32 a, struct Q *q);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern struct Buf3FC *func_0200DF58(struct RecSlot *p, u32 heap);
extern void *func_0215A5DC(void *a0);
extern u8 *func_02012EC4(struct Big *p);
extern s32_0216CC40 *func_0200B3A4(struct Rec94 *p, u32 b);
extern u32 func_02030CB0(u32 idx);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void *func_020490F4(u32, u32);
extern int func_02030DA4();
extern void func_02049238(void *arc);
extern int func_02197C4C();
extern int func_02030D28();
extern int func_0219C5FC();
extern int func_0219C624();
extern int func_0219C630();
extern int func_02087A3C();
extern int func_0216E51C();
extern void func_021642F8(void *a0);
extern void func_02164304(int, u8 *);
extern void func_0216E544(void *obj, VecFx32_0216C2FC *out);
extern int func_02163010();
extern int func_0219D6B8();
extern void func_02163028(void *a);
extern void func_0219D6CC(void *);
extern int func_02197C78();
extern int func_02163C04(int a, int x, int y, int flag);
extern int func_02030DA8(int owner, int fn, int arg, int n);
extern int func_02030EAC();
extern int func_02163F10(int a0);
extern int func_02164010(int a);
void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern u32 func_0200F128(u32 id);
extern void func_0204944C(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
extern unsigned int func_020143CC(unsigned int, unsigned int);
extern unsigned int func_020142E8(void *bitmap, int id);
int func_0216BF38(int a0, int a1);
void func_0216BF74(void *a, int i, void *b);
int func_0216BF9C(void *a, int i, void *b);
int *func_0216BFD4(unsigned short a0, int a1, short a2, short a3, int s0, int s1, int s2);
int *func_0216C028(unsigned short a0, int a1, int a2, int a3, int s0);
int *func_0216C0A4(unsigned short a, int b, int c, int d, int e, int f, int g, int h);
int func_0216C0C0(int a0);
void func_0216C0D4(int *p, int a1);
int func_0216C0E4(int *p);
int func_0216C0E8(void *evt, u32 *state, Work_0216C0E8 *w);
int func_0216C204(void *a, u8 *b);
int func_0216C270(Work_0216C2FC *w);
void *func_0216C280(void *p);
void func_0216C2A4(Work_0216C2FC *w);
int func_0216C2FC(void *evt, u32 *state, Work_0216C2FC *w);
void *func_0216C44C(void *a,void *b);
int func_0216C484(int a, int *st, int *o);
void *func_0216C538(PartyCaller *c, void *sys, u8 useOwn);
void func_0216C640(S *a, int b, int c);
int func_0216C680(int a, int *st, int *o, u32 a3);
void *func_0216C6E8(u8 *d, void *sys, u32 idx, u16 id, u8 dir);
int func_0216C7FC(int a, int *st, int *o);
void *func_0216C860(void *a);
int func_0216C888(int a0, int a1, int a2);
int func_0216C8B0(void *a, int b, int c, void **d);
int func_0216C8CC(int a, int *st, int *o, int *x);
int func_0216C978(int a, int *st, int *o);
void *func_0216C9CC(void *a,void *b,void *c);
int func_0216C9F4(int a, int *st, int *o);
void *func_0216CAA8(void *a,void *b,void *c,void *d);
void func_0216CAD4(void *a0, void *a1, void *a2);
int func_0216CAF4(int a0, int a1, int a2);
void *func_0216CB48(void *owner, int idx, u8 arg);
int func_0216CC30(int a0, int a1);
int func_0216CC40(void *a);
char *func_0216CC58(int a, int b, int c);
int func_0216CCB0(int a0);
void func_0216CCCC(Obj *o);
void func_0216CCDC(char *a, int b, int c, int d, int e, int f);
void func_0216CD30(u32 *a0);
void func_0216CD50(int a0);
int func_0216CD64(int a0);
int func_0216CD78(int a0);
int func_0216CD88(int a0);
void func_0216CDB8(u8 *p, u32 v, int a2);
u8 *func_0216CDC4(u32 a, Rec *p, u32 b, u32 c);
void *func_0216CE60(int a, int b, int c);
void *func_0216CE6C(void *o, u32 f, u32 g, u32 d, In3 in, u32 x);
void func_0216CEAC(u32 a,u8 *p,u32 b,u32 n,u32 c);
int func_0216CEE4(u32 a, Ent *e, u32 b, int n, u32 c, u32 id);
int func_0216CF2C(int a0);
void func_0216CF6C(u32 x);
void func_0216CFC4(int a0, int a1);
void func_0216D02C(int a, u8 *p);
void func_0216D040(u8 *o, u16 *r, u32 b, u32 c);
void func_0216D0E8(int a, u8 *p, int c);
void func_0216D0F8(void *obj, const u8 *a1);
void func_0216D1C8(u8 *p, u32 a, u32 b);
void func_0216D208(void *p);
int func_0216D230(int a0);
void func_0216D244(u32 v, u8 *p);
int func_0216D268(int a0, int a1);
int func_0216D28C(void *a0);
void func_0216D2AC(u32 x);
void func_0216D2F8(u32 x);
void func_0216D38C(int a0);
void func_0216D3A8(u32 a, u32 b);
int func_0216D3B4(int a0);
int func_0216D3CC(int a0);
void func_0216D410(void *a0, u16 a1);
void func_0216D438(char *a0, u16 a1);
int func_0216D454(int a0, u32 a1, u32 a2, u32 a3);
int func_0216D480(char *p);
void *func_0216D4B4(char *p);
int func_0216D4D4(int a0, int a1);
void func_0216D4DC(void *a0, u32 a1);
u32 *func_0216D4E4(u32 *p, u32 v);
u16 func_0216D4F0(void *p);
u16 func_0216D4F4(void *p);
u32 func_0216D4F8(u8 *p);
int func_0216D4FC(int a0);
int func_0216D508(int a0);
u32 func_0216D514(void *p);
u32 func_0216D518(u8 *p);
void func_0216D51C(u8 *p, u32 v);
u32 func_0216D520(void *p);
void func_0216D524(void *p, void *v);
u32 func_0216D528(u8 *p);
u32 func_0216D52C(void *p);
void *func_0216D530(void *p);
u32 func_0216D534(void *p);
u32 func_0216D538(u8 *p);
unsigned int *func_0216D548(unsigned int *p, unsigned int v);
u32 *func_0216D550(u32 *p, u32 v);
int func_0216D55C(int a0, int a1);
u32 func_0216D564(void *p);
void *func_0216D568(void *p, u32 v);
char *func_0216D570(char *p, u32 v);
u32 func_0216D57C(void *p, u32 v);
int func_0216D584(void *p, u16 v);
u16 func_0216D588(void *p);
void func_0216D58C(void *p, u16 v);
u16 func_0216D590(void *p);
void func_0216D594(void *p, u32 v);
u16 func_0216D598(void *p);
void func_0216D59C(void *p, u16 v);
u16 func_0216D5A0(void *p);
int func_0216D5A4(void *p, u16 v);
u16 func_0216D5A8(u8 *p);
int func_0216D5AC(void *p, u16 v);
u16 func_0216D5B0(u8 *p);
int func_0216D5B4(void *p, u16 v);
u32 func_0216D5B8(void *p);
int func_0216D5BC(void *p);
int func_0216D5D4(void *p);
int func_0216D5D8(int a0, int a1);
void func_0216D5E0(int a0, int a1);
u16 func_0216D5F8(void *p);
u16 func_0216D5FC(void *p);
int func_0216D600(int a0, int a1);
u16 func_0216D608(void *p);
int func_0216D60C(int a0, int a1);
int func_0216D620(int a0, int a1, int a2);
int func_0216D63C(char *a0, int a1);
void func_0216D65C(void *p, short v);
int func_0216D660(void *p);
void func_0216D668(void *p, short v);
int func_0216D66C(void *p);
int func_0216D674(void *p, u16 v);
u16 func_0216D678(void *p);
void *func_0216D67C(void *a0);
void *func_0216D684(int a0, int a1, u32 a2, u32 a3);
void *func_0216D69C(void *p);
void *func_0216D6A0(int a0, int a1);
void *func_0216D6B8(void *p);
void *func_0216D6BC(int a0, int a1, int a2);
void *func_0216D6D4(void *p);
void *func_0216D6D8(int a0, int a1);
void *func_0216D6F0(void *p);
void func_0216D6F4(void *a0);
void func_0216D708(void *a0);
int func_0216D71C(void *a0);
void func_0216D730(void *a0);
void func_0216D744(void *a0);
void func_0216D758(void *a0);
int func_0216D76C(void *a0);
void func_0216D780(void *a0);
void func_0216D794(void *a0);
int func_0216D7A8(void *p, unsigned int v);
void func_0216D7C0(void *p, u16 v);
u16 func_0216D7C4(u8 *p);
void *func_0216D7C8(void *p, u16 v);
void func_0216D7CC(u8 *p);
u16 func_0216D7D4(u8 *p);
void func_0216D7D8(void *p, u32 v);
u32 func_0216D7DC(void *p);
void func_0216D7E0(void *p, u32 v);
u32 func_0216D7E4(void *p);
int func_0216D7E8(void *p);
void func_0216D7F0(void *p, short v);
void func_0216D7F4(void *p, short v);
int func_0216D7F8(void *p);
void func_0216D800(void *p, short v);
int func_0216D804(void *p);
void func_0216D80C(void *p, s16 v);
int func_0216D810(void *p);
void func_0216D818(void *p, s16 v);
int func_0216D81C(void *p);
void func_0216D824(void *p, s16 v);
void func_0216D828(u8 *p, Vec3s *out);
int func_0216D83C(void *p);
void func_0216D844(void *p, short v);
void func_0216D848(char *p, short v);
int func_0216D854(void *p);
void func_0216D85C(void *p, int v);
void func_0216D860(char *p, short v);
int func_0216D86C(void *p);
void func_0216D874(int a0, int a1);
void func_0216D87C(char *p, short v);
void *func_0216D888(void *p);
void func_0216D88C(const struct Actor *a, struct VecFx32_0216C2FC *out);
void func_0216D89C(void *p, const Triple *q);
u32 func_0216D8AC(void *p);
void func_0216D8B0(u8 *p, u8 *q);
void func_0216D8C0(u8 *p, const Vec *v);
void func_0216D8D0(u8 *p, u8 *q);
void func_0216D8E0(u8 *p, Rec12 *src);
void func_0216D8F0(u8 *p, u8 *q);
void func_0216D900(void *p, const Triple *q);
int func_0216D910(int a0);
u8 func_0216D91C(int a0);
u8 func_0216D924(int a0);
void func_0216D92C(u8 *p, s32_0216D900 *q);
int func_0216D948(int a0);
void func_0216D95C(unsigned int *p, unsigned int v, int a2);
void func_0216D974(unsigned int *p, unsigned int v, int a2);
int func_0216D98C(int a0);
void func_0216D9A0(void *map);
u32 *func_0216D9E4(void *c);
int func_0216DA20(void *p, unsigned int v);
int func_0216DA30(int a0);
void func_0216DA44(u32 a);
void func_0216DA50(u8 *p);
int func_0216DA5C(void *a0);
void func_0216DA70(void *a0);
void func_0216DA7C(u8 *p);
void func_0216DA88(void *a0);
void func_0216DA94(void *a0);
int func_0216DAA0(void *a0);
int func_0216DAB4(void *a0);
void func_0216DAC8(unsigned int *p, unsigned int v);
void func_0216DAE0(unsigned int *p, unsigned int v);
void func_0216DAF8(void *a0);
char *func_0216DB04(void *a0);
int func_0216DB10(void *a0);
int func_0216DB24(int a0);
int func_0216DB4C(void *a0, int a1);
int func_0216DB68(void *a0);
void func_0216DB80(unsigned int *p, unsigned int v);
int func_0216DB98(void *a0, int a1);
int func_0216DBB4(void *a0);
int func_0216DBCC(void *a0, u32 a1, int a2);
int func_0216DBE8(void *a0);
int func_0216DC00(void *a0);
int func_0216DC18(void *a0, int a1);
int func_0216DC34(void *a0);
int func_0216DC4C(void *a0);
int func_0216DC64(void *a0, int a1);
int func_0216DC80(void *a0);
int func_0216DC98(void *a0, int a1);
int func_0216DCB4(void *a0);
int func_0216DCCC(void *a0, int a1);
int func_0216DCE8(void *a0, int a1);
int func_0216DD04(void *a0);
int func_0216DD1C(struct Ctx *c, struct Rec_0216D9A0 **out, u32 *iter);
int func_0216DD60(u32 x, u32 b, u32 c, u32 d, List *out);
void *func_0216DDC0(u32 a, u32 b, u32 c, u32 d);
u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);
void *func_0216DE54(void *map, u32 kind);
void *func_0216DE94(void *map, u32 id);
void *func_0216DEE0(void *a0);
int func_0216DEEC(int a0);
void func_0216DF1C(u32 x);
void func_0216DF64(u8 *o, u32 b);
int func_0216DFAC(int a0);
int func_0216DFC4(void *a, u32 id);
void func_0216E014(void *a, int *p, int b);
void func_0216E084(void *a, unsigned int x, unsigned int y, unsigned int z, u16 k);
void func_0216E0AC(void *a0, void *a1);
int func_0216E0E8(int a0, u16 a1);
void func_0216E114(void *obj);
int func_0216E160(int a0);
void func_0216E174(void *a0);
int func_0216E180(void *a0);
void func_0216E190(void *a);
int func_0216E1A4(int a0, int a1);
int func_0216E1C4(int a0, int a1);
void func_0216E204(char *a, u32 v);
void *func_0216E280(int a0, int a1);
int func_0216E290(char *p);
void func_0216E29C(Obj *o, int v);
void func_0216E2AC(void *p, u32 i, Rec_0216E0E8 *out);
u16 func_0216E2E0(void *p);
void func_0216E2E8(const char *ctx, u32 id, Record *out);
void func_0216E39C(const char *ctx, u32 id, u8 *w);
void *func_0216E3C4(void *p);
void *func_0216E3C8(void *p);
u8 *func_0216E3CC(u8 *p);
int func_0216E3D0(int a, int b);
unsigned int func_0216E3D8(unsigned int a, unsigned int id);
u32 func_0216E400(int i);
u32 func_0216E40C(int i);
int func_0216E418(void *a);
unsigned int func_0216E42C(void *bitmap, int id);
u32 func_0216E434(u32 a);
extern const u32 d_02172508[];
extern char d_02172A60[];
extern B32 d_02172528;
extern char d_021BA650[];
extern char id_00000045[];
extern char id_0000005D[];
extern char d_021F03C4[];
extern char d_021EFDAC[];
extern char d_02172548[];
extern char d_02172B48[];
extern u32 d_021D5E04[];
extern u32 d_021D770C[];






int func_0216BF38(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    void *t7;
    void *p;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    p = func_0215A5E4((void *)a0);
loc_0216BF44:
    p = func_02012EBC((struct Big *)p);
loc_0216BF48:
    t7 = func_0200D418(p);
loc_0216BF4C:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0216BF56:
a0 = a0 << 0x18;
t4 = (unsigned)a0 >> 0x18;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = (int)func_02159AE8((void *)a0, (void *)a1); /* int-typed on purpose: pointer local changes codegen */
loc_0216BF62:
t5 = a0 + 0;
a1 = t4 + 0;
    a0 = func_0200D468(t7, a1);
loc_0216BF6C:
*(u16 *)&((struct Obj00005 *)((char *)t5))->f0 = a0;
a0 = 0;
    return a0;}





void func_0216BF74(void *a, int i, void *b) {
    if(i<8) func_0200C38C(a,i,func_02008530(b)^*(const u32 *)((u32)d_02172508+(u32)i*4));
}





/*
 * lever: named second call-result local preserves the original comparison registers.
 */
int func_0216BF9C(void *a, int i, void *b) {
    u32 v; u32 x;
    if(i>=8) return 0;
    v=func_02008530(b);
    x=func_0200C39C(a,i);
    if((x^v)==*(const u32 *)((u32)d_02172508+(u32)i*4)) return 1;
    return 0;
}






/*
 * The heap id is a u16: as an int its entry spill (str r0,[sp,#4]) sinks
 * below the stack-argument setup. func_02045838 takes the flag as its second
 * argument, which is why the image loads it into r1 ahead of the p[8] store.
 */
int *func_0216BFD4(unsigned short a0, int a1, short a2, short a3, int s0, int s1, int s2)
{
    int *p = (int *)func_02030734(a0, 0x2c, 0, d_02172A60, 0x37);
    func_02082BCC(p, 0, 0x2c);
    p[0] = a1;
    p[6] = s0;
    ((struct Obj03544 *)p)->f4 = a2;
    ((struct Obj03544 *)p)->f6 = a3;
    p[10] = s2;
    p[8] = (int)func_020457B0(0xb, a0);
    if (s1)
        func_02045838((struct U16Vec *)p[8], (struct U16Vec *)s1);
    return p;
}






/*
 * The heap id is a u16, as in func_0216BFD4; that keeps its entry spill
 * at the front of the prologue.
 */
int *func_0216C028(unsigned short a0, int a1, int a2, int a3, int s0)
{
    int *p = (int *)func_02030734(a0, 0x2c, 0, d_02172A60, 0x59);
    func_02082BCC(p, 0, 0x2c);
    p[0] = 1;
    p[6] = a2;
    p[2] = a1;
    p[10] = s0;
    if (a1) {
        int t;
        ((struct Obj02352 *)p)->f4 = func_02017E1C((void *)a1, 5, 0);
        t = func_02017E1C((void *)a1, 0x6f, 0);
        ((struct Obj02352 *)p)->f6 = (func_02017E1C((void *)a1, 0x6e, 0) << 8) | t;
    }
    p[8] = (int)func_020457B0(0xb, a0);
    if (a3)
        func_02045838((struct U16Vec *)p[8], (struct U16Vec *)a3);
    return p;
}





int *func_0216C0A4(unsigned short a, int b, int c, int d, int e, int f, int g, int h) {
    int *p;
    p = func_0216C028(a,b,c,d,h);
    p[3]=e; p[4]=f; p[5]=g;
    return p;
}






int func_0216C0C0(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj17766 *)t4)->f20;
    a0 = func_02045808(a0);
loc_0216C0CA:
a0 = t4 + 0;
    a0 = func_020307B0((void *)a0);
loc_0216C0D0:
    return a0;}






void func_0216C0D4(int *p, int a1)
{
    func_02045838((struct U16Vec *)a1, (struct U16Vec *)p[8]);
}





int func_0216C0E4(int *p)
{
    return p[7];
}






/*
 * Eight-state proc of the field event beside func_0216C2FC: run the
 * ov021 camera move, animate the actor to the ground, then push the next
 * screens. First draft.
 */
int func_0216C0E8(void *evt, u32 *state, Work_0216C0E8 *w)
{
    VecFx32 cur;
    VecFx32 v;
    Pos pos;
    void *sys = w->sys;
    void *field = w->field;
    void *f0c = w->f0c;
    void *q;

    switch (*state) {
    case 0:
        func_0218FEA4(w->f60);
        func_0218FE78(w->f08, w->f18);
        func_0218FF00((u32)w->f60);
        (*state)++;
        break;
    case 1:
        if (func_021C6E48(f0c) != 0) {
            func_0218FE98(w->f60);
            (*state)++;
        }
        break;
    case 2:
        w->anim = func_020114D0(func_02188C84(field), 0x9D, 0x18);
        func_0200616C((void *)1953, func_02006148(1953));
        (*state)++;
        break;
    case 3:
        func_02011610(w->anim, (struct Rec12 *)&cur);
        func_021BE480((void *)func_02188D2C(field), 0, 0)->y = cur.y;
        q = func_02188CB4(field);
        func_021A3038(q, &v);
        v.y = cur.y;
        func_021A3044(q, &v);
        if (func_02011590(w->anim, 0x1000) != 0) {
            func_02011558(w->anim);
            (*state)++;
        }
        break;
    case 4:
        func_02012374(evt, func_021BE8D4(sys, field, 0, 0));
        (*state)++;
        break;
    case 5:
        pos.f00 = 0;
        pos.f04 = 0;
        pos.f08 = 0;
        func_02012374(evt, func_021854B0(sys, field, 0x8A, &pos, 1));
        (*state)++;
        break;
    case 6:
        func_0201235C(evt, func_0216C44C(sys, field));
        (*state)++;
        break;
    case 7:
        return 1;
    }
    return 0;
}






int func_0216C204(void *a, u8 *b)
{
    int r = (int)func_020122C0(a, 0, (void *)func_0216C0E8, 0x64);
    int *p = func_020124E8((struct Obj *)r);
    p[0] = (int)a;
    p[1] = (int)b;
    p[4] = 0;
    p[2] = (int)func_02188C58((void *)b);
    p[3] = func_02188D38(b);
    p[5] = 0x14;
    *(B32 *)(p + 14) = d_02172528;
    p[22] = 1;
    p[23] = 1;
    p[24] = (int)func_0218FE80((void *)b);
    func_0218FEA0((u8 *)p[24], (unsigned int)(p + 5));
    return r;
}






int func_0216C270(Work_0216C2FC *w)
{
    return func_02011590(w->anim, 0x1000);
}




/*
 * unblocked: func_021BE480 (ov021, unlabelled leaf) matched bottom-up and
 *           filed as pkt_021BE480; the `ov021` token resolves the +0x18
 *           call as `matched, overlay`.  func_02188D2C was already matched.
 *
 * Asks the arm9 side for the slot's descriptor, sizes it through the
 * overlay helper and copies the second word of the local into it.
 */
void *func_0216C280(void *p)
{
    char v[12];
    void *q;

    func_02011610(((struct Obj01029 *)p)->f10, (struct Rec12 *)v);
    q = (void *)func_021BE480((char *)func_02188D2C(((struct Obj01029 *)p)->f8), 0, 0);
    ((struct Obj17768 *)q)->f4 = ((struct Obj17767 *)v)->f4;

    return q;
}



#pragma opt_propagation off


/*
 * Snap the actor's position to the 16-unit grid (z biased by 32) and
 * write it to the ov021 map object.
 *
 * pass 6 2026-10-06 P6L05: closed from a capture of the compiler's register
 * colouring (debugger break at the colour select step of mwccarm). The
 * graph showed y with a long live range (stored after the x snap) was
 * coloured early and took r3. Storing v.y first makes y short-lived, so it
 * is coloured late, after x; reading z, y, x (x snapped first, its load
 * hoisted) gives the image's load order x, z, y. EXACT in c99 and c.
 */
void func_0216C2A4(Work_0216C2FC *w)
{
    VecFx32 v;
    const VecFx32 *pos;
    void *q;
    fx32_0216C2A4 x;
    fx32_0216C2A4 y;
    fx32_0216C2A4 z;
    fx32_0216C2A4 k;

    pos = func_021BE480((void *)func_02188D2C(w->field), 0, 0);
    q = func_02188CB4(w->field);
    z = pos->z;
    y = pos->y;
    x = pos->x;
    k = 0x20000;
    z = z + k;
    v.y = y;
    v.x = (((x >> 12) / 16) << 16) + 0x8000;
    v.z = (((z >> 12) / 16) << 16) + 0x8000;
    func_021A3044(q, &v);
}


#pragma opt_propagation reset






/*
 * Seven-state proc of a field event in ov010: animate the actor until it
 * lands on the grid, push the result screen with a fixed Param, then
 * settle the ov050 gimmick and drop the object back to the ground height.
 * First draft; the 0x021F37xx callees are declared ov050, the only
 * overlay that labels all six.
 */
int func_0216C2FC(void *evt, u32 *state, Work_0216C2FC *w){
    Param p;
    VecFx32_0216C2FC v;
    fx32_0216C2FC y;
    int done;
    void *q;
    void *a;

    func_02188D2C(w->field);
    switch (*state) {
    case 0:
        w->anim = func_020114D0(w->f00, 0x9D, 0x19);
        func_0216C280(w);
        func_0216C2A4(w);
        func_0218F0A8(w->f0c);
        (*state)++;
        break;
    case 1:
        if (func_0218F0E8(w->f0c) == 0)
            (*state)++;
        break;
    case 2:
        func_021F3714(w->field);
        func_021F37B8((int)w->field);
        func_02012374(evt, func_021BE92C(w->sys, w->field, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 3:
        done = func_0216C270(w);
        if (done == 0) {
            func_0216C280(w);
            func_0216C2A4(w);
        }
        if (done != 0) {
            func_02011558(w->anim);
            func_020061F8(func_02006148(1953));
            func_020061E4(1775);
            p.f00 = 2;
            p.f02 = 0;
            p.f10 = 3;
            p.f0f = 2;
            p.f0e = 2;
            p.f14 = 0;
            p.f04 = 0;
            p.f06 = 1;
            p.f08 = 0;
            p.f0a = 0;
            p.f0c = 2;
            func_02012374(evt, func_021D2D50(w->sys, &p));
            (*state)++;
        }
        break;
    case 4:
        if (func_021F3758(w->field) && func_021F3808(w->field)) {
            func_021F3744(w->field);
            func_021F3788(w->field);
            (*state)++;
        }
        break;
    case 5:
        q = func_02188CB4(w->field);
        a = func_021A3074(q);
        func_021A3038(q, (struct VecFx32 *)&v);
        func_02163E58(a, &v, &y);
        v.y = y;
        func_021A3044(q, &v);
        (*state)++;
        break;
    case 6:
        return 1;
    }
    return 0;
}







void *func_0216C44C(void *a,void *b) {
    void *t; u8 *p;
    t=func_020122C0(a,0,(void *)func_0216C2FC,0x14); p=func_020124E8(t);
    ((struct Obj05905 *)p)->f0=func_02188C84(b); ((struct Obj05905 *)p)->f4=a; ((struct Obj05905 *)p)->f8=b;
    ((struct Obj05905 *)p)->fC=func_02188C58(b); ((struct Obj05905 *)p)->f10=0; return t;
}








int func_0216C484(int a, int *st, int *o)
{
    int x = o[0];
    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE8D4((void *)x, (void *)o[1], 0, 0));
        (*st)++;
        break;
    case 1:
        func_02012374((struct Evt *)a, (struct Evt **)func_020144DC(x, o[1]));
        (*st)++;
        break;
    case 2:
        func_02012374((struct Evt *)a, func_02014910((char *)x, o[1], (int)((char *)o + 0x30), (int)((char *)o + 8)));
        (*st)++;
        break;
    case 3:
        func_02012374((struct Evt *)a, func_020145CC((void *)x));
        (*st)++;
        break;
    case 4:
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)x, (void *)o[1], 0, 0, 1, 0, 0));
        func_02082D44((char *)o + 0x79, ((struct Obj02353 *)o)->fD0, 6);
        **(short * *)&((struct Obj02353 *)o)->fCC = o[0x6c / 4];
        **(short * *)&((struct Obj02353 *)o)->fC8 = o[0x70 / 4];
        func_020307B0((void *)o[0x44 / 4]);
        (*st)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}








/*
 * Starts the func_0216C484 task over a 0xD8-byte work: points it at the
 * caller's result fields, picks the party (the player's, or the one at
 * +0x7C8 when `useOwn` is set), and fills the party-screen and summary
 * argument blocks; the screen mode (0x14, 0x15 or 0x16) follows the
 * caller's kind at +9.
 *
 * MATCH (2026-09-28 tree_ov010_4; levers: declaration order q, task, p
 * for the frame slots, the summary block pointer formed before the
 * func_0200CA1C call). The one wildcard is arm9 0x0201A354, an unlabelled
 * Thumb thunk (`movs r0, #0x69; bx` to 0x02048F60) inside the listing's
 * ARM data run: a seed for the ARM9 session.
 */
void *func_0216C538(PartyCaller *c, void *sys, u8 useOwn)
{
    void *q;
    void *task;
    void *p;
    PartyTaskWork *w;
    void *party;
    PartyArgs *pa;
    SummaryArgs *sum;
    void *h;
    u32 mode;
    u32 sel;

    p = func_020120F4(sys);
    q = func_0201210C(sys);
    task = func_020122C0(sys, 0, func_0216C484, sizeof(PartyTaskWork));
    w = func_020124E8(task);
    w->sys = sys;
    w->q = q;
    w->outD0 = c->f7c;
    w->outCC = &c->f82;
    w->outC8 = &c->f84;
    if (useOwn == 0)
        party = func_02012934(p);
    else
        party = c->party;
    mode = 0x14;
    sel = 0;
    pa = &w->pa;
    MI_CpuFill8(pa, 0, sizeof(PartyArgs));
    pa->party = party;
    switch (c->kind) {
    case 1:
    case 6:
        mode = 0x15;
        sel = 1;
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        mode = 0x16;
        sel = 2;
        break;
    }
    pa->f14 = func_0201A354(mode, 4);
    pa->f34 = 0x16;
    pa->f38 = sel;
    sum = &w->sum;
    h = func_0200CA1C(p);
    MI_CpuFill8(sum, 0, sizeof(SummaryArgs));
    sum->party = party;
    sum->f0c = 1;
    sum->count = func_0201AA18(party);
    sum->f0d = 0;
    sum->f10 = 0;
    sum->p = p;
    sum->f18 = (void *)func_0200CA38(h);
    return task;
}








/*
 * lever: The result of func_021CBD08 remains live in r2 and is the third argument of func_0216E8CC.
 *
 * DIFF: original keeps the call result in r2 (adds r2,r0) and loads the 0x7CC offset into r0;
 * ours loads the offset into r1 and stores r0. Tried a local, a struct field, unsigned char.
 */
void func_0216C640(S *a, int b, int c)
{
    int t;
    func_0200B400(4);
    t = func_021CBD08((u8 *)a, b);
    a->f = t;
    if (a->k == 3 || a->k == 8) {
        func_0216CAD4(a, (void *)b, (void *)c);
        return;
    }
    func_0216E8CC(b, c, t);
}








int func_0216C680(int a, int *st, int *o, u32 a3)
{
    switch (*st) {
    case 0:
        if (!func_02191388((u32 *)o[5]))
            break;
        (*st)++;
    case 1:
        func_021914CC((struct S *)o[5]);
        if ((func_020362DC() & 3) == 0)
            break;
        func_020061E4(0x547);
        func_021912D8(o[5]);
        (*st)++;
        break;
    case 2:
        if (func_021912F8(o[5], (u32)st, (u32)o, a3) == 1) {
            func_02045808((struct U16Vec *)o[6]);
            return 1;
        }
        break;
    }
    return 0;
}








/*
 * unit_02045C44.c omits func_02045CAC from function:. Singleton TU split
 * leaves this caller OUT. No overlay leaves filed.
 * EXACT 344 bytes through the ov070 blocker evidence; not recompiled here.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char g_020A7E8C[];
 * extern void *sub_02030734(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void func_020495F4(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void func_0204581C(void *);
 * extern void func_02045A00(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void func_02045CAC(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         func_0204581C(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         func_020495F4(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,g_020A7E8C,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             func_020495F4(bank->stream,size,buf);
 *             func_02045A00(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         func_02045A00(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 * lever: task, ctx, x, proc declaration order restores pointer spill slots.
 */
void *func_0216C6E8(u8 *d, void *sys, u32 idx, u16 id, u8 dir)
{
    VecFx32_0216C2FC ofs;
    u32 a;
    u32 b;
    void *task;
    void *ctx;
    void *x;
    void *proc;
    Spawn *t;
    void *bank;
    void *m;
    u16 n;

    ctx = func_020120F4(sys);
    proc = func_0201210C(sys);
    x = (void *)func_02188C54(proc);
    task = func_020122C0(sys, 0, func_0216C680, 0xD8);
    t = func_020124E8(task);
    t->sys = sys;
    t->id = id;
    if (*(u16 *)((u32)d + 0xA0 + idx * 0x120) == 0xFFFF) {
        t->name = func_020457B0(0x300, 4);
        bank = sub_02045B38(0, 2, 0xB8, 4);
        n = *(u16 *)((u32)d + 0xA2 + idx * 0x120);
        if (n >= 0x3AE)
            n = 0;
        func_02045CAC(bank, n, t->name);
        func_02045C04(bank);
    } else {
        t->name = func_0202435C((u16 *)((u32)d + 0xA0 + idx * 0x120), 4);
    }
    func_0216D88C(func_0216DE94((void *)func_02012964(ctx), t->id), &t->pos);
    m = func_02188C58(proc);
    func_021B09D8(&t->pos, &ofs, (void *)(func_0218EC2C(m)), (void *)m, (void *)dir);
    t->pos.x += ofs.x;
    t->pos.y += ofs.y;
    t->pos.z += ofs.z;
    func_021B09EC(dir, (int *)(&a), (int *)(&b));
    t->obj = func_0219129C(x, a, (u32)(&t->pos), (u32)t->name, 0, b);
    return task;
}








/*
 * blockers: func_02012EFC (unlabelled arm9 leaf, no witness), id_00000045 (pooled small
 * constant, a symbol; no witness), d_021BA650 (pointer into another overlay, no witness)
 *
 * 2026-10-05: data hints now carry an overlay token that has a witness; EXACT.
 */
int func_0216C7FC(int a, int *st, int *o)
{
    int t;
    switch (*st) {
    case 0:
        o[2] = (int)func_020120F4((const struct Ctx *)o[1]);
        t = (int)func_02012EFC((void **)o[2]);
        o[3] = func_0200DF40((struct RecSlot *)t);
        o[4] = func_0200DF4C((struct RecSlot *)t);
        func_02012374((struct Evt *)a, func_020146F8((char *)o[1], o[0], (int)id_00000045, (int)d_021BA650, (int)(&o[2])));
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}







void *func_0216C860(void *a) {
    void *v; void *t; void **p;
    v=func_0201210C(a); t=func_020122C0(a,0,(void *)func_0216C7FC,0x14); p=func_020124E8(t);
    p[1]=a; ((struct Obj12397 *)p)->f0=v; return t;
}








int func_0216C888(int a0, int a1, int a2)
{
    int t4;

a2 = 1;
t4 = a0 + 0;
a0 = 1;
a1 = 0x76;
a2 = a2 << 0xe;
    func_0203064C(a0, a1, a2);
loc_0216C898:
a0 = t4 + 0;
a1 = 4;
a2 = 0x76;
    a0 = func_0203159C(a0, a1, a2);
loc_0216C8A2:
t4 = a0 + 0;
a0 = 0x76;
    a0 = (int)func_02031324(a0);
loc_0216C8AA:
((struct Obj12055 *)((char *)t4))->f0 = a0;
a0 = 1;
    return a0;}







/*
 * extent: zero alignment halfword at 0x0216C8CA, then labelled 0x0216C8CC.
 */
int func_0216C8B0(void *a, int b, int c, void **d) {
    func_0203133C(*d); func_020315D4(a); func_020306F0(0x76); return 1;
}






/*
 * blockers: d_021F03C4 and d_021EFDAC data pointers outside ov010 window; no witness
 * (tried ov006/008/011/187/199/ov010 hints)
 *
 * 2026-10-05: data hints now carry an overlay token that has a witness; EXACT.
 */
int func_0216C8CC(int a, int *st, int *o, int *x)
{
    int r = func_02031330((void *)x[0]);
    switch (*st) {
    case 0:
        func_02034AC4((s32_0216C8CC)id_0000005D);
        func_0203A574(0x100, (u32)d_021F03C4, 9, 0);
        func_0203D594((int)func_020399A8(), 0xc8);
        *st = 1;
        break;
    case 1:
        if (func_0200FB24() != 0) {
            *st = 4;
            break;
        }
        if (func_0203D5A0((int)func_020399A8(), 0xc8) == 0)
            break;
        *st = 2;
        break;
    case 2:
        func_02031348(x[0], ~0, d_021EFDAC, o[1]);
        *st = 3;
        break;
    case 3:
        if (r == 1)
            break;
        *st = 4;
        break;
    case 4:
        func_0203A5E4(0x100);
        func_02034A5C((s32_0216C8CC)id_0000005D);
        *st = 5;
        break;
    case 5:
        return 1;
    }
    return 0;
}






int func_0216C978(int a, int *st, int *o)
{
    int x = o[0];
    int *t;
    switch (*st) {
    case 0:
        t = o + 3;
        o[3] = (int)func_020120F4((const struct Ctx *)x);
        t[1] = o[1];
        t[2] = o[2];
        func_020120B4((struct IcaAnime *)x, ~0, d_02172548, t);
        (*st)++;
        break;
    case 1:
        if (func_020120F0((const struct Ctx *)x) == 0)
            return 1;
        break;
    }
    return 0;
}





void *func_0216C9CC(void *a,void *b,void *c) {
    void *t; void **p;
    t=func_020122C0(a,0,(void *)func_0216C978,0x3c); p=func_020124E8(t);
    p[0]=a; p[1]=b; p[2]=c; return t;
}






int func_0216C9F4(int a, int *st, int *o)
{
    int x = o[0];
    int y = o[1];
    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, func_02161824((void *)x, (void *)y));
        (*st)++;
        break;
    case 1:
        func_02012374((struct Evt *)a, func_02029BCC((void *)x, *(unsigned short *)(o[2] + 0x18)));
        (*st)++;
        break;
    case 2:
        func_021AAABC(func_02188CE8((u8 *)y));
        func_021CF498((struct Ctx *)func_02189A08((unsigned char *)o[1]), a, 9);
        (*st)++;
        break;
    case 3:
        func_02012374((struct Evt *)a, (struct Evt **)func_020144DC(x, y));
        (*st)++;
        break;
    case 4:
        func_02012374((struct Evt *)a, func_0216C9CC((void *)x, (void *)o[2], (void *)o[3]));
        (*st)++;
        break;
    case 5:
        func_02012374((struct Evt *)a, func_02029C00((void *)x));
        (*st)++;
        break;
    case 6:
        func_02012374((struct Evt *)a, func_020145CC((void *)x));
        (*st)++;
        break;
    case 7:
        func_02012374((struct Evt *)a, func_02029CC0((void *)x));
        (*st)++;
        break;
    case 8:
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)x, (void *)y, 0, 0, 1, 0, 0));
        (*st)++;
        break;
    case 9:
        return 1;
    default:
        return 1;
    }
    return 0;
}





void *func_0216CAA8(void *a,void *b,void *c,void *d) {
    void *t; void **p;
    t=func_020122C0(a,0,(void *)func_0216C9F4,0x10); p=func_020124E8(t);
    p[0]=a; p[2]=c; p[3]=d; p[1]=b; return t;
}






/*
 * unblocked: func_021CBD84 (ov021, unlabelled leaf) was matched bottom-up
 *   and filed as pkt_021CBD84; the `ov021` token then resolves the site as
 *   `matched, overlay`.
 *
 * The record's far field (0x7CC) and the arm9 probe result are the last
 * two arguments of the four-argument overlay call.
 */
void func_0216CAD4(void *a0, void *a1, void *a2)
{
    int v = (int)func_021CBD84(a0);

    func_0216CAA8(a1, a2, (void *)(((struct Obj17769 *)a0)->f7CC), (void *)v);
}






int func_0216CAF4(int a0, int a1, int a2)
{
    int t4;
    int t5;

t5 = a1 + 0;
a0 = ((struct Obj09165 *)((char *)t5))->f0;
t4 = a2 + 0;
    if (a0 == 0) goto loc_0216CB0A;
loc_0216CB00:
    if (a0 == 1) goto loc_0216CB1C;
loc_0216CB04:
    if (a0 == 2) goto loc_0216CB2E;
loc_0216CB08:
    goto loc_0216CB42;
loc_0216CB0A:
a0 = ((struct Obj07205 *)t4)->f14;
    a0 = func_02191388(a0);
loc_0216CB10:
    if (a0 != 1) goto loc_0216CB42;
loc_0216CB14:
a0 = ((struct Obj09165 *)((char *)t5))->f0;
a0 = a0 + 1;
((struct Obj09165 *)((char *)t5))->f0 = a0;
    goto loc_0216CB42;
loc_0216CB1C:
    a0 = func_020362DC();
loc_0216CB20:
a1 = 3;
    if ((a0 & a1) == 0) goto loc_0216CB42;
loc_0216CB26:
a0 = ((struct Obj07205 *)t4)->f14;
    a0 = func_021912D8(a0);
loc_0216CB2C:
    goto loc_0216CB14;
loc_0216CB2E:
a0 = ((struct Obj07205 *)t4)->f14;
    a0 = func_021912F8(a0);
loc_0216CB34:
    if (a0 != 1) goto loc_0216CB42;
loc_0216CB38:
a0 = ((struct Obj07205 *)t4)->f18;
    a0 = func_02045808(a0);
loc_0216CB3E:
a0 = 1;
    return a0;
loc_0216CB42:
a0 = 0;
    return a0;}






/*
 * The third parameter is u8: with it declared int the body is byte-identical
 * except that the w->owner store and the next call's argument move swap
 * places (4 bytes); the u8 spill to [sp,#8] changes nothing visible but the
 * schedule.  Found by tools/permuter.py --types.  The call to arm9
 * 0x0202435C (an unlabelled two-slot wrapper) is attested by its shard.
 *
 * evidence: 0x0202435C is an unlabelled ARM9 thunk ("ldr r3, =func_02024368; movs r2, #2; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov069 0x021BA21A, ov093 0x021D1894, ov010 0x02168138), so the call
 * attests as `label`.
 */
void *func_0216CB48(void *owner, int idx, u8 arg)
{
    void *sys;
    void *anm;
    void *ctx;
    void *task;
    Work_0216CB48 *w;
    void *mdl;
    void *m2;
    void *cam;
    VecFx32_0216C2FC ofs;
    s32_0216CB48 b;
    s32_0216CB48 c;
    u8 *tbl;

    sys = func_020120F4(owner);
    anm = func_0201210C(owner);
    ctx = (void *)func_02188C54(anm);
    task = sub_020122C0(owner, 0, func_0216CAF4, sizeof(Work_0216CB48));
    w = sub_020124E8(task);
    w->owner = owner;
    mdl = (void *)func_02012964(sys);
    m2 = func_0216DEE0(mdl);
    func_0216D88C(func_0216DE94(mdl, arg), &w->pos);
    mdl = (void *)func_021B0A40((u32)m2, (struct Q *)(&w->pos));
    cam = func_02188C58(anm);
    func_021B09D8(&w->pos, &ofs, (void *)func_0218EC2C(cam), cam, mdl);
    w->pos.x += ofs.x;
    w->pos.y += ofs.y;
    w->pos.z += ofs.z;
    tbl = (u8 *)func_0200DF58(func_020071CC(func_02012EBC(sys), 0x3b), 4);
    w->field18 = func_0202435C(tbl + idx * 0x22 + 0x18, 4);
    func_020307B0(tbl);
    func_021B09EC((int)mdl, &b, &c);
    w->field14 = (u32)func_0219129C(ctx, b, (u32)(&w->pos), (u32)w->field18, 0, c);
    return task;
}






int func_0216CC30(int a0, int a1)
{
    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0216CC38:
    a0 = func_0216CC40(v0);
loc_0216CC3C:
a0 = 0;
    return a0;}





/*
 * extent: zero alignment halfword at 0x0216CC56, then labelled 0x0216CC58.
 * interface: r1=0x34 is visibly supplied to the accessor despite its body only reading r0.
 */
int func_0216CC40(void *a) {
    *func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(a)),0x34)=1;
}






char *func_0216CC58(int a, int b, int c)
{
    char *p = (char *)func_02030734(a, 0x48, 1, d_02172B48, 0xc3);
    ((struct Obj04949 *)p)->f18 = (int)func_02030734(a, b << 8, 1, d_02172B48, 0xc4);
    ((struct Obj04949 *)p)->f4 = b;
    ((struct Obj04949 *)p)->f8 = a;
    ((struct Obj04949 *)p)->f2C = c;
    ((struct Obj04949 *)p)->fC = 0x80;
    func_0216E280((int)p, a);
    ((struct Obj04949 *)p)->f44 = (int)func_02030734(a, 0xc4 << 2, 1, d_02172B48, 0xcf);
    return p;
}






int func_0216CCB0(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0216E290((char *)a0);
loc_0216CCB8:
a0 = ((struct Obj12056 *)t4)->f44;
    a0 = func_020307B0((void *)a0);
loc_0216CCBE:
a0 = ((struct Obj12056 *)t4)->f18;
    a0 = func_020307B0((void *)a0);
loc_0216CCC4:
a0 = t4 + 0;
    a0 = func_020307B0((void *)a0);
loc_0216CCCA:
    return a0;}






/*
 * Unlabelled leaf (saves no lr, so disasm.py prints it as .word data):
 * clears the 0x310-byte buffer at +0x44, a tail call through a pool word.
 * Callee of ov020 func_021857C0.
 */
void func_0216CCCC(Obj *o)
{
    MI_CpuFill8(o->f44, 0, 0x310);
}






/*
 * lever: The allocation result is the second argument to func_02030CBC; its r1 live range orders the halfword reload.
 *
 * DIFF: original moves the alloc result to r1 (adds r1,r0) and stores it after the ldrh reload
 * (+2 B, pool shifts 4). Tried a result local and a halfword local.
 */
void func_0216CCDC(char *a, int b, int c, int d, int e, int f)
{
    int t;
    unsigned short h;
    ((struct Obj02669 *)a)->f34 = e;
    ((struct Obj02669 *)a)->fA = b;
    ((struct Obj02669 *)a)->f30 = c;
    ((struct Obj02669 *)a)->f3C = d;
    t = (int)func_02030734(b, func_02030CB0(((struct Obj02669 *)a)->f4), 0, d_02172B48, 0x109);
    h = ((struct Obj02669 *)a)->f4;
    ((struct Obj02669 *)a)->f1C = t;
    ((struct Obj02669 *)a)->f20 = (int)func_02030CBC(h, (struct Ctx *)t);
    ((struct Obj02669 *)a)->f10 = (int)func_020490F4(0x31, b);
    ((struct Obj02669 *)a)->f38 = f;
    func_0216D4DC(a, 0x10);
}






void func_0216CD30(u32 *a0)
{
    int t4;
    int a1;

t4 = (int)(a0 + 0);
a0 = (u32 *)(((struct Obj09166 *)t4)->f20);
    a0 = (u32 *)func_02030DA4(a0);
loc_0216CD3A:
a0 = (u32 *)(((struct Obj09166 *)t4)->f1C);
    a0 = (u32 *)func_020307B0(a0);
loc_0216CD40:
a0 = (u32 *)(((struct Obj09166 *)t4)->f10);
    func_02049238((void *)a0);
loc_0216CD46:
a0 = (u32 *)(t4 + 0);
a1 = 0x10;
    a0 = (u32 *)func_0216D4E4(a0, a1);
loc_0216CD4E:
    return;}







void func_0216CD50(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_02197C4C(a0);
loc_0216CD58:
a0 = 0;
((struct Obj17770 *)t4)->f40 = a0;
a0 = t4 + 0;
    func_0216CD30((u32 *)a0);
loc_0216CD62:
    return;}







int func_0216CD64(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj01464 *)t4)->f20;
    a0 = func_02030D28(a0);
loc_0216CD6E:
a0 = t4 + 0;
    a0 = func_0219C5FC(a0);
loc_0216CD74:
    return a0;}







/*
 * blocked:  listing 16 compiled 14
 */
int func_0216CD78(int a0)
{
    int a1;

a1 = ((struct Obj17771 *)a0)->f24;
    if (a1 == 0) goto loc_0216CD84;
loc_0216CD80:
    a0 = func_0219C624(a0);
loc_0216CD84:
    return a0;}







/*
 * blocked:  listing 48 compiled 46
 */
int func_0216CD88(int a0)
{
    int a1;
    int t4;
    int t5;

t5 = a0 + 0;
    a0 = func_0219C630(a0);
loc_0216CD90:
    if (a0 != 1) goto loc_0216CDB4;
loc_0216CD94:
t4 = 1;
loc_0216CD96:
a0 = t5 + 0;
    a0 = func_0216CD64(a0);
loc_0216CD9C:
a0 = t4 + 0;
a1 = t4 + 0;
    a0 = func_02087A3C(a0, a1);
loc_0216CDA4:
a0 = t5 + 0;
    a0 = func_0216CD78(a0);
loc_0216CDAA:
a0 = t5 + 0;
    a0 = func_0219C630(a0);
loc_0216CDB0:
    if (a0 == 1) goto loc_0216CD96;
loc_0216CDB4:
    return a0;}







/*
 * Unlabelled thumb leaf (store, then tail call through a pool word), the
 * sole blocker of ov021 func_02189204 (lane S26).
 * Addresses are Black-image addresses.
 */
void func_0216CDB8(u8 *p, u32 v, int a2)
{
    ((struct Obj19116 *)p)->f40 = v;
    func_0216D95C((unsigned int *)p, 1, a2);
}







u8 *func_0216CDC4(u32 a, Rec *p, u32 b, u32 c)
{
    Rec r = *p;
    u8 *o;

    o = (u8 *)func_0216DEEC(a);
    func_0216D1C8(o, a, b);
    func_0216D040(o, (u16 *)(&r), c, a);
    func_0216D208(o);
    if (func_0216E51C(o) == 1)
        func_0216D548((u32 *)o, 640);
    if (func_0216D4D4(a, 0x10)) {
        func_0216D244(a, o);
        func_0216D268(a, (int)o);
    }
    if (func_0216D4D4(a, 1))
        func_0216E114((void *)o);
    func_0216D4FC((int)func_0216D67C(o));
    func_0216D0E8((int)o, (u8 *)&r, 0);
    return o;
}






void *func_0216CE60(int a, int b, int c){
    func_0216CDC4(a, (Rec *)b, c, 0);
}







void *func_0216CE6C(void *o, u32 f, u32 g, u32 d, In3 in, u32 x)
{
    Big s;
    In3 *ip = &in;
    Big *v = &s;
    W2 *w;

    func_02082BCC(&s, 0, 0x24);
    v->a = ip->a;
    v->b = ip->b;
    v->c = ip->c;
    v->d = d;
    s.e = 0;
    w = &s.w;
    w->f = f;
    w->g = g;
    return func_0216CE60((int)o, (int)(&s), x);
}






/*
 * extent: zero alignment halfword at 0x0216CEE2, then labelled 0x0216CEE4.
 * interface: E42C forwards r0/r1 unchanged; caller reads r0, so extern returns int.
 */
void func_0216CEAC(u32 a,u8 *p,u32 b,u32 n,u32 c) {
    do {
        if(func_0216E418(p)==1 || func_0216E42C((void *)c,((struct Obj19117 *)p)->f8)==0)
            func_0216CDC4((int)a, (Rec *)p, b, c);
        p+=0x24;
    } while(--n);
}









/*
 * The result local is never initialised on the not-found path (the
 * original returns whatever stack slot it had).
 */
int func_0216CEE4(u32 a, Ent *e, u32 b, int n, u32 c, u32 id)
{
    int r;

    do {
        if (func_0216E418(e) == 0 && e->id == id && func_0216E42C((void *)c, e->key) == 0) {
            r = (int)func_0216CDC4(a, (Rec *)e, b, c);
            break;
        }
        e++;
    } while (--n);
    return r;
}









int func_0216CF2C(int a0)
{
    int t4;
    int a1;

t4 = a0 + 0;
    a0 = (int)func_0216D67C((void *)a0);
loc_0216CF34:
    a0 = func_0216D948(a0);
loc_0216CF38:
    if (a0 != 1) goto loc_0216CF42;
loc_0216CF3C:
a0 = t4 + 0;
    a0 = func_0216D76C((void *)a0);
loc_0216CF42:
a0 = t4 + 0;
a1 = 2;
    a0 = func_0216D55C(a0, a1);
loc_0216CF4A:
    if (a0 == 0) goto loc_0216CF5A;
loc_0216CF4E:
a0 = t4 + 0;
    a0 = func_0216D71C((void *)a0);
loc_0216CF54:
a0 = t4 + 0;
    a0 = func_0216DFAC(a0);
loc_0216CF5A:
a0 = t4 + 0;
a0 = a0 + 0x88;
a0 = *(int *)&((struct Obj00113 *)((char *)a0))->f0;
    a0 = func_0216D508(a0);
loc_0216CF64:
a0 = t4 + 0;
    a0 = func_0216E180((void *)a0);
loc_0216CF6A:
    return a0;}









void func_0216CF6C(u32 x)
{
    int n;
    u8 *o;
    u32 k = 2;

    n = 0;
    while (func_0216DD1C((struct Ctx *)x, (struct Rec_0216D9A0 **)(&o), (u32 *)(&n))) {
        if (func_0216D948(x) == 1)
            func_0216D76C(o);
        func_0216D55C((int)o, k);
        func_0216D508(*(u32 *)&((struct Obj00113 *)o)->f88);
        func_0216E180(o);
    }
}









void func_0216CFC4(int a0, int a1)
{
    int a2;
    int t4;
    int t5;

t4 = a1 + 0;
a1 = ((struct Obj02051 *)((char *)t4))->f0;
t5 = a0 + 0;
    a0 = func_0216D584((void *)a0, a1);
loc_0216CFD0:
a1 = ((struct Obj02051 *)t4)->f4;
a0 = t5 + 0;
    func_0216D59C((void *)a0, a1);
loc_0216CFD8:
a1 = ((struct Obj02051 *)t4)->f6;
a0 = t5 + 0;
    a0 = func_0216D5A4((void *)a0, a1);
loc_0216CFE0:
a1 = ((struct Obj02051 *)t4)->f8;
a0 = t5 + 0;
    a0 = func_0216D5AC((void *)a0, a1);
loc_0216CFE8:
a1 = ((struct Obj02051 *)t4)->fA;
a0 = t5 + 0;
    a0 = func_0216D5B4((void *)a0, a1);
loc_0216CFF0:
a0 = ((struct Obj02051 *)t4)->fC;
a1 = ((struct Obj02051 *)t4)->fE;
a2 = 0;
*(u16 *)((char *)t5 + 0x16) = a0;
((struct Obj00113 *)t5)->f1A = a0;
a0 = t5 + 0;
    a0 = func_0216D620(a0, a1, a2);
loc_0216D000:
a1 = ((struct Obj02051 *)t4)->f10;
a0 = t5 + 0;
a2 = 1;
    a0 = func_0216D620(a0, a1, a2);
loc_0216D00A:
a1 = ((struct Obj02051 *)t4)->f12;
a0 = t5 + 0;
a2 = 2;
    a0 = func_0216D620(a0, a1, a2);
loc_0216D014:
func_0216D65C((void *)t5, *(short *)((char *)t4 + 0x14));
loc_0216D01E:
    func_0216D668((void *)t5, *(short *)((char *)t4 + 0x16));
loc_0216D028:
    return;}








void func_0216D02C(int a, u8 *p) {
    if (((struct Obj19118 *)p)->f18 == 0) func_0216D0F8((void *)a, p);
    else func_021642F8((void *)a);
}









void func_0216D040(u8 *o, u16 *r, u32 b, u32 c)
{
    u32 id;
    s8 *p;

    func_0216CFC4((int)o, (int)r);
    id = func_0216E3D8(b, r[1]);
    func_0216D594(o, id);
    func_0216E39C((const char *)c, id, o);
    p = (s8 *)(o + 0xe4);
    if (id == 0xb9) {
        o[0x7c] = r[7];
        o[0x7d] = r[8];
        if (o[0x7c] == 0)
            o[0x7c] += 1;
        if (o[0x7d] == 0)
            o[0x7d] += 1;
    } else {
        o[0x7c] = ((u8 *)p)[0xb];
        o[0x7d] = ((u8 *)p)[0xc];
    }
    o[0x7e] = p[0xd];
    o[0x7f] = p[0xe];
    o[0x80] = p[0xf];
    func_0216D02C((int)o, (u8 *)r);
}








/*
 * extent: zero alignment halfword at 0x0216D0F6, then labelled 0x0216D0F8.
 */
void func_0216D0E8(int a, u8 *p, int c) {
    if (((struct Obj09310 *)p)->f18 == 1) func_02164304(a, p);
}









#pragma opt_propagation off








/*
 * final push 2026-10-05 G4L4: EXACT in c99 and c. The last argument of func_0216D7F4 is
 * a named int local (t) set from the field just before the call, with
 * #pragma opt_propagation off around the function. With propagation on the local is folded
 * into the call and the object copy is born before the argument chain (chain in r1, 13 B);
 * with it off the chain is born first and takes r0, as in the image. s16 local with the
 * pragma gave 9 B; int local without the pragma gave 13 B.
 */
void func_0216D0F8(void *obj, const u8 *a1)
{
    const Src *p = (const Src *)(a1 + 0x1c);
    VecFx32_0216C2FC v;
    s32 x;
    s32 y;
    fx32_0216CEE4 z;

    if (func_0216E51C(obj, (int)a1) == 0) {
        x = p->x;
        y = p->y;
        z = p->z;
    } else {
        func_0216E544(obj, &v);
        x = (v.x >> 4) / 4096;
        y = (v.z >> 4) / 4096;
        z = v.y;
    }
    v.x = (x << 16) + 0x8000;
    func_0216D7F0(obj, p->x);
    func_0216D80C(obj, x);
    func_0216D844(obj, x);
    {
        int t = (p->z >> 4) / 4096;
        func_0216D7F4(obj, t);
    }
    v.y = z;
    x = (z >> 4) / 4096;
    func_0216D818(obj, x);
    func_0216D85C(obj, (s16)x);
    v.z = (y << 16) + 0x8000;
    func_0216D800(obj, p->y);
    func_0216D824(obj, y);
    func_0216D874((int)obj, (s16)y);
    func_0216D89C(obj, (void *)&v);
}








#pragma opt_propagation reset









void func_0216D1C8(u8 *p, u32 a, u32 b)
{
    ((struct Obj19119 *)p)->f88 = a;
    func_0216D58C(p, (u16)b);
    func_0216D548((u32 *)p, 1);
    func_0216D568(p, 0x1800);
    if (func_0216D5BC(p) == 1)
        func_0216DB98(p, 1);
    func_0216D4B4((char *)p);
}








void func_0216D208(void *p)
{
    func_0216D5D8((int)p, (u16)func_0216D5D4(p));
    func_0216D600((int)p, (u16)func_0216D5D4(p));
}








/*
 * blocked:  listing 20 compiled 18
 */
int func_0216D230(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0216D5A0((void *)a0);
loc_0216D238:
    a0 = func_0216E400(a0);
loc_0216D23C:
t4 = t4 + 0x8c;
((struct Obj17772 *)((char *)t4))->f0 = a0;
    return a0;}







void func_0216D244(u32 v, u8 *p)
{
    func_0216D230((int)p);
    func_0216DF64(p, v);
    func_0216D568(p, 0x1820);
}








int func_0216D268(int a0, int a1)
{
    int t4;

t4 = a1 + 0;
a1 = 2;
a0 = t4 + 0;
a1 = a1 << 0xc;
    a0 = func_0216D55C(a0, a1);
loc_0216D276:
    if (a0 != 0) goto loc_0216D282;
loc_0216D27A:
a0 = t4 + 0;
    a0 = func_02163010(a0);
loc_0216D280:
    return a0;
loc_0216D282:
a0 = t4 + 0;
    a0 = func_0219D6B8(a0);
loc_0216D288:
    return a0;}








/*
 * The mask test picks between the overlay's own handler and the arm9
 * field setter.
 */
int func_0216D28C(void *a0){
    if (func_0216D55C((int)a0, 0x2000) == 0) {
        func_02163028((void *)a0);
    } else {
        func_0219D6CC(a0);
    }
}








void func_0216D2AC(u32 x)
{
    int n;
    u8 *o;
    u32 k = 5;

    n = 0;
    if (func_0216D948(x)) {
        while (func_0216DD1C((struct Ctx *)x, (struct Rec_0216D9A0 **)(&o), (u32 *)(&n)) == 1) {
            func_0216DFAC((int)o);
            func_0216D780(o);
            func_0216D568(o, k);
        }
    }
}








void func_0216D2F8(u32 x)
{
    int n;
    u8 *o;
    u32 a = 1;
    u32 b = 4;
    u32 c = 2;

    n = 0;
    if (func_0216DD1C((struct Ctx *)x, (struct Rec_0216D9A0 **)(&o), (u32 *)(&n)) == 1) {
        do {
            func_0216D244(x, o);
            if (func_0216D55C((int)o, c) == 0)
                func_0216D268(x, (int)o);
            if (func_0216D57C(o, a)) {
                func_0216D730(o);
                func_0216D570((char *)o, a);
            }
            if (func_0216DAA0(o) == 0)
                func_0216E114((void *)o);
            if (func_0216D57C(o, b)) {
                func_0216D794(o);
                func_0216D570((char *)o, b);
            }
            func_0216E174(o);
        } while (func_0216DD1C((struct Ctx *)x, (struct Rec_0216D9A0 **)(&o), (u32 *)(&n)) == 1);
    }
}








/*
 * blocked:  listing 28 compiled 26
 */
void func_0216D38C(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0216D28C((void *)a0);
loc_0216D394:
a0 = t4 + 0;
    a0 = func_0216DA30(a0);
loc_0216D39A:
    if (a0 != 1) goto loc_0216D3A4;
loc_0216D39E:
a0 = t4 + 0;
    a0 = func_0216D3B4(a0);
loc_0216D3A4:
    return;}








/*
 * Unlabelled leaf (in a .word run): callback thunk that forwards its
 * second argument to func_0216D38C. Filed as the witness that
 * func_0216DF64's pointer to it needs.
 */
void func_0216D3A8(u32 a, u32 b)
{
    func_0216D38C(b);
}








int func_0216D3B4(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = (int)func_0216D67C((void *)a0);
loc_0216D3BC:
    a0 = func_0216D948(a0);
loc_0216D3C0:
    if (a0 != 1) goto loc_0216D3CA;
loc_0216D3C4:
a0 = t4 + 0;
    a0 = func_02197C78(a0);
loc_0216D3CA:
    return a0;}








int func_0216D3CC(int a0)
{
    int a1;
    int t4;
    int t5;

a1 = 1;
t5 = a0 + 0;
    a0 = func_0216D55C(a0, a1);
loc_0216D3D6:
    if (a0 != 0) goto loc_0216D3DE;
loc_0216D3DA:
a0 = 0;
    return a0;
loc_0216D3DE:
a0 = t5 + 0;
a1 = 0x10;
t4 = 0x10;
    a0 = func_0216D57C((void *)a0, a1);
loc_0216D3E8:
    if (a0 == 0) goto loc_0216D3F0;
loc_0216D3EC:
a0 = 0;
    return a0;
loc_0216D3F0:
a0 = t5 + 0;
a1 = t4 << 5;
    a0 = func_0216D57C((void *)a0, a1);
loc_0216D3F8:
    if (a0 == 0) goto loc_0216D40C;
loc_0216D3FC:
a0 = t5 + 0;
a1 = t4 << 6;
    a0 = func_0216D57C((void *)a0, a1);
loc_0216D404:
    if (a0 != 0) goto loc_0216D40C;
loc_0216D408:
a0 = 0;
    return a0;
loc_0216D40C:
a0 = 1;
    return a0;}








/*
 * blocked:  listing 40 compiled 38
 */
void func_0216D410(void *a0, u16 a1)
{
    u32 t4;

    func_0216D7C0(a0, a1);
    func_0216D7C8(a0, 0);
    t4 = 2;
    t4 = t4 << 8;
    func_0216D568(a0, t4);
    func_0216D570(a0, t4 << 1);
}











void func_0216D438(char *a0, u16 a1)
{
    func_0216D7C0(a0, a1);
    func_0216D7C8(a0, 0);
    func_0216D570(a0, 1 << 10);
}











int func_0216D454(int a0, u32 a1, u32 a2, u32 a3)
{
    int t4;
    int t5;

t4 = 2;
t4 = t4 << 8;
a1 = t4 + 0;
t5 = a0 + 0;
    a0 = func_0216D57C((void *)a0, a1);
loc_0216D462:
    if (a0 != 0) goto loc_0216D46A;
loc_0216D466:
a0 = 1;
    return a0;
loc_0216D46A:
a0 = t5 + 0;
a1 = t4 << 1;
    a0 = func_0216D57C((void *)a0, a1);
loc_0216D472:
    if (a0 == 0) goto loc_0216D47A;
loc_0216D476:
a0 = 1;
    return a0;
loc_0216D47A:
a0 = 0;
    return a0;}










int func_0216D480(char *p)
{
    if (func_0216D57C(p, 0x200) == 0) return 1;
    if (func_0216D57C(p, 0x400) == 0) return 0;
    func_0216D570(p, 0x600);
    return 1;
}










void *func_0216D4B4(char *p)
{
    func_0216D570(p, 0x600);
    func_0216D7C0(p, 0xff);
    return func_0216D7C8(p, 0);
}













int func_0216D4D4(int a0, int a1)
{

a0 = ((struct Obj17773 *)((char *)a0))->f0;
a0 = a0 & a1;
    return a0;}













void func_0216D4DC(void *a0, u32 a1)
{
    ((struct Obj12057 *)a0)->f0 |= a1;
}










u32 *func_0216D4E4(u32 *p, u32 v)
{
    *p &= ~v;
    return p;
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
 *   python tools/match.py one --src src/matched/func_0216D4F0.c \
 *       --func func_0216D4F0 --addr 0x0216D4F0 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0216D4F0(void *p) { return ((struct Obj17774 *)p)->f4; }










/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D4F4.c \
 *       --func func_0216D4F4 --addr 0x0216D4F4 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0216D4F4(void *p) { return ((struct Obj17775 *)p)->fC; }









/*
 * Getter: halfword at +0xa.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0216D4F8(u8 *p)
{
return ((struct Obj17776 *)p)->fA;
}












int func_0216D4FC(int a0)
{
    int a1;
a1 = 6;
a1 = *(short *)((char *)a0 + a1);
a1 = a1 + 1;
((struct Obj17777 *)a0)->f6 = a1;
    return a0;}












int func_0216D508(int a0)
{
    int a1;

a1 = 6;
a1 = *(short *)((char *)a0 + a1);
a1 = a1 - 1;
((struct Obj17778 *)a0)->f6 = a1;
    return a0;}










/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D514.c \
 *       --func func_0216D514 --addr 0x0216D514 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D514(void *p) { return ((struct Obj17779 *)p)->f20; }











/*
 * Reads the word field at +0x10.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0216D518(u8 *p)
{
    return ((struct Obj17780 *)p)->f10;
}











/*
 * Stores the word field at +0x24.
 *
 * Addresses are Black-image addresses.
 */
void func_0216D51C(u8 *p, u32 v)
{
    ((struct Obj17781 *)p)->f24 = v;
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
 *   python tools/match.py one --src src/matched/func_0216D520.c \
 *       --func func_0216D520 --addr 0x0216D520 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D520(void *p) { return ((struct Obj17782 *)p)->f24; }









/*
 * Unlabelled leaf: str r1, [r0, #0x28]; bx lr.
 */
void func_0216D524(void *p, void *v)
{
    ((struct Obj19121 *)p)->f28 = v;
}








/*
 * Getter: word at +0x28.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0216D528(u8 *p)
{
return ((struct Obj17783 *)p)->f28;
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
 *   python tools/match.py one --src src/matched/func_0216D52C.c \
 *       --func func_0216D52C --addr 0x0216D52C --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D52C(void *p) { return ((struct Obj17784 *)p)->f34; }








/*
 * Getter: word at +0x38.
 *
 * Addresses are Black-image addresses.
 */
void *func_0216D530(void *p)
{
    return ((struct Obj17785 *)p)->f38;
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
 *   python tools/match.py one --src src/matched/func_0216D534.c \
 *       --func func_0216D534 --addr 0x0216D534 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D534(void *p) { return ((struct Obj17786 *)p)->f3C; }









/*
 * Unlabelled leaf (no lr push): returns the halfword at the pointer held at +0x40, or 0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0216D538(u8 *p)
{
    u16 *q = *(u16 * *)&((struct Obj19122 *)p)->f40;
    if (q != 0)
        return *q;
    return 0;
}











unsigned int *func_0216D548(unsigned int *p, unsigned int v){
    *p |= v;
    return p;
}









u32 *func_0216D550(u32 *p, u32 v)
{
    *p &= ~v;
    return p;
}











int func_0216D55C(int a0, int a1)
{

a0 = ((struct Obj17788 *)((char *)a0))->f0;
a0 = a0 & a1;
    return a0;}









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D564.c \
 *       --func func_0216D564 --addr 0x0216D564 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D564(void *p) { return ((struct Obj17789 *)p)->f4; }









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Read-modify-write OR into a word field.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D568.c \
 *       --func func_0216D568 --addr 0x0216D568 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0216D568(void *p, u32 v) { ((struct Obj17790 *)p)->f4 |= v;  return p; }









char *func_0216D570(char *p, u32 v)
{
    ((struct Obj19125 *)p)->f4 &= ~v;
    return p;
}









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field mask test: load and return `field & mask`.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D57C.c \
 *       --func func_0216D57C --addr 0x0216D57C --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D57C(void *p, u32 v) { return ((struct Obj17791 *)p)->f4 & v; }









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D584.c \
 *       --func func_0216D584 --addr 0x0216D584 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D584(void *p, u16 v) { ((struct Obj17792 *)p)->f8 = v; }









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D588.c \
 *       --func func_0216D588 --addr 0x0216D588 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0216D588(void *p) { return ((struct Obj17793 *)p)->f8; }









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D58C.c \
 *       --func func_0216D58C --addr 0x0216D58C --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D58C(void *p, u16 v) { ((struct Obj17794 *)p)->fA = v; }









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D590.c \
 *       --func func_0216D590 --addr 0x0216D590 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0216D590(void *p) { return ((struct Obj17795 *)p)->fA; }









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D594.c \
 *       --func func_0216D594 --addr 0x0216D594 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D594(void *p, u32 v) { ((struct Obj17796 *)p)->fC = v; }









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D598.c \
 *       --func func_0216D598 --addr 0x0216D598 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0216D598(void *p) { return ((struct Obj17797 *)p)->fC; }









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D59C.c \
 *       --func func_0216D59C --addr 0x0216D59C --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D59C(void *p, u16 v) { ((struct Obj17798 *)p)->fE = v; }









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D5A0.c \
 *       --func func_0216D5A0 --addr 0x0216D5A0 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0216D5A0(void *p) { return ((struct Obj17799 *)p)->fE; }









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D5A4.c \
 *       --func func_0216D5A4 --addr 0x0216D5A4 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D5A4(void *p, u16 v) { ((struct Obj17800 *)p)->f10 = v; }








/*
 * Getter: halfword at +0x10.
 *
 * Addresses are Black-image addresses.
 */
u16 func_0216D5A8(u8 *p)
{
return ((struct Obj17801 *)p)->f10;
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
 *   python tools/match.py one --src src/matched/func_0216D5AC.c \
 *       --func func_0216D5AC --addr 0x0216D5AC --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D5AC(void *p, u16 v) { ((struct Obj17802 *)p)->f12 = v; }










/*
 * Reads the halfword field at +0x12.
 *
 * Addresses are Black-image addresses.
 */
u16 func_0216D5B0(u8 *p)
{
    return ((struct Obj17803 *)p)->f12;
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
 *   python tools/match.py one --src src/matched/func_0216D5B4.c \
 *       --func func_0216D5B4 --addr 0x0216D5B4 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D5B4(void *p, u16 v) { ((struct Obj17804 *)p)->f14 = v; }









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D5B8.c \
 *       --func func_0216D5B8 --addr 0x0216D5B8 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D5B8(void *p) { return ((struct Obj17805 *)p)->f14; }








int func_0216D5BC(void *p)
{
    return func_0216D5B8(p) == 0xFFFF;
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
 *   python tools/match.py one --src src/matched/func_0216D5D4.c \
 *       --func func_0216D5D4 --addr 0x0216D5D4 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D5D4(void *p) { return ((struct Obj17806 *)p)->f16; }











int func_0216D5D8(int a0, int a1)
{
    int a2;

a2 = ((struct Obj00113 *)a0)->f18;
((struct Obj00113 *)a0)->f1C = a2;
((struct Obj00113 *)a0)->f18 = a1;
    return a0;}









void func_0216D5E0(int a0, int a1)
{
    int t4;
    int t5;

t4 = a1 + 0;
a1 = 8;
t5 = a0 + 0;
    a0 = func_0216D55C(a0, a1);
loc_0216D5EC:
    if (a0 != 0) goto loc_0216D5F6;
loc_0216D5F0:
a0 = ((struct Obj00113 *)t5)->f18;
((struct Obj00113 *)t5)->f1C = a0;
((struct Obj00113 *)t5)->f18 = t4;
loc_0216D5F6:
    return;}









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D5F8.c \
 *       --func func_0216D5F8 --addr 0x0216D5F8 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0216D5F8(void *p) { return ((struct Obj17807 *)p)->f18; }









/*
 * Unlabelled leaf (halfword getter at +0x1c), filed as the only blocker of
 * func_021BBDD4 (ov021).
 */
u16 func_0216D5FC(void *p) { return ((struct Obj19126 *)p)->f1C; }











int func_0216D600(int a0, int a1){
    int a2;

a2 = ((struct Obj00113 *)a0)->f1A;
((struct Obj00113 *)a0)->f1E = a2;
((struct Obj00113 *)a0)->f1A = a1;
    return a0;}









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D608.c \
 *       --func func_0216D608 --addr 0x0216D608 --region ov010 --cc dsi/1.1p1 --thumb
 */
u16 func_0216D608(void *p) { return ((struct Obj17808 *)p)->f1A; }













int func_0216D60C(int a0, int a1)
{
    func_0216D5E0(a0, a1);
    return func_0216D600(a0, a1);
}















int func_0216D620(int a0, int a1, int a2)
{

    if (a2 == 0) goto loc_0216D62E;
loc_0216D624:
    if (a2 == 1) goto loc_0216D632;
loc_0216D628:
    if (a2 == 2) goto loc_0216D636;
loc_0216D62C:
    return a0;
loc_0216D62E:
((struct Obj00113 *)a0)->f20 = a1;
    return a0;
loc_0216D632:
((struct Obj00113 *)a0)->f22 = a1;
    return a0;
loc_0216D636:
((struct Obj00113 *)a0)->f24 = a1;
    return a0;}













/*
 * Recursive MATCH unblocker: dependency of func_0217C294 (ov018 tail-call
 * thunk), which unblocks func_0216AC90 and func_0216ACCC.
 */
int func_0216D63C(char *a0, int a1)
{
    switch (a1) {
    case 0:
        return ((struct Obj00113 *)a0)->f20;
    case 1:
        return ((struct Obj00113 *)a0)->f22;
    case 2:
        return ((struct Obj00113 *)a0)->f24;
    default:
        return 0;
    }
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
 *   python tools/match.py one --src src/matched/func_0216D65C.c \
 *       --func func_0216D65C --addr 0x0216D65C --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D65C(void *p, short v) { ((struct Obj17809 *)p)->f2C = v; }













/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D660.c \
 *       --func func_0216D660 --addr 0x0216D660 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D660(void *p) { return ((struct Obj17810 *)p)->f2C; }













/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D668.c \
 *       --func func_0216D668 --addr 0x0216D668 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D668(void *p, short v) { ((struct Obj17811 *)p)->f2E = v; }













/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D66C.c \
 *       --func func_0216D66C --addr 0x0216D66C --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D66C(void *p) { return ((struct Obj17812 *)p)->f2E; }












/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D674.c \
 *       --func func_0216D674 --addr 0x0216D674 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D674(void *p, u16 v) { ((struct Obj17813 *)p)->f2A = v; }












/*
 * Unlabelled leaf, blocker of ten ov021 callers: reads the halfword at +0x2A.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u16 func_0216D678(void *p)
{
    return ((struct Obj19127 *)p)->f2A;
}














void *func_0216D67C(void *a0)
{
    return ((struct Obj00113 *)a0)->f88;
}












void *func_0216D684(int a0, int a1, u32 a2, u32 a3)
{
    void *t4;
    int t5;

t5 = a1 + 0;
    t4 = func_0216D69C((void *)a0);
loc_0216D68C:
a1 = 0;
a2 = t5 + 0;
    a0 = func_02082BCC(t4, a1, a2);
loc_0216D696:
    return t4;}












/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Returns the address of an interior member (field address), pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D69C.c \
 *       --func func_0216D69C --addr 0x0216D69C --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0216D69C(void *p) { return (char *)p + 148; }












void *func_0216D6A0(int a0, int a1)
{
    int a2;
    void *t4;
    int t5;

t5 = a1 + 0;
    t4 = func_0216D6B8((void *)a0);
loc_0216D6A8:
a1 = 0;
a2 = t5 + 0;
    a0 = func_02082BCC(t4, a1, a2);
loc_0216D6B2:
    return t4;}












/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Returns the address of an interior member (field address), pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D6B8.c \
 *       --func func_0216D6B8 --addr 0x0216D6B8 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0216D6B8(void *p) { return (char *)p + 164; }












void *func_0216D6BC(int a0, int a1, int a2)
{
    void *t4;
    int t5;

t5 = a1 + 0;
    t4 = func_0216D6D4((void *)a0);
loc_0216D6C4:
a1 = 0;
a2 = t5 + 0;
    a0 = func_02082BCC(t4, a1, a2);
loc_0216D6CE:
    return t4;}












/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Returns the address of an interior member (field address), pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D6D4.c \
 *       --func func_0216D6D4 --addr 0x0216D6D4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0216D6D4(void *p) { return (char *)p + 180; }











void *func_0216D6D8(int a0, int a1)
{
    int a2;
    void *t4;
    int t5;

t5 = a1 + 0;
    t4 = func_0216D6F0((void *)a0);
loc_0216D6E0:
a1 = 0;
a2 = t5 + 0;
    a0 = func_02082BCC(t4, a1, a2);
loc_0216D6EA:
    return t4;}











/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Returns the address of an interior member (field address), pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D6F0.c \
 *       --func func_0216D6F0 --addr 0x0216D6F0 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0216D6F0(void *p) { return (char *)p + 196; }











/*
 * Indirect call through the entry the object's vtable pointer
 * holds, skipped when the slot is empty.
 */
void func_0216D6F4(void *a0)
{
    void (*fn)(void *) = *(void (**)(void *))((char *)((struct Obj17814 *)a0)->f8C + 0x4);

    if (fn != 0)
        fn(a0);
}











void func_0216D708(void *a0)
{
    void (*fn)(void *) = *(void (**)(void *))((char *)((struct Obj17816 *)a0)->f8C + 0x8);

    if (fn != 0)
        fn(a0);
}











int func_0216D71C(void *a0){
    void (*fn)(void *) = *(void (**)(void *))((char *)((struct Obj00113 *)a0)->f8C + 0xC);

    if (fn != 0)
        fn(a0);
}











void func_0216D730(void *a0)
{
    void (*fn)(void *) = *(void (**)(void *))((char *)((struct Obj12058 *)a0)->f8C + 0x10);

    if (fn != 0)
        fn(a0);
}













void func_0216D744(void *a0)
{
    void (*fn)(void *) = *(void (**)(void *))((struct Obj00113 *)a0)->f90;

    if (fn != 0)
        fn(a0);
}











void func_0216D758(void *a0)
{
    void (*fn)(void *) = *(void (**)(void *))((char *)((struct Obj00113 *)a0)->f90 + 0x4);

    if (fn != 0)
        fn(a0);
}











int func_0216D76C(void *a0){
    void (*fn)(void *) = *(void (**)(void *))((char *)((struct Obj00113 *)a0)->f90 + 0x8);

    if (fn != 0)
        fn(a0);
}











void func_0216D780(void *a0)
{
    void (*fn)(void *) = *(void (**)(void *))((char *)((struct Obj00113 *)a0)->f90 + 0xC);

    if (fn != 0)
        fn(a0);
}











void func_0216D794(void *a0)
{
    void (*fn)(void *) = *(void (**)(void *))((char *)((struct Obj12058 *)a0)->f90 + 0x10);

    if (fn != 0)
        fn(a0);
}










int func_0216D7A8(void *p, unsigned int v)
{
    Callback f;
    f = *(Callback *)&((struct Obj19128 *)((char *)((struct Obj00113 *)p)->f90))->f14;
    if (f != 0)
        return f(p, v);
    return 0;
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
 *   python tools/match.py one --src src/matched/func_0216D7C0.c \
 *       --func func_0216D7C0 --addr 0x0216D7C0 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D7C0(void *p, u16 v) { ((struct Obj17824 *)p)->f26 = v; }












/*
 * Reads the halfword field at +0x26.
 *
 * Addresses are Black-image addresses.
 */
u16 func_0216D7C4(u8 *p)
{
    return ((struct Obj17825 *)p)->f26;
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
 *   python tools/match.py one --src src/matched/func_0216D7C8.c \
 *       --func func_0216D7C8 --addr 0x0216D7C8 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0216D7C8(void *p, u16 v) { ((struct Obj17826 *)p)->f28 = v;  return p; }











/*
 * Increments the halfword at +0x28 of the object in r0.
 *
 * Filed as the TARGET of 27 ov021 `bl` sites (rule 10): ov010's listing emits
 * these 8 bytes as a `.word` because nothing traced an entry point here -- its
 * only callers are the ov021 sites -- so no `label` witness exists anywhere and
 * a region hint cannot invent one.  The source is the witness.
 *
 * Addresses are Black-image addresses.
 */
void func_0216D7CC(u8 *p)
{
    ((struct Obj00113 *)p)->f28 = ((struct Obj00113 *)p)->f28 + 1;
}












/*
 * Reads the halfword field at +0x28.
 *
 * Addresses are Black-image addresses.
 */
u16 func_0216D7D4(u8 *p)
{
    return ((struct Obj17827 *)p)->f28;
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
 *   python tools/match.py one --src src/matched/func_0216D7D8.c \
 *       --func func_0216D7D8 --addr 0x0216D7D8 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D7D8(void *p, u32 v) { ((struct Obj17828 *)p)->f74 = v; }











/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D7DC.c \
 *       --func func_0216D7DC --addr 0x0216D7DC --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D7DC(void *p) { return ((struct Obj17829 *)p)->f74; }











/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D7E0.c \
 *       --func func_0216D7E0 --addr 0x0216D7E0 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D7E0(void *p, u32 v) { ((struct Obj17830 *)p)->f78 = v; }











/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D7E4.c \
 *       --func func_0216D7E4 --addr 0x0216D7E4 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D7E4(void *p) { return ((struct Obj17831 *)p)->f78; }











/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D7E8.c \
 *       --func func_0216D7E8 --addr 0x0216D7E8 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D7E8(void *p) { return ((struct Obj17832 *)p)->f30; }











/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D7F0.c \
 *       --func func_0216D7F0 --addr 0x0216D7F0 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D7F0(void *p, short v) { ((struct Obj17833 *)p)->f30 = v; }











/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D7F4.c \
 *       --func func_0216D7F4 --addr 0x0216D7F4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D7F4(void *p, short v) { ((struct Obj17834 *)p)->f32 = v; }











/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D7F8.c \
 *       --func func_0216D7F8 --addr 0x0216D7F8 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D7F8(void *p) { return ((struct Obj17835 *)p)->f34; }











/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D800.c \
 *       --func func_0216D800 --addr 0x0216D800 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D800(void *p, short v) { ((struct Obj17836 *)p)->f34 = v; }











/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D804.c \
 *       --func func_0216D804 --addr 0x0216D804 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D804(void *p) { return ((struct Obj17837 *)p)->f36; }











/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D80C.c \
 *       --func func_0216D80C --addr 0x0216D80C --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D80C(void *p, s16 v) { ((struct Obj17838 *)p)->f36 = v; }











/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D810.c \
 *       --func func_0216D810 --addr 0x0216D810 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D810(void *p) { return ((struct Obj17839 *)p)->f38; }











/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D818.c \
 *       --func func_0216D818 --addr 0x0216D818 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D818(void *p, s16 v) { ((struct Obj17840 *)p)->f38 = v; }











/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D81C.c \
 *       --func func_0216D81C --addr 0x0216D81C --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D81C(void *p) { return ((struct Obj17841 *)p)->f3A; }











/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D824.c \
 *       --func func_0216D824 --addr 0x0216D824 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D824(void *p, s16 v) { ((struct Obj17842 *)p)->f3A = v; }











/*
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as the sole blocker of ov018 func_0217BDE0: copies the three
 * s16 at +0x3C/+0x3E/+0x40 out to a caller's vector.
 */
void func_0216D828(u8 *p, Vec3s *out)
{
    out->x = ((struct Obj00113 *)p)->f3C;
    out->y = ((struct Obj00113 *)p)->f3E;
    out->z = ((struct Obj00113 *)p)->f40;
}











/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D83C.c \
 *       --func func_0216D83C --addr 0x0216D83C --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D83C(void *p) { return ((struct Obj17843 *)p)->f3C; }










/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D844.c \
 *       --func func_0216D844 --addr 0x0216D844 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D844(void *p, short v) { ((struct Obj17844 *)p)->f3C = v; }










void func_0216D848(char *p, short v)
{
    ((struct Obj19129 *)p)->f3C += v;
}










/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D854.c \
 *       --func func_0216D854 --addr 0x0216D854 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D854(void *p) { return ((struct Obj17845 *)p)->f3E; }










/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Halfword-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D85C.c \
 *       --func func_0216D85C --addr 0x0216D85C --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D85C(void *p, int v) { ((struct Obj17846 *)p)->f3E = v; }










/*
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as a blocker of ov021 func_0219912C.
 */
void func_0216D860(char *p, short v)
{
    ((struct Obj19130 *)p)->f3E += v;
}










/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Signed-halfword field getter; the compiler picks `movs r1,#N; ldrsh r0,[r0,r1]` rather than the immediate form.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D86C.c \
 *       --func func_0216D86C --addr 0x0216D86C --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216D86C(void *p) { return ((struct Obj17847 *)p)->f40; }












void func_0216D874(int a0, int a1)
{

a0 = a0 + 0x40;
((struct Obj17848 *)((char *)a0))->f0 = a1;
    return;}










void func_0216D87C(char *p, short v)
{
    ((struct Obj19131 *)p)->f40 += v;
}










/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Returns the address of an interior member (field address), pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D888.c \
 *       --func func_0216D888 --addr 0x0216D888 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0216D888(void *p) { return (char *)p + 68; }










/*
 * Copy an actor's position out (the getter of func_0216D89C).
 */
void func_0216D88C(const struct Actor *a, struct VecFx32_0216C2FC *out){
    *out = a->pos;
}










/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Twelve-byte struct copy between an interior member of the
 * object and a caller-supplied 3-word record: the compiler
 * emits ldm/stm plus the odd word.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D89C.c \
 *       --func func_0216D89C --addr 0x0216D89C --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D89C(void *p, const Triple *q)
{
    *(Triple *)((char *)p + 68) = *q;
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
 *   python tools/match.py one --src src/matched/func_0216D8AC.c \
 *       --func func_0216D8AC --addr 0x0216D8AC --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_0216D8AC(void *p) { return ((struct Obj17849 *)p)->f48; }











/*
 * Copies a 12-byte record from p + 0x50 into q.
 *
 * Addresses are Black-image addresses.
 */
void func_0216D8B0(u8 *p, u8 *q)
{
    *(S12 *)q = *(S12 *)(p + 0x50);
}










/*
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as a blocker of ov018 func_0217BCDC: copies a 12-byte vector
 * into the object at +0x50.
 */
void func_0216D8C0(u8 *p, const Vec *v)
{
    *(Vec *)(p + 0x50) = *v;
}











/*
 * Copies a 12-byte record from p + 0x5c into q.
 *
 * Addresses are Black-image addresses.
 */
void func_0216D8D0(u8 *p, u8 *q)
{
    *(S12 *)q = *(S12 *)(p + 0x5c);
}










/*
 * Unlabelled leaf (no lr save): copies a 12-byte record into the object at
 * +0x5c.  Filed as the sole blocker of ov021 func_021A3DA0.
 */
void func_0216D8E0(u8 *p, Rec12 *src)
{
    *(Rec12 *)(p + 0x5c) = *src;
}











/*
 * Copies a 12-byte record from p + 0x68 into q.
 *
 * Addresses are Black-image addresses.
 */
void func_0216D8F0(u8 *p, u8 *q)
{
    *(S12 *)q = *(S12 *)(p + 0x68);
}









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Twelve-byte struct copy between an interior member of the
 * object and a caller-supplied 3-word record: the compiler
 * emits ldm/stm plus the odd word.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216D900.c \
 *       --func func_0216D900 --addr 0x0216D900 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216D900(void *p, const Triple *q)
{
    *(Triple *)((char *)p + 104) = *q;
}









int func_0216D910(int a0)
{

    a0 = (int)func_0216D67C((void *)a0);
loc_0216D916:
    a0 = func_0216D520((void *)a0);
loc_0216D91A:
    return a0;}











u8 func_0216D91C(int a0)
{

a0 = a0 + 0x7c;
a0 = ((struct Obj17850 *)((char *)a0))->f0;
    return a0;}











u8 func_0216D924(int a0)
{

a0 = a0 + 0x7d;
a0 = ((struct Obj17851 *)((char *)a0))->f0;
    return a0;}









/*
 * Unlabelled leaf: widens three signed bytes at p + 0x7e..0x80 to fixed
 * point (<< 12) and stores them into q[0..2].
 *
 * Addresses are Black-image addresses.
 */
void func_0216D92C(u8 *p, s32_0216D900 *q)
{
    q[0] = ((struct Obj09334 *)p)->f7E << 12;
    q[1] = ((struct Obj09334 *)p)->f7F << 12;
    q[2] = ((struct Obj09334 *)p)->f80 << 12;
}









int func_0216D948(int a0)
{
    int a1;
    int t4;

a1 = 1;
t4 = 1;
    a0 = func_0216D4D4(a0, a1);
loc_0216D952:
    if (a0 != 0) goto loc_0216D958;
loc_0216D956:
t4 = 0;
loc_0216D958:
a0 = t4 + 0;
    return a0;}








void func_0216D95C(unsigned int *p, unsigned int v, int a2)
{
    if (v == 1) func_0216D4DC(p, 1);
    else func_0216D4E4(p, 1);
}








void func_0216D974(unsigned int *p, unsigned int v, int a2)
{
    if (v == 0) func_0216D4DC(p, 8);
    else func_0216D4E4(p, 8);
}









int func_0216D98C(int a0)
{
    int a1;
a1 = 8;
    a0 = func_0216D4D4(a0, a1);
loc_0216D994:
    if (a0 != 0) goto loc_0216D99C;
loc_0216D998:
a0 = 1;
    return a0;
loc_0216D99C:
a0 = 0;
    return a0;}

















void func_0216D9A0(void *map)
{
    u32 pos = 0;
    void *it;

    while (func_0216DD1C(map, (struct Rec_0216D9A0 **)(&it), &pos) == 1) {
        if (func_0216DC80(it) == 0)
            func_0216DAF8(it);
    }
    func_0216D4DC(map, 0x20);
}

















/*
 * Releases every record func_0216DD1C yields, then func_0216D4E4(c, 0x20).
 */
u32 *func_0216D9E4(void *c)
{
    u32 iter;
    void *r;

    iter = 0;
    while (func_0216DD1C(c, (struct Rec_0216D9A0 **)(&r), &iter) == 1)
        func_0216DB04(r);
    return func_0216D4E4(c, 0x20);
}
















int func_0216DA20(void *p, unsigned int v)
{
    return func_0216D4D4((int)func_0216D67C(p), v);
}

















int func_0216DA30(int a0)
{
    int t4;
    int a1;

a1 = 1;
t4 = 1;
    a0 = func_0216D55C(a0, a1);
loc_0216DA3A:
    if (a0 != 0) goto loc_0216DA40;
loc_0216DA3E:
t4 = 0;
loc_0216DA40:
a0 = t4 + 0;
    return a0;}


















/*
 * Tail call to func_0216D568 with a masked second argument.
 *
 * Addresses are Black-image addresses.
 */
void func_0216DA44(u32 a)
{
    func_0216D568((void *)a, 0x10);
}

















/*
 * Thin wrapper: clear bit 4 of the word at +4 (tail call to func_0216D570).
 *
 * Addresses are Black-image addresses.
 */
void func_0216DA50(u8 *p)
{
func_0216D570((char *)p, 0x10);
}

















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DA5C.c \
 *       --func func_0216DA5C --addr 0x0216DA5C --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DA5C(void *a0)
{
    if (func_0216D57C(a0, 16))
        return 1;
    return 0;
}

















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216D568, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DA70.c \
 *       --func func_0216DA70 --addr 0x0216DA70 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216DA70(void *a0)
{

    func_0216D568(a0, 32);
}

















/*
 * Thin wrapper: clear bit 6 of the word at +4 (tail call to func_0216D570).
 *
 * Addresses are Black-image addresses.
 */
void func_0216DA7C(u8 *p)
{
func_0216D570((char *)p, 0x40);
}

















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216D568, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DA88.c \
 *       --func func_0216DA88 --addr 0x0216DA88 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216DA88(void *a0)
{

    func_0216D568(a0, 2);
}

















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216D570, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DA94.c \
 *       --func func_0216DA94 --addr 0x0216DA94 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216DA94(void *a0)
{

    func_0216D570(a0, 2);
}

















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DAA0.c \
 *       --func func_0216DAA0 --addr 0x0216DAA0 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DAA0(void *a0)
{
    if (func_0216D57C(a0, 2))
        return 1;
    return 0;
}

















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DAB4.c \
 *       --func func_0216DAB4 --addr 0x0216DAB4 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DAB4(void *a0)
{
    if (func_0216D55C((int)a0, 4))
        return 1;
    return 0;
}
















void func_0216DAC8(unsigned int *p, unsigned int v)
{
    if (v == 1) func_0216D548(p, 4);
    else func_0216D550(p, 4);
}
















void func_0216DAE0(unsigned int *p, unsigned int v)
{
    if (v == 1) func_0216D550(p, 128);
    else func_0216D548(p, 128);
}

















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216D568, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DAF8.c \
 *       --func func_0216DAF8 --addr 0x0216DAF8 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216DAF8(void *a0)
{

    func_0216D568(a0, 8);
}

















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216D570, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DB04.c \
 *       --func func_0216DB04 --addr 0x0216DB04 --region ov010 --cc dsi/1.1p1 --thumb
 */
char *func_0216DB04(void *a0)
{

    return func_0216D570(a0, 8);
}

















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DB10.c \
 *       --func func_0216DB10 --addr 0x0216DB10 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DB10(void *a0)
{
    if (func_0216D57C(a0, 8))
        return 1;
    return 0;
}

















int func_0216DB24(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = (int)func_0216D67C((void *)a0);
loc_0216DB2C:
    a0 = func_0216D948(a0);
loc_0216DB30:
    if (a0 != 0) goto loc_0216DB38;
loc_0216DB34:
a0 = 0;
    return a0;
loc_0216DB38:
a0 = t4 + 0;
    a0 = func_0216DAA0((void *)a0);
loc_0216DB3E:
    if (a0 == 0) goto loc_0216DB46;
loc_0216DB42:
a0 = 1;
    return a0;
loc_0216DB46:
a0 = 0;
    return a0;}

















/*
 * The first argument picks which of the pair of field setters
 * takes the shifted mask and the value.
 */
int func_0216DB4C(void *a0, int a1)
{
    if (a1 == 1)
        return (int)func_0216D548(a0, 0x200);

    return (int)func_0216D550(a0, 0x200);
}

















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DB68.c \
 *       --func func_0216DB68 --addr 0x0216DB68 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DB68(void *a0)
{
    if (func_0216D55C((int)a0, 512))
        return 1;
    return 0;
}
















void func_0216DB80(unsigned int *p, unsigned int v)
{
    if (v == 1) func_0216D548(p, 32);
    else func_0216D550(p, 32);
}

















int func_0216DB98(void *a0, int a1)
{
    int a2;
    if (a1 == 1)
        return (int)func_0216D548(a0, 0x800);

    return (int)func_0216D550(a0, 0x800);
}

















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DBB4.c \
 *       --func func_0216DBB4 --addr 0x0216DBB4 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DBB4(void *a0)
{
    if (func_0216D55C((int)a0, 2048))
        return 1;
    return 0;
}

















int func_0216DBCC(void *a0, u32 a1, int a2)
{
    if (a1 == 1)
        return (int)func_0216D568(a0, 0x40000);

    return (int)func_0216D570(a0, 0x40000);
}

















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DBE8.c \
 *       --func func_0216DBE8 --addr 0x0216DBE8 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DBE8(void *a0)
{
    if (func_0216D57C(a0, 262144))
        return 1;
    return 0;
}
















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DC00.c \
 *       --func func_0216DC00 --addr 0x0216DC00 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DC00(void *a0)
{
    if (func_0216D55C((int)a0, 4096))
        return 1;
    return 0;
}
















int func_0216DC18(void *a0, int a1)
{
    int a2;
    if (a1 == 1)
        return (int)func_0216D568(a0, 0x20000);

    return (int)func_0216D570(a0, 0x20000);
}
















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DC34.c \
 *       --func func_0216DC34 --addr 0x0216DC34 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DC34(void *a0)
{
    if (func_0216D57C(a0, 131072))
        return 1;
    return 0;
}
















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DC4C.c \
 *       --func func_0216DC4C --addr 0x0216DC4C --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DC4C(void *a0)
{
    if (func_0216D57C(a0, 512))
        return 1;
    return 0;
}
















int func_0216DC64(void *a0, int a1)
{
    int a2;
    if (a1 == 1)
        return (int)func_0216D568(a0, 0x80000);

    return (int)func_0216D570(a0, 0x80000);
}
















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DC80.c \
 *       --func func_0216DC80 --addr 0x0216DC80 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DC80(void *a0)
{
    if (func_0216D57C(a0, 524288))
        return 1;
    return 0;
}
















int func_0216DC98(void *a0, int a1)
{
    int a2;
    if (a1 == 1)
        return (int)func_0216D548(a0, 0x400);

    return (int)func_0216D550(a0, 0x400);
}
















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DCB4.c \
 *       --func func_0216DCB4 --addr 0x0216DCB4 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DCB4(void *a0)
{
    if (func_0216D55C((int)a0, 1024))
        return 1;
    return 0;
}















int func_0216DCCC(void *a0, int a1)
{
    int a2;
    if (a1 == 1)
        return (int)func_0216D568(a0, 0x100000);

    return (int)func_0216D570(a0, 0x100000);
}















int func_0216DCE8(void *a0, int a1)
{
    int a2;
    if (a1 == 1)
        return (int)func_0216D568(a0, 0x200000);

    return (int)func_0216D570(a0, 0x200000);
}















/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DD04.c \
 *       --func func_0216DD04 --addr 0x0216DD04 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DD04(void *a0)
{
    if (func_0216D57C(a0, 2097152))
        return 1;
    return 0;
}















/*
 * Iterator: advances *iter over the 0x100-byte records at +0x18 and
 * returns TRUE with *out set at the next record func_0216D55C accepts.
 */
int func_0216DD1C(struct Ctx *c, struct Rec_0216D9A0 **out, u32 *iter){
    u32 n;
    Rec_0216D9A0 *r;

    n = func_0216D4F0(c);
    if (*iter < n) {
        r = &c->recs[*iter];
        do {
            (*iter)++;
            if (func_0216D55C((int)r, 1)) {
                *out = r;
                return 1;
            }
            r++;
        } while (*iter < n);
    }
    return 0;
}













/*
 * Collects up to 16 matching objects into a 0x44-byte result block
 * (count word, then the pointers).
 */
int func_0216DD60(u32 x, u32 b, u32 c, u32 d, List *out)
{
    int n;
    u8 *o;

    n = 0;
    func_02082BCC(out, 0, 0x44);
    while (func_0216DD1C((struct Ctx *)x, (struct Rec_0216D9A0 **)(&o), (u32 *)(&n)) == 1) {
        if (func_02163C04((int)o, b, c, d) == 1) {
            int i = out->n++;
            out->e[i] = o;
            if (out->n >= 16)
                break;
        }
    }
    return out->n;
}











void *func_0216DDC0(u32 a, u32 b, u32 c, u32 d)
{
    List out;
    if (func_0216DD60(a, b, c, d, &out) != 0)
        return out.e[0];
    return 0;
}












u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d)
{
    List buf;
    u32 i;
    u32 n;

    n = func_0216DD60(a, b, c, d, &buf);
    if (n == 0)
        return 0;
    for (i = 0; i < n; i++) {
        s32 q = func_0216D8AC(buf.e[i]) - x;

        if (q < 0)
            q = (s32)(((s64)q * (s64)(s32)0xFFFFF000 + 0x800) >> 12);
        if (q < lim)
            return buf.e[i];
    }
    return 0;
}












/*
 * First object of the given kind in the map (func_0216DD1C walks it),
 * or NULL.
 */
void *func_0216DE54(void *map, u32 kind)
{
    u32 iter;
    void *obj;

    iter = 0;
    while (func_0216DD1C(map, (struct Rec_0216D9A0 **)(&obj), &iter) == 1) {
        if (func_0216D5A0(obj) == kind)
            return obj;
    }
    return 0;
}












/*
 * First free object (func_0216DBB4 zero) with the given id in the map,
 * or NULL (func_0216DE54 is the by-kind twin).
 */
void *func_0216DE94(void *map, u32 id)
{
    u32 iter;
    void *obj;

    iter = 0;
    while (func_0216DD1C(map, (struct Rec_0216D9A0 **)(&obj), &iter) == 1) {
        if (func_0216DBB4(obj) == 0 && func_0216D588(obj) == id)
            return obj;
    }
    return 0;
}











/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216DE94, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DEE0.c \
 *       --func func_0216DEE0 --addr 0x0216DEE0 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0216DEE0(void *a0)
{
    return func_0216DE94(a0, 255);
}











int func_0216DEEC(int a0)
{
    int a1;
    int t4;
    int t5;
    int t6;
    int t7;

t5 = a0 + 0;
t4 = 0;
    a0 = func_0216D4F0((void *)a0);
loc_0216DEF6:
t7 = 1;
t5 = ((struct Obj17852 *)t5)->f18;
t6 = a0 + 0;
t7 = t7 << 8;
loc_0216DEFE:
a0 = t5 + 0;
a1 = 1;
    a0 = func_0216D55C(a0, a1);
loc_0216DF06:
    if (a0 != 0) goto loc_0216DF0E;
loc_0216DF0A:
a0 = t5 + 0;
    return a0;
loc_0216DF0E:
t4 = t4 + 1;
t5 = t5 + t7;
    if (t4 < t6) goto loc_0216DEFE;
loc_0216DF16:
a0 = 0;
    return a0;}











void func_0216DF1C(u32 x)
{
    int n;
    u8 *o;
    u32 k = 0x20;

    n = 0;
    while (func_0216DD1C((struct Ctx *)x, (struct Rec_0216D9A0 **)(&o), (u32 *)(&n))) {
        if (func_0216D55C((int)o, k) == 0) {
            func_0216D588(o);
            func_0216CF2C((int)o);
        }
    }
}











void func_0216DF64(u8 *o, u32 b)
{
    int d = 0;
    int base = func_0216D4F4((void *)b);
    int t = func_0216D5A0(o);

    if (t == 0x30 || t == 0x32)
        d = 1;
    else if (func_0216D588(o) == 0xff)
        d--;
    ((struct Obj19133 *)o)->f84 = func_02030DA8(func_0216D514((void *)b), (int)func_0216D3A8, (int)o, base + d);
}











int func_0216DFAC(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = a0 + 0x84;
a0 = *(int *)&((struct Obj00113 *)((char *)a0))->f0;
    if (a0 == 0) goto loc_0216DFC2;
loc_0216DFB8:
    a0 = func_02030EAC(a0);
loc_0216DFBC:
a0 = 0;
t4 = t4 + 0x84;
*(int *)&((struct Obj00113 *)((char *)t4))->f0 = a0;
loc_0216DFC2:
    return a0;}











int func_0216DFC4(void *a, u32 id)
{
    u32 iter = 0;
    void *out;
    void *ctx;

    ctx = func_0216D67C(a);
    while (func_0216DD1C(ctx, (struct Rec_0216D9A0 **)(&out), &iter) == 1) {
        if (out != a) {
            u32 v = func_0216D598(out);
            if (v != 0xFFFF && v == id)
                return 1;
        }
    }
    return 0;
}











void func_0216E014(void *a, int *p, int b)
{
    func_0216D844(a, (s16_0216DEE0)((p[0] >> 4) / 4096));
    func_0216D85C(a, (s16_0216DEE0)((p[1] >> 4) / 4096));
    func_0216D874((int)a, (s16_0216DEE0)((p[2] >> 4) / 4096));
    func_0216D89C(a, (const Triple *)p);
    func_02163F10((int)a);
    func_0216D5D8((int)a, b);
    func_0216D4B4(a);
    func_0216D568(a, 0x20);
    func_0216D570(a, 0x50);
}










void func_0216E084(void *a, unsigned int x, unsigned int y, unsigned int z, u16 k) { int p[3]; p[0]=(x<<16)+0x8000; p[1]=y<<16; p[2]=(z<<16)+0x8000; func_0216E014(a,p,k); }









void func_0216E0AC(void *a0, void *a1)
{
    void *t4;
    void *t5;
    int t6;

t5 = a0;
t4 = a1;
    t6 = (int)func_0216D67C(a0);
loc_0216E0B6:
    func_0216D71C(t5);
loc_0216E0BE:
    func_0216CFC4((int)t5, (int)t4);
loc_0216E0C6:
    func_0216D02C((int)t5, t4);
loc_0216E0CE:
    func_0216D230((int)t5);
loc_0216E0D4:
    func_0216D268(t6, (int)t5);
loc_0216E0DC:
    func_0216D0E8((int)t5, (u8 *)t4, 0);
loc_0216E0E6:
    return;}














int func_0216E0E8(int a0, u16 a1)
{
    int t6;

    t6 = (int)func_0216D67C((void *)a0);
    func_0216D71C((void *)a0);
    func_0216D59C((void *)a0, a1);
    func_0216D230(a0);
    return func_0216D268(t6, a0);
}















/*
 * blocked:  listing 76 compiled 74
 */
void func_0216E114(void *obj)
{
    if (func_0216D948((int)func_0216D67C(obj)) == 0)
        return;
    if (func_0216D57C(obj, 1 << 12) != 0)
        func_02164010((int)obj);
    func_0216D674(obj, 0);
    if (func_0216DAA0(obj) != 0)
        return;
    func_0216E160((int)obj);
    func_0216D744(obj);
    func_0216DA88(obj);
}















int func_0216E160(int a0)
{
    int t4;
    void *p;

t4 = a0 + 0;
    p = func_0216E3C4((void *)a0);
loc_0216E168:
a0 = ((struct Obj17854 *)p)->f3;
    a0 = func_0216E40C(a0);
loc_0216E16E:
t4 = t4 + 0x90;
((struct Obj17853 *)((char *)t4))->f0 = a0;
    return a0;}














/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216D570, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216E174.c \
 *       --func func_0216E174 --addr 0x0216E174 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216E174(void *a0)
{

    func_0216D570(a0, 442368);
}














/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_02082BCC, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216E180.c \
 *       --func func_0216E180 --addr 0x0216E180 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216E180(void *a0){

    func_02082BCC(a0, 0, 256);
}













void func_0216E190(void *a) { func_0216D568(a, 0x20); func_0216E174(a); }














int func_0216E1A4(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_0216D588((void *)a0);
loc_0216E1AE:
((struct Obj09167 *)((char *)t4))->f0 = a0;
a0 = t5 + 0;
    a0 = func_0216D598((void *)a0);
loc_0216E1B6:
((struct Obj09167 *)t4)->f2 = a0;
a0 = t5 + 0;
    a0 = func_0216D590((void *)a0);
loc_0216E1BE:
((struct Obj09167 *)t4)->f4 = a0;
    return a0;}














int func_0216E1C4(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t4 = a1 + 0;
a1 = 1;
t5 = a0 + 0;
t6 = 1;
    a0 = func_0216D55C(a0, a1);
loc_0216E1D2:
    if (a0 == 0) goto loc_0216E1FE;
loc_0216E1D6:
a0 = t5 + 0;
    a0 = func_0216D588((void *)a0);
loc_0216E1DC:
a1 = ((struct Obj09168 *)((char *)t4))->f0;
    if (a1 != a0) goto loc_0216E1FE;
loc_0216E1E2:
a0 = t5 + 0;
    a0 = func_0216D598((void *)a0);
loc_0216E1E8:
a1 = ((struct Obj09168 *)t4)->f2;
    if (a1 != a0) goto loc_0216E1FE;
loc_0216E1EE:
a0 = t5 + 0;
    a0 = func_0216D590((void *)a0);
loc_0216E1F4:
a1 = ((struct Obj09168 *)t4)->f4;
    if (a1 != a0) goto loc_0216E1FE;
loc_0216E1FA:
a0 = t6 + 0;
    return a0;
loc_0216E1FE:
a0 = 0;
    return a0;}













void func_0216E204(char *a, u32 v)
{
    void *ctx;
    char *p;

    ctx = func_0216D67C(a);
    if (func_0216D948((int)ctx) == 1 && func_0216DAA0(a) == 1)
        func_0216D76C(a);
    func_0216D594(a, v);
    func_0216E39C((const char *)ctx, v, (u8 *)a);
    p = a + 0xe4;
    ((struct Obj00113 *)a)->f7C = ((struct Obj05908 *)p)->fB;
    ((struct Obj00113 *)a)->f7D = ((struct Obj05908 *)p)->fC;
    *(s8 *)&((struct Obj00113 *)a)->f7E = ((struct Obj05908 *)p)->fD;
    *(s8 *)&((struct Obj00113 *)a)->f7F = ((struct Obj05908 *)p)->fE;
    *(s8 *)&((struct Obj00113 *)a)->f80 = ((struct Obj05908 *)p)->fF;
    func_0216DA94(a);
    func_0216E190(a);
    func_0216E114(a);
}













/*
 * blocked:  listing 16 compiled 14
 */
void *func_0216E280(int a0, int a1)
{
    int t4;
    void *p;

t4 = a0 + 0;
    p = func_020490F4(0x30, a1);
loc_0216E28A:
((struct Obj17855 *)t4)->f14 = p;
    return p;}













/*
 * Forwards the pointer at +0x14 to the arm9 routine at 0x02049238.
 */
int func_0216E290(char *p){
    func_02049238(((struct Obj19134 *)p)->f14);
}













/*
 * Unlabelled leaf (saves no lr, so disasm.py prints it as .word data):
 * a tail call through a pool word, the sole blocker of ov020 func_021857C0.
 */
void func_0216E29C(Obj *o, int v)
{
    func_02048F4C(o->f44, 0x3a, v);
}












/*
 * Unlabelled leaf, blocker of ov021 func_0219C680: copies record i (28 bytes) from the table at +0x44.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
void func_0216E2AC(void *p, u32 i, Rec_0216E0E8 *out)
{
    u16 *t = *(u16 * *)&((struct Obj12404 *)p)->f44;

    if (i < t[0]) {
        u16 k = (t[0] + 1) / 2 * 2;
        Rec_0216E0E8 *r = (Rec_0216E0E8 *)(t + (k + 2));

        *out = r[i];
    }
}












/*
 * Unlabelled leaf, blocker of ov021 func_0219C680: count halfword of the table at +0x44.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u16 func_0216E2E0(void *p)
{
    return **(u16 * *)&((struct Obj12404 *)p)->f44;
}










/*
 * Direct halfword-aligned 28-byte Record assignments restore ctx=r5/id=r4/out=r6.
 * A named u16 offset and const context parameter restore the last stack store.
 * func_0216DD1C 0x0216DD1C thumb ov010
 * func_0216D598 0x0216D598 thumb ov010
 * func_0200F128 0x0200F128 thumb
 * func_0204944C 0x0204944C arm
 */
void func_0216E2E8(const char *ctx, u32 id, Record *out)
{
    u16 offset;
    int i;
    u32 j;
    u16 n;
    u16 *tbl;
    u32 iter;
    void *rec;

    tbl = *(u16 * *)&((struct Obj12405 *)ctx)->f44;
    n = tbl[0];

    if (n < 0x1a) {
        u16 k = ((n + 1) / 2) * 2;
        char *recs = (char *)tbl + (k + 2) * 2;
        for (i = 0; i < n; i++) {
            if (id == tbl[i + 1]) {
                u16 *src = (u16 *)(recs + i * 0x1c);
                *out = *(Record *)src;
                return;
            }
        }
    }
    iter = 0;
    if (func_0216DD1C((void *)ctx, (struct Rec_0216D9A0 **)(&rec), &iter)) {
        do {
            if (id == func_0216D598(rec)) {
                u16 *src = (u16 *)((char *)rec + 0xe4);
                *out = *(Record *)src;
                return;
            }
        } while (func_0216DD1C((void *)ctx, (struct Rec_0216D9A0 **)(&rec), &iter));
    }
    offset = func_0200F128(id) * 0x1c + 4;
    func_0204944C(((struct Obj12405 *)ctx)->f14, 0, offset, 0x1c, out);
}











void func_0216E39C(const char *ctx, u32 id, u8 *w)
{
    func_0216D550((u32 *)w, 1);
    func_0216E2E8(ctx, id, (Record *)(w + 0xe4));
    func_0216D548((u32 *)w, 1);
}











/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Returns the address of an interior member (field address), pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216E3C4.c \
 *       --func func_0216E3C4 --addr 0x0216E3C4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0216E3C4(void *p) { return (char *)p + 228; }










/*
 * Unlabelled leaf: adds r0, #0x10; bx lr.
 */
void *func_0216E3C8(void *p)
{
    return (char *)p + 0x10;
}











/*
 * Unlabelled leaf: returns its argument plus 0x10.
 *
 * Addresses are Black-image addresses.
 */
u8 *func_0216E3CC(u8 *p)
{
    return p + 0x10;
}











/*
 * Unlabelled thumb tail-call stub (ldr r3,[pc,#0]; bx r3; .word 0x0216E3D9);
 * the sole blocker of ov021 func_021B181C.
 */
int func_0216E3D0(int a, int b)
{
    return func_0216E3D8(a, b);
}










unsigned int func_0216E3D8(unsigned int a, unsigned int id) { if (id>=162 && id<=177) { if(a==0) id=10; else id=*(u16 *)func_020143CC(a,(u16)(id+0x3f7e)); } return id; }











/*
 * note: un-hinted, sole-ref/data sees several overlays over 0x021D5E04 and
 * refuses.  ov021 is the only one with data there (a pointer table after a
 * zero word at 0x021D5E00); ov093, ov016 and the rest hold code.  ov021 is
 * resident with ov010: ov010 branches straight into 62 ov021 functions
 * (bl 0x021C3400 and others).  The ov021 hint fixes the choice.
 */
u32 func_0216E400(int i)
{
    return d_021D5E04[i];
}











/*
 * note: the parked file gave no overlay hint; un-hinted, sole-ref saw data at
 * 0x021D770C in several overlapping overlays and refused.  ov021 is the
 * pointer-table home of the word (the ov021 datum is 0x021D86C0), so the hint
 * fixes the choice and the site resolves as sole-ref/self.
 */
u32 func_0216E40C(int i)
{
    return d_021D770C[i];
}










int func_0216E418(void *a) { if (((struct Obj19137 *)a)->fA==65535) return 1; return 0; }











/*
 * Tail call thunk: forwards its arguments unchanged to 0x020142E8.
 */
unsigned int func_0216E42C(void *bitmap, int id)
{
    return func_020142E8(bitmap, id);
}










/*
 * Classify an id: 1 for the eight 'special' values, the id itself otherwise.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0216E434(u32 a)
{
switch (a) {
case 4:
case 5:
case 6:
case 7:
case 8:
case 11:
case 12:
case 13:
return 1;
}
return a;
}

void func_0216E464(void)
{
}

void func_0216E468(void)
{
}

void func_0216E46C(void)
{
}

void func_0216E470(void)
{
}

