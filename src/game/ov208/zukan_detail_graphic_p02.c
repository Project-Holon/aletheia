/*
 * file:     zukan_detail_graphic_p02.c
 * unit:     yes
 * function: func_021BD574, func_021BD634, func_021BD74C, func_021BD764, func_021BD7E4, func_021BD7F8, func_021BD7FC, func_021BD808, func_021BD814, func_021BD844, func_021BD848, func_021BD868, func_021BD878, func_021BD880, func_021BD89C, func_021BD8C0, func_021BD954, func_021BD974, func_021BDAAC, func_021BDAD0, func_021BDAD4, func_021BDAE8, func_021BDB08, func_021BDB54, func_021BDBA0, func_021BDBAC, func_021BDBB8, func_021BDBEC, func_021BDC14, func_021BDC2C, func_021BDC48, func_021BDC80, func_021BDCA4, func_021BDCDC, func_021BDCF8, func_021BDD24, func_021BDD48, func_021BDD98, func_021BDFA8, func_021BDFDC, func_021BE128, func_021BE16C, func_021BE170, func_021BE1BC, func_021BE20C, func_021BE300, func_021BE32C, func_021BE378, func_021BE3C4, func_021BE4DC, func_021BE504, func_021BE680, func_021BE6A8, func_021BE710, func_021BE778, func_021BE7A4, func_021BE82C, func_021BE840, func_021BE844, func_021BE854, func_021BE864, func_021BE868, func_021BE8FC, func_021BE920, func_021BE9C8, func_021BE9CC, func_021BEA00, func_021BEA04, func_021BEA90, func_021BEB18, func_021BEE70, func_021BEF9C, func_021BEFA0, func_021BF088, func_021BF1D0, func_021BF280, func_021BF308, func_021BF41C, func_021BF450, func_021BF4C4, func_021BF4FC, func_021BF5B8, func_021BF61C, func_021BF620, func_021BF63C, func_021BF664, func_021BF784, func_021BF788, func_021BF8E0, func_021BF9B0, func_021BFE08, func_021BFFEC, func_021C0048, func_021C0090, func_021C0130, func_021C0134, func_021C03C4, func_021C0450, func_021C0524, func_021C0544, func_021C06A0, func_021C06C8, func_021C06EC, func_021C0714, func_021C0740, func_021C0788, func_021C0898, func_021C08E8, func_021C0950, func_021C0968, func_021C0980, func_021C0A88, func_021C0A8C, func_021C0B10, func_021C0B58, func_021C0B6C, func_021C0C00, func_021C0C14, func_021C0C50, func_021C0C8C, func_021C0CC0, func_021C0CCC, func_021C0D3C, func_021C0D5C, func_021C100C, func_021C1068, func_021C10B8, func_021C1450, func_021C1810, func_021C1920, func_021C1AD4, func_021C1D0C, func_021C1D24, func_021C1D30, func_021C1E10, func_021C1F28, func_021C1F44, func_021C1F50, func_021C1FC4, func_021C1FE0, func_021C2090, func_021C20C0, func_021C21D0, func_021C2228, func_021C2234, func_021C2238, func_021C2304, func_021C231C, func_021C232C, func_021C239C, ov208_func_021C23BC, func_021C2430, func_021C2458, func_021C24A4, func_021C24F0, func_021C252C, func_021C255C, func_021C2560, func_021C2644, func_021C270C, func_021C2A70, func_021C2BA8, func_021C2BE0, func_021C2BF4, func_021C2C1C, func_021C2C44, func_021C2D88, func_021C2DE0, func_021C2E6C, func_021C2FEC, func_021C301C
 * address:  0x021BD574
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204A380  0x0204A380  arm
 *   func_02062B30  0x02062B30  arm
 *   func_0204169C  0x0204169C  arm
 *   func_0204162C  0x0204162C  arm
 *   func_020410D0  0x020410D0  arm
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020416D4  0x020416D4  arm
 *   func_021BD56C  0x021BD56C  thumb
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   data_021C8314  0x021C8314  data
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_02035D20 0x02035D20 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020362DC 0x020362DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_02030734 0x02030734 arm
 *   func_02040618 0x02040618 arm
 *   func_0204047C 0x0204047C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_021BDCF8 0x021BDCF8 thumb ov208
 *   func_021BD358 0x021BD358 thumb ov208
 *   func_020056A0 0x020056A0 thumb
 *   d_021C8DE4 0x021C8DE4 data a1
 *   func_02030EAC 0x02030EAC arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_02040804 0x02040804 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_021BD23C 0x021BD23C thumb
 *   d_021C8388 0x021C8388 data a4
 *   d_021C8384 0x021C8384 data a1
 *   func_021BD2E0 0x021BD2E0 thumb ov208
 *   func_021BD308 0x021BD308 thumb ov208
 *   ov208_func_021BD360  0x021BD360  thumb
 *   ov208_func_021BD330  0x021BD330  thumb
 *   func_021BE170  0x021BE170  thumb
 *   func_021BD378  0x021BD378  thumb
 *   func_021BD3A4 0x021BD3A4  thumb  ov208
 *   func_021BD3B4 0x021BD3B4  thumb  ov208
 *   func_021BD35C  0x021BD35C  thumb
 *   func_021BDD98  0x021BDD98  thumb
 *   func_021BE3C4  0x021BE3C4  thumb
 *   func_021BE504  0x021BE504  thumb
 *   func_0204B53C 0x0204B53C arm
 *   func_0204B528 0x0204B528 arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_021BD148  0x021BD148  thumb
 *   func_021BD3C0  0x021BD3C0  thumb
 *   func_021BD3CC  0x021BD3CC  thumb
 *   func_021BD368  0x021BD368  thumb
 *   func_021BE128  0x021BE128  thumb
 *   data_021C8440  0x021C8440  data
 *   data_021C83A4  0x021C83A4  data
 *   func_021BE1BC 0x021BE1BC thumb
 *   func_021BD208 0x021BD208 thumb
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0203633C 0x0203633C arm
 *   func_021BD388 0x021BD388 thumb
 *   func_021BD3F8 0x021BD3F8 thumb
 *   func_02049F34  0x02049F34  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_02061CA4 0x02061CA4 arm
 *   tbl_020A1B38 0x020A1B38 data
 *   data_021C8390  0x021C8390  data
 *   func_021BD394  0x021BD394  thumb
 *   data_021C83C8  0x021C83C8  data
 *   func_021BE920 0x021BE920 thumb ov208
 *   func_021BE864 0x021BE864 thumb ov208
 *   func_0201C440 0x0201C440 thumb
 *   d_021C8DFC 0x021C8DFC data a1
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_021BE9CC 0x021BE9CC thumb ov208
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0204384C 0x0204384C arm
 *   func_020437EC 0x020437EC arm
 *   func_020437D4 0x020437D4 arm
 *   func_02040B58 0x02040B58 arm
 *   func_0204994C 0x0204994C arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049BDC        0x02049BDC  arm
 *   func_02043814        0x02043814  arm
 *   func_020437AC        0x020437AC  arm
 *   func_02045EC0        0x02045EC0  arm
 *   func_0201C724        0x0201C724  thumb
 *   func_02045808        0x02045808  arm
 *   data_021C84F4        0x021C84F4  data
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02040B1C  0x02040B1C  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02034AC4 0x02034AC4 arm
 *   ov067_id 0x00000043 data
 *   ov206_id 0x000000CE data
 *   func_021BC32C 0x021BC32C thumb
 *   func_021BC448 0x021BC448 thumb
 *   func_021BC518 0x021BC518 thumb
 *   func_021BC508 0x021BC508 thumb
 *   func_021BA2CC 0x021BA2CC thumb ov206
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 *   func_021BC464 0x021BC464 thumb ov208
 *   func_021BC34C 0x021BC34C thumb ov208
 *   func_02034A5C 0x02034A5C arm
 *   func_021BC3B4 0x021BC3B4 thumb
 *   func_021BC3B8 0x021BC3B8 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_020414AC 0x020414AC arm
 *   func_021BDAD0 0x021BDAD0 thumb
 *   func_021BC3BC 0x021BC3BC thumb
 *   func_021BDAAC 0x021BDAAC thumb
 *   func_021BDAD4 0x021BDAD4 thumb
 *   func_021BDBB8 0x021BDBB8 thumb
 *   func_021BC3A4 0x021BC3A4 thumb
 *   func_02012BF8 0x02012BF8 thumb
 *   func_021BE840 0x021BE840 thumb
 *   func_021BE82C 0x021BE82C thumb
 *   func_021BE844 0x021BE844 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_021BC3A8 0x021BC3A8 thumb
 *   func_021BCF4C 0x021BCF4C thumb
 *   func_0200CA70 0x0200CA70 thumb
 *   func_021BC3B0 0x021BC3B0 thumb
 *   func_021B9E68 0x021B9E68 thumb ov206
 *   func_021BA7C8 0x021BA7C8 thumb ov206
 *   func_021BC4D8 0x021BC4D8 thumb
 *   func_021BC4C8 0x021BC4C8 thumb
 *   func_021BDBA0 0x021BDBA0 thumb
 *   func_021BC4E4 0x021BC4E4 thumb
 *   func_021BE854 0x021BE854 thumb
 *   func_021BA374 0x021BA374 thumb ov206
 *   func_021BC46C 0x021BC46C thumb
 *   func_021BC3C0  0x021BC3C0  thumb  ov208
 *   func_021BC3CC  0x021BC3CC  thumb  ov208
 *   func_021BC40C  0x021BC40C  thumb  ov208
 *   func_02012BE0  0x02012BE0  thumb
 *   ov208_func_021BF280  0x021BF280  thumb  ov208
 *   func_020061E4  0x020061E4  thumb
 *   func_021BA550 0x021BA550 thumb ov206
 *   func_021BA6B0 0x021BA6B0 thumb ov206
 *   func_021BA814 0x021BA814 thumb ov206
 *   func_021BA64C 0x021BA64C thumb ov206
 *   func_0204B688 0x0204B688 arm
 *   d_021C851C 0x021C851C data ov208 a1
 *   func_0204B98C 0x0204B98C arm
 *   func_0200CC40 0x0200CC40 thumb
 *   func_0200D288 0x0200D288 thumb
 *   func_0200CED4 0x0200CED4 thumb
 *   func_0200D3C0 0x0200D3C0 thumb
 *   func_021BC3AC 0x021BC3AC thumb ov208
 *   func_021BC560 0x021BC560 thumb ov208
 *   func_021BBB24 0x021BBB24 thumb ov072
 *   func_02012984 0x02012984 thumb
 *   ov072_id 0x00000048 data a1
 *   func_021BC97C 0x021BC97C thumb ov208
 *   func_021BC61C 0x021BC61C thumb ov208
 *   func_021BBB34 0x021BBB34 thumb ov072
 *   ov208_func_021BC3B4  0x021BC3B4  thumb  ov208
 *   ov208_func_021BC3B8  0x021BC3B8  thumb  ov208
 *   func_0207D4B0  0x0207D4B0  arm
 *   data_021C85C0  0x021C85C0  data
 *   data_021C8618  0x021C8618  data
 *   func_020403F4  0x020403F4  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040588  0x02040588  arm
 *   ov208_func_021C0134  0x021C0134  thumb  ov208
 *   ov208_func_021BC844  0x021BC844  thumb  ov208
 *   ov208_func_021C1AD4  0x021C1AD4  thumb  ov208
 *   ov208_func_021BC758  0x021BC758  thumb  ov208
 *   ov208_func_021BC718  0x021BC718  thumb  ov208
 *   ov208_func_021BC4F4  0x021BC4F4  thumb  ov208
 *   ov208_func_021BC4D8  0x021BC4D8  thumb  ov208
 *   ov208_func_021BC6D8  0x021BC6D8  thumb  ov208
 *   ov208_func_021BC3BC  0x021BC3BC  thumb  ov208
 *   ov208_func_021BC3A4  0x021BC3A4  thumb  ov208
 *   ov208_func_021BDC14  0x021BDC14  thumb  ov208
 *   ov208_func_021BC4C8  0x021BC4C8  thumb  ov208
 *   ov208_func_021BC6C8  0x021BC6C8  thumb  ov208
 *   ov208_func_021C1D0C  0x021C1D0C  thumb  ov208
 *   ov208_func_021C1D24  0x021C1D24  thumb  ov208
 *   ov208_func_021C10B8  0x021C10B8  thumb  ov208
 *   ov208_func_021BC4E4  0x021BC4E4  thumb  ov208
 *   ov208_func_021BC6F8  0x021BC6F8  thumb  ov208
 *   ov208_func_021BDAE8  0x021BDAE8  thumb  ov208
 *   ov208_func_021BC508  0x021BC508  thumb  ov208
 *   ov208_func_021BC99C  0x021BC99C  thumb  ov208
 *   ov208_func_021C0968  0x021C0968  thumb  ov208
 *   ov208_func_021BC46C  0x021BC46C  thumb  ov208
 *   ov208_func_021BC678  0x021BC678  thumb  ov208
 *   func_021BC4F4 0x021BC4F4 thumb ov208
 *   func_021BC6BC 0x021BC6BC thumb ov208
 *   func_021BBB3C 0x021BBB3C thumb ov072
 *   d_021C8670 0x021C8670 data a2
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_0204B034  0x0204B034  arm
 *   func_0204B258  0x0204B258  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B800  0x0204B800  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B404  0x0204B404  arm
 *   data_021C8558  0x021C8558  data
 *   data_021C8560  0x021C8560  data
 *   data_021C8568  0x021C8568  data
 *   data_021C8580  0x021C8580  data
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B084 0x0204B084 arm
 *   func_02166CD0  0x02166CD0  thumb
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   data_021C8570  0x021C8570  data
 *   data_021C85A4  0x021C85A4  data
 *   func_02049B90  0x02049B90  arm
 *   func_020452E8 0x020452E8 arm
 *   func_02049740  0x02049740  arm
 *   func_02049990  0x02049990  arm
 *   func_0203FB44  0x0203FB44  arm
 *   func_0204B454  0x0204B454  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC78  0x0201BC78  thumb
 *   func_0201BCEC  0x0201BCEC  thumb
 *   func_0201BABC  0x0201BABC  thumb
 *   func_0201BB5C  0x0201BB5C  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02166C7C  0x02166C7C  thumb
 *   func_021BBB48  0x021BBB48  thumb  ov072
 *   func_021C0C14  0x021C0C14  thumb  ov208
 *   data_021C8554  0x021C8554  data
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_02051F1C 0x02051F1C arm
 *   func_0205207C 0x0205207C arm
 *   func_02051F34 0x02051F34 arm
 *   func_020355C4 0x020355C4 arm
 *   func_0203630C 0x0203630C arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   func_0207CCA4 0x0207CCA4 arm
 *   func_020520A4 0x020520A4 arm
 *   ov208_func_021C1920  0x021C1920  thumb  ov208
 *   ov208_func_021C1FE0  0x021C1FE0  thumb  ov208
 *   ov208_func_021C2090  0x021C2090  thumb  ov208
 *   ov208_func_021C20C0  0x021C20C0  thumb  ov208
 *   ov208_func_021C21D0  0x021C21D0  thumb  ov208
 *   func_021BDBAC  0x021BDBAC  thumb  ov208
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0201EE60  0x0201EE60  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_021C0740  0x021C0740  thumb  ov208
 *   func_02013E4C  0x02013E4C  thumb
 *   func_0204B8C4  0x0204B8C4  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_020437DC  0x020437DC  arm
 *   func_021C0C8C 0x021C0C8C thumb ov208
 *   sub_0201D304  0x0201D304  thumb
 *   sub_0201C724  0x0201C724  thumb
 *   data_021C8E14  0x021C8E14  data
 *   data_021C8E1A  0x021C8E1A  data
 *   func_0207D63C 0x0207D63C  arm
 *   FX_SinCosTable_  0x020A1B38  data
 *   ov208_func_021BC518  0x021BC518  thumb  ov208
 *   ov208_func_021BCF4C  0x021BCF4C  thumb  ov208
 *   func_021BC610  0x021BC610  thumb  ov208
 *   func_02006650  0x02006650  thumb
 *   func_020065D8  0x020065D8  thumb
 *   func_021C3638  0x021C3638  thumb  ov208
 *   func_021BCA54  0x021BCA54  thumb  ov208
 *   func_021C32FC  0x021C32FC  thumb  ov208
 *   func_021C3268  0x021C3268  thumb  ov208
 *   func_021C337C  0x021C337C  thumb  ov208
 *   func_021C3374  0x021C3374  thumb  ov208
 *   func_021C3218 0x021C3218 thumb ov208
 *   func_021C3280 0x021C3280 thumb ov208
 *   func_021C3354 0x021C3354 thumb ov208
 *   func_021C3378 0x021C3378 thumb ov208
 *   func_021BC9BC 0x021BC9BC thumb ov208
 *   func_021BC844 0x021BC844 thumb ov208
 *   func_021C35DC 0x021C35DC thumb ov208
 *   func_021BC758 0x021BC758 thumb ov208
 *   func_021BC718 0x021BC718 thumb ov208
 *   func_021C3AA8 0x021C3AA8 thumb ov208
 *   func_021BC6D8 0x021BC6D8 thumb ov208
 *   func_021BC6C8 0x021BC6C8 thumb ov208
 *   func_021BC6F8 0x021BC6F8 thumb ov208
 *   func_021C3514 0x021C3514 thumb ov208
 *   func_021C3B14 0x021C3B14 thumb ov208
 *   func_021C3380 0x021C3380 thumb ov208
 *   func_021C3650 0x021C3650 thumb ov208
 *   func_021C301C 0x021C301C thumb ov208
 *   func_021C3318 0x021C3318 thumb ov208
 *   func_021BC99C 0x021BC99C thumb ov208
 *   func_021BC678 0x021BC678 thumb ov208
 *   func_021C34A4  0x021C34A4  thumb  ov208
 *   func_02005E30  0x02005E30  thumb
 *   data_021C8704  0x021C8704  data
 *   func_0204B908 0x0204B908 arm
 *   data_021C86EC 0x021C86EC data ov208 a1
 *   func_021BC738 0x021BC738 thumb ov208
 *   func_0204B324 0x0204B324 arm
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_0202D81C 0x0202D81C thumb
 *   func_0202D7D8 0x0202D7D8 thumb
 *   func_0202D898 0x0202D898 thumb
 *   func_0202D060 0x0202D060 thumb
 *   func_0202D0D4 0x0202D0D4 thumb
 *   func_0204B5C0 0x0204B5C0 arm
 *   func_0204B5AC 0x0204B5AC arm
 *   _fdiv 0x0209CE10 arm
 *   _fmul 0x0209C77C arm
 *   _fgr 0x0209BBB0 arm
 *   _fleq 0x0209BC0C arm
 *   _fgeq 0x0209BB54 arm
 */
#include "../../matched/include/Obj18236.h"
#include "../../matched/include/Obj03928.h"
#include "../../matched/include/Obj18238.h"
#include "../../matched/include/Obj03065.h"
#include "../../matched/include/Obj18242.h"
#include "../../matched/include/Obj05536.h"
#include "../../matched/include/Obj14647.h"
#include "../../matched/include/Obj18243.h"
#include "../../matched/include/Obj05866.h"
#include "../../matched/include/Obj12118.h"
#include "../../matched/include/Obj01080.h"
#include "../../matched/include/Obj02345.h"
#include "../../matched/include/Obj10895.h"
#include "../../matched/include/Obj14649.h"
#include "../../matched/include/Obj10896.h"
#include "../../matched/include/Obj14650.h"
#include "../../matched/include/Obj09200.h"
#include "../../matched/include/Obj07227.h"
#include "../../matched/include/Obj09201.h"
#include "../../matched/include/Obj01081.h"
#include "../../matched/include/Obj25442.h"
#include "../../matched/include/Obj14652.h"
#include "zukan_detail_types.h"
#include "../../matched/include/Obj03931.h"
#include "../../matched/include/Obj05867.h"
#include "../../matched/include/Obj03362.h"
#include "../../matched/include/Obj00442.h"
#include "../../matched/include/Obj02254.h"
#include "../../matched/include/Obj05538.h"
#include "../../matched/include/Obj12120.h"
#include "../../matched/include/Obj10901.h"
#include "../../matched/include/Obj18262.h"
#include "../../matched/include/Obj25493.h"
#include "../../matched/include/Obj00510.h"
#include "../../matched/include/Obj03933.h"
#include "../../matched/include/Obj08396.h"
#include "../../matched/include/Obj08397.h"
#include "../../matched/include/Obj25495.h"
#include "../../matched/include/Obj02546.h"
#include "../../matched/include/Obj12126.h"
#include "../../matched/include/Obj09204.h"
#include "../../matched/include/Obj14653.h"
#include "../../matched/include/Obj25499.h"
#include "../../matched/include/Obj02346.h"
#include "../../matched/include/Obj06683.h"
#include "../../matched/include/Obj14654.h"
#include "../../matched/include/Obj12127.h"
#include "../../matched/include/Obj25500.h"
#include "../../matched/include/Obj10903.h"
#include "../../matched/include/Obj10904.h"
#include "../../matched/include/Obj18273.h"
#include "../../matched/include/Obj14656.h"
#include "../../matched/include/Obj00081.h"
#include "../../matched/include/Obj18287.h"
#include "../../matched/include/Obj18288.h"
#include "../../matched/include/Obj14657.h"
#include "../../matched/include/Obj10905.h"
#include "../../matched/include/Obj03934.h"
#include "../../matched/include/Obj08403.h"
#include "../../matched/include/Obj25506.h"
#include "../../matched/include/Obj00146.h"
#include "../../matched/include/Obj05541.h"
#include "../../matched/include/Obj10906.h"

#define WP(o) (*(void **)(p + (o)))
#define FX(x) ((int)(((x)>0) ? ((float)((int)(x)<<12)+0.5f) : ((float)((int)(x)<<12)-0.5f)))
#define FIELD(n) func_021BBB3C(*(char **)(p+0x3c8),i,n)
#define SLOT4C(i) (((u32 *)(p + 0x4c))[i])
#define SLOT5C(i) (((u32 *)(p + 0x5c))[i])
#define REG32(a) (*(volatile u32 *)(a))
#define REG16(a) (*(volatile u16 *)(a))
#define H(o) (*(u16 *)(p + (o)))
struct Obj;
struct Actor;
struct Bank;
struct Ov208Scene;
struct Node;
struct Ov208Mgr;
struct State;
struct Ov208Gfx;
struct PrintSys;
struct Bmp;
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct Obj020437AC;
struct Rec;
struct U16Vec;
struct Ov208Buf;
struct Ov208Blend;
struct Blk37;
struct GfFont;
struct S;
struct Ov208Cur;
struct Ov208Main;
struct Ov208Heap;
struct BigObj;
struct Vec2;
struct Cfg;
struct PtS;
struct SaveBlock;
struct Rec44;
struct S12;
struct Vec3;
struct WordSet;
struct StrObj;
struct S_021C23BC;
struct Ov208Win;
struct Ov208PalFade;
struct Ov208Fade;
struct Ov208Icon;
struct Key;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Scrn {
    u8  pad0[0xc];
    u16 data[1];
};

typedef signed short   s16_021BD574;

struct Ov208ActKind {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u32 e;
    u32 f;
};

struct Ov208Pos {
    s16_021BD574 x;
    s16_021BD574 y;
    u16 h4;
    u8  b6;
    u8  b7;
};

typedef signed int     s32_021BD574;

typedef signed short   s16_021BDAAC;

struct State { char pad[0x68]; unsigned char count; };

struct Pt { u16 x,y; };

struct Actor { char pad[0xc]; struct Pt pos; };

struct Ov208Pltt {
    u32 pad0[3];
    u8 *data;
};

typedef signed short   s16_021BE1BC;

typedef short s16_021BE20C;

typedef signed short   s16_021BE3C4;

struct Ov208Icon_021BE710 { u16 heap,pad2; unsigned f4,f8; int fc; unsigned pad10[2],f18,f1c,f20,f24,f28,f2c,f30; };

struct Ov208Icon_021BE7A4 { u16 heap,pad2; unsigned f4,f8; int fc; unsigned char count,pad11[7]; unsigned f18,f1c,f20,f24,f28,f2c,f30; };

struct Ov208Icon_021BE82C {
    u32 pad0[3];
    int fc;
};

struct Ov208Icon_021BE840 {
    u32 f0;
    u32 f4;
    int state;
    int fc;
    u8  step;
};

struct Ov208Icon_021BE844 {
    u32 f0;
    u32 f4;
    int state;
    int fc;
    u8  step;
};

struct Ov208Icon_021BE854 {
    u32 f0;
    u32 f4;
    int state;
    int fc;
    u8  step;
};

struct Ov208Gfx { u16 heap; u16 pad; int f4; int f8; int fc; int f10; u32 f14; void *f18; int f1c; int f20; int f24; };

struct Ov208Icon {
    u16 heap;
    u16 pad2;
    u32 f4;
    u32 f8;
    int fc;
    u32 pad10[2];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
};

struct Ov208PalTbl {
    u32 v[5];
};

struct Ov208Main {
    int task;
    int f4; int f8;
    void *fc;
    void *f10;
    int f14; int f18;
    char pad[0x94 - 0x1c];
    int f94; int f98;
    char pad2[0x10c - 0x9c];
    int f10c;
};

