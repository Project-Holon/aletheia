/*
 * file:     worldtrade_adapter_p04.c
 * unit:     yes
 * function: func_021FE93C, func_021FE974, func_021FE9B0, func_021FE9DC, func_021FEAE0, func_021FEB50, func_021FEB84, func_021FEBB8, func_021FEBE0, func_021FEC00, func_021FED24, func_021FED4C, func_021FED6C, func_021FEE1C, func_021FEE44, func_021FEE70, func_021FEEFC, func_021FEF24, func_021FEF50, func_021FF004, func_021FF024, func_021FF078, func_021FF0A0, func_021FF0BC, func_021FF0E8, func_021FF118, func_021FF174, func_021FF198, func_021FF218, func_021FF26C, func_021FF2D0, func_021FF318, func_021FF384, func_021FF474, func_021FF4D0, func_021FF50C, func_021FF570, func_021FF58C, func_021FF65C, func_021FF67C, func_021FF6A4, func_021FF8B0, func_021FF914, func_021FF92C, func_021FF9E0, func_021FFA3C, func_021FFAEC, func_021FFB00, func_021FFB20, func_021FFBC0, func_021FFBC8, func_021FFC18, func_021FFC8C, func_021FFCD4, func_021FFD1C, func_021FFD44, func_021FFD74, func_021FFDA8, func_021FFEB4, func_021FFEC8, func_021FFF10, func_021FFFE8, func_022000E4, func_02200118, func_02200130, func_0220015C, func_022001F4, func_02200290, func_022002A0, func_022003BC, func_0220040C, func_02200434, func_02200450, func_02200490, func_022004A0, func_022004C8, func_022004DC, func_022004F0, func_0220052C, func_0220053C, func_022005EC, func_02200770, func_0220078C, func_022007A0, func_022007E0, func_02200800, func_022008B0, func_022008F0, func_0220090C, func_0220093C, func_022009A4, func_02200A10, func_02200A7C, func_02200AB4, func_02200B34, func_02200BAC, func_02200C0C, func_02200C80, func_02200C94, func_02200CCC, func_02200DB8, func_02200DD0, func_02200E48, func_02200E94, func_02200EB0, func_02200EC8, func_02200ED8, func_02200FF4, func_022010BC, func_02201258, func_02201320, func_022013E4, func_02201414, func_022014B8, func_022014D8, func_02201554, func_0220157C, func_0220163C, func_02201658, func_022016CC, func_0220171C, func_022017F0, func_0220180C, func_02201880, func_0220189C, func_02201A34, func_02201A48, func_02201A64, func_02201B18, func_02201B44, func_02201C08, func_02201C24, func_02201C88, func_02201CBC, func_02201D14, func_02201D30, func_02201DBC, func_02201DC0, func_02201DD8, func_02201DF0, func_02201E04, func_02201E1C, func_02201E38, func_02201ED4, func_02201F18, func_02201FA4, func_02201FDC, func_02202000, func_02202038, func_0220207C, func_02202054, func_02202094, func_022020B8, func_022020E0, func_022020F8, func_02202148, func_022021A4, func_022021C0, func_022021F8, func_022022B8, func_022023A4, func_0220246C, func_022024B0, func_022024DC, func_0220251C, func_0220252C, func_0220254C, func_022025E4, func_02202608, func_0220262C, func_02202644, func_02202670, func_022026A0, func_022026BC, func_022026C4, func_022026D8, func_02202744, func_02202770, func_02202840, func_02202858, func_02202878, func_022028C8, func_02202940, func_02202974, func_022029D4, func_022029F8, func_02202A50
 * address:  0x021FE93C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_020061E4 0x020061E4 thumb
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_02034714  0x02034714  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0204B878  0x0204B878  arm
 *   func_021F4FF4  0x021F4FF4  thumb
 *   tbl_02203D46   0x02203D46  data  a2
 *   tbl_02203D38   0x02203D38  data  a1
 *   func_021F4FC4  0x021F4FC4  thumb  ov135
 *   func_021F9968  0x021F9968  thumb  ov135
 *   func_021F99F0  0x021F99F0  thumb
 *   func_021F89A8  0x021F89A8  thumb
 *   func_021F7F9C  0x021F7F9C  thumb
 *   func_021F7B9C  0x021F7B9C  thumb
 *   func_021F8098  0x021F8098  thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021F882C 0x021F882C thumb ov135
 *   func_021F8154 0x021F8154 thumb ov135
 *   func_021F88B0 0x021F88B0 thumb ov135
 *   func_021F8010 0x021F8010 thumb ov135
 *   d_02202EAC 0x02202EAC data a4
 *   func_021F4BE0  0x021F4BE0  thumb  ov135
 *   func_021F4D14 0x021F4D14 thumb ov135
 *   func_021F4CE4 0x021F4CE4 thumb ov135
 *   func_020221A4 0x020221A4 thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0202208C 0x0202208C thumb
 *   func_0204B98C 0x0204B98C arm
 *   func_020355C4 0x020355C4 arm
 *   func_021FE264 0x021FE264 thumb ov135
 *   d_02203D4A 0x02203D4A data a2
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_021F91A0  0x021F91A0  thumb
 *   func_021F91DC  0x021F91DC  thumb
 *   func_020413B0  0x020413B0  arm
 *   func_02040618  0x02040618  arm
 *   func_021F50EC 0x021F50EC thumb ov135
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020120F4 0x020120F4 thumb
 *   func_021F6B34 0x021F6B34 thumb ov135
 *   func_021F6B80 0x021F6B80 thumb ov135
 *   func_021F6B40 0x021F6B40 thumb ov135
 *   func_02031348 0x02031348 arm
 *   str_02203E30 0x02203E30 data a1
 *   d_021DC800 0x021DC800 data ov131 a4
 *   ov131_id       0x00000083  data
 *   func_021F5074  0x021F5074  thumb  ov135
 *   func_021F4EC8  0x021F4EC8  thumb  ov135
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_021F4EA0  0x021F4EA0  thumb
 *   func_0204B454  0x0204B454  arm
 *   tbl_022038A2   0x022038A2  data  a2
 *   func_02030DA8 0x02030DA8 arm
 *   func_02030EE8 0x02030EE8 arm
 *   str_02203E44 0x02203E44 data a1
 *   func_020307B0 0x020307B0 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0204B404  0x0204B404  arm
 *   func_02035C08 0x02035C08 arm
 *   d_022038BE 0x022038BE data a2
 *   func_0204B898 0x0204B898 arm
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_02049F34  0x02049F34  arm
 *   func_02049E34  0x02049E34  arm
 *   DC_FlushRange  0x020862F0  arm
 *   func_0207E804 0x0207E804 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   d_02203884 0x02203884 data a2
 *   d_02203892 0x02203892 data a1
 *   func_021F9254 0x021F9254 thumb ov135
 *   func_02040588 0x02040588 arm
 *   func_0207D55C 0x0207D55C arm
 *   g_02203E58  0x02203E58  data  ov135
 *   func_02043668  0x02043668  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_020435F4  0x020435F4  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040B94  0x02040B94  arm
 *   g_02203914  0x02203914  data  ov135
 *   g_022039A4  0x022039A4  data  ov135
 *   g_02203984  0x02203984  data  ov135
 *   g_022039C4  0x022039C4  data  ov135
 *   func_02041570  0x02041570  arm
 *   g_02203944  0x02203944  data  ov135
 *   g_02203924  0x02203924  data  ov135
 *   g_02203964  0x02203964  data  ov135
 *   g_022039E4  0x022039E4  data  ov135
 *   func_020403F4 0x020403F4 arm
 *   sub_020403F4  0x020403F4  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049238  0x02049238  arm
 *   func_0203D34C 0x0203D34C arm
 *   d_022038E0 0x022038E0 data a2
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_020452E8 0x020452E8 arm
 *   func_021F4F90 0x021F4F90 thumb ov135
 *   g_022038EC  0x022038EC  data  ov135
 *   func_021F4ED4 0x021F4ED4 thumb ov135
 *   func_020355D8  0x020355D8  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   tbl_022038E0   0x022038E0  data  a2
 *   func_020456F8 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   d_022038FC 0x022038FC data a4
 *   func_02045CAC 0x02045CAC arm
 *   func_02049BDC 0x02049BDC arm
 *   func_020499D4 0x020499D4 arm
 *   func_021F9218  0x021F9218  thumb
 *   g_02203E94  0x02203E94  data  ov135
 *   g_02203A04  0x02203A04  data  ov135
 *   g_02203A14  0x02203A14  data  ov135
 *   g_02203A54  0x02203A54  data  ov135
 *   g_02203A34  0x02203A34  data  ov135
 *   func_021F90A0  0x021F90A0  thumb
 *   func_021F4FA4  0x021F4FA4  thumb
 *   str_02203F58  0x02203F58  data  a1
 *   func_02019CE0 0x02019CE0 thumb
 *   func_02025C1C 0x02025C1C thumb
 *   func_02025C30 0x02025C30 thumb
 *   func_020173EC 0x020173EC thumb
 *   func_021B9800 0x021B9800 thumb ov114
 *   func_021B98A0 0x021B98A0 thumb ov114
 *   func_021B98D8 0x021B98D8 thumb ov114
 *   func_021B98F8 0x021B98F8 thumb ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_021B99DC  0x021B99DC  thumb  ov114
 *   func_021B9790  0x021B9790  thumb  ov114
 *   func_021B97F4  0x021B97F4  thumb  ov114
 *   func_021B9774  0x021B9774  thumb  ov114
 *   func_021B99B8  0x021B99B8  thumb  ov114
 *   func_021B9838  0x021B9838  thumb  ov114
 *   func_021B99F0  0x021B99F0  thumb  ov114
 *   func_021B99F4  0x021B99F4  thumb  ov114
 *   func_021B9A14  0x021B9A14  thumb  ov114
 *   func_0200FB4C  0x0200FB4C  thumb
 *   func_0200F7B8  0x0200F7B8  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0203CA04  0x0203CA04  arm
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0203C968  0x0203C968  arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045994 0x02045994 arm
 *   func_02045A90 0x02045A90 arm
 *   func_020458F8 0x020458F8 arm
 *   func_02045A98 0x02045A98 arm
 *   func_0217BC44 0x0217BC44 arm ov009
 *   func_0217BC90 0x0217BC90 arm ov009
 *   func_02045B38 0x02045B38 arm
 *   func_02045C04 0x02045C04 arm
 *   func_021F513C  0x021F513C  thumb  ov135
 *   func_02008DF0  0x02008DF0  thumb
 *   func_021C866C  0x021C866C  arm
 *   func_021C86A8  0x021C86A8  arm
 *   func_0200ADB4  0x0200ADB4  thumb
 *   func_0200ADE0  0x0200ADE0  thumb
 *   func_021C8C68 0x021C8C68 arm ov114
 *   func_0200AD8C  0x0200AD8C  thumb
 *   func_0200AD9C  0x0200AD9C  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0200AD94  0x0200AD94  thumb
 *   func_0200ED48 0x0200ED48 thumb
 *   func_0200ED54 0x0200ED54 thumb
 *   func_021F72C4 0x021F72C4 thumb ov135
 *   func_02009EC8 0x02009EC8 thumb
 *   func_02009DE8 0x02009DE8 thumb
 *   memset 0x02082BCC arm
 *   func_02008494 0x02008494 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202EB7C 0x0202EB7C thumb
 *   func_021C89F0  0x021C89F0  arm  ov114
 *   func_021F9088  0x021F9088  thumb  ov135
 *   func_02012DD0 0x02012DD0 thumb
 *   func_02035C60 0x02035C60 arm
 *   func_02007A18 0x02007A18 thumb
 *   func_0200ADB8 0x0200ADB8 thumb
 *   func_02007664 0x02007664 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_0201A9C8 0x0201A9C8 thumb
 *   func_02012F98 0x02012F98 thumb
 *   func_02012934 0x02012934 thumb
 *   func_02007C34 0x02007C34 thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02017F50  0x02017F50  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_020076D0  0x020076D0  thumb
 *   func_0200752C  0x0200752C  thumb
 *   DWC_GetDateTime  0x02167ED8  arm  ov009
 *   func_0200ADD8  0x0200ADD8  thumb
 *   func_0200ADD0  0x0200ADD0  thumb
 *   func_0200949C 0x0200949C thumb
 *   func_020094D8 0x020094D8 thumb
 *   func_021F6DE8  0x021F6DE8  thumb
 *   func_02019B58  0x02019B58  thumb
 *   func_0202136C  0x0202136C  thumb
 *   func_02008F08  0x02008F08  thumb
 *   func_02008F88  0x02008F88  thumb
 *   g_02203F5C  0x02203F5C  data  ov135
 *   func_0203101C  0x0203101C  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_02028590  0x02028590  thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201C724  0x0201C724  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 */
#include "../../matched/include/Obj23416.h"
#include "../../matched/include/Obj12213.h"
#include "../../matched/include/Obj00018.h"
#include "../../matched/include/Obj12214.h"
#include "../../matched/include/Obj12215.h"
#include "../../matched/include/Obj02861.h"
#include "../../matched/include/Obj09239.h"
#include "../../matched/include/Obj05417.h"
#include "../../matched/include/Obj09240.h"
#include "../../matched/include/Obj02204.h"
#include "../../matched/include/Obj18599.h"
#include "../../matched/include/Obj00045.h"
#include "../../matched/include/Obj23427.h"
#include "../../matched/include/Obj12216.h"
#include "../../matched/include/Obj12217.h"
#include "../../matched/include/Obj07250.h"
#include "../../matched/include/Obj05418.h"
#include "../../matched/include/Obj07251.h"
#include "../../matched/include/Obj08192.h"
#include "../../matched/include/Obj01162.h"
#include "../../matched/include/Obj23428.h"
#include "../../matched/include/Obj23429.h"
#include "../../matched/include/Obj23430.h"
#include "../../matched/include/Obj23431.h"
#include "../../matched/include/Obj23432.h"
#include "../../matched/include/Obj23433.h"
#include "../../matched/include/Obj23434.h"
#include "../../matched/include/Obj23435.h"
#include "../../matched/include/Obj12221.h"
#include "../../matched/include/Obj12222.h"
#include "../../matched/include/Obj18600.h"
#include "../../matched/include/Obj05419.h"
#include "../../matched/include/Obj10589.h"
#include "../../matched/include/Obj23436.h"
#include "../../matched/include/Obj04530.h"
#include "../../matched/include/Obj08193.h"
#include "../../matched/include/Obj23438.h"
#include "../../matched/include/Obj23439.h"
#include "../../matched/include/Obj10591.h"
#include "../../matched/include/Obj10592.h"
#include "../../matched/include/Obj00137.h"
#include "../../matched/include/Obj00287.h"
#include "../../matched/include/Obj12225.h"
#include "../../matched/include/Obj23440.h"
#include "../../matched/include/Obj02862.h"
#include "../../matched/include/Obj18604.h"
#include "../../matched/include/Obj03300.h"
#include "../../matched/include/Obj08194.h"
#include "../../matched/include/Obj09242.h"
#include "../../matched/include/Obj12227.h"
#include "../../matched/include/Obj09243.h"
#include "../../matched/include/Obj18605.h"
#include "../../matched/include/Obj18606.h"
#include "../../matched/include/Obj18607.h"
#include "../../matched/include/Obj02863.h"
#include "../../matched/include/Obj01749.h"
#include "../../matched/include/Obj12229.h"
#include "../../matched/include/Obj18608.h"
#include "../../matched/include/Obj12230.h"
#include "../../matched/include/Obj07254.h"
#include "../../matched/include/Obj04139.h"
#include "../../matched/include/Obj00345.h"
#include "../../matched/include/Obj10593.h"
#include "../../matched/include/Obj10594.h"
#include "../../matched/include/Obj18609.h"
#include "../../matched/include/Obj18610.h"
#include "../../matched/include/Obj18611.h"
#include "../../matched/include/Obj01411.h"
#include "../../matched/include/Obj23442.h"
#include "../../matched/include/Obj06520.h"
#include "../../matched/include/Obj05420.h"
#include "../../matched/include/Obj12231.h"
#include "../../matched/include/Obj02054.h"
#include "../../matched/include/Obj09244.h"
#include "../../matched/include/Obj04908.h"
#include "../../matched/include/Obj12232.h"
#include "../../matched/include/Obj01829.h"
#include "../../matched/include/Obj12233.h"
#include "../../matched/include/Obj09245.h"
#include "../../matched/include/Obj10595.h"
#include "../../matched/include/Obj01943.h"
#include "../../matched/include/Obj23444.h"
#include "../../matched/include/Obj12234.h"
#include "../../matched/include/Obj09246.h"
#include "../../matched/include/Obj12235.h"
#include "../../matched/include/Obj18612.h"
#include "../../matched/include/Obj12237.h"
#include "../../matched/include/Obj03532.h"
#include "../../matched/include/Obj09247.h"
#include "../../matched/include/Obj06521.h"
#include "../../matched/include/Obj08195.h"
#include "../../matched/include/Obj23452.h"
#include "../../matched/include/Obj23453.h"
#include "../../matched/include/Obj23454.h"
#include "../../matched/include/Obj23455.h"
#include "../../matched/include/Obj12238.h"
#include "../../matched/include/Obj07255.h"
#include "../../matched/include/Obj23457.h"
#include "../../matched/include/Obj12239.h"
#include "../../matched/include/Obj04909.h"
#include "../../matched/include/Obj12240.h"
#include "../../matched/include/Obj12241.h"
#include "../../matched/include/Obj18613.h"
#include "../../matched/include/Obj12242.h"
#include "../../matched/include/Obj12243.h"
#include "../../matched/include/Obj07256.h"
#include "../../matched/include/Obj12244.h"
#include "../../matched/include/Obj09248.h"
#include "../../matched/include/Obj09249.h"
#include "../../matched/include/Obj09250.h"
#include "../../matched/include/Obj12245.h"
#include "../../matched/include/Obj23459.h"
#include "../../matched/include/Obj14178.h"
#include "../../matched/include/Obj12246.h"
#include "../../matched/include/Obj14179.h"
#include "../../matched/include/Obj01260.h"
#include "../../matched/include/Obj23460.h"
#include "../../matched/include/Obj23461.h"
#include "../../matched/include/Obj23462.h"
#include "../../matched/include/Obj23463.h"
#include "../../matched/include/Obj23464.h"
#include "../../matched/include/Obj23465.h"
#include "../../matched/include/Obj23466.h"
#include "../../matched/include/Obj23467.h"
#include "../../matched/include/Obj02864.h"
#include "../../matched/include/Obj23476.h"
#include "../../matched/include/Obj23477.h"
#include "../../matched/include/Obj23478.h"
#include "../../matched/include/Obj23479.h"
#include "../../matched/include/Obj23480.h"
#include "../../matched/include/Obj23481.h"
#include "../../matched/include/Obj12247.h"
#include "../../matched/include/Obj07257.h"
#include "../../matched/include/Obj18615.h"
#include "../../matched/include/Obj04532.h"
#include "../../matched/include/Obj07259.h"

struct Obj;
struct CharBuf;
struct Descriptor;
struct Personal;
struct Cfg;
struct Actor;
struct MsgBank;
struct U16Vec;
struct Ctx;
struct PtS;
struct S02030EE8;
struct Node;
struct Vec2;
struct RecDC;
struct Sub0200852CObj;
struct Strbuf;
struct Rec;
struct Sub02008C20Obj;
struct RegB;
struct Rec0200AD8C;
struct Rec0200AD94;
struct WordSet;
struct L0200ED54;
struct Sub02009D9CObj;
struct Ctx_02202094;
struct BigObj;
struct Party;
struct PerapVoice;
struct Sub020079BCEntry;
struct Sub02007AC8Entry;
struct Blk37;
struct PartyMon;
struct Sub02007454Entry;
struct Sub02009470Obj;
struct Sub02008F80Obj;
struct Mon;
struct StrObj;
struct GfFont;
struct Tcbl;
struct PrintSys;
struct S02031140;
struct Rec3;
#include "worldtrade_types.h"


typedef struct {
    u16 x;
    u16 y;
    u16 anim;
    u16 pad;
} CurPos_021FE93C;


