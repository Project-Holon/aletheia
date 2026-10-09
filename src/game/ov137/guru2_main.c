/*
 * file:     guru2_main.c
 * unit:     yes
 * function: func_021DD1E0, func_021DD2E0, func_021DD380, func_021DD3B0, func_021DD3D8, func_021DD4A8, func_021DD570, func_021DD5AC, func_021DD638, func_021DD700, func_021DD760, func_021DD79C, func_021DD7E4, func_021DD80C, func_021DD924, func_021DD928, func_021DD93C, func_021DD94C, func_021DD970, func_021DD99C, func_021DD9D4, func_021DDAEC, func_021DDB04, func_021DDB90, func_021DDBB0, func_021DDBE8, func_021DDC7C, func_021DDCB4, func_021DDCEC, func_021DDD0C, func_021DDD48, func_021DDD80, func_021DDE24, func_021DDE74, func_021DDE94, func_021DDEDC, func_021DDF38, func_021DDF64, func_021DDF84, func_021DDFC0, func_021DDFFC, func_021DE060, func_021DE08C, func_021DE17C, func_021DE220, func_021DE248, func_021DE350, func_021DE354, func_021DE37C, func_021DE388, func_021DE4B4, func_021DE55C, func_021DE5C0, func_021DE5D0, func_021DE6C0, func_021DE6DC, func_021DE6EC, func_021DE738, func_021DE7F4, func_021DE7FC, func_021DE960, func_021DEA0C, func_021DEA68, func_021DEA70, func_021DEA84, func_021DEAC8, func_021DEAE0, func_021DEB10, func_021DEB1C, func_021DEB40, func_021DEB74, func_021DEC08, func_021DEC38, func_021DEC64, func_021DEC84, func_021DECB0, func_021DECCC, func_021DECF4, func_021DED3C, func_021DED88, func_021DEDAC, func_021DEE4C, func_021DEED8, func_021DEF14, func_021DEF3C, func_021DEF6C, func_021DEFB4, func_021DEFD0, func_021DEFE8, func_021DF004, func_021DF01C, func_021DF050, func_021DF060, func_021DF1C4, func_021DF204, func_021DF22C, func_021DF2A0, func_021DF2B8, func_021DF2E0, func_021DF370, func_021DF3E8, func_021DF434, func_021DF488, func_021DF4AC, func_021DF548, func_021DF56C, func_021DF5B0, func_021DF5EC, func_021DF648, func_021DF6A4, func_021DF6B8, func_021DF6D4, func_021DF6FC, func_021DF778, func_021DF7A4, func_021DF7CC, func_021DF7E8, func_021DF800, func_021DF83C, func_021DF864, func_021DF984, func_021DF998, func_021DFA14, func_021DFA68, func_021DFAD8, func_021DFB60, func_021DFC74, func_021DFE40, func_021DFE6C, func_021DFEA0, func_021DFEB8, func_021DFEC4, func_021DFEFC, func_021DFF20, func_021DFF44, func_021DFF70, func_021DFFC8, func_021DFFF8, func_021E00D4, func_021E0130, func_021E01B0, func_021E026C, func_021E0304, func_021E0338, func_021E03A0, func_021E03D8, func_021E0450, func_021E0478, func_021E04B4, func_021E04C4, func_021E04E0, func_021E0554, func_021E0570, func_021E05D4, func_021E0634, func_021E0640, func_021E0678, func_021E0698, func_021E06E0, func_021E073C, func_021E078C, func_021E07A4, func_021E0848, func_021E0980, func_021E09C0, func_021E0A44, func_021E0B14, func_021E0B38, func_021E0BA4, func_021E0BC0, func_021E0C08, func_021E0C70, func_021E0CA4, func_021E0CCC, func_021E0D0C, func_021E0D50, func_021E0DC0, func_021E0DE8, func_021E0E1C, func_021E0E2C, func_021E0E50, func_021E0EAC, func_021E0EFC, func_021E0F20, func_021E0F54, func_021E0F64, func_021E0FAC, func_021E1028, func_021E104C, func_021E1080, func_021E1090, func_021E10D8, func_021E11B4, func_021E11E4, func_021E11F4, func_021E1204, func_021E1210, func_021E121C, func_021E129C, func_021E1320, func_021E13BC, func_021E13F0, func_021E1400, func_021E140C, func_021E141C, func_021E1468, func_021E1488, func_021E14BC, func_021E14CC, func_021E14E4, func_021E1540, func_021E1584, func_021E15DC, func_021E1604, func_021E161C, func_021E1634, func_021E168C, func_021E1694, func_021E16AC, func_021E16C0, func_021E16C4, func_021E16D8, func_021E170C, func_021E172C, func_021E1758, func_021E1768, func_021E1784, func_021E17EC, func_021E180C, func_021E1814, func_021E1830, func_021E18CC, func_021E1910, func_021E1954, func_021E1974, func_021E1988, func_021E19A4
 * address:  0x021DD1E0
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   d_021E1B70 0x021E1B70 data a4
 *   d_021E1BE0 0x021E1BE0 data a4
 *   d_021E1B80 0x021E1B80 data a4
 *   d_021E1BA0 0x021E1BA0 data a4
 *   d_021E1BC0 0x021E1BC0 data a4
 *   d_021E1C00 0x021E1C00 data a4
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02049F78 0x02049F78 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02045808 0x02045808 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02049238 0x02049238 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02045088 0x02045088 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0201FEF4 0x0201FEF4 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 *   func_02039338 0x02039338 arm
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   func_021841A4 0x021841A4 thumb ov022
 *   func_02184114 0x02184114 thumb ov022
 *   func_02184134 0x02184134 thumb ov022
 *   func_020061E4 0x020061E4 thumb
 *   func_0201FDA0 0x0201FDA0 thumb
 *   d_021E1AE8 0x021E1AE8 data a2
 *   func_0201FEBC 0x0201FEBC thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 *   func_0203D7BC 0x0203D7BC arm
 *   func_0202208C 0x0202208C thumb
 *   func_02184180 0x02184180 thumb ov022
 *   func_0201F02C 0x0201F02C thumb
 *   func_020399A8 0x020399A8 arm
 *   func_0203A424 0x0203A424 arm
 *   func_02039CB4 0x02039CB4 arm
 *   sub_02039338 0x02039338 arm
 *   func_0201CE0C 0x0201CE0C thumb
 *   func_02008534 0x02008534 thumb
 *   func_02008500 0x02008500 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_021841A0 0x021841A0 thumb ov022
 *   func_02008530 0x02008530 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0203630C 0x0203630C arm
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_020362DC 0x020362DC arm
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_02008550 0x02008550 thumb
 *   func_02008554 0x02008554 thumb
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02049F34 0x02049F34 arm
 *   d_021E1AF8 0x021E1AF8 data a1
 *   func_0207E51C 0x0207E51C arm
 *   func_02049E34 0x02049E34 arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02012934 0x02012934 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_02047CFC 0x02047CFC arm
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030734 0x02030734 arm
 *   func_02030CBC 0x02030CBC arm
 *   d_021E1FA0 0x021E1FA0 data a2
 *   d_021E22B8 0x021E22B8 data a1
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0202F038 0x0202F038 thumb
 *   func_02030DA4 0x02030DA4 arm
 *   func_02047E54 0x02047E54 arm
 *   func_02046788 0x02046788 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_020351A0 0x020351A0 arm
 *   d_021E217C 0x021E217C data a4
 *   func_02030D28 0x02030D28 arm
 *   func_02039C68 0x02039C68 arm
 *   func_0203D4D0 0x0203D4D0 arm
 *   d_021E1FDC 0x021E1FDC data a2
 *   func_0200ED48 0x0200ED48 thumb
 *   func_021E19C0 0x021E19C0 thumb ov137
 *   func_020056EC 0x020056EC thumb
 *   func_0201292C 0x0201292C thumb
 *   func_02007E50 0x02007E50 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021E1F34 0x021E1F34 data a4
 *   func_02008DF0 0x02008DF0 thumb
 *   func_0203516C 0x0203516C arm
 *   func_0201088C 0x0201088C thumb
 *   func_0202EE30 0x0202EE30 thumb
 *   func_02010904 0x02010904 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FBB0 0x0200FBB0 thumb
 *   func_0200F7B8 0x0200F7B8 thumb
 *   func_0202223C 0x0202223C thumb
 *   func_02010934 0x02010934 thumb
 *   func_0203A5E4 0x0203A5E4 arm
 *   func_02184174 0x02184174 thumb ov022
 *   func_0218417C 0x0218417C thumb ov022
 *   func_020221A4 0x020221A4 thumb
 *   func_02021D50 0x02021D50 thumb
 *   func_0204A648 0x0204A648 arm
 *   func_020419E4 0x020419E4 arm
 *   func_02048B6C 0x02048B6C arm
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_020479D8 0x020479D8 arm
 *   func_0206AA3C 0x0206AA3C arm
 *   func_0206AA78 0x0206AA78 arm
 *   func_0206AA8C 0x0206AA8C arm
 *   func_0206AAB0 0x0206AAB0 arm
 *   func_02047970 0x02047970 arm
 *   func_0204A600 0x0204A600 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_0202F0B0 0x0202F0B0 thumb
 *   func_020433E0 0x020433E0 arm
 *   d_021E1EA4 0x021E1EA4 data a4
 *   func_02040588 0x02040588 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   func_0207DD24 0x0207DD24 arm
 *   d_021E1D90 0x021E1D90 data a2
 *   func_02046440 0x02046440 arm
 *   func_02046BE0 0x02046BE0 arm
 *   func_02048A24 0x02048A24 arm
 *   d_021E2020 0x021E2020 data a4
 *   d_020A1EB8 0x020A1EB8 data a2
 *   d_021E1D00 0x021E1D00 data a4
 *   d_021E1D0C 0x021E1D0C data a4
 *   func_0203F8F4 0x0203F8F4 arm
 *   d_021E202C 0x021E202C data a4
 *   d_021E204C 0x021E204C data a4
 *   d_021E206C 0x021E206C data a4
 *   d_021E208C 0x021E208C data a4
 *   d_021E20AC 0x021E20AC data a4
 *   d_021E20CC 0x021E20CC data a4
 *   func_02062A98 0x02062A98 arm
 *   func_020215BC 0x020215BC thumb
 *   func_02022004 0x02022004 thumb
 *   func_02062A00 0x02062A00 arm
 *   func_02040B1C 0x02040B1C arm
 *   func_02062B30 0x02062B30 arm
 *   func_02040AE0 0x02040AE0 arm
 *   func_02021518 0x02021518 thumb
 *   func_02021EE4 0x02021EE4 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   d_020A1448 0x020A1448 data a4
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02021640 0x02021640 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02041B6C 0x02041B6C arm
 *   func_0201EF40 0x0201EF40 thumb
 *   d_021E1E30 0x021E1E30 data a4
 *   func_02048AC4 0x02048AC4 arm
 *   func_02035C08 0x02035C08 arm
 *   d_021E1CB0 0x021E1CB0 data a4
 *   func_02047E88 0x02047E88 arm
 *   d_021E20EC 0x021E20EC data a4
 *   d_021E1DE8 0x021E1DE8 data a4
 *   func_020480E4 0x020480E4 arm
 *   func_02048A18 0x02048A18 arm
 *   func_020520FC 0x020520FC arm
 *   func_02047A60 0x02047A60 arm
 *   d_021E1D80 0x021E1D80 data a4
 *   d_021E1E60 0x021E1E60 data a4
 *   d_021E1E70 0x021E1E70 data a4
 *   d_021E212C 0x021E212C data a4
 *   func_0207ADC4 0x0207ADC4 arm
 *   d_020A1B38 0x020A1B38 data a2
 *   func_0203F63C 0x0203F63C arm
 *   func_0203F5FC 0x0203F5FC arm
 *   func_02047910 0x02047910 arm
 *   func_02030DA8 0x02030DA8 arm
 *   d_021E1CB8 0x021E1CB8 data a4
 *   d_021E203C 0x021E203C data a4
 *   func_0204B8D4 0x0204B8D4 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B294 0x0204B294 arm
 *   d_021E2278 0x021E2278 data a4
 *   d_021E2018 0x021E2018 data a4
 *   func_020493D4 0x020493D4 arm
 *   func_0204932C 0x0204932C arm
 *   func_021DCE00 0x021DCE00 thumb ov137
 *   func_0201AB28 0x0201AB28 thumb
 *   func_0202F190 0x0202F190 thumb
 *   func_02019CE0 0x02019CE0 thumb
 *   d_021E1F04 0x021E1F04 data a4
 *   func_0201AA18 0x0201AA18 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_02005F38 0x02005F38 thumb
 *   func_02005E9C 0x02005E9C thumb
 */
#include "../../matched/include/Obj02495.h"
#include "../../matched/include/Obj23712.h"
#include "../../matched/include/Obj08210.h"
#include "../../matched/include/Obj10616.h"
#include "../../matched/include/Obj14207.h"
#include "../../matched/include/Obj14208.h"
#include "../../matched/include/Obj00170.h"
#include "../../matched/include/Obj05425.h"
#include "../../matched/include/Obj06534.h"
#include "../../matched/include/Obj08211.h"
#include "../../matched/include/Obj23713.h"
#include "../../matched/include/Obj23714.h"
#include "../../matched/include/Obj23715.h"
#include "../../matched/include/Obj01414.h"
#include "../../matched/include/Obj14209.h"
#include "../../matched/include/Obj23716.h"
#include "../../matched/include/Obj14210.h"
#include "../../matched/include/Obj02867.h"
#include "../../matched/include/Obj23717.h"
#include "../../matched/include/Obj23718.h"
#include "../../matched/include/Obj23719.h"
#include "../../matched/include/Obj03303.h"
#include "../../matched/include/Obj23720.h"
#include "../../matched/include/Obj23721.h"
#include "../../matched/include/Obj23722.h"
#include "../../matched/include/Obj14211.h"
#include "../../matched/include/Obj05426.h"
#include "../../matched/include/Obj14212.h"
#include "../../matched/include/Obj10617.h"
#include "../../matched/include/Obj14213.h"
#include "../../matched/include/Obj23723.h"
#include "../../matched/include/Obj23724.h"
#include "../../matched/include/Obj14214.h"
#include "../../matched/include/Obj04538.h"
#include "../../matched/include/Obj14215.h"
#include "../../matched/include/Obj14216.h"
#include "../../matched/include/Obj14217.h"
#include "../../matched/include/Obj08212.h"
#include "../../matched/include/Obj14218.h"
#include "../../matched/include/Obj23725.h"
#include "../../matched/include/Obj23726.h"
#include "../../matched/include/Obj06535.h"
#include "../../matched/include/Obj03840.h"
#include "../../matched/include/Obj23727.h"
#include "../../matched/include/Obj01261.h"
#include "../../matched/include/Obj23728.h"
#include "../../matched/include/Obj02868.h"
#include "../../matched/include/Obj23729.h"
#include "../../matched/include/Obj23730.h"
#include "../../matched/include/Obj23731.h"
#include "../../matched/include/Obj23732.h"
#include "../../matched/include/Obj23733.h"
#include "../../matched/include/Obj05428.h"
#include "../../matched/include/Obj23734.h"
#include "../../matched/include/Obj23735.h"
#include "../../matched/include/Obj23736.h"
#include "../../matched/include/Obj23737.h"
#include "../../matched/include/Obj23738.h"
#include "../../matched/include/Obj02208.h"
#include "../../matched/include/Obj08213.h"
#include "../../matched/include/Obj23739.h"
#include "../../matched/include/Obj23740.h"
#include "../../matched/include/Obj23741.h"
#include "../../matched/include/Obj23742.h"
#include "../../matched/include/Obj14219.h"
#include "../../matched/include/Obj23743.h"
#include "../../matched/include/Obj08214.h"
#include "../../matched/include/Obj10637.h"
#include "../../matched/include/Obj14220.h"
#include "../../matched/include/Obj01753.h"
#include "../../matched/include/Obj23744.h"
#include "../../matched/include/Obj02496.h"
#include "../../matched/include/Obj23746.h"
#include "../../matched/include/Obj14221.h"
#include "../../matched/include/Obj10618.h"
#include "../../matched/include/Obj10619.h"
#include "../../matched/include/Obj23747.h"
#include "../../matched/include/Obj10620.h"
#include "../../matched/include/Obj03304.h"
#include "../../matched/include/Obj06536.h"
#include "../../matched/include/Obj02869.h"
#include "../../matched/include/Obj08215.h"
#include "../../matched/include/Obj23748.h"
#include "../../matched/include/Obj23749.h"
#include "../../matched/include/Obj06537.h"
#include "../../matched/include/Obj14222.h"
#include "../../matched/include/Obj08216.h"
#include "../../matched/include/Obj14223.h"
#include "../../matched/include/Obj10621.h"
#include "../../matched/include/Obj23750.h"
#include "../../matched/include/Obj23751.h"
#include "../../matched/include/Obj02209.h"
#include "../../matched/include/Obj06538.h"
#include "../../matched/include/Obj23754.h"
#include "../../matched/include/Obj01415.h"
#include "../../matched/include/Obj05429.h"
#include "../../matched/include/Obj23755.h"
#include "../../matched/include/Obj23756.h"
#include "../../matched/include/Obj04542.h"
#include "../../matched/include/Obj23757.h"
#include "../../matched/include/Obj02497.h"
#include "../../matched/include/Obj14225.h"
#include "../../matched/include/Obj04539.h"
#include "../../matched/include/Obj10622.h"
#include "../../matched/include/Obj06540.h"
#include "../../matched/include/Obj06541.h"
#include "../../matched/include/Obj08217.h"
#include "../../matched/include/Obj05430.h"
#include "../../matched/include/Obj23759.h"
#include "../../matched/include/Obj23760.h"
#include "../../matched/include/Obj08218.h"
#include "../../matched/include/Obj08219.h"
#include "../../matched/include/Obj08220.h"
#include "../../matched/include/Obj14226.h"
#include "../../matched/include/Obj23761.h"
#include "../../matched/include/Obj23762.h"
#include "../../matched/include/Obj05431.h"
#include "../../matched/include/Obj23763.h"
#include "../../matched/include/Obj10623.h"
#include "../../matched/include/Obj14227.h"
#include "../../matched/include/Obj03305.h"
#include "../../matched/include/Obj10624.h"
#include "../../matched/include/Obj23766.h"
#include "../../matched/include/Obj14228.h"
#include "../../matched/include/Obj00835.h"
#include "../../matched/include/Obj02870.h"
#include "../../matched/include/Obj23767.h"
#include "../../matched/include/Obj23768.h"
#include "../../matched/include/Obj23769.h"
#include "../../matched/include/Obj23770.h"
#include "../../matched/include/Obj03842.h"
#include "../../matched/include/Obj23771.h"
#include "../../matched/include/Obj03306.h"
#include "../../matched/include/Obj23772.h"
#include "../../matched/include/Obj05432.h"
#include "../../matched/include/Obj03843.h"
#include "../../matched/include/Obj02498.h"
#include "../../matched/include/Obj02871.h"
#include "../../matched/include/Obj23773.h"
#include "../../matched/include/Obj14230.h"
#include "../../matched/include/Obj23774.h"
#include "../../matched/include/Obj14231.h"
#include "../../matched/include/Obj02499.h"
#include "../../matched/include/Obj10625.h"
#include "../../matched/include/Obj23775.h"
#include "../../matched/include/Obj14232.h"
#include "../../matched/include/Obj01754.h"
#include "../../matched/include/Obj14233.h"
#include "../../matched/include/Obj02872.h"
#include "../../matched/include/Obj23776.h"
#include "../../matched/include/Obj14234.h"
#include "../../matched/include/Obj14235.h"
#include "../../matched/include/Obj10628.h"
#include "../../matched/include/Obj14236.h"
#include "../../matched/include/Obj10629.h"
#include "../../matched/include/Obj14237.h"
#include "../../matched/include/Obj23777.h"
#include "../../matched/include/Obj08221.h"
#include "../../matched/include/Obj02873.h"
#include "../../matched/include/Obj02874.h"
#include "../../matched/include/Obj08222.h"
#include "../../matched/include/Obj08223.h"
#include "../../matched/include/Obj14238.h"
#include "../../matched/include/Obj23778.h"
#include "../../matched/include/Obj23779.h"
#include "../../matched/include/Obj01555.h"
#include "../../matched/include/Obj23780.h"
#include "../../matched/include/Obj23781.h"
#include "../../matched/include/Obj23782.h"
#include "../../matched/include/Obj23783.h"
#include "../../matched/include/Obj14239.h"
#include "../../matched/include/Obj23784.h"
#include "../../matched/include/Obj14240.h"
#include "../../matched/include/Obj23785.h"
#include "../../matched/include/Obj23786.h"
#include "../../matched/include/Obj08224.h"
#include "../../matched/include/Obj08225.h"
#include "../../matched/include/Obj14243.h"
#include "../../matched/include/Obj23787.h"
#include "../../matched/include/Obj23788.h"
#include "../../matched/include/Obj23790.h"
#include "../../matched/include/Obj14244.h"
#include "../../matched/include/Obj23791.h"
#include "../../matched/include/Obj14245.h"
#include "../../matched/include/Obj23793.h"
#include "../../matched/include/Obj04541.h"
#include "../../matched/include/Obj14246.h"
#include "../../matched/include/Obj23794.h"
#include "../../matched/include/Obj14247.h"
#include "../../matched/include/Obj23795.h"
#include "../../matched/include/Obj23796.h"
#include "../../matched/include/Obj14248.h"
#include "../../matched/include/Obj23797.h"
#include "../../matched/include/Obj23798.h"
#include "../../matched/include/Obj14249.h"
#include "../../matched/include/Obj14250.h"
#include "../../matched/include/Obj23799.h"
#include "../../matched/include/Obj14251.h"
#include "../../matched/include/Obj23800.h"
#include "../../matched/include/Obj10636.h"
#include "../../matched/include/Obj14254.h"
#include "../../matched/include/Obj23802.h"
#include "../../matched/include/Obj23803.h"
#include "../../matched/include/Obj23806.h"
#include "../../matched/include/Obj06543.h"
#include "../../matched/include/Obj23807.h"
#include "../../matched/include/Obj23808.h"
#include "../../matched/include/Obj14255.h"
#include "../../matched/include/Obj23809.h"
#include "../../matched/include/Obj23810.h"
#include "../../matched/include/Obj23811.h"
#include "../../matched/include/Obj23812.h"