struct Ov208Scn {
    u16 pad0; u16 pad2;
    void *f4; void *f8;
    struct Ov208Blend *fc; struct Ov208Blend *f10;
    int f14; int f18;
    char pad1c[0x94 - 0x1c];
    int f94;
    int f98;
    char pad9c[0xa8 - 0x9c];
    u16 srcA[0x10];
    u16 srcB[0x10];
    u16 dst[0x10];
    int f108;
    int f10c;
    void *font; void *msg0; void *msg1; void *msg2;
};

struct Ov208Heap { u16 heap; };

struct S_021BEE70 {
    u8 pad0[0x14];
    u32 f14;
    u32 f18;
};

struct E {
    u8 pad0[0x1c];
    int h1c;
    u8 x0;
    u8 y0;
    u8 w;
    u8 h;
    u8 pad24[2];
    u16 f26;
    u8 pad28[4];
    u32 f2c;
    u8 pad30[4];
};

struct S_021BEFA0 {
    u8 pad0[0x94];
    u32 cur;
    u32 prev;
};

struct Params {u16 a,b,c,d; unsigned x,y,arr[6];};

enum Index { INDEX_ZERO = 0 };

struct Pos_021BD574 { u16 x, y, z, pad; };

typedef signed int     s32_021BF664;

typedef int            s32_021BF9B0;

struct BgTemplate {
    u32 w[8];
};

struct BgEntry {
    u32 bg;
    struct BgTemplate tmpl;
    u32 type;
    u32 on;
};

typedef signed short   s16_021BFE08;

typedef signed int     s32_021BFE08;

struct S {
    u8 pad0[0x424];
    u32 f424;
    u32 f428;
    u32 f42c;
    u32 f430;
    u32 f434;
};

typedef int            s32_021C0090;

typedef short          s16_021C0134;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 f7;
} ObjPos_021BD574;

typedef struct {
    u32 w[4];
} BankDesc;

typedef struct {
    u8 v[7];
} Row7;

typedef struct {
    s16_021C0134 x;
    s16_021C0134 y;
} Pt_021BFE08;

typedef signed int     s32_021C0134;

typedef short          s16_021C0450;

typedef int            s32_021C0450;

typedef short          s16_021C0544;

typedef int            s32_021C0544;

typedef struct {
    char pad[0x1e0];
    int arr[0x7a];
} S;

typedef int            s32_021C0714;

typedef int            s32_021C0788;

struct WinCfg {
    u8 bg;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
    u8 pal;
    u8 base;
};

struct WinCfg2 {
    struct WinCfg e[2];
};

struct WinCfg4 {
    struct WinCfg e[4];
};

typedef int            s32_021C08E8;

typedef int            s32_021C0A8C;

typedef int            s32_021C0B10;

typedef signed int     s32_021C0B6C;

typedef struct {
    u16 x;
    u16 y;
} Pt_021C0C14;

struct Vec_021C0D5C { int x,y,z; };

struct Ball { struct Vec_021C0D5C p; int radius; };

struct Seg { struct Vec_021C0D5C a,b; int radius; };

struct Out { u32 hit; struct Vec_021C0D5C n; int distance; };

struct Vec_021C1450 { int x, y, z; };

struct PtS { s16_021BFE08 x, y; };

typedef struct {
    u8 f0;
    u8 f1;
    u8 rest[0x3c];
} Entry;

typedef struct {
    u8 f0;
    u8 f1;
    u8 rest[0x3c];
} Entry_021C1E10;

typedef short          s16_021C1E10;

typedef signed short   s16_021C2090;

typedef signed int     s32_021C2090;

typedef signed short   s16_021C20C0;

typedef signed int     s32_021C20C0;

typedef short          s16_021C2228;

typedef int            s32_021C2228;

typedef int            s32_021C1E10;

typedef struct {
    u8 f0;
    u8 f1;
    u8 b[0x3c];
} Entry_021C2234;

typedef int BOOL;

typedef signed short   s16_021C2430;

typedef signed int     s32_021C2430;

typedef enum { ONE = 1 } One;

typedef int            s32_021C2458;

typedef signed short   s16_021C23BC;

typedef signed int     s32_021C2560;

struct S_021C23BC {
    u32 f0;
    u32 f4;
    u32 f8;
    u8 pad0c[0x10];
    u32 f1c;
    u8 pad20[0x34];
    u32 a54[2];
    u32 f5c;
    u8 pad60[8];
    u32 f68;
    u8 pad6c[8];
    u16 f74;
    u16 f76;
    u8 pad78[0x40];
    u32 fb8;
    u32 fbc;
    u32 fc0;
    u32 fc4;
    u32 fc8;
    u32 fcc;
    u32 fd0;
};

typedef signed int     s32_021C23BC;

struct S_021C2A70 {
    u8 pad0[0xcc];
    u32 fcc;
    u32 fd0;
};

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} ObjPos_021C1E10;

struct S_021C2C44 {
    u32 f0;
    u8 pad4[0x80];
    int a84[6];
    u32 a9c[7];
};

struct Indices { u8 v[4]; };

struct Tail {u32 s0,s1,s2,s3,s4;u16 key,pad;};

struct Args {u32 w0,w1,w2,w3;u16 key,pad;};

struct Desc {u16 x,y,z;u8 a,b;u16 c,d;u32 sx,sy;u16 e,f;};

struct S_021C2FEC {
    u8 pad[0x3c];
    u32 a3c[2];
    u32 a44[2];
    u32 a4c[2];
    u32 a54[2];
};

struct Pos_021C1E10 { s16_021C23BC x; s16_021C23BC y; };

struct Pair { int x; int y; };

extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern int func_02062B30(void *file, void **out);
extern u8 func_0204169C(int channel);
extern u32 func_0204162C(int channel);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u8 channel);
extern u32 func_020307B0(void *p);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern u8   func_020416D4(u32 layer);
extern int func_021BD56C(int *p, int i);
extern struct Obj *func_0204B294(u32 owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_0204B3F4(struct Obj *p);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_020355D8(u8 v);
extern u32 func_020362DC(void);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_020061E4(u32 a);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02040618(unsigned,unsigned,unsigned);
extern void func_0204047C(int,u16);
extern struct Bank *func_0204B100(int,unsigned char,unsigned);
extern void func_0204B270(struct Bank *);
extern void func_021BDCF8(struct Ov208Scene *);
extern void func_021BD358(struct Ov208Mgr *p, int v);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern void func_02030EAC(struct Node *n);
extern unsigned int func_0204B1CC(struct Bank *bank);
extern u32 func_02040804(u32 layer);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_021BD23C(struct Ov208Mgr *p);
extern int func_021BD2E0(char *);
extern int func_021BD308(struct Ov208Mgr *m);
extern void ov208_func_021BD360(void *mgr);
extern void ov208_func_021BD330(void *mgr, int v);
extern void func_021BE170(struct Ov208Scene *p);
extern void func_021BD378(struct Ov208Mgr *a, int b, int c);
extern void func_021BD3A4(struct Ov208Mgr *a, int b, int c);
extern int func_021BD3B4(struct Ov208Mgr *mgr, int key);
extern int func_021BD35C(struct Ov208Mgr *p);
extern void func_0204B84C(int, int);
extern void func_021BDD98(struct Ov208Scene *p);
extern void func_021BE3C4(struct Ov208Scene *p);
extern void func_021BE504(struct Ov208Scene *p);
extern void func_0204B53C(const struct Actor *,struct Pt *);
extern void func_0204B528(struct Actor *,const struct Pt *);
extern void *func_020490F4(u32 id, u32 heap);
extern s32_021BD574 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32_021BD574 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021BD574 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern struct Ov208Mgr *func_021BD148(struct Ov208ActList *list, u32 heap);
extern int func_021BD3C0(struct Ov208Mgr *mgr, int key);
extern void func_021BD3CC(struct Ov208Mgr *mgr, int key, u16 *pos);
extern void func_021BD368(struct Ov208Mgr *a, int b, int c);
extern void func_021BE128(struct Ov208Scene *p);
extern void func_021BE1BC(struct Ov208Scene *e);
extern void func_021BD208(struct Ov208Mgr *m);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0203633C(void);
extern int func_021BD388(struct Ov208Mgr *mgr, int key);
extern void func_021BD3F8(struct Ov208Mgr *mgr, int key);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(void *src, void *dst, u32 size);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern s32_021BD574 func_02061CA4(void *p, u32 a, u32 b, s32_021BD574 size);
extern void func_021BD394(struct Ov208Mgr *a, int b, int c);
extern void func_021BE920(struct Ov208Icon_021BE710 *);
extern void func_021BE864(void *);
extern unsigned func_0201C440(void *);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_021BE9CC(struct Ov208Icon_021BE7A4 *);
extern unsigned func_0201C4E4(struct PrintSys *);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *a);
extern struct Bmp *func_0204384C(u32 arc, u32 member, u32 heap2, u32 heap);
extern u32 func_020437EC(const struct Bmp *bmp);
extern void *func_020437D4(const struct Bmp *bmp);
extern u32 func_02040B58(u32 index, const void *src, u32 size);
extern u32 func_0204994C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern unsigned int func_02045C04(struct Rec *rec);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020437AC(struct Obj020437AC *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02043814(struct Bmp *dst, const struct Bmp *src);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void func_02041B6C(u32 layer);
extern int func_02034AC4(s32_021BD574 handle);
extern void *func_021BC32C(struct Ov208Buf *p, u32 size, u32 heap);
extern void *func_021BC448(u32 heap);
extern void func_021BC518(int *p);
extern void func_021BC508(int flag, int *p);
extern void func_021BA2CC(char *);
extern u32 func_0201D83C(void *ptr);
extern void func_021BC464(void *);
extern void func_021BC34C(char *);
extern void func_02034A5C(int);
extern int func_021BC3B4(int *p);
extern int func_021BC3B8(char *p);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_020414AC(u8 a);
extern int func_021BDAD0(void *s);
extern u16 func_021BC3BC(int *ctx);
extern void func_021BDAAC(void *s, u32 a, u32 b, u32 c);
extern void func_021BDAD4(void *s, int a);
extern void func_021BDBB8(void *s, u32 a);
extern int func_021BC3A4(int *ctx);
extern int func_02012BF8(int a, int b);
extern int func_021BE840(void *s);
extern void func_021BE82C(void *s, int a);
extern void func_021BE844(void *s);
extern void *func_0200CA1C(void *a);
extern int func_021BC3A8(int *ctx);
extern int func_021BCF4C(char *p);
extern u32 func_0200CA70(struct Blk37 *p);
extern int func_021BC3B0(int *ctx);
extern void *func_021B9E68(u32 heap, u16 a1, u16 a2, u16 a3, u16 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9, u8 a10, u32 a11, u32 a12, u32 a13, u32 a14, u32 a15, u32 a16);
extern void func_021BA7C8(void *p);
extern void func_021BC4D8(struct Ov208Blend *b);
extern int func_021BC4C8(struct Ov208Blend *b);
extern void func_021BDBA0(void *s);
extern void func_021BC4E4(struct Ov208Blend *b);
extern void func_021BE854(void *s);
extern void func_021BA374(char *p);
extern void func_021BC46C(struct Ov208Blend *a, struct Ov208Blend *b);
extern u16 func_021BC3C0(void *p);
extern void func_021BC3CC(char *p);
extern void func_021BC40C(struct Ov208Cur *p);
extern void func_02012BE0(void *p, u32 a, u32 b);
extern void ov208_func_021BF280(void *first, char *q, void *third, int next);
extern void func_021BA550(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6);
extern void func_021BA6B0(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6, int a7);
extern void func_021BA814(void *);
extern void func_021BA64C(char *p, int mode);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0200CC40(void *, u32, u32 *, u32 *, u32 *, u16);
extern u32 func_0200D288(struct Blk37 *, u32);
extern u32 func_0200CED4(struct Blk37 *, u32);
extern u32 func_0200D3C0(struct Blk37 *, u32, u32);
extern int func_021BC3AC(int *p);
extern u8 func_02012984(const struct BigObj *p);
extern int func_021BBB24(int);
extern void *func_021BC560(u32,u16);
extern void func_021BC97C(char *p);
extern void func_021BC61C(char *p);
extern void func_021BBB34(void *);
extern void *ov208_func_021BC3B4(int key);
extern void *ov208_func_021BC3B8(int key);
extern void func_0207D4B0(int dispMode, int bgMode, int bg0_2d3d);
extern void func_020403F4(u32 i);
extern void func_0203FCA0(u8 bgId, const struct BgTemplate *tmpl, u8 type);
extern void func_02040588(u8 which, u8 enable);
extern void ov208_func_021C0134(u16 *heap, u8 *p, int key);
extern u32  ov208_func_021BC844(u16 heap, u32 kind, u8 layer, u8 pal, u8 objPal);
extern void ov208_func_021C1AD4(u16 *heap, u8 *p, int key);
extern void ov208_func_021BC758(u32 fade);
extern void ov208_func_021BC718(u32 fade);
extern void ov208_func_021BC4F4(int sub, u32 blend);
extern void ov208_func_021BC4D8(u32 blend);
extern void ov208_func_021BC6D8(u32 fade);
extern u16  ov208_func_021BC3BC(char *p);
extern int  ov208_func_021BC3A4(int key);
extern void ov208_func_021BDC14(void *s, int b);
extern int  ov208_func_021BC4C8(u32 blend);
extern int  ov208_func_021BC6C8(u32 fade);
extern void ov208_func_021C1D0C(u16 *heap, u8 *p, int key);
extern void ov208_func_021C1D24(u16 *heap, u8 *p, int key);
extern void ov208_func_021C10B8(u16 *heap, u8 *p, int key);
extern void ov208_func_021BC4E4(u32 blend);
extern void ov208_func_021BC6F8(u32 fade);
extern void ov208_func_021BDAE8(void *s, int v);
extern void ov208_func_021BC508(int sub, u32 blend);
extern void ov208_func_021BC99C(u32 win);
extern void ov208_func_021C0968(u16 *heap, u8 *p, int key);
extern void ov208_func_021BC46C(u32 main, u32 sub);
extern void ov208_func_021BC678(u32 fade);
extern void func_021BC4F4(int flag, int *p);
extern void func_021BC6BC(char *p);
extern u16 func_021BBB3C(char *, int, int);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern struct Obj *func_0204B034(u8 *a0, u32 a1, u32 heap);
extern void func_0204B258(struct Bank *bank, void *p);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B084(void *);
extern int  func_02166CD0(int a, u32 msg);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02049B90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC78(void);
extern int func_0201BCEC(void);
extern u32  func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern u32  func_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
extern void *func_020127A4(struct SaveBlock *p);
extern u16  func_02012AC8(const struct Rec44 *a);
extern u32  func_02166C7C(int a, u32 b);
extern int func_021BBB48(int a0, int a1);
extern u8   func_021C0C14(u16 *heap, u8 *p, int key);
extern void func_02051F1C(struct Ball *,struct Vec_021C0D5C *,u32);
extern void func_0205207C(char *p, struct S12 *q, struct S12 *r, u32 v);
extern u32 func_02051F34(struct Seg *,struct Ball *,struct Out *);
extern u8 func_020355C4(void);
extern unsigned int func_0203630C(void);
extern void func_0207CA00(struct Vec_021C1450 *a, struct Vec_021C1450 *b, struct Vec_021C1450 *out);
extern int func_0207CBD0(struct Vec_021C1450 *v);
extern void func_0207CCA4(struct Vec_021C1450 *src, struct Vec_021C1450 *dst);
extern void func_020520A4(const struct Vec3 *v, int s, struct Vec3 *dst);
extern void ov208_func_021C1920(u16 *heap, u8 *p, int key, int mode);
extern void ov208_func_021C1FE0(u16 *heap, u8 *p, int key);
extern void ov208_func_021C2090(u16 *heap, u8 *p, int key);
extern void ov208_func_021C20C0(u16 *heap, u8 *p, int key);
extern void ov208_func_021C21D0(u16 *heap, u8 *p, int key);
extern void func_021BDBAC(void *s, u32 on);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_021C0740(u16 *heap, u8 *p, int key, u8 i);
extern u32 func_02013E4C(u32 id);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u16 func_020437DC(const struct Bmp *bmp);
extern void func_021C0C8C(u16 *, u8 *, int, int);
extern u32 sub_0201D304(struct StrObj *s, u32 a, u32 b);
extern void sub_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0207D63C(volatile void *, int, int, int, int);
extern void ov208_func_021BC518(u32 blend);
extern u32 ov208_func_021BCF4C(int v);
extern void *func_021BC610(u32 heap);
extern int func_02006650(void);
extern void func_020065D8(void);
extern void func_021C3638(void *unused, char *p, void *a2);
extern void func_021BCA54(u32 a, u32 packed);
extern void func_021C32FC(u16 *heap, u8 *p, int key);
extern void func_021C3268(void *unused, char *p, void *a2);
extern void func_021C337C(void *a0, void *st, void *a2);
extern void func_021C3374(void *a0, void *st, void *a2);
extern void func_021C3218(u16 *,u8 *,int);
extern void func_021C3280(u16 *,u8 *,struct Key *);
extern void func_021C3354(unsigned short *p, void *a1, int a2);
extern void func_021C3378(void *a0, void *a1, int a2, int a3, int a4);
extern u32 func_021BC9BC(int,u16,u8,u8,u8,u8,u32,u32,u32,u32,u32);
extern struct Ov208Win *func_021BC844(u16,u32,u8,u8,u8);
extern void func_021C35DC(u16 *,u8 *,int);
extern void func_021BC758(struct Ov208PalFade *);
extern void func_021BC718(char *p);
extern void func_021C3AA8(void *,u8 *,int);
extern void func_021BC6D8(char *p);
extern int func_021BC6C8(char *p);
extern void func_021BC6F8(char *p);
extern void func_021C3514(u16 *,u8 *,int);
extern void func_021C3B14(void *,u8 *,int);
extern void func_021C3380(u16 *,u8 *,int);
extern void func_021C3650(u16 *,u8 *,int);
extern void func_021C301C(u16 *,u8 *,int);
extern void func_021C3318(u16 *,u8 *,int);
extern void func_021BC99C(char *p);
extern void func_021BC678(char *p);
extern void func_021C34A4(u16 *heap, u8 *p, int key);
extern void func_02005E30(u32 v);
extern int func_02005E9C(void);
extern void func_02005DE4(void *p);
extern void func_02005DF8(u32 a);
extern int func_02005E50(void);
extern int func_02005E64(void);
extern void func_0204B908(int a0, int a1);
extern int func_0202D7C8(int a0);
extern u32 func_0202D81C(u32,u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern int func_0202D7D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned short a8, unsigned short a9);
extern u32 func_0202D898(u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern int func_0202D060(void);
extern s32_021C23BC func_0202D0D4(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern void func_021BC738(struct Ov208Gfx *p, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f, u16 g);
extern struct Obj *func_0204B324(u32 owner, u32 i, u32 j, u32 k, u32 e, u16 f, u16 g);
extern void func_0204B5C0(const struct Obj *o, struct Pair *p);
extern void func_0204B5AC(struct Obj *dst, struct Pair *src);
void ov208_func_021BD574(void *a0, u32 a1, u32 channel, u32 add, u8 a4, u8 a5, u8 a6, u8 a7, u8 x, u8 y, u8 w, u8 h, u8 pal, u32 a13, u16 heap);
void ov208_func_021BD634(struct Ov208Rec *p, u32 owner, const int *res, struct Ov208ActDesc *desc, u32 prio, u16 mode);
void func_021BD74C(char *p);
int func_021BD764(char *p);
int func_021BD7E4(int *p);
int func_021BD7F8(char *p);
void func_021BD7FC(struct Obj **p, unsigned int v);
unsigned func_021BD808(int *p);
void func_021BD814(char *p, int v);
void func_021BD844(char *p, int v);
void func_021BD848(char *p, int which);
int func_021BD868(const void *p);
void func_021BD878(char *p);
void func_021BD880(char *p);
void func_021BD89C(char *p);
char *func_021BD8C0(u16 heap,unsigned arg);
void func_021BD954(struct Ov208Scene *m);
void func_021BD974(struct Ov208Scene *m);
void ov208_func_021BDAAC(struct Ov208Scene *p, u32 mode, u32 kind, u32 flag);
int ov208_func_021BDAD0(struct Ov208Scene *p);
void ov208_func_021BDAD4(struct Ov208Scene *p, int v);
void func_021BDAE8(struct Ov208Scene *p, int v);
unsigned func_021BDB08(const struct State *p);
unsigned func_021BDB54(const struct State *p);
void ov208_func_021BDBA0(struct Ov208Scene *p);
void ov208_func_021BDBAC(struct Ov208Scene *p, int v);
void ov208_func_021BDBB8(struct Ov208Scene *p, u32 kind);
void ov208_func_021BDBEC(struct Ov208Scene *p, int v);
void func_021BDC14(struct Ov208Scene *p, int b);
int func_021BDC2C(char *p);
void func_021BDC48(struct Ov208Scene *p, u32 on);
int func_021BDC80(char *p);
void func_021BDCA4(char *p, unsigned char v);
void func_021BDCDC(int unused, char *p);
void ov208_func_021BDCF8(struct Ov208Scene *p);
void func_021BDD24(char *p);
void func_021BDD48(char *p,short offset);
void ov208_func_021BDD98(struct Ov208Scene *p);
void func_021BDFA8(struct Ov208Scene *e);
void func_021BDFDC(struct Ov208Scene *m);
void ov208_func_021BE128(u8 *p);
void func_021BE16C(struct Ov208Scene *e);
void ov208_func_021BE170(struct Ov208Scene *p);
void ov208_func_021BE1BC(struct Ov208Scene *p);
s32_021BD574 func_021BE20C(struct Ov208Scene *m);
int func_021BE300(int kind);
unsigned func_021BE32C(unsigned n);
unsigned func_021BE378(unsigned n);
void ov208_func_021BE3C4(struct Ov208Scene *p);
void func_021BE4DC(struct Ov208Scene *e);
void ov208_func_021BE504(struct Ov208Scene *p);
void func_021BE680(char *p);
void func_021BE6A8(char *p);
struct Ov208Icon_021BE710 *func_021BE710(u16 heap,unsigned arg);
void func_021BE778(struct Ov208Scene *m);
void func_021BE7A4(struct Ov208Icon_021BE7A4 *p);
void ov208_func_021BE82C(struct Ov208Icon_021BE82C *p, int kind);
int ov208_func_021BE840(struct Ov208Icon_021BE840 *p);
void ov208_func_021BE844(struct Ov208Icon_021BE844 *p);
void ov208_func_021BE854(struct Ov208Icon_021BE854 *p);
void ov208_func_021BE864(void *p);
void func_021BE868(struct Ov208Gfx *g);
void func_021BE8FC(char *p);
void ov208_func_021BE920(struct Ov208Icon *p);
void func_021BE9C8();
void ov208_func_021BE9CC(struct Ov208Icon *p);
void ov208_func_021BEA00(u16 *p, u16 v);
int func_021BEA04(void *owner, int unused, u16 *heap);
int func_021BEA90(char *first,unsigned unused,int owner,char *q,unsigned heap);
int func_021BEB18(void *unused, int *state, struct Ov208Heap *h, struct Ov208Scn *p, int *ctx);
void func_021BEE70(void *a0, void *a1, void *heap, struct S_021BEE70 *st, int *obj, int key);
void func_021BEF9C(void *p);
int func_021BEFA0(void *a0, struct S_021BEFA0 *st, int *obj);
int func_021BF088(void *first,char *p,int key);
void func_021BF1D0(void *first,char *q,void *third);
void func_021BF280(void *first,char *q,void *third,int next);
void func_021BF308(u16 *heap, char *p, int key);
void func_021BF41C(int unused, char *q, u32 a2);
void func_021BF450(void *unused, char *p, int key);
void func_021BF4C4(int unused, char *q, int c, int *tbl);
void func_021BF4FC(const u16 *heap, u8 *p, int *key, u16 *out1, u16 *out2, u16 *out3, u16 *out4, u32 *out5, u32 *out6, u32 *out7);
void func_021BF5B8(u16 *heap, u8 *p, int *ctx);
void func_021BF61C(int unused0, char *unused1, unsigned unused2);
void func_021BF620(struct Ov208Heap *unused, int *p, int *ctx);
void func_021BF63C(int unused, char *p, unsigned unused2);
void func_021BF664(struct Ov208Heap *a0, struct Ov208Scn *e, int *ctx);
void func_021BF784(u16 *p, u16 v);
u32 func_021BF788(void *a0,u32 a1,u16 *heap,u32 a3,int key);
u32 func_021BF8E0(void *a0, u32 a1, void *a2, char *p, void *a4);
int ov208_func_021BF9B0(void *proc, int *seq, u16 *heap, u8 *p, int key);
void func_021BFE08(void *a0, void *a1, void *heap, struct S *st, int *obj, int key);
void func_021BFFEC(void *unused, char *p);
void func_021C0048(u16 *unused, char *p, int a2);
void ov208_func_021C0090(u16 *heap, u8 *p, int key);
void ov208_func_021C0130(u16 *heap, u8 *p, int key);
void func_021C0134(u16 *heap, u8 *p, int key);
void func_021C03C4(void *unused, char *p, void *a2);
void ov208_func_021C0450(u16 *heap, u8 *p, int key);
void func_021C0524(void *unused, char *p, void *a2);
void ov208_func_021C0544(u16 *heap, u8 *p, int key);
void func_021C06A0(void *a0, char *p, void *a2);
void func_021C06C8(unsigned short *a, char *b, int a2);
void func_021C06EC(void *unused, char *p, void *a2);
void ov208_func_021C0714(u16 *heap, u8 *p, int key);
void ov208_func_021C0740(u16 *heap, u8 *p, int key, u8 i);
void ov208_func_021C0788(u16 *heap, u8 *p, int key);
void func_021C0898(void *unused, char *p, void *a2);
void ov208_func_021C08E8(u16 *heap, u8 *p, int key);
void func_021C0950(void *unused, u8 *p, void *a2);
void func_021C0968(int a, int b, int c);
void func_021C0980(int a, unsigned char *p, int a2);
void func_021C0A88(int a0, int a1, int a2);
void ov208_func_021C0A8C(u16 *heap, u8 *p, int key);
void ov208_func_021C0B10(u16 *heap, u8 *p, int key);
void func_021C0B58(void *a, char *q, void *a2);
u32 func_021C0B6C(u32 *slot, u32 a, u32 b, u32 res, u16 heap, u32 species, u32 form, u32 gender, u32 isEgg, u8 x, u8 y);
void func_021C0C00(void *a, void *b);
u8 ov208_func_021C0C14(u16 *heap, u8 *p, int key);
void ov208_func_021C0C50(u16 *heap, u8 *p, int key);
void ov208_func_021C0C8C(u16 *heap, u8 *p, int key, int on);
u32 func_021C0CC0(void *a0, u8 *p, void *a2);
void func_021C0CCC(u16 *heap, u8 *p, int key);
void func_021C0D3C(int a, char *b, int c);
u8 func_021C0D5C(void *unused,char *p,int unused2,u8 x,u8 y);
int func_021C100C(void *unused, char *p, int key, u8 index, u8 x, u8 y, unsigned *out);
u8 func_021C1068(void *heap, char *p, int key, u8 x, u8 y);
void func_021C10B8(u16 *heap, u8 *p, int key);
void func_021C1450(u16 *heap, u8 *p, int key);
void ov208_func_021C1810(u16 *heap, u8 *p, int key);
void func_021C1920(u16 *heap, u8 *p, int key, int mode);
void func_021C1AD4(u16 *heap, u8 *p, int key);
void func_021C1D0C(int a, int b, int c);
void func_021C1D24(void *a, int b, int c);
void func_021C1D30(u16 *heap, u8 *p, int key);
void func_021C1E10(u16 *heap, u8 *p, int key, int dir, int touch);
void *func_021C1F28(int a, int b, int c);
void func_021C1F44(int a);
void func_021C1F50(u16 *heap, u8 *p, int key);
void func_021C1FC4(void *a, char *b, int c);
void func_021C1FE0(u16 *heap, u8 *p, int key);
void func_021C2090(void *unused, u8 *p);
void func_021C20C0(void *a0, u8 *st, void *a2);
void func_021C21D0(void *unused, char *p, int key);
void ov208_func_021C2228(u16 *heap, u8 *p, int key);
void ov208_func_021C2234(u16 *heap, u8 *p, int key);
void func_021C2238(u16 *heap, u8 *p, int key);
void func_021C2304(char *a0);
void func_021C231C(char *p);
void func_021C232C(char *p);
void func_021C239C(char *p);
void ov208_func_021C23BC(u8 *p);
void func_021C2430(u8 *p);
void ov208_func_021C2458(u16 *heap, u8 *p, int key);
void ov208_func_021C24A4(u16 *heap, u8 *p, int key);
void ov208_func_021C24F0(u16 *heap, u8 *p, int key);
void ov208_func_021C252C(u16 *heap, u8 *p, int key);
void func_021C255C(u16 *dst, u16 value);
u32 func_021C2560(void *a0, u32 a1, u16 *desc, u32 a3, int *obj);
u32 func_021C2644(void *a0, u32 a1, void *a2, u8 *st, void *a4);
int func_021C270C(void *unused,int *seq,u16 *heap,u8 *p,int key);
void func_021C2A70(void *a0, void *a1, void *heap, struct S_021C2A70 *st, int *obj, int key);
void func_021C2BA8(void *unused, u8 *p);
void func_021C2BE0(void *unused, u8 *p, void *a2);
void func_021C2BF4(void *unused, char *p, void *a2);
void func_021C2C1C(int unused, char *p, int a2);
void func_021C2C44(u16 *heap, struct S_021C2C44 *st, int a2);
void func_021C2D88(void *unused, u8 *p, void *a2);
void func_021C2DE0(void *unused,u8 *p,void *unused2,int first,u16 second);
void func_021C2E6C(u16 *heap,u8 *p,int key,u32 slot);
void func_021C2FEC(void *unused, struct S_021C2FEC *p, u32 unused2, u32 i);
void ov208_func_021C301C(u16 *heap, u8 *p, int key);
extern const struct Ov208ActKind data_021C8314[];
extern const char d_021C8DE4[];
extern const int d_021C8388[];
extern const u8 d_021C8384[];
extern struct Ov208ActSrc data_021C8440[];
extern u16 data_021C83A4[][2];
extern s16_021BE20C tbl_020A1B38[];
extern struct Ov208ActSrc data_021C8390[];
extern struct Ov208ActSrc data_021C83C8[];
extern const char d_021C8DFC[];
extern const struct Ov208PalTbl data_021C84F4;
extern const char ov067_id[];
extern const char ov206_id[];
extern const u8 d_021C851C[];
extern u8 ov072_id[];
extern const struct BgEntry data_021C85C0[2];
extern const struct BgEntry data_021C8618[2];
extern const u16 d_021C8670[];
extern const BankDesc data_021C8580;
extern const Row7 data_021C8558;
extern const Row7 data_021C8560;
extern const Row7 data_021C8568;
extern const struct WinCfg2 data_021C8570;
extern const struct WinCfg4 data_021C85A4;
extern const Pt_021C0C14 data_021C8554;
extern const u8 data_021C8E14[3][2];
extern u8 data_021C8E1A[3][4];
extern s16_021C23BC FX_SinCosTable_[];
extern const u8 data_021C8704[7][9];
extern const struct Indices data_021C86EC;


#define W(o) (*(u32 *)(p + (o)))












void ov208_func_021BD574(void *a0, u32 a1, u32 channel, u32 add, u8 a4, u8 a5, u8 a6,
                         u8 a7, u8 x, u8 y, u8 w, u8 h, u8 pal, u32 a13, u16 heap)
{
    struct Scrn *scr;
    u32 file;
    int i;
    u16 *d;

    file = (u32)func_0204A380(a0, a1, a13, (u16)((heap & 0x7fff) | 0x8000));
    func_02062B30((void *)file, (void **)(&scr));
    if (add != 0 && func_0204169C((u8)channel) == 0) {
        d = scr->data;
        for (i = 0; i < a6 * a7; i++)
            d[i] += (u16)add;
    }
    if ((int)func_0204162C((u8)channel) != 0) {
        func_020410D0((u8)channel, x, y, w, h, (u32)scr->data, a4, a5, a6, a7);
        func_020413B0(channel, x, y, w, h, pal);
        func_020409B4(channel);
    }
    func_020307B0((void *)file);
}












void ov208_func_021BD634(struct Ov208Rec *p, u32 owner, const int *res, struct Ov208ActDesc *desc,
                         u32 prio, u16 mode)
{
    struct Ov208Pos pos;
    u32 i;
    u32 j;
    u32 k;
    int n;

    func_02082BCC(p, 0, 0x38);
    p->desc = *desc;
    p->f4 = 1;
    p->f34 = 0;
    func_02082BCC(&pos, 0, 8);
    pos.b7 = func_020416D4((u8)res[3]);
    pos.x = desc->x;
    pos.y = desc->y;
    if (desc->f0 >= 7) {
        i = desc->ha;
        j = desc->hc;
        k = desc->he;
        p->f10 = 0;
    } else {
        i = func_021BD56C((int *)res, 1);
        j = func_021BD56C((int *)res, 0);
        k = func_021BD56C((int *)res, 2);
        n = desc->f0;
        p->desc.h10 = data_021C8314[n].a;
        p->desc.h12 = data_021C8314[n].b;
        p->desc.h14 = data_021C8314[n].c;
        p->desc.f18 = data_021C8314[n].e;
        p->desc.f1c = data_021C8314[n].d;
        p->f10 = data_021C8314[n].f;
    }
    p->f8 = p->desc.h10;
    pos.h4 = p->desc.h10;
    p->f0 = (u32)func_0204B294((u32)owner, i, j, k, &pos, prio, mode);
    func_0204B92C((struct Obj *)p->f0, 1);
    switch (p->f10) {
    case 0:
        p->fc = (void (*)(void))func_021BD880;
        break;
    case 1:
        p->fc = (void (*)(void))func_021BD89C;
        break;
    }
}












/*
 * Releases +0 and clears 0x38 bytes of the object.
 */
void func_021BD74C(char *p)
{
    func_0204B3B4((struct Obj *)(((struct Obj18236 *)p)->f0));
    func_02082BCC(p, 0, 0x38);
}











int func_021BD764(char *p)
{
    unsigned x,y;
    int hit=0;
    if(func_0204B3F4(((struct Obj03928 *)p)->f0)&((struct Obj03928 *)p)->f4) {
        if(func_02035D20(&x,&y) && x-((struct Obj03928 *)p)->f18<=((struct Obj03928 *)p)->f1C && y-((struct Obj03928 *)p)->f1A<=24) {
            hit=1;
            func_020355D8(1);
        }
        if(((struct Obj03928 *)p)->f2C && (func_020362DC()&((struct Obj03928 *)p)->f2C)) {
            func_020355D8(0);
            hit=1;
        }
        if(((struct Obj03928 *)p)->f34) {
            func_020355D8(0);
            hit=1;
        }
        if(hit) {
            (*(void (**)(char *))(p+0xc))(p);
            return 1;
        }
    }
    return 0;
}












/*
 * Returns 1 when the ARM9 call at 0x0204B98C on the word at [p] comes back zero.
 */
int func_021BD7E4(int *p)
{
    return func_0204B98C((struct Actor *)(*p)) == 0;
}













int func_021BD7F8(char *p)
{
    return ((struct Obj18238 *)p)->f14;
}












/*
 * Loads the word at [p] and tail-calls the function at 0x0204B3DC with it and
 * the second argument.
 */
void func_021BD7FC(struct Obj **p, unsigned int v)
{
    func_0204B3DC(*p, v);
}












unsigned func_021BD808(int *p)
{
    return func_0204B3F4((struct Obj *)(*p));
}












void func_021BD814(char *p, int v)
{
    ((struct Obj03065 *)p)->f4 = v;
    if (v != 0) {
        if (((struct Obj03065 *)p)->f8 == ((struct Obj03065 *)p)->f28)
            ((struct Obj03065 *)p)->f8 = ((struct Obj03065 *)p)->f24;
        func_0204B878((struct Obj *)(((struct Obj03065 *)p)->f0), (unsigned short)((struct Obj03065 *)p)->f8);
    } else {
        func_0204B878((struct Obj *)(((struct Obj03065 *)p)->f0), ((struct Obj03065 *)p)->f26);
    }
}












void func_021BD844(char *p, int v)
{
    ((struct Obj18242 *)p)->f2C = v;
}











void func_021BD848(char *p, int which)
{
    if (which != 0)
    {
        ((struct Obj05536 *)p)->f8 = ((struct Obj05536 *)p)->f28;
    }
    else
    {
        ((struct Obj05536 *)p)->f8 = ((struct Obj05536 *)p)->f24;
    }
    func_0204B878(((struct Obj05536 *)p)->f0, (unsigned short)((struct Obj05536 *)p)->f8);
}











int func_021BD868(const void *p)
{
    u32 r1 = ((struct Obj14647 *)p)->f8;
    u32 r0 = ((struct Obj14647 *)p)->f28;
    return r1 == r0;
}












/*
 * Clears the word at +0x34.
 */
void func_021BD878(char *p)
{
    ((struct Obj18243 *)p)->f34 = 0;
}











/*
 * Re-verified 2026-09-27 (DIFF fixer lane): the +8 store in the image is a
 * full word, `str r1,[r4,#8]`, not `strh`: the zero-extended u16 is written
 * through an int lvalue.  With `*(int *)(p + 8) = h;` the whole function
 * reproduces, including `ldrh r1,[r4,#0x28]; ldr r0,[r4]; str r1,[r4,#8]`.
 * EXACT*: the inferred extent runs 2 bytes past `pop` (an unlabelled
 * follower/alignment word), never a byte difference.
 */
void func_021BD880(char *p)
{
    unsigned short h = ((struct Obj05866 *)p)->f28;
    int v = ((struct Obj05866 *)p)->f0;

    ((struct Obj05866 *)p)->f8 = h;
    func_0204B878((struct Obj *)v, h);
    if (((struct Obj05866 *)p)->f30 != 0)
        func_020061E4(((struct Obj05866 *)p)->f30);
}











void func_021BD89C(char *p)
{
    int f = func_021BD868(p) == 0;

    func_021BD848(p, f);
    if (((struct Obj12118 *)p)->f30 != 0)
        func_020061E4(((struct Obj12118 *)p)->f30);
}










char *func_021BD8C0(u16 heap,unsigned arg)
{
    char *p=func_02030734(heap,0x11c,1,d_021C8DE4,0x148);
    ((struct Obj01080 *)p)->f0=heap;((struct Obj01080 *)p)->f4=arg;
    ((struct Obj01080 *)p)->f8=0;((struct Obj01080 *)p)->fC=0;((struct Obj01080 *)p)->f10=0;
    ((struct Obj01080 *)p)->f14=1;((struct Obj01080 *)p)->f18=0;((struct Obj01080 *)p)->f1C=0;((struct Obj01080 *)p)->f20=0;
    func_02040618(1,3,-24);func_0204047C(1,0);
    p[0x38]=0;((struct Obj01080 *)p)->f3C=0;
    *(struct Bank * *)&((struct Obj01080 *)p)->f28=func_0204B100(16,0,((struct Obj01080 *)p)->f0);
    func_0204B270(*(struct Bank * *)&((struct Obj01080 *)p)->f28);
    *(unsigned *)&((struct Obj01080 *)p)->f30=0;func_021BDCF8((struct Ov208Scene *)p);
    func_021BD358(((struct Obj01080 *)p)->f30,0);
    ((struct Obj01080 *)p)->fB4=24;func_021BDD48(p,((struct Obj01080 *)p)->fB4);
    ((struct Obj01080 *)p)->f2C=func_020056A0((unsigned)func_021BDCDC,(unsigned)p,1);
    return p;
}










/*
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
void func_021BD954(struct Ov208Scene *m)
{
    func_02030EAC((struct Node *)m->f2c);
    func_021BDD24((char *)m);
    func_0204B1CC((struct Bank *)m->f28);
    func_020307B0(m);
}










void func_021BD974(struct Ov208Scene *m)
{
    int v;
    switch (m->state) {
    case 0:
    case 2:
        break;
    case 1:
        if (m->step == 0) {
            if ((int)func_02040804((int)1) >= 0) {
                func_02041EE4(1, 3, 0);
                m->pos = 0;
                func_021BDD48((char *)m, m->pos);
                m->state = 2;
                if (m->f34 != 0)
                    func_021BD358(m->mgr, 1);
                break;
            }
            func_02041EE4(1, 4, d_021C8388[m->idx]);
            m->pos = m->pos - (short)d_021C8388[m->idx];
            func_021BDD48((char *)m, m->pos);
            m->step = d_021C8384[m->idx];
        } else {
            m->step--;
        }
        break;
    case 3:
        if (m->step == 0) {
            if ((int)func_02040804((int)1) <= -24) {
                func_02041EE4(1, 3, -24);
                m->pos = 24;
                func_021BDD48((char *)m, m->pos);
                m->state = 0;
            } else {
                func_02041EE4(1, 5, d_021C8388[m->idx]);
                m->pos = m->pos + (short)d_021C8388[m->idx];
                func_021BDD48((char *)m, m->pos);
                m->step = d_021C8384[m->idx];
            }
        } else {
            m->step--;
        }
        break;
    }
    func_021BD23C(m->mgr);
    if (m->mode == 0) {
        func_021BDFDC((struct Ov208Scene *)m);
        func_021BE20C((struct Ov208Scene *)m);
    } else if (m->mode == 2) {
        func_021BE6A8((char *)m);
    }
}











void ov208_func_021BDAAC(struct Ov208Scene *p, u32 mode, u32 kind, u32 flag)
{
    p->fc = p->mode;
    p->mode = mode;
    p->f14 = p->f18;
    p->f18 = kind;
    p->f40 = flag;
    func_021BDD24((char *)p);
    p->f1c = p->f18;
    func_021BDCF8(p);
}











int ov208_func_021BDAD0(struct Ov208Scene *p)
{
    return p->state;
}











void ov208_func_021BDAD4(struct Ov208Scene *p, int v)
{
    p->idx = v;
    if (p->state != 2) {
        p->state = 1;
        p->step = 0;
    }
}











/*
 * Stores the argument at +0x20 and, when +8 is set, restarts it at state 3.
 */
void func_021BDAE8(struct Ov208Scene *p, int v)
{
    p->idx = v;
    if (p->state != 0) {
        p->state = 3;
        p->step = 0;
        func_021BD358(p->mgr, 0);
    }
}









unsigned func_021BDB08(const struct State *p)
{
    int key=func_021BD2E0(*(char * *)&((struct Obj10895 *)p)->f30);
    unsigned result=0;
    unsigned char i;
    unsigned count;
    char *entry;
    if(key!=-1) {
        switch(((struct Obj10895 *)p)->f10) {
        case 0: case 1: case 2:
            i=0;
            count=p->count;
            for(;i<count;i++) {
                entry=*(char **)((char *)p+i*8+0x6c);
                if(key==((struct Obj14649 *)entry)->f0) { result=((struct Obj14649 *)entry)->fC; break; }
            }
            break;
        }
    }
    return result;
}









/*
 * trailing: 021BDB9E..021BDBA0 is two-byte zero alignment padding.
 * matching: initialize the byte counter before reading the bound.
 */
unsigned func_021BDB54(const struct State *p)
{
    int key=func_021BD308((struct Ov208Mgr *)(*(char * *)&((struct Obj10896 *)p)->f30));
    unsigned result=0;
    unsigned char i;
    unsigned count;
    char *entry;
    if(key!=-1) {
        switch(((struct Obj10896 *)p)->f10) {
        case 0: case 1: case 2:
            i=0;
            count=p->count;
            for(;i<count;i++) {
                entry=*(char **)((char *)p+i*8+0x6c);
                if(key==((struct Obj14650 *)entry)->f0) { result=((struct Obj14650 *)entry)->f10; break; }
            }
            break;
        }
    }
    return result;
}










void ov208_func_021BDBA0(struct Ov208Scene *p)
{
    ov208_func_021BD360(p->mgr);
}










void ov208_func_021BDBAC(struct Ov208Scene *p, int v)
{
    ov208_func_021BD330(p->mgr, v);
}










void ov208_func_021BDBB8(struct Ov208Scene *p, u32 kind)
{
    u32 saved;
    int restore;

    if (p->mode == 0) {
        restore = 0;
        p->f14 = p->f18;
        p->f18 = kind;
        if (kind == p->f1c) {
            saved = p->f1c;
            restore = 1;
            p->f1c = 4;
        }
        ov208_func_021BE1BC(p);
        func_021BE170(p);
        if (restore)
            p->f1c = saved;
    }
}










void ov208_func_021BDBEC(struct Ov208Scene *p, int v)
{
    if (p->mode == 2) {
        func_021BD378(p->mgr, p->slots[1].src->id, v);
        func_021BD378(p->mgr, p->slots[2].src->id, v);
    }
}










/*
 * Calls func_021BD3A4 with two fields and the second argument while +0x10 is clear.
 */
void func_021BDC14(struct Ov208Scene *p, int b)
{
    if (p->mode == 0)
        func_021BD3A4(p->mgr, p->slots[2].src->id, b);
}










int func_021BDC2C(char *p)
{
    if (((struct Obj09200 *)p)->f10 == 0)
        return func_021BD3B4((void *)(((struct Obj09200 *)p)->f30),
                             *(int *)*(int * *)&((struct Obj09200 *)p)->f7C);
    return 0;
}










void func_021BDC48(struct Ov208Scene *p, u32 on)
{
    p->f34 = on;
    if (on != 0) {
        if (func_021BD35C(p->mgr) == 0 && p->state == 2)
            func_021BD358(p->mgr, 1);
    } else {
        if (func_021BD35C(p->mgr) != 0)
            func_021BD358(p->mgr, 0);
    }
}











int func_021BDC80(char *p)
{
    switch (((struct Obj07227 *)p)->f10) {
    case 0:
        return ((struct Obj07227 *)p)->f44;
    case 1:
        return ((struct Obj07227 *)p)->f50;
    case 2:
        return ((struct Obj07227 *)p)->f5C;
    }
    return -1;
}










/*
 * Stores the mode at +0x38, arms +0x3C and hands the mode to every +0x70 handle.
 */
void func_021BDCA4(char *p, unsigned char v)
{
    unsigned char i;

    ((struct Obj02345 *)p)->f38 = v;
    ((struct Obj02345 *)p)->f3C = 1;
    for (i = 0; i < ((struct Obj02345 *)p)->f68; i++)
        func_0204B84C(*(int *)(p + i * 8 + 0x70), v);
}










/*
 * BLOCKED.  MATCH: the call at +0x10 targets 0204047C, an ARM address with no label and no pool witness outside the compared range, so the site stays wildcarded.
 */
void func_021BDCDC(int unused, char *p)
{
    if (((struct Obj09201 *)p)->f3C != 0) {
        func_0204047C(1, ((struct Obj09201 *)p)->f38);
        ((struct Obj09201 *)p)->f3C = 0;
    }
}










void ov208_func_021BDCF8(struct Ov208Scene *p)
{
    switch (p->mode) {
    case 0:
        func_021BDD98(p);
        break;
    case 1:
        func_021BE3C4(p);
        break;
    case 2:
        func_021BE504(p);
        break;
    }
    p->f34 = 1;
}










void func_021BDD24(char *p)
{
    switch (((struct Obj01081 *)p)->fC) {
    case 0:
        func_021BDFA8((struct Ov208Scene *)p);
        break;
    case 1:
        func_021BE4DC((struct Ov208Scene *)p);
        break;
    case 2:
        func_021BE680(p);
        break;
    }
}









void func_021BDD48(char *p,short offset)
{
    unsigned char i;
    struct Pt pt;
    for(i=0;i<((struct Obj25442 *)p)->f68;i++) {
        func_0204B53C(*(struct Actor **)(p+i*8+0x70),&pt);
        pt.y=*(short *)(*(char **)(p+i*8+0x6c)+6);
        pt.y=(short)pt.y+offset;
        func_0204B528(*(struct Actor **)(p+i*8+0x70),&pt);
    }
}










void ov208_func_021BDD98(struct Ov208Scene *p)
{
    struct Ov208ActList list;
    struct Ov208ActDesc descs[9];
    void *h;
    u8 i;
    int v;

    h = func_020490F4(0x9f, p->heap);
    p->f44 = func_0204AC18(h, 3, 0, 0x160, 0, 3, p->heap);
    p->f48 = func_0204A6C8(h, 0xd, 0, 0, p->heap);
    p->f4c = func_0204AF28(h, 0x1b, 0x2c, p->heap);
    func_02049238(h);
    p->count = 9;
    for (i = 0; i < p->count; i++)
        p->slots[i].src = &data_021C8440[i];
    for (i = 0; i < p->count; i++) {
        descs[i].f0 = p->slots[i].src->id;
        descs[i].x = p->slots[i].src->x;
        descs[i].y = p->slots[i].src->y;
        descs[i].h8 = p->slots[i].src->h8;
    }
    descs[3].ha = p->f48;
    descs[3].hc = p->f44;
    descs[3].he = p->f4c;
    descs[3].h10 = 3;
    descs[3].h12 = 3;
    descs[3].h14 = 7;
    descs[3].f18 = 0;
    descs[3].f1c = 0x54a;
    descs[4].ha = p->f48;
    descs[4].hc = p->f44;
    descs[4].he = p->f4c;
    descs[4].h10 = 2;
    descs[4].h12 = 2;
    descs[4].h14 = 6;
    descs[4].f18 = 0;
    descs[4].f1c = 0x54a;
    descs[5].ha = p->f48;
    descs[5].hc = p->f44;
    descs[5].he = p->f4c;
    descs[5].h10 = 1;
    descs[5].h12 = 1;
    descs[5].h14 = 5;
    descs[5].f18 = 0;
    descs[5].f1c = 0x54a;
    descs[6].ha = p->f48;
    descs[6].hc = p->f44;
    descs[6].he = p->f4c;
    descs[6].h10 = 0;
    descs[6].h12 = 0;
    descs[6].h14 = 4;
    descs[6].f18 = 0;
    descs[6].f1c = 0x54a;
    func_02082BCC(&list, 0, sizeof(list));
    list.descs = descs;
    list.count = 9;
    list.owner = p->f28;
    list.channel = 1;
    list.pal = 0xd;
    list.objPal = 8;
    list.kind = 2;
    p->mgr = func_021BD148(&list, p->heap);
    for (i = 0; i < p->count; i++)
        p->slots[i].obj = func_021BD3C0((void *)p->mgr, p->slots[i].src->id);
    if (p->f4 == 0) {
        for (i = 0; i < 9; i++)
            func_021BD3CC(p->mgr, p->slots[i].src->id, data_021C83A4[i]);
        func_021BD378(p->mgr, p->slots[3].src->id, 0);
    }
    v = func_021BE300(p->f18);
    if (v != 9)
        func_021BD368(p->mgr, p->slots[v].src->id, 0);
    func_021BE128(p);
    func_021BE170((struct Ov208Scene *)p);
    if (p->f40 == 0) {
        func_021BD378(p->mgr, p->slots[8].src->id, 0);
        func_021BD378(p->mgr, p->slots[7].src->id, 0);
    }
}









void func_021BDFA8(struct Ov208Scene *e)
{
    if (e->mgr != 0) {
        func_021BE1BC(e);
        func_021BE16C(e);
        func_021BD208(e->mgr);
        func_0204ADA4((u32)e->f44);
        func_0204A8D4((u32)e->f48);
        func_0204AFD8((u32)e->f4c);
    }
    e->mgr = 0;
}









void func_021BDFDC(struct Ov208Scene *m)
{
    u32 sel = 9;
    u32 trg = func_020362DC();
    u32 held = func_0203633C();
    u32 a;
    u32 b;
    u32 c;
    volatile u32 d; /* volatile on purpose: image spills it to the stack and re-reads it */
    u8 i;
    if (held & 0x20) {
        switch (m->f18) {
        case 0:
            if (func_021BD388(m->mgr, m->slots[3].src->id))
                sel = 3;
            else
                sel = 4;
            break;
        case 1:
            sel = 6;
            break;
        case 2:
            sel = 5;
            break;
        case 3:
            sel = 4;
            break;
        }
    } else if (held & 0x10) {
        switch (m->f18) {
        case 0:
            sel = 5;
            break;
        case 1:
            sel = 4;
            break;
        case 2:
            if (func_021BD388(m->mgr, m->slots[3].src->id))
                sel = 3;
            else
                sel = 6;
            break;
        case 3:
            sel = 6;
            break;
        }
    }
    if (sel != 9)
        func_021BD3F8(m->mgr, m->slots[sel].src->id);
    if ((trg & 0xc0) == 0) {
        if (held & 0x40)
            func_021BD3F8(m->mgr, m->slots[8].src->id);
        else if (held & 0x80)
            func_021BD3F8(m->mgr, m->slots[7].src->id);
    }
    a = func_021BDB08((const struct State *)m);
    b = func_021BDB54((const struct State *)m);
    if (a != 0) {
        c = func_021BE32C(a);
        d = func_021BE378(a);
        if (c != 9 && d != 4) {
            for (i = 3; i <= 6; i++)
                func_021BD368(m->mgr, m->slots[i].src->id, i != c);
            m->f1c = d;
            func_021BE170((struct Ov208Scene *)((struct Ov208Scene *)m));
        }
    }
    if (b != 0) {
        switch (b) {
        case 15:
        case 16:
        case 17:
        case 18:
            func_021BE1BC((struct Ov208Scene *)m);
            break;
        }
    }
}










void ov208_func_021BE128(u8 *p)
{
    struct Ov208Pltt *pltt;
    u32 file;
    u8 *data;

    file = (u32)func_02049F34(0x9f, 3, (u32)(&pltt), ((struct Obj14652 *)p)->f0);
    data = pltt->data;
    func_02082D44(data + 0x20, p + 0xb6, 0x20);
    func_02082D44(data + 0x60, p + 0xd6, 0x20);
    func_020307B0((void *)file);
    ((struct Obj14652 *)p)->f118 = 0;
}










/*
 * Empty stub; the listing pads it with two zero bytes.
 */
void func_021BE16C(struct Ov208Scene *e)
{
}








void ov208_func_021BE170(struct Ov208Scene *p)
{
    u32 idx = 9;

    switch (p->f1c) {
    case 0:
        idx = 6;
        break;
    case 1:
        idx = 5;
        break;
    case 2:
        idx = 4;
        break;
    case 3:
        idx = 3;
        break;
    }
    if (idx != 9)
        func_0204B6F4((struct Obj *)func_021BD3C0(p->mgr, p->slots[idx].src->id), 2, 0);
}








void ov208_func_021BE1BC(struct Ov208Scene *p)
{
    int slot = 9;

    switch (p->f1c) {
    case 0:
        slot = 6;
        break;
    case 1:
        slot = 5;
        break;
    case 2:
        slot = 4;
        break;
    case 3:
        slot = 3;
        break;
    }
    if (slot != 9) {
        func_0204B6F4((struct Obj *)func_021BD3C0(p->mgr, p->slots[slot].src->id), 0, 0);
        p->f1c = 4;
    }
}







s32_021BD574 func_021BE20C(struct Ov208Scene *m)
{
    s16_021BE20C t;
    u8 i;
    if (m->phase + 0x400 >= 0x10000)
        m->phase -= 0xfc00;
    else
        m->phase += 0x400;
    t = (tbl_020A1B38[2 * (m->phase >> 4) + 1] + 0x1000) / 2;
    for (i = 0; i < 16; i++) {
        u16 c1 = m->palA[i];
        u16 c2 = m->palB[i];
        u8 r1 = c1 & 0x1f;
        u8 g1 = (c1 & 0x3e0) >> 5;
        u8 b1 = (c1 & 0x7c00) >> 10;
        u8 r2 = c2 & 0x1f;
        u8 g2 = (c2 & 0x3e0) >> 5;
        u8 b2 = (c2 & 0x7c00) >> 10;
        u8 r = r1 + ((r2 - r1) * t >> 12);
        u8 g = g1 + ((g2 - g1) * t >> 12);
        u8 b = b1 + ((b2 - b1) * t >> 12);
        m->palOut[i] = r | g << 5 | b << 10;
    }
    return func_02061CA4((void *)14, 0x1a0, (u32)m->palOut, 0x20);
}







/*
 * Returns 6, 5, 4 or 3 for the four known kinds and 9 for anything else.
 */
int func_021BE300(int kind)
{
    switch (kind) {
    case 0:
        return 6;
    case 1:
        return 5;
    case 2:
        return 4;
    case 3:
        return 3;
    }
    return 9;
}







/*
 * trailing: 021BE376..021BE378 is two-byte zero alignment padding.
 */
unsigned func_021BE32C(unsigned n)
{
    switch(n) {
    case 0: break;
    case 6: case 15: return 6;
    case 7: case 16: return 5;
    case 8: case 17: return 4;
    case 9: case 18: return 3;
    default: break;
    }
    return 9;
}







/*
 * trailing: 021BE3C2..021BE3C4 is two-byte zero alignment padding.
 */
unsigned func_021BE378(unsigned n)
{
    switch(n) {
    case 0: break;
    case 6: case 15: return 0;
    case 7: case 16: return 1;
    case 8: case 17: return 2;
    case 9: case 18: return 3;
    default: break;
    }
    return 4;
}








void ov208_func_021BE3C4(struct Ov208Scene *p)
{
    struct Ov208ActList list;
    struct Ov208ActDesc descs[1];
    void *h;
    u8 i;

    h = func_020490F4(0x55, p->heap);
    p->f50 = func_0204AC18(h, 2, 0, 0x160, 2, 3, p->heap);
    p->f54 = func_0204A6C8(h, 8, 0, 0, p->heap);
    p->f58 = func_0204AF28(h, 0xc, 0x13, p->heap);
    func_02049238(h);
    p->count = 1;
    for (i = 0; i < p->count; i++)
        p->slots[i].src = &data_021C8390[i];
    for (i = 0; i < p->count; i++) {
        descs[i].f0 = p->slots[i].src->id;
        descs[i].x = p->slots[i].src->x;
        descs[i].y = p->slots[i].src->y;
        descs[i].h8 = p->slots[i].src->h8;
    }
    func_02082BCC(&list, 0, sizeof(list));
    list.descs = descs;
    list.count = 1;
    list.owner = p->f28;
    list.channel = 1;
    list.pal = 0xd;
    list.objPal = 8;
    list.kind = 2;
    p->mgr = func_021BD148(&list, p->heap);
    for (i = 0; i < p->count; i++)
        p->slots[i].obj = func_021BD3C0(p->mgr, p->slots[i].src->id);
}






void func_021BE4DC(struct Ov208Scene *e)
{
    if (e->mgr != 0) {
        func_021BD208(e->mgr);
        func_0204ADA4((u32)e->f50);
        func_0204A8D4((u32)e->f54);
        func_0204AFD8((u32)e->f58);
    }
    e->mgr = 0;
}







void ov208_func_021BE504(struct Ov208Scene *p)
{
    struct Ov208ActList list;
    struct Ov208ActDesc descs[6];
    struct Ov208ActDesc *d;
    void *h;
    u8 i;

    h = func_020490F4(0x9f, p->heap);
    p->f5c = func_0204AC18(h, 3, 0, 0x160, 0, 3, p->heap);
    p->f60 = func_0204A6C8(h, 0xd, 0, 0, p->heap);
    p->f64 = func_0204AF28(h, 0x1b, 0x2c, p->heap);
    func_02049238(h);
    p->count = 6;
    for (i = 0; i < p->count; i++)
        p->slots[i].src = &data_021C83C8[i];
    for (i = 0; i < p->count; i++) {
        descs[i].f0 = p->slots[i].src->id;
        descs[i].x = p->slots[i].src->x;
        descs[i].y = p->slots[i].src->y;
        descs[i].h8 = p->slots[i].src->h8;
    }
    d = &descs[3];
    d->ha = p->f60;
    d->hc = p->f5c;
    d->he = p->f64;
    d->h10 = 0xe;
    d->h12 = 0xe;
    d->h14 = 0x14;
    d->f18 = 1;
    d->f1c = 0x54c;
    func_02082BCC(&list, 0, sizeof(list));
    list.descs = descs;
    list.count = 6;
    list.owner = p->f28;
    list.channel = 1;
    list.pal = 0xd;
    list.objPal = 8;
    list.kind = 2;
    p->mgr = func_021BD148(&list, p->heap);
    for (i = 0; i < p->count; i++)
        p->slots[i].obj = func_021BD3C0(p->mgr, p->slots[i].src->id);
    func_021BD394(p->mgr, p->slots[1].src->id, 0x110);
    func_021BD394(p->mgr, p->slots[2].src->id, 0x220);
    if (p->f40 == 0) {
        func_021BD378(p->mgr, p->slots[5].src->id, 0);
        func_021BD378(p->mgr, p->slots[4].src->id, 0);
    }
}







void func_021BE680(char *p)
{
    if (*(int *)&((struct Obj01081 *)p)->f30 != 0) {
        func_021BD208((struct Ov208Mgr *)(*(int *)&((struct Obj01081 *)p)->f30));
        func_0204ADA4(((struct Obj01081 *)p)->f5C);
        func_0204A8D4(((struct Obj01081 *)p)->f60);
        func_0204AFD8(((struct Obj01081 *)p)->f64);
    }
    *(int *)&((struct Obj01081 *)p)->f30 = 0;
}






void func_021BE6A8(char *p)
{
    unsigned held=func_020362DC();
    unsigned keys=func_0203633C();
    if(!(held&0x3f0)) {
        if(keys&0x40) func_021BD3F8(((struct Obj03931 *)p)->f30,**(int * *)&((struct Obj03931 *)p)->f94);
        else if(keys&0x80) func_021BD3F8(((struct Obj03931 *)p)->f30,**(int * *)&((struct Obj03931 *)p)->f8C);
        else if(keys&0x220) func_021BD3F8(((struct Obj03931 *)p)->f30,**(int * *)&((struct Obj03931 *)p)->f7C);
        else if(keys&0x110) func_021BD3F8(((struct Obj03931 *)p)->f30,**(int * *)&((struct Obj03931 *)p)->f74);
    }
}






struct Ov208Icon_021BE710 *func_021BE710(u16 heap,unsigned arg)
{
    struct Ov208Icon_021BE710 *p=func_02030734(heap,0x34,1,d_021C8DFC,120);
    p->heap=heap;p->f4=arg;p->f8=0;p->fc=5;
    func_02040618(5,3,24);
    func_0204047C(5,0);
    func_021BE868((struct Ov208Gfx *)p);
    func_021BE920(p);
    p->f28=(unsigned)func_020056A0((unsigned)func_021BE864,(unsigned)p,1);
    p->f2c=func_0201C440((void *)(unsigned)p->heap);
    p->f30=0;
    return p;
}






/*
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
void func_021BE778(struct Ov208Scene *m)
{
    func_0201C6EC((void *)m->f2c);
    func_0201C4C0((struct PrintSys *)m->f2c);
    func_02030EAC((struct Node *)m->f28);
    func_021BE9C8(m);
    func_021BE8FC((char *)m);
    func_020307B0(m);
}






/*
 * matching: direct byte field access avoids a persistent extracted pointer register.
 */
void func_021BE7A4(struct Ov208Icon_021BE7A4 *p)
{
    switch(p->f8) {
    case 0: case 2: break;
    case 1:
        if(p->count==0) {
            if((int)func_02040804(5)<=0) {
                func_02041EE4(5,3,0);p->f8=2;
            } else {func_02041EE4(5,5,3);p->count=0;}
        } else --p->count;
        break;
    case 3:
        if(p->count==0) {
            if((int)func_02040804(5)>=24) {
                func_02041EE4(5,3,24);p->f8=0;
            } else {func_02041EE4(5,4,3);p->count=0;}
        } else --p->count;
        break;
    }
    func_021BE9CC(p);
    func_0201C4E4((struct PrintSys *)p->f2c);
}








void ov208_func_021BE82C(struct Ov208Icon_021BE82C *p, int kind)
{
    p->fc = kind;
    func_021BE9C8();
    ov208_func_021BE920((struct Ov208Icon *)p);
}








int ov208_func_021BE840(struct Ov208Icon_021BE840 *p)
{
    return p->state;
}








void ov208_func_021BE844(struct Ov208Icon_021BE844 *p)
{
    if (p->state != 2) {
        p->state = 1;
        p->step = 0;
    }
}








void ov208_func_021BE854(struct Ov208Icon_021BE854 *p)
{
    if (p->state != 0) {
        p->state = 3;
        p->step = 0;
    }
}







void ov208_func_021BE864(void *p)
{
}







/*
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
void func_021BE868(struct Ov208Gfx *g)
{
    g->f14 = func_020450F0(5, 0, 0, 0x10, 1, 13, 0);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)g->f14)), 0);
    func_02045334((struct Descriptor *)g->f14);
    g->f18 = func_0204384C(0x9f, 14, 0, g->heap);
    g->f20 = func_020437EC(g->f18);
    g->f1c = func_02040B58(5, func_020437D4(g->f18), g->f20);
    func_0204994C(0x9f, 0x25, 5, 0, g->f1c, 0xc0, 0, g->heap);
    func_020413B0(5, 0, 0, 0x20, 0x18, 13);
    g->f24 = (int)func_02045B38(0, 2, 0xea, g->heap);
}








void func_021BE8FC(char *p)
{
    func_02045C04((struct Rec *)(((struct Obj05867 *)p)->f24));
    func_0203FB44(5, ((struct Obj05867 *)p)->f1C, ((struct Obj05867 *)p)->f20);
    func_020437AC((struct Obj020437AC *)(((struct Obj05867 *)p)->f18));
    func_020452E8((struct Descriptor *)(((struct Obj05867 *)p)->f14));
}









void ov208_func_021BE920(struct Ov208Icon *p)
{
    struct Ov208PalTbl pal;
    void *h;
    u32 s;

    if (p->fc < 0 || p->fc >= 5)
        return;
    h = func_020490F4(0x9f, p->heap);
    pal = data_021C84F4;
    func_02049BDC(h, 4, 4, pal.v[p->fc] << 5, 0x1a0, 0x20, p->heap);
    func_02049238(h);
    h = func_0204384C(0x9f, 0xe, 0, p->heap);
    func_02043814(h, (const struct Bmp *)p->f18);
    func_020437AC(h);
    s = (u32)func_02045EC0((struct MsgBank *)p->f24, p->fc + 0xb2);
    func_0201C724((void *)p->f2c, p->f18, 0x18, 5, s, p->f4, 0x3dc0);
    func_02045808((struct U16Vec *)s);
    p->f30 = 1;
    ov208_func_021BE9CC(p);
}








void func_021BE9C8()
{
}









void ov208_func_021BE9CC(struct Ov208Icon *p)
{
    if (p->f30 != 0 && func_0201C6C4((struct PrintSys *)p->f2c, (void *)p->f18) == 0) {
        func_02040B1C(5, func_020437D4((const struct Bmp *)p->f18), p->f20, p->f1c);
        func_02041B6C(5);
        p->f30 = 0;
    }
}









void ov208_func_021BEA00(u16 *p, u16 v)
{
    *p = v;
}








/*
 * 2026-10-04 (D2-16): callback func_021BEF9C filed EXACT as src/matched/ov/ov208_func_021BEF9C.c (empty void function, bx lr). Still MATCH only
 * because no shard witnesses it yet; the integrator manifest run should make this EXACT. Symbols line now carries the ov208 hint.
 * 2026-10-02: only func_021BEF9C (task callback, no witness yet) blocks EXACT; bytes match.
 */
int func_021BEA04(void *owner, int unused, u16 *heap)
{
    struct Ov208Main *s;
    func_02034AC4((u32)ov067_id);
    func_02034AC4((u32)ov206_id);
    s = func_021BC32C(owner, 0x120, *heap);
    func_02082BCC(s, 0, 0x120);
    s->task = (int)func_020056A0((unsigned)func_021BEF9C, (unsigned)s, 1);
    s->f94 = 6;
    s->f98 = 6;
    s->f10c = 0;
    s->fc = func_021BC448(*heap);
    s->f10 = func_021BC448(*heap);
    func_021BC518(s->fc);
    func_021BC518(s->f10);
    func_021BC508(0, s->fc);
    func_021BC508(1, s->f10);
    s->f14 = 0;
    s->f18 = 1;
    return 1;
}








/*
 * matching: full-width stack argument reloads; small pool operands are overlay ID symbols.
 * Caller visibly supplies third arguments to helpers and a live r0 to BC464.
 */
int func_021BEA90(char *first,unsigned unused,int owner,char *q,unsigned heap)
{
    func_021BF63C(owner,q,heap);func_021BF61C(owner,q,heap);
    func_021BA2CC(*(char * *)&((struct Obj03362 *)q)->f8);func_021BA2CC(*(char * *)&((struct Obj03362 *)q)->f4);
    func_021BF41C(owner,q,heap);
    func_0201D83C(((struct Obj03362 *)q)->f110);
    func_02045C04(*(struct Rec * *)&((struct Obj03362 *)q)->f11C);
    func_02045C04(*(struct Rec * *)&((struct Obj03362 *)q)->f118);
    func_02045C04(*(struct Rec * *)&((struct Obj03362 *)q)->f114);
    func_021BC464(((struct Obj03362 *)q)->f10);func_021BC464(((struct Obj03362 *)q)->fC);
    func_02030EAC(*(struct Node * *)&((struct Obj03362 *)q)->f0);func_021BC34C(first);
    func_02034A5C((int)ov206_id);func_02034A5C((int)ov067_id);return 1;
}







/*
 * 2026-10-05 (wD8 lane04): EXACT. The three "ov093" callees are in ov206 (matched there, co-resident with
 *   ov208 as in the matched siblings 021BEA04/021BEA90); the region token on their symbols lines is ov206.
 * 2026-10-05 (D5-03): MATCH. Byte-correct except the five calls to the ov093 callees 0x021B9E68,
 *   0x021BA7C8, 0x021BA374 (no witness label; ov093 below 0x021D4000, pengy). Fixes: the colour loop
 *   calls are func_02040618(i, 0, 0) and (i, 3, 0) (the draft passed i; the image keeps the 0 in r7, which
 *   is why ctx left r7), the first 9E68 call passes (2, 0, 1), locals v54 before v50 before w, the
 *   021BDAD0 test written `!= 2` first, and case 4 writes `*state = 5` in both arms.
 * 2026-10-04 (wD2 lane19): also tried ctx as a one-field struct by value and as u32 with casts: no change (frame 0x74/0x78 vs 0x70,
 *   ctx still in r7). Residue unchanged: image stores ctx back to [sp,#0x88] at entry and keeps state at [sp,#0x34], r7 free.
 * 2026-10-05 (wave D4 lane 02): frame layout check: image has v40 at sp+0x40, v44 0x44, w 0x48, v50 0x50,
 *   v54 0x54, tbl 0x58 (frame 0x70). Ours puts two spilled constant temps (0x17+0xfd and 0xf5+0x27, the
 *   msg field offsets) at 0x40/0x44 because ctx holds r7, so everything shifts by 8 (frame 0x78). Tried:
 *   both state and ctx `*volatile` (882 bytes, worse). Root residue is still ctx kept in r7 instead of its
 *   home slot. Also blocked: func_021B9E68, func_021BA7C8, func_021BA374 have no label (ov093 low, pengy).
 * 2026-10-02 (lane C2-01): control flow, callees and frame layout recovered (tbl[6] at sp+0x58 gives the 0x70 frame);
 * the six-state task body is complete. Still DIFF in register allocation: the image keeps the stack argument ctx in
 * its home slot [sp,#0x88] (reloaded at every use, stored back once at entry) and state in [sp,#0x34], leaving r7
 * free for hoisted constants (0x17 and 0xf5 bases in the font/message setup). Here ctx lands in r7 and the setup
 * spills those constants. Tried: int *volatile ctx (state then takes r7).
 * Also unresolved: func_021B9E68, func_021BA7C8, func_021BA374 (ov093 below 0x021D4000, not ours).
 */
int func_021BEB18(void *unused, int *state, struct Ov208Heap *h, struct Ov208Scn *p, int *ctx)
{
    void *scn = (void *)func_021BC3B4(ctx);
    void *icon = (void *)func_021BC3B8((char *)ctx);
    int v40;
    int v44;
    u32 v54;
    u32 v50;
    u16 w[4];
    u32 tbl[6];
    u8 i;
    int t;
    switch (*state) {
    case 0:
        *state = 1;
        p->font = func_0201D7EC(0x17, 0, 1, 0, h->heap);
        p->msg0 = func_02045B38(1, 2, 0x104, h->heap);
        p->msg1 = func_02045B38(1, 2, 0xf5, h->heap);
        p->msg2 = func_02045B38(1, 2, 0x10c, h->heap);
        for (i = 0; i <= 7; i++) {
            if (i != 1 && i != 5) {
                func_02040618(i, 0, 0);
                func_02040618(i, 3, 0);
                func_020414AC(i);
            }
        }
        if (func_021BDAD0(scn) != 2) {
            func_021BDAAC(scn, 0, 0, func_021BC3BC(ctx) > 1);
            func_021BDAD4(scn, 0);
        } else {
            func_021BDBB8(scn, 0);
        }
        func_021BDC48(scn, 0);
        func_021BDC14(scn, func_02012BF8(func_021BC3A4(ctx), 0x11));
        if (func_021BE840(icon) != 2) {
            func_021BE82C(icon, 0);
            func_021BE844(icon);
        }
        func_021BF308((u16 *)h, (char *)p, (int)ctx);
        t = (int)func_0200CA1C((void *)func_021BC3A4(ctx));
        v40 = func_021BCF4C((char *)func_021BC3A8(ctx));
        v44 = func_0200CA70((void *)t);
        func_021BF4FC((const u16 *)h, (u8 *)p, (int *)ctx, &w[3], &w[2], &w[1], &w[0], &v54, &v50, tbl);
        p->f4 = func_021B9E68(h->heap, w[3], w[2], w[1], w[0], v54, v44, v50, 2, 0, 1, v40, (u32)p->font, func_021BC3B0(ctx), (u32)p->msg0, (u32)p->msg1, (u32)p->msg2);
        p->f8 = func_021B9E68(h->heap, w[3], w[2], w[1], w[0], v54, v44, v50, 2, 1, 1, v40, (u32)p->font, func_021BC3B0(ctx), (u32)p->msg0, (u32)p->msg1, (u32)p->msg2);
        func_021BA7C8(p->f8);
        func_021BF4C4((int)h, (char *)p, (int)ctx, (int *)tbl);
        func_021BF5B8((u16 *)h, (u8 *)p, ctx);
        func_021BF620(h, (int *)p, ctx);
        break;
    case 1:
        *state = 2;
        func_021BC4D8(p->fc);
        func_021BC4D8(p->f10);
        break;
    case 2:
        if (func_021BC4C8(p->fc) == 0 && func_021BDAD0(scn) == 2 && func_021BE840(icon) == 2) {
            func_021BDBA0(scn);
            func_021BDC48(scn, 1);
            *state = 3;
        }
        break;
    case 3:
        if (p->f14 != 0) {
            *state = 4;
            func_021BC4E4(p->fc);
            func_021BC4E4(p->f10);
            func_021BE854(icon);
            if (p->f14 == 2)
                func_021BDAE8(scn, 0);
        } else if (p->f18 != 0) {
            if (func_021BEFA0(h, (struct S_021BEFA0 *)((struct S *)p), ctx) == 0)
                func_021BF088(h, (char *)p, (int)ctx);
        }
        break;
    case 4:
        if (func_021BC4C8(p->fc) == 0 && func_021BC4C8(p->f10) == 0 && func_021BE840(icon) == 0) {
            if (p->f14 == 2) {
                if (func_021BDAD0(scn) == 0)
                    *state = 5;
            } else {
                *state = 5;
            }
        }
        break;
    case 5:
        return 1;
    }
    if (*state >= 2) {
        func_021BF450(h, (char *)p, (int)ctx);
        func_021BA374(p->f4);
        func_021BA374(p->f8);
        if (p->f94 == 6)
            func_021BF664(h, p, ctx);
    }
    func_021BC46C(p->fc, p->f10);
    return 0;
}










void func_021BEE70(void *a0, void *a1, void *heap, struct S_021BEE70 *st, int *obj, int key)
{
    int sc;
    u32 flag;

    if (st == 0) {
        return;
    }
    sc = func_021BC3B4(obj);
    flag = 0;
    switch (key) {
    case 15:
        break;
    case 10: case 11: case 12: case 13: case 14: case 16: case 17: case 18:
        st->f18 = flag;
        break;
    }
    switch (key) {
    case 1: case 2: case 3: case 4: case 5: case 7: case 8: case 9:
        flag = 1;
        st->f18 = flag;
        break;
    }
    switch (key) {
    case 12: {
        u16 old = func_021BC3C0(obj);
        func_021BC3CC((char *)obj);
        if (old != func_021BC3C0(obj)) {
            func_021BF1D0(heap, (char *)st, obj);
        }
        break;
    }
    case 13: {
        u16 old = func_021BC3C0(obj);
        func_021BC40C((struct Ov208Cur *)obj);
        if (old != func_021BC3C0(obj)) {
            func_021BF1D0(heap, (char *)st, obj);
        }
        break;
    }
    }
    switch (key) {
    case 0:
        break;
    case 1: case 2:
        st->f14 = 2;
        return;
    case 7: case 8: case 9:
        st->f14 = 1;
        return;
    case 3:
        func_021BDBA0((void *)sc);
        return;
    case 4:
        func_021BDBA0((void *)sc);
        return;
    case 5:
        func_02012BE0((void *)func_021BC3A4(obj), 0x11, func_021BDC2C((char *)sc));
        func_021BDBA0((void *)sc);
        return;
    default:
        if (flag != 0) {
            func_021BDBA0((void *)sc);
        }
        break;
    }
}









void func_021BEF9C(void *p)
{
}









/*
 * note (2026-10-05, integrator): EXACT. The rect bytes are read through a byte pointer with the offset in a local (k = 0x20, c[k] .. c[k + 3]), as in ov208 021C6760; the byte loads then come before x.
 * 2026-10-04 (D2-16): also tried positive forms `x0 <= x && x < x0+w` (13 bytes out, shape changes) and `x0 > x` with u32 or int casts and
 * no locals (13 to 15 bytes out). With `x0 > x` the compare order is right but x0 lands in r0 and x in r1 (the image has x0 in r1);
 * with `x < x0` the registers are right and the compare order flips. The residue is one register colour pair.
 * note:     2026-10-04 (D1-08): f2c store fixed by raw `*(u32 *)((u8 *)st + st->cur * 0x14 + 0x2c) = 1`. Now 4 bytes: the two
 *            bounds tests are `cmp x0,x; bhi` in the image (x0 in r1, x in r0) and `cmp x,x0; blo` here (same registers). Writing
 *            `e->x0 > x` instead flips the registers (x0 in r0) but keeps the compare order; neither gives the image.
 * note:     2026-10-02 lane C2-02: two compare directions (image: cmp x0,x then bhi) and the f2c store constant order differ; tried x0<=x, !(x0>x), locals.
 *
 * 2026-10-05 (D4-18): still 4 bytes. Tried: positive form x >= x0 && x < x0 + w (4 bytes, same as now), !(e->x0 > x || ...) (13 bytes: x0 lands in r0), int-cast compares (17 bytes, bgt). The compare order of the image needs x0 in r1 with the unsigned-greater test; every spelling that gives that order puts x0 in r0.
 */
int func_021BEFA0(void *a0, struct S_021BEFA0 *st, int *obj)
{
    int sc;
    int res;
    u32 x;
    u32 y;
    u8 i;
    struct E *e;
    u8 *c;
    int k;

    sc = func_021BC3B4(obj);
    res = 0;
    if (st->cur == 6 && func_02035D20(&x, &y) != 0) {
        for (i = 0; i < 6; i++) {
            e = (struct E *)((u8 *)st + i * 0x14);
            c = (u8 *)e;
            k = 0x20;
            if (func_0204B3F4((struct Obj *)e->h1c) != 0
                && (u32)c[k] <= x && x < (u32)c[k] + c[k + 2]
                && (u32)c[k + 1] <= y && y < (u32)c[k + 1] + c[k + 3]) {
                if (st->prev == i) break;
                st->cur = i;
                res = 1;
                break;
            }
        }
    }
    if (res != 0) {
        ov208_func_021BF280(a0, (char *)st, obj, st->cur);
        *(u32 *)((u8 *)st + st->cur * 0x14 + 0x2c) = 1;
        e = (struct E *)((u8 *)st + st->cur * 0x14);
        func_0204B878((struct Obj *)e->h1c, e->f26);
        func_020061E4(0x54a);
        func_020355D8(1);
        func_021BDC48((void *)sc, 0);
    }
    return res;
}







int func_021BF088(void *first,char *p,int key)
{
    void *scene;
    int changed;
    u32 buttons,press;
    u8 i,next;
    scene=(void *)func_021BC3B4((int *)key);
    changed=0;
    if(((struct Obj00442 *)p)->f94==6) {
        buttons=func_0203633C();
        press=func_020362DC();
        if(((struct Obj00442 *)p)->f98==6) {
            if((buttons&0x300)||(press&1)) {
                for(i=0;i<6;i++) {
                    if(func_0204B3F4(*(struct Obj **)((u32)p+(u32)i*20+0x1c))!=0) {
                        ((struct Obj00442 *)p)->f94=i; changed=1; break;
                    }
                }
            }
        } else if((buttons&0x100)||(press&1)) {
            for(i=1;i<6;i++) {
                next=(((struct Obj00442 *)p)->f98+i)%6;
                if(func_0204B3F4(*(struct Obj **)((u32)p+(u32)next*20+0x1c))!=0) {
                    ((struct Obj00442 *)p)->f94=next; changed=1; break;
                }
            }
        } else if(buttons&0x200) {
            for(i=1;i<6;i++) {
                next=(((struct Obj00442 *)p)->f98+6-i)%6;
                if(func_0204B3F4(*(struct Obj **)((u32)p+(u32)next*20+0x1c))!=0) {
                    ((struct Obj00442 *)p)->f94=next; changed=1; break;
                }
            }
        }
    }
    if(changed!=0) {
        func_021BF280(first,p,(void *)key,((struct Obj00442 *)p)->f94);
        *(u32 *)((u32)p+*(u32 *)&((struct Obj00442 *)p)->f94*20+0x2c)=1;
        func_0204B878(*(struct Obj **)((u32)p+*(u32 *)&((struct Obj00442 *)p)->f94*20+0x1c),*(u16 *)((u32)p+*(u32 *)&((struct Obj00442 *)p)->f94*20+0x26));
        func_020061E4(0x54a);
        func_020355D8(0);
        func_021BDC48((void *)((int)scene), 0);
    }
    return changed;
}







/*
 * matching: initialize the flag after the output-producing call to keep its zero-cost schedule.
 * Third helper arguments are explicitly live in the original caller.
 */
void func_021BF1D0(void *first,char *q,void *third)
{
    struct Params p;
    int okay,index;
    func_021BF4FC(first,(u8 *)q,(int *)third,&p.d,&p.c,&p.b,&p.a,&p.y,&p.x,p.arr);
    okay=1;
    func_021BA550(((struct Obj00442 *)q)->f4,p.d,p.c,p.b,p.a,p.y,p.x);
    index=((struct Obj00442 *)q)->f98;
    if(index!=6) {
        if(p.arr[index]!=0) okay=0;
        else {func_021BF63C((int)first, q, (unsigned)third);((struct Obj00442 *)q)->f98=6;}
    }
    if(okay) func_021BA7C8(((struct Obj00442 *)q)->f8);
    else func_021BA6B0(((struct Obj00442 *)q)->f8,p.d,p.c,p.b,p.a,p.y,p.x,((struct Obj00442 *)q)->f98);
    func_021BF4C4((int)first,q,(int)third,(int *)p.arr);
}







void func_021BF280(void *first,char *q,void *third,int next)
{
    struct Params p;
    int current=((struct Obj00442 *)q)->f98;
    if(current!=next) {
        if(current==6) {
            func_021BF4FC(first,(u8 *)q,(int *)third,&p.d,&p.c,&p.b,&p.a,&p.y,&p.x,p.arr);
            func_021BA6B0(((struct Obj00442 *)q)->f8,p.d,p.c,p.b,p.a,p.y,p.x,next);
            func_021BA814(((struct Obj00442 *)q)->f8);
        } else func_021BA64C(((struct Obj00442 *)q)->f8,next);
        func_021BF63C((int)first, q, (unsigned)third);((struct Obj00442 *)q)->f98=next;
        func_021BF620(first,(int *)q,third);
    }
}




void func_021BF308(u16 *heap, char *p, int key)
{
    struct Pos_021BD574 pos;
    void *scene;
    int owner;
    void *arc;
    enum Index i;
    u16 flag;
    scene = (void *)func_021BC3B4((int *)key);
    owner = func_021BCF4C((char *)func_021BC3A8((int *)key));
    i = 0;
    arc = func_020490F4(0x9f, *heap);
    ((struct Obj05538 *)p)->f9C = func_021BDC80(scene);
    ((struct Obj05538 *)p)->fA0 = func_0204A6C8(arc, 0xd, 0, 0, *heap);
    ((struct Obj05538 *)p)->fA4 = func_0204AF28(arc, 0x1b, 0x2c, *heap);
    func_02049238(arc);
    flag = (u16)i;
    do {
        char *q;
        const u8 *t;
        func_02082BCC(&pos, 0, 8);
        t = d_021C851C + i * 9;
        q = p + i * 20;
        q[0x20] = t[2];
        q[0x21] = t[3];
        q[0x22] = t[4];
        q[0x23] = t[5];
        ((struct Obj02254 *)q)->f24 = t[6];
        ((struct Obj02254 *)q)->f26 = t[7];
        q[0x28] = t[8];
        ((struct Obj02254 *)q)->f2C = 0;
        pos.x = t[0];
        pos.y = t[1];
        pos.z = ((struct Obj02254 *)q)->f24;
        ((struct Obj02254 *)q)->f1C = (u32)func_0204B294(owner, ((struct Obj05538 *)p)->fA0, ((struct Obj05538 *)p)->f9C, ((struct Obj05538 *)p)->fA4, &pos, flag, *heap);
        func_0204B92C((struct Obj *)((struct Obj02254 *)q)->f1C, 1);
        func_0204B688((struct Actor *)(((struct Obj02254 *)q)->f1C), 1);
        i = (u8)(i + 1);
    } while ((u32)i < 6);
}





/*
 * Releases the sixth 0x14-byte element handle at +0x1C and the two at +0xA0 and +0xA4.
 */
void func_021BF41C(int unused, char *q, u32 a2)
{
    unsigned char i;

    for (i = 0; i < 6; i++)
        func_0204B3B4((struct Obj *)(*(int *)(q + i * 0x14 + 0x1c)));
    func_0204A8D4(((struct Obj12120 *)q)->fA0);
    func_0204AFD8(((struct Obj12120 *)q)->fA4);
}




/*
 * Byte-based state indexing preserves the shared 20-byte stride; u32 indexing changes it to shift/add.
 */
void func_021BF450(void *unused, char *p, int key)
{
    void *scene = (void *)func_021BC3B4((int *)key);
    if (((struct Obj10901 *)p)->f94 != 6) {
        u8 i = ((struct Obj10901 *)p)->f94;
        char *states = p + 0x2c;
        switch (*(unsigned *)(states + i * 20)) {
        case 0: break;
        case 1: *(unsigned *)(states + i * 20) = 2; break;
        case 2:
            if (func_0204B98C(*(struct Actor **)(p + i * 20 + 0x1c)) == 0)
                *(unsigned *)(states + i * 20) = 3;
            break;
        case 3:
            func_0204B878(*(struct Obj **)(p + i * 20 + 0x1c), *(u16 *)(p + i * 20 + 0x24));
            *(unsigned *)(states + i * 20) = 0;
            ((struct Obj10901 *)p)->f94 = 6;
            func_021BDC48(scene, 1);
            break;
        }
    }
}





void func_021BF4C4(int unused, char *q, int c, int *tbl)
{
    unsigned char i;

    for (i = 0; i < 6; i++) {
        func_0204B3DC((struct Obj *)*(int *)(q + i * 0x14 + 0x1c), tbl[i]);
        *(int *)(q + i * 0x14 + 0x2c) = 0;
        func_0204B878((struct Obj *)(*(int *)(q + i * 0x14 + 0x1c)), *(unsigned short *)(q + i * 0x14 + 0x24));
    }
    ((struct Obj18262 *)q)->f94 = 6;
}




/*
 * Species local and CC40/CED4 species arguments are u32: this caller has no u16 truncation before either call.
 */
void func_021BF4FC(const u16 *heap, u8 *p, int *key, u16 *out1, u16 *out2, u16 *out3, u16 *out4, u32 *out5, u32 *out6, u32 *out7)
{
    u32 values[6];
    u32 a, b, c, special, value;
    struct Blk37 *ctx;
    u32 id;
    u8 i;
    ctx = func_0200CA1C((void *)func_021BC3A4(key));
    id = func_021BC3C0(key);
    special = 0;
    func_0200CC40((u8 *)ctx, id, &b, &c, &a, *heap);
    if (id == 327) special = func_0200D288(ctx, special);
    value = func_0200CED4(ctx, id);
    for (i = 0; i < 6; i++) values[i] = func_0200D3C0(ctx, id, p[i * 20 + 0x28]);
    *out1 = id;
    *out2 = a;
    *out3 = b;
    *out4 = c;
    *out5 = special;
    *out6 = value;
    for (i = 0; i < 6; i++) out7[i] = values[i];
}




void func_021BF5B8(u16 *heap, u8 *p, int *ctx)
{
    struct Ov208Pltt *pltt;
    u32 file;
    u8 *data;
    file = (u32)func_02049F34(159, 3, (u32)(&pltt), *heap);
    data = pltt->data;
    func_02082D44(data + 0x20, p + 0xa8, 32);
    func_02082D44(data + 0x60, p + 0xc8, 32);
    func_020307B0((void *)file);
    ((struct Obj25493 *)p)->f108 = 0;
    func_02082D44(p + 0xa8, p + 0xe8, 32);
    func_02061CA4((void *)14, 192, (u32)(p + 0xe8), 32);
}




void func_021BF61C(int unused0, char *unused1, unsigned unused2)
{
}





/*
 * Zeroes word 0x42 and sets word 0x43 when word 0x26 is not 6.
 */
void func_021BF620(struct Ov208Heap *unused, int *p, int *ctx)
{
    if (p[0x26] == 6)
        return;
    p[0x42] = 0;
    p[0x43] = 1;
}





/*
 * Frees the 0x14-byte record at the index held in +0x98.
 */
void func_021BF63C(int unused, char *p, unsigned unused2)
{
    int i = ((struct Obj00442 *)p)->f98;

    if (i == 6)
        return;
    func_0204B6F4((struct Obj *)(*(int *)(p + i * 0x14 + 0x1c)), 0, 0);
    ((struct Obj00442 *)p)->f10C = 0;
}





/*
 * note: 2026-10-05 (D5-03): closed by u8 channel locals for colour A, the store as
 *   r | g << 5 | b << 10 (GX_RGB order) with the three lerps inline, and the f108 wrap
 *   written on the field directly (no x/y locals).
 */
void func_021BF664(struct Ov208Heap *a0, struct Ov208Scn *e, int *ctx)
{
    if (e->f10c != 0) {
        int v = e->f98;

        if (v != 6)
            func_0204B6F4((struct Obj *)(*(int *)((char *)e + v * 0x14 + 0x1c)), 2, 0);
        e->f10c = 0;
    }

    if (e->f108 + 0x400 >= 0x10000)
        e->f108 = e->f108 + 0x400 - 0x10000;
    else
        e->f108 = e->f108 + 0x400;

    {
        unsigned char i;
        int t = e->f108;
        short ratio;

        t = ((t >> 4) << 1) + 1;
        ratio = (tbl_020A1B38[t] + 0x1000) / 2;

        for (i = 0; i < 0x10; i++) {
            unsigned short A = e->srcA[i];
            unsigned short B = e->srcB[i];
            unsigned char g = (A & 0x3e0) >> 5;
            unsigned char r = A & 0x1f;
            unsigned char b = (A & 0x7c00) >> 10;

            e->dst[i] = (unsigned short)((unsigned char)(r + ((ratio * ((unsigned char)(B & 0x1f) - r)) >> 12))
                | ((unsigned char)(g + ((ratio * ((unsigned char)((B & 0x3e0) >> 5) - g)) >> 12)) << 5)
                | ((unsigned char)(b + ((ratio * ((unsigned char)((B & 0x7c00) >> 10) - b)) >> 12)) << 10));
        }

        func_02061CA4((void *)0xe, 0xc0, (int)e->dst, 0x20);
    }
}




void func_021BF784(u16 *p, u16 v)
{
    *p = v;
}




/* Caller explicitly loads r2 for setup helpers whose filed bodies omit it. */
u32 func_021BF788(void *a0,u32 a1,u16 *heap,u32 a3,int key)
{
    u8 *p;
    int save;
    u8 i;
    save = func_021BC3A4((int *)key);
    func_02034AC4((int)ov072_id);
    p = (u8 *)func_021BC32C(a0,0x438,*heap);
    i = 0;
    func_02082BCC(p,0,0x438);
    ((struct Obj00510 *)p)->f0 = func_021BCF4C((char *)func_021BC3A8((int *)key));
    ((struct Obj00510 *)p)->f4 = func_021BC3AC((int *)key);
    for (;i<2;i++) *(u32 *)(p+i*4+0x5c)=0;
    ((struct Obj00510 *)p)->f64=0;
    ((struct Obj00510 *)p)->f8C=0;
    ((struct Obj00510 *)p)->f90=1;
    ((struct Obj00510 *)p)->f94=0;
    ((struct Obj00510 *)p)->f6C=0;
    ((struct Obj00510 *)p)->f70=0;
    ((struct Obj00510 *)p)->f74=0;
    p[0x78]=func_02012984((const struct BigObj *)save);
    p[0x79]=0xff;
    ((struct Obj00510 *)p)->f84=0;
    ((struct Obj00510 *)p)->f88=1;
    ((struct Obj00510 *)p)->f3C8=func_021BBB24(*heap);
    func_021C0048(heap,(char *)p,key);
    ((struct Obj00510 *)p)->f40C=func_020490F4(0xb2,*heap);
    ((struct Obj00510 *)p)->f410=func_020056A0((u32)func_021BFFEC,(u32)p,1);
    p[0x414]=0;
    func_021C06C8(heap,(char *)p,key);
    ((struct Obj00510 *)p)->f418=func_021BC448(*heap);
    ((struct Obj00510 *)p)->f41C=func_021BC448(*heap);
    func_021BC518((int *)(*(u32 * *)&((struct Obj00510 *)p)->f418));
    func_021BC518((int *)(*(u32 * *)&((struct Obj00510 *)p)->f41C));
    func_021BC508(0,(int *)(*(u32 * *)&((struct Obj00510 *)p)->f418));
    func_021BC508(1,(int *)(*(u32 * *)&((struct Obj00510 *)p)->f41C));
    ((struct Obj00510 *)p)->f420=func_021BC560(*heap,0xa);
    ((struct Obj00510 *)p)->f424=0;
    ((struct Obj00510 *)p)->f428=1;
    ((struct Obj00510 *)p)->f42C=0;
    ((struct Obj00510 *)p)->f430=1;
    ((struct Obj00510 *)p)->f434=1;
    return 1;
}




/* Caller explicitly loads r2 for the three-argument teardown helpers. */
u32 func_021BF8E0(void *a0, u32 a1, void *a2, char *p, void *a4)
{
    u8 i;
    func_021C1F44(((struct Obj03933 *)p)->f94);
    for (i = 0; i < 2; i++) {
        char *q = p + i * 4;
        if (((struct Obj08396 *)q)->f5C != 0) func_021C0C00((void *)(((struct Obj08396 *)q)->f4C), (void *)(((struct Obj08396 *)q)->f5C));
        ((struct Obj08396 *)q)->f5C = 0;
    }
    func_021C0B58(a2, p, a4);
    func_021C0950(a2, (u8 *)p, a4);
    func_021C0898(a2, p, a4);
    func_021BC97C(((struct Obj03933 *)p)->f8);
    func_021C06A0(a2, p, a4);
    func_021C0524(a2, p, a4);
    func_021C03C4(a2, p, a4);
    func_021BC61C(((struct Obj03933 *)p)->f420);
    func_021BC464(((struct Obj03933 *)p)->f41C);
    func_021BC464(((struct Obj03933 *)p)->f418);
    func_021C06EC(a2, p, a4);
    func_02030EAC(((struct Obj03933 *)p)->f410);
    func_02049238(((struct Obj03933 *)p)->f40C);
    func_021BBB34(((struct Obj03933 *)p)->f3C8);
    func_021BC34C(a0);
    func_02034A5C((int)ov072_id);
    return 1;
}





int ov208_func_021BF9B0(void *proc, int *seq, u16 *heap, u8 *p, int key)
{
    void *scene;
    void *icon;
    u32 j;
    u32 k;
    u8 i;
    int ready;

    scene = ov208_func_021BC3B4(key);
    icon = ov208_func_021BC3B8(key);
    switch (*seq) {
    case 0:
        *seq = 1;
        func_0207D4B0(1, 5, 0);
        for (j = 0; j < 2; j++) {
            func_020403F4((u8)data_021C85C0[j].bg);
            func_0203FCA0(data_021C85C0[j].bg, &data_021C85C0[j].tmpl, data_021C85C0[j].type);
            func_020414AC(data_021C85C0[j].bg);
            func_02040588(data_021C85C0[j].bg, data_021C85C0[j].on);
        }
        for (i = 0; i <= 7; i++) {
            if (i != 1 && i != 5) {
                func_02040618(i, 0, 0);
                func_02040618(i, 3, 0);
                func_020414AC(i);
            }
        }
        func_0204047C(2, 2);
        func_0204047C(3, 3);
        func_0204047C(0, 1);
        func_0204047C(6, 1);
        func_0204047C(7, 2);
        func_0204047C(4, 3);
        ov208_func_021C0090(heap, p, key);
        ov208_func_021C0134(heap, p, key);
        ov208_func_021C0450(heap, p, key);
        ov208_func_021C0544(heap, p, key);
        W(8) = ov208_func_021BC844(*heap, 1, 4, 9, 10);
        ov208_func_021C0788(heap, p, key);
        ov208_func_021C08E8(heap, p, key);
        ov208_func_021C0B10(heap, p, key);
        ov208_func_021C1AD4(heap, p, key);
        func_0204B688((struct Actor *)(*(u32 *)(p + W(0x64) * 4 + 0x5c)), 1);
        ov208_func_021C0C50(heap, p, key);
        if (W(0x90) == 1)
            ov208_func_021C0C8C(heap, p, key, 1);
        ov208_func_021BC758(W(0x420));
        ov208_func_021BC718(W(0x420));
        break;
    case 1:
        *seq = 2;
        ov208_func_021BC4F4(1, W(0x41c));
        ov208_func_021C24F0(heap, p, key);
        break;
    case 2:
        *seq = 3;
        ov208_func_021BC4D8(W(0x418));
        ov208_func_021BC6D8(W(0x420));
        if (ov208_func_021BDAD0(scene) != 2) {
            ov208_func_021BDAAC(scene, 0, 1, ov208_func_021BC3BC((char *)key) > 1);
            ov208_func_021BDAD4(scene, 0);
        } else {
            ov208_func_021BDBB8(scene, 1);
        }
        func_021BDC48(scene, 0);
        W(0x88) = 0;
        ov208_func_021BDC14(scene, func_02012BF8(ov208_func_021BC3A4(key), 18));
        if (ov208_func_021BE840(icon) != 2) {
            ov208_func_021BE82C(icon, 1);
            ov208_func_021BE844(icon);
        }
        break;
    case 3:
        if (ov208_func_021BC4C8(W(0x418)) == 0 && ov208_func_021BC6C8(W(0x420)) == 0
            && ov208_func_021BDAD0(scene) == 2 && ov208_func_021BE840(icon) == 2) {
            ov208_func_021BDBA0(scene);
            ov208_func_021C2458(heap, p, key);
            ov208_func_021C1D0C(heap, p, key);
            *seq = 4;
        }
        break;
    case 4:
        if (W(0x84) == 0) {
            func_021BDC48(scene, 1);
            W(0x88) = 1;
            *seq = 5;
        }
        break;
    case 5:
        if (W(0x424) != 0) {
            ov208_func_021C1D24(heap, p, key);
            *seq = 6;
        } else {
            if (W(0x90) == 1)
                ov208_func_021C23BC(p);
            ov208_func_021C10B8(heap, p, key);
        }
        break;
    case 6:
        if (W(0x84) == 0) {
            ov208_func_021C24A4(heap, p, key);
            *seq = 7;
            ov208_func_021BC4E4(W(0x418));
            ov208_func_021BC6F8(W(0x420));
            ov208_func_021BE854(icon);
            if (W(0x424) == 2)
                ov208_func_021BDAE8(scene, 0);
        }
        break;
    case 7:
        ready = 0;
        if (ov208_func_021BC4C8(W(0x418)) == 0 && ov208_func_021BC6C8(W(0x420)) == 0
            && ov208_func_021BE840(icon) == 0) {
            if (W(0x424) == 2) {
                if (ov208_func_021BDAD0(scene) == 0)
                    ready = 1;
            } else {
                ready = 1;
            }
        }
        if (ready)
            *seq = 8;
        break;
    case 8:
        *seq = 9;
        ov208_func_021C252C(heap, p, key);
        ov208_func_021BC508(1, W(0x41c));
        break;
    case 9:
        ov208_func_021C0130(heap, p, key);
        func_0207D4B0(1, 0, 0);
        for (k = 0; k < 2; k++) {
            func_020403F4((u8)data_021C8618[k].bg);
            func_0203FCA0(data_021C8618[k].bg, &data_021C8618[k].tmpl, data_021C8618[k].type);
            func_020414AC(data_021C8618[k].bg);
            func_02040588(data_021C8618[k].bg, data_021C8618[k].on);
        }
        return 1;
    }
    if (*seq >= 2) {
        ov208_func_021BC99C(W(8));
        ov208_func_021C0968(heap, p, key);
        ov208_func_021C0A8C(heap, p, key);
    }
    ov208_func_021C1810(heap, p, key);
    ov208_func_021BC46C(W(0x418), W(0x41c));
    ov208_func_021BC678(W(0x420));
    ov208_func_021C0714(heap, p, key);
    return 0;
}




#define OBJ(i) (*(u32 *)(p + (i) * 4 + 0xbc))






void func_021BFE08(void *a0, void *a1, void *heap, struct S *st, int *obj, int key)
{
    int sc;
    u32 flag;

    if (st == 0) {
        return;
    }
    sc = func_021BC3B4(obj);
    flag = 0;
    switch (key) {
    case 16: case 19:
        break;
    case 10: case 11: case 12: case 13: case 14: case 15: case 17: case 18: case 20:
        st->f428 = flag;
        break;
    }
    switch (key) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 8: case 9: case 19:
        flag = 1;
        st->f428 = flag;
        break;
    }
    switch (key) {
    case 12: {
        u16 old = func_021BC3C0(obj);
        func_021BC3CC((char *)obj);
        if (old != func_021BC3C0(obj)) {
            func_021C1AD4(heap, (u8 *)st, (int)obj);
            func_021C1D0C((int)heap, (int)st, (int)obj);
            st->f42c = 1;
            st->f430 = 0;
            st->f434 = 0;
        } else {
            st->f42c = 1;
            st->f430 = 1;
            st->f434 = 0;
        }
        break;
    }
    case 13: {
        u16 old = func_021BC3C0(obj);
        func_021BC40C((struct Ov208Cur *)obj);
        if (old != func_021BC3C0(obj)) {
            func_021C1AD4(heap, (u8 *)st, (int)obj);
            func_021C1D0C((int)heap, (int)st, (int)obj);
            st->f42c = 1;
            st->f430 = 0;
            st->f434 = 0;
        } else {
            st->f42c = 1;
            st->f430 = 1;
            st->f434 = 0;
        }
        break;
    }
    }
    switch (key) {
    case 0:
        break;
    case 1: case 2:
        st->f424 = 2;
        return;
    case 6: case 8: case 9:
        st->f424 = 1;
        return;
    case 3:
        if (st->f42c != 0) {
            st->f434 = 1;
            if (st->f430 != 0) {
                st->f42c = 0;
                func_021BDBA0((void *)sc);
                return;
            }
        }
        break;
    case 4:
        if (st->f42c != 0) {
            st->f434 = 1;
            if (st->f430 != 0) {
                st->f42c = 0;
                func_021BDBA0((void *)sc);
                return;
            }
        }
        break;
    case 5:
        func_02012BE0((void *)func_021BC3A4(obj), 0x12, func_021BDC2C((char *)sc));
        func_021BDBA0((void *)sc);
        return;
    case 19:
        func_021C1920(heap, (u8 *)st, (int)obj, 6);
        return;
    default:
        if (flag != 0) {
            func_021BDBA0((void *)sc);
        }
        break;
    }
}





void func_021BFFEC(void *unused, char *p)
{
    switch (((struct Obj08397 *)p)->f414) {
    case 1: func_021C239C(p); func_021C2304(p); break;
    case 2: func_021C231C(p); func_021C232C(p); break;
    case 3:
        func_021C239C(p);
        func_021C231C(p);
        func_021BC4F4(0, (int *)(((struct Obj08397 *)p)->f418));
        break;
    }
    ((struct Obj08397 *)p)->f414 = 0;
    func_021BC6BC(((struct Obj08397 *)p)->f420);
}





void func_021C0048(u16 *unused, char *p, int a2)
{
    u8 i;
    for (i = 0; i < 61; i++) {
        u16 value = func_021BBB3C(*(char * *)&((struct Obj25495 *)p)->f3C8, i, 0);
        u8 j;
        for (j = 0; j < 61; j++) {
            if (value == d_021C8670[j]) {
                *(u8 *)(p + i + 0x3cc) = j;
                break;
            }
        }
    }
}






void ov208_func_021C0090(u16 *heap, u8 *p, int key)
{
    void *h;

    h = func_020490F4(0x55, *heap);
    func_02049B68(h, 0, 2, 0x6000, 0x2000, *heap);
    func_02049B68(h, 0, 2, 0x4000, 0x2000, *heap);
    func_02049658(h, 5, 2, 0, 0x4000, 0, *heap);
    func_02049658(h, 7, 3, 0, 0xc000, 0, *heap);
    func_020498F4(h, 0x11, 2, 0, 0x800, 0, *heap);
    func_020498F4(h, 0x10, 3, 0, 0x800, 0, *heap);
    func_02049238(h);
}






void ov208_func_021C0130(u16 *heap, u8 *p, int key)
{
}






void func_021C0134(u16 *heap, u8 *p, int key)
{
    BankDesc desc;
    Row7 anim, pri, pal;
    ObjPos_021BD574 pos;
    Pt_021BFE08 pt;
    void *h;
    u8 i;

    desc = data_021C8580;
    WP(0x1d4) = func_0204B034((u8 *)(&desc), 1, *heap);
    W(0x1d0) = (u32)func_0204B100(0x10, 0, *heap);
    func_0204B258((struct Bank *)W(0x1d0), WP(0x1d4));

    h = func_020490F4(0x55, *heap);
    W(0x9c) = func_0204AC18(h, 2, 0, 0, 0, 5, *heap);
    W(0x98) = func_0204A6C8(h, 8, 0, 0, *heap);
    W(0xa0) = func_0204AF28(h, 0xc, 0x13, *heap);
    func_02049238(h);

    h = func_020490F4(0x9f, *heap);
    W(0xa8) = func_0204AC18(h, 6, 0, 0xa0, 0, 2, *heap);
    W(0xa4) = func_0204A6C8(h, 0x10, 0, 0, *heap);
    W(0xac) = func_0204AF28(h, 0x1d, 0x2e, *heap);
    func_02049238(h);

    h = func_020490F4(0x9f, *heap);
    W(0xb4) = func_0204AC18(h, 5, 0, 0xe0, 0, 1, *heap);
    W(0xb0) = func_0204A6C8(h, 0xf, 0, 0, *heap);
    W(0xb8) = func_0204AF28(h, 0x1c, 0x2d, *heap);
    func_02049238(h);

    anim = data_021C8560;
    pri = data_021C8558;
    pal = data_021C8568;

    func_02082BCC(&pos, 0, sizeof(pos));
    for (i = 4; i < 7; i++)
        OBJ(i) = (u32)func_0204B294((u32)W(0x1d0), W(0x98), W(0x9c), W(0xa0), &pos, 0, *heap);
    for (i = 0; i < 4; i++)
        OBJ(i) = (u32)func_0204B294((u32)W(0x1d0), W(0xa4), W(0xa8), W(0xac), &pos, 0, *heap);

    for (i = 0; i < 7; i++) {
        func_0204B878((struct Obj *)OBJ(i), anim.v[i]);
        func_0204B92C((struct Obj *)OBJ(i), 1);
        func_0204B84C(OBJ(i), pri.v[i]);
        func_0204B800((struct Node *)OBJ(i), pal.v[i]);
        func_0204B3DC((struct Obj *)OBJ(i), 0);
        func_0204B688((struct Actor *)OBJ(i), 1);
    }

    pt.x = 0x80;
    pt.y = 0x60;
    for (i = 0; i < 4; i++)
        func_0204B404((struct Obj *)OBJ(i), (const struct Vec2 *)(&pt), 0);

    p[0xd8] = 7;
}





/*
 * Tail: 021C044E..021C0450 is two zero alignment bytes, not a follower.
 */
void func_021C03C4(void *unused, char *p, void *a2)
{
    u8 i;
    for (i = 0; i < 7; i++) func_0204B3B4(*(struct Obj **)(p + i * 4 + 0xbc));
    func_0204AFD8(((struct Obj02546 *)p)->fB8);
    func_0204A8D4(((struct Obj02546 *)p)->fB0);
    func_0204ADA4(((struct Obj02546 *)p)->fB4);
    func_0204AFD8(((struct Obj02546 *)p)->fAC);
    func_0204A8D4(((struct Obj02546 *)p)->fA4);
    func_0204ADA4(((struct Obj02546 *)p)->fA8);
    func_0204AFD8(((struct Obj02546 *)p)->fA0);
    func_0204A8D4(((struct Obj02546 *)p)->f98);
    func_0204ADA4(((struct Obj02546 *)p)->f9C);
    func_0204B1CC(*(struct Bank * *)&((struct Obj02546 *)p)->f1D0);
    func_0204B084(((struct Obj02546 *)p)->f1D4);
}






void ov208_func_021C0450(u16 *heap, u8 *p, int key)
{
    ObjPos_021BD574 pos;
    u8 i;

    func_02082BCC(&pos, 0, sizeof(pos));
    for (i = 0; i < 0x3d; i++) {
        pos.x = func_021BBB3C((char *)W(0x3c8), i, 0x19);
        pos.y = func_021BBB3C((char *)W(0x3c8), i, 0x1a);
        *(u32 *)(p + i * 4 + 0xdc) = (u32)func_0204B294((u32)W(0), W(0xb0), W(0xb4), W(0xb8), &pos, 0, *heap);
        func_0204B878((struct Obj *)(*(u32 *)(p + i * 4 + 0xdc)), func_021BBB3C((char *)W(0x3c8), i, 0x18));
        func_0204B92C((struct Obj *)*(u32 *)(p + i * 4 + 0xdc), 1);
        func_0204B84C(*(u32 *)(p + i * 4 + 0xdc), 2);
        func_0204B800((struct Node *)(*(u32 *)(p + i * 4 + 0xdc)), 4);
        func_0204B3DC((struct Obj *)*(u32 *)(p + i * 4 + 0xdc), 0);
        func_0204B688((struct Actor *)(*(u32 *)(p + i * 4 + 0xdc)), 1);
    }
}






/*
 * Releases each of the 0x3D handles held from +0xDC on.
 */
void func_021C0524(void *unused, char *p, void *a2)
{
    unsigned char i;

    for (i = 0; i < 0x3d; i++)
        func_0204B3B4((struct Obj *)(*(int *)(p + i * 4 + 0xdc)));
}






void ov208_func_021C0544(u16 *heap, u8 *p, int key)
{
    int k;
    u8 i;
    u16 kind;
    u16 msg;
    ObjPos_021BD574 pos;

    k = ov208_func_021BC3A4(key);
    for (i = 0; i < 0x3d; i++) {
        msg = func_021BBB3C((char *)W(0x3c8), i, 0x10);
        if (msg != 0xffff) {
            if ((func_02166CD0(k, msg) == 0 ? 1 : 0)) {
                *(u32 *)(p + i * 8 + 0x1e0) = 1;
                *(u32 *)(p + i * 8 + 0x1e4) = 0;
            } else {
                kind = func_021BBB3C((char *)W(0x3c8), i, 0xb);
                pos.x = func_021BBB3C((char *)W(0x3c8), i, 2);
                pos.y = func_021BBB3C((char *)W(0x3c8), i, 3);
                pos.z = kind == 4 ? 0xe : 0x10;
                pos.pri = 5;
                pos.f7 = 2;
                *(u32 *)(p + i * 8 + 0x1e0) = 2;
                *(u32 *)(p + i * 8 + 0x1e4) = (u32)func_0204B294((u32)W(0x1d0), W(0x98), W(0x9c), W(0xa0), &pos, 0, *heap);
                func_0204B92C((struct Obj *)(*(u32 *)(p + i * 8 + 0x1e4)), 1);
                func_0204B3DC((struct Obj *)(*(u32 *)(p + i * 8 + 0x1e4)), 1);
                func_0204B688((struct Actor *)(*(u32 *)(p + i * 8 + 0x1e4)), 1);
            }
        } else {
            *(u32 *)(p + i * 8 + 0x1e0) = 0;
            *(u32 *)(p + i * 8 + 0x1e4) = 0;
        }
    }
}






/*
 * Frees the second word of every entry whose first word is 2.
 */
void func_021C06A0(void *a0, char *p, void *a2)
{
    S *s = (S *)p;
    unsigned char i;

    for (i = 0; i < 0x3d; i++) {
        if (s->arr[i * 2] == 2)
            func_0204B3B4((struct Obj *)s->arr[i * 2 + 1]);
    }
}






void func_021C06C8(unsigned short *a, char *b, int a2)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        char *e = b + i * 4;
        ((struct Obj12126 *)e)->f34 = func_0201C440((void *)(*a));
        ((struct Obj12126 *)e)->f24 = 0;
    }
}






