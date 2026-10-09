/*
 * file:     gsync_state.c
 * unit:     yes
 * function: func_021D4240, func_021D4244, func_021D424C, func_021D4384, func_021D43B8, func_021D4440, func_021D449C, func_021D44F4, func_021D451C, func_021D45F0, func_021D45F4, func_021D4730, func_021D4778, func_021D478C, func_021D4884, func_021D4A04, func_021D4A64, func_021D4AB4, func_021D4AFC, func_021D4B44, func_021D4BA8, func_021D4C24, func_021D4C4C, func_021D4CA0, func_021D4CBC, func_021D4D40, func_021D4DA4, func_021D4E34, func_021D4E64, func_021D4E7C, func_021D4EF0, func_021D4FAC, func_021D4FB8, func_021D4FEC, func_021D5020, func_021D504C, func_021D50F8, func_021D5120, func_021D5128, func_021D5320, func_021D53D0, func_021D54E0, func_021D54F4, func_021D562C, func_021D5644, func_021D56FC, func_021D57B8, func_021D57D0, func_021D580C, func_021D584C, func_021D5890, func_021D5950, func_021D5960, func_021D59E4, func_021D5A60, func_021D5A7C, func_021D5AB0, func_021D5AC0, func_021D5B10, func_021D5B70, func_021D5BA0, func_021D5BA8, func_021D5BD4, func_021D5C0C, func_021D5C2C, func_021D5C64, func_021D5C9C, func_021D5CAC, func_021D5CF8, func_021D5D24, func_021D5D58, func_021D5D7C, func_021D5D8C, func_021D5D94, func_021D5E60, func_021D5E8C, func_021D5F4C, func_021D60F8, func_021D614C, func_021D62A8, func_021D62B4, func_021D62BC, func_021D62D0, func_021D62E0, func_021D62F8, func_021D634C, func_021D63D4, func_021D63E4, func_021D6404, func_021D6458, func_021D651C, func_021D652C, func_021D6548, func_021D65F4, func_021D6650, func_021D6678, func_021D66D0, func_021D6720, func_021D679C, func_021D67B4, func_021D6830, func_021D6934, func_021D6A70, func_021D6AA8, func_021D6AB8, func_021D6C48, func_021D6C90, func_021D6CD8, func_021D6D5C, func_021D6E08, func_021D6E70, func_021D6EA4, func_021D6EBC, func_021D6EE0, func_021D6EE8, func_021D6F04, func_021D6F44, func_021D6F70, func_021D6FF0, func_021D706C, func_021D7088, func_021D70BC, func_021D7130, func_021D7180, func_021D7204, func_021D7224, func_021D72D8, func_021D7390, func_021D73D8, func_021D7430, func_021D746C, func_021D751C, func_021D7560, func_021D758C, func_021D75D0, func_021D768C, func_021D76B8, func_021D76F0, func_021D7798, func_021D77C4, func_021D7858, func_021D78C0, func_021D7910, func_021D7960, func_021D79A4, func_021D7A18, func_021D7A5C, func_021D7B68, func_021D7BDC, func_021D7C54, func_021D7CB4, func_021D7CEC, func_021D7D18, func_021D7DE8, func_021D7E20, func_021D7E58, func_021D7F5C, func_021D7F9C, func_021D80B8, func_021D8130, func_021D8154, func_021D81B4, func_021D81E4, func_021D8210, func_021D8244, func_021D8270, func_021D8304, func_021D834C, func_021D83A4, func_021D83C8, func_021D840C, func_021D8448, func_021D8490, func_021D8520, func_021D8590, func_021D85C4, func_021D85F0, func_021D8624, func_021D8650, func_021D8790, func_021D87F8, func_021D885C, func_021D88A0, func_021D88C0, func_021D8958, func_021D8A38, func_021D8A7C, func_021D8A9C, func_021D8B0C, func_021D8B7C, func_021D8C04, func_021D8D08, func_021D8D98, func_021D8DFC, func_021D8E28, func_021D8E68, func_021D8E98, func_021D8EC4, func_021D8F3C, func_021D8F58, func_021D8FBC, func_021D9158, func_021D920C, func_021D92B8, func_021D92CC, func_021D9404, func_021D941C, func_021D9514, func_021D95B4, func_021D95F0, func_021D9634, func_021D9670, func_021D9730, func_021D97B0, func_021D97CC, func_021D9844, func_021D9918, func_021D9958, func_021D9A14, func_021D9A1C, func_021D9AE8, func_021D9D34, func_021D9D3C, func_021D9F40, func_021D9FB0, func_021D9FD4, func_021DA034, func_021DA03C, func_021DA054, func_021DA090, func_021DA0B8, func_021DA0E4, func_021DA110, func_021DA138, func_021DA16C, func_021DA1A0, func_021DA1C8, func_021DA1EC, func_021DA244, func_021DA268, func_021DA290, func_021DA2DC, func_021DA308, func_021DA328, func_021DA3A0, func_021DA408, func_021DA434, func_021DA45C, func_021DA478, func_021DA54C
 * address:  0x021D4240
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021DA690 0x021DA690 data a4
 *   d_021DA6B0 0x021DA6B0 data a4
 *   d_021DA6D0 0x021DA6D0 data a4
 *   d_021DA6F0 0x021DA6F0 data a4
 *   d_021DA710 0x021DA710 data a4
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204047C 0x0204047C arm
 *   func_02040588 0x02040588 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 *   func_0202F038 0x0202F038 thumb
 *   func_0202EE8C 0x0202EE8C thumb
 *   func_0203CD98 0x0203CD98 arm
 *   func_020414EC 0x020414EC arm
 *   func_0204BA10 0x0204BA10 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_020452E8 0x020452E8 arm
 *   func_02085D3C 0x02085D3C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201DD68  0x0201DD68  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_02049B40  0x02049B40  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D42C  0x0201D42C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02051C6C  0x02051C6C  arm
 *   func_02041B6C 0x02041B6C arm
 *   d_021DA638 0x021DA638 data a1
 *   d_021DA634 0x021DA634 data a1
 *   d_021DA63C 0x021DA63C data a1
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B688 0x0204B688 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   d_021DA9D0 0x021DA9D0 data a4
 *   func_02051B84 0x02051B84 arm
 *   func_021DA9C0 0x021DA9C0 data a4
 *   d_021DA640 0x021DA640 data a4
 *   d_021DA648 0x021DA648 data a4
 *   func_02040DA8 0x02040DA8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020403F4 0x020403F4 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045808 0x02045808 arm
 *   func_020221A4 0x020221A4 thumb
 *   func_02012138 0x02012138 thumb
 *   func_02026454 0x02026454 thumb
 *   func_02035C60 0x02035C60 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0204BA00 0x0204BA00 arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B898 0x0204B898 arm
 *   func_02051C88  0x02051C88  arm
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 *   func_02021FD8 0x02021FD8 thumb
 *   func_02021730 0x02021730 thumb
 *   func_020862F0 0x020862F0 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_02027778 0x02027778 thumb
 *   func_02027CD8 0x02027CD8 thumb
 *   func_020286C4 0x020286C4 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_02035C38 0x02035C38 arm
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02041570 0x02041570 arm
 *   func_02012DD0 0x02012DD0 thumb
 *   func_02012DAC 0x02012DAC thumb
 *   func_0204A648 0x0204A648 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204363C 0x0204363C arm
 *   func_0207D534 0x0207D534 arm
 *   func_0207D46C 0x0207D46C arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_02030734 0x02030734 arm
 *   func_0203101C 0x0203101C arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0203D34C 0x0203D34C arm
 *   func_020355D8 0x020355D8 arm
 *   d_021DA9F0 0x021DA9F0 data a4
 *   d_021DA680 0x021DA680 data a4
 *   d_021DA658 0x021DA658 data a4
 *   d_021DAA20 0x021DAA20 data a1
 *   func_02012204 0x02012204 thumb
 *   func_020310C4 0x020310C4 arm
 *   func_02040618 0x02040618 arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02031140 0x02031140 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   d_021DAA30 0x021DAA30 data a1
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0207D658 0x0207D658 arm
 *   func_0200F7DC 0x0200F7DC thumb
 *   d_021DAC20 0x021DAC20 data a4
 *   func_02034714 0x02034714 arm
 *   d_021DAA40 0x021DAA40 data ov123 a1
 *   d_021DAA54 0x021DAA54 data ov123 a1
 *   g_021DAC20 0x021DAC20 data ov123 a4
 *   func_02156DE0 0x02156DE0 thumb ov009
 *   func_021C5B80 0x021C5B80 arm ov114
 *   func_021C5928 0x021C5928 arm ov114
 *   d_021DAA58 0x021DAA58 data a1
 *   d_021DAA60 0x021DAA60 data a1
 *   OS_SNPrintf 0x0208D80C arm
 *   func_021C5C04 0x021C5C04 arm ov114
 *   d_021DAA74 0x021DAA74 data a1
 *   func_021C5DB4 0x021C5DB4 arm ov114
 *   func_021C5C38 0x021C5C38 arm ov114
 *   func_021C5CFC 0x021C5CFC arm ov114
 *   func_021C5AB8  0x021C5AB8  arm  ov114
 *   ov067_id 0x00000043 data
 *   func_02034AC4 0x02034AC4 arm
 *   d_021DAB68 0x021DAB68 data a1
 *   d_021DAA9C 0x021DAA9C data a4
 *   d_020A1464 0x020A1464 data a4
 *   d_021DAA78 0x021DAA78 data a4
 *   func_02034A5C 0x02034A5C arm
 *   ov_id 0x00000043 data
 *   d_021DA758 0x021DA758 data a4
 *   func_0207E3D0 0x0207E3D0 arm
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B570 0x0204B570 arm
 *   d_021DAACC 0x021DAACC data a4
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   d_021DA738 0x021DA738 data a4
 *   d_021DA748 0x021DA748 data a4
 *   func_0201BA68 0x0201BA68 thumb
 *   func_0201BBE8 0x0201BBE8 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   d_021DAA88 0x021DAA88 data a2
 *   func_02005624 0x02005624 thumb
 *   func_02024230 0x02024230 thumb
 *   _fflt 0x0209BDBC arm
 *   _f2d 0x0209BD38 arm
 *   _dmul 0x0209B2E8 arm
 *   _d2f 0x0209B64C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B5AC 0x0204B5AC arm
 *   d_021DA730 0x021DA730 data a2
 *   d_021DA750 0x021DA750 data a4
 *   d_021DA734 0x021DA734 data a2
 *   d_021DA740 0x021DA740 data a4
 *   d_020A1B38 0x020A1B38 data a2
 *   func_0204B454 0x0204B454 arm
 *   func_0204B5C0 0x0204B5C0 arm
 *   func_020056EC 0x020056EC thumb
 *   func_02049250 0x02049250 arm
 *   func_02020E60 0x02020E60 thumb
 *   func_02062A98 0x02062A98 arm
 *   func_02062A4C 0x02062A4C arm
 *   func_02019D30 0x02019D30 thumb
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_0201BABC 0x0201BABC thumb
 *   func_0204B7C8 0x0204B7C8 arm
 *   func_0207E51C 0x0207E51C arm
 *   func_020362DC  0x020362DC  arm
 *   func_02012E08  0x02012E08  thumb
 *   func_021B9774 0x021B9774 thumb ov114
 *   d_021DA844 0x021DA844 data a4
 *   func_02005E9C 0x02005E9C thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005DF8 0x02005DF8 thumb
 *   func_02005E64  0x02005E64  thumb
 *   func_02005D90  0x02005D90  thumb
 *   d_021DAB78 0x021DAB78 data a1
 *   func_02009290 0x02009290 thumb
 *   func_020092F8 0x020092F8 thumb
 *   func_020093D4 0x020093D4 thumb
 *   func_021B99DC 0x021B99DC thumb ov114
 *   func_021B9790 0x021B9790 thumb ov114
 *   func_021B97F4 0x021B97F4 thumb ov114
 *   func_021B95D4 0x021B95D4 thumb ov114
 *   func_021B973C 0x021B973C thumb ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_021BE79C 0x021BE79C arm ov114
 *   func_020092D0 0x020092D0 thumb
 *   func_020090F8 0x020090F8 thumb
 *   func_0203F1FC 0x0203F1FC arm
 *   func_02009108 0x02009108 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_02012E7C 0x02012E7C thumb
 *   func_0200734C 0x0200734C thumb
 *   func_0200E8E0 0x0200E8E0 thumb
 *   func_0200C5F8 0x0200C5F8 thumb
 *   d_021DAB88 0x021DAB88 data a1
 *   d_021DAB90 0x021DAB90 data a1
 *   d_021DAB9C 0x021DAB9C data a1
 *   func_0200C6E4 0x0200C6E4 thumb
 *   func_02009390 0x02009390 thumb
 *   func_020093A8 0x020093A8 thumb
 *   func_020093F0 0x020093F0 thumb
 *   func_0203EFC8 0x0203EFC8 arm
 *   func_02009348 0x02009348 thumb
 *   func_0202A128 0x0202A128 thumb
 *   func_02019C90 0x02019C90 thumb
 *   func_02019D58 0x02019D58 thumb
 *   func_0202A19C 0x0202A19C thumb
 *   func_0200E0B0 0x0200E0B0 thumb
 *   func_0200E1A8 0x0200E1A8 thumb
 *   func_0202A170 0x0202A170 thumb
 *   func_020093D0 0x020093D0 thumb
 *   func_020092E0 0x020092E0 thumb
 *   func_020071D8 0x020071D8 thumb
 *   func_020093C8 0x020093C8 thumb
 *   func_0203F4E4 0x0203F4E4 arm
 *   func_0203F540 0x0203F540 arm
 *   func_0203C9AC 0x0203C9AC arm
 *   func_0203C938 0x0203C938 arm
 *   func_020093D8 0x020093D8 thumb
 *   func_02009428 0x02009428 thumb
 *   func_020185F0 0x020185F0 thumb
 *   func_02009294 0x02009294 thumb
 *   func_021B9838  0x021B9838  thumb  ov114
 *   ov114_id 0x00000072 data
 *   func_020092EC 0x020092EC thumb
 *   func_021B9800 0x021B9800 thumb ov114
 *   func_02156DC4 0x02156DC4 thumb ov009
 *   d_021DABA4 0x021DABA4 data a1
 *   func_0200F7C0 0x0200F7C0 thumb
 *   func_02157170 0x02157170 thumb ov009
 *   func_0200FB24 0x0200FB24 thumb
 *   d_021DABA8 0x021DABA8 data ov123 a1
 *   func_0204581C 0x0204581C arm
 *   func_02045AFC 0x02045AFC arm
 *   d_021DA868 0x021DA868 data a2
 *   d_021DA864 0x021DA864 data a2
 *   d_021DABFC 0x021DABFC data a1
 *   d_021DABCC 0x021DABCC data a4
 *   d_021DABBC 0x021DABBC data a4
 *   d_021DA8A8      0x021DA8A8  data
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02021F64 0x02021F64 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_0202208C 0x0202208C thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_02009448 0x02009448 thumb
 */
#include "../../matched/include/Obj00273.h"
#include "../../matched/include/Obj00471.h"
#include "../../matched/include/Obj13968.h"
#include "../../matched/include/Obj10434.h"
#include "../../matched/include/Obj01543.h"
#include "../../matched/include/Obj13969.h"
#include "../../matched/include/Obj10435.h"
#include "../../matched/include/Obj06458.h"
#include "../../matched/include/Obj05360.h"
#include "../../matched/include/Obj13970.h"
#include "../../matched/include/Obj00626.h"
#include "../../matched/include/Obj04495.h"
#include "../../matched/include/Obj02473.h"
#include "../../matched/include/Obj22939.h"
#include "../../matched/include/Obj00590.h"
#include "../../matched/include/Obj06459.h"
#include "../../matched/include/Obj01733.h"
#include "../../matched/include/Obj00772.h"
#include "../../matched/include/Obj22940.h"
#include "../../matched/include/Obj10436.h"
#include "../../matched/include/Obj00499.h"
#include "../../matched/include/Obj13971.h"
#include "../../matched/include/Obj01154.h"
#include "../../matched/include/Obj01933.h"
#include "../../matched/include/Obj04496.h"
#include "../../matched/include/Obj03265.h"
#include "../../matched/include/Obj01734.h"
#include "../../matched/include/Obj13972.h"
#include "../../matched/include/Obj05361.h"
#include "../../matched/include/Obj05362.h"
#include "../../matched/include/Obj13973.h"
#include "../../matched/include/Obj04497.h"
#include "../../matched/include/Obj22941.h"
#include "../../matched/include/Obj13974.h"
#include "../../matched/include/Obj22942.h"
#include "../../matched/include/Obj22943.h"
#include "../../matched/include/Obj10437.h"
#include "../../matched/include/Obj22944.h"
#include "../../matched/include/Obj22945.h"
#include "../../matched/include/Obj10438.h"
#include "../../matched/include/Obj22946.h"
#include "../../matched/include/Obj13975.h"
#include "../../matched/include/Obj06460.h"
#include "../../matched/include/Obj10439.h"
#include "../../matched/include/Obj06461.h"
#include "../../matched/include/Obj13976.h"
#include "../../matched/include/Obj22947.h"
#include "../../matched/include/Obj04498.h"
#include "../../matched/include/Obj03267.h"
#include "../../matched/include/Obj04499.h"
#include "../../matched/include/Obj06462.h"
#include "../../matched/include/Obj22948.h"
#include "../../matched/include/Obj00343.h"
#include "../../matched/include/Obj03266.h"
#include "../../matched/include/Obj02836.h"
#include "../../matched/include/Obj22949.h"
#include "../../matched/include/Obj10440.h"
#include "../../matched/include/Obj02181.h"
#include "../../matched/include/Obj22950.h"
#include "../../matched/include/Obj13977.h"
#include "../../matched/include/Obj08108.h"
#include "../../matched/include/Obj08109.h"
#include "../../matched/include/Obj13978.h"
#include "../../matched/include/Obj13979.h"
#include "../../matched/include/Obj10441.h"
#include "../../matched/include/Obj13980.h"
#include "../../matched/include/Obj03268.h"
#include "../../matched/include/Obj13981.h"
#include "../../matched/include/Obj22951.h"
#include "../../matched/include/Obj02474.h"
#include "../../matched/include/Obj01544.h"
#include "../../matched/include/Obj00063.h"
#include "../../matched/include/Obj10442.h"
#include "../../matched/include/Obj22952.h"
#include "../../matched/include/Obj13982.h"
#include "../../matched/include/Obj22953.h"
#include "../../matched/include/Obj13983.h"
#include "../../matched/include/Obj22954.h"
#include "../../matched/include/Obj22955.h"
#include "../../matched/include/Obj13984.h"
#include "../../matched/include/Obj10443.h"
#include "../../matched/include/Obj05363.h"
#include "../../matched/include/Obj02182.h"
#include "../../matched/include/Obj22956.h"
#include "../../matched/include/Obj22957.h"
#include "../../matched/include/Obj22958.h"
#include "../../matched/include/Obj06463.h"
#include "../../matched/include/Obj03792.h"
#include "../../matched/include/Obj10444.h"
#include "../../matched/include/Obj01736.h"
#include "../../matched/include/Obj01254.h"
#include "../../matched/include/Obj06464.h"
#include "../../matched/include/Obj04500.h"
#include "../../matched/include/Obj05364.h"
#include "../../matched/include/Obj03269.h"
#include "../../matched/include/Obj06465.h"
#include "../../matched/include/Obj13985.h"
#include "../../matched/include/Obj08110.h"
#include "../../matched/include/Obj13986.h"
#include "../../matched/include/Obj03793.h"
#include "../../matched/include/Obj22959.h"
#include "../../matched/include/Obj08111.h"
#include "../../matched/include/Obj13987.h"
#include "../../matched/include/Obj02475.h"
#include "../../matched/include/Obj22960.h"
#include "../../matched/include/Obj10445.h"
#include "../../matched/include/Obj02837.h"
#include "../../matched/include/Obj03270.h"
#include "../../matched/include/Obj08112.h"
#include "../../matched/include/Obj13988.h"
#include "../../matched/include/Obj05365.h"
#include "../../matched/include/Obj13989.h"
#include "../../matched/include/Obj01934.h"
#include "../../matched/include/Obj03271.h"
#include "../../matched/include/Obj05366.h"
#include "../../matched/include/Obj10446.h"
#include "../../matched/include/Obj05367.h"
#include "../../matched/include/Obj22962.h"
#include "../../matched/include/Obj03794.h"
#include "../../matched/include/Obj13991.h"
#include "../../matched/include/Obj05368.h"
#include "../../matched/include/Obj22964.h"
#include "../../matched/include/Obj03795.h"
#include "../../matched/include/Obj22965.h"
#include "../../matched/include/Obj13992.h"
#include "../../matched/include/Obj22966.h"
#include "../../matched/include/Obj13993.h"
#include "../../matched/include/Obj03796.h"
#include "../../matched/include/Obj06466.h"
#include "../../matched/include/Obj03797.h"
#include "../../matched/include/Obj22967.h"
#include "../../matched/include/Obj10447.h"
#include "../../matched/include/Obj13994.h"
#include "../../matched/include/Obj06467.h"
#include "../../matched/include/Obj22968.h"
#include "../../matched/include/Obj10448.h"
#include "../../matched/include/Obj22969.h"
#include "../../matched/include/Obj13995.h"
#include "../../matched/include/Obj22970.h"
#include "../../matched/include/Obj13996.h"
#include "../../matched/include/Obj22971.h"
#include "../../matched/include/Obj22972.h"
#include "../../matched/include/Obj22973.h"
#include "../../matched/include/Obj22974.h"
#include "../../matched/include/Obj22975.h"
#include "../../matched/include/Obj08113.h"
#include "../../matched/include/Obj10450.h"
#include "../../matched/include/Obj22976.h"
#include "../../matched/include/Obj22977.h"
#include "../../matched/include/Obj22978.h"
#include "../../matched/include/Obj22979.h"
#include "../../matched/include/Obj22980.h"
#include "../../matched/include/Obj06468.h"
#include "../../matched/include/Obj13997.h"
#include "../../matched/include/Obj22981.h"
#include "../../matched/include/Obj02183.h"
#include "../../matched/include/Obj03272.h"
#include "../../matched/include/Obj05369.h"
#include "../../matched/include/Obj22982.h"
#include "../../matched/include/Obj03798.h"
#include "../../matched/include/Obj10451.h"
#include "../../matched/include/Obj06469.h"
#include "../../matched/include/Obj08114.h"
#include "../../matched/include/Obj10452.h"
#include "../../matched/include/Obj01545.h"
#include "../../matched/include/Obj08115.h"
#include "../../matched/include/Obj02476.h"
#include "../../matched/include/Obj01059.h"
#include "../../matched/include/Obj03799.h"
#include "../../matched/include/Obj01406.h"
#include "../../matched/include/Obj22983.h"
#include "../../matched/include/Obj00990.h"
#include "../../matched/include/Obj10453.h"
#include "../../matched/include/Obj00500.h"
#include "../../matched/include/Obj13998.h"
#include "../../matched/include/Obj00534.h"
#include "../../matched/include/Obj02477.h"
#include "../../matched/include/Obj04501.h"
#include "../../matched/include/Obj06470.h"
#include "../../matched/include/Obj03800.h"
#include "../../matched/include/Obj03801.h"
#include "../../matched/include/Obj13999.h"
#include "../../matched/include/Obj01737.h"
#include "../../matched/include/Obj03273.h"
#include "../../matched/include/Obj05370.h"
#include "../../matched/include/Obj03802.h"
#include "../../matched/include/Obj03274.h"
#include "../../matched/include/Obj10454.h"
#include "../../matched/include/Obj03804.h"
#include "../../matched/include/Obj22984.h"
#include "../../matched/include/Obj22985.h"
#include "../../matched/include/Obj22986.h"
#include "../../matched/include/Obj10455.h"
#include "../../matched/include/Obj10456.h"
#include "../../matched/include/Obj14000.h"
#include "../../matched/include/Obj14001.h"
#include "../../matched/include/Obj08116.h"
#include "../../matched/include/Obj08117.h"
#include "../../matched/include/Obj03803.h"
#include "../../matched/include/Obj22987.h"
#include "../../matched/include/Obj14002.h"
#include "../../matched/include/Obj06471.h"
#include "../../matched/include/Obj10457.h"
#include "../../matched/include/Obj22988.h"
#include "../../matched/include/Obj22989.h"
#include "../../matched/include/Obj08118.h"
#include "../../matched/include/Obj08119.h"
#include "../../matched/include/Obj02478.h"
#include "../../matched/include/Obj03275.h"
#include "../../matched/include/Obj03276.h"
#include "../../matched/include/Obj22990.h"

struct Ctx;
struct Comm;
struct TaskMenu;
struct Actor;
struct Descriptor;
struct MsgBank;
struct Obj;
struct Cfg;
struct CharBuf;
struct StrObj;
struct GfFont;
struct U16Vec;
struct Rec;
struct Cmd;
struct PalAnmSlot;
struct Chan02021FD8;
struct TaskMenuTmpl;
struct Rec3;
struct Big;
struct Sub020071E4Ctrl;
struct Obj0203159C;
struct Bank;
struct R;
struct Tcbl;
struct DispConfig;
struct DispVram;
struct IcaAnime;
struct PrintSys;
struct Node;
struct S02031140;
struct S020315D4;
struct TaskMenuState;
struct WordSet;
struct Blk;
struct Vec2;
struct PtS;
struct ArcFile;
struct NitroFileHeader;
struct Struct36;
struct Sub02009210Obj;
struct Sub02009448Obj;
struct Sub02007454Entry;
struct Obj02181;
struct Sub02007324Ctrl;
struct Sub020090B0Obj;
struct MusicalDist;
struct Sub02009210Ent;
struct Sub0200852CObj;
struct Ctrl020071D8;
struct Sub02008AECSession;
struct Sub02008C20Obj;
struct Mon;
struct Sub020079BCEntry;
struct Sav;
struct Sub020075B0Entry;
struct BigObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct BgTemplate_021D4240 {
    u32 unk_00, unk_04, bufSize, unk_0c;
    u8 unk_10, unk_11, unk_12, unk_13;
    u32 unk_14;
    u8 unk_18, unk_19, unk_1a, unk_1b;
    u32 unk_1c;
};

typedef struct {
    char pad00[8];
    int f08;
    u16 f0c;
    char pad0e[0x256];
    void *f264;
    char pad268[0x24];
    int f28c;
} Object_021D4440;

typedef short          s16_021D4240;

typedef struct {
    u32 a, b, c, d;
} Rec;

typedef struct {
    u8 pad0[0xC];
    u16 heap;
    u8 pad1[2];
    void *obj[4];
    void *res;
    void *bank;
    u8 pad2[8];
    void *font;
    u8 pad3[4];
    void *str;
    u8 pad4[0x25C - 0x3C];
    int n;
} Own;

typedef struct {
    char pad00[0x10];
    void *f10[4];
    void *f20;
    char pad24[0x238];
    int f25c;
} Object_021D4730;

typedef struct Callback Callback;

struct Callback { u32 first; int (*run)(void *,Callback *); };

struct Point_021D4240 { u16 x, y, z; u8 a, b; };

