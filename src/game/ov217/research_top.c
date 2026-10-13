/*
 * file:     research_top.c
 * unit:     yes
 * function: func_021B95A0, func_021B9600, func_021B9620, func_021B96A0, func_021B96C8, func_021B970C, func_021B9774, func_021B97B8, func_021B97BC, func_021B97F8, func_021B9824, func_021B9850, func_021B9854, func_021B985C, func_021B9874, func_021B9884, func_021B9894, func_021B98A8, func_021B98B8, func_021B990C, func_021B9920, func_021B99EC, func_021B9A24, func_021B9AD0, func_021B9AF8, func_021B9B08, func_021B9B80, func_021B9B90, func_021B9B98, func_021B9C54, func_021B9E44, func_021BA078, func_021BA094, func_021BA0C4, func_021BA144, func_021BA150, func_021BA158, func_021BA180, func_021BA190, func_021BA194, func_021BA19C, func_021BA1C0, func_021BA1CC, func_021BA1D4, func_021BA1F8, func_021BA228, func_021BA254, func_021BA284, func_021BA2BC, func_021BA2FC, func_021BA31C, func_021BA328, func_021BA354, func_021BA364, func_021BA374, func_021BA37C, func_021BA380, func_021BA384, func_021BA388, func_021BA3B0, func_021BA3B4, func_021BA3D0, func_021BA3D8, func_021BA3E0, func_021BA3E8, func_021BA40C, func_021BA41C, func_021BA434, func_021BA4C8, func_021BA4CC, func_021BA4D0, func_021BA4D4, func_021BA4E0, func_021BA4FC, func_021BA504, func_021BA560, func_021BA5B4, func_021BA5BC, func_021BA5D8, func_021BA5E4, func_021BA5F8, func_021BA624, func_021BA63C, func_021BA674, func_021BA67C, func_021BA68C, func_021BA698, func_021BA748, func_021BA768, func_021BA7B4, func_021BA7B8, func_021BA7D0, func_021BA7E0, func_021BA82C, func_021BA830, func_021BA848, func_021BA858, func_021BA86C, func_021BA8E0, func_021BA8FC, func_021BA910, func_021BA960, func_021BA978, func_021BA9D0, func_021BA9E8, func_021BA9FC, func_021BAA28, func_021BAA40, func_021BAA48, func_021BAAB8, func_021BAAC4, func_021BAAD8, func_021BAAF4, func_021BAB0C, func_021BAB38, func_021BAB50, func_021BAB58, func_021BAB68, func_021BAB70, func_021BAB80, func_021BABB4, func_021BABC4, func_021BAC90, func_021BAC98, func_021BACA0, func_021BAE00, func_021BAF70, func_021BB190, func_021BB200, func_021BB2B4, func_021BB37C, func_021BB484, func_021BB534, func_021BB5F4, func_021BB69C, func_021BB710, func_021BB784, func_021BB84C, func_021BB908, func_021BB910, func_021BB91C, func_021BB928, func_021BB934, func_021BB940, func_021BB948, func_021BB94C, func_021BB974, func_021BB978, func_021BB98C, func_021BB990, func_021BB998, func_021BB9A0, func_021BB9D0, func_021BBA00, func_021BBA30, func_021BBAA4, func_021BBAD0, func_021BBADC, func_021BBB60, func_021BBBE4, func_021BBC50, func_021BBCB0, func_021BBCFC, func_021BBD14, func_021BBD18, func_021BBD28, func_021BBD38, func_021BBD40, func_021BBD68, func_021BBDAC, func_021BBDF0, func_021BBE7C, func_021BBF04, func_021BBF1C, func_021BBF28, func_021BBF3C, func_021BBF4C, func_021BBF60, func_021BC014, func_021BC06C, func_021BC07C, func_021BC0E8, func_021BC128, func_021BC168, func_021BC1AC, func_021BC200, func_021BC250, func_021BC264, func_021BC274, func_021BC280, func_021BC2B8, func_021BC2CC, func_021BC2D8, func_021BC2FC, func_021BC30C, func_021BC330, func_021BC338, func_021BC380, func_021BC3AC, func_021BC3B8, func_021BC3D4, func_021BC3E0, func_021BC3EC, func_021BC3F8, func_021BC400, func_021BC40C, func_021BC41C, func_021BC428, func_021BC43C, func_021BC480, func_021BC490, func_021BC4A0, func_021BC4B4, func_021BC50C, func_021BC55C, func_021BC574, func_021BC580, func_021BC5A8, func_021BC5B8, func_021BC5D4, func_021BC5F0, func_021BC5FC, func_021BC600, func_021BC608, func_021BC610, func_021BC628, func_021BC634, func_021BC638, func_021BC63C, func_021BC640, func_021BC644, func_021BC688, func_021BC6D0, func_021BC6DC, func_021BC6E4, func_021BC6EC, func_021BC6F4, func_021BC708, func_021BC714, func_021BC720, func_021BC72C, func_021BC740, func_021BC758, func_021BC774, func_021BC818, func_021BC820, func_021BC8B4, func_021BC8D0, func_021BC8D8, func_021BC8E4, func_021BC910, func_021BC924, func_021BC93C, func_021BC94C, func_021BC954, func_021BC960, func_021BC9FC, func_021BCAC0, func_021BCAE8, func_021BCB44, func_021BCB48, func_021BCB60, func_021BCB70, func_021BCBCC, func_021BCBD0, func_021BCC3C, func_021BCC40, func_021BCC58, func_021BCC68, func_021BCD6C, func_021BCD90, func_021BCDDC, func_021BCDF0, func_021BCE5C, func_021BCE7C, func_021BCF20, func_021BCF4C, func_021BCF68, func_021BCF98, func_021BCFB4, func_021BCFD0, func_021BD05C, func_021BD078, func_021BD094, func_021BD0C4, func_021BD178, func_021BD274, func_021BD370, func_021BD38C, func_021BD3A4, func_021BD3B4, func_021BD458, func_021BD474, func_021BD47C, func_021BD4CC, func_021BD4F0, func_021BD50C, func_021BD520, func_021BD53C, func_021BD56C, func_021BD588, func_021BD5B4, func_021BD5C4, func_021BD5E0, func_021BD5F4, func_021BD61C, func_021BD62C, func_021BD708, func_021BD710, func_021BD718, func_021BD868, func_021BD89C, func_021BDC18, func_021BDF58, func_021BE040, func_021BE094, func_021BE0D0, func_021BE108, func_021BE21C, func_021BE33C, func_021BE36C, func_021BE384, func_021BE448, func_021BE454, func_021BE460, func_021BE468, func_021BE46C, func_021BE490, func_021BE498, func_021BE4A4, func_021BE4CC, func_021BE4DC, func_021BE4E0, func_021BE4E8, func_021BE580, func_021BE614, func_021BE630, func_021BE678, func_021BE704, func_021BE790, func_021BE7B4, func_021BE7D8, func_021BE7F0, func_021BE808, func_021BE8FC, func_021BE90C, func_021BE91C, func_021BE930, func_021BE934, func_021BE9B8, func_021BEA3C, func_021BEA54, func_021BEA8C, func_021BEAEC, func_021BEAF8, func_021BEB40, func_021BEB6C, func_021BEB88, func_021BEBA4, func_021BEBC0, func_021BEBE4, func_021BEC00, func_021BEC0C, func_021BEC34, func_021BEC64, func_021BEC84, func_021BED10, func_021BED9C, func_021BEDC4, func_021BEDEC, func_021BEEA4, func_021BEF30, func_021BEF98, func_021BEFC0, func_021BEFD4, func_021BEFF8, func_021BF08C, func_021BF100, func_021BF11C, func_021BF13C, func_021BF15C, func_021BF264, func_021BF2FC, func_021BF38C, func_021BF3B4, func_021BF3D8, func_021BF47C, func_021BF4AC, func_021BF55C, func_021BF568, func_021BF574, func_021BF580, func_021BF594, func_021BF5BC, func_021BF5D0, func_021BF5E4, func_021BF600, func_021BF60C, func_021BF658, func_021BF6A4, func_021BF6BC, func_021BF6D4, func_021BF704, func_021BF710, func_021BF728, func_021BF734, func_021BF740, func_021BF74C, func_021BF750, func_021BF754, func_021BF758, func_021BF764, func_021BF76C, func_021BF77C, func_021BF78C, func_021BF7CC, func_021BF7E0, func_021BF7F4, func_021BF810, func_021BF834, func_021BF844, func_021BF854, func_021BF878, func_021BF894, func_021BF8B0, func_021BF910, func_021BF968, func_021BF9CC, func_021BF9F0, func_021BF9FC, func_021BFA08, func_021BFA14, func_021BFA30, func_021BFB04, func_021BFB0C, func_021BFB14, func_021BFB24, func_021BFB30, func_021BFB38, func_021BFB54, func_021BFB60, func_021BFB74, func_021BFBA0, func_021BFBB8, func_021BFBC0, func_021BFBD0, func_021BFBDC, func_021BFBFC, func_021BFC28, func_021BFC50, func_021BFC60, func_021BFE40, func_021BFE80, func_021BFE8C, func_021BFED4, func_021BFEE4, func_021BFF00, func_021BFF5C, func_021BFF78
 * address:  0x021B95A0
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012204 0x02012204 thumb
 *   func_021C09FC 0x021C09FC thumb ov217
 *   func_0201058C  0x0201058C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020121CC  0x020121CC  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_021C09BC  0x021C09BC  thumb  ov217
 *   func_021C097C  0x021C097C  thumb  ov217
 *   func_021C099C  0x021C099C  thumb  ov217
 *   func_021C0DC4  0x021C0DC4  thumb  ov217
 *   func_021C0DE4  0x021C0DE4  thumb  ov217
 *   func_021C0DDC  0x021C0DDC  thumb  ov217
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040588  0x02040588  arm
 *   d_021C2E30     0x021C2E30  data  ov217  a4
 *   d_021C2E60     0x021C2E60  data  a4
 *   d_021C2E40     0x021C2E40  data  ov217  a4
 *   d_021C2E80     0x021C2E80  data  ov217  a4
 *   func_020490F4 0x020490F4 arm
 *   func_02049250 0x02049250 arm
 *   func_02062A98 0x02062A98 arm
 *   func_02040E78 0x02040E78 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02062A4C 0x02062A4C arm
 *   func_02040B1C 0x02040B1C arm
 *   func_02062B30 0x02062B30 arm
 *   func_02041090 0x02041090 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02049238 0x02049238 arm
 *   _u32_div_f  0x0209C2B0  arm
 *   sub_020490F4 0x020490F4 arm
 *   sub_020307B0 0x020307B0 arm
 *   sub_020409B4 0x020409B4 arm
 *   func_021C09AC  0x021C09AC  thumb  ov217
 *   func_021C09D0 0x021C09D0 thumb ov217
 *   func_0204A600 0x0204A600 arm
 *   func_020362DC 0x020362DC arm
 *   func_02035C08 0x02035C08 arm
 *   func_021C09B8 0x021C09B8 thumb ov217
 *   func_020061E4 0x020061E4 thumb
 *   func_021C09E0  0x021C09E0  thumb  ov217
 *   func_021C09EC  0x021C09EC  thumb  ov217
 *   func_021C0E4C  0x021C0E4C  thumb  ov217
 *   func_021C0E54  0x021C0E54  thumb  ov217
 *   func_021C0E64  0x021C0E64  thumb  ov217
 *   func_021C09C8  0x021C09C8  thumb  ov217
 *   func_021C09CC  0x021C09CC  thumb  ov217
 *   func_021C09C4  0x021C09C4  thumb  ov217
 *   GAME_BEACON_PopQuestionnaireUpdated  0x020270E0  thumb
 *   func_021C1038  0x021C1038  thumb  ov217
 *   func_021C09D8  0x021C09D8  thumb  ov217
 *   func_021C29F8  0x021C29F8  thumb  ov217
 *   d_021C3008  0x021C3008  data  a4
 *   d_021C3004  0x021C3004  data  a4
 *   func_021C2A00  0x021C2A00  thumb  ov217
 *   func_021C29F0  0x021C29F0  thumb  ov217
 *   func_021C09B4 0x021C09B4 thumb ov217
 *   func_0201296C 0x0201296C thumb
 *   func_020142E8 0x020142E8 thumb
 *   func_021C09F8  0x021C09F8  thumb  ov217
 *   func_0201D83C  0x0201D83C  thumb
 *   d_021C2ED8  0x021C2ED8  data  a4
 *   func_02045C04  0x02045C04  arm
 *   d_021C2EE0  0x021C2EE0  data  a4
 *   func_021C0E08  0x021C0E08  thumb  ov217
 *   func_021C0E3C  0x021C0E3C  thumb  ov217
 *   func_0207D63C 0x0207D63C arm
 *   func_02045088 0x02045088 arm
 *   d_021C2EEC 0x021C2EEC data a4
 *   d_021C2F78 0x021C2F78 data a4
 *   d_021C2F18 0x021C2F18 data a4
 *   d_021C2F38 0x021C2F38 data a4
 *   d_021C2F58 0x021C2F58 data a4
 *   func_02040DA8  0x02040DA8  arm
 *   func_021C0EF4 0x021C0EF4 thumb ov217
 *   func_021C0F5C 0x021C0F5C thumb ov217
 *   d_021C2F98 0x021C2F98 data a4
 *   func_021C0F48  0x021C0F48  thumb  ov217
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204AC18 0x0204AC18 arm
 *   d_021C2ED2  0x021C2ED2  data  a4
 *   d_021C2ED0  0x021C2ED0  data  a4
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   d_021C2EFC 0x021C2EFC data a4
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_021C29C8  0x021C29C8  thumb  ov217
 *   func_021C29D8  0x021C29D8  thumb  ov217
 *   func_021C29E8  0x021C29E8  thumb  ov217
 *   func_021C2A08  0x021C2A08  thumb  ov217
 *   d_021C2FF8  0x021C2FF8  data  a4
 *   func_0204A648  0x0204A648  arm
 *   func_02005654  0x02005654  thumb
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   func_0203630C 0x0203630C arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200E394 0x0200E394 thumb
 *   func_0200E44C 0x0200E44C thumb
 *   d_021C308A 0x021C308A data a1
 *   d_021C3080 0x021C3080 data a1
 *   d_021C30A8 0x021C30A8 data a1
 *   func_0200E440 0x0200E440 thumb
 *   BMP_OAM_SetPalette  0x02025A54  thumb
 *   _s32_div_f 0x0209C0A4 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0204162C 0x0204162C arm
 *   func_02041648  0x02041648  arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B92C 0x0204B92C arm
 *   d_021C309E 0x021C309E data a1
 *   d_021C3094 0x021C3094 data a1
 *   d_021C30D0 0x021C30D0 data a1
 *   func_021C0FF8  0x021C0FF8  thumb  ov217
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _ffix 0x0209C494 arm
 *   _dflt 0x0209B750 arm
 *   _dmul 0x0209B2E8 arm
 *   _dfix 0x0209C508 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_02040804  0x02040804  arm
 *   func_0209C0A4  0x0209C0A4  arm
 *   PALANM_GetFadeRequestBits  0x02021ED8  thumb
 *   d_021C326C 0x021C326C data a4
 *   d_021C3270 0x021C3270 data a4
 *   func_021C2A10  0x021C2A10  thumb  ov217
 *   func_021C0DF0 0x021C0DF0 thumb ov217
 *   func_021C0DF4 0x021C0DF4 thumb ov217
 *   func_021C0DF8 0x021C0DF8 thumb ov217
 *   func_021C0E04 0x021C0E04 thumb ov217
 *   func_021C0E00 0x021C0E00 thumb ov217
 *   func_021C0DFC 0x021C0DFC thumb ov217
 *   func_02025774  0x02025774  thumb
 *   d_021C3068  0x021C3068  data  ov217  a4
 *   func_02045B38 0x02045B38 arm
 *   d_021C3078 0x021C3078 data a4
 *   d_021C30B2 0x021C30B2 data a1 ov217
 *   d_021C3190 0x021C3190 data a4
 *   d_021C3070 0x021C3070 data a4 ov217
 *   d_021C30C0 0x021C30C0 data a4 ov217
 *   d_021C3110 0x021C3110 data a4 ov217
 *   d_021C3130 0x021C3130 data a4 ov217
 *   d_021C30F0 0x021C30F0 data a4 ov217
 *   d_021C3150 0x021C3150 data a4
 *   d_021C3170 0x021C3170 data a4 ov217
 *   d_021C33C8 0x021C33C8 data a4
 *   d_021C3520 0x021C3520 data a4
 *   func_0204B100 0x0204B100 arm
 *   d_021C305C 0x021C305C data a1
 *   d_021C3060 0x021C3060 data a2
 *   d_021C320C 0x021C320C data a4
 *   func_02043678 0x02043678 arm
 *   d_021C3470 0x021C3470 data a4
 *   func_0204384C 0x0204384C arm
 *   func_020439A0 0x020439A0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_020437AC 0x020437AC arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   d_021C3350 0x021C3350 data a4
 *   d_021C349C 0x021C349C data a4
 *   d_021C32D8 0x021C32D8 data a4
 *   d_021C34C8 0x021C34C8 data a4
 *   func_02025538  0x02025538  thumb
 *   func_02025588  0x02025588  thumb
 *   func_020255A0  0x020255A0  thumb
 *   func_020257D0  0x020257D0  thumb
 *   d_021C31BC 0x021C31BC data a4
 *   func_0202570C  0x0202570C  thumb
 *   func_02021540  0x02021540  thumb
 *   d_021C3260 0x021C3260 data a4
 *   func_020056A0  0x020056A0  thumb
 *   func_021C20C4  0x021C20C4  thumb  ov217
 *   func_021BFFC8  0x021BFFC8  thumb  ov217
 *   func_021C00AC  0x021C00AC  thumb  ov217
 *   func_021C00FC  0x021C00FC  thumb  ov217
 *   func_021C0124  0x021C0124  thumb  ov217
 *   func_021C0174  0x021C0174  thumb  ov217
 *   func_021C01B8  0x021C01B8  thumb  ov217
 *   func_021C0250  0x021C0250  thumb  ov217
 *   func_021C02C8  0x021C02C8  thumb  ov217
 *   func_021C03A0  0x021C03A0  thumb  ov217
 *   func_021C0408  0x021C0408  thumb  ov217
 *   func_021C04CC  0x021C04CC  thumb  ov217
 *   func_021C04FC  0x021C04FC  thumb  ov217
 *   func_021C05B0  0x021C05B0  thumb  ov217
 *   func_021C06C8  0x021C06C8  thumb  ov217
 *   func_021C06F0  0x021C06F0  thumb  ov217
 *   func_021C07BC  0x021C07BC  thumb  ov217
 *   func_021C083C  0x021C083C  thumb  ov217
 *   func_021C0878  0x021C0878  thumb  ov217
 *   func_021C08D4  0x021C08D4  thumb  ov217
 *   func_021C08C4  0x021C08C4  thumb  ov217
 *   func_021C0918 0x021C0918 thumb ov217
 *   func_021C093C 0x021C093C thumb ov217
 *   func_02006238  0x02006238  thumb
 *   func_021C1184  0x021C1184  thumb  ov217
 *   func_021C1154  0x021C1154  thumb  ov217
 *   func_021C1178 0x021C1178 thumb ov217
 *   func_021C0084  0x021C0084  thumb  ov217
 *   func_021C00F8  0x021C00F8  thumb  ov217
 *   func_021C0114  0x021C0114  thumb  ov217
 *   func_021C0170  0x021C0170  thumb  ov217
 *   func_021C018C  0x021C018C  thumb  ov217
 *   func_021C0230  0x021C0230  thumb  ov217
 *   func_021C02A8  0x021C02A8  thumb  ov217
 *   func_021C0358  0x021C0358  thumb  ov217
 *   func_021C03D0  0x021C03D0  thumb  ov217
 *   func_021C0494  0x021C0494  thumb  ov217
 *   func_021C06AC  0x021C06AC  thumb  ov217
 *   func_021C06E0  0x021C06E0  thumb  ov217
 *   func_021C0794  0x021C0794  thumb  ov217
 *   func_021C0800  0x021C0800  thumb  ov217
 *   func_021C085C  0x021C085C  thumb  ov217
 *   func_021C08A8  0x021C08A8  thumb  ov217
 *   func_021C08F0  0x021C08F0  thumb  ov217
 *   func_021C0968  0x021C0968  thumb  ov217
 *   func_021C116C  0x021C116C  thumb  ov217
 *   func_021C118C 0x021C118C thumb ov217
 *   func_021C1160 0x021C1160 thumb ov217
 *   func_0204E720  0x0204E720  arm
 *   d_021C3AC8     0x021C3AC8  data  a1
 *   func_021C11D0 0x021C11D0 thumb ov217
 *   func_021C26AC 0x021C26AC thumb ov217
 *   func_021C11C8 0x021C11C8 thumb ov217
 *   func_021C11A4 0x021C11A4 thumb ov217
 *   func_021C10E8 0x021C10E8 thumb ov217
 *   func_021C1124 0x021C1124 thumb ov217
 *   func_021C112C 0x021C112C thumb ov217
 *   func_021C2654 0x021C2654 thumb ov217
 *   func_021C2664 0x021C2664 thumb ov217
 *   func_021C2674 0x021C2674 thumb ov217
 *   func_021C20D8 0x021C20D8 thumb ov217
 *   func_021C11DC 0x021C11DC thumb ov217
 *   func_021C11FC 0x021C11FC thumb ov217
 *   func_021C20B4 0x021C20B4 thumb ov217
 *   func_021C20CC 0x021C20CC thumb ov217
 *   func_021C11E8 0x021C11E8 thumb ov217
 *   func_021C1224 0x021C1224 thumb ov217
 *   func_021C272C 0x021C272C thumb ov217
 *   func_021C271C 0x021C271C thumb ov217
 *   func_021C2740 0x021C2740 thumb ov217
 *   func_021C0900 0x021C0900 thumb ov217
 *   d_021C3628     0x021C3628  data   ov217  a4
 *   d_021C36B8 0x021C36B8 data a1
 *   d_021C369A 0x021C369A data a1
 *   func_021C0F78 0x021C0F78 thumb ov217
 *   func_020457B0 0x020457B0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F250 0x0201F250 thumb
 *   d_021C3850 0x021C3850 data a2
 *   CLACT_SetActorAnimLoopCount 0x0204B9C4 arm
 *   d_021C3A34 0x021C3A34 data a4
 *   PALANM_RequestFade 0x0202173C thumb
 *   func_021C09B0  0x021C09B0  thumb  ov217
 *   func_021C11F4  0x021C11F4  thumb  ov217
 *   d_021C363C 0x021C363C data ov217 a1
 *   d_021C3646 0x021C3646 data ov217 a1
 *   d_021C3632 0x021C3632 data ov217 a1
 *   func_0200E3A0 0x0200E3A0 thumb
 *   func_0200E3A4 0x0200E3A4 thumb
 *   func_021C2644 0x021C2644 thumb ov217
 *   func_02012FCC 0x02012FCC thumb
 *   func_0200864C 0x0200864C thumb
 *   func_0200E458  0x0200E458  thumb
 *   func_020056BC 0x020056BC thumb
 *   func_021C019C 0x021C019C thumb ov217
 *   func_021C0384 0x021C0384 thumb ov217
 *   func_021C03EC 0x021C03EC thumb ov217
 *   func_021C04B0 0x021C04B0 thumb ov217
 *   func_021C07B0 0x021C07B0 thumb ov217
 *   func_021C0820 0x021C0820 thumb ov217
 *   d_021C3650 0x021C3650 data a4
 *   func_0201ED04  0x0201ED04  thumb
 *   func_021C10C8 0x021C10C8 thumb ov217
 *   func_021C10D8 0x021C10D8 thumb ov217
 *   func_02082BCC  0x02082BCC  arm
 *   func_0200E47C 0x0200E47C thumb
 *   func_0200E4B0 0x0200E4B0 thumb
 *   func_0200E4F8 0x0200E4F8 thumb
 *   d_021C367C 0x021C367C data a1
 *   d_021C3D44 0x021C3D44 data a1
 *   d_021C386C 0x021C386C data a1
 *   d_021C3900 0x021C3900 data a1
 *   d_021C3994 0x021C3994 data a1
 *   d_021C3758 0x021C3758 data a1
 *   func_021C2070 0x021C2070 thumb ov217
 *   func_021C209C  0x021C209C  thumb  ov217
 *   func_021C26E8 0x021C26E8 thumb ov217
 *   func_021C270C  0x021C270C  thumb  ov217
 *   func_0207D988 0x0207D988 arm
 *   func_0207DB1C 0x0207DB1C arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   d_021C365C 0x021C365C data a4
 *   PALANM_TransferPalettes  0x02021D50  thumb  arm9
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm  arm9
 */
#include "../../matched/include/Obj10952.h"
#include "../../matched/include/Obj25801.h"
#include "../../matched/include/Obj25805.h"
#include "../../matched/include/Obj00801.h"
#include "../../matched/include/Obj25879.h"
#include "../../matched/include/Obj14733.h"
#include "../../matched/include/Obj14734.h"
#include "../../matched/include/Obj25887.h"
#include "../../matched/include/G_E.h"
#include "../../matched/include/Obj25933.h"
#include "../../matched/include/Obj25949.h"
#include "../../matched/include/G_Bg.h"

#define GB ((const struct G *)gb)
struct DispVram;
struct Obj0203159C;
struct S020315D4;
struct Ctx;
struct BigObj;
struct IcaAnime;
struct BgTemplate;
struct DispConfig;
struct ArcFile;
struct NitroFileHeader;
struct Context;
struct Ring;
struct Obj;
struct Actor;
struct GfFont;
struct MsgBank;
struct Rec;
struct Config;
struct Record;
struct Bank;
struct Big;
struct Vec2;
struct S02021D50;
struct Arc;
struct Bmp;
struct Obj020437AC;
struct Sys;
struct Grid;
struct PalAnmSlot;
struct Node;
struct W;
struct U16Vec;
struct WordSet;
struct PalAnmObj;
struct PlayTime;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef struct {
    u32 w[5];
    u32 a;
} Rec;

struct Desc {u8 a,b,c,d,e,f,g,h,i,j,k;unsigned data;};

struct Entry_021BA86C {struct Desc desc;unsigned mode,data;};

struct Context {void *owner;u16 heap,pad6;char gap8[0x54];int slots[6];};

struct Vec {short x,y,z;unsigned char a,b;};

struct Entry_021BAA48 {struct Vec vec;unsigned first,second,third,fourth;u16 arg,pad;};

struct Ent_021C2FF8 { u32 a; u32 b; u8 c; u8 pad[11]; };

struct ResearchTop {
    u32 f0;
    union { void * f4; u32 f4u; };
    u16 f8;
    u8 padA[0x2];
    union { u32 fC; void * fCp; };
    union {
        u32 arr[0x50];
        struct {
            u8 pad10[0x8];
            u32 f18;
            u32 f1C;
            u32 f20;
            u32 f24;
            u32 f28;
            u32 f2C;
            u8 f30;
            u8 f31;
            u8 f32;
            u8 pad33;
            int f34;
            u32 f38;
            u32 f3C;
            union { u32 f40; int f40s; };
            int f44;
            int f48;
            int f4C;
            u32 f50;
            u32 f54;
            u8 pad58[0x40];
            void * f98;
            u8 pad9C[0x18];
            void * fB4[8];
            u8 padD4[0x10];
            u32 fE4;
            u32 fE8;
            u32 fEC;
            u32 fF0;
            u32 fF4;
            int fF8;
            int fFC;
            int f100;
            int f104;
            int f108;
            int f10C;
            int f110;
            int f114[3];
            u8 pad120[0xC];
            u32 f12C;
            u8 pad130[0x10];
            void * f140[4];
        };
    };
    union { void * f150; u32 f150u; };
    u32 f154;
    u32 f158;
    u32 f15C;
    u32 f160;
    u32 f164;
    u32 f168;
};

struct ResearchObjB {
    union { void * f0; u32 f0u; };
    u16 f4;
    u8 pad6[0x2];
    u32 f8;
    void * fC;
    u8 pad10[0x4];
    void * f14;
    void * f18;
    u32 f1C;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2C;
    u32 f30;
    union { u32 f34; int f34s; };
    u8 f38;
    u8 pad39[0x27F];
    u8 f2B8;
    u8 f2B9;
    u8 pad2BA[0x2];
    void * f2BC;
    void * f2C0;
    void * f2C4;
    void * f2C8;
    u32 f2CC;
    void * f2D0;
    u8 pad2D4[0x28];
    u8 f2FC;
    u8 f2FD;
    u8 pad2FE[0x4A];
    int f348;
    u32 f34C;
    u32 f350;
    u32 f354;
    u32 f358;
    u32 f35C;
    u32 f360;
    u32 f364;
    u8 pad368[0x34];
    u32 f39C;
    void * f3A0;
    u8 pad3A4[0x8];
    u32 f3AC;
    u8 pad3B0[0x8];
    void * f3B8;
    union { void * f3BC; u32 f3BCu; };
    u8 pad3C0[0x4];
    void * f3C4;
    u32 f3C8;
    int f3CC;
    u32 f3D0;
    u32 f3D4;
    u32 f3D8;
    u32 f3DC;
    u32 f3E0;
    u32 f3E4;
};

struct ResearchObjC {
    union { void * f0; u32 f0u; };
    u16 f4;
    u8 pad6[0x2];
    u32 f8;
    u8 padC[0x8];
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
    u32 f28;
    u8 pad2C[0x28];
    u32 f54;
    u8 pad58[0x4];
    u32 f5C;
    u32 f60;
    u32 f64;
    u32 f68;
    u32 f6C;
    u32 f70;
    u8 pad74[0x8];
    void * f7C;
    u32 f80;
    u32 f84;
    u32 f88;
    u32 f8C;
};

struct ResearchProc {
    u16 f0;
    u8 pad2[0x2];
    union { void * f4; u32 f4u; };
    u32 f8;
    u32 fC;
    u32 f10;
    union { u32 f14; void * f14p; };
    u32 f18;
    u32 f1C;
};

typedef enum { INDEX_ZERO=0 } Index;

typedef enum { PLANE_NONE=0,PLANE_OUT=31,PLANE_IN=19 } Plane;

typedef enum { FALSE=0,TRUE=1 } Bool;

struct Vec2 { signed short x,y; };

typedef enum { ZERO = 0 } Origin;

typedef struct PalAnmObj PalAnmObj;

struct Ent_021BBF04 { unsigned int a; unsigned short b; unsigned short pad; unsigned int c[3]; };

struct Ent_021BCAE8 {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 b9;
    u8 b10;
    u8 pad;
    u32 idx;
    u32 arg;
    u32 w;
};

struct Loc {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 b9;
    u8 b10;
    u8 pad;
    u32 w;
};

struct Arg { s16 x,y,z; u8 a,b; };

struct Entry_021BBF04 { s16 x,y,z; u8 a,b; u32 c,d,e,f; u16 g,pad; };

struct Entry_021C3470 { int x, y, z; int bank; int index; int px; int py; u8 r, g, b, pad2; u32 arc, member, enabled; };

typedef signed short s16_021BD0C4;

typedef short s16_021BD178;

struct Tab { int v[3][10]; };

