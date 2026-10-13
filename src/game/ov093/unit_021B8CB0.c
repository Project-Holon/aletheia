/*
 * file:     unit_021B8CB0.c
 * unit:     yes
 * function: func_021B8CB0, func_021B8CE8, func_021B8CFC, func_021B8D08, func_021B8D38, func_021B8D8C, func_021B8DC0, func_021B8DDC, func_021B8DE4, func_021B8DEC, func_021B8E28, func_021B8E70, func_021B8ED8, func_021B8F38, func_021B8F5C, func_021B8F7C, func_021B8FC0, func_021B8FE4, func_021B8FF4, func_021B9000, func_021B9010, func_021B902C, func_021B904C, func_021B9064, func_021B9090, func_021B90BC, func_021B90E8, func_021B90F0, func_021B90F8, func_021B9114, func_021B911C, func_021B9120, func_021B916C, func_021B917C, func_021B9184, func_021B919C, func_021B91E4, func_021B9210, func_021B9234, func_021B9244, func_021B92A0, func_021B92B0, func_021B92D4, func_021B9358, func_021B937C, func_021B93E0, func_021B9424, func_021B9460, func_021B9634, func_021B9674, func_021B969C, func_021B97A0, func_021B985C, func_021B9864, func_021B98A4, func_021B98AC, func_021B990C, func_021B9920, func_021B9934, func_021B9940, func_021B994C, func_021B997C, func_021B99B8, func_021B99C0, func_021B99E0, func_021B99F0, func_021B9A00, func_021B9A24, func_021B9A40, func_021B9A50, func_021B9A5C, func_021B9A6C, func_021B9AB0, func_021B9AC8, func_021B9AE0, func_021B9AEC, func_021B9AF8, func_021B9B04, func_021B9B10, func_021B9B40, func_021B9B54, func_021B9B60, func_021B9B94, func_021B9B98, func_021B9BC4, func_021B9BF0, func_021B9C00, func_021B9C10, func_021B9C24, func_021B9C50, func_021B9C98, func_021B9CBC, func_021B9CE8, func_021B9D10, func_021B9DB8, func_021B9DE8, func_021B9E38, func_021B9E7C, func_021B9EF0, func_021B9F70, func_021B9F84, func_021B9FAC, func_021B9FBC, func_021BA004, func_021BA020, func_021BA02C, func_021BA064, func_021BA080, func_021BA08C, func_021BA094, func_021BA0CC, func_021BA128, func_021BA178, func_021BA1A8, func_021BA1B4, func_021BA1CC, func_021BA1E4, func_021BA1EC, func_021BA20C, func_021BA238, func_021BA250, func_021BA2D4, func_021BA2E4, func_021BA534, func_021BA54C, func_021BA5C4, func_021BA5D0, func_021BA5D8, func_021BA618, func_021BA648, func_021BA670, func_021BA698, func_021BA6C0, func_021BA710, func_021BA73C, func_021BA7F8, func_021BA820, func_021BA82C, func_021BA878
 * address:  0x021B8CB0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from btl_server.c (lane L189): tail of the BtlMain accessor module (struct with clients at +0x10, party at +0x1b0); no __FILE__ string of its own; the head of the module is in the unit_021B7488..unit_021B8B78 files.
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
 *   GPOWER_ApplyPrizeMoney  0x0201119C  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C274  0x0200C274  thumb
 *   func_021D7FF8  0x021D7FF8  thumb  ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_021B8714  0x021B8714  thumb  ov093
 *   NATSUKI_Calc  0x0201B7A0  thumb
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
 *   POKEPARTY_Init 0x0201A948 thumb
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
 *   func_021D5B7C 0x021D5B7C thumb ov093
 *   func_021B8B78  0x021B8B78  thumb  ov093
 *   func_021D5854  0x021D5854  thumb  ov093
 *   func_020307B0  0x020307B0  arm
 *   func_0200846C  0x0200846C  thumb
 *   func_02008494  0x02008494  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008510  0x02008510  thumb
 *   PMSI_PARAM_ClearSentence  0x0202428C  thumb
 *   func_02045874  0x02045874  arm
 *   func_02082D44  0x02082D44  arm
 *   PMSI_PARAM_Copy  0x02024570  thumb
 *   func_020457B0  0x020457B0  arm
 *   STRBUF_SetChars  0x02045A00  arm
 *   COMM_PLAYER_SUPPORT_GetCurrent  0x0202E7DC  thumb
 *   func_0201A920 0x0201A920 thumb
 *   BTL_SETUP_CheckStatusFlag  0x02013158  thumb
 *   sub_02008DF0 0x02008DF0 thumb
 *   sub_02008DAC 0x02008DAC thumb
 *   func_021B6818 0x021B6818 thumb ov093
 *   NATSUKI_CalcUseItem  0x0201B7B4  thumb
 *   NATSUKI_CalcParty 0x0201B818 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_021D7F60 0x021D7F60 thumb ov093
 *   func_021D805C 0x021D805C thumb ov093
 *   func_021D62A8 0x021D62A8 thumb ov093
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021D826C  0x021D826C  thumb  ov093
 *   func_021D8270  0x021D8270  thumb  ov093
 *   func_021D787C  0x021D787C  thumb  ov093
 *   func_021B68D8  0x021B68D8  thumb  ov093
 *   func_021E9034  0x021E9034  thumb  ov093
 *   func_021E8E28  0x021E8E28  thumb  ov093
 *   func_021E8F20  0x021E8F20  thumb  ov093
 *   func_021D54B4 0x021D54B4 thumb ov093
 *   func_02030734 0x02030734 arm
 *   d_021F3A60 0x021F3A60 data a4
 *   func_021EEA58  0x021EEA58  thumb  ov093
 *   func_02045808  0x02045808  arm
 *   func_021EEAE0  0x021EEAE0  thumb  ov093
 *   func_021B86C0 0x021B86C0 thumb ov093
 *   func_021EEB64  0x021EEB64  thumb  ov093
 *   func_021B85A8  0x021B85A8  thumb  ov093
 *   func_021D8454  0x021D8454  thumb  ov093
 *   func_021EE9A4  0x021EE9A4  thumb  ov093
 *   func_021B86DC  0x021B86DC  thumb  ov093
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
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
 *   GAME_BEACON_SetPokeLevelUp 0x02027268 thumb
 *   GAME_BEACON_SetPokeCapture 0x020271DC thumb
 *   SHINKA_CHECK_OpenHandle 0x0201B70C thumb
 *   d_021F3A70 0x021F3A70 data a4
 *   func_021D6EAC 0x021D6EAC thumb ov093
 *   func_021EF874 0x021EF874 thumb ov093
 *   func_0689CFF0 0x0689CFF0 thumb ov095
 *   func_0689D118 0x0689D118 thumb ov095
 *   func_0689D1FC 0x0689D1FC thumb ov095
 *   func_02082BCC 0x02082BCC arm
 *   func_021D8230 0x021D8230 thumb ov093
 *   func_06898BFC 0x06898BFC thumb ov095
 *   func_02049238 0x02049238 arm
 *   func_021B8750 0x021B8750 thumb ov093
 *   func_0689D134 0x0689D134 thumb ov095
 *   func_021D6EE8  0x021D6EE8  thumb  ov093
 *   func_021D74E4  0x021D74E4  thumb  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_0689D174 0x0689D174 thumb ov095
 *   func_021B8BC4  0x021B8BC4  thumb  ov093
 *   func_0689D558 0x0689D558 thumb ov095
 *   func_021EF948  0x021EF948  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D8548  0x021D8548  thumb  ov093
 *   func_021DCFB4  0x021DCFB4  thumb  ov093
 *   func_0689D338 0x0689D338 thumb ov095
 *   func_021E02DC  0x021E02DC  thumb  ov093
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
 *   func_0689D588 0x0689D588 thumb ov095
 *   func_021B86E4 0x021B86E4 thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   POKE_TOOL_IsOwnedByPlayer 0x02018480 thumb
 *   func_021B871C 0x021B871C thumb ov093
 *   func_021B85A0 0x021B85A0 thumb ov093
 *   POKE_TOOL_IsBoxOwnedByPlayer 0x02018488 thumb
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_0689D5C8 0x0689D5C8 thumb ov095
 *   func_021D82FC  0x021D82FC  thumb  ov093
 *   func_0689CD40 0x0689CD40 thumb ov095
 *   func_0689CD38 0x0689CD38 thumb ov095
 *   func_0689CC70 0x0689CC70 thumb ov095
 *   func_0689D4F0 0x0689D4F0 thumb ov095
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   func_021D8244 0x021D8244 thumb ov093
 *   func_0689C68C 0x0689C68C thumb ov095
 *   func_021D8484 0x021D8484 thumb ov093
 *   func_021DCF5C 0x021DCF5C thumb ov093
 *   func_021D63EC 0x021D63EC thumb ov093
 *   func_021D6580 0x021D6580 thumb ov093
 *   func_0689D320 0x0689D320 thumb ov095
 *   func_0689CB3C 0x0689CB3C thumb ov095
 *   func_0689CB48 0x0689CB48 thumb ov095
 *   func_0689CF24 0x0689CF24 thumb ov095
 *   func_0689CC84 0x0689CC84 thumb ov095
 *   func_0689CC8C 0x0689CC8C thumb ov095
 *   func_021D70FC 0x021D70FC thumb ov093
 *   func_021D64F0  0x021D64F0  thumb  ov093
 *   func_0689D2F8 0x0689D2F8 thumb ov095
 *   func_021D6314  0x021D6314  thumb  ov093
 *   func_021E8B80  0x021E8B80  thumb  ov093
 *   func_021D55A0  0x021D55A0  thumb  ov093
 *   func_021D5C08 0x021D5C08 thumb ov093
 *   func_021D80BC 0x021D80BC thumb ov093
 *   func_021D82D0 0x021D82D0 thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_0689CEE4 0x0689CEE4 thumb ov095
 *   func_0689CD78 0x0689CD78 thumb ov095
 *   func_0689CD48 0x0689CD48 thumb ov095
 *   func_0689D01C 0x0689D01C thumb ov095
 *   func_021D6744 0x021D6744 thumb ov093
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   func_021D7394 0x021D7394 thumb ov093
 *   func_021E03D8 0x021E03D8 thumb ov093
 *   func_021D73D4 0x021D73D4 thumb ov093
 *   d_021EFDB8 0x021EFDB8 data a2
 *   func_021D6E74 0x021D6E74 thumb ov093
 *   func_021D6E40 0x021D6E40 thumb ov093
 *   WAZA_TOOL_GetCategory 0x0201C1BC thumb
 *   func_0689CD50 0x0689CD50 thumb ov095
 *   func_0689D050 0x0689D050 thumb ov095
 *   func_0689CC14 0x0689CC14 thumb ov095
 *   func_021D6D7C  0x021D6D7C  thumb  ov093
 *   func_0689D59C 0x0689D59C thumb ov095
 *   func_021D62D8  0x021D62D8  thumb  ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021D7908 0x021D7908 thumb ov093
 *   func_021E896C 0x021E896C thumb ov093
 *   func_021D5C30 0x021D5C30 thumb ov093
 *   func_021E899C  0x021E899C  thumb  ov093
 *   WAZA_TOOL_IsDamaging 0x0201C314 thumb
 *   func_021D5584 0x021D5584 thumb ov093
 *   func_021D67B8 0x021D67B8 thumb ov093
 *   func_021D67A8 0x021D67A8 thumb ov093
 *   func_021EF91C 0x021EF91C thumb ov093
 *   func_021D7AF0 0x021D7AF0 thumb ov093
 *   func_021D61A8  0x021D61A8  thumb  ov093
 *   func_021D6130  0x021D6130  thumb  ov093
 *   func_021D7D18 0x021D7D18 thumb ov093
 *   func_021D69A0  0x021D69A0  thumb  ov093
 *   func_021D5608  0x021D5608  thumb  ov093
 *   func_021D56CC  0x021D56CC  thumb  ov093
 *   func_0689CDCC 0x0689CDCC thumb ov095
 *   func_0689CE58 0x0689CE58 thumb ov095
 *   func_021B8590 0x021B8590 thumb ov093
 *   func_0689CBB8 0x0689CBB8 thumb ov095
 *   d_021F3B2C  0x021F3B2C  data  ov093  a4
 *   d_021F3B20  0x021F3B20  data  ov093  a4
 *   d_021F3B38  0x021F3B38  data  a4
 *   d_021F3B26  0x021F3B26  data  ov093  a4
 *   d_021F3B23  0x021F3B23  data  ov093  a4
 *   d_021F3B20b 0x021F3B20  data  ov093  a4
 *   func_021D6848  0x021D6848  thumb  ov093
 *   WAZA_TOOL_GetCategory   0x0201C1BC  thumb
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_0689CCF8 0x0689CCF8 thumb ov095
 *   func_0689CCB4 0x0689CCB4 thumb ov095
 *   sub_0201BD28   0x0201BD28  thumb
 *   func_021D7B3C  0x021D7B3C  thumb  ov093
 *   WAZA_TOOL_GetDamageType 0x0201C1E8 thumb
 *   func_021D7A44 0x021D7A44 thumb ov093
 *   func_021D7C38 0x021D7C38 thumb ov093
 *   func_021D7A6C 0x021D7A6C thumb ov093
 *   func_021D5B44  0x021D5B44  thumb  ov093
 *   func_021DCF24  0x021DCF24  thumb  ov093
 *   func_021D6730  0x021D6730  thumb  ov093
 *   WAZA_TOOL_GetSickCont 0x0201BF58 thumb
 *   func_021D7C70 0x021D7C70 thumb ov093
 *   func_021D57FC 0x021D57FC thumb ov093
 *   func_021E8D24 0x021E8D24 thumb ov093
 *   func_0689C364 0x0689C364 thumb ov095
 *   func_021D8510 0x021D8510 thumb ov093
 *   func_021D66D8 0x021D66D8 thumb ov093
 *   func_021D7D6C 0x021D7D6C thumb ov093
 *   func_021EF884  0x021EF884  thumb  ov093
 *   func_021D70E4 0x021D70E4 thumb ov093
 *   WAZA_TOOL_GetRankEffectCount 0x0201C020 thumb
 *   WAZA_TOOL_GetRankEffect  0x0201C0BC  thumb
 *   func_021D5D14 0x021D5D14 thumb ov093
 *   func_021D5B48  0x021D5B48  thumb  ov093
 *   func_021D7AD4 0x021D7AD4 thumb ov093
 *   func_021D5FB8  0x021D5FB8  thumb  ov093
 *   func_021D6D90  0x021D6D90  thumb  ov093
 *   func_0689C7A4 0x0689C7A4 thumb ov095
 *   WAZA_TOOL_GetWeather  0x0201C184  thumb
 *   func_021EF894 0x021EF894 thumb ov093
 *   func_021EF8A4 0x021EF8A4 thumb ov093
 *   func_021EF8C8  0x021EF8C8  thumb  ov093
 *   func_021E8A98  0x021E8A98  thumb  ov093
 *   func_021EF8F8  0x021EF8F8  thumb  ov093
 *   func_0689C954 0x0689C954 thumb ov095
 *   func_021D66D0 0x021D66D0 thumb ov093
 *   func_021D8564 0x021D8564 thumb ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021D6D5C  0x021D6D5C  thumb  ov093
 *   func_021D6D9C  0x021D6D9C  thumb  ov093
 *   func_021D6D70  0x021D6D70  thumb  ov093
 *   func_021D6408 0x021D6408 thumb ov093
 *   func_021D6E88 0x021D6E88 thumb ov093
 *   func_021D701C 0x021D701C thumb ov093
 *   func_021B8630 0x021B8630 thumb ov093
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   COMM_PLAYER_SUPPORT_GetMode 0x0202E7E0 thumb
 *   COMM_PLAYER_SUPPORT_SavePreviousAndSuspend 0x0202E7E4 thumb
 *   func_0689C9F8 0x0689C9F8 thumb ov095
 *   func_0689B7A8 0x0689B7A8 thumb ov095
 *   func_021D6064 0x021D6064 thumb ov093
 *   func_021D806C 0x021D806C thumb ov093
 *   func_0689B8CC 0x0689B8CC thumb ov095
 *   func_06898D54 0x06898D54 thumb ov095
 *   func_021EF934 0x021EF934 thumb ov093
 *   func_021C4C40 0x021C4C40 thumb ov093
 *   func_021EF8B8 0x021EF8B8 thumb ov093
 *   func_021D7BD4 0x021D7BD4 thumb ov093
 *   func_0689D15C 0x0689D15C thumb ov095
 *   func_021D646C 0x021D646C thumb ov093
 *   func_021B8640  0x021B8640  thumb  ov093
 *   func_0689D5FC 0x0689D5FC thumb ov095
 *   func_021D8538 0x021D8538 thumb ov093
 *   func_021DCFA4 0x021DCFA4 thumb ov093
 *   func_021E0434 0x021E0434 thumb ov093
 *   func_021D6264 0x021D6264 thumb ov093
 *   func_021EF90C 0x021EF90C thumb ov093
 *   func_021B85EC 0x021B85EC thumb ov093
 *   func_0689D1A0 0x0689D1A0 thumb ov095
 *   func_0689D184 0x0689D184 thumb ov095
 *   func_0689D1BC 0x0689D1BC thumb ov095
 *   func_021D69B8 0x021D69B8 thumb ov093
 *   func_021D61F0  0x021D61F0  thumb  ov093
 *   func_021D6238  0x021D6238  thumb  ov093
 *   func_021D7E10  0x021D7E10  thumb  ov093
 *   func_021D5DC0 0x021D5DC0 thumb ov093
 *   func_021D5E38 0x021D5E38 thumb ov093
 *   func_021D5FA4  0x021D5FA4  thumb  ov093
 *   func_021D6034  0x021D6034  thumb  ov093
 *   func_021E8A78  0x021E8A78  thumb  ov093
 *   func_021D5F90 0x021D5F90 thumb ov093
 *   func_021D56A0  0x021D56A0  thumb  ov093
 *   func_021D5674  0x021D5674  thumb  ov093
 *   func_021D5FE4 0x021D5FE4 thumb ov093
 *   func_021D6008 0x021D6008 thumb ov093
 *   WAZA_TOOL_GetType   0x0201C1C8  thumb
 *   WAZA_TOOL_GetDamageType   0x0201C1E8  thumb
 *   WAZA_TOOL_IsAlwaysHit  0x0201C1F4  thumb
 *   WAZA_TOOL_IsAlwaysCritical  0x0201C284  thumb
 *   func_021D5F14  0x021D5F14  thumb  ov093
 *   func_021D7930  0x021D7930  thumb  ov093
 *   func_021E8CFC 0x021E8CFC thumb ov093
 *   func_021E8D04 0x021E8D04 thumb ov093
 *   func_021E8DA8 0x021E8DA8 thumb ov093
 *   func_021D79E8 0x021D79E8 thumb ov093
 *   func_021D5814  0x021D5814  thumb  ov093
 *   func_0689C6E4 0x0689C6E4 thumb ov095
 *   func_0689C540 0x0689C540 thumb ov095
 *   func_021D794C  0x021D794C  thumb  ov093
 *   func_021D7BA4  0x021D7BA4  thumb  ov093
 *   WAZA_TOOL_GetPower  0x0201C1D8  thumb
 *   func_021D5AD8 0x021D5AD8 thumb ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021D7B2C  0x021D7B2C  thumb  ov093
 *   func_021B86A0 0x021B86A0 thumb ov093
 *   func_0689D5F4 0x0689D5F4 thumb ov095
 *   func_021B8670  0x021B8670  thumb  ov093
 *   SHINKA_CHECK_GetRowParam 0x0201B718 thumb
 *   func_06898CF4  0x06898CF4  thumb  ov095
 *   func_06898CE0 0x06898CE0 thumb ov095
 *   func_068982AC  0x068982AC  thumb
 *   func_021D67E8 0x021D67E8 thumb ov093
 *   func_021D55D8  0x021D55D8  thumb  ov093
 *   func_0689C464 0x0689C464 thumb ov095
 *   func_021D5EA8  0x021D5EA8  thumb  ov093
 *   func_021D5EFC 0x021D5EFC thumb ov093
 *   func_021D5F08  0x021D5F08  thumb  ov093
 *   func_021D5970 0x021D5970 thumb ov093
 *   func_0689C9C0 0x0689C9C0 thumb ov095
 *   func_021D66B0  0x021D66B0  thumb  ov093
 *   func_021D6440 0x021D6440 thumb ov093
 *   func_06898C10 0x06898C10 thumb ov095
 *   func_06898D10 0x06898D10 thumb ov095
 *   func_021EF8E8 0x021EF8E8 thumb ov093
 *   func_068981F0 0x068981F0 thumb ov095
 *   func_0689C974 0x0689C974 thumb ov095
 *   func_021D6738 0x021D6738 thumb ov093
 *   func_021DCF78  0x021DCF78  thumb  ov093
 *   func_021DCF9C  0x021DCF9C  thumb  ov093
 *   func_021D5734  0x021D5734  thumb  ov093
 *   func_021D65C8  0x021D65C8  thumb  ov093
 *   func_021D67D8 0x021D67D8 thumb ov093
 *   func_021D6C50 0x021D6C50 thumb ov093
 *   func_021D6C2C  0x021D6C2C  thumb  ov093
 *   func_021D6D54  0x021D6D54  thumb  ov093
 *   func_021B8C38 0x021B8C38 thumb ov093
 *   func_021D7F00 0x021D7F00 thumb ov093
 *   func_021B8C50 0x021B8C50 thumb ov093
 *   func_021D7EB4 0x021D7EB4 thumb ov093
 *   func_021D6E04 0x021D6E04 thumb ov093
 *   func_021D6E0C 0x021D6E0C thumb ov093
 *   func_02008564 0x02008564 thumb arm9
 *   GPOWER_ApplyExpRate 0x02011168 thumb arm9
 *   _ffltu         0x0209BE04  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_0207C7B4  0x0207C7B4  arm
 *   func_021D6B6C  0x021D6B6C  thumb  ov093
 *   g_021EFDC0      0x021EFDC0  data  ov093
 *   func_02019C90   0x02019C90  thumb arm9
 *   POKE_TOOL_DecodePartyParam   0x02017D30  thumb arm9
 *   POKE_TOOL_EncodePartyParam   0x02017D70  thumb arm9
 *   data_021EFDE4 0x021EFDE4 data a4
 *   func_021B8724 0x021B8724 thumb ov093
 *   func_021D6E24 0x021D6E24 thumb ov093
 *   GPOWER_ApplyCaptureRate 0x020111BC thumb
 *   FX_Div 0x0207C768 arm
 *   FX_Sqrt 0x0207C7B4 arm
 *   _ll_mul 0x0209C054 arm
 *   func_021B873C  0x021B873C  thumb  ov093
 *   TIMEZONE_GetTimeZoneOfHour 0x020113F0 thumb
 *   func_0689C9A0 0x0689C9A0 thumb ov095
 *   _fflt 0x0209BDBC arm
 *   _s32_div_f 0x0209C0A4 arm
 *   func_021E8940  0x021E8940  thumb  ov093
 *   func_021D5F38  0x021D5F38  thumb  ov093
 *   func_021D5450  0x021D5450  thumb  ov093
 *   func_021D5568  0x021D5568  thumb  ov093
 *   func_021D54D0  0x021D54D0  thumb  ov093
 *   func_0689C9E4 0x0689C9E4 thumb ov095
 *   func_0689C8FC 0x0689C8FC thumb ov095
 *   func_021E869C  0x021E869C  thumb  ov093
 *   func_0689D1D4 0x0689D1D4 thumb ov095
 *   d_021EFE9C     0x021EFE9C  data  a4
 *   data_021F3A84 0x021F3A84 data
 *   func_02034714 0x02034714 arm
 *   data_021EFF14  0x021EFF14  data  ov093
 *   data_021F3B44  0x021F3B44  data  ov093
 *   d_021F3A88 0x021F3A88 data a4
 *   func_021D3F04 0x021D3F04 thumb ov093
 *   func_021D3D9C 0x021D3D9C thumb ov093
 *   func_02187F00 0x02187F00 thumb ov096
 *   func_021EE5E4 0x021EE5E4 thumb ov093
 *   func_021EE600 0x021EE600 thumb ov093
 *   func_02188080 0x02188080 thumb ov096
 *   func_021EE63C 0x021EE63C thumb ov093
 *   func_021EE830 0x021EE830 thumb ov093
 *   func_021D3F48 0x021D3F48 thumb ov093
 *   func_021EE674 0x021EE674 thumb ov093
 *   func_021EEBDC 0x021EEBDC thumb ov093
 *   func_021D3F64 0x021D3F64 thumb ov093
 *   func_021D3F88 0x021D3F88 thumb ov093
 *   func_021D3FDC 0x021D3FDC thumb ov093
 *   func_021EEBE8 0x021EEBE8 thumb ov093
 *   func_021EEC20 0x021EEC20 thumb ov093
 *   func_021D3FAC 0x021D3FAC thumb ov093
 *   func_021D3FC4 0x021D3FC4 thumb ov093
 *   func_021D3F4C 0x021D3F4C thumb ov093
 *   func_021EEC4C 0x021EEC4C thumb ov093
 *   func_021D3F60 0x021D3F60 thumb ov093
 *   GFL_USE_SetPlayersAudible 0x02005CA4 thumb
 *   PM_VOICE_ResetMasterVolume 0x02006740 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   func_021D3FA8 0x021D3FA8 thumb ov093
 *   PM_VOICE_SetMasterVolume 0x02006734 thumb
 *   func_021D3F98 0x021D3F98 thumb ov093
 *   func_021EAE24 0x021EAE24 thumb ov093
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   func_021F88BC 0x021F88BC thumb ov094
 *   func_021F8678 0x021F8678 thumb ov094
 *   func_021EAE34 0x021EAE34 thumb ov093
 *   func_021EAE74 0x021EAE74 thumb ov093
 *   d_021EFFEC 0x021EFFEC data a4
 *   func_021F8524 0x021F8524 thumb ov094
 *   func_021E90A0  0x021E90A0  thumb  ov093
 *   func_021E90D0  0x021E90D0  thumb  ov093
 *   func_021F84E8  0x021F84E8  thumb  ov094
 *   func_021F8504  0x021F8504  thumb  ov094
 *   func_021EAEA8  0x021EAEA8  thumb  ov093
 *   func_021EE688  0x021EE688  thumb  ov093
 *   func_021D3F54  0x021D3F54  thumb  ov093
 *   func_021EAA00  0x021EAA00  thumb  ov093
 *   func_021EAA5C  0x021EAA5C  thumb  ov093
 *   func_021EAA34  0x021EAA34  thumb  ov093
 *   func_021EAF18  0x021EAF18  thumb  ov093
 *   func_021EAF50  0x021EAF50  thumb  ov093
 *   func_021EAF78  0x021EAF78  thumb  ov093
 *   func_021EE6B8 0x021EE6B8 thumb ov093
 *   func_021D3FD0 0x021D3FD0 thumb ov093
 *   func_021EA614 0x021EA614 thumb ov093
 *   func_021EA710 0x021EA710 thumb ov093
 *   func_021D8434 0x021D8434 thumb ov093
 *   func_021EAE44 0x021EAE44 thumb ov093
 *   func_021EAE54 0x021EAE54 thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_021D81F8 0x021D81F8 thumb ov093
 *   func_021EA65C 0x021EA65C thumb ov093
 *   func_021E9760 0x021E9760 thumb ov093
 *   func_021E979C 0x021E979C thumb ov093
 *   func_021E97A4 0x021E97A4 thumb ov093
 *   func_021E9964 0x021E9964 thumb ov093
 *   func_0689CB08 0x0689CB08 thumb ov095
 *   func_021E9974 0x021E9974 thumb ov093
 *   func_021E9954 0x021E9954 thumb ov093
 *   func_021F7F58 0x021F7F58 thumb ov094
 *   func_021F7998 0x021F7998 thumb ov094
 *   func_021EA6B0 0x021EA6B0 thumb ov093
 *   func_021D7F38 0x021D7F38 thumb ov093
 *   func_021F87EC 0x021F87EC thumb ov094
 *   func_021F8774 0x021F8774 thumb ov094
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_0202A298 0x0202A298 thumb
 *   func_021D7B60 0x021D7B60 thumb ov093
 *   d_021EFF78 0x021EFF78 data ov093 a2
 *   func_021E97BC 0x021E97BC thumb ov093
 *   func_021E9808 0x021E9808 thumb ov093
 *   func_021E98AC 0x021E98AC thumb ov093
 *   func_021E98B4 0x021E98B4 thumb ov093
 *   func_021D832C 0x021D832C thumb ov093
 *   func_021D83FC 0x021D83FC thumb ov093
 *   func_021D7EF0 0x021D7EF0 thumb ov093
 *   func_021E98BC 0x021E98BC thumb ov093
 *   func_021E9920 0x021E9920 thumb ov093
 *   func_021E98E8 0x021E98E8 thumb ov093
 *   func_021E9858 0x021E9858 thumb ov093
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021E9CE0  0x021E9CE0  thumb  ov093
 *   func_021E9B14  0x021E9B14  thumb  ov093
 *   func_021E9B20  0x021E9B20  thumb  ov093
 *   func_021E9A78 0x021E9A78 thumb ov093
 *   func_0689CB14 0x0689CB14 thumb ov095
 *   func_0689CB1C 0x0689CB1C thumb ov095
 *   func_021D8394 0x021D8394 thumb ov093
 *   func_021E9D04 0x021E9D04 thumb ov093
 *   func_021E9E70 0x021E9E70 thumb ov093
 *   func_021E9E80 0x021E9E80 thumb ov093
 *   func_021EA01C 0x021EA01C thumb ov093
 *   func_021EA044 0x021EA044 thumb ov093
 *   func_021EA030 0x021EA030 thumb ov093
 *   func_021EA04C 0x021EA04C thumb ov093
 *   func_021D8358 0x021D8358 thumb ov093
 *   func_021EA058 0x021EA058 thumb ov093
 *   func_021EA720 0x021EA720 thumb ov093
 *   func_021EABC4 0x021EABC4 thumb ov093
 *   func_021EAC54 0x021EAC54 thumb ov093
 *   func_021D8414 0x021D8414 thumb ov093
 *   func_021EA7FC  0x021EA7FC  thumb  ov093
 *   func_021EA814  0x021EA814  thumb  ov093
 *   func_021D8444  0x021D8444  thumb  ov093
 *   func_021D67C4  0x021D67C4  thumb  ov093
 *   func_021D5750 0x021D5750 thumb ov093
 *   func_021EFCE4 0x021EFCE4 thumb ov093
 *   func_021EFC1C 0x021EFC1C thumb ov093
 *   func_021E8AFC 0x021E8AFC thumb ov093
 *   func_021D631C 0x021D631C thumb ov093
 *   WAZA_TOOL_GetType 0x0201C1C8 thumb
 *   func_021D799C 0x021D799C thumb ov093
 *   func_021D6940 0x021D6940 thumb ov093
 *   d_021EFFC2 0x021EFFC2 data ov093 a2
 *   func_021D5C44  0x021D5C44  thumb  ov093
 *   func_021D7F2C 0x021D7F2C thumb ov093
 *   func_021D3DC4 0x021D3DC4 thumb ov093
 *   func_021880BC 0x021880BC thumb ov096
 *   func_02187FB0 0x02187FB0 thumb ov096
 *   func_02188134 0x02188134 thumb ov096
 *   func_02188140 0x02188140 thumb ov096
 *   func_0689CA98 0x0689CA98 thumb ov095
 *   func_0689CAB0 0x0689CAB0 thumb ov095
 *   func_0689CAE0 0x0689CAE0 thumb ov095
 *   func_021D83C4 0x021D83C4 thumb ov093
 *   func_021EE608  0x021EE608  thumb  ov093
 *   func_021EE638  0x021EE638  thumb  ov093
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   func_021F878C   0x021F878C  thumb ov094
 *   func_021EA600 0x021EA600 thumb ov093
 *   PMSI_PARAM_IsEnabled  0x02024450  thumb
 *   PMSI_PARAM_ToString  0x0202435C  thumb
 *   func_021EA5E4  0x021EA5E4  thumb  ov093
 *   STRBUF_Delete   0x02045808  arm
 *   func_021EA5F0  0x021EA5F0  thumb  ov093
 *   func_02082A90 0x02082A90 arm
 *   func_021EA824 0x021EA824 thumb ov093
 *   d_021F00DC 0x021F00DC data a4
 *   func_021EA458  0x021EA458  thumb  ov093
 *   func_021EA478  0x021EA478  thumb  ov093
 *   func_021EA488 0x021EA488 thumb ov093
 *   func_021EA4C4 0x021EA4C4 thumb ov093
 *   func_021EA678  0x021EA678  thumb  ov093
 *   func_020061E4  0x020061E4  thumb
 *   func_021EA694  0x021EA694  thumb  ov093
 *   func_021EA6F4  0x021EA6F4  thumb  ov093
 *   func_021D80A8  0x021D80A8  thumb  ov093
 *   func_021EA0A0 0x021EA0A0 thumb ov093
 *   func_021EA0E4 0x021EA0E4 thumb ov093
 *   func_021EA354  0x021EA354  thumb  ov093
 *   func_021EA0F4  0x021EA0F4  thumb  ov093
 *   func_021EA120  0x021EA120  thumb  ov093
 *   func_021EA280  0x021EA280  thumb  ov093
 *   func_021EA2BC  0x021EA2BC  thumb  ov093
 *   func_021EA384  0x021EA384  thumb  ov093
 *   func_021EA3A0  0x021EA3A0  thumb  ov093
 *   func_021F81D0  0x021F81D0  thumb  ov094
 *   func_021EA40C  0x021EA40C  thumb  ov093
 *   func_021EA428  0x021EA428  thumb  ov093
 *   func_021EA438  0x021EA438  thumb  ov093
 *   func_021EA448  0x021EA448  thumb  ov093
 *   func_021EA7C8  0x021EA7C8  thumb  ov093
 *   func_021EA7E8  0x021EA7E8  thumb  ov093
 *   func_021EA7D8  0x021EA7D8  thumb  ov093
 *   func_021EF9C0  0x021EF9C0  thumb  ov093
 *   d_021EFFAE     0x021EFFAE  data   ov093  a2
 *   func_021EF9C8  0x021EF9C8  thumb  ov093
 *   func_021EA838  0x021EA838  thumb  ov093
 *   func_021EA850  0x021EA850  thumb  ov093
 *   func_021EA904  0x021EA904  thumb  ov093
 *   func_021EA950  0x021EA950  thumb  ov093
 *   func_021F7E94 0x021F7E94 thumb ov094
 *   func_021F7EA4  0x021F7EA4  thumb  ov094
 *   func_021EA8B4  0x021EA8B4  thumb  ov093
 *   func_021EA8D4  0x021EA8D4  thumb  ov093
 *   func_021EA1B8  0x021EA1B8  thumb  ov093
 *   func_021EA1F0  0x021EA1F0  thumb  ov093
 *   func_021EA8E4 0x021EA8E4 thumb ov093
 *   func_021EA8F4 0x021EA8F4 thumb ov093
 *   d_021EFF88     0x021EFF88  data  ov093  a2
 *   func_021F8204 0x021F8204 thumb ov094
 *   func_021F8134 0x021F8134 thumb ov094
 *   func_021F8180 0x021F8180 thumb ov094
 *   func_021D6EA0 0x021D6EA0 thumb ov093
 *   func_021D6BFC 0x021D6BFC thumb ov093
 *   func_021F8150 0x021F8150 thumb ov094
 *   func_02006238 0x02006238 thumb
 *   func_021EA3B8 0x021EA3B8 thumb ov093
 *   func_021EA3D4 0x021EA3D4 thumb ov093
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   func_02005F38 0x02005F38 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   func_021EADA4 0x021EADA4 thumb ov093
 *   func_021EADB4 0x021EADB4 thumb ov093
 *   func_021EADC4 0x021EADC4 thumb ov093
 *   func_021EADD4 0x021EADD4 thumb ov093
 *   func_021EADE4 0x021EADE4 thumb ov093
 *   func_021EADF4 0x021EADF4 thumb ov093
 *   d_021F3B64 0x021F3B64 data a4
 *   GFL_USE_IsSeqPlaying 0x02006254 thumb
 *   func_020181F4   0x020181F4  thumb
 *   POKE_TOOL_GetLevelUpMove   0x02018328  thumb
 *   func_021EA638   0x021EA638  thumb ov093
 *   func_021EAC64   0x021EAC64  thumb ov093
 *   func_021EAC80   0x021EAC80  thumb ov093
 *   g_021F3B64      0x021F3B64  data
 *   func_021F7CFC 0x021F7CFC thumb ov094
 *   func_021F883C 0x021F883C thumb ov094
 *   d_021EFF80 0x021EFF80 data a2
 *   func_021F7C0C 0x021F7C0C thumb ov094
 *   func_021F7D44  0x021F7D44  thumb  ov094
 *   func_021EAA6C  0x021EAA6C  thumb  ov093
 *   func_021EAAD8  0x021EAAD8  thumb  ov093
 *   func_021EA768  0x021EA768  thumb  ov093
 *   func_021EA778  0x021EA778  thumb  ov093
 *   func_021EA7A8  0x021EA7A8  thumb  ov093
 *   func_021EA7B8  0x021EA7B8  thumb  ov093
 *   func_021EA868  0x021EA868  thumb  ov093
 *   func_021EA878  0x021EA878  thumb  ov093
 *   func_0689C9D4 0x0689C9D4 thumb ov095
 *   func_021BAB40  0x021BAB40  thumb  ov093
 *   func_021BB8BC  0x021BB8BC  thumb  ov093
 *   func_021BB8DC  0x021BB8DC  thumb  ov093
 *   func_021BB964  0x021BB964  thumb  ov093
 *   func_021C7CBC  0x021C7CBC  thumb  ov093
 *   func_021C7CC8  0x021C7CC8  thumb  ov093
 *   func_021C7CD4  0x021C7CD4  thumb  ov093
 *   func_021C7CDC  0x021C7CDC  thumb  ov093
 *   func_021C7CE8  0x021C7CE8  thumb  ov093
 *   func_021C8138  0x021C8138  thumb  ov093
 *   func_021C8140  0x021C8140  thumb  ov093
 *   func_021CD924  0x021CD924  thumb  ov093
 *   func_021CD95C  0x021CD95C  thumb  ov093
 *   func_021CD984  0x021CD984  thumb  ov093
 *   func_021CD9B0  0x021CD9B0  thumb  ov093
 *   func_021CD9F4  0x021CD9F4  thumb  ov093
 *   func_021CDDA0  0x021CDDA0  thumb  ov093
 *   func_021CDDCC  0x021CDDCC  thumb  ov093
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
#include "../../matched/include/Obj13327.h"
#include "../../matched/include/Obj09969.h"
#include "../../matched/include/Obj21086.h"
#include "../../matched/include/Obj09970.h"
#include "../../matched/include/Obj21090.h"
#include "../../matched/include/Obj13329.h"
#include "../../matched/include/Obj09971.h"
#include "../../matched/include/Obj21091.h"
#include "../../matched/include/Obj13330.h"
#include "../../matched/include/Obj13331.h"
#include "../../matched/include/Obj03191.h"
#include "../../matched/include/Obj07754.h"
#include "../../matched/include/Obj21095.h"
#include "../../matched/include/Obj21096.h"
#include "../../matched/include/Obj05192.h"
#include "../../matched/include/Obj07755.h"
#include "../../matched/include/Obj05193.h"
#include "../../matched/include/Obj21097.h"
#include "../../matched/include/Obj06227.h"
#include "../../matched/include/Obj18306.h"
#include "../../matched/include/Obj21098.h"
#include "../../matched/include/Obj21099.h"
#include "../../matched/include/Obj13335.h"
#include "../../matched/include/Obj04360.h"
#include "../../matched/include/Obj13336.h"
#include "../../matched/include/Obj01688.h"
#include "../../matched/include/Obj09972.h"
#include "../../matched/include/Obj21104.h"
#include "../../matched/include/Obj07759.h"
#include "../../matched/include/Obj18319.h"
#include "../../matched/include/Obj18320.h"
#include "../../matched/include/Obj18322.h"
#include "../../matched/include/Obj18323.h"
#include "../../matched/include/Obj02135.h"
#include "../../matched/include/Obj18325.h"
#include "../../matched/include/Obj21110.h"
#include "../../matched/include/Obj21111.h"
#include "../../matched/include/Obj13340.h"
#include "../../matched/include/Obj18333.h"
#include "../../matched/include/Obj26329.h"
#include "../../matched/include/Obj26330.h"
#include "../../matched/include/Obj18335.h"
#include "../../matched/include/Obj18336.h"
#include "../../matched/include/Obj18337.h"
#include "../../matched/include/Obj13341.h"
#include "../../matched/include/Obj21115.h"
#include "../../matched/include/Obj21118.h"
#include "../../matched/include/Obj21119.h"
#include "../../matched/include/Obj21120.h"
#include "../../matched/include/Obj13342.h"
#include "../../matched/include/Obj09974.h"
#include "../../matched/include/Obj21121.h"
#include "../../matched/include/Obj00294.h"
#include "../../matched/include/Obj18339.h"
#include "../../matched/include/Obj21124.h"
#include "../../matched/include/Obj21125.h"
#include "../../matched/include/Obj09973.h"
#include "../../matched/include/Obj05194.h"
#include "../../matched/include/Obj21127.h"
#include "../../matched/include/Obj18348.h"
#include "../../matched/include/Obj09976.h"
#include "../../matched/include/Obj09977.h"
#include "../../matched/include/Obj13344.h"
#include "../../matched/include/Obj09978.h"
#include "../../matched/include/Obj09979.h"
#include "../../matched/include/Obj13345.h"
#include "../../matched/include/Obj13346.h"
#include "../../matched/include/Obj02784.h"
#include "../../matched/include/Obj09980.h"
#include "../../matched/include/Obj06229.h"
#include "../../matched/include/Obj09981.h"
#include "../../matched/include/Obj05195.h"
#include "../../matched/include/Obj09983.h"
#include "../../matched/include/Obj06230.h"
#include "../../matched/include/Obj13347.h"
#include "../../matched/include/Obj05196.h"
#include "../../matched/include/Obj09984.h"
#include "../../matched/include/Obj21130.h"
#include "../../matched/include/Obj18356.h"
#include "../../matched/include/Obj01891.h"
#include "../../matched/include/Obj05197.h"
#include "../../matched/include/Obj13352.h"
#include "../../matched/include/Obj13353.h"
#include "../../matched/include/Obj07767.h"
#include "../../matched/include/Obj18365.h"
#include "../../matched/include/Obj18367.h"
#include "../../matched/include/Obj00463.h"
#include "../../matched/include/Obj00818.h"
#include "../../matched/include/Obj09986.h"
#include "../../matched/include/Obj01689.h"
#include "../../matched/include/Obj06232.h"
#include "../../matched/include/Obj04362.h"
#include "../../matched/include/Obj01892.h"
#include "../../matched/include/Obj07768.h"
#include "../../matched/include/Obj21134.h"
#include "../../matched/include/Obj13355.h"
#include "../../matched/include/Obj01893.h"
#include "../../matched/include/Obj07769.h"
#include "../../matched/include/Obj03688.h"
#include "../../matched/include/Obj13356.h"
#include "../../matched/include/Obj00662.h"
#include "../../matched/include/Obj02785.h"
#include "../../matched/include/Obj03689.h"
#include "../../matched/include/Obj00434.h"
#include "../../matched/include/Obj21136.h"
#include "../../matched/include/Obj05199.h"
#include "../../matched/include/Obj03194.h"
#include "../../matched/include/Obj00967.h"
#include "../../matched/include/Obj09993.h"
#include "../../matched/include/Obj02136.h"
#include "../../matched/include/Obj00888.h"
#include "../../matched/include/Obj07772.h"
#include "../../matched/include/Obj06234.h"
#include "../../matched/include/Obj05200.h"
#include "../../matched/include/Obj01894.h"
#include "../../matched/include/Obj07774.h"
#include "../../matched/include/Obj00489.h"
#include "../../matched/include/Obj01690.h"
#include "../../matched/include/Obj00340.h"
#include "../../matched/include/Obj03197.h"
#include "../../matched/include/Obj00464.h"
#include "../../matched/include/Obj13364.h"
#include "../../matched/include/Obj13365.h"
#include "../../matched/include/Obj03198.h"
#include "../../matched/include/Obj09995.h"
#include "../../matched/include/Obj05202.h"
#include "../../matched/include/Obj01236.h"
#include "../../matched/include/Obj00819.h"
#include "../../matched/include/Obj13368.h"
#include "../../matched/include/Obj13369.h"
#include "../../matched/include/Obj05203.h"
#include "../../matched/include/Obj00066.h"
#include "../../matched/include/Obj01237.h"
#include "../../matched/include/Obj01691.h"
#include "../../matched/include/Obj21146.h"
#include "../../matched/include/Obj06240.h"
#include "../../matched/include/Obj07782.h"
#include "../../matched/include/Obj05206.h"
#include "../../matched/include/Obj05207.h"
#include "../../matched/include/Obj10019.h"
#include "../../matched/include/Obj10021.h"
#include "../../matched/include/Obj07783.h"
#include "../../matched/include/Obj06241.h"
#include "../../matched/include/Obj07784.h"
#include "../../matched/include/Obj04364.h"
#include "../../matched/include/Obj21158.h"
#include "../../matched/include/Obj03693.h"
#include "../../matched/include/Obj13398.h"
#include "../../matched/include/Obj00268.h"
#include "../../matched/include/G_StateData.h"

#define ENTRY(i) (&e[i])
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += 4) - 4))
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
struct S_021C2E4C;
struct QJ;
struct Entry_p11;
struct Obj;
struct Result;
struct Unk021D5FA4;
struct Pack;
struct Rec;
struct Q9;
struct Cmd;
struct Q10;
struct S_p14;
struct Unk021D6C50;
struct Unk021D6C2C;
struct R5;
struct Unk021EFD70;
struct Sav;
struct Q2;
struct QE;
struct Qd;
struct Q3;
struct L;
struct H;
struct QG;
struct QV;
struct G;
struct Rat;
struct G_021CFD50;
struct S;
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

typedef struct { u32 x; } W_021C2E4C;

typedef struct { u8 pad[5]; u8 f : 1; } BF;

struct Flags_021C2E4C { u8 pad[5]; u8 a:1; u8 rest:7; };

typedef struct { u8 pad[5]; u8 f : 1; } Q_p10;

enum Mode { M0, M1, M2, Mneg = -1 };

struct Pair { u8 count, id; };

typedef struct { u8 pad[5]; u8 a:1,b:1,c:6; } Flag_td;

typedef struct { u8 a:4,b:1,c:3; } ByteFlag;

struct Flags_021C5108 { u8 a:1; u8 b:1; u8 rest:6; };

struct Entry_p11 { u32 value; u8 flag; u8 a, b, c, d, e, f, pad; };

struct Out64B4 {
    u16 h0;
    u16 h2;
    u16 h4;
    u8 b6;
    u8 pad7;
    u32 w8;
    u32 wC;
    u32 w10;
};

typedef enum { KIND_NONE, KIND_FIRST, KIND_SECOND } Kind;

/* 021C7CD4  movs r1,#0x7e; lsls r1,#6; ldrh r0,[r0,r1] */
struct Q6 { u8 pad[0x1f80]; u16 v; };

