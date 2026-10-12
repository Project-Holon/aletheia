/*
 * file:     field_effect_p01.c
 * unit:     yes
 * function: func_021A87A8, func_021A8840, func_021A8874, func_021A8AFC, func_021A8B18, func_021A8B84, func_021A8BB8, func_021A8D40, func_021A8DD8, func_021A8E10, func_021A8E20, func_021A8E78, func_021A8E80, func_021A8EEC, func_021A8FFC, func_021A9080, func_021A90A4, func_021A90E0, func_021A9154, func_021A926C, func_021A9294, func_021A92A4, func_021A9350, func_021A94B0, func_021A9508, func_021A954C, func_021A957C, func_021A9604, func_021A96B8, func_021A9780, func_021A9810, func_021A9828, func_021A996C, func_021A99A8, func_021A99E4, func_021A9A5C, func_021A9B00, func_021A9B68, func_021A9BE8, func_021A9C58, func_021A9CAC, func_021A9D30, func_021A9DC8, func_021A9DE0, func_021A9E64, func_021A9E98, func_021A9EC4, func_021A9ED8, func_021A9F28, func_021A9F40, func_021AA0A0, func_021AA180, func_021AA248, func_021AA304, func_021AA35C, func_021AA3E0, func_021AA3FC, func_021AA42C, func_021AA490, func_021AA548, func_021AA5CC, func_021AA69C, func_021AA6E0, func_021AA6F8, func_021AA728, func_021AA778, func_021AA77C, func_021AA794, func_021AA7AC, func_021AA7CC, func_021AA7DC, func_021AA80C, func_021AA8EC, func_021AA8F8, func_021AA900, func_021AA944, func_021AAA4C, func_021AAABC, func_021AAAF0, func_021AAB1C, func_021AAB48, func_021AAB54, func_021AAB74, func_021AABC4, func_021AABEC, func_021AABF4, func_021AACD4, func_021AAE34, func_021AAEC0, func_021AAF54, func_021AAFA0, func_021AAFC0, func_021AAFFC, func_021AB018, func_021AB070, func_021AB0AC, func_021AB0D4, func_021AB0F0, func_021AB0F8, func_021AB100, func_021AB11C, func_021AB140, func_021AB158, func_021AB164, func_021AB170, func_021AB17C, func_021AB188, func_021AB194, func_021AB1A0, func_021AB1AC, func_021AB1B8, func_021AB1C4, func_021AB1D0, func_021AB1DC, func_021AB1E8, func_021AB1F4, func_021AB200, func_021AB20C, func_021AB218, func_021AB224, func_021AB230, func_021AB23C, func_021AB250, func_021AB264, func_021AB270, func_021AB27C, func_021AB29C, func_021AB2BC, func_021AB2DC, func_021AB2E8, func_021AB2F8, func_021AB304, func_021AB310, func_021AB31C, func_021AB328, func_021AB334, func_021AB348, func_021AB358, func_021AB364, func_021AB370, func_021AB37C, func_021AB390, func_021AB3B0, func_021AB3D4, func_021AB3E0, func_021AB3EC, func_021AB3F8, func_021AB404, func_021AB410, func_021AB41C, func_021AB428, func_021AB434, func_021AB440, func_021AB44C, func_021AB458, func_021AB474, func_021AB490, func_021AB4A4, func_021AB4B8, func_021AB4EC, func_021AB4F8, func_021AB504, func_021AB580, func_021AB5AC, func_021AB5F4, func_021AB624, func_021AB634, func_021AB650, func_021AB660, func_021AB75C, func_021AB760, func_021AB764, func_021AB768, func_021AB780, func_021AB798, func_021AB7C0, func_021AB7E4, func_021AB81C, func_021AB840, func_021AB868, func_021AB880, func_021AB884, func_021AB888, func_021AB890, func_021AB908, func_021AB9FC, func_021ABA3C, func_021ABABC, func_021ABB54, func_021ABB78, func_021ABBA0, func_021ABBF0, func_021ABC14, func_021ABC38, func_021ABC5C, func_021ABD08, func_021ABD50, func_021ABDE8, func_021ABE04, func_021ABE0C, func_021ABE14, func_021ABE18, func_021ABE24, func_021ABE28, func_021ABE2C, func_021ABE30, func_021ABE64, func_021ABE8C, func_021ABEA0, func_021ABEAC, func_021ABEE8, func_021ABF2C, func_021ABF48, func_021ABF68, func_021ABFA8, func_021ABFC0, func_021ABFDC, func_021ABFEC, func_021ABFFC, func_021AC03C, func_021AC074, func_021AC0A0, func_021AC134, func_021AC140, func_021AC154, func_021AC178, func_021AC18C, func_021AC1A0, func_021AC1AC, func_021AC1B8, func_021AC1CC, func_021AC1E0, func_021AC1EC, func_021AC1F0, func_021AC218, func_021AC260, func_021AC274, func_021AC2AC, func_021AC2C0, func_021AC2F0, func_021AC384, func_021AC3A4, func_021AC3F8, func_021AC494, func_021AC4B8, func_021AC4CC, func_021AC514, func_021AC528, func_021AC578, func_021AC62C, func_021AC660, func_021AC66C, func_021AC688, func_021AC68C, func_021AC6C0, func_021AC6D4, func_021AC740, func_021AC760
 * address:  0x021A87A8
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
 *   func_0204B09C  0x0204B09C  arm
 *   func_0204B454  0x0204B454  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_02041EE4  0x02041EE4  arm
 *   func_0207D534  0x0207D534  arm
 *   d_021D8BBC     0x021D8BBC  data  a4
 *   d_021D8B5C     0x021D8B5C  data  a4
 *   d_021D8B7C     0x021D8B7C  data  a4
 *   d_021D8B44     0x021D8B44  data  a4
 *   d_021D8C1C     0x021D8C1C  data  a4
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040588  0x02040588  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040618  0x02040618  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02027614  0x02027614  thumb
 *   func_02027618  0x02027618  thumb
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 *   func_02049238  0x02049238  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B034  0x0204B034  arm
 *   func_0204B258  0x0204B258  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B954  0x0204B954  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   func_02013D20  0x02013D20  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_020142E8  0x020142E8  thumb
 *   d_021D8D24  0x021D8D24  data  a4
 *   func_02045B38  0x02045B38  arm
 *   d_021D8C0C     0x021D8C0C  data  ov021  a2
 *   func_020457B0  0x020457B0  arm
 *   func_020084BC  0x020084BC  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02045924  0x02045924  arm
 *   d_021D8B34     0x021D8B34  data  a2
 *   func_02045EC0  0x02045EC0  arm
 *   d_021D8CAC     0x021D8CAC  data  ov021  a4
 *   func_02008550  0x02008550  thumb
 *   d_021D8B18     0x021D8B18  data  ov021  a1
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0203F684  0x0203F684  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *   d_021D8C4C     0x021D8C4C  data  ov021  a1
 *   d_021D8B26     0x021D8B26  data  ov021  a1
 *   d_021D8B27     0x021D8B27  data  ov021  a1
 *   func_020362DC  0x020362DC  arm
 *   func_0203633C  0x0203633C  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_020355D8  0x020355D8  arm
 *   func_02035C08  0x02035C08  arm
 *   d_021D8C2C     0x021D8C2C  data  ov021  a1
 *   func_0204B404  0x0204B404  arm
 *   func_0204B878  0x0204B878  arm
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_020450F0  0x020450F0  arm
 *   func_02045374  0x02045374  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_0204B324  0x0204B324  arm
 *   func_020452E8  0x020452E8  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_02045334  0x02045334  arm
 *   func_02027624  0x02027624  thumb
 *   func_02027628  0x02027628  thumb
 *   func_0202762C  0x0202762C  thumb
 *   func_02049EF4  0x02049EF4  arm
 *   func_020410D0  0x020410D0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02012934  0x02012934  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_0200D418  0x0200D418  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02018598  0x02018598  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_0200D58C  0x0200D58C  thumb
 *   func_0201AA50  0x0201AA50  thumb
 *   func_0201AB08  0x0201AB08  thumb
 *   func_0209C2B0  0x0209C2B0  arm
 *   func_02010FB0  0x02010FB0  thumb
 *   MIi_CpuClear32  0x02082A7C  arm
 *   func_02005728  0x02005728  thumb
 *   func_0200D488  0x0200D488  thumb
 *   func_0200D4AC  0x0200D4AC  thumb
 *   func_0200D4B8  0x0200D4B8  thumb
 *   func_0219390C  0x0219390C  thumb  ov021
 *   func_02193C00  0x02193C00  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_02018A00  0x02018A00  thumb
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   data_021D8DE8  0x021D8DE8  data
 *   func_0200D454  0x0200D454  thumb
 *   func_02019C90  0x02019C90  thumb
 *   _u32_div_f  0x0209C2B0  arm
 *   data_021D8DD8  0x021D8DD8  data
 *   data_021D8DCC  0x021D8DCC  data
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_020186C8  0x020186C8  thumb
 *   func_0201AF6C  0x0201AF6C  thumb
 *   func_02030734  0x02030734  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_0216255C  0x0216255C  thumb  ov010
 *   d_021DDFA4     0x021DDFA4  data  a4
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02012A38  0x02012A38  thumb
 *   func_02188C6C  0x02188C6C  thumb  ov021
 *   func_021A1BF4  0x021A1BF4  thumb  ov021
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02013090  0x02013090  thumb
 *   func_0216E7C8  0x0216E7C8  thumb  ov010
 *   func_02013144  0x02013144  thumb
 *   func_02193920  0x02193920  thumb  ov021
 *   func_02012984  0x02012984  thumb
 *   func_02013ED8  0x02013ED8  thumb
 *   func_0203F4CC  0x0203F4CC  arm
 *   func_021A30C8  0x021A30C8  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_021938F4  0x021938F4  thumb  ov021
 *   func_0207C7B4  0x0207C7B4  arm
 *   _ll_mul        0x0209C054  arm
 *   data_021DDFA4  0x021DDFA4  data
 *   func_0201347C  0x0201347C  thumb
 *   func_020173EC  0x020173EC  thumb
 *   func_0201A920  0x0201A920  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_020130C4  0x020130C4  thumb
 *   func_0202A230  0x0202A230  thumb
 *   func_0202A420  0x0202A420  thumb
 *   func_02013734  0x02013734  thumb
 *   func_02013644  0x02013644  thumb
 *   func_020136E0  0x020136E0  thumb
 *   func_02013610  0x02013610  thumb
 *   func_02013678  0x02013678  thumb
 *   func_020136AC  0x020136AC  thumb
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021A3074  0x021A3074  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   d_021DDFB4  0x021DDFB4  data  a4
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   d_021D8E70  0x021D8E70  data  a4
 *   func_02012974  0x02012974  thumb
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02159C48  0x02159C48  thumb  ov010
 *   func_02159BD4  0x02159BD4  thumb  ov010
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C234  0x0200C234  thumb
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_0216D828  0x0216D828  thumb  ov010
 *   func_021A3624  0x021A3624  thumb  ov021
 *   func_021A3644  0x021A3644  thumb  ov021
 *   func_021ADB4C  0x021ADB4C  thumb
 *   func_021ADB5C  0x021ADB5C  thumb
 *   d_021D8E76     0x021D8E76  data  a1
 *   func_0218D168  0x0218D168  thumb  ov021
 *   func_0218DBD4  0x0218DBD4  thumb  ov021
 *   func_0209BDBC  0x0209BDBC  arm
 *   func_0209C95C  0x0209C95C  arm
 *   func_0209CB8C  0x0209CB8C  arm
 *   func_0209C494  0x0209C494  arm
 *   func_0218DBAC  0x0218DBAC  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_021ADAAC  0x021ADAAC  thumb
 *   d_021D8E8A     0x021D8E8A  data  a2
 *   func_02158768  0x02158768  thumb
 *   func_0218DAEC  0x0218DAEC  thumb
 *   data_021D8EA0  0x021D8EA0  data
 *   data_021D8EA1  0x021D8EA1  data
 *   d_021DDFC8  0x021DDFC8  data  a4
 *   d_021DE000  0x021DE000  data  a4
 *   d_021D8EEC  0x021D8EEC  data  a4
 *   func_0204A39C  0x0204A39C  arm
 *   d_021D8EF4  0x021D8EF4  data  a4
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CBD0  0x0207CBD0  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0207CFB8  0x0207CFB8  arm
 *   func_0218E124  0x0218E124  thumb  ov021
 *   tbl_020A1B38   0x020A1B38  data  a2
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_0218ECF4  0x0218ECF4  thumb  ov021
 *   FX_Div         0x0207C768  arm
 *   func_0218ED34  0x0218ED34  thumb
 *   func_0218ED48  0x0218ED48  thumb
 *   func_0218ED58  0x0218ED58  thumb
 *   func_0218F0D4  0x0218F0D4  thumb
 *   func_0218F05C  0x0218F05C  thumb
 *   sub_0207C768   0x0207C768  arm
 *   func_0218ECD4  0x0218ECD4  thumb ov021
 *   func_0207C768  0x0207C768  arm
 *   func_0218ED64  0x0218ED64  thumb
 *   func_02013B38  0x02013B38  thumb
 *   func_0202E83C  0x0202E83C  thumb
 *   func_02188D58  0x02188D58  thumb  ov021
 *   func_020140D8  0x020140D8  thumb
 *   func_02188C88  0x02188C88  thumb  ov021
 *   func_02050080  0x02050080  arm
 *   func_0204EDBC  0x0204EDBC  arm
 *   func_0204ED70  0x0204ED70  arm
 *   func_0204EDB0  0x0204EDB0  arm
 *   d_021DE018     0x021DE018  data  a1
 *   d_021D8F04     0x021D8F04  data  a4
 *   func_02188CD8  0x02188CD8  thumb  ov021
 *   func_021C6628  0x021C6628  thumb  ov021
 *   d_021D8F60  0x021D8F60  data  a4
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   func_02030DA4  0x02030DA4  arm
 *   func_02030D28  0x02030D28  arm
 *   func_02022040  0x02022040  thumb
 *   d_021DE028     0x021DE028  data  a1
 *   d_021D908C     0x021D908C  data  a4
 *   ENV_SetResourceSet  0x020307B0  arm
 *   func_02050278  0x02050278  arm
 *   d_021D9098  0x021D9098  data
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D98C  0x0216D98C  thumb  ov010
 *   func_0216DAB4  0x0216DAB4  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0216D92C  0x0216D92C  thumb  ov010
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0216D8B0  0x0216D8B0  thumb  ov010
 *   func_0204F720  0x0204F720  arm
 *   func_0204F638  0x0204F638  arm
 *   d_021DE038  0x021DE038  data
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_021C6580  0x021C6580  thumb  ov021
 *   d_021D90AC     0x021D90AC  data  a4
 *   func_0216D538  0x0216D538  thumb  ov010
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021C6694  0x021C6694  thumb  ov021
 *   d_021DE070  0x021DE070  data
 *   func_02188C90  0x02188C90  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_020500F0  0x020500F0  arm
 *   d_021D911C     0x021D911C  data  a2
 *   d_021D90EC  0x021D90EC  data
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_02164280  0x02164280  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 */
#include "../../matched/include/Obj12092.h"
#include "../../matched/include/Obj18071.h"
#include "../../matched/include/Obj07219.h"
#include "../../matched/include/Obj09585.h"
#include "../../matched/include/Obj18072.h"
#include "../../matched/include/Obj19848.h"
#include "../../matched/include/Obj19849.h"
#include "../../matched/include/Obj18073.h"
#include "../../matched/include/Obj18074.h"
#include "../../matched/include/Obj18075.h"
#include "../../matched/include/Obj18076.h"
#include "../../matched/include/Obj12093.h"
#include "../../matched/include/Obj12094.h"
#include "../../matched/include/Obj18077.h"
#include "../../matched/include/Obj18078.h"
#include "../../matched/include/Obj04239.h"
#include "../../matched/include/Obj00757.h"
#include "../../matched/include/Obj04240.h"
#include "../../matched/include/Obj02708.h"
#include "../../matched/include/Obj18079.h"
#include "../../matched/include/Obj18080.h"
#include "../../matched/include/Obj18081.h"
#include "../../matched/include/Obj18082.h"
#include "../../matched/include/Obj18083.h"
#include "../../matched/include/Obj18084.h"
#include "../../matched/include/Obj07511.h"
#include "../../matched/include/Obj18085.h"
#include "../../matched/include/Obj18086.h"
#include "../../matched/include/Obj04241.h"
#include "../../matched/include/Obj12095.h"
#include "../../matched/include/Obj07513.h"
#include "../../matched/include/Obj12096.h"
#include "../../matched/include/Obj05038.h"

struct Actor;
struct PtS;
struct BgTemplate;
struct BigObj;
struct MsgBank;
struct Rec;
struct Strbuf;
struct Sub0200852CObj;
struct U16Vec;
struct Src;
struct W_021A8E78;
struct Vec2;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct Big;
struct Blk38;
struct Spec;
struct Unit_021A8E78;
struct Slot14_021A94B0;
struct GdsEnt;
struct Mon;
struct Entry8_021A8E78;
struct Slot14_021A9C58;
struct Personal;
struct Ctx_021A87A8;
struct Pos;
struct Sub02008C20Obj;
struct Obj00020;
struct Obj;
struct Unit_021A87A8;
struct Tab;
struct Sel_021A9C58;
struct Out;
struct Party;
struct PartyMon;
struct Slot14;
struct Obj020136E0;
struct Obj02013734;
struct Blk34;
struct VecFx32;
struct Self;
struct Ctx;
struct Sub020140BCObj;
struct Blk3;
struct Mgr;
struct Node;
struct Tagged;
struct Ctl;
struct BbActRec;
struct BbActSys;
struct BbActDesc;
struct Trip;
struct X;
typedef unsigned char u8;

typedef signed short s16;

typedef struct {
    s16 x;
    s16 y;
} P_021A87A8;

typedef struct {
    int pad0;
    int f0;
    int pad8[3];
    int f10;
    int pad18;
} E_021A87A8;


typedef unsigned short u16;


typedef unsigned int u32;


typedef struct Pos_021A87A8 {
    s16 x;
    s16 y;
    s16 z;
    u8 a;
    u8 b;
} Pos_021A87A8;

typedef struct Bank {
    u32 w[4];
} Bank;

typedef signed int s32;

typedef signed char s8;

typedef struct Item {
    int f00;
    void *f04;
    int f08;
    void *f0C;
    void *f10;
    int f14;
    void *f18;
} Item;


typedef struct Name {
    u16 s[7];
} Name;

typedef struct Pos_021A8AFC {
    u8 x;
    u8 y;
} Pos_021A8AFC;

typedef struct Rect {
    int a;
    int b;
    int c;
} Rect;

typedef struct St {
    int k;
    u8 x;
    u8 y;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 b9;
    u8 padA[2];
    void *s;
    void *q;
    int a;
    int b;
    int c;
} St;

struct W_021A8D40 {
    u8 pad00[0x134];
    u32 f134;
};

typedef struct {
    s16 x;
    s16 y;
} P_021A8D40;




struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u8 pad0C[8];
    u8 f14;
    u8 f15;
    u8 pad16[2];
    void *f18;
};

struct W_021A8E20 {
    u8 pad00[0x1E];
    u8 f1E;
    u8 f1F;
    u8 pad20[4];
    u32 f24;
    u8 pad28[0xC];
    struct Slot slots[7];
};

struct W_021A8E78 {
    u8 pad00[0x1E];
    u8 f1E;
    u8 f1F;
    u8 pad20;
    u8 f21;
};

typedef struct Item_021A8E78 {
    int f00;
    void *f04;
    int f08;
    void *f0C;
    void *f10;
    int f14;
    void *f18;
} Item_021A8E78;


struct W_021A8FFC {
    u8 pad00[0x1E];
    u8 f1E;
    u8 f1F;
    u8 pad20[4];
    u32 f24;
    u8 pad28[4];
    u32 f2C;
    u32 f30;
    struct Slot slots[7];
    u32 cur;
    u8 padFC[0x28];
    void *f124;
};

struct Buf32 {
    u8 b[32];
};

typedef struct {
    s16 x;
    s16 y;
} P_021A9080;


typedef struct {
    int pad0;
    int f0;
    int pad8[5];
} E_021A8E78;


struct W {
    u8 pad00[0x1E];
    u8 f1E;
    u8 f1F;
    u8 pad20[4];
    u32 f24;
    u8 pad28[4];
    u32 f2C;
    u32 f30;
    struct Slot slots[7];
    struct Slot *cur;
    u8 padFC[0x28];
    void *f124;
};

typedef struct FieldEffectWork6 {
    int f00;
    int f04;
    int f08;
    u32 f0C;
    u32 f10;
    u8 f14;
    u8 f15;
    u8 pad16[0x18 - 0x16];
    u32 f18;
    u8 pad1C[0x38 - 0x1C];
    u16 h38;
    u16 h3a;
    u8 pad3C[0x5B4 - 0x3C];
    int f5b4;
    u16 f5B8;
    u8 pad5BA[0x5BC - 0x5BA];
    u16 h5bc;
} FieldEffectWork6;

typedef struct Src {
    int f00;
    u8 f04;
    u8 f05;
    u8 f06;
    u8 f07;
    u8 f08;
    u8 f09;
    u8 pad0A[2];
    u32 f0C;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
} Src;


typedef struct Hdr {
    u16 f00;
    u16 f02;
    u16 f04;
    u8 f06;
    u8 f07;
    u16 f08;
    u16 f0A;
    u32 f0C;
    u32 f10;
    u16 f14;
    u16 f16;
} Hdr;



struct Scr {
    u8 pad00[0xC];
    u16 data[0x300];
};

struct Sel_021A8E78 {
    void *f00;
    void *f04;
    int f08;
    int f0C;
    u8 pad10[5];
    u8 f15;
    u16 f16;
    u16 f18;
    u8 f1A;
    u8 f1B;
    u8 f1C;
    u8 f1D;
    u8 f1E;
    u8 pad1F;
    u32 f20;
    void *f24;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 9;
    u32 b15 : 1;
};

struct Obj {
    u8 pad00[0xC];
    int f0C;
    u8 pad10[8];
    u16 f18;
    u8 pad1A[0xE];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 4;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
};

