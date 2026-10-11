/*
 * file:     br_codein_p01.c
 * unit:     yes
 * function: func_021DB2E0, func_021DB36C, func_021DB394, func_021DB3C4, func_021DB594, func_021DB61C, func_021DB690, func_021DB698, func_021DB740, func_021DB770, func_021DB924, func_021DB940, func_021DBB3C, func_021DBBC4, func_021DBC68, func_021DBCA8, func_021DBCF4, func_021DBD40, func_021DBD7C, func_021DBEB0, func_021DBFB0, func_021DC228, func_021DC4FC, func_021DC638, func_021DC8EC, func_021DCBD8, func_021DCDD8, func_021DCE28, func_021DCE48, func_021DCEE4, func_021DD054, func_021DD0AC, func_021DD0F4, func_021DD128, func_021DD1D4, func_021DD228, func_021DD25C, func_021DD27C, func_021DD2BC, func_021DD2FC, func_021DD33C, func_021DD37C, func_021DD3F8, func_021DD440, func_021DD5C8, func_021DD684, func_021DD858, func_021DDA2C, func_021DDCCC, func_021DDDE8, func_021DDE2C, func_021DDF5C, func_021DDFA0, func_021DE000, func_021DE02C, func_021DE058, func_021DE084, func_021DE12C, func_021DE15C, func_021DE1C8, func_021DE234, func_021DE274, func_021DE3E4, func_021DE404, func_021DE55C, func_021DE66C, func_021DE780, func_021DE7C0, func_021DE8FC, func_021DE940, func_021DE9A0, func_021DEA30, func_021DEADC, func_021DEB4C, func_021DECB0, func_021DED14, func_021DED64, func_021DEDB4, func_021DEE7C, func_021DF0DC, func_021DF18C, func_021DF1DC, func_021DF388, func_021DF3DC, func_021DF41C, func_021DF428, func_021DF5B8, func_021DF620, func_021DF838, func_021DF8F0, func_021DF920, func_021DF9C8, func_021DFA10, func_021DFB90, func_021DFC88, func_021DFCD4, func_021DFE98, func_021DFF78, func_021DFFB0, func_021E0044, func_021E0080, func_021E009C, func_021E00D8, func_021E0214, func_021E024C, func_021E02F8, func_021E037C, func_021E03B0, func_021E04C8, func_021E050C, func_021E05C4, func_021E0618, func_021E06D0, func_021E0754, func_021E075C, func_021E0764, func_021E0774, func_021E07A4, func_021E0808, func_021E083C, func_021E0840, func_021E08E4, func_021E0954, func_021E0A88, func_021E0C04, func_021E0CE8, func_021E0D00, func_021E0D38, func_021E0D90, func_021E0E40, func_021E0E4C, func_021E0E90, func_021E1008, func_021E10A0, func_021E10BC, func_021E10DC, func_021E10F4
 * address:  0x021DB2E0
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FD940 0x021FD940 thumb ov186
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_021FD72C 0x021FD72C thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FD938 0x021FD938 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   func_021FE794 0x021FE794 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FEE24 0x021FEE24 thumb ov186
 *   func_021F9BF4 0x021F9BF4 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_020061E4 0x020061E4 thumb
 *   func_02035C60 0x02035C60 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021FEE74 0x021FEE74 thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021FEE9C 0x021FEE9C thumb ov186
 *   func_021FEE4C 0x021FEE4C thumb ov186
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021FC1F8 0x021FC1F8 thumb ov186
 *   func_021FC148 0x021FC148 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021F9CB8 0x021F9CB8 thumb ov186
 *   func_021FE840 0x021FE840 thumb ov186
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_021F9F48 0x021F9F48 thumb ov186
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FA018 0x021FA018 thumb ov186
 *   func_021F9FE8 0x021F9FE8 thumb ov186
 *   func_021FA004 0x021FA004 thumb ov186
 *   func_021FA01C 0x021FA01C thumb ov186
 *   func_021FC238 0x021FC238 thumb ov186
 *   func_021FC230 0x021FC230 thumb ov186
 *   func_021FC224 0x021FC224 thumb ov186
 *   func_021FE7F4 0x021FE7F4 thumb ov186
 *   func_02035D20 0x02035D20 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021E3280 0x021E3280 data a4
 *   func_021FC240  0x021FC240  thumb  ov186
 *   func_02025538 0x02025538 thumb
 *   func_0200B928 0x0200B928 thumb
 *   func_0200B910 0x0200B910 thumb
 *   func_0200B98C 0x0200B98C thumb
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_02025588 0x02025588 thumb
 *   func_02012E40 0x02012E40 thumb
 *   func_021FF88C 0x021FF88C thumb ov186
 *   func_021F9C6C 0x021F9C6C thumb ov186
 *   func_021FD6B0 0x021FD6B0 thumb ov186
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021F9C50 0x021F9C50 thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FF54C 0x021FF54C thumb ov186
 *   func_021FF648 0x021FF648 thumb ov186
 *   func_021FF72C 0x021FF72C thumb ov186
 *   func_021FF698 0x021FF698 thumb ov186
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200B938 0x0200B938 thumb
 *   func_02006254 0x02006254 thumb
 *   func_021D7630 0x021D7630 thumb ov125
 *   d_021E3960 0x021E3960 data a1
 *   func_02034714 0x02034714 arm
 *   func_0200B490 0x0200B490 thumb
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_021FC868 0x021FC868 thumb ov186
 *   func_021FC7C4 0x021FC7C4 thumb ov186
 *   func_020457B0 0x020457B0 arm
 *   func_02045808 0x02045808 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0200D6D0 0x0200D6D0 thumb
 *   func_0200D6EC 0x0200D6EC thumb
 *   func_0200D774 0x0200D774 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   _ll_udiv 0x0209C00C arm
 *   _ull_mod 0x0209C018 arm
 *   d_021E32C8 0x021E32C8 data a4
 *   func_020490F4 0x020490F4 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_0201BABC 0x0201BABC thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02049238 0x02049238 arm
 *   d_021E32F0 0x021E32F0 data a2
 *   func_021FD1C4 0x021FD1C4 thumb ov186
 *   func_021FD640 0x021FD640 thumb ov186
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_021FD12C 0x021FD12C thumb ov186
 *   d_021E32A8 0x021E32A8 data a4
 *   func_0200DABC 0x0200DABC thumb
 *   d_021E3350 0x021E3350 data a4
 *   func_0200DB44 0x0200DB44 thumb
 *   func_0200DAC4 0x0200DAC4 thumb
 *   func_0200DAD8 0x0200DAD8 thumb
 *   d_021E33C0 0x021E33C0 data a4
 *   d_021E3400 0x021E3400 data a4
 *   d_021E3490 0x021E3490 data a4
 *   func_0200DC08 0x0200DC08 thumb
 *   d_021E338C 0x021E338C data a4
 *   d_021E336C 0x021E336C data a4
 *   d_021E3440 0x021E3440 data a4
 *   func_0200DBA0 0x0200DBA0 thumb
 *   func_0201296C 0x0201296C thumb
 *   func_020142E8 0x020142E8 thumb
 *   func_0204B878 0x0204B878 arm
 *   d_021E3358 0x021E3358 data a4
 *   func_0200DFD8 0x0200DFD8 thumb
 *   func_02012944 0x02012944 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   d_021E3574 0x021E3574 data a4
 *   d_021E3664 0x021E3664 data a4
 *   d_021E35D4 0x021E35D4 data a4
 *   func_02045CAC 0x02045CAC arm
 *   d_021E351C 0x021E351C data a4
 *   d_021E3534 0x021E3534 data a4
 *   d_021E3964 0x021E3964 data a1
 *   func_021FF6DC 0x021FF6DC thumb ov186
 *   func_021FF704 0x021FF704 thumb ov186
 *   func_021FF6B4 0x021FF6B4 thumb ov186
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201F81C 0x0201F81C thumb
 *   func_021FC8C8 0x021FC8C8 thumb ov186
 *   func_02043678 0x02043678 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045924 0x02045924 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_021FCDAC 0x021FCDAC thumb ov186
 *   func_021FCE50 0x021FCE50 thumb ov186
 *   d_021E3700 0x021E3700 data a4
 *   func_021FCE0C 0x021FCE0C thumb ov186
 *   func_021FCDE8 0x021FCDE8 thumb ov186
 *   func_020437AC 0x020437AC arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_021FCC80 0x021FCC80 thumb ov186
 *   func_0201F868 0x0201F868 thumb
 *   func_021FCD0C 0x021FCD0C thumb ov186
 *   func_021FCDA8 0x021FCDA8 thumb ov186
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B7C8 0x0204B7C8 arm
 *   func_0204B714 0x0204B714 arm
 *   func_0204B784 0x0204B784 arm
 *   func_02049E74 0x02049E74 arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_0204AB84 0x0204AB84 arm
 *   func_020307B0 0x020307B0 arm
 *   d_021E37A8 0x021E37A8 data a4
 *   d_021E3734 0x021E3734 data a2
 *   d_021E3740 0x021E3740 data a4
 *   func_0200856C 0x0200856C thumb
 *   func_02008570 0x02008570 thumb
 *   func_021FB4CC 0x021FB4CC thumb ov186
 *   func_0201F878 0x0201F878 thumb
 *   d_021E3758 0x021E3758 data a4
 *   d_021E3728 0x021E3728 data a4
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_021FFBD4 0x021FFBD4 thumb ov186
 *   func_021FFE5C 0x021FFE5C thumb ov186
 *   func_021FFE34 0x021FFE34 thumb ov186
 *   func_021FFE70 0x021FFE70 thumb ov186
 *   func_021FFC6C 0x021FFC6C thumb ov186
 *   func_021FFC9C 0x021FFC9C thumb ov186
 *   func_021FFE90 0x021FFE90 thumb ov186
 *   func_0201F898 0x0201F898 thumb
 *   func_02025B64 0x02025B64 thumb
 *   func_0201F048 0x0201F048 thumb
 *   func_0201F094 0x0201F094 thumb
 *   d_021E3780 0x021E3780 data a4
 *   d_021E372E 0x021E372E data a4
 *   d_021E37D8 0x021E37D8 data ov183
 *   d_020A7370 0x020A7370 data a4
 *   g_021E3808     0x021E3808  data  ov183
 *   func_02030734 0x02030734 arm
 *   func_021E1244 0x021E1244 thumb ov183
 *   func_021E1910 0x021E1910 thumb ov183
 *   func_021E16E4 0x021E16E4 thumb ov183
 *   d_021E3968 0x021E3968 data ov183
 *   func_02051C6C 0x02051C6C arm
 *   d_021E3974 0x021E3974 data a4
 *   d_021E3978 0x021E3978 data ov183
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0202570C 0x0202570C thumb
 *   func_021E111C 0x021E111C thumb ov183
 */
#include "../../matched/include/Obj02228.h"
#include "../../matched/include/Obj03879.h"
#include "../../matched/include/Obj08308.h"
#include "../../matched/include/Obj06595.h"
#include "../../matched/include/Obj00630.h"
#include "../../matched/include/Obj24519.h"
#include "../../matched/include/Obj24520.h"
#include "../../matched/include/Obj24521.h"
#include "../../matched/include/Obj24522.h"
#include "../../matched/include/Obj24523.h"
#include "../../matched/include/Obj24524.h"
#include "../../matched/include/Obj24525.h"
#include "../../matched/include/Obj24526.h"
#include "../../matched/include/Obj24527.h"
#include "../../matched/include/Obj24528.h"
#include "../../matched/include/Obj24529.h"
#include "../../matched/include/Obj24530.h"
#include "../../matched/include/Obj05470.h"
#include "../../matched/include/Obj24531.h"
#include "../../matched/include/Obj24532.h"
#include "../../matched/include/Obj24533.h"
#include "../../matched/include/Obj24534.h"
#include "../../matched/include/Obj06597.h"
#include "../../matched/include/Obj24535.h"
#include "../../matched/include/Obj24536.h"
#include "../../matched/include/Obj24537.h"
#include "../../matched/include/Obj24538.h"
#include "../../matched/include/Obj24539.h"
#include "../../matched/include/Obj01072.h"
#include "../../matched/include/Obj02517.h"
#include "../../matched/include/Obj10727.h"
#include "../../matched/include/Obj14419.h"
#include "../../matched/include/Obj01004.h"
#include "../../matched/include/Obj02891.h"
#include "../../matched/include/Obj08309.h"
#include "../../matched/include/Obj14420.h"
#include "../../matched/include/Obj00050.h"
#include "../../matched/include/Obj06598.h"
#include "../../matched/include/Obj24541.h"
#include "../../matched/include/Obj02892.h"
#include "../../matched/include/Obj24542.h"
#include "../../matched/include/Obj24543.h"
#include "../../matched/include/Obj24544.h"
#include "../../matched/include/Obj00730.h"
#include "../../matched/include/Obj14421.h"
#include "../../matched/include/Obj24545.h"
#include "../../matched/include/Obj24546.h"
#include "../../matched/include/Obj14422.h"
#include "../../matched/include/Obj24547.h"
#include "../../matched/include/Obj24548.h"
#include "../../matched/include/Obj24549.h"
#include "../../matched/include/Obj24550.h"
#include "../../matched/include/Obj24551.h"
#include "../../matched/include/Obj24552.h"
#include "../../matched/include/Obj24553.h"
#include "../../matched/include/Obj24554.h"
#include "../../matched/include/Obj24555.h"
#include "../../matched/include/Obj24556.h"
#include "../../matched/include/Obj24557.h"
#include "../../matched/include/Obj24558.h"
#include "../../matched/include/Obj24559.h"
#include "../../matched/include/Obj24560.h"
#include "../../matched/include/Obj24561.h"
#include "../../matched/include/Obj24562.h"
#include "../../matched/include/Obj24563.h"
#include "../../matched/include/Obj24564.h"
#include "../../matched/include/Obj24565.h"
#include "../../matched/include/Obj24566.h"
#include "../../matched/include/Obj24567.h"
#include "../../matched/include/Obj24568.h"
#include "../../matched/include/Obj24569.h"
#include "../../matched/include/Obj24571.h"
#include "../../matched/include/Obj02893.h"
#include "../../matched/include/Obj24572.h"
#include "../../matched/include/Obj03329.h"
#include "../../matched/include/Obj10730.h"
#include "../../matched/include/Obj24573.h"
#include "../../matched/include/Obj24574.h"
#include "../../matched/include/Obj06599.h"
#include "../../matched/include/Obj14423.h"
#include "../../matched/include/Obj10731.h"
#include "../../matched/include/Obj24575.h"
#include "../../matched/include/Obj24576.h"
#include "../../matched/include/Obj24577.h"
#include "../../matched/include/Obj24578.h"
#include "../../matched/include/Obj00631.h"
#include "../../matched/include/Obj00632.h"
#include "../../matched/include/Obj06603.h"
#include "../../matched/include/Obj10732.h"
#include "../../matched/include/Obj00363.h"
#include "../../matched/include/Obj00731.h"
#include "../../matched/include/Obj14425.h"
#include "../../matched/include/Obj10733.h"
#include "../../matched/include/Obj10734.h"
#include "../../matched/include/Obj14426.h"
#include "../../matched/include/Obj10735.h"
#include "../../matched/include/Obj10736.h"
#include "../../matched/include/Obj05472.h"
#include "../../matched/include/Obj14427.h"
#include "../../matched/include/Obj14428.h"
#include "../../matched/include/Obj10737.h"
#include "../../matched/include/Obj24580.h"
#include "../../matched/include/Obj02519.h"
#include "../../matched/include/Obj06604.h"
#include "../../matched/include/Obj10738.h"
#include "../../matched/include/Obj00440.h"
#include "../../matched/include/Obj00785.h"
#include "../../matched/include/Obj14429.h"
#include "../../matched/include/Obj10739.h"
#include "../../matched/include/Obj10740.h"
#include "../../matched/include/Obj10741.h"
#include "../../matched/include/Obj08312.h"
#include "../../matched/include/Obj10742.h"
#include "../../matched/include/Obj10743.h"
#include "../../matched/include/Obj10744.h"
#include "../../matched/include/Obj10745.h"
#include "../../matched/include/Obj02229.h"
#include "../../matched/include/Obj06605.h"
#include "../../matched/include/Obj24581.h"
#include "../../matched/include/Obj00923.h"
#include "../../matched/include/Obj24582.h"
#include "../../matched/include/Obj24583.h"
#include "../../matched/include/Obj24584.h"
#include "../../matched/include/Obj02521.h"
#include "../../matched/include/Obj24585.h"
#include "../../matched/include/Obj24586.h"
#include "../../matched/include/Obj00364.h"
#include "../../matched/include/Obj24587.h"
#include "../../matched/include/Obj24588.h"
#include "../../matched/include/Obj24589.h"
#include "../../matched/include/Obj24590.h"
#include "../../matched/include/Obj24591.h"
#include "../../matched/include/Obj24592.h"
#include "../../matched/include/Obj24593.h"
#include "../../matched/include/Obj24595.h"
#include "../../matched/include/Obj24596.h"
#include "../../matched/include/Obj24597.h"
#include "../../matched/include/Obj24598.h"
#include "../../matched/include/Obj02894.h"
#include "../../matched/include/Obj24599.h"
#include "../../matched/include/Obj24600.h"
#include "../../matched/include/Obj14430.h"
#include "../../matched/include/Obj24601.h"
#include "../../matched/include/Obj24602.h"
#include "../../matched/include/Obj14431.h"
#include "../../matched/include/Obj24603.h"
#include "../../matched/include/Obj24604.h"
#include "../../matched/include/Obj03880.h"
#include "../../matched/include/Obj24605.h"
#include "../../matched/include/Obj24606.h"
#include "../../matched/include/Obj24607.h"
#include "../../matched/include/Obj24608.h"
#include "../../matched/include/Obj24609.h"
#include "../../matched/include/Obj24610.h"
#include "../../matched/include/Obj01962.h"
#include "../../matched/include/Obj24611.h"
#include "../../matched/include/Obj24613.h"
#include "../../matched/include/Obj24614.h"
#include "../../matched/include/Obj24615.h"
#include "../../matched/include/Obj24616.h"
#include "../../matched/include/Obj14432.h"
#include "../../matched/include/Obj24617.h"
#include "../../matched/include/Obj24618.h"
#include "../../matched/include/Obj02522.h"
#include "../../matched/include/Obj00786.h"
#include "../../matched/include/Obj24619.h"
#include "../../matched/include/Obj01765.h"
#include "../../matched/include/Obj02230.h"
#include "../../matched/include/Obj10749.h"
#include "../../matched/include/Obj14433.h"
#include "../../matched/include/Obj05476.h"
#include "../../matched/include/Obj05477.h"
#include "../../matched/include/Obj05478.h"
#include "../../matched/include/Obj24620.h"
#include "../../matched/include/Obj00277.h"
#include "../../matched/include/Obj00351.h"
#include "../../matched/include/Obj02523.h"
#include "../../matched/include/Obj04571.h"
#include "../../matched/include/Obj04572.h"
#include "../../matched/include/Obj24621.h"
#include "../../matched/include/Obj04573.h"
#include "../../matched/include/Obj08315.h"
#include "../../matched/include/Obj14434.h"
#include "../../matched/include/Obj02231.h"
#include "../../matched/include/Obj03330.h"
#include "../../matched/include/Obj04574.h"
#include "../../matched/include/Obj24622.h"
#include "../../matched/include/Obj24623.h"
#include "../../matched/include/Obj01767.h"
#include "../../matched/include/Obj04576.h"
#include "../../matched/include/Obj03331.h"
#include "../../matched/include/Obj24624.h"
#include "../../matched/include/Obj24625.h"
#include "../../matched/include/Obj10751.h"
#include "../../matched/include/Obj14437.h"
#include "../../matched/include/Obj00143.h"
#include "../../matched/include/Obj08317.h"
#include "../../matched/include/Obj08316.h"
#include "../../matched/include/Obj02895.h"
#include "../../matched/include/Obj14438.h"
#include "../../matched/include/Obj05480.h"
#include "../../matched/include/Obj05481.h"
#include "../../matched/include/Obj24626.h"

struct Obj24810;
struct Obj0203159C;
struct S020315D4;
struct PrintSys;
struct Obj;
struct Node;
struct ObjC4;
struct Big;
struct Actor;
struct Blk1AC;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct BigObj;
struct Bmp;
struct CharBuf;
struct State;
struct StrObj;
struct Strbuf;
struct Obj020437AC;
struct Struct36;
struct Sub0204A9D0;
struct Sub0200852CObj;
struct Object;
struct Source;
struct Coordinates;
struct Vec2;
struct PtS;
struct Grid;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long long u64;

typedef struct {char pad[0x4c];char saved[0x18];int count;void *ptr;} S_021DB2E0;

typedef struct S_021DBFB0 S_021DBFB0;

typedef struct S S;

typedef struct {u8 x,y,w,h;u32 message;} Descriptor;

typedef struct U16Vec U16Vec;

typedef struct MsgBank MsgBank;

typedef struct WordSet WordSet;

typedef struct GdsProfile GdsProfile;

typedef struct GdsRecord GdsRecord;

typedef struct RecGet RecGet;

typedef signed short s16_021DB2E0;

typedef struct {s16_021DB2E0 x,y,z;u8 a,b;} Position_021DB2E0;

typedef struct {s16_021DB2E0 x,y;} Pair_021DB2E0;

typedef signed int     s32;

typedef struct {u16 x,y,n;u8 flag,pad;} Desc;

typedef struct Triple { int a,b,c; } Triple;

typedef struct {int x,y;} Pair_021DD0F4;

struct Record_021DB2E0 { u8 a, b, c, d; int value; };

struct Pair { int x,y; };

struct Record_021DD1D4 { u8 a, b, c, d; int value; };

struct Record_021DD684{u8 a,b,c,d;int value;};

struct Record_021DDCCC { u8 a,b,c,d; int value; };

struct Position_021DB2E0 { short x,y,z;u8 a,b; };

typedef struct Rect_021DB2E0 { u32 x0, y0, x1, y1; } Rect_021DB2E0;

typedef struct Position_021DE084 { s16_021DB2E0 x, y, z; u8 a, b; } Position_021DE084;

struct Pair_021DE084 { int x,y; };

typedef struct Record {u8 a,b,c,d; u32 value;} Record;

typedef u16 Row[3];

typedef struct Config_021DE084 {u16 left,right,top;u8 flag,pad;} Config_021DE084;

typedef struct Triple_021DE084 {u32 a,b,c;} Triple_021DE084;

struct Pair_021DEE7C { u32 x,y; };

struct Data_021DB2E0 { u8 pad[0x1718]; int count; u32 selected; };

typedef struct {void *text;int id;} Item;

typedef struct {Item *list;u32 count;u8 x,y,width,height,palette,bg,spacing,pad;int mode;char *resources;u32 manager,cursor,other;u16 *selection;} Config_021DF1DC;

typedef struct {u32 w[10];} CfgTpl;

typedef struct Slot_021DB2E0 { u32 a,b; } Slot_021DB2E0;

typedef struct {Slot_021DB2E0 *list;void *view;void *words;u32 c,d;u8 pad[0xbc];char *base;} Menu;

typedef signed char s8;

struct State_021DF428 { u8 pad[0x14]; u16 shared0,shared1; u16 indices[5][6]; int cursor; void *sprites[5][6]; char *source; };

struct Pos { u16 x; short y; u16 z; u8 a,b; };

struct Entries { u32 species[6],form[6],gender[6]; };

struct W { char pad[0x18]; u16 handles[5][6]; char gap[4]; void *objects[5][6]; };

struct Rec { u32 w[9]; };

struct Sub { u8 pad[16]; u32 size,data; };

typedef int (*Method)(char *,int *);

struct Methods { Method init,update,finish; };

struct Request { u16 x,y,id; u8 flag,pad; };

struct Rec6 { u8 x,y,id,pad; u16 file; };

struct Rec8 { u8 a,b,c,d; void *value; };

typedef struct {u32 words[10];} Config;

typedef struct {u16 a,b,c;u8 flag,pad;} Params;

typedef struct {u8 a,b,c,d;u16 file,pad;} Record_021DF41C;

typedef struct {u8 a,b,c,d;u16 file;} Record_021E009C;

struct Record_021E009C { u8 a, b, c, d; int value; };

typedef struct Rect_021DF388 { unsigned int x0, y0, x1, y1; } Rect_021DF388;

struct Data_021DF388 { void *a, *b, *c, *d; u16 heap; u16 pad; void *e; };

typedef unsigned int u32_021E06D0;

struct Source { int words[10]; };

typedef unsigned int   u32_021E0774;

typedef unsigned int u32_021E07A4;

struct Object { int capacity; int entries[4]; int unused; void *vector; void *a; void *b; void *c; };

typedef unsigned int   u32_021E0808;


typedef unsigned int   u32_021E0840;

typedef unsigned int u32_021E0954;

typedef unsigned int u32_021E0A88;

typedef unsigned long u32_021E0C04;

typedef short s16_021E06D0;

struct Params {s16_021E06D0 x,y,a,b,z;u8 mode,flag;};

typedef unsigned int   u32_021E0D00;

struct Coordinates { u8 pad[0x298]; u8 rect[32][4]; };

typedef unsigned int   u32_021E0D38;

typedef unsigned int   u32_021E0D90;

typedef unsigned long u32_021E0E90;

typedef struct {s16_021E06D0 a,b,x,y;} Coords;

typedef unsigned int   u32_021E10DC;