typedef struct { u32 value; u8 flag; u8 pad[7]; } Rec_021CAA58;

struct Flag { u8 pad[0x78a]; u8 low:3; u8 set:1; u8 high:4; };

typedef struct { u32 lo : 4; u32 hi : 28; } W_p12;

typedef union { u32 u; W_p12 w; } U;

typedef struct { u8 *a; U b; u32 c; u32 d; } E_p12;

typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E_p12 e[4]; } S_td;

/* 021C8138  ldr r0,[r0,#0x10]; lsls r0,#0x10; lsrs r0,#0x10 */
struct Q7 { u8 pad[0x10]; u32 v; };

typedef struct { u32 f0; u8 pad[60]; } E64;

typedef short s16_021C82F4;

typedef int s32_021C82F4;

struct Bits { unsigned char a:1; unsigned char rest:7; };

typedef signed short s16_021C83CC;

typedef signed int s32_021C83CC;

struct Flags_021C7D34 { u8 low:5; u8 flag:1; u8 high:2; };

struct Flags_021C8588 { u8 low : 3; u8 a : 1; u8 b : 1; u8 high : 3; };

struct Packed021C8810 { u16 low : 8; u16 high : 8; };

struct S_p12 {
    u16 x;
    u16 y : 8;
    u16 n : 7;
    u16 z : 1;
    u32 arr[8];
};