struct Slot14_021A94B0 { u8 pad00[4]; u8 f04; u8 pad05[0xF]; };

struct Spec { u16 id : 11; u16 lvl : 5; u8 lo; u8 hi; };

struct Unit_021A8E78 {
    void *f00;
    void *f04;
};

struct Sel_021A94B0 {
    u8 pad00[8];
    int f08;
};

struct Out {
    u16 f00;
    u16 f02;
    u8 f04;
    u8 f05;
    u8 f06;
    u8 f07;
};

typedef unsigned long long u64;

struct Unit_021A96B8 {
    u8 pad00[8];
    int f08;
    u8 pad0C[0x11];
    u8 f1D;
    u8 pad1E[2];
    u32 f20;
    void *f24;
    u32 b0 : 9;
    u32 b9 : 1;
    u32 b10 : 1;
};

struct Slot14_021A9604 { u16 f00; u16 f02; u8 f04; u8 f05; u8 f06; u8 f07; };

struct Unit_021A9780 {
    u8 pad00[0x20];
    u32 f20;
};

struct Sel_021A87A8 {
    void *f00;
    void *f04;
    int f08;
    int f0C;
    u8 pad10[5];
    u8 f15;
    u16 f16;
    u16 f18;
    u8 f1A;
    u8 f1B;
    u8 f1C;
    u8 f1D;
    u8 f1E;
    u8 pad1F;
    u32 f20;
    void *f24;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
    u32 b9 : 1;
    u32 b10 : 1;
    u32 b11 : 1;
    u32 b12 : 1;
    u32 b13 : 1;
    u32 b14 : 1;
    u32 b15 : 1;
};

struct Unit_021A9828 {
    u8 pad00[0x18];
    u16 f18;
    u8 pad1A[4];
    u8 f1E;
    u8 pad1F[9];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 2;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
    u32 b9 : 6;
    u32 b15 : 1;
};

struct Entry8_021A8E78 { u32 a, b; };

struct Entry8_021A99E4 { u16 f00; u16 f02; u8 f04; u8 f05; u8 f06; u8 pad07; };

struct Unit_021A87A8 {
    void *f00;
    u8 pad04[4];
    int f08;
    u8 pad0C[4];
    u32 f10;
    u8 f14;
};

struct Unit_021A9A5C {
    void *f00;
    u8 pad04[4];
    int f08;
    u8 pad0C[4];
    u32 f10;
    u8 f14;
};

struct Slot14_021A87A8 { u16 f00; u8 pad02[2]; u8 f04; u8 f05; u8 pad06[0xE]; };

struct Unit_021A9BE8 {
    u8 pad00[0x14];
    u8 f14;
    u8 pad15[0x13];
    u32 b0 : 14;
    u32 b14 : 1;
};

struct Unit_021A9C58 {
    u8 pad00[0x10];
    u32 f10;
    u8 f14;
    u8 pad15[0x13];
    u32 b0 : 12;
    u32 b12 : 1;
    u32 b13 : 1;
};

struct Unit_021A9D30 {
    u8 pad00[0x1C];
    u8 f1C;
    u8 pad1D[3];
    u32 f20;
    u8 pad24[4];
    u32 b0 : 11;
    u32 b11 : 1;
};

struct Slot14_021A9C58 { u16 f00; u8 pad02[3]; u8 f05; u8 f06; u8 pad07[9]; u8 f10; };

struct Mon {
    u8 pad00[7];
    u8 lo : 7;
    u8 b7 : 1;
};

struct Ctx_021A87A8 {
    void *f00;
    int f04;
    void *f08;
    struct Mon *f0C;
};

struct Slot14_021A9ED8 {
    u8 raw[0x14];
};

struct Sel_021A9C58 {
    u8 pad00[0x15];
    u8 f15;
    u8 pad16[0x12];
    u32 b0 : 5;
    u32 b5 : 1;
};

typedef struct {
    u16 h0;
    u16 h2;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 pad8[8];
    u8 b10;
    u8 pad11[0x17];
} Opts;

typedef struct {
    u8 b[0x2c];
} Buf;

typedef struct FieldEffectWork2 {
    int f0;
    int f4;
    int f8;
    u8 pad0C[0x1E - 0xC];
    u8 f1E;
    u8 f1F;
    u8 pad20[0x24 - 0x20];
    int f24;
    int f28;
    int f2C;
    u8 pad30[0x34 - 0x30];
    Item_021A8E78 f34[7];
    int fF8;
    s16 hfc;
    u8 padFE[0x120 - 0xFE];
    int f120;
    u32 f124;
} FieldEffectWork2;

struct Sel_021AA180 {
    u8 pad00[0x15];
    u8 f15;
    u8 pad16[0x16];
};

struct Ctx_021AA248 {
    void *f00;
    int f04;
    void *f08;
};

struct Slot14_021AA248 {
    u16 f00;
    u16 f02;
    u8 f04;
    u8 f05;
    u8 f06;
    u8 f07;
    u8 pad08[0xC];
};

struct Sel_021AA248 {
    u8 pad00[8];
    int f08;
    u8 pad0C[0x20];
};

struct RtcTime { u32 hour; u32 minute; u32 second; };

struct Info_021A87A8 {
    u32 f00;
    u32 f04;
    u8 f08;
    u8 f09;
    u16 f0A;
    u8 f0C;
    u8 f0D;
};

struct Tab { u8 pad00[0xC]; u8 *f0C; };

typedef long long fx64;

typedef int fx32;

struct Ctx_021AA3E0 { void *f00; u8 pad04[4]; void *f08; };

struct Unit_021AA3E0 {
    u8 pad00[8];
    int f08;
    u8 pad0C[0x1C];
    u32 b0 : 5;
    u32 b5 : 1;
};

struct Info_021AA3E0 { u32 f00; u32 f04; u8 f08; u8 f09; u16 f0A; u8 f0C; u8 f0D; u8 pad0E[2]; };

struct Slot14 { u8 raw[0x14]; };

struct Pos { u16 x, y, z; u16 f06; u32 f08; };

typedef struct {
    u8 a;
    u8 b;
} Pair;

typedef struct {
    u8 pad[7];
    u8 k : 7;
    u8 hi : 1;
} R_021AA3E0;

typedef struct {
    int pad[3];
    R_021AA3E0 *fc;
} S_021AA7AC;

typedef struct {
    char pad[0x5b8];
    u16 a;
    u16 b;
} D_021AA7AC;

typedef struct Entry {
    char pad00[0x12];
    short x;
    short y;
    short z;
    char pad18[5];
    unsigned char flags : 4;
} Entry;

struct Enc_021A87A8 {
    u8 pad00[4];
    u16 f04;
    u8 pad06[0x5B4];
    u16 f5BA;
};

struct Ctx_021AA7DC {
    void *f00;
    int f04;
    void *f08;
    struct Mon *f0C;
    struct Enc_021A87A8 *f10;
};


typedef struct Vec3s {
    short x, y, z;
} Vec3s;

typedef struct Ent_021AA900 {
    unsigned short id;
    short x;
    short y;
    short z;
    unsigned long w;
    unsigned char b;
    unsigned char flags : 4;
    unsigned char mid : 2;
    unsigned char top : 2;
} Ent_021AA900;

typedef struct Self_021AA944 {
    void *ctx;
    char pad04[4];
    void *obj;
    char pad0C[4];
    void *f10;
} Self_021AA944;

typedef struct Ent_021AAA4C {
    unsigned short id;
    short x;
    short y;
    short z;
    unsigned long w;
    unsigned char b;
    unsigned char flags : 4;
} Ent_021AAA4C;

typedef struct Self {
    void *ctx;
    char pad04[4];
    void *obj;
} Self;

typedef struct {
    u8 pad[0xd];
    u8 lo : 4;
    u8 mid : 2;
    u8 hi : 2;
} Sub_021AAABC;

typedef struct {
    u8 pad[0x10];
    Sub_021AAABC sub;
} T_021AAABC;

typedef struct FieldEffectWork {
    u16 f00;
    u16 f02;
    void *f04;
    void *f08;
    int f0C;
    u32 f10;
    u32 f14;
    void *f18;
    u16 f1C;
    u8 f1E;
    u8 f1F;
    u8 f20;
    u8 f21;
    u8 pad22[0x24 - 0x22];
    int f24;
    int f28;
    int f2C;
    int f30;
    Item f34[7];
    FieldEffectWork2 *fF8;
    short hfc;
    u8 padFE[0x100 - 0xFE];
    int f100;
    u32 f104;
    u32 f108;
    u32 f10C;
    u32 f110;
    u32 f114;
    u32 f118;
    u32 f11C;
    u32 f120;
    u32 f124;
    u32 f128;
    u32 f12C;
    u8 pad130[0x5B4 - 0x130];
    int f5b4;
} FieldEffectWork;


typedef struct {
    u8 pad[0x1d];
    u8 lo : 4;
    u8 mid : 2;
    u8 hi : 2;
} T_021AAAF0;

typedef struct {
    u8 pad[0x10];
    Sub_021AAABC sub;
} T_021AAABCx_021A87A8;

typedef struct Ent_021AAB74 {
    unsigned short id;
    short x;
    short y;
    short z;
    unsigned long w;
    unsigned char b;
    unsigned char flags : 4;
    unsigned char f4 : 2;
    unsigned char f6 : 2;
} Ent_021AAB74;



struct Ctx {
    void *f00;
    int f04;
    void *f08;
    struct Mon *f0C;
};

struct Area {
    s16 x;
    s16 y;
    s16 mx;
    s16 my;
    s16 bx;
    s16 by;
    u16 ox;
    u16 oy;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
};

typedef struct V3 { int x, y, z; } V3;

struct Cell {
    u8 pad00[8];
    u32 f08;
    u32 f0C;
};

struct Spot {
    u8 kind;
    u8 pad01;
    s16 x;
    u8 pad04[2];
    u16 y;
    u32 f08;
};

struct Enc_021AACD4 {
    u8 pad00[4];
    u16 count;
    u8 pad06[2];
    struct Spot spots[121];
};

typedef struct {
    u8 b0;
    u8 pad1;
    u16 h2;
    u16 h4;
    u16 h6;
    int f8;
} E_021AAE34;

typedef struct {
    int f0;
    u16 h4;
    u16 pad6;
    E_021AAE34 e[1];
} R_021AAE34;

typedef struct {
    u16 h0;
    u16 h2;
    u16 h4;
    u16 h6;
    int f8;
    u8 bc;
    u8 lo : 4;
    u8 mid : 2;
    u8 hi : 2;
    u8 pad[2];
} Sub_021AAE34;

typedef struct {
    u8 pad[0x10];
    Sub_021AAE34 sub;
} T_021AAABCx_021AACD4;

typedef struct Self_021AAEC0 {
    void *ctx;
} Self_021AAEC0;

typedef struct Ent_021AAF54 {
    unsigned short id;
    short x;
    short y;
    short z;
    unsigned long w;
    unsigned char b;
    unsigned char flags : 4;
} Ent_021AAF54;

typedef struct Self_021AAF54 {
    void *ctx;
    char pad04[4];
    void *obj;
    char pad0c[4];
    void *f10;
} Self_021AAF54;

typedef struct {
    u8 b[0x10];
} Sub_021AAEC0;

typedef struct {
    u8 pad[0x10];
    Sub_021AAEC0 sub;
} T_021AAABCx;


typedef struct D_021AAFA0 D_021AAFA0;


typedef struct {
    int f0;
    char pad[0x5b0];
    int f5b4;
} D_021AAFC0;



typedef struct {
    u32 f0;
    void *f4;
    int pad[2];
    FieldEffectWork6 *f10;
} S_021AAFFC;

typedef int BOOL;



struct Rec {
    u8 pad00[0x40];
    u16 f40;
    u16 f42;
    u16 f44;
    u16 f46;
};

struct Obj_021AB660 {
    u8 pad00[8];
    struct Rec *recs;
    void *f0C;
    u32 count;
    int cur;
    int f18;
    u32 f1C;
};

typedef int (*Fn_021AB798)(int a, int b, int c);

typedef struct {
    Fn_021AB798 *f0;
    Fn_021AB798 *f4;
} S_021AB768;

typedef void (*Fn_021AB7C0)(int a, int b, int c);

typedef struct {
    int pad[2];
    int f8[2];
} S_021AB7E4;

typedef struct {
    int f0;
    u32 f4;
    int f8[2];
} S_021AB840;

typedef struct {
    void *f0;
    int f4;
} S_021AB868;

typedef struct Range { unsigned long lo, hi; int min, max; V3 dir; } Range;

typedef struct {
    int x;
    int y;
    int z;
} V;


typedef long long s64;

typedef struct FieldEffectWork4 {
    u16 h0;
    u16 h2;
    u16 h4;
    u16 h6;
    int f8;
    u8 bc;
    u8 pad0D[0x1C - 0xD];
    int f1c;
    u8 pad20[0x2C - 0x20];
    int f2c;
    u8 pad30[0x38 - 0x30];
    E_021A87A8 f38[7];
    s16 hfc;
    u8 padFE[0x120 - 0xFE];
    int f120;
    int f124;
} FieldEffectWork4;


typedef struct {
    int f0;
    int f4;
} E_021ABE30;

typedef struct T T;

typedef struct {
    int id;
    int (*fn4)(void *t, unsigned short h);
    void (*fn8)(void *t, int v);
} D_021ABF48;

struct T {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[2];
    E_021ABE30 *f10;
};

typedef struct {
    int f0;
    int f4;
} E_021ABE64;

typedef struct T_021ABE64 T_021ABE64;

struct T_021ABE64 {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[2];
    E_021ABE64 *f10;
};

typedef struct E_021ABE8C E_021ABE8C;

typedef struct T_021ABEA0 T_021ABEA0;

struct T_021ABEA0 {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[2];
    E_021ABE30 *f10;
};

typedef struct {
    int kind;
    int arg;
} E_021ABEE8;

typedef struct {
    int n;
    int f4;
    int f8;
    int fc;
    E_021ABEE8 *e;
} O;

typedef struct {
    int id;
    int (*f4)(T *t, u16 h);
    void (*f8)(T *t, int v);
} D_021ABE30;


typedef struct T_021ABF48 T_021ABF48;

struct T_021ABF48 {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[2];
    FieldEffectWork6 *f10;
};




typedef struct FieldEffectWork5 {
    int f0;
    u16 h4;
    u8 pad06[0x8 - 0x6];
    int f8;
    int fc;
    FieldEffectWork *f10;
    u16 h14;
    u8 pad16[0x18 - 0x16];
    void *f18;
    int f1c;
    int f20;
    V f24;
    V f30;
} FieldEffectWork5;

typedef struct {
    int f0;
    char pad[0xd0];
} E_021ABFDC;

typedef struct {
    u32 f0;
    int f4;
    E_021ABFDC *f8;
} U;

typedef struct Obj_021AC074 Obj_021AC074;

typedef void (*ObjCb_021AC074)(Obj_021AC074 *o, void *work);

struct Obj_021AC074 {
    u32 active;
    u32 f4;
    u32 f8;
    V3 pos;
    u8 work[0xa4];
    ObjCb_021AC074 init;
    ObjCb_021AC074 exit;
    ObjCb_021AC074 f_c4;
    ObjCb_021AC074 f_c8;
    u32 fcc;
    void *fd0;
};

typedef struct Mgr_021AC074 { u32 count; u32 f4; Obj_021AC074 *objs; } Mgr_021AC074;

typedef struct Obj_021AC0A0 Obj_021AC0A0;

typedef struct Mgr_021AC0A0 Mgr_021AC0A0;

typedef struct ObjFuncs { ObjCb_021AC074 f0; ObjCb_021AC074 init; ObjCb_021AC074 exit; ObjCb_021AC074 f_c4; ObjCb_021AC074 f_c8; } ObjFuncs;

struct Obj_021AC0A0 {
    u32 active;
    u32 f4;
    u32 f8;
    V3 pos;
    u8 work[0xa0];
    ObjFuncs funcs;
    Mgr_021AC0A0 *mgr;
    void *fd0;
};

struct Mgr_021AC0A0 { u32 count; u32 f4; Obj_021AC0A0 *objs; u32 heap; };

typedef void (*ObjCb_021AC134)(Obj_021AC074 *o, void *work);

typedef struct Obj_021AC154 Obj_021AC154;

typedef void (*ObjCb)(Obj_021AC154 *o, void *work);

struct Obj_021AC154 {
    u32 active;
    u32 f4;
    u32 f8;
    V3 pos;
    u8 work[0xa4];
    ObjCb init;
    ObjCb exit;
    ObjCb f_c4;
    ObjCb f_c8;
    u32 fcc;
    void *fd0;
};

typedef struct Res { u8 pad[0x30]; u16 h30; u16 pad32; u32 f34; u32 f38; } Res;

typedef struct FieldEffectWork3 {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    u8 pad1C[0x1E - 0x1C];
    u8 b1e;
    u8 b1f;
    u8 pad20[0x24 - 0x20];
    u32 f24;
    int f28;
    u8 pad2C[0x30 - 0x2C];
    int f30;
    u8 pad34[0x38 - 0x34];
    E_021A8E78 f38[7];
    u8 padFC[0x124 - 0xFC];
    int f124;
    int f128;
    u8 pad12C[0x134 - 0x12C];
    int f134;
} FieldEffectWork3;

typedef struct Tmpl { u32 res; u8 b4, b5, b6, b7; u32 w8; } Tmpl;

typedef struct Ctl { u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; u32 f14; u32 f18; } Ctl;

typedef struct Arg_021AC074 { u32 a; u32 b; } Arg_021AC074;

typedef struct Desc {
    u16 slot;
    u16 v12;
    u16 v14;
    u8 k;
    u8 pad;
    u32 flag;
    u32 w;
    V3 pos;
    void (*f1c)(void);
    u32 f20;
} Desc;

typedef struct Sys { u8 pad[0x10]; u32 f10; u32 f14; u32 f18; } Sys;

typedef struct Arg4 { u8 b0; } Arg4;

typedef struct P_021AC074 {
    u32 f0;
    Sys *sys;
    u32 f8;
    u16 fc[4];
    u32 f14;
} P_021AC074;

typedef struct H { u32 f0, f4, f8, fc, f10; } H;

typedef struct W_021AC384 { u32 f0; H *h; u32 f8, fc, f10; u32 f14; } W_021AC384;

typedef struct P_021AC384 { u32 f0; u32 f4; } P_021AC384;

typedef struct Arg_021AC384 { u32 a; V3 v; } Arg_021AC384;

typedef struct Arg { u32 a; V3 v; } Arg;

typedef struct HidObj_021AC660 {
    int f0;
    void *f4;
    u16 f8;
} HidObj_021AC660;

typedef struct X_021AC66C { u32 f0; u32 f4; u16 f8; } X_021AC66C;

typedef struct P_021AC68C { u32 f0; u32 f4; u32 w[4]; } P_021AC68C;

typedef struct Arg_021AC6D4 { u32 a; u8 b4, b5, b6, b7; u32 c; } Arg_021AC6D4;

typedef struct X { u32 f0; u32 f4; u16 h[8]; } X;

typedef struct Arg_021AC760 {
    u32 f0;
    u32 f4;
    int f8;
    int fc;
    u16 h10;
    u16 h12;
    V3 pos;
    int f20;
} Arg_021AC760;