typedef struct {
    u8 page;
    u8 slot;
} Sel;

typedef struct {
    u16 x;
    u16 y;
    u16 pad[2];
} CurPos_021FEAE0;


typedef struct {
    void *mon, *ctx, *save;
    u8 type, fD, fE, fF, f10, pad11[3];
    u16 f14, pad16;
    void *f18;
    u32 f1C, f20, f24;
} Request;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

typedef struct {
    u16 x;
    u16 y;
} Pos;


typedef struct { int state; int y; u8 *p; } Anim;


struct DispConfig {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

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

typedef struct { u16 x, y, z; u8 pri, f7; } ObjPos;

typedef struct { u16 x, y; } Pair;


typedef struct {
    u8 raw[0x20];
    u16 old_species;
    u16 new_species;
    u8 x;
    u8 y;
    u8 flags;
    u8 tail;
} Record;


typedef struct {
    int year;
    int month;
    int day;
    int week;
} RTCDate;

typedef struct {
    int hour;
    int minute;
    int second;
} RTCTime;


typedef struct {
    u32 a;
    u32 b;
    u32 c;
} Slot_02202094;

typedef struct {
    void *font;
    void *buf;
    u32 arg;
    void *msg;
    u8 pad10[8];
    Slot_02202094 slot[0x18];
    void *res;
} Ctx_02202094;

typedef struct {
    void *win;
    u8 busy;
    void *active;
} Ent_02202094;

typedef struct {
    u8 pad0[4];
    void *heap;
    u8 pad8[0xC - 8];
    void *queue;
    void *yesno;
    void *yesnoArg;
    Ent_02202094 ent[24];
    void *bg;
} Printer_02202094;

typedef struct {
    void *win;
    u8 busy;
    u8 pad5[3];
    u32 used;
} Slot_02202878;

typedef struct {
    u32 font;
    u8 pad4[0xC - 0x4];
    u32 print;
    u8 pad10[0x18 - 0x10];
    Slot_02202878 slots[24];
} Ctx_02202878;

struct Ent_02202940 { u32 a; u32 b; u32 c; };

struct Obj { u32 w0; u32 w1; u32 w2; u32 w3; void *h; u32 n; struct Ent_02202940 e[24]; };

typedef struct {
    void *font;
    void *msg;
    void *words;
    void *bank;
    u8 pad10[0x60];
    u16 heap;
} Ctx_02202974;

typedef struct {
    void *win;
    u8 busy;
} Ent_02202940;

typedef struct {
    u8 pad0[4];
    void *queue;
    u8 pad8[0x10 - 8];
    Ent_02202940 ent[8];
    void *active[8];
} Printer_02202940;

typedef struct {
    void *win;
    u8 shown;
    u8 pad5[3];
} Slot;

typedef struct {
    void *font;
    void *print;
    void *words;
    void *bank;
    Slot slot[8];
    u32 used[8];
    u16 heap;
} Ctx_02202A50;

/*
 * When the mode query answers 1, publish the u16 at +0xe0c.
 */


extern void func_021F4E98(void *,unsigned,unsigned);
extern void func_020061E4(int);
extern void func_021F4EC0(void *,unsigned,unsigned);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_020362DC(void);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern int func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021C8658(u8 *p);
extern void func_021F4FC4(u8 *p);
extern void func_021F9968(u8 *p, int mode);
extern int func_021F99F0(void *obj);
extern void func_021F89A8(u8 *p, int i, u16 a, u16 b);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021F7F9C(void *win, void *bank, u32 index, u32 y, u32 x, u16 color, void *g);
extern void *func_0201ADE4(unsigned int species, int form, unsigned int heap);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern int func_021F7B9C(u8 *p, int event);
extern void func_021F8098(void *win, void *bank, int mode, int force, u32 x, int y, u16 color, void *g);
extern void func_0201F7A8(void *, unsigned);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_021F882C(u8 *dst, int i, int kind);
extern void func_021F8154(void *, void *, int, unsigned, unsigned, u16, int, void *);
extern void func_021F88B0(u8 *p, u32 n);
extern void func_021F8010(void *, void *, void *, unsigned, unsigned, unsigned, u16, void *);
extern void func_021F4BE0(u32 a, u32 b, u32 c, u32 d, u8 e);
extern int func_021F4D14(char *p);
extern void func_021F4CE4(char *p);
extern int func_02035C60(void);
extern u32 func_020221A4(void);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern u32 func_0204B98C(struct Actor *a);
extern u8 func_020355C4(void);
extern void func_021FE264(u8 *p, int mode);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *p);
extern void func_021F91A0(void *p, void *b, u32 c, u32 d, u32 e, u16 f, void *g);
extern void func_021F91DC(void *p, void *b, u32 c, u32 d, u32 e, u16 f, void *g);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_021F50EC(u8 *);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,u32,u32);
extern void *func_020120F4(const struct Ctx *p);
extern int func_021F6B34(int);
extern u32 func_021F6B80(u8 *p, u32 b, u32 c);
extern void *func_021F6B40(void *,void *,int,int);
extern void func_02031348(void *,u32,const void *,void *);
extern u32 func_020307B0(void *p);
extern void func_021F5074(u8 *p);
extern void func_021F4EC8(u8 *p);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B84C(u32, int);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_021F4EA0(u32 a, u32 b, u32 c);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void *func_02030DA8(void *, void (*)(void *, Anim *), void *, int);
extern u32 func_02030EE8(struct S02030EE8 *p);
extern void func_02030EAC(struct Node *n);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern int func_02035C08(const void *);
extern u16 func_0204B898(struct Obj *p);
extern u32 func_0204B3F4(struct Obj *p);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void DC_FlushRange(void *p, u32 size);
extern void func_0207E804(void *, int, int);
extern void func_0207E5D0(void *, int, int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021F9254(u8 *);
extern int func_0207D55C(volatile u16 *reg);
extern u32 func_02043668(void);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_020435F4(u32 a);
extern void func_02043598(u32 mask, u32 enable);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_02041570(int channel, u16 val);
extern void func_020403F4(unsigned);
extern void sub_020403F4(u32 i);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *h);
extern void func_0203D34C(u32 a, u32 b);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 func_020452E8(struct Descriptor *d);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_021F4F90(void *);
extern int func_021F4ED4(void);
extern void func_020355D8(u8 v);
extern void func_0204B9A0(struct Actor *a);
extern void func_020456F8(struct Descriptor *d);
extern void func_02041B6C(u32);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_020499D4(void *, u32, u32, u32, u32, u32, u32, u16);
extern void func_021F9218(void *win, void *bank, int idx, void *g);
extern void func_021F90A0(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_021F4FA4(u8 *p);
extern void func_02019CE0(const struct RecDC *, struct RecDC *);
extern u32 func_02025C1C(u32, u32, u32);
extern u32 func_02025C30(u32, u32, u32);
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern u32 func_020173EC(void);
extern u8 *func_021B9800(int, int, int);
extern void func_021B98A0(u8 *, int, int, int);
extern void func_021B98D8(u8 *, int, int);
extern int func_021B98F8(u8 *);
extern int func_021B9748(u8 *);
extern int func_021B99DC(u8 *p);
extern int func_021B9790(u8 *p);
extern u8 *func_021B97F4(u8 *p);
extern void func_021B9774(u8 *p);
extern void func_021B99B8(u8 *p);
extern void func_021B9838(u8 *p);
extern int func_021B99F0(u8 *p);
extern u32 func_021B99F4(u32 p, u32 i);
extern u8 *func_021B9A14(u8 *p, u32 i);
extern void func_0200FB4C(u32 id);
extern u32 func_0200F7B8(u32 a0);
extern void func_02082D44(const void *src, void *dst, u32 n);
extern u32 func_0200FBB0(void);
extern void func_0203CA04(void);
extern void func_0200FBA0(void);
extern void func_0203C968(void);
extern void func_02045994(struct Strbuf *,const u16 *,u32);
extern u16 *func_02045A90(struct U16Vec *);
extern u16 func_020458F8(struct U16Vec *);
extern u16 func_02045A98(void);
extern int func_0217BC44(unsigned short **words, int wordsnum, char *reserved, int timeout, char *result, int *badwordsnum, int region);
extern int func_0217BC90(void);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern void func_021C86B8(u8 *dst, u8 *src, u32 n);
extern int func_021C866C();
extern s32 func_021C86A8(void);
extern void func_021F513C(u8 *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void func_021C8770(u8 *p);
extern void func_021C87FC(u8 *p);
extern u32 func_0200ADB4(u32 a);
extern u16 func_0200ADE0(struct RegB *p);
extern void func_021C8978(u8 *p);
extern void func_021C8C68(u32, const void *, u32, const void *, u32);
extern void func_021C8D14(u8 *p);
extern void func_021C887C(u8 *p);
extern u16 func_0200AD8C(const struct Rec0200AD8C *p);
extern void func_0200AD9C(void *sys, void *mon);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0200AD94(struct Rec0200AD94 *p, u16 v);
extern void *func_0200ED48(void *);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
extern void *func_021F72C4(void *);
extern void *func_02009EC8(void *);
extern void func_02009DE8(struct Sub02009D9CObj *obj, struct Sub0200852CObj *p);
extern void *memset(void *, int, u32);
extern void func_02008494(void *src, void *dst);
extern u32 func_02017E1C(void *, u32, u32);
extern u32 func_0202EB7C(u32 a0, u32 a1);
extern void func_021C89F0(void);
extern void func_021C88FC(u8 *p);
extern u32 func_021F9088(u8 *p, u32 a, u32 b, u32 c, u32 d);
extern int func_02012DAC(int a0);
extern u32 func_020056EC(u32 v);
extern int func_02012DD0(u8 *p);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern void func_0200ADB8(void *dest, const void *src, u32 a2);
extern void func_02007664(void *, unsigned, unsigned);
extern void *func_0201AB28(void *, unsigned);
extern u32 func_0201A9C8(struct Party *p, s32 idx);
extern struct Sub02007AC8Entry *func_02012F98(void *p);
extern void *func_02012934(const struct BigObj *p);
extern void func_02007C34(struct PerapVoice *p, void *a);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern u32 func_0201AA18(void *p);
extern void func_02017E40(void *mon, u32 id, u32 v);
extern u8 func_02017F50(u32 species, u16 form, u32 pid);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern int func_020076D0(void *save, int *pbox, int *pslot);
extern int func_0200752C(void **save, u32 box, const struct Sub02007454Entry *src);
extern int DWC_GetDateTime(RTCDate *date, RTCTime *time);
extern void func_0200ADD8(struct RegB *p, u32 value);
extern void func_0200ADD0(struct RegB *p, u32 value);
extern u32 func_0200949C(const struct Sub02009470Obj *obj, int row, int col);
extern void func_020094D8(struct Sub02009470Obj *obj, int row, int col, int value);
extern int func_021F6DE8(u32 handle);
extern void func_02019B58(void *mon);
extern u32 func_0202136C(u16 v);
extern void *func_02008F08(int a0);
extern void func_02008F88(struct Sub02008F80Obj *obj, const void *src);
extern void *func_0201747C(struct Mon *p, u32 heap);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_020185F4(void *a);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern void *func_02028590(u32 a0, u32 a1, u32 a2, u32 heap);
extern int func_02028604(int a0);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern void func_02031140(struct S02031140 *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_020286C4(struct Ctx_02202094 *ctx, void *p, void *cell);
extern u32 func_0201CE30(void *p);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201CE38(void *menu);
extern void func_0201CE48(struct Rec3 *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_020310C4(struct Tcbl *p);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *, s16, s16, unsigned, unsigned, int, unsigned, unsigned, unsigned, unsigned);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
int func_021FE93C(char *p);
int func_021FE974(char *p);
int func_021FE9B0(Work *p);
void func_021FE9DC(Work *p);
void func_021FEAE0(Work *p, int i);
int func_021FEB50(u8 *p);
int func_021FEB84(u8 *p);
int func_021FEBB8(u8 *p);
int func_021FEBE0(u8 *p);
int func_021FEC00(Work *p);
int func_021FED24(u8 *p);
int func_021FED4C(u8 *p);
int func_021FED6C(char *p);
int func_021FEE1C(u8 *p);
int func_021FEE44(u8 *p);
int func_021FEE70(char *p);
int func_021FEEFC(u8 *p);
int func_021FEF24(u8 *p);
int func_021FEF50(char *p);
int func_021FF004(u8 *p);
int func_021FF024(char *p);
int func_021FF070(char *p);
int func_021FF078(u8 *p);
int func_021FF0A0(u8 *p);
int func_021FF0BC(u8 *p);
int func_021FF0E8(u8 *p);
int func_021FF118(char *p);
int func_021FF174(u8 *p);
int func_021FF198(char *p);
int func_021FF218(char *p);
int func_021FF26C(char *p);
int func_021FF2D0(u8 *p);
void func_021FF318(u8 *p, u32 k, int b, int c, int d);
void func_021FF384(void **win, void **win2, void *bank, void *g);
void func_021FF474(void *win, void *bank, int flag, void *g);
int func_021FF4D0(Rec *x, Rec *y, int m, int n);
void func_021FF50C(Work *p);
void func_021FF570(u32 v);
void func_021FF58C(u8 *p);
u32 func_021FF65C(u8 *p);
u32 func_021FF67C(u8 *p);
void func_021FF6A4(Work *p);
void func_021FF8B0(u8 *p);
void func_021FF914(u32 *p, u32 v);
void func_021FF92C(void *task, Anim *a);
void func_021FF9E0(u8 *p);
void func_021FFA3C(void *task, Anim *a);
void func_021FFAEC(u32 a, int b, int c);
int func_021FFB00(int n);
void func_021FFB20(u8 *p, int count, int flag);
int func_021FFBC0(int i);
void func_021FFBC8(u8 *p);
void func_021FFC18(Work *p);
void func_021FFC8C(u8 **p, u8 *q, int k, int n, int a4);
void func_021FFCD4(Work *p);
void func_021FFD1C(Work *p, int i, int dy);
void func_021FFD44(char *p);
void func_021FFD74(char *p);
int func_021FFDA8(u8 *p);
void func_021FFEB4(u8 *p);
int func_021FFEC8(u8 *p);
void func_021FFF10(void);
void func_021FFFE8(u8 *p, u32 a, u32 b);
void func_022000E4(char *p);
void func_02200118(void);
void func_02200130(char *p);
void func_0220015C(u8 *a0);
void func_022001F4(u8 *p);
void func_02200290(u8 *p);
void func_022002A0(u8 *p);
void func_022003BC(u8 *p);
void func_0220040C(u8 *p);
void func_02200434(u8 *p);
int func_02200450(u8 *p);
int func_02200490(u8 *p);
int func_022004A0(u8 *p);
int func_022004C8(u8 *p);
int func_022004DC(u8 *p);
int func_022004F0(unsigned char *p);
int func_0220052C(void);
void func_0220053C(u8 *p, int mode);
int func_022005EC(Work *p);
int func_02200770(u8 *p);
int func_0220078C(Work *p);
int func_022007A0(u8 *p);
int func_022007E0(u8 *p);
int func_02200800(u8 *p);
int func_022008B0(u8 *p);
int func_022008F0(u8 *p);
int func_0220090C(u8 *p);
void func_0220093C(Work *p);
void func_022009A4(u8 *p, u32 n, int a2, int a3, int a4);
void func_02200A10(u8 *p, int k, int a2, int a3, int a4);
void func_02200A7C(void *p,void *bank,u32 b,u32 id,u32 fifth,void *out,u16 se);
void func_02200AB4(u8 *p);
void func_02200B34(u8 *p);
void func_02200BAC(u8 *p, u32 k);
int func_02200C0C(u8 *p);
void func_02200C80(u8 *p);
int func_02200C94(u8 *p);
void func_02200CCC(void);
void func_02200DB8(void);
void func_02200DD0(u8 *p);
void func_02200E48(u8 *p);
void func_02200E94(u8 *p);
void func_02200EB0(u8 *p);
void func_02200EC8(u8 *p);
int func_02200ED8(Work *p);
int func_02200FF4(u8 *p);
int func_022010BC(Work *p);
int func_02201258(u8 *p);
int func_02201320(u8 *p);
int func_022013E4(u8 *p);
int func_02201414(u8 *p);
int func_022014B8(u8 *p);
int func_022014D8(u8 *p);
int func_02201554(u8 *p);
int func_0220157C(u8 *p);
int func_0220163C(u8 *p);
int func_02201658(u8 *p);
int func_022016CC(u8 *p);
int func_0220171C(u8 *p);
int func_022017F0(u8 *p);
int func_0220180C(u8 *p);
int func_02201880(u8 *p);
int func_0220189C(Work *p);
int func_02201A34(u8 *p);
int func_02201A48(u8 *p);
int func_02201A64(u8 *p);
void func_02201B18(u8 *p);
void func_02201B44(u8 *p, void *mon, u8 *r, void *old);
int func_02201C08(char *p);
int func_02201C24(u8 *p);
int func_02201C88(u8 *p);
int func_02201CBC(u8 *p);
int func_02201D14(u8 *p);
int func_02201D30(u8 *p);
int func_02201DBC(void);
int func_02201DC0(u8 *p);
int func_02201DD8(u8 *p);
int func_02201DF0(u8 *p);
int func_02201E04(u8 *p);
int func_02201E1C(u8 *p);
int func_02201E38(u8 *p);
int func_02201ED4(u8 *p);
u32 func_02201F18(u8 *p);
int func_02201FA4(u8 *p);
int func_02201FDC(u8 *p);
int func_02202000(u8 *p);
int func_02202038(u8 *p);
int func_02202054(u8 *p);
int func_0220207C(Work *p);
int func_02202094(u8 *p);
int func_022020B8(u8 *p);
int func_022020E0(u8 *p);
int func_022020F8(u8 *p);
int func_02202148(u8 *p);
int func_022021A4(u8 *p);
int func_022021C0(u8 *p);
void func_022021F8(u8 *p, int flag);
void func_022022B8(Work *p, void *mon, u32 box, int hatch);
void func_022023A4(u8 *p,void *mon,void *unused2,void *unused3,u32 index);
void func_0220246C(void *p, int which);
void func_022024B0(void *obj,u8 *p);
int func_022024DC(Work *p, void *mon);
void func_0220251C(u8 *p, u16 a, u16 b);
u32 func_0220252C(u8 *p);
void func_0220254C(void *mon, u32 heap);
void func_022025E4(u32 a, u32 b, u32 c);
void *func_02202608(u32 heap);
void func_0220262C(u32 a, u32 b);
void func_02202644(u32 a, int kind);
u32 func_02202670(u32 a, u32 b, u32 c, u32 d);
void func_022026A0(u8 *p, u32 k);
u32 func_022026BC(void *mon);
int func_022026C4(u32 *p, u32 b, u32 a, u32 c);
void func_022026D8(Ctx_02202094 *ctx, u32 arg);
void func_02202744(u8 *p);
void func_02202770(Printer_02202094 *p);
u32 func_02202840(u8 *p);
u32 func_02202858(void *p,u8 b,void *s,u32 x,u32 y,void *out);
void func_02202878(void *a, unsigned b, unsigned c, int d, int e, u8 *p);
u32 func_022028C8(void *win, u8 z, u32 str, u32 x, u32 y, u32 z2, u16 color, Ctx_02202878 *g);
void func_02202940(struct Obj *p);
Ctx_02202974 *func_02202974(u32 a, u32 b, u32 c, u32 heap);
void func_022029D4(u8 *p);
void func_022029F8(Printer_02202940 *q);
void func_02202A50(Ctx_02202A50 *ctx, u32 num, u32 digits, u32 mode, void *win, int x, int y);
extern const CurPos_021FE93C tbl_02203D46[];
extern const Sel tbl_02203D38[];
extern const int d_02202EAC;
extern const u16 d_02203D4A[][4];
extern const char str_02203E30[], ov131_id[];
extern const u32 d_021DC800[];
extern const Pos tbl_022038A2[];
extern const char str_02203E44[];
extern char d_022038BE;
extern const u16 d_02203884[];
extern const u8 d_02203892[];
extern void *g_02203E58[];
extern struct DispConfig g_02203914;
extern struct BgTemplate g_022039A4;
extern struct BgTemplate g_02203984;
extern struct BgTemplate g_022039C4;
extern struct BgTemplate g_02203944;
extern struct BgTemplate g_02203924;
extern struct BgTemplate g_02203964;
extern struct BgTemplate g_022039E4;
extern const Pair d_022038E0[];
extern char g_022038EC[];
extern const Pos tbl_022038E0[];
extern const u32 d_022038FC[][3];
extern void *g_02203E94[];
extern struct DispConfig g_02203A04;
extern struct BgTemplate g_02203A14;
extern struct BgTemplate g_02203A54;
extern struct BgTemplate g_02203A34;
extern const char str_02203F58[];
extern const char g_02203F5C[];


int func_021FE93C(char *p) {func_021FF318((u8 *)p,171,4,0,0xf0f);func_021F4E98(p,24,31);((struct Obj23416 *)p)->fDFC=0;func_020061E4(0x557);return 2;}


int func_021FE974(char *p) {func_021FF318((u8 *)p,172,4,0,0xf0f);func_021F4E98(p,24,3);func_021F4EC0(p,0,21);func_020061E4(0x557);return 2;}


/*
 * Return the current cursor slot of the state block at +0xE00: the +0x28
 * word while the +0x24 flag is clear, else the +0x2C word plus four.
 * A slot of seven or more reports through func_02034714 (the raw-address
 * assert shape; 0x02203E2C is a plain constant, as in func_02202B20).
 */
int func_021FE9B0(Work *p)
{
    State *s = p->st;
    int r;

    if (s->f24 == 0) {
        r = s->f28;
    } else {
        r = s->f2C + 4;
    }
    if (r >= 7) {
        func_02034714((void *)0x02203E2C, 0, (void *)0x02203E2C);
    }
    return r;
}


/*
 * Move the menu cursor by the pressed d-pad key: up and down step the
 * +0x28 row (page 0, rows 0..3) or the +0x2C row (page 1, rows 0..2),
 * right and left switch the +0x24 page. A real move plays sound 0x548
 * and sets the cursor sprite's animation from the position table; the
 * cursor is then placed at the table position of the current slot.
 */
void func_021FE9DC(Work *p)
{
    int a;
    int b;

    if (func_020362DC() & 0x40) {
        if (p->st->f24 == 0) {
            if (p->st->f28 > 0) {
                p->st->f28--;
                func_020061E4(0x548);
                func_0204B878((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0((Work *)p)].anim);
            }
        } else {
            if (p->st->f2C > 0) {
                func_020061E4(0x548);
                p->st->f2C--;
                func_0204B878((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0((Work *)p)].anim);
            }
        }
    } else if (func_020362DC() & 0x80) {
        if (p->st->f24 == 0) {
            if (p->st->f28 < 3) {
                p->st->f28++;
                func_020061E4(0x548);
                func_0204B878((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0((Work *)p)].anim);
            }
        } else {
            if (p->st->f2C < 2) {
                func_020061E4(0x548);
                p->st->f2C++;
                func_0204B878((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0((Work *)p)].anim);
            }
        }
    } else if (func_020362DC() & 0x10) {
        if (p->st->f24 != 1) {
            p->st->f24 = 1;
            func_020061E4(0x548);
            func_0204B878((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0((Work *)p)].anim);
        } else {
            p->st->f24 = 1;
        }
    } else if (func_020362DC() & 0x20) {
        if (p->st->f24 != 0) {
            p->st->f24 = 0;
            func_020061E4(0x548);
            func_0204B878((struct Obj *)p->cursor, tbl_02203D46[func_021FE9B0((Work *)p)].anim);
        } else {
            p->st->f24 = 0;
        }
    }
    a = func_021FE9B0((Work *)p);
    b = func_021FE9B0((Work *)p);
    func_021F4FF4(p->cursor, tbl_02203D46[a].x, tbl_02203D46[b].y);
}


/*
 * Select cursor entry i from the {page, slot}
/*
 * Select cursor entry i from the {page, slot} byte table: page 0 stores
 * the slot at +0x28 of the state block, any other page sets the +0x24
 * flag and stores it at +0x2C. Then redraw the cursor sprite at +0xBF4
 * from the 8-byte position table.
 */
void func_021FEAE0(Work *p, int i)
{
    int a;
    int b;

    if (tbl_02203D38[i].page == 0) {
        p->st->f24 = 0;
        p->st->f28 = tbl_02203D38[i].slot;
    } else {
        p->st->f24 = 1;
        p->st->f2C = tbl_02203D38[i].slot;
    }
    a = func_021FE9B0((Work *)p);
    b = func_021FE9B0((Work *)p);
    func_021F4FF4(p->cursor, tbl_02203D46[a].x, tbl_02203D46[b].y);
}


/*
 * When the countdown at +0xd3c is spent, run the fixed 3/6/1/0x48 opener, then state 0.
 */
int func_021FEB50(u8 *p)
{
    if (((struct Obj12213 *)p)->fD3C == 0) {
        func_0202208C((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    ((struct Obj12213 *)p)->f28 = 0;
    return 3;
}


/*
 * Every concrete byte is reproduced (52 bytes of code; the listing's extra two
 * are alignment padding).  The one wildcard is the BLX at +0006 to
 * func_021C8658, which has no independent witness outside 0x021FEB84..0x021FEBB6; the
 * resolver reports "(arm, from name) ... 8 overlays overlap this address
 * (ov016, ov021, ov093, ov111, ov114, ov128, ov172, ov208), none resolvable
 * without a region hint on the symbols: line".  Naming one of those eight
 * regions would be a guess, so the site stays parked.
 *
 * Shape: two hand-overs, then the fixed 6/1/0x48 opener, state 0, return 3.
 */
int func_021FEB84(u8 *p)
{
    func_021C8658(p);
    func_021F4FC4(p);
    func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
    ((struct Obj00018 *)p)->f28 = 0;
    return 3;
}


/*
 * Build through func_021FF318 and publish the 0x10/0x5 pair.
 */
int func_021FEBB8(u8 *p)
{
    func_021FF318(p, 0x9, 1, 0, 0xf0f);
    func_021F4E98((char *)p, 0x17, 0x5);
    return 2;
}


/*
 * Publish +0xde4, kick helper 9, latch state 6.
 */
int func_021FEBE0(u8 *p)
{
    func_021F9968((u8 *)(((struct Obj12214 *)p)->fDE4), 0);
    func_021FF570(9);
    ((struct Obj12214 *)p)->f28 = 6;
    return 2;
}


int func_021FEC00(Work *p)
{
    int r = func_021F99F0(p->menu);
    u32 h;
    u32 v;

    switch (r) {
    case -2:
        func_021FF570(0);
        p->state = 0;
        func_021F89A8(p->area, p->target->x6 + p->target->x4, p->target->xA, p->target->x8);
        break;
    case -1:
        break;
    default:
        func_021FF570(0);
        p->sel_h = r;
        p->state = 0;
        func_02043B5C(func_02045770(p->winA), 0);
        func_021F7F9C(p->winA, p->names, r, 0, 0, 0x3C40, p->fFA0);
        h = (u32)func_0201ADE4((u16)r, 0, 0x48);
        v = func_0201AE1C((const struct Personal *)h, 0x14);
        func_0201AE14((void *)h);
        p->target->x20 = v;
        func_021F89A8(p->area, p->target->x6 + p->target->x4, p->target->xA, p->target->x8);
        if (func_021F7B9C((u8 *)(&p->sel_h), p->target->x20) != 0) {
            func_02043B5C(func_02045770(p->winB), 0);
            func_021F8098(p->winB, p->bank, p->mode_sb, 1, 0, 0, 0x3C40, p->fFA0);
        }
        break;
    }
    return 2;
}


/*
 * Build through func_021FF318 and publish the 0x10/0x8 pair.
 */
int func_021FED24(u8 *p)
{
    func_021FF318(p, 0xa, 1, 0, 0xf0f);
    func_021F4E98((char *)p, 0x17, 0x8);
    return 2;
}


/*
 * Publish the +0xde4 slot, kick helper 9 and latch state 9.
 */
int func_021FED4C(u8 *p)
{
    func_021F9968((u8 *)(((struct Obj12215 *)p)->fDE4), 1);
    func_021FF570(9);
    ((struct Obj12215 *)p)->f28 = 9;
    return 2;
}


int func_021FED6C(char *p)
{
    unsigned r;
    void *w;
    r = func_021F99F0(((struct Obj02861 *)p)->fDE4);
    switch (r) {
    case -2:
        func_021FF570(0);
        func_0201F7A8(((struct Obj02861 *)p)->fD40, 0);
        w = ((struct Obj02861 *)p)->fD40;
        func_02045334(w);
        func_02045374(w);
        func_020409B4(func_02045730(w));
        ((struct Obj02861 *)p)->f28 = 0;
        break;
    case 0:
    case 1:
    case 2:
        func_021FF570(0);
        ((struct Obj02861 *)p)->fB58 = r + 1;
        ((struct Obj02861 *)p)->f28 = 0;
        func_02043B5C(func_02045770(((struct Obj02861 *)p)->fD9C), 0);
        func_021F8098(((struct Obj02861 *)p)->fD9C, ((struct Obj02861 *)p)->fB6C, ((struct Obj02861 *)p)->fB58, 1, 0, 0, 0x3c40, p + 0xfa0);
        break;
    }
    return 2;
}


/*
 * Build through func_021FF318 and publish the 0x10/0xb pair.
 */
int func_021FEE1C(u8 *p)
{
    func_021FF318(p, 0xb, 1, 0, 0xf0f);
    func_021F4E98((char *)p, 0x17, 0xb);
    return 2;
}


/*
 * Sentinel at +0xbc, publish +0xde4, kick helper 9, latch state 0xc.
 */
int func_021FEE44(u8 *p)
{
    ((struct Obj09239 *)p)->fBC = 0xffff;
    func_021F9968((u8 *)(((struct Obj09239 *)p)->fDE4), 2);
    func_021FF570(9);
    ((struct Obj09239 *)p)->f28 = 0xc;
    return 2;
}


int func_021FEE70(char *p)
{
    unsigned r = func_021F99F0(((struct Obj05417 *)p)->fDE4);
    switch (r) {
    case 11:
    case -2:
        func_021FF570(0);
        ((struct Obj05417 *)p)->f28 = 0;
        break;
    case -1: break;
    default:
        func_021FF570(0);
        func_021F882C((u8 *)(p + 0xb56), r, 1);
        ((struct Obj05417 *)p)->f28 = 0;
        func_02043B5C(func_02045770(((struct Obj05417 *)p)->fDA4), 0);
        func_021F8154(((struct Obj05417 *)p)->fDA4, ((struct Obj05417 *)p)->fB6C, r, 0, 0, 0x3c40, 1, p + 0xfa0);
        break;
    }
    return 2;
}


/*
 * Build through func_021FF318 and publish the 0x10/0xe pair.
 */
int func_021FEEFC(u8 *p)
{
    func_021FF318(p, 0xbe, 1, 0, 0xf0f);
    func_021F4E98((char *)p, 0x17, 0xe);
    return 2;
}


/*
 * Sentinel at +0xbc, publish +0xde4, kick helper 9, latch state 0xf.
 */
int func_021FEF24(u8 *p)
{
    ((struct Obj09240 *)p)->fBC = 0xffff;
    func_021F9968((u8 *)(((struct Obj09240 *)p)->fDE4), 3);
    func_021FF570(9);
    ((struct Obj09240 *)p)->f28 = 0xf;
    return 2;
}


int func_021FEF50(char *p)
{
    int r;
    void *w;
    r = func_021F99F0(((struct Obj02204 *)p)->fDE4);
    if (r == -1) {
    } else if (r == -2 || r == d_02202EAC + 1) {
        func_021FF570(0);
        func_0201F7A8(((struct Obj02204 *)p)->fD40, 0);
        w = ((struct Obj02204 *)p)->fD40;
        func_02045334(w);
        func_02045374(w);
        func_020409B4(func_02045730(w));
        ((struct Obj02204 *)p)->f28 = 0;
    } else {
        func_021FF570(0);
        func_021F88B0((u8 *)p, r);
        ((struct Obj02204 *)p)->f28 = 0;
        func_02043B5C(func_02045770(((struct Obj02204 *)p)->fDDC), 0);
        func_021F8010(((struct Obj02204 *)p)->fDDC, ((struct Obj02204 *)p)->fB7C, ((struct Obj02204 *)p)->fB6C, ((struct Obj02204 *)p)->fF84, 0, 0, 0x3c40, p + 0xfa0);
    }
    return 2;
}


int func_021FF004(u8 *p)
{
    func_021F4BE0((u32)p, 0x14, 0x120, 0x3, 0x1);
    ((struct Obj18599 *)p)->f28 = 0x1b;
    return 2;
}


int func_021FF024(char *p)
{
    unsigned r = func_021F4D14(p);
    if (r == 1) {
        func_021F4CE4(p);
        *(int *)&((struct Obj00045 *)p)->f28 = 2;
        func_021F4EC0((u8 *)p, 1, 0);
        if (((struct Obj00045 *)p)->fD0 > 0) func_021FFBC8((u8 *)p);
        ((struct Obj00045 *)p)->fD0 = 0;
    } else if (r == 2) {
        func_021F4CE4(p);
        *(int *)&((struct Obj00045 *)p)->f28 = 0;
    }
    return 2;
}


int func_021FF070(char *p)
{
    ((struct Obj23427 *)p)->f28 = 1;
    return 2;
}


/*
 * Build through func_021FF318 and publish the 0x10/0x1 pair.
 */
int func_021FF078(u8 *p)
{
    func_021FF318(p, 0x9e, 1, 0, 0xf0f);
    func_021F4E98((char *)p, 0x17, 0x1);
    return 2;
}


int func_021FF0A0(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        ((struct Obj12216 *)p)->f28 = ((struct Obj12216 *)p)->f2C;
    }
    return 2;
}


/*
 * When the build query answers 0 and either probe is set, roll the state word over.
 */
int func_021FF0BC(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        if (func_020362DC() != 0 || func_02035C60() != 0) {
            ((struct Obj12217 *)p)->f28 = ((struct Obj12217 *)p)->f2C;
        }
    }
    return 2;
}


/*
 * When the build query answers 0, bump the countdown at +0xdfc and roll state when it passes 0x2d.
 */
int func_021FF0E8(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        if (++((struct Obj07250 *)p)->fDFC > 0x2d) {
            ((struct Obj07250 *)p)->fDFC = 0;
            ((struct Obj07250 *)p)->f28 = ((struct Obj07250 *)p)->f2C;
        }
    }
    return 2;
}


/*
 * volatile: 021FF12E reads hardware register 04000304.
 */
int func_021FF118(char *p)
{
    ++((struct Obj05418 *)p)->fD3C;
    if (func_020221A4()) {
        *(volatile u16 *)0x04000304 |= 0x8000;
        ((struct Obj05418 *)p)->fD3C = -16;
        if (((struct Obj05418 *)p)->fE1A) {
            ((struct Obj05418 *)p)->f28 = 2;
            func_021F4EC0((u8 *)p, 3, 16);
            ((struct Obj05418 *)p)->fD4 = 0;
        }
        func_0204B3DC((struct Obj *)((struct Obj05418 *)p)->fD38, 0);
    }
    return 2;
}


/*
 * Decrement the countdown at +0xd3c and, when the tick returns non-zero, zero it and latch state 1.
 */
int func_021FF174(u8 *p)
{
    u32 v = ((struct Obj07251 *)p)->fD3C - 1;

    ((struct Obj07251 *)p)->fD3C = v;
    if (func_020221A4() != 0) {
        ((struct Obj07251 *)p)->fD3C = 0;
        ((struct Obj07251 *)p)->f28 = 1;
    }
    return 2;
}


int func_021FF198(char *p)
{
    int r;
    if (func_020362DC() & 1) {
        func_0202208C(0, 0, 0, 0, 16, 1, 72);
    } else {
        r = func_021FFB00(((struct Obj08192 *)p)->fD0);
        if (((struct Obj08192 *)p)->fE1A && r >= 0) {
            func_0204B878((struct Obj *)(*(unsigned *)(p + 0xd0c + (r + 1) * 4)), (u16)(16 + r * 4));
            ((struct Obj08192 *)p)->f28 = 2;
            func_021F4EC0((u8 *)p, 3, 0);
            ((struct Obj08192 *)p)->fD4 = r;
            func_020061E4(0x54c);
        }
    }
    return 2;
}


int func_021FF218(char *p)
{
    if (func_0204B98C((struct Actor *)(((struct Obj00018 *)p)->fBF4)) == 0) {
        func_0204B878((struct Obj *)(((struct Obj00018 *)p)->fBF4), d_02203D4A[func_021FE9B0((Work *)p)][0]);
        if (func_020355C4() == 1)
            func_0204B3DC((struct Obj *)((struct Obj00018 *)p)->fBF4, 0);
        else
            func_0204B3DC((struct Obj *)((struct Obj00018 *)p)->fBF4, 1);
        func_021FE264((u8 *)p, func_021FE9B0((Work *)p));
    }
    return 2;
}


int func_021FF26C(char *p)
{
    if (func_0204B98C((struct Actor *)(((struct Obj00018 *)p)->fBF4)) == 0) {
        func_0204B878((struct Obj *)(((struct Obj00018 *)p)->fBF4), d_02203D4A[func_021FE9B0((Work *)p)][0]);
        if (func_020355C4() == 1)
            func_0204B3DC((struct Obj *)((struct Obj00018 *)p)->fBF4, 0);
        else
            func_0204B3DC((struct Obj *)((struct Obj00018 *)p)->fBF4, 1);
        func_021FF318((u8 *)p, 15, 1, 0, 0xf0f);
        func_021F4E98((char *)((u8 *)p), 23, 26);
    }
    return 2;
}


int func_021FF2D0(u8 *p)
{
    if (func_0204B98C((struct Actor *)(((struct Obj00018 *)p)->fBF4)) == 0) {
        func_0204B878((struct Obj *)(((struct Obj00018 *)p)->fBF4), d_02203D4A[func_021FE9B0((Work *)((char *)p))][0]);
        if (func_020355C4() == 1) {
            func_0204B3DC((struct Obj *)((struct Obj00018 *)p)->fBF4, 0);
        } else {
            func_0204B3DC((struct Obj *)((struct Obj00018 *)p)->fBF4, 1);
        }
        ((struct Obj00018 *)p)->f28 = 1;
    }
    return 2;
}


/*
 * Tear the object down: unhook the two sub-objects, release the +0xd40 resource, wire the 0/1/e quad, then drain the four engine hooks.
 */
void func_021FF318(u8 *p, u32 k, int b, int c, int d)
{
    u32 v;

    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00018 *)p)->fB6C), k, (void *)(*(u32 *)(p + 0xb6c + 0x1c)));
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj00018 *)p)->fD40)), 0xf);
    func_0201F73C((void *)(((struct Obj00018 *)p)->fD40), 0, 1, 0xe);
    func_02202858((void *)(((struct Obj00018 *)p)->fD40), 0, (void *)(*(u32 *)(p + 0xb6c + 0x1c)), 0, 0, p + 0xfa0);
    v = ((struct Obj00018 *)p)->fD40;
    func_02045334((struct Descriptor *)v);
    func_02045374((struct Cfg *)v);
    func_020409B4(func_02045730((struct Descriptor *)v));
}


