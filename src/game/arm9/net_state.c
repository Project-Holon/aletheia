/*
 * file:     net_state.c
 * unit:     yes
 * function: sub_020353B0, sub_020353C8, sub_020353F8, sub_02035428, sub_0203545C, func_02035544, sub_020355C4, sub_020355D8, sub_020355EC, sub_020355F8,, sub_02035660, func_0203568C, func_020356A0, func_02035750, func_02035760, func_02035780, func_020357A0, func_020357C0, func_020357E0, func_020358A0, func_02035A60, func_02035A70, func_02035AA4, func_02035ADC, func_02035B58, func_02035BA4, func_02035BBC, func_02035C08, func_02035C20, func_02035C38, func_02035C48, func_02035C60, func_02035C70, func_02035CB8, func_02035CD8, func_02035D20, func_02035D40, func_02035D5C, func_02035D98, func_02035DC8, func_02035DD8, func_02035E08, func_02035E18, func_02035E54, func_02035E84, func_02035EB0, func_02035ECC, func_02035EE8, func_02035F38, func_020360A8, func_020360B8, func_02036254, func_02036270, func_02036290, func_020362A4, func_020362BC, func_020362DC, func_020362EC, func_0203630C, func_0203631C, func_0203633C, func_0203634C, func_02036370, func_02036390, func_020363B8, func_020363D4, func_020363F0, func_0203640C, func_02036428, func_020364D4, func_02036500, func_02036540, func_02036568, func_020365E8, func_0203660C, func_02036624, func_02036640, func_0203666C, func_02036670, func_020366A8, func_020366C0, func_020366FC, func_02036738, func_0203675C, func_020367C4, func_020368C0, func_020369C8, func_020369F8, func_02036A50, func_02036AF4, func_02036B4C, func_02036B88, func_02036B98, func_02036BD4, func_02036CA8, func_02036D64, func_02036DC8, func_02036E74, func_02036E80, func_02036EC8, func_02036F04, func_02036F24, func_02036FD8, func_02037010, func_020370C8, func_020370F4, func_02037118, func_02037154, func_02037174, func_02037190, func_020371AC, func_020371D8, func_02037200, func_02037224, func_02037234, func_02037258, func_02037288, func_02037478, func_02037680, func_02037700, func_0203778C, func_020377AC, func_020377B8, func_0203781C, func_02037858, func_02037894, func_02037928, func_020379C8, func_02037A44, func_02037A6C, func_02037B08, func_02037BA4, func_02037BE8, func_02037C10, func_02037D78, func_02037D98, func_02037E60, func_02037F48, func_0203802C, func_020380E4, func_020381D8, func_02038298, func_02038340, func_02038380, func_02038524, func_02038570, func_020385C4, func_020387A0, func_02038924, func_02038A48, func_02038A90, func_02038AE0, func_02038C18, func_02038D30, func_02038D4C, func_02038D68, func_02038DF0, func_02039050, func_020390BC, func_02039160, func_020392B8, func_020392EC, sub_02039338, sub_020393A8, sub_020393D0, func_02039414, func_02039468, func_020394C0, func_020394DC, func_020394F0, func_02039548, sub_02039560, sub_02039578, sub_02039594, func_020395E0, func_020395EC, func_02039658, func_0203971C, func_02039764, func_02039834, func_020398B4, func_0203996C, func_020399A8, func_020399B8, func_020399DC, func_020399EC, func_02039A2C, func_02039A5C, func_02039ACC, func_02039B5C, func_02039C2C, func_02039C3C, func_02039C68, func_02039CA0, func_02039CB4, func_02039CD8, func_02039D94, func_0203A020, func_0203A118, func_0203A150, func_0203A27C, func_0203A28C, func_0203A2F0, func_0203A338, func_0203A388, func_0203A424, func_0203A458, func_0203A494, func_0203A53C, func_0203A574, func_0203A5E4, func_0203A634, func_0203A67C, func_0203A70C, func_0203A730, func_0203A748, func_0203A770, func_0203A7EC, func_0203A804, func_0203A81C, func_0203A858, func_0203A85C, func_0203A958, func_0203AA94, func_0203ABC0, func_0203ACAC, func_0203AD74, func_0203AD8C, func_0203AE20, func_0203AEEC, func_0203AF40, func_0203AFCC, func_0203B018, func_0203B01C, func_0203B038, func_0203B084, func_0203B0C4, func_0203B16C, func_0203B170, func_0203B1B0, func_0203B1D8, func_0203B224, func_0203B228, func_0203B22C, func_0203B258, func_0203B2A8, func_0203B2D0, func_0203B2FC, func_0203B344, func_0203B390, func_0203B448, func_0203B48C, func_0203B4DC, func_0203B52C, func_0203B5D4, func_0203B688, func_0203B6B4, func_0203B6EC, func_0203B758, func_0203B794, func_0203B7F8, func_0203B868, func_0203B90C, func_0203B950, func_0203B9D4, func_0203BA98, func_0203BBB0, func_0203BC58, func_0203BCE0, func_0203BD30, func_0203BDEC, func_0203BE5C, func_0203BEAC, func_0203BEC8, func_0203BF4C, func_0203BF9C, func_0203BFF0, func_0203C00C, func_0203C010, func_0203C044, func_0203C05C, func_0203C060, func_0203C064, func_0203C068, func_0203C0B4, func_0203C0DC, func_0203C0F4, func_0203C238, func_0203C2B0, func_0203C304, func_0203C35C, func_0203C3B4, func_0203C3EC, func_0203C464, func_0203C494, func_0203C554, func_0203C5C8, func_0203C5EC, func_0203C600, func_0203C628, func_0203C65C, func_0203C710, func_0203C774, func_0203C7E0, func_0203C864, func_0203C8A8, func_0203C8E8, func_0203C900, func_0203C934, func_0203C938, func_0203C968, func_0203C990, func_0203C9AC, func_0203CA04, func_0203CA98, func_0203CADC, func_0203CB00, func_0203CB34, func_0203CBAC, func_0203CD98, func_0203CDBC, func_0203CDD4, func_0203CEAC, func_0203CF04, func_0203CF10, func_0203CF3C, func_0203CF5C, func_0203CFA0, func_0203CFF0, func_0203D000, func_0203D010, func_0203D01C, func_0203D060, func_0203D0AC, func_0203D0B8, func_0203D0C4, func_0203D0D0, func_0203D0DC, func_0203D0FC, func_0203D10C, func_0203D12C, func_0203D14C, func_0203D158, func_0203D164, func_0203D170, func_0203D17C, func_0203D1A4, func_0203D1B4, func_0203D1C0, func_0203D1E8, func_0203D210, func_0203D24C, func_0203D26C, func_0203D29C, func_0203D2CC, func_0203D34C, func_0203D378, func_0203D394, func_0203D3A8, func_0203D3F8, func_0203D4D0, func_0203D56C, func_0203D578, func_0203D594, func_0203D5A0, func_0203D5AC, func_0203D5D4, func_0203D5EC, func_0203D610, func_0203D634, func_0203D644, func_0203D650, func_0203D668, func_0203D680, func_0203D6BC, func_0203D6CC, func_0203D700, func_0203D720, func_0203D754, func_0203D788, func_0203D798, func_0203D7B0, func_0203D7BC, func_0203D7C8, func_0203D7FC, func_0203D814, func_0203D828, func_0203D844, func_0203D864, func_0203D880, func_0203D88C, func_0203D8AC, func_0203D8C4, func_0203D8F0, func_0203D9EC, func_0203DA20, func_0203DA4C, func_0203DA68, func_0203DA7C, func_0203DAC4, func_0203DBB0, func_0203DC04, func_0203DC4C, func_0203DC68, func_0203DC70, func_0203E420, func_0203E458, func_0203E484, func_0203E4E8, func_0203E538, func_0203E590, func_0203E5AC
 * address:  0x020353B0
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
 *   func_020353B0  0x020353B0  arm
 *   PM_SetBackLight 0x0208BDD8  arm
 *   func_02035224   0x02035224  arm
 *   func_020353F8   0x020353F8  arm
 *   func_02035E08   0x02035E08  arm
 *   func_0203524C   0x0203524C  arm
 *   PM_GoSleepMode  0x0208C154  arm
 *   func_020353C8   0x020353C8  arm
 *   func_020352AC   0x020352AC  arm
 *   func_02035268   0x02035268  arm
 *   func_02035DC8   0x02035DC8  arm
 *   func_02035428   0x02035428  arm
 *   func_02035284   0x02035284  arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   OS_ResetSystem            0x02087BCC  arm
 *   OS_WaitIrq                0x0208459C  arm
 *   g_021469BC     0x021469BC  data
 *   str_020A798C   0x020A798C  data
 *   g_021469C4     0x021469C4  data
 *   func_02030734  0x02030734  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   TP_Init              0x0208A924  arm
 *   TP_GetUserInfo       0x0208A998  arm
 *   TP_SetCalibrateParam 0x0208AA2C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0208AB1C  0x0208AB1C  arm
 *   func_0208ABB8  0x0208ABB8  arm
 *   func_0208ADB4  0x0208ADB4  arm
 *   func_0208B104  0x0208B104  arm
 *   func_0208AC0C  0x0208AC0C  arm
 *   func_0208AD14  0x0208AD14  arm
 *   func_0208B220  0x0208B220  arm
 *   func_0208B238  0x0208B238  arm
 *   g_020A799C    0x020A799C  data
 *   func_0203521C  0x0203521C  arm
 *   func_02039548  0x02039548  arm
 *   func_02034714  0x02034714  arm
 *   file_020A79A4  0x020A79A4  data
 *   str_020A79B4   0x020A79B4  data
 *   file_020A79C0    0x020A79C0  data
 *   _s32_div_f  0x0209C0A4  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   g_020A79C4      0x020A79C4  data
 *   g_020A79D0      0x020A79D0  data
 *   g_020A79D4      0x020A79D4  data
 *   str_020A79C4  0x020A79C4  data
 *   str_020A79EC  0x020A79EC  data
 *   wm_icon_File    0x020A79F0  data
 *   g_021469C8      0x021469C8  data
 *   str_020A79F0  0x020A79F0  data
 *   str_020A79FC  0x020A79FC  data
 *   GX_GetBankForOBJ     0x02080C24  arm
 *   GX_GetBankForSubOBJ  0x02080C64  arm
 *   func_0200F168   0x0200F168  thumb
 *   func_0200F16C   0x0200F16C  thumb
 *   func_020490F4   0x020490F4  arm
 *   func_02049B68   0x02049B68  arm
 *   func_02049800   0x02049800  arm
 *   func_02049238   0x02049238  arm
 *   d_020A7A20   0x020A7A20  data  a1
 *   str_020A7A24   0x020A7A24  data
 *   g_021469D0     0x021469D0  data
 *   str_020A7A20   0x020A7A20  data
 *   str_020A7A34   0x020A7A34  data
 *   g_020387A0     0x020387A0  data
 *   g_020A7A20      0x020A7A20  data
 *   func_020307B0   0x020307B0  arm
 *   func_02039338   0x02039338  arm
 *   func_020393A8   0x020393A8  arm
 *   func_020393D0  0x020393D0  arm
 *   lbl_020A7A20    0x020A7A20  data
 *   func_020399A8  0x020399A8  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   d_020A7A24     0x020A7A24  data
 *   d_020A7A50     0x020A7A50  data
 *   str_020A7A54   0x020A7A54  data
 *   g_020A7A24     0x020A7A24  data
 *   g_020A7A50     0x020A7A50  data
 *   str_020A7A50   0x020A7A50  data
 *   func_02039594  0x02039594  arm
 *   func_0203996C   0x0203996C  arm
 *   func_02082D44  0x02082D44  arm
 *   g_021469DC     0x021469DC  data
 *   str_020A7A68   0x020A7A68  data
 *   str_020A7A78   0x020A7A78  data
 *   file_020A7A68  0x020A7A68  data
 *   g_021469D4     0x021469D4  data
 *   msg_020A7A7C   0x020A7A7C  data
 *   msg_020A7A88   0x020A7A88  data
 *   func_02087C6C  0x02087C6C  arm
 *   msg_020A7A94   0x020A7A94  data
 *   func_020395E0  0x020395E0  arm
 *   func_0203EFC8  0x0203EFC8  arm
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
 *   unk_0203C00C   0x0203C00C  arm
 *   func_02034F84  0x02034F84  arm
 *   unk_0203B018   0x0203B018  arm
 *   unk_0203B01C   0x0203B01C  arm
 *   s_020A7BA8     0x020A7BA8  data
 *   s_020A7BC8     0x020A7BC8  data
 *   unk_0203B228   0x0203B228  data
 *   unk_0203B22C   0x0203B22C  arm
 *   str_0203B950   0x0203B950  data
 *   str_0203B48C   0x0203B48C  data
 *   unk_021469DC   0x021469DC  data
 *   str_0203C238   0x0203C238  data
 *   func_02039578  0x02039578  arm
 *   func_02039560  0x02039560  arm
 *   g_020A7BEC      0x020A7BEC  data
 *   file_020A7BA8   0x020A7BA8  data
 *   file_020A7C70   0x020A7C70  data
 *   g_020A7C7C     0x020A7C7C  data
 *   g_021469E0     0x021469E0  data
 *   file_020A7CA0  0x020A7CA0  data
 *   str_020A7CA8   0x020A7CA8  data
 *   str_020A7CB8   0x020A7CB8  data
 *   str_020A7CE8   0x020A7CE8  data
 *   func_0203064C  0x0203064C  arm
 *   func_0200F17C  0x0200F17C  thumb
 *   func_020306F0  0x020306F0  arm
 *   func_02034FB8  0x02034FB8  arm
 *   func_0200F234  0x0200F234  thumb
 *   str_020A7CA0   0x020A7CA0  data
 *   func_0203EA9C 0x0203EA9C  arm
 *   g_020A7CA0     0x020A7CA0  data
 *   g_020A7CE8     0x020A7CE8  data
 *   func_020338F8  0x020338F8  arm
 *   g_020A7CEC     0x020A7CEC  data
 *   func_02039CA0  0x02039CA0  arm
 *   file_020A7CF8  0x020A7CF8  data
 *   file_020A7D2C  0x020A7D2C  data
 *   g_021469F0     0x021469F0  data
 *   d_020A7D34     0x020A7D34  data
 *   d_021469F0   0x021469F0  data  a4
 *   str_020A7D34  0x020A7D34  data
 *   str_020A7D48  0x020A7D48  data
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   str_020A7D4C  0x020A7D4C  data
 *   g_021469F4      0x021469F4  data
 *   s_020A7D34      0x020A7D34  data
 *   s_020A7D4C      0x020A7D4C  data
 *   s_020A7D68      0x020A7D68  data
 *   s_020A7D74      0x020A7D74  data
 *   s_020A7DA0      0x020A7DA0  data
 *   s_020A7E00      0x020A7E00  data
 */
#include "../../matched/include/Obj11334.h"
#include "../../matched/include/Obj11335.h"
#include "../../matched/include/Obj11336.h"
#include "../../matched/include/Obj11337.h"
#include "../../matched/include/Obj07103.h"
#include "../../matched/include/Obj06933.h"
#include "../../matched/include/Obj11338.h"
#include "../../matched/include/Obj11339.h"
#include "../../matched/include/Obj15900.h"
#include "../../matched/include/Obj05731.h"
#include "../../matched/include/Obj15901.h"
#include "../../matched/include/Obj11348.h"
#include "../../matched/include/Obj11349.h"
#include "../../matched/include/Obj08825.h"
#include "../../matched/include/Obj06937.h"
#include "../../matched/include/Obj05733.h"
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
#include "../../matched/include/Obj15960.h"
#include "../../matched/include/Obj15961.h"
#include "../../matched/include/Obj11369.h"
#include "../../matched/include/Obj15974.h"
#include "../../matched/include/Obj15975.h"
#include "../../matched/include/Obj15976.h"
#include "../../matched/include/Obj11372.h"
#include "../../matched/include/Obj15978.h"
#include "../../matched/include/Obj15979.h"
#include "../../matched/include/Obj15980.h"
#include "../../matched/include/Obj15990.h"
#include "../../matched/include/Obj11379.h"

struct NetCtx;
struct Entry;

#define HW_BUTTON_XY_BUF    0x02FFFFA8
#define REG_KEYINPUT        0x04000130
#define PAD_ALL_MASK        0x2FFF
struct TPData;
struct Kind;
struct R;
struct Ctx02035C48;
struct Obj;
struct Sys_020353B0;
struct Sub0200F16CHdr;
struct Handler;
struct Icon;
struct Rec;
struct Hdr;
struct St;
struct NetEntry;
struct Obj_02039C68;
struct RTCDate;
struct RTCTime;
struct NetState;
struct Slot;
struct NetHdr;
struct Link;
struct Req;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef void (*UiCb)(void *);

typedef int  (*UiPred)(void *);

struct Sys_020353B0 {
    u8      pad00[0x10];
    UiCb    on_10;
    UiCb    on_14;
    UiCb    on_18;
    UiCb    on_1c;
    UiCb    on_20;
    UiPred  on_24;
    void   *arg_28;
    void   *arg_2c;
    void   *arg_30;
    void   *arg_34;
    u8      always;
    u8      pad39[2];
    u8      backlight;
    u8      unk_3c;
    u8      unk_3d;
    u8      unk_3e;
    u8      unk_3f;
    u8      pad40[3];
    u8      suspended;
};

typedef unsigned short u16;


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

struct NetVtbl {
    void (*f00)(u32 a, u32 b);
    void (*f04)(u16 key, struct NetCtx *ctx, u32 zero, u32 arg);
    void (*f08)(u32 a);
    int  (*f0C)(u32 a);
    u32  (*f10)(u32 a, u32 b);
    u32  (*f14)(u32 a);
    u8   pad18[0x28 - 0x18];
    u32  (*f28)(u32 a);
    void *(*f2C)(u32 a);
    u8   pad30[0x38 - 0x30];
    u32  (*f38)(u32 a);
    void (*f3C)(void *cb);
    u32  (*f40)(u32 a, u32 b);
    u32  (*f44)(u32 a, u32 b);
    u32  (*f48)(u32 a, u32 b, u32 c, u32 d, u32 e);
    u8   pad4C[4];
    u32  (*f50)(int a, u32 b, u32 c);
    u32  (*f54)(u32 a, u32 b);
    u32  (*f58)(void);
    u32  (*f5C)(u32 a);
    u32  (*f60)(u32 a);
    u32  (*f64)(u32 a, u32 b, u32 c, void *d);
    void (*f68)(void *cb);
    u32  (*f6C)(void);
    int  (*f70)(void);
    u32  (*f74)(void);
    u32  (*f78)(void);
    u32  (*f7C)(void);
    int  (*f80)(void);
    u32  (*f84)(void);
    int  (*f88)(void);
    void (*f8C)(u32 a);
    u32  (*f90)(u32 a);
    u8   pad94[0x9C - 0x94];
    void (*f9C)(void);
    u32  (*fA0)(void);
    u32  (*fA4)(void);
    u32  (*fA8)(void);
    u32  (*fAC)(void);
    int  (*fB0)(void);
    void (*fB4)(void);
    void (*fB8)(void *arg);
    int  (*fBC)(void);
    void (*fC0)(int a);
    void (*fC4)(u32 a);
    void (*fC8)(u32 a);
};

struct NetCtx {
    u8   pad00[0x08];
    void (*f08)(u32 a, u32 b);
    void (*f0C)(int a, u32 b);
    u32  (*f10)(u32 a);
    u32  (*f14)(u32 a);
    u8   pad18[0x1C - 0x18];
    void (*f1C)(void);
    u8   pad20[0x24 - 0x20];
    void (*f24)(u32 a, u32 b, u32 c);
    void (*f28)(u32 a, u32 b, u32 c);
    void (*f2C)(u32 a);
    void (*f30)(u32 a);
    u8   pad34[0x40 - 0x34];
    u32  (*f40)(u32 a);
    u32  (*f44)(u32 a);
    u8   pad48[0x56 - 0x48];
    u16  f56;
    u16  f58;
    u16  f5A;
    u16  f5C;
    u16  f5E;
    u8   f60;
    u8   f61;
    u8   f62;
    u8   pad63;
    u8   f64;
    u8   f65;
    u8   f66;
    u8   f67;
    u8   pad68[4];
    u16  f6C;
    u16  f6E;
    struct Entry table[9];
    struct NetVtbl *vt;
    u32  f344;
    void (*f348)(u32 a);
    u32  f34C;
    u8   pad350[2];
    u8   f352;
};

typedef struct {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
    u16 f08;
    u8  f0A;
    u8  f0B;
} S12;

typedef struct {
    struct Sys_020353B0 *sys;
    int (*f04)(S12 *dst, S12 *src);
} Desc;

struct Kind {
    u8 pad00[0x3D];
    u8 unk3D;
};

typedef signed int     s32;

struct Work {
    u8  pad00[0x5c];
    u16 f5c;
    u16 f5e;
    u16 f60;
    u16 f62;
    u16 f64;
    u16 f66;
    u16 f68;
    u16 f6a;
    u16 f6c;
    u16 f6e;
    u16 f70;
    u16 f72;
    u8  f74;
};

struct Samp {
    u16 x;
    u16 y;
    u16 v;
    u16 t;
};

struct R {
    u8 t;
    u8 a;
    u8 b;
    u8 c;
};

struct Hdr {
    u8 f00;
    u8 f01;
    u8 f02;
    u8 f03;
    u8 f04;
    u8 f05;
    u8 f06;
    u8 body[1];
    u8 pad_08[0x4];
    u8 buf[0x4c];
    u16 unk58;
    u16 unk5a;
    u8 pad_5C[0x19];
    u8 unk75;
};

struct Sio_02035E54 {
    u8 pad_00[0x64];
    u16 unk64;
    u16 unk66;
    u16 unk68;
    u16 unk6a;
    u16 unk6c;
    u16 unk6e;
    u16 unk70;
    u16 unk72;
};

typedef struct {
    u8  pad[0x40];
    u32 f40;
    u32 f44;
} T;

typedef volatile u16   vu16;

struct Key {
    u8  pad00[0x0c];
    u32 cont;           /* 0x0c */
    u32 trg;            /* 0x10 */
    u32 rpt;            /* 0x14 */
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u32 f38;
    s32 wait;           /* 0x3c */
    s32 speed;          /* 0x40 */
    s32 delay;          /* 0x44 */
};

struct Ent {
    u32 f00;
    u32 f04;
    u8  f08;
    u8  pad09[3];
};

struct Obj {
    u32 f00;
    u32 f04;
    u32 f08;
    u8  pad0c[0xc];
    u32 f18;
    u32 f1c;
    u32 f20;
};

struct Rec_02036254 {
    u8 pad00[0x40];
    int f40;
    int f44;
};

struct Rec_020362BC {
    u8 pad_00[0x1c];
    u32 unk_1c;
    u8 pad_20[0x08];
    u32 unk_28;
};

struct Rec_020362EC {
    u8 pad_00[0x18];
    u32 unk_18;
    void *unk_1c;
    u32 unk_20;
    u32 unk_24;
    void *unk_28;
    u32 unk_2c;
    u8 pad_30[0x10];
    u32 unk_40;
    u32 unk_44;
};

struct Rec_02036390 {
    u8 pad_00[0x24];
    u32 unk24;
    u32 unk28;
    u32 unk2c;
    u32 unk30;
    u32 unk34;
    u32 unk38;
};

struct Rec_02036290 {
    const void *f0;
};

struct Rec {
    u32 unk0;
    u32 unk4;
    u8  pad8[4];
    u16 unkC;
    u16 unkE;
};

typedef struct {
    u8   *buf;
    int   size;
    u32   state;
    short head;
    volatile short tail;
} NetRingBuff;

struct Rec_020363B8 {
    u8 pad00[0x1c];
    int f1C;
    u8 pad_20[0x8];
    int f28;
};

struct Rec_020363D4 {
    u8 pad00[0x18];
    int f18;
    u8 pad_1c[0x8];
    int f24;
};

struct Rec_020363F0 {
    u8 pad00[0x20];
    int f20;
    u8 pad_24[0x8];
    int f2C;
};

typedef int            BOOL;

typedef struct {
    u8  *src;       /* +0x00 */
    u32  pad4;
    u32  pad8;
    u16  rest;      /* +0x0C */
    u16  fE;
    u8   f10;
    u8   headerDone;/* +0x11 */
} NetSendItem;

typedef struct {
    u8  *ptr;       /* +0x00 */
    u16  len;       /* +0x04 */
} NetOutBuf;

typedef struct NetNode {
    const u8 *f0;
    struct NetNode *f4;
    struct NetNode *f8;
    u16 fC;
    u16 fE;
    u8 f10;
    u8 f11;
} NetNode;

typedef struct NetQueue {
    NetNode *f0;
    NetNode *f4;
    u32 f8;
    u32 fC;
    u32 f10;
    NetRingBuff *f14;
    NetNode *f18;
    s32 f1C;
    u32 f20;
    u32 f24;
} NetQueue;

struct Handler {
    u32 unk00;      /* 0x00 */
    u16 unk04;      /* 0x04 */
    u16 unk06;      /* 0x06 */
    u8  pad08[4];   /* 0x08 */
    u8  unk0c;      /* 0x0c */
    u8  kind;       /* 0x0d */
    u8  busy;       /* 0x0e */
    u8  unk0f;      /* 0x0f */
    u32 unk10;      /* 0x10 */
};

struct Notifier {
    u16 unk00;                /* 0x00 */
    u16 unk02 : 14;           /* 0x02, bits 0-13 */
    u16 mode  : 2;            /* 0x02, bits 14-15 */
    struct Handler *handler;  /* 0x04 */
};

typedef struct {
    union {
        u32 attr01;
        struct { u16 attr0; u16 attr1; };
    };
    u16 attr2;
    u16 _3;
} GXOamAttr;

struct Icon {
    u32 f00;
    u16 f04;
    u16 f06;
    u8  pad08[7];
    u8  f0f;
    GXOamAttr *f10;
};

typedef volatile unsigned int vu32;

