/*
 * file:     field_wfbc.c
 * unit:     yes
 * function: func_02193628, func_02193790, func_021938AC, func_021938D4, func_021938F4, func_021938FC, func_02193904, func_0219390C, func_0219391C, func_02193920, func_02193924, func_021939C0, func_02193ABC, func_02193AFC, func_02193B04, func_02193B20, func_02193B40, func_02193B68, func_02193BC4, func_02193BE4, func_02193C00, func_02193C04, func_02193C08, func_02193C80, func_02193CBC, func_02193D08, func_02193D30, func_02193E54, func_02193EB4, func_02193EE8, func_02193EFC, func_02193F34, func_02193F6C, func_02193F80, func_02193FBC, func_02193FD4, func_02193FE8, func_02194014, func_02194038, func_02194044, func_02194078, func_02194084, func_02194128, func_02194284, func_021942C8, func_02194300, func_02194354, func_02194384, func_021943EC, func_02194418, func_02194434, func_021944BC, func_021944C8, func_021944D8, func_02194588, func_021945A0, func_021945A4, func_021945E0, func_02194670, func_02194704, func_0219470C, func_02194760, func_02194764, func_02194798, func_021947E8, func_02194848, func_02194888, func_021948CC, func_0219492C, func_02194940, func_02194950, func_02194960, func_02194974, func_02194984, func_02194990, func_0219499C, func_02194A00, func_02194A24, func_02194A34, func_02194A48, func_02194A58, func_02194A74, func_02194A84, func_02194A94, func_02194AC8, func_02194B3C, func_02194B70, func_02194B78, func_02194B84, func_02194C60, func_02194CE8, func_02194D1C, func_02194E74, func_02194E90, func_02194F5C, func_02194F84, func_02195128, func_0219518C, func_02195338, func_021953D4, func_0219545C, func_02195490, func_021954CC, func_02195530, func_02195588, func_021955EC, func_02195938, func_02195E54, func_02195E70, func_02195E80, func_02195E90, func_02196030, func_02196034, func_0219603C, func_021961A4, func_02196228, func_02196290, func_021962C4, func_021962F4, func_0219630C, func_02196454, func_0219649C, func_021964B0, func_02196538, func_021966B0, func_021966F0, func_02196768, func_021967BC, func_02196804, func_0219686C, func_021968D8, func_021968DC, func_02196944, func_02196974, func_02196A4C, func_02196A60, func_02196ACC, func_02196B24, func_02196B28, func_02196B7C, func_02196B90, func_02196B94, func_02196BF8, func_02196C68, func_02196CD8, func_02196D20, func_02196D24, func_02196D88, func_02196D94, func_02196E04, func_02196E70, func_02196EC8, func_02196ECC, func_02196F44, func_02196FF0, func_02196FFC, func_02197058, func_0219707C, func_02197190
 * address:  0x02193628
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
 *   func_02169520  0x02169520  thumb ov010
 *   func_0216959C  0x0216959C  thumb ov010
 *   func_02169530  0x02169530  thumb ov010
 *   func_021695BC  0x021695BC  thumb ov010
 *   func_02169620  0x02169620  thumb ov010
 *   func_02169528  0x02169528  thumb ov010
 *   func_02169540  0x02169540  thumb ov010
 *   func_02169580  0x02169580  thumb ov010
 *   func_02169560  0x02169560  thumb ov010
 *   func_02169578  0x02169578  thumb ov010
 *   func_02169598  0x02169598  thumb ov010
 *   func_0218DD04  0x0218DD04  thumb ov021
 *   func_0218DD08  0x0218DD08  thumb ov021
 *   func_0218DD0C  0x0218DD0C  thumb ov021
 *   func_0218DD10  0x0218DD10  thumb ov021
 *   func_0218B974  0x0218B974  thumb ov021
 *   func_0218DCF4  0x0218DCF4  thumb ov021
 *   func_0218DCFC  0x0218DCFC  thumb ov021
 *   func_021A7410  0x021A7410  thumb ov021
 *   _ll_mul        0x0209C054  arm
 *   func_0207C768  0x0207C768  arm
 *   func_02030734  0x02030734  arm  arm9
 *   d_021DDA60     0x021DDA60  data   ov021  a1
 *   func_0216D974  0x0216D974  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_021C939C  0x021C939C  thumb  ov021
 *   func_021C93E4  0x021C93E4  thumb  ov021
 *   func_021C9450  0x021C9450  thumb  ov021
 *   func_021C93D0  0x021C93D0  thumb  ov021
 *   func_020493D4  0x020493D4  arm
 *   func_02049250  0x02049250  arm
 *   func_0216245C  0x0216245C  thumb  ov010
 *   d_021D3F60     0x021D3F60  data  a4
 *   func_0204A380  0x0204A380  arm
 *   func_0218E17C  0x0218E17C  thumb  ov021
 *   func_02186748  0x02186748  thumb  ov020
 *   func_0200846C  0x0200846C  thumb
 *   func_020084A0  0x020084A0  thumb
 *   func_020084D4  0x020084D4  thumb
 *   func_0200852C  0x0200852C  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02186764  0x02186764  thumb
 *   func_02186770  0x02186770  thumb
 *   func_021867C4  0x021867C4  thumb  ov020
 *   func_020490F4  0x020490F4  arm
 *   func_02186830  0x02186830  thumb
 *   func_02049238  0x02049238  arm  arm9
 *   func_02186804  0x02186804  thumb  ov020
 *   func_0218683C  0x0218683C  thumb  ov020
 *   func_02082BCC  0x02082BCC  arm
 *   func_0218625C  0x0218625C  thumb  ov020
 *   func_02161ECC  0x02161ECC  thumb  ov010
 *   func_02186818  0x02186818  thumb  ov020
 *   func_02186844  0x02186844  thumb  ov020
 *   func_0218682C  0x0218682C  thumb  ov020
 *   func_0204932C  0x0204932C  arm
 *   d_021D3F58     0x021D3F58  data  a4
 *   func_0218609C  0x0218609C  thumb  ov020
 *   func_021860B8  0x021860B8  thumb  ov020
 *   func_021867B0  0x021867B0  thumb  ov020
 *   func_02082D44  0x02082D44  arm  arm9
 *   func_02186278  0x02186278  thumb  ov020
 *   _u32_div_f     0x0209C2B0  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   _ull_mul       0x0209C054  arm
 *   d_021DDA70     0x021DDA70  data  a4
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_02163C04  0x02163C04  thumb  ov010
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   d_021D3F68     0x021D3F68  data  ov021  a4
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   func_0216E014  0x0216E014  thumb  ov010
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216DC98  0x0216DC98  thumb  ov010
 *   func_0216DB80  0x0216DB80  thumb  ov010
 *   func_0216DAE0  0x0216DAE0  thumb  ov010
 *   func_0216DC64  0x0216DC64  thumb  ov010
 *   func_0216DCCC  0x0216DCCC  thumb  ov010
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021A0ED4  0x021A0ED4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_020124E4  0x020124E4  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_020129D0  0x020129D0  thumb
 *   func_021A0F30  0x021A0F30  thumb  ov021
 *   func_020129B8  0x020129B8  thumb
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_0203101C  0x0203101C  arm
 *   d_021DDAC4     0x021DDAC4  data  a4
 *   d_020A8140     0x020A8140  data  a4
 *   d_020A8148     0x020A8148  data  a4
 *   func_020310C4  0x020310C4  arm
 *   func_0206DB80  0x0206DB80  arm
 *   d_020A814C     0x020A814C  data  a4
 *   d_020A8144     0x020A8144  data  a4
 *   func_02031140  0x02031140  arm
 *   func_0206DF3C  0x0206DF3C  arm
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_020409B4  0x020409B4  arm
 *   func_020452E8  0x020452E8  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_0206E0C4  0x0206E0C4  arm
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045748  0x02045748  arm
 *   func_02045750  0x02045750  arm
 *   func_02045730  0x02045730  arm
 *   func_02040804  0x02040804  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CBD0  0x0207CBD0  arm
 *   func_02048AFC  0x02048AFC  arm
 *   func_02048B20  0x02048B20  arm
 *   func_02048B44  0x02048B44  arm
 *   func_02048B60  0x02048B60  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_0207D7C4  0x0207D7C4  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B0C  0x02048B0C  arm
 *   func_02048B30  0x02048B30  arm
 *   func_02048B54  0x02048B54  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02049624  0x02049624  arm
 *   func_0207F7A0  0x0207F7A0  arm
 *   DC_FlushRange  0x020862F0  arm
 *   func_0207F7FC  0x0207F7FC  arm
 *   func_0207F9B4  0x0207F9B4  arm
 *   func_0207FA0C  0x0207FA0C  arm
 *   func_0207FA40  0x0207FA40  arm
 *   func_0207FADC  0x0207FADC  arm
 *   d_021DDA84     0x021DDA84  data  a4
 *   d_021DDAA4     0x021DDAA4  data  a4
 *   func_02041300  0x02041300  arm
 *   func_02045374  0x02045374  arm
 *   func_020456F8  0x020456F8  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_02040588  0x02040588  arm
 *   func_02040C14  0x02040C14  arm
 *   d_021D40A0     0x021D40A0  data  ov021  a4
 *   d_021D40C0     0x021D40C0  data  ov021  a4
 *   d_021D40E0     0x021D40E0  data  ov021  a4
 *   d_021D4100     0x021D4100  data  ov021  a4
 *   d_021D4120     0x021D4120  data  ov021  a4
 *   d_021D4140     0x021D4140  data  ov021  a4
 *   func_02021518  0x02021518  thumb
 *   func_0202155C  0x0202155C  thumb
 *   func_020216D4  0x020216D4  thumb
 *   func_02021FD8  0x02021FD8  thumb
 *   func_02021730  0x02021730  thumb
 *   func_020215A0  0x020215A0  thumb
 *   func_02021540  0x02021540  thumb
 *   func_0207E5D0  0x0207E5D0  arm
 *   func_0207E468  0x0207E468  arm
 *   func_0202F038  0x0202F038  thumb
 *   func_0202EE8C  0x0202EE8C  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D42C  0x0201D42C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02051C6C  0x02051C6C  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049740  0x02049740  arm
 *   func_02049990  0x02049990  arm
 *   func_02049F78  0x02049F78  arm
 *   func_0201F5DC  0x0201F5DC  thumb
 *   d_021DDAD4     0x021DDAD4  data  ov021  a2
 *   func_02051B84  0x02051B84  arm
 *   d_021D4070     0x021D4070  data  a4
 *   d_021D4014     0x021D4014  data  a4
 *   d_021D4024     0x021D4024  data  a4
 *   d_021D404C     0x021D404C  data  a4
 *   d_021DDB84     0x021DDB84  data  a4
 *   func_0201DD68  0x0201DD68  thumb
 *   func_02040DA8  0x02040DA8  arm
 *   func_0203FB44  0x0203FB44  arm
 *   func_020403F4  0x020403F4  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02045808  0x02045808  arm
 *   func_020221A4  0x020221A4  thumb
 *   func_02155A90  0x02155A90  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_0202208C  0x0202208C  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02155A94  0x02155A94  thumb  ov010
 *   func_0200873C  0x0200873C  thumb
 *   func_02008428  0x02008428  thumb
 *   func_02197700  0x02197700  thumb  ov021
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204BA00  0x0204BA00  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_021975D0  0x021975D0  thumb  ov021
 *   func_02035C60  0x02035C60  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA1C  0x0201AA1C  thumb
 *   func_02197644  0x02197644  thumb  ov021
 *   func_02051C88  0x02051C88  arm
 *   d_021D3FE0     0x021D3FE0  data  ov021  a4
 *   d_021D3FF4     0x021D3FF4  data  ov021  a4
 *   d_021DDAF4     0x021DDAF4  data  ov021  a4
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BBA8  0x0200BBA8  thumb
 *   func_0219728C  0x0219728C  thumb  ov021
 *   d_021D4080     0x021D4080  data  ov021  a4
 *   d_021D4034     0x021D4034  data  ov021  a4
 *   d_021DDB44     0x021DDB44  data  ov021  a4
 *   d_021D3F9C     0x021D3F9C  data  ov021  a1
 *   func_021973A0  0x021973A0  thumb  ov021
 *   d_021D3FD8     0x021D3FD8  data  ov021  a4
 *   d_021D4004     0x021D4004  data  ov021  a4
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B688  0x0204B688  arm
 *   d_021D3FC8     0x021D3FC8  data  ov021  a1
 *   d_021D3FB0     0x021D3FB0  data  ov021  a1
 *   d_021D3FA8     0x021D3FA8  data  ov021  a1
 *   d_021D3FA0     0x021D3FA0  data   a1
 *   d_021D3F8C     0x021D3F8C  data   a1
 *   d_021D3F94     0x021D3F94  data   a1
 */
#include "../../matched/include/Obj03576.h"
#include "../../matched/include/Obj07438.h"
#include "../../matched/include/Obj17939.h"
#include "../../matched/include/Obj07440.h"
#include "../../matched/include/Obj19614.h"
#include "../../matched/include/Obj17940.h"
#include "../../matched/include/Obj19617.h"
#include "../../matched/include/Obj00485.h"
#include "../../matched/include/Obj04214.h"
#include "../../matched/include/Obj19618.h"
#include "../../matched/include/Obj07441.h"
#include "../../matched/include/Obj12617.h"
#include "../../matched/include/Obj07444.h"
#include "../../matched/include/Obj07446.h"
#include "../../matched/include/Obj09482.h"
#include "../../matched/include/Obj07448.h"
#include "../../matched/include/Obj12622.h"
#include "../../matched/include/Obj05859.h"
#include "../../matched/include/Obj19625.h"
#include "../../matched/include/Obj19627.h"
#include "../../matched/include/Obj19628.h"
#include "../../matched/include/Obj02693.h"
#include "../../matched/include/Obj07451.h"
#include "../../matched/include/Obj01351.h"
#include "../../matched/include/Obj09485.h"
#include "../../matched/include/Obj02376.h"
#include "../../matched/include/Obj09486.h"
#include "../../matched/include/Obj17941.h"
#include "../../matched/include/Obj02343.h"
#include "../../matched/include/Obj17942.h"
#include "../../matched/include/Obj01492.h"
#include "../../matched/include/Obj03114.h"
#include "../../matched/include/Obj04217.h"
#include "../../matched/include/Obj12071.h"
#include "../../matched/include/Obj01493.h"
#include "../../matched/include/Obj02377.h"
#include "../../matched/include/Obj17945.h"
#include "../../matched/include/Obj17946.h"
#include "../../matched/include/Obj07453.h"
#include "../../matched/include/Obj07454.h"
#include "../../matched/include/Obj01494.h"
#include "../../matched/include/Obj07457.h"
#include "../../matched/include/Obj07458.h"
#include "../../matched/include/Obj07211.h"
#include "../../matched/include/Obj05860.h"
#include "../../matched/include/Obj04218.h"
#include "../../matched/include/Obj12626.h"
#include "../../matched/include/Obj04219.h"
#include "../../matched/include/Obj09176.h"
#include "../../matched/include/Obj12628.h"
#include "../../matched/include/Obj00094.h"
#include "../../matched/include/Obj03578.h"
#include "../../matched/include/Obj00150.h"
#include "../../matched/include/Obj12630.h"
#include "../../matched/include/Obj00093.h"
#include "../../matched/include/Obj12631.h"
#include "../../matched/include/Obj05988.h"
#include "../../matched/include/Obj09492.h"
#include "../../matched/include/Obj03115.h"
#include "../../matched/include/Obj19634.h"
#include "../../matched/include/Obj12632.h"
#include "../../matched/include/Obj19635.h"
#include "../../matched/include/Obj09493.h"
#include "../../matched/include/Obj09494.h"
#include "../../matched/include/Obj17948.h"
#include "../../matched/include/Obj07463.h"
#include "../../matched/include/Obj12633.h"
#include "../../matched/include/Obj19636.h"
#include "../../matched/include/Obj05003.h"
#include "../../matched/include/Obj17949.h"
#include "../../matched/include/Obj04220.h"

#define reg_G3_MTX_PUSH        (*(volatile u32 *)0x04000444)
#define reg_G3_MTX_POP         (*(volatile u32 *)0x04000448)
#define reg_G3_MTX_SCALE       (*(volatile u32 *)0x0400046C)
#define reg_G3_MTX_TRANS       (*(volatile u32 *)0x04000470)
#define reg_G3_COLOR           (*(volatile u32 *)0x04000480)
#define reg_G3_TEXCOORD        (*(volatile u32 *)0x04000488)
#define reg_G3_VTX_16          (*(volatile u32 *)0x0400048C)
#define reg_G3_POLYGON_ATTR    (*(volatile u32 *)0x040004A4)
#define reg_G3_TEXIMAGE_PARAM  (*(volatile u32 *)0x040004A8)
#define reg_G3_TEXPLTT_BASE    (*(volatile u32 *)0x040004AC)
#define reg_G3_DIF_AMB         (*(volatile u32 *)0x040004C0)
#define reg_G3_SPE_EMI         (*(volatile u32 *)0x040004C4)
#define reg_G3_BEGIN_VTXS      (*(volatile u32 *)0x04000500)
#define reg_G3_END_VTXS        (*(volatile u32 *)0x04000504)
struct S;
struct X;
struct E50;
struct V_02193628;
struct ArcFile;
struct State;
struct Sub0200852CObj;
struct WordSet;
struct Actor;
struct VecFx32;
struct Desc;
struct Obj_02194A00;
struct BigObj;
struct Tcbl;
struct S02031140;
struct Rec3;
struct FrameStyle;
struct Descriptor;
struct CharBuf;
struct Owner;
struct Sprite;
struct Light;
struct Cfg;
struct BgTemplate;
struct Chan02021FD8;
struct PalAnmSlot;
struct MsgBank;
struct StrObj;
struct GfFont;
struct U16Vec;
struct Cb;
struct Rec;
struct Ctx;
struct Comm;
struct Sub02008700Obj;
struct Cmd;
struct Obj_021968DC;
struct Obj_02196F44;
struct Obj_0219707C;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef int fx32_02193628;

typedef long long s64;

typedef struct Vec {
    fx32_02193628 x;
    fx32_02193628 y;
    fx32_02193628 z;
} Vec;