/*
 * note: pass 2 2026-10-06 P2L19: closed from 8 B off (238 B). The print callees func_021F91A0 and
 *   func_021F91DC are declared void here. Their bodies end in a call and never set r0 themselves, so the
 *   image does not decide between int and void, and no caller reads the result. With int, the six stack
 *   zeros and the six 0x440 stores tie and the zero takes r7; with void the colour 0x440 takes r7 and
 *   the zero is rematerialised per call, as in the image. Plain literals, no pragma.
 */
void func_021FF384(void **win, void **win2, void *bank, void *g)
{
    void *s1, *s2, *s3, *s4, *s5, *s6;

    s1 = func_02045EC0(bank, 0x43);
    func_021F91A0(win[0], s1, 0, 0, 0, 0x440, g);
    func_02045808(s1);

    s2 = func_02045EC0(bank, 0x45);
    func_021F91A0(win[2], s2, 0, 0, 0, 0x440, g);
    func_02045808(s2);

    s3 = func_02045EC0(bank, 0x47);
    func_021F91A0(win[4], s3, 0, 0, 0, 0x440, g);
    func_02045808(s3);

    s4 = func_02045EC0(bank, 0xB9);
    func_021F91A0(win2[0], s4, 0, 0, 0, 0x440, g);
    func_02045808(s4);

    s5 = func_02045EC0(bank, 0x49);
    func_021F91DC(win[6], s5, 0, 0, 0, 0x440, g);
    func_02045808(s5);

    s6 = func_02045EC0(bank, 0xFC);
    func_021F91DC(win[7], s6, 0, 0, 0, 0x440, g);
    func_02045808(s6);
}