/* The object g_021469D0 points at (0x1f0 bytes, allocated by func_02037288). */
struct Net {
    u8  *f00;           /* 0x00 */
    u8  *f04;
    u8  *f08;
    u8  *f0C;
    u8  *f10;
    u8  *f14;
    u8  *f18;
    NetRingBuff f1C;
    NetRingBuff f2C;
    NetRingBuff f3C;
    NetRingBuff f4C[8];
    NetQueue fCC;
    NetQueue fF4;
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

struct Votes {
    u16 tag[8];
    u8  mask[8];
    u8  ready[8];
};

struct Glob_020377B8
{
    u8 pad_00[0x65];
    u8 f65;
};

struct Vt_020377B8
{
    u8 pad_00[0x7c];
    u8 (*f7c)(void);
    u8 pad_80[0x30];
    s32 (*fb0)(void);
};

struct Sys_020377B8
{
    u8 pad_00[0x340];
    struct Vt_020377B8 *f340;
};

struct Buf
{
    void *ptr;
    u16 len;
};

struct Err {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
};

typedef signed short   s16;

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

typedef struct {
    u8 pad_000[0x65];
    u8 f065;
} T_0203D798;

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

typedef struct {
    u8 lo : 4;
    u8 hi : 4;
} Status;

typedef unsigned long long u64;

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext64;

struct NetState {
    u32  f00;
    u32  f04;
    void (*f08)(struct NetState *s);
    MATHRandContext64 rng;
    u32  f24;
    void (*f28)(void);
    void (*f2C)(u32 a);
    u32  err[4];
    u8   mac[6];
    u16  f46;
    s8   flag;
    u8   pad49;
    u8   f4A;
    u8   f4B;
    u8   f4C;
    u8   f4D;
    u8   f4E;
    u8   f4F;
    u8   f50;
    u8   f51;
    u8   pad52;
    u8   f53;
    u8   pad54[2];
    u8   f56;
    u8   addr[6];
    u8   pad5D[7];
};

struct Date { u32 year; u32 mon; u32 day; u32 wday; };

struct Time { u32 hour; u32 min; u32 sec; };

struct Req {
    u32 f00;
    u32 f04;
    u8  pad_08[0x40];
    u32 f48;
    u8  pad_4c[8];
    u16 f54;
    u16 f56;
    u16 f58;
    u16 f5a;
    u16 f5c;
    u16 f5e;
    u8  pad_60[1];
    u8  f61;
    u8  pad_62[3];
    u8  f65;
    u8  pad_66[1];
    u8  f67;
};

struct NetMod {
    u16 f00;
    u16 pad02;
    u32 f04;
    struct NetCtx *f08;
    u32 f0C;
};

typedef int (*Fn_020353B0)(void);

typedef u32 (*Fn_0203CF10)(u32);

typedef void *(*Fn_0203CF3C)(u32);

typedef void (*Fn_0203CDBC)(u32);

typedef unsigned char u32_pad;

struct NetEntry {
    u8 pad_00[0x4a];
    u8 state;
};

typedef struct NetHdr {
    u8    pad_00[0x18];
    void *(*f18)(void *arg);
    void *(*f1C)(void *arg);
    u8    pad_20[0x2c - 0x20];
    void *f2C;
    u8    pad_30[0x54 - 0x30];
    u16   heap;
    u8    pad_56[0x60 - 0x56];
    u8    f60;
    u8    pad_61[3];
    u8    f64;
    u8    f65;
    u8    pad_66;
    u8    f67;
    u8    pad_68[0x6E - 0x68];
    u16   f6E;
} NetHdr;

struct NetMac {
    u8 addr[6];
    u8 pad06[2];
};

struct NetMacList {
    int count;
    struct NetMac mac[4];
};

typedef struct NetLink {
    NetHdr hdr;
    u32    f70;
    u32    f74;
    void *(*f78)(void *arg);
    void *(*f7C)(void *arg);
    void  *f80;
    void (*f84)(u32 arg);
    void (*f88)(u32 arg, int flag);
    void (*f8C)(u32 arg);
    struct NetMacList macs;
    u8     fB4[0x4C];
    u8     f100;
    u8     f101;
    u8     f102;
    u8     f103;
    u8     f104;
    u8     f105;
    u8     f106;
    u8     f107;
    u8     f108;
    u8     f109;
    u8     f10A;
    u8     f10B;
} NetLink;

typedef struct G_021469F0 {
    unsigned char pad[0x7c];
    void *(*fn)(void *);
} G_021469F0;

extern int func_020353B0(void);
extern int PM_SetBackLight(u32 which, u32 status);
extern struct Sys_020353B0 *func_02035224(void);
extern int  func_020353F8(struct Sys_020353B0 *p);
extern void func_02035E08(void);
extern void func_0203524C(struct Sys_020353B0 *p);
extern void PM_GoSleepMode(u32 trigger, u32 a, u32 b);
extern void func_020353C8(struct Sys_020353B0 *p);
extern void func_020352AC(struct Sys_020353B0 *p);
extern void func_02035268(struct Sys_020353B0 *p);
extern void func_02035DC8(void);
extern void func_02035428(u32 status);
extern void func_02035284(struct Sys_020353B0 *p);
extern struct Sys_020353B0 *sub_02035224(void);
extern void GXx_SetMasterBrightness_(u32 reg, int brightness);
extern u32 func_02076B8C(void);
extern void OS_ResetSystem(u32 param);
extern void OS_WaitIrq(u32 clear, u32 irqFlags);
extern void func_0204E638(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  MI_CpuFill8(void *dst, u8 val, u32 size);
extern void  TP_Init(void);
extern int   TP_GetUserInfo(u16 *info);
extern void  TP_SetCalibrateParam(u16 *info);
extern void *func_02082BCC(void *dst, int val, u32 size);
extern void func_0208AB1C(void);
extern u32 func_0208ABB8(struct TPData *result);
extern void func_0208ADB4(struct TPData *result);
extern void func_0208B104(struct TPData *disp, const struct TPData *raw);
extern int sub_02035C20(const void *p);
extern void func_0208AC0C(u32 a, u32 b, void *c, u32 d);
extern void func_0208AD14(void);
extern void func_0208B220(u32 slot);
extern u32 func_0208B238(u32 slot);
extern u32 func_0203521C(u32 *p);
extern void func_02039548(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u32 func_020307B0(void *p);
extern u32  GX_GetBankForOBJ(void);
extern u32  GX_GetBankForSubOBJ(void);
extern u32 func_0200F168(void);
extern void func_0200F16C(struct Sub0200F16CHdr *hdr);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a0, u32 a1, void *a2, int a3, int a4, int a5);
extern void func_02049800(void *a0, u32 a1, int a2, int a3, int a4, int a5, int a6);
extern void func_02049238(void *a0);
extern u16 func_02039338(void);
extern int   func_020393A8(void);
extern int  func_020393D0(void);
extern struct Entry *func_020399A8(void);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern int    func_02039594(void);
extern struct Entry *func_0203996C(s32 idx);
extern void func_02082D44(const void *src, void *dst, int n);
extern void func_02087C6C(void *p);
extern int func_020395E0(int slot);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void OS_GetMacAddress(u8 *);
extern int func_020889C0(struct RTCDate *date, struct RTCTime *time);
extern void func_0203F034(u32 seed);
extern u32 func_0203F0A8(void);
extern void unk_0203C00C(void);
extern void func_02034F84(u32 a);
extern void func_020394DC(u8 v);
extern int func_020351A0(u32 v);
extern void func_0203516C(u32 a);
extern void func_02039578(void);
extern void func_02039560(void);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern int func_0200F17C(u32 sel);
extern void func_0200F234(u32 a);
extern void func_020306F0(u32 a);
extern void func_02034FB8(u32 a);
extern void func_0203EA9C(void);
extern u32  func_020338F8(void);
extern void func_02039CA0(void);
extern void func_02039C68(struct Link *h, u32 a, u32 b);
extern u32 func_02039CB4(struct Link *h, u32 a, u32 b);
int sub_020353B0(void);
void sub_020353C8(struct Sys_020353B0 *p);
int sub_020353F8(struct Sys_020353B0 *p);
void sub_02035428(u32 status);
void sub_0203545C(void);
void func_02035544(u32 param);
u8 sub_020355C4(void);
void sub_020355D8(u8 v);
void sub_020355EC(struct Sys_020353B0 *p);
void sub_020355F8(struct Sys_020353B0 *unused, u8 v);
u8 sub_0203560C(struct Sys_020353B0 *p);
void sub_02035614(u8 v);
u8 sub_02035630(void);
void sub_02035648(void);
void sub_02035660(u8 v);
int func_0203568C(void);
void func_020356A0(int a0);
int func_02035750(void);
u16 func_02035760(struct Kind *p);
u16 func_02035780(struct Kind *p);
int func_020357A0(struct Kind *p);
u16 func_020357C0(struct Kind *p);
void *sub_020357E0(u32 id);
void func_020358A0(struct Sys_020353B0 *ctx);
void func_02035A60(void);
u32 func_02035A70(u8 *p, s32 x, s32 y);
u32 func_02035AA4(u8 *p, u32 a, u32 b);
int func_02035ADC(struct R *p, u32 x, u32 y);
int func_02035B58(u32 a, u32 b);
int func_02035BA4(const void *p);
int func_02035BBC(void *ctx, void *param);
int func_02035C08(const void *p);
int func_02035C20(const void *p);
int sub_02035C38(void);
u16 func_02035C48(struct Ctx02035C48 *ctx);
int sub_02035C60(void);
u32 sub_02035C70(struct Sys_020353B0 *ctx, u32 *outA, u32 *outB);
u32 sub_02035CB8(u32 *outA, u32 *outB);
u32 sub_02035CD8(struct Sys_020353B0 *ctx, u32 *outA, u32 *outB);
u32 sub_02035D20(u32 *outA, u32 *outB);
u32 sub_02035D40(struct Sys_020353B0 *ctx, u32 a, u32 b);
u32 sub_02035D5C(struct Hdr *p);
void sub_02035D98(struct Hdr *p);
void sub_02035DC8(void);
void sub_02035DD8(struct Hdr *p);
void sub_02035E08(void);
u32 sub_02035E18(struct Hdr *p);
void sub_02035E54(struct Sys_020353B0 *p);
void func_02035E84(void *p, u16 a, u16 b, u16 c, u16 d);
int func_02035EB0(int a0, int a1, int a2);
int func_02035ECC(int a0, int a1, int a2);
T *func_02035EE8(u32 a);
void func_02035F38(struct Sys_020353B0 *ctx);
void sub_020360A8(void);
void func_020360B8(struct Obj *o);
int func_02036254(int a0, int a1, int a2);
int func_02036270(int a0, int a1);
int func_02036290(int a0, const void *a1);
void func_020362A4(const void *p);
u32 sub_020362BC(struct Sys_020353B0 *ctx);
u32 sub_020362DC(void);
u32 sub_020362EC(struct Sys_020353B0 *ctx);
u32 sub_0203630C(void);
u32 sub_0203631C(struct Sys_020353B0 *ctx);
u32 sub_0203633C(void);
void sub_0203634C(struct Sys_020353B0 *ctx, u32 *outA, u32 *outB);
void sub_02036370(u32 *outA, u32 *outB);
void sub_02036390(struct Sys_020353B0 *p);
int func_020363B8(int a0, int a1, int a2);
int func_020363D4(int a0, int a1, int a2);
int func_020363F0(int a0, int a1, int a2);
void func_0203640C(struct Rec *p, u32 a, int b);
void func_02036428(NetRingBuff *r, const u8 *src, int len);
int func_020364D4(NetRingBuff *p, unsigned char *dst, u32 len, u32 max);
u32 func_02036500(NetRingBuff *a);
u32 func_02036540(NetRingBuff *a);
int func_02036568(const NetRingBuff *r, u8 *dst, int len, int max);
int func_020365E8(NetRingBuff *p);
int func_0203660C(NetRingBuff *r);
int func_02036624(void *p, int v);
int func_02036640(char *p);
void func_0203666C(NetRingBuff *r);
NetNode *func_02036670(NetQueue *p);
int func_020366A8(NetQueue *p);
int func_020366C0(NetQueue *p);
u32 func_020366FC(u32 *p);
void func_02036738(NetOutBuf *q, int v);
int func_0203675C(NetSendItem *item, NetOutBuf *out);
int func_020367C4(NetSendItem *item, NetOutBuf *out, void *ring, BOOL needHeader);
int func_020368C0(NetQueue *q, u32 a1, const u8 *a2, u32 a3, u32 a4, u32 a5, u32 a6);
u32 func_020369C8(u32 *p);
void func_020369F8(u8 *p);
int func_02036A50(u32 list, u16 *info);
void func_02036AF4(NetQueue *p, u32 n, NetRingBuff *a, u32 b);
int func_02036B4C(NetQueue *p);
void func_02036B88(NetQueue *a0);
int func_02036B98(NetQueue *p, int v);
struct Handler *func_02036BD4(u32 unused, u32 b, u32 c, u32 d, u32 e, struct Handler *h, u32 kind, u32 busy, u32 unk00);
void func_02036CA8(struct Icon *c);
u32 func_02036D64(u8 *p);
u32 func_02036DC8(u32 engine, u32 b);
struct Handler *func_02036E74(struct Handler *p, int v);
void func_02036E80(unsigned char *p);
void func_02036EC8(struct Handler *p, u32 a, u32 b);
int func_02036F04(int a0);
void func_02036F24(int a0, int b, int c);
int func_02036FD8(void);
void func_02037010(u32 a, u32 b, u32 c, u32 d);
void func_020370C8(void);
u32 func_020370F4(u32 a);
void func_02037118(u32 a, u32 b);
void func_02037154(void);
void func_02037174(void);
void func_02037190(void);
void func_020371AC(unsigned short a, unsigned short b);
void func_020371D8(u32 mode);
u32 func_02037200(void);
void func_02037224(u8 v, int b);
void func_02037234(u8 *p);
u32 func_02037258(void);
int func_02037288(u32 a0, u32 heap, u32 c);
void func_02037478(void);
void func_02037680(int i);
int func_02037700(u32 a0, u32 a1);
u32 func_0203778C(u32 p);
u32 func_020377AC(u32 a0, u8 *rec, u32 len);
u32 func_020377B8(u8 arg0);
void func_0203781C(u32 arg);
void func_02037858(u32 arg);
u32 func_02037894(u8 a0, u16 a1, u32 a2, u32 a3);
u32 func_02037928(u32 a0, u16 a1);
int func_020379C8(u32 p);
void func_02037A44(int a);
u32 func_02037A6C(u32 a0, u32 a1, u16 a2, u32 a3);
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
s32 func_02038AE0(struct Hdr *h, NetQueue *c, s32 len, u8 a3);
int func_02038C18(u32 a1, const void *a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
void func_02038D30(int a0, int a1, int a2, int a3);
void func_02038D4C(int a0, int a1, int a2, int a3);
void func_02038D68(int a0, u32 a1, u32 a2, u8 *a3);
void func_02038DF0(NetRingBuff *src, s32 a1, u8 *buf, struct St *st, u32 n);
void func_02039050(void);
void func_020390BC(void);
int func_02039160(u32 mode);
u32 func_020392B8(void);
int func_020392EC(void);
u16 sub_02039338(void);
int sub_020393A8(void);
int sub_020393D0(void);
u32 func_02039414(void);
int func_02039468(u32 a, u32 b);
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
void func_02039834(struct NetCtx *unused);
void func_020398B4(struct NetCtx *unused);
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
void func_0203AD74(struct NetState *s, void *p, u32 v);
void func_0203AD80(struct NetState *s, void *p, u32 v, int line);
void func_0203AD8C(u32 a0);
void func_0203AE20(MATHRandContext64 *o);
void func_0203AEEC(struct NetState *p);
void func_0203AF40(struct NetState *p);
void func_0203AFCC(void *a, u32 b);
void func_0203B018(void);
void func_0203B01C(void);
void func_0203B038(struct NetState *a0);
void func_0203B084(void);
void func_0203B0C4(int a0, int a1);
void func_0203B16C(void);
void func_0203B170(void);
void func_0203B1B0(void);
u32 func_0203B1D8(void);
void func_0203B224(void);
void func_0203B228(void);
int func_0203B22C(void);
void func_0203B258(void);
void func_0203B2A8(int a0);
void func_0203B2D0(u32 val);
u32 func_0203B2FC(struct NetState *p);
u32 func_0203B344(struct NetState *p);
void func_0203B390(struct NetState *p);
void func_0203B448(void);
void func_0203B48C(void);
void func_0203B4DC(void);
void func_0203B52C(struct NetState *p);
void func_0203B5D4(struct NetState *p);
void func_0203B688(struct NetState *a0);
int func_0203B6B4(void);
void func_0203B6EC(struct NetState *p);
void func_0203B758(void);
void func_0203B794(struct NetState *p);
void func_0203B7F8(struct NetState *p);
void func_0203B868(struct NetState *p);
void func_0203B90C(void);
void func_0203B950(struct NetState *p);
void func_0203B9D4(struct NetState *p);
void func_0203BA98(u16 a0, u32 a1, u8 a2);
void func_0203BBB0(struct NetState *a);
void func_0203BC58(u8 v56, u8 v53, const void *src);
void func_0203BCE0(struct NetState *p);
void func_0203BD30(u32 a0, u32 a1, u8 *a2);
void func_0203BDEC(void);
void func_0203BE5C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
u32 func_0203BEAC(void);
void func_0203BEC8(struct NetState *p);
void func_0203BF4C(void);
void func_0203BF9C(u32 v);
void func_0203BFF0(void);
void func_0203C00C(void);
void func_0203C010(void);
struct NetCtx *func_0203C044(int a0, int a1, u8 *a2, int a3);
void func_0203C05C(void);
void func_0203C060(void);
void func_0203C064(void);
void func_0203C068(void);
void func_0203C0B4(void);
void func_0203C0DC(struct NetState *p, u32 v);
void func_0203C0F4(struct NetState *p);
void func_0203C238(struct NetState *p);
int func_0203C2B0(int a);
u32 func_0203C304(void);
u32 func_0203C35C(void);
void func_0203C3B4(void);
int func_0203C3EC(void);
void func_0203C464(void);
void func_0203C494(struct NetState *p);
void func_0203C554(u32 a);
void func_0203C5C8(void);
int func_0203C5EC(void);
int func_0203C600(void);
int func_0203C628(void);
void func_0203C65C(struct NetState *p);
void func_0203C710(void);
void func_0203C774(u32 v);
void func_0203C7E0(struct NetState *p);
void func_0203C864(void);
void func_0203C8A8(void);
void func_0203C8E8(u8 v);
void func_0203C900(u8 v);
void func_0203C934(void);
u32 func_0203C938(u8 mode);
void func_0203C968(void);
u32 func_0203C990(void);
void func_0203C9AC(int a, u32 b, u32 c, u32 d);
void func_0203CA04(void);
u32 func_0203CA98(void);
void func_0203CADC(void);
int func_0203CB00(void);
void func_0203CB34(u32 a, u32 b, u32 c, u32 d);
void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
int func_0203CD98(void);
int func_0203CDBC(void);
void func_0203CDD4(void);
int func_0203CEAC(void (*a0)(u32));
void func_0203CF04(void);
u32 func_0203CF10(u32 a);
void *func_0203CF3C(u32 a);
u32 func_0203CF5C(void);
void func_0203CFA0(void);
void func_0203CFF0(void *p);
void func_0203D000(void *p);
void func_0203D010(void);
void func_0203D01C(void);
void func_0203D060(u32 a, u32 b, u32 c);
void func_0203D0AC(int a0);
void func_0203D0B8(void *dst, u32 i);
void func_0203D0C4(unsigned int value);
void func_0203D0D0(void);
void func_0203D0DC(u32 a0);
void func_0203D0FC(int a);
void func_0203D10C(u32 a0);
void func_0203D12C(int a);
void func_0203D14C(u32 a0, u32 a1, u8 *a2);
u32 func_0203D158(void);
void func_0203D164(int a0);
int func_0203D170(void);
void func_0203D17C(u32 a);
u32 func_0203D1A4(struct Link *p);
int func_0203D1B4(void);
u32 func_0203D1C0(u32 index);
void func_0203D1E8(u32 unused, void *arg);
u32 func_0203D210(void);
void func_0203D24C(u16 a, u16 b);
u32 func_0203D26C(void);
u32 func_0203D29C(void);
void func_0203D2CC(void);
void func_0203D34C(u32 a, u32 b);
u32 func_0203D378(void);
u32 func_0203D394(struct NetEntry *e);
int func_0203D3A8(struct Entry *a, u32 b, u32 c, const void *d);
u32 func_0203D3F8(void *entry, u32 sendID, u32 c, u32 d, const void *e, u32 f, u32 g, u32 h);
u32 func_0203D4D0(void *entry, u32 mask, u32 c, u32 d, const void *e, u32 f, u32 g, u32 h);
void func_0203D56C(void);
void func_0203D578(int a, u32 b);
void func_0203D594(void *p, u16 tag);
void func_0203D5A0(void);
void func_0203D5AC(int a, int b);
u32 func_0203D5D4(void);
u32 func_0203D5EC(void);
u32 func_0203D610(void);
u32 func_0203D634(void);
void func_0203D644(u32 a);
u32 func_0203D650(void);
void func_0203D668(u32 v);
u32 func_0203D680(void);
u32 func_0203D6BC(void);
u32 func_0203D6CC(void);
void func_0203D700(void);
void func_0203D720(u32 a);
void func_0203D754(u32 a);
struct NetCtx *func_0203D788(void);
struct NetCtx *func_0203D798(void);
void func_0203D7B0(u8 a0);
void func_0203D7BC(u8 a0);
void *func_0203D7C8(u32 a, u32 size, const char *c, u16 d);
void func_0203D7FC(void *p);
void func_0203D814(u32 a, u32 b);
void func_0203D828(u32 *a, u32 *b);
void func_0203D844(void *dst);
void func_0203D864(void);
u32 func_0203D880(void);
void func_0203D88C(u32 a, u32 b);
void func_0203D8AC(void);
void func_0203D8C4(u32 a);
NetHdr *func_0203D8F0(const NetHdr *src, u32 a1);
void func_0203D9EC(void);
void func_0203DA20(void);
int func_0203DA4C(void);
void func_0203DA68(unsigned int value);
void *func_0203DA7C(void *a0, void *a1, void *a2);
void func_0203DAC4(const u8 *mac);
void func_0203DBB0(void *dst, u32 i);
void func_0203DC04(void);
void func_0203DC4C(void);
void func_0203DC68(NetLink *p, int state);
void func_0203DC70(void);
void *func_0203E420(void *arg);
void *func_0203E458(void *arg);
void func_0203E484(u32 a, u32 b, struct NetMacList *p);
u32 func_0203E4E8(void);
void func_0203E538(int a0);
int func_0203E590(void);
void func_0203E5AC(int a0);
extern Desc g_021469BC;
extern const char str_020A798C[];
extern void *g_021469C4;
extern u8 g_020A799C[];
extern const char file_020A79A4[];
extern const char str_020A79B4[];
extern const char file_020A79C0[];
extern char g_020A79C4[];
extern char g_020A79D0[];
extern char g_020A79D4[];
extern const u8 str_020A79C4[];
extern const u8 str_020A79EC[];
extern struct Notifier g_021469C8;
extern const char wm_icon_File[];
extern const char str_020A79F0[];
extern const char str_020A79FC[];
extern u8 d_020A7A20[];
extern char str_020A7A24[];
extern struct Net *g_021469D0;
extern u8 str_020A7A20[];
extern const u8 str_020A7A34[];
extern u8   g_020387A0[];
extern u8 g_020A7A20[];
extern u8 lbl_020A7A20[];
extern u8 d_020A7A24[];
extern u8 d_020A7A50[];
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
extern struct NetState *g_021469DC;
extern char g_020A7BA8[];
extern char g_020A7BB4[];
extern u32 g_02FFFC3C;
extern char unk_0203B018[];
extern char unk_0203B01C[];
extern char s_020A7BA8[];
extern char s_020A7BC8[];
extern char  unk_0203B228[];
extern char  unk_0203B22C[];
extern char str_0203B950[];
extern char str_0203B48C[];
extern const char str_0203C238[];
extern u8  g_020A7BEC[];
extern const char file_020A7BA8[];
extern const char file_020A7C70[];
extern u8  g_020A7C7C[];
extern const char file_020A7CA0[];
extern const char str_020A7CA8[];
extern const char str_020A7CB8[];
extern const char str_020A7CE8[];
extern struct NetMod g_021469E0;
extern char str_020A7CA0[];
extern char g_020A7CA0[];
extern char g_020A7CE8[];
extern char g_020A7CEC[];
extern const char file_020A7CF8[];
extern const char file_020A7D2C[];
extern NetLink *g_021469F0;
extern u8 d_020A7D34[];
extern const u8 str_020A7D34[];
extern const u8 str_020A7D48[];
extern const u8 str_020A7D4C[];
extern int *g_021469F4;
extern char s_020A7D34[];
extern char s_020A7D4C[];
extern char s_020A7D68[];
extern char s_020A7D74[];
extern char s_020A7DA0[];
extern char s_020A7E00[];
extern unsigned char *d_021469F0;




























/*
 * The "is the lid state low enough to keep running" predicate: normalise
 * func_0203568C's level to a boolean at the threshold 2.  Written as a
 * signed compare, so the two constant arms come out as movle/movgt off one
 * `cmp r0, #2` instead of a branch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020353B0.c \n *       --func sub_020353B0 --addr 0x020353B0 --cc 1.1p1 --arm
 */
int sub_020353B0(void)
{
    return func_0203568C() <= 2;
}




























/*
 * Run the +0x20 hook, but only when one is installed and sub_020353B0 says
 * the state allows it.  The two guards each carry their own `popeq`: a call
 * sits between them, so they cannot share an exit block and are two `if`s
 * rather than one `&&`.
 *
 * The hook pointer is re-read after the sub_020353B0 call, and the argument
 * at +0x30 is loaded before it, because nothing proves the call left the
 * context alone.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020353C8.c \n *       --func sub_020353C8 --addr 0x020353C8 --cc 1.1p1 --arm
 */
void sub_020353C8(struct Sys_020353B0 *p)
{
    if (p->on_20 == 0) {
        return;
    }
    if (func_020353B0() == 0) {
        return;
    }
    p->on_20(p->arg_30);
}



























/*
 * The context's veto predicate: the byte at +0x38 forces a yes, otherwise a
 * hook at +0x24 decides, and with no hook the answer is no.  The hook
 * pointer stays in r1 from its own null test through the `blx`, which is why
 * the argument at +0x34 is fetched into r0 second.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020353F8.c \n *       --func sub_020353F8 --addr 0x020353F8 --cc 1.1p1 --arm
 */
int sub_020353F8(struct Sys_020353B0 *p)
{
    if (p->always != 0) {
        return 1;
    }
    if (p->on_24 == 0) {
        return 0;
    }
    return p->on_24(p->arg_34);
}


























/*
 * Retry PM_SetBackLight on the bottom screen until it reports success or a
 * thousand attempts have gone by.  The loop counter is assigned before the
 * hoisted screen selector, which is what puts `mov r5, #0` ahead of
 * `mov r4, #2`
 * (docs/idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02035428.c \n *       --func sub_02035428 --addr 0x02035428 --cc 1.1p1 --arm
 */
void sub_02035428(u32 status)
{
    int i;

    for (i = 0; i < 1000; i++) {
        if (PM_SetBackLight(2, status) == 0) {
            return;
        }
    }
}

























/*
 * The lid/sleep service, one of the five sub_02034EF8 runs per frame.  Bit
 * 15 of the halfword at 0x02FFFFA8 is the lid-closed flag; when it is set
 * and the veto predicate sub_020353F8 says no, the machine goes to sleep
 * with the whole shutdown/wake sequence around it, and when the predicate
 * says yes the context is instead marked as suspended (+0x43) with the
 * backlight forced off.  An open lid undoes the suspension.
 *
 * The flag is read as a signed `int`, hence `asrs r1, r1, #0xf` rather than
 * a logical shift: the halfword zero-extends into an `int`, the mask keeps
 * it positive, and the shift inherits the signed type.
 *
 * The literal 0 sits in r5 for the whole function because PM_GoSleepMode's
 * second and third arguments and the +0x43 store all want it.
 *
 * PARKED AT MATCH.  Every concrete byte is right, and fifteen of the sixteen
 * relocation sites resolve.  The sixteenth, PM_GoSleepMode at 0x0208C154, is
 * reached from exactly one place in the whole image: the `bl` at 0x020354A4
 * inside this function.  `label` therefore has no outside branch, and
 * `matched` would need an EXACT manifest entry for TwlSDK libspi code.  No
 * split can help, because the site is inside the only function that needs
 * it.
 *
 * This is what caps src/pending/sub_02034EF8.c as well.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0203545C.c \
 *       --func sub_0203545C --addr 0x0203545C --cc 1.1p1 --arm
 */
void sub_0203545C(void)
{
    struct Sys_020353B0 *p;

    p = func_02035224();

    if ((*(u16 *)0x02FFFFA8 & 0x8000) >> 15) {
        if (func_020353F8(p) == 0) {
            func_02035E08();
            func_0203524C(p);
            PM_GoSleepMode(0xC, 0, 0);
            func_020353C8(p);
            func_020352AC(p);
            func_02035268(p);
            func_02035DC8();
            if (p->suspended != 0) {
                p->suspended = 0;
                func_02035428(p->backlight);
            }
        } else {
            if (p->suspended == 0) {
                p->suspended = 1;
                func_02035428(0);
                func_02035284(p);
                func_0203524C(p);
            }
        }
    } else {
        if (p->suspended != 0) {
            p->suspended = 0;
            func_02035428(p->backlight);
            func_02035268(p);
            func_020352AC(p);
        }
    }
}
























/*
 * The soft-reset trap: fade both screens to white, tear the UI down, then spin
 * forever pumping the main loop's per-frame work.  The loop never exits (the
 * image's tail is an unconditional `b` back to the func_0203D210 test), and
 * the reset path inside it returns through OS_ResetSystem.
 *
 * Both master-brightness registers come off one pool word: 0x0400006C is the
 * main engine's MASTER_BRIGHT and the sub engine's sits +0x1000 away, which is
 * why the image loads the base once into r5 and spells the second as
 * `add r0, r5, #0x1000`.  The brightness value 0x10 and the OS_WaitIrq mask
 * are both kept in r4 across the calls, and the `mov r4, #1` that retargets it
 * sits before the loop head.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035544.c \
 *       --func func_02035544 --addr 0x02035544 --cc 1.1p1 --arm
 */
void func_02035544(u32 param)
{
    struct Sys_020353B0 *ctx;

    ctx = sub_02035224();
    GXx_SetMasterBrightness_(0x0400006C, 0x10);
    GXx_SetMasterBrightness_(0x0400006C + 0x1000, 0x10);
    func_0203CEAC(0);

    while (1) {
        if (func_0203D210() != 0 && func_02076B8C() != 0) {
            sub_02035428(((u8 *)ctx)[0x3b]);
            OS_ResetSystem(param);
        }
        OS_WaitIrq(1, 1);
        func_0203CF5C();
        func_0204E638();
    }
}























/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0203560C, sub_02035614, sub_02035630, sub_02035648
 *
 * The accessor block of the singleton reached through the pointer at
 * 0x021469BC.  None of these eight functions saves lr, so disasm.py
 * labels none of them; they are visible only by sweeping addresses
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * The block is written as instance accessors plus global wrappers that
 * fetch the singleton and forward:
 *
 *   sub_020355C4  read the u8 at +0x3c of the singleton.
 *   sub_020355D8  write it.
 *   sub_020355EC  clear the u8 at +0x3e of a caller-supplied instance.
 *   sub_020355F8  write the u8 at +0x3d.  Takes an instance pointer for
 *                 symmetry with sub_0203560C but ignores it and goes
 *                 through the singleton anyway; the reload of the global
 *                 over r0 is the whole tell.
 *   sub_0203560C  read the u8 at +0x3d of a caller-supplied instance.
 *   sub_02035614  global wrapper over sub_020355F8.
 *   sub_02035630  global wrapper over sub_0203560C.
 *   sub_02035648  global wrapper over sub_020355EC.
 *
 * The range deliberately stops before sub_02035660, the one labelled
 * function of this file: its calls to 0x02036390 and 0x02035E54 have no
 * witness outside the file, so including it caps the whole unit at MATCH.
 * It is parked in src/pending/sub_02035660.c.
 *
 * Every wrapper is a pool word and a `bx ip`, never a displacement
 * branch, because each function is its own section
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020355C4.c \
 *       --addr 0x020355C4 --arm
 */
u8 sub_020355C4(void)
{
    return g_021469BC.sys->unk_3c;
}























void sub_020355D8(u8 v)
{
    g_021469BC.sys->unk_3c = v;
}























void sub_020355EC(struct Sys_020353B0 *p)
{
    p->unk_3e = 0;
}























void sub_020355F8(struct Sys_020353B0 *unused, u8 v)
{
    g_021469BC.sys->unk_3d = v;
}























u8 sub_0203560C(struct Sys_020353B0 *p)
{
    return p->unk_3d;
}























void sub_02035614(u8 v)
{
    sub_020355F8(g_021469BC.sys, v);
}























u8 sub_02035630(void)
{
    return sub_0203560C(g_021469BC.sys);
}























void sub_02035648(void)
{
    sub_020355EC(g_021469BC.sys);
}






















void sub_02035660(u8 v)
{
    sub_020355F8(g_021469BC.sys, v);
    sub_02036390(g_021469BC.sys);
    sub_02035E54(g_021469BC.sys);
}






















int func_0203568C(void)
{
    return g_021469BC.sys->unk_3f;
}























/*
 * A descriptor fan-out: the global at 0x021469BC carries a callback at +4
 * which fills two twelve-byte records on the stack, and the seven
 * accessors below push each pair into the object in a0.
 */
void func_020356A0(int a0)
{
    S12 b;
    S12 a;

    if (g_021469BC.f04 == 0) {
        return;
    }
    if (g_021469BC.f04(&b, &a) == 0) {
        return;
    }
    func_020363B8(a0, b.f00, a.f00);
    func_020363D4(a0, b.f02, a.f02);
    func_020363F0(a0, b.f04, a.f04);
    func_02035E84((void *)a0, b.f06, b.f08, a.f06, a.f08);
    func_02035EB0(a0, b.f0A, a.f0A);
    func_02035ECC(a0, b.f0B, a.f0B);
}






















int func_02035750(void){ return *(int *)(0x21469C4); }























/*
 * A one-liner over the object at 0x021469C4: when the kind byte at +0x3D is
 * 0x1E (30) the halfword at +0x64 is reported, otherwise the one at +0x5C.
 * The kind test is on the *argument*, the two halfwords on the object the
 * accessor func_02035750 returns, which is why the argument is kept in r4
 * across the call.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035760.c \
 *       --func func_02035760 --addr 0x02035760 --cc 1.1p1 --arm
 */
u16 func_02035760(struct Kind *p)
{
    u8 *q;

    q = (u8 *)func_02035750();
    if (p->unk3D == 0x1E)
        return ((struct Obj11334 *)q)->f64;
    return ((struct Obj11334 *)q)->f5C;
}






















/*
 * The second halfword pair of the same accessor family as
 * src/matched/func_02035760.c: kind byte +0x3D == 0x1E selects +0x66, else
 * +0x5E.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035780.c \
 *       --func func_02035780 --addr 0x02035780 --cc 1.1p1 --arm
 */
u16 func_02035780(struct Kind *p)
{
    u8 *q;

    q = (u8 *)func_02035750();
    if (p->unk3D == 0x1E)
        return ((struct Obj11335 *)q)->f66;
    return ((struct Obj11335 *)q)->f5E;
}






















/*
 * Third of the family in src/matched/func_02035760.c: kind byte +0x3D == 0x1E
 * selects +0x6A, else +0x62.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020357A0.c \
 *       --func func_020357A0 --addr 0x020357A0 --cc 1.1p1 --arm
 */
int func_020357A0(struct Kind *p)
{
    u8 *q;

    q = (u8 *)func_02035750();
    if (p->unk3D == 0x1E)
        return ((struct Obj11336 *)q)->f6A;
    return ((struct Obj11336 *)q)->f62;
}






















/*
 * Fourth of the family in src/matched/func_02035760.c: kind byte +0x3D ==
 * 0x1E selects +0x68, else +0x60.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020357C0.c \
 *       --func func_020357C0 --addr 0x020357C0 --cc 1.1p1 --arm
 */
u16 func_020357C0(struct Kind *p)
{
    u8 *q;

    q = (u8 *)func_02035750();
    if (p->unk3D == 0x1E)
        return ((struct Obj11337 *)q)->f68;
    return ((struct Obj11337 *)q)->f60;
}






















/*
 * Allocates the touched-icon work object (0x7c bytes), clears it, brings
 * the touch panel up and stores the calibration handed back by
 * TP_GetUserInfo.  When the user has no stored calibration (the call does
 * not answer 1) the four halfwords are filled with the firmware defaults
 * 0x2ae / 0x58c / 0xe25 / 0x1208; 0x58c is materialised as
 * `0x510 + 0x7c` because the size constant is still live in r6.  The
 * object pointer is published at 0x021469C4 and returned.
 *
 * The two bytes at +0x75/+0x76 are the state and the blinking flag of the
 * icon driver; the u16 pair at +0x58 is cleared before the panel is up.
 */
void *sub_020357E0(u32 id)
{
    u16 info[4];
    void *p = func_02030734(id, 0x7c, 0, str_020A798C, 0x83);

    MI_CpuFill8(p, 0, 0x7c);
    ((struct Obj07103 *)p)->f58 = 0;
    ((struct Obj07103 *)p)->f5A = 0;
    TP_Init();
    if (TP_GetUserInfo(info) == 1) {
        TP_SetCalibrateParam(info);
    } else {
        info[0] = 0x2ae;
        info[1] = 0x58c;
        info[2] = 0xe25;
        info[3] = 0x1208;
        TP_SetCalibrateParam(info);
    }
    ((struct Obj07103 *)p)->f75 = 4;
    ((struct Obj07103 *)p)->f76 = 0;
    g_021469C4 = p;
    return p;
}






















/*
 * The touch-panel sampling pass of the touchpanel.c family: it resolves the
 * work object, refuses to run with the lid closed, samples the panel (with a
 * bounded debounce retry), converts the raw sample, and then does the edge /
 * latch bookkeeping over the halfword block at +0x5c..+0x72.
 *
 * Bit 15 of the halfword at 0x02FFFFA8 is the lid-closed flag, the same
 * hardware address src/matched/sub_0203545C.c reads; it is a cast constant,
 * not a relocation (docs/idioms/volatile-reread-needs-two-locals.md).  When
 * it is set the whole 0x7c-byte object is cleared and the pass returns.
 *
 * Three declaration facts carry the register allocation, and none of them is
 * visible in the control flow:
 *
 *   - The two sample buffers are laid out `raw` first and `cal` second, but
 *     the ORIGINAL passes sp+8 to the sampler and sp+0 to the converter, so
 *     `cal` is the sp+0 object: the dispatch code the function tests is
 *     `cal.t` at [sp,#6] and the state word it latches is `cal.v` at [sp,#4].
 *     Getting those two fields the wrong way round moves every stack offset
 *     in the tail.
 *   - `struct Samp` is x, y, v, t: the `v`/`t` order is what puts the tested
 *     halfword at +6 rather than +4.
 *   - The resolver's result is bound to its own local `sio` DECLARED LAST and
 *     copied into `w`.  Initialising `w` from the call directly, or declaring
 *     `sio` before `w`, swaps r4 and r5 through the whole body; the extra
 *     copy is what splits the live range so that the loop counter keeps r4.
 *     The permuter found this as `temp(tmp=func_02035750(ctx))`.
 *
 * The `% 2 == 0` tail test compiles to the lsr/rsb/adds triple at +0x168,
 * the signed-remainder-by-two idiom on a signed char field.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020358A0.c \
 *       --func func_020358A0 --addr 0x020358A0 --cc 1.1p1 --arm
 */
void func_020358A0(struct Sys_020353B0 *ctx)
{
    struct Samp raw;
    struct Samp cal;
    struct Work *w;
    u32 done = 0;
    u32 n;
    struct Work *sio = (struct Work *)func_02035750();

    w = sio;
    if (w == 0) {
        return;
    }
    if ((s32)(*(u16 *)0x02FFFFA8 & 0x8000) >> 15 != 0) {
        func_02082BCC(w, 0, 0x7c);
        return;
    }
    if (w->f74 == 0) {
        n = 0;
        func_0208AB1C();
        if (func_0208ABB8((struct TPData *)(&raw)) != 0) {
            do {
                n = (n + 1) & 0xff;
                if (n >= 0x20) {
                    cal.t = 3;
                    done = 1;
                    break;
                }
                func_0208AB1C();
            } while (func_0208ABB8((struct TPData *)(&raw)) != 0);
        }
    } else {
        func_0208ADB4((struct TPData *)(&raw));
    }
    if (done == 0) {
        func_0208B104((struct TPData *)(&cal), (const struct TPData *)(&raw));
    }
    if (cal.t == 0) {
        w->f5c = cal.x;
        w->f5e = cal.y;
    } else if (w->f62 != 0) {
        if (cal.t != 1) {
            if (cal.t == 2) {
                w->f5c = cal.x;
            }
        } else {
            w->f5e = cal.y;
        }
    } else {
        cal.v = 0;
    }
    w->f60 = cal.v & (cal.v ^ w->f62);
    w->f62 = cal.v;
    w->f70 = w->f70 | w->f60;
    w->f72 = w->f72 | w->f62;
    if (w->f5e != 0) {
        w->f6e = w->f5e;
    }
    if (w->f5c != 0) {
        w->f6c = w->f5c;
    }
    if (ctx->unk_3e % 2 == 0) {
        w->f64 = w->f6c;
        w->f66 = w->f6e;
        w->f68 = w->f70;
        w->f6a = w->f72;
        w->f6c = 0;
        w->f6e = 0;
        w->f70 = 0;
        w->f72 = 0;
    }
}






















/*
 * Previously parked at MATCH: the `bl` to 0x020358A0 had no outside witness.
 * Closed 2026-09-22 (family wave 5) when 0x020358A0 was itself decompiled to
 * EXACT in src/matched/func_020358A0.c; that manifest entry is now the
 * witness and the site resolves on class `matched`.
 *
 * Two calls in a row: the first one's result is the second one's argument,
 * handed over in r0 with nothing in between.  Nothing else: no stack frame,
 * no locals.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035A60.c \
 *       --func func_02035A60 --addr 0x02035A60 --cc 1.1p1 --arm
 */
void func_02035A60(void)
{
    func_020358A0((struct Sys_020353B0 *)func_02035224());
}






















/*
 * The radius test of a packed four-byte record: (x - p[1])^2 + (y - p[2])^2 is
 * compared against p[3]^2, and the answer is 1 when it is strictly smaller.
 * The two differences are the second and third arguments, which is why the
 * argument registers r1 and r2 are subtracted from p[1] and p[2] rather than
 * the other way round.
 *
 * Two tells worth keeping.  The squared radius is computed with `smulbb`,
 * a 16x16 multiply, because p[3] is a `u8` and mwcc knows both factors fit in
 * sixteen bits; the two distance squares need the full 32-bit `mul`/`mla`
 * because their operands are `int` differences.  And the comparison is
 * unsigned (`movcc`/`movcs`), which is free here: both sides are sums of
 * squares and therefore non-negative, so mwcc may pick either.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035A70.c \
 *       --func func_02035A70 --addr 0x02035A70 --cc 1.1p1 --arm
 */
u32 func_02035A70(u8 *p, s32 x, s32 y)
{
    s32 dx = p[1] - x;
    s32 dy = p[2] - y;
    u32 r = p[3];

    return (u32)(dx * dx + dy * dy) < r * r;
}






















/*
 * The rectangular counterpart of src/matched/func_02035A70.c, on the same
 * packed four-byte record: a point (a, b) is inside when both distances from
 * the low corner fit in the record's width and height, each spelled as the
 * one-sided range test `v - lo <= hi - lo`.
 *
 * Written as `if (c1 && c2) return 1; return 0;`, the whole body compiles to
 * a single chain of conditionally executed instructions - the second pair of
 * loads, the two subtractions and the comparison all carry the LS condition
 * of the first comparison, and the two `movls`/`movhi` are the boolean - and
 * that chain is exactly the original.  A bare `return c1 && c2;` instead
 * presets a zero register and branches, which is 4 bytes longer and does not
 * match; the `return`-in-`if` spelling is what this source needs, the same
 * shape docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md
 * describes for the disjunction.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035AA4.c \
 *       --func func_02035AA4 --addr 0x02035AA4 --cc 1.1p1 --arm
 */
u32 func_02035AA4(u8 *p, u32 a, u32 b)
{
    if (a - p[2] <= (u32)(p[3] - p[2]) && b - p[0] <= (u32)(p[1] - p[0]))
        return 1;
    return 0;
}






















/*
 * The hit-test table walk of the touchpanel.c family.  It scans an array of
 * four-byte records for the first one the point (x, y) falls inside, and
 * returns that record's index, or -1 when the table runs out.  Byte 0 of a
 * record is the shape tag: 0xFF ends the table, 0xFD skips the entry, 0xFE
 * selects the circle test at func_02035A70 and anything else the rectangle
 * test at func_02035AA4.
 *
 * THE DECLARATION IS THE WHOLE FUNCTION.  Written with a `u8 *` parameter
 * and the record address spelled `p + i * 4` (any of: a `rec` local at any
 * scope, `&p[i*4]`, a `u32 *` base with a cast, or the expression written
 * out at each call site), the body compiles to a 21-byte residue in the head
 * that no amount of statement shuffling moves.  The original computes the
 * record address with `add r0, r7, r4, lsl #2` AFTER both argument moves,
 * keeping the tag byte in r0 across the two compares; every pointer-arithmetic
 * spelling hoists the address above the compares instead, which pushes the
 * tag into r1 and rotates the rest.
 *
 * Declaring the record as a struct and indexing the array (`p[i].t`, with
 * `&p[i]` cast for the calls) is what reproduces it: the address becomes an
 * addressing-mode computation the scheduler is free to sink below the
 * compares rather than a value that has to be live across them.  This is the
 * "residue the permuter cannot move at all is usually in the declarations"
 * case: tools/permuter.py plateaus at 8 bytes out from every pointer-spelled
 * start (its best single mutation, `temp(tmp=p + (i * 4))`, is a loop-invariant
 * hoist that is not value-preserving here), and the struct declaration is
 * EXACT with no mutation at all.
 *
 * Supersedes the near miss recorded in docs/notes/pkt_02035ADC.c.txt, which
 * tried four pointer spellings and reached the same 21-byte head.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035ADC.c \
 *       --func func_02035ADC --addr 0x02035ADC --cc 1.1p1 --arm
 */
int func_02035ADC(struct R *p, u32 x, u32 y)
{
    int i = 0;

    while (p[i].t != 0xff) {
        if (p[i].t != 0xfd) {
            if (p[i].t == 0xfe) {
                if (func_02035A70((u8 *)&p[i], x, y) != 0) {
                    return i;
                }
            } else {
                if (func_02035AA4((u8 *)&p[i], x, y) != 0) {
                    return i;
                }
            }
        }
        i++;
    }
    return -1;
}






















int func_02035B58(u32 a, u32 b)
{
    u32 x;
    u32 y;

    func_02035750();
    if (func_020357A0((struct Kind *)a) == 0) {
        return -1;
    }
    x = func_02035760((struct Kind *)a);
    y = func_02035780((struct Kind *)a);
    return func_02035ADC((struct R *)b, x, y);
}






















int func_02035BA4(const void *p)
{
    return func_02035B58((u32)func_02035224(), (u32)p);
}























int func_02035BBC(void *ctx, void *param)
{
    void *a;
    void *b;

    func_02035750();
    if (func_020357C0(ctx) == 0) {
        return -1;
    }

    a = (void *)func_02035760(ctx);
    b = (void *)func_02035780(ctx);

    return func_02035ADC(param, (u32)a, (u32)b);
}























int func_02035C08(const void *p)
{
    return func_02035BBC((void *)((int)func_02035224()), (void *)p);
}























int func_02035C20(const void *p)
{
    func_02035750();
    return func_020357A0((struct Kind *)p);
}























/*
 * A two-call forwarder in the ARM SDK-style block at 0x02035000..0x02038000:
 * "push {r3, lr}; bl sub_02035224; bl sub_02035C20; pop {r3, pc}", sixteen
 * bytes, no register setup between the calls: the first call's result is
 * still in r0 as the second call's argument, and the second call's result
 * is returned.
 *
 * Byte-correct.  sub_02035224 resolves on the `label` class (58 branches to
 * it image-wide, e.g. 0x02035460).  sub_02035C20 does not: this call is its
 * only reference anywhere in the image, so that site stays wildcarded and
 * caps the file at MATCH.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02035C38.c \
 *       --func sub_02035C38 --addr 0x02035C38 --cc 1.1p1 --arm
 */
int sub_02035C38(void)
{
    return sub_02035C20(sub_02035224());
}























/*
 * Hands the same context to both halves of the teardown pair.  The
 * argument is kept in a callee-saved register across the first call
 * rather than reloaded, which is what says it is one parameter passed
 * twice and not two different values.
 *
 * Decompiled to unstick src/pending/sub_02035C60.c, whose only blocking
 * relocation was this address: 0x02035C48 is reached by exactly one
 * branch image-wide (the `bl` at 0x02035C68 inside that caller), so class
 * `label` was unavailable and only an EXACT entry here could attest it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035C48.c \
 *       --func func_02035C48 --addr 0x02035C48 --cc 1.1p1 --arm
 */
u16 func_02035C48(struct Ctx02035C48 *ctx)
{
    func_02035750();
    return func_020357C0((struct Kind *)ctx);
}






















/*
 * Forward to func_02035C48 with the context func_02035224 supplies, same
 * "no context argument" shape as the block in unit_02035C70.c.
 *
 * func_02035C48's only call site anywhere in the image is the one right
 * here, inside this 16-byte function, so the `label` class has no witness
 * outside the range under test and --suggest-split cannot help (the
 * function is atomic; there is nothing to cut).  The site resolves on
 * class `matched` against src/matched/func_02035C48.c, decompiled for
 * exactly this purpose.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02035C60.c \
 *       --func sub_02035C60 --addr 0x02035C60 --cc 1.1p1 --arm
 */
int sub_02035C60(void)
{
    return func_02035C48((struct Ctx02035C48 *)func_02035224());
}























/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02035D40
 *
 * The singleton-facing half of the 0x02035000 block: every entry point here
 * is the "no context argument" spelling of a worker that lives a little
 * earlier in the file, with func_02035224() supplying the context.
 *
 * sub_02035C70 and sub_02035CD8 are the two two-output readers; they differ
 * only in which predicate gates them (0x020357A0 versus 0x020357C0).  Each
 * is called from exactly one place, its own wrapper in this same file, so
 * the two pairs have to live in one unit for those sites to close as
 * `local` (same shape as src/matched/unit_020362BC.c).
 *
 * sub_02035D40 has no label of its own in the listing: it is an unlabelled
 * follower of sub_02035D20 (its prologue saves nothing).  It is the u16
 * narrowing shim in front of func_02035ADC, and it is the pool-word-and-bx
 * tail call idiom, one section per function.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02035C70.c \
 *       --addr 0x02035C70 --arm
 */
u32 sub_02035C70(struct Sys_020353B0 *ctx, u32 *outA, u32 *outB)
{
    func_02035750();
    if (func_020357A0((struct Kind *)ctx) == 0) {
        return 0;
    }
    *outA = func_02035760((struct Kind *)ctx);
    *outB = func_02035780((struct Kind *)ctx);
    return 1;
}





















u32 sub_02035CB8(u32 *outA, u32 *outB)
{
    return sub_02035C70((struct Sys_020353B0 *)func_02035224(), outA, outB);
}





















u32 sub_02035CD8(struct Sys_020353B0 *ctx, u32 *outA, u32 *outB)
{
    func_02035750();
    if (func_020357C0((struct Kind *)ctx) == 0) {
        return 0;
    }
    *outA = func_02035760((struct Kind *)ctx);
    *outB = func_02035780((struct Kind *)ctx);
    return 1;
}





















u32 sub_02035D20(u32 *outA, u32 *outB)
{
    return sub_02035CD8((struct Sys_020353B0 *)func_02035224(), outA, outB);
}





















u32 sub_02035D40(struct Sys_020353B0 *ctx, u32 a, u32 b)
{
    return (u32)func_02035ADC((struct R *)ctx, (u16)a, (u16)b);
}






















/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02035E08, sub_02035E18
 *
 * The open/close pair of the 0x02035000 block's link layer, plus their
 * no-context wrappers.  sub_02035DD8 brings the link up (state word at +0x5a
 * goes to 1) and sub_02035D98 takes it down (state word goes back to 0);
 * both refuse to act unless the handle at +0x58 is live and the state is not
 * already where they would leave it.
 *
 * The four workers are kept in one unit deliberately: sub_02035D5C,
 * sub_02035D98, sub_02035DD8 and sub_02035E18 are each reached by exactly
 * one branch in the image, the one in this same file, so as separate files
 * every wrapper would cap at MATCH.  Inside one range each site is `local`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02035D5C.c \
 *       --addr 0x02035D5C --arm
 */
u32 sub_02035D5C(struct Hdr *p)
{
    if (p->unk58 == 0) {
        return 1;
    }
    func_0208AD14();
    func_0208B220(4);
    if (func_0208B238(4) != 0) {
        return 2;
    }
    return 1;
}





















void sub_02035D98(struct Hdr *p)
{
    struct Hdr *sio = (struct Hdr *)func_02035750();

    if (sio != 0 && sio->unk5a != 0 && sio->unk58 != 0) {
        sub_02035E18(sio);
        sio->unk5a = 0;
    }
}





















void sub_02035DC8(void)
{
    sub_02035D98((struct Hdr *)func_02035224());
}





















void sub_02035DD8(struct Hdr *p)
{
    struct Hdr *sio = (struct Hdr *)func_02035750();

    if (sio != 0 && sio->unk5a != 1 && sio->unk58 != 0) {
        sub_02035D5C(sio);
        sio->unk5a = 1;
    }
}





















void sub_02035E08(void)
{
    sub_02035DD8((struct Hdr *)func_02035224());
}





















u32 sub_02035E18(struct Hdr *p)
{
    u32 ret;

    func_0208AC0C(0, p->unk75, p->buf, 9);
    ret = 2;
    func_0208B220(2);
    if (func_0208B238(2) == 0) {
        ret = 1;
    }
    return ret;
}






















/*
 * Zeroes the eight-halfword counter block at +0x64 of the record
 * func_02035750 resolves its argument to.  One of the two follow-up passes
 * that src/pending/sub_02035660.c runs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02035E54.c \
 *       --func sub_02035E54 --addr 0x02035E54 --cc 1.1p1 --arm
 */
void sub_02035E54(struct Sys_020353B0 *p)
{
    struct Sio_02035E54 *sio = (struct Sio_02035E54 *)func_02035750();

    sio->unk64 = 0;
    sio->unk66 = 0;
    sio->unk68 = 0;
    sio->unk6a = 0;
    sio->unk6c = 0;
    sio->unk6e = 0;
    sio->unk70 = 0;
    sio->unk72 = 0;
}






















/*
 * The setter that mirrors the four accessors of src/matched/func_02035760.c:
 * four halfword stores into the object func_02035750 returns, at +0x64 and
 * +0x66 from the third and fifth arguments and at +0x6C and +0x6E from the
 * second and fourth.  The fifth argument is a stack argument, which is why
 * `ldrh r1, [sp, #0x10]` sits second - the argument area is above the pushed
 * {r4,r5,r6,lr}.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035E84.c \
 *       --func func_02035E84 --addr 0x02035E84 --cc 1.1p1 --arm
 */
void func_02035E84(void *p, u16 a, u16 b, u16 c, u16 d)
{
    u8 *q;

    q = (u8 *)func_02035750();
    ((struct Obj06933 *)q)->f64 = c;
    ((struct Obj06933 *)q)->f66 = d;
    ((struct Obj06933 *)q)->f5C = a;
    ((struct Obj06933 *)q)->f5E = b;
}






















int func_02035EB0(int a0, int a1, int a2){ int t0; t0 = func_02035750(); ((struct Obj11338 *)((char *)(t0)))->f68 = (unsigned short)a2; ((struct Obj11338 *)((char *)(t0)))->f60 = (unsigned short)a1; return t0; }























int func_02035ECC(int a0, int a1, int a2){ int t0; t0 = func_02035750(); ((struct Obj11339 *)((char *)(t0)))->f6A = (unsigned short)a2; ((struct Obj11339 *)((char *)(t0)))->f62 = (unsigned short)a1; return t0; }























T *func_02035EE8(u32 a)
{
    T *p = (T *)func_02030734(a, 0x4c, 0, (const char *)g_020A799C, 0x44);

    func_02082BCC(p, 0, 0x4c);
    p->f40 = 8;
    p->f44 = 0xf;
    return p;
}























static inline s32 PAD_DetectFold(void)
{
    return (s32)((*(vu16 *)HW_BUTTON_XY_BUF & 0x8000) >> 15);
}























static inline u16 PAD_Read(void)
{
    return (u16)(((*(vu16 *)REG_KEYINPUT | *(vu16 *)HW_BUTTON_XY_BUF) ^ PAD_ALL_MASK) & PAD_ALL_MASK);
}























/*
 * key.c.  The per-frame pad update: with the lid closed (PAD_DetectFold) the
 * six edge words are cleared; otherwise the pad is read (PAD_Read, the SDK
 * inline: KEYINPUT | the ARM7 XY buffer, ^ and & 0x2FFF, so the 0x2FFF mask
 * is the 0x02FFFFA8 pool word shifted right by 12, not a pool word of its
 * own), UP cancels DOWN and LEFT cancels RIGHT, trigger and repeat are
 * derived from the previous hold word at +0x0C, the repeat counter at +0x3C
 * reloads from +0x40 (speed) or +0x44 (delay), and func_020360B8 then remaps
 * the three published words before they are accumulated into +0x30..+0x38
 * and latched into +0x24..+0x2C on every other frame (ctx->unk_3e, a SIGNED
 * modulo-2 test on a u8 byte).  Both hardware addresses are cast constants, not
 * relocations.  Written from the SDK inline shapes (NitroSDK pad.h, library
 * function shapes only); EXACT on the first transcription.
 */
void func_02035F38(struct Sys_020353B0 *ctx)
{
    struct Key *k = (struct Key *)func_0203521C((u32 *)ctx);
    u16 key;

    if (PAD_DetectFold()) {
        k->f1c = 0;
        k->f18 = 0;
        k->f20 = 0;
        k->f28 = 0;
        k->f24 = 0;
        k->f2c = 0;
        return;
    }

    key = PAD_Read();
    key = key & ~((key & 0x40) << 1) & ~((key & 0x20) >> 1);

    k->trg = key & (key ^ k->cont);
    k->rpt = key & (key ^ k->cont);
    if (key != 0 && k->cont == key) {
        if (--k->wait == 0) {
            k->rpt = key;
            k->wait = k->speed;
        }
    } else {
        k->wait = k->delay;
    }
    k->cont = key;
    k->f1c = k->trg;
    k->f18 = key;
    k->f20 = k->rpt;
    func_020360B8((struct Obj *)k);
    k->f34 |= k->f1c;
    k->f30 |= k->f18;
    k->f38 |= k->f20;
    if (ctx->unk_3e % 2 != 0) {
        return;
    }
    k->f28 = k->f34;
    k->f24 = k->f30;
    k->f2c = k->f38;
    k->f34 = 0;
    k->f30 = 0;
    k->f38 = 0;
}






















/*
 * The no-context spelling of func_02035F38: fetch the singleton with
 * func_02035224 and hand it over.  Sixteen bytes, no register setup between
 * the two calls, so the argument count is not visible from the code; the
 * one-argument reading is the one the rest of this file's wrappers take
 * (compare src/matched/unit_020362BC.c).
 *
 * PARKED AT MATCH.  Every concrete byte is right.  func_02035224 resolves on
 * `label`; func_02035F38 does not, because the `bl` at 0x020360B0 inside this
 * function is its only reference anywhere in the image.
 *
 * Identical situation to src/pending/sub_02035A60.c: a tu over
 * 0x02035F38..0x020360B8 would make the site `local`, and 0x02035F38 is 360
 * bytes, left for whoever takes pkt_02035E84.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_020360A8.c \
 *       --func sub_020360A8 --addr 0x020360A8 --cc 1.1p1 --arm
 */
void sub_020360A8(void)
{
    func_02035F38((struct Sys_020353B0 *)func_02035224());
}






















static inline void m2(u32 *f, struct Ent *p)
{
    u32 v = 0;
    if (*f & p->f00)
        v |= p->f04;
    if (*f & p->f04)
        v |= p->f00;
    *f &= (p->f00 | p->f04) ^ 0xffff;
    *f |= v;
}




















static inline void m1(u32 *f, struct Ent *p)
{
    if (*f & p->f00)
        *f |= p->f04;
}




















static inline void m3(u32 *f, struct Ent *p)
{
    *f &= p->f00 ^ 0xffff;
}




















/*
 * key.c.  Walks a run of 12-byte entries from o->f00 + o->f08 * 12 and
 * applies each entry's mask/value pair to the three state words at
 * +0x1c/+0x18/+0x20: case 1 ORs the value in where the mask matches, case 2
 * swaps the two bit groups (m2), case 3 clears the mask's bits, and case 0
 * ends the walk.  The function has no relocations; its one pooled word is the
 * constant 0x0000FFFF.
 *
 * What closed it (wave 13): the case-2 accumulator is a FRESH zero per field
 * (`u32 v = 0;` inside a per-field helper, or equally a block-scoped local).
 * The three zeros are three distinct values that the optimiser hoists as
 * r3/r2/r1 ahead of the loop, and that is what leaves lr, the highest
 * callee-saved register, for 0xFFFF.  The earlier source kept three
 * function-scope accumulators a, b, c = 0 and copied them into one v per arm;
 * every instruction was right but 0xFFFF and the arm temporaries rotated
 * through r4/r5/r6/lr (127 bytes).  The two compound statements
 * `*f &= mask; *f |= v;` (not one merged assignment) are still what
 * re-reads the field before the AND.
 */
void func_020360B8(struct Obj *o)
{
    struct Ent *p;

    if (o->f00 == 0)
        return;

    p = (struct Ent *)(o->f00 + o->f08 * 12);

    for (;;) {
        switch (p->f08) {
        case 0:
            return;
        case 1:
            m1(&o->f1c, p);
            m1(&o->f18, p);
            m1(&o->f20, p);
            break;
        case 2:
            m2(&o->f1c, p);
            m2(&o->f18, p);
            m2(&o->f20, p);
            break;
        case 3:
            m3(&o->f1c, p);
            m3(&o->f18, p);
            m3(&o->f20, p);
            break;
        }
        p++;
    }
}





















int func_02036254(int a0, int a1, int a2)
{
    struct Rec_02036254 *r = (struct Rec_02036254 *)func_0203521C((u32 *)a0);

    r->f40 = a1;
    r->f44 = a2;
    return (int)r;
}




















int func_02036270(int a0, int a1)
{
    return func_02036254((int)func_02035224(), a0, a1);
}





















int func_02036290(int a0, const void *a1)
{
    struct Rec_02036290 *r = (struct Rec_02036290 *)func_0203521C((u32 *)a0);

    r->f0 = a1;
    return (int)r;
}























void func_020362A4(const void *p)
{
    func_02036290((int)func_02035224(), p);
}























/*
 * A whole translation unit, matched as one byte range.
 *
 * sub_020362BC picks one of two key masks out of the record returned by
 * func_0203521C, keyed on a one-byte mode tag at +0x3d of its own argument;
 * sub_020362DC is the two-call wrapper that runs func_02035224 first.
 *
 * The two are kept in one unit deliberately: sub_020362DC's only call to
 * sub_020362BC has no witness anywhere else in the image, so as separate
 * files sub_020362DC caps at MATCH.  Inside one range the site is `local`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020362BC.c \
 *       --addr 0x020362BC --arm
 */
u32 sub_020362BC(struct Sys_020353B0 *ctx)
{
    struct Rec_020362BC *rec = (struct Rec_020362BC *)func_0203521C((u32 *)ctx);

    if (ctx->unk_3d == 30) {
        return rec->unk_28;
    }
    return rec->unk_1c;
}





















u32 sub_020362DC(void)
{
    return sub_020362BC((struct Sys_020353B0 *)func_02035224());
}






















/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0203634C, sub_02036370
 *
 * Three more of the mode-keyed record accessors that src/matched/
 * unit_020362BC.c opens: each picks one of two key masks out of the record
 * func_0203521C returns, keyed on the one-byte mode tag at +0x3d of the
 * context, and each is paired with a no-context wrapper that supplies the
 * context from func_02035224().  sub_0203634C is the two-output form and
 * reads the same field pair for either mode.
 *
 * The three workers have no caller but their own wrapper in this file, so
 * as separate files every wrapper would cap at MATCH; inside one range each
 * site is `local`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020362EC.c \
 *       --addr 0x020362EC --arm
 */
u32 sub_020362EC(struct Sys_020353B0 *ctx)
{
    struct Rec_020362EC *rec = (struct Rec_020362EC *)func_0203521C((u32 *)ctx);

    if (ctx->unk_3d == 30) {
        return rec->unk_24;
    }
    return rec->unk_18;
}





















u32 sub_0203630C(void)
{
    return sub_020362EC((struct Sys_020353B0 *)func_02035224());
}





















u32 sub_0203631C(struct Sys_020353B0 *ctx)
{
    struct Rec_020362EC *rec = (struct Rec_020362EC *)func_0203521C((u32 *)ctx);

    if (ctx->unk_3d == 30) {
        return rec->unk_2c;
    }
    return rec->unk_20;
}





















u32 sub_0203633C(void)
{
    return sub_0203631C((struct Sys_020353B0 *)func_02035224());
}





















void sub_0203634C(struct Sys_020353B0 *ctx, u32 *outA, u32 *outB)
{
    struct Rec_020362EC *rec = (struct Rec_020362EC *)func_0203521C((u32 *)ctx);

    *outA = rec->unk_40;
    *outB = rec->unk_44;
}





















void sub_02036370(u32 *outA, u32 *outB)
{
    sub_0203634C((struct Sys_020353B0 *)func_02035224(), outA, outB);
}






















/*
 * Zeroes the six-word block at +0x24 of the record func_0203521C resolves
 * its argument to.  The other follow-up pass that src/pending/sub_02035660.c
 * runs (see src/matched/sub_02035E54.c for the first).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02036390.c \
 *       --func sub_02036390 --addr 0x02036390 --cc 1.1p1 --arm
 */
void sub_02036390(struct Sys_020353B0 *p)
{
    struct Rec_02036390 *rec = (struct Rec_02036390 *)func_0203521C((u32 *)p);

    rec->unk24 = 0;
    rec->unk28 = 0;
    rec->unk2c = 0;
    rec->unk30 = 0;
    rec->unk34 = 0;
    rec->unk38 = 0;
}





















int func_020363B8(int a0, int a1, int a2)
{
    struct Rec_020363B8 *r = (struct Rec_020363B8 *)func_0203521C((u32 *)a0);

    r->f28 = a2;
    r->f1C = a1;
    return (int)r;
}





















int func_020363D4(int a0, int a1, int a2)
{
    struct Rec_020363D4 *r = (struct Rec_020363D4 *)func_0203521C((u32 *)a0);

    r->f24 = a2;
    r->f18 = a1;
    return (int)r;
}





















int func_020363F0(int a0, int a1, int a2)
{
    struct Rec_020363F0 *r = (struct Rec_020363F0 *)func_0203521C((u32 *)a0);

    r->f2C = a2;
    r->f20 = a1;
    return (int)r;
}
























/*
 * Initialises a small record: the two leading words get the first two
 * arguments, and the two halfwords at +0x0C and +0x0E are cleared.  The
 * second argument is declared `s16` and that is visible in the code: the
 * compiler sign-extends it with an `lsl #16` / `asr #16` pair before the
 * two-word `stmia`, which is the only way a narrowed parameter reaches a
 * 32-bit store.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203640C.c \
 *       --func func_0203640C --addr 0x0203640C --cc 1.1p1 --arm
 */
void func_0203640C(struct Rec *p, u32 a, int b)
{
    p->unk0 = a;
    p->unk4 = (short)b;
    p->unkC = 0;
    p->unkE = 0;
}























/*
 * net_ring_buff.c's write: refuse (func_02039548) unless the free space
 * (func_02036640) exceeds len, then copy len bytes in at the +0xE write
 * cursor modulo the capacity (func_02036624), asserting src != NULL at line
 * 0x44 each byte, and store the wrapped cursor back.  The write cursor is
 * declared volatile: the loop bound re-reads it every pass and the first
 * read happens twice, exactly as the image does (the same re-read shape the
 * matched func_020365E8 spells with volatile casts).
 */
void func_02036428(NetRingBuff *r, const u8 *src, int len)
{
    int i;
    int k;

    if (func_02036640((char *)r) <= len) {
        func_02039548();
        return;
    }
    k = 0;
    for (i = r->tail; i < r->tail + len; i++) {
        if (src == 0) {
            func_02034714(file_020A79A4, 0x44, str_020A79B4);
        }
        r->buf[func_02036624(r, i)] = src[k];
        k++;
    }
    r->tail = (short)func_02036624(r, i);
}























/*
 * Blocked: the PC24 at +0008 to 0x02036568 has no witness of any class and no
 * manifest entry is possible this pass: 0x02036568 is a 128-byte ARM function
 * whose C is byte-correct except an eight-instruction schedule permutation of
 * its loop tail (seven spellings measured, all identical) - a DIFF, see
 * docs/notes/pkt_02036568.c.txt.  The second site (func_02036624) resolves as
 * `matched`.  Every concrete byte here reproduces.
 */
int func_020364D4(NetRingBuff *p, unsigned char *dst, u32 len, u32 max)
{
    int d = func_02036568(p, dst, len, max);
    p->head = (short)func_02036624(p, p->head + d);
    return d;
}
























/*
 * PARKED AT MATCH.  Every concrete byte is right; the one open site is the
 * second pool word, file_020A79C0, whose only literal pool in the whole image
 * is this function's own, at 0x0203653C and therefore inside the compared
 * range.  The `string` class cannot stand in for it either: 0x020A79C0 holds
 * the one-character string "0" (the listing shows `.word 0x00000030` there,
 * preceded by the terminator of "pDataArea"), and attest_string() requires at
 * least four printable characters before the NUL, so the address is refused by
 * rule 2.  It closes the day the same string address is referenced from a pool
 * outside this range, or the rule's four-character floor is revisited for
 * one-character strings.  The three other sites resolve: func_020364D4 and
 * func_02034714 as `label`, file_020A79A4 as `literal`.
 */
u32 func_02036500(NetRingBuff *a)
{
    u8 b;

    if (func_020364D4(a, &b, 1, 1) == 1)
        return b;
    func_02034714(file_020A79A4, 0x6C, file_020A79C0);
    return 0;
}
























/*
 * Packs two bytes read through src/matched/func_02036500.c into one halfword,
 * high byte first.  The same call is made twice with the same argument.
 *
 * The shape that reproduces the original is `hi = (u16)(call << 8);` - the
 * `u16` narrowing folded into the shift, which mwcc encodes as `lsl r4, r0,
 * #24` (`(x << 8) mod 2^16` starts its life as `x << 24`) with the companion
 * half of the pair spent as the *shift operand* of the `orr`, `orr r0, r0, r4,
 * lsr #16`.  Spelling the mask as a value first - `hi = (u8)call;` or
 * `(u8)hi << 8` - makes mwcc emit `and r4, r0, #0xFF` followed by
 * `orr r0, r0, r4, lsl #8` instead: the same two instructions, the same
 * result, different bytes.  This is the unequal-shift-pair tell of
 * docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md
 * one level up: with the mask inline mwcc picks the AND form, so the mask has
 * to be on the narrowed *variable*, not on the shifted expression.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036540.c \
 *       --func func_02036540 --addr 0x02036540 --cc 1.1p1 --arm
 */
u32 func_02036540(NetRingBuff *a)
{
    u16 hi;
    u32 lo;

    hi = (u16)(func_02036500(a) << 8);
    lo = func_02036500(a);
    return (u16)(hi | lo);
}























/*
 * wm_icon.c ring reader. Wave 17 lane untried_small, from 25 out: the ring
 * is a const pointer, in this function and in func_02036624's prototype (both
 * only read it). With the read-only qualifier the compiler hoists the
 * loop-bottom bound load above the byte store through dst, as the image does.
 * The write cursor +0x0E stays volatile (the func_02036428 lever).
 */
int func_02036568(const NetRingBuff *r, u8 *dst, int len, int max)
{
    int i;
    int n;

    n = 0;
    for (i = r->head; i < r->head + len; i++) {
        if (r->tail == func_02036624((void *)r, i) || n == max) {
            return n;
        }
        dst[n] = r->buf[func_02036624((void *)r, i)];
        n++;
    }
    return n;
}























/*
 * 36 bytes with no call: the distance from the cursor at p+0x0C to the end of
 * the buffer at p+0x0E, answered from the buffer base at p+4 when the cursor is
 * past the end.
 *
 * The halfword at p+0x0E is read three times in the original (condition, both
 * arms), which is why it is spelled as a field read in each place rather than
 * bound to a local. Spelling all three as plain field reads is not enough on
 * this front end: it CSEs the two arm reads into the condition's register and
 * the function comes out one instruction (4 bytes) short at 32. Declaring the
 * two arm reads `volatile` keeps all three loads, which is the original's shape.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020365E8.c \
 *       --func func_020365E8 --addr 0x020365E8 --cc 1.1p1 --arm
 */
int func_020365E8(NetRingBuff *p)
{
    int a = p->head;

    if (a > p->tail)
        return p->size + *(volatile short *)&p->tail - a;
    return *(volatile short *)&p->tail - a;
}





















int func_0203660C(NetRingBuff *r)
{
    int t0 = func_020365E8(r);

    return r->size - t0;
}























int func_02036624(void *p, int v)
{
    return v % ((struct Obj15900 *)p)->f4;
}























static inline int RingUsed(char *p)
{
    int a = ((struct Obj05731 *)p)->fC;
    if (a > ((struct Obj05731 *)p)->fE)
        return ((struct Obj05731 *)p)->f4 + *(volatile short *)&((struct Obj05731 *)p)->fE - a;
    return *(volatile short *)&((struct Obj05731 *)p)->fE - a;
}























/*
 * Free space of a net_ring_buff.c ring: capacity (+4) minus the used count.
 * The used count is the body of the matched sibling func_020365E8 inlined
 * verbatim (its two volatile re-reads of the +0xE cursor are what keep the
 * per-arm reloads the earlier DIFF note could not reproduce).
 */
int func_02036640(char *p)
{
    return ((struct Obj15901 *)p)->f4 - RingUsed(p);
}






















void func_0203666C(NetRingBuff *r) { }























/*
 * Finds the first of `p->unk1C` records (stride 0x14) whose halfword at +0x0E
 * is zero and returns a pointer to it, or NULL when the count is not positive
 * or no record matches.  The found case is a bare `bxeq lr` with the moving
 * pointer still in r0, which is what makes the return type a pointer rather
 * than a boolean: the function returns the record it found, not 1.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036670.c \
 *       --func func_02036670 --addr 0x02036670 --cc 1.1p1 --arm
 */
NetNode *func_02036670(NetQueue *p)
{
    NetNode *q;
    s32  i;
    s32  n;

    q = p->f18;
    n = p->f1C;
    for (i = 0; i < n; i++) {
        if (q->fE == 0)
            return q;
        q++;
    }
    return 0;
}























int func_020366A8(NetQueue *p)
{
    return func_020366C0(p) == 0;
}






















/*
 * Counts the 20-byte records of the array at p+0x18 whose halfword at +0x0E is
 * non-zero, up to the count in p+0x1C.  60 bytes, no calls, no pool: the loop
 * is rotated and the test is a predicated `addne`.
 *
 * The declaration order is the whole lever.  Declared `e, i, c, n` the four
 * locals land in r1, r2, r3 and ip exactly as the image has them: the cursor
 * first, then the index, then the counter (whose `mov r3, #0` then feeds
 * `mov r2, r3` for the index), and the bound last in ip, so the bound's load
 * is the one that survives to just before the `ble`.  With the bound declared
 * first - how this file previously stood - the bound takes r2, the cursor r3
 * and the counter ends up in r0, which frees the `mov r0, r3` before the
 * return and shortens the body to 56 bytes (DIFF).  A param pointer (`u32 *p`
 * plus `q = (u8 *)p[6]`) does not reach it either: the four locals colour the
 * same way whatever the order.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020366C0.c \
 *       --func func_020366C0 --addr 0x020366C0 --cc 1.1p1 --arm
 */
int func_020366C0(NetQueue *p)
{
    const NetNode *e = p->f18;
    int            i;
    int            c = 0;
    int            n = p->f1C;

    for (i = 0; i < n; i++, e++) {
        if (e->fE != 0)
            c++;
    }
    return c;
}






















/*
 * Pops one entry off a singly linked list held at p[0], one link at a time:
 * the successor is p[0]->unk8; when it exists it becomes the new head and its
 * own back pointer at +4 is cleared, otherwise the head and the word after it
 * are both zeroed.  Returns 0 only when the list was already empty.
 *
 * Every arm is conditional-executed, so the function has exactly one `bx lr`
 * per exit and both `strne`/`streq` groups sit on the same `cmp`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020366FC.c \
 *       --func func_020366FC --addr 0x020366FC --cc 1.1p1 --arm
 */
u32 func_020366FC(u32 *p)
{
    u32 v;

    v = p[0];
    if (v != 0) {
        v = ((struct Obj11348 *)v)->f8;
        if (v != 0) {
            p[0] = v;
            ((struct Obj11348 *)v)->f4 = 0;
        } else {
            p[0] = 0;
            p[1] = 0;
        }
        return 1;
    }
    return 0;
}






















void func_02036738(NetOutBuf *q, int v)
{
    *q->ptr = (u8)v;
    q->ptr = q->ptr + 1;
    q->len = q->len - 1;
}























int func_0203675C(NetSendItem *item, NetOutBuf *out)
{
    func_02036738(out, (item->fE >> 8) & 0xff);
    func_02036738(out, item->fE & 0xff);
    func_02036738(out, (item->rest >> 8) & 0xff);
    func_02036738(out, item->rest & 0xff);
    func_02036738(out, item->f10);
    return 0;
}
























/*
 * Moves one queued send item into an output window: on first touch writes
 * the item's five-byte header (func_0203675C, refused with 0 when a header
 * is required and the window cannot hold rest + 5), then copies as much of
 * the payload as fits -- from the item's own source pointer with
 * MI_CpuCopy8, or out of the ring with func_020364D4 when it has none.  A
 * partial copy leaves the window marked full (0xFFFF) and the item's
 * header flag set; a complete one advances the window.  Exact on the first
 * compile from the image's field widths.
 */
int func_020367C4(NetSendItem *item, NetOutBuf *out, void *ring, BOOL needHeader)
{
    if (item->headerDone == 0) {
        if (needHeader != 0 && out->len < item->rest + 5) {
            return 0;
        }
        func_0203675C(item, out);
    }
    if (out->len < item->rest) {
        if (item->src == 0) {
            func_020364D4(ring, out->ptr, out->len, out->len);
        } else {
            MI_CpuCopy8(item->src, out->ptr, out->len);
            item->src += out->len;
        }
        item->rest = item->rest - out->len;
        out->len = 0xffff;
        item->headerDone = 1;
        return 1;
    }
    if (item->src == 0) {
        func_020364D4(ring, out->ptr, item->rest, item->rest);
    } else {
        MI_CpuCopy8(item->src, out->ptr, item->rest);
    }
    out->ptr += item->rest;
    out->len = out->len - item->rest;
    return 1;
}
























/*
 * blocked:  own-pool - the only pooled words naming g_020A79D0 (0x020A79D0 "0")
 *           and g_020A79D4 (0x020A79D4 "(u16)size < (0xffff/2)") sit inside this
 *           function's own pool at 0x020369BC/0x020369C4; every other witness is
 *           inside 0x020368C0..0x020369C8, so the two ABS32 fields stay wildcarded.
 *           g_020A79C4 ("net_queue.c") does have 10 outside witnesses (literal class).
 *           Verified byte-correct otherwise: 264/264, 0 concrete bytes differ.
 */
int func_020368C0(NetQueue *q, u32 a1, const u8 *a2, u32 a3, u32 a4, u32 a5, u32 a6)
{
    NetNode *n = func_02036670(q);

    if (n == 0) {
        func_02034714(g_020A79C4, 0xdb, g_020A79D0);
        return 0;
    }
    if (!((u16)a3 < 0xffff / 2)) {
        func_02034714(g_020A79C4, 0xdf, g_020A79D4);
    }
    if (a5 != 0) {
        if (!((int)(a3 + 5) < (int)func_0203660C(q->f14))) {
            func_02034714(g_020A79C4, 0xe3, g_020A79D0);
            return 0;
        }
        func_02036428(q->f14, a2, a3);
        func_0203666C(q->f14);
        n->f0 = 0;
    } else {
        n->f0 = a2;
    }
    n->fC = a3;
    n->fE = a1;
    n->f10 = a6;
    n->f11 = 0;
    if (q->f4 == 0) {
        q->f4 = n;
        q->f0 = n;
    } else {
        q->f4->f8 = n;
        n->f4 = q->f4;
        q->f4 = n;
    }
    return 1;
}
























/*
 * First non-null of three words of a queue owner: the word at +0x10, then the
 * word at +0, then the word at +8.  The first two arms load into r1 and only
 * move the answer into r0 on the taken path (`movne r0, r1`); the third arm
 * loads straight into r0, so its null case is the single `moveq r0, #0` that
 * the source's trailing `return 0;` produces.  Both taken arms branch on the
 * compare itself (`bxne lr`) instead of jumping to the shared epilogue.
 *
 * Written with three separate `if (...) return ...;` statements rather than a
 * chain of `?:`: the compiler rejects the GNU `?:` extension outright
 * (CCERR), and the merged `if` chain (`if (a) return a; if (b) return b;
 * return c;`) is 36 bytes and folds the third test away.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020369C8.c \
 *       --func func_020369C8 --addr 0x020369C8 --cc 1.1p1 --arm
 */
u32 func_020369C8(u32 *p)
{
    if (p[4] != 0)
        return p[4];
    if (p[0] != 0)
        return p[0];
    if (p[2] != 0)
        return p[2];
    return 0;
}
























/*
 *           the file string at 0x020A79C4 is not NUL-terminated immediately
 *           before this message, so the `string` class refuses. Every concrete
 *           byte of the body reproduces.
 */
void func_020369F8(u8 *p)
{
    if (((struct Obj11349 *)p)->f10 != 0) {
        ((struct Obj11349 *)p)->f10 = 0;
        return;
    }
    if (func_020366FC((u32 *)p) != 0) {
        return;
    }
    if (func_020366FC((u32 *)(p + 8)) != 0) {
        return;
    }
    func_02034714((char *)((const char *)str_020A79C4), 0x12f, (char *)((const char *)str_020A79EC));
}
























/*
 *           unlabelled work not in the slice and itself only called from here)
 *           and func_020367C4 (pkt_020367C4, not this lane's).  Filing
 *           func_020369F8 would still leave func_020367C4 unwitnessed, so the
 *           park is capped either way.
 *
 * Byte-identical at 164 bytes; only the two PC24 call fields at +0x40 and
 * +0x54 stay wildcarded (func_020369C8 resolves `matched`, func_02082BCC
 * resolves `label x566`).
 *
 * Spellings that mattered: every `return 1` must be a `goto` to one label at
 * the END of the function -- plain `return`s make mwcc predicate all three of
 * them inline (`moveq r0,#1; popeq`) and the frame shifts by 25 bytes.  And
 * `flag = 1;` sits BEFORE the 0xFFFF test, which is why the original shows
 * `mov r8,r6` between the `ldrh` and the `cmp`.
 */
int func_02036A50(u32 list, u16 *info)
{
    int flag = 0;

    if (info[2] == 0)
        goto done;
    while (1) {
        int slot = func_020369C8((u32 *)list);

        if (slot == 0)
            goto done;
        func_020369F8((u8 *)list);
        if (func_020367C4((NetSendItem *)slot, (NetOutBuf *)info, (void *)(((struct Obj08825 *)list)->f14), flag) == 0) {
            ((struct Obj08825 *)list)->f10 = slot;
            goto done;
        }
        flag = 1;
        if (info[2] == 0xffff) {
            ((struct Obj08825 *)list)->f10 = slot;
            return 0;
        }
        func_02082BCC((void *)slot, 0, 0x14);
        if (info[2] == 0)
            break;
    }
done:
    return 1;
}























void func_02036AF4(NetQueue *p, u32 n, NetRingBuff *a, u32 b)
{
    func_02082BCC(p, 0, 0x28);
    p->f18 = func_02030734(b, n * 0x14, 1, (const char *)str_020A79C4, 0x173);
    p->f1C = n;
    p->f14 = a;
}























int func_02036B4C(NetQueue *p)
{
    void *t0 = func_02082BCC(p->f18, 0, p->f1C * 0x14);

    p->f0 = 0;
    p->f4 = 0;
    p->f8 = 0;
    p->fC = 0;
    p->f10 = 0;
    return (int)t0;
}
























void func_02036B88(NetQueue *a0) { func_020307B0(a0->f18); }

























/*
 * Scan the 0x14-stride records behind p's +0x18 pointer for one whose
 * halfword at +0x0E equals the argument; the count is p's word at +0x1C.  A
 * hit returns 1 from inside the loop (`moveq r0, #1` / `bxeq lr`), a miss
 * falls out to `mov r0, #0`.
 *
 * The three scratch registers are decided by declaration order alone: the
 * index declared first takes r2, the record cursor declared second takes r3
 * and the count declared last takes ip.  Any other order of the same three
 * declarations moves the count into r2 or the cursor into ip and misses by
 * seven instructions' worth of register names.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036B98.c \
 *       --func func_02036B98 --addr 0x02036B98 --cc 1.1p1 --arm
 */
int func_02036B98(NetQueue *p, int v)
{
    int      i;
    NetNode *e = p->f18;
    int      n = p->f1C;

    for (i = 0; i < n; i++, e++) {
        if (e->fE == v)
            return 1;
    }
    return 0;
}

























/*
 * TU: wm_icon.c.  The __FILE__ pointer at 0x020A79F0 reads "wm_icon.c"
 * (line 100 here), which names the whole 0x020366C0-0x020371AC block: the
 * wireless-connection icon.
 *
 * Nine parameters, four in registers and five on the stack, and the first
 * one is never read: every caller passes 0 there.  When the caller hands in
 * a null block, a fresh 0x14-byte one is allocated on the heap named by the
 * low 15 bits of the second argument with bit 15 forced on.  The two
 * halfwords at +0x04 / +0x06 take the caller's values unless the override
 * pair in the global at 0x021469C8 is armed, in which case the whole `if`
 * body is predicated rather than branched.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036BD4.c \
 *       --func func_02036BD4 --addr 0x02036BD4 --cc 1.1p1 --arm
 */
struct Handler *func_02036BD4(u32 unused, u32 b, u32 c, u32 d, u32 e,
                              struct Handler *h, u32 kind, u32 busy,
                              u32 unk00)
{
    if (h == 0)
        h = func_02030734((u16)(((u16)b & 0x7fff) | 0x8000), 0x14, 0,
                          wm_icon_File, 100);

    h->unk04 = c;
    h->unk06 = d;

    if (g_021469C8.unk00 != 0) {
        h->unk04 = g_021469C8.unk00;
        h->unk06 = g_021469C8.unk02;
    }

    h->unk00 = unk00;
    h->unk0c = e;
    h->busy  = busy;
    h->kind  = kind;
    h->unk0f = 0;
    h->unk10 = 0x7000000;

    func_02036F24(func_02036D64((u8 *)h), h->unk0c, (u16)b);
    return h;
}
























static inline void G2_SetOBJAttr(GXOamAttr *oam, int x, int y, int priority,
                                 int mode, BOOL mosaic, int effect, int shape,
                                 int color, int charName, int cParam, int rsParam)
{
    oam->attr01 = (u32)(((y & 0xff) << 0) |
                        (mode << 10) |
                        (mosaic << 12) |
                        effect |
                        (color << 13) |
                        shape |
                        ((x & 0x1ff) << 16) |
                        (rsParam << 25));
    oam->attr2 = (u16)((charName << 0) | (priority << 10) | (cParam << 12));
}
























/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036CA8.c  *       --func func_02036CA8 --addr 0x02036CA8 --cc 1.1p1 --arm
 *
 * wm_icon.c: write the wireless icon's two 16x16 OAM entries into main
 * (0x07000000) or sub (0x07000400) OAM, and hide the pair at the previous
 * location when the engine changed.  Every store is the NitroSDK
 * G2_SetOBJAttr inline (attr01 = y | mode<<10 | mosaic<<12 | effect |
 * color<<13 | shape | x<<16 | rs<<25, attr2 = name | prio<<10 | cparam<<12):
 * entry 0 is an OBJ-window sprite (mode 2) or a NODISPLAY blank (effect
 * 0x200), entry 1 the normal sprite, palette 14.  Written through the
 * inline, the shift scheduling of docs/notes/pkt_02036CA8.c.txt (31 bytes,
 * hand-expanded) disappears.
 */
void func_02036CA8(struct Icon *c)
{
    u32 mode;
    u32 name;
    GXOamAttr *oam;

    mode = func_02036D64((u8 *)c);
    name = func_02036DC8(mode, c->f00);
    if (mode == 1) {
        oam = (GXOamAttr *)0x07000000;
    } else {
        oam = (GXOamAttr *)0x07000400;
    }
    if (c->f0f == 1) {
        G2_SetOBJAttr(&oam[0], c->f04, c->f06, 0, 2, 0, 0, 0x40000000, 0, name, 14, 0);
    } else {
        G2_SetOBJAttr(&oam[0], 0, 0, 0, 0, 0, 0x200, 0x40000000, 0, 0, 0, 0);
    }
    G2_SetOBJAttr(&oam[1], c->f04, c->f06, 0, 0, 0, 0, 0x40000000, 0, name, 14, 0);
    if (oam != c->f10) {
        G2_SetOBJAttr(&c->f10[0], 0, 0, 0, 0, 0, 0x200, 0x40000000, 0, 0, 0, 0);
        G2_SetOBJAttr(&c->f10[1], 0, 0, 0, 0, 0, 0x200, 0x40000000, 0, 0, 0, 0);
        c->f10 = oam;
    }
}
























u32 func_02036D64(u8 *p)
{
    switch (p[0xd]) {
    case 1:
        return ((*(u16 *)0x04000304 & 0x8000) >> 15) == 1 ? 1 : 2;
    case 2:
        return ((*(u16 *)0x04000304 & 0x8000) >> 15) == 1 ? 2 : 1;
    }
    return 1;
}
























/*
 * Maps the display control word of the requested engine onto the icon
 * render scale: the OBJ bank bits (20-21) and the OBJ-character mapping
 * bit (4) together pick 4x, 2x or 1x, and anything else is a fatal
 * configuration error.  The mask 0x00300010 is shared by both arms, so
 * the compiler hoists it out of the if and the DISPCNT read happens
 * inside; the switch then binary-searches the three sparse case values
 * with 0x00100010 as the middle.
 *
 * Wave 14: the balanced tree needs a FOURTH case label.  The switch is
 * over the SDK's GXOBJVRamModeChar values (1D_32K 0x10, 1D_64K 0x00100010,
 * 1D_128K 0x00200010, 1D_256K 0x00300010); 256K shares the default's
 * fatal arm, and with four labels mwcc switches from a linear chain to the
 * binary search the image has (docs/notes/pkt_02036DC8.c.txt measured
 * three labels only).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036DC8.c  *       --func func_02036DC8 --addr 0x02036DC8 --cc 1.1p1 --arm
 */
u32 func_02036DC8(u32 engine, u32 b)
{
    int m;

    if (engine == 1) {
        GX_GetBankForOBJ();
        m = *(vu32 *)0x04000000 & 0x00300010;
    } else {
        GX_GetBankForSubOBJ();
        m = *(vu32 *)0x04001000 & 0x00300010;
    }

    switch (m) {
    case 0x10:
        return b * 4;
    case 0x00100010:
        return b * 2;
    case 0x00200010:
        return b;
    case 0x00300010:
    default:
        func_02034714(str_020A79F0, 0xfb, str_020A79FC);
        return b;
    }
}























struct Handler *func_02036E74(struct Handler *p, int v)
{
    if (v < 4)
        p->unk00 = v;
    return p;
}
























/*
 * Program two four-field control blocks: the base one at 0x07000000 always,
 * the second at 0x07000400 only when the byte at +0xe of the record is set.
 * Each block writes the constant 0x40000200, a zero halfword, the same
 * constant, then another zero halfword, which the compiler emits as a
 * word/halfword/word/halfword run off one base register.  The record is then
 * released through the overruled SDK address 0x020307B0 (matched), attesting
 * the PC24 site.  This function was the last blocker for
 * src/matched/func_020370C8.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036E80.c \
 *       --func func_02036E80 --addr 0x02036E80 --arm --cc 1.1p1
 */
void func_02036E80(unsigned char *p)
{
    *(volatile u32 *)0x07000000 = 0x40000200;
    *(volatile u16 *)0x07000004 = 0;
    *(volatile u32 *)0x07000008 = 0x40000200;
    *(volatile u16 *)0x0700000c = 0;
    if (p[0xe] != 0) {
        volatile u32 *q = (volatile u32 *)(0x07000000 + 0x400);
        q[0] = 0x40000200;
        *(volatile u16 *)&((struct Obj06937 *)q)->f4 = 0;
        q[2] = 0x40000200;
        *(volatile u16 *)&((struct Obj06937 *)q)->fC = 0;
    }
    func_020307B0(p);
}
























/*
 * Stamp the two status bytes at +0x0d / +0x0e of the handler block, then
 * feed the result of func_02036D64 straight into func_02036F24.  The `mov
 * r1, #1` is shared between the store to +0x0e and the second argument of
 * the first call, which is why the constant is not rematerialised.  The
 * byte at +0x0c is loaded after the first call, so it is an argument
 * expression of the second call, not a value cached before it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036EC8.c \
 *       --func func_02036EC8 --addr 0x02036EC8 --cc 1.1p1 --arm
 */
void func_02036EC8(struct Handler *p, u32 a, u32 b)
{
    p->kind = (a != 0) ? 1 : 2;
    p->busy = 1;

    func_02036F24(func_02036D64((u8 *)p), p->unk0c, b);
}























int func_02036F04(int a0){ int t0, t1; if ((unsigned int)(a0) == (unsigned int)(1)) { t0 = func_02080C24(); } else { t1 = func_02080C64(); }  return 0; }
























void func_02036F24(int a0, int b, int c)
{
    u32 t[3];
    int q;
    int p;
    void *v;
    int idx;
    int t2;

    v = func_020490F4(func_0200F168(), (u16)((c & 0x7fff) | 0x8000));
    func_0200F16C((struct Sub0200F16CHdr *)t);
    if (a0 == 1) {
        p = 1;
        q = 0;
    } else {
        p = 5;
        q = 1;
    }
    func_02049B68(v, t[2], (void *)p, 0x1c0, 0x20, c);
    idx = (b == 0) ? 1 : 0;
    t2 = func_02036F04(a0);
    func_02049800(v, t[idx], q, t2, 0, 0, c);
    func_02049238(v);
}























int func_02036FD8(void){ int t0 = func_0207E684((int)0x20A0810, (int)0, (int)0x20); int t1 = func_0207E708((int)0x20A0810, (int)0, (int)0x20); return t1; }
























/*
 * Rebuild the handler block held at +0x04 of the global at 0x021469C8 with
 * a nine-argument call to func_02036BD4 (four in registers, five on the
 * stack, which is what the 0x14-byte frame is for).  The two arms differ
 * only in the last four arguments: when a block already exists its three
 * carried fields are read out first and the old block is released by
 * func_020370C8, otherwise the mode bitfield at +0x02 is passed instead and
 * the last two arguments are the constants 0 and 3.
 *
 * The re-read of +0x04 for the sixth argument lands after the call to
 * func_020370C8, so it is a fresh load of the global, not the `h` that was
 * tested.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037010.c \
 *       --func func_02037010 --addr 0x02037010 --cc 1.1p1 --arm
 */
void func_02037010(u32 a, u32 b, u32 c, u32 d)
{
    struct Handler *h;

    func_02036FD8();

    h = g_021469C8.handler;

    if (h != 0) {
        u8  kind;
        u32 unk00;
        u8  busy;

        busy  = h->busy;
        kind  = h->kind;
        unk00 = h->unk00;

        func_020370C8();

        g_021469C8.handler = func_02036BD4(0, d, a, b, c,
                                           g_021469C8.handler,
                                           kind, busy, unk00);
    } else {
        g_021469C8.handler = func_02036BD4(0, d, a, b, c,
                                           h, g_021469C8.mode, 0, 3);
    }
}
























/*
 * Two-stage shutdown guarded on a global word: always run func_02036FD8,
 * then, only when g_021469C8.handler is set, run func_02036E80 and clear the flag.
 * func_02036E80 was the sole blocker for this file; it was matched in the
 * same wave, so its PC24 site now attests on the `matched` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020370C8.c \
 *       --func func_020370C8 --addr 0x020370C8 --arm --cc 1.1p1
 */
void func_020370C8(void)
{
    func_02036FD8();
    if (g_021469C8.handler == 0)
        return;
    func_02036E80((unsigned char *)g_021469C8.handler);
    g_021469C8.handler = 0;
}
























/*
 * Forwards the argument to the handler held in the second word of the global
 * at 0x021469C8, but only when that handler is armed; an unarmed handler is
 * the `popeq` that returns 0 without touching r0.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020370F4.c \
 *       --func func_020370F4 --addr 0x020370F4 --cc 1.1p1 --arm
 */
u32 func_020370F4(u32 a)
{
    struct Handler *h;

    h = g_021469C8.handler;
    if (h == 0)
        return (u32)h;
    return (u32)func_02036E74(h, a);
}























/*
 * Notifier fan-out.  The first call is told which of two kinds of event
 * this is by testing the first argument (`movs r5, r0` sets the flags and
 * saves the argument in one instruction, which is why the ternary costs
 * nothing), and the second call only happens when the handler slot at
 * +0x04 of the global at 0x021469C8 is populated; both of this function's
 * own arguments are forwarded to it, which is what spends r5 and r4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037118.c \
 *       --func func_02037118 --addr 0x02037118 --cc 1.1p1 --arm
 */
void func_02037118(u32 a, u32 b)
{
    func_020371D8(a != 0 ? 1 : 2);

    if (g_021469C8.handler != 0)
        func_02036EC8(g_021469C8.handler, a, b);
}
























/*
 * PARKED AT MATCH.  Every concrete byte is right; the one open site is the
 * `bl` to 0x02036CA8, which has no outside witness.  0x02036CA8 carries no
 * `func_` label in the listing, so the `label` class cannot reach it, and the
 * only branch to it anywhere in the image is the one inside this function, so
 * there is no second caller to attest it either.  It closes the day
 * 0x02036CA8 is matched itself (its manifest entry would then be the witness)
 * or a second caller turns up.
 *
 * Flush hook: does nothing while the handler in the second word of the global
 * at 0x021469C8 is unarmed, otherwise hands it to func_02036CA8.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02037154.c \
 *       --func func_02037154 --addr 0x02037154 --cc 1.1p1 --arm
 */
void func_02037154(void)
{
    if (g_021469C8.handler == 0)
        return;
    func_02036CA8((struct Icon *)g_021469C8.handler);
}
























/*
 * Sets the flag byte at +0x0F of the armed handler, and does nothing at all
 * when the handler is not armed - the `movne`/`strbne` pair is the whole body.
 * src/matched/func_02037190.c is the same function clearing the same byte.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037174.c \
 *       --func func_02037174 --addr 0x02037174 --cc 1.1p1 --arm
 */
void func_02037174(void)
{
    u8 *q;

    q = (u8 *)g_021469C8.handler;
    if (q != 0)
        q[0x0F] = 1;
}
























/*
 * Clears the flag byte at +0x0F of the armed handler; the only difference from
 * src/matched/func_02037174.c is the `movne r0, #0` instead of `#1`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037190.c \
 *       --func func_02037190 --addr 0x02037190 --cc 1.1p1 --arm
 */
void func_02037190(void)
{
    u8 *q;

    q = (u8 *)g_021469C8.handler;
    if (q != 0)
        q[0x0F] = 0;
}






















void func_020371AC(unsigned short a, unsigned short b)
{
    g_021469C8.unk00 = a;
    g_021469C8.unk02 = b;
}
























/*
 * Setter for the two-bit mode field in the top of the halfword at +0x02 of
 * the global at 0x021469C8.  The `lsl #0x1e` plus the `lsr #16` shifter
 * operand on the `orr` is the bitfield insert, and the `bic` of 0xc000 is
 * the field's own mask.  The `lsl #0x10 / lsr #0x10` pair above it is an
 * explicit `(u16)` cast on the stored value: declaring the parameter `u16`
 * instead drops the pair entirely (the insert already masks), so the cast
 * has to be written out.  See
 * docs/idioms/an-explicit-narrowing-cast-into-a-bitfield-is-not-folded.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020371D8.c \
 *       --func func_020371D8 --addr 0x020371D8 --cc 1.1p1 --arm
 */
void func_020371D8(u32 mode)
{
    g_021469C8.mode = (u16)mode;
}

























u32 func_02037200(void)
{
    if (g_021469C8.handler == 0) {
        return 1;
    }
    return func_02036D64((u8 *)g_021469C8.handler);
}

























void func_02037224(u8 v, int b)
{
    d_020A7A20[0] = v;
}

























/*
 * Resets a sixteen-byte record: both halfwords at +8 and +0x0A become 0xFFFF
 * (the "no value" sentinel) and the words at +0 and +4 and the halfword at
 * +0x0C are cleared.  The sentinel cannot be encoded as an ARM immediate, so it
 * comes out of the function's own literal pool; the stores then run in the
 * order the source writes them.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037234.c \
 *       --func func_02037234 --addr 0x02037234 --cc 1.1p1 --arm
 */
void func_02037234(u8 *p)
{
    ((struct Obj05733 *)p)->fC = 0;
    ((struct Obj05733 *)p)->f8 = 0xFFFF;
    ((struct Obj05733 *)p)->fA = 0xFFFF;
    ((struct Obj05733 *)p)->f4 = 0;
    ((struct Obj05733 *)p)->f0 = 0;
}

























/*
 * The current capacity, or the measured one: when the state object's byte at
 * +0x64 is set and its halfword at +0x6C is non-zero, that halfword is the
 * answer; otherwise the two measurement calls are multiplied.
 *
 * The conjunction is the reason both loads after the first comparison are
 * conditional (`ldrhne`, `cmpne`) and the early return is a bare `popne`:
 * written as one `&&` in a single `if`, mwcc keeps the whole guard inside the
 * flags.  The product is a plain `mul`, so the function returns a 32-bit
 * value, not a narrowed one.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037258.c \
 *       --func func_02037258 --addr 0x02037258 --cc 1.1p1 --arm
 */
u32 func_02037258(void)
{
    struct NetCtx *p;

    p = func_0203D788();
    if (p->f64 != 0 && p->f6C != 0)
        return p->f6C;
    return func_0203D6BC() * func_0203D680();
}

























/*
 * Closes the 4-byte residue docs/notes/pkt_02037288_wave25.c.txt records
 * (the `mov r3, r4` / `lsl r1, r1, #1` pair at +0x00B0).  The lever is the
 * ALLOCATION RESULT TYPE, not the size spelling: the seven pointer fields
 * are declared `void *` so each func_02030734 result is stored without an
 * integer conversion.  With them declared `u32` the file does not even
 * compile; with a cast at each site the argument scheduling shifts and the
 * 0xE8 call's size is finished before r3 is written.  The size arguments
 * themselves must stay as in-place expressions re-reading ->f1E0, never
 * bound to a local.
 *
 * The note's other two findings are confirmed and kept: the prototype
 * returns int (the tail `mov r0,#1` is a `return 1`), and the +0x1E0 store
 * is two separate `+ 0x40` adds in the two arms, not one factored add.
 */
int func_02037288(u32 a0, u32 heap, u32 c)
{
    u32 n;
    u32 m;

    if (g_021469D0 == 0) {
        n = func_0203D680();
        m = func_02037258();
        g_021469D0 = func_02030734(heap, 0x1f0, 1, str_020A7A24, 0xdd);
        if (c != 0)
            g_021469D0->f1E0 = m + 0x40;
        else
            g_021469D0->f1E0 = a0 + 0x40;

        g_021469D0->f14 = func_02030734(heap, g_021469D0->f1E0 * 3, 1,
                                          str_020A7A24, 0xe6);
        g_021469D0->f18 = func_02030734(heap, g_021469D0->f1E0 * 2, 1,
                                          str_020A7A24, 0xe8);
        g_021469D0->f10 = func_02030734(heap, n * g_021469D0->f1E0, 1,
                                          str_020A7A24, 0xe9);
        g_021469D0->f00 = func_02030734(heap, func_0203D6BC(), 1,
                                          str_020A7A24, 0xec);
        g_021469D0->f04 = func_02030734(heap, func_0203D6BC() * 15, 1,
                                          str_020A7A24, 0xed);
        g_021469D0->f08 = func_02030734(heap, m, 1, str_020A7A24, 0xee);
        g_021469D0->f0C = func_02030734(heap, m * 2, 1, str_020A7A24, 0xef);
        func_02036AF4(&g_021469D0->fCC, 0x64,
                      &g_021469D0->f1C, heap);
        func_02036AF4(&g_021469D0->fF4, 0xb4,
                      &g_021469D0->f3C, heap);
        g_021469D0->f1AC = 1;
        func_02037478();
    }
    g_021469D0->f1E4 = 0;
    g_021469D0->f1E7 = 0;
    return 1;
}

























/*
 * Second half of net_system init: wipe and re-seed every buffer
 * func_02037288 allocated (docs/families/net_system.h).  Closed from the
 * 520-byte / 135-out source of docs/notes/pkt_02037288_wave25.c.txt with two
 * changes:
 *   1. func_0203640C is a THREE-argument call at every site.  The first
 *      loop's "leftover" r2 is the slot stride f1E0 passed as the header's
 *      length (same finding as func_02037680); with it the file is 12 out.
 *   2. the loop index is declared FIRST, before the three counts.  With
 *      the counts first, n1 and i swap r7/r8 (the last 12 bytes).
 * The three product pairs stay spelled differently per site (n2 + n2 vs
 * n2 << 1, etc.) so the compiler rematerialises instead of CSEing them.
 */
void func_02037478(void)
{
    s32 i;
    s32 n1;
    s32 n2;
    s32 n3;

    n1 = func_0203D680();
    n2 = func_02037258();
    n3 = func_0203D6BC();

    func_02082BCC(g_021469D0->f10, 0, g_021469D0->f1E0 * n1);
    for (i = 0; i < n1; i++) {
        func_0203640C((struct Rec *)&g_021469D0->f4C[i],
              (u32)(g_021469D0->f10 + i * g_021469D0->f1E0), g_021469D0->f1E0);
        g_021469D0->f1D7[i] = 0;
    }

    func_02082BCC(g_021469D0->f0C, 0, n2 + n2);
    func_0203640C((struct Rec *)&g_021469D0->f3C, (u32)g_021469D0->f0C, (u32)n2 << 1);
    for (i = 0; i < n2; i++)
        g_021469D0->f08[i] = 0;

    func_02082BCC(g_021469D0->f04, 0, n3 * 16 - n3);
    func_0203640C((struct Rec *)&g_021469D0->f1C, (u32)g_021469D0->f04, ((u32)n3 << 4) - n3);
    *g_021469D0->f00 = 0xff;
    for (i = 1; i < n3; i++)
        g_021469D0->f00[i] = 0;

    func_02082BCC(g_021469D0->f14, 0, g_021469D0->f1E0 + g_021469D0->f1E0 * 2);
    func_0203640C((struct Rec *)&g_021469D0->f2C, (u32)g_021469D0->f14,
                  g_021469D0->f1E0 * 3);
    for (i = 0; i < 8; i++) {
        func_02037234(g_021469D0->f11C[i]);
        g_021469D0->f1B4[i] = 0;
    }
    g_021469D0->f1B0 = 0;
    func_02037234(g_021469D0->f19C);
    func_02037224(4, 0x13a);
    str_020A7A20[1] = 4;
    func_02036B4C(&g_021469D0->fCC);
    func_02036B4C(&g_021469D0->fF4);
    g_021469D0->f1E8 = 0;
    g_021469D0->f1EB = 1;
    g_021469D0->f1EA = 0;
    g_021469D0->f1ED = 0;
}























/*
 * Reset one net_system slot (docs/families/net_system.h).  The 8-byte
 * "colouring" residue of docs/notes/pkt_02037288_wave25.c.txt was a wrong
 * reading of the callee's argument list: func_0203640C here takes THREE
 * arguments, (header, buffer, length), and r2 at the call is the slot
 * stride f1E0 passed on purpose as the buffer length, not a leftover of
 * the mla.  The slot header is initialised to { f10 + i * f1E0, f1E0 }.
 */
void func_02037680(int i)
{
    if (i >= 8) {
        func_02034714((const char *)str_020A7A24, 0x155, (const char *)str_020A7A34);
    }
    g_021469D0->f1B4[i] = 0;
    func_0203640C((struct Rec *)&g_021469D0->f4C[i], (u32)(g_021469D0->f10 + i * g_021469D0->f1E0), g_021469D0->f1E0);
    g_021469D0->f1D7[i] = 0;
    func_02037234(g_021469D0->f11C[i]);
}























/*
 * Filed on lane 1 as the single-caller callee of src/pending/func_0203C864.c.
 * The 0x340 field is a table of function pointers reached through two
 * indirect calls; the third reaches a slot at +0x68 past two unread words at
 * +0x44 and +0x48, which is why the struct keeps them as padding.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037700.c \
 *       --func func_02037700 --addr 0x02037700 --cc 1.1p1 --arm
 */
int func_02037700(u32 a0, u32 a1)
{
    struct NetCtx *o = func_0203D798();
    struct NetCtx *c = func_0203D788();
    u32 flag = 0;

    if (c->f64 != 0 && c->f6C != 0)
        flag = 1;
    func_02037288(a0, a1, flag);
    c->vt->f04(o->f56, c, 0, c->f34C);
    c->vt->f08(0);
    c->vt->f68(g_020387A0);
    return 1;
}























/*
 * 32-byte hook dispatcher: func_0203D788 returns the current context, whose
 * word at +0x340 names a vtable whose slot +0x90 is called with the incoming
 * argument.  The call is a real `blx r1` and not a tail call because r4 has to
 * be restored afterwards, which is what makes it `return f(p)` and not a
 * `bx`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203778C.c \
 *       --func func_0203778C --addr 0x0203778C --cc 1.1p1 --arm
 */
u32 func_0203778C(u32 p)
{
    struct NetCtx *c = func_0203D788();
    u32 (*f)(u32) = c->vt->f90;

    return f(p);
}




















u32 func_020377AC(u32 a0, u8 *rec, u32 len)
{
    return func_020380E4(a0, rec, len);
}













































/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020377B8.c \
 *       --func func_020377B8 --addr 0x020377B8 --cc 1.1p1 --arm
 */
u32 func_020377B8(u8 arg0)
{
    u32 zero;
    struct NetCtx *a = func_0203D798();
    struct NetCtx *b = func_0203D788();
    u16 val;
    void (*f)(void *);

    a->f66 = arg0;
    f = b->vt->f68;
    f(func_020377AC);

    zero = 0;
    val = a->f56;
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
    struct NetCtx *a = func_0203D798();
    struct NetCtx *b = func_0203D788();
    void (*hook)(u32, u32);

    func_02037680(arg);

    hook = a->f08;
    if (hook == 0)
        return;
    hook(b->f34C, arg);
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
    struct NetCtx *a = func_0203D798();
    struct NetCtx *b = func_0203D788();
    void (*hook)(u32, u32);

    func_02037680(arg);

    hook = a->f08;
    if (hook == 0)
        return;
    hook(b->f34C, arg);
}












































/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037894.c \
 *       --func func_02037894 --addr 0x02037894 --cc 1.1p1 --arm
 */
u32 func_02037894(u8 a0, u16 a1, u32 a2, u32 a3)
{
    struct NetCtx *a = func_0203D798();
    struct NetCtx *b = func_0203D788();
    u32 flag;
    u16 val;
    void (*f1)(void *);
    void (*f2)(void *);
    u32 (*f3)(u32, u32);

    a->f66 = a0;

    f1 = b->vt->f3C;
    f1(func_0203781C);

    f2 = b->vt->f68;
    f2(func_020387A0);

    if (b->f64 != 0 && b->f6C != 0) {
        flag = 1;
    } else {
        flag = 0;
    }

    a = func_0203D798();
    val = a->f56;
    func_02037288(a1, val, flag);

    f3 = b->vt->f40;
    return f3(a2, a3);
}












































/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037928.c \
 *       --func func_02037928 --addr 0x02037928 --cc 1.1p1 --arm
 */
u32 func_02037928(u32 a0, u16 a1)
{
    struct NetCtx *b = func_0203D788();
    void (*f1)(void *);
    u32 (*f2)(u32, u32);
    void (*f3)(void *);
    u32 res;
    u32 flag;
    struct NetCtx *a;
    u16 val;

    f1 = b->vt->f3C;
    f1(func_02037858);

    f2 = b->vt->f44;
    res = f2(a0, 0);

    if (res == 1) {
        f3 = b->vt->f68;
        f3(func_02038924);

        if (b->f64 != 0 && b->f6C != 0) {
            flag = 1;
        } else {
            flag = 0;
        }

        a = func_0203D798();
        val = a->f56;
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
    struct NetCtx *c = func_0203D788();

    c->vt->f3C(func_02037858);
    r = c->vt->fBC();
    if (r == 1) {
        c->vt->f68(func_02038924);
        func_02037288(p, func_0203D798()->f56, 0);
        g_020A7A20[1] = 4;
    }
    return r;
}












































void func_02037A44(int a)
{
    struct NetCtx *r = func_0203D788();
    struct NetVtbl *t = r->vt;
    if (t == 0)
        return;
    t->fC0(a);
}













































/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037A6C.c \
 *       --func func_02037A6C --addr 0x02037A6C --cc 1.1p1 --arm
 */
u32 func_02037A6C(u32 a0, u32 a1, u16 a2, u32 a3)
{
    struct NetCtx *b = func_0203D788();
    struct NetCtx *a = func_0203D798();
    void (*f1)(void *);
    u32 flag;
    u16 val;
    u32 (*f2)(u32, u32, u32, u32, u32);

    f1 = b->vt->f68;
    f1(func_02038924);

    if (a0 != 0) {
        if (b->f64 != 0 && b->f6C != 0) {
            flag = 1;
        } else {
            flag = 0;
        }

        a = func_0203D798();
        val = a->f56;
        func_02037288(a2, val, flag);

        g_020A7A20[1] = 4;
    }

    f2 = b->vt->f48;
    return f2(a0, a1, 0, 0, a3);
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

    func_02036B88(&g_021469D0->fF4);
    func_02036B88(&g_021469D0->fCC);

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
    struct NetCtx *c = func_0203D788();
    struct NetCtx *o = func_0203D798();

    if (g_021469D0 == 0) {
        if (c != 0)
            c->vt->f0C(0);
        return 1;
    }

    {
        u32 (*h)(void) = c->vt->f84;
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
        c->vt->f0C(
            g_021469D0->f1E4);
    }
    func_0203ACAC();
    func_02037BA4();
    goto done;

bail:
    c->vt->f0C(0);
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
        if (func_02038AE0((struct Hdr *)p->f00, &p->fCC, func_0203D6BC(), p->f1D5) != 0) {
            struct Net *q = g_021469D0;
            q->f1D5++;
        }
        lbl_020A7A20[1] = 0;
        r = 1;
    } else {
        struct Net *p = g_021469D0;
        if (func_02038AE0((struct Hdr *)p->f00, &p->fCC, func_0203D6BC(), p->f1D5) != 0) {
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
    struct NetCtx *c = func_0203D788();
    u32 v = func_0203D6BC();
    u32 r;

    r = c->vt->f70();
    if (r == 0)
        return;
    r = func_02039338();
    r = func_02039160(r);
    if (r == 0)
        return;
    if (g_020A7A20[1] != 0)
        return;
    if (func_02039338() != 0) {
        r = c->vt->f64((u32)g_021469D0->f00, v, 0, func_02038A48);
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
    struct NetCtx *p;

    p = func_0203D788();

    if (p->vt->f58() == 0)
        return;

    if (g_021469D0->f1EB != 0)
        func_02037D98(1);

    if (p->vt->f5C((u32)g_021469D0->f00) != 1)
        goto fail;

    d_020A7A20[1] = 4;
    g_021469D0->f1EB = 1;

    v = func_0203D6BC();
    n = func_0203D680();
    i = 0;
    if (n > 0) {
        v = (unsigned short)v;
        do {
        func_020387A0((unsigned short)i,
                      (u8 *)(p->vt->f60(i)), v);
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
    struct NetCtx *p;
    u32 v;

    p = func_0203D788();

    if (func_020366A8(&g_021469D0->fCC) != 0)
        func_0203D3A8(func_020399A8(), 0x10, 0, 0);

    v = (u32)p->vt->f9C;
    if (v != 0)
        ((void (*)(void))v)();
    if (p->vt->f6C() != 1)
        return;

    v = func_0203D6BC();
    if (p->vt->fA0() != 1)
        return;
    if (func_02037D98(0) == 0)
        return;

    func_020381D8((u32)g_021469D0->f00, v);
    d_020A7A20[1] = 4;
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
    func_02036428(&g_021469D0->f4C[a0], rec + 7, n);
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
    struct NetCtx *p;
    u32 v;

    func_0203D798();
    p = func_0203D788();

    if (p->vt->fA4() == 0 ||
        p->vt->fAC() == 0) {
        func_02034714((const char *)d_020A7A24, 0x400, (const char *)d_020A7A50);
        return;
    }

    if (d_020A7A20[1] != 0)
        return;
    p->vt->f64(a0, a1, 0, 0);
    v = p->vt->f80();
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
    struct NetCtx *p;
    u32 v;

    func_0203D798();
    p = func_0203D788();
    v = func_0203D6BC();

    if (g_021469D0->f1E7 == 0)
        return;
    if (g_021469D0->f1ED == 0) {
        if (func_02038AE0((struct Hdr *)g_021469D0->f00, &g_021469D0->fCC,
                          func_0203D6BC(),
                          g_021469D0->f1D5) != 0)
            g_021469D0->f1ED = 1;
    }

    if (g_021469D0->f1ED != 1)
        return;
    if (p->vt->f64((u32)g_021469D0->f00, v,
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
    struct NetCtx *p;

    func_0203D798();
    p = func_0203D788();
    if (p->vt->f70() == 0)
        return;
    if (func_02039160(func_02039338()) == 0)
        return;
    func_02037D98(1);
    func_02037E60();
}






































void func_02038380(void)
{
    struct NetCtx *c = func_0203D788();

    func_0203D680();
    if (g_020A7A20[0] == 1) {
        if ((int)func_020392B8() > 1) {
            func_02037224(2, 0x46a);
            if (c->vt->f70() != 0) {
                u32 t = func_02037258();
                if (c->vt->f64(
                        (u32)g_021469D0->f08, t, 0, func_02038A90) != 0)
                    goto tail;
                func_02037224(1, 0x46a + 4);
                goto tail;
            }
            if ((func_0203D798())->f65 != 3 && (func_0203D798())->f65 != 4)
                goto tail;
            if (c->vt->fA0() == 0) {
                func_02037224(1, 0x475);
                goto tail;
            }
            if (g_021469D0->f08[2] == 0)
                return;
            {
                u32 t = func_0203D6BC();
                c->vt->f64(
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
    if (c->vt->f70() == 0)
        goto last;
    if ((func_0203D798())->f65 == 3)
        goto last;
    if ((func_0203D798())->f65 != 4)
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
    struct NetCtx *c = func_0203D788();
    struct NetCtx *o = func_0203D798();
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
            if (c->vt->f64(
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

            func_02038AE0((struct Hdr *)g->f08, &g->fF4, t, g->f1D4);
            g = g_021469D0;
            g->f1D4 = (u8)(g->f1D4 + 1);
            func_02037224(1, 0x4f4);
        }
        func_02038380();
        return;
    }
    if (c->vt->f70() == 0)
        return;
    if (func_02038524() == 0)
        return;
    if (g_020A7A20[0] == 4) {
        struct Net *g = g_021469D0;
        u32 t = func_02037258();

        func_02038AE0((struct Hdr *)g->f08, &g->fF4, t, g->f1D4);
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
    func_02036428(&g_021469D0->f4C[i], p + 7, len);
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
    func_02036428(&g_021469D0->f2C, p + 7, len);
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





































s32 func_02038AE0(struct Hdr *h, NetQueue *c, s32 len, u8 a3)
{
    struct NetCtx *g;
    struct NetCtx *sys;
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

    h->f03 = sys->vt->f7C();

    if (func_020366A8(c) == 0)
    {
        if ((u8)(g->f65 + 0xfd) > 1)
            goto body;
        if (sys->vt->fB0() != 1)
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
int func_02038C18(u32 a1, const void *a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7)
{
    struct NetCtx *rec;
    struct Net *h;
    struct Err *err;
    NetQueue *tbl;
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
        tbl = &h->fF4;
    else
        tbl = &h->fCC;

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
    func_020365E8(&g_021469D0->f1C);
}



































void func_02038D4C(int a0, int a1, int a2, int a3)
{
    func_020365E8(&g_021469D0->f3C);
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
void func_02038DF0(NetRingBuff *src, s32 a1, u8 *buf, struct St *st, u32 n)
{
    int len;
    s16 sv;
    u8 *p;
    u32 h;
    int cnt;

    func_0203D798();
    while (func_020365E8(src) != 0) {
        h = st->h;
        if (h == 0) {
            h = func_02036540(src);
            if (h == 0) {
                func_02034714((const char *)str_020A7A24, 0x6E3, (const char *)str_020A7A50);
                continue;
            }
        }
        sv = src->head;
        st->h = h;
        if (st->total == 0xFFFF) {
            if (func_020365E8(src) < 3) {
                src->head = sv;
                return;
            }
            {
                u16 v = func_02036540(src);
                st->left = v;
                st->total = v;
            }
            st->f0E = a1;
            st->f0F = func_02036500(src);
        }
        sv = src->head;
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
        src->head = sv;
        return;
    }
}


































void func_02039050(void)
{
    int i;
    struct Net *p;

    if (g_021469D0 == 0)
        return;

    func_0203666C(&g_021469D0->f2C);

    for (i = 0; i < 4; i++) {
        if ((int)func_020365E8(&g_021469D0->f2C) <= 0)
            return;

        p = g_021469D0;
        func_02038DF0((NetRingBuff *)&p->f2C, 0xFF, p->f18,
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
        func_0203666C(&g_021469D0->f4C[i]);
        for (j = 0; j < 4; j++) {
            if (func_020365E8(&g_021469D0->f4C[i]) > 0)
                func_02038DF0((NetRingBuff *)&g_021469D0->f4C[i], i,
                              g_021469D0->f18,
                              (struct St *)g_021469D0->f11C[i], (u32)s);
        }
    }
}



































int func_02039160(u32 mode)
{
    struct NetCtx *p5;
    struct NetCtx *p4;
    struct Net *g;
    u32 v;
    u16 m;

    p5 = func_0203D788();
    p4 = func_0203D798();
    g = g_021469D0;
    if (g == 0)
        return 0;
    v = (u8)(p4->f65 + 0xff);
    if (v <= 1) {
        if (g->f1E7 != 0) {
            if (p5->vt->f80() != -1) {
                if (mode == 0)
                    return 1;
                if (mode == 1)
                    return 1;
            }
        }
        return 0;
    }
    v = (u8)(p4->f65 + 0xfd);
    if (v <= 1) {
        if (mode < 2 || mode == 0xff) {
            if (p5->vt->f70() != 0)
                return 1;
        }
        return 0;
    }
    if (func_020392EC() == 0)
        return 0;
    if (p5->vt->f70() == 0)
        return 0;
    if (mode == (u32)func_02039338())
        return 1;
    if (func_02039338() == 0 || p4->f64 == 0) {
        m = (u16)p5->vt->f7C();
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
    int count;
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
    struct NetCtx *s = func_0203D788();
    struct NetCtx *p = func_0203D798();

    if (g_021469D0 != 0 && (u8)(p->f65 + 0xFF) <= 3)
        return 1;

    return s->vt->f6C();
}
































u16 sub_02039338(void)
{
    struct NetCtx *owner;
    u8 sel;
    s32 v;

    if (g_021469D0 == 0) {
        goto none;
    }

    owner = func_0203D788();
    sel = (func_0203D798())->f65 + 0xff;

    if (sel <= 1) {
        v = owner->vt->f80();
        if (v == -1) {
            goto none;
        }
        return (u16)v;
    }

    return (u16)owner->vt->f80();

none:
    return 0;
}































int sub_020393A8(void)
{
    u16 mask;

    mask = func_0203D788()->vt->f7C();
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
    struct NetCtx *root;

    root = func_0203D788();

    if (g_021469D0 != 0 && g_021469D0->f1E9 != 0) {
        return 1;
    }
    return root->vt->f88() != 0;
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
    struct NetCtx *p = func_0203D788();
    u32 r = 0;

    if (p != 0 && p->vt != 0)
        r = p->vt->f88();
    if (r == 0) {
        struct Net *q = g_021469D0;

        if (q != 0 && q->f1E9 != 0)
            r = 1;
    }
    return r;
}
































int func_02039468(u32 a, u32 b)
{
    struct NetCtx *s = func_0203D798();

    if (s->f64 != 0 && b == 0xff) {
        return func_02036B98(&g_021469D0->fF4, a);
    } else {
        return func_02036B98(&g_021469D0->fCC, a);
    }
}
































/*
 * Leaf that saves no lr: tail-calls func_020366A8 on the 0xCC queue of the
 * net_system record (docs/families/net_system.h, fCC).  Reached only through
 * the long-branch veneer at 0x0203D56C.
 */
int func_020394C0(void)
{
    return func_020366A8(&g_021469D0->fCC);
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
    struct NetCtx *s;

    if (g_021469D0 == 0) {
        goto yes;
    }

    s = func_0203D798();
    if (s->f64 != 0) {
        goto yes;
    }
    if (s->f65 == 0 || s->f65 == 5) {
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
    struct NetCtx *g;
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
            e->slot[i] = func_02030734(g->f56, 0x10, 1, file_020A7A68, 0xc7);
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
void func_02039834(struct NetCtx *unused)
{
    int i;
    struct NetCtx *p;

    p = func_0203D798();
    for (i = 0; i < 8; i++) {
        func_02039764(i);
    }
    func_02039764(0xff);

    if (g_021469D4 != 0) {
        func_02034714(file_020A7A68, 0xe3, msg_020A7A7C);
    }
    g_021469D4 = func_02030734(p->f56, 0x20, 1, file_020A7A68, 0xe5);
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
void func_020398B4(struct NetCtx *unused)
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
    struct NetCtx *owner = func_0203D788();

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
            if (func_0203D3A8((struct Entry *)p, 5, 2, (p + 0x2c + i * 2)) != 0) {
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
    struct NetCtx *q;
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
            buf[7] = q->f67;
            buf[8] = q->f6E;
            return func_0203D3A8((struct Entry *)p, 3, 9, buf);
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
        if (func_0203D3F8(p, 0xff, 4, 0x10, p->slot[i], 1, 0, 1) != 0)
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
    struct NetCtx *g;
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
        if (func_0203D3A8((struct Entry *)p, (u16)7, (u16)4, (p + 0x46)) != 0)
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
    if (g->f65 == 4)
        return;

    e = (u8 *)func_020399A8();
    if (e[0x4e] != 1)
        return;

    if (g->f10 != 0 && g->f14 != 0) {
        u32 a;
        u32 b;
        a = (g->f14)(func_0203D650());
        b = (g->f10)(func_0203D650());
        if (func_0203D3A8((struct Entry *)e, (u16)0xa, (u16)a, ((void *)b)) != 0)
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
  struct NetCtx *r4 = func_0203D798();
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
  if ((a2[6] != 0) && (a2[7] != *(volatile u8 *)&r4->f67))
  {
    if (r4->f6E == a2[8])
    {
      p[0xf] = r4->f6E;
      p[0xe] = r4->f6E;
      return;
    }
  }
  if (((a2[6] == 0) && (a2[7] == *(volatile u8 *)&r4->f67)) && (r4->f6E == a2[8]))
  {
    p[0xf] = r4->f6E;
    p[0xe] = r4->f6E;
  }
  else
  {
    p[0xf] = 0xff;
    p[0xe] = 0;
  }
  return;
  zero:
  {
    u8 hi = *(volatile u8 *)&r4->f67;
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
    if (((struct Obj15952 *)(func_0203D788()))->f352 == 0) {
        if (p[0x4A] != 5)
            p[0x4A] = 7;
    } else {
        p[0x4A] = 7;
    }
}
































void func_0203A150(int a0, int a1, struct Msg *msg, int a3, struct Peer *peer)
{
    struct NetCtx *g;
    u8 mac[8];
    u32 id;

    g = func_0203D798();
    id = func_020395EC((struct Entry *)peer);
    if (id == 0xff)
    {
        peer->f4a = 5;
        return;
    }

    if (g->f6E != 0)
    {
        if (g->f6E != msg->f0f)
            func_0203A118((u8 *)peer);
        if (g->f6E != msg->f0e)
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

    if (g->f0C != 0)
        g->f0C(a3, msg->f0c);

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
    struct NetCtx *g;
    struct Slot *s;

    g = func_0203D798();
    if (func_020395EC(obj) == 0xff)
        return;
    if (id >= 9)
        func_02034714(file_020A7A68, 0x3D1, file_020A7ACC);
    s = (struct Slot *)(struct Entry *)func_0203996C(id);
    if (s->buf != 0)
        func_020307B0(s->buf);
    s->buf = func_02030734(g->f56, len, 1, file_020A7A68, 0x3D8);
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
    struct NetCtx *cfg;
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
    mtu = cfg->f61 - 0xc;
    if (mtu <= 0)
        func_02034714(g_020A7AF8, 0x22b, g_020A7B78);
    s->fE = cfg->f61 - 0xc;
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
            st->lo = func_02038C18(0xd, (const u8 *)hdr, 0xc, 1,
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
            if (func_02038C18(0xc, (const u8 *)base, n, 1,
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
void func_0203AD74(struct NetState *s, void *p, u32 v)
{
    s->f08 = p;
    s->f46 = v;
}





























void func_0203AD80(struct NetState *s, void *p, u32 v, int line)
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
    g_021469DC = func_02030734(a0, 0x64, 1, g_020A7BA8, 0xb9);
    g_021469DC->f46 = 0x32;
    g_021469DC->f4C = 1;
    func_0203AE20(&g_021469DC->rng);
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
void func_0203AEEC(struct NetState *p)
{
    void (*f)(void);

    if (func_0203D788()->vt->f74() == 0)
        return;
    func_0203A53C();
    func_020370C8();
    func_02037B08();
    f = g_021469DC->f28;
    func_020307B0(g_021469DC);
    g_021469DC = 0;
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
 *    field `void (*f2c)(u32)` and writing `p->f2C(func_0203D650())` pins r0
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
void func_0203AF40(struct NetState *p)
{
    struct NetCtx *s = func_0203D788();
    struct NetCtx *c = func_0203D798();

    if (c->f65 != 1 && c->f65 != 2)
        s->vt->f04(c->f56, s, 0, s->f34C);
    func_02037D78();
    if (p->f2C != 0) {
        p->f2C(func_0203D650());
        p->f2C = 0;
    }
    func_0203AD80(g_021469DC, (void *)unk_0203C00C, 0, 0x12f);
}

























void func_0203AFCC(void *a, u32 b)
{
    func_02034F84(4);
    func_0203AD8C((u32)a);
    g_021469DC->f2C = (void (*)(u32))b;
    func_0203AD80(g_021469DC, (void *)func_0203AF40, 0, 0x13F);
}






























/*
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203B018.c \
 *       --addr 0x0203B018 --arm
 *
 * net_state.c.  func_0203B018 is the 4-byte `bx lr` no-op that
 * func_0203B038 hands to func_02037A6C as its completion callback (the
 * pool word at 0x0203B080 is its only referrer).  func_0203B01C is the
 * unlabelled leaf that bumps the state record's +0x46 countdown by 0x3C;
 * func_0203B390 names it through a pool word.  Filing both here gives the
 * `matched` class a witness for each (docs/families/net_state.h, THE REPORT
 * TAG RULE, "the two genuine exceptions").
 *
 * Integrator: seed 0x0203B01C arm (member of this unit, no label).
 */
void func_0203B018(void)
{
}






























void func_0203B01C(void)
{
    g_021469DC->f46 += 0x3c;
}






























/*
 *           resolved.  Adding the symbols: block (it had none) let
 *           0x0203B01C resolve as `literal x8, e.g. 0203B43C`; previously it
 *           reported "no address for 'unk_0203B01C'".  The ONE remaining
 *           site is 0x0203B018.
 * PARKED AT MATCH.  Every concrete byte is right (76 of 76) and the file is
 * the right size; the one open site is the ABS32 to 0x0203B018, the bare
 * `bx lr` filler word that sits between func_0203AFCC's literal pool and the
 * unlabelled leaf at 0x0203B01C.  That address has no label (a prologue that
 * saves no `lr` is never auto-labelled) and the word appears in exactly one
 * literal pool image-wide - this function's own - so neither `label` nor
 * `literal` can attest it.
 *           referenced by exactly ONE word image-wide, the pool word at
 *           0x0203B080 (grep of asm/ finds it in main.s and the four unit
 *           listings, all the same address), and 0x0203B080 lies inside this
 *           function's own compared range 0203B038..0203B084.  `label`
 *           refuses (a `bx lr` saves no lr so disasm.py never labels it),
 *           `literal` refuses (no second occurrence outside the range) and
 *           `sole-ref/code` refuses (not a traced function start).  Blocking
 *           class: none available, own-pool-only code.  It would unstick if a
 *           future EXACT entry covered 0x0203B018 itself, but that address is
 *           outside pkt_0203B038's range (0x0203B038..0x0203B084).
 *
 * Both 0x0203B018 and 0x0203B01C must be declared in the symbols: block:
 * written as plain integer literals the pair folds into one pool word plus a
 * `sub r1, r4, #4`, which is four bytes short of the original's two words.
 * 0x0203B01C resolves as `literal x10`; only the no-op word does not.
 *
 * The call's completion callback is the leaf at 0x0203B01C (bumps the +0x46
 * halfword by 0x3C); the report's identifier is the no-op at 0x0203B018.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0203B038.c \
 *       --func func_0203B038 --addr 0x0203B038 --cc 1.1p1 --arm
 */
void func_0203B038(struct NetState *a0)
{
    if (func_02037A6C(0, (u32)a0->mac, 0x200, (u32)unk_0203B01C) != 0)
        func_0203AD80(g_021469DC, (void *)unk_0203B018, 0xA, 0x169);
}





























/*
 * Starts a 0x200-byte transfer over channel 1 and reports at line 0x17C
 * (380) when it answers zero.  The report site names func_0203B038, the
 * sibling entry that put the read in flight.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B084.c \
 *       --func func_0203B084 --addr 0x0203B084 --cc 1.1p1 --arm
 */
void func_0203B084(void)
{
    func_0203D798();
    if (func_02037928(1, 0x200) != 0)
        func_0203AD80(g_021469DC, (void *)0x203B038, 0, (int)0x17C);
}





























void func_0203B0C4(int a0, int a1)
{
    if ((int)g_021469DC->mac & 1) {
        func_02034714(s_020A7BA8, 395, s_020A7BC8);
    }
    if (a0 != 0) {
        func_02082D44((void *)a0, g_021469DC->mac, 6);
    }
    if (a1 != 0) {
        func_0203AD80(g_021469DC, (void *)func_0203B084, 0, 400);
    } else {
        func_0203AD80(g_021469DC, (void *)func_0203B038, 0, 403);
    }
}





























void func_0203B16C(void)
{
}






























/*
 * The same 0x200-byte channel-1 start as func_0203B084 with no context
 * refresh, reporting at line 0x1AE (430).  0x1AE is not ARM-encodable, so the
 * constant is materialised off the 0x200 argument register as
 * `sub r3, r4, #0x52`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B170.c \
 *       --func func_0203B170 --addr 0x0203B170 --cc 1.1p1 --arm
 */
void func_0203B170(void)
{
    if (func_02037928(1, 0x200) != 0)
        func_0203AD80(g_021469DC, (void *)0x203B16C, 0, 0x1AE);
}






























/*
 * Tail-call wrapper over func_0203AD80 (the object at 0x021469DC, the
 * callback func_0203B170, 0, 0x1BC).  An unlabelled ARM leaf, filed as the
 * witness chain for func_0203D010 (state 10 of func_0203DC70).
 */
void func_0203B1B0(void)
{
    func_0203AD80(g_021469DC, func_0203B170, 0, 0x1BC);
}




























u32 func_0203B1D8(void)
{
    struct NetState *s = g_021469DC;

    if (s == 0)
        return 1;
    if (s->f08 != 0)
        s->f08(s);
    if (g_021469DC == 0)
        return 1;
    func_0203C934();
    return 0;
}




























void func_0203B224(void)
{
}




























void func_0203B228(void)
{
}



























int func_0203B22C(void)
{
    func_0203AD80(g_021469DC, func_0203B224, 0, 0x1f4);
    return 1;
}



























/*
 * Starts a 0x200-entry transfer over channel 1 and reports through
 * func_0203AD80 at line 517 when the start call answers zero.  The line comes
 * out as `add r3, r4, #5` because r4 already holds the 0x200 argument, the
 * same constant-rematerialisation the consecutive-`__LINE__` idiom records.
 *
 * Both callback addresses (0x0203B22C and 0x0203B228, the two `bx lr` filler
 * words in the pool of func_0203B1D8) are declared as symbols: written as
 * plain integer literals this compiler folds the pair into one pool word plus
 * a `sub r1, r4, #4`, which is four bytes short of the original's two pool
 * words.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B258.c \
 *       --func func_0203B258 --addr 0x0203B258 --cc 1.1p1 --arm
 */
void func_0203B258(void)
{
    func_0203D798();
    if (func_02037894(1, 0x200, 1, (u32)unk_0203B22C) != 0)
        func_0203AD80(g_021469DC, (void *)unk_0203B228, 0, 0x205);
}


























void func_0203B2A8(int a0)
{
    func_0203AD80(g_021469DC, (void *)0x203B228, 0, 0x214);
}



























void func_0203B2D0(u32 val)
{
    func_0203AD80(g_021469DC, func_0203B258, 0, 0x222);
}



























u32 func_0203B2FC(struct NetState *p)
{
    u32 hi;
    u64 acc = p->rng.mul * p->rng.x + p->rng.add;
    p->rng.x = acc;
    hi = (u32)(acc >> 32);
    return (u32)(((u64)hi * 40) >> 32) + 0x3c;
}



























u32 func_0203B344(struct NetState *p)
{
    u32 hi;
    u64 acc = p->rng.mul * p->rng.x + p->rng.add;
    p->rng.x = acc;
    hi = (u32)(acc >> 32);
    return (u32)(((u64)hi * 32) >> 32) + 0xb4;
}



























/*
 * Closes the residue docs/notes/pkt_0203B390.c.txt recorded ("DIFF, one
 * instruction": `mov r0, #1` hoisted above the `beq` in the original but
 * left inside the alt block in every spelling that note tried).  The note
 * was looking at the wrong constant.  What the original hoists is not the
 * `1`, it is the 0x200 -- `mov r4, #0x200` at +0x24, before the compare
 * chain -- and r4 then serves FOUR uses: the length argument of
 * func_02037A6C, the second argument of func_02037928 on the alt path, and
 * the base of both line numbers (`add r3, r4, #0x45` = 0x245 and
 * `add r3, r4, #0x4a` = 0x24A).  Binding it to ONE local `u32 n = 0x200;`
 * declared before the guards gives it a live range that spans both arms,
 * which is what pins it in r4 and frees r0 for the literal `1` to be
 * materialised in the pre-branch block.  The note's experiment of making
 * `one` a local was the right technique applied to the wrong value.
 *
 * EXACT on the first compile with that change; no permuter search needed.
 */
void func_0203B390(struct NetState *p)
{
    struct NetCtx *q = func_0203D788();
    u32 n = 0x200;

    if (q->vt->f78() == 0)
        return;
    if (p->f53 == 0 || p->f56 == 1)
        goto alt;

    if (func_02037A6C(1, (u32)p->addr, n, (u32)func_0203B01C) == 0)
        return;
    func_0203AD80(g_021469DC, str_0203B950, func_0203B2FC(p), n + 0x45);
    return;

alt:
    if (func_02037928(1, n) == 0)
        return;
    func_0203AD80(g_021469DC, str_0203B950, func_0203B344(p), n + 0x4a);
}




























/*
 * Reports at line 0x25D (605) when the transport's +0x78 virtual answers
 * non-zero.  The condition is the negated guard - the `pop` is on the equal
 * arm - so the C is the report inside a `!= 0` if, not a return.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B448.c \
 *       --func func_0203B448 --addr 0x0203B448 --cc 1.1p1 --arm
 */
void func_0203B448(void)
{
    if (func_0203D788()->vt->f78() != 0)
        func_0203AD80(g_021469DC, (void *)0x203B390, 0, (int)0x25D);
}




























/*
 * The same +0x10 virtual call as func_0203B4DC, reporting at line 0x265
 * (613).  Both the first call argument and the reported line derive from the
 * single 1 that the function materialises, which is what makes the line come
 * out as `add r3, r5, #0x264`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B48C.c \
 *       --func func_0203B48C --addr 0x0203B48C --cc 1.1p1 --arm
 */
void func_0203B48C(void)
{
    if (func_0203D788()->vt->f10(1, 0) != 0)
        func_0203AD80(g_021469DC, (void *)0x203B448, 0, 0x265);
}




























/*
 * Calls the transport's +0x10 virtual with (1, 0) and reports at line 0x282
 * (642) when it answers non-zero.  The zero argument and the report's third
 * argument are the same `mov r4, #0` local, which is what puts the two
 * together in one register.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B4DC.c \
 *       --func func_0203B4DC --addr 0x0203B4DC --cc 1.1p1 --arm
 */
void func_0203B4DC(void)
{
    if (func_0203D788()->vt->f10(1, 0) != 0)
        func_0203AD80(g_021469DC, (void *)0x203B390, 0, (int)0x282);
}



























/*
 * Wave 14: the "unresolvable" second tag site was a misread.  The pool word
 * at 0x0203B5CC (+0xA0) is 0x0203C00C (bytes 0c c0 03 02), not 0x0203B40C;
 * 0x0203C00C is the same tag func_0203AF40 passes and resolves `literal`.
 * The first tag, 0x0203B4DC, resolves `matched` (src/matched/func_0203B4DC.c).
 * The callback takes func_0203D650's result in r0, which is why the
 * function pointer is loaded into r1 (docs/families/net_state.h, THE
 * CALLBACK ARITY RULE).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B52C.c \
 *       --func func_0203B52C --addr 0x0203B52C --cc 1.1p1 --arm
 */
void func_0203B52C(struct NetState *p)
{
    func_0203D798();
    if (func_020393D0() != 0)
        return;
    if (func_020393A8() == 0) {
        func_0203AD80(g_021469DC, (void *)func_0203B4DC, 0, 0x297);
        return;
    }
    if (func_020399EC() == 0)
        return;
    if (func_02039ACC() == 0)
        return;
    if (p->f2C != 0) {
        p->f2C(func_0203D650());
        p->f2C = 0;
    }
    func_0203AD80(g_021469DC, (void *)func_0203C00C, 0, 0x2a6);
}
























void func_0203B5D4(struct NetState *p)
{
    struct NetCtx *q = func_0203D788();

    if (func_020393A8() != 0) {
        func_0203B2A8(func_0203D798()->f56);
        func_0203D700();
        func_0203AD80(g_021469DC, (void *)func_0203B52C, 0, 0x2c1);
        return;
    }
    if (p->f56 == 1)
        return;
    if (q->vt->f38(0) == 0)
        return;
    if (p->f46 != 0) {
        p->f46--;
        return;
    }
    func_0203AD80(g_021469DC, str_0203B48C, 0, 0x2d3);
}
























void func_0203B688(struct NetState *a0)
{
    func_0203AD80(g_021469DC, (void *)func_0203B5D4, func_0203B344(a0), 0x2e0);
}
























int func_0203B6B4(void)
{
    func_0203AD80(g_021469DC, (void *)func_0203B5D4, func_0203B344(g_021469DC), 0x2E6);
    return 1;
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B6EC.c \
 *       --func func_0203B6EC --addr 0x0203B6EC --cc 1.1p1 --arm
 */
void func_0203B6EC(struct NetState *p)
{
    if (func_0203D788()->vt->f78() == 0)
        return;
    if (func_02037894(0, 0x200, 0, (u32)func_0203B6B4) == 0)
        return;

    p->f4C = 0;
    func_0203AD80(g_021469DC, (void *)func_0203B688, 0x1E, 0x2FC);
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B758.c \
 *       --func func_0203B758 --addr 0x0203B758 --cc 1.1p1 --arm
 */
void func_0203B758(void)
{
    func_0203D798();
    if (func_02039ACC() == 0)
        return;

    func_0203AD80(g_021469DC, (void *)0x0203B794, 0, 0x30E);
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B794.c \
 *       --func func_0203B794 --addr 0x0203B794 --cc 1.1p1 --arm
 */
void func_0203B794(struct NetState *p)
{
    struct NetCtx *s = func_0203D798();

    if (func_020399B8((u8 *)((u32)func_020399A8())) == 0)
        return;

    if (p->f2C != 0) {
        p->f2C(func_0203D650());
        p->f2C = 0;
    }

    func_0203AD80(g_021469DC, (void *)0x0203C00C, 0, 0x325);
}
























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B7F8.c \
 *       --func func_0203B7F8 --addr 0x0203B7F8 --cc 1.1p1 --arm
 */
void func_0203B7F8(struct NetState *p)
{
    func_0203D798();

    func_0203996C(0xFF);
    func_020399A8();
    if (func_020399EC() < 2)
        return;

    func_02039338();

    if (p->f2C != 0) {
        p->f2C(func_0203D650());
        p->f2C = 0;
    }

    func_0203AD80(g_021469DC, (void *)0x0203C00C, 0, 0x33F);
}
























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B868.c \
 *       --func func_0203B868 --addr 0x0203B868 --cc 1.1p1 --arm
 */
void func_0203B868(struct NetState *p)
{
    func_0203D798();

    if (func_0203D788()->vt->fA8() != 1)
        return;
    if (func_02039ACC() == 0)
        return;

    if (func_0203DA4C() == 1) {
        func_0203AD80(g_021469DC, (void *)0x0203B7F8, 0, 0x354);
        return;
    }

    if (p->f2C != 0) {
        p->f2C(func_0203D650());
        p->f2C = 0;
    }

    func_0203AD80(g_021469DC, (void *)0x0203C00C, 0, 0x35B);
}
























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B90C.c \
 *       --func func_0203B90C --addr 0x0203B90C --cc 1.1p1 --arm
 */
void func_0203B90C(void)
{
    if (func_0203D788()->vt->f78() == 0)
        return;

    func_0203AD80(g_021469DC, (void *)0x0203B6EC, 0, 0x371);
}
























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B950.c \
 *       --func func_0203B950 --addr 0x0203B950 --cc 1.1p1 --arm
 */
void func_0203B950(struct NetState *p)
{
    if (func_02039338() != 0) {
        func_0203AD80(g_021469DC, (void *)0x0203B758, 0, 0x383);
        return;
    }

    if (p->f56 == 2)
        return;

    if (p->f46 != 0) {
        p->f46--;
        return;
    }

    func_0203AD80(g_021469DC, (void *)0x0203BCE0, 0, 0x390);
    func_0203BCE0(p);
}
























/*
 * A frame's 64-bit accumulator advanced by a 64-bit multiply: the pair at
 * +0x0c (little-endian u64) is multiplied by the pair at +0x14, the pair at
 * +0x1c is added in, both halves are stored back, and the new high half is
 * re-scaled by 30/2^32 into the u16 countdown at +0x46.
 *
 * Two spellings are load-bearing.  The multiply has to be written `y * x`
 * with x at +0x0c and y at +0x14: the other order loads +0x0c first and
 * swaps two `ldr`s.  And the addend has to stay inline in the multiply's own
 * statement (`r = y * x + *(u64 *)(p + 0x1c);`) with the low half stored by
 * a single 64-bit store: with a named addend and two u32 stores mwcc puts
 * the sum's low half in `ip` and the high half in `r2`, a five-instruction
 * difference in register choice alone.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B9D4.c \
 *       --func func_0203B9D4 --addr 0x0203B9D4 --cc 1.1p1 --arm
 */
void func_0203B9D4(struct NetState *p)
{
    struct NetCtx *s = func_0203D788();
    u64 x, y, r;

    if (s->vt->fAC() == 1) {
        s->vt->fB4();
        func_0203AD80(g_021469DC, (void *)0x0203B868, 0, 0x3A5);
        return;
    }

    if (p->f46 != 0) {
        p->f46 = p->f46 - 1;
        return;
    }

    x = p->rng.x;
    y = p->rng.mul;
    r = y * x + p->rng.add;

    p->f46 = (u16)((u32)(((u64)(u32)(r >> 32) * 30) >> 32) + 15);
    p->rng.x = r;

    s->vt->f08(0);
}
























void func_0203BA98(u16 a0, u32 a1, u8 a2)
{
    struct NetCtx *s = func_0203D798();
    struct NetState *p;
    u64 x, y, r;
    u32 delay = 30;

    func_0203D788();
    func_0203BC58(0, a2, 0);

    if (s->f65 == 3 || s->f65 == 4) {
        func_020377B8(0);
        g_021469DC->f2C = (void (*)(u32))a1;
        p = g_021469DC;
        x = p->rng.x;
        y = p->rng.mul;
        r = y * x + p->rng.add;
        p->rng.x = r;
        func_0203AD80(p, (void *)func_0203B9D4, (u32)(((u64)(u32)(r >> 32) * delay) >> 32), delay + 0x3A8);
    } else {
        p = g_021469DC;
        if (p->f53 != 0 && p->f56 != 1) {
            func_02037A6C(1, (u32)p->addr, 0x200, (u32)func_0203B01C);
        } else {
            func_02037928(1, 0x200);
        }
        g_021469DC->f2C = (void (*)(u32))a1;
        p = g_021469DC;
        func_0203AD80(p, (void *)func_0203B950, delay, delay + 0x3B4);
    }
}

























/*
 * Two presets that differ only in the state byte they match and the handler
 * they advertise.  Each test is a conjunction of the state byte and the
 * eight-byte pointer stored beside it, and the first arm also refuses when
 * the vtable's +0x10 hook answers zero.
 *
 * The four code addresses are declared as the functions they are: written as
 * integer literals the front end folds two nearby ones into one pool word plus
 * a `sub`, which is four bytes shorter than the original.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BBB0.c \
 *       --func func_0203BBB0 --addr 0x0203BBB0 --cc 1.1p1 --arm
 */
void func_0203BBB0(struct NetState *a)
{
    struct NetCtx *s = func_0203D788();
    struct NetState *g;

    g = g_021469DC;
    if (g->f56 == 2 && g->f08 == func_0203B950) {
        if (s->vt->f10(1, 0) != 0) {
            func_0203AD80(g_021469DC, ((void *)func_0203B90C), 0, 0x3E0);
        }
    }

    g = g_021469DC;
    if (g->f56 == 1 && g->f08 == func_0203B5D4) {
        func_0203AD80(g, ((void *)func_0203B48C), 0, 0x3E9);
    }
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BC58.c \
 *       --func func_0203BC58 --addr 0x0203BC58 --cc 1.1p1 --arm
 */
void func_0203BC58(u8 v56, u8 v53, const void *src)
{
    func_0203D788();
    g_021469DC->f53 = v53;
    g_021469DC->f56 = v56;

    if (src != 0) {
        MI_CpuCopy8(src, g_021469DC->addr, 6);
    } else {
        MI_CpuFill8(g_021469DC->addr, 0xFF, 6);
    }

    func_0203AD80(g_021469DC, ((void *)0x0203BBB0), 0, 0x406);
    func_0203BBB0(g_021469DC);
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BCE0.c \
 *       --func func_0203BCE0 --addr 0x0203BCE0 --cc 1.1p1 --arm
 */
void func_0203BCE0(struct NetState *p)
{
    struct NetCtx *s = func_0203D788();

    if (s->vt->f10(1, 0) == 0)
        return;

    func_0203AD80(g_021469DC, ((void *)0x0203B90C), 0, 0x411);
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BD30.c \
 *       --func func_0203BD30 --addr 0x0203BD30 --cc 1.1p1 --arm
 */
void func_0203BD30(u32 a0, u32 a1, u8 *a2)
{
    func_0203D788();

    g_021469DC->f53 = (u8)a1;
    g_021469DC->f56 = (u8)a0;

    if (a2 != 0)
        MI_CpuCopy8(a2, g_021469DC->addr, 6);
    else
        MI_CpuFill8(g_021469DC->addr, 0xFF, 6);

    if (g_021469DC->f56 == 2)
        func_0203AD80(g_021469DC, ((void *)0x0203B48C), 0, 0x430);

    if (g_021469DC->f56 == 1) {
        func_0203AD80(g_021469DC, ((void *)0x0203BCE0), 0, 0x438);
        func_0203BCE0(g_021469DC);
    }
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BDEC.c \
 *       --func func_0203BDEC --addr 0x0203BDEC --cc 1.1p1 --arm
 */
void func_0203BDEC(void)
{
    struct NetCtx *p = func_0203D798();
    struct NetCtx *s = func_0203D788();

    if ((u8)(p->f65 + 0xFD) <= 1) {
        if (s->vt->fAC() != 0)
            return;
        func_0203CEAC(0);
    } else {
        struct NetCtx *s2 = func_0203D788();

        if ((s2->vt->f7C() & 0xFFFE) != 0)
            return;
        func_0203CEAC(0);
    }
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BE5C.c \
 *       --func func_0203BE5C --addr 0x0203BE5C --cc 1.1p1 --arm
 */
void func_0203BE5C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    func_0203D3A8((void *)a4, 2, 0, 0);

    if (func_02039338() != 0)
        return;

    func_0203AD80(g_021469DC, ((void *)0x0203BDEC), 0, 0x46C);
}


























/*
 * "If the state is non-zero, park the card interface."  The result of the
 * test is kept in a local and returned, so the zero path is the `popeq` that
 * gives back r0 == 0 and the busy path returns whatever func_0203CEAC leaves
 * in r0 - no second `mov r0, #0` anywhere.
 *
 * The local is load-bearing: spelling it `if (func_02039338() == 0) return 0;
 * return func_0203CEAC(0);` hoists the `mov r0, #0` that sets up the call's
 * argument above the conditional return and lands two instructions late.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BEAC.c \
 *       --func func_0203BEAC --addr 0x0203BEAC --cc 1.1p1 --arm
 */
u32 func_0203BEAC(void)
{
    u32 r;

    r = func_02039338();
    if (r != 0)
        r = func_0203CEAC(0);
    return r;
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BEC8.c \
 *       --func func_0203BEC8 --addr 0x0203BEC8 --cc 1.1p1 --arm
 */
void func_0203BEC8(struct NetState *p)
{
    struct NetCtx *s;

    func_0203D798();
    s = func_0203D788();

    if (s->vt->f78() != 0) {
        if (s->vt->f14(0) == 0)
            return;
        func_0203AEEC(p);
        return;
    }

    if (s->vt->f6C() != 0)
        return;
    if (s->vt->f14(0) == 0)
        return;
    func_0203AEEC(p);
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BF4C.c \
 *       --func func_0203BF4C --addr 0x0203BF4C --cc 1.1p1 --arm
 */
void func_0203BF4C(void)
{
    struct NetCtx *s = func_0203D788();

    if (s->vt->f10(1, 0) == 0)
        return;

    func_0203AD80(g_021469DC, ((void *)0x0203BEC8), 0, 0x4A4);
}


























/*
 * 116 bytes, three functions: the setter, the 28-byte leaf that clears the
 * same flag, and the four-byte `bx lr` stub the card task is handed as a
 * callback (src/pending/func_0203C010.c passes it at 0x0203C00C).
 *
 * The two leaves carry no label in the generated listing - neither saves `lr`
 * - so this range used to stop at 0x0203BF9C with an `EXACT*`, the inferred
 * extent running on to the next labelled function at 0x0203C010.  Writing
 * them as the unit's own functions is what closes the range.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203BF9C.c \
 *       --addr 0x0203BF9C --arm --cc 1.1p1
 */
void func_0203BF9C(u32 v)
{
    struct NetState *p = g_021469DC;

    if (p != 0 && p->f51 != 0)
        return;

    p->f28 = (void (*)(void))v;
    g_021469DC->f51 = 1;
    func_0203AD80(g_021469DC, ((void *)func_0203BF4C), 5, 0x4B7);
}


























void func_0203BFF0(void)
{
    if (g_021469DC != 0)
        g_021469DC->f51 = 0;
}


























void func_0203C00C(void)
{
}























/*
 * PROMOTED FROM src/pending/ AT THE END OF WAVE 4 LANE 0x02038000..0x02040000.
 * It was parked at MATCH with every concrete byte right, held there only by
 * the `bl` to 0x020379C8, which nothing outside this range witnessed.  That
 * address has since been matched, so the site now resolves on the `matched`
 * class and the whole 52 bytes are EXACT with no change to the C at all.
 *
 * The callback stub this file passes, 0x0203C00C, is matched as well now, as
 * the last function of src/matched/unit_0203BF9C.c.
 *
 * Allocates 0x200 bytes, then starts the card task on the object at
 * 0x021469DC with the four-byte `bx lr` stub at 0x0203C00C as its callback and
 * 0x4DA (1242) as the fourth argument - the source file/line pair of an assert
 * style entry point.  The stub is a real 4-byte ARM function in the listing, so
 * its address is declared as the function it is and passed as a function
 * pointer; the pool word for it is attested by a dozen other pools elsewhere
 * in the image, and unk_021469DC likewise.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0203C010.c \
 *       --func func_0203C010 --addr 0x0203C010 --cc 1.1p1 --arm
 */
void func_0203C010(void)
{
    func_020379C8(0x200);
    func_0203AD80(g_021469DC, func_0203C00C, 0, 0x4DA);
}























struct NetCtx *func_0203C044(int a0, int a1, u8 *a2, int a3)
{
    struct NetCtx *t0 = func_0203D798();

    t0->f64 = *a2;
    return t0;
}






















/*
 * Empty callback (a lone bx lr), one of three adjacent stubs at
 * 0x0203C05C/60/64 whose addresses func_0203C0F4, func_0203C3EC,
 * func_0203C494 and func_0203C7E0 pass or compare as handler pointers.
 */
void func_0203C05C(void)
{
}






















void func_0203C060(void)
{
}






















void func_0203C064(void)
{
}























/*
 * Calls the virtual at +0xC of the object at *(net context + 0x340) with a
 * zero argument and reports through func_0203AD80 when it answers a negative
 * result.  The `mov r4, #0` local is what feeds both the call's r0 and the
 * report's r2, hence its placement; the `popge` is the `>= 0` half of the
 * signed comparison.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C068.c  *       --func func_0203C068 --addr 0x0203C068 --cc 1.1p1 --arm
 */
void func_0203C068(void)
{
    if (func_0203D788()->vt->f0C(0) < 0)
        func_0203AD80(g_021469DC, (void *)0x203C05C, 0, (int)0x52C);
}






















void func_0203C0B4(void)
{
    struct NetCtx *r = func_0203D788();
    func_020394DC(1);
    r->vt->f0C(0);
}























/*
 * Stores one byte at +0x4E, negating it first unless it is 1005 or 1006.  The
 * threshold is written `v - 1005 > 1`, and 1005 is not encodable as an ARM
 * immediate in a `sub`, so mwcc builds it the other way round: `mvn r2, #1004`
 * is -1005 and one `add` finishes the subtraction.  The comparison is
 * unsigned (`rsbhi`), and the negation is `rsb r1, r1, #0`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C0DC.c \
 *       --func func_0203C0DC --addr 0x0203C0DC --cc 1.1p1 --arm
 */
void func_0203C0DC(struct NetState *p, u32 v)
{
    if (v - 1005 > 1)
        v = -v;
    p->f4E = (u8)v;
}






















void func_0203C0F4(struct NetState *p)
{
    struct NetCtx *net = func_0203D788();
    struct NetVtbl *obj = net->vt;
    s32 res = obj->f0C(0);

    if (res == 1000) {
        func_0203AD80(g_021469DC, (void *)func_0203C0B4, 0, 1403);
        return;
    }

    obj = net->vt;
    if (obj->fAC() != 0) {
        func_0203AD80(g_021469DC, (void *)func_0203C0B4, 0, 1407);
        return;
    }

    if (res == 1007) {
        return;
    }

    if (res == 1001) {
        func_0203AD80(g_021469DC, (void *)func_0203C060, 0, 1413);
        return;
    }

    if (res == 1002) {
        func_0203AD80(g_021469DC, (void *)func_0203C064, 0, 1416);
        return;
    }

    if (res >= 10) {
        func_0203AD80(g_021469DC, (void *)func_0203C064, 0, 1420);
        return;
    }

    if (res >= 0) {
        return;
    }

    func_0203C0DC(p, res);
    func_0203AD80(g_021469DC, (void *)func_0203C05C, 0, 1424);
}
























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C238.c \
 *       --func func_0203C238 --addr 0x0203C238 --cc 1.1p1 --arm
 */
void func_0203C238(struct NetState *p)
{
    struct NetCtx *s = func_0203D788();
    struct NetCtx *q = func_0203D798();

    if (s->vt->f50(p->flag, q->f60, 0) != 0)
        return;

    func_02037D78();
    func_020398B4(s);
    func_02039834(s);
    func_0203AD80(g_021469DC, (void *)0x0203C0F4, 0, 0x5AC);
}
























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C2B0.c \
 *       --func func_0203C2B0 --addr 0x0203C2B0 --cc 1.1p1 --arm
 */
int func_0203C2B0(int a)
{
    if (a != -1) {
        if (func_0203778C((u32)a) == 0)
            return 0;
    }

    g_021469DC->flag = a;
    func_0203AD80(g_021469DC, (void *)0x0203C238, 0, 0x5C4);
    return 1;
}


























/*
 * Teardown of one half of the net context: flags the +0x48 sentinel as -2
 * (`mvn r1, #1`, which is only reachable when the field is a signed char -
 * an unsigned one would narrow to `mov r1, #0xfe`), tears the two handles
 * down and reports at line 0x5D9, returning success.  The twin at 0x0203C35C is
 * byte-identical apart from its own line literal.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C304.c  *       --func func_0203C304 --addr 0x0203C304 --cc 1.1p1 --arm
 */
u32 func_0203C304(void)
{
    struct NetCtx *h = func_0203D788();

    g_021469DC->flag = -2;
    func_02037D78();
    func_020398B4(h);
    func_02039834(h);
    func_0203AD80(g_021469DC, (void *)0x203C0F4, 0, (int)0x5D9);
    return 1;
}


























/*
 * Teardown of one half of the net context: flags the +0x48 sentinel as -2
 * (`mvn r1, #1`, which is only reachable when the field is a signed char -
 * an unsigned one would narrow to `mov r1, #0xfe`), tears the two handles
 * down and reports at line 0x5FD, returning success.  The twin at 0x0203C304 is
 * byte-identical apart from its own line literal.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C35C.c  *       --func func_0203C35C --addr 0x0203C35C --cc 1.1p1 --arm
 */
u32 func_0203C35C(void)
{
    struct NetCtx *h = func_0203D788();

    g_021469DC->flag = -2;
    func_02037D78();
    func_020398B4(h);
    func_02039834(h);
    func_0203AD80(g_021469DC, (void *)0x203C0F4, 0, (int)0x5FD);
    return 1;
}


























void func_0203C3B4(void)
{
    g_021469DC->flag = -1;
    func_0203AD80(g_021469DC, (void *)str_0203C238, 0, 0x60d);
}

























/*
 * Unlabelled ARM leaf (saves no register, so disasm.py gives it no func_
 * label): a channel-id classifier that reads the pointer at g_021469DC, then
 * the u32 at +8 of the record, and maps five distinct table addresses to
 * 0/1/3/4/5 (anything else returns 2).
 *
 * The five constants sit in their own pool words at 0x0203C450..0x0203C460
 * and are each loaded with `ldr` from pc, so they are link-time absolute
 * (R_ARM_ABS32) values that the compiler cannot fold against one another.
 * They are spelled as the addresses of the matched arm9 functions that live
 * at those addresses, taken as integers, so each becomes its own relocation
 * and no `sub`/constant-fold is possible.
 */
int func_0203C3EC(void)
{
    void *v = g_021469DC->f08;

    if (v == func_0203C0F4) {
        return 0;
    }
    if (v == func_0203C0B4) {
        return 1;
    }
    if (v == func_0203C068) {
        return 3;
    }
    if (v == func_0203C060) {
        return 4;
    }
    if (v == func_0203C064) {
        return 5;
    }
    return 2;
}
























void func_0203C464(void)
{
    func_0203D788();
    func_0203AD80(g_021469DC, (void *)0x203C0F4, 0, 0x637);
}


























/*
 * The other half of the connect/disconnect pair whose partner is
 * src/matched/func_0203C554.c: it turns the state byte at +0x4B into the
 * vtable's +0x54 hook, then either starts the link layer or, when the +0x0C
 * hook reports a negative result, files line 0x655.
 *
 * `v` is materialised as 0 before the first call and raised to 1 by
 * `moveq` on the state byte's own compare, so the hook's first argument
 * shares a register with the loop's zero rather than being rematerialised.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C494.c \
 *       --func func_0203C494 --addr 0x0203C494 --cc 1.1p1 --arm
 */
void func_0203C494(struct NetState *p)
{
    struct NetCtx *s = func_0203D788();
    u32 v = 0;

    func_020394DC(0);

    if (p->f4B == 0)
        v = 1;

    if (s->vt->f54(v, 0) != 0) {
        func_02037D78();
        func_020398B4(s);
        func_02039834(s);
        func_0203AD80(g_021469DC, (void *)func_0203C464, 0, 0x64F);
    } else if (s->vt->f0C(0) < 0) {
        func_0203AD80(g_021469DC, (void *)func_0203C05C, 0, 0x655);
    }
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C554.c \
 *       --func func_0203C554 --addr 0x0203C554 --cc 1.1p1 --arm
 */
void func_0203C554(u32 a)
{
    struct NetState *p = g_021469DC;

    if (p == 0)
        return;

    if (a != 0) {
        if (func_02039338() == 0)
            g_021469DC->f4B = 0;
        else
            g_021469DC->f4B = 1;
    } else {
        p->f4B = 0;
    }

    func_0203AD80(g_021469DC, (void *)0x0203C494, 0, 0x671);
    func_0203C494(g_021469DC);
}


























/*
 * Arms the sequence: the slot call with a literal 1, then the same 1 into the
 * object's byte at +0x4A.  The 1 lives in r4 across the call, which is why the
 * function pushes r4 at all.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C5C8.c \
 *       --func func_0203C5C8 --addr 0x0203C5C8 --cc 1.1p1 --arm
 */
void func_0203C5C8(void)
{
    func_0203C554(1);
    g_021469DC->f4A = 1;
}


























/*
 * Unlabelled ARM leaf: byte at +0x4a of the card task object.
 */
int func_0203C5EC(void)
{
    return g_021469DC->f4A;
}

























/*
 * Unlabelled ARM predicate: the callback at +8 of the card task object is func_0203C0F4.
 */
int func_0203C600(void)
{
    return g_021469DC->f08 == (void *)func_0203C0F4;
}

























/*
 * Unlabelled ARM predicate: the callback at +8 of the card task object is func_0203C0F4 or func_0203C464.
 */
int func_0203C628(void)
{
    void *cb = g_021469DC->f08;
    return cb == (void *)func_0203C0F4 || cb == (void *)func_0203C464;
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C65C.c \
 *       --func func_0203C65C --addr 0x0203C65C --cc 1.1p1 --arm
 */
void func_0203C65C(struct NetState *p)
{
    struct NetCtx *s;

    func_0203D798();
    s = func_0203D788();

    s->vt->f0C(1);

    if (s->vt->f78() != 0) {
        s->vt->f14(0);
        func_0203AEEC(p);
        return;
    }

    if (s->vt->f6C() == 0) {
        s->vt->f14(0);
        func_0203AEEC(p);
        return;
    }

    if (s->vt->f74() == 0)
        return;

    s->vt->f14(0);
    func_0203AEEC(p);
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C710.c \
 *       --func func_0203C710 --addr 0x0203C710 --cc 1.1p1 --arm
 */
void func_0203C710(void)
{
    struct NetCtx *s = func_0203D788();

    s->vt->f0C(0);
    if (s->vt->f10(1, 0) == 0)
        return;

    func_0203AD80(g_021469DC, (void *)0x0203C65C, 0, 0x702);
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C774.c \
 *       --func func_0203C774 --addr 0x0203C774 --cc 1.1p1 --arm
 */
void func_0203C774(u32 v)
{
    struct NetCtx *s;

    if (g_021469DC == 0)
        return;

    s = func_0203D788();
    func_020351A0(1);
    g_021469DC->f28 = (void (*)(void))v;
    s->vt->f54(1, 0);

    func_0203AD80(g_021469DC, (void *)0x0203C710, 5, 0x719);
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C7E0.c \
 *       --func func_0203C7E0 --addr 0x0203C7E0 --cc 1.1p1 --arm
 */
void func_0203C7E0(struct NetState *p)
{
    struct NetCtx *s = func_0203D788();
    int r = s->vt->f0C(0);

    if (r < 0) {
        func_0203C0DC(p, (u32)r);
        func_0203AD80(g_021469DC, (void *)0x0203C05C, 0, 0x72E);
    } else if (r > 0) {
        func_0203AD80(g_021469DC, (void *)0x0203C464, 0, 0x737);
    }
}

























/*
 * Promoted from src/pending/ on lane 1.  Every concrete byte is right; the one
 * open site was the `bl` to 0x02037700, whose only branch anywhere in the
 * image is this one, so `label` had no outside witness.  With
 * src/matched/func_02037700.c filed EXACT the site resolves through the
 * `matched` class and the file prints EXACT with no change to its C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C864.c \
 *       --func func_0203C864 --addr 0x0203C864 --cc 1.1p1 --arm
 */
void func_0203C864(void)
{
    struct NetCtx *p = func_0203D798();

    if (func_02037700(0x200, p->f56) == 0)
        return;

    func_0203AD80(g_021469DC, (void *)0x0203C7E0, 0, 0x74A);
}

























/*
 * 140 bytes, three functions.  The middle one, 0x0203C8E8, is a 16-byte leaf
 * that saves nothing and so carries no label in the generated listing; the
 * per-function file for 0x0203C8A8 therefore reported an `EXACT*`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203C8A8.c \
 *       --addr 0x0203C8A8 --arm --cc 1.1p1
 */
void func_0203C8A8(void)
{
    if (func_020392EC() != 0)
        return;

    func_0203D798();
    func_0203516C(1);
    func_0203AD80(g_021469DC, (void *)0x0203C864, 0, 0x760);
}

























void func_0203C8E8(u8 v)
{
    if (g_021469DC != 0)
        g_021469DC->f4F = v;
}

























void func_0203C900(u8 v)
{
    struct NetCtx *s = func_0203D788();

    if (g_021469DC != 0)
        g_021469DC->f50 = v;

    s->vt->f8C(v);
}
























void func_0203C934(void){ }

























/*
 * Opens the state: with no live object the answer is 0, otherwise the mode
 * byte at +0x4D is written, the two setup calls run and the answer is 1.
 * src/matched/func_0203C968.c is the matching close.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C938.c \
 *       --func func_0203C938 --addr 0x0203C938 --cc 1.1p1 --arm
 */
u32 func_0203C938(u8 mode)
{
    struct NetState *p;

    p = g_021469DC;
    if (p == 0)
        return 0;
    p->f4D = mode;
    func_02039548();
    func_02039578();
    return 1;
}

























/*
 * Closes the state src/matched/func_0203C938.c opens: clears the mode byte and
 * runs the teardown call.  With no live object it is a bare `popeq`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C968.c \
 *       --func func_0203C968 --addr 0x0203C968 --cc 1.1p1 --arm
 */
void func_0203C968(void)
{
    struct NetState *p;

    p = g_021469DC;
    if (p == 0)
        return;
    p->f4D = 0;
    func_02039560();
}

























/*
 * The mode byte src/matched/func_0203C938.c writes, read back - 0 when there
 * is no object.  Both loads are conditional, so the function is two
 * instructions plus the two pool words.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C990.c \
 *       --func func_0203C990 --addr 0x0203C990 --cc 1.1p1 --arm
 */
u32 func_0203C990(void)
{
    struct NetState *p;

    p = g_021469DC;
    return p ? p->f4D : 0;
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C9AC.c \
 *       --func func_0203C9AC --addr 0x0203C9AC --cc 1.1p1 --arm
 */
void func_0203C9AC(int a, u32 b, u32 c, u32 d)
{
    if (g_021469DC == 0)
        return;

    if ((u32)(a - 0x3ED) > 1)
        a = -a;

    g_021469DC->err[0] = a;
    g_021469DC->err[1] = b;
    g_021469DC->err[2] = c;
    g_021469DC->err[3] = d;

    if (d != 0)
        func_02039548();
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CA04.c \
 *       --func func_0203CA04 --addr 0x0203CA04 --cc 1.1p1 --arm
 */
void func_0203CA04(void)
{
    struct NetCtx *q;
    u32 t;

    if (g_021469DC == 0)
        return;

    q = func_0203D798();

    t = 0;
    if ((u8)(q->f65 + 0xFF) <= 5) {
        if (((1 << (u8)(q->f65 + 0xFF)) & 0x23) != 0)
            t = 1;
    }

    if (t == 0)
        func_02034714((const char *)((u32)g_020A7BA8), 0x8B7, (const char *)((u32)g_020A7BEC));

    g_021469DC->err[0] = 0;
    g_021469DC->err[1] = 0;
    g_021469DC->err[2] = 0;
    g_021469DC->err[3] = 0;
}






















/*
 * Returns the object's work area at +0x30, reporting through func_02034714
 * with the source file at 0x020A7BA8 and line 0x8CA (2250) when the object has
 * not been created - the report is not fatal, the address of the null object's
 * field is still what comes back.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CA98.c \
 *       --func func_0203CA98 --addr 0x0203CA98 --cc 1.1p1 --arm
 */
u32 func_0203CA98(void)
{
    if (g_021469DC == 0)
        func_02034714(file_020A7BA8, 0x8CA, file_020A7C70);
    return (u32)g_021469DC->err;
}






















/*
 * Unlabelled ARM assert thunk: tail call func_02034714(g_020A7BA8, 0x8D8, g_020A7C7C), the fall-through failure path after func_0203CA98.
 */
void func_0203CADC(void)
{
    func_02034714((const char *)((u32)g_020A7BA8), 0x8D8, (const char *)((u32)g_020A7C7C));
}






















/*
 * Unlabelled ARM predicate: the card task object exists and its callback at +8 is func_0203CADC.
 * MATCH only because 0x0203CADC (func_0203CADC.c, EXACT) is not yet a labelled
 * function start: the pool word has no outside witness until the seed lands.
 */
int func_0203CB00(void)
{
    struct NetState *c = g_021469DC;
    if (c != 0 && c->f08 == (void *)func_0203CADC) {
        return 1;
    }
    return 0;
}






















/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CB34.c \
 *       --func func_0203CB34 --addr 0x0203CB34 --cc 1.1p1 --arm
 */
void func_0203CB34(u32 a, u32 b, u32 c, u32 d)
{
    u32 *p = (u32 *)func_0200F17C(1);
    u32 v = a;

    if (p != 0)
        ((void (*)(u32, u32))p[0])(a, b);

    func_0200F234(1);

    if (c != d) {
        *(u16 *)0x021469E0 = (u16)d;
        func_0203064C(c, d, 0x9E80);
    }

    func_020371AC(0, 0);
    func_020370C8();
}






















/*
 * note:     net.c: start one network session (0x354-byte record on the
 *           request's +0x56 heap, published into g_021469E0's +8 slot, the
 *           vtable from func_0200F17C for mode +0x65, then a seven-way mode
 *           switch).  Closed in wave 16 after the 80-byte residue of
 *           docs/notes/pkt_0203CBAC.c.txt:
 *           - the id guard at the head and in the beacon arm is a call in
 *             BOTH arms with the non-zero arm written FIRST; the image's
 *             kept `beq; b` pair is the empty (cross-jumped) then-arm, and
 *             the beacon arm's cross-jump into the shared `bl` follows;
 *           - case map per the note's finding 1 (1/2/6 vtable, 3/4 beacon,
 *             0/5 break, default the line-0x8e error), both arms `break`;
 *           - the tail boolean is `f = 0; if (...) f = 1;`, which is the
 *             image's `mov r2, #0` / `movls r2, #1`, and the 3-or-4 exit
 *             test is bound to `int done` (otherwise it folds to a range
 *             check).
 *           func_0203D8F0 and func_0203AFCC resolve as sole-ref/code.
 */
void func_0203CBAC(struct Req *req, u32 a2, u32 a3)
{
    struct NetCtx *s;
    u8 m;
    u32 f;

    if (g_021469E0.f00 != 0)
        func_0203064C(g_021469E0.f00, req->f56, 0x7800);
    else
        func_0203064C(req->f54, req->f56, 0x7800);
    s = (struct NetCtx *)func_02030734(req->f56, 0x354, 1, file_020A7CA0, 0x6a);
    g_021469E0.f08 = s;
    s->f352 = 1;
    s->vt = (struct NetVtbl *)func_0200F17C(req->f65);
    if (s->vt == 0)
        func_02034714(file_020A7CA0, 0x6f, str_020A7CA8);
    if (req->f65 == 4)
        req = (struct Req *)func_0203D8F0((const struct NetHdr *)req, a3);
    func_02082D44(req, s, 0x70);
    switch (req->f65) {
    case 1:
    case 2:
    case 6:
        s->vt->f00(req->f54, 0);
        func_0203064C(req->f54, (u16)(req->f58 | 0x8000), req->f48);
        break;
    case 3:
    case 4:
        if (req->f61 > 0x80)
            func_02034714(file_020A7CA0, 0x84, str_020A7CB8);
        if (g_021469E0.f00 != 0)
            func_0203064C(g_021469E0.f00, req->f5a, 0x1b00);
        else
            func_0203064C(req->f54, req->f5a, 0x1b00);
        break;
    case 0:
    case 5:
        break;
    default:
        func_02034714(file_020A7CA0, 0x8e, str_020A7CE8);
        return;
    }
    s->f34C = a3;
    func_0203AFCC((void *)req->f56, a2);
    func_02039834(s);
    func_0203A494(req->f67 << 8, req->f00, req->f04, s->f34C, req->f56);
    m = req->f65;
    {
        int done = (m == 3) || (m == 4);
        if (done)
            return;
    }
    f = 0;
    if ((u8)(m + 0xff) <= 1)
        f = 1;
    func_02037010(req->f5c, req->f5e, f, req->f56);
}






















/*
 * Guarded call through a function-pointer table: fetch the singleton via
 * func_0203D788, bail to 0 if it is null, then chase the pointer at +0x340
 * to a table and call its +0x6c entry through a register (no relocation
 * site there, `blx r0`).  func_0203D788 has many outside callers, so its
 * own call closes on the `label` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CD98.c \
 *       --func func_0203CD98 --addr 0x0203CD98 --cc 1.1p1 --arm
 */
int func_0203CD98(void)
{
    struct NetCtx *s = func_0203D788();

    if (s == 0) {
        return 0;
    }

    return s->vt->f6C();
}
























int func_0203CDBC(void)
{
    return func_0203D788() == 0;
}
























/*
 * Net teardown/mode dispatch.  Fetches the state record, snapshots four
 * fields, fires two optional callbacks through function-pointer fields,
 * runs the shared shutdown calls, clears a word of the global block and
 * then dispatches on the mode byte.
 *
 * THE DISPATCH BASE IS THE WHOLE PUZZLE, and it is worth stating plainly
 * because an off-by-one here costs a whole pass.  The image has:
 *
 *   0203CE3C  cmp   r8, #6
 *   0203CE40  addls pc, pc, r8, lsl #2
 *   0203CE44  b     #0x203ce78          <- NOT table[0]
 *   0203CE48  b     #0x203ce8c          <- table[0]
 *
 * `addls pc, pc, ...` reads pc as the instruction address PLUS 8, so the
 * base is 0x0203CE40 + 8 = 0x0203CE48 and entry k sits at 0x0203CE48 + 4k.
 * The word at 0x0203CE44, which LOOKS like the first table slot in a plain
 * byte diff, is the out-of-range fallthrough branch to the default arm.
 * Reading it as table[0] shifts every case by one and yields a residue that
 * no source-level edit can fix: the blocks all land at the right addresses
 * and only the dispatch words differ.  The true mapping is
 *
 *   0 -> break      1 -> f(b)    2 -> f(b)    3 -> f(c)
 *   4 -> f(c)       5 -> break   6 -> f(b)    default -> assert, return
 *
 * The assert arm must be spelled `default:`, not `case 0:`; with an
 * explicit case 0 the fallthrough word at 0x0203CE44 is wrong.
 *
 * PERMUTER RESULT (negative, and recorded because it is the evidence that
 * the residue was structural rather than an allocation tie):
 *   hill,   budget 800,  --types: 181 single mutations, none improved.
 *   anneal, budget 3000, --types: 3000 compiles in 128s, completely flat at
 *   asm=30 bytes-out=8 size=216/216, never once below the baseline.
 * Six different source orderings of the five arms were also measured by
 * hand and every one gave byte-identical output.  A residue that flat is
 * not a spelling problem, which is what sent the work back to the dispatch
 * arithmetic.
 *
 * func_0200F234 is THUMB and reached by `blx`; declaring it arm makes
 * match.py refuse the site outright (it checks the .thumb_func marker).
 * The g_021469E0 store is written g_021469E0[2] rather than
 * *(u32 *)(0x021469E0 + 8): the constant-plus-offset form folds the +8
 * into the pool word and compiles to `str r1, [r0]`.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0203CDD4.c \
 *       --func func_0203CDD4 --addr 0x0203CDD4 --cc 1.1p1 --arm
 */
void func_0203CDD4(void)
{
    struct NetCtx *s = func_0203D788();
    void (*f)(u32);
    u16 a;
    u16 b;
    u16 c;
    u8 m;

    f = s->f348;
    a = s->f56;
    b = s->f58;
    c = s->f5A;
    m = s->f65;

    if (f != 0)
        f(s->f34C);

    f = s->f2C;
    if (f != 0)
        f(s->f34C);

    func_020398B4(s);
    func_0200F234(m);
    func_020307B0(s);

    g_021469E0.f08 = 0;

    switch (m) {
    case 1:
    case 2:
    case 6:
        func_020306F0(b);
        break;
    case 3:
    case 4:
        func_020306F0(c);
        break;
    case 0:
    case 5:
        break;
    default:
        func_02034714(str_020A7CA0, 0xEE, str_020A7CE8);
        return;
    }

    func_020306F0(a);
    func_02034FB8(4);
}
























/*
 * Net bring-up: fetch the state object, run its per-frame tick, and if the
 * object exists stamp the caller's handle into it, then install one of two
 * handlers according to the object's mode byte and finish with the shared
 * tail.  Both handler installs take the same address (0x0203CDD4) and the
 * image loads it from one pool word at 0x0203CF00, so the source names the
 * function at both call sites rather than hoisting it into a local.
 *
 * FILED EXACT 2026-09-22.  This file sat in src/pending as MATCH on two
 * blockers that were both bookkeeping errors, not evidence gaps:
 *
 *   * the `bl` at +0040 was declared `func_0203D70C8` / `0x0203D70C8`, an
 *     address with NINE hex digits.  The instruction is `bl #0x20370c8`, so
 *     the target is 0x020370C8 -- a stray `D`.  The real address is an EXACT
 *     manifest entry (src/matched/func_020370C8.c) and also carries 15
 *     outside branches, so it attests as `label` immediately.
 *   * the ABS32 at +0054 was declared `g_0203CDD4 ... data`.  0x0203CDD4 is
 *     a traced ARM function start (it pushes lr), i.e. this is a FUNCTION
 *     POINTER argument, not a data address.  Declared `data` it was routed
 *     to sole-ref/data, which correctly refuses a code target; declared
 *     `arm` it resolves through sole-ref/code.
 *
 * The C itself was already byte-correct and is unchanged apart from the two
 * declarations and the argument type (void * rather than u8 *).
 *
 * Two spellings still matter, from the original lane's work:
 *   * `if (p != 0) { ... return 1; } return 0;` -- the `if (p == 0) return 0;`
 *     guard form compiles to `moveq r0, #0` + `popeq {r3, r4, r5, pc}` and
 *     shifts every following byte; the image branches to a separate
 *     out-of-line `mov r0, #0; pop {...}` block at 0x0203CEF8.
 *   * the mode byte is read into a named local *before* the caller's handle
 *     is stored into the object, which is the image's order (`ldrb r0,
 *     [r4, #0x65]` at +001C, `str r5, [r4, #0x348]` at +0020).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0203CEAC.c \
 *       --func func_0203CEAC --addr 0x0203CEAC --cc 1.1p1 --arm
 */
int func_0203CEAC(void (*a0)(u32))
{
    struct NetCtx *p;

    p = func_0203D788();
    func_0203DA20();
    if (p != 0) {
        u8 t = p->f65;

        p->f348 = a0;
        if (t == 1) {
            func_0203C774((u32)func_0203CDD4);
        } else {
            func_0203BF9C((u32)func_0203CDD4);
        }
        func_020370C8();
        return 1;
    }
    return 0;
}
























void func_0203CF04(void)
{
    func_0203BFF0();
}
























/*
 * Dispatches through the vtable at +0x340 of the state object: the entry at
 * +0x28 takes the single argument and its result is returned.  A missing state
 * object is the `moveq`/`popeq` pair that answers 0.  The vtable pointer
 * itself is not checked - src/matched/func_0203D17C.c is the neighbouring
 * hook that does check it.
 *
 * The indirect call is a register `blx` with an ordinary `pop {r4, pc}`
 * epilogue: not the ARMv4T-style return that would name a 1.2-built function,
 * so it is compiled C like any other.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CF10.c \
 *       --func func_0203CF10 --addr 0x0203CF10 --cc 1.1p1 --arm
 */
u32 func_0203CF10(u32 a)
{
    struct NetCtx *p;

    p = func_0203D788();
    if (p == 0)
        return 0;
    return p->vt->f28(a);
}
























/*
 * The same vtable dispatch as src/matched/func_0203CF10.c, one slot further
 * on (+0x2C) and without the null test: the state object is assumed live and
 * the hook's pointer result is returned to the caller.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CF3C.c \
 *       --func func_0203CF3C --addr 0x0203CF3C --cc 1.1p1 --arm
 */
void *func_0203CF3C(u32 a)
{
    struct NetCtx *p;

    p = func_0203D788();
    return p->vt->f2C(a);
}
























/*
 *           --suggest-split offers nothing (single function, all four
 *           unresolved sites' only witnesses are inside this range).
 *           all four) -- each has no witness outside 0203CF5C..0203CFA0; every
 *           branch to them in the image is this function's own call. Four of
 *           the eight sites resolve. Every concrete byte of the body
 *           reproduces. Note the chain is two levels deep: func_0203B1D8,
 *           also called here, is itself a documented DIFF
 *           (docs/notes/pkt_0203B1D8.c.txt) and func_02037154 is a pending
 *           MATCH park.
 */
u32 func_0203CF5C(void)
{
    struct NetCtx *p = func_0203D788();

    func_0203EA9C();
    func_0203DC70();
    if (func_0203B1D8() != 0) {
        return 1;
    }
    if (p == 0) {
        return 1;
    }
    func_02037154();
    func_02039D94();
    func_02037C10();
    return func_02039594();
}
























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CFA0.c \
 *       --func func_0203CFA0 --addr 0x0203CFA0 --cc 1.1p1 --arm
 */
void func_0203CFA0(void)
{
    struct NetCtx *s = func_0203D788();
    struct NetCtx *p;

    if (func_0203B1D8() != 0)
        return;
    if (s == 0 || s->vt == 0)
        return;

    p = func_0203D798();
    switch (p->f65) {
    case 1:
    case 2:
        return;
    }

    s->vt->f0C(0);
}
























/*
 * Tail-call wrapper: func_0203B0C4(p, 1).  Called by state 10 of
 * func_0203DC70 with ctx + 0x94.  NOTE: layout/symbols_sdk.txt lists this
 * address as DWC_IsSendableReliable (thumb), a false signature match: the
 * bytes are ARM (`ldr ip, [pc, #4]; mov r1, #1; bx ip`) and the caller
 * reaches it with an ARM `bl`.
 */
void func_0203CFF0(void *p)
{
    func_0203B0C4((int)p, 1);
}
























/*
 * Tail-call wrapper: func_0203B0C4(p, 0), the twin of func_0203CFF0.
 * NOTE: layout/symbols_sdk.txt lists this address as FATFS_FormatDrive
 * (thumb), a false signature match: the bytes are ARM.
 */
void func_0203D000(void *p)
{
    func_0203B0C4((int)p, 0);
}
























/*
 * Tail-call wrapper (`ldr ip, [pc]; bx ip`, docs/idioms tail-call-is-a-
 * pool-word-and-bx), called by state 10 of func_0203DC70.  An unlabelled
 * ARM leaf inside func_0203CFA0's EXACT* extent; filed as a witness.
 */
void func_0203D010(void)
{
    func_0203B1B0();
}
























void func_0203D01C(void)
{
    struct NetCtx *s = func_0203D788();

    switch (s->f65) {
    case 1:
    case 2:
        func_0203C3B4();
        return;
    case 0:
    case 5:
        func_0203B2D0(s->f56);
        return;
    default:
        return;
    }
}























/*
 * PARKED AT MATCH.  Every concrete byte is right; the one open site is the
 * `bl` to 0x0203DA7C, whose only caller in the image is this function, and
 * 0x0203DA7C lies past this packet (another lane's), so it cannot be matched
 * from here.
 *
 * The trailing `*` is the usual unlabelled-follower case and not a byte
 * difference: the inferred extent runs on to 0x0203D0D0 because the three
 * eight-byte ARM long-branch veneers at 0x0203D0AC, 0x0203D0B8 and 0x0203D0C4
 * save no `lr` and so carry no label.  They want seeding into
 * layout/function_starts.txt, which is the integrator's file.
 *            caller, address outside this packet)
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D060.c \
 *       --func func_0203D060 --addr 0x0203D060 --cc 1.1p1 --arm
 */
void func_0203D060(u32 a, u32 b, u32 c)
{
    struct NetCtx *s = func_0203D788();
    u32 v = a;

    if (func_0203DA4C() == 1)
        v = (u32)func_0203DA7C((void *)a, (void *)b, (void *)c);

    func_0203BA98(s->f56, v, 1);
}






















void func_0203D0AC(int a0)
{
    func_0203E5AC(a0);
}






















void func_0203D0B8(void *dst, u32 i)
{
    func_0203DBB0(dst, i);
}






















void func_0203D0C4(unsigned int value)
{
    func_0203DA68(value);
}






















void func_0203D0D0(void){ func_0203D9EC(); }























void func_0203D0DC(u32 a0)
{
    func_0203BA98(func_0203D788()->f56, a0, 1);
}





















void func_0203D0FC(int a)
{
    func_0203D788();
    func_0203C010();
}



















void func_0203D10C(u32 a0)
{
    func_0203BA98(func_0203D788()->f56, a0, 0);
}





















/*
 * EXACT*, not EXACT: the inferred extent runs on to 0x0203D17C because the
 * four eight-byte ARM long-branch veneers at 0x0203D14C, 0x0203D158,
 * 0x0203D164 and 0x0203D170 save no `lr` and so carry no label.  It is not a
 * byte difference.  They want seeding into layout/function_starts.txt, which
 * is the integrator's file.
 *
 * Guarded forwarding call: the hook at 0x0203CD98 answers whether the
 * connection is up, and only then is the argument handed to 0x02037A44.  The
 * `bl` at the top passes r0 through untouched, so the callee is declared
 * `void` while this one takes the value it later forwards.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D12C.c \
 *       --func func_0203D12C --addr 0x0203D12C --cc 1.1p1 --arm
 */
void func_0203D12C(int a)
{
    if (func_0203CD98() == 0)
        return;

    func_02037A44(a);
}




















void func_0203D14C(u32 a0, u32 a1, u8 *a2)
{
    func_0203BD30(a0, a1, a2);
}




















u32 func_0203D158(void)
{
    return func_0203E4E8();
}




















void func_0203D164(int a0)
{
    func_0203E538(a0);
}




















int func_0203D170(void)
{
    return func_0203E590();
}
























/*
 * Vtable dispatch with the *vtable pointer* null-checked (the state object
 * itself is not): the entry at +0xC4 takes the argument, and the hook's value
 * is dropped.  Two loads separate the two tests, which is what makes this
 * shape distinct from src/matched/func_0203CF10.c and
 * src/matched/func_0203CF3C.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D17C.c \
 *       --func func_0203D17C --addr 0x0203D17C --cc 1.1p1 --arm
 */
void func_0203D17C(u32 a)
{
    struct NetCtx *p;
    struct NetVtbl *vt;

    p = func_0203D788();
    vt = p->vt;
    if (vt == 0)
        return;
    vt->fC4(a);
}
























/*
 * Forward to func_020395EC and mask the result to a byte.  func_020395EC is
 * called from func_0203D578 (outside this range), which is what attests the
 * `bl` here as a real function rather than a wildcarded relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D1A4.c \
 *       --func func_0203D1A4 --addr 0x0203D1A4 --cc 1.1p1 --arm
 */
u32 func_0203D1A4(struct Link *p)
{
    return func_020395EC((struct Entry *)p) & 0xff;
}























int func_0203D1B4(void)
{
    return func_020399EC();
}























/*
 * TU: net.c (named by the assert site at 0x0203D2EC, which passes the
 * string at 0x020A7CA0, "net.c").
 *
 * Guard on the network singleton, then a two-step query: look the entry
 * `index` up with func_0203996C and ask func_020399B8 about the result.
 * The `moveq r0, #0` is a no-op on the value it guards; it only exists
 * because the source spells the null return out.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D1C0.c \
 *       --func func_0203D1C0 --addr 0x0203D1C0 --cc 1.1p1 --arm
 */
u32 func_0203D1C0(u32 index)
{
    if (func_0203D788() == 0) {
        return 0;
    }
    return func_020399B8((u8 *)func_0203996C(index));
}






















void func_0203D1E8(u32 unused, void *arg)
{
    void (*fn)(void *) = func_0203D788()->vt->fB8;

    if (fn == 0) {
        return;
    }
    fn(arg);
}






















/*
 * TU: net.c.
 *
 * "Nothing running, or the +0x6c hook says idle".  The first test reads
 * g_021469E0.f08 straight out of the singleton (the same two
 * instructions func_0203D788 is made of), while the second goes through the
 * real call; that asymmetry is what says the first read is a file-local
 * access and not an inlined copy of the extern.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D210.c \
 *       --func func_0203D210 --addr 0x0203D210 --cc 1.1p1 --arm
 */
u32 func_0203D210(void)
{
    if (g_021469E0.f08 == 0) {
        return 1;
    }
    return func_0203D788()->vt->f6C() == 0;
}
























/*
 * TU: net.c.
 *
 * Store a halfword pair into +0x5c/+0x5e of the network state block, if it
 * exists.  Both stores are predicated off the one null test, which is why
 * the two parameters have to survive the accessor call in r5/r4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D24C.c \
 *       --func func_0203D24C --addr 0x0203D24C --cc 1.1p1 --arm
 */
void func_0203D24C(u16 a, u16 b)
{
    struct NetCtx *s = func_0203D798();

    if (s != 0) {
        s->f5C = a;
        s->f5E = b;
    }
}
























/*
 * TU: net.c.
 *
 * "State is 3 or 4" predicate on the +0x65 mode byte of the network
 * singleton.  The range test is written as one unsigned compare on the
 * biased byte, so the original spells `- 3` as `add r0, r0, #0xfd` with the
 * `and r0, r0, #0xff` that the u8 cast forces.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D26C.c \
 *       --func func_0203D26C --addr 0x0203D26C --cc 1.1p1 --arm
 */
u32 func_0203D26C(void)
{
    struct NetCtx *s = func_0203D788();

    if (s != 0) {
        if ((u8)(s->f65 + 0xfd) <= 1) {
            return 1;
        }
    }
    return 0;
}
























/*
 * TU: net.c.
 *
 * Sibling of func_0203D26C one range lower: "state is 1 or 2" on the +0x65
 * mode byte.  Same shape, `add r0, r0, #0xff` for the bias instead of
 * `#0xfd`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D29C.c \
 *       --func func_0203D29C --addr 0x0203D29C --cc 1.1p1 --arm
 */
u32 func_0203D29C(void)
{
    struct NetCtx *s = func_0203D788();

    if (s != 0) {
        if ((u8)(s->f65 + 0xff) <= 1) {
            return 1;
        }
    }
    return 0;
}
























/*
 * TU: net.c.  This is the function that names it: the assert call at
 * 0x0203D2EC passes the string at 0x020A7CA0, which reads "net.c", with
 * line 0x364 (868) and the message string "0" at 0x020A7CE8.
 *
 * Refresh of the on-screen connection indicator.  Both accessors are
 * called even though they return the same singleton field (func_0203D798
 * null-checks it, func_0203D788 does not); the original keeps both results
 * live in r4 and r5 and uses r4 only for the mode test, so the two calls
 * are in the source, not an artefact.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D2CC.c \
 *       --func func_0203D2CC --addr 0x0203D2CC --cc 1.1p1 --arm
 */
void func_0203D2CC(void)
{
    struct NetCtx *a = func_0203D798();
    struct NetCtx *b = func_0203D788();

    if (func_020338F8() == 1) {
        func_02034714(g_020A7CA0, 868, g_020A7CE8);
        return;
    }
    if (b != 0 && a->f65 != 3) {
        u32 flag = 0;

        if ((u8)(b->f65 + 0xff) <= 1) {
            flag = 1;
        }
        func_02037010(b->f5C, b->f5E, flag, b->f56);
    } else {
        func_020370C8();
    }
}
























/*
 * TU: net.c.
 *
 * Three-call sequence: stamp the (0xf0, 0) pair into the state block, run
 * the transfer at 0x02037118 with this function's own two arguments, then
 * kick the state machine at 0x0203D2CC.  Both arguments have to outlive the
 * first call, which is what spends r5/r4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D34C.c \
 *       --func func_0203D34C --addr 0x0203D34C --cc 1.1p1 --arm
 */
void func_0203D34C(u32 a, u32 b)
{
    func_0203D24C(0xf0, 0);
    func_02037118(a, b);
    func_0203D2CC();
}
























/*
 * TU: net.c.
 *
 * Inverted forward: 1 when func_02039338 reports zero.  The result local is
 * initialised before the call, so the zero lands in r4 ahead of the `bl`
 * and the true case is a single `moveq`; writing `return f() == 0;`
 * instead puts the materialisation after the call and loses the shape.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D378.c \
 *       --func func_0203D378 --addr 0x0203D378 --cc 1.1p1 --arm
 */
u32 func_0203D378(void)
{
    u32 res = 0;

    if (func_02039338() == 0) {
        res = 1;
    }
    return res;
}
























/*
 * TU: net.c.
 *
 * Leaf predicate on the +0x4a byte of an entry: "is this entry in state 5".
 * No relocation and no frame; the same three-instruction body appears
 * inlined inside func_020399B8.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D394.c \
 *       --func func_0203D394 --addr 0x0203D394 --cc 1.1p1 --arm
 */
u32 func_0203D394(struct NetEntry *e)
{
    return e->state == 5;
}























/*
 * TU: net.c.
 *
 * Seven-argument send wrapper.  The leading func_0203D798 call is made for
 * effect only, its result is dead in the original, and the four incoming
 * arguments all have to survive it, which is what spends r4-r7.  Arguments
 * five to seven go on the stack, hence the `sub sp, sp, #0xc`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D3A8.c \
 *       --func func_0203D3A8 --addr 0x0203D3A8 --cc 1.1p1 --arm
 */
int func_0203D3A8(struct Entry *a, u32 b, u32 c, const void *d)
{
    func_0203D798();
    return func_02038C18(b, d, c, 0, func_020395EC(a), 0xff, 0);
}























/*
 *           the image and it is the call inside this function, so `label` has
 *           no outside witness for either and no manifest entry covers them
 *           yet.  File those two addresses first and this graduates with no
 *           change to its C (every other site resolves).
 */
u32 func_0203D3F8(void *entry, u32 sendID, u32 c, u32 d, const void *e, u32 f, u32 g, u32 h)
{
    u8 mask;

    func_0203D798();
    mask = 0xff;
    if (func_0203D394((struct NetEntry *)entry) == 0 && c >= 0x11) {
        return 0;
    }
    if (g != 0 && func_02039468(c, func_020395EC((void *)entry)) != 0) {
        return 0;
    }
    if (sendID != 0xff) {
        if (sendID >= 7) {
            func_02034714(g_020A7CA0, 1019, g_020A7CEC);
        }
        mask = 1 << sendID;
    }
    return func_02038C18(c, e, d, f, func_020395EC((void *)entry), mask, h);
}























/*
 * TU: net.c.
 *
 * The explicit-mask sibling of func_0203D3F8: identical guards, but the
 * destination bitmask arrives as the second parameter instead of being
 * derived from a send id, so there is no assert and no `lsl`, and the mask
 * stays in r6 across the whole body.  The two stack arguments that live
 * next to each other go out as one `stmib`.
 *
 * EXACT*, not EXACT: the inferred extent runs to 0x0203D578 because the
 * follower at 0x0203D56C has no label.  It is not a byte difference; the
 * follower is a twelve-byte ARM long-branch veneer (ldr ip, [pc]; bx ip;
 * .word 0x020394C0) that saves no lr and so is invisible to disasm.py.  It
 * wants seeding into layout/function_starts.txt, which is the integrator's
 * file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D4D0.c \
 *       --func func_0203D4D0 --addr 0x0203D4D0 --cc 1.1p1 --arm
 */
u32 func_0203D4D0(void *entry, u32 mask, u32 c, u32 d, const void *e, u32 f, u32 g,
                  u32 h)
{
    func_0203D798();
    if (func_0203D394((struct NetEntry *)entry) == 0 && c >= 0x11) {
        return 0;
    }
    if (g != 0 && func_02039468(c, func_020395EC((void *)entry)) != 0) {
        return 0;
    }
    return func_02038C18(c, e, d, f, func_020395EC((void *)entry), mask, h);
}






















void func_0203D56C(void)
{
    func_020394C0();
}























/*
 * Forwards the first argument through func_020395EC and passes the result
 * with the second argument to func_02039468.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D578.c \
 *       --func func_0203D578 --addr 0x0203D578 --arm --cc 1.1p1
 */
void func_0203D578(int a, u32 b)
{
    u32 r = func_020395EC((void *)a);

    func_02039468(b, r);
}




















void func_0203D594(void *p, u16 tag)
{
    func_02039C3C(p, tag);
}




















void func_0203D5A0(void)
{
    func_02039CA0();
}





















/*
 * PROMOTED from src/pending/.  The `bl` to 0x0203A458 was this file's last
 * open site; it now resolves as `matched` against that function's own EXACT
 * shard entry, so the cap is gone.
 *
 * Sets the net context's +0x67 byte to the argument (after forcing the
 * context through func_0203D788), then updates the channel with
 * func_0203996C(0xff) and func_0203A458.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D5AC.c \
 *       --func func_0203D5AC --addr 0x0203D5AC --arm --cc 1.1p1
 */
void func_0203D5AC(int a, int b)
{
    struct NetCtx *p;

    func_0203D788();
    p = func_0203D798();
    p->f67 = (u8)a;
    func_0203A458((u8 *)func_0203996C(0xff), a);
}






















/*
 * Returns the byte at +0x67 of the net context, or 0 when there is none.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D5D4.c \
 *       --func func_0203D5D4 --addr 0x0203D5D4 --arm --cc 1.1p1
 */
u32 func_0203D5D4(void)
{
    struct NetCtx *p = func_0203D798();

    return p != 0 ? p->f67 : 0;
}






















/*
 * Calls the net context's +0x44 callback with its +0x34c argument, or
 * returns 0 when no callback is installed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D5EC.c \
 *       --func func_0203D5EC --addr 0x0203D5EC --arm --cc 1.1p1
 */
u32 func_0203D5EC(void)
{
    struct NetCtx *p = func_0203D788();

    if (p->f44 == 0) {
        return 0;
    }
    return ((u32 (*)(u32)) p->f44)(p->f34C);
}






















/*
 * Calls the net context's +0x40 callback with its +0x34c argument, or
 * returns 0 when no callback is installed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D610.c \
 *       --func func_0203D610 --addr 0x0203D610 --arm --cc 1.1p1
 */
u32 func_0203D610(void)
{
    struct NetCtx *p = func_0203D788();

    if (p->f40 == 0) {
        return 0;
    }
    return ((u32 (*)(u32)) p->f40)(p->f34C);
}
















u32 func_0203D634(void)
{
    return func_0203D788()->f62;
}

















void func_0203D644(u32 a)
{
    func_020394F0(a);
}



















/*
 * Returns the word at +0x34c of the net context, or 0 when there is none.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D650.c \
 *       --func func_0203D650 --addr 0x0203D650 --arm --cc 1.1p1
 */
u32 func_0203D650(void)
{
    struct NetCtx *p = func_0203D788();

    return p != 0 ? p->f34C : 0;
}



















/*
 * Stores the argument at +0x34c of the net context, when there is one.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D668.c \
 *       --func func_0203D668 --addr 0x0203D668 --arm --cc 1.1p1
 */
void func_0203D668(u32 v)
{
    struct NetCtx *p = func_0203D788();

    if (p != 0) {
        p->f34C = v;
    }
}


















/*
 * Returns the net context's +0x60 byte, reporting through func_02034714 with
 * the source file at 0x020A7CA0 ("net.c") and line 0x593 (1427) when the byte
 * is past 8.  The guard is unsigned (`bls`), so the comparison is
 * `> 8` against an unsigned char.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D680.c \
 *       --func func_0203D680 --addr 0x0203D680 --cc 1.1p1 --arm
 */
u32 func_0203D680(void)
{
    struct NetCtx *p = func_0203D788();

    if (p->f60 > 8)
        func_02034714(file_020A7CA0, 0x593, file_020A7CF8);
    return p->f60;
}



















/*
 * Returns the byte at +0x61 of the net context.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D6BC.c \
 *       --func func_0203D6BC --addr 0x0203D6BC --arm --cc 1.1p1
 */
u32 func_0203D6BC(void)
{
    return func_0203D788()->f61;
}



















/*
 * Halfword getter for the null-test sibling of func_0203D680: reports through
 * func_02034714 at line 0x5B1 (1457) when func_0203D788 comes back null, then
 * reads +0x6C from it regardless.  The null test is the `movs r4, r0` /
 * `bne` pair, so the result is kept in a local that the tail still
 * dereferences rather than being re-requested.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D6CC.c  *       --func func_0203D6CC --addr 0x0203D6CC --cc 1.1p1 --arm
 */
u32 func_0203D6CC(void)
{
    struct NetCtx *p = func_0203D788();

    if (p == 0)
        func_02034714(file_020A7CA0, 0x5B1, file_020A7D2C);
    return p->f6C;
}



















/*
 * Calls the net context's +0x30 callback with its +0x34c argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D700.c \
 *       --func func_0203D700 --addr 0x0203D700 --arm --cc 1.1p1
 */
void func_0203D700(void)
{
    struct NetCtx *p = func_0203D788();

    if (p->f30 != 0) {
        ((void (*)(u32)) p->f30)(p->f34C);
    }
}



















/*
 * Calls the net context's +0x28 callback with the func_020399A8 result,
 * the argument and the context's +0x34c value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D720.c \
 *       --func func_0203D720 --addr 0x0203D720 --arm --cc 1.1p1
 */
void func_0203D720(u32 a)
{
    struct NetCtx *p = func_0203D788();

    if (p->f28 == 0) {
        return;
    }
    ((void (*)(u32, u32, u32)) p->f28)(
        (u32)func_020399A8(), a, p->f34C);
}



















/*
 * Calls the net context's +0x24 callback with the func_020399A8 result,
 * the argument and the context's +0x34c value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D754.c \
 *       --func func_0203D754 --addr 0x0203D754 --arm --cc 1.1p1
 */
void func_0203D754(u32 a)
{
    struct NetCtx *p = func_0203D788();

    if (p->f24 == 0) {
        return;
    }
    ((void (*)(u32, u32, u32)) p->f24)(
        (u32)func_020399A8(), a, p->f34C);
}















struct NetCtx *func_0203D788(void)
{
    return g_021469E0.f08;
}















/*
 * Accessor for the +8 handle of the singleton at 0x021469E0, with the null
 * case spelled out.  The `moveq r0, #0` is a no-op on the value it guards,
 * so it is only there because the source writes the null return
 * explicitly; a plain `return g->unk_08;` loses the `cmp` and the `moveq`
 * and is eight bytes short.
 *
 * EXACT*, not EXACT: the inferred extent runs to 0x0203D7C8 because the
 * follower at 0x0203D7B0 has no label.  It is not a byte difference; the
 * follower is a pair of eight-byte ARM long-branch veneers (0x0203D7B0 ->
 * 0x0203C8E8 and 0x0203D7BC -> 0x0203C900), which save no lr and so are
 * invisible to disasm.py.  Both want seeding into
 * layout/function_starts.txt, which is the integrator's file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D798.c \
 *       --func func_0203D798 --addr 0x0203D798 --cc 1.1p1 --arm
 */
struct NetCtx *func_0203D798(void)
{
    if (g_021469E0.f08 == 0) {
        return 0;
    }
    return g_021469E0.f08;
}















/*
 *           prologue is `ldr r1, [pc, #0xc]` and saves no lr, so disasm.py
 *           emitted no func_ label there (the unlabelled-leaf idiom) and
 *           evidence().labels has no entry.  sole-ref/code therefore refuses
 *           it, veneer_at() does not recognise it, and the pool word under
 *           test is the only reference to it in the image, so `literal` and
 *           `label` both discard their only witness.  All 12 bytes are
 *           correct.  It becomes EXACT the moment 0x0203C8E8 is seeded into
 *           layout/function_starts.txt (the integrator's file) or a second
 *           referrer is decompiled.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/pending/func_0203D7B0.c \
 *       --func func_0203D7B0 --addr 0x0203D7B0 --cc 1.1p1 --arm
 */
void func_0203D7B0(u8 a0)
{
    func_0203C8E8(a0);
}















/*
 * A long-branch veneer pair with func_0203D7B0: the image spells both as
 * `ldr ip, [pc]; bx ip; .word target`, which this compiler emits for a
 * tail call to an ARM callee whose address must come from a pool.
 *
 * The ABS32 at +0008 resolves through sole-ref/code: 0x0203C900 is a
 * traced ARM function start (its prologue saves lr, so disasm.py labelled
 * it), and sole-ref/code accepts an exact label start without requiring a
 * second referrer.  Its neighbour func_0203D7B0 is NOT filable the same
 * way -- 0x0203C8E8 opens with a bare `ldr` and saves no lr, so disasm.py
 * never labelled it and no class can carry the site.  That is why these
 * two 12-byte twins are in different directories.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0203D7BC.c \
 *       --func func_0203D7BC --addr 0x0203D7BC --cc 1.1p1 --arm
 */
void func_0203D7BC(u8 a0)
{
    func_0203C900(a0);
}















/*
 * Allocates size rounded up to 0x20 plus 0x20, rounds the result up to a
 * 0x20 boundary and stores the raw pointer in the word just before the
 * aligned block, which func_0203D7FC releases it by.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D7C8.c \
 *       --func func_0203D7C8 --addr 0x0203D7C8 --arm --cc 1.1p1
 */
void *func_0203D7C8(u32 a, u32 size, const char *c, u16 d)
{
    u8 *p = (u8 *)func_02030734(a, ((size + 0x24) & ~0x1fu) + 0x20, 1, c, d);
    u8 *q = (u8 *)(((u32)p + 0x20) & ~0x1fu);

    *(void **)(q - 4) = p;
    return q;
}















/*
 * Releases the aligned block func_0203D7C8 returns, via the pointer kept
 * just before it, and tolerates a null.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D7FC.c \
 *       --func func_0203D7FC --addr 0x0203D7FC --arm --cc 1.1p1
 */
void func_0203D7FC(void *p)
{
    if (p == 0) {
        return;
    }
    func_020307B0(*(void **)((u8 *)p - 4));
}















/*
 * Stores the two net_irc_wireless context words at +0xc and +4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D814.c \
 *       --func func_0203D814 --addr 0x0203D814 --arm --cc 1.1p1
 */
void func_0203D814(u32 a, u32 b)
{
    g_021469E0.f0C = a;
    g_021469E0.f04 = b;
}















/*
 * Reads back the two net_irc_wireless context words.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D828.c \
 *       --func func_0203D828 --addr 0x0203D828 --arm --cc 1.1p1
 */
void func_0203D828(u32 *a, u32 *b)
{
    *a = g_021469E0.f0C;
    *b = g_021469E0.f04;
}















/*
 * Copies 0x70 bytes from the net context into the destination.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D844.c \
 *       --func func_0203D844 --addr 0x0203D844 --arm --cc 1.1p1
 */
void func_0203D844(void *dst)
{
    func_02082D44(dst, func_0203D788(), 0x70);
}















/*
 * Clears the net context's +0x2c and +0x1c words.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D864.c \
 *       --func func_0203D864 --addr 0x0203D864 --arm --cc 1.1p1
 */
void func_0203D864(void)
{
    struct NetCtx *p = func_0203D788();

    if (p != 0) {
        p->f2C = 0;
        p->f1C = 0;
    }
}















/*
 * A bare tail-call thunk to func_02039414.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D880.c \
 *       --func func_0203D880 --addr 0x0203D880 --arm --cc 1.1p1
 */
u32 func_0203D880(void)
{
    return func_02039414();
}















/*
 * Truncates both arguments to 16 bits, then runs the pair through
 * func_020371AC and func_0203D2CC.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D88C.c \
 *       --func func_0203D88C --addr 0x0203D88C --arm --cc 1.1p1
 */
void func_0203D88C(u32 a, u32 b)
{
    func_020371AC((u16)a, (u16)b);
    func_0203D2CC();
}















/*
 * Runs func_020371AC(0, 0) and func_0203D2CC.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D8AC.c \
 *       --func func_0203D8AC --addr 0x0203D8AC --arm --cc 1.1p1
 */
void func_0203D8AC(void)
{
    func_020371AC(0, 0);
    func_0203D2CC();
}















/*
 * Writes 1 or 0 to the net context's +0x352 byte depending on whether the
 * argument is 1; a null context is a no-op.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D8C4.c \
 *       --func func_0203D8C4 --addr 0x0203D8C4 --arm --cc 1.1p1
 */
void func_0203D8C4(u32 a)
{
    u8 *p = (u8 *)g_021469E0.f08;

    if (p == 0) {
        return;
    }
    if (a == 1) {
        p[0x352] = 1;
    } else {
        p[0x352] = 0;
    }
}















/*
 * net_irc_wireless.c.  Wraps a caller's 0x70-byte task header: allocates a
 * 0x10C-byte record low on the header's own heap (id | 0x8000, __FILE__
 * 0x020A7D34, line 0x72), copies the header in, saves the header's three
 * callbacks (+0x2C, +0x18, +0x1C) at +0x80/+0x78/+0x7C, installs the
 * wireless callbacks func_0203DC4C, func_0203E420, func_0203E458 in their
 * place, publishes the record at 0x021469F0 and returns it.  With a live
 * record whose +0x101 is 1 it returns the header untouched.
 *
 * The lever (docs/notes/pkt_0203D8F0.c.txt had 63 bytes out, 40 after
 * the permuter): the header parameter is `const Base *`.  Without const
 * the stores into the new record may alias the header, so the compiler
 * keeps the header loads behind them and schedules the allocator's stack
 * argument differently; with const both regions reproduce.
 */
NetHdr *func_0203D8F0(const NetHdr *src, u32 a1)
{
    NetLink *obj;

    if (g_021469F0 != 0 && g_021469F0->f101 == 1)
        return (NetHdr *)src;

    obj = func_02030734((u16)((src->heap & 0x7FFF) | 0x8000), sizeof(NetLink), 1, (const char *)d_020A7D34, 0x72);
    obj->hdr = *src;
    obj->f70 = a1;
    obj->f80 = src->f2C;
    obj->f78 = src->f18;
    obj->f7C = src->f1C;
    obj->hdr.f65 = 3;
    obj->hdr.f2C = func_0203DC4C;
    obj->hdr.f18 = func_0203E420;
    obj->hdr.f1C = func_0203E458;
    obj->f104 = obj->hdr.f64;
    obj->hdr.f64 = 0;
    obj->f107 = obj->hdr.f60;

    g_021469F0 = obj;
    func_02034F84(0x20);
    return &g_021469F0->hdr;
}













/*
 * Tears down the net_irc_wireless singleton at 0x021469F0: releases it
 * through func_02034FB8(0x20) and the heap release, then clears the slot.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D9EC.c \
 *       --func func_0203D9EC --addr 0x0203D9EC --arm --cc 1.1p1
 */
void func_0203D9EC(void)
{
    if (g_021469F0 == 0) {
        return;
    }
    func_02034FB8(0x20);
    func_020307B0(g_021469F0);
    g_021469F0 = 0;
}













/*
 * Calls func_0203D9EC when the net_irc_wireless singleton exists and its
 * +0x101 byte is clear.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203DA20.c \
 *       --func func_0203DA20 --addr 0x0203DA20 --arm --cc 1.1p1
 */
void func_0203DA20(void)
{
    NetLink *p = g_021469F0;

    if (p == 0) {
        return;
    }
    if (p->f101 != 0) {
        return;
    }
    func_0203D9EC();
}













int func_0203DA4C(void)
{
    return g_021469F0 != 0;
}











/*
 * Stores a word into the singleton at +0x74.
 */
void func_0203DA68(unsigned int value)
{
    g_021469F0->f74 = value;
}












/*
 * Install the three wireless callbacks and hand back the state machine that
 * drives them.  With no live context (0x021469F0 null) the function returns
 * its first argument untouched - the image leaves r0 alone on that path, so
 * the early exit is `bxeq lr`, not a `moveq r0, #0`.  Otherwise each non-null
 * argument is stored at +0x84, +0x88 and +0x8C of the context, and the
 * function returns func_0203DC04.
 *
 * The context is re-read from the global for the second and third stores
 * (`ldrne r0, [pc, ...]; ldrne r0, [r0]`), because the first store could
 * alias the global: the source spells them g_021469F0->unk_88 rather than
 * reusing a cached local.  The first store uses the value already in r3.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203DA7C.c \
 *       --func func_0203DA7C --addr 0x0203DA7C --cc 1.1p1 --arm
 */
void *func_0203DA7C(void *a0, void *a1, void *a2)
{
    NetLink *p = g_021469F0;

    if (p == 0)
        return a0;
    if (a0 != 0)
        p->f84 = (void (*)(u32))a0;
    if (a1 != 0)
        g_021469F0->f88 = (void (*)(u32, int))a1;
    if (a2 != 0)
        g_021469F0->f8C = (void (*)(u32))a2;
    return func_0203DC04;
}










void func_0203DAC4(const u8 *mac)
{
    int i;

    if (g_021469F0 == 0)
        return;
    for (i = 0; i < 4; i++) {
        if (func_0203EFC8(mac, g_021469F0->macs.mac[i].addr, 6) == 0)
            return;
    }
    {
        u8 buf[6] = {0, 0, 0, 0, 0, 0};
        for (i = 0; i < 4; i++) {
            if (func_0203EFC8(buf, g_021469F0->macs.mac[i].addr, 6) == 0) {
                func_02082D44(mac, g_021469F0->macs.mac[i].addr, 6);
                g_021469F0->macs.count = i;
                return;
            }
        }
    }
    func_0203C938(1);
}









void func_0203DBB0(void *dst, u32 i)
{
    NetLink *g = g_021469F0;

    if (g != 0) {
        func_02082D44(g->macs.mac[i].addr, dst, 6);
    } else {
        func_02034714((const char *)str_020A7D34, 0x109, (const char *)str_020A7D48);
    }
}








void func_0203DC04(void)
{
    if (g_021469F0 == 0)
        return;
    g_021469F0->f102 = 1;
    if (g_021469F0->f106 != 0) {
        g_021469F0->f105 = g_021469F0->f106 - 1;
    } else {
        g_021469F0->f105 = func_02039338();
    }
}








/*
 * net_irc_wireless.c.  Callback installed at +0x2C by func_0203D8F0 and
 * by states 4 and 14 of func_0203DC70: flags +0x103 of the live context.
 * An unlabelled ARM leaf.
 */
void func_0203DC4C(void)
{
    NetLink *p = g_021469F0;

    if (p != 0)
        p->f103 = 1;
}








/*
 * net_irc_wireless.c.  The state setter of the wireless state machine
 * func_0203DC70: stores the new state at +0x109.  An unlabelled ARM leaf
 * (no lr save), filed as the `matched` witness for func_0203DC70's 27 calls.
 */
void func_0203DC68(NetLink *p, int state)
{
    p->f109 = state;
}






void func_0203DC70(void)
{
    NetLink *p = g_021469F0;

    if (p == 0)
        return;

    switch (p->f109) {
    case 0:
        if (p->f102 != 1)
            return;
        p->f101 = 1;
        func_02039C68((struct Link *)func_020399A8(), 3, 0);
        func_0203DC68(p, 1);
        break;
    case 1:
        if (func_02039CB4((struct Link *)func_020399A8(), 3, 0) == 0)
            return;
        func_0203DC68(p, 2);
        break;
    case 2:
        if (func_02039338() == 0) {
            if (func_0203D3A8(func_020399A8(), 1, 0, 0) == 0)
                return;
            func_0203DC68(p, 3);
            p->f100 = 0xC8;
        } else {
            if (func_0203D3A8(func_020399A8(), 0x10, 0, 0) == 0)
                return;
            func_0203DC68(p, 3);
        }
        break;
    case 3:
        p->f100--;
        if (func_0203D210()) {
            if (g_021469F0->f8C != 0)
                g_021469F0->f8C(g_021469F0->f70);
            if (p->f10A != 0 && p->hdr.f60 == 4 && p->f105 == 0) {
                func_0203DC68(p, 0xE);
                p->f108++;
            } else if (p->f105 == 0 && p->hdr.f60 == 4) {
                p->f108++;
                func_0203CEAC(0);
                p->f88(p->f70, 1);
                func_0203DC68(p, 4);
            } else {
                p->f88(p->f70, 0);
                func_0203DC68(p, 9);
            }
        }
        if (p->f100 == 0)
            func_0203CEAC(0);
        break;
    case 4:
        if (func_0203CD98() != 0)
            return;
        p->hdr.f65 = 3;
        p->hdr.f2C = (void *)func_0203DC4C;
        if (p->f10B != 0)
            p->hdr.f67 = p->f10B;
        p->f102 = 0;
        p->f103 = 0;
        func_0203CBAC((struct Req *)p, 0, p->f70);
        func_0203DC68(p, 5);
        break;
    case 5:
        if (func_0203CD98() != 1)
            return;
        func_0203D788()->vt->fC8(g_021469F0->f74);
        func_0203D0DC((int)((void *)func_0203DC04));
        func_0203DC68(p, 6);
        break;
    case 6:
        if (p->f102 != 1)
            return;
        p->f101 = 1;
        if (func_0203D3A8(func_020399A8(), 9, 0x24, &g_021469F0->macs) == 0)
            return;
        func_0203DC68(p, 7);
        break;
    case 7:
        if (p->f102 != 1)
            return;
        if (func_0203D3A8(func_020399A8(), 1, 0, 0) == 0)
            return;
        func_0203D17C(0xC8);
        func_0203DC68(p, 8);
        break;
    case 8:
        if (func_0203D210() == 0)
            return;
        if (g_021469F0->f8C != 0)
            g_021469F0->f8C(g_021469F0->f70);
        func_0203DC68(p, 9);
        break;
    case 9:
        if (func_0203D210() == 0)
            return;
        if (p->f10B != 0) {
            p->hdr.f6E = 0;
            p->hdr.f67 = p->f10B;
        }
        p->hdr.f65 = 0;
        p->hdr.f2C = p->f80;
        p->hdr.f64 = p->f104;
        func_0203CBAC((struct Req *)p, 0, p->f70);
        g_021469F0->f101 = 0;
        func_0203DC68(p, 0xA);
        break;
    case 10:
        if (func_0203CD98() != 1)
            return;
        if (p->f105 == 0) {
            func_0203D01C();
            func_0203DC68(p, 0xC);
        } else if (p->hdr.f60 == 4) {
            func_0203D010();
            func_0203DC68(p, 0xB);
        } else {
            func_0203CFF0(p->macs.mac);
            func_0203DC68(p, 0xC);
        }
        break;
    case 11: {
        u8 mac[6];
        int i;
        int j;
        u8 *q;

        i = 0;
        func_02087C6C(mac);
        for (;; i++) {
            q = (u8 *)func_0203CF10((int)i);
            if (q == 0)
                return;
            for (j = 0; j < 4; j++) {
                if (func_0203EFC8(mac, q + 4 + j * 8, 6) == 0) {
                    func_0203D000(func_0203CF3C((u32)i));
                    func_0203DC68(p, 0xC);
                    break;
                }
            }
        }
    }
    case 12:
        if (p->f105 == 0) {
            if (func_020399EC() == 0)
                return;
            if (func_02039ACC() != 1)
                return;
            func_0203DC68(p, 0xD);
        } else {
            if (func_02039ACC() != 1)
                return;
            func_0203DC68(p, 0xD);
        }
        break;
    case 13:
        if (p->f105 != 0) {
            if (p->f84 != 0)
                p->f84(p->f70);
            func_0203DA20();
        } else {
            if (func_020399EC() < p->f107)
                return;
            if (p->f84 != 0)
                p->f84(p->f70);
            func_0203DA20();
        }
        break;
    case 14:
        if (func_0203CD98() != 0)
            return;
        p->hdr.f65 = 3;
        p->hdr.f2C = (void *)func_0203DC4C;
        p->f102 = 0;
        p->f103 = 0;
        func_0203CBAC((struct Req *)p, 0, p->f70);
        func_0203DC68(p, 0xF);
        break;
    case 15:
        if (func_0203CD98() != 1)
            return;
        func_0203D788()->vt->fC8(g_021469F0->f74);
        func_0203D0DC((int)((void *)func_0203DC04));
        func_0203DC68(p, 0x10);
        break;
    case 16:
        if (p->f102 != 1)
            return;
        func_02039C68((struct Link *)func_020399A8(), 3, 0);
        g_021469F0->f101 = 1;
        func_0203DC68(p, 0x11);
        break;
    case 17:
        if (func_02039CB4((struct Link *)func_020399A8(), 3, 0) == 0)
            return;
        if (func_0203D3A8(func_020399A8(), 1, 0, 0) == 0)
            return;
        func_0203DC68(p, 0x12);
        p->f100 = 0xC8;
        break;
    case 18:
        p->f100--;
        if (func_0203D210() == 0 && p->f100 != 0)
            return;
        if (g_021469F0->f8C != 0)
            g_021469F0->f8C(g_021469F0->f70);
        if (p->f10A != 0 && p->f108 < 3) {
            p->f108++;
            if (p->f108 >= 3)
                func_0203DC68(p, 9);
            else
                func_0203DC68(p, 0xE);
        } else {
            func_0203DC68(p, 9);
        }
        break;
    }
}





void *func_0203E420(void *arg)
{
    NetLink *p = g_021469F0;
    void *r;

    if (p == 0)
        return 0;
    r = p->f78(arg);
    func_02082D44(r, p->fB4, 0x4C);
    return &p->macs;
}



void *func_0203E458(void *arg)
{
    void *r;
    if (g_021469F0 == 0)
        return 0;
    r = g_021469F0->f7C(arg);
    return (char *)r + 0x24;
}




/*
 *           --suggest-split offers nothing (single function, the one
 *           unresolved site's only witness is inside this range).
 *           the file string at 0x020A7D34 ("net_irq_wireless.c") ends at
 *           0x020A7D46, six bytes before this message, so the `string` class
 *           refuses. Every concrete byte of the body reproduces (the register
 *           choice for the loop bound and the index is fixed by declaring the
 *           index first).
 */
void func_0203E484(u32 a, u32 b, struct NetMacList *p)
{
    int i;
    int n;

    if (p->count >= 4) {
        func_02034714((const char *)str_020A7D34, 0x2a5, (const char *)str_020A7D4C);
    }
    n = p->count;
    if (n > 4) {
        n = 4;
    }
    for (i = 0; i < n; i++) {
        func_0203DAC4(p->mac[i].addr);
    }
}




/*
 * Gated state step: only a context whose +0x109 state is 0x10 advances, and
 * it does so by seeding +0x107 from +0x108, re-entering the sub-state and
 * parking the state byte at 9.  The final store re-reads the global, because
 * the call in between may have replaced the context pointer - the same
 * reload the store-after-a-call shape produces.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203E4E8.c \
 *       --func func_0203E4E8 --addr 0x0203E4E8 --cc 1.1p1 --arm
 */
u32 func_0203E4E8(void)
{
    NetLink *p = g_021469F0;

    if (p == 0)
        return 0;
    if (p->f109 != 0x10)
        return 0;
    p->f107 = p->f108 + 1;
    func_0203CEAC(0);
    g_021469F0->f109 = 9;
    return 1;
}


void func_0203E538(int a0)
{
    if (g_021469F0 == 0)
        func_02034714(s_020A7D34, 0x2e4, s_020A7D68);
    if (g_021469F0 != 0) {
        *(u8 *)((char *)g_021469F0 + 0x106) = (u8)(a0 + 1);
        *(u8 *)((char *)g_021469F0 + 0x10a) = 1;
    }
}


/*
 * Reads byte 0x108 of the singleton, or 0 when it is not allocated.
 */
int func_0203E590(void)
{
    unsigned char *p = d_021469F0;
    if (p == 0) return 0;
    return p[0x108];
}


void func_0203E5AC(int a0)
{
    if (g_021469F0 == 0)
        func_02034714(s_020A7D34, 0x31a, s_020A7D68);
    if (g_021469F0 != 0)
        *(u8 *)((char *)g_021469F0 + 0x10b) = (u8)a0;
}
