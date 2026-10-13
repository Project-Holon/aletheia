/*
 * file:     btl_server_cmd.c
 * unit:     yes
 * function: func_021CCAA8, func_021CCAD4, func_021CCAE0, func_021CCB18, func_021CCB34, func_021CCB78, func_021CCB98, func_021CCBE8, func_021CCC0C, func_021CD0F0, func_021CD4B0, func_021CD4FC, func_021CD568, func_021CD5E0, func_021CD63C, func_021CD644, func_021CD64C, func_021CD6AC, func_021CD6EC
 * address:  0x021CCAA8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Battle server command queue: byte writers and readers, the command encoder and decoder driven by the layout table data_021EFF14.  Split from btl_server.c; it may be the front of btl_client.c (see the cut notes).  The empty-string literal data_021F3A84 sits between the btl_server_flow.c and btl_client.c file-name strings.
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
 */

#include "btl_server_cmd_types.h"

typedef char *va_list;
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += 4) - 4))

extern void func_02034714(const char *expr, u32 line, const char *file);
extern char data_021F3A84[];
extern const u8 data_021EFF14[];
extern s32 data_021F3B44[];

/* Appends one byte; an overflow of the queue is fatal. */
void func_021CCAA8(BtlServerCmdQueue *queue, u8 value)
{
    if (queue->writePos >= BTL_SERVER_CMD_QUEUE_SIZE) {
        func_02034714(data_021F3A84, 0, data_021F3A84);
    }
    queue->data[queue->writePos++] = value;
}

/* Reads one byte and advances the read cursor. */
u8 func_021CCAD4(BtlServerCmdQueue *queue)
{
    u32 pos = queue->readPos;
    queue->readPos = pos + 1;
    return queue->data[pos];
}

/* Appends a big-endian halfword. */
void func_021CCAE0(BtlServerCmdQueue *queue, u16 value)
{
    if (queue->writePos >= BTL_SERVER_CMD_QUEUE_SIZE - 1) {
        func_02034714(data_021F3A84, 0, data_021F3A84);
    }
    queue->data[queue->writePos++] = value >> 8;
    queue->data[queue->writePos++] = value;
}

/*
 * Reads a big-endian halfword and advances the read cursor.  The bytes are
 * addressed from the queue base plus the cursor, with the data offset as the
 * load displacement and the cursor read again for the second byte: that is
 * the form the compiler turns into the original code (the plain data[] index
 * form changes the bytes).
 */
u32 func_021CCB18(BtlServerCmdQueue *queue)
{
    const u8 *src;
    u16 value;
    int pos;

    pos = queue->readPos;
    src = (const u8 *)((u32)queue + queue->readPos);
    value = (*(const u8 *)((u32)queue + (u32)pos + BTL_SERVER_CMD_DATA_OFFSET) << 8) | *(const u8 *)((u32)queue + queue->readPos + BTL_SERVER_CMD_DATA_OFFSET + 1);
    queue->readPos += 2;
    return value;
}

/* Appends a big-endian 24-bit value. */
void func_021CCB34(BtlServerCmdQueue *queue, u32 value)
{
    if (queue->writePos >= BTL_SERVER_CMD_QUEUE_SIZE - 2) {
        func_02034714(data_021F3A84, 0, data_021F3A84);
    }
    queue->data[queue->writePos++] = value >> 16;
    queue->data[queue->writePos++] = value >> 8;
    queue->data[queue->writePos++] = value;
}

/* Reads a big-endian 24-bit value and advances the read cursor.  Same base-plus-cursor form as func_021CCB18. */
u32 func_021CCB78(BtlServerCmdQueue *queue)
{
    u32 pos = queue->readPos;
    u8 *src = (u8 *)queue + pos;
    u32 value = (src[BTL_SERVER_CMD_DATA_OFFSET] << 16) | (src[BTL_SERVER_CMD_DATA_OFFSET + 1] << 8) | src[BTL_SERVER_CMD_DATA_OFFSET + 2];

    queue->readPos = pos + 3;
    return value;
}

/* Appends a big-endian word. */
void func_021CCB98(BtlServerCmdQueue *queue, u32 value)
{
    if (queue->writePos >= BTL_SERVER_CMD_QUEUE_SIZE - 3) {
        func_02034714(data_021F3A84, 0, data_021F3A84);
    }
    queue->data[queue->writePos++] = value >> 24;
    queue->data[queue->writePos++] = value >> 16;
    queue->data[queue->writePos++] = value >> 8;
    queue->data[queue->writePos++] = value;
}