void func_021FF474(void *win, void *bank, int flag, void *g)
{
    void *str;
    u16 color;
    u8 pal;

    color = 0x3C40;
    if (flag != 0) {
        color = 0x440;
        pal = 0;
    } else {
        pal = 2;
    }
    func_020413B0(1, 0x11, 2, 0xF, 4, pal);
    func_020409B4(1);
    str = func_02045EC0(bank, 0x4B);
    func_021F91DC(win, (void *)str, 0, 0, 0, color, (void *)g);
    func_02045808(str);
}


/*
 * True when two {s16, s8, s8, s8}
/*
 * True when two {s16, s8, s8, s8} records are equal field by field and
 * the two trailing arguments are equal.
 */
int func_021FF4D0(Rec *x, Rec *y, int m, int n)
{
    if (x->name == y->name && x->mode == y->mode && x->key == y->key && x->val == y->val && m == n) {
        return 1;
    }
    return 0;
}


void func_021FF50C(Work *p)
{
    func_02040618(0, 3, p->scroll);
    func_02040618(1, 3, p->scroll);
    func_02040618(2, 3, p->scroll);
    func_02040618(3, 3, p->scroll);
    func_02040618(4, 3, -p->scroll);
    func_02040618(5, 3, -p->scroll);
    func_02040618(6, 3, -p->scroll);
    func_02040618(7, 3, -p->scroll);
}


/*
 * Program the 0x04000050 display register from the flag, or clear it.
 */
void func_021FF570(u32 v)
{
    if (v != 0) {
        func_0207D658(0x04000050, 0xa, v);
    } else {
        *(u16 *)0x04000050 = 0;
    }
}