#define DISP3D (*(volatile u16 *)0x04000060)
struct MsgBank;
struct U16Vec;
struct Bank;
struct Cfg;
struct Sub0200852CObj;
struct Obj_021DD1E0;
struct CharBuf;
struct Descriptor;
struct StrObj;
struct BmpMenu;
struct WordSet;
struct Entry;
struct Link;
struct Rec3;
struct Rec;
struct Sub0204A9D0;
struct Obj0203159C;
struct BigObj;
struct Ctx;
struct PrintSys;
struct S020315D4;
struct Node;
struct Big;
struct L0200ED54;
struct Sub02008C20Obj;
struct Sub0201088CObj;
struct S02021D50;
struct Light;
struct DispVram;
struct NitroFileHeader;
struct PalAnmSlot;
struct Util;
struct Setup;
struct GfFont;
struct Arg;
struct Mtx33;
struct Actor;
struct Obj;
struct ArcFile;
struct RecDC;
typedef unsigned int u32;

struct DispConfig_021DD1E0 { u32 w[4]; };

struct BgTemplate_021DD1E0 { u32 w[8]; };

typedef unsigned short u16;

typedef unsigned char  u8;

typedef signed short s16_021DD1E0;

typedef signed char s8;

typedef signed int s32;

typedef struct {u8 frame,x,y,pal;u16 chr;} WinDat;

typedef struct { void *current; void *previous; } Entry;

typedef struct { char pad[0x38]; void *font; void *formatter; void *bank; void *names[5]; char pad58[0xe0]; Entry entries[5]; } Context;

typedef unsigned long long u64;

typedef union { struct { u32 a,b; } words; u64 wide; } Pair_021DD1E0;

typedef struct { char pad[0x4824]; Pair_021DD1E0 current,previous; } Record_021DD1E0;

typedef struct { u8 pad[0x4804]; volatile int previous; } Obj_021DD1E0;

typedef struct { u8 pad[0x90]; void *slots[5]; void *other[5]; } Obj_021DED88;

typedef struct {int a,b;u16 values[5];u16 flag;} Msg;

typedef struct {u8 pad[28]; int angle;} Selected;

typedef struct { int state; u8 pad[36]; Selected *selected; int index, count; } Obj_021DF22C;

typedef struct { u8 pad[0x60]; u16 angles[5]; } Obj_021DF2E0;

struct Range_021DD1E0 { u32 low, high; };

typedef enum { GX_SHADING_TOON = 0, GX_SHADING_HIGHLIGHT = 1 } GXShading;

typedef short s16_021DEFD0;

typedef struct { u32 x, y, z; } Vec3;

struct DispConfig_021DEFD0 {u32 w[4];};

struct BgTemplate_021DEFD0 {u32 w[8];};

typedef struct { u32 layer; u8 a,b,c,d; u16 e,pad; } Desc;

typedef struct { int x,y,z; } Vec;

typedef struct { int a[4]; } Descriptor;

typedef struct { int m[9]; } Mtx;

typedef struct { Vec pos,scale; Mtx rot; } Transform;

typedef enum { COUNT_ZERO=0, COUNT_NEGATIVE=-1 } Count;

typedef struct { int active; char rest[0xb0]; } RecordA;

typedef struct { int active; char rest[0x78]; } RecordB;

typedef struct { int active; char rest[0x64]; } RecordC;

typedef struct {
    char pad[0x140];
    RecordA a[5];
    RecordB b[5];
    RecordC c[5];
} Block_021E073C;

typedef enum {INDEX_ZERO=0} Index;

typedef signed short   s16;

typedef struct {u8 pad[0x2c]; int index,count;} Obj;

typedef struct { int active; char rest[0xb0]; } Record_021E073C;

typedef struct { char pad[0x140]; Record_021E073C records[1]; } Block_021E0E1C;

typedef struct { int active, state, x, y, key; } Entry_021E0F64;

typedef struct { int active, state, x, y, z, key; } Entry_021E1090;

typedef struct {unsigned state;int active,other,timer,speed;} State_021E073C;

typedef struct { int v[4]; } Table;

typedef struct { u16 state, flag; int count; } State_021E1320;

typedef struct
{
  int active;
  int a;
  int b;
  int key;
  char rest[0xa4];
} Record_021E14E4;

typedef struct
{
  char pad[0x140];
  Record_021E14E4 records[1];
} Block;

typedef struct { int a, b; } Pair_021E073C;

typedef struct { int a, b, c, d, e; } Record_021E1694;

struct Range_021E073C { u16 lo, hi; };

struct Entry { unsigned count; struct Range_021E073C *ranges; };