struct Triple { u8 v[3]; };

typedef signed int     s32;

typedef struct { u16 value; char *object; void (*callback)(char *); } NotifyCallback;

typedef struct { u32 heap; u8 mode; void *data; int flag; u8 a,b,c,d; } Descriptor;

typedef signed short   s16_021D4A04;

struct DispConfigWords { u32 words[4]; };

typedef struct Config { u32 size; u8 flag; u8 pad[3]; void *target; u32 mode; u8 x,y,z,w; } Config;

typedef signed char s8;

typedef signed short s16;

typedef enum { C0 = 0 } Counter;

struct BgTemplate_021D5BD4 {
    u32 unk00, unk04, bufSize, unk0c;
    u8 unk10, unk11, unk12, unk13;
    u32 unk14;
    u8 unk18, unk19, unk1a, unk1b;
    u32 unk1c;
};

struct Point_021D5BD4 { s16 x, y; u16 f4; u8 f6, f7; };

typedef signed short s16_021D634C;

struct Point_021D634C { s16_021D634C x,y; u16 f4; u8 f6,f7; };

struct Entry { int x,y,n; };

struct Pair_021D634C { int a,b; };

struct Pos_021D634C { short x,y; };

typedef short s16_021D6830;

struct Record { void *h; u16 x,y,a,b,age,c,d,e,f,g; };

struct Pos_021D6830 { s16_021D6830 x,y; };

struct Pair_021D6830 { int x,y; };

struct Obj { u8 pad[0x40f4]; struct Record records[30]; };

typedef signed short s16_021D6A70;

typedef signed short s16_021D6AA8;

typedef struct { u32 x[9]; } Desc;

typedef signed short s16_021D6CD8;

struct Point_021D6830 { s16_021D6CD8 x,y; u16 f4; u8 f6,f7; };

struct Point { s16_021D634C x,y; u16 f4; u8 f6,f7; };

typedef struct { int x[8]; } Table_021D634C;

struct RtcDate_021D634C { int year; u32 month; int day, week; };

struct RtcDate_021D8A9C { u32 year, month, day, week; };

typedef unsigned long long u64;

typedef struct { u16 a[32]; } Table_021D8A9C;

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

typedef short s16_021D8A9C;

extern void func_0203FCA0(u32, const struct BgTemplate_021D4240 *, u32);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
extern void func_0204047C(int, u16);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040C14(u32, u32, u32, u32);
extern void func_02041300(u32, u32, u32, u32, u8, u8, u8);
extern void func_0202F038(u8 *);
extern u8 *func_0202EE8C(u32,void *,u8,u8,u16);
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
extern int func_0203CD98(void);
extern u32 func_02012138(const struct Ctx *p);
extern void func_02026400(struct Comm *p);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_020414EC(u32 i);
extern void func_02027858(struct TaskMenu *m);
extern void func_0204BA10(struct Actor *a);
extern void func_0204B92C(struct Obj *p, u32 v);
extern u32 func_020452E8(struct Descriptor *d);
extern int func_02085D3C(void);
extern int func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201DD68(void);
extern void func_020456F8(struct Descriptor *d);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_02049B40(u32 h, u32 a, u32 c, u32 d, u32 e, u16 heap);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void func_0201C7A4(void *x, s16_021D4240 y, s16_021D4240 z, void *s, void *w);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02051C6C(void *p);
extern void func_02041B6C(u32 bit);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B688(struct Actor *actor, u32 value);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *, void *, u32);
extern u32 func_020307B0(void *p);
extern u32 func_02049740(void *, u32, u32, u32, u32, u16);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *);
extern void *func_0201F5DC(void *, u32, u32, u32);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void *func_02051B84(u8 *a0, int a1, int a2, int a3);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020403F4(u32 i);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020221A4(void);
extern u32 func_02026454(void *obj);
extern int func_02035C60(void);
extern void func_020061E4(u32 a);
extern void func_0204BA00(struct Actor *a, const struct Cmd *cmd);
extern void func_0204B9A0(struct Actor *a);
extern void func_0204B878(struct Obj *p, u16 value);
extern u16 func_0204B898(struct Obj *);
extern s32 func_02051C88(struct Ctx *c);
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int func_02021730(char *p, int i);
extern void func_020862F0(void *, int);
extern void func_0207E5D0(void *, int, int);
extern void func_0207E468(void *, int, int);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern int func_02027CD8(int a0, int a1);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern u32 func_0201CE30(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE38(void *);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern int func_02035C38(void);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *, int, int, void *, void *, void *, void *, int, u16, int);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02041570(int channel, u16 val);
extern int func_02012DD0(u8 *p);
extern int func_02012DAC(int a0);
extern void *func_02012EBC(struct Big *p);
extern int func_020071F0(struct Sub020071E4Ctrl *ctrl);
extern void func_0204A648(void);
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,u8,u32);
extern void func_0204363C(u32 swap);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_0207D46C(void);
extern void func_0203F8F4(u16 heapId);
extern void func_02045088(u16);
extern void func_0201DD60(void);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_020056A0(void *,void *,int);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_02028590(u32,u32,u32,u32);
extern u32 func_0201C440(void *);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_0203D34C(u32,u32);
extern void func_020355D8(u8 v);
extern void func_02027974(void *);
extern u32 func_0201058C(void *key);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0204A600(void);
extern u32 func_020121CC(struct IcaAnime *p);
extern u32 func_02012204(const struct Ctx *p);
extern void func_0202223C(unsigned int,unsigned int);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_02030EAC(struct Node *n);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern int func_02028604(int a0);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02031140(struct S02031140 *p);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_02028470(u8 *p, u32 v);
extern void func_0201EEF4(struct WordSet *,u32,void *);
extern void func_0201EFA4(struct WordSet *,u32,u32,u32,u32,u32);
extern void func_0201F250(struct WordSet *,void *,void *);
extern s32 func_02028484(struct Blk *blk, void *h);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_0200F7DC(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02156DE0(int a, int b);
extern int func_021C5B80(void);
extern int func_021C5928(void (*callback)(int, int, int), char *gamecd, char *passwd);
extern int OS_SNPrintf(char *,int,const char *,...);
extern int func_021C5C04(char *attr1, char *attr2, char *attr3);
extern int func_021C5DB4(void);
extern int func_021C5C38(void *filelist, unsigned int offset, unsigned int num);
extern int func_021C5CFC(void *fileinfo, char *buf, unsigned int size);
extern void func_021C5AB8(void);
extern int func_02034AC4(int);
extern void func_02034A5C(int);
extern void func_0207E3D0(const void *, int, int);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void func_0204B570(struct Actor *actor, u32 value);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u32 func_0201BA68(void *mon);
extern int func_0201BBE8(void *a0);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void *func_02005624(u32 a, u32 b, u32 c);
extern void func_02024230(s16_021D634C *out, u32 count, u16 step, s32 amp);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, unsigned int which);
extern void func_0204B5AC(struct Obj *dst, struct Pair_021D634C *src);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B5C0(const struct Obj *o, struct Pair_021D6830 *p);
extern u32 func_020056EC(u32 range);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern u32 func_02020E60(u16, int);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);
extern u32 func_02019D30(u32 a, u32 n);
extern u32 func_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
extern u32 func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern void func_0204B7C8(const char *src, struct Struct36 *dst);
extern void func_0207E51C(void *,int,int);
extern u32 func_020362DC(void);
extern void func_02012E08(char *p);
extern void func_021B9774(u8 *p);
extern int func_02005E9C(void);
extern void func_02005DE4(void *p);
extern void func_02005DF8(u32 v);
extern int func_02005E64(void);
extern void func_02005D90(int, int);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern int func_020076D0(void *save, int *pbox, int *pslot);
extern u32 func_020173EC(void);
extern u8 *func_02009290(struct Sub02009210Obj *obj);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02019CA0(void *p, u32 v);
extern void *func_020185F4(void *p);
extern int func_020074D8(void **save, const struct Sub02007454Entry *src);
extern void func_020092F8(struct Sub02009210Obj *obj, u8 value);
extern void func_020093D4(struct Sub02009210Obj *obj, s32 value);
extern int func_020185F0(void *);
extern int func_021B99DC(u8 *p);
extern int func_021B9790(u8 *p);
extern u8 *func_021B97F4(u8 *p);
extern int func_021B95D4(int index, u8 *p);
extern int func_021B973C(char *p);
extern int func_021B9748(u8 *p);
extern int func_021BE79C(void *handle, void *value_p, unsigned long length);
extern void func_020092D0(struct Sub02009210Obj *obj, u8 value);
extern void func_02009348(struct Sub02009210Obj *obj, int i, u16 a, u8 b);
extern int func_02012E7C(char *p, int a1);
extern void func_0200734C(struct Sub02007324Ctrl *,unsigned int);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern void func_020090F8(struct Sub020090B0Obj *obj, unsigned char value);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern int func_020072CC(int,int,u16,int,int);
extern void func_0200E8E0(void *obj, u32 value);
extern void func_02012E4C(u8 *,u32);
extern void func_02009108(struct Sub020090B0Obj *obj, u16 value);
extern u32 func_0200C5F8(struct MusicalDist *p);
extern struct MusicalDist *func_0200C5C8(void *sys, const void *src, u32 size, u32 heap);
extern u32 func_0200C6E4(void);
extern u32 func_0200E8B0(void);
extern struct Sub02009210Ent *func_02009390(struct Sub02009210Obj *obj, int i);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void func_020093A8(struct Sub02009210Obj *obj, int i, const void *src);
extern void func_020093F0(struct Sub02009210Obj *obj, int value);
extern void *func_0202A128(int);
extern int func_02019C90(u16, int, int);
extern int func_02019D58(u16, int);
extern int func_0202A19C(u32, void *, u16, u16, int);
extern void *func_0200E0B0(void *);
extern void func_0200E1A8(void *, u16, u16, u8, int, u8, u32);
extern void func_0202A170(void *);
extern s32 func_020093D0(const struct Sub02009210Obj *obj);
extern u32 func_02009370(const struct Sub02009210Obj *obj);
extern void func_020092E0(struct Sub02009210Obj *obj, u8 value);
extern u8 *func_02012944(void *p);
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern void *func_020071D8(struct Ctrl020071D8 *ctrl, int *out);
extern struct Sub02008AECSession *func_02008B14(void *sys);
extern int func_02008BD0(const struct Sub02008AECSession *s);
extern u32 func_020093C8(const struct Sub02009210Obj *obj);
extern void func_0203F4E4(struct RtcDate_021D634C *);
extern int func_0203F540(struct RtcDate_021D634C *);
extern void func_0203C9AC(int a, u32 b, u32 c, u32 d);
extern u32 func_0203C938(u8 mode);
extern void func_020093CC(struct Sub02009210Obj *obj, u32 value);
extern u32 func_020093D8(const struct Sub02009210Obj *obj);
extern void func_02009428(struct Sub02009210Obj *obj, int value);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern void *func_0201747C(struct Mon *p, u32 heap);
extern void func_02009294(struct Sub02009210Obj *obj, const void *src);
extern void func_02007664(void *save, u32 box, u32 slot);
extern void func_021B9838(u8 *p);
extern u32 func_02009228(void);
extern int func_020075B0(void *save, u32 box, u32 slot, const struct Sub020075B0Entry *src);
extern void func_02017528(struct Sav *p);
extern u32 func_0201293C(const struct BigObj *p);
extern u8 func_020092EC(const struct Sub02009210Obj *obj);
extern u8 *func_021B9800(int,int,int);
extern void func_02156DC4(int,int);
extern u32 func_0200FB24(void);
extern void func_0200F7C0(u32 value);
extern int func_02157170(int a0, int a1);
extern void func_0204581C(struct U16Vec *vec);
extern void func_02045AFC(struct U16Vec *vec, u16 value);
extern void func_0201D60C(void *s, u32 b, u32 c, u16 n, const u16 *arr);
extern u32 func_02049658(void *, u32, u32, u32, u32, u32, u16);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void func_02021F64(u16 *, u16 *, int, u8, u16);
extern void func_02005E30(u32 a);
void func_021D4240(void **p, void *f);
void func_021D4244(char *p,void *f,int line);
void func_021D424C(char *a0);
void func_021D4384(u8 *p);
void func_021D43B8(u16 *p, const u16 *add, int n);
void func_021D4440(Object_021D4440 *p);
void func_021D449C(char *p);
void func_021D44F4(char *p);
void func_021D451C(char *p);
void func_021D45F0(void);
void func_021D45F4(int count, u32 *tbl, Own *owner, Rec *recs, u32 *xs, u32 *ys);
void func_021D4730(Object_021D4730 *p);
void func_021D4778(void *p,int flag,Callback *q);
void func_021D478C(char *p);
void func_021D4884(char *p);
void func_021D4A04(char *p);
void func_021D4A64(char *p);
void func_021D4AB4(char *p);
void func_021D4AFC(char *p);
void func_021D4B44(char *p);
int func_021D4BA8(int n, char *p);
void func_021D4C24(u8 *p, int v);
void func_021D4C4C(char *p);
void func_021D4CA0(char *p);
void func_021D4CBC(char *p, int n, int count);
void func_021D4D40(char *p, int flag);
void func_021D4DA4(char *p);
void func_021D4E34(u8 *p);
void func_021D4E64(u8 *p);
int func_021D4E7C(char *p);
void func_021D4EF0(char *p, int n, int flag);
void func_021D4FAC(char *p);
void func_021D4FB8(char *p);
void func_021D4FEC(char *p);
void func_021D5020(char *p);
void func_021D504C(char *p);
void func_021D50F8(char *p);
void func_021D5120(void);
int func_021D5128(void *a,int b,u8 *q);
int func_021D5320(int a,int b,int c,char *p);
int func_021D53D0(void *a,int b,u8 *out,char *p);
void func_021D54E0(u8 *p);
u8 *func_021D54F4(u32 heap,u32 bank);
void func_021D562C(char *p);
void func_021D5644(char *p);
void func_021D56FC(char *p,int mode);
void func_021D57B8(char *p, int a);
void func_021D57D0(void *p, int msg, int n, void *mon);
int func_021D580C(char *p);
void func_021D584C(char *p);
int func_021D5890(char *p,int mode);
int func_021D5950(u8 *p, int x);
void func_021D5960(char *p,int a,int b);
void func_021D59E4(char *p);
void func_021D5A60(char *p);
void func_021D5A7C(char *p);
void func_021D5AB0(u8 *p, int x);
void func_021D5AC0(void *unused, u32 mode);
char *func_021D5B10(int heap,int size);
void func_021D5B70(char *p);
int func_021D5BA0(char *p);
int func_021D5BA8(char *p);
int func_021D5BD4(char *p);
int func_021D5C0C(char *p);
int func_021D5C2C(char *p);
int func_021D5C64(char *p,void *arg,int value);
void func_021D5C9C(char *p);
int func_021D5CAC(char *p);
int func_021D5CF8(char *p);
int func_021D5D24(char *p);
int func_021D5D58(char *p);
void func_021D5D7C(char *p);
void *func_021D5D8C(u8 *p);
u8 *func_021D5D94(u32 heap);
void func_021D5E60(u8 *p);
void func_021D5E8C(u8 *p);
void func_021D5F4C(u8 *p);
void func_021D60F8(void *a, u8 *p);
void func_021D614C(u8 *p);
void func_021D62A8(u8 *p);
void func_021D62B4(u8 *p,unsigned int i);
void func_021D62BC(u8 *p, int i, u32 v);
void func_021D62D0(u8 *p, int i, int v);
void func_021D62E0(u8 *p, int i);
void func_021D62F8(u8 *p, int x, int y);
void func_021D634C(u8 *p, unsigned int i);
void func_021D63D4(u8 *p);
void func_021D63E4(u8 *p);
void func_021D6404(u8 *p);
void func_021D6458(struct Obj02181 *p, void *n, int i);
void func_021D651C(u8 *p);
void func_021D652C(char *p);
void func_021D6548(void *unused, u8 *p);
void func_021D65F4(u8 *p);
void func_021D6650(u8 *p,int flag);
void func_021D6678(u8 *p);
void func_021D66D0(u8 *p, int n);
void func_021D6720(u8 *p, int i);
void func_021D679C(u8 *p);
void func_021D67B4(u8 *p, int i);
void func_021D6830(struct Record *p);
void func_021D6934(struct Obj *p);
void func_021D6A70(u8 *p,int i,int a,int b,int c);
void func_021D6AA8(char *p, int i, u16 v);
void func_021D6AB8(u8 *p);
void func_021D6C48(char *p,int i,void *h);
void func_021D6C90(char *p,int i,void *h);
void func_021D6CD8(u8 *p);
void func_021D6D5C(u8 *p);
int func_021D6E08(char *p,int x);
int func_021D6E70(u8 *p);
int func_021D6EA4(char *p);
int func_021D6EBC(u8 *p);
void func_021D6EDC(u8 *p,u32 v,int unused);
void func_021D6EE0(u8 *p,u32 v,int unused);
void func_021D6EE8(char *p);
void func_021D6F04(char *p);
void func_021D6F44(u8 *p);
void func_021D6F70(unsigned char *a);
void func_021D6FF0(char *p);
void func_021D706C(char *p);
void func_021D7088(char *p);
void func_021D70BC(char *p);
void func_021D7130(char *p);
void func_021D7180(int a);
void func_021D7204(u8 *p);
void func_021D7224(char *p);
void func_021D72D8(char *p);
void func_021D7390(char *p);
void func_021D73D8(char *p);
void func_021D7430(u8 *p);
void func_021D746C(int a);
void func_021D751C(int a);
void func_021D7560(u8 *p);
void func_021D758C(u8 *a);
void func_021D75D0(int a);
void func_021D768C(u8 *p);
void func_021D76B8(char *p);
void func_021D76F0(int a);
void func_021D7798(u8 *p);
void func_021D77C4(int a,int n);
void func_021D7858(int a);
void func_021D78C0(int a);
void func_021D7910(int a);
void func_021D7960(int a);
void func_021D79A4(int a);
void func_021D7A18(int a);
void func_021D7A5C(u8 *p);
void func_021D7B68(char *p);
void func_021D7BDC(char *p);
void func_021D7C54(void *p, char *q);
int func_021D7CB4(int a,u8 *p);
int func_021D7CEC(int a,u8 *p);
void func_021D7D18(u8 *p, int unused, int species, int gender, int form, int n, int value);
void func_021D7DE8(u8 *p,int a,u8 *records);
void func_021D7E20(u8 *p,u8 *list);
void func_021D7E58(u8 *p, void *h, u8 *q, int *r);
int func_021D7F5C(char *p);
void func_021D7F9C(char *p);
void func_021D80B8(char *p);
void func_021D8130(char *p);
void func_021D8154(char *p);
void func_021D81B4(char *p);
void func_021D81E4(char *p);
void func_021D8210(char *p);
void func_021D8244(char *p);
void func_021D8270(char *p);
void func_021D8304(char *p);
void func_021D834C(char *p);
void func_021D83A4(char *p);
void func_021D83C8(char *p);
void func_021D840C(char *p);
void func_021D8448(char *p);
void func_021D8490(char *p);
void func_021D8520(char *p);
void func_021D8590(char *p);
void func_021D85C4(char *p);
void func_021D85F0(char *p);
void func_021D8624(char *p);
void func_021D8650(char *p,int x,int *q);
void func_021D8790(char *p);
void func_021D87F8(char *p);
void func_021D885C(char *p);
void func_021D88A0(char *p);
void func_021D88C0(char *p);
void func_021D8958(char *p);
void func_021D8A38(char *p);
void func_021D8A7C(char *p);
void func_021D8A9C(char *p);
void func_021D8B0C(char *p);
void func_021D8B7C(char *p);
void func_021D8C04(char *p);
void func_021D8D08(char *p);
void func_021D8D98(char *p);
void func_021D8DFC(char *p);
void func_021D8E28(char *p);
void func_021D8E68(char *p);
void func_021D8E98(char *p);
void func_021D8EC4(char *p);
void func_021D8F3C(char *p);
void func_021D8F58(char *p);
int func_021D8FBC(void *a,int b,char *q);
int func_021D9158(void *a, int b, int c, char *p);
int func_021D920C(void *a, int b, int c, char *p);
void func_021D92B8(u8 *p);
u8 *func_021D92CC(u32 heap,u32 bank);
void func_021D9404(char *p);
void func_021D941C(u8 *p);
void func_021D9514(char *p, int n);
void func_021D95B4(char *p);
int func_021D95F0(char *p);
void func_021D9634(char *p);
int func_021D9670(char *p,int mode);
void func_021D9730(char *p, int n);
void func_021D97B0(char *p);
void func_021D97CC(int value, void *p);
void func_021D9844(char *p, int n, int a2);
void func_021D9918(char *p);
char *func_021D9958(int heap);
void func_021D9A14(int a0);
void func_021D9A1C(u8 *p);
void func_021D9AE8(void *a0);
void func_021D9D34(void);
void func_021D9D3C(char *p);
void func_021D9F40(void *unused, char *p);
void func_021D9FB0(unsigned int p);
int func_021D9FD4(char *p, int n);
void func_021DA030(char *p, int n, int unused);
void func_021DA034(char *p, int n, int unused);
void func_021DA03C(char *p);
void func_021DA054(char *p);
void func_021DA090(char *p);
void func_021DA0B8(char *p);
void func_021DA0E4(char *p);
void func_021DA110(char *p);
void func_021DA138(char *p);
void func_021DA16C(char *p);
void func_021DA1A0(char *p);
void func_021DA1C8(char *p);
void func_021DA1EC(char *p);
void func_021DA244(char *p);
void func_021DA268(char *p);
void func_021DA290(char *p);
void func_021DA2DC(char *p);
void func_021DA308(char *p);
void func_021DA328(char *p);
void func_021DA3A0(char *p);
void func_021DA408(char *p);
void func_021DA434(char *p);
void func_021DA45C(char *p);
int func_021DA478(void *a,int unused,char *q);
int func_021DA54C(int a,int b,char *c,char *p);
extern const struct BgTemplate_021D4240 d_021DA690;
extern const struct BgTemplate_021D4240 d_021DA6B0;
extern const struct BgTemplate_021D4240 d_021DA6D0;
extern const struct BgTemplate_021D4240 d_021DA6F0;
extern const struct BgTemplate_021D4240 d_021DA710;
extern const struct Triple d_021DA638;
extern const struct Triple d_021DA634;
extern const struct Triple d_021DA63C;
extern const char d_021DA9D0[];
extern char func_021DA9C0[];
extern int d_021DA640[];
extern int d_021DA648[];
extern const struct DispConfigWords d_021DA680;
extern const u32 d_021DA9F0[];
extern const u32 d_021DA658[];
extern const char d_021DAA20[];
extern const char d_021DAA30[];
extern u8 *d_021DAC20;
extern char d_021DAA40[];
extern char d_021DAA54[];
extern char *g_021DAC20;
extern char d_021DAA58[];
extern char d_021DAA60[];
extern const char d_021DAA74[];
extern const char d_021DAB68[];
extern char ov067_id[];
extern const u32 d_021DAA9C[];
extern const u32 d_020A1464[];
extern const u32 d_021DAA78[];
extern unsigned char ov_id[];
extern const struct BgTemplate_021D5BD4 d_021DA758[7];
extern struct Entry d_021DAACC[];
extern const struct Pair_021D634C d_021DA738;
extern const struct Pair_021D634C d_021DA748;
extern const u16 d_021DAA88[10];
extern const struct Pos_021D634C d_021DA730;
extern const struct Pair_021D634C d_021DA750;
extern const struct Pos_021D634C d_021DA734;
extern const struct Pair_021D634C d_021DA740;
extern const s16_021D6830 d_020A1B38[][2];
extern const Table_021D634C d_021DA844;
extern const char d_021DAB78[];
extern const char d_021DAB88[];
extern const char d_021DAB90[];
extern const char d_021DAB9C[];
extern char ov114_id[];
extern const char d_021DABA4[];
extern const char d_021DABA8[];
extern const Table_021D8A9C d_021DA868;
extern const u16 d_021DA864;
extern const char d_021DABFC[];
extern const u32 d_021DABCC[];
extern const u32 d_021DABBC[];
extern const struct BgTemplate d_021DA8A8[8];





void func_021D4240(void **p, void *f)
{
    *p=f;
}





void func_021D4244(char *p,void *f,int line) { func_021D4240((void **)p,f); }





void func_021D424C(char *a0)
{
    struct BgTemplate_021D4240 b[5];
    b[4] = d_021DA690;
    func_0203FCA0(0, (const struct BgTemplate_021D4240 *)(&b[4]), 0);
    func_020414AC(0);
    func_020409B4(0);
    func_0204047C(0, 0);
    func_02040588(0, 1);
    b[3] = d_021DA6B0;
    func_0203FCA0(4, (const struct BgTemplate_021D4240 *)(&b[3]), 0);
    func_02040588(4, 1);
    func_020409B4(4);
    b[2] = d_021DA6D0;
    func_0203FCA0(5, (const struct BgTemplate_021D4240 *)(&b[2]), 0);
    func_02040C14(5, 0, 1, 0);
    func_02041300(5, 0, 0, 0, 32, 32, 17);
    func_020409B4(5);
    func_02040588(5, 1);
    b[1] = d_021DA6F0;
    func_0203FCA0(6, (const struct BgTemplate_021D4240 *)(&b[1]), 0);
    func_02040588(6, 1);
    func_020409B4(6);
    b[0] = d_021DA710;
    func_0203FCA0(7, (const struct BgTemplate_021D4240 *)(&b[0]), 0);
    func_02040588(7, 1);
    func_020409B4(7);
}





void func_021D4384(u8 *p) { if(*(u8 * *)&((struct Obj00273 *)p)->f288) { func_0202F038(*(u8 * *)&((struct Obj00273 *)p)->f288); *(u32 *)&((struct Obj00273 *)p)->f288=0; } *(u8 * *)&((struct Obj00273 *)p)->f288=func_0202EE8C(((struct Obj00273 *)p)->f230,((struct Obj00273 *)p)->f224,15,16,((struct Obj00273 *)p)->fC); }





void func_021D43B8(u16 *p, const u16 *add, int n)
{
    int i, j;
    u16 *row;
    u16 r, g, b;
    for (i = 0; i < n; i++) {
        row = p + i * 16;
        for (j = 0; j < 16; j++) {
            r = row[j] & 31;
            g = (row[j] & 0x3e0) >> 5;
            b = (row[j] & 0x7c00) >> 10;
            r += add[j];
            g += add[j];
            b += add[j];
            if (r > 31) r = 31;
            if (g > 31) g = 31;
            if (b > 31) b = 31;
            row[j] = r + (g << 5) + (b << 10);
        }
    }
}





void func_021D4440(Object_021D4440 *p)
{
    p->f28c = 1;
    func_0202208C(0, 0, 0, 0, 6, 1, p->f0c);
    switch (p->f08) {
    case 2:
    case 3:
        if (func_0203CD98())
            func_02026400((struct Comm *)func_02012138(p->f264));
        break;
    }
    func_021D4244((char *)p, func_021D4AB4, 0x1aa);
}