struct Packed021C888C { u16 low : 8; u16 index : 7; u16 active : 1; };

typedef struct {
    u32 id : 8;
    u32 client : 5;
    u32 unk13 : 11;
    u32 ignoreIfBusy : 1;
    u32 checkFainted : 1;
    u32 unk26 : 6;
} BtlCmd;

typedef struct {
    u8 unk0[8];
    void *party;        /* 0x0008 */
    u8 unk0C[0x1D68];
    u8 queue[4];        /* 0x1D74 */
} BattleCtx;

typedef struct { u32 pad : 8; u32 idx : 5; u32 rest : 19; } Ent;

typedef struct { u32 pad : 8; u32 idx : 5; u32 rest : 19; } Ent_021C8CBC;

typedef struct { u32 pad : 8; u32 idx : 5; u32 rest : 19; } Ent_021C8D0C;

typedef struct {
    u32 w; u16 h4; u8 b6; u8 b7; u16 h8; u16 ha;
} Ent_021C8DE4;

typedef struct {
    u32 pad : 8; u32 idx : 5; u32 mid : 10; u32 fl : 1; u32 top : 8;
    u16 h4; u8 b6; u8 f7a : 1; u8 f7b : 1; u8 f7c : 6; u16 h8; u8 ba; u8 bb;
} Ent_021C8E58;