struct G {
    char pad0[0xc];
    u32 f0c;
    u32 f10;
    int f14;
    int f18;
    u8 f1c;
    u8 f1d;
    u8 f1e;
    u8 pad1f;
    u32 f20;
    u32 f24;
};

typedef signed short s16_021BD370;

struct Param { void *bmp; s16_021BD370 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };

struct Entry_021BD0C4 { s16_021BD370 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };

struct Entry021C3260 {
    int a;
    int b;
    unsigned char c;
    unsigned char pad[11];
};

typedef struct { unsigned short x, y; } Pos;

typedef struct E E;

struct Item { u8 id,pad[3]; u32 value; u8 x,y,z,a,b,c,pad2[2]; };

struct Input { u16 id; u8 x,y,z,pad; u16 a; u32 b; };

struct Row { u8 x,y,w,h; int fields[8]; };

typedef struct S { u32 a; u16 b; u8 pad[14]; } S;

typedef struct W { u32 w0; u16 h; u16 pad; u32 w8; u32 obj[3]; } W;

struct Entry { u8 a, b, c, d; };

struct Params_021BFE8C { u32 handles[3]; u16 a, b, c, d, e; };

struct Params_021BFF00 { u32 handles[3]; u16 a, b, c; };

extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32 swap);
extern void func_020315D4(struct S020315D4 *);
extern u32 func_02012204(const struct Ctx *);
extern void func_021C09FC(void *);
extern u32 func_0201058C(void *key);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_020121CC(struct IcaAnime *p);
extern u32 func_0201283C(const struct BigObj *p);
extern void func_0203D34C(u32 a, u32 b);
extern void func_021C09BC(void *p, u32 v);
extern int func_021C097C(int a0, int a1);
extern u32 func_021C099C(void *a0);
extern u32 func_021C0DC4(u32 a0);
extern void func_021C0DE4(void *p);
extern void func_021C0DDC(void *a0);
extern void func_0203F8F4(unsigned short heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(unsigned char which, unsigned char enable);
extern u32 func_0203F9B4();
extern u32 func_020403F4(u32 i);
extern void *func_020490F4(unsigned int id, u32 heap);
extern void *func_02049250(struct ArcFile *, u32, u32);
extern int func_02062A98(struct NitroFileHeader *, void **);
extern void func_02040E78(u32, void *, u32, u32);
extern u32 func_020307B0(void *p);
extern int func_02062A4C(struct NitroFileHeader *, void **);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern int func_02062B30(void *, void **);
extern void func_02041090(u32, u32, u32, u32, u8, u8);
extern int func_020409B4(int);
extern void func_02049238(void *);
extern void func_020413B0(int index, int x0, int y0, int w, int h, int pal);
extern void *sub_020490F4(u32 id, u32 heap);
extern u32 sub_020307B0(void *p);
extern void sub_020409B4(u32);
extern u32 func_021C09AC(void *);
extern void func_021C09D0(unsigned);
extern void func_0204A600();
extern u32 func_020362DC(void);
extern int func_02035C08(const void *);
extern void * func_021C09B8(void *);
extern u32 func_020061E4(u32 a);
extern int func_0204E804(void);
extern void func_021C09E0(u32 a0);
extern void func_021C09EC(u32 a0);
extern void func_021C0E4C(u32, u32);
extern u32 func_021C0E54(struct Ring *r);
extern u32 func_021C0E64();
extern u32 func_021C09C8(void *p);
extern u32 func_021C09CC(void *p);
extern void func_021C09C4(u8 *p, u32 v);
extern u8 GAME_BEACON_PopQuestionnaireUpdated(void);
extern void func_021C1038(u8 *p, u8 palette);
extern void func_021C09D8(u8 *p, u32 i);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern u32 CLACT_SetActorAnimFrame();
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern void func_0204B954(struct Actor *a, u32 v);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern void func_021C29F8(u8 *p, u32 b, u16 c);
extern void func_021C2A00(u32 a0);
extern void func_021C29F0(int);
extern unsigned func_021C09B4(void *);
extern u32 func_0201296C(const struct BigObj *p);
extern unsigned func_020142E8(void *,int);
extern u32 func_021C09F8(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201D83C(void *ptr);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern int func_021C0E08(int a0, int a1);
extern void func_021C0E3C(void *p);
extern void func_0207D63C(volatile unsigned *,unsigned,unsigned,unsigned,unsigned);
extern void func_02045088(u16);
extern void func_020450C8(void);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern u32 func_020414EC();
extern void func_02040DA8(u32, u32, u32);
extern struct Record *func_021C0EF4(const struct Config *config, u32 a, u32 b, u32 heap);
extern unsigned func_021C0F5C(unsigned,unsigned);
extern void func_021C0F48(u8 *p);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0204A8D4(u32 i);
extern u32 func_0204ADA4(u32 i);
extern u32 func_0204AFD8();
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern u32 func_0204B1CC(struct Bank *bank);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_021C29C8(u32 a0);
extern u32 func_021C29D8(void *a0);
extern void func_021C29E8(void *p, u32 b, u32 c, u32 d);
extern int func_021C2A08(char *p);
extern void func_0204A648(void);
extern int func_02005654(int a, int b);
extern void func_0200566C(void);
extern int TOUCHPANEL_HitCont(const void *p);
extern u32 TOUCHPANEL_GetPointCont(u32 *,u32 *);
extern u32 func_0203630C(void);
extern void *func_02012EBC(struct Big *);
extern void *func_0200E394(void *a0);
extern int func_0200E44C(int p0, int p1);
extern void func_0200E440(u8 *p, int value, int index);
extern void BMP_OAM_SetPalette(u8 *g, u32 a);
extern int _s32_div_f(int, int);
extern void func_02041B6C(u32 layer);
extern u32 func_0204162C(int channel);
extern u32 func_02041648(u8 channel);
extern void func_0204B404(struct Obj *p,const struct Vec2 *delta,u32 which);
extern void func_021C0FF8(u8 *p, int visible);
extern void func_02041EE4(unsigned layer,unsigned mode,unsigned value);
extern u32 func_02040804(u32 layer);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern u32 func_0209C0A4(u32, u32);
extern int PALANM_RequestFade(PalAnmObj *, u16, u16, s16, u8, u8, u16, void *);
extern u32 PALANM_GetFadeRequestBits(const char *ptr);
extern u32 func_021C2A10();
extern u32 PALANM_TransferPalettes(struct S02021D50 *p);
extern u32 func_020419E4();
extern u32 func_021C0DF0(void *p);
extern u32 func_021C0DF4(void *p);
extern u32 func_021C0DF8(void *p);
extern void func_021C0E04(void *, u32);
extern void func_021C0E00(void *, u32);
extern void func_021C0DFC(void *, u8);
extern void func_02025774(u8 *g, u32 a);
extern u32 func_020056BC(void);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct Bmp *func_0204384C(u32,u32,u32,u32);
extern void func_020439A0(struct Bmp *,struct Bmp *,u32,u32,int,int,u32,u32,u32);
extern void *func_02045EC0(struct MsgBank *,u32);
extern void func_0201C7D0(void *,s16_021BD0C4,s16_021BD0C4,void *,void *,u16);
extern void func_020437AC(struct Obj020437AC *p);
extern void *func_02025538(unsigned int a0, void *a1);
extern void func_02025588(void *p);
extern struct Grid *func_020255A0(struct Sys *,const struct Param *);
extern void func_020257D0(struct Obj *);
extern void func_0202570C(struct Grid *g);
extern void *func_02021518(u32);
extern void func_0202155C(struct PalAnmSlot *, u32, u32, u32);
extern void func_020216D4(struct PalAnmSlot *, u32, u32, u32);
extern u32 func_02021540(void *a0);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern int func_020056A0(void (*)(void), void *, int);
extern void func_02030EAC(struct Node *n);
extern void func_021C20C4(void *h);
extern void func_021BFFC8(char *p);
extern void func_021C00AC(char *p);
extern void func_021C00FC(void *p);
extern void func_021C0124(char *p);
extern void func_021C0174(void *p);
extern void func_021C01B8(char *p);
extern void func_021C0250(char *p);
extern void func_021C02C8(char *p);
extern void func_021C03A0(u8 *p);
extern void func_021C0408(u8 *p);
extern void func_021C04CC(u8 *p);
extern void func_021C04FC(u8 *p);
extern void func_021C05B0(u8 *p);
extern void func_021C06C8(u8 *p);
extern void func_021C06F0(u8 *p);
extern void func_021C07BC(u8 *p);
extern void func_021C083C(u8 *p);
extern void func_021C0878(u8 *p);
extern void func_021C08D4(char *p);
extern void func_021C08C4(u32 a0);
extern void func_021C0918(u8 *a0);
extern int func_021C093C(u8 *a0);
extern int func_02006238(void);
extern void func_021C1184(u8 *h, u32 v);
extern void func_021C1154(u8 *h);
extern void func_021C1178(u8 *h);
extern u32 func_021C0084();
extern u32 func_021C00F8();
extern u32 func_021C0114();
extern u32 func_021C0170();
extern u32 func_021C018C();
extern void func_021C0230(int *p);
extern u32 func_021C02A8(u32 a0);
extern u32 func_021C0358(u32 a0);
extern void func_021C03D0(int *p);
extern void func_021C0494(int *p);
extern void func_021C06AC(int *p);
extern void func_021C06E0(u8 *a0);
extern void func_021C0794(int *p);
extern u32 func_021C0800(u32 a0);
extern void func_021C085C(int *p);
extern void func_021C08A8(int *);
extern void func_021C08F0(u8 *a0);
extern void func_021C0968(unsigned char *a0);
extern void func_021C116C(u8 *h);
extern void func_021C118C(u8 *h, u32 v);
extern void func_021C1160(u8 *h);
extern u8 func_021C11D0(u8 *p, u8 n);
extern u32 func_021C26AC(const u8 *p, u8 unused, u8 key);
extern u8 func_021C11C8(u8 *p, u8 key);
extern void func_021C11A4(u8 *p, int a1);
extern void func_021C10E8(u8 *p, u8 *tab, int n);
extern void func_021C1124(u8 *p);
extern void func_021C112C(u8 *p);
extern unsigned func_021C2654(void *,unsigned,unsigned);
extern unsigned func_021C2664(void *,unsigned,unsigned);
extern unsigned func_021C2674(void *,unsigned,unsigned);
extern unsigned func_021C20D8(unsigned);
extern u8 func_021C11DC(u8 *p, u8 key);
extern void func_021C11FC(u8 *h, u8 key, s32 *px, s32 *py);
extern void func_021C20B4(int a0, int a1, int a2, int a3, int a4);
extern void func_021C20CC(unsigned);
extern u8 func_021C11E8(u8 *p, u8 n);
extern void func_021C1224(u8 *h, u8 n, s32 *px, s32 *py);
extern unsigned func_021C272C(unsigned,unsigned);
extern unsigned func_021C271C(unsigned,unsigned,unsigned);
extern void func_021C2740(u32 a, u32 b);
extern unsigned func_021C0900(int);
extern void func_021C0F78(u8 *p, struct U16Vec *text);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void CLACT_SetActorAnimLoopCount(struct Actor *,unsigned);
extern u32 func_021C09B0(u32 *p);
extern int func_021C11F4(u8 *p);
extern void *func_0200E3A0(void *a);
extern u32 func_0200E3A4(const u8 *, int);
extern u32 func_021C2644(void *, u32, u8);
extern int func_02012FCC(int);
extern u16 func_0200864C(const struct PlayTime *p);
extern u16 func_0200E458(const u16 *, int);
extern void func_021C019C(void *p);
extern void func_021C0384(void *p);
extern void func_021C03EC(void *p);
extern void func_021C04B0(void *p);
extern void func_021C07B0(void *p);
extern void func_021C0820(void *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_021C10C8(u32 a0);
extern u32 func_021C10D8(void *a0);
extern void func_02082BCC(u32, u32, u32);
extern u32 func_0200E47C(u8 *p, int i);
extern u32 func_0200E4B0(u8 *a0, u32 a1, u32 a2);
extern int func_0200E4F8(int a0, int a1, int a2);
extern u32 func_021C2070(u32, u32);
extern u32 func_021C209C(void *a0);
extern u32 func_021C26E8(u32, u32, u32);
extern u32 func_021C270C(void *a0);
extern void func_0207D988(void);
extern void func_0207DB1C(void);
extern void func_0207DCF8(const void *);
u32 func_021B95A0(u32 a0, u32 a1, u8 *a2, u32 a3);
u32 func_021B9600(u32 a0, u32 a1, u32 a2, u32 a3);
int func_021B9620(void *unused, u32 *state, u32 unused2, u32 *p);
void func_021B96A0(u32 a0);
void func_021B96C8(void *a, int *p, int c);
void func_021B970C(u32 *p, u32 *state);
void func_021B9774(u32 *p, u32 *state, u32 kind);
int func_021B97B8(void *a0);
u32 func_021B97BC(u8 *a0);
u32 func_021B97F8(u32 a0);
u32 func_021B9824(u32 a0);
u32 func_021B9850(const void *p);
void func_021B9854(void *p);
void func_021B985C(void *p, u32 value);
void func_021B9874(u32 a0);
u32 func_021B9884(u32 a0);
void func_021B9894(u32 a0);
u32 func_021B98A8(u32 a0);
void func_021B98B8(unsigned short heapId);
u32 func_021B990C(void);
void func_021B9920(u32 heap);
void func_021B99EC(const void *p);
void func_021B9A24(u32 heap);
u32 func_021B9AD0(void *self);
u32 func_021B9AF8(void *a0);
void func_021B9B08(char *p);
int func_021B9B80(void *p);
u32 func_021B9B90(void *p);
void func_021B9B98(char *p);
void func_021B9C54(char *p);
void func_021B9E44(char *p);
void func_021BA078(u32 a0);
void func_021BA094(u32 a0);
void func_021BA0C4(u32 a0);
void func_021BA144(u8 *a0, u32 a1);
void func_021BA150(void *p);
void func_021BA158(u32 a0);
void func_021BA180(void *p, u32 v);
u32 func_021BA190(void *p);
void func_021BA194(void *p);
u32 func_021BA19C(u8 *a0);
void func_021BA1C0(u8 *a0, u32 a1);
void func_021BA1CC(void *p, u32 v);
void func_021BA1D4(u32 a0);
void func_021BA1F8(u32 a0);
void func_021BA228(u32 a0);
void func_021BA254(u32 a0, u32 a1);
void func_021BA284(int sel);
void func_021BA2BC(int sel);
void func_021BA2FC(u32 a0);
void func_021BA31C(u8 *a0);
u32 func_021BA328(u32 a0);
void func_021BA354(void);
void func_021BA364(void);
void func_021BA374(void *p);
u32 func_021BA37C(void *p);
void func_021BA380(void *p, u32 v);
u32 func_021BA384(void *p);
void func_021BA388(char *self, int d);
void func_021BA3B0(void *p, u32 v);
u32 func_021BA3B4(u32 a0, u32 a1);
u32 func_021BA3D0(void *p, u32 i);
u32 func_021BA3D8(void *p, u32 i);
u32 func_021BA3E0(void *p, u32 i);
void func_021BA3E8(char *self, int i);
void func_021BA40C(u8 *a0, u32 a1);
void func_021BA41C(int *p);
unsigned char func_021BA434(char *p);
u32 func_021BA4C8(void *p);
void func_021BA4CC(void *p, u32 v);
void func_021BA4D0(void *p, u32 v);
u32 func_021BA4D4(void *p);
u32 func_021BA4E0(u32 a0);
u32 func_021BA4FC(void *a0);
void func_021BA504(char *p);
void func_021BA560(char *p);
void func_021BA5B4(void *p);
void func_021BA5BC(u32 a0);
void func_021BA5D8(u8 *a0);
void func_021BA5E4(void *p);
void func_021BA5F8(char *self);
void func_021BA624(int *p);
void func_021BA63C(u8 *self);
void func_021BA674(void *p);
void func_021BA67C(u32 a0);
void func_021BA68C(Rec *p);
void func_021BA698(char *p);
void func_021BA748(u32 a0);
void func_021BA768(char *p);
void func_021BA7B4(u32 a0);
u32 func_021BA7B8(void *a0);
void func_021BA7D0(u32 a0);
void func_021BA7E0(char *p);
void func_021BA82C(u32 a0);
u32 func_021BA830(void *a0);
void func_021BA848(u32 a0);
void func_021BA858(void *p);
void func_021BA86C(char *p);
void func_021BA8E0(int *p);
void func_021BA8FC(void *p);
void func_021BA910(struct Context *p);
u32 func_021BA960(u32 a0);
void func_021BA978(struct Context *p);
u32 func_021BA9D0(u32 a0);
void func_021BA9E8(void *p);
void func_021BA9FC(char *self);
void func_021BAA28(int *p);
void func_021BAA40(void *p);
void func_021BAA48(char *p);
void func_021BAAB8(u8 *a0);
void func_021BAAC4(void *p);
void func_021BAAD8(char *p);
void func_021BAAF4(int *p);
void func_021BAB0C(char *self);
void func_021BAB38(char *self);
void func_021BAB50(void);
void func_021BAB58(void *a0);
void func_021BAB68(void);
void func_021BAB70(u32 a0);
u32 func_021BAB80(u32 a0, u32 a1);
u32 func_021BABB4(void *a0);
void func_021BABC4(void *self);
u32 func_021BAC90(void *p);
u32 func_021BAC98(void *p);
void func_021BACA0(u8 *p);
void func_021BAE00(u8 *p);
void func_021BAF70(char *p);
void func_021BB190(u8 *p);
void func_021BB200(struct ResearchTop *p);
void func_021BB2B4(char *p);
void func_021BB37C(char *p);
void func_021BB484(u8 *p);
void func_021BB534(u8 *p);
void func_021BB5F4(u8 *p);
void func_021BB69C(u8 *p);
void func_021BB710(u8 *p);
void func_021BB784(struct ResearchTop *p);
void func_021BB84C(u8 *p);
void func_021BB908(void *p);
void func_021BB910(u8 *a0, u32 a1);
void func_021BB91C(void *p);
u32 func_021BB928(u8 *a0);
void func_021BB934(u8 *a0, u32 a1);
void func_021BB940(void *p, u32 v);
u32 func_021BB948(u8 *a0);
void func_021BB94C(u32 a0);
u32 func_021BB974(void *p);
int func_021BB978(char *p, int a1);
u32 func_021BB98C(void *p);
void func_021BB990(void *p);
void *func_021BB998(void *p);
void func_021BB9A0(u32 a0);
void func_021BB9D0(u32 a0);
void func_021BBA00(u32 a0, u32 a1);
void func_021BBA30(u8 *p);
void func_021BBAA4(u32 a0, u8 a1);
void func_021BBAD0(u32 a0);
void func_021BBADC(u8 *p);
void func_021BBB60(u8 *p);
void func_021BBBE4(u8 *p);
u8 func_021BBC50(u8 *p);
void func_021BBCB0(u8 *p);
void func_021BBCFC(void *p, s32 v);
void func_021BBD14(void *p, u32 v);
void func_021BBD18(int a, int b);
void func_021BBD28(int a, int b);
void func_021BBD38(void *p, u8 v);
void func_021BBD40(u8 *p, int a);
void func_021BBD68(u8 *p);
void func_021BBDAC(u8 *p);
void func_021BBDF0(u32 object,u32 slot);
void func_021BBE7C(u32 object,u32 slot);
u32 func_021BBF04(u32 a0, u32 a1);
u32 func_021BBF1C(u32 unused, u32 v);
int func_021BBF28(unsigned char *p, unsigned int slot);
int func_021BBF3C(unsigned char *p, unsigned char index);
int func_021BBF4C(unsigned char *p, unsigned int index);
void func_021BBF60(u8 *p);
void func_021BC014(u8 *p);
int func_021BC06C(char *p);
int func_021BC07C(u8 *p, u8 index);
void func_021BC0E8(u32 a0);
void func_021BC128(u32 a0);
void func_021BC168(u32 a0);
int func_021BC1AC(void *p);
int func_021BC200(void *p,int position);
void func_021BC250(void *p);
int func_021BC264(void *p);
void func_021BC274(void *p);
void func_021BC280(struct ResearchTop *p);
void func_021BC2B8(void *p);
void func_021BC2CC(void *p, u32 a, u32 b, u32 c);
void func_021BC2D8(struct ResearchTop *p);
int func_021BC2FC(void *p);
void func_021BC30C(struct ResearchTop *p, int v);
void func_021BC330(void *p, u32 v);
void func_021BC338(u8 *p);
void func_021BC380(struct ResearchTop *p);
int func_021BC3AC(void);
void func_021BC3B8(u32 a0);
u32 func_021BC3D4(void);
u32 func_021BC3E0(void);
int func_021BC3EC(u32 a0);
u32 func_021BC3F8(u32 v);
u32 func_021BC400(u32 v);
int func_021BC40C(void *p);
u32 func_021BC41C(void *p);
int func_021BC428(void *p);
void func_021BC43C(u8 *p);
void func_021BC480(void);
void func_021BC490(void);
int func_021BC4A0(void);
void func_021BC4B4(char *p);
void func_021BC50C(char *p);
u32 func_021BC55C(u32 a0);
void func_021BC574(u8 **p, u32 i);
void func_021BC580(char *p, int i);
void func_021BC5A8(u8 *a0, int a1);
u32 func_021BC5B8(u32 a0, u32 a1);
void func_021BC5D4(int *p);
void func_021BC5F0(u8 *a0);
u32 func_021BC5FC(void *p);
void func_021BC600(void *p);
void func_021BC608(void *p);
void func_021BC610(u32 a0, u32 a1);
u32 func_021BC628(u8 *a0);
void func_021BC634(void *p, u32 v);
void func_021BC638(void *p, u32 v);
u32 func_021BC63C(void *p);
void func_021BC640(void *p, u32 v);
void func_021BC644(struct ResearchTop *p);
void func_021BC688(char *p);
u32 func_021BC6D0(void *p);
u32 func_021BC6DC(void *p);
u32 func_021BC6E4(void *p);
void func_021BC6EC(void *p, u8 v);
u32 func_021BC6F4(u32 a0, u32 a1);
u32 func_021BC708(void *p, u32 i);
u32 func_021BC714(void *p, u32 i);
u32 func_021BC720(void *p, u32 i);
void func_021BC72C(u8 *a0, u32 a1, u8 *a2);
int func_021BC740(char *p, int i);
u32 func_021BC758(u32 a0);
void func_021BC774(u8 *p);
u32 func_021BC818(void *a0);
void func_021BC820(u8 *p);
void func_021BC8B4(u32 a0);
void func_021BC8D0(void *p);
void func_021BC8D8(u8 *a0);
void func_021BC8E4(struct ResearchTop *p);
void func_021BC910(void *p);
void func_021BC924(int *p);
void func_021BC93C(u32 a0);
void func_021BC94C(void *p);
void func_021BC954(u8 *a0);
void func_021BC960(u8 *p);
void func_021BC9FC(char *p);
u32 func_021BCAC0(u8 *a0);
void func_021BCAE8(char *p);
void func_021BCB44(u8 *a0);
u32 func_021BCB48(u32 a0);
void func_021BCB60(u32 a0);
void func_021BCB70(char *p);
void func_021BCBCC(u8 *a0);
void func_021BCBD0(struct ResearchTop *p);
void func_021BCC3C(u8 *a0);
u32 func_021BCC40(u32 a0);
void func_021BCC58(u32 a0);
void func_021BCC68(struct ResearchTop *p);
void func_021BCD6C(void *p);
void func_021BCD90(u8 *p);
void func_021BCDDC(void *p);
void func_021BCDF0(char *p);
u32 func_021BCE5C(u32 a0);
void func_021BCE7C(char *p);
u32 func_021BCF20(u32 a0);
void func_021BCF4C(void *p);
void func_021BCF68(struct ResearchTop *p);
void func_021BCF98(int *p);
void func_021BCFB4(void *p);
void func_021BCFD0(u8 *p);
void func_021BD05C(int *p);
void func_021BD078(void *p);
void func_021BD094(struct ResearchTop *p);
void func_021BD0C4(u8 *p);
void func_021BD178(struct ResearchTop *p);
void func_021BD274(struct ResearchTop *p);
void func_021BD370(int *p);
void func_021BD38C(char *p);
void func_021BD3A4(u8 *a0);
void func_021BD3B4(u8 *p);
void func_021BD458(int *p);
void func_021BD474(void *p);
void func_021BD47C(u8 *p);
u32 func_021BD4CC(u32 a0);
void func_021BD4F0(char *p);
void func_021BD50C(void *p);
void func_021BD520(int *p);
void func_021BD53C(int *p);
void func_021BD56C(int *p);
void func_021BD588(void *p);
void func_021BD5B4(u32 a0);
void func_021BD5C4(char *p);
void func_021BD5E0(u32 a0);
void *func_021BD5F4(void *p);
u32 func_021BD61C(void *a0);
void func_021BD62C(unsigned char *p);
u32 func_021BD708(void *p);
u32 func_021BD710(void *p);
void func_021BD718(unsigned char *p);
void func_021BD868(u32 a0);
void func_021BD89C(u8 *p);
void func_021BDC18(u8 *p);
void func_021BDF58(u8 *p);
void func_021BE040(u8 *p);
void func_021BE094(u32 a0);
void func_021BE0D0(u32 a0);
void func_021BE108(char *p);
void func_021BE21C(char *p);
void func_021BE33C(u32 a0);
void func_021BE36C(u32 a0);
void func_021BE384(u8 *a0);
void func_021BE448(void *p);
void func_021BE454(u8 *a0, u32 a1);
void func_021BE460(void *p, u32 v);
u32 func_021BE468(void *p);
u32 func_021BE46C(u8 *a0);
void func_021BE490(void *p);
void func_021BE498(u8 *a0, u32 a1);
void func_021BE4A4(u32 a0);
void func_021BE4CC(void *p, u32 v);
u32 func_021BE4DC(void *p);
void func_021BE4E0(void *p);
void func_021BE4E8(u8 *p);
void func_021BE580(u8 *p);
u32 func_021BE614(u32 a0, u32 a1);
void func_021BE630(u8 *a0, u32 a1);
void func_021BE678(char *p);
void func_021BE704(char *p);
u32 func_021BE790(u32 a0);
u32 func_021BE7B4(u32 a0);
void func_021BE7D8(char *p);
void func_021BE7F0(char *p);
void func_021BE808(char *p);
void func_021BE8FC(void);
void func_021BE90C(void);
void func_021BE91C(char *p, int a);
void func_021BE930(void *p, u32 v);
int func_021BE934(char *p);
void func_021BE9B8(u8 *p);
void func_021BEA3C(char *p, int a);
void func_021BEA54(char *p);
void func_021BEA8C(u8 *p, int step);
void func_021BEAEC(u8 *a0);
void func_021BEAF8(u8 *p);
void func_021BEB40(u32 a0);
void func_021BEB6C(u32 a0);
void func_021BEB88(u32 a0);
void func_021BEBA4(u32 a0);
void func_021BEBC0(u32 a0);
void func_021BEBE4(u32 a0);
void func_021BEC00(u32 *p);
void func_021BEC0C(void *p);
void func_021BEC34(u32 a0);
void func_021BEC64(void *p);
void func_021BEC84(u8 *p,int mode);
void func_021BED10(u8 *p, u32 mode);
void func_021BED9C(char *p);
void func_021BEDC4(char *p);
void func_021BEDEC(char *p);
void func_021BEEA4(char *p);
void func_021BEF30(char *p);
void func_021BEF98(char *p);
void func_021BEFC0(u8 *a0, u32 a1);
void func_021BEFD4(char *p);
void func_021BEFF8(u8 *p);
void func_021BF08C(char *p);
void func_021BF100(char *p);
void func_021BF11C(char *p);
void func_021BF13C(char *p);
void func_021BF15C(char *p);
void func_021BF264(char *p);
void func_021BF2FC(char *p);
void func_021BF38C(char *p);
void func_021BF3B4(char *p);
void func_021BF3D8(char *p);
void func_021BF47C(char *p);
void func_021BF4AC(char *p);
void func_021BF55C(void *a0);
void func_021BF568(void *a0);
void func_021BF574(void *a0);
void func_021BF580(u8 *p, u32 i, u32 j);
void func_021BF594(char *p, int i);
void func_021BF5BC(u8 *a0, u32 a1);
u32 func_021BF5D0(u8 *a0, u32 a1);
void func_021BF5E4(int *p);
void func_021BF600(u8 *a0);
void func_021BF60C(char *p);
void func_021BF658(char *p);
u32 func_021BF6A4(u8 *a0);
u32 func_021BF6BC(u32 a0, u32 a1);
void func_021BF6D4(char *p);
void func_021BF704(void *p);
void func_021BF710(void *p);
void func_021BF728(void *p);
u32 func_021BF734(u8 *a0);
u32 func_021BF740(u8 *a0);
void func_021BF74C(void *p, u32 v);
u32 func_021BF750(void *p);
void func_021BF754(void *p, u32 v);
u32 func_021BF758(void *p);
void func_021BF764(void *p, u32 v);
u8 *func_021BF76C(void *p);
u8 *func_021BF77C(void *p);
u32 func_021BF78C(u32 a0);
u32 func_021BF7CC(void *p);
u32 func_021BF7E0(void *p);
u32 func_021BF7F4(void *p);
u32 func_021BF810(void *p);
u32 func_021BF834(void *p);
u32 func_021BF844(void *p);
u32 func_021BF854(char *p);
u32 func_021BF878(void *p);
u32 func_021BF894(void *p);
u8 func_021BF8B0(u8 *p);
u32 func_021BF910(u8 *p);
u32 func_021BF968(u8 *p);
u16 func_021BF9CC(u32 a0);
u32 func_021BF9F0(void *p, u32 i);
u32 func_021BF9FC(void *p, u32 i);
u32 func_021BFA08(void *p, u32 i);
u32 func_021BFA14(u32 a0);
void func_021BFA30(char *p);
u32 func_021BFB04(void *a0);
void func_021BFB0C(void *p);
void func_021BFB14(u32 a0);
void func_021BFB24(u8 *a0);
void func_021BFB30(void *p);
void func_021BFB38(u32 a0);
void func_021BFB54(u8 *a0);
void func_021BFB60(void *p);
void func_021BFB74(W *p);
void func_021BFBA0(int *p);
void func_021BFBB8(void *p);
void func_021BFBC0(u32 a0);
void func_021BFBD0(u8 *a0);
void func_021BFBDC(void *p);
void func_021BFBFC(char *p);
void func_021BFC28(char *p);
void func_021BFC50(u8 *a0);
void func_021BFC60(char *p);
void func_021BFE40(u8 *p);
void func_021BFE80(void *p);
void func_021BFE8C(char *p);
void func_021BFED4(u8 *a0);
void func_021BFEE4(void *p);
void func_021BFF00(char *p);
void func_021BFF5C(int *p);
void func_021BFF78(void);
extern int d_021C2E30;
extern int d_021C2E60;
extern int d_021C2E40;
extern int d_021C2E80;
extern u8 d_021C3008[];
extern u8 d_021C3004[];
extern u32 d_021C2ED8[];
extern u8 d_021C2EE0[];
extern struct DispConfig d_021C2EEC;
extern const struct BgTemplate d_021C2F78,d_021C2F18,d_021C2F38,d_021C2F58;
extern const struct Entry_021BA86C d_021C2F98[];
extern u16 d_021C2ED2[];
extern u8 d_021C2ED0[];
extern const struct Entry_021BAA48 d_021C2EFC;
extern struct Ent_021C2FF8 d_021C2FF8[];
extern const u8 d_021C308A[];
extern const u8 d_021C3080[];
extern const u8 d_021C30A8[];
extern const u8 d_021C309E[];
extern const u8 d_021C3094[];
extern const u8 d_021C30D0[];
extern const struct Ent_021BBF04 d_021C326C[];
extern int d_021C3068[];
extern const unsigned int d_021C3078[];
extern const u8 d_021C30B2[];
extern const u8 d_021C3190[];
extern const u8 d_021C3070[];
extern struct DispConfig d_021C30C0;
extern const struct BgTemplate d_021C3110, d_021C3130, d_021C30F0, d_021C3150, d_021C3170;
extern const struct Ent_021BCAE8 d_021C33C8[];
extern const struct Ent_021BCAE8 d_021C3520[];
extern const u8 d_021C305C[];
extern const u16 d_021C3060[];
extern const struct Entry_021BBF04 d_021C320C[];
extern const struct Entry_021C3470 d_021C3470[];
extern const struct Tab d_021C3350;
extern const struct G d_021C349C;
extern const struct Tab d_021C32D8;
extern const struct G d_021C34C8;
extern const struct Entry_021BD0C4 d_021C31BC[];
extern const struct Entry021C3260 d_021C3260[];
extern struct E d_021C3AC8[];
extern unsigned char d_021C3628[];
extern u8 d_021C36B8[];
extern u8 d_021C369A[];
extern const u16 d_021C3850[];
extern S d_021C3A34[];
extern const u8 d_021C363C[];
extern const u8 d_021C3646[];
extern const u8 d_021C3632[];
extern u32 d_021C3650[];
extern u8 d_021C367C[];
extern u8 d_021C3D44[][17];
extern struct Bg d_021C386C;
extern u8 d_021C3900[];
extern u8 d_021C3994[];
extern const struct Entry d_021C3758[];
extern const u16 d_021C365C[];








u32 func_021B95A0(u32 a0, u32 a1, u8 *a2, u32 a3)
{
    switch (((struct Obj10952 *)((u8*)a1))->f0) {
    case 0:
    func_0203159C((struct Obj0203159C *)a0, 32, 1);
    ((struct Obj10952 *)((u8*)a1))->f0 = (u32)(((struct Obj10952 *)((u8*)a1))->f0 + 1);
    break;
    case 1:
    func_021B985C((void *)a3, ((struct Obj25801 *)((u8*)a2))->f0);
    func_020433E0((const struct DispVram *)0x21C2EA0);
    func_0204363C(0);
    func_021B98B8(((struct ResearchProc *)a3)->f0);
    func_021B9A24(((struct ResearchProc *)a3)->f0);
    func_021B9920(((struct ResearchProc *)a3)->f0);
    func_021B9874(a3);
    func_021B9894(a3);
    return 1;
    }
    return 0;
}








u32 func_021B9600(u32 a0, u32 a1, u32 a2, u32 a3)
{
    func_021B98A8(a3);
    func_021B9884(a3);
    func_021B990C();
    func_020315D4((struct S020315D4 *)a0);
    return 1;
}








/*
 * tail: zero halfword alignment at 021B969E.
 * state domain: procsys 020315F0 resets subseq to 0 before this main callback;
 *   97B8 returns 1, 97BC returns 1..4, 97F8 returns 1/2/4, 9824 returns 1/3/4.
 *   96C8/9774 stores only those new states; state 4 exits immediately.
 *   Full lifecycle/body proof: scratchpad/overlay-goal-20260930-w32/S23/state-proof.md.
 */
int func_021B9620(void *unused, u32 *state, u32 unused2, u32 *p)
{
    u32 next;
    func_021B96A0((u32)p);
    if (func_02012204((const struct Ctx *)p[1]) != 0)
        func_021C09FC((void *)p[3]);
    switch (*state) {
    case 0: next = func_021B97B8(p); break;
    case 1: next = func_021B97BC((u8 *)p); break;
    case 2: next = func_021B97F8((u32)p); break;
    case 3: next = func_021B9824((u32)p); break;
    case 4: return 1;
    }
    func_021B99EC(p);
    func_021B9854(p);
    if (*state != next)
        func_021B96C8(p, (int *)state, next);
    return 0;
}








/*
 * Flushes the +4 handle through three sub-calls, then raises event 1 with
 * the record's leading halfword when the fourth sub-call reports busy.
 *
 * Addresses are Black-image addresses.
 */
void func_021B96A0(u32 a0)
{
    func_0201058C((void *)func_0201283C(func_020120F4(((struct ResearchProc *)a0)->f4)));
    if (func_020121CC((struct IcaAnime *)(*(u32 *)&((struct ResearchProc *)a0)->f4)) != 0) {
    func_0203D34C(1, ((struct ResearchProc *)a0)->f0);
    }
}









void func_021B96C8(void *a, int *p, int c)
{
    func_021B970C(a, (u32 *)p);
    func_021B9774(a, (u32 *)p, c);
    switch (*p) {
    case 1:
        func_021C09BC((void *)(*(int *)((char *)a + 0xc)), 1);
        break;
    case 2:
        func_021C09BC((void *)(*(int *)((char *)a + 0xc)), 2);
        break;
    case 3:
        func_021C09BC((void *)(*(int *)((char *)a + 0xc)), 3);
        break;
    }
}








/*
 * tail: zero halfword alignment at 021B9772.
 */
void func_021B970C(u32 *p, u32 *state)
{
    switch (*state) {
    case 0: case 4: break;
    case 1: func_021B9AF8((void *)p[4]); break;
    case 2: func_021BABB4((void *)p[5]); break;
    case 3: func_021BD61C((void *)p[6]); break;
    }
    switch (*state) {
    case 0: case 4: break;
    case 1: p[4] = 0; break;
    case 2: p[5] = 0; break;
    case 3: p[6] = 0; break;
    }
}








void func_021B9774(u32 *p, u32 *state, u32 kind)
{
    switch (kind) {
    case 0:
    case 4:
        break;
    case 1:
        p[4] = func_021B9AD0((void *)p[3]);
        break;
    case 2:
        p[5] = func_021BAB80(p[3], p[7]);
        break;
    case 3:
        p[6] = (u32)func_021BD5F4((void *)p[3]);
        break;
    }
    *state = kind;
}








int func_021B97B8(void *a0)
{
    return 1;
}








u32 func_021B97BC(u8 *a0)
{
    func_021B9B08((char *)(((struct ResearchProc *)a0)->f10));
    if (func_021B9B80((void *)(((struct ResearchProc *)a0)->f10)) != 0) {
    switch (func_021B9B90((void *)(((struct ResearchProc *)a0)->f10))) {
    case 0:
    return 2;
    case 1:
    return 3;
    case 2:
    return 4;
    }
    return 4;
    }
    return 1;
}








u32 func_021B97F8(u32 a0)
{
    func_021BABC4((void *)(((struct ResearchProc *)a0)->f14));
    if (func_021BAC90((void *)(((struct ResearchProc *)a0)->f14)) != 0) {
    if (func_021BAC98((void *)(((struct ResearchProc *)a0)->f14)) == 0) {
    return 1;
    }
    return 4;
    }
    return 2;
}








u32 func_021B9824(u32 a0)
{
    func_021BD62C((unsigned char *)(((struct ResearchProc *)a0)->f18));
    if (func_021BD708((void *)(((struct ResearchProc *)a0)->f18)) != 0) {
    if (func_021BD710((void *)(((struct ResearchProc *)a0)->f18)) == 0) {
    return 1;
    }
    return 4;
    }
    return 3;
}









u32 func_021B9850(const void *p)
{
    return *(const u32 *)&((struct ResearchProc *)p)->f8;
}









void func_021B9854(void *p)
{
    u32 *counter = (u32 *)((char *)p + 8);
    *counter += 1;
}









void func_021B985C(void *p, u32 value)
{
    ((struct ResearchProc *)p)->f0 = 1;
    ((struct ResearchProc *)p)->f4u = value;
    ((struct ResearchProc *)p)->f8 = 0;
    ((struct ResearchProc *)p)->fC = 0;
    ((struct ResearchProc *)p)->f10 = 0;
    ((struct ResearchProc *)p)->f14 = 0;
    ((struct ResearchProc *)p)->f18 = 0;
    ((struct ResearchProc *)p)->f1C = 0;
}








void func_021B9874(u32 a0)
{
    ((struct ResearchProc *)a0)->fC = func_021C097C(((struct ResearchProc *)a0)->f0, ((struct ResearchProc *)a0)->f4u);
}








/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021B9884(u32 a0)
{
    func_021C099C((void *)(((struct ResearchProc *)a0)->fC));
    ((struct ResearchProc *)a0)->fC = 0;
    return 0;
}








/*
 * Reconstructed from the listing.
 *
 * Addresses are Black-image addresses.
 */
void func_021B9894(u32 a0)
{
    u32 r = func_021C0DC4(((struct ResearchProc *)a0)->f0);
    ((struct ResearchProc *)a0)->f1C = r;
    func_021C0DE4((void *)r);
}








u32 func_021B98A8(u32 a0)
{
    func_021C0DDC((void *)(((struct ResearchProc *)a0)->f1C));
    ((struct ResearchProc *)a0)->f1C = 0;
    return 0;
}









/*
 * Hint note: d_021C2E60 data line carries no overlay token (contested hint).
 */
void func_021B98B8(unsigned short heapId)
{
    func_0203F8F4(heapId);
    func_0203FC28((struct DispConfig *)(&d_021C2E30));
    func_0203FCA0(4, (const struct BgTemplate *)(&d_021C2E60), 0);
    func_0203FCA0(5, (const struct BgTemplate *)(&d_021C2E40), 0);
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_0203FCA0(1, (const struct BgTemplate *)(&d_021C2E80), 0);
    func_02040588(1, 1);
}








u32 func_021B990C(void)
{
    func_020403F4(1);
    func_020403F4(4);
    return func_0203F9B4();
}








void func_021B9920(u32 heap)
{
    void *palette;
    void *character;
    void *screen;
    void *screen2;
    struct ArcFile *arc;
    void *buffer;
    arc = func_020490F4(192, heap);
    buffer = func_02049250(arc, 9, heap);
    func_02062A98(buffer, &palette);
    func_02040E78(4, *(void **)((char *)palette + 12), 512, 0);
    func_020307B0(buffer);
    buffer = func_02049250(arc, 10, heap);
    func_02062A4C(buffer, &character);
    func_02040B1C(4, *(void **)((char *)character + 0x14), *(u32 *)((char *)character + 0x10), 0);
    func_020307B0(buffer);
    buffer = func_02049250(arc, 11, heap);
    func_02062B30(buffer, &screen);
    func_02041090(4, (u32)((char *)screen + 12), 0, 0, 32, 24);
    func_020409B4(4);
    func_020307B0(buffer);
    buffer = func_02049250(arc, 12, heap);
    func_02062B30(buffer, &screen2);
    func_02041090(5, (u32)((char *)screen2 + 12), 0, 0, 32, 24);
    func_020409B4(5);
    func_020307B0(buffer);
    func_02049238(arc);
}









void func_021B99EC(const void *p)
{
    u32 t = func_021B9850(p) / 10;
    u32 m = (u8)(t % 6);
    func_020413B0(5, 0, 0, 0x20, 0x18, (u8)m);
    func_020409B4(5);
}








void func_021B9A24(u32 heap)
{
    void *palette;
    void *character;
    void *screen;
    struct ArcFile *arc;
    void *buffer;
    arc = sub_020490F4(192, (u16)((heap & 0x7fff) | 0x8000));
    buffer = func_02049250(arc, 0, heap);
    func_02062A98(buffer, &palette);
    func_02040E78(1, ((struct Obj25805 *)palette)->fC, 512, 0);
    sub_020307B0(buffer);
    buffer = func_02049250(arc, 1, heap);
    func_02062A4C(buffer, &character);
    func_02040B1C(1, ((struct ResearchProc *)character)->f14p, ((struct ResearchProc *)character)->f10, 0);
    sub_020307B0(buffer);
    buffer = func_02049250(arc, 2, heap);
    func_02062B30(buffer, &screen);
    func_02041090(1, (u32)((char *)screen + 12), 0, 0, 32, 24);
    sub_020409B4(1);
    sub_020307B0(buffer);
    func_02049238(arc);
}









u32 func_021B9AD0(void *self)
{
    u32 v = func_021C09AC(self);
    u32 o = func_021BA4E0(v);
    func_021BA504((char *)o);
    func_021BA4D0((void *)o, v);
    func_021BA4CC((void *)o, (u32)self);
    return o;
}








u32 func_021B9AF8(void *a0)
{
    func_021BA68C((void *)a0);
    return func_021BA4FC(a0);
}








void func_021B9B08(char *p)
{
    switch (((struct ResearchObjC *)p)->f18) {
    case 0:func_021B9B98(p);break;
    case 1:func_021B9C54(p);break;
    case 2:func_021B9E44(p);break;
    case 3:func_021BA078((unsigned)p);break;
    case 4:func_021BA094((unsigned)p);break;
    case 5:func_021BA0C4((unsigned)p);break;
    case 6:return;
    }
    if (func_021B9B80(p)==0) {
        func_021BA1D4((unsigned)p);func_021BA41C((int *)p);
        func_021C09D0(*(unsigned *)&((struct ResearchObjC *)p)->f0);func_0204A600();
    }
    func_021BA374(p);func_021BA158((unsigned)p);
}









int func_021B9B80(void *p)
{
    if (((struct ResearchObjC *)p)->f88 != 0) {
        return 1;
    }
    return 0;
}









/*
 * Field getter, u32 at +0x8c.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021B9B90(void *p)
{
    return ((struct ResearchObjC *)p)->f8C;
}








void func_021B9B98(char *p)
{
    unsigned kind;
    func_021BA67C((unsigned)p);func_021BA5BC((unsigned)p);
    func_021BA5F8(p);func_021BA63C((u8 *)p);func_021BA560(p);
    func_021BA698(p);func_021BA768(p);func_021BA7B8(p);
    func_021BA7E0(p);func_021BA830(p);func_021BA86C(p);
    func_021BA910((struct Context *)p);func_021BA978((struct Context *)p);
    func_021BA9FC(p);func_021BAA48(p);func_021BAAD8(p);
    func_021BAB0C(p);func_021BAB70((unsigned)p);func_021BAB58(p);
    if (func_021BA3B4((unsigned)p,0)==0)func_021BA2FC((unsigned)p);
    kind=func_021BA19C((unsigned char *)p);
    func_021BA144((unsigned char *)p,func_021BA19C((unsigned char *)p));
    if (kind==2) {func_021BA284(((struct ResearchObjC *)p)->f28);func_021BA3E8((char *)((unsigned)p),0);}
    func_021BA354();func_021BA150(p);
}








/*
 * ABI: 02035C08 result is compared in the original; matched 02025EA4/02027E3C callers also declare its int return despite the forwarding body's void spelling.
 * Original passes p to 020362DC although the own matched body ignores entry r0.
 */
void func_021B9C54(char *p)
{
    u32 keys=func_020362DC();
    int choice=func_02035C08(p+44);
    int other=func_02035C08(func_021C09B8(((struct ResearchObjC *)p)->f0));
    if(func_021BA4D4(p)!=0 || other==0) {
        func_021BA1C0((u8 *)p,1);func_021BA1CC(p,2);func_021BA31C((u8 *)p);func_020061E4(1361);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);return;
    }
    if(keys&2) {
        func_021BA1C0((u8 *)p,0);func_021BA1CC(p,2);func_021BA31C((u8 *)p);func_020061E4(1361);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);return;
    }
    if((keys&64)||(keys&128)||(keys&32)||(keys&16)||(keys&1)) {
        func_021BA284(*(int *)&((struct ResearchObjC *)p)->f28);func_021BA3E8(p,0);func_021BA150(p);func_021BA144((u8 *)p,2);return;
    }
    if(choice==0) {
        if(func_021BA3B4((u32)p,0)!=0) {
            func_021BA1C0((u8 *)p,1);func_021BA1CC(p,0);func_021BA254((u32)p,0);func_021BA284(*(int *)&((struct ResearchObjC *)p)->f28);func_021BA40C((u8 *)p,0);func_021BA3E8(p,2);func_020061E4(1356);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);
        } else func_020061E4(1367);
    } else if(choice==1) {
        if(func_021BA3B4((u32)p,1)!=0) {
            func_021BA1C0((u8 *)p,1);func_021BA1CC(p,1);func_021BA254((u32)p,1);func_021BA284(*(int *)&((struct ResearchObjC *)p)->f28);func_021BA40C((u8 *)p,0);func_021BA3E8(p,2);func_020061E4(1356);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);
        } else func_020061E4(1367);
    }
}








