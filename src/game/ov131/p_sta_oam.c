/*
 * file:     p_sta_oam.c
 * unit:     yes
 * function: func_021D4240, func_021D4418, func_021D44C8, func_021D46E4, func_021D46EC, func_021D48E4, func_021D4940, func_021D4964, func_021D4F24, func_021D4FBC, func_021D5180, func_021D51DC, func_021D5258, func_021D5280, func_021D52A8, func_021D52D4, func_021D54A8, func_021D5650, func_021D5A9C, func_021D5B58, func_021D5BAC, func_021D5C4C, func_021D5C98, func_021D5DC4, func_021D6064, func_021D60A4, func_021D60D4, func_021D614C, func_021D618C, func_021D61B8, func_021D6214, func_021D6244, func_021D62B4, func_021D62E4, func_021D62F4, func_021D6324, func_021D657C, func_021D65BC, func_021D65D8, func_021D6608, func_021D6614, func_021D67EC, func_021D6808, func_021D6810, func_021D694C, func_021D697C, func_021D6A38, func_021D6CDC, func_021D6D04, func_021D6D18, func_021D6F54, func_021D703C, func_021D7060, func_021D708C, func_021D7248, func_021D72E8, func_021D7460, func_021D75A4, func_021D77E8, func_021D77F8, func_021D7810, func_021D785C, func_021D797C, func_021D79A8, func_021D7A1C, func_021D7A44, func_021D7B00, func_021D7B34, func_021D7B48, func_021D7B4C, func_021D7BF0, func_021D7C38, func_021D7CAC, func_021D7E84, func_021D7EAC, func_021D7F04, func_021D8288, func_021D8784, func_021D87E0, func_021D881C, func_021D8830, func_021D8884, func_021D8904, func_021D8938, func_021D89FC, func_021D8A2C, func_021D8AD0, func_021D8CD0, func_021D8E24, func_021D8EA8, func_021D8ED0, func_021D8F0C, func_021D8F50, func_021D8FAC, func_021D909C, func_021D90C0, func_021D911C, func_021D91EC, func_021D91F0, func_021D92B0, func_021D93E4, func_021D9428, func_021D9440, func_021D949C, func_021D9568, func_021D964C, func_021D9670, func_021D96B0, func_021D9734, func_021D9740, func_021D9980, func_021D9A04, func_021D9A4C, func_021D9BD4, func_021D9C3C, func_021D9CD0, func_021D9D44, func_021D9D94, func_021D9E30, func_021D9E44, func_021D9EE8, func_021D9EF0, func_021DA0B0, func_021DA3FC, func_021DA488, func_021DA6A4, func_021DA7A4, func_021DA84C, func_021DA8BC, func_021DA958, func_021DA998, func_021DABCC, func_021DAEE4, func_021DB140, func_021DB3F0, func_021DB468, func_021DB508, func_021DB614, func_021DB688, func_021DB6D0, func_021DB700, func_021DB7B8, func_021DB7D0, func_021DB7D4, func_021DB964, func_021DB9E8, func_021DB9FC, func_021DBA14, func_021DBA54, func_021DBA78, func_021DBA90, func_021DBAC0, func_021DBAD0, func_021DBC3C, func_021DBCA4, func_021DBCF4, func_021DBE2C, func_021DBE98, func_021DBEA4, func_021DBF0C, func_021DBF2C
 * address:  0x021D4240
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   func_0201747C 0x0201747C thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_02082A60 0x02082A60 arm
 *   func_02012BF8 0x02012BF8 thumb
 *   func_0203D34C 0x0203D34C arm
 *   func_02030EAC 0x02030EAC arm
 *   func_02012BE0 0x02012BE0 thumb
 *   func_020355D8 0x020355D8 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02035CB8 0x02035CB8 arm
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_0204B98C 0x0204B98C arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0204A600 0x0204A600 arm
 *   func_02014C08 0x02014C08 thumb
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02014D2C 0x02014D2C thumb
 *   func_02047970 0x02047970 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_0204B878 0x0204B878 arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0202223C 0x0202223C thumb
 *   func_02022224 0x02022224 thumb
 *   func_020433E0 0x020433E0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   func_02046BE0 0x02046BE0 arm
 *   func_0204044C 0x0204044C arm
 *   func_02014B08 0x02014B08 thumb
 *   func_02016020 0x02016020 thumb
 *   func_020160C0 0x020160C0 thumb
 *   g_C0E4 0x021DC0E4 data ov131
 *   g_BFF4 0x021DBFF4 data ov131
 *   g_C004 0x021DC004 data ov131
 *   g_1448 0x020A1448 data
 *   g_BFC0 0x021DBFC0 data ov131
 *   g_BFE4 0x021DBFE4 data ov131
 *   func_02061C30 0x02061C30 arm
 *   func_02014BA8 0x02014BA8 thumb
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02049238 0x02049238 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   g_BFA0 0x021DBFA0 data ov131
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   func_0201C450 0x0201C450 thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02035C08 0x02035C08 arm
 *   d_021DC114 0x021DC114 data a1
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0203633C 0x0203633C arm
 *   func_020362DC 0x020362DC arm
 *   func_020061E4 0x020061E4 thumb
 *   func_02061CA4 0x02061CA4 arm
 *   d_021DBFA8 0x021DBFA8 data a2
 *   d_021DBFB8 0x021DBFB8 data a2
 *   FX_SinCosTable_ 0x020A1B38 data
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _ffix 0x0209C494 arm
 *   func_02006BB4 0x02006BB4 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02006CAC 0x02006CAC thumb
 *   func_02006984 0x02006984 thumb
 *   func_020173E8 0x020173E8 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_02045770 0x02045770 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02017E88 0x02017E88 thumb
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02030734 0x02030734 arm
 *   func_0203630C 0x0203630C arm
 *   func_0201A920 0x0201A920 thumb
 *   func_0201A954 0x0201A954 thumb
 *   func_020173F0 0x020173F0 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_0201A98C 0x0201A98C thumb
 *   func_02017550 0x02017550 thumb
 *   func_02005728 0x02005728 thumb
 *   func_02017600 0x02017600 thumb
 *   func_02017E64 0x02017E64 thumb
 *   func_020124F4 0x020124F4 thumb
 *   d_021DC80C 0x021DC80C data a1
 *   d_021DC138 0x021DC138 data a2
 *   d_021DC144 0x021DC144 data a2
 *   func_02012704 0x02012704 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   d_021DC818 0x021DC818 data a1
 *   func_02015EB0 0x02015EB0 thumb
 *   func_02015EA0 0x02015EA0 thumb
 *   func_02015C78 0x02015C78 thumb
 *   func_02015D30 0x02015D30 thumb
 *   func_02048AFC 0x02048AFC arm
 *   d_020A1B38 0x020A1B38 data a2
 *   d_021DC234 0x021DC234 data a4
 *   d_021DC228 0x021DC228 data a4
 *   d_021DC198 0x021DC198 data a4
 *   d_021DC210 0x021DC210 data a4
 *   d_021DC170 0x021DC170 data a4
 *   d_021DC178 0x021DC178 data a4
 *   d_021DC168 0x021DC168 data a4
 *   d_021DC158 0x021DC158 data a1
 *   d_021DC160 0x021DC160 data a1
 *   func_020450F0 0x020450F0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02049F34 0x02049F34 arm
 *   func_02049DB4 0x02049DB4 arm
 *   func_0204ADEC 0x0204ADEC arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   d_021DC204 0x021DC204 data a4
 *   d_021DC21C 0x021DC21C data a4
 *   d_021DC1B0 0x021DC1B0 data a4
 *   d_021DC1A4 0x021DC1A4 data a4
 *   d_021DC18C 0x021DC18C data a4
 *   d_021DC1BC 0x021DC1BC data a4
 *   func_0201ACDC 0x0201ACDC thumb
 *   func_020452E8 0x020452E8 arm
 *   func_02015E4C 0x02015E4C thumb
 *   d_021DC1D4 0x021DC1D4 data a4
 *   _ffltu 0x0209BE04 arm
 *   _fsub 0x0209CB8C arm
 *   func_02015C48 0x02015C48 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   func_02015E04 0x02015E04 thumb
 *   func_02035C60 0x02035C60 arm
 *   func_02035C38 0x02035C38 arm
 *   func_02035BA4 0x02035BA4 arm
 *   d_021DC1E0 0x021DC1E0 data a1
 *   d_021DC1F8 0x021DC1F8 data ov131 a4
 *   d_021DC240 0x021DC240 data ov131 a4
 *   d_021DC180 0x021DC180 data a4
 *   d_021DC1C8 0x021DC1C8 data ov131 a4
 *   func_02015D80 0x02015D80 thumb
 *   func_02015CDC 0x02015CDC thumb
 *   func_02015BA4 0x02015BA4 thumb
 *   _ll_mul 0x0209C054 arm
 *   d_021DC1EC 0x021DC1EC data a4
 *   d_020A5078 0x020A5078 data a2
 *   func_0207C9D0 0x0207C9D0 arm
 *   func_02015D94 0x02015D94 thumb
 *   func_0201AF80 0x0201AF80 thumb
 *   d_021DC824 0x021DC824 data a1
 *   func_02049EF4 0x02049EF4 arm
 *   d_021DC288 0x021DC288 data a1
 *   func_020410D0 0x020410D0 arm
 *   func_02040AE0 0x02040AE0 arm
 *   func_0204AB84 0x0204AB84 arm
 *   func_0204B784 0x0204B784 arm
 *   func_020275EC 0x020275EC thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B84C 0x0204B84C arm
 *   func_02041300 0x02041300 arm
 *   func_02041570 0x02041570 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02017EB4 0x02017EB4 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_02018584 0x02018584 thumb
 *   func_02043AF4 0x02043AF4 arm
 *   g_020A7370 0x020A7370 data
 *   _s32_div_f 0x0209C0A4 arm
 *   d_021DC24C 0x021DC24C data
 *   d_021DC264 0x021DC264 data
 *   func_0202F688 0x0202F688 thumb
 *   func_0202F6D8 0x0202F6D8 thumb
 *   d_021DC834 0x021DC834 data a1
 *   func_02049E74 0x02049E74 arm
 *   func_02043754 0x02043754 arm
 *   func_020437AC 0x020437AC arm
 *   d_021DC2B0 0x021DC2B0 data a1
 *   func_020437D4 0x020437D4 arm
 *   func_02082D44 0x02082D44 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_0200616C 0x0200616C thumb
 *   func_021DBF94 0x021DBF94 thumb ov131
 *   d_021DC844 0x021DC844 data a1
 *   d_021DC2C2 0x021DC2C2 data a1
 *   func_02045798 0x02045798 arm
 *   func_020409E0 0x020409E0 arm
 *   func_0202D034 0x0202D034 thumb
 *   func_0202D01C 0x0202D01C thumb
 *   func_0201C1E8 0x0201C1E8 thumb
 *   func_02027604 0x02027604 thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_02043678 0x02043678 arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_0202F72C 0x0202F72C thumb
 *   func_020181FC 0x020181FC thumb
 *   func_02019B44 0x02019B44 thumb
 *   d_021DC2B8 0x021DC2B8 data a1
 *   func_0201BD28 0x0201BD28 thumb
 *   func_0201C1C8 0x0201C1C8 thumb
 *   d_021DC854 0x021DC854 data a1
 *   func_020437DC 0x020437DC arm
 *   func_020437E4 0x020437E4 arm
 *   func_020437EC 0x020437EC arm
 *   func_020862F0 0x020862F0 arm
 *   func_0204ABBC 0x0204ABBC arm
 *   func_0207E780 0x0207E780 arm
 *   func_0207E804 0x0207E804 arm
 *   d_021DC2F8 0x021DC2F8 data a4
 */
#include "../../matched/include/Obj00238.h"
#include "../../matched/include/Obj23119.h"
#include "../../matched/include/Obj01255.h"
#include "../../matched/include/Obj23120.h"
#include "../../matched/include/Obj00035.h"
#include "../../matched/include/Obj23121.h"
#include "../../matched/include/Obj23122.h"
#include "../../matched/include/Obj01739.h"
#include "../../matched/include/Obj10503.h"
#include "../../matched/include/Obj08143.h"
#include "../../matched/include/Obj00591.h"
#include "../../matched/include/Obj10504.h"
#include "../../matched/include/Obj03814.h"
#include "../../matched/include/Obj08144.h"
#include "../../matched/include/Obj23123.h"
#include "../../matched/include/Obj00039.h"
#include "../../matched/include/Obj00136.h"
#include "../../matched/include/Obj03284.h"
#include "../../matched/include/Obj00112.h"
#include "../../matched/include/Obj10506.h"
#include "../../matched/include/Obj08145.h"
#include "../../matched/include/Obj06482.h"
#include "../../matched/include/Obj23130.h"
#include "../../matched/include/Obj23131.h"
#include "../../matched/include/Obj00830.h"
#include "../../matched/include/Obj14064.h"
#include "../../matched/include/Obj23132.h"
#include "../../matched/include/Obj00200.h"
#include "../../matched/include/Obj05385.h"
#include "../../matched/include/Obj00993.h"
#include "../../matched/include/Obj05386.h"
#include "../../matched/include/Obj10507.h"
#include "../../matched/include/Obj00436.h"
#include "../../matched/include/Obj00472.h"
#include "../../matched/include/Obj10508.h"
#include "../../matched/include/Obj14066.h"
#include "../../matched/include/Obj14067.h"
#include "../../matched/include/Obj23137.h"
#include "../../matched/include/Obj01546.h"
#include "../../matched/include/Obj01740.h"
#include "../../matched/include/Obj05387.h"
#include "../../matched/include/Obj10509.h"
#include "../../matched/include/Obj02188.h"
#include "../../matched/include/Obj14068.h"
#include "../../matched/include/Obj05388.h"
#include "../../matched/include/Obj23139.h"
#include "../../matched/include/Obj00831.h"
#include "../../matched/include/Obj23140.h"
#include "../../matched/include/Obj00219.h"
#include "../../matched/include/Obj06483.h"
#include "../../matched/include/Obj00994.h"
#include "../../matched/include/Obj14069.h"
#include "../../matched/include/Obj00994.h"
#include "../../matched/include/Obj23143.h"
#include "../../matched/include/Obj00776.h"
#include "../../matched/include/Obj03285.h"
#include "../../matched/include/Obj02844.h"
#include "../../matched/include/Obj01547.h"
#include "../../matched/include/Obj01407.h"
#include "../../matched/include/Obj05391.h"
#include "../../matched/include/Obj23144.h"
#include "../../matched/include/Obj10512.h"
#include "../../matched/include/Obj01256.h"
#include "../../matched/include/Obj23145.h"
#include "../../matched/include/Obj00112.h"
#include "../../matched/include/Obj01547.h"
#include "../../matched/include/Obj23146.h"
#include "../../matched/include/Obj23147.h"
#include "../../matched/include/Obj00091.h"
#include "../../matched/include/Obj03816.h"
#include "../../matched/include/Obj05392.h"
#include "../../matched/include/Obj04509.h"
#include "../../matched/include/Obj10514.h"
#include "../../matched/include/Obj10515.h"
#include "../../matched/include/Obj23148.h"
#include "../../matched/include/Obj05393.h"
#include "../../matched/include/Obj02845.h"
#include "../../matched/include/Obj01548.h"
#include "../../matched/include/Obj23149.h"
#include "../../matched/include/Obj23150.h"
#include "../../matched/include/Obj04510.h"
#include "../../matched/include/Obj23151.h"
#include "../../matched/include/Obj23152.h"
#include "../../matched/include/Obj06484.h"
#include "../../matched/include/Obj10516.h"
#include "../../matched/include/Obj10517.h"
#include "../../matched/include/Obj10518.h"
#include "../../matched/include/Obj23153.h"
#include "../../matched/include/Obj08147.h"
#include "../../matched/include/Obj23154.h"
#include "../../matched/include/Obj23156.h"
#include "../../matched/include/Obj03815.h"
#include "../../matched/include/Obj02484.h"
#include "../../matched/include/Obj23157.h"
#include "../../matched/include/Obj05394.h"
#include "../../matched/include/Obj06485.h"
#include "../../matched/include/Obj23158.h"
#include "../../matched/include/Obj02189.h"
#include "../../matched/include/Obj14075.h"
#include "../../matched/include/Obj23159.h"
#include "../../matched/include/Obj00502.h"
#include "../../matched/include/Obj05395.h"
#include "../../matched/include/Obj02190.h"
#include "../../matched/include/Obj00344.h"
#include "../../matched/include/Obj01939.h"
#include "../../matched/include/Obj05396.h"
#include "../../matched/include/Obj04511.h"
#include "../../matched/include/Obj04512.h"
#include "../../matched/include/Obj14076.h"
#include "../../matched/include/Obj10519.h"
#include "../../matched/include/Obj10520.h"
#include "../../matched/include/Obj00536.h"
#include "../../matched/include/Obj23161.h"
#include "../../matched/include/Obj23162.h"
#include "../../matched/include/Obj01061.h"
#include "../../matched/include/Obj01408.h"
#include "../../matched/include/Obj04513.h"
#include "../../matched/include/Obj23163.h"
#include "../../matched/include/Obj23164.h"
#include "../../matched/include/Obj01940.h"
#include "../../matched/include/Obj02846.h"
#include "../../matched/include/Obj10521.h"
#include "../../matched/include/Obj10522.h"
#include "../../matched/include/Obj00026.h"
#include "../../matched/include/Obj00132.h"
#include "../../matched/include/Obj23165.h"
#include "../../matched/include/Obj23166.h"
#include "../../matched/include/Obj23167.h"
#include "../../matched/include/Obj23168.h"
#include "../../matched/include/Obj23169.h"
#include "../../matched/include/Obj23171.h"
#include "../../matched/include/Obj06486.h"
#include "../../matched/include/Obj10523.h"
#include "../../matched/include/Obj03286.h"
#include "../../matched/include/Obj10524.h"
#include "../../matched/include/Obj01409.h"
#include "../../matched/include/Obj23172.h"
#include "../../matched/include/Obj02847.h"
#include "../../matched/include/Obj23173.h"
#include "../../matched/include/Obj14077.h"
#include "../../matched/include/Obj14078.h"
#include "../../matched/include/Obj14080.h"
#include "../../matched/include/Obj01549.h"
#include "../../matched/include/Obj06487.h"
#include "../../matched/include/Obj06488.h"
#include "../../matched/include/Obj10527.h"
#include "../../matched/include/Obj02191.h"
#include "../../matched/include/Obj08149.h"
#include "../../matched/include/Obj23174.h"

#define H (*(u16 *)p)
#define I(k) (*(int *)(p+(k)))
#define P(k) (*(void **)(p+(k)))
struct Mon;
struct Context;
struct Node;
struct Actor;
struct McssSys;
struct Obj;
struct PrintSys;
struct W;
struct DispVram;
struct DispConfig;
struct Bank;
struct Light;
struct BgConfig;
struct BgTemplate;
struct S;
struct GfFont;
struct MsgBank;
struct Rec;
struct Sav;
struct U16Vec;
struct Descriptor_021D4240;
struct WordSet;
struct StrObj;
struct Obj0203159C;
struct Party;
struct PartyMon;
struct S020315D4;
struct Personal;
struct Cfg;
struct Sub0204A9D0;
struct Struct36;
struct Vec2;
struct Bmp;
struct S_021D8884;
struct Obj020437AC;
struct CharBuf;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef signed short s16_021D4240;

struct BgConfig {u32 w[8];};

struct Cfg {u32 w[4];u16 h[6];};

struct Vec3 {u32 x,y,z;};

typedef enum {GX_DISP_SELECT_SUB_MAIN=0, GX_DISP_SELECT_MAIN_SUB=1} GXDispSelect;

struct Bytes { u8 v[8]; };

struct Desc_021D4240 {u16 x,y,z;u8 kind,flag;};

struct Context {u8 prefix[0x100];u8 rest[0x74];void *bank;void *actors[8];};

typedef struct { u16 pad[9]; u16 x,y; } Palette;

struct Rect36 { unsigned char b[36]; };

typedef signed char s8;

struct Col4 { u16 c[4]; };

struct W {
    char pad[0x1a4];
    u16 ang;
    u16 x4[4];
    u16 pal4[4];
    u16 a16[16];
    u16 b16[16];
    u16 o16[16];
    u16 o3[16];
    u16 i3[16];
};

struct Src { int v; int pad[2]; unsigned char kind; };

typedef signed short s16_021D62B4;

typedef struct {u16 v[5];} Moves;

typedef unsigned long long u64;

typedef short s16_021D6614;

typedef struct {int x,y,z;} Vec_021D62B4;

typedef struct {int v[2];} Pair_021D4240;

typedef struct {u16 x,y,z;u8 priority,flags;} ObjPos;

typedef struct {u32 x,y,z;} Vec_021D697C;

typedef struct {int x,y,z;} Vec;

typedef struct {u8 b[12];} Rects;

typedef enum { D0,D1,D2,D3,D4 } Direction;

typedef enum { F0,F1 } Flag;

struct hdr_021D4240 { u8 f0,f1,f2,f3; int f4; };

typedef struct { u8 pad[0x94]; u8 ring[5]; u8 f99,f9a; } Ring_021D4240;

typedef signed short s16_021D77E8;

struct hdr_021D77E8 {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    int f4;
};

typedef struct
{
    u8 pad[0x94];
    u8 ring[5];
    u8 f99;
    u8 f9a;
} Ring_021D77E8;

typedef struct { u32 x,y,z; } Vec_021D77E8;

typedef struct {int x,y,z;} Vec_021D79A8;

struct Rec { u32 w[9]; };

struct Point_021D4240 { s16_021D77E8 x,y; };

typedef short s16_021D7E84;

struct Tbl6 { u32 v[6]; };

struct Tbl36 { u8 v[6][6]; };

struct S_021D8784 { u32 a; u32 pad[19]; void *f50; u32 pad2[3]; unsigned char b60; };

struct S_021D8884 { u32 a; u32 p1[10]; void *f2c; u32 p2; void *f34; u32 p3; void *f3c; u32 p4; void *f44; u32 p5; void *f4c; u32 p6[7]; void *f6c; };

enum E {E_0};

struct Grid {void *f0;u16 f4;s16_021D4240 f6;u32 f8;u32 f12;u8 f16;u8 f17;u16 f18;u32 f20;};

struct OamEntry { unsigned char p[0x7c]; void *f7c; void *f80; unsigned char q[0x14 - 0x8]; };

typedef struct {
    u8 x;
    u8 y;
    u8 w;
    u8 h;
} Rect;

typedef struct { u16 x; u16 y; } Point_021D89FC;

struct Entry_021D4240 { u16 id; u8 gap[14]; u8 *object; };

struct List { u8 gap[0x70]; struct Entry_021D4240 entries[10]; };

struct Counts { u8 value[5]; };

typedef struct {u32 w[9];} Rec;

typedef struct {s16_021D4240 x,y;} Point_021D9EF0;

typedef struct { u32 w[9]; } Record;

typedef struct { void *bmp; s16_021D4240 x,y; void *resource; u32 value; u8 a,b; u16 c; u32 d; } Descriptor_021D4240;

struct Vec2 { s16_021D4240 x,y; };

struct Point_021D89FC { s16_021D4240 x,y; };

typedef short s16_021DB7B8;

typedef struct {void *pixels;u16 width,height,depth,kind;} Bmp;

typedef struct {Bmp *bmp;s16_021DB7B8 x,y;u32 resource,value;u8 a,b;u16 c;u32 d;} Descriptor_021DB7B8;

typedef struct {u8 x,y;} Pair_021DB7B8;

struct S { u32 f0; u16 f4; u16 pad; int f8[3]; };

typedef signed short s16;

struct Desc_021DBA54 {s16 x,y;u16 z;u8 kind,flag;};

struct Point { s16 x, y; };

struct Entry_021DBA54 { u32 a; u16 b, c, d, e; u8 f; u8 pad[3]; };