/* Reads a big-endian word and advances the read cursor.  Same base-plus-cursor form as func_021CCB18. */
u32 func_021CCBE8(BtlServerCmdQueue *queue)
{
    u32 value;
    u8 *src;

    src = (u8 *)queue + queue->readPos;
    value = ((u32)src[BTL_SERVER_CMD_DATA_OFFSET] << 24) | ((u32)src[BTL_SERVER_CMD_DATA_OFFSET + 1] << 16) | ((u32)src[BTL_SERVER_CMD_DATA_OFFSET + 2] << 8) | src[BTL_SERVER_CMD_DATA_OFFSET + 3];
    queue->readPos += 4;
    return value;
}

/* Writes command id and its arguments, packed as the layout byte says. */
void func_021CCC0C(BtlServerCmdQueue *queue, u32 id, int layout, s32 *args)
{
    int i;
    func_021CCAE0(queue, id);
    switch (layout) {
    case 0x01:
        func_021CCAA8(queue, args[0]);
        break;
    case 0x11:
        func_021CCAE0(queue, args[0]);
        break;
    case 0x02:
        func_021CCAA8(queue, args[0]);
        func_021CCAA8(queue, args[1]);
        break;
    case 0x12:
        func_021CCAA8(queue, args[0]);
        func_021CCAE0(queue, args[1]);
        break;
    case 0x22:
        func_021CCAA8(queue, args[0]);
        func_021CCB98(queue, args[1]);
        break;
    case 0x32:
        func_021CCAA8(queue, ((args[0] & 0xF) << 4) | (args[1] & 0xF));
        break;
    case 0x42:
        func_021CCAA8(queue, ((args[0] & 0x1F) << 3) | (args[1] & 7));
        break;
    case 0x03:
        func_021CCAA8(queue, ((args[0] & 0x1F) << 3) | (args[1] & 7));
        func_021CCAA8(queue, args[2]);
        break;
    case 0x13:
        func_021CCAA8(queue, ((args[0] & 0x1F) << 3) | (args[1] & 7));
        func_021CCAE0(queue, args[2]);
        break;
    case 0x23:
        func_021CCAE0(queue, (args[2] & 0x1F) | (((args[1] & 0x1F) << 5) | ((args[0] & 0x1F) << 10)));
        break;
    case 0x33:
        func_021CCB34(queue, (args[2] & 0x3FFF) | (((args[1] & 0x1F) << 14) | ((args[0] & 0x1F) << 19)));
        break;
    case 0x43:
        func_021CCAA8(queue, args[0]);
        func_021CCAA8(queue, args[1]);
        func_021CCAE0(queue, args[2]);
        break;
    case 0x53:
        func_021CCAA8(queue, args[0]);
        func_021CCAA8(queue, args[1]);
        func_021CCB98(queue, args[2]);
        break;
    case 0x14:
        func_021CCAA8(queue, ((args[0] & 0x1F) << 3) | (args[1] & 7));
        func_021CCAA8(queue, ((args[2] & 0x1F) << 3) | (args[3] & 7));
        break;
    case 0x04:
        func_021CCAA8(queue, ((args[0] & 0x1F) << 3) | (args[1] & 7));
        func_021CCAA8(queue, args[2]);
        func_021CCAE0(queue, args[3]);
        break;
    case 0x24:
        func_021CCB34(queue, (args[2] & 0x3FFF) | (((args[1] & 0x1F) << 14) | ((args[0] & 0x1F) << 19)));
        func_021CCAA8(queue, args[3]);
        break;
    case 0x34:
        func_021CCB34(queue, (args[2] & 0x3FFF) | (((args[1] & 0x1F) << 14) | ((args[0] & 0x1F) << 19)));
        func_021CCAE0(queue, args[3]);
        break;
    case 0x44:
        func_021CCAE0(queue, (args[2] & 0x3F) | (((args[1] & 0x1F) << 6) | ((args[0] & 0x1F) << 11)));
        func_021CCAE0(queue, args[3]);
        break;
    case 0x54:
        func_021CCAA8(queue, args[0]);
        func_021CCAA8(queue, args[1]);
        func_021CCAE0(queue, args[2]);
        func_021CCAE0(queue, args[3]);
        break;
    case 0x05:
        func_021CCAE0(queue, (args[2] & 0x1F) | (((args[1] & 0x1F) << 5) | ((args[0] & 0x1F) << 10)));
        func_021CCAE0(queue, args[3]);
        func_021CCAE0(queue, args[4]);
        break;
    case 0x15: {
        u8 hi = ((args[0] & 0x1F) << 3) | (args[1] & 7);
        u8 lo = ((args[2] & 0x7F) << 1) | (args[3] & 1);
        func_021CCAE0(queue, hi);
        func_021CCAE0(queue, lo);
        func_021CCAE0(queue, args[4]);
        break;
    }
    case 0x25:
        func_021CCAA8(queue, ((args[0] & 7) << 5) | ((args[1] & 7) << 2) | ((args[2] & 1) << 1) | (args[3] & 1));
        func_021CCAE0(queue, args[4]);
        break;
    case 0x06: {
        u16 v0 = (args[2] & 0x1F) | (((args[1] & 0x1F) << 5) | ((args[0] & 0x1F) << 10));
        u16 v1 = (args[5] & 0x1F) | (((args[4] & 0x1F) << 5) | ((args[3] & 0x1F) << 10));
        func_021CCAE0(queue, v0);
        func_021CCAE0(queue, v1);
        break;
    }
    case 0x16:
        func_021CCAA8(queue, ((args[0] & 7) << 5) | ((args[1] & 3) << 3) | ((args[2] & 1) << 2) | ((args[3] & 1) << 1) | (args[4] & 1));
        func_021CCAE0(queue, args[5]);
        break;
    case 0x26:
        func_021CCB34(queue, ((args[0] & 0x1F) << 15) | ((args[1] & 0x1F) << 10) | ((args[2] & 0x1F) << 5) | (args[3] & 0x1F));
        func_021CCAE0(queue, args[4]);
        func_021CCAE0(queue, args[5]);
        break;
    case 0x07:
        for (i = 0; i < 7; i++)
            func_021CCAA8(queue, args[i]);
        break;
    case 0x08:
        for (i = 0; i < 8; i++)
            func_021CCAA8(queue, args[i]);
        break;
    }
}