void func_021B9E44(char *p)
{
    u32 keys=func_020362DC();
    int choice=func_02035C08(p+44);
    int other=func_02035C08(func_021C09B8(((struct ResearchObjC *)p)->f0));
    if(func_021BA4D4(p)!=0 || other==0) {
        func_021BA1C0((u8 *)p,1);func_021BA1CC(p,2);func_021BA31C((u8 *)p);func_020061E4(1361);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);return;
    }
    if(keys&64)func_021BA1F8((u32)p);
    if(keys&128)func_021BA228((u32)p);
    if(keys&1) {
        func_021BA1C0((u8 *)p,0);func_021BA40C((u8 *)p,0);func_021BA3E8(p,2);func_020061E4(1356);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);
        switch(((struct ResearchObjC *)p)->f28) {
        case 0:func_021BA1CC(p,0);return;
        case 1:func_021BA1CC(p,1);return;
        default:func_021BA1CC(p,2);return;
        }
    }
    if(choice==0) {
        if(func_021BA3B4((u32)p,0)!=0) {
            func_021BA1C0((u8 *)p,1);func_021BA254((u32)p,0);func_021BA40C((u8 *)p,0);func_021BA3E8(p,2);func_020061E4(1356);func_021BA1CC(p,0);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);
        } else func_020061E4(1367);
    } else if(choice==1) {
        if(func_021BA3B4((u32)p,1)!=0) {
            func_021BA1C0((u8 *)p,1);func_021BA254((u32)p,1);func_021BA40C((u8 *)p,0);func_021BA3E8(p,2);func_020061E4(1356);func_021BA1CC(p,1);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);
        } else func_020061E4(1367);
    } else if(keys&2) {
        func_021BA31C((u8 *)p);func_020061E4(1361);func_021BA1CC(p,2);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);
    }
}








/*
 * Steps the record through func_021BA150 while the running count is below
 * func_021BA37C().
 *
 * Addresses are Black-image addresses.
 */
void func_021BA078(u32 a0)
{
    u32 v1 = func_021BA384((void *)a0);
    if (v1 < func_021BA37C((void *)a0)) {
    func_021BA150((void *)a0);
    }
}






void func_021BA094(u32 a0)
{
    switch (func_021BA190((void *)a0)) {
    case 0:
    func_021BA364();
    func_021BA194((void *)a0);
    break;
    case 1:
    if (func_0204E804() == 0) {
    func_021BA150((void *)a0);
    }
    break;
    }
}





void func_021BA0C4(u32 a0)
{
    func_021BAB68();
    func_021C09E0(*(u32 *)&((struct ResearchObjC *)a0)->f0);
    func_021C09EC(*(u32 *)&((struct ResearchObjC *)a0)->f0);
    func_021BAB38((char *)a0);
    func_021BAAF4((int *)a0);
    func_021BAAB8((u8 *)a0);
    func_021BAA28((int *)a0);
    func_021BA960(a0);
    func_021BA9D0(a0);
    func_021BA8E0((int *)a0);
    func_021BA848(a0);
    func_021BA82C(a0);
    func_021BA7D0(a0);
    func_021BA7B4(a0);
    func_021BA748(a0);
    func_021BA624((int *)a0);
    func_021BA5D8((u8 *)a0);
    ((struct ResearchObjC *)a0)->f88 = 1;
    func_021BA144((u8 *)a0, 6);
    func_021BA150((void *)a0);
}








/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 20)) to func_021C0E4C.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA144(u8 *a0, u32 a1)
{
    func_021C0E4C((u32)(((struct ResearchObjC *)a0)->f14), a1);
}








void func_021BA150(void *p)
{
    ((struct ResearchObjC *)p)->f80 = 1;
}







void func_021BA158(u32 a0)
{
    if (((struct ResearchObjC *)a0)->f80 != 0) {
    if (func_021C0E64(((struct ResearchObjC *)a0)->f14) == 0) {
    func_021BA180((void *)a0, func_021C0E54((struct Ring *)(((struct ResearchObjC *)a0)->f14)));
    }
    }
}








/*
 * Set +0x18, clear +0x1c, +0x20 and +0x80.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA180(void *p, u32 v)
{
    ((struct ResearchObjC *)p)->f18 = v;
    ((struct ResearchObjC *)p)->f1C = 0;
    ((struct ResearchObjC *)p)->f20 = 0;
    ((struct ResearchObjC *)p)->f80 = 0;
}








u32 func_021BA190(void *p)
{
    return ((struct ResearchObjC *)p)->f1C;
}








void func_021BA194(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x1c);
    *c += 1;
}







u32 func_021BA19C(u8 *a0)
{
    u32 v = ((struct ResearchObjC *)a0)->f0u;
    u32 a = func_021C09C8((void *)v);
    u32 b = func_021C09CC((void *)v);
    if (a != 0 && b == 0) {
    return 2;
    }
    return 1;
}








void func_021BA1C0(u8 *a0, u32 a1)
{
    func_021C09C4(*(u8 * *)&((struct ResearchObjC *)a0)->f0, a1);
}








void func_021BA1CC(void *p, u32 v)
{
    ((struct ResearchObjC *)p)->f8C = v;
}






/*
 * One-shot latch on the +0x84 field.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA1D4(u32 a0)
{
    if (((struct ResearchObjC *)a0)->f84 == 0) {
    if (GAME_BEACON_PopQuestionnaireUpdated() == 1) {
    ((struct ResearchObjC *)a0)->f84 = 1;
    func_021BA328(a0);
    }
    }
}






void func_021BA1F8(u32 a0)
{
    func_021BA2BC(((struct ResearchObjC *)a0)->f28);
    func_021BA388((char *)a0, -1);
    func_021BA284(((struct ResearchObjC *)a0)->f28);
    func_020061E4(1352);
    func_021BA3E8((char *)a0, 1);
}






void func_021BA228(u32 a0)
{
    func_021BA2BC(((struct ResearchObjC *)a0)->f28);
    func_021BA388((char *)a0, 1);
    func_021BA284(((struct ResearchObjC *)a0)->f28);
    func_020061E4(1352);
    func_021BA3E8((char *)a0, 1);
}






void func_021BA254(u32 a0, u32 a1)
{
    func_021BA2BC(((struct ResearchObjC *)a0)->f28);
    func_021BA3B0((void *)a0, a1);
    func_021BA284(((struct ResearchObjC *)a0)->f28);
    func_020061E4(1352);
    func_021BA3E8((char *)a0, 1);
}







void func_021BA284(int sel)
{
    int a, b, c, d, e, f;
    switch (sel) {
    case 0:
        a = 2; b = 3; c = 5; d = 0x1a; e = 5; f = 0xa;
        break;
    case 1:
        a = 2; b = 3; c = 0xc; d = 0x1a; e = 5; f = 0xa;
        break;
    default:
        return;
    }
    func_020413B0(a, b, c, d, e, f);
    func_020409B4(a);
}







void func_021BA2BC(int sel)
{
    int a, b, c, d, e, f;
    switch (sel) {
    case 0:
        a = 2; b = 3; c = 5; d = 0x1a; e = 5; f = 5;
        break;
    case 1:
        a = 2; b = 3; c = 0xc; d = 0x1a; e = 5; f = 6;
        break;
    default:
        return;
    }
    func_020413B0(a, b, c, d, e, f);
    func_020409B4(a);
}






void func_021BA2FC(u32 a0)
{
    func_021C1038((u8 *)(((struct ResearchObjC *)a0)->f54), 15);
    func_021BA3E8((char *)a0, 3);
    func_021BA3E8((char *)a0, 4);
}






void func_021BA31C(u8 *a0)
{
    func_021C09D8((u8 *)(((struct ResearchObjC *)a0)->f0u), 0);
}






u32 func_021BA328(u32 a0)
{
    u32 v1 = func_021BA3E0((void *)a0, 0);
    func_0204B3DC((struct Obj *)v1, 1);
    func_0204B92C((struct Obj *)v1, 1);
    func_0204B954((struct Actor *)v1, 4096);
    return CLACT_SetActorAnimFrame(v1, 0);
}






void func_021BA354(void)
{
    func_0204E720(3, 0x10, 0, 0);
}






void func_021BA364(void)
{
    func_0204E720(3, 0, 16, 0);
}







void func_021BA374(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x20);
    *c += 1;
}







u32 func_021BA37C(void *p)
{
    return ((struct ResearchObjC *)p)->f20;
}







/*
 * Field setter, u32 at +0x24.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA380(void *p, u32 v)
{
    ((struct ResearchObjC *)p)->f24 = v;
}







u32 func_021BA384(void *p)
{
    return ((struct ResearchObjC *)p)->f24;
}







void func_021BA388(char *self, int d)
{
    int n = *(int *)&((struct ResearchObjC *)self)->f28;
    do {
        n = (n + d + 2) % 2;
    } while (!func_021BA3B4((u32)self, n));
    *(int *)&((struct ResearchObjC *)self)->f28 = n;
}







/*
 * Field setter, u32 at +0x28.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA3B0(void *p, u32 v)
{
    ((struct ResearchObjC *)p)->f28 = v;
}






u32 func_021BA3B4(u32 a0, u32 a1)
{
    if (a1 == 0) {
    if (func_021BA434((char *)a0) > 1) {
    return 1;
    }
    return 0;
    }
    return 1;
}







/*
 * Indexed u32 read: element i of the table at +0x5c.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BA3D0(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x5c);
}







/*
 * Indexed u32 read: element i of the table at +0x74.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BA3D8(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x74);
}







/*
 * Indexed u32 read: element i of the table at +0x7c.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BA3E0(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x7c);
}







void func_021BA3E8(char *self, int i)
{
    func_021C29F8(*(void **)(self + i * 4 + 0x38),
                  *(u32 *)(d_021C3004 + i * 0x14),
                  *(u16 *)(d_021C3008 + i * 0x14));
}







/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 56)), (a1)*4 to func_021C2A00.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA40C(u8 *a0, u32 a1)
{
    func_021C2A00((u32)(*(u32*)(a0 + (a1)*4 + 56)));
}







void func_021BA41C(int *p)
{
    int i;
    for (i = 0; i < 5; i++)
        func_021C29F0(p[i + 0x0E]);
}






/*
 * trailing: 021BA4C6..021BA4C8 zero alignment padding.
 */
unsigned char func_021BA434(char *p)
{
    void *bitmap=(void *)func_0201296C((const struct BigObj *)func_021C09B4(((struct ResearchObjC *)p)->f0));
    int count=1;
    if(func_020142E8(bitmap,240)==1)count++;
    if(func_020142E8(bitmap,241)==1)count++;
    if(func_020142E8(bitmap,242)==1)count++;
    if(func_020142E8(bitmap,243)==1)count++;
    if(func_020142E8(bitmap,244)==1)count++;
    if(func_020142E8(bitmap,245)==1)count++;
    if(func_020142E8(bitmap,246)==1)count++;
    if(func_020142E8(bitmap,247)==1)count++;
    if(func_020142E8(bitmap,248)==1)count++;
    return count;
}







u32 func_021BA4C8(void *p)
{
    return ((struct ResearchObjC *)p)->f0u;
}







void func_021BA4CC(void *p, u32 v)
{
    ((struct ResearchObjC *)p)->f0u = v;
}







/*
 * Field setter, u16 at +4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA4D0(void *p, u32 v)
{
    ((struct ResearchObjC *)p)->f4 = v;
}






u32 func_021BA4D4(void *p)
{
    return func_021C09F8((void *)func_021BA4C8(p));
}






u32 func_021BA4E0(u32 a0)
{
    return (u32)func_02030734(a0, 144, 0, (const char *)0x21C3FEC, 1486);
}







u32 func_021BA4FC(void *a0)
{
    return func_020307B0(a0);
}






/*
 * trailing: 021BA55E..021BA560 zero alignment padding.
 */
void func_021BA504(char *p)
{
    ((struct ResearchObjC *)p)->f80=0;((struct ResearchObjC *)p)->f84=0;((struct ResearchObjC *)p)->f88=0;
    ((struct ResearchObjC *)p)->f18=0;((struct ResearchObjC *)p)->f20=0;((struct ResearchObjC *)p)->f24=0;
    ((struct ResearchObjC *)p)->f28=0;((struct ResearchObjC *)p)->f8C=2;((struct ResearchObjC *)p)->f1C=0;
    func_021BA8FC(p);func_021BA674(p);func_021BA5E4(p);func_021BA5B4(p);
    func_021BA858(p);func_021BA9E8(p);func_021BAA40(p);func_021BAAC4(p);
}






void func_021BA560(char *p)
{
    void *owner=((struct ResearchObjC *)p)->f0;
    unsigned a=func_021C09C8(owner),b=func_021C09CC(owner);
    if(a!=0 && b==0) {
        unsigned mode;
        switch(a) {case 2:default:mode=0;break;case 3:mode=1;break;}
        func_021BA3B0(p,mode);
    } else {
        if(func_021BA3B4((unsigned)p,0)!=0) func_021BA3B0(p,0);
        else func_021BA3B0(p,1);
    }
}







void func_021BA5B4(void *p)
{
    ((struct ResearchObjC *)p)->f8 = 0;
}






void func_021BA5BC(u32 a0)
{
    u8 s[4];
    ((struct ResearchObjC *)a0)->f8 = (u32)func_0201D7EC(23, 0, 0, 0, (u32)(((struct ResearchObjC *)a0)->f4));
}







void func_021BA5D8(u8 *a0)
{
    func_0201D83C((void *)((u32)(((struct ResearchObjC *)a0)->f8)));
}