void func_021D449C(char *p)
{
    if (func_020279E8(((struct Obj00273 *)p)->f238)) {
        if (!func_02027A04(((struct Obj00273 *)p)->f238)) {
            func_021D4244(p, func_021D4FB8, 0x1b6);
        } else {
            func_020414EC(5);
            ((struct Obj00273 *)p)->f8 = 0;
            func_021D4244(p, func_021D4A04, 0x1bb);
        }
        func_02027858(((struct Obj00273 *)p)->f238);
        *(int *)&((struct Obj00273 *)p)->f238 = 0;
        func_021D4D40(p, 0);
    }
}





void func_021D44F4(char *p) { if(func_021D4E7C(p)) { func_021D4DA4(p); func_021D4244(p,func_021D449C,0x1c9); } }





/*
 * extent: follower 021D45F0 already filed separately.
 */
void func_021D451C(char *p)
{
    func_0204BA10(*(void **)(p + ((struct Obj00273 *)p)->f270 * 4 + 0x2a0));
    func_0204B92C(*(void **)(p + ((struct Obj00273 *)p)->f270 * 4 + 0x2a0), 0);
    if (((struct Obj00273 *)p)->f8 == 3) {
        if (((struct Obj00273 *)p)->f224) {
            func_020452E8(((struct Obj00273 *)p)->f224);
            ((struct Obj00273 *)p)->f224 = 0;
        }
        if (func_02085D3C()) {
            func_02045CAC(((struct Obj00273 *)p)->f28, 0x20, ((struct Obj00273 *)p)->f38);
            func_021D4EF0(p, 10, 0);
            func_021D4D40(p, 1);
            func_021D4244(p, func_021D4AFC, 0x1df);
        } else {
            func_02045CAC(((struct Obj00273 *)p)->f24, 7, ((struct Obj00273 *)p)->f38);
            func_021D4FAC(p);
            func_021D4D40(p, 1);
            func_021D4244(p, func_021D44F4, 0x1e6);
        }
    } else if (((struct Obj00273 *)p)->f8 == 2 || ((struct Obj00273 *)p)->f8 == 3) {
        func_021D4244(p, func_021D4FB8, 0x1f2);
    } else {
        func_021D4244(p, func_021D4440, 0x1f5);
    }
}





/*
 * extent: bx lr callback stub, two zero alignment bytes, then labelled func_021D45F4.
 */
void func_021D45F0(void) {}






/*
 * note 2026-10-05 (wD6 lane17): closed by the real callee prototypes: func_0201DD68 takes no
 *   argument (so count is spilled and reloaded for the +0x25C store) and the record pointer is not
 *   const (the a/b/c loads stay after the outgoing stack-argument stores).
 */
void func_021D45F4(int count, u32 *tbl, Own *owner, Rec *recs, u32 *xs, u32 *ys)
{
    int i;
    int j;
    int a;
    int b;

    owner->n = count;
    func_0201DD68();
    for (i = 0; i < 4; i++) {
        if (owner->obj[i] != 0) {
            func_020456F8(owner->obj[i]);
            func_0201F7A8(owner->obj[i], 2);
            func_020452E8(owner->obj[i]);
        }
        owner->obj[i] = 0;
    }
    func_02049B40(0x17, 5, 4, 0x100, 0x20, owner->heap);
    for (j = 0; j < count; j++) {
        Rec *r = &recs[j];
        owner->obj[j] = (void *)func_020450F0(7, (u8)r->a, (u8)r->b, (u8)r->c, (u8)r->d, 8, 0);
        func_02043B5C(func_02045770(owner->obj[j]), 0);
        func_02045CAC(owner->bank, tbl[j], owner->str);
        func_0201DD78(0xF, 2, 0);
        if (xs != 0)
            a = xs[j] - func_0201D304(owner->str, (u32)owner->font, 0) / 2;
        else
            a = 0;
        if (ys != 0)
            b = ys[j] - func_0201D42C(owner->str, owner->font) / 2;
        else
            b = 0;
        func_0201C7A4(func_02045770(owner->obj[j]), (s16_021D4240)a, (s16_021D4240)b, owner->str, owner->font);
        func_02045334(owner->obj[j]);
        func_02045374(owner->obj[j]);
    }
    if (owner->res != 0)
        func_02051C6C(owner->res);
    owner->res = 0;
    func_020409B4(7);
}





void func_021D4730(Object_021D4730 *p)
{
    int i;
    if (p->f20)
        func_02051C6C(p->f20);
    p->f20 = 0;
    for (i = 0; i < 4; i++) {
        if (p->f10[i]) {
            func_020456F8(p->f10[i]);
            func_02041B6C(5);
            func_0201F7A8(p->f10[i], 2);
            func_020452E8(p->f10[i]);
        }
        p->f10[i] = 0;
    }
    p->f25c = 0;
}





void func_021D4778(void *p,int flag,Callback *q) { if(flag) return; if(!q->run) return; if(q->run(p,q)) return; }





/*
 * lever: seven independent offset locals each receive 0x2ac then their final literal; both spill stores survive.
 * note 2026-10-05 (wave D9r lane 131): removed the 7 dead first assignments
 * (`o1 = 0x2ac;` before `o1 = 0x294;`; `o2 = 0x2ac;` before `o2 = 0x290;`
 * and 5 more). Game code has no line table, so these were stand-ins. The
 * plain single assignment gives EXACT in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void func_021D478C(char *p)
{
    struct Triple x, y, z;
    struct Point_021D4240 pt;
    int i;
    int o1, o2, o3, o4, o5, o6, o7;
    x = d_021DA638;
    y = d_021DA634;
    z = d_021DA63C;
    i = 0;
    o1 = 0x294;
    o2 = 0x290;
    o3 = 0x298;
    o4 = 0x2a0;
    o5 = 0x2a0;
    o6 = 0x2a0;
    o7 = 0x2a0;
    for (; i < 3; i++) {
        pt.x = x.v[i]; pt.y = y.v[i]; pt.z = z.v[i];
        pt.a = 0; pt.b = 2;
        *(void **)(p + i * 4 + o4) = func_0204B294((void *)((struct Obj00471 *)p)->f2AC, (unsigned int)*(void **)(p + o1), *(u32 *)(p + o2), *(u32 *)(p + o3), &pt, 1, ((struct Obj00471 *)p)->fC);
        func_0204B92C(*(void **)(p + i * 4 + o5), 0);
        func_0204B3DC(*(void **)(p + i * 4 + o6), 1);
        func_0204B688(*(void **)(p + i * 4 + o7), 1);
    }
}





/*
 * interface: 02049990 arg5 is u16 at both original call-site truncations; 02049F78 arg3 is an unchanged address payload passed to 02062A98, whose body stores through it.
 */
void func_021D4884(char *p)
{
    void *h;
    void *allocated;
    void *record;
    ((struct Obj00471 *)p)->f38 = func_020457B0(300, ((struct Obj00471 *)p)->fC);
    ((struct Obj00471 *)p)->f30 = func_0201D7EC(23, 0, 0, 0, ((struct Obj00471 *)p)->fC);
    ((struct Obj00471 *)p)->f24 = func_02045B38(0, 2, 39, ((struct Obj00471 *)p)->fC);
    ((struct Obj00471 *)p)->f28 = func_02045B38(0, 2, 232, ((struct Obj00471 *)p)->fC);
    h = func_020490F4((u32)((void *)29), ((struct Obj00471 *)p)->fC);
    func_02049B68(h, 1, 4, 0, 0, ((struct Obj00471 *)p)->fC);
    func_02049B68(h, 0, 0, 0, 0, ((struct Obj00471 *)p)->fC);
    allocated = func_02049F78(h, 1, (u32)(&record), ((struct Obj00471 *)p)->fC);
    func_02082D44(((struct Obj13968 *)record)->fC, p + 0x44, 0xe0);
    func_02082D44(((struct Obj13968 *)record)->fC, p + 0x124, 0xe0);
    func_021D43B8((u16 *)(p + 0x124), (const u16 *)d_021DA9D0, 7);
    func_020307B0(allocated);
    ((struct Obj00471 *)p)->f40 = func_02049740(h, 4, 4, 0, 0, ((struct Obj00471 *)p)->fC);
    func_02049990(h, 9, 4, 0, (u16)(((struct Obj00471 *)p)->f40), 0, 0, ((struct Obj00471 *)p)->fC);
    func_02049990(h, 14, 6, 0, (u16)(((struct Obj00471 *)p)->f40), 0, 0, ((struct Obj00471 *)p)->fC);
    func_02049238(h);
    ((struct Obj00471 *)p)->f3C = func_0201F5DC((void *)5, 12, 0, ((struct Obj00471 *)p)->fC);
    func_02049B40(23, 5, 4, 0x1a0, 32, ((struct Obj00471 *)p)->fC);
    h = func_020490F4((u32)((void *)29), ((struct Obj00471 *)p)->fC);
    ((struct Obj00471 *)p)->f294 = (void *)func_0204A6C8(h, 5, 0, 1, ((struct Obj00471 *)p)->fC);
    ((struct Obj00471 *)p)->f290 = (void *)func_0204AC18(h, 3, 1, 0, 0, 10, ((struct Obj00471 *)p)->fC);
    ((struct Obj00471 *)p)->f298 = (void *)func_0204AF28(h, 7, 16, ((struct Obj00471 *)p)->fC);
    func_02049238(h);
    func_021D478C(p);
}







void func_021D4A04(char *p)
{
    struct { int value; } zero = {0};
    func_021D45F4(1, (u32 *)&zero, (Own *)p, (Rec *)func_021DA9C0, (u32 *)d_021DA640, (u32 *)(d_021DA640 + 1));
    ((struct Obj10434 *)p)->f20 = func_02051B84((u8 *)d_021DA648, (int)func_021D4778, (int)p, ((struct Obj10434 *)p)->fC);
    ((struct Obj10434 *)p)->f4 = func_021D4BA8;
    func_021D4244(p, func_021D4CA0, 0x321);
}







void func_021D4A64(char *p)
{
    func_0201DD68();
    func_021D4730((Object_021D4730 *)p);
    func_02040DA8(5, 1, 0);
    func_0203FB44((int)5, (u16)(((struct Obj01543 *)p)->f3C), (u16)(((struct Obj01543 *)p)->f3C >> 16));
    func_020403F4(5);
    func_020403F4(4);
    func_02045C04(((struct Obj01543 *)p)->f24);
    func_02045C04(((struct Obj01543 *)p)->f28);
    func_0201D83C(((struct Obj01543 *)p)->f30);
    func_02045808(((struct Obj01543 *)p)->f38);
}







void func_021D4AB4(char *p)
{
    if (func_020221A4() != 0) {
        switch (((struct Obj13969 *)p)->f8) {
        case 2:
        case 3:
            if (func_02026454((void *)func_02012138(((struct Obj13969 *)p)->f264)) == 0)
                func_021D4244(p, 0, 0x345);
            break;
        default:
            func_021D4244(p, 0, 0x349);
            break;
        }
    }
}







void func_021D4AFC(char *p)
{
    if (func_021D4E7C(p) != 0 && func_02035C60() != 0) {
        func_021D4E64((u8 *)p);
        ((struct Obj00273 *)p)->f27C = 0;
        func_020061E4(0x73b);
        func_021D4D40(p, 0);
        func_021D4244(p, func_021D4A04, 0x360);
    }
}







/*
 * evidence: callback 0x021D45F0 resolved by its verified ov123 shard.
 */
void func_021D4B44(char *p)
{
    NotifyCallback cb;
    cb.value = 0;
    cb.object = p;
    cb.callback = func_021D451C;
    func_0204B92C(*(void **)(p + ((struct Obj10435 *)p)->f270 * 4 + 0x2a0), 1);
    func_0204BA00(*(void **)(p + ((struct Obj10435 *)p)->f270 * 4 + 0x2a0), (const struct Cmd *)(&cb));
    func_0204B9A0(*(void **)(p + ((struct Obj10435 *)p)->f270 * 4 + 0x2a0));
    func_021D4244(p, func_021D45F0, 0x376);
}







int func_021D4BA8(int n, char *p)
{
    ((struct Obj06458 *)p)->f270 = n;
    switch (n) {
    case 0:
        func_020061E4(0x73b);
        func_0204B878(((struct Obj06458 *)p)->f2A0, 14);
        func_021D4244(p, func_021D4B44, 0x389);
        ((struct Obj06458 *)p)->f8 = 2;
        break;
    case 1:
        func_020061E4(0x73b);
        ((struct Obj06458 *)p)->f8 = 3;
        func_021D4244(p, func_021D4B44, 0x393);
        break;
    case 2:
        func_020061E4(0x73c);
        ((struct Obj06458 *)p)->f8 = 0;
        func_021D4244(p, func_021D4B44, 0x399);
        break;
    }
    return 1;
}







void func_021D4C24(u8 *p, int v) { if(v!=func_0204B898(*(struct Obj * *)&((struct Obj05360 *)p)->f2A0)) { func_0204B92C(*(struct Obj * *)&((struct Obj05360 *)p)->f2A0,1); func_0204B878(*(struct Obj * *)&((struct Obj05360 *)p)->f2A0,v); } }







void func_021D4C4C(char *p)
{
    u32 keys = ((struct Obj05360 *)p)->f278;
    if (keys != ((struct Obj05360 *)p)->f27C) {
        if (keys & 0x40) func_021D4C24((u8 *)p, 0x18);
        else if (keys & 0x80) func_021D4C24((u8 *)p, 0x16);
        else if (keys & 0x100) func_021D4C24((u8 *)p, 0x15);
        else if (keys & 0x200) func_021D4C24((u8 *)p, 0x15);
        else func_021D4C24((u8 *)p, 0xe);
    }
}








/*
 * Addresses are Black-image addresses.
 */
void func_021D4CA0(char *p)
{
    if (func_020221A4() != 0)
        func_02051C88(((struct Obj05360 *)p)->f20);
    func_021D4C4C(p);
}







/*
 * extent: two zero padding bytes at 0x021D4D3E before next labelled function.
 */
void func_021D4CBC(char *p, int n, int count)
{
    void *obj;
    void *buffer;
    int bytes;
    obj = func_02021518(((struct Obj13970 *)p)->fC);
    func_0202155C(obj, n, 0x200, ((struct Obj13970 *)p)->fC);
    bytes = count * 32;
    func_020216D4(obj, n, 0, bytes);
    func_02021FD8(obj, (int)n, (int)0, (u16)(count * 16), (int)6, (int)0);
    buffer = (void *)func_02021730(obj, n);
    func_020862F0(buffer, bytes);
    switch (n) {
    case 3: func_0207E5D0(buffer, 0, bytes); break;
    case 1: func_0207E468(buffer, 0, bytes); break;
    }
    func_020215A0(obj, n);
    func_02021540(obj);
}







void func_021D4D40(char *p, int flag)
{
    if (flag) {
        func_02082D44((void *)0x05000600, ((struct Obj00273 *)p)->f280, 0x200);
        func_02082D44((void *)0x05000400, ((struct Obj00273 *)p)->f284, 0x200);
        func_021D4CBC(p, 3, 14);
        func_021D4CBC(p, 1, 9);
    } else {
        func_0207E5D0(((struct Obj00273 *)p)->f280, 0, 0x1c0);
        func_0207E468(((struct Obj00273 *)p)->f284, 0, 0x120);
    }
}







void func_021D4DA4(char *p)
{
    Descriptor desc;
    desc.heap = ((struct Obj00626 *)p)->fC;
    desc.mode = 2;
    desc.data = p + 0x23c;
    desc.flag = 1;
    desc.a = 32;
    desc.b = 14;
    desc.c = 13;
    desc.d = 3;
    ((struct Obj00626 *)p)->f23C = func_020457B0(100, ((struct Obj00626 *)p)->fC);
    func_02045CAC(((struct Obj00626 *)p)->f24, 4, ((struct Obj00626 *)p)->f23C);
    ((struct Obj00626 *)p)->f240 = 0x39e0;
    ((struct Obj00626 *)p)->f248 = func_020457B0(100, ((struct Obj00626 *)p)->fC);
    func_02045CAC(((struct Obj00626 *)p)->f24, 5, ((struct Obj00626 *)p)->f248);
    ((struct Obj00626 *)p)->f24C = 0x39e0;
    ((struct Obj00626 *)p)->f238 = func_02027778((struct TaskMenuTmpl *)(&desc), ((struct Obj00626 *)p)->f254);
    func_02027CD8((int)(((struct Obj00626 *)p)->f238), 1);
    func_02045808(((struct Obj00626 *)p)->f23C);
    func_02045808(((struct Obj00626 *)p)->f248);
}







void func_021D4E34(u8 *p) { if(*(u8 * *)&((struct Obj04495 *)p)->f288) { func_0202F038(*(u8 * *)&((struct Obj04495 *)p)->f288); *(u32 *)&((struct Obj04495 *)p)->f288=0; } func_0201F7A8(((struct Obj04495 *)p)->f224,2); func_020456F8(*(struct Descriptor * *)&((struct Obj04495 *)p)->f224); func_02041B6C(5); }








void func_021D4E64(u8 *p)
{
    func_021D4E34(p);
    func_020452E8(((struct Obj04495 *)p)->f224);
    *(u32 *)&((struct Obj04495 *)p)->f224 = 0;
}







int func_021D4E7C(char *p)
{
    if (((struct Obj00626 *)p)->f228) {
        if (((struct Obj00626 *)p)->f224)
            func_020286C4(((struct Obj00626 *)p)->f22C, ((struct Obj00626 *)p)->f228, ((struct Obj00626 *)p)->f224);
        switch (func_0201CE30(((struct Obj00626 *)p)->f228)) {
        case 2:
            func_0201CE48(((struct Obj00626 *)p)->f228);
            ((struct Obj00626 *)p)->f228 = 0;
            break;
        case 1:
            if (func_02035C60()) {
                func_020061E4(0x547);
                func_0201CE38(((struct Obj00626 *)p)->f228);
            }
            break;
        case 0:
            if (func_02035C38()) func_0201CE5C(((struct Obj00626 *)p)->f228, 0);
            break;
        }
        return 0;
    }
    return 1;
}







void func_021D4EF0(char *p, int n, int flag)
{
    void *obj;
    if (((struct Obj02473 *)p)->f224 == 0)
        ((struct Obj02473 *)p)->f224 = (void *)func_020450F0(5, 1, 3, 30, (u8)n, 13, 1);
    obj = ((struct Obj02473 *)p)->f224;
    func_02043B5C(func_02045770(obj), 15);
    func_0201DD78(1, 2, 15);
    if (flag) {
        void *value;
        value = (void *)func_02012FFC();
        ((struct Obj02473 *)p)->f228 = func_0201CCE4(obj, 0, 0, ((struct Obj02473 *)p)->f38, ((struct Obj02473 *)p)->f30, value, ((struct Obj02473 *)p)->f230, 2, ((struct Obj02473 *)p)->fC, 15);
    } else {
        func_0201C7A4(func_02045770(obj), 0, 0, ((struct Obj02473 *)p)->f38, ((struct Obj02473 *)p)->f30);
    }
    func_0201F73C(obj, 1, (u16)(((struct Obj02473 *)p)->f3C), 12);
    func_02045334(obj);
    func_02045374(obj);
    func_02041B6C(5);
}







void func_021D4FAC(char *p) { func_021D4EF0(p,4,1); }







/*
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
 */
void func_021D4FB8(char *p) { func_021D4D40(p,1); func_02041570(5,0); func_02045CAC(*(void **)(p+36),3,*(void **)(p+56)); func_021D4FAC(p); func_021D4244(p,func_021D50F8,0x4d0); }







void func_021D4FEC(char *p) { if(func_02012DD0(((struct Obj00273 *)p)->f260)==2) { func_021D4E64((u8 *)p); func_021D4D40(p,0); func_021D4244(p,func_021D4440,0x4ea); } }







void func_021D5020(char *p) { if(func_021D4E7C(p)) { func_02012DAC((int)(((struct Obj22939 *)p)->f260)); func_021D4244(p,func_021D4FEC,0x4fa); } }







void func_021D504C(char *p)
{
    if (func_020279E8(((struct Obj00273 *)p)->f238)) {
        if (!func_02027A04(((struct Obj00273 *)p)->f238)) {
            if (func_020071F0(func_02012EBC(((struct Obj00273 *)p)->f260))) {
                func_02045CAC(((struct Obj00273 *)p)->f24,46,((struct Obj00273 *)p)->f38);
                func_021D4FAC(p);
                func_021D4244(p,func_021D4AFC,0x50d);
            } else {
                func_02045CAC(((struct Obj00273 *)p)->f24,6,((struct Obj00273 *)p)->f38);
                func_021D4EF0(p,4,0);
                func_021D4384((u8 *)p);
                func_021D4244(p,func_021D5020,0x519);
            }
        } else {
            func_020414EC(5);
            ((struct Obj00273 *)p)->f8=0;
            func_021D4244(p,func_021D4A04,0x51f);
            func_021D4D40(p,0);
        }
        func_02027858(((struct Obj00273 *)p)->f238);
        ((struct Obj00273 *)p)->f238=0;
    }
}







void func_021D50F8(char *p){if(func_021D4E7C(p)){func_021D4DA4(p);func_021D4244(p,func_021D504C,0x536);}}







/*
 * evidence: root claimed this sole blocker of 021D5128; target's matched
 * definition and original body read no incoming argument registers.
 */
void func_021D5120(void)
{
    func_0204A648();
}







/*
 * evidence: sole callback blocker ov123 021D5120 filed and verified before
 * caller recheck; ABS32 at +01E0 now resolves through its matched shard.
 * volatile: display register 04001000 read/write at 021D5198/021D519C.
 * interface: 0203159C leaves its allocation result in r0, which is used
 * throughout this caller; its legacy matched definition is void.
 */
int func_021D5128(void *a,int b,u8 *q)
{
    char *p;
    int bright;
    int color;
    struct DispConfigWords cfg;
    func_0203064C(1,31,0x18000);
    p=func_0203159C(a,0x2b4,31);
    func_02082BCC(p,0,0x2b4);
    ((struct Obj00590 *)p)->fC=31;
    ((struct Obj00590 *)p)->f260=((struct Obj06459 *)q)->f4; ((struct Obj00590 *)p)->f264=((struct Obj06459 *)q)->f0;
    func_0204363C(1);
    if(((struct Obj06459 *)q)->f2C8) bright=16; else bright=-16;
    func_0207D534((void *)0x0400006c,bright); func_0207D534((void *)0x0400106c,bright);
    *(volatile u32 *)0x04001000|=0x10000; func_0207D46C();
    func_0203F8F4(((struct Obj00590 *)p)->fC); func_02045088(((struct Obj00590 *)p)->fC); func_0201DD60();
    func_020433E0((const struct DispVram *)d_021DA9F0);
    cfg=d_021DA680; func_0203FC28((struct DispConfig *)(&cfg));
    func_02043534(0); func_020435F4(0);
    func_0204A48C((const struct Cfg *)d_021DA658,(u32)d_021DA9F0,((struct Obj00590 *)p)->fC);
    ((struct Obj00590 *)p)->f2AC=func_0204B100(40,0,((struct Obj00590 *)p)->fC);
    ((struct Obj00590 *)p)->f2B0=func_020056A0(func_021D5120,p,0);
    func_021D424C(p); func_021D4884(p);
    ((struct Obj00590 *)p)->f280=func_02030734(((struct Obj00590 *)p)->fC,0x200,0,d_021DAA20,0x5a6);
    ((struct Obj00590 *)p)->f284=func_02030734(((struct Obj00590 *)p)->fC,0x200,0,d_021DAA20,0x5a7);
    ((struct Obj00590 *)p)->f230=func_0203101C(((struct Obj00590 *)p)->fC,((struct Obj00590 *)p)->fC,3,0);
    ((struct Obj00590 *)p)->f22C=func_02028590(15,0,1,((struct Obj00590 *)p)->fC);
    ((struct Obj00590 *)p)->f234=func_0201C440((void *)(u32)((struct Obj00590 *)p)->fC);
    ((struct Obj00590 *)p)->f254=func_02027F60(5,9,((struct Obj00590 *)p)->f30,((struct Obj00590 *)p)->f234,((struct Obj00590 *)p)->fC);
    func_0207D63C((void *)0x04001050,4,1,15,4);
    color=0; if(((struct Obj06459 *)q)->f2C8) color=0x7fff;
    func_0202208C(0,1,1,(u16)color,6,1,((struct Obj00590 *)p)->fC);
    *(u32 *)&((struct Obj06459 *)q)->f2C8=0; func_020435F4(31);
    func_021D4244(p,func_021D4A04,0x5bf);
    ((struct Obj00590 *)p)->f258=q;
    func_0203D34C(0,((struct Obj00590 *)p)->fC); func_020355D8(1);
    return 1;
}







/*
 * extent: two bytes zero alignment padding follow the return.
 */
int func_021D5320(int a,int b,int c,char *p)
{
    int result=1;
    if (*(void (**)(char *))p) {
        (*(void (**)(char *))p)(p);
        result=0;
    }
    if (((struct Obj01733 *)p)->f238) func_02027974(((struct Obj01733 *)p)->f238);
    if (func_0203CD98()) {
        ((struct Obj01733 *)p)->f27C=((struct Obj01733 *)p)->f278;
        ((struct Obj01733 *)p)->f278=func_0201058C(0);
    }
    func_020310C4(((struct Obj01733 *)p)->f230);
    func_0201C4E4(((struct Obj01733 *)p)->f234);
    func_02040618(4,3,((struct Obj01733 *)p)->f268);
    --((struct Obj01733 *)p)->f268;
    func_0204A600();
    if (!((struct Obj01733 *)p)->f28C) func_020121CC(((struct Obj01733 *)p)->f264);
    if (func_020221A4() && func_02012204(((struct Obj01733 *)p)->f264)) {
        ((struct Obj01733 *)p)->f8=0;
        result=1;
        func_0202223C(0,0);
        func_0202223C(1,0);
    }
    return result;
}







/*
 * extent: two zero alignment bytes at 021D54DE follow the return.
 */
int func_021D53D0(void *a,int b,u8 *out,char *p)
{
    int i;
    if(!func_020221A4()) return 0;
    for(i=0;i<3;i++) func_0204B3B4(*(void **)(p+i*4+0x2a0));
    func_0204ADA4((u32)(((struct Obj00772 *)p)->f290));
    func_0204A8D4((u32)(((struct Obj00772 *)p)->f294));
    func_0204AFD8((u32)(((struct Obj00772 *)p)->f298));
    func_02030EAC(((struct Obj00772 *)p)->f2B0);
    func_0204B1CC(((struct Obj00772 *)p)->f2AC); func_0204A5AC();
    if(((struct Obj00772 *)p)->f288) { func_0202F038(((struct Obj00772 *)p)->f288); ((struct Obj00772 *)p)->f288=0; }
    if(((struct Obj00772 *)p)->f228) func_0201CE48(((struct Obj00772 *)p)->f228);
    if(((struct Obj00772 *)p)->f238) { func_02027858(((struct Obj00772 *)p)->f238); ((struct Obj00772 *)p)->f238=0; }
    func_021D4A64(p);
    ((struct Obj22940 *)out)->f1C8=((struct Obj00772 *)p)->f8;
    func_020307B0(((struct Obj00772 *)p)->f280); func_020307B0(((struct Obj00772 *)p)->f284);
    func_02028604((int)(((struct Obj00772 *)p)->f22C)); func_020403F4(5);
    func_0201C6EC(((struct Obj00772 *)p)->f234); func_0201C4C0(((struct Obj00772 *)p)->f234);
    if(((struct Obj00772 *)p)->f224) func_020452E8(((struct Obj00772 *)p)->f224);
    func_02031140(((struct Obj00772 *)p)->f230); func_02027FD8(((struct Obj00772 *)p)->f254);
    func_020450C8(); func_0203F9B4(); func_020315D4(a); func_020306F0(31);
    return 1;
}