typedef struct {
    u32 w; u8 n; u8 b5; u8 b6; u8 ids[9]; u32 v[4];
} Ent_021C8F24;

typedef struct { int pad0; int pad1; char *f8; } P_021C8CBC;

typedef struct {
    u32 pad : 8; u32 idx : 5; u32 rest : 19;
    u8 b4; u8 b5; u8 b6; u8 f7a : 1; u8 f7b : 1; u8 f7c : 6;
} Ent_021C8FA4;

typedef struct {
    u32 w; u8 b4; u8 b5; u8 b6; u8 f7a : 1; u8 f7b : 1; u8 f7c : 6;
} Ent_021C9010;

typedef struct {
    u32 pad : 8; u32 idx : 5; u32 mid : 10; u32 fl : 1; u32 top : 8;
    int value;
    u8 targets[12];
    u8 count;
    u8 flag;
    u8 gap[2];
    struct Msg msg;
} Ent_021C9068;

typedef struct { u32 low:8, index:5, pad:10, flag:1, high:8; u32 kind; union Slot value; u8 a,b,c,id,d; u8 pad11[3]; u8 msg[36]; } Ent_021C9178;

typedef struct { u32 low:8,index:5,pad:10,flag:1,high:8; enum Kind kind; u32 value; s8 a; u8 b,c,count; u8 ids[8]; u8 msg[36]; } Ent_021C9250;