extern u8 func_020355C4(void);
extern void *func_0201747C(struct Mon *p, u32 heap);
extern void *func_020056A0(u32,u32,u32);
extern void func_02082A60(const void *,void *,u32);
extern int func_02012BF8(int a0, int a1);
extern void func_0203D34C(u32,u32);
extern void func_02030EAC(struct Node *n);
extern void func_02012BE0(void *p, u32 a, u32 b);
extern void func_020355D8(u8);
extern u32 func_020307B0(void *p);
extern u32 func_02035CB8(u32 *,u32 *);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void);
extern u32 func_0204B98C(struct Actor *a);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0204A600(void);
extern void func_02014C08(char *);
extern void func_02047964(void);
extern void func_020479D8(void);
extern void func_02014D2C(struct McssSys *sys);
extern void func_02047970(void);
extern void func_02041EE4(u32,u32,u32);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204A648(void);
extern void func_020434CC(void),func_02043588(void);
extern void func_0202223C(u32,u32);
extern u32 func_02022224(void *);
extern void func_020433E0(const struct DispVram *);
extern void func_0203F8F4(u16),func_02045088(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_02040588(unsigned int which, unsigned char enable);
extern void func_0207D63C(u32 *,u32,u32,u32,u32);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32,u32),func_02043598(u32,u32);
extern void func_02046440(u32,u32,u32,u32,u16,u16,void (*)(void));
extern u32 *func_02048A24(u32,u32,u32,u32,u32,u32,u32,u32,struct Vec3 *,struct Vec3 *,struct Vec3 *,u16);
extern void func_02048AD0(struct Light *l);
extern void func_0207DCF8(const void *);
extern void func_02046BE0(u32,u32),func_0204044C(u32);
extern void *func_02014B08(u32,void *);
extern void func_02016020(void *,u32);
extern void func_020160C0(char *p, unsigned int v);
extern void func_02061C30(void);
extern void func_02014BA8(u8 *a0);
extern unsigned int func_02048AC4(void *ptr);
extern void func_02046788(void);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_020403F4(unsigned int);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern int func_0204AC18(void *,u32,u32,u32,u16,u16,u16);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02049238(void *);
extern u32 func_020275E4(void);
extern u32 func_020275E8(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern u32 func_020275FC(u32);
extern u32 func_02027600(u32);
extern u32 func_020275F8(u32);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern int func_02027768(void);
extern int func_0202776C(int);
extern int func_02027770(int);
extern int func_02027774(int);
extern u32 func_020276B4(void);
extern u32 func_020276B8(void);
extern u32 func_020276BC(u32);
extern u32 func_020276C0(u32);
extern int func_02027720(int);
extern int func_0202772C(int);
extern int func_02027738(int,int);
extern int func_02027740(int,int);
extern int func_02027748(void);
extern int func_0202774C(int);
extern int func_02027750(int);
extern int func_02027754(int);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void *func_0201C450(u16,u32);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern int func_02035C08(const void *key);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern unsigned int func_0203633C(void);
extern u32 func_020362DC(void);
extern void func_020061E4(u32);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void func_02017528(struct Sav *p);
extern u32 func_02017E88(void *p, int id, void *v);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02006BB4(u32);
extern void func_02006CAC(void **);
extern u32 func_02006984(u32,u32,u32,u32,u32,u32,u32,u32);
extern void *func_020185F0(void *);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_020173E8(void);
extern u32 func_02017D30(struct Sav *p);
extern u32 func_02017D70(struct Sav *p, u32 f);
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02045770(struct Descriptor_021D4240 *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0203064C(unsigned int,unsigned int,unsigned int);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,int);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0203630C(void);
extern struct Party *func_0201A920(u32 heap);
extern void func_0201A954(struct Party *p, s32 capacity);
extern void *func_020173F0(u16,u16,u32,u32,u32);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_02017550(struct Sav *p);
extern u32 func_02005728(u32 range);
extern void func_02017600(void *obj,u16 species,u16 level,u64 id);
extern void func_02017E64(void *p, u32 id, u32 v);
extern void *func_020124F4(u16);
extern void func_02012704(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_02015EB0(void *);
extern void func_02015EA0(void *);
extern void func_02015C78(void *p, u32 *src);
extern void func_02015D30(void *p, u32 *src);
extern void func_02048AFC(void *,const Vec_021D62B4 *);
extern int func_0201ACC4(void *p, u32 pos);
extern void *func_0201ADE4(u32,int,u32);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045334(struct Descriptor_021D4240 *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor_021D4240 *p);
extern void func_02041B6C(u32);
extern void *func_02049F34(u32,u32,u32,u32);
extern void *func_02049DB4(u32,u32,u32,u32,u16);
extern void func_0204ADEC(u32,void *,u32);
extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern u32 func_0201B28C(void *);
extern u32 func_02017EB4(void *);
extern u32 func_02017F90(void *);
extern int func_020276C4(int a0);
extern u32 func_0201B268(void *);
extern void func_0201ACDC(void *p, u32 pos, u32 mode);
extern u32 func_020452E8(struct Descriptor_021D4240 *d);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02018438(void *);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_02015E4C(void *);
extern void func_02015C48(void *,u32 *);
extern int _ffix(float);
extern void func_02015E04(void *);
extern int func_02035C60(void);
extern int func_02035C38(void);
extern int func_02035BA4(const void *);
extern void *func_02017270(void *a0, void *a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern void func_02015FD4(char *,int);
extern void func_02015D80(u8 *,u16);
extern void func_020173B4(void *);
extern void func_02015CDC(void *,u32 *);
extern void func_02015BA4(void *,void *);
extern void func_0207C9D0(Vec *,Vec *,Vec *);
extern void func_02015D94(char *p, int *src);
extern u16 *func_0201AF80(u32 heap, u16 *countOut);
extern void *func_02049EF4(void *, unsigned int, unsigned int, void **, unsigned short);
extern void func_020410D0(u32,u32,u32,u32,u8,u32,u8,u8,u8,u8);
extern void func_02040AE0(u32 index, const void *src, u32 mode);
extern void func_0204AB84(u32,struct Rec *);
extern void func_0204B784(char *dst, const struct Struct36 *src);
extern u8 func_020275EC(int i);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B84C(void *,u32);
extern void func_02041300(unsigned int, int, int, int, unsigned char, unsigned char, unsigned char);
extern void func_02041570(int channel, u16 val);
extern u32 func_02018584(u16,u16,u16);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern int func_0202F498(void *a0, int a1);
extern u8 *func_02012944(void *p);
extern u32 func_02018488(void *, void *);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern u32 sub_0201D2C8(struct StrObj *s);
extern unsigned int func_0202F688(unsigned int);
extern unsigned int func_0202F6D8(unsigned int);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern struct Bmp *func_02043754(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern void func_020437AC(struct Obj020437AC *p);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02082D44(const void *,void *,u32);
extern void func_0201DD78(u32,u32,u32);
extern void func_0201C7A4(void *,s16_021D4240,s16_021D4240,void *,void *);
extern void func_0201DD68(void);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_0200616C(void *,int);
extern unsigned int func_021DBF94(int i);
extern void func_02045798(struct Descriptor_021D4240 *p, u8 v);
extern void func_020409E0(u32,const void *,u32,u32);
extern int func_0202D034(u32 a, u32 b);
extern u8 func_0202D01C(u32 a, u32 b, u32 c);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern int func_0201C1E8(int a);
extern u8 func_02027604(u8);
extern u32 func_0201C1D8(u16);
extern u32 func_0201BD28(u16,u32);
extern u32 func_0201C1F4(u16 id);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_0204B9A0(struct Actor *);
extern u32 func_0202F72C(void *,u16,u16);
extern void func_020181FC(void *,u16,u32);
extern s8 func_02019B44(u32 a, u32 n);
extern int func_0201C1C8(u16);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern u32 func_020437EC(const struct Bmp *bmp);
extern void func_020862F0(void *,int);
extern int func_0204ABBC(u32 idx, u32 flag);
extern void func_0207E780(void *,void *,u32);
extern void func_0207E804(void *,void *,u32);
int func_021D4240(char *p);
int func_021D4418(char *p);
int func_021D44C8(char *p);
void func_021D46E4(void);
void func_021D46EC(char *p);
void func_021D48E4(char *p);
void func_021D4940(struct BgConfig *cfg,u32 bg,u32 mode);
void func_021D4964(u8 *p);
void func_021D4F24(char *p);
void func_021D4FBC(struct Context *ctx);
void func_021D5180(char *p);
void func_021D51DC(char *p);
void func_021D5258(char *p);
void func_021D5280(char *p);
void func_021D52A8(char *p);
int func_021D52D4(char *p);
void func_021D54A8(char *p);
s32 func_021D5650(struct W *p);
void func_021D5A9C(char *p,int a);
int func_021D5B58(unsigned char *p,int a);
int func_021D5BAC(unsigned char *p,int direction,unsigned short *out);
void func_021D5C4C(unsigned char *p);
void func_021D5C98(u8 *p);
void func_021D5DC4(u8 *p);
void *func_021D6064(unsigned char *p);
int func_021D60A4(char *p);
void func_021D60D4(unsigned char *p,int a);
void func_021D614C(unsigned char *p,int a,int b,int c,unsigned short d,unsigned short e);
void func_021D618C(unsigned char *p,unsigned int a,int b,int c,unsigned short d,unsigned short e);
void func_021D61B8(unsigned char *p,int a,void *b,int c,unsigned short d,unsigned short e,unsigned short f);
void func_021D6214(unsigned char *p,unsigned int a,void *b,int c,unsigned short d,unsigned short e,unsigned short f);
void func_021D6244(unsigned char *p,int a,void *b,int c,unsigned short d,unsigned short e,unsigned short f);
void func_021D62B4(unsigned char *p,unsigned int a,void *b,int c,unsigned short d,unsigned short e,unsigned short f);
int func_021D62E4(char *p);
int func_021D62F4(char *p, void *q);
int func_021D6324(u32 heap,int *st,u8 *obj,char *d);
int func_021D657C(struct S020315D4 *handle, int unused, int mode, char *p);
int func_021D65BC(int a, int b, int c, int d);
void *func_021D65D8(u16 *a);
void func_021D6608(void *a,void *b);
void func_021D6614(u8 *a,u8 *p);
void func_021D67EC(u16 *p, int a, void *b);
void func_021D6808(void *a,void *b);
void func_021D6810(u8 *a,u8 *p);
void func_021D694C(void *a,unsigned char *p);
void func_021D697C(unsigned char *p,int *q);
void func_021D6A38(u8 *p,u8 *q);
void func_021D6CDC(unsigned char *a,unsigned char *b);
void func_021D6D04(void *a, u8 *p);
void func_021D6D18(u8 *p,u8 *q,void *mon);
void func_021D6F54(u8 *p,u8 *q);
void func_021D703C(void *unused,u8 *q);
int func_021D7060(void *unused,u8 *q,u8 *counter);
int func_021D708C(u8 *p,u8 *q);
int func_021D7248(unsigned char *p,unsigned char *q);
int func_021D72E8(u8 *p,u8 *q,int mode);
void func_021D7460(u8 *a,u8 *p);
void func_021D75A4(int a,u8 *p);
void func_021D77E8(u8 *p, u32 a, u32 b);
void func_021D77F8(struct hdr_021D77E8 *p, u32 a, u32 b, int c);
void func_021D7810(int unused, Ring_021D77E8 *p, int mode);
void func_021D785C(u8 *p,u8 *q,void *mon);
void func_021D797C(unsigned char *p,void **q);
void func_021D79A8(void *p,unsigned char *q,int radius);
void func_021D7A1C(void *p,void **q,Vec *v);
void func_021D7A44(void *p,int unused,int *a,int *b);
void **func_021D7B00(u16 *a);
void func_021D7B34(int a, char *p);
void func_021D7B48(void *context, void *child);
void func_021D7B4C(unsigned char *a, unsigned char *p, void *arc);
void func_021D7BF0(void *a, unsigned char *p);
void func_021D7C38(void *a, unsigned char *p);
void func_021D7CAC(u8 *a,u8 *p);
void func_021D7E84(void *p,void **q);
void func_021D7EAC(unsigned char *p, void *a1);
void func_021D7F04(u8 *p,u8 *q,void *mon);
void func_021D8288(u8 *a, u8 *p, void *mon);
void *func_021D8784(void *a, unsigned char *p, unsigned int n);
void *func_021D87E0(u16 *a);
void func_021D881C(void *a, u8 *p);
void func_021D8830(unsigned char *a, unsigned char *p);
void func_021D8884(unsigned char *a, unsigned char *p, void *arc);
void func_021D8904(void *a, struct S_021D8884 *s);
void func_021D8938(u8 *a,u8 *p);
void func_021D89FC(void *unused, unsigned char *s);
void func_021D8A2C(u8 *a,u8 *p);
int func_021D8AD0(u8 *a,u8 *p);
void func_021D8CD0(u8 *a,u8 *p);
int func_021D8E24(void *unused, u8 *p);
void func_021D8EA8(u8 *a,u8 *p);
void func_021D8ED0(u8 *a,u8 *p,u8 n);
void func_021D8F0C(void *unused, unsigned char *p, int delta);
void func_021D8F50(void *a, unsigned char *p);
void func_021D8FAC(u8 *a,u8 *p);
void func_021D909C(u8 *a,u8 *p);
void func_021D90C0(unsigned char *a, unsigned char *p);
void func_021D911C(u8 *a,u8 *p);
void func_021D91EC(void *a0, void *a1);
void func_021D91F0(u8 *a,u8 *p,u8 *entry);
void func_021D92B0(u8 *a,u8 *p);
u32 func_021D93E4(u8 *p, u32 target);
unsigned int func_021D9428(unsigned char *p, unsigned int target);
s16_021D4240 func_021D9440(u8 *p, u32 target);
void func_021D949C(u8 *a,u8 *p);
void func_021D9568(u8 *a,u8 *p);
void func_021D964C(u8 *a,u8 *p);
void func_021D9670(u8 *a,u8 *p);
u8 *func_021D96B0(u8 *a);
void func_021D9734(u8 *a,u8 *p);
void func_021D9740(u8 *a,u8 *p);
void func_021D9980(u8 *a,u8 *p,void *resource);
void func_021D9A04(u8 *a, u8 *p);
void func_021D9A4C(u8 *a,u8 *p);
void func_021D9BD4(void *a, u8 *p);
void func_021D9C3C(void *a,u8 *p);
void func_021D9CD0(u8 *a,u8 *p);
void func_021D9D44(void *a, u8 *p);
void func_021D9D94(u8 *a,u8 *p);
void func_021D9E30(void *a, int b);
void func_021D9E44(u8 *a,u8 *p);
void func_021D9EE8(u8 *a,u8 *p);
void func_021D9EF0(u8 *a,u8 *p);
void func_021DA0B0(u8 *a,u8 *p);
void func_021DA3FC(u8 *a,u8 *b);
void func_021DA488(u8 *a,u8 *p);
void func_021DA6A4(u8 *a,u8 *p);
void func_021DA7A4(u8 *a,u8 *b);
void func_021DA84C(u8 *a,u8 *b);
void func_021DA8BC(u8 *a,u8 *b);
void func_021DA958(u8 *a,u8 *b);
int func_021DA998(u8 *a,u8 *b);
void func_021DABCC(u8 *a,u8 *b);
int func_021DAEE4(u8 *a,u8 *p);
void func_021DB140(u8 *a,u8 *b);
void func_021DB3F0(u8 *a,u8 *b);
void func_021DB468(u8 *a,u8 *b,u8 c,int d);
void func_021DB508(u8 *p,u8 *q,u32 a,u32 b);
void func_021DB614(void *a,u8 *b,int c);
void func_021DB688(u8 *a,u8 *b,int c);
u16 func_021DB6D0(u32 a, u32 b, unsigned char c, u32 d);
void func_021DB700(u8 *a,void *b,u8 *p,u8 i);
void func_021DB7B8(void *a, void *b, u8 *p);
void func_021DB7D0(void *a0, void *a1, void *a2);
void func_021DB7D4(u8 *p,u8 *q,u8 *entry);
void func_021DB964(u8 *a,void *b,u8 *p);
void func_021DB9E8(void *a, void *b, u8 *p);
void func_021DB9FC(void *a, void *b, u8 *p);
void func_021DBA14(u8 *a,u8 *b);
void func_021DBA54(unsigned char *p, unsigned short *o);
void func_021DBA78(u8 *p, int i);
struct S *func_021DBA90(u32 a, u32 b);
void func_021DBAC0(u8 *p);
u8 *func_021DBAD0(u8 *a,const u8 *b);
void func_021DBC3C(u8 *p);
void func_021DBCA4(u8 *p, int v);
void func_021DBCF4(u8 *p);
void func_021DBE2C(u8 *p, s16 x, s16 y);
void func_021DBE98(int *a, int *b);
int func_021DBEA4(u8 *p, int screen, u32 owner);
void func_021DBF0C(int *p);
u32 func_021DBF2C(u32 i, u32 field);
extern const struct DispVram g_C0E4;
extern struct DispConfig g_BFF4;
extern struct BgConfig g_C004[7];
extern struct Cfg g_1448;
extern struct Vec3 g_BFC0[3];
extern u16 g_BFE4[8];
extern struct Bytes g_BFA0[3];
extern const struct Rect36 d_021DC114;
extern const struct Col4 d_021DBFA8;
extern const struct Col4 d_021DBFB8;
extern const s16_021D4240 FX_SinCosTable_[];
extern const char d_021DC80C[];
extern const Moves d_021DC138;
extern const Moves d_021DC144;
extern const char d_021DC818[];
extern const s16_021D6614 d_020A1B38[];
extern const Vec_021D62B4 d_021DC234;
extern const Vec_021D62B4 d_021DC228;
extern const Vec_021D62B4 d_021DC198;
extern const Vec_021D62B4 d_021DC210;
extern const Pair_021D4240 d_021DC170;
extern const Pair_021D4240 d_021DC178;
extern const Pair_021D4240 d_021DC168;
extern const u8 d_021DC158[];
extern const u8 d_021DC160[];
extern const Vec_021D697C d_021DC204;
extern const Vec_021D697C d_021DC21C;
extern const Vec_021D697C d_021DC1B0;
extern const Vec_021D697C d_021DC1A4;
extern const Vec_021D697C d_021DC18C;
extern const Vec_021D697C d_021DC1BC;
extern const Vec d_021DC1D4;
extern const Rects d_021DC1E0;
extern const Vec_021D77E8 d_021DC1F8;
extern const Vec_021D77E8 d_021DC240;
extern const Vec_021D77E8 d_021DC180;
extern const Vec_021D77E8 d_021DC1C8;
extern const Vec_021D79A8 d_021DC1EC;
extern const short d_020A5078[];
extern const char d_021DC824[];
extern const unsigned char d_021DC288[];
extern void *g_020A7370;
extern const u32 d_021DC24C[6];
extern const u8 d_021DC264[6][6];
extern const char d_021DC834[];
extern const struct Counts d_021DC2B0;
extern const char d_021DC844[];
extern const u8 d_021DC2C2[];
extern const u8 d_021DC2B8[][2];
extern const char d_021DC854[];
extern const struct Entry_021DBA54 d_021DC2F8[];












int func_021D4240(char *p)
{
    u8 i;
    ((struct Obj00238 *)p)->f18=(*(u8 **)(p+8))[15];
    ((struct Obj00238 *)p)->f1A=255;
    ((struct Obj00238 *)p)->f1B=0;
    ((struct Obj00238 *)p)->f20=*(u32 *)0x02fffc3c;
    ((struct Obj00238 *)p)->f5C=4;
    ((struct Obj00238 *)p)->f44=1;
    ((struct Obj00238 *)p)->f48=0;
    ((struct Obj00238 *)p)->f4C=0;
    ((struct Obj00238 *)p)->f54=0;
    ((struct Obj00238 *)p)->fC=1;
    ((struct Obj00238 *)p)->f25C=0;
    ((struct Obj00238 *)p)->f260=0;
    ((struct Obj00238 *)p)->f50=0;
    ((struct Obj00238 *)p)->f1A0=0;
    ((struct Obj00238 *)p)->f10=0;
    ((struct Obj00238 *)p)->f14=0;
    ((struct Obj00238 *)p)->f1C=func_020355C4();
    if ((*(u8 **)(p+8))[13]==3) {
        (*(u8 **)(p+8))[13]=2;
        ((struct Obj00238 *)p)->f14=1;
    }
    if ((*(u8 **)(p+8))[12]==2) ((struct Obj00238 *)p)->f258=func_0201747C(func_021D6064((u8 *)p),((struct Obj00238 *)p)->f0);
    else ((struct Obj00238 *)p)->f258=0;
    func_021D46EC(p);
    ((struct Obj00238 *)p)->f88=func_021D65D8((u16 *)p);
    ((struct Obj00238 *)p)->f8C=func_021D7B00((u16 *)p);
    ((struct Obj00238 *)p)->f90=func_021D96B0((u8 *)p);
    ((struct Obj00238 *)p)->f94=func_021D87E0((u16 *)p);
    func_021D4964((u8 *)p);
    func_021D51DC(p);
    func_021D4FBC((struct Context *)p);
    ((struct Obj00238 *)p)->f4=func_020056A0((u32)func_021D46E4,(u32)p,8);
    ((struct Obj00238 *)p)->f1A4=0;
    func_02082A60((void *)0x0500026c,p+0x1a6,12);
    func_02082A60((void *)0x05000360,p+0x1b6,64);
    func_02082A60((void *)0x050003a0,p+0x216,32);
    func_02082A60((void *)0x050003a0,p+0x236,32);
    func_021D5C4C((u8 *)p);
    if ((*(u8 **)(p+8))[13]==2) {
        ((struct Obj00238 *)p)->f58=3;
        func_021D697C((u8 *)p,*(int * *)&((struct Obj00238 *)p)->f88);
        func_021DA6A4((u8 *)p,((struct Obj00238 *)p)->f90);
        func_021D911C((u8 *)p,((struct Obj00238 *)p)->f94);
    } else {
        ((struct Obj00238 *)p)->f58=(*(u8 **)(p+8))[16];
        if (((struct Obj00238 *)p)->f58<3) {
            for(i=0;i<3;i++) *(int *)(p+0x60+i*4)=func_02012BF8((int)(((struct Obj23119 *)(*(char * *)&((struct Obj00238 *)p)->f8))->f8),i+7);
        }
        func_021D697C((u8 *)p,*(int * *)&((struct Obj00238 *)p)->f88);
        func_021D911C((u8 *)p,((struct Obj00238 *)p)->f94);
        switch (((struct Obj00238 *)p)->f58) {
        case 0: func_021D7C38(p,*(u8 * *)&((struct Obj00238 *)p)->f8C); break;
        case 1: func_021D9C3C(p,*(u8 * *)&((struct Obj00238 *)p)->f90); break;
        case 2: func_021D8F50(p,*(u8 * *)&((struct Obj00238 *)p)->f94); break;
        default: ((struct Obj00238 *)p)->f58=0;
            func_021D7C38(p,*(u8 * *)&((struct Obj00238 *)p)->f8C); break;
        }
    }
    func_0203D34C(1,((struct Obj00238 *)p)->f0);
    return 1;
}












/*
 * extent: Two zero alignment bytes at 0x021D44C6.
 */
int func_021D4418(char *p)
{
    u8 i;
    func_02030EAC(((struct Obj01255 *)p)->f4);
    (*(u8 **)(p+8))[15]=((struct Obj01255 *)p)->f18;
    func_021D5180(p);
    func_021D5258(p);
    func_021D4F24(p);
    func_021D91EC(p,((struct Obj01255 *)p)->f94);
    func_021D881C(p,*(u8 * *)&((struct Obj01255 *)p)->f94);
    func_021D9734((u8 *)p,((struct Obj01255 *)p)->f90);
    func_021D7B34((int)p,*(char * *)&((struct Obj01255 *)p)->f8C);
    func_021D6608(p,((struct Obj01255 *)p)->f88);
    func_021D48E4(p);
    if(((struct Obj01255 *)p)->f58<3){
        for(i=0;i<3;i++) func_02012BE0(((struct Obj23120 *)(*(char * *)&((struct Obj01255 *)p)->f8))->f8,i+7,*(int *)(p+i*4+0x60));
    }
    if(((struct Obj01255 *)p)->f14==1){
        (*(u8 **)(p+8))[13]=3;
        ((struct Obj01255 *)p)->f14=0;
    }
    func_020355D8(((struct Obj01255 *)p)->f1C);
    if(((struct Obj01255 *)p)->f258) func_020307B0(((struct Obj01255 *)p)->f258);
    return 1;
}












/*
 * interface: 02035CB8 writes fields only on success; their previous values
 *   remain initialized on failure. 021D5BAC guards a null output pointer.
 *   Tick difference is unsigned full-word arithmetic then byte truncation.
 *   Follower 021D46E4 is the complete eight-byte no-argument tail stub
 *   to owner 0204A648 (void(void)), with no return consumed.
 */
int func_021D44C8(char *p)
{
    u32 tick;
    ((struct Obj00035 *)p)->f30=((struct Obj00035 *)p)->f28;
    ((struct Obj00035 *)p)->f34=((struct Obj00035 *)p)->f2C;
    func_02035CB8((u32 *)(p+0x28),(u32 *)(p+0x2c));
    switch (*(u32 *)&((struct Obj00035 *)p)->f50) {
    case 0:
        if (((struct Obj00035 *)p)->fC==1) func_021D5DC4((u8 *)p);
        else {
            func_0202208C(0,1,1,0,6,1,((struct Obj00035 *)p)->f0);
            ((struct Obj00035 *)p)->f50=1;
        }
        break;
    case 1:
        if (func_020221A4()==1) ((struct Obj00035 *)p)->f50=4;
        break;
    case 2:
        if (((struct Obj00035 *)p)->f1A0==0 || func_0204B98C(((struct Obj00035 *)p)->f1A0)==0 || ((struct Obj23121 *)(*(char * *)&((struct Obj00035 *)p)->f8))->f24==1) {
            func_0202208C(0,0,0,0,6,1,((struct Obj00035 *)p)->f0);
            ((struct Obj00035 *)p)->f50=3;
        }
        break;
    case 3:
        if (func_020221A4()==1) return ((struct Obj00035 *)p)->f54;
        break;
    case 4:
        func_021D5280(p);
        if (((struct Obj00035 *)p)->fC==1) func_021D5DC4((u8 *)p);
        else {
            func_021D6614((u8 *)p,((struct Obj00035 *)p)->f88);
            if (((struct Obj23122 *)(*(char * *)&((struct Obj00035 *)p)->f8))->f24==1) {
                ((struct Obj00035 *)p)->f54=1;
                ((struct Obj00035 *)p)->f50=2;
            }
            func_021D52A8(p);
            if (((struct Obj00035 *)p)->fC==0) {
                switch (((struct Obj00035 *)p)->f5C) {
                case 0: func_021D7B48(p,((struct Obj00035 *)p)->f8C); break;
                case 1:
                case 3: func_021D9740((u8 *)p,((struct Obj00035 *)p)->f90); break;
                case 2: func_021D8830((u8 *)p,*(u8 * *)&((struct Obj00035 *)p)->f94); break;
                }
            }
        }
        break;
    }
    func_0201C4E4(((struct Obj00035 *)p)->f84);
    func_0204A600();
    func_02014C08(*(char * *)&((struct Obj00035 *)p)->f78);
    func_02047964();
    func_020479D8();
    func_02014D2C(((struct Obj00035 *)p)->f78);
    func_02047970();
    tick=*(u32 *)0x02fffc3c;
    ((struct Obj00035 *)p)->f1B+=(u8)(tick-((struct Obj00035 *)p)->f20);
    ((struct Obj00035 *)p)->f20=tick;
    while (((struct Obj00035 *)p)->f1B>=4) {
        func_02041EE4(3,1,1);
        func_02041EE4(3,4,1);
        func_02041EE4(7,1,1);
        func_02041EE4(7,4,1);
        ((struct Obj00035 *)p)->f1B-=4;
    }
    if (((struct Obj00035 *)p)->f48==1 && func_0204B98C(((struct Obj00035 *)p)->f188)==0) {
        if (func_021D5BAC((u8 *)p,0,0)==1) func_0204B878(((struct Obj00035 *)p)->f188,3);
        else func_0204B878(((struct Obj00035 *)p)->f188,17);
        ((struct Obj00035 *)p)->f48=0;
    }
    if (((struct Obj00035 *)p)->f4C==1 && func_0204B98C(((struct Obj00035 *)p)->f18C)==0) {
        if (func_021D5BAC((u8 *)p,1,0)==1) func_0204B878(((struct Obj00035 *)p)->f18C,2);
        else func_0204B878(((struct Obj00035 *)p)->f18C,16);
        ((struct Obj00035 *)p)->f4C=0;
    }
    func_021D5650((struct W *)p);
    return 0;
}












void func_021D46E4(void) { func_0204A648(); }












static inline void GX_SetVisiblePlane(int plane)
{ *(volatile u32 *)0x04000000=(u32)((*(volatile u32 *)0x04000000 & ~0x1f00) | (plane<<8)); }












static inline void GXS_SetVisiblePlane(int plane)
{ *(volatile u32 *)0x04001000=(u32)((*(volatile u32 *)0x04001000 & ~0x1f00) | (plane<<8)); }












static inline void GX_SetDispSelect(GXDispSelect sel)
{ *(volatile u16 *)0x04000304=(u16)((*(volatile u16 *)0x04000304 & ~0x8000) | (sel<<15)); }












/*
 * interface: complete original 020160C0 bytes 41 64 70 47 store r1 at
 *   r0+0x44 and return. Caller supplies object and full word 0x10000.
 *   02046440 owner's s16_021D4240 heap is u16 here: original ldrh zero-extends its
 *   outgoing stack word. Lower 16-bit callee conversion remains unchanged.
 *   Config c initializes all 28 bytes before h[0] and consumer reads.
 * lever: game hardware writes use vendor visible-plane and enum display
 *   selection inlines; raw compound assignments change constant sharing.
 * witness: 020160C0 filed as src/matched/arm9/func_020160C0.c.
 * volatile: hardware DISPCNT/BLDCNT/POWCNT1/DISP3DCNT registers
 */
void func_021D46EC(char *p)
{
    struct Cfg c;
    func_020434CC();func_02043588();
    GX_SetVisiblePlane(0);GXS_SetVisiblePlane(0);
    func_0202223C(0,0);func_0202223C(1,0);
    func_02022224(0);func_02022224((void *)1);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    func_020433E0(&g_C0E4);
    func_0203F8F4(((struct Obj01739 *)p)->f0);func_02045088(((struct Obj01739 *)p)->f0);
    func_0203FC28(&g_BFF4);
    func_021D4940(&g_C004[6],1,0);func_021D4940(&g_C004[4],2,0);func_021D4940(&g_C004[0],3,0);
    func_02040588(0,1);
    func_021D4940(&g_C004[1],4,0);func_021D4940(&g_C004[2],5,0);func_021D4940(&g_C004[3],6,0);func_021D4940(&g_C004[5],7,0);
    func_0207D63C((u32 *)0x04000050,4,30,13,16);
    func_0207D63C((u32 *)0x04001050,4,8,13,16);
    c=g_1448;c.h[0]=110;
    func_0204A48C(&c,(u32)(&g_C0E4),((struct Obj01739 *)p)->f0);
    ((struct Obj01739 *)p)->f174=func_0204B100(96,0,((struct Obj01739 *)p)->f0);
    func_0204B270(((struct Obj01739 *)p)->f174);
    func_020434DC(16,1);func_02043598(16,1);
    func_02046440(0,2,0,1,0,((struct Obj01739 *)p)->f0,0);
    *(u32 * *)&((struct Obj01739 *)p)->f70=func_02048A24(2,0xc0000,0,0,0x100000,0x80000,0x200000,0,&g_BFC0[0],&g_BFC0[2],&g_BFC0[1],((struct Obj01739 *)p)->f0);
    func_02048AD0(((struct Obj01739 *)p)->f70);
    func_0207DCF8(g_BFE4);
    *(volatile u16 *)0x04000060 &= ~0x3020;
    func_02046BE0(0,0);func_0204044C(0);
    ((struct Obj01739 *)p)->f78=func_02014B08(2,(void *)((struct Obj01739 *)p)->f0);
    func_02016020(((struct Obj01739 *)p)->f78,0);
    func_020160C0(((struct Obj01739 *)p)->f78,0x10000);
}
















/*
 * 2026-10-02 R3: closed by the arm9 witness src/matched/arm9/func_02061C30.c
 *   (the tail-call stub matches under ../2.0/sp2; see its header).
 * extent: Two zero padding bytes at 0x021D493E.
 */
void func_021D48E4(char *p)
{
    func_02061C30();
    func_02014BA8(((struct Obj10503 *)p)->f78);
    func_02048AC4(((struct Obj10503 *)p)->f70);
    func_02046788();
    func_0204B1CC(((struct Obj10503 *)p)->f174);
    func_0204A5AC();
    func_020403F4(5);
    func_020403F4(6);
    func_020403F4(7);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_020450C8();
    func_0203F9B4();
}
















void func_021D4940(struct BgConfig *cfg,u32 bg,u32 mode)
{
    func_0203FCA0(bg,(const struct BgTemplate *)cfg,mode);
    func_02040588(bg,1);
    func_020414AC(bg);
    func_020409B4(bg);
}
















/*
 * following: 0x021D4F22 is two bytes of alignment padding before func_021D4F24.
 * lever: the loop store associates (p+i*4)+0x130; the second constructor result after func_02027770/74 is stored at +0x120.
 * initialization: resource handles come from the original constructors; no uninitialized local or added success assumption. The u8 counter visits 0..16.
 */
void func_021D4964(u8 *p)
{
    u32 x, y;
    void *a;
    void *b;
    u8 i;
    a=func_020490F4(78,H);
    func_02049B68(a,0,0,0,0,H);
    func_02049658(a,8,2,0,0,0,H);
    func_020498F4(a,70,3,0,0,0,H);
    func_02049B68(a,1,4,0,0,H);
    func_02049658(a,10,6,0,0,0,H);
    func_02049658(a,9,5,0,0,0,H);
    func_020498F4(a,71,7,0,0,0,H);
    func_020498F4(a,65,5,0,0,0,H);
    I(0x98)=func_0204AC18(a,3,0,0,0,4,H);
    I(0xb0)=func_0204AC18(a,5,0,0x160,0,2,H);
    I(0xb4)=func_0204AC18(a,6,1,0,0,5,H);
    I(0xb8)=func_0204AC18(a,4,0,0x1a0,0,1,H);
    I(0xc4)=func_0204AC18(a,2,0,0x1c0,0,1,H);
    I(0xc8)=func_0204A6C8(a,11,0,0,H);
    I(0xe8)=func_0204A6C8(a,15,0,0,H);
    I(0xec)=func_0204A6C8(a,14,0,0,H);
    I(0xf8)=func_0204A6C8(a,13,0,0,H);
    I(0xfc)=func_0204AF28(a,78,129,H);
    I(0x118)=func_0204AF28(a,81,132,H);
    I(0x11c)=func_0204AF28(a,80,131,H);
    I(0x128)=func_0204AF28(a,82,133,H);
    I(0x12c)=func_0204AF28(a,79,130,H);
    b=func_020490F4(func_020275E4(),H);
    func_02049B68(b,func_02027624(),0,0x120,32,H);
    func_02049658(b,func_02027628(),1,0,0,0,H);
    func_020498F4(b,func_0202762C(),1,0,0,0,H);
    func_020413B0(1,0,21,32,3,9);
    func_02049B68(b,0,4,0x1a0,32,H);
    I(0xac)=func_0204AC18(b,1,1,0x100,0,1,H);
    I(0xe4)=func_0204A6C8(b,2,0,1,H);
    I(0x114)=func_0204AF28(b,5,8,H);
    I(0xa4)=func_0204AC18(b,func_020275E8(),0,0x100,0,3,H);
    I(0xa8)=func_0204AC18(b,func_020275E8(),1,0xa0,0,3,H);
    x=func_020275FC(2); y=func_02027600(2);
    I(0x10c)=func_0204AF28(b,x,y,H);
    x=func_020275FC(0); y=func_02027600(0);
    I(0x110)=func_0204AF28(b,x,y,H);
    for(i=0;i<17;i++) *(int *)(p+i*4+0x130)=func_0204A6C8(b,func_020275F8(i),0,0,H);
    I(0xd8)=func_0204A6C8(b,56,0,1,H);
    I(0xdc)=func_0204A6C8(b,57,0,1,H);
    I(0xe0)=func_0204A6C8(b,58,0,1,H);
    I(0xcc)=func_0204A6C8(b,func_02027618(),0,0,H);
    x=func_0202761C(2); y=func_02027620(2);
    I(0x100)=func_0204AF28(b,x,y,H);
    I(0xbc)=func_0204AC18(b,func_02027768(),0,0xa0,0,1,H);
    I(0xf0)=func_0204A6C8(b,func_0202776C(2),0,0,H);
    x=func_02027770(2); y=func_02027774(2);
    I(0x120)=func_0204AF28(b,x,y,H);
    I(0xa0)=func_0204AC18(b,func_02027748(),0,0xc0,0,1,H);
    I(0xd4)=func_0204A6C8(b,func_0202774C(2),0,0,H);
    x=func_02027750(2); y=func_02027754(2);
    I(0x108)=func_0204AF28(b,x,y,H);
    I(0xc0)=func_0204AC18(b,func_020276B4(),0,0x80,0,1,H);
    I(0xf4)=func_0204A6C8(b,func_020276B8(),0,0,H);
    x=func_020276BC(2); y=func_020276C0(2);
    I(0x124)=func_0204AF28(b,x,y,H);
    I(0x9c)=func_0204AC18(b,func_02027720(1),0,0xe0,0,1,H);
    I(0xd0)=func_0204A6C8(b,func_0202772C(1),0,0,H);
    x=func_02027738(1,2); y=func_02027740(1,2);
    I(0x104)=func_0204AF28(b,x,y,H);
    func_02049238(b);
    func_021D67EC((u16 *)p,I(0x88),a);
    func_021D7B4C(p,P(0x8c),a);
    func_021D9980(p,P(0x90),a);
    func_021D8884(p,P(0x94),a);
    func_02049238(a);
}
















/*
 * extent: Two trailing zero alignment bytes at 0x021D4FBA.
 */
void func_021D4F24(char *p)
{
    u8 i;
    func_021D8904(p,((struct Obj08143 *)p)->f94);
    func_021D9A04((u8 *)p,((struct Obj08143 *)p)->f90);
    func_021D7BF0(p,((struct Obj08143 *)p)->f8C);
    func_021D6808(p,((struct Obj08143 *)p)->f88);
    for(i=0;i<=11;i++) func_0204ADA4((u32)(*(void **)(p+i*4+0x98)));
    for(i=12;i<=24;i++) func_0204A8D4((u32)(*(void **)(p+i*4+0x98)));
    for(i=25;i<=37;i++) func_0204AFD8((u32)(*(void **)(p+i*4+0x98)));
    for(i=0;i<17;i++) func_0204A8D4((u32)(*(void **)(p+i*4+0x130)));
}
















/*
 * lever: real far bank/actor struct fields retain four offset spills.
 * interface: owner 0204B294 legacy void prototype tail-forwards allocator
 *   0204CFDC, whose full body returns an object pointer; caller consumes r0.
 *   All seven arguments preserve owner's full-word ids and u16 stack args.
 *   Descriptor_021D4240 x/y/z/kind/flag all initialize before any consumer call.
 *   Byte tables are consecutive records at witnessed base 021DBFA0.
 */
void func_021D4FBC(struct Context *ctx)
{
    char *p=(char *)ctx;
    struct Bytes z=g_BFA0[2];
    struct Bytes x=g_BFA0[0];
    struct Desc_021D4240 d;
    u8 i,j;
    u32 a,b;
    d.kind=10;d.flag=0;
    for(i=0;i<8;i++){
        if(i<=2){a=((struct Obj00591 *)p)->fC8;b=((struct Obj00591 *)p)->fFC;}
        else{a=((struct Obj00591 *)p)->fCC;b=((struct Obj00591 *)p)->f100;}
        d.x=x.v[i];d.y=(i==3)?172:168;d.z=z.v[i];
        ctx->actors[i]=func_0204B294(ctx->bank,a,((struct Obj00591 *)p)->f98,b,&d,0,((struct Obj00591 *)p)->f0);
        func_0204B92C(ctx->actors[i],1);
        func_0204B3DC(ctx->actors[i],1);
    }
    d.x=0;d.y=0;d.z=0;
    ((struct Obj00591 *)p)->f198=func_0204B294((void *)*(u32 *)&((struct Obj00591 *)p)->f174,((struct Obj00591 *)p)->f130,((struct Obj00591 *)p)->fA4,((struct Obj00591 *)p)->f10C,&d,0,((struct Obj00591 *)p)->f0);
    ((struct Obj00591 *)p)->f19C=func_0204B294((void *)*(u32 *)&((struct Obj00591 *)p)->f174,((struct Obj00591 *)p)->f130,((struct Obj00591 *)p)->fA4,((struct Obj00591 *)p)->f10C,&d,0,((struct Obj00591 *)p)->f0);
    for(j=0;j<2;j++)func_0204B3DC(*(void **)(p+0x198+j*4),0);
    if((*(u8 **)(p+8))[13]==2)for(i=0;i<8;i++)if(i!=7)func_0204B3DC(*(void **)(p+0x178+i*4),0);
    if(func_021D62E4(p)==0){func_0204B3DC(((struct Obj00591 *)p)->f190,0);func_0204B3DC(((struct Obj00591 *)p)->f184,0);}
    func_021D6810((u8 *)p,((struct Obj00591 *)p)->f88);
    func_021D8938((u8 *)p,((struct Obj00591 *)p)->f94);
    func_021D9A4C((u8 *)p,((struct Obj00591 *)p)->f90);
}
















void func_021D5180(char *p)
{
    u8 i;
    func_021D89FC(p,((struct Obj10504 *)p)->f94);
    func_021D9BD4(p,((struct Obj10504 *)p)->f90);
    func_021D694C(p,((struct Obj10504 *)p)->f88);
    for (i=0;i<8;i++) func_0204B3B4(*(void **)(p+i*4+0x178));
    for (i=0;i<2;i++) func_0204B3B4(*(void **)(p+i*4+0x198));
}
















void func_021D51DC(char *p)
{
    ((struct Obj03814 *)p)->f80=func_0201D7EC(23,0,0,0,((struct Obj03814 *)p)->f0);
    ((struct Obj03814 *)p)->f7C=func_02045B38(0,2,158,((struct Obj03814 *)p)->f0);
    func_02049B40(23,5,0,448,32,((struct Obj03814 *)p)->f0);
    func_02049B40(23,5,4,448,32,((struct Obj03814 *)p)->f0);
    {
        enum { COLOR=0x4e59 } color=COLOR;
        enum { BASE=0x050005c0 } base=BASE;
        ((Palette *)base)->x=color;
        ((Palette *)base)->y=0x6a52;
    }
    ((struct Obj03814 *)p)->f84=func_0201C450(4096,((struct Obj03814 *)p)->f0);
}
















void func_021D5258(char *p)
{
    func_0201C6EC(((struct Obj08144 *)p)->f84);
    func_0201C4C0(((struct Obj08144 *)p)->f84);
    func_02045C04(((struct Obj08144 *)p)->f7C);
    func_0201D83C(((struct Obj08144 *)p)->f80);
}
















void func_021D5280(char *p)
{
    struct Rect36 r = d_021DC114;
    ((struct Obj23123 *)p)->f24 = func_02035C08(&r);
}
















void func_021D52A8(char *p)
{
    if (((struct Obj00039 *)p)->f44 == 1 && func_0201C6B4(((struct Obj00039 *)p)->f84) == 1 && func_021D52D4(p) == 0) {
        func_021D54A8(p);
    }
}
















int func_021D52D4(char *p)
{
    int max;
    if (func_0203633C() & 0x80) {
        if (func_021D5B58((u8 *)p,1)==1) {
            func_021D5C98((u8 *)p);
            func_0204B878(((struct Obj00039 *)p)->f188,3);
            func_0204B878(((struct Obj00039 *)p)->f18C,10);
            ((struct Obj00039 *)p)->f48=0;
            ((struct Obj00039 *)p)->f4C=1;
            func_020061E4(1636);
            ((struct Obj00039 *)p)->f1C=0;
            return 1;
        }
    } else if (func_0203633C() & 0x40) {
        if (func_021D5B58((u8 *)p,0)==1) {
            func_021D5C98((u8 *)p);
            func_0204B878(((struct Obj00039 *)p)->f188,11);
            func_0204B878(((struct Obj00039 *)p)->f18C,2);
            ((struct Obj00039 *)p)->f48=1;
            ((struct Obj00039 *)p)->f4C=0;
            func_020061E4(1636);
            ((struct Obj00039 *)p)->f1C=0;
            return 1;
        }
    } else if (func_0203633C() & 0x10) {
        max=2;
        if (((struct Obj00039 *)p)->f40==0) max=1;
        if (((struct Obj00039 *)p)->f58<max && ((struct Obj00039 *)p)->f38==0) {
            ((struct Obj00039 *)p)->f58=(int)((u32)((struct Obj00039 *)p)->f58+1);
            func_021D5C98((u8 *)p);
            func_020061E4(1637);
            ((struct Obj00039 *)p)->f1C=0;
            return 1;
        }
    } else if (func_0203633C() & 0x20) {
        if (((struct Obj00039 *)p)->f58>0 && ((struct Obj00039 *)p)->f38==0) {
            ((struct Obj00039 *)p)->f58=(int)((u32)((struct Obj00039 *)p)->f58-1);
            func_021D5C98((u8 *)p);
            func_020061E4(1637);
            ((struct Obj00039 *)p)->f1C=0;
            return 1;
        }
    } else if (func_020362DC() & 2) {
        ((struct Obj00039 *)p)->f54=1;
        (*(u8 **)(p+8))[0x12]=1;
        ((struct Obj00039 *)p)->f50=2;
        func_0204B878(((struct Obj00039 *)p)->f194,9);
        ((struct Obj00039 *)p)->f1A0=((struct Obj00039 *)p)->f194;
        func_020061E4(1361);
        ((struct Obj00039 *)p)->f1C=0;
        return 1;
    } else if ((func_020362DC() & 0x400) && func_021D62E4(p)==1) {
        ((struct Obj00039 *)p)->f54=2;
        (*(u8 **)(p+8))[0x12]=2;
        ((struct Obj00039 *)p)->f50=2;
        func_0204B878(((struct Obj00039 *)p)->f190,8);
        ((struct Obj00039 *)p)->f1A0=((struct Obj00039 *)p)->f190;
        func_020061E4(1366);
        ((struct Obj00039 *)p)->f1C=0;
        return 1;
    } else if ((func_020362DC() & 0x800) && func_021D62E4(p)==1) {
        if (((struct Obj00039 *)p)->f58<3) {
            if (*(int *)((u32)p+0x60+(u32)((struct Obj00039 *)p)->f58*4)==1) {
                *(int *)((u32)p+0x60+(u32)((struct Obj00039 *)p)->f58*4)=0;
                func_0204B878(((struct Obj00039 *)p)->f184,6);
            } else {
                *(int *)((u32)p+0x60+(u32)((struct Obj00039 *)p)->f58*4)=1;
                func_0204B878(((struct Obj00039 *)p)->f184,7);
            }
            func_020061E4(1606);
            ((struct Obj00039 *)p)->f1C=0;
        }
        return 1;
    }
    return 0;
}
















/*
 * arithmetic: signed p+58 guard accepts negatives; scaled address uses
 *   unsigned 32-bit multiply/add for the original wrapping lsl/add sequence.
 */
void func_021D54A8(char *p)
{
    switch (((struct Obj00039 *)p)->f24) {
    case 0:
        if (((struct Obj00039 *)p)->f58!=0) {
            ((struct Obj00039 *)p)->f58=0;
            func_021D5C98((u8 *)p);
            func_020061E4(1637);
            ((struct Obj00039 *)p)->f1C=1;
        }
        break;
    case 1:
        if (((struct Obj00039 *)p)->f58!=1 && ((struct Obj00039 *)p)->f38==0) {
            ((struct Obj00039 *)p)->f58=1;
            func_021D5C98((u8 *)p);
            func_020061E4(1637);
            ((struct Obj00039 *)p)->f1C=1;
        }
        break;
    case 2:
        if (((struct Obj00039 *)p)->f58!=2 && ((struct Obj00039 *)p)->f38==0 && ((struct Obj00039 *)p)->f40==1) {
            ((struct Obj00039 *)p)->f58=2;
            func_021D5C98((u8 *)p);
            func_020061E4(1637);
            ((struct Obj00039 *)p)->f1C=1;
        }
        break;
    case 3:
        if (((struct Obj00039 *)p)->f58<3 && func_021D62E4(p)==1) {
            if (*(int *)((u32)p+0x60+(u32)((struct Obj00039 *)p)->f58*4)==1) {
                *(int *)((u32)p+0x60+(u32)((struct Obj00039 *)p)->f58*4)=0;
                func_0204B878(((struct Obj00039 *)p)->f184,6);
            } else {
                *(int *)((u32)p+0x60+(u32)((struct Obj00039 *)p)->f58*4)=1;
                func_0204B878(((struct Obj00039 *)p)->f184,7);
            }
            func_020061E4(1606);
            ((struct Obj00039 *)p)->f1C=1;
        }
        break;
    case 4:
        if (func_021D5B58((u8 *)p,0)==1) {
            func_021D5C98((u8 *)p);
            func_0204B878(((struct Obj00039 *)p)->f188,11);
            func_0204B878(((struct Obj00039 *)p)->f18C,2);
            ((struct Obj00039 *)p)->f48=1;
            ((struct Obj00039 *)p)->f4C=0;
            func_020061E4(1636);
            ((struct Obj00039 *)p)->f1C=1;
        }
        break;
    case 5:
        if (func_021D5B58((u8 *)p,1)==1) {
            func_021D5C98((u8 *)p);
            func_0204B878(((struct Obj00039 *)p)->f188,3);
            func_0204B878(((struct Obj00039 *)p)->f18C,10);
            ((struct Obj00039 *)p)->f48=0;
            ((struct Obj00039 *)p)->f4C=1;
            func_020061E4(1636);
            ((struct Obj00039 *)p)->f1C=1;
        }
        break;
    case 6:
        if (func_021D62E4(p)==1) {
            ((struct Obj00039 *)p)->f54=2;
            (*(u8 **)(p+8))[0x12]=2;
            ((struct Obj00039 *)p)->f50=2;
            func_0204B878(((struct Obj00039 *)p)->f190,8);
            ((struct Obj00039 *)p)->f1A0=((struct Obj00039 *)p)->f190;
            func_020061E4(1366);
            ((struct Obj00039 *)p)->f1C=1;
        }
        break;
    case 7:
        ((struct Obj00039 *)p)->f54=1;
        (*(u8 **)(p+8))[0x12]=1;
        ((struct Obj00039 *)p)->f50=2;
        func_0204B878(((struct Obj00039 *)p)->f194,9);
        ((struct Obj00039 *)p)->f1A0=((struct Obj00039 *)p)->f194;
        func_020061E4(1361);
        ((struct Obj00039 *)p)->f1C=1;
        break;
    }
}
















s32 func_021D5650(struct W *p)
{
    struct Col4 A;
    struct Col4 B;
    u16 ang;
    float t;
    u8 n_1;
    u16 ca_1, cb_1;
    s8 r_1, g_1, b_1;
    u16 ca_2, cb_2;
    s8 r_2, g_2, b_2;
    u16 ca_3;
    s8 r_3, g_3, b_3, r2_3, g2_3, b2_3;
    int IR_3, IG_3, IB_3;

    ang = p->ang;
    if (ang + 0x400 >= 0x10000) {
        p->ang = ang - 0xfc00;
    } else {
        p->ang = ang + 0x400;
    }
    A = d_021DBFA8;
    B = d_021DBFB8;
    t = (float)((FX_SinCosTable_[(p->ang >> 4) * 2] + 0x1000) / 2) / 4096.0f;

    for (n_1 = 0; n_1 < 4; n_1++) {
        ca_1 = A.c[n_1];
        r_1 = (s8)(ca_1 & 0x1f);
        g_1 = (s8)((ca_1 & 0x3e0) >> 5);
        b_1 = (s8)((ca_1 & 0x7c00) >> 10);
        cb_1 = B.c[n_1];
        r_1 = (s8)(int)((float)r_1 + t * (float)((s8)(cb_1 & 0x1f) - r_1));
        g_1 = (s8)(int)((float)g_1 + t * (float)((s8)((cb_1 & 0x3e0) >> 5) - g_1));
        b_1 = (s8)(int)((float)b_1 + t * (float)((s8)((cb_1 & 0x7c00) >> 10) - b_1));
        if (r_1 < 0) r_1 = 0;
        if (g_1 < 0) g_1 = 0;
        if (b_1 < 0) b_1 = 0;
        if (r_1 > 31) r_1 = 31;
        if (g_1 > 31) g_1 = 31;
        if (b_1 > 31) b_1 = 31;
        p->pal4[n_1] = (b_1 << 10) | ((g_1 << 5) | r_1);
    }
    func_02061CA4((void *)14, 0x6c, (u32)p->pal4, 8);

    for (n_1 = 0; n_1 < 16; n_1++) {
        ca_2 = p->a16[n_1];
        r_2 = (s8)(ca_2 & 0x1f);
        g_2 = (s8)((ca_2 & 0x3e0) >> 5);
        b_2 = (s8)((ca_2 & 0x7c00) >> 10);
        cb_2 = p->b16[n_1];
        r_2 = (s8)(int)((float)r_2 + t * (float)((s8)(cb_2 & 0x1f) - r_2));
        g_2 = (s8)(int)((float)g_2 + t * (float)((s8)((cb_2 & 0x3e0) >> 5) - g_2));
        b_2 = (s8)(int)((float)b_2 + t * (float)((s8)((cb_2 & 0x7c00) >> 10) - b_2));
        if (r_2 < 0) r_2 = 0;
        if (g_2 < 0) g_2 = 0;
        if (b_2 < 0) b_2 = 0;
        if (r_2 > 31) r_2 = 31;
        if (g_2 > 31) g_2 = 31;
        if (b_2 > 31) b_2 = 31;
        p->o16[n_1] = (b_2 << 10) | ((g_2 << 5) | r_2);
    }
    func_02061CA4((void *)14, 0x180, (u32)p->o16, 0x20);

    for (n_1 = 12; n_1 <= 14; n_1++) {
        ca_3 = p->i3[n_1];
        IR_3 = ca_3 & 0x1f;
        r_3 = (s8)IR_3;
        IG_3 = (ca_3 & 0x3e0) >> 5;
        g_3 = (s8)IG_3;
        IB_3 = (ca_3 & 0x7c00) >> 10;
        b_3 = (s8)IB_3;
        r2_3 = (s8)(IR_3 + 10);
        g2_3 = (s8)(IG_3 + 10);
        b2_3 = (s8)(IB_3 + 10);
        if (r2_3 > 31) r2_3 = 31;
        if (g2_3 > 31) g2_3 = 31;
        if (b2_3 > 31) b2_3 = 31;
        r_3 = (s8)(int)((float)r_3 + t * (float)(r2_3 - r_3));
        g_3 = (s8)(int)((float)g_3 + t * (float)(g2_3 - g_3));
        b_3 = (s8)(int)((float)b_3 + t * (float)(b2_3 - b_3));
        if (r_3 < 0) r_3 = 0;
        if (g_3 < 0) g_3 = 0;
        if (b_3 < 0) b_3 = 0;
        if (r_3 > 31) r_3 = 31;
        if (g_3 > 31) g_3 = 31;
        if (b_3 > 31) b_3 = 31;
        p->o3[n_1] = (b_3 << 10) | ((g_3 << 5) | r_3);
    }
    return func_02061CA4((void *)14, 0x1a0, (u32)p->o3, 0x20);
}
















void func_021D5A9C(char *p,int a)
{
    *(int *)&((struct Obj00136 *)p)->f44=a;
    if(a==0){
        func_0204B3DC(((struct Obj00136 *)p)->f178,0);
        func_0204B3DC(((struct Obj00136 *)p)->f17C,0);
        func_0204B3DC(((struct Obj00136 *)p)->f180,0);
        func_0204B3DC(((struct Obj00136 *)p)->f184,0);
        func_0204B3DC(((struct Obj00136 *)p)->f188,0);
        func_0204B3DC(((struct Obj00136 *)p)->f18C,0);
        func_0204B3DC(((struct Obj00136 *)p)->f190,0);
    }else{
        func_0204B3DC(((struct Obj00136 *)p)->f178,1);
        func_0204B3DC(((struct Obj00136 *)p)->f17C,1);
        if(((struct Obj00136 *)p)->f40==1) func_0204B3DC(((struct Obj00136 *)p)->f180,1);
        func_0204B3DC(((struct Obj00136 *)p)->f188,1);
        func_0204B3DC(((struct Obj00136 *)p)->f18C,1);
        if(func_021D62E4(p)==1){
            func_0204B3DC(((struct Obj00136 *)p)->f184,1);
            func_0204B3DC(((struct Obj00136 *)p)->f190,1);
        }
    }
}
















int func_021D5B58(unsigned char *p,int a) {
 unsigned short n;
 int r=func_021D5BAC(p,a,&n);
 if(r==1) {
 ((struct Obj00039 *)p)->f18=n;
 if((*(unsigned char **)(p+8))[12]==2) {
 if(((struct Obj00039 *)p)->f258) {func_02017528(((struct Obj00039 *)p)->f258);func_020307B0(((struct Obj00039 *)p)->f258);}
 ((struct Obj00039 *)p)->f258=func_0201747C(func_021D6064(p),((struct Obj00039 *)p)->f0);
 }
 func_021D5C4C(p);
 }
 return r;
}















int func_021D5BAC(unsigned char *p,int direction,unsigned short *out) {
 int result=0;
 int old;
 int done;
 void *m;
 done=0;
 old=((struct Obj03284 *)p)->f18;
 do {
 if(direction==1 && ((struct Obj03284 *)p)->f18>=(*(unsigned char **)(p+8))[14]-1) {done=1;continue;}
 if(direction==0 && ((struct Obj03284 *)p)->f18==0) {done=1;continue;}
 if(direction==1) ++((struct Obj03284 *)p)->f18; else --((struct Obj03284 *)p)->f18;
 m=func_021D6064(p);
 if(func_02017E88(m,169,0)!=0) {
 if(func_02017E88(m,76,0)!=1 || ((struct Obj03284 *)p)->f58==0) {
 if(((struct Obj03284 *)p)->f58!=2 || func_021D62F4((char *)p,m)!=0) {done=1;result=1;}
 }
 }
 } while(done==0);
 if(out) *out=((struct Obj03284 *)p)->f18;
 ((struct Obj03284 *)p)->f18=old;
 return result;
}















void func_021D5C4C(unsigned char *p) {
 void *q=(void *)func_021D60A4((char *)p);
 void *m=func_021D6064(p);
 int one=1;
 func_021D60D4(p,1);
 *(int *)&((struct Obj00112 *)p)->f38=func_02017E1C(q,76,0);
 ((struct Obj00112 *)p)->f3C=func_02017E1C(q,9,0);
 ((struct Obj00112 *)p)->f40=func_021D62F4((char *)p,m);
 func_021D60D4(p,0);
 ((struct Obj00112 *)p)->f10=one;
}















/*
 * volatile: hardware halfwords reread at 021D5D96, 021D5DA0, 021D5DA6
 *   and written at 021D5D9C, 021D5DA4, 021D5DAA.
 * arithmetic: full-word selectors have cases 0..3 and an empty default;
 *   no selector bound is assumed. Halfword OR with 64 fits promoted int.
 * interfaces: own matched 60D4,697C,7C38,9C3C,8F50,9D44,A84C;
 *   matched callers 4418,4240,7BF0 supply remaining two-argument calls.
 *   Full original 6CDC and 909C confirm both incoming payloads are passed.
 */
void func_021D5C98(u8 *p)
{
    func_021D60D4(p,1);
    if (p[0x1a]!=((struct Obj00039 *)p)->f18) {
        if (p[0x1a]!=255) {
            func_021D6CDC(p,((struct Obj00039 *)p)->f88);
            func_021D91EC(p,((struct Obj00039 *)p)->f94);
        }
        func_021D697C(p,*(int * *)&((struct Obj00039 *)p)->f88);
        func_021D911C(p,((struct Obj00039 *)p)->f94);
    }
    switch (((struct Obj00039 *)p)->f5C) {
    case 0: func_021D7E84(p,(void **)(*(u8 * *)&((struct Obj00039 *)p)->f8C)); break;
    case 1: func_021D9D44(p,*(u8 * *)&((struct Obj00039 *)p)->f90); break;
    case 2: func_021D909C(p,((struct Obj00039 *)p)->f94); break;
    case 3: func_021DA84C(p,*(u8 * *)&((struct Obj00039 *)p)->f90); break;
    }
    switch (*(u32 *)&((struct Obj00039 *)p)->f58) {
    case 0: func_021D7C38(p,*(u8 * *)&((struct Obj00039 *)p)->f8C); break;
    case 1: func_021D9C3C(p,*(u8 * *)&((struct Obj00039 *)p)->f90); break;
    case 2: func_021D8F50(p,*(u8 * *)&((struct Obj00039 *)p)->f94); break;
    case 3: func_021DA6A4(p,((struct Obj00039 *)p)->f90); break;
    }
    if (((struct Obj00039 *)p)->f5C!=*(u32 *)&((struct Obj00039 *)p)->f58) {
        ((struct Obj00039 *)p)->f25C=1;
        p[0x260]=0;
        *(volatile u16 *)0x0400000c |= 64;
        *(volatile u16 *)0x0400100a |= 64;
        *(volatile u16 *)0x0400100c |= 64;
    }
    func_021D60D4(p,0);
    ((struct Obj00039 *)p)->fC=1;
}















/*
 * volatile: byte hardware writes 0400004C at 021D5DE6/021D5E1C
 *   and 0400104C at 021D5DF2/021D5E28; no ordinary object is volatile.
 * arithmetic: byte inc/dec is modulo 256; reloaded byte <=255 shifted
 *   by five fits int. Signed selector <3 admits negatives: address uses
 *   unsigned full-word multiply/add, preserving original wrap.
 * output: matched unit_02006CAC unconditionally stores the one-word out;
 *   the pointer payload passed as the eighth 02006984 argument is u32.
 * interfaces: callee own matched files; 7EAC keeps second caller payload
 *   visibly set at 021D5E9C despite its own body's unused parameter.
 */
void func_021D5DC4(u8 *p)
{
    void *q;
    u32 a,b;
    void *out;
    if (((struct Obj00035 *)p)->f25C==1) {
        ++p[0x260];
        *(volatile u8 *)0x0400004c=p[0x260] | (p[0x260]<<5);
        *(volatile u8 *)0x0400104c=p[0x260] | (p[0x260]<<5);
        if (p[0x260]>=3) ((struct Obj00035 *)p)->f25C=2;
    }
    if (((struct Obj00035 *)p)->f25C==3) {
        --p[0x260];
        *(volatile u8 *)0x0400004c=p[0x260] | (p[0x260]<<5);
        *(volatile u8 *)0x0400104c=p[0x260] | (p[0x260]<<5);
        if (p[0x260]==0) {
            *(u32 *)&((struct Obj00035 *)p)->fC=0;
            ((struct Obj00035 *)p)->f25C=0;
            return;
        }
    }
    if (func_0201C6B4(((struct Obj00035 *)p)->f84)==1 &&
        (((struct Obj00035 *)p)->f25C==2 || ((struct Obj00035 *)p)->f25C==0)) {
        if (p[0x1a]!=((struct Obj00035 *)p)->f18) {
            if (p[0x1a]!=255) func_021D6D04(p,*(u8 * *)&((struct Obj00035 *)p)->f88);
            func_021D6A38(p,((struct Obj00035 *)p)->f88);
            p[0x1a]=((struct Obj00035 *)p)->f18;
        }
        switch (((struct Obj00035 *)p)->f5C) {
        case 0: func_021D7EAC(p,((struct Obj00035 *)p)->f8C); break;
        case 1: func_021D9D94(p,*(u8 * *)&((struct Obj00035 *)p)->f90); break;
        case 2: func_021D90C0(p,*(u8 * *)&((struct Obj00035 *)p)->f94); break;
        case 3: func_021DA8BC(p,*(u8 * *)&((struct Obj00035 *)p)->f90); break;
        }
        switch (((struct Obj00035 *)p)->f58) {
        case 0: func_021D7CAC(p,*(u8 * *)&((struct Obj00035 *)p)->f8C); break;
        case 1: func_021D9CD0(p,*(u8 * *)&((struct Obj00035 *)p)->f90); break;
        case 2: func_021D8FAC(p,*(u8 * *)&((struct Obj00035 *)p)->f94); break;
        case 3: func_021DA7A4(p,*(u8 * *)&((struct Obj00035 *)p)->f90); break;
        }
        if (((struct Obj00035 *)p)->f38==0 && (*(u8 **)(p+8))[13]!=2) {
            func_0204B3DC(((struct Obj00035 *)p)->f17C,1);
            if (((struct Obj00035 *)p)->f40==0) func_0204B3DC(((struct Obj00035 *)p)->f180,0);
            else func_0204B3DC(((struct Obj00035 *)p)->f180,1);
        } else {
            func_0204B3DC(((struct Obj00035 *)p)->f17C,0);
            func_0204B3DC(((struct Obj00035 *)p)->f180,0);
        }
        if (*(u32 *)&((struct Obj00035 *)p)->f48==0) {
            if (func_021D5BAC(p,0,0)==1) func_0204B878(((struct Obj00035 *)p)->f188,3);
            else func_0204B878(((struct Obj00035 *)p)->f188,17);
        }
        if (*(u32 *)&((struct Obj00035 *)p)->f4C==0) {
            if (func_021D5BAC(p,1,0)==1) func_0204B878(((struct Obj00035 *)p)->f18C,2);
            else func_0204B878(((struct Obj00035 *)p)->f18C,16);
        }
        if (*(int *)&((struct Obj00035 *)p)->f58<3 && func_021D62E4((char *)p)==1) {
            if (*(u32 *)((u32)p + (u32)*(int *)&((struct Obj00035 *)p)->f58*4 + 0x60)==1)
                func_0204B878(((struct Obj00035 *)p)->f184,7);
            else func_0204B878(((struct Obj00035 *)p)->f184,6);
        }
        if (((struct Obj00035 *)p)->f10==1) {
            ((struct Obj00035 *)p)->f10=0;
            func_02006BB4(0);
            if (((struct Obj00035 *)p)->f38==0) {
                q=(void *)func_021D60A4((char *)p);
                a=func_02017E1C(q,5,0);
                b=func_02017E1C(q,111,0);
                func_02006CAC(&out);
                func_02006984(a,b,64,0,0,0,0,(u32)&out);
            }
        }
        if (((struct Obj00035 *)p)->f25C==2) {
            ((struct Obj00035 *)p)->f25C=3;
            ((struct Obj00035 *)p)->f5C=((struct Obj00035 *)p)->f58;
            return;
        }
        *(u32 *)&((struct Obj00035 *)p)->fC=0;
        ((struct Obj00035 *)p)->f5C=((struct Obj00035 *)p)->f58;
    }
}















void *func_021D6064(unsigned char *p) {
 switch((*(unsigned char **)(p+8))[12]) {
 case 0: return func_020185F0(**(void ** *)&((struct Obj00112 *)p)->f8);
 case 1: return func_020185F0(func_0201AB28(**(void ** *)&((struct Obj00112 *)p)->f8,((struct Obj00112 *)p)->f18));
 case 2: return (unsigned char *)**(void ** *)&((struct Obj00112 *)p)->f8+func_020173E8()* ((struct Obj00112 *)p)->f18;
 default: return 0;
 }
}














int func_021D60A4(char *p)
{
    struct Src *s = *(struct Src * *)&((struct Obj00112 *)p)->f8;
    switch (s->kind) {
    case 0:
        return s->v;
    case 1:
        return (int)func_0201AB28((void *)s->v, ((struct Obj00112 *)p)->f18);
    case 2:
        return *(int *)&((struct Obj00112 *)p)->f258;
    default:
        return 0;
    }
}














void func_021D60D4(unsigned char *p,int a) {
 void *m;
 switch((*(unsigned char **)(p+8))[12]) {
 case 0:
 m=**(void ** *)&((struct Obj00112 *)p)->f8;
 if(a==1) func_02017D30(m); else func_02017D70(m,1);
 break;
 case 1:
 m=func_0201AB28(**(void ** *)&((struct Obj00112 *)p)->f8,((struct Obj00112 *)p)->f18);
 if(a==1) func_02017D30(m); else func_02017D70(m,1);
 break;
 case 2:
 m=func_021D6064(p);
 if(a==1) {func_02017D30(((struct Obj00112 *)p)->f258);func_02017DBC(m);}
 else {func_02017D70(((struct Obj00112 *)p)->f258,1);func_02017DE4(m,1);}
 break;
 }
}












void func_021D614C(unsigned char *p,int a,int b,int c,unsigned short d,unsigned short e) {
 void *t=func_02045EC0(((struct Obj10506 *)p)->f7C,b);
 func_0201C724(((struct Obj10506 *)p)->f84,a,(short)c,(short)d,(u32)t,((struct Obj10506 *)p)->f80,e);
 func_02045808(t);
}











void func_021D618C(unsigned char *p,unsigned int a,int b,int c,unsigned short d,unsigned short e) {
 func_021D614C(p,(int)func_02045770((struct Descriptor_021D4240 *)a),b,c,d,e);
}











void func_021D61B8(unsigned char *p,int a,void *b,int c,unsigned short d,unsigned short e,unsigned short f) {
 void *t=func_020457B0(16,((struct Obj08145 *)p)->f0);
 void *s=func_02045EC0(((struct Obj08145 *)p)->f7C,c);
 func_0201F250(b,t,s);
 func_0201C724(((struct Obj08145 *)p)->f84,a,(short)d,(short)e,(u32)t,((struct Obj08145 *)p)->f80,f);
 func_02045808(s);
 func_02045808(t);
}










void func_021D6214(unsigned char *p,unsigned int a,void *b,int c,unsigned short d,unsigned short e,unsigned short f) {
 func_021D61B8(p,(int)func_02045770((struct Descriptor_021D4240 *)a),b,c,d,e,f);
}










void func_021D6244(unsigned char *p,int a,void *b,int c,unsigned short d,unsigned short e,unsigned short f) {
 void *t=func_020457B0(16,((struct Obj06482 *)p)->f0);
 void *s=func_02045EC0(((struct Obj06482 *)p)->f7C,c);
 int w;
 func_0201F250(b,t,s);
 w=func_0201D304(t,((struct Obj06482 *)p)->f80,0);
 func_0201C724(((struct Obj06482 *)p)->f84,a,(short)(d-w),(short)e,(u32)t,((struct Obj06482 *)p)->f80,f);
 func_02045808(s);
 func_02045808(t);
}














void func_021D62B4(unsigned char *p,unsigned int a,void *b,int c,unsigned short d,unsigned short e,unsigned short f) {
 func_021D6244(p,(int)func_02045770((struct Descriptor_021D4240 *)a),b,c,d,e,f);
}















int func_021D62E4(char *p)
{
    char *q = *(char * *)&((struct Obj23130 *)p)->f8;

    return ((struct Obj23131 *)q)->f20 == 1;
}














int func_021D62F4(char *p, void *q)
{
    unsigned char i;
    for (i = 0; i < 0x50; i++) {
        if (func_02017E88(q, func_021DBF2C(i, 0), 0) == 1) {
            return 1;
        }
    }
    return 0;
}














static inline void SetA(void *p, Moves m) { func_02017E40(p,0x8e,(u32)(&m)); }














static inline void SetB(void *p, Moves m) { func_02017E64(p,0x8e,(u32)(&m)); }














int func_021D6324(u32 heap,int *st,u8 *obj,char *d) {
    switch(*st) {
    case 0: {
        u8 *c=obj;
        u8 *o;
        u8 i;
                func_0203064C(1,0x42,0x50000);
        o=func_0203159C((void *)heap,0x264,0x42);
        func_02082BCC(o,0,0x264);
        ((struct Obj14064 *)o)->f0=0x42;
        i=0;
        if(c==0) {
            c=func_02030734(1,0x28,0,d_021DC80C,0x4d);
            if((func_0203630C()&0x400)==0) {
                void *party;
                void *pt;
                party=func_0201A920(1);
                func_0201A954(party,6);
                for(i=0;i<5;i++) {
                    pt=func_020173F0(i+3,10,-1,0,1);
                    SetA(pt,d_021DC138);
                    func_02017E40(pt,0x9a,0);
                    func_0201A98C(party,pt);
                    func_020307B0(pt);
                }
                c[0xf]=0;
                ((struct Obj00830 *)c)->f0=party;
                c[0xc]=1;
                c[0xe]=5;
            } else {
                int n;
                u8 *base;
                u32 off;
                n=func_020173E8();
                ((struct Obj00830 *)c)->f0=func_02030734(1,n*0x1e,1,d_021DC80C,0x81);
                c[0xc]=2;
                c[0xe]=0x1e;
                c[0xf]=0xff;
                for(i=0;i<c[0xe];i++) {
                    n=func_020173E8();
                    base=*(u8 * *)&((struct Obj00830 *)c)->f0;
                    off=i*n;
                    func_02017550((struct Sav *)(base+off));
                    if(func_02005728(3)!=0) {
                        func_02017600(base+off,i+1,0x32,(u64)-1);
                        SetB(base+off,d_021DC144);
                        func_02017E64(base+off,0x9a,0);
                        if(c[0xf]==0xff) c[0xf]=i;
                    }
                }
            }
            i=0;
            c[0xd]=0;
            c[0x10]=0;
            ((struct Obj00830 *)c)->f20=1;
            ((struct Obj00830 *)c)->f18=1;
            ((struct Obj00830 *)c)->f8=func_020124F4(1);
            if(func_0203630C()&0x400) {
                c[0xd]=2;
                ((struct Obj00830 *)c)->f20=i;
                ((struct Obj00830 *)c)->f14=10;
            }
            if(func_0203630C()&0x100) {
                c[0xd]=1;
                ((struct Obj00830 *)c)->f20=0;
            }
            func_020355D8(1);
        }
        *(u8 * *)&((struct Obj14064 *)o)->f8=c;
        *st=1;
        break;
    }
    case 1:
        if(func_021D4240(d)==1) return 1;
        break;
    }
    return 0;
}














int func_021D657C(struct S020315D4 *handle, int unused, int mode, char *p)
{
    if (!func_021D4418(p)) return 0;
    if (!mode) {
        func_02012704(*(u8 * *)&((struct Obj23132 *)(*(char * *)&((struct Obj01255 *)p)->f8))->f8);
        func_020307B0(*(void **)*(char * *)&((struct Obj01255 *)p)->f8);
        func_020307B0(((struct Obj01255 *)p)->f8);
    }
    func_020315D4(handle);
    func_020306F0(0x42);
    return 1;
}















/*
 * Addresses are Black-image addresses.
 */
int func_021D65BC(int a, int b, int c, int d)
{
    int r = func_021D44C8((char *)d);

    if (r == 1)
        return 1;
    if (r == 2)
        return 1;
    return 0;
}














void *func_021D65D8(u16 *a) {
 u32 *p=func_02030734(*a,0x9c,1,d_021DC818,0x10d);
 p[0]=0;
 p[1]=0;
 p[27]=0;
 p[3]=1;
 p[2]=0;
 p[23]=0;
 return p;
}














void func_021D6608(void *a,void *b) {
 func_020307B0(b);
}













void func_021D6614(u8 *a,u8 *p) {
    u32 st=((struct Obj00200 *)p)->f8;
    if(st==0 || st==2) {
        func_021D7460(a,p);
        func_021D6F54(a,p);
        return;
    }
    if(st==3) {
        Vec_021D62B4 v48=d_021DC234;
        Vec_021D62B4 v3c=d_021DC228;
        Vec_021D62B4 v30={0,0,0};
        u8 c;
        p[0x9b]=p[0x9b]+1;
        if(p[0x9b]>5 && ((struct Obj00200 *)p)->fC==0) {
            func_02015EB0(((struct Obj00200 *)p)->f0);
            func_02015EA0(((struct Obj00200 *)p)->f4);
            ((struct Obj00200 *)p)->fC=1;
        }
        c=p[0x9b];
        if(c>=10) {
            func_021D79A8(a,p,0);
            ((struct Obj00200 *)p)->f8=0;
        } else {
            u16 ang;
            v48.x=c*0x19000/10-0x42000;
            ang=(p[0x9b]<<15)/10;
            v30.y=d_020A1B38[(ang>>4)*2]<<5;
            if(((struct Obj00200 *)p)->f10==1) v30.y=0;
            func_021D79A8(a,p,v30.y);
        }
        func_02015C78(((struct Obj00200 *)p)->f0,(u32 *)(&v30));
        func_02015C78(((struct Obj00200 *)p)->f4,(u32 *)(&v30));
        func_02015D30(((struct Obj00200 *)p)->f0,(u32 *)(&v3c));
        func_02048AFC(((struct Obj05385 *)a)->f70, (const Vec_021D62B4 *)&v48);
        func_02048AD0(((struct Obj05385 *)a)->f70);
    } else if(st==1) {
        Vec_021D62B4 v24=d_021DC198;
        Vec_021D62B4 v18=d_021DC210;
        u8 c;
        p[0x9b]=p[0x9b]+1;
        c=p[0x9b];
        if(c<3) {
            Pair_021D4240 t1=d_021DC170;
            Pair_021D4240 t2=d_021DC178;
            Pair_021D4240 t3=d_021DC168;
            u8 k=c-1;
            v18.x=t1.v[k];
            v18.y=t2.v[k];
            v24.x=t3.v[k];
            func_02048AFC(((struct Obj05385 *)a)->f70, (const Vec_021D62B4 *)&v24);
            func_02048AD0(((struct Obj05385 *)a)->f70);
            func_02015D30(((struct Obj00200 *)p)->f0,(u32 *)(&v18));
        } else {
            func_02015EA0(((struct Obj00200 *)p)->f0);
            func_02015EB0(((struct Obj00200 *)p)->f4);
            func_02015D30(((struct Obj00200 *)p)->f4,(u32 *)(&v18));
            func_02048AFC(((struct Obj05385 *)a)->f70, (const Vec_021D62B4 *)&v24);
            func_02048AD0(((struct Obj05385 *)a)->f70);
            ((struct Obj00200 *)p)->fC=0;
            ((struct Obj00200 *)p)->f8=2;
            ((struct Obj00200 *)p)->f6C=0;
        }
    }
}














void func_021D67EC(u16 *p, int a, void *b)
{
    func_020498F4(b, 0x3e, 2, 0, 0, 0, *p);
}













void func_021D6808(void *a,void *b) {
 func_021D6CDC(a,b);
}













void func_021D6810(u8 *a,u8 *p) {
    ObjPos pos[4];
    u8 i;
    u32 *e;
    pos[3].x=168;
    pos[3].y=8;
    pos[3].priority=10;
    pos[3].flags=1;
    pos[3].z=0;
    ((struct Obj05386 *)p)->f20=(u32)func_0204B294((void *)((struct Obj00993 *)a)->f174,((struct Obj00993 *)a)->fD0,((struct Obj00993 *)a)->f9C,((struct Obj00993 *)a)->f104,&pos[3],0,((struct Obj00993 *)a)->f0);
    func_0204B3DC((struct Obj *)((struct Obj05386 *)p)->f20,0);
    pos[2].y=128;
    pos[2].priority=10;
    pos[2].flags=1;
    for(i=0;i<8;i++) {
        pos[2].x=d_021DC158[i];
        pos[2].z=d_021DC160[i];
        e=(u32 *)(p+i*4);
        e[9]=(u32)func_0204B294((void *)((struct Obj00993 *)a)->f174,((struct Obj00993 *)a)->fD4,((struct Obj00993 *)a)->fA0,((struct Obj00993 *)a)->f108,&pos[2],0,((struct Obj00993 *)a)->f0);
        func_0204B3DC((struct Obj *)e[9],1);
    }
    pos[1].x=236;
    pos[1].y=26;
    pos[1].priority=10;
    pos[1].flags=1;
    pos[1].z=0;
    ((struct Obj05386 *)p)->f44=(u32)func_0204B294((void *)((struct Obj00993 *)a)->f174,((struct Obj00993 *)a)->fF0,((struct Obj00993 *)a)->fBC,((struct Obj00993 *)a)->f120,&pos[1],0,((struct Obj00993 *)a)->f0);
    func_0204B3DC((struct Obj *)((struct Obj05386 *)p)->f44,0);
    pos[0].x=241;
    pos[0].y=31;
    pos[0].priority=10;
    pos[0].flags=1;
    pos[0].z=0;
    ((struct Obj05386 *)p)->f48=(u32)func_0204B294((void *)((struct Obj00993 *)a)->f174,((struct Obj00993 *)a)->fF4,((struct Obj00993 *)a)->fC0,((struct Obj00993 *)a)->f124,&pos[0],0,((struct Obj00993 *)a)->f0);
    func_0204B3DC((struct Obj *)((struct Obj05386 *)p)->f48,0);
}













void func_021D694C(void *a,unsigned char *p) {
 u8 i;
 func_0204B3B4(((struct Obj10507 *)p)->f48);
 func_0204B3B4(((struct Obj10507 *)p)->f44);
 for(i=0;i<8;i++) func_0204B3B4(*(void **)(p+0x24+i*4));
 func_0204B3B4(((struct Obj10507 *)p)->f20);
}












void func_021D697C(unsigned char *p,int *q) {
 void *m=func_021D6064(p);
 void *t;
 int a,b;
 if((*(unsigned char **)(p+8))[12]==1) q[3]=func_0201ACC4(**(void ** *)&((struct Obj00436 *)p)->f8,((struct Obj00436 *)p)->f18); else q[3]=1;
 if(*(int *)&((struct Obj00436 *)p)->f38==0) {
 a=func_02017E88(m,5,0);
 b=func_02017E88(m,111,0);
 t=func_0201ADE4((unsigned short)a,(unsigned short)b,((struct Obj00436 *)p)->f0);
 if(func_0201AE1C(t,16)==1) q[4]=1; else q[4]=0;
 q[5]=func_0201AE1C(t,38);
 func_0201AE14(t);
 } else {q[4]=0;q[5]=0;}
 q[6]=(int)func_020450F0(1,19,0,13,4,14,1);
 q[7]=(int)func_020450F0(1,19,17,13,4,14,1);
 func_021D6D18(p,(u8 *)q,m);
}












/*
 * lever: block-local Vec_021D697C zero initializers materialize addresses before
 *   stores; explicit visibility if/else calls retain original branch shape;
 *   mask update before i++ retains the original loop scheduling.
 * output: 49F34/49DB4 call 4A1BC, whose returned allocation is nonzero:
 *   30734 null failure calls 88234 -> 882C0 -> 882C8 halt loop (882CC
 *   branches back). Both 62A98 and 62A4C assign *out on every returning
 *   path, including absent block. No output default or success assumption.
 * interface: 785C receives the visibly loaded third mon word even though
 *   its own body ignores it. 4ADEC's fourth legacy parameter is overwritten
 *   before use, original sets only r0-r2; 276C4 reads only r0 and replaces
 *   r1-r3 before each call, so unused legacy trailing inputs are omitted.
 * arithmetic: local u8 i=0..5 and mask truncates modulo256; all vectors
 *   assigned from three-word ROM templates or all three explicit zeros.
 */
/*
 * lever: block-local Vec zero initializers materialize addresses before
 *   stores; explicit visibility if/else calls retain original branch shape;
 *   mask update before i++ retains the original loop scheduling.
 * output: 49F34/49DB4 call 4A1BC, whose returned allocation is nonzero:
 *   30734 null failure calls 88234 -> 882C0 -> 882C8 halt loop (882CC
 *   branches back). Both 62A98 and 62A4C assign *out on every returning
 *   path, including absent block. No output default or success assumption.
 * interface: 785C receives the visibly loaded third mon word even though
 *   its own body ignores it. 4ADEC's fourth legacy parameter is overwritten
 *   before use, original sets only r0-r2; 276C4 reads only r0 and replaces
 *   r1-r3 before each call, so unused legacy trailing inputs are omitted.
 * arithmetic: local u8 i=0..5 and mask truncates modulo256; all vectors
 *   assigned from three-word ROM templates or all three explicit zeros.
 */
void func_021D6A38(u8 *p,u8 *q)
{
    void *pal,*chr;
    void *mon,*other,*window,*loaded;
    u32 form,archive,status;
    u8 i,mask;
    mon=func_021D6064(p);
    other=(void *)func_021D60A4((char *)p);
    func_021D785C(p,q,mon);
    window=((struct Obj00472 *)q)->f18;
    func_02045334(window);
    func_02045374(window);
    func_02041B6C(func_02045730(window));
    window=((struct Obj00472 *)q)->f1C;
    func_02045334(window);
    func_02045374(window);
    func_02041B6C(func_02045730(window));
    form=func_02017E88(mon,0x98,0);
    archive=func_020275E4();
    loaded=func_02049F34(archive,func_02027720(form),(u32)&pal,((struct Obj00112 *)p)->f0);
    func_0204ADEC(((struct Obj00112 *)p)->f9C,pal,1);
    func_020307B0(loaded);
    archive=func_020275E4();
    loaded=func_02049DB4(archive,func_0202772C(form),0,(u32)&chr,((struct Obj00112 *)p)->f0);
    func_0204A9D0(((struct Obj00112 *)p)->fD0,chr);
    func_020307B0(loaded);
    func_0204B3DC(((struct Obj00472 *)q)->f20,1);
    status=func_02017E88(mon,11,0);
    for(i=0,mask=1;i<6;mask=(u8)(mask<<1),i++) {
        if(status & mask) func_0204B878(*(void **)(q+0x24+i*4),i*2+1);
        else func_0204B878(*(void **)(q+0x24+i*4),i*2);
    }
    if(func_0201B28C(mon)==1) func_0204B3DC(((struct Obj00472 *)q)->f40,1);
    else func_0204B3DC(((struct Obj00472 *)q)->f40,0);
    if(func_02017EB4(mon)==1 && ((struct Obj00112 *)p)->f38==0)
        func_0204B3DC(((struct Obj00472 *)q)->f3C,1);
    else func_0204B3DC(((struct Obj00472 *)q)->f3C,0);
    if(((struct Obj00472 *)q)->fC==1) {
        Vec_021D697C a=d_021DC204;
        Vec_021D697C b=d_021DC21C;
        Vec_021D697C c={0,0,0};
        Vec_021D697C d=d_021DC1B0;
        func_02015C78(((struct Obj00472 *)q)->f0,&c.x);
        func_021D7A1C(p, (void * *)q, (Vec *)((Vec_021D697C *)&d));
        func_02015D30(((struct Obj00472 *)q)->f0,&b.x);
        func_02048AFC(((struct Obj00112 *)p)->f70, (const Vec_021D62B4 *)&a);
        func_02048AD0(((struct Obj00112 *)p)->f70);
        ((struct Obj00472 *)q)->f8=0;
    } else {
        Vec_021D697C e=d_021DC1A4;
        Vec_021D697C f=d_021DC18C;
        Vec_021D697C g={0,0,0};
        Vec_021D697C h=d_021DC1BC;
        func_02015C78(((struct Obj00472 *)q)->f0,&g.x);
        func_021D7A1C(p, (void * *)q, (Vec *)((Vec_021D697C *)&h));
        func_02015D30(((struct Obj00472 *)q)->f4,&f.x);
        func_02048AFC(((struct Obj00112 *)p)->f70, (const Vec_021D62B4 *)&e);
        func_02048AD0(((struct Obj00112 *)p)->f70);
        ((struct Obj00472 *)q)->f8=2;
    }
    if((u8)func_02017F90(other)!=0) {
        func_0204B878(((struct Obj00472 *)q)->f48,func_020276C4((int)other));
        func_0204B3DC(((struct Obj00472 *)q)->f48,1);
        func_0204B3DC(((struct Obj00472 *)q)->f44,0);
    } else {
        func_0204B3DC(((struct Obj00472 *)q)->f48,0);
        if(func_0201B268(mon)==1) func_0204B3DC(((struct Obj00472 *)q)->f44,1);
        else func_0204B3DC(((struct Obj00472 *)q)->f44,0);
    }
    {
    Vec_021D697C zero={0,0,0};
    func_02015C78(((struct Obj00472 *)q)->f0,&zero.x);
    func_02015C78(((struct Obj00472 *)q)->f4,&zero.x);
    q[0x78]=0;q[0x79]=0;q[0x80]=0;q[0x81]=0;
    ((struct Obj00472 *)q)->f6C=0;((struct Obj00472 *)q)->f5C=0;
    q[0x88]=0;q[0x89]=0;
    }
}












void func_021D6CDC(unsigned char *a,unsigned char *b) {
 unsigned char *q=*(unsigned char * *)&((struct Obj14066 *)a)->f8;
 if(q[12]==1) func_0201ACDC(((struct Obj14067 *)q)->f0,a[0x1a],(u32)(((struct Obj10508 *)b)->fC));
 func_020452E8(((struct Obj10508 *)b)->f1C);
 func_020452E8(((struct Obj10508 *)b)->f18);
}













void func_021D6D04(void *a, u8 *p)
{
    func_021D797C(a, (void **)p);
    func_0204B3DC(((struct Obj23137 *)p)->f20, 0);
}












void func_021D6D18(u8 *p,u8 *q,void *mon)
{
    void *ws,*buf,*name,*text;
    ws=func_0201EC64(((struct Obj00436 *)p)->f0);
    buf=func_020457B0(32,((struct Obj00436 *)p)->f0);
    name=func_020457B0(32,((struct Obj00436 *)p)->f0);
    func_02017E88(mon,115,(void *)name);
    func_0201EE0C(ws,0,name,0,1,2);
    text=func_02045EC0(((struct Obj00436 *)p)->f7C,0);
    func_0201F250(ws,buf,text);
    func_0201C724(((struct Obj00436 *)p)->f84,(u32)func_02045770(((struct Obj01546 *)q)->f18),25,1,(u32)buf,((struct Obj00436 *)p)->f80,1088);
    func_02045808(name);func_02045808(text);func_02045808(buf);func_0201ED04(ws);
    if(((struct Obj00436 *)p)->f38==0 && func_02017E88(mon,173,0)==1){
        u32 form=func_02017E88(mon,110,0);
        if(form==0){
            buf=func_02045EC0(((struct Obj00436 *)p)->f7C,1);
            func_0201C724(((struct Obj00436 *)p)->f84,(u32)func_02045770(((struct Obj01546 *)q)->f18),89,1,(u32)buf,((struct Obj00436 *)p)->f80,5312);
            func_02045808(buf);
        }else if(form==1){
            buf=func_02045EC0(((struct Obj00436 *)p)->f7C,2);
            func_0201C724(((struct Obj00436 *)p)->f84,(u32)func_02045770(((struct Obj01546 *)q)->f18),89,1,(u32)buf,((struct Obj00436 *)p)->f80,3200);
            func_02045808(buf);
        }
    }
    if(((struct Obj00436 *)p)->f38==0){
        void *text2;
        ws=func_0201EC64(((struct Obj00436 *)p)->f0);buf=func_020457B0(16,((struct Obj00436 *)p)->f0);
        func_0201EFA4(ws,0,func_02018438(mon),3,0,1);
        text2=func_02045EC0(((struct Obj00436 *)p)->f7C,3);
        func_0201F250(ws,buf,text2);
        func_0201C724(((struct Obj00436 *)p)->f84,(u32)func_02045770(((struct Obj01546 *)q)->f18),9,17,(u32)buf,((struct Obj00436 *)p)->f80,1088);
        func_02045808(text2);func_02045808(buf);func_0201ED04(ws);
    }
    buf=func_02045EC0(((struct Obj00436 *)p)->f7C,4);
    func_0201C724(((struct Obj00436 *)p)->f84,(u32)func_02045770(((struct Obj01546 *)q)->f1C),10,1,(u32)buf,((struct Obj00436 *)p)->f80,1088);
    func_02045808(buf);
    {
        void *text3;
        ws=func_0201EC64(((struct Obj00436 *)p)->f0);buf=func_020457B0(16,((struct Obj00436 *)p)->f0);
        func_0201EF40(ws,0,func_02017E88(mon,6,0));
        text3=func_02045EC0(((struct Obj00436 *)p)->f7C,5);
        func_0201F250(ws,buf,text3);
        func_0201C724(((struct Obj00436 *)p)->f84,(u32)func_02045770(((struct Obj01546 *)q)->f1C),6,17,(u32)buf,((struct Obj00436 *)p)->f80,1088);
        func_02045808(text3);func_02045808(buf);func_0201ED04(ws);
    }
}











/*
 * follower: 021D703C complete reset helper is included; 021D7060 is filed
 *   separately. Reset contains constant stores only, preserving order.
 * semantic: unsigned full-word state dispatch guarded at six by the
 *   original; byte counters compared directly. No signed arithmetic.
 */
void func_021D6F54(u8 *p,u8 *q)
{
    switch(((struct Obj01740 *)q)->f5C) {
    case 0:
        if(q[0x78]>10) {((struct Obj01740 *)q)->f5C=1;func_021D703C(p,q);}
        if(q[0x80]>10) {((struct Obj01740 *)q)->f5C=2;func_021D703C(p,q);}
        if(q[0x88]>20) {((struct Obj01740 *)q)->f5C=3;func_021D703C(p,q);}
        break;
    case 1:
        func_021D708C(p,q);
        if(func_021D7060(p,q,q+0x78)==0) ((struct Obj01740 *)q)->f5C=4;
        break;
    case 4:
        if(func_021D708C(p,q)==1) ((struct Obj01740 *)q)->f5C=0;
        break;
    case 2:
        func_021D7248(p,q);
        if(func_021D7060(p,q,q+0x80)==0) ((struct Obj01740 *)q)->f5C=5;
        break;
    case 5:
        if(func_021D7248(p,q)==1) ((struct Obj01740 *)q)->f5C=0;
        break;
    case 3:
        func_021D72E8(p,q,1);
        if(func_021D7060(p,q,q+0x88)==0) ((struct Obj01740 *)q)->f5C=6;
        break;
    case 6:
        if(func_021D72E8(p,q,0)==1) {
            func_02015E4C(((struct Obj01740 *)q)->f0);
            ((struct Obj01740 *)q)->f5C=0;
        }
        break;
    }
}











void func_021D703C(void *unused,u8 *q)
{
    ((struct Obj05387 *)q)->f58=1;
    ((struct Obj05387 *)q)->f64=0;
    ((struct Obj05387 *)q)->f68=0;
    ((struct Obj05387 *)q)->f62=0;
    ((struct Obj05387 *)q)->f66=0;
    ((struct Obj05387 *)q)->f60=0;
}











int func_021D7060(void *unused,u8 *q,u8 *counter)
{
    if(*counter<10) {
        ++((struct Obj10509 *)q)->f60;
        if(((struct Obj10509 *)q)->f60>24) return 0;
    } else ((struct Obj10509 *)q)->f60=0;
    return 1;
}











/*
 * semantic: phase u16<<15 <=2147450880; dividing by 15 then truncating
 *   to u16 leaves a full index <=8190. Speed is explicitly a low byte;
 *   phase*speed <=16711425, division by 15 fits signed int. Signed sample
 *   times 16 fits int. All later shifts and vector additions/subtractions
 *   use u32 wrap, converted to the compiler's signed word for _fflt.
 *   _ffix is called explicitly: the original unsigned speed shift can
 *   convert to float outside int range; no C float-to-int cast is assumed.
 *   The template initializes every base word; zero initializes v.
 */
int func_021D708C(u8 *p,u8 *q)
{
    Vec base=d_021DC1D4;
    Vec v={0,0,0};
    int radius=0;
    int sample,t;
    u32 n;
    u8 speed;
    float f;
    if(((struct Obj02188 *)q)->f10==0) {
        sample=d_020A1B38[((u16)((((struct Obj02188 *)q)->f62<<15)/15)>>4)*2];
        n=((struct Obj14068 *)p)->f3C>>6;
        if(n) f=0.5f+(float)(n<<12);
        else f=(float)(n<<12)-0.5f;
        radius=(u32)(sample*16)+(u32)_ffix(f);
        v.y=radius;
        func_021D79A8(p,q,radius);
    } else {
        v.y=radius;
        func_021D79A8(p,q,radius);
    }
    speed=(u8)((((struct Obj14068 *)p)->f3C>>6)+16);
    t=(((struct Obj02188 *)q)->f62*speed)/15;
    switch(((struct Obj02188 *)q)->f64) {
    case 0:
        if(t>0) f=0.5f+(float)(int)((u32)t<<12);
        else f=(float)(int)((u32)t<<12)-0.5f;
        base.x+=(u32)_ffix(f);
        break;
    case 1:
        t=speed-t;
        if(t>0) f=0.5f+(float)(int)((u32)t<<12);
        else f=(float)(int)((u32)t<<12)-0.5f;
        base.x+=(u32)_ffix(f);
        break;
    case 2:
        if(t>0) f=0.5f+(float)(int)((u32)t<<12);
        else f=(float)(int)((u32)t<<12)-0.5f;
        base.x-=(u32)_ffix(f);
        break;
    case 3:
        t=speed-t;
        if(t>0) f=0.5f+(float)(int)((u32)t<<12);
        else f=(float)(int)((u32)t<<12)-0.5f;
        base.x-=(u32)_ffix(f);
        break;
    }
    func_02015C48(((struct Obj02188 *)q)->f0,(u32 *)&base.x);
    func_02015C78(((struct Obj02188 *)q)->f0,(u32 *)(&v));
    ++((struct Obj02188 *)q)->f62;
    if(((struct Obj02188 *)q)->f62>15) {
        ((struct Obj02188 *)q)->f62=0;
        ++((struct Obj02188 *)q)->f64;
        if(((struct Obj02188 *)q)->f64>3) {((struct Obj02188 *)q)->f64=0;return 1;}
    }
    return 0;
}











int func_021D7248(unsigned char *p,unsigned char *q) {
 Vec v={0,0,0};
 int s;
 unsigned n;
 float f;
 if(((struct Obj05388 *)q)->f10==0) {
 s=d_020A1B38[((unsigned short)((((struct Obj05388 *)q)->f62<<15)/20)>>4)*2];
 n=((struct Obj23139 *)p)->f3C>>6;
 if(n) f=0.5f+(float)(n<<12); else f=(float)(n<<12)-0.5f;
 v.y=(s<<5)+(int)f;
 func_021D79A8(p,q,v.y);
 }
 func_02015C78(((struct Obj05388 *)q)->f0,(u32 *)(&v));
 ++((struct Obj05388 *)q)->f62;
 if(((struct Obj05388 *)q)->f62>20) {((struct Obj05388 *)q)->f62=0;return 1;}
 return 0;
}











int func_021D72E8(u8 *p,u8 *q,int mode)
{
    Vec v={0,0,0};
    u32 sum;
    u8 i;
    u16 delta;
    int height;
    float f;
    if(((struct Obj00831 *)q)->f10==1) return 1;
    if(mode==1) {
        sum=0;
        for(i=0;i<5;i++) sum+=q[0x94+i];
        sum/=5U;
        if(sum<10) sum=10;
        if(sum>20) sum=20;
        delta=20-sum;
        ((struct Obj00831 *)q)->f68=2048+(6144*delta)/10;
        v.y+=*(const s16_021D4240 *)((u32)d_020A1B38+((u32)((((struct Obj00831 *)q)->f62*546)>>4)<<2))*4;
        ++((struct Obj00831 *)q)->f62;
        if(((struct Obj00831 *)q)->f62>120) ((struct Obj00831 *)q)->f62=0;
    } else ((struct Obj00831 *)q)->f68=0;
    if(((struct Obj00831 *)q)->f66<((struct Obj00831 *)q)->f68) ++((struct Obj00831 *)q)->f66;
    if(((struct Obj00831 *)q)->f66>((struct Obj00831 *)q)->f68) {
        if(mode==0) {
            if(((struct Obj00831 *)q)->f66>=32) ((struct Obj00831 *)q)->f66-=32;
            else ((struct Obj00831 *)q)->f66=0;
        } else --((struct Obj00831 *)q)->f66;
    }
    height=((struct Obj00831 *)q)->f66;
    if(height) f=0.5f+(float)(height*4096);
    else f=(float)(height*4096)-0.5f;
    v.y+=(int)f/16;
    func_021D79A8(p,q,v.y);
    func_02015C78(((struct Obj00831 *)q)->f0,(u32 *)(&v));
    func_02015E04(((struct Obj00831 *)q)->f0);
    if(((struct Obj00831 *)q)->f66==0 && ((struct Obj00831 *)q)->f68==0) return 1;
    return 0;
}










/*
 * note 2026-10-02 (lane R4): the loop stores 0 (the copy of r4 before the loop is the
 *   zero already in r4), not the counter; the three post-loop stores are 0 too.
 */
void func_021D7460(u8 *a,u8 *p) {
    Rects r=d_021DC1E0;
    u32 x,y;
    int t,g,k;
    u8 i;
    func_02035CB8(&x,&y);
    if(((struct Obj23140 *)a)->f38!=0) return;
    t=func_02035C60();
    g=func_02035C38();
    k=func_02035BA4(&r);
    if(((struct Obj00200 *)p)->f8==0) {
        if(k==0 || (k==1 && t==0)) {
            if(t==1) {
                ((struct Obj00200 *)p)->f6C=1;
                ((struct Obj00200 *)p)->f58=0;
                func_021D77E8(p+0x78,x,y);
                func_021D77E8(p+0x80,x,y);
                func_021D77E8(p+0x88,x,y);
                for(i=0;i<5;i++) p[0x94+i]=0;
                p[0x99]=0;
                p[0x9a]=0;
                ((struct Obj00200 *)p)->f90=0;
            } else if(g==1 && ((struct Obj00200 *)p)->f6C==1) {
                func_021D75A4((int)a,p);
            }
            ((struct Obj00200 *)p)->f70=x;
            ((struct Obj00200 *)p)->f74=y;
        } else {
            if(((struct Obj00200 *)p)->f6C==1 && ((struct Obj00200 *)p)->f58==0 && ((struct Obj00200 *)p)->f5C==0) {
                ((struct Obj00200 *)p)->f8=1;
                p[0x9b]=0;
            }
            func_021D77E8(p+0x78,x,y);
            func_021D77E8(p+0x80,x,y);
            func_021D77E8(p+0x88,x,y);
            ((struct Obj00200 *)p)->f6C=0;
        }
    } else if(((struct Obj00200 *)p)->f8==2) {
        if(k==0 || (k==1 && t==0)) {
            if(t==1) ((struct Obj00200 *)p)->f6C=1;
        } else if(((struct Obj00200 *)p)->f6C==1) {
            ((struct Obj00200 *)p)->f6C=0;
            ((struct Obj00200 *)p)->f8=3;
            p[0x9b]=0;
        }
    }
}










/*
 * note: three coordinate pairs (x,y from func_02035CB8) are compared against
 *   byte histories at +0x7A/+0x82/+0x8A and dispatched to func_021D77F8 /
 *   func_021D77E8. direction=0 is written before ++p[0x81] and flag=0 after
 *   ry; this places the r3/r4 zero registers.
 * note 2026-10-02 (lane R5): the rotation x delta is spelled
 *   `rx=p[0x8a]; rx=(s8)(x-rx);`. The byte is loaded into rx's own register
 *   (r1, the register that later holds the s8 result), so the subtraction
 *   reads ldrb r1 / ldr r0,x / subs r0,r0,r1. A separate byte temporary or a
 *   direct (s8)(x-p[0x8a]) put the byte in r0 (3 bytes off).
 */
void func_021D75A4(int a,u8 *p)
{
    u32 x,y;
    int dx,dy,rx,ry;
    Direction direction;
    Flag flag;
    u32 tmp;
    u32 *tmp1;
    func_02035CB8(&x,&y);
    dx=(s8)(x-p[0x7a]);
    dy=(s8)(y-p[0x7b]);
    if ((((struct Obj00219 *)p)->f7C==0 || ((struct Obj00219 *)p)->f7C==3) && dx>16)
        func_021D77F8((struct hdr_021D77E8 *)((struct hdr_021D4240 *)(p+0x78)), x, y, 1);
    if (((struct Obj00219 *)p)->f7C<=1 && dx < -16)
        func_021D77F8((struct hdr_021D77E8 *)((struct hdr_021D4240 *)(p+0x78)), x, y, 3);
    if (dy>16 || dy < -16 || p[0x79]>20)
        func_021D77E8((u8 *)p+0x78,x,y);
    ++((u8 *)p)[0x79];
    dx=(s8)(x-p[0x82]);
    dy=(s8)(y-p[0x83]);
    if ((((struct Obj00219 *)p)->f84==0 || ((struct Obj00219 *)p)->f84==4) && dy>16)
        func_021D77F8((struct hdr_021D77E8 *)((struct hdr_021D4240 *)(p+0x80)), x, y, 2);
    if ((((struct Obj00219 *)p)->f84==0 || ((struct Obj00219 *)p)->f84==2) && dy < -16)
        func_021D77F8((struct hdr_021D77E8 *)((struct hdr_021D4240 *)(p+0x80)), x, y, 4);
    if (dx>16 || dx < -16 || p[0x81]>20)
        func_021D77E8((u8 *)p+0x80,x,y);
    direction=0;
    ++((u8 *)p)[0x81];
    rx=p[0x8a];
    rx=(s8)(x-rx);
    ry=(s8)(y-p[0x8b]);
    flag=0;
    if (rx>16) direction=1;
    else if (rx < -16) direction=3;
    else if (ry>16) direction=2;
    else if (ry < -16) direction=4;
    if (direction!=0 && (u32)direction!=((struct Obj00219 *)p)->f8C) {
        if (((struct Obj00219 *)p)->f8C+1==(u32)direction ||
            (((struct Obj00219 *)p)->f8C==4 && direction==1)) {
            tmp=((struct Obj00219 *)p)->f90;
            if (tmp<=1) {
                ((struct Obj00219 *)p)->f90=1;
                func_021D77F8((struct hdr_021D77E8 *)((struct hdr_021D4240 *)(p+0x88)), x, y, direction);
                if (((struct Obj00219 *)p)->f8C==4) flag=1;
            } else {
                ((struct Obj00219 *)p)->f90=0;
                func_021D77E8((u8 *)p+0x88,x,y);
            }
        } else if (((struct Obj00219 *)p)->f8C-1==(u32)direction ||
            (((struct Obj00219 *)p)->f8C==1 && direction==4)) {
            tmp1=(u32 *)(p+0x90);
            if (*tmp1==2 || ((struct Obj00219 *)p)->f90==0) {
                ((struct Obj00219 *)p)->f90=2;
                func_021D77F8((struct hdr_021D77E8 *)((struct hdr_021D4240 *)(p+0x88)), x, y, direction);
                if (((struct Obj00219 *)p)->f8C==4) flag=1;
            } else {
                ((struct Obj00219 *)p)->f90=0;
                func_021D77E8((u8 *)p+0x88,x,y);
            }
        } else if (((struct Obj00219 *)p)->f8C==0) {
            ((struct Obj00219 *)p)->f8C=direction;
        }
    }
    if (p[0x89]>20) {
        ((struct Obj00219 *)p)->f90=0;
        func_021D77E8((u8 *)p+0x88,x,y);
    }
    func_021D7810(a, (Ring_021D77E8 *)((Ring_021D4240 *)p), flag);
    ++((u8 *)p)[0x89];
}













void func_021D77E8(u8 *p, u32 a, u32 b)
{
    p[0] = 0;
    ((struct Obj06483 *)p)->f4 = 0;
    p[1] = 0;
    p[2] = a;
    p[3] = b;
}













void func_021D77F8(struct hdr_021D77E8 *p, u32 a, u32 b, int c)
{
    p->f0 = p->f0 + 1;
    p->f4 = c;
    p->f1 = 0;
    p->f2 = a;
    p->f3 = b;
}













void func_021D7810(int unused, Ring_021D77E8 *p, int mode)
{
    if (mode == 1)
    {
        u8 v = p->f99;
        p->ring[p->f9a] = v;
        p->f99 = 0;
        p->f9a = (u8)(p->f9a + 1);
        if (p->f9a >= 5)
            p->f9a = 0;
    }
    p->f99 = (u8)(p->f99 + 1);
}












/*
 * note: 2026-10-02 relaunch R9. The +0xAA/+0xAC str/movs swap was a
 *   scheduler effect of the pre-allocation instruction count before group 2
 *   (a no-arg call inserted earlier shifts it; a band of 5 positions swaps).
 *   func_020173B4 is declared void(void *): its body only forwards to
 *   func_02015F2C, and an int return adds one result copy per call, which
 *   put the second store inside the band. ov195 declares it the same way.
 */
void func_021D785C(u8 *p,u8 *q,void *mon)
{
    Vec_021D77E8 a=d_021DC1F8;
    Vec_021D77E8 b=d_021DC240;
    Vec_021D77E8 c=d_021DC180;
    Vec_021D77E8 d=d_021DC1C8;
    void *m=(void *)func_021D60A4((void *)p);
    func_021D7A44((void *)p,(int)q,(int *)&a,(int *)&b);
    ((struct Obj00994 *)q)->f0=func_02017270(((struct Obj00112 *)p)->f78,m,0,0xd8000,0x48000,0);
    func_02015FD4(*(char * *)&((struct Obj00994 *)q)->f0,2);
    func_02015D80(*(u8 * *)&((struct Obj00994 *)q)->f0,0xd555);
    func_02015D30(((struct Obj00994 *)q)->f0,&b.x);
    func_020173B4(((struct Obj00994 *)q)->f0);
    func_02015CDC(((struct Obj00994 *)q)->f0,&a.x);
    ((struct Obj00994 *)q)->f4=func_02017270(((struct Obj00112 *)p)->f78,m,1,0xd8000,0x48000,0);
    func_02015FD4(*(char * *)&((struct Obj00994 *)q)->f4,2);
    func_02015D80(*(u8 * *)&((struct Obj00994 *)q)->f4,0xd555);
    func_02015D30(((struct Obj00994 *)q)->f4,&c.x);
    func_020173B4(((struct Obj00994 *)q)->f4);
    func_02015CDC(((struct Obj00994 *)q)->f4,&a.x);
    func_021D79A8((void *)p,q,0);
    func_021D7A1C((void *)p, (void * *)q, (Vec *)((Vec_021D77E8 *)&d));
    if(((struct Obj00994 *)q)->fC==1) {
        func_02015EB0(((struct Obj00994 *)q)->f0);
        func_02015EA0(((struct Obj00994 *)q)->f4);
        return;
    }
    func_02015EB0(((struct Obj00994 *)q)->f4);
    func_02015EA0(((struct Obj00994 *)q)->f0);
}












void func_021D797C(unsigned char *p,void **q) {
 func_02015EA0(q[0]);
 func_02015EA0(q[1]);
 func_02015BA4(((struct Obj14069 *)p)->f78,q[0]);
 func_02015BA4(((struct Obj14069 *)p)->f78,q[1]);
 q[0]=0;
 q[1]=0;
}










static inline int mul(int a,int b) {return (int)(((long long)a*b+0x800LL)>>12);}










void func_021D79A8(void *p,unsigned char *q,int radius) {
 Vec_021D79A8 v=d_021DC1EC;
 ((struct Obj00994 *)q)->f4C=mul(d_020A5078[10],radius);
 ((struct Obj00994 *)q)->f50=mul(d_020A5078[11],radius);
 ((struct Obj00994 *)q)->f54=0;
 func_021D7A1C(p, (void * *)q, (Vec *)((Vec_021D77E8 *)&v));
}












void func_021D7A1C(void *p,void **q,Vec *v) {
 Vec r;
 func_0207C9D0(v,(Vec *)((char *)q+0x4c),&r);
 func_02015D94(q[0],(int *)(&r));
 func_02015D94(q[1],(int *)(&r));
}












void func_021D7A44(void *p,int unused,int *a,int *b) {
 int n=func_02017E88(func_021D6064(p),5,0);
 if(n==5) {b[1]=0x299a;a[1]=0xf4cd;return;}
 if(n==37) {a[1]=0xfb33;return;}
 if(n==86) {a[0]=0x10666;a[1]=0x10666;return;}
 if(n==155) {a[0]=0xfe66;a[1]=0xfb33;return;}
 if(n==179) {a[0]=0x10333;a[1]=0x10333;return;}
 if(n==225) {a[0]=0xfccd;a[1]=0xfccd;return;}
 if(n==248) {a[0]=0xfccd;a[1]=0xfccd;return;}
 if(n==310) {a[0]=0xf800;a[1]=0xf800;return;}
 if(n==311) {a[0]=0xfb33;a[1]=0xfb33;return;}
 if(n==391) {a[0]=0xfb33;a[1]=0xf99a;}
}












void **func_021D7B00(u16 *a) {
 void **p=func_02030734(*a,0x6c,0,d_021DC824,0xc1);
 p[0]=0;
 p[1]=0;
 p[2]=func_0201AF80(*a,0);
 return p;
}













void func_021D7B34(int a, char *p)
{
    func_020307B0(((struct Obj23143 *)p)->f8);
    func_020307B0(p);
}












/*
 * interface: caller 021D44C8 loads r0=context,r1=child; complete leaf
 *   021D7B48 is bx lr, consumes neither input and supplies no return value.
 */
void func_021D7B48(void *context, void *child) {}












void func_021D7B4C(unsigned char *a, unsigned char *p, void *arc)
{
    ((struct Obj03285 *)p)->f50 = func_02049EF4(arc, 63, 0, (void **)(p+0x4c), ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f58 = func_02049EF4(arc, 72, 0, (void **)(p+0x54), ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f60 = func_02049EF4(arc, 64, 0, (void **)(p+0x5c), ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f68 = func_02049EF4(arc, 65, 0, (void **)(p+0x64), ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f38 = func_02045B38(0, 2, 188, ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f3C = func_02045B38(0, 2, 89, ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f40 = func_02045B38(0, 2, 92, ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f44 = func_02045B38(0, 2, 90, ((struct Obj00776 *)a)->f0);
    ((struct Obj03285 *)p)->f48 = func_02045B38(0, 2, 91, ((struct Obj00776 *)a)->f0);
}












void func_021D7BF0(void *a, unsigned char *p)
{
    if (((struct Obj02844 *)p)->f4 == 1) func_021D7E84(a, (void **)p);
    func_02045C04(((struct Obj02844 *)p)->f38);
    func_02045C04(((struct Obj02844 *)p)->f3C);
    func_02045C04(((struct Obj02844 *)p)->f40);
    func_02045C04(((struct Obj02844 *)p)->f44);
    func_02045C04(((struct Obj02844 *)p)->f48);
    func_020307B0(((struct Obj02844 *)p)->f50);
    func_020307B0(((struct Obj02844 *)p)->f58);
    func_020307B0(((struct Obj02844 *)p)->f60);
    func_020307B0(((struct Obj02844 *)p)->f68);
}











void func_021D7C38(void *a, unsigned char *p)
{
    void *arc=func_021D6064(a);
    unsigned char i;
    for(i=0;i<10;i++) {
        unsigned int offset=i*4;
        *(void **)(p+offset+0xc)=(void *)func_020450F0(1,d_021DC288[offset],d_021DC288[offset+1],d_021DC288[offset+2],d_021DC288[offset+3],14,1);
    }
    ((struct Obj01547 *)p)->f34=(void *)func_020450F0(4,4,5,24,20,14,1);
    func_021D7F04(a,p,arc);
    func_021D8288(a,p,arc);
    ((struct Obj01547 *)p)->f4=1;
}











void func_021D7CAC(u8 *a,u8 *p)
{
    struct Rec r1,r2;
    struct Point_021D4240 point;
    u8 i;
    void *object;
    void *cell;
    u32 first,second;
    object=func_021D6064(a);
    if(((struct Obj01407 *)a)->f38==0) func_020410D0(2,0,0,32,24,(u32)(*(u8 * *)&((struct Obj05391 *)p)->f4C+12),0,0,32,32);
    else func_020410D0(2,0,0,32,24,(u32)(*(u8 * *)&((struct Obj05391 *)p)->f54+12),0,0,32,32);
    func_02041B6C(2);
    func_02040AE0(6,*(u8 * *)&((struct Obj05391 *)p)->f5C+12,((struct Obj23144 *)(*(u8 * *)&((struct Obj05391 *)p)->f5C))->f8);
    func_02041B6C(6);
    func_020410D0(5,0,0,32,3,(u32)(*(u8 * *)&((struct Obj05391 *)p)->f64+12),0,0,32,32);
    func_02041B6C(5);
    for(i=0;i<10;i++) {
        cell=*(void **)((p+i*4)+0xc);
        func_02045334(cell);
        func_02045374(cell);
        func_020409B4(func_02045730(cell));
    }
    cell=((struct Obj05391 *)p)->f34;
    func_02045334(cell);
    func_02045374(cell);
    func_020409B4(func_02045730(cell));
    if(((struct Obj01407 *)a)->f38==0) {
        first=func_02017E88(object,174,0);
        second=func_02017E88(object,175,0);
        func_0204AB84(*(u32 *)((u32)a+first*4u+0x130u),&r1);
        func_0204B784(((struct Obj01407 *)a)->f198,(const struct Struct36 *)(&r1));
        func_0204B6F4(((struct Obj01407 *)a)->f198,func_020275EC((u8)first),1);
        point.x=96;
        point.y=48;
        func_0204B404(((struct Obj01407 *)a)->f198,(const struct Vec2 *)(&point),0);
        func_0204B3DC(((struct Obj01407 *)a)->f198,1);
        func_0204B84C(((struct Obj01407 *)a)->f198,1);
        if(first!=second) {
            func_0204AB84(*(u32 *)((u32)a+second*4u+0x130u),&r2);
            func_0204B784(((struct Obj01407 *)a)->f19C,(const struct Struct36 *)(&r2));
            func_0204B6F4(((struct Obj01407 *)a)->f19C,func_020275EC((u8)second),1);
            point.x=130;
            point.y=48;
            func_0204B404(((struct Obj01407 *)a)->f19C,(const struct Vec2 *)(&point),0);
            func_0204B3DC(((struct Obj01407 *)a)->f19C,1);
            func_0204B84C(((struct Obj01407 *)a)->f19C,1);
        } else func_0204B3DC(((struct Obj01407 *)a)->f19C,0);
    } else {
        func_0204B3DC(((struct Obj01407 *)a)->f198,0);
        func_0204B3DC(((struct Obj01407 *)a)->f19C,0);
    }
    func_0204B878(((struct Obj01407 *)a)->f178,3);
}










void func_021D7E84(void *p,void **q) {
 unsigned char i;
 for(i=0;i<10;i++) {
  func_020452E8(q[3+i]);
 }
 func_020452E8(q[13]);
 q[1]=0;
}










void func_021D7EAC(unsigned char *p, void *a1)
{
    func_02041300(1, 0, 0, 0, 19, 21, 16);
    func_02041B6C(1);
    func_02041570(4, 0);
    func_02041B6C(4);
    func_0204B3DC(((struct Obj10512 *)p)->f198, 0);
    func_0204B3DC(((struct Obj10512 *)p)->f19C, 0);
    func_0204B878(((struct Obj10512 *)p)->f178, 0);
}










/*
 * note (2026-10-02): slot order closed by two source facts. (1) func_02017E88's third parameter is
 *   a buffer pointer (void *), so the 0x9a and 0x8d calls pass the v2 buffer directly with no
 *   conversion; casting it to u32 lets the compiler share one conversion temp, which moves v2 below
 *   the named locals. (2) The species argument in the first t arm is a named local; nested, t lands lowest.
 */
void func_021D7F04(u8 *p,u8 *q,void *mon)
{
    void *ws;
    u32 v;
    void *t;
    void *v2;
    void *ws2;
    u32 s18;
    u32 A;
    u32 B;
    u32 C;
    void *ws3,*ws4,*ws5;
    u32 s30,s34,n,tt,r,k;
    u16 pal;
    u32 tile;
    u16 x;
    u32 species;
    if(((struct Obj00112 *)p)->f38==0) {
        func_021D618C(p,((struct Obj01256 *)q)->fC,8,1,1,0x3c40);
        ws=func_0201EC64(((struct Obj00112 *)p)->f0);
        v=func_02017E88(mon,5,0);
        pal=0x440;
        if(((struct Obj23145 *)(*(u8 * *)&((struct Obj00112 *)p)->f8))->f18==0) v=(*(u16 **)(q+8))[v];
        if(func_02017EB4(mon)==1) pal=0xc80;
        if(v==999) {
            func_021D6214(p,((struct Obj01256 *)q)->fC,ws,0x16,0x41,1,pal);
        } else {
            func_0201EFA4(ws,0,v,3,2,1);
            func_021D6214(p,((struct Obj01256 *)q)->fC,ws,9,0x41,1,pal);
        }
        func_0201ED04(ws);
        func_021D618C(p,*(u32 *)&((struct Obj01256 *)q)->f10,10,1,1,0x3c40);
        if(((struct Obj00112 *)p)->f38==0) {species=func_02017E88(mon,5,0); t=func_02045EC0(g_020A7370,species);}
        else t=func_02045EC0(g_020A7370,0x28a);
        tile=(u32)func_02045770(((struct Obj01256 *)q)->f10);
        pal=0x440;
        func_0201C724(((struct Obj00112 *)p)->f84,tile,0x41,1,(u32)t,*(u32 *)&((struct Obj00112 *)p)->f80,pal);
        func_02045808(t);
        func_021D618C(p,((struct Obj01256 *)q)->f14,12,1,1,0x3c40);
        func_021D618C(p,((struct Obj01256 *)q)->f18,13,1,1,0x3c40);
        v2=func_020457B0(0x20,((struct Obj00112 *)p)->f0);
        ws2=func_0201EC64(((struct Obj00112 *)p)->f0);
        r=func_02017E88(mon,0x9a,v2);
        if(r==0) pal=0x14c0;
        else if(r==1) pal=0xc80;
        func_02017E88(mon,0x8d,v2);
        func_0201EE0C(ws2,0,v2,0,1,2);
        func_021D6214(p,((struct Obj01256 *)q)->f18,ws2,14,0x41,1,pal);
        func_0201ED04(ws2);
        func_02045808(v2);
        func_021D618C(p,((struct Obj01256 *)q)->f1C,15,1,1,0x3c40);
        ws3=func_0201EC64(((struct Obj00112 *)p)->f0);
        x=func_02017E88(mon,7,0);
        func_0201EFA4(ws3,0,x,5,2,1);
        func_021D6214(p,((struct Obj01256 *)q)->f1C,ws3,16,0x41,1,0x440);
        func_0201ED04(ws3);
        n=func_02017E88(mon,0x9e,0);
        s18=func_02017E88(mon,8,0);
        s30=func_02017E88(mon,5,0);
        tt=func_02017E88(mon,0x6f,0);
        A=func_02018584((u16)s30,(u16)tt,(u16)(n+1));
        s34=func_02017E88(mon,5,0);
        tt=func_02017E88(mon,0x6f,0);
        B=func_02018584((u16)s34,(u16)tt,(u16)n);
        C=A-s18;
        if(n==100) C=0;
        func_021D618C(p,((struct Obj01256 *)q)->f20,17,1,1,0x3c40);
        ws4=func_0201EC64(((struct Obj00112 *)p)->f0);
        func_0201EFA4(ws4,0,s18,7,0,1);
        func_021D6214(p,((struct Obj01256 *)q)->f24,ws4,18,1,1,0x440);
        func_0201ED04(ws4);
        func_021D618C(p,((struct Obj01256 *)q)->f28,19,1,1,0x3c40);
        func_021D618C(p,((struct Obj01256 *)q)->f2C,20,1,1,0x440);
        ws5=func_0201EC64(((struct Obj00112 *)p)->f0);
        func_0201EFA4(ws5,0,C,6,0,1);
        func_021D6214(p,((struct Obj01256 *)q)->f2C,ws5,21,0x21,1,0x440);
        func_0201ED04(ws5);
        if(n!=100) {
            r=A-B-C;
            k=(r<<6)/(A-B);
            if(r!=0 && k==0) k=1;
            if(k==0x40) k=k-1;
            func_02043AF4(func_02045770(((struct Obj01256 *)q)->f30),0,3,(u16)k,3,5);
        }
    }
    ((struct Obj01256 *)q)->f0=1;
}










/*
 * note: 2026-10-02 relaunch R8. The 0 passed as the number style to the
 *   later SetNumber calls is the same u8 local that later holds the best
 *   row index (stack slot 0x14); max is seeded from it before the table
 *   copies, and the loop counter is zeroed before the row lookup.
 *   func_0201EC74 takes an int heap here (no u8 narrowing in the caller).
 */
void func_021D8288(u8 *a, u8 *p, void *mon)
{
    void *s6c;
    void *s68;
    u32 v5c;
    int y;
    u32 known;
    u32 isEgg;
    u32 v4c;
    u32 v48;
    u32 v44;
    u32 v40;
    u32 v3c;
    u32 v38;
    u32 v34;
    u32 v30;
    u32 v2c;
    u32 v28;
    u32 v24;
    u32 v20;
    u32 flags;
    void *str;
    void *ws;
    void *t;
    u32 f96;
    u32 fl0;
    u32 fl1;
    u32 fl2;
    u32 fl3;
    u16 msg;
    u16 msgAlt;
    u8 best;

    y = 0;
    isEgg = func_02017E88(mon, 0x4c, 0);
    v5c = func_02017E88(mon, 0x70, 0);
    v4c = func_02017E88(mon, 9, 0);
    v48 = func_02017E88(mon, 0x8f, 0);
    v44 = func_02017E88(mon, 0x90, 0);
    v40 = func_02017E88(mon, 0x91, 0);
    v3c = func_02017E88(mon, 0x92, 0);
    v38 = func_02017E88(mon, 0x93, 0);
    v34 = func_02017E88(mon, 0x94, 0);
    v30 = func_02017E88(mon, 0x99, 0);
    v2c = func_02017E88(mon, 0x6d, 0);
    v28 = func_02017E88(mon, 0x77, 0);
    v24 = func_02017E88(mon, 0, 0);
    v20 = func_02017E88(mon, 0x95, 0);
    f96 = func_02017E88(mon, 0x96, 0);
    fl0 = func_0202F498(mon, 0);
    fl1 = func_0202F498(mon, 1);
    fl2 = func_0202F498(mon, 2);
    fl3 = func_0202F498(mon, 3);
    flags = fl0 | fl1 | fl2 | fl3;
    known = func_02018488(mon, func_02012944(((struct Obj23146 *)(*(u8 * *)&((struct Obj00112 *)a)->f8))->f8));

    if (isEgg == 0) {
        t = func_02045EC0(((struct Obj01547 *)p)->f38, v5c);
        func_0201C724(((struct Obj00112 *)a)->f84, (u32)func_02045770(((struct Obj01547 *)p)->f34), (s16_021D7E84)1, (s16_021D7E84)1, (u32)t, (u32)(((struct Obj00112 *)a)->f80), 0x440);
        func_02045808(t);
        y = 0x10;
    }
    str = func_020457B0(0x100, ((struct Obj00112 *)a)->f0);
    ws = func_0201EC74(10, 0x20, ((struct Obj00112 *)a)->f0);
    if (isEgg == 0) {
        if (f96 == 0x7531) {
            msgAlt = 0x29;
            msg = 0x2b;
            if (v2c == 1) {
                msgAlt = 0x2d;
                msg = 0x2f;
            }
            switch (v28) {
            case 1: case 2: case 3:
                f96 = 0x7536;
                break;
            case 4: case 5:
                f96 = 0x7534;
                break;
            case 7: case 8:
                f96 = 0x7535;
                msg = msgAlt;
                break;
            case 10: case 11: case 12:
                f96 = 0x7537;
                msg = msgAlt;
                break;
            case 15:
                f96 = 0x7538;
                break;
            default:
                v20 = 0x7539;
                msg = msgAlt;
                break;
            }
        } else if (f96 >= 0x753a && f96 <= 0x753d && flags == 1) {
            switch (f96 - 0x753a) {
            case 0: msg = 0x31; break;
            case 1: msg = 0x32; break;
            case 2: msg = 0x33; break;
            case 3: msg = 0x34; break;
            }
        } else if (v2c == 0) {
            if (v20 == 0) {
                if (f96 == 0x7532) {
                    msg = 0x1b;
                } else {
                    msg = 0x19;
                }
            } else if (v20 <= 60000) {
                msg = 0x1d;
            } else {
                msg = 0x1f;
            }
        } else {
            msg = 0x21;
            if (v20 != 0) {
                msg = 0x23;
            }
        }
        if (known == 0) {
            if (f96 < 0x753a || f96 > 0x753d) {
                msg++;
            }
        }
    } else if (v2c == 0) {
        if (known == 1) {
            msg = 0x53;
        } else {
            msg = 0x54;
        }
    } else {
        msg = 0x55;
        if (known != 1) {
            msg = 0x56;
        }
    }
    s68 = func_021D8784(a, p, v20);
    s6c = func_021D8784(a, p, f96);
    func_0201EFA4(ws, 0, v3c, 2, 2, 1);
    best = 0;
    func_0201EFA4(ws, 1, v38, 2, best, 1);
    func_0201EFA4(ws, 2, v34, 2, best, 1);
    func_0201EFA4(ws, 3, v30, 3, best, 1);
    func_0201EE0C(ws, 4, s6c, 0, 1, 2);
    func_0201EFA4(ws, 5, v48, 2, 2, 1);
    func_0201EFA4(ws, 6, v44, 2, best, 1);
    func_0201EFA4(ws, 7, v40, 2, best, 1);
    func_0201EE0C(ws, 8, s68, best, 1, 2);
    t = func_02045EC0(((struct Obj01547 *)p)->f38, msg);
    func_0201F250(ws, str, t);
    func_0201C724(((struct Obj00112 *)a)->f84, (u32)func_02045770(((struct Obj01547 *)p)->f34), (s16_021D7E84)1, (s16_021D7E84)(y + 1), (u32)str, (u32)(((struct Obj00112 *)a)->f80), 0x440);
    func_0201ED04(ws);
    y += sub_0201D2C8(str) << 4;
    func_02045808(s68);
    func_02045808(s6c);
    func_02045808(t);
    func_02045808(str);
    if (isEgg == 0) {
        struct Tbl6 ids;
        struct Tbl36 rows;
        u8 max;
        u8 i;
        const u8 *row;
        u32 v;
        max = best;
        ids = *(const struct Tbl6 *)d_021DC24C;
        rows = *(const struct Tbl36 *)d_021DC264;
        i = 0;
        row = rows.v[(u8)(v24 % 6)];
        for (; i < 6; i++) {
            v = func_02017E88(mon, ids.v[row[i]], 0);
            if (max < v) {
                max = v;
                best = row[i];
            }
        }
        t = func_02045EC0(((struct Obj01547 *)p)->f38, best * 5 + 0x35 + max % 5);
        func_0201C724(((struct Obj00112 *)a)->f84, (u32)func_02045770(((struct Obj01547 *)p)->f34), (s16_021D7E84)1, (s16_021D7E84)(y + 1), (u32)t, (u32)(((struct Obj00112 *)a)->f80), 0x440);
        func_02045808(t);
    } else {
        u32 id;
        if (v4c <= 5) {
            id = 0x57;
        } else if (v4c <= 10) {
            id = 0x58;
        } else if (v4c <= 40) {
            id = 0x59;
        } else {
            id = 0x5a;
        }
        t = func_02045EC0(((struct Obj01547 *)p)->f38, id);
        func_0201C724(((struct Obj00112 *)a)->f84, (u32)func_02045770(((struct Obj01547 *)p)->f34), (s16_021D7E84)1, (s16_021D7E84)(y + 1), (u32)t, (u32)(((struct Obj00112 *)a)->f80), 0x440);
        func_02045808(t);
    }
}









void *func_021D8784(void *a, unsigned char *p, unsigned int n)
{
    unsigned int bank = func_0202F688(n);
    unsigned int index = func_0202F6D8(n);
    switch (bank) {
    case 89: return func_02045EC0(((struct Obj01547 *)p)->f3C, index);
    case 92: return func_02045EC0(((struct Obj01547 *)p)->f40, index);
    case 90: return func_02045EC0(((struct Obj01547 *)p)->f44, index);
    case 91: return func_02045EC0(((struct Obj01547 *)p)->f48, index);
    default: return func_02045EC0(((struct Obj01547 *)p)->f3C, 0);
    }
}










void *func_021D87E0(u16 *a) {
 struct S_021D8784 *p = func_02030734(*a, 0x3b8, 0, d_021DC834, 0xaf);
 p->a = 0;
 p->b60 = 0;
 p->f50 = func_02045B38(0, 2, 0xaa, *a);
 return p;
}











void func_021D881C(void *a, u8 *p)
{
    func_02045C04(((struct Obj23147 *)p)->f50);
    func_020307B0(p);
}










void func_021D8830(unsigned char *a, unsigned char *p)
{
    func_021D8A2C(a,p);
    if (((struct Obj00091 *)p)->f8 == 1) {
        if (func_0201C6B4(((struct Obj03816 *)a)->f84) == 1) {
            func_021D9670(a,p);
            func_021D9568(a,p);
            ((struct Obj00091 *)p)->f8=0;
        }
    } else func_021D92B0(a,p);
    if (p[0x60]) p[0x60]--;
}









void func_021D8884(unsigned char *a, unsigned char *p, void *arc)
{
    ((struct Obj05392 *)p)->f2C = func_02049EF4(arc, 66, 0, (void **)(p+0x28), ((struct Obj00776 *)a)->f0);
    ((struct Obj05392 *)p)->f34 = func_02049EF4(arc, 67, 0, (void **)(p+0x30), ((struct Obj00776 *)a)->f0);
    ((struct Obj05392 *)p)->f3C = func_02049EF4(arc, 68, 0, (void **)(p+0x38), ((struct Obj00776 *)a)->f0);
    ((struct Obj05392 *)p)->f44 = func_02049EF4(arc, 69, 0, (void **)(p+0x40), ((struct Obj00776 *)a)->f0);
    ((struct Obj05392 *)p)->f4C = func_02049E74(arc, 12, 0, (u32)(p+0x48), ((struct Obj00776 *)a)->f0);
    ((struct Obj05392 *)p)->f6C = func_021DBA90(((struct Obj00776 *)a)->f0, (u32)(((struct Obj00776 *)a)->f174));
}









void func_021D8904(void *a, struct S_021D8884 *s) {
 if (s->a == 1) func_021D909C(a, (unsigned char *)s);
 func_021DBAC0(s->f6c);
 func_020307B0(s->f4c);
 func_020307B0(s->f2c);
 func_020307B0(s->f34);
 func_020307B0(s->f3c);
 func_020307B0(s->f44);
}







/*
 * note (2026-10-02): the func_021D9440 call is inside the loop (its arg is i), so &d/&g is recomputed
 *   per group; hi/lo are enum locals so (0x19<<22)+(2<<16) is not folded.
 */
void func_021D8938(u8 *a,u8 *p)
{
    struct Desc_021D4240 d;
    struct Grid g;
    enum E hi,lo;
    u32 base;
    u8 i;
    d.x=0;d.y=0;d.kind=10;d.flag=0;d.z=0;
    ((struct Obj10514 *)p)->f54=func_0204B294((void *)((struct Obj04509 *)a)->f174,((struct Obj04509 *)a)->fF8,((struct Obj04509 *)a)->fC4,((struct Obj04509 *)a)->f12C,&d,0,((struct Obj04509 *)a)->f0);
    func_0204B3DC(((struct Obj10514 *)p)->f54,0);
    g.f4=8;
    g.f8=((struct Obj04509 *)a)->fB8;
    g.f12=0;
    g.f16=0;
    hi=0x19;
    lo=2;
    g.f17=lo;
    g.f18=0;
    g.f20=0;
    base=(hi<<22)+(lo<<16);
    for(i=0;i<10;i++){
        u8 *e;
        g.f6=func_021D9440(p,i);
        e=p+i*0x14;
        g.f0=((struct Obj10515 *)e)->f7C=func_02043754((void *)(base-(i+1)*0x660),0x11,3,0x20,((struct Obj04509 *)a)->f0);
        ((struct Obj10515 *)e)->f80=func_021DBAD0(((struct Obj10514 *)p)->f6C,(const u8 *)(&g));
        func_021DBCA4(((struct Obj10515 *)e)->f80,0);
    }
}













void func_021D89FC(void *unused, unsigned char *s) {
 unsigned char i;
 func_0204B3B4(((struct Obj23148 *)s)->f54);
 for (i = 0; i < 10; i++) {
  struct OamEntry *e = (struct OamEntry *)(s + i * 20);
  func_021DBC3C(e->f80);
  func_020437AC(e->f7c);
 }
}













/*
 * note (2026-10-02): the p+0x64 store precedes the p+0x58 store; with source order 58/64/68 the
 *   allocator hoists constant 0 into r7 instead.
 */
void func_021D8A2C(u8 *a,u8 *p)
{
    int index;
    if(((struct Obj00136 *)a)->f44==1) {
        if(p[0x10]==0) return;
        index=func_021D8E24(a,p);
        if(func_020362DC()!=1 && index==-1) return;
        ((struct Obj00091 *)p)->f5C=0;
        func_021D5A9C((char *)a,0);
        if(func_020362DC()==1) {
            func_021D8EA8(a,p);
            a[0x1c]=0;
        } else {
            ((struct Obj00091 *)p)->f64=1;
            p[0x58]=(u8)index;
            ((struct Obj00091 *)p)->f68=1;
            p[0x59]=func_021D9428(p,(u8)index);
            func_021D5A9C((char *)a,0);
            a[0x1c]=1;
        }
        func_020061E4(0x54c);
        func_021D964C(a,p);
        func_021D949C(a,p);
    } else {
        if(*(u32 *)&((struct Obj00091 *)p)->f8==0 && func_021D8AD0(a,p)==0) func_021D8CD0(a,p);
    }
}













int func_021D8AD0(u8 *a,u8 *p)
{
    u8 i,index,narrowDelta;
    s16_021D4240 shortDelta;
    int position;
    if(func_020362DC()==2) {
        func_021D5A9C((char *)a,1);
        func_0204B878(((struct Obj00136 *)a)->f194,9);
        func_0204B3DC(((struct Obj00091 *)p)->f54,0);
        p[0x58]=255;
        p[0x59]=255;
        ((struct Obj00091 *)p)->f68=1;
        func_021D964C(a,p);
        func_021D9670(a,p);
        a[0x1c]=0;
        func_020061E4(1361);
        return 1;
    }
    if(a[0x1c]==1) {
        if(func_020362DC()==1 || func_020362DC()==128 || func_020362DC()==64) {
            position=-16;
            ((struct Obj00091 *)p)->f5C=0;
            *(int *)&((struct Obj00091 *)p)->f64=0;
            for(i=0;i<10;i++) {
                if(p[0x59]==*(u16 *)(p+0x70+i*20)) position=func_021D9440(p,i);
            }
            if(position < -4 || position >144) func_021D8EA8(a,p);
            func_021D964C(a,p);
            func_021D949C(a,p);
            func_020061E4(1352);
            a[0x1c]=0;
            return 1;
        }
    } else if(func_0203633C()==128) {
        index=p[0x58]+1;
        if(index>=10) index-=10;
        if(*(u16 *)(p+0x70+index*20)!=0xffff) {
            p[0x58]=index;
            ((struct Obj00091 *)p)->f68=1;
            if(func_021D9440(p,p[0x58])>128) {
                narrowDelta=func_021D9440(p,p[0x58])-128;
                func_021D8F0C(a,p,narrowDelta);
            }
            func_021D8ED0(a,p,p[0x58]);
            func_021D964C(a,p);
            func_021D949C(a,p);
            func_020061E4(1352);
        }
        return 1;
    } else if(func_0203633C()==64) {
        index=p[0x58];
        if(index==0) index=9;
        else index-=1;
        if(*(u16 *)(p+0x70+index*20)!=0xffff) {
            p[0x58]=index;
            ((struct Obj00091 *)p)->f68=1;
            if(func_021D9440(p,p[0x58])<8) {
                shortDelta=func_021D9440(p,p[0x58])-8;
                func_021D8F0C(a,p,shortDelta);
            }
            func_021D8ED0(a,p,p[0x58]);
            func_021D964C(a,p);
            func_021D949C(a,p);
            func_020061E4(1352);
        }
        return 1;
    }
    return 0;
}













/*
 * proof: The delta subtract at 021D8D9C is full-word modulo arithmetic,
 *   then sign-extends its low halfword. Twice that s16_021D4240 is -65536..65534,
 *   spelled multiply, permitting negative input. Velocity sums wrap as
 *   u32 before conversion to signed int and truncating division by 2.
 *   Negative velocity +1 and positive velocity -1 cannot overflow int;
 *   their halved outgoing values are explicitly narrowed to s16_021D4240.
 * interface: 02035C60's result is read by the original despite its matched
 *   void forwarding declaration. 021D9428 forwards target in live r1 to
 *   021D93E4; the original explicitly narrows target to u8 before the call.
 */
void func_021D8CD0(u8 *a,u8 *p)
{
    int index, delta, velocity;
    if(((struct Obj00136 *)a)->f24==7) {
        func_021D5A9C((char *)a,1);
        func_0204B878(((struct Obj00136 *)a)->f194,9);
        func_0204B3DC(((struct Obj00091 *)p)->f54,0);
        p[0x58]=255;
        p[0x59]=255;
        ((struct Obj00091 *)p)->f68=1;
        a[0x1c]=1;
        func_021D964C(a,p);
        func_021D9670(a,p);
        func_020061E4(1361);
        return;
    }
    if(func_02035C60()==1 && ((struct Obj00136 *)a)->f28>8 && ((struct Obj00136 *)a)->f28<144) {
        index=func_021D8E24(a,p);
        if(index!=-1) {
            p[0x58]=(u8)index;
            ((struct Obj00091 *)p)->f68=1;
            p[0x59]=func_021D9428(p,(u8)index);
            ((struct Obj00091 *)p)->f64=1;
            ((struct Obj00091 *)p)->f5C=0;
            func_0204B3DC(((struct Obj00091 *)p)->f54,0);
            func_021D964C(a,p);
            func_021D949C(a,p);
        }
        a[0x1c]=1;
        return;
    }
    if(func_02035C38()==1 && ((struct Obj00091 *)p)->f64==1 && ((struct Obj00136 *)a)->f28>8 && ((struct Obj00136 *)a)->f28<144) {
        delta=(s16_021D4240)(((struct Obj00136 *)a)->f34-((struct Obj00136 *)a)->f2C);
        velocity=delta*2;
        func_021D8F0C(a,p,delta);
        if(velocity>=0 && ((struct Obj00091 *)p)->f5C>0 && velocity<((struct Obj00091 *)p)->f5C) {
            ((struct Obj00091 *)p)->f5C=(int)((u32)((struct Obj00091 *)p)->f5C+(u32)velocity)/2;
            return;
        }
        if(velocity<=0 && ((struct Obj00091 *)p)->f5C<0 && velocity>((struct Obj00091 *)p)->f5C) {
            ((struct Obj00091 *)p)->f5C=(int)((u32)((struct Obj00091 *)p)->f5C+(u32)velocity)/2;
            return;
        }
        ((struct Obj00091 *)p)->f5C=velocity;
        return;
    }
    ((struct Obj00091 *)p)->f64=0;
    if(((struct Obj00091 *)p)->f5C<0) {
        ((struct Obj00091 *)p)->f5C+=1;
        func_021D8F0C(a,p,(s16_021D4240)(((struct Obj00091 *)p)->f5C/2));
    }
    if(((struct Obj00091 *)p)->f5C>0) {
        ((struct Obj00091 *)p)->f5C-=1;
        func_021D8F0C(a,p,(s16_021D4240)(((struct Obj00091 *)p)->f5C/2));
    }
}














int func_021D8E24(void *unused, u8 *p)
{
    Rect r[11];
    u8 i;
    int v;

    for (i = 0; i < 10; i++) {
        v = func_021D9440(p, i);
        r[i].w = 8;
        r[i].h = 0x90;
        if (v < 0)
            r[i].x = 0;
        else if (v > 0xa8)
            r[i].x = 0xa8;
        else
            r[i].x = v;
        if (v + 0x18 < 0)
            r[i].y = 0;
        else if (v + 0x18 > 0xa8)
            r[i].y = 0xa8;
        else
            r[i].y = v + 0x18;
        if (r[i].x == 0 && r[i].y == 0)
            r[i].x = 0xfd;
        if (func_021D9428(p, i) == 0xffff)
            r[i].x = 0xfd;
    }
    r[10].x = 0xff;
    return func_02035C08(r);
}













void func_021D8EA8(u8 *a,u8 *p)
{
    func_021D8ED0(a,p,(u8)(((((struct Obj00091 *)p)->f14+23)/24)%10));
}













void func_021D8ED0(u8 *a,u8 *p,u8 n)
{
    Point_021D89FC pt;
    pt.x=8;
    pt.y=func_021D9440(p,n);
    func_0204B404(((struct Obj00091 *)p)->f54,(const struct Vec2 *)(&pt),0);
    p[0x58]=n;
    *(int *)&((struct Obj00091 *)p)->f68=1;
    p[0x59]=func_021D9428(p,n);
}













void func_021D8F0C(void *unused, unsigned char *p, int delta)
{
    int max = (p[0x10] - 6) * 24;
    unsigned int old;
    if (max < 0) max = 0;
    if (delta > 24) delta = 24;
    if (delta < -24) delta = -24;
    old = ((struct Obj05393 *)p)->f14;
    if ((short)old + delta < 0) ((struct Obj05393 *)p)->f14 = 0;
    else if (old + delta > (unsigned int)max) ((struct Obj05393 *)p)->f14 = max;
    else ((struct Obj05393 *)p)->f14 = old + delta;
    if (delta != 0) ((struct Obj05393 *)p)->fC = 1;
}












void func_021D8F50(void *a, unsigned char *p)
{
    unsigned char i;
    p[0x58]=255;
    p[0x59]=255;
    p[0x5a]=255;
    ((struct Obj02845 *)p)->f14=0;
    ((struct Obj02845 *)p)->f0=1;
    ((struct Obj02845 *)p)->f4=0;
    ((struct Obj02845 *)p)->f8=0;
    ((struct Obj02845 *)p)->fC=1;
    ((struct Obj02845 *)p)->f20=0;
    ((struct Obj02845 *)p)->f24=0;
    for(i=0;i<10;i++) {
        *(unsigned short *)(p+i*20+0x70)=func_021D9428(p,i);
        func_021D91F0(a,p,p+0x70+i*20);
    }
}












/*
 * lever: The image's 20-byte records are subscripted per field, avoiding
 *   the pointer-arithmetic spelling's cached object-field base and spill.
 * proof: i is initialized u8 and bounded by 10; i*20 fits int.
 *   Loaded address payloads use u32 +12 for full-word modulo arithmetic.
 */
void func_021D8FAC(u8 *a,u8 *p)
{
    u8 i;
    u16 value;
    func_020410D0(2,0,0,32,24,((struct Obj01548 *)p)->f28+12,0,0,32,32);
    func_02041B6C(2);
    func_02040AE0(6,*(u8 * *)&((struct Obj01548 *)p)->f30+12,((struct Obj23150 *)(*(u8 * *)&((struct Obj01548 *)p)->f30))->f8);
    func_02041B6C(6);
    func_020410D0(5,0,0,32,3,((struct Obj01548 *)p)->f40+12,0,0,32,32);
    func_02041B6C(5);
    for(i=0;i<10;i++) {
        value=((struct List *)p)->entries[i].id;
        func_021DBE2C(((struct List *)p)->entries[i].object,8,func_021D9440(p,i));
        if(value!=0xffff) {
            func_021DBCA4(((struct List *)p)->entries[i].object,1);
            func_021DBCF4(((struct List *)p)->entries[i].object);
        } else func_021DBCA4(((struct List *)p)->entries[i].object,0);
    }
    ((struct Obj01548 *)p)->f14=0;
    p[0x58]=255;
    p[0x59]=255;
    p[0x5a]=255;
    ((struct Obj01548 *)p)->f0=1;
    ((struct Obj01548 *)p)->fC=1;
    func_0204B878(((struct Obj23149 *)a)->f180,5);
}












void func_021D909C(u8 *a,u8 *p)
{
    ((struct Obj04510 *)p)->f0=0;
    if(((struct Obj04510 *)p)->f20!=0) {
        func_020452E8(((struct Obj04510 *)p)->f20);
        ((struct Obj04510 *)p)->f20=0;
    }
    if(((struct Obj04510 *)p)->f24!=0) {
        func_020452E8(((struct Obj04510 *)p)->f24);
        ((struct Obj04510 *)p)->f24=0;
    }
}












void func_021D90C0(unsigned char *a, unsigned char *p)
{
    unsigned char i;
    for(i=0;i<10;i++) func_021DBCA4(*(void **)(p+0x80+i*20),0);
    func_02041300(1,0,0,0,19,21,16);
    func_020409B4(1);
    ((struct Obj23152 *)p)->f0=0;
    func_0204B878(((struct Obj23151 *)a)->f180,2);
}












/*
 * lever: Initialize the count after the clear loop so its zero shares the
 *   clear-store value without a redundant live zero register.
 * proof: Loop indices are initialized u8 values bounded by 80 or 10.
 *   func_021DBF2C field 5 reads byte +12 of immutable d_021DC2F8;
 *   all 80 original records have selector 0..4 (B8/table-proof.log).
 *   count begins with five ROM bytes 1,1,1,1,1 and never exceeds 81.
 *   All scaling and count increments fit int; stores preserve u8 narrowing.
 * interface: func_021D9428 forwards live r1 to func_021D93E4, whose
 *   own matched body consumes target; caller sets r1 despite stale one-arg
 *   declaration in func_021D9428's source.
 */
void func_021D911C(u8 *a,u8 *p)
{
    struct Counts counts = d_021DC2B0;
    void *object;
    u8 i, n, selector;
    object=func_021D6064(a);
    for(i=0;i<80;i++) *(u32 *)(p+0x138+i*8)=0;
    n=0;
    for(i=0;i<80;i++) {
        if(func_02017E88(object,func_021DBF2C(i,0),0)==1) {
            selector=func_021DBF2C(i,5);
            *(u32 *)(p+0x138+n*8)=1;
            p[0x13c+n*8]=i;
            p[0x13d+n*8]=selector;
            p[0x13e + n*8]=counts.value[selector];
            counts.value[selector]++;
            n++;
        }
    }
    p[0x10]=n;
    for(i=0;i<10;i++) *(u16 *)(p+0x70+i*20)=func_021D9428(p,i);
}












void func_021D91EC(void *a0, void *a1)
{
}












void func_021D91F0(u8 *a,u8 *p,u8 *entry)
{
    u8 *record;
    u8 *pixels;
    void *text;
    void *buffer;
    void *object;
    void *source;
    record=p+0x138+((struct Obj06484 *)entry)->f0*8;
    if (((struct Obj10518 *)record)->f0!=1) return;
    pixels=*(u8 * *)&((struct Obj23153 *)(*(u8 * *)&((struct Obj10517 *)p)->f48))->f14;
    source=func_020437D4(((struct Obj06484 *)entry)->fC);
    if (((struct Obj06484 *)entry)->f0==p[0x59]) pixels+=0x660;
    func_02082D44(pixels,source,0x660);
    text=func_02045EC0(((struct Obj10517 *)p)->f50,record[5]+160);
    buffer=func_020457B0(32,((struct Obj10516 *)a)->f0);
    object=func_0201EC64(((struct Obj10516 *)a)->f0);
    func_0201EFA4(object,0,record[6],2,2,1);
    func_0201F250(object,buffer,text);
    func_0201DD78(1,2,0);
    func_0201C7A4(((struct Obj06484 *)entry)->fC,10,6,buffer,((struct Obj10516 *)a)->f80);
    func_0201DD68();
    func_02045808(text);
    func_02045808(buffer);
    func_0201ED04(object);
    func_021DBCF4(((struct Obj06484 *)entry)->f10);
}












/*
 * proof: loop i starts at zero and tests i<10 after each byte increment;
 * i*20 <=180. Each other byte index is guarded <10 before *20.
 * prototype: 021D92EA loads r1 for 021D9428 despite its legacy one-input
 * source. Preserve this observed full-word argument in the caller extern.
 */
void func_021D92B0(u8 *a,u8 *p)
{
    int changed;
    u8 *entries;
    u8 i;
    u32 value;
    u8 *entry;
    s16_021D4240 y;
    changed=0;
    entries=p;
    entries+=0x70;
    for(i=0;i<10;i++) {
        if(((struct Obj00091 *)p)->fC==1) {
            y=func_021D9440(p,i);
            func_021DBE2C(*(u8 **)((p+i*20)+0x80),8,y);
            value=func_021D9428(p,i);
            if(value==65535) {
                *(u16 *)((p+i*20)+0x70)=value;
                func_021DBCA4(*(u8 **)((p+i*20)+0x80),0);
            } else if(value!=*(u16 *)((p+i*20)+0x70)) {
                changed=1;
                *(u16 *)((p+i*20)+0x70)=value;
                func_021D91F0(a,p,entries+i*20);
                func_021DBCA4(*(u8 **)((p+i*20)+0x80),1);
            }
        }
        entry=p+i*20;
        if(((struct Obj08147 *)entry)->f78==1 && func_0201C6C4(((struct Obj03816 *)a)->f84,((struct Obj08147 *)entry)->f7C)==0) {
            ((struct Obj08147 *)entry)->f78=0;
            func_021DBCF4(((struct Obj08147 *)entry)->f80);
        }
    }
    if(changed==1 && p[0x60]==0) {
        func_0200616C((void *)1605,1);
        p[0x60]=3;
    }
    if(((struct Obj00091 *)p)->f68==1) {
        if(p[0x58]<10) func_021D91F0(a,p,(p+0x70)+p[0x58]*20);
        if(p[0x5a]<10) func_021D91F0(a,p,(p+0x70)+p[0x5a]*20);
        p[0x5a]=p[0x58];
        ((struct Obj00091 *)p)->f68=0;
    }
    ((struct Obj00091 *)p)->fC=0;
}












u32 func_021D93E4(u8 *p, u32 target)
{
    u8 row;
    s8 delta;
    row = ((struct Obj23154 *)p)->f14 / 24u;
    delta = target - (u8)(row % 10);
    if (delta < -2) delta += 10;
    if (delta > 8) delta -= 10;
    return (u8)(row + delta);
}












unsigned int func_021D9428(unsigned char *p, unsigned int target)
{
    unsigned int r = func_021D93E4(p, target);

    if (r < p[0x10])
        return r;
    return 0xffff;
}











s16_021D4240 func_021D9440(u8 *p, u32 target)
{
    u32 position;
    u8 row, remainder;
    s8 delta;
    position = ((struct Obj23156 *)p)->f14;
    row = position / 24u;
    remainder = position % 24u;
    delta = target - (u8)(row % 10);
    if (delta < -2) delta += 10;
    if (delta > 8 && row > 6) delta -= 10;
    return delta * 24 + 8 - remainder;
}











/*
 * extent: two zero alignment bytes at 021D9566 follow the 202-byte body.
 * proof: index is ldrb at 021D94DA, hence 0..255; index*8+316
 * is at most 2356 and has no signed overflow. No selector bound assumed.
 */
void func_021D949C(u8 *a,u8 *p)
{
    u8 index;
    void *text;
    *(u32 *)&((struct Obj03815 *)p)->f20=func_020450F0(4,5,7,22,2,14,1);
    *(u32 *)&((struct Obj03815 *)p)->f24=func_020450F0(4,1,16,30,4,14,1);
    index=(p+p[0x59]*8)[0x13c];
    text=func_02045EC0(((struct Obj03815 *)p)->f50,func_021DBF2C(index,3));
    func_0201C724(((struct Obj00136 *)a)->f84,(u32)func_02045770(((struct Obj03815 *)p)->f20),1,1,(u32)text,((struct Obj00136 *)a)->f80,1088);
    func_02045808(text);
    text=func_02045EC0(((struct Obj03815 *)p)->f50,func_021DBF94(index));
    func_0201C724(((struct Obj00136 *)a)->f84,(u32)func_02045770(((struct Obj03815 *)p)->f24),1,1,(u32)text,((struct Obj00136 *)a)->f80,1088);
    func_02045808(text);
    ((struct Obj03815 *)p)->f8=1;
}











/*
 * extent: two zero alignment bytes at 021D964A follow the 226-byte body.
 * proof: selector is a byte; selector*8+316 <=2356. Position stores
 * initialize every byte of the eight-byte descriptor before passing it.
 * prototype: 0204B294 leaves 0204CFDC's pointer return live at 0204B318;
 * 021D960E stores it. Keep the own body's u32,u32,u32,u32,u32,u16,u16
 * inputs, and expose the observed r0 result despite its legacy void return.
 */
void func_021D9568(u8 *a,u8 *p)
{
    void *cell;
    void *archive;
    u8 index;
    ObjPos pos;
    index=(p+p[0x59]*8)[0x13c];
    cell=((struct Obj02484 *)p)->f20;
    func_02045334(cell);
    func_02045374(cell);
    func_02041B6C(func_02045730(cell));
    cell=((struct Obj02484 *)p)->f24;
    func_02045334(cell);
    func_02045374(cell);
    func_02041B6C(func_02045730(cell));
    archive=func_020490F4(78,((struct Obj03816 *)a)->f0);
    ((struct Obj02484 *)p)->f18=func_0204A6C8((void *)((u32)archive),func_021DBF2C(index,1),0,1,((struct Obj03816 *)a)->f0);
    func_02049238(archive);
    pos.x=128;
    pos.y=100;
    pos.priority=10;
    pos.flags=0;
    pos.z=0;
    *(u32 *)&((struct Obj02484 *)p)->f1C=(u32)func_0204B294((void *)((struct Obj03816 *)a)->f174,((struct Obj02484 *)p)->f18,((struct Obj03816 *)a)->fB4,((struct Obj03816 *)a)->f128,&pos,1,((struct Obj03816 *)a)->f0);
    func_0204B6F4(((struct Obj02484 *)p)->f1C,(u8)func_021DBF2C(index,2),1);
    func_0204B3DC(((struct Obj02484 *)p)->f1C,1);
    func_02040AE0(6,*(u8 * *)&((struct Obj02484 *)p)->f38+12,((struct Obj23157 *)(*(u8 * *)&((struct Obj02484 *)p)->f38))->f8);
    func_02041B6C(6);
    ((struct Obj02484 *)p)->f4=1;
}











void func_021D964C(u8 *a,u8 *p)
{
    if(((struct Obj05394 *)p)->f20!=0) {
        func_020452E8(((struct Obj05394 *)p)->f20);
        ((struct Obj05394 *)p)->f20=0;
    }
    if(((struct Obj05394 *)p)->f24!=0) {
        func_020452E8(((struct Obj05394 *)p)->f24);
        ((struct Obj05394 *)p)->f24=0;
    }
}











void func_021D9670(u8 *a,u8 *p)
{
    u8 *q;
    if(((struct Obj06485 *)p)->f4==1) {
        func_0204A8D4((u32)(((struct Obj06485 *)p)->f18));
        func_0204B3B4(((struct Obj06485 *)p)->f1C);
        func_02041570(4,0);
        func_02041B6C(4);
        ((struct Obj06485 *)p)->f4=0;
        q=*(u8 * *)&((struct Obj06485 *)p)->f30;
        func_02040AE0(6,q+0xc,((struct Obj23158 *)q)->f8);
        func_02041B6C(6);
    }
}











u8 *func_021D96B0(u8 *a)
{
    u8 *p;
    u8 i;
    p=func_02030734(((struct Obj14075 *)a)->f0,296,0,d_021DC844,315);
    ((struct Obj02189 *)p)->f0=0;
    ((struct Obj02189 *)p)->f4=0;
    ((struct Obj02189 *)p)->f8=0;
    ((struct Obj02189 *)p)->f10=0;
    ((struct Obj02189 *)p)->f14=0;
    ((struct Obj02189 *)p)->f18=0;
    ((struct Obj02189 *)p)->f24=0;
    p[42]=5;
    p[41]=255;
    if ((*(u8 **)(a+8))[13]==2 && ((struct Obj23159 *)(*(u8 * *)&((struct Obj14075 *)a)->f8))->f14!=0) p[43]=5;
    else p[43]=4;
    for(i=0;i<5;i++) {
        p[0xb0+i*24]=255;
        *(u32 *)(p+0xb4+i*24)=0;
    }
    return p;
}











void func_021D9734(u8 *a,u8 *p)
{
    func_020307B0(p);
}











/*
 * proof: all scaled indices are ldrb or byte loop counters, hence
 * *24 <=6120 and *4 <=1020. p[40]+1 <=256 before the byte store;
 * signed %8 uses the reloaded byte 0..255, with no overflow or division
 * failure. No smaller range or successful callee result is assumed.
 */
void func_021D9740(u8 *a,u8 *p)
{
    u8 i;
    int ready;
    void *cell;
    if(((struct Obj00502 *)p)->f4==0 && ((struct Obj00502 *)p)->f8==0 && ((struct Obj00502 *)p)->f10==0 && ((struct Obj00502 *)p)->f20==0) func_021DA958(a,p);
    if(((struct Obj00502 *)p)->f4==1) {
        ready=1;
        for(i=0;i<=7;i++) {
            if(func_0201C6C4(((struct Obj00136 *)a)->f84,func_02045770(*(void **)((p+i*4)+0x5c)))==1) {
                ready=0;
                break;
            }
        }
        if(ready==1) {
            for(i=0;i<=7;i++) {
                cell=*(void **)((p+i*4)+0x5c);
                func_02045334(cell);
                func_02045374(cell);
                func_02041B6C(func_02045730(cell));
            }
            func_021D9E44(a,p);
            ((struct Obj00502 *)p)->f4=0;
        }
    }
    if(((struct Obj00502 *)p)->f8==1) {
        ready=1;
        for(i=8;i<=11;i++) {
            if(func_0201C6C4(((struct Obj00136 *)a)->f84,func_02045770(*(void **)((p+i*4)+0x5c)))==1) {
                ready=0;
                break;
            }
        }
        if(ready==1) {
            for(i=8;i<=11;i++) {
                cell=*(void **)((p+i*4)+0x5c);
                func_02045334(cell);
                func_02045374(cell);
                func_02041B6C(func_02045730(cell));
            }
            func_021D9EF0(a,p);
            ((struct Obj00502 *)p)->f8=0;
        }
    }
    if(((struct Obj00502 *)p)->fC==1) {
        if(func_0201C6C4(((struct Obj00136 *)a)->f84,func_02045770(((struct Obj00502 *)p)->f8C))==0) {
            cell=((struct Obj00502 *)p)->f8C;
            func_02045334(cell);
            func_02045374(cell);
            func_02041B6C(func_02045730(cell));
            ((struct Obj00502 *)p)->fC=0;
        }
    }
    if(((struct Obj00502 *)p)->f10==1 && func_0201C6B4(((struct Obj00136 *)a)->f84)==1) {
        ((struct Obj00502 *)p)->f14=0;
        func_021DBA78((p+0xb0)+p[0x2a]*24,0);
        p[0x2a]=5;
        func_021DB468(a,p,p[0x29],0);
        func_0204B3DC(((struct Obj00502 *)p)->f9C,0);
        ((struct Obj00502 *)p)->f10=0;
    }
    for(i=0;i<5;i++) func_021DB7D0(a,p,(p+0xb0)+i*24);
    if(((struct Obj00502 *)p)->f20==1) {
        p[40]++;
        if((int)p[40]%8<4) {
            if(((struct Obj00502 *)p)->f24==1) func_0204B878(*(void **)((p+p[41]*24)+0xb8),15);
            else func_021DBA78((p+0xb0)+p[41]*24,0);
        } else {
            if(((struct Obj00502 *)p)->f24==1) func_0204B878(*(void **)((p+p[41]*24)+0xb8),16);
            else func_021DBA78((p+0xb0)+p[41]*24,1);
        }
        if(p[40]>16) ((struct Obj00136 *)a)->f50=2;
    }
}











void func_021D9980(u8 *a,u8 *p,void *resource)
{
    ((struct Obj05395 *)p)->f38=func_02049EF4(resource,72,0,(void **)(p+0x34),((struct Obj00776 *)a)->f0);
    ((struct Obj05395 *)p)->f40=func_02049EF4(resource,73,0,(void **)(p+0x3c),((struct Obj00776 *)a)->f0);
    ((struct Obj05395 *)p)->f48=func_02049EF4(resource,74,0,(void **)(p+0x44),((struct Obj00776 *)a)->f0);
    ((struct Obj05395 *)p)->f50=func_02049EF4(resource,75,0,(void **)(p+0x4c),((struct Obj00776 *)a)->f0);
    ((struct Obj05395 *)p)->f58=func_02049EF4(resource,76,0,(void **)(p+0x54),((struct Obj00776 *)a)->f0);
    ((struct Obj05395 *)p)->fA4=func_021DBA90(((struct Obj00776 *)a)->f0,(u32)(((struct Obj00776 *)a)->f174));
}











void func_021D9A04(u8 *a, u8 *p)
{
    if (((struct Obj02190 *)p)->f0 == 1) {
        if ((*(u8 **)(a + 8))[13] == 2) func_021DA84C(a, p);
        else func_021D9D44(a, p);
    }
    func_021DBAC0(*(u8 * *)&((struct Obj02190 *)p)->fA4);
    func_020307B0(((struct Obj02190 *)p)->f38);
    func_020307B0(((struct Obj02190 *)p)->f40);
    func_020307B0(((struct Obj02190 *)p)->f48);
    func_020307B0(((struct Obj02190 *)p)->f50);
    func_020307B0(((struct Obj02190 *)p)->f58);
}











/*
 * extent: two zero alignment bytes at 021D9BD2 follow the 390-byte body.
 * proof: i is byte-wrapped; i*24 <=6120, every descriptor byte initialized.
 * No bound smaller than the ldrb domain is assumed for p[43].
 * prototype: 0204B294 leaves 0204CFDC's pointer result live at 0204B318;
 * this caller stores r0 after every call. Keep all seven own-body inputs.
 */
void func_021D9A4C(u8 *a,u8 *p)
{
    ObjPos pos;
    u8 i;
    pos.x=159;
    pos.y=52;
    pos.priority=10;
    pos.flags=1;
    i=0;
    pos.z=0;
    *(u32 *)&((struct Obj01939 *)p)->f90=(u32)func_0204B294((void *)*(u32 *)&((struct Obj00344 *)a)->f174,((struct Obj00344 *)a)->fE4,((struct Obj00344 *)a)->fAC,((struct Obj00344 *)a)->f114,&pos,1,((struct Obj00344 *)a)->f0);
    func_0204B3DC(((struct Obj01939 *)p)->f90,0);
    pos.x=172;
    pos.y=56;
    *(u32 *)&((struct Obj01939 *)p)->f94=(u32)func_0204B294((void *)*(u32 *)&((struct Obj00344 *)a)->f174,((struct Obj00344 *)a)->fD8,((struct Obj00344 *)a)->fA8,*(u32 *)&((struct Obj00344 *)a)->f10C,&pos,1,((struct Obj00344 *)a)->f0);
    func_0204B3DC(((struct Obj01939 *)p)->f94,0);
    pos.flags=0;
    *(u32 *)&((struct Obj01939 *)p)->f98=(u32)func_0204B294((void *)*(u32 *)&((struct Obj00344 *)a)->f174,((struct Obj00344 *)a)->fEC,((struct Obj00344 *)a)->fC4,((struct Obj00344 *)a)->f11C,&pos,0,((struct Obj00344 *)a)->f0);
    func_0204B3DC(((struct Obj01939 *)p)->f98,0);
    pos.z=5;
    pos.priority=8;
    *(u32 *)&((struct Obj01939 *)p)->f9C=(u32)func_0204B294((void *)*(u32 *)&((struct Obj00344 *)a)->f174,((struct Obj00344 *)a)->fEC,((struct Obj00344 *)a)->fC4,((struct Obj00344 *)a)->f11C,&pos,0,((struct Obj00344 *)a)->f0);
    func_0204B3DC(((struct Obj01939 *)p)->f9C,0);
    func_0204B92C(((struct Obj01939 *)p)->f9C,1);
    pos.z=2;
    pos.priority=4;
    pos.flags=0;
    *(u32 *)&((struct Obj01939 *)p)->fA0=(u32)func_0204B294((void *)*(u32 *)&((struct Obj00344 *)a)->f174,((struct Obj00344 *)a)->fEC,((struct Obj00344 *)a)->fC4,((struct Obj00344 *)a)->f11C,&pos,0,((struct Obj00344 *)a)->f0);
    func_0204B3DC(((struct Obj01939 *)p)->fA0,0);
    func_0204B92C(((struct Obj01939 *)p)->fA0,1);
    for(;i<p[0x2b];i++) func_021DB700(a,p,(p+0xb0)+i*24,i);
}











void func_021D9BD4(void *a, u8 *p)
{
    u8 i;
    for (i = 0; i < p[0x2b]; i++)
        func_021DB7B8(a, p, p + 0xb0 + i * 24);
    func_0204B3B4(((struct Obj05396 *)p)->f90);
    func_0204B3B4(((struct Obj05396 *)p)->f94);
    func_0204B3B4(((struct Obj05396 *)p)->f98);
    func_0204B3B4(((struct Obj05396 *)p)->f9C);
    func_0204B3B4(((struct Obj05396 *)p)->fA0);
}











void func_021D9C3C(void *a,u8 *p)
{
    u8 i;
    for(i=0;i<13;i++) {
        *(void **)(p+0x5c+i*4)=(void *)func_020450F0(4,d_021DC2C2[i*4],d_021DC2C2[i*4+1],d_021DC2C2[i*4+2],d_021DC2C2[i*4+3],14,1);
    }
    func_02045798(((struct Obj04511 *)p)->f60,13);
    func_021D9E30(a,(int)p);
    for(i=0;i<p[43];i++) func_021DB7D4(a,p,p+0xb0+i*24);
    p[41]=255;
    ((struct Obj04511 *)p)->f0=1;
    ((struct Obj04511 *)p)->f20=0;
    p[40]=0;
}











void func_021D9CD0(u8 *a,u8 *p)
{
    u8 i;
    func_020410D0(2,0,0,32,24,((struct Obj04512 *)p)->f34+12,0,0,32,32);
    func_02041B6C(2);
    func_021D9E44(a,p);
    for(i=0;i<p[0x2b];i++) func_021DB964(a,p,p+0xb0+i*24);
    func_0204B878(((struct Obj00136 *)a)->f17C,4);
}











void func_021D9D44(void *a, u8 *p)
{
    u8 i;
    for (i = 0; i < p[0x2b]; i++)
        func_021DB9E8(a, p, p + 0xb0 + i * 24);
    for (i = 0; i < 13; i++)
        func_020452E8(*(void **)(p + 0x5c + i * 4));
    ((struct Obj14076 *)p)->f0 = 0;
}











void func_021D9D94(u8 *a,u8 *p)
{
    u8 i;
    for(i=0;i<p[0x2b];i++) func_021DB9FC(a,p,p+0xb0+i*24);
    func_02041300(1,0,0,0,19,21,16);
    func_020409B4(1);
    func_02041570(4,0);
    func_02041B6C(4);
    func_0204B3DC(((struct Obj10520 *)p)->f90,0);
    func_0204B3DC(((struct Obj10520 *)p)->f94,0);
    func_0204B3DC(((struct Obj10519 *)a)->f198,0);
    func_0204B3DC(((struct Obj10519 *)a)->f19C,0);
    func_0204B878(((struct Obj10519 *)a)->f17C,1);
}












void func_021D9E30(void *a, int b)
{
    func_021DA0B0(a, (u8 *)b);
    func_021DA3FC(a, (u8 *)b);
}











void func_021D9E44(u8 *a,u8 *p)
{
    u8 i;
    void *cell;
    i=0;
    func_02041570(4,0);
    for(;i<=7;i++) {
        cell=*(void **)(p+0x5c+i*4);
        func_02045334(cell);
        func_02045374(cell);
        func_020409B4(func_02045730(cell));
    }
    func_02040AE0(6,*(u8 * *)&((struct Obj04512 *)p)->f3C+12,*((u32 *)(*(u8 * *)&((struct Obj04512 *)p)->f3C+8)));
    func_02041B6C(6);
    func_020410D0(5,0,0,32,3,((struct Obj04512 *)p)->f4C+12,0,0,32,32);
    func_02041B6C(5);
    func_0204B3DC(((struct Obj04512 *)p)->f90,1);
    func_0204B3DC(((struct Obj04512 *)p)->f94,0);
    func_0204B3DC(((struct Obj00136 *)a)->f198,0);
    func_0204B3DC(((struct Obj00136 *)a)->f19C,0);
}











void func_021D9EE8(u8 *a,u8 *p)
{
    func_021DA488(a,p);
}










/*
 * extent: two zero alignment bytes at 021DA0AE follow the 446-byte body.
 * proof: i is a byte, i*24 <=6120. first/second remain full-word u32
 * results; unsigned address multiply/add preserve original modulo-2^32
 * lsl/add without invented selector bounds. 0204AB84 writes all nine words
 * before 0204B784 reads them; both Point_021D9EF0 halfwords are stored before use.
 */
void func_021D9EF0(u8 *a,u8 *p)
{
    Rec r1,r2;
    Point_021D9EF0 point;
    u8 i;
    void *cell;
    void *object;
    u32 first,second;
    func_02041570(4,0);
    for(i=8;i<=11;i++) {
        cell=*(void **)((p+i*4)+0x5c);
        func_02045334(cell);
        func_02045374(cell);
        func_020409B4(func_02045730(cell));
    }
    i=0;
    func_020409E0(6,*(u8 * *)&((struct Obj00536 *)p)->f44+12,((struct Obj23161 *)(*(u8 * *)&((struct Obj00536 *)p)->f44))->f8,0);
    func_02040AE0(6,*(u8 * *)&((struct Obj00536 *)p)->f44+12,((struct Obj23162 *)(*(u8 * *)&((struct Obj00536 *)p)->f44))->f8);
    func_02041B6C(6);
    func_020410D0(5,0,0,32,3,(u32)(*(u8 * *)&((struct Obj00536 *)p)->f54+12),0,0,32,32);
    func_02041B6C(5);
    func_0204B3DC(((struct Obj00536 *)p)->f90,0);
    func_0204B3DC(((struct Obj00536 *)p)->f94,1);
    for(;i<p[0x2b];i++) func_021DB964(a,p,(p+0xb0)+i*24);
    object=func_021D6064(a);
    first=func_02017E88(object,174,0);
    second=func_02017E88(object,175,0);
    func_0204AB84(*(u32 *)(((u32)a+first*4u)+0x130u),(struct Rec *)(&r1));
    func_0204B784(((struct Obj00136 *)a)->f198,(const struct Struct36 *)(&r1));
    func_0204B6F4(((struct Obj00136 *)a)->f198,func_020275EC((u8)first),1);
    point.x=208;
    point.y=120;
    func_0204B404(((struct Obj00136 *)a)->f198,(const struct Vec2 *)(&point),0);
    func_0204B3DC(((struct Obj00136 *)a)->f198,1);
    func_0204B84C(((struct Obj00136 *)a)->f198,0);
    if(first!=second) {
        func_0204AB84(*(u32 *)(((u32)a+second*4u)+0x130u),(struct Rec *)(&r2));
        func_0204B784(((struct Obj00136 *)a)->f19C,(const struct Struct36 *)(&r2));
        func_0204B6F4(((struct Obj00136 *)a)->f19C,func_020275EC((u8)second),1);
        point.x=240;
        point.y=120;
        func_0204B404(((struct Obj00136 *)a)->f19C,(const struct Vec2 *)(&point),0);
        func_0204B3DC(((struct Obj00136 *)a)->f19C,1);
        func_0204B84C(((struct Obj00136 *)a)->f19C,0);
    } else func_0204B3DC(((struct Obj00136 *)a)->f19C,0);
}










/*
 * semantics: full-word results retained; only explicit u8 call arguments
 * narrow. No signed arithmetic or caller-domain assumptions.
 * prototype: 618C final stack argument is u16; func_021DB6D0 is declared to
 * return u16 so its result needs no extra truncation at the call.
 */
void func_021DA0B0(u8 *a,u8 *p)
{
    void *data;
    u32 selected;
    int one;
    void *o1,*o2,*o3,*o4,*o5,*o6,*o7;
    u32 value;
    void *t1,*t2,*str;
    data=(void *)func_021D60A4((char *)a);
    selected=func_02017E1C(data,112,0);
    one=1;
    func_021D618C(a,(u32)((struct Obj01061 *)p)->f5C,110,25,one,15424);
    o1=func_0201EC64(((struct Obj00112 *)a)->f0);
    func_0201EFA4(o1,0,func_02017E1C(data,160,0),3,one,one);
    func_021D62B4(a,(unsigned int)(((struct Obj01061 *)p)->f5C),o1,119,89,one,1088);
    func_0201ED04(o1);
    func_021D618C(a,(u32)((struct Obj01061 *)p)->f5C,117,93,one,1088);
    o2=func_0201EC64(((struct Obj00112 *)a)->f0);
    func_0201EFA4(o2,0,func_02017E1C(data,161,0),3,one,one);
    func_021D62B4(a,(unsigned int)(((struct Obj01061 *)p)->f5C),o2,118,121,one,1088);
    func_0201ED04(o2);
    func_021D618C(a,(u32)((struct Obj01061 *)p)->f64,111,one,one,func_021DB6D0((u32)a,(u32)p,selected,one));
    o3=func_0201EC64(((struct Obj00112 *)a)->f0);
    func_0201EFA4(o3,0,func_02017E1C(data,162,0),3,one,one);
    func_021D62B4(a,(unsigned int)(((struct Obj01061 *)p)->f64),o3,120,105,one,1088);
    func_0201ED04(o3);
    func_021D618C(a,(u32)((struct Obj01061 *)p)->f68,112,one,one,func_021DB6D0((u32)a,(u32)p,selected,2));
    o4=func_0201EC64(((struct Obj00112 *)a)->f0);
    func_0201EFA4(o4,0,func_02017E1C(data,163,0),3,one,one);
    func_021D62B4(a,(unsigned int)(((struct Obj01061 *)p)->f68),o4,121,105,one,1088);
    func_0201ED04(o4);
    func_021D618C(a,(u32)((struct Obj01061 *)p)->f6C,113,one,one,func_021DB6D0((u32)a,(u32)p,selected,3));
    o5=func_0201EC64(((struct Obj00112 *)a)->f0);
    func_0201EFA4(o5,0,func_02017E1C(data,165,0),3,one,one);
    func_021D62B4(a,(unsigned int)(((struct Obj01061 *)p)->f6C),o5,122,105,one,1088);
    func_0201ED04(o5);
    func_021D618C(a,(u32)((struct Obj01061 *)p)->f70,114,one,one,func_021DB6D0((u32)a,(u32)p,selected,4));
    o6=func_0201EC64(((struct Obj00112 *)a)->f0);
    func_0201EFA4(o6,0,func_02017E1C(data,166,0),3,one,one);
    func_021D62B4(a,(unsigned int)(((struct Obj01061 *)p)->f70),o6,123,105,one,1088);
    func_0201ED04(o6);
    func_021D618C(a,(u32)((struct Obj01061 *)p)->f74,115,one,one,func_021DB6D0((u32)a,(u32)p,selected,5));
    o7=func_0201EC64(((struct Obj00112 *)a)->f0);
    func_0201EFA4(o7,0,func_02017E1C(data,164,0),3,one,one);
    func_021D62B4(a,(unsigned int)(((struct Obj01061 *)p)->f74),o7,124,105,one,1088);
    func_0201ED04(o7);
    func_021D618C(a,(u32)((struct Obj01061 *)p)->f78,116,5,one,15424);
    value=func_02017E1C(data,10,0);
    t1=func_02045B38(0,2,183,((struct Obj00112 *)a)->f0);
    str=func_02045EC0(t1,value);
    func_0201C724(((struct Obj00112 *)a)->f84,(int)func_02045770(((struct Obj01061 *)p)->f78),5,17,(u32)str,*(int *)&((struct Obj00112 *)a)->f80,1088);
    func_02045808(str);
    func_02045C04(t1);
    t2=func_02045B38(0,2,182,((struct Obj00112 *)a)->f0);
    str=func_02045EC0(t2,value);
    func_0201C724(((struct Obj00112 *)a)->f84,(int)func_02045770(((struct Obj01061 *)p)->f78),65,one,(u32)str,*(int *)&((struct Obj00112 *)a)->f80,1088);
    func_02045808(str);
    func_02045C04(t2);
    ((struct Obj01061 *)p)->f4=one;
}









void func_021DA3FC(u8 *a,u8 *b) {
    void *p,*bmp;
    u16 x,y;
    int kind,value,first,last;
    p=(void *)func_021D60A4((char *)a);
    x=func_02017E1C(p,161,0);
    y=func_02017E1C(p,160,0);
    kind=func_0202D034(y,x);
    value=func_0202D01C(y,x,48);
    bmp=func_02045770(((struct Obj01061 *)b)->f60);
    if((u8)(kind+254)<=1) {first=7;last=8;}
    else if(kind==1) {first=9;last=10;}
    else {first=5;last=6;}
    func_02043AF4(bmp,0,3,value,1,first);
    func_02043AF4(bmp,0,4,value,1,last);
}









/*
 * extent: two-byte zero alignment padding at 0x021DA6A2.
 * semantics: C1E8 forwards BD28(a,2); BDB4 case 2 at 0201BE0C
 * returns ldrb, bounding kind to 0..255 and (kind+16)*4 to 1084.
 * AB84 copies all 36 output bytes at 0204AB9C..0204ABB0 before B784
 * reads them. Other scalar arithmetic uses u8 indices or constants.
 */
void func_021DA488(u8 *a,u8 *p)
{
    void *data,*object1,*object2,*table,*str;
    u8 i;
    int zero,one,id,kind;
    u32 count,value;
    Record record;
    data=func_021D6064(a);
    zero=0;
    for(i=8;i<=11;i++) func_02043B5C(func_02045770(*(void **)(p+0x5c+i*4)),zero);
    if(p[41]<4) id=func_02017E88(data,p[41]+54,(void *)zero);
    else if(p[41]==255) {
        if((*(u8 **)(a+8))[13]==2 && p[43]==5) id=((struct Obj23163 *)(*(u8 * *)&((struct Obj04513 *)a)->f8))->f14;
        else id=func_02017E88(data,54,0);
    } else id=((struct Obj23164 *)(*(u8 * *)&((struct Obj04513 *)a)->f8))->f14;
    one=1;
    func_021D618C(a, (u32)((struct Obj01408 *)p)->f7C, 149, 1, one, 15424);
    kind=func_0201C1E8((u16)id);
    func_0204AB84(*(u32 *)(a+(kind+16)*4+152),(struct Rec *)(&record));
    func_0204B784(((struct Obj01408 *)p)->f94,(const struct Struct36 *)(&record));
    func_0204B6F4(((struct Obj01408 *)p)->f94,func_02027604(kind),1);
    func_021D618C(a, (u32)((struct Obj01408 *)p)->f80, 147, 1, one, 15424);
    count=func_0201C1D8(id);
    if(count<=1) func_021D618C(a, (u32)((struct Obj01408 *)p)->f80, 154, 87, one, 1088);
    else {
        object1=func_0201EC64(((struct Obj04513 *)a)->f0);
        func_0201EFA4(object1,0,count,3,one,one);
        func_021D6214(a,(unsigned int)(((struct Obj01408 *)p)->f80),object1,150,81,one,1088);
        func_0201ED04(object1);
    }
    func_021D618C(a, (u32)((struct Obj01408 *)p)->f84, 148, 1, 1, 15424);
    value=func_0201BD28(id,4);
    if(func_0201C1F4(id)==1 || value==0) func_021D618C(a, (u32)((struct Obj01408 *)p)->f84, 154, 87, 1, 1088);
    else {
        object2=func_0201EC64(((struct Obj04513 *)a)->f0);
        func_0201EFA4(object2,0,value,3,1,1);
        func_021D6214(a,(unsigned int)(((struct Obj01408 *)p)->f84),object2,151,81,1,1088);
        func_0201ED04(object2);
    }
    table=func_02045B38(0,2,202,((struct Obj04513 *)a)->f0);
    str=func_02045EC0(table,id);
    func_0201C724(((struct Obj04513 *)a)->f84,(int)func_02045770(((struct Obj01408 *)p)->f88),1,1,(u32)str,((struct Obj04513 *)a)->f80,1088);
    func_02045808(str);
    func_02045C04(table);
    ((struct Obj01408 *)p)->fC=0;
    ((struct Obj01408 *)p)->f8=1;
}









/*
 * semantics: u8 loop indices bound multiplication to 255*24; no signed
 * overflow. Descriptor_021D4240 fields are initialized before the call. BAD0 reads
 * offsets 0,4,6,8,12,16,17,18,20; trailing padding is never read.
 */
void func_021DA6A4(u8 *a,u8 *p)
{
    u8 i;
    Descriptor_021D4240 desc;
    for(i=0;i<13;i++) {
        *(void **)(p+0x5c+i*4)=(void *)func_020450F0(4,d_021DC2C2[i*4],d_021DC2C2[i*4+1],d_021DC2C2[i*4+2],d_021DC2C2[i*4+3],14,1);
    }
    func_02045798(((struct Obj01940 *)p)->f60,13);
    func_021D9EE8(a,p);
    for(i=0;i<p[43];i++) func_021DB7D4(a,p,p+0xb0+i*24);
    if(p[43]==5) {
        ((struct Obj01940 *)p)->fA8=func_02043678(11,4,32,((struct Obj02846 *)a)->f0);
        func_021D614C(a,*(int *)&((struct Obj01940 *)p)->fA8,193,5,9,1088);
        desc.x=32;
        desc.y=160;
        desc.resource=((struct Obj02846 *)a)->fB8;
        desc.value=0;
        desc.a=0;
        desc.b=0;
        desc.c=0;
        desc.d=0;
        desc.bmp=((struct Obj01940 *)p)->fA8;
        *(u8 * *)&((struct Obj01940 *)p)->fAC=func_021DBAD0(((struct Obj01940 *)p)->fA4,(const u8 *)(&desc));
        func_021DBCA4(*(u8 * *)&((struct Obj01940 *)p)->fAC,0);
    }
    p[41]=255;
    ((struct Obj01940 *)p)->f0=1;
    ((struct Obj01940 *)p)->f20=0;
    p[40]=0;
}








/*
 * extent: two-byte zero alignment padding at 0x021DA84A.
 */
void func_021DA7A4(u8 *a,u8 *b) {
    u8 i;
    func_020410D0(2,0,0,32,24,(u32)(*(u8 * *)&((struct Obj00536 *)b)->f34+12),0,0,32,32);
    func_02041B6C(2);
    func_021D9EF0(a,b);
    for(i=0;i<b[43];i++) func_021DB964(a,b,b+176+i*24);
    func_0204B878(((struct Obj00136 *)a)->f17C,4);
    if(b[43]==5) b[41]=4;else b[41]=0;
    func_021D5A9C((char *)a,0);
    func_021DB468(a,b,b[41],0);
}








void func_021DA84C(u8 *a,u8 *b) {
    u8 i;
    if(b[43]==5) {
        func_020437AC(((struct Obj02190 *)b)->fA8);
        func_021DBC3C(((struct Obj02190 *)b)->fAC);
    }
    for(i=0;i<b[43];i++) func_021DB9E8(a,b,b+176+i*24);
    for(i=0;i<13;i++) func_020452E8(*(void **)(b+92+i*4));
    *(int *)&((struct Obj02190 *)b)->f0=0;
}








void func_021DA8BC(u8 *a,u8 *b) {
    u8 i;
    for(i=0;i<b[43];i++) func_021DB9FC(a,b,b+176+i*24);
    func_02041300(1,0,0,0,19,21,16);
    func_020409B4(1);
    func_02041570(4,0);
    func_02041B6C(4);
    func_0204B3DC(((struct Obj10522 *)b)->f90,0);
    func_0204B3DC(((struct Obj10522 *)b)->f94,0);
    func_0204B3DC(((struct Obj10521 *)a)->f198,0);
    func_0204B3DC(((struct Obj10521 *)a)->f19C,0);
    func_0204B878(((struct Obj10521 *)a)->f17C,1);
}








void func_021DA958(u8 *a,u8 *b) {
    if ((*(u8 **)(a+8))[13] != 2) {
        if (func_021DA998(a,b)==0) func_021DABCC(a,b);
    } else {
        if (func_021DAEE4(a,b)==0) func_021DB140(a,b);
    }
    if (func_02035C38()==0) ((struct Obj00026 *)b)->f1C=0;
}








/*
 * lever: original shared return0 branch is goto out; selected byte local
 *   preserves the loaded value across its neighbouring selector store.
 * semantics: every key poll is independent; selector bytes retain their
 *   full0..255 domain, so promoted selector*24 is at most6120. No menu
 *   bound is assumed. BA54 unconditionally writes both point halfwords
 *   at BA5E/BA6A before4B404 reads them; no default or success assumption.
 * interfaces: own matched callees, else own-region matched callers.
 *   362DC own body returns a full-word pointer payload; this caller uses
 *   full r0 as a scalar comparison, retained as u32. No argument narrowed
 *   beyond original/callee width. All original call/store order retained.
 */
int func_021DA998(u8 *a,u8 *b)
{
    struct Vec2 point;
    if (((struct Obj00026 *)b)->f1C==1) return 0;
    if (((struct Obj00132 *)a)->f44==1) {
        if (func_020362DC()!=1) goto out;
            b[41]=0;
            a[28]=0;
            func_021D5A9C((char *)a,0);
            func_021DB468(a,b,b[41],0);
            func_021D9EE8(a,b);
            func_020061E4(1356);
            return 1;
    } else {
        if (func_020362DC()==2 && ((struct Obj00026 *)b)->f14==0) {
            func_021D5A9C((char *)a,1);
            func_0204B878(*(struct Obj * *)&((struct Obj00132 *)a)->f194,9);
            func_021DBA78(b+176+b[41]*24,0);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->f98,0);
            func_021D9E30(a,(int)b);
            a[28]=0;
            func_020061E4(1361);
            return 1;
        }
        if (a[28]==1) {
            if (func_020362DC()==0) goto out;
                a[28]=0;
                b[42]=5;
                func_021DB468(a,b,b[41],0);
                func_020061E4(1352);
                return 1;
        } else {
            if (func_020362DC()==1) {
                if ((*(u8 **)(a+8))[13]==6) goto out;
                if (((struct Obj00026 *)b)->f14==0) {
                    u8 selected;
                    ((struct Obj00026 *)b)->f14=1;
                    selected=b[41];
                    b[42]=selected;
                    func_021DBA78(b+176+selected*24,2);
                    func_021DBA54(b+176+b[42]*24,(short unsigned int *)((u8 *)&point));
                    func_0204B404(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,&point,0);
                    func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,1);
                    func_0204B9A0(*(struct Actor * *)&((struct Obj00026 *)b)->f9C);
                    func_020061E4(1356);
                } else {
                    if (b[42]!=b[41]) {
                        func_021DB508(a,b,b[42],b[41]);
                        func_020061E4(1357);
                    } else {
                        ((struct Obj00026 *)b)->f14=0;
                        func_021DB468(a,b,b[41],0);
                        func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,0);
                        func_020061E4(1356);
                    }
                }
                return 1;
            }
            if (func_020362DC()==2 && ((struct Obj00026 *)b)->f14==1) {
                func_021DBA78(b+176+b[42]*24,0);
                func_021DB468(a,b,b[41],0);
                func_0204B878(*(struct Obj * *)&((struct Obj00132 *)a)->f194,9);
                func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,0);
                ((struct Obj00026 *)b)->f14=0;
                b[42]=5;
                func_020061E4(1361);
                return 1;
            }
            if (func_020362DC()==64 || func_020362DC()==128) {
                func_021DB3F0(a,b);
                return 1;
            }
        }
    }
out:
    return 0;
}







/*
 * lever: initialized bounded descriptor list and explicit controller arms;
 *   unsigned distance wrap preserves the original signed tests at INT_MIN.
 * output: BA14 writes all four bytes for each index0..4; terminal record
 *   first byte255 stops ADC before any remaining terminal bytes are read.
 *   Both C08->BBC and BA4->B58 return -1 or0..4 for this list; predicates
 *   do not write it. BA54 writes both halfwords before their consumers.
 * arithmetic: admitted index0..4 after -1 rejection keeps index+54 and
 *   index*24 representable; byte record selectors retain0..255, *24<=6120.
 *   Full word distance uses u32 subtraction/negation modulo2^32, with
 *   original signed tests; INT_MIN retains its wrapped negative result.
 * interfaces: observed C38/C60 scalar returns retained despite legacy
 *   own void wrappers; every original call argument and independent poll
 *   remains. No owner C, defaults, extra bound, volatile or signed overflow.
 */
void func_021DABCC(u8 *a,u8 *b)
{
    u8 i;
    int index;
    u32 distance;
    u8 touch[6][4];
    struct Vec2 point2;
    struct Vec2 point1;
    if (((struct Obj00132 *)a)->f24==7 && ((struct Obj00132 *)a)->f44==0) {
        func_021D5A9C((char *)a,1);
        func_0204B878(*(struct Obj * *)&((struct Obj00132 *)a)->f194,9);
        func_021DBA78(b+176+b[41]*24,0);
        func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->f98,0);
        func_021D9E30(a,(int)b);
        if (((struct Obj00026 *)b)->f14==1) {
            func_021DBA78(b+176+b[42]*24,0);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,0);
            ((struct Obj00026 *)b)->f14=0;
            b[42]=5;
        }
        a[28]=1;
        func_020061E4(1361);
        return;
    }
    for (i=0;i<5;i++) func_021DBA14(b+176+i*24,touch[i]);
    touch[5][0]=255;
    if (func_02035C60()==1) {
        index=func_02035C08(touch[0]);
        if (index==-1) goto out;
        if (func_02017E88(func_021D6064(a),index+54,0)==0) goto out;
        if (((struct Obj00132 *)a)->f44==1) func_021D5A9C((char *)a,0);
        if ((*(u8 **)(a+8))[13]!=6) {
            ((struct Obj00026 *)b)->f1C=1;
            if (((struct Obj00026 *)b)->f14!=1) {
                b[42]=index;
                func_021DBA54(b+176+index*24,(short unsigned int *)((u8 *)&point1));
                func_0204B404(*(struct Obj * *)&((struct Obj00026 *)b)->fA0,&point1,0);
                func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->fA0,1);
                if (index==0) func_0204B878(*(struct Obj * *)&((struct Obj00026 *)b)->fA0,3);
                else if (index==3) func_0204B878(*(struct Obj * *)&((struct Obj00026 *)b)->fA0,4);
                else func_0204B878(*(struct Obj * *)&((struct Obj00026 *)b)->fA0,2);
            }
            ((struct Obj00026 *)b)->f2C=((struct Obj00132 *)a)->f28;
            ((struct Obj00026 *)b)->f30=((struct Obj00132 *)a)->f2C;
            func_021DBA54(b+176+index*24,(short unsigned int *)((u8 *)&point2));
            func_0204B404(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,&point2,0);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,1);
            func_0204B9A0(*(struct Actor * *)&((struct Obj00026 *)b)->f9C);
        }
        a[28]=1;
        func_021DB468(a,b,index,1);
        func_020061E4(1356);
        return;
    }
    if (func_02035C38()==1) {
        if (((struct Obj00026 *)b)->f1C!=1) goto out;
        index=func_02035BA4(touch[0]);
        if (((struct Obj00026 *)b)->f14==0) {
            if (index==-1) {
                ((struct Obj00026 *)b)->f1C=0;
                func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->fA0,0);
                func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,0);
            } else {
                distance=((struct Obj00026 *)b)->f30-((struct Obj00132 *)a)->f2C;
                if ((int)distance<0) distance=0U-distance;
                if ((int)distance>8) {
                    func_021DBA78(b+176+b[42]*24,2);
                    ((struct Obj00026 *)b)->f14=1;
                    func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->fA0,0);
                }
            }
        }
        if (((struct Obj00026 *)b)->f14==1) {
            if (index!=-1) {
                if (func_02017E88(func_021D6064(a),index+54,0)==0) goto out;
                func_021DB468(a,b,index,0);
                return;
            }
            func_021DBA78(b+176+b[42]*24,0);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->fA0,0);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,0);
            ((struct Obj00026 *)b)->f14=0;
            ((struct Obj00026 *)b)->f1C=0;
            func_021DB468(a,b,b[41],0);
            b[42]=5;
            return;
        }
    } else {
        if (((struct Obj00026 *)b)->f1C==1) {
            func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->fA0,0);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00026 *)b)->f9C,0);
            if (((struct Obj00026 *)b)->f14==1) {
                if (b[42]!=b[41]) {
                    func_021DB508(a,b,b[42],b[41]);
                    func_020061E4(1357);
                    return;
                }
                ((struct Obj00026 *)b)->f14=0;
                func_021DB468(a,b,b[41],0);
            }
        }
    }