extern void func_0203FC28(struct DispConfig_021DD1E0 *);
extern void func_0203FCA0(u32,const struct BgTemplate_021DD1E0 *,u32);
extern void func_020414EC(u32);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern u32 func_020307B0(void *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_020403F4(u32);
extern void func_0203F9B4(void);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
extern void func_0204989C(u32,u32,u32,u32,u32,u32,u16);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
extern void func_02040588(unsigned char which, unsigned char enable);
extern u8 *func_02012944(void *);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern int func_0204AC18(void *,u32,u32,u32,u16,u16,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern void func_02049238(void *);
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
extern void func_0204AFD8(u32);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern struct Obj_021DD1E0 *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj_021DD1E0 *,unsigned int);
extern void func_0204B878(struct Obj_021DD1E0 *p, u16 value);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_0204B3DC(struct Obj_021DD1E0 *,unsigned int);
extern void func_02045088(u16);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7D0(void *, s16_021DD1E0, s16_021DD1E0, void *, void *, u16);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_0201FEF4(u8 *o);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern u16 func_02039338(void);
extern void func_0203D7B0(unsigned char a0);
extern void *func_021DCF50(u8 *p);
extern int func_021841A4(unsigned char *p);
extern int func_02184114(unsigned char *p);
extern void func_02184134(u8 *p);
extern void func_020061E4(u32 a);
extern struct BmpMenu *func_0201FDA0(const WinDat *,u16,u8,u8,u16);
extern u32 func_0201FEBC(u8 *p);
extern void func_02082BCC(void *,int,unsigned);
extern int func_021DCBC4(void *,int,void *,int);
extern void func_0203D7BC(u8 a0);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern char *func_02184180(unsigned char *p, int i);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern struct Entry *func_020399A8(void);
extern void func_0203A424(char *p, int a, int b, int c);
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);
extern u16 sub_02039338(void);
extern void func_0201CE0C(void *);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern void func_02008500(void *,void *);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u8 func_021841A0(u8 *);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0201F73C(void *, int, int, int);
extern void func_0201CE48(struct Rec3 *p);
extern void *func_0201CCE4(void *, int, int, void *, void *, int, void *, int, u16, u16);
extern u32 func_0201CE30(void *p);
extern unsigned int func_0203630C(void);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern u32 func_020362DC(void);
extern void func_0201CE38(void *);
extern void func_0201F7A8(void *desc, u32 kind);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_0207E51C(void *, int, int);
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern void func_0203064C(u32 src, u32 dst, u32 size);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void *func_02012934(const struct BigObj *p);
extern void *func_020056A0(void (*)(int,void *),void *,u32);
extern void *func_02047CFC(u16,u16,u16);
extern u32 func_02030CB0(u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void func_0201C6EC(struct PrintSys *);
extern void func_0201C4C0(struct PrintSys *);
extern void func_0202F038(u8 *);
extern void func_02030DA4(void *);
extern void func_02047E54(struct Rec *p);
extern void func_02046788(void);
extern void func_02030EAC(struct Node *n);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(u32);
extern int func_020351A0(u32);
extern void func_02030D28(struct Ctx *c);
extern u32 func_020221A4(void);
extern u32 func_0200FB24(void);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern void func_02039C68(struct Link *p, u32 lo, u32 hi);
extern u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void func_02005D90(int, int);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200ED48(void *);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
extern void func_021E19C0(char *,int);
extern u32 func_020056EC(u32);
extern void *func_0201292C(const struct BigObj *p);
extern u32 func_02007E50(u8 *, u16, u16, u16);
extern u32 func_02008DF0(struct Sub02008C20Obj *,int);
extern void func_0203516C(u32);
extern void *func_0201088C(unsigned, unsigned);
extern u32 func_02010904(struct Sub0201088CObj *p);
extern u32 func_0200FBB0(void);
extern u32 func_0200F7B8(u32 a0);
extern void func_0202223C(unsigned, unsigned);
extern void func_02010934(struct Sub0201088CObj *p);
extern void func_0203A5E4(unsigned);
extern void func_02184174(u8 *p);
extern u32 func_0218417C(u8 *);
extern void func_02021D50(struct S02021D50 *);
extern void func_0204A648(void);
extern void func_020419E4(void);
extern void func_02048B6C(struct Light *l, const u32 *in);
extern void func_02048AD0(struct Light *l);
extern void func_02047964(void),func_020479D8(void),func_02047970(void),func_0204A600(void);
extern void func_0206AA3C(int,int,int,int),func_0206AA78(int,u32),func_0206AA8C(u32,u32,u32),func_0206AAB0(u32,u32,u32);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_0202F0B0(u8 *p);
extern void func_020433E0(const struct DispVram *);
extern void func_0207D63C(unsigned, int, int, int, int);
extern void func_0207DCF8(const u16 *);
extern void func_0207DD24(u16, int, int, int, int);
extern void func_02046440(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize, u16 fifoSize, s16_021DEFD0 heap, void (*setup)(void));
extern void func_02046BE0(u32, u32);
extern void *func_02048A24(u32, u32, u32, u32, u32, u32, u32, u32, Vec3 *, Vec3 *, Vec3 *, u16);
extern void func_0203F8F4(u16);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern void func_02022004(u32,u32,u16,u32,u32);
extern s32 func_02062A00(struct NitroFileHeader *file, void **out);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern int func_02062B30(void *,void **);
extern void func_02040AE0(u32,const void *,u32);
extern void *func_02021518(u32);
extern void func_02021EE4(struct PalAnmSlot *,int);
extern void func_0202155C(struct PalAnmSlot *,u32,u32,u32);
extern void func_020215A0(struct PalAnmSlot *,u32);
extern void func_02021540(struct PalAnmSlot *);
extern int func_0204ABF0(void *,u32,u32,u32,u16);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02021640(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201C440(void *);
extern void func_020456F8(struct Descriptor *d);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_0201D83C(void *ptr);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02041B6C(u32 bit);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern u32 func_02048AC4(void *ptr);
extern int func_02035C08(const void *);
extern int func_02047E88(void *,const void *);
extern void func_020480E4(struct Ctx *c, u32 i);
extern u32 func_02048A18(u8 *a0, int i);
extern void func_020520FC(int,int,int,struct Mtx33 *);
extern void func_02047A60(void *a0, struct Arg *a1);
extern void func_0207ADC4(Mtx *);
extern s16 func_0203F63C(u32 x);
extern int func_0203F5FC(u32 x);
extern int func_02047910(void *a, int idx, int amount);
extern struct Node * func_02030DA8(void *,void (*)(void *,void *),void *,int);
extern void func_0204B8D4(struct Obj *p, u32 arg);
extern u32 func_0204B98C(struct Actor *);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_020493D4(struct ArcFile *, u32);
extern void func_0204932C(struct ArcFile *, u32, void *);
extern int func_021DCE00(char *p, int i);
extern void *func_0201AB28(void *, unsigned);
extern void func_0202F190(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02019CE0(const struct RecDC *src, struct RecDC *dest);
extern u32 func_0201AA18(void *p);
extern unsigned func_02017E1C(void *, unsigned, unsigned);
extern void func_02005DE4(void *);
extern int func_02005E64(void);
extern int func_02005F38(void);
extern int func_02005E9C(void);
void func_021DD1E0(void);
void func_021DD2E0(u8 *p,void *q);
void func_021DD380(u8 *p);
void func_021DD3B0(u32 a0);
void func_021DD3D8(void *p,void *arc);
void func_021DD4A8(const u8 *p);
void func_021DD570(u8 *p);
void func_021DD5AC(u8 *p);
void func_021DD638(u8 *p);
void func_021DD700(void *p, void *text, void *font);
void func_021DD760(u8 *p);
int func_021DD79C(char *p, int state);
int func_021DD7E4(char *p,int a);
void func_021DD80C(char *p);
void func_021DD924(char *p);
int func_021DD928(char *p,int state);
void func_021DD93C(char *p, int v);
int func_021DD94C(char *p,int state);
int func_021DD970(char *p,int state);
int func_021DD99C(char *p,int state);
int func_021DD9D4(char *p,int state);
int func_021DDAEC(char *p,int state);
int func_021DDB04(char *p, int state);
int func_021DDB90(char *p,int state);
int func_021DDBB0(char *p,int state);
int func_021DDBE8(char *p, int state);
int func_021DDC7C(char *p,int state);
int func_021DDCB4(char *p,int state);
int func_021DDCEC(char *p,int state);
int func_021DDD0C(char *p,int state);
int func_021DDD48(char *p,int state);
int func_021DDD80(char *p, int state);
int func_021DDE24(char *p, int state);
int func_021DDE74(char *p,int state);
int func_021DDE94(char *p, int state);
int func_021DDEDC(char *p, int state);
int func_021DDF38(char *p,int state);
int func_021DDF64(char *p,int state);
int func_021DDF84(char *p, int state);
int func_021DDFC0(char *p,int state);
int func_021DDFFC(char *p, int state);
int func_021DE060(char *p);
void func_021DE08C(char *p,int state,int player);
void func_021DE17C(char *p, int command, int player);
int func_021DE220(void *p);
int func_021DE248(void *window,int unused,u16 color,Context *p);
void func_021DE350(char *a0);
int func_021DE354(void *p);
unsigned func_021DE37C(void *p);
int func_021DE388(char *p);
void func_021DE4B4(char *p, int message, int unused);
int func_021DE55C(char *p);
void func_021DE5C0(u8 *p);
void func_021DE5D0(u8 *p);
void func_021DE6C0(char *p, void *a1);
void func_021DE6DC(u8 *p);
void func_021DE6EC(u8 *p, u8 *q, int i, int j, int unused);
int func_021DE738(Obj_021DD1E0 *obj);
u32 func_021DE7F4(void);
int func_021DE7FC(void *obj,int unused,u8 *q);
int func_021DE960(struct S020315D4 *a, int b, int c, u8 *p);
int func_021DEA0C(int a, int b, int c, u8 *p);
void func_021DEA68(char *p);
int func_021DEA70(u8 *p);
int func_021DEA84(u8 *p);
int func_021DEAC8(u8 *p);
int func_021DEAE0(char *p);
void *func_021DEB10(char *p);
int func_021DEB1C(char *p);
int func_021DEB40(char *p);
int func_021DEB74(u8 *p);
int func_021DEC08(char *p);
int func_021DEC38(char *p);
int func_021DEC64(char *p);
int func_021DEC84(char *p);
int func_021DECB0(char *p);
int func_021DECCC(char *p);
int func_021DECF4(u8 *p);
int func_021DED3C(u8 *p);
int func_021DED88(char *p);
int func_021DEDAC(Obj_021DED88 *obj);
int func_021DEE4C(char *p);
int func_021DEED8(char *p);
int func_021DEF14(char *p);
int func_021DEF3C(u8 *p);
void func_021DEF6C(Obj_021DED88 *obj);
int func_021DEFB4(char *p);
int func_021DEFD0(int *p);
int func_021DEFE8(int *p);
int func_021DF004(char *p);
int func_021DF01C(u8 *p);
int func_021DF050(u8 *p);
int func_021DF060(char *p);
int func_021DF1C4(u8 *p);
int func_021DF204(char *p);
int func_021DF22C(Obj_021DF22C *obj);
int func_021DF2A0(int *p);
int func_021DF2B8(int *p);
int func_021DF2E0(Obj_021DF2E0 *obj);
int func_021DF370(u8 *p);
int func_021DF3E8(u8 *p);
int func_021DF434(u8 *p);
int func_021DF488(u8 *p);
int func_021DF4AC(u8 *p);
int func_021DF548(u8 *p);
int func_021DF56C(u8 *p);
int func_021DF598(u8 *p);
int func_021DF5B0(u8 *p);
int func_021DF5EC(u8 *p);
int func_021DF648(u8 *p);
int func_021DF6A4(u8 *p);
int func_021DF6B8(char *p);
int func_021DF6D4(u8 *p);
int func_021DF6FC(u8 *p);
int func_021DF778(char *p);
int func_021DF7A4(int *p);
int func_021DF7CC(int *p);
int func_021DF7E4(void);
void func_021DF7E8(void *arg,char *p);
void func_021DF800(char *p);
void func_021DF83C(char *p);
void func_021DF864(u8 *p);
void func_021DF984(char *p);
void func_021DF998(char *a0);
void func_021DFA14(char *a0);
void func_021DFA68(void);
void func_021DFAD8(u8 *p);
void func_021DFB60(char *a0);
void func_021DFC74(char *p);
void func_021DFE40(char *p);
void func_021DFE6C(u8 *p,int file);
void func_021DFEA0(u8 *p);
void func_021DFEAC(u8 *p);
void func_021DFEB8(u8 *p);
void func_021DFEC4(char *p);
void func_021DFEFC(char *p);
void func_021DFF20(u8 *p,int a);
void func_021DFF44(u8 *p);
void func_021DFF70(u8 *p);
void func_021DFFC8(u8 *p);
void func_021DFFF8(u8 *p);
void func_021E00D4(u8 *p);
void func_021E0130(u8 *p,int message);
void func_021E01B0(u8 *p,int message,void *value);
void func_021E026C(u8 *p,int message,unsigned value);
void func_021E0304(u8 *p);
void func_021E0338(u8 *p,int count);
void func_021E03A0(u8 *p);
void func_021E03D8(u8 *p,void *text,int index,int color);
void func_021E0450(u8 *p,void *text,int index,int a);
void func_021E0478(u8 *p,u32 i);
void func_021E04B4(u8 *p);
int func_021E04C4(char *a0);
void func_021E04E0(u8 *p);
void func_021E0554(u8 *p);
void func_021E0570(u8 *p);
void func_021E05D4(u8 *p);
void func_021E0634(u8 *p,int a);
void func_021E0640(u8 *p);
void func_021E0678(char *p);
void func_021E0698(u8 *p);
void func_021E06E0(char *p);
void func_021E073C(char *p);
void func_021E078C(char *p,char *q);
void func_021E07A4(char *p);
void func_021E0848(u8 *p);
void func_021E0980(char *p,int amount);
void func_021E09C0(char *p,int *q,int amount,int extra);
void *func_021E0A44(Obj *p);
void func_021E0B14(char *p,char *q);
void func_021E0B38(char *p,char *q,int amount);
void func_021E0BA4(char *p, char *q);
void func_021E0BC0(char *p,char *q,int i);
void func_021E0C08(char *p,int a,int b,int c,int d,int e,int *q);
void func_021E0C70(struct Node *task,char *p);
int func_021E0CA4(char *p);
int func_021E0CCC(int *p);
int func_021E0D0C(int *p);
void func_021E0D50(char *p,int *q);
void func_021E0DC0(void *unused,char *p);
void func_021E0DE8(char *p);
void func_021E0E1C(u8 *p);
void func_021E0E2C(char *p,int value);
void func_021E0E50(char *p);
int func_021E0E8C(char *p);
void func_021E0EAC(int *p);
void func_021E0EFC(void *unused,char *p);
void func_021E0F20(char *p);
void func_021E0F54(u8 *p);
void func_021E0F64(char *p, int key);
void func_021E0FAC(int *p);
void func_021E1028(void *unused,char *p);
void func_021E104C(char *p);
void func_021E1080(u8 *p);
void func_021E1090(char *p, int key);
void func_021E10D8(u8 *p,State_021E073C *s);
void func_021E11A0(void *unused,u8 *p);
void func_021E11B4(char *p);
void func_021E11E4(u8 *p);
void func_021E11F4(char *p);
int func_021E1204(char *p);
int func_021E1210(char *p);
void func_021E121C(void *task, int *p);
void func_021E129C(char *p);
void func_021E1320(void *task, State_021E1320 *p);
void func_021E13A8(void *unused, char *p);
void func_021E13BC(char *p);
void func_021E13F0(u8 *p);
u16 func_021E1400(char *p);
void func_021E140C(char *p);
void func_021E141C(void *unused, int *p);
void func_021E1468(void *unused, char *p);
void func_021E1488(char *p);
void func_021E14BC(u8 *p);
void func_021E14CC(char *p, char *q);
void func_021E14E4(const char *p);
void func_021E1540(void *task, int *p);
void func_021E1584(char *p, int flag);
void func_021E15DC(int *p, int v);
void func_021E1604(char *p, int v);
int func_021E161C(char *p);
void *func_021E1634(char *p, u32 member, int flag);
void func_021E168C(int *p,int a);
void func_021E1694(char *p, const Record_021E1694 *q);
char *func_021E16AC(char *p, int n);
char *func_021E16C0(char *p);
int func_021E16C4(char *p, int mask);
int func_021E16D8(const char *p);
int func_021E170C(char *p);
void func_021E172C(char *p,unsigned short *q);
void func_021E1758(char *p, int a1);
int func_021E1768(char *p, int i);
void func_021E1784(char *p, int i);
int func_021E17EC(char *p);
void func_021E180C(int *p,int a,int b);
void func_021E1814(unsigned char *p,u16 *q);
int func_021E1830(char *p, int angle, int index);
int func_021E18CC(void *p);
int func_021E1910(char *p);
int func_021E1954(char *p);
int func_021E1974(char *p);
void func_021E1988(unsigned int n);
int func_021E19A4(void);
extern const struct DispConfig_021DD1E0 d_021E1B70;
extern const struct BgTemplate_021DD1E0 d_021E1BE0,d_021E1B80,d_021E1BA0,d_021E1BC0,d_021E1C00;
extern const struct Cfg d_020A1448;
extern const u32 d_021E1B40[],d_021E1B20[],d_021E1B30[],d_021E1B38[];
extern const u16 d_021E1B08[];
extern const WinDat d_021E1AE8;
extern const u8 d_021E1AF8[];
extern const u16 d_021E1FA0[][5];
extern const char d_021E22B8[];
extern const u16 d_021E1FDC[][5];
extern struct Range_021DD1E0 d_021E1F34[];
extern const struct DispVram d_021E1EA4;
extern const u16 d_021E1D90[];
extern const Vec3 d_021E2020;
extern const s16_021DEFD0 d_020A1EB8[];
extern Vec3 d_021E1D00, d_021E1D0C;
extern const struct DispConfig_021DEFD0 d_021E202C;
extern const struct BgTemplate_021DEFD0 d_021E204C,d_021E206C,d_021E208C,d_021E20AC,d_021E20CC;
extern const Desc *const d_021E1E30[];
extern const u8 d_021E1CB0[];
extern const Descriptor d_021E20EC[];
extern const int d_021E1DE8[];
extern const struct Setup d_021E1D80;
extern const char d_021E1E60[],d_021E1E70[],d_021E212C[];
extern const Table d_021E203C;
extern const int d_021E2278[];
extern const Pair_021E073C d_021E2018;
extern struct Entry d_021E1F04[];
















/*
 * func_0203FC28 0x0203FC28 arm
 * func_0203FCA0 0x0203FCA0 arm
 * func_020414EC 0x020414EC arm
 * func_02040B94 0x02040B94 arm
 * d_021E1B70 0x021E1B70 data a4
 * d_021E1BE0 0x021E1BE0 data a4
 * d_021E1B80 0x021E1B80 data a4
 * d_021E1BA0 0x021E1BA0 data a4
 * d_021E1BC0 0x021E1BC0 data a4
 * d_021E1C00 0x021E1C00 data a4
 */
void func_021DD1E0(void)
{
    struct DispConfig_021DD1E0 d;
    struct BgTemplate_021DD1E0 a,b,c,e,f;
    d=d_021E1B70;
    func_0203FC28((struct DispConfig_021DD1E0 *)&d);
    a=d_021E1BE0;
    func_0203FCA0(4, (const struct BgTemplate_021DD1E0 *)&a, 0); func_020414EC(4);
    b=d_021E1B80;
    func_0203FCA0(5, (const struct BgTemplate_021DD1E0 *)&b, 0); func_020414EC(5);
    c=d_021E1BA0;
    func_0203FCA0(6, (const struct BgTemplate_021DD1E0 *)&c, 0); func_02040B94(4,32,0,114);
    e=d_021E1BC0;
    func_0203FCA0(0, (const struct BgTemplate_021DD1E0 *)&e, 0); func_020414EC(0);
    f=d_021E1C00;
    func_0203FCA0(1, (const struct BgTemplate_021DD1E0 *)&f, 0); func_02040B94(0,32,0,114);
}
















/*
 * func_020457B0 0x020457B0 arm
 * func_02045CAC 0x02045CAC arm
 * func_02049F78 0x02049F78 arm
 * func_021DE6C0 0x021DE6C0 thumb ov137
 */
void func_021DD2E0(u8 *p,void *q)
{
    int i;
    u32 v;
    for(i=0;i<5;i++) {
        *(u32 *)(p+i*4+68)=(u32)func_020457B0(8,114);
        *(u32 *)(p+i*8+312)=0; *(u32 *)(p+i*8+316)=0;
        *(u32 *)(p+i*4+352)=0;
    }
    ((struct Obj02495 *)p)->f5C=(u32)func_020457B0(180,114);
    v=(u32)func_020457B0(40,114); ((struct Obj02495 *)p)->f60=v;
    ((struct Obj02495 *)p)->f118=0;
    func_02045CAC((struct MsgBank *)(((struct Obj02495 *)p)->f40),17,(void *)v);
    func_021DE6C0((char *)p,q);
    ((struct Obj02495 *)p)->f18=0; ((struct Obj02495 *)p)->f20=0; ((struct Obj02495 *)p)->f1C=0;
    ((struct Obj02495 *)p)->f24=(u32)func_02049F78(q,2,(u32)(p+40),114);
    ((struct Obj02495 *)p)->f4804=0; ((struct Obj02495 *)p)->fE8=0;
    ((struct Obj23712 *)(*(u8 * *)&((struct Obj02495 *)p)->f10))->f2C=2;
}















void func_021DD380(u8 *p) {int i;func_021DE6DC(p);func_020307B0(((struct Obj08210 *)p)->f24);for(i=0;i<5;i++)func_02045808(*(void **)((u32)p+i*4+68));func_02045808(((struct Obj08210 *)p)->f60);func_02045808(((struct Obj08210 *)p)->f5C);}















void func_021DD3B0(u32 a0) {func_020403F4(6);func_020403F4(5);func_020403F4(4);func_020403F4(1);func_020403F4(0);func_0203F9B4();}















/*
 * single-function C below is EXACT (52 bytes) at fixed flags, blocker49624.log.
 * typedef unsigned short u16; typedef unsigned int u32;
 * extern u32 func_0204A1BC(void *,void *,u32,u16);
 * extern u32 func_0204968C(u32,void *,void *,u32,u32);
 * u32 func_02049624(void *a,void *b,void *c,void *d,u32 e,u32 f,u16 g) {
 *     u32 r=func_0204A1BC(a,b,f,g); return func_0204968C(r,c,d,e,f);
 * }
 * Blocker symbols: func_0204A1BC 0x0204A1BC arm; func_0204968C 0x0204968C arm.
 * func_02049B68 0x02049B68 arm
 * func_02049658 0x02049658 arm
 * func_020498F4 0x020498F4 arm
 * func_02049B40 0x02049B40 arm
 * func_02049624 0x02049624 arm
 * func_0204989C 0x0204989C arm
 * func_02040588 0x02040588 arm
 * func_0201F5BC 0x0201F5BC thumb
 */
void func_021DD3D8(void *p,void *arc)
{
    func_02049B68(arc,1,0,0,512,114);
    func_02049658(arc,7,1,0,8192,0,114);
    func_020498F4(arc,13,1,0,1536,0,114);
    func_02049B40(23,5,0,416,32,114);
    func_02049B40(30,13,4,0,352,114);
    func_02049624((void *)30,(void *)14,(void *)6,0,0,0,114);
    func_0204989C(30,3,6,0,0,0,114);
    func_0201F5BC(0,1,10,0,114);
    func_0201F5BC(0,31,11,0,114);
    func_02040588(0,1);
    func_02040588(1,1);
    func_02040588(6,1);
}















/*
 * note: 2026-10-05 wave P13 B4: the older draft was DIFF 2/200 (v in r4 instead
 *   of r5). `i = 0;` assigned before `table = ...` (so the counter web starts
 *   while v is live) and `for (; i < 5; ...)` gives EXACT in c99 and c. v is a
 *   plain u8 (the enum local is not needed). Callees: 02008550 returns u8-range
 *   index, 0204B100 returns a pointer, others as in matched callers.
 * func_02012944 0x02012944 thumb
 * func_02008550 0x02008550 thumb
 * func_020490F4 0x020490F4 arm
 * func_0204A48C 0x0204A48C arm
 * func_0204B100 0x0204B100 arm
 * func_0204A6C8 0x0204A6C8 arm
 * func_0204AC18 0x0204AC18 arm
 * func_0204AF28 0x0204AF28 arm
 * func_02049238 0x02049238 arm
 * d_020A1448 0x020A1448 data a4
 * d_021E1B40 0x021E1B40 data a4
 * d_021E1B20 0x021E1B20 data a4
 * d_021E1B30 0x021E1B30 data a4
 * d_021E1B38 0x021E1B38 data a4
 */
void func_021DD4A8(const u8 *p)
{
    u8 v;
    long i;
    u32 a,b;
    const u32 *table;
    void *arc;
    v=func_02008550((const struct Sub0200852CObj *)func_02012944(*(void **)(*(u8 **)(*(u8 **)(p+12)+20)+4)));
    arc=func_020490F4(31,114);
    func_0204A48C(&d_020A1448,(u32)d_021E1B40,114);
    *(void **)(p+104)=func_0204B100(30,1,114);
    i=0;
    table=d_021E1B20+v;
    a=table[0]; b=table[2];
    for(;i<5;i++) {
        *(int *)(p+i*4+128)=func_0204A6C8(arc,a,0,0,114);
        *(int *)(p+i*4+108)=func_0204AC18(arc,b,0,(u16)(i*32),0,1,114);
    }
    *(int *)(p+148)=func_0204AF28(arc,d_021E1B30[v],d_021E1B38[v],114);
    func_02049238(arc);
    *(void **)(p+52)=func_020490F4(32,114);
}















void func_021DD570(u8 *p) {int i;u8 *q;func_02049238(((struct Obj10616 *)p)->f34);for(i=0;i<5;i++) {q=(u8 *)((u32)p+i*4);func_0204A8D4(((struct Obj14207 *)q)->f6C);func_0204ADA4(((struct Obj14207 *)q)->f80);}func_0204AFD8(((struct Obj10616 *)p)->f94);func_0204B1CC(((struct Obj10616 *)p)->f68);func_0204A5AC();}














/*
 * func_0204B294 0x0204B294 arm
 * func_0204B92C 0x0204B92C arm
 * func_0204B878 0x0204B878 arm
 * func_0204B3DC 0x0204B3DC arm
 * func_020434DC 0x020434DC arm
 * func_02043598 0x02043598 arm
 * d_021E1B08 0x021E1B08 data a2
 */
void func_021DD5AC(u8 *p)
{
    struct { u16 a,b,c; u8 d,e; } s;
    long i;
    s.e=1; s.d=0; s.c=0;
    for(i=0;i<5;i++) {
        s.a=d_021E1B08[i*2+2]; s.b=d_021E1B08[i*2+3];
        *(u32 *)(p+i*4+156)=(u32)(struct Obj *)func_0204B294((void *)((struct Obj14208 *)p)->f68,*(u32 *)(p+i*4+128),*(u32 *)(p+i*4+108),((struct Obj14208 *)p)->f94,&s,0,114);
        func_0204B92C((struct Obj_021DD1E0 *)*(u32 *)(p+i*4+156),1);
        func_0204B878((struct Obj_021DD1E0 *)(*(u32 *)(p+i*4+156)),0);
        func_0204B3DC((struct Obj_021DD1E0 *)*(u32 *)(p+i*4+156),0);
    }
    func_020434DC(16,1); func_02043598(16,0);
}














/*
 * extent: Two-byte alignment padding at 0x021DD6FE.
 */
void func_021DD638(u8 *p) {
    func_02045088(0x72);
    *(u32 *)&((struct Obj00170 *)p)->fD8=func_020450F0(5,26,20,6,2,13,1);
    func_02043B5C(func_02045770(((struct Obj00170 *)p)->fD8),0);
    *(u32 *)&((struct Obj00170 *)p)->fD4=func_020450F0(0,2,19,27,4,13,1);
    func_02043B5C(func_02045770(((struct Obj00170 *)p)->fD4),15);
    *(u32 *)&((struct Obj00170 *)p)->fDC=func_020450F0(0,3,1,26,2,15,1);
    func_021DD700(((struct Obj00170 *)p)->fDC,((struct Obj00170 *)p)->f60,((struct Obj00170 *)p)->f38);
    *(u32 *)&((struct Obj00170 *)p)->fD0=func_020450F0(0,2,6,16,11,15,1);
    func_02043B5C(func_02045770(((struct Obj00170 *)p)->fD0),0);
    func_021DE248(((struct Obj00170 *)p)->fD0, 0, 0x480, (Context *)p);
    ((struct Obj00170 *)p)->fF8=((struct Obj00170 *)p)->fDC;
    ((struct Obj00170 *)p)->fFC=0;
}














void func_021DD700(void *p, void *text, void *font) {
    int width;
    width = func_0201D304(text, (u32)font, 0);
    func_02043B5C(func_02045770(p), 0);
    func_0201C7D0(func_02045770(p), (208-width)/2, 1, text, font, 0x480);
    func_02045334(p);
    func_02045374(p);
    func_020409B4((u32)func_02045730(p));
}














void func_021DD760(u8 *p) {if(((struct Obj05425 *)p)->fE8!=0)func_0201FEF4(((struct Obj05425 *)p)->fE8);func_020452E8(((struct Obj05425 *)p)->fD0);func_020452E8(((struct Obj05425 *)p)->fDC);func_020452E8(((struct Obj05425 *)p)->fD8);func_020452E8(((struct Obj05425 *)p)->fD4);func_020450C8();}














int func_021DD79C(char *p, int state) {
    if (func_02039338() == 0) {
        int zero = 0;
        func_0203D7B0(0);
        if ((unsigned)func_021841A4(func_021DCF50((u8 *)p)) >= 2)
            func_021DE4B4(p, 2, zero);
    } else {
        func_0203D7B0(1);
        func_021DE4B4(p, 8, 0);
    }
    func_021DD93C(p, 3);
    return state;
}














/*
 * Lever: nested explicit empty then/else-call plus outer else-call preserves the b-to-next at +0x1c; goto spelling DIFF12/38B.
 * abi: 021DD802 visibly reloads p into r0 for 021DE350; retain that argument despite its empty matched body.
 */
int func_021DD7E4(char *p,int a) {func_021DD80C(p);if(func_02039338()==0) {if(func_021DE220(p)==1) {} else func_021DE350(p);}else func_021DE350(p);return a;}














void func_021DD80C(char *p) {
    char *q;
    if (func_021DE7F4()&1) {
        if (func_02039338()==0) {
            q=*(char * *)&((struct Obj06534 *)p)->f10;
            if (((struct Obj08211 *)q)->f2C==func_021DE354(p) && ((struct Obj08211 *)q)->f30==0) {
                if (func_02184114(func_021DCF50((u8 *)p))) {
                    func_020061E4(0x54c);
                    func_021DE4B4(p,3,0);
                    func_021DD93C(p,22);
                }
            } else func_020061E4(0x548);
        }
    } else if (func_021DE7F4()&2) {
        if (func_02039338()!=0) {
            if (((struct Obj23713 *)(*(char * *)&((struct Obj06534 *)p)->f10))->f28==0) {
                func_021DE4B4(p,4,0);
                func_021DD93C(p,4);
            } else func_020061E4(0x548);
        } else {
            q=*(char * *)&((struct Obj06534 *)p)->f10;
            if (((struct Obj08211 *)q)->f2C==func_021841A4(func_021DCF50((u8 *)p)) && ((struct Obj08211 *)q)->f30==0) {
                if (func_02184114(func_021DCF50((u8 *)p))) {
                    func_021DE4B4(p,4,0);
                    func_021DD93C(p,4);
                    func_020061E4(0x551);
                }
            } else func_020061E4(0x548);
        }
    } else {
        if (((struct Obj06534 *)p)->f4808==0 && func_02039338()==0 &&
            ((struct Obj23714 *)(*(char * *)&((struct Obj06534 *)p)->f10))->f2C==func_021841A4(func_021DCF50((u8 *)p)))
            func_02184134(func_021DCF50((u8 *)p));
    }
}













void func_021DD924(char *p) {}













/*
 * prototype: original r0 holds p at the call to func_021DD924; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 */
int func_021DD928(char *p,int state) {((struct Obj23715 *)p)->f118=2;func_021DD924(p);return state;}














void func_021DD93C(char *p, int v)
{
    ((struct Obj01414 *)p)->f118 = 0x1A;
    ((struct Obj01414 *)p)->f11C = v;
}













int func_021DD94C(char *p,int state) {if(func_021DE55C(p)) ((struct Obj14209 *)p)->f118=((struct Obj14209 *)p)->f11C;func_021DD924(p);return state;}













/*
 * extent: two zero alignment bytes follow the compiled function.
 * prototype: original r0 holds p at the call to func_021DD924; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 */
int func_021DD970(char *p,int state) {if(func_02039338()==0)func_02184134(func_021DCF50((u8 *)p));((struct Obj23716 *)p)->f118=3;func_021DD924(p);return state;}













int func_021DD99C(char *p,int state) {*(struct BmpMenu * *)&((struct Obj14210 *)p)->fE8=func_0201FDA0(&d_021E1AE8,31,11,0,114);((struct Obj14210 *)p)->f118=5;func_021DD924(p);return state;}













int func_021DD9D4(char *p,int state) {
    unsigned count;
    unsigned result;
    u8 msg[4];
    if (func_02039338()!=0) {
        if (((struct Obj23717 *)(*(char * *)&((struct Obj02867 *)p)->f10))->f28!=0) {
            if (func_021DE7F4()&0xc3) func_020061E4(0x548);
            func_021DD924(p);
            return state;
        }
    } else {
        if (((struct Obj23718 *)(*(char * *)&((struct Obj02867 *)p)->f10))->f30!=0) {
            if (func_021DE7F4()&0xc3) func_020061E4(0x548);
            func_021DD924(p);
            return state;
        }
    }
    count=func_021DE354(p);
    if (count!=func_021841A4(func_021DCF50((u8 *)p))) {
        func_021DD924(p);
        return state;
    }
    result=func_0201FEBC(((struct Obj02867 *)p)->fE8);
    if (result!=-1) {
        if (result==-2) {
            if (func_02039338()==0) func_02184134(func_021DCF50((u8 *)p));
            ((struct Obj02867 *)p)->f118=0;
        } else {
            if (func_02039338()==0) {
                func_021DD93C(p,11);
                func_021DE4B4(p,14,0);
            } else {
                func_02082BCC(msg,0,4);
                msg[2]=0;
                msg[0]=func_02039338();
                if (func_021DCBC4(((struct Obj02867 *)p)->f10,0x2801,msg,4)) {
                    ((struct Obj02867 *)p)->f4810=1;
                    ((struct Obj02867 *)p)->f4820=0;
                    ((struct Obj02867 *)p)->f118=6;
                } else ((struct Obj02867 *)p)->f118=0;
            }
        }
        ((struct Obj02867 *)p)->fE8=0;
    }
    func_021DD924(p);
    return state;
}













int func_021DDAEC(char *p,int state) {((struct Obj23719 *)p)->f4820=0;func_021DD924(p);return state;}













int func_021DDB04(char *p, int state) {
    unsigned char buf[4];
    if (((struct Obj23720 *)(*(char * *)&((struct Obj03303 *)p)->f10))->f38 != func_021841A4(func_021DCF50((u8 *)p)) ||
        ((struct Obj23721 *)(*(char * *)&((struct Obj03303 *)p)->f10))->f38 != func_021DE354(p)) {
        ((struct Obj03303 *)p)->f4820 = 0;
        ((struct Obj03303 *)p)->f118 = 8;
        func_021DD924(p);
        return state;
    }
    ++*(volatile s16_021DD1E0 *)&((struct Obj03303 *)p)->f4820;
    if (*(volatile s16_021DD1E0 *)&((struct Obj03303 *)p)->f4820 > 30) {
        int zero = 0;
        func_02082BCC(buf, 0, 4);
        buf[2] = 1;
        buf[0] = func_02039338();
        func_021DCBC4(((struct Obj03303 *)p)->f10, 0x2801, buf, 4);
        ((struct Obj03303 *)p)->f4820 = zero;
        ((struct Obj03303 *)p)->f118 = 9;
    }
    func_021DD924(p);
    return state;
}













int func_021DDB90(char *p,int state) {((struct Obj23722 *)p)->f4810=0;func_021DD93C(p,0);func_021DD924(p);return state;}













int func_021DDBB0(char *p,int state) {*(struct BmpMenu * *)&((struct Obj14211 *)p)->fE8=func_0201FDA0(&d_021E1AE8,31,11,0,114);((struct Obj14211 *)p)->f118=23;func_021DD924(p);return state;}













int func_021DDBE8(char *p, int state) {
    char *q = *(char * *)&((struct Obj05426 *)p)->f10;
    unsigned result;
    if (((struct Obj14212 *)q)->f2C != func_021DE354(p) || ((struct Obj14212 *)q)->f30 != 0) {
        if (func_021DE7F4() & 0xc3) func_020061E4(0x548);
        func_021DD924(p);
        return state;
    }
    result = func_0201FEBC(((struct Obj05426 *)p)->fE8);
    if (result != -1) {
        if (result == -2) {
            func_02184134(func_021DCF50((u8 *)p));
            ((struct Obj05426 *)p)->f118 = 0;
        } else {
            if (func_02039338() == 0) {
                ((struct Obj05426 *)p)->f118 = 0x18;
                ((struct Obj05426 *)p)->f4812 = func_021DE354(p);
            }
        }
        ((struct Obj05426 *)p)->fE8 = 0;
    }
    func_021DD924(p);
    return state;
}













/*
 * prototype: original cmp r0,#1 at 021DDC96 uses func_021DCBC4's return;
 * retain int return despite the pending void tail-forwarder. Original 021DDCA2
 * supplies r0=1 to func_0203D7BC despite its filed no-argument prototype.
 */
int func_021DDC7C(char *p,int state) {if(((struct Obj10617 *)p)->f4813==0) {if(func_021DCBC4(((struct Obj10617 *)p)->f10,0x2804,0,0)==1) {((struct Obj10617 *)p)->f118=27;func_0203D7BC(1);}}return state;}













/*
 * extent: two zero alignment bytes follow the compiled function.
 */
int func_021DDCB4(char *p,int state) {if(func_02039338()==0)func_021841A4(func_021DCF50((u8 *)p));if(((struct Obj23723 *)(*(char * *)&((struct Obj14213 *)p)->f10))->f20==func_021841A4(func_021DCF50((u8 *)p))) ((struct Obj14213 *)p)->f118=27;return state;}













int func_021DDCEC(char *p,int state) {func_021DE4B4(p,5,0);func_021DD93C(p,10);func_021DD924(p);return state;}












int func_021DDD0C(char *p,int state) {if(++((struct Obj23724 *)p)->f124>60) {func_0202208C(0,0,0,0,16,1,114);state=3;}func_021DD924(p);return state;}












int func_021DDD48(char *p,int state) {*(struct BmpMenu * *)&((struct Obj14214 *)p)->fE8=func_0201FDA0(&d_021E1AE8,31,11,0,114);((struct Obj14214 *)p)->f118=12;func_021DD924(p);return state;}












int func_021DDD80(char *p, int state) {
    char *q = *(char * *)&((struct Obj04538 *)p)->f10;
    unsigned result;
    if (((struct Obj14215 *)q)->f2C != func_021DE354(p) || ((struct Obj14215 *)q)->f30 != 0) {
        if (func_021DE7F4() & 0xc3) func_020061E4(0x54c);
        func_021DD924(p);
        return state;
    }
    result = func_0201FEBC(((struct Obj04538 *)p)->fE8);
    if (result != -1) {
        if (result == -2) {
            ((struct Obj04538 *)p)->f118 = 0;
            func_02184134(func_021DCF50((u8 *)p));
        } else {
            ((struct Obj04538 *)p)->f118 = 0xd;
            func_021DCBC4(((struct Obj04538 *)p)->f10, 0x2802, 0, 0);
            func_0201F02C(((struct Obj04538 *)p)->f3C, 0, func_02184180(func_021DCF50((u8 *)p), 0));
        }
        ((struct Obj04538 *)p)->fE8 = 0;
    }
    func_021DD924(p);
    return state;
}












int func_021DDE24(char *p, int state) {
    if (func_02039338() == 0) {
        func_021DE4B4(p, 5, 0);
    } else {
        func_0201F02C(((struct Obj14216 *)p)->f3C, 0, func_02184180(func_021DCF50((u8 *)p), 0));
        func_021DE4B4(p, 0x10, 0);
    }
    func_021DD93C(p, 0xe);
    ((struct Obj14216 *)p)->f124 = 0;
    func_021DD924(p);
    return state;
}












int func_021DDE74(char *p,int state) {if(++((struct Obj14217 *)p)->f124>45) ((struct Obj14217 *)p)->f118=15;func_021DD924(p);return state;}












int func_021DDE94(char *p, int state) {
    func_020399A8();
    ((struct Obj08212 *)p)->f4814 = ((struct Obj08212 *)p)->f480C ^ func_021DE37C(p);
    func_0203A424((char *)func_020399A8(), 0xcf, 0x28, (u16)(((struct Obj08212 *)p)->f4814));
    ((struct Obj08212 *)p)->f118 = 0x10;
    func_021DD924(p);
    return state;
}












int func_021DDEDC(char *p, int state) {
    if (func_02039CB4((struct Link *)func_020399A8(), 0xcf, 0x28) != 0 ||
        ((struct Obj14218 *)p)->f4814 != (func_021DE37C(p) ^ ((struct Obj14218 *)p)->f480C)) {
        func_0203D7B0(0);
        func_0202208C(0,0,0,0,0x10,1,0x72);
        state = 3;
    }
    func_021DD924(p);
    return state;
}












int func_021DDF38(char *p,int state) {if(func_021DE55C(p)) {func_021DE4B4(p,7,0);((struct Obj23725 *)p)->f118=18;}func_021DD924(p);return state;}












int func_021DDF64(char *p,int state) {if(func_021DE55C(p)) ((struct Obj23726 *)p)->f118=10;func_021DD924(p);return state;}












int func_021DDF84(char *p, int state) {
    func_021DE4B4(p, 15, 1);
    *(int *)(p + 0x118) = 20;
    sub_02039338();
    *(int *)(p + 0x481C) = func_021841A4(func_021DCF50((u8 *)p));
    *(int *)(p + 0x4818) = 300;
    func_021DD924(p);
    return state;
}












int func_021DDFC0(char *p,int state) {if(((struct Obj06535 *)p)->f481C){if(((struct Obj06535 *)p)->f481C!=(u32)func_021841A4(func_021DCF50((u8 *)p))) ((struct Obj06535 *)p)->f481C=0;}((struct Obj06535 *)p)->f118=21;((struct Obj06535 *)p)->f124=0;func_021DD924(p);return state;}












int func_021DDFFC(char *p, int state) {
    if (((struct Obj03840 *)p)->f481C != 0) {
        if (((struct Obj03840 *)p)->f481C != func_021841A4(func_021DCF50((u8 *)p)))
            ((struct Obj03840 *)p)->f481C = 0;
    }
    if (--((struct Obj03840 *)p)->f4818 < 0)
        ((struct Obj03840 *)p)->f481C = 0;
    if (++((struct Obj03840 *)p)->f124 > 60 && ((struct Obj03840 *)p)->f481C == 0) {
        ((struct Obj03840 *)p)->f118 = 0;
        func_02039338();
    }
    func_021DD924(p);
    return state;
}












int func_021DE060(char *p) {func_0202208C(0,0,0,0,16,1,114);((struct Obj23727 *)p)->f8=1;func_021DD924(p);return 3;}












void func_021DE08C(char *p,int state,int player) {
    switch(state) {
    case 2:
        func_021DE5C0((u8 *)p);
        break;
    case 13:
        if (((struct Obj01261 *)p)->fE8) {
            func_0201FEF4(((struct Obj01261 *)p)->fE8);
            ((struct Obj01261 *)p)->fE8=0;
        }
        break;
    case 25:
        func_021DE4B4(p,12,0);
        if (((struct Obj01261 *)p)->fE8) {
            func_0201FEF4(((struct Obj01261 *)p)->fE8);
            ((struct Obj01261 *)p)->fE8=0;
        }
        break;
    case 19:
        if (((struct Obj01261 *)p)->f4810==1) return;
        func_0201F02C(((struct Obj01261 *)p)->f3C,0,func_02184180(func_021DCF50((u8 *)p),player));
        if (player==func_02039338()) return;
        if (((struct Obj01261 *)p)->fE8) {
            func_0201FEF4(((struct Obj01261 *)p)->fE8);
            ((struct Obj01261 *)p)->fE8=0;
        }
        if (func_02039338()==0)
            ((struct Obj23728 *)(*(char * *)&((struct Obj01261 *)p)->f10))->f30&=player^0xffff;
        break;
    case 27:
        if (!func_021DE55C(p)) func_0201CE0C(((struct Obj01261 *)p)->fF0);
        if (((struct Obj01261 *)p)->fE8) {
            func_0201FEF4(((struct Obj01261 *)p)->fE8);
            ((struct Obj01261 *)p)->fE8=0;
        }
        break;
    case 7:
    case 8:
        break;
    default:
        return;
    }
    ((struct Obj01261 *)p)->f118=state;
}












void func_021DE17C(char *p, int command, int player) {
    void *target;
    if (((struct Obj02868 *)p)->f118 == 3) {
        switch (command) {
        case 1:
            target = func_02184180(func_021DCF50((u8 *)p), player);
            if (target != 0)
                func_0201F02C(((struct Obj02868 *)p)->f3C, 0, target);
            ((struct Obj02868 *)p)->f118 = command;
            ((struct Obj23729 *)(*(char * *)&((struct Obj02868 *)p)->f10))->f2C = func_021841A4(func_021DCF50((u8 *)p));
            ((struct Obj23730 *)(*(char * *)&((struct Obj02868 *)p)->f10))->f30 = 0;
            return;
        case 19:
            func_0201F02C(((struct Obj02868 *)p)->f3C, 0, func_02184180(func_021DCF50((u8 *)p), player));
            if (player != func_02039338()) {
                if (func_02039338() == 0)
                    ((struct Obj23731 *)(*(char * *)&((struct Obj02868 *)p)->f10))->f30 &= player ^ 0xffff;
                ((struct Obj02868 *)p)->f118 = command;
            }
            break;
        }
    } else {
        if (command == 1) {
            ((struct Obj23732 *)(*(char * *)&((struct Obj02868 *)p)->f10))->f30 = 0;
            ((struct Obj23733 *)(*(char * *)&((struct Obj02868 *)p)->f10))->f2C = func_021841A4(func_021DCF50((u8 *)p));
        }
    }
}












int func_021DE220(void *p) {int i,n;n=0;for(i=0;i<5;i++) if(func_02184180(func_021DCF50(p),(u8)i)) n++;return n;}












/*
 * extent: Two-byte alignment padding at 0x021DE34E.
 * lever: Struct members avoid cached element addresses; block scopes and expanding the first y argument settle the two spill slots.
 */
int func_021DE248(void *window,int unused,u16 color,Context *p) {
    int player;
    void *format;
    u16 value;
    void *text;
    int i;
    u16 ink;
    player=func_02039338();
    if (!func_021DE388((char *)p)) return 0;
    func_02043B5C(func_02045770(window),0);
    for(i=0;i<5;i++) {
      do {
        if (p->entries[i].current) {
            int y;
            value=func_02008534(p->entries[i].current);
            text=func_020457B0(16,0x72);
            func_02008500(p->entries[i].current,p->names[i]);
            func_0201EFA4(p->formatter,0,value,5,2,1);
            format=func_02045EC0(p->bank,1);
            func_0201F250(p->formatter,text,format);
            if (player==i) ink=0x860; else ink=color;
            y=18*i+1;
            func_0201C7D0(func_02045770(window),5,18*i+1,p->names[i],p->font,ink);
            func_0201C7D0(func_02045770(window),70,y,text,p->font,ink);
            func_02045808(text);
            do { func_02045808(format); } while (0);
        }
      } while (0);
    }
    func_02045334(window);
    func_02045374(window);
    func_020409B4(func_02045730(window));
    return 1;
}












void func_021DE350(char *a0) {}












int func_021DE354(void *p) {int i,n;n=0;for(i=0;i<5;i++) if(func_02184180(func_021DCF50(p),(u8)i)) n++;return n;}












unsigned func_021DE37C(void *p) {return func_021841A0(func_021DCF50(p));}












int func_021DE388(char *p) {
    int changed;
    int i;
    u32 *slot;
    Record_021DD1E0 *record;
    changed=0;
    for(i=0;i<5;i++) {
        slot=(u32 *)(p+i*8);
        slot[0x13c/4]=slot[0x138/4];
        slot[0x138/4]=(u32)func_02184180(func_021DCF50((u8 *)p),(u8)i);
        record=(Record_021DD1E0 *)(p+i*16);
        record->previous=record->current;
        if (slot[0x138/4]) {
            record->current.words.a=func_02008530((void *)slot[0x138/4]);
            record->current.words.b=1;
        } else {
            record->current.wide=0;
        }
    }
    for(i=0;i<5;i++) {
        slot=(u32 *)(p+i*8);
        if (slot[0x13c/4]!=slot[0x138/4]) {
            changed=1;
            if (slot[0x138/4]==0) *(u32 *)(p+i*4+0x160)=3;
            else *(u32 *)(p+i*4+0x160)=1;
        } else {
            record=(Record_021DD1E0 *)(p+i*16);
            if (record->current.wide!=record->previous.wide) {
                changed=1;
                if (record->current.words.b==0) *(u32 *)(p+i*4+0x160)=3;
                else *(u32 *)(p+i*4+0x160)=1;
            }
        }
    }
    return changed;
}












void func_021DE4B4(char *p, int message, int unused) {
    void *text;
    void *window;
    text = func_020457B0(0xb4, 0x72);
    func_02045CAC(((struct Obj01414 *)p)->f40, message, text);
    func_0201F250(((struct Obj01414 *)p)->f3C, ((struct Obj01414 *)p)->f5C, text);
    func_02045808(text);
    func_02043B5C(func_02045770(((struct Obj01414 *)p)->fD4), 0xf);
    func_0201F73C(((struct Obj01414 *)p)->fD4, 0, 1, 0xa);
    if (((struct Obj01414 *)p)->fF0 != 0)
        func_0201CE48(((struct Obj01414 *)p)->fF0);
    ((struct Obj01414 *)p)->fF0 = func_0201CCE4(((struct Obj01414 *)p)->fD4, 0, 0, ((struct Obj01414 *)p)->f5C, ((struct Obj01414 *)p)->f38, 0, ((struct Obj01414 *)p)->fF4, 0, 0x72, 0xf);
    window = ((struct Obj01414 *)p)->fD4;
    func_02045334(window);
    func_02045374(window);
    func_020409B4(func_02045730(window));
}












int func_021DE55C(char *p) {
    int state;
    if (((struct Obj05428 *)p)->fF0 == 0) return 1;
    state = func_0201CE30(((struct Obj05428 *)p)->fF0);
    if (state == 0) {
        if (func_0203630C() & 1)
            func_0201CE5C(((struct Obj05428 *)p)->fF0, 0);
    } else if (state == 1) {
        if (func_020362DC() & 1)
            func_0201CE38(((struct Obj05428 *)p)->fF0);
    } else if (state == 2) {
        func_0201CE48(((struct Obj05428 *)p)->fF0);
        ((struct Obj05428 *)p)->fF0 = 0;
        return 1;
    }
    return 0;
}













/*
 * Addresses are Black-image addresses.
 */
void func_021DE5C0(u8 *p)
{
    func_0201F7A8(((struct Obj23734 *)p)->fD4, 0);
}












void func_021DE5D0(u8 *p)
{
    int i;
    int flag = 0;
    u8 a, b;
    for (i = 0; i < 5; i++) {
        switch(*(u32 *)(p+i*4+0x160)) {
        case 0: break;
        case 1:
            a=func_02008550(*(void **)(p+i*8+0x138));
            b=func_02008554(*(void **)(p+i*8+0x138));
            if (i==func_02039338()) {
                func_0204B878((struct Obj_021DD1E0 *)(*(void **)(p+i*4+0x9c)), 4);
            } else {
                func_021DE6EC((u8 *)p,*(u8 **)(p+0x114),i,b,a);
                func_0204B878((struct Obj_021DD1E0 *)(*(void **)(p+i*4+0x9c)), 4);
            }
            func_0204B3DC((struct Obj_021DD1E0 *)(*(void **)(p+i*4+0x9c)), 1);
            *(u32 *)(p+i*4+0x160)=2;
            flag=1;
            break;
        case 2: break;
        case 3:
            if(i==func_02039338()) {
                func_02008550(*(void **)(p+i*8+0x138));
                func_0204B878((struct Obj_021DD1E0 *)(*(void **)(p+i*4+0x9c)), 5);
            } else {
                func_0204B878((struct Obj_021DD1E0 *)(*(void **)(p+i*4+0x9c)), 5);
            }
            *(u32 *)(p+i*4+0x160)=0;
            break;
        }
    }
    if(flag) func_020061E4(0x676);
}












void func_021DE6C0(char *p, void *a1) { ((struct Obj23735 *)p)->f110=func_02049F34(32,0,(u32)(p+276),114); }













void func_021DE6DC(u8 *p)
{
    func_020307B0(((struct Obj08210 *)p)->f110);
}












void func_021DE6EC(u8 *p, u8 *q, int i, int j, int unused)
{
    void *r;
    int n;
    func_0207E51C(*(u8 * *)&((struct Obj23736 *)q)->fC + d_021E1AF8[j] * 32, i * 32, 32);
    r = func_02049E34(32, j + 1, 0, (u32)(&n), 114);
    func_0204A9D0((int)(*(void **)(p + (i + 5) * 4 + 0x6c)), (struct Sub0204A9D0 *)n);
    func_020307B0(r);
}












/*
 * volatile: previous state at +0x4804 is read at 0x021DE764 and 0x021DE7CA.
 */
int func_021DE738(Obj_021DD1E0 *obj)
{
    u8 *p = (u8 *)obj;
    int state;
    state = func_021DE354(p);
    if (state > ((struct Obj23737 *)(*(u8 * *)&((struct Obj00170 *)p)->f10))->f2C) {
        if (func_02184114(func_021DCF50(p))) ((struct Obj00170 *)p)->f4808 = 1;
    } else ((struct Obj00170 *)p)->f4808 = 0;
    if (state == obj->previous) return 1;
    switch (state) {
    case 0: break;
    case 1:
        if ((unsigned)func_021841A4(func_021DCF50(p)) > 1 || func_021841A0(func_021DCF50(p)) > 1) return 1;
        *(int *)&((struct Obj00170 *)p)->f118 = 17;
        if (((struct Obj00170 *)p)->fE8) {
            func_0201FEF4(((struct Obj00170 *)p)->fE8);
            ((struct Obj00170 *)p)->fE8 = 0;
        }
        return 2;
    case 2: case 3: case 4:
        if (state < obj->previous)
            ((struct Obj23738 *)(*(u8 * *)&((struct Obj00170 *)p)->f10))->f2C = (unsigned)func_021841A4(func_021DCF50(p));
        break;
    case 5: break;
    }
    obj->previous = func_021DE354(p);
    return 1;
}










u32 func_021DE7F4(void) { return func_020362DC(); }









int func_021DE7FC(void *obj,int unused,u8 *q)
{
    u8 *p,*s;
    void *r;
    int i,n,player;
    func_0203D7B0(1);
    func_0203064C(1,114,0x80000);
    p=func_0203159C(obj,0xdac,114);
    i=0;
    func_02082BCC(p,0,0xdac);
    *(u8 * *)&((struct Obj08213 *)q)->f1C=p;
    *(u8 * *)&((struct Obj02208 *)p)->fD8=q;
    ((struct Obj02208 *)p)->fDC=((struct Obj08213 *)q)->f18;
    ((struct Obj02208 *)p)->f24=func_02012934(((struct Obj23740 *)(*(u8 * *)&((struct Obj23739 *)(*(u8 * *)&((struct Obj02208 *)p)->fD8))->f14))->f4);
    ((struct Obj02208 *)p)->fD58=func_020490F4(183,114);
    func_021DF800((char *)p);
    ((struct Obj02208 *)p)->fD9C=func_020056A0((void (*)(int,  void *))func_021DF7E8,p,1);
    ((struct Obj02208 *)p)->fAF4=func_02047CFC(20,11,114);
    func_021E0640(p);func_021E06E0((char *)p);func_021E04E0(p);
    n=0;
    player=func_02039338();
    s=p+0xe0;
    q=*(u8 * *)&((struct Obj02208 *)p)->fD8;
    for(;i<5;i++) {
        if(((struct Obj08213 *)q)->fC&(1<<i)) {if(i==player) break;n++;}
    }
    ((struct Obj23741 *)s)->f40=d_021E1FA0[((struct Obj08213 *)q)->f8][n]<<12;
    r=func_02030734(0x8072,func_02030CB0(32),0,d_021E22B8,0x4ec);
    ((struct Obj02208 *)p)->fD94=r;
    ((struct Obj02208 *)p)->fD98=func_02030CBC(32,r);
    func_021E0DE8((char *)p);func_021E0F20((char *)p);func_021E104C((char *)p);func_021E11B4((char *)p);func_021E13BC((char *)p);func_021E1488((char *)p);
    func_0202208C(0,1,1,0,8,1,114);
    func_0203D7BC(1);
    return 1;
}








int func_021DE960(struct S020315D4 *a, int b, int c, u8 *p)
{
    func_0201C6EC(*(struct PrintSys **)(p + 0xD38));
    func_0201C4C0(*(struct PrintSys **)(p + 0xD38));
    if (*(u8 **)(p + 0xDA8) != 0) func_0202F038(*(u8 **)(p + 0xDA8));
    func_021E0E1C(p);
    func_021E0F54(p);
    func_021E1080(p);
    func_021E11E4(p);
    func_021E13F0(p);
    func_021E14BC(p);
    func_02030DA4(*(void **)(p + 0xD98));
    func_020307B0(*(void **)(p + 0xD94));
    func_021E0678((char *)p);
    func_021E0554(p);
    func_021E073C((char *)p);
    func_02047E54(*(void **)(p + 0xAF4));
    func_02046788();
    func_021DF83C((char *)p);
    func_02030EAC(*(void **)(p + 0xD9C));
    func_02049238(*(void **)(p + 0xD58));
    func_020315D4(a);
    func_020306F0(0x72);
    func_020351A0(8);
    return 1;
}








extern int (*const d_021E217C[])(void *);








int func_021DEA0C(int a, int b, int c, u8 *p)
{
    int result;
    do { result = d_021E217C[*(int *)p](p); } while (result == 1);
    if (result == 2) return 1;
    func_021E0570(p);
    func_021E07A4((char *)p);
    func_021DF864(p);
    func_021DEA68((char *)p);
    func_02030D28(((struct Obj23742 *)p)->fD98);
    if (func_020221A4() && func_0200FB24()) return 1;
    return 0;
}








void func_021DEA68(char *p) { ((struct Obj14219 *)p)->f34=0;((struct Obj14219 *)p)->f3C=0; }









int func_021DEA70(u8 *p)
{
    func_021E0130(p, 0);
    ((struct Obj23743 *)p)->f0 = 1;
    return 0;
}








int func_021DEA84(u8 *p)
{
    if (func_020221A4()) {
        ((struct Obj08214 *)p)->f0 = func_02039338() == 0 ? 2 : 8;
        ((struct Obj08214 *)p)->fDA8 = func_0202EE30(((struct Obj08214 *)p)->fD98, ((struct Obj08214 *)p)->fCF0, 15, 16, 114);
        return 1;
    }
    return 0;
}








int func_021DEAC8(u8 *p)
{
    if (func_021E16D8((const char *)p)) {
        ((struct Obj10637 *)p)->f0 = 3;
        return 1;
    }
    return 0;
}







int func_021DEAE0(char *p) {u16 v=1;if(func_021DCBC4(((struct Obj14220 *)p)->fDC,0x2805,&v,2)==1){((struct Obj14220 *)p)->f0=4;return 1;}return 0;}








/*
 * extent: two trailing bytes of zero alignment padding.
 */
void *func_021DEB10(char *p) {return **(void ** *)&((struct Obj23744 *)(*(char * *)&((struct Obj01753 *)p)->fD8))->f14;}







int func_021DEB1C(char *p) {unsigned v;v=func_021E170C(p)+1;if(v!=func_021841A4(func_021DEB10(p)))return 0;((struct Obj01753 *)p)->f0=5;return 1;}







int func_021DEB40(char *p) {((struct Obj01753 *)p)->f30=func_021E170C(p)+1;if(func_021DCBC4(((struct Obj01753 *)p)->fDC,0x280A,p+48,4)==1){((struct Obj01753 *)p)->f14=0;((struct Obj01753 *)p)->f0=6;}return 0;}







int func_021DEB74(u8 *p)
{
    u16 buf[2];
    int i, count;
    u16 mask;
    if (((struct Obj02496 *)p)->f14 == 0) {
        buf[1] = 0; buf[0] = 0;
        if (func_021DCBC4(((struct Obj02496 *)p)->fDC, 10249, buf, 4) == 1) (((struct Obj02496 *)p)->f14)++;
        return 0;
    }
    i = 1;
    mask = ((struct Obj23746 *)(*(u8 * *)&((struct Obj02496 *)p)->fDC))->f42;
    for (count = 1; i < 5; i++) {
        if (mask & (1 << i)) {
            if (count >= ((struct Obj02496 *)p)->f14) {
                buf[1] = i; buf[0] = ((struct Obj02496 *)p)->f14;
                if (func_021DCBC4(((struct Obj02496 *)p)->fDC, 10249, buf, 4) == 1) (((struct Obj02496 *)p)->f14)++;
                break;
            }
            count++;
        }
    }
    if (((struct Obj02496 *)p)->f14 >= ((struct Obj02496 *)p)->f30) ((struct Obj02496 *)p)->f0 = 7;
    return 0;
}







int func_021DEC08(char *p) {u16 v=8;if(func_021DCBC4(((struct Obj14221 *)p)->fDC,0x2805,&v,2)==1)((struct Obj14221 *)p)->f0=10;return 0;}






int func_021DEC38(char *p) {if(func_021DCBC4(((struct Obj10618 *)p)->fDC,0x2806,0,0)==1){((struct Obj10618 *)p)->f0=9;((struct Obj10618 *)p)->f10=0;return 0;}return 0;}






int func_021DEC64(char *p) {if(func_021E16C4(p,8)==1){((struct Obj01753 *)p)->f30=func_021E170C(p)+1;((struct Obj01753 *)p)->f0=10;}return 0;}






int func_021DEC84(char *p) {void *v;v=func_020399A8();func_0202F038(((struct Obj10619 *)p)->fDA8);((struct Obj10619 *)p)->fDA8=0;func_02039C68(v,202,40);((struct Obj10619 *)p)->f0=11;return 0;}






int func_021DECB0(char *p) {if(func_02039CB4((struct Link *)func_020399A8(),202,40))((struct Obj23747 *)p)->f0=12;return 0;}






int func_021DECCC(char *p) {if(func_021DCBC4(((struct Obj10620 *)p)->fDC,0x280B,*(char * *)&((struct Obj10620 *)p)->fD8+4,4))((struct Obj10620 *)p)->f0=13;return 0;}






int func_021DECF4(u8 *p)
{
    void *q;
    q = func_020399A8();
    if ((int)func_0203D4D0((u32)q, (u8)((int)func_021841A0(func_021DEB10((char *)p))), (int)10255, (int)1428, (u32)(((struct Obj01753 *)p)->f24), (int)1, (int)1, (int)1))
        ((struct Obj01753 *)p)->f0 = 14;
    return 0;
}






int func_021DED3C(u8 *p)
{
    if (((struct Obj03304 *)p)->f30 == func_021E17EC((char *)p)) {
        if (func_021E1910((char *)p) == 1) {
            func_021DCBC4(((struct Obj03304 *)p)->fDC, 10253, 0, 0);
            ((struct Obj03304 *)p)->f0 = 45;
        } else {
            func_021DCBC4(((struct Obj03304 *)p)->fDC, 10254, 0, 0);
            ((struct Obj03304 *)p)->f0 = 15;
        }
    }
    return 0;
}





int func_021DED88(char *p) {if(func_021E1974(p)==1)((struct Obj06536 *)p)->f0=45;else if(((struct Obj06536 *)p)->f30==func_021E1954(p))((struct Obj06536 *)p)->f0=16;return 0;}





int func_021DEDAC(Obj_021DED88 *obj)
{
    u8 *p = (u8 *)obj;
    u8 *q;
    int i, count;
    q = (u8 *)func_021E16AC((char *)p, 24);
    ((struct Obj08215 *)q)->f10 = ((struct Obj02869 *)p)->f2C;
    count = ((struct Obj02869 *)p)->f30;
    ((struct Obj08215 *)q)->f14 = count;
    ((struct Obj08215 *)q)->f4 = d_021E1FA0[count][((struct Obj02869 *)p)->f2C];
    for (i = 0; i < 5; i++) {
        if (func_021E1768((char *)p, i)) {
            obj->slots[i] = func_02184180(func_021DEB10((char *)p), (u8)i);
            func_02008500(obj->slots[i], obj->other[i]);
        }
    }
    func_021DEF6C((Obj_021DED88 *)p);
    ((struct Obj02869 *)p)->f120 = ((struct Obj08215 *)q)->f4 << 12;
    ((struct Obj02869 *)p)->f0 = 17;
    func_02005D90(1157, 65535);
    ((struct Obj23749 *)(*(u8 * *)&((struct Obj23748 *)(*(u8 * *)&((struct Obj02869 *)p)->fD8))->f14))->f14 = 1;
    func_021E0304(p);
    return 1;
}





/*
 * extent: unlabelled follower at 021DEED8, filed separately.
 * lever: raw unsigned byte-table address and a named row byte offset restore r6.
 */
int func_021DEE4C(char *p)
{
    int *r;
    int value, a, row;
    if (--((struct Obj06537 *)p)->fC>0) return 0;
    ((struct Obj06537 *)p)->fC=15;
    r=(int *)func_021E16C0(p);
    row=r[5]*10;
    value=*(const u16 *)((unsigned)d_021E1FDC+row+r[4]*2);
    a=*(u16 *)(p+0x7e + r[4]*4);
    *(u16 *)(p+0x60+r[4]*2)=value;
    func_021E0C08(p,a,r[4],r[0],value,r[1],(int *)(p+0x2e0+r[4]*0xb4));
    r[4]++;
    r[4]%=r[5];
    if (++r[0]==r[5]) {
        ((struct Obj06537 *)p)->fC=0;
        ((struct Obj06537 *)p)->f0=18;
    }
    return 0;
}





int func_021DEED8(char *p)
{
    char *q=p+0x1a0;
    int i,n,count;
    count=((struct Obj14222 *)p)->f30;
    i=0;
    n=0;
    do {
        if (*(int *)(q+i*0xb4+0x148)==1) n++;
        i++;
    } while(i<count);
    if (n==count) {((struct Obj14222 *)p)->f0=19;return 1;}
    return 0;
}




int func_021DEF14(char *p) {if(++((struct Obj08216 *)p)->fC>30){((struct Obj08216 *)p)->fC=0;if(func_02039338()==0)((struct Obj08216 *)p)->f0=20;else ((struct Obj08216 *)p)->f0=21;}return 0;}




int func_021DEF3C(u8 *p) { u16 buf; buf=4; if(func_021DCBC4(((struct Obj14223 *)p)->fDC,0x2805,&buf,2)==1) ((struct Obj14223 *)p)->f0=22; return 0; }




void func_021DEF6C(Obj_021DED88 *obj)
{
    u8 *p = (u8 *)obj;
    void *q;
    int i;
    q = func_0200ED48(func_02012EBC(((struct Obj23751 *)(*(u8 * *)&((struct Obj23750 *)(*(u8 * *)&((struct Obj10621 *)p)->fD8))->f14))->f4));
    for (i = 0; i < 5; i++) {
        if (obj->slots[i] && i != func_02039338())
            func_0200ED54(q, func_02008530(obj->slots[i]));
    }
}




/*
 * trailing: Two zero alignment bytes.
 */
int func_021DEFB4(char *p) { if(func_021E16C4(p,4)==1) { ((struct Obj01753 *)p)->f0=22; return 1; } return 0; }







int func_021DEFD0(int *p) { func_02039C68((struct Link *)func_020399A8(),203,40); *p=23; return 0; }







int func_021DEFE8(int *p) { if(func_02039CB4((struct Link *)func_020399A8(),203,40)) *p=24; return 0; }







int func_021DF004(char *p) { func_021E1584(p,1); func_021E129C(p); ((struct Obj02209 *)p)->f0=25; return 0; }







int func_021DF01C(u8 *p) { int i; ((struct Obj06538 *)p)->fC+=1; if(((struct Obj06538 *)p)->fC<95) return 0; for(i=0;i<((struct Obj06538 *)p)->f30;i++) func_021E0478(p,i); ((struct Obj06538 *)p)->fC=0; ((struct Obj06538 *)p)->f0=26; return 0; }








int func_021DF050(u8 *p)
{
    func_02039338();
    ((struct Obj23754 *)p)->f0 = 0x1b;
    return 0;
}







int func_021DF060(char *p)
{
    char *s;
    Msg msg;
    int state,i,rate;
    state=func_021E161C(p);
    if(state==1 && func_021E1210(p)==0 && ((struct Obj01415 *)p)->f5C==0) ((struct Obj01415 *)p)->f20=1;
    if(((struct Obj01415 *)p)->f6A==1) {((struct Obj01415 *)p)->f0=28;return 1;}
    if(state==0) {
        if(((struct Obj01415 *)p)->f34 && func_021E1210(p)==0) func_021E11F4(p);
        if(func_021E1400(p)==0 && func_021E04C4(p)==1) {
            if(func_021E1210(p)==0) ((struct Obj01415 *)p)->f38=1;
            func_021E140C(p);
        }
        if(((struct Obj01415 *)p)->f38) {
            if(func_021DCBC4(((struct Obj23755 *)(*(char * *)&((struct Obj01415 *)p)->fD8))->f18,0x2807,p+0x38,1)==1) ((struct Obj01415 *)p)->f38=0;
        }
    }
    s=p+0xe0;
    if(func_02039338()==0) {
        if(((struct Obj01415 *)p)->f8<300) {
            ((struct Obj05429 *)s)->f48+=95;
            if(((struct Obj05429 *)s)->f48>=0x7000) ((struct Obj05429 *)s)->f48=0x7000;
        } else {
            ((struct Obj05429 *)s)->f48-=95;
            if(((struct Obj05429 *)s)->f48<0x4000) ((struct Obj05429 *)s)->f48=0x4000;
        }
    }
    if(func_02039338()==0) {
        msg.a=((struct Obj01415 *)p)->f11C;
        msg.flag=((struct Obj01415 *)p)->f20;
        msg.b=((struct Obj01415 *)p)->f33C;
        for(i=0;i<((struct Obj01415 *)p)->f30;i++) msg.values[i]=*(int *)(p+i*0xb4+0x2fc)/4096;
        func_021DCBC4(((struct Obj01415 *)p)->fDC,0x2808,&msg,20);
    }
    if(func_02039338()==0) {
        rate=((struct Obj01415 *)p)->f128;
        if(func_021E1204(p)==1) func_021E0634((u8 *)(p+0xe0),rate*2);
        else func_021E1604(p,rate);
    }
    return 0;
}







int func_021DF1C4(u8 *p)
{
    func_021E1584((char *)p, 0);
    *(u8 * *)&((struct Obj02209 *)p)->f28 = func_021E0A44((Obj *)p);
    if (func_02039338() == 0) {
        if (((struct Obj23756 *)(*(u8 * *)&((struct Obj02209 *)p)->f28))->fC == func_02039338())
            ((struct Obj02209 *)p)->f0 = 29;
        else
            ((struct Obj02209 *)p)->f0 = 30;
    } else {
        ((struct Obj02209 *)p)->f0 = 31;
    }
    func_020061E4(1833);
    return 1;
}







int func_021DF204(char *p) { func_021E19C0(p,0x4000); *(u8 * *)&((struct Obj04542 *)p)->f28=func_021E0A44((Obj *)p); if(((struct Obj23757 *)(*(u8 * *)&((struct Obj04542 *)p)->f28))->fC!=func_02039338()) ((struct Obj04542 *)p)->f0=30; return 0; }







#pragma opt_propagation off







/*
 * note 2026-10-05 (wave P17 L7, final push G6L7): DIFF 26/116, obj/step/target colour
 * rotation and index load order; about 60 forms tried (see git history of the pending copy).
 *
 * pass 2 2026-10-06 P2L39: EXACT in --lang c99 and --lang c. Under #pragma opt_propagation
 * off, all locals declared at the top (target before step), with step assigned before
 * target: this gives obj r6, step r5, target r4. A named table pointer local assigned first
 * keeps the table load live across the multiply (table r4), which lets count be a named
 * local without a copy before muls. The reads in the order index, selected, count, angle
 * give the low colours (angle r1, count r2, index r3).
 */
int func_021DF22C(Obj_021DF22C *obj)
{
    Selected *sel;
    int current, index, count;
    int target, step;
    int angle, delta;
    const u16 (*table)[5];
    table = d_021E1FDC;
    index = obj->index;
    sel = obj->selected;
    count = obj->count;
    current = sel->angle;
    step = 0x4000;
    target = table[count][index] << 12;
    angle = current;
    delta = target - current;
    if (delta < 0) delta = target + 0x168000 - current;
    if (delta <= 0x10000) step >>= 1;
    if (delta < step) step = delta;
    func_021E19C0((char *)obj, step);
    func_021E15DC(&angle, step);
    if (angle / 4096 == target / 4096) obj->state = 31;
    return 0;
}







#pragma opt_propagation reset







int func_021DF2A0(int *p) { func_02039C68((struct Link *)func_020399A8(),204,40); *p=32; return 0; }







int func_021DF2B8(int *p) { if(func_02039CB4((struct Link *)func_020399A8(),204,40)) { if(func_02039338()==0) *p=33; else *p=34; } return 0; }







int func_021DF2E0(Obj_021DF2E0 *obj)
{
    u8 *p = (u8 *)obj;
    struct { u16 angle, mask, entries[6]; } buf;
    int i;
    u8 *q;
    buf.angle = ((struct Obj02497 *)p)->f58 / 4096;
    ((struct Obj02497 *)p)->f1C = 0;
    for (i = 0; i < ((struct Obj02497 *)p)->f30; i++) {
        q = p + 0x2e0 + i * 180;
        {
        int angle;
        angle = obj->angles[i];
        buf.entries[((struct Obj14225 *)q)->f10] = angle;
        if (func_021E1830((char *)p, angle << 12, ((struct Obj02497 *)p)->f30) == 1)
            ((struct Obj02497 *)p)->f1C |= 1 << ((struct Obj14225 *)q)->fC;
        }
    }
    buf.mask = ((struct Obj02497 *)p)->f1C;
    if (func_021DCBC4(((struct Obj02497 *)p)->fDC, 10252, &buf, 16) == 1) ((struct Obj02497 *)p)->f0 = 35;
    return 0;
}







int func_021DF370(u8 *p)
{
    int i;
    u8 *entry;
    u16 *values;
    if (((struct Obj04539 *)p)->f40 == 1) {
        values = (u16 *)(p + 108);
        ((struct Obj04539 *)p)->f11C = values[0] << 12;
        ((struct Obj04539 *)p)->f58 = values[0] << 12;
        for (i = 0; i < ((struct Obj04539 *)p)->f30; i++) {
            entry = p + 736 + i * 180;
            ((struct Obj10622 *)entry)->f1C = values[((struct Obj10622 *)entry)->f10 + 2] << 12;
            *(u16 *)(p + 96 + i * 2) = values[((struct Obj10622 *)entry)->f10 + 2];
        }
        ((struct Obj04539 *)p)->f1C = values[1];
        func_021E0570(p);
        func_021E07A4((char *)p);
        *(u8 * *)&((struct Obj04539 *)p)->f28 = func_021E0A44((Obj *)p);
        ((struct Obj04539 *)p)->f0 = 35;
    }
    return 0;
}







int func_021DF3E8(u8 *p)
{
    int index, i, count, selected;
    index = (*(int **)(p + 40))[4];
    ((struct Obj06540 *)p)->f5C = 0;
    for (i = 0; i < ((struct Obj06540 *)p)->f30; i++) {
        selected = *(int *)(p + 748 + index * 180);
        func_021E0450(p, (void *)(*(int *)(p + 164 + selected * 4)), i, selected);
        count = ((struct Obj06540 *)p)->f30;
        index = (index + 1) % count;
    }
    ((struct Obj06540 *)p)->fC = 0;
    ((struct Obj06540 *)p)->f0 = 36;
    return 0;
}







int func_021DF434(u8 *p)
{
    int i;
    ((struct Obj06541 *)p)->fC += 1;
    if (((struct Obj06541 *)p)->fC < 120) return 0;
    ((struct Obj06541 *)p)->fC = 0;
    for (i = 0; i < ((struct Obj06541 *)p)->f30; i++) func_021E0478(p, i);
    func_021E01B0(p, 2, (void *)(*(int *)(p + 144 + 4 * (*(int **)(p + 40))[3])));
    func_021E1988(1302);
    ((struct Obj06541 *)p)->f0 = 37;
    return 0;
}







int func_021DF488(u8 *p) { if(((struct Obj08217 *)p)->fC<120) ((struct Obj08217 *)p)->fC+=1; else if(!func_021E19A4()) { ((struct Obj08217 *)p)->fC=0; ((struct Obj08217 *)p)->f0=38; } return 0; }







/*
 * lever: Mutable range table is reloaded after RNG; updating low in place preserves r4/r5 colouring.
 */
int func_021DF4AC(u8 *p)
{
    u32 low, high, value;
    int count;
    func_021E14E4((const char *)p);
    if ((((struct Obj05430 *)p)->f1C & (1 << (*(int **)(p + 40))[3])) == 0) {
        ((struct Obj05430 *)p)->f0 = 42;
        return 0;
    }
    count = ((struct Obj05430 *)p)->f30;
    low = d_021E1F34[count].low;
    high = d_021E1F34[count].high;
    low += func_020056EC(65535) % (high - low + 1);
    if (low < d_021E1F34[count].low) low = d_021E1F34[count].low;
    else if (low > high) low = high;
    func_021E026C(p, 3, low);
    value = func_02007E50(func_0201292C((((struct Obj23760 *)(*(u8 * *)&((struct Obj23759 *)(*(u8 * *)&((struct Obj05430 *)p)->fD8))->f14))->f4)), low, 1, 114);
    func_021E1988(1302);
    if (value == 1) ((struct Obj05430 *)p)->f0 = 39;
    else ((struct Obj05430 *)p)->f0 = 40;
    return 0;
}







int func_021DF548(u8 *p) { if(((struct Obj08218 *)p)->fC<180) ((struct Obj08218 *)p)->fC+=1; if(!func_021E19A4()) { ((struct Obj08218 *)p)->fC=0; ((struct Obj08218 *)p)->f0=42; } return 0; }







int func_021DF56C(u8 *p)
{
    if (((struct Obj08219 *)p)->fC < 180) {
        ((struct Obj08219 *)p)->fC += 1;
    } else if (func_021E19A4() == 0) {
        ((struct Obj08219 *)p)->fC = 0;
        ((struct Obj08219 *)p)->f0 = 41;
        func_021E0130(p, 4);
    }
    return 0;
}







int func_021DF598(u8 *p)
{
    if (((struct Obj08220 *)p)->fC < 180) {
        ((struct Obj08220 *)p)->fC += 1;
    } else {
        ((struct Obj08220 *)p)->fC = 0;
        ((struct Obj08220 *)p)->f0 = 42;
    }
    return 0;
}







int func_021DF5B0(u8 *p) { struct Link *link; link=(struct Link *)func_020399A8(); func_02008DF0(*(struct Sub02008C20Obj * *)&((struct Obj23762 *)(*(u8 * *)&((struct Obj23761 *)(*(u8 * *)&((struct Obj14226 *)p)->fD8))->f14))->f10,90); func_021E0130(p,11); func_02039C68(link,205,40); ((struct Obj14226 *)p)->f0=43; func_0203516C(8); return 0; }







int func_021DF5EC(u8 *p)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 205, 40)) {
        func_021E1784((char *)p, (*(int **)(p + 40))[3]);
        ((struct Obj05431 *)p)->fDA0 = func_0201088C(114, (*(unsigned **)(*(u8 * *)&((struct Obj05431 *)p)->fD8 + 20))[1]);
        ((struct Obj05431 *)p)->fDA8 = func_0202EE30(((struct Obj05431 *)p)->fD98, ((struct Obj05431 *)p)->fCF0, 15, 16, 114);
        ((struct Obj05431 *)p)->f0 = 44;
    }
    return 0;
}