void func_021D54E0(u8 *p)
{
    if (((struct Obj10436 *)p)->f1C) {
        func_02051C6C(((struct Obj10436 *)p)->f1C);
        *(u32 *)&((struct Obj10436 *)p)->f1C = 0;
    }
}







u8 *func_021D54F4(u32 heap,u32 bank)
{
    u8 *p;
    p=func_02030734(heap,0xb4,1,d_021DAA30,0x96);
    ((struct Obj00499 *)p)->fB0=heap;
    ((struct Obj00499 *)p)->f24=func_0201EC64(((struct Obj00499 *)p)->fB0);
    func_02045088(((struct Obj00499 *)p)->fB0); func_0201DD60();
    ((struct Obj00499 *)p)->f84=func_0203101C(((struct Obj00499 *)p)->fB0,((struct Obj00499 *)p)->fB0,2,0);
    ((struct Obj00499 *)p)->f88=func_0201C440((void *)(u32)((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->f2C=func_020457B0(400,((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->f30=func_020457B0(400,((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->f28=func_0201D7EC(23,0,0,0,((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->f20=func_02045B38(0,2,(u16)bank,((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->f40=func_02028590(15,1,1,((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->fA4=func_02027F60(5,9,*(u32 *)&((struct Obj00499 *)p)->f28,((struct Obj00499 *)p)->f88,((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->f8=func_0201F5DC((void *)5,12,0,((struct Obj00499 *)p)->fB0);
    ((struct Obj00499 *)p)->f4=func_0201F5DC((void *)6,12,0,((struct Obj00499 *)p)->fB0);
    func_02049B40(23,5,4,352,32,((struct Obj00499 *)p)->fB0);
    func_02049B40(23,5,0,352,32,((struct Obj00499 *)p)->fB0);
    return p;
}








void func_021D562C(char *p)
{
    func_020310C4(((struct Obj13971 *)p)->f84);
    func_0201C4E4(((struct Obj13971 *)p)->f88);
}







/*
 * lever: low and high halves of packed words pass to u16 callee parameters; no explicit high-half cast.
 */
void func_021D5644(char *p)
{
    int i;
    u32 a;
    func_021D584C(p);
    if (((struct Obj01154 *)p)->f44) func_020452E8(((struct Obj01154 *)p)->f44);
    if (((struct Obj01154 *)p)->f48) func_020452E8(((struct Obj01154 *)p)->f48);
    for(i=0;i<12;i++) {
        if (*(void **)(p+0x4c+i*4)) func_020452E8(*(void **)(p+0x4c+i*4));
    }
    a=((struct Obj01154 *)p)->f8>>16;
    func_0203FB44((int)5,(u16)(((struct Obj01154 *)p)->f8),(u16)a);
    a=((struct Obj01154 *)p)->f4>>16;
    func_0203FB44((int)6,(u16)(((struct Obj01154 *)p)->f4),(u16)a);
    func_021D54E0((u8 *)p);
    func_02028604((int)(((struct Obj01154 *)p)->f40));
    func_0201ED04(((struct Obj01154 *)p)->f24);
    func_0201DD68();
    func_02045C04(((struct Obj01154 *)p)->f20);
    func_0201D83C(((struct Obj01154 *)p)->f28);
    func_02045808(((struct Obj01154 *)p)->f2C);
    func_02045808(((struct Obj01154 *)p)->f30);
    func_02027FD8(((struct Obj01154 *)p)->fA4);
    func_0201C6EC(((struct Obj01154 *)p)->f88);
    func_0201C4C0(((struct Obj01154 *)p)->f88);
    func_02031140(((struct Obj01154 *)p)->f84);
    func_020450C8();
    func_020307B0(p);
}







void func_021D56FC(char *p,int mode)
{
    void *q;
    if (!((struct Obj01933 *)p)->f44) ((struct Obj01933 *)p)->f44=(void *)func_020450F0((int)5,(int)1,(u8)1,(int)30,4,11,1);
    q=((struct Obj01933 *)p)->f44;
    func_02043B5C(func_02045770(q),15);
    func_0201DD78(1,2,15);
    if (mode) {
        func_0201C7A4(func_02045770(q),0,0,((struct Obj01933 *)p)->f2C,((struct Obj01933 *)p)->f28);
    } else {
        ((struct Obj01933 *)p)->f80=func_0201CCE4(q, (int)0, (int)0, ((struct Obj01933 *)p)->f2C, ((struct Obj01933 *)p)->f28, (void *)((int)func_02012FFC()), ((struct Obj01933 *)p)->f84, (int)2, ((struct Obj01933 *)p)->fB0, 15);
        func_02028470((u8 *)(p+0xa8),(int)6);
    }
    func_0201F73C(q,1,(u16)(((struct Obj01933 *)p)->f8),12);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(5);
}







void func_021D57B8(char *p, int a)
{
    func_02045CAC(((struct Obj01933 *)p)->f20, a, ((struct Obj01933 *)p)->f2C);
    func_021D56FC(p, 0);
}






void func_021D57D0(void *p, int msg, int n, void *mon) {
func_02045CAC(*(void **)((unsigned)p+0x20),msg,*(void **)((unsigned)p+0x30));
func_0201EEF4(*(void **)((unsigned)p+0x24),0,mon);
func_0201EFA4(*(void **)((unsigned)p+0x24),1,n,3,1,1);
func_0201F250(*(void **)((unsigned)p+0x24),*(void **)((unsigned)p+0x2c),*(void **)((unsigned)p+0x30));
}






int func_021D580C(char *p)
{
    if (((struct Obj04496 *)p)->f80) {
        func_020286C4(((struct Obj04496 *)p)->f40, ((struct Obj04496 *)p)->f80, ((struct Obj04496 *)p)->f44);
        if (!func_02028484((struct Blk *)(p+0xa8), ((struct Obj04496 *)p)->f80)) return 0;
        func_0201CE48(((struct Obj04496 *)p)->f80);
        ((struct Obj04496 *)p)->f80=0;
    }
    return 1;
}






void func_021D584C(char *p)
{
    if (((struct Obj03265 *)p)->f7C) {
        func_0202F038(((struct Obj03265 *)p)->f7C);
        ((struct Obj03265 *)p)->f7C=0;
    }
    if (((struct Obj03265 *)p)->f80) {
        func_0201CE48(((struct Obj03265 *)p)->f80);
        ((struct Obj03265 *)p)->f80=0;
    }
    if (((struct Obj03265 *)p)->f44) {
        func_0201F7A8(((struct Obj03265 *)p)->f44,2);
        func_020456F8(((struct Obj03265 *)p)->f44);
        func_02041B6C(5);
    }
}






int func_021D5890(char *p,int mode)
{
    Config c;
    int result;
    c.size=((struct Obj01734 *)p)->fB0;
    c.flag=2;
    c.target=p+0x8c;
    switch (mode) {
    case 0: c.x=32; c.y=12; c.mode=1; break;
    case 1: c.x=32; c.y=24; c.mode=1; break;
    }
    c.z=13;
    c.w=3;
    ((struct Obj01734 *)p)->f8C=func_020457B0(100,((struct Obj01734 *)p)->fB0);
    func_02045CAC(((struct Obj01734 *)p)->f20,4,((struct Obj01734 *)p)->f8C);
    ((struct Obj01734 *)p)->f90=0x39e0;
    ((struct Obj01734 *)p)->f98=func_020457B0(100,((struct Obj01734 *)p)->fB0);
    func_02045CAC(((struct Obj01734 *)p)->f20,5,((struct Obj01734 *)p)->f98);
    ((struct Obj01734 *)p)->f9C=0x39e0;
    result=(int)func_02027778((struct TaskMenuTmpl *)(&c),((struct Obj01734 *)p)->fA4);
    func_02045808(((struct Obj01734 *)p)->f8C);
    func_02045808(((struct Obj01734 *)p)->f98);
    func_0207D658(0x04001050,9,-8);
    return result;
}







int func_021D5950(u8 *p, int x)
{
    return func_02045CAC((struct MsgBank *)(((struct Obj13972 *)p)->f20), x, ((struct Obj13972 *)p)->f2C);
}






void func_021D5960(char *p,int a,int b)
{
    void *q;
    if (((struct Obj05361 *)p)->f48) func_020452E8(((struct Obj05361 *)p)->f48);
    q=(void *)func_020450F0((int)6,(int)1,(u8)a,(int)30,b,11,1);
    ((struct Obj05361 *)p)->f48=q;
    func_02043B5C(func_02045770(q),15);
    func_0201DD78(1,2,15);
    func_0201C7A4(func_02045770(q),0,0,((struct Obj05361 *)p)->f2C,((struct Obj05361 *)p)->f28);
    func_0201F73C(q,1,(u16)(((struct Obj05361 *)p)->f4),12);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(6);
}






void func_021D59E4(char *p)
{
    void *q;
    if (((struct Obj05362 *)p)->f48) func_020452E8(((struct Obj05362 *)p)->f48);
    q=(void *)func_020450F0(6,1,9,30,6,11,1);
    ((struct Obj05362 *)p)->f48=q;
    func_02043B5C(func_02045770(q),15);
    func_0201DD78(1,2,15);
    func_0201C7A4(func_02045770(q),0,0,((struct Obj05362 *)p)->f2C,((struct Obj05362 *)p)->f28);
    func_0201F73C(q,1,(u16)(((struct Obj05362 *)p)->f4),12);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(6);
}






void func_021D5A60(char *p)
{
    func_0201F7A8(((struct Obj13973 *)p)->f48, 2);
    func_020456F8(((struct Obj13973 *)p)->f48);
    func_02041B6C(6);
}





void func_021D5A7C(char *p){if(((struct Obj04497 *)p)->f7C){func_0202F038(((struct Obj04497 *)p)->f7C);((struct Obj04497 *)p)->f7C=0;}((struct Obj04497 *)p)->f7C=func_0202EE8C(((struct Obj04497 *)p)->f84,((struct Obj04497 *)p)->f44,15,16,((struct Obj04497 *)p)->fB0);}






void func_021D5AB0(u8 *p, int x)
{
    func_021D97CC(x, ((struct Obj22941 *)p)->f2C);
}






static inline u32 func_021D5AC0_next(u32 mode)
{
    switch (mode) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 7:
        break;
    case 3:
        return mode;
    case 6:
        *(u32 *)(d_021DAC20 + 0xC8) = 1;
        break;
    case 8:
        func_0200F7DC();
        break;
    }
    return mode;
}






/*
 * 2026-10-05 (wD9r lane99): EXACT. The switch is a static inline helper that returns the mode; case 3
 *   returns from inside the switch, the other cases break to the final `return mode;`. The inline return
 *   copy into the result keeps case 3's own `b end` block until after jump-table threading (the stub at
 *   +0x26). No redundant statement and no cast: only the return-versus-break shape of case 3.
 *   Earlier lanes (D2 to D9r) tried every in-function form of case 3; all merged it with the end label.
 */
void func_021D5AC0(void *unused, u32 mode)
{
    u32 next = func_021D5AC0_next(mode);
    *(u32 *)(d_021DAC20 + 0xB0) = 1;
    *(u32 *)(d_021DAC20 + 0xB4) = next;
}





char *func_021D5B10(int heap,int size)
{
    char *p;
    p=func_02030734(heap,0xd4,1,d_021DAA40,0x88);
    if (g_021DAC20) func_02034714(d_021DAA54,0,d_021DAA54);
    g_021DAC20=p;
    ((struct Obj13974 *)p)->fB8=func_02030734(heap,size+0x40,0,d_021DAA40,0x8c);
    ((struct Obj13974 *)p)->fBC=size;
    return p;
}





void func_021D5B70(char *p){if(g_021DAC20){func_02156DE0(0,0);func_020307B0(((struct Obj22942 *)p)->fB8);func_020307B0(p);g_021DAC20=0;}}





int func_021D5BA0(char *p){return ((struct Obj22943 *)p)->fB8;}





int func_021D5BA8(char *p){if(!((struct Obj10437 *)p)->fC4){if(func_021C5B80())((struct Obj10437 *)p)->fC4=1;}return ((struct Obj10437 *)p)->fB0==0;}




int func_021D5BD4(char *p){((struct Obj22944 *)p)->fB0=0;if(!func_021C5928((void (*)(int,  int,  int))func_021D5AC0,d_021DAA58,d_021DAA60))return 0;func_02156DE0((int)func_021D5BA8,(int)p);return 1;}




int func_021D5C0C(char *p){if(*(int *)(g_021DAC20+0xb0)){if(!((struct Obj22945 *)p)->fB4)return 1;}return 0;}




int func_021D5C2C(char *p){if(((struct Obj10438 *)p)->fD0&&((struct Obj10438 *)p)->fC8)return 1;if(*(int *)(g_021DAC20+0xb0)&&((struct Obj10438 *)p)->fB4)return 1;return 0;}




int func_021D5C64(char *p,void *arg,int value){char buf[20];int ok=0;((struct Obj22946 *)p)->fB0=0;OS_SNPrintf(buf,20,d_021DAA74,value);if(func_021C5C04(arg,buf,(char *)d_021DAA54))ok=1;return ok;}





void func_021D5C9C(char *p)
{
    ((struct Obj13975 *)p)->fCC = 0;
    ((struct Obj13975 *)p)->fD0 = 0;
}




int func_021D5CAC(char *p)
{
    if (((struct Obj06460 *)p)->fD0) return 0;
    if (((struct Obj06460 *)p)->fCC) {
        if (++((struct Obj06460 *)p)->fCC>3600) {
            ((struct Obj06460 *)p)->fD0=1;
            if (!func_021C5DB4()) ((struct Obj06460 *)p)->fC8=1;
            return 0;
        }
    }
    return 1;
}




int func_021D5CF8(char *p){int ok=1;((struct Obj10439 *)p)->fB0=0;((struct Obj10439 *)p)->fCC=1;((struct Obj10439 *)p)->fD0=0;if(!func_021C5C38(p,0,1))ok=0;return ok;}




int func_021D5D24(char *p){int ok=1;((struct Obj06461 *)p)->fB0=0;((struct Obj06461 *)p)->fCC=1;((struct Obj06461 *)p)->fD0=0;if(!func_021C5CFC(p,((struct Obj06461 *)p)->fB8,((struct Obj06461 *)p)->fBC+0x40))ok=0;return ok;}




int func_021D5D58(char *p){int ok;if(!((struct Obj13976 *)p)->fC4){ok=0;((struct Obj13976 *)p)->fB0=0;if(!func_021C5B80())return ok;}return 1;}





void func_021D5D7C(char *p)
{
    if (func_021D5CAC(p) != 0)
        func_021C5AB8();
}




void *func_021D5D8C(u8 *p){return ((struct Obj22947 *)p)->fAC;}




/*
 * volatile: display register 04001000 read/write at 021D5DCA/021D5DD0.
 */
u8 *func_021D5D94(u32 heap)
{
    u8 *p;
    p=func_02030734(heap,0x4568,1,d_021DAB68,0xfe);
    ((struct Obj04498 *)p)->f43C4=heap;
    func_02034AC4((int)ov067_id);
    func_02043534(0); func_020435F4(0); func_0204363C(1);
    *(volatile u32 *)0x04001000|=0x10000;
    func_0207D46C();
    func_0203F8F4(((struct Obj04498 *)p)->f43C4);
    func_0204A48C((const struct Cfg *)d_020A1464,(u32)d_021DAA9C,((struct Obj04498 *)p)->f43C4);
    ((struct Obj04498 *)p)->fC=func_0204B100(40,0,((struct Obj04498 *)p)->f43C4);
    func_020433E0((const struct DispVram *)d_021DAA9C); func_0203FC28((struct DispConfig *)d_021DAA78);
    func_021D5F4C(p); func_021D614C(p); func_021D6CD8(p); func_021D6D5C(p);
    ((struct Obj04498 *)p)->f10=func_020056A0(func_021D60F8,p,0);
    ((struct Obj04498 *)p)->f455C=200;
    func_020435F4(31); func_02043534(27);
    return p;
}




void func_021D5E60(u8 *p){(((struct Obj03267 *)p)->f43C6)++;if(((struct Obj03267 *)p)->f43C6>=192)((struct Obj03267 *)p)->f43C6=0;func_0204A600();func_021D6678(p);func_021D6934((struct Obj *)p);}




void func_021D5E8C(u8 *p)
{
    Counter i;
    func_021D63E4(p);
    func_020307B0(((struct Obj04499 *)p)->f1C);
    func_0204B3B4(((struct Obj04499 *)p)->fB4);
    func_0204B3B4(((struct Obj04499 *)p)->fB8);
    i=0;
    do { if(*(void **)(p+i*4+0x20)) func_0204ADA4((u32)(*(void **)(p+i*4+0x20))); i++; } while(i<6);
    for(;i<13;i++) if(*(void **)(p+i*4+0x20)) func_0204A8D4((u32)(*(void **)(p+i*4+0x20)));
    for(;i<20;i++) if(*(void **)(p+i*4+0x20)) func_0204AFD8((u32)(*(void **)(p+i*4+0x20)));
    if(((struct Obj04499 *)p)->f14) func_02030EAC(((struct Obj04499 *)p)->f14);
    func_02030EAC(((struct Obj04499 *)p)->f10);
    func_0204B1CC(((struct Obj04499 *)p)->fC);
    func_0204A5AC();
    func_02040DA8(1,1,0); func_02040DA8(6,1,0);
    func_020403F4(5); func_020403F4(4);
    func_02040588(5,0); func_0203F9B4(); func_020307B0(p);
    func_02034A5C((int)ov_id);
}




void func_021D5F4C(u8 *p)
{
    struct BgTemplate_021D5BD4 b[7];
    b[6]=d_021DA758[0]; func_0203FCA0(0, (const struct BgTemplate_021D4240 *)(&b[6]), 0); func_02040588(0,1); func_020409B4(0);
    b[5]=d_021DA758[1]; func_0203FCA0(1, (const struct BgTemplate_021D4240 *)(&b[5]), 0); func_02040588(1,1); func_020409B4(1);
    b[4]=d_021DA758[2]; func_0203FCA0(3, (const struct BgTemplate_021D4240 *)(&b[4]), 0); func_02040588(3,1); func_020409B4(3);
    b[3]=d_021DA758[3]; func_0203FCA0(4, (const struct BgTemplate_021D4240 *)(&b[3]), 0); func_02040588(4,1); func_020409B4(4);
    b[2]=d_021DA758[4]; func_0203FCA0(5, (const struct BgTemplate_021D4240 *)(&b[2]), 0);
    func_02040C14(5,0,1,0); func_02041300(5,0,0,0,32,32,17); func_02040588(5,1); func_020409B4(5);
    b[1]=d_021DA758[5]; func_0203FCA0(6, (const struct BgTemplate_021D4240 *)(&b[1]), 0); func_02040588(6,1);
    func_02040C14(6,0,1,0); func_02041300(6,0,0,0,32,32,17); func_020409B4(6);
    b[0]=d_021DA758[6]; func_0203FCA0(7, (const struct BgTemplate_021D4240 *)(&b[0]), 0); func_02040588(7,1); func_020409B4(7);
}




void func_021D60F8(void *a, u8 *p)
{
    int n;
    u8 *base;
    int off;
    func_0204A648();
    n = ((struct Obj06462 *)p)->f4564 + 1;
    ((struct Obj06462 *)p)->f4564 = n;
    if (n % 10 == 1) {
        base = *(u8 * *)&((struct Obj22948 *)(*(u8 * *)&((struct Obj06462 *)p)->f18))->fC;
        off = (n / 10 + 2) * 32;
        func_0207E3D0(base + off, 64, 32);
        func_0207E468(base + off, 64, 32);
    }
    if (((struct Obj06462 *)p)->f4564 >= 80) ((struct Obj06462 *)p)->f4564 = 0;
}




void func_021D614C(u8 *p)
{
    void *h;
    h=func_020490F4((u32)((void *)143),((struct Obj00343 *)p)->f43C4);
    func_02049B68(h,2,4,0,0,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f0=func_02049740(h,8,4,0,0,((struct Obj00343 *)p)->f43C4);
    func_02049990(h,21,4,0,(u16)(((struct Obj00343 *)p)->f0),0,0,((struct Obj00343 *)p)->f43C4);
    func_02049990(h,24,7,0,(u16)(((struct Obj00343 *)p)->f4),0,0,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f1C=func_02049F78(h,2,(u32)((void **)(p+0x18)),((struct Obj00343 *)p)->f43C4);
    func_02049B68(h,2,0,0,0,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f4=func_02049740(h,8,0,0,0,((struct Obj00343 *)p)->f43C4);
    func_02049990(h,23,0,0,(u16)(((struct Obj00343 *)p)->f4),0,0,((struct Obj00343 *)p)->f43C4);
    func_02049990(h,24,1,0,(u16)(((struct Obj00343 *)p)->f4),0,0,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f38=(void *)func_0204A6C8(h,9,0,2,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f20=(void *)func_0204AC18(h,3,2,96,0,4,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f54=(void *)func_0204AF28(h,12,25,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f3C=(void *)func_0204A6C8(h,10,0,2,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f24=(void *)func_0204AC18(h,4,2,224,0,0,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f58=(void *)func_0204AF28(h,13,26,((struct Obj00343 *)p)->f43C4);
    func_021D6404(p); func_02049238(h);
}




void func_021D62A8(u8 *p){func_021D62F8(p,133,128);}




void func_021D62B4(u8 *p,unsigned int i){func_021D634C(p,i);}





void func_021D62BC(u8 *p, int i, u32 v)
{
    func_0204B878(*(void **)(p + i * 4 + 0x74), (u16)v);
}





void func_021D62D0(u8 *p, int i, int v)
{
    func_0204BA00(*(void **)(p + i * 4 + 0x74), (const struct Cmd *)v);
}





void func_021D62E0(u8 *p, int i)
{
    if (*(u32 *)(p + 0x74 + i * 4)) {
        func_0204B3B4(*(void **)(p + 0x74 + i * 4));
        *(u32 *)(p + 0x74 + i * 4) = 0;
    }
}




void func_021D62F8(u8 *p, int x, int y)
{
    struct Point_021D5BD4 pt;
    if (((struct Obj03266 *)p)->fAC == 0) {
        pt.x = x; pt.y = y; pt.f4 = 0; pt.f6 = 0; pt.f7 = 1;
        ((struct Obj03266 *)p)->fAC = func_0204B294((void *)((struct Obj03266 *)p)->fC, (u32)((struct Obj03266 *)p)->f3C, ((struct Obj03266 *)p)->f24, ((struct Obj03266 *)p)->f58, &pt, 1, ((struct Obj03266 *)p)->f43C4);
        func_0204B92C(((struct Obj03266 *)p)->fAC, 1);
        func_0204B3DC(((struct Obj03266 *)p)->fAC, 1);
    }
}











/*
 * lever: indexed p+0x74 array base and non-const table retain the original scheduling.
 */
void func_021D634C(u8 *p, unsigned int i)
{
    struct Point_021D634C pt;
    if (*(void **)(p + i*4 + 0x74)) func_0204B3B4(*(void **)(p+i*4+0x74));
    pt.x = d_021DAACC[i].x; pt.y = d_021DAACC[i].y;
    pt.f4 = i; pt.f6 = d_021DAACC[i].n; pt.f7 = 1;
    ((void **)(p + 0x74))[i] = func_0204B294((void *)((struct Obj02836 *)p)->fC, (u32)((struct Obj02836 *)p)->f38, ((struct Obj02836 *)p)->f20, ((struct Obj02836 *)p)->f54, &pt, 0, ((struct Obj02836 *)p)->f43C4);
    func_0204B8C4(((void **)(p+0x74))[i],0);
    func_0204B92C(((void **)(p+0x74))[i],1);
    func_0204B3DC(((void **)(p+0x74))[i],1);
    func_0204B570(((void **)(p+0x74))[i],2);
}












void func_021D63D4(u8 *p)
{
    func_0204B878(((struct Obj22949 *)p)->fA8, 2);
}











void func_021D63E4(u8 *p){int i;for(i=0;i<16;i++){u8 *q=p+i*4;if(*(struct Obj * *)&((struct Obj10440 *)q)->f74){func_0204B3B4(*(struct Obj * *)&((struct Obj10440 *)q)->f74);((struct Obj10440 *)q)->f74=0;}}}











void func_021D6404(u8 *p)
{
    void *h;
    h = func_020490F4(7, ((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f28 = (void *)func_0204ACEC(h, func_0201BC3C(), 2, 0, ((struct Obj00343 *)p)->f43C4);
    func_02049238(h);
    h = func_020490F4(143, ((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f5C = (void *)func_0204AF28(h, 14, 27, ((struct Obj00343 *)p)->f43C4);
    func_02049238(h);
}











void func_021D6458(struct Obj02181 *p, void *n, int i)
{
    struct Pair_021D634C a = d_021DA738;
    struct Pair_021D634C b = d_021DA748;
    struct Point_021D634C pt;
    void *h;
    h = func_020490F4(7, p->f43C4);
    p->f40 = (void *)func_0204A6C8(h,func_0201BA68((void *)n),0,2,p->f43C4);
    if(i==0) { pt.x=a.b; pt.y=b.b; }
    else { pt.x=a.a; pt.y=b.a; }
    pt.f4=0; pt.f6=3; pt.f7=1;
    p->fA8 = func_0204B294((void *)p->fC,(unsigned int)p->f40,p->f28,p->f5C,&pt,(u16)i,p->f43C4);
    func_0204B92C(p->fA8,0);
    func_0204B3DC(p->fA8,1);
    func_0204B6F4(p->fA8,func_0201BBE8(n),1);
    func_02049238(h);
}












void func_021D651C(u8 *p)
{
    func_0204B92C(((struct Obj22950 *)p)->fA8, 1);
}












void func_021D652C(char *p)
{
    func_0204B878(((struct Obj13977 *)p)->fA8, 1);
    func_0204B92C(((struct Obj13977 *)p)->fA8, 1);
}











void func_021D6548(void *unused, u8 *p)
{
    int line;
    int idx;
    int d;
    int v;
    idx = *(s16_021D634C *)(p + 0x43C6) + 1;
    line = *(volatile u16 *)0x04000006;
    idx = (line + idx) % 0xC0;
    if (*(volatile u16 *)0x04000004 & 2) {
        *(volatile u32 *)0x0400001C = *(s16_021D634C *)(p + 0x43C8 + idx * 2) & 0x1FF;
        v = *(int *)(p + 0x455C);
        if (v >= 0xC0) {
            func_0207E3D0(d_021DAA88, 0x142, 2);
            return;
        }
        if (v == 0) {
            func_0207E3D0(&d_021DAA88[9], 0x142, 2);
            return;
        }
        if (line > 200) {
            func_0207E3D0(d_021DAA88, 0x142, 2);
            return;
        }
        if (v > line) {
            func_0207E3D0(d_021DAA88, 0x142, 2);
            return;
        }
        d = line - v;
        if ((u32)d < 10 && d >= 0) {
            func_0207E3D0(&d_021DAA88[d], 0x142, 2);
            return;
        }
        func_0207E3D0(&d_021DAA88[9], 0x142, 2);
    }
}











void func_021D65F4(u8 *p)
{
    void *h;
    h = func_020490F4(143, ((struct Obj08108 *)p)->f43C4);
    func_02049990(h, 22, 3, 0, (u16)((struct Obj08108 *)p)->f4, 0, 0, ((struct Obj08108 *)p)->f43C4);
    func_02049238(h);
    ((struct Obj08108 *)p)->f14 = func_02005624((u32)func_021D6548, (u32)p, 0);
    func_02024230((s16_021D634C *)(p + 0x43c8), 192, 0x5b0, 0x1800);
}











void func_021D6650(u8 *p,int flag){if(flag){((struct Obj08109 *)p)->f4554=0;((struct Obj08109 *)p)->f4558=1;}else{((struct Obj08109 *)p)->f4554=65536;((struct Obj08109 *)p)->f4558=-1;}}











void func_021D6678(u8 *p)
{
    int v;
    if (((struct Obj03267 *)p)->f4558 != 0) {
        ((struct Obj03267 *)p)->f4554 += ((struct Obj03267 *)p)->f4558 << 10;
        v = ((struct Obj03267 *)p)->f4554 >> 12;
        func_02040588(3, 1);
        if (v > 10) { ((struct Obj03267 *)p)->f4558 = 0; return; }
        if (v < 0) { v = 0; func_02040588(3, 0); ((struct Obj03267 *)p)->f4558 = v; return; }
        func_0207D63C((void *)0x04000050, 8, 55, v, 8);
    }
}











void func_021D66D0(u8 *p, int n)
{
    float x = (float)(1.2 * (double)(float)n);
    int v;
    if (n > 100) v = 0;
    else v = (int)(120.0f - x);
    if (((struct Obj13978 *)p)->f455C > v) ((struct Obj13978 *)p)->f455C = v;
}











void func_021D6720(u8 *p, int i)
{
    struct Pos_021D634C pos;
    struct Pair_021D634C pair;
    void *h;
    func_021D6C48((char *)p,i,((struct Obj13979 *)p)->fB4);
    h = ((struct Obj13979 *)p)->fB4;
    pos = d_021DA730; pair = d_021DA750;
    func_0204B404(h,(const struct Vec2 *)(&pos),0); func_0204B5AC(h, (struct Pair_021D634C *)&pair);
    func_0204B92C(h,0); func_0204B3DC(h,0);
    func_0204B688(h,1); func_0204B570(h,2);
    *(void **)(p+i*24+0x40f4) = h;
}











void func_021D679C(u8 *p){if(*(struct Obj * *)&((struct Obj10441 *)p)->f0)func_0204B3DC(*(struct Obj * *)&((struct Obj10441 *)p)->f0,0);((struct Obj10441 *)p)->f0=0;}











void func_021D67B4(u8 *p, int i)
{
    struct Pos_021D634C pos;
    struct Pair_021D634C pair;
    void *h;
    func_021D6C90((char *)p,i,((struct Obj13980 *)p)->fB8);
    h = ((struct Obj13980 *)p)->fB8;
    pos = d_021DA734; pair = d_021DA740;
    func_0204B404(h,(const struct Vec2 *)(&pos),0); func_0204B5AC(h, (struct Pair_021D634C *)&pair);
    func_0204B92C(h,0); func_0204B3DC(h,0);
    func_0204B688(h,1); func_0204B570(h,2);
    *(void **)(p+i*24+0x40f4) = h;
}










/*
 * lever: spelled-out x assignments reuse its already-loaded halfword.
 */
void func_021D6830(struct Record *p)
{
    struct Pos_021D6830 pos;
    struct Pair_021D6830 scale;
    int a,b;
    if (p == 0) return;
    a = (s16_021D6830)(d_020A1B38[p->a >> 4][0] * 4) >> 12;
    b = (s16_021D6830)(d_020A1B38[p->b >> 4][0] * 3) >> 12;
    if (p->h) {
        func_0204B454(p->h, (struct PtS *)&pos, 0);
        pos.x = p->x + a + b;
        pos.y = (p->y + a + b + p->age) >> 2;
        if (p->age % 8 == 0) {
            if (p->x > 128) p->x = p->x - 1;
            else p->x = p->x + 1;
        }
        func_0204B404(p->h, (const struct Vec2 *)(&pos), 0);
        func_0204B3DC(p->h, 1);
        p->age++;
        if (pos.y > 25) {
            func_0204B5C0(p->h, (struct Pair_021D6830 *)&scale);
            scale.x -= 16;
            scale.y -= 16;
            if (scale.x < 0 || scale.y < 0) func_021D679C((u8 *)p);
            else func_0204B5AC(p->h, (struct Pair_021D634C *)&scale);
        }
        if (pos.y > 50) func_021D679C((u8 *)p);
    } else p->g = 1;
    if (p->g == 0) {
        p->a += (u16)(func_020056EC(12) + 200);
        p->b -= (u16)(func_020056EC(12) + 666);
    }
}










/*
 * lever: bind i+20 to n before indexing, sharing its scaled address.
 */
void func_021D6934(struct Obj *p)
{
    int active = 0;
    int i,n;
    for (i = 0; i < 20; i++) {
        if (p->records[i].c && !p->records[i].g) {
            func_021D6830(&p->records[i]);
            active = 1;
        }
    }
    if (active == 0) {
        for (i = 0; i < 20; i++) {
            n = func_020056EC(20);
            if (!p->records[n].c && p->records[n].d) {
                p->records[n].c = 1;
                p->records[n].x = func_020056EC(128) + 64;
                p->records[n].y = 0;
                func_021D67B4((u8 *)p, n);
                break;
            }
        }
    }
    for (i = 0; i < 10; i++) {
        n = i + 20;
        if (p->records[n].c && !p->records[n].g) {
            func_021D6830(&p->records[n]);
            active = 1;
        }
    }
    if (active == 0) {
        for (i = 0; i < 10; i++) {
            n = func_020056EC(10) + 20;
            if (!p->records[n].c && p->records[n].d) {
                p->records[n].c = 1;
                p->records[n].x = func_020056EC(128) + 64;
                p->records[n].y = 0;
                func_021D6720((u8 *)p, n);
                return;
            }
        }
    }
}










void func_021D6A70(u8 *p,int i,int a,int b,int c){if(a!=0 && a<=493){*(s16_021D6A70 *)(p+(u32)i*24+0x4104)=a;*(s16_021D6A70 *)(p+(u32)i*24+0x4106)=b;if(c>2)c=0;*(s16_021D6A70 *)((u32)p+(u32)i*24+0x4108)=c;}}











void func_021D6AA8(char *p, int i, u16 v)
{
    *(u16 *)(p + i * 0x18 + 0x4104) = v;
}










/*
 * lever: declare out2 before out to place out at sp+0x3c, out2 at sp+0x40.
 */
void func_021D6AB8(u8 *p)
{
    void *h;
    void *h2;
    void *buf;
    void *buf2;
    u8 *out2;
    u8 *out;
    int i,n,species,form,gender;
    u32 value;
    u16 id;
    h = func_020490F4(25, ((struct Obj03268 *)p)->f43C4);
    for (i = 0; i < 20; i++) {
        species = ((struct Obj *)p)->records[i].d;
        if (species) {
            buf = func_02049250(h,func_02020E60(species,2),((struct Obj03268 *)p)->f43C4);
            func_02062A98(buf,(void **)(&out));
            func_02082D44(((struct Obj22951 *)out)->fC,p+0xbc+i*0x224,32);
            func_020307B0(buf);
            buf2 = func_02049250(h,func_02020E60(species,1),((struct Obj03268 *)p)->f43C4);
            func_02062A4C(buf2,(void **)(&out2));
            func_02082D44(((struct Obj13981 *)out2)->f14,p+0xdc+i*0x224,512);
            func_020307B0(buf2);
        }
    }
    func_02049238(h);
    h2 = func_020490F4(7, ((struct Obj03268 *)p)->f43C4);
    for (i = 0; i < 10; i++) {
        n = i+20;
        species = ((struct Obj *)p)->records[n].d;
        if (species) {
            gender = ((struct Obj *)p)->records[n].f;
            form = (int)func_02019D30((u16)species,(u8)(((struct Obj *)p)->records[n].e));
            value = func_0201BB5C(species,form,gender,0);
            id = func_0201BABC(species,form,gender,0);
            buf2 = func_02049250(h2,id,((struct Obj03268 *)p)->f43C4);
            func_02062A4C(buf2,(void **)(&out2));
            func_02082D44(((struct Obj13981 *)out2)->f14,p+0xdc+n*0x224,512);
            func_020307B0(buf2);
            *(u32 *)(p+n*0x224+0x2dc) = value;
        }
    }
    func_02049238(h2);
}










void func_021D6C48(char *p,int i,void *h)
{
    Desc d;
    func_0204B7C8(h,(struct Struct36 *)(&d));
    func_02082D44(p+0xdc+i*0x224,(void *)(d.x[1]+0x6400000),0x200);
    func_0204B6F4(h,(u8)(*(u32 *)(p+i*0x224+0x2dc)),1);
}










void func_021D6C90(char *p,int i,void *h)
{
    Desc d;
    func_0204B7C8(h,(struct Struct36 *)(&d));
    func_02082D44(p+0xdc+i*0x224,(void *)(d.x[1]+0x6400000),0x200);
    func_020862F0(p+0xbc+i*0x224,0x20);
    func_0207E51C(p+0xbc+i*0x224,0x100,0x20);
}










/*
 * lever: narrow the helper result through a named u16 local before the call.
 */
void func_021D6CD8(u8 *p)
{
    struct Point_021D6830 pt;
    void *h;
    u16 n;
    h=func_020490F4(7,((struct Obj02474 *)p)->f43C4);
    n=func_0201BABC(1,0,0,0);
    ((struct Obj02474 *)p)->f44=(void *)func_0204A6C8(h,n,0,0,((struct Obj02474 *)p)->f43C4);
    pt.x=133; pt.y=128; pt.f4=0; pt.f6=3; pt.f7=2;
    ((struct Obj02474 *)p)->fB4=func_0204B294((void *)((struct Obj02474 *)p)->fC,(u32)((struct Obj02474 *)p)->f44,((struct Obj02474 *)p)->f28,((struct Obj02474 *)p)->f5C,&pt,0,((struct Obj02474 *)p)->f43C4);
    func_0204B92C(((struct Obj02474 *)p)->fB4,0);
    func_0204B3DC(((struct Obj02474 *)p)->fB4,0);
    func_02049238(h);
}









void func_021D6D5C(u8 *p)
{
    struct Point pt;
    void *h;
    h=func_020490F4(25,((struct Obj01544 *)p)->f43C4);
    ((struct Obj01544 *)p)->f34=(void *)func_0204AC18(h,func_02020E60(1,2),0,256,0,1,((struct Obj01544 *)p)->f43C4);
    ((struct Obj01544 *)p)->f50=(void *)func_0204A6C8(h,func_02020E60(1,1),0,0,((struct Obj01544 *)p)->f43C4);
    ((struct Obj01544 *)p)->f6C=(void *)func_0204AF28(h,1,0,((struct Obj01544 *)p)->f43C4);
    func_02049238(h);
    pt.x=156; pt.y=28; pt.f4=0; pt.f6=0; pt.f7=2;
    ((struct Obj01544 *)p)->fB8=func_0204B294((void *)((struct Obj01544 *)p)->fC,(unsigned int)((struct Obj01544 *)p)->f50,*(u32 *)&((struct Obj01544 *)p)->f34,*(u32 *)&((struct Obj01544 *)p)->f6C,&pt,0,((struct Obj01544 *)p)->f43C4);
    func_0204B92C(((struct Obj01544 *)p)->fB8,0);
    func_0204B3DC(((struct Obj01544 *)p)->fB8,0);
}









int func_021D6E08(char *p,int x)
{
    switch (x) {
    case 503:
        ((struct Obj00063 *)p)->f80=0xfff1;
        func_021D6EE0((u8 *)p,(int)func_021D6FF0,0xd3);
        return 1;
    case 502:
        ((struct Obj00063 *)p)->f80=0xfff2;
        func_021D6EE0((u8 *)p,(int)func_021D6FF0,0xd7);
        return 1;
    }
    if (x>=400) {
        ((struct Obj00063 *)p)->f80=0xfff3;
        func_021D6EE0((u8 *)p,(int)func_021D6FF0,0xdd);
        return 1;
    }
    return 0;
}









int func_021D6E70(u8 *p){u8 *q=*(u8 * *)&((struct Obj22952 *)p)->f20;if(((struct Obj10442 *)q)->f1C8==2)return 0;if(((struct Obj10442 *)q)->f50 && ((struct Obj10442 *)q)->fC==4)return 0;if(func_0203CD98())return 1;return 0;}










int func_021D6EA4(char *p)
{
    char *q = *(char * *)&((struct Obj22953 *)p)->f20;

    return ((struct Obj13982 *)q)->f50 != 0 && ((struct Obj13982 *)q)->fC == 0;
}









int func_021D6EBC(u8 *p){u8 *q=*(u8 * *)&((struct Obj22954 *)p)->f20;if(((struct Obj13983 *)q)->f50){unsigned int x=((struct Obj13983 *)q)->fC;if(x==0)return 1;if(x==4)return 1;}return 0;}









void func_021D6EDC(u8 *p,u32 v,int unused){((struct Obj22955 *)p)->f50=v;}









void func_021D6EE0(u8 *p,u32 v,int unused){func_021D6EDC(p,v,unused);}










void func_021D6EE8(char *p)
{
    if (func_020221A4() != 0)
        func_021D6EE0((u8 *)p, 0, 0x157);
}









void func_021D6F04(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj13984 *)p)->f18)) {
        func_0202208C(0,0,0,0,6,1,((struct Obj13984 *)p)->f0);
        func_021D6EE0((u8 *)p,(int)func_021D6EE8,0x16b);
    }
}









void func_021D6F44(u8 *p){if(func_021D5C0C((char *)(((struct Obj10443 *)p)->f8))){func_021D5B70((char *)(((struct Obj10443 *)p)->f8));((struct Obj10443 *)p)->f8=0;func_021D6EE0(p,(u32)func_021D706C,0x17c);}}










void func_021D6F70(unsigned char *a)
{
    if (((struct Obj05363 *)a)->fAB != 0)
        return;
    if (func_020362DC() == 0 && func_02035C60() == 0)
        return;
    if (((struct Obj05363 *)a)->fAD != 0) {
        func_02012E08((char *)(((struct Obj05363 *)a)->f2C));
        ((struct Obj05363 *)a)->fAD = 0;
    }
    func_021D8F58((char *)a);
    if (((struct Obj05363 *)a)->f8 != 0) {
        if (func_021D5D58((char *)(((struct Obj05363 *)a)->f8)) != 0)
            func_021D6EE0(a, (int)func_021D6F44, 0x191);
        func_021D6EE0(a, 0x021D706D, 0x193);
    } else {
        func_021D6EE0(a, 0x021D706D, 0x196);
    }
}









/*
 * extent: unit includes the 28-byte store-and-tail stub at 021D706C.
 */
void func_021D6FF0(char *p)
{
    int n=((struct Obj02182 *)p)->f80+29;
    if (((struct Obj02182 *)p)->f10) func_021B9774(((struct Obj02182 *)p)->f10);
    if (((struct Obj02182 *)p)->f80==0xfff0) n=39;
    else if (((struct Obj02182 *)p)->f80==0xfff1) n=40;
    else if (((struct Obj02182 *)p)->f80==0xfff2) n=41;
    else if (((struct Obj02182 *)p)->f80==0xfff3) n=38;
    else if (((struct Obj02182 *)p)->f80<=0 || ((struct Obj02182 *)p)->f80>=10) n=38;
    func_021D584C(*(char * *)&((struct Obj02182 *)p)->f18);
    func_021D5950((u8 *)(*(char * *)&((struct Obj02182 *)p)->f18),n);
    func_021D5960(*(char * *)&((struct Obj02182 *)p)->f18,1,16);
    func_021D6EE0((u8 *)p,(int)func_021D6F70,0x1b9);
}









void func_021D706C(char *p)
{
    ((struct Obj22957 *)(*(char * *)&((struct Obj22956 *)p)->f20))->f1C8=6;
    func_021D6EE0((u8 *)p,(int)func_021D6F04,0x1c9);
}









void func_021D7088(char *p) { if(func_021D580C(*(char * *)&((struct Obj22958 *)p)->f18) && (func_020362DC() || func_02035C60())) func_021D6EE0((u8 *)p,(int)func_021D706C,0x1d9); }









void func_021D70BC(char *p)
{
    Table_021D634C t=d_021DA844;
    if (((struct Obj06463 *)p)->fA8) {
        func_021D584C(*(char * *)&((struct Obj06463 *)p)->f18);
        func_021D5950((u8 *)(*(char * *)&((struct Obj06463 *)p)->f18),t.x[((struct Obj06463 *)p)->fA8]);
        func_021D5960(*(char * *)&((struct Obj06463 *)p)->f18,1,8);
        func_021D6EE0((u8 *)p,(int)func_021D7088,0x1f0);
    } else {
        func_021D6EE0((u8 *)p,(int)func_021D706C,0x1f3);
    }
}









void func_021D7130(char *p)
{
    if (func_021D580C(*(char **)(p + 0x18)) != 0) {
        int n = *(int *)(p + 0x78) - 1;
        *(int *)(p + 0x78) = n;
        if (n <= 0) {
            if (n == 0) {
                func_02005E9C();
                func_02005DE4(0);
                func_02005DF8(6);
            }
            if (func_020362DC() != 0 || func_02035C60() != 0) {
                func_021D6EE0((u8 *)p, (int)func_021D70BC, 0x20B);
            }
        }
    }
}










void func_021D7180(int a)
{
    if (func_021D580C((char *)(((struct Obj03792 *)a)->f18)) == 0)
        return;
    if (func_020362DC() == 0 && func_02035C60() == 0)
        return;
    if (((struct Obj03792 *)a)->f6C == 0) {
        func_021D6EE0((u8 *)a, (int)func_021D70BC, 0x217);
        return;
    }
    func_021D5A60((char *)(((struct Obj03792 *)a)->f18));
    func_021D57D0((void *)(((struct Obj03792 *)a)->f18), 0x16, ((struct Obj03792 *)a)->f6C,
                 (void *)(((struct Obj03792 *)a)->fC));
    func_021D56FC((char *)(((struct Obj03792 *)a)->f18), 0);
    func_02005DE4((void *)1);
    func_02005E64();
    func_02005D90(0x515, 0xffff);
    ((struct Obj03792 *)a)->f78 = 0xb4;
    func_021D6EE0((u8 *)a, (int)func_021D7130, 0x222);
}









void func_021D7204(u8 *p) { func_021D62BC(*(u8 * *)&((struct Obj10444 *)p)->f14,0,0); func_021D62B4((u8 *)(*(char * *)&((struct Obj10444 *)p)->f14),12); func_021D63D4(*(u8 * *)&((struct Obj10444 *)p)->f14); }








/*
 * lever: update the call-result local in both clamp arms to preserve its register.
 */
void func_021D7224(char *p)
{
    void *g;
    void *q;
    int size;
    int n;
    g=func_02009448(((struct Obj01736 *)p)->f28);
    if (((struct Obj01736 *)p)->fC) {
        func_020307B0(((struct Obj01736 *)p)->fC);
        ((struct Obj01736 *)p)->fC=0;
    }
    if (func_020076D0(((struct Obj01736 *)p)->f24,(int *)(p+0x48),(int *)(p+0x4c))) {
        q=func_02030734(((struct Obj01736 *)p)->f0,func_020173EC(),1,d_021DAB78,0x245);
        size=func_020173EC();
        func_02082D44(func_02009290(g),q,size);
        if (((struct Obj01736 *)p)->f6C) {
            n=func_02017E1C(q,158,0);
            if (n==100) ((struct Obj01736 *)p)->f6C=0;
            if (n+((struct Obj01736 *)p)->f6C>100) {
                ((struct Obj01736 *)p)->f6C=100-n;
                n=100;
            } else {
                n+=((struct Obj01736 *)p)->f6C;
            }
            func_02019CA0(q,n);
        }
        func_020074D8(((struct Obj01736 *)p)->f24,(const struct Sub02007454Entry *)((int)func_020185F4(q)));
        ((struct Obj01736 *)p)->fC=q;
        func_020092F8(g,0);
        func_020093D4(g,((struct Obj01736 *)p)->f7C);
    }
}








void func_021D72D8(char *p)
{
    NotifyCallback cb;
    func_02009448(((struct Obj01254 *)p)->f28);
    if (func_02012DD0(((struct Obj01254 *)p)->f2C)==2) {
        ((struct Obj01254 *)p)->fAD=0;
        ((struct Obj01254 *)p)->fAB=0;
        ((struct Obj01254 *)p)->fAE=0;
        func_021D584C(*(char * *)&((struct Obj01254 *)p)->f18);
        func_021D57D0(*(char * *)&((struct Obj01254 *)p)->f18,45,0,(void *)(*(int *)&((struct Obj01254 *)p)->fC));
        func_021D5960(*(char * *)&((struct Obj01254 *)p)->f18,1,4);
        func_021D62B4((u8 *)(*(char * *)&((struct Obj01254 *)p)->f14),0);
        func_021D62BC((u8 *)(*(char * *)&((struct Obj01254 *)p)->f14),6,7);
        func_021D62BC((u8 *)(*(char * *)&((struct Obj01254 *)p)->f14),0,1);
        cb.value=0; cb.object=p; cb.callback=(void (*)(char *))func_021D7204;
        func_021D62D0((u8 *)(*(char * *)&((struct Obj01254 *)p)->f14),0,(int)&cb);
        func_021D6650((u8 *)(*(char * *)&((struct Obj01254 *)p)->f14),0);
        func_021D6458((struct Obj02181 *)(*(char * *)&((struct Obj01254 *)p)->f14),(void *)func_020185F0(((struct Obj01254 *)p)->fC),0);
        func_021D652C(*(char * *)&((struct Obj01254 *)p)->f14);
        func_020061E4(0x658);
        func_021D6EE0((u8 *)p,(int)func_021D7180,0x295);
    }
}








void func_021D7390(char *p)
{
    if (func_021D6E08(p,func_021B99DC(((struct Obj06464 *)p)->f10))==0) {
        if (func_021B9790(((struct Obj06464 *)p)->f10)==0) {
            func_021B97F4(((struct Obj06464 *)p)->f10);
            func_02009448(((struct Obj06464 *)p)->f28);
            ((struct Obj06464 *)p)->fAE=1;
            func_021D6EE0((u8 *)p,(int)func_021D72D8,0x2ae);
        }
    }
}








void func_021D73D8(char *p)
{
    if (((struct Obj04500 *)p)->f78) {
        --((struct Obj04500 *)p)->f78;
        return;
    }
    if (func_0203CD98()) {
        if (func_021B95D4(8,((struct Obj04500 *)p)->f10)) {
            p[2]=1;
            p[3]=0;
            func_021BE79C((void *)func_021B973C(((struct Obj04500 *)p)->f10),(void *)((unsigned int)(p+2)),4);
            if (func_021B9748(((struct Obj04500 *)p)->f10)==0)
                func_021D6EE0((u8 *)p,(int)func_021D7390,0x2cd);
        }
    }
}








void func_021D7430(u8 *p) { if(((struct Obj05364 *)p)->f70<100) ++((struct Obj05364 *)p)->f70; func_021D66D0(*(u8 * *)&((struct Obj05364 *)p)->f14,((struct Obj05364 *)p)->f70); if(func_02012DD0(((struct Obj05364 *)p)->f2C)==1) { ((struct Obj05364 *)p)->f78=func_020056EC(190); func_021D6EE0((u8 *)p,(int)func_021D73D8,0x2e6); } }








void func_021D746C(int a)
{
    int b;
    int i;
    u8 *p;
    b=(int)func_02009448((void *)(((struct Obj03269 *)a)->f28));
    ((struct Obj03269 *)a)->fAB=1;
    func_021D7224((char *)a);
    if(func_021D6EBC((u8 *)a)==0) {
        func_021D7CB4(b,(u8 *)(((struct Obj03269 *)a)->f38));
        func_021D7DE8((u8 *)a,b,(u8 *)(((struct Obj03269 *)a)->f38));
        func_021D7C54((void *)b,(char *)(((struct Obj03269 *)a)->f38));
        func_020092D0((struct Sub02009210Obj *)b,*(u8 *)(((struct Obj03269 *)a)->f38+0x5a));
    } else {
        p=*(u8 * *)&((struct Obj03269 *)a)->f20+0xc;
        func_021D7D18((u8 *)a,b,((struct Obj06465 *)p)->f2,p[7],p[6],((struct Obj06465 *)p)->f4,func_020056EC(8));
        for(i=0;i<20;i++) func_02009348((struct Sub02009210Obj *)b,i,*(u16 *)(p+8+i*2),p[0x30+i]);
    }
    ((struct Obj03269 *)a)->fAD=1;
    func_02012DAC(((struct Obj03269 *)a)->f2C);
    func_021D6EE0((u8 *)a,(int)func_021D7430,0x311);
}








void func_021D751C(int a)
{
    if (func_021D5D58((char *)(((struct Obj13985 *)a)->f8))) {
        func_021D6EE0((u8 *)a, (int)func_021D7858, 0x319);
        return;
    }
    ((struct Obj13985 *)a)->f80 = 0xfff0;
    func_021D6EE0((u8 *)a, (int)func_021D6FF0, 0x31d);
}








void func_021D7560(u8 *p) { p[165]=0; func_020307B0(((struct Obj08110 *)p)->f40); p[174]=0; ((struct Obj08110 *)p)->f40=0; func_021D6EE0((u8 *)p,(int)func_021D751C,0x328); }








void func_021D758C(u8 *a)
{
    int b = (int)func_02012EBC((struct Big *)(((struct Obj13986 *)a)->f2C));
    if(func_02012E7C((char *)(((struct Obj13986 *)a)->f2C),4)==2) {
        func_0200734C((struct Sub02007324Ctrl *)b,4);
        func_020090F8((struct Sub020090B0Obj *)func_02009210((void *)b),1);
        func_021D6EE0(a,(int)func_021D7560,0x333);
    }
}








void func_021D75D0(int a)
{
    u16 checksum;
    int b;
    u8 *p;
    int x;
    b=(int)func_02012EBC((struct Big *)(((struct Obj03793 *)a)->f2C));
    p=(u8 *)func_021D5BA0((char *)(((struct Obj03793 *)a)->f8));
    checksum=func_0203F1FC(p,0x2600);
    if(checksum!=((struct Obj22959 *)p)->f2600) {
        ((struct Obj03793 *)a)->f80=0xfff0;
        func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x345);
        return;
    }
    ((struct Obj03793 *)a)->fAE=1;
    x=(int)func_02030734(((struct Obj03793 *)a)->f0,0x3000,0,d_021DAB78,0x34a);
    ((struct Obj03793 *)a)->f40=x;
    func_020072CC(b,4,((struct Obj03793 *)a)->f0,x,0x3000);
    func_02082D44(p,(void *)x,0x2600);
    func_02009108((struct Sub020090B0Obj *)func_02009210((void *)b),checksum);
    func_02012E4C((u8 *)((struct Obj03793 *)a)->f2C,4);
    func_021D6EE0((u8 *)a,(int)func_021D758C,0x355);
}








void func_021D768C(u8 *p) { p[166]=0; func_020307B0(((struct Obj08111 *)p)->f3C); p[174]=0; ((struct Obj08111 *)p)->f3C=0; func_021D6EE0((u8 *)p,(int)func_021D751C,0x360); }








void func_021D76B8(char *p) { int v; v=(int)func_02012EBC((struct Big *)(((struct Obj13987 *)p)->f2C)); if(func_02012E7C((char *)(((struct Obj13987 *)p)->f2C),7)==2) { func_0200734C((struct Sub02007324Ctrl *)v,7); func_021D6EE0((u8 *)p,(int)func_021D768C,0x36a); } }








void func_021D76F0(int a)
{
    int b;
    u8 *p;
    int x;
    u16 checksum;
    b=(int)func_02012EBC((struct Big *)(((struct Obj02475 *)a)->f2C));
    p=(u8 *)func_021D5BA0((char *)(((struct Obj02475 *)a)->f8));
    checksum=func_0203F1FC(p,0x6200);
    if(checksum!=((struct Obj22960 *)p)->f6200) {
        ((struct Obj02475 *)a)->f80=0xfff0;
        func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x378);
        return;
    }
    ((struct Obj02475 *)a)->fAE=1;
    x=(int)func_02030734(((struct Obj02475 *)a)->f0,0x6800,0,d_021DAB78,0x37d);
    *(int *)&((struct Obj02475 *)a)->f3C=x;
    func_020072CC(b,7,((struct Obj02475 *)a)->f0,*(int *)&((struct Obj02475 *)a)->f3C,0x6800);
    func_02082D44(p,((struct Obj02475 *)a)->f3C,0x6200);
    func_0200E8E0((void *)(*(int *)&((struct Obj02475 *)a)->f3C),1);
    func_02012E4C((u8 *)((struct Obj02475 *)a)->f2C,7);
    func_021D6EE0((u8 *)a,(int)func_021D76B8,0x383);
}








void func_021D7798(u8 *p) { if(func_0200C5F8(((struct Obj10445 *)p)->f30)) { p[174]=0; ((struct Obj10445 *)p)->f30=0; func_021D6EE0((u8 *)p,(int)func_021D751C,0x38e); } }








void func_021D77C4(int a,int n)
{
    u8 *p;
    int h;
    u16 checksum;
    ((struct Obj02837 *)a)->fA4=0;
    p=(u8 *)func_021D5BA0((char *)(((struct Obj02837 *)a)->f8));
    h=n/2;
    if(n>0x1fc0e) {
        ((struct Obj02837 *)a)->f80=0xfff0;
        func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x39d);
        return;
    }
    checksum=func_0203F1FC(p,n);
    if(checksum!=*(u16 *)(p+h*2)) {
        ((struct Obj02837 *)a)->f80=0xfff0;
        func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x3a3);
        return;
    }
    ((struct Obj02837 *)a)->fAE=1;
    ((struct Obj02837 *)a)->f30=(int)func_0200C5C8((void *)(((struct Obj02837 *)a)->f2C),p,n,((struct Obj02837 *)a)->f0);
    func_021D6EE0((u8 *)a,(int)func_021D7798,0x3a9);
}







void func_021D7858(int a)
{
    if(func_021D5C0C((char *)(((struct Obj03270 *)a)->f8))) {
        if(func_021D5C2C((char *)(((struct Obj03270 *)a)->f8))) {
            ((struct Obj03270 *)a)->f80=0xfff0;
            func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x3b6);
            return;
        }
        func_021D5B70((char *)(((struct Obj03270 *)a)->f8));
        ((struct Obj03270 *)a)->f8=0;
        if(((int *)a)[28]<100) ((int *)a)[28]+=10;
        func_021D66D0(*(unsigned char * *)&((struct Obj03270 *)a)->f14,((struct Obj03270 *)a)->f70);
        func_021D6EE0((u8 *)a,(int)func_021D7BDC,0x3c3);
    }
}







void func_021D78C0(int a)
{
    switch(((struct Obj02837 *)a)->fA7) {
    case 0: func_021D6EE0((u8 *)a,(int)func_021D75D0,0x3cb); break;
    case 1: func_021D77C4(a,(int)func_021D5D8C((u8 *)(((struct Obj02837 *)a)->f8))-2); break;
    case 2: func_021D6EE0((u8 *)a,(int)func_021D76F0,0x3d1); break;
    }
}







void func_021D7910(int a)
{
    if(func_021D5C2C((char *)(((struct Obj08112 *)a)->f8))) {
        ((struct Obj08112 *)a)->f80=0xfff0;
        func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x3dd);
        return;
    }
    if(func_021D5C0C((char *)(((struct Obj08112 *)a)->f8))) {
        func_021D5C9C((char *)(((struct Obj08112 *)a)->f8));
        func_021D6EE0((u8 *)a,(int)func_021D78C0,0x3e8);
    }
}







void func_021D7960(int a)
{
    if (func_021D5D24((char *)(((struct Obj13988 *)a)->f8))) {
        func_021D6EE0((u8 *)a, (int)func_021D7910, 0x3f1);
        return;
    }
    ((struct Obj13988 *)a)->f80 = 0xfff0;
    func_021D6EE0((u8 *)a, (int)func_021D6FF0, 0x3f5);
}






void func_021D79A4(int a)
{
    if(func_021D5C2C((char *)(((struct Obj05365 *)a)->f8))) {
        ((struct Obj05365 *)a)->f80=0xfff0;
        func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x3fe);
        return;
    }
    if(func_021D5C0C((char *)(((struct Obj05365 *)a)->f8))) {
        if((void *)(int)func_021D5D8C((u8 *)((int)((u8 *)(((struct Obj05365 *)a)->f8))))==0) {
            ((struct Obj05365 *)a)->f80=0xfff0;
            func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x407);
            return;
        }
        func_021D5C9C((char *)(((struct Obj05365 *)a)->f8));
        func_021D6EE0((u8 *)a,(int)func_021D7960,0x40d);
    }
}






void func_021D7A18(int a)
{
    if (func_021D5CF8((char *)(((struct Obj13989 *)a)->f8))) {
        func_021D6EE0((u8 *)a, (int)func_021D79A4, 0x415);
        return;
    }
    ((struct Obj13989 *)a)->f80 = 0xfff0;
    func_021D6EE0((u8 *)a, (int)func_021D6FF0, 0x419);
}






void func_021D7A5C(u8 *p)
{
    if (func_021D5C0C(((struct Obj01934 *)p)->f8)) {
        if (func_021D5C2C(((struct Obj01934 *)p)->f8)) {
            ((struct Obj01934 *)p)->f80 = 0xfff0;
            func_021D6EE0(p, (int)func_021D6FF0, 0x424);
            return;
        }
        switch (p[0xa7]) {
        case 0:
            if (func_021D5C64(((struct Obj01934 *)p)->f8, (void *)d_021DAB88, p[0xa5])) {
                func_021D6EE0(p, (int)func_021D7A18, 0x42b);
                return;
            }
            ((struct Obj01934 *)p)->f80 = 0xfff0;
            func_021D6EE0(p, (int)func_021D6FF0, 0x42f);
            return;
        case 1:
            if (func_021D5C64(((struct Obj01934 *)p)->f8, (void *)d_021DAB90, p[0xa4])) {
                func_021D6EE0(p, (int)func_021D7A18, 0x434);
                return;
            }
            ((struct Obj01934 *)p)->f80 = 0xfff0;
            func_021D6EE0(p, (int)func_021D6FF0, 0x438);
            return;
        case 2:
            if (func_021D5C64(((struct Obj01934 *)p)->f8, (void *)d_021DAB9C, p[0xa6])) {
                func_021D6EE0(p, (int)func_021D7A18, 0x43d);
                return;
            }
            ((struct Obj01934 *)p)->f80 = 0xfff0;
            func_021D6EE0(p, (int)func_021D6FF0, 0x441);
            return;
        }
    }
}






void func_021D7B68(char *p)
{
    switch (((struct Obj03271 *)p)->fA7) {
    case 0: ((struct Obj03271 *)p)->f8 = func_021D5B10(((struct Obj03271 *)p)->f0, func_0200C6E4() + 4); break;
    case 1: ((struct Obj03271 *)p)->f8 = func_021D5B10(((struct Obj03271 *)p)->f0, 0x20000); break;
    case 2: ((struct Obj03271 *)p)->f8 = func_021D5B10(((struct Obj03271 *)p)->f0, func_0200E8B0() + 4); break;
    }
    if (func_021D5BD4(((struct Obj03271 *)p)->f8)) {
        func_021D6EE0((u8 *)p, (int)func_021D7A5C, 0x458);
        return;
    }
    ((struct Obj03271 *)p)->f80 = 0xfff0;
    func_021D6EE0((u8 *)p, (int)func_021D6FF0, 0x45c);
}





void func_021D7BDC(char *p)
{
    if (((struct Obj05366 *)p)->fA5) {
        p[0xa7] = 0;
        func_021D6EE0((u8 *)p, (int)func_021D7B68, 0x465);
        return;
    }
    if (((struct Obj05366 *)p)->fA4) {
        p[0xa7] = 1;
        func_021D6EE0((u8 *)p, (int)func_021D7B68, 0x46a);
        return;
    }
    if (((struct Obj05366 *)p)->fA6) {
        p[0xa7] = 2;
        func_021D6EE0((u8 *)p, (int)func_021D7B68, 0x46f);
        return;
    }
    func_021D6EE0((u8 *)p, (int)func_021D746C, 0x472);
}





/*
 * extent: two zero alignment bytes at 021D7CB2 follow the return.
 */
void func_021D7C54(void *p, char *q)
{
    int changed = 0;
    int i;
    for (i = 0; i < 5; i++) {
        if (func_0203EFC8((const u8 *)func_02009390(p, i), (const u8 *)(q + 0x98 + i * 26), 26)) {
            changed = 1;
            break;
        }
    }
    if (changed) {
        for (i = 0; i < 5; i++) func_020093A8(p, i, q + 0x98 + i * 26);
        func_020093F0(p, 127);
    }
}





int func_021D7CB4(int a,u8 *p) { int i,result; u16 n; result=0; for(i=0;i<20;i++) { n=*(u16 *)(p+92+i*2); if(n!=0 && n<=626) { func_02009348((struct Sub02009210Obj *)a,i,n,p[132+i]); result=1; } } return result; }





int func_021D7CEC(int a,u8 *p) { int i,result; u16 n; result=0; for(i=0;i<20;i++) { n=*(u16 *)(p+92+i*2); if(n!=0 && n<=626) result=1; } return result; }





void func_021D7D18(u8 *p, int unused, int species, int gender, int form, int n, int value)
{
    int f;
    u8 v = value;
    void *h;
    int kind;
    int mapped;
    int g;
    if (species == 0 || species > 493) return;
    h = func_0202A128(((struct Obj10446 *)p)->f0);
    kind = 3;
    f = (int)func_02019D30((u16)species, (u8)form);
    g = func_02019C90(species, f, 20);
    mapped = func_02019D58(species, f);
    switch (g) {
    case 0: gender = 0; break;
    case 254: gender = 1; break;
    case 255: gender = 2; break;
    default: if (gender > 1) gender = func_020056EC(2); break;
    }
    if (func_0202A19C(((struct Obj10446 *)p)->f2C, h, species, gender, mapped)) kind = 2;
    if (v > 8) v = 0;
    func_0200E1A8(func_0200E0B0(((struct Obj10446 *)p)->f28), species, n, gender, mapped, v, kind);
    func_0202A170(h);
}





void func_021D7DE8(u8 *p,int a,u8 *records) { int i; u8 *r; for(i=0;i<10;i++) { r=records+i*8; if(((struct Obj05367 *)r)->f4==0) break; func_021D7D18(p,a,((struct Obj05367 *)r)->f4,r[9],r[8],((struct Obj05367 *)r)->f6,r[10]); } }





void func_021D7E20(u8 *p,u8 *list) { int i; u16 n; for(i=0;i<20;i++) { n=*(u16 *)(list+92+i*2); if(n!=0 && list[132+i]!=0 && n<=626) func_021D6AA8(*(char * *)&((struct Obj22962 *)p)->f14,i,n); } }





/*
 * lever: bind the record word before the call and use shared goto guards.
 */
void func_021D7E58(u8 *p, void *h, u8 *q, int *r)
{
    int i;
    int v;
    if (*r != 0) {
        ((struct Obj00063 *)p)->f80 = *r;
        func_021D6EE0(p, (int)func_021D6FF0, 0x500);
        return;
    }
    if (q[0x5b] != 0) goto unchanged;
    v = *(int *)q;
    if (v == func_020093D0(h)) goto unchanged;
    {
        ((struct Obj00063 *)p)->f7C = v;
        p[0xa4] = q[0x57];
        p[0xa5] = q[0x58];
        p[0xa6] = q[0x59];
        ((struct Obj00063 *)p)->f6C = ((struct Obj03794 *)q)->f54;
        if (p[0xa5]) p[0xa8] |= 1;
        if (p[0xa4]) p[0xa8] |= 2;
        if (p[0xa6]) p[0xa8] |= 4;
        for (i = 0; i < 10; i++) {
            if (*(u16 *)(q+i*8+4) == 0) break;
            func_021D6A70(((struct Obj00063 *)p)->f14, i+20, *(u16 *)(q+i*8+4), q[i*8+8], q[i*8+9]);
        }
        p[0xa9] = func_021D7CEC((int)h,q);
        func_021D7E20(p,q);
        func_021D6AB8(((struct Obj00063 *)p)->f14);
    }
    goto done;
unchanged:
    p[0xa9] = 0;
done:
    func_021D7BDC((char *)p);
}




int func_021D7F5C(char *p)
{
    int i, j;
    char *q;
    func_02009448(((struct Obj13991 *)p)->f28);
    q = *(char * *)&((struct Obj13991 *)p)->f20 + 0xc;
    for (i = 0; i < 20; i++) {
        for (j = i + 1; j < 20; j++) {
            if (*(u16 *)(q + i * 2 + 8) != 0 &&
                *(u16 *)(q + j * 2 + 8) == *(u16 *)(q + i * 2 + 8))
                return 0;
        }
    }
    return 1;
}




void func_021D7F9C(char *p)
{
    char *q, *data;
    void *v, *allocated;
    if (func_021D6E70((u8 *)p) && !func_021D6EBC((u8 *)p)) {
        if (((struct Obj00063 *)p)->f70<30) ++((struct Obj00063 *)p)->f70;
        func_021D66D0(*(u8 * *)&((struct Obj00063 *)p)->f14,((struct Obj00063 *)p)->f70);
        if (func_021D6E08(p,func_021B99DC(((struct Obj00063 *)p)->f10))) return;
        if (func_021B9790(((struct Obj00063 *)p)->f10)) return;
        q=(char *)func_021B97F4((u8 *)(((struct Obj00063 *)p)->f10));
        v=func_02009448(((struct Obj00063 *)p)->f28);
        data=q+0x80;
        allocated=func_02030734(((struct Obj00063 *)p)->f0,0x11c,1,d_021DAB78,0x573);
        ((struct Obj00063 *)p)->f38=allocated;
        func_02082D44(data,allocated,0x11c);
        func_021D7E58((u8 *)p,v,(u8 *)data,(int *)q);
        return;
    } else {
        ++((struct Obj00063 *)p)->f74;
        if (((struct Obj00063 *)p)->f70<30) ++((struct Obj00063 *)p)->f70;
        if (((struct Obj00063 *)p)->f74==360) {
            func_021D5950(*(u8 * *)&((struct Obj00063 *)p)->f18,43);
            func_021D59E4(*(char * *)&((struct Obj00063 *)p)->f18);
        } else if (((struct Obj00063 *)p)->f74==720) {
            func_021D5950(*(u8 * *)&((struct Obj00063 *)p)->f18,44);
            func_021D59E4(*(char * *)&((struct Obj00063 *)p)->f18);
        } else if (((struct Obj00063 *)p)->f74==1080) {
            if (func_021D6EA4(p)) func_021D5A60(*(char * *)&((struct Obj00063 *)p)->f18);
            if (func_021D7F5C(p)) {
                func_021D6EE0((u8 *)p,(int)func_021D746C,0x58c);
            } else {
                ((struct Obj00063 *)p)->f80=9;
                func_021D6EE0((u8 *)p,(int)func_021D6FF0,0x591);
            }
        }
        func_021D66D0(*(u8 * *)&((struct Obj00063 *)p)->f14,((struct Obj00063 *)p)->f70);
    }
}




void func_021D80B8(char *p)
{
    if (func_021D6E70((unsigned char *)p) && !func_021D6EBC((unsigned char *)p)) {
        if (func_021B95D4(2, ((struct Obj05368 *)p)->f10) && !func_021B9748(((struct Obj05368 *)p)->f10)) {
            func_021D6EE0((u8 *)p, (int)func_021D7F9C, 0x59d);
            return;
        }
    } else {
        if (func_021D6EA4(p)) {
            ((struct Obj05368 *)p)->f74 = 0;
            func_021D5950((u8 *)(*(char * *)&((struct Obj05368 *)p)->f18), 42);
            func_021D59E4(*(char * *)&((struct Obj05368 *)p)->f18);
        } else {
            ((struct Obj05368 *)p)->f74 = 0x42e;
        }
        func_021D6EE0((u8 *)p, (int)func_021D7F9C, 0x5aa);
    }
}




void func_021D8130(char *p) { if(func_021D580C(*(char * *)&((struct Obj22964 *)p)->f18)) func_021D6EE0((u8 *)p,(int)func_021D80B8,0x5b3); }




void func_021D8154(char *p)
{
    func_021D57B8(*(char * *)&((struct Obj03795 *)p)->f18, 11);
    func_021D5A7C(*(char * *)&((struct Obj03795 *)p)->f18);
    func_021D62E0(*(u8 * *)&((struct Obj03795 *)p)->f14, 8);
    func_021D65F4((u8 *)(*(char * *)&((struct Obj03795 *)p)->f14));
    func_021D6650((u8 *)(*(char * *)&((struct Obj03795 *)p)->f14), 1);
    func_021D62BC(*(u8 * *)&((struct Obj03795 *)p)->f14, 6, 5);
    func_021D62B4((u8 *)(*(char * *)&((struct Obj03795 *)p)->f14), 0);
    func_021D62B4((u8 *)(*(char * *)&((struct Obj03795 *)p)->f14), 12);
    func_020061E4(0x657);
    func_021D6EE0((u8 *)p, (int)func_021D8130, 0x5c3);
}




void func_021D81B4(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj22965 *)p)->f18)) {
        if (func_020362DC() || func_02035C60()) {
            func_021D6EE0((u8 *)p, (int)func_021D706C, 0x5d0);
        }
    }
}




void func_021D81E4(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj13992 *)p)->f18)) {
        func_021D57B8(*(char * *)&((struct Obj13992 *)p)->f18, 16);
        func_021D6EE0((u8 *)p, (int)func_021D81B4, 0x5de);
    }
}




void func_021D8210(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj22966 *)p)->f18)) {
        if (func_020362DC() || func_02035C60()) {
            func_021D6EE0((u8 *)p, (int)func_021D706C, 0x5e9);
        }
    }
}




void func_021D8244(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj13993 *)p)->f18)) {
        func_021D57B8(*(char * *)&((struct Obj13993 *)p)->f18, 49);
        func_021D6EE0((u8 *)p, (int)func_021D8210, 0x5f6);
    }
}




void func_021D8270(char *p)
{
    if (((struct Obj03796 *)p)->f64 % 110 == 0) func_020061E4(0x659);
    (((struct Obj03796 *)p)->f64)++;
    if (func_020279E8(((struct Obj03796 *)p)->f1C)) {
        if (func_02027A04(((struct Obj03796 *)p)->f1C) == 0) {
            if (func_020076D0(((struct Obj03796 *)p)->f24, (int *)(p + 0x48), (int *)(p + 0x4c)) == 0)
                func_021D6EE0((u8 *)p, (int)func_021D8244, 0x60f);
            else
                func_021D6EE0((u8 *)p, (int)func_021D8154, 0x612);
        } else {
            func_021D6EE0((u8 *)p, (int)func_021D706C, 0x616);
        }
        func_021D584C(*(char * *)&((struct Obj03796 *)p)->f18);
        func_02027858(((struct Obj03796 *)p)->f1C);
        *(unsigned short *)0x04001050 = 0;
        ((struct Obj03796 *)p)->f1C = 0;
    }
}




void func_021D8304(char *p)
{
    if (((struct Obj06466 *)p)->f64 % 110 == 0) func_020061E4(0x659);
    (((struct Obj06466 *)p)->f64)++;
    if (func_021D580C(*(char * *)&((struct Obj06466 *)p)->f18)) {
        ((struct Obj06466 *)p)->f1C = (void *)func_021D5890(*(char * *)&((struct Obj06466 *)p)->f18, 0);
        func_021D6EE0((u8 *)p, (int)func_021D8270, 0x632);
    }
}




void func_021D834C(char *p)
{
    func_021D584C(*(char * *)&((struct Obj03797 *)p)->f18);
    func_021D62B4((u8 *)(*(char * *)&((struct Obj03797 *)p)->f14), 0);
    func_021D62B4((u8 *)(*(char * *)&((struct Obj03797 *)p)->f14), 12);
    func_021D62B4((u8 *)(*(char * *)&((struct Obj03797 *)p)->f14), 6);
    func_021D62B4((u8 *)(*(char * *)&((struct Obj03797 *)p)->f14), 8);
    if (func_02009370((const struct Sub02009210Obj *)func_02009448(((struct Obj03797 *)p)->f28)))
        func_021D57B8(*(char * *)&((struct Obj03797 *)p)->f18, 21);
    else
        func_021D57B8(*(char * *)&((struct Obj03797 *)p)->f18, 10);
    func_021D6EE0((u8 *)p, (int)func_021D8304, 0x64c);
}




void func_021D83A4(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj22967 *)p)->f18)) {
        func_021D6EE0((u8 *)p, (int)func_021D834C, 0x68d);
    }
}




void func_021D83C8(char *p)
{
    if (func_020362DC() != 0 || func_02035C60() != 0) {
        func_021D5A60(*(char * *)&((struct Obj10447 *)p)->f18);
        func_020092E0((struct Sub02009210Obj *)func_02009448(((struct Obj10447 *)p)->f28), 1);
        p[0xaf] = 1;
        func_021D6EE0((u8 *)p, (int)func_021D8958, 0x6a2);
    }
}




void func_021D840C(char *p)
{
    if (func_020362DC() || func_02035C60()) {
        func_021D5950((u8 *)(*(char * *)&((struct Obj13994 *)p)->f18), 48);
        func_021D5960(*(char * *)&((struct Obj13994 *)p)->f18, 7, 14);
        func_021D6EE0((u8 *)p, (int)func_021D83C8, 0x6ab);
    }
}




void func_021D8448(char *p)
{
    func_021D5AB0(*(u8 * *)&((struct Obj06467 *)p)->f18, func_0200853C((const struct Sub0200852CObj *)func_02012944(((struct Obj22968 *)(*(char * *)&((struct Obj06467 *)p)->f20))->f4)));
    func_021D56FC(*(char * *)&((struct Obj06467 *)p)->f18, 1);
    func_021D5950((u8 *)(*(char * *)&((struct Obj06467 *)p)->f18), 47);
    func_021D5960(*(char * *)&((struct Obj06467 *)p)->f18, 7, 14);
    func_021D6EE0((u8 *)p, (int)func_021D840C, 0x6b7);
}




void func_021D8490(char *p)
{
    char *q;
    if (func_0203CD98()) {
        if (func_021D6E08(p, func_021B99DC(((struct Obj00063 *)p)->f10))) return;
        if (func_021B9790(((struct Obj00063 *)p)->f10)) return;
        q = (char *)func_021B97F4((u8 *)(((struct Obj00063 *)p)->f10));
        if (((struct Obj10448 *)q)->f0 == 2) {
            func_021D6EE0((u8 *)p, (int)func_021D8958, 0x6d4);
            return;
        }
        if (((struct Obj10448 *)q)->f0 == 0) {
            func_021D584C(*(char * *)&((struct Obj00063 *)p)->f18);
            func_021D6EE0((u8 *)p, (int)func_021D8448, 0x6d8);
            return;
        }
        ((struct Obj00063 *)p)->f80 = ((struct Obj10448 *)q)->f0;
        func_021D6EE0((u8 *)p, (int)func_021D6FF0, 0x6dc);
        return;
    } else {
        func_021D6EE0((u8 *)p, (int)func_021D8958, 0x6e2);
    }
}




void func_021D8520(char *p)
{
    int x;
    unsigned int v;
    if (func_0203CD98()) {
        if (func_021B95D4(9,*(void **)(p+0x10))) {
            v=(unsigned int)func_020071D8(*(void **)(p+0x28),&x);
            func_021BE79C((void *)func_021B973C(*(void **)(p+0x10)),(void *)v,0x80000);
            if (!func_021B9748(*(void **)(p+0x10)))
                func_021D6EE0((u8 *)p,(int)func_021D8490,0x6fa);
        }
    } else {
        if (func_020362DC() || func_02035C60())
            func_021D6EE0((u8 *)p,(int)func_021D8490,0x700);
    }
}




void func_021D8590(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj22969 *)p)->f18)) {
        if (func_020362DC() || func_02035C60()) {
            func_021D6EE0((u8 *)p, (int)func_021D83A4, 0x727);
        }
    }
}