/*
 * Clear two u32 slots at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA5E4(void *p)
{
    int i;
    for (i = 0; i < 2; i++)
        *(u32 *)((char *)p + i * 4 + 0xc) = 0;
}







void func_021BA5F8(char *self)
{
    int i = 0;
    do {
        int o = i * 4;
        *(u32 *)(self + o + 0xc) = (u32)func_02045B38((int)0, (int)2, (u16)(*(u32 *)((char *)d_021C2ED8 + o)), (u16)(((struct ResearchObjC *)self)->f4));
        i++;
    } while (i < 2);
}







void func_021BA624(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        func_02045C04((struct Rec *)p[i + 3]);
}







void func_021BA63C(u8 *self)
{
    int i = 0;
    do {
        int o = i * 4;
        u8 *t = d_021C2EE0 + o;
        self[o + 0x2e] = t[0];
        self[o + 0x2f] = t[1];
        self[o + 0x2c] = t[2];
        self[o + 0x2d] = t[3];
        i++;
    } while (i < 3);
}







void func_021BA674(void *p)
{
    ((struct ResearchObjC *)p)->f14 = 0;
}






void func_021BA67C(u32 a0)
{
    ((struct ResearchObjC *)a0)->f14 = func_021C0E08(10, ((struct ResearchObjC *)a0)->f4);
}







void func_021BA68C(Rec *p)
{
    func_021C0E3C((void *)p->a);
}






void func_021BA698(char *p)
{
    func_0203FC28(&d_021C2EEC);
    func_0203FCA0(6,&d_021C2F78,0);func_0203FCA0(7,&d_021C2F18,0);
    func_0203FCA0(2,&d_021C2F38,0);func_0203FCA0(3,&d_021C2F58,0);
    func_02040588(4,1);func_02040588(5,1);func_02040588(6,1);func_02040588(7,1);
    func_02040588(1,1);func_02040588(2,1);func_02040588(3,1);
    func_0207D63C((volatile unsigned *)0x04001050,2,1,7,15);
    func_0207D63C((volatile unsigned *)0x04000050,4,2,16,5);
    func_02045088(((struct ResearchObjC *)p)->f4);
}






void func_021BA748(u32 a0)
{
    func_020450C8();
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(7);
    func_020403F4(6);
}






void func_021BA768(char *p)
{
    struct ArcFile *arc=func_020490F4(192,((struct ResearchObjC *)p)->f4);
    void *file=func_02049250(arc,13,((struct ResearchObjC *)p)->f4);
    void *data;
    func_02062B30(file,&data);
    func_02041090(6,(unsigned)((char *)data+12),0,0,32,24);
    func_020409B4(6);func_020307B0(file);func_02049238(arc);
}







void func_021BA7B4(u32 a0)
{
}






u32 func_021BA7B8(void *a0)
{
    func_02040C14(7, 0, 1, 0);
    return func_020414EC(7);
}







void func_021BA7D0(u32 a0)
{
    func_02040DA8(7, 1, 0);
}






void func_021BA7E0(char *p)
{
    struct ArcFile *arc=func_020490F4(192,((struct ResearchObjC *)p)->f4);
    void *file=func_02049250(arc,4,((struct ResearchObjC *)p)->f4);
    void *data;
    func_02062B30(file,&data);
    func_02041090(2,(unsigned)((char *)data+12),0,0,32,24);
    func_020409B4(2);func_020307B0(file);func_02049238(arc);
}







void func_021BA82C(u32 a0)
{
}






u32 func_021BA830(void *a0)
{
    func_02040C14(3, 0, 1, 0);
    return func_020414EC(3);
}







void func_021BA848(u32 a0)
{
    func_02040DA8(3, 1, 0);
}







void func_021BA858(void *p)
{
    int i;
    for (i = 0; i < 4; i++)
        *(u32 *)((char *)p + i * 4 + 0x4c) = 0;
}






void func_021BA86C(char *p)
{
    struct Desc desc;
    int i;
    for(i=0;i<4;i++) {
        const struct Entry_021BA86C *s=&d_021C2F98[i];
        desc.a=s->desc.a;desc.b=s->desc.b;desc.c=s->desc.c;desc.d=s->desc.d;
        desc.e=s->desc.e;desc.f=s->desc.f;desc.g=s->desc.g;desc.h=s->desc.h;
        desc.i=s->desc.i;desc.j=s->desc.j;desc.k=s->desc.k;desc.data=s->data;
        *(unsigned *)(p+i*4+0x4c)=(unsigned int)func_021C0EF4((const struct Config *)(&desc),((struct ResearchObjC *)p)->f8,*(unsigned *)(p+s->desc.data*4+0xc),((struct ResearchObjC *)p)->f4);
        func_021C0F5C(*(unsigned *)(p+i*4+0x4c),s->mode);
    }
}







void func_021BA8E0(int *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        func_021C0F48((u8 *)p[i + 0x13]);
        p[i + 0x13] = 0;
    }
}







/*
 * Clear six u32 slots at +0x5c.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA8FC(void *p)
{
    int i;
    for (i = 0; i < 6; i++)
        *(u32 *)((char *)p + i * 4 + 0x5c) = 0;
}






/*
 * trailing: 021BA95E..021BA960 zero alignment padding.
 * lever: acquisition-order a,b,c stores hoist spilled b reload before c store.
 * ABF0 forwards AC18's returned r0; caller stores it at +0x6c.
 */
void func_021BA910(struct Context *p)
{
    u16 heap=p->heap;
    void *arc=func_020490F4(192,heap);
    int a=func_0204A6C8((void *)((unsigned)arc),15,0,1,heap);
    int b=func_0204ABF0((void *)arc,16,1,0,heap);
    int c=func_0204AF28((void *)((unsigned)arc),14,17,heap);
    p->slots[3]=a;p->slots[4]=b;p->slots[5]=c;
    func_02049238(arc);
}






u32 func_021BA960(u32 a0)
{
    func_0204A8D4(((struct ResearchObjC *)a0)->f68);
    func_0204ADA4(((struct ResearchObjC *)a0)->f6C);
    return func_0204AFD8(((struct ResearchObjC *)a0)->f70);
}






void func_021BA978(struct Context *p)
{
    u16 heap=p->heap;
    void *arc=func_020490F4(192,heap);
    int a=func_0204A6C8((void *)((unsigned)arc),15,0,0,heap);
    int b=func_0204AC18((void *)((unsigned)arc),16,0,192,0,4,heap);
    int c=func_0204AF28((void *)((unsigned)arc),14,17,heap);
    p->slots[0]=a;p->slots[1]=b;p->slots[2]=c;
    func_02049238(arc);
}






u32 func_021BA9D0(u32 a0)
{
    func_0204A8D4(((struct ResearchObjC *)a0)->f5C);
    func_0204ADA4(((struct ResearchObjC *)a0)->f60);
    return func_0204AFD8(((struct ResearchObjC *)a0)->f64);
}







void func_021BA9E8(void *p)
{
    int i;
    for (i = 0; i < 2; i++)
        *(u32 *)((char *)p + i * 4 + 0x74) = 0;
}







void func_021BA9FC(char *self)
{
    int i = 0;
    do {
        *(u32 *)(self + i * 4 + 0x74) = (u32)func_0204B100(d_021C2ED2[i], d_021C2ED0[i], ((struct ResearchObjC *)self)->f4);
        i++;
    } while (i < 2);
}







/*
 * Addresses are Black-image addresses.
 */
void func_021BAA28(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        func_0204B1CC((struct Bank *)p[i + 0x1D]);
}







/*
 * Clear the u32 at +0x7c.
 *
 * Addresses are Black-image addresses.
 */
void func_021BAA40(void *p)
{
    ((struct ResearchObjC *)p)->f7C = 0;
}






/*
 * B294's returned r0 is stored and passed to B3DC in the original.
 */
void func_021BAA48(char *p)
{
    struct Vec vec;
    unsigned first,second,third,fourth;
    vec.x=d_021C2EFC.vec.x;vec.y=d_021C2EFC.vec.y;vec.z=d_021C2EFC.vec.z;
    vec.a=d_021C2EFC.vec.a;vec.b=d_021C2EFC.vec.b;
    first=func_021BA3D8(p,d_021C2EFC.first);
    second=func_021BA3D0(p,d_021C2EFC.second);
    third=func_021BA3D0(p,d_021C2EFC.third);
    fourth=func_021BA3D0(p,d_021C2EFC.fourth);
    *(unsigned *)&((struct ResearchObjC *)p)->f7C=(unsigned)func_0204B294((void *)first,second,third,fourth,&vec,d_021C2EFC.arg,((struct ResearchObjC *)p)->f4);
    func_0204B3DC(*(struct Obj * *)&((struct ResearchObjC *)p)->f7C,0);
}







void func_021BAAB8(u8 *a0)
{
    func_0204B3B4((struct Obj *)((u32)(((struct ResearchObjC *)a0)->f7C)));
}







/*
 * Clear five u32 slots at +0x38.
 *
 * Addresses are Black-image addresses.
 */
void func_021BAAC4(void *p)
{
    int i;
    for (i = 0; i < 5; i++)
        *(u32 *)((char *)p + i * 4 + 0x38) = 0;
}







void func_021BAAD8(char *p)
{
    int i;
    for (i = 0; i < 5; i++)
        ((int *)(p + 0x38))[i] = func_021C29C8(((struct ResearchObjC *)p)->f4);
}







void func_021BAAF4(int *p)
{
    int i;
    for (i = 0; i < 5; i++)
        func_021C29D8((void *)p[i + 0x0E]);
}







void func_021BAB0C(char *self)
{
    int i;
    for (i = 0; i < 5; i++) {
        func_021C29E8((void *)(*(int *)(self + i * 4 + 0x38)), d_021C2FF8[i].a, d_021C2FF8[i].b, d_021C2FF8[i].c);
    }
}







void func_021BAB38(char *self)
{
    int i;
    for (i = 0; i < 5; i++) {
        func_021C2A08((char *)(*(int *)(self + i * 4 + 0x38)));
    }
}







/*
 * Tail-call thunk: ldr r3,[pc,#0]; bx r3; .word 0x0204A648.  Blocker target
 * for func_021BAB58 (pkt_021B9850).
 */
void func_021BAB50(void)
{
    func_0204A648();
}






void func_021BAB58(void *a0)
{
    func_02005654((int)func_021BAB50, 0);
}







/*
 * Tail-call veneer: branch to func_0200566C.
 *
 * Addresses are Black-image addresses.
 */
void func_021BAB68(void)
{
    func_0200566C();
}






void func_021BAB70(u32 a0)
{
    func_0203D34C(1, ((struct ResearchObjC *)a0)->f4);
}






u32 func_021BAB80(u32 a0, u32 a1)
{
    u32 v1 = func_021C09AC((void *)a0);
    u32 v2 = func_021BC758(v1);
    func_021BC774((u8 *)v2);
    func_021BC634((void *)v2, v1);
    func_021BC638((void *)v2, a0);
    func_021BC640((void *)v2, a1);
    return v2;
}






u32 func_021BABB4(void *a0)
{
    func_021BC954((u8 *)a0);
    return func_021BC818(a0);
}







void func_021BABC4(void *self)
{
    switch (func_021BB974(self)) {
    case 0: func_021BACA0(self); break;
    case 1: func_021BAE00(self); break;
    case 2: func_021BAF70(self); break;
    case 3: func_021BB190(self); break;
    case 4: func_021BB200((struct ResearchTop *)self); break;
    case 6: func_021BB69C(self); break;
    case 5: func_021BB710(self); break;
    case 7: func_021BB484(self); break;
    case 8: func_021BB2B4(self); break;
    case 9: func_021BB534(self); break;
    case 10: func_021BB37C(self); break;
    case 11: func_021BB784((struct ResearchTop *)self); break;
    case 12: func_021BB5F4(self); break;
    case 13: func_021BB84C(self); break;
    case 14: break;
    }
    if (!func_021BAC90(self)) {
        func_021BC5F0(self);
        func_021BC5D4(self);
        func_0204A600();
    }
    func_021BB908(self);
    func_021BB94C((u32)self);
}







u32 func_021BAC90(void *p)
{
    return ((struct ResearchTop *)p)->f164;
}







/*
 * Field getter, u32 at +0x168.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BAC98(void *p)
{
    return ((struct ResearchTop *)p)->f168;
}






void func_021BACA0(u8 *p)
{
    u8 slot;
    func_021BC93C((u32)p);
    func_021BC8B4((u32)p);
    func_021BC8E4((struct ResearchTop *)p);
    func_021BC960(p);
    func_021BC43C(p);
    func_021BC820(p);
    func_021BC9FC((char *)p);
    func_021BCAE8((char *)p);
    func_021BCB48((u32)p);
    func_021BCB70((char *)p);
    func_021BCBD0((struct ResearchTop *)p);
    func_021BCC40((u32)p);
    func_021BCC68((struct ResearchTop *)p);
    func_021BCDF0((char *)p);
    func_021BCE7C((char *)p);
    func_021BCF68((struct ResearchTop *)p);
    func_021BCFD0(p);
    func_021BD094((struct ResearchTop *)p);
    func_021BD0C4(p);
    func_021BD178((struct ResearchTop *)p);
    func_021BD274((struct ResearchTop *)p);
    func_021BD38C((char *)p);
    func_021BD3B4(p);
    func_021BD47C(p);
    func_021BD4F0((char *)p);
    func_021BD53C((int *)p);
    func_021BD5C4((char *)p);
    func_021BD5B4((u32)p);
    func_021BD588(p);
    func_021BC580((char *)p,0);
    func_021BC72C(p,0,0);
    func_021BC72C(p,1,0);
    func_021BC72C(p,2,0);
    func_021BC644((struct ResearchTop *)p);
    slot=func_021BBC50(p);
    if(slot!=255) {
        func_021BBDF0((u32)p,slot);
        func_021BC6EC(p,slot);
        func_021BC014(p);
    }
    func_021BC43C(p);
    func_021BC168((u32)p);
    func_021BC014(p);
    func_021BBF60(p);
    func_021BC06C((char *)p);
    if(func_021BB928(p)==0) {
        func_021BBD68(p);
        func_021BC128((u32)p);
        func_021BB91C(p);
        func_021BB910(p,2);
    } else {
        func_021BBDAC(p);
        func_021BC0E8((u32)p);
        func_021BB91C(p);
        func_021BB910(p,1);
    }
    func_021BC480();
}






/* Narrow selection parameters follow the caller's explicit lsls/lsrs #24 pairs. */
void func_021BAE00(u8 *p)
{
    u32 keys=func_020362DC();
    int sel=func_02035C08(p+0x64);
    int flag;
    u32 a,b;
    flag=func_02035C08(func_021C09B8(*(void **)p));
    TOUCHPANEL_GetPointCont(&a,&b);
    if(func_021BC6D0(p)!=0 || flag==0) {
        func_020061E4(0x551);
        func_021BBAD0((u32)p);
        func_021BB934(p,1);
        func_021BB91C(p);
        func_021BB910(p,5);
        return;
    }
    if(keys&2) {
        func_020061E4(0x551);
        func_021BBAD0((u32)p);
        func_021BB934(p,0);
        func_021BB91C(p);
        func_021BB910(p,5);
        return;
    }
    if((keys&0x40)||(keys&0x80)||(keys&0x20)||(keys&0x10)||(keys&1)) {
        func_021BBD68(p);
        func_021BC128((u32)p);
        func_021BB91C(p);
        func_021BB910(p,2);
        return;
    }
    if(sel>=0 && sel<=9) {
        if(b>=24 && b<=168) {
            if(func_021BC6F4((u32)p,(u8)sel)==1) {
                func_021BBAA4((u32)p,sel);
                func_021BC6EC(p,p[0x32]);
                func_020061E4(0x54c);
                func_021BC580((char *)p,2);
                func_021BC06C((char *)p);
                func_021BC128((u32)p);
                func_021BB91C(p);
                func_021BB910(p,7);
                return;
            }
        }
    } else {
        if(TOUCHPANEL_HitCont(p+0x90)==0 || func_02035C08(p+0x90)==0) {
            if(func_021BC428(p)==1) {
                func_021BB91C(p);
                func_021BB910(p,4);
                func_021BB910(p,1);
            }
        }
    }
}







void func_021BAF70(char *p)
{
    u32 trg = func_0203630C();
    u32 keys = func_020362DC();
    int sel = func_02035C08(p + 0x64);
    int flag;
    u32 a;
    u32 b;
    flag = func_02035C08(func_021C09B8(*(void **)p));
    TOUCHPANEL_GetPointCont(&a, &b);
    if (trg & 0xc0) {
        func_021BC600(p);
    } else {
        func_021BC608(p);
    }
    if (func_021BC6D0(p) != 0 || flag == 0) {
        func_020061E4(0x551);
        func_021BBAD0((u32)p);
        func_021BB934((u8 *)p, (int)1);
        func_021BB91C(p);
        func_021BB910((u8 *)p, (int)6);
        return;
    }
    if ((keys & 0x40) || ((trg & 0x40) && ((struct ResearchTop *)p)->f32 != 0 && func_021BC5FC(p) > 10)) {
        func_021BBDAC((u8 *)p);
        func_021BBD40((u8 *)p, -1);
        func_021BB91C(p);
        func_021BB910((u8 *)p, (int)3);
        func_021BB910((u8 *)p, (int)2);
        return;
    }
    if ((keys & 0x80) || ((trg & 0x80) && ((struct ResearchTop *)p)->f32 < (int)func_021BC6DC(p) - 1 && func_021BC5FC(p) > 10)) {
        func_021BBDAC((u8 *)p);
        func_021BBD40((u8 *)p, 1);
        func_021BB91C(p);
        func_021BB910((u8 *)p, (int)3);
        func_021BB910((u8 *)p, (int)2);
        return;
    }
    if (keys & 1) {
        func_021BC580(p, 2);
        func_021BC6EC(p, ((struct ResearchTop *)p)->f32);
        func_020061E4(0x54c);
        func_021BB910((u8 *)p, (int)9);
        func_021BB91C(p);
        return;
    }
    if (sel >= 0 && sel <= 9) {
        if (b >= 0x18 && b <= 0xa8 && func_021BC6F4((u32)p, (u8)sel) == 1) {
            func_021BBAA4((u32)p, (u8)sel);
            func_021BC6EC(p, ((struct ResearchTop *)p)->f32);
            func_021BC580(p, 2);
            func_020061E4(0x54c);
            func_021BC06C(p);
            func_021BB91C(p);
            func_021BB910((u8 *)p, (int)7);
        }
        return;
    }
    if (keys & 2) {
        func_020061E4(0x551);
        func_021BBAD0((u32)p);
        func_021BB934((u8 *)p, (int)0);
        func_021BB91C(p);
        func_021BB910((u8 *)p, (int)6);
        return;
    }
    if (TOUCHPANEL_HitCont(p + 0x90) == 0 || func_02035C08(p + 0x90) == 0) {
        if (func_021BC428(p) == 1) {
            func_021BBDAC((u8 *)p);
            func_021BC0E8((u32)p);
            func_021BB91C(p);
            func_021BB910((u8 *)p, (int)4);
            func_021BB910((u8 *)p, (int)1);
        }
    }
}






void func_021BB190(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        func_021BBADC(p);
        func_021BBAA4((unsigned)p, p[0x33]);
        func_021BC06C((char *)p);
        func_021BB990(p);
        break;
    case 1:
        func_021BC2D8((struct ResearchTop *)p);
        func_021BC338(p);
        func_021BC43C(p);
        func_021BC168((unsigned)p);
        func_021BC014(p);
        func_021BBF60(p);
        if (func_021BC2FC(p)) {
            func_021BBF60(p);
            func_021BB91C(p);
        }
        break;
    }
}







void func_021BB200(struct ResearchTop *p)
{
    int a;
    int b;
    int r = TOUCHPANEL_GetPointCont((unsigned int *)(&a), (unsigned int *)(&b));
    int m = func_021BB98C(p);
    switch (m) {
    case 0:
    {
        if (r == 0) {
            func_021BC280((struct ResearchTop *)p);
            func_021BC2B8(p);
            func_021BB990(p);
        } else {
            func_021BC30C((struct ResearchTop *)p, func_021BC200(p, b));
            func_021BC380((struct ResearchTop *)p);
            func_021BC43C((u8 *)p);
            func_021BC168((unsigned int)p);
            func_021BC014((u8 *)p);
            func_021BC274(p);
        }
        break;
    }
    case 1:
    {
        func_021BC30C((struct ResearchTop *)p, p->f34 + p->f4C);
        func_021BC380((struct ResearchTop *)p);
        func_021BC43C((u8 *)p);
        func_021BC168((unsigned int)p);
        func_021BC014((u8 *)p);
        func_021BC250(p);
        if (func_021BC264(p) == 0) {
            func_021BC06C((char *)p);
            func_021BB91C(p);
        }
        break;
    }
    }
    func_021BBA30((u8 *)p);
}






void func_021BB2B4(char *p)
{
    u32 keys = func_020362DC();
    int st = func_02035C08(p + 0x58);
    if ((keys & 0x40) || (keys & 0x80) || (keys & 0x20) || (keys & 0x10) || (keys & 1)) {
        func_021BB91C(p);
        func_021BB910((unsigned char *)p, 9);
        return;
    }
    if (st == 0) {
        func_021BBA00((u32)p, 0);
        func_021BC5A8((u8 *)p, 3);
        func_021BC580(p, 5);
        func_021BB934((u8 *)p, 1);
        func_021BB91C(p);
        func_021BB910((unsigned char *)p, 12);
        return;
    }
    if (func_021BC6D0(p) != 0 || (keys & 2) || st == 1) {
        func_021BBA00((u32)p, 1);
        func_021BC5A8((u8 *)p, 3);
        func_021BC580(p, 5);
        func_020061E4(0x551);
        func_021BB91C(p);
        func_021BB910((unsigned char *)p, 11);
        func_021BB910((unsigned char *)p, 2);
    }
}






void func_021BB37C(char *p)
{
    u32 keys = func_020362DC();
    int st = func_02035C08(p + 0x58);
    if (keys & 0x40) {
        func_021BB9A0((u32)p);
    }
    if (keys & 0x80) {
        func_021BB9D0((u32)p);
    }
    if (keys & 1) {
        func_021BC5A8((u8 *)p, 3);
        func_021BC580(p, 5);
        switch (*(int *)&((struct ResearchTop *)p)->f2C) {
        case 0:
            func_021BB934((u8 *)p, 0);
            func_021BB91C(p);
            func_021BB910((unsigned char *)p, 12);
            break;
        case 1:
            func_020061E4(0x551);
            func_021BB91C(p);
            func_021BB910((unsigned char *)p, 11);
            func_021BB910((unsigned char *)p, 2);
            break;
        }
        return;
    }
    if (st == 0) {
        func_021BBA00((u32)p, 0);
        func_021BC5A8((u8 *)p, 3);
        func_021BC580(p, 5);
        func_021BB934((u8 *)p, 1);
        func_021BB91C(p);
        func_021BB910((unsigned char *)p, 12);
        return;
    }
    if (func_021BC6D0(p) != 0 || (keys & 2) || st == 1) {
        func_021BBA00((u32)p, 1);
        func_021BC5A8((u8 *)p, 3);
        func_021BC580(p, 5);
        func_020061E4(0x551);
        func_021BB91C(p);
        func_021BB910((unsigned char *)p, 11);
        func_021BB910((unsigned char *)p, 2);
    }
}





void func_021BB484(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        func_021BBD28((int)p, 1);
        func_021BBD28((int)p, 0);
        func_021BC72C(p, 0, (u8 *)1);
        func_021BC72C(p, 1, (u8 *)1);
        func_021BC72C(p, 2, (u8 *)1);
        if (((struct ResearchTop *)p)->f15C == 0) {
            func_021C1038((u8 *)(*(unsigned *)(p + p[0x32] * 4 + 0xb4)), 14);
            func_021BC4B4((char *)p);
        }
        func_021BBBE4(p);
        func_021BB990(p);
        break;
    case 1:
        func_021BC2D8((struct ResearchTop *)p);
        func_021BC338(p);
        func_021BC43C(p);
        func_021BC168((unsigned)p);
        func_021BC014(p);
        func_021BBF60(p);
        if (func_021BC2FC(p)) {
            func_021BB91C(p);
            func_021BB910(p, 8);
        }
        break;
    }
}





void func_021BB534(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        func_021BBD14(p, 0);
        func_021BBD28((int)p, 1);
        func_021BBD18((int)p, 0);
        func_021BC580((char *)((unsigned)p), 3);
        func_021BC72C(p, 0, (u8 *)1);
        func_021BC72C(p, 1, (u8 *)1);
        func_021BC72C(p, 2, (u8 *)1);
        if (((struct ResearchTop *)p)->f15C == 0) {
            func_021C1038((u8 *)(*(unsigned *)(p + p[0x32] * 4 + 0xb4)), 14);
            func_021BC4B4((char *)p);
        }
        func_021BBBE4(p);
        func_021BB990(p);
        break;
    case 1:
        func_021BC2D8((struct ResearchTop *)p);
        func_021BC338(p);
        func_021BC43C(p);
        func_021BC168((unsigned)p);
        func_021BC014(p);
        func_021BBF60(p);
        if (func_021BC2FC(p)) {
            func_021BB91C(p);
            func_021BB910(p, 10);
        }
        break;
    }
}





/*
 * arity: BB910 retains supplied r1=13 through its forwarding chain.
 */
void func_021BB5F4(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        func_021BBE7C((unsigned int)p, func_021BBC50(p));
        func_021BBCB0(p);
        func_021BBDF0((unsigned int)p, func_021BC6E4(p));
        func_021BC014(p);
        func_021BC72C(p, 3, (u8 *)1);
        func_020061E4(1898);
        func_021BB990(p);
        break;
    case 1:
        if (((struct ResearchTop *)p)->f24 >= 60) {
            func_021BC490();
            func_021BB990(p);
        }
        break;
    case 2:
        if (func_021BC4A0()) {
            func_021BC50C((char *)p);
            func_021BB990(p);
        }
        break;
    case 3:
        if (func_021BC55C((unsigned)p)) {
            func_021BB91C(p);
            func_021BB910(p, 13);
        }
        break;
    }
}





/*
 * extent: 021BB70E..021BB710 is two zero bytes of alignment padding.
 * arity: BB910 visibly receives r1=13; retain it through the forwarding chain despite its one-argument legacy file.
 */
void func_021BB69C(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        if (func_021BB948(p) < ((struct ResearchTop *)p)->f24) {
            func_021BC490();
            func_021BB990(p);
        }
        break;
    case 1:
        if (func_021BC4A0()) {
            func_021BC50C((char *)p);
            func_021BB990(p);
        }
        break;
    case 2:
        if (func_021BC55C((unsigned)p)) {
            func_021C1038((u8 *)(*(unsigned *)(p + p[0x32] * 4 + 0xb4)), 15);
            func_021BB91C(p);
            func_021BB910(p, 13);
        }
        break;
    }
}





/*
 * extent: 021BB782..021BB784 is two zero bytes of alignment padding.
 * arity: BB910 visibly receives r1=13; retain it through the forwarding chain despite its one-argument legacy file.
 */
void func_021BB710(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        if (func_021BB948(p) < ((struct ResearchTop *)p)->f24) {
            func_021BC490();
            func_021BB990(p);
        }
        break;
    case 1:
        if (func_021BC4A0()) {
            func_021BC50C((char *)p);
            func_021BB990(p);
        }
        break;
    case 2:
        if (func_021BC55C((unsigned)p)) {
            func_021C1038((u8 *)(*(unsigned *)(p + p[0x32] * 4 + 0xb4)), 15);
            func_021BB91C(p);
            func_021BB910(p, 13);
        }
        break;
    }
}






void func_021BB784(struct ResearchTop *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        func_021BBB60((u8 *)p);
        func_021BB990(p);
        break;
    case 1:
        func_021BC2D8((struct ResearchTop *)p);
        func_021BC338((u8 *)p);
        func_021BC43C((u8 *)p);
        func_021BC168((unsigned int)p);
        func_021BC014((u8 *)p);
        func_021BBF60((u8 *)p);
        if (func_021BC2FC(p) != 0) {
            func_021BB990(p);
        }
        break;
    case 2:
        if (func_021BC5B8((u32)p, 5) != 0) {
            func_021BC72C((u8 *)p, 0, 0);
            func_021BC72C((u8 *)p, 1, 0);
            func_021BC72C((u8 *)p, 2, 0);
            func_021BBF60((u8 *)p);
            func_021BC50C((char *)p);
            func_021BB990(p);
        }
        break;
    case 3:
        if (func_021BC55C((u32)p) != 0) {
            func_021C1038(p->fB4[p->f32], 15);
            func_021BB91C(p);
        }
        break;
    }
}





/*
 * volatile: DISPCNT read at 021BB8FA and write at 021BB900.
 * arity: C09E0/C09EC overwrite r1 before their indexed targets; BD3A4 overwrites r1=300; BCC58/BCB60 overwrite r1/r2 before 02040DA8. Omit only unused legacy trailing inputs, retain each visibly supplied context and BB910 r1=14.
 */
void func_021BB84C(u8 *p)
{
    func_021BC688((char *)p);
    func_021BD5E0((unsigned)p);
    func_021BD56C((int *)p);
    func_021BD520((int *)p);
    func_021C09E0(*(unsigned *)p);
    func_021C09EC(*(unsigned *)p);
    func_021BD4CC((unsigned)p);
    func_021BD370((int *)p);
    func_021BD458((int *)p);
    func_021BD3A4(p);
    func_021BD05C((int *)p);
    func_021BCF98((int *)p);
    func_021BCE5C((unsigned)p);
    func_021BCF20((unsigned)p);
    func_021BCD90(p);
    func_021BCC58((unsigned)p);
    func_021BCBCC(p);
    func_021BCC3C(p);
    func_021BCB60((unsigned)p);
    func_021BCB44(p);
    func_021BCAC0(p);
    func_021BC924((int *)p);
    func_021BC8D8(p);
    func_021BB940(p, 0);
    func_021BB91C(p);
    func_021BB910(p, 14);
    ((struct ResearchTop *)p)->f164 = 1;
    *(volatile unsigned *)0x04000000 &= 0xffff1fff;
}






void func_021BB908(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x24);
    *c += 1;
}






void func_021BB910(u8 *a0, u32 a1)
{
    func_021C0E4C((u32)(((struct ResearchTop *)a0)->f18), a1);
}






/*
 * Set the u32 at +0x158 to 1.
 *
 * Addresses are Black-image addresses.
 */
void func_021BB91C(void *p)
{
    ((struct ResearchTop *)p)->f158 = 1;
}






/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to func_021C09CC.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BB928(u8 *a0)
{
    return func_021C09CC((void *)((u32)(((struct ResearchTop *)a0)->f0)));
}






void func_021BB934(u8 *a0, u32 a1)
{
    func_021C09C4(*(u8 * *)&((struct ResearchTop *)a0)->f0, a1);
}




/*
 * Field setter, u32 at +0x168.
 *
 * Addresses are Black-image addresses.
 */
void func_021BB940(void *p, u32 v)
{
    ((struct ResearchTop *)p)->f168 = v;
}





u32 func_021BB948(u8 *a0)
{
    return ((struct ResearchTop *)a0)->f28;
}



/*
 * Same guard shape as 021BA158 on the +0x158 word, handing the +0x18
 * handle to func_021BB978.
 *
 * Addresses are Black-image addresses.
 */
void func_021BB94C(u32 a0)
{
    if (((struct ResearchTop *)a0)->f158 != 0) {
    if (func_021C0E64(((struct ResearchTop *)a0)->f18) == 0) {
    func_021BB978((char *)a0, func_021C0E54((struct Ring *)(((struct ResearchTop *)a0)->f18)));
    }
    }
}




u32 func_021BB974(void *p)
{
    return ((struct ResearchTop *)p)->f1C;
}




int func_021BB978(char *p, int a1)
{
    int off = 0x56;
    ((struct ResearchTop *)p)->f1C = a1;
    ((struct ResearchTop *)p)->f24 = 0;
    *(int *)(p + (off << 2)) = 0;
    return (int)func_021BB998(p);
}




u32 func_021BB98C(void *p)
{
    return ((struct ResearchTop *)p)->f20;
}




void func_021BB990(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x20);
    *c += 1;
}




/*
 * Unlabelled Thumb leaf in a .word run:
 *   movs r1,#0; str r1,[r0,#0x20]; bx lr
 * Clears the word at p+0x20.
 */
void *func_021BB998(void *p)
{
    ((struct ResearchTop *)p)->f20 = 0;
    return p;
}