/*
 *   extern void func_020307B0(void *);
 *   void func_02010934(void *p) { func_020307B0(p); }
 * tail: 021DF6A2..021DF6A4 is two zero alignment bytes.
 */
int func_021DF648(u8 *p)
{
    int ready;
    ready = func_02010904(*(void **)(p + 3488));
    if (func_0200FB24()) {
        func_0200FBB0();
        func_0200F7B8(1);
        func_0202223C(0, 0);
        func_0202223C(1, 0);
        return 0;
    }
    if (ready) {
        func_0202F038(*(void **)(p + 3496));
        *(void **)(p + 3496) = 0;
        func_02010934(*(void **)(p + 3488));
        *(int *)p = 47;
    }
    return 0;
}







int func_021DF6A4(u8 *p){func_021E0130(p,12);((struct Obj23763 *)p)->f0=46;return 0;}







/*
 * follower: unlabelled timer inside handed 021DF6A4 extent, followed by 2-byte zero padding.
 */
int func_021DF6B8(char *p){if(++((struct Obj10623 *)p)->fC>=180){((struct Obj10623 *)p)->fC=0;((struct Obj10623 *)p)->f0=47;return 1;}return 0;}







int func_021DF6D4(u8 *p){void *ctx=func_020399A8();if(!((struct Obj14227 *)p)->f18)func_02039C68(ctx,206,40);func_021E0130(p,10);((struct Obj14227 *)p)->f0=48;return 0;}