void func_021D85C4(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj13995 *)p)->f18)) {
        func_021D57B8(*(char * *)&((struct Obj13995 *)p)->f18, 17);
        func_021D6EE0((u8 *)p, (int)func_021D8590, 0x739);
    }
}




void func_021D85F0(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj22970 *)p)->f18)) {
        if (func_020362DC() || func_02035C60()) {
            func_021D6EE0((u8 *)p, (int)func_021D706C, 0x746);
        }
    }
}




void func_021D8624(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj13996 *)p)->f18)) {
        func_021D57B8(*(char * *)&((struct Obj13996 *)p)->f18, 20);
        func_021D6EE0((u8 *)p, (int)func_021D85F0, 0x758);
    }
}




void func_021D8650(char *p,int x,int *q)
{
    int state;
    switch (*q) {
    case 0:
        state=((struct Obj22971 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f1C8;
        switch (state) {
        case 0:
            if (x==0) func_021D6EE0((u8 *)p,(int)func_021D83A4,0x774);
            else if (x==3) func_021D6EE0((u8 *)p,(int)func_021D83A4,0x777);
            else if (x==1) func_021D6EE0((u8 *)p,(int)func_021D85C4,0x77b);
            else if (x==2) func_021D6EE0((u8 *)p,(int)func_021D8624,0x77f);
            else if (x==4) func_021D6EE0((u8 *)p,(int)func_021D83A4,0x782);
            else func_021D6EE0((u8 *)p,(int)func_021D83A4,0x787);
            break;
        case 3:
            if (((struct Obj00063 *)p)->fAF==0) func_021D6EE0((u8 *)p,(int)func_021D8448,0x78c);
            else func_021D6EE0((u8 *)p,(int)func_021D8958,0x78f);
            break;
        }
        break;
    case 5:
        if (((struct Obj22972 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f1C8==3)
            func_021D6EE0((u8 *)p,(int)func_021D8958,0x797);
        else {
            ((struct Obj00063 *)p)->f80=*q;
            func_021D6EE0((u8 *)p,(int)func_021D6FF0,0x79b);
        }
        break;
    case 8:
        switch (((struct Obj22973 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f1C8) {
        case 0: func_021D6EE0((u8 *)p,(int)func_021D83A4,0x7a2); break;
        case 3: func_021D6EE0((u8 *)p,(int)func_021D8520,0x7a6); break;
        }
        break;
    default:
        ((struct Obj00063 *)p)->f80=*q;
        func_021D6EE0((u8 *)p,(int)func_021D6FF0,0x7ac);
        break;
    }
}




void func_021D8790(char *p)
{
    char *q;
    if (func_0203CD98()) {
        if (func_021D6E08(p,func_021B99DC(((struct Obj00063 *)p)->f10))) return;
        if (func_021B9790(((struct Obj00063 *)p)->f10)) return;
        q=(char *)func_021B97F4((u8 *)(((struct Obj00063 *)p)->f10));
        func_02082D44(q+0x80,*(char * *)&((struct Obj00063 *)p)->f20+0xc,0x44);
        ((struct Obj22975 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f50=1;
        func_021D8650(p,((struct Obj22974 *)q)->f80,(int *)q);
    } else {
        func_021D6EE0((u8 *)p,(int)func_021D83A4,0x7d4);
    }
}




void func_021D87F8(char *p)
{
    func_021D57B8(*(char * *)&((struct Obj08113 *)p)->f18,13);
    func_021D5A7C(*(char * *)&((struct Obj08113 *)p)->f18);
    if (func_0203CD98()) {
        if (func_021B95D4(0,((struct Obj08113 *)p)->f10)) {
            if (!func_021B9748(((struct Obj08113 *)p)->f10))
                func_021D6EE0((unsigned char *)p,(int)func_021D8790,0x7ea);
        }
    } else {
        if (func_020362DC() || func_02035C60())
            func_021D6EE0((unsigned char *)p,(int)func_021D8790,0x7f1);
    }
}




void func_021D885C(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj10450 *)p)->f18)) {
        if (func_020362DC() || func_02035C60()) {
            ((struct Obj22976 *)(*(char * *)&((struct Obj10450 *)p)->f20))->f1C8 = 1;
            func_021D584C(*(char * *)&((struct Obj10450 *)p)->f18);
            func_021D6EE0((u8 *)p, (int)func_021D6F04, 0x808);
        }
    }
}




void func_021D88A0(char *p)
{
    func_021D57B8(*(char * *)&((struct Obj22977 *)p)->f18, 19);
    func_021D6EE0((u8 *)p, (int)func_021D885C, 0x817);
}




void func_021D88C0(char *p)
{
    char *q;
    int state;
    if (func_0203CD98()) {
        if (func_021D6E08(p,func_021B99DC(((struct Obj00063 *)p)->f10))) return;
        if (func_021B9790(((struct Obj00063 *)p)->f10)) return;
        q=(char *)func_021B97F4((u8 *)(((struct Obj00063 *)p)->f10));
        state=((struct Obj22978 *)q)->f0;
        if (state==0 || state==8) {
            func_02082D44(q+0x80,*(char * *)&((struct Obj00063 *)p)->f20+0x1d8,0x80);
            ((struct Obj22979 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f1C8=5;
            func_021D6EE0((u8 *)p,(int)func_021D6F04,0x837);
        } else {
            ((struct Obj00063 *)p)->f80=state;
            func_021D6EE0((u8 *)p,(int)func_021D6FF0,0x842);
        }
    } else {
        ((struct Obj22980 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f1C8=5;
        func_021D6EE0((u8 *)p,(int)func_021D6F04,0x849);
    }
}




void func_021D8958(char *p)
{
    struct RtcDate_021D634C saved, current;
    u32 value;
    int day;
    if (func_02008BD0(func_02008B14(((struct Obj06468 *)p)->f28)) && ((struct Obj06468 *)p)->fAC) {
        func_021D6EE0((u8 *)p,(int)func_021D81E4,0x85c);
        return;
    }
    value=func_020093C8((const struct Sub02009210Obj *)func_02009448(((struct Obj06468 *)p)->f28));
    saved.year=(u8)(value>>24);
    saved.month=(u8)(value>>16);
    saved.day=(u8)(value>>8);
    saved.week=(u8)value;
    func_0203F4E4((struct RtcDate_021D634C *)&current);
    day=func_0203F540((struct RtcDate_021D634C *)&saved);
    if (day==func_0203F540((struct RtcDate_021D634C *)&current)) {
        func_021D6EE0((u8 *)p,(int)func_021D81E4,0x869);
        return;
    }
    if (func_0203CD98()) {
        if (func_021B95D4(1,((struct Obj06468 *)p)->f10) && !func_021B9748(((struct Obj06468 *)p)->f10))
            func_021D6EE0((u8 *)p,(int)func_021D88C0,0x871);
    } else {
        if (func_020362DC() || func_02035C60())
            func_021D6EE0((u8 *)p,(int)func_021D88C0,0x878);
    }
}




void func_021D8A38(char *p)
{
    if (((struct Obj13997 *)p)->f64 % 110 == 0) func_020061E4(0x659);
    ++((struct Obj13997 *)p)->f64;
    if (func_020362DC() || func_02035C60())
        func_021D6EE0((u8 *)p, (int)func_021D706C, 0x88e);
}




void func_021D8A7C(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj22981 *)p)->f18)) {
        func_021D6EE0((u8 *)p, (int)func_021D8A38, 0x8a0);
    }
}



void func_021D8A9C(char *p)
{
    if (((struct Obj02183 *)p)->f44) {
        func_020307B0(((struct Obj02183 *)p)->f44);
        ((struct Obj02183 *)p)->f44=0;
    }
    ((struct Obj02183 *)p)->f70=100;
    func_021D66D0(((struct Obj02183 *)p)->f14,100);
    func_021D57D0(((struct Obj02183 *)p)->f18,14,0,(void *)(((struct Obj02183 *)p)->fC));
    func_021D56FC(((struct Obj02183 *)p)->f18,0);
    func_021D62B4(((struct Obj02183 *)p)->f14,8);
    func_021D6650(((struct Obj02183 *)p)->f14,0);
    func_021D62B4(((struct Obj02183 *)p)->f14,0);
    func_021D62BC(((struct Obj02183 *)p)->f14,4,6);
    func_020061E4(0x658);
    func_021D6EE0((u8 *)p,(int)func_021D8A7C,0x8bd);
}



void func_021D8B0C(char *p)
{
    if (((struct Obj03272 *)p)->f70<100) ++((struct Obj03272 *)p)->f70;
    func_021D66D0(((struct Obj03272 *)p)->f14,((struct Obj03272 *)p)->f70);
    switch (func_02012DD0(((struct Obj03272 *)p)->f2C)) {
    case 1:
        if (((struct Obj03272 *)p)->f34) {
            func_020307B0(((struct Obj03272 *)p)->f34);
            ((struct Obj03272 *)p)->f34=0;
        }
        break;
    case 3:
        func_0203C9AC(0,0,0,0x3f3);
        func_0203C938(0);
        break;
    case 2:
        p[0xad]=0;
        func_021D6EE0((u8 *)p,(int)func_021D8A9C,0x8e6);
        break;
    }
}



/*
 * lever: func_02012F2C leaves its return in r0 for func_02008DF0.
 */
void func_021D8B7C(char *p)
{
    void *q;
    struct RtcDate_021D8A9C date;
    q=func_02009448(((struct Obj05369 *)p)->f28);
    p[0xaa]=0;
    func_0203F4E4((struct RtcDate_021D634C *)&date);
    func_020093CC(q, (date.year << 24) | ((date.month & 255) << 16) | ((date.day & 255) << 8) | date.week);
    if (func_020093D8(q)!=127) {
        func_02009428(q,1);
        func_020093F0(q,126);
    }
    ((struct Obj05369 *)p)->f70=50;
    func_02008DF0(func_02012F2C(((struct Obj05369 *)p)->f2C),119);
    p[0xad]=1;
    func_02012DAC((int)(((struct Obj05369 *)p)->f2C));
    func_021D6EE0((u8 *)p,(int)func_021D8B0C,0x914);
}



void func_021D8C04(char *p)
{
    char *q;
    int state;
    func_02009448(((struct Obj00063 *)p)->f28);
    func_021D6934(((struct Obj00063 *)p)->f14);
    if (func_021D6EA4(p)) {
        if (((struct Obj00063 *)p)->f74==0) {
            func_021D5950(*(u8 * *)&((struct Obj00063 *)p)->f18,42);
            func_021D59E4(*(char * *)&((struct Obj00063 *)p)->f18);
        } else if (((struct Obj00063 *)p)->f74==360) {
            func_021D5950(*(u8 * *)&((struct Obj00063 *)p)->f18,43);
            func_021D59E4(*(char * *)&((struct Obj00063 *)p)->f18);
        } else if (((struct Obj00063 *)p)->f74==720) {
            func_021D5950(*(u8 * *)&((struct Obj00063 *)p)->f18,44);
            func_021D59E4(*(char * *)&((struct Obj00063 *)p)->f18);
        }
        ++((struct Obj00063 *)p)->f74;
    }
    if (func_021D6E70((u8 *)p)) {
        if (((struct Obj00063 *)p)->f70<50) ++((struct Obj00063 *)p)->f70;
        func_021D66D0(*(u8 * *)&((struct Obj00063 *)p)->f14,((struct Obj00063 *)p)->f70);
        if (func_021D6E08(p,func_021B99DC(((struct Obj00063 *)p)->f10))) return;
        if (func_021B9790(((struct Obj00063 *)p)->f10)) return;
        q=(char *)func_021B97F4((u8 *)(((struct Obj00063 *)p)->f10));
        if (func_021D6EA4(p)) func_021D5A60(*(char * *)&((struct Obj00063 *)p)->f18);
        state=((struct Obj22982 *)q)->f0;
        if (state==0) {
            func_021D6EE0((u8 *)p,(int)func_021D8B7C,0x955);
            return;
        }
        ((struct Obj00063 *)p)->f80=state;
        func_021D6EE0((u8 *)p,(int)func_021D6FF0,0x959);
        return;
    } else {
        func_021D66D0(*(u8 * *)&((struct Obj00063 *)p)->f14,((struct Obj00063 *)p)->f68);
        if (++((struct Obj00063 *)p)->f68==100) {
            if (func_021D6EA4(p)) func_021D5A60(*(char * *)&((struct Obj00063 *)p)->f18);
            func_021D6EE0((u8 *)p,(int)func_021D8B7C,0x967);
        }
    }
}



/*
 *   Run 2 also left ov114 0x021B973C unresolved; S23 has since verified its
 *   pkt_ov114_021B973C shard. No caller retry while ARM9 remains blocked.
 *   extern unsigned int func_02031994(void *, int *);
 *   unsigned int func_020071D8(char *p, int *out) {
 *       return func_02031994(*(void **)(p + 0x10), out);
 *   }
 */
void func_021D8D08(char *p)
{
    int x;
    unsigned int v;
    func_02009448(*(void **)(p+0x28));
    if (func_021D580C(*(char **)(p+0x18))) {
        *(int *)(p+0x74)=0;
        if (func_021D6E70((u8 *)p)) {
            if (func_021B95D4(3,*(void **)(p+0x10))) {
                v=(unsigned int)func_020071D8(*(void **)(p+0x28),&x);
                func_021BE79C((void *)func_021B973C(*(void **)(p+0x10)),(void *)v,0x80000);
                func_021D66D0(*(void **)(p+0x14),0);
                *(int *)(p+0x70)=0;
                if (!func_021B9748(*(void **)(p+0x10)))
                    func_021D6EE0((u8 *)p,(int)func_021D8C04,0x986);
            }
        } else {
            func_021D66D0(*(void **)(p+0x14),0);
            func_021D6EE0((u8 *)p,(int)func_021D8C04,0x98c);
        }
    }
}



void func_021D8D98(char *p)
{
    if (--((struct Obj03798 *)p)->f60==0) {
        func_021D65F4((unsigned char *)(*(char * *)&((struct Obj03798 *)p)->f14));
        func_021D57B8(*(char * *)&((struct Obj03798 *)p)->f18,8);
        func_021D5A7C(*(char * *)&((struct Obj03798 *)p)->f18);
        func_021D6650(((struct Obj03798 *)p)->f14,1);
        func_021D62BC(((struct Obj03798 *)p)->f14,4,5);
        func_021D62BC(((struct Obj03798 *)p)->f14,0,0);
        func_021D62B4(((struct Obj03798 *)p)->f14,12);
        func_020061E4(0x657);
        func_021D6EE0((u8 *)p,(int)func_021D8D08,0x9a8);
    }
}



void func_021D8DFC(char *p) { if(--((struct Obj10451 *)p)->f60==0) { func_021D62B4(((struct Obj10451 *)p)->f14,4); ((struct Obj10451 *)p)->f60=60; func_021D6EE0((u8 *)p,(int)func_021D8D98,0x9b9); } }



void func_021D8E28(char *p)
{
    if (--((struct Obj06469 *)p)->f60 == 0) {
        func_021D62BC(((struct Obj06469 *)p)->f14, 0, 1);
        func_021D62B4(((struct Obj06469 *)p)->f14, 2);
        func_021D62B4(((struct Obj06469 *)p)->f14, 3);
        ((struct Obj06469 *)p)->f60 = 15;
        func_021D6EE0((u8 *)p, (int)func_021D8DFC, 0x9cf);
    }
}



void func_021D8E68(char *p) { if(--((struct Obj08114 *)p)->f60==0) { func_021D62A8(((struct Obj08114 *)p)->f14); func_021D651C(((struct Obj08114 *)p)->f14); ((struct Obj08114 *)p)->f60=70; func_021D6EE0((u8 *)p,(int)func_021D8E28,0x9e4); } }



void func_021D8E98(char *p) { func_021D6458(((struct Obj10452 *)p)->f14,(void *)func_020185F0(((struct Obj10452 *)p)->fC),1); ((struct Obj10452 *)p)->f60=10; func_021D6EE0((u8 *)p,(int)func_021D8E68,0x9f6); }



void func_021D8EC4(char *p)
{
    void *v;
    void *q;
    void *t;
    v=func_02009448(((struct Obj01545 *)p)->f28);
    if (((struct Obj01545 *)p)->fC) {
        func_020307B0(((struct Obj01545 *)p)->fC);
        ((struct Obj01545 *)p)->fC=0;
    }
    t=func_02007A18(((struct Obj01545 *)p)->f24,((struct Obj01545 *)p)->f48,((struct Obj01545 *)p)->f4C);
    if (t) {
        q=func_0201747C(t,((struct Obj01545 *)p)->f0);
        func_02009294(v,q);
        ((struct Obj01545 *)p)->fC=q;
        func_02007664(((struct Obj01545 *)p)->f24,((struct Obj01545 *)p)->f48,((struct Obj01545 *)p)->f4C);
        func_020092F8(v,1);
        ((struct Obj01545 *)p)->fAA=1;
    }
    func_021D62B4(((struct Obj01545 *)p)->f14,0);
    func_021D62B4(((struct Obj01545 *)p)->f14,12);
    func_021D6EE0((u8 *)p,(int)func_021D8E98,0xa2a);
}




void func_021D8F3C(char *p)
{
    if (*(u32 *)&((struct Obj08115 *)p)->f10 != 0) {
        func_021B9774(((struct Obj08115 *)p)->f10);
        func_021B9838(((struct Obj08115 *)p)->f10);
        *(u32 *)&((struct Obj08115 *)p)->f10 = 0;
    }
}



/*
 * extent: two zero alignment bytes follow the return.
 */
void func_021D8F58(char *p)
{
    void *v;
    void *q;
    v=func_02009448(((struct Obj02476 *)p)->f28);
    if (((struct Obj02476 *)p)->f34) {
        func_02082D44(((struct Obj02476 *)p)->f34,v,func_02009228());
        func_020307B0(((struct Obj02476 *)p)->f34);
        ((struct Obj02476 *)p)->f34=0;
    }
    if (((struct Obj02476 *)p)->fAA) {
        q=func_02009290(v);
        func_020075B0(((struct Obj02476 *)p)->f24,((struct Obj02476 *)p)->f48,((struct Obj02476 *)p)->f4C,func_020185F4(q));
        func_02017528(q);
        func_020092F8(v,0);
        ((struct Obj02476 *)p)->fAA=0;
    }
}



/*
 * interface: 0203159C returns the allocation live in r0 (original store
 * at 020315C0, then return); legacy matched definition says void.
 */
int func_021D8FBC(void *a,int b,char *q)
{
    char *p;
    int value;
    func_02034AC4((int)ov114_id);
    func_0203064C(1,98,0x88000);
    p=func_0203159C(a,0xb0,98);
    func_02082BCC(p,0,0xb0);
    ((struct Obj01059 *)p)->f0=98;
    if (!q) func_02034714(d_021DABA4,0,d_021DABA4);
    if (q) {
        *(char * *)&((struct Obj01059 *)p)->f20=q;
        ((struct Obj01059 *)p)->f2C=((struct Obj03799 *)q)->f4;
        ((struct Obj01059 *)p)->f28=func_02012EBC(((struct Obj03799 *)q)->f4);
        value=func_0200853C((const struct Sub0200852CObj *)func_02012944(((struct Obj03799 *)q)->f4));
        ((struct Obj01059 *)p)->f24=func_0201293C(((struct Obj03799 *)q)->f4);
        ((struct Obj01059 *)p)->f48=((struct Obj03799 *)q)->f1D0;
        ((struct Obj01059 *)p)->f4C=((struct Obj03799 *)q)->f1D2;
        ((struct Obj01059 *)p)->fAC=func_020092EC((const struct Sub02009210Obj *)func_02009448(((struct Obj01059 *)p)->f28));
        ((struct Obj01059 *)p)->fAF=((struct Obj01059 *)p)->fAC;
        func_02009448(((struct Obj01059 *)p)->f28);
        switch (((struct Obj03799 *)q)->f1C8) {
        case 0:
            if (!value) func_02034714(d_021DABA4,0,d_021DABA4);
            func_021D6EE0((u8 *)p,(int)func_021D87F8,0xa89);
            break;
        case 1:
            if (!value) func_02034714(d_021DABA4,0,d_021DABA4);
            func_021D6EE0((u8 *)p,(int)func_021D8EC4,0xa8d);
            break;
        case 2:
            if (!value) func_02034714(d_021DABA4,0,d_021DABA4);
            func_021D6EE0((u8 *)p,(int)func_021D8EC4,0xa91);
            break;
        case 3:
            if (!value) func_02034714(d_021DABA4,0,d_021DABA4);
            func_021D6EE0((u8 *)p,(int)func_021D87F8,0xa95);
            break;
        case 4:
            func_021D6EE0((u8 *)p,(int)func_021D88A0,0xa98);
            break;
        }
        if (*(int *)&((struct Obj03799 *)q)->f1C8!=4) {
            ((struct Obj01059 *)p)->f10=func_021B9800(98,value,(int)(q+0x54));
            func_02156DC4((int)func_021D8F3C,(int)p);
        }
    }
    ((struct Obj01059 *)p)->f14=func_021D5D94(((struct Obj01059 *)p)->f0);
    ((struct Obj01059 *)p)->f18=func_021D54F4(((struct Obj01059 *)p)->f0,39);
    func_0202208C(0,1,1,0,6,1,((struct Obj01059 *)p)->f0);
    func_0203D34C(0,((struct Obj01059 *)p)->f0);
    return 1;
}



int func_021D9158(void *a, int b, int c, char *p)
{
    void (*callback)(char *);
    int result;
    callback=*(void (**)(char *))(p+0x50);
    result=1;
    if (func_020221A4() && !((struct Obj01406 *)p)->fAE && func_0200FB24()) {
        if (((struct Obj01406 *)p)->f8) func_021D5D58(((struct Obj01406 *)p)->f8);
        func_021B9774(((struct Obj01406 *)p)->f10);
        if (((struct Obj01406 *)p)->fAD) {
            func_02012E08(((struct Obj01406 *)p)->f2C);
            ((struct Obj01406 *)p)->fAD=0;
        }
        func_021D8F58(p);
        if (((struct Obj01406 *)p)->fAB) func_0200F7C0(41);
        func_0202223C(0,0);
        func_0202223C(1,0);
        func_02157170(1,0);
        ((struct Obj22983 *)(*(char * *)&((struct Obj01406 *)p)->f20))->f1C8=7;
        return 1;
    }
    if (callback) { callback(p); result=0; }
    if (((struct Obj01406 *)p)->f1C) func_02027974(((struct Obj01406 *)p)->f1C);
    if (((struct Obj01406 *)p)->f8) func_021D5D7C(((struct Obj01406 *)p)->f8);
    func_021D5E60(((struct Obj01406 *)p)->f14);
    func_021D562C(((struct Obj01406 *)p)->f18);
    return result;
}



/*
 * evidence: unlabelled ov009 02156DE0 leaf filed and verified before caller rerun.
 */
int func_021D920C(void *a, int b, int c, char *p)
{
    if (!func_020221A4()) return 0;
    if (((struct Obj00990 *)p)->f1C) func_02027858(((struct Obj00990 *)p)->f1C);
    if (((struct Obj00990 *)p)->f38) {
        func_020307B0(((struct Obj00990 *)p)->f38);
        ((struct Obj00990 *)p)->f38=0;
    }
    func_021D5644(((struct Obj00990 *)p)->f18);
    func_021D5E8C(((struct Obj00990 *)p)->f14);
    func_021D5B70(((struct Obj00990 *)p)->f8);
    if (((struct Obj00990 *)p)->f30) func_020307B0(((struct Obj00990 *)p)->f30);
    if (((struct Obj00990 *)p)->f3C) func_020307B0(((struct Obj00990 *)p)->f3C);
    if (((struct Obj00990 *)p)->f40) func_020307B0(((struct Obj00990 *)p)->f40);
    if (((struct Obj00990 *)p)->fC) func_020307B0(((struct Obj00990 *)p)->fC);
    if (((struct Obj00990 *)p)->f44) func_020307B0(((struct Obj00990 *)p)->f44);
    if (func_0203CD98()) func_02156DE0(0,0);
    if (((struct Obj00990 *)p)->f10) {
        func_021B9838(((struct Obj00990 *)p)->f10);
        func_02156DC4(0,0);
    }
    func_020315D4(a);
    func_020306F0(98);
    func_02034A5C((int)ov114_id);
    return 1;
}




void func_021D92B8(u8 *p)
{
    if (((struct Obj10453 *)p)->f1C) {
        func_02051C6C(((struct Obj10453 *)p)->f1C);
        *(u32 *)&((struct Obj10453 *)p)->f1C = 0;
    }
}



u8 *func_021D92CC(u32 heap,u32 bank)
{
    u8 *p;
    p=func_02030734(heap,0xb4,1,d_021DABA8,0x9b);
    ((struct Obj00500 *)p)->fB0=heap;
    func_02045088(((struct Obj00500 *)p)->fB0);
    func_0201DD60();
    ((struct Obj00500 *)p)->f88=func_0203101C(((struct Obj00500 *)p)->fB0,((struct Obj00500 *)p)->fB0,2,0);
    ((struct Obj00500 *)p)->f8C=func_0201C440((void *)(u32)((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f2C=func_020457B0(400,((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f30=func_020457B0(400,((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f28=func_0201D7EC(23,0,0,0,((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f20=func_02045B38(0,2,(u16)bank,((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f24=func_0201EC64(((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->fAC=func_02027F60(5,9,*(u32 *)&((struct Obj00500 *)p)->f28,((struct Obj00500 *)p)->f8C,((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f0=func_0201F5DC((void *)1,12,0,((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f8=func_0201F5DC((void *)5,12,0,((struct Obj00500 *)p)->fB0);
    ((struct Obj00500 *)p)->f4=func_0201F5DC((void *)6,12,0,((struct Obj00500 *)p)->fB0);
    func_02049B40(23,5,4,352,32,((struct Obj00500 *)p)->fB0);
    func_02049B40(23,5,0,352,32,((struct Obj00500 *)p)->fB0);
    return p;
}




void func_021D9404(char *p)
{
    func_020310C4(((struct Obj13998 *)p)->f88);
    func_0201C4E4(((struct Obj13998 *)p)->f8C);
}



void func_021D941C(u8 *p)
{
    u32 a;
    int i;
    func_0203FB44(1,(u16)(((struct Obj00534 *)p)->f0),(u16)(((struct Obj00534 *)p)->f0>>16));
    a=((struct Obj00534 *)p)->f8>>16;
    func_0203FB44(5,(u16)(((struct Obj00534 *)p)->f8),(u16)a);
    a=((struct Obj00534 *)p)->f4>>16;
    func_0203FB44(6,(u16)(((struct Obj00534 *)p)->f4),(u16)a);
    func_021D92B8(p);
    func_0201DD68();
    func_02045C04(((struct Obj00534 *)p)->f20);
    func_0201D83C(((struct Obj00534 *)p)->f28);
    func_02045808(((struct Obj00534 *)p)->f2C);
    func_02045808(((struct Obj00534 *)p)->f30);
    func_0201ED04(((struct Obj00534 *)p)->f24);
    func_02027FD8(((struct Obj00534 *)p)->fAC);
    func_0201C6EC(((struct Obj00534 *)p)->f8C);
    func_0201C4C0(((struct Obj00534 *)p)->f8C);
    if (((struct Obj00534 *)p)->f80) func_0201CE48(((struct Obj00534 *)p)->f80);
    if (((struct Obj00534 *)p)->f90) {
        func_0202F038(((struct Obj00534 *)p)->f90);
        ((struct Obj00534 *)p)->f90=0;
    }
    if (((struct Obj00534 *)p)->f40) func_020452E8(((struct Obj00534 *)p)->f40);
    if (((struct Obj00534 *)p)->f44) func_020452E8(((struct Obj00534 *)p)->f44);
    if (((struct Obj00534 *)p)->f48) func_020452E8(((struct Obj00534 *)p)->f48);
    if (((struct Obj00534 *)p)->f4C) func_020452E8(((struct Obj00534 *)p)->f4C);
    for(i=0;i<12;i++) if (*(void **)(p+i*4+0x50)) func_020452E8(*(void **)(p+i*4+0x50));
    func_02031140(((struct Obj00534 *)p)->f88);
    func_020450C8();
    func_020307B0(p);
}



void func_021D9514(char *p, int n)
{
    void *q;
    func_02045CAC(((struct Obj02477 *)p)->f20,n,((struct Obj02477 *)p)->f2C);
    if (!((struct Obj02477 *)p)->f48) ((struct Obj02477 *)p)->f48=(void *)func_020450F0(5,1,3,30,4,11,1);
    q=((struct Obj02477 *)p)->f48;
    func_02043B5C(func_02045770(q),15);
    func_0201DD78(1,2,15);
    ((struct Obj02477 *)p)->f80=func_0201CCE4(q, 0, 0, ((struct Obj02477 *)p)->f2C, ((struct Obj02477 *)p)->f28, (void *)(func_02012FFC()), ((struct Obj02477 *)p)->f88, 2, ((struct Obj02477 *)p)->fB0, 15);
    func_0201F73C(q,1,(u16)(((struct Obj02477 *)p)->f8),12);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(5);
}



/*
 * extent: 58 compiled bytes followed by 2 bytes of zero alignment padding.
 */
void func_021D95B4(char *p) { if(((struct Obj04501 *)p)->f90) { func_0202F038(((struct Obj04501 *)p)->f90); ((struct Obj04501 *)p)->f90=0; } ((struct Obj04501 *)p)->f90=func_0202EE8C(((struct Obj04501 *)p)->f88,((struct Obj04501 *)p)->f48,15,16,((struct Obj04501 *)p)->fB0); }



int func_021D95F0(char *p)
{
    if (((struct Obj06470 *)p)->f80) {
        switch (func_0201CE30(((struct Obj06470 *)p)->f80)) {
        case 2:
            func_0201CE48(((struct Obj06470 *)p)->f80);
            ((struct Obj06470 *)p)->f80=0;
            break;
        case 1:
            if (func_020362DC()==1) func_0201CE38(((struct Obj06470 *)p)->f80);
            break;
        }
        return 0;
    }
    return 1;
}



void func_021D9634(char *p) { if(((struct Obj03800 *)p)->f90) { func_0202F038(((struct Obj03800 *)p)->f90); ((struct Obj03800 *)p)->f90=0; } if(((struct Obj03800 *)p)->f48) { func_0201F7A8(((struct Obj03800 *)p)->f48,2); func_020456F8(((struct Obj03800 *)p)->f48); func_02041B6C(5); func_020452E8(((struct Obj03800 *)p)->f48); ((struct Obj03800 *)p)->f48=0; } }



int func_021D9670(char *p,int mode) {
    Config c;
    int result;
    c.size=*(u16 *)(p+0xb0);
    c.flag=2;
    c.target=p+0x94;
    switch (mode) {
    case 0: c.x=32; c.y=14; c.mode=1; break;
    case 1: c.x=32; c.y=24; c.mode=1; break;
    }
    c.z=13;
    c.w=3;
    *(void **)(p+0x94)=func_020457B0(100,*(u16 *)(p+0xb0));
    func_02045CAC(*(void **)(p+0x20),4,*(void **)(p+0x94));
    *(u16 *)(p+0x98)=0x39e0;
    *(void **)(p+0xa0)=func_020457B0(100,*(u16 *)(p+0xb0));
    func_02045CAC(*(void **)(p+0x20),5,*(void **)(p+0xa0));
    *(u16 *)(p+0xa4)=0x39e0;
    result=(int)func_02027778((struct TaskMenuTmpl *)(&c),*(void **)(p+0xac));
    func_02045808(*(void **)(p+0x94));
    func_02045808(*(void **)(p+0xa0));
    func_0207D658(0x04001050,17,-8);
    return result;
}



void func_021D9730(char *p, int n)
{
    void *q;
    func_02045CAC(((struct Obj03801 *)p)->f20,n,((struct Obj03801 *)p)->f2C);
    if (!((struct Obj03801 *)p)->f4C) ((struct Obj03801 *)p)->f4C=(void *)func_020450F0(6,1,3,30,16,11,1);
    q=((struct Obj03801 *)p)->f4C;
    func_02043B5C(func_02045770(q),15);
    func_0201DD78(1,2,15);
    func_0201C7A4(func_02045770(q),0,0,((struct Obj03801 *)p)->f2C,((struct Obj03801 *)p)->f28);
    func_0201F73C(q,1,(u16)(((struct Obj03801 *)p)->f4),12);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(6);
}




void func_021D97B0(char *p)
{
    func_0201F7A8(((struct Obj13999 *)p)->f4C, 2);
    func_020456F8(((struct Obj13999 *)p)->f4C);
    func_02041B6C(6);
}



void func_021D97CC(int value, void *p)
{
    Table_021D8A9C table;
    int copy;
    u32 checksum;
    u16 arg;
    u64 v;
    int i;
    table=d_021DA868;
    copy=value;
    checksum=func_0203F1FC((const u8 *)(&copy),4);
    arg=d_021DA864;
    v=(u64)(long long)copy+((u64)checksum<<32);
    func_0204581C(p);
    for (i=0;i<10;i++) {
        u16 index;
        index=(u16)(v&31);
        v>>=5;
        func_02045AFC(p,table.a[index]);
        func_0201D60C(p,189,4,1,&arg);
    }
}



void func_021D9844(char *p, int n, int a2)
{
    void *q;
    func_021D97CC(n,((struct Obj01737 *)p)->f2C);
    if (!((struct Obj01737 *)p)->f40) ((struct Obj01737 *)p)->f40=(void *)func_020450F0((int)1,(int)1,(u8)8,(int)30,4,11,1);
    q=((struct Obj01737 *)p)->f40;
    func_02043B5C(func_02045770(q),15);
    func_0201DD78(1,2,15);
    func_0201C7A4(func_02045770(q),0,0,((struct Obj01737 *)p)->f2C,((struct Obj01737 *)p)->f28);
    func_0201F73C(q,1,(u16)(((struct Obj01737 *)p)->f0),12);
    func_02045334(q);
    func_02045374(q);
    if (!((struct Obj01737 *)p)->f44) ((struct Obj01737 *)p)->f44=(void *)func_020450F0((int)1,(int)3,(u8)3,(int)22,2,11,1);
    q=((struct Obj01737 *)p)->f44;
    func_0201DD78(1,2,0);
    func_02045CAC(((struct Obj01737 *)p)->f20,10,((struct Obj01737 *)p)->f2C);
    func_0201C7A4(func_02045770(q),0,0,((struct Obj01737 *)p)->f2C,((struct Obj01737 *)p)->f28);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(5);
}



void func_021D9918(char *p)
{
    if (((struct Obj03273 *)p)->f40) {
        func_0201F7A8(((struct Obj03273 *)p)->f40,2);
        func_020456F8(((struct Obj03273 *)p)->f40);
        func_0201F7A8(((struct Obj03273 *)p)->f44,2);
        func_020456F8(((struct Obj03273 *)p)->f44);
        func_020452E8(((struct Obj03273 *)p)->f40);
        func_020452E8(((struct Obj03273 *)p)->f44);
        func_02041B6C(5);
        ((struct Obj03273 *)p)->f40=0;
        ((struct Obj03273 *)p)->f44=0;
    }
}



/*
 * evidence: ov123 021D9D34 callback stub filed and verified before caller rerun.
 * volatile: hardware register 04001000 is read then written at 021D9990/021D9994.
 */
char *func_021D9958(int heap)
{
    char *p;
    p=func_02030734(heap,0xb70,1,d_021DABFC,201);
    ((struct Obj05370 *)p)->f9E4=heap;
    func_02034AC4((int)ov067_id);
    func_02043534(0);
    func_020435F4(0);
    func_0204363C(1);
    *(volatile u32 *)0x04001000|=0x10000;
    func_0207D46C();
    func_0203F8F4(((struct Obj05370 *)p)->f9E4);
    func_0204A48C((const struct Cfg *)d_020A1464,(u32)d_021DABCC,((struct Obj05370 *)p)->f9E4);
    ((struct Obj05370 *)p)->f97C=func_0204B100(40,0,((struct Obj05370 *)p)->f9E4);
    func_020433E0((const struct DispVram *)d_021DABCC);
    func_0203FC28((struct DispConfig *)d_021DABBC);
    func_021D9AE8(p);
    func_021D9D3C(p);
    ((struct Obj05370 *)p)->f980=func_020056A0(func_021D9D34,p,0);
    func_020435F4(31);
    func_02043534(27);
    return p;
}



void func_021D9A14(int a0) { func_0204A600(); }



void func_021D9A1C(u8 *p)
{
    Counter i;
    func_021D9FB0((unsigned int)p);
    if (((struct Obj03802 *)p)->f8) {
        func_02030EAC(((struct Obj03802 *)p)->f8);
        ((struct Obj03802 *)p)->f8=0;
        ((struct Obj03802 *)p)->fC=0;
    }
    i=0;
    do { if (*(void **)(p+i*4+0x988)) func_0204ADA4((unsigned int)(*(void **)(p+i*4+0x988))); i++; } while(i<3);
    for(;i<6;i++) if (*(void **)(p+i*4+0x988)) func_0204A8D4((unsigned int)(*(void **)(p+i*4+0x988)));
    for(;i<9;i++) if (*(void **)(p+i*4+0x988)) func_0204AFD8((unsigned int)(*(void **)(p+i*4+0x988)));
    if (((struct Obj03802 *)p)->f984) func_02030EAC(((struct Obj03802 *)p)->f984);
    func_02030EAC(((struct Obj03802 *)p)->f980);
    func_0204B1CC(((struct Obj03802 *)p)->f97C);
    func_0204A5AC();
    func_02040DA8(1,1,0);
    func_02040DA8(6,1,0);
    func_020403F4(5);
    func_020403F4(4);
    func_02040588(5,0);
    func_0203F9B4();
    func_020307B0(p);
    func_02034A5C((int)ov_id);
}




/*
 * BG-layer init, same shape as func_021D6100 (ov120) with its own template
 * table at 0x021DA8A8 (index order 1,4,3,7,5,0,6,2) and slight per-layer
 * differences in the enable/fill sequence.
 */
void func_021D9AE8(void *a0)
{
    struct BgTemplate b[8];

    b[7] = d_021DA8A8[1];
    func_0203FCA0(0, (const struct BgTemplate_021D4240 *)(&b[7]), 0);
    func_02040588(0, 1);
    func_020409B4(0);

    b[6] = d_021DA8A8[4];
    func_0203FCA0(1, (const struct BgTemplate_021D4240 *)(&b[6]), 0);
    func_02040588(1, 1);
    func_02040C14(1, 0, 1, 0);
    func_02041300(1, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(1);

    b[5] = d_021DA8A8[3];
    func_0203FCA0(2, (const struct BgTemplate_021D4240 *)(&b[5]), 0);
    func_02040588(2, 1);
    func_02041300(2, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(2);

    b[4] = d_021DA8A8[7];
    func_0203FCA0(3, (const struct BgTemplate_021D4240 *)(&b[4]), 0);
    func_02040588(3, 1);
    func_02040C14(3, 0, 1, 0);
    func_02041300(3, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(3);

    b[3] = d_021DA8A8[5];
    func_0203FCA0(4, (const struct BgTemplate_021D4240 *)(&b[3]), 0);
    func_02040588(4, 1);
    func_020409B4(4);

    b[2] = d_021DA8A8[0];
    func_0203FCA0(5, (const struct BgTemplate_021D4240 *)(&b[2]), 0);
    func_02040588(5, 1);
    func_02040C14(5, 0, 1, 0);
    func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(5);

    b[1] = d_021DA8A8[6];
    func_0203FCA0(6, (const struct BgTemplate_021D4240 *)(&b[1]), 0);
    func_02040588(6, 1);
    func_02040C14(6, 0, 1, 0);
    func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(6);

    b[0] = d_021DA8A8[2];
    func_0203FCA0(7, (const struct BgTemplate_021D4240 *)(&b[0]), 0);
    func_02040588(7, 1);
    func_02040C14(7, 0, 1, 0);
    func_02041300(7, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(7);
}



/*
 * leaf: sole blocker of owned ov123 021D9958; parent ownership audit passed.
 * extent: 8-byte tailcall stub; next labelled function 021D9D3C follows.
 */
void func_021D9D34(void)
{
    func_0204A648();
}



/*
 * note 2026-10-05 (wD9r lane50): closed. func_02049658 returns a value (it ends in a call whose r0 it
 *   keeps; ov110 func_021BB328 declares it u32); declared void, it moved the constant 3 into r5 and
 *   tied the late zero arguments to j. The two palette bases are assigned inside the outer loop (mwcc
 *   hoists them after i = 0), and the source row is written inline in the 02021F64 call.
 */
void func_021D9D3C(char *p)
{
    void *record;
    u16 *base0;
    u16 *base1;
    void *h;
    int done;
    int k;
    int j;
    int i;
    u16 *cur;
    void *allocated;
    int m;
    int t;
    u16 *dst;
    u16 heap;
    h = func_020490F4(0x91, *(u16 *)(p + 0x9e4));
    j = 0;
    func_02049B68(h, 3, 4, 0, j, *(u16 *)(p + 0x9e4));
    func_02049658(h, 4, 4, 0, j, j, *(u16 *)(p + 0x9e4));
    func_020498F4(h, 6, 4, 0, j, j, *(u16 *)(p + 0x9e4));
    func_02049B68(h, 3, 0, 0, j, *(u16 *)(p + 0x9e4));
    func_02049658(h, 4, 0, 0, j, j, *(u16 *)(p + 0x9e4));
    func_020498F4(h, 5, 0, 0, j, j, *(u16 *)(p + 0x9e4));
    func_02049658(h, 4, 3, 0, j, j, *(u16 *)(p + 0x9e4));
    func_020498F4(h, 7, 3, 0, j, j, *(u16 *)(p + 0x9e4));
    heap = *(u16 *)(p + 0x9e4);
    func_02082BCC(p + 8, 0, 0x970);
    allocated = func_02049F78(h, 2, (u32)&record, heap);
    func_02082D44(*(void **)((u8 *)record + 0xc), p + 0x10, 0x1e0);
    func_02082D44(*(void **)((u8 *)record + 0xc), p + 0x1f0, 0x1e0);
    func_020307B0(allocated);
    for (i = 0; i < 15; i++) {
        base1 = (u16 *)(p + 0x1f0);
        base0 = (u16 *)(p + 0x10);
        t = i + 1;
        if (t >= 15) t -= 15;
        k = 0;
        done = 0;
        cur = (u16 *)(p + t * 32);
        while (1) {
            dst = base0 + i * 16;
            for (m = 4; m < 11; m++) {
                func_02021F64(dst + m, base1 + j * 16 + m, 1, (u8)(k >> 8), cur[m + 8]);
            }
            j++;
            if (done == 1) break;
            k += 0x600;
            if (k >= 0x1000) {
                k = 0x1000;
                done = 1;
            }
        }
    }
    func_020862F0(p + 0x1f0, 0x780);
    *(u32 *)(p + 0xc) = 1;
    *(void **)(p + 8) = func_020056A0((void *)func_021D9F40, p + 8, 0x14);
    func_0207D63C((void *)0x04000050, 1, 8, 8, 0x10);
    *(u8 *)(p + 0x974) = 0;
    func_02049238(h);
}



void func_021D9F40(void *unused, char *p)
{
    if (((struct Obj03274 *)p)->f4) {
        ((struct Obj03274 *)p)->f96B^=1;
        if (!(*(volatile u8 *)&((struct Obj03274 *)p)->f96B&1)) {
            func_0207E3D0(p+0x1f0+((struct Obj03274 *)p)->f968*32,40,14);
            func_0207E468(p+0x1f0+((struct Obj03274 *)p)->f968*32,40,14);
            ++((struct Obj03274 *)p)->f968;
            if (*(volatile s16_021D8A9C *)&((struct Obj03274 *)p)->f968>=60) ((struct Obj03274 *)p)->f968=0;
            func_02040618(((struct Obj03274 *)p)->f96C,2,7);
        }
    }
}



/*
 * lever: A named unsigned cursor q preserves counter r4 and cursor r5.
 */
void func_021D9FB0(unsigned int p) { int i; unsigned int q; for(i=0;i<13;i++) { q=p+(unsigned)i*4; if(((struct Obj10454 *)q)->f9B0) { func_0204B3B4(((struct Obj10454 *)q)->f9B0); ((struct Obj10454 *)q)->f9B0=0; } } }



/*
 * extent: lead with store-and-return follower 021DA030 and tailcall follower 021DA034.
 */
int func_021D9FD4(char *p, int n)
{
    switch (n) {
    case 503:
        ((struct Obj03804 *)p)->f70=0xfff1;
        func_021DA034(p,(int)func_021DA1EC,0x99);
        return 1;
    case 502:
        ((struct Obj03804 *)p)->f70=0xfff2;
        func_021DA034(p,(int)func_021DA1EC,0x9d);
        return 1;
    default:
        if (n>=400) {
            ((struct Obj03804 *)p)->f70=0xfff3;
            func_021DA034(p,(int)func_021DA1EC,0xa3);
            return 1;
        }
        return 0;
    }
}



void func_021DA030(char *p, int n, int unused)
{
    ((struct Obj22984 *)p)->f30=n;
}



void func_021DA034(char *p, int n, int unused)
{
    func_021DA030(p,n,unused);
}




void func_021DA03C(char *p)
{
    if (func_020221A4() != 0)
        func_021DA034(p, 0, 0xd5);
}



void func_021DA054(char *p) { func_0202208C(0,0,0,0x7fff,6,1,((struct Obj22985 *)p)->f0); func_02005E30(6); func_021DA034(p,(int)func_021DA03C,0xe7); }



void func_021DA090(char *p) { if(func_021D95F0(*(char * *)&((struct Obj22986 *)p)->f10) && func_020362DC()!=0) func_021DA034(p,(int)func_021DA054,0xf1); }



/*
 * lever: Unsigned result-minus-two range test emits subs/cmp/bhi.
 */
void func_021DA0B8(char *p) { if((unsigned int)(func_02012DD0(((struct Obj10455 *)p)->f20)-2)<=1) { ((struct Obj10455 *)p)->f6C=0; func_021D9514(*(char * *)&((struct Obj10455 *)p)->f10,11); func_021DA034(p,(int)func_021DA090,0xfe); } }



void func_021DA0E4(char *p) { if(func_021D95F0(*(char * *)&((struct Obj10456 *)p)->f10)) { ((struct Obj10456 *)p)->f6C=1; func_02012DAC(((struct Obj10456 *)p)->f20); func_021DA034(p,(int)func_021DA0B8,0x109); } }



void func_021DA110(char *p) { func_021D9514(*(char * *)&((struct Obj14000 *)p)->f10,6); func_021D95B4(*(char * *)&((struct Obj14000 *)p)->f10); func_021DA034(p,(int)func_021DA0E4,0x112); }



void func_021DA138(char *p) { if(func_020362DC()) { func_021D97B0(*(char * *)&((struct Obj14001 *)p)->f10); func_020092E0((struct Sub02009210Obj *)func_02009448(((struct Obj14001 *)p)->f1C),1); func_021DA034(p,(int)func_021DA110,0x11a); } }



void func_021DA16C(char *p) { if(func_020362DC()) { func_021D9844(*(char * *)&((struct Obj08116 *)p)->f10,((struct Obj08116 *)p)->f28,((struct Obj08116 *)p)->f28); func_021D9730(*(char * *)&((struct Obj08116 *)p)->f10,9); func_021DA034(p,(int)func_021DA138,0x12a); } }



void func_021DA1A0(char *p) { func_021D9844(*(char * *)&((struct Obj08117 *)p)->f10,((struct Obj08117 *)p)->f28,((struct Obj08117 *)p)->f28); func_021D9730(*(char * *)&((struct Obj08117 *)p)->f10,8); func_021DA034(p,(int)func_021DA16C,0x13c); }



void func_021DA1C8(char *p) { if(func_020362DC() & 3) func_021DA034(p,(int)func_021DA054,0x14b); }



void func_021DA1EC(char *p)
{
    unsigned n;
    n = ((struct Obj03803 *)p)->f70 + 11;
    if (((struct Obj03803 *)p)->f8) func_021B9774(((struct Obj03803 *)p)->f8);
    if (((struct Obj03803 *)p)->f70 == 0xfff1) n = 22;
    else if (((struct Obj03803 *)p)->f70 == 0xfff2) n = 23;
    else if (((struct Obj03803 *)p)->f70 == 0xfff3) n = 20;
    else if (((struct Obj03803 *)p)->f70 >= 10) n = 20;
    func_021D9730(((struct Obj03803 *)p)->f10,n);
    func_021DA034(p,(int)func_021DA1C8,0x167);
}



void func_021DA244(char *p) { if(func_021D95F0(*(char * *)&((struct Obj22987 *)p)->f10)) func_021DA034(p,(int)func_021DA3A0,0x172); }



void func_021DA268(char *p) { func_021D9514(*(char * *)&((struct Obj14002 *)p)->f10,3); func_021D95B4(*(char * *)&((struct Obj14002 *)p)->f10); func_021DA034(p,(int)func_021DA244,0x17b); }



void func_021DA290(char *p)
{
    if (func_020279E8(((struct Obj06471 *)p)->f14)) {
        if (!func_02027A04(((struct Obj06471 *)p)->f14))
            func_021DA034(p, (int)func_021DA268, 0x18d);
        else
            func_021DA034(p, (int)func_021DA054, 0x190);
        func_021D9634(((struct Obj06471 *)p)->f10);
        func_02027858(((struct Obj06471 *)p)->f14);
        *(int *)&((struct Obj06471 *)p)->f14 = 0;
    }
}



void func_021DA2DC(char *p) { if(func_021D95F0(*(char * *)&((struct Obj10457 *)p)->f10)) { ((struct Obj10457 *)p)->f14=func_021D9670(*(char * *)&((struct Obj10457 *)p)->f10,0); func_021DA034(p,(int)func_021DA290,0x1a6); } }



void func_021DA308(char *p) { func_021D9514(*(char * *)&((struct Obj22988 *)p)->f10,2); func_021DA034(p,(int)func_021DA2DC,0x1b7); }



void func_021DA328(char *p)
{
    int *q;
    if (func_0203CD98() && !func_021D9FD4(p,func_021B99DC(((struct Obj03804 *)p)->f8)) && !func_021B9790(((struct Obj03804 *)p)->f8)) {
        q = (int *)(char *)func_021B97F4((u8 *)(((struct Obj03804 *)p)->f8));
        func_021D9634(((struct Obj03804 *)p)->f10);
        if (*q == 2) { func_021DA034(p,(int)func_021DA1A0,0x1d4); return; }
        if (*q == 0) { func_021DA034(p,(int)func_021DA1A0,0x1d7); return; }
        ((struct Obj03804 *)p)->f70 = *q;
        func_021DA034(p,(int)func_021DA1EC,0x1db);
    }
}



/*
 *   in scratch blocker071d8-r1.log, 12 bytes. Ilias owns filing it.
 *   extern unsigned func_02031994(void *, unsigned *);
 * evidence: 0x021B973C ov114 Thumb leaf now has S23's verified EXACT
 *   pkt_ov114_021B973C shard; no caller retry because ARM9 still blocks it.
 */
void func_021DA3A0(char *p)
{
    int a;
    unsigned b;
    if (func_0203CD98()) {
        if (func_021B95D4(9,*(void **)(p + 8))) {
            b = (unsigned int)func_020071D8(*(void **)(p + 0x1c),&a);
            func_021BE79C((void *)func_021B973C(*(void **)(p + 8)),(void *)b,0x80000);
            if (!func_021B9748(*(void **)(p + 8))) {
                func_021DA034(p,(int)func_021DA328,0x1f6);
                return;
            }
        }
    } else if (func_020362DC()) {
        func_021DA034(p,(int)func_021DA328,0x1fc);
    }
}



void func_021DA408(char *p) { if(func_020221A4() && func_020362DC()) { func_021D9918(*(char * *)&((struct Obj22989 *)p)->f10); func_021DA034(p,(int)func_021DA054,0x22c); } }



void func_021DA434(char *p) { func_021D9844(*(char * *)&((struct Obj08118 *)p)->f10,((struct Obj08118 *)p)->f28,((struct Obj08118 *)p)->f28); func_021D9730(*(char * *)&((struct Obj08118 *)p)->f10,7); func_021DA034(p,(int)func_021DA408,0x23c); }



void func_021DA45C(char *p) { if(*(u8 * *)&((struct Obj08119 *)p)->f8) { func_021B9774(*(u8 * *)&((struct Obj08119 *)p)->f8); func_021B9838(*(u8 * *)&((struct Obj08119 *)p)->f8); *(u8 * *)&((struct Obj08119 *)p)->f8=0; } }



/*
 * interface: 0203159C retains the allocator result in r0; caller consumes that return.
 */
int func_021DA478(void *a,int unused,char *q)
{
    char *p;
    func_02034AC4((int)ov114_id);
    p=func_0203159C(a,0x74,((struct Obj03275 *)q)->f8);
    func_02082BCC(p,0,0x74);
    ((struct Obj02478 *)p)->f0=((struct Obj03275 *)q)->f8;
    ((struct Obj02478 *)p)->f1C=func_02012EBC(((struct Obj03275 *)q)->f0);
    ((struct Obj02478 *)p)->f20=((struct Obj03275 *)q)->f0;
    ((struct Obj02478 *)p)->f28=func_0200853C((const struct Sub0200852CObj *)func_02012944(((struct Obj03275 *)q)->f0));
    if(func_0203CD98()) {
        ((struct Obj02478 *)p)->f8=func_021B9800(((struct Obj03275 *)q)->f8,((struct Obj02478 *)p)->f28,((struct Obj03275 *)q)->f4);
        func_02156DC4((int)func_021DA45C,(int)p);
    }
    ((struct Obj02478 *)p)->fC=func_021D9958(((struct Obj02478 *)p)->f0);
    ((struct Obj02478 *)p)->f10=func_021D92CC(((struct Obj02478 *)p)->f0,87);
    func_0202208C(0,1,1,0,6,1,((struct Obj02478 *)p)->f0);
    func_02005D90(0x483,0xffff);
    switch(((struct Obj03275 *)q)->fC) {
    case 0: func_021DA034(p,(int)func_021DA308,0x276); break;
    case 1: func_021DA034(p,(int)func_021DA434,0x279); break;
    }
    ((struct Obj03275 *)q)->f10=0;
    return 1;
}



int func_021DA54C(int a,int b,char *c,char *p)
{
    void (*f)(char *);
    int r;
    f = *(void (**)(char *))(p + 0x30);
    r = 1;
    if (f) {
        if (!func_0200FB24()) f(p);
        r = 0;
    }
    if (((struct Obj03276 *)p)->f14) func_02027974(((struct Obj03276 *)p)->f14);
    func_021D9A14(((struct Obj03276 *)p)->fC);
    func_021D9404(((struct Obj03276 *)p)->f10);
    if (func_020221A4()) {
        if (func_0200FB24()) {
            func_021B9774(((struct Obj03276 *)p)->f8);
            if (((struct Obj03276 *)p)->f6C) {
                func_02012E08(((struct Obj03276 *)p)->f20);
                ((struct Obj03276 *)p)->f6C = 0;
            }
            func_0202223C(0,0);
            func_0202223C(1,0);
            r = 1;
            func_02157170(1,0);
            ((struct Obj22990 *)c)->f10 = 1;
        }
    } else if (func_0200FB24()) r = 1;
    return r;
}