void func_021BB9A0(u32 a0)
{
    func_021BBD28(a0, ((struct ResearchTop *)a0)->f2C);
    func_021BBCFC((void *)a0, -1);
    func_021BBD18(a0, ((struct ResearchTop *)a0)->f2C);
    func_020061E4(1352);
    func_021BC580((char *)a0, 4);
}



void func_021BB9D0(u32 a0)
{
    func_021BBD28(a0, ((struct ResearchTop *)a0)->f2C);
    func_021BBCFC((void *)a0, 1);
    func_021BBD18(a0, ((struct ResearchTop *)a0)->f2C);
    func_020061E4(1352);
    func_021BC580((char *)a0, 4);
}



void func_021BBA00(u32 a0, u32 a1)
{
    func_021BBD28(a0, ((struct ResearchTop *)a0)->f2C);
    func_021BBD14((void *)a0, a1);
    func_021BBD18(a0, ((struct ResearchTop *)a0)->f2C);
    func_020061E4(1352);
    func_021BC580((char *)a0, 4);
}



/*
 * arity: BC400 forwards entry r0 into BC3F8, so retain supplied argument despite legacy void. BC3EC overwrites r1 with 24 and tail-calls signed division; legacy trailing a1 neither read nor forwarded.
 */
void func_021BBA30(u8 *p)
{
    int low, high, left, right;
    u8 index;
    low = func_021BC3D4();
    high = func_021BC3E0();
    left = func_021BC3F8(p[0x32]);
    right = func_021BC400(p[0x32]);
    if (right <= low) {
        index = func_021BC3EC(right + 1);
        if (((struct ResearchTop *)p)->f160) func_021BBAA4((unsigned)p, index);
        else func_021BBD38(p, index);
    }
    if (high <= left) {
        index = func_021BC3EC(left - 1);
        if (((struct ResearchTop *)p)->f160) func_021BBAA4((unsigned)p, index);
        else func_021BBD38(p, index);
    }
}



void func_021BBAA4(u32 a0, u8 a1)
{
    func_021BBDAC((u8 *)a0);
    func_021BBD38((void *)a0, a1);
    func_021BBD68((u8 *)a0);
    func_020061E4(1352);
    func_021BC580((char *)a0, 1);
}



/*
 * Reconstructed from the listing.
 *
 * evidence: func_021BC574 is ov217's own code ("ldr r0, [r0]; ldr r3,
 * =func_021C09D8; bx r3" after the pop at 0x021BC570), inside ov217's window,
 * so only ov217 can be resident there when this pool word is used.  Its start
 * is seeded in layout/function_starts.txt from this pointer word, the only
 * reference; it attests as sole-ref/code from ov217's own listing.  The old
 * hint ov209 named a different overlay's function mapped over the address.
 *
 * Addresses are Black-image addresses.
 */
void func_021BBAD0(u32 a0)
{
    func_021BC574((u8 **)a0, 0);
}



void func_021BBADC(u8 *p)
{
    int start, end, low, high, step, low2, high2;
    start = ((struct ResearchTop *)p)->f34;
    if (p[0x32] < p[0x33]) end = func_021BC400(p[0x33]) + 1;
    else end = func_021BC3F8(p[0x33]);
    low = func_021BC3D4();
    high = func_021BC3E0();
    if (end < low || high < end) {
        if (start < end) start = high;
        else start = low;
    }
    step = ((start >= end ? start : end) - (start <= end ? start : end)) / 4;
    low2 = func_021BC3D4();
    high2 = func_021BC3E0();
    if (low2 <= start && start <= high2 && low2 <= end && end <= high2) step = 0;
    func_021BC2CC(p, start, end, step);
}



void func_021BBB60(u8 *p)
{
    int start, end, step, low, high, low2, high2;
    start = ((struct ResearchTop *)p)->f34;
    end = start;
    if ((int)func_021BC41C(p) < start) end = func_021BC40C(p) + 24;
    else if (start < 0) end = 144;
    low = func_021BC3D4();
    high = func_021BC3E0();
    if (end < low || high < end) {
        if (start < end) start = high;
        else start = low;
    }
    step = ((start >= end ? start : end) - (start <= end ? start : end)) / 3;
    low2 = func_021BC3D4();
    high2 = func_021BC3E0();
    if (low2 <= start && start <= high2 && low2 <= end && end <= high2) step = 1;
    func_021BC2CC(p, start, end, step);
}



void func_021BBBE4(u8 *p)
{
    int center, target, start, end;
    center = (int)(func_021BC3D4() + func_021BC3E0()) / 2;
    target = func_021BBF1C((unsigned)p, p[0x32]) * 8;
    if (center < target) {
        start = func_021BC3E0();
        end = (target - center) + func_021BC3E0();
    } else {
        start = func_021BC3D4();
        end = func_021BC3D4() - (center - target);
    }
    func_021BC2CC(p, start, end, ((start >= end ? start : end) - (start <= end ? start : end)) / 3);
}



u8 func_021BBC50(u8 *p)
{
    u8 values[3];
    int i;
    void *data;
    u8 a, b, c, index;
    data = func_0200E394(func_02012EBC((struct Big *)func_021BC628(p)));
    for (i = 0; i < 3; i++) values[i] = func_0200E44C((int)data, i);
    a = values[0];
    b = values[1];
    c = values[2];
    for (index = 0; index < 10; index++)
        if (a == d_021C30A8[index] && b == d_021C3080[index] && c == d_021C308A[index]) return index;
    return 0;
}



/*
 * blocker C: typedef unsigned char u8; void func_0200E440(u8 *p,int value,int index) { (p+index)[640]=value; }
 * arity: BC628 returns C09B4's +8 pointer; E394 returns 071CC's pointer, both used live despite legacy void declarations.
 */
void func_021BBCB0(u8 *p)
{
    u32 index;
    int data;
    index=func_021BC6E4(p);
    data=(int)func_0200E394((void *)((int)func_02012EBC((struct Big *)func_021BC628(p))));
    func_0200E440((u8 *)data,d_021C30A8[index],0);
    func_0200E440((u8 *)data,d_021C3080[index],1);
    func_0200E440((u8 *)data,d_021C308A[index],2);
}




/*
 * Advance the u32 at +0x2c by the argument plus two, reduced modulo two.
 *
 * Addresses are Black-image addresses.
 */
void func_021BBCFC(void *p, s32 v)
{
    *(s32 *)&((struct ResearchTop *)p)->f2C = (*(s32 *)&((struct ResearchTop *)p)->f2C + v + 2) % 2;
}




/*
 * Field setter, u32 at +0x2c.
 *
 * Addresses are Black-image addresses.
 */
void func_021BBD14(void *p, u32 v)
{
    ((struct ResearchTop *)p)->f2C = v;
}




void func_021BBD18(int a, int b)
{
    BMP_OAM_SetPalette((u8 *)func_021BC740((char *)a, b), 0);
}




void func_021BBD28(int a, int b)
{
    BMP_OAM_SetPalette((u8 *)func_021BC740((char *)a, b), 1);
}




/*
 * Field setter, u8 at +0x32.
 *
 * Addresses are Black-image addresses.
 */
void func_021BBD38(void *p, u8 v)
{
    ((struct ResearchTop *)p)->f32 = v;
}




void func_021BBD40(u8 *p, int a)
{
    int base = p[0x32];
    int x = (int)func_021BC6DC(p);
    int s = base + a;
    p[0x33] = (u8)((s + x) % (int)func_021BC6DC(p));
}



void func_021BBD68(u8 *p)
{
    u8 slot;
    u32 x;
    u32 y;
    slot=p[0x32];
    x=func_021BBF04((u32)p,slot);
    y=func_021BBF1C((u32)p,slot);
    func_020413B0(2,x,y,28,3,10);
    func_02041B6C(2);
    ((struct ResearchTop *)p)->f160=1;
}



void func_021BBDAC(u8 *p)
{
    u8 slot;
    u32 x;
    u32 y;
    slot=p[0x32];
    x=func_021BBF04((u32)p,slot);
    y=func_021BBF1C((u32)p,slot);
    func_020413B0(2,x,y,28,3,9);
    func_02041B6C(2);
    ((struct ResearchTop *)p)->f160=0;
}



void func_021BBDF0(u32 object,u32 slot)
{
    u16 *first;
    int row;
    u16 *second;
    int column;
    Index index;
    int base,destination;
    first=(u16 *)func_0204162C(2);
    second=(u16 *)func_0204162C(3);
    for(row=0;row<3;row++) {
        for(column=0;column<28;column++) {
            base=func_021BBF1C(object,slot);
            index=column+2+(base+row)*32;
            destination=index-1;
            first[destination]=first[index];
            second[destination]=second[index];
        }
    }
    base=func_021BBF1C(object,slot);
    first[base*32+29]=first[0];
    second[base*32+29]=second[0];
    first[(base+1)*32+29]=first[0];
    second[(base+1)*32+29]=second[0];
    first[(base+2)*32+29]=first[0];
    second[(base+2)*32+29]=second[0];
    func_02041B6C(2);
    func_02041B6C(3);
}



void func_021BBE7C(u32 object,u32 slot)
{
    u16 *first;
    int row;
    u16 *second;
    int column;
    Index index;
    int base,destination;
    first=(u16 *)func_0204162C(2);
    second=(u16 *)func_0204162C(3);
    for(row=2;row>=0;row--) {
        for(column=27;column>=0;column--) {
            base=func_021BBF1C(object,slot);
            index=column+1+(base+row)*32;
            destination=index+1;
            first[destination]=first[index];
            second[destination]=second[index];
        }
    }
    base=func_021BBF1C(object,slot);
    first[base*32+1]=first[0];
    second[base*32+1]=second[0];
    first[(base+1)*32+1]=first[0];
    second[(base+1)*32+1]=second[0];
    first[(base+2)*32+1]=first[0];
    second[(base+2)*32+1]=second[0];
    func_02041B6C(2);
    func_02041B6C(3);
}













/*
 * Returns 2, or 1 when func_021BBC50() reports the caller's own a1.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BBF04(u32 a0, u32 a1)
{
    u8 v = 2;
    if (a1 == func_021BBC50((u8 *)a0)) {
    v -= 1;
    }
    return v;
}














u32 func_021BBF1C(u32 unused, u32 v)
{
    return (u8)(v * 3);
}














int func_021BBF28(unsigned char *p, unsigned int slot)
{
    int t = func_021BBF04((unsigned int)p, slot) << 3;
    return t - func_02041648(2);
}














int func_021BBF3C(unsigned char *p, unsigned char index)
{
    int t = func_021BBF1C((unsigned int)p, index) << 3;
    return t - func_021BC3AC();
}














int func_021BBF4C(unsigned char *p, unsigned int index)
{
    int t = (func_021BBF1C((unsigned int)p, index) << 3) + 0x17;
    return t - func_021BC3AC();
}













static inline void outside(Plane wnd,Bool effect)
{
    u32 tmp;
    tmp=(*(volatile u16 *)0x0400004A & ~63u) | (u32)wnd;
    if(effect)tmp|=32;
    *(volatile u16 *)0x0400004A=(u16)tmp;
}













static inline void inside(Plane wnd,Bool effect)
{
    u32 tmp;
    tmp=(*(volatile u16 *)0x04000048 & ~63u) | (u32)wnd;
    if(effect)tmp|=32;
    *(volatile u16 *)0x04000048=(u16)tmp;
}













void func_021BBF60(u8 *p)
{
    int active;
    int top,bottom;
    int x1,x2,y1,y2;
    active=0;
    top=func_021BBF3C(p,0);
    bottom=func_021BBF4C(p,9);
    if(top>0) {
        active=1;x1=0;x2=240;y1=0;y2=top-1;
    } else if(bottom<192) {
        active=1;x1=0;x2=240;y1=bottom+1;y2=192;
    }
    if(active) {
        *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000 & 0xFFFF1FFF)|0x2000;
        *(volatile u16 *)0x04000040=(u16)(((x1<<8)&0xFF00)|(x2&0xFF));
        *(volatile u16 *)0x04000044=(u16)(((y1<<8)&0xFF00)|(y2&0xFF));
        outside(PLANE_OUT,TRUE);
        inside(PLANE_IN,TRUE);
    } else {
        *(volatile u32 *)0x04000000=*(volatile u32 *)0x04000000 & 0xFFFF1FFF;
    }
}













/*
 * arity: BF28/BF3C forward entry r0/r1 to BF04/BF1C; preserve both, with observed u8 argument truncation.
 */
void func_021BC014(u8 *p)
{
    struct Vec2 point;
    u32 index;
    struct Obj *obj;
    index=func_021BBC50(p);
    obj=(struct Obj *)func_021BC720(p,2);
    if(index==255) {
        func_0204B3DC(obj,0);
        return;
    }
    point.x=func_021BBF28(p,(u8)index);
    point.y=func_021BBF3C(p,index)+10;
    func_0204B404(obj,&point,0);
    func_0204B92C(obj,1);
    func_0204B3DC(obj,1);
}














int func_021BC06C(char *p)
{
    return func_021BC07C((u8 *)p, ((struct ResearchTop *)p)->f32);
}













/*
 * arity: original visibly supplies r1 to C0F5C; preserve second argument omitted by legacy source.
 */
int func_021BC07C(u8 *p, u8 index)
{
    func_021C0F5C(((struct ResearchTop *)p)->fE4,d_021C309E[index]);
    func_021C0F5C(((struct ResearchTop *)p)->fE8,d_021C3094[index]);
    func_021C0F5C(((struct ResearchTop *)p)->fEC,d_021C30D0[d_021C30A8[index]]);
    func_021C0F5C(((struct ResearchTop *)p)->fF0,d_021C30D0[d_021C3080[index]]);
    return func_021C0F5C(((struct ResearchTop *)p)->fF4,d_021C30D0[d_021C308A[index]]);
}













void func_021BC0E8(u32 a0)
{
    func_021C0FF8((u8 *)(((struct ResearchTop *)a0)->fE4), 0);
    func_021C0FF8((u8 *)(((struct ResearchTop *)a0)->fE8), 0);
    func_021C0FF8((u8 *)(((struct ResearchTop *)a0)->fEC), 0);
    func_021C0FF8((u8 *)(((struct ResearchTop *)a0)->fF0), 0);
    func_021C0FF8((u8 *)(((struct ResearchTop *)a0)->fF4), 0);
}













void func_021BC128(u32 a0)
{
    func_021C0FF8((u8 *)(((struct ResearchTop *)a0)->fE4), 1);
    func_021C0FF8((u8 *)(((struct ResearchTop *)a0)->fE8), 1);
    func_021C0FF8((u8 *)(((struct ResearchTop *)a0)->fEC), 1);
    func_021C0FF8((u8 *)(((struct ResearchTop *)a0)->fF0), 1);
    func_021C0FF8((u8 *)(((struct ResearchTop *)a0)->fF4), 1);
}













/*
 * Packs a 0xF8 message (second halfword from func_021BC1AC()) and pushes
 * it through the +0x0c channel, on the path where func_021BC428() is clear.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC168(u32 a0)
{
    u8 s[4];
    u32 v1 = func_021BC720((void *)a0, 0);
    if (func_021BC428((void *)a0) == 0) {
    func_0204B3DC((struct Obj *)v1, 0);
    return;
    }
    ((struct Obj00801 *)((u8*)s))->f0 = 248;
    *(u16 *)&((struct Obj00801 *)(((u8*)s)))->f2 = func_021BC1AC((void *)a0);
    func_0204B404((struct Obj *)v1, (const struct Vec2 *)s, 0);
    func_0204B3DC((struct Obj *)v1, 1);
}













/*
 * 021BC40C forwards live r0 to 021BC6DC's +0x30 getter despite legacy void prototype.
 */
int func_021BC1AC(void *p)
{
    int scroll;
    int height;
    float top;
    float span;
    int result;
    scroll=func_021BC3AC();
    height=func_021BC40C(p);
    scroll+=24;
    height+=24;
    top=(float)scroll;
    span=(float)height;
    result=(int)(32.0f+128.0f*(top/span));
    if(result<32)result=32;
    if(result>160)result=160;
    return result;
}













int func_021BC200(void *p,int position)
{
    float ratio;
    int height;
    float zero;
    Origin origin;
    if(position<32)position=32;
    if(position>160)position=160;
    ratio=(float)(position-32)/128.0f;
    height=func_021BC40C(p)+24;
    origin=ZERO;
    zero=(float)origin;
    return (int)(zero+ratio*(float)height);
}














/*
 * Accumulate +0x50 into +0x4c, zeroing the total when the product is not positive.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC250(void *p)
{
    s32 a = *(u32 *)&((struct ResearchTop *)p)->f4C;
    s32 b = ((struct ResearchTop *)p)->f50;
    s32 t = a + b;
    if (a * t <= 0) {
        t = 0;
    }
    *(u32 *)&((struct ResearchTop *)p)->f4C = t;
}














/*
 * Flag test: nonzero u32 at +0x4c as 1/0.
 *
 * Addresses are Black-image addresses.
 */
int func_021BC264(void *p)
{
    if (((struct ResearchTop *)p)->f4C != 0) {
        return 1;
    }
    return 0;
}














void func_021BC274(void *p)
{
    int a = *(u32 *)&((struct ResearchTop *)p)->f34;
    int b = ((struct ResearchTop *)p)->f38;
    *(u32 *)&((struct ResearchTop *)p)->f4C = a - b;
}














void func_021BC280(struct ResearchTop *p)
{
    double d = p->f4C;
    int v;
    d *= 1.5;
    v = d;
    p->f4C = v;
    if (v > 9) {
        p->f4C = 9;
    } else if (v < -9) {
        p->f4C = -9;
    }
}














void func_021BC2B8(void *p)
{
    if (((struct ResearchTop *)p)->f4C < 0) {
        ((struct ResearchTop *)p)->f50 = 1;
    } else {
        ((struct ResearchTop *)p)->f50 = -1;
    }
}














void func_021BC2CC(void *p, u32 a, u32 b, u32 c)
{
    ((struct ResearchTop *)p)->f3C = a;
    ((struct ResearchTop *)p)->f40 = b;
    *(u32 *)&((struct ResearchTop *)p)->f44 = c;
    *(u32 *)&((struct ResearchTop *)p)->f48 = 0;
}














void func_021BC2D8(struct ResearchTop *p)
{
    int base = p->f3C;
    int n = p->f48 + 1;
    p->f48 = n;
    func_021BC330(p, base + (p->f40s - base) * n / p->f44);
}














int func_021BC2FC(void *p)
{
    if (((struct ResearchTop *)p)->f44 > ((struct ResearchTop *)p)->f48) {
        return 0;
    }
    return 1;
}














void func_021BC30C(struct ResearchTop *p, int v)
{
    if (v < 0) {
        v = 0;
    }
    if ((int)func_021BC41C(p) < v) {
        v = (int)func_021BC41C(p);
    }
    p->f38 = p->f34;
    p->f34 = v;
}














void func_021BC330(void *p, u32 v)
{
    ((struct ResearchTop *)p)->f38 = v;
    ((struct ResearchTop *)p)->f34 = v;
}













void func_021BC338(u8 *p)
{
    int position;
    int low;
    int high;
    position=((struct ResearchTop *)p)->f34;
    low=func_021BC3D4();
    high=func_021BC3E0();
    if(position<low) {
        position-=24;
        func_02041EE4(2,3,position);
        func_02041EE4(3,3,position);
    } else if(high<position) {
        position-=168;
        func_02041EE4(2,3,position);
        func_02041EE4(3,3,position);
    }
}














void func_021BC380(struct ResearchTop *p)
{
    int v = p->f34 - 24;
    if (v < -24) {
        v = -24;
    }
    if (func_021BC40C(p) < v) {
        v = func_021BC40C(p);
    }
    func_021BC3B8(v);
}














int func_021BC3AC(void)
{
    return func_02040804(2);
}













void func_021BC3B8(u32 a0)
{
    func_02040618(2, 3, a0);
    func_02040618(3, 3, a0);
}













u32 func_021BC3D4(void)
{
    return func_021BC3AC() + 24;
}













u32 func_021BC3E0(void)
{
    return func_021BC3AC() + 168;
}














/*
 * Tail-call veneer: forwards arg(s) a0, 24 to func_0209C0A4.
 *
 * Addresses are Black-image addresses.
 */
int func_021BC3EC(u32 a0)
{
    return func_0209C0A4(a0, 24);
}














/*
 * Twenty-four times the argument.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC3F8(u32 v)
{
    return v * 24;
}













u32 func_021BC400(u32 v)
{
    return func_021BC3F8(v) + 23;
}














int func_021BC40C(void *p)
{
    return (int)func_021BC6DC(p) * 0x18 - 0xa8;
}













u32 func_021BC41C(void *p)
{
    return func_021BC40C(p) + 168;
}














int func_021BC428(void *p)
{
    return (int)func_021BC6DC(p) * 0x18 > 0x90;
}













void func_021BC43C(u8 *p)
{
    int i;
    int x;
    int y;
    for(i=0;i<=9;i++) {
        x=func_021BBF28(p,(u8)i);
        y=func_021BBF3C(p,i);
        p[i*4+0x66]=x;
        p[i*4+0x67]=x+0xd8;
        p[i*4+0x64]=y;
        p[i*4+0x65]=y+0x18;
    }
}













void func_021BC480(void)
{
    func_0204E720(3, 16, 0, 0);
}













void func_021BC490(void)
{
    func_0204E720(3, 0, 16, 0);
}













/*
 * Returns 1 when ARM func_0204E804() is 0.
 *
 * Addresses are Black-image addresses.
 */
int func_021BC4A0(void)
{
    return func_0204E804() == 0;
}













void func_021BC4B4(char *p)
{
    PALANM_RequestFade(*(PalAnmObj * *)&((struct ResearchTop *)p)->f98, 1, 0xBBFF, 2, 0, 10, 0, ((struct ResearchTop *)p)->f150);
    PALANM_RequestFade(*(PalAnmObj * *)&((struct ResearchTop *)p)->f98, 4, 0xCF, 2, 0, 10, 0, ((struct ResearchTop *)p)->f150);
    ((struct ResearchTop *)p)->f15C = 1;
}













void func_021BC50C(char *p)
{
    PALANM_RequestFade(*(PalAnmObj * *)&((struct ResearchTop *)p)->f98, 1, 0xBBFF, 2, 10, 0, 0, ((struct ResearchTop *)p)->f150);
    PALANM_RequestFade(*(PalAnmObj * *)&((struct ResearchTop *)p)->f98, 4, 0xCF, 2, 10, 0, 0, ((struct ResearchTop *)p)->f150);
    ((struct ResearchTop *)p)->f15C = 0;
}













u32 func_021BC55C(u32 a0)
{
    if (PALANM_GetFadeRequestBits((const char *)(((struct ResearchTop *)a0)->f98)) == 0) {
    return 1;
    }
    return 0;
}














void func_021BC574(u8 **p, u32 i)
{
    func_021C09D8(*p, i);
}














void func_021BC580(char *p, int i)
{
    func_021C29F8((u8 *)(*(int *)(p + 0x9c + i * 4)), d_021C326C[i].a, d_021C326C[i].b);
}














/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 156)), (a1)*4 to func_021C2A00.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC5A8(u8 *a0, int a1)
{
    func_021C2A00((u32)(*(u32*)(a0 + (a1)*4 + 156)));
}













/*
 * Reports whether the a1-th entry of the +0x9c handle array is still
 * active.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC5B8(u32 a0, u32 a1)
{
    if (func_021C2A10(*(u32*)(((u8*)a0 + ((u32)a1 << 2) + 156))) == 0) {
    return 1;
    }
    return 0;
}














void func_021BC5D4(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        func_021C29F0(p[i + 0x27]);
}














void func_021BC5F0(u8 *a0)
{
    func_021C09D0((u32)(((struct ResearchTop *)a0)->f0));
}














u32 func_021BC5FC(void *p)
{
    return ((struct ResearchTop *)p)->f54;
}














/*
 * Increment the u32 at +0x54.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC600(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x54);
    *c += 1;
}














/*
 * Clear the u32 at +0x54.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC608(void *p)
{
    ((struct ResearchTop *)p)->f54 = 0;
}













void func_021BC610(u32 a0, u32 a1)
{
    func_020419E4();
    func_0204A648();
    PALANM_TransferPalettes((struct S02021D50 *)(((struct ResearchTop *)a1)->f98));
}














u32 func_021BC628(u8 *a0)
{
    return func_021C09B4((void *)((u32)(((struct ResearchTop *)a0)->f0)));
}














/*
 * Field setter, u16 at +8.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC634(void *p, u32 v)
{
    ((struct ResearchTop *)p)->f8 = v;
}














/*
 * Field setter, u32 at +0.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC638(void *p, u32 v)
{
    ((struct ResearchTop *)p)->f0 = v;
}














u32 func_021BC63C(void *p)
{
    return (u32)((struct ResearchTop *)p)->f0;
}














/*
 * Field setter, u32 at +4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC640(void *p, u32 v)
{
    ((struct ResearchTop *)p)->f4u = v;
}














void func_021BC644(struct ResearchTop *p)
{
    int v;
    if (p->f4 != 0) {
        v = func_021C0DF8(p->f4);
        if (v < -24) {
            v = -24;
        }
        if (v > 72) {
            v = 72;
        }
        func_021BC3B8(v);
        v = func_021C0DF4(p->f4);
        if (v < 0) {
            v = 0;
        }
        if (v > 240) {
            v = 240;
        }
        p->f34 = v;
        p->f32 = func_021C0DF0(p->f4);
    }
}













/*
 * Extent ends in two zero alignment bytes at 021BC6CE.
 * 021BC3AC is void in its source but forwards to 02040804. Original reads
 * r0 as a signed coordinate, so declare int and preserve its visible input.
 */
void func_021BC688(char *p)
{
    int y;
    if (*(u32 *)&((struct ResearchTop *)p)->f4 != 0) {
        y = func_021BC3AC();
        if (y < -24) y = -24;
        if (y > 72) y = 72;
        func_021C0E04(((struct ResearchTop *)p)->f4, y);
        y = ((struct ResearchTop *)p)->f34;
        if (y < 0) y = 0;
        if (y > 240) y = 240;
        func_021C0E00(((struct ResearchTop *)p)->f4, y);
        func_021C0DFC(((struct ResearchTop *)p)->f4, ((struct ResearchTop *)p)->f32);
    }
}













u32 func_021BC6D0(void *p)
{
    return func_021C09F8((void *)func_021BC63C(p));
}














u32 func_021BC6DC(void *p)
{
    return ((struct ResearchTop *)p)->f30;
}














/*
 * Field getter, u8 at +0x31.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC6E4(void *p)
{
    return ((struct ResearchTop *)p)->f31;
}














void func_021BC6EC(void *p, u8 v)
{
    ((struct ResearchTop *)p)->f31 = v;
}













u32 func_021BC6F4(u32 a0, u32 a1)
{
    if (a1 < func_021BC6DC((void *)a0)) {
    return 1;
    }
    return 0;
}














/*
 * Indexed u32 read: element i of the table at +0xf8.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC708(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0xf8);
}














/*
 * Indexed u32 read: element i of the table at +0x114.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC714(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x114);
}














u32 func_021BC720(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x120);
}














void func_021BC72C(u8 *a0, u32 a1, u8 *a2)
{
    func_02025774((u8 *)((u32)(*(u32*)(a0 + (a1)*4 + 304))), (u32)(a2 + 0));
}














int func_021BC740(char *p, int i)
{
    return *(int *)(p + (d_021C3068[i] << 2) + 0x130);
}













u32 func_021BC758(u32 a0)
{
    return (u32)func_02030734(a0, 364, 0, (const char *)0x21C3FFC, 3687);
}













/*
 * Extent ends in two zero alignment bytes at 021BC816.
 */
void func_021BC774(u8 *p)
{
    ((struct ResearchTop *)p)->f4u = 0;
    ((struct ResearchTop *)p)->f1C = 0;
    ((struct ResearchTop *)p)->f24 = 0;
    ((struct ResearchTop *)p)->f158 = 0;
    ((struct ResearchTop *)p)->f28 = 15;
    p[0x32] = 0;
    p[0x33] = 0;
    p[0x30] = 0;
    ((struct ResearchTop *)p)->f2C = 0;
    p[0x31] = 255;
    ((struct ResearchTop *)p)->f150u = func_020056BC();
    ((struct ResearchTop *)p)->f34 = 0;
    ((struct ResearchTop *)p)->f38 = 0;
    ((struct ResearchTop *)p)->f3C = 0;
    ((struct ResearchTop *)p)->f40 = 0;
    ((struct ResearchTop *)p)->f44 = 0;
    ((struct ResearchTop *)p)->f48 = 0;
    ((struct ResearchTop *)p)->f15C = 0;
    ((struct ResearchTop *)p)->f160 = 0;
    ((struct ResearchTop *)p)->f168 = 0;
    ((struct ResearchTop *)p)->f164 = 0;
    ((struct ResearchTop *)p)->f154 = 0;
    func_021BC94C(p);
    func_021BC910(p);
    func_021BC8D0(p);
    func_021BCD6C(p);
    func_021BCF4C(p);
    func_021BCFB4(p);
    func_021BCDDC(p);
    func_021BD474(p);
    func_021BD078(p);
    func_021BD50C(p);
}














/*
 * Tail-call veneer: branch to func_020307B0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC818(void *a0)
{
    return func_020307B0(a0);
}













void func_021BC820(u8 *p)
{
    void *bitmap;
    int n;
    bitmap = (void *)func_0201296C((const struct BigObj *)func_021BC628(p));
    n = 1;
    if (func_020142E8(bitmap, 240) == 1) n++;
    if (func_020142E8(bitmap, 241) == 1) n++;
    if (func_020142E8(bitmap, 242) == 1) n++;
    if (func_020142E8(bitmap, 243) == 1) n++;
    if (func_020142E8(bitmap, 244) == 1) n++;
    if (func_020142E8(bitmap, 245) == 1) n++;
    if (func_020142E8(bitmap, 246) == 1) n++;
    if (func_020142E8(bitmap, 247) == 1) n++;
    if (func_020142E8(bitmap, 248) == 1) n++;
    p[0x30] = n;
}













void func_021BC8B4(u32 a0)
{
    u8 s[4];
    *(u32 *)&((struct ResearchTop *)a0)->fCp = (u32)func_0201D7EC(23, 0, 0, 0, (u32)(((struct ResearchTop *)a0)->f8));
}














/*
 * Clear the u32 at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC8D0(void *p)
{
    ((struct ResearchTop *)p)->fC = 0;
}














/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 12)) to func_0201D83C.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC8D8(u8 *a0)
{
    func_0201D83C((void *)((u32)(((struct ResearchTop *)a0)->fC)));
}














void func_021BC8E4(struct ResearchTop *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        p->arr[i] = (int)func_02045B38(0, 2, (u16)d_021C3078[i], p->f8);
    }
}














void func_021BC910(void *p)
{
    int i;
    for (i = 0; i < 2; i++)
        *(u32 *)((char *)p + i * 4 + 0x10) = 0;
}














void func_021BC924(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        func_02045C04((struct Rec *)p[i + 4]);
}













void func_021BC93C(u32 a0)
{
    ((struct ResearchTop *)a0)->f18 = func_021C0E08(10, ((struct ResearchTop *)a0)->f8);
}














/*
 * Clear the u32 at +0x18.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC94C(void *p)
{
    ((struct ResearchTop *)p)->f18 = 0;
}














/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 24)) to func_021C0E3C.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC954(u8 *a0)
{
    func_021C0E3C((void *)((u32)(((struct Obj25879 *)a0)->f18)));
}













/*
 * Pool +94 names 021C3190; no cross-overlay loading proof. Drop contested
 * ov217 token to use the sole-ref/data witness without swapping tables.
 */