typedef struct Tile {
    s16 n0[3];
    s16 n1[3];
    fx32_02193628 d0;
    fx32_02193628 d1;
    u32 attr : 31;
    u32 flag : 1;
} Tile;

typedef struct Plane {
    s16 x;
    s16 y;
    s16 z;
    s16 pad;
    u32 attr;
    fx32_02193628 height;
    int w[0x3C];
    int valid;
} Plane;

typedef signed char s8;

typedef struct { u8 a; u8 b; u16 c; } Cell_02193FE8;

typedef struct { u8 lo:4; u8 hi:4; u8 b; u16 c; } Cell_02193924;

typedef struct { u16 a; u16 b; u32 c; } Ent_021939C0;

typedef struct E50 {
    u16 f00;
    u16 f02;
    u8  f04[0x30];
    u8  f34[0x18];
    u16 f4c;
    u16 f4e;
} E50;

typedef struct E18 {
    u8 b[0x18];
} E18;

typedef struct Tbl_02193628 {
    u8  hdr[8];
    E18 e[10];
} Tbl_02193628;

typedef struct V_02193628 {
    u8   f00;
    u8   f01;
    u8   pad02[2];
    E50 *f04;
    Tbl_02193628 *f08;
} V_02193628;

typedef struct X {
    u32 f00;
    void *f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    void *f14;
    u8  pad18[0x100];
    u32 f118;
} X;

typedef struct { u8 a; u8 b; u8 rest[0x16]; } E18_02193D30;

typedef struct { u16 h0; u16 h1; u32 w4; E18_02193D30 A[10]; E18_02193D30 B[10]; } Src;

typedef struct { u8 lo : 4; u8 hi : 4; u8 b; } P;

typedef struct { P k; u16 c; } Cell_02194014;

typedef unsigned long long u64;

typedef struct { u32 x0; u32 x4; E18_02193D30 items[10]; } In;

typedef struct {
    u64 seed;
    u64 mul;
    u64 add;
    u16 x18;
    u16 x1a;
    u32 x1c;
    u32 x20;
} Out;

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext32;

typedef struct {
    P cells[8][8];
    u32 vals[1][16];
} T_02194128;

typedef struct {
    MATHRandContext32 rand;
    u16 max;
    u16 base;
    int f1c;
    u32 seed;
} E;

typedef struct { u32 key; u32 x4; u32 x8; } Item_021942C8;

typedef struct { u16 n; u16 pad; u32 x4; Item_021942C8 *items; } List_021942C8;

typedef struct Rec {
    u32 key;
    u32 f4;
    u32 val;
} Rec;

typedef struct Tbl_021943EC {
    u16 n;
    u16 pad;
    u32 f4;
    Rec *recs;
} Tbl_021943EC;

typedef struct { unsigned w[9]; } T_02194434;

typedef struct { unsigned w[6]; } T24;

typedef struct { u16 kind; u8 f2; u8 rest[97]; } Ent_02194354;

typedef struct { u8 pad[0x18]; Ent_02194354 ents[32]; } Top;

typedef struct {
    u32 f0;
    u32 f4;
    u8  f8;
    u8  f9;
    u8  fa;
    u8  fb;
    u16 fc;
    u16 fe;
    u32 f10;
} Cfg;

typedef struct { u8 pad[0x10]; u32 x10; u8 x14; u8 x15; } Obj_02194A00;

typedef struct V3 { int x, y, z; } V3;

typedef signed int s32;

typedef s16 fx16;

typedef s32 fx32_02194AC8;

typedef struct { fx32_02194AC8 x, y, z; } VecFx32;

typedef struct { fx16 x, y, z; } VecFx16;

typedef struct Sprite {
    char pad00[0x18];
    u16 color;          /* 0x18 */
    u16 pad1a;
    struct Quad {
        VecFx32 trans;  /* 0x1C */
        fx32_02194AC8 scale;     /* 0x28 */
        VecFx16 v[7];   /* 0x2C */
        int tri;        /* 0x58 */
    } q;
    char pad5c[2];
    u16 rate;           /* 0x5E */
} Sprite;

typedef struct Owner {
    char pad[0xCC8];
    u32 texKey;         /* 0xCC8 */
    u32 plttKey;        /* 0xCCC */
} Owner;

struct FrameStyle {
    char pad_00[0x0C];
    u16 baseTile;
    char pad_0E[0x02];
    u32 bgLayer;
    u8 palette;
};

typedef struct { u8 x0; u8 x1; u8 x2; u8 x3; u32 x4; u32 x8; u32 xc; } Obj_02195E70;

typedef struct { int w[8]; } B32;

typedef struct { u32 x0; u32 x4; u32 x8; u32 xc; } Desc;

typedef struct Obj_0219630C {
    u8 pad0[0x10];
    u16 x10;
    u16 pad12;
    u32 w[4];
    u32 x24;
    u32 x28;
    u32 x2c;
    u8 pad30[8];
    u32 x38;
    u8 pad3c[0x2B8];
    int x2f4;
} Obj_0219630C;

typedef struct Cb { u32 x0; int (*fn)(void *, struct Cb *); } Cb;

typedef struct { u32 w[4]; } Blk;

typedef struct Obj_021968DC { u32 x0; u32 x4; u32 x8; u32 xc; u8 pad[0x284]; void *objs[27]; u32 mode; } Obj_021968DC;

typedef struct { u16 x0; Obj_021968DC *a; void (*cb)(); } Req_021968DC;

struct Rec8 { u32 a; u32 b; };

struct Rec16 { u32 a; u32 b; u32 c; u32 d; };

typedef struct { u8 v[3]; } Tbl3;

typedef struct { u8 pad[0x294]; void *arr[5]; } Obj_02196F44;

typedef struct { u8 v[5]; } B5;

typedef struct { u16 x; u16 y; u16 z; u8 a; u8 b; } Pos;

typedef struct { u16 a, b, c; u8 d, e; } Rect;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int arr[3];
} Sub;

typedef struct {
    u8 pad0[0x10];
    u16 f10;
    u8 pad12[0x26C - 0x12];
    Sub sub;
} Obj_0219707C;