out:
    return;
}







int func_021DAEE4(u8 *a,u8 *p)
{
    struct Point_021D89FC pt;
    u32 r;
    u8 t;
    if(a[0x1c]==1 && func_020362DC()!=0) {
        a[0x1c]=0;
        if(((struct Obj00026 *)p)->f18==0) {
            p[0x2a]=5;
            func_021DB468(a,p,p[0x29],0);
        }
    }
    if(func_020362DC()==2) {
        if(((struct Obj00026 *)p)->f18==0) {
            a[0x1c]=0;
            ((struct Obj00132 *)a)->f54=1;
            (*(u8 **)(a+8))[0x12]=1;
            ((struct Obj00132 *)a)->f50=2;
            func_0204B878(((struct Obj00132 *)a)->f194,9);
            ((struct Obj00132 *)a)->f1A0=((struct Obj00132 *)a)->f194;
            func_020061E4(0x551);
            return 1;
        } else {
            a[0x1c]=0;
            func_021DBA78(p+0xb0+p[0x2a]*0x18,0);
            func_021DB468(a,p,p[0x29],0);
            func_0204B3DC(((struct Obj00026 *)p)->f9C,0);
            p[0x29]=p[0x2a];
            p[0x2a]=5;
            ((struct Obj00026 *)p)->f18=0;
            func_021DB468(a,p,p[0x29],0);
            func_0204B878(((struct Obj00132 *)a)->f194,9);
            func_021DB614(a,p,0);
            func_020061E4(0x551);
        }
    } else if(((struct Obj00026 *)p)->f18!=0) {
        if(func_020362DC()==1) {
            a[0x1c]=0;
            ((struct Obj00132 *)a)->f54=1;
            (*(u8 **)(a+8))[0x11]=p[0x2a];
            (*(u8 **)(a+8))[0x12]=0;
            ((struct Obj00026 *)p)->f20=1;
            ((struct Obj00026 *)p)->f24=1;
            *(int *)&((struct Obj00132 *)a)->f1A0=0;
            func_020061E4(0x54c);
        }
    } else if(func_020362DC()==1) {
        a[0x1c]=0;
        if(p[0x29]<4) {
            r=func_0202F72C(((struct Obj23165 *)((*(u8 * *)&((struct Obj00132 *)a)->f8)))->f8,func_02017E88(func_021D6064(a),*(volatile u8 *)&((struct Obj00026 *)p)->f29+0x36,0),((struct Obj00132 *)a)->f0);
            if(r==0 || ((struct Obj00132 *)a)->f14==1) {
                if(((struct Obj23166 *)((*(u8 * *)&((struct Obj00132 *)a)->f8)))->f14==0) {
                    ((struct Obj00132 *)a)->f54=1;
                    (*(u8 **)(a+8))[0x12]=0;
                    (*(u8 **)(a+8))[0x11]=p[0x29];
                    ((struct Obj00026 *)p)->f20=1;
                    *(int *)&((struct Obj00132 *)a)->f1A0=0;
                } else {
                    ((struct Obj00026 *)p)->f18=1;
                    t=p[0x29];
                    p[0x2a]=t;
                    func_021DBA78(p+0xb0+t*0x18,2);
                    p[0x29]=4;
                    func_021DB468(a,p,p[0x29],0);
                    func_021DBA54(p+0xb0+p[0x2a]*0x18,(short unsigned int *)(&pt));
                    func_0204B404(((struct Obj00026 *)p)->f9C,(const struct Vec2 *)(&pt),0);
                    func_0204B3DC(((struct Obj00026 *)p)->f9C,1);
                    func_0204B9A0(((struct Obj00026 *)p)->f9C);
                    func_021DB614(a,p,1);
                }
            } else {
                func_021DB688(a,p,r);
                goto done;
            }
        } else {
            ((struct Obj00132 *)a)->f54=1;
            (*(u8 **)(a+8))[0x12]=1;
            ((struct Obj00026 *)p)->f20=1;
            *(int *)&((struct Obj00132 *)a)->f1A0=0;
        }
        func_020061E4(0x54c);
done:
        return 1;
    } else {
        if(func_020362DC()==0x40 || func_020362DC()==0x80) {
            func_021DB3F0(a,p);
            return 1;
        }
    }
    return 0;
}