/*
 * Clears a word and releases two handles of each of four entries.
 */
void func_021C06EC(void *unused, char *p, void *a2)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        char *e = p + i * 4;
        ((struct Obj09204 *)e)->f24 = 0;
        func_0201C6EC((struct PrintSys *)(((struct Obj09204 *)e)->f34));
        func_0201C4C0((struct PrintSys *)(((struct Obj09204 *)e)->f34));
    }
}




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ
#define OBJ(i) (((u32 *)(p + 0xbc))[i])






void ov208_func_021C0714(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        func_0201C4E4((struct PrintSys *)(((u32 *)(p + 0x34))[i]));
        ov208_func_021C0740(heap, p, key, i);
    }
}






void ov208_func_021C0740(u16 *heap, u8 *p, int key, u8 i)
{
    u32 w;

    if (((u32 *)(p + 0x24))[i] != 0) {
        if (func_0201C6C4((struct PrintSys *)(((u32 *)(p + 0x34))[i]), (void *)((u32)func_02045770((struct Descriptor *)((u32 *)(p + 0x14))[i]))) == 0) {
            w = ((u32 *)(p + 0x14))[i];
            func_02045334((struct Descriptor *)w);
            func_02045374((struct Cfg *)w);
            func_02041B6C(func_02045730((struct Descriptor *)w));
            ((u32 *)(p + 0x24))[i] = 0;
        }
    }
}