extern int func_02169520(int a0, int a1);
extern void func_0216959C(u8 *p);
extern void func_02169530(unsigned char *a, int *out);
extern void func_021695BC(struct S *p, int b);
extern int func_02169620(struct S *p);
extern void func_02169528(unsigned char *a, int *out);
extern void func_02169540(unsigned char *a, unsigned int v);
extern int func_02169580(int a0);
extern int func_02169560(unsigned char *a);
extern int func_02169578(unsigned char *a);
extern unsigned int func_02169598(u8 *p);
extern int func_0218DD04(u8 *p);
extern int func_0218DD08(u8 *p);
extern int func_0218DD0C(u8 *p);
extern u16 func_0218DD10(u8 *p);
extern int func_0218B974(int a, int o, void *p, int n);
extern int func_0218DCF4(unsigned int *a0);
extern int func_0218DCFC(unsigned int *a0);
extern int func_021A7410(u32 a, u32 b, u32 c, u32 d);
extern u32 func_0207C768(u32 a, u32 b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_0216D974(unsigned int *p, unsigned int v);
extern u32 *func_021C939C(u32 a, u32 heap);
extern void func_021C93E4(u32 a, u8 *q, u32 x, u32 y, u32 z, u32 w, u32 n, u32 cnt);
extern u32 func_021C9450(u32 a, u32 b, u32 c, u32 d, int e, int f);
extern void func_021C93D0(void **q);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern Ent_021939C0 *func_02049250(int h, int a, u16 heap);
extern void func_0216245C(u8 *o, u16 idx);
extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_0218E17C(u32 *p, u32 v);
extern void func_02186748(struct State *p);
extern void *func_0200846C(int a0);
extern void func_020084A0(struct Sub0200852CObj *);
extern u32 func_020084D4(u32 value, void *dst);
extern void func_0200852C(struct Sub0200852CObj *obj, u32 value);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_02186764(u8 *);
extern int func_02186770(u8 *);
extern int *func_021867C4(int a, int id);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_02186830(int, int, int);
extern void func_0218683C(void *p);
extern void func_02049238(void *a);
extern void func_02186804(void **p);
extern u32 func_02082BCC(void *p, int v, int n);
extern int func_0218625C(unsigned short *p);
extern int func_02161ECC(E18_02193D30 *p);
extern void func_02186818(u32 *p, u32 member);
extern u8 *func_02186844(u8 *t, int i);
extern char *func_0218682C(char *p);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
extern void func_0218609C(char *p);
extern void func_021860B8(char *p);
extern int func_021867B0(u8 *p);
extern void func_02082D44(void *src, void *dst, int n);
extern int func_02186278(char *p, int which);
extern int func_0216D854(void *p);
extern int func_02163C04(int a, int x, int y, int flag);
extern int func_0216CF2C(int a0, int a1);
extern void *func_0216CE60(void *a, void *b, int c);
extern void func_0216E014(void *a, int *p, int b);
extern int func_0216DB4C(void *a0, int a1);
extern int func_0216DC98(void *a0, int a1);
extern void func_0216DB80(unsigned int *p, unsigned int v);
extern void func_0216DAE0(unsigned int *p, unsigned int v);
extern int func_0216DC64(void *a0, int a1);
extern int func_0216DCCC(void *a0, int a1);
void *func_0216D684(int a0, int a1);
extern void *func_0216D69C(void *p);
extern void func_0216D5E0(int a0, int a1);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern u16 func_0216D5F8(void *p);
extern u16 func_0216D598(void *p);
extern void func_0216D674(void *a, int v);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
extern u32 func_02188CCC(u8 *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj_02194A00 *p);
extern int func_021A0ED4(u32 a);
extern void *func_02188C7C(u8 *p);
extern void *func_020124E4(struct Obj_02194A00 *p);
extern u32 func_020120F4(void);
extern void func_0216D9A0(void *a);
extern void func_020129D0(struct BigObj *p, u8 v);
extern int func_021A0F30(u32 a, u32 b);
extern void func_020129B8(struct BigObj *p, u32 v);
extern u32 *func_0216D9E4(void *c);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_020310C4(struct Tcbl *p);
extern void func_0206DB80(void);
extern void func_02031140(struct S02031140 *p);
extern u32 func_0206DF3C();
extern void func_0201CE48(struct Rec3 *p);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern u32 func_020409B4(u32);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *a);
extern u32 func_0206E0C4(u32, u32, u32, u32);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045748(struct Descriptor *p);
extern u8 func_02045750(struct Descriptor *p);
extern u8 func_02045730(struct Descriptor *p);
extern u32 func_02040804(u32 layer);
extern void func_0207CA00(const V3 *a, const V3 *b, V3 *c);
extern int func_0207CBD0(V3 *a);
extern u32 func_02048AFC();
extern u32 func_02048B20();
extern u32 func_02048B44();
extern void func_02048B60(struct Light *l, const u32 *in);
extern u32 func_02048AD0();
extern void func_0207D7C4(V3 *a, V3 *b, V3 *c, int d, int e);
extern u32 func_02048AE8(u32, u32, u32, u32);
extern u32 func_02048B0C(u32, u32);
extern u32 func_02048B30(u32, u32);
extern u32 func_02048B54(u32, u32);
extern void func_020414EC(u32 a);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
extern void func_0207F7A0();
extern void DC_FlushRange(void *p, u32 size);
extern void func_0207F7FC(void *p, u32 off, u32 size);
extern void func_0207F9B4();
extern void func_0207FA0C();
extern void func_0207FA40(void *p, u32 off, u32 size);
extern void func_0207FADC();
extern void func_02045374(struct Cfg *cfg);
extern void func_02041300(u8 layer, u16 tile, u8 x, u8 y, u8 w, u8 h, u8 mode);
extern void func_020456F8(struct Descriptor *d);
extern void func_0203FCA0(unsigned int bgId, const struct BgTemplate *tmpl, unsigned int type);
extern void func_020414AC(int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int func_02021730(char *p, int i);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern void func_0207E5D0(void *p, u32 a, u32 size);
extern void func_0207E468(void *p, u32 a, u32 size);
extern void func_0202F038(u8 *p);
extern u8 *func_0202EE8C(u32 a, void *b, u8 c, u8 d, u16 e);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 func_02041B6C(u32);
extern void func_0201DD78(u32, u32, u32);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02051C6C(void *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern void *func_02051B84(u8 *a0, int a1, int a2, int a3);
extern void func_0201DD68(void);
extern void func_02040DA8(u32 a, u32 b, u32 c);
extern void func_0203FB44(u32 a, u32 b, u32 c);
extern void func_020403F4(u32 a);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020221A4();
extern u32 func_02155A90(u8 *p);
extern u32 func_02012138(const struct Ctx *p);
extern u32 func_02026454(void *obj);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_02026400(struct Comm *p);
extern u32 func_02155A94(u8 *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern int func_02008428(unsigned short *p);
extern void func_02197700(u8 *a);
extern void func_0204B92C(struct Obj_021968DC *p, u32 v);
extern void func_0204BA00(struct Actor *a, const struct Cmd *cmd);
extern void func_0204B9A0(struct Actor *a);
extern int func_021975D0(u8 *p);
extern int func_02035C60(void);
extern void func_020061E4(u32 a);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA1C(void *p);
extern void func_02197644(u8 *p, u32 b);
extern s32 func_02051C88(struct Ctx *c);
extern void *func_0200BAC8(void *p);
extern u32 func_0200BBA8(void *a);
extern void func_0219728C(u8 *p);
extern void func_021973A0(u8 *p);
extern s32 func_0204A6C8(void *h, u32 b, u32 c, u32 d, u16 e);
extern s32 func_0204AC18(void *h, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *h, u32 b, u32 c, u32 d);
extern void func_0204B3B4(struct Obj_02196F44 *p);
extern struct Obj_0219707C *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void func_0204B3DC(struct Obj_0219707C *obj, unsigned int on);
extern void func_0204B688(struct Actor *actor, u32 value);
int func_02193628(u8 *o, unsigned int *q);
void func_02193790(Plane *out, const int *map, Vec *pos, fx32_02193628 size, fx32_02193628 base);
void *func_021938AC(u32 heap);
u32 func_021938D4(void *a);
int func_021938F4(unsigned char *p);
;
void *func_0219390C(void *a, u32 b);
u8 func_0219391C(u8 *p);
u8 func_02193920(u8 *p);
int func_02193924(u8 *a, void *q, int c, int d, int e, int f, int g, u16 h);
void func_021939C0(u8 *o, void *dst, int skip, u32 heap);
void func_02193ABC(char *p, int a, int b);
void func_02193AFC(u8 *p, u32 v);
void func_02193B04(u32 a, u32 b, u32 c, u32 d);
void func_02193B20(u32 a, u32 b);
void func_02193B40(V_02193628 *v, u32 key);
void func_02193B68(void *a, int b, int c, int d, u16 e);
void func_02193BC4(void *a, u32 b);
int func_02193BE4(void *a, u32 b);
char *func_02193C00(char *p);
void *func_02193C04(u8 *p);
void func_02193C08(char *p, int heap);
void func_02193C80(X *x);
void func_02193CBC(unsigned char *p);
int func_02193D08(unsigned char *p);
void func_02193D30(u8 *o, Src *s, int which);
void func_02193E54(unsigned char *p, unsigned char *q);
void func_02193EB4(V_02193628 *v);
void func_02193EE8(V_02193628 *v);
E50 *func_02193EFC(V_02193628 *v, u32 key);
E50 *func_02193F34(V_02193628 *v, u32 key);
void func_02193F6C(E50 *e);
void func_02193F80(E50 *e, void *a, u8 *b, void *c);
void func_02193FBC(u16 *a, void *b);
void func_02193FD4(u16 *a, void *b);
void func_02193FE8(Cell_02193FE8 (*t)[8]);
void func_02194014(Cell_02194014 (*t)[8], int j, int i, P e, u16 c);
Cell_02193924 func_02194038(void *a, int b, int c);
int func_02194044(Cell_02193FE8 (*t)[8], u16 b, u16 c);
void func_02194078(void *a);
void func_02194084(Out *o, In *in, u32 c);
void func_02194128(E *e, T_02194128 *tbl, u8 *out);
void *func_02194284(int a, void *b, int heap, int c);
void func_021942C8(List_021942C8 *p);
void func_02194300(u16 *a, int b, int c, u16 *d, int e, int f);
void func_02194354(List_021942C8 *p, u32 key);
int func_02194384(u16 *a, s16 b, int c, s16 d, int *e, unsigned *f);
u32 func_021943EC(Tbl_021943EC *t, u32 key);
int func_02194418(void *a, int a1);
void *func_02194434(unsigned char *a, int x, u16 *q, int d, int e, int f);
void *func_021944BC(int a);
void func_021944C8(u32 a);
void func_021944D8(void *a);
void func_02194588(u32 a, u32 b, u32 c, u32 d, u32 e);
int func_021945A0(int x);
void *func_021945A4(void *a, u32 b, u32 c);
int func_021945E0(void *a, int b, u8 *c);
void *func_02194670(u16 *a);
void func_02194704(char *a0);
void func_0219470C(unsigned char *a);
void func_02194760(u32 a);
void func_02194764(Top *a);
void func_02194798(unsigned char *a);
void func_021947E8(u8 *p, int i, u32 a, u8 b, u8 c, u8 d, u8 f, u32 g, u32 h, u32 k, u8 m, u8 n);
void func_02194848(u8 *p, int i, u32 a, u32 b, u32 u, u32 v, u32 w, u32 x);
void func_02194888(u8 *p, int i, u32 a, u32 b, u32 u, u32 v, u32 w, u32 x);
void func_021948CC(u8 *p, int i, u32 a, u32 b, u8 u, u32 v, u32 x);
void func_0219492C(u8 *p, int i);
void func_02194940(u8 *p, int i);
void func_02194950(u8 *p, int i);
u32 func_02194960(u32 a, u32 b, u32 c, u32 a3);
int func_02194974(u8 *p, int i);
u32 func_02194984(u32 a, u32 b);
u32 func_02194990(u32 a, u32 b);
void func_0219499C(u8 *p, int i, u32 b, u32 c);
u32 func_02194A00(u32 a, u8 b, u8 c, u8 d, u8 e, u32 f);
int func_02194A24(u32 a, u32 b, u32 c, u32 d);
int func_02194A34(u32 a, u32 b);
u32 func_02194A48(u32 a, struct Descriptor *b);
int func_02194A58(u32 a);
int func_02194A74(u32 a);
int func_02194A84(u16 *p, int i);
u32 func_02194A94(Obj_02194A00 *a, u8 b, u8 c, int d, u8 e);
void func_02194AC8(u8 *p, u8 *e, u32 a, u32 b, u8 *s);
void func_02194B3C(u8 *p, u8 *e);
void func_02194B70(u16 *p, int i);
void func_02194B78(u8 *p, int i);
void func_02194B84(u8 *p, u8 *e);
void func_02194C60(u8 *p, u8 *e);
void func_02194CE8(int a, u16 *b);
void func_02194D1C(Owner *a, Sprite *b, int c);
int func_02194E74(u32 a, u32 b, u32 c, u32 d);
void func_02194E90(u8 *e, u8 *ent, int *b, int *c, void *d);
void func_02194F5C(int x, int w, int side, u16 *a, u16 *b);
int func_02194F84(u8 *e, int b, int c, void *d, void *f);
void func_02195128(u8 *p, u32 c0, u32 c1, u32 c2, u32 c3);
void func_0219518C(u8 *p, u8 *e, const V3 *a, V3 *b, V3 *c, V3 *d, V3 *f, V3 *g, V3 *h);
u32 func_02195338(u8 *p, u8 *e);
void func_021953D4(u8 *p, int m);
int func_0219545C(u32 a, u32 b, u32 c, u32 d);
int func_02195490(u32 a, u32 b, u32 c, u32 d);
u32 func_021954CC(u32 p, u8 *e);
void func_02195530(char *p);
void func_02195588(u8 *p);
void func_021955EC(struct FrameStyle *style, void *win, int deco);
void func_02195938(struct FrameStyle *style, void *win, int deco);
u32 func_02195E54(u32 a, u32 b, u8 c, u32 d);
void func_02195E70(u32 a, Obj_02195E70 *b);
int func_02195E80(u32 a, u32 b);
void func_02195E90(struct FrameStyle *style, void *win);
void func_02196030(u32 *p, u32 v);
void func_02196034(void *p, void *fn, u32 n);
void func_0219603C(void *a0);
void func_021961A4(u8 *p, u32 a, u32 b);
void func_02196228(u8 *p, int flag);
void func_02196290(u8 *a);
int func_021962C4(u32 a);
void func_021962F4(u8 *a);
void func_0219630C(int n, u32 *msg, Obj_0219630C *a, Desc *d, int *xs, int *ys);
void func_02196454(u8 *p);
void func_0219649C(void *a, int b, Cb *c);
void func_021964B0(u16 (*dst)[16], u16 *add, int n);
void func_02196538(u8 *p);
void func_021966B0(u8 *p, u32 a);
void func_021966F0(u8 *p);
void func_02196768(u8 *p);
void func_021967BC(u8 *p);
void func_02196804(u8 *p);
void func_0219686C(u8 *p);
void func_021968D8(void);
void func_021968DC(Obj_021968DC *a);
void func_02196944(u8 *a);
int func_02196974(u32 s, u8 *p);
void func_02196A4C(u8 *a);
void func_02196A60(u8 *p);
void func_02196ACC(u8 *p);
void func_02196B24(void);
void func_02196B28(Obj_021968DC *a);
void func_02196B7C(u8 *p);
void func_02196B90(void);
void func_02196B94(Obj_021968DC *a);
int func_02196BF8(u32 v, u8 *p);
void func_02196C68(u8 *p);
void func_02196CD8(u8 *p);
void func_02196D20(void);
void func_02196D24(Obj_021968DC *a);
void func_02196D88(u8 *p);
int func_02196D94(u32 v, u8 *p);
void func_02196E04(u8 *p);
void func_02196E70(u8 *p);
void func_02196EC8(void);
void func_02196ECC(Obj_021968DC *a);
int func_02196F44(u32 v, u8 *p);
void func_02196FF0(u8 *p);
void func_02196FFC(u8 *p);
void func_02197058(Obj_02196F44 *a);
void func_0219707C(u8 *p);
void func_02197190(Obj_0219707C *p);
extern char d_021DDA60[];
extern int d_021D3F60[];
extern int d_021D3F58[];
extern int d_021DDA70;
extern T_02194434 d_021D3F68;
extern int d_021DDAC4;
extern u32 d_021DDA84[];
extern u32 d_021DDAA4[];
extern const B32 d_021D40A0;
extern const B32 d_021D40C0;
extern const B32 d_021D40E0;
extern const B32 d_021D4100;
extern const B32 d_021D4120;
extern const B32 d_021D4140;
extern const u16 d_021DDAD4[];
extern Blk d_021D4070;
extern int d_021D4014[];
extern int d_021D4024[];
extern u8 d_021D404C[];
extern Desc d_021DDB84[];
extern struct Rec8 d_021D3FE0;
extern u8 d_021D3FF4[];
extern Desc d_021DDAF4[];
extern struct Rec16 d_021D4080;
extern u8 d_021D4034[];
extern Desc d_021DDB44[];
extern const Tbl3 d_021D3F9C;
extern struct Rec8 d_021D3FD8;
extern u8 d_021D4004[];
extern B5 d_021D3FC8;
extern B5 d_021D3FB0;
extern B5 d_021D3FA8;
extern const Tbl3 d_021D3FA0;
extern const Tbl3 d_021D3F8C;
extern const Tbl3 d_021D3F94;

;


;



;




;





;






;







;








;









;










;











;



















/*
 * Addresses are Black-image addresses.
 */
int func_02193628(u8 *o, unsigned int *q)
{
    u16 *st;
    int x;
    char *h;
    int boff;
    char *base;
    int j;
    int y0;
    int g;
    int id;
    u16 c;
    char *p;
    int off;
    int r;
    int n;
    int i;
    int x0;

    func_0218DD10((u8 *)q);
    func_02169520((int)o, (int)(&st));
    switch (*st) {
    case 1:
        func_0216959C((u8 *)o);
        func_02169530((unsigned char *)o, &x);
        func_021695BC((struct S *)o, x);
        *st = 2;
        break;
    case 2:
        if (func_02169620((struct S *)o) != 0)
            break;
        ((struct Obj03576 *)st)->f18 = 1;
        ((struct Obj03576 *)st)->f1C = 1;
        ((struct Obj03576 *)st)->f20 = 1;
        *st = 3;
        break;
    case 3:
        func_02169528((unsigned char *)o, (int *)(&h));
        p = h;
        func_02169540((unsigned char *)o, (unsigned int)(p + ((struct Obj07438 *)p)->f4));
        off = ((struct Obj07438 *)p)->fC;
        if (off != ((struct Obj07438 *)p)->f10)
            r = func_0218B974(func_0218DD04((u8 *)q), (int)o, h + off + 4, *(int *)(h + off));
        g = func_0218DD04((u8 *)q);
        base = h;
        boff = ((struct Obj07438 *)p)->f8;
        n = func_0218DD0C((u8 *)q);
        id = func_0218DD08((u8 *)q);
        c = func_0218DD10((u8 *)q);
        x0 = (n % 2) * 4;
        y0 = (n / 2) * 4;
        for (j = 0; j < 4; j++) {
            for (i = 0; i < 4; i++) {
                r = func_02193924((u8 *)id, base + boff, g, (int)o, r, x0 + i, y0 + j, c);
            }
        }
        func_02169580((int)o);
        if (func_0218DCF4(q))
            func_021A7410(func_0218DCFC((unsigned int *)q), func_02169560((unsigned char *)o), func_02169578((unsigned char *)o), func_02169598(o));
        *st = 4;
        break;
    case 4:
        *st = 0;
        return 0;
    }
    return 1;
}



















static inline fx32_02193628 FX_MUL(fx32_02193628 a, fx32_02193628 b)
{
    return (fx32_02193628)(((s64)a * b + 0x800LL) >> 12);
}



















static inline void VecSet(Plane *p, int x, int y, int z)
{
    p->x = x;
    p->y = y;
    p->z = z;
}



















void func_02193790(Plane *out, const int *map, Vec *pos, fx32_02193628 size, fx32_02193628 base)
{
    fx32_02193628 half = size / 2;
    fx32_02193628 z = pos->z + half;
    fx32_02193628 x = pos->x + half;
    int lx = x % 0x10000;
    int lz = z % 0x10000;
    Tile *t = (Tile *)((char *)map + map[2] + 4) + (x / 0x10000 + ((size >> 12) / 16) * (z / 0x10000));
    fx32_02193628 d;

    if (t->flag == 0) {
        if (lx + lz < 0x10000) {
            VecSet(out, t->n0[0], t->n0[1], -t->n0[2]);
            d = t->d0;
        } else {
            VecSet(out, t->n1[0], t->n1[1], -t->n1[2]);
            d = t->d1;
        }
    } else {
        if (lx > lz) {
            VecSet(out, t->n0[0], t->n0[1], -t->n0[2]);
            d = t->d0;
        } else {
            VecSet(out, t->n1[0], t->n1[1], -t->n1[2]);
            d = t->d1;
        }
    }
    {
        fx32_02193628 ny = out->y;
        fx32_02193628 mz = FX_MUL(out->z, pos->z);
        fx32_02193628 mx = FX_MUL(out->x, pos->x);
        out->attr = t->attr;
        out->height = base + func_0207C768(-(d + (mx + mz)), ny);
    }
    out->valid = 1;
}



















void *func_021938AC(u32 heap)
{
    void *o = func_02030734(heap, 0x144, 1, d_021DDA60, 0x12A);
    func_02193CBC(o);
    return o;
}



















/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021938D4(void *a)
{
func_02193C80((X *)((struct X *)a));
if (*(u32 *)((u8 *)(a) + ((5 << 6))) != 0) {
    func_0216D974((unsigned int *)(*(u32 *)((u8 *)(a) + ((5 << 6)))), 1);
}
return func_020307B0(a);
}



















/*
 * Unblocked by matching the leaf at 0x02193D08 in ov021; the tail-call site
 * now resolves via `matched`.
 */
int func_021938F4(unsigned char *p)
{
    return func_02193D08(p);
}



















/*
 * Tail-call thunk: forwards to func_02193E54 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021938FC(v, a1)
void *v;












unsigned char *a1;












{
    func_02193E54(v, a1);
}







/*
 * Unlabelled leaf (saves nothing, so disasm.py prints it as .word data);
 * filed as the blocker of func_02186D48 (ov020).
 */
void func_02193904(void *p)
{
    func_02193EB4((V_02193628 *)p);
}



















void *func_0219390C(void *a, u32 b)
{
if (b < 30) {
    return func_02193F34((struct V_02193628 *)a, b);
}
return 0;
}



















u8 func_0219391C(u8 *p)
{
    return *p;
}



















/*
 * Loads the byte at +0x1 of the object.
 */
u8 func_02193920(u8 *p)
{
    return ((struct Obj17939 *)p)->f1;
}



















/*
 * The cell comes back from func_02194038 as a 4-byte struct in r0; the high
 * nibble is read before the low one.
 * Addresses are Black-image addresses.
 */
int func_02193924(u8 *a, void *q, int c, int d, int e, int f, int g, u16 h)
{
    Cell_02193924 cell = func_02194038(a + 0x18, f, g);
    u32 *t;
    int x, y;
    int lo, hi;

    if (cell.b != 0xFF) {
        x = (f * 8) & 0x1F;
        y = (g * 8) & 0x1F;
        t = func_021C939C(cell.c, (u16)((h & 0x7FFF) | 0x8000));
        hi = cell.hi;
        lo = cell.lo;
        func_021C93E4((u32)t, q, lo * 8, hi * 8, x, y, 8, 8);
        if (lo == 0 && hi == 0) {
            e = func_021C9450((u32)t, c, d, e, x, y);
        }
        func_021C93D0((void **)t);
    }
    return e;
}



















void func_021939C0(u8 *o, void *dst, int skip, u32 heap)
{
    u32 n;
    Ent_021939C0 *e;
    u32 *seen;
    u32 cnt;
    u32 i;
    u32 j;
    Ent_021939C0 *cur;

    if (skip != 0)
        return;
    n = func_020493D4((struct ArcFile *)(((struct Obj07440 *)o)->f10), d_021D3F60[*o]);
    heap = (heap & 0x7FFF) | 0x8000;
    e = func_02049250(((struct Obj07440 *)o)->f10, d_021D3F60[*o], (u16)heap);
    n >>= 3;
    seen = func_02030734((u16)heap, n * 4, 1, (const char *)&d_021DDA60, 0x208);
    cnt = 0;
    for (i = 0; i < n; i++) {
        cur = &e[i];
        if (func_02194044((Cell_02193FE8 (*)[8])(o + 0x18), e[i].a, cur->b)) {
            seen[cnt] = cur->c;
            cnt++;
        } else {
            for (j = 0; j < cnt; j++) {
                if (seen[j] == e[i].c)
                    break;
            }
            if (j >= cnt) {
                for (j = i + 1; j < n; j++) {
                    if (cur->c == e[j].c)
                        break;
                }
                if (j >= n)
                    func_0216245C(dst, (u16)cur->c);
            }
        }
    }
    func_020307B0(seen);
    func_020307B0(e);
}



















void func_02193ABC(char *p, int a, int b)
{
    u16 *h;

    h = func_0204A380((void *)(((struct Obj19614 *)p)->f10), 0x24, 0, (u16)((b & 0x7fff) | 0x8000));
    func_0218E17C((u32 *)a, h[func_021938F4((unsigned char *)p)]);
    func_020307B0(h);
}



















/*
 * Stores the 32-bit word into byte +0x140 of the object.
 */
void func_02193AFC(u8 *p, u32 v)
{
    ((struct Obj17940 *)p)->f140 = v;
}


















void func_02193B04(u32 a, u32 b, u32 c, u32 d)
{
func_02193C08((char *)a, d);
func_02193D30((u8 *)a, (Src *)b, c);
}


















void func_02193B20(u32 a, u32 b)
{
func_02193EB4((V_02193628 *)((struct V_02193628 *)a));
func_02193F6C((struct E50 *)func_02193EFC((V_02193628 *)((struct V_02193628 *)a), b));
func_02193EE8((V_02193628 *)a);
}
















void func_02193B40(V_02193628 *v, u32 key)
{
    E50 *e;

    func_02193EB4((V_02193628 *)v);
    e = (struct E50 *)func_02193EFC((V_02193628 *)((struct V_02193628 *)v), key);
    if (v->f01 == 0) {
        func_02186748((struct State *)e->f34);
        func_02193EE8((V_02193628 *)((u32)v));
    }
}
















void func_02193B68(void *a, int b, int c, int d, u16 e)
{
    char *q;
    int h;

    func_02193EB4((V_02193628 *)a);
    q = (char *)func_02193F34((struct V_02193628 *)a, c);
    h = (int)func_0200846C((u16)((e & 0x7fff) | 0x8000));
    func_020084A0((struct Sub0200852CObj *)h);
    func_020084D4(h, q + 0x38);
    func_0200852C((struct Sub0200852CObj *)h, ((struct Obj19617 *)q)->f48);
    func_0201F02C((struct WordSet *)b, d, (void *)h);
    func_020307B0((void *)h);
}
















/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_02186764 (0x02186764) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_02193BC4(void *a, u32 b)
{
func_02193EB4((V_02193628 *)a);
func_02186764(((u8 *)(struct E50 *)func_02193EFC((V_02193628 *)((struct V_02193628 *)a), b) + 52));
func_02193EE8((V_02193628 *)((u32)a));
}
















/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_02186770 (0x02186770) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02193BE4(void *a, u32 b)
{
func_02193EB4((V_02193628 *)a);
return func_02186770(((u8 *)func_02193F34((struct V_02193628 *)a, b) + 52));
}















char *func_02193C00(char *p)
{
    return p + 4;
}
















void *func_02193C04(u8 *p)
{
    return p + 0x34;
}
















void func_02193C08(char *p, int heap)
{
    int i;

    if (((struct Obj00485 *)p)->fC == 0) {
        i = 0;
        ((struct Obj00485 *)p)->fC = (int)func_021867C4(0, heap);
        ((struct Obj00485 *)p)->f4 = func_02030734(heap, 0x320, 1, (const char *)&d_021DDA60, 0x39e);
        for (i = 0; i < 10; i++) {
            func_02193F6C((struct E50 *)((char *)*(int *)&((struct Obj00485 *)p)->f4 + i * 0x50));
        }
        ((struct Obj00485 *)p)->f10 = func_020490F4(0x9a, heap);
        ((struct Obj00485 *)p)->f14 = func_02030734(heap, 0x600, 1, (const char *)&d_021DDA60, 0x3ab);
        *(int *)&((struct Obj00485 *)p)->f118 = func_02186830(((struct Obj00485 *)p)->fC, ((struct Obj00485 *)p)->f0, heap);
    }
}
















void func_02193C80(X *x)
{
    if (x->f0c != 0) {
        func_0218683C((void *)x->f118);
        func_020307B0(x->f14);
        func_02049238((void *)x->f10);
        func_02186804((void **)x->f0c);
        func_020307B0(x->f04);
        x->f0c = 0;
        x->f04 = 0;
        x->f10 = 0;
        x->f14 = 0;
        x->f118 = 0;
    }
}
















void func_02193CBC(unsigned char *p)
{
    int i;
    unsigned char *q = *(unsigned char * *)&((struct Obj04214 *)p)->f4;

    p[0] = 0;
    p[1] = 0;
    ((struct Obj04214 *)p)->f8 = 0;
    if (q != 0) {
        for (i = 0; i < 10; i++)
            func_02193F6C((struct E50 *)(*(unsigned char * *)&((struct Obj04214 *)p)->f4 + i * 0x50));
    }
    if (((struct Obj04214 *)p)->f14 != 0)
        func_02082BCC(((struct Obj04214 *)p)->f14, 0, 0x600);
    func_02193FE8((Cell_02193FE8 (*)[8])(p + 0x18));
    func_02194078(p + 0x11c);
}
















int func_02193D08(unsigned char *p)
{
    int count = 0;
    int i;
    unsigned char *q = *(unsigned char * *)&((struct Obj19618 *)p)->f4;

    if (q != 0) {
        for (i = 0; i < 10; i++) {
            if (*(unsigned short *)(q + i * 0x50) != 0)
                count++;
        }
    }
    return count;
}
















void func_02193D30(u8 *o, Src *s, int which)
{
    int i;
    int off;
    u8 *pair;

    func_0218625C((short unsigned int *)s);
    func_02193CBC(o);
    o[0] = s->h1;
    o[1] = which;
    for (i = 0; i < 10; i++) {
        if (which == 0) {
            off = i * 0x18;
            if (func_02161ECC((E18_02193D30 *)((u8 *)s->A + off))) {
                func_02186818((u32 *)(((struct Obj00485 *)o)->fC), s->A[i].b);
                func_02193F80((struct E50 *)(*(u8 * *)&((struct Obj00485 *)o)->f4 + i * 0x50), (E18_02193D30 *)((u8 *)s->A + off),
                              func_02186844(*(u8 * *)&((struct Obj00485 *)o)->f118, i),
                              (u16 *)func_0218682C((char *)(((struct Obj00485 *)o)->fC)));
            }
        } else {
            off = i * 0x18;
            if (func_02161ECC((E18_02193D30 *)((u8 *)s->B + off))) {
                func_02186818((u32 *)(((struct Obj00485 *)o)->fC), s->B[i].b);
                pair = func_02186844(*(u8 * *)&((struct Obj00485 *)o)->f118, i);
                func_0218682C((char *)(((struct Obj00485 *)o)->fC));
                func_02193F80((struct E50 *)(*(u8 * *)&((struct Obj00485 *)o)->f4 + i * 0x50), (E18_02193D30 *)((u8 *)s->B + off),
                              pair, (u16 *)func_0218682C((char *)(((struct Obj00485 *)o)->fC)));
            }
        }
    }
    func_02194084((Out *)(o + 0x11c), (In *)s, ((struct Obj00485 *)o)->fC);
    if (which == 0)
        *(Src * *)&((struct Obj00485 *)o)->f8 = s;
    else
        *(Src * *)&((struct Obj00485 *)o)->f8 = 0;
    func_020493D4((struct ArcFile *)(*(int *)&((struct Obj00485 *)o)->f10), d_021D3F58[o[0]]);
    func_0204932C((struct ArcFile *)(*(int *)&((struct Obj00485 *)o)->f10), d_021D3F58[o[0]], (void *)(*(int *)&((struct Obj00485 *)o)->f14));
    func_02194128((E *)(o + 0x11c), (T_02194128 *)*(int *)&((struct Obj00485 *)o)->f14, o + 0x18);
}
















void func_02193E54(unsigned char *p, unsigned char *q)
{
    int i;

    ((struct Obj12617 *)q)->f0 = 1;
    ((struct Obj12617 *)q)->f2 = p[0];
    if (p[1] == 0) {
        func_0218609C((char *)q);
        q += 8;
        for (i = 0; i < 10; i++)
            func_02193FD4((u16 *)(*(unsigned char * *)&((struct Obj07441 *)p)->f4 + i * 0x50), q + i * 0x18);
    } else {
        func_021860B8((char *)q);
        q += 0xf8;
        for (i = 0; i < 10; i++)
            func_02193FD4((u16 *)(*(unsigned char * *)&((struct Obj07441 *)p)->f4 + i * 0x50), q + i * 0x18);
    }
}
















void func_02193EB4(V_02193628 *v)
{
    int i;

    if (v->f01 == 0 && v->f08 != 0) {
        for (i = 0; i < 10; i++)
            func_02193FBC((u16 *)(&v->f04[i]), &v->f08->e[i]);
    }
}
















void func_02193EE8(V_02193628 *v)
{
    if (v->f01 == 0 && v->f08 != 0)
        func_021938FC(v);
}
















E50 *func_02193EFC(V_02193628 *v, u32 key)
{
    int i;

    if (v->f04 != 0) {
        for (i = 0; i < 10; i++) {
            if (v->f04[i].f00 != 0 && key == func_021867B0(v->f04[i].f34))
                return &v->f04[i];
        }
    }
    return 0;
}















/*
 * Addresses are Black-image addresses.
 */
E50 *func_02193F34(V_02193628 *v, u32 key)
{
    int i;

    if (v->f04 != 0) {
        for (i = 0; i < 10; i++) {
            if (v->f04[i].f00 != 0 && key == func_021867B0(v->f04[i].f34))
                return &v->f04[i];
        }
    }
    return 0;
}















void func_02193F6C(E50 *e)
{
    func_02082BCC(e, 0, 0x50);
    e->f00 = 0;
}















void func_02193F80(E50 *e, void *a, u8 *b, void *c)
{
    func_02161ECC(a);
    e->f00 = 1;
    func_02082D44(a, e->f34, 0x18);
    func_02082D44(c, e->f04, 0x30);
    e->f4c = b[0];
    e->f4e = b[1];
}















void func_02193FBC(u16 *a, void *b)
{
    if (*a == 1) {
        func_02082D44(b, (u8 *)a + 0x34, 0x18);
    }
}















void func_02193FD4(u16 *a, void *b)
{
    if (*a == 1) {
        func_02082D44((u8 *)a + 0x34, b, 0x18);
    }
}















void func_02193FE8(Cell_02193FE8 (*t)[8])
{
    int i;
    int j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            t[i][j].b = 0xFF;
            t[i][j].c = 0xFFFF;
        }
    }
}















/*
 * Cell holds the Pair as one member; the struct copy t[i][j].k = e emits the
 * two byte stores, the first one addressed [j*4, row].
 *
 * Addresses are Black-image addresses.
 */
void func_02194014(Cell_02194014 (*t)[8], int j, int i, P e, u16 c)
{
    t[i][j].k = e;
    t[i][j].c = c;
}















Cell_02193924 func_02194038(void *a, int b, int c)
{
    return *(Cell_02193924 *)((char *)a + c * 0x20 + b * 4);
}














/*
 * Addresses are Black-image addresses.
 */
int func_02194044(Cell_02193FE8 (*t)[8], u16 b, u16 c)
{
    int i;
    int j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (b == t[i][j].b && c == t[i][j].c) {
                return 1;
            }
        }
    }
    return 0;
}