/*
 * note: callee func_0202F72C filed as arm9 witness (pkt_0202F72C).
 * interface: C08 returns -1 or 0..4 for this five-record list (full
 *   C08/BBC/ADC bodies and nonwriting A70/AA4 predicates, retained evidence).
 *   BA14 writes every four-byte record; the sixth first byte is the sentinel.
 *   BA54 stores both output halfwords before returning. Only sentinel byte
 *   touch[5][0] is read; no other bytes of its partial record are consumed.
 * arithmetic: loop i is initialized zero and guarded <5; selected index
 *   admitted after -1 rejection is 0..4, so index+54 and index*24 are safe.
 *   Secondary record selector is an ldrb, 0..255, product <=6120. No menu
 *   domain, default output value, volatile or narrowed full-word result.
 */
void func_021DB140(u8 *a,u8 *b)
{
    u8 i;
    int index,result;
    u16 point[2];
    u8 touch[6][4];
    if (((struct Obj00132 *)a)->f24==7) {
        if (((struct Obj00026 *)b)->f18==0) {
            ((struct Obj00132 *)a)->f54=1;
            (*(u8 **)(a+8))[18]=1;
            ((struct Obj00132 *)a)->f50=2;
            func_0204B878(((struct Obj00132 *)a)->f194,9);
            ((struct Obj00132 *)a)->f1A0=((struct Obj00132 *)a)->f194;
            func_020061E4(1361);
            return;
        }
        a[28]=1;
        func_021DBA78(b+176+b[42]*24,0);
        func_021DB468(a,b,b[41],0);
        func_0204B3DC(((struct Obj00026 *)b)->f9C,0);
        b[42]=5;
        ((struct Obj00026 *)b)->f18=0;
        if (b[43]==5) {
            func_021DB468(a,b,4,0);
            func_021D9EE8(a,b);
        } else {
            b[41]=255;
            func_021DB468(a,b,255,0);
        }
        func_021DB614(a,b,0);
        func_020061E4(1361);
        return;
    }
    for (i=0;i<5;i++) func_021DBA14(b+176+i*24,touch[i]);
    touch[5][0]=255;
    index=func_02035C08(touch[0]);
    if (index==-1) return;
    if (((struct Obj00026 *)b)->f18==0) {
        if (index<4) {
            if (func_02017E88(func_021D6064(a),index+54,0)==0) return;
            result=func_0202F72C(((struct Obj23167 *)(*(u8 * *)&((struct Obj00132 *)a)->f8))->f8,func_02017E88(func_021D6064(a),index+54,0),((struct Obj00132 *)a)->f0);
            if (result==0 || ((struct Obj00132 *)a)->f14==1) {
                if (((struct Obj23168 *)(*(u8 * *)&((struct Obj00132 *)a)->f8))->f14==0) {
                    ((struct Obj00132 *)a)->f54=1;
                    (*(u8 **)(a+8))[18]=0;
                    (*(u8 **)(a+8))[17]=index;
                    ((struct Obj00026 *)b)->f20=1;
                    *(int *)&((struct Obj00132 *)a)->f1A0=0;
                    func_020061E4(1356);
                    func_021DB468(a,b,index,0);
                    func_021DBA78(b+176+index*24,2);
                    return;
                }
                a[28]=1;
                ((struct Obj00026 *)b)->f18=1;
                func_021DB468(a,b,index,0);
                b[42]=index;
                func_021DBA78(b+176+index*24,2);
                b[41]=4;
                func_021DB468(a,b,b[41],0);
                func_021DBA54(b+176+b[42]*24,(short unsigned int *)point);
                func_0204B404(((struct Obj00026 *)b)->f9C,(const struct Vec2 *)point,0);
                func_0204B3DC(((struct Obj00026 *)b)->f9C,1);
                func_0204B9A0(*(struct Actor * *)&((struct Obj00026 *)b)->f9C);
                func_021DB614(a,b,1);
                func_020061E4(1356);
                return;
            }
            func_021DB468(a,b,index,0);
            b[42]=index;
            func_021DBA78(b+176+index*24,2);
            func_021DB688(a,b,result);
            return;
        }
        func_021DB468(a,b,index,0);
        a[28]=1;
        ((struct Obj00132 *)a)->f54=1;
        (*(u8 **)(a+8))[18]=1;
        ((struct Obj00026 *)b)->f20=1;
        *(int *)&((struct Obj00132 *)a)->f1A0=0;
        func_020061E4(1356);
        return;
    }
    if (index==4) {
        a[28]=1;
        ((struct Obj00132 *)a)->f54=1;
        (*(u8 **)(a+8))[17]=b[42];
        (*(u8 **)(a+8))[18]=0;
        ((struct Obj00026 *)b)->f20=1;
        ((struct Obj00026 *)b)->f24=1;
        *(int *)&((struct Obj00132 *)a)->f1A0=0;
        func_020061E4(1356);
    }
}