void ov208_func_021C0788(u16 *heap, u8 *p, int key)
{
    struct WinCfg2 a;
    struct WinCfg4 b;
    u8 i;

    a = data_021C8570;
    b = data_021C85A4;
    func_02049B90(0x17, 5, 4, 0, 0x100, 0x20, *heap);
    func_02049B90(0x17, 5, 0, 0, 0, 0x20, *heap);
    for (i = 0; i < 2; i++) {
        *(u32 *)(p + i * 4 + 0x44) = func_020450F0(a.e[i].bg, a.e[i].x, a.e[i].y, a.e[i].w, a.e[i].h, a.e[i].pal, a.e[i].base);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)(p + i * 4 + 0x44))), 0);
        func_02045334((struct Descriptor *)*(u32 *)(p + i * 4 + 0x44));
    }
    for (i = 0; i < 4; i++) {
        *(u32 *)(p + i * 4 + 0x14) = func_020450F0(b.e[i].bg, b.e[i].x, b.e[i].y, b.e[i].w, b.e[i].h, b.e[i].pal, b.e[i].base);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)(p + i * 4 + 0x14))), 0);
        func_02045334((struct Descriptor *)*(u32 *)(p + i * 4 + 0x14));
    }
    W(0xc) = (u32)func_02045B38(0, 2, 0xea, *heap);
    W(0x10) = (u32)func_02045B38(0, 2, 0x59, *heap);
}