/*
 * Tail-call thunk: pins arguments 2 and 3 to 0 and 36.
 *
 * Addresses are Black-image addresses.
 */
void func_02194078(void *a)
{
    func_02082BCC(a, 0, 36);
}














void func_02194084(Out *o, In *in, u32 c)
{
    int sum;
    int cnt;
    int i;

    sum = 0;
    cnt = 0;
    for (i = 0; i < 10; i++) {
        if (func_02161ECC(&in->items[i]) != 0) {
            func_02186818((u32 *)c, in->items[i].b);
            sum += *(u16 *)(func_0218682C((char *)c) + 0x2E);
            cnt += in->items[i].b;
        }
    }
    o->x1c = func_02186278((char *)in, 0);
    o->seed = in->x4;
    o->mul = 0x5D588B656C078965ULL;
    o->add = 0x269EC3;
    if (o->x1c == 0) {
        o->x18 = 1;
    } else {
        o->x18 = sum + 2;
    }
    o->x1a = cnt;
    o->x20 = in->x4;
}














static inline void MATH_InitRand32(MATHRandContext32 *context, u64 seed)
{
    context->x = seed;
    context->mul = 0x5d588b656c078965ULL;
    context->add = 0x269ec3ULL;
}














static inline u32 MATH_Rand32(MATHRandContext32 *context, u32 max)
{
    context->x = context->mul * context->x + context->add;
    if (max) {
        return (u32)(((context->x >> 32) * max) >> 32);
    } else {
        return (u32)(context->x >> 32);
    }
}














/*
 * Seeds a NitroSDK MATHRandContext32 at the head of e (MATH_InitRand32
 * inline) and fills an 8x8 grid of 4-byte cells through func_02194014.
 * Spill-slot order (u64 max temp at the top, then row, j, d, k) needs the
 * explicit locals in this declaration order; the index `r += k * 8` must be
 * folded into r before the call or the tail's loads schedule differently.
 * Addresses are Black-image addresses.
 */
void func_02194128(E *e, T_02194128 *tbl, u8 *out)
{
    P t;
    u32 mx;
    P *row;
    int j;
    u8 d;
    u8 k;
    int i;
    int r;
    int dx;
    int dy;

    MATH_InitRand32(&e->rand, e->seed);
    for (j = 0; j < 8; j++) {
        row = tbl->cells[j];
        for (i = 0; i < 8; i++) {
            t = row[i];
            d = t.b;
            if (d == 0xFF) {
                continue;
            }
            if (t.lo != 0 || t.hi != 0) {
                func_02194014((Cell_02194014 (*)[8])out, i, j, t, *(u16 *)(out + (j - t.hi) * 0x20 + (i - t.lo) * 4 + 2));
            } else {
                dx = i - t.lo;
                dy = j - t.hi;
                k = (u8)((u8)((u8)e->base + (u8)(dx + dy)) / (u32)((dx + 3) + (dy + 1))) % 2;
                r = (e->f1c * 8) / 10;
                mx = e->max;
                r += MATH_Rand32(&e->rand, mx);
                if (r >= 8) {
                    r = 7;
                }
                r += k * 8;
                func_02194014((Cell_02194014 (*)[8])out, i, j, t, tbl->vals[d][r]);
            }
        }
    }
}














void *func_02194284(int a, void *b, int heap, int c)
{
    int n = 0xc;
    char *p = (char *)func_02030734(heap, n, 1, (const char *)&d_021DDA70, 0x5d);

    ((struct Obj07444 *)p)->f0 = a;
    ((struct Obj07444 *)p)->f2 = c;
    ((struct Obj07444 *)p)->f4 = b;
    ((struct Obj07444 *)p)->f8 = func_02030734(heap, n * a, 1, (const char *)&d_021DDA70, 0x63);
    return p;
}














void func_021942C8(List_021942C8 *p)
{
    u16 i;
    Item_021942C8 *it;
    extern int func_02194418();

    i = 0;
    it = p->items;
    if (i < p->n) {
        for (; i < p->n; i++) {
            if (it->x8 != 0) {
                func_02194418((u32)it);
            }
            it++;
        }
    }
    func_020307B0(p->items);
    func_020307B0(p);
}














void func_02194300(u16 *a, int b, int c, u16 *d, int e, int f)
{
    u16 i;
    unsigned char *q = *(unsigned char * *)&((struct Obj09482 *)a)->f8;

    func_021945A0(*d);
    for (i = 0; i < *a; i++) {
        if (*(int *)&((struct Obj07446 *)q)->f8 == 0) {
            ((struct Obj07446 *)q)->f8 = func_02194434((unsigned char *)a, c, d, e, f, (int)q);
            ((struct Obj07446 *)q)->f0 = b;
            ((struct Obj07446 *)q)->f6 = a[1];
            return;
        }
        q += 0xc;
    }
}














/*
 * Addresses are Black-image addresses.
 */
void func_02194354(List_021942C8 *p, u32 key)
{
    Item_021942C8 *it;
    u16 i;

    it = p->items;
    for (i = 0; i < p->n; i++) {
        if (it->x8 != 0 && it->key == key) {
            func_02194418(it, key);
            return;
        }
        it++;
    }
}














int func_02194384(u16 *a, s16 b, int c, s16 d, int *e, unsigned *f)
{
    unsigned n = *a;
    unsigned char *q;
    short dlt;

    if (*f < n) {
        q = *(unsigned char * *)&((struct Obj12622 *)a)->f8 + *f * 0xc;
        do {
            (*f)++;
            if (((struct Obj07448 *)q)->f8 != 0) {
                dlt = func_0216D854(((struct Obj07448 *)q)->f8) - c;
                if (dlt < 0)
                    dlt = -dlt;
                if (dlt < 1) {
                    if (func_02163C04((int)(((struct Obj07448 *)q)->f8), b, d, 1)) {
                        *e = ((struct Obj07448 *)q)->f0;
                        return 1;
                    }
                }
                q += 0xc;
            }
        } while (*f < n);
    }
    return 0;
}














/*
 * Unlabelled Thumb leaf (push {r4, r5} saves no lr): finds the record whose
 * key equals the argument among n 12-byte records and returns its +8 field,
 * or 0. Sole blocker of ov010 func_021679C4's callee relocation.
 */
u32 func_021943EC(Tbl_021943EC *t, u32 key)
{
    u16 i;
    Rec *r;
    u16 n;

    n = t->n;
    i = 0;
    r = t->recs;
    for (; i < n; i++, r++) {
        if (r->val != 0 && r->key == key)
            return r->val;
    }
    return 0;
}














/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02194418(void *a, int a1)
{
if (((struct Obj05859 *)((u8 *)(a)))->f4 == 0) {
    func_0216CF2C(((struct Obj05859 *)((u8 *)(a)))->f8, a1);
}
return func_02082BCC(a, 0, 12);
}














void *func_02194434(unsigned char *a, int x, u16 *q, int d, int e, int f)
{
    void *m = ((struct Obj19625 *)a)->f4;
    T_02194434 local = d_021D3F68;
    void *o;

    *(u16 *)((unsigned char *)&local + 2) = x;
    o = func_0216CE60(m, &local, 0);
    func_02194588((u32)o, (u32)q, d, e, f);
    func_0216E014(o, (int *)d, func_021945A0(*q));
    func_0216DB4C(o, 1);
    func_0216DC98(o, 1);
    func_0216DB80(o, 1);
    func_0216DAE0(o, 0);
    func_0216DC64(o, 1);
    func_0216DCCC(o, 1);
    return o;
}












void *func_021944BC(int a)
{
    return func_0216D684(a, 0x10);
}


















/*
 * Addresses are Black-image addresses.
 */
void func_021944C8(u32 a)
{
    ((struct Obj19628 *)(*(u8 * *)&((struct Obj19627 *)((u8 *)func_0216D69C((void *)a)))->fC))->f4 = 1;
}


















void func_021944D8(void *a)
{
    int v[3];
    int *r4;
    int r6;
    int *p;
    int s;
    int t;

    r4 = func_0216D69C(a);
    func_0216D5E0((int)a, func_021945A0(*(u16 *)r4[0]));
    r6 = 0;
    func_0216D88C(a, (struct VecFx32 *)v);
    p = (int *)r4[1];
    if (v[0] != p[0] || v[1] != p[1] || v[2] != p[2]) {
        func_0216E014(a, (int *)r4[1], func_0216D5F8(a));
        r6 = 3;
        if (*(u16 *)(r4[3] + 6) != 0) {
            s = func_0216D598(a);
            if (s == 1 || s == 4) {
                int sum = 0;
                p = (int *)r4[1];
                t = v[0] - p[0];
                if (t < 0)
                    t = -t;
                sum += t;
                t = v[2] - p[2];
                if (t < 0)
                    t = -t;
                sum += t;
                if (sum >= 0x4000)
                    r6 = 10;
            }
        }
    }
    func_0216D674(a, r6);
    if (r4[2] != 0)
    {
        int f = 0;

        if (*(int *)r4[2] == 1)
            f = 1;
        func_0216DAC8(a, f);
    }
}


















void func_02194588(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    u32 *p;

    p = func_0216D69C((void *)a);
    p[0] = b;
    p[1] = c;
    p[2] = d;
    p[3] = e;
}


















/*
 * An empty function.
 */
int func_021945A0(int x)
{
    return x;
}


















void *func_021945A4(void *a, u32 b, u32 c)
{
    void *t;
    u32 *w;

    func_02188CCC((u8 *)b);
    t = func_020122C0(a, 0, func_021945E0, 0x14);
    w = func_020124E8(t);
    func_02082BCC(w, 0, 0x14);
    w[1] = (u32)a;
    w[0] = (u32)t;
    w[2] = b;
    w[3] = c;
    return t;
}


















int func_021945E0(void *a, int b, u8 *c)
{
    void *r6;
    u32 r4;

    switch (c[0x10]) {
    case 0:
        if (func_021A0ED4(func_02188CCC(((struct Obj02693 *)c)->f8)) == 1) {
            r6 = func_02188C7C(((struct Obj02693 *)c)->f8);
            func_020124E4(a);
            r4 = func_020120F4();
            func_0216D9A0(r6);
            func_020129D0((struct BigObj *)r4, 1);
            func_021A0F30(func_02188CCC(((struct Obj02693 *)c)->f8), ((struct Obj02693 *)c)->fC);
            c[0x10]++;
        }
        break;
    case 1:
        if (func_021A0ED4(func_02188CCC(((struct Obj02693 *)c)->f8)) == 1) {
            func_020124E4(a);
            func_020129B8((struct BigObj *)func_020120F4(), ((struct Obj02693 *)c)->fC & 0xff);
            c[0x10]++;
        }
        break;
    case 2:
        func_0216D9E4(func_02188C7C(((struct Obj02693 *)c)->f8));
        return 1;
    }
    return 0;
}

















extern void *(*d_020A8140)(int, int, int);

















extern void *(*d_020A8148)(int, int, int);


















void *func_02194670(u16 *a)
{
    unsigned char *r6;
    int i;

    r6 = (unsigned char *)func_02030734(*a, 0xcd0, 1, (const char *)&d_021DDAC4, 0xec);
    *(T24 *)r6 = *(T24 *)a;
    ((struct Obj07451 *)r6)->fC98 = func_0203101C(*a, *a, 0x20, 0x20);
    for (i = 0; i < 0x20; i++)
        func_02194A58((u32)(r6 + 0x18 + i * 0x64));
    ((struct Obj07451 *)r6)->fCC8 = d_020A8140(0x20, 0, 0);
    ((struct Obj07451 *)r6)->fCCC = d_020A8148(0x20, 0, 0);
    ((struct Obj07451 *)r6)->fC9C = func_021954CC((u32)r6, r6) >> 5;
    return r6;
}


