void func_021DB3F0(u8 *a,u8 *b) {
    void *p;
    int i,step;
    unsigned v;
    p=func_021D6064(a);
    i=b[41];
    if(func_020362DC()==64) step=-1;else step=1;
    func_020061E4(1352);
    do {
        i+=step;
        if(i<0) i=b[43]-1;
        else if(i>b[43]-1) i=0;
        if(i<4) v=(u16)func_02017E88(p,i+54,0);
        else v=((struct Obj23169 *)(*(u8 * *)&((struct Obj00112 *)a)->f8))->f14;
    } while(v==0);
    func_021DB468(a,b,i,0);
}






/*
 * lever: repeat func_0204B3DC in both arms to retain branch to next.
 */
void func_021DB468(u8 *a,u8 *b,u8 c,int d) {
    u8 box[4];
    if(a[28]==0) {
        func_021DBA54(b+176+c*24,(short unsigned int *)box);
        func_0204B404(((struct Obj00536 *)b)->f98,(const struct Vec2 *)box,0);
        func_0204B3DC(((struct Obj00536 *)b)->f98,0);
    } else func_0204B3DC(((struct Obj00536 *)b)->f98,0);
    if(b[41]!=b[42] || ((struct Obj00536 *)b)->f14==0) {
        if(b[41]!=255) func_021DBA78(b+176+b[41]*24,0);
    } else func_021DBA78(b+176+b[41]*24,2);
    func_021DBA78(b+176+c*24,1);
    if(b[41]!=c || d==1) {
        b[41]=c;
        func_021D9EE8(a,b);
    }
}