void func_021C0898(void *unused, char *p, void *a2)
{
    u8 i;
    for (i = 0; i < 2; i++) func_02045C04(*(struct Rec **)(p + i * 4 + 0xc));
    for (i = 0; i < 4; i++) {
        *(unsigned *)(p + i * 4 + 0x24) = 0;
        func_0201C6EC(*(struct PrintSys **)(p + i * 4 + 0x34));
        func_020452E8(*(struct Descriptor **)(p + i * 4 + 0x14));
    }
    for (i = 0; i < 2; i++) func_020452E8(*(struct Descriptor **)(p + i * 4 + 0x44));
}






void ov208_func_021C08E8(u16 *heap, u8 *p, int key)
{
    void *h;

    h = func_020490F4(0x9f, *heap);
    func_02049BDC(h, 2, 4, 0, 0, 0x100, *heap);
    ((struct Obj14653 *)p)->f68 = func_02049740(h, 12, 7, 0, 0, *heap);
    func_02049990(h, 0x26, 7, 0, (u16)((struct Obj14653 *)p)->f68, 0, 0, *heap);
    func_02049238(h);
}






void func_021C0950(void *unused, u8 *p, void *a2)
{
    u32 v = ((struct Obj25499 *)p)->f68;
    func_0203FB44(7, (u16)v, (u16)(v >> 16));
}






void func_021C0968(int a, int b, int c)
{
    func_021C0980(a, (unsigned char *)b, c);
    func_021C0A88(a, b, c);
}






void func_021C0980(int a, unsigned char *p, int a2)
{
    switch (*(unsigned int *)&((struct Obj02346 *)p)->f70) {
    case 0:
        break;
    case 2:
        break;
    case 1:
        if ((int)func_02040804((int)7) >= 0x40) {
            func_02041EE4(7, 3, 0x40);
            ((struct Obj02346 *)p)->f70 = 2;
        } else {
            func_02041EE4(7, 4, 8);
            func_02041EE4(6, 4, 8);
        }
        break;
    case 3:
        if ((int)func_02040804((int)7) <= 0) {
            func_02041EE4(7, 3, 0);
            ((struct Obj02346 *)p)->f70 = 0;
        } else {
            func_02041EE4(7, 5, 8);
            func_02041EE4(6, 5, 8);
        }
        break;
    }
    if (*(int *)(p + 0x5c + 4 * ((struct Obj02346 *)p)->f64) == 0)
        return;
    {
        short v[2];

        switch (*(unsigned int *)&((struct Obj02346 *)p)->f74) {
        case 0:
            break;
        case 2:
            break;
        case 1:
            func_0204B454((struct Actor *)*(int *)(p + 0x5c + 4 * ((struct Obj02346 *)p)->f64), (struct PtS *)v, 1);
            if (v[1] <= 0x70) {
                v[1] = 0x70;
                ((struct Obj02346 *)p)->f74 = 2;
            } else {
                v[1] -= 8;
            }
            func_0204B404((struct Obj *)(*(int *)(p + 0x5c + 4 * ((struct Obj02346 *)p)->f64)), (const struct Vec2 *)v, 1);
            break;
        case 3:
            func_0204B454((struct Actor *)*(int *)(p + 0x5c + 4 * ((struct Obj02346 *)p)->f64), (struct PtS *)v, 1);
            if (v[1] >= 0xb0) {
                v[1] = 0xb0;
                ((struct Obj02346 *)p)->f74 = 0;
            } else {
                v[1] += 8;
            }
            func_0204B404((struct Obj *)(*(int *)(p + 0x5c + 4 * ((struct Obj02346 *)p)->f64)), (const struct Vec2 *)v, 1);
            break;
        }
    }
}





/*
 * Empty stub; the listing pads it with two zero bytes.
 */
void func_021C0A88(int a0, int a1, int a2)
{
}






void ov208_func_021C0A8C(u16 *heap, u8 *p, int key)
{
    void *scene;
    u8 sel;
    u16 anim;
    u32 next;
    u16 nextAnim;

    scene = ov208_func_021BC3B4(key);
    sel = p[0xd8];
    if (sel == 2) {
        anim = 2;
        next = 1;
        nextAnim = 4;
    } else if (sel == 1) {
        anim = 4;
        next = 2;
        nextAnim = 2;
    }
    if (sel != 7 && func_0204B98C((struct Actor *)OBJ(sel)) == 0) {
        func_0204B878((struct Obj *)OBJ(p[0xd8]), anim);
        func_0204B92C((struct Obj *)OBJ(next), 1);
        func_0204B878((struct Obj *)OBJ(next), nextAnim);
        p[0xd8] = 7;
        if (((struct Obj06683 *)p)->f6C == 0 || ((struct Obj06683 *)p)->f6C == 5)
            func_021BDC48((struct Ov208Scene *)scene, 1);
    }
}






void ov208_func_021C0B10(u16 *heap, u8 *p, int key)
{
    void *h;

    h = func_020490F4(7, *heap);
    ((struct Obj14654 *)p)->f54 = func_0204ACEC(h, func_0201BC3C(), 1, 0, *heap);
    ((struct Obj14654 *)p)->f58 = func_0204AF28(h, func_0201BC78(), func_0201BCEC(), *heap);
    func_02049238(h);
}






/*
 * Calls 0x0204AFD8 on +0x58 and 0x0204ADA4 on +0x54 of the second argument.
 */
void func_021C0B58(void *a, char *q, void *a2)
{
    func_0204AFD8(((struct Obj12127 *)q)->f58);
    func_0204ADA4(((struct Obj12127 *)q)->f54);
}






u32 func_021C0B6C(u32 *slot, u32 a, u32 b, u32 res, u16 heap, u32 species, u32 form,
                  u32 gender, u32 isEgg, u8 x, u8 y)
{
    ObjPos_021BD574 pos;
    void *h;
    u32 obj;

    h = func_020490F4(7, heap);
    pos.x = x;
    pos.y = y;
    pos.z = 1;
    pos.pri = 1;
    pos.f7 = 0;
    *slot = func_0204A6C8(h, func_0201BABC(species, form, gender, isEgg), 0, 1, heap);
    obj = (u32)func_0204B294((u32)res, *slot, a, b, &pos, 1, heap);
    func_0204B92C((struct Obj *)obj, 0);
    func_0204B6F4((struct Obj *)obj, func_0201BB5C(species, form, gender, isEgg), 0);
    func_0204B688((struct Actor *)obj, 0);
    func_02049238(h);
    return obj;
}






/*
 * Calls 0x0204B3B4 on the second argument, then 0x0204A8D4 on the first.
 */
void func_021C0C00(void *a, void *b)
{
    func_0204B3B4(b);
    func_0204A8D4((u32)a);
}











u8 ov208_func_021C0C14(u16 *heap, u8 *p, int key)
{
    int a;
    u32 m;
    int v;
    u8 r;

    a = ov208_func_021BC3A4(key);
    m = func_02012AC8((const struct Rec44 *)func_020127A4((struct SaveBlock *)a));
    r = 0xff;
    v = func_021BBB48(((struct Obj25500 *)p)->f3C8, func_02166C7C(a, m));
    if (v != 0xffff)
        r = v;
    return r;
}











void ov208_func_021C0C50(u16 *heap, u8 *p, int key)
{
    u8 idx;
    u16 pos[2];

    idx = ov208_func_021C0C14(heap, p, key);
    if (idx != 0xff) {
        pos[0] = func_021BBB3C((char *)(((struct Obj10903 *)p)->f3C8), idx, 2);
        pos[1] = func_021BBB3C((char *)(((struct Obj10903 *)p)->f3C8), idx, 3);
        func_0204B404((struct Obj *)(((struct Obj10903 *)p)->fD4), (const struct Vec2 *)pos, 0);
    }
}











void ov208_func_021C0C8C(u16 *heap, u8 *p, int key, int on)
{
    if (on) {
        if (ov208_func_021C0C14(heap, p, key) != 0xff) {
            func_0204B878((struct Obj *)(((struct Obj10904 *)p)->fD4), 6);
            func_0204B3DC((struct Obj *)((struct Obj10904 *)p)->fD4, 1);
        }
    } else {
        func_0204B3DC((struct Obj *)((struct Obj10904 *)p)->fD4, 0);
    }
}










/*
 * Loads the word at +0xD4 of the second argument and tail-calls the function at 0x0204B3F4 with it.
 *
 * The pool word carries the thumb bit, so the callee is deliberately left
 * undeclared here and resolved through the label class.
 */
u32 func_021C0CC0(void *a0, u8 *p, void *a2)
{
    return func_0204B3F4((struct Obj *)(((struct Obj18273 *)p)->fD4));
}









void func_021C0CCC(u16 *heap, u8 *p, int key)
{
    Pt_021C0C14 pt = data_021C8554;

    if (p[0x79] == 0xff)
        p[0x79] = func_021C0C14(heap, p, key);
    if (p[0x79] != 0xff) {
        pt.x = func_021BBB3C((char *)W(0x3c8), p[0x79], 2);
        pt.y = func_021BBB3C((char *)W(0x3c8), p[0x79], 3);
    }
    func_0204B404((struct Obj *)W(0xcc), (const struct Vec2 *)(&pt), 0);
    func_0204B3DC((struct Obj *)W(0xcc), 1);
}








/*
 * Stores the byte result of func_021C0C14 at +0x79 of the second argument then calls func_021C0CCC.
 */
void func_021C0D3C(int a, char *b, int c)
{
    b[0x79] = func_021C0C14((u16 *)a, (u8 *)b, c);
    func_021C0CCC((u16 *)a, (u8 *)b, c);
}