/*
 * Tail-call thunk: forwards to func_02195530 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_02194704(char *a0)
{
    func_02195530(a0);
}

















void func_0219470C(unsigned char *a)
{
    extern int func_02195490();
    int i;
    extern int func_0219545C();

    func_020310C4(((struct Obj01351 *)a)->fC98);
    func_0219545C(a);
    func_021953D4(a, 0);
    for (i = 0; i < 0x20; i++) {
        if (a[i * 0x64 + 0x1a] == 0)
            func_02194B84(a, a + 0x18 + i * 0x64);
        else
            func_02194C60(a, a + 0x18 + i * 0x64);
    }
    func_02195490(a);
}

















void func_02194760(u32 a)
{
}

















void func_02194764(Top *a)
{
    int i;

    func_0206DB80();
    func_021953D4((u8 *)a, 1);
    for (i = 0; i < 32; i++) {
        if (a->ents[i].f2 == 0) {
            func_02194CE8((int)a, (u16 *)(&a->ents[i]));
        }
    }
}

















extern void (*d_020A814C)(void *p);
















extern void (*d_020A8144)(void *p);

















void func_02194798(unsigned char *a)
{
    int i;

    for (i = 0; i < 0x20; i++)
        func_02194B3C(a, a + 0x18 + i * 0x64);
    d_020A814C(((struct Obj09485 *)a)->fCCC);
    d_020A8144(((struct Obj09485 *)a)->fCC8);
    func_02031140(((struct Obj09485 *)a)->fC98);
    func_020307B0(a);
}

















void func_021947E8(u8 *p, int i, u32 a, u8 b, u8 c, u8 d, u8 f, u32 g, u32 h, u32 k, u8 m, u8 n)
{
    Cfg s;
    u8 *e;

    s.f0 = 0;
    s.f4 = 0;
    s.f8 = b;
    s.f9 = c;
    s.fa = d;
    s.fb = f;
    s.fc = 0x7FFF;
    s.fe = h;
    s.f10 = k;
    e = p + 0x18 + i * 100;
    func_02194AC8(p, e, 0, a, (u8 *)(&s));
    e[0x5C] = m;
    e[0x5D] = n;
    e[2] = 1;
}

















void func_02194848(u8 *p, int i, u32 a, u32 b, u32 u, u32 v, u32 w, u32 x)
{
    Cfg s;

    s.f0 = 1;
    s.f4 = w;
    s.f8 = 1;
    s.f9 = 1;
    s.fa = 0x1E;
    s.fb = 4;
    s.fc = 0x7FFF;
    s.fe = v;
    s.f10 = x;
    func_02194AC8(p, p + 0x18 + i * 100, a, b, (u8 *)(&s));
}

















void func_02194888(u8 *p, int i, u32 a, u32 b, u32 u, u32 v, u32 w, u32 x)
{
    Cfg s;

    s.f0 = 2;
    s.f4 = w;
    s.f8 = 1;
    s.f9 = 0x13;
    s.fa = 0x1E;
    s.fb = 4;
    s.fc = 0x7FFF;
    s.fe = v;
    s.f10 = x;
    func_02194AC8(p, p + 0x18 + i * 100, a, b, (u8 *)(&s));
}

















void func_021948CC(u8 *p, int i, u32 a, u32 b, u8 u, u32 v, u32 x)
{
    int px;
    int py;

    func_0206DF3C(a, &px, &py);
    if (py < 0x60)
        func_02194888(p, i, a, b, u, v, 0, x);
    else
        func_02194848(p, i, a, b, u, v, 0, x);
}

















/*
 * Tail call with the object and a strided element address.
 *
 * Addresses are Black-image addresses.
 */
void func_0219492C(u8 *p, int i)
{
    func_02194B3C(p, p + 0x18 + i * 100);
}

















/*
 * Tail call with a strided element address and the index.
 *
 * Addresses are Black-image addresses.
 */
void func_02194940(u8 *p, int i)
{
    func_02194B70((u16 *)(p + 0x18 + i * 100), i);
}
















void func_02194950(u8 *p, int i)
{
    func_02194B78(p + 0x18 + i * 100, i);
}
















/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02194960(u32 a, u32 b, u32 c, u32 a3)
{
if (*(u16 *)((u8 *)((a + (b * 100))) + 24) == 0) {
    return 1;
}
return 0;
}
















int func_02194974(u8 *p, int i)
{
    return func_02194A84((u16 *)(p + 0x18 + i * 100), i);
}
















u32 func_02194984(u32 a, u32 b)
{
return *(u32 *)((u8 *)((a + (b * 100))) + 32);
}
















u32 func_02194990(u32 a, u32 b)
{
return *(u32 *)((u8 *)((a + (b * 100))) + 36);
}















void func_0219499C(u8 *p, int i, u32 b, u32 c)
{
    u8 *e;

    e = p + 0x18 + i * 100;
    if (((struct Obj02376 *)e)->f8 != 0) {
        func_0201CE48((struct Rec3 *)(((struct Obj02376 *)e)->f8));
        ((struct Obj02376 *)e)->f8 = 0;
    }
    if (b != 0) {
        ((struct Obj02376 *)e)->f60 = c;
        ((struct Obj02376 *)e)->f14 = b;
        ((struct Obj02376 *)e)->f8 = func_0201CCE4(((struct Obj02376 *)e)->fC, e[0x5C], e[0x5D], ((struct Obj02376 *)e)->f14,
                                        ((struct Obj09486 *)p)->f8, c, ((struct Obj09486 *)p)->fC98, 0, ((struct Obj09486 *)p)->f0, 15);
        ((struct Obj02376 *)e)->f0 = 4;
    }
}















u32 func_02194A00(u32 a, u8 b, u8 c, u8 d, u8 e, u32 f)
{
    u32 r;

    r = func_02194A94((Obj_02194A00 *)a, b, c, d, e);
    func_02195E54(a, r, f, 0);
    return r;
}















int func_02194A24(u32 a, u32 b, u32 c, u32 d)
{
return func_02195E54(a, b, ((c << 24) >> 24), 0);
}















int func_02194A34(u32 a, u32 b)
{
func_02195E90((struct FrameStyle *)a, (void *)b);
return func_020409B4(((((struct Obj17941 *)((u8 *)(a)))->f10 << 24) >> 24));
}















u32 func_02194A48(u32 a, struct Descriptor *b)
{
func_02195E90((struct FrameStyle *)a, (void *)b);
return func_020452E8(b);
}















int func_02194A58(u32 a)
{
((struct Obj02343 *)((u8 *)(a)))->f0 = 0;
((struct Obj02343 *)((u8 *)(a)))->f8 = 0;
((struct Obj02343 *)((u8 *)(a)))->f2C = 0;
((struct Obj02343 *)((u8 *)(a)))->f2E = 0;
((struct Obj02343 *)((u8 *)(a)))->f30 = 0;
((struct Obj02343 *)((u8 *)(a)))->f32 = 0;
((struct Obj02343 *)((u8 *)(a)))->f34 = 0;
((struct Obj02343 *)((u8 *)(a)))->f36 = 0;
((struct Obj02343 *)((u8 *)(a)))->f38 = 0;
((struct Obj02343 *)((u8 *)(a)))->f3A = 0;
((struct Obj02343 *)((u8 *)(a)))->f3C = 0;
return a;
}















int func_02194A74(u32 a)
{
if (((struct Obj17942 *)((u8 *)(a)))->f0 == 0) {
    return 1;
}
return 0;
}















/*
 * Untraced .word blob in ov021 (only reached by an r3 tail call): predicate
 * on a u16 field.  Listing bytes 00 88 04 28 01 D1 01 20 70 47 00 20 70 47.
 *
 * Addresses are Black-image addresses.
 */
int func_02194A84(u16 *p, int i)
{
    return *p == 4;
}















u32 func_02194A94(Obj_02194A00 *a, u8 b, u8 c, int d, u8 e)
{
    u32 w;

    w = func_020450F0((u8)a->x10, b, c, d, e, a->x15, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)w)), 15);
    func_02045334((struct Descriptor *)w);
    return w;
}


















/*
 * Addresses are Black-image addresses.
 */
void func_02194AC8(u8 *p, u8 *e, u32 a, u32 b, u8 *s)
{
    int w;
    u8 h;
    int y;
    u8 x;

    func_02194B3C(p, e);
    ((struct Obj01492 *)e)->f10 = a;
    ((struct Obj01492 *)e)->f14 = b;
    ((struct Obj01492 *)e)->f18 = ((struct Obj03114 *)s)->fC;
    ((struct Obj01492 *)e)->f1A = 0;
    ((struct Obj01492 *)e)->f4 = ((struct Obj03114 *)s)->f0;
    ((struct Obj01492 *)e)->f3 = ((struct Obj03114 *)s)->fE;
    ((struct Obj01492 *)e)->f60 = ((struct Obj03114 *)s)->f10;
    w = s[0xA];
    x = s[8];
    x = (x + w > 0x20) ? 0x20 - w : x;
    h = s[0xB];
    y = s[9];
    if (y + h > 0x18)
        y = 0x18 - h;
    ((struct Obj01492 *)e)->fC = func_02194A94((Obj_02194A00 *)p, x, y, w, h);
    ((struct Obj01492 *)e)->f58 = ((struct Obj03114 *)s)->f4;
    ((struct Obj01492 *)e)->f5C = 8;
    ((struct Obj01492 *)e)->f5D = 0;
    ((struct Obj01492 *)e)->f0 = 1;
}


















void func_02194B3C(u8 *p, u8 *e)
{
    if (func_02194A74((u32)e) == 0) {
        if (((struct Obj04217 *)e)->f8 != 0) {
            func_0201CE48((struct Rec3 *)(((struct Obj04217 *)e)->f8));
            ((struct Obj04217 *)e)->f8 = 0;
        }
        func_02195E90((struct FrameStyle *)p, (void *)(((struct Obj04217 *)e)->fC));
        func_020452E8((struct Descriptor *)(((struct Obj04217 *)e)->fC));
        ((struct Obj04217 *)e)->f2 = 0;
        ((struct Obj04217 *)e)->f0 = 0;
    }
}


















/*
 * Untraced .word blob in ov021 (only reached by an r3 tail call): stores 2
 * into the u16 at offset 0.  Listing bytes 02 21 01 80 70 47.
 *
 * Addresses are Black-image addresses.
 */
void func_02194B70(u16 *p, int i)
{
    *p = 2;
}


















/*
 * Untraced .word blob in ov021 (only reached by an r3 tail call): two u16
 * constant stores, one at offset 0 and one at +0x5e.  Listing bytes
 * 05 21 01 80 04 21 5E 30 01 80 70 47.
 *
 * Addresses are Black-image addresses.
 */
void func_02194B78(u8 *p, int i)
{
    ((struct Obj12071 *)p)->f0 = 5;
    ((struct Obj12071 *)p)->f5E = 4;
}


















void func_02194B84(u8 *p, u8 *e)
{
    u32 t;

    switch (((struct Obj01493 *)e)->f0) {
    case 0:
    case 1:
        break;
    case 2:
        func_02195338(p, e);
        ((struct Obj01493 *)e)->f5E = 0;
        ((struct Obj01493 *)e)->f0 = 3;
        return;
    case 3:
        func_02195338(p, e);
        if (((struct Obj01493 *)e)->f5E < 8) {
            ((struct Obj01493 *)e)->f5E += 1;
            return;
        }
        ((struct Obj01493 *)e)->f0 = 4;
        t = ((struct Obj01493 *)e)->f60;
        func_02195E80((u32)p, (u32)e);
        ((struct Obj01493 *)e)->f8 = func_0201CCE4(((struct Obj01493 *)e)->fC, e[0x5C], e[0x5D], ((struct Obj01493 *)e)->f14,
                                        ((struct Obj01351 *)p)->f8, t, *(u32 *)&((struct Obj01351 *)p)->fC98, 0, ((struct Obj01351 *)p)->f0, 15);
        return;
    case 4:
        if (func_02195338(p, e) == 1) {
            func_02195E80((u32)p, (u32)e);
        }
        return;
    case 5:
        if (((struct Obj01493 *)e)->f5E != 0) {
            ((struct Obj01493 *)e)->f5E -= 1;
            return;
        }
        ((struct Obj01493 *)e)->f0 = 6;
        return;
    case 6:
        func_02194B3C(p, e);
        return;
    }
}


















void func_02194C60(u8 *p, u8 *e)
{
    u32 t;

    switch (((struct Obj02377 *)e)->f0) {
    case 2:
        ((struct Obj02377 *)e)->f5E = 0;
        ((struct Obj02377 *)e)->f0 = 3;
    case 3:
        ((struct Obj02377 *)e)->f0 = 4;
        t = ((struct Obj02377 *)e)->f60;
        func_02195E70((u32)p, (Obj_02195E70 *)e);
        ((struct Obj02377 *)e)->f8 = func_0201CCE4(((struct Obj02377 *)e)->fC, e[0x5C], e[0x5D], ((struct Obj02377 *)e)->f14,
                                        ((struct Obj01351 *)p)->f8, t, *(u32 *)&((struct Obj01351 *)p)->fC98, 0, ((struct Obj01351 *)p)->f0, 15);
        return;
    case 5:
        ((struct Obj02377 *)e)->f0 = 6;
        return;
    case 6:
        func_02194B3C(p, e);
        return;
    }
}


















/*
 * The callee 0x02194D1C is src/matched/ov/ov021_func_02194D1C.c. EXACT* only
 * because that callee is the unlabelled follower.
 */
void func_02194CE8(int a, u16 *b)
{
    switch (*b) {
    case 0:
    case 1:
    case 2:
    case 5:
    case 6:
        break;
    case 3:
        func_02194D1C((struct Owner *)a, (struct Sprite *)b, 0);
        break;
    case 4:
        func_02194D1C((struct Owner *)a, (struct Sprite *)b, 1);
        break;
    }
}
















static inline void G3_Translate(fx32_02194AC8 x, fx32_02194AC8 y, fx32_02194AC8 z)
{
    reg_G3_MTX_TRANS = (u32)x;
    reg_G3_MTX_TRANS = (u32)y;
    reg_G3_MTX_TRANS = (u32)z;
}
















static inline void G3_Scale(fx32_02194AC8 x, fx32_02194AC8 y, fx32_02194AC8 z)
{
    reg_G3_MTX_SCALE = (u32)x;
    reg_G3_MTX_SCALE = (u32)y;
    reg_G3_MTX_SCALE = (u32)z;
}
















static inline void G3_TexCoord(fx32_02194AC8 s, fx32_02194AC8 t)
{
    reg_G3_TEXCOORD = (u32)(u16)(fx16)(s >> 8) | ((u32)(u16)(fx16)(t >> 8) << 16);
}
















static inline void G3_Vtx(fx16 x, fx16 y, fx16 z)
{
    reg_G3_VTX_16 = (u32)(u16)x | ((u32)(u16)y << 16);
    reg_G3_VTX_16 = (u32)(u16)z;
}
















/*
 * Immediate-mode draw of one sprite through the geometry engine registers:
 * push, translate, uniform scale, texture/palette from the owner's texture
 * keys, material, polygon attributes, an optional triangle (v[2], v[0], v[1])
 * and, when c is 0, a quad (v[5], v[3], v[4], v[6]); then pop. The texture
 * and palette addresses are the NNS key decode folded into the SDK packing
 * macros. Region ov021: ov021 holds this Thumb code and its caller
 * func_02194CE8 directly precedes it; ov009 is ARM here (wave A1 witness).
 *
 * What closed the docs/notes/func_02194D1C.c.txt residue: the SDK G3_Vtx /
 * G3_TexCoord inline shapes, a sub-struct pointer for b+0x1C (the image keeps
 * it in r6), translate loaded z, y, x into locals, and non-const parameters
 * (with const the loads float across the volatile stores).
 * Addresses are Black-image addresses.
 */
void func_02194D1C(Owner *a, Sprite *b, int c)
{
    struct Quad *q = &b->q;
    fx32_02194AC8 x, y, z;
    fx32_02194AC8 s;

    reg_G3_MTX_PUSH = 0;
    z = q->trans.z;
    y = q->trans.y;
    x = q->trans.x;
    G3_Translate(x, y, z);
    s = q->scale * b->rate / 8;
    G3_Scale(s, s, s);
    reg_G3_TEXIMAGE_PARAM = (((u16)a->texKey & 0x1FFFFFFF)) | 0x0C030000;
    reg_G3_TEXPLTT_BASE = ((a->plttKey & 0xFFFF) << 3) >> 4;
    reg_G3_DIF_AMB = 0x4210FFFF;
    reg_G3_SPE_EMI = 0x4210;
    reg_G3_POLYGON_ATTR = 0x3F1F00C0;
    if (q->tri) {
        reg_G3_BEGIN_VTXS = 0;
        reg_G3_COLOR = b->color;
        G3_TexCoord(0, 0x8000);
        G3_Vtx(q->v[2].x, q->v[2].y, q->v[2].z);
        G3_TexCoord(0, 0);
        G3_Vtx(q->v[0].x, q->v[0].y, q->v[0].z);
        G3_TexCoord(0x8000, 0);
        G3_Vtx(q->v[1].x, q->v[1].y, q->v[1].z);
        reg_G3_END_VTXS = 0;
    }
    if (c == 0) {
        reg_G3_BEGIN_VTXS = 1;
        reg_G3_COLOR = b->color;
        G3_TexCoord(0, 0x8000);
        G3_Vtx(q->v[5].x, q->v[5].y, q->v[5].z);
        G3_TexCoord(0, 0);
        G3_Vtx(q->v[3].x, q->v[3].y, q->v[3].z);
        G3_TexCoord(0x8000, 0);
        G3_Vtx(q->v[4].x, q->v[4].y, q->v[4].z);
        G3_TexCoord(0x8000, 0x8000);
        G3_Vtx(q->v[6].x, q->v[6].y, q->v[6].z);
        reg_G3_END_VTXS = 0;
    }
    reg_G3_MTX_POP = 1;
}















/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02194E74(u32 a, u32 b, u32 c, u32 d)
{
func_0206DF3C(a, b, c, d);
return func_0206E0C4(((struct Obj17945 *)((u8 *)(b)))->f0, ((struct Obj17946 *)((u8 *)(c)))->f0, d, 0);
}