int func_021DF6FC(u8 *p)
{
    void *ctx;
    ctx = func_020399A8();
    if (((struct Obj03305 *)p)->f18 == 0) {
        if (func_02039CB4(ctx, 206, 40)) {
            ((struct Obj03305 *)p)->fDA8 = func_0202EE30(((struct Obj03305 *)p)->fD98, ((struct Obj03305 *)p)->fCF0, 15, 16, 114);
            func_0203D7BC(0);
            func_0203A5E4(10240);
            func_02184174(func_021DEB10((char *)p));
            ((struct Obj03305 *)p)->f0 = 49;
        }
    } else {
        ((struct Obj03305 *)p)->fC += 1;
        if (((struct Obj03305 *)p)->fC >= 180) {
            ((struct Obj03305 *)p)->fC = 0;
            if ((*(int **)(p + 220))[15] == 0) func_0203D7B0(0);
            ((struct Obj03305 *)p)->f0 = 49;
        }
    }
    return 0;
}







int func_021DF778(char *p){if(func_0218417C(func_021DEB10(p))){func_0202F038(((struct Obj10624 *)p)->fDA8);((struct Obj10624 *)p)->fDA8=0;((struct Obj10624 *)p)->f0=50;return 1;}return 0;}







int func_021DF7A4(int *p){func_0202208C((void *)2,0,0,0,8,1,114);*p=51;return 0;}