/* Reads the arguments of a fixed-layout command into args. */
void func_021CD0F0(BtlServerCmdQueue *queue, int layout, s32 *args)
{
    u8 byte;
    u32 half;
    u32 word;
    int i;
    switch (layout) {
    case 0x01:
        args[0] = func_021CCAD4(queue);
        break;
    case 0x11:
        args[0] = func_021CCB18(queue);
        break;
    case 0x02:
        args[0] = func_021CCAD4(queue);
        args[1] = func_021CCAD4(queue);
        break;
    case 0x12:
        args[0] = func_021CCAD4(queue);
        args[1] = func_021CCB18(queue);
        break;
    case 0x22:
        args[0] = func_021CCAD4(queue);
        args[1] = func_021CCBE8(queue);
        break;
    case 0x32:
        byte = func_021CCAD4(queue);
        args[0] = (byte >> 4) & 0xF;
        args[1] = byte & 0xF;
        break;
    case 0x42:
        byte = func_021CCAD4(queue);
        args[0] = (byte >> 3) & 0x1F;
        args[1] = byte & 7;
        break;
    case 0x03:
        byte = func_021CCAD4(queue);
        args[0] = (byte >> 3) & 0x1F;
        args[1] = byte & 7;
        args[2] = func_021CCAD4(queue);
        break;
    case 0x13:
        byte = func_021CCAD4(queue);
        args[0] = (byte >> 3) & 0x1F;
        args[1] = byte & 7;
        args[2] = func_021CCB18(queue);
        break;
    case 0x23:
        half = func_021CCB18(queue);
        args[0] = (half >> 10) & 0x1F;
        args[1] = (half >> 5) & 0x1F;
        args[2] = half & 0x1F;
        break;
    case 0x33:
        word = func_021CCB78(queue);
        args[0] = (word >> 19) & 0x1F;
        args[1] = (word >> 14) & 0x1F;
        args[2] = word & 0x3FFF;
        break;
    case 0x43:
        args[0] = func_021CCAD4(queue);
        args[1] = func_021CCAD4(queue);
        args[2] = func_021CCB18(queue);
        break;
    case 0x53:
        args[0] = func_021CCAD4(queue);
        args[1] = func_021CCAD4(queue);
        args[2] = func_021CCBE8(queue);
        break;
    case 0x14:
        byte = func_021CCAD4(queue);
        args[0] = (byte >> 3) & 0x1F;
        args[1] = byte & 7;
        byte = func_021CCAD4(queue);
        args[2] = (byte >> 3) & 0x1F;
        args[3] = byte & 7;
        break;
    case 0x04:
        byte = func_021CCAD4(queue);
        args[0] = (byte >> 3) & 0x1F;
        args[1] = byte & 7;
        args[2] = func_021CCAD4(queue);
        args[3] = func_021CCB18(queue);
        break;
    case 0x24:
        word = func_021CCB78(queue);
        args[0] = (word >> 19) & 0x1F;
        args[1] = (word >> 14) & 0x1F;
        args[2] = word & 0x3FFF;
        args[3] = func_021CCAD4(queue);
        break;
    case 0x34:
        word = func_021CCB78(queue);
        args[0] = (word >> 19) & 0x1F;
        args[1] = (word >> 14) & 0x1F;
        args[2] = word & 0x3FFF;
        args[3] = func_021CCB18(queue);
        break;
    case 0x44:
        half = func_021CCB18(queue);
        args[0] = (half >> 11) & 0x1F;
        args[1] = (half >> 6) & 0x1F;
        args[2] = half & 0x3F;
        args[3] = func_021CCB18(queue);
        break;
    case 0x54:
        args[0] = func_021CCAD4(queue);
        args[1] = func_021CCAD4(queue);
        args[2] = func_021CCB18(queue);
        args[3] = func_021CCB18(queue);
        break;
    case 0x05:
        half = func_021CCB18(queue);
        args[0] = (half >> 10) & 0x1F;
        args[1] = (half >> 5) & 0x1F;
        args[2] = half & 0x1F;
        args[3] = func_021CCB18(queue);
        args[4] = func_021CCB18(queue);
        break;
    case 0x15: {
        u32 hi = func_021CCB18(queue);
        u32 lo = func_021CCB18(queue);
        args[0] = ((u8)hi >> 3) & 0x1F;
        args[1] = (u8)hi & 7;
        args[2] = ((u8)lo >> 1) & 0x7F;
        args[3] = (u8)lo & 1;
        args[4] = func_021CCB18(queue);
        break;
    }
    case 0x25:
        word = func_021CCAD4(queue);
        args[0] = (word >> 5) & 7;
        args[1] = (word >> 2) & 7;
        args[2] = (word >> 1) & 1;
        args[3] = word & 1;
        args[4] = func_021CCB18(queue);
        break;
    case 0x06: {
        u32 v0 = func_021CCB18(queue);
        u32 v1 = func_021CCB18(queue);
        args[0] = (v0 >> 10) & 0x1F;
        args[1] = (v0 >> 5) & 0x1F;
        args[2] = v0 & 0x1F;
        args[3] = (v1 >> 10) & 0x1F;
        args[4] = (v1 >> 5) & 0x1F;
        args[5] = v1 & 0x1F;
        break;
    }
    case 0x16:
        word = func_021CCAD4(queue);
        args[0] = (word >> 5) & 7;
        args[1] = (word >> 3) & 3;
        args[2] = (word >> 2) & 1;
        args[3] = (word >> 1) & 1;
        args[4] = word & 1;
        args[5] = func_021CCB18(queue);
        break;
    case 0x26:
        word = func_021CCB78(queue);
        args[0] = (word >> 15) & 0x1F;
        args[1] = (word >> 10) & 0x1F;
        args[2] = (word >> 5) & 0x1F;
        args[3] = word & 0x1F;
        args[4] = func_021CCB18(queue);
        args[5] = func_021CCB18(queue);
        break;
    case 0x07:
        for (i = 0; i < 7; i++)
            args[i] = func_021CCAD4(queue);
        break;
    case 0x08:
        for (i = 0; i < 8; i++)
            args[i] = func_021CCAD4(queue);
        break;
    }
}