void func_021BC960(u8 *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        p[i * 4 + 0x5A] = d_021C30B2[i * 4];
        p[i * 4 + 0x5B] = d_021C30B2[i * 4 + 1];
        p[i * 4 + 0x58] = d_021C30B2[i * 4 + 2];
        p[i * 4 + 0x59] = d_021C30B2[i * 4 + 3];
    }
    for (i = 0; i < 11; i++) {
        p[i * 4 + 0x66] = d_021C3190[i * 4];
        p[i * 4 + 0x67] = d_021C3190[i * 4 + 1];
        p[i * 4 + 0x64] = d_021C3190[i * 4 + 2];
        p[i * 4 + 0x65] = d_021C3190[i * 4 + 3];
    }
    for (i = 0; i < 2; i++) {
        p[i * 4 + 0x92] = d_021C3070[i * 4];
        p[i * 4 + 0x93] = d_021C3070[i * 4 + 1];
        p[i * 4 + 0x90] = d_021C3070[i * 4 + 2];
        p[i * 4 + 0x91] = d_021C3070[i * 4 + 3];
    }
}













void func_021BC9FC(char *p)
{
    func_0203FC28(&d_021C30C0);
    func_0203FCA0(6, &d_021C3110, 0);
    func_0203FCA0(7, &d_021C3130, 0);
    func_0203FCA0(0, &d_021C30F0, 0);
    func_0203FCA0(2, &d_021C3150, 0);
    func_0203FCA0(3, &d_021C3170, 0);
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_02040588(6, 1);
    func_02040588(7, 1);
    func_02040588(1, 1);
    func_02040588(0, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
    func_0207D63C((volatile unsigned *)0x04001050, 2, 1, 16, 5);
    func_0207D63C((volatile unsigned *)0x04000050, 4, 2, 16, 5);
    func_02045088(((struct ResearchTop *)p)->f8);
}













u32 func_021BCAC0(u8 *a0)
{
    func_020450C8();
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(0);
    func_020403F4(7);
    return func_020403F4(6);
}












/*
 * Original narrows the heap before 020490F4; its extern takes u16.
 */
void func_021BCAE8(char *p)
{
    void *arc;
    void *buf;
    void *screen;
    arc = func_020490F4(192, (u16)((((struct ResearchTop *)p)->f8 & 0x7FFF) | 0x8000));
    buf = func_02049250(arc, 13, ((struct ResearchTop *)p)->f8);
    func_02062B30(buf, &screen);
    func_02041090(6, (u32)((char *)screen + 12), 0, 0, 32, 24);
    func_02041B6C(6);
    func_020307B0(buf);
    func_02049238(arc);
}













void func_021BCB44(u8 *a0)
{
}












u32 func_021BCB48(u32 a0)
{
    func_02040C14(7, 0, 1, 0);
    return func_020414EC(7);
}













void func_021BCB60(u32 a0)
{
    func_02040DA8(7, 1, 0);
}












void func_021BCB70(char *p)
{
    void *arc;
    void *buf;
    void *screen;
    arc = func_020490F4(192, (u16)((((struct ResearchTop *)p)->f8 & 0x7FFF) | 0x8000));
    buf = func_02049250(arc, 3, ((struct ResearchTop *)p)->f8);
    func_02062B30(buf, &screen);
    func_02041090(0, (u32)((char *)screen + 12), 0, 0, 32, 24);
    func_02041B6C(0);
    func_020307B0(buf);
    func_02049238(arc);
}













/*
 * Empty stub.
 *
 * Addresses are Black-image addresses.
 */
void func_021BCBCC(u8 *a0)
{
}













void func_021BCBD0(struct ResearchTop *p)
{
    void *heap = func_020490F4(0xc0, (u16)((p->f8 & 0x7fff) | 0x8000));
    int v = func_021BC6DC(p) * 3;
    void *res = func_02049250(heap, 5, p->f8);
    char *q;
    func_02062B30(res, (void **)(&q));
    func_02041090(2, (u32)(q + 0xc), 0, 0, 0x20, (u8)v);
    func_02041B6C(2);
    func_020307B0(res);
    func_02049238(heap);
}













void func_021BCC3C(u8 *a0)
{
}












u32 func_021BCC40(u32 a0)
{
    func_02040C14(3, 0, 1, 0);
    return func_020414EC(3);
}













void func_021BCC58(u32 a0)
{
    func_02040DA8(3, 1, 0);
}













void func_021BCC68(struct ResearchTop *p)
{
    int i;
    for (i = 0; i < 7; i++) {
        const struct Ent_021BCAE8 *e = &d_021C33C8[i];
        struct Loc l1;
        l1.b0 = e->b0;
        l1.b1 = e->b1;
        l1.b2 = e->b2;
        l1.b3 = e->b3;
        l1.b4 = e->b4;
        l1.b5 = e->b5;
        l1.b6 = e->b6;
        l1.b7 = e->b7;
        l1.b8 = e->b8;
        l1.b9 = e->b9;
        l1.b10 = e->b10;
        l1.w = e->w;
        p->arr[0xdc / 4 - 4 + i] = (u32)func_021C0EF4((const struct Config *)(&l1), (u32)p->fC, p->arr[e->idx], p->f8);
        func_021C0F5C(p->arr[0xdc / 4 - 4 + i], e->arg);
    }
    for (i = 0; i < (int)func_021BC6DC(p); i++) {
        const struct Ent_021BCAE8 *e = &d_021C3520[i];
        struct Loc l2;
        l2.b0 = e->b0;
        l2.b1 = e->b1;
        l2.b2 = e->b2;
        l2.b3 = e->b3;
        l2.b4 = e->b4;
        l2.b5 = e->b5;
        l2.b6 = e->b6;
        l2.b7 = e->b7;
        l2.b8 = e->b8;
        l2.b9 = e->b9;
        l2.b10 = e->b10;
        l2.w = e->w;
        p->arr[0xb4 / 4 - 4 + i] = (u32)func_021C0EF4((const struct Config *)(&l2), (u32)p->fC, p->arr[e->idx], p->f8);
        func_021C0F5C(p->arr[0xb4 / 4 - 4 + i], e->arg);
    }
}













/*
 * Clear seven u32 slots at +0xdc, then ten at +0xb4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BCD6C(void *p)
{
    int i;
    for (i = 0; i < 7; i++)
        *(u32 *)((char *)p + i * 4 + 0xdc) = 0;
    for (i = 0; i < 10; i++)
        *(u32 *)((char *)p + i * 4 + 0xb4) = 0;
}












void func_021BCD90(u8 *p)
{
    int i;
    for (i = 0; i < 7; i++) {
        func_021C0F48(*(u8 **)(p + i * 4 + 0xDC));
        *(u32 *)(p + i * 4 + 0xDC) = 0;
    }
    for (i = 0; i < (int)func_021BC6DC(p); i++) {
        func_021C0F48(*(u8 **)(p + i * 4 + 0xB4));
        *(u32 *)(p + i * 4 + 0xB4) = 0;
    }
}













void func_021BCDDC(void *p)
{
    int i;
    for (i = 0; i < 7; i++)
        *(u32 *)((char *)p + i * 4 + 0xf8) = 0;
}











/*
 * 0204ABF0 is void in its source but forwards to the int-returning
 * 0204AC18; the original stores its live r0 result. 020490F4 narrows heap.
 */
void func_021BCDF0(char *p)
{
    u16 heap;
    void *arc;
    int a, b, c;
    heap = ((struct ResearchTop *)p)->f8;
    arc = func_020490F4(192, (u16)((heap & 0x7FFF) | 0x8000));
    a = func_0204A6C8((void *)((u32)arc), 15, 0, 1, heap);
    b = func_0204ABF0((void *)arc, 16, 1, 0, heap);
    c = func_0204AF28((void *)((u32)arc), 14, 17, heap);
    ((struct ResearchTop *)p)->f108 = a;
    ((struct ResearchTop *)p)->f10C = b;
    ((struct ResearchTop *)p)->f110 = c;
    func_02049238(arc);
}











u32 func_021BCE5C(u32 a0)
{
    func_0204A8D4(((struct ResearchTop *)a0)->f108);
    func_0204ADA4(((struct ResearchTop *)a0)->f10C);
    return func_0204AFD8(((struct ResearchTop *)a0)->f110);
}











void func_021BCE7C(char *p)
{
    u16 heap;
    void *arc;
    int a, b, c, d;
    heap = ((struct ResearchTop *)p)->f8;
    arc = func_020490F4(192, (u16)((heap & 0x7FFF) | 0x8000));
    a = func_0204A6C8((void *)((u32)arc), 15, 0, 0, heap);
    b = func_0204AC18((void *)((u32)arc), 16, 0, 192, 0, 4, heap);
    c = func_0204AF28((void *)((u32)arc), 14, 17, heap);
    func_02049238(arc);
    arc = func_020490F4(83, (u16)heap);
    d = func_0204AC18((void *)((u32)arc), 31, 0, 128, 0, 2, heap);
    func_02049238(arc);
    ((struct ResearchTop *)p)->fF8 = a;
    ((struct ResearchTop *)p)->fFC = b;
    ((struct ResearchTop *)p)->f100 = c;
    ((struct ResearchTop *)p)->f104 = d;
}










u32 func_021BCF20(u32 a0)
{
    func_0204A8D4(((struct ResearchTop *)a0)->fF8);
    func_0204ADA4(((struct ResearchTop *)a0)->fFC);
    func_0204AFD8(((struct ResearchTop *)a0)->f100);
    return func_0204ADA4(((struct ResearchTop *)a0)->f104);
}











void func_021BCF4C(void *p)
{
    int i;
    for (i = 0; i < 3; i++)
        *(u32 *)((char *)p + i * 4 + 0x114) = 0;
}











void func_021BCF68(struct ResearchTop *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        p->f114[i] = (int)func_0204B100(d_021C3060[i], d_021C305C[i], p->f8);
    }
}











void func_021BCF98(int *p)
{
    int i;
    for (i = 0; i < 3; i++)
        func_0204B1CC((struct Bank *)p[i + 0x45]);
}










void func_021BCFB4(void *p)
{
    int i;
    for (i = 0; i < 3; i++)
        *(u32 *)((char *)p + i * 4 + 0x120) = 0;
}









/*
 * Lever: const source table and destination base without the field offset.
 */
void func_021BCFD0(u8 *p)
{
    struct Arg arg;
    const struct Entry_021BBF04 *q;
    u8 *dest;
    int i;
    u32 a,b,c,d;
    for (i=0;i<3;i++) {
        q=&d_021C320C[i];
        arg.x=q->x; arg.y=q->y; arg.z=q->z; arg.a=q->a; arg.b=q->b;
        a=func_021BC714(p,q->c);
        b=func_021BC708(p,q->d);
        c=func_021BC708(p,q->e);
        d=func_021BC708(p,q->f);
        dest=p+i*4;
        ((struct Obj14733 *)dest)->f120=(u32)func_0204B294((void *)a,b,c,d,&arg,q->g,((struct ResearchTop *)p)->f8);
        func_0204B3DC((struct Obj *)((struct Obj14733 *)dest)->f120,0);
    }
}










void func_021BD05C(int *p)
{
    int i;
    for (i = 0; i < 3; i++)
        func_0204B3B4((struct Obj *)p[i + 0x48]);
}










void func_021BD078(void *p)
{
    int i;
    for (i = 0; i < 4; i++)
        *(u32 *)((char *)p + i * 4 + 0x140) = 0;
}








void func_021BD094(struct ResearchTop *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        p->f140[i] = (void *)func_02043678(d_021C3470[i].x, d_021C3470[i].y, d_021C3470[i].z, p->f8);
    }
}









void func_021BD0C4(u8 *p)
{
    const struct Entry_021C3470 *q;
    struct Bmp *bmp;
    void *text;
    u16 color;
    u8 *dest;
    int i;
    for(i=0;i<4;i++) {
        q=&d_021C3470[i];
        if(q->enabled) {
            bmp=func_0204384C(q->arc,q->member,0,((struct ResearchTop *)p)->f8);
            dest=p+i*4;
            func_020439A0(bmp,*(struct Bmp * *)&((struct Obj14734 *)dest)->f140,0,0,0,0,q->x<<3,q->y<<3,q->b);
            color=((q->r&31)<<10)|((q->g&31)<<5)|(q->b&31);
            text=func_02045EC0(*(struct MsgBank **)(p+16+q->bank*4),q->index);
            func_0201C7D0(((struct Obj14734 *)dest)->f140,q->px,q->py,text,((struct ResearchTop *)p)->fCp,color);
            func_020307B0(text);
            func_020437AC((struct Obj020437AC *)((int)bmp));
        }
    }
}









/*
 * Base address held in a u32 local and cast per use (reloads the pool word at each site); colour expression a | (c | b).
 */
void func_021BD178(struct ResearchTop *p)
{
    u32 gb = (u32)&d_021C349C;
    struct Tab tab = d_021C3350;
    int i;
    int j;
    void *heap;
    void *res;
    u16 color;
    heap = func_0204384C(GB->f20, GB->f24, 0, p->f8);
    for (i = 0; i < 3; i++) {
        int y = i * 8;
        for (j = 0; j < 10; j++) {
            func_020439A0(heap, p->f140[1], (tab.v[i][j] % 3) * 8, (tab.v[i][j] / 3) * 8, j * 8, y, 8, 8, 0);
        }
    }
    func_020437AC(heap);
    color = (GB->f1e & 0x1f) | (((GB->f1c & 0x1f) << 10) | ((GB->f1d & 0x1f) << 5));
    res = func_02045EC0((void *)p->arr[GB->f0c], GB->f10);
    func_0201C7D0(p->f140[1], (s16_021BD178)GB->f14, (s16_021BD178)GB->f18, res, (void *)p->fC, color);
    func_020307B0(res);
}








/*
 * Same lever as 021BD178: u32 base local cast per use, colour a | (c | b).
 */
void func_021BD274(struct ResearchTop *p)
{
    u32 gb = (u32)&d_021C34C8;
    struct Tab tab = d_021C32D8;
    int i;
    int j;
    void *heap;
    void *res;
    u16 color;
    heap = func_0204384C(GB->f20, GB->f24, 0, p->f8);
    for (i = 0; i < 3; i++) {
        int y = i * 8;
        for (j = 0; j < 10; j++) {
            func_020439A0(heap, p->f140[2], (tab.v[i][j] % 3) * 8, (tab.v[i][j] / 3) * 8, j * 8, y, 8, 8, 0);
        }
    }
    func_020437AC(heap);
    color = (GB->f1e & 0x1f) | (((GB->f1c & 0x1f) << 10) | ((GB->f1d & 0x1f) << 5));
    res = func_02045EC0((void *)p->arr[GB->f0c], GB->f10);
    func_0201C7D0(p->f140[2], (s16_021BD0C4)GB->f14, (s16_021BD0C4)GB->f18, res, (void *)p->fC, color);
    func_020307B0(res);
}


















void func_021BD370(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        func_020437AC((struct Obj020437AC *)p[i + 0x50]);
}


















void func_021BD38C(char *p)
{
    int i = 0x47;
    *(void **)(p + (i << 2) + 0x10) =
        func_02025538(((struct ResearchTop *)p)->f8, *(void **)(p + (i << 2)));
}


















void func_021BD3A4(u8 *a0)
{
    func_02025588((void *)((u32)(((struct ResearchTop *)a0)->f12C)));
}

















void func_021BD3B4(u8 *p)
{
    int sysOff,outOff,callOff,uploadOff;
    struct Param param;
    int i;
    const struct Entry_021BD0C4 *q;
    u8 *dest;
    sysOff=0x12C;
    outOff=0x130;
    callOff=0x130;
    uploadOff=0x130;
    for(i=0;i<4;i++) {
        dest=p+i*4;
        param.bmp=((struct Obj25887 *)dest)->f140;
        q=&d_021C31BC[i];
        param.x=q->x; param.y=q->y;
        param.f8=func_021BC708(p,q->f8);
        param.fc=q->fc;
        param.f10=q->f10; param.f11=q->f11;
        param.f12=q->f12; param.f14=q->f14;
        *(struct Grid **)(dest+outOff)=func_020255A0(*(struct Sys **)(p+sysOff),&param);
        func_02025774(*(u8 **)(dest+callOff),0);
        func_020257D0(*(struct Obj **)(dest+uploadOff));
    }
}


















void func_021BD458(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        func_0202570C((struct Grid *)p[i + 0x4C]);
}


















void func_021BD474(void *p)
{
    ((struct ResearchTop *)p)->f98 = 0;
}

















void func_021BD47C(u8 *p)
{
    *(struct PalAnmSlot * *)&((struct ResearchTop *)p)->f98 = func_02021518(((struct ResearchTop *)p)->f8);
    func_0202155C(*(struct PalAnmSlot * *)&((struct ResearchTop *)p)->f98, 0, 512, ((struct ResearchTop *)p)->f8);
    func_0202155C(*(struct PalAnmSlot * *)&((struct ResearchTop *)p)->f98, 2, 512, ((struct ResearchTop *)p)->f8);
    func_020216D4(*(struct PalAnmSlot * *)&((struct ResearchTop *)p)->f98, 0, 0, 512);
    func_020216D4(*(struct PalAnmSlot * *)&((struct ResearchTop *)p)->f98, 2, 0, 512);
}

















/*
 * Reconstructed from the listing (.inst decoded).
 *
 * BLOCKED at MATCH: the relocation site(s) below have no independent witness.
 *   +001E THM_CALL func_02021540       -> unresolved: 02021540 (arm, from name) has no witness outside 021BD4CC..021BD4F0
 * Promote automatically when the target is matched.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BD4CC(u32 a0)
{
    func_020215A0((struct PalAnmSlot *)(((struct ResearchTop *)a0)->f98), 0);
    func_020215A0((struct PalAnmSlot *)(((struct ResearchTop *)a0)->f98), 2);
    return func_02021540((void *)(((struct ResearchTop *)a0)->f98));
}


















void func_021BD4F0(char *p)
{
    int i;
    for (i = 0; i < 6; i++)
        ((int *)(p + 0x9c))[i] = func_021C29C8(((struct ResearchTop *)p)->f8);
}


















/*
 * Clear six u32 slots at +0x9c.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD50C(void *p)
{
    int i;
    for (i = 0; i < 6; i++)
        *(u32 *)((char *)p + i * 4 + 0x9c) = 0;
}


















void func_021BD520(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        func_021C29D8((void *)p[i + 0x27]);
}


















void func_021BD53C(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        func_021C29E8((void *)p[i + 0x27], d_021C3260[i].a, d_021C3260[i].b, d_021C3260[i].c);
}


















void func_021BD56C(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        func_021C2A08((char *)p[i + 0x27]);
}


















void func_021BD588(void *p)
{
    int obj = func_021BC720(p, 1);
    Pos pos;
    pos.x = 0x80;
    pos.y = 0x60;
    func_0204B404((struct Obj *)obj, (const struct Vec2 *)(&pos), 0);
    func_0204B3DC((struct Obj *)obj, 1);
}

















void func_021BD5B4(u32 a0)
{
    func_0203D34C(1, ((struct ResearchTop *)a0)->f8);
}


















void func_021BD5C4(char *p)
{
    ((struct ResearchTop *)p)->f154 = func_020056A0((void (*)(void))func_021BC610, p, 0);
}

















void func_021BD5E0(u32 a0)
{
    func_02030EAC((struct Node *)(((struct ResearchTop *)a0)->f154));
    ((struct ResearchTop *)a0)->f154 = 0;
}


















void *func_021BD5F4(void *p)
{
    void *r;
    void *a;
    a = (void *)func_021C09AC(p);
    r = (void *)func_021BFA14((u32)a);
    func_021BFA30(r);
    func_021BF74C(r, (u32)a);
    func_021BF754(r, (u32)p);
    return r;
}

















u32 func_021BD61C(void *a0)
{
    func_021BFB24((u8 *)a0);
    return func_021BFB04(a0);
}


















void func_021BD62C(unsigned char *p)
{
    switch (((struct ResearchObjB *)p)->f20) {
    case 0: func_021BD718(p); break;
    case 1: func_021BD868((u32)p); break;
    case 2: func_021BD89C(p); break;
    case 3: func_021BDC18(p); break;
    case 4: func_021BDF58(p); break;
    case 5: func_021BE040(p); break;
    case 6: func_021BE094((u32)p); break;
    case 7: func_021BE0D0((u32)p); break;
    case 8: func_021BE108((char *)p); break;
    case 9: func_021BE21C((char *)p); break;
    case 10: func_021BE33C((u32)p); break;
    case 11: func_021BE36C((u32)p); break;
    case 12: func_021BE384((u8 *)p); break;
    case 13: return;
    }
    func_021BF6D4((char *)p);
    func_021BF710(p);
    if (((struct ResearchObjB *)p)->f3C4 != 0) {
        func_0204A600(((struct ResearchObjB *)p)->f3C4);
        func_021BED9C((char *)p);
        func_021C20C4(((struct ResearchObjB *)p)->f2D0);
        func_021BF600(p);
        func_021BF5E4((int *)p);
        func_021BEDC4((char *)p);
        func_021BEDEC((char *)p);
        *(volatile unsigned int *)0x04000540 = 0;
    }
    func_021BE490(p);
    func_021BE4A4((u32)p);
}


















u32 func_021BD708(void *p)
{
    return ((struct ResearchObjB *)p)->f3E0;
}


















/*
 * Field getter, u32 at +0x3e4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BD710(void *p)
{
    return ((struct ResearchObjB *)p)->f3E4;
}


















void func_021BD718(unsigned char *p)
{
    int r;
    func_021BFB14((u32)p);
    func_021BFB38((u32)p);
    func_021BFB74((struct W *)p);
    func_021BFBC0((u32)p);
    func_021BFE40(p);
    func_021BEFF8(p);
    func_021BFF78();
    func_021BFFC8((char *)p);
    func_021C00AC((char *)p);
    func_021C00FC(p);
    func_021C0124((char *)p);
    func_021C0174(p);
    func_021C01B8((char *)p);
    func_021C0250((char *)p);
    func_021C02C8((char *)p);
    func_021C03A0(p);
    func_021C0408(p);
    func_021C04CC(p);
    func_021C04FC(p);
    func_021C05B0(p);
    func_021C06C8(p);
    func_021C06F0(p);
    func_021BFC60((char *)p);
    func_021BFBFC((char *)p);
    func_021BFE8C((char *)p);
    func_021BFF00((char *)p);
    func_021C07BC(p);
    func_021C083C(p);
    func_021C0878(p);
    func_021C08D4((char *)p);
    func_021C08C4((u32)p);
    func_021BF100((char *)p);
    func_021BF11C((char *)p);
    func_021BF13C((char *)p);
    func_021BF15C((char *)p);
    func_021BF264((char *)p);
    func_021BF2FC((char *)p);
    func_021BF38C((char *)p);
    func_021BF3B4((char *)p);
    func_021BF3D8((char *)p);
    func_021BF08C((char *)p);
    func_021BF47C((char *)p);
    func_021BF55C(p);
    func_021BF594((char *)p, 0);
    func_021BF594((char *)p, 7);
    func_021BEAF8(p);
    *(int *)&((struct ResearchObjB *)p)->f3C4 = 1;
    func_021BE8FC();
    r = func_021BE46C(p);
    func_021BE498(p, 1);
    func_021BE498(p, r);
    if (r == 3)
        func_021BE934((char *)p);
    func_021BE448(p);
}


















#pragma thumb on


















void func_021BD868(u32 a0)
{
    switch (func_021BE4DC((void *)a0)) {
    case 0:
        func_021C0918((u8 *)a0);
        func_021BE4E0((void *)a0);
        break;
    case 1:
        if (func_021C093C((u8 *)a0) != 0) {
            func_021BE448((void *)a0);
        }
        break;
    }
}


















void func_021BD89C(u8 *p)
{
    u32 keys;
    int hit;
    int sub;

    func_0203630C();
    keys = func_020362DC();
    hit = func_02035C08(p + 0x2FE);
    sub = func_02035C08(func_021C09B8(((struct ResearchObjB *)p)->f0));
    if (*(int *)&((struct ResearchObjB *)p)->f3C8 != 0 && ((struct ResearchObjB *)p)->f3D8 != 0 && *(int *)&((struct ResearchObjB *)p)->f3D4 != 0) {
        func_021BE448(p);
        func_021BE498(p, 8);
        func_021BE498(p, 6);
        func_021BE498(p, 7);
        func_021BE498(p, 5);
        func_021BE498(p, 2);
        return;
    }
    if (func_021BF758(p) != 0 || sub == 0) {
        func_021BE454(p, 1);
        func_021BEC00((u32 *)p);
        func_020061E4(0x551);
        func_021BE448(p);
        func_021BE498(p, 11);
        func_021BE498(p, 10);
        func_021BE498(p, 12);
        return;
    }
    if ((keys & 0x40) || (keys & 0x80) || (keys & 0x20) || (keys & 0x10) || (keys & 1)) {
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
        return;
    }
    if (hit == 6 && *(int *)&((struct ResearchObjB *)p)->f3C8 == 0 && func_021BF810(p) != 0) {
        ((struct ResearchObjB *)p)->f3CC = 1;
        func_021BEB40((u32)p);
        func_021BE448(p);
        func_021BE498(p, 4);
        func_021BE498(p, 6);
        func_021BE498(p, 7);
        func_021BE498(p, 5);
        func_021BE498(p, 2);
    } else if (hit == 7) {
        if (*(int *)&((struct ResearchObjB *)p)->f3C8 == 0 && func_021BF810(p) != 0) {
            ((struct ResearchObjB *)p)->f3CC = 1;
            func_021BEB40((u32)p);
            func_021BE448(p);
            func_021BE498(p, 4);
            func_021BE498(p, 6);
            func_021BE498(p, 7);
            func_021BE498(p, 5);
            func_021BE498(p, 2);
        } else {
            func_020061E4(0x557);
        }
    } else if (hit == 2) {
        if (*(int *)&((struct ResearchObjB *)p)->f3C8 == 0 && func_021BF810(p) != 0) {
            ((struct ResearchObjB *)p)->f3CC = 1;
            func_021BEB40((u32)p);
            func_021BE448(p);
            func_021BE498(p, 4);
            func_021BE498(p, 6);
            func_021BE498(p, 7);
            func_021BE498(p, 5);
            func_021BE498(p, 2);
        } else {
            func_021BE614((u32)p, 0);
        }
    } else if (*(int *)&((struct ResearchObjB *)p)->f3C8 != 0 && func_021BF810(p) != 0 && hit == 3) {
        func_021BE614((u32)p, 1);
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
    } else if (*(int *)&((struct ResearchObjB *)p)->f3C8 != 0 && func_021BF810(p) != 0 && hit == 4) {
        func_021BE614((u32)p, 2);
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
    } else if (hit == 5) {
        func_021BE614((u32)p, 3);
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
    } else if (hit == 0) {
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
        switch (*(int *)&((struct ResearchObjB *)p)->f34) {
        case 0: func_021BE704((char *)p); break;
        case 1: func_021BE7B4((u32)p); break;
        case 3: func_021BE808((char *)p); break;
        }
    } else if (hit == 1) {
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
        switch (*(int *)&((struct ResearchObjB *)p)->f34) {
        case 0: func_021BE678((char *)p); break;
        case 1: func_021BE790((u32)p); break;
        case 3: func_021BE808((char *)p); break;
        }
    } else if (keys & 2) {
        func_021BE454(p, 0);
        func_021BEC00((u32 *)p);
        func_020061E4(0x551);
        func_021BE448(p);
        func_021BE498(p, 11);
        func_021BE498(p, 10);
        func_021BE498(p, 12);
    }
}


















void func_021BDC18(u8 *p)
{
    u32 keys;
    int hit;
    int sub;

    func_0203630C();
    keys = func_020362DC();
    hit = func_02035C08(p + 0x2FE);
    sub = func_02035C08(func_021C09B8(((struct ResearchObjB *)p)->f0));
    if (*(int *)&((struct ResearchObjB *)p)->f3C8 != 0 && ((struct ResearchObjB *)p)->f3D8 != 0 && *(int *)&((struct ResearchObjB *)p)->f3D4 != 0) {
        func_021BE448(p);
        func_021BE498(p, 9);
        func_021BE498(p, 6);
        func_021BE498(p, 7);
        func_021BE498(p, 5);
        func_021BE498(p, 3);
        return;
    }
    if (func_021BF758(p) != 0 || sub == 0) {
        func_021BE454(p, 1);
        func_021BEC00((u32 *)p);
        func_020061E4(0x551);
        func_021BE448(p);
        func_021BE498(p, 11);
        func_021BE498(p, 10);
        func_021BE498(p, 12);
        return;
    }
    if (keys & 0x40) {
        func_021BE4E8(p);
    } else if (keys & 0x80) {
        func_021BE580(p);
    } else if (hit == 6 && *(int *)&((struct ResearchObjB *)p)->f3C8 == 0 && func_021BF810(p) != 0) {
        ((struct ResearchObjB *)p)->f3CC = 1;
        func_021BEB40((u32)p);
        func_021BE448(p);
        func_021BE498(p, 4);
        func_021BE498(p, 6);
        func_021BE498(p, 7);
        func_021BE498(p, 5);
        func_021BE498(p, 2);
    } else if (hit == 7) {
        if (*(int *)&((struct ResearchObjB *)p)->f3C8 == 0 && func_021BF810(p) != 0) {
            ((struct ResearchObjB *)p)->f3CC = 1;
            func_021BEB40((u32)p);
            func_021BE448(p);
            func_021BE498(p, 4);
            func_021BE498(p, 6);
            func_021BE498(p, 7);
            func_021BE498(p, 5);
            func_021BE498(p, 2);
        } else {
            func_020061E4(0x557);
        }
    } else if (hit == 2) {
        if (*(int *)&((struct ResearchObjB *)p)->f3C8 == 0 && func_021BF810(p) != 0) {
            ((struct ResearchObjB *)p)->f3CC = 1;
            func_021BEB40((u32)p);
            func_021BE448(p);
            func_021BE498(p, 4);
            func_021BE498(p, 6);
            func_021BE498(p, 7);
            func_021BE498(p, 5);
            func_021BE498(p, 2);
        } else {
            func_021BE614((u32)p, 0);
        }
    } else if (*(int *)&((struct ResearchObjB *)p)->f3C8 != 0 && func_021BF810(p) != 0 && hit == 3) {
        func_021BE614((u32)p, 1);
    } else if (*(int *)&((struct ResearchObjB *)p)->f3C8 != 0 && func_021BF810(p) != 0 && hit == 4) {
        func_021BE614((u32)p, 2);
    } else if (hit == 5) {
        func_021BE614((u32)p, 3);
    } else if ((keys & 0x20) || hit == 0) {
        switch (*(int *)&((struct ResearchObjB *)p)->f34) {
        case 0: func_021BE704((char *)p); break;
        case 1: func_021BE7B4((u32)p); break;
        case 3: func_021BE808((char *)p); break;
        }
    } else if ((keys & 0x10) || hit == 1) {
        switch (*(int *)&((struct ResearchObjB *)p)->f34) {
        case 0: func_021BE678((char *)p); break;
        case 1: func_021BE790((u32)p); break;
        case 3: func_021BE808((char *)p); break;
        }
    } else if ((keys & 1) && *(int *)&((struct ResearchObjB *)p)->f3C8 == 0 && func_021BF810(p) != 0
               && (*(int *)&((struct ResearchObjB *)p)->f34 == 0 || *(int *)&((struct ResearchObjB *)p)->f34 == 4)) {
        ((struct ResearchObjB *)p)->f3CC = 0;
        func_021BEB40((u32)p);
        func_021BE448(p);
        func_021BE498(p, 4);
        func_021BE498(p, 6);
        func_021BE498(p, 7);
        func_021BE498(p, 5);
        func_021BE498(p, 3);
    } else if (keys & 2) {
        func_021BE454(p, 0);
        func_021BEC00((u32 *)p);
        func_020061E4(0x551);
        func_021BE448(p);
        func_021BE498(p, 11);
        func_021BE498(p, 10);
        func_021BE498(p, 12);
    }
}


















void func_021BDF58(u8 *p)
{
    switch (func_021BE4DC(p)) {
    case 0:
        func_021BFC60((char *)p);
        func_021BF704(p);
        func_021BF568(p);
        func_021BEC84(p, 0);
        func_021BEC84(p, 1);
        func_021C1184(func_021BF76C(p), 1);
        func_021C1154(func_021BF76C(p));
        func_021BE4E0(p);
        break;
    case 1:
        if (func_02006238() == 0) {
            if (((struct ResearchObjB *)p)->f28 >= 0x78)
                func_021BE4E0(p);
            else
                func_020061E4(0x76B);
        }
        break;
    case 2:
        *(int *)&((struct ResearchObjB *)p)->f3C8 = 1;
        func_021BE930(p, 1);
        func_021BF3D8((char *)p);
        func_021BEFF8(p);
        func_021BE7F0((char *)p);
        func_021BF574(p);
        func_021BF08C((char *)p);
        func_021BF15C((char *)p);
        func_021BF264((char *)p);
        func_021BF3B4((char *)p);
        func_021BF2FC((char *)p);
        func_021BEEA4((char *)p);
        func_021BF47C((char *)p);
        if (((struct ResearchObjB *)p)->f3CC == 0)
            func_021BE934((char *)p);
        func_020061E4(0x76C);
        func_021BE448(p);
        break;
    }
}

















void func_021BE040(u8 *p)
{
    switch (func_021BE4DC(p)) {
    case 0:
        func_021BEF30((char *)p);
        func_021BE4E0(p);
        break;
    case 1:
        if (((struct ResearchObjB *)p)->f28 % 10u == 0) {
            u8 index = p[765];
            p[765] = index + 1;
            func_021BEFC0(p, index);
        }
        if (p[764] <= p[765]) func_021BE448(p);
        break;
    }
}

















/*
 * Same two-case entry as func_021BE0D0; mode 0 arms the +5 handle and
 * func_021BF60C().
 *
 * Addresses are Black-image addresses.
 */