typedef struct {
    u32 w; u8 b[8];
} Ent_021C9394;

typedef struct { int pad0; int pad1; char *f8; void *fc; } P_021C9178;

typedef struct { u32 w; u8 n; u8 ids[1]; } Ent_021C9448;

typedef struct { u32 w; u16 values[5]; u8 id; u8 f0:1,f1:1,f2:1,f3:1,f4:1,pad:3; u8 msg[36]; } Ent_021C94C8;

typedef struct { u32 w; u8 b4; u8 b5; } Ent_021C95D0;

typedef struct { u32 w; u16 h4; u8 b6; u8 b7; } Ent_021C962C;

struct Cmd_021C96D4 {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 10;
    u32 flag : 1;
};

struct Cmd_021C97D0 {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u32 w4;
    u32 w8;
    u8 b12;
};

struct Cmd_021C98E4 {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 3;
    u32 pad2 : 7;
    u32 flag : 1;
    u32 pad3 : 8;
    u8 b4;
    u8 b5;
    u8 b6;
};

struct Cmd_021C9A24 { u32 a:8; u32 id:5; u32 pad:19; u32 w4; u8 b8; u8 pad9[3]; u8 data[16]; u8 b28; };

typedef struct { u32 low:8,index:5,pad:10,flag:1,high:8; u16 value; u8 id,a; u8 pad8[4]; u8 msg[36]; } Ent_021C9A60;