/*
 * Appends command id with its variadic arguments; the layout byte gives the count.
 * stand-in: id is volatile.  Removing it changes the bytes.
 */
void func_021CD4B0(BtlServerCmdQueue *queue, volatile u32 id, ...)
{
    va_list ap;
    u32 i = 0;
    u8 layout = data_021EFF14[id];
    u32 argCount = layout & 0xF;

    va_start(ap, id);
    for (; i < argCount; i++) {
        data_021F3B44[i] = va_arg(ap, s32);
    }
    func_021CCC0C(queue, id, layout, data_021F3B44);
}

/*
 * Reserves room for command id: writes it with zero arguments to measure its
 * length, then overwrites the start with a filler record of that length.
 * Returns the position of the slot for func_021CD568 to fill in later.
 */
u16 func_021CD4FC(BtlServerCmdQueue *queue, u32 id)
{
    u8 layout;
    u8 argCount;
    u8 i;
    u8 length;
    u16 slotPos;

    layout = data_021EFF14[id];
    argCount = layout & 0xf;
    i = 0;
    if (argCount != 0) {
        do {
            data_021F3B44[i] = 0;
            i++;
        } while (i < argCount);
    }
    slotPos = queue->writePos;
    func_021CCC0C(queue, id, layout, data_021F3B44);
    length = queue->writePos - slotPos;
    queue->writePos = slotPos;
    func_021CCAE0(queue, BTL_SERVER_CMD_ID_FILLER);
    func_021CCAA8(queue, length - 3);
    queue->writePos = slotPos + length;
    return slotPos;
}