int func_021DF7CC(int *p){if(func_020221A4()){*p=52;return 1;}return 0;}







int func_021DF7E4(void){return 2;}







void func_021DF7E8(void *arg,char *p){func_02021D50(*(struct S02021D50 * *)&((struct Obj23766 *)p)->fD78);func_0204A648();func_020419E4();}







void func_021DF800(char *p){func_021DF984(p);func_021DFAD8((u8 *)p);func_021DFB60(p);func_021DFEC4(p);func_021DFF44((u8 *)p);func_021DFC74(p);func_021DFFF8((u8 *)p);func_021DFF70((u8 *)p);func_021DF998(p);}







void func_021DF83C(char *p){func_021DFA14(p);func_021DFFC8((u8 *)p);func_021E00D4((u8 *)p);func_021DFE40(p);func_021DFEFC(p);func_021E04B4((u8 *)p);}







/*
 * omits func_02048B6C from function: and its shard. tu --suggest-split leaves caller OUT.
 * typedef unsigned int u32;
 * void func_02048B6C(char *p,const u32 *in) {*(u32 *)(p+0x18)=*in;}
 */
void func_021DF864(u8 *p)
{
    u32 flags=0x1000000;
    void *r;
    int i;
    func_02048B6C(*(void **)(p+0xd54),&flags);
    func_02047964();
    func_02048AD0(*(void **)(p+0xd54));
    func_020479D8();
    func_0206AA3C(0,0,-4096,0);
    func_0206AA78(0,0x7fff);
    func_0206AA8C(0x7fff,0x7fff,0);
    func_0206AAB0(0x7fff,0x7fff,0);
    func_021E0698(p);func_021E05D4(p);func_021E0848(p);
    func_02047970();func_0204A600();
    func_0201C4E4(*(void **)(p+0xd38));
    r=*(void **)(p+0xd38);
    if(*(u8 *)(p+0xd0c)) {
        if(!func_0201C6C4(r,func_02045770(*(void **)(p+0xd08)))) {
            func_02045334(*(void **)(p+0xd08));
            *(u8 *)(p+0xd0c)=0;
        }
    }
    for(i=0;i<5;i++) {
        r=*(void **)(p+0xd38);
        if(*(u8 *)(p+i*8+0xd14)) {
            if(!func_0201C6C4(r,func_02045770(*(void **)(p+i*8+0xd10)))) {
                func_02045334(*(void **)(p+i*8+0xd10));
                *(u8 *)(p+i*8+0xd14)=0;
            }
        }
    }
    if(*(void **)(p+0xda8)) func_0202F0B0(*(void **)(p+0xda8));
}







void func_021DF984(char *p){func_020433E0(&d_021E1EA4);func_02045088(114);}







static inline void G2_SetBG0Priority(int priority)
{
    *(volatile u16 *)0x04000008 = (u16)((*(volatile u16 *)0x04000008 & ~3) | priority);
}







/*
 * volatile: BG0CNT 0x04000008 read at 021DF9F2, written 021DF9FC.
 */
void func_021DF998(char *a0)
{
    func_02040588(0, 1);
    func_02040588(1, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 1);
    func_02040588(7, 1);
    func_020434DC(16, 1);
    func_02043598(16, 1);
    G2_SetBG0Priority(1);
    func_0207D63C(0x04000050, 4, 40, 11, 10);
}







void func_021DFA14(char *a0)
{
    func_02040588(0, 0);
    func_02040588(1, 0);
    func_02040588(2, 0);
    func_02040588(3, 0);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 0);
    func_02040588(7, 0);
    func_020434DC(16, 0);
    func_02043598(16, 0);
}







static inline void G3X_SetShading(GXShading shading)
{
    DISP3D = (u16)((DISP3D & ~(2 | 0x1000 | 0x2000)) | (shading << 1));
}







static inline void G3X_AntiAlias(int enable)
{
    if (enable) DISP3D = (u16)((DISP3D & ~0x3000) | 16);
    else DISP3D &= (u16)~0x3010;
}







static inline void G3X_AlphaTest(int enable, int ref)
{
    if (enable) {
        DISP3D = (u16)((DISP3D & ~0x3000) | 4);
        *(volatile u16 *)0x04000340 = (u16)ref;
    } else DISP3D &= (u16)~0x3004;
}







static inline void G3X_AlphaBlend(int enable)
{
    if (enable) DISP3D = (u16)((DISP3D & ~0x3000) | 8);
    else DISP3D &= (u16)~0x3008;
}







static inline void G3X_EdgeMarking(int enable)
{
    if (enable) DISP3D = (u16)((DISP3D & ~0x3000) | 32);
    else DISP3D &= (u16)~0x3020;
}







/*
 * volatile: DISP3DCNT 0x04000060 re-read at 021DFA70,76,82,8A,96; GXSTAT written 021DFABA.
 */
void func_021DFA68(void)
{
    G3X_SetShading(GX_SHADING_TOON);
    G3X_AntiAlias(1);
    G3X_AlphaTest(0, 0);
    G3X_AlphaBlend(1);
    G3X_EdgeMarking(1);
    func_0207DCF8(d_021E1D90);
    func_0207DD24(0x7fff, 0, 0x7fff, 63, 0);
    *(volatile u32 *)0x04000580 = 0xbfff0000;
}







void func_021DFAD8(u8 *p)
{
    u8 *section;
    Vec3 position;
    section = p + 3392;
    func_02046440(0, 1, 0, 1, 0, 114, func_021DFA68);
    func_02046BE0(0, 0);
    position = d_021E2020;
    ((struct Obj14228 *)section)->f14 = func_02048A24(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 4096, 0x400000, 0, &d_021E1D00, &position, &d_021E1D0C, 114);
    func_02048AD0(((struct Obj14228 *)section)->f14);
}







/*
 * volatile: 021DFB6E reads and 021DFB76 writes hardware register 04000304
 */
void func_021DFB60(char *a0)
{
    func_0203F8F4(114);
    *(volatile u16 *)0x04000304 |= 0x8000;
    {struct DispConfig_021DEFD0 t=d_021E202C; func_0203FC28((struct DispConfig_021DD1E0 *)&t);}
    {struct BgTemplate_021DEFD0 t=d_021E204C; func_0203FCA0(1, (const struct BgTemplate_021DD1E0 *)&t, 0); func_020414EC(1); func_02040B94(1,32,0,114);}
    {struct BgTemplate_021DEFD0 t=d_021E206C; func_0203FCA0(2, (const struct BgTemplate_021DD1E0 *)&t, 0); func_020414EC(2);}
    {struct BgTemplate_021DEFD0 t=d_021E208C; func_0203FCA0(3, (const struct BgTemplate_021DD1E0 *)&t, 0); func_020414EC(3);}
    {struct BgTemplate_021DEFD0 t=d_021E20AC; func_0203FCA0(6, (const struct BgTemplate_021DD1E0 *)&t, 0); func_020414EC(6);}
    {struct BgTemplate_021DEFD0 t=d_021E20CC; func_0203FCA0(7, (const struct BgTemplate_021DD1E0 *)&t, 0); func_020414EC(7);}
}







void func_021DFC74(char *p)
{
    void *buf;
    u8 *data;
    buf=func_021E1634(p,17,0);
    func_02062A98(buf,(void **)(p+0xd64));
    func_020215BC(((struct Obj00835 *)p)->fD78,((struct Obj23767 *)(*(u8 * *)&((struct Obj00835 *)p)->fD64))->fC,0,0,64);
    func_020307B0(buf);
    buf=func_021E1634(p,20,0);
    func_02062A98(buf,(void **)(p+0xd64));
    func_020215BC(((struct Obj00835 *)p)->fD78,((struct Obj23768 *)(*(u8 * *)&((struct Obj00835 *)p)->fD64))->fC,1,0,64);
    func_020307B0(buf);
    func_02022004(*(u32 *)&((struct Obj00835 *)p)->fD78,1,65535,8,0);
    buf=func_021E1634(p,16,0);
    func_02062A00(buf,(void **)(p+0xd60));
    data=*(u8 * *)&((struct Obj00835 *)p)->fD60;
    func_02040B1C(3,((struct Obj02870 *)data)->f14,((struct Obj02870 *)data)->f10,0);
    func_020307B0(buf);
    buf=func_021E1634(p,22,0);
    func_02062A00(buf,(void **)(p+0xd60));
    data=*(u8 * *)&((struct Obj00835 *)p)->fD60;
    func_02040B1C(6,((struct Obj02870 *)data)->f14,((struct Obj02870 *)data)->f10,0);
    func_020307B0(buf);
    buf=func_021E1634(p,21,0);
    func_02062A00(buf,(void **)(p+0xd60));
    data=*(u8 * *)&((struct Obj00835 *)p)->fD60;
    func_02040B1C(7,((struct Obj02870 *)data)->f14,((struct Obj02870 *)data)->f10,0);
    func_020307B0(buf);
    buf=func_021E1634(p,19,0);
    func_02062B30(buf,(void **)(p+0xd5c));
    data=*(u8 * *)&((struct Obj00835 *)p)->fD5C;
    func_02040AE0(2,data+12,((struct Obj02870 *)data)->f8);
    func_020409B4(2);
    func_020307B0(buf);
    buf=func_021E1634(p,18,0);
    func_02062B30(buf,(void **)(p+0xd5c));
    data=*(u8 * *)&((struct Obj00835 *)p)->fD5C;
    func_02040AE0(3,data+12,((struct Obj02870 *)data)->f8);
    func_020409B4(3);
    func_020307B0(buf);
    buf=func_021E1634(p,24,0);
    func_02062B30(buf,(void **)(p+0xd5c));
    data=*(u8 * *)&((struct Obj00835 *)p)->fD5C;
    func_02040AE0(6,data+12,((struct Obj02870 *)data)->f8);
    func_020409B4(6);
    func_020307B0(buf);
    buf=func_021E1634(p,23,0);
    func_02062B30(buf,(void **)(p+0xd5c));
    data=*(u8 * *)&((struct Obj00835 *)p)->fD5C;
    func_02040AE0(7,data+12,((struct Obj02870 *)data)->f8);
    func_020409B4(7);
    func_020307B0(buf);
}







void func_021DFE40(char *p){func_020450C8();func_020403F4(1);func_020403F4(2);func_020403F4(3);func_020403F4(6);func_020403F4(7);func_0203F9B4();}







/*
 * followers: 021DFEA0,021DFEAC,021DFEB8 are pooled tail-call stubs; parent cleared ownership.
 */
void func_021DFE6C(u8 *p,int file)
{
    void *buf;
    u8 *screen;
    buf=func_021E1634((char *)p,file,0);
    func_02062B30(buf,(void **)(p+3420));
    screen=*(u8 * *)&((struct Obj23769 *)p)->fD5C;
    func_02040AE0(6,screen+12,((struct Obj23770 *)screen)->f8);
    func_020409B4(6);
    func_020307B0(buf);
}







void func_021DFEA0(u8 *p) { func_021DFE6C(p,26); }







void func_021DFEAC(u8 *p) { func_021DFE6C(p,24); }







void func_021DFEB8(u8 *p) { func_021DFE6C(p,25); }







void func_021DFEC4(char *p){*(struct PalAnmSlot * *)&((struct Obj00835 *)p)->fD78=func_02021518(114);func_02021EE4(*(struct PalAnmSlot * *)&((struct Obj00835 *)p)->fD78,1);func_0202155C(*(struct PalAnmSlot * *)&((struct Obj00835 *)p)->fD78,0,512,114);func_0202155C(*(struct PalAnmSlot * *)&((struct Obj00835 *)p)->fD78,1,512,114);}







void func_021DFEFC(char *p){func_020215A0(*(struct PalAnmSlot * *)&((struct Obj03842 *)p)->fD78,0);func_020215A0(*(struct PalAnmSlot * *)&((struct Obj03842 *)p)->fD78,1);func_02021540(*(struct PalAnmSlot * *)&((struct Obj03842 *)p)->fD78);}







void func_021DFF20(u8 *p,int a){func_02022004(((struct Obj23771 *)p)->fD78,1,65535,(u8)a,0);}







/*
 * blocking: ABS32 data d_020A1448 at +0x20 has no witness outside 021DFF44..021DFF70; ROM pool at021DFF64 is020A1448. Alignment-only data a4 hint already used; one recheck and tu --suggest-split remain MATCH with zero witnesses. Both ARM9 callees resolve matched.
 */
void func_021DFF44(u8 *p){func_0204A48C(&d_020A1448,0x021E1EA4,114);*(struct Bank **)(p+0xd68)=func_0204B100(30,1,114);}







void func_021DFF70(u8 *p)
{
    void *arc;
    arc = func_020490F4(184,114);
    ((struct Obj00835 *)p)->fD6C = func_0204A6C8(arc,6,0,0,114);
    ((struct Obj00835 *)p)->fD70 = func_0204ABF0(arc,0,0,0,114);
    ((struct Obj00835 *)p)->fD74 = func_0204AF28(arc,10,14,114);
    func_02049238(arc);
    func_0203D34C(1,114);
}







void func_021DFFC8(u8 *p){func_0204A8D4(((struct Obj03842 *)p)->fD6C);func_0204ADA4(((struct Obj03842 *)p)->fD70);func_0204AFD8(((struct Obj03842 *)p)->fD74);func_0204B1CC(*(struct Bank * *)&((struct Obj03842 *)p)->fD68);func_0204A5AC();}







void func_021DFFF8(u8 *p)
{
    int i;
    u8 *s=p+0xce0;
    func_0201F5BC(1,1,15,0,114);
    func_02021640(((struct Obj00835 *)p)->fD78,5,3,114,0,32,224);
    func_02021640(((struct Obj00835 *)p)->fD78,23,5,114,0,32,240);
    ((struct Obj03306 *)s)->f4=func_0201D7EC(23,0,0,0,114);
    ((struct Obj03306 *)s)->f8=func_02045B38(0,2,41,114);
    ((struct Obj03306 *)s)->fC=func_0201EC64(114);
    ((struct Obj03306 *)s)->f10=func_020450F0(1,2,19,26,4,15,1);
    ((struct Obj03306 *)s)->f5C=func_020457B0(256,114);
    for(i=0;i<5;i++) {*(void **)(p+0xa4+i*4)=func_020457B0(8,114);}
    ((struct Obj03306 *)s)->f28=((struct Obj03306 *)s)->f10;
    ((struct Obj03306 *)s)->f2C=0;
    ((struct Obj03306 *)s)->f58=func_0201C440((void *)114);
    func_021E0338(p,((struct Obj23772 *)(*(u8 * *)&((struct Obj00835 *)p)->fD8))->f8);
}







/*
 * extent: Two zero alignment bytes at 021E012E follow the 90-byte function.
 */
void func_021E00D4(u8 *p)
{
    u8 *s;
    void *obj;
    int i;
    s=p+3296;
    obj=((struct Obj05432 *)s)->f10;
    func_020456F8(obj);
    func_020409B4(func_02045730(obj));
    func_020452E8(((struct Obj05432 *)s)->f10);
    func_021E03A0(p);
    func_02045C04(((struct Obj05432 *)s)->f8);
    func_0201ED04(((struct Obj05432 *)s)->fC);
    func_0201D83C(((struct Obj05432 *)s)->f4);
    func_02045808(((struct Obj05432 *)s)->f5C);
    for(i=0;i<5;i++) func_02045808(*(void **)(p+164+i*4));
    func_020450C8();
}







void func_021E0130(u8 *p,int message)
{
    u8 *s;
    void *window,*owner,*data;
    s=p+3296;
    window=((struct Obj03843 *)s)->f10;
    func_02043B5C(func_02045770(window),15);
    func_0201F73C(window,2,1,14);
    func_02043B5C(func_02045770(window),15);
    func_02045CAC(((struct Obj03843 *)s)->f8,message,((struct Obj03843 *)s)->f5C);
    owner=((struct Obj03843 *)s)->f58;
    data=func_02045770(((struct Obj03843 *)s)->f28);
    func_0201C724(owner,(u32)data,0,0,(u32)(((struct Obj03843 *)s)->f5C),(u32)(((struct Obj03843 *)s)->f4),1088);
    ((struct Obj03843 *)s)->f2C=1;
    func_02045334(window);
    func_02045374(window);
    func_02041B6C(func_02045730(window));
}







void func_021E01B0(u8 *p,int message,void *value)
{
    u8 *s;
    void *window,*text,*owner,*data;
    s=p+3296;
    window=((struct Obj02498 *)s)->f10;
    func_0201F02C(((struct Obj02498 *)s)->fC,1,func_02184180(func_021DEB10((char *)p),(u8)func_02039338()));
    func_0201F02C(((struct Obj02498 *)s)->fC,2,value);
    text=func_020457B0(256,114);
    func_02045CAC(((struct Obj02498 *)s)->f8,message,text);
    func_0201F250(((struct Obj02498 *)s)->fC,((struct Obj02498 *)s)->f5C,text);
    func_02045808(text);
    func_0201F73C(window,2,1,14);
    func_02043B5C(func_02045770(window),15);
    owner=((struct Obj02498 *)s)->f58;
    data=func_02045770(((struct Obj02498 *)s)->f28);
    func_0201C724(owner,(u32)data,0,0,(u32)(((struct Obj02498 *)s)->f5C),(u32)(((struct Obj02498 *)s)->f4),1088);
    ((struct Obj02498 *)s)->f2C=1;
    func_02045334(window);
    func_02045374(window);
    func_02041B6C(func_02045730(window));
}