void func_02194E90(u8 *e, u8 *ent, int *b, int *c, void *d)
{
    int x1;
    int y1;
    int w1;
    int h1;
    int x2;
    int y2;
    int w2;
    int h2;

    x1 = (func_02045758((struct Descriptor *)(((struct Obj07453 *)e)->fC)) - 1) << 3;
    y1 = (func_02045760((struct Descriptor *)(((struct Obj07453 *)e)->fC)) - 1) << 3;
    w1 = (func_02045748((struct Descriptor *)(((struct Obj07453 *)e)->fC)) + 2) << 3;
    h1 = (func_02045750((struct Descriptor *)(((struct Obj07453 *)e)->fC)) + 2) << 3;
    x2 = (func_02045758((struct Descriptor *)(((struct Obj07454 *)ent)->fC)) - 1) << 3;
    y2 = (func_02045760((struct Descriptor *)(((struct Obj07454 *)ent)->fC)) - 1) << 3;
    w2 = (func_02045748((struct Descriptor *)(((struct Obj07454 *)ent)->fC)) + 2) << 3;
    h2 = (func_02045750((struct Descriptor *)(((struct Obj07454 *)ent)->fC)) + 2) << 3;
    if (x1 + w1 < x2) {
        *b = x2;
    } else if (x1 > x2 + w2) {
        *b = x2 + w2;
    } else {
        *b = x2 + w2 / 2;
    }
    if (y1 + h1 < y2) {
        *c = y2;
    } else if (y1 > y2 + h2) {
        *c = y2 + h2;
    } else {
        *c = y2 + h2 / 2;
    }
    func_0206E0C4(*b, *c, (u32)d, 0);
}
















/*
 * Unlabelled leaf (no lr save), sole caller func_02194F84.
 * Addresses are Black-image addresses.
 */
void func_02194F5C(int x, int w, int side, u16 *a, u16 *b)
{
    if (side == 0) {
        *a = x + 0x40;
        *b = *a + 0x10;
    } else {
        *b = x + w - 0x40;
        *a = *b - 0x10;
    }
}
















int func_02194F84(u8 *e, int b, int c, void *d, void *f)
{
    int x;
    int y;
    int w;
    int h;
    int m;
    int r;
    int side;
    u16 t;
    u16 ya;
    u16 yb;
    u16 v[2];

    x = (func_02045758((struct Descriptor *)(((struct Obj01494 *)e)->fC)) - 1) << 3;
    y = (func_02045760((struct Descriptor *)(((struct Obj01494 *)e)->fC)) - 1) << 3;
    w = (func_02045748((struct Descriptor *)(((struct Obj01494 *)e)->fC)) + 2) << 3;
    h = (func_02045750((struct Descriptor *)(((struct Obj01494 *)e)->fC)) + 2) << 3;
    y += func_02040804(func_02045730((struct Descriptor *)(((struct Obj01494 *)e)->fC)));
    switch (((struct Obj01494 *)e)->f4) {
    case 0:
    default:
        if (w >= 16 && h >= 16) {
            m = 16;
        } else {
            m = h;
        }
        if (c < y) {
            yb = ya =y + 3;
            v[1] = x + w / 2 - m / 2;
            v[0] = m / 2 + (x + w / 2);
            r = 1;
        } else if (c > y + h) {
            yb = ya =y + h - 3;
            v[1] = x + w / 2 - m / 2;
            v[0] = m / 2 + (x + w / 2);
            r = 2;
        } else {
            ya = y + h / 2 - m / 2;
            yb = m / 2 + (y + h / 2);
            if (b < x) {
                t = x + 1;
                v[1] = t;
                v[0] = t;
                r = 3;
            } else if (b > x + w) {
                t = x + w - 1;
                v[1] = t;
                v[0] = t;
                r = 4;
            } else {
                t = x + w / 2;
                v[1] = t;
                v[0] = t;
                r = 0;
            }
        }
        break;
    case 1:
        yb = ya =y + h - 4;
        if (((struct Obj01494 *)e)->f58 == 0) {
            if (b < 0x80) {
                side = 0;
                r = 7;
            } else {
                side = 1;
                r = 8;
            }
        } else if (((struct Obj01494 *)e)->f58 == 7) {
            side = 0;
            r = 7;
        } else {
            side = 1;
            r = 8;
        }
        func_02194F5C(x, w, side, &v[1], &v[0]);
        break;
    case 2:
        yb = ya =y + 4;
        if (((struct Obj01494 *)e)->f58 == 0) {
            if (b < 0x80) {
                side = 0;
                r = 5;
            } else {
                side = 1;
                r = 6;
            }
        } else if (((struct Obj01494 *)e)->f58 == 5) {
            side = 0;
            r = 5;
        } else {
            side = 1;
            r = 6;
        }
        func_02194F5C(x, w, side, &v[1], &v[0]);
        break;
    }
    func_0206E0C4(v[1], ya, (u32)d, 0);
    func_0206E0C4(v[0], yb, (u32)f, 0);
    return r;
}














void func_02195128(u8 *p, u32 c0, u32 c1, u32 c2, u32 c3)
{
    int x;
    int y;
    int w;
    int h;

    x = func_02045758((struct Descriptor *)(((struct Obj07457 *)p)->fC)) << 3;
    y = (func_02045760((struct Descriptor *)(((struct Obj07457 *)p)->fC)) - 1) << 3;
    w = func_02045748((struct Descriptor *)(((struct Obj07457 *)p)->fC)) << 3;
    h = (func_02045750((struct Descriptor *)(((struct Obj07457 *)p)->fC)) + 2) << 3;
    func_0206E0C4(x, y, c0, 0);
    func_0206E0C4(x + w, y, c1, 0);
    func_0206E0C4(x, y + h, c2, 0);
    func_0206E0C4(x + w, y + h, c3, 0);
}














static inline void setv(V3 *o, int x, int y, int z)
{
    o->x = x;
    o->y = y;
    o->z = z;
}














static inline void set3(s16 *o, s16 x, s16 y, s16 z)
{
    o[0] = x;
    o[1] = y;
    o[2] = z;
}














void func_0219518C(u8 *p, u8 *e, const V3 *a, V3 *b, V3 *c, V3 *d, V3 *f, V3 *g, V3 *h)
{
    V3 l0;
    V3 l1;
    V3 l2;
    V3 l3;
    V3 l4;
    V3 l5;
    int m;
    int m1;
    int m2;
    int m3;
    int m4;
    int m5;

    func_0207CA00(b, a, &l0);
    func_0207CA00(c, a, &l1);
    func_0207CA00(d, a, &l2);
    func_0207CA00(f, a, &l3);
    func_0207CA00(g, a, &l4);
    func_0207CA00(h, a, &l5);
    m = func_0207CBD0(&l0);
    m1 = func_0207CBD0(&l1);
    m2 = func_0207CBD0(&l2);
    m3 = func_0207CBD0(&l3);
    m4 = func_0207CBD0(&l4);
    m5 = func_0207CBD0(&l5);
    if (m < m1) {
        m = m1;
    }
    if (m < m2) {
        m = m2;
    }
    if (m < m3) {
        m = m3;
    }
    if (m < m4) {
        m = m4;
    }
    if (m < m5) {
        m = m5;
    }
    setv((V3 *)(e + 0x1C), a->x, a->y, a->z);
    ((struct Obj07458 *)e)->f28 = m;
    ((struct Obj07458 *)e)->f2C = 0;
    ((struct Obj07458 *)e)->f2E = 0;
    ((struct Obj07458 *)e)->f30 = 0;
    set3((s16 *)(e + 0x32), func_0207C768(l0.x, m), func_0207C768(l0.y, m), func_0207C768(l0.z, m));
    set3((s16 *)(e + 0x38), func_0207C768(l1.x, m), func_0207C768(l1.y, m), func_0207C768(l1.z, m));
    set3((s16 *)(e + 0x3E), func_0207C768(l2.x, m), func_0207C768(l2.y, m), func_0207C768(l2.z, m));
    set3((s16 *)(e + 0x44), func_0207C768(l3.x, m), func_0207C768(l3.y, m), func_0207C768(l3.z, m));
    set3((s16 *)(e + 0x4A), func_0207C768(l4.x, m), func_0207C768(l4.y, m), func_0207C768(l4.z, m));
    set3((s16 *)(e + 0x50), func_0207C768(l5.x, m), func_0207C768(l5.y, m), func_0207C768(l5.z, m));
}












u32 func_02195338(u8 *p, u8 *e)
{
    V3 v8;
    V3 v7;
    V3 v6;
    V3 v5;
    V3 v4;
    V3 v3;
    V3 v2;
    V3 v1;
    int b;
    int c;
    int r;

    if (((struct Obj01494 *)e)->f10 != 0) {
        func_0207CA00((const V3 *)(((struct Obj01494 *)e)->f10), (const V3 *)(p + 0xCB8), &v1);
        func_02194E74((u32)(&v1), (u32)(&b), (u32)(&c), (u32)(&v8));
    } else {
        func_02194E90(e, p + 0x18 + ((struct Obj01494 *)e)->f1A * 100, &b, &c, &v8);
    }
    r = func_02194F84(e, b, c, &v7, &v6);
    func_02195128(e, (u32)(&v5), (u32)(&v4), (u32)(&v3), (u32)(&v2));
    func_0219518C(p, e, (const V3 *)&v8, &v7, &v6, &v5, &v4, &v3, &v2);
    if (((struct Obj01494 *)e)->f58 != r) {
        ((struct Obj01494 *)e)->f58 = r;
        return 1;
    }
    return 0;
}












void func_021953D4(u8 *p, int m)
{
    V3 t;
    V3 a;
    V3 b;
    V3 c;
    int f;

    func_0207CA00((const V3 *)(p + 0xCA0), (const V3 *)(p + 0xCB8), &t);
    a.x = t.x;
    a.y = t.y;
    a.z = t.z;
    b.x = 0;
    b.y = 0x1000;
    b.z = 0;
    c.x = 0;
    c.y = 0;
    c.z = 0;
    if (m == 0) {
        f = 0x40000;
        if (((struct Obj01351 *)p)->fCC4 >= f)
            f = ((struct Obj01351 *)p)->fCC4 + 0x1000;
        func_02048AFC(((struct Obj01351 *)p)->f4, &a);
        func_02048B20(((struct Obj01351 *)p)->f4, &b);
        func_02048B44(((struct Obj01351 *)p)->f4, &c);
        func_02048B60((struct Light *)(((struct Obj01351 *)p)->f4), (const u32 *)(&f));
        func_02048AD0((struct Light *)(((struct Obj01351 *)p)->f4));
        return;
    }
    func_0207D7C4(&a, &b, &c, 1, 0);
}












int func_0219545C(u32 a, u32 b, u32 c, u32 d)
{
func_02048AE8(((struct Obj07211 *)((u8 *)(a)))->f4, (a + (202 << 4)), c, d);
func_02048B0C(((struct Obj07211 *)((u8 *)(a)))->f4, (a + ((202 << 4) + 12)));
func_02048B30(((struct Obj07211 *)((u8 *)(a)))->f4, (a + ((202 << 4) + 24)));
return func_02048B54(((struct Obj07211 *)((u8 *)(a)))->f4, (a + ((202 << 4) + 36)));
}











/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02195490(u32 a, u32 b, u32 c, u32 d)
{
func_02048AFC(((struct Obj05860 *)((u8 *)(a)))->f4, (a + (202 << 4)), c, d);
func_02048B20(((struct Obj05860 *)((u8 *)(a)))->f4, (a + ((202 << 4) + 12)));
func_02048B44(((struct Obj05860 *)((u8 *)(a)))->f4, (a + ((202 << 4) + 24)));
func_02048B60((struct Light *)(((struct Obj05860 *)((u8 *)(a)))->f4), (const u32 *)(a + ((202 << 4) + 36)));
return func_02048AD0(((struct Obj05860 *)((u8 *)(a)))->f4);
}











/*
 * Addresses are Black-image addresses.
 */
u32 func_021954CC(u32 p, u8 *e)
{
    u32 k;

    func_020414EC(((struct Obj04218 *)e)->f10 & 0xFF);
    k = 0;
    switch (((struct Obj04218 *)e)->f10) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        k = 4;
        break;
    }
    func_02049B40(5, 0, k, e[0x14] << 5, 0x20, ((struct Obj04218 *)e)->f0);
    return func_02049624((void *)5, (void *)5, (void *)(((struct Obj04218 *)e)->f10), (void *)(((struct Obj04218 *)e)->fC), 0, 0, ((struct Obj04218 *)e)->f0);
}











void func_02195530(char *p)
{
    func_0207F7A0();
    DC_FlushRange(d_021DDA84, 0x20);
    func_0207F7FC(d_021DDA84, (u16)((struct Obj12626 *)p)->fCC8 << 3, 0x20);
    func_0207F9B4();
    func_0207FA0C();
    DC_FlushRange(d_021DDAA4, 0x20);
    func_0207FA40(d_021DDAA4, (u16)((struct Obj12626 *)p)->fCCC << 3, 0x20);
    func_0207FADC();
}











void func_02195588(u8 *p)
{
    u32 r;
    u32 v;

    func_020414EC(((struct Obj04219 *)p)->f10 & 0xFF);
    v = ((struct Obj04219 *)p)->f10;
    r = 0;
    switch (v) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        r = 4;
        break;
    }
    func_02049B40(5, 0, r, (u32)p[0x14] << 5, 0x20, ((struct Obj04219 *)p)->f0);
    func_02049624((void *)5, (void *)5, (void *)(((struct Obj04219 *)p)->f10), (void *)(((struct Obj04219 *)p)->fC), 0, 0, ((struct Obj04219 *)p)->f0);
}











/*
 * Draws a simple window frame (corners and edges, one tile each) around a
 * window on its BG layer, plus an optional decoration tile pair selected by
 * `deco`. Sibling of func_02195938, which draws the double-corner frame. Edges that touch the
 * screen border (x == 0, x + w == 32, y == 0, y + h == 24) are skipped.
 *
 * Addresses are Black-image addresses.
 */
void func_021955EC(struct FrameStyle *style, void *win, int deco)
{
    u16 x;
    u16 y;
    u16 w;
    u16 h;
    int topClip;
    int bottomClip;
    int leftClip;
    int rightClip;
    u8 bg;
    int pal;
    u16 tile;
    int top;
    int right;
    int bottom;
    u16 t2;

    x = func_02045758(win);
    y = func_02045760(win);
    w = func_02045748(win);
    h = func_02045750(win);
    topClip = 0;
    bottomClip = 0;
    leftClip = 0;
    rightClip = 0;
    bg = style->bgLayer;
    pal = (style->palette & 0xF) << 12;
    tile = style->baseTile;

    if (x == 0)
        leftClip = 1;
    right = x + w;
    if (right == 0x20)
        rightClip = 1;
    if (y == 0)
        topClip = 1;
    bottom = y + h;
    if (bottom == 0x18)
        bottomClip = 1;

    func_02045374(win);

    if (!topClip) {
        if (!leftClip)
            func_02041300(bg, (tile + 1) | pal, x - 1, y - 1, 1, 1, 0x11);
        top = y - 1;
        func_02041300(bg, (tile + 3) | pal, x, top, w, 1, 0x11);
        if (!rightClip)
            func_02041300(bg, (tile + 0x401) | pal, right, top, 1, 1, 0x11);
    }
    if (!leftClip)
        func_02041300(bg, (tile + 4) | pal, x - 1, y, 1, h, 0x11);
    if (!rightClip)
        func_02041300(bg, (tile + 0x404) | pal, right, y, 1, h, 0x11);
    if (!bottomClip) {
        if (!leftClip)
            func_02041300(bg, (tile + 0x801) | pal, x - 1, bottom, 1, 1, 0x11);
        func_02041300(bg, (tile + 0x803) | pal, x, bottom, w, 1, 0x11);
        if (!rightClip)
            func_02041300(bg, (tile + 0xC01) | pal, right, bottom, 1, 1, 0x11);
    }

    t2 = (tile + 2) | pal;
    switch (deco) {
    case 1:
        if (!topClip)
            func_02041300(bg, t2, x + ((u32)w >> 1) - 1, y - 1, 2, 1, 0x11);
        break;
    case 2:
        if (!bottomClip)
            func_02041300(bg, t2 | 0x800, x + ((u32)w >> 1) - 1, bottom, 2, 1, 0x11);
        break;
    case 3:
        if (!leftClip)
            func_02041300(bg, (tile + 5) | pal, x - 1, y + ((u32)h >> 1) - 1, 1, 2, 0x11);
        break;
    case 4:
        if (!rightClip)
            func_02041300(bg, (tile + 5) | pal, right, y + ((u32)h >> 1) - 1, 1, 2, 0x11);
        break;
    case 5:
        if (!topClip)
            func_02041300(bg, t2, x + 7, y - 1, 2, 1, 0x11);
        break;
    case 7:
        if (!topClip)
            func_02041300(bg, t2 | 0x800, x + 7, bottom, 2, 1, 0x11);
        break;
    case 6:
        if (!bottomClip) {
            right -= 9;
            func_02041300(bg, t2, right, y - 1, 2, 1, 0x11);
        }
        break;
    case 8:
        if (!bottomClip) {
            right -= 9;
            func_02041300(bg, t2 | 0x800, right, bottom, 2, 1, 0x11);
        }
        break;
    }
    func_020409B4(bg);
}











/*
 * Draws a window frame around a window on its BG layer: corners, edges, and
 * an optional decoration tile pair selected by `deco`. Edges that touch the
 * screen border (x == 0, x + w == 32, y == 0, y + h == 24) are skipped.
 * The window geometry getters are held in u16 locals and the palette nibble
 * is masked and shifted into an int; both are what the truncations and the
 * lsl #28 / lsr #16 fold in the image require.
 *
 * Addresses are Black-image addresses.
 */