u8 func_021C0D5C(void *unused,char *p,int unused2,u8 x,u8 y)
{
    struct Ball ball;
    struct Vec_021C0D5C point;
    struct Seg seg;
    struct Vec_021C0D5C a,b;
    struct Out out;
    int best;
    u8 i;
    u8 result=255;
    point.x=FX(x);
    point.y=FX(y);
    point.z=0;
    func_02051F1C(&ball,&point,0);
    for(i=0;i<61;i++) {
        if (*(u32 *)(p+i*8+0x1e0)==1) continue;
        a.x=FX(FIELD(6));
        a.y=FX(FIELD(7));
        a.z=0;
        b.x=FX(FIELD(8));
        b.y=FX(FIELD(9));
        b.z=0;
        func_0205207C((char *)(&seg),(struct S12 *)(&a),(struct S12 *)(&b),FX(FIELD(10)));
        if (func_02051F34(&seg,&ball,&out)) {
            if(result==255) { best=out.distance; result=i; }
            else if(best>out.distance) { best=out.distance; result=i; }
        }
    }
    return result;
}







/*
 * Tail: 021C1066..021C1068 is two zero alignment bytes, not a follower.
 */
int func_021C100C(void *unused, char *p, int key, u8 index, u8 x, u8 y, unsigned *out)
{
    unsigned dx, dy, distance;
    if (*(unsigned *)(p + index * 8 + 0x1e0) == 1) return 0;
    dx = func_021BBB3C(*(char * *)&((struct Obj14656 *)p)->f3C8, index, 4);
    dy = func_021BBB3C(*(char * *)&((struct Obj14656 *)p)->f3C8, index, 5);
    dy -= y;
    dx -= x;
    distance = dx * dx + dy * dy;
    if (distance < 144) {
        if (out) *out = distance;
        return 1;
    }
    return 0;
}







u8 func_021C1068(void *heap, char *p, int key, u8 x, u8 y)
{
    unsigned distance, bestDistance;
    u8 best = 255, i;
    for (i = 0; i < 61; i++) {
        if (func_021C100C(heap, p, key, i, x, y, &distance)) {
            if (best == 255) {
                best = i;
                bestDistance = distance;
            } else if (bestDistance > distance) {
                best = i;
                bestDistance = distance;
            }
        }
    }
    return best;
}








void func_021C10B8(u16 *heap, u8 *p, int key)
{
    void *s;
    int hit, touch;
    int moved, done;
    u32 x, y, tx, ty;

    s = (void *)func_021BC3B4((int *)key);
    if (W(0x428) == 0 || p[0xd8] != 7)
        return;

    switch (W(0x6c)) {
    case 0:
        hit = 0;
        touch = 0;
        if (func_020362DC() & 1) {
            touch = 1;
            hit = 1;
        } else if (W(0x8c) != 0) {
            if (func_0203633C() & 0x100) {
                p[0x78]++;
                if (p[0x78] >= 4)
                    p[0x78] = 0;
                hit = 1;
                func_021C1E10(heap, p, key, 1, 0);
                func_020061E4(0x54a);
            } else if (func_0203633C() & 0x200) {
                if (p[0x78] == 0) p[0x78] = 3; else p[0x78]--;
                func_021C1E10(heap, p, key, 0, 0);
                func_020061E4(0x54a);
                hit = 1;
            }
        }
        if (hit) {
            func_020355D8(0);
            if (touch)
                W(0x7c) = 0;
        }
        if (hit == 0) {
            if (func_02035D20(&x, &y)) {
                if (W(0x8c) == 0) {
                    if (y < 0xa8) {
                        touch = 1;
                        hit = 1;
                    }
                } else if (x >= 0x88 && x < 0xa0 && y < 0x10) {
                    p[0x78]++;
                    if (p[0x78] >= 4)
                        p[0x78] = 0;
                    hit = 1;
                    func_021C1E10(heap, p, key, 1, hit);
                    func_020061E4(0x54a);
                } else if (x < 0x18 && y < 0x10) {
                    if (p[0x78] == 0) p[0x78] = 3; else p[0x78]--;
                    hit = 1;
                    func_021C1E10(heap, p, key, 0, hit);
                    func_020061E4(0x54a);
                } else if ((x >= 0xa0 || y >= 0x18) && y < 0xa8) {
                    touch = 1;
                    hit = 1;
                }
            }
            if (hit) {
                hit = 1;
                func_020355D8(1);
                if (touch) {
                    W(0x7c) = hit;
                    p[0x80] = x;
                    p[0x81] = y;
                }
            }
        }
        if (touch && (W(0x8c) != 0 || W(0x90) != 0)) {
            func_021C1920(heap, p, key, 1);
            func_020061E4(0x54c);
            func_021BDC48((struct Ov208Scene *)s, 0);
        }
        break;
    case 5:
        moved = 0;
        done = 1;
        if (func_020362DC() & 2) {
            W(0x428) = 0;
            moved = 1;
            done = 0;
        } else if (W(0x8c) != 0) {
            if (func_0203633C() & 0x100) {
                p[0x78]++;
                if (p[0x78] >= 4)
                    p[0x78] = 0;
                done = 0;
                func_021C1E10(heap, p, key, 1, done);
                moved = 1;
                func_020061E4(0x54a);
            } else if (func_0203633C() & 0x200) {
                if (p[0x78] == 0) p[0x78] = 3; else p[0x78]--;
                done = 0;
                func_021C1E10(heap, p, key, 0, 0);
                func_020061E4(0x54a);
                moved = 1;
            }
        }
        if (moved)
            func_020355D8(0);
        if (moved == 0) {
            if (func_02035D20(&tx, &ty)) {
                if (W(0x8c) == 0) {
                    if (ty >= 0xa8)
                        done = 0;
                } else if (W(0x8c) == 1) {
                    if (tx >= 0x88 && tx < 0xa0 && ty < 0x10) {
                        p[0x78]++;
                        if (p[0x78] >= 4)
                            p[0x78] = 0;
                        moved = 1;
                        func_021C1E10(heap, p, key, 1, moved);
                        func_020061E4(0x54a);
                        done = 0;
                    } else if (tx < 0x18 && ty < 0x10) {
                        if (p[0x78] == 0) p[0x78] = 3; else p[0x78]--;
                        moved = 1;
                        func_021C1E10(heap, p, key, 0, moved);
                        done = 0;
                        func_020061E4(0x54a);
                    } else if (tx < 0xa0 && ty < 0x18) {
                        done = 0;
                    } else if (ty >= 0xa8) {
                        done = 0;
                    }
                }
            }
            if (moved)
                func_020355D8(1);
        }
        if (done)
            func_021C1450(heap, p, key);
        break;
    }
}








static inline void set3(struct Vec_021C1450 *v, int x, int y, int z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}








void func_021C1450(u16 *heap, u8 *p, int key)
{
    u32 tx, ty;
    struct { struct PtS t, c; } pt;
    u8 idx;
    u8 old;
    int found, near;
    int moved;
    unsigned int keys;
    int dx, dy;

    if (W(0x90) == 0)
        return;
    if (func_020355C4() == 0) {
        if (func_02035D20(&tx, &ty)) {
            func_020355D8(1);
            func_0204B3DC((struct Obj *)W(0xcc), 0);
        }
    } else if (func_020362DC()) {
        func_020355D8(0);
        func_021C0CCC(heap, p, key);
        func_021C1D30(heap, p, key);
        func_021C2238(heap, p, key);
        return;
    }
    if (func_020355C4() == 0) {
        old = p[0x79];
        moved = 0;
        found = 0;
        near = 0;
        {
        struct Vec_021C1450 v = {0, 0, 0};
        struct Vec_021C1450 d = {0, 0, 0};
        struct Vec_021C1450 a;
        struct Vec_021C1450 b;
        func_0204B454((struct Actor *)W(0xcc), &pt.c, 0);
        keys = func_0203630C();
        if ((keys & 0x10) || (keys & 0x20) || (keys & 0x40) || (keys & 0x80)) {
            moved = 1;
            if (keys & 0x10)
                v.x += 0x1000;
            if (keys & 0x20)
                v.x -= 0x1000;
            if (keys & 0x40)
                v.y -= 0x1000;
            if (keys & 0x80)
                v.y += 0x1000;
        }
        idx = func_021C1068(heap, (char *)p, key, (u8)pt.c.x, (u8)pt.c.y);
        if (idx != 0xff) {
            found = 1;
            pt.t.x = func_021BBB3C(*(char **)(p + 0x3c8), idx, 4);
            pt.t.y = func_021BBB3C(*(char **)(p + 0x3c8), idx, 5);
            a.x = FX(pt.t.x);
            a.y = FX(pt.t.y);
            a.z = 0;
            b.x = FX(pt.c.x);
            b.y = FX(pt.c.y);
            b.z = 0;
            func_0207CA00(&a, &b, &d);
            if (func_0207CBD0(&d) < 0x1BB6)
                near = 1;
            if (func_0207CBD0(&d) > 0x1000) {
                func_0207CCA4(&d, &d);
                func_020520A4((const struct Vec3 *)(&d), 0x1000, (struct Vec3 *)(&d));
            }
        }
        if (moved == 0 && found == 0)
            return;
        if (moved == 0 && found != 0 && near != 0) {
            pt.c = pt.t;
        } else {
            func_0207CCA4(&v, &v);
            dx = d.x + v.x * 3;
            dy = d.y + v.y * 3;
            if (dx > 0 && dx < 0x1000)
                dx = 0x1000;
            else if (dx > -0x1000 && dx < 0)
                dx = -0x1000;
            if (dy > 0 && dy < 0x1000)
                dy = 0x1000;
            else if (dy > -0x1000 && dy < 0)
                dy = -0x1000;
            pt.c.x = pt.c.x + (s16_021BFE08)(dx >> 12);
            pt.c.y = pt.c.y + (s16_021BFE08)(dy >> 12);
        }
        pt.c.x = pt.c.x > 0xf8 ? 0xf8 : (pt.c.x < 0 ? 0 : pt.c.x);
        pt.c.y = pt.c.y > 0xa8 ? 0xa8 : (pt.c.y < 8 ? 8 : pt.c.y);
        func_0204B404((struct Obj *)W(0xcc), (const struct Vec2 *)(&pt.c), 0);
        p[0x79] = func_021C0D5C(heap, (char *)p, key, (u8)pt.c.x, (u8)pt.c.y);
        if (p[0x79] != old) {
            func_021C1D30(heap, p, key);
            func_021C2238(heap, p, key);
            if (p[0x79] != 0xff)
                func_020061E4(0x548);
        }
        }
    } else if (func_02035D20(&tx, &ty)) {
        p[0x79] = func_021C0D5C(heap, (char *)p, key, (u8)tx, (u8)ty);
        func_021C1D30(heap, p, key);
        func_021C2238(heap, p, key);
        if (p[0x79] != 0xff)
            func_020061E4(0x54C);
    }
}








void ov208_func_021C1810(u16 *heap, u8 *p, int key)
{
    switch (W(0x6c)) {
    case 1:
        ov208_func_021C1920(heap, p, key, 2);
        break;
    case 2:
        ov208_func_021C1920(heap, p, key, 5);
        break;
    case 3:
        switch (W(0x84)) {
        case 1:
            ov208_func_021C1FE0(heap, p, key);
            W(0x84) = 2;
            break;
        case 2:
            ov208_func_021C2090(heap, p, key);
            W(0x84) = 3;
            break;
        case 3:
            ov208_func_021C20C0(heap, p, key);
            W(0x84) = 0;
            ov208_func_021C1920(heap, p, key, 0);
            break;
        }
        break;
    case 4:
        switch (W(0x84)) {
        case 1:
            ov208_func_021C21D0(heap, p, key);
            W(0x84) = 2;
            break;
        case 2:
            ov208_func_021C2228(heap, p, key);
            W(0x84) = 3;
            break;
        case 3:
            ov208_func_021C2234(heap, p, key);
            W(0x84) = 0;
            break;
        }
        break;
    case 6:
        ov208_func_021C1920(heap, p, key, 7);
        break;
    case 7:
        ov208_func_021C1920(heap, p, key, 0);
        break;
    case 8:
        switch (W(0x84)) {
        case 1:
            ov208_func_021C1FE0(heap, p, key);
            W(0x84) = 2;
            break;
        case 2:
            ov208_func_021C2090(heap, p, key);
            W(0x84) = 3;
            break;
        case 3:
            ov208_func_021C20C0(heap, p, key);
            W(0x84) = 0;
            ov208_func_021C1920(heap, p, key, 5);
            break;
        }
        break;
    }
}








void func_021C1920(u16 *heap, u8 *p, int key, int mode)
{
    void *s;
    u32 wide;

    s = (void *)func_021BC3B4((int *)key);
    switch (W(0x6c)) {
    case 0:
        if (mode == 1) {
        } else if (mode == 3) {
            W(0x84) = 1;
        } else if (mode == 4) {
            W(0x84) = 1;
        }
        break;
    case 1:
        if (mode == 2)
            func_021BDBAC(s, 0);
        break;
    case 2:
        if (mode == 5) {
            W(0x70) = 1;
            W(0x74) = 1;
            if (W(0x90) == 1) {
                if (W(0x7c) == 0) {
                    func_021C0D3C((int)heap, (char *)p, key);
                } else {
                    p[0x79] = func_021C0D5C(heap, (char *)p, key, p[0x80], p[0x81]);
                    if (p[0x79] != 0xff)
                        func_0204B3DC((struct Obj *)W(0xd0), 1);
                }
                func_021C1D30(heap, p, key);
                func_021C2238(heap, p, key);
            }
            func_021BDAAC(s, 1, 1, func_021BC3BC((int *)((char *)key)) > 1);
        }
        break;
    case 3:
        if (mode == 0) {
            if (W(0x42c) != 0) {
                W(0x430) = 1;
                if (W(0x434) != 0) {
                    W(0x42c) = 0;
                    func_021BDBA0((void *)((int)s));
                }
            }
            if (p[0xd8] == 7 && W(0x88) != 0)
                func_021BDC48((struct Ov208Scene *)s, 1);
        }
        break;
    case 4:
        break;
    case 5:
        if (mode == 6) {
        } else if (mode == 8) {
            W(0x84) = 1;
        }
        break;
    case 6:
        if (mode == 7)
            func_021BDBAC(s, 0);
        break;
    case 7:
        if (mode == 0) {
            W(0x70) = 3;
            W(0x74) = 3;
            func_0204B3DC((struct Obj *)W(0xcc), 0);
            func_0204B3DC((struct Obj *)W(0xd0), 0);
            wide = func_021BC3BC((int *)((char *)key)) > 1 ? 1 : 0;
            func_021BDAAC(s, 0, 1, wide);
            func_021BDC14((struct Ov208Scene *)s, func_02012BF8(func_021BC3A4((int *)key), 0x12));
        }
        break;
    case 8:
        if (mode == 5) {
            func_021BDBA0((void *)((int)s));
            if (p[0xd8] == 7 && W(0x88) != 0)
                func_021BDC48((struct Ov208Scene *)s, 1);
        }
        break;
    }
    W(0x6c) = mode;
}







void func_021C1AD4(u16 *heap, u8 *p, int key)
{
    u32 prev;
    u16 id;
    void *win;
    void *str;
    void *buf;
    u32 out1, out2, form;

    prev = W(0x8c);
    id = func_021BC3C0((void *)key);
    func_021C1F44(W(0x94));
    W(0x94) = (u32)func_021C1F28(id, *heap, W(0x40c));
    W(0x8c) = ((Entry *)W(0x94))->f0 == 0;
    if (W(0x8c) == 0)
        W(0x90) = ((Entry *)W(0x94))[0].f1 == 0;
    else
        W(0x90) = ((Entry *)W(0x94))[p[0x78]].f1 == 0;

    if (SLOT5C(((struct Obj00081 *)p)->f64) != 0)
        func_0204B3DC((struct Obj *)SLOT5C(((struct Obj00081 *)p)->f64), 0);
    ((struct Obj00081 *)p)->f64 = (((struct Obj00081 *)p)->f64 + 1) % 2;
    if (SLOT5C(((struct Obj00081 *)p)->f64) != 0) {
        if (SLOT5C(((struct Obj00081 *)p)->f64) != 0)
            func_021C0C00((void *)SLOT4C(((struct Obj00081 *)p)->f64), (void *)SLOT5C(((struct Obj00081 *)p)->f64));
        SLOT5C(*(int *)(p + 0x64)) = 0;
    }

    func_0200CC40(func_0200CA1C((void *)func_021BC3A4((int *)key)), id, &out1, &out2, &form, *heap);
    SLOT5C(*(int *)(p + 0x64)) = func_021C0B6C(&SLOT4C(((struct Obj00081 *)p)->f64), W(0x54), W(0x58), W(0),
                                               *heap, id, form, out1, 0, 0x38, 0xb0);
    W(0x24) = 0;
    func_0201C6EC((struct PrintSys *)W(0x34));
    func_02043B5C(func_02045770((struct Descriptor *)W(0x14)), 0);
    win = func_0201EC64(*heap);
    str = func_02045EC0((struct MsgBank *)W(0xc), 0xbd);
    buf = func_020457B0(0x40, *heap);
    func_0201EE60(win, 0, id);
    func_0201F250(win, buf, str);
    func_02045808(str);
    func_0201ED04(win);
    func_0201C724((void *)W(0x34), (u32)func_02045770((struct Descriptor *)W(0x14)), 0, 5, (u32)buf, W(4), 0x3c40);
    func_02045808(buf);
    W(0x24) = 1;
    func_021C0740(heap, p, key, 0);

    if (W(0x8c) == 0) {
        if (prev == 1) {
            W(0x2c) = 0;
            func_0201C6EC((struct PrintSys *)W(0x3c));
            func_02043B5C(func_02045770((struct Descriptor *)W(0x1c)), 0);
            func_02045334((struct Descriptor *)W(0x1c));
            func_0204B3DC((struct Obj *)W(0xbc), 0);
            func_0204B3DC((struct Obj *)W(0xc4), 0);
            func_0204B3DC((struct Obj *)W(0xc0), 0);
        }
    } else if (prev == 0) {
        func_021C1F50(heap, p, key);
        func_0204B3DC((struct Obj *)W(0xbc), 1);
        func_0204B878((struct Obj *)W(0xc4), 2);
        func_0204B3DC((struct Obj *)W(0xc4), 1);
        func_0204B878((struct Obj *)W(0xc0), 4);
        func_0204B3DC((struct Obj *)W(0xc0), 1);
    }
}







/*
 * Calls func_021C1FC4 then func_021C2238 on the same three arguments.
 */
void func_021C1D0C(int a, int b, int c)
{
    func_021C1FC4((void *)a, (char *)b, c);
    func_021C2238((u16 *)a, (u8 *)b, c);
}







void func_021C1D24(void *a, int b, int c)
{
    func_021C1920(a, (u8 *)b, c, 4);
}





void func_021C1D30(u16 *heap, u8 *p, int key)
{
    void *str;
    Pt_021C0C14 pt;

    W(0x28) = 0;
    func_0201C6EC((struct PrintSys *)W(0x38));
    func_02043B5C(func_02045770((struct Descriptor *)W(0x18)), 0);
    if (p[0x79] != 0xff) {
        str = func_02045EC0((struct MsgBank *)W(0x10), func_02013E4C(func_021BBB3C((char *)W(0x3c8), p[0x79], 0)));
        func_0201C724((void *)W(0x38), (u32)func_02045770((struct Descriptor *)W(0x18)), 0, 1, (u32)str, W(4), 0x3c40);
        func_02045808(str);
        W(0x28) = 1;
        func_021C0740(heap, p, key, 1);
        pt.x = func_021BBB3C((char *)W(0x3c8), p[0x79], 2);
        pt.y = func_021BBB3C((char *)W(0x3c8), p[0x79], 3);
        func_0204B878((struct Obj *)W(0xd0), 5);
        func_0204B404((struct Obj *)W(0xd0), (const struct Vec2 *)(&pt), 0);
        func_0204B3DC((struct Obj *)W(0xd0), 1);
    } else {
        func_02045334((struct Descriptor *)W(0x18));
        func_0204B3DC((struct Obj *)W(0xd0), 0);
    }
}

#undef W


#define W(o) (*(u32 *)(p + (o)))

#undef OBJ

#define OBJ(i) (((u32 *)(p + 0xbc))[i])







void func_021C1E10(u16 *heap, u8 *p, int key, int dir, int touch)
{
    void *s;
    int other;
    u16 anim;

    s = (void *)func_021BC3B4((int *)key);
    if (W(0x8c) == 0)
        W(0x90) = ((Entry_021C1E10 *)W(0x94))[0].f1 == 0;
    else
        W(0x90) = ((Entry_021C1E10 *)W(0x94))[p[0x78]].f1 == 0;
    W(0x2c) = 0;
    func_0201C6EC((struct PrintSys *)W(0x3c));
    func_02043B5C(func_02045770((struct Descriptor *)W(0x1c)), 0);
    func_021C1F50(heap, p, key);
    if (dir) {
        p[0xd8] = 2;
        anim = 3;
        other = 1;
    } else {
        p[0xd8] = 1;
        anim = 5;
        other = 2;
    }
    func_0204B878((struct Obj *)OBJ(p[0xd8]), anim);
    func_0204B92C((struct Obj *)OBJ(other), 0);
    func_0204B8C4((struct Obj *)OBJ(other), 0);
    func_021BDC48((struct Ov208Scene *)s, 0);
    if (touch == 1) {
        func_0204B3DC((struct Obj *)W(0xcc), 0);
    } else if (W(0x6c) == 5 && W(0x90) == 1) {
        func_021C0CCC(heap, p, key);
        func_021C1D30(heap, p, key);
    }
    func_021C1FC4(heap, (char *)p, key);
    func_021C2238(heap, p, key);
}








/*
 * Forwards to func_0204A39C with the first argument less one and an out slot.
 */
void *func_021C1F28(int a, int b, int c)
{
    int out;

    return func_0204A39C((void *)c, a - 1, 0, b, (u32 *)(&out));
}








void func_021C1F44(int a)
{
    if (a != 0)
        func_020307B0((void *)a);
}







void func_021C1F50(u16 *heap, u8 *p, int key)
{
    void *str;
    u16 tw;
    u32 w;

    str = func_02045EC0((struct MsgBank *)W(0xc), p[0x78] + 0xbe);
    tw = func_0201D304(str, W(4), 0);
    w = func_020437DC(func_02045770((struct Descriptor *)W(0x1c)));
    func_0201C724((void *)W(0x3c), (u32)func_02045770((struct Descriptor *)W(0x1c)), (s16_021C1E10)((u16)((int)(w - tw) / 2)), (s16_021C1E10)1, (u32)str, W(4), 0x3c40);
    func_02045808(str);
    W(0x2c) = 1;
    func_021C0740(heap, p, key, 2);
}







/*
 * Dispatches on the word at +0x6C: state 0 hands a 3, state 5 hands an 8 to func_021C1920.
 */
void func_021C1FC4(void *a, char *b, int c)
{
    int s = ((struct Obj00081 *)b)->f6C;

    if (s == 0) {
        func_021C1920(a, (u8 *)b, c, 3);
        return;
    }
    if (s == 5) {
        func_021C1920(a, (u8 *)b, c, 8);
    }
}






void func_021C1FE0(u16 *heap, u8 *p, int key)
{
    u8 i;
    if (func_0204B3F4(*(struct Obj * *)&((struct Obj00081 *)p)->fC8)) {
        if (((struct Obj00081 *)p)->f90 == 1) {
            ((struct Obj00081 *)p)->f30 = 0;
            func_0201C6EC(*(struct PrintSys * *)&((struct Obj00081 *)p)->f40);
            func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00081 *)p)->f20), 0);
            func_02045334(*(struct Descriptor * *)&((struct Obj00081 *)p)->f20);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00081 *)p)->fC8, 0);
        }
    } else {
        for (i = 0; i < 61; i++) func_0204B3DC(*(struct Obj **)(p + i * 4 + 0xdc), 0);
        if (((struct Obj00081 *)p)->f90 == 0) {
            func_021C0C8C(heap, p, key, 0);
            p[0x79] = 255;
            func_0204B3DC(*(struct Obj * *)&((struct Obj00081 *)p)->fCC, 0);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00081 *)p)->fD0, 0);
            func_021C1D30(heap, p, key);
            func_021C2238(heap, p, key);
        }
    }
}






void func_021C2090(void *unused, u8 *p)
{
    if (func_0204B3F4((struct Obj *)(*(int *)&((struct Obj00081 *)p)->fC8)) == 0) {
        if (*(int *)&((struct Obj00081 *)p)->f90 == 0) {
            p[0x414] = 1;
        } else {
            p[0x414] = 2;
        }
    }
}