void func_021FF58C(u8 *p)
{
    Request *r;
    func_021F50EC(p);
    *(Request * *)&((struct Obj01162 *)p)->f10DC=func_02030734(0x48,sizeof(Request),0,str_02203E30,0x4C);
    func_02082BCC(*(Request * *)&((struct Obj01162 *)p)->f10DC,0,sizeof(Request));
    r=*(Request * *)&((struct Obj01162 *)p)->f10DC;
    r->ctx=((struct Obj23428 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->f20;
    r->save=func_020120F4(((struct Obj23429 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->f40);
    if(func_021F6B34(((struct Obj01162 *)p)->fC4))
        r->fE=func_021F6B80(((struct Obj23430 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->f8,(u32)(((struct Obj23431 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->fC),((struct Obj01162 *)p)->fC4);
    else r->fE=30;
    r->fF=((struct Obj01162 *)p)->fC6;
    r->fD=1;
    r->f14=0;
    r->f10=0;
    r->f18=((struct Obj23432 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->f2C;
    r->f20=0;
    if(func_021F6B34(((struct Obj01162 *)p)->fC4)) {
        r->mon=((struct Obj23433 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->f8;
        r->type=1;
    } else {
        r->mon=func_021F6B40(((struct Obj23434 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->f8,((struct Obj23435 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->fC,((struct Obj01162 *)p)->fC4,0);
        r->type=2;
    }
    func_02031348(((struct Obj01162 *)p)->f12F0,(u32)ov131_id,d_021DC800,r);
    ((struct Obj01162 *)p)->fB8=1;
}


/*
 * Answer 2, or set the 5/mode pair and answer 3 when the +0x12f4 word is clear.
 */
u32 func_021FF65C(u8 *p)
{
    u32 r = 2;

    if (((struct Obj12221 *)p)->f12F4 == 0) {
        func_021F4EC0(p, 5, ((struct Obj12221 *)p)->f20);
        r = 3;
    }
    return r;
}


u32 func_021FF67C(u8 *p)
{
    u32 q = ((struct Obj12222 *)p)->f10DC;

    ((struct Obj12222 *)p)->fC6 = ((struct Obj18600 *)q)->fF;
    func_020307B0((void *)q);
    func_021F5074(p);
    func_021F4EC8(p);
    return 0;
}


/*
 * Create the screen's sprites after loading their graphics
 * (func_021FFC18): the header sprite, seven list sprites placed from the
 * position table with palettes 2..8, the arrow sprite and the page
 * sprite, then record the position of each of the first eight sprites
 * at +0xEC4.
 */
void func_021FF6A4(Work *p)
{
    Local s;
    SPos pos;
    int i;

    func_021FFC18((Work *)p);
    s.a = 0x80;
    s.b = 0x82;
    s.c = 0;
    s.d = 0;
    s.e = 0;
    p->spr[0] = (u32)func_0204B294((void *)p->res_res.f0, p->res_res.f1C, p->res_res.f20, p->res_res.f24, &s, 1, 0x48);
    func_0204B92C((struct Obj *)p->spr[0], 1);
    func_0204B84C(p->spr[0], 2);
    func_0204B878((struct Obj *)p->spr[0], 3);
    func_0204B3DC((struct Obj *)p->spr[0], 1);
    for (i = 0; i < 7; i++) {
        p->spr[i + 1] = (u32)func_0204B294((void *)p->res_res.f0, p->res_res.f10, p->res_res.f14, p->res_res.f18, &s, 1, 0x48);
        func_0204B92C((struct Obj *)p->spr[i + 1], 1);
        func_0204B878((struct Obj *)p->spr[i + 1], i * 4 + 0xE);
        func_0204B3DC((struct Obj *)p->spr[i + 1], 0);
        func_021FFAEC(p->spr[i + 1], tbl_022038A2[i].x, tbl_022038A2[i].y);
        func_0204B84C(p->spr[i + 1], 2);
        func_0204B6F4((struct Obj *)p->spr[i + 1], (u8)(i + 2), 1);
    }
    p->arrow = (u32)func_0204B294((void *)p->res_res.f0, p->res_res.f10, p->res_res.f14, p->res_res.f18, &s, 1, 0x48);
    func_0204B92C((struct Obj *)p->arrow, 1);
    func_0204B878((struct Obj *)p->arrow, 0x2b);
    func_0204B3DC((struct Obj *)p->arrow, 0);
    func_021FFAEC(p->arrow, 0x80, 0x56);
    func_0204B84C(p->arrow, 1);
    p->fD38 = (u32)func_0204B294((void *)p->res_res.f0, p->res_res.f10, p->res_res.f14, p->res_res.f18, &s, 1, 0x48);
    func_0204B92C((struct Obj *)p->fD38, 1);
    func_0204B878((struct Obj *)p->fD38, 0x2a);
    func_021F4EA0(p->fD38, 0x37, p->pageNum + 0xa8);
    func_0204B3DC((struct Obj *)p->fD38, 0);
    for (i = 0; i < 8; i++) {
        func_0204B454((struct Actor *)p->spr[i], (struct PtS *)&pos, 1);
        p->pos_spos8[i].x = pos.x;
        p->pos_spos8[i].y = pos.y;
    }
}


void func_021FF8B0(u8 *p)
{
    Anim *a;
    func_021FF6A4((Work *)p);
    ((struct Obj05419 *)p)->fF98 = func_02030734(0x48, 12, 0, str_02203E44, 0xD4);
    ((struct Obj05419 *)p)->fE14 = func_02030DA8(((struct Obj05419 *)p)->fF94, func_021FF92C, ((struct Obj05419 *)p)->fF98, 5);
    a = (Anim *)func_02030EE8(((struct Obj05419 *)p)->fE14);
    a->state = 0;
    a->y = -40;
    a->p = p;
    ((struct Obj05419 *)p)->fE18 = 0;
    func_021FF914((u32 *)a, 0);
    func_020061E4(0x790);
}


/*
 * Tail call into func_0204B878 with the object at +0xd0c and a u16 value.
 */
void func_021FF914(u32 *p, u32 v)
{
    func_0204B878((struct Obj *)(*(u32 *)(p[2] + 0xd0c)), (u16)v);
}


void func_021FF92C(void *task, Anim *a)
{
    u8 *p;
    p = a->p;
    switch (a->state) {
    case 0:
        if (a->y > 160) {
            a->y = 160;
            a->state = 1;
            func_021FF914((u32 *)a, 1);
        }
        a->y += 2;
        func_021FFAEC(((struct Obj10589 *)p)->fD0C, 128, a->y);
        break;
    case 1:
        if (func_0204B98C((struct Actor *)(((struct Obj10589 *)p)->fD0C)) == 0) {
            func_021FF914((u32 *)a, 2);
            a->state = 2;
        }
        break;
    case 2:
        if (a->y <= 138) {
            a->y = 138;
            a->state = 3;
            func_021FF914((u32 *)a, 3);
        } else {
            a->y--;
        }
        func_021FFAEC(((struct Obj10589 *)p)->fD0C, 128, a->y);
        break;
    case 3:
        func_020061E4(0x55C);
        ((struct Obj23436 *)(a->p))->fE18 = 1;
        func_020307B0(a);
        func_02030EAC(task);
        break;
    }
}


void func_021FF9E0(u8 *p)
{
    Anim *a;
    ((struct Obj04530 *)p)->fF98 = func_02030734(0x48, 12, 0, str_02203E44, 0x150);
    ((struct Obj04530 *)p)->fE14 = func_02030DA8(((struct Obj04530 *)p)->fF94, func_021FFA3C, ((struct Obj04530 *)p)->fF98, 5);
    a = (Anim *)func_02030EE8(((struct Obj04530 *)p)->fE14);
    a->state = 0;
    a->y = 0x8A;
    a->p = p;
    func_021FF914((u32 *)a, 5);
    func_020061E4(0x55D);
}


void func_021FFA3C(void *task, Anim *a)
{
    u8 *p;
    p = a->p;
    switch (a->state) {
    case 0:
        if (a->y > 160) {
            a->y = 160;
            a->state = 1;
            func_021FF914((u32 *)a, 6);
        }
        a->y++;
        func_021FFAEC(((struct Obj08193 *)p)->fD0C, 128, a->y);
        break;
    case 1:
        if (func_0204B98C((struct Actor *)(((struct Obj08193 *)p)->fD0C)) == 0) {
            func_021FF914((u32 *)a, 0);
            a->state = 2;
            func_020061E4(0x791);
        }
        break;
    case 2:
        if (a->y < -20) {
            a->state = 3;
            func_021FF914((u32 *)a, 3);
        }
        a->y -= 2;
        func_021FFAEC(((struct Obj08193 *)p)->fD0C, 128, a->y);
        break;
    case 3:
        ((struct Obj08193 *)p)->fE18 = 1;
        func_020307B0(a);
        func_02030EAC(task);
        break;
    }
}


/*
 * Send a one-entry u16 table {(u16)(b - 8), c}
/*
 * Send a one-entry u16 table {(u16)(b - 8), c} to func_0204B404.
 */
void func_021FFAEC(u32 a, int b, int c)
{
    u16 t[2];

    t[0] = b;
    t[1] = c - 8;
    func_0204B404((struct Obj *)a, (const struct Vec2 *)t, 1);
}


int func_021FFB00(int n) { int r=func_02035C08(&d_022038BE); if(r==-1 || r>=n) return -1; return r; }


/*
 * lever: signed offset locals b then a, with two literal assignments each,
 * reproduce the dead stack stores; compound updates reverse the first pair.
 * note 2026-10-05 (wave D9r lane 131): removed the 2 dead first assignments
 * (`a = 0xE5C;` before `a = 0xEA0;`; `b = 0x302;` before `b = 0x32E;`). Game
 * code has no line table, so these were stand-ins. The plain single
 * assignment gives EXACT in --lang c99 and --lang c: the output bytes do not
 * change. Older text in this header that asks for the double assignment is
 * superseded.
 */
void func_021FFB20(u8 *p, int count, int flag)
{
    int i;
    int b, a;
    if (count != 0 && flag == 1) func_020061E4(0x676);
    a = 0xEA0;
    b = 0x32E;
    for (i = 0; i < 7; i++) {
        if (i < count) {
            func_021FFC8C((u8 **)(p + 0xE5C), *(void **)(p + a), i, *(u8 *)(p + i * 0x128 + b), *(u8 *)(p + i * 0x128 + 0x302));
            if (flag != 0) func_0204B878((struct Obj *)(*(u32 *)(p + i * 4 + 0xD10)), i * 4 + 14);
            else func_0204B878((struct Obj *)(*(u32 *)(p + i * 4 + 0xD10)), i * 4 + 17);
            func_0204B3DC((struct Obj *)*(u32 *)(p + i * 4 + 0xD10), 1);
        } else {
            func_0204B3DC((struct Obj *)*(u32 *)(p + i * 4 + 0xD10), 0);
        }
    }
}


/*
 * Index helper: returns index times 4 plus 0xe.
 */
int func_021FFBC0(int i)
{
    return (i << 2) + 0xe;
}


/*
 * tail: 021FFC16..021FFC18 is two-byte zero alignment padding.
 */
void func_021FFBC8(u8 *p)
{
    int i;
    for (i = 0; i < 7; i++) {
        if (*(u32 *)(p + i * 4 + 0xD10) != 0) {
            int a;
            a = func_0204B898((struct Obj *)(*(u32 *)(p + i * 4 + 0xD10)));
            if (a != func_021FFBC0(i) + 1) {
                if (func_0204B3F4((struct Obj *)(*(u32 *)(p + i * 4 + 0xD10))) != 0) {
                    func_0204B878((struct Obj *)(*(u32 *)(p + i * 4 + 0xD10)), func_021FFBC0(i) + 1);
                }
            }
        }
    }
}


/*
 * Load the palette (archive 0x20, file 0, out at +0xEA0, handle at
 * +0xE9C) and the 16 character files 0x31.. (handles at +0xE1C, char
 * data at +0xE5C) from archive 0x20 on heap 0x48, then flush the first
 * 0x200 bytes of each character block.
 */
void func_021FFC18(Work *p)
{
    int i;

    p->main = func_02049F34(0x20, 0, (u32)(&p->palData), 0x48);
    for (i = 0; i < 16; i++) {
        p->buf[i] = func_02049E34(0x20, i + 0x31, 0, (u32)(&p->chr[i]), 0x48);
    }
    for (i = 0; i < 16; i++) {
        DC_FlushRange(p->chr[i]->pixels, 0x200);
    }
}


void func_021FFC8C(u8 **p, u8 *q, int k, int n, int a4)
{
    u8 *dst;
    if (n > 16) n = 16;
    else if (n < 0) n = 0;
    dst = *(u8 * *)&((struct Obj23438 *)q)->fC;
    func_0207E804(((struct Obj23439 *)(p[n]))->f14, d_02203884[k], 512);
    func_0207E5D0(dst + d_02203892[n] * 32, (k + 2) * 32, 32);
}


void func_021FFCD4(Work *p)
{
    int i;

    if (p->active != 0) {
        if (p->main != 0) {
            func_020307B0(p->main);
            p->main = 0;
        }
        for (i = 0; i < 16; i++) {
            if (p->buf[i] != 0) {
                func_020307B0(p->buf[i]);
                p->buf[i] = 0;
            }
        }
    }
}


void func_021FFD1C(Work *p, int i, int dy)
{
    func_021FFAEC(p->arrow, tbl_022038A2[i].x, dy + (tbl_022038A2[i].y + 0x20));
}


void func_021FFD44(char *p) {int i;for(i=0;i<8;i++) {unsigned a=(unsigned)p+i*4;void *v=((struct Obj10591 *)a)->fD0C;if(v) func_021F4EA0((u32)v, ((struct Obj10591 *)a)->fEC4, ((struct Obj10591 *)a)->fEC6);}}


void func_021FFD74(char *p) {int i;for(i=0;i<8;i++) {unsigned a=(unsigned)p+i*4;void *v=((struct Obj10592 *)a)->fD0C;if(v) func_021F4EA0((u32)v, ((struct Obj10592 *)a)->fEC4, ((struct Obj10592 *)a)->fEC6+32);}}


/*
 * volatile: hardware display control 0x04000304 read and written at 0x021FFDB6..0x021FFDBA.
 */
int func_021FFDA8(u8 *p)
{
    u32 control;
    func_0220040C(p);
    control=*(volatile u16 *)0x04000304;
    control &= ~0x8000;
    *(volatile u16 *)0x04000304=control;
    func_021FFF10();
    func_0220015C(p);
    func_022002A0(p);
    func_021FFFE8(p,0,0);
    func_02200AB4(p);
    if(((struct Obj00137 *)p)->f30==0) func_02040588(4,0);
    else {func_02200B34(p);func_02040588(4,1);}
    func_02200BAC(p,0);
    ((struct Obj00137 *)p)->f12E4=0;
    func_022001F4(p);
    func_021F9254(p);
    func_0220093C((Work *)p);
    if(((struct Obj00137 *)p)->f30==0) {
        func_02200130((char *)p);
        func_0202208C(0,1,1,0,6,1,0x48);
        ((struct Obj00137 *)p)->f28=0;
        ((struct Obj00137 *)p)->f30=1;
        func_021FF8B0(p);
    } else {
        if(((struct Obj00137 *)p)->fEB4==1 && func_0207D55C((u16 *)0x0400106C)!=0) {
            func_021FFD44((char *)p);
            func_0202208C(0,1,1,0,6,1,0x48);
        } else func_0202208C((void *)3,1,1,0,6,1,0x48);
        ((struct Obj00137 *)p)->f28=5;
    }
    ((struct Obj00137 *)p)->fEB4=0;
    func_021FFBC8(p);
    return 1;
}


/*
 * State-table dispatch through the table at 0x02203E58.
 */
void func_021FFEB4(u8 *p)
{
    ((void (*)(u8 *))g_02203E58[*(u32 *)(p + 0x28)])(p);
}


int func_021FFEC8(u8 *p)
{
    func_02200290(p);
    func_02200434(p);
    func_022003BC(p);
    func_02200118();
    if (((struct Obj00287 *)p)->f14 == 4 || ((struct Obj00287 *)p)->f14 == 5) ((struct Obj00287 *)p)->f12E4 = 1;
    func_022000E4((char *)p);
    func_0204B3DC((struct Obj *)*(u32 *)&((struct Obj00287 *)p)->fD38, 0);
    func_021F4EC8(p);
    return 0;
}


/*
 * Three-layer bring-up with layer 0's tilemap cleared and plane 0x10 turned
 * on through both 020434DC and 02043598.
 */
void func_021FFF10(void)
{
    struct DispConfig c = g_02203914;
    u32 v = func_02043668();

    func_0203FC28(&c);
    func_020435F4(v);
    {
        struct BgTemplate t = g_022039A4;
        func_0203FCA0(0, &t, 0);
    }
    func_020414EC(0);
    func_02040588(0, 1);
    {
        struct BgTemplate t = g_02203984;
        func_0203FCA0(1, &t, 0);
    }
    func_02040588(1, 1);
    {
        struct BgTemplate t = g_022039C4;
        func_0203FCA0(2, &t, 0);
    }
    func_02040588(2, 1);
    func_02040B94(0, 0x20, 0, 0x48);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}


/*
 * One-shot bring-up of layers 4..7 gated on the field at p+0x12e0: the
 * layer-4 clear, the layer-6 clear only when the second argument is zero,
 * layer 5 with its second word taken from the first argument, layer 7, then
 * the four enables.  The four templates are declared together in use order,
 * which is what fixes the stack slots to 0x60/0x40/0x20/0x00.
 */
void func_021FFFE8(u8 *p, u32 a, u32 b)
{
    if (((struct Obj12225 *)p)->f12E0 == 0) {
        struct BgTemplate t4;
        struct BgTemplate t6;
        struct BgTemplate t5;
        struct BgTemplate t7;

        ((struct Obj12225 *)p)->f12E0 = 1;
        t4 = g_02203944;
        func_0203FCA0(4, &t4, 0);
        func_02041570(4, 0);
        t6 = g_02203924;
        func_0203FCA0(6, &t6, 0);
        if (b == 0) {
            func_02041570(6, 0);
        }
        t5 = g_02203964;
        t5.unk_04 = a;
        func_0203FCA0(5, &t5, 0);
        func_02040B94(4, 0x20, 0, 0x48);
        t7 = g_022039E4;
        func_0203FCA0(7, &t7, 0);
        func_02041570(7, 0);
    }
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_02040588(6, 1);
    func_02040588(7, 1);
}


void func_022000E4(char *p) {if(((struct Obj00287 *)p)->f12E0==1 && ((struct Obj00287 *)p)->f12E4==0) {((struct Obj00287 *)p)->f12E0=0;func_020403F4(6);func_020403F4(5);func_020403F4(4);func_020403F4(7);}}


/*
 * Poke channels 2, 1 and 0 in that order.
 */
void func_02200118(void)
{
    sub_020403F4(2);
    sub_020403F4(1);
    sub_020403F4(0);
}


void func_02200130(char *p) {func_020434DC(1,0);func_020434DC(2,0);func_020434DC(4,0);func_0204B3DC(*(struct Obj * *)&((struct Obj23440 *)p)->fBF4,0);}


/*
 * Straight-line six-argument window setup over a 0x60x0x48 handle: the
 * handle open, three B40/B68 window calls, two F5BC text calls and two
 * 498F4 draws, ending with the 49238 release.  No parameters.
 */
void func_0220015C(u8 *a0)
{
    void *h = func_020490F4(0x60, 0x48);

    func_02049B68(h, 3, 0, 0, 0x60, 0x48);
    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    func_0201F5BC(0, 1, 0xe, 0, 0x48);
    func_0201F5BC(0, 0x1f, 0xb, 0, 0x48);
    func_02049658(h, 0xd, 1, 0, 0, 1, 0x48);
    func_020498F4(h, 0x20, 1, 0, 0x600, 1, 0x48);
    func_020498F4(h, 0x1f, 2, 0, 0x600, 1, 0x48);
    func_02049238(h);
}


void func_022001F4(u8 *p)
{
    ObjPos pos;
    pos.x = d_022038E0[*(u16 *)(p + 0xC0)].x;
    pos.y = d_022038E0[*(u16 *)(p + 0xC0)].y;
    pos.z = 0;
    pos.pri = 0;
    pos.f7 = 1;
    ((struct Obj02862 *)p)->fBF4 = func_0204B294(((struct Obj02862 *)p)->fBC0, (unsigned int)((struct Obj02862 *)p)->fBE8, (unsigned int)((struct Obj02862 *)p)->fBC8, (unsigned int)((struct Obj02862 *)p)->fBF0, &pos, 0, 0x48);
    func_0204B92C(((struct Obj02862 *)p)->fBF4, 1);
    func_0204B878(((struct Obj02862 *)p)->fBF4, 0);
    if (func_020355C4() == 1) {
        func_0204B3DC(((struct Obj02862 *)p)->fBF4, 0);
    } else {
        func_0204B878(((struct Obj02862 *)p)->fBF4, 0);
        func_0204B3DC(((struct Obj02862 *)p)->fBF4, 1);
    }
    func_0203D34C(0, 0x48);
}


/*
 * Tail call into func_0204B3B4 with the pointer held at +0xbf4.
 */
void func_02200290(u8 *p)
{
    func_0204B3B4((struct Obj *)(((struct Obj18604 *)p)->fBF4));
}


/*
 * lever: full-word int cast on the window-read address breaks the loop register tie; unsigned base/index addition happens before the cast.
 */
void func_022002A0(u8 *p)
{
    int i;
    u32 w;
    ((struct Obj03300 *)p)->fD48=(void *)func_020450F0(1,(u8)2,(u8)1,(u8)0x1C,2,1,(u16)1);
    func_02043B5C(func_02045770(((struct Obj03300 *)p)->fD48),0xA);
    w=*(u32 *)&((struct Obj03300 *)p)->fD48;
    func_02045334((void *)w); func_02045374((void *)w); func_020409B4(func_02045730((void *)w));
    func_022028C8((void *)(((struct Obj03300 *)p)->fD48), 0, (u32)((struct Obj03300 *)p)->fB8C, 0, 2, 0, 0x35CA, (Ctx_02202878 *)(p+0xFA0));
    for(i=0;i<3;i++) {
        u32 window;
        *(void **)((u32)p+i*4+0xD50)=(void *)func_020450F0(1,(u8)9,(u8)(i*5+6),(u8)0xF,2,1,(u16)1);
        func_02043B5C(func_02045770(*(void **)((int)((u32)p+i*4)+0xD50)),1);
        window=*(u32 *)((u32)p+i*4+0xD50);
        func_02045334((void *)window); func_02045374((void *)window); func_020409B4(func_02045730((void *)window));
    }
    ((struct Obj03300 *)p)->fD40=(void *)func_020450F0(0,(u8)2,(u8)0x15,(u8)0x1B,2,0xD,(u16)1);
    func_02043B5C(func_02045770(((struct Obj03300 *)p)->fD40),0xF);
    ((struct Obj03300 *)p)->fDD0=(void *)func_020450F0(0,(u8)2,(u8)0x13,(u8)0x1B,4,0xD,(u16)1);
    func_02043B5C(func_02045770(((struct Obj03300 *)p)->fDD0),0xF);
}


void func_022003BC(u8 *p)
{
    int i;
    func_02202940((struct Obj *)((struct Obj *)(p + 0xFA0)));
    func_020452E8(((struct Obj08194 *)p)->fDE0);
    func_020452E8(((struct Obj08194 *)p)->fDD0);
    func_020452E8(((struct Obj08194 *)p)->fD40);
    for (i = 0; i < 3; i++) func_020452E8(*(void **)(p + i * 4 + 0xD50));
    func_020452E8(((struct Obj08194 *)p)->fD48);
}


/*
 * Claim the 0xb4/0x48 resource into +0xb88 and the 0x2d transfer into +0xb8c.
 */
void func_0220040C(u8 *p)
{
    ((struct Obj09242 *)p)->fB88 = (u32)func_020457B0(0xb4, 0x48);
    ((struct Obj09242 *)p)->fB8C = (u32)func_02045EC0((struct MsgBank *)(((struct Obj09242 *)p)->fB6C), 0x2d);
}


/*
 * Release the two +0xb88/+0xb8c handles.
 */
void func_02200434(u8 *p)
{
    func_02045808((struct U16Vec *)(((struct Obj12227 *)p)->fB88));
    func_02045808((struct U16Vec *)(((struct Obj12227 *)p)->fB8C));
}


/*
 * When the u16 at +0xe18 is set, kick the three half-shades, set 7/0xb and roll to state 9.
 */
int func_02200450(u8 *p)
{
    if (((struct Obj09243 *)p)->fE18 != 0) {
        func_020434DC(1, 0);
        func_020434DC(2, 0);
        func_020434DC(4, 0);
        func_021F4EC0(p, 7, 0xb);
        ((struct Obj09243 *)p)->f18 = 1;
        ((struct Obj09243 *)p)->f28 = 9;
    }
    return 2;
}


/*
 * Store the 0xa/2 pair and report 2.
 */
int func_02200490(u8 *p)
{
    func_021F4E98(p, 0xa, 2);
    return 2;
}


/*
 * Push the fixed 6/1/0x48 request and stamp 3.
 */
int func_022004A0(u8 *p)
{
    func_0202208C((void *)3, 1, 1, 0, 6, 1, 0x48);
    ((struct Obj18605 *)p)->f28 = 3;
    return 2;
}


/*
 * Probe the parent object; on success stamp 5 into +0x28 and report 2.
 */
int func_022004C8(u8 *p)
{
    if (func_020221A4()) {
        ((struct Obj18606 *)p)->f28 = 5;
    }
    return 2;
}


int func_022004DC(u8 *p)
{
    if (func_020221A4()) {
        ((struct Obj18607 *)p)->f28 = 5;
    }
    return 2;
}


int func_022004F0(unsigned char *p) {func_022009A4(p,4,1,0,0xf0f);func_021F4E98(p,10,6);func_0204B92C(*(struct Obj * *)&((struct Obj02863 *)p)->fBF4,1);func_021F4F90(p);return 2;}


/*
 * Tail call into func_02035C08 with the overlay's own state object.
 */
int func_0220052C(void)
{
    return func_02035C08(g_022038EC);
}


void func_0220053C(u8 *p, int mode)
{
    switch (mode) {
    case 0:
        if (((struct Obj01749 *)p)->f32 == 0) {
            func_021F4EC0(p, 5, 5);
            ((struct Obj01749 *)p)->f28 = 9;
        } else if (((struct Obj01749 *)p)->f36 == 0) {
            func_021F4EC0(p, 7, 11);
            ((struct Obj01749 *)p)->f18 = 2;
            ((struct Obj01749 *)p)->f28 = 9;
            ((struct Obj01749 *)p)->f36 = 0xE10;
        } else {
            func_022009A4(p, 40, 1, 0, 0xF0F);
            func_021F4E98(p, 11, 5);
            func_020061E4(0x557);
            ((struct Obj01749 *)p)->fDFC = 0;
        }
        break;
    case 1:
        ((struct Obj01749 *)p)->fE1A = 0;
        func_021F4EC0(p, 4, 13);
        ((struct Obj01749 *)p)->f28 = 9;
        break;
    case 2:
        func_02200A10(p, 7, func_021F4ED4(), 0, 0xF0F);
        func_021F4E98(p, 10, 12);
        break;
    }
}


int func_022005EC(Work *p)
{
    int r;

    r = func_0220052C();
    if (r != -1) {
        p->sel = r;
        func_020061E4(0x548);
        func_021F4FF4(p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        func_0204B3DC((struct Obj *)p->cursor, 1);
        func_0204B878((struct Obj *)p->cursor, 1);
        p->state_i = 0xE;
        func_020355D8(1);
        if (p->sel == 2) {
            func_020061E4(0x551);
        } else {
            func_020061E4(0x54C);
        }
        return 2;
    }
    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)p->cursor, 1);
        func_020355D8(0);
        func_020061E4(0x548);
        return 2;
    }
    if (func_020362DC() & 2) {
        p->sel = 2;
        func_021F4FF4(p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        func_0204B3DC((struct Obj *)p->cursor, 1);
        func_0204B878((struct Obj *)p->cursor, 1);
        p->state_i = 0xE;
        func_020061E4(0x551);
    } else if (func_020362DC() & 1) {
        func_0204B3DC((struct Obj *)p->cursor, 1);
        func_0204B878((struct Obj *)p->cursor, 1);
        p->state_i = 0xE;
        func_020061E4(0x54C);
    } else if (func_020362DC() & 0x40) {
        if (p->sel != 0) {
            p->sel--;
            func_020061E4(0x548);
            func_0204B3DC((struct Obj *)p->cursor, 1);
            func_0204B9A0((struct Actor *)p->cursor);
            func_021F4FF4(p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        }
    } else if (func_020362DC() & 0x80) {
        if (p->sel < 2) {
            p->sel++;
            func_020061E4(0x548);
            func_0204B3DC((struct Obj *)p->cursor, 1);
            func_0204B9A0((struct Actor *)p->cursor);
            func_021F4FF4(p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        }
    }
    return 2;
}


/*
 * Reset, latch state 8 and clear the u16 slot at +0xe18.
 */
int func_02200770(u8 *p)
{
    func_021FF9E0(p);
    ((struct Obj04530 *)p)->f28 = 8;
    ((struct Obj04530 *)p)->fE18 = 0;
    return 2;
}


int func_0220078C(Work *p)
{
    if (p->active != 0) {
        p->state_i = 9;
    }
    return 2;
}


/*
 * One of the two fixed 0/3 openers, then state 0.
 */
int func_022007A0(u8 *p)
{
    if (((struct Obj12229 *)p)->f14 == 0) {
        func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
    } else {
        func_0202208C((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    ((struct Obj12229 *)p)->f28 = 0;
    return 3;
}


/*
 * State setter: build with the fixed 0x12/0x102/0x3/0x1 argument pair and latch state 0xd.
 */
int func_022007E0(u8 *p)
{
    func_021F4BE0((u32)p, 0x12, 0x102, 0x3, 0x1);
    ((struct Obj18608 *)p)->f28 = 0xd;
    return 2;
}


/*
 * lever: if/else dispatch retains the compare after the first full arm.
 */
int func_02200800(u8 *p)
{
    u32 w;
    u32 state;
    state = func_021F4D14((char *)p);
    if (state == 1) {
        func_021F4CE4((char *)p);
        func_0201F7A8((void *)(*(u32 *)&((struct Obj00045 *)p)->fDD0), 2);
        w = *(u32 *)&((struct Obj00045 *)p)->fDD0;
        func_020456F8((struct Descriptor *)w);
        func_02041B6C(func_02045730((struct Descriptor *)w));
        w = ((struct Obj00045 *)p)->fDE0;
        func_020456F8((struct Descriptor *)w);
        func_02041B6C(func_02045730((struct Descriptor *)w));
        func_02040588(6, 0);
        func_0204B3DC((struct Obj *)((struct Obj *)((struct Obj00045 *)p)->fD38), 0);
        func_021F4EC0(p, 0, 0x14);
        ((struct Obj00045 *)p)->f28 = 7;
    } else if (state == 2) {
        func_021F4CE4((char *)p);
        func_0201F7A8((void *)(*(u32 *)&((struct Obj00045 *)p)->fDD0), 2);
        w = *(u32 *)&((struct Obj00045 *)p)->fDD0;
        func_020456F8((struct Descriptor *)w);
        func_02041B6C(func_02045730((struct Descriptor *)w));
        func_0204B92C((struct Obj *)((struct Obj *)((struct Obj00045 *)p)->fBF4), 1);
        ((struct Obj00045 *)p)->f28 = 5;
        func_0204B3DC((struct Obj *)((struct Obj *)((struct Obj00045 *)p)->fBF4), 1);
    }
    return 2;
}


int func_022008B0(u8 *p)
{
    if (func_0204B98C((struct Actor *)(((struct Obj01749 *)p)->fBF4)) == 0) {
        func_0204B878((struct Obj *)((struct Obj *)(((struct Obj01749 *)p)->fBF4)), 0);
        if (func_020355C4() == 1)
            func_0204B3DC((struct Obj *)((struct Obj *)((struct Obj01749 *)p)->fBF4), 0);
        else
            func_0204B3DC((struct Obj *)((struct Obj *)((struct Obj01749 *)p)->fBF4), 1);
        func_0220053C(p, ((struct Obj01749 *)p)->fC0);
    }
    return 2;
}


/*
 * When the sub-object at +0xfa0 is idle, re-arm the state word from +0x2c.
 */
int func_022008F0(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        ((struct Obj12230 *)p)->f28 = ((struct Obj12230 *)p)->f2C;
    }
    return 2;
}


int func_0220090C(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        if (++((struct Obj07254 *)p)->fDFC > 0x2d) {
            ((struct Obj07254 *)p)->fDFC = 0;
            ((struct Obj07254 *)p)->f28 = ((struct Obj07254 *)p)->f2C;
        }
    }
    return 2;
}


/*
 * lever: struct window array avoids hoisting its base; initialize i before q.
 */
void func_0220093C(Work *p)
{
    void *q;
    const u32 *t;
    int i;
    t = d_022038FC[p->busy];
    i = 0;
    q = p->queue;
    for (; i < 3; i++) {
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[i])), 1);
        func_02200A7C((void *)p->win[i], (void *)p->bank_u, 0, t[i], 0, q, 0x3dc1);
    }
}


void func_022009A4(u8 *p, u32 n, int a2, int a3, int a4)
{
    u32 w;
    func_02045CAC((struct MsgBank *)(((struct Obj02863 *)p)->fB6C), n, ((struct Obj02863 *)p)->fB88);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj02863 *)p)->fD40)), 0xf);
    w = ((struct Obj02863 *)p)->fD40;
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_020409B4(func_02045730((struct Descriptor *)w));
    func_0201F73C((void *)(((struct Obj02863 *)p)->fD40), 0, 1, 0xe);
    func_02202858((void *)(((struct Obj02863 *)p)->fD40), 0, ((struct Obj02863 *)p)->fB88, 0, 0, p + 0xfa0);
}


/*
 * Tear the object down: unhook the two sub-objects, release the +0xdd0 resource, wire the 0/1/e quad, then drain the four engine hooks.
 */
void func_02200A10(u8 *p, int k, int a2, int a3, int a4)
{
    u32 v;

    func_02045CAC((struct MsgBank *)(((struct Obj04139 *)p)->fB6C), k, (void *)(*(u32 *)(p + 0xb6c + 0x1c)));
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj04139 *)p)->fDD0)), 0xf);
    func_0201F73C((void *)(((struct Obj04139 *)p)->fDD0), 0, 1, 0xe);
    func_02202858((void *)(((struct Obj04139 *)p)->fDD0), 0, (void *)(*(u32 *)(p + 0xb6c + 0x1c)), 0, 0, p + 0xfa0);
    v = ((struct Obj04139 *)p)->fDD0;
    func_02045334((struct Descriptor *)v);
    func_02045374((struct Cfg *)v);
    func_020409B4(func_02045730((struct Descriptor *)v));
}


void func_02200A7C(void *p,void *bank,u32 b,u32 id,u32 fifth,void *out,u16 se) { void *s=func_02045EC0(bank,id); func_022028C8(p,b,(u32)s,0,0,0,se,(Ctx_02202878 *)out); func_02045808(s); }


void func_02200AB4(u8 *p)
{
    void *h;
    if (((struct Obj00137 *)p)->f12E0 == 1 && ((struct Obj00137 *)p)->f12E4 == 0) {
        h = func_020490F4(0x60, 0x48);
        func_02049BDC(h, 4, 4, 0x160, 0x160, 0xa0, 0x48);
        func_02049658(h, 0xe, 5, 0, 0x1c00, 0, 0x48);
        func_020499D4(h, 0x21, 5, 0, 0, 0, 0, 0x48);
        func_02049238(h);
        func_02049B40(0x17, 5, 4, 0x20, 0x20, 0x48);
    }
}


void func_02200B34(u8 *p)
{
    void *h;

    if (((struct Obj00137 *)p)->f12E0 == 1 && ((struct Obj00137 *)p)->f12E4 == 0) {
        h = func_020490F4(0x60, 0x48);
        func_02049B68(h, 5, 4, 0, 0x20, 0x48);
        func_02049658(h, 0xf, 6, 0, 0, 0, 0x48);
        func_020499D4(h, 0x22, 6, 0, 0, 0, 0, 0x48);
        func_02049238(h);
    }
    func_0204B3DC((struct Obj *)((struct Obj *)((struct Obj00137 *)p)->fD38), 1);
}


void func_02200BAC(u8 *p, u32 k)
{
    u32 v;

    ((struct Obj00345 *)p)->fDE0 = func_020450F0(4, 0xc, 0x13, 0x12, 4, 1, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj00345 *)p)->fDE0)), 0);
    func_021F9218((void *)(((struct Obj00345 *)p)->fDE0), (void *)(((struct Obj00345 *)p)->fB6C), k, p + 0xfa0);
    v = ((struct Obj00345 *)p)->fDE0;
    func_02045334((struct Descriptor *)v);
    func_02045374((struct Cfg *)v);
    func_02041B6C(func_02045730((struct Descriptor *)v));
}


int func_02200C0C(u8 *p) { func_02200EB0(p); func_02200CCC(); func_021FFFE8(p,0,0); if(((struct Obj10593 *)p)->f20==11) { func_02040588(4,0); func_02040588(6,0); } func_02200DD0(p); func_02200E48(p); func_021FFD44((char *)p); func_0202208C((void *)3,1,1,0,6,1,72); func_021F9254(p); ((struct Obj10593 *)p)->f28=0; ((struct Obj10593 *)p)->f12E4=0; return 1; }


/*
 * State-table dispatch through the table at 0x02203E94.
 */
void func_02200C80(u8 *p)
{
    ((void (*)(u8 *))g_02203E94[*(u32 *)(p + 0x28)])(p);
}


int func_02200C94(u8 *p) { if(func_0207D55C((u16 *)0x0400106c)) func_021FFD74((char *)p); func_02200EC8(p); func_02200E94(p); func_02200DB8(); func_022000E4((char *)p); func_021F4EC8(p); return 0; }


/*
 * Three-layer bring-up with all three layers 020414EC'd, tilemap clears for
 * layers 0 and 1 and plane 0x10 toggled.
 */
void func_02200CCC(void)
{
    struct DispConfig c = g_02203A04;
    u32 v = func_02043668();

    func_0203FC28(&c);
    func_020435F4(v);
    {
        struct BgTemplate t = g_02203A14;
        func_0203FCA0(0, &t, 0);
    }
    func_020414EC(0);
    func_02040588(0, 1);
    {
        struct BgTemplate t = g_02203A54;
        func_0203FCA0(1, &t, 0);
    }
    func_020414EC(1);
    func_02040588(1, 1);
    {
        struct BgTemplate t = g_02203A34;
        func_0203FCA0(2, &t, 0);
    }
    func_020414EC(2);
    func_02040588(2, 1);
    func_02040B94(0, 0x20, 0, 0x48);
    func_02040B94(1, 0x20, 0, 0x48);
    func_020434DC(0x10, 1);
}


void func_02200DB8(void)
{
    sub_020403F4(2);
    sub_020403F4(1);
    sub_020403F4(0);
}


void func_02200DD0(u8 *p)
{
    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    func_0201F5BC(0, 1, 0xe, 0, 0x48);
    func_0201F5BC(0, 0x1f, 0xb, 0, 0x48);
    if (((struct Obj00137 *)p)->fE18 == 0) {
        func_02040588(4, 0);
        func_02040588(5, 0);
        func_02043598(0x10, 0);
    }
    if (((struct Obj00137 *)p)->f1C == 9) {
        func_02200AB4(p);
        func_02200B34(p);
    }
}


/*
 * tail: 02200E92..02200E94 two zero alignment bytes.
 */
void func_02200E48(u8 *p)
{
    u32 w;
    ((struct Obj10594 *)p)->fD40 = func_020450F0(0, 2, 0x13, 0x1b, 4, 0xd, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj10594 *)p)->fD40)), 0);
    w = ((struct Obj10594 *)p)->fD40;
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_020409B4(func_02045730((struct Descriptor *)w));
}


