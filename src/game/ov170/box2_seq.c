/*
 * file:     box2_seq.c
 * unit:     yes
 * function: func_021E09E0, func_021E0A40, func_021E0ABC, func_021E0E50, func_021E0ED4, func_021E0F4C, func_021E0FB0, func_021E0FD8, func_021E122C, func_021E1324, func_021E1458, func_021E152C, func_021E1628, func_021E1988, func_021E19D4, func_021E1A28, func_021E1A78, func_021E1ACC, func_021E1B1C, func_021E1E34, func_021E1E80, func_021E1F90, func_021E2020, func_021E203C, func_021E2054, func_021E2070, func_021E2094, func_021E20D4, func_021E2140, func_021E2154, func_021E216C, func_021E21A0, func_021E22B8, func_021E22E0, func_021E2334, func_021E24EC, func_021E2648, func_021E2650, func_021E2B04, func_021E2B48, func_021E2B88, func_021E2CBC, func_021E3258, func_021E3340, func_021E3568, func_021E35D8, func_021E36A8, func_021E376C, func_021E3B50, func_021E3BF8, func_021E3C38, func_021E3C88, func_021E3E84, func_021E432C, func_021E4470, func_021E4504, func_021E4944, func_021E498C, func_021E49CC, func_021E4A64, func_021E4DE8, func_021E4E6C, func_021E4EAC, func_021E4EE8, func_021E4F60, func_021E5374, func_021E53B0, func_021E543C, func_021E5524, func_021E557C, func_021E58D8, func_021E5914, func_021E594C, func_021E5AD4, func_021E5C5C, func_021E5DD8, func_021E5E08, func_021E5E68, func_021E62BC, func_021E62FC, func_021E6374, func_021E63B0, func_021E6418, func_021E644C, func_021E65E4, func_021E695C, func_021E6A60, func_021E6C3C, func_021E6CD4, func_021E6D00, func_021E6EC0, func_021E7258, func_021E7298, func_021E73D8, func_021E754C, func_021E75E0, func_021E78F4, func_021E7904, func_021E79C8, func_021E7A10, func_021E7BD0, func_021E7C58, func_021E7D04, func_021E7D3C, func_021E7D64, func_021E7E54, func_021E7F6C, func_021E8014, func_021E8024, func_021E8188, func_021E81D0, func_021E8340, func_021E83C0, func_021E8508, func_021E85F0, func_021E86EC, func_021E87A0, func_021E8950, func_021E8A58, func_021E8A74, func_021E8BF8, func_021E8E24, func_021E8F20, func_021E8F50, func_021E8F60, func_021E8F90, func_021E8FC0, func_021E8FD0, func_021E8FE0, func_021E8FE8, func_021E9010, func_021E90D4, func_021E912C, func_021E91A0, func_021E9284, func_021E92A8, func_021E93F4, func_021E941C, func_021E946C, func_021E949C, func_021E94AC, func_021E954C, func_021E95CC, func_021E95F8, func_021E96E8, func_021E9848, func_021E9938, func_021E9968, func_021E99B0, func_021E9B74, func_021E9C94, func_021E9CE0, func_021E9D2C, func_021E9D98, func_021E9DF8, func_021E9E7C, func_021E9EC0, func_021E9F3C, func_021E9FA8, func_021EA020, func_021EA064, func_021EA0BC, func_021EA114, func_021EA14C, func_021EA1C0, func_021EA1E8, func_021EA1F4, func_021EA2DC, func_021EA39C, func_021EA458, func_021EA4DC, func_021EA514, func_021EA598, func_021EA66C, func_021EA728, func_021EA750, func_021EA75C, func_021EA770, func_021EA784, func_021EA798, func_021EA808, func_021EA83C, func_021EA858, func_021EA878, func_021EA8CC, func_021EA908, func_021EA928, func_021EA984, func_021EA9F4, func_021EAA3C, func_021EAA80, func_021EAAC4, func_021EAAE4, func_021EAB04, func_021EAB50, func_021EABA0, func_021EABB8, func_021EABD0, func_021EAC28, func_021EAC98, func_021EACA8, func_021EACFC, func_021EADB4, func_021EAE20, func_021EAE74, func_021EAF20, func_021EAFBC, func_021EB098, func_021EB114, func_021EB190, func_021EB208, func_021EB2A4, func_021EB324, func_021EB378, func_021EB6D8, func_021EB6F0, func_021EB708, func_021EB744, func_021EB79C, func_021EB7C8, func_021EB7E8, func_021EB85C, func_021EB874, func_021EB90C, func_021EB95C, func_021EB988, func_021EBA30, func_021EBA5C, func_021EBA70, func_021EBA84, func_021EBADC, func_021EBAF8, func_021EBB1C, func_021EBB28, func_021EBB34, func_021EBB58, func_021EBB64, func_021EBBBC, func_021EBBC8, func_021EBC28, func_021EBC58, func_021EBCB4, func_021EBD1C, func_021EBD50, func_021EBD78, func_021EBD94, func_021EBDD8, func_021EBDF4, func_021EBE24, func_021EBE4C, func_021EBEAC, func_021EBEE0, func_021EBF34, func_021EBF50, func_021EBF74, func_021EBFA8, func_021EBFCC, func_021EBFEC, func_021EC000, func_021EC01C, func_021EC030, func_021EC048, func_021EC060, func_021EC08C, func_021EC0B0, func_021EC0DC, func_021EC1E8, func_021EC254, func_021EC2A0, func_021EC338, func_021EC35C, func_021EC428, func_021EC45C, func_021EC48C, func_021EC4E0, func_021EC4FC, func_021EC548, func_021EC5A0, func_021EC61C, func_021EC688, func_021EC6F4, func_021EC768, func_021EC7B8, func_021EC804, func_021EC8E4, func_021EC94C, func_021EC994, func_021EC9D8, func_021ECA24, func_021ECA38, func_021ECA6C, func_021ECB20, func_021ECB60, func_021ECB74, func_021ECB84, func_021ECBD8, func_021ECC1C, func_021ECCA4, func_021ECCCC, func_021ECDF4, func_021ECF78, func_021ECFDC, func_021ED028, func_021ED058, func_021ED094, func_021ED108, func_021ED14C, func_021ED164, func_021ED198, func_021ED1C8, func_021ED2F4, func_021ED310, func_021ED370, func_021ED508, func_021ED544, func_021ED55C, func_021ED588, func_021ED594, func_021ED6E4, func_021ED75C, func_021ED7C4
 * address:  0x021E09E0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DE428 0x021DE428 thumb ov170
 *   func_021DDAE8 0x021DDAE8 thumb ov170
 *   func_021DE66C 0x021DE66C thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021E066C 0x021E066C thumb ov170
 *   func_021EF5C4 0x021EF5C4 thumb ov170
 *   func_021EF400 0x021EF400 thumb
 *   func_021EF534 0x021EF534 thumb
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   func_021EF45C 0x021EF45C thumb
 *   func_021DF1DC 0x021DF1DC thumb
 *   func_021DF228 0x021DF228 thumb
 *   func_021DDE80 0x021DDE80 thumb
 *   func_021DEA3C 0x021DEA3C thumb
 *   func_021DD210 0x021DD210 thumb
 *   func_021DEDCC 0x021DEDCC thumb
 *   func_021DEC98 0x021DEC98 thumb
 *   func_021EF180 0x021EF180 thumb
 *   func_021EF35C 0x021EF35C thumb
 *   func_021EF36C 0x021EF36C thumb
 *   func_021EE364 0x021EE364 thumb
 *   func_02026124 0x02026124 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_021EF1B4 0x021EF1B4 thumb
 *   func_021DD16C 0x021DD16C thumb
 *   func_021E00C4 0x021E00C4 thumb
 *   func_021E0128 0x021E0128 thumb
 *   func_021DEAFC 0x021DEAFC thumb
 *   d_021EF79C 0x021EF79C data a1
 *   func_021E0190 0x021E0190 thumb ov170
 *   func_021DE980 0x021DE980 thumb
 *   func_021DEA4C 0x021DEA4C thumb
 *   func_021DEB08 0x021DEB08 thumb ov170
 *   d_021EF7B4 0x021EF7B4 data a1
 *   func_021ED888 0x021ED888 thumb
 *   func_021EF248 0x021EF248 thumb
 *   func_021EF3D8 0x021EF3D8 thumb
 *   func_0202136C 0x0202136C thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_021EE008 0x021EE008 thumb
 *   func_021EDF5C 0x021EDF5C thumb
 *   func_021EDD38 0x021EDD38 thumb
 *   func_020260E4 0x020260E4 thumb
 *   BGWINFRM_IsMoving 0x0202CE40 thumb
 *   func_02035C38 0x02035C38 arm
 *   func_021DD930 0x021DD930 thumb
 *   func_021DE158 0x021DE158 thumb
 *   func_021DE5C8 0x021DE5C8 thumb
 *   func_021DF43C 0x021DF43C thumb
 *   func_021EE3E4 0x021EE3E4 thumb
 *   func_021EF57C 0x021EF57C thumb
 *   func_021E01B0 0x021E01B0 thumb
 *   func_021EF60C 0x021EF60C thumb
 *   func_021EF770 0x021EF770 thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   d_021EFA7C 0x021EFA7C data a4
 *   func_02034AC4 0x02034AC4 arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0204363C 0x0204363C arm
 *   func_0203064C 0x0203064C arm
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   KEY_GetRepeatSpeed 0x02036370 arm
 *   KEY_SetRepeatSpeed 0x02036270 arm
 *   func_021DC9C4 0x021DC9C4 thumb ov170
 *   func_021DC9E0 0x021DC9E0 thumb ov170
 *   func_021DCDB8 0x021DCDB8 thumb ov170
 *   func_021DCB8C 0x021DCB8C thumb ov170
 *   func_021DCE14 0x021DCE14 thumb ov170
 *   func_021DD8D0 0x021DD8D0 thumb ov170
 *   func_021EF274 0x021EF274 thumb ov170
 *   func_021EDB1C 0x021EDB1C thumb ov170
 *   func_021EE2C4 0x021EE2C4 thumb ov170
 *   func_021DCEC0 0x021DCEC0 thumb ov170
 *   func_021DCDF0 0x021DCDF0 thumb ov170
 *   func_0203D34C 0x0203D34C arm
 *   func_021DC94C 0x021DC94C thumb ov170
 *   str_021F140C 0x021F140C data a1
 *   ov067_id 0x00000043 data a1
 *   func_021DC964  0x021DC964  thumb  ov170
 *   func_021DCF30  0x021DCF30  thumb  ov170
 *   func_021EE3CC  0x021EE3CC  thumb  ov170
 *   func_021EF310  0x021EF310  thumb  ov170
 *   func_021DD8F8  0x021DD8F8  thumb  ov170
 *   func_021DCE80  0x021DCE80  thumb  ov170
 *   func_021DCDD8  0x021DCDD8  thumb  ov170
 *   func_021DCB48  0x021DCB48  thumb  ov170
 *   func_02049238  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020306F0  0x020306F0  arm
 *   func_02034A5C  0x02034A5C  arm
 *   PALANM_GetFadeRequestBits   0x02021ED8  thumb
 *   func_02035C60 0x02035C60 arm
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_02027974 0x02027974 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02027858 0x02027858 thumb
 *   d_021EFA4C 0x021EFA4C data a4
 *   func_021DCFC0  0x021DCFC0  thumb  ov170
 *   g_021EFA28  0x021EFA28  data  ov170
 *   d_021EFA2C 0x021EFA2C data a4
 *   func_021DEFEC 0x021DEFEC thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 *   func_0201AA18 0x0201AA18 thumb
 *   func_021EF68C 0x021EF68C thumb ov170
 *   d_021EF9B4 0x021EF9B4 data
 *   d_021EF950 0x021EF950 data
 *   d_021EFA10 0x021EFA10 data
 *   d_021EF918 0x021EF918 data
 *   d_021EF8EC 0x021EF8EC data
 *   func_021EF1FC 0x021EF1FC thumb
 *   func_021DD1C4 0x021DD1C4 thumb
 *   func_021EF170 0x021EF170 thumb
 *   func_020260F4 0x020260F4 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_02035D20 0x02035D20 arm
 *   func_021EF5E8 0x021EF5E8 thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_021DD14C 0x021DD14C thumb
 *   func_021EE65C 0x021EE65C thumb
 *   func_021DF0BC 0x021DF0BC thumb
 *   func_021EEF74 0x021EEF74 thumb
 *   func_021DD530 0x021DD530 thumb ov170
 *   func_021DD238 0x021DD238 thumb
 *   func_021EE754 0x021EE754 thumb
 *   func_021EF1D4 0x021EF1D4 thumb
 *   func_021EE850 0x021EE850 thumb
 *   func_020260F0 0x020260F0 thumb
 *   func_021EF34C 0x021EF34C thumb ov170
 *   func_021EF194 0x021EF194 thumb
 *   func_021EE8A8 0x021EE8A8 thumb
 *   func_021EF3A0 0x021EF3A0 thumb ov170
 *   func_021EF480 0x021EF480 thumb
 *   func_021EF680 0x021EF680 thumb
 *   func_021EF69C 0x021EF69C thumb
 *   func_021EE96C 0x021EE96C thumb
 *   func_021EF1A4 0x021EF1A4 thumb
 *   func_021EF3EC 0x021EF3EC thumb ov170
 *   func_021EECE4 0x021EECE4 thumb
 *   func_021EEDE0 0x021EEDE0 thumb
 *   func_020355C4 0x020355C4 arm
 *   func_021EE57C 0x021EE57C thumb
 *   func_021E070C 0x021E070C thumb ov170
 *   func_021E0068 0x021E0068 thumb ov170
 *   func_021EE474 0x021EE474 thumb
 *   func_021E0778 0x021E0778 thumb
 *   func_021EE520 0x021EE520 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   func_0203633C 0x0203633C arm
 *   func_020077B8 0x020077B8 thumb
 *   func_020076D0 0x020076D0 thumb
 *   func_021EE544 0x021EE544 thumb
 *   func_021E087C 0x021E087C thumb
 *   func_021EEA48 0x021EEA48 thumb
 *   func_021DD2B4 0x021DD2B4 thumb
 *   func_021DD2D0 0x021DD2D0 thumb
 *   func_021DD718 0x021DD718 thumb
 *   func_021DD8A8 0x021DD8A8 thumb
 *   func_021EEB40 0x021EEB40 thumb
 *   func_021EEEA4 0x021EEEA4 thumb
 *   func_021DD908 0x021DD908 thumb ov170
 *   func_021EF508 0x021EF508 thumb
 *   func_021DEF98 0x021DEF98 thumb ov170
 *   func_021DF110 0x021DF110 thumb ov170
 *   func_021EF6A8 0x021EF6A8 thumb ov170
 *   func_021E01A8 0x021E01A8 thumb ov170
 *   func_021DF11C 0x021DF11C thumb ov170
 *   func_021EF6CC 0x021EF6CC thumb ov170
 *   func_021DD694 0x021DD694 thumb ov170
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017E88 0x02017E88 thumb
 *   func_021DE7C8 0x021DE7C8 thumb ov170
 *   func_021DE7B4 0x021DE7B4 thumb ov170
 *   func_021DD314 0x021DD314 thumb
 *   func_021EDAB0 0x021EDAB0 thumb
 *   func_021EDB34 0x021EDB34 thumb
 *   func_021E002C 0x021E002C thumb
 *   d_021EF908 0x021EF908 data a4
 *   func_02007A80 0x02007A80 thumb
 *   d_021EF9C8 0x021EF9C8 data
 *   d_021EF93C 0x021EF93C data
 *   d_021EF964 0x021EF964 data
 *   d_021EF978 0x021EF978 data
 *   d_021EF98C 0x021EF98C data
 *   d_021EF9A0 0x021EF9A0 data
 *   d_021EF9E0 0x021EF9E0 data
 *   d_021EF928 0x021EF928 data
 *   d_021EF9F8 0x021EF9F8 data
 *   func_020216D4 0x020216D4 thumb
 *   func_020056BC 0x020056BC thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   func_021DED58 0x021DED58 thumb ov170
 *   func_02007838 0x02007838 thumb
 *   func_021DC9A0  0x021DC9A0  thumb  ov170
 *   func_021DC9B8  0x021DC9B8  thumb  ov170
 *   func_021DCF58 0x021DCF58 thumb
 *   func_02007E50 0x02007E50 thumb
 *   func_021DEFF8 0x021DEFF8 thumb ov170
 *   func_021DE728 0x021DE728 thumb ov170
 *   func_021DE898  0x021DE898  thumb  ov170
 *   func_021DD090  0x021DD090  thumb  ov170
 *   BGWINFRM_GetBgFrame 0x0202CF8C thumb
 *   data_021EFA10 0x021EFA10 data a1
 *   func_021EF4E4 0x021EF4E4 thumb
 *   func_02007F1C 0x02007F1C thumb
 *   data_021EF918 0x021EF918 data a1
 *   func_021DD1E8 0x021DD1E8 thumb
 *   func_021E01C4 0x021E01C4 thumb
 *   func_021E072C 0x021E072C thumb
 *   func_021DFA30 0x021DFA30 thumb
 *   func_021E0470  0x021E0470  thumb  ov170
 *   func_021DF484 0x021DF484 thumb
 *   func_021E0200 0x021E0200 thumb
 *   func_021EF32C  0x021EF32C  thumb  ov170
 *   func_021EF33C  0x021EF33C  thumb  ov170
 *   d_021F140C 0x021F140C data a1
 *   func_021EF75C  0x021EF75C  thumb  ov170
 *   func_0202614C 0x0202614C thumb
 *   d_021EF8FC 0x021EF8FC data a1
 *   d_021EF8F4 0x021EF8F4 data a1
 *   func_02045088 0x02045088 arm
 *   func_020450F0 0x020450F0 arm
 *   d_021EFC20 0x021EFC20 data a1
 *   func_02045334 0x02045334 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045770 0x02045770 arm
 *   func_02045374  0x02045374  arm  arm9
 *   func_02045730  0x02045730  arm  arm9
 *   func_02041B6C  0x02041B6C  arm  arm9
 *   func_020456F8  0x020456F8  arm  arm9
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045B38  0x02045B38  arm  arm9
 *   func_02043B5C 0x02043B5C arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201EEA4 0x0201EEA4 thumb
 *   func_0201EF14 0x0201EF14 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201EF98 0x0201EF98 thumb
 *   func_0201EF8C 0x0201EF8C thumb
 *   func_0201EF40 0x0201EF40 thumb
 *   func_02045758 0x02045758 arm
 *   func_02045760 0x02045760 arm
 *   func_02045738 0x02045738 arm
 *   func_02045740 0x02045740 arm
 *   func_02049DB4 0x02049DB4 arm
 *   func_020436FC 0x020436FC arm
 *   func_020439A0 0x020439A0 arm
 *   func_020437AC 0x020437AC arm
 *   func_020275E4 0x020275E4 thumb
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   BGWINFRM_AddFrame 0x0202CA3C thumb
 *   BGWINFRM_PutBmpWin 0x0202CEBC thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0200785C 0x0200785C thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_020257D0 0x020257D0 thumb
 *   func_020078C4 0x020078C4 thumb
 *   BGWINFRM_ChangePalette 0x0202CE50 thumb
 *   BGWINFRM_GetSize 0x0202CFC0 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_0201F7A8  0x0201F7A8  thumb  ov170
 *   func_021EE0FC 0x021EE0FC thumb
 *   func_021EE120 0x021EE120 thumb ov170
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_021EE200  0x021EE200  thumb  ov170
 *   func_021DC9D8 0x021DC9D8 thumb ov170
 *   func_0204A48C 0x0204A48C arm
 *   d_021EFD64 0x021EFD64 data a4
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B100 0x0204B100 arm
 *   func_021ED824 0x021ED824 thumb ov170
 *   func_0204B294 0x0204B294 arm
 *   func_0204BA20 0x0204BA20 arm
 *   func_0204B98C  0x0204B98C  arm  arm9
 *   func_0204B3F4  0x0204B3F4  arm  arm9
 *   func_0204B688 0x0204B688 arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02027618 0x02027618 thumb
 *   func_02027614 0x02027614 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   d_021EFD04 0x021EFD04 data a4
 *   _u32_div_f 0x0209C2B0 arm
 *   func_020079BC 0x020079BC thumb
 *   MIi_CpuCopy32 0x02082A90 arm
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   d_021EFD4C 0x021EFD4C data a2
 *   BGWINFRM_GetPos 0x0202CF98 thumb
 *   d_021EFCE0 0x021EFCE0 data a1
 *   _ffix 0x0209C494 arm
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 *   CLACT_SetActorAffineOrigin 0x0204B588 arm
 *   _fsub 0x0209CB8C arm
 *   _fadd 0x0209C95C arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_02017DBC 0x02017DBC thumb
 *   func_0202D934 0x0202D934 thumb
 *   func_0202D8D0 0x0202D8D0 thumb
 *   func_0202D9A4 0x0202D9A4 thumb
 *   func_02017DE4 0x02017DE4 thumb
 *   d_021EFD80 0x021EFD80 data a4
 *   func_020275F8 0x020275F8 thumb
 *   func_020275FC 0x020275FC thumb
 *   func_02027600 0x02027600 thumb
 *   func_020275E8 0x020275E8 thumb
 *   func_0202774C 0x0202774C thumb
 *   func_02027750 0x02027750 thumb
 *   func_02027754 0x02027754 thumb
 *   func_02027748 0x02027748 thumb
 *   func_0202776C 0x0202776C thumb
 *   func_02027770 0x02027770 thumb
 *   func_02027774 0x02027774 thumb
 *   func_02027768 0x02027768 thumb
 *   d_021EFD34 0x021EFD34 data a4
 *   func_020275EC 0x020275EC thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02020E60 0x02020E60 thumb
 *   func_02020F08 0x02020F08 thumb
 *   func_02049E34 0x02049E34 arm
 *   CLACT_GetActorCharacterIndex 0x0204B7F0 arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_02049F34 0x02049F34 arm
 *   CLACT_GetActorPaletteIndex 0x0204B7F8 arm
 *   func_0204ADEC 0x0204ADEC arm
 *   CLACT_GetActorDrawPriority 0x0204B838 arm
 *   CLACT_GetActorBgPriority 0x0204B864 arm
 *   d_021EFE70 0x021EFE70 data a1
 *   d_021EFCD0 0x021EFCD0 data a1
 *   d_021EFCC8 0x021EFCC8 data a1
 *   CLACT_GetActorImageProxy 0x0204B7C8 arm
 *   CLACT_SetActorImageProxy 0x0204B784 arm
 *   CLACT_TransferCharacterPart  0x0204AA94  arm  arm9
 *   CLACT_SetActorDrawPriority  0x0204B800  arm  arm9
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm  arm9
 *   CLACT_AddActorAnimFrame  0x0204B8D4  arm  arm9
 *   CLACT_GetActorAutoAnim  0x0204B944  arm  arm9
 */
#include "box2_types.h"
#include "../../matched/include/Obj23878.h"
#include "../../matched/include/Obj14264.h"
#include "../../matched/include/Obj08237.h"
#include "../../matched/include/Obj23881.h"
#include "../../matched/include/Obj23882.h"
#include "../../matched/include/Obj23883.h"
#include "../../matched/include/Obj23884.h"
#include "../../matched/include/Obj23885.h"
#include "../../matched/include/Obj23886.h"
#include "../../matched/include/Obj18463.h"
#include "../../matched/include/Obj12157.h"
#include "../../matched/include/Obj09224.h"
#include "../../matched/include/Obj10654.h"
#include "../../matched/include/Obj23887.h"
#include "../../matched/include/Obj23888.h"
#include "../../matched/include/Obj23889.h"
#include "../../matched/include/Obj23890.h"
#include "../../matched/include/Obj23891.h"
#include "../../matched/include/Obj23892.h"
#include "../../matched/include/Obj23893.h"
#include "../../matched/include/Obj23894.h"
#include "../../matched/include/Obj23895.h"
#include "../../matched/include/Obj23896.h"
#include "../../matched/include/Obj23897.h"
#include "../../matched/include/Obj23898.h"
#include "../../matched/include/Obj23899.h"
#include "../../matched/include/Obj23900.h"
#include "../../matched/include/Obj23901.h"
#include "../../matched/include/Obj23902.h"
#include "../../matched/include/Obj23904.h"
#include "../../matched/include/Obj23905.h"
#include "../../matched/include/Obj23906.h"
#include "../../matched/include/Obj23907.h"
#include "../../matched/include/Obj23908.h"
#include "../../matched/include/Obj23909.h"
#include "../../matched/include/Obj23910.h"
#include "../../matched/include/Obj23911.h"
#include "../../matched/include/Obj23912.h"
#include "../../matched/include/Obj23913.h"
#include "../../matched/include/Obj23914.h"
#include "../../matched/include/Obj23915.h"
#include "../../matched/include/Obj23916.h"
#include "../../matched/include/Obj23917.h"
#include "../../matched/include/Obj23918.h"
#include "../../matched/include/Obj23919.h"
#include "../../matched/include/Obj23920.h"
#include "../../matched/include/Obj23921.h"
#include "../../matched/include/Obj23922.h"
#include "../../matched/include/Obj23923.h"
#include "../../matched/include/Obj23924.h"
#include "../../matched/include/Obj23925.h"
#include "../../matched/include/Obj23926.h"
#include "../../matched/include/Obj23927.h"
#include "../../matched/include/Obj18467.h"
#include "../../matched/include/Obj23928.h"
#include "../../matched/include/Obj23929.h"
#include "../../matched/include/Obj23930.h"
#include "../../matched/include/Obj23931.h"
#include "../../matched/include/Obj23932.h"
#include "../../matched/include/Obj23933.h"
#include "../../matched/include/Obj23934.h"
#include "../../matched/include/Obj23935.h"
#include "../../matched/include/Obj23936.h"
#include "../../matched/include/Obj23937.h"
#include "../../matched/include/Obj23938.h"
#include "../../matched/include/Obj23940.h"
#include "../../matched/include/Obj18468.h"
#include "../../matched/include/Obj18469.h"
#include "../../matched/include/Obj18470.h"
#include "../../matched/include/Obj23942.h"
#include "../../matched/include/Obj23943.h"
#include "../../matched/include/Obj23944.h"
#include "../../matched/include/Obj05869.h"
#include "../../matched/include/Obj23945.h"
#include "../../matched/include/Obj23946.h"
#include "../../matched/include/Obj23947.h"
#include "../../matched/include/Obj23948.h"
#include "../../matched/include/Obj23949.h"
#include "../../matched/include/Obj23950.h"
#include "../../matched/include/Obj23951.h"
#include "../../matched/include/Obj23952.h"
#include "../../matched/include/Obj23953.h"
#include "../../matched/include/Obj23954.h"
#include "../../matched/include/Obj23957.h"
#include "../../matched/include/Obj18479.h"
#include "../../matched/include/Obj18480.h"
#include "../../matched/include/Obj18488.h"
#include "../../matched/include/Obj18489.h"
#include "../../matched/include/Obj18491.h"
#include "../../matched/include/Obj18493.h"
#include "../../matched/include/Obj18495.h"
#include "../../matched/include/Obj23958.h"
#include "../../matched/include/Obj12168.h"
#include "../../matched/include/Obj23959.h"
#include "../../matched/include/Obj23961.h"
#include "../../matched/include/Obj18507.h"
#include "../../matched/include/Obj08242.h"
#include "../../matched/include/Obj23962.h"
#include "../../matched/include/Obj00414.h"
#include "../../matched/include/Obj23964.h"
#include "../../matched/include/Obj02053.h"
#include "../../matched/include/Obj06549.h"
#include "../../matched/include/Obj23969.h"
#include "../../matched/include/Obj23970.h"
#include "../../matched/include/Obj23971.h"
#include "../../matched/include/Obj23973.h"
#include "../../matched/include/Obj23974.h"
#include "../../matched/include/Obj23975.h"
#include "../../matched/include/Obj23977.h"
#include "../../matched/include/Obj23978.h"
#include "../../matched/include/Obj23979.h"
#include "../../matched/include/Obj23980.h"
#include "../../matched/include/Obj23981.h"
#include "../../matched/include/Obj23982.h"
#include "../../matched/include/Obj23983.h"
#include "../../matched/include/Obj23984.h"
#include "../../matched/include/Obj23985.h"
#include "../../matched/include/Obj23986.h"
#include "../../matched/include/Obj23987.h"
#include "../../matched/include/Obj23988.h"
#include "../../matched/include/Obj23989.h"
#include "../../matched/include/Obj18517.h"
#include "../../matched/include/Obj18518.h"
#include "../../matched/include/Obj23990.h"
#include "../../matched/include/Obj23991.h"
#include "../../matched/include/Obj23992.h"
#include "../../matched/include/Obj23993.h"
#include "../../matched/include/Obj23994.h"
#include "../../matched/include/Obj23995.h"
#include "../../matched/include/Obj23996.h"
#include "../../matched/include/Obj23997.h"
#include "../../matched/include/Obj24001.h"
#include "../../matched/include/Obj24002.h"
#include "../../matched/include/Obj24003.h"
#include "../../matched/include/Obj24004.h"
#include "../../matched/include/Obj24005.h"
#include "../../matched/include/Obj24008.h"
#include "../../matched/include/Obj24010.h"
#include "../../matched/include/Obj24012.h"
#include "../../matched/include/Obj24013.h"
#include "../../matched/include/Obj24014.h"
#include "../../matched/include/Obj24015.h"
#include "../../matched/include/Obj24016.h"
#include "../../matched/include/Obj05439.h"
#include "../../matched/include/Obj04547.h"
#include "../../matched/include/Obj24017.h"
#include "../../matched/include/Obj14276.h"
#include "../../matched/include/Obj08247.h"
#include "../../matched/include/Obj24020.h"
#include "../../matched/include/Obj24021.h"
#include "../../matched/include/Obj24022.h"

#define SYS(p) (*(unsigned **)(p))
#define NEXT(p) (*(int *)(W(p)+0xA198))
#define TOP(p) (*(char **)(p))
#define SUB(p) (*(s16_021E09E0 *)(WORK(p) + 0xA16C))
#define STATE(p) (*(int *)((p) + 0x28))
#define SCROLL(p) (*(Scroll **)(WORK(p) + 0xA190))
#define LASTY(p) (*(unsigned *)(WORK(p) + 0xA184))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LO(p) (((Nib_021E09E0 *)((p)+0x1C))->lo)
#define LIST(p) (*(void **)(WORK(p) + 0x70))
#define HELD(p) (*(unsigned char *)(WORK(p) + 0xA17E))
#define WIN(p, i) (*(unsigned char *)(WORK(p) + (i) + 0x3DD2))
#define TGT(p) (*(unsigned char *)(WORK(p) + 0xA17E))
#define S (*(int *)(W + 0xA194))
#define M (*(struct WinMgr **)(W + 0x74))
#define KIND(p) (*(unsigned char *)(WORK(p) + 0xA17C))
#define SAVE(p) (*(void **)(*(char **)(p) + 4))
#define HELD_WIN(p) (*(unsigned char *)(WORK(p) + 0x3DF6))
#define HEAP 0x804C
#define HND(p) (*(int *)((p) + 0x9E9C))
#define CELL(w, k) (*(void **)((w) + (k) * 4 + 0x9E74))
struct WinMgr;
struct Sound;
struct PrintSys;
struct Ov170Ctx;
struct TaskMenu;
struct Struct_02025CD0;
struct PalAnmSlot;
struct Descriptor;
struct Cfg;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct CharBuf;
struct Rec;
struct StrObj;
struct Bmp;
struct Obj020437AC;
struct Obj;
struct Bank;
struct Actor;
struct Slots_021EBF34;
struct Node;
struct Vec2;
struct PtS;
struct Pair;
struct Pt;
struct Sav;
struct Sub0204A9D0;
struct Struct36;
typedef unsigned int   u32;

typedef struct {
    unsigned char pad[0xC];
    unsigned short state;
    unsigned short timer;
} Blk_021E0ABC;

typedef struct {
    unsigned char pad[0xC];
    unsigned short state;
    unsigned short timer;
} Blk_021E0FD8;

typedef struct {
    unsigned short idx;
    unsigned short slot;
} Entry;

typedef struct {
    unsigned char pad[8];
    Entry *entry;
    unsigned short state;
} Blk_021E122C;

typedef struct {
    unsigned char pad[0xC];
    unsigned short state;
    unsigned short cnt;
} Blk_021E1324;

typedef struct {
    unsigned char pad[0xC];
    unsigned short state;
    unsigned short cnt;
} Blk_021E1458;

typedef struct {
    unsigned char pad[0xC];
    unsigned short state;
} Blk_021E152C;

typedef struct {
    unsigned char pad[0xC];
    unsigned short state;
    unsigned short timer;
} Blk_021E1628;

typedef struct {
    unsigned char pad[0xE];
    unsigned short fE;
} Blk_021E19D4;

typedef unsigned char  u8;

typedef struct {
    unsigned char pad[0xE];
    unsigned short fE;
} Blk_021E1A28;

typedef struct { unsigned char pad[0xE]; unsigned short fE; } Blk_021E1A78;

typedef struct { unsigned char pad[0xE]; unsigned short fE; } Blk_021E1ACC;

typedef struct {
    unsigned char pad[8];
    void *moves;
    unsigned short state;
    unsigned short timer;
} Blk_021E1B1C;

typedef unsigned short u16;

struct BoxCountWork {
    char pad[0xA18C];
    int count;
};

typedef struct { int (*a)(char *); int (*b)(char *); } Pair;

typedef struct { void (*callback)(u8 *); u32 value; u32 next; } Dispatch;

typedef short s16_021E09E0;

typedef struct {
    short left;
    short dir;
} Scroll;

typedef struct BoxTop {
    unsigned char pad0[4];
    void *x4;
    unsigned char pad8[0x24 - 8];
    int x24;
    unsigned short h28;
    unsigned char b2A;
    unsigned char b2B;
} BoxTop;

typedef struct BoxObj {
    BoxTop *top;
    unsigned char pad4[0x13 - 4];
    unsigned char b13;
    unsigned char b14;
    unsigned char b15;
    unsigned char b16;
    unsigned char b17;
    unsigned char b18;
    unsigned char b19;
    unsigned char b1A;
    unsigned char b1B;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char b1D;
    unsigned char pad1E[0x24 - 0x1E];
    int x24;
    int x28;
    char *work;
} BoxObj;

typedef struct { u8 lo:4; u8 hi:4; } Nib_021E09E0;

typedef struct {
    unsigned char lo : 4;
    unsigned char hi : 4;
} Nib_021E65E4;

typedef struct { unsigned char pad[0x1C]; unsigned char lo:4; unsigned char hi:4; } Flags_021E65E4;

typedef struct { unsigned short a; unsigned short b; } Ent;

typedef struct { u8 pad[0x1c]; u8 lo : 4; u8 hi : 4; } Flags_021E8340;

typedef signed short s16_021E65E4;

typedef struct BoxWorkView {
    unsigned char pad[0x1A6];
    unsigned char flag : 1;
    unsigned char id : 7;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char state;
    unsigned char count;
    unsigned char x;
    unsigned char y;
    unsigned char w;
    unsigned char h;
} BoxWorkView;

typedef struct { unsigned value; unsigned char pad[14]; unsigned char low:7; unsigned char flag:1; } Entry_021EADB4;

typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; unsigned char kind : 4; unsigned char enabled : 1; unsigned char rest : 3; } Entry_021EAE74;

typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; unsigned char kind : 4; unsigned char enabled : 1; unsigned char rest : 3; } Entry_021EAF20;

typedef struct { unsigned char pad[18]; unsigned char low:7,high:1; } Entry_021EAFBC;

typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; } Entry_021EB098;

typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; } Entry_021EB114;

typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; } Entry_021EB190;

typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; unsigned char kind : 4; unsigned char enabled : 1; unsigned char rest : 3; } Entry_021EB208;

typedef struct {
    void *obj;
    int pad;
} Item;

typedef struct {
    unsigned char pad[0x94];
    Item items[14];
} Work;

typedef struct {
    unsigned char pad[0x14];
    char *raw;
} Chr;

typedef signed int s32;

typedef struct {unsigned a,b,c,d,e,f,g;} Template;

typedef struct {
    short x;
    short y;
    unsigned char pad4[2];
    unsigned char b6;
    unsigned char b7;
    int a;
    int b;
    int c;
    unsigned short e;
    unsigned short d;
} Desc;

typedef struct {
    Desc a[13];
    Desc b[6];
    Desc c[6];
    Desc d[3];
} DescTable;

struct Slots_021EBF34 { char pad[0x9E74]; int arr[1]; };

typedef struct { short x; short y; } Pos_021EC548;

typedef struct { short x; short y; } Pos_021EC5A0;

typedef struct {
    short x;
    short y;
} Pos_021EC61C;

typedef struct { short x, y; } Pos_021EC688;

typedef struct { short x, y; } Pos_021EC6F4;

typedef struct { unsigned char a; unsigned char b; } Off;

typedef signed char s8;

typedef struct {
    int pad[9];
    int x24;
} Top;

typedef struct {unsigned char low:7;unsigned char high:1;} Flag;

struct Slot { unsigned char a[0x1c]; unsigned char f : 4; };

typedef struct {
    int w[9];
} Struct36;

extern void func_021DE428(unsigned char *p, unsigned a, unsigned b);
extern int func_021DDAE8(unsigned char *p);
extern void func_021DE66C(char *p, void *a);
extern void func_020061E4(u32 a);
extern int func_021E066C(char *p);
extern int func_021EF5C4(struct WinMgr *mgr);
extern int func_021EF400(unsigned char *p);
extern void func_021EF534(struct WinMgr *mgr);
extern unsigned TOUCHPANEL_GetPointCont(unsigned *outA, unsigned *outB);
extern int func_021EF45C(struct WinMgr *mgr);
extern int func_021DF1DC(short x, int y);
extern int func_021DF228(short x, short y, const unsigned char *r);
extern int func_021DDE80(unsigned char *p, unsigned a, unsigned b);
extern void func_021DEA3C(int a, int b, int c, int d);
extern int func_021DD210(unsigned char *p, unsigned a, unsigned b);
extern int func_021DEDCC(char *p, int box);
extern void func_021DEC98(char *p, void *a, int dir);
extern int func_021EF180(int a, int b);
extern void func_021EF35C(struct WinMgr *mgr);
extern void func_021EF36C(struct WinMgr *mgr);
extern void func_021EE364(char **p, int idx, int v);
extern void func_02026124(struct Sound *obj, u32 idx);
extern void func_021EE038(char *p, int a, int b, int c);
extern int func_021EF1B4(void);
extern void func_021DD16C(unsigned char *p, int dir);
extern int func_021E00C4(char *p);
extern int func_021E0128(char *p);
extern int func_021DEAFC(int a);
extern int func_021E0190(char *p);
extern void func_021DE980(unsigned char *p, int mode);
extern void func_021DEA4C(char *p, int a, int b);
extern int func_021DEB08(unsigned char *p);
extern void func_021ED888(char *w, int a);
extern int func_021EF248(void);
extern void func_021EF3D8(struct WinMgr *mgr);
extern unsigned func_0202136C(unsigned short v);
extern u8 func_020260E0(struct Sound *obj);
extern void func_021EE008(char *p, int a, int b);
extern void func_021EDF5C(unsigned char *p);
extern void func_021EDD38(char *p, int d);
extern u32 BGWINFRM_IsMoving(struct WinMgr *mgr, u32 idx);
extern int func_021E01B0(unsigned char *p);
extern int func_02035C38(void);
extern void func_021EF57C(struct WinMgr *mgr);
extern int func_021EF770(struct WinMgr *mgr);
extern int func_021DE158(unsigned char *p, unsigned a, unsigned b);
extern int func_021EF60C(struct WinMgr *mgr);
extern int func_021DE5C8(char *p, unsigned id);
extern void func_021DF43C(char *p, int x, int y);
extern int func_021DD930(unsigned char *p);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE3E4(char **p, unsigned idx);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int func_02034AC4(int);
extern void func_02043534(unsigned);
extern void func_020435F4(unsigned);
extern void func_0204363C(unsigned);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(u32 id, u32 heap);
extern void KEY_GetRepeatSpeed(u32 *outA, u32 *outB);
extern int KEY_SetRepeatSpeed(int a0, int a1);
extern void func_021DC9C4(void);
extern void func_021DC9E0(u8 *);
extern void func_021DCDB8(char *p);
extern void func_021DCB8C(struct Ov170Ctx *ctx);
extern void func_021DCE14(char *);
extern void func_021DD8D0(char *p);
extern void func_021EF274(char *);
extern void func_021EDB1C(int p);
extern void func_021EE2C4(char **);
extern void func_021DCEC0(char *);
extern void func_021DCDF0(int);
extern void func_0203D34C(unsigned,unsigned);
extern void func_021DC94C(char *p);
extern void func_021DC964(char *p);
extern void func_021DCF30(char *p);
extern void func_021EE3CC(int *p);
extern void func_021EF310(char *p);
extern void func_021DD8F8(char *p);
extern void func_021DCE80(char *p);
extern void func_021DCDD8(int *p);
extern void func_021DCB48(void *p);
extern void func_02049238(void *a);
extern u32 func_020307B0(void *p);
extern void func_020306F0(unsigned int a);
extern void func_02034A5C(int a);
extern u32 func_020221A4(void);
extern u32 PALANM_GetFadeRequestBits(const char *ptr);
extern int func_02035C60(void);
extern u32 func_020362DC(void);
extern void func_020355D8(u8 v);
extern void func_02027974(void *);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_02027858(struct TaskMenu *m);
extern int func_021DCFC0(char *p);
extern void func_021DEFEC(char *p, int b);
extern void func_021EF670(char *);
extern u32 func_0201AA18(void *p);
extern void func_021EF68C(char *);
extern int func_021EF1FC(unsigned *a, unsigned *b);
extern void func_021DD1C4(char *p, int a);
extern unsigned func_021EF170(void);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021EF5E8(struct WinMgr *mgr);
extern void func_021DF040(char *p);
extern void func_021DD14C(char *p);
extern unsigned func_021EE65C(char *p);
extern void func_021DF0BC(unsigned char *p);
extern void func_021EEF74(char *w, int k, int v);
extern void func_021DD530(unsigned char *);
extern void func_021DD238(char *p);
extern void func_021EE754(unsigned char *p, unsigned r);
extern int func_021EF1D4(unsigned *a, unsigned *b);
extern unsigned func_021EE850(char *p);
extern u32 func_020260F0(struct Sound *obj);
extern void func_021EF34C(struct WinMgr *mgr);
extern unsigned func_021EF194(void);
extern unsigned func_021EE8A8(char *p);
extern u8 func_020355C4(void);
extern int func_021EF480(struct WinMgr *mgr);
extern void func_021EF3A0(struct WinMgr *mgr);
extern void func_021EF680(char *w);
extern void func_021EF69C(char *w);
extern unsigned func_021EE96C(char *p);
extern unsigned func_021EF1A4(void);
extern void func_021EF3EC(struct WinMgr *mgr);
extern unsigned func_021EECE4(char *p);
extern unsigned func_021EEDE0(char *p);
extern unsigned func_021EE57C(char *p);
extern int func_021E070C(char *p);
extern int func_021E0068(char *p);
extern unsigned func_021EE474(char *p);
extern int func_021E0778(unsigned char *p);
extern void func_021EE520(char *p, unsigned idx);
extern int func_02025DE8(struct Sound *obj);
extern unsigned int func_0203633C(void);
extern int func_020077B8(void *save, u32 box);
extern int func_020076D0(void *save, int *pbox, int *pslot);
extern void func_021EE544(char *p, unsigned int i);
extern int func_021E087C(unsigned char *p);
extern unsigned func_021EEA48(char *p);
extern void func_021DD2B4(int a, int b, int c, int d, int e);
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern int func_021DD718(void **pp, void *mon);
extern void func_021DD8A8(void **pp, u32 idx);
extern unsigned func_021EEB40(char *p);
extern unsigned func_021EEEA4(char *p);
extern int func_021DD908(char *p, u32 a);
extern void func_021EF508(struct WinMgr *mgr);
extern int func_021DEF98(char *p, int a, unsigned b);
extern void func_021DF110(char *p, int b);
extern void func_021EF6A8(struct WinMgr *mgr);
extern int func_021E01A8(char *p);
extern void func_021DF11C(char *p, int b);
extern void func_021EF6CC(struct WinMgr *mgr);
extern int func_021DD694(void ***, unsigned);
extern void *func_0201AB28(void *, unsigned);
extern unsigned func_02017E1C(void *, unsigned, unsigned);
extern unsigned func_02017E88(void *, unsigned, unsigned);
extern int func_021DE7C8(unsigned char *p);
extern void func_021DE7B4(char *p);
extern void func_021DD314(char **p, int a, unsigned b);
extern void func_021EDAB0(char *p, int i);
extern void func_021EDB34(char *p, int a);
extern int func_021E002C(unsigned char *p);
extern int func_02007A80(void *save, unsigned bits);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern u32 func_020056BC(void);
extern int PALANM_RequestFade(void *, u16, u16, s16_021E65E4, u8, u8, u16, void *);
extern void func_021DED58(char *, int);
extern void func_02007838(void *save, u32 box, u8 v);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021DC9A0(char *, int);
extern void func_021DC9B8(char *);
extern void func_021DCF58(unsigned char *p, int sel);
extern u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern void func_021DEFF8(char *p, unsigned b);
extern void func_021DE728(unsigned char *p);
extern void func_021DE898(int *q);
extern void func_021DD090(char *, int);
extern u8 BGWINFRM_GetBgFrame(struct WinMgr *mgr, u32 idx);
extern void func_021EF4E4(struct WinMgr *mgr);
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern void func_021DD1E8(char *p);
extern int func_021E01C4(char *p);
extern void func_021E072C(unsigned char *p);
extern int func_021DFA30(unsigned char *p);
extern int func_021E0470(unsigned char *p);
extern int func_021DF484(unsigned char *p);
extern int func_021E0200(unsigned char *p);
extern void func_021EF32C(struct WinMgr *mgr);
extern void func_021EF33C(struct WinMgr *mgr);
extern void func_021EF75C(struct WinMgr *mgr);
extern void func_0202614C(struct Sound *obj, u32 idx);
extern void func_02045088(u16 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern void func_02045334(struct Descriptor *d);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void *func_02045770(struct Descriptor *p);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned int);
extern void func_020456F8(struct Descriptor *d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32 func_02045C04(struct Rec *rec);
extern void func_0201EEA4(struct WordSet *p, u32 i, void *mon);
extern void func_0201EF14(struct WordSet *p, u32 i, void *mon);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201EF98(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF8C(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern struct Bmp *func_020436FC(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void func_020437AC(struct Obj020437AC *p);
extern unsigned func_020275E4(void);
extern void func_021B6AE4(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern void BGWINFRM_AddFrame(void *,unsigned,unsigned,unsigned,unsigned);
extern void BGWINFRM_PutBmpWin(void *,unsigned,void *);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0200785C(void *save, unsigned box, void *dest);
extern void func_0201C7D0(void *x, short y, short z, void *s, void *w, unsigned short v);
extern void func_020257D0(struct Obj *o);
extern int func_020078C4(void *save, u32 box);
extern void BGWINFRM_ChangePalette(struct WinMgr *mgr, u32 idx, s32 x, s32 y, u8 w, u8 h, u8 pal);
extern void BGWINFRM_GetSize(struct WinMgr *mgr, u32 idx, u16 *w, u16 *h);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201F7A8(void *, int);
extern void func_021EE0FC(char *p);
extern void func_021EE120(char *p);
extern void func_020434DC(unsigned, unsigned);
extern void func_02043598(unsigned, unsigned);
extern void func_021EE200(char *);
extern void func_0204A5AC(void);
extern unsigned func_021DC9D8(void);
extern void func_0204A48C(Template *,unsigned,unsigned);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_021ED824(char *);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204BA20(struct Actor *a, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_0204B1CC(struct Bank *bank);
extern u32 CLACT_GetActorAutoAnim(struct Obj *p);
extern void CLACT_AddActorAnimFrame(struct Obj *p, u32 arg);
extern void func_0204A600(void);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *, unsigned int);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern u32 func_0204B3F4(struct Obj *p);
extern void func_0204B84C(int, int);
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern unsigned func_02027618(void);
extern unsigned func_02027614(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern u32 func_0201BA68(void *mon);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_020079BC(void **save, u32 box, u32 slot, int field, int arg);
extern void MIi_CpuCopy32(const void *src, void *dst, unsigned size);
extern int POKE_TOOL_GetIconPalette(void *a0);
extern u16 CLACT_GetActorCharacterIndex(u8 *p);
extern void CLACT_TransferCharacterPart(int a, void *b, u32 c, int d, int e);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void *POKE_TOOL_GetBoxParam(void *);
extern void BGWINFRM_GetPos(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);
extern void CLACT_SetActorScale(struct Obj *dst, struct Pair *src);
extern void CLACT_SetActorAffineOrigin(struct Actor *actor, const struct Pt *src);
extern int func_0202D7C8(int);
extern u32 func_02017DBC(struct Sav *p);
extern int func_0202D934(int,void *,int,int,u16);
extern int func_0202D8D0(int,void *,int,int,u32,u16);
extern u32 func_0202D9A4(u32,u32,u32,u32,u16);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern unsigned int func_020275F8(unsigned int a);
extern u32 func_020275FC(u32 a);
extern u32 func_02027600(u32 a);
extern unsigned func_020275E8(void);
extern int func_0202774C(int a);
extern int func_02027750(int a);
extern int func_02027754(int a);
extern int func_02027748(void);
extern int func_0202776C(int a);
extern int func_02027770(int a);
extern int func_02027774(int a);
extern int func_02027768(void);
extern u8 func_020275EC(int i);
extern unsigned func_02020E60(unsigned,unsigned);
extern unsigned func_02020F08(void);
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern u16 CLACT_GetActorPaletteIndex(u8 *p);
extern void func_0204ADEC(void *dst, void *src, unsigned flag);
extern int CLACT_GetActorDrawPriority(int a0);
extern u32 CLACT_GetActorBgPriority(u8 *a0);
extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);
extern void CLACT_SetActorImageProxy(char *dst, const struct Struct36 *src);
int func_021E09E0(char *p);
int func_021E0A40(char *p);
int func_021E0ABC(unsigned char *p);
int func_021E0E50(char *p);
int func_021E0ED4(unsigned char *p);
int func_021E0F4C(unsigned char *p);
void func_021E0FB0(char *w, int x, int y);
int func_021E0FD8(unsigned char *p);
int func_021E122C(unsigned char *p);
int func_021E1324(char *p);
int func_021E1458(char *p);
int func_021E152C(unsigned char *p);
int func_021E1628(unsigned char *p);
int func_021E1988(unsigned char *p);
int func_021E19D4(char *p);
int func_021E1A28(char *p);
int func_021E1A78(char *p);
int func_021E1ACC(char *p);
int func_021E1B1C(unsigned char *p);
int func_021E1E34(char *p, int *state);
int func_021E1E80(u8 *p);
int func_021E1F90(u8 *p);
int func_021E2020(char *p);
int func_021E203C(void *p);
int func_021E2054(void *p);
int func_021E2070(char *p);
int func_021E2094(char *p);
int func_021E20D4(char *p);
int func_021E2140(int p);
int func_021E2154(unsigned char *p);
int func_021E216C(u8 *p);
int func_021E21A0(u8 *p);
int func_021E22B8(int p);
int func_021E22E0(unsigned char *p);
int func_021E2334(unsigned char *p);
int func_021E24EC(unsigned char *p);
int func_021E2648(unsigned char *p);
int func_021E2650(BoxObj *p);
int func_021E2B04(unsigned char *p);
void func_021E2B48(char *p);
int func_021E2B88(u8 *p);
int func_021E2CBC(BoxObj *p);
int func_021E3258(u8 *p);
int func_021E3340(unsigned char *p);
int func_021E3568(unsigned char *p);
int func_021E35D8(u8 *p);
int func_021E36A8(unsigned char *p);
int func_021E376C(BoxObj *p);
int func_021E3B50(unsigned char *p);
void func_021E3BF8(char *p);
int func_021E3C38(unsigned char *p);
int func_021E3C88(unsigned char *p);
int func_021E3E84(BoxObj *p);
int func_021E432C(u8 *p);
int func_021E4470(unsigned char *p);
int func_021E4504(BoxObj *p);
int func_021E4944(unsigned char *p);
void func_021E498C(char *p);
int func_021E49CC(unsigned char *p);
int func_021E4A64(BoxObj *p);
int func_021E4DE8(unsigned char *p);
void func_021E4E6C(char *p);
int func_021E4EAC(u8 *p);
int func_021E4EE8(unsigned char *p);
int func_021E4F60(BoxObj *p);
void func_021E5374(u8 *p);
int func_021E53B0(unsigned char *p);
int func_021E543C(u8 *p);
int func_021E5524(unsigned char *p);
int func_021E557C(BoxObj *p);
void func_021E58D8(u8 *p);
int func_021E5914(char *p);
int func_021E594C(unsigned char *p);
int func_021E5AD4(unsigned char *p);
int func_021E5C5C(unsigned char *p);
int func_021E5DD8(u8 *p);
int func_021E5E08(unsigned char *p);
int func_021E5E68(BoxObj *p);
int func_021E62BC(char *p);
int func_021E62FC(unsigned char *p);
void func_021E6374(u8 *p);
int func_021E63B0(unsigned char *p);
int func_021E6418(u8 *p);
int func_021E644C(unsigned char *p);
int func_021E65E4(BoxObj *p);
int func_021E695C(u8 *p);
int func_021E6A60(unsigned char *p);
int func_021E6C3C(unsigned char *p);
int func_021E6CD4(u8 *p);
int func_021E6D00(unsigned char *p);
int func_021E6EC0(BoxObj *p);
int func_021E7258(char *p);
int func_021E7298(u8 *p);
int func_021E73D8(unsigned char *p);
int func_021E754C(unsigned char *p);
int func_021E75E0(BoxObj *p);
int func_021E78F4(char *p);
int func_021E7904(unsigned char *p);
void func_021E79C8(unsigned char *p);
int func_021E7A04(unsigned char *p);
int func_021E7A10(unsigned char *p);
int func_021E7BD0(unsigned char *p);
int func_021E7C58(unsigned char *p);
int func_021E7D04(u8 *p);
void func_021E7D3C(char *p);
int func_021E7D64(u8 *p);
int func_021E7E54(u8 *p);
int func_021E7F6C(unsigned char *p);
int func_021E8014(char *p);
int func_021E8024(char *p);
int func_021E8188(unsigned char *p);
int func_021E81D0(unsigned char *p);
int func_021E8340(unsigned char *p);
int func_021E83C0(char *p);
int func_021E8508(u8 *p);
int func_021E85F0(char *p);
int func_021E86EC(unsigned char *p);
int func_021E87A0(unsigned char *p);
int func_021E8950(char *p);
int func_021E8A58(char *p);
int func_021E8A74(unsigned char *p);
int func_021E8BF8(unsigned char *p);
int func_021E8E24(char *p);
int func_021E8F14(unsigned char *p);
void func_021E8F20(u8 *p);
int func_021E8F50(char *p, int v);
int func_021E8F60(void *p, int a);
int func_021E8F90(void *p, int a);
int func_021E8FC0(char *p, int a, int b);
int func_021E8FD0(char *p, int a);
int func_021E8FE0(char *p, int v);
int func_021E8FE8(unsigned char *p, int sel);
int func_021E9010(unsigned char *p);
int func_021E90D4(unsigned char *p);
int func_021E912C(unsigned char *p);
int func_021E91A0(unsigned char *p);
int func_021E9284(char *p);
int func_021E92A8(unsigned char *p);
void func_021E93F4(char *p);
int func_021E941C(unsigned char *p);
void func_021E946C(unsigned char *p);
int func_021E949C(char *p, int a, int b);
int func_021E94AC(BoxObj *p,int a,int b);
int func_021E954C(BoxObj *p, int id, int lo, int arg);
int func_021E95CC(unsigned char *p, unsigned char v);
int func_021E95F8(unsigned char *p);
int func_021E96E8(unsigned char *p);
int func_021E9848(unsigned char *p);
int func_021E9938(unsigned char *p);
int func_021E9968(unsigned char *p);
int func_021E99B0(unsigned char *p);
int func_021E9B74(unsigned char *p);
int func_021E9C94(char *p, int a, int n);
int func_021E9CE0(char *p, int a, int n);
int func_021E9D2C(BoxObj *p, int i);
int func_021E9D98(BoxObj *p, int i);
int func_021E9DF8(u8 *p, int a);
int func_021E9E7C(char *p, int i, int v);
int func_021E9EC0(unsigned char *p, int i);
int func_021E9F3C(unsigned char *p, int i);
int func_021E9FA8(unsigned char *p, int i);
int func_021EA020(char *p, int i, int v);
int func_021EA064(unsigned char *p, int i, int v);
int func_021EA0BC(unsigned char *p, unsigned char i);
int func_021EA114(char *p, int a);
int func_021EA14C(unsigned char *p, unsigned i, int v);
void func_021EA1C0(void *p);
void func_021EA1E8(char *p);
int func_021EA1F4(BoxObj *p, int i);
int func_021EA2DC(BoxObj *p, int i);
int func_021EA39C(BoxObj *p, unsigned i);
int func_021EA458(BoxObj *p, unsigned i);
int func_021EA4DC(BoxObj *p);
int func_021EA514(BoxObj *p, unsigned i);
int func_021EA598(BoxObj *p, int i);
int func_021EA66C(BoxObj *p, int i);
void func_021EA728(void *p);
void func_021EA750(char *p);
void func_021EA75C(int p);
void func_021EA770(int p);
void func_021EA784(int p);
int func_021EA798(unsigned char *p, int sel);
void func_021EA808(char *p);
int func_021EA83C(char *p, int a);
int func_021EA858(char *p, int a);
void func_021EA878(BoxObj *p, int v);
int func_021EA8CC(unsigned char *p);
void func_021EA908(int p, int bit);
int func_021EA928(unsigned char *p,int a);
void func_021EA984(unsigned char *p);
int func_021EA9F4(BoxObj *p, int v);
int func_021EAA3C(BoxObj *p, int v);
void func_021EAA80(unsigned char *p);
void func_021EAAC4(char *p);
void func_021EAAE4(unsigned char *p, unsigned i);
void func_021EAB04(unsigned char *w);
void func_021EAB50(unsigned char *w);
void func_021EABA0(void **p);
void func_021EABB8(void **p);
void func_021EABD0(unsigned char *w,int i,void *bank,unsigned idx,int x,int y,unsigned font,unsigned short color);
void func_021EAC28(char *w, int i, void *bank, u32 idx, int x, int y, u32 font, u16 color);
void *func_021EAC98(void);
void func_021EACA8(unsigned char *p);
void func_021EACFC(u8 *p);
void func_021EADB4(unsigned char *w,Entry_021EADB4 *e,unsigned i);
void func_021EAE20(char *p, void **q, int i);
void func_021EAE74(char *p, Entry_021EAE74 *e, unsigned i);
void func_021EAF20(char *p, Entry_021EAF20 *e, unsigned i);
void func_021EAFBC(char *p,const Entry_021EAFBC *e,u32 i);
void func_021EB098(char *p, unsigned char *e, int i);
void func_021EB114(char *p, unsigned char *e, int i);
void func_021EB190(char *p, unsigned char *e, int i);
void func_021EB208(char *p, Entry_021EB208 *e, int i);
void func_021EB2A4(u8 *p, int a);
void func_021EB324(Work *w);
void func_021EB378(char *p, int idx, unsigned msg, unsigned short frame, unsigned short col, int icon);
void func_021EB6D8(int a, int b, int c, int d);
void func_021EB6F0(int a, int b, int c);
void func_021EB708(void *m,unsigned i,void *d);
void func_021EB744(char *p);
void func_021EB79C(unsigned char *p);
void func_021EB7C8(char *p);
void func_021EB7E8(char **p, unsigned box, int i);
void func_021EB85C(unsigned char *p, int i);
void func_021EB874(char **p, unsigned a, int i);
void func_021EB90C(char *p);
void func_021EB95C(char *p);
void func_021EB988(unsigned char *p, const void *e, unsigned n);
void func_021EBA30(unsigned char *p, void *win);
void func_021EBA5C(char *p, int i);
void func_021EBA70(char *p, int i);
void func_021EBA84(unsigned char *p, int msg, int i);
void func_021EBADC(char *p, int b);
void func_021EBAF8(unsigned char *p, u32 v, int i);
void func_021EBB1C(unsigned char *p, int i);
void func_021EBB28(char *p, int b);
void func_021EBB34(char *p, int a, int b);
void func_021EBB58(char *p, int b);
void func_021EBB64(unsigned char *p, unsigned v, int i);
void func_021EBBBC(char *p, int b);
void func_021EBBC8(unsigned char *p, unsigned kind, int i);
void func_021EBC28(unsigned char *p,int n,int i);
void func_021EBC58(unsigned char *p, int sel, int kind, int i);
void func_021EBCB4(unsigned char *p, int kind, int i);
void func_021EBD1C(char *p, int row, int b);
void func_021EBD50(unsigned char *p);
void func_021EBD78(char *p, int b);
void func_021EBD94(unsigned char *p);
void func_021EBDD8(char *p);
void func_021EBDF4(void *a0);
void func_021EBE24(char *p);
void func_021EBE4C(char *p);
void func_021EBEAC(unsigned char *p);
void *func_021EBEE0(char *w, const Desc *s);
void func_021EBF34(struct Slots_021EBF34 *p, int i);
void func_021EBF50(char *p);
void func_021EBF74(char *p);
void func_021EBFA8(char *p, int i, int v);
void func_021EBFCC(char *p, int i, int v);
u32 func_021EBFEC(char *p, int i);
void func_021EC000(char *p, int i, int v);
u32 func_021EC01C(char *p, int i);
void func_021EC030(char *p, int i, int c);
void func_021EC048(char *p, int i, int c);
void func_021EC060(char *p,unsigned i,int b);
void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
void func_021EC0DC(char *p);
void func_021EC1E8(char *p);
void func_021EC254(char *p);
void func_021EC2A0(char *p);
void *func_021EC338(char *p, void *b, void *c);
void func_021EC35C(char **p, int box);
void func_021EC428(char *p, int a, int i, int b);
void func_021EC45C(unsigned char *p, void *a, int i);
void func_021EC48C(unsigned char *p, int box, int pos, int win);
void func_021EC4E0(char *p);
void func_021EC4FC(unsigned char *p);
void func_021EC548(unsigned i, short *x, short *y, int mode);
void func_021EC5A0(char **p, int flag);
void func_021EC61C(unsigned char *p);
void func_021EC688(char *p);
void func_021EC6F4(char *p);
void func_021EC768(char *p, unsigned i, int flag);
void func_021EC7B8(char *p, int i, unsigned j, int flag);
void func_021EC804(char **p, short dx);
void func_021EC8E4(char *p);
void func_021EC94C(char *p);
int func_021EC994(char *p);
int func_021EC9D8(char *p);
void func_021ECA24(int *p);
void func_021ECA38(int *p);
void func_021ECA6C(unsigned char *p, int flag, int i, unsigned end, int mode);
void func_021ECB20(char *p, int f, int c);
void func_021ECB60(char *p, int i, int f);
void func_021ECB74(char *a, int b);
void func_021ECB84(char *w, unsigned i);
void func_021ECBD8(unsigned char *p, int i);
void func_021ECC1C(unsigned char *p);
void func_021ECCA4(char *p);
void func_021ECCCC(char *p,void **mon,int index);
void func_021ECDF4(char *w);
void func_021ECF78(char *p);
void func_021ECFDC(char *p, int a, int b);
void func_021ED028(char *p,unsigned char *q);
void func_021ED058(u8*p);
void func_021ED094(char *w, unsigned item);
void func_021ED108(char *p, int on);
void func_021ED14C(int a, int b, int c);
void func_021ED164(char *p, int a, int c);
void func_021ED198(char *p, int a, int c);
void func_021ED1C8(char *w);
void func_021ED2F4(char *p);
void func_021ED310(char *w);
void func_021ED370(unsigned char *p);
void func_021ED508(unsigned char *p, int a, int b);
void func_021ED544(char *p, int b);
void func_021ED55C(char **p, int flag);
void func_021ED588(char *p);
void func_021ED594(char *p, unsigned i);
void func_021ED6E4(char **p, int v);
void func_021ED75C(char **p, int i);
void func_021ED7C4(char *p, int i);
extern const unsigned char d_021EF79C[];
extern const unsigned char d_021EF7B4[];
extern const char str_021F140C[];
extern const char ov067_id[];
extern const Pair d_021EFA4C[];
extern Dispatch d_021EFA2C;
extern const unsigned char d_021EF9B4[];
extern const unsigned char d_021EF950[];
extern const unsigned char d_021EFA10[];
extern const unsigned char d_021EF918[];
extern const unsigned char d_021EF8EC[];
extern Ent d_021EF908[];
extern const unsigned char d_021EF9C8[];
extern const unsigned char d_021EF93C[];
extern const unsigned char d_021EF964[];
extern const unsigned char d_021EF978[];
extern const unsigned char d_021EF98C[];
extern const unsigned char d_021EF9A0[];
extern const unsigned char d_021EF9E0[];
extern const unsigned char d_021EF928[];
extern const unsigned char d_021EF9F8[];
extern const unsigned char data_021EFA10[];
extern const unsigned char data_021EF918[];
extern const char d_021F140C[];
extern const unsigned char d_021EF8FC[];
extern const unsigned char d_021EF8F4[];
extern const unsigned char d_021EFC20[];
extern const Template d_021EFD64;
extern const Desc d_021EFD04;
extern const Pos_021EC548 d_021EFD4C[];
extern const Off d_021EFCE0[];
extern const DescTable d_021EFD80;
extern const Desc d_021EFD34;
extern const Desc d_021EFE70;
extern const signed char d_021EFCD0[];
extern const signed char d_021EFCC8[];

#define SLOT(p) (*(char **)(WORK(p) + 0xA190))



#define CNT(p) (*(unsigned short *)(WORK(p) + 0xA16C))


#define NIB(p) ((Nib_021E09E0 *)((p) + 0x1C))





#define WORK(p) (*(char **)((p) + 0x2C))




#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))







#define W(p) (*(char **)((p) + 0x2C))









int func_021E09E0(char *p)
{
    char *s;
    s = *(char * *)&((BoxTask *)p)->f2C + 0x58;
    switch (((BoxSeq *)s)->fC) {
    case 0:
        func_021ED544(p, 7);
        func_021DE428((unsigned char *)p, ((BoxTask *)p)->f16, ((struct Obj23878 *)(*(char * *)&((BoxTask *)p)->f2C))->fA17E);
        ((BoxSeq *)s)->fC = 1;
        break;
    case 1:
        if (func_021DDAE8((unsigned char *)p) == 0) {
            func_021DE66C(p, ((BoxSeq *)s)->f8);
            func_021ED544(p, 6);
            func_020061E4(0x667);
            ((BoxSeq *)s)->fC = 0;
            return 0;
        }
        break;
    }
    return 1;
}









int func_021E0A40(char *p)
{
    char *s;
    int a;
    int b;
    s = WORK(p) + 0x58;
    switch (((BoxSeq *)s)->fC) {
    case 0:
        if (*(unsigned short *)(WORK(p) + 0xA16C)) {
            func_021ED108(WORK(p), 1);
            func_021EBFA8(WORK(p), 10, 1);
            func_021EC000(WORK(p), 10, 1);
        }
        (((BoxSeq *)s)->fC)++;
    case 1:
        a = func_021E066C(p);
        b = func_021EF5C4(*(struct WinMgr **)(WORK(p) + 0x74));
        if (a == 0 && b == 0) {
            if (*(unsigned short *)(WORK(p) + 0xA16C)) {
                func_021ED108(WORK(p), 0);
                func_021ED2F4(WORK(p));
            }
            ((BoxSeq *)s)->fC = 0;
            return 0;
        }
        break;
    }
    return 1;
}










/*
 * Same state-machine family as src/matched/ov170_func_021DFA30.c.  The spill
 * slots of `first` and `flag` follow declaration order (later declaration,
 * lower address), and the two identical "fall back to p[0x16]" arms are an
 * if/else-if that the compiler tail-merges (bne then b), not one `||`.
 */
int func_021E0ABC(unsigned char *p)
{
    Blk_021E0ABC *b = (Blk_021E0ABC *)(WORK(p) + 0x58);
    int busy = func_021EF5C4(MGR(p));
    int wait = func_021EF400(p);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        func_021EA878((BoxObj *)p, (short)CNT(p));
        if (CNT(p) != 0) {
            func_021ED108(WORK(p), 1);
            func_021EBFA8(WORK(p), 10, 1);
            func_021EC000(WORK(p), 10, 1);
            b->state = 1;
        } else {
            func_021EF534(MGR(p));
            b->state = 11;
        }
        break;
    case 1:
        if (func_021EBFEC(WORK(p), 10) == 1)
            break;
        func_021ED108(WORK(p), 0);
        func_021ED2F4(WORK(p));
        b->state = 2;
    case 2:
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            unsigned first;
            int flag;
            unsigned r;
            int back;
            if (wait == 1 || func_021EF45C(MGR(p)) == 1)
                flag = 1;
            else
                flag = 0;
            r = (unsigned short)func_021DF1DC(*(int *)(WORK(p) + 0xA180), (short)(*(int *)(WORK(p) + 0xA184)));
            if (wait == 0 && func_021EF45C(MGR(p)) == 1 && r == 0xFF)
                r = (unsigned short)func_021DF228(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF79C);
            back = 0;
            first = r;
            if (r == 0xFF) {
                r = p[0x16];
                back = 1;
            } else if (func_021DDE80(p, p[0x16], r) == 0) {
                r = p[0x16];
                back = 1;
            }
            if (flag == 1) {
                func_021DEA3C((int)p, first, r, 2);
                if (back == 1 && p[0x17] != 0xFF && p[0x17] != p[0x14]) {
                    int dir = func_021DD210(p, p[0x14], p[0x17]);
                    p[0x14] = p[0x17];
                    func_021EC35C((char **)p, p[0x14]);
                    func_021DEC98((char *)p, (void *)func_021DEDCC((char *)p, p[0x14]), dir);
                    if (dir == 0)
                        b->state = 5;
                    else
                        b->state = 6;
                } else {
                    b->state = 7;
                }
            } else {
                func_021DEA3C((int)p, first, r, 0);
                func_021EF534(MGR(p));
                b->state = 8;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (busy == 0 && wait == 0 && func_021EF45C(MGR(p)) == 0 && p[0x16] != func_021EF180(x, y)) {
            func_021EF35C(MGR(p));
            func_021EF36C(MGR(p));
            func_021EC5A0((char **)p, 1);
            func_021ECB20((char *)p, 0x82, 1);
            func_020061E4(0x669);
            func_021EE364((char **)p, 6, p[0x16]);
            func_02026124(*(void **)(WORK(p) + 0x70), 0x27);
            func_02026124(*(void **)(WORK(p) + 0x70), 0x28);
            func_021EE038((char *)p, 2, 1, 1);
            p[0x1E] = 0;
            *(unsigned char *)(WORK(p) + 0xA172) = 0;
            *(int *)(WORK(p) + 0xA168) = p[0x16];
            *(int *)(WORK(p) + 0x68) = 0x42;
        }
        if (b->timer == 0) {
            int dir = func_021EF1B4();
            if (dir == 0) {
                func_020061E4(0x548);
                func_021DD16C(p, 0);
                b->state = 3;
            } else if (dir == 1) {
                func_020061E4(0x548);
                func_021DD16C(p, 1);
                b->state = 4;
            }
        }
        func_021E0FB0(WORK(p), x, y);
        break;
    case 3:
        if (func_021E00C4((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            func_021E0FB0(WORK(p), x, y);
        break;
    case 4:
        if (func_021E0128((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            func_021E0FB0(WORK(p), x, y);
        break;
    case 5:
        if (func_021E00C4((char *)p) == 0)
            b->state = 7;
        break;
    case 6:
        if (func_021E0128((char *)p) == 0)
            b->state = 7;
        break;
    case 7:
        if (func_021DEAFC((int)p) == 0) {
            func_020061E4(0x667);
            b->state = 9;
        }
        break;
    case 8:
        if (func_021DEAFC((int)p) == 0) {
            func_020061E4(0x667);
            if (CNT(p) != 0) {
                func_021ED108(WORK(p), 0);
                func_021ED2F4(WORK(p));
            }
            func_021EE038((char *)p, 0, 0, 1);
            b->state = 11;
        }
        break;
    case 9:
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 2);
        func_021ED6E4((char **)p, 0);
        b->state = 10;
        break;
    case 10:
        if (func_021EBFEC(WORK(p), 10) == 0) {
            func_021EC000(WORK(p), 10, 0);
            func_021ED108(WORK(p), 0);
            b->state = 11;
        }
        break;
    case 11:
        if (busy == 0 && wait == 0) {
            b->state = 0;
            return 0;
        }
        break;
    }
    return 1;
}









int func_021E0E50(char *p)
{
    char *s;
    int a;
    int b;
    s = WORK(p) + 0x58;
    switch (((BoxSeq *)s)->fC) {
    case 0:
        if (func_021EC01C(WORK(p), 10) == 1) {
            func_021ED108(WORK(p), 1);
            func_021EBFA8(WORK(p), 10, 2);
        }
        (((BoxSeq *)s)->fC)++;
    case 1:
        a = func_021E066C(p);
        b = func_021E0190(p);
        if (a == 0 && b == 0)
            (((BoxSeq *)s)->fC)++;
        break;
    case 2:
        if (func_021EC01C(WORK(p), 10) == 1) {
            func_021ED108(WORK(p), 0);
            func_021EC000(WORK(p), 10, 0);
        }
        ((BoxSeq *)s)->fC = 0;
        return 0;
    }
    return 1;
}









int func_021E0ED4(unsigned char *p)
{
    char *b = W(p) + 0x58;
    switch (((BoxSeq *)b)->fC) {
    case 0:
        if (func_021EC01C(W(p), 10) == 1) {
            func_021ED108(W(p), 1);
            func_021EBFA8(W(p), 10, 2);
        }
        (((BoxSeq *)b)->fC)++;
        /* fall through */
    case 1:
        if (!func_021E0190((char *)p))
            (((BoxSeq *)b)->fC)++;
        break;
    case 2:
        if (func_021EC01C(W(p), 10) == 1) {
            func_021ED108(W(p), 0);
            func_021EC000(W(p), 10, 0);
        }
        ((BoxSeq *)b)->fC = 0;
        return 0;
    }
    return 1;
}









int func_021E0F4C(unsigned char *p)
{
    char *b = W(p) + 0x58;
    switch (((BoxSeq *)b)->fC) {
    case 0:
        if (func_021EC01C(W(p), 10) == 1) {
            func_021ED108(W(p), 1);
            func_021EBFA8(W(p), 10, 2);
        }
        (((BoxSeq *)b)->fC)++;
        break;
    case 1:
        if (!func_021EBFEC(W(p), 10)) {
            func_021ED108(W(p), 0);
            func_021EC000(W(p), 10, 0);
        }
        ((BoxSeq *)b)->fC = 0;
        return 0;
    }
    return 1;
}










void func_021E0FB0(char *w, int x, int y)
{
    func_021ED14C((int)w, (short)x, (short)y);
    func_021ED310(w);
    ((struct Obj14264 *)w)->fA180 = x;
    ((struct Obj14264 *)w)->fA184 = y;
}










/*
 * Sibling of src/matched/ov170_func_021E0ABC.c.
 */
int func_021E0FD8(unsigned char *p)
{
    Blk_021E0FD8 *b = (Blk_021E0FD8 *)(WORK(p) + 0x58);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 1);
        func_021EC000(WORK(p), 10, 1);
        b->state = 1;
        break;
    case 1:
        if (func_021EBFEC(WORK(p), 10) != 0)
            break;
        func_021ED108(WORK(p), 0);
        func_021ED2F4(WORK(p));
        b->state = 2;
        break;
    case 2:
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            unsigned first;
            unsigned r;
            int back;
            r = (unsigned short)func_021DF1DC(*(int *)(WORK(p) + 0xA180), (short)(*(int *)(WORK(p) + 0xA184)));
            if (r == 0xFF)
                r = (unsigned short)func_021DF228(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF79C);
            back = 0;
            first = r;
            if (r == 0xFF) {
                r = p[0x16];
                back = 1;
            } else if (func_021DDE80(p, p[0x16], r) == 0) {
                r = p[0x16];
                back = 1;
            }
            func_021DEA3C((int)p, first, r, 2);
            if (back == 1 && p[0x17] != 0xFF && p[0x17] != p[0x14]) {
                int dir = func_021DD210(p, p[0x14], p[0x17]);
                p[0x14] = p[0x17];
                func_021EC35C((char **)p, p[0x14]);
                func_021DEC98((char *)p, (void *)func_021DEDCC((char *)p, p[0x14]), dir);
                if (dir == 0)
                    b->state = 5;
                else
                    b->state = 6;
            } else {
                b->state = 7;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (b->timer == 0) {
            int dir = func_021EF1B4();
            if (dir == 0) {
                func_020061E4(0x548);
                func_021DD16C(p, 0);
                b->state = 3;
            } else if (dir == 1) {
                func_020061E4(0x548);
                func_021DD16C(p, 1);
                b->state = 4;
            }
        }
        func_021E0FB0(WORK(p), x, y);
        break;
    case 3:
        if (func_021E00C4((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            func_021E0FB0(WORK(p), x, y);
        break;
    case 4:
        if (func_021E0128((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            func_021E0FB0(WORK(p), x, y);
        break;
    case 5:
    case 6:
        if (b->state == 5 && func_021E00C4((char *)p) == 0)
            b->state = 7;
        if (b->state == 6 && func_021E0128((char *)p) == 0)
            b->state = 7;
    case 7:
        if (func_021DEAFC((int)p) == 0 && b->state == 7) {
            func_020061E4(0x667);
            b->state = 8;
        }
        break;
    case 8:
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 2);
        func_021ED6E4((char **)p, 0);
        b->state = 9;
        break;
    case 9:
        if (func_021EBFEC(WORK(p), 10) == 0) {
            func_021EC000(WORK(p), 10, 0);
            func_021ED108(WORK(p), 0);
            b->state = 10;
        }
        break;
    case 10:
        b->state = 0;
        return 0;
    }
    return 1;
}










/*
 * Callback of func_021E6A60 (state machine in the 021E1324 family): show
 * window 10, return the held item to its slot, then hide the window.
 */
int func_021E122C(unsigned char *p)
{
    Blk_021E122C *b = (Blk_021E122C *)(WORK(p) + 0x58);
    switch (b->state) {
    case 0:
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 1);
        func_021EC000(WORK(p), 10, 1);
        b->state = 1;
        break;
    case 1:
        if (func_021EBFEC(WORK(p), 10) != 0)
            break;
        func_021ED108(WORK(p), 0);
        b->state = 2;
        break;
    case 2: {
        unsigned char old = p[0x16];
        p[0x16] = b->entry->idx;
        if (p[0x17] != 0xFF && p[0x17] != p[0x14])
            func_021DE980(p, 2);
        else
            func_021DEA3C((int)p, old, old, 2);
        b->state = 3;
        break;
    }
    case 3:
        if (func_021DEAFC((int)p) != 0)
            break;
        if (p[0x17] != 0xFF && p[0x17] != p[0x14]) {
            b->state = 5;
        } else {
            func_020061E4(0x667);
            b->state = 4;
        }
        break;
    case 4:
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 2);
        b->state = 5;
        break;
    case 5:
        if (func_021EBFEC(WORK(p), 10) != 0)
            break;
        func_021EC000(WORK(p), 10, 0);
        func_021ED108(WORK(p), 0);
        b->state = 6;
        break;
    case 6:
        b->state = 0;
        return 0;
    }
    return 1;
}










int func_021E1324(char *p)
{
    Blk_021E1324 *b = (Blk_021E1324 *)(WORK(p) + 0x58);
    short t[2];
    switch (b->state) {
    case 0:
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 1);
        func_021EC000(WORK(p), 10, 1);
        b->state++;
        break;
    case 1:
        if (func_021EBFEC(WORK(p), 10) != 0)
            break;
        func_021ED108(WORK(p), 0);
        b->state++;
        break;
    case 2:
        func_021ED544(p, 7);
        b->state++;
    case 3:
        if (b->cnt == 4) {
            b->cnt = 0;
            b->state++;
            break;
        }
        func_021EC0B0(WORK(p), 4, &t[1], &t[0], 0);
        func_021EC08C(WORK(p), 4, (short)t[1], (short)(t[0] + 2), (short)0);
        b->cnt++;
        break;
    case 4:
        func_020061E4(0x666);
        func_021ED544(p, 8);
        b->state++;
    case 5:
        if (b->cnt == 4) {
            func_021ED1C8(WORK(p));
            func_021ED2F4(WORK(p));
            b->cnt = 0;
            b->state = 0;
            return 0;
        }
        func_021EC0B0(WORK(p), 4, &t[1], &t[0], 0);
        func_021EC08C(WORK(p), 4, (short)t[1], (short)(t[0] - 2), (short)0);
        func_021EC0B0(WORK(p), 10, &t[1], &t[0], 0);
        func_021EC08C(WORK(p), 10, (short)t[1], (short)(t[0] - 2), (short)0);
        b->cnt++;
        break;
    }
    return 1;
}










int func_021E1458(char *p)
{
    Blk_021E1458 *b = (Blk_021E1458 *)(WORK(p) + 0x58);
    short t[2];
    switch (b->state) {
    case 0:
        func_021ED544(p, 7);
        b->state = 1;
    case 1:
        if (b->cnt == 4) {
            b->cnt = 0;
            b->state = 2;
            break;
        }
        func_021EC0B0(WORK(p), 10, &t[1], &t[0], 0);
        func_021EC08C(WORK(p), 10, (short)t[1], (short)(t[0] + 2), (short)0);
        b->cnt++;
        break;
    case 2:
        func_020061E4(0x667);
        func_021ED544(p, 6);
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 2);
        b->state = 3;
        break;
    case 3:
        if (func_021EBFEC(WORK(p), 10) == 0) {
            func_021ED108(WORK(p), 0);
            func_021EC000(WORK(p), 10, 0);
            b->state = 4;
        }
        break;
    case 4:
        func_021ED544(p, 6);
        b->state = 0;
        return 0;
    }
    return 1;
}










int func_021E152C(unsigned char *p)
{
    Blk_021E152C *b = (Blk_021E152C *)(WORK(p) + 0x58);
    switch (b->state) {
    case 0:
        if (p[0x17] != 0xFF && p[0x17] != p[0x14]) {
            int dir = func_021DD210(p, p[0x14], p[0x17]);
            p[0x14] = p[0x17];
            func_021EC35C((char **)p, p[0x14]);
            func_021DEC98((char *)p, (void *)func_021DEDCC((char *)p, p[0x14]), dir);
            if (dir == 0)
                b->state = 2;
            else
                b->state = 3;
            break;
        }
    case 1:
        func_021ED544((char *)p, 7);
        func_021DEA4C((char *)p, *(unsigned short *)(WORK(p) + 0xA16E), 2);
        b->state = 4;
        break;
    case 2:
        if (func_021E00C4((char *)p) == 0)
            b->state = 1;
        break;
    case 3:
        if (func_021E0128((char *)p) == 0)
            b->state = 1;
        break;
    case 4:
        if (func_021DEB08(p) == 0) {
            func_020061E4(0x667);
            b->state = 5;
        }
        break;
    case 5:
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 2);
        b->state = 6;
        break;
    case 6:
        if (func_021EBFEC(WORK(p), 10) == 0) {
            func_021ED108(WORK(p), 0);
            func_021EC000(WORK(p), 10, 0);
            b->state = 7;
        }
        break;
    case 7:
        func_021ED544((char *)p, 6);
        b->state = 0;
        return 0;
    }
    return 1;
}










/*
 * Twin of src/matched/ov170_func_021E0ABC.c.
 */
int func_021E1628(unsigned char *p)
{
    Blk_021E1628 *b = (Blk_021E1628 *)(WORK(p) + 0x58);
    int busy = func_021EF5C4(MGR(p));
    int wait = func_021EF400(p);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        func_021EA878((BoxObj *)p, (short)CNT(p));
        if (CNT(p) != 0) {
            func_021ED108(WORK(p), 1);
            func_021EBFA8(WORK(p), 10, 1);
            func_021EC000(WORK(p), 10, 1);
            b->state = 1;
        } else {
            func_021EF534(MGR(p));
            b->state = 11;
        }
        break;
    case 1:
        if (func_021EBFEC(WORK(p), 10) == 1)
            break;
        func_021ED108(WORK(p), 0);
        func_021ED2F4(WORK(p));
        b->state = 2;
    case 2:
        if (func_021EF45C(MGR(p)) == 1)
            func_021ED888(WORK(p), 1);
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            unsigned first;
            int flag;
            unsigned r;
            if (wait == 1 || func_021EF45C(MGR(p)) == 1)
                flag = 1;
            else
                flag = 0;
            if (wait == 0 && func_021EF45C(MGR(p)) == 1) {
                r = (unsigned short)func_021DF1DC(*(int *)(WORK(p) + 0xA180), (short)(*(int *)(WORK(p) + 0xA184)));
                if (r == 0xFF)
                    r = (unsigned short)func_021DF228(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF79C);
            } else {
                r = (unsigned short)func_021DF228(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF7B4);
            }
            first = r;
            if (r == 0xFF)
                r = p[0x16];
            else if (func_021DDE80(p, p[0x16], r) == 0)
                r = p[0x16];
            if (flag == 1) {
                func_021DEA3C((int)p, first, r, 2);
                b->state = 7;
            } else {
                func_021DEA3C((int)p, first, r, 1);
                if (r == p[0x16] && (func_0202136C(CNT(p)) == 0 || first == p[0x16]))
                    func_021EF534(MGR(p));
                b->state = 8;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (busy == 0 && wait == 0 && func_021EF45C(MGR(p)) == 0 && func_021EF248() == 0) {
            func_021EF3D8(MGR(p));
            func_021ECB20((char *)p, 0x81, 1);
            func_020061E4(0x669);
            func_021EE364((char **)p, 6, p[0x16]);
            func_02026124(*(void **)(WORK(p) + 0x70), 0x27);
            func_02026124(*(void **)(WORK(p) + 0x70), 0x28);
            func_021EC000(WORK(p), 4, 0);
            func_021EE038((char *)p, 2, 1, 1);
            p[0x1E] = 1;
            *(int *)(WORK(p) + 0xA168) = p[0x16];
            *(int *)(WORK(p) + 0x68) = 0x42;
        }
        if (b->timer == 0) {
            int dir = func_021EF1B4();
            if (dir == 0) {
                func_020061E4(0x548);
                func_021DD16C(p, 0);
                b->state = 3;
            } else if (dir == 1) {
                func_020061E4(0x548);
                func_021DD16C(p, 1);
                b->state = 4;
            }
        }
        func_021E0FB0(WORK(p), x, y);
        break;
    case 3:
        if (func_021E00C4((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            func_021E0FB0(WORK(p), x, y);
        break;
    case 4:
        if (func_021E0128((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            func_021E0FB0(WORK(p), x, y);
        break;
    case 7:
    case 8:
        if (func_021DEAFC((int)p) == 0) {
            func_020061E4(0x667);
            if (b->state == 7) {
                b->state = 9;
            } else if (b->state == 8) {
                if (CNT(p) != 0) {
                    func_021ED108(WORK(p), 0);
                    func_021ED2F4(WORK(p));
                }
                func_021EE038((char *)p, 0, 0, 1);
                b->state = 11;
            }
        }
        break;
    case 9:
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 2);
        func_021ED6E4((char **)p, 0);
        b->state = 10;
        break;
    case 10:
        if (func_021EBFEC(WORK(p), 10) == 0) {
            func_021EC000(WORK(p), 10, 0);
            func_021ED108(WORK(p), 0);
            b->state = 11;
        }
        break;
    case 11:
        if (busy == 0 && wait == 0) {
            b->state = 0;
            return 0;
        }
        break;
    }
    return 1;
}









int func_021E1988(unsigned char *p)
{
    char *w = *(char * *)&((BoxTask *)p)->f2C;
    char *b = w + 0x58;
    switch (((struct Obj08237 *)b)->fC) {
    case 0:
        if (!func_021EBFEC(w, 10)) {
            unsigned old = p[0x16];
            p[0x16] = **(unsigned short * *)&((struct Obj08237 *)b)->f8;
            func_021DEA3C((int)p, old, old, 1);
            ((struct Obj08237 *)b)->fC = 1;
        }
        break;
    case 1:
        if (!func_021DEAFC((int)p)) {
            ((struct Obj08237 *)b)->fC = 0;
            return 0;
        }
        break;
    }
    return 1;
}










int func_021E19D4(char *p)
{
    Blk_021E19D4 *b = (Blk_021E19D4 *)(*(char * *)&((BoxTask *)p)->f2C + 0x58);
    if (b->fE == 5) {
        unsigned r = func_020260E0(((struct Obj23881 *)(*(char * *)&((BoxTask *)p)->f2C))->f70);
        if (r >= 0x22 && r <= 0x25)
            func_021EE008(p, r - 0x22, 1);
        else
            func_021EE008(p, 0, 0);
        func_021EDF5C((unsigned char *)p);
        b->fE = 0;
        return 0;
    }
    b->fE++;
    func_021EDD38(p, (short)-b->fE);
    return 1;
}










int func_021E1A28(char *p)
{
    Blk_021E1A28 *b = (Blk_021E1A28 *)(*(char * *)&((BoxTask *)p)->f2C + 0x58);
    if (b->fE == 5) {
        unsigned r = func_020260E0(((struct Obj23882 *)(*(char * *)&((BoxTask *)p)->f2C))->f70);
        if (r >= 0x22 && r <= 0x25)
            func_021EE008(p, r - 0x22, 1);
        else
            func_021EE008(p, 0, 0);
        func_021EDF5C((unsigned char *)p);
        b->fE = 0;
        return 0;
    }
    b->fE++;
    func_021EDD38(p, (short)b->fE);
    return 1;
}









int func_021E1A78(char *p)
{
    Blk_021E1A78 *b = (Blk_021E1A78 *)(*(char * *)&((BoxTask *)p)->f2C + 0x58);
    if (b->fE == 5) {
        unsigned r = func_020260E0(((struct Obj23883 *)(*(char * *)&((BoxTask *)p)->f2C))->f70);
        if (r >= 1 && r <= 4)
            func_021EE008(p, r - 1, 1);
        else
            func_021EE008(p, 0, 0);
        func_021EDF5C((unsigned char *)p);
        b->fE = 0;
        return 0;
    }
    b->fE++;
    func_021EDD38(p, (short)-b->fE);
    return 1;
}









int func_021E1ACC(char *p)
{
    Blk_021E1ACC *b = (Blk_021E1ACC *)(*(char * *)&((BoxTask *)p)->f2C + 0x58);
    if (b->fE == 5) {
        unsigned r = func_020260E0(((struct Obj23884 *)(*(char * *)&((BoxTask *)p)->f2C))->f70);
        if (r >= 1 && r <= 4)
            func_021EE008(p, r - 1, 1);
        else
            func_021EE008(p, 0, 0);
        func_021EDF5C((unsigned char *)p);
        b->fE = 0;
        return 0;
    }
    b->fE++;
    func_021EDD38(p, (short)b->fE);
    return 1;
}










/*
 * Sibling of src/matched/ov170_func_021DFA30.c.
 */
int func_021E1B1C(unsigned char *p)
{
    Blk_021E1B1C *b = (Blk_021E1B1C *)(WORK(p) + 0x58);
    int busy;
    unsigned r;
    unsigned x;
    unsigned y;
    if (BGWINFRM_IsMoving(MGR(p), 8) == 1)
        busy = func_021E01B0(p);
    else
        busy = 0;
    r = func_021EF5C4(MGR(p));
    switch (b->state) {
    case 0:
        if (func_02035C38() == 1)
            func_021EF57C(MGR(p));
        b->state = 1;
        break;
    case 1:
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            r = 0xFF;
            if (func_021EF45C(MGR(p)) == 1)
                r = func_021DF228(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF79C);
            if (r == 0xFF)
                r = func_021DF1DC(*(int *)(WORK(p) + 0xA180), (short)(*(int *)(WORK(p) + 0xA184)));
            if (SYS(p)[9] == 4 && SYS(p)[5] == 1) {
                r = 0xFF;
                *(unsigned char *)(WORK(p) + 0xA173) = 5;
            }
            if (func_021DE158(p, p[0x16], r) == 0)
                r = 0xFF;
            if (func_021EF60C(MGR(p)) == 0)
                func_021ED6E4((char **)p, 0);
            if (r != 0xFF)
                p[0x16] = func_021DE5C8((char *)p, 0x24);
            if (func_021EF45C(MGR(p)) == 0 && busy == 0)
                func_021EF534(MGR(p));
            if (r == 0xFF && p[0x14] != p[0x17]) {
                r = func_021DD210(p, p[0x14], p[0x17]);
                p[0x14] = p[0x17];
                func_021EC35C((char **)p, p[0x14]);
                func_021DEC98((char *)p, (void *)func_021DEDCC((char *)p, p[0x14]), r);
                if (r == 0)
                    b->state = 4;
                else
                    b->state = 5;
            } else {
                b->state = 2;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (busy == 0 && r == 0 && func_021EF45C(MGR(p)) == 0 && p[0x16] != func_021EF180(x, y)) {
            p[0x1A] = 2;
            func_021EF35C(MGR(p));
            func_021EF36C(MGR(p));
            func_021EC5A0((char **)p, 1);
            func_020061E4(0x669);
            func_021EE364((char **)p, 6, p[0x16]);
            func_021EE038((char *)p, 2, 1, 2);
            *(int *)(WORK(p) + 0xA168) = p[0x16];
            *(int *)(WORK(p) + 0x68) = 0x17;
        }
        if (b->timer == 0) {
            int dir = func_021EF1B4();
            if (dir == 0) {
                func_020061E4(0x548);
                func_021DD16C(p, 0);
                b->state = 6;
            } else if (dir == 1) {
                func_020061E4(0x548);
                func_021DD16C(p, 1);
                b->state = 7;
            }
        }
        func_021DF43C((char *)p, x, y);
        break;
    case 4:
        if (func_021E00C4((char *)p) == 0)
            b->state = 2;
        break;
    case 5:
        if (func_021E0128((char *)p) == 0)
            b->state = 2;
        break;
    case 2:
        if (func_021DD930(p) == 0) {
            func_020061E4(0x667);
            b->state = 3;
        }
        break;
    case 3:
        if (busy == 0 && r == 0)
            b->state = 0x10;
        break;
    case 6:
        if (func_021E00C4((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 7:
        if (func_021E0128((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 16:
        func_021DE66C((char *)p, b->moves);
        if (func_021EF770(MGR(p)) == 0 && func_021EF45C(MGR(p)) == 0) {
            func_021ED7C4(WORK(p), p[0x16]);
            func_021ED6E4((char **)p, 1);
        } else {
            func_021ED6E4((char **)p, 0);
            func_020260E4(*(void **)(WORK(p) + 0x70), p[0x16]);
            func_021EE3E4((char **)p, p[0x16]);
        }
        b->state = 0;
        return 0;
    }
    return 1;
}









extern int (*const d_021EFA7C[])(char *);









int func_021E1E34(char *p, int *state)
{
    if (!*(char * *)&((BoxTask *)p)->f2C || !((struct Obj23885 *)(*(char * *)&((BoxTask *)p)->f2C))->f8C || func_0201C6B4(((struct Obj23886 *)(*(char * *)&((BoxTask *)p)->f2C))->f8C))
        *state = d_021EFA7C[*state](p);
    if (*state == 0x69)
        return 0;
    if (*(char * *)&((BoxTask *)p)->f2C) {
        func_021EAB50((unsigned char *)(*(char * *)&((BoxTask *)p)->f2C));
        func_021EBF74(*(char * *)&((BoxTask *)p)->f2C);
    }
    return 1;
}







#undef W






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(p) (*(char **)((p)+0x2C))








/*
 *   src/matched/arm9/unit_0204361C.c contains its body but omits it from
 *   the function list. Its header should list func_0204361C,func_0204363C,
 *   func_02043658 and its shard must be regenerated by the owner.
 *   Verified standalone EXACT, dsi/1.1p1 -O4,p ARM c99, 28 bytes:
 *   typedef unsigned short u16;
 *   typedef unsigned int u32;
 *   void func_0204363C(u32 swap) {
 *       *(volatile u16 *)0x04000304 =
 *           (*(volatile u16 *)0x04000304 & ~0x8000) | (swap << 15);
 *   }
 *   scratchpad/overlay-goal-20261002-w62/B4/blocker-1.log is the verdict.
 *   tu --suggest-split remains MATCH; no viable partition.
 * volatile: hardware halfword writes at 021E1E9C and 021E1EA0.
 * prototype: DC9E0 takes the explicitly loaded p despite its unused input.
 */
int func_021E1E80(u8 *p)
{
    func_02034AC4((int)ov067_id);
    func_02043534(0);
    func_020435F4(0);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    func_0204363C(0);
    func_0203064C(1,0x4C,0x80000);
    W(p)=func_02030734(0x4C,0xA19C,1,str_021F140C,0x2B5);
    *(void **)(W(p)+0x1B0)=func_020490F4(7,0x4C);
    KEY_GetRepeatSpeed((u32 *)(W(p)+0x4C),(u32 *)(W(p)+0x50));
    KEY_SetRepeatSpeed(6,6);
    func_021DC9C4();
    func_021DC9E0(p);
    func_021DCDB8((char *)p);
    func_021DCB8C((struct Ov170Ctx *)p);
    func_021DCE14((char *)p);
    func_021DD8D0((char *)p);
    func_021EAA80(p);
    func_021EBD94(p);
    func_021EC4E0((char *)p);
    func_021EC4FC(p);
    func_021DEC98((char *)p,(void *)func_021DEDCC((char *)p,p[0x14]),2);
    func_021EF274((char *)p);
    func_021EACA8(p);
    func_021EACFC(p);
    func_021EDB1C((int)p);
    func_021EE2C4((char **)p);
    func_021DCEC0((char *)p);
    func_021DCDF0(1);
    func_0203D34C(1,0x4C);
    func_021DC94C((char *)p);
    return *(int *)(p+0x28);
}









int func_021E1F90(u8 *p)
{
    func_021DC964((char *)p);
    func_021DCF30((char *)p);
    func_021EE3CC((int *)p);
    func_021EF310(((BoxTask *)p)->f2C);
    func_021EBDD8(((BoxTask *)p)->f2C);
    func_021EAAC4((char *)p);
    func_021DD8F8((char *)p);
    func_021DCE80((char *)p);
    func_021DCDD8((int *)p);
    func_021DCB48(p);
    KEY_SetRepeatSpeed(*(u32 *)(*(u32 *)&((BoxTask *)p)->f2C + 0x4c), *(u32 *)(*(u32 *)&((BoxTask *)p)->f2C + 0x50));
    func_02049238((void *)*(u32 *)(*(u32 *)&((BoxTask *)p)->f2C + 0x1b0));
    func_020307B0(((BoxTask *)p)->f2C);
    func_020306F0(0x4c);
    *(u32 *)&((BoxTask *)p)->f2C = 0;
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    func_02043534(0);
    func_020435F4(0);
    func_02034A5C((int)ov067_id);
    return *(u32 *)&((BoxTask *)p)->f28;
}






/*
 * Query the current mode; when it is 1 return the 0xA188 word of
 *   the p+0x2c object, else 2.
 */
int func_021E2020(char *p)
{
    if (func_020221A4() == 1)
        return *(int *)(((struct Obj18463 *)p)->f2C + 0xA188);
    return 2;
}







int func_021E203C(void *p)
{
    if (PALANM_GetFadeRequestBits((const char *)(*(int *)(((struct Obj12157 *)p)->f2C + 0x6c))) == 0)
        return ((BoxTask *)p)->f28;
    return 3;
}





int func_021E2054(void *p)
{
    struct BoxCountWork *w = (struct BoxCountWork *)((struct Obj12157 *)p)->f2C;
    int v = w->count;
    if (v == 0)
        return ((BoxTask *)p)->f28;
    w->count = v - 1;
    return 4;
}




#undef WORK



#undef WORK


#undef WORK

#undef WORK


#define WORK(p) (*(char **)((p) + 0x2C))






#define STEP(p) (*(int *)(WORK(p) + 0xA194))







#define MODE(p) (*(int *)(TOP(p) + 0x24))







#define OBJ(p) (*(void **)((p)->work + 0x70))




#undef MGR



#undef MGR


#undef MGR

#undef MGR




#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))




#undef W



#undef W


#undef W

#undef W






#define W(p) (*(char **)((p) + 0x2C))












int func_021E2070(char *p)
{
    int (*f)(char *) = *(int (**)(char *))(((struct Obj09224 *)p)->f2C + 0x58);
    if (f != 0 && f(p) == 0) {
        *(int *)(((struct Obj09224 *)p)->f2C + 0x58) = 0;
        return *(int *)(((struct Obj09224 *)p)->f2C + 0x68);
    }
    return 5;
}











int func_021E2094(char *p)
{
    if (func_02035C60() == 1) {
        func_020061E4(0x54C);
        func_020355D8(1);
        return ((BoxTask *)p)->f28;
    }
    if (func_020362DC() & 3) {
        func_020061E4(0x54C);
        func_020355D8(0);
        return ((BoxTask *)p)->f28;
    }
    return 6;
}











int func_021E20D4(char *p)
{
    func_02027974(*(void **)(W(p) + 0x1A0));
    if (func_020279E8(*(void **)(W(p) + 0x1A0)) == 1) {
        int r = func_02027A04(*(void **)(W(p) + 0x1A0));
        func_02027858(*(void **)(W(p) + 0x1A0));
        KEY_SetRepeatSpeed(6, 6);
        if (r == 0)
            return d_021EFA4C[*(unsigned short *)(W(p) + 0x1A4)].a(p);
        else
            return d_021EFA4C[*(unsigned short *)(W(p) + 0x1A4)].b(p);
    }
    return 7;
}











int func_021E2140(int p)
{
    if (func_021DCFC0((char *)p) == 0)
        return ((BoxTask *)p)->f28;
    return 8;
}











extern struct Ent { void (*fn)(void *); int a; int b; } g_021EFA28[];











/*
 * Dispatch through the 12-byte table at 0x021EFA28 keyed by p[0x12].
 *   CLOSES the operand-order residue: the image's `ldr r1,[r1,r3]` (base first)
 *   comes out of a pointer VARIABLE holding the element address; writing the
 *   subscript as a direct member access makes mwccarm encode `[r3,r1]`.
 */
int func_021E2154(unsigned char *p)
{
    struct Ent *e = &g_021EFA28[p[0x12]];
    e->fn(p);
    return 10;
}











int func_021E216C(u8 *p){if(((BoxTask *)p)->f8!=1){(*(void (**)(u8 *))((u32)&d_021EFA2C.callback+p[0x12]*12))(p);((struct Obj10654 *)p)->f28=*(u32 *)((u32)&d_021EFA2C.value+p[0x12]*12);return 0;}return 10;}









#undef W








#undef W







#undef W






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(p) (*(char **)((p)+0x2C))










int func_021E21A0(u8 *p)
{
    func_020061E4(0x55C);
    switch(((struct Obj23887 *)(*(char * *)&((BoxTask *)p)->f0))->f24) {
    case 0:
        func_021EA784((int)p);
        func_021ED888(W(p),0);
        func_021ECB20((char *)p,1,1);
        func_021DEFEC((char *)p,30);
        NEXT(p)=0x31;
        break;
    case 1:
        func_021DEFEC((char *)p,0);
        NEXT(p)=0x2C;
        break;
    case 2:
        func_021DEFEC((char *)p,0);
        func_021EF670(W(p));
        NEXT(p)=0x11;
        break;
    case 3:
        func_021ECB20((char *)p,0x81,1);
        func_021DEFEC((char *)p,0);
        func_021EF670(W(p));
        NEXT(p)=0x39;
        break;
    case 4:
        if(func_0201AA18(((struct Obj23888 *)(*(char * *)&((BoxTask *)p)->f0))->f8)==0) {
            func_021EF670(W(p));
            func_021DEFEC((char *)p,0);
            func_021EE364((char **)p,13,0);
            NEXT(p)=0x23;
        } else {
            func_021EA784((int)p);
            func_021ED888(W(p),0);
            func_021ECB20((char *)p,1,1);
            func_021EF68C(W(p));
            func_021DEFEC((char *)p,30);
            func_021EE364((char **)p,14,0);
            NEXT(p)=0x27;
        }
        break;
    case 5:
        func_021DEFEC((char *)p,0);
        func_021ECB20((char *)p,0x81,1);
        func_021EE038((char *)p,0,1,1);
        NEXT(p)=0x4B;
        break;
    }
    return func_021E22B8((int)p);
}










/*
 * candidate func_021E22B8: guard then dispatch
 */
int func_021E22B8(int p)
{
    if (func_0201C6B4((const struct PrintSys *)(*(int *)(*(int *)&((BoxTask *)p)->f2C + 0x8c))) == 0)
        return 0xc;
    func_021E8F60((void *)p, *(int *)(*(int *)&((BoxTask *)p)->f2C + 0xA198));
}










int func_021E22E0(unsigned char *p)
{
    func_020307B0(((struct Obj23889 *)(*(char * *)&((BoxTask *)p)->f2C))->f60);
    if ((*(unsigned char **)(p + 0x2C))[0xA172] == 1) {
        if (((struct Obj23890 *)(*(char * *)&((BoxTask *)p)->f0))->f24 == 3) {
            if (((struct Obj23891 *)(*(char * *)&((BoxTask *)p)->f2C))->fA16C == 0)
                func_021EBCB4(p, 0, 0x18);
            else
                func_021EBCB4(p, 1, 0x18);
        } else {
            func_021EBC58(p, p[0x16], 1, 0x18);
        }
        (*(char **)(p + 0x2C))[0xA172] = 0;
    }
    return ((BoxTask *)p)->f28;
}











/*
 * Two-step machine on the work word at 0xA194: step 0 opens the menu for
 * the current mode and fades, step 1 picks the next state from the mode.
 */
int func_021E2334(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        switch (MODE(p)) {
        case 1:
            func_021EB988(p, d_021EF9B4, 5);
            break;
        case 0:
            func_021EB988(p, d_021EF950, 5);
            break;
        case 2:
            func_021EB988(p, d_021EFA10, 6);
            break;
        case 3:
            func_021EA878((BoxObj *)p, SUB(p));
            break;
        case 4:
            func_021EB988(p, d_021EF918, 4);
            break;
        case 5:
            func_021EBA5C(WORK(p), 0x1B);
            func_021EB988(p, d_021EF8EC, 2);
            break;
        }
        if (*(unsigned char *)(WORK(p) + 0xA170) == 1) {
            *(unsigned char *)(WORK(p) + 0xA170) = 0;
            if (MODE(p) == 3) {
                if (p[0x16] >= 0x1E) {
                    func_021ECB20((char *)p, 0x82, 0);
                } else {
                    func_021ED888(WORK(p), 1);
                    func_021ECB20((char *)p, 0x81, 0);
                }
            } else {
                if (p[0x16] >= 0x1E) {
                    func_021ECB20((char *)p, 2, 0);
                } else {
                    func_021ED888(WORK(p), 1);
                    func_021ECB20((char *)p, 1, 0);
                }
            }
        }
        func_021EF534(MGR(p));
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E0190, 0xE);
    case 1:
        STEP(p) = 0;
        func_021ED55C((char **)p, 1);
        func_021ED508(p, 0xE, 1);
        switch (MODE(p)) {
        case 1:
            func_021EBC58(p, p[0x16], 1, 0x18);
            return 0x2C;
        case 0:
            func_021EBC58(p, p[0x16], 1, 0x18);
            return 0x31;
        case 2:
            func_021EBC58(p, p[0x16], 1, 0x18);
            if (p[0x16] < 0x1E)
                return 0x11;
            return 0x1B;
        case 3:
            if (*(unsigned short *)(WORK(p) + 0xA16C) == 0)
                func_021EBCB4(p, 0, 0x18);
            else
                func_021EBCB4(p, 1, 0x18);
            if (p[0x16] < 0x1E)
                return 0x39;
            return 0x46;
        case 4:
            func_021EBC58(p, p[0x16], 1, 0x18);
            if (p[0x16] < 0x1E)
                return 0x23;
            return 0x27;
        case 5:
            func_021EBC58(p, p[0x16], 1, 0x18);
            return 0x4B;
        }
        break;
    }
    return 0xE;
}











/*
 * Touch-drag paging of the box list: a drag of three or more pixels
 * starts a scroll of |d| / 8 steps in its direction; each later call
 * spends one step until the count runs out.
 */
int func_021E24EC(unsigned char *p)
{
    unsigned x, y;
    Scroll *s;
    unsigned old;
    int d;

    if (func_021EF1FC(&x, &y) == 0) {
        func_020307B0(SCROLL(p));
        return STATE(p);
    }
    s = SCROLL(p);
    old = LASTY(p);
    LASTY(p) = y;
    d = old - y;
    if (ABS(d) >= 3) {
        s->left = ABS(d) / 8;
        if (y < old) {
            s->dir = 1;
            func_021DD1C4((char *)p, 1);
            func_020061E4(0x548);
            if (STATE(p) == 0x15)
                return func_021E8FC0((char *)p, (int)func_021E19D4, 0xF);
            return func_021E8FC0((char *)p, (int)func_021E1A78, 0xF);
        }
        if (y > old) {
            s->dir = -1;
            func_021DD1C4((char *)p, -1);
            func_020061E4(0x548);
            if (STATE(p) == 0x15)
                return func_021E8FC0((char *)p, (int)func_021E1A28, 0xF);
            return func_021E8FC0((char *)p, (int)func_021E1ACC, 0xF);
        }
    }
    if (s->left != 0) {
        s->left--;
        if (s->dir == 1) {
            func_021DD1C4((char *)p, 1);
            func_020061E4(0x548);
            if (STATE(p) == 0x15)
                return func_021E8FC0((char *)p, (int)func_021E19D4, 0xF);
            return func_021E8FC0((char *)p, (int)func_021E1A78, 0xF);
        }
        if (s->dir == -1) {
            func_021DD1C4((char *)p, -1);
            func_020061E4(0x548);
            if (STATE(p) == 0x15)
                return func_021E8FC0((char *)p, (int)func_021E1A28, 0xF);
            return func_021E8FC0((char *)p, (int)func_021E1ACC, 0xF);
        }
    }
    return 0xF;
}








#undef MGR







#undef MGR






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))








#undef W







#undef W






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W
#define W(p) (*(char **)((p)+0x2C))










/*
 * State handler (table entry at 0x021EFABC) that forwards to
 * func_021E9284.
 */
int func_021E2648(unsigned char *p)
{
    return func_021E9284((char *)p);
}










int func_021E2650(BoxObj *p)
{
    unsigned r;
    if (func_020362DC() & 4) {
        p->b1B = 0;
        return func_021EA9F4((BoxObj *)p, 0x14);
    }
    r = func_021EF170();
    if (r != -1) {
        func_020260F4(OBJ(p), 0);
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            func_020061E4(0x666);
            func_02035D20((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
            if (func_021EF5E8(MGR(p)) == 0)
                func_021EB988((unsigned char *)p, d_021EFA10, 6);
            func_021DEFEC((char *)p, r);
            return func_021E9D2C((BoxObj *)p, r);
        }
        func_020260E4(OBJ(p), r);
        func_021EE3E4((char **)p, r);
        func_021DF040((char *)p);
        if (func_021EF5E8(MGR(p)) == 1) {
            func_021EF57C(MGR(p));
            func_021ED6E4((char **)p, 0);
            func_021EBA5C(p->work, 0x18);
            func_021DD14C((char *)p);
            func_021EF670(p->work);
            return func_021E8FC0((char *)p, (int)func_021E0190, 0x11);
        }
        return 0x11;
    }
    r = func_021EE65C((char *)p);
    switch (r) {
    case 0x1E:
        func_020061E4(0x54C);
        func_021DF040((char *)p);
        return func_021E8F50((char *)p, 0x5D);
    case 0x1F:
        func_020061E4(0x548);
        func_021DF0BC((unsigned char *)p);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        return func_021E9C94((char *)p, 1, 0x11);
    case 0x20:
        func_020061E4(0x548);
        func_021DF0BC((unsigned char *)p);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        return func_021E9CE0((char *)p, 1, 0x11);
    case 0x21:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 0xA, func_021E8F50((char *)p, 0x1A));
    case 0x22:
        func_020061E4(0x556);
        p->top->h28 = 1;
        return func_021E954C((BoxObj *)p, 7, 8, 0x10);
    case 0x23:
        func_020061E4(0x551);
        p->top->h28 = 0;
        return func_021E954C((BoxObj *)p, 6, 9, 0x68);
    case 0x24:
        func_020061E4(0x54C);
        p->b1B = 0;
        p->lo = 0;
        return func_021E949C((char *)p, 0, func_021E8F50((char *)p, 0x14));
    case 0x25:
        func_020061E4(0x54C);
        p->b13 = 0;
        p->b17 = p->b14;
        p->x24 = 0x25;
        return func_021E949C((char *)p, 1, 0x4F);
    case 0x26:
        func_020061E4(0x54C);
        p->b13 = 0;
        p->x24 = 0x26;
        return func_021E949C((char *)p, 2, func_021E8F50((char *)p, 0x50));
    case 0x27:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 3, func_021E8F50((char *)p, 0x55));
    case 0x28:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x59));
    case 0x29: {
        unsigned char k;
        func_020061E4(0x551);
        k = p->b16;
        func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), k);
        return func_021E949C((char *)p, 5, 0x13);
    }
    case 0x2A:
        p->b1B = 0;
        return func_021EAA3C((BoxObj *)p, 0x14);
    case -6:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            func_020061E4(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9C94((char *)p, 1, 0x11);
        }
        break;
    case -5:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            func_020061E4(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9CE0((char *)p, 1, 0x11);
        }
        break;
    case -3: {
        unsigned char v = func_020260E0(OBJ(p));
        if (v < 0x1E)
            func_021DEFEC((char *)p, v);
        else if (v != 0x24 && v != 0x25 && v != 0x26 && v != 0x27 && v != 0x28 && v != 0x29)
            func_021DF040((char *)p);
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x11));
    }
    case -2:
        func_020061E4(0x551);
        if (func_021EF5E8(MGR(p)) == 1) {
            unsigned char k = p->b16;
            func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), k);
            return func_021E949C((char *)p, 5, 0x13);
        }
        p->top->h28 = 0;
        return func_021E954C((BoxObj *)p, 6, 9, 0x68);
    case -4:
        func_020061E4(0x548);
        break;
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            func_020061E4(0x54C);
            func_021EB988((unsigned char *)p, d_021EFA10, 6);
            func_021DEFEC((char *)p, r);
            func_021EEF74(p->work, 0x24, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), 0x24);
            return func_021E9E7C((char *)((BoxObj *)p), r, 0x11);
        }
        break;
    }
    return 0x11;
}









int func_021E2B04(unsigned char *p)
{
    func_021DD530(p);
    func_021EA1E8((char *)p);
    func_020260E4(((struct Obj23892 *)(*(char * *)&((BoxTask *)p)->f2C))->f70, 0x24);
    func_021EE3E4((char **)p, 0x24);
    func_021ED55C((char **)p, 1);
    func_021EE038((char *)p, 0, 0, 1);
    func_021EBC58(p, p[0x16], 1, 0x18);
    return 0x11;
}









/*
 * Re-key the p+0x2c+0x74 object, clear the frame, retag 0x18,
 *   forward the status bytes, refresh, then store state 0x11 with the
 *   0x021E070D thumb pointer as the selector.  Six-member wrapper family
 *   (see func_021E3BF8 / func_021E498C / func_021E4E6C / func_021E62BC /
 *   func_021E7258): only the mid call, the selector and the state differ.
 */
void func_021E2B48(char *p)
{
    func_021EF57C(*(struct WinMgr **)(*(int *)&((BoxTask *)p)->f2C + 0x74));
    func_021ED6E4((char **)p, 0);
    func_021EBA5C((char *)(*(int *)&((BoxTask *)p)->f2C), 0x18);
    func_021DD14C(p);
    func_021EF670((char *)(*(int *)&((BoxTask *)p)->f2C));
    func_021E8FC0(p, 0x21E070D, func_021E8FE0(p, 0x11));
}









int func_021E2B88(u8 *p)
{
    switch(*(int *)(W(p)+0xA194)) {
    case 0:
        p[0x19]=p[0x14];
        if(LO(p)==1) {
            p[0x17]=255;
            p[0x16]=func_020260E0(*(void **)(W(p)+0x70));
            if(p[0x16]>=30) {
                p[0x16]=0;
                func_021DEFEC((char *)p,p[0x16]);
            }
        } else {
            p[0x17]=p[0x14];
            func_021EBA5C(W(p),24);
            func_021DD14C((char *)p);
            func_021EF670(W(p));
            func_021ECB84(W(p),p[0x16]);
        }
        func_021ED55C((char **)p,0);
        func_021EF57C(*(struct WinMgr **)(W(p)+0x74));
        (*(int *)(W(p)+0xA194))++;
        return func_021E8FC0((char *)p,(int)func_021E0190,20);
    case 1:
        func_020061E4(0x669);
        (*(int *)(W(p)+0xA194))++;
        return func_021EA83C((char *)p,20);
    case 2:
        func_021EE364((char **)p,4,p[0x16]);
        func_021ED544((char *)p,6);
        func_021EE038((char *)p,0,1,0);
        *(int *)(W(p)+0xA168)=p[0x16];
        *(int *)(W(p)+0xA194)=0;
        if(LO(p)==1) {
            if(!func_021DD25C((void ***)p,p[0x16],p[0x14],0xA9,0))
                func_021EE038((char *)p,0,1,2);
            func_021ED508(p,13,1);
            return 21;
        }
        if(LO(p)==2) func_021ED508(p,13,1);
        else func_021ED508(p,14,1);
        return func_021EA114((char *)p,p[0x16]);
    }
    return 20;
}







#undef MGR






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))







#undef MODE






#undef MODE





#undef MODE




#undef MODE



#undef MODE


#undef MODE

#undef MODE
#define MODE(p) (*(unsigned char *)(WORK(p) + 0xA173))







#undef OBJ






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ


#define OBJ(p) (*(void **)((p)->work + 0x70))









int func_021E2CBC(BoxObj *p)
{
    unsigned r;
    unsigned x;
    unsigned y;
    if (p->hi == 1) {
        p->lo = 0;
        p->hi = 0;
        return func_021E8F50((char *)p, 0x16);
    }
    if ((func_020362DC() & 4) && p->lo != 0 && p->b18 == 0) {
        func_021DD238((char *)p);
        p->lo = 0;
        return func_021E8F50((char *)p, 0x16);
    }
    if (p->b18 == 0) {
        r = func_021EF170();
        if (r != -1) {
            func_020260F4(OBJ(p), 0);
            func_021EE008((char *)p, 0, 0);
            if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
                func_020061E4(0x666);
                func_02035D20((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
                func_021DEFEC((char *)p, r);
                func_020260E4(OBJ(p), r);
                return func_021EA064((unsigned char *)p, r, 0x15);
            }
            func_020260E4(OBJ(p), r);
            func_021EE754((unsigned char *)p, r);
            *(int *)(p->work + 0xA168) = r;
            func_021EE3E4((char **)p, r);
            func_021DF040((char *)p);
            return 0x15;
        }
    }
    if (func_021EF1D4(&x, &y) == 1) {
        *(unsigned *)(p->work + 0xA184) = y;
        p->x28 = 0x15;
        func_021EA808((char *)p);
        return 0xF;
    }
    r = func_021EE850((char *)p);
    switch (r) {
    case 0x1E:
        func_021EE008((char *)p, 0, 0);
        if (p->b18 != 0)
            break;
        func_020061E4(0x54C);
        func_021DF040((char *)p);
        return func_021E8F50((char *)p, 0x5D);
    case 0x1F:
        func_020061E4(0x548);
        func_021EE008((char *)p, 0, 0);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        func_021EE754((unsigned char *)p, 0x1E);
        *(int *)(p->work + 0xA168) = 0x1E;
        if (p->b18 == 0)
            func_021DF0BC((unsigned char *)p);
        else
            func_021ECC1C((unsigned char *)p);
        return func_021E9C94((char *)p, 0, 0x15);
    case 0x20:
        func_020061E4(0x548);
        func_021EE008((char *)p, 0, 0);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        func_021EE754((unsigned char *)p, 0x1E);
        *(int *)(p->work + 0xA168) = 0x1E;
        if (p->b18 == 0)
            func_021DF0BC((unsigned char *)p);
        else
            func_021ECC1C((unsigned char *)p);
        return func_021E9CE0((char *)p, 0, 0x15);
    case 0x27:
        func_020061E4(0x54C);
        if (p->b18 == 0)
            func_021DF040((char *)p);
        return func_021E949C((char *)p, 0xA, func_021E8F50((char *)p, 0x19));
    case 0x28:
        if (p->b18 == 0) {
            unsigned char v = func_020260E0(OBJ(p));
            if (v >= 0x1E || func_021DD25C((void ***)p, v, p->b14, 0xA9, 0) == 0)
                break;
            p->b16 = v;
            p->b17 = p->b14;
            p->b13 = 2;
        } else {
            p->b13 = 3;
            p->b1D = func_020260E0(OBJ(p));
        }
        func_020061E4(0x54C);
        return func_021E954C((BoxObj *)p, 8, 1, 0x4F);
    case 0x29:
        if (p->b18 != 0)
            break;
        func_020061E4(0x551);
        p->lo = 0;
        return func_021E954C((BoxObj *)p, 6, 9, func_021E8F50((char *)p, 0x16));
    case 0x2A:
        if (p->lo == 0 || p->b18 != 0)
            break;
        p->lo = 0;
        return func_021E8F50((char *)p, 0x16);
    case -2:
        if (p->b18 == 1)
            return func_021EA14C((unsigned char *)p, 0xFF, 0x15);
        func_020061E4(0x551);
        p->lo = 0;
        return func_021E954C((BoxObj *)p, 6, 9, func_021E8F50((char *)p, 0x16));
    case -8:
        if (func_020260E0(OBJ(p)) != 0x22)
            break;
        func_020061E4(0x548);
        func_021DD1C4((char *)p, -1);
        return func_021E8FC0((char *)p, (int)func_021E1A28, 0x15);
    case -7:
        if (func_020260E0(OBJ(p)) != 0x25)
            break;
        func_020061E4(0x548);
        func_021DD1C4((char *)p, 1);
        return func_021E8FC0((char *)p, (int)func_021E19D4, 0x15);
    case -6:
        if (func_020260E0(OBJ(p)) != 0x1E)
            break;
        func_020061E4(0x548);
        return func_021E9C94((char *)p, 0, 0x15);
    case -5:
        if (func_020260E0(OBJ(p)) != 0x1E)
            break;
        func_020061E4(0x548);
        return func_021E9CE0((char *)p, 0, 0x15);
    case -3: {
        unsigned char v;
        func_020061E4(0x548);
        v = func_020260E0(OBJ(p));
        if (p->b18 == 0) {
            if (v < 0x1E)
                func_021DEFEC((char *)p, v);
            else
                func_021DF040((char *)p);
        }
        if (v >= 0x22 && v <= 0x25)
            func_021EE008((char *)p, v - 0x22, 1);
        else
            func_021EE008((char *)p, 0, 0);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x15));
    }
    case -4:
        func_020061E4(0x548);
        break;
    case 0x21:
        func_020061E4(0x548);
        func_021DD1C4((char *)p, -1);
        return func_021E8FC0((char *)p, (int)func_021E1A28, 0x15);
    case 0x26:
        func_020061E4(0x548);
        func_021DD1C4((char *)p, 1);
        return func_021E8FC0((char *)p, (int)func_021E19D4, 0x15);
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
        func_021EE008((char *)p, r - 0x22, 1);
        if (p->b18 == 1)
            return func_021EA14C((unsigned char *)p, r + 2, 0x15);
        func_020061E4(0x548);
        func_021DF040((char *)p);
        *(unsigned char *)(p->work + 0xA17F) = p->b19 + r - 0x22;
        if (*(unsigned char *)(p->work + 0xA17F) >= p->b15)
            *(unsigned char *)(p->work + 0xA17F) -= p->b15;
        if (*(unsigned char *)(p->work + 0xA17F) != p->b14)
            return func_021EA798((unsigned char *)p, 0);
        break;
    case -1:
        break;
    default:
        func_021EE008((char *)p, 0, 0);
        if (p->b18 == 1)
            return func_021EA14C((unsigned char *)p, r, 0x15);
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            p->b16 = r;
            p->b17 = p->b14;
            func_021ECB84(p->work, p->b16);
            return func_021EA114((char *)p, p->b16);
        }
        break;
    }
    return 0x15;
}







#undef W






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(p) (*(char **)((p)+0x2C))








int func_021E3258(u8 *p)
{
    unsigned n;
    switch(*(int *)(W(p)+0xA194)) {
    case 0:
        func_021ED55C((char **)p,0);
        func_021EE008((char *)p,0,0);
        func_021EE038((char *)p,0,0,1);
        if(func_020260E0(*(void **)(W(p)+0x70))>=30) func_021DF040((char *)p);
        (*(int *)(W(p)+0xA194))++;
        func_020061E4(0x669);
        return func_021EA858((char *)p,22);
    case 1:
        if(p[0x1B]==1) {
            func_021EF35C(*(struct WinMgr **)(W(p)+0x74));
            func_021EF36C(*(struct WinMgr **)(W(p)+0x74));
            (*(int *)(W(p)+0xA194))++;
            return func_021E8FC0((char *)p,(int)func_021E01B0,22);
        }
        n=func_020260E0(*(void **)(W(p)+0x70));
        if(n>=30) n=0;
        func_021EE364((char **)p,3,n);
        func_021ED544((char *)p,6);
        func_021ED508(p,14,1);
        func_021DEFEC((char *)p,n);
        *(int *)(W(p)+0xA194)=0;
        return 17;
    case 2:
        func_021EF68C(W(p));
        *(int *)(W(p)+0xA194)=0;
        return 33;
    }
    return 22;
}








#undef OBJ







#undef OBJ






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ
#define OBJ(p) (*(void **)(WORK(p) + 0x70))









/*
 * Re-entry of the box menu: restores the cursor, redraws the box and picks
 * the message for the current mode.
 */
int func_021E3340(unsigned char *p)
{
    unsigned char sel;
    int arg;
    func_021DD530(p);
    p[0x18] = 0;
    p[0x17] = 0xFF;
    if (MODE(p) == 0) {
        sel = func_020260E0(OBJ(p));
    } else {
        func_020260E4(OBJ(p), p[0x16]);
        func_021EE3E4((char **)p, p[0x16]);
        func_021ED55C((char **)p, 1);
        sel = p[0x16];
    }
    *(int *)(WORK(p) + 0xA168) = sel;
    func_021EA1E8((char *)p);
    if (func_021EF770(MGR(p)) == 1) {
        if (STATE(p) == 0x20) {
            func_021EE364((char **)p, 4, sel);
            func_021DEFEC((char *)p, sel);
            STATE(p) = 0x15;
            if (func_021DD25C((void ***)p, sel, p[0x14], 0xA9, 0))
                arg = 0;
            else
                arg = 2;
        } else if (sel < 0x1E && func_021DD25C((void ***)p, sel, p[0x14], 0xA9, 0)) {
            func_021DEFEC((char *)p, sel);
            arg = 0;
        } else {
            func_021DF040((char *)p);
            arg = 2;
        }
    } else if (func_021EF45C(MGR(p)) == 1) {
        if (STATE(p) == 0x15) {
            sel = func_020260E0(OBJ(p));
            if (sel > 0x20)
                sel = p[0x16];
            func_021EE364((char **)p, 6, sel);
            func_021DEFEC((char *)p, sel);
            STATE(p) = 0x20;
            if (func_021DD25C((void ***)p, sel, p[0x14], 0xA9, 0))
                arg = 0;
            else
                arg = 2;
        } else if (sel < 0x24 && func_021DD25C((void ***)p, sel, p[0x14], 0xA9, 0)) {
            func_021DEFEC((char *)p, sel);
            arg = 0;
        } else {
            func_021DF040((char *)p);
            arg = 2;
        }
    } else if (sel < 0x24 && func_021DD25C((void ***)p, sel, p[0x14], 0xA9, 0)) {
        func_021DEFEC((char *)p, sel);
        arg = 0;
    } else {
        func_021DF040((char *)p);
        arg = 2;
    }
    if (((Nib_021E09E0 *)(p + 0x1C))->lo == 0) {
        ((Nib_021E09E0 *)(p + 0x1C))->hi = 1;
        arg = p[0x21];
    }
    func_021EE038((char *)p, 0, 1, arg);
    switch (MODE(p)) {
    case 2:
        func_020061E4(0x557);
        func_021ED55C((char **)p, 0);
        func_021EBD1C((char *)p, 2, 0x18);
        return 0x18;
    case 3:
        func_020061E4(0x557);
        func_021ED55C((char **)p, 0);
        func_021EBD1C((char *)p, 3, 0x18);
        return 0x18;
    case 4:
        func_020061E4(0x557);
        func_021ED55C((char **)p, 0);
        func_021EBD1C((char *)p, 4, 0x18);
        return 0x18;
    case 5:
        func_020061E4(0x557);
        func_021ED55C((char **)p, 0);
        func_021EBD78((char *)p, 0);
        return 0x18;
    }
    if (((struct Obj23893 *)(*(char * *)&((BoxTask *)p)->f0))->f24 == 2) {
        if (func_021EF770(MGR(p)) == 1)
            func_021EF670(WORK(p));
        else
            func_021EF68C(WORK(p));
    }
    return STATE(p);
}








#undef W







#undef W






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W
#define W(p) (*(char **)((p) + 0x2C))








int func_021E3568(unsigned char *p)
{
    int n;
    if (func_021E2094((char *)p) == 6)
        return 0x18;
    if (func_020260F0(*(void **)(W(p) + 0x70)) == 1)
        func_021EC000(W(p), 4, 1);
    if ((unsigned char)W(p)[0xA173] == 5)
        n = 0x1B;
    else
        n = 0x18;
    func_021EBA5C(W(p), n);
    func_021DD14C((char *)p);
    if (((struct Obj23894 *)(*(char * *)&((BoxTask *)p)->f0))->f24 == 2) {
        if (func_021EF770(*(struct WinMgr **)(W(p) + 0x74)) == 1)
            func_021EF670(W(p));
        else
            func_021EF68C(W(p));
    }
    W(p)[0xA173] = 0;
    return ((BoxTask *)p)->f28;
}








#undef W







#undef W






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W
#define W(p) (*(char **)((p)+0x2C))








int func_021E35D8(u8 *p)
{
    switch(*(int *)(W(p)+0xA194)) {
    case 0:
        func_021EC000(W(p),4,0);
        func_021EE008((char *)p,0,0);
        func_020061E4(0x669);
        (*(int *)(W(p)+0xA194))++;
        return func_021EA858((char *)p,25);
    case 1:
        func_021EF35C(*(struct WinMgr **)(W(p)+0x74));
        func_021EF36C(*(struct WinMgr **)(W(p)+0x74));
        if(p[0x18]==1) func_021EC5A0((char **)p,1);
        else func_021EC5A0((char **)p,0);
        func_020061E4(0x669);
        (*(int *)(W(p)+0xA194))++;
        return func_021E8FC0((char *)p,(int)func_021E01B0,25);
    case 2:
        func_021EE364((char **)p,6,30);
        func_021EE754(p,30);
        if(p[0x18]==0) func_021DEFEC((char *)p,30);
        func_021EF68C(W(p));
        *(int *)(W(p)+0xA168)=30;
        *(int *)(W(p)+0xA194)=0;
        return 32;
    }
    return 25;
}






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(p) (*(char **)((p) + 0x2C))






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK
#define WORK(p) (*(char **)((p) + 0x2c))






#undef STEP





#undef STEP




#undef STEP



#undef STEP


#undef STEP

#undef STEP
#define STEP(p) (*(int *)(WORK(p) + 0xa194))







int func_021E36A8(unsigned char *p)
{
    switch (*(int *)(W(p) + 0xA194)) {
    case 0:
        func_021DF0BC(p);
        func_021DD14C((char *)p);
        func_021ED888(W(p), 0);
        func_021ECB20((char *)p, 1, 1);
        func_021ED55C((char **)p, 0);
        func_021EF34C(*(struct WinMgr **)(W(p) + 0x74));
        func_021EF36C(*(struct WinMgr **)(W(p) + 0x74));
        func_021EC5A0((char **)p, 0);
        if (((struct Obj23895 *)(*(char * *)&((BoxTask *)p)->f0))->f24 == 3)
            func_021ECB20((char *)p, 0x82, 1);
        func_020061E4(0x669);
        (*(int *)(W(p) + 0xA194))++;
        return func_021E8FC0((char *)p, (int)func_021E01B0, 0x1A);
    case 1:
        *(int *)(W(p) + 0xA194) = 0;
        func_021DEFEC((char *)p, 0x1E);
        func_021EF68C(W(p));
        if (((struct Obj23896 *)(*(char * *)&((BoxTask *)p)->f0))->f24 == 3) {
            func_021EE364((char **)p, 8, 0);
            return 0x46;
        } else {
            func_021EE364((char **)p, 5, 0);
            return 0x1B;
        }
    }
    return 0x1A;
}






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ


#define OBJ(p) (*(void **)((p)->work + 0x70))






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR

#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))








/*
 * Sibling of src/matched/ov170_func_021E2650.c.  The image computes r + 0x1E
 * separately for func_021DEFEC and for the call after it; the (int) cast on
 * the first keeps the two expressions apart so they are not CSEd.
 */
int func_021E376C(BoxObj *p)
{
    unsigned r;
    if (func_020362DC() & 4) {
        p->b1B = 1;
        return func_021EA9F4((BoxObj *)p, 0x1F);
    }
    r = func_021EF194();
    if (r != -1) {
        func_020260F4(OBJ(p), 0);
        if (func_021DD25C((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
            func_020061E4(0x666);
            func_02035D20((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
            if (func_021EF5E8(MGR(p)) == 0)
                func_021EB988((unsigned char *)p, d_021EFA10, 6);
            func_021DEFEC((char *)p, (int)r + 0x1E);
            return func_021E9EC0((unsigned char *)p, r + 0x1E);
        }
        func_020260E4(OBJ(p), r);
        func_021EE3E4((char **)p, r);
        func_021DF040((char *)p);
        if (func_021EF5E8(MGR(p)) == 1) {
            func_021EF57C(MGR(p));
            func_021ED6E4((char **)p, 0);
            func_021EBA5C(p->work, 0x18);
            func_021DD14C((char *)p);
            func_021EF68C(p->work);
            return func_021E8FC0((char *)p, (int)func_021E0190, 0x1B);
        }
        return 0x1B;
    }
    r = func_021EE8A8((char *)p);
    switch (r) {
    case 6:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 0xA, func_021E8F50((char *)p, 0x1C));
    case 7:
        func_020061E4(0x556);
        p->top->h28 = 1;
        return func_021E954C((BoxObj *)p, 7, 8, 0x10);
    case 8:
        func_020061E4(0x551);
        return func_021E954C((BoxObj *)p, 6, 9, func_021E8F50((char *)p, 0x1C));
    case 9:
        func_020061E4(0x54C);
        p->b1B = 1;
        p->lo = 0;
        return func_021E949C((char *)p, 0, func_021E8F50((char *)p, 0x1F));
    case 10:
        func_020061E4(0x54C);
        p->b17 = p->b14;
        p->b13 = 1;
        return func_021E949C((char *)p, 1, 0x4F);
    case 11:
        func_020061E4(0x54C);
        p->b13 = 1;
        return func_021E949C((char *)p, 2, func_021E8F50((char *)p, 0x50));
    case 12:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 3, func_021E8F50((char *)p, 0x55));
    case 13:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x59));
    case 14: {
        unsigned char k;
        func_020061E4(0x551);
        k = p->b16 - 0x1E;
        func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), k);
        return func_021E949C((char *)p, 5, 0x1D);
    }
    case 15:
        p->b1B = 1;
        return func_021EAA3C((BoxObj *)p, 0x1F);
    case -4:
        func_020061E4(0x548);
        break;
    case -3: {
        unsigned char v = func_020260E0(OBJ(p));
        if (v < 6)
            func_021DEFEC((char *)p, v + 0x1E);
        else if (v == 6)
            func_021DF040((char *)p);
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x1B));
    }
    case -2:
        func_020061E4(0x551);
        if (func_021EF5E8(MGR(p)) == 1) {
            unsigned char k = p->b16 - 0x1E;
            func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), k);
            return func_021E949C((char *)p, 5, 0x1D);
        }
        return func_021E954C((BoxObj *)p, 6, 9, func_021E8F50((char *)p, 0x1C));
    case -1:
    case -5:
    case -6:
    case -7:
    case -8:
        break;
    default:
        if (func_021DD25C((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
            func_020061E4(0x54C);
            func_021EB988((unsigned char *)p, d_021EFA10, 6);
            func_021DEFEC((char *)p, (int)r + 0x1E);
            func_021EEF74(p->work, 9, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), 9);
            return func_021EA020((char *)p, r + 0x1E, 0x1B);
        }
        break;
    }
    return 0x1B;
}







#undef OBJ






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ
#define OBJ(p) (*(void **)(WORK(p) + 0x70))







#undef MGR






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))







int func_021E3B50(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_021DF0BC(p);
        func_021DD14C((char *)p);
        func_021EC000(WORK(p), 4, 0);
        func_021EF3A0(MGR(p));
        func_020061E4(0x669);
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E01B0, 0x1c);
    case 1:
        STEP(p) = 0;
        func_021ED888(WORK(p), 1);
        func_021EF670(WORK(p));
        if (((struct Obj23897 *)(*(char * *)&((BoxTask *)p)->f0))->f24 == 3) {
            func_021ECB20((char *)p, 0x81, 1);
            func_021EE364((char **)p, 7, 0x21);
            return 0x39;
        } else {
            func_021ECB20((char *)p, 1, 0);
            func_021EE364((char **)p, 3, 0x21);
            return 0x11;
        }
    }
    return 0x1c;
}







/*
 * Wrapper family member: func_021EF68C and state 0x1b.
 */
void func_021E3BF8(char *p)
{
    func_021EF57C(*(struct WinMgr **)(*(int *)&((BoxTask *)p)->f2C + 0x74));
    func_021ED6E4((char **)p, 0);
    func_021EBA5C((char *)(*(int *)&((BoxTask *)p)->f2C), 0x18);
    func_021DD14C(p);
    func_021EF68C((char *)(*(int *)&((BoxTask *)p)->f2C));
    func_021E8FC0(p, 0x21E070D, func_021E8FE0(p, 0x1B));
}







int func_021E3C38(unsigned char *p)
{
    func_020061E4(0x667);
    func_021DD530(p);
    func_021EA1E8((char *)p);
    func_020260E4(((struct Obj23898 *)(*(char * *)&((BoxTask *)p)->f2C))->f70, 9);
    func_021EE3E4((char **)p, 9);
    func_021ED55C((char **)p, 1);
    func_021EE038((char *)p, 0, 0, 1);
    func_021EBC58(p, p[0x16], 1, 0x18);
    return 0x1b;
}





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ
#define OBJ(p) (*(void **)(WORK(p) + 0x70))





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))





#undef STEP




#undef STEP



#undef STEP


#undef STEP

#undef STEP
#define STEP(p) (*(int *)(WORK(p) + 0xA194))






/*
 * Three-step state machine on the work word at 0xA194: restore the cursor,
 * close the prompt, then redraw the box.  The dispatch and the step-1
 * increment read the work pointer through a local loaded once at the top; with
 * the macro on both, the 0xA194 offset is CSEd into the increment and takes r4.
 */
int func_021E3C88(unsigned char *p)
{
    char *w = WORK(p);
    switch (((BoxWork *)w)->fA194) {
    case 0:
        if (NIB(p)->lo == 1) {
            p[0x17] = 0xFF;
            p[0x16] = func_020260E0(OBJ(p));
            if (func_021EF480(MGR(p)) == 1) {
                if (p[0x16] >= 6)
                    p[0x16] = 0x1E;
                else
                    p[0x16] += 0x1E;
            } else if (p[0x16] >= 0x1E) {
                p[0x16] = 0;
            }
            func_021DEFEC((char *)p, p[0x16]);
        } else {
            if (func_021EF480(MGR(p)) == 1)
                p[0x17] = 0xFF;
            else
                p[0x17] = p[0x14];
            func_021EBA5C(WORK(p), 0x18);
            func_021DD14C((char *)p);
            func_021EF68C(WORK(p));
            func_021ED6E4((char **)p, 0);
        }
        func_021ED55C((char **)p, 0);
        func_021EF57C(MGR(p));
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E0190, 0x1F);
    case 1:
        if (*(int *)(TOP(p) + 0x24) == 4 && *(int *)(TOP(p) + 0x14) == 1) {
            func_020061E4(0x557);
            func_021EBD78((char *)p, 0);
            NIB(p)->lo = 0;
            STEP(p) = 0;
            STATE(p) = 0x2B;
            return 6;
        }
        (((BoxWork *)w)->fA194)++;
        if (func_021EF480(MGR(p)) == 1) {
            func_021EF3D8(MGR(p));
        } else {
            func_021EF35C(MGR(p));
            func_021EF36C(MGR(p));
            func_021EC5A0((char **)p, 0);
        }
        func_020061E4(0x669);
        return func_021E8FC0((char *)p, (int)func_021E01B0, 0x1F);
    case 2:
        func_021ECB20((char *)p, 1, 0);
        func_021ED888(WORK(p), 1);
        func_021EE038((char *)p, 0, 1, 0);
        func_021EE364((char **)p, 6, p[0x16]);
        func_021ED544((char *)p, 6);
        *(int *)(WORK(p) + 0xA168) = p[0x16];
        STEP(p) = 0;
        if (NIB(p)->lo == 1) {
            if (func_021DD25C((void ***)p, p[0x16], p[0x14], 0xA9, 0) == 0)
                func_021EE038((char *)p, 0, 1, 2);
            if (*(int *)(TOP(p) + 0x24) == 4) {
                func_021EF680(WORK(p));
                func_021EF69C(WORK(p));
                func_02026124(OBJ(p), 0x27);
            }
            func_021ED508(p, 0xD, 1);
            return 0x20;
        }
        if (NIB(p)->lo == 2)
            func_021ED508(p, 0xD, 1);
        else
            func_021ED508(p, 0xE, 1);
        func_021ECB84(WORK(p), p[0x16]);
        return func_021EA0BC(p, p[0x16]);
    }
    return 0x1F;
}



#undef W


#undef W

#undef W

#define W(p) (*(u8 **)((p) + 44))



#undef WORK


#undef WORK

#undef WORK




#define WORK(p) (*(char **)((p) + 0x2c))



#undef STEP


#undef STEP

#undef STEP




#define STEP(p) (*(int *)(WORK(p) + 0xa194))



#undef OBJ


#undef OBJ

#undef OBJ








#define OBJ(p) (*(void **)((p)->work + 0x70))











int func_021E3E84(BoxObj *p)
{
    unsigned r;
    if (p->hi == 1) {
        p->lo = 0;
        p->hi = 0;
        return func_021E8F50((char *)p, 0x21);
    }
    if ((func_020362DC() & 4) && p->lo != 0 && p->b18 == 0) {
        func_021DD238((char *)p);
        p->lo = 0;
        return func_021E8F50((char *)p, 0x21);
    }
    if (p->b18 == 0) {
        r = func_021EF170();
        if (r != -1) {
            func_020260F4(OBJ(p), 0);
            if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
                func_020061E4(0x666);
                func_02035D20((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
                func_021DEFEC((char *)((BoxObj *)p), r);
                return func_021EA064((unsigned char *)p, r, 0x20);
            }
            func_020260E4(OBJ(p), r);
            func_021EE754((unsigned char *)p, r);
            *(int *)(p->work + 0xA168) = r;
            func_021EE3E4((char **)p, r);
            func_021DF040((char *)p);
            return 0x20;
        }
        r = func_021EF1A4();
        if (r != -1) {
            func_020260F4(OBJ(p), 0);
            if (func_021DD25C((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
                func_020061E4(0x666);
                func_02035D20((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
                func_021DEFEC((char *)((BoxObj *)p), (int)r + 0x1E);
                return func_021EA064((unsigned char *)p, r + 0x1E, 0x20);
            }
            func_020260E4(OBJ(p), r + 0x1E);
            func_021EE754((unsigned char *)p, r + 0x1E);
            *(int *)(p->work + 0xA168) = r + 0x1E;
            func_021EE3E4((char **)p, r + 0x1E);
            func_021DF040((char *)p);
            return 0x20;
        }
    }
    r = func_021EE96C((char *)p);
    switch (r) {
    case 0x24:
        if (p->b18 != 0)
            break;
        func_020061E4(0x54C);
        func_021DF040((char *)p);
        return func_021E8F50((char *)p, 0x5D);
    case 0x25:
        func_020061E4(0x548);
        func_020260E4(OBJ(p), 0x24);
        func_021EE3E4((char **)p, 0x24);
        func_021EE754((unsigned char *)p, 0x24);
        *(int *)(p->work + 0xA168) = 0x24;
        if (p->b18 == 0)
            func_021DF0BC((unsigned char *)p);
        else
            func_021ECC1C((unsigned char *)p);
        return func_021E9C94((char *)p, 0, 0x20);
    case 0x26:
        func_020061E4(0x548);
        func_020260E4(OBJ(p), 0x24);
        func_021EE3E4((char **)p, 0x24);
        func_021EE754((unsigned char *)p, 0x24);
        *(int *)(p->work + 0xA168) = 0x24;
        if (p->b18 == 0)
            func_021DF0BC((unsigned char *)p);
        else
            func_021ECC1C((unsigned char *)p);
        return func_021E9CE0((char *)p, 0, 0x20);
    case 0x27:
        func_020061E4(0x54C);
        if (p->b18 == 0)
            func_021DF040((char *)p);
        return func_021E949C((char *)p, 0xB, func_021E8F50((char *)p, 0x22));
    case 0x28:
        if (p->b18 == 0) {
            unsigned char v = func_020260E0(OBJ(p));
            if (v >= 0x24 || func_021DD25C((void ***)p, v, p->b14, 0xA9, 0) == 0)
                break;
            p->b16 = v;
            p->b17 = p->b14;
            p->b13 = 4;
        } else {
            p->b13 = 5;
            p->b1D = func_020260E0(OBJ(p));
        }
        func_020061E4(0x54C);
        return func_021E954C((BoxObj *)((BoxObj *)p), 8, 1, 0x4F);
    case 0x29:
        if (p->b18 != 0)
            break;
        func_020061E4(0x551);
        p->lo = 0;
        return func_021E954C((BoxObj *)((BoxObj *)p), 6, 9, func_021E8F50((char *)p, 0x21));
    case 0x2A:
        if (p->lo == 0 || p->b18 != 0)
            break;
        p->lo = 0;
        return func_021E8F50((char *)p, 0x21);
    case -2:
        if (p->b18 == 1)
            return func_021EA14C((unsigned char *)p, 0xFF, 0x20);
        func_020061E4(0x551);
        p->lo = 0;
        return func_021E954C((BoxObj *)((BoxObj *)p), 6, 9, func_021E8F50((char *)p, 0x21));
    case -6:
        if (func_020260E0(OBJ(p)) != 0x24)
            break;
        func_020061E4(0x548);
        return func_021E9C94((char *)p, 0, 0x20);
    case -5:
        if (func_020260E0(OBJ(p)) != 0x24)
            break;
        func_020061E4(0x548);
        return func_021E9CE0((char *)p, 0, 0x20);
    case -4:
        func_020061E4(0x548);
        break;
    case -3:
        func_020061E4(0x548);
        if (p->b18 == 0) {
            unsigned char v = func_020260E0(OBJ(p));
            if (v < 0x24)
                func_021DEFEC((char *)((BoxObj *)p), v);
            else
                func_021DF040((char *)p);
        }
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x20));
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (p->b18 == 1)
            return func_021EA14C((unsigned char *)p, r, 0x20);
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            p->b16 = r;
            p->b17 = p->b14;
            func_021ECB84(p->work, p->b16);
            return func_021EA0BC((unsigned char *)p, p->b16);
        }
        break;
    }
    return 0x20;
}











int func_021E432C(u8 *p)
{
    u8 index;
    u8 selection;
    switch (*(u32 *)(W(p) + 0xa194)) {
    case 0:
        func_021EC000((char *)W(p), 4, 0);
        func_021EE038((char *)p, 0, 0, 1);
        if (p[27] == 0) {
            func_021EF3A0(*(struct WinMgr **)(W(p) + 116));
            *(u32 *)(W(p) + 0xa194) = 2;
        } else {
            func_021ECB20((char *)p, 1, 1);
            func_021ED888((char *)W(p), 0);
            func_021EF3EC(*(struct WinMgr **)(W(p) + 116));
            *(u32 *)(W(p) + 0xa194) = 1;
        }
        func_020061E4(0x669);
        return func_021E8FC0((char *)p, (int)func_021E01B0, 33);
    case 1:
        *(u32 *)(W(p) + 0xa194) = 0;
        index = func_020260E0(*(void **)(W(p) + 112));
        if (index < 30 || index >= 36)
            selection = 0;
        else
            selection = index - 30;
        func_021DEFEC((char *)((BoxObj *)((char *)p)), selection + 30);
        func_021ED544((char *)p, 6);
        func_021ED508(p, 14, 1);
        if (((struct Obj23899 *)(*(u8 * *)&((BoxTask *)p)->f0))->f24 == 2) {
            func_021EE364((char **)p, 5, selection);
            return 27;
        }
        func_021EF68C((char *)W(p));
        func_021EE364((char **)p, 14, selection);
        return 39;
    case 2:
        *(u32 *)(W(p) + 0xa194) = 0;
        index = func_020260E0(*(void **)(W(p) + 112));
        if (index >= 30)
            index = 0;
        func_021DEFEC((char *)((BoxObj *)((char *)p)), index);
        func_021EF670((char *)W(p));
        func_021ED544((char *)p, 6);
        func_021ED508(p, 14, 1);
        if (((struct Obj23900 *)(*(u8 * *)&((BoxTask *)p)->f0))->f24 == 4) {
            func_021EE364((char **)p, 13, index);
            return 35;
        }
        func_021EE364((char **)p, 3, index);
        return 17;
    }
    return 33;
}










#undef OBJ









#undef OBJ








#undef OBJ







#undef OBJ






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ

#define OBJ(p) (*(void **)(WORK(p) + 0x70))



#undef MGR


#undef MGR

#undef MGR








#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))











int func_021E4470(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_021EC000(WORK(p), 4, 0);
        func_021EF3A0(MGR(p));
        func_020061E4(0x669);
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E01B0, 0x22);
    case 1:
        func_020061E4(0x669);
        p[0x19] = p[0x14];
        STEP(p)++;
        return func_021EA83C((char *)p, 0x22);
    case 2:
        func_021EE364((char **)p, 4, 0x27);
        func_021EF670(WORK(p));
        *(int *)(WORK(p) + 0xa168) = 0x27;
        STEP(p) = 0;
        return 0x15;
    }
    return 0x22;
}











#undef OBJ










#undef OBJ









#undef OBJ








#undef OBJ







#undef OBJ






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ

#define OBJ(p) (*(void **)((p)->work + 0x70))











#undef MGR










#undef MGR









#undef MGR








#undef MGR







#undef MGR






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))












int func_021E4504(BoxObj *p)
{
    unsigned r;
    if (func_020362DC() & 4) {
        p->b1B = 0;
        return func_021EA9F4((BoxObj *)((BoxObj *)p), 0x1F);
    }
    r = func_021EF170();
    if (r != -1) {
        func_020260F4(OBJ(p), 0);
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            func_020061E4(0x666);
            func_02035D20((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
            if (func_021EF5E8(MGR(p)) == 0)
                func_021EB988((unsigned char *)((BoxObj *)p), d_021EF918, 4);
            func_021DEFEC((char *)((BoxObj *)((char *)p)), r);
            p->b1B = 0;
            return func_021E9D98((BoxObj *)p, r);
        }
        func_020260E4(OBJ(p), r);
        func_021EE3E4((char **)p, r);
        func_021DF040((char *)p);
        if (func_021EF5E8(MGR(p)) == 1) {
            func_021EF57C(MGR(p));
            func_021ED6E4((char **)p, 0);
            func_021EBA5C(p->work, 0x18);
            func_021DD14C((char *)p);
            func_021EF670(p->work);
            return func_021E8FC0((char *)p, (int)func_021E0190, 0x23);
        }
        return 0x23;
    }
    r = func_021EECE4((char *)p);
    switch (r) {
    case 0x1E:
        func_020061E4(0x54C);
        func_021DF040((char *)p);
        return func_021E8F50((char *)p, 0x5D);
    case 0x1F:
        func_020061E4(0x548);
        func_021DF0BC((unsigned char *)p);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        return func_021E9C94((char *)p, 1, 0x23);
    case 0x20:
        func_020061E4(0x548);
        func_021DF0BC((unsigned char *)p);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        return func_021E9CE0((char *)p, 1, 0x23);
    case 0x21:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 0xA, func_021E8F50((char *)p, 0x26));
    case 0x22:
        func_020061E4(0x556);
        p->top->h28 = 1;
        return func_021E954C((BoxObj *)((BoxObj *)p), 7, 8, 0x10);
    case 0x23:
        func_020061E4(0x551);
        p->top->h28 = 0;
        return func_021E954C((BoxObj *)((BoxObj *)p), 6, 9, 0x68);
    case 0x24:
        func_020061E4(0x54C);
        p->b1B = 0;
        p->lo = 0;
        return func_021E949C((char *)p, 2, func_021E8F50((char *)p, 0x1F));
    case 0x25:
        func_020061E4(0x54C);
        p->b13 = 0;
        p->b17 = p->b14;
        p->x24 = 0x25;
        return func_021E949C((char *)p, 3, 0x4F);
    case 0x26:
        func_020061E4(0x54C);
        p->b13 = 0;
        p->x24 = 0x26;
        return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x50));
    case 0x27: {
        unsigned char k;
        func_020061E4(0x551);
        k = p->b16;
        func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), k);
        return func_021E949C((char *)p, 5, 0x25);
    }
    case 0x28:
        p->b1B = 0;
        return func_021EAA3C((BoxObj *)((BoxObj *)p), 0x1F);
    case -6:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            func_020061E4(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9C94((char *)p, 1, 0x23);
        }
        break;
    case -5:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            func_020061E4(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9CE0((char *)p, 1, 0x23);
        }
        break;
    case -3: {
        unsigned char v = func_020260E0(OBJ(p));
        if (v < 0x1E)
            func_021DEFEC((char *)((BoxObj *)((char *)p)), v);
        else if (v != 0x24 && v != 0x25 && v != 0x26 && v != 0x27)
            func_021DF040((char *)p);
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x23));
    }
    case -2:
        func_020061E4(0x551);
        if (func_021EF5E8(MGR(p)) == 1) {
            unsigned char k = p->b16;
            func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), k);
            return func_021E949C((char *)p, 5, 0x25);
        }
        p->top->h28 = 0;
        return func_021E954C((BoxObj *)((BoxObj *)p), 6, 9, 0x68);
    case -4:
        func_020061E4(0x548);
        break;
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            func_020061E4(0x54C);
            func_021EB988((unsigned char *)((BoxObj *)p), d_021EF918, 4);
            func_021DEFEC((char *)((BoxObj *)((char *)p)), r);
            func_021EEF74(p->work, 0x24, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), 0x24);
            return func_021E9E7C((char *)((BoxObj *)((BoxObj *)p)), r, 0x23);
        }
        break;
    }
    return 0x23;
}










int func_021E4944(unsigned char *p)
{
    func_020061E4(0x667);
    func_021DD530(p);
    func_021EA1E8((char *)p);
    func_020260E4(((struct Obj23901 *)(*(char * *)&((BoxTask *)p)->f2C))->f70, 0x24);
    func_021EE3E4((char **)p, 0x24);
    func_021EE038((char *)p, 0, 0, 1);
    func_021EBC58(p, p[0x16], 1, 0x18);
    return 0x23;
}










/*
 * Wrapper family member: func_021EF670 and state 0x23.
 */
void func_021E498C(char *p)
{
    func_021EF57C(*(struct WinMgr **)(*(int *)&((BoxTask *)p)->f2C + 0x74));
    func_021ED6E4((char **)p, 0);
    func_021EBA5C((char *)(*(int *)&((BoxTask *)p)->f2C), 0x18);
    func_021DD14C(p);
    func_021EF670((char *)(*(int *)&((BoxTask *)p)->f2C));
    func_021E8FC0(p, 0x21E070D, func_021E8FE0(p, 0x23));
}









#undef OBJ








#undef OBJ







#undef OBJ






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ

#define OBJ(p) (*(void **)(WORK(p) + 0x70))









#undef MGR








#undef MGR







#undef MGR






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR

#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))










int func_021E49CC(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_021DF0BC(p);
        func_021DD14C((char *)p);
        func_021ED888(WORK(p), 0);
        func_021ECB20((char *)p, 1, 1);
        func_021ED55C((char **)p, 0);
        func_021EF34C(MGR(p));
        func_021EF36C(MGR(p));
        func_021EC5A0((char **)p, 0);
        func_020061E4(0x669);
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E01B0, 0x26);
    case 1:
        STEP(p) = 0;
        func_021DEFEC((char *)((BoxObj *)((char *)p)), 0x1e);
        func_021EF68C(WORK(p));
        func_021EE364((char **)p, 0xe, 0);
        return 0x27;
    }
    return 0x26;
}










#undef OBJ









#undef OBJ








#undef OBJ







#undef OBJ






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ

#define OBJ(p) (*(void **)((p)->work + 0x70))










#undef MGR









#undef MGR








#undef MGR







#undef MGR






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))











/*
 * Sibling of src/matched/ov170_func_021E2650.c and ov170_func_021E376C.c.
 * The image computes r + 0x1E
 * separately for func_021DEFEC and for the call after it; the (int) cast on
 * the first keeps the two expressions apart so they are not CSEd.
 */
int func_021E4A64(BoxObj *p)
{
    unsigned r;
    if (func_020362DC() & 4) {
        p->b1B = 1;
        return func_021EA9F4((BoxObj *)((BoxObj *)p), 0x1F);
    }
    r = func_021EF194();
    if (r != -1) {
        func_020260F4(OBJ(p), 0);
        if (func_021DD25C((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
            func_020061E4(0x666);
            func_02035D20((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
            if (func_021EF5E8(MGR(p)) == 0)
                func_021EB988((unsigned char *)((BoxObj *)p), d_021EF918, 4);
            func_021DEFEC((char *)((BoxObj *)((char *)p)), (int)r + 0x1E);
            return func_021E9F3C((unsigned char *)p, r + 0x1E);
        }
        func_020260E4(OBJ(p), r);
        func_021EE3E4((char **)p, r);
        func_021DF040((char *)p);
        if (func_021EF5E8(MGR(p)) == 1) {
            func_021EF57C(MGR(p));
            func_021ED6E4((char **)p, 0);
            func_021EBA5C(p->work, 0x18);
            func_021DD14C((char *)p);
            func_021EF68C(p->work);
            return func_021E8FC0((char *)p, (int)func_021E0190, 0x27);
        }
        return 0x27;
    }
    r = func_021EEDE0((char *)p);
    switch (r) {
    case 6:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 0xA, func_021E8F50((char *)p, 0x28));
    case 7:
        func_020061E4(0x556);
        p->top->h28 = 1;
        return func_021E954C((BoxObj *)((BoxObj *)p), 7, 8, 0x10);
    case 8:
        func_020061E4(0x551);
        return func_021E954C((BoxObj *)((BoxObj *)p), 6, 9, func_021E8F50((char *)p, 0x28));
    case 9:
        func_020061E4(0x54C);
        p->b1B = 1;
        p->lo = 0;
        return func_021E949C((char *)p, 2, func_021E8F50((char *)p, 0x1F));
    case 10:
        func_020061E4(0x54C);
        p->b13 = 1;
        p->b17 = p->b14;
        return func_021E949C((char *)p, 3, 0x4F);
    case 11:
        func_020061E4(0x54C);
        p->b13 = 1;
        return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x50));
    case 12: {
        unsigned char k;
        func_020061E4(0x551);
        k = p->b16 - 0x1E;
        func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), k);
        return func_021E949C((char *)p, 5, 0x29);
    }
    case 13:
        p->b1B = 1;
        return func_021EAA3C((BoxObj *)((BoxObj *)p), 0x1F);
    case -2:
        func_020061E4(0x551);
        if (func_021EF5E8(MGR(p)) == 1) {
            unsigned char k = p->b16 - 0x1E;
            func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), k);
            return func_021E949C((char *)p, 5, 0x29);
        }
        return func_021E954C((BoxObj *)((BoxObj *)p), 6, 9, func_021E8F50((char *)p, 0x28));
    case -4:
        func_020061E4(0x548);
        break;
    case -3: {
        unsigned char v = func_020260E0(OBJ(p));
        if (v < 6)
            func_021DEFEC((char *)((BoxObj *)((char *)p)), v + 0x1E);
        else if (v == 6)
            func_021DF040((char *)p);
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x27));
    }
    case -1:
    case -5:
    case -6:
    case -7:
    case -8:
        break;
    default:
        if (func_021DD25C((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
            func_020061E4(0x54C);
            func_021EB988((unsigned char *)((BoxObj *)p), d_021EF918, 4);
            func_021DEFEC((char *)((BoxObj *)((char *)p)), (int)r + 0x1E);
            func_021EEF74(p->work, 9, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), 9);
            return func_021EA020((char *)p, r + 0x1E, 0x27);
        }
        break;
    }
    return 0x27;
}










#undef OBJ









#undef OBJ








#undef OBJ







#undef OBJ






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ
#define OBJ(p) (*(void **)(WORK(p) + 0x70))










#undef MGR









#undef MGR








#undef MGR







#undef MGR






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))










int func_021E4DE8(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_021DF0BC(p);
        func_021DD14C((char *)p);
        func_021EC000(WORK(p), 4, 0);
        func_021EF3A0(MGR(p));
        func_020061E4(0x669);
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E01B0, 0x28);
    case 1:
        STEP(p) = 0;
        func_021ED888(WORK(p), 1);
        func_021ECB20((char *)p, 1, 0);
        func_021EF670(WORK(p));
        func_021EE364((char **)p, 0xd, 0x21);
        return 0x23;
    }
    return 0x28;
}









/*
 * Wrapper family member: func_021EF68C and state 0x27.
 */
void func_021E4E6C(char *p)
{
    func_021EF57C(*(struct WinMgr **)(*(int *)&((BoxTask *)p)->f2C + 0x74));
    func_021ED6E4((char **)p, 0);
    func_021EBA5C((char *)(*(int *)&((BoxTask *)p)->f2C), 0x18);
    func_021DD14C(p);
    func_021EF68C((char *)(*(int *)&((BoxTask *)p)->f2C));
    func_021E8FC0(p, 0x21E070D, func_021E8FE0(p, 0x27));
}









/*
 *   void func_020260E4(unsigned char *p, unsigned value) {
 *       p[13] = value; p[14] = 255; p[15] = 255;
 *   }
 */
int func_021E4EAC(u8 *p){func_021DD530(p);func_021EA1E8((char *)p);func_020260E4(*(void **)(*(char **)(p+0x2c)+0x70),9);func_021EE3E4((char **)p,9);func_021EE038((char *)p,0,0,1);func_021EBC58(p,p[0x16],1,24);return 39;}








#undef OBJ







#undef OBJ






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ

#define OBJ(p) (*(void **)(WORK(p) + 0x70))








#undef MGR







#undef MGR






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR

#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))









int func_021E4EE8(unsigned char *p)
{
    func_021EBA5C(WORK(p), 0x1b);
    func_021ED6E4((char **)p, 0);
    func_021DD14C((char *)p);
    if (func_020355C4() == 0)
        func_020260F4(OBJ(p), 1);
    if (func_021EF480(MGR(p)) == 1) {
        func_020260E4(OBJ(p), p[0x16] - 0x1e);
        func_021EE3E4((char **)p, p[0x16] - 0x1e);
        func_021EF68C(WORK(p));
        return 0x27;
    } else {
        func_020260E4(OBJ(p), p[0x16]);
        func_021EE3E4((char **)p, p[0x16]);
        func_021EF670(WORK(p));
        return 0x23;
    }
}









#undef OBJ








#undef OBJ







#undef OBJ






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ

#define OBJ(p) (*(void **)((p)->work + 0x70))









#undef MGR








#undef MGR







#undef MGR






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))










int func_021E4F60(BoxObj *p)
{
    unsigned r;
    r = func_021EF170();
    if (r != -1) {
        func_020260F4(OBJ(p), 0);
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            func_020061E4(0x666);
            func_02035D20((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
            if (func_021EF5E8(MGR(p)) == 0)
                func_021EB988((unsigned char *)((BoxObj *)p), d_021EF9B4, 5);
            func_021DEFEC((char *)((BoxObj *)((char *)p)), r);
            return func_021E9DF8((u8 *)p, r);
        }
        func_020260E4(OBJ(p), r);
        func_021EE3E4((char **)p, r);
        func_021DF040((char *)p);
        if (func_021EF5E8(MGR(p)) == 1) {
            func_021EF57C(MGR(p));
            func_021ED6E4((char **)p, 0);
            func_021EBA5C(p->work, 0x18);
            func_021DD14C((char *)p);
            return func_021E8FC0((char *)p, (int)func_021E0190, 0x2C);
        }
        return 0x2C;
    }
    r = func_021EE57C((char *)p);
    switch (r) {
    case 0x1E:
        func_020061E4(0x54C);
        func_021DF040((char *)p);
        return func_021E8F50((char *)p, 0x5D);
    case 0x1F:
        func_020061E4(0x548);
        func_021DF0BC((unsigned char *)p);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        return func_021E9C94((char *)p, 0, 0x2C);
    case 0x20:
        func_020061E4(0x548);
        func_021DF0BC((unsigned char *)p);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        return func_021E9CE0((char *)p, 0, 0x2C);
    case 0x21:
        func_020061E4(0x556);
        p->top->h28 = 1;
        return func_021E954C((BoxObj *)((BoxObj *)p), 7, 8, 0x10);
    case 0x22:
        func_020061E4(0x551);
        p->top->h28 = 0;
        return func_021E954C((BoxObj *)((BoxObj *)p), 6, 9, 0x68);
    case 0x23:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 1, func_021E8F50((char *)p, 0x2E));
    case 0x24:
        func_020061E4(0x54C);
        p->b17 = p->b14;
        p->x24 = 0x24;
        return func_021E949C((char *)p, 2, 0x4F);
    case 0x25:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 3, func_021E8F50((char *)p, 0x55));
    case 0x26:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x59));
    case 0x27: {
        unsigned char k;
        func_020061E4(0x551);
        k = p->b16;
        func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), k);
        return func_021E949C((char *)p, 5, 0x2D);
    }
    case -6:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            func_020061E4(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9C94((char *)p, 0, 0x2C);
        }
        break;
    case -5:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            func_020061E4(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9CE0((char *)p, 0, 0x2C);
        }
        break;
    case -3: {
        unsigned char v = func_020260E0(OBJ(p));
        if (v < 0x1E)
            func_021DEFEC((char *)((BoxObj *)((char *)p)), v);
        else if (v != 0x23 && v != 0x24 && v != 0x25 && v != 0x26 && v != 0x27)
            func_021DF040((char *)p);
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x2C));
    }
    case -2:
        func_020061E4(0x551);
        if (func_021EF5E8(MGR(p)) == 1) {
            unsigned char k = p->b16;
            func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), k);
            return func_021E949C((char *)p, 5, 0x2D);
        }
        p->top->h28 = 0;
        return func_021E954C((BoxObj *)((BoxObj *)p), 6, 9, 0x68);
    case -4:
        func_020061E4(0x548);
        break;
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            func_020061E4(0x54C);
            func_021EB988((unsigned char *)((BoxObj *)p), d_021EF9B4, 5);
            func_021DEFEC((char *)((BoxObj *)((char *)p)), r);
            func_021EEF74(p->work, 0x23, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), 0x23);
            return func_021E9E7C((char *)((BoxObj *)((BoxObj *)p)), r, 0x2C);
        }
        break;
    }
    return 0x2C;
}









void func_021E5374(u8 *p){func_021EF57C(*(struct WinMgr * *)&((struct Obj23902 *)(*(char * *)&((BoxTask *)p)->f2C))->f74);func_021ED6E4((char **)p,0);func_021EBA5C(*(char * *)&((BoxTask *)p)->f2C,24);func_021DD14C((char *)p);func_021E8FC0((char *)p,(int)func_021E070C,func_021E8FE0((char *)p,44));}









#undef OBJ








#undef OBJ







#undef OBJ






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ
#define OBJ(p) (*(void **)(WORK(p) + 0x70))









#undef MGR








#undef MGR







#undef MGR






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))









int func_021E53B0(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_021ED55C((char **)p, 0);
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C((char *)p);
        func_021EF57C(MGR(p));
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E0190, 0x2e);
    case 1:
        if (func_0201AA18(((void **)((BoxTask *)p)->f0)[2]) != 6)
            return func_021E8F50((char *)p, 0x2f);
        func_020061E4(0x557);
        func_021EBC58(p, 0, 2, 0x18);
        ((BoxTask *)p)->f28 = 0xe;
        return func_021E8F50((char *)p, 6);
    }
    return 0x2e;
}









int func_021E543C(u8 *p)
{
    switch (*(u32 *)(*(u8 **)(p + 44) + 0xa194)) {
    case 0:
        func_020061E4(0x669);
        func_021EC61C(p);
        func_021EF35C((struct WinMgr *)(*(int *)(*(u8 **)(p + 44) + 116)));
        func_021EF36C((struct WinMgr *)(*(int *)(*(u8 **)(p + 44) + 116)));
        p[26] = 2;
        (*(u32 *)(*(u8 **)(p + 44) + 0xa194))++;
        return func_021E8FC0((char *)p, (int)func_021E01B0, 47);
    case 1:
        p[23] = p[20];
        func_021ECB84(*(char **)(p + 44), p[22]);
        func_021EA1C0(p);
        (*(u32 *)(*(u8 **)(p + 44) + 0xa194))++;
        return func_021E8FC0((char *)p, (int)func_021E0068, 47);
    case 2:
        func_020061E4(0x669);
        func_021DD530(p);
        func_021EA1E8((char *)p);
        func_021DF040((char *)p);
        func_021EF3A0((struct WinMgr *)(*(int *)(*(u8 **)(p + 44) + 116)));
        (*(u32 *)(*(u8 **)(p + 44) + 0xa194))++;
        return func_021E8FC0((char *)p, (int)func_021E01B0, 47);
    case 3:
        func_020260E4(*(void **)(*(u8 **)(p + 44) + 112), p[22]);
        func_021EE3E4((char **)p, p[22]);
        func_021ED55C((char **)p, 1);
        p[22] = 255;
        *(u32 *)(*(u8 **)(p + 44) + 0xa194) = 0;
        return 44;
    }
    return 47;
}









#undef OBJ








#undef OBJ







#undef OBJ






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ
#define OBJ(p) (*(void **)(WORK(p) + 0x70))









int func_021E5524(unsigned char *p)
{
    unsigned r = *(unsigned *)(*(char **)(WORK(p) + 0x60) + 0xac);
    func_021DD530(p);
    func_021EA1E8((char *)p);
    func_021ED888(WORK(p), 1);
    func_021EE038((char *)p, 0, 0, 1);
    if (p[0x16] != 0xff) {
        func_021EBC58(p, p[0x16], 1, 0x18);
        r = 0x23;
    }
    func_020260E4(OBJ(p), r);
    func_021EE3E4((char **)p, r);
    return 0x2c;
}









#undef OBJ








#undef OBJ







#undef OBJ






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ

#define OBJ(p) (*(void **)((p)->work + 0x70))









#undef MGR








#undef MGR







#undef MGR






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))










int func_021E557C(BoxObj *p)
{
    unsigned r = func_021EF194();
    if (r != -1) {
        func_020260F4(OBJ(p), 0);
        if (func_021DD25C((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
            func_020061E4(0x666);
            func_02035D20((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
            if (func_021EF5E8(MGR(p)) == 0)
                func_021EB988((unsigned char *)((BoxObj *)p), d_021EF950, 5);
            func_021DEFEC((char *)((BoxObj *)((char *)p)), (int)r + 0x1E);
            return func_021E9FA8((unsigned char *)p, r + 0x1E);
        }
        func_020260E4(OBJ(p), r);
        func_021EE3E4((char **)p, r + 0x3C);
        func_021DF040((char *)p);
        if (func_021EF5E8(MGR(p)) == 1) {
            func_021EF57C(MGR(p));
            func_021ED6E4((char **)p, 0);
            func_021EBA5C(p->work, 0x18);
            func_021DD14C((char *)p);
            return func_021E8FC0((char *)p, (int)func_021E0190, 0x31);
        }
        return 0x31;
    }
    r = func_021EE474((char *)p);
    switch (r) {
    case 6:
        func_020061E4(0x556);
        p->top->h28 = 1;
        return func_021E954C((BoxObj *)((BoxObj *)p), 7, 8, 0x10);
    case 7:
        func_020061E4(0x551);
        p->top->h28 = 0;
        return func_021E954C((BoxObj *)((BoxObj *)p), 6, 9, 0x68);
    case 8:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 1, func_021E8F50((char *)p, 0x34));
    case 9:
        func_020061E4(0x54C);
        p->x24 = 9;
        return func_021E949C((char *)p, 2, 0x4F);
    case 10:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 3, func_021E8F50((char *)p, 0x55));
    case 11:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x59));
    case 12: {
        unsigned char k;
        func_020061E4(0x551);
        k = p->b16 - 0x1E;
        func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), k);
        return func_021E949C((char *)p, 5, 0x32);
    }
    case -4:
        func_020061E4(0x548);
        break;
    case -3: {
        unsigned char v = func_020260E0(OBJ(p));
        if (v < 6)
            func_021DEFEC((char *)((BoxObj *)((char *)p)), v + 0x1E);
        else if (v != 8 && v != 9 && v != 10 && v != 11 && v != 12)
            func_021DF040((char *)p);
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x31));
    }
    case -2:
        func_020061E4(0x551);
        if (func_021EF5E8(MGR(p)) == 1) {
            unsigned char k = p->b16 - 0x1E;
            func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), k);
            return func_021E949C((char *)p, 5, 0x32);
        }
        p->top->h28 = 0;
        return func_021E954C((BoxObj *)((BoxObj *)p), 6, 9, 0x68);
    case -1:
    case -5:
    case -6:
    case -7:
    case -8:
        break;
    default:
        if (func_021DD25C((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
            func_020061E4(0x54C);
            func_021EB988((unsigned char *)((BoxObj *)p), d_021EF950, 5);
            func_021DEFEC((char *)((BoxObj *)((char *)p)), (int)r + 0x1E);
            func_021EEF74(p->work, 8, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), 8);
            return func_021EA020((char *)p, r + 0x1E, 0x31);
        }
        break;
    }
    return 0x31;
}









void func_021E58D8(u8 *p){func_021EF57C(*(struct WinMgr * *)&((struct Obj23904 *)(*(char * *)&((BoxTask *)p)->f2C))->f74);func_021ED6E4((char **)p,0);func_021EBA5C(*(char * *)&((BoxTask *)p)->f2C,24);func_021DD14C((char *)p);func_021E8FC0((char *)p,(int)func_021E070C,func_021E8FE0((char *)p,49));}







#undef WORK






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))







#undef MGR






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))







#undef STEP






#undef STEP





#undef STEP




#undef STEP



#undef STEP


#undef STEP

#undef STEP
#define STEP(p) (*(int *)(WORK(p) + 0xA194))








/*
 * Refresh the tag-derived index, re-key, arm, retag 0x18, forward,
 *   and report 0x31.
 */
int func_021E5914(char *p)
{
    func_020260E4((struct Sound *)(*(int *)(*(int *)&((BoxTask *)p)->f2C + 0x70)),
                  (unsigned char)(((BoxTask *)p)->f16 - 0x1e));
    func_021EE3E4((char **)p, ((BoxTask *)p)->f16 - 0x1e);
    func_021ED55C((char **)p, 1);
    func_021EBA5C((char *)(*(int *)&((BoxTask *)p)->f2C), 0x18);
    func_021DD14C(p);
    return 0x31;
}









/*
 * Five-step machine on the work word at 0xA194: fade out, confirm the
 * party slot (or back out to state 0x33), fade, swap, then reopen.
 */
int func_021E594C(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_021EF57C(MGR(p));
        func_021ED55C((char **)p, 0);
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C((char *)p);
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E0190, 0x34);
    case 1:
        switch (func_021EA8CC(p)) {
        case 0:
            p[0x18] = 1;
            func_021ECB84(WORK(p), p[0x16]);
            func_021EC768(WORK(p), 0x24, 0);
            func_021ED55C((char **)p, 1);
            func_021EE3E4((char **)p, p[0x16] - 0x1E);
            STEP(p)++;
            return func_021E8FC0((char *)p, (int)func_021E0778, 0x34);
        case 1:
            func_020061E4(0x557);
            func_021ED6E4((char **)p, 0);
            func_021EBBC8(p, 6, 0x18);
            STATE(p) = 0x33;
            STEP(p) = 0;
            return 6;
        case 2:
            func_020061E4(0x557);
            func_021ED6E4((char **)p, 0);
            func_021EBC58(p, 0, 5, 0x18);
            STATE(p) = 0x33;
            STEP(p) = 0;
            return 6;
        }
        break;
    case 2:
        func_020061E4(0x669);
        func_021EF3A0(MGR(p));
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E01B0, 0x34);
    case 3:
        func_021EE520((char *)p, p[0x16] - 0x1E);
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E066C, 0x34);
    case 4:
        func_020307B0(*(void **)(WORK(p) + 0x60));
        func_021ED888(WORK(p), 1);
        func_021EBC58(p, 0, 3, 0x1A);
        func_021EE038((char *)p, 0, 1, 1);
        func_021EE364((char **)p, 1, 0);
        STEP(p) = 0;
        return 0x35;
    }
    return 0x34;
}









/*
 * Party list input: L and R page the list when nothing is picked; a pick
 * of the first two rows opens the slot (or refuses it), the others page,
 * jump or cancel.
 */
int func_021E5AD4(unsigned char *p)
{
    unsigned r;
    unsigned b, a;

    r = func_02025DE8(LIST(p));
    if (r == (unsigned)-1) {
        if (func_0203633C() & 0x200) {
            func_021DD238((char *)p);
            r = 2;
        } else if (func_0203633C() & 0x100) {
            func_021DD238((char *)p);
            r = 3;
        }
    }
    switch (r) {
    case 0:
    case 1:
        func_020260E4(LIST(p), 0);
        if (func_020077B8(*(void **)(TOP(p) + 4), p[0x14]) == 0) {
            func_020061E4(0x557);
            func_021EBC58(p, 0, 4, 0x18);
            STATE(p) = 0x37;
            return 6;
        }
        a = p[0x14];
        b = 0;
        func_020076D0(*(void **)(TOP(p) + 4), (int *)(&a), (int *)(&b));
        *(unsigned char *)(WORK(p) + 0xA17E) = b;
        p[0x1A] = 0;
        p[0x17] = p[0x14];
        func_020061E4(0x54C);
        return func_021E8F50((char *)p, 0x36);
    case 2:
        func_020260E4(LIST(p), 0);
    case (unsigned)-6:
        func_020061E4(0x548);
        return func_021E9C94((char *)p, 0, 0x35);
    case 3:
        func_020260E4(LIST(p), 0);
    case (unsigned)-5:
        func_020061E4(0x548);
        return func_021E9CE0((char *)p, 0, 0x35);
    case 4:
    case (unsigned)-2:
        func_020061E4(0x551);
        *(unsigned char *)(WORK(p) + 0xA17E) = 0xFF;
        p[0x17] = p[0x14];
        p[0x1A] = 1;
        return func_021E954C((BoxObj *)((BoxObj *)p), 6, 9, func_021E8F50((char *)p, 0x36));
    case (unsigned)-4:
        func_020061E4(0x548);
        break;
    case (unsigned)-8:
    case (unsigned)-7:
    case (unsigned)-3:
    case (unsigned)-1:
        break;
    }
    return 0x35;
}









/*
 * Eight-step machine on the work word at 0xA194 for the party swap:
 * fade, take the slot (from the held box slot at 0xA17E if any), fade
 * back and restore the box view.
 */
int func_021E5C5C(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        if (HELD(p) == 0xFF) {
            func_021EE544((char *)p, p[0x16]);
            STEP(p) = 1;
        } else {
            func_021EE544((char *)p, HELD(p));
            STEP(p) = 4;
        }
        func_021ED888(WORK(p), 0);
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C((char *)p);
        return func_021E8FC0((char *)p, (int)func_021E066C, 0x36);
    case 1:
        func_020307B0(*(void **)(WORK(p) + 0x60));
        func_020061E4(0x669);
        func_021EF36C(MGR(p));
        STEP(p) = 2;
        return func_021E8FC0((char *)p, (int)func_021E01B0, 0x36);
    case 2:
        func_021EA1C0(p);
        STEP(p) = 6;
        return func_021E8FC0((char *)p, (int)func_021E087C, 0x36);
    case 3:
        func_020061E4(0x669);
        func_021EC000(WORK(p), 4, 0);
        func_021EF36C(MGR(p));
        STEP(p) = 7;
        return func_021E8FC0((char *)p, (int)func_021E01B0, 0x36);
    case 4:
        func_020307B0(*(void **)(WORK(p) + 0x60));
        func_021EA1C0(p);
        func_021ED6E4((char **)p, 0);
        STEP(p) = 5;
        return func_021E8FC0((char *)p, (int)func_021E09E0, 0x36);
    case 5:
        func_021DD530(p);
        func_021EA1E8((char *)p);
        func_021DF040((char *)p);
        func_021ECB20((char *)p, 1, 1);
        func_021ECB20((char *)p, 2, 0);
        STEP(p) = 3;
        break;
    case 6:
        func_021EA1E8((char *)p);
    case 7:
        p[0x18] = 0;
        func_021ED6E4((char **)p, 0);
        func_021EE038((char *)p, 0, 0, 1);
        func_021EE364((char **)p, 0, p[0x16] - 0x1E);
        func_021DEFEC((char *)((BoxObj *)((char *)p)), p[0x16]);
        STEP(p) = 0;
        return 0x31;
    }
    return 0x36;
}








int func_021E5DD8(u8 *p){func_021EBA5C(*(char * *)&((BoxTask *)p)->f2C,24);func_021DD14C((char *)p);func_021EBC58(p,0,3,26);func_021EE038((char *)p,0,1,1);return 53;}






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2c))






#undef STEP





#undef STEP




#undef STEP



#undef STEP


#undef STEP

#undef STEP
#define STEP(p) (*(int *)(WORK(p) + 0xa194))






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ

#define OBJ(p) (*(void **)(WORK(p) + 0x70))







int func_021E5E08(unsigned char *p)
{
    func_021DD530(p);
    func_021EA1E8((char *)p);
    func_021EE038((char *)p, 0, 0, 1);
    if (p[0x16] == 0xff) {
        func_020260E4(OBJ(p), 0);
        func_021EE3E4((char **)p, 0);
        func_021DEFEC((char *)((BoxObj *)((char *)p)), 0x1e);
    } else {
        func_021EBC58(p, p[0x16], 1, 0x18);
        func_020260E4(OBJ(p), 8);
        func_021EE3E4((char **)p, 8);
    }
    return 0x31;
}







#undef OBJ






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ

#define OBJ(p) (*(void **)((p)->work + 0x70))






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR

#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))








int func_021E5E68(BoxObj *p)
{
    unsigned r;
    if (func_020362DC() & 4) {
        r = func_021EA9F4((BoxObj *)((BoxObj *)p), 0x3F);
        if (p->lo == 1) {
            unsigned char v = func_020260E0(OBJ(p));
            if (v < 0x1E)
                p->b16 = v;
            else
                p->b16 = 0;
        }
        return r;
    }
    r = func_021EF170();
    if (r != -1) {
        func_020260F4(OBJ(p), 0);
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            func_020061E4(0x666);
            func_02035D20((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
            func_021DEFEC((char *)((BoxObj *)((char *)p)), r);
            return func_021EA1F4(p, r);
        }
        func_021DF040((char *)p);
        if (func_021EF5E8(MGR(p)) == 1) {
            func_021EEF74(p->work, r, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), r);
            return func_021E62BC((char *)p);
        }
        func_020260E4(OBJ(p), r);
        func_021EE3E4((char **)p, r);
        return 0x39;
    }
    r = func_021EEA48((char *)p);
    switch (r) {
    case 0x1E:
        func_020061E4(0x54C);
        func_021DF040((char *)p);
        return func_021E8F50((char *)p, 0x5D);
    case 0x1F:
        func_020061E4(0x548);
        func_021DF0BC((unsigned char *)p);
        func_021EC000(p->work, 10, 0);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        return func_021E9C94((char *)p, 1, 0x39);
    case 0x20:
        func_020061E4(0x548);
        func_021DF0BC((unsigned char *)p);
        func_021EC000(p->work, 10, 0);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        return func_021E9CE0((char *)p, 1, 0x39);
    case 0x21:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 10, func_021E8F50((char *)p, 0x1A));
    case 0x22:
        func_020061E4(0x556);
        p->top->h28 = 1;
        return func_021E954C((BoxObj *)((BoxObj *)p), 7, 8, 0x10);
    case 0x23:
        func_020061E4(0x551);
        p->top->h28 = 0;
        return func_021E954C((BoxObj *)((BoxObj *)p), 6, 9, 0x68);
    case 0x24:
        func_020061E4(0x54C);
        p->lo = 0;
        return func_021E949C((char *)p, 3, func_021E8F50((char *)p, 0x3F));
    case 0x25:
        func_020061E4(0x54C);
        if (*(unsigned short *)(p->work + 0xA16C) == 0) {
            p->b13 = 0;
            p->x24 = 0x25;
            return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x50));
        }
        return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x50));
    case 0x26: {
        unsigned char k;
        func_020061E4(0x551);
        k = p->b16;
        func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), k);
        return func_021E949C((char *)p, 5, 0x3A);
    }
    case 0x27:
        r = func_021EAA3C((BoxObj *)((BoxObj *)p), 0x3F);
        if (p->lo == 1) {
            unsigned char v = func_020260E0(OBJ(p));
            if (v < 0x1E)
                p->b16 = v;
            else
                p->b16 = 0;
        }
        return r;
    case -6:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            func_020061E4(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9C94((char *)p, 1, 0x39);
        }
        break;
    case -5:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            func_020061E4(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9CE0((char *)p, 1, 0x39);
        }
        break;
    case -4:
        func_020061E4(0x548);
        break;
    case -3: {
        unsigned char v = func_020260E0(OBJ(p));
        if (v < 0x1E)
            func_021DEFEC((char *)((BoxObj *)((char *)p)), v);
        else if (v != 0x24 && v != 0x25 && v != 0x26)
            func_021DF040((char *)p);
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x39));
    }
    case -2:
        func_020061E4(0x551);
        if (func_021EF5E8(MGR(p)) == 1) {
            unsigned char k = p->b16;
            func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), k);
            return func_021E949C((char *)p, 5, 0x3A);
        }
        p->top->h28 = 0;
        return func_021E954C((BoxObj *)((BoxObj *)p), 6, 9, 0x68);
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            func_020061E4(0x54C);
            return func_021EA2DC(p, r);
        }
        break;
    }
    return 0x39;
}







/*
 * Wrapper family member: func_021EF670, state 0x39 and
 *   0x021E0E51 as the selector.
 */
int func_021E62BC(char *p)
{
    func_021EF57C(*(struct WinMgr **)(*(int *)&((BoxTask *)p)->f2C + 0x74));
    func_021ED6E4((char **)p, 0);
    func_021EBA5C((char *)(*(int *)&((BoxTask *)p)->f2C), 0x18);
    func_021DD14C(p);
    func_021EF670((char *)(*(int *)&((BoxTask *)p)->f2C));
    return func_021E8FC0(p, 0x21E0E51, func_021E8FE0(p, 0x39));
}







#undef OBJ






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ
#define OBJ(p) (*(void **)(WORK(p) + 0x70))







#undef MGR






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))







int func_021E62FC(unsigned char *p)
{
    if (func_021EBFEC(WORK(p), 0xa) == 1)
        return 0x3b;
    func_021EA878((BoxObj *)p, 0);
    func_021ED108(WORK(p), 0);
    func_021EC000(WORK(p), 0xa, 0);
    func_021EBCB4(p, 3, 0x18);
    if (p[0x16] < 0x1e) {
        func_021ECB20((char *)p, 0x81, 1);
        func_021ED888(WORK(p), 1);
    } else {
        func_021ECB20((char *)p, 0x82, 1);
    }
    *(unsigned short *)(WORK(p) + 0xa16c) = 0;
    ((BoxTask *)p)->f28 = 0x3d;
    return func_021E8F50((char *)p, 6);
}







void func_021E6374(u8 *p){func_021ED6E4((char **)p,0);func_021EBA5C(*(char * *)&((BoxTask *)p)->f2C,24);func_021DD14C((char *)p);if(p[0x16]<30)func_021EF670(*(char * *)&((BoxTask *)p)->f2C);else func_021EF68C(*(char * *)&((BoxTask *)p)->f2C);func_021E8FC0((char *)p,(int)func_021E0F4C,61);}





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK
#define WORK(p) (*(char **)((p) + 0x2c))





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ
#define OBJ(p) (*(void **)(WORK(p) + 0x70))





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))





#undef STEP




#undef STEP



#undef STEP


#undef STEP

#undef STEP
#define STEP(p) (*(int *)(WORK(p) + 0xa194))






int func_021E63B0(unsigned char *p)
{
    int r;
    func_021EBA5C(WORK(p), 0x18);
    func_021DD14C((char *)p);
    if (p[0x16] < 0x1e) {
        func_020260E4(OBJ(p), p[0x16]);
        func_021EE3E4((char **)p, p[0x16]);
        func_021EF670(WORK(p));
        r = 0x39;
    } else {
        func_020260E4(OBJ(p), p[0x16] - 0x1e);
        func_021EE3E4((char **)p, p[0x16] - 0x1e);
        func_021EF68C(WORK(p));
        r = 0x46;
    }
    func_021ED55C((char **)p, 1);
    func_021ED508(p, 0xe, 1);
    return r;
}






int func_021E6418(u8 *p){int sel;sel=37;if(*(u16 *)(*(char **)(p+0x2c)+0xa16c)!=0)sel=36;func_020260E4(*(void **)(*(char **)(p+0x2c)+0x70),sel);func_021EE3E4((char **)p,sel);func_021ED55C((char **)p,1);return 57;}




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ
#define OBJ(p) (*(void **)(WORK(p) + 0x70))




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))




#undef STEP



#undef STEP


#undef STEP

#undef STEP
#define STEP(p) (*(int *)(WORK(p) + 0xA194))





/*
 * Three-step machine on the work word at 0xA194: close the held view,
 * fade, then reopen the menu for the current nibble mode.
 */
int func_021E644C(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        STEP(p)++;
        func_021ED55C((char **)p, 0);
        if (func_021EF480(MGR(p)) == 1)
            p[0x1E] = 1;
        else
            p[0x1E] = 0;
        if (NIB(p)->lo == 1) {
            p[0x17] = 0xFF;
            *(unsigned short *)(WORK(p) + 0xA16C) = 0;
            func_021DD14C((char *)p);
            func_021DEFEC((char *)((BoxObj *)((char *)p)), p[0x16]);
        } else {
            if (NIB(p)->lo == 2 && *(unsigned short *)(WORK(p) + 0xA16C) == 0) {
                p[0x17] = 0xFF;
                NIB(p)->lo = 1;
            }
            func_021EBA5C(WORK(p), 0x18);
            func_021DD14C((char *)p);
            func_021ED6E4((char **)p, 0);
            func_021EF57C(MGR(p));
            return func_021E8FC0((char *)p, (int)func_021E0ED4, 0x3F);
        }
    case 1:
        STEP(p)++;
        if (func_021EF480(MGR(p)) == 1) {
            func_021EF3D8(MGR(p));
        } else {
            func_021EF35C(MGR(p));
            func_021EF36C(MGR(p));
            func_021EC5A0((char **)p, 0);
        }
        func_020061E4(0x669);
        return func_021E8FC0((char *)p, (int)func_021E01B0, 0x3F);
    case 2:
        STEP(p) = 0;
        func_021ECB20((char *)p, 0x81, 1);
        func_021ECB20((char *)p, 0x82, 1);
        func_021ED888(WORK(p), 1);
        func_021EE364((char **)p, 6, p[0x16]);
        func_021ED544((char *)p, 6);
        func_02026124(OBJ(p), 0x27);
        func_02026124(OBJ(p), 0x28);
        if (NIB(p)->lo == 1) {
            func_021EE038((char *)p, 0, 1, 1);
            func_021ED508(p, 0xD, 1);
            return 0x40;
        }
        if (NIB(p)->lo == 2)
            func_021ED508(p, 0xD, 1);
        else
            func_021ED508(p, 0xE, 1);
        func_021EE038((char *)p, 2, 1, 1);
        return func_021EA458((BoxObj *)p, p[0x16]);
    }
    return 0x3F;
}


#undef NIB

#undef NIB
#define NIB(p) ((Nib_021E65E4 *)((p) + 0x1C))


#undef STEP

#undef STEP
#define STEP(p) (*(int *)(WORK(p) + 0xA194))


#undef MODE

#undef MODE
#define MODE(p) (*(int *)(*(char **)(p) + 0x24))


#undef CNT

#undef CNT
#define CNT(p) (*(unsigned short *)((p)->work + 0xA16C))


#undef WORK

#undef WORK


#define WORK(p) (*(char **)((p) + 0x2C))



#define ITEM(p) (*(unsigned short *)(WORK(p) + 0xA16C))



#define SEL(p) (*(unsigned char *)(WORK(p) + 0xA17C))




#define CUR(p) (*(unsigned short *)(WORK(p) + 0xA16E))


#undef W

#undef W




#define W(p) (*(u8 **)((p) + 44))


#undef MGR

#undef MGR





#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))


#undef OBJ

#undef OBJ







#define OBJ(p) (*(void **)((p)->work + 0x70))










/*
 * Sibling of src/matched/ov170_func_021E3E84.c.
 */
int func_021E65E4(BoxObj *p)
{
    unsigned r;
    if (p->hi == 1) {
        p->lo = 0;
        p->hi = 0;
        return func_021E8F50((char *)p, 0x41);
    }
    if ((func_020362DC() & 4) && p->lo != 0 && p->b18 == 0) {
        func_021DD238((char *)p);
        p->lo = 0;
        return func_021E8F50((char *)p, 0x41);
    }
    if (p->b18 == 0) {
        r = func_021EF1A4();
        if (r != -1) {
            func_020260F4(OBJ(p), 0);
            if (func_021DD25C((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
                func_021DEFEC((char *)p, (int)r + 0x1E);
                func_021EC000(p->work, 4, 0);
                return func_021EA39C((BoxObj *)((BoxObj *)p), r + 0x1E);
            }
            func_021DF040((char *)p);
            func_020260E4(OBJ(p), r + 0x1E);
            return 0x40;
        }
        r = func_021EF170();
        if (r != -1) {
            func_020260F4(OBJ(p), 0);
            if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
                func_021DEFEC((char *)p, r);
                func_021EC000(p->work, 4, 0);
                return func_021EA39C((BoxObj *)((BoxObj *)p), r);
            }
            func_021DF040((char *)p);
            func_020260E4(OBJ(p), r);
            return 0x40;
        }
    }
    r = func_021EE96C((char *)p);
    switch (r) {
    case 0x24:
        if (p->b18 != 0)
            break;
        func_020061E4(0x54C);
        func_021DF040((char *)p);
        return func_021E8F50((char *)p, 0x5D);
    case 0x25:
        func_020061E4(0x548);
        func_020260E4(OBJ(p), 0x24);
        func_021EE3E4((char **)p, 0x24);
        if (p->b18 == 0)
            func_021DF0BC((unsigned char *)p);
        else
            func_021ECC1C((unsigned char *)p);
        return func_021E9C94((char *)p, 0, 0x40);
    case 0x26:
        func_020061E4(0x548);
        func_020260E4(OBJ(p), 0x24);
        func_021EE3E4((char **)p, 0x24);
        if (p->b18 == 0)
            func_021DF0BC((unsigned char *)p);
        else
            func_021ECC1C((unsigned char *)p);
        return func_021E9CE0((char *)p, 0, 0x40);
    case 0x29:
        if (p->b18 != 0)
            break;
        func_020061E4(0x551);
        p->lo = 0;
        return func_021E954C((BoxObj *)((BoxObj *)p), 6, 9, func_021E8F50((char *)p, 0x41));
    case 0x2A:
        if (p->lo == 0 || p->b18 != 0)
            break;
        p->lo = 0;
        return func_021E8F50((char *)p, 0x41);
    case -2:
        if (p->b18 == 1)
            return func_021EA514((BoxObj *)((BoxObj *)p), 0xFF);
        func_020061E4(0x551);
        p->lo = 0;
        return func_021E954C((BoxObj *)((BoxObj *)p), 6, 9, func_021E8F50((char *)p, 0x41));
    case -6:
        if (func_020260E0(OBJ(p)) != 0x24)
            break;
        func_020061E4(0x548);
        return func_021E9C94((char *)p, 0, 0x40);
    case -5:
        if (func_020260E0(OBJ(p)) != 0x24)
            break;
        func_020061E4(0x548);
        return func_021E9CE0((char *)p, 0, 0x40);
    case -4:
        func_020061E4(0x548);
        break;
    case -3:
        func_020061E4(0x548);
        if (p->b18 == 0) {
            unsigned char v = func_020260E0(OBJ(p));
            if (v < 0x24)
                func_021DEFEC((char *)p, v);
            else
                func_021DF040((char *)p);
        }
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x40));
    case -1:
    case -7:
    case -8:
    case 0x27:
    case 0x28:
        break;
    default:
        if (p->b18 == 1)
            return func_021EA514((BoxObj *)((BoxObj *)p), r);
        return func_021EA458((BoxObj *)((BoxObj *)p), r);
    }
    return 0x40;
}









int func_021E695C(u8 *p)
{
    u8 index;
    u8 selection;
    switch (((struct Obj23905 *)(*(u8 * *)&((BoxTask *)p)->f2C))->fA194) {
    case 0:
        func_021DF040((char *)p);
        func_021EC000(*(char * *)&((BoxTask *)p)->f2C, 4, 0);
        if (p[30] == 0) {
            func_021EF3A0(*(struct WinMgr * *)&((struct Obj23906 *)(*(u8 * *)&((BoxTask *)p)->f2C))->f74);
        } else {
            func_021ED888(*(char * *)&((BoxTask *)p)->f2C, 0);
            func_021ECB20((char *)p, 1, 1);
            func_021EF3EC(*(struct WinMgr * *)&((struct Obj23907 *)(*(u8 * *)&((BoxTask *)p)->f2C))->f74);
        }
        func_020061E4(0x669);
        (((struct Obj23908 *)(*(u8 * *)&((BoxTask *)p)->f2C))->fA194)++;
        return func_021E8FC0((char *)p, (int)func_021E01B0, 65);
    case 1:
        ((struct Obj23909 *)(*(u8 * *)&((BoxTask *)p)->f2C))->fA194 = 0;
        func_021ED544((char *)p, 6);
        func_021ED508(p, 14, 1);
        func_021EE038((char *)p, 0, 0, 1);
        if (p[30] == 0) {
            index = func_020260E0(((struct Obj23910 *)(*(u8 * *)&((BoxTask *)p)->f2C))->f70);
            if (index >= 36)
                index = 0;
            else if (index >= 30)
                index = 0;
            func_021EE364((char **)p, 7, index);
            func_021DEFEC((char *)p, index);
            func_021EF670(*(char * *)&((BoxTask *)p)->f2C);
            return 57;
        } else {
            index = func_020260E0(((struct Obj23911 *)(*(u8 * *)&((BoxTask *)p)->f2C))->f70);
            selection = 0;
            if (index < 36 && index >= 30)
                selection = index - 30;
            func_021EE364((char **)p, 8, selection);
            func_021DEFEC((char *)p, selection + 30);
            func_021EF68C(*(char * *)&((BoxTask *)p)->f2C);
            return 70;
        }
    }
    return 65;
}








#undef OBJ







#undef OBJ






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ

#define OBJ(p) (*(void **)(WORK(p) + 0x70))










/*
 * Drop of a held item onto a slot: put it back when dropped where it was
 * picked up, otherwise swap the two slots' items.
 */
int func_021E6A60(unsigned char *p)
{
    Entry *o;
    if (NIB(p)->lo == 0)
        NIB(p)->hi = 1;
    func_021ED6E4((char **)p, 0);
    o = *(Entry **)(WORK(p) + 0x60);
    if (o->idx == p[0x16] && (p[0x17] == 0xFF || p[0x17] == p[0x14])) {
        unsigned short from = o->slot;
        func_021EA750((char *)p);
        func_021ECB60(WORK(p), p[0x16], 0);
        func_020260E4(OBJ(p), p[0x16]);
        func_021EE038((char *)p, 0, 1, 1);
        if (func_0202136C(ITEM(p)) == 1 && from != p[0x16]) {
            func_020061E4(0x557);
            func_021EBB28((char *)p, 0x18);
            STATE(p) = 0x44;
            return 6;
        }
        return 0x40;
    } else {
        unsigned short item;
        if (p[0x17] == p[0x14] || p[0x16] >= 0x1E)
            func_021ECB60(WORK(p), p[0x16], 1);
        func_021ECB60(WORK(p), o->idx, 0);
        item = func_021DD25C((void ***)p, o->idx, p[0x14], 6, 0);
        func_021DD2B4((int)p, o->idx, p[0x14], 6, ITEM(p));
        if (func_021DD718((void **)p, (void *)func_021DD2D0((void ***)p, p[0x14], o->idx)) == 1) {
            func_021DD8A8((void **)p, o->idx);
            func_021EC48C(p, p[0x14], o->idx, WIN(p, o->idx));
        }
        func_021DEFEC((char *)p, o->idx);
        func_020260E4(OBJ(p), o->idx);
        ITEM(p) = item;
        func_021DD2B4((int)p, p[0x16], p[0x17], 6, ITEM(p));
        if (func_021DD718((void **)p, (void *)func_021DD2D0((void ***)p, p[0x17], p[0x16])) == 1) {
            func_021DD8A8((void **)p, p[0x16]);
            if (p[0x17] == 0xFF || p[0x17] == p[0x14])
                func_021EC48C(p, p[0x14], p[0x16], WIN(p, p[0x16]));
        }
        if (ITEM(p) == 0) {
            p[0x16] = o->idx;
            func_021EA750((char *)p);
            func_021EE038((char *)p, 0, 1, 1);
            return 0x40;
        }
        func_021ED094(WORK(p), ITEM(p));
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 1);
        func_021EC000(WORK(p), 10, 1);
        func_021ED1C8(WORK(p));
        func_020061E4(0x666);
        return func_021E8FC0((char *)p, (int)func_021E122C, 0x43);
    }
}









int func_021E6C3C(unsigned char *p)
{
    unsigned short *o;
    unsigned char old;
    unsigned short slot, item;
    unsigned char r;
    if (((Flags_021E65E4 *)p)->lo == 0)
        ((Flags_021E65E4 *)p)->hi = 1;
    o = *(unsigned short **)(WORK(p) + 0x60);
    func_021ECB60(WORK(p), o[0], 0);
    old = p[0x16];
    slot = o[1];
    p[0x16] = o[0];
    func_021EA750((char *)p);
    item = *(unsigned short *)(WORK(p) + 0xA16C);
    *(unsigned short *)(WORK(p) + 0xA16C) = 0;
    if (func_0202136C(item) == 1 && slot != old) {
        func_020061E4(0x557);
        func_021ED55C((char **)p, 0);
        func_021EBB28((char *)p, 0x18);
        ((BoxTask *)p)->f28 = 0x44;
        return 6;
    }
    func_021ED55C((char **)p, 1);
    r = func_020260E0(*(void **)(WORK(p) + 0x70));
    if (r < 0x24)
        func_021DEFEC((char *)p, r);
    func_021EE038((char *)p, 0, 1, 1);
    return 0x40;
}









/*
 *   unsigned func_020260F0(unsigned char *p) { return *(unsigned *)(p+4); }
 */
int func_021E6CD4(u8 *p){func_021EBA70(*(char **)(p+0x2c),24);func_021DD14C((char *)p);if(func_020260F0(*(void **)(*(char **)(p+0x2c)+0x70))==1)func_021EC000(*(char **)(p+0x2c),4,1);return 64;}









#undef OBJ








#undef OBJ







#undef OBJ






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ
#define OBJ(p) (*(void **)(WORK(p) + 0x70))










/*
 * Twin of func_021E6A60 driven by the work fields: moves the held item from
 * slot 0xA16E to slot 0xA17E, swapping with what is there.
 */
int func_021E6D00(unsigned char *p)
{
    unsigned short item;
    if (NIB(p)->lo == 0)
        NIB(p)->hi = 1;
    if (TGT(p) == CUR(p) && (p[0x17] == 0xFF || p[0x17] == p[0x14])) {
        ITEM(p) = 0;
        func_021EE038((char *)p, 0, 1, 1);
        return 0x40;
    }
    if (p[0x17] == p[0x14] || CUR(p) >= 0x1E)
        func_021ECB60(WORK(p), CUR(p), 1);
    func_021ECB60(WORK(p), TGT(p), 0);
    item = func_021DD25C((void ***)p, TGT(p), p[0x14], 6, 0);
    func_021DD2B4((int)p, TGT(p), p[0x14], 6, ITEM(p));
    if (func_021DD718((void **)p, (void *)func_021DD2D0((void ***)p, p[0x14], TGT(p))) == 1) {
        func_021DD8A8((void **)p, TGT(p));
        func_021EC48C(p, p[0x14], TGT(p), WIN(p, TGT(p)));
    }
    func_021DEFEC((char *)p, TGT(p));
    ITEM(p) = item;
    func_021DD2B4((int)p, CUR(p), p[0x17], 6, ITEM(p));
    if (func_021DD718((void **)p, (void *)func_021DD2D0((void ***)p, p[0x17], CUR(p))) == 1) {
        func_021DD8A8((void **)p, CUR(p));
        if (p[0x17] == 0xFF || p[0x17] == p[0x14])
            func_021EC48C(p, p[0x14], CUR(p), WIN(p, CUR(p)));
    }
    if (ITEM(p) == 0) {
        func_021EE038((char *)p, 0, 1, 1);
        return 0x40;
    }
    func_021EA728(p);
    (*(Entry **)(WORK(p) + 0x60))->idx = TGT(p);
    func_021ED094(WORK(p), ITEM(p));
    func_021ED108(WORK(p), 1);
    func_021EBFA8(WORK(p), 10, 1);
    func_021EC000(WORK(p), 10, 1);
    func_021ED1C8(WORK(p));
    func_020061E4(0x666);
    return func_021E8FC0((char *)p, (int)func_021E122C, 0x43);
}









#undef OBJ








#undef OBJ







#undef OBJ






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ

#define OBJ(p) (*(void **)((p)->work + 0x70))










/*
 * Sibling of src/matched/ov170_func_021E5E68.c and ov170_func_021E376C.c.
 */
int func_021E6EC0(BoxObj *p)
{
    unsigned r;
    if (func_020362DC() & 4) {
        r = func_021EA9F4((BoxObj *)p, 0x3F);
        if (p->lo == 1) {
            unsigned char v = func_020260E0(OBJ(p));
            if (v < 6)
                p->b16 = v + 0x1E;
            else
                p->b16 = 0x1E;
        }
        return r;
    }
    r = func_021EF194();
    if (r != -1) {
        func_020260F4(OBJ(p), 0);
        if (func_021DD25C((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
            func_020061E4(0x666);
            func_02035D20((u32 *)(p->work + 0xA180), (u32 *)(p->work + 0xA184));
            func_021DEFEC((char *)p, (int)r + 0x1E);
            return func_021EA598((BoxObj *)((BoxObj *)p), r + 0x1E);
        }
        func_021DF040((char *)p);
        if (func_021EF5E8(MGR(p)) == 1) {
            func_021EEF74(p->work, (unsigned char)r, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), r + 0x1E);
            return func_021E7258((char *)p);
        }
        func_020260E4(OBJ(p), r);
        func_021EE3E4((char **)p, r);
        return 0x46;
    }
    r = func_021EEB40((char *)p);
    switch (r) {
    case 6:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 10, func_021E8F50((char *)p, 0x1C));
    case 7:
        func_020061E4(0x556);
        p->top->h28 = 1;
        return func_021E954C((BoxObj *)((BoxObj *)p), 7, 8, 0x10);
    case 8:
        func_020061E4(0x551);
        return func_021E954C((BoxObj *)((BoxObj *)p), 6, 9, func_021E8F50((char *)p, 0x1C));
    case 9:
        func_020061E4(0x54C);
        p->lo = 0;
        return func_021E949C((char *)p, 3, func_021E8F50((char *)p, 0x3F));
    case 10:
        func_020061E4(0x54C);
        if (*(unsigned short *)(p->work + 0xA16C) == 0) {
            p->b13 = 1;
            p->x24 = 10;
            return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x50));
        }
        return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x50));
    case 11: {
        unsigned char k;
        func_020061E4(0x551);
        k = p->b16 - 0x1E;
        func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), k);
        return func_021E949C((char *)p, 5, 0x47);
    }
    case 12:
        r = func_021EAA3C((BoxObj *)p, 0x3F);
        if (p->lo == 1) {
            unsigned char v = func_020260E0(OBJ(p));
            if (v < 6)
                p->b16 = v + 0x1E;
            else
                p->b16 = 0x1E;
        }
        return r;
    case -4:
        func_020061E4(0x548);
        break;
    case -3: {
        unsigned char v = func_020260E0(OBJ(p));
        if (v < 6)
            func_021DEFEC((char *)p, v + 0x1E);
        else if (v == 6)
            func_021DF040((char *)p);
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x46));
    }
    case -2:
        func_020061E4(0x551);
        if (func_021EF5E8(MGR(p)) == 1) {
            unsigned char k = p->b16 - 0x1E;
            func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), k);
            return func_021E949C((char *)p, 5, 0x47);
        }
        return func_021E954C((BoxObj *)((BoxObj *)p), 6, 9, func_021E8F50((char *)p, 0x1C));
    case -1:
    case -5:
    case -6:
    case -7:
    case -8:
        break;
    default:
        if (func_021DD25C((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
            func_020061E4(0x54C);
            return func_021EA66C((BoxObj *)((BoxObj *)p), r + 0x1E);
        }
        break;
    }
    return 0x46;
}








/*
 * Wrapper family member: func_021EF68C, state 0x46 and
 *   0x021E0E51 as the selector.
 */
int func_021E7258(char *p)
{
    func_021EF57C(*(struct WinMgr **)(*(int *)&((BoxTask *)p)->f2C + 0x74));
    func_021ED6E4((char **)p, 0);
    func_021EBA5C((char *)(*(int *)&((BoxTask *)p)->f2C), 0x18);
    func_021DD14C(p);
    func_021EF68C((char *)(*(int *)&((BoxTask *)p)->f2C));
    return func_021E8FC0(p, 0x21E0E51, func_021E8FE0(p, 0x46));
}








int func_021E7298(u8 *p)
{
    u16 *pair = *(u16 **)(W(p) + 96);
    u16 item = *(u16 *)(W(p) + 0xa16c);
    u16 second;
    if (item == 0) {
        func_021EA750((char *)p);
        func_021EBCB4(p, 0, 24);
        func_020260E4(*(void **)(W(p) + 112), 10);
        func_021EE3E4((char **)p, 10);
        func_021ED55C((char **)p, 1);
        return 70;
    }
    if (pair[0] == p[22]) {
        second = pair[1];
        func_021EA750((char *)p);
        func_020260E4(*(void **)(W(p) + 112), 9);
        func_021EE3E4((char **)p, 9);
        if (func_0202136C(*(u16 *)(W(p) + 0xa16c)) == 1 && second != p[22]) {
            func_021ECB60((char *)W(p), p[22], 0);
            func_021EBCB4(p, 7, 24);
            func_020061E4(0x557);
            *(int *)(p + 40) = 14;
            return func_021E8F50((char *)p, 6);
        }
        func_021EBCB4(p, 1, 24);
        func_021ED55C((char **)p, 1);
        return 70;
    }
    if (func_0202136C(item) == 1) {
        func_021EA750((char *)p);
        func_020061E4(0x557);
        func_021ECB60((char *)W(p), p[22], 0);
        func_021EBCB4(p, 7, 24);
        func_020061E4(0x557);
        func_020260E4(*(void **)(W(p) + 112), 9);
        func_021EE3E4((char **)p, 9);
        func_021ED55C((char **)p, 1);
        *(int *)(p + 40) = 14;
        return func_021E8F50((char *)p, 6);
    }
    func_021ECB60((char *)W(p), pair[0], 0);
    func_021ECB60((char *)W(p), p[22], 1);
    func_021ED6E4((char **)p, 0);
    func_021ED108((char *)W(p), 1);
    func_021EBFA8((char *)W(p), 10, 2);
    return 73;
}







#undef OBJ






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ

#define OBJ(p) (*(void **)(WORK(p) + 0x70))









/*
 * Item swap on drop (template 021E6A60): moves the held item onto the
 * target slot, returns the target's old item to the source, and either
 * finishes or keeps the new item held.
 */
int func_021E73D8(unsigned char *p)
{
    Entry *o;
    unsigned short item;

    if (func_021EBFEC(WORK(p), 10) == 1)
        return 0x49;
    func_021ED108(WORK(p), 0);
    func_021EC000(WORK(p), 10, 0);
    o = *(Entry **)(WORK(p) + 0x60);
    item = func_021DD25C((void ***)p, o->idx, p[0x14], 6, 0);
    func_021DD2B4((int)p, o->idx, p[0x14], 6, ITEM(p));
    if (func_021DD718((void **)p, (void *)func_021DD2D0((void ***)p, p[0x14], o->idx)) == 1) {
        func_021DD8A8((void * *)p, o->idx);
        func_021EC48C(p, p[0x14], o->idx, WIN(p, o->idx));
    }
    func_021DEFEC((char *)p, o->idx);
    ITEM(p) = item;
    func_021DD2B4((int)p, p[0x16], p[0x17], 6, ITEM(p));
    if (p[0x17] == 0xFF || p[0x17] == p[0x14]) {
        if (func_021DD718((void **)p, (void *)func_021DD2D0((void ***)p, p[0x14], p[0x16])) == 1) {
            func_021DD8A8((void * *)p, p[0x16]);
            func_021EC48C(p, p[0x14], p[0x16], WIN(p, p[0x16]));
        }
    }
    if (ITEM(p) == 0) {
        p[0x16] = o->idx;
        func_021EA750((char *)p);
        func_021EF68C(WORK(p));
        func_020260E4(OBJ(p), p[0x16] - 0x1E);
        func_021DEFEC((char *)p, p[0x16]);
        func_020260F4(OBJ(p), 1);
        return 0x46;
    }
    func_020061E4(0x666);
    func_021ED094(WORK(p), ITEM(p));
    func_021ED108(WORK(p), 1);
    func_021EBFA8(WORK(p), 10, 1);
    func_021EC000(WORK(p), 10, 1);
    func_021ED1C8(WORK(p));
    return func_021E8FC0((char *)p, (int)func_021E1988, func_021E8F50((char *)p, 0x4A));
}








int func_021E754C(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_020061E4(0x667);
        func_021ECB60(WORK(p), **(unsigned short **)(WORK(p) + 0x60), 0);
        func_021ED6E4((char **)p, 0);
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 2);
        func_020260E4(*(void **)(WORK(p) + 0x70), p[0x16] - 0x1E);
        func_021EA750((char *)p);
        STEP(p)++;
        break;
    case 1:
        if (func_021EBFEC(WORK(p), 10) == 1)
            break;
        func_021DEFEC((char *)p, p[0x16]);
        func_020260F4(*(void **)(WORK(p) + 0x70), 1);
        func_021EF68C(WORK(p));
        return 0x46;
    }
    return 0x4A;
}








#undef OBJ







#undef OBJ






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ

#define OBJ(p) (*(void **)((p)->work + 0x70))







#undef MGR






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR

#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))









int func_021E75E0(BoxObj *p)
{
    unsigned r = func_021EEEA4((char *)p);
    switch (r) {
    case 0x1E:
        func_021DF0BC((unsigned char *)p);
        break;
    case 0x1F:
        func_020061E4(0x548);
        func_021DF0BC((unsigned char *)p);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        return func_021E9C94((char *)p, 0, 0x4B);
    case 0x20:
        func_020061E4(0x548);
        func_021DF0BC((unsigned char *)p);
        func_020260E4(OBJ(p), 0x1E);
        func_021EE3E4((char **)p, 0x1E);
        return func_021E9CE0((char *)p, 0, 0x4B);
    case 0x21:
        func_020061E4(0x551);
        p->top->h28 = 0;
        p->top->b2A = 0xFF;
        p->top->b2B = 0xFF;
        return func_021E954C((BoxObj *)((BoxObj *)p), 6, 9, 0x68);
    case 0x22:
        func_020061E4(0x54C);
        return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x4D));
    case 0x23: {
        unsigned char k;
        func_020061E4(0x551);
        k = p->b16;
        func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), k);
        return func_021E949C((char *)p, 5, 0x4E);
    }
    case -6:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            func_020061E4(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9C94((char *)p, 0, 0x4B);
        }
        break;
    case -5:
        if (func_020260E0(OBJ(p)) == 0x1E) {
            func_020061E4(0x548);
            func_021DF0BC((unsigned char *)p);
            return func_021E9CE0((char *)p, 0, 0x4B);
        }
        break;
    case -4:
        func_020061E4(0x548);
        break;
    case -3: {
        unsigned char v = func_020260E0(OBJ(p));
        if (v < 0x1E)
            func_021DEFEC((char *)p, v);
        else if (v != 0x22 && v != 0x23)
            func_021DF040((char *)p);
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x4B));
    }
    case -2:
        func_020061E4(0x551);
        if (func_021EF5E8(MGR(p)) == 1) {
            unsigned char k = p->b16;
            func_021EEF74(p->work, k, func_020260E0(OBJ(p)));
            func_020260E4(OBJ(p), k);
            return func_021E949C((char *)p, 5, 0x4E);
        }
        p->top->h28 = 0;
        p->top->b2A = 0xFF;
        p->top->b2B = 0xFF;
        return func_021E954C((BoxObj *)((BoxObj *)p), 6, 9, 0x68);
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
            func_020061E4(0x54C);
            p->b16 = r;
            func_021EB988((unsigned char *)p, d_021EF8EC, 2);
            func_021DEFEC((char *)p, r);
            func_021ED588((char *)p);
            func_020260E4(OBJ(p), 0x22);
            if (func_021EF5E8(MGR(p)) == 1)
                return func_021E78F4((char *)p);
            func_021EEF74(p->work, 0x22, r);
            func_021EF534(MGR(p));
            return func_021E8FC0((char *)p, (int)func_021E070C, func_021E8FE0((char *)p, 0x4C));
        }
        func_020061E4(0x548);
        func_021DEFEC((char *)p, r);
        if (func_021EF5E8(MGR(p)) == 1) {
            func_021EF57C(MGR(p));
            func_021ED6E4((char **)p, 0);
            func_021EBA5C(p->work, 0x18);
            func_021DD14C((char *)p);
            return func_021E8FC0((char *)p, (int)func_021E0190, 0x4B);
        }
        break;
    }
    return 0x4B;
}








/*
 * Push the 0x16 field through the 0x18 selector; return 75.
 */
int func_021E78F4(char *p)
{
    func_021EBC58((unsigned char *)p, (unsigned char)p[0x16], 1, 0x18);
    return 0x4b;
}








int func_021E7904(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_021ED55C((char **)p, 0);
        func_021EF57C(*(struct WinMgr **)(WORK(p) + 0x74));
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E0190, 0x4D);
    case 1:
        if (func_021DD25C((void ***)p, p[0x16], p[0x14], 0x4C, 0) != 0) {
            func_021EBD1C((char *)p, 4, 0x18);
            ((BoxTask *)p)->f28 = 0xE;
            return func_021E8F50((char *)p, 6);
        }
        if (func_021DD908((char *)p, p[0x16]) == 0) {
            func_021EBD1C((char *)p, 6, 0x1B);
            ((BoxTask *)p)->f28 = 0xE;
            return func_021E8F50((char *)p, 6);
        }
        func_021ECB20((char *)p, 1, 1);
        func_021ECB60(WORK(p), p[0x16], 0);
        func_021EBD50(p);
        STEP(p) = 0;
        return func_021E8FE8(p, 5);
    }
    return 0x4D;
}








void func_021E79C8(unsigned char *p)
{
    func_021EF57C(*(struct WinMgr **)(WORK(p) + 0x74));
    func_021ED6E4((char **)p, 0);
    func_021EBA5C(WORK(p), 0x18);
    func_021DD14C((char *)p);
    func_021E8FC0((char *)p, (int)func_021E070C, func_021E8FE0((char *)p, 0x4B));
}








int func_021E7A04(unsigned char *p)
{
    return func_021E95CC(p, 0);
}








#undef MGR







#undef MGR






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))









/*
 * Item menu "give": checks the slot, then asks to swap or confirms.  A
 * four-step machine on the work word at 0xA194 (template 021E3C88).
 */
int func_021E7A10(unsigned char *p)
{
    switch (STEP(p)) {
    case 0: {
        unsigned item;
        if (*(int *)(TOP(p) + 0x24) == 4 && *(int *)(TOP(p) + 0x14) == 1) {
            func_021EC000(WORK(p), 4, 0);
            func_021EF57C(MGR(p));
            STEP(p) = 3;
            return func_021E8FC0((char *)p, (int)func_021E0190, 0x50);
        }
        if (func_021DD25C((void ***)p, p[0x16], p[0x14], 0x4C, 0) == 0) {
            item = func_021DD25C((void ***)p, p[0x16], p[0x14], 6, 0);
            if (item == 0)
                return func_021E95CC(p, 1);
            func_021EC000(WORK(p), 4, 0);
            func_021ED508(p, 0xE, 0);
            func_021ED888(WORK(p), 0);
            if (func_0202136C(item) == 1) {
                func_021EF57C(MGR(p));
                STEP(p) = 1;
                return func_021E8FC0((char *)p, (int)func_021E0190, 0x50);
            }
            if (p[0x16] < 0x1E)
                func_021ECB20((char *)p, 1, 1);
            else
                func_021ECB20((char *)p, 2, 1);
            func_021ECB60(WORK(p), p[0x16], 0);
            *(unsigned char *)(WORK(p) + 0xA170) = 1;
            func_021EF508(MGR(p));
            func_021EBAF8(p, item, 0x18);
            if (*(int *)(TOP(p) + 0x24) == 3)
                return func_021E8FE8(p, 2);
            return func_021E8FE8(p, 0);
        }
        func_021EC000(WORK(p), 4, 0);
        func_021EF57C(MGR(p));
        STEP(p) = 2;
        return func_021E8FC0((char *)p, (int)func_021E0190, 0x50);
    }
    case 1:
        func_020061E4(0x557);
        func_021EBB1C(p, 0x18);
        STATE(p) = 0xE;
        return func_021E8F50((char *)p, 6);
    case 2:
        func_020061E4(0x557);
        func_021EBCB4(p, 5, 0x18);
        STATE(p) = 0xE;
        return func_021E8F50((char *)p, 6);
    case 3:
        func_020061E4(0x557);
        func_021EBD78((char *)p, 1);
        STATE(p) = 0x2B;
        return 6;
    }
    return 0x50;
}








int func_021E7BD0(unsigned char *p)
{
    if (p[0x17] != 0xFF)
        func_021DEF98((char *)p, p[0x17], p[0x16]);
    else
        func_021DEFEC((char *)p, p[0x16]);
    func_021ED544((char *)p, 6);
    if (((Flags_021E65E4 *)p)->lo == 0)
        func_021ED508(p, 0xE, 1);
    else
        func_021ED508(p, 0xD, 1);
    switch (((struct Obj23912 *)(*(char * *)&((BoxTask *)p)->f0))->f24) {
    case 0:
        *(int *)(WORK(p) + 0xA198) = func_021E9968(p);
        break;
    case 1:
        *(int *)(WORK(p) + 0xA198) = func_021E9938(p);
        break;
    case 2:
        *(int *)(WORK(p) + 0xA198) = func_021E99B0(p);
        break;
    case 4:
        *(int *)(WORK(p) + 0xA198) = func_021E9B74(p);
        break;
    case 3:
        break;
    }
    return func_021E22B8((int)p);
}






#undef W





#undef W




#undef W



#undef W


#undef W

#undef W
#define W (*(char **)(p + 0x2c))






#undef OBJ





#undef OBJ




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ
#define OBJ(p) (*(void **)(WORK(p) + 0x70))







int func_021E7C58(unsigned char *p)
{
    func_021DF040((char *)p);
    switch (((struct Obj23913 *)(*(char * *)&((BoxTask *)p)->f0))->f24) {
    case 1:
        func_021EE364((char **)p, 2, 0x1E);
        *(int *)(WORK(p) + 0xA168) = 0x1E;
        *(int *)(WORK(p) + 0xA198) = 0x2C;
        break;
    case 2:
        func_021EF670(WORK(p));
        func_021EE364((char **)p, 3, 0x1E);
        *(int *)(WORK(p) + 0xA168) = 0x1E;
        *(int *)(WORK(p) + 0xA198) = 0x11;
        break;
    case 3:
        func_021ECB20((char *)p, 0x81, 1);
        func_021EF670(WORK(p));
        func_021EE364((char **)p, 7, 0x1E);
        *(int *)(WORK(p) + 0xA168) = 0x1E;
        *(int *)(WORK(p) + 0xA198) = 0x39;
        break;
    case 4:
        func_021EF670(WORK(p));
        func_021EE364((char **)p, 0xD, 0x1E);
        *(int *)(WORK(p) + 0xA168) = 0x1E;
        *(int *)(WORK(p) + 0xA198) = 0x23;
        break;
    case 0:
        break;
    }
    return func_021E22B8((int)p);
}







int func_021E7D04(u8 *p){switch(((struct Obj23914 *)(*(char * *)&((BoxTask *)p)->f0))->f24){case 2:((struct Obj23915 *)(*(char * *)&((BoxTask *)p)->f2C))->fA198=func_021E95F8(p);break;case 3:((struct Obj23916 *)(*(char * *)&((BoxTask *)p)->f2C))->fA198=func_021E96E8(p);break;case 4:((struct Obj23917 *)(*(char * *)&((BoxTask *)p)->f2C))->fA198=func_021E9848(p);break;}return func_021E22B8((int)p);}







/*
 * candidate func_021E7D3C: state machine step
 */
void func_021E7D3C(char *p)
{
    int v;
    func_021EBB64((unsigned char *)((int)p), ((BoxTask *)p)->f10, 0x18);
    v = *(int *)(*(int *)&((BoxTask *)p)->f0 + 0x24);
    if (v == 3)
        ((BoxTask *)p)->f28 = 0x3c;
    else
        ((BoxTask *)p)->f28 = 0xe;
    func_021E8F50((char *)((int)p), 6);
}







int func_021E7D64(u8 *p)
{
    switch (((struct Obj23918 *)(*(u8 * *)&((BoxTask *)p)->f2C))->fA194) {
    case 0:
        func_021EC000(*(char * *)&((BoxTask *)p)->f2C, 4, 0);
        func_021ED508(p, 14, 0);
        func_021EBA5C(*(char * *)&((BoxTask *)p)->f2C, 24);
        func_021DD14C((char *)p);
        func_021EF57C(*(struct WinMgr * *)&((struct Obj23919 *)(*(u8 * *)&((BoxTask *)p)->f2C))->f74);
        (((struct Obj23920 *)(*(u8 * *)&((BoxTask *)p)->f2C))->fA194)++;
        return func_021E8FC0((char *)p, (int)func_021E0190, 85);
    case 1:
        ((struct Obj23921 *)(*(u8 * *)&((BoxTask *)p)->f2C))->fA174 = func_021DD25C((void ***)p, p[22], p[20], 11, 0);
        func_021DF110((char *)p, ((struct Obj23922 *)(*(u8 * *)&((BoxTask *)p)->f2C))->fA174);
        func_021EF6A8(*(struct WinMgr * *)&((struct Obj23923 *)(*(u8 * *)&((BoxTask *)p)->f2C))->f74);
        func_020061E4(0x669);
        (((struct Obj23924 *)(*(u8 * *)&((BoxTask *)p)->f2C))->fA194)++;
        return func_021E8FC0((char *)p, (int)((int (*)(u8 *))func_021E01A8), 85);
    case 2:
        func_021EE364((char **)p, 9, 0);
        func_021ED888(*(char * *)&((BoxTask *)p)->f2C, 0);
        func_021ECB20((char *)p, 1, 1);
        func_021ECB20((char *)p, 2, 1);
        func_021ECB60(*(char * *)&((BoxTask *)p)->f2C, p[22], 0);
        func_021EBBBC((char *)p, 24);
        return func_021E8F50((char *)p, 86);
    }
    return 85;
}







int func_021E7E54(u8 *p)
{
    u8 mask;
    switch ((unsigned)func_02025DE8(((struct Obj23925 *)(*(u8 * *)&((BoxTask *)p)->f2C))->f70)) {
    case 0:
        func_020061E4(0x54c);
        func_021EA908((int)p, 0);
        break;
    case 1:
        func_020061E4(0x54c);
        func_021EA908((int)p, 1);
        break;
    case 2:
        func_020061E4(0x54c);
        func_021EA908((int)p, 2);
        break;
    case 3:
        func_020061E4(0x54c);
        func_021EA908((int)p, 3);
        break;
    case 4:
        func_020061E4(0x54c);
        func_021EA908((int)p, 4);
        break;
    case 5:
        func_020061E4(0x54c);
        func_021EA908((int)p, 5);
        break;
    case 6:
        mask = ((struct Obj23926 *)(*(u8 * *)&((BoxTask *)p)->f2C))->fA174;
        func_021DD2B4((int)p, p[22], p[20], 11, mask);
        func_021DF11C((char *)p, (unsigned)mask);
        func_020061E4(0x54c);
        return func_021E94AC((BoxObj *)p, 0, 87);
    case 7:
        func_020061E4(0x551);
        return func_021E94AC((BoxObj *)p, 1, 87);
    case (unsigned)-2:
        func_020061E4(0x551);
        return func_021E94AC((BoxObj *)p, 1, 87);
    case (unsigned)-3:
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, 88);
    case (unsigned)-4:
        func_020061E4(0x548);
        break;
    }
    return 86;
}







int func_021E7F6C(unsigned char *p)
{
    switch (((struct Obj23927 *)(*(char * *)&((BoxTask *)p)->f0))->f24) {
    case 0:
        func_021EE364((char **)p, 0, 10);
        break;
    case 1:
        func_021ED888(WORK(p), 1);
        func_021EE364((char **)p, 2, 0x25);
        break;
    case 2:
    default:
        if (p[0x16] < 0x1E) {
            func_021ED888(WORK(p), 1);
            func_021EE364((char **)p, 3, 0x27);
        } else {
            func_021EE364((char **)p, 5, 0xC);
        }
        break;
    }
    func_021ED55C((char **)p, 0);
    func_021EBA5C(WORK(p), 0x18);
    func_021DD14C((char *)p);
    if (p[0x16] < 0x1E)
        func_021ECB20((char *)p, 1, 0);
    func_021ECB20((char *)p, 2, 0);
    func_021EF6CC(*(struct WinMgr **)(WORK(p) + 0x74));
    func_020061E4(0x669);
    return func_021E8FC0((char *)p, (int)((int (*)(unsigned char *))func_021E01A8), func_021E8F50((char *)p, 0xE));
}








/*
 * Forward and then return a status constant.
 */
int func_021E8014(char *p)
{
    func_020307B0(((struct Obj18467 *)(*(char * *)&((BoxTask *)p)->f2C))->f60);
    return 0x56;
}







int func_021E8024(char *p)
{
    unsigned slot;
    switch (S) {
    case 0:
        func_021EC000(W, 4, 0);
        func_021ED508((unsigned char *)p, 14, 0);
        func_021EF57C(*(struct WinMgr **)(W + 0x74));
        S++;
        return func_021E8FC0(p, (int)func_021E0190, 0x59);
    case 1:
        if (((BoxTask *)p)->f16 >= 30) {
            func_021ECB20(p, 2, 1);
            func_021ECB60(W, ((BoxTask *)p)->f16, 0);
            slot = ((BoxTask *)p)->f16 - 30;
            if (func_021DD694((void ***)p, slot) == 0) {
                func_020061E4(0x557);
                func_021EBBC8((u8 *)p, 6, 24);
                *(u8 *)(W + 0xA170) = 1;
                ((BoxTask *)p)->f28 = 14;
                return func_021E8F50(p, 6);
            }
            if (func_0202136C(func_02017E1C(func_0201AB28(((struct Obj23928 *)(*(char * *)&((BoxTask *)p)->f0))->f8, slot), 6, 0)) == 1) {
                func_020061E4(0x557);
                func_021EBC58((u8 *)p, 0, 5, 24);
                *(u8 *)(W + 0xA170) = 1;
                ((BoxTask *)p)->f28 = 14;
                return func_021E8F50(p, 6);
            }
        } else {
            func_021ED888(W, 0);
            func_021ECB20(p, 1, 1);
            func_021ECB60(W, ((BoxTask *)p)->f16, 0);
        }
        if (func_02017E88((void *)func_021DD2D0((void ***)p, ((BoxTask *)p)->f14, ((BoxTask *)p)->f16), 0x4c, 0) != 0) {
            func_020061E4(0x557);
            func_021EBBC8((u8 *)p, 3, 24);
            *(u8 *)(W + 0xA170) = 1;
            ((BoxTask *)p)->f28 = 14;
            return func_021E8F50(p, 6);
        }
        func_021EBBC8((u8 *)p, 0, 24);
        return func_021E8F50(p, func_021E8FE8((u8 *)p, 1));
    }
    return 0x59;
}







int func_021E8188(unsigned char *p)
{
    func_021DE7C8(p);
    if (func_021EC994(SLOT(p)) == 0) {
        if (((unsigned char *)SLOT(p))[6] != 0)
            return func_021E8F50((char *)p, 0x5C);
        func_021ECA24((int *)SLOT(p));
        func_021DE7B4((char *)p);
        return func_021E8F50((char *)p, 0x5B);
    }
    return 0x5A;
}








/*
 * Four-step machine on the work word at 0xA194 for releasing a Pokemon:
 * two confirmation messages, then the release itself (box slot in place,
 * party slot with a fade), then the view is restored.
 */
int func_021E81D0(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_021EBBC8(p, 1, 0x18);
        STATE(p) = 0x5B;
        STEP(p)++;
        return 6;
    case 1:
        func_021EBBC8(p, 2, 0x18);
        STATE(p) = 0x5B;
        STEP(p)++;
        return 6;
    case 2:
        func_021DD314((char **)p, p[0x14], p[0x16]);
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C((char *)p);
        func_021DF040((char *)p);
        if (p[0x16] < 0x1E) {
            func_021EDAB0((char *)p, p[0x14]);
            func_021EDB34((char *)p, p[0x14]);
            if (MODE(p) == 1) {
                STATE(p) = 0x2C;
            } else {
                STATE(p) = 0x11;
                func_021EF670(WORK(p));
            }
            func_020260E4(OBJ(p), p[0x16]);
            func_021EE3E4((char **)p, p[0x16]);
            func_021ED55C((char **)p, 1);
            func_021ED888(WORK(p), 1);
            func_021ECB20((char *)p, 1, 0);
            func_021ED508(p, 0xE, 1);
            p[0x16] = 0xFF;
            STEP(p) = 0;
            return STATE(p);
        }
        func_021EA1C0(p);
        p[0x1A] = 1;
        func_021ECB20((char *)p, 2, 0);
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E002C, 0x5B);
    case 3:
        STEP(p) = 0;
        func_021EA1E8((char *)p);
        func_021DEFEC((char *)p, p[0x16]);
        func_020260E4(OBJ(p), p[0x16] - 0x1E);
        func_021EE3E4((char **)p, p[0x16] - 0x1E);
        func_021ED55C((char **)p, 1);
        p[0x16] = 0xFF;
        if (MODE(p) == 0)
            return 0x31;
        func_021ED508(p, 0xE, 1);
        func_021EF68C(WORK(p));
        return 0x1B;
    }
    return 0x5B;
}





#undef W




#undef W



#undef W


#undef W

#undef W
#define W (*(char **)(p + 0x2c))






int func_021E8340(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        if (func_021EC9D8(SLOT(p)) != 0)
            break;
        func_021ECA38((int *)SLOT(p));
        func_021DE7B4((char *)p);
        func_021ED588((char *)p);
        func_021EBBC8(p, 4, 0x18);
        ((BoxTask *)p)->f28 = 0x5C;
        STEP(p)++;
        return 6;
    case 1:
        func_021EBBC8(p, 5, 0x18);
        ((BoxTask *)p)->f28 = 0x5C;
        STEP(p)++;
        return 6;
    case 2:
        STEP(p) = 0;
        return func_021E912C(p);
    }
    return 0x5C;
}






/*
 * Return r0 from func_021EC01C and func_021EA858 is read by this caller.
 * Lever: low-nibble bitfield assignment emits bics #15; a byte mask
 * emits ands #240 and changes four concrete bytes at +0x120..+0x124.
 */
int func_021E83C0(char *p)
{
    switch (S) {
    case 0:
        S++;
        func_021EC000(W, 4, 0);
        func_021ED508((unsigned char *)p, 14, 0);
        func_021ED888(W, 0);
        if (func_021EF5E8(M) == 1) {
            if (func_021EC01C(W, 10) == 1)
                func_021EC000(W, 10, 0);
            func_021ED6E4((char **)p, 0);
            func_021EBA5C(W, 24);
            func_021DD14C(p);
            func_021EF57C(M);
            return func_021E8FC0(p, (int)func_021E0190, 0x5d);
        } else if (func_021EF770(M) == 1) {
            func_021EE008(p, 0, 0);
            func_021EF680(W);
            return func_021EA858(p, 0x5d);
        } else if (func_021EF45C(M) == 1) {
            func_021EF69C(W);
            func_021EF3A0(M);
            return func_021E8FC0(p, (int)func_021E01B0, 0x5d);
        } else {
            func_021EF680(W);
        }
    case 1:
        func_021EB988((unsigned char *)((BoxObj *)p), d_021EF908, 4);
        func_021EF534(M);
        S++;
        return func_021E8FC0(p, (int)func_021E0190, 0x5d);
    case 2:
        S = 0;
        func_021ECB20(p, 1, 1);
        func_021EBC28((u8 *)p, 0, 24);
        func_021EE364((char **)p, 10, 0);
        ((Flags_021E8340 *)p)->lo = 0;
        func_021ED544(p, 6);
        return 0x5e;
    }
    return 0x5d;
}






int func_021E8508(u8 *p)
{
    unsigned v = func_02025DE8(((struct Obj23929 *)(*(u8 * *)&((BoxTask *)p)->f2C))->f70);
    switch (v) {
    case 0:
        func_020061E4(0x54c);
        return func_021E949C((char *)p, 2, func_021E8F50((char *)p, 0x60));
    case 1:
        func_020061E4(0x54c);
        ((struct Obj23930 *)(*(u8 * *)&((BoxTask *)p)->f2C))->fA17C = 0;
        return func_021E949C((char *)p, 3, func_021E8F50((char *)p, 0x64));
    case 2:
        func_020061E4(0x54c);
        return func_021E949C((char *)p, 4, 0x67);
    case 3:
        func_020061E4(0x551);
        return func_021E949C((char *)p, 5, func_021E8F50((char *)p, 0x5f));
    case -2:
        func_020061E4(0x551);
        return func_021E949C((char *)p, 5, func_021E8F50((char *)p, 0x5f));
    case -3:
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x5e));
    }
    return 0x5e;
}






int func_021E85F0(char *p)
{
    switch (S) {
    case 0:
        func_021ED55C((char **)p, 0);
        func_021EBA5C(W, 24);
        func_021DD14C(p);
        func_021EE038(p, 0, 0, 1);
        func_021EF57C(*(struct WinMgr **)(W + 0x74));
        S++;
        return func_021E8FC0(p, (int)func_021E0190, 0x5f);
    case 1:
        S = 0;
        func_021ED888(W, 1);
        func_021ED508((unsigned char *)p, 14, 1);
        if (((struct Obj23931 *)(*(char * *)&((BoxTask *)p)->f0))->f24 == 2) {
            func_021ECB20(p, 1, 0);
            func_021EF670(W);
            func_021EE364((char **)p, 3, 30);
            return 17;
        } else if (((struct Obj23932 *)(*(char * *)&((BoxTask *)p)->f0))->f24 == 1) {
            func_021ECB20(p, 1, 0);
            func_021EE364((char **)p, 2, 30);
            return 44;
        } else if (((struct Obj23933 *)(*(char * *)&((BoxTask *)p)->f0))->f24 == 3) {
            func_021ECB20(p, 0x81, 1);
            func_021EF670(W);
            func_021EE364((char **)p, 7, 30);
            return 57;
        } else if (((struct Obj23934 *)(*(char * *)&((BoxTask *)p)->f0))->f24 == 4) {
            func_021ECB20(p, 1, 0);
            func_021EF670(W);
            func_021EE364((char **)p, 13, 30);
            return 35;
        }
    }
    return 0x5f;
}






int func_021E86EC(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        *(unsigned char *)(WORK(p) + 0xA17A) = 1;
        func_021ED55C((char **)p, 0);
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C((char *)p);
        func_021EF57C(*(struct WinMgr **)(WORK(p) + 0x74));
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E0190, 0x60);
    case 1:
        p[0x19] = p[0x14];
        STEP(p)++;
        func_020061E4(0x669);
        return func_021EA83C((char *)p, 0x60);
    case 2:
        STEP(p) = 0;
        func_021EE008((char *)p, 0, 1);
        func_021EE364((char **)p, 0xC, 1);
        *(int *)(WORK(p) + 0xA168) = 1;
        func_021EBC28(p, 1, 0x19);
        func_021EE038((char *)p, 0, 1, 1);
        return 0x61;
    }
    return 0x60;
}




#undef CUR



#undef CUR


#undef CUR

#undef CUR
#define CUR(p) (*(unsigned char *)(WORK(p) + 0xA17F))




#undef W



#undef W


#undef W

#undef W
#define W (*(char **)(p + 0x2c))




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))






/*
 * List input for the box menu: a touch pick stores the slot and leaves,
 * otherwise the list result selects a page, a jump, or a cancel.
 */
int func_021E87A0(unsigned char *p)
{
    unsigned x, y;
    unsigned r;

    if (func_021EF1D4(&x, &y) == 1) {
        *(unsigned *)(WORK(p) + 0xA184) = y;
        STATE(p) = 0x61;
        func_021EA808((char *)p);
        func_020260F4(LIST(p), 0);
        return 0xF;
    }
    r = func_02025DE8(LIST(p));
    switch (r) {
    case 0:
        func_020061E4(0x548);
        func_021DD1C4((char *)p, -1);
        return func_021E8FC0((char *)p, (int)func_021E1ACC, 0x61);
    case 5:
        func_020061E4(0x548);
        func_021DD1C4((char *)p, 1);
        return func_021E8FC0((char *)p, (int)func_021E1A78, 0x61);
    case 1:
    case 2:
    case 3:
    case 4:
        CUR(p) = p[0x19] + r - 1;
        if (CUR(p) >= p[0x15])
            CUR(p) -= p[0x15];
        if (CUR(p) != p[0x14]) {
            func_021EE008((char *)p, 0, 0);
            return func_021EA798(p, 1);
        }
        func_020061E4(0x548);
        func_021EE008((char *)p, r - 1, 1);
        break;
    case 6:
    case (unsigned)-2:
        func_020061E4(0x551);
        return func_021E954C((BoxObj *)((BoxObj *)p), 6, 9, func_021E8F50((char *)p, 0x62));
    case (unsigned)-3:
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x61));
    case (unsigned)-8:
        if (func_020260E0(LIST(p)) == 1) {
            func_020061E4(0x548);
            func_021DD1C4((char *)p, -1);
            return func_021E8FC0((char *)p, (int)func_021E1ACC, 0x61);
        }
        break;
    case (unsigned)-7:
        if (func_020260E0(LIST(p)) == 4) {
            func_020061E4(0x548);
            func_021DD1C4((char *)p, 1);
            return func_021E8FC0((char *)p, (int)func_021E1A78, 0x61);
        }
        break;
    }
    return 0x61;
}





/*
 * Return from func_021EA858 is used despite its legacy void declaration.
 */
int func_021E8950(char *p)
{
    switch (S) {
    case 0:
        *(u8 *)(W + 0xA17A) = 0;
        func_021ED55C((char **)p, 0);
        func_021EBA5C(W, 25);
        func_021DD14C(p);
        func_021EE008(p, 0, 0);
        func_020061E4(0x669);
        S++;
        return func_021EA858(p, 0x62);
    case 1:
        S = 0;
        func_021ED888(W, 1);
        func_021EE038(p, 0, 0, 1);
        func_021ED508((unsigned char *)p, 14, 1);
        if (((struct Obj23935 *)(*(char * *)&((BoxTask *)p)->f0))->f24 == 2) {
            func_021ECB20(p, 1, 0);
            func_021EF670(W);
            func_021EE364((char **)p, 3, 30);
            return 17;
        } else if (((struct Obj23936 *)(*(char * *)&((BoxTask *)p)->f0))->f24 == 1) {
            func_021ECB20(p, 1, 0);
            func_021EE364((char **)p, 2, 30);
            return 44;
        } else if (((struct Obj23937 *)(*(char * *)&((BoxTask *)p)->f0))->f24 == 3) {
            func_021ECB20(p, 0x81, 1);
            func_021EF670(W);
            func_021EE364((char **)p, 7, 30);
            return 57;
        } else if (((struct Obj23938 *)(*(char * *)&((BoxTask *)p)->f0))->f24 == 4) {
            func_021ECB20(p, 1, 0);
            func_021EF670(W);
            func_021EE364((char **)p, 13, 30);
            return 35;
        }
    }
    return 0x62;
}





int func_021E8A58(char *p)
{
    func_021EE008(p, func_020260E0((struct Sound *)(*(int *)(*(int *)&((BoxTask *)p)->f2C + 0x70))) - 1, 1);
    return 0x61;
}






/*
 * Three-step machine on the work word at 0xA194 for the box-list menu:
 * fade out, open the menu for list kind 0xA17C (two kinds pick the long
 * menu when a save flag is set), then print the prompt and lock the list.
 */
int func_021E8A74(unsigned char *p)
{
    int flag;

    switch (STEP(p)) {
    case 0:
        func_021ED55C((char **)p, 0);
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C((char *)p);
        func_021EF57C(MGR(p));
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E0190, 0x64);
    case 1:
        if (KIND(p) == 0) {
            if (func_02007A80(SAVE(p), 1) == 1)
                func_021EB988((unsigned char *)((BoxObj *)p), d_021EF9C8, 6);
            else
                func_021EB988((unsigned char *)((BoxObj *)p), d_021EF93C, 5);
        } else if (KIND(p) == 1) {
            func_021EB988((unsigned char *)((BoxObj *)p), d_021EF964, 5);
        } else if (KIND(p) == 2) {
            func_021EB988((unsigned char *)((BoxObj *)p), d_021EF978, 5);
        } else if (KIND(p) == 3) {
            func_021EB988((unsigned char *)((BoxObj *)p), d_021EF98C, 5);
        } else if (KIND(p) == 4) {
            func_021EB988((unsigned char *)((BoxObj *)p), d_021EF9A0, 5);
        } else if (KIND(p) == 5) {
            if (func_02007A80(SAVE(p), 2) == 1)
                func_021EB988((unsigned char *)((BoxObj *)p), d_021EF9E0, 6);
            else
                func_021EB988((unsigned char *)((BoxObj *)p), d_021EF928, 5);
        } else if (KIND(p) == 6) {
            func_021EB988((unsigned char *)((BoxObj *)p), d_021EF9F8, 6);
        }
        func_021EF534(MGR(p));
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E0190, 0x64);
    case 2:
        STEP(p) = 0;
        if (KIND(p) == 0)
            func_021EBC28(p, 2, 0x18);
        else
            func_021EBC28(p, 3, 0x18);
        flag = 0;
        if (KIND(p) == 0) {
            if (func_02007A80(SAVE(p), 1) == 0)
                flag = 1;
        } else if (KIND(p) == 5) {
            if (func_02007A80(SAVE(p), 2) == 0)
                flag = 1;
        } else if (KIND(p) != 6) {
            flag = 1;
        }
        if (flag == 1) {
            func_021EE364((char **)p, 0xB, 1);
            func_02026124(LIST(p), 0);
        } else {
            func_021EE364((char **)p, 0xB, 0);
        }
        return 0x65;
    }
    return 0x64;
}






int func_021E8BF8(unsigned char *p)
{
    switch ((unsigned)func_02025DE8(*(void **)(WORK(p) + 0x70))) {
    case 0:
        func_020061E4(0x54C);
        if (SEL(p) == 0) {
            SEL(p) = 5;
            return func_021E949C((char *)p, 0, func_021E8F50((char *)p, 0x64));
        }
        return func_021EA928(p, 0);
    case 1:
        func_020061E4(0x54C);
        if (SEL(p) == 0) {
            SEL(p) = 1;
            return func_021E949C((char *)p, 1, func_021E8F50((char *)p, 0x64));
        }
        return func_021EA928(p, 1);
    case 2:
        func_020061E4(0x54C);
        if (SEL(p) == 0) {
            SEL(p) = 2;
            return func_021E949C((char *)p, 2, func_021E8F50((char *)p, 0x64));
        }
        return func_021EA928(p, 2);
    case 3:
        func_020061E4(0x54C);
        if (SEL(p) == 0) {
            SEL(p) = 3;
            return func_021E949C((char *)p, 3, func_021E8F50((char *)p, 0x64));
        }
        return func_021EA928(p, 3);
    case 4:
        func_020061E4(0x54C);
        if (SEL(p) == 0) {
            SEL(p) = 4;
            return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x64));
        }
        if (SEL(p) == 5 && func_02007A80(((void **)((BoxTask *)p)->f0)[1], 2) == 1) {
            SEL(p) = 6;
            return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x64));
        }
        if (SEL(p) == 6) {
            SEL(p) = 5;
            return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x64));
        }
        return func_021EA928(p, 4);
    case 5:
        func_020061E4(0x551);
        if (SEL(p) == 0)
            return func_021E949C((char *)p, 5, func_021E8F50((char *)p, 0x5F));
        SEL(p) = 0;
        return func_021E949C((char *)p, 5, func_021E8F50((char *)p, 0x64));
    case 0xFFFFFFFE:
        func_020061E4(0x551);
        if (SEL(p) == 0)
            return func_021E949C((char *)p, 5, func_021E8F50((char *)p, 0x5F));
        SEL(p) = 0;
        return func_021E949C((char *)p, 5, func_021E8F50((char *)p, 0x64));
    case 0xFFFFFFFD:
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x65));
    }
    return 0x65;
}



#undef W


#undef W

#undef W

#define W (*(char **)(p + 0x2c))



#undef ITEM


#undef ITEM

#undef ITEM
#define ITEM (*(unsigned short *)(p+0x10))



#undef OBJ


#undef OBJ

#undef OBJ
#define OBJ(p) (*(void **)((p)->work + 0x70))



#undef SEL


#undef SEL

#undef SEL
#define SEL(p) (*(unsigned char *)((p)->work + 0xA17E))









int func_021E8E24(char *p)
{
    switch (S) {
    case 0:
        func_021ED55C((char **)p, 0);
        func_020216D4(*(void **)(W + 0x6c), 0, 0, 0x200);
        PALANM_RequestFade(*(void **)(W + 0x6c), 1, 0xc000, 0, 0, 16, 0x7fff, (void *)func_020056BC());
        ((BoxTask *)p)->f28 = 0x66;
        S++;
        return 3;
    case 1:
        func_021DED58(p, *(u8 *)(W + 0xA17B));
        func_02007838(((struct Obj23940 *)(*(char * *)&((BoxTask *)p)->f0))->f4, ((BoxTask *)p)->f14, *(u8 *)(W + 0xA17B));
        func_021EDAB0(p, ((BoxTask *)p)->f14);
        S++;
        break;
    case 2:
        PALANM_RequestFade(*(void **)(W + 0x6c), 1, 0xc000, 0, 16, 0, 0x7fff, (void *)func_020056BC());
        ((BoxTask *)p)->f28 = 0x66;
        S++;
        return 3;
    case 3:
        func_021ED55C((char **)p, 1);
        S = 0;
        return 0x65;
    }
    return 0x66;
}









int func_021E8F14(unsigned char *p)
{
    return func_021E95CC(p, 2);
}









void func_021E8F20(u8 *p){func_021EC000(*(char * *)&((BoxTask *)p)->f2C,4,0);func_021ED508(p,14,0);func_021EBADC((char *)p,24);func_021EA984(p);func_021E8FE8(p,4);}











/*
 * Clear the pooled-offset word and return the argument.
 */
int func_021E8F50(char *p, int v)
{
    ((struct Obj18468 *)(*(char * *)&((BoxTask *)p)->f2C))->fA194 = 0;
    return v;
}











/*
 * Sibling of func_021E8F90: the seven-argument setup call then
 * the state word at +0xA188 of the sub-object, return 2.
 */
int func_021E8F60(void *p, int a)
{
    func_0202208C(0, 1, 1, 0, 6, 1, 0x4c);
    *(int *)(((struct Obj18469 *)p)->f2C + 0xA188) = a;
    return 2;
}











/*
 * Same body as func_021E8F60 with the first four arguments zero;
 * the state word goes to +0xA188, return 2.
 */
int func_021E8F90(void *p, int a)
{
    func_0202208C(0, 0, 0, 0, 6, 1, 0x4c);
    *(int *)(((struct Obj18470 *)p)->f2C + 0xA188) = a;
    return 2;
}









/*
 * Store the third argument, then reset the sub-object.
 */
int func_021E8FC0(char *p, int a, int b)
{
    *(int *)(*(int *)&((BoxTask *)p)->f2C + 0x68) = b;
    func_021DC9A0(*(char * *)&((BoxTask *)p)->f2C, a);
    return 5;
}









/*
 * Store the second argument, then re-seat the sub-object.
 */
int func_021E8FD0(char *p, int a)
{
    *(int *)(*(int *)&((BoxTask *)p)->f2C + 0x68) = a;
    func_021DC9B8(*(char * *)&((BoxTask *)p)->f2C);
    return 5;
}











/*
 * Store v at +0x28, return 13.
 */
int func_021E8FE0(char *p, int v)
{
    ((BoxTask *)p)->f28 = v;
    return 0xd;
}



#undef WORK


#undef WORK

#undef WORK







#define WORK(p) (*(char **)((p) + 0x2C))










/*
 * Opens the yes/no menu with the cursor on sel and enters state 7.
 */
int func_021E8FE8(unsigned char *p, int sel)
{
    *(unsigned short *)(WORK(p) + 0x1A4) = sel;
    if (sel == 1)
        func_021DCF58(p, 1);
    else
        func_021DCF58(p, 0);
    KEY_SetRepeatSpeed(*(unsigned *)(WORK(p) + 0x4C), *(unsigned *)(WORK(p) + 0x50));
    return 7;
}









#undef WORK








#undef WORK







#undef WORK






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK
#define WORK(p) (*(char **)((p) + 0x2C))









int func_021E9010(unsigned char *p)
{
    unsigned item;
    void *mon;
    item = func_021DD25C((void ***)p, p[0x16], p[0x14], 6, 0);
    if (func_02007E50(((struct Obj23942 *)(*(char * *)&((BoxTask *)p)->f0))->fC, item, 1, 0x4C) == 1) {
        mon = (void *)func_021DD2D0((void ***)p, p[0x14], p[0x16]);
        func_021EBB34((char *)p, item, 0x18);
        func_021DD2B4((int)p, p[0x16], p[0x14], 6, 0);
        if (func_021DD718((void **)p, mon) == 1) {
            func_021DD8A8((void **)p, p[0x16]);
            func_021EC48C(p, p[0x14], p[0x16], *(unsigned char *)(WORK(p) + p[0x16] + 0x3DD2));
        }
        func_021DEFF8((char *)p, p[0x16]);
    } else {
        func_020061E4(0x557);
        func_021EBB58((char *)p, 0x18);
    }
    if (func_020355C4() == 1) {
        func_020260F4(*(void **)(WORK(p) + 0x70), 0);
    } else {
        func_020260F4(*(void **)(WORK(p) + 0x70), 1);
        func_021ED55C((char **)p, 0);
    }
    ((BoxTask *)p)->f28 = 0xE;
    return func_021E8F50((char *)p, 6);
}









#undef WORK








#undef WORK







#undef WORK






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK
#define WORK(p) (*(char **)((p) + 0x2C))









int func_021E90D4(unsigned char *p)
{
    func_021ED6E4((char **)p, 0);
    func_021EBA5C(WORK(p), 0x18);
    func_021DD14C((char *)p);
    func_021DE728(p);
    func_021EC94C(*(char **)(WORK(p) + 0xA190));
    if (func_020355C4() == 1) {
        func_020260F4(*(void **)(WORK(p) + 0x70), 0);
    } else {
        func_020260F4(*(void **)(WORK(p) + 0x70), 1);
        func_021ED55C((char **)p, 0);
    }
    return 0x5A;
}









#undef WORK








#undef WORK







#undef WORK






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK
#define WORK(p) (*(char **)((p)+0x2C))









int func_021E912C(unsigned char *p) {
 func_021ED6E4((char **)p,1); func_021EBA70(WORK(p),0x18); func_021DD14C((char *)p);
 if(p[0x16]<0x1E) { func_021ED888(WORK(p),1); func_021ECB20((char *)p,1,0); }
 else func_021ECB20((char *)p,2,0);
 if(func_020355C4()==1) func_020260F4(*(void **)(WORK(p)+0x70),0);
 else { func_020260F4(*(void **)(WORK(p)+0x70),1); func_021ED55C((char **)p,0); }
 return func_021E8FC0((char *)p,(int)func_021E0190,func_021E8F50((char *)p,0xE));
}









#undef WORK








#undef WORK







#undef WORK






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK
#define WORK(p) (*(char **)((p) + 0x2C))









int func_021E91A0(unsigned char *p)
{
    void *mon;
    if(func_020355C4()==1) func_020260F4(*(void **)(WORK(p)+0x70),0);
    else { func_020260F4(*(void **)(WORK(p)+0x70),1); func_021ED55C((char **)p,0); }
    if(func_02007E50(((struct Obj23943 *)(*(char * *)&((BoxTask *)p)->f0))->fC,*(unsigned short *)(WORK(p)+0xa16c),1,0x4c)==1) {
        mon=(void *)func_021DD2D0((void ***)p,p[0x14],p[0x16]);
        func_021DD2B4((int)p,p[0x16],p[0x14],6,0);
        if(func_021DD718((void **)p,mon)==1) {
            func_021DD8A8((void **)p,p[0x16]);
            func_021EC48C(p,p[0x14],p[0x16],*(unsigned char *)(WORK(p)+p[0x16]+0x3dd2));
        }
        func_021DEFEC((char *)p,p[0x16]); func_021ED6E4((char **)p,0);
        func_021EBA5C(WORK(p),0x18); func_021DD14C((char *)p); func_021EF670(WORK(p));
        func_021ED108(WORK(p),1); func_021EBFA8(WORK(p),0xa,2);
        return 0x3b;
    }
    func_020061E4(0x557); func_021EBCB4(p,6,0x18);
    ((BoxTask *)p)->f28=0xe;
    return func_021E8F50((char *)p,6);
}









/*
 * Set the id, re-key the queue, store 0x69 as the frame, then
 *   arm the flag.
 */
int func_021E9284(char *p)
{
    func_020061E4(0x55D);
    func_021DE898((int *)p);
    ((BoxTask *)p)->f28 = 0x69;
    return func_021E8F90(p, 1);
}









#undef WORK








#undef WORK







#undef WORK






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK
#define WORK (*(char **)(p+0x2c))









/*
 * trailing extent: two-byte zero alignment at 021E93F2.
 */
int func_021E92A8(unsigned char *p)
{
    func_021EBA5C(WORK,0x18);
    func_021DD14C((char *)p);
    if(func_020355C4()==1) func_020260F4(*(void **)(WORK+0x70),0);
    else func_020260F4(*(void **)(WORK+0x70),1);
    func_021ED508(p,0xe,1);
    switch(((struct Obj23944 *)(*(char * *)&((BoxTask *)p)->f0))->f24) {
    case 0: func_021ECB20((char *)p,2,0); return 0x31;
    case 1: func_021ED888(WORK,1); func_021ECB20((char *)p,1,0); return 0x2c;
    case 2:
        if(func_021EF480(*(struct WinMgr **)(WORK+0x74))==1) {
            func_021ECB20((char *)p,2,0); func_021EF68C(WORK); return 0x1b;
        }
        func_021ED888(WORK,1); func_021ECB20((char *)p,1,0); func_021EF670(WORK); return 0x11;
    case 3:
        if(func_021EF480(*(struct WinMgr **)(WORK+0x74))==1) {
            func_021ECB20((char *)p,0x82,0); func_021EF68C(WORK); return 0x46;
        }
        func_021ED888(WORK,1); func_021ECB20((char *)p,0x81,0); func_021EF670(WORK); return 0x39;
    case 4:
        if(func_021EF480(*(struct WinMgr **)(WORK+0x74))==1) {
            func_021ECB20((char *)p,2,0); func_021EF68C(WORK); return 0x27;
        }
        func_021ED888(WORK,1); func_021ECB20((char *)p,1,0); func_021EF670(WORK); return 0x23;
    case 5: func_021ED888(WORK,1); func_021ECB20((char *)p,0x81,1); return 0x4b;
    }
    return 0x11;
}









/*
 * candidate func_021E93F4: copy two bytes into a sub object
 */
void func_021E93F4(char *p)
{
    func_021DE898((int *)((int)p));
    *(unsigned char *)(((struct Obj05869 *)p)->f0 + 0x2a) = ((BoxTask *)p)->f14;
    *(unsigned char *)(((struct Obj05869 *)p)->f0 + 0x2b) = ((BoxTask *)p)->f16;
    ((BoxTask *)p)->f28 = 0x69;
    func_021E8F90((void *)((int)p), 1);
}









#undef WORK








#undef WORK







#undef WORK






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK
#define WORK(p) (*(char **)((p)+0x2C))









int func_021E941C(unsigned char *p) {
 func_021EBA5C(WORK(p),0x1B); func_021DD14C((char *)p);
 func_020260E4(*(void **)(WORK(p)+0x70),p[0x16]);
 func_021ECB20((char *)p,0x81,1); func_021ED6E4((char **)p,0);
 if(func_020355C4()==1) func_020260F4(*(void **)(WORK(p)+0x70),0);
 else func_020260F4(*(void **)(WORK(p)+0x70),1);
 return 0x4B;
}









void func_021E946C(unsigned char *p){if(func_020355C4()==1)func_020260F4(((struct Obj23945 *)(*(unsigned char * *)&((BoxTask *)p)->f2C))->f70,0);else {func_020260F4(((struct Obj23946 *)(*(unsigned char * *)&((BoxTask *)p)->f2C))->f70,1);func_021ED55C((char **)p,0);}func_021E2334(p);}









/*
 * Forward, then store the third argument at 0x28.
 */
int func_021E949C(char *p, int a, int b)
{
    func_021DD090(p, a);
    ((BoxTask *)p)->f28 = b;
    return 8;
}









int func_021E94AC(BoxObj *p,int a,int b) {
 ((BoxWorkView *)p->work)->flag=1;
 ((BoxWorkView *)p->work)->id=BGWINFRM_GetBgFrame(*(struct WinMgr * *)&((struct Obj23947 *)((char *)p->work))->f74,7);
 ((BoxWorkView *)p->work)->lo=13;
 ((BoxWorkView *)p->work)->hi=12;
 ((BoxWorkView *)p->work)->state=0;
 ((BoxWorkView *)p->work)->count=0;
 if(a==0) ((BoxWorkView *)p->work)->y=14;
 else ((BoxWorkView *)p->work)->y=17;
 ((BoxWorkView *)p->work)->x=21;
 ((BoxWorkView *)p->work)->w=11;
 ((BoxWorkView *)p->work)->h=3;
 p->x28=b;
 return 8;
}








#undef WORK







#undef WORK






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))










int func_021E954C(BoxObj *p, int id, int lo, int arg)
{
    ((BoxWorkView *)p->work)->flag = 0;
    ((BoxWorkView *)p->work)->id = (unsigned char)id;
    ((BoxWorkView *)p->work)->lo = (unsigned char)lo;
    ((BoxWorkView *)p->work)->hi = 0;
    ((BoxWorkView *)p->work)->state = 0;
    ((BoxWorkView *)p->work)->count = 0;
    ((BoxWorkView *)p->work)->x = 0;
    ((BoxWorkView *)p->work)->y = 0;
    ((BoxWorkView *)p->work)->w = 0;
    ((BoxWorkView *)p->work)->h = 0;
    p->x28 = arg;
    return 8;
}










/*
 * Enters state 9 with reason v.
 */
int func_021E95CC(unsigned char *p, unsigned char v)
{
    if (func_020260F0(*(void **)(WORK(p) + 0x70)) == 1)
        func_020355D8(0);
    else
        func_020355D8(1);
    ((BoxTask *)p)->f28 = 9;
    p[0x12] = v;
    return func_021E8F90(p, 1);
}







#undef WORK






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK
#define WORK (*(char **)(p+0x2c))







int func_021E95F8(unsigned char *p)
{
    int next;
    void *mon;
    switch(p[0x13]) {
    case 0: func_021EF670(WORK); next=0x11; break;
    case 1:
        func_021EA75C((int)p); func_021ECB20((char *)p,1,1); func_021ED888(WORK,0);
        func_021EE364((char **)p,5,0xb); func_021EF68C(WORK); next=0x1b; break;
    }
    func_021ED588((char *)p);
    if(ITEM==0) {
        func_021DEFEC((char *)p,p[0x16]); func_021EB988((unsigned char *)((BoxObj *)p), data_021EFA10, 6);
        func_021EF4E4(*(struct WinMgr **)(WORK+0x74)); func_021EBC58(p,p[0x16],1,0x18);
        return next;
    }
    if(func_0202136C(ITEM)==0) {
        mon=(void *)func_021DD2D0((void ***)p,p[0x14],p[0x16]);
        func_021DD2B4((int)p,p[0x16],p[0x14],6,ITEM);
        if(func_021DD718((void **)p,mon)==1) {
            func_021DD8A8((void * *)p, p[0x16]);
            func_021EC48C(p,p[0x14],p[0x16],*(unsigned char *)(WORK+p[0x16]+0x3dd2));
        }
        func_02007F1C(((struct Obj23948 *)(*(char * *)&((BoxTask *)p)->f0))->fC,ITEM,1,0x804c);
    }
    func_021DEFEC((char *)p,p[0x16]); func_021ED55C((char **)p,0);
    return 0x54;
}






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK
#define WORK (*(char **)(p+0x2c))






int func_021E96E8(unsigned char *p)
{
    int next;
    void *mon;
    switch(p[0x13]) {
    case 0: func_021ED164(WORK,p[0x16],0); next=0x39; break;
    case 1:
        func_021EA75C((int)p); func_021ED888(WORK,0);
        func_021ED164(WORK,p[0x16],1); func_021EE364((char **)p,8,0xa); next=0x46; break;
    }
    func_021EA878((BoxObj *)p,*(short *)&((BoxTask *)p)->f10);
    if(ITEM==0) {
        func_021DEFEC((char *)p,p[0x16]); func_021EF4E4(*(struct WinMgr **)(WORK+0x74));
        func_021EBCB4(p,0,0x18);
        if(p[0x13]==0) func_021ECB20((char *)p,0x81,1);
        else { func_021ECB20((char *)p,1,1); func_021ECB20((char *)p,0x82,1); }
        return next;
    }
    if(func_0202136C(ITEM)==0) {
        mon=(void *)func_021DD2D0((void ***)p,p[0x14],p[0x16]);
        func_021DD2B4((int)p,p[0x16],p[0x14],6,ITEM);
        if(func_021DD718((void **)p,mon)==1) {
            func_021DD8A8((void **)p,p[0x16]);
            func_021EC48C(p,p[0x14],p[0x16],*(unsigned char *)(WORK+p[0x16]+0x3dd2));
        }
        func_02007F1C(((struct Obj23949 *)(*(char * *)&((BoxTask *)p)->f0))->fC,ITEM,1,0x804c);
        *(unsigned short *)(WORK+0xa16c)=ITEM;
        func_021ED094(WORK,*(unsigned short *)(WORK+0xa16c));
        func_021EC000(WORK,0xa,1); func_021ED1C8(WORK); func_021ED2F4(WORK);
    }
    if(p[0x13]==0) { func_021ECB20((char *)p,0x81,1); func_021EF670(WORK); }
    else { func_021ECB20((char *)p,1,1); func_021ECB20((char *)p,0x82,1); func_021EF68C(WORK); }
    func_021DEFEC((char *)p,p[0x16]); func_021ED55C((char **)p,0);
    return 0x54;
}





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK
#define WORK (*(char **)(p+0x2c))





int func_021E9848(unsigned char *p)
{
    int next;
    void *mon;
    switch(p[0x13]) {
    case 0: func_021EF670(WORK); next=0x23; break;
    case 1:
        func_021EA75C((int)p); func_021ECB20((char *)p,1,1); func_021ED888(WORK,0);
        func_021EE364((char **)p,0xe,0xb); func_021EF68C(WORK); next=0x27; break;
    }
    func_021ED588((char *)p);
    if(ITEM==0) {
        func_021DEFEC((char *)p,p[0x16]); func_021EB988((unsigned char *)((BoxObj *)p), data_021EF918, 4);
        func_021EF4E4(*(struct WinMgr **)(WORK+0x74)); func_021EBC58(p,p[0x16],1,0x18);
        return next;
    }
    if(func_0202136C(ITEM)==0) {
        mon=(void *)func_021DD2D0((void ***)p,p[0x14],p[0x16]);
        func_021DD2B4((int)p,p[0x16],p[0x14],6,ITEM);
        if(func_021DD718((void **)p,mon)==1) {
            func_021DD8A8((void * *)p, p[0x16]);
            func_021EC48C(p,p[0x14],p[0x16],*(unsigned char *)(WORK+p[0x16]+0x3dd2));
        }
        func_02007F1C(((struct Obj23950 *)(*(char * *)&((BoxTask *)p)->f0))->fC,ITEM,1,0x804c);
    }
    func_021DEFEC((char *)p,p[0x16]); func_021ED55C((char **)p,0);
    return 0x54;
}



#undef MGR


#undef MGR

#undef MGR








#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))




#undef WORK



#undef WORK


#undef WORK

#undef WORK










#define WORK(p) (*(char **)((p)+0x2C))














int func_021E9938(unsigned char *p){func_021EB988((unsigned char *)((BoxObj *)p), d_021EF9B4, 5);func_021EF4E4((struct WinMgr *)(((struct Obj23951 *)(*(unsigned char * *)&((BoxTask *)p)->f2C))->f74));func_021EBC58(p,p[22],1,24);func_021ED588((char *)p);return 44;}














int func_021E9968(unsigned char *p) {
 func_021EB988((unsigned char *)((BoxObj *)p), d_021EF950, 5);
 func_021EF4E4((struct WinMgr *)((int)(*(struct WinMgr **)(WORK(p)+0x74))));
 func_021EBC58(p,p[0x16],1,0x18);
 func_021ECB20((char *)p,1,1); func_021ED888(WORK(p),0);
 func_021EA75C((int)p); func_021ED588((char *)((unsigned char *)((char *)p))); return 0x31;
}













#undef WORK












#undef WORK











#undef WORK










#undef WORK









#undef WORK








#undef WORK







#undef WORK






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK


#define WORK(p) (*(char **)((p) + 0x2C))















/*
 * Leaves a box-menu mode (p[0x13]): restores the windows the mode changed
 * and returns the next menu state.
 */
int func_021E99B0(unsigned char *p)
{
    switch (p[0x13]) {
    case 0:
        func_021EB988((unsigned char *)((BoxObj *)p), d_021EFA10, 6);
        func_021EF4E4((struct WinMgr *)((int)(MGR(p))));
        func_021EBC58(p, p[0x16], 1, 0x18);
        func_021ED588((char *)((unsigned char *)((char *)p)));
        return 0x11;
    case 1:
        func_021EB988((unsigned char *)((BoxObj *)p), d_021EFA10, 6);
        func_021EF4E4((struct WinMgr *)((int)(MGR(p))));
        func_021EBC58(p, p[0x16], 1, 0x18);
        func_021ECB20((char *)p, 1, 1);
        func_021ED888(WORK(p), 0);
        func_021EE364((char **)p, 5, 10);
        func_021EA75C((int)p);
        func_021ED588((char *)((unsigned char *)((char *)p)));
        return 0x1B;
    case 2:
        if (p[0x1B] == 1)
            func_021EC61C(p);
        func_021EE364((char **)p, 4, p[0x16]);
        func_021DD1E8((char *)p);
        while (func_021E01C4((char *)p) != 0)
            ;
        func_021EDF5C(p);
        func_021EF670(WORK(p));
        p[0x16] = 0xFF;
        return 0x15;
    case 3:
        if (p[0x16] >= 0x1E) {
            func_021EC61C(p);
            func_021ECB84(WORK(p), p[0x16]);
        } else if (p[0x14] == p[0x17]) {
            func_021ECB84(WORK(p), p[0x16]);
        } else {
            func_021EC48C(p, p[0x17], p[0x16], HELD_WIN(p));
        }
        func_021E072C(p);
        func_021ED75C((char **)p, 0x24);
        func_021EE364((char **)p, 4, p[0x1D]);
        func_021DD1E8((char *)p);
        while (func_021E01C4((char *)p) != 0)
            ;
        func_021EDF5C(p);
        func_021EF670(WORK(p));
        if (p[0x1D] >= 0x22 && p[0x1D] <= 0x25)
            func_021EE008((char *)p, p[0x1D] - 0x22, 1);
        func_021ED594((char *)p, 0x24);
        return 0x15;
    case 4:
        func_021EA770((int)p);
        func_021EE364((char **)p, 6, p[0x16]);
        func_021EF68C(WORK(p));
        p[0x16] = 0xFF;
        return 0x20;
    case 5:
        func_021EA770((int)p);
        if (p[0x16] < 0x1E && p[0x14] != p[0x17])
            func_021EC48C(p, p[0x17], p[0x16], HELD_WIN(p));
        else
            func_021ECB84(WORK(p), p[0x16]);
        func_021E072C(p);
        func_021ED75C((char **)p, 0x24);
        func_021EE364((char **)p, 6, p[0x1D]);
        func_021EF68C(WORK(p));
        func_021ED594((char *)p, 0x24);
        return 0x20;
    }
    return 0;
}














#undef WORK













#undef WORK












#undef WORK











#undef WORK










#undef WORK









#undef WORK








#undef WORK







#undef WORK






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK
#define WORK (*(char **)(p+0x2c))














int func_021E9B74(unsigned char *p)
{
    switch(p[0x13]) {
    case 0:
        func_021EB988((unsigned char *)((BoxObj *)p), data_021EF918, 4);
        func_021EF4E4((struct WinMgr *)((int)(*(struct WinMgr **)(WORK+0x74)))); func_021EBC58(p,p[0x16],1,0x18);
        func_021EE364((char **)p,0xd,0x25); func_021ED588((char *)((unsigned char *)((char *)p))); return 0x23;
    case 1:
        func_021EB988((unsigned char *)((BoxObj *)p), data_021EF918, 4);
        func_021EF4E4((struct WinMgr *)((int)(*(struct WinMgr **)(WORK+0x74)))); func_021EBC58(p,p[0x16],1,0x18);
        func_021ECB20((char *)p,1,1); func_021ED888(WORK,0);
        func_021EE364((char **)p,0xe,0xa); func_021EA75C((int)p); func_021ED588((char *)((unsigned char *)((char *)p))); return 0x27;
    case 4:
        func_021EA770((int)p); func_021EE364((char **)p,6,p[0x16]);
        func_02026124(*(void **)(WORK+0x70),0x27);
        p[0x16]=0xff; return 0x20;
    case 5:
        func_021EA770((int)p);
        if(p[0x16]<0x1e && p[0x14]!=p[0x17])
            func_021EC48C(p,p[0x17],p[0x16],*(unsigned char *)(WORK+0x3df6));
        else func_021ECB84(WORK,p[0x16]);
        func_021E072C(p); func_021ED75C((char **)p,0x24);
        func_021EE364((char **)p,6,p[0x1d]); func_02026124(*(void **)(WORK+0x70),0x27);
        func_021ED594((char *)p,0x24); return 0x20;
    }
    return 0;
}














#undef WORK













#undef WORK












#undef WORK











#undef WORK










#undef WORK









#undef WORK








#undef WORK







#undef WORK






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))















int func_021E9C94(char *p, int a, int n)
{
    func_021DD16C((unsigned char *)p, 0);
    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 1) {
        func_021EF57C(*(struct WinMgr **)(WORK(p) + 0x74));
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C(p);
        if (a == 1)
            func_021EF670(WORK(p));
    }
    return func_021E8FC0(p, (int)func_021E00C4, n);
}












#undef WORK











#undef WORK










#undef WORK









#undef WORK








#undef WORK







#undef WORK






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))














int func_021E9CE0(char *p, int a, int n)
{
    func_021DD16C((unsigned char *)p, 1);
    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 1) {
        func_021EF57C(*(struct WinMgr **)(WORK(p) + 0x74));
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C(p);
        if (a == 1)
            func_021EF670(WORK(p));
    }
    return func_021E8FC0(p, (int)func_021E0128, n);
}














int func_021E9D2C(BoxObj *p, int i)
{
    p->b1B = 0;
    p->lo = 0;
    p->b16 = i;
    p->b17 = p->b14;
    func_021EC768(p->work, p->b16, 0);
    func_021ECB84(p->work, p->b16);
    func_021ED594((char *)p, 0x24);
    func_021EA1C0(p);
    func_021EE038((char *)p, 2, 2, 1);
    func_021EBA5C(p->work, 0x18);
    func_021DD14C((char *)p);
    func_021EF670(p->work);
    p->x28 = 0x15;
    p->b1A = 0;
    return func_021E8FC0((char *)p, (int)func_021DFA30, 0x12);
}














int func_021E9D98(BoxObj *p, int i)
{
    p->b16 = i;
    p->b17 = p->b14;
    p->b1B = 0;
    func_021EC768(p->work, p->b16, 0);
    func_021ECB84(p->work, p->b16);
    func_021ED594((char *)p, 0x24);
    func_021EA1C0(p);
    func_021EE038((char *)p, 2, 2, 1);
    func_021EBA5C(p->work, 0x18);
    func_021DD14C((char *)p);
    p->b1A = 0;
    p->x28 = 0x20;
    return func_021E8FC0((char *)p, (int)func_021E1B1C, 0x24);
}














int func_021E9DF8(u8 *p, int a)
{
    u8 old = ((BoxTask *)p)->f14;
    ((BoxTask *)p)->f16 = a;
    ((BoxTask *)p)->f17 = old;
    func_021EC768((char *)(*(u32 *)&((BoxTask *)p)->f2C), ((BoxTask *)p)->f16, 0);
    func_021ECB84((char *)(*(u32 *)&((BoxTask *)p)->f2C), ((BoxTask *)p)->f16);
    func_021ED594((char *)p, 0x24);
    func_021ED888((char *)(*(u32 *)&((BoxTask *)p)->f2C), 0);
    func_021EC61C(p);
    func_021ECB20((char *)p, 1, 1);
    func_021ECB20((char *)p, 2, 1);
    func_021ECB60((char *)(*(u32 *)&((BoxTask *)p)->f2C), 0x24, 0);
    func_021EA1C0(p);
    func_021EE038((char *)p, 2, 2, 1);
    func_021EBA5C((char *)(*(u32 *)&((BoxTask *)p)->f2C), 0x18);
    func_021DD14C((char *)p);
    ((BoxTask *)p)->f1A = 2;
    return func_021E8FC0((char *)p, (int)((void (*)(void))func_021E0470), 0x30);
}














int func_021E9E7C(char *p, int i, int v)
{
    p[0x16] = i;
    *(unsigned char *)(WORK(p) + 0xA172) = 1;
    func_021EC768(WORK(p), (unsigned char)p[0x16], 1);
    func_021ED588((char *)((unsigned char *)p));
    func_021EF534(*(struct WinMgr **)(WORK(p) + 0x74));
    return func_021E8FC0(p, (int)func_021E070C, func_021E8FE0(p, v));
}














int func_021E9EC0(unsigned char *p, int i)
{
    p[0x16] = i;
    ((Nib_021E65E4 *)(p + 0x1C))->lo = 0;
    p[0x17] = p[0x14];
    p[0x1B] = 1;
    func_021EC768(WORK(p), p[0x16], 0);
    func_021ECB84(WORK(p), p[0x16]);
    func_021ED594((char *)p, 0x24);
    func_0201AB28(((struct Obj23952 *)(*(char * *)&((BoxTask *)p)->f0))->f8, i - 0x1E);
    func_021EA1C0(p);
    func_021EE038((char *)p, 2, 2, 1);
    func_021EBA5C(WORK(p), 0x18);
    func_021DD14C((char *)p);
    func_021EF68C(WORK(p));
    ((BoxTask *)p)->f28 = 0x20;
    p[0x1A] = 1;
    return func_021E8FC0((char *)p, (int)func_021DF484, 0x1E);
}














int func_021E9F3C(unsigned char *p, int i)
{
    p[0x17] = p[0x14];
    p[0x16] = i;
    p[0x1B] = 1;
    func_021EC768(WORK(p), p[0x16], 0);
    func_021ECB84(WORK(p), p[0x16]);
    func_021ED594((char *)p, 0x24);
    func_0201AB28(((struct Obj23953 *)(*(char * *)&((BoxTask *)p)->f0))->f8, i - 0x1E);
    func_021EA1C0(p);
    func_021EE038((char *)p, 2, 2, 1);
    func_021EBA5C(WORK(p), 0x18);
    func_021DD14C((char *)p);
    ((BoxTask *)p)->f28 = 0x20;
    p[0x1A] = 1;
    return func_021E8FC0((char *)p, (int)func_021DF484, 0x2A);
}














int func_021E9FA8(unsigned char *p, int i)
{
    p[0x16] = i;
    func_021EC768(WORK(p), p[0x16], 0);
    func_021ECB84(WORK(p), p[0x16]);
    func_021ED594((char *)p, 0x24);
    func_021ECB20((char *)p, 2, 1);
    func_021ECB60(WORK(p), 0x24, 0);
    func_0201AB28(((struct Obj23954 *)(*(char * *)&((BoxTask *)p)->f0))->f8, i - 0x1E);
    func_021EA1C0(p);
    func_021EE038((char *)p, 2, 2, 1);
    func_021EBA5C(WORK(p), 0x18);
    func_021DD14C((char *)p);
    p[0x1A] = 1;
    return func_021E8FC0((char *)p, (int)func_021E0200, 0x38);
}














int func_021EA020(char *p, int i, int v)
{
    p[0x16] = i;
    *(unsigned char *)(WORK(p) + 0xA172) = 1;
    func_021EC768(WORK(p), (unsigned char)p[0x16], 1);
    func_021ED588((char *)((unsigned char *)p));
    func_021EF534(*(struct WinMgr **)(WORK(p) + 0x74));
    return func_021E8FC0(p, (int)func_021E070C, func_021E8FE0(p, v));
}














int func_021EA064(unsigned char *p, int i, int v)
{
    p[0x17] = p[0x14];
    p[0x16] = i;
    *(int *)(WORK(p) + 0xA168) = i;
    func_021ECB84(WORK(p), p[0x16]);
    func_021EC768(WORK(p), 0x24, 0);
    func_021ED594((char *)p, 0x24);
    func_021EE038((char *)p, 2, 1, 2);
    func_021EA1C0(p);
    ((BoxTask *)p)->f28 = v;
    p[0x1A] = 2;
    return func_021E8FC0((char *)p, (int)func_021DFA30, 0x17);
}











#undef WORK










#undef WORK









#undef WORK








#undef WORK







#undef WORK






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))













int func_021EA0BC(unsigned char *p, unsigned char i)
{
    p[0x18] = 1;
    p[0x16] = i;
    func_021EC768(WORK(p), 0x24, 0);
    func_021ED594((char *)p, 0x24);
    func_021EE038((char *)p, 2, 1, 0);
    if ((*(BoxTop * *)&((BoxTask *)p)->f0)->x24 == 4) {
        func_021EF680(WORK(p));
        func_021EF69C(WORK(p));
        func_02026124(*(void **)(WORK(p) + 0x70), 0x27);
    }
    return func_021E8FC0((char *)p, (int)func_021E0778, 0x20);
}












/*
 * Arm the flag, store the state byte, zero the 0x24 queue entry,
 *   re-stage it, publish (2,1,0) and set selector 0x021E0779.
 */
int func_021EA114(char *p, int a)
{
    ((BoxTask *)p)->f18 = 1;
    ((BoxTask *)p)->f16 = a;
    func_021EC768((char *)(*(int *)&((BoxTask *)p)->f2C), 0x24, 0);
    func_021ED594(p, 0x24);
    func_021EE038(p, 2, 1, 0);
    return func_021E8FC0(p, 0x021E0779, 0x15);
}













int func_021EA14C(unsigned char *p, unsigned i, int v)
{
    if (i >= 0x1E && i >= 0x24 && i != 0xFF) {
        unsigned k = p[0x19] + i - 0x24;
        if (k >= p[0x15])
            k -= p[0x15];
        if (k == p[0x14]) {
            func_020061E4(0x557);
            return 0x15;
        }
        if (func_020077B8((*(BoxTop * *)&((BoxTask *)p)->f0)->x4, k) == 0) {
            func_020061E4(0x557);
            return 0x15;
        }
    }
    ((struct Obj23957 *)(*(char * *)&((BoxTask *)p)->f2C))->fA17E = i;
    p[0x1A] = 2;
    ((BoxTask *)p)->f28 = v;
    func_021EA1C0(p);
    return func_021E8FC0((char *)p, (int)func_021E087C, 0x17);
}














/*
 * Allocate (0x4c, 0xb8, 1) into the 0x021F140C buffer and store
 * the handle at sub-object +0x60.
 */
void func_021EA1C0(void *p)
{
    int v = (int)func_02030734(0x4c, 0xb8, 1, (const char *)0x021F140C, 0x2130);
    *(int *)(((struct Obj18479 *)p)->f2C + 0x60) = v;
}













/*
 * Tail call func_020307B0 with the word at +0x2c/+0x60.
 */
void func_021EA1E8(char *p)
{
    func_020307B0(((struct Obj18480 *)(*(char * *)&((BoxTask *)p)->f2C))->f60);
}










#undef MGR









#undef MGR








#undef MGR







#undef MGR






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))












int func_021EA1F4(BoxObj *p, int i)
{
    short t[2];
    p->b16 = i;
    p->b17 = p->b14;
    p->work[0xA172] = 1;
    CNT(p) = func_021DD25C((void ***)p, p->b16, p->b14, 6, 0);
    func_021EF508(MGR(p));
    func_021EBA5C(p->work, 0x18);
    func_021DD14C((char *)p);
    if (CNT(p) != 0) {
        func_021EC000(p->work, 10, 0);
        func_021ED164(p->work, p->b16, 0);
        func_021ED094(p->work, CNT(p));
        func_021ED1C8(p->work);
        func_021EE038((char *)p, 2, 2, 1);
    } else if (func_021EC01C(p->work, 10) == 1) {
        func_021EC000(p->work, 10, 0);
        func_021ED6E4((char **)p, 0);
    }
    func_021EC548(p->b16, &t[1], &t[0], 0);
    *(int *)(p->work + 0xA180) = t[1] + 8;
    *(int *)(p->work + 0xA184) = t[0] + 8;
    func_021EA728(p);
    return func_021E8FC0((char *)p, (int)func_021E0ABC, func_021E8FE0((char *)p, 0x3E));
}












int func_021EA2DC(BoxObj *p, int i)
{
    p->b16 = i;
    p->b17 = p->b14;
    p->work[0xA172] = 1;
    func_021DEFEC((char *)p, p->b16);
    CNT(p) = func_021DD25C((void ***)p, p->b16, p->b14, 6, 0);
    func_021EA878((BoxObj *)p, (short)CNT(p));
    func_021EF534(MGR(p));
    if (CNT(p) != 0) {
        func_021EC000(p->work, 10, 0);
        func_021ED164(p->work, p->b16, 0);
        func_021ED094(p->work, CNT(p));
        func_021ED1C8(p->work);
        func_021EEF74(p->work, 0x24, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), 0x24);
    } else {
        func_021EEF74(p->work, 0x25, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), 0x25);
    }
    return func_021E8FC0((char *)p, (int)func_021E0A40, func_021E8FE0((char *)p, 0x39));
}









#undef MGR








#undef MGR







#undef MGR






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))











int func_021EA39C(BoxObj *p, unsigned i)
{
    short t[2];
    p->b16 = i;
    p->b17 = i < 0x1E ? p->b14 : 0xFF;
    CNT(p) = func_021DD25C((void ***)p, p->b16, p->b14, 6, 0);
    if (CNT(p) == 0) {
        func_020260E4(OBJ(p), p->b16);
        return 0x40;
    }
    func_020061E4(0x666);
    func_021EC000(p->work, 10, 0);
    func_021ED164(p->work, p->b16, 2);
    func_021ED094(p->work, CNT(p));
    func_021ED1C8(p->work);
    func_021EE038((char *)p, 2, 1, 1);
    func_021EC548(p->b16, &t[1], &t[0], 2);
    *(int *)(p->work + 0xA180) = t[1] + 8;
    *(int *)(p->work + 0xA184) = t[0] + 8;
    func_021EA728(p);
    return func_021E8FC0((char *)p, (int)func_021E0FD8, 0x42);
}











int func_021EA458(BoxObj *p, unsigned i)
{
    p->b16 = i;
    *(unsigned short *)(p->work + 0xA16E) = i;
    p->b17 = i < 0x1E ? p->b14 : 0xFF;
    CNT(p) = func_021DD25C((void ***)p, p->b16, p->b14, 6, 0);
    if (CNT(p) == 0)
        return 0x40;
    p->b18 = 1;
    func_021EC000(p->work, 10, 0);
    func_021ED198(p->work, p->b16, 2);
    func_021ED094(p->work, CNT(p));
    func_021EE038((char *)p, 2, 1, 1);
    return func_021E8FC0((char *)p, (int)func_021E1324, 0x40);
}











int func_021EA4DC(BoxObj *p)
{
    unsigned char v = func_020260E0(OBJ(p));
    if (v < 0x24)
        func_021DEFEC((char *)p, v);
    else
        func_021DF040((char *)p);
    func_021EA728(p);
    return func_021E8FC0((char *)p, (int)func_021E152C, 0x43);
}








#undef MGR







#undef MGR






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))










int func_021EA514(BoxObj *p, unsigned i)
{
    short t[2];
    SEL(p) = i;
    p->b18 = 0;
    func_021EC0B0(p->work, 4, &t[1], &t[0], 0);
    func_021EC08C(p->work, 10, (short)t[1], (short)(t[0] + 8), (short)0);
    func_021ED6E4((char **)p, 0);
    if (SEL(p) == 0xFF)
        return func_021EA4DC((BoxObj *)p);
    if (func_021DDE80((unsigned char *)p, p->b16, i) == 0)
        return func_021EA4DC((BoxObj *)p);
    return func_021E8FC0((char *)p, (int)func_021E1458, 0x45);
}










int func_021EA598(BoxObj *p, int i)
{
    short t[2];
    p->b16 = i;
    p->b17 = 0xFF;
    CNT(p) = func_021DD25C((void ***)p, p->b16, p->b14, 6, 0);
    func_021EF508(MGR(p));
    func_021EBA5C(p->work, 0x18);
    func_021DD14C((char *)p);
    if (CNT(p) != 0) {
        func_021EC000(p->work, 10, 0);
        func_021ED164(p->work, p->b16, 1);
        func_021ED094(p->work, CNT(p));
        func_021ED1C8(p->work);
        func_021EE038((char *)p, 2, 2, 1);
    } else if (func_021EC01C(p->work, 10) == 1) {
        func_021EC000(p->work, 10, 0);
        func_021ED6E4((char **)p, 0);
    }
    func_021EC548(p->b16, &t[1], &t[0], 1);
    *(int *)(p->work + 0xA180) = t[1] + 8;
    *(int *)(p->work + 0xA184) = t[0] + 8;
    func_021EA728(p);
    return func_021E8FC0((char *)p, (int)func_021E1628, 0x48);
}







#undef MGR






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)((p)->work + 0x74))









int func_021EA66C(BoxObj *p, int i)
{
    p->b16 = i;
    p->b17 = p->b14;
    p->work[0xA172] = 1;
    func_021DEFEC((char *)p, p->b16);
    CNT(p) = func_021DD25C((void ***)p, p->b16, p->b14, 6, 0);
    func_021EA878((BoxObj *)p, (short)CNT(p));
    func_021EF534(MGR(p));
    if (CNT(p) != 0) {
        func_021EC000(p->work, 10, 0);
        func_021ED164(p->work, p->b16, 1);
        func_021ED094(p->work, CNT(p));
        func_021ED1C8(p->work);
        func_021EEF74(p->work, 9, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), 9);
    } else {
        func_021EEF74(p->work, 10, func_020260E0(OBJ(p)));
        func_020260E4(OBJ(p), 10);
    }
    return func_021E8FC0((char *)p, (int)func_021E0A40, func_021E8FE0((char *)p, 0x46));
}










/*
 * Sibling of func_021EA1C0 with (0x1c, 0) and the 0x228F buffer.
 */
void func_021EA728(void *p)
{
    int v = (int)func_02030734(0x4c, 0x1c, 0, (const char *)0x021F140C, 0x228F);
    *(int *)(((struct Obj18488 *)p)->f2C + 0x60) = v;
}









void func_021EA750(char *p)
{
    func_020307B0(((struct Obj18489 *)(*(char * *)&((BoxTask *)p)->f2C))->f60);
}






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))







/*
 * Stop one 0x74 sub-object, then the plain stop.
 */
void func_021EA75C(int p)
{
    func_021EF32C(*(struct WinMgr **)(((struct Obj18491 *)p)->f2C + 0x74));
    func_021EC688((char *)p);
}







/*
 * Resume one 0x74 sub-object, then the plain resume.
 */
void func_021EA770(int p)
{
    func_021EF33C(*(struct WinMgr **)(((struct Obj18493 *)p)->f2C + 0x74));
    func_021EC6F4((char *)p);
}







/*
 * Plain stop, then stop the 0x74 sub-object.
 */
void func_021EA784(int p)
{
    func_021EC688((char *)p);
    func_021EF32C(*(struct WinMgr **)(((struct Obj18495 *)p)->f2C + 0x74));
}








int func_021EA798(unsigned char *p, int sel)
{
    int (*cb)(unsigned char *);
    int r = func_021DD210(p, p[0x14], *(unsigned char *)(WORK(p) + 0xA17F));
    p[0x14] = *(unsigned char *)(WORK(p) + 0xA17F);
    func_021EC35C((char **)p, p[0x14]);
    func_021DEC98((char *)p, (void *)func_021DEDCC((char *)p, p[0x14]), r);
    if (r == 1)
        cb = (int (*)(unsigned char *))func_021E0128;
    else
        cb = (int (*)(unsigned char *))func_021E00C4;
    switch (sel) {
    case 0:
        ((BoxTask *)p)->f28 = 0x15;
        break;
    case 1:
        ((BoxTask *)p)->f28 = 0x63;
        break;
    }
    func_020061E4(0x548);
    return func_021E8FC0((char *)p, (int)cb, ((BoxTask *)p)->f28);
}








void func_021EA808(char *p)
{
    unsigned short *q = func_02030734(0x804C, 4, 0, d_021F140C, 0x2305);
    q[0] = 0;
    q[1] = 0;
    *(unsigned short * *)&((struct Obj23958 *)(*(char * *)&((BoxTask *)p)->f2C))->fA190 = q;
}





/*
 * Reset the entry then store the field with the dispatcher
 *   thumb-pointer 0x021E01C5 as its second argument.
 */
int func_021EA83C(char *p, int a)
{
    func_021DD1E8(p);
    return func_021E8FC0(p, 0x021E01C5, a);
}

#undef OBJ

#define OBJ(p) (*(void **)((p)->work + 0x70))

#undef W
#define W(p) (*(char **)((p)+44))

#undef SLOT


#define SLOT(p,o) (*(void **)((p)+(o)))

#undef MGR









#define MGR(p) (*(struct WinMgr **)(*(char **)((char *)(p) + 0x2C) + 0x74))

#undef WORK










#define WORK(p) (*(char **)((p)+0x2C))















/*
 * Same forward as func_021EA83C but after restarting the queue.
 */
int func_021EA858(char *p, int a)
{
    func_021EF75C(*(struct WinMgr **)(*(int *)&((BoxTask *)p)->f2C + 0x74));
    return func_021E8FC0(p, 0x021E01E1, a);
}

















void func_021EA878(BoxObj *p, int v)
{
    if (v != 0) {
        if (p->b16 < 0x1E)
            func_0202614C(OBJ(p), 0x24);
        else
            func_0202614C(OBJ(p), 9);
        func_021EB988((unsigned char *)p, d_021EF8FC, 3);
    } else {
        if (p->b16 < 0x1E)
            func_02026124(OBJ(p), 0x24);
        else
            func_02026124(OBJ(p), 9);
        func_021EB988((unsigned char *)p, d_021EF8F4, 2);
    }
}
















/*
 * Busy 1 for the 0x16 field below 0x1e, else run the panel query and
 *   answer 2 for a hit, 0 otherwise.  `p` must be unsigned char *
 *   (ldrb, not ldrsb) and the result must be the CONSTANTS 1/2/0 with
 *   an early return -- an `int r = 0; ... return r;` keeps r live from
 *   the top, which pushes i from r4 to r6 and widens the push set.
 */
int func_021EA8CC(unsigned char *p)
{
    int i = p[0x16] - 0x1e;
    if (func_021DD694((void ***)p, i) == 0)
        return 1;
    if (func_0202136C((unsigned short)func_02017E1C(
            func_0201AB28(*(void **)(((struct Obj12168 *)p)->f0 + 8), i), 6, 0)) == 1)
        return 2;
    return 0;
}
















/*
 * candidate func_021EA908: xor bit
 */
void func_021EA908(int p, int bit)
{
    *(int *)(*(int *)&((BoxTask *)p)->f2C + 0xA174) ^= 1 << bit;
    func_021DF110((char *)p, *(int *)(*(int *)&((BoxTask *)p)->f2C + 0xA174));
}















int func_021EA928(unsigned char *p,int a) {
 if((unsigned char)WORK(p)[0xA17C]<=4 || ((unsigned char)WORK(p)[0xA17C]==5 && func_02007A80(((struct Obj23959 *)(*(char * *)&((BoxTask *)p)->f0))->f4,2)==0))
  WORK(p)[0xA17B]=((unsigned char)WORK(p)[0xA17C]-1)*4+a-1;
 else WORK(p)[0xA17B]=((unsigned char)WORK(p)[0xA17C]-1)*4+a;
 return func_021E949C((char *)p,a,func_021E8F50((char *)p,0x66));
}















void func_021EA984(unsigned char *p) {
 switch(((struct Obj23961 *)(*(char * *)&((BoxTask *)p)->f0))->f24) {
 case 0: func_021ECB20((char *)p,2,1); return;
 case 1: case 3: func_021ED888(WORK(p),0); func_021ECB20((char *)p,1,1); return;
 case 2: case 4: case 5:
  func_021ED888(WORK(p),0);
  if(func_021EF480(*(struct WinMgr **)(WORK(p)+0x74))==1) {
   func_021ECB20((char *)p,2,1); return;
  } else { func_021ECB20((char *)p,1,1); return; }
 }
}
















int func_021EA9F4(BoxObj *p, int v)
{
    func_020061E4(0x54C);
    if (func_021EF5E8(MGR(p)) == 1)
        p->lo = 2;
    else
        p->lo = 1;
    p->hi = 0;
    func_021DD238((char *)p);
    return func_021E8F50((char *)p, v);
}
















int func_021EAA3C(BoxObj *p, int v)
{
    func_020061E4(0x54C);
    if (func_021EF5E8(MGR(p)) == 1)
        p->lo = 2;
    else
        p->lo = 1;
    p->hi = 0;
    return func_021E8F50((char *)p, v);
}















void func_021EAA80(unsigned char *p) {
 const unsigned char *x; unsigned i;
 func_02045088(0x4C);
 x=d_021EFC20;
 for(i=0;i<28;i++,x+=6)
  *(void **)(WORK(p)+0x94+i*8)=(void *)func_020450F0(x[0],x[1],x[2],x[3],x[4],x[5],1);
}














/*
 * Walk 0x1c 8-byte records at p+0x2c+0x94, release each, then
 *   release the pool.  Unsigned counter for the image's blo.
 */
void func_021EAAC4(char *p)
{
    unsigned i;
    for (i = 0; i < 0x1c; i++)
        func_020452E8((struct Descriptor *)(*(int *)(((struct Obj18507 *)p)->f2C + i * 8 + 0x94)));
    func_020450C8();
}














/*
 * Set bit i of the 0x174-byte bitmap hung off p.
 *   Unsigned index, or mwccarm emits asr instead of the image's lsr.
 */
void func_021EAAE4(unsigned char *p, unsigned i)
{
    unsigned char *q = p + 0x174;
    q[i >> 3] |= (unsigned char)(1 << (i & 7));
}














void func_021EAB04(unsigned char *w) {
 unsigned i; unsigned char mask; unsigned char index;
 for(i=0;i<28;i++) {
  if(*(void **)(w+0x94+i*8)!=0) {
   mask=1<<(i&7); index=i>>3;
   if(w[0x174+index]&mask) {
    func_02045334(*(void **)(w+0x94+i*8));
    w[0x174+index]^=mask;
   }
  }
 }
}














void func_021EAB50(unsigned char *w) {
 unsigned i; void *print;
 func_0201C4E4(((struct Obj08242 *)w)->f8C);
 for(i=0;i<28;i++) {
  print=((struct Obj08242 *)w)->f8C;
  if(w[0x98+i*8]) {
   if(func_0201C6C4(print,func_02045770(*(void **)(w+i*8+0x94)))==0) {
    func_02045334(*(void **)(w+i*8+0x94));
    w[0x98+i*8]=0;
   }
  }
 }
}















/*
 * Release both children of the object and then a global one.
 */
void func_021EABA0(void **p)
{
    func_02045374(*p);
    func_02041B6C(func_02045730(*p));
}















void func_021EABB8(void **p)
{
    func_020456F8(*p);
    func_02041B6C(func_02045730(*p));
}














void func_021EABD0(unsigned char *w,int i,void *bank,unsigned idx,int x,int y,unsigned font,unsigned short color) {
 void *s; unsigned print;
 s=func_02045EC0(bank,idx);
 print=((struct Obj23962 *)w)->f8C;
 func_0201C724((void *)print,(u32)func_02045770(*(void **)(w+0x94+i*8)),(short)x,(short)y,(u32)s,font,color);
 *(w+i*8+0x98)=1;
 func_02045808(s);
}















/*
 * Expands message idx of bank into the work string buffer and prints it into
 * message window i; marks the window dirty.
 */
void func_021EAC28(char *w, int i, void *bank, u32 idx, int x, int y, u32 font, u16 color)
{
    u32 print;
    void *s;
    s = func_02045EC0(bank, idx);
    func_0201F250(((struct Obj00414 *)w)->f84, (void *)(*(u32 *)&((struct Obj00414 *)w)->f88), s);
    print = ((struct Obj00414 *)w)->f8C;
    func_0201C724((void *)print, (u32)func_02045770(*(void **)(w + i * 8 + 0x94)), (short)x, (short)y, *(u32 *)&((struct Obj00414 *)w)->f88, font, color);
    *(unsigned char *)(w + i * 8 + 0x98) = 1;
    func_02045808(s);
}















/*
 * Call func_02045B38 with fixed arguments.
 */
void *func_021EAC98(void)
{
    return func_02045B38(0, 2, 0xa, 0x4c);
}














void func_021EACA8(unsigned char *p) {
 unsigned char *w; void *bank;
 w=(unsigned char *)WORK(p);
 func_02043B5C(func_02045770(((BoxWork *)w)->f94),0);
 bank=func_021EAC98();
 func_021EABD0(w,0,bank,((struct Obj23964 *)(*(char * *)&((BoxTask *)p)->f0))->f24+0x25,0,8,((BoxWork *)w)->f78,0x440);
 func_02045C04(bank);
 func_021EABA0((void **)(WORK(p)+0x94));
}














void func_021EACFC(u8 *p)
{
    u8 *q = *(u8 * *)&((BoxTask *)p)->f2C;

    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((BoxWork *)q)->fE4)), 0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((BoxWork *)q)->fEC)), 0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((BoxWork *)q)->fF4)), 0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((BoxWork *)q)->fFC)), 0);
    func_021EABD0(q, 0xa, (void *)(((struct Obj02053 *)q)->f80), 0x6d, 0, 0, ((BoxWork *)q)->f78, 0x440);
    func_021EABD0(q, 0xb, (void *)(((struct Obj02053 *)q)->f80), 0x64, 0, 0, ((BoxWork *)q)->f78, 0x440);
    func_021EABD0(q, 0xc, (void *)(((struct Obj02053 *)q)->f80), 0x65, 0, 0, ((BoxWork *)q)->f78, 0x440);
    func_021EABD0(q, 0xd, (void *)(((struct Obj02053 *)q)->f80), 0x66, 0, 0, ((BoxWork *)q)->f78, 0x440);
}













void func_021EADB4(unsigned char *w,Entry_021EADB4 *e,unsigned i) {
 void **windows;
 windows=(void **)(w+0x94);
 func_02043B5C(func_02045770(windows[i*2]),0);
 if(!e->flag) {
  func_0201EEA4(((struct Obj00414 *)w)->f84,0,(void *)e->value);
  func_021EAC28((char *)w,i,((struct Obj00414 *)w)->f80,0,0,0,((struct Obj00414 *)w)->f78,0x440);
 } else { func_021EAAE4(w,i); return; }
 func_021EABA0(windows+i*2);
}













void func_021EAE20(char *p, void **q, int i)
{
    func_02043B5C(func_02045770(*(void **)(p + 0x94 + i * 8)), 0);
    func_0201EF14(((BoxWork *)p)->f84, 0, *q);
    func_021EAC28(p, i, ((BoxWork *)p)->f80, 1, 0, 0, ((BoxWork *)p)->f78, 0x440);
    func_021EABA0((void **)(p + 0x94 + i * 8));
}













void func_021EAE74(char *p, Entry_021EAE74 *e, unsigned i)
{
    unsigned n;
    func_02043B5C(func_02045770(*(void **)(p + 0x94 + i * 8)), 0);
    if (!e->flag) {
        func_021EAC28(p, i, ((BoxWork *)p)->f80, 107, 0, 0, ((BoxWork *)p)->f78, 0x440);
        n = func_0201D304(((BoxWork *)p)->f88, ((BoxWork *)p)->f78, 0);
        func_0201EFA4(((BoxWork *)p)->f84, 0, e->low, 3, 0, 1);
        func_021EAC28(p, i, ((BoxWork *)p)->f80, 103, n, 0, ((BoxWork *)p)->f78, 0x440);
    } else {
        func_021EAAE4((unsigned char *)p, i); return;
    }
    func_021EABA0((void **)(p + 0x94 + i * 8));
}













/*
 * trailing: two-byte zero alignment padding at 0x021EAFBA.
 */
void func_021EAF20(char *p, Entry_021EAF20 *e, unsigned i)
{
    func_02043B5C(func_02045770(*(void **)(p + 0x94 + i * 8)), 0);
    if (!e->flag && e->enabled == 1) {
        if (e->kind == 0) {
            func_021EABD0((unsigned char *)p, i, ((BoxWork *)p)->f80, 95, 0, 0, ((BoxWork *)p)->f78, 0x14c0);
        } else if (e->kind == 1) {
            func_021EABD0((unsigned char *)p, i, ((BoxWork *)p)->f80, 96, 0, 0, ((BoxWork *)p)->f78, 0xc80);
        } else {
            func_021EAAE4((unsigned char *)p, i); return;
        }
    } else {
        func_021EAAE4((unsigned char *)p, i); return;
    }
    func_021EABA0((void **)(p + 0x94 + i * 8));
}













void func_021EAFBC(char *p,const Entry_021EAFBC *e,u32 i)
{
    u16 n;
    u32 text;
    func_02043B5C(func_02045770(*(void **)(W(p)+i*8+148)),0);
    if (e->high == 0) {
        if (*(u32 *)(W(p)+380) == 1)
            n = ((struct Obj06549 *)e)->f4;
        else
            n = *(u16 *)(*(char **)(W(p)+384)+((struct Obj06549 *)e)->f4*2);
        if (n != 999) {
            func_021EAC28(W(p),i,*(void **)(W(p)+128),108,0,0,*(u32 *)(W(p)+120),1088);
            text=func_0201D304(*(void **)(W(p)+136),*(u32 *)(W(p)+120),0);
            func_0201EFA4(*(void **)(W(p)+132),0,n,3,2,1);
            func_021EAC28(W(p),i,*(void **)(W(p)+128),104,text,0,*(u32 *)(W(p)+120),1088);
        } else { func_021EAAE4((unsigned char *)W(p),i); return; }
    } else { func_021EAAE4((unsigned char *)W(p),i); return; }
    func_021EABA0((void **)(W(p)+148+i*8));
}













void func_021EB098(char *p, unsigned char *e, int i)
{
    func_02043B5C(func_02045770(*(void **)(p + 0x94 + i * 8)), 0);
    if (!((Entry_021EB098 *)e)->flag) {
        func_0201EF98(((BoxWork *)p)->f84, 0, e[15]);
        func_021EAC28(p, i, ((BoxWork *)p)->f80, 98, 0, 0, ((BoxWork *)p)->f78, 0x440);
    } else {
        func_021EABD0((unsigned char *)p, i, ((BoxWork *)p)->f80, 106, 0, 0, ((BoxWork *)p)->f78, 0x440);
    }
    func_021EABA0((void **)(p + 0x94 + i * 8));
}













void func_021EB114(char *p, unsigned char *e, int i)
{
    func_02043B5C(func_02045770(*(void **)(p + 0x94 + i * 8)), 0);
    if (!((Entry_021EB114 *)e)->flag) {
        func_0201EF8C(((BoxWork *)p)->f84, 0, e[14]);
        func_021EAC28(p, i, ((BoxWork *)p)->f80, 97, 0, 0, ((BoxWork *)p)->f78, 0x440);
    } else {
        func_021EABD0((unsigned char *)p, i, ((BoxWork *)p)->f80, 106, 0, 0, ((BoxWork *)p)->f78, 0x440);
    }
    func_021EABA0((void **)(p + 0x94 + i * 8));
}













void func_021EB190(char *p, unsigned char *e, int i)
{
    func_02043B5C(func_02045770(*(void **)(p + 0x94 + i * 8)), 0);
    if (((struct Obj06549 *)e)->f6 != 0) {
        func_0201EF40(((BoxWork *)p)->f84, 0, ((struct Obj06549 *)e)->f6);
        func_021EAC28(p, i, ((BoxWork *)p)->f80, 99, 0, 0, ((BoxWork *)p)->f78, 0x440);
    } else {
        func_021EABD0((unsigned char *)p, i, ((BoxWork *)p)->f80, 105, 0, 0, ((BoxWork *)p)->f78, 0x440);
    }
    func_021EABA0((void **)(p + 0x94 + i * 8));
}













/*
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`windows = (void **)p;` before `windows = (void **)(p + 0x94);`). Game
 * code has no line table, so these were stand-ins. The plain single
 * assignment gives EXACT in --lang c99 and --lang c: the output bytes do not
 * change. Older text in this header that asks for the double assignment is
 * superseded.
 */
void func_021EB208(char *p, Entry_021EB208 *e, int i)
{
    void **windows;
    unsigned j;
    void *bank;
    windows = (void **)(p + 0x94);
    func_02043B5C(func_02045770(windows[i * 2]), 0);
    j = 0;
    bank = func_02045B38(0, 2, 203, 0x804c);
    if (!e->flag) {
        for (; j < 4; j++) {
            func_021EABD0((unsigned char *)p, i, bank, *(unsigned short *)((char *)e + 0x14 + j * 2), 0, j * 16, ((BoxWork *)p)->f78, 0x440);
        }
    } else {
        func_021EABD0((unsigned char *)p, i, ((BoxWork *)p)->f80, 106, 0, 0, ((BoxWork *)p)->f78, 0x440);
    }
    func_02045C04(bank);
    func_021EABA0(windows + i * 2);
}











#undef WORK










#undef WORK









#undef WORK








#undef WORK







#undef WORK






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))













void func_021EB2A4(u8 *p, int a)
{
    func_021EADB4((unsigned char *)(((BoxTask *)p)->f2C), (Entry_021EADB4 *)a, 1);
    func_021EAE20(((BoxTask *)p)->f2C, (void **)a, 2);
    func_021EAE74((char *)(((BoxTask *)p)->f2C), (Entry_021EAE74 *)a, 3);
    func_021EAF20((char *)(((BoxTask *)p)->f2C), (Entry_021EAF20 *)a, 4);
    func_021EAFBC((char *)p, (const Entry_021EAFBC *)a, 5);
    func_021EB098(((BoxTask *)p)->f2C, (unsigned char *)a, 6);
    func_021EB114(((BoxTask *)p)->f2C, (unsigned char *)a, 7);
    func_021EB190(((BoxTask *)p)->f2C, (unsigned char *)a, 8);
    func_021EB208((char *)(((BoxTask *)p)->f2C), (Entry_021EB208 *)a, 9);
    func_021EABA0((void **)((u8 *)((BoxTask *)p)->f2C + 0xe4));
    func_021EABA0((void **)((u8 *)((BoxTask *)p)->f2C + 0xec));
    func_021EABA0((void **)((u8 *)((BoxTask *)p)->f2C + 0xf4));
    func_021EABA0((void **)((u8 *)((BoxTask *)p)->f2C + 0xfc));
}













void func_021EB324(Work *w)
{
    unsigned i;
    for (i = 1; i <= 9; i++) {
        func_021EABB8((void **)(&w->items[i]));
        func_02043B5C(func_02045770(w->items[i].obj), 0);
        func_021EAAE4((unsigned char *)w, i);
    }
    func_021EABB8((void **)(&w->items[10]));
    func_021EABB8((void **)(&w->items[11]));
    func_021EABB8((void **)(&w->items[12]));
    func_021EABB8((void **)(&w->items[13]));
}













/*
 * Draws a window frame from 8x8 tiles, then centres a message in it.  The
 * window size locals are u8 like the getters that return them: as int
 * locals the w - 1 and h - 1 loop guards stop sharing the corner offsets'
 * common subexpressions and the function comes out 20 bytes short.
 */
void func_021EB378(char *p, int idx, unsigned msg, unsigned short frame, unsigned short col, int icon)
{
    void *win = *(void **)(WORK(p) + 0x94 + idx * 8);
    void *bmp = func_02045770(win);
    unsigned char w;
    unsigned char h;
    Chr *chr;
    void *res;
    char *raw;
    void *t;
    unsigned char i;
    void *str;

    func_02045730(win);
    func_02045758(win);
    func_02045760(win);
    w = func_02045738(win);
    h = func_02045740(win);
    func_02043B5C(bmp, 4);
    res = func_02049DB4(0x74, 0x3E, 1, (u32)(&chr), HEAP);
    raw = chr->raw;
    frame *= 0x20;

    t = func_020436FC(raw + frame, 8, 8, 0x20, HEAP);
    func_020439A0(t, bmp, 0, 0, 0, 0, 8, 8, 0xFFFF);
    func_020437AC(t);

    t = func_020436FC(raw + (frame + 0x40), 8, 8, 0x20, HEAP);
    func_020439A0(t, bmp, 0, 0, (w - 1) * 8, 0, 8, 8, 0xFFFF);
    func_020437AC(t);

    t = func_020436FC(raw + (frame + 0xC0), 8, 8, 0x20, HEAP);
    func_020439A0(t, bmp, 0, 0, 0, (h - 1) * 8, 8, 8, 0xFFFF);
    func_020437AC(t);

    t = func_020436FC(raw + (frame + 0x100), 8, 8, 0x20, HEAP);
    func_020439A0(t, bmp, 0, 0, (w - 1) * 8, (h - 1) * 8, 8, 8, 0xFFFF);
    func_020437AC(t);

    t = func_020436FC(raw + (frame + 0x60), 8, 8, 0x20, HEAP);
    for (i = 1; i < h - 1; i++)
        func_020439A0(t, bmp, 0, 0, 0, i * 8, 8, 8, 0xFFFF);
    func_020437AC(t);

    t = func_020436FC(raw + (frame + 0xA0), 8, 8, 0x20, HEAP);
    for (i = 1; i < h - 1; i++)
        func_020439A0(t, bmp, 0, 0, (w - 1) * 8, i * 8, 8, 8, 0xFFFF);
    func_020437AC(t);

    t = func_020436FC(raw + (frame + 0x20), 8, 8, 0x20, HEAP);
    for (i = 1; i < w - 1; i++)
        func_020439A0(t, bmp, 0, 0, i * 8, 0, 8, 8, 0xFFFF);
    func_020437AC(t);

    t = func_020436FC(raw + (frame + 0xE0), 8, 8, 0x20, HEAP);
    for (i = 1; i < w - 1; i++)
        func_020439A0(t, bmp, 0, 0, i * 8, (h - 1) * 8, 8, 8, 0xFFFF);
    func_020437AC(t);

    func_020307B0(res);

    if (icon == 1) {
        res = func_02049DB4(func_020275E4(), 0x20, 0, (u32)(&chr), HEAP);
        t = func_020436FC(chr->raw + 0x120, 0x10, 8, 0x20, HEAP);
        func_020439A0(t, bmp, 0, 0, (w - 3) * 8, 8, 0x10, 8, 5);
        func_020437AC(t);
        func_020307B0(res);
    }

    str = func_02045EC0(*(void **)(WORK(p) + 0x80), msg);
    func_021B6AE4((u8 *)(WORK(p) + 0x94 + idx * 8), (void *)(*(void **)(WORK(p) + 0x8C)), w * 8 / 2, 4, (u32)str,
                  *(unsigned *)(WORK(p) + 0x78), col, 2);
    func_02045808(str);
}












/*
 * Range call with a fixed span and the caller's fourth value.
 */
void func_021EB6D8(int a, int b, int c, int d)
{
    func_021EB378((char *)a, b, c, 0, 0x3d80, d);
}












/*
 * Same range call with both tail slots fixed.
 */
void func_021EB6F0(int a, int b, int c)
{
    func_021EB378((char *)a, b, c, 0, 0xf6 << 6, 0);
}












void func_021EB708(void *m,unsigned i,void *d){unsigned bg=func_02045730(d);unsigned w=func_02045738(d);unsigned h=func_02045740(d);BGWINFRM_AddFrame(m,i,bg,w,h);BGWINFRM_PutBmpWin(m,i,d);}












void func_021EB744(char *p)
{
    func_021EB708(*(struct WinMgr * *)&((BoxWork *)p)->f74, 0, ((BoxWork *)p)->f104);
    func_021EB708(*(struct WinMgr * *)&((BoxWork *)p)->f74, 1, ((BoxWork *)p)->f10C);
    func_021EB708(*(struct WinMgr * *)&((BoxWork *)p)->f74, 2, ((BoxWork *)p)->f114);
    func_021EB708(*(struct WinMgr * *)&((BoxWork *)p)->f74, 3, ((BoxWork *)p)->f11C);
    func_021EB708(*(struct WinMgr * *)&((BoxWork *)p)->f74, 4, ((BoxWork *)p)->f124);
    func_021EB708(*(struct WinMgr * *)&((BoxWork *)p)->f74, 5, ((BoxWork *)p)->f12C);
}












void func_021EB79C(unsigned char *p){if(((struct Obj23969 *)(*(unsigned char * *)&((BoxTask *)p)->f0))->f24==4)func_021EB6F0((int)p,22,71);else func_021EB6F0((int)p,22,69);func_021EB708(((struct Obj23970 *)(*(unsigned char * *)&((BoxTask *)p)->f2C))->f74,10,((struct Obj23971 *)(*(unsigned char * *)&((BoxTask *)p)->f2C))->f144);}












/*
 * Stage 0x17/0x46 then hand the 0x14C word over with index 0xb.
 */
void func_021EB7C8(char *p)
{
    func_021EB6F0((int)p, 0x17, 0x46);
    func_021EB708(*(struct WinMgr **)(*(int *)&((BoxTask *)p)->f2C + 0x74), 0xb,
                  (void *)(*(int *)(*(int *)&((BoxTask *)p)->f2C + 0x14C)));
}













void func_021EB7E8(char **p, unsigned box, int i)
{
    void *s = func_020457B0(0x14, 0x804C);
    unsigned n;
    func_0200785C(((void **)p[0])[1], box, s);
    func_02043B5C(*(void **)(p[11] + i * 8 + 8), 0);
    n = func_0201D304(s, ((struct Obj23973 *)(p[11]))->f78, 0);
    n = (0x60 - n) / 2;
    func_0201C7D0(*(void **)(p[11] + i * 8 + 8), n, 0, s, ((struct Obj23974 *)(p[11]))->f78, 0x440);
    func_02045808(s);
    func_020257D0(*(void **)(p[11] + i * 8 + 4));
}










#undef WORK









#undef WORK








#undef WORK







#undef WORK






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))










#undef MGR









#undef MGR








#undef MGR







#undef MGR






#undef MGR





#undef MGR




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))











/*
 * Wrap the 0x19 counter and forward it with p.
 */
void func_021EB85C(unsigned char *p, int i)
{
    unsigned v = i + p[0x19];
    if (v >= p[0x15])
        v -= p[0x15];
    func_021EB7E8((char **)p, v, 0);
}












void func_021EB874(char **p, unsigned a, int i)
{
    void *s = func_02045EC0(((struct Obj23975 *)(p[11]))->f80, 0x1E);
    unsigned n = func_020078C4((void *)(((unsigned *)p[0])[1]), a);
    func_0201EFA4(((struct Obj23977 *)(p[11]))->f84, 0, n, 2, 0, 1);
    func_0201F250(((struct Obj23978 *)(p[11]))->f84, ((struct Obj23979 *)(p[11]))->f88, s);
    func_02043B5C(*(void **)(p[11] + i * 8 + 8), 0);
    if (n == 0x1E)
        func_0201C7D0(*(void **)(p[11] + i * 8 + 8), 0, 0, ((struct Obj23980 *)(p[11]))->f88, ((struct Obj23981 *)(p[11]))->f7C, 0x1480);
    else
        func_0201C7D0(*(void **)(p[11] + i * 8 + 8), 0, 0, ((struct Obj23982 *)(p[11]))->f88, ((struct Obj23983 *)(p[11]))->f7C, 0x440);
    func_02045808(s);
    func_020257D0(*(void **)(p[11] + i * 8 + 4));
}











/*
 * trailing: two-byte zero alignment padding at 0x021EB95A.
 */
void func_021EB90C(char *p)
{
    func_021EB6D8((int)p, 20, 84, 0);
    func_021EB6D8((int)p, 21, 85, 1);
    BGWINFRM_ChangePalette(*(struct WinMgr * *)&((struct Obj23984 *)(*(char * *)&((BoxTask *)p)->f2C))->f74, 7, 0, 9, 11, 3, 12);
    BGWINFRM_ChangePalette(*(struct WinMgr * *)&((struct Obj23985 *)(*(char * *)&((BoxTask *)p)->f2C))->f74, 7, 0, 12, 11, 3, 12);
}











void func_021EB95C(char *p){BGWINFRM_PutBmpWin((struct WinMgr *)(((struct Obj23986 *)(*(char * *)&((BoxTask *)p)->f2C))->f74),7,(void *)(((struct Obj23987 *)(*(char * *)&((BoxTask *)p)->f2C))->f134));BGWINFRM_PutBmpWin((struct WinMgr *)(((struct Obj23988 *)(*(char * *)&((BoxTask *)p)->f2C))->f74),7,(void *)(((struct Obj23989 *)(*(char * *)&((BoxTask *)p)->f2C))->f13C));func_021EB90C(p);}












void func_021EB988(unsigned char *p, const void *e, unsigned n)
{
    unsigned short w;
    unsigned short h;
    unsigned i = 0;
    BGWINFRM_GetSize(MGR(p), 0, &w, &h);
    for (i = 0; i < n; i++) {
        const Ent *x = &((const Ent *)e)[n - 1 - i];
        if (x->b == 0)
            func_021EB6D8((int)p, 0x13 - i, x->a, 0);
        else
            func_021EB6D8((int)p, 0x13 - i, x->a, 1);
        BGWINFRM_ChangePalette(MGR(p), 5 - i, 0, 0, w, h, 0xC);
    }
    for (; n < 6; n++) {
        unsigned k = 0x13 - n;
        func_02043B5C(func_02045770(*(void **)(WORK(p) + k * 8 + 0x94)), 0);
        func_021EAAE4((unsigned char *)WORK(p), k);
    }
}












/*
 * Clears a message window to colour 15 and draws its frame.
 */
void func_021EBA30(unsigned char *p, void *win)
{
    func_02043B5C(func_02045770(win), 0xF);
    func_0201F73C(win, 2, (unsigned short)*(int *)(WORK(p) + 0x178), 10);
}












/*
 * Forward the i-th entry word with flag 1.
 */
void func_021EBA5C(char *p, int i)
{
    func_0201F7A8(*(void **)(p + i * 8 + 0x94), 1);
}












/*
 * Forward the i-th entry word with flag 0.
 */
void func_021EBA70(char *p, int i)
{
    func_0201F7A8(*(void **)(p + i * 8 + 0x94), 0);
}












/*
 * Prints message msg of the box-menu bank into message window i.
 */
void func_021EBA84(unsigned char *p, int msg, int i)
{
    void *bank = func_021EAC98();
    func_021EBA30(p, *(void **)(WORK(p) + i * 8 + 0x94));
    func_021EAC28(WORK(p), i, bank, msg, 0, 0, *(u32 *)(WORK(p) + 0x78), 0x44F);
    func_021EABA0((void **)(WORK(p) + 0x94 + i * 8));
    func_02045C04(bank);
    func_021EE0FC((char *)p);
}











/*
 * Sibling of func_021EBB28: index 0x34 when state is 5, else 0xb.
 */
void func_021EBADC(char *p, int b)
{
    if (*(int *)(((struct Obj18517 *)p)->f0 + 0x24) == 5)
        func_021EBA84((unsigned char *)p, 0x34, b);
    else
        func_021EBA84((unsigned char *)p, 0xb, b);
}












/*
 * Puts item v into word slot 0 and prints message 0x15 into window i.
 */
void func_021EBAF8(unsigned char *p, u32 v, int i)
{
    func_0201EF40(*(void **)(WORK(p) + 0x84), 0, v);
    func_021EBA84(p, 0x15, i);
}












/*
 * Prints message 0x16 into window i.
 */
void func_021EBB1C(unsigned char *p, int i)
{
    func_021EBA84(p, 0x16, i);
}












/*
 * Forward with index 43.
 */
void func_021EBB28(char *p, int b)
{
    func_021EBA84((unsigned char *)p, 0x2b, b);
}











/*
 * Stage 0x84 of the p+0x2c object with (0, arg1), then index 0xe
 *   with the third argument.
 */
void func_021EBB34(char *p, int a, int b)
{
    func_0201EF40((struct WordSet *)(*(int *)(((struct Obj18518 *)p)->f2C + 0x84)), 0, a);
    func_021EBA84((unsigned char *)p, 0xe, b);
}












/*
 * Forward with index 13.
 */
void func_021EBB58(char *p, int b)
{
    func_021EBA84((unsigned char *)p, 0xd, b);
}











void func_021EBB64(unsigned char *p, unsigned v, int i)
{
    if (v == 0) {
        func_0201EF40(((struct Obj23990 *)(*(char * *)&((BoxTask *)p)->f2C))->f84, 0, 0x70);
        func_021EBA84(p, 0x2c, i);
    } else if (func_0202136C(v) == 1) {
        func_021EBA84(p, 0x30, i);
    } else {
        func_0201EF40(((struct Obj23991 *)(*(char * *)&((BoxTask *)p)->f2C))->f84, 0, v);
        func_021EBA84(p, 15, i);
    }
}












/*
 * Forward with index 32.
 */
void func_021EBBBC(char *p, int b)
{
    func_021EBA84((unsigned char *)p, 0x20, b);
}











/*
 * The image leaves the message undefined for kinds above six.
 */
void func_021EBBC8(unsigned char *p, unsigned kind, int i)
{
    int msg;
    switch (kind) {
    case 0: msg = 2; break;
    case 1: msg = 3;
        func_0201EF14(((struct Obj23992 *)(*(char * *)&((BoxTask *)p)->f2C))->f84, 0, (void *)func_021DD2D0((void ***)p, p[0x14], p[0x16]));
        break;
    case 2: msg = 4;
        func_0201EF14(((struct Obj23993 *)(*(char * *)&((BoxTask *)p)->f2C))->f84, 0, (void *)func_021DD2D0((void ***)p, p[0x14], p[0x16]));
        break;
    case 3: msg = 0x1c; break;
    case 4: msg = 0x1d;
        func_0201EF14(((struct Obj23994 *)(*(char * *)&((BoxTask *)p)->f2C))->f84, 0, (void *)func_021DD2D0((void ***)p, p[0x14], p[0x16]));
        break;
    case 5: msg = 0x1e; break;
    case 6: msg = 6; break;
    }
    func_021EBA84(p, msg, i);
}











void func_021EBC28(unsigned char *p,int n,int i){switch(n){case 0:n=7;break;case 1:n=8;break;case 2:n=9;break;case 3:n=10;break;}func_021EBA84(p,n,i);}












/*
 * Picks the prompt for a menu kind (kind 1 first names the Pokemon in the
 * current slot) and prints it into window i.  An out-of-range kind prints
 * whatever msg holds; the image does not initialise it.
 */
void func_021EBC58(unsigned char *p, int sel, int kind, int i)
{
    int msg;
    switch (kind) {
    case 0:
        msg = 0x10;
        break;
    case 1:
        msg = 0;
        func_0201EF14(*(void **)(WORK(p) + 0x84), 0, (void *)func_021DD2D0((void ***)p, p[0x14], p[0x16]));
        break;
    case 2:
        msg = 5;
        break;
    case 3:
        msg = 0x11;
        break;
    case 4:
        msg = 0xC;
        break;
    case 5:
        msg = 0x1B;
        break;
    }
    func_021EBA84(p, msg, i);
}









#undef WORK








#undef WORK







#undef WORK






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))











/*
 * Item-menu prompt for a kind; kinds 1 to 3 name the held item first.  An
 * out-of-range kind prints whatever msg holds; the image does not initialise it.
 */
void func_021EBCB4(unsigned char *p, int kind, int i)
{
    int msg;
    switch (kind) {
    case 0:
        msg = 0x1A;
        break;
    case 1:
        msg = 0x17;
        func_0201EF40(*(void **)(WORK(p) + 0x84), 0, *(unsigned short *)(WORK(p) + 0xA16C));
        break;
    case 2:
        msg = 0x18;
        func_0201EF40(*(void **)(WORK(p) + 0x84), 0, *(unsigned short *)(WORK(p) + 0xA16C));
        break;
    case 3:
        msg = 0x19;
        func_0201EF40(*(void **)(WORK(p) + 0x84), 0, *(unsigned short *)(WORK(p) + 0xA16C));
        break;
    case 4:
        msg = 0x16;
        break;
    case 5:
        msg = 0x1F;
        break;
    case 6:
        msg = 0xD;
        break;
    case 7:
        msg = 0x2F;
        break;
    }
    func_021EBA84(p, msg, i);
}











/*
 * Maps a menu row to its message index, then tail-calls the printer.
 */
void func_021EBD1C(char *p, int row, int b)
{
    switch (row) {
    case 2:
        row = 0x2d;
        break;
    case 3:
        row = 0x2e;
        break;
    case 4:
        row = 0x31;
        break;
    case 6:
        row = 0x33;
        break;
    }
    func_021EBA84((unsigned char *)p, row, b);
}










void func_021EBD50(unsigned char *p){void *m=(void *)func_021DD2D0((void ***)p,p[20],p[22]);func_0201EF14((struct WordSet *)(((struct Obj23995 *)(*(unsigned char * *)&((BoxTask *)p)->f2C))->f84), 0, m);func_021EBA84(p,50,27);}










/*
 * Index 0x35 when the flag is clear, 0x36 when set.
 */
void func_021EBD78(char *p, int b)
{
    if (b == 0)
        func_021EBA84((unsigned char *)p, 0x35, 0x1b);
    else
        func_021EBA84((unsigned char *)p, 0x36, 0x1b);
}










/*
 * trailing: two-byte zero alignment padding at 0x021EBDD6.
 */
void func_021EBD94(unsigned char *p)
{
    func_021EBDF4(((BoxTask *)p)->f2C);
    func_021EBE24(((BoxTask *)p)->f2C);
    func_021EBEAC(p);
    func_021EE038((char *)p, p[0x1f], p[0x20], p[0x21]);
    func_021EE120(((BoxTask *)p)->f2C);
    func_020434DC(16, 1);
    func_02043598(16, 1);
}










/*
 * Three teardown steps then the SDK pool release.
 */
void func_021EBDD8(char *p)
{
    func_021EE200(p);
    func_021EBF50(p);
    func_021EBE4C(p);
    func_0204A5AC();
}










void func_021EBDF4(void *a0){Template t=d_021EFD64;unsigned n=func_021DC9D8();func_0204A48C(&t,n,76);}










void func_021EBE24(char *p){func_021EC0DC(p);func_021EC1E8(p);func_021EC254(p);func_021ED058((u8 *)p);func_021ECCA4(p);func_021ECDF4(p);}










void func_021EBE4C(char *p)
{
    unsigned i;
    for (i = 0; i < 0x45; i++)
        if (*(int *)(p + i * 4 + 0x9FF4) != -1)
            func_0204A8D4(*(int *)(p + i * 4 + 0x9FF4));
    for (i = 0; i < 0xB; i++)
        if (*(int *)(p + i * 4 + 0xA108) != -1)
            func_0204ADA4(*(int *)(p + i * 4 + 0xA108));
    for (i = 0; i < 0xC; i++)
        if (*(int *)(p + i * 4 + 0xA134) != -1)
            func_0204AFD8(*(int *)(p + i * 4 + 0xA134));
}










void func_021EBEAC(unsigned char *p){((struct Obj23996 *)(*(char * *)&((BoxTask *)p)->f2C))->f9E70=func_0204B100(180,0,76);func_021ED824(*(char * *)&((BoxTask *)p)->f2C);func_021EC2A0(*(char * *)&((BoxTask *)p)->f2C);func_021ED370(p);func_021ECF78(*(char * *)&((BoxTask *)p)->f2C);}











void *func_021EBEE0(char *w, const Desc *s)
{
    void *r = func_0204B294(((struct Obj23997 *)w)->f9E70, (unsigned int)*(void **)(w + s->a * 4 + 0x9FF4),
                            (unsigned int)*(void **)(w + s->b * 4 + 0xA108), (unsigned int)*(void **)(w + s->c * 4 + 0xA134),
                            s, s->d, 0x4C);
    func_0204BA20(r, 0);
    return r;
}










/*
 * Release slot i of the 0x9E74 array when non-null.
 *   CLOSES the register-order residue: `struct Slots_021EBF34 { char pad[0x9E74]; int arr[1]; }`
 *   with `p->arr[i]` gives the image's r4 = p+0x9E74 / r5 = i*4; a plain
 *   `char *p` plus `p + i * 4 + 0x9E74` puts the index in r1 and the constant
 *   in r5 instead.
 */
void func_021EBF34(struct Slots_021EBF34 *p, int i)
{
    if (p->arr[i] != 0) {
        func_0204B3B4((struct Obj *)p->arr[i]);
        p->arr[i] = 0;
    }
}










/*
 * Release all 0x60 slots of the 0x9E70 pool, then release the pool
 *   head itself.
 */
void func_021EBF50(char *p)
{
    unsigned i;
    for (i = 0; i < 0x60; i++)
        func_021EBF34((struct Slots_021EBF34 *)p, i);
    func_0204B1CC((struct Bank *)(((BoxWork *)p)->f9E70));
}










/*
 * Sweep 0x2d slots of the 0x9E74 array, restarting each live one.
 *   The element address must be a named `int *row = (int *)(p + i*4)`
 *   and the offset written as the WORD index row[0x279d]: that is what
 *   puts i in r4, the row in r5 and 0x9E74 in r7 (the flat spelling
 *   swaps r4/r5).
 */
void func_021EBF74(char *p)
{
    unsigned i;
    for (i = 0; i < 0x2d; i++) {
        int *row = (int *)(p + i * 4);
        if (row[0x279d] != 0 && CLACT_GetActorAutoAnim((struct Obj *)row[0x279d]) != 1)
            CLACT_AddActorAnimFrame((struct Obj *)row[0x279d], 0x1000);
    }
    func_0204A600();
}










/*
 * Stop and re-issue slot i of the 0x9E74 array; the word is
 *   re-read for the second call.  Writing the array offset before the index
 *   term is what puts the pool constant in r2 and the index in r6.
 */
void func_021EBFA8(char *p, int i, int v)
{
    CLACT_SetActorAnimFrame((struct Obj *)(*(int *)(p + 0x9E74 + i * 4)), 0);
    func_0204B878((struct Obj *)(*(int *)(p + 0x9E74 + i * 4)), (unsigned short)v);
}










/*
 * Release-and-flag slot i of the 0x9E74 array.
 */
void func_021EBFCC(char *p, int i, int v)
{
    func_021EBFA8(p, i, v);
    func_0204B92C((struct Obj *)*(int *)(p + i * 4 + 0x9E74), 1);
}











/*
 * Forward the i-th word of the pooled table.
 */
u32 func_021EBFEC(char *p, int i)
{
    return func_0204B98C((struct Actor *)(*(int *)(p + i * 4 + 0x9E74)));
}










/*
 * Release slot i of the 0x9E74 array when it is non-null.
 */
void func_021EC000(char *p, int i, int v)
{
    int x = *(int *)(p + i * 4 + 0x9E74);
    if (x != 0)
        func_0204B3DC((struct Obj *)x, v);
}











u32 func_021EC01C(char *p, int i)
{
    return func_0204B3F4((struct Obj *)(*(int *)(p + i * 4 + 0x9E74)));
}










/*
 * Tail call with the table word at the pooled offset.
 */
void func_021EC030(char *p, int i, int c)
{
    func_0204B84C(*(int *)(p + i * 4 + 0x9E74), (unsigned char)c);
}








#undef WORK







#undef WORK






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK
#define WORK(p) (*(char **)((p) + 0x2C))









void func_021EC048(char *p, int i, int c)
{
    CLACT_SetActorDrawPriority((struct Node *)(*(int *)(p + i * 4 + 0x9E74)), (unsigned char)c);
}









void func_021EC060(char *p,unsigned i,int b){if(b==1)func_0204B688(*(void **)((unsigned)p+i*4+0x9e74),1);else func_0204B688(*(void **)((unsigned)p+i*4+0x9e74),0);}









/*
 * Stage two shorts on the stack and hand the 0x9E74 array slot to the
 *   SDK call.  Two spellings (array and struct) both give the image's
 *   store order, because the index term is computed between the stores.
 */
void func_021EC08C(char *p, int i, int a, int b, unsigned short c)
{
    unsigned short t[2];
    t[0] = a;
    t[1] = b;
    func_0204B404((struct Obj *)(*(int *)(p + i * 4 + 0x9E74)), (const struct Vec2 *)t, c);
}










void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space)
{
    short t[2];
    func_0204B454((struct Actor *)*(int *)(p + i * 4 + 0x9E74), (struct PtS *)t, space);
    *a = t[0];
    *b = t[1];
}









void func_021EC0DC(char *p)
{
    void *h;
    unsigned i,j;
    h=func_020490F4(116,76);
    for(j=0;j<6;j++) SLOT(p+j*4,0xA0D8)=(void *)func_0204A6C8(h,71,1,0,76);
    SLOT(p,0xA11C)=(void *)func_0204ABF0(h,72,0,0,76);
    SLOT(p,0xA148)=(void *)func_0204AF28(h,73,74,76);
    for(i=0;i<37;i++) SLOT(p+i*4,0x9FF4)=(void *)func_0204A6C8(h,75,1,0,76);
    SLOT(p,0xA0F0)=(void *)func_0204A6C8(h,67,1,0,76);
    SLOT(p,0xA120)=(void *)func_0204ABF0(h,70,0,192,76);
    SLOT(p,0xA14C)=(void *)func_0204AF28(h,68,69,76);
    SLOT(p,0xA0F4)=(void *)func_0204A6C8(h,64,1,0,76);
    SLOT(p,0xA150)=(void *)func_0204AF28(h,65,66,76);
    SLOT(p,0xA090)=(void *)func_0204A6C8(h,76,1,0,76);
    SLOT(p,0xA140)=(void *)func_0204AF28(h,77,78,76);
    func_02049238(h);
}









void func_021EC1E8(char *p)
{
    void *h = func_020490F4(func_020275E4(), 0x4C);
    ((BoxWork *)p)->fA0F8 = (void *)func_0204A6C8(h, func_02027618(), 0, 0, 0x4C);
    ((BoxWork *)p)->fA124 = (void *)func_0204ABF0(h, func_02027614(), 0, 0x100, 0x4C);
    ((BoxWork *)p)->fA154 = (void *)func_0204AF28(h, func_0202761C(2), func_02027620(2), 0x4C);
    func_02049238(h);
}









void func_021EC254(char *p)
{
    void *h = func_020490F4(7, 0x4C);
    ((BoxWork *)p)->fA108 = (void *)func_0204ACEC(h, func_0201BC3C(), 0, 0x60, 0x4C);
    ((BoxWork *)p)->fA134 = (void *)func_0204AF28(h, func_0201BC40(), func_0201BCB4(), 0x4C);
    func_02049238(h);
}









void func_021EC2A0(char *p)
{
    Desc d;
    Desc base = d_021EFD04;
    unsigned i;
    for (i = 0; i < 0x25; i++) {
        d = base;
        d.x += (short)((i % 6) * 24);
        d.y += (short)((i / 6) * 24);
        d.b6 = 0x75 - i * 2;
        d.a = i;
        *(void **)(p + i * 4 + 0x9F40) = func_021EBEE0(p, (const Desc *)&d);
        *(unsigned char *)(p + i + 0x3DD2) = i + 0x33;
    }
}










/*
 * Forward with a resolved handle and the object table entry.
 */
void *func_021EC338(char *p, void *b, void *c)
{
    return func_02049E74((void *)(((BoxWork *)p)->f1B0), func_0201BA68(b), 0, (u32)c, 0x4c);
}










void func_021EC35C(char **p, int box)
{
    unsigned i;
    void *m;
    void *r;
    void *buf;
    for (i = 0; i < 0x1E; i++) {
        if (func_020079BC(((void **)p[0])[1], box, i, 0xA9, 0) == 0) {
            *(int *)(p[11] + i * 4 + 0x3DF8) = 0;
        } else if (((struct Obj24001 *)(p[0]))->f24 != 3 && ((unsigned char *)p)[0x14] == ((unsigned char *)p)[0x17]
                   && ((unsigned char *)p)[0x16] == i) {
            *(int *)(p[11] + i * 4 + 0x3DF8) = 0;
        } else {
            m = (void *)func_021DD2D0((void ***)p, box, i);
            r = func_021EC338(p[11], m, &buf);
            MIi_CpuCopy32(((struct Obj24002 *)buf)->f14, p[11] + 0x1B4 + i * 0x200, 0x200);
            func_020307B0(r);
            *(unsigned char *)(p[11] + i + 0x3DB4) = POKE_TOOL_GetIconPalette(m);
            *(int *)(p[11] + i * 4 + 0x3DF8) = 1;
        }
    }
}









/*
 * Stop the slot, re-key it and restart it.  Two facts pin this one:
 *   the second call's FIRST argument is the first call's RESULT (r0 is
 *   never overwritten), and the result must be a named local -- the
 *   nested spelling moves a and b to r6/r7 (r6=a) instead of the image's
 *   r7=a / r6=b, a 1-byte miss at +0x18.
 */
void func_021EC428(char *p, int a, int i, int b)
{
    int v = CLACT_GetActorCharacterIndex((u8 *)(*(int *)(p + 0x9E74 + i * 4)));
    CLACT_TransferCharacterPart(v, (void *)a, 0x200, 0, 0);
    func_0204B6F4((struct Obj *)(*(int *)(p + 0x9E74 + i * 4)), (unsigned char)b, 1);
}










/*
 * Loads an icon resource for a, uploads it and frees the file.
 */
void func_021EC45C(unsigned char *p, void *a, int i)
{
    void *d;
    void *res = func_021EC338(WORK(p), a, &d);
    func_021EC428(WORK(p), ((struct Obj24003 *)d)->f14, i, POKE_TOOL_GetIconPalette(a));
    func_020307B0(res);
}










/*
 * Hides window win, and when slot (box, pos) holds something shows its icon
 * there again.  The image narrows both the slot and the box to 16 bits
 * before func_021DD25C, so its box parameter is declared unsigned short here;
 * the callee body only forwards it and cannot show the width.
 */
void func_021EC48C(unsigned char *p, int box, int pos, int win)
{
    char *w = WORK(p);
    func_021EC000(WORK(p), win, 0);
    if (func_021DD25C((void ***)p, pos, (unsigned short)box, 0xA9, 0)) {
        func_021EC45C(p, (void *)func_021DD2D0((void ***)p, box, pos), win);
        func_021EC000(w, win, 1);
    }
}









/*
 * Loop 0x1e entries forwarding (p[0x14], i, i+0x33).
 */
void func_021EC4E0(char *p)
{
    unsigned i;
    for (i = 0; i < 0x1e; i++)
        func_021EC48C((unsigned char *)p, ((BoxTask *)p)->f14, i, i + 0x33);
}









void func_021EC4FC(unsigned char *p)
{
    unsigned n = func_0201AA18(((struct Obj24004 *)(*(char * *)&((BoxTask *)p)->f0))->f8);
    unsigned i;
    for (i = 0; i < n; i++) {
        func_021EC45C(p, POKE_TOOL_GetBoxParam(func_0201AB28(((struct Obj24005 *)(*(char * *)&((BoxTask *)p)->f0))->f8, i)),
                       *(unsigned char *)(*(char * *)&((BoxTask *)p)->f2C + i + 0x3DF0));
        func_021EC000(*(char * *)&((BoxTask *)p)->f2C, *(unsigned char *)(*(char * *)&((BoxTask *)p)->f2C + i + 0x3DF0), 0);
    }
}










void func_021EC548(unsigned i, short *x, short *y, int mode)
{
    if (i < 0x1E) {
        *x = (i % 6 + 1) * 0x18;
        *y = (i / 6) * 0x18 + 0x30;
        return;
    }
    i -= 0x1E;
    *x = d_021EFD4C[i].x;
    *y = d_021EFD4C[i].y - 0x90;
    if (mode == 2)
        *x += 0x98;
}










void func_021EC5A0(char **p, int flag)
{
    unsigned n = func_0201AA18(((void **)p[0])[2]);
    unsigned i;
    for (i = 0; i < 6; i++) {
        int k = *(unsigned char *)(p[11] + i + 0x3DF0);
        func_021EC08C(p[11], k, d_021EFD4C[i].x, d_021EFD4C[i].y, 0);
        func_021EC768(p[11], i + 0x1E, 1);
        if (i < n && (flag == 0 || ((unsigned char *)p)[0x16] != i + 0x1E))
            func_021EC000(p[11], k, 1);
        else
            func_021EC000(p[11], k, 0);
    }
}










/*
 * Lays out the six party-slot windows and shows the ones the party fills.
 * The window id is an int local: as unsigned char the load is scheduled after
 * the table address and 34 bytes move.
 */
void func_021EC61C(unsigned char *p)
{
    unsigned n = func_0201AA18(((struct Obj24008 *)(*(char * *)&((BoxTask *)p)->f0))->f8);
    unsigned i;
    for (i = 0; i < 6; i++) {
        int win = *(unsigned char *)(WORK(p) + i + 0x3DF0);
        func_021EC08C(WORK(p), win, (short)(d_021EFD4C[i].x + 0x98), (short)d_021EFD4C[i].y, (short)0);
        func_021EC768(WORK(p), i + 0x1E, 1);
        if (i < n)
            func_021EC000(WORK(p), win, 1);
        else
            func_021EC000(WORK(p), win, 0);
    }
}









void func_021EC688(char *p)
{
    unsigned n = func_0201AA18(((struct Obj24010 *)(*(char * *)&((BoxTask *)p)->f0))->f8);
    unsigned i;
    for (i = 0; i < 6; i++) {
        int win = *(unsigned char *)(WORK(p) + i + 0x3DF0);
        func_021EC08C(WORK(p), win, (short)d_021EFD4C[i].x, (short)(d_021EFD4C[i].y - 0x90), (short)0);
        func_021EC768(WORK(p), i + 0x1E, 1);
        if (i < n)
            func_021EC000(WORK(p), win, 1);
        else
            func_021EC000(WORK(p), win, 0);
    }
}









void func_021EC6F4(char *p)
{
    unsigned n = func_0201AA18(((struct Obj24012 *)(*(char * *)&((BoxTask *)p)->f0))->f8);
    unsigned i;
    for (i = 0; i < 6; i++) {
        int win = *(unsigned char *)(WORK(p) + i + 0x3DF0);
        func_021EC08C(WORK(p), win, (short)(d_021EFD4C[i].x + 0x98), (short)(d_021EFD4C[i].y - 0x90), (short)0);
        func_021EC768(WORK(p), i + 0x1E, 1);
        if (i < n)
            func_021EC000(WORK(p), win, 1);
        else
            func_021EC000(WORK(p), win, 0);
    }
}







#undef WORK






#undef WORK





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))









void func_021EC768(char *p, unsigned i, int flag)
{
    unsigned char c = *(unsigned char *)(p + i + 0x3DD2);
    if (flag == 0) {
        func_021EC030(p, c, 0);
        func_021EC048(p, c, 0x14);
        return;
    }
    if (i < 0x1E || i == 0x24)
        func_021EC030(p, c, 3);
    else
        func_021EC030(p, c, 1);
    func_021EC048(p, c, 0x75 - i * 2);
}









void func_021EC7B8(char *p, int i, unsigned j, int flag)
{
    unsigned char c = *(unsigned char *)(p + i + 0x3DD2);
    if (flag == 0) {
        func_021EC030(p, c, 0);
        func_021EC048(p, c, 0x14);
        return;
    }
    if (j < 0x1E)
        func_021EC030(p, c, 3);
    else
        func_021EC030(p, c, 1);
    func_021EC048(p, c, 0x75 - j * 2);
}









void func_021EC804(char **p, short dx)
{
    short t[2];
    short reset;
    short lim;
    unsigned short i;
    unsigned char k;
    if (dx >= 0) {
        lim = 0xB0;
        reset = -8;
    } else {
        lim = -8;
        reset = 0xB0;
    }
    for (i = 0; i < 0x1E; i++) {
        k = *(unsigned char *)(p[11] + i + 0x3DD2);
        func_021EC0B0(p[11], k, &t[1], &t[0], 0);
        t[1] += dx;
        if (t[1] == lim) {
            t[1] = reset;
            func_021EC428(p[11], (int)(p[11] + 0x1B4 + i * 0x200), k, *(unsigned char *)(p[11] + i + 0x3DB4));
            func_021EC000(p[11], k, *(int *)(p[11] + i * 4 + 0x3DF8));
            if (((struct Obj24013 *)(p[11]))->fA17A == 0 && (((struct Obj24014 *)(p[0]))->f24 == 3 || ((struct Obj24015 *)(p[0]))->f24 == 5))
                func_021ECB74((char *)p, i);
        }
        func_021EC08C(p[11], k, t[1], t[0], 0);
    }
}









void func_021EC8E4(char *p)
{
    signed char buf[2];
    unsigned short i;
    short x, y;
    BGWINFRM_GetPos(*(struct WinMgr * *)&((struct Obj24016 *)(*(char * *)&((BoxTask *)p)->f2C))->f74, 8, &buf[1], &buf[0]);
    x = buf[0] * 8;
    y = buf[1] * 8;
    for (i = 0; i < 6; i++)
        func_021EC08C(*(char * *)&((BoxTask *)p)->f2C, *(unsigned char *)(*(char * *)&((BoxTask *)p)->f2C + i + 0x3DF0),
                      (short)(y + d_021EFCE0[i].a), (short)(x + d_021EFCE0[i].b), (short)0);
}








void func_021EC94C(char *p)
{
    int pair[2];
    unsigned short shape[2];
    *(float *)(p + 8) = 4096.0f;
    p[7] = 0;
    CLACT_SetActorAffineMode(((BoxTask *)p)->f0, 1);
    pair[0] = (int)*(float *)(p + 8);
    pair[1] = (int)*(float *)(p + 8);
    CLACT_SetActorScale(((BoxTask *)p)->f0, (struct Pair *)pair);
    shape[0] = 0;
    shape[1] = 8;
    CLACT_SetActorAffineOrigin(((BoxTask *)p)->f0, (const struct Pt *)shape);
}








int func_021EC994(char *p)
{
    int pair[2];
    (((struct Obj05439 *)p)->f7)++;
    *(float *)(p + 8) -= 102.0f;
    if ((unsigned char)p[7] == 40)
        return 0;
    pair[0] = (int)*(float *)(p + 8);
    pair[1] = (int)*(float *)(p + 8);
    CLACT_SetActorScale(((BoxTask *)p)->f0, (struct Pair *)pair);
    return 1;
}








int func_021EC9D8(char *p)
{
    int pair[2];
    ((struct Obj04547 *)p)->f7 -= 2;
    *(float *)(p + 8) += 102.0f;
    *(float *)(p + 8) += 102.0f;
    if ((unsigned char)p[7] == 0)
        return 0;
    pair[0] = (int)*(float *)(p + 8);
    pair[1] = (int)*(float *)(p + 8);
    CLACT_SetActorScale(((BoxTask *)p)->f0, (struct Pair *)pair);
    return 1;
}








/*
 * Zero*p through the pool, then run the sibling teardown.
 */
void func_021ECA24(int *p)
{
    func_0204B3DC((struct Obj *)*p, 0);
    func_021ECA38(p);
}








/*
 * Program the two 0x1000 spans of the frame handle and zero its head.
 *
 * Blocker resolved: 0x0204B5AC was matched in arm9 (src/matched/
 * CLACT_SetActorScale.c, shard pkt_0204B5AC), so the call at +0022 attests as
 * `matched`.  Every concrete byte matches; the extent ran long because the
 * follower has no func_ label.
 */
void func_021ECA38(int *p)
{
    struct { unsigned short a[2]; int b[2]; } s;
    s.a[0] = 0;
    s.a[1] = 0;
    CLACT_SetActorAffineOrigin((struct Actor *)(*p), (const struct Pt *)s.a);
    s.b[0] = 0x1000;
    s.b[1] = 0x1000;
    CLACT_SetActorScale((struct Obj *)(*p), (struct Pair *)s.b);
    CLACT_SetActorAffineMode((struct Actor *)(*p), 0);
}








void func_021ECA6C(unsigned char *p, int flag, int i, unsigned end, int mode)
{
    if (mode == 1) {
        if (((struct Obj24017 *)(*(char * *)&((BoxTask *)p)->f0))->f24 == 5) {
            for (; i < end; i++) {
                if (func_021DD908((char *)p, i) == 1 && func_021DD25C((void ***)p, i, p[0x14], 0x4C, 0) == 0)
                    func_021EC060(WORK(p), WIN(p, i), 0);
                else
                    func_021EC060(WORK(p), WIN(p, i), 1);
            }
        } else {
            for (; i < end; i++) {
                if (func_021DD25C((void ***)p, i, p[0x14], 6, 0) == 0)
                    func_021EC060(WORK(p), WIN(p, i), 1);
                else
                    func_021EC060(WORK(p), WIN(p, i), 0);
            }
        }
    } else {
        for (; i < end; i++)
            func_021EC060(WORK(p), WIN(p, i), flag);
    }
}







/*
 * Dispatch flag bits 1 and 2 to the two range halves, with bit
 *   0x80 selecting the sub-range selector.  Matches on the tst-based ternary.
 */
void func_021ECB20(char *p, int f, int c)
{
    int t = (f & 0x80) ? 1 : 0;
    if (f & 1)
        func_021ECA6C((unsigned char *)p, c, 0, 0x1e, t);
    if (f & 2)
        func_021ECA6C((unsigned char *)p, c, 0x1e, 0x25, t);
}








/*
 * Forward the byte at the pooled table offset.  The callee takes three
 * arguments, so the forwarded byte is argument 1 and the passing flag
 * stays in r2 untouched; that is what forces the sum into r3.
 */
void func_021ECB60(char *p, int i, int f)
{
    func_021EC060(p, *(unsigned char *)(p + i + 0x3DD2), f);
}







/*
 * One range call with the selector pair fixed.
 */
void func_021ECB74(char *a, int b)
{
    func_021ECA6C((unsigned char *)a, 1, b, b + 1, 1);
}








void func_021ECB84(char *w, unsigned i)
{
    short xy[2];
    unsigned char *tbl = (unsigned char *)(w + 0x3DD2);
    unsigned char t;
    func_021EC0B0(w, tbl[i], &xy[1], &xy[0], 0);
    t = w[0x3DF6];
    w[0x3DF6] = tbl[i];
    tbl[i] = t;
    func_021EC08C(w, tbl[i], xy[1], xy[0], 0);
    func_021EC768(w, i, 1);
}








void func_021ECBD8(unsigned char *p, int i)
{
    short xy[2];
    unsigned char t;
    func_021EC0B0((char *)p, p[0x3DF6], &xy[1], &xy[0], 0);
    t = (p + 0x3DD2)[i];
    (p + 0x3DD2)[i] = p[0x3DF6];
    p[0x3DF6] = t;
    func_021EC08C((char *)p, p[0x3DF6], xy[1], xy[0], 0);
}





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))







void func_021ECC1C(unsigned char *p)
{
    short xy[2];
    int k;
    if (p[0x18] == 0)
        return;
    func_021EC0B0(WORK(p), 4, &xy[1], &xy[0], 0);
    if ((*(Top * *)&((BoxTask *)p)->f0)->x24 == 3) {
        k = 0xA;
        xy[0] += 8;
    } else {
        k = *(unsigned char *)(WORK(p) + 0x3DF6);
        xy[0] += 4;
    }
    func_021EC08C(WORK(p), k, xy[1], xy[0], 0);
    if ((*(Top * *)&((BoxTask *)p)->f0)->x24 == 3) {
        func_021ED310(WORK(p));
        return;
    }
    if (*(void **)(WORK(p) + 0x9FD4) == 0)
        func_021ED588((char *)p);
    func_021ED7C4(WORK(p), 0x24);
}








/*
 * candidate func_021ECCA4: clear six ints
 */
void func_021ECCA4(char *p)
{
    ((BoxWork *)p)->fA088 = -1;
    ((BoxWork *)p)->fA10C = -1;
    ((BoxWork *)p)->fA138 = -1;
    ((BoxWork *)p)->fA08C = -1;
    ((BoxWork *)p)->fA110 = -1;
    ((BoxWork *)p)->fA13C = -1;
}




/*
 * prototype: 0202D7C8 reads and forwards only r0; legacy r1-r3 omitted.
 * prototype: 0202D8D0 stack mode is full-width in this caller, with no
 * truncation; its callee forwards the same low-halfword value.
 */
void func_021ECCCC(char *p,void **mon,int index)
{
    int *bmp,*cell,*anim;
    int other;
    int mode;
    int archive,state;
    if (*(u16 *)(W(p)+0xA164)==0) {
        bmp=(int *)(W(p)+0xA088);cell=(int *)(W(p)+0xA10C);
        anim=(int *)(W(p)+0xA138);mode=96;other=index+1;
    } else {
        bmp=(int *)(W(p)+0xA08C);cell=(int *)(W(p)+0xA110);
        anim=(int *)(W(p)+0xA13C);mode=128;other=index;index++;
    }
    if (*(void **)((W(p)+index*4)+0x9E74)) {
        func_0204B3B4(*(void **)((W(p)+index*4)+0x9E74));
        func_0204A8D4(*bmp);func_0204ADA4(*cell);func_0204AFD8(*anim);
    }
    archive=func_0202D7C8(76);
    state=func_02017DBC(*mon);
    *bmp=func_0202D934(archive,*mon,0,1,76);
    *cell=func_0202D8D0(archive,*mon,0,1,mode,76);
    *anim=func_0202D9A4((u32)*mon,0,2,1,76);
    func_02017DE4(*mon,state);func_02049238((void *)archive);
    *(void **)((W(p)+index*4)+0x9E74)=func_021EBEE0(W(p), &((const Desc *)&d_021EFD80)[(u32)index]);
    func_021EC000(W(p),index,1);
    if (*(void **)((W(p)+other*4)+0x9E74)) func_021EC000(W(p),other,0);
    *(u16 *)(W(p)+0xA164)^=1;
}



#undef SLOT


#undef SLOT

#undef SLOT
#define SLOT(w, o) (*(void **)((w) + (o)))





/*
 * Loads the box screen graphics from the shared archive into the work
 * slots at 0xA094 (seventeen palettes) and 0xA0FC..0xA160 (character,
 * cell and animation resources), then closes the archive.
 */
void func_021ECDF4(char *w)
{
    void *h;
    unsigned i;

    h = func_020490F4(func_020275E4(), 0x804C);
    for (i = 0; i < 0x11; i++)
        *(void **)(w + i * 4 + 0xA094) = (void *)func_0204A6C8(h, func_020275F8((unsigned char)i), (int)0, (int)1, (unsigned)0x4C);
    SLOT(w, 0xA144) = (void *)func_0204AF28(h, func_020275FC(2), func_02027600(2), 0x4C);
    SLOT(w, 0xA118) = (void *)func_0204ABF0(h, func_020275E8(), 1, 0, 0x4C);
    SLOT(w, 0xA100) = (void *)func_0204A6C8(h, func_0202774C(2), (int)0, (int)1, (unsigned)0x4C);
    SLOT(w, 0xA15C) = (void *)func_0204AF28(h, func_02027750(2), func_02027754(2), 0x4C);
    SLOT(w, 0xA12C) = (void *)func_0204ABF0(h, func_02027748(), 1, 0xA0, 0x4C);
    SLOT(w, 0xA104) = (void *)func_0204A6C8(h, func_0202776C(2), (int)0, (int)1, (unsigned)0x4C);
    SLOT(w, 0xA160) = (void *)func_0204AF28(h, func_02027770(2), func_02027774(2), 0x4C);
    SLOT(w, 0xA130) = (void *)func_0204ABF0(h, func_02027768(), 1, 0xC0, 0x4C);
    SLOT(w, 0xA0FC) = (void *)func_0204A6C8(h, func_0202774C(2), (int)0, (int)0, (unsigned)0x4C);
    SLOT(w, 0xA158) = (void *)func_0204AF28(h, func_02027750(2), func_02027754(2), 0x4C);
    SLOT(w, 0xA128) = (void *)func_0204ABF0(h, func_02027748(), 0, 0x1A0, 0x4C);
    func_02049238(h);
}




/*
 * Verified scratch-only with one --thumb, no --region: EXACT, 12 bytes.
 * symbols for blocker: _PokeTypePltOffset 0x0209FCF8 data a1
 * extern const unsigned char _PokeTypePltOffset[];
 * unsigned func_020275EC(unsigned char i) { return _PokeTypePltOffset[i]; }
 */
void func_021ECF78(char *p)
{
    Desc d = d_021EFD34;
    unsigned i;
    for (i = 0; i < 0x11; i++) {
        d.a = i + 0x28;
        *(void **)(p + i * 4 + 0x9EE4) = func_021EBEE0(p, (const Desc *)&d);
        func_0204B6F4(*(void **)(p + i * 4 + 0x9EE4), (unsigned)func_020275EC((unsigned char)i), 1);
        func_021EC000(p, i + 0x1C, 0);
    }
}


#undef WORK

#undef WORK
#define WORK(p) (*(char **)((p) + 0x2C))



void func_021ECFDC(char *p, int a, int b)
{
    int k = a + 0x1c;
    func_021EC000(p, k, 1);
    func_021EC08C(p, k, 0x58, 0x38, 1);
    if (b != 0 && a != b) {
        k = b + 0x1c;
        func_021EC000(p, k, 1);
        func_021EC08C(p, k, 0x7a, 0x38, 1);
    }
}



/*
 * lever: Byte bitfield access reproduces the original ldrb/lsl24/lsr31
 * at 0x021ED042..0x021ED046; a mask test emitted movs/tst instead.
 */
void func_021ED028(char *p,unsigned char *q){unsigned i;for(i=28;i<45;i++)func_021EC000(p,i,0);if(!((Flag *)(q+18))->high)func_021ECFDC(p,q[12],q[13]);}



void func_021ED058(u8*p){void*h;h=func_020490F4(25,76);*(void* *)&((BoxWork *)p)->fA114=(void *)func_0204ABF0(h,func_02020E60(0,2),0,0x180,76);func_02049238(h);}




void func_021ED094(char *w, unsigned item)
{
    void *a;
    void *b;
    void *q;
    q = func_02049E34(func_02020F08(), func_02020E60(item, 1), 0, (u32)(&a), 0x4C);
    func_0204A9D0(CLACT_GetActorCharacterIndex(((struct Obj14276 *)w)->f9E9C), a);
    func_020307B0(q);
    q = func_02049F34(func_02020F08(), func_02020E60(item, 2), (u32)(&b), 0x4C);
    func_0204ADEC((void *)CLACT_GetActorPaletteIndex(((struct Obj14276 *)w)->f9E9C), b, 1);
    func_020307B0(q);
}




void func_021ED108(char *p, int on)
{
    unsigned short s[2];
    if (on == 1) {
        CLACT_SetActorAffineMode((struct Actor *)HND(p), 1);
        s[0] = 0xC;
        s[1] = 0xC;
        CLACT_SetActorAffineOrigin((struct Actor *)HND(p), (const struct Pt *)s);
    } else {
        s[0] = 0;
        s[1] = 0;
        CLACT_SetActorAffineOrigin((struct Actor *)HND(p), (const struct Pt *)s);
        CLACT_SetActorAffineMode((struct Actor *)HND(p), 0);
    }
}



/*
 * One range call with the sub-range selector.
 */
void func_021ED14C(int a, int b, int c)
{
    func_021EC08C((char *)a, 10, b, c, 0);
}



/*
 * Twin of func_021ED198 with both shorts biased by 8.
 */
void func_021ED164(char *p, int a, int c)
{
    short t[2];
    func_021EC548(a, t + 1, t, c);
    func_021ED14C((int)p, (short)(t[1] + 8), (short)(t[0] + 8));
}



/*
 * Read the 2-short record for the sub-range then push it back with
 *   the first element biased by 4.
 */
void func_021ED198(char *p, int a, int c)
{
    short t[2];
    func_021EC548(a, t + 1, t, c);
    func_021ED14C((int)p, t[1], (short)(t[0] + 4));
}




static inline void setup(Desc *dp, void **res)
{
    dp->b6 = CLACT_GetActorDrawPriority((int)(*res)) + 1;
    dp->b7 = CLACT_GetActorBgPriority(*res);
}




/*
 * Sibling of src/matched/ov/ov170_func_021ED594.c: builds (or moves) the
 * eight frame pieces around window 10 while the count at 0xA16C is nonzero.
 * The index is an int compared against 8u (docs/idioms/a-signed-index-under-an-unsigned-bound-keeps-the-window-sum-uncached.md).
 */
void func_021ED1C8(char *w)
{
    int j;
    Desc d;
    short xy[2];
    if (((struct Obj08247 *)w)->fA16C == 0)
        return;
    j = 0;
    func_021EC0B0(w, 10, &xy[1], &xy[0], 0);
    if (((struct Obj08247 *)w)->f9FD4 == 0) {
        d = d_021EFE70;
        setup(&d, (void **)(w + 0x9E9C));
        d.a = 0x27;
        d.b = 6;
        d.e = 1;
        for (; j < 8u; j++) {
            d.x = xy[1] + d_021EFCD0[j];
            d.y = xy[0] + d_021EFCC8[j];
            *(void **)(w + j * 4 + 0x9FD4) = func_021EBEE0(w, &d);
            func_0204B6F4(*(void **)(w + j * 4 + 0x9FD4), (unsigned char)d.e, 1);
            func_021EC000(w, j + 0x58, 0);
        }
    } else {
        int n6 = CLACT_GetActorDrawPriority((int)(((struct Obj08247 *)w)->f9E9C));
        int n7 = CLACT_GetActorBgPriority(((struct Obj08247 *)w)->f9E9C);
        for (; j < 8u; j++) {
            func_021EC08C(w, j + 0x58, (short)(xy[1] + d_021EFCD0[j]), (short)(xy[0] + d_021EFCC8[j]), (short)0);
            func_021EC048(w, j + 0x58, n6 + 1);
            func_021EC030(w, j + 0x58, n7);
            func_021EC000(w, j + 0x58, 0);
        }
    }
}



/*
 * Loop 8 entries forwarding (i+0x58, 1).
 */
void func_021ED2F4(char *p)
{
    unsigned i;
    for (i = 0; i < 8; i++)
        func_021EC000(p, i + 0x58, 1);
}




void func_021ED310(char *w)
{
    short xy[2];
    unsigned i;
    if (((struct Obj24020 *)w)->f9FD4 != 0) {
        i = 0;
        func_021EC0B0(w, 0xA, &xy[1], &xy[0], 0);
        for (; i < 8; i++)
            func_021EC08C(w, i + 0x58, (short)(xy[1] + d_021EFCD0[i]), (short)(xy[0] + d_021EFCC8[i]), (short)0);
    }
}




/*
 * Builds the cell objects of the box screen from the descriptor table
 * at 0x021EFD80 into the work slots at 0x9E74, hides five of them, then
 * refreshes the cursor.  The loop rows are addressed as a byte offset
 * (i * 0x18 + 0x138) from the table base: both the member form .b[i] and
 * the index form [i + 13] fold the row offset into the literal instead.
 */
void func_021ED370(unsigned char *p)
{
    char *w = WORK(p);
    unsigned i;

    CELL(w, 0) = func_021EBEE0(w, &d_021EFD80.a[0]);
    CELL(w, 1) = func_021EBEE0(w, &d_021EFD80.a[1]);
    CELL(w, 2) = func_021EBEE0(w, &d_021EFD80.a[2]);
    CELL(w, 3) = func_021EBEE0(w, &d_021EFD80.a[3]);
    CELL(w, 4) = func_021EBEE0(w, &d_021EFD80.a[4]);
    CELL(w, 5) = func_021EBEE0(w, &d_021EFD80.a[5]);
    CELL(w, 10) = func_021EBEE0(w, &d_021EFD80.a[10]);
    CELL(w, 6) = func_021EBEE0(w, &d_021EFD80.a[6]);
    CELL(w, 7) = func_021EBEE0(w, &d_021EFD80.a[7]);
    CELL(w, 8) = func_021EBEE0(w, &d_021EFD80.a[8]);
    CELL(w, 9) = func_021EBEE0(w, &d_021EFD80.a[9]);
    for (i = 0; i < 6; i++) {
        *(void **)(w + i * 4 + 0x9EA8) = func_021EBEE0(w, (const Desc *)((const char *)&d_021EFD80 + (i * 0x18 + 0x138)));
        *(void **)(w + i * 4 + 0x9EC0) = func_021EBEE0(w, (const Desc *)((const char *)&d_021EFD80 + (i * 0x18 + 0x1C8)));
    }
    CELL(w, 25) = func_021EBEE0(w, &d_021EFD80.d[0]);
    CELL(w, 26) = func_021EBEE0(w, &d_021EFD80.d[1]);
    CELL(w, 27) = func_021EBEE0(w, &d_021EFD80.d[2]);
    func_021EC000(w, 5, 0);
    func_021EC000(w, 10, 0);
    func_021EC000(w, 0x19, 0);
    func_021EC000(w, 0x1A, 0);
    func_021EC000(w, 0x1B, 0);
    func_021ED508(p, 0xE, 1);
}




/*
 * Sets window 9's frame and mode; outside modes 2, 3 and 4 the mode is
 * cleared again.
 */
void func_021ED508(unsigned char *p, int a, int b)
{
    int kind;
    func_021EBFA8(WORK(p), 9, a);
    func_021EC000(WORK(p), 9, b);
    kind = ((struct Obj24021 *)(*(char * *)&((BoxTask *)p)->f0))->f24;
    if (kind != 2 && kind != 4 && kind != 3)
        func_021EC000(WORK(p), 9, 0);
}



/*
 * Offset by four when the low nibble of 0x1c is set.
 */
void func_021ED544(char *p, int b)
{
    if (((struct Slot *)p)->f)
        b += 4;
    func_021EBFA8(*(char * *)&((BoxTask *)p)->f2C, 4, b);
}




void func_021ED55C(char **p, int flag)
{
    if (flag == 1) {
        if (func_020260F0(((struct Obj24022 *)(p[11]))->f70) == 1)
            func_021EC000(p[11], 4, 1);
    } else {
        func_021EC000(p[11], 4, 0);
    }
}




/*
 * Forward with the byte field at +0x16.
 */
void func_021ED588(char *p)
{
    func_021ED594(p, ((BoxTask *)p)->f16);
}




void func_021ED594(char *p, unsigned i)
{
    char *w;
    unsigned c;
    unsigned short j;
    Desc d;
    Struct36 buf;
    short xy[2];
    if (i == 0xFF)
        return;
    w = *(char * *)&((BoxTask *)p)->f2C;
    c = *(unsigned char *)(w + i + 0x3DD2);
    j = 0;
    func_021EC0B0(w, c, &xy[1], &xy[0], 0);
    if (((BoxWork *)w)->f9FD4 == 0) {
        d = d_021EFD04;
        setup(&d, &((void **)(w + 0x9E74))[c]);
        d.a = c - 0x33;
        d.b = 6;
        d.e = 1;
        for (; j < 8; j++) {
            d.x = xy[1] + d_021EFCD0[j];
            d.y = xy[0] + d_021EFCC8[j];
            *(void **)(w + j * 4 + 0x9FD4) = func_021EBEE0(w, &d);
            func_0204B6F4(*(void **)(w + j * 4 + 0x9FD4), (unsigned char)d.e, 1);
        }
    } else {
        int n6;
        int n7;
        CLACT_GetActorImageProxy(((void **)(w + 0x9E74))[c], (struct Struct36 *)(&buf));
        n6 = CLACT_GetActorDrawPriority((int)(((void **)(w + 0x9E74))[c]));
        n7 = CLACT_GetActorBgPriority(((void **)(w + 0x9E74))[c]);
        for (; j < 8; j++) {
            CLACT_SetActorImageProxy(*(void **)(w + j * 4 + 0x9FD4), (const struct Struct36 *)(&buf));
            func_021EC08C(w, j + 0x58, (short)(xy[1] + d_021EFCD0[j]), (short)(xy[0] + d_021EFCC8[j]), (short)0);
            func_021EC048(w, j + 0x58, n6 + 1);
            func_021EC030(w, j + 0x58, n7);
            func_021EC000(w, j + 0x58, 1);
        }
    }
}




void func_021ED6E4(char **p, int v)
{
    int j;
    for (j = 0; j < 8u; j++) {
        if (*(int *)(p[11] + j * 4 + 0x9FD4) != 0) {
            func_021EC000(p[11], j + 0x58, v);
            if (v == 1 && ((unsigned char *)p)[0x16] != 0xFF) {
                unsigned char k = *(unsigned char *)(p[11] + ((unsigned char *)p)[0x16] + 0x3DD2);
                func_021EC048(p[11], j + 0x58, CLACT_GetActorDrawPriority(*(int *)(p[11] + k * 4 + 0x9E74)) + 1);
                func_021EC030(p[11], j + 0x58, CLACT_GetActorBgPriority((u8 *)(*(int *)(p[11] + k * 4 + 0x9E74))));
            }
        }
    }
}




void func_021ED75C(char **p, int i)
{
    unsigned char k = *(unsigned char *)(p[11] + i + 0x3DD2);
    int a = CLACT_GetActorDrawPriority(*(int *)(p[11] + k * 4 + 0x9E74));
    int b = CLACT_GetActorBgPriority((u8 *)(*(int *)(p[11] + k * 4 + 0x9E74)));
    int j;
    for (j = 0; j < 8u; j++) {
        if (*(int *)(p[11] + j * 4 + 0x9FD4) != 0 && ((unsigned char *)p)[0x16] != 0xFF) {
            func_021EC048(p[11], j + 0x58, a + 1);
            func_021EC030(p[11], j + 0x58, b);
        }
    }
}




void func_021ED7C4(char *p, int i)
{
    short xy[2];
    int j;
    if (i == 0xFF)
        return;
    j = 0;
    func_021EC0B0(p, *(unsigned char *)(p + i + 0x3DD2), &xy[1], &xy[0], j);
    for (; j < 8u; j++)
        func_021EC08C(p, j + 0x58, (short)(xy[1] + d_021EFCD0[j]), (short)(xy[0] + d_021EFCC8[j]), (short)0);
}