void func_021BE094(u32 a0)
{
    switch (func_021BE4DC((void *)a0)) {
    case 0:
    func_021BF5BC((u8 *)a0, 5);
    func_021BF60C((char *)a0);
    func_021BE4E0((void *)a0);
    break;
    case 1:
    if (func_021BF6A4((u8 *)a0) != 0) {
    func_021BE448((void *)a0);
    }
    break;
    }
}

















void func_021BE0D0(u32 a0)
{
    switch (func_021BE4DC((void *)a0)) {
    case 0:
    func_021BF658((char *)a0);
    func_021BE4E0((void *)a0);
    break;
    case 1:
    if (func_021BF6A4((u8 *)a0) != 0) {
    func_021BEAF8((u8 *)a0);
    func_021BE448((void *)a0);
    }
    break;
    }
}

















void func_021BE108(char *p)
{
    switch (func_021BE4DC(p)) {
    case 0:
        ((struct ResearchObjB *)p)->f3D0 = 1;
        func_021BF704(p);
        func_021BF728(p);
        func_021BFC60(p);
        func_021BF08C(p);
        func_021BF15C(p);
        func_021BF3B4(p);
        func_021BF38C(p);
        func_021BEEA4(p);
        func_021BF3D8(p);
        func_021BEF98(p);
        func_021BED10((u8 *)p, 0);
        func_021BED10((u8 *)p, 1);
        func_021BEC64(p);
        func_021C1184(func_021BF77C(p), 1);
        func_021C1178(func_021BF77C(p));
        func_021BE4E0(p);
        break;
    case 1:
        if (func_02006238() == 0) {
            if (((struct ResearchObjB *)p)->f28 >= 0x3c) {
                func_021BE4E0(p);
                return;
            }
            func_020061E4(0x76b);
        }
        break;
    case 2:
        ((struct ResearchObjB *)p)->f3D0 = 0;
        func_021BEC0C(p);
        func_021C1184(func_021BF77C(p), 0);
        func_021BF08C(p);
        func_021BF3B4(p);
        func_021BF15C(p);
        func_021BF264(p);
        func_021BF2FC(p);
        func_021BEEA4(p);
        func_021BF3D8(p);
        func_021BF4AC(p);
        func_021BF47C(p);
        func_020061E4(0x76c);
        func_021BE448(p);
        break;
    }
}

















void func_021BE21C(char *p)
{
    switch (func_021BE4DC(p)) {
    case 0:
        ((struct ResearchObjB *)p)->f3D0 = 1;
        func_021BF704(p);
        func_021BF728(p);
        func_021BFC60(p);
        func_021BE9B8((u8 *)p);
        func_021BF08C(p);
        func_021BF15C(p);
        func_021BF3B4(p);
        func_021BF38C(p);
        func_021BEEA4(p);
        func_021BF3D8(p);
        func_021BEF98(p);
        func_021BED10((u8 *)p, 0);
        func_021BED10((u8 *)p, 1);
        func_021BEC64(p);
        func_021C1184(func_021BF77C(p), 1);
        func_021C1178(func_021BF77C(p));
        func_021BE4E0(p);
        break;
    case 1:
        if (func_02006238() == 0) {
            if (((struct ResearchObjB *)p)->f28 >= 0x3c) {
                func_021BE4E0(p);
                return;
            }
            func_020061E4(0x76b);
        }
        break;
    case 2:
        ((struct ResearchObjB *)p)->f3D0 = 0;
        func_021BEC0C(p);
        func_021C1184(func_021BF77C(p), 0);
        func_021BF08C(p);
        func_021BE934(p);
        func_021BF3B4(p);
        func_021BF15C(p);
        func_021BF264(p);
        func_021BF2FC(p);
        func_021BEEA4(p);
        func_021BF3D8(p);
        func_021BF4AC(p);
        func_021BF47C(p);
        func_020061E4(0x76c);
        func_021BE448(p);
        break;
    }
}

















/*
 * Same two-case entry with func_021BE90C() and the ARM9 query func_0204E804().
 *
 * Addresses are Black-image addresses.
 */
void func_021BE33C(u32 a0)
{
    switch (func_021BE4DC((void *)a0)) {
    case 0:
    func_021BE90C();
    func_021BE4E0((void *)a0);
    break;
    case 1:
    if (func_0204E804() == 0) {
    func_021BE448((void *)a0);
    }
    break;
    }
}

















/*
 * Calls func_021BE448() while func_021BE468() is below the record's +0x28
 * count.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE36C(u32 a0)
{
    if (func_021BE468((void *)a0) < ((struct ResearchObjB *)a0)->f28) {
    func_021BE448((void *)a0);
    }
}

















void func_021BE384(u8 *a0)
{
    func_021C08A8((int *)a0);
    func_021C085C((int *)a0);
    func_021C09E0(*(u32 *)&((struct ResearchObjB *)a0)->f0);
    func_021C09EC(*(u32 *)&((struct ResearchObjB *)a0)->f0);
    func_021C08F0((u8 *)a0);
    func_021BFF5C((int *)a0);
    func_021BFED4(a0);
    func_021BFC28((char *)a0);
    func_021C0800((u32)a0);
    func_021C06AC((int *)a0);
    func_021C0794((int *)a0);
    func_021C06E0((u8 *)a0);
    func_021C0494((int *)a0);
    func_021C03D0((int *)a0);
    func_021C02A8((u32)a0);
    func_021C0358((u32)a0);
    func_021C0230((int *)a0);
    func_021C018C(a0);
    func_021C0170(a0);
    func_021C0114(a0);
    func_021C00F8(a0);
    func_021C0084(a0);
    func_021BFBD0((u8 *)a0);
    func_021BFBA0((int *)a0);
    func_021BFB54((u8 *)a0);
    func_021BE460((void *)a0, 0);
    func_021BE498((u8 *)a0, 13);
    func_021BE448((void *)a0);
    func_021C0968((unsigned char *)a0);
    *(u32 *)&((struct ResearchObjB *)a0)->f3C4 = 0;
    ((struct ResearchObjB *)a0)->f3E0 = 1;
}


















void func_021BE448(void *p)
{
    ((struct ResearchObjB *)p)->f3DC = 1;
}


















/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to func_021C09C4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE454(u8 *a0, u32 a1)
{
    func_021C09C4(*(u8 * *)&((struct ResearchObjB *)a0)->f0, a1);
}


















void func_021BE460(void *p, u32 v)
{
    ((struct ResearchObjB *)p)->f3E4 = v;
}


















u32 func_021BE468(void *p)
{
    return ((struct ResearchObjB *)p)->f2C;
}

















/*
 * Classifies the record: 3 when the first query is busy and the second is
 * not, else 2.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE46C(u8 *a0)
{
    u32 v = ((struct ResearchObjB *)a0)->f0u;
    u32 a = func_021C09C8((void *)v);
    u32 b = func_021C09CC((void *)v);
    if (a != 0 && b == 0) {
    return 3;
    }
    return 2;
}


















/*
 * Increment the u32 at +0x28.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE490(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x28);
    *c += 1;
}


















/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 28)) to func_021C0E4C.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE498(u8 *a0, u32 a1)
{
    func_021C0E4C((u32)(((struct ResearchObjB *)a0)->f1C), a1);
}
















void func_021BE4A4(u32 a0)
{
    if (((struct ResearchObjB *)a0)->f3DC != 0) {
    if (func_021C0E64(((struct ResearchObjB *)a0)->f1C) == 0) {
    func_021BE4CC((void *)a0, func_021C0E54((struct Ring *)(((struct ResearchObjB *)a0)->f1C)));
    }
    }
}

















/*
 * Set +0x20, clear +0x24, +0x28 and +0x3dc.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE4CC(void *p, u32 v)
{
    ((struct ResearchObjB *)p)->f20 = v;
    ((struct ResearchObjB *)p)->f24 = 0;
    ((struct ResearchObjB *)p)->f28 = 0;
    ((struct ResearchObjB *)p)->f3DC = 0;
}

















u32 func_021BE4DC(void *p)
{
    return ((struct ResearchObjB *)p)->f24;
}
















/*
 * Increment the u32 at +0x24.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE4E0(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x24);
    *c += 1;
}















void func_021BE4E8(u8 *p)
{
    int repeat=1;
    func_021BE9B8(p);
    func_021BE91C((char *)p,-1);
    do {
        u32 index=((struct ResearchObjB *)p)->f34;
        if (index-1<=1) {
            if (((struct ResearchObjB *)p)->f3C8==0 || func_021BF810(p)==0) {
                func_021BE91C((char *)p,-1);
            } else repeat=0;
        } else if (index==4) {
            if (((struct ResearchObjB *)p)->f3C8==1 || func_021BF810(p)==0) {
                func_021BE91C((char *)p,-1);
            } else repeat=0;
        } else repeat=0;
    } while(repeat);
    func_021BE934((char *)p);
    func_021BF3D8((char *)p);
    func_021BF4AC((char *)p);
    func_021BF594((char *)p,1);
    if (((struct ResearchObjB *)p)->f34==4) func_021BEBA4((u32)p);
    func_020061E4(1352);
    func_021BEFF8(p);
}













void func_021BE580(u8 *p)
{
    int repeat=1;
    func_021BE9B8(p);
    func_021BE91C((char *)p,1);
    do {
        u32 index=((struct ResearchObjB *)p)->f34;
        if (index-1<=1) {
            if (((struct ResearchObjB *)p)->f3C8==0 || func_021BF810(p)==0) {
                func_021BE91C((char *)p,1);
            } else repeat=0;
        } else if (index==4) {
            if (((struct ResearchObjB *)p)->f3C8==1 || func_021BF810(p)==0) {
                func_021BE91C((char *)p,1);
            } else repeat=0;
        } else repeat=0;
    } while(repeat);
    func_021BE934((char *)p);
    func_021BF3D8((char *)p);
    func_021BF4AC((char *)p);
    func_021BF594((char *)p,1);
    if (((struct ResearchObjB *)p)->f34==4) func_021BEBA4((u32)p);
    func_020061E4(1352);
    func_021BEFF8(p);
}












u32 func_021BE614(u32 a0, u32 a1)
{
    func_021BE630((u8 *)a0, a1);
    func_021BF594((char *)a0, 1);
    return func_020061E4(1352);
}












void func_021BE630(u8 *a0, u32 a1)
{
    if ((u32)(a1 - 1) <= 1) {
    if (((struct ResearchObjB *)a0)->f3C8 == 0) {
    return;
    }
    if (func_021BF810(a0) == 0) {
    return;
    }
    }
    func_021BE9B8(a0);
    func_021BE930(a0, a1);
    func_021BE934((char *)a0);
    func_021BF3D8((char *)a0);
    func_021BF4AC((char *)a0);
    func_021BEFF8(a0);
}













/*
 * Per-frame step for the record's +0x3C8 sub-state; the tail is the
 * fixed-order call list that re-arms the sub-system (delta +1).
 *
 * Addresses are Black-image addresses.
 */
void func_021BE678(char *p)
{
    if (((struct ResearchObjB *)p)->f3C8 != 0) {
        if (func_021BF810(p) != 0) {
            func_021C116C(func_021BF76C(p));
        }
    }
    func_021BFC60(p);
    func_021BF704(p);
    func_021BEA3C(p, 1);
    ((struct ResearchObjB *)p)->f3C8 = 0;
    func_021BF08C(p);
    func_021BE934(p);
    func_021BF11C(p);
    func_021BF13C(p);
    func_021BE7D8((char *)p);
    func_021BF264(p);
    func_021BF2FC(p);
    func_021BF38C(p);
    func_021BEF98(p);
    func_021BF47C(p);
    func_021BEAF8((u8 *)p);
    func_020061E4(1352);
}











/*
 * Identical frame step to func_021BE678 with the sub-state delta -1.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE704(char *p)
{
    if (((struct ResearchObjB *)p)->f3C8 != 0) {
        if (func_021BF810(p) != 0) {
            func_021C116C(func_021BF76C(p));
        }
    }
    func_021BFC60(p);
    func_021BF704(p);
    func_021BEA3C(p, -1);
    ((struct ResearchObjB *)p)->f3C8 = 0;
    func_021BF08C(p);
    func_021BE934(p);
    func_021BF11C(p);
    func_021BF13C(p);
    func_021BE7D8((char *)p);
    func_021BF264(p);
    func_021BF2FC(p);
    func_021BF38C(p);
    func_021BEF98(p);
    func_021BF47C(p);
    func_021BEAF8((u8 *)p);
    func_020061E4(1352);
}









u32 func_021BE790(u32 a0)
{
    func_021BEA8C((u8 *)a0, 1);
    func_021BF15C((char *)a0);
    func_021BEEA4((char *)a0);
    return func_020061E4(1352);
}








u32 func_021BE7B4(u32 a0)
{
    func_021BEA8C((u8 *)a0, -1);
    func_021BF15C((char *)a0);
    func_021BEEA4((char *)a0);
    return func_020061E4(1352);
}








void func_021BE7D8(char *p)
{
    func_021BEAEC((u8 *)p);
    func_021BF15C(p);
    func_021BEEA4(p);
}









void func_021BE7F0(char *p)
{
    func_021BEA54(p);
    func_021BF15C(p);
    func_021BEEA4(p);
}









void func_021BE808(char *p)
{
    int flag = 0;
    u32 k;
    if (func_021BF78C((u32)p) == 0) {
        return;
    }
    if (((struct ResearchObjB *)p)->f3C8 != 0 && func_021BF810(p) != 0) {
        func_021C116C(func_021BF76C(p));
        flag = 1;
    }
    switch (((struct ResearchObjB *)p)->f2CC) {
    case 0:
        k = 1;
        break;
    case 1:
        k = 0;
        break;
    }
    func_021BF764(p, k);
    func_021BF08C(p);
    func_021BE934(p);
    func_021BF15C(p);
    func_021BF264(p);
    func_021BF2FC(p);
    func_021BF38C(p);
    func_021BF3B4(p);
    func_021BF47C(p);
    func_021BEAF8((u8 *)p);
    func_021BEEA4(p);
    func_021BEF98(p);
    if (((struct ResearchObjB *)p)->f3C8 != 0 && func_021BF810(p) != 0) {
        func_021BEF30(p);
        func_021BEFD4(p);
    }
    if (((struct ResearchObjB *)p)->f3C8 != 0 && func_021BF810(p) != 0) {
        if (flag != 0) {
            func_021C118C(func_021BF76C(p), 0x14);
        }
        func_021C1160(func_021BF76C(p));
        func_021C1184(func_021BF76C(p), 1);
    }
    func_020061E4(0x548);
}









void func_021BE8FC(void)
{
    func_0204E720(3, 0x10, 0, 0);
}








void func_021BE90C(void)
{
    func_0204E720(3, 0, 16, 0);
}









void func_021BE91C(char *p, int a)
{
    ((struct ResearchObjB *)p)->f34s = (((struct ResearchObjB *)p)->f34s + a + 5) % 5;
}








/*
 * Field setter, u32 at +0x34.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE930(void *p, u32 v)
{
    ((struct ResearchObjB *)p)->f34 = v;
}








int func_021BE934(char *p)
{
    switch (((struct ResearchObjB *)p)->f34s) {
    case 0:
    case 2:
    case 3:
        func_020413B0(2, d_021C3AC8[*(int *)(p + 0x34)].a,
                      d_021C3AC8[*(int *)(p + 0x34)].b,
                      d_021C3AC8[*(int *)(p + 0x34)].c,
                      d_021C3AC8[*(int *)(p + 0x34)].d, 0xa);
        break;
    case 1:
        func_020413B0(2, 0xd, 4, 0x13, 4, 0xa);
        func_020413B0(2, 0x10, 8, 0x10, 3, 0xa);
        break;
    case 4:
        func_021BEB6C((u32)p);
        break;
    }
    return func_020409B4(2);
}







void func_021BE9B8(u8 *p)
{
    switch (((struct ResearchObjB *)p)->f34) {
    case 0:
    case 2:
    case 3:
        func_020413B0(2, d_021C3AC8[*(u32 *)(p + 52)].a,
            d_021C3AC8[*(u32 *)(p + 52)].b,
            d_021C3AC8[*(u32 *)(p + 52)].c,
            d_021C3AC8[*(u32 *)(p + 52)].d, 6);
        break;
    case 1:
        func_020413B0(2,13,4,19,4,6);
        func_020413B0(2,16,8,16,3,6);
        break;
    case 4:
        func_021BEB88((u32)p);
        break;
    }
    func_020409B4(2);
}








void func_021BEA3C(char *p, int a)
{
    ((struct ResearchObjB *)p)->f2B8 = (u8)((((struct ResearchObjB *)p)->f2B8 + a + 3) % 3);
}







void func_021BEA54(char *p)
{
    u8 *o = func_021BF76C(p);

    u32 k = func_021BF7CC(p);
    int v = func_021C11D0(o, 0);
    ((struct ResearchObjB *)p)->f2B9 = func_021C26AC((const u8 *)(p + 0x38), (u8)k, (u8)v);
}







/*
 * Prototypes: original loads r0/r1 and reads return at 021C11C8/11D0;
 * narrow argument truncations are explicit in the caller.
 */
void func_021BEA8C(u8 *p, int step)
{
    u8 *object;
    int kind;
    int count;
    int index;
    object = func_021BF76C(p);
    kind = func_021BF7CC(p);
    count = func_021BF7E0(p);
    index = func_021BF7F4(p);
    index = func_021C11C8(object, index);

    index = (count + (index + step)) % count;
    index = func_021C11D0(object, index);
    p[697] = func_021C26AC(p + 56, kind, index);
}









void func_021BEAEC(u8 *a0)
{
    ((struct ResearchObjB *)a0)->f2B9 = 0;
}






void func_021BEAF8(u8 *p)
{
    if (((struct ResearchObjB *)p)->f3C8 == 1 || ((struct ResearchObjB *)p)->f3D0 == 1 || func_021BF810(p) == 0) {
        if (func_021BF5D0(p, 5) == 0) func_021BEBE4((u32)p);
    } else {
        if (func_021BF5D0(p, 5) == 1) func_021BEBC0((u32)p);
    }
}






void func_021BEB40(u32 a0)
{
    BMP_OAM_SetPalette((u8 *)(((struct ResearchObjB *)a0)->f3AC), 0);
    func_021BF5BC((u8 *)a0, 5);
    func_021BF5BC((u8 *)a0, 6);
    func_021BF594((char *)a0, 2);
}





void func_021BEB6C(u32 a0)
{
    BMP_OAM_SetPalette((u8 *)(((struct ResearchObjB *)a0)->f3AC), 0);
    func_021BF594((char *)a0, 3);
}





void func_021BEB88(u32 a0)
{
    BMP_OAM_SetPalette((u8 *)(((struct ResearchObjB *)a0)->f3AC), 1);
    func_021BF5BC((u8 *)a0, 3);
}





void func_021BEBA4(u32 a0)
{
    BMP_OAM_SetPalette((u8 *)(((struct ResearchObjB *)a0)->f3AC), 0);
    func_021BF594((char *)a0, 4);
}





void func_021BEBC0(u32 a0)
{
    BMP_OAM_SetPalette((u8 *)(((struct ResearchObjB *)a0)->f3AC), 1);
    func_021BF5BC((u8 *)a0, 5);
    func_021BF594((char *)a0, 6);
}





void func_021BEBE4(u32 a0)
{
    BMP_OAM_SetPalette((u8 *)(((struct ResearchObjB *)a0)->f3AC), 1);
    func_021BF594((char *)a0, 5);
}





void func_021BEC00(u32 *p)
{
    func_021C09D8((u8 *)(*p), 0);
}






/*
 * Swap the u32 pairs at +0x2bc and +0x2c4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BEC0C(void *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        u32 t = *(u32 *)((char *)p + i * 4 + 0x2bc);
        *(u32 *)((char *)p + i * 4 + 0x2bc) = *(u32 *)((char *)p + i * 4 + 0x2c4);
        *(u32 *)((char *)p + i * 4 + 0x2c4) = t;
    }
}





void func_021BEC34(u32 a0)
{
    u32 v1 = func_0209C0A4(((struct Item *)a0)->y + 62, 3);
    u32 v2 = func_0209C0A4(((struct Item *)a0)->z + 62, 3);
    ((struct Item *)a0)->a = func_0209C0A4(((struct Item *)a0)->x + 62, 3);
    ((struct Item *)a0)->b = v1;
    ((struct Item *)a0)->c = v2;
}






void func_021BEC64(void *p)
{
    func_021C11A4(func_021BF76C(p), 0xFFFFE000);
    func_021C11A4(func_021BF77C(p), 0);
}





void func_021BEC84(u8 *p,int mode)
{
    struct Item items[17];
    struct Input *base;
    u32 object;
    int count;
    int i;
    object=*(u32 *)(p+700+mode*4);
    count=func_021BF7E0(p);
    base=(struct Input *)(p+60+p[696]*212);
    for(i=0;i<count;i++) {
        struct Input *q=(struct Input *)((u8 *)base+8+i*12);
        struct Item *t=&items[i];
        t->id=q->id; t->x=q->x; t->y=q->y; t->z=q->z;
        func_021BEC34((u32)t);
        switch(mode) { case 0: t->value=q->a; break; case 1: t->value=q->b; break; }
    }
    func_021C10E8((u8 *)object,(u8 *)items,count);
}





void func_021BED10(u8 *p, u32 mode)
{
    struct Item items[17];
    struct Input *base;
    u32 object;
    int count;
    int i;
    object=*(u32 *)(p+708+mode*4);
    count=func_021BF7E0(p);
    base=(struct Input *)(p+60+p[696]*212);
    for(i=0;i<count;i++) {
        struct Input *q=(struct Input *)((u8 *)base+8+i*12);
        struct Item *t=&items[i];
        t->id=q->id; t->x=q->x; t->y=q->y; t->z=q->z;
        func_021BEC34((u32)t);
        switch(mode) { case 0: t->value=q->a; break; case 1: t->value=q->b; break; }
    }
    func_021C10E8((u8 *)object,(u8 *)items,count);
}





void func_021BED9C(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        func_021C1124(*(u8 **)(p + i * 4 + 0x2bc));
        func_021C1124(*(u8 **)(p + i * 4 + 0x2c4));
    }
}





void func_021BEDC4(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        func_021C112C(*(u8 **)(p + i * 4 + 0x2bc));
        func_021C112C(*(u8 **)(p + i * 4 + 0x2c4));
    }
}





void func_021BEDEC(char *p)
{
    unsigned r,g,b;
    void *color;
    if (((struct ResearchObjB *)p)->f3C8==0 || ((struct ResearchObjB *)p)->f3D0==1 || func_021BF810(p)==0) return;
    color=p+56;
    r=func_021C2654(color,((struct ResearchObjB *)p)->f2B8,((struct ResearchObjB *)p)->f2B9);
    g=func_021C2664(color,((struct ResearchObjB *)p)->f2B8,((struct ResearchObjB *)p)->f2B9);
    b=func_021C2674(color,((struct ResearchObjB *)p)->f2B8,((struct ResearchObjB *)p)->f2B9);
    *(volatile unsigned *)0x040004a4=0x001f00c0;
    *(volatile unsigned *)0x04000500=1;
    *(volatile unsigned *)0x04000480=(u16)(r | (g<<5) | (b<<10));
    *(volatile unsigned *)0x0400048c=0x096cfc68;
    *(volatile unsigned *)0x0400048c=0;
    *(volatile unsigned *)0x0400048c=0x0a7afc68;
    *(volatile unsigned *)0x0400048c=0;
    *(volatile unsigned *)0x0400048c=0x0a7afda1;
    *(volatile unsigned *)0x0400048c=0;
    *(volatile unsigned *)0x0400048c=0x096cfda1;
    *(volatile unsigned *)0x0400048c=0;
    *(volatile unsigned *)0x04000504=0;
}





/*
 * C11DC forwards r0/r1 through C1AC0; caller's narrowed index remains in its prototype.
 * C20CC overwrites incoming r1 with 1 before forwarding to C218C; legacy unused trailing parameter omitted.
 */
void func_021BEEA4(char *p)
{
    u8 *object;
    unsigned index;
    s32 x,y;
    func_021C20D8(*(unsigned *)&((struct ResearchObjB *)p)->f2D0);
    if (((struct ResearchObjB *)p)->f3D0==1) return;
    if (((struct ResearchObjB *)p)->f3C8==0) return;
    if (func_021BF810(p)==0) return;
    object=func_021BF76C(p);
    index=func_021BF7F4(p);
    if (func_021C11DC(object,index)==0) return;
    if (((struct ResearchObjB *)p)->f3C8!=0) {
        object=func_021BF76C(p);
        index=func_021BF7F4(p);
        func_021C11FC(object,index,&x,&y);

        func_021C20B4(*(unsigned *)&((struct ResearchObjB *)p)->f2D0,104,34,x,y);
        func_021C20CC(*(unsigned *)&((struct ResearchObjB *)p)->f2D0);
    }
}





/*
 * lever: unsigned output counter i; initialize before decrementing the signed reverse counter.
 * C11E8 forwards original r0/r1 to C1AB4's two-input record lookup.
 * C271C forwards original r1/r2 to C288C's two-field setter.
 */
void func_021BEF30(char *p)
{
    int n,id;
    unsigned i;
    u8 *object;
    s32 x,y;
    unsigned slot;
    n=func_021BF7E0(p);
    object=func_021BF76C(p);
    i=0;
    n--;
    for (;n>=0;n--) {
        id=func_021C11E8(object,n);
        func_021C1224(object,n,&x,&y);

        if (id>=10) {
            slot=*(unsigned *)(p+i*4+0x2d4);
            func_021C272C(slot,id);
            func_021C271C(slot,x,y);
            i++;
        }
    }
    ((struct ResearchObjB *)p)->f2FC=i;
}




void func_021BEF98(char *p)
{
    int i;
    u8 z = 0;
    for (i = 0; i < 10; i++) {
        func_021C2740(*(u32 *)(p + i * 4 + 0x2d4), z);
    }
    ((struct ResearchObjB *)p)->f2FD = z;
}





/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 724)), 1 to func_021C2740.
 *
 * Addresses are Black-image addresses.
 */
void func_021BEFC0(u8 *a0, u32 a1)
{
    func_021C2740((u32)(*(u32*)(a0 + (a1)*4 + 724)), 1);
}




void func_021BEFD4(char *p)
{
    int i;
    int n;
    n = ((struct ResearchObjB *)p)->f2FC;
    for (i = 0; i < n; i++) {
        func_021BEFC0((u8 *)p, (u8)i);
    }
}




/*
 * lever: pool 021BF088 is 021C3AC8; dropping contested ov217 data hint resolves sole-ref evidence.
 */
void func_021BEFF8(u8 *p)
{
    const struct Row *row;
    u8 *q;
    row=(const struct Row *)&d_021C3AC8[((struct ResearchObjB *)p)->f34];
    q=p+0x2fe;
    q[2]=func_021C0900(row->fields[0]+row->fields[4]-16);
    p[0x2fe]=func_021C0900(row->fields[1]+row->fields[5]-16);
    q[3]=func_021C0900(q[2]+32);
    q[1]=func_021C0900(p[0x2fe]+32);
    row=(const struct Row *)&d_021C3AC8[((struct ResearchObjB *)p)->f34];
    q=p+0x302;
    q[2]=func_021C0900(row->fields[0]+row->fields[6]-16);
    p[0x302]=func_021C0900(row->fields[1]+row->fields[7]-16);
    q[3]=func_021C0900(q[2]+32);
    q[1]=func_021C0900(p[0x302]+32);
}




void func_021BF08C(char *p)
{
    struct ArcFile *arc;
    void *file,*out;
    unsigned id;
    arc=func_020490F4(192,((struct ResearchObjB *)p)->f4);
    if (((struct ResearchObjB *)p)->f3D0!=0) id=8;
    else if (func_021BF810(p)==0) id=6;
    else {
        id=6;
        if (((struct ResearchObjB *)p)->f3C8!=0) id=7;
    }
    file=func_02049250(arc,id,((struct ResearchObjB *)p)->f4);
    func_02062B30(file,&out);
    func_02041090(2,(unsigned)out+12,0,0,32,32);
    func_020409B4(2);
    func_020307B0(file);
    func_02049238(arc);
}