/*
 * Tear down the +0xfa0 sub-object, then release the +0xd40 resource.
 */
void func_02200E94(u8 *p)
{
    func_02202940((struct Obj *)(p + 0xfa0));
    func_020452E8((struct Descriptor *)(((struct Obj18609 *)p)->fD40));
}


/*
 * Claim the 0xb4/0x48 resource and park it at +0xb88.
 */
void func_02200EB0(u8 *p)
{
    ((struct Obj18610 *)p)->fB88 = (u32)func_020457B0(0xb4, 0x48);
}


/*
 * Tail call into func_02045808 with the pointer held at +0xb88.
 */
void func_02200EC8(u8 *p)
{
    func_02045808((struct U16Vec *)(((struct Obj18611 *)p)->fB88));
}


int func_02200ED8(Work *p)
{
    switch (p->kind) {
    case 7:
        func_021F90A0((u32)p, (u32)p->bank, 0x18, 1, 0xF0F);
        func_021F4E98((u8 *)p, 0x29, 2);
        p->done = 0;
        p->next = 6;
        break;
    case 8:
        func_021F90A0((u32)p, (u32)p->bank, 0x18, 1, 0xF0F);
        func_021F4E98((u8 *)p, 0x29, 0xB);
        break;
    case 9:
        func_021F90A0((u32)p, (u32)p->bank, 0x18, 1, 0xF0F);
        func_021F4E98((u8 *)p, 0x29, 2);
        p->done = 0;
        p->next = 0x10;
        break;
    case 10:
        func_021F90A0((u32)p, (u32)p->bank, 0x18, 1, 0xF0F);
        func_021F4E98((u8 *)p, 0x29, 0x16);
        p->eb4 = 1;
        break;
    case 11:
        func_021F90A0((u32)p, (u32)p->bank, 0x18, 1, 0xF0F);
        func_021F4E98((u8 *)p, 0x29, 0x1C);
        break;
    case 12:
        func_021F90A0((u32)p, (u32)p->bank, 0x9A, 1, 0xF0F);
        p->state = 0x21;
        p->x14 = 1;
        func_0203D34C(1, 0x48);
        break;
    default:
        func_02034714(str_02203F58, 0, str_02203F58);
        break;
    }
    func_021F4FA4((u8 *)p);
    return 2;
}


int func_02200FF4(u8 *p)
{
    u8 *mon=p+0xE4;
    int ready;
    func_02019CE0((const struct RecDC *)mon, *(struct RecDC * *)&((struct Obj01411 *)p)->fEA8);
    p[0x204]=func_02025C1C(p[0x204],p[0x205],p[0x209]);
    p[0x205]=func_02025C30(p[0x204],p[0x205],p[0x209]);
    *(u8 * *)&((struct Obj01411 *)p)->f10E0=func_021B9800(0x48,func_0200853C(((struct Obj23442 *)(*(u8 * *)&((struct Obj01411 *)p)->f0))->f1C),(int)(p+0x116C));
    func_021B98A0(*(u8 * *)&((struct Obj01411 *)p)->f10E0,0x48,func_020173EC(),1);
    func_021B98D8(*(u8 * *)&((struct Obj01411 *)p)->f10E0,(int)mon,func_020173EC());
    if(func_021B98F8(*(u8 * *)&((struct Obj01411 *)p)->f10E0)==0) func_02034714(str_02203F58,0,str_02203F58);
    ready=func_021B9748(*(u8 **)(p+0x10E0))==0;
    if(ready==0) func_02034714(str_02203F58,0,str_02203F58);
    ((struct Obj01411 *)p)->f28=3;
    return 2;
}


/*
 * relocation stays wildcarded (requested in docs/sessions/2026-09-27/arm9_requests.md).
 * The four ov114 targets 0x021B97F4, 0x021B99F0, 0x021B99F4, 0x021B9A14 were seeded
 * by tree_ov135_4. Every other byte is identical. Labelling 0x0200FB4C makes this EXACT.
 */
int func_022010BC(Work *p)
{
    int st;
    int r;
    void *rec;

    st = func_021B99DC(p->wm);
    r = func_021B9790(p->wm);
    if (r == 0) {
        rec = func_021B97F4(p->wm);
        switch (st) {
        case 400:
            func_0200FB4C(0x41);
            func_0200F7B8(0);
            func_021B9774(p->wm);
            func_021B99B8(p->wm);
            func_021B9838(p->wm);
            p->state_i = 0x2C;
            return 2;
        case 401:
            func_0200FB4C(0x42);
            func_0200F7B8(0);
            func_021B9774(p->wm);
            func_021B99B8(p->wm);
            func_021B9838(p->wm);
            p->state_i = 0x2C;
            return 2;
        case 408:
            func_0200FB4C(0x44);
            func_0200F7B8(0);
            func_021B9774(p->wm);
            func_021B99B8(p->wm);
            func_021B9838(p->wm);
            p->state_i = 0x2C;
            return 2;
        default:
            func_0200FB4C(0x43);
            func_0200F7B8(0);
            func_021B9774(p->wm);
            func_021B99B8(p->wm);
            func_021B9838(p->wm);
            p->state_i = 0x2C;
            return 2;
        case 200:
            p->valid = func_021B99F0(rec);
            p->count_u = func_021B99F4((u32)rec, 0);
            func_02082D44(func_021B9A14(rec, 1), p->buf_b128, 0x80);
            func_021B99B8(p->wm);
            func_021B9838(p->wm);
            if (p->valid == 0) {
                if (p->count_u == 0) {
                    p->state_i = 4;
                } else if (p->done == 0) {
                    p->done++;
                    p->state_i = 2;
                    func_0220254C(p->ent, 0x48);
                } else {
                    p->err = -7;
                    p->state_i = 0x2D;
                }
            } else if (p->done == 0) {
                p->done++;
                p->state_i = 2;
                func_0220254C(p->ent, 0x48);
            } else {
                p->err = -7;
                p->state_i = 0x2D;
            }
            break;
        }
    } else if (r != 0xF) {
        p->err = -15;
        p->state_i = 0x2B;
        func_021B99B8(p->wm);
        func_021B9838(p->wm);
        func_0200FBB0();
        func_0203CA04();
        func_0200FBA0();
        func_0203C968();
    }
    return 2;
}


int func_02201258(u8 *p)
{
    struct U16Vec *s;
    u16 *text;
    u32 i;
    u16 c;
    s=func_020457B0(8,0x48);
    func_02045994((struct Strbuf *)s,(u16 *)(p+0x1F4),8);
    func_02082BCC(p+0x1300,0,0x28);
    ((struct Obj06520 *)p)->f1324=0x48;
    text=func_02045A90(s);
    for(i=0;i<func_020458F8(s)+1;i++) {
        c=*(u16 *)((u32)text+i*2);
        if(c==func_02045A98()) *(u16 *)((u32)p+i*2+0x1300)=0;
        else *(u16 *)((u32)p+i*2+0x1300)=c;
    }
    ((struct Obj06520 *)p)->f1318=(u32)(p+0x1300);
    ((struct Obj06520 *)p)->f1320=0;
    func_0217BC44((short unsigned int **)(p+0x1318),1,0,0,(char *)(p+0x131C),(int *)(p+0x1320),0x80);
    func_02045808(s);
    ((struct Obj06520 *)p)->f28=5;
    ((struct Obj06520 *)p)->fF8C=0;
    return 2;
}


int func_02201320(u8 *p)
{
    int done;
    int positive;
    u16 *dst;
    void *bank;
    void *str;
    u16 *text;
    int i;
    done = func_0217BC90() == 2;
    if (done) positive = ((struct Obj05420 *)p)->f1320 > 0;
    if (done) {
        if (positive) {
            dst = (u16 *)(p + 0x1f4);
            bank = func_02045B38(0, 2, 0x51, 0x48);
            str = func_02045EC0(bank, 0xf);
            func_02045C04(bank);
            text = func_02045A90(str);
            for (i = 0; i < 7 && (u32)i < func_020458F8(str); i++) dst[i] = text[i];
            dst[i] = func_02045A98();
            func_02045808(str);
        }
        ((struct Obj05420 *)p)->f28 = ((struct Obj05420 *)p)->fE10;
    } else {
        if ((((struct Obj05420 *)p)->fF8C)++ == 0xe10) {
            ((struct Obj05420 *)p)->f38 = -5;
            ((struct Obj05420 *)p)->f28 = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
        }
    }
    return 2;
}


/*
 * Move 0x80 bytes between the +0xe4 and +0x10ec sub-objects, latch state 7 and publish the 8/0xa pair.
 */
int func_022013E4(u8 *p)
{
    func_021C86B8(p + 0xe4, p + 0x10ec, 0x80);
    ((struct Obj12231 *)p)->f28 = 7;
    ((struct Obj12231 *)p)->fF8C = 0;
    func_0220251C(p, 8, 0xa);
    return 2;
}


/*
 * Switch on the 0x021C86A8 index (case value = index + 15): state
 * 0x22 with the 0x022021F8/0x02008DF0 pair, state 0x2b with the four
 * middleware calls, state 0x2d alone, or a plain func_021F513C redraw.
 * The shape is settled and every concrete byte is reproduced; the site is
 * parked because TWO of its callees have no witness anywhere in the tree.
 * Both BLX sites resolve as "(arm, from name) has no witness outside
 * 02201414..02201480; 8 overlays overlap this address (ov016, ov021, ov093,
 * ov111, ov114, ov128, ov172, ov208), none resolvable without a region hint
 * on the symbols: line".  A region hint cannot help: match.py's `label`
 * class needs EXACTLY ONE overlay listing to carry a func_ label at the
 * address, and 0x021C866C / 0x021C86A8 carry none in any overlay.  The
 * neighbours 0x021C8770/0x021C87FC/0x021C887C/0x021C8978 DO carry labels --
 * they are in asm/overlays/ov114.s -- so the fix is to trace those two
 * entries (layout/function_starts.txt is not this lane's file).
 *
 * UNBLOCKED: func_021C866C (0x021C866C) and func_021C86A8
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int func_02201414(u8 *p)
{
    s32 n;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        ((struct Obj02054 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
            func_022021F8(p, 1);
            func_02008DF0((struct Sub02008C20Obj *)(*(u32 *)(((struct Obj02054 *)p)->f0 + 0x24)), 0x1c);
            ((struct Obj02054 *)p)->f28 = 0x22;
            break;
        case 14:
            ((struct Obj02054 *)p)->f38 = n;
            ((struct Obj02054 *)p)->f28 = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            ((struct Obj02054 *)p)->f38 = n;
            ((struct Obj02054 *)p)->f28 = 0x2d;
            break;
        case 3:
        case 11:
            ((struct Obj02054 *)p)->f38 = n;
            ((struct Obj02054 *)p)->f28 = 0x2d;
            break;
        case 0:
        case 1:
        case 13:
            ((struct Obj02054 *)p)->f38 = n;
            ((struct Obj02054 *)p)->f28 = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case 2:
            func_021F513C(p);
            break;
        }
    } else {
        if (++((struct Obj02054 *)p)->fF8C == 0xe10) {
            func_021F513C(p);
        }
    }
    return 2;
}


/*
 * State 9 with the slot cleared and the u16 at +0x32 set.
 */
int func_022014B8(u8 *p)
{
    func_021C8770(p);
    ((struct Obj09244 *)p)->f28 = 9;
    ((struct Obj09244 *)p)->fF8C = 0;
    ((struct Obj09244 *)p)->f32 = 1;
    return 2;
}


/*
 * Switch on the 0x021C86A8 index (case value = index + 15): state 0x25
 * with the u16 at +0x36 cleared, state 0x2d with the index archived at
 * +0x38, or a plain func_021F513C redraw.
 * The shape is settled and every concrete byte is reproduced; the site is
 * parked because TWO of its callees have no witness anywhere in the tree.
 * Both BLX sites resolve as "(arm, from name) has no witness outside
 * 02201414..02201480; 8 overlays overlap this address (ov016, ov021, ov093,
 * ov111, ov114, ov128, ov172, ov208), none resolvable without a region hint
 * on the symbols: line".  A region hint cannot help: match.py's `label`
 * class needs EXACTLY ONE overlay listing to carry a func_ label at the
 * address, and 0x021C866C / 0x021C86A8 carry none in any overlay.  The
 * neighbours 0x021C8770/0x021C87FC/0x021C887C/0x021C8978 DO carry labels --
 * they are in asm/overlays/ov114.s -- so the fix is to trace those two
 * entries (layout/function_starts.txt is not this lane's file).
 *
 * UNBLOCKED: func_021C866C (0x021C866C) and func_021C86A8
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int func_022014D8(u8 *p)
{
    s32 n;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        ((struct Obj04908 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
            ((struct Obj04908 *)p)->f36 = 0;
            ((struct Obj04908 *)p)->f28 = 0x25;
            break;
        case 3:
        case 11:
            ((struct Obj04908 *)p)->f38 = n;
            ((struct Obj04908 *)p)->f28 = 0x2d;
            break;
        case 0:
        case 1:
        case 10:
        case 12:
        case 13:
        case 14:
            func_021F513C(p);
            break;
        case 2:
            func_021F513C(p);
            break;
        }
    } else {
        if (++((struct Obj04908 *)p)->fF8C == 0xe10) {
            func_021F513C(p);
        }
    }
    return 2;
}


/*
 * State 0xc, slot cleared, then publish the 0xd/0xf pair.
 */
int func_02201554(u8 *p)
{
    func_021C87FC(p + 0xe4);
    ((struct Obj12232 *)p)->f28 = 0xc;
    ((struct Obj12232 *)p)->fF8C = 0;
    func_0220251C(p, 0xd, 0xf);
    return 2;
}


/*
 * Switch on the 0x021C86A8 index (case value = index + 15): state 0x22
 * (with the two 0x0200ADxx queries and a 0x022022B8 call, or 0x1c when the
 * s8 flag at +0x207 is set), then the 0x2b pair (index 12 with the +0x38
 * archive, index 11 without), 0x2d, the +0x38/0x2b group and the plain
 * redraw; indexes 4..10 and 14 are table holes.
 * The shape is settled and every concrete byte is reproduced; the site is
 * parked because 0x021C866C / 0x021C86A8 carry no func_ label in any
 * overlay listing (see the wave-5 residue note for the one-line fix).
 */
int func_0220157C(u8 *p)
{
    s32 n;
    s32 v;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        ((struct Obj01829 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
            v = ((struct Obj01829 *)p)->f207;
            if (v != 0) {
                ((struct Obj01829 *)p)->f28 = 0x1c;
            } else {
                func_022022B8((Work *)p, (void *)func_0200ADB4(*(u32 *)(((struct Obj01829 *)p)->f0)),
                              func_0200ADE0((struct RegB *)(*(u32 *)(((struct Obj01829 *)p)->f0))), v);
                ((struct Obj01829 *)p)->f28 = 0x22;
            }
            break;
        case 12:
            ((struct Obj01829 *)p)->f28 = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case 11:
            ((struct Obj01829 *)p)->f28 = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case 3:
            ((struct Obj01829 *)p)->f38 = n;
            ((struct Obj01829 *)p)->f28 = 0x2d;
            break;
        case 0:
        case 1:
        case 13:
            ((struct Obj01829 *)p)->f38 = n;
            ((struct Obj01829 *)p)->f28 = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case 2:
            func_021F513C(p);
            break;
        }
    } else {
        if (++((struct Obj01829 *)p)->fF8C == 0xe10) {
            func_021F513C(p);
        }
    }
    return 2;
}


/*
 * State-setter: hand the object to func_021C8978, latch state 0xe at +0x28,
 * clear the word at +0xf8c and report 2.
 */
int func_0220163C(u8 *p)
{
    func_021C8978(p);
    ((struct Obj12233 *)p)->f28 = 0xe;
    ((struct Obj12233 *)p)->fF8C = 0;
    return 2;
}