void func_02195938(struct FrameStyle *style, void *win, int deco)
{
    u16 x;
    u16 y;
    u16 w;
    u16 h;
    int topClip;
    int bottomClip;
    int leftClip;
    int rightClip;
    u8 bg;
    int pal;
    u16 tile;
    int right;
    int bottom;
    u16 t8;

    x = func_02045758(win);
    y = func_02045760(win);
    w = func_02045748(win);
    h = func_02045750(win);
    topClip = 0;
    bottomClip = 0;
    leftClip = 0;
    rightClip = 0;
    bg = style->bgLayer;
    pal = (style->palette & 0xF) << 12;
    tile = style->baseTile;

    if (x == 0)
        leftClip = 1;
    right = x + w;
    if (right == 0x20)
        rightClip = 1;
    if (y == 0)
        topClip = 1;
    bottom = y + h;
    if (bottom == 0x18)
        bottomClip = 1;

    func_02045374(win);

    if (!topClip) {
        if (!leftClip) {
            func_02041300(bg, (tile + 9) | pal, x - 1, y - 1, 1, 1, 0x11);
            func_02041300(bg, (tile + 10) | pal, x, y - 1, 1, 1, 0x11);
            func_02041300(bg, (tile + 11) | pal, x - 1, y, 1, 1, 0x11);
        }
        func_02041300(bg, (tile + 6) | pal, x + 1, y - 1, w - 1, 1, 0x11);
        if (!rightClip) {
            func_02041300(bg, (tile + 0x409) | pal, x + w, y - 1, 1, 1, 0x11);
            func_02041300(bg, (tile + 0x40A) | pal, x + w - 1, y - 1, 1, 1, 0x11);
            func_02041300(bg, (tile + 0x40B) | pal, x + w, y, 1, 1, 0x11);
        }
    }
    if (!leftClip) {
        if (!topClip)
            func_02041300(bg, (tile + 7) | pal, x - 1, y + 1, 1, h - 1, 0x11);
        else
            func_02041300(bg, (tile + 7) | pal, x - 1, y, 1, h, 0x11);
    }
    if (!rightClip) {
        if (!topClip)
            func_02041300(bg, (tile + 0x407) | pal, right, y + 1, 1, h - 1, 0x11);
        else
            func_02041300(bg, (tile + 0x407) | pal, right, y, 1, h, 0x11);
    }
    if (!bottomClip) {
        if (!leftClip) {
            func_02041300(bg, (tile + 0x809) | pal, x - 1, y + h, 1, 1, 0x11);
            func_02041300(bg, (tile + 0x80A) | pal, x, y + h, 1, 1, 0x11);
            func_02041300(bg, (tile + 0x80B) | pal, x - 1, y + h - 1, 1, 1, 0x11);
        }
        func_02041300(bg, (tile + 0x806) | pal, x + 1, bottom, w - 1, 1, 0x11);
        if (!rightClip) {
            func_02041300(bg, (tile + 0xC09) | pal, x + w, y + h, 1, 1, 0x11);
            func_02041300(bg, (tile + 0xC0A) | pal, x + w - 1, y + h, 1, 1, 0x11);
            func_02041300(bg, (tile + 0xC0B) | pal, x + w, y + h - 1, 1, 1, 0x11);
        }
    }

    t8 = (tile + 8) | pal;
    switch (deco) {
    case 1:
        if (!topClip)
            func_02041300(bg, t8, x + ((u32)w >> 1) - 1, y - 1, 2, 1, 0x11);
        break;
    case 2:
        if (!bottomClip)
            func_02041300(bg, t8 | 0x800, x + ((u32)w >> 1) - 1, bottom, 2, 1, 0x11);
        break;
    case 3:
        if (!leftClip)
            func_02041300(bg, (tile + 5) | pal, x - 1, y + ((u32)h >> 1) - 1, 1, 2, 0x11);
        break;
    case 4:
        if (!rightClip)
            func_02041300(bg, (tile + 5) | pal, right, y + ((u32)h >> 1) - 1, 1, 2, 0x11);
        break;
    case 5:
        if (!topClip)
            func_02041300(bg, t8, x + 7, y - 1, 2, 1, 0x11);
        break;
    case 7:
        if (!topClip)
            func_02041300(bg, t8 | 0x800, x + 7, bottom, 2, 1, 0x11);
        break;
    case 6:
        if (!bottomClip) {
            right -= 9;
            func_02041300(bg, t8, right, y - 1, 2, 1, 0x11);
        }
        break;
    case 8:
        if (!bottomClip) {
            right -= 9;
            func_02041300(bg, t8 | 0x800, right, bottom, 2, 1, 0x11);
        }
        break;
    }
    func_020409B4(bg);
}











u32 func_02195E54(u32 a, u32 b, u8 c, u32 d)
{
    switch (c) {
    case 0:
        func_021955EC((struct FrameStyle *)a, (void *)b, d);
        break;
    case 1:
        func_02195938((struct FrameStyle *)a, (void *)b, d);
        break;
    }
}











void func_02195E70(u32 a, Obj_02195E70 *b)
{
    func_02195E54(a, b->xc, b->x3, 0);
}










/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02195E80(u32 a, u32 b)
{
return func_02195E54(a, ((struct Obj09176 *)((u8 *)(b)))->fC, ((struct Obj09176 *)((u8 *)(b)))->f3, ((struct Obj09176 *)((u8 *)(b)))->f58);
}










/*
 * Clears the one-tile frame around a window (tile 0 on all eight edges),
 * skipping any edge that touches the 32x24 screen border. The erase
 * counterpart of func_02195938.
 */
void func_02195E90(struct FrameStyle *style, void *win)
{
    u16 x;
    u16 y;
    u16 w;
    u16 h;
    int topClip;
    int bottomClip;
    int leftClip;
    int rightClip;
    u8 bg;
    int top;
    int right;
    int bottom;

    x = func_02045758(win);
    y = func_02045760(win);
    w = func_02045748(win);
    h = func_02045750(win);
    topClip = 0;
    bottomClip = 0;
    leftClip = 0;
    rightClip = 0;
    bg = style->bgLayer;

    func_020456F8(win);

    if (x == 0)
        leftClip = 1;
    right = x + w;
    if (right == 0x20)
        rightClip = 1;
    if (y == 0)
        topClip = 1;
    bottom = y + h;
    if (bottom == 0x18)
        bottomClip = 1;

    if (!topClip) {
        if (!leftClip)
            func_02041300(bg, 0, x - 1, y - 1, 1, 1, 0x11);
        top = y - 1;
        func_02041300(bg, 0, x, top, w, 1, 0x11);
        if (!rightClip)
            func_02041300(bg, 0, right, top, 1, 1, 0x11);
    }
    if (!leftClip)
        func_02041300(bg, 0, x - 1, y, 1, h, 0x11);
    if (!rightClip)
        func_02041300(bg, 0, right, y, 1, h, 0x11);
    if (!bottomClip) {
        if (!leftClip)
            func_02041300(bg, 0, x - 1, bottom, 1, 1, 0x11);
        func_02041300(bg, 0, x, bottom, w, 1, 0x11);
        if (!rightClip)
            func_02041300(bg, 0, right, bottom, 1, 1, 0x11);
    }
    func_020409B4(bg);
}









/*
 * Unlabelled leaf setter, callee of the thunk at 0x02196034.
 *
 * Addresses are Black-image addresses.
 */
void func_02196030(u32 *p, u32 v)
{
    *p = v;
}











/*
 * Tail-call thunk: forwards to func_02196030 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_02196034(void *p, void *fn, u32 n)
{
    extern void func_02196030();
    func_02196030();
}











void func_0219603C(void *a0)
{
    B32 t0;
    B32 t1;
    B32 t4;
    B32 t5;
    B32 t6;
    B32 t7;

    t0 = d_021D40A0;
    func_0203FCA0(0, (const struct BgTemplate *)(&t0), 0);
    func_020414AC(0);
    func_020409B4(0);
    func_02040588(0, 1);

    t1 = d_021D40C0;
    func_0203FCA0(1, (const struct BgTemplate *)(&t1), 0);
    func_020414AC(1);
    func_020409B4(1);
    func_02040588(1, 1);

    t4 = d_021D40E0;
    func_0203FCA0(4, (const struct BgTemplate *)(&t4), 0);
    func_02040588(4, 1);
    func_020409B4(4);

    t5 = d_021D4100;
    func_0203FCA0(5, (const struct BgTemplate *)(&t5), 0);
    func_02040588(5, 1);
    func_02040C14(5, 0, 1, 0);
    func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(5);

    t6 = d_021D4120;
    func_0203FCA0(6, (const struct BgTemplate *)(&t6), 0);
    func_02040588(6, 1);
    func_020409B4(6);

    t7 = d_021D4140;
    func_0203FCA0(7, (const struct BgTemplate *)(&t7), 0);
    func_02040588(7, 1);
    func_020409B4(7);
}










void func_021961A4(u8 *p, u32 a, u32 b)
{
    u32 h;
    u32 n;
    void *d;

    h = (u32)func_02021518(((struct Obj12628 *)p)->f10);
    func_0202155C((struct PalAnmSlot *)h, a, 0x200, ((struct Obj12628 *)p)->f10);
    n = b << 5;
    func_020216D4((struct PalAnmSlot *)h, a, 0, n);
    func_02021FD8((struct Chan02021FD8 *)h, a, 0, (b << 20) >> 16, 6, 0);
    d = (void *)func_02021730((char *)h, a);
    DC_FlushRange(d, n);
    if (a != 1) {
        if (a == 3)
            func_0207E5D0(d, 0, n);
    } else {
        func_0207E468(d, 0, n);
    }
    func_020215A0((struct PalAnmSlot *)h, a);
    func_02021540((void *)h);
}










void func_02196228(u8 *p, int flag)
{
    if (flag) {
        func_02082D44((void *)0x05000600, (void *)((struct Obj00094 *)p)->f2EC, 0x200);
        func_02082D44((void *)0x05000400, (void *)((struct Obj00094 *)p)->f2F0, 0x200);
        func_021961A4(p, 3, 0xE);
        func_021961A4(p, 1, 9);
    } else {
        func_0207E5D0((void *)(((struct Obj00094 *)p)->f2EC), 0, 0x1C0);
        func_0207E468((void *)(((struct Obj00094 *)p)->f2F0), 0, 0x120);
    }
}











/*
 * Addresses are Black-image addresses.
 */
void func_02196290(u8 *a)
{
    if (((struct Obj00094 *)a)->f2E8 != 0) {
        func_0202F038((u8 *)(((struct Obj00094 *)a)->f2E8));
        ((struct Obj00094 *)a)->f2E8 = 0;
    }
    ((struct Obj00094 *)a)->f2E8 = (u32)func_0202EE8C(((struct Obj00094 *)a)->f2B8, (void *)(*(u32 *)&((struct Obj00094 *)a)->f2B0), 15, 16, ((struct Obj00094 *)a)->f10);
}











/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021962C4(u32 a)
{
if (*(u32 *)((u8 *)(a) + ((186 << 2))) != 0) {
    func_0202F038((u8 *)(*(u32 *)((u8 *)(a) + ((186 << 2)))));
    *(u32 *)((u8 *)(a) + ((186 << 2))) = 0;
}
func_0201F7A8((void *)(*(u32 *)((u8 *)(a) + ((43 << 4)))), 2);
func_020456F8((struct Descriptor *)(*(u32 *)((u8 *)(a) + ((43 << 4)))));
return func_02041B6C(5);
}











void func_021962F4(u8 *a)
{
    func_021962C4((u32)a);
    func_020452E8((struct Descriptor *)(*(u32 *)&((struct Obj00094 *)a)->f2B0));
    *(u32 *)&((struct Obj00094 *)a)->f2B0 = 0;
}









void func_0219630C(int n, u32 *msg, Obj_0219630C *a, Desc *d, int *xs, int *ys)
{
    int i;
    int x;
    int y;

    func_020414EC(7);
    a->x2f4 = n;
    func_02049B40(0x17, 5, 4, 0x100, 0x20, a->x10);
    for (i = 0; i < 4; i++) {
        if (a->w[i] != 0) {
            func_020456F8((struct Descriptor *)a->w[i]);
            func_0201F7A8((void *)a->w[i], 2);
            func_020452E8((struct Descriptor *)a->w[i]);
        }
        a->w[i] = 0;
    }
    for (i = 0; i < n; i++) {
        func_0201DD78(15, 2, 0);
        a->w[i] = func_020450F0(7, (u8)d[i].x0, (u8)d[i].x4, (u8)d[i].x8, (u8)d[i].xc, 8, 0);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)a->w[i])), 0);
        func_02045CAC((struct MsgBank *)a->x28, msg[i], (void *)a->x38);
        if (xs != 0) {
            x = xs[i] - (func_0201D304((struct StrObj *)a->x38, a->x2c, 0) >> 1);
        } else {
            x = 0;
        }
        if (ys != 0) {
            y = ys[i] - (func_0201D42C((struct StrObj *)a->x38, (void *)a->x2c) >> 1);
        } else {
            y = 0;
        }
        func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)a->w[i])), x, y, (void *)a->x38, (void *)a->x2c);
        func_02045334((struct Descriptor *)a->w[i]);
        func_02045374((struct Cfg *)a->w[i]);
    }
    if (a->x24 != 0) {
        func_02051C6C((void *)a->x24);
    }
    a->x24 = 0;
    func_02041B6C(7);
    func_02040588(7, 1);
}









void func_02196454(u8 *p)
{
    int i;

    if (((struct Obj03578 *)p)->f24 != 0)
        func_02051C6C((void *)(((struct Obj03578 *)p)->f24));
    ((struct Obj03578 *)p)->f24 = 0;
    for (i = 0; i < 4; i++) {
        u32 *q = (u32 *)p + i;
        if (q[5] != 0) {
            func_020456F8((struct Descriptor *)q[5]);
            func_02041B6C(5);
            func_0201F7A8((void *)q[5], 2);
            func_020452E8((struct Descriptor *)q[5]);
        }
        q[5] = 0;
    }
    ((struct Obj03578 *)p)->f2F4 = 0;
}









void func_0219649C(void *a, int b, Cb *c)
{
    if (b == 0 && c->fn != 0 && c->fn(a, c) != 0) {
        return;
    }
}









void func_021964B0(u16 (*dst)[16], u16 *add, int n)
{
    int i;
    int j;
    u16 c;
    u16 r;
    u16 g;
    u16 b;

    for (i = 0; i < n; i++) {
        for (j = 0; j < 16; j++) {
            c = dst[i][j];
            r = c & 0x1F;
            g = (c & 0x3E0) >> 5;
            b = (c & 0x7C00) >> 10;
            r += add[j];
            g += add[j];
            b += add[j];
            if (r > 31) {
                r = 31;
            }
            if (g > 31) {
                g = 31;
            }
            if (b > 31) {
                b = 31;
            }
            dst[i][j] = (b << 10) + (r + (g << 5));
        }
    }
}









void func_02196538(u8 *p)
{
    void *h;
    void *res;
    u8 *pal;

    ((struct Obj00150 *)p)->f2F8 = 0;
    ((struct Obj00150 *)p)->f38 = func_020457B0(0x12C, ((struct Obj00150 *)p)->f10);
    ((struct Obj00150 *)p)->f2C = func_0201D7EC(0x17, 0, 0, 0, ((struct Obj00150 *)p)->f10);
    ((struct Obj00150 *)p)->f28 = func_02045B38(0, 2, 0x2E, ((struct Obj00150 *)p)->f10);

    h = func_020490F4(0x1C, ((struct Obj00150 *)p)->f10);
    func_02049B68(h, 1, 0, 0, 0, ((struct Obj00150 *)p)->f10);
    ((struct Obj00150 *)p)->f44 = func_02049740(h, 6, 0, 0, 0, ((struct Obj00150 *)p)->f10);
    func_02049990(h, 0xD, 0, 0, (u16)((struct Obj00150 *)p)->f44, 0, 0, ((struct Obj00150 *)p)->f10);
    func_02049238(h);

    h = func_020490F4(0x1D, ((struct Obj00150 *)p)->f10);
    func_02049B68(h, 2, 4, 0, 0, ((struct Obj00150 *)p)->f10);
    res = func_02049F78(h, 2, (u32)(&pal), ((struct Obj00150 *)p)->f10);
    func_02082D44((void *)((struct Obj12630 *)pal)->fC, p + 0x48, 0x100);
    func_02082D44((void *)((struct Obj12630 *)pal)->fC, p + 0x148, 0x100);
    func_021964B0((u16 (*)[16])(p + 0x148), (u16 *)d_021DDAD4, 8);
    func_020307B0(res);
    func_02049B68(h, 0, 0, 0, 0, ((struct Obj00150 *)p)->f10);
    ((struct Obj00150 *)p)->f40 = func_02049740(h, 4, 4, 0, 0, ((struct Obj00150 *)p)->f10);
    func_02049990(h, 9, 4, 0, (u16)((struct Obj00150 *)p)->f40, 0, 0, ((struct Obj00150 *)p)->f10);
    func_02049990(h, 0xB, 6, 0, (u16)((struct Obj00150 *)p)->f40, 0, 0, ((struct Obj00150 *)p)->f10);
    func_02049238(h);

    ((struct Obj00150 *)p)->f3C = func_0201F5DC((void *)5, 0xC, 0, ((struct Obj00150 *)p)->f10);
    func_02049B40(0x17, 5, 4, 0x160, 0x20, ((struct Obj00150 *)p)->f10);
}










void func_021966B0(u8 *p, u32 a)
{
    void *h;

    h = func_020490F4(0x1D, ((struct Obj00093 *)p)->f10);
    func_02049990(h, a, 6, 0, (u16)((struct Obj00093 *)p)->f40, 0, 0, ((struct Obj00093 *)p)->f10);
    func_02049238(h);
    func_02040588(6, 1);
}










void func_021966F0(u8 *p)
{
    Blk t = d_021D4070;

    func_021966B0(p, 0xB);
    func_0219707C(p);
    func_0219630C(4, (u32 *)&t, (Obj_0219630C *)p, d_021DDB84, d_021D4014, d_021D4024);
    *(u32 *)&((struct Obj00093 *)p)->f24 = (u32)func_02051B84(d_021D404C, (int)((void *)func_0219649C), (int)p, ((struct Obj00093 *)p)->f10);
    ((struct Obj00093 *)p)->f4 = (void *)func_02196974;
    func_02196034(p, (void *)func_02196A4C, 0x340);
}










void func_02196768(u8 *p)
{
    u32 v;

    func_0201DD68();
    func_02196454(p);
    func_02040DA8(5, 1, 0);
    v = ((struct Obj03578 *)p)->f3C;
    func_0203FB44(5, (u16)v, (u16)(v >> 16));
    func_020403F4(5);
    func_020403F4(4);
    func_02045C04((struct Rec *)(((struct Obj03578 *)p)->f28));
    func_0201D83C((void *)(((struct Obj03578 *)p)->f2C));
    func_02045808((struct U16Vec *)(((struct Obj03578 *)p)->f38));
    func_02040588(5, 0);
}










void func_021967BC(u8 *p)
{
    if (func_020221A4()) {
        if (((struct Obj12631 *)p)->f8 != 0xC) {
            if (func_02026454((void *)func_02012138((const struct Ctx *)
                    func_02155A90((u8 *)((struct Obj12631 *)p)->f2E4))) == 0)
                func_02196034(p, 0, 0x361);
        } else {
            func_02196034(p, 0, 0x365);
        }
    }
}










