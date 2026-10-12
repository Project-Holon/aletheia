/*
 * file:     btl_server_p01.c
 * unit:     yes
 * function: func_021B8CB0, func_021B8CE8, func_021B8CFC, func_021B8D08, func_021B8D38, func_021B8D8C, func_021B8DC0, func_021B8DDC, func_021B8DE4, func_021B8DEC, func_021B8E28, func_021B8E70, func_021B8ED8, func_021B8F38, func_021B8F5C, func_021B8F7C, func_021B8FC0, func_021B8FE4, func_021B8FF4, func_021B9000, func_021B9010, func_021B902C, func_021B904C, func_021B9064, func_021B9090, func_021B90BC, func_021B90E8, func_021B90F0, func_021B90F8, func_021B9114, func_021B911C, func_021B9120, func_021B916C, func_021B917C, func_021B9184, func_021B919C, func_021B91E4, func_021B9210, func_021B9234, func_021B9244, func_021B92A0, func_021B92B0, func_021B92D4, func_021B9358, func_021B937C, func_021B93E0, func_021B9424, func_021B9460, func_021B9634, func_021B9674, func_021B969C, func_021B97A0, func_021B985C, func_021B9864, func_021B98A4, func_021B98AC, func_021B990C, func_021B9920, func_021B9934, func_021B9940, func_021B994C, func_021B997C, func_021B99B8, func_021B99C0, func_021B99E0, func_021B99F0, func_021B9A00, func_021B9A24, func_021B9A40, func_021B9A50, func_021B9A5C, func_021B9A6C, func_021B9AB0, func_021B9AC8, func_021B9AE0, func_021B9AEC, func_021B9AF8, func_021B9B04, func_021B9B10, func_021B9B40, func_021B9B54, func_021B9B60, func_021B9B94, func_021B9B98, func_021B9BC4, func_021B9BF0, func_021B9C00, func_021B9C10, func_021B9C24, func_021B9C50, func_021B9C98, func_021B9CBC, func_021B9CE8, func_021B9D10, func_021B9DB8, func_021B9DE8, func_021B9E38, func_021B9E7C, func_021B9EF0, func_021B9F70, func_021B9F84, func_021B9FAC, func_021B9FBC, func_021BA004, func_021BA020, func_021BA02C, func_021BA064, func_021BA080, func_021BA08C, func_021BA094, func_021BA0CC, func_021BA128, func_021BA178, func_021BA1A8, func_021BA1B4, func_021BA1CC, func_021BA1E4, func_021BA1EC, func_021BA20C, func_021BA238, func_021BA250, func_021BA2D4, func_021BA2E4, func_021BA534, func_021BA54C, func_021BA5C4, func_021BA5D0, func_021BA5D8, func_021BA618, func_021BA648, func_021BA670, func_021BA698, func_021BA6C0, func_021BA710, func_021BA73C, func_021BA7F8, func_021BA820, func_021BA82C, func_021BA878, func_021BA9C8, func_021BAA94, func_021BAACC, func_021BAB10, func_021BAB40, func_021BAB5C, func_021BAB9C, func_021BABDC, func_021BABEC, func_021BABF4, func_021BAC04, func_021BACAC, func_021BAE60, func_021BAEF8, func_021BB040, func_021BB0A0, func_021BB0E0, func_021BB208, func_021BB280, func_021BB320, func_021BB368, func_021BB3B0, func_021BB3F8, func_021BB43C, func_021BB484, func_021BB4E0, func_021BB56C, func_021BB570, func_021BB5FC, func_021BB628, func_021BB650, func_021BB6A8, func_021BB718, func_021BB724, func_021BB768, func_021BB798, func_021BB7D0, func_021BB7FC, func_021BB828, func_021BB830, func_021BB840, func_021BB848, func_021BB85C, func_021BB878, func_021BB890, func_021BB8A8, func_021BB8B0, func_021BB8BC, func_021BB8DC, func_021BB908, func_021BB914, func_021BB920, func_021BB930, func_021BB964, func_021BB968, func_021BB9D0, func_021BB9D8, func_021BBB48, func_021BBB60, func_021BBC34, func_021BBC44, func_021BBCD4, func_021BBD20, func_021BBD2C, func_021BBD80, func_021BBD8C, func_021BBFA8, func_021BC0E8, func_021BC220, func_021BC2B0, func_021BC310, func_021BC360, func_021BC390, func_021BC3B0, func_021BC418, func_021BC4DC, func_021BC550, func_021BC55C, func_021BC568, func_021BC610, func_021BC874, func_021BC8EC, func_021BC948, func_021BCA08, func_021BCA50, func_021BCAAC, func_021BCB14, func_021BCB68, func_021BCB98, func_021BCC50, func_021BCCE0, func_021BCEFC, func_021BCF34, func_021BCF70, func_021BCFAC, func_021BD080, func_021BD0C0, func_021BD148, func_021BD170, func_021BD1B0, func_021BD1D0, func_021BD1E0, func_021BD200, func_021BD2B4, func_021BD338, func_021BD34C, func_021BD3E8, func_021BD43C, func_021BD4E4, func_021BD518, func_021BD554, func_021BD584, func_021BD60C, func_021BD6B8, func_021BD708, func_021BD850, func_021BD8AC, func_021BD8F0, func_021BD9D4, func_021BDA00, func_021BDB88, func_021BDBB8, func_021BDBEC, func_021BDC0C, func_021BDC2C, func_021BDC58, func_021BDC78, func_021BDC98, func_021BDD00, func_021BDD7C, func_021BDE18, func_021BDE48, func_021BDE98, func_021BE3A8, func_021BE400, func_021BE518, func_021BE52C, func_021BE550, func_021BE620, func_021BE66C, func_021BE6A8, func_021BE6EC, func_021BE7E4, func_021BE878, func_021BE8C4, func_021BE8F4, func_021BE924, func_021BE95C, func_021BE994, func_021BE9D0, func_021BEA14, func_021BEA60, func_021BEAB4, func_021BEB14, func_021BEBD8, func_021BEC08, func_021BEC2C, func_021BEC58, func_021BF04C, func_021BF0E4, func_021BF168, func_021BF1B4, func_021BF244, func_021BF27C, func_021BF2B4, func_021BF2EC, func_021BF324, func_021BF3D8, func_021BF4AC, func_021BF6E8, func_021BF78C, func_021BF83C, func_021BF8D4, func_021BF9A4, func_021BFA00, func_021BFA60, func_021BFBD0, func_021BFC08, func_021BFD24, func_021BFE60, func_021BFEAC, func_021BFF60, func_021C001C, func_021C024C, func_021C0274, func_021C02CC, func_021C031C, func_021C03AC, func_021C03D8, func_021C0404, func_021C0450, func_021C0520, func_021C0780, func_021C07AC, func_021C07D4, func_021C0898, func_021C08CC, func_021C091C, func_021C0A4C, func_021C0C34, func_021C0C38, func_021C0CB4, func_021C0CE8, func_021C0D70, func_021C0D90, func_021C0F24, func_021C1184, func_021C1194, func_021C1198, func_021C11A4, func_021C11F0, func_021C14E0, func_021C15AC, func_021C15D4, func_021C15E8, func_021C1624, func_021C1678, func_021C16F8, func_021C1758, func_021C1788, func_021C17CC, func_021C1828, func_021C1880, func_021C18D4, func_021C1910, func_021C195C, func_021C199C, func_021C19D8, func_021C1A10, func_021C1A54, func_021C1B5C, func_021C1C88, func_021C1CCC, func_021C1CE4, func_021C1D60, func_021C1DCC, func_021C1E14, func_021C1E74, func_021C2048, func_021C20BC, func_021C20D0, func_021C2128, func_021C2204, func_021C2250, func_021C2314, func_021C232C, func_021C236C, func_021C2488, func_021C25A4, func_021C264C, func_021C26A8, func_021C26FC, func_021C2758, func_021C27A0, func_021C282C, func_021C2910, func_021C2AB0, func_021C2AF0, func_021C2B3C, func_021C2BA4, func_021C2BF0, func_021C2C50, func_021C2CA8, func_021C2CD8, func_021C2D10, func_021C2DC4
 * address:  0x021B8CB0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   data_021EFCF0  0x021EFCF0  data  ov093
 *   func_021B8778  0x021B8778  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B8BEC  0x021B8BEC  thumb  ov093
 *   d_021EFCF4  0x021EFCF4  data  ov093  a1
 *   d_021EFCFA  0x021EFCFA  data  ov093  a1
 *   func_021B86C8 0x021B86C8 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021B8B9C  0x021B8B9C  thumb  ov093
 *   func_02007F1C 0x02007F1C thumb
 *   func_02007E50 0x02007E50 thumb
 *   func_0201119C  0x0201119C  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C274  0x0200C274  thumb
 *   func_021D7FF8  0x021D7FF8  thumb  ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_021B8714  0x021B8714  thumb  ov093
 *   func_0201B7A0  0x0201B7A0  thumb
 *   func_021D54F4 0x021D54F4 thumb ov093
 *   func_021D6C24  0x021D6C24  thumb  ov093
 *   func_021D5864  0x021D5864  thumb  ov093
 *   func_021D53B8 0x021D53B8 thumb ov093
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_021D4D84 0x021D4D84 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D5848 0x021D5848 thumb ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_02017E1C 0x02017E1C thumb
 *   func_020173F0 0x020173F0 thumb
 *   func_0201A948 0x0201A948 thumb
 *   func_021D6B84 0x021D6B84 thumb ov093
 *   func_0201A98C 0x0201A98C thumb
 *   func_0201AC2C 0x0201AC2C thumb
 *   func_021D6C3C 0x021D6C3C thumb ov093
 *   func_021D67D0  0x021D67D0  thumb  ov093
 *   func_02007B50 0x02007B50 thumb
 *   func_02007C70 0x02007C70 thumb
 *   func_021B6994  0x021B6994  thumb  ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   data_021EFD70  0x021EFD70  data  ov093
 *   func_021B8C20 0x021B8C20 thumb ov093
 *   func_021CD9F4 0x021CD9F4 thumb ov093
 *   func_021D5B7C 0x021D5B7C thumb ov093
 *   func_021B8B78  0x021B8B78  thumb  ov093
 *   func_021D5854  0x021D5854  thumb  ov093
 *   func_020307B0  0x020307B0  arm
 *   func_0200846C  0x0200846C  thumb
 *   func_02008494  0x02008494  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008510  0x02008510  thumb
 *   func_0202428C  0x0202428C  thumb
 *   func_02045874  0x02045874  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02024570  0x02024570  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045A00  0x02045A00  arm
 *   func_0202E7DC  0x0202E7DC  thumb
 *   func_0201A920 0x0201A920 thumb
 *   func_02013158  0x02013158  thumb
 *   sub_02008DF0 0x02008DF0 thumb
 *   sub_02008DAC 0x02008DAC thumb
 *   func_021B6818 0x021B6818 thumb ov093
 *   func_0201B7B4  0x0201B7B4  thumb
 *   func_0201B818 0x0201B818 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_021D7F60 0x021D7F60 thumb ov093
 *   func_021D805C 0x021D805C thumb ov093
 *   func_021D62A8 0x021D62A8 thumb ov093
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021D826C  0x021D826C  thumb  ov093
 *   func_021D8270  0x021D8270  thumb  ov093
 *   func_021CDDA0  0x021CDDA0  thumb  ov093
 *   func_021CDDCC 0x021CDDCC thumb ov093
 *   func_021CD924  0x021CD924  thumb  ov093
 *   func_021D787C  0x021D787C  thumb  ov093
 *   func_021B68D8  0x021B68D8  thumb  ov093
 *   func_021CD984  0x021CD984  thumb  ov093
 *   func_021E9034  0x021E9034  thumb  ov093
 *   func_021E8E28  0x021E8E28  thumb  ov093
 *   func_021E8F20  0x021E8F20  thumb  ov093
 *   func_021CD95C  0x021CD95C  thumb  ov093
 *   func_021CD9B0 0x021CD9B0 thumb ov093
 *   func_021C8138 0x021C8138 thumb ov093
 *   func_021C8140 0x021C8140 thumb ov093
 *   func_021C7CBC 0x021C7CBC thumb ov093
 *   func_021C7CC8 0x021C7CC8 thumb ov093
 *   func_021C7CD4 0x021C7CD4 thumb ov093
 *   func_021C7CDC 0x021C7CDC thumb ov093
 *   func_021C7CE8 0x021C7CE8 thumb ov093
 *   func_021D54B4 0x021D54B4 thumb ov093
 *   func_02030734 0x02030734 arm
 *   d_021F3A60 0x021F3A60 data a4
 *   func_021EEA58  0x021EEA58  thumb  ov093
 *   func_02045808  0x02045808  arm
 *   func_021EEAE0  0x021EEAE0  thumb  ov093
 *   func_021B86C0 0x021B86C0 thumb ov093
 *   func_021C84D8 0x021C84D8 thumb ov093
 *   func_021EEB64  0x021EEB64  thumb  ov093
 *   func_021B85A8  0x021B85A8  thumb  ov093
 *   func_021D8454  0x021D8454  thumb  ov093
 *   func_021EE9A4  0x021EE9A4  thumb  ov093
 *   func_021B86DC  0x021B86DC  thumb  ov093
 *   func_02005D90  0x02005D90  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_021EE9B4  0x021EE9B4  thumb  ov093
 *   func_021EE9E4  0x021EE9E4  thumb  ov093
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_021EE8B4 0x021EE8B4 thumb ov093
 *   func_021EE8D8 0x021EE8D8 thumb ov093
 *   func_021EE8F4  0x021EE8F4  thumb  ov093
 *   func_021EE96C  0x021EE96C  thumb  ov093
 *   func_021EEAE8  0x021EEAE8  thumb  ov093
 *   func_021EEB00  0x021EEB00  thumb  ov093
 *   func_021EEAFC  0x021EEAFC  thumb  ov093
 *   func_021EEB70 0x021EEB70 thumb ov093
 *   func_021EEB2C 0x021EEB2C thumb ov093
 *   func_021EEAD0 0x021EEAD0 thumb ov093
 *   func_02027268 0x02027268 thumb
 *   func_020271DC 0x020271DC thumb
 *   func_0201B70C 0x0201B70C thumb
 *   d_021F3A70 0x021F3A70 data a4
 *   func_021D6EAC 0x021D6EAC thumb ov093
 *   func_021EF874 0x021EF874 thumb ov093
 *   func_021BBB08 0x021BBB08 thumb ov093
 *   func_021BBB18 0x021BBB18 thumb ov093
 *   func_021BBB28 0x021BBB28 thumb ov093
 *   func_02082BCC 0x02082BCC arm
 *   func_021C7C18 0x021C7C18 thumb ov093
 *   func_021C8588 0x021C8588 thumb ov093
 *   func_021D8230 0x021D8230 thumb ov093
 *   func_021CC8C8 0x021CC8C8 thumb ov093
 *   func_021C5474 0x021C5474 thumb ov093
 *   func_021BBB38 0x021BBB38 thumb ov093
 *   func_02049238 0x02049238 arm
 *   func_021C3B68 0x021C3B68 thumb ov093
 *   func_021B8750 0x021B8750 thumb ov093
 *   func_021C84E8  0x021C84E8  thumb  ov093
 *   func_021BBCC4  0x021BBCC4  thumb  ov093
 *   func_021D6EE8  0x021D6EE8  thumb  ov093
 *   func_021D74E4  0x021D74E4  thumb  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021C6110  0x021C6110  thumb  ov093
 *   func_021BBF88 0x021BBF88 thumb ov093
 *   func_021BBF98 0x021BBF98 thumb ov093
 *   func_021C5200 0x021C5200 thumb ov093
 *   func_021C4614 0x021C4614 thumb ov093
 *   func_021C6158 0x021C6158 thumb ov093
 *   func_021C446C 0x021C446C thumb ov093
 *   func_021BC0D8 0x021BC0D8 thumb ov093
 *   func_021C8534 0x021C8534 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021C6350 0x021C6350 thumb ov093
 *   func_021B8BC4  0x021B8BC4  thumb  ov093
 *   func_021BC408  0x021BC408  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021C5108  0x021C5108  thumb  ov093
 *   func_021EF948  0x021EF948  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021C5620  0x021C5620  thumb  ov093
 *   func_021D8548  0x021D8548  thumb  ov093
 *   func_021DCFB4  0x021DCFB4  thumb  ov093
 *   func_021BC4CC  0x021BC4CC  thumb  ov093
 *   func_021BC540  0x021BC540  thumb  ov093
 *   func_021E02DC  0x021E02DC  thumb  ov093
 *   func_021C6394  0x021C6394  thumb  ov093
 *   func_021E0394  0x021E0394  thumb  ov093
 *   func_021D83E0  0x021D83E0  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_0201BD28  0x0201BD28  thumb
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021D7674  0x021D7674  thumb  ov093
 *   func_021D7B10  0x021D7B10  thumb  ov093
 *   func_021D8340  0x021D8340  thumb  ov093
 *   func_021C859C 0x021C859C thumb ov093
 *   func_021BCEEC 0x021BCEEC thumb ov093
 *   func_021B86E4 0x021B86E4 thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021CB730 0x021CB730 thumb ov093
 *   func_021C54BC 0x021C54BC thumb ov093
 *   func_021C60EC 0x021C60EC thumb ov093
 *   func_021C85B8 0x021C85B8 thumb ov093
 *   func_02018480 0x02018480 thumb
 *   func_021B871C 0x021B871C thumb ov093
 *   func_021B85A0 0x021B85A0 thumb ov093
 *   func_02018488 0x02018488 thumb
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021BD138  0x021BD138  thumb  ov093
 *   func_021D82FC  0x021D82FC  thumb  ov093
 *   func_021BD264  0x021BD264  thumb  ov093
 *   func_021BD274  0x021BD274  thumb  ov093
 *   func_021BD284  0x021BD284  thumb  ov093
 *   func_021BD294  0x021BD294  thumb  ov093
 *   func_021BD2A4  0x021BD2A4  thumb  ov093
 *   func_021C5D88  0x021C5D88  thumb  ov093
 *   func_021BD4D4  0x021BD4D4  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   func_021D8244 0x021D8244 thumb ov093
 *   func_021BD89C  0x021BD89C  thumb  ov093
 *   func_021D8484 0x021D8484 thumb ov093
 *   func_021DCF5C 0x021DCF5C thumb ov093
 *   func_021D63EC 0x021D63EC thumb ov093
 *   func_021D6580 0x021D6580 thumb ov093
 *   func_021BD9C4 0x021BD9C4 thumb ov093
 *   func_021BDB28 0x021BDB28 thumb ov093
 *   func_021BDB38 0x021BDB38 thumb ov093
 *   func_021BDB48 0x021BDB48 thumb ov093
 *   func_021C88E4 0x021C88E4 thumb ov093
 *   func_021BDB58 0x021BDB58 thumb ov093
 *   func_021BDB68 0x021BDB68 thumb ov093
 *   func_021BDB78 0x021BDB78 thumb ov093
 *   func_021D70FC 0x021D70FC thumb ov093
 *   func_021C6190  0x021C6190  thumb  ov093
 *   func_021D64F0  0x021D64F0  thumb  ov093
 *   func_021BDE08  0x021BDE08  thumb  ov093
 *   func_021D6314  0x021D6314  thumb  ov093
 *   func_021E8B80  0x021E8B80  thumb  ov093
 *   func_021D55A0  0x021D55A0  thumb  ov093
 *   func_021D5C08 0x021D5C08 thumb ov093
 *   func_021D80BC 0x021D80BC thumb ov093
 *   func_021D82D0 0x021D82D0 thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_021C62D8 0x021C62D8 thumb ov093
 *   func_021C5604 0x021C5604 thumb ov093
 *   func_021C64B4 0x021C64B4 thumb ov093
 *   func_021CA7F4 0x021CA7F4 thumb ov093
 *   func_021BE338 0x021BE338 thumb ov093
 *   func_021BE348 0x021BE348 thumb ov093
 *   func_021BE358 0x021BE358 thumb ov093
 *   func_021BE368 0x021BE368 thumb ov093
 *   func_021BE378 0x021BE378 thumb ov093
 *   func_021BE388 0x021BE388 thumb ov093
 *   func_021BE398 0x021BE398 thumb ov093
 *   func_021C6458 0x021C6458 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 *   func_021C8810 0x021C8810 thumb ov093
 *   func_021D6744 0x021D6744 thumb ov093
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   func_0201BEB8  0x0201BEB8  thumb
 *   func_021D7394 0x021D7394 thumb ov093
 *   func_021E03D8 0x021E03D8 thumb ov093
 *   func_021D73D4 0x021D73D4 thumb ov093
 *   d_021EFDB8 0x021EFDB8 data a2
 *   func_021D6E74 0x021D6E74 thumb ov093
 *   func_021D6E40 0x021D6E40 thumb ov093
 *   func_021C5718  0x021C5718  thumb  ov093
 *   func_021BEB04 0x021BEB04 thumb ov093
 *   func_021BEBB8  0x021BEBB8  thumb  ov093
 *   func_021BEBC8  0x021BEBC8  thumb  ov093
 *   func_0201C1BC 0x0201C1BC thumb
 *   func_021BEFEC 0x021BEFEC thumb ov093
 *   func_021BEFFC 0x021BEFFC thumb ov093
 *   func_021BF00C 0x021BF00C thumb ov093
 *   func_021BF01C 0x021BF01C thumb ov093
 *   func_021BF02C 0x021BF02C thumb ov093
 *   func_021BF03C 0x021BF03C thumb ov093
 *   func_021CD4FC 0x021CD4FC thumb ov093
 *   func_021C65A8 0x021C65A8 thumb ov093
 *   func_021CC8A0 0x021CC8A0 thumb ov093
 *   func_021C3184 0x021C3184 thumb ov093
 *   func_021C3438 0x021C3438 thumb ov093
 *   func_021C376C 0x021C376C thumb ov093
 *   func_021C3274 0x021C3274 thumb ov093
 *   func_021C3AA8 0x021C3AA8 thumb ov093
 *   func_021C3D08 0x021C3D08 thumb ov093
 *   func_021C4F64 0x021C4F64 thumb ov093
 *   func_021BF0A4  0x021BF0A4  thumb  ov093
 *   func_021BF0B4  0x021BF0B4  thumb  ov093
 *   func_021BF0C4  0x021BF0C4  thumb  ov093
 *   func_021BF0D4  0x021BF0D4  thumb  ov093
 *   func_021C572C  0x021C572C  thumb  ov093
 *   func_021BF138  0x021BF138  thumb  ov093
 *   func_021BF148  0x021BF148  thumb  ov093
 *   func_021BF158  0x021BF158  thumb  ov093
 *   func_021BF204  0x021BF204  thumb  ov093
 *   func_021BF214  0x021BF214  thumb  ov093
 *   func_021BF224  0x021BF224  thumb  ov093
 *   func_021BF234  0x021BF234  thumb  ov093
 *   func_021D6D7C  0x021D6D7C  thumb  ov093
 *   func_021BF3B8  0x021BF3B8  thumb  ov093
 *   func_021BF3C8  0x021BF3C8  thumb  ov093
 *   func_021D62D8  0x021D62D8  thumb  ov093
 *   func_021CC8B0  0x021CC8B0  thumb  ov093
 *   func_021BF46C  0x021BF46C  thumb  ov093
 *   func_021BF47C  0x021BF47C  thumb  ov093
 *   func_021BF48C  0x021BF48C  thumb  ov093
 *   func_021BF49C  0x021BF49C  thumb  ov093
 *   func_021C6E3C  0x021C6E3C  thumb  ov093
 *   func_021C7C24  0x021C7C24  thumb  ov093
 *   func_021BF5E8 0x021BF5E8 thumb ov093
 *   func_021BF5F8 0x021BF5F8 thumb ov093
 *   func_021BF608 0x021BF608 thumb ov093
 *   func_021BF618 0x021BF618 thumb ov093
 *   func_021BF628 0x021BF628 thumb ov093
 *   func_021BF638 0x021BF638 thumb ov093
 *   func_021BF648 0x021BF648 thumb ov093
 *   func_021BF658 0x021BF658 thumb ov093
 *   func_021BF668 0x021BF668 thumb ov093
 *   func_021BF678 0x021BF678 thumb ov093
 *   func_021BF688 0x021BF688 thumb ov093
 *   func_021BF698 0x021BF698 thumb ov093
 *   func_021BF6A8 0x021BF6A8 thumb ov093
 *   func_021BF6B8 0x021BF6B8 thumb ov093
 *   func_021BF6C8 0x021BF6C8 thumb ov093
 *   func_021BF6D8 0x021BF6D8 thumb ov093
 *   func_021C6668 0x021C6668 thumb ov093
 *   func_021C8828  0x021C8828  thumb  ov093
 *   func_021CC8C0  0x021CC8C0  thumb  ov093
 *   func_021BF894  0x021BF894  thumb  ov093
 *   func_021BF8A4  0x021BF8A4  thumb  ov093
 *   func_021BF8B4  0x021BF8B4  thumb  ov093
 *   func_021BF8C4  0x021BF8C4  thumb  ov093
 *   func_021C6948  0x021C6948  thumb  ov093
 *   func_021BF944  0x021BF944  thumb  ov093
 *   func_021BF954  0x021BF954  thumb  ov093
 *   func_021BF964  0x021BF964  thumb  ov093
 *   func_021BF974  0x021BF974  thumb  ov093
 *   func_021BF984  0x021BF984  thumb  ov093
 *   func_021BF994  0x021BF994  thumb  ov093
 *   func_021C69B8 0x021C69B8 thumb ov093
 *   func_021C6A04 0x021C6A04 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021D7908 0x021D7908 thumb ov093
 *   func_021CD568 0x021CD568 thumb ov093
 *   func_021C66AC 0x021C66AC thumb ov093
 *   func_021C6720 0x021C6720 thumb ov093
 *   func_021E896C 0x021E896C thumb ov093
 *   func_021C5C1C 0x021C5C1C thumb ov093
 *   func_021C6878 0x021C6878 thumb ov093
 *   func_021C68A8 0x021C68A8 thumb ov093
 *   func_021C676C 0x021C676C thumb ov093
 *   func_021BFE30 0x021BFE30 thumb ov093
 *   func_021BFE40 0x021BFE40 thumb ov093
 *   func_021BFE50 0x021BFE50 thumb ov093
 *   func_021C6848 0x021C6848 thumb ov093
 *   func_021D5C30 0x021D5C30 thumb ov093
 *   func_021E899C  0x021E899C  thumb  ov093
 *   func_021C000C  0x021C000C  thumb  ov093
 *   func_0201C314 0x0201C314 thumb
 *   func_021D5584 0x021D5584 thumb ov093
 *   func_021D67B8 0x021D67B8 thumb ov093
 *   func_021D67A8 0x021D67A8 thumb ov093
 *   func_021EF91C 0x021EF91C thumb ov093
 *   func_021D7AF0 0x021D7AF0 thumb ov093
 *   func_021C5480 0x021C5480 thumb ov093
 *   func_021C557C 0x021C557C thumb ov093
 *   func_021D61A8  0x021D61A8  thumb  ov093
 *   func_021C54C8  0x021C54C8  thumb  ov093
 *   func_021C54FC  0x021C54FC  thumb  ov093
 *   func_021D6130  0x021D6130  thumb  ov093
 *   func_021C63D0 0x021C63D0 thumb ov093
 *   func_021D7D18 0x021D7D18 thumb ov093
 *   func_021C6564 0x021C6564 thumb ov093
 *   func_021D69A0  0x021D69A0  thumb  ov093
 *   func_021C0868  0x021C0868  thumb  ov093
 *   func_021C0878  0x021C0878  thumb  ov093
 *   func_021C0888  0x021C0888  thumb  ov093
 *   func_021D5608  0x021D5608  thumb  ov093
 *   func_021D56CC  0x021D56CC  thumb  ov093
 *   func_021C0A1C 0x021C0A1C thumb ov093
 *   func_021C71E0 0x021C71E0 thumb ov093
 *   func_021C0A2C 0x021C0A2C thumb ov093
 *   func_021C0A3C 0x021C0A3C thumb ov093
 *   func_021C0C04 0x021C0C04 thumb ov093
 *   func_021C0C14 0x021C0C14 thumb ov093
 *   func_021C0C24 0x021C0C24 thumb ov093
 *   func_021C6BF8 0x021C6BF8 thumb ov093
 *   func_021CC8B8 0x021CC8B8 thumb ov093
 *   func_021C0EC4 0x021C0EC4 thumb ov093
 *   func_021C0ED4 0x021C0ED4 thumb ov093
 *   func_021C0EE4 0x021C0EE4 thumb ov093
 *   func_021C0EF4 0x021C0EF4 thumb ov093
 *   func_021C0F04 0x021C0F04 thumb ov093
 *   func_021C0F14 0x021C0F14 thumb ov093
 *   func_021C1144 0x021C1144 thumb ov093
 *   func_021C1154 0x021C1154 thumb ov093
 *   func_021C1164 0x021C1164 thumb ov093
 *   func_021C1174 0x021C1174 thumb ov093
 *   func_021B8590 0x021B8590 thumb ov093
 *   func_021C14B0  0x021C14B0  thumb  ov093
 *   func_021C14C0  0x021C14C0  thumb  ov093
 *   func_021C14D0  0x021C14D0  thumb  ov093
 *   func_021C4104  0x021C4104  thumb  ov093
 *   func_021C4218  0x021C4218  thumb  ov093
 *   func_021C5798  0x021C5798  thumb  ov093
 *   func_021C5840  0x021C5840  thumb  ov093
 *   func_021C59C4  0x021C59C4  thumb  ov093
 *   d_021F3B2C  0x021F3B2C  data  ov093  a4
 *   d_021F3B20  0x021F3B20  data  ov093  a4
 *   d_021F3B38  0x021F3B38  data  a4
 *   d_021F3B26  0x021F3B26  data  ov093  a4
 *   d_021F3B23  0x021F3B23  data  ov093  a4
 *   d_021F3B20b 0x021F3B20  data  ov093  a4
 *   func_021C156C  0x021C156C  thumb  ov093
 *   func_021C157C  0x021C157C  thumb  ov093
 *   func_021C6B5C  0x021C6B5C  thumb  ov093
 *   func_021C6BB8  0x021C6BB8  thumb  ov093
 *   func_021C158C  0x021C158C  thumb  ov093
 *   func_021C159C  0x021C159C  thumb  ov093
 *   func_021D6848  0x021D6848  thumb  ov093
 *   sub_0201C1BC   0x0201C1BC  thumb
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021C1B2C 0x021C1B2C thumb ov093
 *   func_021C1B3C 0x021C1B3C thumb ov093
 *   func_021C1B4C 0x021C1B4C thumb ov093
 *   func_021C1C48 0x021C1C48 thumb ov093
 *   func_021C1C58 0x021C1C58 thumb ov093
 *   func_021C1C68 0x021C1C68 thumb ov093
 *   func_021C1C78 0x021C1C78 thumb ov093
 *   func_021C7664 0x021C7664 thumb ov093
 *   func_021C1D30  0x021C1D30  thumb  ov093
 *   func_021C1D40  0x021C1D40  thumb  ov093
 *   func_021C1D50  0x021C1D50  thumb  ov093
 *   func_021C76F4  0x021C76F4  thumb  ov093
 *   func_021C7780  0x021C7780  thumb  ov093
 *   sub_0201BD28   0x0201BD28  thumb
 *   func_021D7B3C  0x021D7B3C  thumb  ov093
 *   func_021C78F4  0x021C78F4  thumb  ov093
 *   func_021C3370  0x021C3370  thumb  ov093
 *   func_021C334C  0x021C334C  thumb  ov093
 *   func_0201C1E8 0x0201C1E8 thumb
 *   func_021C728C 0x021C728C thumb ov093
 *   func_021C7374 0x021C7374 thumb ov093
 *   func_021C7474 0x021C7474 thumb ov093
 *   func_021D7A44 0x021D7A44 thumb ov093
 *   func_021D7C38 0x021D7C38 thumb ov093
 *   func_021C75EC 0x021C75EC thumb ov093
 *   func_021D7A6C 0x021D7A6C thumb ov093
 *   func_021C6CAC  0x021C6CAC  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C7330 0x021C7330 thumb ov093
 *   func_021C5B74  0x021C5B74  thumb  ov093
 *   func_021C21F4 0x021C21F4 thumb ov093
 *   func_021CC918 0x021CC918 thumb ov093
 *   func_021C6DD0 0x021C6DD0 thumb ov093
 *   func_021D5B44  0x021D5B44  thumb  ov093
 *   func_021C7AD0  0x021C7AD0  thumb  ov093
 *   func_021C7B0C  0x021C7B0C  thumb  ov093
 *   func_021C6134  0x021C6134  thumb  ov093
 *   func_021DCF24  0x021DCF24  thumb  ov093
 *   func_021D6730  0x021D6730  thumb  ov093
 *   func_021C5BE4 0x021C5BE4 thumb ov093
 *   sub_0201BF58 0x0201BF58 thumb
 *   func_021D7C70 0x021D7C70 thumb ov093
 *   func_021C2564 0x021C2564 thumb ov093
 *   func_021C2574 0x021C2574 thumb ov093
 *   func_021C2584 0x021C2584 thumb ov093
 *   func_021C2594 0x021C2594 thumb ov093
 *   func_021C5C74  0x021C5C74  thumb  ov093
 *   func_021D57FC 0x021D57FC thumb ov093
 *   func_021E8D24 0x021E8D24 thumb ov093
 *   func_021C2AA0 0x021C2AA0 thumb ov093
 *   func_021D8510 0x021D8510 thumb ov093
 *   func_021D66D8 0x021D66D8 thumb ov093
 *   func_021D7D6C 0x021D7D6C thumb ov093
 *   func_021C3FDC 0x021C3FDC thumb ov093
 *   func_021EF884  0x021EF884  thumb  ov093
 *   func_021D70E4 0x021D70E4 thumb ov093
 *   func_021C2E64 0x021C2E64 thumb ov093
 *   func_021C2E1C  0x021C2E1C  thumb  ov093
 *   func_021C2E2C  0x021C2E2C  thumb  ov093
 *   func_021C2E3C  0x021C2E3C  thumb  ov093
 */
#include "../../matched/include/Obj13271.h"
#include "../../matched/include/Obj07744.h"
#include "../../matched/include/Obj18132.h"
#include "../../matched/include/Obj09938.h"
#include "../../matched/include/Obj13272.h"
#include "../../matched/include/Obj09939.h"
#include "../../matched/include/Obj13273.h"
#include "../../matched/include/Obj18134.h"
#include "../../matched/include/Obj18136.h"
#include "../../matched/include/Obj13274.h"
#include "../../matched/include/Obj20977.h"
#include "../../matched/include/Obj18137.h"
#include "../../matched/include/Obj13275.h"
#include "../../matched/include/Obj06219.h"
#include "../../matched/include/Obj07745.h"
#include "../../matched/include/Obj20979.h"
#include "../../matched/include/Obj04354.h"
#include "../../matched/include/Obj20982.h"
#include "../../matched/include/Obj20983.h"
#include "../../matched/include/Obj07746.h"
#include "../../matched/include/Obj13276.h"
#include "../../matched/include/Obj13277.h"
#include "../../matched/include/Obj13278.h"
#include "../../matched/include/Obj09940.h"
#include "../../matched/include/Obj07747.h"
#include "../../matched/include/Obj13279.h"
#include "../../matched/include/Obj20992.h"
#include "../../matched/include/Obj20995.h"
#include "../../matched/include/Obj09942.h"
#include "../../matched/include/Obj03187.h"
#include "../../matched/include/Obj01371.h"
#include "../../matched/include/Obj13281.h"
#include "../../matched/include/Obj20998.h"
#include "../../matched/include/Obj20999.h"
#include "../../matched/include/Obj21000.h"
#include "../../matched/include/Obj21001.h"
#include "../../matched/include/Obj21002.h"
#include "../../matched/include/Obj21004.h"
#include "../../matched/include/Obj13284.h"
#include "../../matched/include/Obj13285.h"
#include "../../matched/include/Obj00324.h"
#include "../../matched/include/Obj21005.h"
#include "../../matched/include/Obj21009.h"
#include "../../matched/include/Obj21010.h"
#include "../../matched/include/Obj21012.h"
#include "../../matched/include/Obj21014.h"
#include "../../matched/include/Obj21015.h"
#include "../../matched/include/Obj18159.h"
#include "../../matched/include/Obj07748.h"
#include "../../matched/include/Obj21016.h"
#include "../../matched/include/Obj09944.h"
#include "../../matched/include/Obj21017.h"
#include "../../matched/include/Obj13286.h"
#include "../../matched/include/Obj13287.h"
#include "../../matched/include/Obj07743.h"
#include "../../matched/include/Obj21018.h"
#include "../../matched/include/Obj21019.h"
#include "../../matched/include/Obj02131.h"
#include "../../matched/include/Obj21020.h"
#include "../../matched/include/Obj21021.h"
#include "../../matched/include/Obj02132.h"
#include "../../matched/include/Obj01687.h"
#include "../../matched/include/Obj09945.h"
#include "../../matched/include/Obj01234.h"
#include "../../matched/include/Obj21023.h"
#include "../../matched/include/Obj13288.h"
#include "../../matched/include/Obj21024.h"
#include "../../matched/include/Obj21025.h"
#include "../../matched/include/Obj07749.h"
#include "../../matched/include/Obj13289.h"
#include "../../matched/include/Obj07750.h"
#include "../../matched/include/Obj21026.h"
#include "../../matched/include/Obj09946.h"
#include "../../matched/include/Obj01372.h"
#include "../../matched/include/Obj06222.h"
#include "../../matched/include/Obj01235.h"
#include "../../matched/include/Obj21031.h"
#include "../../matched/include/Obj21032.h"
#include "../../matched/include/Obj02775.h"
#include "../../matched/include/Obj13292.h"
#include "../../matched/include/Obj05188.h"
#include "../../matched/include/Obj21033.h"
#include "../../matched/include/Obj21034.h"
#include "../../matched/include/Obj03190.h"
#include "../../matched/include/Obj09956.h"
#include "../../matched/include/Obj13294.h"
#include "../../matched/include/Obj13295.h"
#include "../../matched/include/Obj02133.h"
#include "../../matched/include/Obj21039.h"
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj09958.h"
#include "../../matched/include/Obj02776.h"
#include "../../matched/include/Obj02777.h"
#include "../../matched/include/Obj06224.h"
#include "../../matched/include/Obj05189.h"
#include "btl_server_types.h"
#include "../../matched/include/Obj21043.h"
#include "../../matched/include/Obj13305.h"
#include "../../matched/include/Obj13306.h"
#include "../../matched/include/Obj09961.h"
#include "../../matched/include/Obj13311.h"
#include "../../matched/include/Obj21052.h"
#include "../../matched/include/Obj09962.h"
#include "../../matched/include/Obj09964.h"
#include "../../matched/include/Obj09965.h"
#include "../../matched/include/Obj21056.h"
#include "../../matched/include/Obj07752.h"
#include "../../matched/include/Obj13315.h"
#include "../../matched/include/Obj04358.h"
#include "../../matched/include/Obj13316.h"
#include "../../matched/include/Obj13317.h"
#include "../../matched/include/Obj05190.h"
#include "../../matched/include/Obj21062.h"
#include "../../matched/include/Obj04359.h"
#include "../../matched/include/Obj09966.h"
#include "../../matched/include/Obj21063.h"
#include "../../matched/include/Obj21064.h"
#include "../../matched/include/Obj21066.h"
#include "../../matched/include/Obj01373.h"
#include "../../matched/include/Obj02134.h"
#include "../../matched/include/Obj21074.h"
#include "../../matched/include/Obj21076.h"
#include "../../matched/include/Obj13320.h"
#include "../../matched/include/Obj02778.h"
#include "../../matched/include/Obj21078.h"
#include "../../matched/include/Obj09968.h"
#include "../../matched/include/Obj13323.h"
#include "../../matched/include/Obj13324.h"
#include "../../matched/include/Obj13325.h"
#include "../../matched/include/Obj21079.h"
#include "../../matched/include/Obj09967.h"
#include "../../matched/include/Obj21082.h"
#include "../../matched/include/Obj21083.h"
#include "../../matched/include/Obj21084.h"
#include "../../matched/include/Obj21085.h"

#define ENTRY(i) (&e[i])
struct Unk021B8CB0;
struct Blk34;
struct Work;
struct R4;
struct S2;
struct Q1;
struct QF;
struct QH;
struct S_021B8CB0;
struct Party;
struct PartyMon;
struct Rec534;
struct R3;
struct PerapVoice;
struct Sub0200852CObj;
struct U16Vec;
struct Rec8;
struct Buf;
struct Sub02008C20Obj;
struct Unk021D62A8;
struct Flags;
struct T;
struct QA;
struct Scene;
struct Q5;
struct Q7;
struct Q6;
struct Q4;
struct QW;
struct UtilWork;
struct Unk021BDE48;
struct Unk021D82FC;
struct B;
struct Arr;
struct Msg;
struct O;
struct Out64B4;
struct Unk021BD1E0;
struct Unk021BE518;
struct Unk021D82D0;
struct UtilSlots;
struct Q;
struct QL;
struct QI;
struct S_p12;
struct Q_021C0CB4;
struct Q_021C0CE8;
struct QK;
struct Unk021B8CB0 { u32 f0; u32 mode; };

typedef struct { u8 pad[0xC1]; unsigned char flag:1; unsigned char rest:7; } Flags_021B9184;

typedef struct {
    u8 pad[0x473];
    u8 a : 1;
    u8 b : 1;
    u8 c : 1;
    u8 d : 1;
    u8 e : 1;
    u8 f : 1;
    u8 g : 1;
} B_td;

typedef struct { u8 lo:6; u8 flag:1; u8 hi:1; } Flags_021B9210;

typedef unsigned long long u64;

struct Unk021EFD70 { u16 n0; volatile u16 n1; u8 b[6]; };

/* 021B9B54  ldrb r3,[r0,#0x18]; adds r2,r3,#1; strb r2,[r0,#0x18];
 *           lsls r2,r3,#2; str r1,[r0,r2] */
struct Q1 { u32 items[6]; u8 count; };

/* 021B9BF0  ldrb r2,[r0,#0x18]; cmp r1,r2; bhs; lsls r1,#2; ldr r0,[r0,r1] */
struct S2 { u8 *items[6]; u8 count; };

struct Arr { void *e[6]; u8 n; };

struct H {
    u16 a, b, c, d;
};

struct A {
    int vt;
    int q;
    u16 h8;
    u16 ha;
    int c;
    u16 h[4];
    struct H s18;
    struct H s20;
};

struct B_021B9A00 {
    int f0;
    int f4;
    int f8;
    char b[8];
    int f14;
    struct H s18;
    struct H s20;
};

struct B_021B9EF0 {
    int f0;
    int f4;
    int f8;
    char b[8];
    int f14;
    struct H s18;
    struct H s20;
    char pad[0x68 - 0x28];
    int f68;
};

/* 021BA08C  movs r1,#0xaf; lsls r1,#2; ldr r0,[r0,r1] */
struct Q2 { u8 pad[0x2bc]; u32 v; };

struct S_021B8CB0 { char pad[0x298]; void *a[4]; void *b[4]; void *c; };

struct F {
    u8 b : 1;
};

/* 021BA5D0  movs r1,#0x11; lsls r1,#6; ldrh r0,[r0,r1] */
struct Q3 { u8 pad[0x440]; u16 v; };

struct T {
    int w[6];
};

typedef struct { unsigned int a, b; } Pair_td;

typedef struct {
    u32 pad : 7;
    u32 f : 3;
} B_021B9EF0_td;

typedef struct {
    u8 pad0[0x68];
    u8 rd[0x4c];      /* 0x68 */
    u32 tab[4][3];    /* 0xb4 */
    u8 cnt[4];        /* 0xe4 */
} Obj_td;

typedef struct { u32 h; u32 x[2]; } EntP;

typedef struct { u32 w; } W;

typedef struct { W v[3]; } D;

typedef struct {
    u8 pad0[0x14];
    EntP e[4];
    u8 pad1[0x70];
    D d[4];
    u8 c[4];
} P;

/* 021BB840  strb r1,[r0,#0xb]; str r2,[r0]; strb r3,[r0,#0xa] */
struct Q4 { u32 w; u8 pad[6]; u8 c; u8 b; };

/* 021BB964  ldr r0,[r0,#0x44] */
struct Q5 { u8 pad[0x44]; u32 v; };

typedef struct { u8 a:1; u8 b:1; u8 c:1; u8 pad:3; u8 d:1; u8 rest:1; } Flags_td;

typedef struct { u32 a; u32 kind : 4; u32 x : 3; u32 y : 3; u32 z : 1; u32 pad : 21; u32 c; u8 d, f; unsigned short pad2; } E_021BBCD4;

typedef struct {
    u8 *f0; void *f4; u8 pad8[4]; int *fC; u8 pad10[4]; u32 f14;
    u8 pad18[0x3e0 - 0x18]; u8 g3e0[0xee]; u8 g4ce[0x77c - 0x4ce];
    u8 init; u8 pad77d[5]; u8 n; u8 k; u8 pad784[0x5c]; E_021BBCD4 e[6];
} S_021B8CB0_td;

typedef struct { u32 a:4; u32 b:3; u32 action:16; u32 rest:9; } EntBits;

typedef struct { u8 *a; EntBits b; u32 c; u8 d, f; unsigned short pad; } E;

typedef struct { u8 pad[0x14]; u32 state; u8 pad2[0x76a]; u8 n; u8 pad3[0x5d]; E e[6]; } S_021BBFA8;

typedef struct { u8 *a; EntBits b; u32 c; u8 d,f; u16 pad; } E2;

/* Same layout as Entry. Reading e[l].b through this second type keeps mwcc from reusing r->b; the bytes need that reload. */
typedef struct { u8 *a; Action b; u32 c; u8 d; u8 done; u8 f; u8 pad; } EntryAlt;

typedef struct { u32 x; void *m; } Q_td;

struct Unk021BD200 {
    u16 f0;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
};

struct Cursor { u8 a, b, c, d; };

enum Offset { queue = 0x1a68 };

struct Fl { u8 f : 1; };

struct Out_021BDB88 { u8 c0; u8 pad; u16 c2; u8 c4; };

struct Cell { u32 w[5]; };

struct Out_021BE3A8 { u8 pad[16]; u32 flag : 1; u32 rest : 31; };

struct Unk021BE518 { u8 f0; u8 f1[6]; };

struct Lock_021BDB88 { u32 a:10; u32 b:9; u32 c:9; u32 d:1; u32 e:1; u32 f:1; u32 g:1; };

struct State { u16 f0; u8 f2, f3, f4; u8 a:1, b:1, rest:6; };

struct Bits78A { u8 low:4, skip:1, rest:3; };

struct Buf { u32 wpos, rpos; };

struct S { u32 id[6]; u16 a[6], b[6]; u8 c[6]; u16 d[6]; u8 n, max, f44, f45; };

struct Rec { u32 value; u16 kind; u8 data, flag; };

struct O { u32 pos; struct Rec r[120]; };

struct O_p11 { u16 h; u8 b; };

struct Lock_021BF244 { u32 a:10, b:9, c:9, d:1, e:1, f:1, g:1; };

struct Bf { u8 pad[0x10]; u32 f : 1; };

struct Entry { u16 value; u16 id:5; u16 mode:4; u16 type:4; u16 marked:1; u16 special:1; u16 error:1; };

struct List_021BDB88 { u8 good, bad, count, pad; struct Entry entries[1]; };

struct Ent_021C0CB4 {
    u16 v;
    u16 lo:5;
    u16 b:4;
    u16 c:4;
    u16 d:1;
    u16 e:1;
    u16 f:1;
};

struct Q_021C0CB4 { u8 pad0[2]; u8 n; u8 pad3; struct Ent_021C0CB4 e[]; };

struct Ent_021C0CE8 {
    u16 v;
    u16 lo : 5;
    u16 b : 4;
    u16 c : 4;
    u16 d : 1;
    u16 e : 1;
    u16 f : 1;
};

struct Q_021C0CE8 { u8 pad0[2]; u8 n; u8 pad3; struct Ent_021C0CE8 e[1]; };

struct Entry_p08 { u16 value; u16 id:5, mode:4, type:4, marked:1, special:1, error:1; };

struct List_021C0F24 { u8 good, bad, count, pad; struct Entry_p08 entries[1]; };

struct St { u8 pad[5]; u8 f : 1; };

struct Rec_p09 { u16 a; u16 b; u8 c; u8 d; u8 e; };

typedef struct { u32 a:10,b:9,c:9,d:1,e:1,f:1,g:1; } Lock_td;

typedef struct { u8 pad[5]; u8 f:1; } BF_021C1184;

typedef struct { u8 pad[0x78a]; u8 low:4; u8 f:1; } State_td;

typedef struct { u8 pad[5]; u8 f : 1; } BF_021C2AB0;

extern u8 func_021B8778(struct Unk021B8CB0 **p, int k, u8 *out);
extern int func_021D5B68(void *m);
extern u8 func_021D5440(u8 *p);
extern u8 func_021B8BEC(u8 *p, u32 k, u8 n);
extern int func_021B86C8(unsigned char **p);
extern void *func_021B86B8(void ***p);
extern int func_021B8B9C(u8 *p, u8 k);
extern int func_02007F1C(void *,u32,int,u16);
extern int func_02007E50(void *,u32,int,u16);
extern u32 func_0201119C(u32 v);
extern void *func_02012F08(int *p);
extern u32 func_0200C274(struct Blk34 *p);
extern u32 func_021D7FF8(u32 a, void *b);
extern void *func_021D5844(void *m);
extern char *func_021B8714(char **p);
extern void func_0201B7A0(void *a0, int a1, int a2, int a3);
extern void func_021D54F4(struct Work *, struct Work *);
extern int func_021D6C24(struct R4 *p);
extern void *func_021D5864(struct Work *p);
extern void func_021D53B8(void *);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern struct S_021B8CB0 *func_021D4D84(void *a, u8 b, u32 c);
extern int func_021D59B4(u8 *p, int k);
extern void func_021D5848(struct QH *p, void *v);
extern u16 func_021D5444(struct QF *p);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void *func_020173F0(u16 species, u16 level, u64 id, u16 heap);
extern void func_0201A948(struct Party *p);
extern void func_021D6B84(void *, int);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern void func_021D6C3C(void **p, void *q);
extern int func_021D67D0(struct R3 *p);
extern void *func_02007B50(void **p);
extern u32 func_02007C70(struct PerapVoice *p);
int func_021B6994(struct S_021B8CB0 **pp, u32 b);
extern u32 func_021B8588(void **p);
extern u8 func_021B8C20(int, u32, u32);
extern void func_021CD9F4(void *,int);
extern int func_021D5B7C(void *);
extern unsigned int func_021B8B78(unsigned char *p, int k);
extern void func_021D5854(struct Work *p);
extern u32 func_020307B0(void *p);
extern void *func_0200846C(int a);
extern void func_02008494(void *src, void *dst);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_02008510(void *a, int tag);
extern void func_0202428C(void *a);
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
extern void func_02082D44(void *, void *, int);
extern void func_02024570(struct Rec8 *dst, const struct Rec8 *src);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045A00(struct Buf *buf, const void *src, u32 n);
char *func_0202E7DC(char *p);
extern struct Party *func_0201A920(u32);
int func_02013158(char *base, int m);
extern u32 sub_02008DF0(struct Sub02008C20Obj *, int);
extern u32 sub_02008DAC(struct Sub02008C20Obj *, int, u32);
extern unsigned int func_021B6818(unsigned int *p);
extern void func_0201B7B4(void *, int, u16, u16);
extern int func_021D7F60(u32);
extern void func_0201B818(void *a0, int a1, int a2);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_021D805C(void *p, u32 n);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern u32 _u32_div_f(u32, u32);
extern u32 func_021D826C(u32 *p);
extern int func_021D8270(void *, int, unsigned int);
extern int func_021CDDA0(u8 *p);
extern u32 func_021CDDCC(struct Flags *p);
extern u16 *func_021CD924(u8 *p, u32 *out);
extern void func_021D787C(void *);
extern void func_021B68D8(u8 *s, struct T *t);
extern void func_021CD984(void *, int);
extern void func_021E9034(char *p);
extern void func_021E8E28(void *p);
extern struct Scene *func_021E8F20(void *a, void *b, u32 c, int d, u16 heap);
extern void func_021CD95C(struct QA *p, u32 v);
extern void func_021CD9B0(u8 *p);
extern u16 func_021C8138(struct Q7 *p);
extern unsigned char func_021C8140(char *p, int i);
extern u16 func_021C7CBC(u8 *p);
extern u16 func_021C7CC8(u8 *p);
extern u16 func_021C7CD4(struct Q6 *p);
extern u16 func_021C7CDC(u8 *p);
extern u16 func_021C7CE8(u8 *p);
extern u8 func_021D54B4(u8 *p);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, u16);
int func_021EEA58(int, int, int, int);
extern void func_02045808(struct U16Vec *vec);
extern void func_021EEAE0(void *p);
extern u8 func_021B86C0(u8 **p);
extern int func_021C84D8(u8 *p);
extern u32 func_021EEB64(struct QW *p, u32 *out);
extern int func_021B85A8(u8 *);
extern u32 func_021D8454(Action *);
extern u8 *func_021EE9A4(u8 *p, unsigned int *out);
extern u16 func_021B86DC(void **);
extern void func_02005D90(u32, u32);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_021EE9B4(u8 *, void *, u8);
extern int func_021EE9E4(u8 *p, u32 *pos, u8 *a, u8 *b, u32 *dst);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void func_021EE8B4(u8 *, int);
extern u8 *func_021EE8D8(u8 *p, u32 *out, int flag);
extern void func_021EE8F4(u8 *p, u8 idx, const void *src, u32 n);
extern u32 func_021EE96C(u8 *p, int a, int b);
extern void func_021EEAE8(void);
extern void func_021EEB00(u32, int, int, int);
extern void func_021EEAFC(void);
extern void func_021EEB70(u32);
extern int func_021EEB2C(u32);
extern void func_021EEAD0(u8 *p);
extern void func_02027268(u32);
extern void func_020271DC(u16);
extern void *func_0201B70C(u16 heap);
extern void func_021D6EAC(void);
extern int func_021EF874(int a);
extern void func_021BBB08(void *);
extern void func_021BBB18(void *);
extern void func_021BBB28(void *, void *, void *, u32);
extern void func_02082BCC(void *, int, u32);
extern void func_021C7C18(void *);
extern void func_021C8588(Server *p);
extern void func_021D8230(u8 *p);
extern void func_021CC8C8(u32 *p);
extern void *func_021C5474(char *p);
extern void func_021BBB38(void *);
extern void func_02049238(u32);
extern int func_021C3B68(Server *, int, u8);
extern void func_021B8750(char *p, unsigned char k, void *m);
extern void func_021C84E8(Server *p);
extern void func_021BBCC4(u8 *p);
extern void func_021D6EE8(void);
extern void func_021D74E4(void);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void func_021C6110(Server *p, u8 *a, u32 n);
extern int func_021BBF88(u8 *, int);
extern int func_021BBF98(u8 *, int);
extern int func_021C5200(Server *p);
extern void func_021C4614(Server *p);
extern void func_021C6158(Server *p, u8 *a);
extern int func_021C446C(Server *p);
extern int func_021BC0D8(void *, int);
extern int func_021C8534(Server *p);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern u8 func_021C6350(Server *, u8 *);
extern unsigned char func_021B8BC4(int unused, unsigned int b);
extern int func_021BC408(u8 *p, u8 i, u32 *out);
extern void func_021CD4B0(void *w, u32 id, ...);
extern void func_021C5108(Server *p, u8 *a, int b);
extern int func_021EF948(int k);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021C5620(Server *p, u8 *a, int k, union Slot *out);
extern void func_021D8548(void *p);
extern void func_021DCFB4(void *p);
extern void func_021BC4CC(u8 *p, int a, int b, u8 *c, u8 *d);
extern u8 func_021BC540(u8 *p, u8 i, u8 *buf);
extern int func_021E02DC(u8 *a, u16 key, u32 sub_pri);
extern void func_021C6394(Server *p, u8 *a, unsigned int n);
extern void func_021E0394(u8 *a, int b);
extern int func_021D83E0(Action *p);
extern u32 func_021D78AC(u32 range);
extern u32 func_0201BD28(u32 v, u32 n);
extern void func_021D74F8(int line);
extern void func_021D75EC(int key, u32 val);
extern void func_021D75A8(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern void func_021D7674(int key, u32 a, u32 b, u32 c);
extern u32 func_021D7B10(u32 a, u32 b);
extern u32 func_021D8340(Action *m);
extern void func_021C859C(Server *);
extern int func_021BCEEC(void *, u8);
extern int func_021B86E4(unsigned int **p);
extern u8 func_021D69AC(u8 *, int);
extern void func_021D5FC0(struct UtilWork *p, u32 n);
extern int func_021CB730(Server *, u8 *, u16, u8, u8);
extern void func_021C54BC(Server *, u8 *);
extern void func_021C60EC(Server *p, u8 *a, u32 n);
extern void func_021C85B8(Server *);
extern int func_021B871C(char *);
extern int func_02018480(void *, int);
extern u8 func_021B85A0(u8 **p);
extern void func_021D7630(int key, u32 val);
extern int func_021BD138(u8 *p, u32 k);
extern void func_021D82FC(Action *p, int sub);
extern int func_021BD264(int t);
extern u8 func_021BD274(u8 *p, u8 x);
extern int func_021BD284(int t);
extern u8 *func_021BD294(int t, int k);
extern u8 func_021BD2A4(u8 *p, u8 x);
extern void func_021C5D88(Server *p, u8 *a, int b);
extern void func_021BD4D4(u8 *p, int a, int b);
extern void func_021CD64C(void *w, u8 id, ...);
extern int func_021D58A8(u8 *p, int k);
extern void func_021D8244(struct B *p, int n);
extern void func_021BD89C(Server *p, u8 *a);
extern void *func_021D8484(void *a);
extern void *func_021DCF5C(void *p);
extern void func_021D63EC(u8 *p, u16 n);
extern void func_021D6580(void *);
extern void func_021BD9C4(void *, int, u8, void *);
extern void func_021BDB28(void *);
extern void func_021BDB38(void *, u8 *);
extern void func_021BDB48(void *, Server *);
extern int func_021C88E4(Server *);
extern void func_021BDB58(void *);
extern u8 *func_021BDB68(void *);
extern u8 *func_021BDB78(void *);
extern void func_021D70FC(int a, int b, int c);
extern int func_021C6190(Server *p, u8 *a);
extern void func_021D64F0(u8 *a);
extern void func_021BDE08(u8 *p, u32 n);
extern union Slot func_021D6314(void *p, int i);
extern u16 func_021E8B80(union Slot v);
extern int func_021D55A0(struct UtilWork *p, int id);
extern u32 func_021D5C08(struct UtilWork *p);
extern u8 func_021D80BC(void *p, int a, int m, u16 move);
extern void func_021D82D0(struct Unk021D82D0 *out, u32 id, u32 sub);
extern u8 func_021D5778(struct UtilWork *p, u16 id);
extern int func_021C62D8(Server *p, u8 *a, u32 unused, u32 c, struct O_p11 *out);
extern void func_021C5604(Server *, u8 *, int);
extern void func_021C64B4(Server *p, u16 q, u8 *a, struct Out64B4 *out);
extern int func_021CA7F4(Server *, u8 *, u8, const u8 *, void *);
extern void func_021BE338(void *);
extern void func_021BE348(void *);
extern u32 func_021BE358(void *);
extern void func_021BE368(void *);
extern void func_021BE378(void *, void *);
extern void func_021BE388(void *, u32);
extern void func_021BE398(void *, u16, u32, u32);
extern int func_021C6458(Server *, u8 *, u32, u32, u8 *);
extern int func_021C99A0(Server *w, const struct Msg *m);
extern void func_021C8810(u8 *);
extern void func_021D6744(u8 *, u8, int, u8, u16, u16);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern int func_0201BEB8(void *bag, int item);
extern void func_021D7394(int kind);
extern void func_021E03D8(u8 *a, int b);
extern void func_021D73D4(int kind);
extern u32 func_021D6E74(u8 *p);
extern void func_021D6E40(u8 *, u8, u16);
extern void func_021C5718(Server *p, u8 *a, u32 b);
extern u8 func_021BEB04(u8 *p, int selector);
extern u32 func_021BEBB8(int d);
extern u8 *func_021BEBC8(int d, u32 i);
extern u32 func_0201C1BC(u16);
extern void func_021BEFEC(void *);
extern void func_021BEFFC(struct S *);
extern int func_021BF00C(struct S *);
extern int func_021BF01C(struct S *);
extern int func_021BF02C(struct S *);
extern void func_021BF03C(struct O *);
extern u16 func_021CD4FC(u8 *, u32);
extern int func_021C65A8(Server *, u8 *, u32, u8 *);
extern void func_021CC8A0(u32 *p);
extern void func_021C3184(Server *, const u16 *, u32, u32);
extern void func_021C3438(Server *, u16 *, u8 *, u8 *);
extern void func_021C376C(Server *, u16, int, int);
extern void func_021C3274(Server *, u32, u32, u32);
extern void func_021C3AA8(Server *, u16 *, u8 *);
extern void func_021C3D08(Server *, u16 *, u8 *, u8 *);
extern int func_021C4F64(Server *, u8 *);
extern void func_021BF0A4(int c);
extern int func_021BF0B4(int c);
extern void func_021BF0C4(int c, int x);
extern int func_021BF0D4(int c);
extern void func_021C572C(Server *p, u8 *a, u32 v);
extern int func_021BF138(int c);
extern u8 *func_021BF148(int c, int k);
extern void func_021BF158(int c, u8 *x);
extern void func_021BF204(int c);
extern int func_021BF214(int c);
extern void func_021BF224(int c, int x);
extern int func_021BF234(int c);
extern u32 func_021D6D7C(u8 *p);
extern int func_021BF3B8(u8 *q, int k, u32 n);
extern int func_021BF3C8(u8 *q, int k, u32 n);
extern u16 func_021D62D8(struct UtilSlots *p, int i);
extern void func_021CC8B0(u32 *p, u32 i, u32 b);
extern void func_021BF46C(int d);
extern u8 *func_021BF47C(int d);
extern void func_021BF48C(int d, u8 *x);
extern u8 *func_021BF49C(int d);
extern int func_021C6E3C(Server *p, u8 *a, u8 *b, u8 *q, int flag);
extern void func_021C7C24(u16 *p, int unused, u8 *b, u8 *c, int e);
extern void func_021BF5E8(void *);
extern u8 *func_021BF5F8(void *);
extern void func_021BF608(void *, u8 *);
extern u8 *func_021BF618(void *);
extern void func_021BF628(void *);
extern u8 *func_021BF638(void *);
extern void func_021BF648(void *, u8 *);
extern u8 *func_021BF658(void *);
extern void func_021BF668(void *);
extern u8 *func_021BF678(void *);
extern void func_021BF688(void *, u8 *);
extern u8 *func_021BF698(void *);
extern void func_021BF6A8(void *);
extern u8 *func_021BF6B8(void *);
extern void func_021BF6C8(void *, u8 *);
extern u8 *func_021BF6D8(void *);
extern int func_021C6668(Server *, u8 *, u8 *, u16);
extern u32 func_021C8828(u8 *p);
extern u32 func_021CC8C0(u32 *p, u32 i);
extern void func_021BF894(int d);
extern u8 *func_021BF8A4(int d);
extern void func_021BF8B4(int d, u8 *x);
extern u8 *func_021BF8C4(int d);
extern int func_021C6948(Server *p, u8 *a, u8 *b, u32 v);
extern int func_021BF944(int d);
extern u8 *func_021BF954(int d, int k);
extern void func_021BF964(int d);
extern u8 *func_021BF974(int d);
extern void func_021BF984(int d, u8 *x);
extern u8 *func_021BF994(int d);
extern int func_021C69B8(Server *, u8 *, u32, u16);
extern int func_021C6A04(Server *, u8 *, u8 *, struct Q *);
extern void func_021D7704(int, int);
extern unsigned char func_021D7908(int a, int i);
extern void func_021CD568(void *, u16, u32, ...);
extern int func_021C66AC(Server *, u8 *, u32);
extern int func_021C6720(Server *, u8 *, u32);
extern union Slot func_021E896C(int, int);
extern void func_021C5C1C(Server *, u8 *, int, union Slot);
extern void func_021C6878(Server *p, u8 *a, int a2);
extern int func_021C68A8(Server *, u8 *, u8 *, u16);
extern int func_021C676C(Server *, u8 *, u8 *, u16, u8 *, u32 *);
extern int func_021BFE30(u8 *);
extern u8 *func_021BFE40(u8 *, int);
extern u8 func_021BFE50(void *, u8);
extern void func_021C6848(Server *, u8 *);
extern int func_021D5C30(struct UtilWork *p);
extern union Slot func_021E899C(u32 a);
extern int func_021C000C(u8 *p, int k);
extern u32 func_021D5584(struct UtilWork *p, u32 i);
extern u16 func_021D67B8(u8 *);
extern u16 func_021D67A8(struct QL *p);
extern u32 func_0201C314(void *p);
extern int func_021EF91C(void *, u8 *, u16);
extern int func_021D7AF0(u32);
extern void func_021C5480(Server *, u8 *, int);
extern void func_021C557C(Server *, u8 *, int, int);
extern int func_021D61A8(struct UtilSlots *p);
extern void func_021C54C8(Server *p, u8 *a);
extern void func_021C54FC(Server *p, u8 *a);
extern int func_021D6130(struct UtilSlots *p);
extern u32 func_021C63D0(Server *, u8 *);
extern union Slot func_021D7D18(int);
extern void func_021C6564(Server *, u8 *, u32, u32);
extern void func_021D69A0(u8 *base, int idx, u8 val);
extern u32 func_021C0868(int e);
extern u8 *func_021C0878(int e, int i);
extern u8 *func_021C0888(int e, int i);
extern void func_021D5608(struct UtilWork *p, int i, u8 n);
extern void func_021D56CC(struct Work *p, int i);
extern void func_021C0A1C(u8 *);
extern int func_021C71E0(Server *, u8 *, u32, u8 *);
extern int func_021C0A2C(u8 *);
extern int func_021C0A3C(u8 *);
extern void func_021C0C04(u8 *);
extern u8 *func_021C0C14(u8 *);
extern u8 *func_021C0C24(u8 *);
extern int func_021C6BF8(Server *p, u8 *a, u8 *b, u16 q);
extern u32 func_021CC8B8(u32 *p, u32 i);
extern u32 func_021C0EC4(u8 *);
extern u32 func_021C0ED4(u8 *);
extern void func_021C0EE4(u8 *, u8 *, u8 *);
extern void func_021C0EF4(u8 *, u8 *, u8 *);
extern u32 func_021C0F04(u8 *);
extern u32 func_021C0F14(u8 *);
extern u32 func_021C1144(void *, u32);
extern u8 func_021C1154(u8 *, u8);
extern u8 func_021C1164(u8 *, u8);
extern u8 func_021C1174(u8 *, u8);
extern unsigned int func_021B8590(unsigned char *p);
extern u8 func_021C14B0(void *p, int n);
extern void func_021C14C0(void *w, u8 *c, int h, int f);
extern void func_021C14D0(void *w, u8 *c, int d, int f);
extern u16 func_021C4104(Server *p, u8 *q, u8 *c, u16 d, int sa, u8 sb, u16 *e);
extern void func_021C4218(Server *p, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3);
extern void func_021C5798(Server *p, u16 *a, u32 n, int *arr, u8 **ptrs, u16 *vals, u8 *unused1, int unused2);
extern void func_021C5840(Server *p, u32 count, int *v, u8 **a, int flag);
extern void func_021C59C4(Server *p, u32 n, u8 **a, u8 *b, int flag);
extern void func_021C156C(u8 *c);
extern u8 *func_021C157C(u8 *c);
extern int func_021C6B5C(Server *p, u8 *a, u8 *b, u8 *q);
extern void func_021C6BB8(Server *p, u8 *a, u8 *r);
extern void func_021C158C(u8 *c, u8 *r);
extern u8 *func_021C159C(u8 *c);
extern void func_021D6848(u8 *c, struct Rec_p09 *r);
extern u32 sub_0201C1BC(u16 move);
extern u16 func_021D5B40(struct QI *p);
extern void func_021C1B2C(u8 *);
extern u8 *func_021C1B3C(u8 *);
extern u8 *func_021C1B4C(u8 *);
extern u32 func_021C1C48(u8 *);
extern u8 *func_021C1C58(u8 *, u32);
extern int func_021C1C68(u8 *, u8 *, u32 *);
extern int func_021C1C78(u8 *, u8 *, u32 *);
extern int func_021C7664(Server *, u32, u8 *);
extern void func_021C1D30(u8 *w);
extern u8 *func_021C1D40(u8 *w);
extern u8 *func_021C1D50(u8 *w);
extern int func_021C76F4(Server *p, u8 *q, u32 n);
extern void func_021C7780(Server *p, u8 *q);
extern u32 sub_0201BD28(u16 id, u32 field);
extern u32 func_021D7B3C(u32 a, u32 b);
extern u16 func_021C78F4(Server *p, u8 *a, u8 *b, u32 s);
extern int func_021C3370(Server *p, void *q);
extern int func_021C334C(Server *p, u8 *q, int a, int b);
extern int func_0201C1E8(int a);
extern u16 func_021C728C(Server *, u8 *, u8 *, const u8 *);
extern u16 func_021C7374(Server *p, u8 *a, u8 *b, const u8 *c, int flag);
extern u16 func_021C7474(Server *p, u8 *a, u8 *b, const u8 *c, u32 flag);
extern u32 func_021D7A44(u32 a, u32 b, u32 c, u32 d);
extern u32 func_021D7C38(int a, int b);
extern int func_021C75EC(Server *, u8 *, int);
extern u32 func_021D7A6C(u32, u32);
extern int func_021C6CAC(Server *p, u8 *a, u16 b, u32 c, int *out);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S_p12 *l, u32 v);
extern int func_021C7330(Server *, u8 *);
extern void func_021C5B74(Server *p, u8 *a, int c, int k);
extern int func_021C21F4(void *, u32);
extern u32 func_021CC918(void *, u16, int);
extern void func_021C6DD0(Server *, u8 *);
extern void func_021D5B44(struct QI *p, u16 v);
extern void func_021C7AD0(Server *p, u8 *a, u32 b);
extern void func_021C7B0C(Server *p, u8 *a);
extern void func_021C6134(Server *p, u8 *a, unsigned int n);
extern void func_021DCF24(u8 *a);
extern void func_021D6730(struct QK *p, u16 v);
extern void func_021C5BE4(Server *, u8 *, int);
extern W_021C312C sub_0201BF58(u16);
extern void func_021D7C70(W_021C312C, u32, union Slot *);
extern u32 func_021C2564(u32);
extern void func_021C2574(u32);
extern u8 *func_021C2584(u32);
extern u8 *func_021C2594(u32);
extern void func_021C5C74(Server *p, u8 *a, int kind, u32 v);
extern u16 func_021D57FC(void *);
extern int func_021E8D24(int x, int k);
extern void func_021C2AA0(int, union Slot, u8 *, struct Msg *);
extern void func_021D8510(void *p);
extern void func_021D66D8(void *, u8);
extern int func_021D7D6C(int);
extern void func_021C3FDC(Server *, u8 *);
extern int func_021EF884(void);
extern void func_021D70E4(void *a, int id);
extern int func_021C2E64(Server *, const u16 *, u8 *, u8 *, int);
extern void func_021C2E1C(u32 c);
extern u32 func_021C2E2C(u32 c);
extern u32 func_021C2E3C(u32 c);
u8 func_021B8CB0(struct Unk021B8CB0 **p, u8 x);
int func_021B8CE8(int a, int b, int c);
unsigned char func_021B8CFC(char *p, int i);
u8 func_021B8D08(u32 x);
u8 func_021B8D38(void *p, int a, int k, u8 *out);
u8 func_021B8D8C(void *p, void *a, u32 b);
unsigned char func_021B8DC0(unsigned char *p,void *a,unsigned int b);
u8 func_021B8DDC(u32 x);
u8 func_021B8DE4(char *p, int i);
unsigned char func_021B8DEC(char *p,unsigned char k);
void func_021B8E28(u8 *p, u8 n, u8 *out, u8 *cnt_out);
u8 func_021B8E70(u8 *p, u32 k);
u8 func_021B8ED8(u8 *p, u8 k);
int func_021B8F38(unsigned char *p);
int func_021B8F5C(char *p,int k);
int func_021B8F7C(u8 *p, u32 k);
unsigned char func_021B8FC0(unsigned char *p,unsigned int k);
u8 func_021B8FE4(u8 *p);
u8 func_021B8FF4(u8 *p);
u8 func_021B9000(u8 *p);
u8 func_021B9010(u8 *p, u8 k);
int func_021B902C(int a, int b);
u8 func_021B904C(u8 *p,int k);
u32 func_021B9064(u8 *p, int k, int x);
void func_021B9090(u8 *p, u32 k, u32 x);
void func_021B90BC(u8 *p,u8 k,u32 x);
u32 func_021B90E8(void **p);
u32 func_021B90F0(void **p);
int func_021B90F8(u8 *p);
u8 func_021B9114(u8 **p);
int func_021B911C(void *p, int k);
void func_021B9120(u8 *p, u8 n);
void func_021B916C(u8 *p,u32 x);
int func_021B917C(char *p);
void func_021B9184(Flags_021B9184 **p);
u32 func_021B919C(u8 *p);
void func_021B91E4(void *p, int add);
u32 func_021B9210(u8 *p);
void func_021B9234(unsigned char *p);
u32 func_021B9244(char *p);
void func_021B92A0(u8 *p);
void func_021B92B0(char *p,void *m,int k);
void func_021B92D4(char *p, void *m, int c);
void func_021B9358(char *p, int i);
u8 *func_021B937C(void *a, char *b, u8 *c);
void func_021B93E0(char *p, u32 a, u32 b);
void func_021B9424(char *p);
void func_021B9460(char *a, char *b, u8 c);
int func_021B9634(void *a);
void func_021B9674(char *p);
void func_021B969C(char *a, char *b, int k, int flag);
void func_021B97A0(char *a, char *b, int k);
int func_021B985C(char *p, int i);
int func_021B9864(int a, int b, int c);
u8 *func_021B98A4(char *const *q, u8 b);
u8 *func_021B98AC(char *const *q, u8 b);
void *func_021B990C(char *p, unsigned int i, unsigned int j);
u8 *func_021B9920(void *p, u32 i, u8 j);
u8 *func_021B9934(char *p, int i);
u8 *func_021B9940(char *p, u8 i);
int func_021B994C(u8 *p, u32 i, void **out);
int func_021B997C(u8 *p, unsigned int i);
int func_021B99B8(void *pp, unsigned int b);
int func_021B99C0(struct S_021B8CB0 **p, u32 b);
struct Unk021EFD70 *func_021B99E0(int i);
u32 func_021B99F0(u32 x);
int func_021B9A00(u32 x, u8 *out);
int func_021B9A24(unsigned int a, unsigned int b);
unsigned char func_021B9A40(unsigned int x);
unsigned char func_021B9A50(unsigned int x);
u8 func_021B9A5C(u32 x);
int func_021B9A6C(int a, u32 b);
u8 func_021B9AB0(u8 x);
int func_021B9AC8(int a);
unsigned char func_021B9AE0(unsigned int x);
char *func_021B9AEC(char *p, int i);
char *func_021B9AF8(char *p, int i);
unsigned char func_021B9B04(int a, int b);
void func_021B9B10(u8 *p,u8 i,int v);
void func_021B9B40(u8 *p);
void func_021B9B54(struct Q1 *p, u32 v);
void func_021B9B60(u8 *p);
u8 func_021B9B94(struct Q1 *p);
u8 func_021B9B98(u8 *p);
u8 func_021B9BC4(u8 *p,int i);
u32 func_021B9BF0(struct S2 *p, u32 i);
u8 *func_021B9C00(struct S2 *p, u32 i);
void func_021B9C10(u32 *p, int a, int b);
void func_021B9C24(u8 *p, u8 i);
void func_021B9C50(u8 **p, u8 k, u8 **o1, u8 **o2);
int func_021B9C98(u8 *p,u32 v);
int func_021B9CBC(u8 *p, int v);
void *func_021B9CE8(u8 *p);
void func_021B9D10(char *a, struct Arr *arr, int k);
void func_021B9DB8(char *p);
void func_021B9DE8(char *p);
void func_021B9E38(char *p, int a, int b);
void func_021B9E7C(struct A *p, struct B_021B9A00 *src);
void func_021B9EF0(struct A *p, const struct B_021B9EF0 *src);
int func_021B9F70(u8 *p, int i);
u16 func_021B9F84(char *p,int i,unsigned int j);
u32 func_021B9FAC(u8 *p, int i, u32 *out);
int func_021B9FBC(char *p, int i);
u16 func_021BA004(char *p, int i);
unsigned short func_021BA020(char *p, int i);
void *func_021BA02C(char *p, int i, int mode);
int func_021BA064(char *p, int i);
void func_021BA080(char **p);
u32 func_021BA08C(struct Q2 *p);
void func_021BA094(struct S_021B8CB0 *p);
void func_021BA0CC(struct S_021B8CB0 *p);
void func_021BA128(struct S_021B8CB0 *p, int i, void *x);
void *func_021BA178(void *p, int i, int mode);
int func_021BA1A8(char **p, int m);
void func_021BA1B4(char **p, int i);
void func_021BA1CC(char **p, int i, u32 delta);
char *func_021BA1E4(char **p);
BOOL func_021BA1EC(char **p);
int func_021BA20C(char **p);
void func_021BA238(char *p, void *m);
void func_021BA250(char *p, u8 *a, int b);
void func_021BA2D4(u32 p, u32 *q);
void func_021BA2E4(char *p);
int func_021BA534(void ***p);
int func_021BA54C(char *p);
u16 func_021BA5C4(u8 *p);
u16 func_021BA5D0(struct Q3 *p);
int func_021BA5D8(char *p);
int func_021BA618(char *p);
void func_021BA648(char *p, u8 k, void *dst);
void func_021BA670(char *p, u8 k, void *dst);
void func_021BA698(u8 *p, int k);
void func_021BA6C0(char *p);
u8 func_021BA710(int a, int b);
void func_021BA73C(char *p, int x);
void func_021BA7F8(char *p);
u32 func_021BA820(int *p);
void func_021BA82C(char *p);
void func_021BA878(u8 *p);
u8 *func_021BA9C8(void *a, struct Copy24 *b, void *c, int d, u16 heap);
void func_021BAA94(char *p, int b, u8 c, u8 d);
void func_021BAACC(char *p, int a, int b, int c, u8 d);
void func_021BAB10(char *p, u8 c, u8 d);
void func_021BAB40(char *p);
void func_021BAB5C(int a);
int func_021BAB9C(int a);
void func_021BABDC(char *p, Pair_td *out);
void func_021BABEC(int *p, void *f);
void func_021BABF4(void *p);
int func_021BAC04(char *p, int *st);
int func_021BACAC(u8 *p, int *s);
int func_021BAE5C(u8 *p);
int func_021BAE60(u8 *p, int *s);
int func_021BAEF8(u8 *p, int *s);
int func_021BB040(u8 *p);
u32 func_021BB0A0(u8 *p);
int func_021BB0E0(u8 *p, int *s);
int func_021BB208(u8 *p, int *s);
int func_021BB280(u8 *p);
int func_021BB320(u8 *p, int *s);
int func_021BB368(u8 *p, int *s);
int func_021BB3B0(u8 *p, int *s);
int func_021BB3F8(u8 *p, int *s);
int func_021BB43C(u8 *p, int *s);
int func_021BB484(u8 *p, int *s);
void func_021BB4E0(Obj_td *p, void *src, u8 n);
void func_021BB56C(void *p);
int func_021BB570(u8 *p, int sel, void *data, u32 n);
int func_021BB5FC(u8 *p, int b);
int func_021BB628(u8 *p, int a, int b);
int func_021BB650(u8 *p, int a, int b, int c);
void func_021BB6A8(P *p);
void func_021BB718(int a, int b);
void func_021BB724(u8 *p, int a, int b, int c);
void func_021BB768(u8 *p, int a, u32 i, int b, int c);
int func_021BB798(u8 *p);
void func_021BB7D0(const u8 *p);
void func_021BB7FC(const u8 *p);
void func_021BB828(u8 *p);
int func_021BB830(u8 *p);
void func_021BB840(struct Q4 *p, int a, int b, int c);
void func_021BB848(u8 *p, void *q, u8 v);
u8 *func_021BB85C(u8 *p, unsigned int i);
u8 *func_021BB878(u8 *p, u32 i);
int func_021BB890(u8 *p, u8 i);
u8 func_021BB8A8(u8 *p, u8 i);
Action func_021BB8B0(u8 *p, u8 i, u8 j);
void func_021BB8BC(u8 *p, u32 *q);
void func_021BB8DC(u8 *p, u32 *q);
void func_021BB908(int *p, int add);
void func_021BB914(int *p);
void func_021BB920(u8 *p);
void func_021BB930(u8 *p, u32 value);
u32 func_021BB964(struct Q5 *p);
Server *func_021BB968(void *a, void *b, void *c, void *d, int e, u16 heap);
void func_021BB9D0(Server *p);
void func_021BB9D8(Server *p);
void func_021BBB48(u8 *p);
int func_021BBB60(Server *p);
void func_021BBC34(u8 *p);
int func_021BBC44(Server *p, int a);
void func_021BBCD4(Server *p);
void func_021BBD20(u8 *p);
int func_021BBD2C(Server *p, int a);
void func_021BBD80(u8 *p);
int func_021BBD8C(Server *p, int a);
u32 func_021BBFA8(Server *p, u32 i);
void func_021BC0E8(Server *p, Entry *e, u32 n);
int func_021BC220(Server *p, u8 *o);
int func_021BC2B0(Server *p);
int func_021BC310(Server *p);
int func_021BC360(Server *p);
int func_021BC390(Server *p);
void func_021BC3B0(Server *p);
void func_021BC418(Server *p, int a, u8 b);
int func_021BC4DC(Server *p, u8 *out);
u8 *func_021BC550(Server *p);
u8 func_021BC55C(Server *p);
void func_021BC568(Server *p);
u8 func_021BC610(Server *p, u8 *o, Entry *e, int unused);
void func_021BC874(Entry *p, u32 n);
int func_021BC8EC(Server *p, u32 x, u8 *a);
u16 func_021BC948(Server *p, u8 *x, int flag);
Entry *func_021BCA08(Server *p, u8 x);
Entry *func_021BCA50(Server *p, Entry *cur, u32 x);
Entry *func_021BCAAC(Server *p, u16 x, u32 i);
Entry *func_021BCB14(Server *p, u16 x, u8 y, u32 unused);
int func_021BCB68(Server *p, Entry *cur);
int func_021BCB98(Server *p, Entry *cur, int start);
void func_021BCC50(Server *p, Entry *cur);
u32 func_021BCCE0(Server *p, Entry *e);
void func_021BCEFC(Server *p, u8 *a, u32 k);
void func_021BCF34(Server *p, u8 *a, u32 k);
void func_021BCF70(Server *p, u8 *a, u32 k);
int func_021BCFAC(Server *p, u8 *a);
int func_021BD080(Server *p, u8 *a);
int func_021BD0C0(Server *p, u8 x, u32 y);
int func_021BD148(Server *p, u8 x);
int func_021BD170(Server *p, u16 x);
int func_021BD1B0(Server *p, u8 x);
void func_021BD1D0(Server *p, u8 n);
void func_021BD1E0(struct Unk021BD1E0 *p);
void func_021BD200(struct Unk021BD1E0 *p, Server *q, u8 *a, int t);
void func_021BD2B4(u8 *p, u8 **q);
void func_021BD338(u8 *p, Server *q);
int func_021BD34C(u8 *p, u8 **q, u8 **out);
void func_021BD3E8(Server *p, u8 *a);
void func_021BD43C(Server *p, int i, u8 a, u8 b, int c);
void func_021BD4E4(Server *p, int i, u8 a, u8 b);
void func_021BD518(Server *p, u8 *m);
void func_021BD554(Server *p, u8 *m);
int func_021BD584(Server *p, u8 *a);
int func_021BD60C(Server *p, u8 *a, u8 flag);
int func_021BD6B8(Server *p, u8 *a);
int func_021BD708(Server *p, u8 *a, int r, int z);
int func_021BD850(Server *p, u8 *a);
int func_021BD8AC(Server *p, u8 *a);
void func_021BD8F0(Server *p, u8 i, u8 a, u8 b);
void func_021BD9D4(Server *p, u8 i, u8 a, u8 b, int c);
int func_021BDA00(Server *p);
void func_021BDB88(Server *p, u8 *a);
void func_021BDBB8(Server *p, u8 *a);
void func_021BDBEC(Server *p);
void func_021BDC0C(Server *p);
void func_021BDC2C(Server *p);
void func_021BDC58(Server *p);
void func_021BDC78(Server *p, u8 *a);
void func_021BDC98(Server *p, u8 *a, u8 v);
int func_021BDD00(Server *p, u8 *a, int c);
void func_021BDD7C(Server *p, u8 *a, u32 c);
void func_021BDE18(Server *p, u8 *a);
u16 func_021BDE48(void *p, Action *m);
void func_021BDE98(Server *p, u8 *a, Action *act, u32 key);
int func_021BE3A8(Server *p, u8 *a, u16 *s);
void func_021BE400(Server *p, u16 key);
void func_021BE518(struct Unk021BE518 *p);
void func_021BE52C(u8 *p, int a, int b, int c);
void func_021BE550(Server *p, u8 *b, u16 c, void *unused);
void func_021BE620(Server *p, u8 *a, u8 *c);
void func_021BE66C(Server *p, u8 *a, u8 *c, int k);
void func_021BE6A8(Server *p, u8 *a, u8 *c, int k);
int func_021BE6EC(Server *p, u8 *a, u16 key, u32 x);
int func_021BE7E4(Server *p, u8 *a, u32 b, u32 c, u8 *q);
int func_021BE878(Server *p, u8 *a, u32 v);
void func_021BE8C4(Server *p, u8 *a);
void func_021BE8F4(Server *p,u8 *a);
void func_021BE924(Server *p, u8 *a, u32 v);
void func_021BE95C(Server *p, u8 *a, u32 v);
void func_021BE994(Server *p,u8 *a,u32 c,u32 d);
void func_021BE9D0(Server *p, u8 *a, u32 c, u32 d);
void func_021BEA14(Server *p, u8 *a, u8 *b, u32 c);
void func_021BEA60(Server *p, u8 *a, u8 *b, u32 c);
int func_021BEAB4(Server *p, u8 *a, int b, int c, u8 *q);
int func_021BEB14(int a, u8 *b, int c, int d, u8 *e, u8 *g);
void func_021BEBD8(Server *p,u8 *a,int c,int d);
int func_021BEC08(Server *p,u8 *a);
void func_021BEC2C(Server *p,u8 *a,int c);
int func_021BEC58(Server *p, u8 *a, u16 key, u8 *d);
void func_021BF04C(Server *p, u16 *b, int s, int c);
void func_021BF0E4(int u, u8 *b, int c, u8 *d, int e);
int func_021BF168(Server *p, u16 *a, u8 *b);
void func_021BF1B4(int u, u16 *b, int s, int c, int e);
void func_021BF244(Server *p, u32 a, u32 b);
void func_021BF27C(Server *p, u32 a, u32 b);
void func_021BF2B4(Server *p, u32 a, u32 b);
void func_021BF2EC(Server *p, u32 a, u32 b, int k);
int func_021BF324(Server *p, u8 *a, u8 *b);
void func_021BF3D8(Server *p, int b, u8 *a, int d, void *arr);
void func_021BF4AC(Server *p, u8 *b, u8 *a, void *d, void *e);
int func_021BF6E8(Server *p, u8 *b, u8 *c2, u8 *d, void *s0, int s1);
int func_021BF78C(Server *p, u8 *b, int c, u8 *d, u8 *e, void *f, void *g, int *h);
void func_021BF83C(Server *p, u16 *b, u8 *c, int d);
void func_021BF8D4(Server *p, u16 *b, u8 *c, int d);
int func_021BF9A4(Server *p, u8 *a, u8 *b, u16 *c);
int func_021BFA00(Server *p, u8 *a, u8 *b, void *item);
int func_021BFA60(Server *p, u8 *a, u8 *b, struct Q *q);
void func_021BFBD0(Server *p, u32 fallback, u8 *record, u32 pos);
int func_021BFC08(Server *p, u8 *q, u8 *d, u16 c);
int func_021BFD24(Server *p, u8 *q, u16 c, u8 *d, u16 e);
void func_021BFE60(Server *p, u8 *a);
int func_021BFEAC(Server *p, u8 *a, u8 *b, int *out);
void func_021BFF60(Server *p, u8 *a, int z);
int func_021C001C(Server *p, u8 *a, u16 c, u16 d);
int func_021C024C(Server *p, u8 *a, u16 c);
int func_021C0274(Server *p, u8 *a, u32 c, u32 d);
int func_021C02CC(Server *p, u8 *a, u32 c, int k);
int func_021C031C(Server *p, u8 *a);
int func_021C03AC(Server *p, u8 *a);
void func_021C03D8(Server *p, u8 *a, u16 a2);
int func_021C0404(Server *p, u8 *a, void *bag);
void func_021C0450(Server *p, u8 *q, u16 c, int k);
void func_021C0520(Server *p, u8 *a, u16 b, u32 c);
void func_021C0780(Server *p, u8 *a, int i, u8 v);
int func_021C07AC(Server *p, u8 *a, u16 c, u16 d, int e);
int func_021C07D4(Server *p, u8 *a, u16 c, u16 d, int e);
int func_021C0898(Server *p, u8 *a, u32 b, u8 c);
void func_021C08CC(Server *p, u8 *a, int b, u8 c);
void func_021C091C(Server *p, u8 *q, u8 *a, u8 *b, const u32 *c, u32 d);
void func_021C0A4C(Server *p, u8 *a, u8 *b, const u8 *q, const u32 *c, u32 k, struct List_021BDB88 *out);
u32 func_021C0C34(u8 *p);
int func_021C0C38(Server *p, const List_td *l, u32 *o0, u16 *o1, u32 *o2, u8 *o3);
int func_021C0CB4(Server *p, const struct Q_021C0CB4 *q, u32 *out);
int func_021C0CE8(Server *p, const struct Q_021C0CE8 *q, u32 *o1, u16 *o2, u32 *o3, u8 *o4, u8 *o5);
u32 func_021C0D70(const u8 *q);
u32 func_021C0D90(Server *p, u8 *q, u8 *a, u8 *b, const u32 *c, u32 *out, u32 d);
u32 func_021C0F24(Server *p, u8 *q, u8 *a, u8 *d, const u32 *c);
int func_021C1184(const u8 *p);
u8 func_021C1194(u8 *p);
void func_021C1198(unsigned char *p, int x);
u32 func_021C11A4(Server *p, u16 *a, u8 *b, u8 *c, u8 *d, u8 *e, u32 f, CallFlags g);
int func_021C11F0(Server *p, u8 *x, u8 *unused, u8 *y, u16 *e, u8 *st, u32 a6, CallFlags a7);
void func_021C14E0(Server *p, u8 *a, int b, u8 *c);
void func_021C15AC(Server *p, int k);
u32 func_021C15D4(void *p, u32 n);
void func_021C15E8(Server *p, u8 *a, u8 *b, u16 *c);
void func_021C1624(Server *p, u8 *a, u8 *b, u16 *c);
int func_021C1678(Server *p, u8 *a, u8 *b, u32 c, u16 *d);
void func_021C16F8(Server *p, u8 *a, int k);
void func_021C1758(Server *p, u8 *q, int k);
void func_021C1788(Server *p, u32 x, u8 *a, u32 n, u32 *arr);
void func_021C17CC(Server *p, u32 x, u8 *a, u32 n, u8 **arr);
void func_021C1828(Server *p, u8 b, u8 *x, u8 *c, u8 *q, u16 w);
void func_021C1880(Server *p, u8 *q, u8 *a, u8 *b, u32 s0, int s1);
void func_021C18D4(Server *p, u8 *a, u8 *q, u32 v);
void func_021C1910(Server *p, u8 *a, u8 *q, u32 v);
void func_021C195C(Server *p, u8 *q, u32 n);
void func_021C199C(Server *p, u8 *q, u32 n);
void func_021C19D8(Server *p, u8 *a, u8 *q);
void func_021C1A10(Server *p, u8 *a, u8 *q);
void func_021C1A54(Server *p, u8 *a, u8 *b, u8 *c, u32 unused, u32 d);
void func_021C1B5C(Server *p, u8 *a, u8 *b, u8 *c, u32 d, u8 e, int f);
void func_021C1C88(Server *p, u8 *a, u32 unused, u8 *q, u32 v);
int func_021C1CCC(Server *p, u16 *x, u8 *a, u8 *q);
void func_021C1CE4(Server *p, u8 *q, u32 unused, u8 *w);
int func_021C1D60(Server *p, u8 *q, u32 n);
void func_021C1DCC(Server *p, u8 *q, u32 a, u8 *b, u32 s);
int func_021C1E14(Server *p, u8 *q, u32 a, u32 b);
int func_021C1E74(Server *p, u8 *a, u8 *b, const u8 *c, u32 d, u32 e, u32 f, int g, u16 *out);
void func_021C2048(Server *p, u8 *a, u16 b, u32 c);
int func_021C20BC(Server *p, u8 *a, int r);
int func_021C20D0(Server *p, u8 *a, int c, u8 *l);
int func_021C2128(Server *p, u8 *a);
int func_021C2204(Server *p, u8 *a, u16 c);
void func_021C2250(Server *p, u8 *a, u16 b, u32 c);
int func_021C2314(Server *p, u8 *a);
void func_021C232C(Server *p, const u16 *a, u8 *b, u8 *c);
u32 func_021C236C(Server *p, u16 id, u8 *a, u8 *b, union Slot *dest);
void func_021C2488(Server *p, u16 id, u8 *a, u32 c);
int func_021C25A4(Server *p, u8 *a, u8 *b, u32 unused, u32 s0, union Slot s1, u32 s2);
int func_021C264C(Server *p, u8 *a, u8 *b, u32 c);
void func_021C26A8(Server *p, u32 a, u8 *b, u8 *c, u32 d);
void func_021C26FC(Server *p, u8 *a, u8 *b, u32 c, union Slot *d);
int func_021C2758(Server *p, u8 *x, u8 *y, int z, union Slot a, u32 b, u32 c);
int func_021C27A0(Server *p, u8 *x, u8 *y, int z, union Slot a, u8 b, u32 c);
int func_021C282C(Server *a, struct Unk021D62A8 *b, int c, union Slot d, u8 e);
void func_021C2910(Server *p, u8 *a, u8 *b, int kind, union Slot value, int f, int g, const void *m);
int func_021C2AB0(Server *p);
int func_021C2AF0(u8 *p, u8 *a);
int func_021C2B3C(Server *p, u8 *a, u8 *b, u32 c);
void func_021C2BA4(Server *p, u8 *a, u8 *b, u32 c);
void func_021C2BF0(Server *p, u8 *a, u8 *b, u32 c, u32 d);
void func_021C2C50(Server *p, u8 *a, u8 *b, u32 c);
void func_021C2CA8(Server *p, u8 *a);
void func_021C2CD8(Server *p, u16 *q, u8 *a, u8 *b);
int func_021C2D10(Server *p, u16 *q, u8 *b, u8 *c);
void func_021C2DC4(Server *p, u32 a, u32 b, u32 c);
extern const u8 data_021EFCF0[4];
extern u8 d_021EFCF4[2][3];
extern u8 d_021EFCFA[2][3];
extern struct Unk021EFD70 data_021EFD70[];
extern u8 d_021F3A60[];
extern u8 d_021F3A70[];
extern const u16 d_021EFDB8[3];
extern u32 d_021F3B2C[];
extern u8 d_021F3B20[];
extern u8 *d_021F3B38[];
extern u16 d_021F3B26[];
extern u8 d_021F3B23[];
extern u32 d_021F3B20b[];










u8 func_021B8CB0(struct Unk021B8CB0 **p, u8 x)
{
    switch ((*p)->mode) {
    case 0:
        return x;
    case 3:
        return x;
    case 1:
        return (x + 2) & 3;
    case 2:
        return x;
    }
    return x;
}









int func_021B8CE8(int a, int b, int c) { int r=1; if ((b&1)==(c&1)) r=0; return r; }









unsigned char func_021B8CFC(char *p, int i)
{
    return *(unsigned char *)(p + i + 0x428);
}










u8 func_021B8D08(u32 x)
{
    u8 i;
    for (i = 0; i < 4; i++) {
        u8 lo = data_021EFCF0[i];
        u8 hi = lo + 5;
        if (x >= lo && x <= hi) return i;
    }
    return 0;
}










u8 func_021B8D38(void *p, int a, int k, u8 *out)
{
    u8 buf[8];
    u8 n;
    u8 cnt;
    u8 i;
    u8 *m;

    n = func_021B8778(p, k, buf);
    i = 0;
    cnt = 0;
    for (; i < n; i++) {
        m = func_021B98A4((char *const *)a, buf[i]);
        if (m && !func_021D5B68(m)) {
            out[cnt++] = func_021D5440(m);
        }
    }
    return cnt;
}










u8 func_021B8D8C(void *p, void *a, u32 b)
{
    u8 i = func_021B8D08(b);
    int r = func_021B9864((int)a, i, b);

    if (r >= 0) {
        u8 s = func_021B8BEC(p, i, r);
        if (s != 6) return s;
    }
    return 6;
}









unsigned char func_021B8DC0(unsigned char *p,void *a,unsigned int b) { int k=func_021B8D8C(p,a,b); if(k!=6) return func_021B8E70(p,k); return 255; }










/*
 * tail-call thunk to func_021B8D08
 */
u8 func_021B8DDC(u32 x)
{
    return func_021B8D08(x);
}










u8 func_021B8DE4(char *p, int i)
{
    return func_021B8CFC(p, i);
}









unsigned char func_021B8DEC(char *p,unsigned char k) { unsigned char i,v,n; i=k; v=func_021B8CFC(p,k); n=0; while(i--!=0) { if(v==(unsigned char)p[i+0x428]) n++; } return n; }










void func_021B8E28(u8 *p, u8 n, u8 *out, u8 *cnt_out)
{
    u8 i = n;
    u8 cnt;
    *out = func_021B8CFC((char *)p, n);
    cnt = 0;
    while (i-- != 0) {
        if (*out == p[i + 0x428]) {
            cnt++;
        }
    }
    *cnt_out = cnt;
}










u8 func_021B8E70(u8 *p, u32 k)
{
    int s0 = 1;
    u8 s;
    u32 mode;
    int r;
    if ((p[0x46d] & 1) != (k & 1)) {
        s0 = 0;
    }
    s = s0;
    mode = *(u32 *)(((struct Obj13271 *)p)->f0 + 4);
    if (mode == 0) {
        r = 0;
        if (s == 0) {
            r = 1;
        }
        return r;
    }
    if (mode == 1) {
        return d_021EFCF4[s][(u8)(k >> 1)];
    }
    return d_021EFCFA[s][(u8)(k >> 1)];
}










u8 func_021B8ED8(u8 *p, u8 k)
{
    u8 par = k & 1;
    u32 mode = *(u32 *)(((struct Obj07744 *)p)->f0 + 4);
    u8 t;
    int r;
    if (mode == 0) {
        if (par != 0) {
            r = 1;
            if (p[0x46d] != 0) {
                r = 0;
            }
            return r;
        }
        return p[0x46d];
    }
    t = p[0x46d] & 1;
    if (par != 0) {
        return (t ^ 1) + (k - 3);
    }
    return t + (k - 2);
}









int func_021B8F38(unsigned char *p) { unsigned int v; if(func_021B86C8((unsigned char **)p)) { v=(unsigned int)func_021B86B8((void ***)p); if(v!=1 && v!=0) return 1; } return 0; }









int func_021B8F5C(char *p,int k) { func_021B969C(p+0xc8,p,k,0); return func_021B985C(p+0xc8,k); }










int func_021B8F7C(u8 *p, u32 k)
{
    u8 n;
    if (func_021B86C8((unsigned char **)p)) {
        n = (k + 2) & 3;
        if (func_021B8B9C(p, n)) {
            func_021B969C((char *)(p + 0xc8), (char *)p, n, 0);
            return func_021B985C((char *)(p + 0xc8), n);
        }
    }
    return 0;
}









unsigned char func_021B8FC0(unsigned char *p,unsigned int k) { if(func_021B86C8((unsigned char **)p)) return (unsigned char)((k&2)!=0); return 0; }









u8 func_021B8FE4(u8 *p)
{
    return func_021B8FC0(p, p[0x46c]);
}










u8 func_021B8FF4(u8 *p)
{
    return ((struct Obj18132 *)p)->f46C;
}









u8 func_021B9000(u8 *p) { return func_021B9010(p,p[0x46c]); }









u8 func_021B9010(u8 *p, u8 k) { u8 n; n=(k+2)&3; if(!func_021B8B9C(p,n)) n=4; return n; }









int func_021B902C(int a, int b) { if(a==b) return 1; if(a==(u8)((b+2)&3)) return 1; return 0; }









u8 func_021B904C(u8 *p,int k) { return func_021B9064(p,p[0x46c],k); }









u32 func_021B9064(u8 *p, int k, int x) { u8 m; k &= 1; k ^= 1; if(x) { m=k+((x&1)<<1); if(func_021B8B9C(p,m)) k=m; } return k; }









void func_021B9090(u8 *p, u32 k, u32 x) { u8 *q; q=*(u8 * *)&((struct Obj09938 *)p)->f0; if(q[0x23]==0 && k==p[0x46c]) func_02007F1C(((struct Obj13272 *)q)->f60,x,1,((struct Obj09938 *)p)->f468); }









void func_021B90BC(u8 *p,u8 k,u32 x) { u8 *q; q=*(u8 * *)&((struct Obj09939 *)p)->f0; if(q[0x23]==0 && k==p[0x46c]) func_02007E50(((struct Obj13273 *)q)->f60,x,1,((struct Obj09939 *)p)->f468); }










/*
 * double deref: *(u32*)(*p + 0x60)
 */
u32 func_021B90E8(void **p)
{
    return ((struct Obj18134 *)((u8 *)*p))->f60;
}










/*
 * double deref: *(u32*)(*p + 0x64)
 */
u32 func_021B90F0(void **p)
{
    return ((struct Obj18136 *)((u8 *)*p))->f64;
}









int func_021B90F8(u8 *p) { u8 *q; q=*(u8 * *)&((struct Obj20977 *)p)->f0; if(((struct Obj13274 *)q)->f94!=0 && q[0x23]==0) return 1; return 0; }










/* 021B9114  ldr r0,[r0]; adds r0,#0x23; ldrb r0,[r0] */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; adds r0, #0x23; ldrb r0, [r0]; bx lr.
 */
u8 func_021B9114(u8 **p) { return ((struct Obj18137 *)(*p))->f23; }










/* 021B911C  movs r0,#0; bx lr */
/*
 * Returns the constant #0.
 */
int func_021B911C(void *p, int k) { return 0; }









void func_021B9120(u8 *p, u8 n)
{
    u8 cnt;
    u8 t;
    u8 m;
    if (*(u8 *)(*(u32 *)p + 0x90) == 6) {
        m = n;
        t = func_021B8CFC((char *)p, n);
        cnt = 0;
        while (m--) {
            if (t == *(u8 *)(p + m + 0x428))
                cnt++;
        }
        *(u8 *)(*(u32 *)p + 0x90) = cnt;
    }
}









void func_021B916C(u8 *p,u32 x) { if(((struct Obj13275 *)p)->f444==7) ((struct Obj13275 *)p)->f444=x; }










/*
 * tail-call thunk to func_021BA54C
 */
int func_021B917C(char *p)
{
    return func_021BA54C(p);
}









void func_021B9184(Flags_021B9184 **p)
{
    (*p)->flag = 1;
}










u32 func_021B919C(u8 *p)
{
    if (((B_td *)p)->d == 0) {
        if (((B_td *)p)->g) {
            ((struct Obj06219 *)p)->f430 = ((struct Obj06219 *)p)->f430 << 1;
        }
        ((struct Obj06219 *)p)->f430 = func_0201119C(((struct Obj06219 *)p)->f430);
        ((B_td *)p)->d = 1;
    }
    return ((struct Obj06219 *)p)->f430;
}










/*
 * Unlabelled Thumb leaf in a .word run.  If bit 3 of p[0x473] is clear,
 * adds `add` to the word at p+0x434 and clamps it to 0x1869f.
 * The bit test is a lsls #0x1c / lsrs #0x1f pair, so the promoted value
 * must stay unsigned.
 */
void func_021B91E4(void *p, int add)
{
    if (((unsigned int)((struct Obj07745 *)p)->f473 << 28 >> 31) != 0)
        return;
    ((struct Obj07745 *)p)->f434 += add;
    if (((struct Obj07745 *)p)->f434 > 0x1869f)
        ((struct Obj07745 *)p)->f434 = 0x1869f;
}









u32 func_021B9210(u8 *p) { u32 n; n=((struct Obj20979 *)p)->f434; if(((Flags_021B9210 *)(p+0x473))->flag) { n*=2; if(n>99999) n=99999; } return n; }









/*
 * Unlabelled Thumb leaf in a .word run:
 *   ldr r2,[pc,#8]; movs r1,#0x40; ldrb r3,[r0,r2]; orrs r1,r3; strb r1,[r0,r2]; bx lr
 * with pool word 0x473.  Sets bit 6 of the byte at p+0x473.
 */
void func_021B9234(unsigned char *p)
{
    p[0x473] |= 0x40;
}










u32 func_021B9244(char *p)
{
    u32 r;
    u32 m;
    u32 c;

    r = 0;
    if (((u32)((struct Obj04354 *)p)->f473 << 27 >> 31) == 0) {
        if (**(u32 * *)&((struct Obj04354 *)p)->f0 <= 1) {
            m = func_0200C274(func_02012F08(((struct Obj20982 *)(*(char * *)&((struct Obj04354 *)p)->f0))->f58));
            c = func_021D7FF8(((struct Obj20983 *)(*(char * *)&((struct Obj04354 *)p)->f0))->f80, func_021B9AF8(p + 0x1b0, ((struct Obj04354 *)p)->f46C));
            if (c > m)
                c = m;
            r = c;
            ((struct Obj04354 *)p)->f438 = r;
        }
        ((struct Obj04354 *)p)->f473 |= 0x10;
    }
    return r;
}









void func_021B92A0(u8 *p) { p[0x473]|=32; }









void func_021B92B0(char *p,void *m,int k) { u8 *q; q=*(u8 * *)&((struct Obj07746 *)p)->f0; if(((struct Obj13276 *)q)->f0<=1 && q[0x23]==0) func_021B92D4(p,m,k?5:4); }










void func_021B92D4(char *p, void *m, int c)
{
    u8 i;
    void *x;
    void *y;
    char *e;

    i = func_021D5440(m);
    x = func_021B9940(p + 0x1b0, i);
    y = func_021B9940(p + 0xc8, i);
    x = func_021D5844(x);
    y = func_021D5844(y);
    e = func_021B8714((char **)p);
    func_0201B7A0(x, c, ((struct Obj13277 *)e)->fA, (u16)((((struct Obj07746 *)p)->f468 & 0x7fff) | 0x8000));
    func_0201B7A0(y, c, ((struct Obj13277 *)e)->fA, (u16)((((struct Obj07746 *)p)->f468 & 0x7fff) | 0x8000));
}









void func_021B9358(char *p, int i)
{
    u8 *dst = func_021B9934(p + 0x1b0, i);
    u8 *src = func_021B9934(p + 0xc8, i);
    func_021D54F4((struct Work *)src, (struct Work *)dst);
}










u8 *func_021B937C(void *a, char *b, u8 *c)
{
    u8 *t;
    void *v;
    void *k;
    int e;
    char *g;
    u32 n;
    u32 i;

    if (func_021D6C24((struct R4 *)c)) {
        e = func_021B8DDC(func_021D5440(c));
        k = func_021D5864((struct Work *)c);
        g = func_021B9AF8(b, e);
        n = func_021B9B94((struct Q1 *)g);
        for (i = 0; i < n; i++) {
            t = func_021B9C00((struct S2 *)g, (u8)i);
            v = func_021D5844(t);
            if (v == k)
                return t;
        }
    }
    return c;
}










void func_021B93E0(char *p, u32 a, u32 b)
{
    u32 i;
    u32 j;
    u32 k;

    ((struct Obj13278 *)p)->f0 = a;
    ((struct Obj13278 *)p)->fE4 = b;
    for (i = 0; i < 4; i++)
        func_021B9B40((u8 *)(p + 4 + i * 0x1c));
    for (j = 0; j < 0x18; j++)
        *(u32 *)(p + 0x84 + j * 4) = 0;
    for (k = 0; k < 4; k++)
        *(u32 *)(p + 0x74 + k * 4) = 0;
}









void func_021B9424(char *p)
{
    unsigned int i;
    for (i = 0; i < 24; i++) {
        if (*(void **)(p + i * 4 + 0x84) != 0) {
            func_021D53B8(*(void **)(p + i * 4 + 0x84));
            *(void **)(p + i * 4 + 0x84) = 0;
        }
    }
    for (i = 0; i < 4; i++) func_021B9B40((u8 *)(p + 4 + i * 28));
}









#pragma opt_lifetimes off









/*
 * 2026-10-05 (wave P5, pengy share): EXACT. Needs #pragma opt_lifetimes off (per-function
 * pragma) and the clear of nw written AFTER the func_021BA178 call (l2 = f(...); nw = 0;).
 * Written before the call, the zero took r0 instead of the original r1. Other levers: raw
 * offsets, early locals qs = a + 4 and qo = c * 0x1c, declaration order qo, qs, list, n, v, nw,
 * x, j, i, y, cnt, comma-form loop headers, e = func_0201AB28() as its own statement.
 */
void func_021B9460(char *a, char *b, u8 c)
{
    u32 qo;
    char *qs;
    void *list;
    u32 n;
    u8 *v;
    void *e;
    u8 nw;
    u8 x;
    u32 j;
    int i;
    u8 y;
    int cnt;
    list = func_021BA178(b, c, *(u32 *)(a + 0xe4));
    qs = a + 4;
    qo = c * 0x1c;
    n = func_0201AA18(list);
    x = data_021EFCF0[c];
    *(void **)(a + c * 4 + 0x74) = list;
    for (i = 0, y = x; i < n; i++, y++) {
        e = func_0201AB28(list, i);
        *(void **)(a + y * 4 + 0x84) = (struct S *)func_021D4D84(e, y, 0x12);
        func_021B9B54((struct Q1 *)(qs + qo), (u32)(*(void **)(a + y * 4 + 0x84)));
    }
    cnt = func_021B9634(list);
    if (cnt > 0) {
        for (i = 0, y = x; i < cnt; i++, y++) {
                if (func_021D59B4(*(u8 **)(a + y * 4 + 0x84), 0x11) == 0x95)
                    func_021D5848(*(void **)(a + y * 4 + 0x84), func_0201AB28(list, cnt));
            }
    }
    if (func_021B86B8((void ***)b) == 0 && c == 1) {
        for (j = 0; j < n; j++, x++) {
            v = *(u8 **)(a + x * 4 + 0x84);
            if (func_021D5444((struct QF *)v) == 0x23B && func_021D59B4(v, 0x11) == 0x95) {
                void *l2;
                u8 m, q;
                l2 = func_021BA178(b, 0, *(u32 *)(a + 0xe4));
                nw = 0;
                m = func_0201AA18(l2);
                for (q = 0; q < m; q++) {
                    u16 s = func_02017E1C(func_0201AB28(l2, q), 5, 0);
                    if (s == 0xf3) { nw = 0xf4; break; }
                    if (s == 0xf4) { nw = 0xf5; break; }
                    if (s == 0xf5) { nw = 0xf3; break; }
                }
                if (nw != 0) {
                    if (*(void **)(b + 0x2c0) == 0)
                        *(void **)(b + 0x2c0) = func_020173F0(nw, func_021D59B4(v, 0xf), 0, *(u16 *)(b + 0x468));
                    func_021D5848((struct QH *)v, *(void **)(b + 0x2c0));
                }
            }
        }
    }
    func_021B9B60((u8 *)(qs + qo));
}









#pragma opt_lifetimes reset










int func_021B9634(void *a)
{
    int i;
    void *e;

    for (i = func_0201AA18(a) - 1; i >= 0; i--) {
        e = func_0201AB28(a, i);
        if (func_02017E1C(e, 0x4c, 0) == 0 && func_02017E1C(e, 0xa0, 0) != 0)
            return i;
    }
    return -1;
}









void func_021B9674(char *p)
{
    unsigned int i;
    for (i = 0; i < 24; i++) {
        if (*(void **)(p + i * 4 + 0x84) != 0) {
            func_021D53B8(*(void **)(p + i * 4 + 0x84));
            *(void **)(p + i * 4 + 0x84) = 0;
        }
    }
}









void func_021B969C(char *a, char *b, int k, int flag)
{
    void *list;
    char *g;
    u32 n, i, j;
    void *m, *e;
    void *h;
    u8 links[6];
    list = (void *)func_021B985C(a, k);
    g = func_021B9AEC(a, k);
    n = func_0201AA18(list);
    func_0201A948(((struct Obj09940 *)b)->f2B8);
    for (i = 0; i < 6; i++) links[i] = 6;
    for (i = 0; i < n; i++) {
        m = (void *)func_021B9BF0((struct S2 *)g, (u8)i);
        func_021D6B84(m, flag);
        func_0201A98C(((struct Obj09940 *)b)->f2B8, func_021D5844(m));
        if (func_021D6C24(m)) {
            h = func_021D5864(m);
            for (j = 0; j < n; j++) {
                if (h == func_021D5844((void *)func_021B9BF0((struct S2 *)g, (u8)j))) {
                    links[i] = j;
                    break;
                }
            }
        }
    }
    func_0201AC2C(((struct Obj09940 *)b)->f2B8, list);
    for (i = 0; i < n; i++) {
        e = func_0201AB28(list, i);
        m = (void *)func_021B9BF0((struct S2 *)g, (u8)i);
        func_021D6C3C(m, e);
        if (links[i] != 6)
            func_021D5848(m, func_0201AB28(list, links[i]));
    }
}










void func_021B97A0(char *a, char *b, int k)
{
    void *list;
    char *g;
    u32 n;
    u32 t;
    u32 i;
    u32 j;
    void *m;

    list = (void *)func_021B985C(a, k);
    g = func_021B9AEC(a, k);
    n = func_0201AA18(list);
    func_0201A948(((struct Obj07747 *)b)->f2B8);
    t = data_021EFCF0[k];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m = (void *)func_021B9BF0((struct S2 *)g, (u8)j);
            if (t + i == func_021D5440(m)) {
                func_021D6B84(m, 1);
                func_0201A98C(((struct Obj07747 *)b)->f2B8, func_021D5844(m));
                if (func_021D67D0(m) != 0)
                    *(u8 *)(*(char * *)&((struct Obj07747 *)b)->f0 + i + 0xc2) = 1;
                break;
            }
        }
    }
    func_0201AC2C(((struct Obj07747 *)b)->f2B8, list);
}









int func_021B985C(char *p, int i)
{
    return *(int *)(p + i * 4 + 0x74);
}










int func_021B9864(int a, int b, int c)
{
    char *p = (char *)(a + 4) + b * 0x1c;
    unsigned int n = func_021B9B94((struct Q1 *)p);
    unsigned int i;
    for (i = 0; i < n; i++) {
        if (c == func_021D5440((u8 *)func_021B9C00((struct S2 *)p, (unsigned char)i)))
            return i;
    }
    return -1;
}










/*
 * tail-call thunk to func_021B98AC
 */
u8 *func_021B98A4(char *const *q, u8 b)
{
    return func_021B98AC(q, b);
}










u8 *func_021B98AC(char *const *q, u8 b)
{
    u8 i = b;
    char *p = *q;
    u8 a;
    u8 cnt;
    char *g;

    a = func_021B8CFC(p, b);
    cnt = 0;
    while (i-- != 0) {
        if (a == *(u8 *)(p + i + 0x428))
            cnt++;
    }
    g = (char *)q + 4 + a * 0x1c;
    if (cnt < func_021B9B94((struct Q1 *)g))
        return func_021B9C00((struct S2 *)g, cnt);
    return 0;
}









void *func_021B990C(char *p, unsigned int i, unsigned int j)
{
    return (void *)func_021B9BF0((void *)((unsigned int)p + 4 + i * 28), j);
}









u8 *func_021B9920(void *p, u32 i, u8 j)
{
    return func_021B9C00((void *)((unsigned int)p + 4 + i * 28), j);
}










u8 *func_021B9934(char *p, int i)
{
    return *(u8 **)(p + i * 4 + 0x84);
}










u8 *func_021B9940(char *p, u8 i)
{
    return *(u8 **)(p + i * 4 + 0x84);
}









/*
 * evidence: original narrows second argument before 021B8ED8 call.
 */
int func_021B994C(u8 *p, u32 i, void **out)
{
    void *v;
    u32 n = func_021B8DE4((char *)p, func_021B8ED8(p, i));
    v = *(void **)(p + n * 4 + 0x3e0);
    if (v != 0) {
        *out = v;
        return 1;
    }
    return 0;
}









int func_021B997C(u8 *p, unsigned int i)
{
    if (func_021B9114((u8 **)p) == 0) {
        unsigned int q = (unsigned int)p + 0x3e0;
        if (*(void **)(q + i * 4) != 0 && func_02007B50(*(void **)(q + i * 4)) != 0)
            return func_02007C70(*(void **)(q + i * 4));
        return 0;
    }
    return *(u8 *)((unsigned int)*(u8 * *)&((struct Obj13279 *)p)->f0 + i + 0x44);
}










int func_021B99B8(void *pp, unsigned int b)
{
    return func_021B6994((struct S_021B8CB0 * *)pp, b);
}









/*
 * evidence: entry r1 is forwarded unchanged to the two-argument 021B6994.
 */
int func_021B99C0(struct S_021B8CB0 **p, u32 b)
{
    int result = func_021B6994((struct S_021B8CB0 * *)p, b);
    if (func_021B8588((void **)p) == 3) result = (u8)(result + 2);
    return result;
}










struct Unk021EFD70 *func_021B99E0(int i)
{
    return &data_021EFD70[i];
}










u32 func_021B99F0(u32 x) { return (x == 2 || x == 3) ? 1 : 0; }












int func_021B9A00(u32 x, u8 *out)
{
    if (func_021B99F0(x) == 0) {
        *out = func_021B8C20(2, x, (u8)(x >> 1));
        return 1;
    }
    return 0;
}












int func_021B9A24(unsigned int a, unsigned int b)
{
    unsigned char v = func_021B9A40(a);
    if (v == func_021B9A40(b)) return 1;
    return 0;
}












unsigned char func_021B9A40(unsigned int x)
{
    BOOL result;
    if (x < 12) result = FALSE;
    else result = TRUE;
    return result;
}













unsigned char func_021B9A50(unsigned int x)
{
    return func_021B9A5C(func_021B9A40(x));
}













/* 021B9A5C  cmp r0,#0; bne; movs r0,#1; else 0; zext8 */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: cmp r0, #0; bne loc_021B9A64; movs r0, #1; b loc_021B9A66; movs r0, #0; lsls r0, r0, #0x18; lsrs r0, r0, #0x18; bx lr.
 */
u8 func_021B9A5C(u32 x) { return x == 0; }













int func_021B9A6C(int a, u32 b)
{
    struct Unk021EFD70 *p = func_021B99E0(a);
    u32 i;

    for (i = 0; i < p->n0; i++) {
        if (b == p->b[i])
            return 1;
    }
    for (i = 0; i < p->n1; i++) {
        if (b == *((u8 *)p + 7 + i))
            return 1;
    }
    return 0;
}












u8 func_021B9AB0(u8 x)
{
    switch (x) {
    case 2: return 1;
    case 3: return 2;
    default: return 0;
    }
}












int func_021B9AC8(int a) {
    switch (a) { case 2: return 2; case 3: return 1; default: return 0; }
}












unsigned char func_021B9AE0(unsigned int x)
{
    return x & 1;
}












char *func_021B9AEC(char *p, int i)
{
    return p + 4 + i * 0x1c;
}












char *func_021B9AF8(char *p, int i)
{
    return p + 4 + i * 0x1c;
}













unsigned char func_021B9B04(int a, int b)
{
    return func_021B9B98((u8 *)func_021B9AF8((char *)a, b));
}












void func_021B9B10(u8 *p,u8 i,int v) {
    void *q;
    if(p[0x46e] && func_021B8B9C(p,i)) {
        q=*(void **)(p+i*4+16);
        if(q) func_021CD9F4(q,v);
    }
}












void func_021B9B40(u8 *p) {
    int i;
    p[24] = 0;
    for(i=0;i<6;i++) ((u32 *)p)[i]=0;
}












void func_021B9B54(struct Q1 *p, u32 v)
{
    u8 n = p->count;
    p->count = n + 1;
    p->items[n] = v;
}












void func_021B9B60(u8 *p) {
    unsigned int j;
    int i;
    j=0;
    i=0;
    for(;j<p[24];j++) {
        if(func_021D5B7C(*(void **)((u32)p+(u32)i*4))) i++;
        else func_021B9C24(p,i);
    }
}












/* 021B9B94  ldrb r0,[r0,#0x18] */
/*
 * Reads the u8 field at #0x18 of the argument and returns it.
 */
u8 func_021B9B94(struct Q1 *p) { return p->count; }












u8 func_021B9B98(u8 *p) {
    int i;
    u32 n;
    i = 0;
    n = 0;
    for (; i < p[24]; i++) if (func_021D5B7C(((void **)p)[i])) n++;
    return n;
}












u8 func_021B9BC4(u8 *p,int i) {
    u32 n=0;
    for(;i<p[24];i++) if(func_021D5B7C(*(void **)((u32)p+(u32)i*4))) n++;
    return n;
}












u32 func_021B9BF0(struct S2 *p, u32 i)
{
    if (i < p->count)
        return (u32)p->items[i];
    return 0;
}












/* 021B9C00  same shape as 021B9BF0 */
u8 *func_021B9C00(struct S2 *p, u32 i)
{
    if (i < p->count)
        return p->items[i];
    return 0;
}












void func_021B9C10(u32 *p, int a, int b) {
    u32 t=*(u32 *)((u32)p+(u32)a*4);
    *(u32 *)((u32)p+(u32)a*4)=*(u32 *)((u32)p+(u32)b*4);
    *(u32 *)((u32)p+(u32)b*4)=t;
}












void func_021B9C24(u8 *p, u8 i) {
    u32 t=((u32 *)p)[i];
    for(;i<p[24]-1;i++) ((u32 *)p)[i]=((u32 *)p)[i+1];
    ((u32 *)p)[i]=t;
}












void func_021B9C50(u8 **p, u8 k, u8 **o1, u8 **o2)
{
    u8 *t;
    int a;
    int b;

    if (k != 0) {
        if (k != 1) {
            t = p[0];
            a = func_021B9AB0(k);
            b = func_021B9AC8(k);
            p[0] = p[a];
            p[a] = p[b];
            p[b] = t;
            if (o1)
                *o1 = t;
            if (o2)
                *o2 = p[0];
        }
    }
}











int func_021B9C98(u8 *p,u32 v) {
    int i;
    for(i=0;i<*(volatile u8 *)&((struct Obj20992 *)p)->f18;i++) {
        u32 t=*(u32 *)((u32)p+(u32)i*4);
        if(t==v) return i;
    }
    return -1;
}











int func_021B9CBC(u8 *p, int v) {
    int i;
    for(i=0;i<p[24];i++) if(v==func_021D5440(*(void **)((u32)p+(u32)i*4))) return i;
    return -1;
}











void *func_021B9CE8(u8 *p) {
    int i;
    for(i=0;i<p[24];i++) if(func_021D5B7C(*(void **)((u32)p+(u32)i*4))) return *(void **)((u32)p+(u32)i*4);
    return 0;
}












void func_021B9D10(char *a, struct Arr *arr, int k)
{
    int j;
    void *m;
    void *h;

    for (j = arr->n - 1; j > 0; j--) {
        if (func_021D5B7C(arr->e[j]) != 0)
            break;
    }
    if (func_021B8588((void **)a) != 3)
        k = func_021B8B78((unsigned char *)a, k);
    else
        k = 3;
    for (; k < arr->n; k++) {
        m = arr->e[k];
        if (func_021D59B4(m, 0x11) == 0x95) {
            if (k < j) {
                func_021D5848(m, func_021D5844(arr->e[j]));
            } else {
                h = func_021D5864(m);
                if (h != ((struct Obj20995 *)a)->f2C0)
                    func_021D5854(m);
            }
        }
    }
    for (k = 0; k < arr->n; k++)
        func_021D6C24(arr->e[k]);
}











void func_021B9DB8(char *p) {
    u32 i;
    char *q;
    for(i=0;i<4;i++) {
        q=p+i*40;
        ((struct Obj09942 *)q)->f20=0;
        ((struct Obj09942 *)q)->f2A=0;
        ((struct Obj09942 *)q)->f2C=0;
    }
    for(i=0;i<4;i++) *(u32 *)(p+i*4+0x3e0)=0;
}












void func_021B9DE8(char *p)
{
    u32 i;
    char *q;

    for (i = 0; i < 4; i++) {
        q = p + i * 0x28;
        if (((struct Obj03187 *)q)->f20) {
            func_020307B0(((struct Obj03187 *)q)->f20);
            ((struct Obj03187 *)q)->f20 = 0;
        }
        if (((struct Obj03187 *)q)->f24) {
            func_020307B0(((struct Obj03187 *)q)->f24);
            ((struct Obj03187 *)q)->f24 = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        q = p + i * 4;
        if (((struct Obj03187 *)q)->f3E0) {
            func_020307B0(((struct Obj03187 *)q)->f3E0);
            ((struct Obj03187 *)q)->f3E0 = 0;
        }
    }
}











void func_021B9E38(char *p, int a, int b)
{
    u16 f;

    void *h = func_0200846C(a);

    ((struct Obj01371 *)p)->f0 = h;
    func_02008494((void *)b, h);
    f = 0;
    ((struct Obj01371 *)p)->fA = 0;
    if (func_02008550(((struct Obj01371 *)p)->f0))
        f = 1;
    ((struct Obj01371 *)p)->f8 = f;
    ((struct Obj01371 *)p)->f4 = (int)func_02008510(((struct Obj01371 *)p)->f0, 0x12);
    func_0202428C(p + 0x18);
    func_0202428C(p + 0x20);
}











void func_021B9E7C(struct A *p, struct B_021B9A00 *src)
{
    unsigned int i;

    p->vt = 0;
    if (src) {
        p->ha = src->f0;
        p->h8 = src->f4;
        p->q = (int)func_02045874((struct U16Vec *)src->f14, 0x12);
        p->c = src->f8;
        func_02082D44(src->b, p->h, 8);
        func_02024570((struct Rec8 *)(&p->s18), (const struct Rec8 *)(&src->s18));
        func_02024570((struct Rec8 *)(&p->s20), (const struct Rec8 *)(&src->s20));
    } else {
        p->ha = 0;
        p->h8 = 0;
        p->q = 0;
        for (i = 0; i < 4; i++) {
            p->h[i] = 0;
        }
        func_0202428C(&p->s18);
        func_0202428C(&p->s20);
    }
}


















void func_021B9EF0(struct A *p, const struct B_021B9EF0 *src)
{
    unsigned int i;
    int t, u;

    p->vt = 0;
    if (src) {
        p->ha = src->f0;
        p->h8 = src->f4;
        t = (int)func_020457B0(0x20, 0x12);
        u = src->f68 + 1;
        p->q = t;
        func_02045A00((struct Buf *)t, (char *)src + 0x28, u);
        p->c = src->f8;
        func_02082D44((void *)src->b, (void *)p->h, 8);
        func_02024570((struct Rec8 *)(&p->s18), (const struct Rec8 *)(&src->s18));
        func_02024570((struct Rec8 *)(&p->s20), (const struct Rec8 *)(&src->s20));
    } else {
        p->ha = 0;
        p->h8 = 0;
        p->q = 0;
        for (i = 0; i < 4; i++) {
            p->h[i] = 0;
        }
        func_0202428C(&p->s18);
        func_0202428C(&p->s20);
    }
}


















/* 021B9F70  movs r2,#0x28; muls r2,r1,r2; adds r0,r0,r2; ldr r0,[r0,#0x20] */
int func_021B9F70(u8 *p, int i) { return *(u32 *)(p + i * 0x28 + 0x20) == 0; }

















u16 func_021B9F84(char *p,int i,unsigned int j) {
    char *q;
    if(func_021B9F70((u8 *)p,i)) {
        q=(char *)((u32)p+32+(u32)i*40);
        if(j<4) return *(u16 *)((u32)q+16+j*2);
    }
    return 0;
}

















u32 func_021B9FAC(u8 *p, int i, u32 *out) {
    u32 q = (u32)p + (u32)i * 40;
    *out = ((struct Obj13281 *)q)->f28;
    return ((struct Obj13281 *)q)->f24;
}


















int func_021B9FBC(char *p, int i)
{
    if (func_021B86B8((void ***)p) == 0) {
        i = 8;
        if (func_021BA1A8((char **)p, i)) {
            return i << 8;
        }
        if (func_021B8588((void **)p) == 1) {
            return 0x80;
        }
    } else {
        if (func_021B9F70((u8 *)p, i)) {
            return *(int *)(p + i * 0x28 + 0x2c);
        }
    }
    return 0;
}

















u16 func_021BA004(char *p, int i)
{
    if (func_021B9F70((u8 *)p, i)) return *(u16 *)((u32)p + (u32)i * 0x28 + 0x2a);
    return 0;
}
















unsigned short func_021BA020(char *p, int i)
{
    return *(unsigned short *)(p + i * 0x28 + 0x28);
}
















void *func_021BA02C(char *p, int i, int mode)
{
    if ((int)func_021B86B8((void ***)p) == 2 && func_021B9F70((u8 *)p, i)) {
        if (mode == 1) return (void *)(((u32)p + 0x40) + (u32)i * 0x28);
        return (void *)(((u32)p + 0x38) + (u32)i * 0x28);
    }
    return 0;
}
















int func_021BA064(char *p, int i)
{
    if (func_021B9F70((u8 *)p, i)) return 0;
    return *(int *)((u32)p + (u32)i * 0x28 + 0x20);
}

















/*
 * branch, so the pool relocation cannot be witnessed.  All bytes correct.
 */
void func_021BA080(char **p)
{
    func_0202E7DC((char *)(((struct Obj20998 *)(*p))->f70));
}
















/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0xaf; lsls r1, r1, #2; ldr r0, [r0, r1]; bx lr.
 */
u32 func_021BA08C(struct Q2 *p) { return p->v; }
















void func_021BA094(struct S_021B8CB0 *p)
{
    unsigned int i;
    for (i = 0; i < 4; i++) {
        p->a[i] = func_0201A920(0x12);
        p->b[i] = func_0201A920(0x12);
    }
    p->c = func_0201A920(0x12);
}

















void func_021BA0CC(struct S_021B8CB0 *p)
{
    unsigned int i;

    for (i = 0; i < 4; i++) {
        if (p->a[i]) {
            func_020307B0(p->a[i]);
            p->a[i] = 0;
        }
        if (p->b[i]) {
            func_020307B0(p->b[i]);
            p->b[i] = 0;
        }
    }
    if (p->c) {
        func_020307B0(p->c);
        p->c = 0;
    }
}

















void func_021BA128(struct S_021B8CB0 *p, int i, void *x)
{
    if (p->a[i]) {
        func_0201A948(p->a[i]);
        func_0201A948(p->b[i]);
        func_0201AC2C(x, p->a[i]);
        func_0201AC2C(x, p->b[i]);
        if (func_0201AA18(p->b[i])) {
            func_0201AB28(p->b[i], 0);
        }
    }
}
















void *func_021BA178(void *p, int i, int mode)
{
    if (mode) {
        if (func_0201AA18(*(void **)(((u32)p + 0x2a8) + (u32)i * 4)))
            func_0201AB28(*(void **)(((u32)p + 0x2a8) + (u32)i * 4), 0);
        return *(void **)(((u32)p + 0x2a8) + (u32)i * 4);
    }
    return *(void **)((u32)p + (u32)i * 4 + 0x298);
}

















int func_021BA1A8(char **p, int m)
{
    return func_02013158(*p, m);
}
















void func_021BA1B4(char **p, int i)
{
    if (((struct Obj20999 *)(*p))->f23 == 0)
        sub_02008DF0(*(struct Sub02008C20Obj * *)&((struct Obj21000 *)(*p))->f6C, i);
}
















void func_021BA1CC(char **p, int i, u32 delta)
{
    if (((struct Obj21001 *)(*p))->f23 == 0)
        sub_02008DAC(*(struct Sub02008C20Obj * *)&((struct Obj21002 *)(*p))->f6C, i, delta);
}
















char *func_021BA1E4(char **p)
{
    return *p + 0x78;
}
















BOOL func_021BA1EC(char **p)
{
    BOOL result = FALSE;
    if (func_021B6818((unsigned int *)((int *)*p)) == 1) {
        if (((struct Obj21004 *)(*p))->f7F) result = TRUE;
    }
    return result;
}
















int func_021BA20C(char **p)
{
    int v;
    if (func_021B6818((unsigned int *)((int *)*p)) == 1) return func_021BA1EC(p);
    v = (int)func_021B86B8((void ***)p);
    switch (v) {
    case 0:
    case 1: return 1;
    default: return 0;
    }
}















void func_021BA238(char *p, void *m)
{
    func_021B92D4(p, m, 0);
    func_021BB8BC(((struct Obj07746 *)p)->f8, m);
}
















void func_021BA250(char *p, u8 *a, int b)
{
    u8 i;
    void *x;
    void *y;
    void *xv;
    void *yv;
    char *q;

    i = func_021D5440(a);
    x = func_021B9940(p + 0x1b0, i);
    y = func_021B9940(p + 0xc8, i);
    xv = func_021D5844(x);
    yv = func_021D5844(y);
    q = func_021B8714((char **)p);
    func_0201B7B4(xv, b, ((struct Obj13285 *)q)->fA, (((struct Obj13284 *)p)->f468 & 0x7fff) | 0x8000);
    func_0201B7B4(yv, b, ((struct Obj13285 *)q)->fA, (((struct Obj13284 *)p)->f468 & 0x7fff) | 0x8000);
}















void func_021BA2D4(u32 p, u32 *q) {
    u8 *v = *(u8 **)(p + 8);
    if (v) func_021BB8DC(v, q);
}















void func_021BA2E4(char *p)
{
    void *list;
    u32 n, move, k0, i0, k, slot;
    char *group;
    u32 count, total, maximum, i, base, j, obj;
    void *old, *mon;
    u8 *m;
    u32 tmp, tmp1, tmp2;
    if (((struct Obj21005 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f23 != 0) return;
    if (*(u32 *)*(char * *)&((struct Obj00324 *)p)->f0 <= 1) {
        func_021B97A0(p + 0x1b0, p, (u8)p[0x46c]);
        list = (void *)func_021B985C(p + 0x1b0, (u8)p[0x46c]);
        if (*(u32 *)*(char * *)&((struct Obj00324 *)p)->f0 == 1 && func_021D7F60((u16)(u32)func_021BA020(p, 1)))
            func_0201B818(list, *(u16 *)(func_021B8714((char **)p) + 10), (u16)((((struct Obj00324 *)p)->f468 & 0x7fff) | 0x8000));
        if (*(u32 *)*(char * *)&((struct Obj00324 *)p)->f0 == 1) {
            n = func_0201AA18(list);
            for (i0 = 0; i0 < n; i0++) {
                old = func_0201AB28(((struct Obj21009 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f24, i0);
                mon = func_0201AB28(list, i0);
                move = (u16)func_02017E1C(old, 6, 0);
                if (!func_021D805C((void *)move, 0x10))
                    func_02017E40(mon, 6, move);
                else if (move != func_02017E1C(mon, 6, 0))
                    func_02017E40(mon, 6, 0);
            }
        }
        func_0201AC2C(list, ((struct Obj21010 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f24);
        for (i0 = 0; i0 < (u32)func_0201AA18(list); i0++) func_0201AB28(list, i0);
    }
    if (*(u32 *)*(char * *)&((struct Obj00324 *)p)->f0 == 0) {
        k0 = (u8)func_021B9064((u8 *)p, (u8)p[0x46c], 0);
        func_021B969C(p + 0x1b0, p, k0, 1);
        func_0201AC2C((void *)func_021B985C(p + 0x1b0, k0), ((struct Obj21012 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f28);
    }
    if (*(u32 *)*(char * *)&((struct Obj00324 *)p)->f0 == 4) return;
    for (k = 0; k < 4; k++) {
        slot = func_021BA710((u8)p[0x46c], (u8)k);
        for (j = 0; j < 6; j++) { obj = *(u32 *)&((struct Obj00324 *)p)->f0; tmp1 = slot * 6; *(u8 *)(j + (tmp1 + obj) + 0xc8) = 0; }
        if (func_021B8B9C((u8 *)p, (u8)slot)) {
            group = func_021B9AEC(p + 0xc8, slot);
            count = func_021B9B94((struct Q1 *)group);
            total = maximum = 0;
            base = data_021EFCF0[slot];
            for (j = 0; j < count; j++) {
                m = (u8 *)func_021B9BF0((struct S2 *)((struct S2 *)group), (u8)j);
                i = (u8)(func_021D5440(m) - base);
                total += func_021D59B4(m, 13);
                maximum += func_021D59B4(m, 14);
                if (func_021D5B68(m)) { obj = *(u32 *)&((struct Obj00324 *)p)->f0; tmp = slot * 6; *(u8 *)(i + (tmp + *(u32 *)&((struct Obj00324 *)p)->f0) + 0xc8) = 2; }
                else if (func_021D62A8((struct Unk021D62A8 *)m)) { obj = *(u32 *)&((struct Obj00324 *)p)->f0; tmp2 = slot * 6; *(u8 *)(i + (tmp2 + obj) + 0xc8) = 1; }
            }
            *(u32 *)(*(char * *)&((struct Obj00324 *)p)->f0 + slot * 4 + 0xe0) = _u32_div_f(total * 100, maximum);
        }
    }
}















int func_021BA534(void ***p)
{
    int v = (int)func_021B86B8(p);
    switch (v) {
    case 2:
    case 3: return 1;
    default: return 0;
    }
}
















int func_021BA54C(char *p)
{
    int v;

    if ((int)func_021B86B8((void ***)p) == 4) {
        v = 1;
    } else if (((struct F *)(p + 0x473))->b) {
        v = 6;
    } else if (((struct Obj21014 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f90 != 6) {
        v = 5;
    } else if (func_021D826C((u32 *)(p + 0x448))) {
        v = func_021D8270(p + 0x448, *(u8 *)&((struct Obj00324 *)p)->f46C, (unsigned int)func_021B86B8((void ***)p));
    } else {
        if (((struct Obj00324 *)p)->f444 == 7) {
            ((struct Obj00324 *)p)->f444 = 1;
        }
        v = ((struct Obj00324 *)p)->f444;
    }
    ((struct Obj21015 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f8C = v;
    return v;
}
















u16 func_021BA5C4(u8 *p)
{
    return ((struct Obj18159 *)p)->f442;
}















/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0x11; lsls r1, r1, #6; ldrh r0, [r0, r1]; bx lr.
 */
u16 func_021BA5D0(struct Q3 *p) { return p->v; }
















int func_021BA5D8(char *p)
{
    int *q = *(int * *)&((struct Obj07748 *)p)->f0;
    if (((struct Obj21016 *)q)->f23 == 0) {
        if (((struct Obj07748 *)p)->f440 != 0)
            return func_021CDDA0((u8 *)(*(int *)(p + (((struct Obj07748 *)p)->f46C << 2) + 0x10)));
        return 0;
    }
    return func_021CDDA0((u8 *)(*(int *)(p + (((struct Obj07748 *)p)->f46C << 2) + 0x10)));
}















int func_021BA618(char *p)
{
    int v;
    if (((struct Obj21017 *)(*(char * *)&((struct Obj09944 *)p)->f0))->f23) {
        v = func_021CDDCC(*(void **)(p + 0x10 + ((struct Obj09944 *)p)->f46C * 4));
        if (v) ((struct Obj09944 *)p)->f444 = 2;
        return v;
    }
    return 0;
}















void func_021BA648(char *p, u8 k, void *dst)
{
 int i;
 void *q;
 i = func_021BA710(((struct Obj13286 *)p)->f46C, k);
 q = *(void **)(*(char * *)&((struct Obj13286 *)p)->f0 + i * 4 + 0x24);
 if (q != 0) func_0201AC2C(dst, q);
}















void func_021BA670(char *p, u8 k, void *dst)
{
 int i;
 void *q;
 i = func_021BA710(((struct Obj13287 *)p)->f46C, k);
 q = *(void **)(*(char * *)&((struct Obj13287 *)p)->f0 + i * 4 + 0x34);
 if (q != 0) func_02008494((void *)dst, q);
}















void func_021BA698(u8 *p, int k)
{
 int i;
 i = func_021BA710(p[0x46c], k);
 *((u8 *)(*(char * *)&((struct Obj07743 *)p)->f0 + i) + 0x44) = func_021B997C(p, k);
}
















void func_021BA6C0(char *p)
{
    int n;
    void *src;

    if (func_021B90F8((u8 *)p)) {
        src = func_021CD924(*(void **)(p + (u8)p[0x46c] * 4 + 0x10), (u32 *)(&n));
        if (src) {
            func_02082D44(src, ((struct Obj21018 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f94, n);
            ((struct Obj21019 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f98 = n;
            *(struct T *)(*(char * *)&((struct Obj00324 *)p)->f0 + 0x9c) = *(struct T *)(p + 0x3f0);
        }
    }
}















u8 func_021BA710(int a, int b)
{
 u8 x;
 u8 y;
 if (a == b) return 0;
 x = a & 1;
 y = b & 1;
 if (x == y) return 2;
 return b <= 1U ? 1 : 3;
}
















/*
 * func_021CD95C takes two arguments (its own file: `p->v = v`), and the
 * value passed second is the func_021E8F20 result just stored at p + 4:
 * that is the `adds r1, r0, #0` the one-argument prototype could not
 * produce (twin: ov093_func_021B835C).
 */
void func_021BA73C(char *p, int x)
{
    unsigned int i;
    int t;

    t = func_021B6818((unsigned int *)(*(int * *)&((struct Obj02131 *)p)->f0));
    func_021D787C(p + 0x3f0);
    func_021B68D8((u8 *)p, ((struct Obj02131 *)p)->f0);
    func_021B9424(p + 0xc8);
    func_021B9424(p + 0x1b0);
    for (i = 0; i < 4; i++) {
        if (func_021B8B9C((unsigned char *)p, (u8)i)) {
            func_021B9460(p + 0x1b0, p, i);
            func_021B9460(p + 0xc8, p, i);
            func_021CD984(*(void **)(p + i * 4 + 0x10), x);
        }
    }
    func_021E9034((char *)(((struct Obj02131 *)p)->f4));
    func_021E8E28((void *)0x13);
    ((struct Obj02131 *)p)->f4 = (int)func_021E8F20(p, *(void **)(p + (((struct Obj21020 *)(*(char * *)&((struct Obj02131 *)p)->f0))->f21) * 4 + 0x10), (u32)(p + 0xc8), t, 0x13);
    func_021CD95C(*(void **)(p + (((struct Obj21021 *)(*(char * *)&((struct Obj02131 *)p)->f0))->f21) * 4 + 0x10), ((struct Obj02131 *)p)->f4);
    func_021BAB40((char *)(((struct Obj02131 *)p)->f8));
}















void func_021BA7F8(char *p)
{
 unsigned int i;
 for (i = 0; i < 4; i++) {
  if (func_021B8B9C((unsigned char *)p, (u8)i)) func_021CD9B0(*(void **)(p + i * 4 + 0x10));
 }
}
















u32 func_021BA820(int *p)
{
    return func_021BB964((struct Q5 *)p[2]);
}
















void func_021BA82C(char *p)
{
    p[0xb6] = 0;
    p[0xb7] = 0;
    p[0xb8] = 0;
    p[0xb9] = 0;
    p[0xba] = 0;
    p[0xbb] = 0;
    p[0xbc] = 0;
    p[0xbd] = 0;
    p[0xbe] = 0;
    p[0xbf] = 0;
    p[0xc0] = 0;
    ((struct Obj02132 *)p)->fB4 = 0;
}
















void func_021BA878(u8 *p)
{
    u8 *q;
    u8 *a;
    char *list;
    u32 n;
    u32 count;
    u32 i;
    void *item;
    if (((struct Obj09945 *)p)->f8 == 0)
        return;
    a = (u8 *)func_021BB964(((struct Obj09945 *)p)->f8);
    q = *(u8 * *)&((struct Obj09945 *)p)->f0;
    q[0xb6] = func_021C8138((struct Q7 *)a);
    q[0xb7] = func_021C8140((char *)a, 0);
    q[0xb8] = func_021C7CBC(a);
    q[0xb9] = func_021C7CC8(a);
    q[0xba] = func_021C7CD4((struct Q6 *)a);
    q[0xbb] = func_021C7CDC(a);
    q[0xbc] = func_021C7CE8(a);
    if (((struct Obj01687 *)q)->f8C == 1)
        q[0xbd] = 1;
    list = func_021B9AEC((char *)p + 0x1b0, 0);
    n = func_021B9B94((struct Q1 *)list);
    count = func_021B9B98((u8 *)list);
    for (i = 0; i < n; i++) {
        item = (void *)func_021B9BF0((struct S2 *)((struct S2 *)list), (u8)i);
        q[0xc0] += func_021D54B4(item);
        ((struct Obj01687 *)q)->fB4 += (u16)func_021D59B4(item, 13);
    }
    q[0xbf] = n - count;
    list = func_021B9AEC((char *)p + 0x1b0, 1);
    n = func_021B9B94((struct Q1 *)list);
    count = func_021B9B98((u8 *)list);
    q[0xbe] = n - count;
    if (func_021B8B9C(p, 3)) {
        list = func_021B9AEC((char *)p + 0x1b0, 3);
        if (list) {
            n = func_021B9B94((struct Q1 *)list);
            count = func_021B9B98((u8 *)list);
            q[0xbe] += (u8)(n - count);
        }
    }
}
















u8 *func_021BA9C8(void *a, struct Copy24 *b, void *c, int d, u16 heap)
{
    u8 *p;
    int i;
    p = func_02030734(heap, 0xcc4, 1, (const char *)d_021F3A60, 0xad);
    ((struct Obj01234 *)p)->fC = a;
    ((struct Obj01234 *)p)->f10 = c;
    ((struct Obj01234 *)p)->fCC0 = heap;
    ((struct Obj01234 *)p)->fCB0 = p + 0xf0;
    p[0xed] = 0;
    *(int *)&((struct Obj01234 *)p)->f44 = 0;
    p[0xcba] = 0;
    p[0xcbf] = 0;
    ((struct Obj01234 *)p)->f4C = d;
    *(struct Copy24 *)(p + 0x50) = *b;
    ((struct Obj01234 *)p)->fAC = (int)func_020457B0((int)0x20, (int)heap);
    func_021D787C(b);
    for (i = 0; i < 4; i++)
        func_021BB828(p + 0x14 + i * 12);
    ((struct Obj01234 *)p)->f44 = func_021BB968(p, ((struct Obj01234 *)p)->fC, ((struct Obj01234 *)p)->f10, p + 0xf0, ((struct Obj01234 *)p)->f4C, ((struct Obj01234 *)p)->fCC0);
    ((struct Obj01234 *)p)->fB0 = func_021BC550(((struct Obj01234 *)p)->f44);
    func_021BABEC((int *)p, (void *)func_021BAC04);
    return p;
}















void func_021BAA94(char *p, int b, u8 c, u8 d)
{
 char *x;
 unsigned int q;
 unsigned int off;
 x = func_021B9AEC(*(char * *)&((struct Obj21023 *)p)->f10, c);
 q = (unsigned int)p + 0x14U;
 off = (unsigned int)c * 12U;
 func_021BB840((struct Q4 *)(q + off), c, b, 1);
 func_021BB848((u8 *)(q + off), x, d);
}
















void func_021BAACC(char *p, int a, int b, int c, u8 d)
{
    char *x;
    int y;
    char *q;
    int off;

    x = func_021B9AEC(*(char * *)&((struct Obj13288 *)p)->f10, c);
    y = func_021EEA58(b, c, 1, ((struct Obj13288 *)p)->fCC0);
    q = p + 0x14;
    off = c * 12;
    func_021BB840((struct Q4 *)(q + off), c, y, 0);
    func_021BB848((u8 *)(q + off), x, d);
}















void func_021BAB10(char *p, u8 c, u8 d)
{
 char *x;
 unsigned int q;
 unsigned int off;
 x = func_021B9AEC(*(char * *)&((struct Obj21024 *)p)->f10, c);
 q = (unsigned int)p + 0x14U;
 off = (unsigned int)c * 12U;
 func_021BB840((struct Q4 *)(q + off), c, 0, 0);
 func_021BB848((u8 *)(q + off), x, d);
}















void func_021BAB40(char *p)
{
 func_021BABEC((int *)p, (void *)func_021BAC04);
 func_021BB7FC((const u8 *)p);
 func_021BB9D0(((struct Obj21025 *)p)->f44);
}
















void func_021BAB5C(int a)
{
    int i;
    char *p = (char *)a;
    func_02045808((struct U16Vec *)(((struct Obj13289 *)p)->fAC));
    func_021BBB48((u8 *)(((struct Obj13289 *)p)->f44));
    for (i = 0; i < 4; i++) {
        unsigned char *e = (unsigned char *)p + i * 0xc;
        if (e[0x1f] != 0xff && ((struct Obj07749 *)e)->f14 != 0 && e[0x1e] == 0)
            func_021EEAE0((void *)(((struct Obj07749 *)e)->f14));
    }
    func_020307B0((void *)a);
}
















int func_021BAB9C(int a)
{
    char *p = (char *)a;
    if (((struct Obj07750 *)p)->fED != 2) {
        int (*fp)(int, int) = *(int (**)(int, int))p;
        if (fp(a, a + 4) != 0) {
            func_021BB724((u8 *)a, 9, ((struct Obj07750 *)p)->fB0, 8);
            ((struct Obj07750 *)p)->fED = 2;
        }
    } else {
        if (func_021BB798((unsigned char *)p) != 0)
            return 1;
    }
    return 0;
}















void func_021BABDC(char *p, Pair_td *out)
{
 *out = **(Pair_td * *)&((struct Obj21026 *)p)->fB0;
}















void func_021BABEC(int *p, void *f)
{
 p[0] = (int)f;
 p[1] = 0;
}
















void func_021BABF4(void *p)
{
    func_021BABEC(p, (void *)func_021BACAC);
}















int func_021BAC04(char *p, int *st)
{
    int *q;

    switch (*st) {
    case 0:
        func_021BB718((int)p, 1);
        (*st)++;
    case 1:
        if (func_021BB798((unsigned char *)p)) {
            func_021BB7D0((const unsigned char *)p);
            if (func_021B86B8(*(void *** *)&((struct Obj09946 *)p)->fC) != (void *)4) {
                func_021BB5FC((unsigned char *)p, func_021BBB60((Server *)((struct Obj09946 *)p)->f44));
                (*st)++;
            } else {
                func_021BABEC((int *)p, (void *)func_021BB280);
            }
        }
        break;
    case 2:
        if (func_021BB798((unsigned char *)p)) {
            func_021BB7D0((const unsigned char *)p);
            (*st)++;
        }
        break;
    case 3:
        q = *(int * *)&((struct Obj09946 *)p)->fCB0;
        func_021BB724((unsigned char *)p, 8, (int)(q + 2), *q);
        (*st)++;
        break;
    case 4:
        if (func_021BB798((unsigned char *)p)) {
            func_021BB7D0((const unsigned char *)p);
            func_021BABF4(p);
        }
        break;
    }
    return 0;
}















/*
 * Contains the lead callback and its trailing return-one stub.
 * The fifth pool word is func_021BB0E0, the distinct case-1 callback;
 * reusing func_021BAEF8 there shortens the pool and cross-jumps the calls.
 */
int func_021BACAC(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        if (func_021BC390(((struct Obj01372 *)p)->f44)) {
            int *q = *(int * *)&((struct Obj01372 *)p)->fCB0;
            func_021BB724(p, 8, (int)(q + 2), *q);
            (*s)++;
        } else
            *s += 2;
        break;
    case 1:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 2:
        func_021BB718((int)p, 3);
        (*s)++;
        break;
    case 3:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            if (func_021BA5D8(*(char * *)&((struct Obj01372 *)p)->fC)) {
                func_021BABEC((int *)p, (void *)func_021BB208);
                break;
            }
            if (func_021BA618((char *)(*(u8 * *)&((struct Obj01372 *)p)->fC))) {
                func_021BABEC((int *)p, (void *)func_021BB280);
                break;
            }
            func_021BB6A8((P *)p);
            if (func_021BB628(p, 1, func_021BAE5C(p)))
                (*s)++;
            else
                *s += 2;
        }
        break;
    case 4:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 5:
        func_021BBC34(*(u8 * *)&((struct Obj01372 *)p)->f44);
        func_021BB7D0(p);
        (*s)++;
    case 6:
        ((struct Obj01372 *)p)->f48 = func_021BBC44(((struct Obj01372 *)p)->f44, (int)(p + 0xb4));
        if (func_021B86C0(((struct Obj01372 *)p)->fC))
            func_021BB56C(p + 0xb4);
        {
            int *q = *(int * *)&((struct Obj01372 *)p)->fCB0;
            func_021BB724(p, 8, (int)(q + 2), *q);
        }
        (*s)++;
        break;
    case 7:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            switch (((struct Obj01372 *)p)->f48) {
            case 0:
                func_021BABF4(p);
                break;
            case 3:
                *s = 6;
                break;
            case 2:
                {
                    void *a = func_021B86B8(*(void *** *)&((struct Obj01372 *)p)->fC);
                    u32 b = func_021B8588(((struct Obj01372 *)p)->fC);
                    if (!a && !b)
                        func_021BABEC((int *)p, (void *)func_021BAE60);
                    else
                        func_021BABEC((int *)p, (void *)func_021BAEF8);
                }
                break;
            case 1:
                func_021BABEC((int *)p, (void *)func_021BB0E0);
                break;
            case 6:
                func_021B9120(((struct Obj01372 *)p)->fC, func_021BC55C(((struct Obj01372 *)p)->f44));
                func_021BABEC((int *)p, (void *)func_021BB280);
                return 0;
            case 4:
                func_021B916C((u8 *)(*(int *)&((struct Obj01372 *)p)->fC), func_021C84D8((u8 *)(*(int *)&((struct Obj01372 *)p)->f44)));
                func_021BABEC((int *)p, (void *)func_021BB280);
                return 0;
            case 5:
            default:
                return 1;
            }
        }
        break;
    }
    return 0;
}















int func_021BAE5C(u8 *p)
{
    return 1;
}















int func_021BAE60(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB718((int)p, 7);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p) != 0) {
            u8 idx = func_021B8FF4(*(u8 * *)&((struct Obj06222 *)p)->fC);
            int *q;

            func_021BB7D0(p);
            if (*((u8 *)func_021EEB64((struct QW *)(*(u32 *)(p + 0x14 + idx * 12)), 0)) == 0) {
                func_021BABEC((int *)p, (void *)func_021BAEF8);
            } else {
                ((struct Obj06222 *)p)->f48 = func_021BC360((Server *)((struct Obj06222 *)p)->f44);
                q = *(int * *)&((struct Obj06222 *)p)->fCB0;
                func_021BB724(p, 8, (int)(q + 2), *q);
                (*s)++;
            }
        }
        break;
    case 2:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            if (((struct Obj06222 *)p)->f48 != 0)
                return 1;
            func_021BABEC((int *)p, (void *)func_021BAEF8);
        }
        break;
    }
    return 0;
}















/*
 * Case 4 falls through into case 5; the two entry points prevent the
 * field-address setup from moving above the state increment.
 */
int func_021BAEF8(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB724(p, 5, (int)(p + 0xcb4), p[0xcba]);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p)) {
            if (func_021BB040(p)) {
                p[0xec] = func_021BB0A0(p);
                func_021BB768(p, 4, 0, (int)(p + 0xec), 1);
            }
            (*s)++;
        }
        break;
    case 2:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            if (func_021BA618((char *)(*(u8 * *)&((struct Obj01235 *)p)->fC))) {
                func_021BABEC((int *)p, (void *)func_021BB280);
                break;
            }
            func_021BB6A8((P *)p);
            if (func_021BB628(p, 2, 0))
                (*s)++;
            else
                *s += 2;
        }
        break;
    case 3:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 4:
        func_021BB7D0(p);
        func_021BBD80(*(u8 * *)&((struct Obj01235 *)p)->f44);
        (*s)++;
    case 5:
        ((struct Obj01235 *)p)->f48 = func_021BBD8C(((struct Obj01235 *)p)->f44, (int)(p + 0xb4));
        {
            int *q = *(int * *)&((struct Obj01235 *)p)->fCB0;
            func_021BB724(p, 8, (int)(q + 2), *q);
        }
        (*s)++;
        break;
    case 6:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            switch (((struct Obj01235 *)p)->f48) {
            case 2:
                *s = 0;
                break;
            case 3:
                *s = 5;
                break;
            case 4:
                func_021B916C((u8 *)(*(int *)&((struct Obj01235 *)p)->fC), func_021C84D8((u8 *)(*(int *)&((struct Obj01235 *)p)->f44)));
                func_021BABEC((int *)p, (void *)func_021BB280);
                break;
            case 5:
                return 1;
            default:
                func_021BABF4(p);
                break;
            }
        }
        break;
    }
    return 0;
}















int func_021BB040(u8 *p)
{
    unsigned i;

    if (func_021B85A8(*(u8 * *)&((struct Obj01235 *)p)->fC) != 0 && p[0xcba] != 0) {
        for (i = 0; i < p[0xcba]; i++) {
            if (func_021B8DE4((char *)(*(u8 * *)&((struct Obj01235 *)p)->fC), p[0xcb4 + i]) == 0)
                return 0;
        }
        if (func_021B9B98((u8 *)func_021B9AEC(*(char * *)&((struct Obj01235 *)p)->f10, func_021B8FF4(*(u8 * *)&((struct Obj01235 *)p)->fC))) < 2)
            return 0;
        return 1;
    }
    return 0;
}















u32 func_021BB0A0(u8 *p)
{
    u8 *q = p + 0x20;
    B_021B9EF0_td *b;

    if (func_021BB830(q) != 0) {
        b = (B_021B9EF0_td *)func_021EEB64((struct QW *)(((struct Obj21032 *)q)->f0), 0);
        if (func_021D8454((Action *)b) == 3) {
            u8 *r = func_021B9920(((struct Obj21031 *)p)->f10, 1, b->f);
            return func_021D5440(r);
        }
    }
    return 0x1f;
}














int func_021BB0E0(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB724(p, 6, (int)(p + 0xcb4), p[0xcba]);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            if (func_021BA618(((struct Obj02775 *)p)->fC)) {
                func_021BABEC((int *)p, (void *)func_021BB280);
            } else {
                func_021BB6A8((P *)p);
                if (func_021BB628(p, 3, 0)) (*s)++;
                else *s += 2;
            }
        }
        break;
    case 2:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 3:
        func_021BB7D0(p);
        func_021BBD20(((struct Obj02775 *)p)->f44);
        (*s)++;
    case 4: {
        int *q;
        q = *(int * *)&((struct Obj02775 *)p)->fCB0;
        q[0] = 0;
        q[1] = 0;
        ((struct Obj02775 *)p)->f48 = func_021BBD2C(((struct Obj02775 *)p)->f44, (int)(p + 0xb4));
        q = *(int * *)&((struct Obj02775 *)p)->fCB0;
        func_021BB724(p, 8, (int)(q + 2), q[0]);
        (*s)++;
        break;
    }
    case 5:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            switch (((struct Obj02775 *)p)->f48) {
            case 1: *s = 0; break;
            case 3: *s = 4; break;
            case 2: func_021BABEC((int *)p, (void *)func_021BAEF8); break;
            case 4:
                func_021B916C((u8 *)(*(int *)&((struct Obj02775 *)p)->fC), func_021C84D8((u8 *)(*(int *)&((struct Obj02775 *)p)->f44)));
                func_021BABEC((int *)p, (void *)func_021BB280);
                break;
            case 5: return 1;
            case 0:
            default: func_021BABF4(p); break;
            }
        }
        break;
    }
    return 0;
}















int func_021BB208(u8 *p, int *s)
{
    int n;

    switch (*s) {
    case 0: {
        u8 *r = func_021EE9A4(p + 0x68, (unsigned int *)(&n));
        func_021BB724(p, 0xa, (int)r, n);
        (*s)++;
        break;
    }
    case 1:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            func_021BB718((int)p, 0x10);
            (*s)++;
        }
        break;
    case 2:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            func_021B916C((u8 *)(((struct Obj13292 *)p)->fC), func_021C84D8((u8 *)(((struct Obj13292 *)p)->f44)));
            func_021BABEC((int *)p, (void *)func_021BB280);
        }
        break;
    }
    return 0;
}















int func_021BB280(u8 *p)
{
    int r5 = func_021B917C((char *)(*(u8 * *)&((struct Obj05188 *)p)->fC));

    ((struct Obj05188 *)p)->fAA = r5;
    ((struct Obj05188 *)p)->fA8 = func_021B8FF4(*(u8 * *)&((struct Obj05188 *)p)->fC);

    switch ((int)func_021B86B8(*(void *** *)&((struct Obj05188 *)p)->fC)) {
    case 1:
        func_021BABEC((int *)p, (void *)func_021BB43C);
        break;
    case 2:
        func_021BABEC((int *)p, (void *)func_021BB484);
        break;
    case 3:
        func_021BABEC((int *)p, (void *)func_021BB3F8);
        break;
    case 0:
        if (r5 == 1) {
            func_021BABEC((int *)p, (void *)func_021BB368);
        } else if (r5 == 0 || r5 == 2) {
            func_021BABEC((int *)p, (void *)func_021BB3B0);
        } else {
            func_021BABEC((int *)p, (void *)func_021BB320);
        }
        break;
    default:
        if (r5 == 1) {
            func_02005D90(func_021B86DC(*(void ** *)&((struct Obj05188 *)p)->fC), 0xffff);
        }
        func_021BABEC((int *)p, (void *)func_021BB320);
        break;
    }
    return 0;
}















int func_021BB320(u8 *p, int *s)
{
    switch (*s) {
    case 0: {
        int r = 0;
        if (func_021B9114(*(u8 ** *)&((struct Obj21033 *)p)->fC) == 0) {
            if ((func_020362DC() & 3) != 0 || func_02035C60() != 0) r = 1;
        } else {
            r = 1;
        }
        if (r != 0) {
            (*s)++;
            return 1;
        }
        break;
    }
    case 1:
        return 1;
    }
    return 0;
}















int func_021BB368(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB724(p, 0xe, (int)(p + 0xa8), 4);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 2:
        func_021BABEC((int *)p, (void *)func_021BB320);
        break;
    }
    return 0;
}















int func_021BB3B0(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB724(p, 0xf, (int)(p + 0xa8), 4);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 2:
        func_021BABEC((int *)p, (void *)func_021BB320);
        break;
    }
    return 0;
}















int func_021BB3F8(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB724(p, 0xd, (int)(p + 0xa8), 4);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}















int func_021BB43C(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB724(p, 0xb, (int)(p + 0xa8), 4);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 2:
        func_021BABEC((int *)p, (void *)func_021BB320);
        break;
    }
    return 0;
}















int func_021BB484(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB724(p, 0xc, (int)(p + 0xa8), 4);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 2:
        if (func_021B86C0(*(u8 ** *)&((struct Obj21034 *)p)->fC) == 0) {
            func_021BABEC((int *)p, (void *)func_021BB320);
        } else {
            return 1;
        }
        break;
    }
    return 0;
}














void func_021BB4E0(Obj_td *p, void *src, u8 n)
{
    u8 i;
    u8 type;
    u8 count;
    int idx;
    u32 buf[3];

    idx = 0;
    for (i = 0; i < 4; i++)
        p->cnt[i] = 0;
    func_021EE9B4(p->rd, src, n);
    while (func_021EE9E4(p->rd, (u32 *)(&idx), &type, &count, buf) != 0) {
        for (i = 0; i < count; i++)
            p->tab[type][i] = buf[i];
        p->cnt[type] = count;
    }
}













void func_021BB56C(void *p)
{
}














int func_021BB570(u8 *p, int sel, void *data, u32 n)
{
    u32 *s = *(u32 * *)&((struct Obj03190 *)p)->fCB0;

    s[0] = 0;
    s[1] = 0;
    switch (sel) {
    case 4:
        func_021BBB60(((struct Obj03190 *)p)->f44);
        break;
    case 1:
        func_021BBC34(*(u8 * *)&((struct Obj03190 *)p)->f44);
        func_021BBC44(((struct Obj03190 *)p)->f44, (int)(p + 0xb4));
        break;
    case 2:
        func_021BBD80(*(u8 * *)&((struct Obj03190 *)p)->f44);
        func_021BBD8C(((struct Obj03190 *)p)->f44, (int)((void *)((int)(p + 0xb4))));
        break;
    case 3:
        func_021BBD20(*(u8 * *)&((struct Obj03190 *)p)->f44);
        func_021BBD2C(((struct Obj03190 *)p)->f44, (int)(p + 0xb4));
        break;
    }
    s = *(u32 * *)&((struct Obj03190 *)p)->fCB0;
    if (s[0] == n && func_0203EFC8((const u8 *)(s + 2), data, n) == 0)
        return 0;
    return 1;
}













int func_021BB5FC(u8 *p, int b)
{
 int n;
 int r;
 func_021EE8B4(p + 0x68, 1);
 r = (int)func_021EE8D8(p + 0x68, (u32 *)(&n), b);
 func_021BB724(p, 10, r, n);
 return 1;
}













/*
 * interface: func_021BB650's matched source declares void and an integer
 * fourth payload. Its original forwards that full word into EE96C r2;
 * EE96C stores the output count through r2 only on its nonzero return path
 * (021EE998), returns base+4 or zero, and BB650 leaves that r0 live.
 * This caller passes &n in r3 and reads r0, so its extern preserves both.
 */
int func_021BB628(u8 *p, int a, int b)
{
 int n;
 int r;
 r = func_021BB650(p, a, b, (int)(&n));
 if (r != 0) {
  func_021BB724(p, 10, r, n);
  return 1;
 }
 return 0;
}














int func_021BB650(u8 *p, int a, int b, int c)
{
    u32 i;
    u32 v;

    func_021EE8B4(p + 0x68, b);
    for (i = 0; i < 4; i++) {
        if (p[i * 12 + 0x1f] != 0xff) {
            u32 r = func_021EEB64((struct QW *)(*(u32 *)(p + i * 12 + 0x14)), &v);

            func_021EE8F4(p + 0x68, i, (const void *)r, (v << 22) >> 24);
        }
    }
    return func_021EE96C(p + 0x68, a, c);
}














/*
 * note 2026-10-05 (final push G6L5): closed by copying each word through a one-word struct
 *   (`typedef struct { u32 w; } W;`, source cursor `W *s`, destination element type W, so
 *   `p->d[i].v[j] = *s++;` is a struct assignment). The word-copy path creates the load before
 *   the destination address, which gives the walking source in r2 with j in r0, cnt in r1 and
 *   the load in r6. Plain `u32 *s` with `*s++` (every spelling) gave j=r1, cnt=r2, s=r3, load r0
 *   (51 bytes); indexed `s[j]` gave `ldr r6,[r2,r4]` (1 byte). Same shape in both lang c99 and c.
 */
void func_021BB6A8(P *p)
{
    u32 i;
    u32 j;
    u32 n;
    u32 cnt;
    W *s;
    EntP *e;

    for (i = 0; i < 4; i++) {
        e = &p->e[i];
        p->c[i] = 0;
        if (func_021BB830((u8 *)e) != 0) {
            s = (W *)func_021EEB64((void *)e->h, &n);
            cnt = n >> 2;
            for (j = 0; j < cnt; j++) {
                p->d[i].v[j] = *s++;
                p->c[i]++;
            }
        }
    }
}














void func_021BB718(int a, int b)
{
    func_021BB724((u8 *)a, b, 0, 0);
}














void func_021BB724(u8 *p, int a, int b, int c)
{
    int i;
    u8 *q;

    func_021EEAE8();
    i = 0;
    q = p + 0x14;
    for (; i < 4; i++) {
        if (func_021BB830(q + i * 12) != 0)
            func_021EEB00(*(u32 *)(p + 0x14 + i * 12), a, b, c);
    }
    func_021EEAFC();
}













void func_021BB768(u8 *p, int a, u32 i, int b, int c) {
    u8 *q;
    q = (u8 *)((u32)p + 20);
    if (func_021BB830((u8 *)((u32)q+i*12))) {
        func_021EEB70(*(u32 *)((u32)q+i*12));
        func_021EEB00(*(u32 *)((u32)q+i*12),a,b,c);
    }
}













int func_021BB798(u8 *p) {
    int result;
    int i;
    u8 *q;
    result = 1; i = 0; q = p+20;
    for (; i < 4; i++) {
        if (func_021BB830(q+i*12)) {
            if (!func_021EEB2C(*(u32 *)((p+i*12)+20))) result = 0;
        }
    }
    return result;
}













void func_021BB7D0(const u8 *p) {
    int i;
    i = 0;
    for (; i < 4; i++) {
        if (func_021BB830((u8 *)(p+20+i*12))) func_021EEB70(*(const u32 *)((p+i*12)+20));
    }
}













void func_021BB7FC(const u8 *p) {
    int i;
    i = 0;
    for (; i < 4; i++) {
        if (func_021BB830((u8 *)(p+20+i*12))) func_021EEAD0((u8 *)(*(const u32 *)((p+i*12)+20)));
    }
}














/*
 * store constant 0xff at #0xb
 */
void func_021BB828(u8 *p)
{
    *(u8 *)&p[0xb] = 0xff;
}













int func_021BB830(u8 *p) { if (p[11] != 255) return 1; return 0; }












void func_021BB840(struct Q4 *p, int a, int b, int c)
{
    p->b = a;
    p->w = b;
    p->c = c;
}












void func_021BB848(u8 *p, void *q, u8 v) { ((struct Obj09956 *)p)->f4 = q; p[8] = func_021B9B94(q); p[9] = v; }












u8 *func_021BB85C(u8 *p, unsigned int i) { if (i < 4 && (p+i*12)[31] != 255) return p+20+i*12; return 0; }












u8 *func_021BB878(u8 *p, u32 i) { if (((u8 *)((u32)p+i*12))[31] != 255) return (u8 *)((u32)p+20+i*12); return 0; }












int func_021BB890(u8 *p, u8 i) { if (i < 4) return func_021BB830(p+20+i*12); return 0; }













/* 021BB8A8  adds r0,r0,r1; adds r0,#0x30; ldrb r0,[r0] */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: adds r0, r0, r1; adds r0, #0x30; ldrb r0, [r0]; bx lr.
 */
u8 func_021BB8A8(u8 *p, u8 i) { return *(u8 *)(p + i + 0x30); }













/* 021BB8B0  movs r3,#0xc; muls r3,r1,r3; lsls r1,r2,#2; adds r0,r0,r3;
 *           ldr r0,[r1,r0] */
/*
 * Leaf with no calls and no pool; 6 instructions, 12 bytes: movs r3, #0xc; muls r3, r1, r3; lsls r1, r2, #2; adds r0, r0, r3; ldr r0, [r1, r0]; bx lr.
 */
Action func_021BB8B0(u8 *p, u8 i, u8 j)
{
    return *(Action *)(p + i * 12 + j * 4);
}












void func_021BB8BC(u8 *p, u32 *q) {
    func_02017E1C(func_021D5844(q),0x73,((struct Obj13294 *)p)->fAC);
    func_02027268(((struct Obj13294 *)p)->fAC);
}












/*
 * evidence: caller narrows func_02017E1C result to u16 before 020271DC.
 */
void func_021BB8DC(u8 *p, u32 *q) {
    func_020271DC(func_02017E1C(func_021D5844(q),5,0));
    func_021BA1B4((char **)(*(u8 * *)&((struct Obj13295 *)p)->fC),7);
    func_021BA1B4((char **)(*(u8 * *)&((struct Obj13295 *)p)->fC),0x54);
}













void func_021BB908(int *p, int add)
{
    func_021B91E4((void *)p[3], add);
}













/*
 * overlays, with no outside branch; the pool relocation has no witness.
 * All bytes correct.
 *
 * UNBLOCKED: func_021B9234 is now an EXACT entry in layout/matched/ov093;
 * the call site resolves as matched, verdict promoted to EXACT.
 */
void func_021BB914(int *p)
{
    func_021B9234((unsigned char *)p[3]);
}












void func_021BB920(u8 *p) { p[0xcba] = 0; p[0xcbf] = 0; }












/*
 * Lever: left-associated pointer addition p + count + 0xcb4 preserves
 * the base-plus-count computation before the incrementing byte store.
 */
void func_021BB930(u8 *p, u32 value)
{
    u32 i;
    u32 count = p[0xcba];
    for (i = 0; i < count; i++) {
        if (value == p[0xcb4 + i]) return;
    }
    p[0xcba]++;
    *(p + count + 0xcb4) = value;
}












u32 func_021BB964(struct Q5 *p) { return p->v; }













Server *func_021BB968(void *a, void *b, void *c, void *d, int e, u16 heap)
{
    Server *p;
    p = func_02030734(heap, 0x212c, 1, (const char *)d_021F3A70, 0x245);
    p->f0 = a;
    p->f8 = c;
    p->f4 = b;
    p->n = 0;
    p->f10 = 0;
    p->f14 = 0;
    p->fC = d;
    p->f780 = heap;
    p->f18 = e;
    p->f4a4 = func_0201B70C(heap);
    func_021BB9D8(p);
    return p;
}











void func_021BB9D0(Server *p)
{
    func_021BB9D8(p);
}









/*
 * Lever: the four flag clears are typed bitfield assignments, emitting bics.
 * func_021C5474 leaves its input in r0 for the following func_021BBB38.
 */
void func_021BB9D8(Server *p)
{
    func_021D6EAC();
    func_021EF874(0);
    func_021BBB08(p->w1c);
    func_021BBB18(p->g3e0);
    func_021BBB28(p->w1ab8, p->f4, p->f8, func_021B8588(p->f4));
    func_02082BCC(p->w7a9, 0, 0x18);
    func_02082BCC(p->flags, 0, 0x18);
    func_02082BCC(p->w7d9, 0, 4);
    func_02082BCC(p->w4d4, 0, 0x2a0);
    func_021C7C18(p->w1f7c);
    func_021C8588(p);
    func_021D8230(p->w4b8);
    func_021CC8C8(&p->lock);
    func_021BBB38(func_021C5474((char *)p->w1b50));
    p->f786 = 0;
    p->f787 = 0;
    ((Flags_td *)&p->f78a)->a = 0;
    ((Flags_td *)&p->f78a)->b = 0;
    ((Flags_td *)&p->f78a)->c = 0;
    p->init = 0;
    p->f789 = 31;
    p->f1f74 = 0;
    p->f784 = 6;
    p->f774 = 0;
    p->f77e = 0;
    p->f778 = 0;
    ((Flags_td *)&p->f78a)->d = 0;
}








void func_021BBB48(u8 *p)
{
    func_02049238(((struct Obj21039 *)p)->f4A4);
    func_020307B0(p);
}









int func_021BBB60(Server *p)
{
    u8 *initial;
    u32 i;
    int result;
    void *m;
    u32 *out = p->fC;
    out[0] = 0;
    result = 0;
    out[1] = 0;
    initial = (u8 *)func_021B8714((char * *)(p->f4));
    if (initial[8] && func_021C3B68(p, initial[8], 255)) result = 1;
    for (i = 0; i < 4; i++) {
        u8 *q = func_021BB878(p->f0, (u8)i);
        if (q) {
            u32 j;
            for (j = 0; j < q[9]; j++) {
                m = (void *)func_021B9BF0(((struct Obj09958 *)q)->f4, (u8)j);
                if (m && !func_021D5B68(m)) func_021BD8F0(p, i, j, j);
            }
            if (func_021B8588(p->f4) == 3) {
                for (j = 0; j < 3; j++) {
                    m = (void *)func_021B9BF0(((struct Obj09958 *)q)->f4, (u8)j);
                    if (m && !func_021D5B68(m)) func_021B8750(p->f4, i, m);
                }
            }
        }
    }
    if (func_021BDA00(p)) result = 1;
    return result;
}










void func_021BBC34(u8 *p)
{
    p[0x77c] = 0;
    p[0x783] = 0;
}








int func_021BBC44(Server *p, int a)
{
    int *q;
    u32 i;

    p->f14 = 0;
    q = p->fC;
    q[0] = 0;
    q[1] = 0;
    if (p->init == 0) {
        func_021C84E8(p);
        func_021BBCC4(p->g3e0);
        for (i = 0; i < 4; i++)
            p->f1fe8[i] = 0;
        func_021D6EE8();
        func_021BB920((u8 *)(p->f0));
        func_021D74E4();
        func_021BBCD4(p);
        p->n = func_021BC610(p, (u8 *)a, p->e, 6);
        p->init = 1;
    }
    p->k = func_021BBFA8(p, p->k);
    return p->f14;
}







void func_021BBCD4(Server *p)
{
    u32 it;
    u8 *x;
    u32 n;

    func_021BD2B4((u8 *)&it, (u8 **)p);
    if (func_021BD34C((u8 *)&it, (u8 **)p, &x) != 0) {
        n = 12;
        do {
            if (func_021D5BDC((struct UtilWork *)x, n) != 0)
                func_021C6110(p, x, n);
        } while (func_021BD34C((u8 *)&it, (u8 **)p, &x) != 0);
    }
}








void func_021BBD20(u8 *p)
{
    p[0x77c] = 0;
}








int func_021BBD2C(Server *p, int a)
{
    int *q;

    p->f14 = 0;
    q = p->fC;
    q[0] = 0;
    q[1] = 0;
    if (p->init == 0) {
        func_021BB920((u8 *)(p->f0));
        func_021D74E4();
        p->f77d = 0;
        p->init = 1;
        if (func_021BC220(p, (u8 *)a) != 0) {
            p->f14 = 3;
            return 3;
        }
    }
    p->k = func_021BBFA8(p, p->k);
    return p->f14;
}








void func_021BBD80(u8 *p)
{
    p[0x77c] = 0;
}








int func_021BBD8C(Server *p, int a)
{
    int *q;
    u32 i;
    int saved;
    int ret;

    p->f14 = 0;
    q = p->fC;
    q[0] = 0;
    q[1] = 0;
    if (p->init == 0) {
        func_021BB920(p->f0);
        func_021D74E4();
        saved = func_021BBF88(p->g3e0, 0);
        p->n = func_021BC610(p, (u8 *)a, p->e, 6);
        p->k = 0;
        for (i = 0; i < p->n; i++) {
            if (p->e[i].b.small.type == 3 && p->e[i].b.small.z == 0) {
                if (func_021D5B68((void *)p->e[i].a) == 0) {
                    func_021BDC98(p, (u8 *)p->e[i].a, p->e[i].b.small.move);
                    p->e[i].done = 1;
                }
            }
        }
        for (i = 0; i < p->n; i++) {
            if (p->e[i].b.small.type == 3 && p->e[i].b.small.z == 0) {
                if (func_021D5B68((void *)p->e[i].a) != 0) {
                    func_021BD9D4(p, p->e[i].d, p->e[i].b.small.select, p->e[i].b.small.move, 1);
                    p->e[i].done = 1;
                }
            }
        }
        if (func_021B8588(p->f4) == 3) {
            for (i = 0; i < p->n; i++) {
                if (p->e[i].b.small.type == 6 && p->e[i].b.small.z == 0)
                    func_021BCCE0(p, &p->e[i]);
            }
        }
        p->init = 1;
    }
    func_021BDA00(p);
    func_021C5200(p);
    func_021BC4DC(p, p->g4ce);
    ret = 0;
    if (saved == func_021BBF98(p->g3e0, 0)) {
        func_021C4614(p);
        return ret;
    }
    if (func_021BC2B0(p) == 0) {
        func_021C6158(p, p->g4ce);
        return 2;
    }
    return 4;
}




u32 func_021BBFA8(Server *p, u32 i)
{
    u32 previous = 0;
    for (; i < p->n; i++) {
        u32 current = func_021D8454(&p->e[i].b);
        u8 stop;
        if (previous == 6 && current != 6) {
            func_021BDC2C(p);
            func_021BC0E8(p, &p->e[i], p->n - i);
        }
        previous = func_021BCCE0(p, &p->e[i]);
        stop = func_021C5200(p);
        if ((u8)func_021BC2B0(p)) { p->f14 = 4; return i + 1; }
        if (p->f14 == 6) return i + 1;
        if (p->f14 == 1) return i + 1;
        if (stop) { p->f14 = 3; return i + 1; }
    }
    if (p->f14 == 0) {
        u8 stop = func_021C446C(p);
        int present;
        if ((u8)func_021BC2B0(p)) { p->f14 = 4; return p->n; }
        if (stop) { p->f14 = 3; return p->n; }
        present = func_021BC0D8((u8 *)p->g3e0, 0);
        if (func_021C8534(p) || present) {
            func_021BC4DC(p, (u8 *)p->g4ce);
            func_021C6158(p, (u8 *)p->g4ce);
            p->f14 = 2;
            return p->n;
        }
        p->f14 = 0;
    }
    return p->n;
}






static inline void set_accuracy(Entry *e, u16 v)
{
    e->c = (v & 0x1fff) | (e->c & 0xffffe000);
}






static inline u32 pack(u16 low, u8 a, u8 b, u8 c)
{
    return (low & 0x1fff) | (((u16)(a << 13)) | ((((u32)(u16)(c << 13) << 9)) | (((u32)b & 63) << 16)));
}






static inline void update(Entry *e, int result)
{
    u16 low = (u16)(e->c & 0x1fff);
    u8 a = (e->c >> 13) & 7;
    u8 c = (e->c >> 22) & 7;
    e->c = pack(low, a, result, c);
}






void func_021BC0E8(Server *p, Entry *e, u32 n)
{
    u32 i;
    u32 off;
    u32 type;
    u16 value;
    u32 lock;
    int result;
    Entry *q;
    for (i = 0; i < n; i++) {
        off = i * 16;
        q = &e[i];
        set_accuracy(q, func_021BC948(p, ENTRY(i)->a, 1));
        type = func_021D8454(&q->b);
        if (type == 1) {
            if (((Entry *)e)[i].b.full.type == 1) value = ((Entry *)e)[i].b.full.move; else value = 0;
            lock = func_021CC8D8(&p->lock, 1076);
            q = (Entry *)((u32)e + off);
            result = func_021BC8EC(p, value, q->a);
            update(q, result);
            func_021CC95C(&p->lock, lock, 1079);
        }
        if (type == 1 || type == 5) {
            lock = func_021CC8D8(&p->lock, 1087);
            q = (Entry *)((u32)e + off);
            q->c = ((func_021C6350(p, q->a) & 7) << 13) | (q->c & 0xffff1fff);
            func_021CC95C(&p->lock, lock, 1090);
        }
    }
    func_021BC874(e, n);
}








/*
 * func_021BB8B0 returns a 4-byte bitfield struct: declaring it that way
 * (a u32 return with shifts and masks gives a different frame) is what
 * matches.
 */
int func_021BC220(Server *p, u8 *o)
{
    u32 i;
    u32 j;
    u32 n;
    Action v;

    for (i = 0; i < 4; i++) {
        if (func_021BB85C((u8 *)((int)p->f0), (u8)i) != 0) {
            n = func_021BB8A8(o, i);
            for (j = 0; j < n; j++) {
                v = func_021BB8B0(o, i, j);
                if (v.small.type == 3 && v.small.z == 0)
                    func_021BD9D4(p, i, v.small.select, v.small.move, 1);
            }
        }
    }
    func_021BDA00(p);
    return func_021C5200(p);
}








int func_021BC2B0(Server *p)
{
    u8 f[2];
    u32 i;

    f[1] = 0;
    f[0] = f[1];
    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(p->f4, i) != 0) {
            char *q = func_021B9AEC(p->f8, i);
            u8 k = func_021B8BC4((int)(p->f4), (u8)i);

            if (func_021B9B98((u8 *)q) != 0)
                f[k] = 1;
        }
    }
    if (f[0] == 0 || f[1] == 0)
        return 1;
    return 0;
}







int func_021BC310(Server *p)
{
    u32 i;

    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(p->f4, i) != 0) {
            u8 a = func_021B8BC4((int)(p->f4), (u8)i);
            u8 b = func_021B8BC4((int)(p->f4), (u8)func_021B8FF4(p->f4));

            if (a == b) {
                if (func_021B9B98((u8 *)func_021B9AEC(p->f8, i)) != 0)
                    return 1;
            }
        }
    }
    return 0;
}






/*
 * extent: two zero alignment bytes at 0x021BC38E, then func_021BC390.
 * Lever: bind the first call result before initializing the boolean result.
 */
int func_021BC360(Server *p)
{
    u8 *a;
    u32 side;
    int result;
    u32 *out;
    side = func_021B8FF4(p->f4);
    result = 0;
    a = func_021B990C(p->f8, side, 0);
    out = p->fC;
    out[0] = 0;
    out[1] = 0;
    if (func_021BD584(p, a)) result = 1;
    return result;
}






/*
 * extent: two zero alignment bytes at 0x021BC3AE, then matched func_021BC3B0.
 */
int func_021BC390(Server *p)
{
    int result = 0;
    u32 *out = p->fC;
    out[0] = 0;
    out[1] = 0;
    func_021BC3B0(p);
    if (*(u32 *)p->fC) result = 1;
    return result;
}





void func_021BC3B0(Server *p)
{
    u32 i;
    u32 x;
    u32 v;

    if (p->f18 == 1) {
        for (i = 0; i < 4; i++) {
            if (func_021BB890(p->f0, i) != 0) {
                if (func_021B8588(p->f4) != 2)
                    v = 1;
                else
                    v = func_021BC408(p->w1ab8, i, &x) + 1;
                func_021CD4B0(p->fC, 0x29, (u8)i, (u8)v);
            }
        }
    }
}











void func_021BC418(Server *p, int a, u8 b)
{
    u8 *t;
    u8 *v1;
    u8 *v2;
    int k;

    if (b == 1)
        return;
    if (b == 0)
        return;
    t = (u8 *)func_021B9AEC((char *)(p->f8), a);
    func_021CD4B0(p->fC, 0x48, a, b);
    func_021B9C50((u8 **)t, b, &v1, &v2);
    if (func_021D5B68(v1) == 0)
        func_021C5108(p, v1, 1);
    if (func_021D5B68(v2) == 0) {
        if (func_021EF948(2) != 0) {
            k = 0x20;
            if (func_021D62C4((struct Unk021D62A8 *)v2, k) != 0)
                func_021C5620(p, v2, k, 0);
            k = 0x1e;
            if (func_021D62C4((struct Unk021D62A8 *)v2, k) != 0)
                func_021C5620(p, v2, k, 0);
        }
        func_021D8548(v2);
        func_021DCFB4(v2);
    }
    func_021BC4CC(p->w1ab8, b, a, v2, p->f8);
}











int func_021BC4DC(Server *p, u8 *out)
{
    u8 buf[4];
    u8 i;
    u8 n;
    u8 j;
    int ok = 0;
    *out = 0;
    for (i = 0; i < 4; i++) {
        n = func_021BC540(p->w1ab8, i, buf);
        if (n != 0) {
            for (j = 0; j < n; j++)
                func_021BB930(p->f0, buf[j]);
            ok = 1;
            out[(*out)++ + 1] = i;
        }
    }
    return ok;
}











u8 *func_021BC550(Server *p)
{
    return p->w4b8;
}











u8 func_021BC55C(Server *p)
{
    return p->f784;
}











void func_021BC568(Server *p)
{
    u32 lk = func_021CC8D8(&p->lock, 1425);
    u32 i;
    for (i = 0; i < p->n; i++) {
        u16 id;
        u8 *a;
        Entry *e;
        e = &p->e[i];
        if (e->b.full.type == 1)
            id = e->b.full.move;
        else
            id = 0;
        if (id != 0) {
            a = p->e[i].a;
            if (func_021E02DC(a, id, func_021D59B4(a, 12))) {
                func_021C6394(p, a, id);
                func_021E0394(a, id);
            }
        }
    }
    func_021CC95C(&p->lock, lk, 0x5a0);
}











u8 func_021BC610(Server *p, u8 *o, Entry *e, int unused)
{
    u8 cnt;
    u32 k;
    u8 *a;
    u32 lock;
    u8 i;
    u8 j;
    u8 n;
    u32 flag;
    u8 l;
    Q_td *q;
    Entry *r;

    flag = 0;
    for (i = 0, cnt = 0; i < 4; i++) {
        q = (Q_td *)func_021BB85C(p->f0, i);
        if (q != 0) {
            u8 r5;
            n = func_021BB8A8(o, i);
            r5 = 0;
            for (j = 0; j < n; j++) {
                u32 t;
                r = &e[cnt];
                r->b = func_021BB8B0(o, i, j);
                if (func_021D83E0(&r->b) != 0)
                    break;
                t = func_021D8454(&r->b) & 0xff;
                switch (t) {
                case 6:
                    r5 = func_021B9AB0(r->b.full.select);
                    r->a = (u8 *)func_021B9BF0(q->m, (u8)r5);
                    flag = 1;
                    break;
                case 3:
                    r->a = (u8 *)func_021B9BF0(q->m, (u8)r->b.full.select);
                    r5++;
                    break;
                default:
                    r->a = (u8 *)func_021B9BF0(q->m, (u8)r5);
                    r5++;
                    break;
                }
                r->d = i;
                r->done = 0;
                r->f = 0;
                cnt++;
            }
        }
    }
    for (l = 0; l < cnt; l++) {
        u32 m = 0x1FFF;
        u8 r5;
        u32 sub;
        lock = func_021CC8D8(&p->lock, 0x678 - 0x38);
        r = &e[l];
        a = e[l].a;
        switch (r->b.full.type) {
        case 4:
            if (func_021B86B8((void ***)p->f4) == 0 && r->d == 1) {
                r5 = 0;
            } else {
                r5 = 4;
            }
            break;
        case 3:
            r5 = 3;
            break;
        case 2:
            r5 = 2;
            break;
        case 6:
            r5 = 1;
            break;
        case 7:
            r5 = 0;
            break;
        case 5:
            r5 = 0;
            break;
        case 1:
            r5 = 0;
            break;
        case 0:
            r->c = 0x01002000;
            continue;
        case 8:
            continue;
        default:
            r5 = 0;
            break;
        }
        if (r->b.full.type == 1) {
            u16 id;
            if (((EntryAlt *)e)[l].b.full.type == 1)
                id = ((EntryAlt *)e)[l].b.full.move;
            else
                id = 0;
            sub = func_021BC8EC(p, id, a);
        } else if (r->b.full.type == 5 || r->b.full.type == 7) {
            sub = 7;
        } else {
            sub = 0;
        }
        k = func_021BC948(p, a, 1);
        func_021CC95C(&p->lock, lock, 0x678);
        r->c = (k & m) | ((m + 1) | (((r5 & 7) << 22) | ((sub & 0x3f) << 16)));
    }
    func_021BC874(e, cnt);
    if (flag == 0) {
        for (i = 0; i < cnt; i++) {
            r = &e[i];
            if (r->b.full.type == 1 || r->b.full.type == 5) {
                u32 lock = func_021CC8D8(&p->lock, 0x68A);
                u32 v = func_021C6350(p, r->a);
                r->c = (r->c & 0xFFFF1FFF) | ((v & 7) << 13);
                func_021CC95C(&p->lock, lock, 0x68A + 3);
            }
        }
        func_021BC874(e, cnt);
    }
    return cnt;
}











void func_021BC874(Entry *p, u32 n)
{
    u32 i;
    u32 j;
    Entry *a;
    Entry *b;
    Entry t;
    for (i = 0; i < n; i++) {
        j = i + 1;
        if (j < n) {
            a = &p[i];
            do {
                b = &p[j];
                if (a->c <= b->c && (a->c != b->c || func_021D78AC(2) != 0)) {
                    t = *a;
                    *a = *b;
                    *b = t;
                }
                j++;
            } while (j < n);
        }
    }
}











int func_021BC8EC(Server *p, u32 x, u8 *a)
{
    u8 n = func_0201BD28(x, 6) + 7;
    u8 r;
    func_021D74F8(1735);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, x);
    func_021D75A8(0x18, n);
    func_021D70F0(p, 0x11);
    r = func_021D775C(0x18);
    func_021D7540(1741);
    return r;
}











u16 func_021BC948(Server *p, u8 *x, int flag)
{
    u32 r;
    int k = func_021D59B4(x, 0xc);
    int one;
    func_021D74F8(1760);
    func_021D75EC(2, func_021D5440(x));
    func_021D75EC(0x2f, k);
    one = 1;
    func_021D75A8(0x51, 1);
    func_021D75A8(0x4a, 0);
    func_021D7674(0x35, one << 12, 410, one << 17);
    func_021D70F0(p, 0x13);
    r = func_021D7B10(func_021D775C(0x2f), func_021D775C(0x35));
    if (func_021D62A8((struct Unk021D62A8 *)x) == 1 && func_021D775C(0x51) != 0)
        r = r * 25 / 100;
    if (r > 10000)
        r = 10000;
    if (flag != 0 && func_021D775C(0x4a) != 0)
        r = 10000 - r;
    func_021D7540(1792);
    return r;
}











Entry *func_021BCA08(Server *p, u8 x)
{
    u32 i;
    u32 y = x;
    for (i = 0; i < p->n; i++) {
        if (y == func_021D5440(p->e[i].a))
            return &p->e[i];
    }
    return 0;
}











Entry *func_021BCA50(Server *p, Entry *cur, u32 x)
{
    u32 i;
    for (i = 0; i < p->n; i++) {
        if (&p->e[i] == cur) {
            i++;
            break;
        }
    }
    for (; i < p->n; i++) {
        if (x == func_021D5440(p->e[i].a))
            return &p->e[i];
    }
    return 0;
}











Entry *func_021BCAAC(Server *p, u16 x, u32 i)
{
    for (; i < p->n; i++) {
        if (p->e[i].done == 0 && func_021D8454(&p->e[i].b) == 1 && x == func_021D8340(&p->e[i].b))
            return &p->e[i];
    }
    return 0;
}











Entry *func_021BCB14(Server *p, u16 x, u8 y, u32 unused)
{
    Entry *e = func_021BCAAC(p, x, 0);
    while (e) {
        if (func_021B9A24(y, func_021D5440(e->a)) && func_021D5B68(e->a) == 0)
            return e;
        e = func_021BCAAC(p, x, (u8)(func_021BCB68(p, e) + 1));
    }
    return 0;
}











/*
 * unlabelled leaf (push {r3, r4}); filed as the blocker of func_021BCB14.
 */
int func_021BCB68(Server *p, Entry *cur)
{
    int i;
    int n = p->n;
    for (i = 0; i < n; i++) {
        if (&p->e[i] == cur)
            return (u8)i;
    }
    return n;
}











int func_021BCB98(Server *p, Entry *cur, int start)
{
    int a = -1;
    int b = -1;
    int i;
    int n = p->n;
    for (i = start; i < n; i++) {
        if (&p->e[i] == cur) {
            a = i;
            break;
        }
    }
    for (; start < n; start++) {
        if (p->e[start].done == 0) {
            b = start;
            break;
        }
    }
    if (a >= 0 && b >= 0 && a > b) {
        p->t = *cur;
        for (i = a; i > b; i--)
            p->e[i] = p->e[i - 1];
        p->e[b] = p->t;
        return b;
    }
    return -1;
}











void func_021BCC50(Server *p, Entry *cur)
{
    int i;
    int idx = -1;
    int n = p->n;
    for (i = 0; i < n; i++) {
        if (&p->e[i] == cur) {
            idx = i;
            break;
        }
    }
    if (idx < 0)
        return;
    p->t = *cur;
    for (i = idx; i < p->n - 1; i++)
        p->e[i] = p->e[i + 1];
    p->e[i] = p->t;
}











/*
 * interface: CC8D8's own matched source returns one-word struct Lock;
 *   this caller treats all r0 bits as a raw u32, copies r0 to r6 at 021BCEA4,
 *   and forwards r6 unchanged in r1 at 021BCEB6 to CC95C (str r1,[r0]).
 *   CC8D8 returns the entire pre-mutation 32-bit word. No bit is interpreted,
 *   narrowed or changed; both line arguments and all arities are preserved.
 *   Matched BD708 uses this same scalar interface. Struct diagnostic run03
 *   adds 8 frame bytes; byte score is not the payload/effect equivalence proof.
 * lever: Union views preserve bits7..22 for the full move field and bits7..9
 *   for case3; arg is bits23..30. Wrapping arithmetic is never signed.
 * semantics: Packed word widths derive from listing shift pairs; all fields
 *   unsigned, no signed arithmetic or asserted external selector bounds.
 */
u32 func_021BCCE0(Server *p, Entry *e)
{
    u8 *a;
    Action b;
    u32 lock;
    if (e->done == 0) {
        a = e->a;
        b = e->b;
        func_021C859C(p);
        e->done = 1;
        if (p->f14 == 5 && b.full.type != 4) goto end;
        if (func_021D5B68(a) != 0) goto end;
        if (b.full.type != 6 && func_021BCEEC(p->w1ab8, func_021D5440(a)) == 0) goto end;
        if (func_021D62C4((struct Unk021D62A8 *)a, 0x21) != 0) {
            if (b.full.type != 4 || func_021B86E4((unsigned int **)p->f4) != 2) {
                if (func_021D69AC(a, 3) != 0) func_021C0780(p, a, 3, 0);
                goto end;
            }
        }
        func_021BCEFC(p, a, e->b.full.type);
        func_021D5FC0((struct UtilWork *)a, 0);
        switch (b.full.type) {
        case 6:
            if (func_021B8588((void **)p->f4) == 3) func_021BC418(p, e->d, (u8)b.full.select);
            break;
        case 1:
            if (p->f1fe8[0] == 0) {
                func_021BC568(p);
                p->f1fe8[0] = 1;
            }
            p->f1f78 = func_021BCFAC(p, a);
            func_021BDE98(p, a, &b, e->c & 0x3fffff);
            break;
        case 2:
            if (func_021CB730(p, a, (u16)b.full.move, (u8)b.full.arg, (u8)b.full.select) == 1) {
                if (func_021BD708(p, a, 1, 1)) p->f14 = 5;
            }
            break;
        case 3:
            func_021BDC98(p, a, (u8)b.small.move);
            func_021BDA00(p);
            break;
        case 4:
            if (func_021BD584(p, a)) p->f14 = 5;
            break;
        case 8:
            p->f14 = 4;
            break;
        case 5:
            func_021BD3E8(p, a);
            break;
        case 7:
            func_021C54BC(p, a);
            break;
        case 0:
        default:
            break;
        }
        if (b.full.type == 1 || b.full.type == 2) {
            func_021D5FC0((struct UtilWork *)a, 1);
            func_021C60EC(p, a, 0);
        }
        lock = func_021CC8D8(&p->lock, 0x83b);
        func_021BCF70(p, a, b.full.type);
        func_021CC95C(&p->lock, lock, 0x83d);
    end:
        func_021C85B8(p);
        return b.full.type;
    }
    return 0;
}










/*
 * interface: func_021CC8D8 returns its four-byte Lock in r0; use the
 * full-word payload spelling of matched caller func_021BC568. The entire
 * func_021CC95C body is str r1,[r0]; bx lr, retaining every payload bit.
 * Aggregate spelling added eight bytes of frame; paired fixed-flag
 * runs were DIFF (60 bytes) and EXACT (56 bytes). Calls and stores agree.
 */
void func_021BCEFC(Server *p, u8 *a, u32 k)
{
    int line = 0x854;
    u32 old = func_021CC8D8(&p->lock, line);
    func_021BCF34(p, a, k);
    func_021CC95C(&p->lock, old, line + 3);
}












void func_021BCF34(Server *p, u8 *a, u32 k)
{
    int line = 0x864;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(12, k);
    func_021D70F0(p, 1);
    func_021D7540(line + 4);
}












void func_021BCF70(Server *p, u8 *a, u32 k)
{
    int line = 0x874;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(12, k);
    func_021D70F0(p, 2);
    func_021D7540(line + 4);
}











/*
 * note 2026-10-05 (wD9r lane04): EXACT* (the trailing 021BD07E halfword is alignment padding). Closed
 *   with `r -= x - y; if (r < x - y) return 3;` in place of the one-expression
 *   `(u16)(r - (u16)(x - y)) < x - y`. The redefinition of r splits its live range, so the first use
 *   reloads the spilled r (`str r0,[sp]; ldr r0,[sp]`). No cast stand-in.
 * note 2026-10-05 (wD9 lane18): still DIFF 55 B (no stand-in). Reading: the first use of r must be an
 *   operation on the spilled r (the u16 to u32 widening node), not the call temp; any plain form forwards r0.
 *   Tried: a static inline u16 rnd(u32) for both random calls; operands reversed (x - y > r) in one and both
 *   compares; an int d = x - y block; r as u32 with (u16) at the def and (int)r at the compare (a real
 *   signedness cast, still forwards r0). All 55 B.
 * note 2026-10-05 (integrator): the source no longer has the (int)(u32)r stand-in cast, so it is DIFF (the plain compare drops the reload of r). With the cast it verifies EXACT*: rejected as a stand-in.
 * note: the reload `str r0,[sp]; ldr r0,[sp]` at 021BD046/021BD048 comes only
 *   from spelling the first use of r through a widening cast, `(int)(u32)r`;
 *   plain `r`, `(int)r` and u16/u32/int locals forward r0 into the compare
 *   and drop the ldr (55 bytes out), and `(u32)r` alone reloads but turns
 *   the bge into bhs.
 */
int func_021BCFAC(Server *p, u8 *a)
{
    int k;
    u32 n;
    u16 x, y;
    if ((u32)func_021B86B8((void ***)p->f4) <= 1) {
        k = func_021B8DDC(func_021D5440(a));
        if (k == func_021B8FF4((u8 *)p->f4)) {
            void *v = func_021D5844(a);
            if (func_02018480(v, func_021B871C((char *)p->f4)) == 0) {
                n = func_021B85A0((u8 **)p->f4);
                if (n < 8) {
                    u16 r;
                    x = (u16)func_021D59B4(a, 15);
                    y = (u16)(10 * (n + 1));
                    if (x <= y) return 0;
                    if ((u16)func_021D78AC(x + y + 1) < y) return 0;
                    if (func_021D62C4((struct Unk021D62A8 *)a, 2) != 0) return 4;
                    r = func_021D78AC(256);
                    if (r < x - y && func_021BD080(p, a) == 0) return 2;
                    r -= x - y;
                    if (r < x - y) return 3;
                    return 4;
                }
            }
        }
    }
    return 0;
}











int func_021BD080(Server *p, u8 *a)
{
    int r;
    func_021D74F8(2256);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0xe);
    r = func_021D775C(0x41);
    func_021D7540(2261);
    return r;
}











int func_021BD0C0(Server *p, u8 x, u32 y)
{
    Entry *e = func_021BCA08(p, x);
    if (e) {
        if (e->done != 0 && func_021D8454(&e->b) == 6) {
            e = func_021BCA50(p, e, x);
        }
        if (e->done == 0) {
            if (func_021BDE48(e->a, &e->b)) return 0;
            if (func_021D8454(&e->b) == 6) return 0;
            func_021D82FC(&e->b, func_021BD138(p->w1ab8, y));
            func_021BCCE0(p, e);
            return 1;
        }
    }
    return 0;
}








int func_021BD148(Server *p, u8 x)
{
    Entry *e = func_021BCA08(p, x);
    if (e && e->done == 0) {
        if (func_021BCB98(p, e, 0) >= 0) return 1;
    }
    return 0;
}








int func_021BD170(Server *p, u16 x)
{
    int i = 0;
    int r;
    Entry *e = func_021BCAAC(p, x, 0);
    r = 0;
    while (e) {
        i = func_021BCB98(p, e, i);
        if (i < 0) break;
        i++;
        e = func_021BCAAC(p, x, (u8)i);
        r = 1;
    }
    return r;
}








int func_021BD1B0(Server *p, u8 x)
{
    Entry *e = func_021BCA08(p, x);
    if (e && e->done == 0) {
        func_021BCC50(p, e);
        return 1;
    }
    return 0;
}








/* 021BD1D0  guard on a callee's pointer result, then set a byte */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; bl func_021BCA08; cmp r0, #0; beq loc_021BD1DE; movs r1, #1; strb r1, [r0, #0xd]; pop {r3, pc}.
 */
void func_021BD1D0(Server *p, u8 n)
{
    Entry *e = func_021BCA08(p, n);
    if (e != 0)
        e->done = 1;
}








void func_021BD1E0(struct Unk021BD1E0 *p)
{
    p->f0 = 0;
    p->f2 = 6;
    p->f3 = 6;
    p->f4 = 0;
    p->b0 = 0;
    p->b1 = 0;
}








void func_021BD200(struct Unk021BD1E0 *p, Server *q, u8 *a, int t)
{
    int r = func_021BD264(t);
    p->f2 = func_021BD274(q->w1ab8, func_021D5440(a));
    p->f3 = 6;
    p->b0 = 0;
    p->b1 = 0;
    if (r == 1 && func_021BD284(t)) {
        p->f3 = func_021BD2A4(q->w1ab8, func_021D5440(func_021BD294(t, 0)));
    }
}









void func_021BD2B4(u8 *p, u8 **q)
{
    u8 i = 0;
    u8 *m;
    u8 j;
    u8 *x;
    int f;
    p[0] = i;
    p[1] = i;
    p[2] = 1;
    p[3] = i;
    for (; i < 4; i++) {
        m = func_021BB878(*q, i);
        if (m == 0) continue;
        for (j = 0; j < m[9]; j++) {
            x = func_021B9C00((struct S2 *)(*(u8 * *)&((struct Obj13305 *)m)->f4), j);
            if (x) f = func_021D5B68(x) == 0;
            else f = 0;
            if (f) {
                p[0] = i;
                p[2] = 0;
                p[1] = j;
                return;
            }
        }
    }
}








void func_021BD338(u8 *p, Server *q)
{
    if (func_021B8588(q->f4) == 3) p[3] = 1;
}









int func_021BD34C(u8 *p, u8 **q, u8 **out)
{
    u8 *m;
    u8 *x;
    u8 n;
    int f;
    if (p[2] != 0) return 0;
    *out = (u8 *)func_021B9BF0((struct S2 *)(*(u8 **)(func_021BB85C(*q, p[0]) + 4)), p[1]);
    p[1]++;
    while (p[0] < 4) {
        m = func_021BB878(*q, p[0]);
        if (m) {
            n = p[3] == 0 ? m[9] : 3;
            for (; p[1] < n; p[1]++) {
                x = (u8 *)func_021B9BF0((struct S2 *)(*(u8 * *)&((struct Obj13306 *)m)->f4), p[1]);
                if (x) f = func_021D5B68(x) == 0;
                else f = 0;
                if (f) return 1;
            }
        }
        p[0]++;
        p[1] = 0;
    }
    p[2] = 1;
    return 1;
}









void func_021BD3E8(Server *p, u8 *a)
{
    int i;
    int r;
    i = func_021B8DDC(func_021D5440(a));
    r = func_021B9C98((u8 *)func_021B9AEC((char *)p->f8, i), (u32)a);
    if (r == 0 || r == 2) {
        func_021BD43C(p, i, r, 1, 0);
        func_021C5D88(p, a, 0xe7);
        func_021BD4E4(p, i, r, 1);
    }
}








void func_021BD43C(Server *p, int i, u8 a, u8 b, int c)
{
    char *s = func_021B9AEC((char *)p->f8, i);
    int x = func_021B8BEC((u8 *)p->f4, i, a);
    int y = func_021B8BEC((u8 *)p->f4, i, b);
    u8 *q;
    u8 *r;
    func_021BD4D4(p->w1ab8, x, y);
    func_021B9C10((u32 *)s, a, b);
    if (c == 0) {
        func_021CD4B0(p->fC, 0x44, i, x, y);
        q = (u8 *)func_021B9BF0((struct S2 *)s, a);
        r = (u8 *)func_021B9BF0((struct S2 *)s, b);
        if (!func_021D5B68(q)) func_021D5FC0((struct UtilWork *)q, 0xc);
        if (!func_021D5B68(r)) func_021D5FC0((struct UtilWork *)r, 0xc);
    }
}









void func_021BD4E4(Server *p, int i, u8 a, u8 b)
{
    u8 *arr;
    u8 *first;
    u8 *second;
    arr = (u8 *)func_021B9AEC((char *)p->f8, i);
    first = func_021B9C00((struct S2 *)arr, a);
    second = func_021B9C00((struct S2 *)arr, b);
    func_021BD518(p, first);
    func_021BD518(p, second);
}









/*
 * return evidence: func_021CC8D8's matched Lock is one full 32-bit word;
 *   021CC8DA loads it, 021CC900 returns that unchanged word in r0.
 *   This caller saves r0 in r4 and passes it unchanged in r1 to restore.
 *   Scalar u32 return follows matched neighbours 021BD708/021BDA00;
 *   union aggregate spelling gave a spurious 8-byte stack frame (run 1).
 */
void func_021BD518(Server *p, u8 *m)
{
    u32 old;
    if (func_021D5B68(m) == 0) {
        old = func_021CC8D8(&p->lock, 2697);
        func_021BD554(p, m);
        func_021CC95C(&p->lock, old, 2699);
    }
}









void func_021BD554(Server *p, u8 *m)
{
    func_021D74F8(2712);
    func_021D75A8(2, func_021D5440(m));
    func_021D70F0(p, 164);
    func_021D7540(2715);
}










int func_021BD584(Server *p, u8 *a)
{
    int k = func_021B8DDC(func_021D5440(a));
    int m = func_021B8FF4((u8 *)p->f4);
    int s = func_021BD60C(p, a, 0);
    if (s) return 1;
    if (k == m) {
        func_021BA1B4((char **)p->f4, 0x4e);
        func_021CD64C(p->fC, 0x5a, 0x49, 0xffff0000);
    } else {
        func_021CD64C(p->fC, 0x5b, 0x36b, func_021D5440(a), 0xffff0000);
    }
    if (k == m) {
        p->f786++;
        if (p->f786 > 0x1e) p->f786 = 0x1e;
    }
    return s;
}










int func_021BD60C(Server *p, u8 *a, u8 flag)
{
    int ret = 0;
    int k;
    u8 *q;
    u16 lo;
    u16 hi;
    int d;
    u32 t;
    if (func_021B86E4((unsigned int **)p->f4) == 0) {
        k = func_021B8DDC(func_021D5440(a));
        if (k == func_021B8FF4((u8 *)p->f4)) {
            ret = func_021BD6B8(p, a);
            if (ret) flag = 1;
        } else {
            flag = 1;
        }
    } else {
        flag = 1;
        ret = 1;
    }
    if (flag == 0) {
        q = func_021B9920(p->f8, 1, 0);
        if (q) {
            lo = func_021D58A8(a, 0xc);
            hi = func_021D58A8(q, 0xc);
            if (lo <= hi) {
                d = (((int)lo << 12) / (int)hi << 7) >> 12;
                t = d + p->f786 * 30;
                if (func_021D78AC(0x100) >= t) return 0;
            }
        }
    }
    return func_021BD708(p, a, ret, 0);
}










int func_021BD6B8(Server *p, u8 *a)
{
    int r;
    if (func_021D5B68(a) == 0) {
        func_021D74F8(2849);
        func_021D75EC(2, func_021D5440(a));
        func_021D7630(0x51, 0);
        func_021D70F0(p, 0xb);
        r = func_021D775C(0x51);
        func_021D7540(2854);
        return r;
    }
    return 0;
}








int func_021BD708(Server *p, u8 *a, int r, int z)
{
    int k = func_021B8DDC(func_021D5440(a));
    u8 f;
    if (func_021B86E4((unsigned int **)p->f4) == 0) {
        f = (u8)(func_021B902C(k, func_021B8FF4((u8 *)p->f4)) == 0 ? 1 : 0);
        if (r == 0 && func_021D5B68(a) == 0) {
            u32 l;
            l = func_021CC8D8(&p->lock, 2888);
            r = func_021BD850(p, a);
            func_021CC95C(&p->lock, l, 2890);
            if (r) return 0;
        }
        if (p->f78a.bits.b2 == 0) {
            if (z == 0) {
                u32 l;
                l = func_021CC8D8(&p->lock, 2904);
                r = func_021BD8AC(p, a);
                func_021CC95C(&p->lock, l, 2906);
            } else {
                r = 0;
            }
            if (r == 0) {
                if (f != 0) {
                    if (func_021B86B8((void ***)p->f4) == 0)
                        func_021CD64C(p->fC, 0x5c, 0x4b, 0x56a, func_021D5440(a), 0xffff0000);
                } else {
                    func_021CD64C(p->fC, 0x5c, 0x48, 0x56a, 0xffff0000);
                }
            }
            p->f78a.raw |= 4;
        }
    } else {
        if (func_021B86C0((u8 **)p->f4) != 0 && p->f78a.bits.b2 == 0) {
            func_021CD64C(p->fC, 0x5a, 0xc6, 0xffff0000);
            p->f78a.raw |= 4;
        }
    }
    func_021D8244((struct B *)(p->w4b8), k);
    return 1;
}







int func_021BD850(Server *p, u8 *a)
{
    int r;
    func_021D74F8(2957);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x41, 0);
    func_021BD89C(p, a);
    func_021D70F0(p, 0xc);
    r = func_021D775C(0x41);
    func_021D7540(2963);
    return r;
}






int func_021BD8AC(Server *p, u8 *a)
{
    int r;
    func_021D74F8(2979);
    func_021D75A8(2, func_021D5440(a));
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0xd);
    r = func_021D775C(0x51);
    func_021D7540(2984);
    return r;
}





void func_021BD8F0(Server *p, u8 i, u8 a, u8 b)
{
    char *arr;
    u8 *m;
    u8 id;
    u8 *flags;
    arr = func_021B9AEC((char *)p->f8, i);
    func_021CD4B0(p->fC, 42, i);
    func_021B9D10((char *)p->f4, (struct Arr *)arr, i);
    if (a != b) func_021B9C10((u32 *)arr, a, b);
    m = (u8 *)func_021B9BF0((struct S2 *)arr, a);
    id = func_021D5440(m);
    func_021B8750(p->f4, i, m);
    func_021D8484(m);
    func_021DCF5C(m);
    func_021D63EC(m, p->f10);
    func_021D6580(m);
    flags = p->flags;
    flags[id] = 1;
    if (func_021B8588(p->f4) == 3) {
        if ((u32)func_021B99B8(p->f4, (int)i) <= a) flags[id] = 0;
    }
    func_021CD4B0(p->fC, 18, i, a, b, (u16)p->f10);
    func_021BD9C4(p->w1ab8, func_021B8BEC((u8 *)p->f4, i, a), id, p->f8);
}




/*
 * extent: 42-byte function followed by 2-byte zero alignment padding.
 */
void func_021BD9D4(Server *p, u8 i, u8 a, u8 b, int c)
{
    func_021BD8F0(p, i, a, b);
    func_021CD4B0(p->fC, 61, i, a, b, (u8)c);
}




/*
 * lever: enum queue offset declared after the live locals retains r7;
 * cursor declared before out places cursor at sp+8 and out at sp+4.
 */
int func_021BDA00(Server *p)
{
    int result = 0;
    struct Cursor cursor;
    u8 *out;
    u32 lock;
    u8 *flag;
    enum Offset q = queue;
    func_021BDB28((u8 *)p + q);
    func_021BD2B4((u8 *)(&cursor), (u8 **)p);
    while (func_021BD34C((u8 *)(&cursor), (u8 **)p, &out) != 0) {
        flag = (u8 *)p + func_021D5440(out);
        if (flag[0x7c1] != 0) {
            func_021BDB38((u8 *)p + q, out);
            flag[0x7c1] = 0;
        }
    }
    func_021BDB48((u8 *)p + q, p);
    lock = func_021CC8D8(&p->lock, 3096);
    func_021BDBEC(p);
    if (func_021C88E4(p) != 0) result = 1;
    func_021CC95C(&p->lock, lock, 3102);
    func_021BDB58((u8 *)p + q);
    out = func_021BDB68((u8 *)p + q);
    while (out != 0) {
        lock = func_021CC8D8(&p->lock, 3108);
        func_021BDB88(p, out);
        if (func_021C88E4(p) != 0) result = 1;
        func_021CC95C(&p->lock, lock, 3114);
        out = func_021BDB78((u8 *)p + q);
    }
    lock = func_021CC8D8(&p->lock, 3117);
    func_021BDC0C(p);
    if (func_021C88E4(p) != 0) result = 1;
    func_021CC95C(&p->lock, lock, 3123);
    return result;
}





















void func_021BDB88(Server *p, u8 *a)
{
    func_021D74F8(0xc43);
    func_021D75EC(2, func_021D5440(a));
    func_021D70F0(p, 0x55);
    func_021D7540(0xc46);
}






















void func_021BDBB8(Server *p, u8 *a)
{
    func_021D74F8(0xc55);
    func_021D75EC(2, func_021D5440(a));
    func_021D70FC((int)p, 0x55, 4);
    func_021D7540(0xc58);
}






















void func_021BDBEC(Server *p)
{
    func_021D74F8(3173);
    func_021D70F0(p, 86);
    func_021D7540(3175);
}






















void func_021BDC0C(Server *p)
{
    func_021D74F8(3187);
    func_021D70F0(p, 87);
    func_021D7540(3189);
}






















void func_021BDC2C(Server *p)
{
    u32 old;
    old = func_021CC8D8(&p->lock, 0xc82);
    func_021BDC58(p);
    func_021CC95C(&p->lock, old, 0xc84);
}






















void func_021BDC58(Server *p)
{
    func_021D74F8(3217);
    func_021D70F0(p, 88);
    func_021D7540(3219);
}






















void func_021BDC78(Server *p, u8 *a)
{
    u8 id;
    int value;
    id = func_021D5440(a);
    value = func_021B8DDC(id);
    func_021CD4B0(p->fC, 0x3b, value, id);
}























void func_021BDC98(Server *p, u8 *a, u8 v)
{
    u8 buf[2];
    u8 r;
    u8 *q;
    func_021BDC78(p, a);
    if (func_021BDD00(p, a, 0)) {
        r = func_021B8D8C(p->f4, p->f8, func_021D5440(a));
        func_021B8E28(p->f4, r, &buf[1], &buf[0]);
        q = p->w7d9;
        if (q[buf[1]] < 0xFF) q[buf[1]]++;
        func_021BD9D4(p, buf[1], buf[0], v, 1);
    }
}























int func_021BDD00(Server *p, u8 *a, int c)
{
    u32 n, i;
    if (c == 0) {
        n = func_021C6190(p, a);
        if (n != 0) {
            ((struct Fl *)&p->f78a)->f = 1;
            for (i = 0; i < n; i++) {
                func_021BD0C0(p, p->f78b[i], func_021D5440(a));
                if (func_021D5B68(a)) break;
            }
            ((struct Fl *)&p->f78a)->f = 0;
        }
    }
    if (func_021D5B68(a) == 0) {
        func_021BDD7C(p, a, 0x26C);
        return 1;
    }
    return 0;
}





















void func_021BDD7C(Server *p, u8 *a, u32 c)
{
    u8 n = func_021D5440(a);
    u32 s;
    int r = func_021B8D8C(p->f4, p->f8, n);
    if (r != 6) func_021CD4B0(p->fC, 0x3C, r, c);
    func_021BD1D0(p, n);
    s = func_021CC8D8(&p->lock, 3327);
    func_021BDE18(p, a);
    func_021CC95C(&p->lock, s, 3329);
    func_021C5108(p, a, 0);
    func_021D64F0(a);
    func_021CD4B0(p->fC, 0x20, func_021D5440(a));
    func_021BDE08(p->w1ab8, n);
}





















void func_021BDE18(Server *p, u8 *a)
{
    func_021D74F8(3348);
    func_021D75EC(2, func_021D5440(a));
    func_021D70F0(p, 0x54);
    func_021D7540(3351);
}






















u16 func_021BDE48(void *p, Action *m)
{
    u16 r = 0x17;
    if (func_021D62C4(p, 0x17) && m->full.move != 0xA5) {
        r = func_021E8B80(func_021D6314(p, r));
        if (r != m->full.move && func_021D55A0(p, r)) return r;
    }
    return 0;
}





















static inline void ev18(void *w, u32 x, u32 s, u32 c, u32 b, u32 i2, u32 i1)
{
    func_021CD4B0(w, 0x18, x, s, c, b, i2, i1);
}





















void func_021BDE98(Server *p, u8 *a, Action *act, u32 key)
{
    u8 sel;
    u32 prev;
    int chk1, chk2;
    int found;
    u8 flag;
    u8 pr;
    u16 m;
    u16 id;
    u16 id2;
    struct Out_021BDB88 o;

    prev = func_021D5C08((struct UtilWork *)a);
    func_021BD1E0((struct Unk021BD1E0 *)p->f4a8);
    func_021BE518((struct Unk021BE518 *)p->f4b0);
    o.c2 = 0;
    o.c4 = 6;
    m = func_021BDE48(a, (Action *)act);
    if (m != 0) {
        func_021D82D0((struct Unk021D82D0 *)act, m, func_021D80BC(p->f4, (int)p->f8, (int)a, m));
    }
    id = act->full.move;
    pr = func_021D5778((struct UtilWork *)a, id);
    id2 = id;
    sel = (u8)act->full.select;
    flag = 0;
    o.c0 = 0;
    chk1 = (u8)func_021D62C4((struct Unk021D62A8 *)a, 0x19);
    chk2 = (u8)func_021D62C4((struct Unk021D62A8 *)a, 0x1a);
    func_021E02DC(a, id, key);
    func_021BE924(p, a, id);
    if (func_021C001C(p, a, id, (u8)((chk1 != 0 || chk2 != 0) ? 1 : flag)) != 0) goto end;
    if (func_021C62D8(p, a, id, sel, (struct O_p11 *)(&o.c2)) == 0) {
        func_021C5604(p, a, id);
        func_021C64B4(p, id, a, (struct Out64B4 *)p->f1ab4);
        func_021CA7F4(p, a, sel, p->f1ab4, p->f850);
        func_021C07AC(p, a, id, pr, (int)p->f850);
        flag = 1;
        func_021C0450(p, a, id, 0x1a);
        goto end;
    }
    found = (u8)((o.c2 != 0) ? 1 : 0);
    if (found) {
        func_021C5604(p, a, id);
        func_021BEBD8(p, a, id, sel);
        func_021E02DC(a, o.c2, key);
        id2 = o.c2;
        sel = o.c4;
    } else {
        id2 = id;
    }
    func_021C64B4(p, id, a, (struct Out64B4 *)p->f1ab4);
    if (found) {
        func_021C64B4(p, id2, a, (struct Out64B4 *)p->f1ab0);
        ((u32 *)p->f1ab0)[4] |= 4;
        ((u16 *)p->f1ab0)[1] = id;
        if (func_021BE3A8(p, a, (u16 *)p->f1ab0) != 0) {
            func_021C07AC(p, a, id, pr, (int)p->f850);
            flag = 1;
            goto end;
        }
    } else {
        *(struct Cell *)p->f1ab0 = *(struct Cell *)p->f1ab4;
    }
    func_021BE338(p->f850);
    func_021BE348(p->f854);
    func_021CA7F4(p, a, sel, p->f1ab0, p->f850);
    {
        u32 v = (u8)func_021BE358(p->f850);
        func_021BE368(p->f850);
        func_021BE378(p->f850, p->f854);
        func_021BE388(p->f854, v);
    }
    if (chk1 == 0 && chk2 == 0 && pr != 4) {
        func_021C07AC(p, a, id, pr, (int)p->f850);
        flag = 1;
    }
    {
        func_021BE66C(p, a, p->f1ab4, 0x22);
        func_021BE620(p, a, p->f1ab0);
        if (func_021C6458(p, a, id, id2, p->w1ae4) != 0) {
            func_021C99A0(p, (const struct Msg *)p->w1ae4);
            func_021C8810(p->w1ae4);
        } else {
            func_021C5604(p, a, id2);
        }
    }
    p->f1f74 = id2;
    if (func_021D62C4((struct Unk021D62A8 *)a, 0x22) != 0) {
        func_021C5620(p, a, 0x22, 0);
        func_021D5FC0((struct UtilWork *)a, 0xe);
    }
    if (func_021C024C(p, a, id2) == 0
        && func_021BE7E4(p, a, id2, sel, (u8 *)&o) == 0
        && func_021BE6EC(p, a, id2, sel) == 0) {
        func_021BE398(p->w1c, id2, p->f10, func_021D5440(a));
        func_021BE66C(p, a, p->f1ab0, 0x23);
        if (func_021BEAB4(p, a, id2, (int)p->f854, p->f4ac) != 0) {
            func_021BE550(p, a, id2, p->f854);
        } else {
            o.c0 = func_021BEC58(p, a, id2, p->f854);
        }
    }
end:
    func_021D5FC0((struct UtilWork *)a, 3);
    if (flag != 0 || chk1 != 0 || id2 == 0xa5) {
        func_021D6744(a, sel, o.c0, ((u8 *)p->f1ab0)[6], id2, id);
        ev18(p->fC, func_021D5440(a), sel, o.c0, ((u8 *)p->f1ab0)[6], id2, id);
    } else if (func_021D69AC(a, 3) != 0) {
        func_021C0780(p, a, 3, 0);
    }
    if (prev != 0x10 && func_021D5C08((struct UtilWork *)a) != 0x10) func_021BFE60(p, a);
    if (func_021D5BB0((struct UtilWork *)a, 0xb) != 0) {
        func_021CD4B0(p->fC, 0x31, func_021D5440(a), 0);
        func_021BFF60(p, a, 0);
    }
    func_021BE994(p, a, id2, o.c0);
    if (o.c2 != 0) func_021E0394(a, o.c2);
    func_021E0394(a, id);
    func_021BE400(p, id2);
}

























int func_021BE3A8(Server *p, u8 *a, u16 *s)
{
    u16 t = *s;
    int k = 0;
    if (func_021D62C4((struct Unk021D62A8 *)a, 0xF) && (u32)func_0201BEB8((void *)t, (int)0xC)) {
        k = 0xD;
    } else if (func_021EF948(2) && (u32)func_0201BEB8((void *)t, (int)9)) {
        k = 0x14;
    }
    if (k) {
        func_021C0450(p, a, t, k);
        return 1;
    }
    return 0;
}

























void func_021BE400(Server *p, u16 key)
{
    u32 i;
    u8 *a;
    u8 *b;
    u32 lock;
    for (i = 0; i < (p->f4b0)[0]; i++) {
        a = func_021B9934(p->f8, (p->f4b0)[i + 1]);
        b = func_021B9934(p->f8, (p->f4b0)[i + 13]);
        if (func_021D5B7C(a) != 0) {
            lock = func_021CC8D8(&p->lock, 3657);
            func_021BEA60(p, a, b, key);
            func_021CC95C(&p->lock, lock, 3659);
            func_021C64B4(p, key, a, (struct Out64B4 *)(p->f1ab0));
            (((struct Out_021BE3A8*)p->f1ab0))->flag = 1;
            func_021CA7F4(p, a, (p->f4b0)[i + 7], (const u8 *)(p->f1ab0), p->f864);
            func_021D7394(func_021D5440(a));
            func_021E02DC(a, key, func_021D59B4(a, 12));
            func_021BEC58(p, a, key, p->f864);
            func_021E03D8(a, key);
            func_021D73D4(func_021D5440(a));
        }
    }
}

























void func_021BE518(struct Unk021BE518 *p)
{
    u32 i;
    p->f0 = 0;
    for (i = 0; i < 6; i++) p->f1[i] = 0x1F;
}
























/*
 * evidence: Each byte store may alias p[0], so reread the index.
 */
void func_021BE52C(u8 *p, int a, int b, int c)
{
    if (p[0] < 6) {
        (p + p[0])[1] = a;
        (p + p[0])[13] = b;
        (p + p[0])[7] = c;
        p[0]++;
    }
}
























void func_021BE550(Server *p, u8 *b, u16 c, void *unused)
{
    u8 *a;
    u32 lock;
    if ((p->f4ac)[0] != 0) {
        a = func_021B9934(p->f8, (p->f4ac)[1]);
        lock = func_021CC8D8(&p->lock, 3720);
        func_021BEA14(p, a, b, c);
        func_021CC95C(&p->lock, lock, 3722);
        func_021C64B4(p, c, a, p->f1ab0);
        func_021CA7F4(p, a, (p->f4ac)[7], p->f1ab0, p->f864);
        if (func_021D62C4((struct Unk021D62A8 *)a, 15) != 0 && (u32)func_0201BEB8((void *)c, (int)12) != 0) {
            func_021C0520(p, a, c, 13);
            return;
        }
        func_021E02DC(a, c, func_021D59B4(a, 12));
        func_021BEC58(p, a, c, p->f864);
        func_021E03D8(a, c);
    }
}

























void func_021BE620(Server *p, u8 *a, u8 *c)
{
    func_021D74F8(3755);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, ((struct Obj09961 *)c)->f0);
    func_021D7630(0x16, c[6]);
    func_021D70F0(p, 0xA2);
    c[6] = func_021D775C(0x16);
    func_021D7540(3761);
}
























/*
 * evidence: CC8D8 returns its four-byte Lock_021BDB88 in r0; preserve that complete
 * word as u32, as matched twin 021BE924 does. CC95C stores r1 unchanged.
 */
void func_021BE66C(Server *p, u8 *a, u8 *c, int k)
{
    u32 old;
    old = func_021CC8D8((struct Lock_021BDB88 *)&p->lock, 3774);
    func_021BE6A8(p, a, c, k);
    func_021CC95C(&p->lock, old, 3778);
}

























void func_021BE6A8(Server *p, u8 *a, u8 *c, int k)
{
    func_021D74F8(3791);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, ((struct Obj13311 *)c)->f0);
    func_021D75EC(0x16, c[6]);
    func_021D70F0(p, k);
    func_021D7540(3796);
}
























int func_021BE6EC(Server *p, u8 *a, u16 key, u32 x)
{
    u32 i;
    u32 n;
    u8 id;
    u8 *chosen;
    u32 best;
    u8 chosen_id;
    Entry *cur;
    Entry *found[2];
    u32 v;
    for (i = 0; i < 3; i++) {
        if (key == d_021EFDB8[i]) break;
    }
    if (i == 3) goto fail;
    if (func_021D5BB0((struct UtilWork *)a, 10) != 0) goto fail;
    if (func_021D6E74(a) != 0) goto fail;
    n = 0;
    id = func_021D5440(a);
    for (i = 0; i < 3; i++) {
        if (key != d_021EFDB8[i]) {
            found[n] = func_021BCB14(p, d_021EFDB8[i], id, x);
            if (found[n] != 0) {
                n++;
                if (n >= 2) break;
            }
        }
    }
    if (n == 0) goto fail;
    best = 6;
    chosen = found[0]->a;
    for (i = 0; i < n; i++) {
        cur = found[i];
        v = (u32)func_021BCB68(p, cur);
        if (v < best) {
            best = v;
            chosen = cur->a;
        }
    }
    chosen_id = func_021D5440(chosen);
    func_021D5FC0((struct UtilWork *)a, 10);
    func_021D6E40(chosen, id, key);
    func_021CD64C(p->fC, 91, 0x47a, id, chosen_id, 0xffff0000);
    func_021BD148(p, chosen_id);
    return 1;
fail:
    return 0;
}

























int func_021BE7E4(Server *p, u8 *a, u32 b, u32 c, u8 *q)
{
    u32 lk = func_021CC8D8(&p->lock, 3894);
    int r = func_021BE878(p, a, c);
    int s;
    *q = 0;
    if (r) {
        s = func_021B8D8C(p->f4, p->f8, func_021D5440(a));
        if (func_021C88E4(p) == 2) {
            func_021CD4B0(p->fC, 0x30, s, c, b, 0);
            func_021BE8C4(p, a);
            *q = 1;
        } else {
            func_021C5718(p, a, b);
        }
    }
    func_021CC95C(&p->lock, lk, 3913);
    return r;
}

























int func_021BE878(Server *p, u8 *a, u32 v)
{
    int r;
    func_021D74F8(3931);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0xD, v);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 6);
    r = func_021D775C(0x51);
    func_021D7540(3937);
    return r;
}






















void func_021BE8C4(Server *p, u8 *a)
{
    u32 old;
    old = func_021CC8D8((struct Lock_021BDB88 *)&p->lock, 3951);
    func_021BE8F4(p, a);
    func_021CC95C(&p->lock, old, 3956);
}






















void func_021BE8F4(Server *p,u8 *a)
{
    func_021D74F8(3968);
    func_021D75EC(3,func_021D5440(a));
    func_021D70F0(p,7);
    func_021D7540(3971);
}























void func_021BE924(Server *p, u8 *a, u32 v)
{
    u32 s = func_021CC8D8(&p->lock, 3985);
    func_021BE95C(p, a, v);
    func_021CC95C(&p->lock, s, 3987);
}






















void func_021BE95C(Server *p, u8 *a, u32 v)
{
    func_021D74F8(4000);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, v);
    func_021D70F0(p, 3);
    func_021D7540(4004);
}





















/*
 * Interface: getter's matched Lock_021BDB88 return is one full word; original
 * 021CC8DA loads old [r0] into r1; 021CC900 copies r1 to r0 unchanged.
 * This caller
 * saves r0 at 021BE9A8 and restores all bits through r1 at 021BE9BA;
 * 021CC95C is str r1,[r0]; bx lr. Scalar spelling follows matched caller
 * 021BC568 and retains the same word ABI. Struct/union locals used a
 * 12-byte frame and separate 4019 pool; scalar uses original 4-byte frame.
 */
void func_021BE994(Server *p,u8 *a,u32 c,u32 d)
{
    u32 old;
    old=func_021CC8D8(&p->lock, 4017);
    func_021BE9D0(p,a,c,d);
    func_021CC95C(&p->lock,old,4019);
}






















void func_021BE9D0(Server *p, u8 *a, u32 c, u32 d)
{
    func_021D74F8(4032);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x12, c);
    func_021D75EC(0x51, d);
    func_021D70F0(p, 4);
    func_021D7540(4037);
}






















void func_021BEA14(Server *p, u8 *a, u8 *b, u32 c)
{
    func_021D74F8(4051);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(3, func_021D5440(b));
    func_021D75EC(0x12, c);
    func_021D70F0(p, 8);
    func_021D7540(4056);
}





















void func_021BEA60(Server *p, u8 *a, u8 *b, u32 c)
{
    func_021D74F8(4069);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(3, func_021D5440(b));
    func_021D75EC(0x12, c);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 9);
    func_021D7540(4075);
}




















/*
 * The byte loaded and compared in r1 remains the veneer call's second
 * argument. The veneer at 021BEB04 preserves r0/r1 to its target.
 */
int func_021BEAB4(Server *p, u8 *a, int b, int c, u8 *q)
{
    u8 buf[2];
    buf[1] = 0x1F;
    buf[0] = 0x1F;
    func_021BEB14((int)p, a, b, c, &buf[1], &buf[0]);
    if (buf[1] != 0x1F) {
        q[7] = (buf[0] != 0x1F) ? func_021BEB04(p->w1ab8, buf[0]) : 6;
        q[1] = buf[1];
        q[0] = 1;
        return 1;
    }
    return 0;
}


















int func_021BEB14(int a, u8 *b, int c, int d, u8 *e, u8 *g)
{
    u32 n;
    u32 i;
    n = func_021BEBB8(d);
    func_021D74F8(4136);
    func_021D75EC(0x12, c);
    func_021D75EC(3, func_021D5440(b));
    func_021D75EC(5, n);
    for (i = 0; i < n; i++)
        func_021D75EC(6 + i, func_021D5440(func_021BEBC8(d, i)));
    func_021D7630(2, 0x1f);
    func_021D75A8(4, 0x1f);
    func_021D70F0((void *)a, 0x1a);
    *e = func_021D775C(2);
    *g = func_021D775C(4);
    func_021D7540(4155);
    if (*e != 0x1f)
        return 1;
    return 0;
}


















void func_021BEBD8(Server *p,u8 *a,int c,int d)
{
    int n;
    n=func_021B8D8C(p->f4,p->f8,func_021D5440(a));
    func_021CD4B0(p->fC,0x30,n,d,c,0);
}



















int func_021BEC08(Server *p,u8 *a)
{
    int n;
    n=func_021B8DDC(func_021D5440(a));
    if(n==func_021B8FF4(p->f4)) return 1;
    return 0;
}



















void func_021BEC2C(Server *p,u8 *a,int c)
{
    if(func_021BEC08(p,a)) {
        if(c==150) func_021BA1B4((char **)(p->f4),73);
        else if(c==165) func_021BA1B4((char **)(p->f4),74);
    }
}


















/*
 * budget: 2 iteration one; scheduling variant1/2 consumed; no checks/permuter.
 * Single action/filter pipeline, with flags initialized at EC74..EC7E.
 * All exit paths and switch table mappings retain their original results.
 * CC8D8 returns the full pre-mutation 32-bit Lock_021BDB88 (10+9+9+1+1+1+1).
 * ECFA saves all r0 and ED0E/ED14 forwards all r1 to own CC95C's u32
 * store; preserve line inputs 10A8/10AA under original return-use rule.
 * C5718's own one-input body does not erase the original loaded r1/r2.
 * Veneers EFEC/FFC/00C/01C/02C/03C forward respectively to ov095
 * CB3C/CEE4/CD50/CD50/CD50/D050; own matched records fix their widths.
 * Original ED78 branches onto ED7A: duplicated forced=1 arms retain the
 * cross-jumped break. Original EDB0..EDB4 extracts byte bit4, represented
 * by Bits78A. EE44 branches directly to EE6C, skipping C5718 at EE68;
 * only BF02C's true path performs that call before BF27C.
 */
int func_021BEC58(Server *p, u8 *a, u16 key, u8 *d)
{
    u32 lock;
    u32 action = func_0201C1BC(key);
    u8 id = func_021D5440(a);
    int active = 1;
    int execute = 0;
    int forced = 0;
    u32 pos;
    int result;
    struct State *s;
    func_021BEC2C(p, a, key);
    if ((u32)func_0201BEB8((void *)key, (int)1)) {
        switch (func_021BFC08(p, a, d, key)) {
        case 0: break;
        case 1: return execute;
        case 2: return active;
        case 3: return execute;
        case 4: break;
        }
    }
    func_021BEFEC(p->f860);
    pos = func_021CD4FC((u8 *)(p->fC), 0x30);
    func_021BD200((struct Unk021BD1E0 *)((struct State * )p->f4a8), p, a, (int)d);
    lock = func_021CC8D8(&p->lock, 0x10a8);
    result = func_021C65A8(p, a, key, d);
    func_021CC95C(&p->lock, lock, 0x10aa);
    if (result != 0) {
        s = (struct State * )p->f4a8;
        if (s->a == 0) s->a = 1;
        if (result == 2) {
            func_021BFBD0(p, key, p->f4a8, pos);
            return 1;
        }
    }
    switch (action) {
    case 0: case 4: case 6: case 7: case 8:
        execute = 1;
        forced = 1;
        break;
    case 9:
        forced = 1;
        break;
    }
    func_021BEFFC((struct S *)d);
    func_021BF04C(p, p->f1ab0, (int)a, (int)d);
    func_021BF0E4((int)p, a, (int)d, p->f1ab0, execute);
    if (func_021BF00C((struct S *)d)) {
        if (((struct Bits78A *)&p->f78a)->skip == 0) func_021C5718(p, a, key);
        active = 0;
    }
    if (active != 0) {
        if (action != 9) func_021BF83C(p, p->f1ab0, a, (int)d);
        func_021CC8A0((u32 *)p->w1f88);
        if (forced != 0 || func_021BF168(p, p->f1ab0, a))
            func_021BF3D8(p, (int)p->f1ab0, a, (int)d, p->w1f88);
        func_021BF4AC(p, p->f1ab0, a, d, p->w1f88);
        if (action != 9) func_021BF8D4(p, p->f1ab0, a, (int)d);
        if (func_021BF01C((struct S *)d)) {
            func_021BF27C(p, id, key);
            active = 0;
        } else {
            func_021BF1B4((int)p, p->f1ab0, (int)a, (int)d, forced);
            if (func_021BF02C((struct S *)d)) {
                func_021C5718(p, a, key);
                func_021BF27C(p, id, key);
                active = 0;
            }
        }
    }
    if (active != 0) {
        if (execute != 0) {
            func_021C091C(p, p->f1ab0, a, d, (const u32 *)p->w1f88, 0);
        } else {
            switch (action) {
            case 2: func_021C2DC4(p, (u32)p->f1ab0, (u32)a, (u32)d); break;
            case 1: func_021C2488(p, key, a, (u32)d); break;
            case 5: func_021C3184(p, p->f1ab0, (u32)a, (u32)d); break;
            case 9: func_021C3438(p, p->f1ab0, a, d); break;
            case 12: func_021C376C(p, key, (int)a, (int)d); break;
            case 3: func_021C3274(p, key, (u32)a, (u32)d); break;
            case 10: func_021C3AA8(p, p->f1ab0, a); break;
            case 11: case 13: func_021C3D08(p, p->f1ab0, a, d); break;
            }
        }
        s = (struct State * )p->f4a8;
        if (s->a != 0) {
            if (s->b == 0) func_021BFBD0(p, key, p->f4a8, pos);
            func_021BF03C((struct O *)p->w1c);
            if (!func_021D5B68(a) && (u32)func_0201BEB8((void *)key, (int)2)) func_021C60EC(p, a, 12);
            func_021BF244(p, id, key);
        } else {
            func_021BF27C(p, id, key);
            active = 0;
        }
    } else {
        s = (struct State * )p->f4a8;
        if (s->a != 0) func_021BFBD0(p, key, p->f4a8, pos);
    }
    func_021BF2B4(p, id, key);
    func_021C4F64(p, a);
    return active;
}
















void func_021BF04C(Server *p, u16 *b, int s, int c)
{
    int x;
    func_021BF0A4(c);
    x = func_021BF0B4(c);
    while (x != 0) {
        if (func_021BFA00(p, (u8 *)s, (u8 *)x, (void *)(*b)) != 0) {
            func_021BF0C4(c, x);
            func_021C572C(p, (u8 *)x, *b);
            p->f78a.raw |= 0x10;
        }
        x = func_021BF0D4(c);
    }
}















void func_021BF0E4(int u, u8 *b, int c, u8 *d, int e)
{
    u8 *x;
    if (func_021BF138(c) == 1) {
        x = func_021BF148(c, 0);
        if (x != 0) {
            if (func_021D5440(x) == func_021D5440(b)) {
                if (((struct Obj21056 *)d)->fC != 7) {
                    if (func_021D5BB0((struct UtilWork *)b, 12) != 0 || e != 0)
                        func_021BF158(c, x);
                }
            }
        }
    }
}















int func_021BF168(Server *p, u16 *a, u8 *b)
{
    int r;
    func_021D74F8(4500);
    func_021D75A8(3, func_021D5440(b));
    func_021D75A8(0x12, *a);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x3d);
    r = func_021D775C(0x51);
    func_021D7540(4506);
    return r;
}















void func_021BF1B4(int u, u16 *b, int s, int c, int e)
{
    int x;
    func_021BF204(c);
    x = func_021BF214(c);
    while (x != 0) {
        if (s != x && func_021D6D7C((u8 *)x) != 0 && e == 0 && (u32)func_0201BEB8((void *)((u16)((void *)*b)), (int)0xd) == 0)
            func_021BF224(c, x);
        x = func_021BF234(c);
    }
}














/*
 * interface: The four-byte Lock_021BF244 getter returns its entire original word in
 * r0 (021CC8DA,021CC900); restore 021CC95C stores that word unchanged.
 * Scalar payload follows matched caller 021BCEFC and preserves every bit.
 */
void func_021BF244(Server *p, u32 a, u32 b)
{
    int line = 0x11e7;
    u32 old = func_021CC8D8((struct Lock_021BF244 *)&p->lock, line);
    func_021BF2EC(p, a, b, 0x25);
    func_021CC95C(&p->lock, old, line + 2);
}














void func_021BF27C(Server *p, u32 a, u32 b)
{
    int line = 0x11f6;
    u32 old = func_021CC8D8((struct Lock_021BF244 *)&p->lock, line);
    func_021BF2EC(p, a, b, 0x26);
    func_021CC95C(&p->lock, old, line + 2);
}














void func_021BF2B4(Server *p, u32 a, u32 b)
{
    int line = 0x1205;
    u32 old = func_021CC8D8((struct Lock_021BF244 *)&p->lock, line);
    func_021BF2EC(p, a, b, 0x27);
    func_021CC95C(&p->lock, old, line + 2);
}














void func_021BF2EC(Server *p, u32 a, u32 b, int k)
{
    int line = 0x1214;
    func_021D74F8(line);
    func_021D75EC(2, a);
    func_021D75EC(0x12, b);
    func_021D70F0(p, k);
    func_021D7540(line + 4);
}














int func_021BF324(Server *p, u8 *a, u8 *b)
{
    u8 t;
    if (func_021BF3B8(p->w1ab8, (int)p->f4, func_021D5440(a)) != 0) {
        if (func_021D59B4(a, 0x11) == 0x63)
            return 1;
    }
    if (func_021BF3C8(p->w1ab8, (int)p->f4, func_021D5440(b)) != 0) {
        if (func_021D59B4(b, 0x11) == 0x63)
            return 1;
    }
    if (func_021D62C4((struct Unk021D62A8 *)a, 0x1c) != 0)
        return 1;
    if (func_021D62C4((struct Unk021D62A8 *)a, 0x1d) != 0) {
        t = func_021D62D8((struct UtilSlots *)a, 0x1d);
        if (t == func_021D5440(b))
            return 1;
    }
    return 0;
}












void func_021BF3D8(Server *p, int b, u8 *a, int d, void *arr)
{
    u8 *x;
    int r;
    int e;
    func_021CC8A0(arr);
    func_021BF46C(d);
    x = func_021BF47C(d);
    while (x != 0) {
        r = func_021C6E3C(p, a, x, (u8 *)b, 1);
        func_021CC8B0(arr, func_021D5440(x), r);
        if (r == 0) {
            func_021BF48C(d, x);
            func_021C7C24((u16 *)p->w1f7c, (int)p, a, x, 0);
            e = func_021B8DDC(func_021D5440(a));
            if (e == func_021B8FF4(p->f4))
                func_021BA1B4((char **)(p->f4), 0x4b);
        }
        x = func_021BF49C(d);
    }
}










void func_021BF4AC(Server *p, u8 *b, u8 *a, void *d, void *e)
{
    u8 *q;
    func_021BF5E8(d);
    q = func_021BF5F8(d);
    while (q) {
        if (func_021BF324(p, a, q) == 0 && func_021BF6E8(p, b, a, q, e, 43))
            func_021BF608(d, q);
        q = func_021BF618(d);
    }
    func_021BF628(d);
    q = func_021BF638(d);
    while (q) {
        if (func_021BF6E8(p, b, a, q, e, 44)) func_021BF648(d, q);
        q = func_021BF658(d);
    }
    if ((u32)func_0201BEB8((void *)(((struct Obj04358 *)b)->f0), (int)3)) {
        func_021BF668(d);
        q = func_021BF678(d);
        while (q) {
            if (func_021D5BB0((struct UtilWork *)q, 7) && func_021C6668(p, a, q, ((struct Obj04358 *)b)->f0) == 0) {
                func_021BF688(d, q);
                func_021CD64C(p->fC, 91, 523, func_021D5440(q), 0xffff0000);
            }
            q = func_021BF698(d);
        }
    }
    func_021BF6A8(d);
    q = func_021BF6B8(d);
    while (q) {
        if (func_021BF6E8(p, b, a, q, e, 45)) func_021BF6C8(d, q);
        q = func_021BF6D8(d);
    }
}











int func_021BF6E8(Server *p, u8 *b, u8 *c2, u8 *d, void *s0, int s1)
{
    u32 s;
    int flag;
    int r;
    s = func_021CC8D8(&p->lock, 4784);
    flag = 0;
    r = func_021BF78C(p, b, s1, c2, d, s0, p->w1ae4, &flag);
    if (r != 0) {
        if (func_021C8828(p->w1ae4) != 0) {
            func_021C99A0(p, (const struct Msg *)p->w1ae4);
            func_021C8810(p->w1ae4);
        } else if (func_021C88E4(p) == 0 && flag == 0) {
            func_021CD64C(p->fC, 0x5b, 0xd2, func_021D5440(d), 0xffff0000);
        }
    }
    func_021CC95C(&p->lock, s, 4810);
    return r;
}












int func_021BF78C(Server *p, u8 *b, int c, u8 *d, u8 *e, void *f, void *g, int *h)
{
    u32 t;
    int r;
    t = func_021CC8C0(f, func_021D5440(e));
    func_021C8810(g);
    func_021D74F8(4834);
    func_021D75EC(3, func_021D5440(d));
    func_021D75EC(4, func_021D5440(e));
    func_021D75EC(0x12, ((struct Obj13317 *)b)->f0);
    func_021D75EC(0x16, b[6]);
    func_021D75EC(0x4e, ((struct Bf *)b)->f);
    func_021D75EC(0x3f, (u32)g);
    func_021D75EC(0x38, t);
    func_021D7630(0x40, 0);
    func_021D7630(0x51, 0);
    func_021D70F0(p, c);
    r = func_021D775C(0x40);
    *h = func_021D775C(0x51);
    func_021D7540(4847);
    return r;
}












void func_021BF83C(Server *p, u16 *b, u8 *c, int d)
{
    u8 *x;
    func_021BF894(d);
    x = func_021BF8A4(d);
    while (x != 0) {
        if (func_021BF324(p, c, x) == 0) {
            if (func_021C6948(p, c, x, *b) != 0) {
                func_021BF8B4(d, x);
                func_021C572C(p, x, *b);
            }
        }
        x = func_021BF8C4(d);
    }
}









void func_021BF8D4(Server *p, u16 *b, u8 *c, int d)
{
    u8 *x;
    if (func_021BF944(d) == 1 && func_021BF954(d, 0) == c)
        return;
    func_021BF964(d);
    x = func_021BF974(d);
    while (x != 0) {
        if (func_021BF9A4(p, c, x, b) == 0 && func_021BFA60(p, c, x, (struct Q *)b) == 0) {
            func_021BF984(d, x);
            func_021C572C(p, x, *b);
        }
        x = func_021BF994(d);
    }
}












int func_021BF9A4(Server *p, u8 *a, u8 *b, u16 *c)
{
    int r;
    func_021D74F8(4929);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x12, *c);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x1c);
    r = func_021D775C(0x51);
    func_021D7540(4936);
    return r;
}













int func_021BFA00(Server *p, u8 *a, u8 *b, void *item)
{
    int x;
    int y;
    if (func_021B8588(p->f4) == 2) {
        if (item != 0 && func_0201BEB8(item, 0xb) != 0) return 0;
        x = func_021B8D8C(p->f4, p->f8, func_021D5440(a));
        y = func_021B8D8C(p->f4, p->f8, func_021D5440(b));
        if (func_021B9A6C(x, y) == 0) return 1;
    }
    return 0;
}












/*
 * lever: Declare flag before base to place their spills at the original stack offsets.
 */
int func_021BFA60(Server *p, u8 *a, u8 *b, struct Q *q)
{
    u8 flag;
    s8 x, y;
    int base;
    u32 scale;
    int v;
    u32 chance;
    if (func_021BF324(p, a, b)) return 1;
    if (func_021C69B8(p, a, (u32)b, q->h0)) return 1;
    if (func_021D62C4((struct Unk021D62A8 *)b, 32)) return 1;
    base = func_021C6A04(p, a, b, q);
    func_021D74F8(5014);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D7630(75, 0);
    func_021D75A8(39, func_021D59B4(a, 6));
    func_021D75A8(40, func_021D59B4(b, 7));
    func_021D7674(53, 4 << 10, 41, 4 << 15);
    func_021D70F0(p, 51);
    x = func_021D775C(39);
    y = func_021D775C(40);
    flag = func_021D775C(75);
    if ((func_021D62C4((struct Unk021D62A8 *)b, 17) && y > 6) || flag) y = 6;
    if (func_021D5BB0((struct UtilWork *)a, 14)) func_021D7704(53, 4915);
    scale = func_021D775C(53);
    func_021D7540(5039);
    v = x + 6 - y;
    if (v < 0) v = 0;
    if (v > 12) v = 12;
    chance = func_021D7B10(func_021D7908((u8)base, (u8)(s8)v), scale);
    if (chance > 100) chance = 100;
    if (func_021B911C(p->f4, 6)) chance = 100;
    if (func_021D78AC(100) < (u8)chance) return 1;
    return 0;
}












void func_021BFBD0(Server *p, u32 fallback, u8 *record, u32 pos)
{
    u32 value = ((struct Obj05190 *)record)->f0;
    if (value == 0) value = fallback;
    func_021CD568(p->fC, (u16)pos, 0x30,
                 record[2], record[3], value, record[4]);
    record[4] = 0;
    record[5] |= 2;
}










/*
 * lever: Wide n/callee parameter avoids truncation; named one-word union Slot result supplies the frame word.
 */
int func_021BFC08(Server *p, u8 *q, u8 *d, u16 c)
{
    int result;
    if (func_021D62C4((struct Unk021D62A8 *)q, 26) == 0) {
        u16 n = func_021B8D8C(p->f4, p->f8, func_021D5440(q));
        if (func_021C66AC(p, q, (u32)d)) {
            func_021C5718(p, q, c);
            return 1;
        }
        if (func_021C6720(p, q, c) == 0) {
            if (func_021BFD24(p, q, n, d, c)) {
                union Slot s = func_021E896C(2, c);
                func_021C5C1C(p, q, 26, s);
            }
            return 2;
        }
        if (func_021BFD24(p, q, n, d, c) == 0) return 1;
        {
            u32 lock = func_021CC8D8(&p->lock, 5124);
            func_021C6878(p, q, c);
            func_021CC95C(&p->lock, lock, 5126);
        }
    }
    (p->f4a8)[4] = 1;
    {
        u32 lock = func_021CC8D8(&p->lock, 5134);
        result = func_021C68A8(p, q, d, c);
        func_021CC95C(&p->lock, lock, 5136);
    }
    func_021D5FC0((struct UtilWork *)q, 11);
    func_021BFE60(p, q);
    return result ? 4 : 3;
}









int func_021BFD24(Server *p, u8 *q, u16 c, u8 *d, u16 e)
{
    u32 out;
    u8 id;
    u32 lock;
    int r;
    u8 n;
    out = 0;
    id = 31;
    lock = func_021CC8D8(&p->lock, 5160);
    r = func_021C676C(p, q, d, e, &id, &out);
    if (r) {
        n = p->f77f;
        if (func_021BFE30(d))
            n = func_021BFE50(p->w1ab8, func_021D5440(func_021BFE40(d, 0)));
        func_021CD4B0(p->fC, 48, c, n, e, 0);
    }
    func_021CC95C(&p->lock, lock, 5173);
    if (r) {
        lock = func_021CC8D8(&p->lock, 5177);
        func_021C6848(p, q);
        func_021CC95C(&p->lock, lock, 5179);
        if (func_021D5C30((struct UtilWork *)q))
            func_021CD4B0(p->fC, 49, func_021D5440(q), 1);
        if (id != 31)
            func_021CD4B0(p->fC, 49, id, 1);
    } else if (out == 0) {
        func_021C5718(p, q, e);
    }
    return r;
}











void func_021BFE60(Server *p, u8 *a)
{
    int k = 0x1a;
    u32 r;
    if (func_021D62C4((struct Unk021D62A8 *)a, k) != 0) {
        func_021C5620(p, a, k, 0);
        func_021D5FC0((struct UtilWork *)a, 0xb);
    }
    r = func_021D5C08((struct UtilWork *)a);
    while (r != 0x10) {
        func_021C6110(p, a, r);
        r = func_021D5C08((struct UtilWork *)a);
    }
}











int func_021BFEAC(Server *p, u8 *a, u8 *b, int *out)
{
    u8 n;
    union Slot t;
    *out = 0;
    if (func_021D5B68(b) == 0 && func_021D6D7C(b) == 0 && func_021D5C30((struct UtilWork *)b) == 0) {
        if (func_021D5BB0((struct UtilWork *)b, 7) == 0) {
            n = func_021D5440(b);
            func_021C60EC(p, a, 3);
            func_021C60EC(p, b, 3);
            func_021C0780(p, a, 4, n + 1);
            t = func_021E899C(func_021D5440(a));
            func_021C2910(p, b, a, 0x21, t, 0, 0, 0);
            return 1;
        }
        func_021CD64C(p->fC, 0x5b, 0x20b, func_021D5440(b), 0xffff0000);
        *out = 1;
    }
    return 0;
}










void func_021BFF60(Server *p, u8 *a, int z)
{
    u8 k;
    int n;
    u8 *w;
    n = func_021D69AC(a, 4);
    if (n == 0) goto bad;
    k = n - 1;
    if (k < 0x18) goto ok;
bad:
    k = 0x1f;
ok:
    if (k != 0x1f) {
        w = func_021B9934(p->f8, k);
        if (func_021D62C4((struct Unk021D62A8 *)w, 0x21) != 0) {
            func_021C5620(p, w, 0x21, 0);
            func_021C6110(p, w, 3);
            if (func_021C000C(p->w1ab8, k) != 0) {
                func_021CD4B0(p->fC, 0x31, k, 0);
                func_021C5D88(p, w, 0x465);
            }
        }
        func_021C0780(p, a, 4, 0);
        k = 0;
        if (z == 0 && func_021D5B68(a) == 0) {
            func_021CD4B0(p->fC, 0x31, func_021D5440(a), k);
        }
    }
}








/*
 * lever: Naming the one-word union result before passing it restores the original frame.
 * Symbol hints retain the Thumb ISA of the two already-matched ARM9 callees.
 */
int func_021C001C(Server *p, u8 *a, u16 c, u16 d)
{
    int mode;
    int changed = 0;
    int reason;
    union Slot move;
    func_021C03D8(p, a, c);
    mode = func_021D62A8((struct Unk021D62A8 *)a);
    if (mode == 2) {
        reason = 2;
        if (func_021C0274(p, a, c, 2) == 0) goto done;
    }
    changed = func_021C0404(p, a, (void *)c);
    mode = func_021D62A8((struct Unk021D62A8 *)a);
    if (mode == 3 && changed == 0) { reason = 4; goto done; }
    if (p->f1f78 == 4) { reason = 22; goto done; }
    if (p->f1f78 == 2) { reason = 23; goto done; }
    if (d == 0) {
        int index = func_021D5778((struct UtilWork *)a, c);
        if (index != 4 && func_021D5584((struct UtilWork *)a, index) == 0) { reason = 1; goto done; }
    }
    reason = func_021C02CC(p, a, c, 30);
    if (reason) goto done;
    if (func_021D5BB0((struct UtilWork *)a, 6)) { reason = 7; goto done; }
    if (func_021D5BB0((struct UtilWork *)a, 4)) { reason = 6; goto done; }
    if (func_021D62C4((struct Unk021D62A8 *)a, 13) && c != 165) {
        move = func_021D6314(a, 13);
        if (c == func_021E8B80(move)) { reason = 9; goto done; }
    }
    if (func_021D62C4((struct Unk021D62A8 *)a, 15) && (u32)func_0201BEB8((void *)c, (int)12)) { reason = 13; goto done; }
    if (func_021EF948(2) && (u32)func_0201BEB8((void *)c, (int)9)) { reason = 20; goto done; }
    if (c != 165) {
        if (func_021D62C4((struct Unk021D62A8 *)a, 23)) {
            u16 id = func_021D67B8(a);
            if (id != 165 && id != c) { reason = 17; goto done; }
        }
        if (func_021D62C4((struct Unk021D62A8 *)a, 25) && c != func_021D67A8((struct QL *)a)) { reason = 17; goto done; }
        if (func_021D62C4((struct Unk021D62A8 *)a, 11) && func_0201C314((void *)c) == 0) { reason = 10; goto done; }
        if (func_021EF948(3) && func_021EF91C(p->f8, a, c)) { reason = 12; goto done; }
    }
    if (func_021C031C(p, a)) { reason = 5; goto done; }
    if (mode == 1 && func_021D7AF0(25)) { reason = 3; goto done; }
    if (func_021C03AC(p, a)) reason = 8;
done:
    if (reason) {
        func_021C0450(p, a, c, reason);
        return 1;
    }
    if (mode == 2) {
        func_021C0520(p, a, c, 2);
        func_021C5480(p, a, 598);
    } else if (changed && mode == 3) {
        func_021C557C(p, a, mode, 0);
        func_021CD64C(p->fC, 91, 303, func_021D5440(a), c, 0xffff0000);
    }
    return 0;
}











/*
 * lever: Wide third extern argument preserves the full r2 passed by the image.
 */
int func_021C024C(Server *p, u8 *a, u16 c)
{
    int result;
    if (c != 0xa5) {
        result = func_021C02CC(p, a, c, 0x1f);
        if (result != 0) {
            func_021C0450(p, a, c, result);
            return 1;
        }
    }
    return 0;
}












int func_021C0274(Server *p, u8 *a, u32 c, u32 d)
{
    int r;
    func_021D74F8(5537);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x22, d);
    func_021D75EC(0x12, c);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x1D);
    r = func_021D775C(0x41);
    func_021D7540(5544);
    return r;
}












int func_021C02CC(Server *p, u8 *a, u32 c, int k)
{
    int r;
    func_021D74F8(5563);
    func_021D75EC(0x12, c);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x22, 0);
    func_021D70F0(p, k);
    r = func_021D775C(0x22);
    func_021D7540(5569);
    return r;
}











int func_021C031C(Server *p, u8 *a)
{
    int k = 6;
    if (p->f1f78 == 3) {
        func_021CD64C(p->fC, 0x5a, 0xbc, func_021D5440(a), 0xffff0000);
        return 1;
    }
    if (func_021D62C4((struct Unk021D62A8 *)a, k) != 0) {
        if (func_021D61A8((struct UtilSlots *)a) != 0) {
            func_021C5620(p, a, k, 0);
            func_021CD64C(p->fC, 0x5b, 0x15f, func_021D5440(a), 0xffff0000);
            return 0;
        }
        func_021C54C8(p, a);
        return func_021D7AF0(50);
    }
    return 0;
}












int func_021C03AC(Server *p, u8 *a)
{
    if (func_021D62C4((struct Unk021D62A8 *)a, 7) != 0) {
        func_021C54FC(p, a);
        if (func_021D7AF0(50) != 0) return 1;
    }
    return 0;
}












void func_021C03D8(Server *p, u8 *a, u16 a2)
{
    int k = func_021D62A8((struct Unk021D62A8 *)a);
    if (k == 2 && func_021D6130((struct UtilSlots *)a) != 0) {
        func_021C557C(p, a, k, 1);
    }
}











int func_021C0404(Server *p, u8 *a, void *bag)
{
    int k = func_021D62A8((struct Unk021D62A8 *)a);
    int f = 0;
    int r = 0;
    if (k == 3) {
        if (func_0201BEB8(bag, 10) != 0) {
            r = 1;
        } else if (func_021D7AF0(20) != 0) {
            f = 1;
        }
    }
    if (f != 0) {
        func_021C557C(p, a, k, 1);
    }
    return r;
}











/*
 * lever: Raw u32 lock return avoids an aggregate frame word; Slot_021C024C remains a one-word aggregate.
 */
/*
 * lever: Raw u32 lock return avoids an aggregate frame word; Slot remains a one-word aggregate.
 */
void func_021C0450(Server *p, u8 *q, u16 c, int k)
{
    u32 old;
    if (k == 5) {
        func_021C63D0(p, q);
        if (func_021C4F64(p, q) && func_021BC2B0(p)) return;
    } else {
        func_021C0520(p, q, c, k);
        switch (k) {
        case 2: func_021C5480(p, q, 598); break;
        case 3: func_021C5480(p, q, 602); break;
        case 4: func_021C5480(p, q, 601); break;
        case 23: {
            union Slot s = func_021D7D18(2);
            func_021CD4B0(p->fC, 49, func_021D5440(q), 0);
            func_021C5C1C(p, q, 2, s);
            func_021C5480(p, q, 598);
            break;
        }
        }
    }
    old = func_021CC8D8(&p->lock, 5728);
    func_021C6564(p, q, c, k);
    func_021CC95C(&p->lock, old, 5730);
}











/*
 * lever: a u8 local for the random result narrows in r0 before copying to r2.
 */
void func_021C0520(Server *p, u8 *a, u16 b, u32 c)
{
    u32 id = func_021D5440(a);
    switch (c) {
    case 2: func_021CD64C(p->fC, 0x5b, 0x135, id, 0xffff0000); break;
    case 3: func_021CD64C(p->fC, 0x5b, 0x114, id, 0xffff0000); break;
    case 4: func_021CD64C(p->fC, 0x5b, 0x123, id, 0xffff0000); break;
    case 6: func_021CD64C(p->fC, 0x5b, 0x16b, id, 0xffff0000); break;
    case 7: func_021CD64C(p->fC, 0x5b, 0x16e, id, 0xffff0000); break;
    case 8: func_021CD64C(p->fC, 0x5b, 0x150, id, 0xffff0000); break;
    case 9: func_021CD64C(p->fC, 0x5b, 0x253, id, b, 0xffff0000); break;
    case 18: func_021CD64C(p->fC, 0x5b, 0x1bd, id, 0xffff0000); break;
    case 10: func_021CD64C(p->fC, 0x5b, 0x23b, id, b, 0xffff0000); break;
    case 11: func_021CD64C(p->fC, 0x5b, 0x244, id, b, 0xffff0000); break;
    case 12: func_021CD64C(p->fC, 0x5b, 0x24d, id, b, 0xffff0000); break;
    case 13: func_021CD64C(p->fC, 0x5b, 0x37a, id, b, 0xffff0000); break;
    case 14: func_021CD64C(p->fC, 0x5b, 0x37d, id, 0xffff0000); break;
    case 15:
        func_021CD4B0(p->fC, 0x57, id);
        func_021CD64C(p->fC, 0x5b, 0x1c3, id, 0xffff0000);
        func_021CD4B0(p->fC, 0x58, id);
        break;
    case 20: func_021CD64C(p->fC, 0x5b, 0x43e, id, b, 0xffff0000); break;
    case 22:
        if (func_021D62C4((struct Unk021D62A8 *)a, 2) != 0) {
            func_021CD64C(p->fC, 0x5a, 0xc2, id, 0xffff0000);
        } else {
            u8 rand = func_021D78AC(4);
            func_021CD64C(p->fC, 0x5a, rand + 0xbc, id, 0xffff0000);
        }
        break;
    case 23: func_021CD64C(p->fC, 0x5a, 0xc1, id, 0xffff0000); break;
    case 1:
        func_021C5604(p, a, b);
        func_021CD64C(p->fC, 0x5a, 0x52, id, 0xffff0000);
        break;
    default: func_021CD64C(p->fC, 0x5a, 0x47, id, 0xffff0000); break;
    case 19:
    case 25:
        break;
    }
}












void func_021C0780(Server *p, u8 *a, int i, u8 v)
{
    func_021CD4B0(p->fC, 0x25, func_021D5440(a), (u8)i, v);
    func_021D69A0(a, i, v);
}











/*
 * extent: Two alignment bytes at 0x021C07D2 precede matched func_021C07D4.
 * lever: Wide forwarded arguments avoid truncations absent before the first call.
 */
int func_021C07AC(Server *p, u8 *a, u16 c, u16 d, int e)
{
    u8 result = func_021C07D4(p, a, d, c, e);
    return func_021C0898(p, a, d, result);
}








/*
 * c and d are narrow parameters: their home stores (`str r2,[sp]` first,
 * `str r3,[sp,#4]` after `adds r7,r1`) sit where the narrow-parameter idiom
 * puts them; as u32 both sink below `ldr r5`. u8 and u16 compile the same
 * (any mix of the two); nothing in the image fixes the width, u16 chosen.
 * func_021C0868/0878/0888 are `bx pc` ARM veneers declared as thumb externs.
 * `i = 0;` as its own statement before the func_021C0868 call puts
 * `movs r4,#0` between `adds r0,r5` and that bl.
 */
int func_021C07D4(Server *p, u8 *a, u16 c, u16 d, int e)
{
    int i;
    u8 *r;
    int res;
    func_021D74F8(0x16ef);
    i = 0;
    func_021D75EC(5, func_021C0868(e));
    r = func_021C0878(e, 0);
    if (r != 0) {
        do {
            func_021D75EC(i + 6, func_021D5440(r));
            i++;
            r = func_021C0888(e, i);
        } while (r != 0);
    }
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, d);
    func_021D75EC(0x17, c);
    func_021D75A8(0x20, 1);
    func_021D70F0(p, 0x4e);
    res = func_021D775C(0x20);
    func_021D7540(0x1704);
    return res;
}







int func_021C0898(Server *p, u8 *a, u32 b, u8 c)
{
    u8 limit = func_021D5584((struct UtilWork *)a, b);
    if (c >= limit) c = limit;
    if (c != 0) {
        func_021C08CC(p, a, b, c);
        return 1;
    }
    return 0;
}









void func_021C08CC(Server *p, u8 *a, int b, u8 c)
{
    u32 n;
    if (func_021B911C(p->f4, 5) == 0) {
        n = func_021D5440(a);
        func_021D5608((struct UtilWork *)a, b, c);
        func_021CD4B0(p->fC, 4, n, b, c);
        func_021D56CC((struct Work *)a, b);
        func_021CD4B0(p->fC, 6, n, b);
    }
}








void func_021C091C(Server *p, u8 *q, u8 *a, u8 *b, const u32 *c, u32 d)
{
    u32 result = 0;
    int flag = 0;
    u32 out;
    p->f1fe8[1] = 0;
    func_021C19D8(p, a, q);
    func_021C0A1C(p->f860);
    func_021C71E0(p, a, ((struct Obj04358 *)q)->f0, p->f4b4);
    func_021C14E0(p, a, (int)q, b);
    if (func_021C0A2C(b) != 0) {
        if (func_021C1194(p->f4b4) != 0 && func_021C0A3C(b) == 1) {
            result = func_021C0F24(p, q, a, b, c);
        } else {
            result = func_021C0D90(p, q, a, b, c, &out, d);
            flag = 1;
        }
        func_021C2048(p, a, ((struct Obj04358 *)q)->f0, result);
    }
    func_021C1A54(p, q, a, p->f860, result, d);
    if (flag != 0) {
        struct State_p06 *s = (struct State_p06 * )p->f4a8;
        if (s->a == 0) {
            s->a = 1;
            s->b = 1;
        }
        func_021BFBD0(p, ((struct Obj04358 *)q)->f0, p->f4a8, out);
    }
}






void func_021C0A4C(Server *p, u8 *a, u8 *b, const u8 *q, const u32 *c, u32 k, struct List_021BDB88 *out)
{
    int i = 0;
    u8 *r;
    struct { u16 x, y; } temp;
    out->good = 0;
    out->bad = 0;
    func_021C0C04(b);
    r = func_021C0C14(b);
    if (r != 0) {
        do {
            out->entries[i].id = func_021D5440(r);
            out->entries[i].marked = (u16)func_021C6BF8(p, a, r, (u32)(((struct Obj21063 *)q)->f0));
            out->entries[i].mode = (u16)(int)func_021CC8B8((u32 *)c, (u8)out->entries[i].id);
            out->entries[i].special = (u16)func_021C1E74(p, a, r, q, out->entries[i].mode, k, out->entries[i].marked, 0, &temp.y);
            out->entries[i].value = temp.y;
            if (out->entries[i].special) {
                out->entries[i].marked = 0;
                out->entries[i].mode = 3;
            }
            out->entries[i].error = (u16)func_021D6D7C(r);
            if (!out->entries[i].error) {
                temp.x = func_021C15D4(r, out->entries[i].value);
                out->entries[i].type = (u16)func_021C1678(p, a, r, 1, &temp.x);
                out->entries[i].value = temp.x;
                out->good++;
            } else {
                out->entries[i].value = temp.y;
                out->entries[i].type = 0;
                out->bad++;
            }
            func_021C7C24((u16 *)p->w1f7c, (int)p, a, r, out->entries[i].mode);
            i++;
            r = func_021C0C24(b);
        } while (r != 0);
    }
    out->count = i;
}







/* 021C0C34  ldrb r0,[r0,#2] */
/*
 * Reads the u8 field at #2 of the argument and returns it.
 */
u32 func_021C0C34(u8 *p) { return p[2]; }







int func_021C0C38(Server *p, const List_td *l, u32 *o0, u16 *o1, u32 *o2, u8 *o3)
{
    u32 i = 0;
    int k = 0;
    for (; i < l->n; i++) {
        if (l->r[i].flag) {
            o0[k] = (u32)func_021B9934(p->f8, (u8)l->r[i].idx);
            o1[k] = l->r[i].v;
            o2[k] = l->r[i].b;
            o3[k] = l->r[i].c;
            k++;
        }
    }
    return k;
}







/*
 * Record shape follows the matched unpacker func_021C0CE8.
 * The byte count admits multiple four-byte trailing records (q+4+i*4);
 * a flexible array models that extent without imposing a one-record bound.
 * The original narrows the five-bit field to u8 before the call.
 */
int func_021C0CB4(Server *p, const struct Q_021C0CB4 *q, u32 *out)
{
    u32 i = 0;
    for (; i < q->n; i++)
        out[i] = (u32)func_021B9934(p->f8, (u8)q->e[i].lo);
    return q->n;
}








/*
 * Structure recovered (7 parameters; the three stack pointers are re-stored to
 * their own slots in the prologue, `ldr r0,[sp,#0x28]; str r0,[sp,#0x28]`,
 * which the compiled code reproduces). Entries at q+4, stride 4: {u16 v; u16
 * bitfield}, bitfield lo:5 b:4 c:4 d:1 e:1 f:1 (LSB first: lsls #0x1b, #0x17,
 * #0x13, #0x12, #0x10 pairs). Loop keeps entries with f == 0 and packs
 * o1[n]=func_021B9934(p[8], lo) (u8 argument: a `lsls/lsrs #0x18` follows the
 * 5-bit extract), o2[n]=v, o3[n]=b, o4[n]=d, o5[n]=c.
 *
 * Residue: register/spill allocation of the loop. Original: q in r6, i in r7,
 * n in r4, i*4 in r5, the hoisted q+6 spilled to [sp+0x10], flag test through
 * (q+r5)+6 and the lo/b/c/d fields through ONE shared halfword load from the
 * hoisted base (`ldrh r0,[r0,r5]` after `ldr r0,[sp,#0x10]`) with the flag and v read
 * separately through q+r5. Compiled: q in r7, i spilled to [sp+0x10], the hoisted
 * q+6 in r6, and each bitfield reloaded from memory (138 B against 136 B, no
 * cast; 142 B with the u8 parameter). Struct Bits copy (`t = e[i].bits`) gives
 * the single shared load but adds a stack temp and swaps i/n.
 *
 * checks: 1 func_021B9934 is (char *p, int i) in its matched file; the original casts the lo field to u8 before the bl, so the extern parameter is u8 (tried: +4 bytes of cast, spills unchanged); 2 no twin in ov093 with a 7-parameter bitfield unpack; 3 u32/int for i and n, u8-cast loop bound, n declared before i, struct Bits copy for b/c/d, manual (h>>5)&0xf form (gives asrs/ands, wrong), pointer form q+4 cast to struct Ent: none moved q into r6 and i into r7; 4 none fits (declaration-order idiom tried as n-before-i, no change); 5 no new idiom. Sweep I would run: the permuter over declaration order and over which of the flag/lo/b/c/d reads go through a shared u16 local.
 */
int func_021C0CE8(Server *p, const struct Q_021C0CE8 *q, u32 *o1, u16 *o2, u32 *o3, u8 *o4, u8 *o5)
{
    u32 i = 0;
    u32 n = 0;
    for (; i < q->n; i++) {
        if (q->e[i].f == 0) {
            o1[n] = (u32)func_021B9934(p->f8, (u8)q->e[i].lo);
            o2[n] = q->e[i].v;
            o3[n] = q->e[i].b;
            o4[n] = q->e[i].d;
            o5[n] = q->e[i].c;
            n++;
        }
    }
    return n;
}







/*
 * Extent ends with two zero alignment bytes at 0x021C0D8E.
 * Declare i before sum, but initialize sum before i, to reproduce both
 * register allocation and the order of the initial movs instructions.
 * Each record supplies the halfword at offset 4, stride 4.
 */
u32 func_021C0D70(const u8 *q)
{
    u32 i;
    u32 sum = 0;
    i = 0;
    for (; i < q[2]; i++)
        sum += *(const u16 *)(q + 4 + i * 4);
    return sum;
}





u32 func_021C0D90(Server *p, u8 *q, u8 *a, u8 *b, const u32 *c, u32 *out, u32 d)
{
    u16 k;
    u32 result;
    CallFlags f;
    if (func_021C0EC4(b) == 1) k = 0x1000;
    else k = 0xc00;
    result = 0;
    f.bits.a = func_021C0ED4(b) > 1;
    f.bits.b = d;
    func_021C0EE4(b, a, p->f858);
    func_021C0EF4(b, a, p->f85c);
    func_021C0A4C(p, a, p->f858, q, c, k, p->f86c);
    func_021C0A4C(p, a, p->f85c, q, c, k, p->f870);
    *out = func_021CD4FC(p->fC, 0x30);
    if (func_021C0F04(p->f858) != 0) {
        result += func_021C11A4(p, (u16 *)q, a, p->f858, p->f86c, p->f4b4, k, f);
        if (result != 0 && func_021BEC08(p, a) != 0)
            func_021BA1B4((char **)(p->f4), 0x4d);
    }
    if (func_021C0F14(p->f85c) != 0)
        result += func_021C11A4(p, (u16 *)q, a, p->f85c, p->f870, p->f4b4, k, f);
    return result;
}




u32 func_021C0F24(Server *p, u8 *q, u8 *a, u8 *d, const u32 *c)
{
    u32 i;
    u32 completed;
    u32 sum = 0;
    int old;
    u8 tag = 6;
    u8 *b = (u8 *)func_021C1144(d, 0);
    struct State_p06 *s;
    CallFlags f;
    p->f789 = func_021D5440(b);
    if (func_021B8590(p->f4)) {
        tag = func_021C1154(p->w1ab8, func_021D5440(b));
        if (tag != 6) {
            func_021CD4B0(p->fC, 0x4e,
                func_021C1164(p->w1ab8, func_021D5440(a)), tag, 0x27e);
        }
    }
    i = 0;
    completed = 0;
    f.word = 0;
    for (; i < (p->f4b4)[0]; i++) {
        old = func_021D62A8((struct Unk021D62A8 *)a);
        s = (struct State_p06 * )p->f4a8;
        if (s->a == 0) {
            s->a = 1;
            s->b = 1;
        }
        func_021CD4B0(p->fC, 0x30,
            (p->f4a8)[2], (p->f4a8)[3], ((struct Obj21074 *)q)->f0, 0);
        func_021C0A4C(p, a, d, q, c, 0x1000, p->f870);
        sum += func_021C11A4(p, (u16 *)q, a, d,
            p->f870, (u8 *)p->f4b4, 0x1000, f);
        completed++;
        if (func_021D5B68(b)) break;
        if (func_021D5B68(a)) break;
        func_021C195C(p, b, 1);
        if (func_021D62A8((struct Unk021D62A8 *)a) == 2 && old != 2) break;
        if ((p->f4b4)[2] != 0 &&
            !func_021BFA60(p, a, b, (struct Q *)q)) break;
    }
    if (completed != 0) {
        func_021C15AC(p, (p->f4b4)[5]);
        func_021CD64C(p->fC, 0x5a, 0x20, completed, 0xffff0000);
    }
    if (func_021D5B68(b)) {
        func_021CD64C(p->fC, 0x5b, 0, func_021D5440(b), 0xffff0000);
    }
    if (tag != 6) {
        func_021CD4B0(p->fC, 0x4d,
            func_021C1174(p->w1ab8, func_021D5440(a)), 0x291);
    }
    p->f789 = 0x1f;
    return sum;
}













int func_021C1184(const u8 *p)
{
    return p[1] == 0;
}















/* 021C1194  ldrb r0,[r0,#3] */
u8 func_021C1194(u8 *p) { return p[3]; }














void func_021C1198(unsigned char *p, int x)
{
    if (p[5] == 3) {
        p[5] = x;
    }
}













u32 func_021C11A4(Server *p, u16 *a, u8 *b, u8 *c, u8 *d, u8 *e, u32 f, CallFlags g)
{
    u32 r;
    if ((u8)func_021C0C34(d) != 0) {
        r = func_021C11F0(p, b, c, d, a, e, f, g);
        func_021C18D4(p, b, (u8 *)a, r);
        return r;
    }
    return 0;
}












/*
 * 2026-10-05 Q10/Q10b/Q10c/G7L9 (pengy share, user-approved): body from the listing, 47 of 704 bytes off (spill
 *   slot order m/k*4 around the third count, and the 5798/5840/59C4 argument order). Facts kept: v28 is u8,
 *   021C4104 takes sa/sb as separate stack args, 021C1198 takes an int, a7 is a one-bit field struct, the last
 *   loop's byte argument is d_021F3B20[k], 021C5798 has 8 parameters (two unused).
 * pass 2 2026-10-06 P2L45: EXACT (was 47 bytes off). Closing form: variables reused as a person would. The third
 *   count reuses `cnt` (no separate cnt3), the m loop reuses `j` from the cnt2 loop, and the later loops reuse
 *   `i` (neutral). A reused variable gets a second web numbered after the declared locals, which puts the m index
 *   at the lowest slot and the k*4 temp above the count (36 B). Then `cnt` and `cnt2` as u8 (the counts are u8
 *   results): mwcc keeps the reload of a spilled narrow local below the outgoing stack stores
 *   (docs/idioms/a-reload-kept-below-outgoing-stack-stores-is-a-narrow-local.md), which fixes the
 *   5798/5840/59C4 order; u8 cnt2 fixes the cnt/cnt2 slot swap. No (u8) casts needed. EXACT in --lang c99 and c.
 */
int func_021C11F0(Server *p, u8 *x, u8 *unused, u8 *y, u16 *e, u8 *st, u32 a6, CallFlags a7)
{
    int sum;
    u8 v28;
    u8 cnt;
    u8 cnt2;
    int h;
    int i;
    int j;
    int flag;

    v28 = func_021C14B0(p->w1ab8, func_021D5440(x));
    sum = func_021C0D70(y);
    cnt = func_021C0C38(p, (List_td *)y, (u32 *)d_021F3B38, (u16 *)d_021F3B26, (u32 *)d_021F3B2C, (u8 *)d_021F3B20);
    for (i = 0; i < cnt; i++) {
        if (func_021D6D7C(d_021F3B38[i])) {
            h = func_021C4104(p, x, d_021F3B38[i], d_021F3B26[i], d_021F3B2C[i], d_021F3B20[i], e);
            func_021C14C0(p->f860, d_021F3B38[i], h, 1);
            sum -= d_021F3B26[i] - h;
        }
    }
    if (func_021C1184(st)) {
        cnt2 = func_021C0CB4(p, (const struct Q_021C0CB4 *)y, (u32 *)d_021F3B38);
        for (j = 0; j < cnt2; j++)
            func_021C15E8(p, x, d_021F3B38[j], e);
    }
    st[1] = st[1] + 1;
    cnt = func_021C0CE8(p, (const struct Q_021C0CE8 *)y, (u32 *)d_021F3B38, d_021F3B26, d_021F3B2C, d_021F3B20, d_021F3B23);
    if (cnt == 0)
        return sum;
    func_021C1788(p, (u32)e, x, cnt, (u32 *)d_021F3B38);
    flag = a7.bits.a;
    func_021C5798(p, e, cnt, (int *)d_021F3B2C, d_021F3B38, d_021F3B26, d_021F3B20, flag);
    if (func_021C1194(st) == 0)
        func_021C5840(p, cnt, (int *)d_021F3B2C, d_021F3B38, flag);
    else
        func_021C1198(st, d_021F3B20b[3]);
    func_021C59C4(p, cnt, d_021F3B38, d_021F3B20, flag);
    for (j = 0; j < cnt; j++) {
        func_021C14D0(p->f860, d_021F3B38[j], d_021F3B26[j], 0);
        func_021C1828(p, v28, x, d_021F3B38[j], (u8 *)e, d_021F3B26[j]);
        func_021D5FC0((struct UtilWork *)d_021F3B38[j], 2);
    }
    for (i = 0; i < cnt; i++) {
        if (d_021F3B23[i])
            func_021C16F8(p, d_021F3B38[i], d_021F3B23[i]);
    }
    for (i = 0; i < cnt; i++) {
        func_021C1CCC(p, e, x, d_021F3B38[i]);
        func_021C1DCC(p, (u8 *)e, (u32)x, d_021F3B38[i], d_021F3B26[i]);
        func_021C1880(p, (u8 *)e, x, d_021F3B38[i], d_021F3B26[i], 0);
        func_021C4218(p, x, d_021F3B38[i], (u8 *)e, d_021F3B2C[i], d_021F3B26[i], d_021F3B20[i], 0);
    }
    for (i = 0; i < cnt; i++)
        func_021C4F64(p, d_021F3B38[i]);
    func_021C4F64(p, x);
    return sum;
}











void func_021C14E0(Server *p, u8 *a, int b, u8 *c)
{
    u8 *r;
    u32 s;
    func_021C156C(c);
    r = func_021C157C(c);
    if (r != 0) {
        do {
            if (func_021C6B5C(p, a, r, (u8 *)b) != 0) {
                struct St *st = (struct St * )p->f4a8;
                if (st->f == 0) st->f = 1;
                s = func_021CC8D8(&p->lock, 0x197b);
                func_021C6BB8(p, a, r);
                func_021CC95C(&p->lock, s, 0x197f);
                func_021C158C(c, r);
            }
            r = func_021C159C(c);
        } while (r != 0);
    }
}














void func_021C15AC(Server *p, int k)
{
    if (k < 3) {
        func_021CD64C(p->fC, 0x5a, 0x4f, 0xffff0000);
    } else if (k > 3) {
        func_021CD64C(p->fC, 0x5a, 0x4e, 0xffff0000);
    }
}















u32 func_021C15D4(void *p, u32 n)
{
    u32 v = func_021D59B4(p, 13);
    if (n > v) n = v;
    return n;
}















/*
 * interface: Complete lock word returned in r0 at 021CC900; restore
 * 021CC95C stores the unchanged full r1 word. Scalar u32 preserves all bits.
 */
void func_021C15E8(Server *p, u8 *a, u8 *b, u16 *c)
{
    u32 s = func_021CC8D8(&p->lock, 6570);
    func_021C1624(p, a, b, c);
    func_021CC95C(&p->lock, s, 6570 + 4);
}














void func_021C1624(Server *p, u8 *a, u8 *b, u16 *c)
{
    func_021D74F8(0x19bd);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x12, c[0]);
    func_021D75EC(0x16, ((u8 *)c)[6]);
    func_021D70F0(p, 0x45);
    func_021D7540(0x19bd + 7);
}














int func_021C1678(Server *p, u8 *a, u8 *b, u32 c, u16 *d)
{
    int r;
    if (func_021D59B4(b, 13) > *d) return 0;
    func_021D74F8(0x19df);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x51, c);
    func_021D7630(0x3a, 0);
    func_021D70F0(p, 0x74);
    r = func_021D775C(0x3a);
    func_021D7540(0x19df + 7);
    if (r != 0) *d = func_021D59B4(b, 13) - 1;
    return r;
}














/*
 * The empty `case 3: break;` is what keeps the `cmp r4, #3` and the
 * unconditional branch; a plain `if (k == 3) {}` compiles differently.
 */
void func_021C16F8(Server *p, u8 *a, int k)
{
    u32 s;
    u8 n = func_021D5440(a);
    switch (k) {
    case 1:
        func_021CD64C(p->fC, 0x5b, 0x202, n, 0xffff0000);
        return;
    case 3:
        break;
    }
    s = func_021CC8D8(&p->lock, 0x1a04);
    func_021C1758(p, a, k);
    func_021CC95C(&p->lock, s, 0x1a07);
}














void func_021C1758(Server *p, u8 *q, int k)
{
    func_021D74F8(0x1a17);
    func_021D75EC(2, func_021D5440(q));
    func_021D70F0(p, 0x75);
    func_021D7540(0x1a17 + 3);
}













void func_021C1788(Server *p, u32 x, u8 *a, u32 n, u32 *arr)
{
    u32 s = func_021CC8D8(&p->lock, 6697);
    func_021C17CC(p, x, a, n, (u8 **)arr);
    func_021CC95C(&p->lock, s, 6702);
}













void func_021C17CC(Server *p, u32 x, u8 *a, u32 n, u8 **arr)
{
    u32 i;
    func_021D74F8(6719);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(5, n);
    for (i = 0; i < n; i++) {
        func_021D75EC(6 + i, func_021D5440(arr[i]));
    }
    func_021D70F0(p, 0x44);
    func_021D7540(6727);
}













/*
 * The Rec build loads q[6] and q[0] first (ldrb, ldrh) only when both are
 * read into their own locals (c6 before a0), assigned after the second
 * func_021D5440 call; reading them straight into the fields interleaves
 * loads and stores.
 */
void func_021C1828(Server *p, u8 b, u8 *x, u8 *c, u8 *q, u16 w)
{
    struct Rec_p09 r;
    u8 c6;
    u16 a0;
    u8 n = func_021D5440(x);
    u8 m = func_021D5440(c);
    c6 = q[6];
    a0 = ((struct Obj02778 *)q)->f0;
    r.a = a0;
    r.b = w;
    r.c = c6;
    r.d = n;
    r.e = b;
    func_021D6848(c, &r);
    func_021CD4B0(p->fC, 0x2d, m, n, b, q[6], ((struct Obj02778 *)q)->f0, w);
}













void func_021C1880(Server *p, u8 *q, u8 *a, u8 *b, u32 s0, int s1)
{
    switch (sub_0201C1BC(((struct Obj09968 *)q)->f0)) {
    case 7:
        func_021C2CD8(p, (u16 *)q, a, a);
        break;
    case 6:
        if (s1 == 0) {
            func_021C2CD8(p, (u16 *)q, a, b);
        }
        break;
    case 4:
        if (s1 == 0) {
            func_021C232C(p, (const u16 *)q, a, b);
        }
        break;
    }
}













void func_021C18D4(Server *p, u8 *a, u8 *q, u32 v)
{
    u32 s = func_021CC8D8(&p->lock, 6802);
    func_021C1910(p, a, q, v);
    func_021CC95C(&p->lock, s, 6802 + 3);
}













void func_021C1910(Server *p, u8 *a, u8 *q, u32 v)
{
    func_021D74F8(6823);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, ((struct Obj13323 *)q)->f0);
    func_021D75EC(0x16, q[6]);
    func_021D75EC(0x32, v);
    func_021D70F0(p, 0x4d);
    func_021D7540(6829);
}













void func_021C195C(Server *p, u8 *q, u32 n)
{
    if (func_021D5B40((struct QI *)q)) {
        u32 s = func_021CC8D8(&p->lock, 6844);
        func_021C199C(p, q, n);
        func_021CC95C(&p->lock, s, 6850);
    }
}












void func_021C199C(Server *p, u8 *q, u32 n)
{
    func_021D74F8(0x1acf);
    func_021D75EC(2, func_021D5440(q));
    func_021D75EC(0x2e, n);
    func_021D70F0(p, 0x91);
    func_021D7540(0x1acf + 4);
}












void func_021C19D8(Server *p, u8 *a, u8 *q)
{
    u32 s = func_021CC8D8(&p->lock, 6874);
    func_021C1A10(p, a, q);
    func_021CC95C(&p->lock, s, 6874 + 2);
}












void func_021C1A10(Server *p, u8 *a, u8 *q)
{
    func_021D74F8(6890);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, ((struct Obj13324 *)q)->f0);
    func_021D75EC(0x16, q[6]);
    func_021D70F0(p, 0x81);
    func_021D7540(6897);
}











void func_021C1A54(Server *p, u8 *a, u8 *b, u8 *c, u32 unused, u32 d)
{
    u32 lock;
    u8 *x;
    func_021C1CE4(p, a, (u32)b, c);
    lock = func_021CC8D8(&p->lock, 0x1b07);
    func_021C1B5C(p, b, c, a, d, 0, 0x84);
    func_021C1B5C(p, b, c, a, d, 1, 0x83);
    func_021C1B5C(p, b, c, a, d, 0, 0x85);
    func_021C1B2C(c);
    x = func_021C1B3C(c);
    while (x) {
        func_021C195C(p, x, 1);
        x = func_021C1B4C(c);
    }
    func_021C1B5C(p, b, c, a, d, 0, 0x86);
    func_021C1B5C(p, b, c, a, d, 1, 0x87);
    func_021C1C88(p, b, (u32)c, a, d);
    func_021CC95C(&p->lock, lock, 0x1b1b);
}








void func_021C1B5C(Server *p, u8 *a, u8 *b, u8 *c, u32 d, u8 e, int f)
{
    u32 sum;
    u32 n;
    u32 got;
    u32 i;
    u32 v;
    u8 *x;
    int ok;
    n = func_021C1C48(b);
    sum = 0;
    got = 0;
    func_021D74F8(0x1b2b);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x4d, d);
    func_021D75EC(0x12, ((struct Obj13325 *)c)->f0);
    func_021D75EC(0x16, c[6]);
    for (i = 0; i < n; i++) {
        x = func_021C1C58(b, i);
        if (e) ok = func_021C1C68(b, x, &v);
        else ok = func_021C1C78(b, x, &v);
        if (ok) {
            sum += v;
            func_021D75EC(got + 6, func_021D5440(x));
            got++;
        }
    }
    if (got) {
        func_021D75EC(5, got);
        func_021D7630(0x47, 0);
        func_021D7630(0x48, 0);
        func_021D75EC(0x32, sum);
        func_021D70F0(p, 0x82);
        if (!func_021D775C(0x48)) func_021D70F0(p, f);
    }
    func_021D7540(0x1b52);
}









void func_021C1C88(Server *p, u8 *a, u32 unused, u8 *q, u32 v)
{
    func_021D74F8(7009);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x4d, v);
    func_021D75EC(0x12, ((struct Obj21079 *)q)->f0);
    func_021D70F0(p, 0x88);
    func_021D7540(7014);
}









int func_021C1CCC(Server *p, u16 *x, u8 *a, u8 *q)
{
    int n;
    n = func_021C7664(p, *x, a);
    return func_021C1D60(p, q, n);
}










void func_021C1CE4(Server *p, u8 *q, u32 unused, u8 *w)
{
    u8 *t;
    if (q[6] == 9) {
        func_021C1D30(w);
        t = func_021C1D40(w);
        while (t) {
            int k = 3;
            if (func_021D62A8((struct Unk021D62A8 *)t) == 3 && func_021D6D7C(t) == 0) {
                func_021C557C(p, t, k, 1);
            }
            t = func_021C1D50(w);
        }
    }
}









int func_021C1D60(Server *p, u8 *q, u32 n)
{
    if (func_021D5BB0((struct UtilWork *)q, 5)) {
        func_021D5FC0((struct UtilWork *)q, 6);
        return 1;
    }
    if (func_021C76F4(p, q, n)) {
        func_021D5FC0((struct UtilWork *)q, 4);
        return 1;
    }
    if (n >= 100) {
        u32 s = func_021CC8D8(&p->lock, 7085);
        func_021C7780(p, q);
        func_021CC95C(&p->lock, s, 7087);
    }
    return 0;
}









void func_021C1DCC(Server *p, u8 *q, u32 a, u8 *b, u32 s)
{
    if (sub_0201C1BC(((struct Obj09967 *)q)->f0) == 8) {
        if (func_021C1E14(p, (u8 *)a, (u32)b, (u16)func_021D7B3C(s, sub_0201BD28(((struct Obj09967 *)q)->f0, 0x19)))) {
            func_021C5D88(p, b, 0x383);
        }
    }
}









int func_021C1E14(Server *p, u8 *q, u32 a, u32 b)
{
    u32 s = func_021CC8D8(&p->lock, 7154);
    int r = 0;
    u8 *t = (u8 *)func_021C78F4(p, q, (u8 *)a, b);
    if (t) {
        if (func_021C3370(p, q) == 0) {
            r = func_021C334C(p, q, (int)t, 1);
        }
    }
    func_021CC95C(&p->lock, s, 7168);
    return r;
}








/*
 *   Call +0x10 has no witness outside 021C1E74..021C2048; all concrete
 *   bytes match, and the other 39 relocation sites resolve.
 *   Verified one --thumb, no --region, dsi/1.1p1 -O4,p: EXACT, 12 bytes.
 *   typedef unsigned short u16; typedef unsigned int u32;
 *   extern u32 sub_0201BD28(u16, u32);
 * lever: a separately narrowed u8 level local avoids the extra r0-to-r2
 *   copy from narrowing an inline call argument. value * scale selects
 *   the original multiplication destination; scale * value adds a copy.
 */
int func_021C1E74(Server *p, u8 *a, u8 *b, const u8 *c, u32 d, u32 e, u32 f, int g, u16 *out)
{
    int category = func_0201C1E8(*(u16 *)c);
    int flag = 0;
    u32 result;
    u32 x;
    u32 y;
    u32 value;
    u32 factor;
    u16 scale;
    u8 level;
    func_021D74F8(0x1c21);
    func_021D75EC(0x38, d);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x45, f);
    func_021D75EC(0x16, c[6]);
    func_021D75EC(0x12, *(u16 *)c);
    func_021D75EC(0x1a, category);
    func_021D75A8(0x37, 0);
    func_021D70F0(p, 0x46);
    result = (u32)func_021D775C(0x37);
    if (result) {
        flag = 1;
    } else {
        x = func_021C728C(p, a, b, c);
        y = func_021C7374(p, a, b, c, f);
        value = func_021C7474(p, a, b, c, f);
        level = func_021D59B4(a, 15);
        value = func_021D7A44(x, y, level, value);
        if (e != 0x1000) value = func_021D7B10(value, e);
        factor = func_021D7C38(func_021C2AB0(p), c[6]);
        if (factor != 0x1000) value = func_021D7B10(value, factor);
        if (f) value *= 2;
        if (!func_021B911C(p->f4, 7)) {
            if (g) scale = 85;
            else scale = 100 - func_021D78AC(16);
            value = (u32)(value * scale) / 100u;
        }
        if (c[6] != 17) value = func_021D7B10(value, func_021C75EC(p, a, c[6]));
        value = func_021D7A6C(value, d);
        if (category == 1 && func_021D62A8((struct Unk021D62A8 *)a) == 4 && func_021D59B4(a, 17) != 62) {
            value = (u32)(50u * value) / 100u;
        }
        if (!value) value = 1;
        func_021D7674(0x35, 0x1000, 0x29, 0x20000);
        func_021D75A8(0x32, value);
        func_021D70F0(p, 0x47);
        factor = (u32)func_021D775C(0x35);
        result = func_021D7B10((u32)func_021D775C(0x32), factor);
    }
    func_021D70F0(p, 0x48);
    func_021D7540(0x1c8d);
    *out = result;
    return flag;
}









void func_021C2048(Server *p, u8 *a, u16 b, u32 c)
{
    int loc;
    int r;
    if (func_021D5B68(a) != 0)
        return;
    r = func_021C6CAC(p, a, b, c, &loc);
    if (r == 0)
        return;
    func_021C8838(p->w1ae4, 2, 378);
    func_021C8860((struct S_p12 *)p->w1ae4, func_021D5440(a));
    if (loc == 0 && func_021C20BC(p, a, r) == 0)
        return;
    func_021C20D0(p, a, r, p->w1ae4);
}








/*
 * extent: two zero alignment bytes follow the return at 0x021C20CE.
 */
int func_021C20BC(Server *p, u8 *a, int r)
{
    if (func_021C7330(p, a))
        return 1;
    return 0;
}









int func_021C20D0(Server *p, u8 *a, int c, u8 *l)
{
    int r;
    c = -c;
    if (c != 0) {
        func_021C5B74(p, a, c, 1);
        func_021D5FC0((struct UtilWork *)a, 2);
        if (l != 0) {
            func_021C99A0(p, (const struct Msg *)l);
            func_021C8810(l);
        }
        r = 1;
        func_021C195C(p, a, 1);
        if (func_021C4F64(p, a) != 0) {
            func_021BC2B0(p);
            return r;
        }
        return r;
    }
    return 0;
}







int func_021C2128(Server *p, u8 *a)
{
    int t = func_021D5B40((struct QI *)a);
    int result = 0;
    u32 s;
    u32 v;
    u16 pos;
    if (func_021C21F4(p->w1ab8, func_021D5440(a))) {
        s = func_021CC8D8(&p->lock, 0x1cea);
        if (func_021C2204(p, a, (u16)t) == 0) result = 1;
        if (result) {
            pos = func_021CD4FC((u8 *)(p->fC), 0x42);
            v = func_021CC918(&p->lock, (u16)t, 0x1cf4);
            func_021C6DD0(p, a);
            if (func_021C88E4(p) != 2) result = 0;
            func_021CC95C(&p->lock, v, 0x1cf9);
            if (result) {
                func_021CD568(p->fC, pos, 0x42, func_021D5440(a));
                if (func_021D805C((void *)((u16)t), 0x10)) func_021C2250(p, a, 0, 1);
            }
        }
        func_021CC95C(&p->lock, s, 0x1d06);
    }
    return result;
}










int func_021C2204(Server *p, u8 *a, u16 c)
{
    int r;
    func_021D74F8(7449);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x2d, c);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x90);
    r = func_021D775C(0x41);
    func_021D7540(7455);
    return r;
}











void func_021C2250(Server *p, u8 *a, u16 b, u32 c)
{
    u32 s;
    u16 t;
    int name;
    name = func_021D5440(a);
    t = (u16)(int)func_021D5B40((struct QI *)a);
    s = func_021CC8D8(&p->lock, 7469);
    func_021C7AD0(p, a, b);
    func_021CC95C(&p->lock, s, 7471);
    if (b == 0)
        func_021C60EC(p, a, 15);
    func_021DCF24(a);
    func_021CD4B0(p->fC, 0x1E, name, b);
    func_021D5B44((struct QI *)a, b);
    if (b != 0)
        func_021DCF5C(a);
    s = func_021CC8D8(&p->lock, 7485);
    func_021C7B0C(p, a);
    func_021CC95C(&p->lock, s, 7487);
    if (c != 0) {
        func_021D6730((struct QK *)a, t);
        func_021CD4B0(p->fC, 0x17, name, t);
        func_021C6134(p, a, 8);
    }
}










/*
 * extent: two zero alignment bytes follow the return at 0x021C232A.
 * interface: func_021C5BE4 reads r0/r1/r2 and forwards r2 unchanged;
 * func_021C4F64 has two arguments in its existing DIFF note.
 */
int func_021C2314(Server *p, u8 *a)
{
    func_021C5BE4(p, a, 0);
    return func_021C4F64(p, a);
}









void func_021C232C(Server *p, const u16 *a, u8 *b, u8 *c)
{
    union Slot loc;
    u32 r;
    r = func_021C236C(p, *a, b, c, &loc);
    if (r != 0 && func_021D5B68(c) == 0)
        func_021C25A4(p, b, c, *a, r, loc, 0);
}







static inline int chance(u32 n)
{
    return func_021D78AC(100) < n;
}







u32 func_021C236C(Server *p, u16 id, u8 *a, u8 *b, union Slot *dest)
{
    u32 s;
    W_021C312C w;
    union Slot out;
    u8 rate;
    u32 result;
    u8 changedRate;
    u8 veto;
    s = sub_0201BD28(id, 11);
    w = sub_0201BF58(id);
    rate = sub_0201BD28(id, 12);
    func_021D7C70(w, (u32)a, &out);
    func_021D74F8(0x1d7c);
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, id);
    func_021D75A8(0x1d, s);
    func_021D7630(0x41, 0);
    func_021D7630(0x1e, out.raw);
    func_021D75A8(0x26, rate);
    func_021D70F0(p, 0x64);
    result = func_021D775C(0x1d);
    rate = func_021D775C(0x26);
    veto = func_021D775C(0x41);
    if (result == 0xffff) result = 0;
    out.raw = func_021D775C(0x1e);
    func_021D7540(0x1d8f);
    if (!veto && result) {
        if (chance(rate)) {
            *dest = out;
            return result;
        }
        if (func_021B911C(p->f4, 0)) {
            *dest = out;
            return result;
        }
    }
    return 0;
}






void func_021C2488(Server *p, u16 id, u8 *a, u32 c)
{
    u32 s;
    W_021C312C w;
    union Slot out;
    u8 *t;
    int got;
    s = sub_0201BD28(id, 11);
    w = sub_0201BF58(id);
    got = 0;
    if (func_021C2564(c)) {
        func_021C2574(c);
        for (t = func_021C2584(c); t; t = func_021C2594(c)) {
            func_021D7C70(w, (u32)a, &out);
            if (func_021C25A4(p, a, t, id, s, out, 1)) {
                BF_021C1184 *flag = (BF_021C1184 * )p->f4a8;
                if (!flag->f) flag->f = 1;
                got = 1;
            }
        }
        if (!got && !((State_td *)p)->f) func_021C5718(p, a, id);
    } else {
        func_021C5718(p, a, id);
    }
}









int func_021C25A4(Server *p, u8 *a, u8 *b, u32 unused, u32 s0, union Slot s1, u32 s2)
{
    int t;
    func_021C8810(p->w1ae4);
    if (s0 == 0xFFFF) {
        s0 = func_021C264C(p, a, b, (u32)p->w1ae4);
        if (s0 == 0 || s0 == 0xFFFF)
            return 0;
    } else {
        func_021C26A8(p, s0, a, b, (u32)p->w1ae4);
    }
    func_021C26FC(p, a, b, s0, &s1);
    t = func_021C8828(p->w1ae4) ? 0 : 1;
    if (func_021C2758(p, b, a, s0, s1, s2, t) != 0) {
        if (t == 0) {
            func_021C99A0(p, (const struct Msg *)p->w1ae4);
            func_021C8810(p->w1ae4);
        }
        return 1;
    }
    return 0;
}










int func_021C264C(Server *p, u8 *a, u8 *b, u32 c)
{
    int r;
    func_021D74F8(7681);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x3f, c);
    func_021D75A8(0x1d, 0);
    func_021D70F0(p, 0x60);
    r = func_021D775C(0x1d);
    func_021D7540(7688);
    return r;
}










void func_021C26A8(Server *p, u32 a, u8 *b, u8 *c, u32 d)
{
    func_021D74F8(7704);
    func_021D75EC(3, func_021D5440(b));
    func_021D75EC(4, func_021D5440(c));
    func_021D75EC(0x3f, d);
    func_021D75EC(0x1d, a);
    func_021D70F0(p, 0x61);
    func_021D7540(7710);
}










void func_021C26FC(Server *p, u8 *a, u8 *b, u32 c, union Slot *d)
{
    func_021D74F8(7726);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x1d, c);
    func_021D75A8(0x1e, d->raw);
    func_021D70F0(p, 0x62);
    d->raw = func_021D775C(0x1e);
    func_021D7540(7726 + 7);
}








int func_021C2758(Server *p, u8 *x, u8 *y, int z, union Slot a, u32 b, u32 c)
{
    if (func_021C27A0(p, x, y, z, a, 0, b) == 0) {
        func_021C2910(p, x, y, z, a, c, 0, 0);
        return 1;
    }
    return 0;
}







/*
 * The fifth parameter is a one-word struct passed by value and handed on
 * to func_021C282C by value (`add r3, sp, #0x20; ldr r3, [r3]`, the
 * push-r0-r3 struct idiom); a plain u32 folds to `ldr r3, [sp, #0x20]`.
 * The caller func_021C2758 passes it as a plain u32 word. Declaring s
 * before t puts s in [sp, #8].
 */
int func_021C27A0(Server *p, u8 *x, u8 *y, int z, union Slot a, u8 b, u32 c)
{
    int r;
    u32 s;
    int t;
    r = func_021C282C(p, (struct Unk021D62A8 *)x, z, a, b);
    if (r != 0) {
        if (c != 0)
            func_021C5C74(p, x, r, z);
        return 1;
    }
    s = func_021CC8D8(&p->lock, 7779);
    t = func_021C2B3C(p, y, x, z);
    if (t != 0 && c != 0) {
        func_021C2BA4(p, x, y, z);
        p->f78a.raw |= 0x10;
    }
    func_021CC95C(&p->lock, s, 7792);
    return t;
}






int func_021C282C(Server *a, struct Unk021D62A8 *b, int c, union Slot d, u8 e)
{
    u16 t;
    if (func_021D62C4(b, c) && e != 2) return 1;
    if (c < 6 && func_021D62A8(b) && e == 0) return 3;
    if (func_021C2AB0(a) == 1 && c == 3) return 3;
    if (c == 5) {
        t = func_021D57FC(b);
        if (func_021E8D24(t, 8) || func_021E8D24(t, 3)) return 2;
    }
    if (c == 4 && func_021E8D24(func_021D57FC(b), 9)) return 2;
    if (c == 3 && func_021E8D24(func_021D57FC(b), 14)) return 2;
    if (c == 18 && func_021E8D24(func_021D57FC(b), 11)) return 2;
    if (c == 14 && func_021D62A8(b)) return 3;
    if (c == 16 && func_021D59B4((u8 *)b, 16) == 121) return 3;
    return 0;
}






void func_021C2910(Server *p, u8 *a, u8 *b, int kind, union Slot value, int f, int g, const void *m)
{
    u32 lock;
    func_021C5C1C(p, a, kind, value);
    switch (kind) {
    case 5: func_021C5480(p, a, 599); break;
    case 4: func_021C5480(p, a, 600); break;
    case 1: func_021C5480(p, a, 602); break;
    case 3: func_021C5480(p, a, 601); break;
    case 2: func_021C5480(p, a, 598); break;
    case 6: func_021C5480(p, a, 603); break;
    case 7: func_021C5480(p, a, 604); break;
    case 0: break;
    }
    if (f) {
        func_021C2AA0(kind, value, a, (struct Msg *)p->w1ae4);
        func_021C99A0(p, (struct Msg *)p->w1ae4);
        func_021C8810(p->w1ae4);
    } else if (m) func_021C99A0(p, m);
    if (kind == 3 && func_021D5444((struct QF *)a) == 492 && func_021D59B4(a, 19) == 1) {
        func_021D8510(a);
        func_021D66D8(a, 0);
        func_021CD4B0(p->fC, 79, func_021D5440(a), 0);
        func_021D8484(a);
        func_021C5D88(p, a, 222);
    }
    lock = func_021CC8D8(&p->lock, 7936);
    if (func_021D7D6C(kind)) {
        func_021C2BF0(p, a, b, kind, value.raw);
    } else if (kind == 16) {
        func_021C2CA8(p, (u8 *)((int)a));
        if (func_021D59B4(a, 17) == 127) func_021C3FDC(p, a);
    } else func_021C2C50(p, a, b, kind);
    func_021CC95C(&p->lock, lock, 7951);
    if (!g) func_021C195C(p, a, 3);
}







int func_021C2AB0(Server *p)
{
    int r;
    int t;
    func_021D74F8(7971);
    func_021D7630(0x41, 0);
    r = 0;
    func_021D70F0(p, 0x7a);
    t = func_021D775C(0x41);
    func_021D7540(7975);
    if (t == 0)
        r = func_021EF884();
    return r;
}







int func_021C2AF0(u8 *p, u8 *a)
{
    int r;
    func_021D74F8(7997);
    func_021D75EC(2, func_021D5440(a));
    func_021D7674(0x35, 2 << 11, 410, 2 << 16);
    func_021D70F0(p, 0x7B);
    r = func_021D775C(0x35);
    func_021D7540(8002);
    return r;
}







int func_021C2B3C(Server *p, u8 *a, u8 *b, u32 c)
{
    int r;
    func_021D74F8(8021);
    func_021D75EC(3, a ? func_021D5440(a) : 0x1F);
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x1D, c);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x65);
    r = func_021D775C(0x41);
    func_021D7540(8028);
    return r;
}







void func_021C2BA4(Server *p, u8 *a, u8 *b, u32 c)
{
    func_021D74F8(8042);
    func_021D75A8(4, func_021D5440(a));
    func_021D75A8(3, func_021D5440(b));
    func_021D75A8(0x1D, c);
    func_021D70F0(p, 0x67);
    func_021D7540(8047);
}







void func_021C2BF0(Server *p, u8 *a, u8 *b, u32 c, u32 d)
{
    func_021D74F8(8062);
    func_021D75EC(4, func_021D5440(a));
    func_021D75EC(3, (u8)(b ? func_021D5440(b) : 0x1F));
    func_021D75EC(0x1D, c);
    func_021D75EC(0x1E, d);
    func_021D70F0(p, 0x68);
    func_021D7540(8071);
}







void func_021C2C50(Server *p, u8 *a, u8 *b, u32 c)
{
    func_021D74F8(8085);
    func_021D75EC(4, func_021D5440(a));
    func_021D75EC(3, (u8)(b ? func_021D5440(b) : 0x1F));
    func_021D75EC(0x1D, c);
    func_021D70F0(p, 0x69);
    func_021D7540(8093);
}






void func_021C2CA8(Server *p, u8 *a)
{
    func_021D74F8(8105);
    func_021D75EC(2, func_021D5440(a));
    func_021D70E4(p, 0x6a);
    func_021D7540(8108);
}






/*
 * extent: two bytes of zero alignment padding at 0x021C2D0E.
 */
void func_021C2CD8(Server *p, u16 *q, u8 *a, u8 *b)
{
    if (func_021D5B68(b) == 0) {
        if (func_021C2D10(p, q, a, b) != 0)
            func_021C2E64(p, q, a, b, 0);
    }
}






int func_021C2D10(Server *p, u16 *q, u8 *b, u8 *c)
{
    u8 s, x, y;
    u32 t;
    s = sub_0201BD28(*q, 0x12);
    func_021D74F8(8142);
    func_021D75EC(3, func_021D5440(b));
    func_021D75EC(4, func_021D5440(c));
    func_021D75EC(0x12, *q);
    t = 0;
    func_021D7630(0x41, 0);
    func_021D75A8(0x26, s);
    func_021D70F0(p, 0x51);
    x = func_021D775C(0x41);
    y = func_021D775C(0x26);
    func_021D7540(8152);
    if (x == 0) {
        if (func_021D78AC(100) < y)
            t = 1;
        if (t)
            return 1;
        if (func_021B911C((void *)(p->f4), 0) != 0)
            return 1;
    }
    return 0;
}





void func_021C2DC4(Server *p, u32 a, u32 b, u32 c)
{
    u32 t;
    func_021C2E1C(c);
    for (t = func_021C2E2C(c); t != 0; t = func_021C2E3C(c)) {
        if (func_021C2E64(p, (const u16 *)a, (u8 *)b, (u8 *)t, 1) != 0) {
            BF_021C2AB0 *f = (BF_021C2AB0 * )p->f4a8;
            if (!f->f)
                f->f = 1;
        }
    }
}