/*
 * Switch on the 0x021C86A8 index (case value = index + 15): state 0x25
 * or a plain func_021F513C redraw.
 * The shape is settled and every concrete byte is reproduced; the site is
 * parked because TWO of its callees have no witness anywhere in the tree.
 * Both BLX sites resolve as "(arm, from name) has no witness outside
 * 02201414..02201480; 8 overlays overlap this address (ov016, ov021, ov093,
 * ov111, ov114, ov128, ov172, ov208), none resolvable without a region hint
 * on the symbols: line".  A region hint cannot help: match.py's `label`
 * class needs EXACTLY ONE overlay listing to carry a func_ label at the
 * address, and 0x021C866C / 0x021C86A8 carry none in any overlay.  The
 * neighbours 0x021C8770/0x021C87FC/0x021C887C/0x021C8978 DO carry labels --
 * they are in asm/overlays/ov114.s -- so the fix is to trace those two
 * entries (layout/function_starts.txt is not this lane's file).
 *
 * UNBLOCKED: func_021C866C (0x021C866C) and func_021C86A8
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int func_02201658(u8 *p)
{
    s32 n;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        ((struct Obj09245 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
            ((struct Obj09245 *)p)->f28 = 0x25;
            break;
        case 10:
        case 11:
        case 12:
            func_021F513C(p);
            break;
        case 0:
        case 1:
        case 3:
        case 13:
            func_021F513C(p);
            break;
        case 2:
            func_021F513C(p);
            break;
        }
    } else {
        if (++((struct Obj09245 *)p)->fF8C == 0xe10) {
            func_021F513C(p);
        }
    }
    return 2;
}


int func_022016CC(u8 *p)
{
    func_021C8C68(*(u32 *)(p + ((struct Obj10595 *)p)->fD4 * 0x128 + 0x314), p + 0xe4, (u32)(p + 0xa24), p + 0x10ec, 0x80);
    func_0220251C(p, 0x12, 0x14);
    ((struct Obj10595 *)p)->f28 = 0x11;
    ((struct Obj10595 *)p)->fF8C = 0;
    return 2;
}


int func_0220171C(u8 *p)
{
    int r;
    if(func_021C866C()) {
        r=func_021C86A8();
        ((struct Obj01943 *)p)->fF8C=0;
        switch(r) {
        case 0:
            ((struct Obj01943 *)p)->f28=0x22;
            func_022021F8(p,0);
            func_022023A4(p,p+0xA24,p+0xE4,p+0xA24,((struct Obj01943 *)p)->fC4);
            func_022024B0(((struct Obj23444 *)(*(u8 * *)&((struct Obj01943 *)p)->f0))->f18,p+0xA24);
            func_02201B44(p,p+0xA24,p+0xA24,p+0xE4);
            break;
        case -5:
            ((struct Obj01943 *)p)->f38=r;
            ((struct Obj01943 *)p)->f28=0x15;
            break;
        case -6: case -7: case -8: case -9: case -10: case -11:
            ((struct Obj01943 *)p)->f38=r;
            ((struct Obj01943 *)p)->f28=0x2D;
            break;
        case -12:
            ((struct Obj01943 *)p)->f38=r;
            ((struct Obj01943 *)p)->f28=0x2D;
            break;
        case -15: case -14: case -2:
            ((struct Obj01943 *)p)->f38=r;
            ((struct Obj01943 *)p)->f28=0x2B;
            func_0200FBB0(); func_0203CA04(); func_0200FBA0(); func_0203C968();
            break;
        case -13:
            func_021F513C(p);
            break;
        }
    } else {
        if(++((struct Obj01943 *)p)->fF8C==0xE10) func_021F513C(p);
    }
    return 2;
}


/*
 * State setter: hand over the object, latch the state word at +0x28 and clear the slot.
 */
int func_022017F0(u8 *p)
{
    func_021C8D14(p);
    ((struct Obj12234 *)p)->f28 = 0x13;
    ((struct Obj12234 *)p)->fF8C = 0x0;
    return 0x2;
}


int func_0220180C(u8 *p)
{
    s32 n;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        ((struct Obj09246 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
            ((struct Obj09246 *)p)->f28 = 0x25;
            break;
        case 10:
            func_021F513C(p);
            break;
        case 0:
        case 1:
        case 3:
        case 13:
            func_021F513C(p);
            break;
        case 2:
            func_021F513C(p);
            break;
        }
    } else {
        if (++((struct Obj09246 *)p)->fF8C == 0xe10) {
            func_021F513C(p);
        }
    }
    return 2;
}


int func_02201880(u8 *p)
{
    func_021C887C(p + 0xe4);
    ((struct Obj12235 *)p)->f28 = 0x1d;
    ((struct Obj12235 *)p)->fF8C = 0x0;
    return 0x2;
}


int func_0220189C(Work *p)
{
    int r;
    void *mon;

    if (func_021C866C() != 0) {
        r = func_021C86A8();
        p->timer = 0;
        switch (r) {
        case 0:
            p->state_i = 0x1E;
            break;
        case 1:
            p->busy = 1;
            switch (func_022024DC((Work *)p, p->ent)) {
            case 1:
                func_021F4FC4((u8 *)p);
                func_021F90A0((u32)p, (u32)p->bank, 0x23, 1, 0xF0F);
                func_021F4E98((u8 *)p, 0x2A, 0x20);
                break;
            case 2:
                func_021F4FC4((u8 *)p);
                func_021F90A0((u32)p, (u32)p->bank, 0x29, 1, 0xF0F);
                func_021F4E98((u8 *)p, 0x2A, 0x20);
                break;
            case 0:
                p->state_i = 0x16;
                p->eb4 = 1;
                p->f12F8 = 1;
                break;
            }
            break;
        case -3:
            p->busy = 0;
            if (func_0200AD8C(p->ctx->sys) != 0) {
                mon = func_02202608(0x48);
                func_0200AD9C(p->ctx->sys, mon);
                func_0201EEF4(p->words, 0, mon);
                p->mode = 2;
                p->state_i = 0x26;
                func_022022B8((Work *)p, (void *)mon, func_0200ADE0(p->ctx->sys), 0);
                func_0200AD94(p->ctx->sys, 0);
                func_020307B0(mon);
            } else {
                func_02201B18((u8 *)p);
            }
            break;
        case -4:
            p->busy = 0;
            if (func_0200AD8C(p->ctx->sys) != 0) {
                mon = func_02202608(0x48);
                func_0200AD9C(p->ctx->sys, mon);
                func_0201EEF4(p->words, 0, mon);
                p->mode = 3;
                p->state_i = 0x26;
                func_0200AD94(p->ctx->sys, 0);
                func_020307B0(mon);
            }
            break;
        case -15:
        case -14:
        case -12:
        case -2:
            p->err = r;
            p->state_i = 0x2B;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case -13:
            func_021F513C((u8 *)p);
            break;
        }
    } else {
        if (++p->timer == 0xE10) {
            func_021F513C((u8 *)p);
        }
    }
    return 2;
}


/*
 * Set the mode pair and latch state 0x28.
 */
int func_02201A34(u8 *p)
{
    func_021F4EC0(p, 0x1, 0x0);
    ((struct Obj18612 *)p)->f28 = 0x28;
    return 2;
}


int func_02201A48(u8 *p)
{
    func_021C87FC(p + 0xe4);
    ((struct Obj12237 *)p)->f28 = 0x1f;
    ((struct Obj12237 *)p)->fF8C = 0x0;
    return 0x2;
}


/*
 * Switch on the 0x021C86A8 index (case value = index + 15): the 0x1a guard
 * over func_0220252C with the +0x32 flag, index 12 with only the flag, the
 * +0x38/0x2b group returning 2, and the plain redraw returning 2.  The nine
 * hole indices 4..11 and 14 are LISTED as empty cases: without them the
 * compiler folds the case set into a compare chain instead of the listing's
 * 16-slot table, and the func_02201B18 call sits after the switch (every
 * break and every hole lands on it).
 * The shape is settled and every concrete byte is reproduced; the site is
 * parked because 0x021C866C / 0x021C86A8 carry no func_ label in any
 * overlay listing (see the wave-5 residue note for the one-line fix).
 *
 * UNBLOCKED: func_021C866C (0x021C866C) and func_021C86A8
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int func_02201A64(u8 *p)
{
    s32 n;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        ((struct Obj03532 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
            if (func_0220252C(p) != 0) {
                ((struct Obj03532 *)p)->f28 = 0x1a;
                ((struct Obj03532 *)p)->f32 = 0;
                return 2;
            }
            ((struct Obj03532 *)p)->f32 = 1;
            break;
        case 12:
            ((struct Obj03532 *)p)->f32 = 0;
            break;
        case 0:
        case 1:
        case 3:
        case 13:
            ((struct Obj03532 *)p)->f38 = n;
            ((struct Obj03532 *)p)->f28 = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            return 2;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 14:
            break;
        case 2:
            func_021F513C(p);
            return 2;
        }
        func_02201B18(p);
    } else {
        if (++((struct Obj03532 *)p)->fF8C == 0xe10) {
            func_021F513C(p);
        }
    }
    return 2;
}


/*
 * Switch on the mode word at +0x18; both arms latch state 0x28.
 */
void func_02201B18(u8 *p)
{
    switch (((struct Obj09247 *)p)->f18) {
    case 1:
        func_021F4EC0(p, 1, 0);
        ((struct Obj09247 *)p)->f28 = 0x28;
        break;
    case 2:
        func_021F4EC0(p, 2, 3);
        ((struct Obj09247 *)p)->f28 = 0x28;
        break;
    }
}


/*
 * lever: u16 local joins species branches; byte flags use explicit masked RMW.
 */
void func_02201B44(u8 *p, void *mon, u8 *r, void *old)
{
    void *copy;
    Record rec;
    u16 species;
    func_02008DF0(((struct Obj23452 *)(*(u8 * *)&((struct Obj08195 *)p)->f0))->f24, 0x10);
    func_0200ED54(func_0200ED48(((struct Obj23453 *)(*(u8 * *)&((struct Obj08195 *)p)->f0))->f3C), ((struct Obj06521 *)r)->f10C);
    copy = func_021F72C4(r);
    func_02009DE8(func_02009EC8(((struct Obj23454 *)(*(u8 * *)&((struct Obj08195 *)p)->f0))->f3C), copy);
    func_020307B0(copy);
    copy = func_021F72C4(r);
    memset(&rec, 0, sizeof(rec));
    func_02008494(copy, &rec);
    if (old != 0) species = func_02017E1C(old, 5, 0);
    else species = ((struct Obj06521 *)r)->fEC;
    rec.old_species = species;
    rec.new_species = func_02017E1C(mon, 5, 0);
    rec.x = ((struct Obj06521 *)r)->f126;
    rec.flags = (rec.flags & ~7) | (((struct Obj06521 *)r)->fF7 & 7);
    rec.y = ((struct Obj06521 *)r)->f127;
    func_0202EB7C((u32)(((struct Obj23455 *)(*(u8 * *)&((struct Obj08195 *)p)->f0))->f18), (u32)(&rec));
    func_020307B0(copy);
}


/*
 * Addresses are Black-image addresses.
 */
int func_02201C08(char *p)
{
    ((struct Obj12238 *)p)->fF8C = 0;
    func_021C89F0();
    ((struct Obj12238 *)p)->f28 = 0x2f;
    return 2;
}


/*
 * Small sparse switch on the 0x021C86A8 index: state 0x30 for the +15 index
 * 3 and for the 0/1/13 group, the plain redraw for index 2, and a
 * state-0x30 (not redraw) counter arm.  This handler does not clear
 * p+0xf8c.
 * The shape is settled and every concrete byte is reproduced; the site is
 * parked because 0x021C866C / 0x021C86A8 carry no func_ label in any
 * overlay listing (see the wave-5 residue note for the one-line fix).
 *
 * UNBLOCKED: func_021C866C (0x021C866C) and func_021C86A8
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int func_02201C24(u8 *p)
{
    s32 n;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        switch (n) {
        case -12:
            ((struct Obj07255 *)p)->f28 = 0x30;
            break;
        case -15:
        case -14:
        case -2:
            ((struct Obj07255 *)p)->f28 = 0x30;
            break;
        case -13:
            func_021F513C(p);
            break;
        }
    } else {
        if (++((struct Obj07255 *)p)->fF8C == 0xe10) {
            ((struct Obj07255 *)p)->f28 = 0x30;
        }
    }
    return 2;
}


/*
 * Every concrete byte is reproduced (52 bytes of code; the listing's extra two
 * are alignment padding).  The one wildcard is the BLX at +0006 to
 * func_021C8658, which has no independent witness outside 0x02201C88..0x02201CBA; the
 * resolver reports "(arm, from name) ... 8 overlays overlap this address
 * (ov016, ov021, ov093, ov111, ov114, ov128, ov172, ov208), none resolvable
 * without a region hint on the symbols: line".  Naming one of those eight
 * regions would be a guess, so the site stays parked.
 *
 * Shape: two hand-overs, then the fixed 6/1/0x48 opener, state 0, return 3.
 */
int func_02201C88(u8 *p)
{
    func_021C8658(p);
    func_021F4FC4(p);
    func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
    ((struct Obj00018 *)p)->f28 = 0;
    return 3;
}


int func_02201CBC(u8 *p)
{
    func_022022B8((Work *)p, (void *)(p + 0xe4), func_0200ADE0(**(void ** *)&((struct Obj00018 *)p)->f0), ((struct Obj00018 *)p)->f207);
    func_022024B0(((struct Obj23457 *)(*(u8 * *)&((struct Obj00018 *)p)->f0))->f18, p + 0xe4);
    func_02201B44(p, p + 0xe4, p + 0xe4, 0);
    func_0200AD94(**(void ** *)&((struct Obj00018 *)p)->f0, 0);
    ((struct Obj00018 *)p)->f28 = 0x22;
    func_0220251C(p, 0x17, 0xf);
    return 2;
}


int func_02201D14(u8 *p)
{
    func_021C88FC(p);
    ((struct Obj12239 *)p)->f28 = 0x18;
    ((struct Obj12239 *)p)->fF8C = 0x0;
    return 0x2;
}


/*
 * Switch on the 0x021C86A8 index (case value = index + 15): state 0x25, the
 * +0x38/0x2b four-call group, the +0x38 archive with a plain redraw for the
 * 3+11 pair, the 0/1/13 and 2 redraw groups; 4..10 and 14 are table holes.
 * Concrete bytes reproduced; parked because 0x021C866C / 0x021C86A8 carry
 * no func_ label in any overlay listing (see pkt_ov135_residue.c.txt).
 * Concrete bytes are identical to the image; the only wildcards are the two
 * BLX sites to 0x021C866C and 0x021C86A8, which carry no func_ label in any
 * overlay listing (match.py's `label` class needs exactly one listing to
 * carry the label, so no region hint can witness them).  One-line fix:
 * trace 0x021C866C / 0x021C86A8 in layout/function_starts.txt and this
 * promotes automatically.
 *
 * UNBLOCKED: func_021C866C (0x021C866C) and func_021C86A8
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT*.
 */
int func_02201D30(u8 *p)
{
    s32 n;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        ((struct Obj04909 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
            ((struct Obj04909 *)p)->f28 = 0x25;
            break;
        case 12:
            ((struct Obj04909 *)p)->f38 = n;
            ((struct Obj04909 *)p)->f28 = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case 3:
        case 11:
            ((struct Obj04909 *)p)->f38 = n;
        case 0:
        case 1:
        case 13:
            func_021F513C(p);
            break;
        case 2:
            func_021F513C(p);
            break;
        }
    } else {
        if (++((struct Obj04909 *)p)->fF8C == 0xe10) {
            func_021F513C(p);
        }
    }
    return 2;
}


int func_02201DBC(void)
{
    return 2;
}


/*
 * Enter the 201DC0 sub-state: flag the u16 at +0x32, set the two work values and stamp the state.
 */
int func_02201DC0(u8 *p)
{
    ((struct Obj12240 *)p)->f32 = 1;
    func_021F4EC0(p, 9, 7);
    ((struct Obj12240 *)p)->f28 = 0x28;
    return 2;
}


/*
 * Enter the 201DD8 sub-state: flag the u16 at +0x32, set the two work values and stamp the state.
 */
int func_02201DD8(u8 *p)
{
    ((struct Obj12241 *)p)->f32 = 0;
    func_021F4EC0(p, 9, 8);
    ((struct Obj12241 *)p)->f28 = 0x28;
    return 2;
}


int func_02201DF0(u8 *p)
{
    func_021F4EC0(p, 0x9, 0x9);
    ((struct Obj18613 *)p)->f28 = 0x28;
    return 2;
}


int func_02201E04(u8 *p)
{
    ((struct Obj12242 *)p)->f32 = 0;
    func_021F4EC0(p, 9, 10);
    ((struct Obj12242 *)p)->f28 = 0x22;
    return 2;
}


int func_02201E1C(u8 *p)
{
    func_021C8978(p);
    ((struct Obj12243 *)p)->f28 = 0x1b;
    ((struct Obj12243 *)p)->fF8C = 0x0;
    return 0x2;
}


/*
 * Switch on the 0x021C86A8 index (case value = index + 15): three
 * func_02201B18 calls falling into the state-0x2b group (archive at +0x38,
 * then the four redraw calls), the two func_021F513C groups at indexes 0/1/3/13
 * and 2, and the plain redraw; indexes 4..9 and 14 are table holes.
 * Every concrete byte reproduced; parked only because 0x021C866C / 0x021C86A8
 * carry no func_ label in any overlay listing (wave-5 residue note).
 * Concrete bytes are identical to the image; the only wildcards are the two
 * BLX sites to 0x021C866C and 0x021C86A8, which carry no func_ label in any
 * overlay listing (match.py's `label` class needs exactly one listing to
 * carry the label, so no region hint can witness them).  One-line fix:
 * trace 0x021C866C / 0x021C86A8 in layout/function_starts.txt and this
 * promotes automatically.
 *
 * UNBLOCKED: func_021C866C (0x021C866C) and func_021C86A8
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int func_02201E38(u8 *p)
{
    s32 n;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        ((struct Obj07256 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
            func_02201B18(p);
            break;
        case 12:
            func_02201B18(p);
        case 11:
            func_02201B18(p);
        case 10:
            ((struct Obj07256 *)p)->f38 = n;
            ((struct Obj07256 *)p)->f28 = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case 0:
        case 1:
        case 3:
        case 13:
            func_021F513C(p);
            break;
        case 2:
            func_021F513C(p);
            break;
        }
    } else {
        if (++((struct Obj07256 *)p)->fF8C == 0xe10) {
            func_021F513C(p);
        }
    }
    return 2;
}


int func_02201ED4(u8 *p)
{
    func_021F90A0((u32)p, (u32)(((struct Obj00018 *)p)->fB6C), 0x99, 1, 0xf0f);
    func_021F4E98(p, 0x2a, 0x28);
    func_021F4EC0(p, 1, 0);
    func_021F4FC4(p);
    func_021FFBC8(p);
    return 2;
}


/*
 * Maps the state word at +0x38 to one of fifteen codes (cases written in
 * descending order, which is the order MWCC lays the bodies out in) and
 * forwards to func_021F9088 with p, the +0xb6c word, the code, 1 and 0x0f0f.
 */
u32 func_02201F18(u8 *p)
{
    u32 v;

    switch (((struct Obj00018 *)p)->f38 + 15) {
    case 14:
        v = 0x9d;
        break;
    case 13:
        v = 0xa9;
        break;
    case 12:
        v = 0xa2;
        break;
    case 11:
        v = 0xa4;
        break;
    case 10:
        v = 0xa3;
        break;
    case 9:
        v = 0x1b;
        break;
    case 8:
        v = 0x1c;
        break;
    case 7:
        v = 0x1d;
        break;
    case 6:
        v = 0x1e;
        break;
    case 5:
        v = 0x1f;
        break;
    case 4:
        v = 0x20;
        break;
    case 3:
        v = 0xa0;
        break;
    case 2:
        v = 0xa5;
        break;
    case 1:
        v = 0xaa;
        break;
    case 0:
        v = 0xa1;
        break;
    default:
        v = 0x9f;
        break;
    }
    return func_021F9088(p, *(u32 *)&((struct Obj00018 *)p)->fB6C, v, 1, 0x0f0f);
}


int func_02201FA4(u8 *p) { func_02201F18(p); if(func_021C866C()) func_021F4E98(p,41,48); else func_021F4E98(p,41,46); func_021F4EC0(p,0,21); func_021F4FC4(p); return 2; }


/*
 * Every concrete byte is reproduced (36 bytes, the last two of them the
 * listing's alignment padding).  The single wildcard is the BLX at +0004 to
 * func_021C866C, which has no independent witness outside 02201FDC..02201FFE;
 * the resolver reports "(arm, from name) ... 8 overlays overlap this address
 * (ov016, ov021, ov093, ov111, ov114, ov128, ov172, ov208), none resolvable
 * without a region hint on the symbols: line".  Guessing one of those eight
 * regions would be a false witness, so the site stays parked until the region
 * that owns 0x021C866C is named.
 *
 * The shape itself is settled: the callee's result selects state 0x30 or 0x2e,
 * then the 0/0x15 pair is published and 2 is returned.
 *
 * UNBLOCKED: func_021C866C (0x021C866C) and func_021C86A8
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT*.
 */
int func_02201FDC(u8 *p)
{
    if (func_021C866C(p) != 0) {
        ((struct Obj12244 *)p)->f28 = 0x30;
    } else {
        ((struct Obj12244 *)p)->f28 = 0x2e;
    }
    func_021F4EC0(p, 0, 0x15);
    return 2;
}