/*
 * extent: Two zero alignment bytes at 021E0302.
 */
void func_021E026C(u8 *p,int message,unsigned value)
{
    u8 *s;
    void *window,*text,*owner,*data;
    s=p+3296;
    window=((struct Obj02871 *)s)->f10;
    func_0201EF40(((struct Obj02871 *)s)->fC,0,value);
    text=func_020457B0(256,114);
    func_02045CAC(((struct Obj02871 *)s)->f8,message,text);
    func_0201F250(((struct Obj02871 *)s)->fC,((struct Obj02871 *)s)->f5C,text);
    func_02045808(text);
    func_0201F73C(window,2,1,14);
    func_02043B5C(func_02045770(window),15);
    owner=((struct Obj02871 *)s)->f58;
    data=func_02045770(((struct Obj02871 *)s)->f28);
    func_0201C724(owner,(u32)data,0,0,(u32)(((struct Obj02871 *)s)->f5C),(u32)(((struct Obj02871 *)s)->f4),1088);
    ((struct Obj02871 *)s)->f2C=1;
    func_02045334(window);
    func_02045374(window);
    func_02041B6C(func_02045730(window));
}







void func_021E0304(u8 *p){struct Descriptor *w=*(struct Descriptor * *)&((struct Obj02869 *)p)->fCF0;func_0201F7A8(w,0);func_02043B5C(func_02045770(w),0);func_02045334(w);func_02045374((struct Cfg *)w);func_02041B6C(func_02045730(w));}







/*
 * lever: Store the call result directly into its slot, then reuse that slot; declare counter before section base.
 */
void func_021E0338(u8 *p,int count)
{
    int i;
    u8 *s;
    const Desc *table;
    u32 obj;
    u32 *slot;
    const Desc *entry;
    s=p+3296;
    i=0;
    table=d_021E1E30[count];
    ((struct Obj23773 *)s)->f0=count;
    for(;i<count;i++) {
        entry=&table[i];
        slot=(u32 *)(s+i*4);
        slot[5]=func_020450F0((u8)entry->layer,entry->a,entry->b,entry->c,entry->d,entry->e,1);
        obj=slot[5];
        *(u32 *)(s+48+i*8)=obj;
        *(u8 *)(s+52+i*8)=0;
    }
}







void func_021E03A0(u8 *p){int i;u8 *s=p+0xce0;for(i=0;i<((struct Obj23774 *)s)->f0;i++){u8 *q=s+(u32)i*4;struct Descriptor *w=*(struct Descriptor * *)&((struct Obj14230 *)q)->f14;func_020456F8(w);func_020409B4(func_02045730(w));func_020452E8(*(struct Descriptor * *)&((struct Obj14230 *)q)->f14);}}







void func_021E03D8(u8 *p,void *text,int index,int color)
{
    u8 *s;
    void *window,*owner,*data;
    s=p+3296;
    window=*(void **)(s+20+index*4);
    func_0201F73C(window,2,1,14);
    func_02043B5C(func_02045770(window),15);
    owner=((struct Obj14231 *)s)->f58;
    data=func_02045770(*(void **)(s+48+index*8));
    func_0201C724(owner,(u32)data,4,1,(u32)text,(u32)(((struct Obj14231 *)s)->f4),color);
    *(u8 *)(s+52+index*8)=1;
    func_02045334(window);
    func_02045374(window);
    func_02041B6C(func_02045730(window));
}







void func_021E0450(u8 *p,void *text,int index,int a){int c=0x440;if(a==func_02039338())c=0xc80;func_021E03D8(p,text,index,c);}







void func_021E0478(u8 *p,u32 i){struct Descriptor *w=*(struct Descriptor **)(p+i*4+0xcf4);func_0201F7A8(w,0);func_02043B5C(func_02045770(w),0);func_02045334(w);func_02045374((struct Cfg *)w);func_02041B6C(func_02045730(w));}






void func_021E04B4(u8 *p){func_02048AC4(((struct Obj03842 *)p)->fD54);}






int func_021E04C4(char *a0){if(func_02035C08(d_021E1CB0)!=-1)return 1;return 0;}






/*
 * lever: Enum zero preserves its early definition; halfword stores use literal zero to avoid truncation.
 */
void func_021E04E0(u8 *p)
{
    int index;
    enum { ZERO } zero;
    u8 *s;
    index=((struct Obj23775 *)(*(u8 * *)&((struct Obj10625 *)p)->fD8))->f8;
    s=p+224;
    ((struct Obj02499 *)s)->fBC=func_02047E88(((struct Obj10625 *)p)->fAF4,&d_021E20EC[index-2]);
    zero=0;
    ((struct Obj02499 *)s)->f44=d_021E1DE8[index];
    ((struct Obj02499 *)s)->f18=4096;
    ((struct Obj02499 *)s)->f1C=4096;
    ((struct Obj02499 *)s)->f20=4096;
    ((struct Obj02499 *)s)->f4C=0;
    ((struct Obj02499 *)s)->f4E=0;
    ((struct Obj02499 *)s)->f50=0;
    ((struct Obj02499 *)s)->f3C=zero;
    ((struct Obj10625 *)p)->fE0=zero;
    ((struct Obj02499 *)s)->f4=-147456;
    ((struct Obj02499 *)s)->f8=zero;
    *(Vec *)(s+12)=*(Vec *)s;
}






void func_021E0554(u8 *p){func_020480E4(*(struct Ctx * *)&((struct Obj14232 *)p)->fAF4,(u16)(((struct Obj14232 *)p)->f19C));}






void func_021E0570(u8 *p)
{
    u8 *s;
    int angle;
    s=p+224;
    angle=((struct Obj14233 *)p)->f58;
    func_021E15DC(&angle,((struct Obj01754 *)s)->f40);
    func_021E15DC(&angle,((struct Obj01754 *)s)->f44);
    ((struct Obj01754 *)s)->f4E=(360-angle/4096)%360;
    ((struct Obj01754 *)s)->fC=((struct Obj14233 *)p)->fE0+((struct Obj01754 *)s)->f30+((struct Obj01754 *)s)->f24;
    ((struct Obj01754 *)s)->f10=((struct Obj01754 *)s)->f4+((struct Obj01754 *)s)->f34+((struct Obj01754 *)s)->f28;
    ((struct Obj01754 *)s)->f14=((struct Obj01754 *)s)->f8+((struct Obj01754 *)s)->f38+((struct Obj01754 *)s)->f2C;
}






static inline void VecSet(Vec *v,int x,int y,int z)
{
    v->x=x; v->y=y; v->z=z;
}






void func_021E05D4(u8 *p)
{
    Transform t;
    u8 *s;
    void *object;
    s=p+224;
    object=(void *)func_02048A18(((struct Obj23776 *)p)->fAF4,(u16)(((struct Obj02872 *)s)->fBC));
    VecSet(&t.pos,((struct Obj02872 *)s)->fC,((struct Obj02872 *)s)->f10,((struct Obj02872 *)s)->f14);
    VecSet(&t.scale,((struct Obj02872 *)s)->f18,((struct Obj02872 *)s)->f1C,((struct Obj02872 *)s)->f20);
    func_020520FC(((struct Obj02872 *)s)->f4C,(u16)(((struct Obj02872 *)s)->f4E*182),((struct Obj02872 *)s)->f50,(struct Mtx33 *)&t.rot);
    func_02047A60(object,(struct Arg *)(&t));
}






void func_021E0634(u8 *p,int a){func_021E15DC((int *)(p+0x3c),a);}





void func_021E0640(u8 *p){((struct Obj02208 *)p)->fDA4=func_02047E88(*(struct Util * *)&((struct Obj02208 *)p)->fAF4,&d_021E1D80);func_0207DD24(0,0,32767,0,0);}





/*
 * note: original narrows the second call argument with lsls/lsrs #16 at 021E0682/021E0686, so this caller's extern uses u16.
 */
void func_021E0678(char *p) { func_020480E4(*(struct Ctx * *)&((struct Obj14234 *)p)->fAF4,(u16)(((struct Obj14234 *)p)->fDA4)); }




/*
 * lever: Position setter before scale setter keeps zero in r0 and scale in r1.
 */
void func_021E0698(u8 *p)
{
    Transform t;
    void *object;
    object = (void *)func_02048A18(((struct Obj14235 *)p)->fAF4,(u16)(((struct Obj14235 *)p)->fDA4));
    VecSet(&t.pos,0,0,0);
    VecSet(&t.scale,4096,4096,4096);
    func_020520FC(0,0,0,(struct Mtx33 *)&t.rot);
    func_02047A60(object,(struct Arg *)(&t));
}




void func_021E06E0(char *p)
{
    int i;
    char *q=p+0x1a0;
    ((struct Obj14236 *)q)->f938=func_02047E88(((struct Obj10628 *)p)->fAF4,d_021E1E60);
    ((struct Obj14236 *)q)->f93C=func_02047E88(((struct Obj10628 *)p)->fAF4,d_021E1E70);
    for (i=0;i<5;i++) *(int *)(q+0x940+i*4)=func_02047E88(((struct Obj10628 *)p)->fAF4,d_021E212C+i*16);
}










void func_021E073C(char *p)
{
    int i;
    char *q = p+0x1a0;
    for (i=0;i<5;i++) func_020480E4(((struct Obj10629 *)p)->fAF4,(u16)(*(int *)(q+0x940+i*4)));
    func_020480E4(((struct Obj10629 *)p)->fAF4,(u16)(((struct Obj14237 *)q)->f938));
    func_020480E4(((struct Obj10629 *)p)->fAF4,(u16)(((struct Obj14237 *)q)->f93C));
}










void func_021E078C(char *p,char *q) { ((struct Obj23777 *)q)->f4=1; func_021E0B14(p,q); func_021E0BA4(p,q); }










void func_021E07A4(char *p)
{
    Count count;
    int i=0;
    Block_021E073C *base;
    count=((struct Obj08221 *)p)->f30;
    base=(Block_021E073C *)(p+0x1a0);
    for (;i<count;i++) {
        if (base->a[i].active)
            func_021E09C0((char *)&base->a[i],(int *)(p+0x110),*(u16 *)(p+0x60+i*2)<<12,((struct Obj08221 *)p)->f5C);
        if (base->b[i].active)
            func_021E0B38(p,(char *)&base->b[i],((struct Obj08221 *)p)->f5C);
        if (base->c[i].active)
            func_021E0BC0(p,(char *)&base->c[i],i);
    }
}










void func_021E0848(u8 *p)
{
    int i=0;
    int count=((struct Obj08222 *)p)->f30;
    u8 *base=p+0x1a0;
    u8 *first=base+0x140,*second=base+0x4c4,*third=base+0x730;
    for(;i<count;i=i+1) {
        if(((struct Obj02873 *)first)->f4) {
            Transform t;
            void *object=(void *)func_02048A18(((struct Obj08222 *)p)->fAF4,(u16)(((struct Obj14238 *)base)->f938));
            VecSet(&t.pos,((struct Obj02873 *)first)->f44,((struct Obj02873 *)first)->f48,((struct Obj02873 *)first)->f4C);
            VecSet(&t.scale,((struct Obj02873 *)first)->f38,((struct Obj02873 *)first)->f3C,((struct Obj02873 *)first)->f40);
            func_020520FC(((struct Obj02873 *)first)->f24,((struct Obj02873 *)first)->f26,((struct Obj02873 *)first)->f28,(struct Mtx33 *)&t.rot);
            func_02047A60(object,(struct Arg *)(&t));
        }
        if(((struct Obj02874 *)second)->f0) {
            Transform t;
            void *object=(void *)func_02048A18(((struct Obj08222 *)p)->fAF4,(u16)(((struct Obj14238 *)base)->f93C));
            VecSet(&t.pos,((struct Obj02874 *)second)->f18,((struct Obj02874 *)second)->f1C,((struct Obj02874 *)second)->f20);
            VecSet(&t.scale,((struct Obj02874 *)second)->fC,((struct Obj02874 *)second)->f10,((struct Obj02874 *)second)->f14);
            func_020520FC(((struct Obj02874 *)second)->f4,((struct Obj02874 *)second)->f6,((struct Obj02874 *)second)->f8,(struct Mtx33 *)&t.rot);
            func_02047A60(object,(struct Arg *)(&t));
        }
        if(((struct Obj08223 *)third)->f0) {
            Transform t;
            void *object=(void *)func_02048A18(((struct Obj08222 *)p)->fAF4,(u16)(*(int *)((unsigned)(base+i*4)+0x940)));
            VecSet(&t.pos,((struct Obj08223 *)third)->f4,((struct Obj08223 *)third)->f8,((struct Obj08223 *)third)->fC);
            VecSet(&t.scale,4096,4096,4096);
            func_0207ADC4(&t.rot);
            func_02047A60(object,(struct Arg *)(&t));
        }
        first+=0xb4;second+=0x7c;third+=0x68;
    }
}










void func_021E0980(char *p,int amount)
{
    int count = ((struct Obj23778 *)p)->f30;
    int i = 0;
    char *base = p+0x1a0;
    for (;i<count;i++) {
        if (*(int *)(base+0x140+i*0xb4))
            func_021E15DC((int *)(base+0x15c+i*0xb4),amount);
    }
}










/*
 * extent: two-byte alignment padding at 0x021E0A42.
 * Verified ARM scratch C: S12/blocker_0203F63C-r1.log EXACT (72 bytes),
 * S13/blocker_0203F5FC-r1.log EXACT (64 bytes). Both use this symbol:
 *   d_020A1B38 0x020A1B38 data a2
 * typedef unsigned short u16;
 * extern const short d_020A1B38[];
 * int func_0203F63C(u16 angle) {
 *     if (angle >= 360) return 0;
 *     return d_020A1B38[((angle * 65535 / 360) >> 4) * 2 + 1];
 * }
 * int func_0203F5FC(u16 angle) {
 *     if (angle >= 360) return 0;
 *     return d_020A1B38[((angle * 65535 / 360) >> 4) * 2];
 * }
 */
void func_021E09C0(char *p,int *q,int amount,int extra)
{
    u16 angle;
    func_021E15DC(&amount,*(int *)(p+0x20));
    angle=amount/4096;
    *(int *)(p+0x44)=*(int *)(p+0x50)+q[0]+22*func_0203F63C(angle);
    *(int *)(p+0x48)=extra+(*(int *)(p+0x54)-0x6000+q[1]);
    *(int *)(p+0x4c)=*(int *)(p+0x58)+q[2]+22*func_0203F5FC(angle);
    *(short *)(p+0x24)=*(int *)(p+0x2c)/4096;
    *(short *)(p+0x26)=*(int *)(p+0x30)/4096;
    *(short *)(p+0x28)=*(int *)(p+0x34)/4096;
}










/*
 * lever: (pass 2 2026-10-06 P2L40) i zeroed before the angle statement, the row offset
 *   count*10 in a named local as in the twin func_021DEE4C, and a separate local for the
 *   insertion-sort value in the third loop.
 * history: wave P12 lane A8 33 of 208 bytes off; final push G7L3 26 (initialised declarations
 *   count, table, base); pass 2 P2L40: early i 13, separate sort-value local 6, named row 0.
 */
void *func_021E0A44(Obj *p)
{
    int distance[5],indices[5];
    int angle,i,j,key,value,delta,dist,row;
    long count=p->count;
    const u8 *base=(const u8 *)p+0x1a0;
    i=0;
    row=count*10;
    angle=*(const u16 *)((unsigned)d_021E1FDC+row+p->index*2)<<12;
    do {indices[i]=i;distance[i]=65535;i++;} while(i<count);
    for(i=0;i<count;i++) {
        value=*(int *)(base+i*0xb4+0x15c);
        delta=angle-value;
        if(delta<0)delta=angle+0x168000-value;
        distance[i]=delta/4096;
    }
    for(i=1;i<count;i++) {
        key=indices[i];dist=distance[key];
        j=i-1;
        while(j>=0 && distance[indices[j]]>dist) {indices[j+1]=indices[j];j--;}
        indices[j+1]=key;
    }
    return (void *)(base+0x140+indices[0]*0xb4);
}










void func_021E0B14(char *p,char *q) { char *r; int offset; r=p+0x664; offset=((struct Obj23779 *)q)->f10*0x7c; *(int *)(r+offset)=1; *(char **)(r+offset+0x78)=q; func_021E0B38(p,r+offset,0); }










void func_021E0B38(char *p,char *q,int amount)
{
    int n;
    ((struct Obj01555 *)q)->f4=0;
    ((struct Obj01555 *)q)->f6=0;
    ((struct Obj01555 *)q)->f8=0;
    *(Vec *)(q+0x18)=*(Vec *)(*(char * *)&((struct Obj01555 *)q)->f78+0x44);
    ((struct Obj01555 *)q)->f18-=((struct Obj23780 *)(*(char * *)&((struct Obj01555 *)q)->f78))->f50;
    ((struct Obj01555 *)q)->f1C-=((struct Obj23781 *)(*(char * *)&((struct Obj01555 *)q)->f78))->f54+amount;
    ((struct Obj01555 *)q)->f20-=((struct Obj23782 *)(*(char * *)&((struct Obj01555 *)q)->f78))->f58;
    ((struct Obj01555 *)q)->f1C+=0x2000;
    n=((struct Obj23783 *)(*(char * *)&((struct Obj01555 *)q)->f78))->f54+amount;
    if (n<0) n=-n;
    n/=128;
    if (n>0x800) n=0x800;
    ((struct Obj01555 *)q)->fC=0x1000-n;
    ((struct Obj01555 *)q)->f10=0x1000-n;
    ((struct Obj01555 *)q)->f14=0x1000-n;
}











void func_021E0BA4(char *p, char *q)
{
    char *r = p + 0x8D0 + ((struct Obj23784 *)q)->f10 * 0x68;

    ((struct Obj14239 *)r)->f0 = 1;
    *(char * *)&((struct Obj14239 *)r)->f64 = q;
}










void func_021E0BC0(char *p,char *q,int i)
{
    void *r = (void *)func_02048A18(((struct Obj08221 *)p)->fAF4,(u16)(*(int *)(p+0xae0+i*4)));
    *(Vec *)(q+4) = *(Vec *)(*(char * *)&((struct Obj14240 *)q)->f64+0x44);
    ((struct Obj14240 *)q)->f8 += 0x14000;
    func_02047910(r,0,0x1000);
}









void func_021E0C08(char *p,int a,int b,int c,int d,int e,int *q)
{
    int *r;
    q[3]=a;
    q[4]=b;
    q[5]=c;
    q[6]=b;
    q[7]=d<<12;
    q[8]=e<<12;
    q[0]=1;
    q[2]=0;
    r=func_02030734(0x8072,24,0,d_021E22B8,0x130e);
    func_02082BCC(r,0,24);
    r[5]=(int)p;
    r[4]=(int)q;
    func_02030DA8(((struct Obj06537 *)p)->fD98,(void (*)(void *, void *))func_021E0C70,r,0);
}









extern int (*const d_021E1CB8[])(char *);









void func_021E0C70(struct Node *task,char *p) { int result; do { result=d_021E1CB8[*(int *)p](p); } while(result==1); if(result==2) { ((struct Obj23786 *)(*(char * *)&((struct Obj23785 *)p)->f10))->f8=1; func_020307B0(p); func_02030EAC(task); } }









int func_021E0CA4(char *p) { char *q; q=*(char * *)&((struct Obj08224 *)p)->f10; ((struct Obj08225 *)q)->f38=4096; ((struct Obj08225 *)q)->f3C=4096; ((struct Obj08225 *)q)->f40=4096; ((struct Obj08225 *)q)->f54=0xc0000; func_021E078C(*(char * *)&((struct Obj08224 *)p)->f14,q); ((struct Obj08224 *)p)->fC=0x8000; ((struct Obj08224 *)p)->f0=1; return 0; }









int func_021E0CCC(int *p)
{
    int *q = (int *)p[4];
    q[21] -= p[3];
    if (p[2] == 0 && q[21] <= 0x68000) {
        p[2] = 1;
        func_020061E4(0x725);
    }
    if (q[21] <= 0x20000) {
        q[21] = 0x20000;
        p[0] = 2;
    }
    return 0;
}








/*
 * extent: two-byte alignment padding at 0x021E0D4E.
 */
int func_021E0D0C(int *p)
{
    int *q = (int *)p[4];
    char *r;
    if (p[3] > 0x1000) {
        p[3] -= 0x1000;
        if (p[3] < 0x1000) p[3] = 0x1000;
    }
    q[21] -= p[3];
    if (q[21] <= 0) {
        q[21] = 0;
        r = (char *)p[5];
        func_021E0450((u8 *)r, (void *)(*(int *)(r + 0xa4 + q[3]*4)), q[5], q[3]);
        return 2;
    }
    return 0;
}