typedef struct { u32 low:8,index:5,pad:10,flag:1,high:8; u16 value; u8 id,a,b,c; u8 padA[2]; u8 msg[36]; } Ent_021C9BB8;

typedef struct { u32 low:8,index:5,pad:10,flag:1,high:8; u8 id,pad5[3]; u8 msg[108]; } Ent_021C9CC0;

struct Cmd_021C9DE8 {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u32 f0 : 1;
    u32 f1 : 1;
};

struct Cmd_021C9E3C {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u8 b4;
    u8 b5;
    u16 h6;
};

struct Cmd_021C9ECC {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u32 w4;
};

struct Cmd_021C9F0C {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u16 h8;
};

struct Out { u16 h0,h2,h4; u8 b6,pad7; u32 w8,wc,w10; };

struct State_p13 { u16 h0; u8 b2,b3,b4; u8 flag:1; u8 rest:7; };

struct Bits_p13 { u32 low : 8; u32 index : 5; u32 high : 19; };

struct Cmd_021CA158 {
    u8 pad[0x4C];
    u8 b4c;
    u8 b4d;
};

struct Cmd_021CA1D0 {
    u32 pad;
    u8 b4;
    u8 b5;
};

struct Cmd_021CA248 {
    u32 pad;
    u8 b4;
    u8 b5;
    u16 h6;
};

struct Q_021C95D0 {
    u32 a : 8;
    u32 b : 5;
    u32 c : 19;
    u16 e;
    u8 f;
    u8 lo : 4;
    u8 hi : 4;
};

struct Cmd_021CA2E8 { u32 a:8; u32 id:5; u32 b:10; u32 flag:1; u32 c:8; u8 target; };

struct Cmd { u32 a:8; u32 id:5; u32 b:19; };

struct Q_021CA5CC {
    u32 lo : 23;
    u32 f : 1;
    u32 hi : 8;
    u8 pad4[0];
};

typedef struct {
    u8 unk0[0x4A8];
    u8 *state;          /* 0x4A8 */
} BattleCtx_021CA7C4;

typedef struct {
    u8 unk0[5];
    u8 flag : 1;
    u8 unk5 : 7;
} BattleState;

typedef struct {
    u8 unk0[0x4A8];
    BattleState *state; /* 0x4A8 */
} BattleCtx_021CA7D4;

struct Flags { u32 a:1; u32 b:31; };

struct Record { u16 n0, n1; u8 ids[6]; };

struct T6 { u8 f0; u8 f1; u16 f2; u16 f4; };

typedef enum
{
  COND_ZERO,
  COND_ONE,
  COND_TWO
} Condition;

typedef int (*Callback_021CAA58)(Server *, u8 *, u16, u32, u32);

typedef struct
{
  u16 id;
  u8 mode;
  u8 exact;
  Callback_021CAA58 call;
} Entry_021CAA58;

typedef signed long long s64;

typedef struct Word_021CAA58 { u32 v; } Word_021CAA58_td;

typedef struct Rec_021CC008 {
    int f00;
    u32 f04;
    u8 f08;
    u8 pad[11];
    u8 f14;
} Rec_021CC008_td;

struct S_p14 {
    unsigned int x : 10;
};