/*
 * extent: the final two bytes at 021DB612 are zero alignment padding.
 * semantic: selectors and slot indices preserve every input word. Selector
 *   additions and index*24/address additions are u32 wrap, with pointer
 *   conversion only after address arithmetic; no asserted slot bound.
 *   Six getter results and four selectors are assigned before use.
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`apid=a;` before `apid=a+58U;`; `auid=a;` before `auid=a+62U;` and 2
 * more). Game code has no line table, so these were stand-ins. The plain
 * single assignment gives EXACT* in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void func_021DB508(u8 *p,u8 *q,u32 a,u32 b)
{
    void *m;
    u32 am,app,au,bm,bpp,bu;
    u32 apid,auid,bpid,buid;
    m=func_021D6064(p);
    func_021D60D4(p,1);
    am=func_02017E88(m,a+54U,0);
    apid=a+58U;
    app=func_02017E88(m,apid,0);
    auid=a+62U;
    au=func_02017E88(m,auid,0);
    bm=func_02017E88(m,b+54U,0);
    bpid=b+58U;
    bpp=func_02017E88(m,bpid,0);
    buid=b+62U;
    bu=func_02017E88(m,buid,0);
    func_020181FC(m,bm,a);
    func_020181FC(m,am,b);
    func_02017E64(m,apid,bpp);
    func_02017E64(m,auid,bu);
    func_02017E64(m,bpid,app);
    func_02017E64(m,buid,au);
    func_021D60D4(p,0);
    func_021DBE98(*(void **)((u32)q+a*24U+196U),*(void **)((u32)q+b*24U+196U));
    *(u32 *)((u32)q+a*24U+180U)=1;
    *(u32 *)((u32)q+b*24U+180U)=1;
    func_021D9EE8(p,q);
    ((struct Obj23171 *)q)->f10=1;
}






void func_021DB614(void *a,u8 *b,int c) {
    u8 *p=b+272;
    if(c==1) {
        func_0204B878(((struct Obj06486 *)p)->f8,16);
        func_021DBCA4(((struct Obj06486 *)p)->f14,0);
        func_0204B3DC(((struct Obj06486 *)p)->fC,0);
        func_021DBCF4(((struct Obj00026 *)b)->fAC);
        func_021DBCA4(((struct Obj00026 *)b)->fAC,1);
    } else {
        func_021DBCA4(((struct Obj00026 *)b)->fAC,0);
        func_0204B3DC(((struct Obj06486 *)p)->fC,1);
        if(b[41]==4) func_021DBA78(p,1); else func_021DBA78(p,0);
        func_021DBCA4(((struct Obj06486 *)p)->f14,1);
    }
}






void func_021DB688(u8 *a,u8 *b,int c) {
    ((struct Obj10523 *)b)->fC=1;
    func_02043B5C(func_02045770(((struct Obj10523 *)b)->f8C),0);
    if(c==1) func_021D618C(a,(unsigned int)(((struct Obj10523 *)b)->f8C),156,0,0,15424);
    func_020061E4(1367);
}






u16 func_021DB6D0(u32 a, u32 b, unsigned char c, u32 d) {
 switch (func_02019B44(c, d)) {
 case 1: return 0x3d20;
 case -1: return 0x3d40;
 case 0:
 default: return 0x3c40;
 }
}






/*
 * lever: assign p[0] before pos.x to schedule its store before the stack address.
 */