extern unsigned func_021F9B9C(struct Obj24810 *p);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void * func_02082BCC(void *,int,unsigned);
extern u32 func_0201C440(void *p);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern void func_021FD940(u8 *p, u32 value);
extern int *func_021FD6D8(int payload, int callback, u32 heap);
extern void func_021FD820(char *);
extern void func_021FD714(void *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020315D4(struct S020315D4 *);
extern void func_021FD71C(u8 *p);
extern void func_021FD854(char *);
extern int func_021FD72C(int *);
extern u32 func_0201C4E4(struct PrintSys *);
extern void func_021FD860(void *, unsigned, const void *);
extern int func_021FD938(char *);
extern void *func_021FC6A4(unsigned short,unsigned,unsigned short,unsigned short,unsigned char,unsigned char,void *,unsigned short);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void func_021FC754(char *,void *,void *,void *,unsigned short);
extern void func_021FE794(char *p, u32 index, u32 a, u32 b, u32 c);
extern int func_021FE7B0(int *);
extern void func_021FC734(u8 *p);
extern void func_021FEE24(char *p);
extern int func_021FC830(u8 *p);
extern void func_021F9BF4(unsigned *,unsigned);
extern int *func_021FD73C(int *p, int v);
extern void func_020061E4(u32 a);
extern void func_020409B4(u32 index);
extern int func_02035C60(void);
extern void func_021FEE74(char *p);
extern void func_021F9BA0(unsigned *ctx);
extern void func_021FEE9C(char *p);
extern void func_021FEE4C(char *p);
extern int func_021FD744(int *a);
extern void func_021FC1F8(int *,int);
extern void func_021FC148(char *p, unsigned i, unsigned heap);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern struct Obj *func_021F9CB8(int a, int b, int c, int d, int e, int f, u32 heap);
extern void func_021FE840(int,int,int);
extern void func_021FE784(int,int,int,int);
extern int func_021FA018(char *),func_021FA01C(char *);
extern void func_021F9FE8(char *);
extern int func_021FA004(char *,int *,int *);
extern int func_021FC238(char *),func_021FC224(char *);
extern void func_021FC230(char *,int),func_021FE7F4(int *,int);
extern u32 func_02035D20(u32 *,u32 *);
extern void *func_020056A0(void (*)(void),void *,int);
extern void func_02030EAC(struct Node *n);
extern void func_021FC240(char *p, void *owner, unsigned short heap);
extern void * func_02025538(unsigned,void *);
extern char * func_0200B928(void);
extern struct ObjC4 *func_0200B910(void);
extern unsigned long long func_0200B98C(u8 *p, int selector, int index);
extern void func_021FD15C(void *,int);
extern void func_02025588(void *p);
extern u8 func_02012E40(const u8 *o);
extern int func_021FF88C(char *p);
extern void func_021F9C6C(void *);
extern int func_021FD6B0(u8 *p);
extern void func_021FD1BC(void *);
extern int func_021FB4B4(unsigned int *obj, int x, int y);
extern void func_021F9C50(S_021DB2E0 *);
extern void func_021FD170(char *p, char *q, void *text);
extern void func_021FF54C(char *p, int kind, const int *values);
extern int func_021FF648(char *p);
extern int func_021FF72C(char *p, int *out);
extern int func_021FF698(char *,int,int *);
extern void *func_02012EBC(struct Big *p);
extern void func_0200B938(const void *,const void *,const void *,unsigned int);
extern int func_02006254(u32 a);
extern int func_021D7630(void *a, int x, u16 *state, u16 *b, u16 c);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_0200B490(void);
extern int func_02012DAC(int),func_02012DD0(u8 *);
extern int func_021FC21C(char *);
extern void func_021FC868(u8 *p, u32 a, u32 b, u32 c);
extern void func_021FC7C4(char *,void *,void *,u16);
extern struct U16Vec *func_020457B0(u32 capacity, u16 heapId);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_0200D6D0(const void *,u32);
extern void *func_0200D774(struct GdsProfile *p, struct GdsRecord *out, u32 tag);
extern u32 func_0200D6EC(struct RecGet *p);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0201BC3C(void),func_0201BC40(void),func_0201BCB4(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_0201BABC(u32,u32,u32,u32),func_0201BB5C(u32,u32,u32,u32);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_02049238(void *);
extern char *func_021FD1C4(void *prof, char *q, void *a2, void *a3, int mode, u16 heap);
extern void func_021FD640(int *);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_021FBE54(char *,u32,u32);
extern int func_021FC124(void *,int,Triple *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
extern void func_021FB494(char *p);
extern void func_021FC0C8(char *p, unsigned i);
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern u16 func_0200DABC(struct Blk1AC *p);
extern u32 func_0200DB44(struct Blk1AC *p, u32 i);
extern u16 func_0200DAC4(struct Blk1AC *p, u32 i);
extern u16 func_0200DAD8(struct Blk1AC *p, u32 i);
extern u8 func_0200DC08(struct Blk1AC *p);
extern u32 func_0200DBA0(struct Blk1AC *p, s32 i, u32 op);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *,int);
extern void func_0204B878(struct Obj *p, u16 value);
extern u16 func_0200DFD8(Row *,int,int);
extern u8 *func_02012944(void *p);
extern void func_0201F02C(struct WordSet *,u32,void *);
extern void func_02045CAC(struct MsgBank *,u32,void *);
extern int func_021FF6DC(char *p, void *buffer, int count, int *out);
extern int func_021FF704(char *p, void *buffer, int count, int *out);
extern int func_021FF6B4(char *p, void *buffer, int count, int *out);
extern struct WordSet *func_0201EC64(u32 heap);
extern Slot_021DB2E0 *func_0201F81C(u32,u32);
extern void *func_021FC8C8(const Config_021DF1DC *,u16);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7D0(void *x, s16_021DB2E0 y, s16_021DB2E0 z, void *s, void *w, u16 v);
extern void func_021FCDAC(u8 *p, u16 i, u32 v);
extern void func_021FCE50(char *p);
extern int func_021FCE0C(char *p, unsigned field);
extern u32 func_021FCDE8(u8 *p, u16 i);
extern void func_020437AC(struct Obj020437AC *p);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_021FCC80(char *p);
extern u32 func_0201F868(void *p);
extern void func_021FCD0C(char *p);
extern int func_021FCDA8(char *);
extern int func_0201BC3C(void);
extern int func_0201BC40(void);
extern u32 func_0204B3F4(struct Obj *p);
extern u32 func_0204B714(struct Obj *o);
extern void func_0204B7C8(const char *src, struct Struct36 *dst);
extern void func_0204B784(char *dst, const struct Struct36 *src);
extern void *func_02049E74(void *,u32,u32,u32,u16);
extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern void func_0204AB84(u32,struct Rec *);
extern u32 func_020307B0(void *p);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern int func_021FB4CC(u32 *p, int a1, int a2);
extern void func_0201F878(Slot_021DB2E0 *table, u32 a, u32 b, u32 tag, u32 heap);
extern void *func_0200CA1C(void *);
extern char *func_021FFBD4(void *, void *, int, int, int, int, int, u16);
extern void func_021FFE5C(char *);
extern unsigned func_021FFE34(char *p);
extern void func_021FFE70(char *p);
extern void func_021FFC6C(char *p);
extern int func_021FFC9C(char *);
extern int func_021FFE90(int *, u16 *);
extern void func_0201F898(Slot_021DB2E0 *table, u32 a, u32 b, u32 tag);
extern u8 func_02025B64(u32);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void *func_02030734(u32_021E06D0 heapId, u32_021E06D0 size, int clear, const char *site, u16 tag);
extern void func_021E1244(char *);
extern void func_021E1910(char *);
extern int func_021E16E4(char *p);
extern void func_02051C6C(void *);
extern void func_0204B92C(struct Obj *p, u32_021E0A88 v);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32_021E0C04 which);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B8C4(struct Obj *p, u32_021E0D38 value);
extern u16 func_0204B898(struct Obj *p);
extern u32_021E0D90 func_0204B98C(struct Actor *a);
extern void func_0202570C(struct Grid *);
extern void func_021E111C(const void *,int,int,int,int);
int func_021DB2E0(int *task, int unused, char *p);
int func_021DB36C(struct S020315D4 *task,int b,int c,char *p);
int func_021DB394(int a,int b,int c,char *p);
void func_021DB3C4(int *task,int *state,char *p);
void func_021DB594(int *task, int *state, char *p);
void func_021DB61C(int *task, int *state, char *p);
void func_021DB690(int *task);
int func_021DB698(int *task,int b,char *p);
int func_021DB740(struct S020315D4 *task,int b,char *q,char *p);
int func_021DB770(int *task,int *state,char *p,char *q);
void func_021DB924(int a0, char *p);
int func_021DB940(int *task,int *state,char *q);
int func_021DBB3C(int task,int b,char *q,char *p);
int func_021DBBC4(int a,int b,int c,char *p);
void func_021DBC68(int a, int b, char *p);
void func_021DBCA8(int *task, int *state, char *p);
void func_021DBCF4(int *task, int *state, char *p);
void func_021DBD40(int *task,int b,char *p);
void func_021DBD7C(int *task,int *state,char *p);
void func_021DBEB0(int *task,int *state,char *p);
void func_021DBFB0(int *a,int *state,char *p);
void func_021DC228(int *a,int *state,char *p);
void func_021DC4FC(int *a,int *state,char *p);
void func_021DC638(int *a,int *state,char *p);
void func_021DC8EC(char *p,char *q);
void func_021DCBD8(char *p,void *manager,void *party,u16 heap);
void func_021DCDD8(char *p, char *q);
void func_021DCE28(char *p,char *unused);
void func_021DCE48(char *p,char *q);
void func_021DCEE4(char *p,char *q);
void func_021DD054(char *p, char *q);
void func_021DD0AC();
void func_021DD0F4(char *p, char *a1);
void func_021DD128(char *p, char *q);
void func_021DD1D4(char *p, char *q);
int func_021DD228(void *p);
int func_021DD25C(void *p);
int func_021DD27C(char *p, int a, int b);
int func_021DD2BC(char *p, int a, int b);
int func_021DD2FC(char *p, int a, int b);
int func_021DD33C(char *p, int a, int b);
int func_021DD37C(void *a, int unused, char *q);
int func_021DD3F8(struct S020315D4 *a, int unused, char *q, char *p);
int func_021DD440(void *unused,u32 *state,char *q,char *p);
void func_021DD5C8(char *p, char *q);
void func_021DD684(char *p,char *q);
void func_021DD858(char *p,char *q);
void func_021DDA2C(char *p, char *q);
void func_021DDCCC(char *p,char *q);
void func_021DDDE8(char *p, char *q);
void func_021DDE2C(char *p,char *q);
void func_021DDF5C(char *p, char *q);
int func_021DDFA0(char *p, int x, int y);
int func_021DE000(void *p,char *q);
int func_021DE02C(void *p, void *q);
int func_021DE058(void *p, void *q);
void func_021DE084(char *p, void *manager, const char *q, unsigned int value, s16_021DB2E0 x, s16_021DB2E0 y, u16 heap);
void func_021DE12C(char *p);
void func_021DE15C(char *p, u32 value);
int func_021DE1C8(void *a, int b, char *q);
int func_021DE234(void *a, int b, char *q, char *p);
int func_021DE274(void *unused,u32 *state,char *q,char *p);
void func_021DE3E4(char *p, char *q);
void func_021DE404(char *p,char *q);
void func_021DE55C(char *p,char *q);
void func_021DE66C(char *p,char *q);
void func_021DE780(char *p, char *q);
void func_021DE7C0(char *p,char *q);
void func_021DE8FC(char *p, char *q);
int func_021DE940(char *p, int x, int y);
int func_021DE9A0(void *a, int b, char *q);
int func_021DEA30(void *a, int b, char *q, char *p);
int func_021DEADC(int a, int b, int c, char *p);
void func_021DEB4C(int *task,int *state,char *p);
void func_021DECB0(void *a, int b, char *p);
void func_021DED14(int *a, int *state, char *p);
void func_021DED64(int *p, int *state, char *q);
void func_021DEDB4(int *task, int *state, char *p);
void func_021DEE7C(int *task,u32 *state,char *p);
void func_021DF0DC(int *p, int *state, char *q);
void func_021DF18C(int *p, int *state, char *q);
void func_021DF1DC(Menu *p,char *base,char *res,u32 mgr,u32 a5,u32 a6,u16 *sel,u16 heap);
void func_021DF388(char *p);
void func_021DF3DC(char *p, u16 a);
int func_021DF41C(char *p);
void func_021DF428(struct State_021DF428 *p,u32 mgr,u16 heap);
void func_021DF5B8(char *p);
void func_021DF620(struct State_021DF428 *p,int first,short step,u16 heap);
void func_021DF838(int p, char *out);
int func_021DF8F0(int x, int y);
int func_021DF920(void *obj, int unused, char *q);
int func_021DF9C8(void *p, int unused, char *q, char *data);
int func_021DFA10(void *unused,u32 *state,int *q,char *p);
int func_021DFB90(char *p,char *q);
int func_021DFC88(char *p, char *q);
int func_021DFCD4(char *p,char *q);
int func_021DFE98(char *p,char *q);
int func_021DFF78(char *p, char *q);
int func_021DFFB0(char *p, char *q);
void func_021E0044(char *p, char *q);
int func_021E0080(char *p);
int func_021E009C(char *p, char *q);
int func_021E00D8(char *p,char *q);
int func_021E0214(char *p, char *q);
int func_021E024C(char *p, char *q);
void func_021E02F8(char *p, int *q);
void func_021E037C(char *p,char *q);
void func_021E03B0(char *p,char *q,int mode);
int func_021E04C8(void);
int func_021E050C(void *task, int unused, char *q);
int func_021E05C4(void *a, int unused, int *q, void **p);
int func_021E0618(int unused, int *state, int *q, int *p);
char *func_021E06D0(const struct Source *src, u16 heap);
void func_021E0754(char *p);
int func_021E075C(char *p);
u64 func_021E0764(char *p);
void func_021E0774(char *p);
struct Object *func_021E07A4(int heap, int n, void *a, void *b, void *c, int *entries);
void func_021E0808(char *p);
void func_021E083C(void);
void func_021E0840(char *p);
void func_021E08E4(char *p);
void func_021E0954(char *p);
void func_021E0A88(char *p);
void func_021E0C04(char *p);
void func_021E0CE8(char *p, int index, int a2);
void func_021E0D00(char *p,int i);
void func_021E0D38(struct Coordinates *p, int index);
void func_021E0D90(char *p);
int func_021E0E40(int a, int b);
void func_021E0E4C(char *p);
void func_021E0E90(char *p,int animated);
void func_021E1008(char *p);
void func_021E10A0(char *p);
void func_021E10BC(char *p);
void func_021E10DC(char *p);
void func_021E10F4(char *p);
extern int d_021E3280[];
extern char d_021E3960[];
extern const Descriptor d_021E32C8[];
extern const Pair_021DB2E0 d_021E32F0[];
extern const struct Record_021DB2E0 d_021E32A8[];
extern const struct Record_021DD1D4 d_021E3350[];
extern const struct Record_021DD684 d_021E33C0[];
extern const struct Record_021DD684 d_021E3400[];
extern const struct Record_021DD1D4 d_021E3490[];
extern const struct Record_021DDCCC d_021E338C[];
extern const struct Record_021DD1D4 d_021E336C[];
extern const Rect_021DB2E0 d_021E3440[];
extern const u32 d_021E3358[];
extern const Record d_021E3574[];
extern const Record d_021E3664[];
extern const Record d_021E35D4[];
extern const Record d_021E351C[];
extern const Rect_021DB2E0 d_021E3534[];
extern const char d_021E3964[];
extern const CfgTpl d_021E3700;
extern const struct Methods d_021E37A8[];
extern const struct Rec6 d_021E3734[];
extern const struct Rec8 d_021E3740[];
extern const Config d_021E3758;
extern const Record_021DF41C d_021E3728[];
extern const Config d_021E3780;
extern const Record_021E009C d_021E372E[];
extern const struct Record_021E009C d_021E37D8[];
extern int d_020A7370;
extern Rect_021DF388 g_021E3808[];
extern char d_021E3968[];
extern char d_021E3974[];
extern char d_021E3978[];














int func_021DB2E0(int *task, int unused, char *p)
{
    char *s;
    void *callback;
    s=func_0203159C((struct Obj0203159C *)task,0x20,func_021F9B9C(((struct Obj03879 *)p)->f10));
    func_02082BCC(s,0,0x20);
    *(char * *)&((struct Obj02228 *)s)->f1C=p;
    ((struct Obj02228 *)s)->f4=func_021F9B9C(((struct Obj03879 *)p)->f10);
    ((struct Obj02228 *)s)->fC=(void *)func_0201C440((void *)(((struct Obj02228 *)s)->f4));
    ((struct Obj02228 *)s)->f14=func_021FD760(((struct Obj03879 *)p)->f4,(char *)(((struct Obj03879 *)p)->fC),0,((struct Obj02228 *)s)->f4);
    ((struct Obj02228 *)s)->f18=func_021FD760(((struct Obj03879 *)p)->f4,(char *)(((struct Obj03879 *)p)->fC),1,((struct Obj02228 *)s)->f4);
    func_021FD940(((struct Obj02228 *)s)->f14,1);
    func_021FD940(((struct Obj02228 *)s)->f18,1);
    if(((struct Obj03879 *)p)->f0==0) callback=func_021DB3C4;
    else if(((struct Obj03879 *)p)->f0==1) callback=func_021DB594;
    else callback=func_021DB61C;
    ((struct Obj02228 *)s)->f0=func_021FD6D8((int)s,(int)callback,((struct Obj02228 *)s)->f4);
    return 1;
}














int func_021DB36C(struct S020315D4 *task,int b,int c,char *p) { func_021FD820(*(char * *)&((struct Obj08308 *)p)->f14); func_021FD820(*(char * *)&((struct Obj08308 *)p)->f18); func_0201C4C0(((struct Obj08308 *)p)->fC); func_021FD714((void *)(((struct Obj08308 *)p)->f0)); func_020315D4(task); return 1; }














int func_021DB394(int a,int b,int c,char *p) { func_021FD71C((u8 *)(*(int *)&((struct Obj06595 *)p)->f0)); func_0201C4E4(*(struct PrintSys * *)&((struct Obj06595 *)p)->fC); func_021FD854(*(char * *)&((struct Obj06595 *)p)->f14); func_021FD854(*(char * *)&((struct Obj06595 *)p)->f18); if(func_021FD72C(*(int * *)&((struct Obj06595 *)p)->f0)) return 1; return 0; }














/*
 * lever: enum-valued one-bit mask preserves the original call/mask scheduling, as in sibling 021DB594.
 * abi: 02035C60 returns a full word consumed by the original caller's comparison.
 */
void func_021DB3C4(int *task,int *state,char *p)
{
    int a,b;
    switch(*state) {
    case 0: {int args[2];args[0]=128;args[1]=96;func_021FD860((void *)(*(int *)&((struct Obj00630 *)p)->f14), 2, (const void *)args);func_020061E4(0x700);*state=1;break;}
    case 1: if(func_021FD938(*(char * *)&((struct Obj00630 *)p)->f14))*state=2;break;
    case 2: {int args[2];args[0]=128;args[1]=-8;func_021FD860((void *)(*(int *)&((struct Obj00630 *)p)->f18), 3, (const void *)args);*state=3;break;}
    case 3: if(func_021FD938(*(char * *)&((struct Obj00630 *)p)->f18))*state=4;break;
    case 4:
        ((struct Obj00630 *)p)->f8=func_021FC6A4(4,8,16,16,2,14,((struct Obj00630 *)p)->fC,((struct Obj00630 *)p)->f4);
        a=func_021FC20C(*(char * *)&((struct Obj24519 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->fC);
        b=func_021FC214(*(char * *)&((struct Obj24520 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->fC);
        func_021FC754(*(char * *)&((struct Obj00630 *)p)->f8,(void *)b,(void *)228,(void *)a,0x440);
        func_021FE794((char *)(((struct Obj24521 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8),3,15,1,4);*state=5;break;
    case 5: if(func_021FE7B0(*(int * *)&((struct Obj24522 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8))*state=6;break;
    case 6: func_021FE794((char *)(((struct Obj24523 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8),3,15,0,4);*state=7;break;
    case 7: if(func_021FE7B0(*(int * *)&((struct Obj24524 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8))*state=8;break;
    case 8: if(func_02035C60()) {func_020061E4(0x6ff);func_021FC734(((struct Obj00630 *)p)->f8);*(int *)&((struct Obj00630 *)p)->f8=0;func_020409B4(4);*state=9;}break;
    case 9: func_021FE794((char *)(((struct Obj24525 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8),3,3,0,48);func_021FEE24((char *)(((struct Obj24526 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f14));*state=10;break;
    case 10: {enum {ONE=1} mask=ONE;if(func_021FE7B0((int *)(*(int * *)&((struct Obj24527 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8))&mask) {func_021FD860((void *)(*(int *)&((struct Obj00630 *)p)->f18), 8, (const void *)0);*state=11;}break;}
    case 11: func_021FE794((char *)(((struct Obj24528 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8),2,3,1,1);*state=12;break;
    case 12: if(func_021FE7B0(*(int * *)&((struct Obj24529 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8))*state=13;break;
    case 13: if(func_021FD938(*(char * *)&((struct Obj00630 *)p)->f18)) {func_021F9BF4(*(unsigned * *)&((struct Obj24530 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f10,1);func_021FD73C(task,(int)func_021DB690);}break;
    }
    if(((struct Obj00630 *)p)->f8)func_021FC830(((struct Obj00630 *)p)->f8);
}














/*
 * lever: enum mask local materializes one before the call; int mask left nine bytes different
 */
void func_021DB594(int *task, int *state, char *p)
{
    switch(*state) {
    case 0: *state=1; break;
    case 1:
        func_021FEE74((char *)(((struct Obj24531 *)(*(char * *)&((struct Obj05470 *)p)->f1C))->f14));
        *state=2;
        break;
    case 2:
        if((((struct Obj05470 *)p)->f10)++ !=0) {
            ((struct Obj05470 *)p)->f10=0;
            func_021FE794((char *)(((struct Obj24532 *)(*(char * *)&((struct Obj05470 *)p)->f1C))->f8),3,3,1,26);
            *state=3;
        }
        break;
    case 3:
    {
        enum { MASK=1 } mask=MASK;
        if(func_021FE7B0(*(int * *)&((struct Obj24533 *)(*(char * *)&((struct Obj05470 *)p)->f1C))->f8)&mask) *state=4;
        break;
    }
    case 4:
        func_021F9BA0(((struct Obj24534 *)(*(char * *)&((struct Obj05470 *)p)->f1C))->f10);
        func_021FD73C(task,(int)func_021DB690);
        break;
    }
}














void func_021DB61C(int *task, int *state, char *p)
{
    switch(*state) {
    case 0:
        func_021FE794((char *)(((struct Obj24535 *)(*(char * *)&((struct Obj06597 *)p)->f1C))->f8),2,3,1,1);
        *state=1;
        break;
    case 1:
        if(func_021FE7B0(*(int * *)&((struct Obj24536 *)(*(char * *)&((struct Obj06597 *)p)->f1C))->f8)) *state=2;
        break;
    case 2:
        func_021FEE9C((char *)(((struct Obj24537 *)(*(char * *)&((struct Obj06597 *)p)->f1C))->f14));
        func_021FEE4C((char *)(((struct Obj24538 *)(*(char * *)&((struct Obj06597 *)p)->f1C))->f14));
        func_021F9BF4((unsigned int *)(((struct Obj24539 *)(*(char * *)&((struct Obj06597 *)p)->f1C))->f10),1);
        func_021FD73C(task,(int)func_021DB690);
        break;
    }
}














void func_021DB690(int *task)
{
    func_021FD744((int *)task);
}














/*
 * extent: two bytes of zero alignment padding at 0x021DB73E
 */
int func_021DB698(int *task,int b,char *p)
{
    char *s;
    s=func_0203159C((struct Obj0203159C *)task,24,func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct Obj01072 *)p)->f1C)));
    func_02082BCC(s,0,24);
    *(char * *)&((struct Obj02517 *)s)->fC=p;
    ((struct Obj02517 *)s)->f14=func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct Obj01072 *)p)->f1C));
    func_021FC1F8(*(int * *)&((struct Obj01072 *)p)->f18,0);
    func_021FC1F8(*(int * *)&((struct Obj01072 *)p)->f18,1);
    func_021FC148((char *)(*(int * *)&((struct Obj01072 *)p)->f18),0,((struct Obj02517 *)s)->f14);
    func_021FC148((char *)(*(int * *)&((struct Obj01072 *)p)->f18),1,((struct Obj02517 *)s)->f14);
    if(((struct Obj01072 *)p)->f0<5) func_021FB964(*(int * *)&((struct Obj01072 *)p)->f18,3,((struct Obj02517 *)s)->f14);
    else func_021FB964(*(int * *)&((struct Obj01072 *)p)->f18,4,((struct Obj02517 *)s)->f14);
    ((struct Obj02517 *)s)->f4=(int)func_021FD760(((struct Obj01072 *)p)->f14,(char *)(*(int *)&((struct Obj01072 *)p)->f18),1,((struct Obj02517 *)s)->f14);
    ((struct Obj02517 *)s)->f0=(int)func_021F9CB8(((struct Obj01072 *)p)->f0,((struct Obj01072 *)p)->f14,*(int *)&((struct Obj01072 *)p)->f18,((struct Obj01072 *)p)->f20,((struct Obj01072 *)p)->f24,((struct Obj02517 *)s)->f4,((struct Obj02517 *)s)->f14);
    if(((struct Obj01072 *)p)->fC==4) func_021FE840(((struct Obj01072 *)p)->f10,2,0);
    else func_021FE840(((struct Obj01072 *)p)->f10,3,0);
    return 1;
}














/*
 * lever: Explicit call arms preserve the original conditional argument branch.
 */
int func_021DB740(struct S020315D4 *task,int b,char *q,char *p) { if(((struct Obj10727 *)q)->f0<5) func_021FBDA4(((struct Obj10727 *)q)->f18,3); else func_021FBDA4(((struct Obj10727 *)q)->f18,4); func_021F9F48(*(u8 * *)&((struct Obj14419 *)p)->f0); func_021FD820(*(char * *)&((struct Obj14419 *)p)->f4); func_020315D4(task); return 1; }














/*
 * lever: explicit case-3 call arms preserve the original block shape; ARM9 division helper uses the proven _u32_div_f ABI.
 */
int func_021DB770(int *task,int *state,char *p,char *q)
{
    u32 x,y;
    switch(*state) {
    case 0: func_021FE784(*(int *)&((struct Obj01004 *)p)->f10,((struct Obj01004 *)p)->fC,3,0);*state=1;break;
    case 1: if(func_021FE7B0(*(int * *)&((struct Obj01004 *)p)->f10))*state=2;break;
    case 2:
        if(((struct Obj01004 *)p)->f0<=4 && !func_021FA018(*(char * *)&((struct Obj02891 *)q)->f0) && func_02035D20(&x,&y)) {
            if(x<8 || x>248) {func_020061E4(0x703);*state=6;break;}
        }
        func_021F9FE8(*(char * *)&((struct Obj02891 *)q)->f0);
        if(func_021FA004(*(char * *)&((struct Obj02891 *)q)->f0,(int *)(p+4),(int *)(p+8))) *state=3;
        break;
    case 3:
        if(((struct Obj01004 *)p)->f4==12)func_021FE784(*(int *)&((struct Obj01004 *)p)->f10,4,3,1);
        else func_021FE784(*(int *)&((struct Obj01004 *)p)->f10,2,3,1);
        *state=4;break;
    case 4: if(func_021FE7B0(*(int * *)&((struct Obj01004 *)p)->f10))*state=5;break;
    case 5:
        switch(func_021FA004(*(char * *)&((struct Obj02891 *)q)->f0,(int *)(p+4),(int *)(p+8))) {
        case 1: func_021F9BF4(*(unsigned * *)&((struct Obj01004 *)p)->f1C,(unsigned short)((struct Obj01004 *)p)->f4);return 1;
        case 2: func_021F9BA0(((struct Obj01004 *)p)->f1C);**(int * *)&((struct Obj01004 *)p)->f28=func_021FA01C(*(char * *)&((struct Obj02891 *)q)->f0);return 1;
        }
        break;
    case 6: {
        int v=func_021FC238(*(char * *)&((struct Obj01004 *)p)->f18);u32 i;
        for(i=0;i<7;i++) {if(v==d_021E3280[i]) {v=d_021E3280[(i+1)%7];break;}}
        func_021FC230(*(char * *)&((struct Obj01004 *)p)->f18,v);
        func_021FE7F4(*(int * *)&((struct Obj01004 *)p)->f10,func_021FC224(*(char * *)&((struct Obj01004 *)p)->f18));
        func_021FE784(*(int *)&((struct Obj01004 *)p)->f10,3,3,1);*state=7;break;
    }
    case 7: if(func_021FE7B0(*(int * *)&((struct Obj01004 *)p)->f10))*state=8;break;
    case 8: ((struct Obj02891 *)q)->f8=func_020056A0((void (*)(void))func_021DB924,q,0);((struct Obj02891 *)q)->f10=0;*state=9;break;
    case 9: if(((struct Obj02891 *)q)->f10) {func_02030EAC(((struct Obj02891 *)q)->f8);*state=10;}break;
    case 10: func_021FE784(*(int *)&((struct Obj01004 *)p)->f10,3,3,0);*state=11;break;
    case 11: if(func_021FE7B0(*(int * *)&((struct Obj01004 *)p)->f10))*state=2;break;
    }
    func_021FD854(*(char * *)&((struct Obj02891 *)q)->f4);return 0;
}















void func_021DB924(int a0, char *p)
{
    int v = ((struct Obj08309 *)p)->f10;
    char *q = *(char * *)&((struct Obj08309 *)p)->fC;

    if (v == 0) {
        func_021FC240((char *)(((struct Obj14420 *)q)->f18), (void *)(((struct Obj14420 *)q)->f10),
                      ((struct Obj08309 *)p)->f14);
    }
    ((struct Obj08309 *)p)->f10 = 1;
}














/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * lever: shared state-flag store and distinct case-5 null path preserve the original switch layout.
 * blocker-C: copied prior verified Thumb EXACT from ov183_func_021DF838.c header, blocker-r2.log; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 func_0200B98C_Table[];
 * u64 func_0200B98C(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==func_0200B98C_Table[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 */
int func_021DB940(int *task,int *state,char *q)
{
    char *p,*s;
    int i;
    p=func_0203159C((struct Obj0203159C *)task,0xe8,func_021F9B9C((struct Obj24810 *)(*(char **)(q+0x14))));
    func_02082BCC(p,0,0xe8);
    *(unsigned short *)(p+0xb4)=func_021F9B9C((struct Obj24810 *)(*(char **)(q+0x14)));
    *(int *)(p+0xb0)=0;
    *(char **)(p+0xd0)=q;
    *(void **)p=func_02025538(*(unsigned short *)(p+0xb4),*(void **)(q+0x18));
    *(void **)(p+4)=(void *)func_0201C440((void *)(*(unsigned short *)(p+0xb4)));
    *(void **)(p+8)=func_021FD6D8((int)p,0,*(unsigned short *)(p+0xb4));
    for(i=0;i<2;i++) *(char **)(p+i*4+0xc)=func_021FD760(*(unsigned *)(q+0x18),*(char **)(q+0x10),i,*(unsigned short *)(p+0xb4));
    switch(*(int *)(*(char **)(p+0xd0)+8)) {
    case 4:
        s=*(char **)(*(char **)(p+0xd0)+0x30);
        *(char **)(p+0xc4)=s+*(int *)(s+0x171c)*0xc4+0x80;
        s=*(char **)(*(char **)(p+0xd0)+0x30);
        *(char **)(p+0xc0)=s+*(int *)(s+0x171c)*0xc4;
        *(int *)(p+0xcc)=1;
        if(**(int **)(*(char **)(p+0xd0)+0x3c) && *(int *)(*(char **)(p+0xd0)+0x34)) {
            s=*(char **)(*(char **)(p+0xd0)+0x30);
            *(s+*(int *)(s+0x171c)+0x16f8)=1;
        }
        s=*(char **)(*(char **)(p+0xd0)+0x30);
        *(int *)(p+0xc8)=*(unsigned char *)(s+*(int *)(s+0x171c)+0x16f8);
        break;
    case 0:
        *(char **)(p+0xc4)=func_0200B928();*(char **)(p+0xc0)=(char *)func_0200B910();
        *(int *)(p+0xc8)=1;i=0;goto set_cc;
    case 1: case 2: case 3:
        *(char **)(p+0xc4)=func_0200B928();*(char **)(p+0xc0)=(char *)func_0200B910();
        *(int *)(p+0xc8)=func_0200B98C(*(void **)(p+0xc4),5,0);*(int *)(p+0xcc)=0;break;
    case 5:
        if(*(int *)(*(char **)(p+0xd0)+0x34)==0) {
            *(int *)(p+0xc4)=0;*(int *)(p+0xc0)=0;
        }else {
            *(char **)(p+0xc4)=func_0200B928();*(char **)(p+0xc0)=(char *)func_0200B910();
            *(int *)(p+0xc8)=**(int **)(*(char **)(p+0xd0)+0x3c);
        }
        i=1;
    set_cc:
        *(int *)(p+0xcc)=i;
        break;
    }
    if(*(int *)(*(char **)(p+0xd0)+8)==5) {
        if(*(int *)(*(char **)(p+0xd0)+0x34)==0)func_021FD73C(*(int **)(p+8),(int)func_021DBFB0);
        else func_021FD73C(*(int **)(p+8),(int)func_021DBC68);
    }else if((u32)(*(int *)(*(char **)(p+0xd0)+8)-1)<=2 && *(int *)(*(char **)(p+0xd0)+0x34) && **(int **)(*(char **)(p+0xd0)+0x3c) && *(int *)(p+0xc8)==0) {
        func_021FD73C(*(int **)(p+8),(int)func_021DC4FC);
    }else func_021FD73C(*(int **)(p+8),(int)func_021DBC68);
    return 1;
}














int func_021DBB3C(int task,int b,char *q,char *p)
{
    int i;
    func_021DCE28(p,q);
    func_021DCE48(p,q);
    func_021DD054(p,q);
    func_021DD0F4(p,q);
    func_021DD1D4(p,q);
    ((struct Obj06598 *)q)->f4=((struct Obj00050 *)p)->fC8;
    func_020409B4(4);
    func_020409B4(1);
    if(((struct Obj00050 *)p)->f18) {
        func_021FD15C(((struct Obj00050 *)p)->f18,((struct Obj24541 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f10);
        ((struct Obj00050 *)p)->f18=0;
    }
    for(i=0;i<2;i++) func_021FD820(*(char **)(p+i*4+0xc));
    func_021FD714((void *)(((struct Obj00050 *)p)->f8));
    func_0201C4C0(((struct Obj00050 *)p)->f4);
    func_02025588((void *)(((struct Obj00050 *)p)->f0));
    func_020315D4((struct S020315D4 *)task);
    return 1;
}














/*
 * extent: two bytes of zero alignment padding at 0x021DBC66
 */
int func_021DBBC4(int a,int b,int c,char *p)
{
    int i;
    if(func_02012E40(((struct Obj24542 *)(*(char * *)&((struct Obj02892 *)p)->fD0))->f28)==0 && func_021FF88C(((struct Obj24543 *)(*(char * *)&((struct Obj02892 *)p)->fD0))->f24)==2) {
        func_021F9C6C(((struct Obj24544 *)(*(char * *)&((struct Obj02892 *)p)->fD0))->f14);
        return 1;
    }
    func_021FD71C(((struct Obj02892 *)p)->f8);
    if(func_021FD72C(((struct Obj02892 *)p)->f8)) return 1;
    for(i=0;i<2;i++) func_021FD854(*(void **)(p+i*4+0xc));
    func_0201C4E4(((struct Obj02892 *)p)->f4);
    for(i=0;i<2;i++) if(*(void **)(p+i*4+0x28)) func_021FC830(*(void **)(p+i*4+0x28));
    for(i=0;i<5;i++) if(*(void **)(p+i*4+0x30)) func_021FC830(*(void **)(p+i*4+0x30));
    if(((struct Obj02892 *)p)->f44) func_021FD6B0(((struct Obj02892 *)p)->f44);
    if(((struct Obj02892 *)p)->f18) func_021FD1BC(((struct Obj02892 *)p)->f18);
    return 0;
}













/*
 * Flush the object, dispatch on the p+0xB0 flag, then chain to 0x21FD73C.
 */
void func_021DBC68(int a, int b, char *p)
{
    func_021DCEE4(p, (char *)(((struct Obj00730 *)p)->fD0));
    if (((struct Obj00730 *)p)->fB0 != 0)
        func_021DCDD8(p, (char *)(((struct Obj00730 *)p)->fD0));
    else
        func_021DC8EC(p, (char *)(((struct Obj00730 *)p)->fD0));
    func_021FD73C((int *)a, (int)func_021DBCA8);
}












void func_021DBCA8(int *task, int *state, char *p)
{
    switch(*state) {
    case 0:
        func_021FE784(((struct Obj24545 *)(*(char * *)&((struct Obj14421 *)p)->fD0))->fC,2,3,0);
        *state=1;
        break;
    case 1:
        if(func_021FE7B0(*(int * *)&((struct Obj24546 *)(*(char * *)&((struct Obj14421 *)p)->fD0))->fC)) *state=2;
        break;
    case 2:
        func_021FD73C(task,(int)func_021DBD7C);
        break;
    }
}












void func_021DBCF4(int *task, int *state, char *p)
{
    switch(*state) {
    case 0:
        func_021FE784(((struct Obj24547 *)(*(char * *)&((struct Obj14422 *)p)->fD0))->fC,2,3,1);
        *state=1;
        break;
    case 1:
        if(func_021FE7B0(*(int * *)&((struct Obj24548 *)(*(char * *)&((struct Obj14422 *)p)->fD0))->fC)) *state=2;
        break;
    case 2:
        func_021FD73C(task,(int)func_021DBD40);
        break;
    }
}











void func_021DBD40(int *task,int b,char *p) { if(((struct Obj00050 *)p)->fB0) func_021DCE28(p,*(char * *)&((struct Obj00050 *)p)->fD0); else func_021DCE48(p,*(char * *)&((struct Obj00050 *)p)->fD0); func_021DD054(p,*(char * *)&((struct Obj00050 *)p)->fD0); func_021FD744(task); }











/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * lever: decode each callback literal from its actual PC-relative pool slot; repeated shared loads obscure distinct callback targets.
 * blocker-C: copied prior verified Thumb EXACT from ov183_func_021DF838.c header, blocker-r2.log; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 func_0200B98C_Table[];
 * u64 func_0200B98C(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==func_0200B98C_Table[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 */
void func_021DBD7C(int *task,int *state,char *p)
{
    u32 x,y;
    if(func_02035D20(&x,&y)) {
        if(func_021DD27C(p,x,y)) {
            *(int *)(p+0xb0)^=1;
            func_021FD73C(task,(int)func_021DBEB0);
        }
        if(func_021FB4B4((unsigned int *)(*(int *)(p+0x1c)),x,y)) {
            int args[2];
            args[0]=x;args[1]=y;
            func_021FD860((void *)(*(int *)(p+0x10)), 1, (const void *)args);
            **(int **)(p+0xd0)=0;
            func_021F9BA0(*(void **)(*(char **)(p+0xd0)+0x14));
            func_021FD73C(task,(int)func_021DBCF4);
        }
        if(*(int *)(p+0x20) && func_021FB4B4((unsigned int *)(*(int *)(p+0x20)),x,y)) {
            int args[2];
            args[0]=x;args[1]=y;
            func_021FD860((void *)(*(int *)(p+0x10)), 1, (const void *)args);
            func_021F9BF4(*(unsigned **)(*(char **)(p+0xd0)+0x14),10);
            *(u64 *)(*(char **)(p+0xd0)+0x1c)=func_0200B98C(*(void **)(p+0xc4),4,0);
            func_021FD73C(task,(int)func_021DBCF4);
        }
        if(func_021DD2BC(p,x,y)) {
            if((u32)(*(u32 *)(*(char **)(p+0xd0)+8)-4)<=1)func_021FD73C(task,(int)func_021DC228);
            else if(*(int *)(p+0xc8)==0)func_021FD73C(task,(int)func_021DC638);
            else {
                **(int **)(p+0xd0)=1;
                func_021F9C50((S_021DB2E0 *)(*(S_021DB2E0 **)(*(char **)(p+0xd0)+0x14)));
                func_021FD73C(task,(int)func_021DBCF4);
            }
        }
    }
}











void func_021DBEB0(int *task,int *state,char *p)
{
    int a,b;
    switch(*state) {
    case 0:
        func_021FE784(((struct Obj24549 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC,2,1,1);
        (*state)++;break;
    case 1:
        if(func_021FE7B0(*(int * *)&((struct Obj24550 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC))(*state)++;
        break;
    case 2:
        a=func_021FC20C(*(char * *)&((struct Obj24551 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f10);
        b=func_021FC214(*(char * *)&((struct Obj24552 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f10);
        if(((struct Obj00050 *)p)->fB0) {
            func_021DCE48(p,*(char * *)&((struct Obj00050 *)p)->fD0);
            func_021FC754(*(char * *)&((struct Obj00050 *)p)->f28,(void *)b,(void *)0x72,(void *)a,0x3da0);
            func_021DCDD8(p,*(char * *)&((struct Obj00050 *)p)->fD0);
        }else{
            func_021DCE28(p,*(char * *)&((struct Obj00050 *)p)->fD0);
            func_021FC754(*(char * *)&((struct Obj00050 *)p)->f28,(void *)b,(void *)0x71,(void *)a,0x3da0);
            func_021DC8EC(p,(char *)(*(int *)&((struct Obj00050 *)p)->fD0));
        }
        func_021FE784(((struct Obj24553 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC,2,1,0);
        (*state)++;break;
    case 3:
        if(func_021FE7B0(*(int * *)&((struct Obj24554 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC))func_021FD73C(task,(int)func_021DBD7C);
        break;
    }
}










/*
 * note 2026-10-05: shape copied from matched twin ov183_func_021DC228.c (same state machine, same callees). v1 was 4 bytes off (stack slots of source and index swapped); declaring source before index fixed it. Older draft docs/notes/pkt_ov183_021DBFB0.c.txt (167 B off) superseded.
 */
void func_021DBFB0(int *a,int *state,char *p)
{
    u64 t;
    int message;
    char *source;
    int index;
    u32 x,y;
    int args[2];
    switch(*state) {
    case 0:
        func_021DD0AC(p,*(char **)(p+0xd0));
        func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x14b);*state=1;break;
    case 1: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,0);*state=2;break;
    case 2: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=3;break;
    case 3:
        func_02082BCC(&t,0,8);
        t=*(u64 *)(*(char **)(p+0xd0)+0x1c);
        func_021FF54C(*(void **)(*(char **)(p+0xd0)+0x24),3,(const int *)(&t));
        *(int *)(p+0xbc)=0;*state=4;break;
    case 4:
        ++*(int *)(p+0xbc);
        if(func_021FF648(*(void **)(*(char **)(p+0xd0)+0x24)) && *(u32 *)(p+0xbc)>96) {
            func_021FD860((void *)(*(int *)(p+12)), 0, (const void *)0);*state=5;
        }
        break;
    case 5:
        if(!func_021FF72C(*(void **)(*(char **)(p+0xd0)+0x24),&message)) {
            if(func_021FF698(*(char **)(*(char **)(p+0xd0)+0x24),(int)&source,&index)) {
                *(char **)(p+0xc0)=source;
                *(char **)(p+0xc4)=source+0x80;*state=6;
            } else {
                func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x114);*state=11;
            }
        } else {
            func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)message);*state=11;
        }
        break;
    case 11:
        if(func_02035C60()) {
            func_02035D20(&x,&y);args[0]=x;args[1]=y;
            func_021FD860((void *)(*(int *)(p+0x10)), 1, (const void *)args);func_020061E4(0x703);
            func_021F9BA0((unsigned int *)(*(S_021DBFB0 **)(*(char **)(p+0xd0)+0x14)));*state=12;
        }
        break;
    case 6: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=7;break;
    case 7:
        if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) {
            func_021DD0F4(p,*(char **)(p+0xd0));
            func_021DCEE4(p,*(char **)(p+0xd0));
            func_021DC8EC(p,*(char **)(p+0xd0));*state=8;
        }
        break;
    case 8: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,0);*state=9;break;
    case 9: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=10;break;
    case 10: func_021FD73C(a,(int)func_021DBD7C);break;
    case 12: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=13;break;
    case 13: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=14;break;
    case 14: func_021DD0F4(p,*(char **)(p+0xd0));func_021FD744((int *)a);break;
    }
}










/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * diagnostic: ov186 0x021FF648 +013C resolved through a sibling's new shard in the TU; only ARM9 remains. TU --suggest-split leaves caller out.
 * blocker-C: prior verified Thumb EXACT from ov183_func_021DF838.c header, blocker-r2.log, dsi/1.1p1 -O4,p; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 func_0200B98C_Table[];
 * u64 func_0200B98C(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==func_0200B98C_Table[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 * abi: B938 retains caller-loaded r3; DD0AC/DD0F4 retain caller-loaded r1; 35C60 return is consumed.
 */
void func_021DC228(int *a,int *state,char *p)
{
    u64 t;
    int message;
    int index;
    char *source;
    u32 x,y;
    int args[2];
    switch(*state) {
    case 0: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=1;break;
    case 1: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=2;break;
    case 2:
        if(*(int *)(p+0xb0)) func_021DCE28(p,*(char **)(p+0xd0));
        else func_021DCE48(p,*(char **)(p+0xd0));
        func_021DD054(p,*(char **)(p+0xd0));
        func_021DD0AC(p,*(char **)(p+0xd0));
        func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x14b);
        *state=3;break;
    case 3: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,0);*state=4;break;
    case 4: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=5;break;
    case 5:
        func_02082BCC(&t,0,8);
        t=func_0200B98C(*(void **)(p+0xc4),4,0);
        func_021FF54C(*(void **)(*(char **)(p+0xd0)+0x24),3,(const int *)(&t));
        *(int *)(p+0xbc)=0;*state=6;break;
    case 6:
        ++*(int *)(p+0xbc);
        if(func_021FF648(*(void **)(*(char **)(p+0xd0)+0x24)) && *(u32 *)(p+0xbc)>96) {
            func_021FD860((void *)(*(int *)(p+12)), 0, (const void *)0);*state=7;
        }
        break;
    case 7:
        if(!func_021FF72C(*(void **)(*(char **)(p+0xd0)+0x24),&message)) {
            if(func_021FF698(*(char **)(*(char **)(p+0xd0)+0x24),(int)&source,&index)) {
                func_0200B938(source,source+0x80,source+0xc4,(unsigned int)func_02012EBC(*(void **)(*(char **)(p+0xd0)+0x28)));
                **(long long **)(*(char **)(p+0xd0)+0x2c)=index;
                **(int **)(p+0xd0)=1;
                func_021F9C50((S_021DB2E0 *)(*(S_021DBFB0 **)(*(char **)(p+0xd0)+0x14)));*state=8;
            } else {
                func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x114);*state=11;
            }
        } else {
            func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)message);*state=11;
        }
        break;
    case 11:
        if(func_02035C60()) {
            func_02035D20(&x,&y);args[0]=x;args[1]=y;
            func_021FD860((void *)(*(int *)(p+0x10)), 1, (const void *)args);func_020061E4(0x703);*state=12;
        }
        break;
    case 8: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=9;break;
    case 9: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=10;break;
    case 10:
        if(!func_02006254(0x701)) {func_021DD0F4(p,*(char **)(p+0xd0));func_021FD744((int *)(*(int *)(p+8)));}
        break;
    case 12: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=13;break;
    case 13: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=14;break;
    case 14: func_021DD0F4(p,*(char **)(p+0xd0));func_021FD73C(a,(int)func_021DBC68);break;
    }
}










/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * blocker-C: prior verified Thumb EXACT from ov183_func_021DF838.c header, blocker-r2.log, dsi/1.1p1 -O4,p; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 func_0200B98C_Table[];
 * u64 func_0200B98C(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==func_0200B98C_Table[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 * abi: DD0AC/DD0F4 keep the visibly loaded second descriptor argument despite body using only the first.
 */
void func_021DC4FC(int *a,int *state,char *p)
{
    switch(*state) {
    case 0:
        func_021DD0AC(p,*(char **)(p+0xd0));
        func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x152);
        func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,0);
        *state=1;break;
    case 1: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=2;break;
    case 2: *state=3;break;
    case 3: *(u16 *)(p+0xb6)=0;*(u16 *)(p+0xb8)=0;*state=4;break;
    case 4:
        if(*(int *)(*(char **)(p+0xd0)+8)>3) func_02034714(d_021E3960,0,d_021E3960);
        if(func_021D7630((void *)(*(int *)(*(char **)(p+0xd0)+0x28)),*(int *)(*(char **)(p+0xd0)+8),(u16 *)(p+0xb6),(u16 *)(p+0xb8),*(u16 *)(p+0xb4))==2) {
            func_0200B490();
            *(int *)(p+0xc8)=(int)func_0200B98C(*(void **)(p+0xc4),5,0);
            *state=5;
        }
        break;
    case 5: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=6;break;
    case 6: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=7;break;
    case 7: func_021DD0F4(p,*(char **)(p+0xd0));func_021FD73C(a,(int)func_021DBC68);break;
    }
}









/*
 * abi: DD0AC/DD0F4 retain caller-loaded r1.
 */
void func_021DC638(int *a,int *state,char *p)
{
    u32 x,y;
    switch(*state) {
    case 0: func_021FE784((int)(*(int * *)&((struct Obj24555 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC),2,3,1);*state=1;break;
    case 1: if(func_021FE7B0(*(int * *)&((struct Obj24556 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC)) *state=2;break;
    case 2:
        if(((struct Obj00050 *)p)->fB0) func_021DCE28(p,*(char * *)&((struct Obj00050 *)p)->fD0);
        else func_021DCE48(p,*(char * *)&((struct Obj00050 *)p)->fD0);
        func_021DD054(p,*(char * *)&((struct Obj00050 *)p)->fD0);func_021DD128(p,*(char * *)&((struct Obj00050 *)p)->fD0);*state=3;break;
    case 3: func_021FE784((int)(*(int * *)&((struct Obj24557 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC),2,3,0);++*state;break;
    case 4: if(func_021FE7B0(*(int * *)&((struct Obj24558 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC)) ++*state;break;
    case 5: ++*state;break;
    case 6:
        if(func_02035D20(&x,&y)) {
            if(func_021DD2FC(p,x,y)) *state=7;
            else if(func_021DD33C(p,x,y)) *state=10;
        }
        break;
    case 7: func_021FE784((int)(*(int * *)&((struct Obj24559 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC),2,3,1);++*state;break;
    case 8: if(func_021FE7B0(*(int * *)&((struct Obj24560 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC)) ++*state;break;
    case 9: func_021DD1D4(p,*(char * *)&((struct Obj00050 *)p)->fD0);*state=13;break;
    case 10: func_021FE784((int)(*(int * *)&((struct Obj24561 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC),2,3,1);++*state;break;
    case 11: if(func_021FE7B0(*(int * *)&((struct Obj24562 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC)) ++*state;break;
    case 12: func_021DD1D4(p,*(char * *)&((struct Obj00050 *)p)->fD0);func_021FD73C(a,(int)func_021DBC68);break;
    case 13: func_021DD0AC(p,*(char * *)&((struct Obj00050 *)p)->fD0);*state=14;break;
    case 14:
        func_021FD170(((struct Obj00050 *)p)->f18,(char *)(((struct Obj24563 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f10),(void *)0x152);
        func_021FE784((int)(*(int * *)&((struct Obj24564 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC),2,3,0);*state=15;break;
    case 15: if(func_021FE7B0(*(int * *)&((struct Obj24565 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC)) *state=16;break;
    case 16: *state=17;break;
    case 17: func_02012DAC(((struct Obj24566 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f28);*state=18;break;
    case 18:
        if(func_02012DD0(*(u8 * *)&((struct Obj24567 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f28)==2) {func_021FD860((void *)(*(int *)&((struct Obj00050 *)p)->fC), 0, (const void *)0);*state=19;}
        break;
    case 19: func_021FE784((int)(*(int * *)&((struct Obj24568 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC),2,3,1);*state=20;break;
    case 20: if(func_021FE7B0(*(int * *)&((struct Obj24569 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC)) *state=21;break;
    case 21:
        if(!func_02006254(0x701)) {
            func_021DD0F4(p,*(char * *)&((struct Obj00050 *)p)->fD0);
            **(int * *)&((struct Obj00050 *)p)->fD0=1;
            func_021F9C50((S_021DB2E0 *)(*(S * *)&((struct Obj24571 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f14));
            func_021FD744((int *)a);
        }
        break;
    }
}









/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * blocker-C: prior verified Thumb EXACT from ov183_func_021DF838.c header, blocker-r2.log, dsi/1.1p1 -O4,p; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 func_0200B98C_Table[];
 * u64 func_0200B98C(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==func_0200B98C_Table[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 * lever: counter declared before context locals restores stack homes; named selector fixes call-result addition operand order (existing idioms).
 * abi: EE0C retains caller's sixth outgoing word (2), beyond callee's five used arguments.
 */
void func_021DC8EC(char *p,char *q)
{
    u16 record[4];
    int i;
    void *font;
    MsgBank *bank;
    WordSet *words;
    int ready;
    const Descriptor *d;
    char *slot;
    U16Vec *text;
    if(!*(int *)(p+0xd4)) {
        *(int *)(p+0xd4)=1;
        if(func_021DD228(*(void **)(p+0xc4))) func_021FB964((void *)(*(int *)(q+0x10)),7,*(u16 *)(p+0xb4));
        else func_021FB964((void *)(*(int *)(q+0x10)),6,*(u16 *)(p+0xb4));
        font=(void *)func_021FC20C(*(char **)(q+0x10));
        bank=(MsgBank *)func_021FC214(*(char **)(q+0x10));
        words=(WordSet *)func_021FC21C(*(char **)(q+0x10));
        for(i=0;i<5;i++) {
            d=&d_021E32C8[i];
            slot=p+i*4;
            *(void **)(slot+0x30)=func_021FC6A4(1,d->x,d->y,d->w,d->h,14,*(void **)(p+4),*(u16 *)(p+0xb4));
            switch(i) {
            case 0:
                {
                void *name;
                void *message;
                text=func_020457B0(128,*(u16 *)(p+0xb4));
                name=func_0200D6D0(*(void **)(p+0xc0),*(u16 *)(p+0xb4));
                message=func_02045EC0(bank,d->message);
                func_0201EE0C(words,0,name,func_0200D6EC(*(RecGet **)(p+0xc0)),1,2);
                func_0201F250(words,text,message);
                func_02045808((U16Vec *)name);func_02045808((U16Vec *)message);
                func_021FC868(*(void **)(slot+0x30),0,1,0);
                ready=1;break;
                }
            case 1:
                {
                u32 selector;
                selector=func_0200B98C(*(void **)(p+0xc4),3,0);
                text=func_02045EC0(bank,selector+d->message);
                func_021FC868(*(void **)(slot+0x30),0,1,0);ready=1;break;
                }
            case 2:
                {
                u64 value;
                u64 quotient;
                u32 low,middle,high;
                void *message;
                void *temporary;
                value=func_0200B98C(*(void **)(p+0xc4),4,0);
                low=value%100000ULL;
                quotient=value/100000ULL;
                middle=quotient%100000ULL;
                high=quotient/100000ULL;
                temporary=func_0200D774(*(GdsProfile **)(p+0xc0),(GdsRecord *)record,*(u16 *)(p+0xb4));
                if(temporary) {
                    message=func_02045EC0(bank,13);func_02045808((U16Vec *)temporary);
                } else message=func_02045EC0(bank,d->message);
                text=func_020457B0(128,*(u16 *)(p+0xb4));
                func_0201EFA4(words,2,low,5,2,1);func_0201EFA4(words,1,middle,5,2,1);func_0201EFA4(words,0,high,2,2,1);
                func_0201F250(words,text,message);
                func_021FC868(*(void **)(slot+0x30),0,1,0);func_02045808((U16Vec *)message);
                ready=1;break;
                }
            case 3:
                if(func_021DD25C(*(void **)(p+0xc4))) {
                    u32 count;
                    void *message;
                    count=func_0200B98C(*(void **)(p+0xc4),2,0);
                    text=func_020457B0(128,*(u16 *)(p+0xb4));
                    message=func_02045EC0(bank,d->message);
                    func_0201EFA4(words,0,count,4,0,1);func_0201F250(words,text,message);func_02045808((U16Vec *)message);
                    func_021FC868(*(void **)(slot+0x30),0,1,1);ready=1;
                } else ready=0;
                break;
            case 4:
                if(func_021DD25C(*(void **)(p+0xc4))) {
                    text=func_02045EC0(bank,d->message);
                    func_021FC868(*(void **)(slot+0x30),0,1,1);ready=1;
                } else ready=0;
                break;
            }
            if(ready) {
                func_021FC7C4(*(char **)(slot+0x30),text,font,0x3da0);func_02045808(text);
            }
        }
        func_021DCBD8(p,*(void **)(q+0x18),*(void **)(p+0xc4),*(u16 *)(p+0xb4));
    }
}









/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * blocker-symbols: func_0200B98C_Table 0x0209DDCC data a4
 *   typedef unsigned char u8;
 *   typedef unsigned short u16;
 *   typedef unsigned long long u64;
 *   extern const u16 func_0200B98C_Table[];
 *   u64 func_0200B98C(char *p, int selector, int index)
 *   {
 *       int i;
 *       u16 v;
 *       switch (selector) {
 *       case 0:
 *           v = ((u16 *)p)[index];
 *           if (v > 0x289) return 0;
 *           return v;
 *       case 1:
 *           return *(u8 *)(p + index + 0x18) & 0x7F;
 *       case 2:
 *           v = *(u16 *)(p + 0x24);
 *           if (v > 0x270F) return 0x270F;
 *           return v;
 *       case 3:
 *           for (i = 0; i < 0x29; i++) {
 *               if (*(u16 *)(p + 0x26) == func_0200B98C_Table[i]) return i;
 *           }
 *           return 0;
 *       case 4:
 *           return *(u64 *)(p + 0x38);
 *       case 5:
 *           return *(u8 *)(p + 0x2A);
 *       case 6:
 *           return (*(u8 *)(p + index + 0x18) & 0x80) >> 7;
 *       case 7:
 *           return *(u8 *)(p + 0x2B);
 *       default:
 *           return 0;
 *       }
 *   }
 * lever: swapped start/end declaration homes, then zeroed phase-two j before coords assignment; DIFF16 to4 to MATCH.
 * checks: 1 own ARM9 and matched caller arities re-derived; B98C original shown, 3 args/u64, DD228 shown 1 arg; 2 F838 and F620/DE084 twins reread; 3 codegen became MATCH in3 runs, further type probes unnecessary; 4 counter-before-base/declared-struct idioms read; 5 fresh directory/neighbors reread before handoff; prior permuter300 not repeated.
 * TU: cbd8-tu.log terminal exit0, MATCH, three B98C wildcards at +009A/+00A6/+00B2, no viable split.
 */
void func_021DCBD8(char *p,void *manager,void *party,u16 heap)
{
    u32 species[12],forms[12],half[12];
    Position_021DB2E0 pos;
    u32 v,f,h;
    int count=0;
    int mode;
    void *archive;
    int step;
    int i;
    int start;
    int n;
    int end;
    const Pair_021DB2E0 *coords;
    char *slot;
    int mapping;
    archive=func_020490F4(7,(u16)((heap&0x7fff)|0x8000));
    *(void **)(p+0x48)=(void *)func_0204ACEC(archive,func_0201BC3C(),0,128,heap);
    mapping=func_0201BC40();
    *(void **)(p+0x4c)=(void *)func_0204AF28(archive,mapping,func_0201BCB4(),heap);
    n=0;
    step=6;start=0;end=6;mode=0;
    if(func_021DD228(party)==1) {step=3;end=3;mode=1;}
    do {
        for(i=start;i<end;i++) {
            species[n]=255;
            v=func_0200B98C(party,0,i);
            f=func_0200B98C(party,1,i);
            h=func_0200B98C(party,6,i);
            if(v) {species[n]=v;forms[n]=f;half[n]=h;n++;}
        }
        for(i=n;i<end;i++) {species[n]=0;forms[n]=0;half[n]=0;n++;}
        start+=step;end+=step;
    } while(end<=12);
    {
    int j;
    u32 h2,f2,v2;
    j=0;
    coords=(const Pair_021DB2E0 *)((u32)d_021E32F0+(int)mode*48);
    for(;j<12;j++) {
        slot=p+j*4;
        *(void **)(slot+0x80)=0;
        *(u32 *)(slot+0x50)=-1;
        v2=species[j];
        if(v2) {
            h2=half[j];f2=forms[j];
            *(u32 *)(slot+0x50)=func_0204A6C8(archive,func_0201BABC(v2,f2,h2,0),0,0,heap);
            func_02082BCC(&pos,0,8);
            pos.x=coords[j].x+8;pos.y=coords[j].y-12;pos.z=1;pos.a=12-count;
            *(void **)(p+count*4+0x80)=func_0204B294(manager,(u32)(*(void **)(slot+0x50)),(u32)(*(void **)(p+0x48)),(u32)(*(void **)(p+0x4c)),&pos,0,heap);
            func_0204B688(*(void **)(count*4+p+0x80),1);
            func_0204B6F4(*(void **)(p+count*4+0x80),func_0201BB5C(v2,f2,h2,0),0);
            count++;
        }
    }
    }
    func_02049238(archive);
}









void func_021DCDD8(char *p, char *q)
{
    int flag;
    if(*(int *)(p+0x44)==0 && *(int *)(p+0xdc)==0) {
        *(int *)(p+0xdc)=1;
        flag=1;
        if(*(int *)(*(char **)(p+0xd0)+8)==0) flag=0;
        *(void **)(p+0x44)=func_021FD1C4((void *)(*(int *)(p+0xc0)),(char *)(*(int *)(q+0x10)),(void *)(*(int *)(q+0x18)),(void *)(*(int *)(p+4)),flag,*(unsigned short *)(p+0xb4));
    }
}









void func_021DCE28(char *p,char *unused) { if(((struct Obj00050 *)p)->fDC && *(int * *)&((struct Obj00050 *)p)->f44) { func_021FD640(*(int * *)&((struct Obj00050 *)p)->f44); *(int *)&((struct Obj00050 *)p)->f44=0; ((struct Obj00050 *)p)->fDC=0; } }








void func_021DCE48(char *p,char *q)
{
    int i;
    char *slot;
    if(((struct Obj00050 *)p)->fD4) {
        for(i=0;i<12;i++) {
            slot=p+i*4;
            if(((struct Obj02893 *)slot)->f80) {
                func_0204B3DC(((struct Obj02893 *)slot)->f80,0);
                func_0204B3B4(((struct Obj02893 *)slot)->f80);
                *(int *)&((struct Obj02893 *)slot)->f80=0;
            }
            if(((struct Obj02893 *)slot)->f50!=-1) { func_0204A8D4(((struct Obj02893 *)slot)->f50); ((struct Obj02893 *)slot)->f50=-1; }
        }
        if(((struct Obj00050 *)p)->f48!=-1) { func_0204ADA4(((struct Obj00050 *)p)->f48); ((struct Obj00050 *)p)->f48=-1; }
        if(((struct Obj00050 *)p)->f4C!=-1) { func_0204AFD8(((struct Obj00050 *)p)->f4C); ((struct Obj00050 *)p)->f4C=-1; }
        for(i=0;i<5;i++) {
            slot=p+i*4;
            if(((struct Obj02893 *)slot)->f30) { func_021FC734(((struct Obj02893 *)slot)->f30); *(int *)&((struct Obj02893 *)slot)->f30=0; }
        }
        func_021FBDA4(((struct Obj24572 *)q)->f10,6);
        func_020409B4(1);
        ((struct Obj00050 *)p)->fD4=0;
    }
}








void func_021DCEE4(char *p,char *q)
{
    int a,b;
    if(!((struct Obj00730 *)p)->fD8) {
        ((struct Obj00730 *)p)->fD8=1;
        func_021FB964((void *)(*(int *)&((struct Obj03329 *)q)->f10),5,((struct Obj00730 *)p)->fB4);
        func_021FBE54(*(char * *)&((struct Obj03329 *)q)->f10,6,((struct Obj00730 *)p)->fB4);
        a=func_021FC20C(*(char * *)&((struct Obj03329 *)q)->f10);
        b=func_021FC214(*(char * *)&((struct Obj03329 *)q)->f10);
        if(((struct Obj00730 *)p)->fCC) {
            Desc d;
            Triple t;
            func_02082BCC(&d,0,8);
            d.x=24;d.y=168;d.n=0;d.flag=1;
            func_021FC124(((struct Obj03329 *)q)->f10,6,&t);
            ((struct Obj00730 *)p)->f1C=func_021FB378(&d,4,96,1,((struct Obj03329 *)q)->f18,((struct Obj00730 *)p)->f0,a,b,&t,((struct Obj00730 *)p)->fB4);
            d.x=136;d.n=3;
            ((struct Obj00730 *)p)->f20=func_021FB378(&d,84,96,1,((struct Obj03329 *)q)->f18,((struct Obj00730 *)p)->f0,a,b,&t,((struct Obj00730 *)p)->fB4);
        } else {
            Desc d;
            Triple t;
            func_02082BCC(&d,0,8);
            d.x=80;d.y=168;d.n=0;d.flag=1;
            func_021FC124(((struct Obj03329 *)q)->f10,6,&t);
            ((struct Obj00730 *)p)->f1C=func_021FB378(&d,4,96,1,((struct Obj03329 *)q)->f18,((struct Obj00730 *)p)->f0,a,b,&t,((struct Obj00730 *)p)->fB4);
        }
        ((struct Obj00730 *)p)->f28=func_021FC6A4(4,8,3,16,2,14,((struct Obj00730 *)p)->f4,((struct Obj00730 *)p)->fB4);
        if(((struct Obj00730 *)p)->fB0) func_021FC754(*(char * *)&((struct Obj00730 *)p)->f28,(void *)b,(void *)0x72,(void *)a,0x3da0);
        else func_021FC754(*(char * *)&((struct Obj00730 *)p)->f28,(void *)b,(void *)0x71,(void *)a,0x3da0);
    }
}








void func_021DD054(char *p, char *q)
{
    int i;
    char *slot;
    if(((struct Obj00050 *)p)->fD8) {
        if(((struct Obj00050 *)p)->f28) { func_021FC734(((struct Obj00050 *)p)->f28); *(int *)&((struct Obj00050 *)p)->f28=0; }
        for(i=0;i<2;i++) {
            slot=p+i*4;
            if(((struct Obj10730 *)slot)->f1C) { func_021FB494(((struct Obj10730 *)slot)->f1C); *(int *)&((struct Obj10730 *)slot)->f1C=0; }
        }
        func_020409B4(4);
        func_021FC0C8((char *)(((struct Obj06598 *)q)->f10),6);
        func_021FBDA4(((struct Obj06598 *)q)->f10,5);
        ((struct Obj00050 *)p)->fD8=0;
    }
}






void func_021DD0AC(char *p)
{
    if (!((struct Obj00050 *)p)->fE0) {
        int args[2];
        ((struct Obj00050 *)p)->fE0 = 1;
        if (!((struct Obj00050 *)p)->f18)
            ((struct Obj00050 *)p)->f18 = func_021FD12C(((struct Obj24573 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f10, (void *)(*(int *)&((struct Obj00050 *)p)->f4), ((struct Obj00050 *)p)->fB4);
        args[0] = 0x80;
        args[1] = 0x60;
        func_021FD860((void *)(*(int *)&((struct Obj00050 *)p)->fC), 4, (const void *)args);
    }
}






void func_021DD0F4(char *p, char *a1) { if(((struct Obj00050 *)p)->fE0) { func_021FD860(*(char * *)&((struct Obj00050 *)p)->fC,0,0); if(((struct Obj00050 *)p)->f18) { func_021FD15C(((struct Obj00050 *)p)->f18,((struct Obj24574 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f10); *(int *)&((struct Obj00050 *)p)->f18=0; } ((struct Obj00050 *)p)->fE0=0; } }






void func_021DD128(char *p, char *q)
{
    if (!((struct Obj00050 *)p)->fE4) {
        int first, second, i;
        const struct Record_021DB2E0 *rec;
        char *slot;
        ((struct Obj00050 *)p)->fE4 = 1;
        if (!((struct Obj00050 *)p)->f18)
            ((struct Obj00050 *)p)->f18 = func_021FD12C(*(int *)&((struct Obj06599 *)q)->f10, (void *)(*(int *)&((struct Obj00050 *)p)->f4), ((struct Obj00050 *)p)->fB4);
        func_021FD170(((struct Obj00050 *)p)->f18, (char *)(*(int *)&((struct Obj06599 *)q)->f10), (void *)0x14f);
        func_021FB964((void *)(*(int *)&((struct Obj06599 *)q)->f10), 30, ((struct Obj00050 *)p)->fB4);
        first = func_021FC20C(*(char * *)&((struct Obj06599 *)q)->f10);
        second = func_021FC214(*(char * *)&((struct Obj06599 *)q)->f10);
        for (i = 0; i < 2; i++) {
            rec = &d_021E32A8[i];
            slot = p + i * 4;
            ((struct Obj14423 *)slot)->f28 = func_021FC6A4(4, rec->a, rec->b, rec->c, rec->d, 14, (void *)(*(int *)&((struct Obj00050 *)p)->f4), ((struct Obj00050 *)p)->fB4);
            func_021FC754(((struct Obj14423 *)slot)->f28, (void *)second, (void *)rec->value, (void *)first, 0x3da0);
        }
    }
}











/*
 * trailing: 2 zero alignment bytes at 0x021DD226
 */
void func_021DD1D4(char *p, char *q)
{
    int i;
    char *slot;
    if (((struct Obj00050 *)p)->fE4) {
        for (i = 0; i < 2; i++) {
            slot = p + i * 4;
            if (((struct Obj10731 *)slot)->f28) {
                func_021FC734(((struct Obj10731 *)slot)->f28);
                *(int *)&((struct Obj10731 *)slot)->f28 = 0;
            }
        }
        func_020409B4(4);
        func_021FBDA4(((struct Obj06598 *)q)->f10, 30);
        if (((struct Obj00050 *)p)->f18) {
            func_021FD15C(((struct Obj00050 *)p)->f18, ((struct Obj06598 *)q)->f10);
            *(int *)&((struct Obj00050 *)p)->f18 = 0;
        }
        ((struct Obj00050 *)p)->fE4 = 0;
    }
}











/*
 * 2026-10-05 (D8 lane19): re-verified, status unchanged; sole blocker is arm9 callee 0x0200B98C (no witness outside the caller). Needs a label seed. Source is byte-correct; no C change possible.
 * blocker-symbols: func_0200B98C_Table 0x0209DDCC data a4
 *   typedef unsigned char u8;
 *   typedef unsigned short u16;
 *   typedef unsigned long long u64;
 *   extern const u16 func_0200B98C_Table[];
 *   u64 func_0200B98C(char *p, int selector, int index)
 *   {
 *       int i;
 *       u16 v;
 *       switch (selector) {
 *       case 0:
 *           v = ((u16 *)p)[index];
 *           if (v > 0x289) return 0;
 *           return v;
 *       case 1: return *(u8 *)(p + index + 0x18) & 0x7F;
 *       case 2:
 *           v = *(u16 *)(p + 0x24);
 *           if (v > 0x270F) return 0x270F;
 *           return v;
 *       case 3:
 *           for (i = 0; i < 0x29; i++) {
 *               if (*(u16 *)(p + 0x26) == func_0200B98C_Table[i]) return i;
 *           }
 *           return 0;
 *       case 4: return *(u64 *)(p + 0x38);
 *       case 5: return *(u8 *)(p + 0x2A);
 *       case 6: return (*(u8 *)(p + index + 0x18) & 0x80) >> 7;
 *       case 7: return *(u8 *)(p + 0x2B);
 *       default: return 0;
 *       }
 *   }
 */
int func_021DD228(void *p) { switch((int)func_0200B98C(p,3,0)) { case 16: case 17: case 18: case 19: case 22: return 1; case 20: case 21: default: return 0; } }











int func_021DD25C(void *p) { int result; int v; result=0; v=(int)func_0200B98C(p,3,0); if(v==20) goto yes; if(v==21) goto yes; if(v!=22) goto no; yes: return 1; no: return result; }











int func_021DD27C(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x40) <= 0x88) &
             ((unsigned int)(b - 0x10) <= 0x20);
    if (ok) {
        int args[2];
        args[0] = a;
        args[1] = b;
        func_021FD860((void *)(((struct Obj24575 *)p)->f10), 1, (const void *)args);
        func_020061E4(0x703);
    }
    return ok;
}











int func_021DD2BC(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x50) <= 0x60) &
             ((unsigned int)(b - 0x38) <= 0x40);
    if (ok) {
        int args[2];
        args[0] = a;
        args[1] = b;
        func_021FD860((void *)(((struct Obj24576 *)p)->f10), 1, (const void *)args);
        func_020061E4(0x703);
    }
    return ok;
}











int func_021DD2FC(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x20) <= 0x48) &
             ((unsigned int)(b - 0x30) <= 0x10);
    if (ok) {
        int args[2];
        args[0] = a;
        args[1] = b;
        func_021FD860((void *)(((struct Obj24577 *)p)->f10), 1, (const void *)args);
        func_020061E4(0x703);
    }
    return ok;
}











int func_021DD33C(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x90) <= 0x48) &
             ((unsigned int)(b - 0x30) <= 0x10);
    if (ok) {
        int args[2];
        args[0] = a;
        args[1] = b;
        func_021FD860((void *)(((struct Obj24578 *)p)->f10), 1, (const void *)args);
        func_020061E4(0x703);
    }
    return ok;
}











/*
 * trailing: 2 zero alignment bytes at 0x021DD3F6
 */
int func_021DD37C(void *a, int unused, char *q)
{
    char *p = func_0203159C(a, 0x80, func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct Obj00632 *)q)->fC)));
    func_02082BCC(p, 0, 0x80);
    ((struct Obj00631 *)p)->f7C = func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct Obj00632 *)q)->fC));
    ((struct Obj00631 *)p)->f0 = func_02025538(((struct Obj00631 *)p)->f7C, ((struct Obj00632 *)q)->f4);
    ((struct Obj00631 *)p)->f4 = (void *)func_0201C440((void *)(((struct Obj00631 *)p)->f7C));
    ((struct Obj00631 *)p)->f74 = func_021FD760((unsigned int)(((struct Obj00632 *)q)->f4), (char *)(*(int *)&((struct Obj00632 *)q)->f8), 1, ((struct Obj00631 *)p)->f7C);
    func_021FBE54(*(char * *)&((struct Obj00632 *)q)->f8, 13, ((struct Obj00631 *)p)->f7C);
    func_021DDE2C(p, q);
    func_021DD5C8(p, q);
    return 1;
}










int func_021DD3F8(struct S020315D4 *a, int unused, char *q, char *p)
{
    func_021DDF5C(p, q);
    func_021DDDE8(p, q);
    func_020409B4(4);
    func_020409B4(1);
    func_021FC0C8((char *)(((struct Obj06603 *)q)->f8), 13);
    func_021FD820(*(char * *)&((struct Obj10732 *)p)->f74);
    func_0201C4C0(((struct Obj10732 *)p)->f4);
    func_02025588(((struct Obj10732 *)p)->f0);
    func_020315D4(a);
    return 1;
}










/*
 * tail: 021DD5C6..021DD5C8 is two zero alignment bytes.
 */
int func_021DD440(void *unused,u32 *state,char *q,char *p)
{
 int x,y,i;
 struct Pair pair;
 switch(*state){
 case 0:func_021FE784(*(int *)&((struct Obj00363 *)q)->f0,2,3,0);*state=1;break;
 case 1:if(func_021FE7B0(*(int * *)&((struct Obj00363 *)q)->f0)) *state=2;break;
 case 2:
  if(func_02035D20((u32 *)(&x),(u32 *)(&y))){
   ((struct Obj00731 *)p)->f78=func_021DDFA0(p,x,y);
   if(((struct Obj00731 *)p)->f78) *state=3;
   if(func_021FB4B4((unsigned int *)(((struct Obj00731 *)p)->f20),x,y)){
    pair.x=x;pair.y=y;
    func_021FD860((void *)(*(int *)&((struct Obj00731 *)p)->f74), 1, (const void *)((int *)&pair));
    *state=7;
   }
  }break;
 case 3:func_021FE784(*(int *)&((struct Obj00363 *)q)->f0,2,1,1);++*state;break;
 case 4:if(func_021FE7B0(*(int * *)&((struct Obj00363 *)q)->f0)) ++*state;break;
 case 5:
  func_021DDDE8(p,q);
  switch(*(u32 *)&((struct Obj00731 *)p)->f78){
  case 1:func_021DD684(p,q);break;
  case 2:func_021DD858(p,q);break;
  case 3:func_021DDA2C(p,q);break;
  case 4:func_021DDCCC(p,q);break;
  }
  func_021FE784(*(int *)&((struct Obj00363 *)q)->f0,2,1,0);++*state;break;
 case 6:if(func_021FE7B0(*(int * *)&((struct Obj00363 *)q)->f0)) *state=2;break;
 case 7:func_021FE784(*(int *)&((struct Obj00363 *)q)->f0,2,3,1);*state=8;break;
 case 8:if(func_021FE7B0(*(int * *)&((struct Obj00363 *)q)->f0)) *state=9;break;
 case 9:func_021F9BA0(((struct Obj00363 *)q)->fC);return 1;
 }
 for(i=0;i<4;i++) if(*(void **)(p+i*4+0x24)) func_021FC830(*(void **)(p+i*4+0x24));
 for(i=0;i<16;i++) if(*(void **)(p+i*4+0x34)) func_021FC830(*(void **)(p+i*4+0x34));
 func_0201C4E4(((struct Obj00731 *)p)->f4);
 if(((struct Obj00731 *)p)->f1C)func_021FD1BC(((struct Obj00731 *)p)->f1C);
 func_021FD854(((struct Obj00731 *)p)->f74);
 return 0;
}










/*
 * lever: const record array at the table address restores early argument loads;
 *        a scalar record and const pointer local remained 22 bytes DIFF.
 */
void func_021DD5C8(char *p, char *q)
{
    int first, second, v;
    Triple triple;
    const struct Record_021DD1D4 *rec;
    u8 a, b, c, d;
    first = func_021FC20C(*(char * *)&((struct Obj00632 *)q)->f8);
    second = func_021FC214(*(char * *)&((struct Obj00632 *)q)->f8);
    func_021FB964((void *)(*(int *)&((struct Obj00632 *)q)->f8), 14, ((struct Obj00631 *)p)->f7C);
    rec = &d_021E3350[0];
    d = rec->d;
    a = rec->a;
    b = rec->b;
    c = rec->c;
    ((struct Obj00631 *)p)->f34 = func_021FC6A4(1, a, b, c, d, 14, ((struct Obj00631 *)p)->f4, ((struct Obj00631 *)p)->f7C);
    func_021FC868(((struct Obj00631 *)p)->f34, 0, 1, 0);
    func_021FC754(((struct Obj00631 *)p)->f34, (void *)second, (void *)rec->value, (void *)first, 0x3da0);
    ((struct Obj00631 *)p)->f1C = func_021FD12C(*(int *)&((struct Obj00632 *)q)->f8, (void *)(*(int *)&((struct Obj00631 *)p)->f4), ((struct Obj00631 *)p)->f7C);
    func_021FD170(((struct Obj00631 *)p)->f1C, (char *)(*(int *)&((struct Obj00632 *)q)->f8), (void *)0x86);
    v = func_0200DABC((struct Blk1AC *)(((struct Obj00632 *)q)->f10));
    func_021FC124((void *)(*(int *)&((struct Obj00632 *)q)->f8), 13, (Triple *)((Triple *)&triple));
    func_021DE084((void *)(p + 8), (void *)(*(int *)&((struct Obj00632 *)q)->f4), (const char *)(&triple), v, 0x68, 0x58, ((struct Obj00631 *)p)->f7C);
}









void func_021DD684(char *p,char *q)
{
 int first,second,third,index,v;
 const struct Record_021DD684 *rec;
 char *slot;
 unsigned select;
 int number1,number2;
 void *obj;
 Triple triple;
 first=func_021FC20C(*(char **)(q+8));
 second=func_021FC214(*(char **)(q+8));
 third=func_021FC21C(*(char **)(q+8));
 func_021FB964((void *)(*(int *)(q+8)),10,*(u16 *)(p+0x7c));
 select=func_021DE000((void *)(*(int *)(q+0x10)),(char *)(*(int *)(q+0x14)))?5:0;
 for(index=0;index<8;index++){
  rec=&d_021E33C0[index];slot=p+index*4;
  *(void **)(slot+0x34)=func_021FC6A4(1,rec->a,rec->b,rec->c,rec->d,14,*(void **)(p+4),*(u16 *)(p+0x7c));
  func_021FC868(*(void **)(slot+0x34),0,1,0);
  switch(index){
   case 1:
    obj=func_02045EC0((struct MsgBank *)second,func_021DE000((void *)(*(int *)(q+0x10)),(char *)(*(int *)(q+0x14)))?0x83:0x7e);break;
   case 2:
    obj=func_02045EC0((struct MsgBank *)second,func_0200DB44(*(void **)(q+0x10),select)?0x91:0x87);break;
   case 3:{
    void *base;
    number1=func_0200DAC4(*(void **)(q+0x10),select);
    number1=(number1>9999)?9999:number1;
    base=func_02045EC0((struct MsgBank *)second,rec->value);
    obj=func_020457B0(0x80,*(u16 *)(p+0x7c));
    func_0201EFA4((void *)third,0,number1,4,1,1);
    func_0201F250((void *)third,obj,base);
    func_02045808(base);break;
   }
   case 6:{
    void *base;
    number2=func_0200DAD8(*(void **)(q+0x10),select);
    number2=(number2>9999)?9999:number2;
    base=func_02045EC0((struct MsgBank *)second,rec->value);
    obj=func_020457B0(0x80,*(u16 *)(p+0x7c));
    func_0201EFA4((void *)third,0,number2,4,1,1);
    func_0201F250((void *)third,obj,base);
    func_02045808(base);break;
   }
   default:obj=func_02045EC0((struct MsgBank *)second,rec->value);break;
  }
  func_021FC7C4(*(char **)(slot+0x34),obj,(void *)first,0x3da0);
  func_02045808(obj);
 }
 v=func_0200DABC(*(void **)(q+0x10));
 func_021FC124((void *)(*(int *)(q+8)), 13, (Triple *)((Triple *)&triple));
 func_021DE084(p+8,*(void **)(q+4),(const char *)&triple,v,0xa0,0x20,*(u16 *)(p+0x7c));
}









/*
 * note: 2026-10-05 wave P10 lane Y1. Twin of func_021DD684 (same body: other table d_021E3400, getter func_021DE02C, selector 6/1, argument 11, strings 0x84/0x7f). 468 B; the 1140 B listing extent also holds func_021DDA2C, filed separately. The clamps are n = (n > 9999) ? 9999 : n; as in the twin.
 */
void func_021DD858(char *p,char *q)
{
 int first,second,third,index,v;
 const struct Record_021DD684 *rec;
 char *slot;
 unsigned select;
 int number1,number2;
 void *obj;
 Triple triple;
 first=func_021FC20C(*(char **)(q+8));
 second=func_021FC214(*(char **)(q+8));
 third=func_021FC21C(*(char **)(q+8));
 func_021FB964((void *)(*(int *)(q+8)),11,*(u16 *)(p+0x7c));
 select=func_021DE02C((void *)(*(int *)(q+0x10)),(void *)(*(int *)(q+0x14)))?6:1;
 for(index=0;index<8;index++){
  rec=&d_021E3400[index];slot=p+index*4;
  *(void **)(slot+0x34)=func_021FC6A4(1,rec->a,rec->b,rec->c,rec->d,14,*(void **)(p+4),*(u16 *)(p+0x7c));
  func_021FC868(*(void **)(slot+0x34),0,1,0);
  switch(index){
   case 1:
    obj=func_02045EC0((struct MsgBank *)second,func_021DE02C((void *)(*(int *)(q+0x10)),(void *)(*(int *)(q+0x14)))?0x84:0x7f);break;
   case 2:
    obj=func_02045EC0((struct MsgBank *)second,func_0200DB44(*(void **)(q+0x10),select)?0x91:0x87);break;
   case 3:{
    void *base;
    number1=func_0200DAC4(*(void **)(q+0x10),select);
    number1=(number1>9999)?9999:number1;
    base=func_02045EC0((struct MsgBank *)second,rec->value);
    obj=func_020457B0(0x80,*(u16 *)(p+0x7c));
    func_0201EFA4((void *)third,0,number1,4,1,1);
    func_0201F250((void *)third,obj,base);
    func_02045808(base);break;
   }
   case 6:{
    void *base;
    number2=func_0200DAD8(*(void **)(q+0x10),select);
    number2=(number2>9999)?9999:number2;
    base=func_02045EC0((struct MsgBank *)second,rec->value);
    obj=func_020457B0(0x80,*(u16 *)(p+0x7c));
    func_0201EFA4((void *)third,0,number2,4,1,1);
    func_0201F250((void *)third,obj,base);
    func_02045808(base);break;
   }
   default:obj=func_02045EC0((struct MsgBank *)second,rec->value);break;
  }
  func_021FC7C4(*(char **)(slot+0x34),obj,(void *)first,0x3da0);
  func_02045808(obj);
 }
 v=func_0200DABC(*(void **)(q+0x10));
 func_021FC124((void *)(*(int *)(q+8)), 13, (Triple *)((Triple *)&triple));
 func_021DE084(p+8,*(void **)(q+4),(const char *)&triple,v,0xa0,0x20,*(u16 *)(p+0x7c));
}







/*
 * lever: bounded permuter rec/index declaration order, selector use and
 *        field-base expansion restore the three selector/index spill homes.
 */
void func_021DDA2C(char *p, char *q)
{
  int first;
  int second;
  int third;
  const struct Record_021DD1D4 *rec;
  int v;
  unsigned select;
  unsigned select2;
  int index;
  char *slot;
  int number1;
  int number2;
  int number3;
  int number4;
  void *obj;
  Triple triple;
  char **tmp1;
  u16 tmp;
  first = func_021FC20C(*((char **) (q + 8)));
  second = func_021FC214(*((char **) (q + 8)));
  third = func_021FC21C(*((char **) (q + 8)));
  tmp = *((u16 *) (p + 0x7c));
  func_021FB964((void *)(*((int *) (q + 8))), 12, tmp);
  if (func_021DE058((void *)(*((int *) (q + 0x10))), (void *)(*((int *) (q + 0x14)))))
  {
    select = 7;
    select2 = 8;
  }
  else
  {
    select = 2;
    select2 = 3;
  }
  ;
  for (index = 0; index < 16; index++)
  {
    rec = &d_021E3490[index];
    slot = p + (index * 4);
    *((void **) (slot + 0x34)) = func_021FC6A4(1, (&d_021E3490[index])->a, (&d_021E3490[index])->b, (&d_021E3490[index])->c, (&d_021E3490[index])->d, 14, *((void **) (p + 4)), *((u16 *) (p + 0x7c)));
    func_021FC868(*((void **) (slot + 0x34)), 0, 1, 0);
    switch (index)
    {
      if (select2)
      {
      }
      case 1:
        obj = func_02045EC0((struct MsgBank *)second, (func_021DE058((void *)(*((int *) (q + 0x10))), (void *)(*((int *) (q + 0x14))))) ? (0x85) : (0x80));
        break;

      case 3:
        obj = func_02045EC0((struct MsgBank *)second, (func_0200DB44(*((void **) (q + 0x10)), select)) ? (0x91) : (0x87));
        break;

      case 4:
      {
        void *base;
        number1 = func_0200DAC4(*((void **) (q + 0x10)), select);
        if (number1 > 9999)
          number1 = 9999;
        base = func_02045EC0((struct MsgBank *)second, rec->value);
        obj = func_020457B0(0x80, *((u16 *) (p + 0x7c)));
        func_0201EFA4((void *) third, 0, number1, 4, 1, 1);
        func_0201F250((void *) third, obj, base);
        func_02045808(base);
        break;
      }

      case 7:
      {
        void *base;
        number2 = func_0200DAD8(*((void **) (q + 0x10)), select);
        if (number2 > 9999)
          number2 = 9999;
        base = func_02045EC0((struct MsgBank *)second, rec->value);
        obj = func_020457B0(0x80, *((u16 *) (p + 0x7c)));
        func_0201EFA4((void *) third, 0, number2, 4, 1, 1);
        func_0201F250((void *) third, obj, base);
        func_02045808(base);
        break;
      }

      case 10:
        obj = func_02045EC0((struct MsgBank *)second, (func_0200DB44(*((void **) (q + 0x10)), select2)) ? (0x91) : (0x87));
        break;

      case 11:
      {
        void *base;
        number3 = func_0200DAC4(*((void **) (q + 0x10)), select2);
        if (number3 > 9999)
          number3 = 9999;
        base = func_02045EC0((struct MsgBank *)second, rec->value);
        obj = func_020457B0(0x80, *((u16 *) (p + 0x7c)));
        func_0201EFA4((void *) third, 0, number3, 4, 1, 1);
        func_0201F250((void *) third, obj, base);
        func_02045808(base);
        break;
      }

      case 14:
      {
        void *base;
        number4 = func_0200DAD8(*((void **) (q + 0x10)), select2);
        if (number4 > 9999)
          number4 = 9999;
        base = func_02045EC0((struct MsgBank *)second, rec->value);
        obj = func_020457B0(0x80, *((u16 *) (p + 0x7c)));
        func_0201EFA4((void *) third, 0, number4, 4, 1, 1);
        func_0201F250((void *) third, obj, base);
        func_02045808(base);
        break;
      }

      default:
        obj = func_02045EC0((struct MsgBank *)second, rec->value);
        break;

    }

    tmp1 = (char **) (slot + 0x34);
    func_021FC7C4(*tmp1, obj, (void *) first, 0x3da0);
    func_02045808(obj);
  }

  v = func_0200DABC((struct Blk1AC *)(*((int *) (q + 0x10))));
  func_021FC124((void *)(*((int *) (q + 8))), 13, (Triple *)((Triple *)&triple));
  func_021DE084(p + 8, *((void **) (q + 4)), (const char *) (&triple), v, 0xa0, 0x20, *((u16 *) (p + 0x7c)));
}







/*
 * lever: declaring the text object before the loop index fixes r4/r5.
 */
void func_021DDCCC(char *p,char *q)
{
 int first,second,third,v,text;
 void *obj;
 int i;
 char *slot;
 const struct Record_021DDCCC *rec;
 Triple triple;
 first=func_021FC20C(*(char * *)&((struct Obj00363 *)q)->f8);
 second=func_021FC214(*(char * *)&((struct Obj00363 *)q)->f8);
 third=func_021FC21C(*(char * *)&((struct Obj00363 *)q)->f8);
 func_021FB964((void *)(*(int *)&((struct Obj00363 *)q)->f8),13,((struct Obj00731 *)p)->f7C);
 for(i=0;i<5;i++){
  rec=&d_021E338C[i]; slot=p+i*4;
  ((struct Obj14425 *)slot)->f34=func_021FC6A4(1,rec->a,rec->b,rec->c,rec->d,14,((struct Obj00731 *)p)->f4,((struct Obj00731 *)p)->f7C);
  if(i==4){
   v=func_0200DC08((struct Blk1AC *)(*(int *)&((struct Obj00363 *)q)->f10));
   text=(int)func_02045EC0((struct MsgBank *)second,rec->value);
   obj=func_020457B0(0x80,((struct Obj00731 *)p)->f7C);
   func_0201EFA4((void *)third,0,v,2,1,1);
   func_0201F250((void *)third,obj,(void *)text);
   func_02045808((struct U16Vec *)text);
  }else obj=(void *)func_02045EC0((struct MsgBank *)second,rec->value);
  func_021FC7C4(*(char * *)&((struct Obj14425 *)slot)->f34,obj,(void *)first,0x3da0);
  func_02045808((struct U16Vec *)((int)obj));
 }
 v=func_0200DABC((struct Blk1AC *)(*(int *)&((struct Obj00363 *)q)->f10));
 func_021FC124((void *)(*(int *)&((struct Obj00363 *)q)->f8), 13, (Triple *)((Triple *)&triple));
 func_021DE084(p+8,((struct Obj00363 *)q)->f4,(const char *)&triple,v,0xa0,0x20,((struct Obj00731 *)p)->f7C);
}







void func_021DDDE8(char *p, char *q)
{
    int i;
    char *slot;
    func_021DE12C(p + 8);
    for (i = 0; i < 16; i++) {
        slot = p + i * 4;
        if (((struct Obj10734 *)slot)->f34) {
            func_021FC734(((struct Obj10734 *)slot)->f34);
            *(int *)&((struct Obj10734 *)slot)->f34 = 0;
        }
    }
    func_021FBDA4(((struct Obj06603 *)q)->f8, 10);
    if (((struct Obj10733 *)p)->f1C) {
        func_021FD15C(((struct Obj10733 *)p)->f1C, ((struct Obj06603 *)q)->f8);
        *(int *)&((struct Obj10733 *)p)->f1C = 0;
    }
}






void func_021DDE2C(char *p,char *q)
{
 int first,second,i,id;
 Triple triple;
 struct Position_021DB2E0 pos;
 const struct Record_021DD1D4 *rec;
 char *slot;
 func_021FBE54(*(char * *)&((struct Obj00632 *)q)->f8,6,((struct Obj00631 *)p)->f7C);
 func_021FB964((void *)(*(int *)&((struct Obj00632 *)q)->f8),9,((struct Obj00631 *)p)->f7C);
 first=func_021FC20C(*(char * *)&((struct Obj00632 *)q)->f8);
 second=func_021FC214(*(char * *)&((struct Obj00632 *)q)->f8);
 func_02082BCC(&pos,0,8);
 pos.x=0x50;pos.y=0xa8;pos.z=0;pos.a=1;
 func_021FC124((void *)(*(int *)&((struct Obj00632 *)q)->f8), 6, (Triple *)((Triple *)&triple));
 ((struct Obj00631 *)p)->f20=func_021FB378(&pos,4,0x60,1,*(int *)&((struct Obj00632 *)q)->f4,*(int *)&((struct Obj00631 *)p)->f0,first,second,&triple,((struct Obj00631 *)p)->f7C);
 for(i=0;i<4;i++){
  rec=&d_021E336C[i];slot=p+i*4;
  ((struct Obj14426 *)slot)->f24=func_021FC6A4(4,rec->a,rec->b,rec->c,rec->d,14,((struct Obj00631 *)p)->f4,((struct Obj00631 *)p)->f7C);
  switch(i){
   case 0: if(func_021DE000((void *)(((struct Obj00632 *)q)->f10),(char *)(((struct Obj00632 *)q)->f14))) id=0x83;else id=0x7e;break;
   case 1: if(func_021DE02C((void *)(((struct Obj00632 *)q)->f10),(void *)(((struct Obj00632 *)q)->f14))) id=0x84;else id=0x7f;break;
   case 2: if(func_021DE058((void *)(((struct Obj00632 *)q)->f10),(void *)(((struct Obj00632 *)q)->f14))) id=0x85;else id=0x80;break;
   case 3: id=0x81;break;
  }
  func_021FC754(((struct Obj14426 *)slot)->f24,(void *)second,(void *)id,(void *)first,0x3da0);
 }
}






void func_021DDF5C(char *p, char *q)
{
    int i;
    char *slot;
    for (i = 0; i < 4; i++) {
        slot = p + i * 4;
        if (((struct Obj10736 *)slot)->f24) {
            func_021FC734(((struct Obj10736 *)slot)->f24);
            *(int *)&((struct Obj10736 *)slot)->f24 = 0;
        }
    }
    if (((struct Obj10735 *)p)->f20) {
        func_021FB494(((struct Obj10735 *)p)->f20);
        *(int *)&((struct Obj10735 *)p)->f20 = 0;
    }
    func_021FC0C8((char *)(((struct Obj06603 *)q)->f8), 6);
    func_021FBDA4(((struct Obj06603 *)q)->f8, 9);
}






int func_021DDFA0(char *p, int x, int y)
{
    int skip = ((struct Obj00731 *)p)->f78;
    int i;
    for (i = 0; i < 5; i++) {
        if (i != skip && (u32)(x - d_021E3440[i].x0) <= d_021E3440[i].x1 - d_021E3440[i].x0 &&
            (u32)(y - d_021E3440[i].y0) <= d_021E3440[i].y1 - d_021E3440[i].y0) {
            int args[2];
            args[0] = x;
            args[1] = y;
            func_021FD860((void *)(*(int *)&((struct Obj00731 *)p)->f74), 1, (const void *)args);
            func_020061E4(0x703);
            return i;
        }
    }
    return 0;
}






int func_021DE000(void *p,char *q) { u32 a,b; a=func_0200DBA0(p,4,0); b=func_020142E8((void *)func_0201296C((const struct BigObj *)q),0x960); if(a && b) return 1; return 0; }






int func_021DE02C(void *p, void *q)
{
    int a = func_0200DBA0(p, 5, 0);
    unsigned b = func_020142E8((void *)func_0201296C(q), 0x960);
    if (a && b) return 1;
    return 0;
}






int func_021DE058(void *p, void *q)
{
    int a = func_0200DBA0(p, 6, 0);
    unsigned b = func_020142E8((void *)func_0201296C(q), 0x960);
    if (a && b) return 1;
    return 0;
}








/*
 * extent: two trailing zero bytes are alignment padding before the next labelled function.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`base = x;` before `base = x + 20;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT* in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
void func_021DE084(char *p, void *manager, const char *q, unsigned int value, s16_021DB2E0 x, s16_021DB2E0 y, u16 heap)
{
    Position_021DE084 pos;
    int base;
    int i;
    func_02082BCC(p, 0, 0x14);
    func_02082BCC(&pos, 0, 8);
    pos.x = x;
    pos.y = y;
    pos.z = 10;
    ((struct Obj14427 *)p)->f0 = func_0204B294(manager, (unsigned int)((struct Obj05472 *)q)->f4, (unsigned int)((struct Obj05472 *)q)->f8, (unsigned int)((struct Obj05472 *)q)->f0, &pos, 0, heap);
    func_0204B688(((struct Obj14427 *)p)->f0, 1);
    pos.z = 0;
    base = x + 20;
    for (i = 0; i < 4; i++) {
        char *slot;
        pos.x = base + i * 16;
        pos.y = y;
        slot = p + i * 4;
        ((struct Obj14428 *)slot)->f4 = func_0204B294(manager, (unsigned int)((struct Obj05472 *)q)->f4, (unsigned int)((struct Obj05472 *)q)->f8, (unsigned int)((struct Obj05472 *)q)->f0, &pos, 0, heap);
        func_0204B688(((struct Obj14428 *)slot)->f4, 1);
    }
    func_021DE15C(p, value);
}








void func_021DE12C(char *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        char *slot = p + i * 4;
        if (((struct Obj10737 *)slot)->f4) {
            func_0204B3B4(((struct Obj10737 *)slot)->f4);
            ((struct Obj10737 *)slot)->f4 = 0;
        }
    }
    func_0204B3B4(((struct Obj24580 *)p)->f0);
    func_02082BCC(p, 0, 20);
}








void func_021DE15C(char *p, u32 value)
{
    u8 temp = value;
    int i;
    int j;
    if (temp != 0) {
        for (;;) {
            if (temp == 0) break;
            temp /= 10;
        }
    }
    for (i = 0; i < 4; i++) func_0204B878(*(void **)(p + i * 4 + 4), 0);
    for (j = 0; j < 4; j++)
        func_0204B878(*(void **)(p + (3 - j) * 4 + 4), value % d_021E3358[j + 1] / d_021E3358[j]);
}








int func_021DE1C8(void *a, int b, char *q)
{
    char *p = func_0203159C(a, 0x70, func_021F9B9C(((struct Obj06604 *)q)->fC));
    func_02082BCC(p, 0, 0x70);
    ((struct Obj02519 *)p)->f6C = func_021F9B9C(((struct Obj06604 *)q)->fC);
    ((struct Obj02519 *)p)->f0 = func_02025538(((struct Obj02519 *)p)->f6C, ((struct Obj06604 *)q)->f0);
    ((struct Obj02519 *)p)->f4 = (void *)func_0201C440((void *)(((struct Obj02519 *)p)->f6C));
    ((struct Obj02519 *)p)->f64 = func_021FD760((unsigned int)(((struct Obj06604 *)q)->f0), (char *)(((struct Obj06604 *)q)->f8), 1, ((struct Obj02519 *)p)->f6C);
    func_021DE3E4(p, q);
    func_021DE7C0(p, q);
    return 1;
}








int func_021DE234(void *a, int b, char *q, char *p)
{
    func_021DE780(p, q);
    func_021DE8FC(p, q);
    func_020409B4(4);
    func_020409B4(1);
    func_021FD820(((struct Obj10738 *)p)->f64);
    func_0201C4C0(((struct Obj10738 *)p)->f4);
    func_02025588(((struct Obj10738 *)p)->f0);
    func_020315D4(a);
    return 1;
}








int func_021DE274(void *unused,u32 *state,char *q,char *p)
{
 int x,y,i;
 struct Pair_021DE084 pair;
 switch(*state){
 case 0:func_021FE784(*(int *)&((struct Obj00440 *)q)->f4,2,3,0);*state=1;break;
 case 1:if(func_021FE7B0(*(int * *)&((struct Obj00440 *)q)->f4)) *state=2;break;
 case 2:
  if(func_02035D20((u32 *)(&x),(u32 *)(&y))){
   ((struct Obj00785 *)p)->f68=func_021DE940(p,x,y);
   if(((struct Obj00785 *)p)->f68) *state=3;
   if(func_021FB4B4((unsigned int *)(((struct Obj00785 *)p)->fC),x,y)){
    pair.x=x;pair.y=y;
    func_021FD860((void *)(*(int *)&((struct Obj00785 *)p)->f64), 1, (const void *)((struct Pair_021DE084 *)&pair));
    *state=7;
   }
  }break;
 case 3:func_021FE784(*(int *)&((struct Obj00440 *)q)->f4,2,1,1);++*state;break;
 case 4:if(func_021FE7B0(*(int * *)&((struct Obj00440 *)q)->f4)) ++*state;break;
 case 5:
  func_021DE780(p,q);
  switch(*(u32 *)&((struct Obj00785 *)p)->f68){
  case 1:func_021DE404(p,q);break;
  case 2:func_021DE55C(p,q);break;
  case 3:func_021DE66C(p,q);break;
  }
  func_021FE784(*(int *)&((struct Obj00440 *)q)->f4,2,1,0);++*state;break;
 case 6:if(func_021FE7B0(*(int * *)&((struct Obj00440 *)q)->f4)) *state=2;break;
 case 7:func_021FE784(*(int *)&((struct Obj00440 *)q)->f4,2,3,1);*state=8;break;
 case 8:if(func_021FE7B0(*(int * *)&((struct Obj00440 *)q)->f4)) *state=9;break;
 case 9:func_021F9BA0(((struct Obj00440 *)q)->fC);return 1;
 }
 for(i=0;i<3;i++) if(*(void **)(p+i*4+0x10)) func_021FC830(*(void **)(p+i*4+0x10));
 for(i=0;i<18;i++) if(*(void **)(p+i*4+0x1c)) func_021FC830(*(void **)(p+i*4+0x1c));
 func_0201C4E4(((struct Obj00785 *)p)->f4);
 func_021FD854(((struct Obj00785 *)p)->f64);
 if(((struct Obj00785 *)p)->f8)func_021FD1BC(((struct Obj00785 *)p)->f8);
 return 0;
}








void func_021DE3E4(char *p, char *q)
{
    ((struct Obj02519 *)p)->f8 = func_021FD12C(((struct Obj14429 *)q)->f8, (void *)(*(int *)&((struct Obj02519 *)p)->f4), ((struct Obj02519 *)p)->f6C);
    func_021FD170(((struct Obj02519 *)p)->f8, (char *)(((struct Obj14429 *)q)->f8), (void *)0x86);
}








/*
 * lever: declaring text before i/flag restores the original stack slots.
 */
void func_021DE404(char *p,char *q)
{
    int font, bank, words;
    struct U16Vec *text;
    int i, flag;
    const Record *rec;
    char *slot;
    void *base;
    font=func_021FC20C(*(char * *)&((struct Obj00440 *)q)->f8);
    bank=func_021FC214(*(char * *)&((struct Obj00440 *)q)->f8);
    words=func_021FC21C(*(char * *)&((struct Obj00440 *)q)->f8);
    func_021FB964((void *)(*(int *)&((struct Obj00440 *)q)->f8),16,((struct Obj00785 *)p)->f6C);
    for(i=0;i<12;i++) {
        flag=1;
        rec=&d_021E3574[i];
        slot=p+i*4;
        ((struct Obj10739 *)slot)->f1C=func_021FC6A4(1,rec->a,rec->b,rec->c,rec->d,14,((struct Obj00785 *)p)->f4,((struct Obj00785 *)p)->f6C);
        func_021FC868(((struct Obj10739 *)slot)->f1C,0,1,0);
        switch(i) {
        case 0: func_0201F02C((struct WordSet *)words,0,func_02012944(((struct Obj00440 *)q)->f10)); break;
        case 7: func_0201EFA4((struct WordSet *)words,0,func_0200DFD8(*(Row * *)&((struct Obj00440 *)q)->f14,5,0),4,1,1); break;
        case 8: func_0201EFA4((struct WordSet *)words,0,func_0200DFD8(*(Row * *)&((struct Obj00440 *)q)->f14,6,0),4,1,1); break;
        case 9: func_0201EFA4((struct WordSet *)words,0,func_0200DFD8(*(Row * *)&((struct Obj00440 *)q)->f14,7,0),4,1,1); break;
        case 10: func_0201EFA4((struct WordSet *)words,0,func_0200DFD8(*(Row * *)&((struct Obj00440 *)q)->f14,8,0),4,1,1); break;
        case 11: func_0201EFA4((struct WordSet *)words,0,func_0200DFD8(*(Row * *)&((struct Obj00440 *)q)->f14,9,0),4,1,1); break;
        default: text=func_02045EC0((struct MsgBank *)bank,rec->value); flag=0; break;
        }
        if(flag) {
            base=func_02045EC0((struct MsgBank *)bank,rec->value);
            text=func_020457B0(128,((struct Obj00785 *)p)->f6C);
            func_0201F250((struct WordSet *)words,text,base);
            func_02045808(base);
        }
        func_021FC7C4(*(char * *)&((struct Obj10739 *)slot)->f1C,text,(void *)font,0x3da0);
        func_02045808(text);
    }
}








void func_021DE55C(char *p,char *q)
{
    int font, bank, words, i, flag, value;
    const Record *rec;
    char *slot;
    struct U16Vec *text;
    void *base;
    font=func_021FC20C(*(char * *)&((struct Obj00440 *)q)->f8);
    bank=func_021FC214(*(char * *)&((struct Obj00440 *)q)->f8);
    words=func_021FC21C(*(char * *)&((struct Obj00440 *)q)->f8);
    func_021FB964((void *)(*(int *)&((struct Obj00440 *)q)->f8),17,((struct Obj00785 *)p)->f6C);
    for(i=0;i<18;i++) {
        rec=&d_021E3664[i];
        slot=p+i*4;
        ((struct Obj10740 *)slot)->f1C=func_021FC6A4(1,rec->a,rec->b,rec->c,rec->d,14,((struct Obj00785 *)p)->f4,((struct Obj00785 *)p)->f6C);
        func_021FC868(((struct Obj10740 *)slot)->f1C,0,1,0);
        if(i>=8 && i<=12) {value=func_0200DFD8(*(Row * *)&((struct Obj00440 *)q)->f14,i-3,1);flag=1;}
        else if(i>=13 && i<=17) {value=func_0200DFD8(*(Row * *)&((struct Obj00440 *)q)->f14,i-8,2);flag=1;}
        else {text=func_02045EC0((struct MsgBank *)bank,rec->value);flag=0;}
        if(flag) {
            base=func_02045EC0((struct MsgBank *)bank,rec->value);
            text=func_020457B0(128,((struct Obj00785 *)p)->f6C);
            func_0201EFA4((struct WordSet *)words,0,value,5,1,1);
            func_0201F250((struct WordSet *)words,text,base);
            func_02045808(base);
        }
        func_021FC7C4(*(char * *)&((struct Obj10740 *)slot)->f1C,text,(void *)font,0x3da0);
        func_02045808(text);
    }
}








void func_021DE66C(char *p,char *q)
{
    int font, bank, words, i, flag, value;
    const Record *rec;
    char *slot;
    struct U16Vec *text;
    void *base;
    font=func_021FC20C(*(char * *)&((struct Obj00440 *)q)->f8);
    bank=func_021FC214(*(char * *)&((struct Obj00440 *)q)->f8);
    words=func_021FC21C(*(char * *)&((struct Obj00440 *)q)->f8);
    func_021FB964((void *)(*(int *)&((struct Obj00440 *)q)->f8),17,((struct Obj00785 *)p)->f6C);
    for(i=0;i<18;i++) {
        rec=&d_021E35D4[i];
        slot=p+i*4;
        ((struct Obj10741 *)slot)->f1C=func_021FC6A4(1,rec->a,rec->b,rec->c,rec->d,14,((struct Obj00785 *)p)->f4,((struct Obj00785 *)p)->f6C);
        func_021FC868(((struct Obj10741 *)slot)->f1C,0,1,0);
        if(i>=8 && i<=12) {value=func_0200DFD8(*(Row * *)&((struct Obj00440 *)q)->f14,i-8,1);flag=1;}
        else if(i>=13 && i<=17) {value=func_0200DFD8(*(Row * *)&((struct Obj00440 *)q)->f14,i-13,2);flag=1;}
        else {text=func_02045EC0((struct MsgBank *)bank,rec->value);flag=0;}
        if(flag) {
            base=func_02045EC0((struct MsgBank *)bank,rec->value);
            text=func_020457B0(128,((struct Obj00785 *)p)->f6C);
            func_0201EFA4((struct WordSet *)words,0,value,5,1,1);
            func_0201F250((struct WordSet *)words,text,base);
            func_02045808(base);
        }
        func_021FC7C4(*(char * *)&((struct Obj10741 *)slot)->f1C,text,(void *)font,0x3da0);
        func_02045808(text);
    }
}








/*
 * extent: two trailing zero bytes are alignment padding before the next labelled function.
 */
void func_021DE780(char *p, char *q)
{
    int i;
    for (i = 0; i < 18; i++) {
        char *slot = p + i * 4;
        if (((struct Obj10743 *)slot)->f1C != 0) {
            func_021FC734(((struct Obj10743 *)slot)->f1C);
            ((struct Obj10743 *)slot)->f1C = 0;
        }
    }
    func_021FBDA4(((struct Obj08312 *)q)->f8, 17);
    if (((struct Obj10742 *)p)->f8 != 0) {
        func_021FD15C(((struct Obj10742 *)p)->f8, ((struct Obj08312 *)q)->f8);
        ((struct Obj10742 *)p)->f8 = 0;
    }
}








/*
 * lever: bank/words declaration order selects their original stack slots.
 * omits func_02045CAC from its function header. Existing C verified EXACT
 * (344 bytes, 12/12 relocations; ARM9-45CAC-one.log, terminal exit 0).
 * typedef unsigned char  u8;
 * typedef unsigned short u16;
 * typedef unsigned int   u32;
 *
 * struct MsgEntry {
 *     u32 off;
 *     u16 len;
 *     u16 pad_06;
 * };
 *
 * struct MsgFile {
 *     u16 langCount;
 *     u16 count;
 *     u32 unk_04;
 *     u32 unk_08;
 *     u32 langOff[1];
 * };
 *
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void                 *base;
 *     struct MsgEntry       cache;
 *     u32                   origin;
 *     void                 *stream;
 *     u16                   heapId;
 *     u8                    langIndex;
 *     u8                    resident;
 * };
 *
 * extern char g_020A7E8C[];
 * extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
 *                           u16 tag);
 * extern void func_020307B0(void *p);
 * extern void func_020495F4(void *stream, u32 size, void *dest);
 * extern void func_0204960C(void *stream, u32 pos);
 * extern void func_0204581C(void *dest);
 * extern void func_02045A00(void *dest, const void *src, u16 len);
 * extern void func_02045E04(void *dest, u32 index);
 * extern u8 func_020461B8(const void *file);
 * extern void func_02046110(struct MsgBank *bank);
 * extern void func_02046180(struct MsgBank *bank);
 *
 * void func_02045CAC(struct MsgBank *bank, u32 index, void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *
 *     if (index >= bank->file->count) {
 *         func_0204581C(dest);
 *         return;
 *     }
 *
 *     func_02046180(bank);
 *
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *
 *         func_0204960C(bank->stream, pos + (index * 8 + 4));
 *         func_020495F4(bank->stream, 8, &bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *
 *     if (bank->resident == 0) {
 *         void *buf;
 *
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000), size,
 *                            0, g_020A7E8C, 0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             func_020495F4(bank->stream, size, buf);
 *             func_02045A00(dest, buf, e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         func_02045A00(dest, (u8 *)bank->base + e->off, e->len);
 *     }
 *
 *     func_02045E04(dest, index);
 * }
 */
void func_021DE7C0(char *p,char *q)
{
    int font,words,bank,i;
    Config_021DE084 config;
    Triple_021DE084 triple;
    struct U16Vec *base,*text;
    void *value;
    const Record *rec;
    char *slot;
    func_021FBE54(*(char **)(q+8),6,*(u16 *)(p+0x6c));
    func_021FB964((void *)(*(int *)(q+8)),15,*(u16 *)(p+0x6c));
    font=func_021FC20C(*(char **)(q+8));
    bank=func_021FC214(*(char **)(q+8));
    words=func_021FC21C(*(char **)(q+8));
    func_02082BCC(&config,0,8);
    config.left=80; config.right=168; config.top=0; config.flag=1;
    func_021FC124((void *)(*(void **)(q+8)), 6, (Triple *)&triple);
    *(void **)(p+0xc)=func_021FB378(&config,4,96,1,*(int *)q,*(int *)p,font,bank,&triple,*(u16 *)(p+0x6c));
    base=func_020457B0(128,*(u16 *)(p+0x6c));
    text=func_020457B0(128,*(u16 *)(p+0x6c));
    value=func_02012944(*(void **)(q+0x10));
    for(i=0;i<3;i++) {
        rec=&d_021E351C[i];
        slot=p+i*4;
        *(void **)(slot+0x10)=func_021FC6A4(4,rec->a,rec->b,rec->c,rec->d,14,*(void **)(p+4),*(u16 *)(p+0x6c));
        if(i==0) {
            func_02045CAC((struct MsgBank *)bank,rec->value,base);
            func_0201F02C((struct WordSet *)words,0,value);
            func_0201F250((struct WordSet *)words,text,base);
        } else func_02045CAC((struct MsgBank *)bank,rec->value,text);
        func_021FC7C4(*(char **)(slot+0x10),text,(void *)font,0x3da0);
    }
    func_02045808(base);
    func_02045808(text);
}








void func_021DE8FC(char *p, char *q)
{
    int i;
    for (i = 0; i < 3; i++) {
        char *slot = p + i * 4;
        if (((struct Obj10745 *)slot)->f10) {
            func_021FC734(((struct Obj10745 *)slot)->f10);
            ((struct Obj10745 *)slot)->f10 = 0;
        }
    }
    if (((struct Obj10744 *)p)->fC) {
        func_021FB494(((struct Obj10744 *)p)->fC);
        ((struct Obj10744 *)p)->fC = 0;
    }
    func_021FC0C8((char *)(((struct Obj08312 *)q)->f8), 6);
    func_021FBDA4(((struct Obj08312 *)q)->f8, 15);
}








int func_021DE940(char *p, int x, int y)
{
    int skip = ((struct Obj00785 *)p)->f68;
    int i;
    for (i = 0; i < 4; i++) {
        if (i != skip && (u32)(x - d_021E3534[i].x0) <= d_021E3534[i].x1 - d_021E3534[i].x0 &&
            (u32)(y - d_021E3534[i].y0) <= d_021E3534[i].y1 - d_021E3534[i].y0) {
            int args[2];
            args[0] = x;
            args[1] = y;
            func_021FD860((void *)(*(int *)&((struct Obj00785 *)p)->f64), 1, (const void *)((struct Pair_021DE084 *)args));
            func_020061E4(0x703);
            return i;
        }
    }
    return 0;
}








int func_021DE9A0(void *a, int b, char *q)
{
    char *p = func_0203159C(a, 0x10C, func_021F9B9C(((struct Obj06605 *)q)->f14));
    int i;
    func_02082BCC(p, 0, 0x10C);
    *(char * *)&((struct Obj02229 *)p)->f108 = q;
    ((struct Obj02229 *)p)->f18 = func_021F9B9C(((struct Obj06605 *)q)->f14);
    ((struct Obj02229 *)p)->f0 = func_02025538(((struct Obj02229 *)p)->f18, ((struct Obj06605 *)q)->fC);
    ((struct Obj02229 *)p)->f14 = (void *)func_0201C440((void *)(((struct Obj02229 *)p)->f18));
    for (i = 0; i < 2; i++)
        *(void **)(p + i * 4 + 0x1C) = func_021FD760((unsigned int)(((struct Obj06605 *)q)->fC), (char *)(((struct Obj06605 *)q)->f10), i, ((struct Obj02229 *)p)->f18);
    ((struct Obj02229 *)p)->f10 = func_021FD6D8((int)p, (int)func_021DF0DC, ((struct Obj02229 *)p)->f18);
    if (((struct Obj24581 *)(*(char * *)&((struct Obj02229 *)p)->f108))->f4 != 0)
        func_021FD73C(((struct Obj02229 *)p)->f10, (int)func_021DEB4C);
    else
        func_021FD73C(((struct Obj02229 *)p)->f10, (int)func_021DF0DC);
    return 1;
}








int func_021DEA30(void *a, int b, char *q, char *p)
{
    int i;
    if (((struct Obj00923 *)p)->f100 != 0) {
        func_021DF388(p + 0x28);
        ((struct Obj00923 *)p)->f100 = 0;
    }
    if (((struct Obj00923 *)p)->fC != 0) {
        func_021FC734(((struct Obj00923 *)p)->fC);
        ((struct Obj00923 *)p)->fC = 0;
    }
    if (((struct Obj00923 *)p)->f8 != 0) {
        func_021FC734(((struct Obj00923 *)p)->f8);
        ((struct Obj00923 *)p)->f8 = 0;
    }
    if (((struct Obj00923 *)p)->f4 != 0) {
        func_021FB494(((struct Obj00923 *)p)->f4);
        ((struct Obj00923 *)p)->f4 = 0;
    }
    if (((struct Obj00923 *)p)->f104 != 0) {
        func_021FC0C8(((struct Obj24583 *)(*(char * *)&((struct Obj00923 *)p)->f108))->f10, 6);
        func_021FBDA4((int)(((struct Obj24584 *)(*(char * *)&((struct Obj00923 *)p)->f108))->f10), 24);
        ((struct Obj00923 *)p)->f104 = 0;
    }
    func_021FD714(((struct Obj00923 *)p)->f10);
    if (((struct Obj00923 *)p)->f24 != 0) {
        func_021FD15C(((struct Obj00923 *)p)->f24, ((struct Obj24582 *)q)->f10);
        ((struct Obj00923 *)p)->f24 = 0;
    }
    for (i = 0; i < 2; i++) func_021FD820(*(void **)(p + 0x1C + i * 4));
    func_02025588(((struct Obj00923 *)p)->f0);
    func_0201C4C0(((struct Obj00923 *)p)->f14);
    func_020315D4(a);
    return 1;
}








int func_021DEADC(int a, int b, int c, char *p)
{
    int i;
    if (func_021FF88C(((struct Obj24585 *)(*(char * *)&((struct Obj02521 *)p)->f108))->f18) == 2) {
        func_021F9C6C(((struct Obj24586 *)(*(char * *)&((struct Obj02521 *)p)->f108))->f14);
        return 1;
    }
    func_021FD71C(((struct Obj02521 *)p)->f10);
    if (func_021FD72C(((struct Obj02521 *)p)->f10) != 0) return 1;
    for (i = 0; i < 2; i++) func_021FD854(*(void **)(p + 0x1C + i * 4));
    func_0201C4E4(((struct Obj02521 *)p)->f14);
    if (((struct Obj02521 *)p)->f8 != 0) func_021FC830(((struct Obj02521 *)p)->f8);
    if (((struct Obj02521 *)p)->fC != 0) func_021FC830(((struct Obj02521 *)p)->fC);
    if (((struct Obj02521 *)p)->f24 != 0) func_021FD1BC(((struct Obj02521 *)p)->f24);
    return 0;
}








void func_021DEB4C(int *task,int *state,char *p)
{
    int font,bank;
    Config_021DE084 config;
    Triple_021DE084 triple;
    font=func_021FC20C(*(char * *)&((struct Obj24587 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10);
    bank=func_021FC214(*(char * *)&((struct Obj24588 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10);
    if(((struct Obj00364 *)p)->f24) {
        func_021FD15C(((struct Obj00364 *)p)->f24,((struct Obj24589 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10);
        ((struct Obj00364 *)p)->f24=0;
    }
    func_021FB964((void *)(((struct Obj24590 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10),24,((struct Obj00364 *)p)->f18);
    func_021FBE54(*(char * *)&((struct Obj24591 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10,6,((struct Obj00364 *)p)->f18);
    ((struct Obj00364 *)p)->f104=1;
    func_02082BCC(&config,0,8);
    config.left=80;config.right=168;config.top=0;config.flag=1;
    if(!func_021FC124((void *)(((struct Obj24592 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10), 6, (Triple *)&triple))
        func_02034714(d_021E3964,0,d_021E3964);
    ((struct Obj00364 *)p)->f4=func_021FB378(&config,4,96,1,((struct Obj24593 *)(*(char * *)&((struct Obj00364 *)p)->f108))->fC,((struct Obj00364 *)p)->f0,font,bank,&triple,((struct Obj00364 *)p)->f18);
    ((struct Obj00364 *)p)->f8=func_021FC6A4(4,11,6,10,4,14,((struct Obj00364 *)p)->f14,((struct Obj00364 *)p)->f18);
    func_021FC754(*(char * *)&((struct Obj00364 *)p)->f8,(void *)bank,(void *)0x55,(void *)font,0x3da0);
    ((struct Obj00364 *)p)->fC=func_021FC6A4(1,3,3,26,4,14,((struct Obj00364 *)p)->f14,((struct Obj00364 *)p)->f18);
    func_021FC868(((struct Obj00364 *)p)->fC,0,1,0);
    func_021FC754(*(char * *)&((struct Obj00364 *)p)->fC,(void *)bank,(void *)(**(int * *)&((struct Obj00364 *)p)->f108+0x57),(void *)font,0x3da0);
    func_021DF1DC((Menu *)(p+0x28), *(char * *)&((struct Obj24595 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f1C, *(char * *)&((struct Obj24596 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10, ((struct Obj24597 *)(*(char * *)&((struct Obj00364 *)p)->f108))->fC, (u32)(((struct Obj00364 *)p)->f1C), (u32)(((struct Obj00364 *)p)->f20), *(u16 * *)&((struct Obj24598 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f28, ((struct Obj00364 *)p)->f18);
    ((struct Obj00364 *)p)->f100=1;
    func_021FD73C(task,(int)func_021DED14);
}








void func_021DECB0(void *a, int b, char *p)
{
    func_021DF388(p + 0x28);
    ((struct Obj02894 *)p)->f100 = 0;
    func_021FC734(((struct Obj02894 *)p)->fC);
    ((struct Obj02894 *)p)->fC = 0;
    func_021FC734(((struct Obj02894 *)p)->f8);
    ((struct Obj02894 *)p)->f8 = 0;
    func_020409B4(4);
    func_020409B4(1);
    func_021FB494(((struct Obj02894 *)p)->f4);
    ((struct Obj02894 *)p)->f4 = 0;
    func_021FC0C8(((struct Obj24599 *)(*(char * *)&((struct Obj02894 *)p)->f108))->f10, 6);
    func_021FBDA4((int)(((struct Obj24600 *)(*(char * *)&((struct Obj02894 *)p)->f108))->f10), 24);
    ((struct Obj02894 *)p)->f104 = 0;
    func_021FD744((int *)a);
}








void func_021DED14(int *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        func_021FE784((int)(((struct Obj24601 *)(*(char * *)&((struct Obj14430 *)p)->f108))->f8), 2, 3, 0);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0(*(int * *)&((struct Obj24602 *)(*(char * *)&((struct Obj14430 *)p)->f108))->f8) != 0) *state = 2;
        break;
    case 2:
        func_021FD73C(a, (int)func_021DEDB4);
        break;
    }
}








void func_021DED64(int *p, int *state, char *q)
{
    switch (*state) {
    case 0:
        func_021FE784((int)(*(int * *)&((struct Obj24603 *)(*(char * *)&((struct Obj14431 *)q)->f108))->f8), 2, 3, 1);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0(*(int * *)&((struct Obj24604 *)(*(char * *)&((struct Obj14431 *)q)->f108))->f8) != 0) *state = 2;
        break;
    case 2:
        func_021FD73C(p, (int)func_021DECB0);
        break;
    }
}








void func_021DEDB4(int *task, int *state, char *p)
{
    u32 x,y;
    func_021DF3DC(p+0x28,((struct Obj03880 *)p)->f18);
    if (func_02035D20(&x,&y)) {
        if (func_021FB4B4((unsigned int *)(((struct Obj03880 *)p)->f4),x,y)) {
            int args[2];
            args[0]=x; args[1]=y;
            func_021FD860((void *)(((struct Obj03880 *)p)->f20), 1, (const void *)((struct Pair_021DE084 *)args));
            func_021F9BA0(((struct Obj24605 *)(*(char * *)&((struct Obj03880 *)p)->f108))->f14);
            func_021FD73C(task,(int)func_021DED64);
        }
        if (func_021DF8F0(x,y)) {
            u32 selection;
            int args[2];
            selection=func_021DF41C(p+0x28);
            if (selection>=((struct Obj24607 *)(*(char * *)&((struct Obj24606 *)(*(char * *)&((struct Obj03880 *)p)->f108))->f1C))->f1718)
                func_02034714(d_021E3964,0,d_021E3964);
            ((struct Obj24609 *)(*(char * *)&((struct Obj24608 *)(*(char * *)&((struct Obj03880 *)p)->f108))->f1C))->f171C=selection;
            func_021F9BF4(*(unsigned * *)&((struct Obj24610 *)(*(char * *)&((struct Obj03880 *)p)->f108))->f14,2);
            func_021FD73C(task,(int)func_021DED64);
            args[0]=x; args[1]=y;
            func_021FD860((void *)(((struct Obj03880 *)p)->f20), 1, (const void *)((struct Pair_021DE084 *)args));
        }
    }
}






void func_021DEE7C(int *task,u32 *state,char *p)
{
    switch(*state) {
    case 0: {
        struct Pair_021DEE7C initial;
        int mode;
        func_02082BCC(&initial,0,8);
        switch(**(u32 **)(p+0x108)) {
        case 0: mode=5; break;
        case 1: mode=6; break;
        case 2: mode=7; break;
        case 3: initial=*(struct Pair_021DEE7C *)(*(char **)(p+0x108)+0x20); mode=4; break;
        default: func_02034714(d_021E3964,0,d_021E3964); break;
        }
        func_02082BCC(*(void **)(*(char **)(p+0x108)+0x1c),0,0x1720);
        *(u32 *)(p+0xfc)=0;
        func_021FF54C(*(void **)(*(char **)(p+0x108)+0x18),mode,(const int *)(&initial));
        *state=1; break;
    }
    case 1:
        ++*(u32 *)(p+0xfc);
        if(func_021FF648(*(char **)(*(char **)(p+0x108)+0x18)) && *(u32 *)(p+0xfc)>96) {
            func_021FD860((void *)(*(int *)(p+0x1c)), 0, (const void *)((struct Pair_021DE084 *)0)); *state=2;
        } break;
    case 2: {
        int message,success,i;
        struct Data_021DB2E0 *data;
        enum { COUNT_OFFSET=0x1718 } offset;
        data=*(struct Data_021DB2E0 **)(*(char **)(p+0x108)+0x1c);
        offset=COUNT_OFFSET;
        if(!func_021FF72C(*(void **)(*(char **)(p+0x108)+0x18),&message)) {
            switch(**(u32 **)(p+0x108)) {
            case 0: success=func_021FF6DC(*(void **)(*(char **)(p+0x108)+0x18),data,30,(void *)((u32)data+offset)); break;
            case 1: success=func_021FF6DC(*(void **)(*(char **)(p+0x108)+0x18),data,30,(void *)((u32)data+offset)); break;
            case 2: success=func_021FF704(*(void **)(*(char **)(p+0x108)+0x18),data,30,(void *)((u32)data+offset)); break;
            case 3: success=func_021FF6B4(*(void **)(*(char **)(p+0x108)+0x18),data,30,(void *)((u32)data+offset)); break;
            default: func_02034714(d_021E3964,0,d_021E3964); break;
            }
            if(success) {
                for(i=0;i<(*(struct Data_021DB2E0 **)(*(char **)(p+0x108)+0x1c))->count;i++) {
                    *(u8 *)(*(char **)(*(char **)(p+0x108)+0x1c)+i+0x16f8)=(u8)func_0200B98C((u8 *)(*(char **)(*(char **)(p+0x108)+0x1c)+i*0xc4+0x80),5,0);
                }
                func_021FD73C(task,(int)func_021DF18C);
            } else {
                if(**(u32 **)(p+0x108)==3) func_021FD170(*(void **)(p+0x24),(char *)(*(int *)(*(char **)(p+0x108)+0x10)),(void *)276);
                else func_021FD170(*(void **)(p+0x24),(char *)(*(int *)(*(char **)(p+0x108)+0x10)),(void *)339);
                *state=3;
            }
        } else {
            func_021FD170(*(void **)(p+0x24),(char *)(*(int *)(*(char **)(p+0x108)+0x10)),(void *)message);
            *state=3;
        } break;
    }
    case 3: {
        u32 x,y;
        struct Pair_021DEE7C clicked;
        if(func_02035C60()) {
            func_02035D20(&x,&y);
            clicked.x=x; clicked.y=y;
            func_021FD860((void *)(*(int *)(p+0x20)), 1, (const void *)((struct Pair_021DE084 *)&clicked));
            func_020061E4(0x703);
            func_021FE784(*(int *)(*(char **)(p+0x108)+8),2,3,1);
            *state=4;
        } break;
    }
    case 4:
        if(func_021FE7B0(*(int **)(*(char **)(p+0x108)+8))) *state=5;
        break;
    case 5:
        func_021F9BA0(*(void **)(*(char **)(p+0x108)+0x14)); func_021FD744((int *)task); break;
    }
}






void func_021DF0DC(int *p, int *state, char *q)
{
    int args[2];
    switch (*state) {
    case 0:
        if (((struct Obj01962 *)q)->f24 == 0) {
            ((struct Obj01962 *)q)->f24 = (int)func_021FD12C(((struct Obj24611 *)(*(char * *)&((struct Obj01962 *)q)->f108))->f10, (void *)(((struct Obj01962 *)q)->f14), ((struct Obj01962 *)q)->f18);
        }
        if (**(int * *)&((struct Obj01962 *)q)->f108 == 3) {
            func_021FD170((char *)(((struct Obj01962 *)q)->f24), (char *)(((struct Obj24613 *)(*(char * *)&((struct Obj01962 *)q)->f108))->f10), (void *)0x14B);
        } else {
            func_021FD170((char *)(((struct Obj01962 *)q)->f24), (char *)(((struct Obj24614 *)(*(char * *)&((struct Obj01962 *)q)->f108))->f10), (void *)0x13E);
        }
        args[0] = 0x80;
        args[1] = 0x60;
        func_021FD860((void *)(((struct Obj01962 *)q)->f1C), 4, (const void *)((struct Pair_021DE084 *)args));
        *state = 1;
        break;
    case 1:
        func_021FE784((int)(*(int * *)&((struct Obj24615 *)(*(char * *)&((struct Obj01962 *)q)->f108))->f8), 2, 3, 0);
        *state = 2;
        break;
    case 2:
        if (func_021FE7B0(*(int * *)&((struct Obj24616 *)(*(char * *)&((struct Obj01962 *)q)->f108))->f8) != 0) *state = 3;
        break;
    case 3:
        func_021FD73C(p, (int)func_021DEE7C);
        break;
    }
}






void func_021DF18C(int *p, int *state, char *q)
{
    switch (*state) {
    case 0:
        func_021FE784((int)(*(int * *)&((struct Obj24617 *)(*(char * *)&((struct Obj14432 *)q)->f108))->f8), 2, 3, 1);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0(*(int * *)&((struct Obj24618 *)(*(char * *)&((struct Obj14432 *)q)->f108))->f8) != 0) *state = 2;
        break;
    case 2:
        func_021FD73C(p, (int)func_021DEB4C);
        break;
    }
}




void func_021DF1DC(Menu *p,char *base,char *res,u32 mgr,u32 a5,u32 a6,u16 *sel,u16 heap)
{
    unsigned first,second;
    int i;
    void *bmp;
    void *buf1,*msg,*buf2;
    Config_021DF1DC cfg;
    first=func_021FC20C(res);
    second=func_021FC214(res);
    func_02082BCC(p,0,0xd4);
    p->base=base;
    p->words=func_0201EC64(heap);
    p->c=a5;
    p->d=a6;
    p->list=func_0201F81C(*(u32 *)(base+0x1718),heap);
    for(i=0;i<*(int *)(base+0x1718);i++)p->list[i].b=i;
    *(CfgTpl *)&cfg=d_021E3700;
    cfg.list=(Item *)p->list;
    cfg.count=*(u32 *)(base+0x1718);
    cfg.resources=res;
    cfg.manager=mgr;
    cfg.cursor=p->c;
    cfg.other=p->d;
    cfg.selection=sel;
    p->view=func_021FC8C8((const Config_021DF1DC *)&cfg, heap);
    buf1=func_020457B0(0xff,heap);
    msg=func_02045EC0((struct MsgBank *)second,0x7a);
    buf2=func_020457B0(0xff,heap);
    for(i=0;i<*(int *)(base+0x1718);i++){
        bmp=func_02043678(cfg.width,cfg.spacing,0x20,heap);
        func_02043B5C(bmp,0);
        func_0201EFA4(p->words,0,i+1,2,0,1);
        func_0201F250(p->words,buf1,msg);
        func_02045924(buf2,(const u16 *)(base+i*0xc4));
        func_0201C7D0(bmp,(short)(16-func_0201D304(buf1,first,0)),4,buf1,(void *)first,0x3DA0);
        func_0201C7D0(bmp,0x14,4,buf2,(void *)first,0x3DA0);
        func_021FCDAC(p->view,(u16)i,(u32)bmp);
    }
    func_02045808(buf2);
    func_02045808(buf1);
    func_02045808(msg);
    func_021FCE50(p->view);
    func_021DF428((struct State_021DF428 *)p,mgr,heap);
    for(i=0;i<*sel;i++)func_021DF620((struct State_021DF428 *)p,i+1,1,heap);
}




/*
 * trailing: two zero alignment bytes at 0x021DF3DA
 */
void func_021DF388(char *p)
{
    unsigned int i;
    func_021DF5B8(p);
    for (i = 0; i < func_021FCE0C(((struct Obj02522 *)p)->f4, 3); i++) {
        func_020437AC((struct Obj020437AC *)func_021FCDE8(((struct Obj02522 *)p)->f4, i));
    }
    func_0201ED04(((struct Obj02522 *)p)->f8);
    func_021FCC80(((struct Obj02522 *)p)->f4);
    func_0201F868(((struct Obj02522 *)p)->f0);
    func_02082BCC(p, 0, 0xD4);
}




/*
 * trailing: two zero alignment bytes at 0x021DF41A
 */
void func_021DF3DC(char *p, u16 a)
{
    unsigned int old, current;
    s8 direction;
    old = func_021FCE0C(((struct Obj00786 *)p)->f4, 1);
    func_021FCD0C(((struct Obj00786 *)p)->f4);
    current = func_021FCE0C(((struct Obj00786 *)p)->f4, 1);
    direction = func_021FCE0C(((struct Obj00786 *)p)->f4, 2);
    if (direction != 0 && old != current) func_021DF620((struct State_021DF428 *)p, current, direction, a);
}







int func_021DF41C(char *p)
{
    return func_021FCDA8(*(char * *)&((struct Obj24619 *)p)->f4);
}







/*
 * 2026-10-05 (wave P6 lane U1b): EXACT. Types from matched ov183 021DF1DC (Menu: base
 * at +0xD0) and 021DF620 (State layout). Two fixes closed the earlier 24 B residue:
 * heap is a u16 parameter (it is only masked and passed to u16-style callees; the
 * narrow type moves its home store before mgr's), and the clamp is a ternary
 * `n = (n >= 5) ? 5 : n;` which gives n the lowest spill slot, under the loop temps.
 * Final call is an if/else with a call in each arm.
 */
void func_021DF428(struct State_021DF428 *p,u32 mgr,u16 heap)
{
    int i,j;
    void *archive;
    u32 mode,species;
    int n;
    struct Entries e;
    struct Pos pos;
    n=*(int *)(p->source+0x1718);
    n=(n>=5)?5:n;
    mode=(heap&0x7fff)|0x8000;
    archive=func_020490F4(7,(u16)mode);
    i=0;
    p->shared0=func_0204ACEC(archive,func_0201BC3C(),0,0x80,heap);
    p->shared1=func_0204AF28(archive,func_0201BC40(),func_0201BCB4(),heap);
    func_02082BCC(&pos,0,8);
    pos.z=1;
    pos.a=i;
    pos.b=i;
    for(i=0;i<n;i++) {
        func_021DF838((int)(p->source+i*0xc4),(char *)(&e));
        for(j=0;j<6;j++) {
            species=e.species[j];
            if(species==0) species=1;
            p->indices[i][j]=func_0204A6C8(archive,func_0201BABC(species,e.form[j],e.gender[j],0),0,0,heap);
            pos.x=j*0x18+0x6e;
            pos.y=i*0x18+0x48;
            pos.a=6-j;
            p->sprites[i][j]=func_0204B294((void *)mgr,p->indices[i][j],p->shared0,p->shared1,&pos,0,heap);
            func_0204B6F4(p->sprites[i][j],func_0201BB5C(species,e.form[j],e.gender[j],0),0);
            func_0204B688(p->sprites[i][j],1);
            if(e.species[j]==0) func_0204B3DC(p->sprites[i][j],0);
            else func_0204B3DC(p->sprites[i][j],1);
        }
    }
    func_02049238(archive);
}







/*
 * trailing: two zero alignment bytes at 0x021DF61E
 * lever: padded struct array members prevent caching the element cursor across calls.
 */
void func_021DF5B8(char *p)
{
    int i, j;
    func_0204AFD8(((struct Obj02522 *)p)->f16);
    func_0204ADA4(((struct Obj02522 *)p)->f14);
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 6; j++) {
            if (((struct W *)p)->objects[i][j] != 0) {
                func_0204A8D4(((struct W *)p)->handles[i][j]);
                func_0204B3B4(((struct W *)p)->objects[i][j]);
                ((struct W *)p)->objects[i][j] = 0;
            }
        }
    }
}







/*
 * Lever: short step spills first; i remains live after the first loop and
 * supplies the second loop's row; forward/back/loaded declaration order
 * gives the three 36-byte buffers at sp+7c, sp+58, sp+34.
 */
void func_021DF620(struct State_021DF428 *p,int first,short step,u16 heap)
{
    int i,j;
    char *src,*dst;
    u32 value;
    void *archive,*handle;
    struct Sub *data;
    struct Rec forward,back,loaded;
    struct Entries entries;
    u32 mode;
    for(i=0;i<5;i++) {
        for(j=0;j<6;j++) {
            if(step==1 && i!=4) {
                src=p->sprites[i+1][j]; dst=p->sprites[i][j];
                if(func_0204B3F4((struct Obj *)src)) {
                    func_0204B7C8(src,(struct Struct36 *)(&forward));
                    value=func_0204B714((struct Obj *)src);
                    func_0204B784(dst,(const struct Struct36 *)(&forward));
                    func_0204B6F4((struct Obj *)dst,value,0);
                    func_0204B3DC((struct Obj *)dst,1);
                } else func_0204B3DC((struct Obj *)dst,0);
            } else if(step==-1 && i!=4) {
                src=p->sprites[3-i][j]; dst=p->sprites[4-i][j];
                if(func_0204B3F4((struct Obj *)src)) {
                    func_0204B7C8(src,(struct Struct36 *)(&back));
                    value=func_0204B714((struct Obj *)src);
                    func_0204B784(dst,(const struct Struct36 *)(&back));
                    func_0204B6F4((struct Obj *)dst,value,0);
                    func_0204B3DC((struct Obj *)dst,1);
                } else func_0204B3DC((struct Obj *)dst,0);
            }
        }
    }
    mode=(heap&0x7fff)|0x8000;
    archive=func_020490F4(7,(u16)mode);
    if(step==-1) { --p->cursor; if(p->cursor<0) p->cursor=4; }
    for(j=0;j<6;j++) {
        if(step==1) i=4; else if(step==-1) i=0;
        func_021DF838((int)((u32)p->source+(i+first)*0xc4),(char *)&entries);
        if(entries.species[j]) {
            handle=func_02049E74(archive,func_0201BABC(entries.species[j],entries.form[j],entries.gender[j],0),0,(u32)&data,mode);
            func_0204A9D0(p->indices[p->cursor][j],(struct Sub0204A9D0 *)data);
            func_0204AB84(p->indices[p->cursor][j],&loaded);
            func_0204B784(p->sprites[i][j],(const struct Struct36 *)(&loaded));
            func_0204B6F4((struct Obj *)p->sprites[i][j],func_0201BB5C(entries.species[j],entries.form[j],entries.gender[j],0),0);
            func_020307B0(handle);
            func_0204B3DC((struct Obj *)p->sprites[i][j],1);
        } else func_0204B3DC((struct Obj *)p->sprites[i][j],0);
    }
    if(step==1) { ++p->cursor; if(p->cursor>4) p->cursor=0; }
    func_02049238(archive);
}







/*
 * 2026-10-05 (D8 lane19): re-verified, status unchanged; sole blocker is arm9 callee 0x0200B98C (no witness outside the caller). Needs a label seed. Source is byte-correct; no C change possible.
 * blocker-symbols: func_0200B98C_Table 0x0209DDCC data a4
 * + *   typedef unsigned char u8;
 *   typedef unsigned short u16;
 *   typedef unsigned long long u64;
 *   extern const u16 func_0200B98C_Table[];
 *   u64 func_0200B98C(char *p, int selector, int index)
 *   {
 *       int i;
 *       u16 v;
 *       switch (selector) {
 *       case 0:
 *           v = ((u16 *)p)[index];
 *           if (v > 0x289) return 0;
 *           return v;
 *       case 1:
 *           return *(u8 *)(p + index + 0x18) & 0x7F;
 *       case 2:
 *           v = *(u16 *)(p + 0x24);
 *           if (v > 0x270F) return 0x270F;
 *           return v;
 *       case 3:
 *           for (i = 0; i < 0x29; i++) {
 *               if (*(u16 *)(p + 0x26) == func_0200B98C_Table[i]) return i;
 *           }
 *           return 0;
 *       case 4:
 *           return *(u64 *)(p + 0x38);
 *       case 5:
 *           return *(u8 *)(p + 0x2A);
 *       case 6:
 *           return (*(u8 *)(p + index + 0x18) & 0x80) >> 7;
 *       case 7:
 *           return *(u8 *)(p + 0x2B);
 *       default:
 *           return 0;
 *       }
 *   }
 * checks: 1 full callee reads 3 args, 64-bit return; 2 no filed twin; 3 int base/long index unchanged (2/2); 4 named base and second declaration order close DIFF (2/2); 5 fresh idiom/neighbour reread, no stack-object residue. Both reorder variants consumed.
 */
void func_021DF838(int p, char *out)
{
    long i;
    int a, b, c;
    void *base;
    int special, n = 0;
    unsigned int count;
    func_02082BCC(out, 0, 0x48);
    base = (void *)(p + 0x80);
    switch ((int)func_0200B98C(base, 3, 0)) {
    case 16: case 17: case 18: case 19: case 22:
        special = 1;
        count = 9;
        break;
    default:
        special = 0;
        count = 6;
        break;
    }
    for (i = 0; i < count; i++) {
        if (special && i >= 3 && i <= 5) continue;
        a = func_0200B98C(base, 0, i);
        b = func_0200B98C(base, 1, i);
        c = func_0200B98C(base, 6, i);
        if (a >= 0x28B) a = 0;
        if (a != 0) {
            *(int *)(out + n * 4) = a;
            *(int *)(out + n * 4 + 0x18) = b;
            *(int *)(out + n * 4 + 0x30) = c;
            n++;
        }
    }
}







int func_021DF8F0(int x, int y)
{
    int ok = ((unsigned)(x - 80) <= 88) & ((unsigned)(y - 32) <= 56);
    if (ok) func_020061E4(0x703);
    return ok;
}







int func_021DF920(void *obj, int unused, char *q)
{
    char *p;
    int i;
    p = func_0203159C(obj, 0x58, func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct Obj02230 *)q)->fC)));
    func_02082BCC(p, 0, 0x58);
    ((struct Obj01765 *)p)->f54 = func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct Obj02230 *)q)->fC));
    ((struct Obj01765 *)p)->f48 = (void *)func_0201C440((void *)(((struct Obj01765 *)p)->f54));
    ((struct Obj01765 *)p)->f44 = func_02025538(((struct Obj01765 *)p)->f54, ((struct Obj02230 *)q)->f4);
    ((struct Obj01765 *)p)->f38 = (int)func_021FD12C(((struct Obj02230 *)q)->f8, (void *)(*(int *)&((struct Obj01765 *)p)->f48), ((struct Obj01765 *)p)->f54);
    func_021FD170((char *)(((struct Obj01765 *)p)->f38), (char *)(((struct Obj02230 *)q)->f8), (void *)0x6B);
    for (i = 0; i < 2; i++) {
        *(int *)(p + i * 4 + 0x3C) = (int)func_021FD760(*(int *)&((struct Obj02230 *)q)->f4, (char *)(((struct Obj02230 *)q)->f8), i, ((struct Obj01765 *)p)->f54);
    }
    ((struct Obj02230 *)q)->f14 = 0xFFFF;
    ((struct Obj02230 *)q)->f16 = 0xFF;
    ((struct Obj02230 *)q)->f17 = 0xFF;
    ((struct Obj02230 *)q)->f18 = 0x13;
    func_021FBE54((char *)(((struct Obj02230 *)q)->f8), 6, ((struct Obj01765 *)p)->f54);
    func_021E02F8(p, (int *)q);
    return 1;
}







int func_021DF9C8(void *p, int unused, char *q, char *data)
{
    int i;
    func_021E037C(data, q);
    func_021FC0C8((char *)(((struct Obj14433 *)q)->f8), 6);
    for (i = 0; i < 2; i++) func_021FD820(*(char **)(data + i * 4 + 0x3c));
    func_021FD15C(((struct Obj10749 *)data)->f38, ((struct Obj14433 *)q)->f8);
    func_02025588(((struct Obj10749 *)data)->f44);
    func_0201C4C0(((struct Obj10749 *)data)->f48);
    func_020315D4(p);
    return 1;
}







int func_021DFA10(void *unused,u32 *state,int *q,char *p)
{
    int i;
    switch(*state) {
    case 0: if(d_021E37A8[*(int *)(p+0x4c)].init(p,q)) ++*state; break;
    case 1: func_021FE784(q[0],2,3,0); ++*state; break;
    case 2: if(func_021FE7B0((int *)q[0])) *state=3; break;
    case 3: if(d_021E37A8[*(int *)(p+0x4c)].update(p,q)) {
        if(((struct Obj05476 *)p)->f50==-1) *state=10; else *state=4;
    } break;
    case 4: func_021FE784(q[0],2,2,1); ++*state; break;
    case 5: if(func_021FE7B0((int *)q[0])) ++*state; break;
    case 6: if(d_021E37A8[*(int *)(p+0x4c)].finish(p,q)) {
        ((struct Obj05476 *)p)->f4C=((struct Obj05476 *)p)->f50; ++*state;
    } break;
    case 7: if(d_021E37A8[*(int *)(p+0x4c)].init(p,q)) ++*state; break;
    case 8: func_021FE784(q[0],2,2,0); ++*state; break;
    case 9: if(func_021FE7B0((int *)q[0])) *state=3; break;
    case 10: func_021FE784(q[0],2,3,1); ++*state; break;
    case 11: if(func_021FE7B0((int *)q[0])) *state=12; break;
    case 12: if(d_021E37A8[*(int *)(p+0x4c)].finish(p,q)) return 1; break;
    }
    for(i=0;i<3;i++) if(*(void **)(p+i*4)) func_021FC830(*(void **)(p+i*4));
    for(i=0;i<6;i++) if(*(void **)(p+0x20+i*4)) func_021FC830(*(void **)(p+0x20+i*4));
    if(((struct Obj05476 *)p)->f38) func_021FD1BC(((struct Obj05476 *)p)->f38);
    func_0201C4E4(((struct Obj05476 *)p)->f48);
    for(i=0;i<2;i++) func_021FD854(*(char **)(p+0x3c+i*4));
    return 0;
}







int func_021DFB90(char *p,char *q)
{
    int first,second,i;
    struct Request req;
    Triple triple;
    const struct Rec6 *r;
    const struct Rec8 *s;
    first=func_021FC20C(*(char * *)&((struct Obj05478 *)q)->f8);
    second=func_021FC214(*(char * *)&((struct Obj05478 *)q)->f8);
    func_021FB964((void *)(*(int *)&((struct Obj05478 *)q)->f8),26,((struct Obj05477 *)p)->f54);
    func_02082BCC(&req,0,8);
    func_021FC124((void *)*(int *)&((struct Obj05478 *)q)->f8,6,&triple);
    for(i=0;i<2;i++) {
        r=&d_021E3734[i];
        req.x=r->x; req.y=r->y; req.id=r->id; req.flag=1;
        *(void **)(p+0xc+i*4)=func_021FB378(&req,r->file,0x60,1,((struct Obj05478 *)q)->f4,((struct Obj05477 *)p)->f44,first,second,&triple,((struct Obj05477 *)p)->f54);
    }
    for(i=0;i<3;i++) {
        s=&d_021E3740[i];
        *(void **)(p+i*4)=func_021FC6A4(4,s->a,s->b,s->c,s->d,14,((struct Obj05477 *)p)->f48,((struct Obj05477 *)p)->f54);
        func_021FC754(*(char **)(p+i*4),(void *)second,s->value,(void *)first,0x3da0);
    }
    func_021FD170(((struct Obj05477 *)p)->f38,(char *)(*(int *)&((struct Obj05478 *)q)->f8),(void *)107);
    return 1;
}







int func_021DFC88(char *p, char *q)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (*(void **)(p + i * 4) != 0) {
            func_021FC734(*(void **)(p + i * 4));
            *(void **)(p + i * 4) = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (*(void **)(p + i * 4 + 12) != 0) {
            func_021FB494(*(void **)(p + i * 4 + 12));
            *(void **)(p + i * 4 + 12) = 0;
        }
    }
    func_020409B4(4);
    func_021FBDA4(((struct Obj24620 *)q)->f8, 26);
    return 1;
}






/*
 * lever: A separate result!=3 guard around the three-case switch removes the extra 8-byte dense dispatch (460 to 452 B).
 */
int func_021DFCD4(char *p,char *q)
{
    int result=func_021E04C8();
    if(result!=3) {
    switch(result) {
    case 0: {
        u32 x,y;
        int args[2];
        func_02035D20(&x,&y);args[0]=x;args[1]=y;
        func_021FD860((void *)((struct Obj00277 *)p)->f40,1,args);
        func_020061E4(0x703);
        ((struct Obj00351 *)q)->f18=19;
        func_021E03B0(p,q,0);
        func_021FD170(((struct Obj00277 *)p)->f38,(char *)(*(int *)&((struct Obj00351 *)q)->f8),(void *)105);
        ((struct Obj00277 *)p)->f50=1;
        return 1;
    }
    case 1: {
        u32 x,y;
        int args[2];
        func_02035D20(&x,&y);args[0]=x;args[1]=y;
        func_021FD860((void *)((struct Obj00277 *)p)->f40,1,args);
        func_020061E4(0x703);
        ((struct Obj00351 *)q)->f14=0xffff;
        func_021E03B0(p,q,1);
        func_021FD170(((struct Obj00277 *)p)->f38,(char *)(*(int *)&((struct Obj00351 *)q)->f8),(void *)106);
        ((struct Obj00277 *)p)->f50=2;
        return 1;
    }
    case 2: {
        void *v;
        int a,b;
        u32 x,y;
        int args[2];
        v=func_02012944(((struct Obj00351 *)q)->f10);
        a=func_0200856C(v);b=func_02008570(v);
        if(!a && !b) {
            func_021FD170(((struct Obj00277 *)p)->f38,(char *)(*(int *)&((struct Obj00351 *)q)->f8),(void *)120);
            func_020061E4(0x704);
            break;
        }
        func_02035D20(&x,&y);args[0]=x;args[1]=y;
        func_021FD860((void *)((struct Obj00277 *)p)->f40,1,args);
        func_020061E4(0x703);
        if(((struct Obj00351 *)q)->f16==255){((struct Obj00351 *)q)->f16=a;((struct Obj00351 *)q)->f17=b;}
        else{((struct Obj00351 *)q)->f16=255;((struct Obj00351 *)q)->f17=255;}
        func_021E03B0(p,q,2);
        return 0;
    }
    }
    }
    {
        u32 x,y;
        if(func_02035D20(&x,&y)) {
            if(func_021FB4B4((unsigned int *)(((struct Obj00277 *)p)->fC),x,y)) {
                int args[2];
                args[0]=x;args[1]=y;
                func_021FD860((void *)((struct Obj00277 *)p)->f40,1,args);
                ((struct Obj00277 *)p)->f50=-1;
                func_021F9BA0(((struct Obj00351 *)q)->fC);
                return 1;
            }
            if(func_021FB4CC((u32 *)(((struct Obj00277 *)p)->f10),x,y)) {
                if(((struct Obj00351 *)q)->f14!=0xffff || ((struct Obj00351 *)q)->f17!=255 || ((struct Obj00351 *)q)->f18!=19) {
                    int args[2];
                    args[0]=x;args[1]=y;
                    func_020061E4(0x703);
                    func_021FD860((void *)((struct Obj00277 *)p)->f40,1,args);
                    ((struct Obj00277 *)p)->f50=-1;
                    func_021F9BF4(*(unsigned * *)&((struct Obj00351 *)q)->fC,5);
                    return 1;
                }
                func_020061E4(0x704);
                func_021FD170(((struct Obj00277 *)p)->f38,(char *)(*(int *)&((struct Obj00351 *)q)->f8),(void *)108);
            }
        }
    }
    return 0;
}






int func_021DFE98(char *p,char *q)
{
    int first,second,i;
    Config cfg;
    Triple triple;
    Params params;
    first=func_021FC20C(*(char * *)&((struct Obj04571 *)q)->f8);
    second=func_021FC214(*(char * *)&((struct Obj04571 *)q)->f8);
    func_021FB964((void *)(*(int *)&((struct Obj04571 *)q)->f8),27,((struct Obj02523 *)p)->f54);
    *(Slot_021DB2E0 * *)&((struct Obj02523 *)p)->f14=func_0201F81C(19,((struct Obj02523 *)p)->f54);
    for(i=0;i<19;i++)func_0201F878((Slot_021DB2E0 *)((u32)*(Slot_021DB2E0 * *)&((struct Obj02523 *)p)->f14+i*8),second,i+205,i,((struct Obj02523 *)p)->f54);
    cfg=d_021E3758;
    cfg.words[0]=*(u32 *)&((struct Obj02523 *)p)->f14;cfg.words[1]=19;
    cfg.words[5]=*(u32 *)&((struct Obj04571 *)q)->f8;cfg.words[6]=((struct Obj04571 *)q)->f4;
    ((struct Obj02523 *)p)->f18=func_021FC8C8((const Config_021DF1DC *)&cfg,((struct Obj02523 *)p)->f54);
    func_02082BCC(&params,0,8);
    func_021FC124((void *)*(int *)&((struct Obj04571 *)q)->f8, 6, (Triple *)&triple);
    params.a=d_021E3728[0].a;params.b=d_021E3728[0].b;params.c=d_021E3728[0].c;params.flag=1;
    ((struct Obj02523 *)p)->fC=func_021FB378(&params,d_021E3728[0].file,96,1,*(int *)&((struct Obj04571 *)q)->f4,((struct Obj02523 *)p)->f44,first,second,&triple,((struct Obj02523 *)p)->f54);
    return 1;
}






int func_021DFF78(char *p, char *q)
{
    if (((struct Obj04572 *)p)->fC) {
        func_021FB494(((struct Obj04572 *)p)->fC);
        ((struct Obj04572 *)p)->fC = 0;
    }
    func_021FCC80(((struct Obj04572 *)p)->f18);
    ((struct Obj04572 *)p)->f18 = 0;
    func_0201F868(((struct Obj04572 *)p)->f14);
    ((struct Obj04572 *)p)->f14 = 0;
    func_021FBDA4(((struct Obj24621 *)q)->f8, 27);
    func_020409B4(4);
    return 1;
}






int func_021DFFB0(char *p, char *q)
{
    int selected, pressed;
    unsigned int x, y;
    func_021FCD0C(((struct Obj00277 *)p)->f18);
    selected = func_021FCDA8(((struct Obj00277 *)p)->f18);
    pressed = func_02035D20(&x, &y);
    pressed &= func_021FB4B4((unsigned int *)(((struct Obj00277 *)p)->fC), x, y);
    if (selected != -1) {
        unsigned int x1, y1;
        int args[2];
        func_02035D20(&x1, &y1);
        args[0] = x1;
        args[1] = y1;
        func_021FD860((void *)((struct Obj00277 *)p)->f40, 1, args);
        ((struct Obj00351 *)q)->f18 = selected;
        func_021E03B0(p, q, 0);
        ((struct Obj00277 *)p)->f50 = 0;
        return 1;
    } else if (pressed != 0) {
        unsigned int x2, y2;
        int args[2];
        func_02035D20(&x2, &y2);
        args[0] = x2;
        args[1] = y2;
        func_021FD860((void *)((struct Obj00277 *)p)->f40, 1, args);
        ((struct Obj00277 *)p)->f50 = 0;
        return 1;
    }
    return 0;
}






void func_021E0044(char *p, char *q)
{
    *(char * *)&((struct Obj04573 *)p)->f1C = func_021FFBD4(func_0200CA1C(((struct Obj08315 *)q)->f10), ((struct Obj08315 *)q)->f8, ((struct Obj08315 *)q)->f4, ((struct Obj04573 *)p)->f44, ((struct Obj08315 *)q)->f0, ((struct Obj04573 *)p)->f3C, ((struct Obj04573 *)p)->f40, ((struct Obj04573 *)p)->f54);
    func_021FFE5C(*(char * *)&((struct Obj04573 *)p)->f1C);
    func_021FFE34(*(char * *)&((struct Obj04573 *)p)->f1C);
}






int func_021E0080(char *p)
{
    func_021FFE70(((struct Obj14434 *)p)->f1C);
    func_021FFC6C(((struct Obj14434 *)p)->f1C);
    func_020409B4(4);
    return 1;
}





/*
 * lever: Repeat the reset store in both result arms, with return 1 shared after them; hoisting the store removes the branch at 0x021E00C8.
 */
int func_021E009C(char *p, char *q)
{
    u16 out;
    int result;
    func_021FFC9C(*(char * *)&((struct Obj00277 *)p)->f1C);
    result = func_021FFE90(*(int * *)&((struct Obj00277 *)p)->f1C, &out);
    if (result) {
        if (result == 2) {
            ((struct Obj00351 *)q)->f14 = out;
            func_021E03B0(p, q, 1);
            ((struct Obj00277 *)p)->f50 = 0;
        } else {
            ((struct Obj00277 *)p)->f50 = 0;
        }
        return 1;
    }
    return 0;
}





int func_021E00D8(char *p,char *q)
{
    int first,second,a,b;
    void *v,*text,*data;
    int ws;
    Config cfg;
    Triple triple;
    Params params;
    first=func_021FC20C(*(char * *)&((struct Obj03330 *)q)->f8);
    second=func_021FC214(*(char * *)&((struct Obj03330 *)q)->f8);
    func_021FB964((void *)(*(int *)&((struct Obj03330 *)q)->f8),28,((struct Obj02231 *)p)->f54);
    text=func_020457B0(128,((struct Obj02231 *)p)->f54);
    v=func_02012944(((struct Obj03330 *)q)->f10);
    a=func_0200856C(v);b=func_02008570(v);
    ws=func_021FC21C(*(char * *)&((struct Obj03330 *)q)->f8);
    data=func_02045EC0((void *)second,125);
    if(!func_02025B64(a))func_0201F048((void *)ws,0,a);
    else func_0201F094((void *)ws,0,a,b);
    func_0201F250((void *)ws,text,data);
    func_02045808(data);
    *(Slot_021DB2E0 * *)&((struct Obj02231 *)p)->f14=func_0201F81C(1,((struct Obj02231 *)p)->f54);
    func_0201F898(*(Slot_021DB2E0 * *)&((struct Obj02231 *)p)->f14,(u32)text,0,((struct Obj02231 *)p)->f54);
    func_02045808(text);
    cfg=d_021E3780;
    cfg.words[0]=*(u32 *)&((struct Obj02231 *)p)->f14;cfg.words[1]=1;
    cfg.words[5]=*(u32 *)&((struct Obj03330 *)q)->f8;cfg.words[6]=((struct Obj03330 *)q)->f4;
    ((struct Obj02231 *)p)->f18=func_021FC8C8((const Config_021DF1DC *)&cfg,((struct Obj02231 *)p)->f54);
    func_02082BCC(&params,0,8);
    func_021FC124((void *)*(int *)&((struct Obj03330 *)q)->f8, 6, (Triple *)&triple);
    params.a=d_021E372E[0].a;params.b=d_021E372E[0].b;params.c=d_021E372E[0].c;params.flag=1;
    ((struct Obj02231 *)p)->fC=func_021FB378(&params,d_021E372E[0].file,96,1,*(int *)&((struct Obj03330 *)q)->f4,((struct Obj02231 *)p)->f44,first,second,&triple,((struct Obj02231 *)p)->f54);
    return 1;
}





int func_021E0214(char *p, char *q)
{
    if (((struct Obj04574 *)p)->fC) {
        func_021FB494(((struct Obj04574 *)p)->fC);
        ((struct Obj04574 *)p)->fC = 0;
    }
    func_021FCC80(((struct Obj04574 *)p)->f18);
    ((struct Obj04574 *)p)->f18 = 0;
    func_0201F868(((struct Obj04574 *)p)->f14);
    ((struct Obj04574 *)p)->f14 = 0;
    func_021FBDA4(((struct Obj24622 *)q)->f8, 28);
    func_020409B4(4);
    return 1;
}





/*
 * trailing: two zero alignment bytes at 0x021E02F6
 */
int func_021E024C(char *p, char *q)
{
    int selected, pressed;
    unsigned int x, y;
    func_021FCD0C(((struct Obj00277 *)p)->f18);
    selected = func_021FCDA8(((struct Obj00277 *)p)->f18);
    pressed = func_02035D20(&x, &y);
    pressed &= func_021FB4B4((unsigned int *)(((struct Obj00277 *)p)->fC), x, y);
    if (selected != -1) {
        unsigned int x1, y1;
        int args[2];
        void *v;
        int a;
        func_02035D20(&x1, &y1);
        args[0] = x1;
        args[1] = y1;
        func_021FD860((void *)((struct Obj00277 *)p)->f40, 1, args);
        v = func_02012944(((struct Obj00351 *)q)->f10);
        a = func_0200856C(v);
        ((struct Obj00351 *)q)->f17 = func_02008570(v);
        ((struct Obj00351 *)q)->f16 = a;
        func_021E03B0(p, q, 2);
        ((struct Obj00277 *)p)->f50 = 0;
        return 1;
    } else if (pressed != 0) {
        unsigned int x2, y2;
        int args[2];
        func_02035D20(&x2, &y2);
        args[0] = x2;
        args[1] = y2;
        func_021FD860((void *)((struct Obj00277 *)p)->f40, 1, args);
        ((struct Obj00277 *)p)->f50 = 0;
        return 1;
    }
    return 0;
}





void func_021E02F8(char *p, int *q)
{
    int first, second, i;
    const struct Record_021E009C *r;
    first = func_021FC20C((char *)q[2]);
    second = func_021FC214((char *)q[2]);
    func_021FB964((void *)q[2], 25, ((struct Obj01765 *)p)->f54);
    for (i = 0; i < 6; i++) {
        r = &d_021E37D8[i];
        *(void **)(p + i * 4 + 0x20) = func_021FC6A4(1, r->a, r->b, r->c, r->d, 14, ((struct Obj01765 *)p)->f48, ((struct Obj01765 *)p)->f54);
        func_021FC868(*(void **)(p + i * 4 + 0x20), 0, 1, 0);
        func_021FC754(*(void **)(p + i * 4 + 0x20), (void *)second, (void *)r->value, (void *)first, 15776);
    }
}





/*
 * extent: final two bytes are alignment padding.
 */
void func_021E037C(char *p,char *q){int i;for(i=0;i<6;i++){if(*(void **)(p+i*4+0x20)){func_021FC734(*(void **)(p+i*4+0x20));*(void **)(p+i*4+0x20)=0;}}func_021FBDA4(((struct Obj24623 *)q)->f8,25);func_020409B4(1);}





void func_021E03B0(char *p,char *q,int mode)
{
    int first,second,ws;
    void *data,*text;
    first=func_021FC20C(*(char * *)&((struct Obj00351 *)q)->f8);
    second=func_021FC214(*(char * *)&((struct Obj00351 *)q)->f8);
    switch(mode) {
    case 0:
        if(((struct Obj00351 *)q)->f18!=19)func_021FC754(*(char * *)&((struct Obj00277 *)p)->f24,(void *)second,(void *)(((struct Obj00351 *)q)->f18+205),(void *)first,0x3da0);
        else func_021FC754(*(char * *)&((struct Obj00277 *)p)->f24,(void *)second,(void *)117,(void *)first,0x3da0);
        return;
    case 1:
        if(((struct Obj00351 *)q)->f14!=0xffff)func_021FC754(*(char * *)&((struct Obj00277 *)p)->f2C,(void *)d_020A7370,(void *)(u32)((struct Obj00351 *)q)->f14,(void *)first,0x3da0);
        else func_021FC754(*(char * *)&((struct Obj00277 *)p)->f2C,(void *)second,(void *)117,(void *)first,0x3da0);
        return;
    case 2:
        if(((struct Obj00351 *)q)->f16==255 && ((struct Obj00351 *)q)->f17==255) {
            func_021FC754(*(char * *)&((struct Obj00277 *)p)->f34,(void *)second,(void *)117,(void *)first,0x3da0);
            return;
        }
        ws=func_021FC21C(*(char * *)&((struct Obj00351 *)q)->f8);
        data=func_02045EC0((void *)second,24);
        text=func_020457B0(128,((struct Obj00277 *)p)->f54);
        if(!func_02025B64(((struct Obj00351 *)q)->f16))func_0201F048((void *)ws,0,((struct Obj00351 *)q)->f16);
        else func_0201F094((void *)ws,0,((struct Obj00351 *)q)->f16,((struct Obj00351 *)q)->f17);
        func_0201F250((void *)ws,text,data);
        func_021FC7C4(*(char * *)&((struct Obj00277 *)p)->f34,text,(void *)first,0x3da0);
        func_02045808(data);func_02045808(text);
        break;
    }
}






/*
 * Hit-test a point against a table of three rectangles; returns the index
 * of the first hit, or 3 when none (or when no point is available).
 */
int func_021E04C8(void)
{
    unsigned int x, y;
    int i;

    if (func_02035D20(&x, &y)) {
        for (i = 0; i < 3; i++) {
            const Rect_021DF388 *r = &g_021E3808[i];
            if (x - r->x0 <= r->x1 - r->x0 && y - r->y0 <= r->y1 - r->y0) {
                return i;
            }
        }
    }
    return 3;
}





/*
 * extent: 021E05C2 alignment padding.
 */
int func_021E050C(void *task, int unused, char *q)
{
    struct Data_021DF388 *p;
    int entries[3];
    func_021FC20C((char *)(*(int *)&((struct Obj01767 *)q)->f8));
    func_021FC214(*(char * *)&((struct Obj01767 *)q)->f8);
    p = func_0203159C(task, 24, func_021F9B9C(((struct Obj01767 *)q)->fC));
    func_02082BCC(p, 0, 24);
    p->heap = func_021F9B9C(((struct Obj01767 *)q)->fC);
    func_021FB964((void *)(*(int *)&((struct Obj01767 *)q)->f8), 29, p->heap);
    func_021FBE54(*(char * *)&((struct Obj01767 *)q)->f8, 11, p->heap);
    func_021FBE54(*(char * *)&((struct Obj01767 *)q)->f8, 12, p->heap);
    func_021FBE54(*(char * *)&((struct Obj01767 *)q)->f8, 6, p->heap);
    p->e = func_021FD760((unsigned int)(((struct Obj01767 *)q)->f4), (char *)(*(int *)&((struct Obj01767 *)q)->f8), 1, p->heap);
    entries[0] = 2;
    entries[1] = 5;
    entries[2] = 5;
    p->a = func_021E07A4(p->heap, 12, ((struct Obj01767 *)q)->f4, (void *)(*(int *)&((struct Obj01767 *)q)->f8), p->e, entries);
    p->b = func_021E06D0(p->a, p->heap);
    p->d = (void *)func_0201C440((void *)p->heap);
    p->c = func_021FD12C(*(int *)&((struct Obj01767 *)q)->f8, p->d, p->heap);
    func_021FD170(p->c, (char *)(*(int *)&((struct Obj01767 *)q)->f8), (void *)104);
    return 1;
}





/*
 * extent: 021E0616 alignment padding; next owned function starts 021E0618.
 */
int func_021E05C4(void *a, int unused, int *q, void **p)
{
    func_021FD15C((void *)((int)p[2]), q[2]);
    func_021E0774(p[1]);
    func_021E0808(p[0]);
    func_0201C4C0(p[3]);
    func_021FD820(p[5]);
    func_021FBDA4(q[2], 29);
    func_021FC0C8((char *)q[2], 6);
    func_021FC0C8((char *)q[2], 12);
    func_021FC0C8((char *)q[2], 11);
    func_020315D4(a);
    return 1;
}





/*
 * extent: 021E06CE alignment padding.
 */
int func_021E0618(int unused, int *state, int *q, int *p)
{
    switch (*state) {
    case 0:
        func_021FE784(q[0], 2, 3, 0);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0((int *)q[0])) *state = 2;
        break;
    case 2:
        func_021E0754((char *)p[1]);
        switch (func_021E075C((char *)p[1])) {
        case 1: func_021F9BA0((unsigned int *)q[3]); *state = 3; break;
        case 2: ((struct Obj04576 *)q)->f10 = func_021E0764((char *)p[1]); func_021F9BF4((unsigned int *)q[3], 2); *state = 3; break;
        }
        break;
    case 3:
        func_021FE784(q[0], 2, 3, 1);
        *state = 4;
        break;
    case 4:
        if (func_021FE7B0((int *)q[0])) *state = 5;
        break;
    case 5: return 1;
    }
    if (p[2]) func_021FD1BC((void *)p[2]);
    func_0201C4E4((struct PrintSys *)p[3]);
    func_021FD854((char *)p[5]);
    return 0;
}


/*
 * extent: 0754 tail-call stub; 075C state getter; 0764 64-bit getter; 0772 padding.
 */
char *func_021E06D0(const struct Source *src, u16 heap)
{
    char *p;
    p = func_02030734(heap, 0x368, 0, d_021E3968, 56);
    func_02082BCC(p, 0, 0x368);
    *(struct Source *)(p + 0x324) = *src;
    ((struct Obj03331 *)p)->f34C = heap;
    ((struct Obj03331 *)p)->f25C = src->words[7];
    ((struct Obj03331 *)p)->f310 = func_021FC20C((char *)src->words[8]);
    ((struct Obj03331 *)p)->f258 = func_020490F4(59, ((struct Obj03331 *)p)->f34C);
    func_021E1244(p);
    func_021E1910(p);
    ((struct Obj03331 *)p)->f314 = func_020056A0(func_021E083C, p, 16);
    return p;
}


void func_021E0754(char *p)
{
    func_021E16E4(p);
}


int func_021E075C(char *p)
{
    return ((struct Obj24624 *)p)->f350;
}


u64 func_021E0764(char *p)
{
    return ((struct Obj24625 *)p)->f360;
}


void func_021E0774(char *p){func_02030EAC(((struct Obj10751 *)p)->f314);func_021E08E4(p);func_02049238(((struct Obj10751 *)p)->f258);func_02051C6C(((struct Obj10751 *)p)->f294);func_020307B0(p);}


struct Object *func_021E07A4(int heap, int n, void *a, void *b, void *c, int *entries)
{
    int i;
    struct Object *p;
    p = func_02030734((u16)heap, 40, 0, d_021E3968, 192);
    p->a = a;
    p->b = b;
    p->capacity = n;
    p->vector = func_020457B0(n + 1, heap);
    p->c = c;
    for (i = 0; i < 3; i++) p->entries[i] = entries[i];
    p->entries[i] = entries[i - 1];
    return p;
}


/*
 * extent: existing matched callback 021E083C and its alignment follow the pool.
 */
void func_021E0808(char *p){if(!((struct Obj14437 *)p)->f18)func_02034714(d_021E3974,0,d_021E3974);if(!p)func_02034714(d_021E3974,0,d_021E3974);func_02045808(((struct Obj14437 *)p)->f18);func_020307B0(p);}


/*
 * leaf: empty callback solely blocks owned constructor 021E06D0; parent cleared.
 * extent: bx lr at 083C; 083E alignment; existing owned 0840 follows.
 */
void func_021E083C(void)
{
}


void func_021E0840(char *p)
{
    struct Triple t;
    if (!func_021FC124(((struct Obj00143 *)p)->f344, 11, &t)) func_02034714(d_021E3978, 0, d_021E3978);
    ((struct Obj00143 *)p)->f260 = t.c;
    ((struct Obj00143 *)p)->f26C = t.b;
    ((struct Obj00143 *)p)->f284 = t.a;
    if (!func_021FC124(((struct Obj00143 *)p)->f344, 12, &t)) func_02034714(d_021E3978, 0, d_021E3978);
    ((struct Obj00143 *)p)->f268 = t.c;
    ((struct Obj00143 *)p)->f274 = t.b;
    ((struct Obj00143 *)p)->f28C = t.a;
    if (!func_021FC124(((struct Obj00143 *)p)->f344, 6, &t)) func_02034714(d_021E3978, 0, d_021E3978);
    *(int *)&((struct Obj00143 *)p)->f264 = t.c;
    *(int *)&((struct Obj00143 *)p)->f270 = t.b;
    *(int *)&((struct Obj00143 *)p)->f288 = t.a;
}


/*
 * extent: 021E0952 alignment padding.
 */
void func_021E08E4(char *p)
{
    int i;
    for (i = 0; i < ((struct Obj08317 *)p)->f23C; i++) func_0204B3B4(*(void **)(p + i * 28 + 12));
    for (i = 0; i < 2; i++) {
        func_0204B3B4(*(void **)(p + i * 28 + 0x15c));
        func_0204B3B4(*(void **)(p + i * 28 + 0x1e8));
    }
    for (i = 0; i < 3; i++) func_0204B3B4(*(void **)(p + i * 28 + 0x194));
    func_021E10BC(p);
}


/*
 * lever: The explicit entry guard encloses a do-while; a for adds a second entry test (308 B DIFF to 306 B EXACT*).
 * trailing: 021E0A86..021E0A88 is two zero alignment bytes.
 * abi: 0204B294 caller uses returned r0 despite callee's void spelling; fifth payload remains its u32 address word.
 * note 2026-10-05 (wave D9r lane 131): removed the 7 dead first assignments
 * (`heapA=0x25c;` before `heapA=0x34c;`; `aA=0x25c;` before `aA=0x26c;` and
 * 5 more). Game code has no line table, so these were stand-ins. The plain
 * single assignment gives EXACT* in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void func_021E0954(char *p)
{
    int i,special,normal,base;
    u32_021E0954 owner;
    int heapA,aA,bA,cA,heapB,aB,bB,cB,countOffset,recordOffset;
    Params params;
    normal=0;
    base=0x25c;
    owner=*(u32_021E0954 *)(p+base);
    params.a=normal;params.b=normal;params.c=normal;params.flag=10;params.pad=normal;
    special=0;i=0;
    if(*(int *)(p+base-0x20)+2>0) {
        heapA=0x34c;
        aA=0x26c;
        bA=0x260;
        cA=0x284;
        heapB=0x34c;
        aB=0x26c;
        bB=0x260;
        cB=0x284;
        countOffset=0x23c;
        recordOffset=0x150;
        do {
            char *q;
            q=p+special*28;
            if(i==*(int *)(q+recordOffset)+special+1) {
                void *obj;
                params.a=i*8+76;params.b=24;params.c=22;
                obj=func_0204B294((void *)owner,*(u32_021E0954 *)(p+aB),*(u32_021E0954 *)(p+bB),*(u32_021E0954 *)(p+cB),&params,1,*(u16 *)(p+heapB));
                ((struct Obj08316 *)q)->f15C=obj;func_0204B688(obj,1);
                special++;
            } else {
                void *obj;
                params.a=i*8+76;params.b=24;
                q=p+normal*28;
                params.c=func_021E0E40(((struct Obj08316 *)q)->f0,((struct Obj08316 *)q)->f8);
                obj=func_0204B294((void *)owner,*(u32_021E0954 *)(p+aA),*(u32_021E0954 *)(p+bA),*(u32_021E0954 *)(p+cA),&params,1,*(u16 *)(p+heapA));
                ((struct Obj08316 *)q)->fC=obj;func_0204B688(obj,1);
                normal++;
            }
            i++;
        } while(i<*(int *)(p+countOffset)+2);
    }
}


/*
 * abi: 0204B294 r0 consumed after call; pointer request passed as the unchanged u32 fifth payload.
 */
void func_021E0A88(char *p)
{
    int base,zero;
    u32_021E0A88 owner;
    Params params;
    base=0x25c;owner=*(u32_021E0A88 *)(p+base);zero=0;
    params.a=zero;params.b=zero;params.c=zero;params.flag=zero;params.pad=zero;
    *(u32_021E0A88 *)(p+base-0xc8)=(u32_021E0A88)func_0204B294((void *)owner,*(u32_021E0A88 *)(p+base+0x18),*(u32_021E0A88 *)(p+base+0xc),*(u32_021E0A88 *)(p+base+0x30),&params,1,*(u16 *)(p+base+0xf0));
    func_0204B688(*(void **)(p+base-0xc8),1);
    *(u32_021E0A88 *)(p+base-0xac)=(u32_021E0A88)func_0204B294((void *)owner,*(u32_021E0A88 *)(p+base+0x18),*(u32_021E0A88 *)(p+base+0xc),*(u32_021E0A88 *)(p+base+0x30),&params,1,*(u16 *)(p+base+0xf0));
    func_0204B688(*(void **)(p+base-0xac),1);
    *(u32_021E0A88 *)(p+base-0x90)=(u32_021E0A88)func_0204B294((void *)owner,*(u32_021E0A88 *)(p+base+0x18),*(u32_021E0A88 *)(p+base+0xc),*(u32_021E0A88 *)(p+base+0x30),&params,1,*(u16 *)(p+base+0xf0));
    func_0204B688(*(void **)(p+base-0x90),1);
    func_021E0D00(p,0);
    func_0204B878(*(void **)(p+base-0xc8),0);func_0204B92C(*(void **)(p+base-0xc8),1);
    *(u16 *)(p+base-0xa4)=zero;*(u16 *)(p+base-0xa2)=zero;*(u32_021E0A88 *)(p+base-0xb8)=1;
    func_021E0D38((struct Coordinates *)p,0);
    func_0204B878(*(void **)(p+base-0xac),*(u32_021E0A88 *)(p+base-0xb8));
    func_0204B92C(*(void **)(p+base-0xac),1);func_0204B688(*(void **)(p+base-0xac),1);
    *(u16 *)(p+base-0x88)=zero;*(u16 *)(p+base-0x86)=zero;*(u32_021E0A88 *)(p+base-0x9c)=1;
    func_021E0D38((struct Coordinates *)p,zero);
    func_0204B878(*(void **)(p+base-0x90),*(u32_021E0A88 *)(p+base-0x9c));
    func_0204B688(*(void **)(p+base-0x90),1);func_0204B92C(*(void **)(p+base-0x90),1);
    func_021E0CE8(p,1,zero);func_021E0CE8(p,2,zero);
}


/*
 * Caller evidence: 0204B294 leaves its forwarded return word live in r0; consumed by store and 0204B688 here.
 */
void func_021E0C04(char *p) {
    struct Params pos;
    u32_021E0C04 manager=*(u32_021E0C04 *)&((struct Obj00143 *)p)->f25C;
    pos.a=0;pos.b=0;pos.z=0;pos.mode=10;pos.flag=0;
    *(u32_021E0C04 *)&((struct Obj00143 *)p)->f1E8=(u32_021E0C04)func_0204B294((void *)manager,((struct Obj00143 *)p)->f270,((struct Obj00143 *)p)->f264,((struct Obj00143 *)p)->f288,&pos.a,1,((struct Obj00143 *)p)->f34C);
    func_0204B688(((struct Obj00143 *)p)->f1E8,1);
    pos.z=1;
    *(u32_021E0C04 *)&((struct Obj00143 *)p)->f204=(u32_021E0C04)func_0204B294((void *)manager,((struct Obj00143 *)p)->f270,((struct Obj00143 *)p)->f264,((struct Obj00143 *)p)->f288,&pos.a,1,((struct Obj00143 *)p)->f34C);
    func_0204B688(((struct Obj00143 *)p)->f204,1);
    pos.x=((struct Obj00143 *)p)->f2F2;pos.y=((struct Obj00143 *)p)->f2F0+16;
    func_0204B404(((struct Obj00143 *)p)->f1E8,(const struct Vec2 *)(&pos.x),1);
    func_0204B878(((struct Obj00143 *)p)->f1E8,0);
    pos.x=((struct Obj00143 *)p)->f2F6;pos.y=((struct Obj00143 *)p)->f2F4+16;
    func_0204B404(((struct Obj00143 *)p)->f204,(const struct Vec2 *)(&pos.x),1);
    func_0204B878(((struct Obj00143 *)p)->f204,1);
}



void func_021E0CE8(char *p, int index, int a2)
{
    func_0204B3DC((struct Obj *)*(int *)(p + index * 0x1c + 0x194), (unsigned int)a2);
}


void func_021E0D00(char *p,int i){short pos[2];void *obj;obj=*(void **)(p+i*28+12);((struct Obj02895 *)p)->f188=i;func_0204B454(obj,(struct PtS *)pos,1);pos[1]+=16;func_0204B404(((struct Obj02895 *)p)->f194,(const struct Vec2 *)pos,1);}


/*
 * extent: 021E0D8E alignment padding.
 */
void func_021E0D38(struct Coordinates *p, int index)
{
    int width = p->rect[index + 12][1] - p->rect[index + 12][0];
    int height = p->rect[index + 12][3] - p->rect[index + 12][2];
    s16_021E06D0 pos[2];
    pos[0] = height / 2 + p->rect[index + 12][2];
    pos[1] = width / 2 + p->rect[index + 12][0];
    func_0204B404(((struct Obj02895 *)p)->f1B0, (const struct Vec2 *)pos, 1);
    func_0204B8C4(((struct Obj02895 *)p)->f1B0, 0);
}


/*
 * extent: 021E0E3E alignment padding.
 */
void func_021E0D90(char *p)
{
    int i, state;
    for (i = 1; i < 3; i++) {
        state = func_0204B898(*(void **)(p + i * 28 + 0x194));
        if (state == 3) {
            if (!func_0204B98C(*(void **)(p + i * 28 + 0x194))) {
                func_0204B878(*(void **)(p + i * 28 + 0x194), *(int *)(p + i * 28 + 0x188));
                if (((struct Obj14438 *)p)->f2FC == 1) func_021E0CE8(p, 1, 0);
                else func_021E0CE8(p, 1, 1);
                func_021E0CE8(p, 2, 0);
            }
        } else {
            if (state != *(int *)(p + i * 28 + 0x188)) func_0204B878(*(void **)(p + i * 28 + 0x194), *(int *)(p + i * 28 + 0x188));
            if (func_0204B898(*(void **)(p + i * 28 + 0x194)) != 3) {
                if (((struct Obj14438 *)p)->f2FC == 1) func_021E0CE8(p, 1, 0);
                else func_021E0CE8(p, 1, 1);
            }
        }
    }
}


int func_021E0E40(int a, int b) { int n=0; if(b==0)n=11; return n+a; }


void func_021E0E4C(char *p)
{
    int i;
    for (i = 0; i < ((struct Obj00143 *)p)->f23C; i++) {
        if (i >= ((struct Obj00143 *)p)->f248 && i < ((struct Obj00143 *)p)->f24C)
            *(int *)(p + i * 28 + 8) = 1;
        else
            *(int *)(p + i * 28 + 8) = 0;
    }
}


void func_021E0E90(char *p,int animated) {
    int i,group;
    s16_021E06D0 pos;
    char *record,*special;
    Coords coords;
    pos=*(s16_021E06D0 *)((u32_021E0E90)p+((struct Obj00143 *)p)->f240*2+0x214);
    group=0;
    for(i=0;i<((struct Obj00143 *)p)->f23C;i++){
        if(i>=((struct Obj00143 *)p)->f248&&i<((struct Obj00143 *)p)->f24C){
            if(i==((struct Obj00143 *)p)->f248)pos+=20;else pos+=32;
        }else{
            if(i==0)pos+=20;else pos+=8;
        }
        record=(char *)((u32_021E0E90)p+i*28);
        func_0204B454(((struct Obj05480 *)record)->fC,(struct PtS *)&coords.x,1);
        if(animated==0){
            coords.x=pos;
            func_0204B404(((struct Obj05480 *)record)->fC,(const struct Vec2 *)(&coords.x),1);
        }else{
            ((struct Obj05480 *)record)->f14=(pos-coords.x)/4;
            ((struct Obj05480 *)record)->f16=0;
            ((struct Obj05480 *)record)->f18=4;
            ((struct Obj05480 *)record)->f19=0;
        }
        special=(char *)((u32_021E0E90)p+group*28);
        if(i==((struct Obj05481 *)special)->f150&&group!=2){
            func_0204B454(((struct Obj05481 *)special)->f15C,(struct PtS *)&coords.a,1);
            if(((struct Obj00143 *)p)->f248==((struct Obj00143 *)p)->f24C)pos+=8;
            else {
                if(i>((struct Obj00143 *)p)->f248&&i<((struct Obj00143 *)p)->f24C)pos+=20;
                else pos+=8;
            }
            if(animated==0){
                coords.a=pos;
                func_0204B404(((struct Obj05481 *)special)->f15C,(const struct Vec2 *)(&coords.a),1);
            }else{
                ((struct Obj05481 *)special)->f164=(pos-coords.a)/4;
                ((struct Obj05481 *)special)->f166=0;
                ((struct Obj05481 *)special)->f168=4;
            }
            group++;
        }
    }
}


void func_021E1008(char *p)
{
    int i, x, y;
    s16_021E06D0 pos[2];
    for (i = 0; i < ((struct Obj00143 *)p)->f23C; i++) {
        if (i >= ((struct Obj00143 *)p)->f248 && i < ((struct Obj00143 *)p)->f24C) {
            x = 16;
            y = 16;
        } else {
            x = 4;
            y = 8;
        }
        func_0204B454(*(void **)(p + i * 28 + 12), (struct PtS *)pos, 1);
        (*(u8 **)(p + i * 28 + 16))[0] = pos[1] - y;
        (*(u8 **)(p + i * 28 + 16))[2] = pos[0] - x;
        (*(u8 **)(p + i * 28 + 16))[1] = pos[1] + y;
        (*(u8 **)(p + i * 28 + 16))[3] = pos[0] + x;
    }
}



void func_021E10A0(char *p)
{
    ((struct Obj00143 *)p)->f300 =
        func_02025538(((struct Obj00143 *)p)->f34C, ((struct Obj00143 *)p)->f25C);
}


void func_021E10BC(char *p){ func_0202570C(*(struct Grid * *)&((struct Obj08317 *)p)->f304); func_0202570C(*(struct Grid * *)&((struct Obj08317 *)p)->f308); func_02025588(((struct Obj08317 *)p)->f300); }



void func_021E10DC(char *p)
{
    func_02049238(func_020490F4(0x17, ((struct Obj24626 *)p)->f34C));
}


void func_021E10F4(char *p){ func_021E10DC(p);func_021E111C(p,0,32,8,0);func_021E111C(p,1,32,8,0); }