void func_021E0D50(char *p,int *q)
{
    int *r=(int *)q[7];
    switch(q[1]) {
    case 0:
        func_021E0F64(p,(int)r);
        q[4]=0x4000;
        q[5]=-1092;
        q[1]++;
    case 1:
        r[23]+=q[4];
        q[4]+=q[5];
        q[2]++;
        if(q[2]>=15) {
            q[2]=0;
            q[4]=0;
            if(q[3]==0) { q[3]=1; return; }
            r[23]=0;
            func_021E1090(p,(int)r);
            func_02082BCC(q,0,32);
        }
        break;
    }
}








void func_021E0DC0(void *unused,char *p) { int i; int *q; q=(int *)(p+0xaf8); for(i=0;i<5;i++,q+=8) if(*q!=0) func_021E0D50(p,q); }








void func_021E0DE8(char *p) { func_02082BCC(p+2808,0,160); *(struct Node * *)&((struct Obj14243 *)p)->fD7C=func_02030DA8(*(struct Ctx * *)&((struct Obj14243 *)p)->fD98, (void ( *)(void *,void *))((u32)func_021E0DC0), (void *)((u32)p), 256); }








void func_021E0E1C(u8 *p)
{
    func_02030EAC(((struct Obj23787 *)p)->fD7C);
}







void func_021E0E2C(char *p,int value) { int i; int *q; q=(int *)(p+0xaf8); for(i=0;i<5;i++,q+=8) { if(*q==0) { *q=1; q[7]=value; return; } } }







void func_021E0E50(char *p)
{
    Block_021E0E1C *base=(Block_021E0E1C *)(p+0x1a0);
    int count=((struct Obj23788 *)p)->f30;
    int i;
    i=0;
    do {
        if (base->records[i].active) func_021E0E2C(p,(int)((char *)&base->records[i]));
        i++;
    } while (i<count);
}







/*
 * extent: unlabelled bool scan follower at 0x021E0E8C, through pool at 0x021E0EA8.
 */
int func_021E0E8C(char *p)
{
    int i;
    char *q=p+0xaf8;
    for (i=0;i<5;i++,q+=0x20) if (((struct Obj23790 *)q)->f0) return 1;
    return 0;
}







void func_021E0EAC(int *p)
{
    int *q = (int *)p[4];
    switch (p[1]) {
    case 0:
        p[3] = 0x18000;
        q[12] = 0;
        p[1]++;
    case 1:
        func_021E15DC(q + 12, p[3]);
        if (q[12] < 0x4000) {
            p[3] = (unsigned)p[3] >> 1;
            if (p[3] < 0x4000) {
                q[12] = 0;
                func_02082BCC(p, 0, 20);
            }
        }
        break;
    }
}







void func_021E0EFC(void *unused,char *p) { int i; int *q; q=(int *)(p+0xb98); for(i=0;i<5;i++,q+=5) if(*q!=0) func_021E0EAC(q); }







void func_021E0F20(char *p) { func_02082BCC(p+2968,0,100); *(struct Node * *)&((struct Obj14244 *)p)->fD80=func_02030DA8(*(struct Ctx * *)&((struct Obj14244 *)p)->fD98, (void ( *)(void *,void *))((u32)func_021E0EFC), (void *)((u32)p), 257); }








void func_021E0F54(u8 *p)
{
    func_02030EAC(((struct Obj23791 *)p)->fD80);
}







void func_021E0F64(char *p, int key)
{
    int i;
    Entry_021E0F64 *entry;
    Entry_021E0F64 *base = (Entry_021E0F64 *)(p + 0xb98);
    entry = base;
    for (i = 0; i < 5; i++, entry++) {
        if (entry->active == 1 && entry->key == key) {
            entry->state = 0;
            return;
        }
    }
    for (i = 0; i < 5; i++, base++) {
        if (base->active == 0) {
            base->active = 1;
            base->key = key;
            return;
        }
    }
}







/*
 *   typedef unsigned short u16;
 *   extern const short d_020A1B38[];
 *   int func_0203F5FC(u16 angle) {
 *       if (angle >= 360) return 0;
 *       return d_020A1B38[((angle * 65535 / 360) >> 4) * 2];
 *   }
 */
void func_021E0FAC(int *p)
{
    int *q = (int *)p[5];
    int old;
    int amount;
    switch (p[1]) {
    case 0:
        q[13] = 0;
        p[4] = 0;
        p[2] = 0x1e000;
        p[3] = 0x14000;
        p[1]++;
    case 1:
        amount = func_0203F5FC((u16)(p[4] / 4096)) * (p[2] / 4096);
        q[13] = 0;
        func_021E15DC(q + 13, amount);
        old = p[4];
        func_021E15DC(p + 4, p[3]);
        if (p[4] < old) {
            p[2] = (unsigned)p[2] >> 1;
            if (p[2] == 0) {
                q[13] = 0;
                func_02082BCC(p, 0, 24);
            }
        }
        break;
    }
}







void func_021E1028(void *unused,char *p) { int i; int *q; q=(int *)(p+0xbfc); for(i=0;i<5;i++,q+=6) if(*q!=0) func_021E0FAC(q); }







void func_021E104C(char *p) { func_02082BCC(p+3068,0,120); *(struct Node * *)&((struct Obj14245 *)p)->fD84=func_02030DA8(*(struct Ctx * *)&((struct Obj14245 *)p)->fD98, (void ( *)(void *,void *))((u32)func_021E1028), (void *)((u32)p), 258); }








void func_021E1080(u8 *p)
{
    func_02030EAC(((struct Obj23793 *)p)->fD84);
}







void func_021E1090(char *p, int key)
{
    int i;
    Entry_021E1090 *entry;
    Entry_021E1090 *base = (Entry_021E1090 *)(p + 0xbfc);
    entry = base;
    for (i = 0; i < 5; i++, entry++) {
        if (entry->active == 1 && entry->key == key) {
            entry->state = 0;
            return;
        }
    }
    for (i = 0; i < 5; i++, base++) {
        if (base->active == 0) {
            base->active = 1;
            base->key = key;
            return;
        }
    }
}







void func_021E10D8(u8 *p,State_021E073C *s)
{
    u8 *b=p+0xe0;
    switch(s->state) {
    case 1:
        s->speed=0x4000;s->timer=0;s->state++;
    case 2:
        ((struct Obj04541 *)b)->f34-=4096;
        if(((struct Obj04541 *)b)->f34<=-32768)s->state++;
        break;
    case 3:
        ((struct Obj04541 *)b)->f34+=8192;
        if(((struct Obj04541 *)b)->f34>=0) {
            ((struct Obj04541 *)b)->f34=0;
            func_021E0E50((char *)p);
            s->active=1;s->state++;
            func_020061E4(0x55e);
        }
        break;
    case 4:
        ((struct Obj04541 *)b)->f28=s->speed;
        s->speed=-s->speed;
        s->timer++;
        if(!(s->timer&3)) {
            if(s->speed<=4096) {((struct Obj04541 *)b)->f28=0;s->state++;}
            else s->speed>>=1;
        }
        break;
    case 5:
        if(!func_021E0E8C((char *)p)) {
            s->other=0;s->active=0;s->state=0;
            func_020061E4(0x76d);
        }
        break;
    case 0:break;
    }
}







void func_021E11A0(void *unused,u8 *p)
{
    func_021E10D8(p,(State_021E073C *)(p+0xc74));
}






void func_021E11B4(char *p)
{
    func_02082BCC(p + 0xc74, 0, 20);
    ((struct Obj14246 *)p)->fD88 = (void *)func_02030DA8(((struct Obj14246 *)p)->fD98, (void ( *)(void *,void *))func_021E11A0, p, 255);
}







void func_021E11E4(u8 *p)
{
    func_02030EAC(((struct Obj23794 *)p)->fD88);
}







void func_021E11F4(char *p)
{
    char *q = p + 0xC74;

    ((struct Obj14247 *)q)->f8 = 1;
    ((struct Obj14247 *)q)->f0 = 1;
}






int func_021E1204(char *p)
{
    return ((struct Obj23795 *)p)->fC78;
}






int func_021E1210(char *p)
{
    return ((struct Obj23796 *)p)->fC7C;
}





void func_021E121C(void *task, int *p)
{
    switch (p[0]) {
    case 0:
        if (p[3] < 4) {
            Table sounds = d_021E203C;
            p[1]--;
            if (p[1] <= 0) {
                p[1] = 30;
                func_020061E4(sounds.v[p[3]]);
                p[3]++;
            }
        }
        func_0204B8D4((struct Obj *)p[5], 0x1800);
        if (func_0204B98C((struct Actor *)p[5]) == 0) p[0]++;
        break;
    case 1:
        func_0204B3B4((struct Obj *)p[5]);
        func_020307B0(p);
        func_02030EAC(task);
        break;
    }
}





void func_021E129C(char *p)
{
    struct { u16 x, y, z; u8 a, b; } pos;
    int *q = func_02030734(0x8072, 24, 0, d_021E22B8, 5638);
    func_02082BCC(q, 0, 24);
    pos.x = 128;
    pos.y = 100;
    pos.z = 0;
    pos.b = 0;
    pos.a = 0;
    q[5] = (int)(struct Obj *)func_0204B294((void *)((struct Obj02209 *)p)->fD68, ((struct Obj02209 *)p)->fD6C, ((struct Obj02209 *)p)->fD70, ((struct Obj02209 *)p)->fD74, &pos, 0, 114);
    func_0204B8D4((struct Obj *)q[5], 4096);
    q[4] = (int)p;
    func_02030DA8(((struct Obj02209 *)p)->fD98, (void ( *)(void *,void *))func_021E121C, q, 0);
}




void func_021E1320(void *task, State_021E1320 *p)
{
    switch (p->state) {
    case 0: break;
    case 1:
        func_021DFEA0(task);
        func_020061E4(1832);
        p->count = 0;
        p->state++;
    case 2:
        p->count++;
        if (p->count >= 2) {
            p->count = 0;
            p->state++;
            func_021DFEB8(task);
        }
        break;
    case 3:
        p->count++;
        if (p->count >= 4) {
            func_021DFEA0(task);
            p->count = 0;
            p->state++;
        }
        break;
    case 4:
        p->count++;
        if (p->count >= 2) {
            func_021DFEAC(task);
            p->flag = 0;
            p->state = 0;
        }
        break;
    }
}




/*
 * follower: 021E13A8 tail-forwards r1 and r1+0xC88 to this callback.
 */
void func_021E13A8(void *unused, char *p)
{
    func_021E1320(p, (State_021E1320 *)(p + 0xc88));
}




void func_021E13BC(char *p)
{
    unsigned n = 8;
    func_02082BCC(p + 0xc88, 0, n);
    n += 251;
    ((struct Obj14248 *)p)->fD8C = (void *)func_02030DA8(((struct Obj14248 *)p)->fD98, (void ( *)(void *,void *))func_021E13A8, p, n);
}





void func_021E13F0(u8 *p)
{
    func_02030EAC(((struct Obj23797 *)p)->fD8C);
}





u16 func_021E1400(char *p)
{
    return ((struct Obj23798 *)p)->fC8A;
}





void func_021E140C(char *p)
{
    char *q = p + 0xC88;

    ((struct Obj14249 *)q)->f2 = 1;
    ((struct Obj14249 *)q)->f0 = 1;
}




void func_021E141C(void *unused, int *p)
{
    switch (p[0]) {
    case 0: break;
    case 1:
        *(int *)(p[3] + 0x54) = d_021E2278[p[1]] << 12;
        p[1]++;
        if (p[1] >= 16) {
            p[1] = 0;
            p[0]++;
        }
        break;
    case 2:
        p[2]++;
        if (p[2] >= 15) {
            p[2] = 0;
            p[0] = 1;
        }
        break;
    }
}




void func_021E1468(void *unused, char *p)
{
    int i;
    int *q = (int *)(p + 0xc90);
    for (i = 0; i < 5; i++, q += 4) func_021E141C(p, q);
}




void func_021E1488(char *p)
{
    unsigned n = 80;
    func_02082BCC(p + 0xc90, 0, n);
    n += 180;
    ((struct Obj14250 *)p)->fD90 = (void *)func_02030DA8(((struct Obj14250 *)p)->fD98, (void ( *)(void *,void *))func_021E1468, p, n);
}




void func_021E14BC(u8 *p)
{
    func_02030EAC(((struct Obj23799 *)p)->fD90);
}




void func_021E14CC(char *p, char *q)
{
    char *r = p + 0xC90 + ((struct Obj23800 *)q)->fC * 0x10;

    ((struct Obj14251 *)r)->f0 = 1;
    *(char * *)&((struct Obj14251 *)r)->fC = q;
}



void func_021E14E4(const char *p)
{
  int mask = *((int *) (p + 28));
  const Block *base;
  int i;
  int count;
  i = 0;
  base = (const Block *) (p + 0x1a0);
  count = *((int *) (p + 48));
  for (; i < count; i++)
  {
    if ((base->records[i].active != 0) && (mask & (1 << base->records[i].key)))
      func_021E14CC((char *) p, (char *) (&base->records[i]));
  }
}



void func_021E1540(void *task, int *p)
{
    int done = 0;
    if (p[1] == 1) {
        p[2]--;
        if (p[2] <= 0) {
            p[2] = 0;
            done = 1;
        }
    } else {
        p[2]++;
        if (p[2] >= 8) {
            p[2] = 8;
            done = 1;
        }
    }
    func_021DFF20((void *)p[0], p[2]);
    if (done == 1) {
        func_020307B0(p);
        func_02030EAC(task);
    }
}



void func_021E1584(char *p, int flag)
{
    Pair_021E073C values = d_021E2018;
    int *q = func_02030734(0x8072, 12, 0, d_021E22B8, 5992);
    q[0] = (int)p;
    q[1] = flag;
    q[2] = ((int *)&values)[flag];
    func_02030DA8(((struct Obj02209 *)p)->fD98, (void ( *)(void *,void *))func_021E1540, q, 0);
}




void func_021E15DC(int *p, int v)
{
    *p += v;
    while (*p < 0) *p += 0x168000;
    *p %= 0x168000;
}



void func_021E1604(char *p, int v)
{
    func_021E0634((u8 *)(p + 0xe0), v);
    func_021E0980(p, v);
}




int func_021E161C(char *p)
{
    int n = ((struct Obj10636 *)p)->f8 + 1;

    ((struct Obj10636 *)p)->f8 = n;
    if (n < 0x258)
        return 0;
    ((struct Obj10636 *)p)->f8 = 0x258;
    return 1;
}



/*
 * extent: following 021E168C is already matched separately.
 */
void *func_021E1634(char *p, u32 member, int flag)
{
    u32 size = func_020493D4(*(struct ArcFile * *)&((struct Obj14254 *)p)->fD58, member);
    void *result;
    if (flag == 1)
        result = func_02030734(114, size, 0, d_021E22B8, 6090);
    else
        result = func_02030734(0x8072, size, 0, d_021E22B8, 6092);
    func_0204932C(*(struct ArcFile * *)&((struct Obj14254 *)p)->fD58, member, result);
    return result;
}



void func_021E168C(int *p,int a) { if(a!=0) p[13]=a; }



void func_021E1694(char *p, const Record_021E1694 *q)
{
    ((struct Obj23802 *)p)->f3C = 1;
    *(Record_021E1694 *)(p + 0x58) = *q;
}



char *func_021E16AC(char *p, int n)
{
    func_02082BCC(p + 0xb8, 0, 32);
    return p + 0xb8;
}




char *func_021E16C0(char *p)
{
    return p + 0xb8;
}




int func_021E16C4(char *p, int mask)
{
    return (((struct Obj23803 *)(*(char * *)&((struct Obj01753 *)p)->fDC))->f40 & mask) != 0;
}



/*
 * Lever: initialise count before bound, then carry bound through a plain copy bound_ after x is loaded.
 * Direct bound use left a four-byte zero/subtraction scheduling swap; bounded permuter found the copy spelling.
 * trailing: Two zero alignment bytes.
 */
int func_021E16D8(const char *p)
{
  unsigned int count;
  int bound;
  unsigned int x;
  int bound_;
  count = 0;
  bound = (*((int *) ((*((char **) (p + 0xd8))) + 8))) - 1;
  x = *((unsigned short *) ((*((char **) (p + 0xdc))) + 0x42));
  bound_ = bound;
  while (x)
  {
    count += x & 1;
    x >>= 1;
  }

  return ((int) count) >= bound_;
}




/*
 * extent: 30-byte body followed by two bytes of zero alignment padding.
 * lever: Initialize count before loading x; declare count before x.
 * Existing result-before-input and declaration-order idioms cover this.
 */
int func_021E170C(char *p) { int count; unsigned int x; count=0;x=((struct Obj23806 *)(*(char * *)&((struct Obj01753 *)p)->fDC))->f42;while(x) { count+=x&1; x>>=1; }return count; }



/*
 * extent: 42-byte body followed by two bytes of zero alignment padding.
 * volatile: The raw halfword at q+0 is re-read at 021E1732/021E1734.
 */
void func_021E172C(char *p,unsigned short *q) { unsigned int index;unsigned short value; index=*(volatile unsigned short *)&((struct Obj06543 *)q)->f0;value=*(volatile unsigned short *)&((struct Obj06543 *)q)->f0;*(unsigned short *)(p+index*4+0x7c)=value;*(unsigned short *)(p+index*4+0x7e)=q[1];if(q[1]==func_02039338())((struct Obj23807 *)p)->f2C=q[0]; }



void func_021E1758(char *p, int a1) { ((struct Obj01753 *)p)->f30=func_021841A4(func_021DEB10(p)); }




/*
 * The `&` operand order names the temporary: `field & (1 << i)` (field into
 * r2, mask into r0) reproduces the original; `(1 << i) & field` rotates them.
 */
int func_021E1768(char *p, int i)
{
    if (i != 0 && (((struct Obj23808 *)(*(char * *)&((struct Obj03304 *)p)->fDC))->f42 & (1 << i)) == 0)
        return 0;
    return 1;
}



void func_021E1784(char *p, int i)
{
    void *party;
    void *other;
    int slot;
    void *a;
    void *b;
    void *q;
    party = ((struct Obj14255 *)p)->f24;
    other = (void *)func_021DCE00(*(char * *)&((struct Obj14255 *)p)->fDC, i);
    slot = *(int *)(p + 0x44 + i * 4);
    a = func_0201AB28(party, (*(int **)(p + 0xd8))[1]);
    b = func_0201AB28(other, slot);
    q = func_021DEB10(p);
    func_0202F190(b, (int)6, (u32)func_02184180(q, (u8)func_02039338()), (int)30002, (int)114);
    func_02019CE0(b, a);
}



int func_021E17EC(char *p)
{
    int count = 0;
    unsigned bits = ((struct Obj23809 *)(*(char * *)&((struct Obj03304 *)p)->fDC))->f46;
    while (bits) {
        count += bits & 1;
        bits >>= 1;
    }
    return count;
}



void func_021E180C(int *p,int a,int b) { (p+a)[17]=b; }



void func_021E1814(unsigned char *p,u16 *q)
{
    u16 *d=(u16 *)(p+108);
    unsigned n=8;
    do { *d++=*q++; } while(--n);
    ((struct Obj23810 *)p)->f40=1;
}



int func_021E1830(char *p, int angle, int index)
{
    int tmp;
    unsigned a;
    unsigned count;
    unsigned b;
    struct Range_021E073C *r;
    struct Entry *e;
    func_021E15DC(&angle, -((struct Obj02497 *)p)->f11C);
    func_021E15DC(&angle, -((struct Obj02497 *)p)->f124);
    tmp = angle;
    func_021E15DC(&tmp, -0x4000);
    a = tmp / 0x1000;
    tmp = angle;
    func_021E15DC(&tmp, 0x5000);
    b = tmp / 0x1000;
    e = &d_021E1F04[index];
    count = e->count;
    r = e->ranges;
    while (count) {
        if ((a >= r->lo && a <= r->hi) || (b >= r->lo && b <= r->hi))
            return 1;
        r++;
        count--;
    }
    return 0;
}



int func_021E18CC(void *p)
{
    int n;
    int i;
    void *m;
    n = func_0201AA18(p);
    for (i = 0; i < n; i++) {
        m = func_0201AB28(p, i);
        if (func_02017E1C(m, 0x4c, 0) != 0 && func_02017E1C(m, 3, 0) != 0)
            return 1;
    }
    return 0;
}



int func_021E1910(char *p)
{
    int i;
    if (func_021E18CC(((struct Obj03304 *)p)->f24) == 1)
        return 1;
    for (i = 0; i < 5; i++) {
        if (func_021E1768(p, i) != 0 && func_021E18CC((void *)func_021DCE00(*(char * *)&((struct Obj03304 *)p)->fDC, i)) == 1)
            return 1;
    }
    return 0;
}




int func_021E1954(char *p) { int count; unsigned int x; count=0;x=((struct Obj23811 *)(*(char * *)&((struct Obj06536 *)p)->fDC))->f4A;while(x) { count+=x&1; x>>=1; }return count; }




int func_021E1974(char *p)
{
    return ((struct Obj23812 *)(*(char * *)&((struct Obj06536 *)p)->fDC))->f48 != 0;
}



void func_021E1988(unsigned int n) { func_02005DE4((void *)1);func_02005E64();func_02005D90(n,65535); }



/*
 * prototype: Legacy 02005E9C source lists four inputs, but its complete
 * body starts with 02005FBC(void) and reads no entry inputs; omitted them.
 */
int func_021E19A4(void) { if(func_02005F38()==0) { func_02005E9C();func_02005DE4(0);return 0; }return 1; }