void func_021DB700(u8 *a,void *b,u8 *p,u8 i) {
    ObjPos pos;
    ((struct Obj03286 *)p)->f4=0;
    p[0]=i;
    pos.x=d_021DC2B8[i][0]*8;
    pos.y=d_021DC2B8[i][1]*8;
    pos.priority=10;
    pos.flags=0;
    pos.z=p[0];
    ((struct Obj03286 *)p)->f8=func_0204B294(((struct Obj00344 *)a)->f174,(unsigned int)((struct Obj00344 *)a)->fE8,(unsigned int)((struct Obj00344 *)a)->fB0,(unsigned int)((struct Obj00344 *)a)->f118,&pos,0,((struct Obj00344 *)a)->f0);
    func_0204B3DC(((struct Obj03286 *)p)->f8,0);
    pos.x=d_021DC2B8[p[0]][0]*8+26;
    pos.y=d_021DC2B8[p[0]][1]*8+9;
    pos.priority=8;
    pos.flags=0;
    pos.z=0;
    ((struct Obj03286 *)p)->fC=func_0204B294(((struct Obj00344 *)a)->f174,(unsigned int)((struct Obj00344 *)a)->f130,(unsigned int)((struct Obj00344 *)a)->fA4,(unsigned int)((struct Obj00344 *)a)->f10C,&pos,0,((struct Obj00344 *)a)->f0);
    func_0204B3DC(((struct Obj03286 *)p)->fC,0);
}