extern void func_0204B09C(int a, int b, P_021A87A8 *c);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B3DC(FieldEffectWork *h, unsigned int v);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020414EC(u32 i);
extern void func_02040618(u32 bgId, u32 which, u32 value);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_02049658(void *o, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_020275E4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern void func_02049238(void *h);
extern void func_020409B4(u32 layer);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern FieldEffectWork *func_0204B034(u8 *a0, u32 a1, u32 heap);
extern void func_0204B258(struct Bank *bank, void *p);
extern FieldEffectWork *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B954(struct Actor *a, u32 v);
extern void func_0204B92C(FieldEffectWork *, u32);
extern void func_0204B84C(u32, int);
extern u32 func_02013CC8(u32 id);
extern u32 func_02013CE0(u16 v);
extern u32 func_02013D20(u16 v);
extern int func_02012B70(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern int func_020084BC(const u16 *values);
extern const void *func_020084F4(const void *p);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern short func_0203F684(unsigned short x);
extern void func_0207E5D0(void *src, u32 off, u32 n);
extern u32 func_020362DC(void);
extern unsigned int func_0203633C(void);
extern void func_020061E4(u32 se);
extern void func_020355D8(u8 v);
extern int func_02035C08(const void *p);
extern void func_0204B404(FieldEffectWork2 *p, const struct Vec2 *delta, u32 which);
extern void func_0204B878(FieldEffectWork2 *p, u16 value);
extern u32 func_02188C54(u8 *p);
extern u32 func_021904AC(u8 *p);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045374(struct Cfg *cfg);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern FieldEffectWork *func_0204B324(u32 owner, u32 i, u32 j, u32 k, u32 e, u16 f, u16 g);
extern unsigned int func_020452E8(struct Descriptor *d);
extern void func_0204B3B4(FieldEffectWork *p);
extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_02045334(struct Descriptor *a);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern void *func_02049EF4(void *o, u32 a, u32 b, void **out, u32 e);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_02041B6C(u8 a);
extern u32 func_020307B0(void *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_02082BCC(void *p, int v, int n);
extern void *func_0200D418(void *p);
extern u8 *func_02012944(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern u8 func_02018598(void *p);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_0200D58C(struct Blk38 *p);
extern u32 func_0201AA50(void *p);
extern u32 func_0201AB08(void *p);
extern u32 func_0209C2B0(u32 a, u32 b);
extern u32 func_02010FB0(u32 v);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern u8 func_0200D488(struct Blk38 *p, u32 i);
extern struct GdsEnt *func_0200D4AC(struct Blk38 *p, u32 i);
extern u32 func_0200D4B8(const struct GdsEnt *e, u32 i);
extern u32 func_02005728(u32 v);
extern void *func_0219390C(void *a, u32 b);
extern u8 *func_02193C00(int a);
extern u32 func_020056EC(u32 v);
extern void *func_0201ADE4(unsigned int a, int b, unsigned int c);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02017E40(void *p, u32 id, u32 v);
extern void func_02018A00(void *p, u32 a, u32 b);
extern void func_020185C4(void *p);
extern void func_0201AE14(void *p);
extern u8 func_0200D454(struct Blk38 *p);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern u32 func_02019C90(u16 a, u16 b, u32 k);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern u32 func_0201AF6C(u32 v);
extern u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern u16 func_02188C84(u8 *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx_021A87A8 *p);
extern u32 func_02012844(const struct BigObj *p);
extern u32 func_0216255C(u32 a);
extern void *func_02030734(u32 a, u32 b, int c, const char *d, u16 e);
extern void *func_02188CB4(struct Obj00020 *p);
extern u32 func_02012A38(const struct BigObj *p);
extern u32 func_02188C6C(u8 *p);
extern u16 func_021A1BF4(u8 *p);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u16 func_02188C9C(u8 *p);
extern void *func_02013090(u32 heap);
extern int func_0216E7C8(int a0, int a1, int a2, int a3, int a4);
extern void func_02013144(char *p, int v);
extern u8 func_02193920(u8 *p);
extern u8 func_02013ED8(u32 id);
extern u32 func_021A30C8(void **ctx);
extern void func_0203F4CC(struct RtcTime *time);
extern u8 func_02012984(const struct BigObj *p);
extern u32 func_02188C98(u8 *p);
extern int func_021938F4(unsigned char *p);
extern fx32 func_0207C7B4(fx32 x);
extern struct Party *func_0201A920(u32 heap);
extern u32 func_020173EC(void);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_0201347C(u8 *a0, void *a1, u32 a2, u32 a3, u32 a4, u16 a5);
extern void func_020130C4(u8 *p);
extern u32 func_0202A230(void *a, u32 idx);
extern u32 func_0202A420(u32 key);
extern void func_02013734(struct Obj02013734 *o, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_020136E0(struct Obj020136E0 *o, u32 a1, u32 a2, u32 a3, u32 a4, u16 a5);
extern void func_02013644(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void func_02013610(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void func_02013678(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void func_020136AC(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void *func_021A3074(u8 *p);
extern int func_0216D83C(void *p);
extern int func_0216D854(void *p);
extern int func_0216D86C(void *p);
extern u32 func_02188CD0(u8 *p);
extern u32 func_02012974(const struct BigObj *p);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern int func_02159C48(int a0, int a1, int a2);
extern int func_02159BD4(int a0, int a1, int a2);
extern void *func_02012F08(int *p);
extern u32 func_0200C234(struct Blk34 *p, u32 bit);
extern u32 func_02188CFC(u8 *p);
extern void func_0216D828(void *p, Vec3s *out);
extern int func_021A3624(void *p);
extern void func_021A3644(void **p);
extern void func_021ADB4C(u32 a, int v);
extern void func_021ADB5C(int a, int b);
extern int func_0218D168(char *p);
extern int func_0218DBD4(char *p, int i);
extern int func_0209BDBC(int a);
extern int func_0209C95C(int a, int b);
extern int func_0209CB8C(int a, int b);
extern int func_0209C494(int a);
extern int func_0218DBAC(u8 *a, int idx, u32 c, u8 *d);
extern void *func_02188C7C(u8 *p);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern int func_0216D454(void *rec);
extern void *func_0216E3C4(void *p);
extern u8 func_021ADAAC(int a, u8 *b, int c, int d, int e, int f);
extern int func_02158768(void *a0, u32 a1, int a2, u16 a3);
extern int func_0218DAEC(void *a, void *b, u32 *out);
extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern void func_0207CA00(const V3 *a, const V3 *b, V3 *out);
extern int func_0207CBD0(const V3 *v);
extern void func_0207CCA4(const V3 *v, V3 *out);
extern unsigned long func_0207CFB8(int x, int z);
extern void func_0218E124(u8 *a, u32 s);
extern void func_0218EC90(u32 a, V3 *v);
extern void func_0218ECF4(u32 a, V3 *v);
extern int FX_Div(int a, int b);
extern void func_0218ED34(u8 *p, u16 v);
extern void func_0218ED48(u8 *p, u32 v);
extern void func_0218ED58(u8 *p, u32 v);
extern void func_0218F0D4(u8 *a, int b);
extern void func_0218F05C(unsigned char *a);
extern u32 sub_0207C768(u32 a, u32 b);
extern void func_0218ECD4(int a, V *v);
extern u32 func_0207C768(u32 a, u32 b);
extern void func_0218ED64(u8 *a, u16 angle);
extern u32 func_02013B38(u32 id);
extern int func_0202E83C(void *a0);
extern u32 func_02188D58(u8 *p);
extern u8 func_020140D8(struct Sub020140BCObj *p);
extern u32 func_02188C88(u8 *p);
extern u32 func_02050080(u32 *p);
extern void func_0204EDBC(u8 *dst, u8 val);
extern void func_0204ED70(u8 *dst, struct Blk3 *src);
extern void func_0204EDB0(u8 *dst, u8 *src);
extern u32 func_02188CD8(u8 *p);
extern u32 func_02030CB0(u32 idx);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void func_02030DA4(int a);
extern void func_02030D28(struct Ctx *c);
extern void *func_02030DA8(u32 heap, void (*cb)(void), void *arg, u32 pri);
extern void func_02030EAC(struct Node *n);
extern void *func_02046F48(struct Tagged *p);
extern unsigned char *func_0206E964(unsigned char *p);
extern void func_02022040(u16 *pal, int n, const u8 *table);
extern void ENV_SetResourceSet(void *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern u16 func_020500F0(struct BbActSys *o, const struct BbActRec *recs, u32 n);
extern void func_02050278(struct BbActSys *o, u32 first, u32 count);
extern int func_0216E1A4(int a0, int a1);
extern u16 func_02050340(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern void func_0204F6DC(u8 *a0, int i, u8 *px);
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
extern int func_0216E1C4(int a0, int a1);
extern void *func_0216D67C(void *a0);
extern int func_0216D98C(int a0);
extern int func_0216DAB4(void *a0);
extern u32 func_0216D57C(void *p, u32 v);
extern void func_0216D92C(u8 *p, s32 *q);
extern void func_0207C9D0(V3 *a, V3 *b, V3 *c);
extern void func_0216D8B0(u8 *p, u8 *q);
extern void func_0204F720(void *p, u32 idx, u32 *flag);
extern void func_0204F638(u8 *a0, int i, struct Trip *src);
extern void func_021C6AE0(u32 a);
extern int func_021C6AF0(u32 a, u32 b, u32 c);
extern void func_021C6AF8(u32 *p, u32 v);
extern void func_021C6AFC(u32 *a, u32 b);
extern int func_021C6574(u32 a, u32 b, u32 c);
extern u32 func_021C6580(u32, u32);
extern u32 func_0216D538(u8 *p);
extern u32 func_021C6590(u32 a, u32 b, u32 c, u32 *d);
void func_021C6628(u32 a, u32 b);
extern int func_021C6694(u32 *a, int idx, int v);
extern u32 func_02188C90(u8 *p);
extern u16 func_0216D588(void *p);
extern u16 func_0216D590(void *p);
extern void func_02164280(int x, int y, int *p);
extern u32 func_0216D8AC(void *p);
extern int func_0216D55C(int a0, int a1);
extern void func_02163E58(u32 a, V3 *v, int *out);
void func_021A87A8(FieldEffectWork4 *s);
void func_021A8840(FieldEffectWork *s);
void func_021A8874(FieldEffectWork *p, void *q, int r, u32 unused);
void func_021A8AFC(int a, int b);
u32 func_021A8B18(void *a, void *b, u32 c);
int func_021A8B84(int idx);
void func_021A8BB8(FieldEffectWork *p, void *q, int r);
void func_021A8D40(void *unused, struct W_021A8D40 *w);
void func_021A8DD8(FieldEffectWork2 *s);
int func_021A8E10(FieldEffectWork *s);
void func_021A8E20(struct W_021A8E20 *w, u32 v);
int func_021A8E78(u32 a, u32 b);
u32 func_021A8E80(struct W_021A8E78 *w, u32 dir);
void func_021A8EEC(FieldEffectWork2 *p);
void func_021A8FFC(struct W_021A8FFC *w);
void func_021A9080(FieldEffectWork3 *s, s16 x, s16 y);
void func_021A90A4(FieldEffectWork3 *s, int m);
void func_021A90E0(struct W *w);
void func_021A9154(FieldEffectWork *p, FieldEffectWork6 *it, const Src *s);
void func_021A926C(int a, FieldEffectWork3 *s);
void func_021A9294(int a, FieldEffectWork2 *s);
void func_021A92A4(u32 a, u32 b);
void func_021A9350(struct Sel_021A8E78 *s, void *a, int b, int c, u16 d);
u32 func_021A94B0(struct Obj *o, u32 unused, u32 n);
int func_021A9508(u8 *u, void *arg, struct Slot14_021A94B0 *slots);
int func_021A954C(void *a0, void *u, u16 id, void *slots);
void *func_021A957C(void *a0, struct Unit_021A8E78 *u, u32 want);
u32 func_021A9604(int obj, struct Sel_021A94B0 *sel, struct Out *out);
void func_021A96B8(void *mon, const struct Unit_021A96B8 *u, struct Slot14_021A9604 *s);
void func_021A9780(void *mon, const struct Unit_021A9780 *u, void *src);
u16 func_021A9810(int a);
void func_021A9828(struct Sel_021A87A8 *s, u16 d);
int func_021A996C(struct Unit_021A9828 *u, u8 n);
const struct Entry8_021A8E78 *func_021A99A8(void *p);
int func_021A99E4(void *a0, struct Unit_021A87A8 *u, u16 id, struct Spec *spec);
u8 func_021A9A5C(u8 *a0, struct Unit_021A9A5C *u, u16 id, struct Spec *spec);
void func_021A9B00(struct Spec *spec, struct Slot14_021A87A8 *s);
u8 func_021A9B68(u8 *u, struct Spec *specs, u32 type);
void func_021A9BE8(const struct Unit_021A9BE8 *u, const struct Spec *specs, struct Slot14_021A87A8 *s);
void func_021A9C58(struct Unit_021A9C58 *u, struct Spec *specs, struct Slot14_021A9C58 *s);
void func_021A9CAC(void *mon, void *src, int a, int b);
u32 func_021A9D30(struct Unit_021A9D30 *u, void *src, struct Slot14_021A9C58 *s);
u32 func_021A9DC8(void);
u32 func_021A9DE0(void);
int func_021A9E64(int a);
int func_021A9E98(int a);
u32 func_021A9EC4(u32 a);
u32 *func_021A9ED8(u32 a);
int func_021A9F28(void *a, u32 b, u32 c, u32 d);
int func_021A9F40(struct Ctx_021A87A8 *ctx, int mode);
void func_021AA0A0(FieldEffectWork2 *s, u16 a, u8 b, u32 flags);
struct Obj *func_021AA180(struct Ctx_021A87A8 *ctx, int mode);
int func_021AA248(struct Ctx_021AA248 *ctx, void *b);
void func_021AA304(struct Info_021A87A8 *out, void *a1, void *a2);
int func_021AA35C(void **ctx, int mode, u8 *out);
int func_021AA3E0(struct Tab *t, int i, int add);
int func_021AA3FC(void *a0, void *p, u32 rate);
int func_021AA42C(void *a, void *b);
void func_021AA490(struct Ctx_021AA3E0 *ctx, struct Unit_021AA3E0 *u, void *a2, u16 heap, struct Slot14 *slots);
void func_021AA548(struct Ctx_021AA3E0 *ctx, void *a1, void *a2, u16 heap, void *src);
void func_021AA5CC(struct Ctx_021AA3E0 *ctx, void *a1, u32 mode, u32 flag, void *mon, u32 a5, u16 heap);
u8 func_021AA69C(void *p);
u32 func_021AA6E0(void);
void func_021AA6F8(struct Pos *p, void *q);
void func_021AA728(struct Pos *p, void *q);
u32 func_021AA778(u8 *p);
void *func_021AA77C(int heap);
int func_021AA794(void *a);
void func_021AA7AC(u32 a, u32 b);
void func_021AA7CC(u32 a, u32 b, u32 c, u32 d);
void func_021AA7DC(S_021AA7AC *s, D_021AA7AC *d);
void func_021AA80C(struct Ctx_021AA7DC *ctx);
void func_021AA8EC(u8 *p);
void func_021AA8F8(struct Self *a0);
int func_021AA900(FieldEffectWork *self, short *pos);
int func_021AA944(Self_021AA944 *self);
int func_021AAA4C(Self *self, short *out);
void func_021AAABC(FieldEffectWork5 *s);
void func_021AAAF0(FieldEffectWork5 *s, int b);
void func_021AAB1C(FieldEffectWork5 *s, int b);
u16 func_021AAB48(char *p);
void func_021AAB54(FieldEffectWork5 *s);
void func_021AAB74(Self *self, int a);
int func_021AABC4(FieldEffectWork6 *s, FieldEffectWork6 *d);
void func_021AABEC(u8 *p);
void func_021AABF4(struct Ctx *ctx, void *unused, struct Area *a);
void func_021AACD4(void **ctx, struct Enc_021AACD4 *e);
void func_021AAE34(FieldEffectWork2 *s, R_021AAE34 *r);
int func_021AAEC0(Self_021AAEC0 *self, s16 x, s16 y2, s16 z, int skip);
int func_021AAF54(Self_021AAF54 *self);
void func_021AAFA0(FieldEffectWork6 *s, D_021AAFA0 *d);
void func_021AAFC0(int a, D_021AAFC0 *d, FieldEffectWork4 *r);
void func_021AAFFC(FieldEffectWork6 *d);
unsigned short func_021AB018(void);
u16 func_021AB070(void);
int func_021AB0AC(S_021AAFFC *s, u16 v);
int func_021AB0D4(void *a, void *b);
u16 func_021AB0F0(u32 attr);
u16 func_021AB0F8(u32 attr);
BOOL func_021AB100(u32 attr);
BOOL func_021AB11C(u32 attr);
int func_021AB140(int x);
BOOL func_021AB158(u16 id);
BOOL func_021AB164(u16 id);
BOOL func_021AB170(u16 id);
BOOL func_021AB17C(u16 id);
BOOL func_021AB188(u16 id);
BOOL func_021AB194(u16 id);
int func_021AB1A0(int x);
BOOL sub_021AB1AC(u16 id);
BOOL sub_021AB1B8(u16 id);
BOOL sub_021AB1C4(u16 id);
BOOL sub_021AB1D0(u16 id);
BOOL sub_021AB1DC(u16 id);
BOOL sub_021AB1E8(u16 id);
BOOL sub_021AB1F4(u16 id);
BOOL sub_021AB200(u16 id);
BOOL sub_021AB20C(u16 id);
BOOL sub_021AB218(u16 id);
BOOL sub_021AB224(u16 id);
BOOL sub_021AB230(u16 id);
BOOL func_021AB23C(u16 id);
BOOL func_021AB250(u16 id);
BOOL func_021AB264(u16 id);
BOOL func_021AB270(u16 id);
BOOL func_021AB27C(u16 id);
BOOL func_021AB29C(u16 id);
BOOL func_021AB2BC(u16 id);
BOOL func_021AB2DC(u16 id);
BOOL func_021AB2E8(int id);
int func_021AB2F8(int x);
BOOL sub_021AB304(u16 id);
BOOL func_021AB310(u16 id);
BOOL func_021AB31C(u16 id);
BOOL func_021AB328(int id);
BOOL func_021AB334(u16 id);
BOOL func_021AB348(u32 id);
int func_021AB358(int x);
BOOL func_021AB364(u16 id);
BOOL func_021AB370(u16 id);
BOOL func_021AB37C(u32 id);
BOOL func_021AB390(u16 id);
BOOL func_021AB3B0(u16 id);
int func_021AB3D4(int x);
BOOL sub_021AB3E0(u16 id);
BOOL sub_021AB3EC(u16 id);
BOOL sub_021AB3F8(u16 id);
int func_021AB404(int x);
int func_021AB410(int x);
BOOL sub_021AB41C(u16 id);
BOOL sub_021AB428(u16 id);
BOOL sub_021AB434(u16 id);
BOOL sub_021AB440(u16 id);
BOOL sub_021AB44C(u16 id);
int func_021AB458(int id);
int func_021AB474(int id);
int func_021AB490(int id);
int func_021AB4A4(int id);
int func_021AB4B8(int id);
BOOL sub_021AB4EC(u16 id);
BOOL sub_021AB4F8(u16 id);
int func_021AB504(u32 attr);
u8 func_021AB580(u16 x);
int func_021AB5AC(unsigned long a, unsigned long b);
FieldEffectWork3 *func_021AB5F4(int heap, int a, int b);
void func_021AB624(u8 *p);
void func_021AB634(FieldEffectWork3 *s, int a, int b, int c);
void func_021AB650(FieldEffectWork3 *s);
int func_021AB660(struct Obj_021AB660 *o, void *arg);
void func_021AB75C(u8 *p, u32 v);
u32 func_021AB760(u8 *p);
u32 func_021AB764(u8 *p);
int func_021AB768(u32 a, u32 b);
int func_021AB780(u32 a, u32 b);
int func_021AB798(S_021AB768 *s, int i, int a, int b, int c);
void func_021AB7C0(S_021AB768 *s, int i, int a, int b, int c);
S_021AB7E4 *func_021AB7E4(int heap);
void func_021AB81C(S_021AB7E4 *s);
void func_021AB840(S_021AB840 *s, int i, int b, int d);
void func_021AB868(S_021AB868 *s);
u32 func_021AB880(u8 *p);
u32 func_021AB884(u8 *p);
void *func_021AB888(void);
int func_021AB890(void *self, const Range *r, V3 *ref);
void func_021AB908(u32 a0, const u8 *p, const V3 *q);
void func_021AB9FC(int a, const FieldEffectWork5 *s);
int func_021ABA3C(int a, const u16 *r, V *v);
void func_021ABABC(int a0, const u16 *p, void *q);
void func_021ABB54(int a, FieldEffectWork4 *s, int c);
void func_021ABB78(int a, FieldEffectWork4 *s, int c);
void func_021ABBA0(u16 *r, V *v, int *o1, int *o2);
void func_021ABBF0(u8 *a, u32 b, u32 c, u32 d);
void func_021ABC14(u8 *a, u32 b, u32 c, u32 d);
void func_021ABC38(u8 *a, u32 b, u32 c, u32 d);
void func_021ABC5C(u8 *a0, char *p, void *q);
void func_021ABD08(unsigned char *a, const FieldEffectWork6 *s, int c);
char *func_021ABD50(int a, int b, u16 c);
int func_021ABDE8(void *a, u32 b, u32 c, u32 d);
void func_021ABE04(u32 a);
void func_021ABE0C(u32 a);
u32 func_021ABE14(u8 *p);
u32 func_021ABE18(u8 *p);
u32 func_021ABE24(u8 *p);
u8 func_021ABE28(u8 *p);
u8 func_021ABE2C(u8 *p);
void func_021ABE30(T *t, int *arr, int n);
void func_021ABE64(T_021ABE64 *t, int id);
int func_021ABE8C(T_021ABE64 *a, int id);
int func_021ABEA0(u32 a, u32 b);
void func_021ABEAC(T_021ABEA0 *t);
void func_021ABEE8(O *o);
E_021ABE30 *func_021ABF2C(T *t, int id);
D_021ABF48 *func_021ABF48(int id);
void func_021ABF68(FieldEffectWork5 *t, int n);
void func_021ABFA8(FieldEffectWork5 *t, int b, int c, int d, int e, int f);
void func_021ABFC0(FieldEffectWork5 *t);
void func_021ABFDC(FieldEffectWork5 *t);
void func_021ABFEC(FieldEffectWork5 *t);
char *func_021ABFFC(u16 heap, int b, int cnt);
void func_021AC03C(U *u);
void func_021AC074(Mgr_021AC074 *m);
Obj_021AC0A0 *func_021AC0A0(Mgr_021AC0A0 *m, const ObjFuncs *funcs, const V3 *pos, u32 f4, u32 f8, u32 pri);
void func_021AC134(u32 a, u32 b);
void func_021AC140(Obj_021AC074 *o);
void func_021AC154(Obj_021AC154 *o);
void func_021AC178(Obj_021AC154 *o);
void func_021AC18C(Obj_021AC154 *o);
int func_021AC1A0(u32 a);
int func_021AC1AC(u32 a);
void func_021AC1B8(Obj_021AC154 *o, V3 *out);
void func_021AC1CC(Obj_021AC154 *o, V3 *in);
int func_021AC1E0(u32 a);
void func_021AC1EC(u32 *p, u32 v);
void func_021AC1F0(FieldEffectWork3 *x, void *b);
char *func_021AC218(int a, int heap);
void func_021AC260(u32 a, u8 *p);
void func_021AC274(Ctl *p);
void func_021AC2AC(u8 *p);
void func_021AC2C0(u32 a, u32 b);
void func_021AC2F0(u32 a, P_021AC074 *p);
void func_021AC384(u32 a, W_021AC384 *w);
void func_021AC3A4(u32 a, u32 *b);
void func_021AC3F8(u32 unused, u32 *p);
P_021AC384 *func_021AC494(u32 a, int heap);
void func_021AC4B8(u32 a, u8 *p);
void func_021AC4CC(u32 *a);
int func_021AC514(u32 a);
void func_021AC528(u32 a, u32 b);
void func_021AC578(u32 a, u32 b);
void func_021AC62C(u32 a, u32 *b);
void func_021AC660(u32 a, HidObj_021AC660 *q);
void func_021AC66C(u32 a, X_021AC66C *x);
void func_021AC688(void);
P_021AC68C *func_021AC68C(int a, int heap);
void func_021AC6C0(u32 a, u8 *p);
void func_021AC6D4(u32 *p);
void func_021AC740(X *x);
void func_021AC760(u32 a, u32 b, u32 c, int d);
extern const u8 d_021D8BBC[];
extern const u8 d_021D8B5C[];
extern const u8 d_021D8B7C[];
extern const u32 d_021D8B44[];
extern const Bank d_021D8C1C;
extern const int d_021D8D24[][7];
extern const Name d_021D8C0C;
extern const u16 d_021D8B34[];
extern const Rect d_021D8CAC[];
extern const Pos_021A8AFC d_021D8B18[];
extern u8 d_021D8C4C[][8][4];
extern u8 d_021D8B26[];
extern u8 d_021D8B27[];
extern struct Buf32 d_021D8C2C;
extern const struct Entry8_021A8E78 data_021D8DE8[];
extern const u8 data_021D8DCC[];
extern int d_021DDFA4;
extern const char data_021DDFA4[];
extern char d_021DDFB4[];
extern const Pair d_021D8E70[];
extern const s8 d_021D8E76[][4];
extern unsigned short d_021D8E8A[];
extern const u8 data_021D8EA0[];
extern const u8 data_021D8EA1[];
extern char d_021DDFC8[];
extern char d_021DE000[];
extern const int d_021D8EEC[];
extern s16 tbl_020A1B38[];
extern char d_021DE018[];
extern V d_021D8F04;
extern D_021ABF48 d_021D8F60[];
extern char d_021DE028[];
extern V d_021D908C;
extern u8 d_021D9098[];
extern char d_021DE038[];
extern u8 d_021D90AC[];
extern char d_021DE070[];
extern u16 d_021D911C[];
extern u8 d_021D90EC[];



















void func_021A87A8(FieldEffectWork4 *s)
{
    P_021A87A8 v;
    P_021A87A8 p4;
    P_021A87A8 p0;
    u8 i;

    v.x = 0;
    v.y = -s->hfc;
    func_0204B09C(s->f120, 0, &v);
    for (i = 0; i < 7; i++) {
        if (s->f38[i].f10 != 0 && s->f38[i].f0 != 7) {
            func_0204B454((struct Actor *)s->f38[i].f10, (struct PtS *)&p4, 0);
            if (p4.y < 0xd0) {
                func_0204B3DC((FieldEffectWork *)s->f38[i].f10, 1);
            } else {
                func_0204B3DC((FieldEffectWork *)s->f38[i].f10, 0);
            }
        }
    }
    func_0204B454((struct Actor *)s->f124, (struct PtS *)&p0, 0);
    if (s->f2c != 0 && p0.y < 0xd6) {
        func_0204B3DC((FieldEffectWork *)s->f124, 1);
    } else {
        func_0204B3DC((FieldEffectWork *)s->f124, 0);
    }
}



















void func_021A8840(FieldEffectWork *s)
{
    if (s->f100 == 1) {
        func_02041EE4(5, 3, -s->hfc);
        func_02041EE4(6, 3, -5 - s->hfc);
        s->f100 = 0;
    }
}



















void func_021A8874(FieldEffectWork *p, void *q, int r, u32 unused)
{
    void *h;
    u32 t;
    Pos_021A87A8 pos;
    Bank bank;

    func_0207D534((volatile u16 *)0x0400106C, -16);
    func_0203FCA0(5, (const struct BgTemplate *)d_021D8BBC, 0);
    func_02040588(5, 1);
    func_020414EC(5);
    func_0203FCA0(6, (const struct BgTemplate *)d_021D8B5C, 0);
    func_02040588(6, 1);
    func_020414EC(6);
    func_0203FCA0(7, (const struct BgTemplate *)d_021D8B7C, 0);
    func_02040588(7, 1);
    func_020414EC(7);
    func_02040618(6, 3, -5);
    func_02049B68(q, 0, 4, 0, 0, p->f02);
    func_02049658(q, 2, 5, 0, 0, 0, p->f02);
    func_020498F4(q, d_021D8B44[r], 5, 0, 0, 0, p->f02);
    func_020498F4(q, 0xE, 7, 0, 0, 0, p->f02);
    p->f104 = func_0204AC18(q, 1, 1, 0, 0, 0xB, p->f00);
    p->f108 = func_0204A6C8(q, 0xD, 0, 1, p->f00);
    p->f10C = func_0204AF28(q, 0x1C, 0x26, p->f00);
    h = func_020490F4(func_020275E4(), p->f02);
    p->f110 = func_0204AC18(h, func_02027614(), 1, 0x160, 0, 2, p->f00);
    p->f114 = func_0204A6C8(h, func_02027618(), 0, 1, p->f00);
    t = func_0202761C(0);
    p->f118 = func_0204AF28(h, t, func_02027620(0), p->f00);
    func_02049238(h);
    func_020409B4(5);
    p->f11C = (u32)func_0204B100(8, 0, p->f00);
    bank = d_021D8C1C;
    p->f120 = (u32)func_0204B034((u8 *)(&bank), 1, p->f00);
    func_0204B258((struct Bank *)p->f11C, (void *)p->f120);
    pos.x = 0x40;
    pos.y = 0x2C;
    pos.z = 0;
    pos.a = 0;
    pos.b = 0;
    p->f124 = (u32)func_0204B294((void *)p->f11C, p->f108, p->f104, p->f10C, &pos, 0, p->f00);
    func_0204B954((struct Actor *)p->f124, 0x1000);
    func_0204B92C((FieldEffectWork *)p->f124, 1);
    func_0204B84C(p->f124, 2);
    pos.x = 0xE0;
    pos.y = 0xA8;
    p->f128 = (u32)func_0204B294((void *)p->f11C, p->f114, p->f110, p->f118, &pos, 0, p->f00);
    func_0204B954((struct Actor *)p->f128, 0x1000);
    func_0204B92C((FieldEffectWork *)p->f128, 1);
    func_0204B3DC((FieldEffectWork *)p->f128, 1);
    func_0204B954((struct Actor *)p->f128, 0x2000);
}



















void func_021A8AFC(int a, int b)
{
    func_021A92A4(a, 4);
    if (b != 0) {
        func_02040588(4, 0);
    }
}



















/*
 * Addresses are Black-image addresses.
 */
u32 func_021A8B18(void *a, void *b, u32 c)
{
    u32 r = 0;

    if (func_02013CC8((u16)c) || func_02013CE0(c)) {
        r = 1;
    } else if (func_02013D20(c)) {
        r = 4;
    } else if (func_02012B70(a)) {
        r = 5;
    } else if (!func_020142E8(b, 0x961)) {
        r = 3;
    } else if (!func_020142E8(b, 0x962)) {
        r = 2;
    }
    return r;
}


















int func_021A8B84(int idx)
{
    int i;
    int n;
    i = 0;
    n = 0;
    for (; d_021D8D24[idx][i] != 0; i++) {
        if (d_021D8D24[idx][i] != 7) {
            n++;
        }
    }
    return n;
}



















void func_021A8BB8(FieldEffectWork *p, void *q, int r)
{
    void *h;
    u8 i;
    u8 j;
    int k;
    const int *row;
    St st;
    Name n;
    Name def;

    h = func_02045B38(0, 2, 0x22, p->f02);
    for (i = 0; i < 7; i++) {
        p->f34[i].f00 = 0;
    }
    j = 0;
    row = d_021D8D24[r];
    def = d_021D8C0C;
    for (; j < 7; j++) {
        k = row[j];
        if (k == 4) {
            st.s = func_020457B0(0x10, p->f02);
            if (func_020084BC(p->f18) == 0) {
                func_02045924(st.s, func_020084F4(p->f18));
            } else {
                n = def;
                func_02045924(st.s, n.s);
            }
        } else {
            st.s = func_02045EC0(h, d_021D8B34[k]);
        }
        st.k = k;
        if (j != 6) {
            st.x = (j % 2) * 128 + 0x40;
            st.y = (j / 2) * 0x30 + 0x2C;
            st.b8 = st.x - 0x20;
            st.b9 = st.y;
            st.q = q;
            st.a = d_021D8CAC[k].a;
            st.b = d_021D8CAC[k].b;
            st.c = d_021D8CAC[k].c;
            if (k == 3 && func_02008550(p->f18) == 1) {
                st.a = 7;
                st.b = 0x16;
                st.c = 0x20;
            }
            if (k == 2 && func_02008550(p->f18) == 1) {
                st.a = 0xC;
                st.b = 0x1B;
                st.c = 0x25;
            }
        } else {
            st.x = 0x80;
            st.y = 0xB4;
            st.b8 = 0;
            st.b9 = 0;
            st.q = 0;
            st.a = 0;
            st.b = 0;
            st.c = 0;
        }
        st.b6 = d_021D8B18[j].x;
        st.b7 = d_021D8B18[j].y;
        func_021A9154((FieldEffectWork *)p, (FieldEffectWork6 *)(&p->f34[j]), (const Src *)((const struct Src *)(&st)));
        func_02045808(st.s);
    }
    func_02045C04(h);
}


















void func_021A8D40(void *unused, struct W_021A8D40 *w)
{
    s32 t = func_0203F684((u16)w->f134) + 0x1000;
    u16 c[2];

    c[1] = (t * 8 / 0x2000 + 9) | ((0x1F << 10) | ((t * 5 / 0x2000 + 0x12) << 5));
    func_0207E5D0(&c[1], 0x142, 2);
    c[0] = (t * 0x1F / 0x2000) |
           (((t * 6 / 0x2000 + 0x19) << 10) | ((t * 13 / 0x2000 + 0x12) << 5));
    func_0207E5D0(&c[0], 0x15E, 2);
    w->f134 += 6;
}


















void func_021A8DD8(FieldEffectWork2 *s)
{
    P_021A8D40 v;
    s->hfc = 0xc0;
    func_02040618(5, 3, -0xc0);
    func_02040618(6, 3, -0xc5);
    v.x = 0;
    v.y = 0xc0;
    func_0204B09C(s->f120, 0, (void *)&v);
}


















int func_021A8E10(FieldEffectWork *s)
{
    FieldEffectWork2 *p = s->fF8;
    if (p == 0) {
        return 0;
    }
    return p->f8;
}


















void func_021A8E20(struct W_021A8E20 *w, u32 v)
{
    u8 i;
    struct Slot *s;

    for (i = 0, s = w->slots; i < 7; i++) {
        if (w->slots[i].f00 == 1 && v == w->slots[i].f08) {
            w->f1E = i % 2;
            w->f1F = i / 2;
            w->f24 = 1;
            func_021A9080((FieldEffectWork3 *)w, s[w->f1E + w->f1F * 2].f14, s[w->f1E + w->f1F * 2].f15);
        }
    }
}
























/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A8E78(u32 a, u32 b)
{
return (a + (b << 1));
}
























/*
 * Addresses are Black-image addresses.
 */
u32 func_021A8E80(struct W_021A8E78 *w, u32 dir)
{
    u32 idx = func_021A8E78(w->f1E, w->f1F);
    u32 r = d_021D8C4C[func_021A8B84(w->f21) - 4][idx][dir];

    if (idx != r) {
        if (r == 0xFF) {
            w->f1F = 2;
            return 1;
        }
        if (r == 0xFE) {
            w->f1F = 1;
            return 1;
        }
        if (r != 6) {
            w->f1E = d_021D8B26[r * 2];
        }
        w->f1F = d_021D8B27[r * 2];
        return 1;
    }
    return 0;
}























void func_021A8EEC(FieldEffectWork2 *p)
{
    u32 trg;
    u32 rep;

    trg = func_020362DC();
    rep = func_0203633C();
    if (p->f2C == 0 && (trg | rep) != 0) {
        if ((trg & 2) || (trg & 0x400)) {
            func_021A90A4((void *)p, 1);
            return;
        }
        func_020061E4(0x548);
        p->f2C = 1;
        p->fF8 = 0;
        p->f24 = 1;
        func_0204B3DC((FieldEffectWork *)((FieldEffectWork2 *)p->f124), 1);
        return;
    }
    if (rep & 0x40) {
        if (func_021A8E80((struct W_021A8E78 *)p, 0) != 0) {
            p->f24 = 1;
            func_020061E4(0x548);
        }
    } else if (rep & 0x80) {
        if (func_021A8E80((struct W_021A8E78 *)p, 1) != 0) {
            p->f24 = 1;
            func_020061E4(0x548);
        }
    } else if (rep & 0x20) {
        if (func_021A8E80((struct W_021A8E78 *)p, 2) != 0) {
            p->f24 = 1;
            func_020061E4(0x548);
        }
    } else if (rep & 0x10) {
        if (func_021A8E80((struct W_021A8E78 *)p, 3) != 0) {
            p->f24 = 1;
            func_020061E4(0x548);
        }
    } else if ((trg & 2) || (trg & 0x400)) {
        func_021A90A4((void *)p, 1);
    } else if (trg & 1) {
        if (p->f34[func_021A8E78(p->f1E, p->f1F)].f08 != 7) {
            func_021A90A4((void *)p, 0);
            func_020355D8(0);
        }
    }
}






















void func_021A8FFC(struct W_021A8FFC *w)
{
    struct Buf32 buf = d_021D8C2C;
    int r = func_02035C08(&buf);
    u32 z;

    if (r != -1 && w->slots[r].f08 != 7) {
        w->f1E = r % 2;
        w->f1F = r / 2;
        z = 0;
        w->f2C = z;
        func_0204B3DC((FieldEffectWork *)w->f124, 0);
        if (r == 6) {
            func_021A90A4((void *)w, 1);
            return;
        }
        w->f24 = 1;
        func_021A90A4((void *)w, z);
        func_020355D8(1);
    }
}






















void func_021A9080(FieldEffectWork3 *s, s16 x, s16 y)
{
    P_021A9080 v;
    v.x = x;
    v.y = y;
    func_0204B404((FieldEffectWork2 *)s->f124, (const struct Vec2 *)(&v), 0);
    s->f134 = 0;
}






















void func_021A90A4(FieldEffectWork3 *s, int m)
{
    if (m == 1) {
        s->f28 = 1;
        s->fc = 4;
        func_0204B878((FieldEffectWork2 *)s->f128, 8);
    } else {
        s->f28 = 0;
        s->fc = 5;
        s->f30 = s->f38[func_021A8E78(s->b1e, s->b1f)].f0;
    }
}






















void func_021A90E0(struct W *w)
{
    struct Slot *old;

    if (w->f24 == 1) {
        old = w->cur;
        w->cur = &w->slots[w->f1E + w->f1F * 2];
        func_0204B878(w->f124, 0);
        func_021A9080((void *)w, w->cur->f14, w->cur->f15);
        if (w->cur->f18 != 0 && w->f2C == 1) {
            func_0204B878(w->cur->f18, 1);
        }
        if (old != 0 && old->f18 != 0) {
            func_0204B878(old->f18, 0);
        }
        w->f24 = 0;
    }
}






















void func_021A9154(FieldEffectWork *p, FieldEffectWork6 *it, const Src *s)
{
    Hdr h;
    u32 k;

    k = func_021904AC((u8 *)func_02188C54(p->f04));
    it->f00 = 1;
    it->f08 = s->f00;
    it->f14 = s->f04;
    it->f15 = s->f05;
    it->f04 = func_020450F0(6, s->f06, s->f07, 8, 2, 0xD, 1);
    func_02045374((struct Cfg *)it->f04);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)it->f04)), 0);
    func_0201C724((void *)p->f12C, (int)func_02045770((struct Descriptor *)it->f04), 2, 1, s->f0C, k, 0x440);
    if (s->f10 != 0) {
        it->f0C = func_0204A6C8((void *)s->f10, s->f14, 0, 1, p->f00);
        it->f10 = func_0204AF28((void *)s->f10, s->f18, s->f1C, p->f00);
        h.f00 = s->f08;
        h.f02 = s->f09;
        h.f04 = 0;
        h.f06 = 0;
        h.f07 = 0;
        h.f08 = 0;
        h.f0A = 0;
        h.f0C = 0x1000;
        h.f10 = 0x1000;
        h.f14 = 0;
        h.f16 = 2;
        it->f18 = (u32)func_0204B324(p->f11C, it->f0C, p->f104, it->f10, (u32)(&h), 0, p->f00);
        func_0204B954((struct Actor *)it->f18, 0x1000);
        func_0204B92C((FieldEffectWork *)((FieldEffectWork *)it->f18), 1);
        func_0204B878((void *)((FieldEffectWork *)it->f18), 0);
        if (it->f08 == 7)
            func_0204B3DC((FieldEffectWork *)((void *)((FieldEffectWork *)it->f18)), 0);
        else
            func_0204B3DC((FieldEffectWork *)((void *)((FieldEffectWork *)it->f18)), 1);
    } else {
        it->f18 = 0;
    }
}






















void func_021A926C(int a, FieldEffectWork3 *s)
{
    if (s->f0 == 1) {
        func_020452E8((struct Descriptor *)s->f4);
        if (s->f18 != 0) {
            func_0204B3B4((FieldEffectWork *)s->f18);
            func_0204AFD8(s->f10);
            func_0204A8D4(s->fc);
        }
    }
}






















void func_021A9294(int a, FieldEffectWork2 *s)
{
    if (s->f0 == 1) {
        func_02045334((struct Descriptor *)s->f4);
    }
}






















void func_021A92A4(u32 a, u32 b)
{
    struct Scr *ptr;
    void *h;
    int i;
    u16 *d;
    void *o;

    o = func_020490F4(func_020275E4(), a);
    func_02049B68(o, func_02027624(), 4, 0x60, 0x20, a);
    func_02049658(o, func_02027628(), b, 0x80, 0, 0, a);
    h = func_02049EF4(o, func_0202762C(), 0, (void **)&ptr, a);
    func_02049238(o);
    d = ptr->data;
    for (i = 0; i < 0x300; i++) {
        d[i] = (d[i] + 0x80) | 0x3000;
    }
    func_020410D0((u8)b, 0, 0x15, 0x20, (u32)3, (u32)ptr->data, (u32)0, (u32)0x15, (u32)0x20, (u32)0x18);
    func_02041B6C(b);
    func_020307B0(h);
}






















void func_021A9350(struct Sel_021A8E78 *s, void *a, int b, int c, u16 d)
{
    void *t;
    void *party;
    void *mon;

    t = func_02012EBC(a);
    party = func_02012934(a);
    func_02082BCC(s, 0, 0x2C);
    s->f08 = b;
    s->f0C = c;
    s->f00 = a;
    s->f04 = func_0200D418(t);
    if (b == 5 || b == 6)
        s->b1 = 1;
    s->f24 = func_02012944(a);
    s->f20 = func_02008530(s->f24);
    mon = func_0201AB28(party, 0);
    s->f1A = func_02017E1C(mon, 0x4C, 0);
    if (s->f1A == 0) {
        s->f16 = func_02017E1C(mon, 5, 0);
        s->f18 = func_02017E1C(mon, 6, 0);
        s->f1B = func_02017E1C(mon, 10, 0);
        s->f1C = func_02017E1C(mon, 0x6E, 0);
        s->f1D = func_02018598(mon);
        func_021A9828((struct Sel_021A87A8 *)((void *)s), d);
    }
    s->b0 = func_020142E8((void *)func_0201296C(a), 0x960);
    if (func_0200D58C(func_0200D418(t)) == 0)
        s->b2 = 1;
    if (s->f0C == 2) {
        s->b3 = 1;
        s->f0C = 0;
    }
    if (s->f0C == 1)
        s->b3 = 1;
    s->b4 = 0;
    s->b5 = 0;
    if (s->f08 == 1 && (int)func_0201AA50(party) >= 2 && func_021A9DC8() < 0x28)
        s->b5 = 1;
    if (s->b15 || s->b2)
        s->f1E = func_02017E1C(func_0201AB28(party, func_0201AB08(party)), 0x9E, 0);
    s->f15 = s->b5 + 1;
}





















u32 func_021A94B0(struct Obj *o, u32 unused, u32 n)
{
    u32 v = n;

    if (o->b1) {
        if (o->b8) {
            v = v * 2;
        }
        if (v > 100) {
            v = 100;
        }
        return v;
    }
    if (o->b6) {
        v = v * 2;
    } else if (o->b7) {
        v = v >> 1;
    }
    if (o->f18 == 0xE0 || o->f18 == 0x140) {
        v = func_0209C2B0(n * 2, 3);
    }
    if (v > 100) {
        v = 100;
    }
    return func_02010FB0(v);
}





















int func_021A9508(u8 *u, void *arg, struct Slot14_021A94B0 *slots)
{
    int n = 0;
    int i;

    for (i = 0; i < u[0x15]; i++) {
        struct Slot14_021A94B0 *s = &slots[n];
        func_021A9C58((struct Unit_021A9C58 *)((struct Unit_021A8E78 *)u), arg, (struct Slot14_021A9C58 *)s);
        if (func_021A996C((void *)((struct Unit_021A8E78 *)u), s->f04) == 0)
            n++;
    }
    return n;
}





















int func_021A954C(void *a0, void *u, u16 id, void *slots)
{
    struct Spec specs[12];

    MIi_CpuClear32(0, specs, sizeof(specs));
    func_021A9A5C(a0, u, id, specs);
    return func_021A9508(u, specs, slots);
}





















void *func_021A957C(void *a0, struct Unit_021A8E78 *u, u32 want)
{
    void *buf[2];
    u8 n = 0;
    u8 i;
    void *m;

    for (i = 0; i < 2; i++) {
        if (func_0200D488(u->f04, i) == 0)
            continue;
        m = func_0200D4AC(u->f04, i);
        if (func_0200D4B8(m, 1) != want)
            continue;
        if (func_021A996C((void *)u, func_0200D4B8(m, 6)) != 0)
            continue;
        buf[n++] = m;
    }
    if (n == 0 || func_02005728(1000) < 500)
        return 0;
    return buf[func_02005728(n)];
}





















u32 func_021A9604(int obj, struct Sel_021A94B0 *sel, struct Out *out)
{
    u32 k;
    u32 sum;
    u32 r;
    int i;
    u8 *q;
    int p;

    switch (sel->f08) {
    case 0:
        k = 0;
        break;
    case 1:
        k = 1;
        break;
    case 3:
        k = 2;
        break;
    case 0xFF:
        return 0;
    }
    sum = 0;
    for (i = 0; i < 30; i++) {
        p = (int)func_0219390C((void *)obj, i);
        if (p) {
            sum += func_02193C00(p)[k + 0x14];
        }
    }
    r = func_020056EC(sum);
    sum = 0;
    for (i = 0; i < 30; i++) {
        p = (int)func_0219390C((void *)obj, i);
        if (p) {
            q = func_02193C00(p);
            sum += q[k + 0x14];
            if (r < sum) {
                func_02082BCC(out, 0, 0x14);
                out->f00 = ((u16 *)(q + 8))[k];
                out->f04 = (q + k)[0x10];
                return 1;
            }
        }
    }
    return 0;
}





















void func_021A96B8(void *mon, const struct Unit_021A96B8 *u, struct Slot14_021A9604 *s)
{
    void *pd = func_0201ADE4(s->f00, s->f05, 4);
    u32 pid = func_021A9D30((struct Unit_021A9D30 *)((struct Unit_021A96B8 *)u), pd, (struct Slot14_021A9C58 *)s);

    func_02017588(mon, s->f00, s->f04, u->f20, 0xFFFFFFFF, pid);
    func_02017E40(mon, 0x6F, s->f05);
    if (s->f07)
        func_02018A00(mon, s->f00, s->f05);
    if (s->f02 <= 0x272) {
        if (s->f02 != 0)
            func_02017E40(mon, 6, s->f02);
        else
            func_021A9CAC(mon, pd, u->b9, u->f08 == 1);
    }
    func_02017E40(mon, 0x9A, func_02008550(u->f24));
    func_02017E40(mon, 0x8E, (u32)func_020084F4(u->f24));
    if (u->b10)
        func_02017E40(mon, 0x70, u->f1D);
    func_020185C4(mon);
    func_0201AE14(pd);
}





















/*
 * Addresses are Black-image addresses.
 *
 * Lever: `const struct Unit_021A8E78 *u` settles the argument scheduling before the
 * func_02017588 call (as in ov021_func_021A96B8.c).
 */
/*
 * Addresses are Black-image addresses.
 *
 * Lever: `const struct Unit_021A87A8 *u` settles the argument scheduling before the
 * func_02017588 call (as in ov021_func_021A96B8.c).
 */
void func_021A9780(void *mon, const struct Unit_021A9780 *u, void *src)
{
    u16 species = func_0200D4B8(src, 4);
    u8 level = func_0200D4B8(src, 6);
    u32 pow = func_0200D4B8(src, 2);

    func_02017588(mon, species, level, u->f20, pow, func_0200D4B8(src, 3));
    func_02017E40(mon, 0x70, func_0200D4B8(src, 10));
    func_02017E40(mon, 0x9D, func_0200D4B8(src, 7));
    func_02017E40(mon, 0xA0, func_0200D4B8(src, 5));
    func_020185C4(mon);
}





















u16 func_021A9810(int a)
{
    u16 *p = (u16 *)func_021A99A8((void *)a);
    if (p == 0) {
        return 0xffff;
    }
    return *p;
}




















void func_021A9828(struct Sel_021A87A8 *s, u16 d)
{
    switch (s->f1B) {
    case 0x23:
    case 0x47:
    case 0x63:
        s->b6 = 1;
        return;
    case 0x01:
    case 0x49:
    case 0x5F:
        s->b7 = 1;
        return;
    case 0x08:
        if (d == 3 || d == 12)
            s->b7 = 1;
        return;
    case 0x51:
        if (d == 1 || d == 4 || d == 5)
            s->b7 = 1;
        return;
    case 0x15:
    case 0x3C:
        if (s->b1)
            s->b8 = 1;
        return;
    case 0x0E:
        s->b9 = 1;
        return;
    }
    if (s->f1B == 0x38 && func_021A9DC8() < 0x43) {
        s->b11 = 1;
        return;
    }
    if (func_021A9DC8() < 0x32)
        return;
    switch (s->f1B) {
    case 0x2A:
        s->b12 = 1;
        return;
    case 0x09:
        s->b13 = 1;
        return;
    case 0x2E:
    case 0x37:
    case 0x48:
        s->b14 = 1;
        return;
    case 0x16:
    case 0x33:
        s->b15 = 1;
        return;
    case 0x1C:
        s->b10 = 1;
        return;
    }
}




















int func_021A996C(struct Unit_021A9828 *u, u8 n)
{
    if (u->b3)
        return 0;
    if (u->b15 && u->f1E >= n + 5)
        return 1;
    if (!u->b1 && u->b2 && n < u->f1E)
        return 1;
    return 0;
}



















const struct Entry8_021A8E78 *func_021A99A8(void *p)
{
    void *q = func_02012EBC(p);
    u32 k;

    if (func_020142E8((void *)func_0201296C(p), 0x960) == 0)
        return 0;
    k = func_0200D454(func_0200D418(q));
    if (k >= 0x11)
        k = 0;
    return &data_021D8DE8[k];
}


















int func_021A99E4(void *a0, struct Unit_021A87A8 *u, u16 id, struct Spec *spec)
{
    const struct Entry8_021A99E4 *e = (void *)func_021A99A8(u->f00);

    if (e == 0 || e->f00 != id)
        return 0;
    if (u->f08 != 0)
        return 0;
    if (func_02005728(1000) > 400)
        return 0;
    spec->id = e->f02;
    spec->lo = e->f05;
    spec->hi = e->f06;
    spec->lvl = e->f04;
    u->f10 = 3;
    u->f14 = 1;
    return 1;
}



















/*
 * Addresses are Black-image addresses.
 *
 * Shape: n is a u8 (the return needs no truncation) and each case assigns
 * mode, then n, then src; that order keeps every case its own block with a
 * branch to the join and gives n r6, src r4.
 */
u8 func_021A9A5C(u8 *a0, struct Unit_021A9A5C *u, u16 id, struct Spec *spec)
{
    u8 n = 0;
    u32 mode = 0;
    u8 *src;

    if (func_021A99E4(a0, (struct Unit_021A87A8 *)((void *)u), id, spec) != 0)
        return u->f14;
    if (u->f08 >= 7)
        u->f08 = 0;
    switch (u->f08) {
    case 0:
        n = 12;
        src = a0 + 0x08;
        break;
    case 1:
        n = 12;
        src = a0 + 0x38;
        break;
    case 2:
        n = 12;
        src = a0 + 0x68;
        break;
    case 3:
        mode = 1;
        n = 5;
        src = a0 + 0x98;
        break;
    case 4:
        mode = 1;
        n = 5;
        src = a0 + 0xAC;
        break;
    case 5:
        mode = 2;
        n = 5;
        src = a0 + 0xC0;
        break;
    case 6:
        mode = 2;
        n = 5;
        src = a0 + 0xD4;
        break;
    }
    u->f10 = mode;
    u->f14 = n;
    MI_CpuCopy8(src, spec, n * 4);
    return n;
}



















void func_021A9B00(struct Spec *spec, struct Slot14_021A87A8 *s)
{
    s16 range = spec->hi - spec->lo;
    u8 cap;
    int lvl;
    u16 id;

    MI_CpuFill8(s, 0, 0x14);
    if (range < 0)
        range = 0;
    s->f04 = spec->lo + func_021A9DC8() % (u32)(range + 1);
    id = spec->id;
    s->f00 = id;
    cap = func_02019C90(id, 0, 0x20);
    lvl = spec->lvl;
    if (lvl == 0x1F)
        s->f05 = func_02005728(cap);
    else if (lvl >= cap)
        s->f05 = 0;
    else
        s->f05 = lvl;
}



















u8 func_021A9B68(u8 *u, struct Spec *specs, u32 type)
{
    u8 buf[12];
    int i;
    int n;
    u8 t1, t2;

    n = 0;
    for (i = 0; i < u[0x14]; i++) {
        if (specs[i].lvl != 0x1F) {
            t1 = func_02019C90(specs[i].id, specs[i].lvl, 6);
            t2 = func_02019C90(specs[i].id, specs[i].lvl, 7);
            if (t1 == type || t2 == type) {
                buf[n] = i;
                n++;
            }
        }
    }
    if (n == 0)
        return 0xFF;
    return buf[func_021A9DC8() % n];
}



















/*
 * Lever: `const` on both the unit and the spec-table pointers keeps the
 * per-iteration reload of u->f14 and the image colouring; declaration order
 * i, max, base, varied.
 */
void func_021A9BE8(const struct Unit_021A9BE8 *u, const struct Spec *specs, struct Slot14_021A87A8 *s)
{
    int i;
    u8 max;
    u8 base;
    int varied;

    max = s->f04;
    base = max;
    varied = 0;
    if (u->b14 == 0)
        return;
    for (i = 0; i < u->f14; i++) {
        if (varied == 0 && specs[i].lo != specs[i].hi)
            varied = 1;
        if (s->f00 == specs[i].id && max < specs[i].hi)
            max = specs[i].hi;
    }
    if (base + 5 <= max && varied == 1)
        s->f04 += 5;
    else
        s->f04 = max;
}

















extern u32 (*const data_021D8DD8[])(u8 n);


















/*
 * Addresses are Black-image addresses.
 */
void func_021A9C58(struct Unit_021A9C58 *u, struct Spec *specs, struct Slot14_021A9C58 *s)
{
    u8 idx = 0xFF;

    if (u->b12)
        idx = func_021A9B68((u8 *)u, specs, 8);
    else if (u->b13)
        idx = func_021A9B68((u8 *)u, specs, 12);
    if (idx == 0xFF)
        idx = data_021D8DD8[u->f10](u->f14);
    func_021A9B00(&specs[idx], (struct Slot14_021A87A8 *)s);
    func_021A9BE8((const struct Unit_021A9BE8 *)u, specs, (struct Slot14_021A87A8 *)s);
}


















void func_021A9CAC(void *mon, void *src, int a, int b)
{
    u16 vals[3];
    int i;
    const u8 *w;
    u8 r;
    u8 acc;

    for (i = 0; i < 3; i++)
        vals[i] = func_0201AE1C(src, 0x11 + i);
    if (vals[0] == vals[1]) {
        func_02017E40(mon, 6, vals[0]);
        return;
    }
    w = &data_021D8DCC[(a + b * 2) * 3];
    r = func_021A9DC8();
    acc = 0;
    for (i = 0; i < 3; i++) {
        acc += w[i];
        if (r < acc) {
            func_02017E40(mon, 6, vals[i]);
            return;
        }
    }
}


















u32 func_021A9D30(struct Unit_021A9D30 *u, void *src, struct Slot14_021A9C58 *s)
{
    u32 gender = 2;
    u32 r;
    u32 x;

    if (func_0201AF6C((u8)func_0201AE1C(src, 0x14)) != 1) {
        if (u->b11) {
            if (u->f1C == 0)
                gender = 1;
            else if (u->f1C == 1)
                gender = 0;
        }
        if (s->f10 == 1)
            gender = 0;
        else if (s->f10 == 2)
            gender = 1;
    }
    r = func_020186C8(u->f20, s->f00, s->f05, gender, 2, s->f06 == 2 ? 0 : 2);
    if (s->f06 != 2) {
        x = (u16)r ^ ((u->f20 >> 16) ^ (u16)u->f20);
        if (x & 1)
            r |= 0x80000000;
        else
            r &= 0x7FFFFFFF;
    }
    return r;
}


















u32 func_021A9DC8(void)
{
    return func_0209C2B0(func_020056EC(0xFFFF), 0x290);
}


















u32 func_021A9DE0(void)
{
    u32 v = func_021A9DC8();

    if (v < 0x14) return 0;
    if (v >= 0x14 && v < 0x28) return 1;
    if (v >= 0x28 && v < 0x32) return 2;
    if (v >= 0x32 && v < 0x3C) return 3;
    if (v >= 0x3C && v < 0x46) return 4;
    if (v >= 0x46 && v < 0x50) return 5;
    if (v >= 0x50 && v < 0x55) return 6;
    if (v >= 0x55 && v < 0x5A) return 7;
    if (v >= 0x5A && v < 0x5E) return 8;
    if (v >= 0x5E && v < 0x62) return 9;
    if (v == 0x62) return 10;
    return 11;
}


















int func_021A9E64(int a)
{
    u32 v = func_021A9DC8();
    if (v < 60) {
        return 0;
    }
    if (v >= 60 && v < 90) {
        return 1;
    }
    if (v >= 90 && v < 95) {
        return 2;
    }
    if (v >= 95 && v < 99) {
        return 3;
    }
    return 4;
}


















int func_021A9E98(int a)
{
    u32 v = func_021A9DC8();
    if (v < 40) {
        return 0;
    }
    if (v < 80) {
        return 1;
    }
    if (v < 95) {
        return 2;
    }
    if (v < 99) {
        return 3;
    }
    return 4;
}


















u32 func_021A9EC4(u32 a)
{
    return func_021A9DC8() % a;
}


















u32 *func_021A9ED8(u32 a)
{
    u32 heap = func_02188C84((u8 *)a);
    u32 *p = (u32 *)func_02030734(heap, 0x14, 1, (const char *)&d_021DDFA4, 0x62);
    u32 x;
    u32 t;
    u32 q;

    p[0] = a;
    x = (u32)func_02188C80((void *)a);
    p[1] = x;
    t = (u32)func_020120F4((const struct Ctx_021A87A8 *)x);
    p[2] = t;
    p[3] = func_0216255C(func_02012844((const struct BigObj *)t));
    q = (u32)func_021AA77C(heap);
    p[4] = q;
    func_021AA7AC((u32)p, q);
    return p;
}


















/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A9F28(void *a, u32 b, u32 c, u32 d)
{
func_021AA7CC((u32)a, ((struct Obj12092 *)((u8 *)(a)))->f10, c, d);
func_021AA794((void *)((struct Obj12092 *)a)->f10);
return func_020307B0(a);
}


















int func_021A9F40(struct Ctx_021A87A8 *ctx, int mode)
{
    struct Slot14_021A9ED8 slots[2];
    struct Sel_021A9C58 sel;
    u8 loc;
    int n;
    int m;
    void *p;
    void *q;
    int skip;
    void *src;
    void *h;
    int cnt;

    skip = 0;
    src = 0;
    q = func_02188CB4(ctx->f00);
    p = (void *)func_02012A38(ctx->f08);
    if (mode == 1 || mode == 2)
        skip = 1;
    else
        func_021AA728(p, q);
    if (ctx->f0C == 0 || !ctx->f0C->b7)
        return 0;
    loc = 0;
    m = func_021AA35C((void **)ctx, mode, &loc);
    n = func_021AA3E0((struct Tab *)ctx, m, loc);
    if (m == 0xFF || n == 0)
        return 0;
    func_021A9350((struct Sel_021A8E78 *)&sel, ctx->f08, m, mode, func_021A1BF4((u8 *)func_02188C6C(ctx->f00)));
    if (!skip) {
        if (!func_021AA3FC(ctx, p, func_021A94B0((struct Obj *)(&sel), (u32)ctx->f08, n)))
            return 0;
    }
    if (mode == 1)
        func_02008DF0((void *)func_02012F2C(ctx->f08), 0x70);
    else
        src = func_021A957C(ctx->f0C, (struct Unit_021A8E78 *)((struct Unit_021A87A8 *)(&sel)), func_02188C9C(ctx->f00));
    if (src) {
        h = func_02013090(4);
        func_021AA548((struct Ctx_021AA3E0 *)((struct Ctx_021A87A8 *)ctx), &sel, h, 4, src);
    } else {
        src = 0;
        func_02082BCC(slots, 0, 0x28);
        cnt = func_021A954C(ctx->f0C, &sel, func_02188C9C(ctx->f00), slots);
        if (cnt == 0)
            return (int)src;
        if (sel.b5 && cnt == 1) {
            sel.b5 = 0;
            sel.f15 = cnt;
        }
        h = func_02013090(4);
        func_021AA490((struct Ctx_021AA3E0 *)((struct Ctx_021A87A8 *)ctx), (struct Unit_021AA3E0 *)((struct Unit_021A87A8 *)(&sel)), h, 4, (struct Slot14 *)slots);
    }
    func_021AA6F8(p, q);
    return func_0216E7C8(ctx->f04, (int)ctx->f00, (int)h, 0, mode);
}


















void func_021AA0A0(FieldEffectWork2 *s, u16 a, u8 b, u32 flags)
{
    Opts opts;
    Buf buf;
    int h;
    Opts *o;

    func_02188CB4((struct Obj00020 *)s->f0);
    func_021A9350((struct Sel_021A8E78 *)((struct Sel_021A9C58 *)(&buf)), (void *)s->f8, 0xff, 0, func_021A1BF4((u8 *)func_02188C6C((u8 *)s->f0)));
    o = &opts;
    func_02082BCC(o, 0, 0x28);
    opts.h0 = a;
    o->b4 = b;
    if (flags & 4) {
        o->h2 = 0xffff;
    }
    if (flags & 2) {
        o->b6 = 1;
    } else if (flags & 0x10) {
        o->b6 = 2;
    } else {
        o->b6 = 0;
    }
    if (flags & 8) {
        o->b7 = 1;
    }
    if (flags & 0x20) {
        o->b10 = 1;
    } else if (flags & 0x40) {
        o->b10 = 2;
    }
    h = (int)func_02013090(4);
    func_021AA490((struct Ctx_021AA3E0 *)((struct Ctx_021A87A8 *)s), (struct Unit_021AA3E0 *)((struct Unit_021A87A8 *)(&buf)), (void *)h, 4, (struct Slot14 *)((struct Slot14_021A9ED8 *)(&opts)));
    if (flags & 1) {
        func_02013144((char *)h, 4);
    } else if (flags & 0x80) {
        func_02013144((char *)h, 0x80);
    }
    if (flags & 0x100) {
        func_02013144((char *)h, 0x200);
    }
    func_0216E7C8(s->f4, s->f0, h, 1, 0);
}
















struct Obj *func_021AA180(struct Ctx_021A87A8 *ctx, int mode)
{
    struct Slot14_021A87A8 slots[2];
    struct Sel_021AA180 sel;
    int k;
    int m;
    u32 rate;
    struct Obj *h;

    if (ctx->f0C == 0 || !ctx->f0C->b7)
        return 0;
    k = 6;
    if (mode != 1)
        k = 5;
    m = func_021AA3E0((struct Tab *)ctx, k, 0);
    if (m == 0)
        return 0;
    func_021A9350((struct Sel_021A8E78 *)((void *)&sel), ctx->f08, k, mode, func_021A1BF4((u8 *)func_02188C6C(ctx->f00)));
    if (mode != 1) {
        rate = func_021A94B0((struct Obj *)(&sel), (u32)ctx->f08, m);
        if (func_021AA6E0() > rate)
            return 0;
    }
    h = 0;
    func_02082BCC(slots, 0, 0x28);
    if ((u32)func_021A954C(ctx->f0C, &sel, func_02188C9C(ctx->f00), slots) < sel.f15)
        return h;
    h = func_02013090(4);
    func_021AA490((struct Ctx_021AA3E0 *)((struct Ctx_021A87A8 *)ctx), (struct Unit_021AA3E0 *)((struct Unit_021A87A8 *)(&sel)), h, 4, (struct Slot14 *)((void *)slots));
    func_02013144((char *)h, 1);
    h->f0C = 6;
    return h;
}















/*
 * Addresses are Black-image addresses.
 */
int func_021AA248(struct Ctx_021AA248 *ctx, void *b)
{
    struct Slot14_021AA248 slots[2];
    struct Sel_021AA248 sel;
    u8 loc;
    void *q;
    void *p;
    int m;
    void *h;

    q = func_02188CB4(ctx->f00);
    p = (void *)func_02012A38(ctx->f08);
    func_021AA728(p, q);
    if (func_02193920(b) == 1) {
        return 0;
    }
    if (!func_021AA42C(p, b)) {
        return 0;
    }
    loc = 0;
    m = func_021AA35C((void **)ctx, 3, &loc);
    func_021A9350((struct Sel_021A8E78 *)&sel, ctx->f08, m, 3, func_021A1BF4((u8 *)func_02188C6C(ctx->f00)));
    func_02082BCC(slots, 0, 0x28);
    if (!func_021A9604((int)b, (struct Sel_021A94B0 *)&sel, (struct Out *)slots)) {
        return 0;
    }
    h = func_02013090(4);
    func_021AA490((struct Ctx_021AA3E0 *)((struct Ctx_021A87A8 *)ctx), (struct Unit_021AA3E0 *)((struct Unit_021A87A8 *)(&sel)), h, 4, (struct Slot14 *)((struct Slot14_021A9ED8 *)slots));
    func_021AA6F8(p, q);
    return func_0216E7C8(ctx->f04, (int)ctx->f00, (int)h, 0, 3);
}
















void func_021AA304(struct Info_021A87A8 *out, void *a1, void *a2)
{
    struct RtcTime t;
    u16 x = func_02188C9C(a2);
    void *y = func_02188CB4(a2);

    out->f00 = func_02013ED8(x);
    out->f04 = func_021AB580(func_021AB0F0(func_021A30C8(y)));
    out->f0A = x;
    func_0203F4CC(&t);
    out->f0C = t.hour;
    out->f0D = t.minute;
    out->f08 = func_021AA69C(a2);
    out->f09 = func_02012984(a1);
}
















int func_021AA35C(void **ctx, int mode, u8 *out)
{
    void *y = func_02188CB4(ctx[0]);
    u32 attr;
    u16 fl;
    u16 t;

    func_02188C98(ctx[0]);
    *out = 0;
    attr = func_021A30C8(y);
    if (func_021AB100(attr) == 0)
        return 0xFF;
    fl = func_021AB0F8(attr);
    if (mode != 1 && (fl & 4) == 0)
        return 0xFF;
    t = func_021AB0F0(attr);
    if (func_021AB140(t))
        *out += 10;
    if (fl & 2) {
        if (mode == 1)
            return 4;
        return 3;
    }
    if (mode == 1)
        return 2;
    if (func_021AB29C(t))
        return 1;
    return 0;
}
















/*
 * Addresses are Black-image addresses.
 */
int func_021AA3E0(struct Tab *t, int i, int add)
{
    int v;

    if (i >= 7)
        return 0;
    v = t->f0C[i];
    if (v > 0)
        v += add;
    if (v < 0)
        v = 0;
    return v;
}
















int func_021AA3FC(void *a0, void *p, u32 rate)
{
    u32 r;

    if (rate > 100)
        rate = 100;
    r = func_021AA778(p);
    if (r == 0)
        return 0;
    if (r == 1)
        rate = 1;
    if (func_021AA6E0() <= rate)
        return 1;
    return 0;
}
















static inline fx32 FX_MUL(fx32 v1, fx32 v2)
{
    return (fx32)(((fx64)v1 * v2 + 0x800LL) >> 12);
}
















int func_021AA42C(void *a, void *b)
{
    int n = func_021AA778(a);
    int m = func_021938F4(b);
    int rnd = func_020056EC(100);
    fx32 sq = func_0207C7B4(m << 12);
    fx32 t = FX_MUL((n - 1) << 12, sq);

    t = FX_MUL(t, 0x4000);
    return (int)func_02010FB0((int)(t >> 12)) > rnd;
}
















void func_021AA490(struct Ctx_021AA3E0 *ctx, struct Unit_021AA3E0 *u, void *a2, u16 heap, struct Slot14 *slots)
{
    struct Info_021AA3E0 info;
    void *party = func_0201A920(heap);
    void *mon = func_02030734(heap, func_020173EC(), 1, data_021DDFA4, 0x285);
    int i;

    for (i = 0; i < (u8)u->b5 + 1; i++) {
        func_021A96B8(mon, (const struct Unit_021A96B8 *)u, (struct Slot14_021A9604 *)(&slots[i]));
        func_0201A98C(party, mon);
    }
    func_021AA304((struct Info_021A87A8 *)&info, ctx->f08, ctx->f00);
    func_0201347C(a2, ctx->f08, (u32)party, (u32)(&info), u->b5, heap);
    if (u->f08 == 1)
        func_02013144(a2, 0x20);
    func_020307B0(mon);
    func_020307B0(party);
}
















void func_021AA548(struct Ctx_021AA3E0 *ctx, void *a1, void *a2, u16 heap, void *src)
{
    struct Info_021AA3E0 info;
    void *party = func_0201A920(heap);
    void *mon = func_02030734((u16)((heap & 0x7FFF) | 0x8000), func_020173EC(), 1, data_021DDFA4, 0x2A4);

    func_021A9780(mon, (const struct Unit_021A9780 *)a1, src);
    func_0201A98C(party, mon);
    func_021AA304((struct Info_021A87A8 *)&info, ctx->f08, ctx->f00);
    func_0201347C(a2, ctx->f08, (u32)party, (u32)(&info), 0, heap);
    func_02013144(a2, 8);
    func_020307B0(mon);
    func_020307B0(party);
}
















void func_021AA5CC(struct Ctx_021AA3E0 *ctx, void *a1, u32 mode, u32 flag, void *mon, u32 a5, u16 heap)
{
    struct Info_021AA3E0 info;
    void *x = ctx->f08;
    u32 r;

    func_020130C4(a1);
    func_021AA304((struct Info_021A87A8 *)&info, ctx->f08, ctx->f00);
    r = func_0202A420(func_0202A230(mon, 1));
    if (r != 0x11) {
        info.f04 = r;
    }
    switch (mode) {
    case 1:
        if (flag) {
            func_02013734(a1, (u32)x, (u32)(&info), flag, (u32)mon, a5, heap);
        } else {
            func_02013644(a1, (u32)x, (u32)(&info), (u32)mon, heap);
        }
        return;
    case 0:
        if (a5) {
            func_020136E0(a1, (u32)x, (u32)(&info), (u32)mon, a5, heap);
        } else {
            func_02013610(a1, (u32)x, (u32)(&info), (u32)mon, heap);
        }
        return;
    case 2:
        func_02013678(a1, (u32)x, (u32)(&info), (u32)mon, heap);
        return;
    case 3:
        func_020136AC(a1, (u32)x, (u32)(&info), (u32)mon, heap);
        return;
    }
}
















u8 func_021AA69C(void *p)
{
    switch (func_021A1BF4((u8 *)func_02188C6C(p))) {
    case 2:
    case 6:
    case 7:
        return 2;
    case 3:
    case 12:
        return 4;
    case 4:
    case 5:
        return 3;
    }
    return 0;
}
















u32 func_021AA6E0(void)
{
    return func_0209C2B0(func_020056EC(0xFFFF), 0x290);
}
















void func_021AA6F8(struct Pos *p, void *q)
{
    void *o = func_021A3074(q);

    MI_CpuFill8(p, 0, sizeof(*p));
    p->x = func_0216D83C(o);
    p->y = func_0216D854(o);
    p->z = func_0216D86C(o);
}
















void func_021AA728(struct Pos *p, void *q)
{
    void *o = func_021A3074(q);

    if (p->f06 != 0) {
        if (p->f08 < 0xA000)
            p->f08++;
        return;
    }
    if (p->x != func_0216D83C(o) || p->y != func_0216D854(o) || p->z != func_0216D86C(o)) {
        p->f06 = 1;
        p->f08++;
    }
}
















/*
 * Loads the 32-bit word at byte +0x8 of the object.
 */
u32 func_021AA778(u8 *p)
{
    return ((struct Obj18071 *)p)->f8;
}
















void *func_021AA77C(int heap)
{
    return func_02030734(heap, 0x5c0, 1, d_021DDFB4, 0x6e);
}
















/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AA794(void *a)
{
    func_02082BCC(a, 0, 23 << 6);
return func_020307B0(a);
}
















void func_021AA7AC(u32 a, u32 b)
{
((struct Obj09585 *)((u8 *)(b)))->f0 = func_02188CD0((u8 *)(*(u32 *)&((struct Obj07219 *)((u8 *)(a)))->f0));
func_021AA7DC((S_021AA7AC *)a, (D_021AA7AC *)b);
func_021AAB74((Self *)a, b);
}
















void func_021AA7CC(u32 a, u32 b, u32 c, u32 d)
{
func_021AAB54((FieldEffectWork5 *)a);
func_021AAFFC((FieldEffectWork6 *)b);
}















void func_021AA7DC(S_021AA7AC *s, D_021AA7AC *d)
{
    unsigned int k = s->fc->k;
    if (k > 2) {
        k = 0;
    }
    d->a = d_021D8E70[k].a;
    d->b = d_021D8E70[k].b;
}















void func_021AA80C(struct Ctx_021AA7DC *ctx)
{
    struct Enc_021A87A8 *e = ctx->f10;
    struct Entry *p = (struct Entry *)func_02012A38(ctx->f08);
    void *m;
    u16 id;
    s32 pos[3];
    int r;

    if (ctx == 0 || ctx->f0C == 0 || !ctx->f0C->b7)
        return;
    m = (void *)func_02012974(ctx->f08);
    if (ctx->f00 == 0 || m == 0)
        return;
    id = func_02188C9C(ctx->f00);
    func_0216D88C(func_021A3074(func_02188CB4(ctx->f00)), (struct VecFx32 *)pos);
    if (func_02159C48((int)m, pos[0], pos[2]) == 0)
        return;
    r = func_02159BD4((int)m, pos[0], pos[2]);
    if (id == 0xFFFF || r == 0xFFFF || id != r)
        return;
    if (func_0200C234(func_02012F08(ctx->f08), 0) == 0)
        return;
    if (func_02188CFC(ctx->f00) != 0)
        return;
    if (p->flags != 0)
        return;
    if (func_021AABC4((FieldEffectWork6 *)p, (FieldEffectWork6 *)e) == 0)
        return;
    if (func_02005728(1000) >= e->f5BA * 10) {
        func_021AABEC((u8 *)p);
        return;
    }
    func_021AACD4((void **)ctx, (struct Enc_021AACD4 *)e);
    if (e->f04 != 0)
        func_021AAE34((FieldEffectWork2 *)((struct Ctx_021AA7DC *)ctx), (R_021AAE34 *)e);
}















/*
 * Tail call with the object and the word at +0x10.
 *
 * Addresses are Black-image addresses.
 */
void func_021AA8EC(u8 *p)
{
    func_021AAFA0((FieldEffectWork6 *)p, (D_021AAFA0 *)(((struct Obj18072 *)p)->f10));
}















/*
 * Tail-call thunk: forwards to func_021AAF54 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021AA8F8(struct Self *a0)
{
    func_021AAF54((Self_021AAF54 *)a0);
}














/*
 * True when the entry behind self->+8 is live (low nibble of +0x1D) and its
 * s16 triple at +0x12/+0x14/+0x16 equals pos[0]/pos[1]/pos[2].
 */
int func_021AA900(FieldEffectWork *self, short *pos)
{
    Entry *e = (Entry *)func_02012A38(self->f08);

    if (e->flags == 0)
        return 0;
    if (e->x != pos[0] || e->z != pos[2] || e->y != pos[1])
        return 0;
    return 1;
}














static inline int same_pos(Ent_021AA900 *e, Vec3s *v)
{
    if (e->x != v->x || e->z != v->z || e->y != v->y)
        return 0;
    return 1;
}














/*
 * Addresses are Black-image addresses.
 */
int func_021AA944(Self_021AA944 *self)
{
    void *arg = self->f10;
    char *base = (char *)func_02012A38(self->obj);
    Ent_021AA900 *e = (Ent_021AA900 *)(base + 0x10);
    int flag = 0;
    Vec3s v;
    u16 r;
    int x;
    void *o;

    if (((Ent_021AA900 *)(base + 0x10))->flags == 0)
        return flag;
    func_0216D828(func_021A3074(func_02188CB4(self->ctx)), &v);
    if (!same_pos(e, &v))
        return 0;
    r = func_02005728(1000);
    if (e->b == 7) {
        if (r < 200) {
            x = func_021A9F40((struct Ctx_021A87A8 *)((struct Ctx *)self), 1);
        } else {
            x = func_021AB0AC((S_021AAFFC *)self, func_021AB070());
            flag = 1;
        }
    } else if (e->b == 4) {
        if (r < 400) {
            x = func_021A9F40((struct Ctx_021A87A8 *)((struct Ctx *)self), 1);
        } else {
            x = func_021AB0AC((S_021AAFFC *)self, func_021AB018());
            flag = 1;
        }
    } else {
        x = func_021A9F40((struct Ctx_021A87A8 *)((struct Ctx *)self), 1);
    }
    if (x == 0) {
        func_021AAFA0((FieldEffectWork6 *)((u8 *)self), (D_021AAFA0 *)((u32)arg));
        return 0;
    }
    if (flag) {
        func_021AAFA0((FieldEffectWork6 *)((u8 *)self), (D_021AAFA0 *)((u32)arg));
    } else {
        if (e->b == 5 || e->b == 6)
            func_021AAB1C((FieldEffectWork5 *)self, 1);
        e->top = 1;
        o = func_02188CB4(self->ctx);
        if (func_021A3624(o))
            func_021A3644(o);
    }
    return x;
}













int func_021AAA4C(Self *self, short *out)
{
    Ent_021AAA4C *e = (Ent_021AAA4C *)(func_02012A38(self->obj) + 0x10);
    Vec3s v;
    int a, b;

    if (e->flags == 0) {
        *out = 0;
        return 0;
    }
    func_0216D828(func_021A3074(func_02188CB4(self->ctx)), &v);
    a = (short)(e->x - v.x);
    if (a < 0)
        a = a * 0xffffffff;
    b = (short)(e->z - v.z);
    if (b < 0)
        b = b * 0xffffffff;
    if (a > b)
        *out = a;
    else
        *out = b;
    return 1;
}














void func_021AAABC(FieldEffectWork5 *s)
{
    Sub_021AAABC *b = &((T_021AAABC *)func_02012A38((const struct BigObj *)s->f8))->sub;
    if (b->lo) {
        b->hi = 1;
        if (s->f10->f5b4 != 0) {
            func_021ADB4C(s->f10->f5b4, 1);
        }
    }
}















void func_021AAAF0(FieldEffectWork5 *s, int b)
{
    T_021AAAF0 *t = (T_021AAAF0 *)func_02012A38((const struct BigObj *)s->f8);
    FieldEffectWork *d = s->f10;
    if (t->lo && d->f5b4 != 0) {
        func_021ADB4C(d->f5b4, b);
    }
}















void func_021AAB1C(FieldEffectWork5 *s, int b)
{
    T_021AAAF0 *t = (T_021AAAF0 *)func_02012A38((const struct BigObj *)s->f8);
    FieldEffectWork *d = s->f10;
    if (t->lo && d->f5b4 != 0) {
        func_021ADB5C(d->f5b4, b);
    }
}














u16 func_021AAB48(char *p)
{
    return ((struct Obj19849 *)(*(char * *)&((struct Obj19848 *)p)->f10))->f5BC;
}














void func_021AAB54(FieldEffectWork5 *s)
{
    Sub_021AAABC *b = &((T_021AAABC *)func_02012A38((const struct BigObj *)s->f8))->sub;
    if (b->lo) {
        b->mid = 1;
    }
}













void func_021AAB74(Self *self, int a)
{
    Ent_021AAB74 *e = (Ent_021AAB74 *)((u32)func_02012A38((const struct BigObj *)self->obj) + 0x10);
    unsigned short id;

    if (e->flags == 0 || e->f4 == 0)
        return;
    e->f4 = 0;
    id = func_02188C9C(self->ctx);
    if (id != e->id || e->f6 != 0)
        func_02082BCC(e, 0, 0x10);
    else
        func_021AAFC0((int)self, (D_021AAFC0 *)a, (FieldEffectWork4 *)e);
}













int func_021AABC4(FieldEffectWork6 *s, FieldEffectWork6 *d)
{
    u32 *c = &s->f0C;
    if (*c < 0xffffffff) {
        (*c)++;
    }
    if (*c >= d->f5B8) {
        return 1;
    }
    return 0;
}













/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021AABEC(u8 *p)
{
    ((struct Obj18073 *)p)->fC = 0;
}













/*
 * Addresses are Black-image addresses.
 */
void func_021AABF4(struct Ctx *ctx, void *unused, struct Area *a)
{
    void *o = func_021A3074(func_02188CB4(ctx->f00));
    const s8 *t;
    s16 x0;
    s16 x1;
    s16 y0;
    s16 y1;

    a->x = func_0216D83C(o);
    a->y = func_0216D86C(o);
    a->mx = a->x % 32;
    a->my = a->y % 32;
    a->bx = a->x / 32;
    a->by = a->y / 32;
    a->ox = a->x - a->mx;
    a->oy = a->y - a->my;
    if (ctx->f0C->lo != 2)
        t = d_021D8E76[func_02005728(4) + 1];
    else
        t = d_021D8E76[0];
    x0 = a->mx + t[0];
    if (x0 < 0)
        x0 = 0;
    x1 = a->mx + t[1];
    if (x1 >= 32)
        x1 = 31;
    y0 = a->my + t[2];
    if (y0 < 0)
        y0 = 0;
    y1 = a->my + t[3];
    if (y1 >= 32)
        y1 = 31;
    a->x0 = x0 + a->ox;
    a->x1 = x1 + a->ox;
    a->y0 = y0 + a->oy;
    a->y1 = y1 + a->oy;
}











/*
 * Addresses are Black-image addresses.
 */
void func_021AACD4(void **ctx, struct Enc_021AACD4 *e)
{
    V3 v;
    struct Area a;
    struct Cell c;
    int idx;
    int xs;
    s16 y;
    s16 x;
    u32 m;
    int r;
    int k;

    m = func_02188C98(ctx[0]);
    func_02082BCC(&e->count, 0, 0x5B0);
    v.y = 0;
    idx = func_0218D168((char *)m);
    if (func_0218DBD4((char *)m, idx) == 0)
        return;
    func_021AABF4((struct Ctx *)ctx, e, &a);
    y = a.y0;
    if ((y << 4) > 0)
        r = func_0209C95C(0x3f000000, func_0209BDBC(y << 16));
    else
        r = func_0209CB8C(func_0209BDBC(y << 16), 0x3f000000);
    v.z = func_0209C494(r) + 0x8000;
    if ((a.x0 << 4) > 0)
        r = func_0209C95C(0x3f000000, func_0209BDBC(a.x0 << 16));
    else
        r = func_0209CB8C(func_0209BDBC(a.x0 << 16), 0x3f000000);
    xs = func_0209C494(r) + 0x8000;
    for (; y <= a.y1; y++) {
        v.x = xs;
        for (x = a.x0; x <= a.x1; x++) {
            func_0218DBAC((u8 *)m, idx, (u32)(&v), (u8 *)(&c));
            k = func_021AB504(c.f08);
            if (k != 8) {
                e->spots[e->count].kind = k;
                e->spots[e->count].x = x;
                e->spots[e->count].y = y;
                e->spots[e->count++].f08 = c.f0C;
            }
            v.x += 0x10000;
        }
        v.z += 0x10000;
    }
}











void func_021AAE34(FieldEffectWork2 *s, R_021AAE34 *r)
{
    u16 k = func_02005728(r->h4);
    E_021AAE34 *e = &r->e[k];
    T_021AAABCx_021AACD4 *t = (T_021AAABCx_021AACD4 *)func_02012A38((const struct BigObj *)s->f8);
    Sub_021AAE34 *b = &t->sub;
    e->h4 = (e->f8 >> 4) / 0x1000;
    if (func_021AAEC0((Self_021AAEC0 *)s, e->h2, e->h4, e->h6, 0) == 0) {
        b->h2 = e->h2;
        b->h4 = e->h4;
        b->h6 = e->h6;
        b->f8 = e->f8;
        b->bc = e->b0;
        b->h0 = func_02188C9C((u8 *)s->f0);
        b->lo = 1;
        func_021AABEC((u8 *)t);
        func_021AAFC0((int)((Self *)s), (D_021AAFC0 *)((int)r), (FieldEffectWork4 *)((Ent_021AAB74 *)b));
    }
}














int func_021AAEC0(Self_021AAEC0 *self, s16 x, s16 y2, s16 z, int skip)
{
    Vec3s v;
    void *rec;
    unsigned long it = 0;
    void *list;
    void *cur;
    unsigned char *info;

    cur = func_021A3074(func_02188CB4(self->ctx));
    list = func_02188C7C(self->ctx);
    for (;;) {
        if (!func_0216DD1C(list, (struct Rec **)(&rec), (u32 *)(&it)))
            break;
        if (!func_0216D454(rec))
            continue;
        if (rec == cur && skip)
            continue;
        info = func_0216E3C4(rec);
        func_0216D828(rec, &v);
        if (y2 != v.y)
            continue;
        if (x < v.x || x >= v.x + info[0xb])
            continue;
        if (z > v.z || z <= v.z - info[0xc])
            continue;
        return 1;
    }
    return 0;
}














int func_021AAF54(Self_021AAF54 *self)
{
    Ent_021AAF54 *e = (Ent_021AAF54 *)(func_02012A38(self->obj) + 0x10);

    if (e->flags == 0)
        return 0;
    if (func_021AAEC0((void *)self, e->x, e->y, e->z, 1)) {
        func_021AAFA0((void *)self, self->f10);
        return 1;
    }
    return 0;
}














void func_021AAFA0(FieldEffectWork6 *s, D_021AAFA0 *d)
{
    T_021AAABCx *t = (T_021AAABCx *)func_02012A38((const struct BigObj *)s->f08);
    func_021AAFFC((void *)d);
    func_02082BCC(&t->sub, 0, 0x10);
}














void func_021AAFC0(int a, D_021AAFC0 *d, FieldEffectWork4 *r)
{
    if (d->f5b4 == 0) {
        d->f5b4 = func_021ADAAC(a, (u8 *)d->f0, r->h2, r->h6, r->f8, r->bc);
        if (d->f5b4 == 0) {
            func_02082BCC(r, 0, 0x10);
        }
    }
}
















void func_021AAFFC(FieldEffectWork6 *d)
{
    if (d->f5b4 != 0) {
        func_021AC154((Obj_021AC154 *)d->f5b4);
        d->f5b4 = 0;
    }
}
















unsigned short func_021AB018(void)
{
    unsigned short r = func_02005728(1000);

    if (r < 100)
        return d_021D8E8A[(unsigned short)(func_02005728(1000) / 100)];
    if (r < 950)
        return (unsigned short)((unsigned short)(func_02005728(1700) / 100) + 548);
    return 229;
}
















u16 func_021AB070(void)
{
    if ((u16)func_02005728(1000) < 900) {
        return (u16)(func_02005728(600) / 100) + 565;
    }
    return 571;
}
















int func_021AB0AC(S_021AAFFC *s, u16 v)
{
    s->f10->h5bc = v;
    return func_02158768(s->f4, 0x2795, 0, func_02188C84((u8 *)s->f0));
}
















/*
 * Runs the lookup func_0218DAEC into a four-word buffer and returns its third
 * word on success, -1 otherwise.
 *
 * Addresses are Black-image addresses.
 */
int func_021AB0D4(void *a, void *b)
{
    u32 buf[4];

    if (func_0218DAEC(a, b, buf) == 1)
        return buf[2];
    return -1;
}
















/*
 * Terrain-attribute accessor: the low half of the 32-bit attribute word a
 * map tile's 8-byte grid record carries at byte offset 4 (see
 * func_021D14C4, which hands that word to its caller verbatim with bit 31
 * cleared).  The low half is the terrain id; func_021AB0F8 is the matching
 * accessor for the high half, which is the flag half.
 *
 * A leaf that saves nothing, so disasm.py labels it only because a branch
 * elsewhere in ov021 targets it.
 */
u16 func_021AB0F0(u32 attr)
{
    return (u16)attr;
}


















/*
 * Terrain-attribute accessor: the high half of the tile attribute word,
 * the flag half.  bit 0 is the passable flag (func_021AB11C), bit 1 selects
 * the alternate encounter-effect set (enceff.c at 0x021CF6CE), bit 2 gates
 * the terrain-class switch in func_021AB504.
 */
u16 func_021AB0F8(u32 attr)
{
    return (u16)(attr >> 16);
}

















/*
 * The tile attribute word is present at all: neither the all-ones no-tile
 * sentinel nor the 0xFF no-terrain id in its low half.
 */
BOOL func_021AB100(u32 attr)
{
    u16 id;

    id = func_021AB0F0(attr);

    if (attr == 0xFFFFFFFF || id == 0xFF) {
        return 0;
    }

    return 1;
}

















/*
 * The walk/collision test: a tile blocks movement when its attribute word
 * is absent (func_021AB100) or when bit 0 of the flag half is set.
 */
BOOL func_021AB11C(u32 attr)
{
    u16 flags;

    flags = func_021AB0F8(attr);

    if (!func_021AB100(attr) || (flags & 1)) {
        return 1;
    }

    return 0;
}
















/*
 * Addresses are Black-image addresses.
 */
int func_021AB140(int x)
{
    if ((u16)(x + 0xFFF8) <= 1)
        return 1;
    return 0;
}
















/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x74.
 */
BOOL func_021AB158(u16 id)
{
    if (id == 0x74) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x75.
 */
BOOL func_021AB164(u16 id)
{
    if (id == 0x75) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x73.
 */
BOOL func_021AB170(u16 id)
{
    if (id == 0x73) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x72.
 */
BOOL func_021AB17C(u16 id)
{
    if (id == 0x72) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x7c.
 */
BOOL func_021AB188(u16 id)
{
    if (id == 0x7c) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0xd4.
 */
BOOL func_021AB194(u16 id)
{
    if (id == 0xd4) {
        return 1;
    }

    return 0;
}















int func_021AB1A0(int x)
{
    return x == 0xD6;
}
















/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xd7.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB1AC(u16 id)
{
    if (id == 0xd7) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xd8.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB1B8(u16 id)
{
    if (id == 0xd8) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xe2.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB1C4(u16 id)
{
    if (id == 0xe2) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xd9.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB1D0(u16 id)
{
    if (id == 0xd9) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xda.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB1DC(u16 id)
{
    if (id == 0xda) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xdb.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB1E8(u16 id)
{
    if (id == 0xdb) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xdc.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB1F4(u16 id)
{
    if (id == 0xdc) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xdd.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB200(u16 id)
{
    if (id == 0xdd) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xde.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB20C(u16 id)
{
    if (id == 0xde) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xdf.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB218(u16 id)
{
    if (id == 0xdf) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xe0.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB224(u16 id)
{
    if (id == 0xe0) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xe1.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB230(u16 id)
{
    if (id == 0xe1) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x4, 0x21, 0x5.
 */
BOOL func_021AB23C(u16 id)
{
    if (id == 0x4 || id == 0x21 || id == 0x5) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x6, 0x22, 0x7.
 */
BOOL func_021AB250(u16 id)
{
    if (id == 0x6 || id == 0x22 || id == 0x7) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x8.
 */
BOOL func_021AB264(u16 id)
{
    if (id == 0x8) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x9.
 */
BOOL func_021AB270(u16 id)
{
    if (id == 0x9) {
        return 1;
    }

    return 0;
}

















/*
 * Terrain-id predicate: the union of the two families below.
 */
BOOL func_021AB27C(u16 id)
{
    if (func_021AB23C(id) == 1 || func_021AB264(id) == 1) {
        return 1;
    }

    return 0;
}
















BOOL func_021AB29C(u16 id)
{
    if (func_021AB250(id) == 1 || func_021AB270(id) == 1) {
        return 1;
    }

    return 0;
}
















BOOL func_021AB2BC(u16 id)
{
    if (func_021AB27C(id) == 1 || func_021AB29C(id) == 1) {
        return 1;
    }

    return 0;
}















/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x1d.
 */
BOOL func_021AB2DC(u16 id)
{
    if (id == 0x1d) {
        return 1;
    }

    return 0;
}














/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x41, 0x44.
 */
BOOL func_021AB2E8(int id)
{
    if (id == 0x41 || id == 0x44) {
        return 1;
    }

    return 0;
}













/*
 * Two equality predicates.
 */
int func_021AB2F8(int x)
{
    return x == 0x14;
}
















/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x17.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB304(u16 id)
{
    if (id == 0x17) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x40.
 */
BOOL func_021AB310(u16 id)
{
    if (id == 0x40) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0xe.
 */
BOOL func_021AB31C(u16 id)
{
    if (id == 0xe) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0xf.
 */
BOOL func_021AB328(int id)
{
    if (id == 0xf) {
        return 1;
    }

    return 0;
}

















/*
 * Terrain-id predicate forwarding to func_021AB31C (id 0x0e).
 */
BOOL func_021AB334(u16 id)
{
    if (func_021AB31C(id)) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x18, 0x10.
 */
BOOL func_021AB348(u32 id)
{
    if (id == 0x18 || id == 0x10) {
        return 1;
    }

    return 0;
}















int func_021AB358(int x)
{
    return x == 0x10;
}
















/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x1c.
 */
BOOL func_021AB364(u16 id)
{
    if (id == 0x1c) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x19.
 */
BOOL func_021AB370(u16 id)
{
    if (id == 0x19) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0xc, 0xb, 0x23.
 */
BOOL func_021AB37C(u32 id)
{
    if (id == 0xc || id == 0xb || id == 0x23) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate: func_021AB370 (0x19) or func_021AB37C (0x0b, 0x0c, 0x23).
 */
BOOL func_021AB390(u16 id)
{
    if (func_021AB370(id) || func_021AB37C(id)) {
        return 1;
    }

    return 0;
}

















/*
 * Terrain-id predicate: true for id 0x3d, 0x3e, 0x3f, 0x42 and 0x43.  The
 * compiler folds the last two arms into one (u16)(id - 0x42) <= 1 range test.
 */
BOOL func_021AB3B0(u16 id)
{
    if (id == 0x3d || id == 0x3e || id == 0x3f || id == 0x42 || id == 0x43) {
        return 1;
    }

    return 0;
}














int func_021AB3D4(int x)
{
    return x == 0x2;
}















/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x1e.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB3E0(u16 id)
{
    if (id == 0x1e) {
        return 1;
    }

    return 0;
}














/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x30.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB3EC(u16 id)
{
    if (id == 0x30) {
        return 1;
    }

    return 0;
}














/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x32.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB3F8(u16 id)
{
    if (id == 0x32) {
        return 1;
    }

    return 0;
}











/*
 * Seven one-line equality predicates, one per constant.
 */
int func_021AB404(int x)
{
    return x == 0xBE;
}












int func_021AB410(int x)
{
    return x == 0xBF;
}












/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xc.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB41C(u16 id)
{
    if (id == 0xc) {
        return 1;
    }

    return 0;
}












/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x5.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB428(u16 id)
{
    if (id == 0x5) {
        return 1;
    }

    return 0;
}












/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x7.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB434(u16 id)
{
    if (id == 0x7) {
        return 1;
    }

    return 0;
}












/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x1b.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB440(u16 id)
{
    if (id == 0x1b) {
        return 1;
    }

    return 0;
}












/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x33.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB44C(u16 id)
{
    if (id == 0x33) {
        return 1;
    }

    return 0;
}











int func_021AB458(int id)
{
    if (id == 0x53 || (unsigned short)(id + 0xFFAB) <= 1)
        return 1;
    return 0;
}










int func_021AB474(int id)
{
    if (id == 0x54 || (unsigned short)(id + 0xFFA9) <= 1)
        return 1;
    return 0;
}










int func_021AB490(int id)
{
    if (id == 0x52 || id == 0x56 || id == 0x58)
        return 1;
    return 0;
}










int func_021AB4A4(int id)
{
    if (id == 0x51 || id == 0x55 || id == 0x57)
        return 1;
    return 0;
}














int func_021AB4B8(int id)
{
    if (func_021AB140(id) || func_021AB404(id) || func_021AB410(id) || func_021AB328(id))
        return 1;
    return 0;
}














/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x21.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB4EC(u16 id)
{
    if (id == 0x21) {
        return 1;
    }

    return 0;
}














/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0x22.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB4F8(u16 id)
{
    if (id == 0x22) {
        return 1;
    }

    return 0;
}














/*
 * Terrain class of a tile attribute word, for the encounter-effect lane.
 * Its one caller, func_021AACD4 in effect_encount.c, drops the tile when
 * the answer is 8 and otherwise stores the class byte in its per-tile
 * candidate list, so 8 is "no effect".  Note the flag-half gate: unless
 * bit 2 of the high half is set, every id falls through to 8, which is why
 * the overwhelmingly common 0x0081 flag half never produces a class.
 *
 * The two half accessors are func_021AB0F0/func_021AB0F8 inlined.
 */
int func_021AB504(u32 attr)
{
    u16 id = (u16)attr;
    u16 flags = (u16)(attr >> 16);

    if (id == 0x20) {
        return 7;
    }

    if (!(flags & 4)) {
        return 8;
    }

    switch (id) {
    case 4:
        return 0;
    case 5:
        return 1;
    case 0x21:
        return 2;
    case 8:
        return 3;
    case 10:
        return 4;
    case 0x3d:
        return 5;
    case 0x3f:
    case 0x43:
        return 6;
    }

    return 8;
}














/*
 * Addresses are Black-image addresses.
 */
u8 func_021AB580(u16 x)
{
    u32 i;

    for (i = 0; i < 0x25; i++) {
        if (x == data_021D8EA0[i * 2])
            return data_021D8EA1[i * 2];
    }
    return 0;
}














int func_021AB5AC(unsigned long a, unsigned long b)
{
    unsigned short lo = func_021AB0F8(b);
    unsigned short hi = func_021AB0F0(b);

    if (func_021AB11C(a))
        return 0;
    if (((lo & 2) && !func_021AB11C(b)) || func_021AB2E8(hi))
        return 1;
    return 0;
}













FieldEffectWork3 *func_021AB5F4(int heap, int a, int b)
{
    FieldEffectWork3 *p = func_02030734((u16)heap, 0x20, 1, d_021DDFC8, 0x51);
    p->f0 = a;
    p->f4 = b;
    p->f14 = -1;
    p->f18 = 1;
    return p;
}













/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021AB624(u8 *p)
{
    func_021AB650((void *)p);
    func_020307B0(p);
}













void func_021AB634(FieldEffectWork3 *s, int a, int b, int c)
{
    func_021AB650(s);
    s->f8 = a;
    s->fc = c;
    s->f10 = b;
    s->f14 = -1;
}













void func_021AB650(FieldEffectWork3 *s)
{
    s->f8 = 0;
    s->fc = 0;
    s->f10 = 0;
    s->f14 = -1;
}













/*
 * The loop's id load is spelled as byte-base + i * sizeof + 0x40: with
 * o->recs[i].f40, (o->recs + i)->f40, a Rec * local, a recs local, a
 * u16 ids[4] member or a cast through &o->recs[i], the records base and the
 * i * 0x48 product swap r3/r6 (7 bytes); int i and declaration order do
 * not move it.
 *
 * Addresses are Black-image addresses.
 */
int func_021AB660(struct Obj_021AB660 *o, void *arg)
{
    u32 i;
    int sel;

    if (o->f18 == 0)
        return -1;
    o->f1C = 0xFFFF;
    sel = -1;
    for (i = 0; i < o->count; i++) {
        if (func_021AB798((S_021AB768 *)o->f0C, *(u16 *)((u8 *)o->recs + i * sizeof(struct Rec) + 0x40), (int)o, (int)(&o->recs[i]), (int)arg))
            sel = i;
    }
    if (sel != o->cur) {
        if (o->cur != -1) {
            func_021AB7C0((S_021AB768 *)o->f0C, o->recs[o->cur].f46, (int)o, (int)(&o->recs[o->cur]), (int)arg);
            o->f1C = o->recs[o->cur].f46;
        }
        if (sel != -1) {
            func_021AB7C0((S_021AB768 *)o->f0C, o->recs[sel].f44, (int)o, (int)(&o->recs[sel]), (int)arg);
            o->f1C = o->recs[sel].f44;
        }
        o->cur = sel;
    } else if (o->cur != -1) {
        func_021AB7C0((S_021AB768 *)o->f0C, o->recs[o->cur].f42, (int)o, (int)(&o->recs[o->cur]), (int)arg);
        o->f1C = o->recs[o->cur].f42;
    }
    return o->cur;
}













/*
 * Field setter at +0x18.
 *
 * Addresses are Black-image addresses.
 */
void func_021AB75C(u8 *p, u32 v)
{
    ((struct Obj18074 *)p)->f18 = v;
}













/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021AB760(u8 *p)
{
    return ((struct Obj18075 *)p)->f0;
}













/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
u32 func_021AB764(u8 *p)
{
    return ((struct Obj18076 *)p)->f4;
}













/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AB768(u32 a, u32 b)
{
if (((struct Obj12093 *)((u8 *)(a)))->f8 > b) {
    if (*(u32 *)((u8 *)(((struct Obj12093 *)((u8 *)(a)))->f0) + ((b << 2))) != 0) {
        return 1;
    }
}
return 0;
}













int func_021AB780(u32 a, u32 b)
{
if (((struct Obj12094 *)((u8 *)(a)))->fA > b) {
    if (*(u32 *)((u8 *)(((struct Obj12094 *)((u8 *)(a)))->f4) + ((b << 2))) != 0) {
        return 1;
    }
}
return 0;
}













int func_021AB798(S_021AB768 *s, int i, int a, int b, int c)
{
    if (func_021AB768((u32)s, i)) {
        return s->f0[i](a, b, c);
    }
    return 0;
}













void func_021AB7C0(S_021AB768 *s, int i, int a, int b, int c)
{
    if (func_021AB780((u32)s, i)) {
        s->f4[i](a, b, c);
    }
}













S_021AB7E4 *func_021AB7E4(int heap)
{
    S_021AB7E4 *p = func_02030734(heap, 0x10, 1, d_021DE000, 0x81);
    int i;
    for (i = 0; i < 2; i++) {
        p->f8[i] = (int)func_020490F4(d_021D8EEC[i], heap);
    }
    return p;
}













void func_021AB81C(S_021AB7E4 *s)
{
    int i;
    func_021AB868((void *)s);
    for (i = 0; i < 2; i++) {
        func_02049238((void *)(s->f8[i]));
    }
    func_020307B0(s);
}













void func_021AB840(S_021AB840 *s, int i, int b, int d)
{
    u32 out;
    s->f0 = (int)func_0204A39C((void *)s->f8[i], b, 0, d, &out);
    s->f4 = out / 0x48;
}













void func_021AB868(S_021AB868 *s)
{
    if (s->f0 != 0) {
        func_020307B0(s->f0);
        s->f0 = 0;
        s->f4 = 0;
    }
}













u32 func_021AB880(u8 *p)
{
    return ((struct Obj18077 *)p)->f0;
}













u32 func_021AB884(u8 *p)
{
    return ((struct Obj18078 *)p)->f4;
}












void *func_021AB888(void)
{
    return (void *)0x021D8EF4;
}













static inline void VecSet(V3 *v, int x, int y, int z) { v->x = x; v->y = y; v->z = z; }













/*
 * Lever: `const Range *` together with the inline VecSet helper gives the
 * y, x, z load order of the 12-byte vector fill; either alone does not.
 */
int func_021AB890(void *self, const Range *r, V3 *ref)
{
    V3 out;
    V3 a;
    int d;
    unsigned long ang;

    VecSet(&a, r->dir.x, r->dir.y, r->dir.z);
    func_0207CA00((const V3 *)ref, (const V3 *)&a, (V3 *)&out);
    out.y = 0;
    d = func_0207CBD0((const V3 *)&out);
    func_0207CCA4((const V3 *)&out, (V3 *)&out);
    ang = func_0207CFB8(out.x, out.z);
    if (r->min <= d && r->max > d) {
        if (r->hi < r->lo) {
            if (r->hi >= ang || (ang < 0x10000 && ang >= r->lo))
                return 1;
        } else {
            if (r->lo <= ang && r->hi > ang)
                return 1;
        }
    }
    return 0;
}











static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((long long)a * b + 0x800LL) >> 12);
}











/*
 * Lever (wave A3): the position is copied field by field with its y kept in
 * the vector (`a.y = p->y`), y is saved by reading it back (`y = a.y`), and
 * a.y is zeroed before the copy of *q. The read keeps the first a.y store
 * alive and puts the zero ahead of the q copy, which gives the colouring
 * (y r7, zero r6, table r4) and lets the final a.y reload become `mov r1, r7`.
 *
 * Addresses are Black-image addresses.
 */
void func_021AB908(u32 a0, const u8 *p, const V3 *q)
{
    V3 b;
    V3 a;
    V3 n;
    V3 out;
    u32 obj;
    s32 y;
    s32 c;
    s16 t0;
    s16 t1;

    obj = func_021AB760((u8 *)a0);
    func_0218E124((u8 *)obj, 2);
    a.x = *(const s32 *)&((struct Obj04239 *)p)->f10;
    a.y = *(const s32 *)&((struct Obj04239 *)p)->f14;
    a.z = *(const s32 *)&((struct Obj04239 *)p)->f18;
    y = a.y;
    a.y = 0;
    b = *q;
    b.y = 0;
    func_0207CA00((const V3 *)&b, (const V3 *)&a, (V3 *)&b);
    func_0207CCA4((const V3 *)&b, (V3 *)&n);
    t0 = tbl_020A1B38[(*(const s32 *)&((struct Obj04239 *)p)->f1C >> 4) * 2];
    a.y = y;
    out.y = FX_Mul(t0, *(const s32 *)&((struct Obj04239 *)p)->f20);
    t1 = tbl_020A1B38[(*(const s32 *)&((struct Obj04239 *)p)->f1C >> 4) * 2 + 1];
    c = FX_Mul(t1, *(const s32 *)&((struct Obj04239 *)p)->f20);
    out.x = FX_Mul(n.x, c);
    out.z = FX_Mul(n.z, c);
    out.x += a.x;
    out.y += a.y;
    out.z += a.z;
    func_0218EC90(obj, (V3 *)&a);
    func_0218ECF4(obj, (V3 *)&out);
}













static inline void set3(V *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}












/*
 * Lever: `const S *` together with the inline set3 helper gives the y, x, z
 * load order of the two 12-byte vector fills (as in ov021_func_021AB890.c).
 */
void func_021AB9FC(int a, const FieldEffectWork5 *s)
{
    int h = func_021AB760((u8 *)a);
    V v1;
    V v0;

    func_0218E124((u8 *)h, 2);
    set3(&v1, s->f24.x, s->f24.y, s->f24.z);
    set3(&v0, s->f30.x, s->f30.y, s->f30.z);
    func_0218EC90(h, (V3 *)((void *)&v1));
    func_0218ECF4(h, (V3 *)((void *)&v0));
}













/*
 * Lever: `const u16 *r` sinks the t.z spill store below the first shift pair
 * (const on the vector source alone does not).
 */
int func_021ABA3C(int a, const u16 *r, V *v)
{
    V t;
    u16 px;
    u16 pz;
    int w;
    int h;

    if (func_02188CFC((u8 *)func_021AB764((u8 *)a)) == 1)
        return 0;
    t = *v;
    t.x -= 0x8000;
    t.z -= 0x8000;
    px = (t.x >> 12) / 16;
    pz = (t.z >> 12) / 16;
    w = r[2];
    if (w == 1) {
        w = r[4];
        h = r[3];
    } else {
        h = r[4];
    }
    if (px >= r[0] && px < r[0] + w && pz >= r[1] && pz < r[1] + h)
        return 1;
    return 0;
}













/*
 * const on p lets the three loads from p schedule above the store of t to the
 * address-taken d (docs/idioms/a-const-parameter-hoists-field-loads-above-a-
 * call-result-store-into-an-address-taken-local.md). One reused temporary v
 * keeps the quotient on the left of each add and stops x and y being
 * forward-substituted into their calls; z, the last, is.
 */
void func_021ABABC(int a0, const u16 *p, void *q)
{
    int h = func_021AB760((u8 *)a0);
    int s;
    int d;
    int t;
    int x, y, z;
    int v;

    func_0218E124((u8 *)h, 0);
    func_021ABBA0((void *)p, q, &s, &d);
    d = t = FX_Div(d, s);
    v = p[10] - p[6];
    v = v * t / 4096;
    x = v + p[6];
    v = p[11] - p[7];
    v = v * t / 4096;
    y = v + p[7];
    v = *(const int *)&((struct Obj00757 *)p)->f18 - *(const int *)&((struct Obj00757 *)p)->f10;
    v = (int)(((s64)v * t + 0x800) >> 12);
    z = v + *(const int *)&((struct Obj00757 *)p)->f10;
    func_0218ED34((u8 *)h, x);
    func_0218ED48((u8 *)h, (u16)y);
    func_0218ED58((u8 *)h, z);
}











void func_021ABB54(int a, FieldEffectWork4 *s, int c)
{
    int h = func_021AB760((u8 *)a);
    if (s->f1c != 0) {
        func_0218F0D4((u8 *)h, s->f1c);
    }
    func_021ABABC(a, (const u16 *)s, (void *)c);
}











void func_021ABB78(int a, FieldEffectWork4 *s, int c)
{
    int h = func_021AB760((u8 *)a);
    func_021ABABC(a, (const u16 *)s, (void *)c);
    if (s->f1c != 0) {
        func_0218F05C((unsigned char *)h);
    }
}











void func_021ABBA0(u16 *r, V *v, int *o1, int *o2)
{
    V t = *v;

    t.x -= 0x8000;
    t.z -= 0x8000;
    *o1 = r[4] << 16;
    if (r[2] == 1)
        *o2 = t.x - (r[0] << 16);
    else
        *o2 = t.z - (r[1] << 16);
}











void func_021ABBF0(u8 *a, u32 b, u32 c, u32 d)
{
func_021ABABC((int)a, (const u16 *)b, (void *)c);
func_021ABC5C(a, (char *)b, (void *)c);
func_021ABD08((unsigned char *)((u32)a), (const FieldEffectWork6 *)b, c);
}









/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_021ABC14(u8 *a, u32 b, u32 c, u32 d)
{
func_021ABB54((int)a, (FieldEffectWork4 *)((void *)b), c);
func_021ABC5C(a, (char *)b, (void *)c);
func_021ABD08((unsigned char *)((u32)a), (const FieldEffectWork6 *)b, c);
}









void func_021ABC38(u8 *a, u32 b, u32 c, u32 d)
{
func_021ABB78((int)a, (FieldEffectWork4 *)((void *)b), c);
func_021ABC5C(a, (char *)b, (void *)c);
func_021ABD08((unsigned char *)((u32)a), (const FieldEffectWork6 *)b, c);
}








void func_021ABC5C(u8 *a0, char *p, void *q)
{
    int a;
    int s;
    int d;
    V v;
    int dx;
    int dy;
    int dz;

    a = func_021AB760(a0);
    func_021ABBA0((u16 *)p, (V *)q, &s, &d);
    dx = ((struct Obj00757 *)p)->f30 - ((struct Obj00757 *)p)->f24;
    dy = ((struct Obj00757 *)p)->f34 - ((struct Obj00757 *)p)->f28;
    dz = ((struct Obj00757 *)p)->f2C - ((struct Obj00757 *)p)->f20;
    v.x = ((struct Obj00757 *)p)->f20 +
          sub_0207C768((int)(((long long)dz * d + 0x800) >> 12), s);
    v.y = ((struct Obj00757 *)p)->f24 + sub_0207C768((int)(((long long)dx * d + 0x800) >> 12), s);
    v.z = ((struct Obj00757 *)p)->f28 + sub_0207C768((int)(((long long)dy * d + 0x800) >> 12), s);
    func_0218ECD4(a, &v);
}









/*
 * const on s lets mwcc hoist the two field loads above the store to the
 * address-taken x (see docs/idioms/a-const-source-pointer-hoists-the-last-
 * load-of-a-struct-copy-into-an-address-taken-local.md); the assignment
 * must stay inside the multiply for the result to land in r3.
 */
void func_021ABD08(unsigned char *a, const FieldEffectWork6 *s, int c)
{
    int h = func_021AB760(a);
    int y;
    int x;
    func_021ABBA0((u16 *)s, (V *)c, &y, &x);
    func_0218ED64((u8 *)h, s->h38 + (s->h3a - s->h38) * (x = func_0207C768(x, y)) / 0x1000);
}










char *func_021ABD50(int a, int b, u16 c)
{
    char *p;
    int h;
    V v;
    u8 z;

    p = (char *)func_02030734(c, 0x28, 1, d_021DE018, 0x7e);
    ((struct Obj04240 *)p)->f0 = b;
    ((struct Obj04240 *)p)->f4 = c;
    ((struct Obj04240 *)p)->f8 = a;
    ((struct Obj04240 *)p)->fC = (int)func_020490F4(0x4b, c);
    func_02013B38(func_02188C9C((u8 *)a));
    ((struct Obj04240 *)p)->f16 = func_0202E83C(func_02188C80((void *)a));
    ((struct Obj04240 *)p)->f17 = func_020140D8((struct Sub020140BCObj *)func_02188D58((u8 *)a));
    func_021ABEAC((T_021ABEA0 *)p);
    h = func_02050080((u32 *)func_02188C88((u8 *)(((struct Obj04240 *)p)->f8)));
    func_0204EDBC((u8 *)h, 0);
    v = d_021D8F04;
    func_0204ED70((u8 *)h, (struct Blk3 *)(&v));
    z = 0;
    func_0204EDB0((u8 *)h, &z);
    return p;
}










/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021ABDE8(void *a, u32 b, u32 c, u32 d)
{
func_021ABFC0((FieldEffectWork5 *)a);
func_021ABEE8((O *)((u32)a));
func_02049238((void *)(((struct Obj02708 *)((u8 *)(a)))->fC));
return func_020307B0(a);
}










/*
 * Tail-call thunk: forwards to func_021ABFDC with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021ABE04(u32 a)
{
    func_021ABFDC((FieldEffectWork5 *)((void *)a));
}










/*
 * Tail-call thunk: forwards to func_021ABFEC with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021ABE0C(u32 a)
{
    func_021ABFEC((FieldEffectWork5 *)((void *)a));
}









/*
 * Loads the 32-bit word at byte +0x8 of the object.
 */
u32 func_021ABE14(u8 *p)
{
    return ((struct Obj18079 *)p)->f8;
}









/*
 * Tail-call thunk: the object's word at +0x8.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021ABE18(u8 *p)
{
    return func_02188CD8((u8 *)(((struct Obj18080 *)p)->f8));
}









/*
 * Loads the 32-bit word at byte +0xc of the object.
 */
u32 func_021ABE24(u8 *p)
{
    return ((struct Obj18081 *)p)->fC;
}









/*
 * Loads the byte at +0x16 of the object.
 */
u8 func_021ABE28(u8 *p)
{
    return ((struct Obj18082 *)p)->f16;
}








/*
 * Loads the byte at +0x17 of the object.
 */
u8 func_021ABE2C(u8 *p)
{
    return ((struct Obj18083 *)p)->f17;
}








void func_021ABE30(T *t, int *arr, int n)
{
    E_021ABE30 *e;
    D_021ABF48 *d;
    for (; n != 0; n--) {
        e = func_021ABF2C(t, 0x18);
        d = func_021ABF48(*arr);
        e->f0 = *arr;
        e->f4 = d->fn4(t, t->h4);
        arr++;
    }
}







void func_021ABE64(T_021ABE64 *t, int id)
{
    E_021ABE64 *e = (E_021ABE64 *)func_021ABF2C((T *)t, id);
    D_021ABF48 *d;
    if (e != 0) {
        d = func_021ABF48(id);
        d->fn8(t, e->f4);
        e->f0 = 0x18;
        e->f4 = 0;
    }
}







/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021ABE8C(T_021ABE64 *a, int id)
{
if ((E_021ABE64 *)func_021ABF2C((T *)a, id) != 0) {
    return 1;
}
return 0;
}







int func_021ABEA0(u32 a, u32 b)
{
return ((struct Obj18084 *)((u8 *)((E_021ABE64 *)func_021ABF2C((T *)((void *)a), b))))->f4;
}







void func_021ABEAC(T_021ABEA0 *t)
{
    E_021ABE30 *e;
    int i;
    e = t->f10 = func_02030734(t->h4, t->f0 * 8, 1, d_021DE018, 0x174);
    i = 0;
    if (t->f0 > 0) {
        for (; i < t->f0; i++) {
            e->f0 = 0x18;
            e++;
        }
    }
}




void func_021ABEE8(O *o)
{
    int i;
    E_021ABEE8 *e;

    i = 0;
    e = o->e;
    if (i < o->n) {
        for (; i < o->n; i++, e++) {
            if (e->kind != 0x18) {
                func_021ABF48(e->kind)->fn8(o, e->arg);
                e->kind = 0x18;
                e->arg = 0;
            }
        }
    }
    func_020307B0(o->e);
    o->e = 0;
}



E_021ABE30 *func_021ABF2C(T *t, int id)
{
    int n = t->f0;
    E_021ABE30 *e = t->f10;
    while (n != 0) {
        if (e->f0 == id) {
            return e;
        }
        n--;
        e++;
    }
    return 0;
}








D_021ABF48 *func_021ABF48(int id)
{
    int i;
    D_021ABF48 *d = d_021D8F60;
    for (i = 0; i < 0x18; i++) {
        if (d->id == id) {
            return d;
        }
        d++;
    }
    return d;
}








void func_021ABF68(FieldEffectWork5 *t, int n)
{
    t->h14 = n;
    t->f18 = func_02030734(t->h4, func_02030CB0(n), 0, d_021DE018, 0x1db);
    t->f1c = (int)func_02030CBC(n, t->f18);
    t->f20 = (int)func_021ABFFC(t->h4, t->f1c, n);
}








void func_021ABFA8(FieldEffectWork5 *t, int b, int c, int d, int e, int f)
{
    func_021AC0A0((Mgr_021AC0A0 *)t->f20, (const ObjFuncs *)b, (const V3 *)c, d, e, f);
}








void func_021ABFC0(FieldEffectWork5 *t)
{
    if (t->f20 != 0) {
        func_021AC03C((void *)t->f20);
        func_02030DA4(t->f1c);
        func_020307B0(t->f18);
    }
}








void func_021ABFDC(FieldEffectWork5 *t)
{
    if (t->f1c != 0) {
        func_02030D28((struct Ctx *)t->f1c);
    }
}








void func_021ABFEC(FieldEffectWork5 *t)
{
    if (t->f20 != 0) {
        func_021AC074((Mgr_021AC074 *)((struct Mgr *)t->f20));
    }
}








char *func_021ABFFC(u16 heap, int b, int cnt)
{
    char *p;

    p = (char *)func_02030734(heap, 0x10, 1, d_021DE018, 0x23a);
    ((struct Obj07511 *)p)->f0 = cnt;
    ((struct Obj07511 *)p)->f4 = heap;
    ((struct Obj07511 *)p)->f8 = func_02030734(heap, cnt * 0xd4, 1, d_021DE018, 0x23e);
    ((struct Obj07511 *)p)->fC = b;
    return p;
}








void func_021AC03C(U *u)
{
    u32 i;
    for (i = 0; i < u->f0; i++) {
        if (u->f8[i].f0 != 0) {
            func_021AC154((Obj_021AC154 *)(&u->f8[i]));
        }
    }
    func_020307B0(u->f8);
    func_020307B0(u);
}











void func_021AC074(Mgr_021AC074 *m)
{
    u32 i;

    for (i = 0; i < m->count; i++) {
        if (m->objs[i].active != 0)
            func_021AC18C((void *)&m->objs[i]);
    }
}











Obj_021AC0A0 *func_021AC0A0(Mgr_021AC0A0 *m, const ObjFuncs *funcs, const V3 *pos, u32 f4, u32 f8, u32 pri)
{
    u32 i = 0;
    Obj_021AC0A0 *o = m->objs;

    do {
        if (o->active == 0) {
            func_02082BCC(o, 0, sizeof(Obj_021AC0A0));
            o->active = 1;
            o->funcs = *funcs;
            o->f4 = f4;
            o->f8 = f8;
            if (pos != 0)
                o->pos = *pos;
            o->mgr = m;
            o->fd0 = func_02030DA8(m->heap, (void (*)(void))func_021AC134, o, pri);
            break;
        }
        i++;
        o++;
    } while (i < m->count);
    if (i < m->count) {
        func_021AC140((void *)o);
        return o;
    }
    return 0;
}











/*
 * Untraced thunk: forwards the second argument.
 *
 * Addresses are Black-image addresses.
 */
void func_021AC134(u32 a, u32 b)
{
    func_021AC178((void *)b);
}











void func_021AC140(Obj_021AC074 *o)
{
    if (o != 0)
        o->init(o, o->work);
}










void func_021AC154(Obj_021AC154 *o)
{
    if (o != 0) {
        o->exit(o, o->work);
        func_02030EAC(o->fd0);
        o->active = 0;
    }
}










void func_021AC178(Obj_021AC154 *o)
{
    if (o != 0)
        o->f_c4(o, o->work);
}










void func_021AC18C(Obj_021AC154 *o)
{
    if (o != 0)
        o->f_c8(o, o->work);
}










/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AC1A0(u32 a)
{
if (a != 0) {
    return ((struct Obj18085 *)((u8 *)(a)))->f4;
}
return 0;
}










int func_021AC1AC(u32 a)
{
if (a != 0) {
    return ((struct Obj18086 *)((u8 *)(a)))->f8;
}
return 0;
}










void func_021AC1B8(Obj_021AC154 *o, V3 *out)
{
    if (o != 0)
        *out = o->pos;
}










void func_021AC1CC(Obj_021AC154 *o, V3 *in)
{
    if (o != 0)
        o->pos = *in;
}










int func_021AC1E0(u32 a)
{
if (a != 0) {
    return (a + 24);
}
return 0;
}









/*
 * Setter: stores the second argument at +0x24.  Unlabelled in the listing;
 * called from func_021881D8.
 *
 * Addresses are Black-image addresses.
 */
void func_021AC1EC(u32 *p, u32 v)
{
    p[9] = v;
}









void func_021AC1F0(FieldEffectWork3 *x, void *b)
{
    Res *p;

    if (x->f24 != 0) {
        p = (Res *)func_0206E964(func_02046F48(b));
        func_02022040((u16 *)((u8 *)p + p->f38), p->h30 * 8u / 2, (const u8 *)x->f24);
    }
}









char *func_021AC218(int a, int heap)
{
    char *p;

    p = (char *)func_02030734(heap, 0x1c, 1, d_021DE028, 0x5c);
    *(int *)&((struct Obj04241 *)p)->f0 = a;
    *(V *)(p + 4) = d_021D908C;
    ((struct Obj04241 *)p)->f10 = func_02188C88((u8 *)func_021ABE14((u8 *)a));
    ((struct Obj04241 *)p)->f14 = func_02050080((u32 *)(((struct Obj04241 *)p)->f10));
    func_021AC274((struct Ctl *)p);
    return p;
}









/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021AC260(u32 a, u8 *p)
{
    func_021AC2AC(p);
    ENV_SetResourceSet(p);
}









void func_021AC274(Ctl *p)
{
    Tmpl t;

    t.res = (u32)func_02046E24(func_021ABE24((u8 *)p->f0), 0x2f);
    t.b4 = 2;
    t.b5 = 0x11;
    t.b6 = 0x10;
    t.b7 = 0x10;
    t.w8 = 1;
    p->f18 = func_020500F0((struct BbActSys *)p->f10, (const struct BbActRec *)(&t), 1);
}









/*
 * Tail call with two fields and a constant one.
 *
 * Addresses are Black-image addresses.
 */
void func_021AC2AC(u8 *p)
{
    func_02050278((struct BbActSys *)(((struct Obj12095 *)p)->f10), (u16)((struct Obj12095 *)p)->f18, 1);
}









void func_021AC2C0(u32 a, u32 b)
{
    Arg_021AC074 s;

    s.a = func_021ABEA0(b, 0);
    s.b = a;
    func_021ABFA8((FieldEffectWork5 *)b, (int)d_021D9098, 0, 0, (int)&s, 0);
}









void func_021AC2F0(u32 a, P_021AC074 *p)
{
    u32 *q = (u32 *)func_021AC1AC(a);
    Arg4 t;
    Desc s;

    p->sys = (Sys *)q[0];
    p->f8 = q[1];
    func_0216E1A4(q[1], (int)p->fc);
    s.slot = 0;
    s.v12 = 0x1000;
    s.v14 = 0x1000;
    s.k = 0x13;
    s.flag = 1;
    s.w = 1;
    {
        V3 zero = {0, 0, 0};

        s.pos = zero;
    }
    s.f1c = 0;
    s.f20 = (u32)p;
    p->f14 = func_02050340((struct BbActSys *)p->sys->f10, (u16)p->sys->f18, (const struct BbActDesc *)(&s), 1, 3);
    if (p->f14 == 0xFFFF) {
        func_021AC154((void *)a);
        return;
    }
    t.b0 = 2;
    func_0204F6DC((u8 *)p->sys->f14, p->f14, (u8 *)(&t));
    func_021AC178((void *)a);
}








void func_021AC384(u32 a, W_021AC384 *w)
{
    if (w->f14 != 0xFFFF)
        func_02050468((struct BbActSys *)w->h->f10, (u16)w->f14, 1);
}








/*
 * Addresses are Black-image addresses.
 */
void func_021AC3A4(u32 a, u32 *b)
{
    if (func_0216E1C4(b[2], (int)(b + 3)) == 0) {
        func_021AC154((void *)a);
        return;
    }
    if (func_0216D98C((int)func_0216D67C((void *)b[2])) == 0) {
        func_021AC154((void *)a);
        return;
    }
    if (func_0216DAB4((void *)b[2]) == 1 || func_0216D57C((void *)b[2], 0x8000) != 0)
        b[0] = 1;
    else
        b[0] = 0;
}








void func_021AC3F8(u32 unused, u32 *p)
{
    V3 v1;
    V3 v2;
    u32 one;
    u32 zero;
    u32 r4 = p[5];
    u8 *r6 = func_0216E3C4((void *)p[2]);
    if (p[0] == 0) {
        one = 1;
        func_0216D88C((const struct Actor *)p[2], (struct VecFx32 *)&v1);
        func_0216D92C((u8 *)p[2], (s32 *)(&v2));
        func_0207C9D0((V3 *)&v1, (V3 *)&v2, (V3 *)&v1);
        if ((u8)(r6[3] + 246) <= 1) {
            func_0216D8B0((u8 *)p[2], (u8 *)(&v2));
            if (r6[7] == 0)
                v2.y = -0x800;
            func_0207C9D0((V3 *)&v1, (V3 *)&v2, (V3 *)&v1);
        }
        func_0204F720((void *)(*(u32 *)(p[1] + 0x14)), r4, &one);
        v1.y += 0x1000;
        func_0204F638((u8 *)(*(u32 *)(p[1] + 0x14)), r4, (struct Trip *)(&v1));
    } else {
        zero = 0;
        func_0204F720((void *)(*(u32 *)(p[1] + 0x14)), r4, &zero);
    }
}








P_021AC384 *func_021AC494(u32 a, int heap)
{
    P_021AC384 *p;

    p = (P_021AC384 *)func_02030734(heap, 8, 1, d_021DE038, 0x52);
    p->f0 = a;
    func_021AC4CC((u32 *)p);
    return p;
}








void func_021AC4B8(u32 a, u8 *p)
{
    func_021AC514((u32)p);
    func_020307B0(p);
}








void func_021AC4CC(u32 *a)
{
    u32 buf[9];
    u32 r6 = func_021ABE18((u8 *)a[0]);
    u32 r4 = func_021ABE24((u8 *)a[0]);
    func_021C6AE0((u32)buf);
    func_021C6AF0((u32)buf, r4, 0x30);
    func_021C6AF8((u32 *)buf, r4);
    func_021C6AFC(buf, 0x60);
    ((struct Obj07513 *)a)->f4 = func_021C6574(r6, (u32)buf, 0);
}








int func_021AC514(u32 a)
{
    u32 b;
    u32 c;
    u32 d;
return func_021C6580(func_021ABE18((u8 *)(((struct Obj12096 *)((u8 *)(a)))->f0)), ((struct Obj12096 *)((u8 *)(a)))->f4);
}








void func_021AC528(u32 a, u32 b)
{
    V3 v;
    Arg_021AC384 s;
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&v);
    v.y += 0x1000;
    v.z += 0x6000;
    s.a = func_021ABEA0(b, 1);
    s.v = v;
    func_021ABFA8((FieldEffectWork5 *)b, (int)d_021D90AC, 0, 0, (int)((void *)&s), 0);
}






void func_021AC578(u32 a, u32 b)
{
    V3 v;
    Arg s;
    int i;
    i = func_0216D538(func_0216D67C((void *)a));
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&v);
    v.y += 0x1000;
    i = (i >> 4) * 2;
    v.z += (s32)(((long long)tbl_020A1B38[i + 1] * 0x6000 + 0x800) >> 12);
    v.x += (s32)(((long long)tbl_020A1B38[i] * 0x6000 + 0x800) >> 12);
    s.a = func_021ABEA0(b, 1);
    s.v = v;
    func_021ABFA8((FieldEffectWork5 *)b, (int)d_021D90AC, 0, 0, (int)&s, 0);
}






void func_021AC62C(u32 a, u32 *b)
{
    u32 *p = (u32 *)func_021AC1AC(a);
    b[0] = p[0];
    b[1] = func_021ABE18((u8 *)(*(u32 *)b[0]));
    func_021AC1CC((Obj_021AC154 *)a, (V3 *)(p + 1));
    ((struct Obj05038 *)b)->f8 = func_021C6590(b[1], *(u16 *)(b[0] + 4), 0, p + 1);
}




void func_021AC660(u32 a, HidObj_021AC660 *q)
{
    func_021C6628((u32)q->f4, q->f8);
}




void func_021AC66C(u32 a, X_021AC66C *x)
{
    if (func_021C6694((u32 *)x->f4, x->f8, 0x1000) == 0)
        func_021AC154((Obj_021AC154 *)a);
}




void func_021AC688(void)
{
}




P_021AC68C *func_021AC68C(int a, int heap)
{
    P_021AC68C *p;

    p = (P_021AC68C *)func_02030734(heap, 0x18, 1, d_021DE070, 0x6c);
    p->f0 = a;
    p->f4 = func_02188C90((u8 *)func_021ABE14((u8 *)a));
    func_021AC6D4((u32 *)p);
    return p;
}





/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021AC6C0(u32 a, u8 *p)
{
    func_021AC740((struct X *)p);
    func_020307B0(p);
}





/*
 * Addresses are Black-image addresses.
 */
void func_021AC6D4(u32 *p)
{
    Arg_021AC6D4 s;
    int i;
    u32 r7 = func_021ABE24((u8 *)p[0]);
    u16 *t;
    u32 lv;
    func_02188C80((void *)func_021ABE14((u8 *)p[0]));
    lv = func_021ABE28((u8 *)p[0]);
    s.b4 = 0;
    s.b5 = 0x24;
    s.b6 = 0x20;
    s.b7 = 0x20;
    s.c = 1;
    t = d_021D911C + lv;
    for (i = 0; i < 8; i++) {
        s.a = (u32)func_02046E24(r7, t[i * 4]);
        func_021AC1F0((FieldEffectWork3 *)((struct X *)p[0]), (void *)s.a);
        ((u16 *)p)[4 + i] = func_020500F0((struct BbActSys *)p[1], (const struct BbActRec *)(&s), 1);
    }
}





void func_021AC740(X *x)
{
    int i;

    for (i = 0; i < 8; i++)
        func_02050278((struct BbActSys *)x->f4, x->h[i], 1);
}





/*
 * The v.z -= 0x2000 adjust is written in both arms of the if; the
 * compiler tail-merges the arms and keeps the 2 of 0x2000 in r6
 * (docs/idioms/a-constant-shifted-in-a-merged-tail-is-a-statement-repeated-in-each-arm.md).
 */
void func_021AC760(u32 a, u32 b, u32 c, int d)
{
    V3 v;
    Arg_021AC760 s;
    int tmp;

    if (d >= 8)
        return;
    s.f0 = func_021ABEA0(a, 2);
    s.f4 = b;
    s.f20 = d;
    s.h10 = func_0216D588((void *)b);
    s.h12 = func_0216D590((void *)b);
    s.f8 = func_0216D83C((void *)b);
    s.fc = func_0216D86C((void *)b);
    func_02164280((s16)s.f8, (s16)s.fc, (int *)(&v));
    v.y = func_0216D8AC((void *)b);
    if (func_0216D55C(b, 0x2000) != 0) {
        v.y += 7 * 0x1000;
        v.z -= 0x2000;
    } else {
        func_02163E58(b, &v, &tmp);
        v.y = tmp + 9 * 0x1000;
        v.z -= 0x2000;
    }
    s.pos = v;
    func_021ABFA8((FieldEffectWork5 *)a, (int)d_021D90EC, 0, c, (int)&s, 0);
}