int func_02202000(u8 *p) { func_02201F18(p); func_021F4E98(p,41,40); func_021F4EC0(p,1,0); func_021F4FC4(p); if(((struct Obj00018 *)p)->fD0>0) func_021FFBC8(p); return 2; }


/*
 * Publish the 0x29/0x22 then the 0x25/0x28 pair and report 2.
 */
int func_02202038(u8 *p)
{
    func_021F4E98(p, 0x29, 0x22);
    func_0220251C(p, 0x25, 0x28);
    return 2;
}


/*
 * Latch state 0x23 and publish the +2 tick of the 0x3c query into +0xdfc.
 */
int func_02202054(u8 *p)
{
    func_02012DAC((int)func_020120F4((const struct Ctx *)(*(u32 *)(((struct Obj09248 *)p)->f0 + 0x40))));
    ((struct Obj09248 *)p)->f28 = 0x23;
    ((struct Obj09248 *)p)->fDFC = func_020056EC(0x3c) + 2;
    return 2;
}


int func_0220207C(Work *p)
{
    p->cnt--;
    if (p->cnt == 0) {
        p->state_i = 0x24;
    }
    return 2;
}


int func_02202094(u8 *p)
{
    if (func_02012DD0(func_020120F4((const struct Ctx *)(*(u32 *)(((struct Obj09249 *)p)->f0 + 0x40)))) == 1) {
        ((struct Obj09249 *)p)->f28 = ((struct Obj09249 *)p)->fE0C;
    }
    return 2;
}


/*
 * When the mode query answers 2, publish the u16 at +0xe0e and hand the object back.
 */
int func_022020B8(u8 *p)
{
    if (func_02012DD0(func_020120F4((const struct Ctx *)(*(u32 *)(((struct Obj09250 *)p)->f0 + 0x40)))) == 2) {
        ((struct Obj09250 *)p)->f28 = ((struct Obj09250 *)p)->fE0E;
        func_021F4FC4(p);
    }
    return 2;
}


/*
 * Run the sub-object init, stamp 0x27 and report 2.
 */
int func_022020E0(u8 *p)
{
    func_02012DAC((int)func_020120F4((const struct Ctx *)(*(u32 *)(((struct Obj12245 *)p)->f0 + 0x40))));
    ((struct Obj12245 *)p)->f28 = 0x27;
    return 2;
}


int func_022020F8(u8 *p)
{
    if (func_02012DD0(func_020120F4((const struct Ctx *)(((struct Obj23459 *)(*(u8 * *)&((struct Obj00018 *)p)->f0))->f40))) == 2) {
        func_021F4EC0(p, 1, 0);
        func_021F4FC4(p);
        func_021F90A0((u32)p, (u32)(((struct Obj00018 *)p)->fB6C), ((struct Obj00018 *)p)->f24, 1, 0xF0F);
        func_021F4E98(p, 0x2A, 0x20);
    }
    return 2;
}


/*
 * lever: nested if with equal sentinel arm first preserves the branch hop.
 */
int func_02202148(u8 *p)
{
    func_021F4FC4(p);
    if (((struct Obj14178 *)p)->fEB4 == 1) {
        if (func_0207D55C((u16 *)0x0400106C) == -16)
            func_0202208C((void *)3, 0, 0, 0, 6, 1, 0x48);
        else
            func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
    } else {
        func_0202208C((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    ((struct Obj14178 *)p)->f28 = 0;
    return 3;
}


int func_022021A4(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        ((struct Obj12246 *)p)->f28 = ((struct Obj12246 *)p)->f2C;
    }
    return 2;
}


int func_022021C0(u8 *p) { if((func_02202840(p+0xfa0)==0 && (func_020362DC()&1)) || func_02035C60()) { func_020061E4(0x547); ((struct Obj14179 *)p)->f28=((struct Obj14179 *)p)->f2C; } return 2; }


/*
 * tail: 022022B6..022022B8 zero alignment padding.
 */
void func_022021F8(u8 *p, int flag)
{
    void *mon;
    void *save;
    void *box;
    if (((struct Obj01260 *)p)->fC4 != 0xFF) {
        mon = func_02202608(0x48);
        func_022026A0((u8 *)func_02007A18(((struct Obj23460 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->fC, ((struct Obj01260 *)p)->fC4, ((struct Obj01260 *)p)->fC6), (u32)mon);
        if (flag) func_0200ADB8(((struct Obj23461 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f0, mon, ((struct Obj01260 *)p)->fC4);
        func_02007664(((struct Obj23462 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->fC, ((struct Obj01260 *)p)->fC4, ((struct Obj01260 *)p)->fC6);
        func_020307B0(mon);
    } else {
        mon = func_0201AB28(((struct Obj23463 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f8, ((struct Obj01260 *)p)->fC6);
        if (flag) func_0200ADB8(((struct Obj23464 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f0, mon, ((struct Obj01260 *)p)->fC4);
        func_0201A9C8(((struct Obj23465 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f8, ((struct Obj01260 *)p)->fC6);
        save = func_020120F4((const struct Ctx *)(((struct Obj23466 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f40));
        box = func_02012F98(save);
        func_02007C34(box, func_02012934(save));
    }
    if (flag) func_0200AD94(((struct Obj23467 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f0, 1);
}


void func_022022B8(Work *p, void *mon, u32 box, int hatch)
{
    u32 pos;
    u32 species;
    u32 form;
    u32 slot;

    func_02017E1C(mon, 6, 0);
    func_0200CDE0(p->ctx->dex, mon);
    box = 0xFF;
    if (func_0201AA18(p->ctx->party) == 6) {
        box = 0;
    }
    if (hatch != 0) {
        func_02017E40(mon, 9, 0x46);
        species = func_02017E1C(mon, 5, 0);
        form = func_02017E1C(mon, 0x6F, 0);
        func_02017E40(mon, 0x6E, func_02017F50((u16)species, form, func_02017E1C(mon, 0, 0)));
        func_0220246C(p->ctx->sys, 0);
    }
    if (box == 0xFF) {
        func_0201A98C(p->ctx->party, mon);
        slot = func_0201AA18(p->ctx->party);
        p->box_u = 0xFF;
        slot -= 1;
    } else {
        pos = 0;
        func_020076D0((void *)p->ctx->box, (int *)(&box), (int *)(&pos));
        func_0200752C((void **)p->ctx->box, box, (const struct Sub02007454Entry *)func_022026BC(mon));
        p->box_u = box;
        slot = pos;
    }
    p->pos = slot;
    func_0200AD94(p->ctx->sys, 0);
}


/*
 * evidence: func_0200CDE0 receives the entry r1 Pokemon pointer; fifth parameter is reassigned in its incoming stack slot.
 */
void func_022023A4(u8 *p,void *mon,void *unused2,void *unused3,u32 index)
{
    u32 species, form, pos;
    func_0200CDE0(*(struct Blk37 * *)&((struct Obj23476 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->f10,mon);
    index=0xFF;
    if(func_0201AA18(((struct Obj23477 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->f8)==6) index=0;
    func_02017E40(mon,9,0x46);
    species=func_02017E1C(mon,5,0);
    form=func_02017E1C(mon,0x6F,0);
    func_02017E40(mon,0x6E,func_02017F50((u16)species,form,func_02017E1C(mon,0,0)));
    if(index==0xFF) {
        func_0201A98C(*(struct Party * *)&((struct Obj23478 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->f8,(const struct PartyMon *)mon);
        pos=func_0201AA18(((struct Obj23479 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->f8);
        ((struct Obj02864 *)p)->fDC=0xFF;
        pos--;
    } else {
        u32 slot=0;
        func_020076D0(((struct Obj23480 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->fC,(int *)(&index),(int *)(&slot));
        func_0200752C(((struct Obj23481 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->fC,index,(const struct Sub02007454Entry *)func_022026BC(mon));
        ((struct Obj02864 *)p)->fDC=index;
        pos=slot;
    }
    ((struct Obj02864 *)p)->fE0=pos;
    func_0220246C(*(void **)*(u8 * *)&((struct Obj02864 *)p)->f0,1);
}


void func_0220246C(void *p, int which)
{
    RTCDate date;
    RTCTime time;
    u32 v;

    DWC_GetDateTime(&date, &time);
    v = ((u32)date.year << 24) | (((u32)date.month << 24) >> 8) | (((u32)date.day << 24) >> 16) | date.week;
    if (which == 1) {
        func_0200ADD8(p, v);
    } else {
        func_0200ADD0(p, v);
    }
}


void func_022024B0(void *obj,u8 *p) { int b=p[0x121],a=p[0x120]; if(func_0200949C(obj,a,b)==0) func_020094D8(obj,a,b,1); }


int func_022024DC(Work *p, void *mon)
{
    if (func_021F6DE8((u32)mon) != 0 && func_0201AA18(p->ctx->party) == 6) {
        return 2;
    }
    if (p->species == 0x2D0 && func_0201AA18(p->ctx->party) == 6) {
        return 1;
    }
    return 0;
}


/*
 * Store a pair of u16 values at +0xe0c and +0xe0e.
 */
void func_0220251C(u8 *p, u16 a, u16 b)
{
    ((struct Obj00018 *)p)->fE0C = a;
    ((struct Obj00018 *)p)->fE0E = b;
}


/*
 * 1 only when the query is clear and the u16 at +0x32 is set.
 */
u32 func_0220252C(u8 *p)
{
    if (func_0200AD8C((const struct Rec0200AD8C *)(*(u32 *)(((struct Obj12247 *)p)->f0))) == 0) {
        if (((struct Obj12247 *)p)->f32 != 0) {
            return 1;
        }
    }
    return 0;
}


void func_0220254C(void *mon, u32 heap)
{
    void *bank;
    void *str;
    void *buf;
    u32 id;

    id = (heap & 0x7FFF) | 0x8000;
    bank = func_02045B38(0, 2, 0x51, (u16)id);
    str = func_02045EC0(bank, 0xF);
    func_02045C04(bank);
    func_02019B58(mon);
    func_02017E40(mon, 0x8E, (u32)func_02045A90(str));
    if (func_0202136C((u16)func_02017E1C(mon, 6, 0)) != 0) {
        buf = func_02008F08((u16)id);
        func_02017E1C(mon, 0xA7, (u32)buf);
        func_02008F88(buf, func_02045A90(str));
        func_02017E40(mon, 0xA7, (u32)buf);
        func_020307B0(buf);
    }
    func_02045808(str);
}


/*
 * Allocate a 0x48-byte block and hand it to the writer, then free the block.
 */
void func_022025E4(u32 a, u32 b, u32 c)
{
    void *blk = func_0201747C((void *)c, 0x48);

    func_0201EEF4((void *)a, b, blk);
    func_020307B0(blk);
}


/*
 * Create the table entry and register the 0x47 callback against it.
 */
void *func_02202608(u32 heap)
{
    return func_02030734(heap, func_020173EC(), 0, g_02203F5C, 0x47);
}


/*
 * Hand the size guess back to the main writer with the caller's handle.
 */
void func_0220262C(u32 a, u32 b)
{
    func_02082D44((const void *)a, (void *)b, func_020173EC());
}


/*
 * switch on kind
 */
void func_02202644(u32 a, int kind)
{
    func_020456F8((struct Descriptor *)a);
    switch (kind) {
    case 0:
        func_020409B4(func_02045730((struct Descriptor *)a));
        break;
    case 1:
        func_02041B6C(func_02045730((struct Descriptor *)a));
        break;
    }
}


/*
 * Encode one record through the two stage helpers and flush it to the writer.
 */
u32 func_02202670(u32 a, u32 b, u32 c, u32 d)
{
    u32 t1 = (u32)func_02045EC0((struct MsgBank *)b, c);
    u32 t2 = (u32)func_020457B0(0x200, d);

    func_0201F250((struct WordSet *)a, (void *)t2, (void *)t1);
    func_02045808((struct U16Vec *)t1);
    return t2;
}


/*
 * Create the 0x48 sub-object, register the handle and hand it to the callback.
 */
void func_022026A0(u8 *p, u32 k)
{
    u32 h = (u32)func_0201747C((struct Mon *)p, 0x48);

    func_0220262C(h, k);
    func_020307B0((void *)h);
}


/*
 * Tail-call thunk to the thumb routine at 0x020185F4.
 */
u32 func_022026BC(void *mon)
{
    return (u32)func_020185F4(mon);
}


/*
 * Tail call: the third argument goes first, the dereferenced pointer second, the u16 last.
 */
int func_022026C4(u32 *p, u32 b, u32 a, u32 c)
{
    return func_0201D304((struct StrObj *)a, *p, (u16)c);
}


void func_022026D8(Ctx_02202094 *ctx, u32 arg)
{
    int i;
    Slot_02202094 *s;

    func_02082BCC(ctx, 0, 0x13C);
    ctx->buf = func_0203101C(0x48, 0x48, 0x20, 0x20);
    ctx->arg = arg;
    ctx->font = func_0201D7EC(0x17, 0, 0, 0, 0x48);
    ctx->msg = (void *)func_0201C440((void *)0x48);
    ctx->res = func_02028590(0xF, 1, 1, 0x48);
    for (i = 0; i < 0x18; i++) {
        s = &ctx->slot[i];
        func_02082BCC(s, 0, 8);
        s->c = 0;
    }
}


/*
 * Free every buffer the object owns and blank the 0x13c-byte tail.
 */
void func_02202744(u8 *p)
{
    func_02028604(((struct Obj07257 *)p)->f138);
    func_0201C4C0((struct PrintSys *)(((struct Obj07257 *)p)->fC));
    func_0201D83C((void *)(((struct Obj07257 *)p)->f0));
    func_02031140((struct S02031140 *)(((struct Obj07257 *)p)->f4));
    func_02082BCC((void *)((u32)p), 0, 0x13c);
}


void func_02202770(Printer_02202094 *p)
{
    int i;
    Ent_02202094 *e;
    void *queue;

    for (i = 0; i < 24; i++) {
        e = &p->ent[i];
        if (e->active != 0) {
            queue = p->queue;
            if (e->busy != 0 && func_0201C6C4(queue, func_02045770(e->win)) == 0) {
                func_02045334(e->win);
                e->busy = 0;
            }
            if (e->busy == 0) {
                e->active = 0;
            }
        }
    }
    if (p->yesno != 0) {
        func_020286C4((struct Ctx_02202094 *)p->bg, p->yesno, p->yesnoArg);
        switch (func_0201CE30(p->yesno)) {
        case 0:
            if ((func_020362DC() & 3) || func_02035C60() != 0) {
                func_0201CE5C(p->yesno, 0);
            }
            break;
        case 1:
            if ((func_020362DC() & 3) || func_02035C60() != 0) {
                func_020061E4(0x547);
                func_0201CE38(p->yesno);
            }
            break;
        case 2:
            func_0201CE48(p->yesno);
            p->yesno = 0;
            p->yesnoArg = 0;
            break;
        }
    }
    func_0201C4E4(p->queue);
    func_020310C4(p->heap);
}


/*
 * Non-zero unless the +0x10 handle is absent or the query answers 2.
 */
u32 func_02202840(u8 *p)
{
    u32 r;
    u32 x;

    r = 0;
    x = ((struct Obj18615 *)p)->f10;
    if (x != 0 && func_0201CE30((void *)x) != 2) {
        r = 1;
    }
    return r;
}


u32 func_02202858(void *p,u8 b,void *s,u32 x,u32 y,void *out) { return func_022028C8(p, b, (u32)s, x, y, 0, 0x44f, (Ctx_02202878 *)out); }


/*
 * tail: 022028C6..022028C8 zero alignment padding.
 */
void func_02202878(void *a, unsigned b, unsigned c, int d, int e, u8 *p)
{
    int v;
    if (((struct Obj04532 *)p)->f10) {
        func_0201CE48(((struct Obj04532 *)p)->f10);
        ((struct Obj04532 *)p)->f10 = 0;
    }
    v = func_02012FFC();
    ((struct Obj04532 *)p)->f10 = func_0201CCE4(a, d, e, c, ((struct Obj04532 *)p)->f0, v, ((struct Obj04532 *)p)->f4, 0, 0x48, 0xF);
    ((struct Obj04532 *)p)->f14 = a;
}


u32 func_022028C8(void *win, u8 z, u32 str, u32 x, u32 y, u32 z2, u16 color, Ctx_02202878 *g)
{
    Slot_02202878 *found = 0;
    int i;
    u32 print;

    for (i = 0; i < 24; i++) {
        if (g->slots[i].used == 0) {
            found = &g->slots[i];
        }
    }
    if (found == 0) {
        func_02034714((void *)0x02203F74, 0, (void *)0x02203F74);
    }
    found->win = win;
    found->busy = 0;
    print = g->print;
    func_0201C724((void *)print, (u32)func_02045770((struct Descriptor *)win), (s16)x, (s16)y, str, g->font, color);
    found->busy = 1;
    found->used = 1;
    return 1;
}


/*
 * note: 2026-10-05 P22L9: array base reached through a static inline accessor p->e (the bare field, a local pointer and u32 arithmetic all kept the base in r1, DIFF16/13). The zero stored is the counter's initial copy (idiom a-copy-of-the-counter-before-the-loop-label-is-a-stored-zero).
 */
void func_02202940(struct Obj *p) {
    int i;
    for (i = 0; i < 24; i++) {
        struct Ent_02202940 *e = p->e + i;
        if (e->c != 0) e->c = 0;
    }
    if (p->h != 0) {
        func_0201CE48(p->h);
        p->h = 0;
        p->n = 0;
    }
}


Ctx_02202974 *func_02202974(u32 a, u32 b, u32 c, u32 heap)
{
    Ctx_02202974 *ctx;

    ctx = func_02030734(heap, 0x74, 0, (const char *)g_02203F5C, 0x1DD);
    func_02082BCC(ctx, 0, 0x74);
    ctx->heap = heap;
    ctx->font = func_0201D7EC(0x17, 3, 0, 0, heap);
    ctx->msg = (void *)func_0201C440((void *)heap);
    ctx->bank = func_02045B38(0, 2, 0xD0, heap);
    ctx->words = func_0201EC64(heap);
    return ctx;
}


/*
 * Release every buffer the object owns, then the object itself.
 */
void func_022029D4(u8 *p)
{
    func_0201ED04((struct WordSet *)(((struct Obj07259 *)p)->f8));
    func_02045C04((struct Rec *)(((struct Obj07259 *)p)->fC));
    func_0201C4C0((struct PrintSys *)(((struct Obj07259 *)p)->f4));
    func_0201D83C((void *)(((struct Obj07259 *)p)->f0));
    func_020307B0((void *)((u32)p));
}


void func_022029F8(Printer_02202940 *q)
{
    int i;
    void *queue;

    for (i = 0; i < 8; i++) {
        if (q->active[i] != 0) {
            queue = q->queue;
            if (q->ent[i].busy != 0 && func_0201C6C4(queue, func_02045770(q->ent[i].win)) == 0) {
                func_02045334(q->ent[i].win);
                q->ent[i].busy = 0;
            }
            if (q->ent[i].busy == 0) {
                q->active[i] = 0;
            }
        }
    }
    func_0201C4E4(q->queue);
}


void func_02202A50(Ctx_02202A50 *ctx, u32 num, u32 digits, u32 mode, void *win, int x, int y)
{
    void *str;
    void *fmt;
    void *print;
    int i;

    str = func_020457B0(0x20, ctx->heap);
    fmt = func_020457B0(0x20, ctx->heap);
    func_02045CAC(ctx->bank, 0xFD, fmt);
    func_0201EFA4(ctx->words, 0, num, digits, mode, 1);
    func_0201F250(ctx->words, str, fmt);
    for (i = 0; i < 8; i++) {
        if (ctx->used[i] == 0) {
            ctx->slot[i].win = win;
            ctx->slot[i].shown = 0;
            print = ctx->print;
            func_0201C724(print, (u32)func_02045770(ctx->slot[i].win), (s16)x, (s16)y, (u32)str, (u32)ctx->font, 0x3DC8);
            ctx->slot[i].shown = 1;
            ctx->used[i] = 1;
            func_02045808(fmt);
            func_02045808(str);
            return;
        }
    }
    func_02034714((void *)0x02203F74, 0, (void *)0x02203F74);
}