void func_021C20C0(void *a0, u8 *st, void *a2)
{
    int res = func_0204B3F4((struct Obj *)(*(int *)&((struct Obj00081 *)st)->fC8));

    if (((struct Obj00081 *)st)->f90 == 0) {
        if (res == 0) {
            void *msg;
            u32 w;
            int d;
            int h;
            u32 t;

            msg = func_02045EC0(((struct Obj00081 *)st)->fC, 0x80);
            w = (u16)sub_0201D304(msg, ((struct Obj00081 *)st)->f4, 0);
            h = func_020437DC((const struct Bmp *)((u32)func_02045770(((struct Obj00081 *)st)->f20)));
            t = (u32)func_02045770(((struct Obj00081 *)st)->f20);
            d = h - w;
            sub_0201C724(((struct Obj00081 *)st)->f40, t, (s16_021C20C0)(u16)(d / 2), 1, (u32)msg, ((struct Obj00081 *)st)->f4, 0x3c40);
            func_02045808(msg);
            ((struct Obj00081 *)st)->f30 = 1;
            func_021C0740((u16 *)a0, st, (int)a2, 3);
            func_0204B3DC((struct Obj *)*(int *)&((struct Obj00081 *)st)->fC8, 1);
        }
    } else {
        u8 i;
        u8 v;
        u8 *tbl;

        v = ((struct Obj00081 *)st)->f8C == 0 ? 0 : st[0x78];
        for (i = 0; i < 0x3d; i++) {
            tbl = *(u8 * *)&((struct Obj00081 *)st)->f94;
            if (tbl[v * 0x3e + st[0x3cc + i] + 2] != 0 && *(u32 *)(st + 0x1e0 + i * 8) != 1) {
                func_0204B3DC((struct Obj *)*(int *)(st + 0xdc + i * 4), 1);
            }
        }
        if (func_021C0CC0(a0, st, a2) == 0) {
            func_021C0C8C((u16 *)a0, st, (int)a2, 1);
        }
    }
}





void func_021C21D0(void *unused, char *p, int key)
{
    u8 i;
    if (func_0204B3F4(*(struct Obj * *)&((struct Obj00081 *)p)->fC8)) {
        ((struct Obj00081 *)p)->f30 = 0;
        func_0201C6EC(*(struct PrintSys * *)&((struct Obj00081 *)p)->f40);
        func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00081 *)p)->f20), 0);
        func_02045334(*(struct Descriptor * *)&((struct Obj00081 *)p)->f20);
        func_0204B3DC(*(struct Obj * *)&((struct Obj00081 *)p)->fC8, 0);
    } else {
        for (i = 0; i < 61; i++) func_0204B3DC(*(struct Obj **)(p + i * 4 + 0xdc), 0);
    }
}






void ov208_func_021C2228(u16 *heap, u8 *p, int key)
{
    p[0x414] = 3;
}





void ov208_func_021C2234(u16 *heap, u8 *p, int key)
{
}





/*
 * note: 2026-10-05 (D6-04): closed by declaring data_021C8E1A non-const; the
 *   image keeps the x0 table load below the stack argument stores (a plain
 *   extern cannot move past them).
 */
void func_021C2238(u16 *heap, u8 *p, int key)
{
    u8 on[3] = {0, 0, 0};
    u8 idx, k, i;

    if (W(0x90) == 1 && p[0x79] != 0xff) {
        idx = W(0x8c) != 0 ? p[0x78] : 0;
        k = (p + p[0x79])[0x3cc];
        if ((*(Entry_021C2234 **)(p + 0x94))[idx].b[k] & 7)
            on[0] = 1;
        if ((*(Entry_021C2234 **)(p + 0x94))[idx].b[k] & 0x18)
            on[1] = 1;
        if ((*(Entry_021C2234 **)(p + 0x94))[idx].b[k] & 0x60)
            on[2] = 1;
    }
    for (i = 0; i < 3; i++)
        func_020413B0(7, data_021C8E1A[i][0], data_021C8E1A[i][1], data_021C8E1A[i][2],
                      data_021C8E1A[i][3], data_021C8E14[i][on[i]]);
    func_02041B6C(7);
}





/*
 * Writes 4 on the stack and calls the SDK function at 0x0207D63C with
 * (0x04000050, 0, 0x3F, 0xC, 4).
 *
 * Promoted from MATCH by the recursive-unblocker lane: 0x0207D63C is the ARM
 * SDK symbol G2x_SetBlendAlpha_, and the `sdk` class attests the call once
 * the symbols block declares `arm`.  The old `thumb` declaration fought the
 * image's ISA and suppressed the witness.  Verified EXACT, 24 bytes.
 */
void func_021C2304(char *a0)
{
    func_0207D63C((volatile void *)0x04000050, 0, 0x3f, 0xc, 4);
}





/*
 * Loads the word at +0x418 and tail-calls func_021BC518 with it.
 */
void func_021C231C(char *p)
{
    func_021BC518((int *)(((struct Obj18287 *)p)->f418));
}




static inline void GX_SetVisibleWnd(int window)
{
    REG32(0x04000000) = (u32)((REG32(0x04000000) & ~0xe000) | (window << 13));
}




static inline void G2_SetWnd0Position(int x1, int y1, int x2, int y2)
{
    REG16(0x04000040) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(0x04000044) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}




static inline void G2_SetWnd1Position(int x1, int y1, int x2, int y2)
{
    REG16(0x04000042) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(0x04000046) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}




static inline void G2_SetWnd0InsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (REG16(0x04000048) & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    REG16(0x04000048) = (u16)tmp;
}




static inline void G2_SetWnd1InsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (REG16(0x04000048) & ~0x3f00) | ((u32)wnd << 8);
    if (effect) tmp |= 0x2000;
    REG16(0x04000048) = (u16)tmp;
}




static inline void G2_SetWndOutsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (REG16(0x0400004a) & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    REG16(0x0400004a) = (u16)tmp;
}




void func_021C232C(char *p)
{
    GX_SetVisibleWnd(3);
    G2_SetWnd0Position(0, 0, 160, 168);
    G2_SetWnd1Position(160, 0, 0, 168);
    G2_SetWnd0InsidePlane(31, 1);
    G2_SetWnd1InsidePlane(31, 1);
    G2_SetWndOutsidePlane(31, 0);
    func_021C2430((u8 *)p);
}





/*
 * Masks 0x04000000 with 0xFFFF1FFF, then tail-calls func_021BC518 on the word at +0x418.
 */
void func_021C239C(char *p)
{
    *(volatile unsigned int *)0x04000000 &= 0xffff1fff;
    func_021BC518((int *)(((struct Obj18288 *)p)->f418));
}


#undef OBJ

#undef OBJ
#define OBJ(p) (*(void **)((p) + *(int *)((p) + 0x5c) * 4 + 0x54))


#undef W

#undef W




#define W(o) (*(u32 *)(p + (o)))








void ov208_func_021C23BC(u8 *p)
{
    func_0207D63C((volatile void *)0x04000050, 0, 0x3f, W(0x1d8), 16 - W(0x1d8));
    if (H(0x1dc) + 0x400u >= 0x10000)
        H(0x1dc) = H(0x1dc) - 0xfc00;
    else
        H(0x1dc) += 0x400;
    W(0x1d8) = ((s16_021C23BC)((FX_SinCosTable_[(H(0x1dc) >> 4) * 2 + 1] + 0x1000) / 2) * 14 >> 12) + 1;
}









void func_021C2430(u8 *p)
{
    One one = ONE;
    ((struct Obj14657 *)p)->f1D8 = one;
    ((struct Obj14657 *)p)->f1DC = one << 15;
    func_0207D63C((volatile void *)0x04000050, 0, 0x3f, one, 16 - one);
}









void ov208_func_021C2458(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 7; i++) {
        if (i != 3)
            func_0204B688((struct Actor *)(*(u32 *)(p + i * 4 + 0xbc)), 0);
    }
    for (i = 0; i < 0x3d; i++) {
        if (*(u32 *)(p + i * 8 + 0x1e0) == 2)
            func_0204B688((struct Actor *)(*(u32 *)(p + i * 8 + 0x1e4)), 0);
    }
}








void ov208_func_021C24A4(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 7; i++) {
        if (i != 3)
            func_0204B688((struct Actor *)(*(u32 *)(p + i * 4 + 0xbc)), 1);
    }
    for (i = 0; i < 0x3d; i++) {
        if (*(u32 *)(p + i * 8 + 0x1e0) == 2)
            func_0204B688((struct Actor *)(*(u32 *)(p + i * 8 + 0x1e4)), 1);
    }
}








void ov208_func_021C24F0(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (((u32 *)(p + 0x5c))[i] != 0)
            func_0204B688((struct Actor *)(((u32 *)(p + 0x5c))[i]), 0);
    }
    func_0207D63C((volatile void *)0x04001050, 8, 0x3f, 12, 4);
}








void ov208_func_021C252C(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (((u32 *)(p + 0x5c))[i] != 0)
            func_0204B688((struct Actor *)(((u32 *)(p + 0x5c))[i]), 1);
    }
    ov208_func_021BC518(((struct Obj10905 *)p)->f41C);
}








void func_021C255C(u16 *dst, u16 value)
{
    *dst = value;
}





#undef W




#undef W



#undef W


#undef W

#undef W

#define W(o) (*(u32 *)(p+(o)))







u32 func_021C2560(void *a0, u32 a1, u16 *desc, u32 a3, int *obj)
{
    struct S_021C23BC *st;
    u8 i;

    st = func_021BC32C(a0, 0xd4, *desc);
    func_02082BCC(st, 0, 0xd4);
    i = 0;
    st->f0 = ov208_func_021BCF4C(func_021BC3A8(obj));
    st->f4 = func_021BC3AC(obj);
    st->f8 = func_021BC3B0(obj);
    st->f1c = 0;
    st->f68 = 0;
    st->f74 = 0;
    st->f76 = 1;
    st->fb8 = 0;
    func_021C2BE0(desc, (u8 *)st, obj);
    st->fbc = (u32)func_020056A0((unsigned)func_021C2BA8, (unsigned)st, 1);
    st->fc0 = (u32)func_021BC448(*desc);
    st->fc4 = (u32)func_021BC448(*desc);
    func_021BC518((int *)st->fc0);
    func_021BC518((int *)st->fc4);
    func_021BC508(0, (int *)st->fc0);
    func_021BC508(1, (int *)st->fc4);
    st->fc8 = (u32)func_021BC610(*desc);
    st->fcc = 0;
    st->fd0 = 1;
    for (i = 0; i < 2; i++) {
        st->a54[i] = 0;
    }
    st->f5c = 0;
    return 1;
}







u32 func_021C2644(void *a0, u32 a1, void *a2, u8 *st, void *a4)
{
    u8 i;

    if (func_02006650() != 0) {
        func_020065D8();
    }
    func_021C3638(a2, (char *)st, a4);
    func_021BC97C(*(char * *)&((struct Obj03934 *)st)->f80);
    func_021BC97C(*(char * *)&((struct Obj03934 *)st)->f7C);
    func_021BCA54(2, ((struct Obj03934 *)st)->f78);
    for (i = 0; i < 2; i++) {
        func_021C2FEC(a2, (struct S_021C2FEC *)((struct S_021C23BC *)st), (u32)a4, i);
    }
    func_021C32FC(a2, st, (int)a4);
    func_021C3268(a2, (char *)st, a4);
    func_021C337C(a2, st, a4);
    func_021C3374(a2, st, a4);
    func_021C2D88(a2, st, a4);
    func_021BC61C(*(char * *)&((struct Obj03934 *)st)->fC8);
    func_021BC464(*(char * *)&((struct Obj03934 *)st)->fC4);
    func_021BC464(*(char * *)&((struct Obj03934 *)st)->fC0);
    if (((struct Obj03934 *)st)->fB8 != 3) {
        func_021C2BF4(a2, (char *)st, a4);
    }
    func_02030EAC(((struct Obj03934 *)st)->fBC);
    func_021BC34C((char *)a0);
    return 1;
}






/* Explicit caller r2 loads preserve trailing arguments on setup/update helpers. */
int func_021C270C(void *unused,int *seq,u16 *heap,u8 *p,int key)
{
    void *scene;
    struct Ov208Icon *icon;
    u8 i;
    int ready;
    scene=(void *)func_021BC3B4((int *)key);
    icon=(struct Ov208Icon *)func_021BC3B8((char *)key);
    switch(*seq){
    case 0:
        *seq=1;
        for(i=0;i<=7;i++){
            if(i!=1 && i!=5){
                func_02040618(i,0,0);
                func_02040618(i,3,0);
                func_020414AC(i);
            }
        }
        func_0204047C(2,1);
        func_0204047C(3,2);
        func_0204047C(0,3);
        func_0204047C(6,1);
        func_0204047C(4,3);
        func_021C2C44(heap, (struct S_021C2C44 *)((struct S_021C23BC *)p), key);
        func_021C2E6C(heap,p,key,W(0x5c));
        func_0204B688((struct Actor *)(*(u32 *)((p+W(0x5c)*4)+0x54)),1);
        func_021C3218(heap,p,key);
        func_021C3280(heap,p,(struct Key *)key);
        func_021C3354(heap,p,key);
        func_021C3378(heap,p,key,0,0);
        W(0x78)=func_021BC9BC(0,*heap,2,1,0,5,0x9f,1,0xb,0x2a,0);
        W(0x7c)=(u32)func_021BC844(*heap,2,0,2,3);
        W(0x80)=(u32)func_021BC844(*heap,2,4,1,2);
        func_021C2DE0(heap,p,(void *)key,0,0);
        func_021C35DC(heap,p,key);
        func_021BC758((struct Ov208PalFade *)W(0xc8));
        func_021BC718((char *)W(0xc8));
        break;
    case 1:
        *seq=2;
        func_021BC4F4(0,(int *)W(0xc0));
        func_021BC4F4(1,(int *)W(0xc4));
        func_021C3AA8(heap,p,key);
        break;
    case 2:
        *seq=3;
        func_021BC6D8((char *)W(0xc8));
        if(func_021BDAD0(scene)!=2){
            func_021BDAAC(scene,0,2,func_021BC3BC((int *)((char *)key))>1);
            func_021BDAD4(scene,0);
        }else func_021BDBB8(scene,2);
        func_021BDC48(scene,0);
        func_021BDC14((struct Ov208Scene *)scene, func_02012BF8(func_021BC3A4((int *)key),0x13));
        if(func_021BE840(icon)!=2){
            func_021BE82C(icon,2);
            func_021BE844(icon);
        }
        break;
    case 3:
        if(func_021BC6C8((char *)W(0xc8))==0 && func_021BDAD0(scene)==2 && func_021BE840(icon)==2){
            func_021BDBA0(scene);
            func_021BDC48(scene,1);
            *seq=4;
        }
        break;
    case 4:
        if(W(0xcc)!=0){
            *seq=5;
            func_021BC6F8((char *)W(0xc8));
            func_021BE854(icon);
            if(W(0xcc)==2)func_021BDAE8((struct Ov208Scene *)scene, 0);
            func_021C2BF4(heap,(char *)p,(void *)key);
        }else func_021C3514(heap,p,key);
        break;
    case 5:
        ready=0;
        if(func_021BC6C8((char *)W(0xc8))==0 && func_021BE840(icon)==0){
            if(W(0xcc)==2){
                if(func_021BDAD0(scene)==0)ready=1;
            }else ready=1;
        }
        if(ready)*seq=6;
        break;
    case 6:
        *seq=7;
        func_021C3B14(heap,p,key);
        func_021BC508(0,(int *)W(0xc0));
        func_021BC508(1,(int *)W(0xc4));
        break;
    case 7:
        return 1;
    }
    if(*seq>=3){
        func_021C3380(heap,p,key);
        func_021C3650(heap,p,key);
        func_021C301C(heap,p,key);
    }
    if(*seq>=2){
        func_021C3318(heap,p,key);
        func_021BC99C((char *)W(0x7c));
        func_021BC99C((char *)W(0x80));
    }
    func_021BC46C((struct Ov208Blend *)W(0xc0),(struct Ov208Blend *)W(0xc4));
    func_021BC678((char *)W(0xc8));
    func_021C2C1C((int)heap,(char *)p,key);
    return 0;
}






void func_021C2A70(void *a0, void *a1, void *heap, struct S_021C2A70 *st, int *obj, int key)
{
    int sc;
    u32 flag;

    if (st == 0) {
        return;
    }
    sc = func_021BC3B4(obj);
    flag = 0;
    switch (key) {
    case 17:
        break;
    case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 18:
        st->fd0 = flag;
        break;
    }
    switch (key) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 9:
        flag = 1;
        st->fd0 = flag;
        break;
    }
    switch (key) {
    case 12: {
        u16 old = func_021BC3C0(obj);
        func_021BC3CC((char *)obj);
        if (old != func_021BC3C0(obj)) {
            func_021C34A4(heap, (u8 *)st, (int)obj);
        }
        break;
    }
    case 13: {
        u16 old = func_021BC3C0(obj);
        func_021BC40C((struct Ov208Cur *)obj);
        if (old != func_021BC3C0(obj)) {
            func_021C34A4(heap, (u8 *)st, (int)obj);
        }
        break;
    }
    }
    switch (key) {
    case 0:
        break;
    case 1: case 2:
        st->fcc = 2;
        return;
    case 6: case 7: case 9:
        st->fcc = 1;
        return;
    case 3:
        func_021BDBA0((struct Ov208Scene *)sc);
        return;
    case 4:
        func_021BDBA0((struct Ov208Scene *)sc);
        return;
    case 5:
        func_02012BE0((void *)func_021BC3A4(obj), 0x13, func_021BDC2C((char *)sc));
        func_021BDBA0((struct Ov208Scene *)sc);
        return;
    default:
        if (flag != 0) {
            func_021BDBA0((struct Ov208Scene *)sc);
        }
        break;
    }
}






void func_021C2BA8(void *unused, u8 *p)
{
    if (((struct Obj08403 *)p)->f1C != 0) {
        func_02040618(3, 0, ((struct Obj08403 *)p)->f18 - 1);
        func_02040618(3, 3, 0);
        func_020409B4(3);
        ((struct Obj08403 *)p)->f1C = 0;
    }
    func_021BC6BC(*(char * *)&((struct Obj08403 *)p)->fC8);
}






void func_021C2BE0(void *unused, u8 *p, void *a2)
{
    func_02005E30(0x1e);
    ((struct Obj25506 *)p)->fB8 = 1;
}






/*
 * Leaves state 2 and moves the object at +0xB8 to state 3.
 */
void func_021C2BF4(void *unused, char *p, void *a2)
{
    if (((struct Obj00146 *)p)->fB8 == 2) {
        func_02005E9C();
        func_02005DE4(0);
    }
    func_02005DF8(0x3c);
    ((struct Obj00146 *)p)->fB8 = 3;
}





/*
 * Moves the object at +0xB8 from state 1 to state 2.
 */
void func_021C2C1C(int unused, char *p, int a2)
{
    if (((struct Obj00146 *)p)->fB8 == 1) {
        if (func_02005E50() == 0) {
            func_02005DE4((void *)1);
            func_02005E64();
            ((struct Obj00146 *)p)->fB8 = 2;
        }
    }
}





/*
 * note: 2026-10-05 (wave D4 lane 02): the loop back edge in the image goes to the memset call,
 *         so the memset is the first statement of the loop body. The loop-invariant &pos
 *         (add r7, sp, #0x10) is then hoisted into the preheader, before the call.
 */
void func_021C2C44(u16 *heap, struct S_021C2C44 *st, int a2)
{
    int arc;
    u8 i;
    ObjPos_021C1E10 pos;

    arc = (int)func_020490F4(0x9f, *heap);
    i = 0;
    st->a84[1] = func_0204AC18((void *)arc, 3, 0, 0, 0, 4, *heap);
    st->a84[0] = func_0204A6C8((void *)arc, 0xd, 0, 0, *heap);
    st->a84[2] = func_0204AF28((void *)arc, 0x1b, 0x2c, *heap);
    st->a84[4] = func_0204AC18((void *)arc, 8, 1, 0x40, 0, 1, *heap);
    st->a84[3] = func_0204A6C8((void *)arc, 0x18, 0, 1, *heap);
    st->a84[5] = func_0204AF28((void *)arc, 0x1e, 0x2f, *heap);
    func_02049238((void *)arc);
    do {
        const u8 *e;
        func_02082BCC(&pos, 0, 8);
        e = data_021C8704[i];
        pos.a = e[0];
        pos.b = e[1];
        pos.c = e[2];
        pos.d = e[3];
        pos.e = e[4];
        st->a9c[i] = (u32)func_0204B294((u32)st->f0, st->a84[e[5]], st->a84[e[6]], st->a84[e[7]], &pos, e[8], *heap);
        func_0204B3DC((struct Obj *)st->a9c[i], 1);
        func_0204B688((struct Actor *)st->a9c[i], 1);
        i++;
    } while (i < 7);
    func_0204B92C((struct Obj *)st->a9c[6], 1);
}




void func_021C2D88(void *unused, u8 *p, void *a2)
{
    u8 i;
    for (i = 0; i < 7; i++)
        func_0204B3B4(*(struct Obj **)(p + i * 4 + 0x9c));
    func_0204ADA4(((struct Obj05541 *)p)->f88);
    func_0204A8D4(((struct Obj05541 *)p)->f84);
    func_0204AFD8(((struct Obj05541 *)p)->f8C);
    func_0204ADA4(((struct Obj05541 *)p)->f94);
    func_0204A8D4(((struct Obj05541 *)p)->f90);
    func_0204AFD8(((struct Obj05541 *)p)->f98);
}




void func_021C2DE0(void *unused,u8 *p,void *unused2,int first,u16 second)
{
    struct Indices ids;
    u16 digits[4];
    u8 i;
    ids=data_021C86EC;
    digits[0]=first/10;
    if(digits[0]>9)digits[0]=9;
    digits[1]=first%10;
    digits[2]=second/10;
    if(digits[2]>9)digits[2]=9;
    digits[3]=second%10;
    for(i=0;i<4;i++)
        func_0204B908((int)(*(struct Obj **)(p+ids.v[i]*4+0x9c)),digits[i]);
}




void func_021C2E6C(u16 *heap,u8 *p,int key,u32 slot)
{
    struct Desc desc;
    u32 form,b,a;
    u32 arc,special,species;
    void *ctx;
    species=func_021BC3C0((void *)key);
    special=0;
    ctx=func_0200CA1C((void *)func_021BC3A4((int *)key));
    func_0200CC40(ctx,species,&form,&b,&a,*heap);
    if(species==327)special=func_0200D288(ctx,special);
    arc=func_0202D7C8(*heap);
    *(u32 *)((u32)p+0x44+slot*4)=func_0202D81C(arc,species,a,form,b,0,0,special,1,*heap);
    *(u32 *)((u32)p+0x3c+slot*4)=func_0202D7D8(arc,species,a,form,b,0,0,1,(u16)(slot<<5),*heap);
    *(u32 *)((u32)p+0x4c+slot*4)=func_0202D898(species,a,form,b,0,0,2,1,*heap);
    func_021BC738(((struct Obj00146 *)p)->fC8,arc,func_0202D0D4(func_0202D060(),species,a,form,b,0,0),*heap,3,32,(u16)(slot<<4),0);
    func_02049238((void *)arc);
    func_02082BCC(&desc,0,24);
    desc.x=128;desc.y=128;desc.z=0;desc.a=0;desc.b=0;desc.c=0;desc.d=0;
    desc.sx=4096;desc.sy=4096;desc.e=0;desc.f=2;
    *(u32 *)((u32)p+0x54+slot*4)=(u32)func_0204B324(((struct Obj00146 *)p)->f0,*(u32 *)((u32)p+0x44+slot*4),*(u32 *)((u32)p+0x3c+slot*4),*(u32 *)((u32)p+0x4c+slot*4),(u32)(&desc),1,*heap);
    func_0204B688((struct Actor *)(*(u32 *)((u32)p+0x54+slot*4)),0);
    ((struct Obj00146 *)p)->f60=0;
}





void func_021C2FEC(void *unused, struct S_021C2FEC *p, u32 unused2, u32 i)
{
    if (p->a54[i] != 0) {
        func_0204B3B4((struct Obj *)p->a54[i]);
        p->a54[i] = 0;
        func_0204ADA4(p->a3c[i]);
        func_0204A8D4(p->a44[i]);
        func_0204AFD8(p->a4c[i]);
    }
}





void ov208_func_021C301C(u16 *heap, u8 *p, int key)
{
    struct Pos_021C1E10 pos;
    struct Pair sc;
    float f;
    switch (((struct Obj10906 *)p)->f60) {
    case 0:
    case 2:
        break;
    case 1:
        func_0204B454(OBJ(p), (struct PtS *)&pos, 1);
        func_0204B5C0(OBJ(p), &sc);
        f = (float)sc.y / 4096.0f;
        f += 0.01f;
        if (f >= 1.1f) {
            f = 1.1f;
            ((struct Obj10906 *)p)->f60 = 2;
        }
        pos.y = 0x80 - (int)(96.0f * (f - 1.0f) / 2.0f);
        if (f > 0.0f)
            sc.y = (int)(4096.0f * f + 0.5f);
        else
            sc.y = (int)(4096.0f * f - 0.5f);
        func_0204B404(OBJ(p), (const struct Vec2 *)(&pos), 1);
        func_0204B5AC(OBJ(p), &sc);
        break;
    case 3:
        func_0204B454(OBJ(p), (struct PtS *)&pos, 1);
        func_0204B5C0(OBJ(p), &sc);
        f = (float)sc.y / 4096.0f - 0.01f;
        if (f <= 1.0f) {
            f = 1.0f;
            ((struct Obj10906 *)p)->f60 = 0;
            pos.y = 0x80;
        } else {
            pos.y = 0x80 - (int)(96.0f * (f - 1.0f) / 2.0f);
        }
        if (f > 0.0f)
            sc.y = (int)(4096.0f * f + 0.5f);
        else
            sc.y = (int)(4096.0f * f - 0.5f);
        func_0204B404(OBJ(p), (const struct Vec2 *)(&pos), 1);
        func_0204B5AC(OBJ(p), &sc);
        break;
    }
}