/* 021CC96C  ldr r0,[r0]; lsls #1; lsrs #0x1f */
struct Q9 { u32 a : 30; u32 b : 1; u32 c : 1; };

/* 021CC99C  ldr r0,[r0]; lsls #3; lsrs #0x1f */
struct Q10 { u32 a : 28; u32 b : 1; u32 c : 3; };

struct SizeEntry {
    u8 id;
    u8 size;
};

struct Rec_p14 {
    u32 id : 8;
    u32 b : 5;
    u32 size : 10;
    u32 x : 1;
    u32 pad : 2;
    u32 y : 1;
    u32 rest : 5;
};

struct Pack {
    u32 lo : 10;
    u32 off : 9;
    u32 rest : 13;
    u8 data[500];
};

typedef struct {
    u32 unk0;
    u32 pos;
} ByteStream;

typedef char *va_list;

typedef struct { u8 f0:1,f1:1,f2:1,f3:1,f4:1,f5:1,rest:2; } Flags_021CC768;

/* 021CD95C  str r1,[r0,#0x54] */
struct QA { u8 pad[0x54]; u32 v; };

/* 021CD978  ldr r0,[r0,#0x50] */
struct QB { u8 pad[0x50]; u32 v; };

/* 021CD97C  push {r3,lr}; ldr r1,[r0,#0x28]; blx r1; pop {r3,pc} */
struct R2 { u8 pad[0x28]; void (*fn)(struct R2 *); };

/* 021CD9DC  ldrh r0,[r0,#0x22] */
struct QD { u8 pad[0x22]; u16 v; };

/* 021CDA0C  str r1,[r0,#0x28]; movs r1,#0x6a; movs r2,#0; lsls r1,#2;
 *           strb r2,[r0,r1] */
struct QE { u8 pad[0x28]; u32 v; u8 rest[0x1a8 - 0x2c]; u8 z; };

typedef int (*Callback_021CC768)(u8 *,int *);

typedef struct { u8 f0:1,f1:1,f2:1,f3:1,f4:1,f5:1,rest:2; } Flags_021CDA18;

typedef struct { u8 id; u8 flag; u16 pad; Callback_021CC768 callbacks[3]; } Entry_021CC768;

typedef struct {
    int a;
    int b;
} S_p14_td;

struct Flags_021CDDA0 { u8 pad[0x1b2]; u8 low:4; u8 flag:1; u8 high:3; };

struct Flags_021CDDCC { u8 pad[0x1b2]; u8 low:5; u8 flag:1; u8 high:2; };

typedef struct { u8 a : 5; u8 flag : 1; } Flags_021CE1B0;

typedef struct { u32 kind : 4; u32 rest : 28; } Command;

typedef struct { u8 a : 2; u8 f : 1; } Flags_021CE308;

struct L { u8 pad[0x11D]; u8 idx; u8 pad2[0x1A6-0x11E]; u8 sel; };

typedef struct { u8 flag : 1; u8 rest : 7; } Flags_021CE7D4;

typedef enum { OFFSET = 0x19a } Off;

struct Offsets { Off skip,ok0,ok1,ok2,ok3,invalid; };

typedef struct { u32 kind:4; u32 sub:3; u32 id:16; u32 rest:9; } Record_td;

typedef struct { u8 *q; u8 f[4]; } Ent_021CECB4;

typedef enum { VALUE_ZERO, VALUE_ONE } Value;

struct Unk021D82D0 { u32 kind : 4; u32 sub : 3; u32 id : 16; u32 rest : 9; };

struct G_021CFD50 {
    void *p0;
    void *p1;
    u8 pad0[0xec];
    u64 seed;
    u64 mul;
    u64 add;
};

struct G_021CFE08 {
    void *p0;
    u8 pad0[0xf0];
    u64 seed;
    u64 mul;
    u64 add;
};

struct G_021CFE98 { u8 pad[0xf4]; u64 seed; u64 mul; u64 add; };

struct G_021CFFAC { u8 pad[0xf4]; u64 seed; u64 mul; u64 add; };

struct G_021D0100 { u8 pad[0xf4]; u64 seed; u64 mul; u64 add; };

struct Row { u8 kind; u8 pad; u16 ids[4]; };

struct G_021D0248 {
    u8 pad0[0xf4];
    u64 seed;
    u64 mul;
    u64 add;
};

struct G_021D0304 { void *p0; u8 pad[0xf0]; u64 seed; u64 mul; u64 add; u8 pad2[0xc]; void *list; u8 start; };

struct G {
    u8 pad0[0xf4];
    u64 seed;
    u64 mul;
    u64 add;
    u8 pad1[0xc];
    void *list;
};

typedef struct {
    void *battle;         /* 0x00 */
    u8 unk04[0x50];
    void *msgWin;         /* 0x54 */
    u8 msg[0x14E];        /* 0x58 */
    u8 unk1A6;            /* 0x1A6 */
} BattleSeq_021D0B6C;

typedef struct { u8 pad[0x1B3]; volatile u8 count; } CountField;

typedef struct { u8 pad[0x1B2]; unsigned char f0:5; unsigned char flag:1; unsigned char f6:2; } Flags_p15;

typedef struct {
    void *battle;         /* 0x00 */
    void *unk04;          /* 0x04 */
    u8 unk08[0x4C];
    void *msgWin;         /* 0x54 */
    u8 msg[0x14E];        /* 0x58 */
    u8 unk1A6;            /* 0x1A6 */
} BattleSeq_021D123C;

typedef struct { u8 pad[0x1B2]; unsigned char f0:5; unsigned char flag:1; unsigned char f6:2; } Flags_021D1410;

typedef struct { u8 pad[0x1B2]; unsigned char f0:3; unsigned char flag:1; unsigned char f4:4; } Flags_021D1A60;

typedef int (*Callback)(u8 *, int *, int *);

typedef struct { int code; Callback fn; } CodeEntry;

typedef struct {
    u8 unk00[0x54];
    void *win;            /* 0x54 */
} Seq_021D123C;

typedef struct {
    u32 unk00;
    void *unk04;
    u8 unk08[0x4C];
    void *win;
} Seq_021D2030;

typedef struct {
    u32 unk00;
    u32 unk04;
    u8 unk08[0x4C];
    void *win;            /* 0x54 */
} Seq_021D20BC;

typedef struct {
    u32 unk00;
    u32 unk04;
    u8 unk08[0x4C];
    void *win;            /* 0x54 */
} Seq_021D210C;

typedef struct {
    u8 unk00[0x54];
    void *win;            /* 0x54 */
    u8 unk58[0x134 - 0x58];
    u32 unk134;
} Seq_021D215C;

typedef struct {
    u32 unk00;
    u32 unk04;
    u8 unk08[0x4C];
    void *win;            /* 0x54 */
} Seq_021D21D4;

typedef struct {
    u32 unk00;
    u32 unk04;
} Seq_021D2234;

typedef struct { u16 a; u16 b; } Pair16;

typedef struct { u8 data[0x24]; } MsgParam;

typedef struct {
    void *battle;
    void *party;
    u8 unk008[0x4c];
    void *msgWin;
    MsgParam msg;
    u8 unk07C[0x11e];
    u16 level;
    u8 unk19C[0xa];
    u8 side;
} LearnSeq_021D123C;

struct StateDataL { u8 pad0[8]; int counter; u32 remaining; u32 pad10; u8 result[14]; };

typedef struct {
    void *battle;       /* 0x000 */
    void *party;        /* 0x004 */
    u8 unk008[0x4C];
    void *msgWin;       /* 0x054 */
    MsgParam msg;       /* 0x058 */
    u8 unk07C[0x11E];
    u16 level;          /* 0x19A */
    u8 unk19C[0xA];
    u8 side;            /* 0x1A6 */
} LearnSeq_021D2C7C;

union DView { struct StateDataL s; u32 w[9]; };