void func_02196804(u8 *p)
{
    p[0x306] = 1;
    func_0202208C(0, 0, 0, 0, 6, 1, ((struct Obj05988 *)p)->f10);
    if (((struct Obj05988 *)p)->f8 != 0xC) {
        if (func_02026454((void *)func_02012138((const struct Ctx *)func_02155A90((u8 *)((struct Obj05988 *)p)->f2E4))) != 0) {
            func_02026400((struct Comm *)func_02012138((const struct Ctx *)func_02155A90((u8 *)((struct Obj05988 *)p)->f2E4)));
        }
    }
    func_02196034(p, (void *)func_021967BC, 0x37C);
}










void func_0219686C(u8 *p)
{
    if (((struct Obj09492 *)p)->f8 == 0xC) {
        func_02196034(p, (void *)func_02196804, 0x38C);
        return;
    }
    if (func_02008428((unsigned short *)func_0200873C((void *)func_02155A94((u8 *)(((struct Obj09492 *)p)->f2E4)))) == 1) {
        func_02196034(p, (void *)func_02197700, 0x38F);
        return;
    }
    if (((struct Obj09492 *)p)->f8 - 6 <= 2) {
        func_02196034(p, (void *)func_02196804, 0x394);
        return;
    }
    func_02196034(p, (void *)func_02196A60, 0x397);
}










/*
 * Untraced blob: empty body (bx lr only).
 *
 * Addresses are Black-image addresses.
 */
void func_021968D8(void)
{
}










/*
 * Addresses are Black-image addresses.
 */
void func_021968DC(Obj_021968DC *a)
{
    Req_021968DC r;
    u32 i;

    i = a->mode;
    r.x0 = 0;
    r.a = a;
    r.cb = func_0219686C;
    if (i == 5) {
        i = 0;
    } else if (i == 6) {
        i = 1;
    } else if (i == 7) {
        i = 3;
    }
    func_0204B92C(a->objs[i], 1);
    func_0204BA00(a->objs[i], (const struct Cmd *)(&r));
    func_0204B9A0(a->objs[i]);
    func_02196034(a, func_021968D8, 0x3BF);
}










void func_02196944(u8 *a)
{
    if (func_021975D0(a) != 0 && func_02035C60() != 0) {
        func_021962F4(a);
        func_02196034(a, func_02196A4C, 0x3CB);
    }
}










int func_02196974(u32 s, u8 *p)
{
    int r = 0;

    ((struct Obj03115 *)p)->f300 = s;
    switch (s) {
    case 0:
    case 5:
        func_020061E4(0x73B);
        func_02196034(p, (void *)func_021968DC, 0x3DE);
        r = 1;
        ((struct Obj03115 *)p)->f8 = 1;
        break;
    case 1:
    case 6:
        if ((int)func_0201AA1C(func_02012934(((struct Obj03115 *)p)->f30)) < 2) {
            func_02045CAC((struct MsgBank *)(((struct Obj03115 *)p)->f28), 0x2C, (void *)(((struct Obj03115 *)p)->f38));
            func_02197644(p, 0);
            func_02196034(p, (void *)func_02196944, 0x3EA);
        } else {
            func_020061E4(0x73B);
            ((struct Obj03115 *)p)->f8 = 6;
            func_02196034(p, (void *)func_021968DC, 0x3F0);
            r = 1;
        }
        break;
    case 2:
        func_020061E4(0x73B);
        ((struct Obj03115 *)p)->f8 = 8;
        func_02196034(p, (void *)func_021968DC, 0x3F6);
        r = 1;
        break;
    case 3:
    case 7:
        func_020061E4(0x73B);
        ((struct Obj03115 *)p)->f8 = 7;
        func_02196034(p, (void *)func_021968DC, 0x3FD);
        r = 1;
        break;
    case 4:
        func_020061E4(0x73C);
        ((struct Obj03115 *)p)->f8 = 0xC;
        func_02196034(p, (void *)func_021968DC, 0x404);
        break;
    }
    return r;
}









void func_02196A4C(u8 *a)
{
    if (func_020221A4() != 0) {
        func_02051C88((struct Ctx *)(((struct Obj19634 *)a)->f24));
    }
}









/*
 * State setup: copies an 8-byte record, calls the setup helpers, installs
 * the per-frame handler at +4 and registers the next step.
 *
 * Addresses are Black-image addresses.
 */
void func_02196A60(u8 *p)
{
    struct Rec8 loc = d_021D3FE0;

    func_02197190((Obj_0219707C *)p);
    func_021966B0(p, 0xC);
    func_0219630C(2, (u32 *)&loc, (Obj_0219630C *)p, d_021DDAF4, 0, 0);
    ((struct Obj00093 *)p)->f24 = func_02051B84(d_021D3FF4, (int)func_0219649C, (int)p, ((struct Obj00093 *)p)->f10);
    ((struct Obj00093 *)p)->f4 = func_02196BF8;
    func_02196034(p, func_02196FF0, 0x432);
}







/*
 * State step: picks the next handler from the state word and a status query.
 *
 * Addresses are Black-image addresses.
 */
void func_02196ACC(u8 *p)
{
    if (((struct Obj12632 *)p)->f8 == 5) {
        if (func_0200BBA8(func_0200BAC8(((struct Obj19635 *)(*(u8 * *)&((struct Obj12632 *)p)->f2E4))->f4C)) != 0) {
            func_02196034(p, func_02196E04, 0x443);
        } else {
            func_02196034(p, func_02196804, 0x446);
        }
    } else {
        func_02196034(p, func_02196C68, 0x44D);
    }
}







/*
 * Untraced blob: empty body (bx lr only).
 *
 * Addresses are Black-image addresses.
 */
void func_02196B24(void)
{
}







/*
 * Addresses are Black-image addresses.
 */
void func_02196B28(Obj_021968DC *a)
{
    Req_021968DC r;
    int i;

    i = 0;
    if (a->x8 == 5) {
        i = 1;
    }
    r.x0 = 0;
    r.a = a;
    r.cb = func_02196ACC;
    func_0204B92C(a->objs[i], 1);
    func_0204BA00(a->objs[i], (const struct Cmd *)(&r));
    func_0204B9A0(a->objs[i]);
    func_02196034(a, func_02196B24, 0x471);
}







/*
 * Untraced thunk: registers the record at 0x021966F0.
 *
 * Addresses are Black-image addresses.
 */
void func_02196B7C(u8 *p)
{
    func_02196034((Obj_021968DC *)p, func_021966F0, 0x47A);
}







void func_02196B90(void)
{
}





/*
 * Addresses are Black-image addresses.
 */
void func_02196B94(Obj_021968DC *a)
{
    Req_021968DC r;

    r.x0 = 0;
    r.a = a;
    r.cb = func_02196B7C;
    func_0204B92C(a->objs[a->mode], 1);
    func_0204BA00(a->objs[a->mode], (const struct Cmd *)(&r));
    func_0204B9A0(a->objs[a->mode]);
    func_02196034(a, func_02196B90, 0x492);
}







/*
 * Handler: stores the request at +0x300 and dispatches on it.
 *
 * Addresses are Black-image addresses.
 */
int func_02196BF8(u32 v, u8 *p)
{
    int r = 1;

    ((struct Obj09493 *)p)->f300 = v;
    switch (v) {
    case 0:
        func_020061E4(0x73B);
        func_02196034((Obj_021968DC *)p, func_02196B28, 0x4A3);
        break;
    case 1:
        func_020061E4(0x73B);
        ((struct Obj09493 *)p)->f8 = 5;
        func_02196034((Obj_021968DC *)p, func_02196B28, 0x4A9);
        break;
    case 2:
        func_020061E4(0x73C);
        ((struct Obj09493 *)p)->f8 = 0xC;
        func_02196034((Obj_021968DC *)p, func_02196B94, 0x4AF);
        break;
    default:
        r = 1;
        break;
    }
    return r;
}







/*
 * State setup: like func_02196A60 with a 16-byte record and other handlers.
 *
 * Addresses are Black-image addresses.
 */
void func_02196C68(u8 *p)
{
    struct Rec16 loc = d_021D4080;

    func_0219728C(p);
    func_021966B0(p, 0xD);
    func_0219630C(4, (u32 *)&loc, (Obj_0219630C *)p, d_021DDB44, 0, 0);
    ((struct Obj00093 *)p)->f24 = func_02051B84(d_021D4034, (int)func_0219649C, (int)p, ((struct Obj00093 *)p)->f10);
    ((struct Obj00093 *)p)->f4 = func_02196F44;
    func_02196034((Obj_021968DC *)p, func_02196FF0, 0x4CC);
}







/*
 * State step: registers the next handler through func_02196034.
 *
 * Addresses are Black-image addresses.
 */
void func_02196CD8(u8 *p)
{
    if (((struct Obj09494 *)p)->fC == 2) {
        if (((struct Obj09494 *)p)->f8 == 5) {
            ((struct Obj09494 *)p)->f8 = 1;
            func_02196034((Obj_021968DC *)p, func_02196A60, 0x4DD);
        } else {
            func_02196034((Obj_021968DC *)p, func_02196C68, 0x4E1);
        }
    } else {
        func_02196034((Obj_021968DC *)p, func_02196804, 0x4E5);
    }
}







/*
 * Untraced blob: empty body (bx lr only).
 *
 * Addresses are Black-image addresses.
 */
void func_02196D20(void)
{
}




/*
 * Addresses are Black-image addresses.
 */
void func_02196D24(Obj_021968DC *a)
{
    Tbl3 t = d_021D3F9C;
    Req_021968DC r;
    int i;

    i = t.v[a->xc];
    r.x0 = 0;
    r.a = a;
    r.cb = func_02196CD8;
    func_0204B92C(a->objs[i], 1);
    func_0204BA00(a->objs[i], (const struct Cmd *)(&r));
    func_0204B9A0(a->objs[i]);
    func_02196034(a, func_02196D20, 0x504);
}







/*
 * Untraced thunk: tail call on the word at +0x24 into the ARM9 image.
 *
 * Addresses are Black-image addresses.
 */
void func_02196D88(u8 *p)
{
    func_02051C88((struct Ctx *)(((struct Obj17948 *)p)->f24));
}







/*
 * Handler: stores the request at +0x300 and dispatches on it.
 *
 * Addresses are Black-image addresses.
 */
int func_02196D94(u32 v, u8 *p)
{
    int r = 0;

    ((struct Obj07463 *)p)->f300 = v;
    switch (v) {
    case 1:
        func_020061E4(0x73B);
        ((struct Obj07463 *)p)->fC = 0;
        func_02196034((Obj_021968DC *)p, func_02196D24, 0x524);
        r = 1;
        break;
    case 0:
        func_020061E4(0x73B);
        r = 1;
        ((struct Obj07463 *)p)->fC = 1;
        func_02196034((Obj_021968DC *)p, func_02196D24, 0x52A);
        break;
    case 2:
        func_020061E4(0x73C);
        ((struct Obj07463 *)p)->fC = 2;
        func_02196034((Obj_021968DC *)p, func_02196D24, 0x530);
        break;
    }
    return r;
}







/*
 * State setup: like func_02196A60 with other handlers.
 *
 * Addresses are Black-image addresses.
 */
void func_02196E04(u8 *p)
{
    struct Rec8 loc = d_021D3FD8;

    func_021973A0(p);
    func_021966B0(p, 0xD);
    func_0219630C(2, (u32 *)&loc, (Obj_0219630C *)p, d_021DDAF4, 0, 0);
    ((struct Obj00093 *)p)->f24 = func_02051B84(d_021D4004, (int)func_0219649C, (int)p, ((struct Obj00093 *)p)->f10);
    ((struct Obj00093 *)p)->f4 = func_02196D94;
    func_02196034((Obj_021968DC *)p, func_02196D88, 0x54D);
}







/*
 * State step: picks the next handler from the state word and a status query.
 *
 * Addresses are Black-image addresses.
 */
void func_02196E70(u8 *p)
{
    if (((struct Obj12633 *)p)->f8 == 0xC) {
        func_02196034((Obj_021968DC *)p, func_02196A60, 0x558);
    } else {
        if (func_0200BBA8(func_0200BAC8(((struct Obj19636 *)(*(u8 * *)&((struct Obj12633 *)p)->f2E4))->f4C)) != 0) {
            func_02196034((Obj_021968DC *)p, func_02196E04, 0x55D);
        } else {
            func_02196034((Obj_021968DC *)p, func_02196804, 0x560);
        }
    }
}





/*
 * Untraced blob: empty body (bx lr only).
 *
 * Addresses are Black-image addresses.
 */
void func_02196EC8(void)
{
}





/*
 * Addresses are Black-image addresses.
 */
void func_02196ECC(Obj_021968DC *a)
{
    Req_021968DC r;
    int i;

    switch (a->x8) {
    case 1:
        i = 0;
        break;
    case 2:
        i = 1;
        break;
    case 3:
        i = 2;
        break;
    case 4:
        i = 3;
        break;
    default:
        i = 4;
        break;
    }
    r.x0 = 0;
    r.a = a;
    r.cb = func_02196E70;
    func_0204B92C((struct Obj_021968DC *)(a->objs[i]), 1);
    func_0204BA00(a->objs[i], (const struct Cmd *)(&r));
    func_0204B9A0(a->objs[i]);
    func_02196034((Obj_021968DC *)a, func_02196EC8, 0x58F);
}







/*
 * Handler: stores the request at +0x300 and dispatches on it (five cases).
 *
 * Addresses are Black-image addresses.
 */
int func_02196F44(u32 v, u8 *p)
{
    int r = 0;

    ((struct Obj05003 *)p)->f300 = v;
    switch (v) {
    case 0:
        func_020061E4(0x73B);
        r = 1;
        ((struct Obj05003 *)p)->f8 = 1;
        func_02196034((Obj_021968DC *)p, func_02196ECC, 0x5B1);
        break;
    case 1:
        func_020061E4(0x73B);
        ((struct Obj05003 *)p)->f8 = 2;
        func_02196034((Obj_021968DC *)p, func_02196ECC, 0x5B7);
        r = 1;
        break;
    case 2:
        func_020061E4(0x73B);
        ((struct Obj05003 *)p)->f8 = 3;
        func_02196034((Obj_021968DC *)p, func_02196ECC, 0x5BD);
        r = 1;
        break;
    case 3:
        func_020061E4(0x73B);
        ((struct Obj05003 *)p)->f8 = 4;
        func_02196034((Obj_021968DC *)p, func_02196ECC, 0x5C3);
        r = 1;
        break;
    case 4:
        func_020061E4(0x73C);
        ((struct Obj05003 *)p)->f8 = 0xC;
        func_02196034((Obj_021968DC *)p, func_02196ECC, 0x5C9);
        break;
    }
    return r;
}








/*
 * Untraced thunk: tail call on the word at +0x24 into the ARM9 image.
 *
 * Addresses are Black-image addresses.
 */
void func_02196FF0(u8 *p)
{
    func_02051C88((struct Ctx *)(((struct Obj17949 *)p)->f24));
}








/*
 * Builds three objects on one owner handle and stores them at +0x274,
 * +0x27C and +0x284.
 *
 * Addresses are Black-image addresses.
 */
void func_02196FFC(u8 *p)
{
    void *h = func_020490F4(0x1D, ((struct Obj04220 *)p)->f10);

    ((struct Obj04220 *)p)->f27C = func_0204A6C8(h, 5, 0, 1, ((struct Obj04220 *)p)->f10);
    ((struct Obj04220 *)p)->f274 = func_0204AC18(h, 3, 1, 0, 0, 0xA, ((struct Obj04220 *)p)->f10);
    ((struct Obj04220 *)p)->f284 = func_0204AF28(h, 7, 0x10, ((struct Obj04220 *)p)->f10);
    func_02049238(h);
}






void func_02197058(Obj_02196F44 *a)
{
    int i;

    for (i = 0; i < 5; i++) {
        if (a->arr[i] != 0) {
            func_0204B3B4((struct Obj_02196F44 *)(a->arr[i]));
            a->arr[i] = 0;
        }
    }
}




void func_0219707C(u8 *p)
{
    B5 xs = d_021D3FC8;
    B5 ys = d_021D3FB0;
    B5 zs = d_021D3FA8;
    Pos pos;
    int i;

    func_02197058((Obj_02196F44 *)p);
    for (i = 0; i < 5; i++) {
        pos.x = xs.v[i];
        pos.y = ys.v[i];
        pos.z = zs.v[i];
        pos.a = 0;
        pos.b = 1;
        *(u32 *)(p + i * 4 + 0x294) = (u32)func_0204B294((void *)*(u32 *)&((struct Obj00093 *)p)->f26C, *(u32 *)&((struct Obj00093 *)p)->f27C,
            *(u32 *)&((struct Obj00093 *)p)->f274, *(u32 *)&((struct Obj00093 *)p)->f284, &pos, 1, ((struct Obj00093 *)p)->f10);
        func_0204B92C((struct Obj_021968DC *)((struct Obj_0219707C *)*(u32 *)(p + i * 4 + 0x294)), 0);
        func_0204B3DC((struct Obj_0219707C *)*(u32 *)(p + i * 4 + 0x294), 1);
        func_0204B688((struct Actor *)(*(u32 *)(p + i * 4 + 0x294)), 1);
    }
}



void func_02197190(Obj_0219707C *p)
{
    Tbl3 x0 = d_021D3FA0;
    Tbl3 x1 = d_021D3F8C;
    Tbl3 x2 = d_021D3F94;
    Rect r;
    int i;

    func_02197058((Obj_02196F44 *)p);
    for (i = 0; i < 3; i++) {
        r.a = x0.v[i];
        r.b = x1.v[i];
        r.c = x2.v[i];
        r.d = 0;
        r.e = 1;
        p->sub.arr[i] = (int)func_0204B294((void *)p->sub.f0, p->sub.f10, p->sub.f8, p->sub.f18, &r, 1, p->f10);
        func_0204B92C((struct Obj_021968DC *)((struct Obj_0219707C *)p->sub.arr[i]), 0);
        func_0204B3DC((struct Obj_0219707C *)p->sub.arr[i], 1);
        func_0204B688((struct Actor *)p->sub.arr[i], 1);
    }
}