/* Writes command id with its variadic arguments into a slot reserved by func_021CD4FC. */
void func_021CD568(BtlServerCmdQueue *queue, u16 slotPos, u32 id, ...)
{
    va_list ap;
    u32 i = 0;
    u8 layout = data_021EFF14[id];
    u32 argCount = layout & 0xF;
    u16 savedPos;

    va_start(ap, id);
    for (; i < argCount; i++) {
        data_021F3B44[i] = va_arg(ap, s32);
    }
    savedPos = queue->readPos;
    queue->readPos = slotPos;
    func_021CCB18(queue);
    func_021CCAD4(queue);
    queue->readPos = savedPos;
    if (id != BTL_SERVER_CMD_ID_FILLER) {
        savedPos = queue->writePos;
        queue->writePos = slotPos;
        func_021CCC0C(queue, id, layout, data_021F3B44);
        queue->writePos = savedPos;
    }
}

/*
 * Reads the next command into args, skipping filler records; returns its id,
 * or BTL_SERVER_CMD_ID_NONE when the read cursor reaches the write cursor.
 */
int func_021CD5E0(BtlServerCmdQueue *queue, s32 *args)
{
    int id;
    u8 layout;

    id = func_021CCB18(queue);
    while (id == BTL_SERVER_CMD_ID_FILLER) {
        queue->readPos += func_021CCAD4(queue);
        if (queue->readPos >= queue->writePos) {
            return BTL_SERVER_CMD_ID_NONE;
        }
        id = func_021CCB18(queue);
    }
    layout = data_021EFF14[id];
    if (layout != 0 && layout != 0x10) {
        func_021CD0F0(queue, layout, args);
    } else {
        func_021CD6AC(queue, id, args);
    }
    return id;
}

/* Same as func_021CCAA8, called through a wrapper. */
void func_021CD63C(BtlServerCmdQueue *queue, u8 value)
{
    func_021CCAA8(queue, value);
}

/* Same as func_021CCAD4, called through a wrapper. */
u8 func_021CD644(BtlServerCmdQueue *queue)
{
    return func_021CCAD4(queue);
}

/*
 * Appends a variable-length command: id, first argument and (for the long
 * list command) a second halfword, then words up to BTL_SERVER_CMD_ARG_END.
 */
void func_021CD64C(BtlServerCmdQueue *queue, u8 id, ...)
{
    va_list ap;
    u16 first;
    s32 word;

    va_start(ap, id);
    first = va_arg(ap, s32);
    func_021CCAE0(queue, id);
    func_021CCAE0(queue, first);
    if (id == BTL_SERVER_CMD_ID_LONG_LIST) {
        func_021CCAE0(queue, va_arg(ap, s32));
    }
    do {
        word = va_arg(ap, s32);
        func_021CCB98(queue, word);
    } while (word != (s32)BTL_SERVER_CMD_ARG_END);
}

/* Reads the arguments of a variable-length command into args (at most 16). */
void func_021CD6AC(BtlServerCmdQueue *queue, u8 id, s32 *args)
{
    int i;

    i = 1;
    args[0] = func_021CCB18(queue);
    if (id == BTL_SERVER_CMD_ID_LONG_LIST) {
        args[1] = func_021CCB18(queue);
        i++;
    }
    for (; i < BTL_SERVER_CMD_MAX_ARGS; i++) {
        args[i] = func_021CCBE8(queue);
        if (args[i] == BTL_SERVER_CMD_ARG_END) {
            break;
        }
    }
}

/* Empty function. */
void func_021CD6EC(void)
{
}