/*
 * Tail call through a pool word: bx r3 spends r3 on the target, so only the
 * two argument registers are live (see docs/idioms/a-tail-call-cannot-pass-a-fourth-argument.md).
 *
 * Addresses are Black-image addresses.
 */
void func_021BF100(char *p)
{
    func_021C0F5C(((struct ResearchObjB *)p)->f348, d_021C3628[((struct ResearchObjB *)p)->f38]);
}




void func_021BF11C(char *p)
{
    u32 i = func_021BF7CC(p);
    func_021C0F5C(((struct ResearchObjB *)p)->f34C, d_021C36B8[i]);
}




void func_021BF13C(char *p)
{
    u32 o = ((struct ResearchObjB *)p)->f350;
    u32 i = func_021BF7CC(p);
    func_021C0F5C(o, d_021C369A[i]);
}




void func_021BF15C(char *p)
{
    u32 t = ((struct ResearchObjB *)p)->f354;
    u8 *o = func_021BF76C(p);
    u32 k;
    u32 a, b, c;
    void *x, *y, *z;
    if (((struct ResearchObjB *)p)->f3C8 == 0 || ((struct ResearchObjB *)p)->f3D0 == 1) {
        func_021C0FF8((u8 *)t, 0);
        return;
    }
    if (func_021BF810(p) == 0) {
        func_021C0FF8((u8 *)t, 0);
        return;
    }
    k = func_021BF7F4(p);
    a = func_021C11C8(o, (u8)k);

    b = func_021BF854(p);
    c = func_021C11DC(o, (u8)k);
    x = func_02045EC0(((struct ResearchObjB *)p)->fC, 0xd);
    y = func_02045EC0(((struct ResearchObjB *)p)->f14, k);
    z = func_020457B0(0x80, ((struct ResearchObjB *)p)->f4);
    func_0201EFA4(((struct ResearchObjB *)p)->f18, 0, a + 1, 2, 1, 1);
    func_0201EE0C(((struct ResearchObjB *)p)->f18, 1, y, 0, 1, 2);
    func_0201EFA4(((struct ResearchObjB *)p)->f18, 2, b, 5, 1, 1);
    func_0201EFA4(((struct ResearchObjB *)p)->f18, 3, c, 3, 1, 1);
    func_0201F250(((struct ResearchObjB *)p)->f18, z, x);
    func_021C0F78((u8 *)t, z);
    func_021C0FF8((u8 *)t, 1);
    func_02045808(x);
    func_02045808(z);
    func_02045808(y);
}




/*
 * EE0C: original stores sixth argument 2 at sp+4; preserve visibly supplied trailing input.
 */
void func_021BF264(char *p)
{
    unsigned index;
    struct U16Vec *a,*b,*buf;
    if (((struct ResearchObjB *)p)->f3C8==0 || func_021BF810(p)==0) {
        func_021C0FF8((u8 *)(((struct ResearchObjB *)p)->f358),0);
        return;
    }
    index=func_021BF910((unsigned char *)p);
    a=func_02045EC0(*(struct MsgBank * *)&((struct ResearchObjB *)p)->fC,14);
    b=func_02045EC0(*(struct MsgBank * *)&((struct ResearchObjB *)p)->f14,index);
    buf=func_020457B0(128,((struct ResearchObjB *)p)->f4);
    func_0201EE0C(*(struct WordSet * *)&((struct ResearchObjB *)p)->f18,0,b,0,1,2);
    func_0201F250(*(struct WordSet * *)&((struct ResearchObjB *)p)->f18,buf,a);
    func_021C0FF8((u8 *)(((struct ResearchObjB *)p)->f358),1);
    func_021C0F78((u8 *)(((struct ResearchObjB *)p)->f358),buf);
    func_02045808(a);
    func_02045808(buf);
    func_02045808(b);
}




void func_021BF2FC(char *p)
{
    u32 k;
    u32 x;
    void *a, *b;
    void *c;
    if (((struct ResearchObjB *)p)->f3C8 != 0) {
        switch (((struct ResearchObjB *)p)->f2CC) {
        case 0:
            k = 0xf;
            break;
        case 1:
            k = 0x11;
            break;
        }
    } else {
        switch (((struct ResearchObjB *)p)->f2CC) {
        case 0:
            k = 0x10;
            break;
        case 1:
            k = 0x12;
            break;
        }
    }
    x = func_021BF810(p);
    c = ((struct ResearchObjB *)p)->f18;
    a = func_02045EC0(((struct ResearchObjB *)p)->fC, k);
    b = func_020457B0(0x80, ((struct ResearchObjB *)p)->f4);
    func_0201EFA4(c, 0, x, 6, 1, 1);
    func_0201F250(c, b, a);
    func_021C0F78((u8 *)(((struct ResearchObjB *)p)->f35C), b);
    func_02045808(a);
    func_02045808(b);
}




void func_021BF38C(char *p)
{
    if (func_021BF810(p) == 0) {
        func_021C0FF8((u8 *)(((struct ResearchObjB *)p)->f360), 1);
    } else {
        func_021C0FF8((u8 *)(((struct ResearchObjB *)p)->f360), 0);
    }
}




void func_021BF3B4(char *p)
{
    if (((struct ResearchObjB *)p)->f3D0 != 0) {
        func_021C0FF8((u8 *)(((struct ResearchObjB *)p)->f364), 1);
    } else {
        func_021C0FF8((u8 *)(((struct ResearchObjB *)p)->f364), 0);
    }
}




void func_021BF3D8(char *p)
{
    const struct Row *row;
    struct Obj *a,*b;
    struct Vec2 pos;
    row=(const struct Row *)&d_021C3AC8[((struct ResearchObjB *)p)->f34];
    a=(struct Obj *)func_021BFA08(p,0);
    b=(struct Obj *)func_021BFA08(p,1);
    if (((struct ResearchObjB *)p)->f3D0==1 || ((struct ResearchObjB *)p)->f34==2 || ((struct ResearchObjB *)p)->f34==4) {
        func_0204B3DC(a,0);
        func_0204B3DC(b,0);
        return;
    }
    pos.x=row->fields[0]+row->fields[4];
    pos.y=row->fields[1]+row->fields[5];
    func_0204B404(a,&pos,0);
    pos.x=row->fields[0]+row->fields[6];
    pos.y=row->fields[1]+row->fields[7];
    func_0204B404(b,&pos,0);
    func_0204B3DC(a,1);
    func_0204B3DC(b,1);
    func_0204B92C(a,1);
    func_0204B92C(b,1);
}




void func_021BF47C(char *p)
{
    if (((struct ResearchObjB *)p)->f3C8 == 0 || func_021BF810(p) == 0) {
        func_0204B3DC((struct Obj *)((struct ResearchObjB *)p)->f39C, 0);
    } else {
        func_0204B3DC((struct Obj *)((struct ResearchObjB *)p)->f39C, 1);
    }
}




void func_021BF4AC(char *p)
{
    struct Obj *obj;
    unsigned index;
    s32 x,y;
    struct Vec2 pos;
    const u16 *table;
    obj=*(struct Obj * *)&((struct ResearchObjB *)p)->f3A0;
    table=d_021C3850;
    if (((struct ResearchObjB *)p)->f3C8==0) { func_0204B3DC(obj,0); return; }
    if (((struct ResearchObjB *)p)->f34!=2) { func_0204B3DC(obj,0); return; }
    index=func_021BF910((u8 *)p);
    if (func_021C11DC(func_021BF76C(p),index)==0) { func_0204B3DC(obj,0); return; }
    if (index==0) { func_0204B3DC(obj,0); return; }
    func_021C11FC(func_021BF76C(p),index,&x,&y);

    pos.x=x;
    pos.y=y;
    func_0204B404(obj,&pos,table[12]);
    func_0204B3DC(obj,1);
    func_0204B92C(obj,1);
    CLACT_SetActorAnimLoopCount((struct Actor *)obj,2);
}





void func_021BF55C(void *a0)
{
    func_021BF580((u8 *)a0, 1, 1);
}





/*
 * Tail-call veneer: forwards arg(s) a0, 0, 1 to func_021BF580.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF568(void *a0)
{
    func_021BF580((u8 *)a0, 0, 1);
}





/*
 * Tail-call veneer: forwards arg(s) a0, 0, 0 to func_021BF580.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF574(void *a0)
{
    func_021BF580((u8 *)a0, 0, 0);
}




void func_021BF580(u8 *p, u32 i, u32 j)
{
    func_02025774((u8 *)(*(u32 *)(p + i * 4 + 0x3a8)), j);
}




void func_021BF594(char *p, int i)
{
    func_021C29F8((u8 *)(*(u32 *)(p + i * 4 + 0x324)), d_021C3A34[i].a, d_021C3A34[i].b);
}





/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 804)), (u32)(a0 + (a1)*4) to func_021C2A00.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF5BC(u8 *a0, u32 a1)
{
    func_021C2A00((u32)(*(u32*)(a0 + (a1)*4 + 804)));
}





/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 804)), (u32)(a0 + (a1)*4) to func_021C2A10.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF5D0(u8 *a0, u32 a1)
{
    return func_021C2A10((u32)(*(u32*)(a0 + (a1)*4 + 804)), (u32)(a0 + (a1)*4));
}





void func_021BF5E4(int *p)
{
    int i;
    for (i = 0; i < 8; i++)
        func_021C29F0(p[i + 0xC9]);
}





/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to func_021C09D0.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF600(u8 *a0)
{
    func_021C09D0((u32)(((struct ResearchObjB *)a0)->f0u));
}




void func_021BF60C(char *p)
{
    PALANM_RequestFade(*(struct PalAnmObj * *)&((struct ResearchObjB *)p)->f3B8,1,0xffff,3,0,7,0xffff,((struct ResearchObjB *)p)->f3BC);
    PALANM_RequestFade(*(struct PalAnmObj * *)&((struct ResearchObjB *)p)->f3B8,4,0xffff,3,0,7,0xffff,((struct ResearchObjB *)p)->f3BC);
}




void func_021BF658(char *p)
{
    PALANM_RequestFade(*(struct PalAnmObj * *)&((struct ResearchObjB *)p)->f3B8,1,0xffff,3,7,0,0xffff,((struct ResearchObjB *)p)->f3BC);
    PALANM_RequestFade(*(struct PalAnmObj * *)&((struct ResearchObjB *)p)->f3B8,4,0xffff,3,7,0,0xffff,((struct ResearchObjB *)p)->f3BC);
}




/*
 * Note: the record's +0x3B8 handle is idle.
 *            witness outside 021BF6A4..021BF6BC.  Bytes are exact and 24/24
 *            match the listing extent; file the TARGET first (OV-BRIEF rule
 *            10) and this promotes to EXACT with no source change.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF6A4(u8 *a0)
{
    if (PALANM_GetFadeRequestBits((const char *)(((struct ResearchObjB *)a0)->f3B8)) == 0) {
    return 1;
    }
    return 0;
}




u32 func_021BF6BC(u32 a0, u32 a1)
{
    func_020419E4();
    func_0204A648();
    return PALANM_TransferPalettes((struct S02021D50 *)((struct ResearchObjB *)a1)->f3B8);
}




void func_021BF6D4(char *p)
{
    if (GAME_BEACON_PopQuestionnaireUpdated() == 1) {
        u16 a = func_021BF834(p);
        if (a != (u16)(u32)func_021BF9CC((u32)p)) {
            ((struct ResearchObjB *)p)->f3D8 = 1;
        }
    }
}





/*
 * Clear the u32 at +0x3d8.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF704(void *p)
{
    ((struct ResearchObjB *)p)->f3D8 = 0;
}





void func_021BF710(void *p)
{
    if (((struct ResearchObjB *)p)->f30 < 0xf0) {
        ((struct ResearchObjB *)p)->f30 += 1;
    } else {
        ((struct ResearchObjB *)p)->f3D4 = 1;
    }
}





void func_021BF728(void *p)
{
    ((struct ResearchObjB *)p)->f30 = 0;
    ((struct ResearchObjB *)p)->f3D4 = 0;
}





u32 func_021BF734(u8 *a0)
{
    return func_021C09B0((u32 *)(((struct Obj25933 *)a0)->f0));
}





/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to func_021C09B4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF740(u8 *a0)
{
    return func_021C09B4((void *)(((struct ResearchObjB *)a0)->f0u));
}





void func_021BF74C(void *p, u32 v)
{
    ((struct ResearchObjB *)p)->f4 = v;
}





/*
 * Field getter, u32 at +0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF750(void *p)
{
    return ((struct ResearchObjB *)p)->f0u;
}





void func_021BF754(void *p, u32 v)
{
    ((struct ResearchObjB *)p)->f0u = v;
}




u32 func_021BF758(void *p)
{
    return func_021C09F8((void *)func_021BF750(p));
}





/*
 * Field setter, u32 at +0x2cc.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF764(void *p, u32 v)
{
    ((struct ResearchObjB *)p)->f2CC = v;
}





u8 *func_021BF76C(void *p)
{
    u32 i = ((struct ResearchObjB *)p)->f2CC;
    return *(u8 **)((char *)p + i * 4 + 0x2bc);

}





u8 *func_021BF77C(void *p)
{
    u32 i = ((struct ResearchObjB *)p)->f2CC;
    return *(u8 **)((char *)p + i * 4 + 0x2c4);

}




u32 func_021BF78C(u32 a0)
{
    if (func_021C11F4(*(u8 * *)&((struct ResearchObjB *)a0)->f2BC) != 0 || func_021C11F4(*(u8 * *)&((struct ResearchObjB *)a0)->f2C0) != 0 || func_021C11F4(*(u8 * *)&((struct ResearchObjB *)a0)->f2C4) != 0 || func_021C11F4(*(u8 * *)&((struct ResearchObjB *)a0)->f2C8) != 0) {
    return 0;
    }
    return 1;
}





u32 func_021BF7CC(void *p)
{
    u32 i = ((struct ResearchObjB *)p)->f2B8;
    return *(u8 *)((char *)p + i * 0xd4 + 0x3c);
}





u32 func_021BF7E0(void *p)
{
    u32 i = ((struct ResearchObjB *)p)->f2B8;
    return *(u8 *)((char *)p + i * 0xd4 + 0x3d);
}





/*
 * Element field: u16 at +0x44 of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF7F4(void *p)
{
    u32 i = ((u8 *)p)[0x2b8];
    u32 j = ((u8 *)p)[0x2b9];
    return *(u16 *)((char *)p + 0x44 + i * 0xd4 + j * 0xc);
}




u32 func_021BF810(void *p)
{
    u32 r = 0;
    switch (((struct ResearchObjB *)p)->f2CC) {
    case 0:
        r = func_021BF834(p);
        break;
    case 1:
        r = func_021BF844(p);
        break;
    }
    return r;
}





/*
 * Element field: u16 at +0x3e of record 0xd4 bytes, selected by the u8 at +0x2b8.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF834(void *p)
{
    u32 i = ((struct ResearchObjB *)p)->f2B8;
    return *(u16 *)((char *)p + i * 0xd4 + 0x3e);
}





u32 func_021BF844(void *p)
{
    u32 i = ((struct ResearchObjB *)p)->f2B8;
    return *(u32 *)((char *)p + i * 0xd4 + 0x40);
}




u32 func_021BF854(char *p)
{
    switch (((struct ResearchObjB *)p)->f2CC) {
    case 0:
        return func_021BF878(p);
    case 1:
        return func_021BF894(p);
    }
    return 0;
}





/*
 * Element field: u16 at +0x4a of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF878(void *p)
{
    u32 i = ((u8 *)p)[0x2b8];
    u32 j = ((u8 *)p)[0x2b9];
    return *(u16 *)((char *)p + 0x4a + i * 0xd4 + j * 0xc);
}





/*
 * Element field: u32 at +0x4c of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF894(void *p)
{
    u32 i = ((u8 *)p)[0x2b8];
    u32 j = ((u8 *)p)[0x2b9];
    return *(u32 *)((char *)p + 0x4c + i * 0xd4 + j * 0xc);
}




/*
 * lever: pointer-typed lookup base keeps the original r4/r5 allocation; E44C full body reads only r0/r1 and forwards neither legacy trailing input.
 * F740 tail-forwards to C09B4's pointer getter; E394 tail-forwards to 071CC's returned save block.
 * E44C's full body reads only r0/r1 and has no forwarding calls; legacy two trailing inputs omitted.
 */
u8 func_021BF8B0(u8 *p)
{
    u8 bytes[3];
    u8 a,b,c,j;
    void *base;
    int i;
    base=func_0200E394(func_02012EBC((struct Big *)func_021BF740(p)));
    for (i=0;i<3;i++) bytes[i]=func_0200E44C((int)base,i);
    b=bytes[1];
    c=bytes[2];
    a=bytes[0];
    for (j=0;j<10;j++) {
        if (a==d_021C363C[j] && b==d_021C3646[j] && c==d_021C3632[j]) return j;
    }
    return 0;
}




u32 func_021BF910(u8 *p)
{
    void *bits;
    u32 index;
    u16 n;
    bits = func_0200E3A0(func_0200E394(func_02012EBC((struct Big *)func_021BF740(p))));
    index = func_021BF7CC(p);
    if (index == 29) return func_021BF968(p);
    n = func_0200E3A4((const u8 *)bits, index);
    if (n == 0) return 0;
    n--;
    return (u8)func_021C2644(p + 0x38, p[0x2b8], n);
}




/*
 * extent: trailing 00 00 at 021BF9CA is two-byte alignment padding.
 * prototype: 02012FCC legacy trailing arguments omitted: full 12-byte body only reads r0, then returns its field at 0x6ac; no forwarding.
 * prototype: full 02012FCC body only reads r0, does not forward r1-r3; legacy trailing inputs omitted.
 */
u32 func_021BF968(u8 *p)
{
    u32 v = func_0200864C((const struct PlayTime *)func_02012FCC(func_021BF740(p)));
    if (v < 10) return 135;
    if (v < 20) return 136;
    if (v < 30) return 137;
    if (v < 40) return 138;
    if (v < 50) return 139;
    if (v < 60) return 140;
    if (v < 70) return 141;
    if (v < 80) return 142;
    if (v < 90) return 143;
    if (v < 100) return 144;
    return 145;
}




/*
 * Reconstructed from the listing.
 *
 * BLOCKED at MATCH: the relocation site(s) below have no independent witness.
 *   +001C THM_CALL func_0200E458       -> unresolved: 0200E458 (arm, from name) has no witness outside 021BF9CC..021BF9EE
 * Promote automatically when the target is matched.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021BF9CC(u32 a0)
{
    return func_0200E458((const u16 *)func_0200E394(func_02012EBC((struct Big *)func_021BF740((u8 *)a0))), func_021BF7CC((void *)a0));
}





u32 func_021BF9F0(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x368);
}





u32 func_021BF9FC(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x384);
}





u32 func_021BFA08(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x394);
}




u32 func_021BFA14(u32 a0)
{
    return (u32)func_02030734(a0, 1000, 0, (const char *)0x21C400C, 4096);
}




void func_021BFA30(char *p)
{
    int i;
    ((struct ResearchObjB *)p)->f20 = 0;
    ((struct ResearchObjB *)p)->f24 = 0;
    ((struct ResearchObjB *)p)->f3DC = 0;
    ((struct ResearchObjB *)p)->f2C = 0xf;
    ((struct ResearchObjB *)p)->f28 = 0;
    ((struct ResearchObjB *)p)->f30 = 0;
    ((struct ResearchObjB *)p)->f34 = 0;
    ((struct ResearchObjB *)p)->f3C4 = 0;
    ((struct ResearchObjB *)p)->f3C8 = 0;
    ((struct ResearchObjB *)p)->f3CC = 0;
    ((struct ResearchObjB *)p)->f3D0 = 0;
    ((struct ResearchObjB *)p)->f3D4 = 0;
    ((struct ResearchObjB *)p)->f3D8 = 0;
    ((struct ResearchObjB *)p)->f2B8 = 0;
    ((struct ResearchObjB *)p)->f2B9 = 0;
    ((struct ResearchObjB *)p)->f2CC = 0;
    ((struct ResearchObjB *)p)->f3BCu = func_020056BC();
    ((struct ResearchObjB *)p)->f2FC = 0;
    ((struct ResearchObjB *)p)->f2FD = 0;
    ((struct ResearchObjB *)p)->f3E4 = 0;
    ((struct ResearchObjB *)p)->f3E0 = 0;
    for (i = 0; i < 7; i++) {
        *(u32 *)(p + i * 4 + 0x368) = 0;
    }
    func_021BFC50((u8 *)p);
    func_021BFB0C(p);
    func_021BFBDC(p);
    func_021BFE80(p);
    func_021BFEE4(p);
    func_021BFB60(p);
    func_021BFBB8(p);
    func_021BFB30(p);
    func_021C019C(p);
    func_021C0384(p);
    func_021C03EC(p);
    func_021C04B0(p);
    func_021C07B0(p);
    func_021C0820(p);
}





u32 func_021BFB04(void *a0)
{
    return func_020307B0(a0);
}





/*
 * Clear the u32 at +0x1c.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFB0C(void *p)
{
    ((struct ResearchObjB *)p)->f1C = 0;
}




void func_021BFB14(u32 a0)
{
    ((struct ResearchObjB *)a0)->f1C = func_021C0E08(10, ((struct ResearchObjB *)a0)->f4);
}





void func_021BFB24(u8 *a0)
{
    func_021C0E3C((void *)((u32)(((struct Obj25949 *)a0)->f1C)));
}





/*
 * Clear the u32 at +8.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFB30(void *p)
{
    ((struct ResearchObjB *)p)->f8 = 0;
}




void func_021BFB38(u32 a0)
{
    u8 s[4];
    ((struct ResearchObjB *)a0)->f8 = (u32)func_0201D7EC(23, 0, 0, 0, (u32)(((struct ResearchObjB *)a0)->f4));
}





/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 8)) to func_0201D83C.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFB54(u8 *a0)
{
    func_0201D83C((void *)((u32)(((struct ResearchObjB *)a0)->f8)));
}





/*
 * Clear three u32 slots at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFB60(void *p)
{
    int i;
    for (i = 0; i < 3; i++)
        *(u32 *)((char *)p + i * 4 + 0xc) = 0;
}




void func_021BFB74(W *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        p->obj[i] = (u32)func_02045B38(0, 2, (u16)d_021C3650[i], (u16)p->h);
    }
}





void func_021BFBA0(int *p)
{
    int i;
    for (i = 0; i < 3; i++)
        func_02045C04((struct Rec *)p[i + 3]);
}





void func_021BFBB8(void *p)
{
    ((struct ResearchObjB *)p)->f18 = 0;
}




void func_021BFBC0(u32 a0)
{
    ((struct ResearchObjB *)a0)->f18 = (void *)func_0201EC64(((struct ResearchObjB *)a0)->f4);
}





void func_021BFBD0(u8 *a0)
{
    func_0201ED04((struct WordSet *)((u32)(((struct ResearchObjB *)a0)->f18)));
}





/*
 * Clear two pairs of u32 slots at +0x2bc and +0x2c4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFBDC(void *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        *(u32 *)((char *)p + i * 4 + 0x2bc) = 0;
        *(u32 *)((char *)p + i * 4 + 0x2c4) = 0;
    }
}




void func_021BFBFC(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        *(u32 *)(p + i * 4 + 0x2bc) = func_021C10C8(((struct ResearchObjB *)p)->f4);
        *(u32 *)(p + i * 4 + 0x2c4) = func_021C10C8(((struct ResearchObjB *)p)->f4);
    }
}




void func_021BFC28(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        func_021C10D8((void *)(*(u32 *)(p + i * 4 + 0x2bc)));
        func_021C10D8((void *)(*(u32 *)(p + i * 4 + 0x2c4)));
    }
}





/*
 * Tail-call veneer: forwards arg(s) (u32)(a0 + 56), 0, 640 to func_02082BCC.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFC50(u8 *a0)
{
    func_02082BCC((u32)(a0 + 56), 0, 640);
}




/*
 * blocker (2026-10-02, lane04 wC1): 203 bytes differ, relocations all resolve.
 * Locals now laid out like the original (sh, A, B, va, vb, buf declaration
 * order gives the right stack slots). Left: the original keeps the first
 * loop counter in memory (sp+0x20) and addresses buf+3 as reg+reg, has one
 * more spill word (frame sub sp 0x4c vs 0x48), first byte in sp+0x1c, and
 * spills grp[1] to sp+8. Opus lane to finish.
 *
 * Addresses are Black-image addresses.
 *
 * Note 2026-10-04 (wD2 lane04): n, i, first now sit in the original slots (declare `int n` before
 * `i`, then `first`; 195 bytes differ). Left: the u8 c1 spill (original sp+8, the last slot, below the four
 * loop pointer temps at 0x18..0xc; here 0x18), k lives in memory (sp+4), and buf+3 is formed as
 * `add r1,sp,#0x28; adds r1,#3` then reg+reg (here folded to [r0,#3]); a two-array struct
 * {u8 a[3]; u8 b[3]} did not change that.
 * Note 2026-10-05 (wD4 lane12): MATCH, all 480 bytes. Keys: buf is two
 * separate u8 arrays grp[3] (declared first, lands at sp+0x2B) and cnt[3]
 * (sp+0x28), which gives the `add sp,#0x28; adds #3` reg+reg form; no c0/c1/c2
 * locals (grp[x] re-read, the compiler CSE temp takes the sp+8 slot below the
 * loop temps); no `a` local for va[k]; `s = sh[k][j]` before `r = q + j*12`.
 * Only blocker: arm9 callee 0x0200E47C had no label. Filed it as
 * src/matched/arm9/func_0200E47C.c (EXACT, 10 bytes); this goes EXACT once
 * that file has a shard (integrator).
 * Note 2026-10-04 (wD1 lane06): Not retried (203 bytes, stack slot order only). No new finding.
 */
void func_021BFC60(char *p)
{
    u16 sh[3][17];
    u32 A[3][17];
    u32 B[3][17];
    u32 va[3];
    u32 vb[3];
    u8 grp[3];
    u8 cnt[3];
    int n;
    int i, j, k;
    void *h;
    u8 first;
    h = func_0200E394(func_02012EBC((struct Big *)func_021BF740((u8 *)p)));
    first = func_021BF8B0((u8 *)p);
    i = 0;
    grp[0] = func_0200E44C((int)h, 0);
    grp[1] = func_0200E44C((int)h, 1);
    grp[2] = func_0200E44C((int)h, 2);
    cnt[0] = d_021C367C[grp[0]];
    cnt[1] = d_021C367C[grp[1]];
    cnt[2] = d_021C367C[grp[2]];
    va[0] = func_0200E458(h, grp[0]);
    va[1] = func_0200E458(h, grp[1]);
    va[2] = func_0200E458(h, grp[2]);
    vb[0] = func_0200E47C(h, grp[0]);
    vb[1] = func_0200E47C(h, grp[1]);
    vb[2] = func_0200E47C(h, grp[2]);
    for (i = 0; i < 3; i++) {
        u8 g = grp[i];
        n = cnt[i];
        for (j = 0; j < n; j++) {
            sh[i][j] = d_021C3D44[g][j];
            A[i][j] = func_0200E4B0(h, g, j + 1);
            B[i][j] = func_0200E4F8((int)h, g, j + 1);
        }
    }
    *(u8 *)(p + 0x38) = first;
    for (k = 0; k < 3; k++) {
        char *q = p + k * 0xd4;
        *(u8 *)(q + 0x3c) = grp[k];
        *(u8 *)(q + 0x3d) = cnt[k];
        *(u16 *)(q + 0x3e) = va[k];
        *(u32 *)(q + 0x40) = va[k] + vb[k];
        if (*(u32 *)(q + 0x40) > 999999) {
            *(u32 *)(q + 0x40) = 999999;
        }
        for (j = 0; j < 17; j++) {
            u16 s = sh[k][j];
            char *r = q + j * 12;
            u32 x;
            *(u16 *)(r + 0x44) = s;
            *(u8 *)(r + 0x46) = ((u8 *)&d_021C386C)[s];
            *(u8 *)(r + 0x47) = d_021C3900[s];
            *(u8 *)(r + 0x48) = d_021C3994[s];
            x = A[k][j];
            *(u16 *)(r + 0x4a) = x;
            *(u32 *)(r + 0x4c) = x + B[k][j];
        }
    }
}




void func_021BFE40(u8 *p)
{
    int i;
    for (i = 0; i < 9; i++) {
        p[i * 4 + 0x300] = d_021C3758[i].a;
        p[i * 4 + 0x301] = d_021C3758[i].b;
        p[i * 4 + 0x2fe] = d_021C3758[i].c;
        p[i * 4 + 0x2ff] = d_021C3758[i].d;
    }
}





/*
 * Clear the u32 at +0x2d0.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFE80(void *p)
{
    ((struct ResearchObjB *)p)->f2D0 = 0;
}




void func_021BFE8C(char *p)
{
    struct Params_021BFE8C args;
    args.handles[0] = func_021BF9F0(p, 0);
    args.handles[1] = func_021BF9F0(p, 1);
    args.handles[2] = func_021BF9F0(p, 2);
    args.a = 0;
    args.b = 0;
    args.c = 1;
    args.d = 2;
    args.e = 3;
    ((struct ResearchObjB *)p)->f2D0 = (void *)func_021C2070(((struct ResearchObjB *)p)->f4, (u32)&args);
}





/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 720)), 720 to func_021C209C.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFED4(u8 *a0)
{
    func_021C209C((void *)(((struct ResearchObjB *)a0)->f2D0));
}





/*
 * Clear ten u32 slots at +0x2d4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFEE4(void *p)
{
    int i;
    for (i = 0; i < 10; i++)
        *(u32 *)((char *)p + i * 4 + 0x2d4) = 0;
}




/*
 * lever: p + i * 4 + 0x2d4 keeps the indexed base before the call; p + 0x2d4 + i * 4 differed by 23 bytes.
 */
void func_021BFF00(char *p)
{
    struct Params_021BFF00 args;
    int i;
    args.handles[0] = func_021BF9F0(p, 0);
    args.handles[1] = func_021BF9F0(p, 1);
    args.handles[2] = func_021BF9F0(p, 2);
    args.a = 0;
    args.b = 12;
    args.c = 13;
    for (i = 0; i < 10; i++) {
        *(u32 *)(p + i * 4 + 0x2d4) = func_021C26E8(((struct ResearchObjB *)p)->f4, (u32)&args, func_021BF9FC(p, 3));
        func_021C2740(*(u32 *)(p + i * 4 + 0x2d4), 0);
    }
}





void func_021BFF5C(int *p)
{
    int i;
    for (i = 0; i < 10; i++)
        func_021C270C((void *)p[i + 0xB5]);
}




/*
 * prototype: 0207DCF8 full body fixes r1/r2 and forwards only entry r0 to 02082A60; full target overwrites entry r3 and reads no stack arguments.
 * data: pool 021BFFC4 contains 5c 36 1c 02; contested ov217 hint removed per canonical rule, data a4 resolves sole-ref.
 * volatile: hardware stores 021BFF88/8C/90/94; 04000060 re-read at 021BFF96 and 021BFFA4.
 */
void func_021BFF78(void)
{
    func_0207D988();
    func_0207DB1C();
    *(volatile u32 *)0x04000440 = 0;
    *(volatile u32 *)0x04000454 = 0;
    *(volatile u32 *)0x04000440 = 2;
    *(volatile u32 *)0x04000454 = 0;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x10;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x20;
    func_0207DCF8(d_021C365C);
}