void func_021DB7B8(void *a, void *b, u8 *p)
{
    func_0204B3B4(((struct Obj10524 *)p)->f8);
    func_0204B3B4(((struct Obj10524 *)p)->fC);
    ((struct Obj10524 *)p)->f0 = 0xff;
}




void func_021DB7D0(void *a0, void *a1, void *a2) {
}




/*
 * semantic: selector loads are fresh bytes after each getter, additions
 *   <=321 fit int. Every branch initializes id/count/value. Late table
 *   index is the full byte, with no assumed menu bound; address arithmetic
 *   is u32 wrap. Table x+5<=260, times8<=2080; y*8<=2040, fit s16_021DB7B8.
 *   All24 descriptor bytes (including its value and screen) are assigned.
 *   Pool B95C/B960 name the same byte-pair object at C2B8 and its +1 byte.
 */
void func_021DB7D4(u8 *p,u8 *q,u8 *entry)
{
    Descriptor_021DB7B8 desc;
    void *mon;
    u32 id,count,value;
    struct MsgBank *bank;
    void *text;
    struct WordSet *first,*second;
    mon=func_021D6064(p);
    if(entry[0]<4) {
        id=func_02017E88(mon,entry[0]+54,0);
        count=func_02017E88(mon,entry[0]+58,0);
        value=func_02017E88(mon,entry[0]+66,0);
    } else {
        id=((struct Obj23172 *)(*(u8 * *)&((struct Obj02846 *)p)->f8))->f14;
        count=func_0201BD28(id,5);
        value=count;
    }
    *(Bmp * *)&((struct Obj01409 *)entry)->f10=(Bmp *)func_02043678(11,4,32,((struct Obj02846 *)p)->f0);
    bank=func_02045B38(0,2,203,((struct Obj02846 *)p)->f0);
    text=func_02045EC0(bank,id);
    func_0201C724(((struct Obj02846 *)p)->f84,*(u32 *)&((struct Obj01409 *)entry)->f10,3,2,(u32)text,((struct Obj02846 *)p)->f80,1088);
    func_02045808(text);
    func_02045C04((struct Rec *)bank);
    if(id!=0) {
        func_021D614C(p,*(int *)&((struct Obj01409 *)entry)->f10,135,13,17,1088);
        first=func_0201EC64(((struct Obj02846 *)p)->f0);
        func_0201EFA4(first,0,count,3,1,1);
        func_021D6244(p,*(int *)&((struct Obj01409 *)entry)->f10,first,136,57,17,1088);
        func_0201ED04(first);
        func_021D614C(p,*(int *)&((struct Obj01409 *)entry)->f10,117,57,17,1088);
        second=func_0201EC64(((struct Obj02846 *)p)->f0);
        func_0201EFA4(second,0,value,3,1,1);
        func_021D61B8(p,*(int *)&((struct Obj01409 *)entry)->f10,second,141,61,17,1088);
        func_0201ED04(second);
    } else {
        func_021D614C(p,*(int *)&((struct Obj01409 *)entry)->f10,153,49,17,1088);
    }
    desc.x=(d_021DC2B8[entry[0]][0]+5)*8;
    desc.y=d_021DC2B8[entry[0]][1]*8;
    desc.resource=*(u32 *)&((struct Obj02846 *)p)->fB8;
    desc.value=0;
    desc.a=6;
    desc.b=0;
    desc.c=0;
    desc.d=0;
    desc.bmp=*(Bmp * *)&((struct Obj01409 *)entry)->f10;
    *(u8 * *)&((struct Obj01409 *)entry)->f14=func_021DBAD0(*(u8 * *)&((struct Obj04511 *)q)->fA4,(const u8 *)(&desc));
    ((struct Obj01409 *)entry)->f4=1;
}




/*
 * extent: two-byte zero alignment padding at 0x021DB9E6.
 */
void func_021DB964(u8 *a,void *b,u8 *p) {
    unsigned v;
    int i;
    unsigned words[9];
    void *q;
    q=func_021D6064(a);
    if(p[0]<4) v=func_02017E88(q,p[0]+54,0);
    else v=((struct Obj23173 *)(*(u8 * *)&((struct Obj00112 *)a)->f8))->f14;
    if(((struct Obj02847 *)p)->f4==1) {
        if(v!=0) {
            i=func_0201C1C8(v);
            func_0204AB84((unsigned int)(*(void **)(a+304+i*4)),(struct Rec *)words);
            func_0204B784(((struct Obj02847 *)p)->fC,(const struct Struct36 *)words);
            func_0204B6F4(((struct Obj02847 *)p)->fC,func_020275EC(i),1);
            func_0204B3DC(((struct Obj02847 *)p)->fC,1);
        } else func_0204B3DC(((struct Obj02847 *)p)->fC,0);
        func_021DBCF4(((struct Obj02847 *)p)->f14);
        func_0204B3DC(((struct Obj02847 *)p)->f8,1);
        ((struct Obj02847 *)p)->f4=0;
    }
}





void func_021DB9E8(void *a, void *b, u8 *p)
{
    func_020437AC(((struct Obj14077 *)p)->f10);
    func_021DBC3C(((struct Obj14077 *)p)->f14);
}




void func_021DB9FC(void *a, void *b, u8 *p)
{
    func_0204B3DC(((struct Obj14078 *)p)->f8, 0);
    func_0204B3DC(((struct Obj14078 *)p)->fC, 0);
}



void func_021DBA14(u8 *a,u8 *b) {
    if (*a<5) {
        b[0]=d_021DC2B8[*a][1]*8;
        b[1]=b[0]+32;
        b[2]=d_021DC2B8[*a][0]*8;
        b[3]=b[2]+136;
    } else { b[0]=0;b[1]=0;b[2]=0;b[3]=0; }
}



void func_021DBA54(unsigned char *p, unsigned short *o) {
 o[0] = d_021DC2B8[*p][0] << 3;
 o[1] = d_021DC2B8[*p][1] << 3;
}




void func_021DBA78(u8 *p, int i)
{
    func_0204B878(((struct Obj14080 *)p)->f8, (u16)(p[0] + i * 5));
}



struct S *func_021DBA90(u32 a, u32 b) {
 struct S *p = func_02030734(a, 0x14, 1, d_021DC854, 0x5d);
 int i;
 p->f4 = a;
 p->f0 = b;
 for (i = 0; i < 3; i++) p->f8[i] = -1;
 return p;
}




void func_021DBAC0(u8 *p)
{
    func_021DBF0C((int *)p);
    func_020307B0(p);
}



/*
 * note (2026-10-02): b is const-qualified; that frees the b loads from ordering behind the stack
 *   stores (d fields, outgoing args), which fixes both scheduling residues. bm local feeds the first size call.
 */
u8 *func_021DBAD0(u8 *a,const u8 *b)
{
    struct Desc_021DBA54 d={0};
    u8 *blk;
    u8 cols,rows,i,j;
    void *heap;
    u8 *row;
    u8 *e;
    int mode;
    void *bm;
    blk=func_02030734(((struct Obj06487 *)a)->f4,0x24,1,d_021DC854,0x8a);
    bm=*(void *const *)&((struct Obj01549 *)b)->f0;
    ((struct Obj06488 *)blk)->f0=bm;
    cols=((u32)func_020437DC(bm)>>6)&0xff;
    rows=((u32)func_020437E4(*(void *const *)&((struct Obj01549 *)b)->f0)>>5)&0xff;
    if(func_020437DC(*(void *const *)&((struct Obj01549 *)b)->f0)%64!=0) cols=cols+1;
    if(func_020437E4(*(void *const *)&((struct Obj01549 *)b)->f0)%32!=0) rows=rows+1;
    blk[0x22]=cols;
    blk[0x23]=rows;
    ((struct Obj06488 *)blk)->f20=*(const u16 *)&((struct Obj01549 *)b)->f12;
    ((struct Obj06488 *)blk)->f10=*(const u32 *)&((struct Obj01549 *)b)->f14;
    heap=func_020490F4(0x4e,((struct Obj06487 *)a)->f4);
    for(i=0;i<rows;i++) {
        for(j=0;j<cols;j++) {
            row=blk+i*cols*4;
            mode=func_021DBEA4(a,*(const u32 *)&((struct Obj01549 *)b)->f14,(u32)heap);
            e=row+j*4;
            ((struct Obj10527 *)e)->f14=(void *)func_0204A6C8(heap,7,0,*(const u32 *)&((struct Obj01549 *)b)->f14,((struct Obj06487 *)a)->f4);
            d.x=*(const s16 *)&((struct Obj01549 *)b)->f4+(j<<6);
            d.y=*(const s16 *)&((struct Obj01549 *)b)->f6+(i<<5);
            d.kind=b[0x10];
            d.flag=b[0x11];
            ((struct Obj10527 *)e)->f4=func_0204B294((void *)((struct Obj06487 *)a)->f0,*(u32 *)&((struct Obj10527 *)e)->f14,*(const u32 *)&((struct Obj01549 *)b)->f8,*(u32 *)(a+8+mode*4),&d,*(const u16 *)&((struct Obj01549 *)b)->f12,((struct Obj06487 *)a)->f4);
            func_0204B6F4(*(void **)(blk+(u32)j*4+4),(u8)(*(const u32 *)&((struct Obj01549 *)b)->fC),0);
        }
    }
    func_02049238(heap);
    return blk;
}



void func_021DBC3C(u8 *p)
{
    u8 i, j;
    for (i = 0; i < p[0x23]; i++) {
        for (j = 0; j < p[0x22]; j++) {
            func_0204A8D4((u32)(*(void **)(p + 0x14 + (j + i * p[0x22]) * 4)));
            func_0204B3B4(*(void **)(p + 4 + (j + i * p[0x22]) * 4));
        }
    }
    func_020307B0(p);
}



void func_021DBCA4(u8 *p, int v)
{
    u8 i, j;
    for (i = 0; i < p[0x23]; i++) {
        for (j = 0; j < p[0x22]; j++) {
            func_0204B3DC(*(void **)(p + 4 + (j + i * p[0x22]) * 4), v);
        }
    }
}



void func_021DBCF4(u8 *p)
{
    u8 *dst0;
    int c,r;
    u32 off,seg,edge;
    int rem;
    u32 wt;
    u8 *src;
    u8 k;
    void (*fn)(void *,void *,u32);
    dst0=func_020437D4(((struct Obj02191 *)p)->f0);
    func_020862F0(dst0,func_020437EC(((struct Obj02191 *)p)->f0));
    if(((struct Obj02191 *)p)->f10==0) fn=func_0207E780; else fn=func_0207E804;
    wt=(u32)func_020437DC(((struct Obj02191 *)p)->f0)>>3;
    rem=(u32)func_020437E4(((struct Obj02191 *)p)->f0)>>3;
    rem=rem%4;
    edge=func_020437DC(((struct Obj02191 *)p)->f0)%64/8*32;
    if(edge==0) edge=256;
    off=0;
    for(r=0;r<p[0x23];r++) {
        for(c=0;c<p[0x22];c++) {
            if(c==p[0x22]-1) seg=edge; else seg=256;
            src=(u8 *)func_0204ABBC((u32)(*(void **)(p+0x14+(c+r*p[0x22])*4)),((struct Obj02191 *)p)->f10);
            for(k=0;k<4;k++) {
                if(r==p[0x23]-1 && rem!=0 && k>=rem) continue;
                fn(dst0+(off+k*(wt*32)),src,seg);
                src+=256;
            }
            off+=seg;
        }
        off+=wt*32;
    }
}



void func_021DBE2C(u8 *p, s16 x, s16 y)
{
    struct Point pt;
    int i, j;
    for (i = 0; i < p[0x23]; i++) {
        for (j = 0; j < p[0x22]; j++) {
            pt.x = (s16)(x + (j << 6));
            pt.y = (s16)(y + (i << 5));
            func_0204B404(*(void **)(p + 4 + (j + i * p[0x22]) * 4), (const struct Vec2 *)(&pt), ((struct Obj08149 *)p)->f20);
        }
    }
}



void func_021DBE98(int *a, int *b) {
 int t = *a;
 *a = *b;
 *b = t;
}



/*
 * volatile: hardware register read at 021DBEB4
 */
int func_021DBEA4(u8 *p, int screen, u32 owner)
{
    int mode;
    u32 bits;
    bits = *(volatile u32 *)(screen == 0 ? 0x04000000 : 0x04001000) & 0x00300010;
    switch (bits) {
    case 0x00200010: mode = 0; break;
    case 0x00100010: mode = 1; break;
    case 0x10: mode = 2; break;
    default: mode = 0; break;
    }
    if (*(int *)(p + 8 + mode * 4) != -1) return mode;
    *(int *)(p + 8 + mode * 4) = func_0204AF28((void *)owner, 0x4d, 0x80, ((struct Obj23174 *)p)->f4);
    return mode;
}



void func_021DBF0C(int *p) {
 int i;
 for (i = 0; i < 3; i++) {
  if (p[2 + i] != -1) {
   func_0204AFD8(p[2 + i]);
   p[2 + i] = -1;
  }
 }
}



u32 func_021DBF2C(u32 i, u32 field)
{
    switch (field) {
    case 0: return d_021DC2F8[i].a;
    case 1: return d_021DC2F8[i].b;
    case 2: return d_021DC2F8[i].c;
    case 3: return d_021DC2F8[i].d;
    case 4: return d_021DC2F8[i].e;
    case 5: return d_021DC2F8[i].f;
    default: return 0;
    }
}