extern u8 func_021B8778(struct Unk021B8CB0 **p, int k, u8 *out);
extern int func_021D5B68(void *m);
extern u8 func_021D5440(u8 *p);
extern u8 func_021B8BEC(u8 *p, u32 k, u8 n);
extern int func_021B86C8(unsigned char **p);
extern void *func_021B86B8(void ***p);
extern int func_021B8B9C(u8 *p, u8 k);
extern int func_02007F1C(void *,u32,int,u16);
extern int func_02007E50(void *,u32,int,u16);
extern u32 GPOWER_ApplyPrizeMoney(u32 v);
extern void *func_02012F08(int *p);
extern u32 func_0200C274(struct Blk34 *p);
extern u32 func_021D7FF8(u32 a, void *b);
extern void *func_021D5844(void *m);
extern char *func_021B8714(char **p);
extern void NATSUKI_Calc(void *a0, int a1, int a2, int a3);
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
extern void POKEPARTY_Init(struct Party *p);
extern void func_021D6B84(void *, int);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern void func_021D6C3C(void **p, void *q);
extern int func_021D67D0(struct R3 *p);
extern void *func_02007B50(void **p);
extern u32 func_02007C70(struct PerapVoice *p);
u8 func_021B6994(struct S_021B8CB0 **pp, u32 b);
extern u32 func_021B8588(void **p);
extern u8 func_021B8C20(int, u32, u32);
extern int func_021D5B7C(void *);
extern unsigned int func_021B8B78(unsigned char *p, int k);
extern void func_021D5854(struct Work *p);
extern u32 func_020307B0(void *p);
extern void *func_0200846C(int a);
extern void func_02008494(void *src, void *dst);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_02008510(void *a, int tag);
extern void PMSI_PARAM_ClearSentence(void *a);
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
extern void func_02082D44(void *, void *, int);
extern void PMSI_PARAM_Copy(struct Rec8 *dst, const struct Rec8 *src);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void STRBUF_SetChars(struct Buf *buf, const void *src, u32 n);
char *COMM_PLAYER_SUPPORT_GetCurrent(char *p);
extern struct Party *func_0201A920(u32);
int BTL_SETUP_CheckStatusFlag(char *base, int m);
extern u32 sub_02008DF0(struct Sub02008C20Obj *, int);
extern u32 sub_02008DAC(struct Sub02008C20Obj *, int, u32);
extern unsigned int func_021B6818(unsigned int *p);
extern void NATSUKI_CalcUseItem(void *, int, u16, u16);
extern int func_021D7F60(u32);
extern void NATSUKI_CalcParty(void *a0, int a1, int a2);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_021D805C(void *p, u32 n);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern u32 _u32_div_f(u32, u32);
extern u32 func_021D826C(u32 *p);
extern int func_021D8270(void *, int, unsigned int);
extern void func_021D787C(void *);
extern void func_021B68D8(u8 *s, struct T *t);
extern void func_021E9034(char *p);
extern void func_021E8E28(void *p);
extern struct Scene *func_021E8F20(void *a, void *b, u32 c, int d, u16 heap);
extern u8 func_021D54B4(u8 *p);
extern void GFL_USE_CancelChangeAndPlayBgm(u32, u32);
extern void GAME_BEACON_SetPokeLevelUp(u32);
extern void GAME_BEACON_SetPokeCapture(u16);
extern void *SHINKA_CHECK_OpenHandle(u16 heap);
extern int POKE_TOOL_IsOwnedByPlayer(void *, int);
extern int WAZA_TOOL_GetFlag(void *bag, int item);
extern u32 WAZA_TOOL_GetCategory(u16);
extern u32 WAZA_TOOL_IsDamaging(void *p);
extern u32 WAZA_TOOL_GetCategory(u16 move);
extern u32 sub_0201BD28(u16 id, u32 field);
extern int WAZA_TOOL_GetDamageType(int a);
extern W_021C312C WAZA_TOOL_GetSickCont(u16);
extern u8 WAZA_TOOL_GetRankEffectCount(u16);
extern u8 WAZA_TOOL_GetRankEffect(u16 id, u32 idx, s32 *out);
extern u32 WAZA_TOOL_GetWeather(int id);
extern u32 COMM_PLAYER_SUPPORT_GetMode(Server *);
extern void COMM_PLAYER_SUPPORT_SavePreviousAndSuspend(void *);
extern u8 WAZA_TOOL_GetType(void *p);
extern int WAZA_TOOL_GetDamageType(int a);
extern u32 WAZA_TOOL_IsAlwaysHit(u16 id);
extern u32 WAZA_TOOL_IsAlwaysCritical(u16 id);
extern u16 WAZA_TOOL_GetPower(void *p);
extern unsigned int SHINKA_CHECK_GetRowParam(void *, unsigned int, unsigned int, unsigned int);
extern u32 GPOWER_ApplyExpRate(u32);
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);
extern int GPOWER_ApplyCaptureRate(int);
extern int FX_Div(int, int);
extern int FX_Sqrt(int);
extern int TIMEZONE_GetTimeZoneOfHour(int row, int col);
extern void GFL_USE_SetPlayersAudible(int,u32);
extern void PM_VOICE_ResetMasterVolume(void);
extern int GFL_USE_IsBgmFading(void);
extern void PM_VOICE_SetMasterVolume(u8);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void GFL_USE_FadeOutBgm(u32);
extern u8 WAZA_TOOL_GetType(void *p);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern int PMSI_PARAM_IsEnabled(const u16 *p);
extern void *PMSI_PARAM_ToString(void *slots, unsigned int heap);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void GFL_USE_SetBgmPlayerParam(void *);
extern int GFL_USE_PushBgm(void);
extern int GFL_USE_PopBgm(void);
extern int GFL_USE_IsSeqPlaying(unsigned int);
extern u16 POKE_TOOL_GetLevelUpMove(void *p, u32 *idx, u32 heap);
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
u8 func_021B99C0(struct S_021B8CB0 **p, u32 b);
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
void func_021B9B10(u8 *p,u8 i,u8 v);
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
void func_021BA73C(char *p, u16 x);
void func_021BA7F8(char *p);
u32 func_021BA820(int *p);
void func_021BA82C(char *p);
void func_021BA878(u8 *p);
void func_021BAB40(char *p);
void func_021BB8BC(u8 *p, u32 *q);
void func_021BB8DC(u8 *p, u32 *q);
u32 func_021BB964(struct Q5 *p);
void CallbackForJpeg(int result, void *arg);
u16 func_021C7CBC(u8 *p);
u16 func_021C7CC8(u8 *p);
u16 func_021C7CD4(struct Q6 *p);
u16 func_021C7CDC(u8 *p);
u16 func_021C7CE8(u8 *p);
u16 func_021C8138(struct Q7 *p);
unsigned char func_021C8140(char *p, int i);
u16 *func_021CD924(u8 *p, u32 *out);
void func_021CD95C(struct QA *p, u32 v);
void func_021CD984(u8 *p,u16 n);
void func_021CD9B0(u8 *p);
void func_021CD9F4(u8 *p,u8 n);
int func_021CDDA0(u8 *p);
u32 func_021CDDCC(struct Flags_021CDDCC *p);
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
extern struct T6 g_021EFDC0[];
extern const Entry_021CAA58 data_021EFDE4[];
extern struct SizeEntry d_021EFE9C[0x3B];
extern char data_021F3A84[];
extern const u8 data_021EFF14[];
extern s32 data_021F3B44[];
extern u8 d_021F3A88[];
extern const Entry_021CC768 d_021EFFEC[15];
extern const u16 d_021EFF78[4];
extern const struct Row d_021EFFC2[4];
extern const CodeEntry d_021F00DC[];
extern Pair16 d_021EFFAE[5];
extern u16 d_021EFF88[];
extern union DView d_021F3B64;
extern struct StateData g_021F3B64;
extern const u16 d_021EFF80[];














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
        ((struct Obj06219 *)p)->f430 = GPOWER_ApplyPrizeMoney(((struct Obj06219 *)p)->f430);
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
    NATSUKI_Calc(x, c, ((struct Obj13277 *)e)->fA, (u16)((((struct Obj07746 *)p)->f468 & 0x7fff) | 0x8000));
    NATSUKI_Calc(y, c, ((struct Obj13277 *)e)->fA, (u16)((((struct Obj07746 *)p)->f468 & 0x7fff) | 0x8000));
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
    POKEPARTY_Init(((struct Obj09940 *)b)->f2B8);
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
    POKEPARTY_Init(((struct Obj07747 *)b)->f2B8);
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
u8 func_021B99C0(struct S_021B8CB0 **p, u32 b)
{
    u8 result = func_021B6994((struct S_021B8CB0 * *)p, b);
    if (func_021B8588((void **)p) == 3) result += 2;
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















void func_021B9B10(u8 *p,u8 i,u8 v) {
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
    PMSI_PARAM_ClearSentence(p + 0x18);
    PMSI_PARAM_ClearSentence(p + 0x20);
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
        PMSI_PARAM_Copy((struct Rec8 *)(&p->s18), (const struct Rec8 *)(&src->s18));
        PMSI_PARAM_Copy((struct Rec8 *)(&p->s20), (const struct Rec8 *)(&src->s20));
    } else {
        p->ha = 0;
        p->h8 = 0;
        p->q = 0;
        for (i = 0; i < 4; i++) {
            p->h[i] = 0;
        }
        PMSI_PARAM_ClearSentence(&p->s18);
        PMSI_PARAM_ClearSentence(&p->s20);
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
        STRBUF_SetChars((struct Buf *)t, (char *)src + 0x28, u);
        p->c = src->f8;
        func_02082D44((void *)src->b, (void *)p->h, 8);
        PMSI_PARAM_Copy((struct Rec8 *)(&p->s18), (const struct Rec8 *)(&src->s18));
        PMSI_PARAM_Copy((struct Rec8 *)(&p->s20), (const struct Rec8 *)(&src->s20));
    } else {
        p->ha = 0;
        p->h8 = 0;
        p->q = 0;
        for (i = 0; i < 4; i++) {
            p->h[i] = 0;
        }
        PMSI_PARAM_ClearSentence(&p->s18);
        PMSI_PARAM_ClearSentence(&p->s20);
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
    COMM_PLAYER_SUPPORT_GetCurrent((char *)(((struct Obj20998 *)(*p))->f70));
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
        POKEPARTY_Init(p->a[i]);
        POKEPARTY_Init(p->b[i]);
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
    return BTL_SETUP_CheckStatusFlag(*p, m);
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
    NATSUKI_CalcUseItem(xv, b, ((struct Obj13285 *)q)->fA, (((struct Obj13284 *)p)->f468 & 0x7fff) | 0x8000);
    NATSUKI_CalcUseItem(yv, b, ((struct Obj13285 *)q)->fA, (((struct Obj13284 *)p)->f468 & 0x7fff) | 0x8000);
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
            NATSUKI_CalcParty(list, *(u16 *)(func_021B8714((char **)p) + 10), (u16)((((struct Obj00324 *)p)->f468 & 0x7fff) | 0x8000));
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
void func_021BA73C(char *p, u16 x)
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
